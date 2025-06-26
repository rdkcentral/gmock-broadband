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

#ifndef MOCK_ANSC_MEMORY_H
#define MOCK_ANSC_MEMORY_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#ifndef ULONG
typedef unsigned long ULONG;
#endif

class AnscMemoryInterface
{
    public:
        virtual ~AnscMemoryInterface() {}
        virtual void * Ansc_AllocateMemory_Callback(ULONG ulMemorySize) = 0;
        virtual void Ansc_FreeMemory_Callback(void * pMemory) = 0;
        virtual void AnscFreeMemoryOrig(void * pMemoryBlock) = 0;
};

class AnscMemoryMock : public AnscMemoryInterface
{
    public:
        virtual ~AnscMemoryMock() {}
        MOCK_METHOD1(Ansc_AllocateMemory_Callback, void * (ULONG ulMemorySize));
        MOCK_METHOD1(Ansc_FreeMemory_Callback, void(void * pMemory));
        MOCK_METHOD1(AnscFreeMemoryOrig, void(void * pMemoryBlock));
};

#endif
