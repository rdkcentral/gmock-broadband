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

#ifndef MOCK_CCSP_DM_API_H
#define MOCK_CCSP_DM_API_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {
    #include "ccsp_base_api.h"
    #include "ccsp_dm_api.h"
}

class CcspDmApiInterface {
public:
    virtual ~CcspDmApiInterface() {}
    virtual DmErr_t Cdm_GetNames(const char *path, int recursive, char (**names)[CDM_PATH_SZ], int *cnt) = 0;
    virtual void Cdm_FreeNames(char (*names)[CDM_PATH_SZ]) = 0;
};

class CcspDmApiMock : public CcspDmApiInterface {
public:
    virtual ~CcspDmApiMock() {}
    MOCK_METHOD4(Cdm_GetNames, DmErr_t(const char *, int, char (**)[CDM_PATH_SZ], int *));
    MOCK_METHOD1(Cdm_FreeNames, void(char (*)[CDM_PATH_SZ]));
};

#endif 