/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:
*
* Copyright 2020 RDK Management
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
#include "mock_emmc_hal.h"

extern EmmcHalMock *g_emmcHALMock;

extern "C" eSTMGRReturns CcspHalEmmcGetHealthInfo(eSTMGRHealthInfo* pHealthInfo)
{
    if (!g_emmcHALMock)
    {
        return RDK_STMGR_RETURN_GENERIC_FAILURE;
    }
    return g_emmcHALMock->CcspHalEmmcGetHealthInfo(pHealthInfo);
}

extern "C" eSTMGRReturns CcspHalEmmcGetDeviceInfo(eSTMGRDeviceInfo* pDeviceInfo)
{
    if (!g_emmcHALMock)
    {
        return RDK_STMGR_RETURN_GENERIC_FAILURE;
    }
    return g_emmcHALMock->CcspHalEmmcGetDeviceInfo(pDeviceInfo);
}
