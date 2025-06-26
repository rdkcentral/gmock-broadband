/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
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

#ifndef MOCK_ANSC_CO_H
#define MOCK_ANSC_CO_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C"
{
   #include "ansc_platform.h"
}

class AnscCoInterface {
public:
    virtual ~AnscCoInterface() {}
    virtual ANSC_STATUS AnscCoRemove(ANSC_HANDLE hThisObject) = 0;
    virtual ANSC_STATUS AnscCoInitialize(ANSC_HANDLE hThisObject) = 0;
    virtual ANSC_STATUS AnscCoEnrollObjects(ANSC_HANDLE hThisObject) = 0;
};

class AnscCoMock : public AnscCoInterface {
public:
    virtual ~AnscCoMock() {}
    MOCK_METHOD1(AnscCoRemove, ANSC_STATUS(ANSC_HANDLE hThisObject));
    MOCK_METHOD1(AnscCoInitialize, ANSC_STATUS(ANSC_HANDLE hThisObject));
    MOCK_METHOD1(AnscCoEnrollObjects, ANSC_STATUS(ANSC_HANDLE hThisObject));
};

#endif // MOCK_ANSC_CO_H
