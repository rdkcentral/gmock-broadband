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
#ifndef MOCK_BASE64_H
#define MOCK_BASE64_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdint.h>
#include <stddef.h>


class base64Interface
{
    public:
        virtual ~base64Interface() {}
        virtual size_t b64_get_encoded_buffer_size(const size_t) = 0;
        virtual void b64_encode(const uint8_t *, const size_t, uint8_t *) = 0;
        virtual size_t b64_get_decoded_buffer_size(const size_t) = 0;
        virtual size_t b64_decode(const uint8_t *, const size_t, uint8_t *) = 0;
};

class base64Mock: public base64Interface
{
    public:
        virtual ~base64Mock() {}
        MOCK_METHOD1(b64_get_encoded_buffer_size, size_t(const size_t));
        MOCK_METHOD3(b64_encode, void(const uint8_t *, const size_t, uint8_t *));
        MOCK_METHOD1(b64_get_decoded_buffer_size, size_t(const size_t));
        MOCK_METHOD3(b64_decode, size_t(const uint8_t *, const size_t, uint8_t *));
};

#endif //MOCK_BASE64_H