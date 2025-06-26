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

#include "mock_slap.h"

extern SlapMock * g_slapMock;

extern "C" SLAP_HANDLE SlapVcoStringToCalendarTime(ANSC_HANDLE hThisObject, char* calendar_time)
{
    if (!g_slapMock)
    {
        return NULL;
    }
    return g_slapMock->SlapVcoStringToCalendarTime(hThisObject, calendar_time);
}

extern "C" SLAP_UINT32 SlapVcoStringToIp4Addr(ANSC_HANDLE hThisObject, char* ip4_addr)
{
    if (!g_slapMock)
    {
        return 0;
    }
    return g_slapMock->SlapVcoStringToIp4Addr(hThisObject, ip4_addr);
}

extern "C" SLAP_UCHAR_ARRAY* SlapVcoStringToMacAddr(ANSC_HANDLE hThisObject, char* mac_addr)
{
    if (!g_slapMock)
    {
        return NULL;
    }
    return g_slapMock->SlapVcoStringToMacAddr(hThisObject, mac_addr);
}

extern "C" void SlapVhoCleanVarArray(ANSC_HANDLE hThisObject, ANSC_HANDLE slap_array)
{
    if (!g_slapMock)
    {
        return;
    }
    return g_slapMock->SlapVhoCleanVarArray(hThisObject, slap_array);
}

extern "C" char* SlapVcoIp4AddrToString2(ANSC_HANDLE hThisObject, SLAP_UINT32 ip4_addr)
{
    if (!g_slapMock)
    {
        return NULL;
    }
    return g_slapMock->SlapVcoIp4AddrToString2(hThisObject, ip4_addr);
}