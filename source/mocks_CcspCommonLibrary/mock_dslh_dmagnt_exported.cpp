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

#include "mock_dslh_dmagnt_exported.h"

extern DslhDmagntExportedMock* g_dslhDmagntExportedMock;

extern "C" ANSC_STATUS COSAGetParamValueByPathName(
    void* bus_handle,
    parameterValStruct_t *val,
    ULONG *parameterValueLength)
    
{
    if (!g_dslhDmagntExportedMock) {
        return ANSC_STATUS_FAILURE; 
    }
    return g_dslhDmagntExportedMock->COSAGetParamValueByPathName(bus_handle, val, parameterValueLength);
    
}

extern "C" ANSC_STATUS COSAGetParamValueString(
        void*                       hDmlAgent,
        char*                       pParamName,
        char*                       pBuffer,
        PULONG                      pulSize
    )
{
    printf("%s %d\n",__FUNCTION__,__LINE__);
    if (!g_dslhDmagntExportedMock) {
        return ANSC_STATUS_FAILURE;
    }
    return g_dslhDmagntExportedMock->COSAGetParamValueString(hDmlAgent, pParamName, pBuffer,pulSize);
}
