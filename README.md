# RdkbGMock Repository: Setup, Usage, and Configuration Guide

The **RdkbGMock** repository provides Google Mock-based implementations and utilities to support robust unit testing of RDK-B (RDK Broadband) components. It includes mocks for a wide range of APIs, system libraries, and hardware abstraction layers (HALs), simplifying the creation of test cases and ensuring consistency across RDK-B development.

---

## Prerequisites

### Setup Docker

Use the container from [ghcr.io/rdkcentral/docker-rdk-ci](https://github.com/rdkcentral/docker-rdk-ci/pkgs/container/docker-rdk-ci) and follow these commands:

```plaintext
docker run --name=<x> --volume=$HOME/<y>:/home/$USER --restart=no --runtime=runc -t -d ghcr.io/rdkcentral/docker-rdk-ci:latest

docker start <x>

docker exec <x> groupadd $USER --gid=$(id -g $USER)

docker exec <x> useradd -m $USER -G users --uid=$(id -u $USER) --gid=$(id -g $USER)

docker exec --user $USER -it <x> /bin/bash
```

Replace the placeholders:
- **x**: A name you choose for your Docker container (e.g., `rdk-ci-dev`).
- **y**: A directory on your host machine that will be mounted into the container (e.g., `rdk_workspace`).


---

## Repository Structure

```plaintext
RdkbGMock/
├── docker_scripts/            # Scripts for Docker-based development and testing
├── source/
│   ├── mocks/                 # Mock implementations grouped by category
│   │   ├── HAL/               # Hardware Abstraction Layer mocks
│   │   ├── syscfg/            # Mocks for Syscfg APIs
│   │   ├── file_io/           # File I/O-related mocks
│   │   └── ...                # Additional mocks (scheduler, telemetry, etc.)
├── autogen.sh                 # Script to initialize autotools
├── configure.ac               # Configuration for autotools
├── Makefile.am                # Makefile template for building
├── LICENSE                    # License information
├── README.md                  # Repository documentation
```

---

## Features

- **Comprehensive Mocks**: Includes mocks for HAL layers, system libraries, and RDK-B-specific utilities.
- **Organized Structure**: Mocks are categorized for ease of use and modularity.
- **Docker Support**: Contains scripts to enable building and testing in Docker environments.
- **Scalable Testing**: Easily add new mocks and integrate with existing RDK-B test cases.
- **Standardized Framework**: Supports Google Test (GTest) and Google Mock (GMock).

---

## Build Instructions

**Note**: These build instructions are not necessary, as the `run_ut.sh` script automatically performs the steps required to retrieve the mock shared libraries for linking to your component.

1. Clone the **RdkbGMock** repository:

    ```bash
    git clone <rdkb_repository_url>
    ```

2. Navigate to the RdkbGMock directory:

    ```bash
    cd RdkbGMock
    ```

3. Run the `autogen.sh` script:

    ```bash
    ./autogen.sh
    ```

4. Export the following path variables to configure C and C++ include paths for RDKB headers in the user's home directory:

    ```bash
    export C_INCLUDE_PATH=$HOME/usr/include/rdkb
    export CPLUS_INCLUDE_PATH=$HOME/usr/include/rdkb
    export C_INCLUDE_PATH=$HOME/usr/include/rdkb/rbus:$C_INCLUDE_PATH
    export CPLUS_INCLUDE_PATH=$HOME/usr/include/rdkb/rbus:$CPLUS_INCLUDE_PATH
    ```

5. Build and install the mocks:

    ```bash
    make install
    ```

6. Copy the `.la` files from the local `lib` directory to `$HOME/usr/local/lib`:

    ```bash
    cp lib/*.la "$HOME/usr/local/lib"
    ```

---

## Usage

### Linking Mocks to Your Component

1. **Include Necessary Mock Headers**: Add the required mock headers in your test files and declare the mock global variables as `extern`.  
   Example:

    ```cpp
    #include "mocks_hal/mock_platform_hal.h"

    extern PlatformHalMock *g_platformHALMock;
    ```

2. **Link the RdkbGMock Mock's Shared Library**: Update your `Makefile.am` to link the required shared libraries. Use the `_LDADD` variable as shown below:  
   Example:

    ```makefile
    _LDADD = \
        $(HOME)/usr/local/lib/libmock_platform_hal.la
    ```

3. **Write and Run Test Cases**: Use Google Mock to write test cases leveraging the linked mocks. Ensure the mocks are correctly initialized and used in your tests.

4. **Validate Your Changes**: Export the following variables, and run the `make` command in the component-specific `source/test/<test_directory>`, or use your preferred testing command to validate the integration of mocks.

    ```bash
    export C_INCLUDE_PATH=$HOME/usr/include/rdkb
    export CPLUS_INCLUDE_PATH=$HOME/usr/include/rdkb
    export C_INCLUDE_PATH=$HOME/usr/include/rdkb/rbus:$C_INCLUDE_PATH
    export CPLUS_INCLUDE_PATH=$HOME/usr/include/rdkb/rbus:$CPLUS_INCLUDE_PATH
    ```

---

### Adding New Mocks

1. Create a new mock in the appropriate `source/mocks/` directory.
2. Update `Makefile.am` to include the new mock.
3. Write test cases to validate the new mock.

---

## Dependency Component Repository Configuration Guide

This guide explains how to use the `dependency_repos.conf` file to configure dependency component repositories for your project.

**Note**: The branch varies based on the repository being used. Before running the `run_ut.sh` script, export the `BRANCH` variable for local Docker. This step is not required for CI Docker Jenkins.

**Example**:

```bash
export BRANCH=rdk-next
```

### Format for Configuration

Each line in the `dependency_repos.conf` file should follow this format:

```
repository_url branch_name repository_alias src_path dest_path
```

### Examples

1. **GitHub Repository**:

    ```
    https://github.com/org/repo.git main alias src_path dest_path
    ```

2. **Gerrit or CMF Repository**:

    ```
    ssh://host/repo_path branch alias src_path dest_path
    ```

### Guidelines for Configuration

#### 1. GitHub Repositories
- Use `main` as the primary branch.

#### 2. Gerrit Repositories
- Specify the branch as `branch` keyword. This uses the `$BRANCH` variable from the Jenkins environment, which maps to the latest sprint branch.

#### 3. Repository Alias
- Choose a descriptive `repository_alias`. This should reflect the repo name as it appears in Gerrit (generic) or GitHub.

#### 4. Source and Destination Paths
- Specify the source path (`src_path`) where the headers are located in the repository.
- Specify the destination path (`dest_path`) where the headers should be copied.

### Managing Multiple Entries for the Same Repository

When configuring multiple paths for the same repository, the `dependency_repos.conf` file allows you to specify multiple entries. The repository cloning process is optimized to avoid redundant operations. Here’s how it works:

- **Initial Clone**: The first entry of a repository in the `dependency_repos.conf` file triggers the git clone operation.
- **Subsequent Entries**: If the repository is listed again with different `src_path` and `dest_path` values, the system does not clone it again. Instead, it reuses the initially cloned repository to copy files from the new source to the designated destination path.

### Example

Consider you have multiple configurations for the same repository in your `dependency_repos.conf` file:

```
https://github.com/rdkcentral/rdkb-halif-platform.git main platform_hal include $HOME/usr/include/rdkb
https://github.com/rdkcentral/rdkb-halif-platform.git main platform_hal src/new_include $HOME/usr/include/rdkb/new_include
```

In this case:
- The repository `rdkcentral/rdkb-halif-platform` is cloned once and performs copying operation from `include` to `$HOME/usr/include/rdkb`.
- For the second entry, the system uses the existing clone and only performs the copying operation from `src/new_include` to `$HOME/usr/include/rdkb/new_include`.

### Adding Repositories

When adding new repositories, ensure that `branch_name`, `src_path`, and `dest_path` match your development requirements. Follow the format and guidelines provided above.

### Repository Entries

#### GitHub Repositories

Example:

```
https://github.com/rdkcentral/rbus.git main rbus include $HOME/usr/include/rdkb/rbus
```

#### Gerrit or CMF Repositories

Example:

```
<x>://<y>/<z> branch <brach_name> . $HOME/usr/include/rdkb
```

- **x**: Either `ssh` or `https` or if any.
- **y**: Either `code.rdkcentral.com` or `github.com/rdkcentral` or if any.
- **z**: Any rdkcentral repositories.
- **branch_name**: Any rdkcentral repositories branch name.

By following these guidelines and using the provided format, you can ensure proper configuration of repositories for your project.

---

# Contribution Guidelines

1. **Fork the Repository**: Work on a feature or bug fix in a separate branch.
2. **Test Your Changes**: Ensure that all tests pass before submission.
3. **Pull Request**: Submit a PR with a description of the changes.

---

# Support

For issues, contact the rdkb-gmock maintainers.

---

# License

This project is licensed under the Apache-2.0. See the `LICENSE` file for details.

---

# Acknowledgments

Thanks to all contributors and the RDK-B community for their support and efforts in maintaining this repository.