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

#include "mock_psm.h"

using namespace std;

extern PsmMock * g_psmMock;

extern "C" int PSM_Get_Record_Value2
(
    void*                       bus_handle,
    char const * const          pSubSystemPrefix,
    char const * const          pRecordName,
    unsigned int *              ulRecordType,
    char**                      pValue
)
{
	if(!g_psmMock)
	{
		return 0;
	}
	return g_psmMock->PSM_Get_Record_Value2(bus_handle, pSubSystemPrefix, pRecordName, ulRecordType, pValue);
}

extern "C" int PSM_Set_Record_Value2
(
        void*                       bus_handle,
    char const * const          pSubSystemPrefix,
    char const * const          pRecordName,
    unsigned int const          ulRecordType,
    char const * const          pVal
)
{
        if(!g_psmMock)
        {
                return false;
        }
        return g_psmMock->PSM_Set_Record_Value2(bus_handle,pSubSystemPrefix,pRecordName,ulRecordType,pVal);
}

extern "C" int PsmGetNextLevelInstances
(
    void* bus_handle,
    char const * const pSubSystemPrefix,
    char const * const pParentPath,
    unsigned int* pulNumInstance,
    unsigned int**  ppInstanceArray
)
{
    if (!g_psmMock)
    {
        return false;
    }
    return g_psmMock->PsmGetNextLevelInstances(bus_handle, pSubSystemPrefix, pParentPath, pulNumInstance, ppInstanceArray);
}

