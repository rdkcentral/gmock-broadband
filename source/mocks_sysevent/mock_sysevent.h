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

#ifndef MOCK_SYSEVENT_H
#define MOCK_SYSEVENT_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
typedef unsigned int token_t;

extern "C"
{
#include "sysevent/sysevent.h"
#include "sysevent/libsysevent_internal.h"
}

class SyseventInterface {
public:
    virtual ~SyseventInterface() {}
    virtual int sysevent_open(char *, unsigned short, int, char *, token_t*) = 0;
    virtual int sysevent_close(const int, const token_t) = 0;
    virtual int sysevent_get(const int, const token_t, const char *, char *, int) = 0;
    virtual int sysevent_set(const int, const token_t, const char *, const char *, int) = 0;
    virtual int sysevent_set_options(const int, const token_t, const char *, unsigned int) = 0;
    virtual int sysevent_getnotification(const int fd, const token_t token, char *namebuf, int *namebytes, char *valbuf, int *valbytes, async_id_t *async_id) = 0; 
    virtual int sysevent_setnotification(const int fd, const token_t token, char *subject, async_id_t *async_id) = 0;
    virtual char *SE_msg_get_string(char *, int *) = 0;
    virtual int SE_msg_receive(int, char *, unsigned int *, token_t *) = 0;
    virtual int sysevent_rmnotification(const int, const token_t, async_id_t) = 0;
    virtual int sysevent_set_unique(const int , const token_t , const char *, const char *, char *, int) = 0;
    virtual int  SE_msg_hdr_mbytes_fixup (se_msg_hdr *) = 0;
    virtual int sysevent_open_data (char *, unsigned short, int, char *, token_t *) = 0;
    virtual int sysevent_local_open_data (char *, int, char *, token_t *) = 0;
    virtual int sysevent_rmcallback(const int, const token_t, async_id_t) = 0;
};
class SyseventMock : public SyseventInterface {
public:
    virtual ~SyseventMock() {}
    MOCK_METHOD5(sysevent_open, int(char *, unsigned short, int, char *, token_t*));
    MOCK_METHOD2(sysevent_close, int(const int, const token_t));
    MOCK_METHOD5(sysevent_get, int(const int, const token_t, const char *, char *, int));
    MOCK_METHOD5(sysevent_set, int(const int, const token_t, const char *, const char *, int));
    MOCK_METHOD4(sysevent_set_options, int(const int, const token_t, const char *, unsigned int));
    MOCK_METHOD7(sysevent_getnotification, int(const int fd, const token_t token, char *namebuf, int *namebytes, char *valbuf, int *valbytes, async_id_t *async_id));
    MOCK_METHOD4(sysevent_setnotification, int(const int, const token_t, char *, async_id_t *));
    MOCK_METHOD2(SE_msg_get_string, char *(char *, int *));
    MOCK_METHOD4(SE_msg_receive, int(int, char *, unsigned int *, token_t *));
    MOCK_METHOD3(sysevent_rmnotification, int(const int, const token_t, async_id_t));
    MOCK_METHOD6(sysevent_set_unique, int(const int, const token_t, const char *, const char *, char *, int));
    MOCK_METHOD1(SE_msg_hdr_mbytes_fixup, int(se_msg_hdr *));
    MOCK_METHOD5(sysevent_open_data, int(char *, unsigned short, int, char *, token_t *));
    MOCK_METHOD4(sysevent_local_open_data, int(char *, int, char *, token_t *));
    MOCK_METHOD3(sysevent_rmcallback, int(const int, const token_t, async_id_t));
};

#endif // MOCK_SYSEVENT_H