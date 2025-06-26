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

#ifndef MOCK_ANSC_TASK_H
#define MOCK_ANSC_TASK_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

typedef void* PVOID;
#ifndef ULONG
#define ULONG unsigned long
#endif
typedef PVOID ANSC_HANDLE;
typedef ULONG ANSC_STATUS;

class AnscTaskInterface {
public:
    virtual ~AnscTaskInterface() {}
    virtual ANSC_STATUS AnscSpawnTask(void* pTaskEntry,ANSC_HANDLE hTaskContext,char* name) = 0;
    virtual void *UserCreateTask(void *routine, ULONG stackSize, int priority, void * context, void * name) = 0;
};

class AnscTaskMock : public AnscTaskInterface {
public:
    virtual ~AnscTaskMock() {}
    MOCK_METHOD(ANSC_STATUS, AnscSpawnTask, (void* pTaskEntry, ANSC_HANDLE hTaskContext, char* name), (override));
    MOCK_METHOD(void *, UserCreateTask, (void *routine, ULONG stackSize, int priority, void * context, void * name), (override));
};

#endif // MOCK_ANSC_TASK_H

