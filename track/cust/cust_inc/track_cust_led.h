/******************************************************************************
 * track_led.h - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *        LED  显示 
 * 
 * modification history
 * --------------------
 * v1.0   2012-07-22,  chengjun create this file
 * 
 ******************************************************************************/

#ifndef _TRACK_CUST_LED_H
#define _TRACK_CUST_LED_H

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "track_drv_led.h"
#include "common_nvram_editor_data_item.h"


/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/

//#define __LED_DEBUG__


#define LED_FIRST_DISPLAY_TIME	( 5*60*1000 )      //在产品进入正常工作状态后，LED 灯持续显示的时间
#define LED_FIRST_PWRON_TIME 20*1000                 /*按键灯第一次上电常亮20S灭*/
#define LED_ALWAYS_DISPLAY_TIME  60*1000           /*First time power on ,led display 5 minutes,other display 20S*/
#define LED_KEY_DISPLAY_TIME 5*1000

/*LED 状态灯的显示关闭时间       --    MagicNing  2010-05-24*/
#define LED_OFF_DELAY_TIME  80

/***************************************************************************** 
* Typedef  Enum
*****************************************************************************/
typedef enum
{
    GPS_INVALID_STATE,       // GPS关闭
    GPS_PWON_STATE,            // 刚开机
    GPS_SCAN_STATE,             // 正在搜星
    GPS_LOCATION_STATE     // 已定位
} GPS_WORK_STATE;

typedef enum
{
    PW_OFF_STATE,
    PW_NORMAL_STATE,
    PW_TOO_LOW_STATE,
    PW_LOW_ALARM_STATE,
    PW_ON_STATE,
    PW_CHARGING_STATE,
    //PW_SHUTDOWN_STATE,
    PW_FULLCHARGED_STATE
} GPS_BATTERY_STATE; //电池状态

typedef enum
{
    GSM_OFF_STATE,
    GSM_NORMAL_STATE,
    GSM_COMING_CALL_STATE,
    GSM_IN_CALL_STATE,
    GSM_INITIAL_STATE,
    GSM_NO_SIGNAL_STATE,
    GPRS_CONNECT_STATE,
    //GSM_SHUTDOWN_STATE
} GSM_SIGNAL_STATE; //GSM

typedef enum 
{
	TWO_GSM_IN_CALL_STATE=0,
    TWO_PW_CHARGING_STATE,
	TWO_PW_FULLCHARGED_STATE,
	TWO_PW_TOO_LOW_STATE,
	TWO_GSM_OFF_STATE,//未插SIM卡
    TWO_GSM_SCAN_STATE,
	TWO_GPS_UNLOCATION_STATE,	   // 未定位
	TWO_GPRS_DISCONNECT_STATE,
	TWO_GPRS_CONNECT_STATE,
	TWO_PW_ON_STATE,
	TWO_COLOR_MAX
}TWO_COLOR_STATE;

typedef enum 
{
	TLEVEL1,
	TLEVEL2,
	TLEVEL3,
	TLEVEL4,
		TLEVEL5,
	TLEVEL_MAX
}TWO_COLOR_LEVEL_STATE;


/*****************************************************************************
 *  Struct					数据结构定义
 *****************************************************************************/


/*****************************************************************************
 *  Global Functions			全局变量
 *****************************************************************************/

/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/


/*****************************************************************************
 *  Global Functions			全局函数
 *****************************************************************************/
extern void LED_GPS_StatusSet(GPS_WORK_STATE status);
extern void LED_GSM_StatusSet(GSM_SIGNAL_STATE status);
extern void LED_PWR_StatusSet(GPS_BATTERY_STATE status);
extern kal_uint8 track_cust_led_sleep(kal_int8 par);
#endif  /* _TRACK_CUST_LED_H */
