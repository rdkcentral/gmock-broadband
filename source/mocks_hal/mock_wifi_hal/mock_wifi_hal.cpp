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

#include "mock_wifi_hal.h"

extern WifiHalMock *g_WifiHalMock;

extern "C" INT wifi_getApEnable(INT apIndex, BOOL *output_bool)
{
    if (!g_WifiHalMock)
    {
        return RETURN_ERR; 
    }
    return g_WifiHalMock->wifi_getApEnable(apIndex, output_bool);
}

extern "C" INT wifi_getBaseBSSID(INT ssidIndex, CHAR *output_string)
{
    if (!g_WifiHalMock)
    {
        return RETURN_ERR;
    }
    return g_WifiHalMock->wifi_getBaseBSSID(ssidIndex, output_string);
}

extern "C" INT wifi_getSSIDRadioIndex(INT ssidIndex, INT *radioIndex)
{
    if (!g_WifiHalMock)
    {
        return RETURN_ERR;
    }
    return g_WifiHalMock->wifi_getSSIDRadioIndex(ssidIndex, radioIndex);
}

extern "C" INT wifi_getRadioChannelsInUse(INT radioIndex, CHAR *output_string)
{
    if (!g_WifiHalMock)
    {
        return RETURN_ERR;
    }
    return g_WifiHalMock->wifi_getRadioChannelsInUse(radioIndex, output_string);
}

extern "C" INT wifi_getRadioChannel(INT radioIndex, ULONG *output_ulong)
{
    if (!g_WifiHalMock)
    {
        return RETURN_ERR;
    }
    return g_WifiHalMock->wifi_getRadioChannel(radioIndex, output_ulong);
}

extern "C" INT wifi_getRadioOperatingFrequencyBand(INT radioIndex, CHAR *output_string)
{
    if (!g_WifiHalMock)
    {
        return RETURN_ERR;
    }
    return g_WifiHalMock->wifi_getRadioOperatingFrequencyBand(radioIndex, output_string);
}

extern "C" INT wifi_getApAssociatedDeviceDiagnosticResult(INT apIndex, wifi_associated_dev_t **associated_dev_array, UINT *output_array_size)
{
    if (!g_WifiHalMock)
    {
        return RETURN_ERR;
    }
    return g_WifiHalMock->wifi_getApAssociatedDeviceDiagnosticResult(apIndex, associated_dev_array, output_array_size);
}

extern "C" INT wifi_getRadioNumberOfEntries(ULONG *output)
{
    if (!g_WifiHalMock)
    {
        return RETURN_ERR;
    }
    return g_WifiHalMock->wifi_getRadioNumberOfEntries(output);
}

extern "C" INT wifi_getSSIDNumberOfEntries(ULONG *output)
{
    if (!g_WifiHalMock)
    {
        return RETURN_ERR;
    }
    return g_WifiHalMock->wifi_getSSIDNumberOfEntries(output);
}

extern "C" INT wifi_getSSIDName(INT apIndex, CHAR *output_string)
{
    if (!g_WifiHalMock)
    {
        return RETURN_ERR;
    }
    return g_WifiHalMock->wifi_getSSIDName(apIndex, output_string);
}

extern "C" INT wifi_getRadioEnable(INT radioIndex, BOOL *output_bool)
{
    if (!g_WifiHalMock)
    {
        return RETURN_ERR;
    }
    return g_WifiHalMock->wifi_getRadioEnable(radioIndex, output_bool);
}

extern "C" INT wifi_getRadioIfName(INT radioIndex, CHAR *output_string)
{
    if (!g_WifiHalMock)
    {
        return RETURN_ERR;
    }
    return g_WifiHalMock->wifi_getRadioIfName(radioIndex, output_string);
}

extern "C" INT wifi_getRadioTrafficStats2(INT radioIndex, wifi_radioTrafficStats2_t *output_struct)
{
    if (!g_WifiHalMock)
    {
        return RETURN_ERR;
    }
    return g_WifiHalMock->wifi_getRadioTrafficStats2(radioIndex, output_struct);
}

extern "C" INT wifi_getNeighboringWiFiDiagnosticResult2(INT radioIndex, wifi_neighbor_ap2_t **neighbor_ap_array, UINT *output_array_size)
{
    if (!g_WifiHalMock)
    {
        return RETURN_ERR;
    }
    return g_WifiHalMock->wifi_getNeighboringWiFiDiagnosticResult2(radioIndex, neighbor_ap_array, output_array_size);
}

extern "C" INT wifi_getRadioOperatingChannelBandwidth(INT radioIndex, CHAR *output_string)
{
    if (!g_WifiHalMock)
    {
        return RETURN_ERR;
    }
    return g_WifiHalMock->wifi_getRadioOperatingChannelBandwidth(radioIndex, output_string);
}