/******************************************************************************
 * track_charge_bmt.h - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *        充电与电池 
 * 
 * modification history
 * --------------------
 * v1.0   2012-07-20,  chengjun create this file
 * 
 ******************************************************************************/

#ifndef _TRACK_DRV_CHARGE_BMT_H
#define _TRACK_DRV_CHARGE_BMT_H

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/



/****************************************************************************
* Include Files                         包含头文件
*****************************************************************************/
#include "track_os_data_types.h"
#include "kal_public_defs.h"
#include "device.h"

/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/
typedef enum
{
    SLEEP_DRV_MOD,
    SLEEP_SOC_MOD,
    SLEEP_CMD_MOD,
    SLEEP_SMT_MOD,
    SLEEP_OBD_MOD,/*2318项目中，用作bms模块句柄*/
    SLEEP_APP_MOD,
    SLEEP_CALL_MOD,
    SLEEP_EXT_UART_MOD, /*串口与外设通信专用       --    chengjun  2017-06-30*/
    /*最多扩展到8个，否则代码计算错误!!       --    chengjun  2012-09-03*/
    SLEEP_MOD_ALL   //强制控制全部模块
} sleep_mod_enum;

typedef enum
{
    NO_CHR,
    AC_CHR,
    USB_CHR,
    NON_STD_CHR,
    MAX_CHR
}chr_way_enum;
/*****************************************************************************
 *  Struct                              数据结构定义
 *****************************************************************************/

typedef struct
{
    LOCAL_PARA_HDR
    pmic_status_enum status;
    battery_level_enum level;
    kal_uint32 volt;
} charbat_status_struct;


typedef struct
{
    kal_bool in_chr;
    float bmt_vBat;
    float bmt_iChr;
    float bmt_vChr;
    float bmt_vTemp;//假的!! 借用这个值判断是否有电池
} charge_measure_struct;

typedef struct
{
    kal_int32 vBat;
    kal_int32 iChr;
    kal_int32 vChr;
    kal_int32 vTemp;
} charge_adc_struct;

typedef struct
{
    charge_adc_struct adc[9];
    kal_uint8 count;
} charge_adc_count_struct;

/*****************************************************************************
 *  Global Functions			全局变量
 *****************************************************************************/


/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/


/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
extern kal_int8 track_drv_sleep_enable(sleep_mod_enum mod ,BOOL enable);
extern kal_int32 track_drv_get_external_voltage_status(void);
extern kal_uint8 track_drv_bmt_get_charging_status(void);
extern kal_uint32 track_drv_bmt_get_vol(void);
#endif  /* _TRACK_DRV_CHARGE_BMT_H */
