/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:
*
* Copyright 2024 RDK Management
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

#ifndef MOCK_WIFI_HAL_H
#define MOCK_WIFI_HAL_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {
    #include "wifi_hal_generic.h"
    #include "wifi_hal_ap.h"
    #include "wifi_hal_telemetry.h"
}

class WifiHalInterface
{
public:
    virtual ~WifiHalInterface() {}
    virtual INT wifi_getApEnable(INT apIndex, BOOL *output_bool) = 0;
    virtual INT wifi_getBaseBSSID(INT ssidIndex, CHAR *output_string) = 0;
    virtual INT wifi_getSSIDRadioIndex(INT ssidIndex, INT *radioIndex) = 0;
    virtual INT wifi_getRadioChannelsInUse(INT radioIndex, CHAR *output_string) = 0;
    virtual INT wifi_getRadioChannel(INT radioIndex, ULONG *output_ulong) = 0;
    virtual INT wifi_getRadioOperatingFrequencyBand(INT radioIndex, CHAR *output_string) = 0;
    virtual INT wifi_getApAssociatedDeviceDiagnosticResult(INT apIndex, wifi_associated_dev_t **associated_dev_array, UINT *output_array_size) = 0;
    virtual INT wifi_getRadioNumberOfEntries(ULONG *output) = 0;
    virtual INT wifi_getSSIDNumberOfEntries(ULONG *output) = 0;
    virtual INT wifi_getSSIDName(INT apIndex, CHAR *output_string) = 0;
    virtual INT wifi_getRadioEnable(INT radioIndex, BOOL *output_bool) = 0;
    virtual INT wifi_getRadioIfName(INT radioIndex, CHAR *output_string) = 0;
    virtual INT wifi_getRadioTrafficStats2(INT radioIndex, wifi_radioTrafficStats2_t *output_struct) = 0;
    virtual INT wifi_getNeighboringWiFiDiagnosticResult2(INT radioIndex, wifi_neighbor_ap2_t **neighbor_ap_array, UINT *output_array_size) = 0;
    virtual INT wifi_getRadioOperatingChannelBandwidth(INT radioIndex, CHAR *output_string) = 0;
};

class WifiHalMock : public WifiHalInterface
{
public:
    virtual ~WifiHalMock() {}
    MOCK_METHOD2(wifi_getApEnable, INT(INT, BOOL*));
    MOCK_METHOD2(wifi_getBaseBSSID, INT(INT, CHAR*));
    MOCK_METHOD2(wifi_getSSIDRadioIndex, INT(INT, INT*));
    MOCK_METHOD2(wifi_getRadioChannelsInUse, INT(INT, CHAR*));
    MOCK_METHOD2(wifi_getRadioChannel, INT(INT, ULONG*));
    MOCK_METHOD2(wifi_getRadioOperatingFrequencyBand, INT(INT, CHAR*));
    MOCK_METHOD3(wifi_getApAssociatedDeviceDiagnosticResult, INT(INT, wifi_associated_dev_t**, UINT*));
    MOCK_METHOD1(wifi_getRadioNumberOfEntries, INT(ULONG*));
    MOCK_METHOD1(wifi_getSSIDNumberOfEntries, INT(ULONG*));
    MOCK_METHOD2(wifi_getSSIDName, INT(INT, CHAR*));
    MOCK_METHOD2(wifi_getRadioEnable, INT(INT, BOOL*));
    MOCK_METHOD2(wifi_getRadioIfName, INT(INT, CHAR*));
    MOCK_METHOD2(wifi_getRadioTrafficStats2, INT(INT, wifi_radioTrafficStats2_t*));
    MOCK_METHOD3(wifi_getNeighboringWiFiDiagnosticResult2, INT(INT, wifi_neighbor_ap2_t**, UINT*));
    MOCK_METHOD2(wifi_getRadioOperatingChannelBandwidth, INT(INT, CHAR*));
};

#endif // MOCK_WIFI_HAL_H
