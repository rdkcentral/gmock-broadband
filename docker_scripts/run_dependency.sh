#!/bin/bash
##########################################################################
#
# Copyright 2024 Comcast Cable Communications Management, LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# SPDX-License-Identifier: Apache-2.0
##########################################################################
# Source necessary scripts
# Check if utility.sh exists, source it, or exit if it doesn't exist
if [ -f "${PWD}/docker_scripts/utility.sh" ]; then
    source "${PWD}/docker_scripts/utility.sh"
else
    echo "Error: utility.sh does not exist."
    exit 1
fi

# Check if export_var.sh exists, source it, or exit if it doesn't exist
if [ -f "${PWD}/docker_scripts/export_var.sh" ]; then
    source "${PWD}/docker_scripts/export_var.sh"
else
    echo "Error: export_var.sh does not exist."
    exit 1
fi

# Get the name of the current directory
current_dir=$(basename "$PWD")

# Check if the current directory is 'RdkbGMock'
if [ "$current_dir" != "RdkbGMock" ]; then
    # If not, change to the RdkbGMock directory if it exists
    if [ -d "RdkbGMock" ]; then
        log "INFO" "Changing directory to RdkbGMock..."
        cd RdkbGMock
    else
        log "ERROR" "Directory RdkbGMock does not exist. Exiting..."
        exit 1
    fi
else
    log "INFO" "Already in RdkbGMock directory."
fi

# Ensure the dependency_repos.conf file exists
check_file_exists "dependency_repos.conf"

# Create necessary directories
log "INFO" "Creating necessary directory for dependency header file under /usr/include/*..."
create_dir usr/include/rdkb usr/include/rdkb/rbus usr/include/rdkb/mocks usr/include/rdkb/dbus \
           usr/include/rdkb/linux usr/include/rdkb/syscfg usr/include/rdkb/sysevent usr/include/rdkb/utctx usr/include/rdkb/utapi /usr/include/rdkb/ulog usr/include/rdkb/trower-base64 \
           usr/local/lib usr/include/rdkb/avro usr/include/rdkb/cimplog usr/include/rdkb/msgpack /usr/include/rdkb/resolv /usr/include/rdkb/libsafec usr/include/rdkb/libnfnetlink \
           usr/include/rdkb/libnetfilter_queue usr/include/rdkb/pcap usr/include/rdkb/libev usr/include/rdkb/wrp-c usr/include/rdkb/libparodus usr/include/rdkb/cjson usr/include/rdkb/utlog \
           usr/include/rdkb/net-snmp

# Initialize an associative array to keep track of cloned repositories
declare -A cloned_repos

# Read repositories from the configuration file and process each one
readarray -t lines < "${PWD}/docker_scripts/dependency_repos.conf"
for line in "${lines[@]}"; do
    # Skip empty lines and lines starting with #
    [[ "$line" =~ ^#.*$ || -z "$line" ]] && continue
    log "INFO" "Processing line: $line"

    # Read fields from the line
    IFS=' ' read -r repo_url branch repo_name src_path dest_path <<< "$line"

    # Check if branch is empty or missing
    if [[ -z "$branch" ]]; then
        log "ERROR" "Branch is missing for repo '$repo_url' in dependency_repos.conf. Exiting."
        exit 1
    fi

    log "INFO" "Repo URL: $repo_url"
    log "INFO" "Branch: $branch"
    log "INFO" "Repo Name: $repo_name"
    log "INFO" "Current Path: $PWD"
    log "INFO" "Source Path for Copy Header file: $src_path"
    log "INFO" "Destination Path for Copy Header file: $dest_path"

    repo_key="${repo_url} ${branch}"

    # Check if the repository has already been cloned
    if [[ -z "${cloned_repos[$repo_key]}" ]]; then
        log "INFO" "Cloning repository for the first time: $repo_url (branch: $branch)"
        clone_repository "$repo_url" "$branch" "$repo_name" "$src_path" "$dest_path"
        cloned_repos[$repo_key]=1  # Mark this repo and branch as cloned

        # Check if the repository is net-snmp and configure it
        if [[ "$repo_name" == "net-snmp" ]]; then
            uname -a
            autoconf --version
            cd net-snmp
            if autoconf && ./configure --prefix=$HOME/usr/local --enable-shared --disable-static --with-defaults --enable-ucd-snmp-compatibility; then
                log "INFO" "Successfully configured net-snmp"
            else
                log "ERROR" "Failed to configure net-snmp"
            fi
            cd ..
        fi
    else
        log "INFO" "Repository already cloned: $repo_url (branch: $branch)"
    fi

    # Copy the necessary files from the already cloned directory
    log "INFO" "Copying files from $src_path to $dest_path"
    copy_headers_from_repo "$repo_name" "$src_path" "$dest_path"
done

log "INFO" "Completed processing all repositories."

log "INFO" "Start copying the all RdkbMock Dependent component header files for docker"
# Example usage of the function with dynamic paths
copy_headers_from_repo "$repo_name" "$src_path" "$dest_path"

log "INFO" "Copying RdkbGMock headers to $HOME/usr/include/rdkb/mocks..."
find source -type f -name "*.h" | xargs -I {} cp {} $HOME/usr/include/rdkb/mocks

log "INFO" "Adding DBusLoop typedef on $HOME/usr/include/rdkb/ccsp_message_bus.h"
if sed -i '/typedef struct _CCSP_MESSAGE_BUS_CONNECTION/i typedef struct DBusLoop DBusLoop;' $HOME/usr/include/rdkb/ccsp_message_bus.h; then
    log "INFO" "DBusLoop typedef added successfully."
else
    log "ERROR" "Failed to add DBusLoop typedef."
    rm -rf CcspCommonLibrary
    exit 1
fi

# Copy libdbus-1-dev header files into $HOME/usr/include/rdkb/dbus
log "INFO" "Copying D-Bus headers into $HOME/usr/include/rdkb/dbus..."
copy_files "/usr/include/dbus-1.0/dbus" "$HOME/usr/include/rdkb/dbus"

# Define the path dynamically based on the machine architecture and check if the specific file exists
dbus_arch_path="/usr/lib/$(uname -m)-linux-gnu/dbus-1.0/include/dbus"
if [ -f "$dbus_arch_path/dbus-arch-deps.h" ]; then
    log "INFO" "Found architecture-dependent dbus header file, copying to $HOME/usr/include/rdkb/dbus..."
    copy_files "$dbus_arch_path" "$HOME/usr/include/rdkb/dbus"
else
    log "ERROR" "The architecture-dependent D-Bus header file (dbus-arch-deps.h) does not exist."
    exit 1
fi
log "INFO" "All D-Bus header files have been successfully copied to $HOME/usr/include/rdkb/dbus"

# Define the path dynamically based on the machine architecture and check if the specific file exists for glib
glib_arch_path="/usr/lib/$(uname -m)-linux-gnu/glib-2.0/include"
if [ -f "$glib_arch_path/glibconfig.h" ]; then
    log "INFO" "Found architecture-dependent glibconfig header file, copying to $HOME/usr/include/rdkb..."
    copy_files "$glib_arch_path" "$HOME/usr/include/rdkb"
else
    log "ERROR" "The architecture-dependent glibconfig header file (glibconfig.h) does not exist."
    exit 1
fi
log "INFO" "All glibconfig header files have been successfully copied to $HOME/usr/include/rdkb"

# If the common_headers directory exists and contains header files, copy all required headers for rdkb-gmock
if [ -d "docker_scripts/common_headers" ]; then
    log "INFO" "Start Copying common headers into $HOME/usr/include/rdkb"
    cp docker_scripts/common_headers/*.h $HOME/usr/include/rdkb
else
    log "ERROR" "common_headers directory not found in docker_scripts"
fi
log "INFO" "Copied common headers from RdkbGMock/docker_scripts/common_headers into $HOME/usr/include/rdkb"

# Execute a main script
log "INFO" "Starting to run the RdkbGMock Main Script..."
if ./docker_scripts/run_rdkbmock.sh; then
    log "INFO" "Successfully completed running the RdkbGMock Main Script."
else
    log "ERROR" "Failed to run the RdkbGMock Main Script."
    cd ..
    #rm -rf RdkbGMock
    exit 1
fi
