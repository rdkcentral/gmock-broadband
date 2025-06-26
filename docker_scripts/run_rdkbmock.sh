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
# This is the generic script for developers.
# If any new GMock shared libraries are added to the RdkbMock component,
# it is required to add corresponding dependencies in this script,
# which will help to write the Gtest test case for specific components.

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

# Default libc directory where the libraries are stored
lib_dir="$HOME/usr/local/lib"

# Remove existing all files from $HOME/usr/local/lib
log "INFO" "Removing all shared libraries files from $lib_dir"
rm -f "$lib_dir"/*
if [ $? -ne 0 ]; then
    log "ERROR" "Failed to remove all shared libraries files from $lib_dir"
    exit 1
else
    log "INFO" "All shared libraries files removed successfully from $lib_dir"
fi

# Remove existing all files from RdkbGMock/lib
log "INFO" "Removing all shared libraries files from RdkbGMock/lib"
rm -f lib/*
if [ $? -ne 0 ]; then
    log "ERROR" "Failed to remove all shared libraries files from RdkbGMock/lib"
    exit 1
else
    log "INFO" "All shared libraries files removed successfully from RdkbGMock/lib"
fi

# Run autogen.sh to prepare the configuration
log "INFO" "Starting the autogen.sh script"
if ./autogen.sh --enable-unitTestDockerSupport; then
    log "INFO" "autogen.sh executed successfully."

    # Perform the compilation and installation
    log "INFO" "Running make install"
    if make install; then
        log "INFO" "Make install completed successfully."

        # Assuming the new .so files are ready in a 'lib' subdirectory of the current working directory
        log "INFO" "Copying new .la files from local lib directory to $lib_dir"
        cp lib/*.la "$lib_dir/"
        if [ $? -ne 0 ]; then
            log "ERROR" "Failed to copy .la files to $lib_dir"
            exit 1
        else
            log "INFO" "New .la files copied successfully to $lib_dir"
        fi
    else
        log "ERROR" "Make install failed."
        exit 1
    fi
else
    log "ERROR" "autogen.sh failed to execute."
    exit 1
fi

log "INFO" "All operations for RdkbGMock completed successfully."