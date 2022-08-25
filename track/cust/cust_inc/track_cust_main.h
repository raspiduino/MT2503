#ifndef _TRACK_CUST_MAIN_H
#define _TRACK_CUST_MAIN_H

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "track_drv.h"
#include "nvram_editor_data_item.h"


/*****************************************************************************
*  Define                               宏定义
******************************************************************************/

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/


/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Functions Define                     函数声明
******************************************************************************/
extern void track_cust_eint_trigger_response(U8 eint, U8 level);
extern void track_cust_chargestatus_vbtstatus_check(pmic_status_enum status, battery_level_enum level, kal_uint32 volt);
extern void track_cust_call_incomming_number(char *inc_number);
extern void track_cust_call_status(kal_uint16 callState);
extern void track_cust_init(void);
extern void track_cust_external_batter_measure_done(kal_int32 ext_volt);
extern kal_bool track_cust_is_upload_UTC_time(void);
//extern void track_cust_check_simalm(void);
//extern void track_cust_mode3_work_check(void* flag);
extern void track_cust_mode_change(kal_uint8 flg);
#endif  /* _TRACK_CUST_MAIN_H */


