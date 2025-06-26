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
#ifndef MOCK_CJSON_H
#define MOCK_CJSON_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#ifdef __cplusplus
extern "C" {
#endif
#include <cjson/cJSON.h>
#ifdef __cplusplus
}
#endif

class cjsonInterface
{
    public:
        virtual ~cjsonInterface() {}
        virtual cJSON * cJSON_Parse(const char *) = 0;
        virtual cJSON * cJSON_GetObjectItem(const cJSON * const, const char * const) = 0;
        virtual cJSON * cJSON_GetArrayItem(const cJSON *, int ) = 0;
        virtual cJSON * cJSON_CreateObject() = 0;
        virtual cJSON * cJSON_CreateString(const char *) = 0;
        virtual cJSON * cJSON_CreateNumber(double) = 0;
        virtual cJSON * cJSON_CreateArray() = 0;
        virtual char * cJSON_Print(const cJSON *) = 0;
        virtual void cJSON_Delete(cJSON *) = 0;
        virtual cJSON * cJSON_Duplicate(const cJSON *, int) = 0;
        virtual cJSON_bool cJSON_AddItemToObject(cJSON *, const char *, cJSON *) = 0;
        virtual cJSON_bool cJSON_IsArray(const cJSON * const) = 0;
        virtual cJSON_bool cJSON_IsString(const cJSON * const) = 0;
        virtual int cJSON_GetArraySize(const cJSON *) = 0;
        virtual cJSON * cJSON_GetObjectItemCaseSensitive(const cJSON * const, const char * const) = 0;
        virtual cJSON_bool cJSON_IsBool(const cJSON * const) = 0;
        virtual cJSON_bool cJSON_IsTrue(const cJSON * const) = 0;
        virtual void cJSON_DeleteItemFromArray(cJSON *, int) = 0;
        virtual cJSON* cJSON_AddNumberToObject(cJSON * const, const char * const, const double) = 0;
        virtual cJSON_bool cJSON_IsNumber(const cJSON * const) = 0;
        virtual cJSON_bool cJSON_AddItemToArray(cJSON *, cJSON *) = 0;
        virtual cJSON * cJSON_CreateBool(cJSON_bool) = 0;
        virtual cJSON * cJSON_CreateNull(void) = 0;
        virtual cJSON* cJSON_AddStringToObject(cJSON * const, const char * const, const char * const) = 0;
        virtual char * cJSON_PrintUnformatted(const cJSON *) = 0;
        virtual cJSON_bool cJSON_ReplaceItemInObject(cJSON *,const char *,cJSON *) = 0;
        virtual void cJSON_DeleteItemFromObject(cJSON *, const char *) = 0;
        virtual const char * cJSON_GetErrorPtr() = 0;
        virtual cJSON_bool cJSON_HasObjectItem(const cJSON *, const char *) = 0;
        virtual cJSON_bool cJSON_AddItemReferenceToObject(cJSON *, const char *, cJSON *) = 0;
        virtual cJSON_bool cJSON_InsertItemInArray(cJSON *, int, cJSON *) = 0;
        virtual cJSON_bool cJSON_ReplaceItemInArray(cJSON *, int, cJSON *) = 0;
};

class cjsonMock: public cjsonInterface
{
    public:
        virtual ~cjsonMock() {}
        MOCK_METHOD1(cJSON_Parse, cJSON *(const char *));
        MOCK_METHOD2(cJSON_GetObjectItem, cJSON *(const cJSON * const, const char * const));
        MOCK_METHOD2(cJSON_GetArrayItem, cJSON *(const cJSON *, int));
        MOCK_METHOD0(cJSON_CreateObject, cJSON *());
        MOCK_METHOD1(cJSON_CreateString, cJSON *(const char *));
        MOCK_METHOD1(cJSON_CreateNumber, cJSON *(double));
        MOCK_METHOD0(cJSON_CreateArray, cJSON *());
        MOCK_METHOD1(cJSON_Print, char *(const cJSON * ));
        MOCK_METHOD1(cJSON_Delete, void(cJSON *));
        MOCK_METHOD2(cJSON_Duplicate, cJSON *(const cJSON *, int));
        MOCK_METHOD3(cJSON_AddItemToObject, cJSON_bool(cJSON *, const char *, cJSON *));
        MOCK_METHOD1(cJSON_IsArray, cJSON_bool(const cJSON * const));
        MOCK_METHOD1(cJSON_IsString, cJSON_bool(const cJSON * const));
        MOCK_METHOD1(cJSON_GetArraySize, int(const cJSON *));
        MOCK_METHOD2(cJSON_GetObjectItemCaseSensitive, cJSON *(const cJSON * const, const char * const));
        MOCK_METHOD1(cJSON_IsBool, cJSON_bool(const cJSON * const));
        MOCK_METHOD1(cJSON_IsTrue, cJSON_bool(const cJSON * const));
        MOCK_METHOD2(cJSON_DeleteItemFromArray, void(cJSON *, int));
        MOCK_METHOD3(cJSON_AddNumberToObject, cJSON* (cJSON * const, const char * const, const double));
        MOCK_METHOD1(cJSON_IsNumber, cJSON_bool(const cJSON * const));
        MOCK_METHOD2(cJSON_AddItemToArray, cJSON_bool(cJSON *, cJSON *));
        MOCK_METHOD1(cJSON_CreateBool, cJSON *(cJSON_bool));
        MOCK_METHOD0(cJSON_CreateNull, cJSON *());
        MOCK_METHOD3(cJSON_AddStringToObject, cJSON* (cJSON * const, const char * const, const char * const));
        MOCK_METHOD1(cJSON_PrintUnformatted, char *(const cJSON *));
        MOCK_METHOD3(cJSON_ReplaceItemInObject, cJSON_bool(cJSON *,const char *,cJSON *));
        MOCK_METHOD2(cJSON_DeleteItemFromObject, void(cJSON *, const char *));
        MOCK_METHOD0(cJSON_GetErrorPtr, const char *());
        MOCK_METHOD2(cJSON_HasObjectItem, cJSON_bool(const cJSON *, const char *));
        MOCK_METHOD3(cJSON_AddItemReferenceToObject, cJSON_bool(cJSON *, const char *, cJSON *));
        MOCK_METHOD3(cJSON_InsertItemInArray, cJSON_bool(cJSON *, int, cJSON *));
        MOCK_METHOD3(cJSON_ReplaceItemInArray, cJSON_bool(cJSON *, int, cJSON *));
};

#endif //MOCK_CJSON_H