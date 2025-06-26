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
#include "mock_cm_hal.h"

extern CmHalMock *g_cmHALMock;

extern "C" INT cm_hal_InitDB()
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_InitDB();
}

extern "C" INT docsis_InitDS()
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_InitDS();
}

extern "C" INT docsis_InitUS()
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_InitUS();
}

extern "C" INT docsis_getCMStatus(CHAR *cm_status)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_getCMStatus(cm_status);
}

extern "C" INT docsis_GetDSChannel(PCMMGMT_CM_DS_CHANNEL *ppinfo)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_GetDSChannel(ppinfo);
}

extern "C" INT docsis_GetUsStatus(USHORT i, PCMMGMT_CM_US_CHANNEL pinfo)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_GetUsStatus(i, pinfo);
}

extern "C" INT docsis_GetUSChannel(PCMMGMT_CM_US_CHANNEL *ppinfo)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_GetUSChannel(ppinfo);
}

extern "C" INT docsis_GetDOCSISInfo(PCMMGMT_CM_DOCSIS_INFO pinfo)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_GetDOCSISInfo(pinfo);
}

extern "C" INT docsis_GetNumOfActiveTxChannels(ULONG *cnt)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_GetNumOfActiveTxChannels(cnt);
}

extern "C" INT docsis_GetNumOfActiveRxChannels(ULONG *cnt)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_GetNumOfActiveRxChannels(cnt);
}

extern "C" INT docsis_GetErrorCodewords(PCMMGMT_CM_ERROR_CODEWORDS *ppinfo)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_GetErrorCodewords(ppinfo);
}

extern "C" INT docsis_GetMddIpModeOverride(CHAR *pValue)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_GetMddIpModeOverride(pValue);
}

extern "C" INT docsis_SetMddIpModeOverride(CHAR *pValue)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_SetMddIpModeOverride(pValue);
}

extern "C" UINT8 docsis_GetUSChannelId()
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_GetUSChannelId();
}

extern "C" void docsis_SetUSChannelId(INT index)
{
    if (!g_cmHALMock)
    {
        return;
    }
    g_cmHALMock->docsis_SetUSChannelId(index);
}

extern "C" ULONG docsis_GetDownFreq()
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_GetDownFreq();
}

extern "C" void docsis_SetStartFreq(ULONG value)
{
    if (!g_cmHALMock)
    {
        return;
    }
    g_cmHALMock->docsis_SetStartFreq(value);
}

extern "C" INT docsis_GetDocsisEventLogItems(CMMGMT_CM_EventLogEntry_t *entryArray, INT len)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_GetDocsisEventLogItems(entryArray, len);
}

extern "C" INT docsis_ClearDocsisEventLog()
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_ClearDocsisEventLog();
}

extern "C" INT cm_hal_GetDHCPInfo(PCMMGMT_CM_DHCP_INFO pInfo)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_GetDHCPInfo(pInfo);
}

extern "C" INT cm_hal_GetIPv6DHCPInfo(PCMMGMT_CM_IPV6DHCP_INFO pInfo)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_GetIPv6DHCPInfo(pInfo);
}

extern "C" INT cm_hal_GetCPEList(PCMMGMT_DML_CPE_LIST *ppCPEList, ULONG *InstanceNum, CHAR *LanMode)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_GetCPEList(ppCPEList, InstanceNum, LanMode);
}

extern "C" INT cm_hal_GetMarket(CHAR *market)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_GetMarket(market);
}

extern "C" INT cm_hal_Set_HTTP_Download_Url(char *pHttpUrl, char *pfilename)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_Set_HTTP_Download_Url(pHttpUrl, pfilename);
}

extern "C" INT cm_hal_Get_HTTP_Download_Url(char *pHttpUrl, char *pfilename)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_Get_HTTP_Download_Url(pHttpUrl, pfilename);
}

extern "C" INT cm_hal_Set_HTTP_Download_Interface(unsigned int interface)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_Set_HTTP_Download_Interface(interface);
}

extern "C" INT cm_hal_Get_HTTP_Download_Interface(unsigned int *pinterface)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_Get_HTTP_Download_Interface(pinterface);
}

extern "C" INT cm_hal_HTTP_Download()
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_HTTP_Download();
}

extern "C" INT cm_hal_Get_HTTP_Download_Status()
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_Get_HTTP_Download_Status();
}

extern "C" INT cm_hal_Reboot_Ready(ULONG *pValue)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_Reboot_Ready(pValue);
}

extern "C" INT cm_hal_HTTP_Download_Reboot_Now()
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_HTTP_Download_Reboot_Now();
}

extern "C" INT cm_hal_FWupdateAndFactoryReset(char *pUrl, char *pImagename)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_FWupdateAndFactoryReset(pUrl, pImagename);
}

extern "C" INT cm_hal_ReinitMac()
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_ReinitMac();
}

extern "C" INT docsis_GetProvIpType(CHAR *pValue)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_GetProvIpType(pValue);
}

extern "C" INT docsis_GetCert(CHAR *pCert)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_GetCert(pCert);
}

extern "C" INT docsis_GetCertStatus(ULONG *pVal)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_GetCertStatus(pVal);
}

extern "C" INT cm_hal_Get_CableModemResetCount(ULONG *resetcnt)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_Get_CableModemResetCount(resetcnt);
}

extern "C" INT cm_hal_Get_LocalResetCount(ULONG *resetcnt)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_Get_LocalResetCount(resetcnt);
}

extern "C" INT cm_hal_Get_DocsisResetCount(ULONG *resetcnt)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_Get_DocsisResetCount(resetcnt);
}

extern "C" INT cm_hal_Get_ErouterResetCount(ULONG *resetcnt)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_Get_ErouterResetCount(resetcnt);
}

extern "C" INT cm_hal_HTTP_LED_Flash(BOOLEAN LedFlash)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_HTTP_LED_Flash(LedFlash);
}

extern "C" INT docsis_GetDsOfdmChanTable(PDOCSIF31_CM_DS_OFDM_CHAN *ppinfo, int *output_NumberOfEntries)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_GetDsOfdmChanTable(ppinfo, output_NumberOfEntries);
}

extern "C" INT docsis_GetUsOfdmaChanTable(PDOCSIF31_CM_US_OFDMA_CHAN *ppinfo, int *output_NumberOfEntries)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_GetUsOfdmaChanTable(ppinfo, output_NumberOfEntries);
}

extern "C" INT docsis_GetStatusOfdmaUsTable(PDOCSIF31_CMSTATUSOFDMA_US *ppinfo, int *output_NumberOfEntries)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_GetStatusOfdmaUsTable(ppinfo, output_NumberOfEntries);
}

extern "C" INT docsis_LLDgetEnableStatus()
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_LLDgetEnableStatus();
}

extern "C" INT cm_hal_snmpv3_kickstart_initialize(snmpv3_kickstart_table_t *pKickstart_Table)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_snmpv3_kickstart_initialize(pKickstart_Table);
}

extern "C" INT docsis_IsEnergyDetected(BOOLEAN *pEnergyDetected)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->docsis_IsEnergyDetected(pEnergyDetected);
}

extern "C" INT cm_hal_set_ReinitMacThreshold(ULONG value)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_set_ReinitMacThreshold(value);
}

extern "C" INT cm_hal_get_ReinitMacThreshold(ULONG *pValue)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_get_ReinitMacThreshold(pValue);
}

extern "C" INT cm_hal_get_DiplexerSettings(CM_DIPLEXER_SETTINGS *pValue)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_get_DiplexerSettings(pValue);
}

extern "C" INT cm_hal_Register_DiplexerVariationCallback(cm_hal_DiplexerVariationCallback callback_proc)
{
    if (!g_cmHALMock)
    {
        return 0;
    }
    return g_cmHALMock->cm_hal_Register_DiplexerVariationCallback(callback_proc);
}