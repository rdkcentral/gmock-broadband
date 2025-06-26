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
#include "mock_nfqueue.h"

extern NfQueueMock *g_nfQueueMock;

extern "C" int nfnl_fd(struct nfnl_handle *handle)
{
    if (g_nfQueueMock)
    {
        return g_nfQueueMock->nfnl_fd(handle);
    }
    return -1;
}

extern "C" struct nfq_handle *nfq_open(void)
{
    if (g_nfQueueMock)
    {
        return g_nfQueueMock->nfq_open();
    }
    return NULL;
}

extern "C" int nfq_close(struct nfq_handle *handle)
{
    if (g_nfQueueMock)
    {
        return g_nfQueueMock->nfq_close(handle);
    }
    return -1;
}

extern "C" struct nfnl_handle *nfq_nfnlh(struct nfq_handle *handle)
{
    if (g_nfQueueMock)
    {
        return g_nfQueueMock->nfq_nfnlh(handle);
    }
    return NULL;
}

extern "C" int nfq_set_mode(struct nfq_q_handle *qh, uint8_t mode, unsigned int len)
{
    if (g_nfQueueMock)
    {
        return g_nfQueueMock->nfq_set_mode(qh, mode, len);
    }
    return -1;
}

extern "C" int nfq_bind_pf(struct nfq_handle *h, uint16_t pf)
{
    if (g_nfQueueMock)
    {
        return g_nfQueueMock->nfq_bind_pf(h, pf);
    }
    return -1;
}

extern "C" int nfq_unbind_pf(struct nfq_handle *h, uint16_t pf)
{
    if (g_nfQueueMock)
    {
        return g_nfQueueMock->nfq_unbind_pf(h, pf);
    }
    return -1;
}

extern "C" int nfq_get_payload(struct nfq_data *data, unsigned char **buf)
{
    if (g_nfQueueMock)
    {
        return g_nfQueueMock->nfq_get_payload(data, buf);
    }
    return -1;
}

extern "C" struct nfqnl_msg_packet_hdr *nfq_get_msg_packet_hdr(struct nfq_data *data)
{
    if (g_nfQueueMock)
    {
        return g_nfQueueMock->nfq_get_msg_packet_hdr(data);
    }
    return NULL;
}

extern "C" int nfq_handle_packet(struct nfq_handle *h, char *buf, int len)
{
    if (g_nfQueueMock)
    {
        return g_nfQueueMock->nfq_handle_packet(h, buf, len);
    }
    return -1;
}

extern "C" struct nfq_q_handle *nfq_create_queue(struct nfq_handle *h, uint16_t num, nfq_callback *cb, void *data)
{
    if (g_nfQueueMock)
    {
        return g_nfQueueMock->nfq_create_queue(h, num, cb, data);
    }
    return NULL;
}

extern "C" int nfq_destroy_queue(struct nfq_q_handle *qh)
{
    if (g_nfQueueMock)
    {
        return g_nfQueueMock->nfq_destroy_queue(qh);
    }
    return -1;
}

extern "C" int nfq_set_verdict(struct nfq_q_handle *qh, uint32_t id, uint32_t verdict, uint32_t data_len, const unsigned char *buf)
{
    if (g_nfQueueMock)
    {
        return g_nfQueueMock->nfq_set_verdict(qh, id, verdict, data_len, buf);
    }
    return -1;
}