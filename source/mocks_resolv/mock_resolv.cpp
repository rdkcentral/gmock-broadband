/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:
*
* Copyright 2024 RDK Management
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
#include "mock_resolv.h"

// Declare a global pointer to the mock object, so it can be used in the tests
extern ResolvMock* g_resolvMock;

// Wrapper functions that call the mock methods
extern "C" int ns_initparse(const u_char* msg, int msglen, ns_msg* handle) {
    if (g_resolvMock) {
        return g_resolvMock->ns_initparse(msg, msglen, handle);
    }
    return -1;  // Default return value for error
}

extern "C" int ns_msg_getflag(ns_msg handle, int flag) {
    if (g_resolvMock) {
        return g_resolvMock->ns_msg_getflag(handle, flag);
    }
    return -1;  // Default return value for error
}

extern "C" int ns_parserr(ns_msg* handle, ns_sect section, int rrnum, ns_rr* rr) {
    if (g_resolvMock) {
        return g_resolvMock->ns_parserr(handle, section, rrnum, rr);
    }
    return -1;  // Default return value for error
}

