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
#include "mock_netsnmp.h"

extern netsnmpMock *g_netsnmpMock;

extern "C" void *netsnmp_tdata_extract_entry(netsnmp_request_info * reqInfo)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_tdata_extract_entry(reqInfo);
}

extern "C" int netsnmp_request_set_error(netsnmp_request_info *reqInfo, int error)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_request_set_error(reqInfo, error);
}

extern "C" int netsnmp_set_request_error(netsnmp_agent_request_info *reqInfo, netsnmp_request_info *request, int error)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_set_request_error(reqInfo, request, error);
}

extern "C" int snmp_set_var_typed_value(netsnmp_variable_list *var, u_char type, const void *val_str, size_t val_len)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->snmp_set_var_typed_value(var, type, val_str, val_len);
}

extern "C" int netsnmp_check_vb_type(netsnmp_variable_list *var, u_char type)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_check_vb_type(var, type);
}

extern "C" netsnmp_variable_list *snmp_varlist_add_variable(netsnmp_variable_list **varlist, const oid *name, size_t name_length, u_char type, const void *value, size_t len)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->snmp_varlist_add_variable(varlist, name, name_length, type, value, len);
}

extern "C" int netsnmp_check_vb_type_and_max_size(netsnmp_variable_list *var, u_char type, size_t size)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_check_vb_type_and_max_size(var, type, size);
}

extern "C" int netsnmp_check_vb_int_range(netsnmp_variable_list *var, int low, int high)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_check_vb_int_range(var, low, high);
}

extern "C" netsnmp_tdata_row *netsnmp_tdata_create_row(void)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_tdata_create_row();
}

extern "C" int netsnmp_tdata_add_row(netsnmp_tdata *table, netsnmp_tdata_row *row)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_tdata_add_row(table, row);
}

extern "C" void netsnmp_remove_tdata_row(netsnmp_request_info *table, netsnmp_tdata_row *row)
{
    if (!g_netsnmpMock)
    {
        g_netsnmpMock->netsnmp_remove_tdata_row(table, row);
    }
}

extern "C" netsnmp_tdata_row *netsnmp_tdata_extract_row(netsnmp_request_info *reqInfo)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_tdata_extract_row(reqInfo);
}

extern "C" void *netsnmp_tdata_delete_row(netsnmp_tdata_row *row)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_tdata_delete_row(row);
}

extern "C" void *netsnmp_tdata_remove_and_delete_row(netsnmp_tdata *table, netsnmp_tdata_row *row)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_tdata_remove_and_delete_row(table, row);
}

extern "C" int netsnmp_check_vb_size(netsnmp_variable_list *var, size_t size)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_check_vb_size(var, size);
}

extern "C" int netsnmp_check_vb_max_size(netsnmp_variable_list *var, size_t size)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_check_vb_max_size(var, size);
}

extern "C" int netsnmp_check_vb_range(netsnmp_variable_list *var, int low, int high)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_check_vb_range(var, low, high);
}

extern "C" netsnmp_mib_handler *netsnmp_cache_handler_get(netsnmp_cache *cache)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_cache_handler_get(cache);
}

extern "C" netsnmp_cache *netsnmp_cache_create(int timeout, NetsnmpCacheLoad *load_hook, NetsnmpCacheFree *free_hook, const oid *rootoid, int rootoid_len)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_cache_create(timeout, load_hook, free_hook, rootoid, rootoid_len);
}

extern "C" void netsnmp_cache_handler_owns_cache(netsnmp_mib_handler *handler)
{
    if (!g_netsnmpMock)
    {
        g_netsnmpMock->netsnmp_cache_handler_owns_cache(handler);
    }
}

extern "C" netsnmp_handler_registration *netsnmp_create_handler_registration(const char *name, Netsnmp_Node_Handler *handler, const oid *reg_oid, size_t reg_oid_len, int modes)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_create_handler_registration(name, handler, reg_oid, reg_oid_len, modes);
}

extern "C" int netsnmp_register_scalar(netsnmp_handler_registration *reginfo)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_register_scalar(reginfo);
}

extern "C" int netsnmp_inject_handler(netsnmp_handler_registration *reqinfo, netsnmp_mib_handler *handler)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_inject_handler(reqinfo, handler);
}

extern "C" netsnmp_table_request_info *netsnmp_extract_table_info(netsnmp_request_info *request)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_extract_table_info(request);
}

extern "C" netsnmp_tdata *netsnmp_tdata_extract_table(netsnmp_request_info *request)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_tdata_extract_table(request);
}

extern "C" void netsnmp_insert_tdata_row(netsnmp_request_info *request, netsnmp_tdata_row *row)
{
    if (!g_netsnmpMock)
    {
        g_netsnmpMock->netsnmp_insert_tdata_row(request, row);
    }
}

extern "C" int netsnmp_check_vb_rowstatus(netsnmp_variable_list *var, int old_value)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_check_vb_rowstatus(var, old_value);
}

extern "C" int netsnmp_check_vb_size_range(netsnmp_variable_list *var, size_t low, size_t high)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_check_vb_size_range(var, low, high);
}

extern "C" netsnmp_tdata_row *netsnmp_tdata_row_first(netsnmp_tdata *table)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_tdata_row_first(table);
}

extern "C" netsnmp_tdata *netsnmp_tdata_create_table(const char *name, long flags)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_tdata_create_table(name, flags);
}

extern "C" int netsnmp_tdata_register(netsnmp_handler_registration *reginfo, netsnmp_tdata *table, netsnmp_table_registration_info *tabreq)
{
    if (!g_netsnmpMock)
    {
        return 0;
    }
    return g_netsnmpMock->netsnmp_tdata_register(reginfo, table, tabreq);
}

extern "C" void  netsnmp_table_helper_add_indexes(netsnmp_table_registration_info *tinfo, ...)
{
    (void) tinfo;
    return;
}