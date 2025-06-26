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
#include "mock_cellular_modem_hal.h"

extern ModemHalMock *g_modemHALMock;

extern "C" int Modem_FactoryReset(void)
{
    if (!g_modemHALMock)
    {
        return 0;
    }
    return g_modemHALMock->Modem_FactoryReset();
}

extern "C" int Modem_Reboot(void)
{
    if (!g_modemHALMock)
    {
        return 0;
    }
    return g_modemHALMock->Modem_Reboot();
}

extern "C" int Modem_Firmware_Version(char *firmware_version)
{
    if (!g_modemHALMock)
    {
        return 0;
    }
    return g_modemHALMock->Modem_Firmware_Version(firmware_version);
}