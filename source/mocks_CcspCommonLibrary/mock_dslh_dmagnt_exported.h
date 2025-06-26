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

#ifndef MOCK_DSLH_DMAGNT_EXPORTED_H
#define MOCK_DSLH_DMAGNT_EXPORTED_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C"{
    #include "ansc_wrapper_base.h"
    #include "ccsp_base_api.h"
    #include "ansc_status.h"
}

class DslhDmagntExportedInterface {
public:
    virtual ~DslhDmagntExportedInterface() {}
    virtual ANSC_STATUS COSAGetParamValueByPathName(void* bus_handle,parameterValStruct_t *val,ULONG *parameterValueLength) = 0;
    virtual ANSC_STATUS COSAGetParamValueString(void* hDmlAgent,char* pParamName,char* pBuffer,PULONG pulSize) = 0;
};

class DslhDmagntExportedMock : public DslhDmagntExportedInterface {
public:
    virtual ~DslhDmagntExportedMock() {}
    MOCK_METHOD3(COSAGetParamValueByPathName, ANSC_STATUS(void* bus_handle, parameterValStruct_t *val, ULONG *parameterValueLength));
    MOCK_METHOD4(COSAGetParamValueString, ANSC_STATUS(void* hDmlAgent, char* pParamName, char* pBuffer, PULONG pulSize));
};

#endif 
