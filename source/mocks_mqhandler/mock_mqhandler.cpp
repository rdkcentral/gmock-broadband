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
#ifndef MOCK_FUNC_H
#define MOCK_FUNC_H

#include "mock_mqhandler.h"

using namespace std;
using ::testing::_;

extern MQHandlerMock * g_MQHandlerMock;

extern "C" mqd_t mq_open(const char *__name, int __oflag, ...)
{
    mode_t mode;
    struct mq_attr *attr;
    if (!g_MQHandlerMock)
    {
        return -1;
    }
    return g_MQHandlerMock->mq_open(__name, __oflag, mode, attr);
}

extern "C" ssize_t mq_timedreceive(mqd_t __mqdes, char *__restrict __msg_ptr,
                                size_t __msg_len,
                                unsigned int *__restrict __msg_prio,
                                const struct timespec *__restrict __abs_timeout)
{
    if (!g_MQHandlerMock)
    {
        return -1;
    }
    return g_MQHandlerMock->mq_timedreceive(__mqdes, __msg_ptr, __msg_len, __msg_prio, __abs_timeout);
}

extern "C" ssize_t mq_receive (mqd_t __mqdes, char *__msg_ptr, size_t __msg_len,
                           unsigned int *__msg_prio)
{
    if (!g_MQHandlerMock)
    {
        return -1;
    }
    return g_MQHandlerMock->mq_receive(__mqdes, __msg_ptr, __msg_len, __msg_prio);
}

extern "C" int mq_close(mqd_t __mqdes)
{
    if (!g_MQHandlerMock)
    {
        return -1;
    }
    return g_MQHandlerMock->mq_close(__mqdes);
}

extern "C" int mq_unlink(const char *__name)
{
    if (!g_MQHandlerMock)
    {
        return -1;
    }
    return g_MQHandlerMock->mq_unlink(__name);
}


extern "C" int mq_send(mqd_t __mqdes, const char *__msg_ptr, size_t __msg_len, unsigned int __msg_prio )
{
    if (!g_MQHandlerMock)
    {
        return -1;
    }
    return g_MQHandlerMock->mq_send(__mqdes, __msg_ptr, __msg_len, __msg_prio);
}

#endif
