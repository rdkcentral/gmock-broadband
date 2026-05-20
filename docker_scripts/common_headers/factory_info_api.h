/*
 * factory_info_api.h - Stub header for Coverity/native builds
 *
 * factory_info_api.h ships with the Technicolor factory-nvram platform SDK
 * and is not available in any public repository. This stub provides the
 * minimal declarations required to compile persistent-storage-manager in a
 * native/Coverity build environment where the real SDK is not present.
 *
 * Only the symbols actually referenced by this component are declared here.
 */

#ifndef _FACTORY_INFO_API_H_
#define _FACTORY_INFO_API_H_

int factory_info_get_default_24_SSID(char *outputData);
int factory_info_get_default_50_SSID(char *outputData);
int factory_info_get_default_60_SSID(char *outputData);
int factory_info_get_default_xhs_SSID(char *outputData);
int factory_info_get_wifi_passwd(char *outputData);
int factory_info_get_xhs_passkey(char *outputData);

#endif /* _FACTORY_INFO_API_H_ */
