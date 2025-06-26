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
#ifndef MOCK_CELLULAR_MODEM_HAL_H
#define MOCK_CELLULAR_MODEM_HAL_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "cellular_modem_hal_api.h"

class ModemHalInterface
{
public:
    virtual ~ModemHalInterface() {}
    virtual int Modem_FactoryReset(void) = 0;
    virtual int Modem_Reboot(void) = 0;
    virtual int Modem_Firmware_Version(char *firmware_version) = 0;
};

class ModemHalMock : public ModemHalInterface
{
public:
    virtual ~ModemHalMock() {}
    MOCK_METHOD0(Modem_FactoryReset, int());
    MOCK_METHOD0(Modem_Reboot, int());
    MOCK_METHOD1(Modem_Firmware_Version, int(char*));
};

#endif // MOCK_CELLULAR_MODEM_HAL_H
