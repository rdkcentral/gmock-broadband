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
#include "mock_lpa_hal.h"

extern LpaHalMock *g_lpaHALMock;

extern "C" int cellular_esim_download_profile_with_activationcode(char* ActivationCodeStr, cellular_sim_download_progress_callback download_progress)
{
    if (!g_lpaHALMock)
    {
        return 0;
    }
    return g_lpaHALMock->cellular_esim_download_profile_with_activationcode(ActivationCodeStr, download_progress);
}

extern "C" int cellular_esim_download_profile_from_smds(char* smds)
{
    if (!g_lpaHALMock)
    {
        return 0;
    }
    return g_lpaHALMock->cellular_esim_download_profile_from_smds(smds);
}

extern "C" int cellular_esim_download_profile_from_defaultsmdp(char* smdp)
{
    if (!g_lpaHALMock)
    {
        return 0;
    }
    return g_lpaHALMock->cellular_esim_download_profile_from_defaultsmdp(smdp);
}

extern "C" int cellular_esim_get_profile_info(eSIMProfileStruct **profile_list, int *nb_profiles)
{
    if (!g_lpaHALMock)
    {
        return 0;
    }
    return g_lpaHALMock->cellular_esim_get_profile_info(profile_list, nb_profiles);
}

extern "C" int cellular_esim_enable_profile(char* iccid, int iccid_size)
{
    if (!g_lpaHALMock)
    {
        return 0;
    }
    return g_lpaHALMock->cellular_esim_enable_profile(iccid, iccid_size);
}

extern "C" int cellular_esim_disable_profile(char* iccid, int iccid_size)
{
    if (!g_lpaHALMock)
    {
        return 0;
    }
    return g_lpaHALMock->cellular_esim_disable_profile(iccid, iccid_size);
}

extern "C" int cellular_esim_delete_profile(char* iccid, int iccid_size)
{
    if (!g_lpaHALMock)
    {
        return 0;
    }
    return g_lpaHALMock->cellular_esim_delete_profile(iccid, iccid_size);
}

extern "C" int cellular_esim_lpa_init(void)
{
    if (!g_lpaHALMock)
    {
        return 0;
    }
    return g_lpaHALMock->cellular_esim_lpa_init();
}

extern "C" int cellular_esim_lpa_exit(void)
{
    if (!g_lpaHALMock)
    {
        return 0;
    }
    return g_lpaHALMock->cellular_esim_lpa_exit();
}

extern "C" int cellular_esim_get_eid()
{
    if (!g_lpaHALMock)
    {
        return 0;
    }
    return g_lpaHALMock->cellular_esim_get_eid();
}

extern "C" int cellular_esim_get_euicc()
{
    if (!g_lpaHALMock)
    {
        return 0;
    }
    return g_lpaHALMock->cellular_esim_get_euicc();
}