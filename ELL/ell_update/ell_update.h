#ifndef _ELL_UPDATE_H
#define _ELL_UPDATE_H

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "kal_general_types.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */

#include "mmi_l3_enums.h"
#include "custom_config_account.h"
#include "cbm_consts.h"
#include "cbm_api.h"
#include "ps_public_enum.h"

#include "l4c2smsal_struct.h"
#include "soc_api.h"

#include "ell_timer.h"
#include "ell_os.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/
#define EBUFFERLENGTH  400*1024 

#define FOTA_FILE_RW_PATH       "TRACK_RW"
#define FOTA_FILE_RO_PATH       "TRACK_RO"
#define FOTA_FILE_NVRAM_PATH    "TRACK_NVRAM"

#define FOTA_FILE_PATH          "TRACK.BIN"
#define FOTA_MD5_FILE_PATH      "TRACK.MD5"

/* 有自动添加函数名 */
#define EllLog(fmt, args...) EllLog2(__func__, fmt, ##args)

#define EllHex(buff, size) EllHex2(__func__, buff, size) 

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/
typedef enum
{
    OTAFILE_FLAG_ERROR = 0,
    OTAFILE_FLAG_READY,
    OTAFILE_FLAG_DONE,
} check_otafile_flag_enum;

typedef struct {
    kal_int8   recount;
    kal_int8   log;
    kal_uint16 port;
    char       *server;
} ell_data_parameter_struct;
typedef struct
{
    kal_bool                       custom_apn_valid;
    char                           apn[MAX_GPRS_APN_LEN];
    char                           username[MAX_GPRS_USER_NAME_LEN];
    char                           password[MAX_GPRS_PASSWORD_LEN];
} nvram_GPRS_APN_struct;
typedef struct
{
    kal_uint16                      crc;
    kal_uint16                      port;
    kal_uint8                       server[100];
    nvram_GPRS_APN_struct           apn;
} ell_nvram_data_struct;

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
extern void ell_update_soc_nw_attach_ind(void *msg);
extern S8 ell_update_delete_file(void);
extern ell_data_parameter_struct *ell_get_data_parameter(void);

extern void EllLog2 (const char* fun_name, const char* message , ... );
extern void EllHex2(const char *fun_name, void * buff, int size);


#endif  /* _ELL_UPDATE_H */

