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
#include "mock_cJSON.h"

extern cjsonMock *g_cjsonMock;

extern "C" cJSON *cJSON_Parse(const char *value)
{
    if (!g_cjsonMock)
    {
        return NULL;
    }
    return g_cjsonMock->cJSON_Parse(value);
}

extern "C" char *cJSON_Print(const cJSON *item)
{
    if (!g_cjsonMock)
    {
        return NULL;
    }
    return g_cjsonMock->cJSON_Print(item);
}

extern "C" void cJSON_Delete(cJSON *c)
{
    if (!g_cjsonMock)
    {
        return;
    }
    g_cjsonMock->cJSON_Delete(c);
}

extern "C" cJSON *cJSON_GetObjectItem(const cJSON * const object, const char * const string)
{
    if (!g_cjsonMock)
    {
        return NULL;
    }
    return g_cjsonMock->cJSON_GetObjectItem(object, string);
}

extern "C" cJSON *cJSON_GetArrayItem(const cJSON *array, int index)
{
    if (!g_cjsonMock)
    {
        return NULL;
    }
    return g_cjsonMock->cJSON_GetArrayItem(array, index);
}

extern "C" cJSON *cJSON_CreateObject()
{
    if (!g_cjsonMock)
    {
        return NULL;
    }
    return g_cjsonMock->cJSON_CreateObject();
}

extern "C" cJSON *cJSON_CreateString(const char *string)
{
    if (!g_cjsonMock)
    {
        return NULL;
    }
    return g_cjsonMock->cJSON_CreateString(string);
}

extern "C" cJSON *cJSON_CreateNumber(double num)
{
    if (!g_cjsonMock)
    {
        return NULL;
    }
    return g_cjsonMock->cJSON_CreateNumber(num);
}

extern "C" cJSON *cJSON_CreateArray()
{
    if (!g_cjsonMock)
    {
        return NULL;
    }
    return g_cjsonMock->cJSON_CreateArray();
}

extern "C" cJSON *cJSON_Duplicate(const cJSON *item, int recurse)
{
    if (!g_cjsonMock)
    {
        return NULL;
    }
    return g_cjsonMock->cJSON_Duplicate(item, recurse);
}

extern "C" cJSON_bool cJSON_AddItemToObject(cJSON *object, const char *string, cJSON *item)
{
    if (!g_cjsonMock)
    {
        return false;
    }
    return g_cjsonMock->cJSON_AddItemToObject(object, string, item);
}

extern "C" cJSON_bool cJSON_IsArray(const cJSON * const item)
{
    if (!g_cjsonMock)
    {
        return false;
    }
    return g_cjsonMock->cJSON_IsArray(item);
}

extern "C" cJSON_bool cJSON_IsString(const cJSON * const item)
{
    if (!g_cjsonMock)
    {
        return false;
    }
    return g_cjsonMock->cJSON_IsString(item);
}

extern "C" int cJSON_GetArraySize(const cJSON *array)
{
    if (!g_cjsonMock)
    {
        return 0;
    }
    return g_cjsonMock->cJSON_GetArraySize(array);
}

extern "C" cJSON *cJSON_GetObjectItemCaseSensitive(const cJSON * const object, const char * const string)
{
    if (!g_cjsonMock)
    {
        return NULL;
    }
    return g_cjsonMock->cJSON_GetObjectItemCaseSensitive(object, string);
}

extern "C" cJSON_bool cJSON_IsBool(const cJSON * const item)
{
    if (!g_cjsonMock)
    {
        return false;
    }
    return g_cjsonMock->cJSON_IsBool(item);
}

extern "C" cJSON_bool cJSON_IsTrue(const cJSON * const item)
{
    if (!g_cjsonMock)
    {
        return false;
    }
    return g_cjsonMock->cJSON_IsTrue(item);
}

extern "C" void cJSON_DeleteItemFromArray(cJSON *array, int which)
{
    if (!g_cjsonMock)
    {
        return;
    }
    g_cjsonMock->cJSON_DeleteItemFromArray(array, which);
}

extern "C" cJSON* cJSON_AddNumberToObject(cJSON * const object, const char * const name, const double number)
{
    if (!g_cjsonMock)
    {
        return NULL;
    }
    return g_cjsonMock->cJSON_AddNumberToObject(object, name, number);
}

extern "C" cJSON_bool cJSON_IsNumber(const cJSON * const item)
{
    if (!g_cjsonMock)
    {
        return false;
    }
    return g_cjsonMock->cJSON_IsNumber(item);
}

extern "C" cJSON_bool cJSON_AddItemToArray(cJSON *array, cJSON *item)
{
    if (!g_cjsonMock)
    {
        return false;
    }
    return g_cjsonMock->cJSON_AddItemToArray(array, item);
}

extern "C" cJSON *cJSON_CreateBool(cJSON_bool b)
{
    if (!g_cjsonMock)
    {
        return NULL;
    }
    return g_cjsonMock->cJSON_CreateBool(b);
}

extern "C" cJSON *cJSON_CreateNull(void)
{
    if (!g_cjsonMock)
    {
        return NULL;
    }
    return g_cjsonMock->cJSON_CreateNull();
}

extern "C" cJSON* cJSON_AddStringToObject(cJSON * const object, const char * const name, const char * const string)
{
    if (!g_cjsonMock)
    {
        return NULL;
    }
    return g_cjsonMock->cJSON_AddStringToObject(object, name, string);
}

extern "C" char *cJSON_PrintUnformatted(const cJSON *item)
{
    if (!g_cjsonMock)
    {
        return NULL;
    }
    return g_cjsonMock->cJSON_PrintUnformatted(item);
}

extern "C" cJSON_bool cJSON_ReplaceItemInObject(cJSON *object,const char *string,cJSON *newitem)
{
    if (!g_cjsonMock)
    {
        return false;
    }
    return g_cjsonMock->cJSON_ReplaceItemInObject(object, string, newitem);
}

extern "C" void cJSON_DeleteItemFromObject(cJSON *object, const char *string)
{
    if (!g_cjsonMock)
    {
        return;
    }
    g_cjsonMock->cJSON_DeleteItemFromObject(object, string);
}

extern "C" const char *cJSON_GetErrorPtr(void)
{
    if (!g_cjsonMock)
    {
        return nullptr;
    }
    return g_cjsonMock->cJSON_GetErrorPtr();
}

extern "C" cJSON_bool cJSON_HasObjectItem(const cJSON *object, const char *string)
{
    if (!g_cjsonMock)
    {
        return false;
    }
    return g_cjsonMock->cJSON_HasObjectItem(object, string);
}

extern "C" cJSON_bool cJSON_AddItemReferenceToObject(cJSON *object, const char *string, cJSON *item)
{
    if (!g_cjsonMock)
    {
        return false;
    }
    return g_cjsonMock->cJSON_AddItemReferenceToObject(object, string, item);
}

extern "C" cJSON_bool cJSON_InsertItemInArray(cJSON *array, int which, cJSON *newitem)
{
    if (!g_cjsonMock)
    {
        return false;
    }
    return g_cjsonMock->cJSON_InsertItemInArray(array, which, newitem);
}

extern "C" cJSON_bool cJSON_ReplaceItemInArray(cJSON *array, int which, cJSON *newitem)
{
    if (!g_cjsonMock)
    {
        return false;
    }
    return g_cjsonMock->cJSON_ReplaceItemInArray(array, which, newitem);
}