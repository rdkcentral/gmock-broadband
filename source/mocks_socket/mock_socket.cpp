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

#include "mock_socket.h"

using namespace std;

extern SocketMock * g_socketMock;

extern "C" int socket(int domain, int type, int protocol)
{
    if (!g_socketMock)
    {
        return -1;
    }
    return g_socketMock->socket(domain, type, protocol);
}

extern "C" int close(int sockfd)
{
    if (!g_socketMock)
    {
        return -1;
    }
    return g_socketMock->close(sockfd);
}

extern "C" int connect(int sockfd, const struct sockaddr* addr, socklen_t len)
{
    if (!g_socketMock)
    {
        return -1;
    }
    return g_socketMock->connect(sockfd, addr, len);
}

extern "C" ssize_t recv(int sockfd, void *buf, size_t len, int flags)
{
    if (!g_socketMock)
    {
        return -1;
    }
    return g_socketMock->recv(sockfd, buf, len, flags);
}
