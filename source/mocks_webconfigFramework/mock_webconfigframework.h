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
#ifndef MOCK_WEBCONFIGFRAMEWORK_H
#define MOCK_WEBCONFIGFRAMEWORK_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#ifdef __cplusplus
extern "C" {
#endif
#include <webconfig_framework.h>
#ifdef __cplusplus
}
#endif

class webconfigFwInterface
{
    public:
        virtual ~webconfigFwInterface() {}
        virtual void PushBlobRequest (execData *) = 0;
        virtual void register_sub_docs(blobRegInfo *, int, getVersion, setVersion) = 0;
        virtual void check_component_crash(char*) = 0;
};

class webconfigFwMock: public webconfigFwInterface
{
    public:
        virtual ~webconfigFwMock() {}
        MOCK_METHOD1(PushBlobRequest, void(execData *));
        MOCK_METHOD4(register_sub_docs, void(blobRegInfo *, int, getVersion, setVersion));
        MOCK_METHOD1(check_component_crash, void(char*));
};

#endif //MOCK_WEBCONFIGFRAMEWORK_H