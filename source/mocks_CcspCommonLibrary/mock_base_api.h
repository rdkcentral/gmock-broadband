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

#ifndef MOCK_BASE_API_H
#define MOCK_BASE_API_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C"
{       
        #include "ccsp_base_api.h"
}

class BaseAPIInterface {
public:
        virtual ~BaseAPIInterface() {}
        virtual int CcspBaseIf_getParameterValues(void*, const char*, char*, char **, int, int *, parameterValStruct_t ***) = 0;
        virtual int CcspBaseIf_setParameterValues(void* ,const char* ,char* ,int ,unsigned int, parameterValStruct_t*,int ,dbus_bool,char **) = 0;
        virtual void free_parameterValStruct_t (void *, int,parameterValStruct_t **) = 0;
        virtual int CcspBaseIf_discComponentSupportingNamespace(void*, const char*, const char*, const char*, componentStruct_t***, int*) = 0;
        virtual void free_componentStruct_t(void *, int, componentStruct_t **) = 0;
        virtual int CcspBaseIf_SendSignal_WithData(void * bus_handle, char *event, char* data) = 0;
        virtual int CcspBaseIf_getParameterNames(void*, const char*, char*, char *, dbus_bool, int *, parameterInfoStruct_t ***) = 0;
        virtual int getPartnerId (char *) = 0;
        virtual int CcspBaseIf_AddTblRow(void* , const char* , char* , int , char *, int *) = 0;
        virtual int CcspBaseIf_DeleteTblRow(void* , const char* , char* , int , char *) = 0;
        virtual int CcspBaseIf_setCommit(void* , const char* , char* , int , unsigned int, dbus_bool) = 0;
        virtual int CcspBaseIf_setParameterAttributes(void* , const char* , char* , int , parameterAttributeStruct_t *, int ) = 0;
        virtual int CcspBaseIf_getParameterAttributes(void*, const char*, char*, char **, int, int *, parameterAttributeStruct_t ***) = 0;
        virtual int PSM_Del_Record(void* , const char* , const char* ) = 0;
        virtual int CcspBaseIf_GetNextLevelInstances(void* ,const char* ,char* ,char* ,unsigned int* ,unsigned int**) = 0;
        virtual void free_parameterInfoStruct_t (void*, int, parameterInfoStruct_t **) = 0;
        virtual int CcspBaseIf_SendSignal_WithData_rbus(void*, char *, char*) = 0;

};


class BaseAPIMock: public BaseAPIInterface {
public:
        virtual ~BaseAPIMock() {}
        MOCK_METHOD7(CcspBaseIf_getParameterValues , int(void*, const char*, char*, char **, int, int *, parameterValStruct_t ***));
        MOCK_METHOD9(CcspBaseIf_setParameterValues , int(void* ,const char* ,char* ,int ,unsigned int, parameterValStruct_t*,int ,dbus_bool,char **));
        MOCK_METHOD3(free_parameterValStruct_t , void(void *, int,parameterValStruct_t **));
        MOCK_METHOD6(CcspBaseIf_discComponentSupportingNamespace, int(void*, const char*, const char*, const char*, componentStruct_t***, int*));
        MOCK_METHOD3(free_componentStruct_t, void(void *, int, componentStruct_t **));
        MOCK_METHOD3(CcspBaseIf_SendSignal_WithData, int(void*, char *, char*));
        MOCK_METHOD1(getPartnerId, int(char *));
        MOCK_METHOD7(CcspBaseIf_getParameterNames, int(void*, const char*, char*, char *, dbus_bool, int *, parameterInfoStruct_t ***));
        MOCK_METHOD6(CcspBaseIf_AddTblRow, int(void* , const char* , char* , int , char *, int *));
        MOCK_METHOD5(CcspBaseIf_DeleteTblRow, int(void* , const char* , char* , int , char *));
        MOCK_METHOD6(CcspBaseIf_setCommit, int(void* , const char* , char* , int , unsigned int, dbus_bool));
        MOCK_METHOD6(CcspBaseIf_setParameterAttributes, int(void* , const char* , char* , int , parameterAttributeStruct_t *, int));
        MOCK_METHOD7(CcspBaseIf_getParameterAttributes, int(void*, const char*, char*, char **, int, int *, parameterAttributeStruct_t ***));
        MOCK_METHOD3(PSM_Del_Record, int(void* , const char* , const char* ));
        MOCK_METHOD6(CcspBaseIf_GetNextLevelInstances, int(void* ,const char* ,char* ,char* ,unsigned int* ,unsigned int**));
        MOCK_METHOD3(free_parameterInfoStruct_t, void(void*, int, parameterInfoStruct_t **));
        MOCK_METHOD3(CcspBaseIf_SendSignal_WithData_rbus, int(void*, char *, char*));
};

#endif

