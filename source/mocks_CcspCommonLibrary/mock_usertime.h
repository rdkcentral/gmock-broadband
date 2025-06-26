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

#ifndef MOCK_USER_TIME_H
#define MOCK_USER_TIME_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C"
{
#include <user_base.h>
#include <user_time.h>
}

class UserTimeInterface {
public:
        virtual ~UserTimeInterface() {}
        virtual void UserGetLocalTime(USER_SYSTEM_TIME* ) = 0;
        virtual ULONG UserGetTickInSeconds2() = 0; 
};

class UserTimeMock: public UserTimeInterface {
public:
        virtual ~UserTimeMock() {}
        MOCK_METHOD1(UserGetLocalTime, void(USER_SYSTEM_TIME *));
        MOCK_METHOD0(UserGetTickInSeconds2, ULONG());
  
};
#endif
