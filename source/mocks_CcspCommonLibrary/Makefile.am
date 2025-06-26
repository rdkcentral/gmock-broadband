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
AM_CFLAGS = -D_GNU_SOURCE
AM_CFLAGS += -fPIC -fno-exceptions -Os -Wall -Wextra

AM_CXXFLAGS = -std=c++11 -lstdc++fs

ACLOCAL_AMFLAGS = -I m4

lib_LTLIBRARIES = libmock_ccsp_common.la

libmock_ccsp_common_la_CPPFLAGS = -I$(PKG_CONFIG_SYSROOT_DIR)$(includedir)/ccsp \
                                  -I$(PKG_CONFIG_SYSROOT_DIR)$(includedir)/dbus-1.0 \
                                  -I$(PKG_CONFIG_SYSROOT_DIR)$(libdir)/dbus-1.0/include

libmock_ccsp_common_la_SOURCES = mock_messagebus.cpp mock_ansc_memory.cpp mock_ansc_wrapper_api.cpp \
                                 mock_usertime.cpp mock_base_api.cpp mock_trace.cpp mock_ansc_debug.cpp \
                                 mock_user_runtime.cpp mock_ccsp_dmapi.cpp mock_dslh_dmagnt_exported.cpp \
                                 mock_ansc_co.cpp mock_ansc_file_io.cpp mock_ansc_xml.cpp mock_ansc_crypto.cpp \
                                 mock_ansc_timer_scheduler.cpp mock_SysInfoRepository.cpp mock_ansc_task.cpp \
                                 mock_slap.cpp
libmock_ccsp_common_la_LDFLAGS = -lgtest -lgmock

if UNIT_TEST_DOCKER_SUPPORT
libmock_ccsp_common_la_LDFLAGS += -static
endif
