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

#include "mock_syscfg.h"

using namespace std;

extern SyscfgMock * g_syscfgMock;

extern "C" int syscfg_init()
{
    if (!g_syscfgMock)
    {
        return 0;
    }
    return g_syscfgMock->syscfg_init();
}

extern "C" int syscfg_commit()
{
    if (!g_syscfgMock) 
    {
        return 0;
    }
    return g_syscfgMock->syscfg_commit();
}

extern "C" int syscfg_get(const char *ns, const char *name, char *out_value, int outbufsz)
{
    if(!g_syscfgMock)
    {
        return 0;
    }
    return g_syscfgMock->syscfg_get(ns, name, out_value, outbufsz);
}

extern "C" int syscfg_set(const char *ns, const char *name, const char *value)
{
    if(!g_syscfgMock)
    {
        return 0;
    }
    return g_syscfgMock->syscfg_set(ns, name, value);
}

extern "C" int syscfg_set_nns(const char *name, const char *value)
{
    if(!g_syscfgMock)
    {
        return 0;
    }
    return g_syscfgMock->syscfg_set_nns(name, value);
}

extern "C" int syscfg_set_commit(const char *ns, const char *name, const char *value)
{
    if(!g_syscfgMock)
    {
        return 0;
    }
    return g_syscfgMock->syscfg_set_commit(ns, name, value);
}

extern "C" int syscfg_set_nns_commit(const char *name, const char *value)
{
    if(!g_syscfgMock)
    {
        return 0;
    }
    return g_syscfgMock->syscfg_set_nns_commit(name, value);
}

extern "C" int syscfg_unset(const char *ns, const char *name)
{
    if(!g_syscfgMock)
    {
        return 0;
    }
    return g_syscfgMock->syscfg_unset(ns, name);
}

extern "C" int syscfg_set_nns_u_commit(const char *name, unsigned long value)
{
    if(!g_syscfgMock)
    {
        return 0;
    }
    return g_syscfgMock->syscfg_set_nns_u_commit(name, value);
}

extern "C" int syscfg_set_nns_u (const char *name, unsigned long value)
{
    if(!g_syscfgMock)
    {
        return 0;
    }
    return g_syscfgMock->syscfg_set_nns_u(name, value);
}

extern "C" int syscfg_set_ns_u (const char *ns, const char *name, unsigned long value)
{
    if(!g_syscfgMock)
    {
        return 0;
    }
    return g_syscfgMock->syscfg_set_ns_u(ns, name, value);
}

extern "C" int syscfg_set_u_commit(const char *ns, const char *name, unsigned long value)
{
    if(!g_syscfgMock)
    {
        return 0;
    }
    return g_syscfgMock->syscfg_set_u_commit(ns, name, value);
}


extern "C" int syscfg_commit_lock()
{
    if(!g_syscfgMock)
    {
        return 0;
    }
    return g_syscfgMock->syscfg_commit_lock();
}

extern "C" int syscfg_commit_unlock()
{
    if(!g_syscfgMock)
    {
        return 0;
    }
    return g_syscfgMock->syscfg_commit_unlock();
}

extern "C" int syscfg_set_ns_commit(const char *ns, const char *name, const char *value)
{
    if (!g_syscfgMock)
    {
        return -1;
    }
    return g_syscfgMock->syscfg_set_ns_commit(ns, name, value);
}

