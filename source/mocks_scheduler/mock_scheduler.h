/*************************************************************************
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
**************************************************************************/

#ifndef MOCK_SCHEDULER_H
#define MOCK_SCHEDULER_H
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct schedule_info_t {
    int dummy;
} schedule_info_t;

// Dummy prototypes for required APIs
void freeScheduleInfo(schedule_info_t* schedule);
int run_schedule(schedule_info_t *t, char* action_key);
int delete_schedule(char *action_key);

#ifdef __cplusplus
}
#endif

class scheduleLibOperations
{
    public:
        virtual ~scheduleLibOperations() {}
        virtual void freeScheduleInfo(schedule_info_t* schedule) = 0;
        virtual int run_schedule(schedule_info_t *t, char* action_key) = 0;
        virtual int delete_schedule(char *action_key) = 0;
};

class scheduleLibMock : public scheduleLibOperations
{
    public:
        virtual ~scheduleLibMock () {}
        MOCK_METHOD1(freeScheduleInfo, void(schedule_info_t*));
        MOCK_METHOD1(delete_schedule, int (char *));
        MOCK_METHOD2(run_schedule, int(schedule_info_t *, char*));
};

#endif
