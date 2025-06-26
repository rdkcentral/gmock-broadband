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
#ifndef MOCK_CM_HAL_H
#define MOCK_CM_HAL_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "cm_hal.h"

class CmHalInterface
{
public:
    virtual ~CmHalInterface() {}
    virtual INT cm_hal_InitDB() = 0;
    virtual INT docsis_InitDS() = 0;
    virtual INT docsis_InitUS() = 0;
    virtual INT docsis_getCMStatus(CHAR *cm_status) = 0;
    virtual INT docsis_GetDSChannel(PCMMGMT_CM_DS_CHANNEL *ppinfo) = 0;
    virtual INT docsis_GetUsStatus(USHORT i, PCMMGMT_CM_US_CHANNEL pinfo) = 0;
    virtual INT docsis_GetUSChannel(PCMMGMT_CM_US_CHANNEL *ppinfo) = 0;
    virtual INT docsis_GetDOCSISInfo(PCMMGMT_CM_DOCSIS_INFO pinfo) = 0;
    virtual INT docsis_GetNumOfActiveTxChannels(ULONG *cnt) = 0;
    virtual INT docsis_GetNumOfActiveRxChannels(ULONG *cnt) = 0;
    virtual INT docsis_GetErrorCodewords(PCMMGMT_CM_ERROR_CODEWORDS *ppinfo) = 0;
    virtual INT docsis_GetMddIpModeOverride(CHAR *pValue) = 0;
    virtual INT docsis_SetMddIpModeOverride(CHAR *pValue) = 0;
    virtual UINT8 docsis_GetUSChannelId() = 0;
    virtual void docsis_SetUSChannelId(INT index) = 0;
    virtual ULONG docsis_GetDownFreq() = 0;
    virtual void docsis_SetStartFreq(ULONG value) = 0;
    virtual INT docsis_GetDocsisEventLogItems(CMMGMT_CM_EventLogEntry_t *entryArray, INT len) = 0;
    virtual INT docsis_ClearDocsisEventLog() = 0;
    virtual INT cm_hal_GetDHCPInfo(PCMMGMT_CM_DHCP_INFO pInfo) = 0;
    virtual INT cm_hal_GetIPv6DHCPInfo(PCMMGMT_CM_IPV6DHCP_INFO pInfo) = 0;
    virtual INT cm_hal_GetCPEList(PCMMGMT_DML_CPE_LIST *ppCPEList, ULONG *InstanceNum, CHAR *LanMode) = 0;
    virtual INT cm_hal_GetMarket(CHAR *market) = 0;
    virtual INT cm_hal_Set_HTTP_Download_Url(char *pHttpUrl, char *pfilename) = 0;
    virtual INT cm_hal_Get_HTTP_Download_Url(char *pHttpUrl, char *pfilename) = 0;
    virtual INT cm_hal_Set_HTTP_Download_Interface(unsigned int interface) = 0;
    virtual INT cm_hal_Get_HTTP_Download_Interface(unsigned int *pinterface) = 0;
    virtual INT cm_hal_HTTP_Download() = 0;
    virtual INT cm_hal_Get_HTTP_Download_Status() = 0;
    virtual INT cm_hal_Reboot_Ready(ULONG *pValue) = 0;
    virtual INT cm_hal_HTTP_Download_Reboot_Now() = 0;
    virtual INT cm_hal_FWupdateAndFactoryReset(char *pUrl, char *pImagename) = 0;
    virtual INT cm_hal_ReinitMac() = 0;
    virtual INT docsis_GetProvIpType(CHAR *pValue) = 0;
    virtual INT docsis_GetCert(CHAR *pCert) = 0;
    virtual INT docsis_GetCertStatus(ULONG *pVal) = 0;
    virtual INT cm_hal_Get_CableModemResetCount(ULONG *resetcnt) = 0;
    virtual INT cm_hal_Get_LocalResetCount(ULONG *resetcnt) = 0;
    virtual INT cm_hal_Get_DocsisResetCount(ULONG *resetcnt) = 0;
    virtual INT cm_hal_Get_ErouterResetCount(ULONG *resetcnt) = 0;
    virtual INT cm_hal_HTTP_LED_Flash(BOOLEAN LedFlash) = 0;
    virtual INT docsis_GetDsOfdmChanTable(PDOCSIF31_CM_DS_OFDM_CHAN *ppinfo, int *output_NumberOfEntries) = 0;
    virtual INT docsis_GetUsOfdmaChanTable(PDOCSIF31_CM_US_OFDMA_CHAN *ppinfo, int *output_NumberOfEntries) = 0;
    virtual INT docsis_GetStatusOfdmaUsTable(PDOCSIF31_CMSTATUSOFDMA_US *ppinfo, int *output_NumberOfEntries) = 0;
    virtual INT docsis_LLDgetEnableStatus() = 0;
    virtual INT cm_hal_snmpv3_kickstart_initialize(snmpv3_kickstart_table_t *pKickstart_Table) = 0;
    virtual INT docsis_IsEnergyDetected(BOOLEAN *pEnergyDetected) = 0;
    virtual INT cm_hal_set_ReinitMacThreshold(ULONG value) = 0;
    virtual INT cm_hal_get_ReinitMacThreshold(ULONG *pValue) = 0;
    virtual INT cm_hal_get_DiplexerSettings(CM_DIPLEXER_SETTINGS *pValue) = 0;
    virtual INT cm_hal_Register_DiplexerVariationCallback(cm_hal_DiplexerVariationCallback callback_proc) = 0;
};

class CmHalMock : public CmHalInterface
{
public:
    virtual ~CmHalMock() {}
    MOCK_METHOD0(cm_hal_InitDB, INT());
    MOCK_METHOD0(docsis_InitDS, INT());
    MOCK_METHOD0(docsis_InitUS, INT());
    MOCK_METHOD1(docsis_getCMStatus, INT(CHAR *));
    MOCK_METHOD1(docsis_GetDSChannel, INT(PCMMGMT_CM_DS_CHANNEL *));
    MOCK_METHOD2(docsis_GetUsStatus, INT(USHORT, PCMMGMT_CM_US_CHANNEL));
    MOCK_METHOD1(docsis_GetUSChannel, INT(PCMMGMT_CM_US_CHANNEL *));
    MOCK_METHOD1(docsis_GetDOCSISInfo, INT(PCMMGMT_CM_DOCSIS_INFO));
    MOCK_METHOD1(docsis_GetNumOfActiveTxChannels, INT(ULONG *));
    MOCK_METHOD1(docsis_GetNumOfActiveRxChannels, INT(ULONG *));
    MOCK_METHOD1(docsis_GetErrorCodewords, INT(PCMMGMT_CM_ERROR_CODEWORDS *));
    MOCK_METHOD1(docsis_GetMddIpModeOverride, INT(CHAR *));
    MOCK_METHOD1(docsis_SetMddIpModeOverride, INT(CHAR *));
    MOCK_METHOD0(docsis_GetUSChannelId, UINT8());
    MOCK_METHOD1(docsis_SetUSChannelId, void(INT));
    MOCK_METHOD0(docsis_GetDownFreq, ULONG());
    MOCK_METHOD1(docsis_SetStartFreq, void(ULONG));
    MOCK_METHOD2(docsis_GetDocsisEventLogItems, INT(CMMGMT_CM_EventLogEntry_t *, INT));
    MOCK_METHOD0(docsis_ClearDocsisEventLog, INT());
    MOCK_METHOD1(cm_hal_GetDHCPInfo, INT(PCMMGMT_CM_DHCP_INFO));
    MOCK_METHOD1(cm_hal_GetIPv6DHCPInfo, INT(PCMMGMT_CM_IPV6DHCP_INFO));
    MOCK_METHOD3(cm_hal_GetCPEList, INT(PCMMGMT_DML_CPE_LIST *, ULONG *, CHAR *));
    MOCK_METHOD1(cm_hal_GetMarket, INT(CHAR *));  
    MOCK_METHOD2(cm_hal_Set_HTTP_Download_Url, INT(char *, char *));
    MOCK_METHOD2(cm_hal_Get_HTTP_Download_Url, INT(char *, char *));
    MOCK_METHOD1(cm_hal_Set_HTTP_Download_Interface, INT(unsigned int));
    MOCK_METHOD1(cm_hal_Get_HTTP_Download_Interface, INT(unsigned int *));
    MOCK_METHOD0(cm_hal_HTTP_Download, INT());
    MOCK_METHOD0(cm_hal_Get_HTTP_Download_Status, INT());
    MOCK_METHOD1(cm_hal_Reboot_Ready, INT(ULONG *));
    MOCK_METHOD0(cm_hal_HTTP_Download_Reboot_Now, INT());
    MOCK_METHOD2(cm_hal_FWupdateAndFactoryReset, INT(char *, char *));
    MOCK_METHOD0(cm_hal_ReinitMac, INT());
    MOCK_METHOD1(docsis_GetProvIpType, INT(CHAR *));
    MOCK_METHOD1(docsis_GetCert, INT(CHAR *));
    MOCK_METHOD1(docsis_GetCertStatus, INT(ULONG *));
    MOCK_METHOD1(cm_hal_Get_CableModemResetCount, INT(ULONG *));
    MOCK_METHOD1(cm_hal_Get_LocalResetCount, INT(ULONG *));
    MOCK_METHOD1(cm_hal_Get_DocsisResetCount, INT(ULONG *));
    MOCK_METHOD1(cm_hal_Get_ErouterResetCount, INT(ULONG *));
    MOCK_METHOD1(cm_hal_HTTP_LED_Flash, INT(BOOLEAN));
    MOCK_METHOD2(docsis_GetDsOfdmChanTable, INT(PDOCSIF31_CM_DS_OFDM_CHAN *, int *));
    MOCK_METHOD2(docsis_GetUsOfdmaChanTable, INT(PDOCSIF31_CM_US_OFDMA_CHAN *, int *));
    MOCK_METHOD2(docsis_GetStatusOfdmaUsTable, INT(PDOCSIF31_CMSTATUSOFDMA_US *, int *));
    MOCK_METHOD0(docsis_LLDgetEnableStatus, INT());
    MOCK_METHOD1(cm_hal_snmpv3_kickstart_initialize, INT(snmpv3_kickstart_table_t *));
    MOCK_METHOD1(docsis_IsEnergyDetected, INT(BOOLEAN *));
    MOCK_METHOD1(cm_hal_set_ReinitMacThreshold, INT(ULONG));
    MOCK_METHOD1(cm_hal_get_ReinitMacThreshold, INT(ULONG *));
    MOCK_METHOD1(cm_hal_get_DiplexerSettings, INT(CM_DIPLEXER_SETTINGS *));
    MOCK_METHOD1(cm_hal_Register_DiplexerVariationCallback, INT(cm_hal_DiplexerVariationCallback));
};

#endif // MOCK_CM_HAL_H