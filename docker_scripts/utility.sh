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
# General purpose log function with log level
log() {
    local level=$1
    local message=$2
    local timestamp=$(date +'%Y-%m-%d %H:%M:%S')
    echo " "
    echo "[$timestamp] $level: $message"
    echo " "
}

# Function to check if a file exists
check_file_exists() {
    local file_path="${PWD}/docker_scripts/$1"
    if [ -f "$file_path" ]; then
        log "INFO" "File exists: $file_path"
        return 0
    else
        log "ERROR" "File does not exist: $file_path"
        return 1
    fi
}

# Function to create directories after removing existing ones, all under the $HOME directory
create_dir() {
    for dir in "$@"; do
        local full_path="$HOME/$dir"
        if [ -d "$full_path" ]; then
            rm -rf "$full_path" || { log "ERROR" "Failed to remove existing directory $full_path"; exit 1; }
        fi
        mkdir -p "$full_path" || { log "ERROR" "Failed to create directory $full_path"; exit 1; }
        log "INFO" "Created directory $full_path"
    done
}

# Function to clone a Git repository
clone_repository() {
    local repo_url=$1
    local branch=$2
    local repo_name=$3
    if [ -d "$repo_name" ]; then
        log "INFO" "$repo_name already exists. Skipping clone."
        return
    else
        log "INFO" "Attempting to clone from $repo_url into $repo_name"
        if git clone "$repo_url" -b "$branch" "$repo_name"; then
            log "INFO" "Repository $repo_name cloned successfully."
        else
            log "ERROR" "Failed to clone $repo_name."
            exit 1
        fi
    fi
}

# Function to copy header files from a specific directory in a repository to a destination
copy_headers_from_repo() {
    local repo_name=$1
    local src_dir=$2
    local dest_path=$3
    local current_dir=$(pwd)

    log "INFO" "Starting in directory: $current_dir"
    if [ ! -d "$repo_name" ]; then
        log "ERROR" "Repository directory $repo_name does not exist"
        return 1
    fi

    cd "$repo_name" || { log "ERROR" "Failed to change directory to $repo_name"; return 1; }
    log "INFO" "Changed directory to $repo_name. Current path: $(pwd)"

    if [ ! -d "$src_dir" ]; then
        log "ERROR" "Source directory $src_dir does not exist in $repo_name"
        cd "$current_dir"
        return 1
    fi

    # Expand the destination path in case it contains variables
    eval dest_path_expanded=$dest_path
    if [ ! -d "$dest_path_expanded" ]; then
        mkdir -p "$dest_path_expanded" || { log "ERROR" "Failed to create destination path $dest_path_expanded"; cd "$current_dir"; return 1; }
        log "INFO" "Created destination path $dest_path_expanded"
    fi

    log "INFO" "Attempting to copy from $src_dir to $dest_path_expanded"
    if ! find "$src_dir" -type f -name "*.h" -exec cp {} "$dest_path_expanded" \; ; then
        log "ERROR" "Failed to copy headers from $src_dir to $dest_path_expanded"
        cd "$current_dir"
        return 1
    else
        log "INFO" "Successfully copied headers from $src_dir to $dest_path_expanded"
    fi

    cd "$current_dir"
    log "INFO" "Returned to starting directory: $current_dir"
}

# Function to perform a simple copy operation
copy_files() {
    local source_path=$1
    local destination_path=$2

    if [ ! -d "$source_path" ]; then
        log "ERROR" "Source path $source_path does not exist"
        exit 1
    fi

    if [ ! -d "$destination_path" ]; then
        mkdir -p "$destination_path" || { log "ERROR" "Failed to create destination path $destination_path"; exit 1; }
        log "INFO" "Created destination path $destination_path"
    fi

    if cp -rf "$source_path"/* "$destination_path"/; then
        log "INFO" "Files copied successfully from $source_path to $destination_path"
    else
        log "ERROR" "Failed to copy files from $source_path to $destination_path"
        exit 1
    fi
}
