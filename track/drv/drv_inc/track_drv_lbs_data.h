/******************************************************************************
 * track_lbs_data.h - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *        获取LBS 信息 
 * 
 * modification history
 * --------------------
 * v1.0   2012-07-27,  chengjun create this file
 * 
 ******************************************************************************/

#ifndef _TRACK_DRV_LBS_DATA_H
#define _TRACK_DRV_LBS_DATA_H


/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
//#define  __LBS_DATA_DEBUG__


/****************************************************************************
* Include Files                         包含头文件
*****************************************************************************/
#include "stack_msgs.h"
#include "stdlib.h"
#include "kal_public_defs.h"
#include "track_os_data_types.h"
#include "as2l4c_struct.h"

/*****************************************************************************
 *  Struct                              数据结构定义
 *****************************************************************************/
typedef struct
{
    kal_uint16 mcc;
    kal_uint16 mnc;
    kal_uint16 lac;
    kal_uint16 cell_id;
    kal_int16 rxlev;   /*  rxlev  : 通过catcher 信息查看，这个值应该是被处理后的信号电平，
                                    算信号等级值，不是真正的信号强度值 */
                              /*track_drv_convert_rxlev_to_rssi  -信号等级逆转换为信号强度 -- chengjun  2012-03-08*/
} Multi_Cell_Info_Struct;

typedef struct
{
    BOOL status;    //  TRUE = 有效
    Multi_Cell_Info_Struct      MainCell_Info;
    Multi_Cell_Info_Struct      NbrCell_Info[6];
    kal_uint8 valid_cel_num;
    kal_uint8 ta;
} LBS_Multi_Cell_Data_Struct;

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
extern void track_drv_get_network_info(void);

#endif  /* _TRACK_DRV_LBS_DATA_H */

