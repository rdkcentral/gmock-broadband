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

#include "mock_mso_mgmt_hal.h"

extern MsoMgmtHalMock *g_msoMgmtHALMock;

extern "C" mso_pwd_ret_status mso_validatepwd(char *pwd)
{
    if (!g_msoMgmtHALMock)
    {
        return Invalid_PWD;
    }
    return g_msoMgmtHALMock->mso_validatepwd(pwd);
}

extern "C" INT mso_set_pod_seed(char *pSeed)
{
    if (!g_msoMgmtHALMock)
    {
        return 0;
    }
    return g_msoMgmtHALMock->mso_set_pod_seed(pSeed);
}

extern "C" INT mso_get_pod_seed(char* pSeed)
{
    if (!g_msoMgmtHALMock)
    {
        return 0;
    }
    return g_msoMgmtHALMock->mso_get_pod_seed(pSeed);
}