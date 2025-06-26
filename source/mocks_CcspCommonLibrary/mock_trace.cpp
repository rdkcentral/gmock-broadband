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
#include "mock_trace.h"
using namespace std;

int g_iTraceLevel = 0; // Mock global variable
char *pComponentName = "MockComponent"; // Mock global variable

extern TraceMock * g_traceMock;

extern "C" const char *CcspTraceGetRdkLogModule(const char *pComponentName)
{
        if(!g_traceMock)
        {
                return false;
        }
        return g_traceMock->CcspTraceGetRdkLogModule(pComponentName);
}
