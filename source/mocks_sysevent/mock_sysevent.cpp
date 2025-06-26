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

#include "mock_sysevent.h"

using namespace std;

extern SyseventMock *g_syseventMock;

extern "C" int sysevent_open(char *ip, unsigned short port, int version, char *id, token_t *token)
{
    if(!g_syseventMock)
    {
        return 0;
    }
    return g_syseventMock->sysevent_open(ip, port, version, id, token);
}

extern "C" int sysevent_close(const int fd, const token_t token)
{
    if(!g_syseventMock)
    {
        return 0;
    }
    return g_syseventMock->sysevent_close(fd, token);
}

extern "C" int sysevent_get(const int fd, const token_t token, const char *inbuf, char *outbuf, int outbytes)
{
    if(!g_syseventMock)
    {
        return 0;
    }
    return g_syseventMock->sysevent_get(fd, token, inbuf, outbuf, outbytes);
}

extern "C" int sysevent_set(const int fd, const token_t token, const char *name, const char *value, int conf_req)
{
    if(!g_syseventMock)
    {
        return 0;
    }
    return g_syseventMock->sysevent_set(fd, token, name, value, conf_req);
}

extern "C" int sysevent_set_options(const int fd, const token_t token, const char *name, unsigned int flags)
{
    if(!g_syseventMock)
    {
        return 0;
    }
    return g_syseventMock->sysevent_set_options(fd, token, name, flags);
}

extern "C" int sysevent_getnotification(const int fd, const token_t token, char *namebuf, int *namebytes, char *valbuf, int *valbytes, async_id_t *async_id)
{
    if(!g_syseventMock)
    {
        return 0;
    }
    return g_syseventMock->sysevent_getnotification(fd, token, namebuf, namebytes, valbuf, valbytes, async_id);
}

extern "C" int sysevent_setnotification(const int fd, const token_t token, char *subject, async_id_t *async_id)
{
    if(!g_syseventMock)
    {
        return 0;
    }
    return g_syseventMock->sysevent_setnotification(fd, token, subject, async_id);
}

extern "C" char *SE_msg_get_string(char *msg, int *size)
{
    if(!g_syseventMock)
    {
        return NULL;
    }
    return g_syseventMock->SE_msg_get_string(msg, size);
}

extern "C" int SE_msg_receive(int fd, char *replymsg, unsigned int *replymsg_size, token_t *who)
{
    if(!g_syseventMock)
    {
        return 0;
    }
    return g_syseventMock->SE_msg_receive(fd, replymsg, replymsg_size, who);
}

extern "C" int sysevent_rmnotification(const int fd, const token_t token, async_id_t async_id)
{
    if(!g_syseventMock)
    {
        return 0;
    }
    return g_syseventMock->sysevent_rmnotification(fd, token, async_id);
}

extern "C" int sysevent_set_unique(const int fd, const token_t token, const char *name, const char *value, char *outbuf, int outbytes)
{
    if (!g_syseventMock)
    {
        return 0;
    }
    return g_syseventMock->sysevent_set_unique(fd, token, name, value, outbuf, outbytes);
}

extern "C" int SE_msg_hdr_mbytes_fixup(se_msg_hdr *hdr)
{
    if(!g_syseventMock)
    {
        return 0;
    }
    return g_syseventMock->SE_msg_hdr_mbytes_fixup(hdr);
}

 extern "C" int sysevent_open_data(char *ip, unsigned short port, int version, char *id, token_t *token)
{
    if(!g_syseventMock)
    {
        return 0;
    }
    return g_syseventMock->sysevent_open_data(ip, port, version, id, token);
}

extern "C" int sysevent_local_open_data(char *id, int version, char *name, token_t *token)
{
    if(!g_syseventMock)
    {
        return 0;
    }
    return g_syseventMock->sysevent_local_open_data(id, version, name, token);
}

extern "C" int sysevent_rmcallback(const int fd, const token_t token, async_id_t async_id)
{
    if(!g_syseventMock)
    {
        return 0;
    }
    return g_syseventMock->sysevent_rmcallback(fd, token, async_id);
}
