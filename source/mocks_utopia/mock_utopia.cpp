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
#include "mock_utopia.h"

extern utopiaMock *g_utopiaMock;

extern "C" int Utopia_Init(UtopiaContext* pUtopiaCtx)
{
    if (!g_utopiaMock)
    {
        return 0;
    }
    return g_utopiaMock->Utopia_Init(pUtopiaCtx);
}

extern "C" void Utopia_Free(UtopiaContext* pUtopiaCtx, int fCommit)
{
    if (!g_utopiaMock)
    {
        return;
    }
    g_utopiaMock->Utopia_Free(pUtopiaCtx, fCommit);
}

extern "C" int Utopia_GetNamed(UtopiaContext* pUtopiaCtx, UtopiaValue ixUtopia, char* pszName, char* pszBuffer, unsigned int ccbBuf)
{
    if (!g_utopiaMock)
    {
        return 0;
    }
    return g_utopiaMock->Utopia_GetNamed(pUtopiaCtx, ixUtopia, pszName, pszBuffer, ccbBuf);
}   

extern "C" int Utopia_GetBridgeSettings (UtopiaContext *ctx, bridgeInfo_t *bridge_info)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetBridgeSettings(ctx, bridge_info);
}

extern "C" int Utopia_set_lan_host_comments(UtopiaContext *ctx, unsigned char *pMac, unsigned char *pComments)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_set_lan_host_comments(ctx, pMac, pComments);
}

extern "C" int Utopia_RawSet(UtopiaContext* pUtopiaCtx, char* pszNamespace, char* pszKey, char* pszValue)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_RawSet(pUtopiaCtx, pszNamespace, pszKey,pszValue);
}

extern "C" int Utopia_RawGet(UtopiaContext* pUtopiaCtx, char* pszNamespace, char* pszKey, char* pszBuffer, unsigned int ccbBuf)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_RawGet(pUtopiaCtx, pszNamespace, pszKey,pszBuffer,ccbBuf);
}

//utapi's mock
extern "C" int s_sysevent_connect(token_t *out_se_token)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->s_sysevent_connect(out_se_token);
}

extern "C" int Utopia_DiagTracerouteTestStart (char *dest)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_DiagTracerouteTestStart(dest);
}

extern "C" int file_parse(char *file_name, param_node **head)
{
    if (!g_utopiaMock)
    {
        return -1;  // Return -1 if the mock is not set
    }
    return g_utopiaMock->file_parse(file_name, head);  // Call the mock method
}

extern "C" int Utopia_GetWifiRadioCfg(UtopiaContext *ctx, int radioIndex, void *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetWifiRadioCfg(ctx, radioIndex, cfg);
}

extern "C" int Utopia_SetWifiRadioCfg(UtopiaContext *ctx, void *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_SetWifiRadioCfg(ctx, cfg);
}

extern "C" int Utopia_GetWifiRadioDinfo(unsigned long radioIndex, void *dinfo)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetWifiRadioDinfo(radioIndex, dinfo);
}

extern "C" int Utopia_GetWifiRadioStats(unsigned long radioIndex, void *stats)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetWifiRadioStats(radioIndex, stats);
}

extern "C" int Utopia_GetWifiSSIDCfg(UtopiaContext *ctx, int ssidIndex, void *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetWifiSSIDCfg(ctx, ssidIndex, cfg);
}

extern "C" int Utopia_GetWifiSSIDSInfo(unsigned long ssidIndex, void *sinfo)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetWifiSSIDSInfo(ssidIndex, sinfo);
}

extern "C" int Utopia_GetWifiSSIDDInfo(unsigned long ssidIndex, void *dinfo)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetWifiSSIDDInfo(ssidIndex, dinfo);
}

extern "C" int Utopia_GetWifiAPCfg(UtopiaContext *ctx, int apIndex, void *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetWifiAPCfg(ctx, apIndex, cfg);
}

extern "C" int Utopia_SetWifiAPCfg(UtopiaContext *ctx, void *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_SetWifiAPCfg(ctx, cfg);
}

extern "C" int Utopia_GetAssocDevice(UtopiaContext *ctx, char *mac, unsigned long radioIndex, void *assoc)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetAssocDevice(ctx, mac, radioIndex, assoc);
}

extern "C" unsigned long Utopia_GetAssociatedDevicesCount(UtopiaContext *ctx, char *mac)
{
    if (!g_utopiaMock)
    {
        return -1;  // Returning -1 for consistency; consider if 0 or another value is more appropriate for this function
    }
    return g_utopiaMock->Utopia_GetAssociatedDevicesCount(ctx, mac);
}

extern "C" int Utopia_SetWifiAPWPSCfg(UtopiaContext *ctx, char *ssid, void *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_SetWifiAPWPSCfg(ctx, ssid, cfg);
}

extern "C" int Utopia_SetWifiAPSecCfg(UtopiaContext *ctx, char *ssid, void *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_SetWifiAPSecCfg(ctx, ssid, cfg);
}

extern "C" int Utopia_GetWifiAPInfo(UtopiaContext *ctx, char *ssid, void *info)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetWifiAPInfo(ctx, ssid, info);
}

extern "C" int setMacList(unsigned char *mac, char *comments, unsigned long count)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->setMacList(mac, comments, count);
}

extern "C" int Utopia_GetWifiAPMFCfg(UtopiaContext *ctx, char *ssid, void *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetWifiAPMFCfg(ctx, ssid, cfg);
}

extern "C" int Utopia_SetWifiAPMFCfg(UtopiaContext *ctx, char *ssid, void *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_SetWifiAPMFCfg(ctx, ssid, cfg);
}

extern "C" int Utopia_GetWifiSSIDStats(unsigned long ssidIndex, void *sinfo)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetWifiSSIDStats(ssidIndex, sinfo);
}

extern "C" int Utopia_AddWifiSSID(UtopiaContext *ctx, void *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_AddWifiSSID(ctx, cfg);
}

extern "C" int Utopia_GetWifiSSIDInstances(UtopiaContext *ctx)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetWifiSSIDInstances(ctx);
}

extern "C" int Utopia_DelWifiSSID(UtopiaContext *ctx, unsigned long ssidIndex)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_DelWifiSSID(ctx, ssidIndex);
}

extern "C" int Utopia_DeleteDHCPServerLANHost(char *mac)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_DeleteDHCPServerLANHost(mac);
}

extern "C" int Utopia_GetARPCacheEntries(UtopiaContext *ctx, int *count, arpHost_t **arpHost)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetARPCacheEntries(ctx, count, arpHost);
}

extern "C" int Utopia_GetWLANClients(UtopiaContext *ctx, int *count, char **mac)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetWLANClients(ctx, count, mac);
}

extern "C" int Utopia_GetStaticRouteTable(int *count, routeStatic_t **route)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetStaticRouteTable(count, route);
}

extern "C" int Utopia_SetWebUIAdminPasswd(UtopiaContext *ctx, char *username, char *password)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_SetWebUIAdminPasswd(ctx, username, password);
}

extern "C" int Utopia_GetIncomingTrafficLog(UtopiaContext *ctx, int *count, logentry_t **log)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetIncomingTrafficLog(ctx, count, log);
}

extern "C" int Utopia_GetOutgoingTrafficLog(UtopiaContext *ctx, int *count, logentry_t **log)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetOutgoingTrafficLog(ctx, count, log);
}

extern "C" int Utopia_GetSecurityLog(UtopiaContext *ctx, int *count, logentry_t **log)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetSecurityLog(ctx, count, log);
}

extern "C" int Utopia_GetDHCPClientLog(UtopiaContext *ctx)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetDHCPClientLog(ctx);
}

extern "C" int Utopia_GetEthAssocDevices(int radioIndex, int ssidIndex, unsigned char *mac, int *count)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetEthAssocDevices(radioIndex, ssidIndex, mac, count);
}

extern "C" int Utopia_SetLanMngmInsNum(UtopiaContext *ctx, unsigned long int insNum)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_SetLanMngmInsNum(ctx, insNum);
}

extern "C" int Utopia_get_lan_host_comments(UtopiaContext *ctx, unsigned char *mac, unsigned char *comments)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_get_lan_host_comments(ctx, mac, comments);
}

extern "C" int Utopia_IPRule_ephemeral_port_forwarding(portMapDyn_t *portMapDyn, boolean_t enable)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_IPRule_ephemeral_port_forwarding(portMapDyn, enable);
}

extern "C" int Utopia_SetWifiMacFilters(UtopiaContext *ctx, wifiMacFilterInfo_t *macFilter)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_SetWifiMacFilters(ctx, macFilter);
}

extern "C" int Utopia_WPSPushButtonStart(void)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_WPSPushButtonStart();
}

extern "C" int Utopia_WPSPinStart(int pin)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_WPSPinStart(pin);
}

extern "C" int Utopia_WPSStop(void)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_WPSStop();
}

extern "C" int Utopia_GetWPSStatus(wpsStatus_t *status)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetWPSStatus(status);
}

extern "C" int Utopia_Get_DeviceDnsRelayForwarding(UtopiaContext *ctx, int instance, void *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_Get_DeviceDnsRelayForwarding(ctx, instance, cfg);
}

extern "C" int Utopia_Set_DeviceDnsRelayForwarding(UtopiaContext *ctx, int instance, void *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_Set_DeviceDnsRelayForwarding(ctx, instance, cfg);
}

extern "C" int Utopia_GetDhcpV4ServerPoolCfg(UtopiaContext *ctx, void *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetDhcpV4ServerPoolCfg(ctx, cfg);
}

extern "C" int Utopia_SetDhcpV4ServerPoolCfg(UtopiaContext *ctx, void *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_SetDhcpV4ServerPoolCfg(ctx, cfg);
}

extern "C" int Utopia_SetDhcpV4SPool_SAddress(UtopiaContext *ctx, unsigned long poolIndex, void *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_SetDhcpV4SPool_SAddress(ctx, poolIndex, cfg);
}

extern "C" int Utopia_GetDhcpV4SPool_SAddressByIndex(UtopiaContext *ctx, unsigned long index, dhcpV4ServerPoolStaticAddress_t *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetDhcpV4SPool_SAddressByIndex(ctx, index, cfg);
}

extern "C" int Utopia_AddDhcpV4SPool_SAddress(UtopiaContext *ctx, unsigned long poolIndex, void *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_AddDhcpV4SPool_SAddress(ctx, poolIndex, cfg);
}

extern "C" int Utopia_GetDhcpV4SPool_SAddress(UtopiaContext *ctx, unsigned long ulPoolInstanceNumber, unsigned long ulIndex, void *pSAddr)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetDhcpV4SPool_SAddress(ctx, ulPoolInstanceNumber, ulIndex, pSAddr);
}

extern "C" int Utopia_SetUserByIndex(UtopiaContext *ctx, unsigned long index, userCfg_t *cfg)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_SetUserByIndex(ctx, index, cfg);
}

extern "C" int Utopia_DelUser(UtopiaContext *ctx, unsigned long index)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_DelUser(ctx, index);
}

extern "C" int Utopia_GetMocaIntf_Static(void *str_handle)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetMocaIntf_Static(str_handle);
}

extern "C" int Utopia_SetMocaIntf_Cfg(UtopiaContext *pCtx, void *str_handle)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_SetMocaIntf_Cfg(pCtx, str_handle);
}

extern "C" int Utopia_GetMocaIntf_AssociateDevice(void *str_handle, int count)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->Utopia_GetMocaIntf_AssociateDevice(str_handle, count);
}

// util's mock
extern "C" int iface_get_hwaddr(const char *ifname, char *mac, size_t size)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->iface_get_hwaddr(ifname, mac, size);
}

extern "C" int serv_can_start(int sefd, token_t tok, const char *servname) {
    if (!g_utopiaMock) {
        return -1;
    }
    return g_utopiaMock->serv_can_start(sefd, tok, servname);
}

extern "C" int pid_of(const char *name, const char *keyword) {
    if (!g_utopiaMock) {
        return -1;
    }
    return g_utopiaMock->pid_of(name, keyword);
}

extern "C" int serv_can_stop(int sefd, token_t tok, const char *servname) {
    if (!g_utopiaMock) {
        return -1;
    }
    return g_utopiaMock->serv_can_stop(sefd, tok, servname);
}

extern "C" int IsValid_ULAAddress(const char *address) {
    if (!g_utopiaMock) {
        return -1;
    }
    return g_utopiaMock->IsValid_ULAAddress(address);
}

extern "C" int sysctl_iface_set(const char *path, const char *ifname, const char *content)
{
        if (!g_utopiaMock)
    {
        return 0;
    }
    return g_utopiaMock->sysctl_iface_set(path,ifname,content);
}

extern "C" int iface_get_ipv4addr (const char *ifname, char *ipv4Addr, size_t size)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->iface_get_ipv4addr(ifname, ipv4Addr, size);
}

extern "C" int is_iface_present(const char *ifname)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->is_iface_present(ifname);
}

extern "C" void print_uptime(char *uptimeLog, char *bootfile, char *uptime)
{
    if (!g_utopiaMock)
    {
        return;
    }
    g_utopiaMock->print_uptime(uptimeLog, bootfile, uptime);
}

extern "C" int sysevent_setcallback(const int fd, const token_t token, action_flag_t flags, char *subject, char *function, int numparams, char **params, async_id_t *async_id)
{
    if (!g_utopiaMock)
    {
        return -1;
    }
    return g_utopiaMock->sysevent_setcallback(fd, token, flags, subject, function, numparams, params, async_id);
}
