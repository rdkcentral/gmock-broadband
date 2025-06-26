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
#include "mock_parodus.h"

extern parodusMock *g_parodusMock;

extern "C" int libparodus_init(libpd_instance_t *instance, libpd_cfg_t *libpd_cfg)
{
    if (!g_parodusMock)
    {
        return 0;
    }
    return g_parodusMock->libparodus_init(instance, libpd_cfg);
}

extern "C" int libparodus_shutdown(libpd_instance_t *instance)
{
    if (!g_parodusMock)
    {
        return 0;
    }
    return g_parodusMock->libparodus_shutdown(instance);
}

extern "C" const char *libparodus_strerror(libpd_error_t error)
{
    if (!g_parodusMock)
    {
        return NULL;
    }
    return g_parodusMock->libparodus_strerror(error);
}

extern "C" int libparodus_send(libpd_instance_t instance, wrp_msg_t *msg)
{
    if (!g_parodusMock)
    {
        return 0;
    }
    return g_parodusMock->libparodus_send(instance, msg);
}