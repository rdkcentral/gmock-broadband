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

#ifndef MOCK_TELEMETRY_H
#define MOCK_TELEMETRY_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C"
{
#include <telemetry_busmessage_sender.h>
#include <telemetry2_0.h>
}

class telemetryInterface
{
    public:
        virtual ~telemetryInterface() {}
        virtual T2ERROR t2_event_s(const char* marker, const char* value) = 0;
        virtual T2ERROR t2_event_d(const char* marker, int value) = 0;
        virtual void t2_init(char *component) = 0;
};

class telemetryMock: public telemetryInterface
{
    public:
        virtual ~telemetryMock() {}
        MOCK_METHOD2(t2_event_s, T2ERROR(const char*, const char*));
        MOCK_METHOD2(t2_event_d, T2ERROR(const char*, int));
        MOCK_METHOD1(t2_init, void(char*));
};


#endif //MOCK_TELEMETRY_H
