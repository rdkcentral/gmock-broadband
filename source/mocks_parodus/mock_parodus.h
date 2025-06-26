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
#ifndef MOCK_PARODUS_H
#define MOCK_PARODUS_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {
#include <libparodus/libparodus.h>
}

class parodusInterface
{
    public:
        virtual ~parodusInterface() {}
        virtual int libparodus_init(libpd_instance_t *, libpd_cfg_t *) = 0;
        virtual int libparodus_shutdown(libpd_instance_t *) = 0;
        virtual const char *libparodus_strerror(libpd_error_t) = 0;
        virtual int libparodus_send(libpd_instance_t, wrp_msg_t *) = 0;
};

class parodusMock: public parodusInterface
{
    public:
        virtual ~parodusMock() {}
        MOCK_METHOD2(libparodus_init, int(libpd_instance_t *, libpd_cfg_t *));
        MOCK_METHOD1(libparodus_shutdown, int(libpd_instance_t *));
        MOCK_METHOD1(libparodus_strerror, const char *(libpd_error_t));
        MOCK_METHOD2(libparodus_send, int(libpd_instance_t, wrp_msg_t *));
};

#endif //MOCK_PARODUS_H