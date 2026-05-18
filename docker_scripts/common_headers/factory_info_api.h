/********** COPYRIGHT AND CONFIDENTIALITY INFORMATION NOTICE *************
** Copyright (c) 2017
** - Technicolor Connected Home USA, LLC
** - All Rights Reserved
** Technicolor hereby informs you that certain portions
** of this software module and/or Work are owned by Technicolor
** and/or its software providers.
** Distribution copying and modification of all such work are reserved
** to Technicolor and/or its affiliates, and are not permitted without
** express written authorization from Technicolor.
** Technicolor is registered trademark and trade name of Technicolor,
** and shall not be used in any manner without express written
** authorization from Technicolor
*************************************************************************/
#ifndef _FACTORY_INFO_API_H_

#define _FACTORY_INFO_API_H_

#include <stddef.h>
#include <stdint.h>
#include <unistd.h>

#define FACTORY_INFO_API_VERSION 4

/** Resulting MD5 hash values are 128 bits */
typedef unsigned char SaMd5_Hash[16];

typedef enum {
    MAC_CM = 0,
    MAC_EMTA,
    MAC_RG_WAN,
    MAC_RG_DATA,
    MAC_WIFI_BASE,
    MAC_MOCA,
    MAC_BLUETOOTH,
    MAC_ZIGBEE,
    MAC_THREAD,
    MAX_MAC_INFO
} MAC_INFO;
#define LEASE_MAC_INFO_LEN 18

typedef enum {
    PRO_MANUFACTURE_DATE = 0,
    PRO_HARDMODEL,
    PRO_SERIALNUMBER,
    PRO_HARD_VERSION,
    PRO_BOARD_VERSION,
    MAX_PRODUCT_INFO
} PRODUCT_INFO;

typedef enum
{
    MTD_BOOT = 0,
    MMC_BOOT
} BOOT_FLASH;

#define LEASE_PRO_INFO_LEN 32

#define FACTORY_INFO_SUCCESS 0
#define FACTORY_INFO_FAIL (-1)
#define FACTORY_INFO_INVALD_PARAM (-2)
#define FACTORY_INFO_INVALD_FACTORY_DATA (-3)
#define FACTORY_INFO_UNKNOWN_PARTITION      (-4)

#define MAX_PARTITION_NAME_LEN 50
#define DEFAULT_FACTORY_INFO_PARTITION_NAME "flash0.macadr"
#define TCH_FACTORY_INFO_PARTITION_NAME "flash0.FactoryData"
#define TCH_FACTORY_INFO_MMC_PARTITION_FILE   "/mnt/factory_data/FactoryData"

// This enumerator is used to hold the Customer codes
typedef enum {
    eUnprogrammed = 0,
    eComcast,
    eCharter,
    eCox,
    eRogers,
    eVodafone,
    eShaw,
    eVideotron,
    eMaxCustCode = eVideotron
} eCustomerCode;

typedef enum {

//    Unprogrammed = 0,
    pc20 = 1,
    pc20genband,
    pc15sip,
    pc15mgcp
}eCm_varient;

#define MAX_LEGAL_CM_CODE 4
#define PROCFS_CM_CODE                                                   \
    "/proc/device-tree/chosen/trusted/socinfo/CmCode"

#define PROCFS_CUSTOMER_CODE                                                   \
    "/proc/device-tree/chosen/trusted/socinfo/CustomerCode"

/******************************************************************************
partition : the partition name of factory data
            if partition is NULL , it will use
DEFAULT_FACTORY_INFO_PARTITION_NAME

return : FACTORY_INFO_SUCCESS when init sucessfully
******************************************************************************/
int factory_info_initialized(const char *partition);
int factory_info_initialized_emmc(const char *partition);

/******************************************************************************
index : indicate which mac info will be read
outputData : output MAC string by format 99:AA:BB:CC:DD:EE
len : the length of outputData

return : FACTORY_INFO_SUCCESS when get sucessfully
*******************************************************************************/
int factory_info_get_mac(MAC_INFO index, char *outputData, int len);

/******************************************************************************
index : BSSID Index (0-15)
outputData : uint8_t
len : the length of outputData

return : FACTORY_INFO_SUCCESS when get sucessfully
*******************************************************************************/
int factory_info_get_bssid_mac(int index, uint8_t *p_output);

/******************************************************************************
outputData : output string which include the wifi password
len : the length of outputData

return : FACTORY_INFO_SUCCESS when get sucessfully
*******************************************************************************/
int factory_info_get_wifi_passwd(char *outputData);

/******************************************************************************
hash : ptr to hash of the wifi password

return : FACTORY_INFO_SUCCESS when get successfully
*******************************************************************************/
int factory_info_get_wifi_passwd_hash(SaMd5_Hash *hash);

/******************************************************************************
outputData : output string which include the xhs passkey
len : the length of outputData

return : FACTORY_INFO_SUCCESS when get sucessfully
*******************************************************************************/
int factory_info_get_xhs_passkey(char *outputData);
/******************************************************************************
hash : ptr to hash of the xhs passkey

return : FACTORY_INFO_SUCCESS when get sucessfully
*******************************************************************************/
int factory_info_get_xhs_passkey_hash(SaMd5_Hash *hash);

/******************************************************************************
outputData : output string which include the default XHS SSID (XHS SSID is same
for 2.4GHz and 5.0GHz)
len : the length of outputData

return : FACTORY_INFO_SUCCESS when get sucessfully
*******************************************************************************/
int factory_info_get_default_xhs_SSID(char *outputData);

/******************************************************************************
outputData : output string which include the default 2.4GHz SSID
len : the length of outputData

return : FACTORY_INFO_SUCCESS when get sucessfully
*******************************************************************************/
int factory_info_get_default_24_SSID(char *outputData);

/******************************************************************************
outputData : output string which include the wps pin
len : the length of outputData

return : FACTORY_INFO_SUCCESS when get sucessfully
*******************************************************************************/
int factory_info_get_wps_pin(char *outputData);

/******************************************************************************
hash : ptr to hash of the wps pin

return : FACTORY_INFO_SUCCESS when get successfully
*******************************************************************************/
int factory_info_get_wps_pin_hash(SaMd5_Hash *hash);

/******************************************************************************
index : indicate which product info will be read
outputData : the string of product infor
len : the length of outputData

return : FACTORY_INFO_SUCCESS when get sucessfully
******************************************************************************/

int factory_info_get_product_info(PRODUCT_INFO index, char *outputData,
                                  int len);

typedef enum {
    PLAT_BT_VER = 0,
    PLAT_FW_NAME,
    PLAT_FW_VER,
    /*
     for nand & nor flash size , it will result the size by MegaByte unit
    */
    PLAT_FLASH_NAND_SIZE,
    PLAT_FLASH_NOR_SIZE,
    MAX_PLAT_INFO
} PLAT_INFO;

#define PLAT_INFO_SUCCESS 0
#define PLAT_INFO_FAIL (-1)
/******************************************************************************
index : indicate which platform info will be read
outputData : the string of platform info
len : the length of outputData

return : PLAT_INFO_SUCCESS when get sucessfully
******************************************************************************/
int platform_get_platform_info(PLAT_INFO index, char *outputData, int len);

/******************************************************************************
outputData : None

return : the factory id  when successful or  FACTORY_INFO_INVALD_FACTORY_DATA
*******************************************************************************/
int factory_info_get_factory_id(void);

/******************************************************************************
outputData : None

return : the Customer code when successful or FACTORY_INFO_INVALD_FACTORY_DATA
*******************************************************************************/
int factory_info_get_otp_code(void);
/******************************************************************************
outputData : output string which include the Customer Name
len : the length of outputData

return : FACTORY_INFO_SUCCESS when get sucessfully
*******************************************************************************/
int factory_info_get_partner_id(char *outputData);

/******************************************************************************
outputData : output string which include the Customer Name

return : FACTORY_INFO_SUCCESS when get sucessfully
*******************************************************************************/
int factory_info_set_partner_id(char *outputData);

/******************************************************************************
outputData : None

return : FACTORY_INFO_SUCCESS when get sucessfully
*******************************************************************************/
int factory_info_reset_partner_id();

/******************************************************************************
outputData : output string which include the Cm variant Name
len : the length of outputData

return : FACTORY_INFO_SUCCESS when get sucessfully
*******************************************************************************/
int factory_info_get_Cm_variant(char *outputData);

/******************************************************************************
outputData : output string which include the Cm variant Name

return : FACTORY_INFO_SUCCESS when get sucessfully
*******************************************************************************/
int factory_info_set_Cm_variant(char *inputData);

#endif