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

#ifndef MOCK_TRACE_H
#define MOCK_TRACE_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C"
{
#include "ccsp_trace.h"
extern int g_iTraceLevel;
extern char *pComponentName;
#define CcspTraceWarning2(pComponentName, msg)      CcspTraceExec(pComponentName, CCSP_TRACE_LEVEL_WARNING, msg)
#define CcspTraceWarning(msg)                       CcspTraceWarning2(pComponentName, msg)
}

class TraceInterface {
public:
        virtual ~TraceInterface() {}
        virtual const char *CcspTraceGetRdkLogModule(const char *) = 0;
};


class TraceMock: public TraceInterface {
public:
        virtual ~TraceMock() {}
        MOCK_METHOD1(CcspTraceGetRdkLogModule , const char *(const char *));
};

#endif
