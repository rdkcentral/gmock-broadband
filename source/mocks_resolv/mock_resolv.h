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
#ifndef MOCK_RESOLV_H
#define MOCK_RESOLV_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>


#include <resolv.h>

// Define an interface for resolv functions
class ResolvInterface {
public:
    virtual ~ResolvInterface() {}

    virtual int ns_initparse(const u_char* msg, int msglen, ns_msg* handle) = 0;
    virtual int ns_msg_getflag(ns_msg handle, int flag) = 0;
    virtual int ns_parserr(ns_msg* handle, ns_sect section, int rrnum, ns_rr* rr) = 0;
};

// Mock class that implements the ResolvInterface
class ResolvMock : public ResolvInterface {
public:
    virtual ~ResolvMock() {}

    MOCK_METHOD(int, ns_initparse, (const u_char* msg, int msglen, ns_msg* handle), (override));
    MOCK_METHOD(int, ns_msg_getflag, (ns_msg handle, int flag), (override));
    MOCK_METHOD(int, ns_parserr, (ns_msg* handle, ns_sect section, int rrnum, ns_rr* rr), (override));
};
#endif
