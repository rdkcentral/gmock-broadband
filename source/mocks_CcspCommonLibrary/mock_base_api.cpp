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
#include "mock_base_api.h"
using namespace std;

extern BaseAPIMock * g_baseapiMock;

extern "C" int CcspBaseIf_getParameterValues
(
    void*       bus_handle,
    const char* dst_component_id,
    char* dbus_path,
    char * parameterNames[],
    int size,
    int *val_size,
    parameterValStruct_t ***val
)
{
        if(!g_baseapiMock)
        {
                return false;
        }
        return g_baseapiMock->CcspBaseIf_getParameterValues(bus_handle,dst_component_id,dbus_path,parameterNames,size,val_size,val);
}

extern "C" int CcspBaseIf_getParameterNames
(
    void* bus_handle,
    const char* dst_component_id,
    char* dbus_path,
    char * parameterName,
    dbus_bool nextLevel,
    int *size ,
    parameterInfoStruct_t ***parameter
)
{
    if(!g_baseapiMock)
    {
        return false;
    }
    return g_baseapiMock->CcspBaseIf_getParameterNames(bus_handle, dst_component_id, dbus_path, parameterName, nextLevel, size, parameter);
}

extern "C" int CcspBaseIf_setParameterValues
(
    void* bus_handle,
    const char* dst_component_id,
    char* dbus_path,
    int sessionId,
    unsigned int writeID,
    parameterValStruct_t *val,
    int size,
    dbus_bool commit,
    char ** invalidParameterName
)
{
        if(!g_baseapiMock)
        {
                return false;
        }
        return g_baseapiMock->CcspBaseIf_setParameterValues(bus_handle,dst_component_id,dbus_path,sessionId,writeID,val,size,commit,invalidParameterName);
}

extern "C" void free_parameterValStruct_t (void *bus_handle, int size,parameterValStruct_t **val)
{
        if(!g_baseapiMock)
        {
                return;
        }
        return g_baseapiMock->free_parameterValStruct_t (bus_handle,size,val);
}

extern "C" int CcspBaseIf_discComponentSupportingNamespace
(
    void* bus_handle,
    const char* dst_component_id,
    const char* name_space,
    const char* subsystem_prefix,
    componentStruct_t ***components,
    int *size
)
{
    if(!g_baseapiMock)
    {
        return false;
    }
    return g_baseapiMock->CcspBaseIf_discComponentSupportingNamespace(bus_handle, dst_component_id, name_space, subsystem_prefix, components, size);
}

extern "C" void free_componentStruct_t(void *bus_handle, int size, componentStruct_t **val)
{
    if (!g_baseapiMock)
    {
        return;
    }
    return g_baseapiMock->free_componentStruct_t(bus_handle, size, val);
}

extern "C" int CcspBaseIf_SendSignal_WithData(void * bus_handle, char *event, char* data)
{
    if (!g_baseapiMock)
    {
        return -1;
    }
    return g_baseapiMock->CcspBaseIf_SendSignal_WithData(bus_handle, event, data);
}

extern "C" int getPartnerId (char *partnerID)
{
    if (!g_baseapiMock)
    {
        return false;
    }
    return g_baseapiMock->getPartnerId(partnerID);
}

extern "C" int CcspBaseIf_AddTblRow
(
    void* bus_handle,
    const char* dst_component_id,
    char* dbus_path,
    int sessionId,
    char *objectName,
    int *instanceNumber
)
{
    if (!g_baseapiMock)
    {
        return false;
    }
    return g_baseapiMock->CcspBaseIf_AddTblRow(bus_handle, dst_component_id, dbus_path, sessionId, objectName, instanceNumber);
}

extern "C" int CcspBaseIf_DeleteTblRow
(
    void* bus_handle,
    const char* dst_component_id,
    char* dbus_path,
    int sessionId,
    char *objectName
)
{
    if (!g_baseapiMock)
    {
        return false;
    }
    return g_baseapiMock->CcspBaseIf_DeleteTblRow(bus_handle, dst_component_id, dbus_path, sessionId, objectName);
}

extern "C" int CcspBaseIf_setCommit
(
    void* bus_handle,
    const char* dst_component_id,
    char* dbus_path,
    int sessionId,
    unsigned int writeID,
    dbus_bool commit
)
{
    if (!g_baseapiMock)
    {
        return false;
    }
    return g_baseapiMock->CcspBaseIf_setCommit(bus_handle, dst_component_id, dbus_path, sessionId, writeID, commit);
}

extern "C" int CcspBaseIf_setParameterAttributes
(
    void* bus_handle,
    const char* dst_component_id,
    char* dbus_path,
    int sessionId,
    parameterAttributeStruct_t *val,
    int size
)
{
    if (!g_baseapiMock)
    {
        return false;
    }
    return g_baseapiMock->CcspBaseIf_setParameterAttributes(bus_handle, dst_component_id, dbus_path, sessionId, val, size);
}

extern "C" int CcspBaseIf_getParameterAttributes
(
    void* bus_handle,
    const char* dst_component_id,
    char* dbus_path,
    char * parameterNames[],
    int size,
    int *val_size,
    parameterAttributeStruct_t ***parameterAttributeval
)
{
    if (!g_baseapiMock)
    {
        return false;
    }
    return g_baseapiMock->CcspBaseIf_getParameterAttributes(bus_handle, dst_component_id, dbus_path, parameterNames, size, val_size, parameterAttributeval);
}

extern "C" int PSM_Del_Record
(
    void* bus_handle,
    char const * const pSubSystemPrefix,
    char const * const pRecordName
)
{
    if (!g_baseapiMock)
    {
        return false;
    }
    return g_baseapiMock->PSM_Del_Record(bus_handle, pSubSystemPrefix, pRecordName);
}

extern "C" int
CcspBaseIf_GetNextLevelInstances
(
    void* bus_handle,
    const char* dst_component_id,
    char* dbus_path,
    char* pObjectName,
    unsigned int*  pNums,
    unsigned int** pNumArray
)
{
    if (!g_baseapiMock)
    {
        return false;
    }
    return g_baseapiMock->CcspBaseIf_GetNextLevelInstances(bus_handle, dst_component_id, dbus_path, pObjectName, pNums, pNumArray);
}

extern "C" void free_parameterInfoStruct_t (void* bus_handle, int size, parameterInfoStruct_t **val) {
    if(!g_baseapiMock)
    {
       return;
    }
    return g_baseapiMock->free_parameterInfoStruct_t(bus_handle, size, val);
}

extern "C" int CcspBaseIf_SendSignal_WithData_rbus(void* bus_handle, char *event, char* data)
{
    if (!g_baseapiMock)
    {
        return -1;
    }
    return g_baseapiMock->CcspBaseIf_SendSignal_WithData_rbus(bus_handle, event, data);
}
