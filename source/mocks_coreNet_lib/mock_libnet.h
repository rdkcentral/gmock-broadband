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

#ifndef MOCK_LIBNET_H
#define MOCK_LIBNET_H


#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <pthread.h>

extern "C"
{
#include "libnet.h"
}

class LibnetInterface {
public:
	virtual ~LibnetInterface() {}
	virtual libnet_status addr_derive_broadcast(char *, unsigned int, char *, int ) = 0;
	virtual libnet_status addr_add(char *) = 0;
	virtual libnet_status interface_up(char *) = 0;
	virtual libnet_status rule_add(char *) = 0;
	virtual libnet_status interface_set_flags(char *, unsigned int) = 0;
	virtual libnet_status interface_down(char *) = 0;
	virtual libnet_status interface_set_netmask(const char*, const char*) = 0;
	virtual libnet_status interface_delete(char *) = 0;
	virtual libnet_status bridge_get_info(char *, struct bridge_info *) = 0;
	virtual libnet_status interface_add_to_bridge(const char *, const char *) = 0;
	virtual libnet_status interface_remove_from_bridge(const char *) = 0;
	virtual libnet_status vlan_delete(const char *)	= 0;
	virtual libnet_status bridge_delete(const char *)	= 0;
	virtual libnet_status vlan_create(const char *, int) = 0;
	virtual libnet_status bridge_create(const char *) = 0;
	virtual libnet_status route_add(char *) = 0;
	virtual libnet_status route_delete(char *) = 0;
	virtual libnet_status addr_delete(char *) = 0;
	virtual libnet_status file_write(const char *file_name ,const char *buf, size_t count) = 0;
	virtual libnet_status rule_delete(char *) = 0;
	virtual libnet_status interface_set_mac(const char* , char*)=0;
	virtual libnet_status interface_rename(char* , char* )=0;
	virtual void bridge_free_info(struct bridge_info *) =0;
	virtual libnet_status interface_status(char *if_name, int *status) = 0;
	virtual libnet_status get_ipv6_address(char *if_name, char *ipv6_addr, size_t size) = 0;
	virtual char* interface_get_ip(const char* if_name) = 0;
	virtual libnet_status neighbour_get_list(struct neighbour_info *arr, char *mac, char *if_name, int af_filter) = 0;
	virtual void neighbour_free_neigh(struct neighbour_info *neigh_info) = 0;

};

class LibnetMock: public LibnetInterface {
public:
	virtual ~LibnetMock() {}
	MOCK_METHOD4(addr_derive_broadcast, libnet_status(char *, unsigned int, char *, int ));
	MOCK_METHOD1(addr_add, libnet_status(char *));
	MOCK_METHOD1(interface_up, libnet_status(char *));
	MOCK_METHOD1(rule_add, libnet_status(char *));
	MOCK_METHOD2(interface_set_flags, libnet_status(char *, unsigned int));
	MOCK_METHOD1(interface_down, libnet_status(char *));
	MOCK_METHOD2(interface_set_netmask, libnet_status(const char*, const char*));
	MOCK_METHOD1(interface_delete, libnet_status(char *));
	MOCK_METHOD2(bridge_get_info, libnet_status(char *, struct bridge_info *));
	MOCK_METHOD2(interface_add_to_bridge, libnet_status(const char *, const char *));
	MOCK_METHOD1(interface_remove_from_bridge, libnet_status(const char *));
	MOCK_METHOD1(vlan_delete, libnet_status(const char *));
	MOCK_METHOD1(bridge_delete, libnet_status(const char *));
	MOCK_METHOD2(vlan_create, libnet_status(const char *, int));
	MOCK_METHOD1(bridge_create, libnet_status(const char *));
	MOCK_METHOD1(route_add, libnet_status(char *));
	MOCK_METHOD1(route_delete, libnet_status(char *));
	MOCK_METHOD1(addr_delete, libnet_status(char *));
	MOCK_METHOD3(file_write, libnet_status(const char *, const char *, size_t));
	MOCK_METHOD1(rule_delete, libnet_status(char *));
    MOCK_METHOD2(interface_rename,libnet_status(char*, char*));       
	MOCK_METHOD1(bridge_free_info, void(struct bridge_info *));
	MOCK_METHOD2(interface_status, libnet_status(char *, int *));
	MOCK_METHOD3(get_ipv6_address, libnet_status(char *, char *, size_t));
	MOCK_METHOD1(interface_get_ip, char*(const char*));
	MOCK_METHOD2(interface_set_mac,libnet_status(const char* , char*));
	MOCK_METHOD4(neighbour_get_list, libnet_status(struct neighbour_info *, char *, char *, int));
	MOCK_METHOD1(neighbour_free_neigh, void(struct neighbour_info *));
};

#endif
