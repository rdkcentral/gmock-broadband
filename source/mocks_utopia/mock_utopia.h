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
#ifndef MOCK_UTOPIA_H
#define MOCK_UTOPIA_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {
#include <utctx/utctx.h>
#include <utctx/utctx_api.h>
#include <utapi/utapi.h>
#include <utapi/DM_TR181.h>
#include <utapi/utapi_tr_dhcp.h>
#include <utapi/utapi_tr_user.h>
#include <utapi/utapi_wlan.h>
#include <util.h>
#include <sysevent.h>
}

class utopiaInterface
{
    public:
        virtual ~utopiaInterface() {}
        virtual int Utopia_Init(UtopiaContext* ) = 0;
        virtual void Utopia_Free(UtopiaContext* , int ) = 0;
        virtual int Utopia_GetNamed(UtopiaContext* , UtopiaValue , char* , char* , unsigned int ) = 0;
        virtual int Utopia_GetBridgeSettings (UtopiaContext*, bridgeInfo_t *) = 0;
        virtual int Utopia_set_lan_host_comments(UtopiaContext*, unsigned char*, unsigned char*) = 0;
        virtual int Utopia_RawSet(UtopiaContext* pUtopiaCtx, char* pszNamespace, char* pszKey, char* pszValue)=0;
        virtual int Utopia_RawGet(UtopiaContext* pUtopiaCtx, char* pszNamespace, char* pszKey, char* pszBuffer, unsigned int ccbBuf)=0;
        virtual int s_sysevent_connect(token_t *out_se_token) = 0;
        virtual int Utopia_DiagTracerouteTestStart (char *) = 0;
        virtual int file_parse(char*, param_node **) = 0;
        virtual int Utopia_GetWifiRadioCfg(UtopiaContext *,int, void *) = 0;
        virtual int Utopia_SetWifiRadioCfg(UtopiaContext *, void *) = 0;
        virtual int Utopia_GetWifiRadioDinfo(unsigned long, void *) = 0;
        virtual int Utopia_GetWifiRadioStats(unsigned long, void *) = 0;
        virtual int Utopia_GetWifiSSIDCfg(UtopiaContext *, int, void *) = 0;
        virtual int Utopia_GetWifiSSIDSInfo(unsigned long, void *) = 0;
        virtual int Utopia_GetWifiSSIDDInfo(unsigned long, void *) = 0;
        virtual int Utopia_GetWifiAPCfg(UtopiaContext *, int, void *) = 0;
        virtual int Utopia_SetWifiAPCfg(UtopiaContext *, void *) = 0;
        virtual int Utopia_GetAssocDevice(UtopiaContext *, char *, unsigned long, void *) = 0;
        virtual unsigned long Utopia_GetAssociatedDevicesCount(UtopiaContext *, char *) = 0;
        virtual int Utopia_SetWifiAPWPSCfg(UtopiaContext *,char *, void *) = 0;
        virtual int Utopia_SetWifiAPSecCfg(UtopiaContext *,char *, void *) = 0;
        virtual int Utopia_GetWifiAPInfo(UtopiaContext *, char *, void *) = 0;
        virtual int setMacList(unsigned char *, char *, unsigned long) = 0;
        virtual int Utopia_GetWifiAPMFCfg(UtopiaContext *, char *, void *) = 0;
        virtual int Utopia_SetWifiAPMFCfg(UtopiaContext *, char *, void *) = 0;
        virtual int Utopia_GetWifiSSIDStats(unsigned long, void *) = 0;
        virtual int Utopia_AddWifiSSID(UtopiaContext *, void *) = 0;
        virtual int Utopia_GetWifiSSIDInstances(UtopiaContext *) = 0;
        virtual int Utopia_DelWifiSSID(UtopiaContext *, unsigned long) = 0;
        virtual int Utopia_DeleteDHCPServerLANHost (char *) = 0;
        virtual int Utopia_GetARPCacheEntries (UtopiaContext *, int *, arpHost_t **) = 0;
        virtual int Utopia_GetWLANClients (UtopiaContext *, int *, char **) = 0;
        virtual int Utopia_GetStaticRouteTable (int *, routeStatic_t **) = 0;
        virtual int Utopia_SetWebUIAdminPasswd (UtopiaContext *, char *, char *) = 0;
        virtual int Utopia_GetIncomingTrafficLog (UtopiaContext *, int *, logentry_t **) = 0;
        virtual int Utopia_GetOutgoingTrafficLog (UtopiaContext *, int *, logentry_t **) = 0;
        virtual int Utopia_GetSecurityLog (UtopiaContext *, int *, logentry_t **) = 0;
        virtual int Utopia_GetDHCPClientLog (UtopiaContext *) = 0;
        virtual int Utopia_GetEthAssocDevices(int, int, unsigned char *,int *) = 0;
        virtual int Utopia_SetLanMngmInsNum(UtopiaContext *, unsigned long int) = 0;
        virtual int Utopia_get_lan_host_comments(UtopiaContext *, unsigned char *, unsigned char *) = 0;
        virtual int Utopia_IPRule_ephemeral_port_forwarding(portMapDyn_t *, boolean_t) = 0;
        virtual int Utopia_SetWifiMacFilters (UtopiaContext *, wifiMacFilterInfo_t *) = 0;
        virtual int Utopia_WPSPushButtonStart (void) = 0;
        virtual int Utopia_WPSPinStart (int) = 0;
        virtual int Utopia_WPSStop (void) = 0;
        virtual int Utopia_GetWPSStatus (wpsStatus_t *) = 0;
        virtual int Utopia_Get_DeviceDnsRelayForwarding(UtopiaContext *, int, void *) = 0;
        virtual int Utopia_Set_DeviceDnsRelayForwarding(UtopiaContext *, int, void *) = 0;
        virtual int Utopia_GetDhcpV4ServerPoolCfg(UtopiaContext *,void *) = 0;
        virtual int Utopia_SetDhcpV4ServerPoolCfg(UtopiaContext *, void *) = 0;
        virtual int Utopia_SetDhcpV4SPool_SAddress(UtopiaContext *, unsigned long, void *) = 0;
        virtual int Utopia_GetDhcpV4SPool_SAddress(UtopiaContext *, unsigned long,unsigned long, void *) = 0;
        virtual int Utopia_AddDhcpV4SPool_SAddress(UtopiaContext *, unsigned long, void *) = 0;
        virtual int Utopia_GetDhcpV4SPool_SAddressByIndex(UtopiaContext *, unsigned long, dhcpV4ServerPoolStaticAddress_t *) = 0;
        virtual int Utopia_SetUserByIndex(UtopiaContext *, unsigned long, userCfg_t *) = 0;
        virtual int Utopia_DelUser(UtopiaContext *, unsigned long) = 0;
        virtual int Utopia_GetMocaIntf_Static(void *) = 0;
        virtual int Utopia_SetMocaIntf_Cfg(UtopiaContext *, void *) = 0;
        virtual int Utopia_GetMocaIntf_AssociateDevice(void *, int) = 0;
        virtual int iface_get_hwaddr(const char *ifname, char *mac, size_t size) = 0;
        virtual int serv_can_start(int sefd, token_t tok, const char *servname) = 0;
        virtual int pid_of(const char *name, const char *keyword) = 0;
        virtual int serv_can_stop(int sefd, token_t tok, const char *servname) = 0;
        virtual int IsValid_ULAAddress(const char *address) = 0;
	virtual int sysctl_iface_set(const char *, const char *, const char *)=0;
        virtual int iface_get_ipv4addr(const char *ifname, char *ipv4Addr, size_t size) = 0;
        virtual int is_iface_present(const char *ifname) = 0;
        virtual void print_uptime(char *uptimeLog, char *bootfile, char *uptime) = 0;
        virtual int sysevent_setcallback(const int fd, const token_t token, action_flag_t flags, char *subject, char *function, int numparams, char **params, async_id_t *async_id) = 0;
};

class utopiaMock: public utopiaInterface
{
    public:
        virtual ~utopiaMock() {}
        MOCK_METHOD1(Utopia_Init, int(UtopiaContext* ));
        MOCK_METHOD2(Utopia_Free, void(UtopiaContext* , int ));
        MOCK_METHOD5(Utopia_GetNamed, int(UtopiaContext* , UtopiaValue , char* , char* , unsigned int ));
        MOCK_METHOD2(Utopia_GetBridgeSettings, int(UtopiaContext*, bridgeInfo_t*));
        MOCK_METHOD3(Utopia_set_lan_host_comments, int(UtopiaContext*, unsigned char*, unsigned char *));
        MOCK_METHOD4(Utopia_RawSet,int(UtopiaContext*, char*, char* , char* ));
        MOCK_METHOD5(Utopia_RawGet,int(UtopiaContext*, char*, char* , char* , unsigned int ));
        MOCK_METHOD1(s_sysevent_connect, int(token_t *));
        MOCK_METHOD1(Utopia_DiagTracerouteTestStart, int(char *));
        MOCK_METHOD2(file_parse, int(char*, param_node **));
        MOCK_METHOD3(Utopia_GetWifiRadioCfg, int(UtopiaContext *, int, void *));
        MOCK_METHOD2(Utopia_SetWifiRadioCfg, int(UtopiaContext *, void *));
        MOCK_METHOD2(Utopia_GetWifiRadioDinfo, int(unsigned long, void *));
        MOCK_METHOD2(Utopia_GetWifiRadioStats, int(unsigned long, void *));
        MOCK_METHOD3(Utopia_GetWifiSSIDCfg, int(UtopiaContext *, int, void *));
        MOCK_METHOD2(Utopia_GetWifiSSIDSInfo, int(unsigned long, void *));
        MOCK_METHOD2(Utopia_GetWifiSSIDDInfo, int(unsigned long, void *));
        MOCK_METHOD3(Utopia_GetWifiAPCfg, int(UtopiaContext *, int, void *));
        MOCK_METHOD2(Utopia_SetWifiAPCfg, int(UtopiaContext *, void *));
        MOCK_METHOD4(Utopia_GetAssocDevice, int(UtopiaContext *, char *, unsigned long, void *));
        MOCK_METHOD2(Utopia_GetAssociatedDevicesCount, unsigned long(UtopiaContext *, char *));
        MOCK_METHOD3(Utopia_SetWifiAPWPSCfg, int(UtopiaContext *, char *, void *));
        MOCK_METHOD3(Utopia_SetWifiAPSecCfg, int(UtopiaContext *, char *, void *));
        MOCK_METHOD3(Utopia_GetWifiAPInfo, int(UtopiaContext *, char *, void *));
        MOCK_METHOD3(setMacList, int(unsigned char *, char *, unsigned long));
        MOCK_METHOD3(Utopia_GetWifiAPMFCfg, int(UtopiaContext *, char *, void *));
        MOCK_METHOD3(Utopia_SetWifiAPMFCfg, int(UtopiaContext *, char *, void *));
        MOCK_METHOD2(Utopia_GetWifiSSIDStats, int(unsigned long, void *));
        MOCK_METHOD2(Utopia_AddWifiSSID, int(UtopiaContext *, void *));
        MOCK_METHOD1(Utopia_GetWifiSSIDInstances, int(UtopiaContext *));
        MOCK_METHOD2(Utopia_DelWifiSSID, int(UtopiaContext *, unsigned long));
        MOCK_METHOD1(Utopia_DeleteDHCPServerLANHost, int(char *));
        MOCK_METHOD3(Utopia_GetARPCacheEntries, int(UtopiaContext *, int *, arpHost_t **));
        MOCK_METHOD3(Utopia_GetWLANClients, int(UtopiaContext *, int *, char **));
        MOCK_METHOD2(Utopia_GetStaticRouteTable, int(int *, routeStatic_t **));
        MOCK_METHOD3(Utopia_SetWebUIAdminPasswd, int(UtopiaContext *, char *, char *));
        MOCK_METHOD3(Utopia_GetIncomingTrafficLog, int(UtopiaContext *, int *, logentry_t **));
        MOCK_METHOD3(Utopia_GetOutgoingTrafficLog, int(UtopiaContext *, int *, logentry_t **));
        MOCK_METHOD3(Utopia_GetSecurityLog, int(UtopiaContext *, int *, logentry_t **));
        MOCK_METHOD1(Utopia_GetDHCPClientLog, int(UtopiaContext *));
        MOCK_METHOD4(Utopia_GetEthAssocDevices, int(int, int, unsigned char *, int *));
        MOCK_METHOD2(Utopia_SetLanMngmInsNum, int(UtopiaContext *, unsigned long int));
        MOCK_METHOD3(Utopia_get_lan_host_comments, int(UtopiaContext *, unsigned char *, unsigned char *));
        MOCK_METHOD2(Utopia_IPRule_ephemeral_port_forwarding, int(portMapDyn_t *, boolean_t));
        MOCK_METHOD2(Utopia_SetWifiMacFilters, int(UtopiaContext *, wifiMacFilterInfo_t *));
        MOCK_METHOD0(Utopia_WPSPushButtonStart, int(void));
        MOCK_METHOD1(Utopia_WPSPinStart, int(int));
        MOCK_METHOD0(Utopia_WPSStop, int(void));
        MOCK_METHOD1(Utopia_GetWPSStatus, int(wpsStatus_t *));
        MOCK_METHOD3(Utopia_Get_DeviceDnsRelayForwarding, int(UtopiaContext *, int, void *));
        MOCK_METHOD3(Utopia_Set_DeviceDnsRelayForwarding, int(UtopiaContext *, int, void *));
        MOCK_METHOD2(Utopia_GetDhcpV4ServerPoolCfg, int(UtopiaContext *, void *));
        MOCK_METHOD2(Utopia_SetDhcpV4ServerPoolCfg, int(UtopiaContext *, void *));
        MOCK_METHOD3(Utopia_SetDhcpV4SPool_SAddress, int(UtopiaContext *, unsigned long, void *));
        MOCK_METHOD3(Utopia_GetDhcpV4SPool_SAddressByIndex, int(UtopiaContext *, unsigned long, dhcpV4ServerPoolStaticAddress_t *));
        MOCK_METHOD3(Utopia_AddDhcpV4SPool_SAddress, int(UtopiaContext *, unsigned long, void *));
        MOCK_METHOD4(Utopia_GetDhcpV4SPool_SAddress, int(UtopiaContext *, unsigned long, unsigned long, void *));
        MOCK_METHOD3(Utopia_SetUserByIndex, int(UtopiaContext *, unsigned long, userCfg_t *));
        MOCK_METHOD2(Utopia_DelUser, int(UtopiaContext *, unsigned long));
        MOCK_METHOD1(Utopia_GetMocaIntf_Static, int(void *));
        MOCK_METHOD2(Utopia_SetMocaIntf_Cfg, int(UtopiaContext *, void *));
        MOCK_METHOD2(Utopia_GetMocaIntf_AssociateDevice, int(void *, int));
        MOCK_METHOD3(iface_get_hwaddr, int(const char *, char *, size_t));
        MOCK_METHOD3(serv_can_start, int(int, token_t, const char *));
        MOCK_METHOD2(pid_of, int(const char *, const char *));
        MOCK_METHOD3(serv_can_stop, int(int, token_t, const char *));
        MOCK_METHOD1(IsValid_ULAAddress, int(const char *));
	MOCK_METHOD3(sysctl_iface_set,int(const char *, const char *, const char *));
        MOCK_METHOD3(iface_get_ipv4addr, int(const char *, char *, size_t));
        MOCK_METHOD1(is_iface_present, int(const char *));
        MOCK_METHOD3(print_uptime, void(char *, char *, char *));
        MOCK_METHOD8(sysevent_setcallback, int(const int fd, const token_t token, action_flag_t flags, char *subject, char *function, int numparams, char **params, async_id_t *async_id));
};  

#endif //MOCK_UTOPIA_H
