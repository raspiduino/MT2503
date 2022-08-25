/******************************************************************************
 * track_drv_lcd.h -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        keypad 自定义
 *
 * modification history
 * --------------------
 * v1.0   2014-4-19,  wangqi create this file
 *
 ******************************************************************************/

#if defined (__OLED__)

#ifndef _TRACK_DRV_LCD_H
#define _TRACK_DRV_LCD_H


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

#define OLED_WIDTH                  128
#define OLED_HEIGTH                 32

#define LCD_MODE_SIZE_MAX           18

#define SUBLCD_CS_PIN				40
#define SUBLCD_DC_PIN				36
#define SUBLCD_CLK_PIN	             37
#define SUBLCD_DATA_PIN			38
#define SUBLCD_RESET_PIN			43
#define SET_SUBLCD_CLK_HIGH		GPIO_WriteIO(1,SUBLCD_CLK_PIN)
#define SET_SUBLCD_CLK_LOW			GPIO_WriteIO(0,SUBLCD_CLK_PIN)
#define SET_SUBLCD_DATA_HIGH		GPIO_WriteIO(1,SUBLCD_DATA_PIN)
#define SET_SUBLCD_DATA_LOW         GPIO_WriteIO(0,SUBLCD_DATA_PIN)

/*****************************************************************************
 *  Struct                              数据结构定义
 *****************************************************************************/

typedef struct
{
    kal_uint8 row;
    kal_uint8 column;
    //kal_uint8 endcol;
    kal_uint8 hight;
    kal_uint8 width;
    
} lcd_mode_position;

typedef struct
{
    kal_uint8 length;
    kal_uint8* data;    
} lcd_source;

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

extern void track_drv_Init_OLED_IC(void);
extern void track_drv_lcd_display_test(int index);
extern void track_drv_spi_set_background(char d);
extern kal_uint8 track_drv_lcd_time_type(kal_uint8 utc);
extern void track_drv_lcd_updata_gsm(int level);
extern void track_drv_lcd_updata_charge(kal_uint8 type, kal_uint8 level);
extern void track_drv_lcd_write_time(kal_uint8 month, kal_uint8 day, kal_uint8 hour, kal_uint8 mins);
extern void track_drv_lcd_enter_sleep(void);
extern void track_drv_lcd_exit_sleep(void);

#endif  /* _TRACK_DRV_LCD_H */

#endif /* __OLED__ */
