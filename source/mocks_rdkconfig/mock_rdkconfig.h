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
#ifndef MOCK_RDKCONFIG_H
#define MOCK_RDKCONFIG_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C"
{
int rdkconfig_get(uint8_t **, size_t *, const char *);
int rdkconfig_free(uint8_t **, size_t);
}

class rdkconfigInterface
{
    public:
        virtual ~rdkconfigInterface() {}
        virtual int rdkconfig_get(uint8_t **, size_t *, const char *) = 0;
        virtual int rdkconfig_free(uint8_t **, size_t) = 0;
};

class rdkconfigMock: public rdkconfigInterface
{
    public:
        virtual ~rdkconfigMock() {}
        MOCK_METHOD3(rdkconfig_get, int(uint8_t **, size_t *, const char *));
        MOCK_METHOD2(rdkconfig_free, int(uint8_t **, size_t));
};

#endif //MOCK_RDKCONFIG_H
