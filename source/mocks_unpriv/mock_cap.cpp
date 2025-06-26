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

#include "mock_cap.h"

extern CapMock * g_capMock;

extern "C" int drop_root_caps(cap_user * _appcaps)
{
    if (!g_capMock)
    {
        return -1;
    }
    return g_capMock->drop_root_caps(_appcaps);
}

extern "C" cap_t init_capability(void)
{
    if (!g_capMock)
    {
        return NULL;
    }
    return g_capMock->init_capability();
}

extern "C" void read_capability(cap_user * _appcaps)
{
    if (g_capMock)
    {
        g_capMock->read_capability(_appcaps);
    }
}

extern "C" int update_process_caps(cap_user * _appcaps)
{
    if (!g_capMock)
    {
        return -1;
    }
    return g_capMock->update_process_caps(_appcaps);
}
