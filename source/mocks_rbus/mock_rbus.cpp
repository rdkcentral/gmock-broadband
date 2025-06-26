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
#include "mock_rbus.h"

extern rbusMock *g_rbusMock;

extern "C" rbusError_t rbus_open(rbusHandle_t* handle, char const* value)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS;
    }
    return g_rbusMock->rbus_open( handle, value);
}

extern "C" rbusError_t rbus_close(rbusHandle_t handle)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS;
    }
    return g_rbusMock->rbus_close(handle);
}

extern "C" rbusError_t rbus_get( rbusHandle_t handle, char const* name, rbusValue_t* value)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS;
    }
    return g_rbusMock->rbus_get( handle, name, value);
}

extern "C" char* rbusValue_ToString(rbusValue_t value, char* buf, size_t buflen)
{
    if (!g_rbusMock)
    {
        return (char *)NULL;
    }
    return g_rbusMock->rbusValue_ToString( value, buf, buflen);
}

extern "C" rbusObject_t rbusObject_Init(rbusObject_t* object, char const* value)
{
    if (!g_rbusMock)
    {
        return NULL;
    }
    return g_rbusMock->rbusObject_Init(object, value);
}

extern "C" rbusValue_t rbusValue_Init(rbusValue_t* value)
{
    if (!g_rbusMock)
    {
        return NULL;
    }
    return g_rbusMock->rbusValue_Init(value);
}

extern "C" void rbusValue_SetString(rbusValue_t value, char const* var)
{
    if (!g_rbusMock)
    {
        return;
    }
    return g_rbusMock->rbusValue_SetString(value, var);
}

extern "C" char const* rbusValue_GetString(rbusValue_t value, int* len)
{
    if (!g_rbusMock)
    {
        return NULL;
    }
    return g_rbusMock->rbusValue_GetString(value, len);
}

extern "C" void rbusObject_SetValue(rbusObject_t object, char const* var, rbusValue_t value)
{
    if (!g_rbusMock)
    {
        return;
    }
    return g_rbusMock->rbusObject_SetValue(object, var, value);
}

extern "C" rbusValue_t rbusObject_GetValue(rbusObject_t object, char const* var) 
{
    if (!g_rbusMock)
    {
        return NULL;
    }
    return g_rbusMock->rbusObject_GetValue(object, var);
}

extern "C" void rbusValue_Release(rbusValue_t value)
{
    if (!g_rbusMock)
    {
        return;
    }
    return g_rbusMock->rbusValue_Release(value);
}

extern "C" void rbusObject_Release(rbusObject_t object)
{
    if (!g_rbusMock)
    {
        return;
    }
    return g_rbusMock->rbusObject_Release(object);
}

extern "C" int32_t rbusValue_GetInt32(rbusValue_t value)
{
    if(!g_rbusMock)
    {
       return 0;
    }
    return g_rbusMock->rbusValue_GetInt32(value);
}

extern "C" void rbusValue_SetInt32(rbusValue_t value, int32_t i32)
{
    if(!g_rbusMock)
    {
       return;
    }
    return g_rbusMock->rbusValue_SetInt32(value, i32);
}

extern "C" rbusError_t rbusMethod_Invoke(rbusHandle_t handle, char const* value, rbusObject_t object, rbusObject_t* objectpt)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS;
    }
    return g_rbusMock->rbusMethod_Invoke(handle, value, object, objectpt);
}

extern "C" const char* rbusError_ToString(rbusError_t e)
{
    if (!g_rbusMock)
    {
        return "RBUS_ERROR_INVALID_OPERATION";
    }
    else{
    #define rbusError_String(E, S) case E: s = S; break;

  char const * s = NULL;
  switch (e)
  {
    rbusError_String(RBUS_ERROR_SUCCESS, "ok");
    rbusError_String(RBUS_ERROR_BUS_ERROR, "generic error");
    rbusError_String(RBUS_ERROR_INVALID_INPUT, "invalid input");
    rbusError_String(RBUS_ERROR_NOT_INITIALIZED, "not initialized");
    rbusError_String(RBUS_ERROR_OUT_OF_RESOURCES, "out of resources");
    rbusError_String(RBUS_ERROR_DESTINATION_NOT_FOUND, "destination not found");
    rbusError_String(RBUS_ERROR_DESTINATION_NOT_REACHABLE, "destination not reachable");
    rbusError_String(RBUS_ERROR_DESTINATION_RESPONSE_FAILURE, "destination response failure");
    rbusError_String(RBUS_ERROR_INVALID_RESPONSE_FROM_DESTINATION, "invalid response from destination");
    rbusError_String(RBUS_ERROR_INVALID_OPERATION, "invalid operation");
    rbusError_String(RBUS_ERROR_INVALID_EVENT, "invalid event");
    rbusError_String(RBUS_ERROR_INVALID_HANDLE, "invalid handle");
    rbusError_String(RBUS_ERROR_SESSION_ALREADY_EXIST, "session already exists");
    rbusError_String(RBUS_ERROR_COMPONENT_NAME_DUPLICATE, "duplicate component name");
    rbusError_String(RBUS_ERROR_ELEMENT_NAME_DUPLICATE, "duplicate element name");
    rbusError_String(RBUS_ERROR_ELEMENT_NAME_MISSING, "name missing");
    rbusError_String(RBUS_ERROR_COMPONENT_DOES_NOT_EXIST, "component does not exist");
    rbusError_String(RBUS_ERROR_ELEMENT_DOES_NOT_EXIST, "element name does not exist");
    rbusError_String(RBUS_ERROR_ACCESS_NOT_ALLOWED, "access denied");
    rbusError_String(RBUS_ERROR_INVALID_CONTEXT, "invalid context");
    rbusError_String(RBUS_ERROR_TIMEOUT, "timeout");
    rbusError_String(RBUS_ERROR_ASYNC_RESPONSE, "async operation in progress");
    default:
      s = "unknown error";
  }
  return s;
    }
}

extern "C" bool rbusCheckMethodExists(const char* rbusMethodName)
{
    if (!g_rbusMock)
    {
        return false;
    }
    return g_rbusMock->rbusCheckMethodExists(rbusMethodName);
}

extern "C" int rbusMethodCaller(char *methodName, rbusObject_t* inputParams, char* payload)
{
    if (!g_rbusMock)
    {
        return -1;
    }
    return g_rbusMock->rbusMethodCaller(methodName, inputParams, payload);
}

extern "C" rbusError_t rbus_set(rbusHandle_t handle, char const* name, rbusValue_t value, rbusSetOptions_t* opts)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS;
    }
    return g_rbusMock->rbus_set(handle, name, value, opts);
}

extern "C" rbusValueType_t rbusValue_GetType(rbusValue_t value)
{
    if (!g_rbusMock)
    {
        return RBUS_NONE;
    }
    return g_rbusMock->rbusValue_GetType(value);
}

extern "C" bool rbusValue_SetFromString(rbusValue_t value, rbusValueType_t type, const char* str)
{
    if (!g_rbusMock)
    {
        return false;
    }
    return g_rbusMock->rbusValue_SetFromString(value, type, str);
}

extern "C" bool rbusValue_GetBoolean(rbusValue_t value)
{
    if (!g_rbusMock)
    {
        return false;
    }
    return g_rbusMock->rbusValue_GetBoolean(value);
}

extern "C" char const* rbusProperty_GetName(rbusProperty_t property)
{
    if (!g_rbusMock)
    {
        return NULL;
    }
    return g_rbusMock->rbusProperty_GetName(property);
}

extern "C" void rbusProperty_SetName(rbusProperty_t property, char const* name)
{
    if(!g_rbusMock)
    {
       return;
    }
    return g_rbusMock->rbusProperty_SetName(property, name);
}

extern "C" rbusProperty_t rbusProperty_Init(rbusProperty_t* pproperty, char const* name, rbusValue_t value)
{
    if (!g_rbusMock)
    {
        return NULL;
    }
    return g_rbusMock->rbusProperty_Init(pproperty, name, value);
}

extern "C" void rbusProperty_Append(rbusProperty_t property, rbusProperty_t back)
{
    if (!g_rbusMock)
    {
        return;
    }
    g_rbusMock->rbusProperty_Append(property, back);
}

extern "C" void rbusProperty_Release(rbusProperty_t property)
{
    if (!g_rbusMock)
    {
        return;
    }
    g_rbusMock->rbusProperty_Release(property);
}

extern "C" rbusError_t rbus_setMulti(rbusHandle_t handle, int numValues, rbusProperty_t values, rbusSetOptions_t* options)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS;
    }
    return g_rbusMock->rbus_setMulti(handle, numValues, values, options);
}
extern "C" rbusError_t rbus_getExt(rbusHandle_t handle, int numParams, const char** params, int* resCount, rbusProperty_t* props)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS; 
    }
    return g_rbusMock->rbus_getExt(handle, numParams, params, resCount, props);
}

extern "C" rbusProperty_t rbusProperty_GetNext(rbusProperty_t property)
{
    if (!g_rbusMock)
    {
        return NULL; 
    }
    return g_rbusMock->rbusProperty_GetNext(property);
}


extern "C" void rbusProperty_SetNext(rbusProperty_t property, rbusProperty_t next)
{
    if (!g_rbusMock)
    {
        return; 
    }
    g_rbusMock->rbusProperty_SetNext(property, next);
}
extern "C" rbusError_t rbus_regDataElements(rbusHandle_t handle, int numDataElements, rbusDataElement_t *elements)
{
    if(!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS;
    }
    return g_rbusMock->rbus_regDataElements(handle, numDataElements, elements);
}

extern "C" rbusValue_t rbusProperty_GetValue(rbusProperty_t property)
{
    if(!g_rbusMock)
    {
        return NULL;
    }
    return g_rbusMock->rbusProperty_GetValue(property);
}

extern "C" void rbusProperty_SetValue(rbusProperty_t property, rbusValue_t value)
{
    if(!g_rbusMock)
    {
       return;
    }
    return g_rbusMock->rbusProperty_SetValue(property, value);
}

extern "C" rbusError_t rbusTable_unregisterRow(rbusHandle_t handle, char const* rowName)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS;
    }
    return g_rbusMock->rbusTable_unregisterRow(handle, rowName);
}

extern "C" rbusError_t rbusEvent_Subscribe(
    rbusHandle_t        handle,
    char const*         eventName,
    rbusEventHandler_t  handler,
    void*               userData,
    int                 timeout)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS;
    }
    return g_rbusMock->rbusEvent_Subscribe(handle, eventName, handler, userData, timeout);
}

extern "C" rbusError_t rbusEvent_SubscribeEx(
    rbusHandle_t              handle,
    rbusEventSubscription_t*  subscription,
    int                       numSubscriptions,
    int                       timeout)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS;
    }
    return g_rbusMock->rbusEvent_SubscribeEx(handle, subscription, numSubscriptions, timeout);
}

extern "C" rbusProperty_t rbusObject_GetProperties(rbusObject_t object)
{
    if (!g_rbusMock)
    {
        return NULL;
    }

    return g_rbusMock->rbusObject_GetProperties(object);
}

extern "C" rbusError_t rbusMethod_InvokeAsync(
    rbusHandle_t handle,
    char const* methodName,
    rbusObject_t inParams,
    rbusMethodAsyncRespHandler_t callback,
    int timeout)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS;
    }
    return g_rbusMock->rbusMethod_InvokeAsync(handle, methodName, inParams, callback, timeout);
}

extern "C" rbusError_t rbusTable_registerRow(
    rbusHandle_t handle,
    char const* tableName,
    uint32_t instNum,
    char const* aliasName)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS;
    }
    return g_rbusMock->rbusTable_registerRow(handle, tableName, instNum, aliasName);
}

extern "C" uint32_t rbusValue_GetUInt32(rbusValue_t value)
{
    if (!g_rbusMock)
    {
        return 0; // Return a default value, since it's a uint32_t function.
    }
    return g_rbusMock->rbusValue_GetUInt32(value);
}

extern "C" rbusError_t rbus_getUint(rbusHandle_t handle, char const* paramName, unsigned int* paramVal)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS; // Return a default success value.
    }
    return g_rbusMock->rbus_getUint(handle, paramName, paramVal);
}

extern "C" rbusError_t rbusEvent_Unsubscribe(rbusHandle_t handle, char const* eventName)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS; // Return a default success value.
    }
    return g_rbusMock->rbusEvent_Unsubscribe(handle, eventName);
}

extern "C" rbusError_t rbus_unregDataElements(rbusHandle_t handle, int numDataElements, rbusDataElement_t *elements)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS; // Return a default success value.
    }
    return g_rbusMock->rbus_unregDataElements(handle, numDataElements, elements);
}

extern "C" void rbusValue_SetUInt64(rbusValue_t value, uint64_t u64)
{
    if (!g_rbusMock)
    {
        return;
    }
    g_rbusMock->rbusValue_SetUInt64(value, u64);
}

extern "C" void rbusValue_SetBoolean(rbusValue_t value, bool b)
{
    if (!g_rbusMock)
    {
        return;
    }
    g_rbusMock->rbusValue_SetBoolean(value, b);
}

extern "C" rbusError_t rbusEvent_Publish(rbusHandle_t handle, rbusEvent_t* eventData)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS; // Return a default success value.
    }
    return g_rbusMock->rbusEvent_Publish(handle, eventData);
}


extern "C" void rbusObject_fwrite(rbusObject_t obj, int depth, FILE* fout)
{
    if (!g_rbusMock)
    {
        return;
    }
    g_rbusMock->rbusObject_fwrite(obj, depth, fout);
}

extern "C" rbusError_t rbus_discoverComponentName(rbusHandle_t handle, int numElements, char const** elementNames, int *numComponents, char ***componentName)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS; // Return a default success value.
    }
    return g_rbusMock->rbus_discoverComponentName(handle, numElements, elementNames, numComponents, componentName);
}

extern "C" rbusStatus_t rbus_checkStatus(void)
{
    if (!g_rbusMock)
    {
        return RBUS_DISABLED; 
    }
    return g_rbusMock->rbus_checkStatus();
}

extern "C" rbusError_t rbusEvent_SubscribeAsync(rbusHandle_t handle, char const* eventName, rbusEventHandler_t handler, rbusSubscribeAsyncRespHandler_t subscribeHandler, void* userData, int timeout)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_BUS_ERROR;
    }
    return g_rbusMock->rbusEvent_SubscribeAsync(handle, eventName, handler, subscribeHandler, userData, timeout);
}

extern "C" rbusError_t rbusTable_addRow(rbusHandle_t handle, char const* tableName, char const* aliasName, uint32_t* instNum)
{
    if (!g_rbusMock)
    {
        return RBUS_ERROR_SUCCESS;
    }
    return g_rbusMock->rbusTable_addRow(handle, tableName, aliasName, instNum);
}

extern "C" void rbusValue_SetUInt32(rbusValue_t value, uint32_t u32)
{
    if (!g_rbusMock)
    {
        return;
    }
    g_rbusMock->rbusValue_SetUInt32(value, u32);
}
