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

#include "mock_mta_hal.h"

extern MtaHalMock *g_mtaHALMock;

extern "C" INT mta_hal_InitDB()
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_InitDB();
}

extern "C" INT mta_hal_GetDHCPInfo(PMTAMGMT_MTA_DHCP_INFO pInfo)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_GetDHCPInfo(pInfo);
}

extern "C" INT mta_hal_GetDHCPV6Info(PMTAMGMT_MTA_DHCPv6_INFO pInfo)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_GetDHCPV6Info(pInfo);
}

extern "C" ULONG mta_hal_LineTableGetNumberOfEntries()
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_LineTableGetNumberOfEntries();
}

extern "C" INT mta_hal_LineTableGetEntry(ULONG Index, PMTAMGMT_MTA_LINETABLE_INFO pEntry)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_LineTableGetEntry(Index, pEntry);
}

extern "C" INT mta_hal_TriggerDiagnostics(ULONG Index)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_TriggerDiagnostics(Index);
}

extern "C" INT mta_hal_GetServiceFlow(ULONG* Count, PMTAMGMT_MTA_SERVICE_FLOW *ppCfg)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_GetServiceFlow(Count, ppCfg);
}

extern "C" INT mta_hal_DectGetEnable(BOOLEAN *pBool)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_DectGetEnable(pBool);
}

extern "C" INT mta_hal_DectSetEnable(BOOLEAN bBool)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_DectSetEnable(bBool);
}

extern "C" INT mta_hal_DectGetRegistrationMode(BOOLEAN* pBool)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_DectGetRegistrationMode(pBool);
}

extern "C" INT mta_hal_DectSetRegistrationMode(BOOLEAN bBool)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_DectSetRegistrationMode(bBool);
}

extern "C" INT mta_hal_DectDeregisterDectHandset(ULONG uValue)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_DectDeregisterDectHandset(uValue);
}

extern "C" INT mta_hal_GetDect(PMTAMGMT_MTA_DECT pDect)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_GetDect(pDect);
}

extern "C" INT mta_hal_GetDectPIN(char* pPINString)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_GetDectPIN(pPINString);
}

extern "C" INT mta_hal_SetDectPIN(char* pPINString)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_SetDectPIN(pPINString);
}

extern "C" INT mta_hal_GetHandsets(ULONG* pulCount, PMTAMGMT_MTA_HANDSETS_INFO* ppHandsets)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_GetHandsets(pulCount, ppHandsets);
}

extern "C" INT mta_hal_GetCalls(ULONG InstanceNumber, ULONG *Count, PMTAMGMT_MTA_CALLS *ppCfg)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_GetCalls(InstanceNumber, Count, ppCfg);
}

extern "C" INT mta_hal_GetCALLP(ULONG LineNumber, PMTAMGMT_MTA_CALLP pCallp)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_GetCALLP(LineNumber, pCallp);
}

extern "C" INT mta_hal_GetDSXLogs(ULONG *Count, PMTAMGMT_MTA_DSXLOG *ppDSXLog)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_GetDSXLogs(Count, ppDSXLog);
}

extern "C" INT mta_hal_GetDSXLogEnable(BOOLEAN *pBool)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_GetDSXLogEnable(pBool);
}

extern "C" INT mta_hal_SetDSXLogEnable(BOOLEAN Bool)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_SetDSXLogEnable(Bool);
}

extern "C" INT mta_hal_ClearDSXLog(BOOLEAN Bool)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_ClearDSXLog(Bool);
}

extern "C" INT mta_hal_GetCallSignallingLogEnable(BOOLEAN *pBool)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_GetCallSignallingLogEnable(pBool);
}

extern "C" INT mta_hal_SetCallSignallingLogEnable(BOOLEAN Bool)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_SetCallSignallingLogEnable(Bool);
}

extern "C" INT mta_hal_ClearCallSignallingLog(BOOLEAN Bool)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_ClearCallSignallingLog(Bool);
}

extern "C" INT mta_hal_GetMtaLog(ULONG *Count, PMTAMGMT_MTA_MTALOG_FULL *ppCfg)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_GetMtaLog(Count, ppCfg);
}

extern "C" INT mta_hal_BatteryGetInstalled(BOOLEAN* Val)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_BatteryGetInstalled(Val);
}

extern "C" INT mta_hal_BatteryGetTotalCapacity(ULONG* Val)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_BatteryGetTotalCapacity(Val);
}

extern "C" INT mta_hal_BatteryGetActualCapacity(ULONG* Val)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_BatteryGetActualCapacity(Val);
}

extern "C" INT mta_hal_BatteryGetRemainingCharge(ULONG* Val)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_BatteryGetRemainingCharge(Val);
}

extern "C" INT mta_hal_BatteryGetRemainingTime(ULONG* Val)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_BatteryGetRemainingTime(Val);
}

extern "C" INT mta_hal_BatteryGetNumberofCycles(ULONG* Val)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_BatteryGetNumberofCycles(Val);
}

extern "C" INT mta_hal_BatteryGetPowerStatus(CHAR *Val, ULONG *len)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_BatteryGetPowerStatus(Val, len);
}

extern "C" INT mta_hal_BatteryGetCondition(CHAR *Val, ULONG *len)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_BatteryGetCondition(Val, len);
}

extern "C" INT mta_hal_BatteryGetStatus(CHAR* Val, ULONG *len)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_BatteryGetStatus(Val, len);
}

extern "C" INT mta_hal_BatteryGetLife(CHAR* Val, ULONG *len)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_BatteryGetLife(Val, len);
}

extern "C" INT mta_hal_BatteryGetInfo(PMTAMGMT_MTA_BATTERY_INFO pInfo)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_BatteryGetInfo(pInfo);
}

extern "C" INT mta_hal_BatteryGetPowerSavingModeStatus(ULONG *pValue)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_BatteryGetPowerSavingModeStatus(pValue);
}

extern "C" INT mta_hal_Get_MTAResetCount(ULONG *resetcnt)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_Get_MTAResetCount(resetcnt);
}

extern "C" INT mta_hal_Get_LineResetCount(ULONG *resetcnt)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_Get_LineResetCount(resetcnt);
}

extern "C" INT mta_hal_ClearCalls(ULONG InstanceNumber)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_ClearCalls(InstanceNumber);
}

extern "C" INT mta_hal_getDhcpStatus(MTAMGMT_MTA_STATUS *output_pIpv4status, MTAMGMT_MTA_STATUS *output_pIpv6status)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_getDhcpStatus(output_pIpv4status, output_pIpv6status);
}

extern "C" INT mta_hal_getConfigFileStatus(MTAMGMT_MTA_STATUS *poutput_status)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_getConfigFileStatus(poutput_status);
}

extern "C" INT mta_hal_getLineRegisterStatus(MTAMGMT_MTA_STATUS *output_status_array, int array_size)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_getLineRegisterStatus(output_status_array, array_size);
}

extern "C" INT mta_hal_devResetNow(BOOLEAN bResetValue)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_devResetNow(bResetValue);
}

extern "C" INT mta_hal_getMtaOperationalStatus(MTAMGMT_MTA_STATUS *operationalStatus)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_getMtaOperationalStatus(operationalStatus);
}

extern "C" INT mta_hal_getMtaProvisioningStatus(MTAMGMT_MTA_PROVISION_STATUS *provisionStatus)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_getMtaProvisioningStatus(provisionStatus);
}

extern "C" INT mta_hal_start_provisioning(PMTAMGMT_MTA_PROVISIONING_PARAMS pParameters)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_start_provisioning(pParameters);
}

extern "C" void mta_hal_LineRegisterStatus_callback_register(mta_hal_getLineRegisterStatus_callback callback_proc)
{
    if (!g_mtaHALMock)
    {
        return;
    }
    g_mtaHALMock->mta_hal_LineRegisterStatus_callback_register(callback_proc);
}

extern "C" int mta_hal_getTR104parameterValues(char **parameterNamesList, int *parameterListLen, char ***parameterValuesList)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_getTR104parameterValues(parameterNamesList, parameterListLen, parameterValuesList);
}

extern "C" int mta_hal_freeTR104parameterValues(char **parameterValuesList, int parameterListLen)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_freeTR104parameterValues(parameterValuesList, parameterListLen);
}

extern "C" int mta_hal_setTR104parameterValues(char **parameterValueList, int *parameterListLen)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_setTR104parameterValues(parameterValueList, parameterListLen);
}

extern "C" int mta_hal_getTR104parameterNames(char ***parameterNamesList, int *parameterListLen)
{
    if (!g_mtaHALMock)
    {
        return 0;
    }
    return g_mtaHALMock->mta_hal_getTR104parameterNames(parameterNamesList, parameterListLen);
}