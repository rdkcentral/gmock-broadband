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

#include "mock_platform_hal.h"

extern PlatformHalMock *g_platformHALMock;

extern "C" INT platform_hal_GetDeviceConfigStatus(CHAR *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetDeviceConfigStatus(pValue);
}

extern "C" INT platform_hal_GetTelnetEnable(BOOLEAN *pFlag)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetTelnetEnable(pFlag);
}

extern "C" INT platform_hal_SetTelnetEnable(BOOLEAN Flag)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_SetTelnetEnable(Flag);
}

extern "C" INT platform_hal_GetSSHEnable(BOOLEAN *pFlag)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetSSHEnable(pFlag);
}

extern "C" INT platform_hal_SetSSHEnable(BOOLEAN Flag)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_SetSSHEnable(Flag);
}

extern "C" INT platform_hal_GetSNMPEnable(CHAR *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetSNMPEnable(pValue);
}

extern "C" INT platform_hal_SetSNMPEnable(CHAR *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_SetSNMPEnable(pValue);
}

extern "C" INT platform_hal_GetWebUITimeout(ULONG *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetWebUITimeout(pValue);
}

extern "C" INT platform_hal_SetWebUITimeout(ULONG value)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_SetWebUITimeout(value);
}

extern "C" INT platform_hal_GetWebAccessLevel(INT userIndex, INT ifIndex, ULONG *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetWebAccessLevel(userIndex, ifIndex, pValue);
}

extern "C" INT platform_hal_SetWebAccessLevel(INT userIndex, INT ifIndex, ULONG value)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_SetWebAccessLevel(userIndex, ifIndex, value);
}

extern "C" INT platform_hal_PandMDBInit()
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_PandMDBInit();
}

extern "C" INT platform_hal_DocsisParamsDBInit()
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_DocsisParamsDBInit();
}

extern "C" INT platform_hal_GetModelName(CHAR *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetModelName(pValue);
}

extern "C" INT platform_hal_GetRouterRegion(CHAR *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetRouterRegion(pValue);
}

extern "C" INT platform_hal_GetSerialNumber(CHAR *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetSerialNumber(pValue);
}

extern "C" INT platform_hal_GetHardwareVersion(CHAR *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetHardwareVersion(pValue);
}

extern "C" INT platform_hal_GetSoftwareVersion(CHAR *pValue, ULONG maxSize)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetSoftwareVersion(pValue, maxSize);
}

extern "C" INT platform_hal_GetBootloaderVersion(CHAR *pValue, ULONG maxSize)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetBootloaderVersion(pValue, maxSize);
}

extern "C" INT platform_hal_GetFirmwareName(CHAR *pValue, ULONG maxSize)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetFirmwareName(pValue, maxSize);
}

extern "C" INT platform_hal_GetBaseMacAddress(CHAR *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetBaseMacAddress(pValue);
}

extern "C" INT platform_hal_GetHardware(CHAR *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetHardware(pValue);
}

extern "C" INT platform_hal_GetHardware_MemUsed(CHAR *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetHardware_MemUsed(pValue);
}

extern "C" INT platform_hal_GetHardware_MemFree(CHAR *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetHardware_MemFree(pValue);
}

extern "C" INT platform_hal_GetTotalMemorySize(ULONG *pulSize)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetTotalMemorySize(pulSize);
}

extern "C" INT platform_hal_GetUsedMemorySize(ULONG *pulSize)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetUsedMemorySize(pulSize);
}

extern "C" INT platform_hal_GetFreeMemorySize(ULONG *pulSize)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetFreeMemorySize(pulSize);
}

extern "C" INT platform_hal_GetFactoryResetCount(ULONG *pulSize)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetFactoryResetCount(pulSize);
}

extern "C" INT platform_hal_ClearResetCount(BOOLEAN bFlag)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_ClearResetCount(bFlag);
}

extern "C" INT platform_hal_getTimeOffSet(CHAR *timeOffSet)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_getTimeOffSet(timeOffSet);
}

extern "C" INT platform_hal_SetDeviceCodeImageTimeout(INT seconds)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_SetDeviceCodeImageTimeout(seconds);
}

extern "C" INT platform_hal_SetDeviceCodeImageValid(BOOLEAN flag)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_SetDeviceCodeImageValid(flag);
}

extern "C" INT platform_hal_getFactoryPartnerId(CHAR *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_getFactoryPartnerId(pValue);
}

extern "C" INT platform_hal_getFactoryCmVariant(CHAR *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_getFactoryCmVariant(pValue);
}

extern "C" INT platform_hal_setFactoryCmVariant(CHAR *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_setFactoryCmVariant(pValue);
}

#ifdef FEATURE_RDKB_LED_MANAGER
extern "C" INT platform_hal_initLed(CHAR *config_file_name)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_initLed(config_file_name);
}
#endif

extern "C" INT platform_hal_setLed(PLEDMGMT_PARAMS pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_setLed(pValue);
}

extern "C" INT platform_hal_getLed(PLEDMGMT_PARAMS pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_getLed(pValue);
}

extern "C" UINT platform_hal_getFanSpeed(UINT fanIndex)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_getFanSpeed(fanIndex);
}

extern "C" UINT platform_hal_getRPM(UINT fanIndex)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_getRPM(fanIndex);
}

extern "C" INT platform_hal_getRotorLock(UINT fanIndex)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_getRotorLock(fanIndex);
}

extern "C" BOOLEAN platform_hal_getFanStatus(UINT fanIndex)
{
    if (!g_platformHALMock)
    {
        return FALSE;
    }
    return g_platformHALMock->platform_hal_getFanStatus(fanIndex);
}

extern "C" INT platform_hal_setFanMaxOverride(BOOLEAN bOverrideFlag, UINT fanIndex)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_setFanMaxOverride(bOverrideFlag, fanIndex);
}

#ifdef FEATURE_RDKB_THERMAL_MANAGER
extern "C" INT platform_hal_initThermal(THERMAL_PLATFORM_CONFIG *pThermalPlatformConfig)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_initThermal(pThermalPlatformConfig);
}

extern "C" INT platform_hal_LoadThermalConfig(THERMAL_PLATFORM_CONFIG *pThermalPlatformConfig)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_LoadThermalConfig(pThermalPlatformConfig);
}

extern "C" INT platform_hal_setFanSpeed(UINT fanIndex, FAN_SPEED fanSpeed, FAN_ERR *pErrReason)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_setFanSpeed(fanIndex, fanSpeed, pErrReason);
}

extern "C" INT platform_hal_getFanTemperature(INT *pTemp)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_getFanTemperature(pTemp);
}

extern "C" INT platform_hal_getInputCurrent(INT *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_getInputCurrent(pValue);
}

extern "C" INT platform_hal_getInputPower(INT *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_getInputPower(pValue);
}

extern "C" INT platform_hal_getRadioTemperature(INT radioIndex, INT *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_getRadioTemperature(radioIndex, pValue);
}

extern "C" INT platform_hal_getEcoModeStatus(INT radioIndex, INT *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_getEcoModeStatus(radioIndex, pValue);
}
#endif

extern "C" INT platform_hal_SetSNMPOnboardRebootEnable(CHAR *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_SetSNMPOnboardRebootEnable(pValue);
}

extern "C" INT platform_hal_GetMACsecEnable(INT ethPort, BOOLEAN *pFlag)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetMACsecEnable(ethPort, pFlag);
}

extern "C" INT platform_hal_SetMACsecEnable(INT ethPlatform, BOOLEAN flag)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_SetMACsecEnable(ethPlatform, flag);
}

extern "C" INT platform_hal_GetMACsecOperationalStatus(INT ethPort, BOOLEAN *pFlag)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetMACsecOperationalStatus(ethPort, pFlag);
}

extern "C" INT platform_hal_StartMACsec(INT ethPort, INT timeoutSec)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_StartMACsec(ethPort, timeoutSec);
}

extern "C" INT platform_hal_StopMACsec(INT ethPort)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_StopMACsec(ethPort);
}

extern "C" INT platform_hal_GetMemoryPaths(RDK_CPUS index, PPLAT_PROC_MEM_INFO *ppinfo)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetMemoryPaths(index, ppinfo);
}

extern "C" INT platform_hal_GetDhcpv4_Options(dhcp_opt_list **req_opt_list, dhcp_opt_list **send_opt_list)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetDhcpv4_Options(req_opt_list, send_opt_list);
}

extern "C" INT platform_hal_GetDhcpv6_Options(dhcp_opt_list **req_opt_list, dhcp_opt_list **send_opt_list)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetDhcpv6_Options(req_opt_list, send_opt_list);
}

extern "C" INT platform_hal_SetLowPowerModeState(PPSM_STATE pState)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_SetLowPowerModeState(pState);
}

extern "C" INT platform_hal_getCMTSMac(CHAR *pValue)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_getCMTSMac(pValue);
}

extern "C" INT platform_hal_setDscp(WAN_INTERFACE interfaceType, TRAFFIC_CNT_COMMAND cmd, CHAR *pDscpVals)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_setDscp(interfaceType, cmd, pDscpVals);
}

extern "C" INT platform_hal_resetDscpCounts(WAN_INTERFACE interfaceType)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_resetDscpCounts(interfaceType);
}

extern "C" INT platform_hal_getDscpClientList(WAN_INTERFACE interfaceType, pDSCP_list_t pDSCP_List)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_getDscpClientList(interfaceType, pDSCP_List);
}

extern "C" INT platform_hal_GetCPUSpeed(CHAR *cpuSpeed)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetCPUSpeed(cpuSpeed);
}

extern "C" INT platform_hal_GetFirmwareBankInfo(FW_BANK bankIndex, PFW_BANK_INFO pFW_Bankinfo)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetFirmwareBankInfo(bankIndex, pFW_Bankinfo);
}

extern "C" INT platform_hal_GetInterfaceStats(const CHAR *ifname, PINTF_STATS pIntfStats)
{
    if (!g_platformHALMock)
    {
        return 0;
    }
    return g_platformHALMock->platform_hal_GetInterfaceStats(ifname, pIntfStats);
}