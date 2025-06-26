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
#ifndef MOCK_NFQUEUE_H
#define MOCK_NFQUEUE_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C"
{
#include <libnfnetlink/libnfnetlink.h>
#include <libnetfilter_queue/libnetfilter_queue.h>
}

class NfQueueInterface {
    public:
        virtual ~NfQueueInterface() {}
        virtual int nfnl_fd(struct nfnl_handle *) = 0;
        virtual struct nfq_handle *nfq_open(void) = 0;
        virtual int nfq_close(struct nfq_handle *) = 0;
        virtual struct nfnl_handle *nfq_nfnlh(struct nfq_handle *) = 0;
        virtual int nfq_set_mode(struct nfq_q_handle *, uint8_t, unsigned int) = 0;
        virtual int nfq_bind_pf(struct nfq_handle *h, uint16_t pf) = 0;
        virtual int nfq_unbind_pf(struct nfq_handle *h, uint16_t pf) = 0;
        virtual int nfq_get_payload(struct nfq_data *, unsigned char **) = 0;
        virtual struct nfqnl_msg_packet_hdr *nfq_get_msg_packet_hdr(struct nfq_data *) = 0;
        virtual int nfq_handle_packet(struct nfq_handle *, char *, int) = 0;
        virtual struct nfq_q_handle *nfq_create_queue(struct nfq_handle *, uint16_t, nfq_callback *, void *) = 0;
        virtual int nfq_destroy_queue(struct nfq_q_handle *) = 0;
        virtual int nfq_set_verdict(struct nfq_q_handle *, uint32_t , uint32_t , uint32_t , const unsigned char *) = 0;
};

class NfQueueMock: public NfQueueInterface {
    public:
        virtual ~NfQueueMock() {}
        MOCK_METHOD1(nfnl_fd, int(struct nfnl_handle*));
        MOCK_METHOD0(nfq_open, struct nfq_handle*());
        MOCK_METHOD1(nfq_close, int(struct nfq_handle*));
        MOCK_METHOD1(nfq_nfnlh, struct nfnl_handle*(struct nfq_handle*));
        MOCK_METHOD3(nfq_set_mode, int(struct nfq_q_handle*, uint8_t, unsigned int));
        MOCK_METHOD2(nfq_bind_pf, int(struct nfq_handle*, uint16_t));
        MOCK_METHOD2(nfq_unbind_pf, int(struct nfq_handle*, uint16_t));
        MOCK_METHOD2(nfq_get_payload, int(struct nfq_data*, unsigned char**));
        MOCK_METHOD1(nfq_get_msg_packet_hdr, struct nfqnl_msg_packet_hdr*(struct nfq_data*));
        MOCK_METHOD3(nfq_handle_packet, int(struct nfq_handle*, char*, int));
        MOCK_METHOD4(nfq_create_queue, struct nfq_q_handle*(struct nfq_handle*, uint16_t, nfq_callback*, void*));
        MOCK_METHOD1(nfq_destroy_queue, int(struct nfq_q_handle*));
        MOCK_METHOD5(nfq_set_verdict, int(struct nfq_q_handle*, uint32_t, uint32_t, uint32_t, const unsigned char*));

};

#endif //MOCK_NFQUEUE_H
