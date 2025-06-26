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

#ifndef MOCK_MSO_MGMT_HAL_H
#define MOCK_MSO_MGMT_HAL_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {
#include "mso_mgmt_hal.h"
}

class MsoMgmtHalInterface
{
public:
    virtual ~MsoMgmtHalInterface() {}
    virtual mso_pwd_ret_status mso_validatepwd(char *pwd) = 0;
    virtual INT mso_set_pod_seed(char *pSeed) = 0;
    virtual INT mso_get_pod_seed(char* pSeed) = 0;
};

class MsoMgmtHalMock : public MsoMgmtHalInterface
{
public:
    virtual ~MsoMgmtHalMock() {}
    MOCK_METHOD1(mso_validatepwd, mso_pwd_ret_status(char*));
    MOCK_METHOD1(mso_set_pod_seed, INT(char*));
    MOCK_METHOD1(mso_get_pod_seed, INT(char*));
};

#endif // MOCK_MSO_MGMT_HAL_H
