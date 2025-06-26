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

#ifndef MOCK_SLAP_H
#define MOCK_SLAP_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {
#include "slap_definitions.h"
}

typedef void* PVOID;
#ifndef ULONG
#define ULONG unsigned long
#endif
typedef PVOID ANSC_HANDLE;


class SlapInterface {
public:
    virtual ~SlapInterface() {}
    virtual SLAP_HANDLE SlapVcoStringToCalendarTime(ANSC_HANDLE hThisObject, char* calendar_time) = 0;
    virtual SLAP_UINT32 SlapVcoStringToIp4Addr(ANSC_HANDLE hThisObject, char* ip4_addr) = 0;
    virtual SLAP_UCHAR_ARRAY* SlapVcoStringToMacAddr(ANSC_HANDLE hThisObject, char* mac_addr) = 0;
    virtual void SlapVhoCleanVarArray(ANSC_HANDLE hThisObject, ANSC_HANDLE slap_array) = 0;
    virtual char* SlapVcoIp4AddrToString2(ANSC_HANDLE hThisObject, SLAP_UINT32 ip4_addr) = 0;
};

class SlapMock : public SlapInterface {
public:
    virtual ~SlapMock() {}
    MOCK_METHOD(SLAP_HANDLE, SlapVcoStringToCalendarTime, (ANSC_HANDLE hThisObject, char* calendar_time), (override));
    MOCK_METHOD(SLAP_UINT32, SlapVcoStringToIp4Addr, (ANSC_HANDLE hThisObject, char* ip4_addr), (override));
    MOCK_METHOD(SLAP_UCHAR_ARRAY*, SlapVcoStringToMacAddr, (ANSC_HANDLE hThisObject, char* mac_addr), (override));
    MOCK_METHOD(void, SlapVhoCleanVarArray, (ANSC_HANDLE hThisObject, ANSC_HANDLE slap_array), (override));
    MOCK_METHOD(char*, SlapVcoIp4AddrToString2, (ANSC_HANDLE hThisObject, SLAP_UINT32 ip4_addr), (override));
};

#endif // MOCK_SLAP_H
