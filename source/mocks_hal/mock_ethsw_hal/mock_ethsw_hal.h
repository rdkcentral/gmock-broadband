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
#ifndef MOCK_ETHSW_HAL_H
#define MOCK_ETHSW_HAL_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {
#include "ccsp_hal_ethsw.h"
}

class EthSwHalInterface
{
public:
    virtual ~EthSwHalInterface() {}
    virtual INT CcspHalEthSwInit(void) = 0;
    virtual INT CcspHalEthSwGetPortStatus(CCSP_HAL_ETHSW_PORT PortId, PCCSP_HAL_ETHSW_LINK_RATE pLinkRate, PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode, PCCSP_HAL_ETHSW_LINK_STATUS pStatus) = 0;
    virtual INT CcspHalEthSwGetPortCfg(CCSP_HAL_ETHSW_PORT PortId, PCCSP_HAL_ETHSW_LINK_RATE pLinkRate, PCCSP_HAL_ETHSW_DUPLEX_MODE pDuplexMode) = 0;
    virtual INT CcspHalEthSwSetPortCfg(CCSP_HAL_ETHSW_PORT PortId, CCSP_HAL_ETHSW_LINK_RATE LinkRate, CCSP_HAL_ETHSW_DUPLEX_MODE DuplexMode) = 0;
    virtual INT CcspHalEthSwGetPortAdminStatus(CCSP_HAL_ETHSW_PORT PortId, PCCSP_HAL_ETHSW_ADMIN_STATUS pAdminStatus) = 0;
    virtual INT CcspHalEthSwSetPortAdminStatus(CCSP_HAL_ETHSW_PORT PortId, CCSP_HAL_ETHSW_ADMIN_STATUS AdminStatus) = 0;
    virtual INT CcspHalEthSwSetAgingSpeed(CCSP_HAL_ETHSW_PORT PortId, INT AgingSpeed) = 0;
    virtual INT CcspHalEthSwLocatePortByMacAddress(unsigned char* mac, INT* port) = 0;
    virtual INT CcspHalExtSw_getAssociatedDevice(ULONG* output_array_size, eth_device_t** output_struct) = 0;
    virtual void CcspHalExtSw_ethAssociatedDevice_callback_register(CcspHalExtSw_ethAssociatedDevice_callback callback_proc) = 0;
    virtual int CcspHalExtSw_ethPortConfigure(char* ifname, BOOLEAN WanMode) = 0;
    virtual INT CcspHalExtSw_getEthWanEnable(BOOLEAN* pFlag) = 0;
    virtual INT CcspHalExtSw_setEthWanEnable(BOOLEAN Flag) = 0;
    virtual BOOLEAN CcspHalExtSw_getCurrentWanHWConf() = 0;
    virtual INT CcspHalExtSw_getEthWanPort(UINT* pPort) = 0;
    virtual INT CcspHalExtSw_setEthWanPort(UINT Port) = 0;
    virtual INT CcspHalEthSwGetEthPortStats(CCSP_HAL_ETHSW_PORT PortId, PCCSP_HAL_ETH_STATS pStats) = 0;
    virtual void GWP_RegisterEthWan_Callback(appCallBack* obj) = 0;
    virtual INT GWP_GetEthWanLinkStatus() = 0;
    virtual INT GWP_GetEthWanInterfaceName(unsigned char* Interface, ULONG maxSize) = 0;
};

class EthSwHalMock : public EthSwHalInterface
{
public:
    virtual ~EthSwHalMock() {}
    MOCK_METHOD0(CcspHalEthSwInit, INT());
    MOCK_METHOD4(CcspHalEthSwGetPortStatus, INT(CCSP_HAL_ETHSW_PORT, PCCSP_HAL_ETHSW_LINK_RATE, PCCSP_HAL_ETHSW_DUPLEX_MODE, PCCSP_HAL_ETHSW_LINK_STATUS));
    MOCK_METHOD3(CcspHalEthSwGetPortCfg, INT(CCSP_HAL_ETHSW_PORT, PCCSP_HAL_ETHSW_LINK_RATE, PCCSP_HAL_ETHSW_DUPLEX_MODE));
    MOCK_METHOD3(CcspHalEthSwSetPortCfg, INT(CCSP_HAL_ETHSW_PORT, CCSP_HAL_ETHSW_LINK_RATE, CCSP_HAL_ETHSW_DUPLEX_MODE));
    MOCK_METHOD2(CcspHalEthSwGetPortAdminStatus, INT(CCSP_HAL_ETHSW_PORT, PCCSP_HAL_ETHSW_ADMIN_STATUS));
    MOCK_METHOD2(CcspHalEthSwSetPortAdminStatus, INT(CCSP_HAL_ETHSW_PORT, CCSP_HAL_ETHSW_ADMIN_STATUS));
    MOCK_METHOD2(CcspHalEthSwSetAgingSpeed, INT(CCSP_HAL_ETHSW_PORT, INT));
    MOCK_METHOD2(CcspHalEthSwLocatePortByMacAddress, INT(unsigned char*, INT*));
    MOCK_METHOD2(CcspHalExtSw_getAssociatedDevice, INT(ULONG*, eth_device_t**));
    MOCK_METHOD1(CcspHalExtSw_ethAssociatedDevice_callback_register, void(CcspHalExtSw_ethAssociatedDevice_callback));   
    MOCK_METHOD2(CcspHalExtSw_ethPortConfigure, int(char*, BOOLEAN));   
    MOCK_METHOD1(CcspHalExtSw_getEthWanEnable, INT(BOOLEAN*));
    MOCK_METHOD1(CcspHalExtSw_setEthWanEnable, INT(BOOLEAN));
    MOCK_METHOD0(CcspHalExtSw_getCurrentWanHWConf, BOOLEAN()); 
    MOCK_METHOD1(CcspHalExtSw_getEthWanPort, INT(UINT*));
    MOCK_METHOD1(CcspHalExtSw_setEthWanPort, INT(UINT));
    MOCK_METHOD2(CcspHalEthSwGetEthPortStats, INT(CCSP_HAL_ETHSW_PORT, PCCSP_HAL_ETH_STATS));
    MOCK_METHOD1(GWP_RegisterEthWan_Callback, void(appCallBack*));
    MOCK_METHOD0(GWP_GetEthWanLinkStatus, INT());
    MOCK_METHOD2(GWP_GetEthWanInterfaceName, INT(unsigned char*, ULONG));
};

#endif // MOCK_ETHSW_HAL_H