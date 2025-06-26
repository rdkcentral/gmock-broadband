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


#ifndef MOCK_CAP_H
#define MOCK_CAP_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sys/capability.h>
extern "C" {
    typedef struct _cap_user {
      cap_value_t add[CAP_LAST_CAP+1];
      cap_value_t drop[CAP_LAST_CAP+1];
      cap_value_t caps_default[CAP_LAST_CAP+1];
      char *user_name;
      short add_count;
      short drop_count;
      short default_count;
      char *caps;
    }cap_user;
}

class CapInterface
{
public:
    virtual ~CapInterface(){}
    virtual int drop_root_caps(cap_user *_appcaps) = 0;
    virtual cap_t init_capability(void) = 0;
    virtual void read_capability(cap_user * _appcaps) = 0;
    virtual int update_process_caps(cap_user * _appcaps) = 0;
};

class CapMock: public CapInterface
{
public:
    virtual ~CapMock(){}
    MOCK_METHOD1(drop_root_caps, int(cap_user *_appcaps));
    MOCK_METHOD0(init_capability, cap_t(void));
    MOCK_METHOD1(read_capability, void(cap_user * _appcaps));
    MOCK_METHOD1(update_process_caps, int(cap_user * _appcaps));
};

#endif
