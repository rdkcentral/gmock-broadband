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
#include "mock_libev.h"

using namespace std;

extern LibevMock * g_libevMock;

extern "C" void ev_break(struct ev_loop *loop ,int how )
{
    if (g_libevMock)
    {
        return g_libevMock->ev_break(loop,how);
    }
    return;
}

extern "C" void ev_timer_stop(struct ev_loop *loop ,ev_timer* how )
{
    if (g_libevMock)
    {
        return g_libevMock->ev_timer_stop(loop,how);
    }
    return;
}

extern "C" void ev_loop_destroy(struct ev_loop *loop )
{
    if (g_libevMock)
    {
        return g_libevMock->ev_loop_destroy(loop);
    }
    return;
}

extern "C" struct ev_loop * ev_loop_new(unsigned int how )
{
    if (g_libevMock)
    {
        return g_libevMock->ev_loop_new(how);
    }
    return NULL;
}

extern "C" void ev_io_start(struct ev_loop *loop ,ev_io *how )
{
    if (g_libevMock)
    {
        return g_libevMock->ev_io_start(loop,how);
    }
    return;
}

extern "C" void ev_timer_start(struct ev_loop *loop ,ev_timer *how )
{
    if (g_libevMock)
    {
        return g_libevMock->ev_timer_start(loop,how);
    }
    return;
}

extern "C" int ev_run(struct ev_loop *loop ,int how )
{
    if (g_libevMock)
    {
        return g_libevMock->ev_run(loop,how);
    }
    return 0;
}

extern "C" void ev_io_stop(struct ev_loop *loop ,ev_io* how )
{
    if (g_libevMock)
    {
        return g_libevMock->ev_io_stop(loop,how);
    }
    return;
}

extern "C" void ev_stat_start(struct ev_loop *loop ,ev_stat * how )
{
    if (g_libevMock)
    {
        return g_libevMock->ev_stat_start(loop,how);
    }
    return;
}
