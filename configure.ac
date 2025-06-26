##########################################################################
# If not stated otherwise in this file or this component's Licenses.txt
# file the following copyright and licenses apply:
#
# Copyright 2015 RDK Management
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
##########################################################################
#                                              -*- Autoconf -*-
# Process this file with autoconf to produce configure script.
#

AC_PREREQ([2.65])
AC_INIT([RdkbGMock], [1.0], [BUG-REPORT-ADDRESS])
AM_INIT_AUTOMAKE
LT_INIT

AC_ARG_ENABLE([unitTestDockerSupport],
             AS_HELP_STRING([--enable-unitTestDockerSupport],[enable docker support for unit testing (default is no)]),
             [
              UNIT_TEST_DOCKER_SUPPORT=""
               case "${enableval}" in
                yes) UNIT_TEST_DOCKER_SUPPORT=true;;
                no) UNIT_TEST_DOCKER_SUPPORT=false;;
                 *) AC_MSG_ERROR([bad value ${enableval} for --enable-unitTestDockerSupport ]);;
               esac
             ],
             [echo "Docker support is disabled"])
AM_CONDITIONAL([UNIT_TEST_DOCKER_SUPPORT], [test x$UNIT_TEST_DOCKER_SUPPORT = xtrue])

AC_PREFIX_DEFAULT(`pwd`)
AC_ENABLE_SHARED
AC_DISABLE_STATIC

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

# Checks for programs.
AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL
AM_PROG_CC_C_O
AM_PROG_LIBTOOL(libtool)

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE

# Checks for library functions.
AC_FUNC_MALLOC

AC_CONFIG_FILES(
    source/mocks_fd/Makefile
    source/mocks_file_io/Makefile
    source/mocks_CcspCommonLibrary/Makefile
    source/mocks_psm/Makefile
    source/mocks_socket/Makefile
    source/mocks_syscfg/Makefile
    source/mocks_sysevent/Makefile
    source/mocks_util/Makefile
    source/mocks_rbus/Makefile
    source/mocks_safec_lib/Makefile
    source/mocks_hal/Makefile
    source/mocks_hal/mock_platform_hal/Makefile
    source/mocks_SyscallWrapper/Makefile
    source/mocks_unpriv/Makefile
    source/mocks_hal/mock_mta_hal/Makefile
    source/mocks_hal/mock_cm_hal/Makefile
    source/mocks_hal/mock_moca_hal/Makefile
    source/mocks_hal/mock_fwupgrade_hal/Makefile
    source/mocks_hal/mock_mso_mgmt_hal/Makefile
    source/mocks_hal/mock_emmc_hal/Makefile
    source/mocks_hal/mock_cellular_modem_hal/Makefile
    source/mocks_hal/mock_lpa_hal/Makefile
    source/mocks_hal/mock_ethsw_hal/Makefile
    source/mocks_hal/mock_wifi_hal/Makefile
    source/mocks_rdk_logger/Makefile
    source/mocks_CcspMisc/Makefile
    source/mocks_CcspMisc/mock_TimeConv/Makefile
    source/mocks_base64/Makefile
    source/mocks_parodus/Makefile
    source/mocks_webconfigFramework/Makefile
    source/mocks_cJSON/Makefile
    source/mocks_msgpack/Makefile
    source/mocks_utopia/Makefile
    source/mocks_telemetry/Makefile
    source/mocks_pthread/Makefile
    source/mocks_mqhandler/Makefile
    source/mocks_scheduler/Makefile
    source/mocks_jansson/Makefile
    source/mocks_nfqueue/Makefile
    source/mocks_libev/Makefile
    source/mocks_pcap/Makefile
    source/mocks_resolv/Makefile
    source/mocks_netsnmp/Makefile
    source/mocks_libxml/Makefile
    source/mocks_rdkconfig/Makefile
    source/mocks_coreNet_lib/Makefile
    source/Makefile
    Makefile
)

AC_SUBST(UNIT_TEST_DOCKER_SUPPORT)

AC_OUTPUT
