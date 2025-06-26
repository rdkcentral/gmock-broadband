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

#include "mock_fwupgrade_hal.h"

extern FwUpgradeHalMock *g_fwUpgradeHALMock;

extern "C" INT fwupgrade_hal_set_download_url(char* pUrl, char* filename)
{
    if (!g_fwUpgradeHALMock)
    {
        return 0;
    }
    return g_fwUpgradeHALMock->fwupgrade_hal_set_download_url(pUrl, filename);
}

extern "C" INT fwupgrade_hal_get_download_url(char* pUrl, char* filename)
{
    if (!g_fwUpgradeHALMock)
    {
        return 0;
    }
    return g_fwUpgradeHALMock->fwupgrade_hal_get_download_url(pUrl, filename);
}

extern "C" INT fwupgrade_hal_set_download_interface(unsigned int interface)
{
    if (!g_fwUpgradeHALMock)
    {
        return 0;
    }
    return g_fwUpgradeHALMock->fwupgrade_hal_set_download_interface(interface);
}

extern "C" INT fwupgrade_hal_get_download_interface(unsigned int* interface)
{
    if (!g_fwUpgradeHALMock)
    {
        return 0;
    }
    return g_fwUpgradeHALMock->fwupgrade_hal_get_download_interface(interface);
}

extern "C" INT fwupgrade_hal_download()
{
    if (!g_fwUpgradeHALMock)
    {
        return 0;
    }
    return g_fwUpgradeHALMock->fwupgrade_hal_download();
}

extern "C" INT fwupgrade_hal_get_download_status()
{
    if (!g_fwUpgradeHALMock)
    {
        return 0;
    }
    return g_fwUpgradeHALMock->fwupgrade_hal_get_download_status();
}

extern "C" INT fwupgrade_hal_reboot_ready(ULONG *pValue)
{
    if (!g_fwUpgradeHALMock)
    {
        return 0;
    }
    return g_fwUpgradeHALMock->fwupgrade_hal_reboot_ready(pValue);
}

extern "C" INT fwupgrade_hal_download_reboot_now()
{
    if (!g_fwUpgradeHALMock)
    {
        return 0;
    }
    return g_fwUpgradeHALMock->fwupgrade_hal_download_reboot_now();
}

extern "C" INT fwupgrade_hal_update_and_factoryreset()
{
    if (!g_fwUpgradeHALMock)
    {
        return 0;
    }
    return g_fwUpgradeHALMock->fwupgrade_hal_update_and_factoryreset();
}

extern "C" INT fwupgrade_hal_download_install(const char *url)
{
    if (!g_fwUpgradeHALMock)
    {
        return 0;
    }
    return g_fwUpgradeHALMock->fwupgrade_hal_download_install(url);
}