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

#ifndef MOCK_MOCA_HAL_H
#define MOCK_MOCA_HAL_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {
#include "moca_hal.h"
}

class MocaHalInterface
{
public:
    virtual ~MocaHalInterface() {}
    virtual void moca_associatedDevice_callback_register(moca_associatedDevice_callback callback_proc) = 0;
    virtual INT moca_GetIfConfig(ULONG ifIndex, moca_cfg_t *pmoca_config) = 0;
    virtual INT moca_SetIfConfig(ULONG ifIndex, moca_cfg_t *pmoca_config) = 0;
    virtual INT moca_IfGetDynamicInfo(ULONG ifIndex, moca_dynamic_info_t *pmoca_dynamic_info) = 0;
    virtual INT moca_IfGetStaticInfo(ULONG ifIndex, moca_static_info_t *pmoca_static_info) = 0;
    virtual INT moca_IfGetStats(ULONG ifIndex, moca_stats_t *pmoca_stats) = 0;
    virtual INT moca_GetNumAssociatedDevices(ULONG ifIndex, ULONG *pulCount) = 0;
    virtual INT moca_IfGetExtCounter(ULONG ifIndex, moca_mac_counters_t *pmoca_mac_counters) = 0;
    virtual INT moca_IfGetExtAggrCounter(ULONG ifIndex, moca_aggregate_counters_t *pmoca_aggregate_counts) = 0;
    virtual INT moca_GetMocaCPEs(ULONG ifIndex, moca_cpe_t *cpes, INT *pnum_cpes) = 0;
    virtual INT moca_GetAssociatedDevices(ULONG ifIndex, moca_associated_device_t **ppdevice_array) = 0;
    virtual INT moca_FreqMaskToValue(UCHAR *mask) = 0;
    virtual BOOL moca_HardwareEquipped(void) = 0;
#ifndef MOCA_VAR
    virtual INT moca_GetFullMeshRates(ULONG ifIndex, moca_mesh_table_t *pDeviceArray, ULONG *pulCount) = 0;
#endif
    virtual INT moca_GetFlowStatistics(ULONG ifIndex, moca_flow_table_t *pDeviceArray, ULONG *pulCount) = 0;
    virtual INT moca_GetResetCount(ULONG *resetcnt) = 0;
    virtual int moca_setIfAcaConfig(int interfaceIndex, moca_aca_cfg_t acaCfg) = 0;
    virtual int moca_getIfAcaConfig(int interfaceIndex, moca_aca_cfg_t *acaCfg) = 0;
    virtual int moca_cancelIfAca(int interfaceIndex) = 0;
    virtual int moca_getIfAcaStatus(int interfaceIndex, moca_aca_stat_t *pacaStat) = 0;
    virtual int moca_getIfScmod(int interfaceIndex, int *pnumOfEntries, moca_scmod_stat_t **ppscmodStat) = 0;
};

class MocaHalMock : public MocaHalInterface
{
public:
    virtual ~MocaHalMock() {}
    MOCK_METHOD1(moca_associatedDevice_callback_register, void(moca_associatedDevice_callback));
    MOCK_METHOD2(moca_GetIfConfig, INT(ULONG, moca_cfg_t *));
    MOCK_METHOD2(moca_SetIfConfig, INT(ULONG, moca_cfg_t *));
    MOCK_METHOD2(moca_IfGetDynamicInfo, INT(ULONG, moca_dynamic_info_t *));
    MOCK_METHOD2(moca_IfGetStaticInfo, INT(ULONG, moca_static_info_t *));
    MOCK_METHOD2(moca_IfGetStats, INT(ULONG, moca_stats_t *));
    MOCK_METHOD2(moca_GetNumAssociatedDevices, INT(ULONG, ULONG *));
    MOCK_METHOD2(moca_IfGetExtCounter, INT(ULONG, moca_mac_counters_t *));
    MOCK_METHOD2(moca_IfGetExtAggrCounter, INT(ULONG, moca_aggregate_counters_t *));
    MOCK_METHOD3(moca_GetMocaCPEs, INT(ULONG, moca_cpe_t *, INT *));
    MOCK_METHOD2(moca_GetAssociatedDevices, INT(ULONG, moca_associated_device_t **));
    MOCK_METHOD1(moca_FreqMaskToValue, INT(UCHAR *));
    MOCK_METHOD0(moca_HardwareEquipped, BOOL());
#ifndef MOCA_VAR
    MOCK_METHOD3(moca_GetFullMeshRates, INT(ULONG, moca_mesh_table_t *, ULONG *));
#endif
    MOCK_METHOD3(moca_GetFlowStatistics, INT(ULONG, moca_flow_table_t *, ULONG *));
    MOCK_METHOD1(moca_GetResetCount, INT(ULONG *));
    MOCK_METHOD2(moca_setIfAcaConfig, int(int, moca_aca_cfg_t));
    MOCK_METHOD2(moca_getIfAcaConfig, int(int, moca_aca_cfg_t *));
    MOCK_METHOD1(moca_cancelIfAca, int(int));
    MOCK_METHOD2(moca_getIfAcaStatus, int(int, moca_aca_stat_t *));
    MOCK_METHOD3(moca_getIfScmod, int(int, int *, moca_scmod_stat_t **));
};

#endif // MOCK_MOCA_HAL_H