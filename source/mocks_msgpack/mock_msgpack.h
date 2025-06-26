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
#ifndef MOCK_MSGPACK_H
#define MOCK_MSGPACK_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <stdint.h>
#include <stddef.h>

extern "C"
{
#include "msgpack.h"
#include "msgpack/unpack.h"
#include "msgpack/sbuffer.h"
#include "msgpack/vrefbuffer.h"
#include "msgpack/pack.h"
#include "msgpack/version.h"
#include "msgpack/zone.h"
#include "msgpack/object.h"
}

class msgpackInterface
{
    public:
        virtual ~msgpackInterface() {}
        virtual bool msgpack_zone_init(msgpack_zone*, size_t) = 0;
        virtual msgpack_unpack_return msgpack_unpack(const char*, size_t, size_t*, msgpack_zone*, msgpack_object*) = 0;
        virtual void msgpack_zone_destroy(msgpack_zone*) = 0;
        virtual msgpack_unpack_return msgpack_unpack_next(msgpack_unpacked* result, const char* data, size_t len, size_t* off) = 0;
        virtual void msgpack_object_print(FILE* out, msgpack_object o) = 0;
        virtual void msgpack_zone_free(msgpack_zone* zone) = 0;
};

class msgpackMock: public msgpackInterface
{
    public:
        virtual ~msgpackMock() {}
        MOCK_METHOD2(msgpack_zone_init, bool(msgpack_zone*, size_t));
        MOCK_METHOD5(msgpack_unpack, msgpack_unpack_return(const char*, size_t, size_t*, msgpack_zone*, msgpack_object*));
        MOCK_METHOD1(msgpack_zone_destroy, void(msgpack_zone*));
        MOCK_METHOD4(msgpack_unpack_next, msgpack_unpack_return(msgpack_unpacked* result, const char* data, size_t len, size_t* off));
        MOCK_METHOD2(msgpack_object_print, void(FILE* out, msgpack_object o));
        MOCK_METHOD1(msgpack_zone_free, void(msgpack_zone* zone));
};

#endif //MOCK_MSGPACK_H