/******************************************************************************
 * track_cust_lcd.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        modem 工程OLED应用层接口
 *
 * modification history
 * --------------------
 * v1.0   2014-4-25,  wangqi create this file
 *
 ******************************************************************************/

#if defined (__OLED__)

/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "track_cust.h"
#include "track_drv_lcd.h"
#include "track_cust_lcd.h"
/*****************************************************************************
 *  Define					宏定义
*****************************************************************************/


/*****************************************************************************
* Typedef  Enum
*****************************************************************************/


/*****************************************************************************
 *  Struct					数据结构定义
*****************************************************************************/


/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/
static kal_uint8 gsm_level = 0xff;
static kal_uint8 chargin = 0;
static kal_uint8 charglevel = 0x0f;

/****************************************************************************
* Global Variable - Extern          全局变量
*****************************************************************************/

/****************************************************************************
* Global Variable - Extern              引用全局变量
*****************************************************************************/
extern kal_uint8 track_drv_bmt_get_charging_status(void);

/*****************************************************************************
 *  Local Functions			本地函数
*****************************************************************************/


/******************************************************************************
 *  Function    -  track_cust_lcd_set_background
 *  Purpose     -  
 *  Description -  全写白 0
 *  
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-4-19,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_lcd_set_background(char d)
{
    track_drv_spi_set_background(d);
}

/******************************************************************************
 *  Function    -  track_drv_lcd_time_type
 *  Purpose     -  
 *  Description -  
 *  
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-4-19,  wangqi  written
 * ----------------------------------------
*******************************************************************************/

kal_uint8 track_drv_lcd_time_type(kal_uint8 utc)
{
    static kal_uint8 lcd_utc = 0;
    if(0 == utc || 1 == utc)
    {
        lcd_utc = utc;
    }
    return lcd_utc;
}
/******************************************************************************
 *  Function    -  track_cust_lcd_updata_time
 *  Purpose     -  
 *  Description -  更新时间
 *  [0-31]
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-4-19,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_lcd_updata_time(void)
{
    static kal_uint8 count = 0;
    applib_time_struct rtc = {0};
    if(track_drv_lcd_is_sos())
    {
        LOGD(L_APP, L_V5,"==lcd is sos ing ...");
        return;
    }
    if(track_drv_lcd_time_type(0xFF))
    {
        track_fun_get_time(&rtc, KAL_TRUE, NULL);
    }
    else
    {
        track_fun_get_time(&rtc, KAL_FALSE, &G_parameter.zone.zone);
    }
    
    track_drv_lcd_write_time(rtc.nMonth, rtc.nDay, rtc.nHour, rtc.nMin);
    count = 60 - rtc.nSec;

    track_cust_lcd_updata_gsm(0xff);
    track_cust_lcd_updata_charge(track_drv_bmt_get_charging_status());
    track_drv_lcd_write();
    
    tr_start_timer(LED_DISPALY_TIMER_ID, count * 1000, track_cust_lcd_updata_time);
    LOGD(L_APP, L_V6, "%d,Hour:%d,Min:%d,Sec:%d", count, rtc.nHour, rtc.nMin, rtc.nSec);

}
/******************************************************************************
 *  Function    -  track_cust_lcd_updata_gsm
 *  Purpose     -  
 *  Description -  更新GSM图标
 *  [0-4)
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-4-19,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_lcd_updata_gsm(kal_uint8 level)
{
    int lv = 0;
    if(level == 0xff)
    {
        lv = track_cust_get_rssi_level();
        level = (lv < 0 ? 0 : lv);
    }
    //LOGD(L_APP, L_V5, "level:%d,%d,gsm_level:%d", level, lv, gsm_level);

    if(level <= 4)
    {
        track_drv_lcd_updata_gsm(level);
        if(gsm_level == 0xff)
        {
            track_drv_lcd_write();
        }
        gsm_level = level;
    }
}

kal_uint8 track_cust_get_bat_level(kal_uint32 volt)
{
    kal_uint8 level = 2;
    if(volt > 4000000)
    {
        level = 5;
    }
    else if(volt >= 3900000)
    {
        level = 4;
    }
    else if(volt >= 3790000)
    {
        level = 3;
    }
    else if(volt >= 3680000)
    {
        level = 2;
    }
    else if(volt >= LOWER_BATTERY_LEVEL)
    {
        level = 1;
    }
    else 
    {
        level = 0;
    }
    return level;
}

/******************************************************************************
 *  Function    -  track_cust_lcd_updata_charge
 *  Purpose     -  
 *  Description -  更新电量图标
 *  chargin :3 充电完成 0 充电器拔出 1接入充电器
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-4-19,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_lcd_updata_charge(kal_uint8 type)
{
    kal_uint32 volt = track_drv_bmt_get_vol();
    LOGD(L_APP, L_V5, "==type:%d:%d,level:%d", type, chargin,volt);
    if(volt != 0)
    {
        charglevel = track_cust_get_bat_level(volt);
    }
    if(chargin == 3 && type == 1)
    {
        track_drv_lcd_updata_charge(chargin, charglevel);
        return;
    }
    
    if(0x0f != charglevel || (chargin != type))
    {
        chargin = type;
        track_drv_lcd_updata_charge(chargin, charglevel);
        track_drv_lcd_write();
    }
}


/******************************************************************************
 *  Function    -  track_cust_lcd_flash
 *  Purpose     -  
 *  Description -  刷新图标
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-10-08,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_lcd_flash(void)
{
    LOGD(L_DRV, L_V5, "charglevel:%d",charglevel);
    track_cust_lcd_updata_time();
    //track_cust_lcd_updata_gsm(gsm_level);
}
extern void track_cust_key_led_sleep(void);
void track_cust_lcd_sos_callback(void)
{
    track_cust_lcd_flash();
    LOGD(L_DRV, L_V5, "%d", G_realtime_data.key_status);
    
    if(G_realtime_data.key_status == 0)
    {
        G_realtime_data.key_status = 1;
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    }
    track_cust_led_sleep(1);
    if(G_parameter.lcd_on_time)
    {
        tr_start_timer(TRACK_CUST_SOS_KEY_LED_ON_TIMER, G_parameter.lcd_on_time * 1000, track_cust_key_led_sleep);
    }
    
}
/******************************************************************************
 *  Function    -  track_cust_volt_init
 *  Purpose     -  
 *  Description -  更新电量图标
 *  volt :首次更新电量时主动更新图标
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-10-08,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
kal_bool track_cust_volt_init(kal_uint32 volt)
{
    static kal_bool is_init = KAL_TRUE;
    LOGD(L_APP, L_V5, "==charglevel:%d, is_init:%d, volt:%d", charglevel, is_init, volt);

    if(volt > 0)
    {
        if(charglevel == 0xf)
        {
            is_init = KAL_FALSE;
            charglevel = track_cust_get_bat_level(volt);
            track_cust_lcd_updata_charge(track_drv_bmt_get_charging_status());
        }
    }
    return is_init;
}

void track_cust_lcd_sos(void)
{
    LOGD(L_APP, L_V5, "");
    track_drv_lcd_write_sos();  
}

void track_cust_lcd_enter_sleep(void)
{
    LOGD(L_DRV, L_V5, "");
    track_drv_lcd_enter_sleep();
    if(0 == track_cust_gps_status())
    {
        track_drv_sleep_enable(SLEEP_DRV_MOD, TRUE);
    }

}

void track_cust_lcd_exit_sleep(void)
{
    LOGD(L_DRV, L_V5, "");
    track_drv_lcd_exit_sleep();
    track_cust_lcd_flash();
}

void track_cust_lcd_change_sleep(void)
{
    static kal_uint8 lcd_sleep = 0;
    if(lcd_sleep)
    {
        lcd_sleep = 0;
        track_cust_lcd_exit_sleep();
    }
    else
    {
        lcd_sleep = 1;
        track_cust_lcd_enter_sleep();
    }
}

/******************************************************************************
 *  Function    -  track_drv_lcd_display_test
 *  Purpose     -  
 *  Description -  测试指令
 *  
 *  modification history
 * ----------------------------------------
 * v1.0  , 2014-4-19,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_lcd_display_test(int index)
{

}

#endif /* __OLED__ */

