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
#include "mock_ethsw_hal.h"

extern EthSwHalMock *g_ethSwHALMock;

extern "C" INT CcspHalEthSwInit(void)
{
    if (!g_ethSwHALMock)
    {
        return 0;
    }
    return g_ethSwHALMock->CcspHalEthSwInit();
}

extern "C" INT CcspHalEthSwGetPortStatus(CCSP_HAL_ETHSW_PORT PortId, PCCSP_HAL_ETHSW_LINK_RATE pLinkRate, PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode, PCCSP_HAL_ETHSW_LINK_STATUS pStatus)
{
    if (!g_ethSwHALMock)
    {
        return 0;
    }
    return g_ethSwHALMock->CcspHalEthSwGetPortStatus(PortId, pLinkRate, pDuplexMode, pStatus);
}

extern "C" INT CcspHalEthSwGetPortCfg(CCSP_HAL_ETHSW_PORT PortId, PCCSP_HAL_ETHSW_LINK_RATE pLinkRate, PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode)
{
    if (!g_ethSwHALMock)
    {
        return 0;
    }
    return g_ethSwHALMock->CcspHalEthSwGetPortCfg(PortId, pLinkRate, pDuplexMode);
}

extern "C" INT CcspHalEthSwSetPortCfg(CCSP_HAL_ETHSW_PORT PortId, CCSP_HAL_ETHSW_LINK_RATE LinkRate, CCSP_HAL_ETHSW_DUPLEX_MODE DuplexMode)
{
    if (!g_ethSwHALMock)
    {
        return 0;
    }
    return g_ethSwHALMock->CcspHalEthSwSetPortCfg(PortId, LinkRate, DuplexMode);
}

extern "C" INT CcspHalEthSwGetPortAdminStatus(CCSP_HAL_ETHSW_PORT PortId, PCCSP_HAL_ETHSW_ADMIN_STATUS pAdminStatus)
{
    if (!g_ethSwHALMock)
    {
        return 0;
    }
    return g_ethSwHALMock->CcspHalEthSwGetPortAdminStatus(PortId, pAdminStatus);
}

extern "C" INT CcspHalEthSwSetPortAdminStatus(CCSP_HAL_ETHSW_PORT PortId, CCSP_HAL_ETHSW_ADMIN_STATUS AdminStatus)
{
    if (!g_ethSwHALMock)
    {
        return 0;
    }
    return g_ethSwHALMock->CcspHalEthSwSetPortAdminStatus(PortId, AdminStatus);
}

extern "C" INT CcspHalEthSwSetAgingSpeed(CCSP_HAL_ETHSW_PORT PortId, INT AgingSpeed)
{
    if (!g_ethSwHALMock)
    {
        return 0;
    }
    return g_ethSwHALMock->CcspHalEthSwSetAgingSpeed(PortId, AgingSpeed);
}

extern "C" INT CcspHalEthSwLocatePortByMacAddress(unsigned char* mac, INT* port)
{
    if (!g_ethSwHALMock)
    {
        return 0;
    }
    return g_ethSwHALMock->CcspHalEthSwLocatePortByMacAddress(mac, port);
}

extern "C" INT CcspHalExtSw_getAssociatedDevice(ULONG* output_array_size, eth_device_t** output_struct)
{
    if (!g_ethSwHALMock)
    {
        return 0;
    }
    return g_ethSwHALMock->CcspHalExtSw_getAssociatedDevice(output_array_size, output_struct);
}

extern "C" void CcspHalExtSw_ethAssociatedDevice_callback_register(CcspHalExtSw_ethAssociatedDevice_callback callback_proc)
{
    if (!g_ethSwHALMock)
    {
        return;
    }
    g_ethSwHALMock->CcspHalExtSw_ethAssociatedDevice_callback_register(callback_proc);
}

extern "C" int CcspHalExtSw_ethPortConfigure(char* ifname, BOOLEAN WanMode)
{
    if (!g_ethSwHALMock)
    {
        return 0;
    }
    return g_ethSwHALMock->CcspHalExtSw_ethPortConfigure(ifname, WanMode);
}

extern "C" INT CcspHalExtSw_getEthWanEnable(BOOLEAN* pFlag)
{
    if (!g_ethSwHALMock)
    {
        return 0;
    }
    return g_ethSwHALMock->CcspHalExtSw_getEthWanEnable(pFlag);
}

extern "C" INT CcspHalExtSw_setEthWanEnable(BOOLEAN Flag)
{
    if (!g_ethSwHALMock)
    {
        return 0;
    }
    return g_ethSwHALMock->CcspHalExtSw_setEthWanEnable(Flag);
}

extern "C" BOOLEAN CcspHalExtSw_getCurrentWanHWConf()
{
    if (!g_ethSwHALMock)
    {
        return FALSE;
    }
    return g_ethSwHALMock->CcspHalExtSw_getCurrentWanHWConf();
}

extern "C" INT CcspHalExtSw_getEthWanPort(UINT* pPort)
{
    if (!g_ethSwHALMock)
    {
        return 0;
    }
    return g_ethSwHALMock->CcspHalExtSw_getEthWanPort(pPort);
}

extern "C" INT CcspHalExtSw_setEthWanPort(UINT Port)
{
    if (!g_ethSwHALMock)
    {
        return 0;
    }
    return g_ethSwHALMock->CcspHalExtSw_setEthWanPort(Port);
}

extern "C" INT CcspHalEthSwGetEthPortStats(CCSP_HAL_ETHSW_PORT PortId, PCCSP_HAL_ETH_STATS pStats)
{
    if (!g_ethSwHALMock)
    {
        return 0;
    }
    return g_ethSwHALMock->CcspHalEthSwGetEthPortStats(PortId, pStats);
}

extern "C" void GWP_RegisterEthWan_Callback(appCallBack* obj)
{
    if (!g_ethSwHALMock)
    {
        return;
    }
    g_ethSwHALMock->GWP_RegisterEthWan_Callback(obj);
}

extern "C" INT GWP_GetEthWanLinkStatus()
{
    if (!g_ethSwHALMock)
    {
        return 0;
    }
    return g_ethSwHALMock->GWP_GetEthWanLinkStatus();
}

extern "C" INT GWP_GetEthWanInterfaceName(unsigned char* Interface, ULONG maxSize)
{
    if (!g_ethSwHALMock)
    {
        return 0;
    }
    return g_ethSwHALMock->GWP_GetEthWanInterfaceName(Interface, maxSize);
}