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
#ifndef MOCK_JANSSON_H
#define MOCK_JANSSON_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C"
{
#include <jansson.h>
}

class JanssonInterface {
    public:
        virtual ~JanssonInterface() {}
        virtual json_t *json_object_get(const json_t *object, const char *key) = 0;
        virtual void json_delete(json_t *json) = 0;
        virtual json_t *json_object(void) = 0;
        virtual json_t *json_array(void) = 0;
        virtual json_t *json_true(void) = 0;
        virtual json_t *json_false(void) = 0;
        virtual json_t *json_string(const char *value)= 0;
        virtual json_t *json_integer(json_int_t value) = 0;
        virtual int json_object_set_new(json_t *object, const char *key, json_t *value) = 0;
        virtual const char *json_string_value(const json_t *string) = 0;
        virtual int json_dump_file(const json_t *json, const char *path, size_t flags) = 0;
        virtual json_t *json_load_file(const char *path, size_t flags, json_error_t *error) = 0;
        virtual int json_array_append_new(json_t *array, json_t *value) = 0;
        virtual json_t *json_array_get(const json_t *array, size_t index) = 0;
        virtual json_int_t json_integer_value(const json_t *integer) = 0;
        virtual char *json_dumps(const json_t *json, size_t flags) = 0;
};

class JanssonMock: public JanssonInterface {
    public:
        virtual ~JanssonMock() {}
        MOCK_METHOD2(json_object_get, json_t*(const json_t*, const char*));
        MOCK_METHOD1(json_delete, void(json_t*));
        MOCK_METHOD0(json_object, json_t*());
        MOCK_METHOD0(json_array, json_t*());
        MOCK_METHOD0(json_true, json_t*());
        MOCK_METHOD0(json_false, json_t*());
        MOCK_METHOD1(json_string, json_t*(const char*));
        MOCK_METHOD1(json_integer, json_t*(json_int_t));
        MOCK_METHOD3(json_object_set_new, int(json_t*, const char*, json_t*));
        MOCK_METHOD1(json_string_value, const char*(const json_t*));
        MOCK_METHOD3(json_dump_file, int(const json_t*, const char*, size_t));
        MOCK_METHOD3(json_load_file, json_t*(const char*, size_t, json_error_t*));
        MOCK_METHOD2(json_array_append_new, int(json_t*, json_t*));
        MOCK_METHOD2(json_array_get, json_t*(const json_t*, size_t));
        MOCK_METHOD1(json_integer_value, json_int_t(const json_t*));
        MOCK_METHOD2(json_dumps, char*(const json_t*, size_t));
};

#endif //MOCK_JANSSON_H
