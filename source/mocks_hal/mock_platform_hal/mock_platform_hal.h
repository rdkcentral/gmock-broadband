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

#ifndef MOCK_PLATFORM_HAL_H
#define MOCK_PLATFORM_HAL_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "platform_hal.h"

#ifndef ULONG
typedef unsigned long ULONG;
#endif

class PlatformHalInterface
{
public:
    virtual ~PlatformHalInterface() {}
    virtual INT platform_hal_GetDeviceConfigStatus(CHAR *pValue) = 0;
    virtual INT platform_hal_GetTelnetEnable(BOOLEAN *pFlag) = 0;
    virtual INT platform_hal_SetTelnetEnable(BOOLEAN Flag) = 0;
    virtual INT platform_hal_GetSSHEnable(BOOLEAN *pFlag) = 0;
    virtual INT platform_hal_SetSSHEnable(BOOLEAN Flag) = 0;
    virtual INT platform_hal_GetSNMPEnable(CHAR *pValue) = 0;
    virtual INT platform_hal_SetSNMPEnable(CHAR *pValue) = 0;
    virtual INT platform_hal_GetWebUITimeout(ULONG *pValue) = 0;
    virtual INT platform_hal_SetWebUITimeout(ULONG value) = 0;
    virtual INT platform_hal_GetWebAccessLevel(INT userIndex, INT ifIndex, ULONG *pValue) = 0;
    virtual INT platform_hal_SetWebAccessLevel(INT userIndex, INT ifIndex, ULONG value) = 0;
    virtual INT platform_hal_PandMDBInit(void) = 0;
    virtual INT platform_hal_DocsisParamsDBInit(void) = 0;
    virtual INT platform_hal_GetModelName(CHAR *pValue) = 0;
    virtual INT platform_hal_GetRouterRegion(CHAR *pValue) = 0;
    virtual INT platform_hal_GetSerialNumber(CHAR *pValue) = 0;
    virtual INT platform_hal_GetHardwareVersion(CHAR *pValue) = 0;
    virtual INT platform_hal_GetSoftwareVersion(CHAR* pValue, ULONG maxSize) = 0;
    virtual INT platform_hal_GetBootloaderVersion(CHAR *pValue, ULONG maxSize) = 0;
    virtual INT platform_hal_GetFirmwareName(CHAR *pValue, ULONG maxSize) = 0;
    virtual INT platform_hal_GetBaseMacAddress(CHAR *pValue) = 0;
    virtual INT platform_hal_GetHardware(CHAR *pValue) = 0;
    virtual INT platform_hal_GetHardware_MemUsed(CHAR *pValue) = 0;
    virtual INT platform_hal_GetHardware_MemFree(CHAR *pValue) = 0;
    virtual INT platform_hal_GetTotalMemorySize(ULONG *pulSize) = 0;
    virtual INT platform_hal_GetUsedMemorySize(ULONG *pulSize) = 0;
    virtual INT platform_hal_GetFreeMemorySize(ULONG *pulSize) = 0;
    virtual INT platform_hal_GetFactoryResetCount(ULONG *pulSize) = 0;
    virtual INT platform_hal_ClearResetCount(BOOLEAN bFlag) = 0;
    virtual INT platform_hal_getTimeOffSet(CHAR *timeOffSet) = 0;
    virtual INT platform_hal_SetDeviceCodeImageTimeout(INT seconds) = 0;
    virtual INT platform_hal_SetDeviceCodeImageValid(BOOLEAN flag) = 0;
    virtual INT platform_hal_getFactoryPartnerId(CHAR *pValue) = 0;
    virtual INT platform_hal_getFactoryCmVariant(CHAR *pValue) = 0;
    virtual INT platform_hal_setFactoryCmVariant(CHAR *pValue) = 0;
#ifdef FEATURE_RDKB_LED_MANAGER
    virtual INT platform_hal_initLed(CHAR *config_file_name) = 0;
#endif
    virtual INT platform_hal_setLed(PLEDMGMT_PARAMS pValue) = 0;
    virtual INT platform_hal_getLed(PLEDMGMT_PARAMS pValue) = 0;
    virtual UINT platform_hal_getFanSpeed(UINT fanIndex) = 0;
    virtual UINT platform_hal_getRPM(UINT fanIndex) = 0;
    virtual INT platform_hal_getRotorLock(UINT fanIndex) = 0;
    virtual BOOLEAN platform_hal_getFanStatus(UINT fanIndex) = 0;
    virtual INT platform_hal_setFanMaxOverride(BOOLEAN bOverrideFlag, UINT fanIndex) = 0;
#ifdef FEATURE_RDKB_THERMAL_MANAGER
    virtual INT platform_hal_initThermal(THERMAL_PLATFORM_CONFIG *pThermalPlatformConfig) = 0;
    virtual INT platform_hal_LoadThermalConfig(THERMAL_PLATFORM_CONFIG *pThermalPlatformConfig) = 0;
    virtual INT platform_hal_setFanSpeed(UINT fanIndex, FAN_SPEED fanSpeed, FAN_ERR *pErrReason) = 0;
    virtual INT platform_hal_getFanTemperature(INT *pTemp) = 0;
    virtual INT platform_hal_getInputCurrent(INT *pValue) = 0;
    virtual INT platform_hal_getInputPower(INT *pValue) = 0;
    virtual INT platform_hal_getRadioTemperature(INT radioIndex, INT *pValue) = 0;
    virtual INT platform_hal_getEcoModeStatus(INT radioIndex, INT *pValue) = 0;
#endif
    virtual INT platform_hal_SetSNMPOnboardRebootEnable(CHAR *pValue) = 0;
    virtual INT platform_hal_GetMACsecEnable(INT ethPort, BOOLEAN *pFlag) = 0;
    virtual INT platform_hal_SetMACsecEnable(INT ethPort, BOOLEAN flag) = 0;
    virtual INT platform_hal_GetMACsecOperationalStatus(INT ethPort, BOOLEAN *pFlag) = 0;
    virtual INT platform_hal_StartMACsec(INT ethPort, INT timeoutSec) = 0;
    virtual INT platform_hal_StopMACsec(INT ethPort) = 0;
    virtual INT platform_hal_GetMemoryPaths(RDK_CPUS index, PPLAT_PROC_MEM_INFO *ppinfo) = 0;
    virtual INT platform_hal_GetDhcpv4_Options(dhcp_opt_list **req_opt_list, dhcp_opt_list **send_opt_list) = 0;
    virtual INT platform_hal_GetDhcpv6_Options(dhcp_opt_list **req_opt_list, dhcp_opt_list **send_opt_list) = 0;
    virtual INT platform_hal_SetLowPowerModeState(PPSM_STATE pState) = 0;
    virtual INT platform_hal_getCMTSMac(CHAR *pValue) = 0;
    virtual INT platform_hal_setDscp(WAN_INTERFACE interfaceType, TRAFFIC_CNT_COMMAND cmd, CHAR *pDscpVals) = 0;
    virtual INT platform_hal_resetDscpCounts(WAN_INTERFACE interfaceType) = 0;
    virtual INT platform_hal_getDscpClientList(WAN_INTERFACE interfaceType, pDSCP_list_t pDSCP_List) = 0;
    virtual INT platform_hal_GetCPUSpeed(CHAR *cpuSpeed) = 0;
    virtual INT platform_hal_GetFirmwareBankInfo(FW_BANK bankIndex, PFW_BANK_INFO pFW_Bankinfo) = 0;
    virtual INT platform_hal_GetInterfaceStats(const CHAR *ifname, PINTF_STATS pIntfStats) = 0;
};

class PlatformHalMock : public PlatformHalInterface
{
public:
    virtual ~PlatformHalMock() {}
    MOCK_METHOD1(platform_hal_GetDeviceConfigStatus, INT(CHAR *));
    MOCK_METHOD1(platform_hal_GetTelnetEnable, INT(BOOLEAN *));
    MOCK_METHOD1(platform_hal_SetTelnetEnable, INT(BOOLEAN));
    MOCK_METHOD1(platform_hal_GetSSHEnable, INT(BOOLEAN *));
    MOCK_METHOD1(platform_hal_SetSSHEnable, INT(BOOLEAN));
    MOCK_METHOD1(platform_hal_GetSNMPEnable, INT(CHAR *));
    MOCK_METHOD1(platform_hal_SetSNMPEnable, INT(CHAR *));
    MOCK_METHOD1(platform_hal_GetWebUITimeout, INT(ULONG *));
    MOCK_METHOD1(platform_hal_SetWebUITimeout, INT(ULONG));
    MOCK_METHOD3(platform_hal_GetWebAccessLevel, INT(INT, INT, ULONG *));
    MOCK_METHOD3(platform_hal_SetWebAccessLevel, INT(INT, INT, ULONG));
    MOCK_METHOD0(platform_hal_PandMDBInit, INT(void));
    MOCK_METHOD0(platform_hal_DocsisParamsDBInit, INT(void));
    MOCK_METHOD1(platform_hal_GetModelName, INT(CHAR *));
    MOCK_METHOD1(platform_hal_GetRouterRegion, INT(CHAR *));
    MOCK_METHOD1(platform_hal_GetSerialNumber, INT(CHAR *));
    MOCK_METHOD1(platform_hal_GetHardwareVersion, INT(CHAR *));
    MOCK_METHOD2(platform_hal_GetSoftwareVersion, INT(CHAR*, ULONG));
    MOCK_METHOD2(platform_hal_GetBootloaderVersion, INT(CHAR*, ULONG));
    MOCK_METHOD2(platform_hal_GetFirmwareName, INT(CHAR*, ULONG));
    MOCK_METHOD1(platform_hal_GetBaseMacAddress, INT(CHAR *));
    MOCK_METHOD1(platform_hal_GetHardware, INT(CHAR *));
    MOCK_METHOD1(platform_hal_GetHardware_MemUsed, INT(CHAR *));
    MOCK_METHOD1(platform_hal_GetHardware_MemFree, INT(CHAR *));
    MOCK_METHOD1(platform_hal_GetTotalMemorySize, INT(ULONG *));
    MOCK_METHOD1(platform_hal_GetUsedMemorySize, INT(ULONG *));
    MOCK_METHOD1(platform_hal_GetFreeMemorySize, INT(ULONG *));
    MOCK_METHOD1(platform_hal_GetFactoryResetCount, INT(ULONG *));
    MOCK_METHOD1(platform_hal_ClearResetCount, INT(BOOLEAN));
    MOCK_METHOD1(platform_hal_getTimeOffSet, INT(CHAR *));
    MOCK_METHOD1(platform_hal_SetDeviceCodeImageTimeout, INT(INT));
    MOCK_METHOD1(platform_hal_SetDeviceCodeImageValid, INT(BOOLEAN));
    MOCK_METHOD1(platform_hal_getFactoryPartnerId, INT(CHAR *));
    MOCK_METHOD1(platform_hal_getFactoryCmVariant, INT(CHAR *));
    MOCK_METHOD1(platform_hal_setFactoryCmVariant, INT(CHAR *));
#ifdef FEATURE_RDKB_LED_MANAGER
    MOCK_METHOD1(platform_hal_initLed, INT(CHAR *));
#endif
    MOCK_METHOD1(platform_hal_setLed, INT(PLEDMGMT_PARAMS));
    MOCK_METHOD1(platform_hal_getLed, INT(PLEDMGMT_PARAMS));
    MOCK_METHOD1(platform_hal_getFanSpeed, UINT(UINT));
    MOCK_METHOD1(platform_hal_getRPM, UINT(UINT));
    MOCK_METHOD1(platform_hal_getRotorLock, INT(UINT));
    MOCK_METHOD1(platform_hal_getFanStatus, BOOLEAN(UINT));
    MOCK_METHOD2(platform_hal_setFanMaxOverride, INT(BOOLEAN, UINT));
#ifdef FEATURE_RDKB_THERMAL_MANAGER
    MOCK_METHOD1(platform_hal_initThermal, INT(THERMAL_PLATFORM_CONFIG *));
    MOCK_METHOD1(platform_hal_LoadThermalConfig, INT(THERMAL_PLATFORM_CONFIG *));
    MOCK_METHOD3(platform_hal_setFanSpeed, INT(UINT, FAN_SPEED, FAN_ERR *));
    MOCK_METHOD1(platform_hal_getFanTemperature, INT(INT *));
    MOCK_METHOD1(platform_hal_getInputCurrent, INT(INT *));
    MOCK_METHOD1(platform_hal_getInputPower, INT(INT *));
    MOCK_METHOD2(platform_hal_getRadioTemperature, INT(INT, INT *));
    MOCK_METHOD2(platform_hal_getEcoModeStatus, INT(INT, INT *));
#endif
    MOCK_METHOD1(platform_hal_SetSNMPOnboardRebootEnable, INT(CHAR *));
    MOCK_METHOD2(platform_hal_GetMACsecEnable, INT(INT, BOOLEAN *));
    MOCK_METHOD2(platform_hal_SetMACsecEnable, INT(INT, BOOLEAN));
    MOCK_METHOD2(platform_hal_GetMACsecOperationalStatus, INT(INT, BOOLEAN *));
    MOCK_METHOD2(platform_hal_StartMACsec, INT(INT, INT));
    MOCK_METHOD1(platform_hal_StopMACsec, INT(INT));
    MOCK_METHOD2(platform_hal_GetMemoryPaths, INT(RDK_CPUS, PPLAT_PROC_MEM_INFO *));
    MOCK_METHOD2(platform_hal_GetDhcpv4_Options, INT(dhcp_opt_list **, dhcp_opt_list **));
    MOCK_METHOD2(platform_hal_GetDhcpv6_Options, INT(dhcp_opt_list **, dhcp_opt_list **));
    MOCK_METHOD1(platform_hal_SetLowPowerModeState, INT(PPSM_STATE));
    MOCK_METHOD1(platform_hal_getCMTSMac, INT(CHAR *));
    MOCK_METHOD3(platform_hal_setDscp, INT(WAN_INTERFACE, TRAFFIC_CNT_COMMAND, CHAR *));
    MOCK_METHOD1(platform_hal_resetDscpCounts, INT(WAN_INTERFACE));
    MOCK_METHOD2(platform_hal_getDscpClientList, INT(WAN_INTERFACE, pDSCP_list_t));
    MOCK_METHOD1(platform_hal_GetCPUSpeed, INT(CHAR *));
    MOCK_METHOD2(platform_hal_GetFirmwareBankInfo, INT(FW_BANK, PFW_BANK_INFO));
    MOCK_METHOD2(platform_hal_GetInterfaceStats, INT(const CHAR *, PINTF_STATS));
};

#endif // MOCK_PLATFORM_HAL_H