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
#ifndef MOCK_RBUS_H
#define MOCK_RBUS_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <rbus.h>

class rbusInterface
{
    public:
        virtual ~rbusInterface() {}
        virtual rbusError_t rbus_open(rbusHandle_t*, char const*) = 0;
        virtual rbusError_t rbus_close(rbusHandle_t) = 0;
        virtual rbusError_t rbus_get( rbusHandle_t , char const* , rbusValue_t* ) = 0;
        virtual char* rbusValue_ToString(rbusValue_t , char* , size_t ) = 0;
        virtual rbusObject_t rbusObject_Init(rbusObject_t*, char const*) = 0;
        virtual rbusValue_t rbusValue_Init(rbusValue_t*) = 0;
        virtual void rbusValue_SetString(rbusValue_t, char const*) = 0;
        virtual char const* rbusValue_GetString(rbusValue_t, int*) = 0;
        virtual void rbusObject_SetValue(rbusObject_t, char const*, rbusValue_t) = 0;
        virtual rbusValue_t rbusObject_GetValue(rbusObject_t, char const*) = 0;
        virtual int32_t rbusValue_GetInt32(rbusValue_t) = 0;
        virtual void rbusValue_SetInt32(rbusValue_t, int32_t) = 0;
        virtual void rbusValue_Release(rbusValue_t) = 0;
        virtual void rbusObject_Release(rbusObject_t) = 0;
        virtual rbusError_t rbusMethod_Invoke(rbusHandle_t, char const*, rbusObject_t, rbusObject_t*) = 0;
        virtual const char* rbusError_ToString(rbusError_t) = 0;
        virtual bool rbusCheckMethodExists(const char*) = 0;
        virtual int rbusMethodCaller(char *, rbusObject_t*, char*) = 0;
        virtual rbusError_t rbus_set(rbusHandle_t, char const*, rbusValue_t, rbusSetOptions_t*) = 0;
        virtual rbusValueType_t rbusValue_GetType(rbusValue_t) = 0;
        virtual bool rbusValue_SetFromString(rbusValue_t, rbusValueType_t, const char*) = 0;
        virtual bool rbusValue_GetBoolean(rbusValue_t) = 0;
        virtual char const* rbusProperty_GetName(rbusProperty_t) = 0;
        virtual void rbusProperty_SetName(rbusProperty_t, char const*) = 0;
        virtual rbusError_t rbus_regDataElements(rbusHandle_t, int, rbusDataElement_t*) = 0;
        virtual rbusValue_t rbusProperty_GetValue(rbusProperty_t) = 0;
        virtual void rbusProperty_SetValue(rbusProperty_t, rbusValue_t) = 0;
        virtual rbusError_t rbusTable_unregisterRow(rbusHandle_t, char const* ) = 0;
        virtual rbusError_t rbusEvent_Subscribe(rbusHandle_t ,char const* ,rbusEventHandler_t  ,void* , int ) =0;
        virtual rbusError_t rbusEvent_SubscribeEx(rbusHandle_t , rbusEventSubscription_t* , int , int ) = 0;
        virtual rbusProperty_t rbusObject_GetProperties(rbusObject_t ) = 0;
        virtual rbusError_t rbusMethod_InvokeAsync(rbusHandle_t , char const* , rbusObject_t , rbusMethodAsyncRespHandler_t , int ) = 0;
        virtual rbusError_t rbusTable_registerRow(rbusHandle_t ,char const* , uint32_t , char const* ) = 0;
        virtual uint32_t rbusValue_GetUInt32(rbusValue_t ) = 0;
        virtual rbusError_t rbus_getUint(rbusHandle_t , char const* , unsigned int* ) = 0;
        virtual rbusError_t rbus_getStr(rbusHandle_t , char const* , char** ) = 0;
        virtual rbusError_t rbusEvent_Unsubscribe(rbusHandle_t , char const* ) = 0;
        virtual rbusError_t rbus_unregDataElements(rbusHandle_t , int , rbusDataElement_t *) = 0;
        virtual void rbusValue_SetUInt64(rbusValue_t , uint64_t ) = 0;
        virtual void rbusValue_SetBoolean(rbusValue_t , bool ) = 0;
        virtual rbusError_t rbusEvent_Publish(rbusHandle_t , rbusEvent_t* ) = 0;
        virtual void rbusObject_fwrite(rbusObject_t , int , FILE* ) = 0;
        virtual rbusError_t rbus_discoverComponentName(rbusHandle_t , int , char const** , int *, char ***) = 0;
        virtual rbusStatus_t rbus_checkStatus(void) = 0;
        virtual rbusError_t  rbusEvent_SubscribeAsync(rbusHandle_t , char const* , rbusEventHandler_t ,rbusSubscribeAsyncRespHandler_t ,void* ,int ) = 0;
        virtual rbusError_t rbusTable_addRow(rbusHandle_t , char const* ,char const* ,uint32_t* ) = 0;
        virtual void rbusValue_SetUInt32(rbusValue_t , uint32_t ) = 0;
        virtual rbusProperty_t rbusProperty_Init(rbusProperty_t*, char const*, rbusValue_t) = 0;
        virtual void rbusProperty_Append(rbusProperty_t, rbusProperty_t) = 0;
        virtual void rbusProperty_Release(rbusProperty_t) = 0;
        virtual rbusError_t rbus_setMulti(rbusHandle_t handle, int numValues, rbusProperty_t values, rbusSetOptions_t* options) = 0;
        virtual rbusError_t rbus_getExt(rbusHandle_t handle, int paramCount, const char** params, int* resCount, rbusProperty_t* props) = 0;
        virtual rbusProperty_t rbusProperty_GetNext(rbusProperty_t property) = 0;
        virtual void rbusProperty_SetNext(rbusProperty_t property, rbusProperty_t next) = 0;


};

class rbusMock: public rbusInterface
{
    public:
        virtual ~rbusMock() {}
        MOCK_METHOD1(rbusError_ToString, const char*(rbusError_t));
        MOCK_METHOD2(rbus_open, rbusError_t(rbusHandle_t*, char const*));
        MOCK_METHOD1(rbus_close, rbusError_t(rbusHandle_t));
        MOCK_METHOD3(rbus_get, rbusError_t( rbusHandle_t , char const* , rbusValue_t* ));
        MOCK_METHOD3(rbusValue_ToString, char* (rbusValue_t , char* , size_t ));
        MOCK_METHOD2(rbusObject_Init, rbusObject_t(rbusObject_t*, char const*));
        MOCK_METHOD1(rbusValue_Init, rbusValue_t(rbusValue_t*));
        MOCK_METHOD2(rbusValue_SetString, void(rbusValue_t, char const*));
        MOCK_METHOD2(rbusValue_GetString, char const*(rbusValue_t, int*));
        MOCK_METHOD3(rbusObject_SetValue, void(rbusObject_t, char const*, rbusValue_t));
        MOCK_METHOD2(rbusObject_GetValue, rbusValue_t(rbusObject_t, char const*));
        MOCK_METHOD1(rbusValue_GetInt32, int32_t(rbusValue_t));
        MOCK_METHOD2(rbusValue_SetInt32, void(rbusValue_t, int32_t));
        MOCK_METHOD1(rbusValue_Release, void(rbusValue_t));
        MOCK_METHOD1(rbusObject_Release, void(rbusObject_t));
        MOCK_METHOD4(rbusMethod_Invoke, rbusError_t(rbusHandle_t, char const*, rbusObject_t, rbusObject_t*));
        MOCK_METHOD1(rbusCheckMethodExists, bool(const char*));
        MOCK_METHOD3(rbusMethodCaller, int(char *, rbusObject_t*, char*));
        MOCK_METHOD4(rbus_set, rbusError_t(rbusHandle_t, char const*, rbusValue_t, rbusSetOptions_t*));
        MOCK_METHOD1(rbusValue_GetType, rbusValueType_t(rbusValue_t));
        MOCK_METHOD3(rbusValue_SetFromString, bool(rbusValue_t, rbusValueType_t, const char*));
        MOCK_METHOD1(rbusValue_GetBoolean, bool(rbusValue_t));
        MOCK_METHOD1(rbusProperty_GetName, char const*(rbusProperty_t));
        MOCK_METHOD2(rbusProperty_SetName, void(rbusProperty_t, char const*));
        MOCK_METHOD3(rbus_regDataElements, rbusError_t(rbusHandle_t, int, rbusDataElement_t*));
        MOCK_METHOD1(rbusProperty_GetValue, rbusValue_t(rbusProperty_t));
        MOCK_METHOD2(rbusProperty_SetValue, void(rbusProperty_t, rbusValue_t));
        MOCK_METHOD2(rbusTable_unregisterRow, rbusError_t(rbusHandle_t , char const*));
        MOCK_METHOD5(rbusEvent_Subscribe, rbusError_t(rbusHandle_t , char const*, rbusEventHandler_t, void*, int));
        MOCK_METHOD4(rbusEvent_SubscribeEx, rbusError_t(rbusHandle_t , rbusEventSubscription_t*, int, int));
        MOCK_METHOD1(rbusObject_GetProperties, rbusProperty_t(rbusObject_t));
        MOCK_METHOD5(rbusMethod_InvokeAsync, rbusError_t(rbusHandle_t,  char const*, rbusObject_t, rbusMethodAsyncRespHandler_t, int));
        MOCK_METHOD4(rbusTable_registerRow, rbusError_t(rbusHandle_t, char const*, uint32_t, char const*));
        MOCK_METHOD1(rbusValue_GetUInt32, uint32_t(rbusValue_t));
        MOCK_METHOD3(rbus_getUint, rbusError_t(rbusHandle_t, char const*, unsigned int*));
        MOCK_METHOD3(rbus_getStr, rbusError_t(rbusHandle_t, char const*, char**));
        MOCK_METHOD2(rbusEvent_Unsubscribe, rbusError_t(rbusHandle_t, char const*));
        MOCK_METHOD3(rbus_unregDataElements, rbusError_t(rbusHandle_t, int, rbusDataElement_t*));
        MOCK_METHOD2(rbusValue_SetUInt64, void(rbusValue_t, uint64_t));
        MOCK_METHOD2(rbusValue_SetBoolean, void(rbusValue_t, bool));
        MOCK_METHOD2(rbusEvent_Publish, rbusError_t(rbusHandle_t, rbusEvent_t*));
        MOCK_METHOD3(rbusObject_fwrite, void(rbusObject_t, int, FILE*));
        MOCK_METHOD5(rbus_discoverComponentName, rbusError_t(rbusHandle_t, int, char const**, int*, char***));
        MOCK_METHOD0(rbus_checkStatus, rbusStatus_t());
        MOCK_METHOD6(rbusEvent_SubscribeAsync, rbusError_t(rbusHandle_t, char const*, rbusEventHandler_t, rbusSubscribeAsyncRespHandler_t, void*, int));
        MOCK_METHOD4(rbusTable_addRow, rbusError_t(rbusHandle_t, char const*, char const*, uint32_t*));
        MOCK_METHOD2(rbusValue_SetUInt32, void(rbusValue_t, uint32_t));
        MOCK_METHOD3(rbusProperty_Init, rbusProperty_t(rbusProperty_t*, char const*, rbusValue_t));
        MOCK_METHOD2(rbusProperty_Append, void(rbusProperty_t, rbusProperty_t));
        MOCK_METHOD1(rbusProperty_Release, void(rbusProperty_t));
        MOCK_METHOD4(rbus_setMulti, rbusError_t(rbusHandle_t, int, rbusProperty_t, rbusSetOptions_t*));
        MOCK_METHOD5(rbus_getExt, rbusError_t(rbusHandle_t, int, const char**, int*, rbusProperty_t*));
        MOCK_METHOD1(rbusProperty_GetNext, rbusProperty_t(rbusProperty_t));
        MOCK_METHOD2(rbusProperty_SetNext, void(rbusProperty_t, rbusProperty_t));
};  

#endif //MOCK_RBUS_H
