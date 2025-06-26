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
#ifndef MOCK_PTHREAD_H
#define MOCK_PTHREAD_H


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <pthread.h>

class PtdHandlerInterface {
public:
        virtual ~PtdHandlerInterface() {}
        virtual int pthread_create(pthread_t*, const pthread_attr_t*, void* (*)(void*), void*) = 0;
        virtual int pthread_condattr_setclock(pthread_condattr_t *, clockid_t) = 0;
        virtual int pthread_cond_timedwait(pthread_cond_t *, pthread_mutex_t *, const struct timespec *) = 0;
        virtual int pthread_cond_signal(pthread_cond_t *) = 0;
        virtual int pthread_cond_destroy(pthread_cond_t *) = 0;
        virtual int pthread_setspecific(pthread_key_t , const void *) = 0;
        virtual void *pthread_getspecific(pthread_key_t) = 0;
        virtual int pthread_key_create(pthread_key_t *, void (*) (void *)) = 0;
        virtual int pthread_key_delete(pthread_key_t ) = 0 ;
        virtual int pthread_detach(pthread_t ) = 0 ;
};

class PtdHandlerMock: public PtdHandlerInterface {
public:
        virtual ~PtdHandlerMock() {}
        MOCK_METHOD4(pthread_create, int(pthread_t*, const pthread_attr_t*, void* (*)(void*), void*));
        MOCK_METHOD2(pthread_condattr_setclock, int(pthread_condattr_t *, clockid_t));
        MOCK_METHOD3(pthread_cond_timedwait, int(pthread_cond_t *, pthread_mutex_t *, const struct timespec *));
        MOCK_METHOD1(pthread_cond_signal, int(pthread_cond_t *));
        MOCK_METHOD1(pthread_cond_destroy, int(pthread_cond_t *));
        MOCK_METHOD2(pthread_setspecific, int(pthread_key_t , const void *));
        MOCK_METHOD1(pthread_getspecific, void *(pthread_key_t));
        MOCK_METHOD2(pthread_key_create, int(pthread_key_t *, void (*)(void*)));
        MOCK_METHOD1(pthread_key_delete, int(pthread_key_t));
        MOCK_METHOD1(pthread_detach, int(pthread_t));
};

#endif

