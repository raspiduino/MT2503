/******************************************************************************
 * track_cust_key.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        GT300按键处理
 *
 * modification history
 * --------------------
 * v1.0   2013-07-5,  wangqi create this file
 *
 ******************************************************************************/



/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "med_api.h"
#include "track_cust.h"
#include "track_cust_key.h"
#include "track_at_call.h"
#include "track_drv_system_interface.h"

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#define DOBULE_TIME 1000
/*****************************************************************************
* Typedef  Enum
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

/*****************************************************************************
* Golbal variable				全局变量
*****************************************************************************/


/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/
extern void track_cust_module_sos_trigger_button(void);

/*****************************************************************************
 *  Global Functions	- Extern		引用外部函数
 *****************************************************************************/
#if defined (__NETWORK_LICENSE__)
extern void track_drv_network_license_key_make_call(void);
#endif /* __NETWORK_LICENSE__ */
extern void track_cust_set_call_state(void);
extern void track_cust_alarm_pwoffalm(void);
extern kal_uint32 track_cust_check_sosnum(void);
/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/



/*****************************************************************************
 *  Global Functions			全局函数
 *****************************************************************************/
/******************************************************************************
 *  Function    -  track_cust_key_single_press
 *
 *  Purpose     -
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0   13-08-2013,  Wangqi
 * ----------------------------------------
*******************************************************************************/
static void track_cust_key_single_press(void)
{
    extern kal_uint8 track_cust_key_dail_way(kal_uint8 option);

    LOGD(L_APP, L_V5, "=====");

    if(track_is_in_call())
    {
        if(track_cust_get_SOS_callout())
        {
            //   track_cust_key_control_led();
        }
        else
        {
            track_cust_key_dail_way(2);
            track_cust_call_hangup();
        }
    }
    else
    {
        // track_cust_key_control_led();
    }

}
/******************************************************************************
 *  Function    -  track_cust_key_sos_double_press
 *
 *  Purpose     -  SOS按键双击事件处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0   13-08-2013,  Wangqi
 * v1.1   29-10-2013,  ZengPing && LiuJW
 * ----------------------------------------
*******************************************************************************/
static kal_uint8 track_cust_key_sos_double_press(void)
{
    kal_uint8 result = 0xFF;
    kal_uint8 defence_status = track_cust_status_defences();
    LOGD(L_APP, L_V5, "=====current status:%d,sw:%d", defence_status , G_parameter.vibrates_alarm.sw);

    if(G_parameter.vibrates_alarm.sw == 0 || track_cust_get_work_mode() == WORK_MODE_3)
    {
        LOGD(L_APP, L_V5, "报警开关为关闭状态设防操作失效");
    }
    else if(0 == defence_status)
    {
        result = 1;
        track_cust_status_defences_change((void*)1);
        track_stop_timer(TRACK_CUST_MODULE_ALARM_VIBRATES_TIMER_ID);
#if defined(__GT300S__) || defined(__GT370__)|| defined (__GT380__)
        track_start_timer(
            TRACK_CUST_STATUS_DEFENCES_TIMER_ID, 
            30 * 1000, 
            track_cust_status_defences_change, (void*)2);
#else
        track_start_timer(
            TRACK_CUST_STATUS_DEFENCES_TIMER_ID, 
            G_parameter.defense_time * 1000, 
            track_cust_status_defences_change, (void*)2);
#endif
    }
    else if(1 == defence_status || 2 == defence_status)
    {
        result = 0;
        track_cust_status_defences_change((void*)0);
    }
    else
    {
        LOGD(L_APP, L_V5, "=====ERROR defence status:%d", defence_status);
        //重启
    }
    return result;
}

/******************************************************************************
 *  Function    -  track_cust_key_led_sleep
 *
 *  Purpose     -  GT03进入休眠状态
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 14-10-2013,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_key_led_sleep(void)
{
    LOGD(L_APP, L_V5, "");
#if defined(__GT740__)

#else
    track_cust_led_sleep(2);
#endif
#if defined(__GT300S__) || defined(__GT370__)|| defined (__GT380__)
    if(track_cust_status_charger() == 1)
    {
        LED_PWR_StatusSet(PW_CHARGING_STATE);
    }
    else if(track_cust_status_charger() == 2)
    {
        LED_PWR_StatusSet(PW_FULLCHARGED_STATE);
    }
#endif

    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
}

void track_cust_led_wake(void)
{
    LOGD(L_APP, L_V5, "");
    G_realtime_data.key_status = 1;
    track_cust_led_sleep(1);
    if(G_parameter.lcd_on_time)
    {
        tr_start_timer(TRACK_CUST_SOS_KEY_LED_ON_TIMER, G_parameter.lcd_on_time * 1000, track_cust_key_led_sleep);
    }
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
}
/******************************************************************************
 *  Function    -  track_cust_key_control_led
 *
 *  Purpose     -  按键控制led灯
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 15-10-2013,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
 void track_cust_key_control_led(void)
{
    LOGD(L_APP, L_V5, "按键按下=%d", G_realtime_data.key_status);
#if defined(__SAME_GT02__)
    if(track_cust_led_sleep(99) == 1)
    {
        tr_stop_timer(TRACK_CUST_SOS_KEY_LED_ON_TIMER);
        G_realtime_data.key_status = 0;
        track_cust_led_sleep(2);
    }
    else
    {
        G_realtime_data.key_status = 1;
        track_cust_led_sleep(1);
    }
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
#else
    if(track_cust_led_sleep(99) == 1)
    {
        tr_stop_timer(TRACK_CUST_SOS_KEY_LED_ON_TIMER);
        G_realtime_data.key_status = 0;
        track_cust_key_led_sleep();
    }
    else
    {
	track_cust_led_wake();
    }
#endif
}
/******************************************************************************
 *  Function    -  track_cust_key_sos
 *
 *  Purpose     -  SOS按键处理事件
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * v1.5 , 13-08-2013,  Wangqi
 * ----------------------------------------
*******************************************************************************/
void track_cust_key_sos(void)
{
    LOGD(L_APP, L_V5, "按键按下=%d", G_realtime_data.key_status);
    if(KAL_TRUE == track_is_timer_run(TRACK_CUST_PWROFFALM_TIMER_ID))
    {
        LOGD(L_APP, L_V5, "关机报警发送中,不处理SOS按键");
        return;
    }
    track_stop_timer(TRACK_CUST_LED_START_TIMER);

#if defined(__GT300S__)
    if(track_is_timer_run(TRACK_CUST_SOS_KEY_DOUBLE_TIMER))
    {
		tr_stop_timer(TRACK_CUST_SOS_KEY_DOUBLE_TIMER);
        track_cust_key_sos_double_press();
    }
    else
    {
        tr_start_timer(TRACK_CUST_SOS_KEY_DOUBLE_TIMER, DOBULE_TIME, track_cust_key_single_press);
    }
#endif

#if !defined( __OLED__)
    track_cust_key_control_led();
#endif /* __OLED__ */
}

/******************************************************************************
 *  Function    -  track_cust_key_dail_way
 *  Purpose     -  按键触发打电话
 *  Description - return1 是FN触发
                        2 SOS键
 *  modification history
 * ----------------------------------------
 * v1.0   09-12M-2013,  Wangqi
 * ----------------------------------------
*******************************************************************************/
kal_uint8 track_cust_key_dail_way(kal_uint8 option)
{
    static kal_uint8 cur_way = 0;
    if(option == 0 || option == 1 || option == 2)
    {
        cur_way = option;
        if(option == 1)
        {
#if defined(__AUDIO_RC__)
            track_cust_monitor_set_speaket(0);
#endif /* __AUDIO_RC__ */
        }
    }

    return cur_way;
}


static void track_cust_key_event_wakeup(void)
{
    LOGD(L_APP, L_V5,"MCU唤醒GSM");
    track_drv_mcu_and_gsm_sleep(1);
}

/******************************************************************************
 *  Function    -  track_cust_keypad_init
 *
 *  Purpose     -  按键注册
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0   13-08-2013,  Wangqi
 * ----------------------------------------
*******************************************************************************/
void track_cust_keypad_init(void)
{
#if defined (__NETWORK_LICENSE__)
    track_drv_network_license_key_make_call();
#endif /* __NETWORK_LICENSE__ */

#if defined (__MCU_BJ8M601A_NT13V__)
    track_drv_set_key_handler(track_cust_key_event_wakeup, KEY_POWER, KEY_FULL_PRESS_DOWN);
#endif /* __MCU_BJ8M601A_NT13V__ */

#if defined (__KEYPAD_MOD__)
    track_project_keypad_init();
#endif /* __KEYPAD_MOD__ */

}

