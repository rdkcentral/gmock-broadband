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
#ifndef MOCK_NETSNMP_H
#define MOCK_NETSNMP_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/library/container.h>
#include <net-snmp/agent/snmp_agent.h>
#include <net-snmp/agent/agent_handler.h>
#include <net-snmp/agent/cache_handler.h>
#include <net-snmp/agent/table.h>
#include <net-snmp/agent/table_tdata.h>
#include <net-snmp/types.h>
}

class netsnmpInterface
{
    public:
        virtual ~netsnmpInterface() {}
        virtual void *netsnmp_tdata_extract_entry(netsnmp_request_info *) = 0;
        virtual int netsnmp_request_set_error(netsnmp_request_info *, int) = 0;
        virtual int netsnmp_set_request_error(netsnmp_agent_request_info *, netsnmp_request_info *, int) = 0;
        virtual int snmp_set_var_typed_value(netsnmp_variable_list *, u_char, const void *, size_t) = 0;
        virtual int netsnmp_check_vb_type(netsnmp_variable_list *, u_char) = 0;
        virtual netsnmp_variable_list *snmp_varlist_add_variable(netsnmp_variable_list **, const oid *, size_t, u_char, const void *, size_t) = 0;
        virtual int netsnmp_check_vb_type_and_max_size(netsnmp_variable_list *, u_char, size_t) = 0;
        virtual int netsnmp_check_vb_int_range(netsnmp_variable_list *, int, int) = 0;
        virtual netsnmp_tdata_row *netsnmp_tdata_create_row(void) = 0;
        virtual int netsnmp_tdata_add_row(netsnmp_tdata *, netsnmp_tdata_row *) = 0;
        virtual void netsnmp_remove_tdata_row(netsnmp_request_info *, netsnmp_tdata_row *) = 0;
        virtual netsnmp_tdata_row *netsnmp_tdata_extract_row(netsnmp_request_info *) = 0;
        virtual void *netsnmp_tdata_delete_row(netsnmp_tdata_row *) = 0;
        virtual void *netsnmp_tdata_remove_and_delete_row(netsnmp_tdata *, netsnmp_tdata_row *) = 0;
        virtual int netsnmp_check_vb_size(netsnmp_variable_list *, size_t) = 0;
        virtual int netsnmp_check_vb_max_size(netsnmp_variable_list *, size_t) = 0;
        virtual int netsnmp_check_vb_range(netsnmp_variable_list *, int, int) = 0;
        virtual netsnmp_mib_handler *netsnmp_cache_handler_get(netsnmp_cache *) = 0;
        virtual netsnmp_cache *netsnmp_cache_create(int, NetsnmpCacheLoad, NetsnmpCacheFree, const oid *, int) = 0;
        virtual void netsnmp_cache_handler_owns_cache(netsnmp_mib_handler *) = 0;
        virtual netsnmp_handler_registration *netsnmp_create_handler_registration(const char *, Netsnmp_Node_Handler *, const oid *, size_t , int ) = 0;
        virtual int netsnmp_register_scalar(netsnmp_handler_registration *) = 0;
        virtual int netsnmp_inject_handler(netsnmp_handler_registration *,  netsnmp_mib_handler *) = 0;
        virtual netsnmp_table_request_info *netsnmp_extract_table_info(netsnmp_request_info *) = 0;
        virtual netsnmp_tdata *netsnmp_tdata_extract_table(netsnmp_request_info *) = 0;
        virtual void netsnmp_insert_tdata_row(netsnmp_request_info *, netsnmp_tdata_row *) = 0;
        virtual int netsnmp_check_vb_rowstatus(netsnmp_variable_list *, int) = 0;
        virtual int netsnmp_check_vb_size_range(netsnmp_variable_list *, size_t, size_t) = 0;
        virtual netsnmp_tdata_row *netsnmp_tdata_row_first(netsnmp_tdata *) = 0;
        virtual netsnmp_tdata *netsnmp_tdata_create_table(const char *, long) = 0;
        virtual int netsnmp_tdata_register(netsnmp_handler_registration *, netsnmp_tdata *, netsnmp_table_registration_info *) = 0;
};

class netsnmpMock: public netsnmpInterface
{
    public:
        virtual ~netsnmpMock() {}
        MOCK_METHOD1(netsnmp_tdata_extract_entry, void *(netsnmp_request_info *));
        MOCK_METHOD2(netsnmp_request_set_error, int(netsnmp_request_info *, int));
        MOCK_METHOD3(netsnmp_set_request_error, int(netsnmp_agent_request_info *, netsnmp_request_info *, int));
        MOCK_METHOD4(snmp_set_var_typed_value, int(netsnmp_variable_list *, u_char, const void *, size_t));
        MOCK_METHOD2(netsnmp_check_vb_type, int(netsnmp_variable_list *, u_char));
        MOCK_METHOD6(snmp_varlist_add_variable, netsnmp_variable_list *(netsnmp_variable_list **, const oid *, size_t, u_char, const void *, size_t));
        MOCK_METHOD3(netsnmp_check_vb_type_and_max_size, int(netsnmp_variable_list *, u_char, size_t));
        MOCK_METHOD3(netsnmp_check_vb_int_range, int(netsnmp_variable_list *, int, int));
        MOCK_METHOD0(netsnmp_tdata_create_row, netsnmp_tdata_row *());
        MOCK_METHOD2(netsnmp_tdata_add_row, int(netsnmp_tdata *, netsnmp_tdata_row *));
        MOCK_METHOD2(netsnmp_remove_tdata_row, void(netsnmp_request_info *, netsnmp_tdata_row *));
        MOCK_METHOD1(netsnmp_tdata_extract_row, netsnmp_tdata_row *(netsnmp_request_info *));
        MOCK_METHOD1(netsnmp_tdata_delete_row, void *(netsnmp_tdata_row *));
        MOCK_METHOD2(netsnmp_tdata_remove_and_delete_row, void *(netsnmp_tdata *, netsnmp_tdata_row *));
        MOCK_METHOD2(netsnmp_check_vb_size, int(netsnmp_variable_list *, size_t));
        MOCK_METHOD2(netsnmp_check_vb_max_size, int(netsnmp_variable_list *, size_t));
        MOCK_METHOD3(netsnmp_check_vb_range, int(netsnmp_variable_list *, int, int));
        MOCK_METHOD1(netsnmp_cache_handler_get, netsnmp_mib_handler *(netsnmp_cache *));
        MOCK_METHOD5(netsnmp_cache_create, netsnmp_cache *(int, NetsnmpCacheLoad, NetsnmpCacheFree, const oid *, int));
        MOCK_METHOD1(netsnmp_cache_handler_owns_cache, void(netsnmp_mib_handler *));
        MOCK_METHOD5(netsnmp_create_handler_registration, netsnmp_handler_registration *(const char *, Netsnmp_Node_Handler *, const oid *, size_t , int ));
        MOCK_METHOD1(netsnmp_register_scalar, int(netsnmp_handler_registration *));
        MOCK_METHOD2(netsnmp_inject_handler, int(netsnmp_handler_registration *,  netsnmp_mib_handler *));
        MOCK_METHOD1(netsnmp_extract_table_info, netsnmp_table_request_info *(netsnmp_request_info *));
        MOCK_METHOD1(netsnmp_tdata_extract_table, netsnmp_tdata *(netsnmp_request_info *));
        MOCK_METHOD2(netsnmp_insert_tdata_row, void(netsnmp_request_info *, netsnmp_tdata_row *));
        MOCK_METHOD2(netsnmp_check_vb_rowstatus, int(netsnmp_variable_list *, int));
        MOCK_METHOD3(netsnmp_check_vb_size_range, int(netsnmp_variable_list *, size_t, size_t));
        MOCK_METHOD1(netsnmp_tdata_row_first, netsnmp_tdata_row *(netsnmp_tdata *));
        MOCK_METHOD2(netsnmp_tdata_create_table, netsnmp_tdata *(const char *, long));
        MOCK_METHOD3(netsnmp_tdata_register, int(netsnmp_handler_registration *, netsnmp_tdata *, netsnmp_table_registration_info *));
};

#endif //MOCK_NETSNMP_H