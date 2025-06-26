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
#include "mock_jansson.h"

extern JanssonMock *g_janssonMock;

extern "C" json_t *json_object_get(const json_t *object, const char *key)
{
    if (g_janssonMock)
    {
        return g_janssonMock->json_object_get(object, key);
    }
    return NULL;
}

extern "C" void json_delete(json_t *json)
{
    if (g_janssonMock)
    {
        g_janssonMock->json_delete(json);
    }
}

extern "C" json_t *json_object(void)
{
    if (g_janssonMock)
    {
        return g_janssonMock->json_object();
    }
    return NULL;
}

extern "C" json_t *json_array(void)
{
    if (g_janssonMock)
    {
        return g_janssonMock->json_array();
    }
    return NULL;
}

extern "C" json_t *json_true(void)
{
    if (g_janssonMock)
    {
        return g_janssonMock->json_true();
    }
    return NULL;
}

extern "C" json_t *json_false(void)
{
    if (g_janssonMock)
    {
        return g_janssonMock->json_false();
    }
    return NULL;
}

extern "C" json_t *json_string(const char *value)
{
    if (g_janssonMock)
    {
        return g_janssonMock->json_string(value);
    }
    return NULL;
}

extern "C" json_t *json_integer(json_int_t value)
{
    if (g_janssonMock)
    {
        return g_janssonMock->json_integer(value);
    }
    return NULL;
}

extern "C" int json_object_set_new(json_t *object, const char *key, json_t *value)
{
    if (g_janssonMock)
    {
        return g_janssonMock->json_object_set_new(object, key, value);
    }
    return -1;
}

extern "C" const char *json_string_value(const json_t *string)
{
    if (g_janssonMock)
    {
        return g_janssonMock->json_string_value(string);
    }
    return NULL;
}

extern "C" int json_dump_file(const json_t *json, const char *path, size_t flags)
{
    if (g_janssonMock)
    {
        return g_janssonMock->json_dump_file(json, path, flags);
    }
    return -1;
}

extern "C" json_t *json_load_file(const char *path, size_t flags, json_error_t *error)
{
    if (g_janssonMock)
    {
        return g_janssonMock->json_load_file(path, flags, error);
    }
    return NULL;
}

extern "C" int json_array_append_new(json_t *array, json_t *value)
{
    if (g_janssonMock)
    {
        return g_janssonMock->json_array_append_new(array, value);
    }
    return -1;
}

extern "C" json_t *json_array_get(const json_t *array, size_t index)
{
    if (g_janssonMock)
    {
        return g_janssonMock->json_array_get(array, index);
    }
    return NULL;
}

extern "C" json_int_t json_integer_value(const json_t *integer)
{
    if (g_janssonMock)
    {
        return g_janssonMock->json_integer_value(integer);
    }
    return -1;
}

extern "C" char *json_dumps(const json_t *json, size_t flags)
{
    if (g_janssonMock)
    {
        return g_janssonMock->json_dumps(json, flags);
    }
    return NULL;
}