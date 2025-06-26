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
#include "mock_pthread.h"

using namespace std;

extern PtdHandlerMock * g_PtdHandlerMock;

extern "C" int pthread_create(pthread_t *__restrict __newthread, const pthread_attr_t *__restrict __attr, void *(*__start_routine) (void *), void *__restrict __arg)
{
    if (!g_PtdHandlerMock)
    {
        return 0;
    }
    return g_PtdHandlerMock->pthread_create(__newthread, NULL, __start_routine, __arg);
}

extern "C" int pthread_condattr_setclock(pthread_condattr_t *attr, clockid_t clock_id)
{
        if (!g_PtdHandlerMock)
        {
            return 0;
        }
    return g_PtdHandlerMock->pthread_condattr_setclock(attr, clock_id);
}

extern "C" int pthread_cond_timedwait (pthread_cond_t *__restrict __cond,
                                   pthread_mutex_t *__restrict __mutex,
                                   const struct timespec *__restrict __abstime)
{
        if (!g_PtdHandlerMock)
        {
            return 0;
        }
    return g_PtdHandlerMock->pthread_cond_timedwait(__cond, __mutex, __abstime);
}

extern "C" int pthread_cond_signal(pthread_cond_t *cond)
{
        if (!g_PtdHandlerMock)
        {
            return 0;
        }
    return g_PtdHandlerMock->pthread_cond_signal(cond);
}

extern "C" int pthread_cond_destroy(pthread_cond_t *cond)
{
        if (!g_PtdHandlerMock)
        {
            return 0;
        }
    return g_PtdHandlerMock->pthread_cond_destroy(cond);
}

extern "C" int pthread_setspecific(pthread_key_t __key ,  const void *__value)
{
        if (!g_PtdHandlerMock)
        {
            return 0;
        }
    return g_PtdHandlerMock->pthread_setspecific(__key , __value) ;
}

extern "C" void *pthread_getspecific(pthread_key_t __key )
{
        if (!g_PtdHandlerMock)
        {
            return NULL;
        }
    return g_PtdHandlerMock->pthread_getspecific(__key);
}

extern "C" int pthread_key_create(pthread_key_t *__key, void (*__destr_routine) (void *)  )
{
        if (!g_PtdHandlerMock)
        {
            return 0;
        }
    return g_PtdHandlerMock->pthread_key_create(__key, __destr_routine);
}

extern "C" int pthread_key_delete(pthread_key_t __key)
{
        if (!g_PtdHandlerMock)
        {
            return 0;
        }
    return g_PtdHandlerMock->pthread_key_delete(__key);
}

extern "C" int pthread_detach(pthread_t __threadid)
{
        if (!g_PtdHandlerMock)
        {
            return 0;
        }
    return g_PtdHandlerMock->pthread_detach(__threadid);
}
