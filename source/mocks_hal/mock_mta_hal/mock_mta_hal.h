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

#ifndef MOCK_MTA_HAL_H
#define MOCK_MTA_HAL_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {
#include "mta_hal.h"
}

class MtaHalInterface
{
public:
    virtual ~MtaHalInterface() {}
    virtual INT mta_hal_InitDB() = 0;
    virtual INT mta_hal_GetDHCPInfo(PMTAMGMT_MTA_DHCP_INFO pInfo) = 0;
    virtual INT mta_hal_GetDHCPV6Info(PMTAMGMT_MTA_DHCPv6_INFO pInfo) = 0;
    virtual ULONG mta_hal_LineTableGetNumberOfEntries() = 0;
    virtual INT mta_hal_LineTableGetEntry(ULONG Index, PMTAMGMT_MTA_LINETABLE_INFO pEntry) = 0;
    virtual INT mta_hal_TriggerDiagnostics(ULONG Index) = 0;
    virtual INT mta_hal_GetServiceFlow(ULONG* Count, PMTAMGMT_MTA_SERVICE_FLOW *ppCfg) = 0;
    virtual INT mta_hal_DectGetEnable(BOOLEAN *pBool) = 0;
    virtual INT mta_hal_DectSetEnable(BOOLEAN bBool) = 0;
    virtual INT mta_hal_DectGetRegistrationMode(BOOLEAN* pBool) = 0;
    virtual INT mta_hal_DectSetRegistrationMode(BOOLEAN bBool) = 0;
    virtual INT mta_hal_DectDeregisterDectHandset(ULONG uValue) = 0;
    virtual INT mta_hal_GetDect(PMTAMGMT_MTA_DECT pDect) = 0;
    virtual INT mta_hal_GetDectPIN(char* pPINString) = 0;
    virtual INT mta_hal_SetDectPIN(char* pPINString) = 0;
    virtual INT mta_hal_GetHandsets(ULONG* pulCount, PMTAMGMT_MTA_HANDSETS_INFO* ppHandsets) = 0;
    virtual INT mta_hal_GetCalls(ULONG InstanceNumber, ULONG *Count, PMTAMGMT_MTA_CALLS *ppCfg) = 0;
    virtual INT mta_hal_GetCALLP(ULONG LineNumber, PMTAMGMT_MTA_CALLP pCallp) = 0;
    virtual INT mta_hal_GetDSXLogs(ULONG *Count, PMTAMGMT_MTA_DSXLOG *ppDSXLog) = 0;
    virtual INT mta_hal_GetDSXLogEnable(BOOLEAN *pBool) = 0;
    virtual INT mta_hal_SetDSXLogEnable(BOOLEAN Bool) = 0;
    virtual INT mta_hal_ClearDSXLog(BOOLEAN Bool) = 0;
    virtual INT mta_hal_GetCallSignallingLogEnable(BOOLEAN *pBool) = 0;
    virtual INT mta_hal_SetCallSignallingLogEnable(BOOLEAN Bool) = 0;
    virtual INT mta_hal_ClearCallSignallingLog(BOOLEAN Bool) = 0;
    virtual INT mta_hal_GetMtaLog(ULONG *Count, PMTAMGMT_MTA_MTALOG_FULL *ppCfg) = 0;
    virtual INT mta_hal_BatteryGetInstalled(BOOLEAN* Val) = 0;
    virtual INT mta_hal_BatteryGetTotalCapacity(ULONG* Val) = 0;
    virtual INT mta_hal_BatteryGetActualCapacity(ULONG* Val) = 0;
    virtual INT mta_hal_BatteryGetRemainingCharge(ULONG* Val) = 0;
    virtual INT mta_hal_BatteryGetRemainingTime(ULONG* Val) = 0;
    virtual INT mta_hal_BatteryGetNumberofCycles(ULONG* Val) = 0;
    virtual INT mta_hal_BatteryGetPowerStatus(CHAR *Val, ULONG *len) = 0;
    virtual INT mta_hal_BatteryGetCondition(CHAR *Val, ULONG *len) = 0;
    virtual INT mta_hal_BatteryGetStatus(CHAR* Val, ULONG *len) = 0;
    virtual INT mta_hal_BatteryGetLife(CHAR* Val, ULONG *len) = 0;
    virtual INT mta_hal_BatteryGetInfo(PMTAMGMT_MTA_BATTERY_INFO pInfo) = 0;
    virtual INT mta_hal_BatteryGetPowerSavingModeStatus(ULONG *pValue) = 0;
    virtual INT mta_hal_Get_MTAResetCount(ULONG *resetcnt) = 0;
    virtual INT mta_hal_Get_LineResetCount(ULONG *resetcnt) = 0;
    virtual INT mta_hal_ClearCalls(ULONG InstanceNumber) = 0;
    virtual INT mta_hal_getDhcpStatus(MTAMGMT_MTA_STATUS *output_pIpv4status, MTAMGMT_MTA_STATUS *output_pIpv6status) = 0;
    virtual INT mta_hal_getConfigFileStatus(MTAMGMT_MTA_STATUS *poutput_status) = 0;
    virtual INT mta_hal_getLineRegisterStatus(MTAMGMT_MTA_STATUS *output_status_array, int array_size) = 0;
    virtual INT mta_hal_devResetNow(BOOLEAN bResetValue) = 0;
    virtual INT mta_hal_getMtaOperationalStatus(MTAMGMT_MTA_STATUS *operationalStatus) = 0;
    virtual INT mta_hal_getMtaProvisioningStatus(MTAMGMT_MTA_PROVISION_STATUS *provisionStatus) = 0;
    virtual INT mta_hal_start_provisioning(PMTAMGMT_MTA_PROVISIONING_PARAMS pParameters) = 0;
    virtual void mta_hal_LineRegisterStatus_callback_register(mta_hal_getLineRegisterStatus_callback callback_proc) = 0;
    virtual int mta_hal_getTR104parameterValues(char **parameterNamesList, int *parameterListLen, char ***parameterValuesList) = 0;
    virtual int mta_hal_freeTR104parameterValues(char **parameterValuesList, int parameterListLen) = 0;
    virtual int mta_hal_setTR104parameterValues(char **parameterValueList, int *parameterListLen) = 0;
    virtual int mta_hal_getTR104parameterNames(char ***parameterNamesList, int *parameterListLen) = 0;
};

class MtaHalMock : public MtaHalInterface
{
public:
    virtual ~MtaHalMock() {}
    MOCK_METHOD0(mta_hal_InitDB, INT());
    MOCK_METHOD1(mta_hal_GetDHCPInfo, INT(PMTAMGMT_MTA_DHCP_INFO));
    MOCK_METHOD1(mta_hal_GetDHCPV6Info, INT(PMTAMGMT_MTA_DHCPv6_INFO));
    MOCK_METHOD0(mta_hal_LineTableGetNumberOfEntries, ULONG());
    MOCK_METHOD2(mta_hal_LineTableGetEntry, INT(ULONG, PMTAMGMT_MTA_LINETABLE_INFO));
    MOCK_METHOD1(mta_hal_TriggerDiagnostics, INT(ULONG));
    MOCK_METHOD2(mta_hal_GetServiceFlow, INT(ULONG*, PMTAMGMT_MTA_SERVICE_FLOW*));
    MOCK_METHOD1(mta_hal_DectGetEnable, INT(BOOLEAN*));
    MOCK_METHOD1(mta_hal_DectSetEnable, INT(BOOLEAN));
    MOCK_METHOD1(mta_hal_DectGetRegistrationMode, INT(BOOLEAN*));
    MOCK_METHOD1(mta_hal_DectSetRegistrationMode, INT(BOOLEAN));
    MOCK_METHOD1(mta_hal_DectDeregisterDectHandset, INT(ULONG));
    MOCK_METHOD1(mta_hal_GetDect, INT(PMTAMGMT_MTA_DECT));
    MOCK_METHOD1(mta_hal_GetDectPIN, INT(char*));
    MOCK_METHOD1(mta_hal_SetDectPIN, INT(char*));
    MOCK_METHOD2(mta_hal_GetHandsets, INT(ULONG*, PMTAMGMT_MTA_HANDSETS_INFO*));
    MOCK_METHOD3(mta_hal_GetCalls, INT(ULONG, ULONG*, PMTAMGMT_MTA_CALLS*));
    MOCK_METHOD2(mta_hal_GetCALLP, INT(ULONG, PMTAMGMT_MTA_CALLP));
    MOCK_METHOD2(mta_hal_GetDSXLogs, INT(ULONG*, PMTAMGMT_MTA_DSXLOG*));
    MOCK_METHOD1(mta_hal_GetDSXLogEnable, INT(BOOLEAN*));
    MOCK_METHOD1(mta_hal_SetDSXLogEnable, INT(BOOLEAN));
    MOCK_METHOD1(mta_hal_ClearDSXLog, INT(BOOLEAN));
    MOCK_METHOD1(mta_hal_GetCallSignallingLogEnable, INT(BOOLEAN*));
    MOCK_METHOD1(mta_hal_SetCallSignallingLogEnable, INT(BOOLEAN));
    MOCK_METHOD1(mta_hal_ClearCallSignallingLog, INT(BOOLEAN));
    MOCK_METHOD2(mta_hal_GetMtaLog, INT(ULONG*, PMTAMGMT_MTA_MTALOG_FULL*));
    MOCK_METHOD1(mta_hal_BatteryGetInstalled, INT(BOOLEAN*));
    MOCK_METHOD1(mta_hal_BatteryGetTotalCapacity, INT(ULONG*));
    MOCK_METHOD1(mta_hal_BatteryGetActualCapacity, INT(ULONG*));
    MOCK_METHOD1(mta_hal_BatteryGetRemainingCharge, INT(ULONG*));
    MOCK_METHOD1(mta_hal_BatteryGetRemainingTime, INT(ULONG*));
    MOCK_METHOD1(mta_hal_BatteryGetNumberofCycles, INT(ULONG*));
    MOCK_METHOD2(mta_hal_BatteryGetPowerStatus, INT(CHAR*, ULONG*));
    MOCK_METHOD2(mta_hal_BatteryGetCondition, INT(CHAR*, ULONG*));
    MOCK_METHOD2(mta_hal_BatteryGetStatus, INT(CHAR*, ULONG*));
    MOCK_METHOD2(mta_hal_BatteryGetLife, INT(CHAR*, ULONG*));
    MOCK_METHOD1(mta_hal_BatteryGetInfo, INT(PMTAMGMT_MTA_BATTERY_INFO));
    MOCK_METHOD1(mta_hal_BatteryGetPowerSavingModeStatus, INT(ULONG*));
    MOCK_METHOD1(mta_hal_Get_MTAResetCount, INT(ULONG*));
    MOCK_METHOD1(mta_hal_Get_LineResetCount, INT(ULONG*));
    MOCK_METHOD1(mta_hal_ClearCalls, INT(ULONG));
    MOCK_METHOD2(mta_hal_getDhcpStatus, INT(MTAMGMT_MTA_STATUS*, MTAMGMT_MTA_STATUS*));
    MOCK_METHOD1(mta_hal_getConfigFileStatus, INT(MTAMGMT_MTA_STATUS*));
    MOCK_METHOD2(mta_hal_getLineRegisterStatus, INT(MTAMGMT_MTA_STATUS*, int));
    MOCK_METHOD1(mta_hal_devResetNow, INT(BOOLEAN));
    MOCK_METHOD1(mta_hal_getMtaOperationalStatus, INT(MTAMGMT_MTA_STATUS*));
    MOCK_METHOD1(mta_hal_getMtaProvisioningStatus, INT(MTAMGMT_MTA_PROVISION_STATUS*));
    MOCK_METHOD1(mta_hal_start_provisioning, INT(PMTAMGMT_MTA_PROVISIONING_PARAMS));
    MOCK_METHOD1(mta_hal_LineRegisterStatus_callback_register, void(mta_hal_getLineRegisterStatus_callback));
    MOCK_METHOD3(mta_hal_getTR104parameterValues, INT(char**, int*, char***));
    MOCK_METHOD2(mta_hal_freeTR104parameterValues, INT(char**, int));
    MOCK_METHOD2(mta_hal_setTR104parameterValues, INT(char**, int*));
    MOCK_METHOD2(mta_hal_getTR104parameterNames, INT(char***, int*));
};

#endif // MOCK_MTA_HAL_H