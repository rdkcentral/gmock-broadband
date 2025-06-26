/*****************************************************************************
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
****************************************************************************/
#include "mock_scheduler.h"

using namespace std;

extern scheduleLibMock * g_scheduleLibMock;

extern "C" void freeScheduleInfo(schedule_info_t* schedule)
{
    if (!g_scheduleLibMock)
    {
        return;
    }
    return g_scheduleLibMock->freeScheduleInfo(schedule);
}
extern "C" int run_schedule(schedule_info_t *t, char* action_key)
{
    if (!g_scheduleLibMock)
    {
        return 0;
    }
    return g_scheduleLibMock->run_schedule(t, action_key);
}

extern "C" int delete_schedule(char *action_key)
{
    if (!g_scheduleLibMock)
    {
        return 0;
    }
    return g_scheduleLibMock->delete_schedule(action_key);
}
