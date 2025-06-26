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
#include "mock_msgpack.h"

extern msgpackMock *g_msgpackMock;

extern "C" bool msgpack_zone_init(msgpack_zone* zone, size_t chunk_size)
{
    if (!g_msgpackMock)
    {
        return 0;
    }
    return g_msgpackMock->msgpack_zone_init(zone, chunk_size);
}

extern "C" msgpack_unpack_return msgpack_unpack(const char* data, size_t len, size_t* off, msgpack_zone* zone, msgpack_object* result)
{
    if (!g_msgpackMock)
    {
        return MSGPACK_UNPACK_PARSE_ERROR;
    }
    return g_msgpackMock->msgpack_unpack(data, len, off, zone, result);
}

extern "C" void msgpack_zone_destroy(msgpack_zone* zone)
{
    if (g_msgpackMock)
    {
        g_msgpackMock->msgpack_zone_destroy(zone);
    }
}

extern "C" msgpack_unpack_return msgpack_unpack_next(msgpack_unpacked* result, const char* data, size_t len, size_t* off)
{
    if (!g_msgpackMock)
    {
        return MSGPACK_UNPACK_PARSE_ERROR;
    }
    return g_msgpackMock->msgpack_unpack_next(result, data, len, off);
}

extern "C" void msgpack_object_print(FILE* out, msgpack_object o)
{
    if (g_msgpackMock)
    {
        g_msgpackMock->msgpack_object_print(out, o);
    }
}

extern "C" void msgpack_zone_free(msgpack_zone* zone)
{
    if (g_msgpackMock)
    {
        g_msgpackMock->msgpack_zone_free(zone);
    }
}