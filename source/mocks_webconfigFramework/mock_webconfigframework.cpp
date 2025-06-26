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
#include "mock_webconfigframework.h"

extern webconfigFwMock *g_webconfigFwMock;


extern "C" void PushBlobRequest (execData *exec_data )
{
    if (g_webconfigFwMock)
    {
        g_webconfigFwMock->PushBlobRequest(exec_data);
    }
}

extern "C" void register_sub_docs(blobRegInfo *bInfo,int NumOfSubdocs, getVersion getv,setVersion setv)
{
    if (g_webconfigFwMock)
    {
        g_webconfigFwMock->register_sub_docs(bInfo, NumOfSubdocs, getv, setv);
    }
}

extern "C" void check_component_crash(char* init_file)
{
    if (g_webconfigFwMock)
    {
        g_webconfigFwMock->check_component_crash(init_file);
    }
}