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

#include "mock_moca_hal.h"

extern MocaHalMock *g_mocaHALMock;

extern "C" void moca_associatedDevice_callback_register(moca_associatedDevice_callback callback_proc)
{
    if (!g_mocaHALMock)
    {
        return;
    }
    g_mocaHALMock->moca_associatedDevice_callback_register(callback_proc);
}

extern "C" INT moca_GetIfConfig(ULONG ifIndex, moca_cfg_t *pmoca_config)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_GetIfConfig(ifIndex, pmoca_config);
}

extern "C" INT moca_SetIfConfig(ULONG ifIndex, moca_cfg_t *pmoca_config)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_SetIfConfig(ifIndex, pmoca_config);
}

extern "C" INT moca_IfGetDynamicInfo(ULONG ifIndex, moca_dynamic_info_t *pmoca_dynamic_info)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_IfGetDynamicInfo(ifIndex, pmoca_dynamic_info);
}

extern "C" INT moca_IfGetStaticInfo(ULONG ifIndex, moca_static_info_t *pmoca_static_info)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_IfGetStaticInfo(ifIndex, pmoca_static_info);
}

extern "C" INT moca_IfGetStats(ULONG ifIndex, moca_stats_t *pmoca_stats)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_IfGetStats(ifIndex, pmoca_stats);
}

extern "C" INT moca_GetNumAssociatedDevices(ULONG ifIndex, ULONG *pulCount)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_GetNumAssociatedDevices(ifIndex, pulCount);
}

extern "C" INT moca_IfGetExtCounter(ULONG ifIndex, moca_mac_counters_t *pmoca_mac_counters)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_IfGetExtCounter(ifIndex, pmoca_mac_counters);
}

extern "C" INT moca_IfGetExtAggrCounter(ULONG ifIndex, moca_aggregate_counters_t *pmoca_aggregate_counts)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_IfGetExtAggrCounter(ifIndex, pmoca_aggregate_counts);
}

extern "C" INT moca_GetMocaCPEs(ULONG ifIndex, moca_cpe_t *cpes, INT *pnum_cpes)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_GetMocaCPEs(ifIndex, cpes, pnum_cpes);
}

extern "C" INT moca_GetAssociatedDevices(ULONG ifIndex, moca_associated_device_t **ppdevice_array)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_GetAssociatedDevices(ifIndex, ppdevice_array);
}

extern "C" INT moca_FreqMaskToValue(UCHAR *mask)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_FreqMaskToValue(mask);
}

extern "C" BOOL moca_HardwareEquipped(void)
{
    if (!g_mocaHALMock)
    {
        return FALSE;
    }
    return g_mocaHALMock->moca_HardwareEquipped();
}

#ifndef MOCA_VAR
extern "C" INT moca_GetFullMeshRates(ULONG ifIndex, moca_mesh_table_t *pDeviceArray, ULONG *pulCount)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_GetFullMeshRates(ifIndex, pDeviceArray, pulCount);
}
#endif

extern "C" INT moca_GetFlowStatistics(ULONG ifIndex, moca_flow_table_t *pDeviceArray, ULONG *pulCount)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_GetFlowStatistics(ifIndex, pDeviceArray, pulCount);
}

extern "C" INT moca_GetResetCount(ULONG *resetcnt)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_GetResetCount(resetcnt);
}

extern "C" int moca_setIfAcaConfig(int interfaceIndex, moca_aca_cfg_t acaCfg)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_setIfAcaConfig(interfaceIndex, acaCfg);
}

extern "C" int moca_getIfAcaConfig(int interfaceIndex, moca_aca_cfg_t *acaCfg)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_getIfAcaConfig(interfaceIndex, acaCfg);
}

extern "C" int moca_cancelIfAca(int interfaceIndex)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_cancelIfAca(interfaceIndex);
}

extern "C" int moca_getIfAcaStatus(int interfaceIndex, moca_aca_stat_t *pacaStat)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_getIfAcaStatus(interfaceIndex, pacaStat);
}

extern "C" int moca_getIfScmod(int interfaceIndex, int *pnumOfEntries, moca_scmod_stat_t **ppscmodStat)
{
    if (!g_mocaHALMock)
    {
        return 0;
    }
    return g_mocaHALMock->moca_getIfScmod(interfaceIndex, pnumOfEntries, ppscmodStat);
}