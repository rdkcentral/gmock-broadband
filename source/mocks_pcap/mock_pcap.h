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

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <pcap.h>

class PcapInterface {
public:
    virtual ~PcapInterface() {}
    virtual pcap_t* pcap_create(const char*, char*) = 0;
    virtual int pcap_set_buffer_size(pcap_t*, int) = 0;
    virtual int pcap_set_immediate_mode(pcap_t*, int) = 0;
    virtual int pcap_set_snaplen(pcap_t*, int) = 0;
    virtual int pcap_setnonblock(pcap_t*, int, char*) = 0;
    virtual int pcap_set_timeout(pcap_t*, int) = 0;
    virtual int pcap_activate(pcap_t*) = 0;
    virtual char* pcap_geterr(pcap_t*) = 0;
    virtual int pcap_compile(pcap_t*, struct bpf_program*, const char*, int, bpf_u_int32) = 0;
    virtual int pcap_setfilter(pcap_t*, struct bpf_program*) = 0;
    virtual int pcap_get_selectable_fd(pcap_t*) = 0;
    virtual int pcap_dispatch(pcap_t *p, int cnt, pcap_handler callback, u_char *user) = 0;
    virtual void pcap_breakloop(pcap_t *p) = 0;
};

class PcapMock : public PcapInterface {
public:
    virtual ~PcapMock() {}
    MOCK_METHOD2(pcap_create, pcap_t*(const char*, char*));
    MOCK_METHOD2(pcap_set_buffer_size, int(pcap_t*, int));
    MOCK_METHOD2(pcap_set_immediate_mode, int(pcap_t*, int));
    MOCK_METHOD2(pcap_set_snaplen, int(pcap_t*, int));
    MOCK_METHOD3(pcap_setnonblock, int(pcap_t*, int, char*));
    MOCK_METHOD2(pcap_set_timeout, int(pcap_t*, int));
    MOCK_METHOD1(pcap_activate, int(pcap_t*));
    MOCK_METHOD1(pcap_geterr, char*(pcap_t*));
    MOCK_METHOD5(pcap_compile, int(pcap_t*, struct bpf_program*, const char*, int, bpf_u_int32));
    MOCK_METHOD2(pcap_setfilter, int(pcap_t*, struct bpf_program*));
    MOCK_METHOD1(pcap_get_selectable_fd, int(pcap_t*));
    MOCK_METHOD4(pcap_dispatch, int(pcap_t *p, int cnt, pcap_handler callback, u_char *user));
    MOCK_METHOD1(pcap_breakloop, void(pcap_t *p));
};

