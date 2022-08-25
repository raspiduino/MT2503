/******************************************************************************
 * track_cust_lcd.h -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        modem 工程OLED应用层接口
 *
 * modification history
 * --------------------
 * v1.0   2014-4-24,  wangqi create this file
 *
 ******************************************************************************/

#if defined (__OLED__)

#ifndef _TRACK_CUST_LCD_H
#define _TRACK_CUST_LCD_H


/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/


/****************************************************************************
* Include Files                         包含头文件
*****************************************************************************/
#include "stack_msgs.h"
#include "stdlib.h"
#include "kal_public_defs.h"
#include "track_os_data_types.h"
#include "stack_ltlcom.h"



/*****************************************************************************
 *  Struct                              数据结构定义
 *****************************************************************************/


/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

extern void track_cust_lcd_change_sleep(void);
extern void track_cust_lcd_updata_gsm(kal_uint8 level);
extern void track_cust_lcd_updata_charge(kal_uint8 type);
extern void track_cust_lcd_sos(void);
#endif  /* _TRACK_CUST_LCD_H */

#endif /* __OLED__ */
