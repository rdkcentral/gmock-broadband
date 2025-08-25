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
#include "mock_pcap.h"

using namespace std;

extern PcapMock * g_pcapMock;

extern "C" pcap_t* pcap_create
(
    const char *source,
    char *errbuf
)
{
    if (!g_pcapMock)
    {
        return nullptr;
    }
    return g_pcapMock->pcap_create(source, errbuf);
}

extern "C" int pcap_set_buffer_size
(
    pcap_t *p,
    int buffer_size
)
{
    if (!g_pcapMock)
    {
        return 0;
    }
    return g_pcapMock->pcap_set_buffer_size(p, buffer_size);
}

extern "C" int pcap_set_immediate_mode
(
    pcap_t *p,
    int mode
)
{
    if (!g_pcapMock)
    {
        return 0;
    }
    return g_pcapMock->pcap_set_immediate_mode(p, mode);
}

extern "C" int pcap_set_snaplen
(
    pcap_t *p,
    int snaplen
)
{
    if (!g_pcapMock)
    {
        return 0;
    }
    return g_pcapMock->pcap_set_snaplen(p, snaplen);
}

extern "C" int pcap_setnonblock
(
    pcap_t *p,
    int nonblock,
    char *errbuf
)
{
    if (!g_pcapMock)
    {
        return 0;
    }
    return g_pcapMock->pcap_setnonblock(p, nonblock, errbuf);
}

extern "C" int pcap_set_timeout
(
    pcap_t *p,
    int to_ms
)
{
    if (!g_pcapMock)
    {
        return 0;
    }
    return g_pcapMock->pcap_set_timeout(p, to_ms);
}

extern "C" int pcap_activate
(
    pcap_t *p
)
{
    if (!g_pcapMock)
    {
        return 0;
    }
    return g_pcapMock->pcap_activate(p);
}

extern "C" char* pcap_geterr
(
    pcap_t *p
)
{
    if (!g_pcapMock)
    {
        return nullptr;
    }
    return g_pcapMock->pcap_geterr(p);
}

extern "C" int pcap_compile
(
    pcap_t *p,
    struct bpf_program *fp,
    const char *str,
    int optimize,
    bpf_u_int32 netmask
)
{
    if (!g_pcapMock)
    {
        return 0;
    }
    return g_pcapMock->pcap_compile(p, fp, str, optimize, netmask);
}

extern "C" int pcap_setfilter
(
    pcap_t *p,
    struct bpf_program *fp
)
{
    if (!g_pcapMock)
    {
        return 0;
    }
    return g_pcapMock->pcap_setfilter(p, fp);
}

extern "C" int pcap_get_selectable_fd
(
    pcap_t *p
)
{
    if (!g_pcapMock)
    {
        return 0;
    }
    return g_pcapMock->pcap_get_selectable_fd(p);
}

extern "C" void pcap_breakloop(pcap_t* p) {
    if (g_pcapMock) {
        g_pcapMock->pcap_breakloop(p);
    }
}

extern "C" int pcap_dispatch(pcap_t* p, int cnt, pcap_handler callback, u_char* user) {
    if (g_pcapMock) {
        return g_pcapMock->pcap_dispatch(p, cnt, callback, user);
    }
    return 0;  // Default return value
}

extern "C" void pcap_freecode(struct bpf_program *program)
{
    if (!g_pcapMock)
    {
        return;
    }
    g_pcapMock->pcap_freecode(program);
}

extern "C" void pcap_close(pcap_t *p)
{
    if (p != nullptr) {
        free(p);
    }
}