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
#ifndef MOCK_MQUEUE_H
#define MOCK_MQUEUE_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <mqueue.h>
#include <time.h>

class MQHandlerInterface {
public:
        virtual ~MQHandlerInterface() {}
        virtual mqd_t mq_open(const char *, int, mode_t, struct mq_attr *) = 0;
        virtual ssize_t mq_timedreceive(mqd_t, char *, size_t, unsigned int*, const struct timespec *) = 0;
        virtual ssize_t mq_receive(mqd_t, char *, size_t, unsigned int *) = 0;
        virtual int mq_close(mqd_t) = 0;
        virtual int mq_unlink(const char *) = 0;
        virtual int mq_send(mqd_t , const char * , size_t , unsigned int ) = 0;

};

class MQHandlerMock: public MQHandlerInterface {
public:
        virtual ~MQHandlerMock() {}
        MOCK_METHOD4(mq_open, mqd_t(const char *, int, mode_t, struct mq_attr *));
        MOCK_METHOD5(mq_timedreceive, ssize_t(mqd_t, char *, size_t, unsigned int*, const struct timespec *));
        MOCK_METHOD4(mq_receive, ssize_t(mqd_t, char *, size_t, unsigned int *));
        MOCK_METHOD1(mq_close, int(mqd_t));
        MOCK_METHOD1(mq_unlink, int(const char *));
        MOCK_METHOD4(mq_send, int(mqd_t , const char * , size_t , unsigned int));
};

#endif
