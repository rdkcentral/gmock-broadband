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

#include "mock_libnet.h"

using namespace std;

extern LibnetMock * g_libnetMock;

extern "C" libnet_status addr_derive_broadcast(char *ip, unsigned int prefix_len, char *bcast, int size)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->addr_derive_broadcast(ip, prefix_len, bcast, size);
}

extern "C" libnet_status addr_add(char *ip)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->addr_add(ip);
}

extern "C" libnet_status interface_up(char *ifname)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->interface_up(ifname);
}

extern "C" libnet_status rule_add(char *rule)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->rule_add(rule);
}

extern "C" libnet_status interface_set_flags(char *ifname, unsigned int flags)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->interface_set_flags(ifname, flags);
}

extern "C" libnet_status interface_down(char *ifname)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->interface_down(ifname);
}

extern "C" libnet_status interface_set_netmask(const char*ifname, const char*netmask)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->interface_set_netmask(ifname, netmask);
}

extern "C" libnet_status interface_delete(char *ifname)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->interface_delete(ifname);
}

extern "C" libnet_status bridge_get_info(char *ifname, struct bridge_info *info)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->bridge_get_info(ifname, info);
}

extern "C" libnet_status interface_add_to_bridge(const char *ifname, const char *bridge)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->interface_add_to_bridge(ifname, bridge);
}

extern "C" libnet_status interface_remove_from_bridge(const char *ifname)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->interface_remove_from_bridge(ifname);
}

extern "C" libnet_status vlan_delete(const char *vlan)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->vlan_delete(vlan);
}

extern "C" libnet_status bridge_delete(const char *bridge)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->bridge_delete(bridge);
}

extern "C" libnet_status vlan_create(const char *vlan, int vid)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->vlan_create(vlan, vid);
}

extern "C" libnet_status bridge_create(const char *bridge)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->bridge_create(bridge);
}

extern "C" libnet_status route_add(char *route)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->route_add(route);
}

extern "C" libnet_status route_delete(char *route)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->route_delete(route);
}

extern "C" libnet_status addr_delete(char *ip)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->addr_delete(ip);
}

extern "C" libnet_status file_write(const char *file_name, const char *buf, size_t count)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->file_write(file_name, buf, count);
}

extern "C" libnet_status rule_delete(char *rule)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->rule_delete(rule);
}

extern "C" libnet_status interface_rename(char *if_name, char *new_name)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->interface_rename(if_name,new_name);
}

extern "C" void bridge_free_info(struct bridge_info *bridge)
{
    if(!g_libnetMock)
    {
        return;
    }
    g_libnetMock->bridge_free_info(bridge);
}

extern "C" libnet_status interface_status(char *ifname, int *status)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->interface_status(ifname, status);
}

extern "C" libnet_status get_ipv6_address(char *ifname, char *ipv6_addr, size_t size)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->get_ipv6_address(ifname, ipv6_addr, size);
}

extern "C" char* interface_get_ip(const char* ifname)
{
    if(!g_libnetMock)
    {
        return NULL;
    }
    return g_libnetMock->interface_get_ip(ifname);
}
    
extern "C" libnet_status interface_set_mac(const char *if_name, char *mac)
{
	if(!g_libnetMock)
	{
		return CNL_STATUS_FAILURE;
	}
	return g_libnetMock->interface_set_mac(if_name,mac);
}

extern "C" libnet_status neighbour_get_list(struct neighbour_info *arr, char *mac, char *if_name, int af_filter)
{
    if(!g_libnetMock)
    {
        return CNL_STATUS_FAILURE;
    }
    return g_libnetMock->neighbour_get_list(arr, mac, if_name, af_filter);
}

//void neighbour_free_neigh(struct neighbour_info *neigh_info);
//give mock implementation for neighbour_free_neigh
extern "C" void neighbour_free_neigh(struct neighbour_info *neigh_info)
{
    if(!g_libnetMock)
    {
        return;
    }
    g_libnetMock->neighbour_free_neigh(neigh_info);
}