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
#ifndef MOCK_LPA_HAL_H
#define MOCK_LPA_HAL_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {
#include "lpa_hal.h"
}

class LpaHalInterface
{
public:
    virtual ~LpaHalInterface() {}
    virtual int cellular_esim_download_profile_with_activationcode(char* ActivationCodeStr, cellular_sim_download_progress_callback download_progress) = 0;
    virtual int cellular_esim_download_profile_from_smds(char* smds) = 0;
    virtual int cellular_esim_download_profile_from_defaultsmdp(char* smdp) = 0;
    virtual int cellular_esim_get_profile_info(eSIMProfileStruct **profile_list, int *nb_profiles) = 0;
    virtual int cellular_esim_enable_profile(char* iccid, int iccid_size) = 0;
    virtual int cellular_esim_disable_profile(char* iccid, int iccid_size) = 0;
    virtual int cellular_esim_delete_profile(char* iccid, int iccid_size) = 0;
    virtual int cellular_esim_lpa_init(void) = 0;
    virtual int cellular_esim_lpa_exit(void) = 0;
    virtual int cellular_esim_get_eid() = 0;
    virtual int cellular_esim_get_euicc() = 0;
};

class LpaHalMock : public LpaHalInterface
{
public:
    virtual ~LpaHalMock() {}
    MOCK_METHOD2(cellular_esim_download_profile_with_activationcode, int(char*, cellular_sim_download_progress_callback));
    MOCK_METHOD1(cellular_esim_download_profile_from_smds, int(char*));
    MOCK_METHOD1(cellular_esim_download_profile_from_defaultsmdp, int(char*));
    MOCK_METHOD2(cellular_esim_get_profile_info, int(eSIMProfileStruct **, int *));
    MOCK_METHOD2(cellular_esim_enable_profile, int(char*, int));
    MOCK_METHOD2(cellular_esim_disable_profile, int(char*, int));
    MOCK_METHOD2(cellular_esim_delete_profile, int(char*, int));
    MOCK_METHOD0(cellular_esim_lpa_init, int());
    MOCK_METHOD0(cellular_esim_lpa_exit, int());
    MOCK_METHOD0(cellular_esim_get_eid, int());
    MOCK_METHOD0(cellular_esim_get_euicc, int());
};

#endif // MOCK_LPA_HAL_H