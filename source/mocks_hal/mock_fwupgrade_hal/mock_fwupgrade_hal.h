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

#ifndef MOCK_FWUPGRADE_HAL_H
#define MOCK_FWUPGRADE_HAL_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "fwupgrade_hal.h"

class FwUpgradeHalInterface
{
public:
    virtual ~FwUpgradeHalInterface() {}
    virtual INT fwupgrade_hal_set_download_url(char* pUrl, char* filename) = 0;
    virtual INT fwupgrade_hal_get_download_url(char* pUrl, char* filename) = 0;
    virtual INT fwupgrade_hal_set_download_interface(unsigned int interface) = 0;
    virtual INT fwupgrade_hal_get_download_interface(unsigned int* interface) = 0;
    virtual INT fwupgrade_hal_download() = 0;
    virtual INT fwupgrade_hal_get_download_status() = 0;
    virtual INT fwupgrade_hal_reboot_ready(ULONG *pValue) = 0;
    virtual INT fwupgrade_hal_download_reboot_now() = 0;
    virtual INT fwupgrade_hal_update_and_factoryreset() = 0;
    virtual INT fwupgrade_hal_download_install(const char *url) = 0;
};

class FwUpgradeHalMock : public FwUpgradeHalInterface
{
public:
    virtual ~FwUpgradeHalMock() {}
    MOCK_METHOD2(fwupgrade_hal_set_download_url, INT(char*, char*));
    MOCK_METHOD2(fwupgrade_hal_get_download_url, INT(char*, char*));
    MOCK_METHOD1(fwupgrade_hal_set_download_interface, INT(unsigned int));
    MOCK_METHOD1(fwupgrade_hal_get_download_interface, INT(unsigned int*));
    MOCK_METHOD0(fwupgrade_hal_download, INT());
    MOCK_METHOD0(fwupgrade_hal_get_download_status, INT());
    MOCK_METHOD1(fwupgrade_hal_reboot_ready, INT(ULONG*));
    MOCK_METHOD0(fwupgrade_hal_download_reboot_now, INT());
    MOCK_METHOD0(fwupgrade_hal_update_and_factoryreset, INT());
    MOCK_METHOD1(fwupgrade_hal_download_install, INT(const char*));
};

#endif // MOCK_FWUPGRADE_HAL_H
