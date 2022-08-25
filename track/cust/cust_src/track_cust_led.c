/******************************************************************************
 * Led.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        LED 控制
 *
 *     LED状态的优先顺序：
 *
 *          休眠 > 通话中绿灯常亮 > 报警状态 > ACC切换状态 > 设防状态 > 充电状态 > 正常状态
 *
 *
 *
 * modification history
 * --------------------
 *
 ******************************************************************************/



/****************************************************************************
* Include Files                   		包含头文件
*****************************************************************************/
#include "track_cust.h"

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/


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
static kal_uint16 led_rgb_last_status[3] = {0};
static kal_uint8 led_status = 1;            // 1 正常输出 2 设防输出  3 ACC变化输出  4 触发报警后，临时恢复正常状态30秒
static kal_uint8 level_status[TLEVEL_MAX] = {0};
static kal_uint8 state_cache[TWO_COLOR_MAX] = {0};


/*****************************************************************************
* Golbal variable				全局变量
*****************************************************************************/
kal_uint8 red_led_status = PW_NORMAL_STATE;

/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/


/*****************************************************************************
 *  Global Functions	- Extern		引用外部函数
 *****************************************************************************/
#if 0
#endif /* 0 */
/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/
static void led_red_set(GPS_BATTERY_STATE status);
static void led_green_set(GSM_SIGNAL_STATE status);
static void led_blue_set(GPS_WORK_STATE status);

/*****************************************************************************
 *  Global Functions			全局函数
 *****************************************************************************/
void LED_TWO_COLOR_StatusSet(TWO_COLOR_STATE status);
void led_level_state_switch(void);


/******************************************************************************
 *  Function    -  led_defences
 *
 *  Purpose     -  设防状态的LED显示
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void led_defences(void)
{
    int i = 0;
    static led_loop_main_struct data = {0};
    data.loop = 0;

    if(track_cust_status_defences() == 1)//预设防慢闪
    {
        /* 全灭 1000ms
        data.leds[i].valid = KAL_TRUE;
        data.leds[i].delay = 600;
        i++;*/

        /* 绿灯 亮 300ms */
        data.leds[i].valid = KAL_TRUE;
        data.leds[i].delay = 700;
        data.leds[i].status[LED_GSM] = KAL_TRUE;
        i++;

        /* 红灯 亮 300ms */
        data.leds[i].valid = KAL_TRUE;
        data.leds[i].delay = 700;
        data.leds[i].status[LED_PWR] = KAL_TRUE;
        i++;

        /* 蓝灯 亮 300ms */
        data.leds[i].valid = KAL_TRUE;
        data.leds[i].delay = 700;
        data.leds[i].status[LED_GPS] = KAL_TRUE;
        i++;
    }
    else if(track_cust_status_defences() == 2)//设防快闪
    {
        /* 全灭 1000ms
        data.leds[i].valid = KAL_TRUE;
        data.leds[i].delay = 300;
        i++;*/

        /* 绿灯 亮 300ms */
        data.leds[i].valid = KAL_TRUE;
        data.leds[i].delay = 300;
        data.leds[i].status[LED_GSM] = KAL_TRUE;
        i++;

        /* 红灯 亮 300ms */
        data.leds[i].valid = KAL_TRUE;
        data.leds[i].delay = 300;
        data.leds[i].status[LED_PWR] = KAL_TRUE;
        i++;

        /* 蓝灯 亮 300ms */
        data.leds[i].valid = KAL_TRUE;
        data.leds[i].delay = 300;
        data.leds[i].status[LED_GPS] = KAL_TRUE;
        i++;
    }
    else
    {
        LOGD(L_APP, L_V5, "====Defences==== return");
        /* 红灯 亮 300ms */
        data.leds[i].valid = KAL_TRUE;
        data.leds[i].delay = 300;
        data.leds[i].status[LED_PWR] = KAL_TRUE;
        i++;
        /* 全灭 500ms */
        data.leds[i].valid = KAL_TRUE;
        data.leds[i].delay = 500;
        i++;
        /* 绿灯 亮 300ms */
        data.leds[i].valid = KAL_TRUE;
        data.leds[i].delay = 300;
        data.leds[i].status[LED_GSM] = KAL_TRUE;
        i++;
        /* 全灭 500ms */
        data.leds[i].valid = KAL_TRUE;
        data.leds[i].delay = 500;
        i++;
        /* 蓝灯 亮 300ms */
        data.leds[i].valid = KAL_TRUE;
        data.leds[i].delay = 300;
        data.leds[i].status[LED_GPS] = KAL_TRUE;
        i++;
        /* 全灭 500ms */
        data.leds[i].valid = KAL_TRUE;
        data.leds[i].delay = 500;
        i++;
    }

    track_drv_led_loop(&data);
}


//time不变
static void led_red_set(GPS_BATTERY_STATE status)
{
    LOGD(L_APP, L_V5, "status=%d, led_status=%d, sw_nbver:%d", status, led_status, G_parameter.sw_nbver);
    if(G_parameter.sw_nbver == 1) status = PW_ON_STATE;
    led_rgb_last_status[0] = status;
    switch(status)
    {

#if defined(__SAME_GT02__)
        case PW_ON_STATE:
        case PW_CHARGING_STATE:
            LED_Set_Flash(LED_PWR, 100, 2000);
            break;

        case PW_OFF_STATE:
            track_drv_led_switch(LED_PWR, KAL_FALSE);
            break;

        case PW_NORMAL_STATE:
            LED_Set_Flash(LED_PWR, 100, 2000);
            break;

        case PW_LOW_ALARM_STATE:
            LED_Set_Flash(LED_PWR, 100, 100);
            break;

        case PW_FULLCHARGED_STATE:
            LED_Set_Flash(LED_PWR, 100, 2000);
            break;

#else
        case PW_CHARGING_STATE:
            track_drv_led_switch(LED_PWR, KAL_TRUE);
            break;

        case PW_OFF_STATE:
            track_drv_led_switch(LED_PWR, KAL_FALSE);
            break;

        case PW_ON_STATE:
        case PW_NORMAL_STATE:
            LED_Set_Flash(LED_PWR, 100, 3000);//100,3000
            break;

        case PW_LOW_ALARM_STATE:
            LED_Set_Flash(LED_PWR, 300, 300);//300,300
            break;

        case PW_FULLCHARGED_STATE:
            LED_Set_Flash(LED_PWR, 1000, 3000);//1000,3000
            break;
#endif
    }
}

//time --
static void led_green_set(GSM_SIGNAL_STATE status)
{
    LOGD(L_APP, L_V5, "status=%d, led_status=%d", status, led_status);
    led_rgb_last_status[1] = status;
    switch(status)
    {
#if defined(__SAME_GT02__)
        case GSM_COMING_CALL_STATE:
        case GSM_IN_CALL_STATE:
            if(track_cust_status_defences() == 2)
            {
                led_red_set(led_rgb_last_status[0]);
                track_drv_led_switch(LED_GSM, KAL_TRUE);
                led_blue_set(led_rgb_last_status[2]);
            }
        case GPRS_CONNECT_STATE:
            track_drv_led_switch(LED_GSM, KAL_TRUE);
            break;

        case GSM_NO_SIGNAL_STATE:
        case GSM_OFF_STATE:
            track_drv_led_switch(LED_GSM, KAL_FALSE);
            break;

        case GSM_INITIAL_STATE:
            LED_Set_Flash(LED_GSM, 100, 100);
            break;

        case GSM_NORMAL_STATE:
            LED_Set_Flash(LED_GSM, 100, 2000);
            break;
#elif defined(__NT55__)
			case GSM_INITIAL_STATE:
				LED_Set_Flash(LED_GSM, 100, 100);//300,300
				break;

			case GSM_NORMAL_STATE:
				LED_Set_Flash(LED_GSM, 100, 2000);//1000,3000
				break;

			case GPRS_CONNECT_STATE:
				track_drv_led_switch(LED_GSM, KAL_TRUE);
				break;

			case GSM_COMING_CALL_STATE:
			case GSM_IN_CALL_STATE:
				track_drv_led_switch(LED_GSM, KAL_TRUE);
				break;

			case GSM_NO_SIGNAL_STATE:
			case GSM_OFF_STATE:
				track_drv_led_switch(LED_GSM, KAL_FALSE);
				break;
#else
        case GSM_INITIAL_STATE:
            LED_Set_Flash(LED_GSM, 290, 290);//300,300
            break;

        case GSM_NORMAL_STATE:
            LED_Set_Flash(LED_GSM, 900, 2900);//1000,3000
            break;

        case GPRS_CONNECT_STATE:
            LED_Set_Flash(LED_GSM, 90, 2900);//100,3000
            break;

        case GSM_COMING_CALL_STATE:
        case GSM_IN_CALL_STATE:
            track_drv_led_switch(LED_GSM, KAL_TRUE);
            break;

        case GSM_NO_SIGNAL_STATE:
        case GSM_OFF_STATE:
            track_drv_led_switch(LED_GSM, KAL_FALSE);
            break;
#endif
    }
}


//time ++
static void led_blue_set(GPS_WORK_STATE status)
{
    LOGD(L_APP, L_V5, "status=%d, led_status=%d", status, led_status);
    led_rgb_last_status[2] = status;
    switch(status)
    {
#if defined(__SAME_GT02__)
        case GPS_LOCATION_STATE:
            track_drv_led_switch(LED_GPS, KAL_TRUE);
            break;

        case GPS_PWON_STATE:
        case GPS_INVALID_STATE:
            track_drv_led_switch(LED_GPS, KAL_FALSE);
            break;

        case GPS_SCAN_STATE:
            LED_Set_Flash(LED_GPS, 100, 100);
            break;
#elif defined(__NT55__)
		case GPS_SCAN_STATE:
			LED_Set_Flash(LED_GPS, 310, 310);//300,300
			break;

		case GPS_LOCATION_STATE:
			track_drv_led_switch(LED_GPS, KAL_TRUE);
			break;

		case GPS_PWON_STATE:
		case GPS_INVALID_STATE:
			track_drv_led_switch(LED_GPS, KAL_FALSE);
			break;
#else
        case GPS_SCAN_STATE:
            LED_Set_Flash(LED_GPS, 310, 310);//300,300
            break;

        case GPS_LOCATION_STATE:
            LED_Set_Flash(LED_GPS, 110, 3100);//100,3000
            break;

        case GPS_PWON_STATE:
        case GPS_INVALID_STATE:
            track_drv_led_switch(LED_GPS, KAL_FALSE);
            break;
#endif
    }
}


/******************************************************************************
 *  Function    -  led_state_switch
 *
 *  Purpose     -  LED不同状态切换
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void led_state_switch(void)
{
    int gps_status;
    LOGD(L_APP, L_V5, "led_status=%d last{%d,%d,%d}", led_status, led_rgb_last_status[0], led_rgb_last_status[1], led_rgb_last_status[2]);
    if(led_status == 3 || led_status == 4) return;
    gps_status = track_cust_gps_status();
    if(gps_status > GPS_LOCATION_STATE) gps_status = GPS_LOCATION_STATE;
    if(track_cust_module_call_status() != 0)
    {
        LOGD(L_APP, L_V5, "1");
        if(g_GT03D)
        {
            if(track_cust_status_defences() >= 1 && led_status == 1)
            {
                led_status = 2;
            }
            else if(track_cust_status_defences() == 0 && led_status == 2)
            {
                led_status = 1;
            }
        }
        else
        {
            if(track_cust_status_defences() == 2 && led_status == 1)
            {
                led_status = 2;
            }
            else if(track_cust_status_defences() != 2 && led_status == 2)
            {
                led_status = 1;
            }
        }
#if defined(__ET310__)|| defined(__GT300S__) || defined(__MT200__)
        if((track_cust_module_call_status() == 3) || (track_cust_module_call_status() == 4))
        {
            led_red_set(led_rgb_last_status[0]);
            led_green_set(GSM_IN_CALL_STATE);
            led_blue_set(gps_status/*last_status[2]*/);
        }
        else if(led_status == 2)
        {
            led_defences();
        }
        else
        {
            led_red_set(led_rgb_last_status[0]);
            led_green_set(led_rgb_last_status[1]);
            led_blue_set(gps_status/*last_status[2]*/);
        }
#else
        if(led_status == 2)
        {
            led_defences();
        }
        else
        {
            led_red_set(led_rgb_last_status[0]);

            led_green_set(GSM_IN_CALL_STATE);

            led_blue_set(led_rgb_last_status[2]);
        }
#endif

    }
    else if(track_is_timer_run(TRACK_CUST_LED_ALARM_TIMER))
    {
        LOGD(L_APP, L_V5, "2");
        led_status = 4;
        led_red_set(led_rgb_last_status[0]);
        led_green_set(led_rgb_last_status[1]);
        led_blue_set(led_rgb_last_status[2]);
    }
    else if((g_GT03D && track_cust_status_defences() >= 1) || (!g_GT03D && track_cust_status_defences() == 2))
    {
        LOGD(L_APP, L_V5, "3");
        led_status = 2;
        led_defences();
    }
    else if(Socket_get_conn_status(0) == SOC_CONN_SUCCESSFUL)
    {
        LOGD(L_APP, L_V5, "4");
        led_status = 1;
        led_red_set(led_rgb_last_status[0]);
        led_green_set(GPRS_CONNECT_STATE);
        led_blue_set(led_rgb_last_status[2]);
    }
    else
    {
        LOGD(L_APP, L_V5, "5");
        led_status = 1;
        led_red_set(led_rgb_last_status[0]);
        led_green_set(led_rgb_last_status[1]);
        led_blue_set(led_rgb_last_status[2]);
    }
}

/******************************************************************************
 *  Function    -  led_state_switch
 *
 *  Purpose     -  LED不同状态切换
 *
 *  Description - 优先级
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 31-03-2017,  xzq  written
 * ----------------------------------------
*******************************************************************************/
void led_level_state_switch(void)
{
    static U8 first_pwn = 1;
    if(first_pwn)
    {
        first_pwn = 0;
        LED_TWO_COLOR_StatusSet(TWO_PW_ON_STATE);
        tr_start_timer(TRACK_CUST_LED_FIRST_PWN_TIMER_ID, 5 * 1000, led_level_state_switch);
        return;
    }
    else if(track_is_timer_run(TRACK_CUST_LED_FIRST_PWN_TIMER_ID))
    {
        return;
    }
    if(track_cust_module_call_status() != 0)
    {
        LOGD(L_APP, L_V5, "1");
        LED_TWO_COLOR_StatusSet(TWO_GSM_IN_CALL_STATE);
    }
    else if(track_cust_status_charger() >= 1)
    {
        LOGD(L_APP, L_V5, "2");
        if(track_cust_status_charger() == 1)
        {
            LED_TWO_COLOR_StatusSet(TWO_PW_CHARGING_STATE);
        }
        else if(track_cust_status_charger() == 2)
        {
            LED_TWO_COLOR_StatusSet(TWO_PW_FULLCHARGED_STATE);
        }
    }
    else if(track_cust_get_battery_volt() <= LOWER_BATTERY_LEVEL)
    {
        LOGD(L_APP, L_V5, "3");
        LED_TWO_COLOR_StatusSet(TWO_PW_TOO_LOW_STATE);
    }
    else if(track_drv_get_sim_type() <= 0)
    {
        LOGD(L_APP, L_V5, "4");
        LED_TWO_COLOR_StatusSet(TWO_GSM_OFF_STATE);
    }
    else if(!track_cust_soc_scan_network())
    {
        LOGD(L_APP, L_V5, "5");
        LED_TWO_COLOR_StatusSet(TWO_GSM_SCAN_STATE);
    }
    else if(track_cust_gps_status() < GPS_STAUS_2D)
    {
        LOGD(L_APP, L_V5, "6");
        LED_TWO_COLOR_StatusSet(TWO_GPS_UNLOCATION_STATE);
    }
    else if(track_soc_login_status())
    {
        LOGD(L_APP, L_V5, "8");
        LED_TWO_COLOR_StatusSet(TWO_GPRS_CONNECT_STATE);
    }
    else
    {
        LOGD(L_APP, L_V5, "9");
        LED_TWO_COLOR_StatusSet(TWO_GPRS_DISCONNECT_STATE);
    }
}

static void led_acc_change_status_exit(void)
{
    LOGD(L_APP, L_V5, "");
    if((g_GT03D && track_cust_status_defences() >= 1) || (!g_GT03D && track_cust_status_defences() == 2))
    {
        led_status = 2;
    }
    else
    {
        led_status = 1;
    }
    tr_start_timer(TRACK_CUST_LED_SWITCH_TIMER, 1000, led_state_switch); //LED控制函数在退出时做延迟，不然会对LED控制产生干扰
}

static void led_alarm_exit(void)
{
    LOGD(L_APP, L_V5, "");
#if defined(__GT300S__)
    if(track_cust_led_sleep(99) == 0 || G_realtime_data.key_status == 0 || track_cust_led_sleep(99) == 2)
    {
        track_cust_key_led_sleep(2);
    }
    else
#endif
    {
        if((g_GT03D && track_cust_status_defences() >= 1) || (!g_GT03D && track_cust_status_defences() == 2))
        {
            led_status = 2;
        }
        else
        {
            led_status = 1;
        }
        tr_start_timer(TRACK_CUST_LED_SWITCH_TIMER, 1000, led_state_switch); //LED控制函数在退出时做延迟，不然会对LED控制产生干扰
    }

}

/******************************************************************************
 *  Function    -  LED_PWR_StatusSet
 *
 *  Purpose     -  设置 PWR 状态指示灯
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 12-01-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void LED_PWR_StatusSet(GPS_BATTERY_STATE status)
{
    kal_uint8 call_status = track_cust_module_call_status();
    LOGD(L_APP, L_V5, "status=%d, led_status=%d, call_status=%d", status, led_status, call_status);
    red_led_status = status;//test for defense
    led_rgb_last_status[0] = status;

    if(led_status == 1 || led_status == 4 || call_status != 0 || ((track_cust_led_sleep(99) == 2) && (!track_is_timer_run(TRACK_CUST_SOS_KEY_LED_ON_TIMER))))
    {
        led_red_set(status);
    }
}

/******************************************************************************
 *  Function    -  LED_GSM_StatusSet
 *
 *  Purpose     -  设置 GSM 状态指示灯
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 12-01-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void LED_GSM_StatusSet(GSM_SIGNAL_STATE status)
{
    kal_bool soc_conn_status = KAL_FALSE;
    kal_uint8 call_status = track_cust_module_call_status();

    if(Socket_get_conn_status(0) == SOC_CONN_SUCCESSFUL)
    {
        soc_conn_status = KAL_TRUE;
    }

    LOGD(L_APP, L_V5, "status=%d, led_status=%d, soc_conn_status=%d, call_status=%d", status, led_status, soc_conn_status, call_status);
    if(call_status != 0)
    {
        led_rgb_last_status[1] = GSM_IN_CALL_STATE;

        led_state_switch();
    }
    else
    {
        if(soc_conn_status)
        {
            status = GPRS_CONNECT_STATE;
        }
        led_rgb_last_status[1] = status;
        if(led_status == 1 || led_status == 4)
        {
            led_green_set(status);
        }
    }
}

/******************************************************************************
 *  Function    -  LED_GPS_StatusSet
 *
 *  Purpose     -  设置 GPS 状态指示灯
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 12-01-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void LED_GPS_StatusSet(GPS_WORK_STATE status)
{
    kal_uint8 call_status = track_cust_module_call_status();
    LOGD(L_APP, L_V5, "status=%d, led_status=%d, call_status=%d", status, led_status, call_status);
    led_rgb_last_status[2] = status;
    if(led_status == 1 || led_status == 4 || call_status != 0)
    {
        led_blue_set(status);
    }
}



/******************************************************************************
 *  Function    -  LED_TWO_COLOR_StatusSet
 *
 *  Purpose     -  设置 单个双色灯 状态指示灯
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-03-30,  xzq  written
 * ----------------------------------------
 ******************************************************************************/
void LED_TWO_COLOR_StatusSet(TWO_COLOR_STATE status)
{
    LOGD(L_APP, L_V5, "status=%d", status);
    switch(status)
    {
        case TWO_GSM_SCAN_STATE:
            track_drv_led_switch(LED_RED, KAL_FALSE);
            LED_Set_Flash(LED_GREEN, 300, 1000);
            break;
        case TWO_GSM_OFF_STATE:
            track_drv_led_switch(LED_GREEN, KAL_FALSE);
            LED_Set_Flash(LED_RED, 300, 1000);
            break;
        case TWO_GPS_UNLOCATION_STATE:
            LED_Set_Flash(LED_GREEN, 300, 1000);
            LED_Set_Flash(LED_RED, 300, 1000);
            break;
        case TWO_GPRS_CONNECT_STATE:
            track_drv_led_switch(LED_RED, KAL_FALSE);
            LED_Set_Flash(LED_GREEN, 300, 3000);
            break;
        case TWO_PW_TOO_LOW_STATE:
            track_drv_led_switch(LED_GREEN, KAL_FALSE);
            LED_Set_Flash(LED_RED, 300, 3000);
            break;
        case TWO_GPRS_DISCONNECT_STATE:
            LED_Set_Flash(LED_GREEN, 300, 3000);
            LED_Set_Flash(LED_RED, 300, 3000);
            break;
        case TWO_PW_FULLCHARGED_STATE:
        case TWO_GSM_IN_CALL_STATE:
            track_drv_led_switch(LED_GREEN, KAL_TRUE);
            track_drv_led_switch(LED_RED, KAL_FALSE);
            break;
        case TWO_PW_ON_STATE:
            track_drv_led_switch(LED_GREEN, KAL_FALSE);
            track_drv_led_switch(LED_RED, KAL_TRUE);
            break;
        case TWO_PW_CHARGING_STATE:
            track_drv_led_switch(LED_GREEN, KAL_TRUE);
            track_drv_led_switch(LED_RED, KAL_TRUE);
            break;
    }
}


void track_cust_led_unlock_level_event(TWO_COLOR_LEVEL_STATE level)
{
    level_status[level] = 0;
}

/******************************************************************************
 *  Function    -  track_cust_led_defences
 *
 *  Purpose     -  设防撤防对LED的控制
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_led_defences(kal_uint8 status)
{
    LOGD(L_APP, L_V5, "status=%d", status);
    if(track_is_testmode()) return;
    led_state_switch();
}

/******************************************************************************
 *  Function    -  track_cust_led_sleep
 *
 *  Purpose     -  LED休眠处理
 *
 *  Description -
 *                 1  退出休眠
 *                 2  进入休眠(关闭所有LED灯)
 *                 99 查询当前的休眠状态，返回1表示当前处于LED休眠，0表示当前处于正常显示
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 10-01-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_uint8 track_cust_led_sleep(kal_int8 par)
{
    LOGD(L_APP, L_V5, "par:%d, led_sleep:%d;power_saving_mode:%d", par, G_parameter.led_sleep, G_realtime_data.power_saving_mode);
    if(par == 99)
    {
        return track_drv_led_sleep(99);
    }
    if(par == 2)
    {
        /* 进入休眠(关闭所有LED灯) */
#if defined(__GT300S__)
        if(track_cust_status_charger() >= 1)
        {
            track_drv_led_sleep(3);

            if(track_cust_status_charger() == 1)
            {
                LED_PWR_StatusSet(PW_CHARGING_STATE);
            }
            else if(track_cust_status_charger() == 2)
            {
                LED_PWR_StatusSet(PW_FULLCHARGED_STATE);
            }
        }
        else
#endif
        {
            track_drv_led_sleep(2);
        }
    }
    else if(par == 3 && G_parameter.led_sleep != 3)
    {
        /* 退出休眠 */
        track_drv_led_sleep(1);
        led_state_switch();
    }
    else if(G_realtime_data.key_status == 0) /* LEDSW 有更高优先级 */
    {
        LOGD(L_APP, L_V5, "LEDSW OFF 状态，忽略");
        return;
    }
    else if(par == 1 && G_parameter.led_sleep != 3)
    {
        /* 退出休眠 */
        track_drv_led_sleep(1);
        led_state_switch();
    }

    return 0;
}

/******************************************************************************
 *  Function    -  track_cust_led_first_start
 *
 *  Purpose     -  启动时自动还原之前的状态
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 12-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_led_first_start(void)
{
    LOGD(L_APP, L_V5, "%d", G_realtime_data.key_status);

    if(g_GT03D)
    {
        if(!track_is_timer_run(TRACK_CUST_SOS_KEY_LED_ON_TIMER))
        {
            if(G_realtime_data.key_status == 0)
            {
                track_cust_led_sleep(2);
            }
        }
        return;
    }

    if(G_realtime_data.key_status == 0)
    {
        track_cust_led_sleep(2);
    }
#ifdef __NT31__
    if(G_realtime_data.key_status == 1 && G_parameter.led_sleep != 2 && track_cust_gps_status() == 0)
    {
        track_cust_led_sleep(2);
    }
    else if(G_realtime_data.key_status == 1 && G_parameter.led_sleep == 3)
    {
        track_cust_led_sleep(2);
    }
#endif /* __NT31__ */
}

/******************************************************************************
 *  Function    -  track_cust_led_acc_change_status
 *
 *  Purpose     -  ACC变化，LED需要3个LED同时闪烁一次
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 12-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_led_acc_change_status(kal_uint8 acc_status)
{
#if defined(__NF2318__)||defined(__SAME_GT02__)
#else
    LOGD(L_APP, L_V5, "led_status=%d, acc_status=%d ", led_status, acc_status);
    if(track_cust_module_call_status() == 0)
    {
        if(led_status == 2 || led_status == 1 || led_status == 3)
        {
            int i = 0;
            static led_loop_main_struct data = {0};
            led_status = 3;
            data.exit_function = led_acc_change_status_exit;
            /* 全 灭 500ms */
            data.leds[i].valid = KAL_TRUE;
            data.leds[i].delay = 500;
            i++;
            /* 全 亮 300ms */
            if(acc_status == 1)  // OFF -> ON
            {
                data.loop = 3;
                data.leds[i].valid = KAL_TRUE;
                data.leds[i].delay = 100;
                data.leds[i].status[LED_GSM] = KAL_TRUE;
                data.leds[i].status[LED_PWR] = KAL_TRUE;
                data.leds[i].status[LED_GPS] = KAL_TRUE;
                i++;
                data.leds[i].valid = KAL_TRUE;
                data.leds[i].delay = 500;
            }
            else  // ON -> OFF
            {
                data.loop = 5;
                data.leds[i].valid = KAL_TRUE;
                data.leds[i].delay = 100;
                data.leds[i].status[LED_GSM] = KAL_TRUE;
                data.leds[i].status[LED_PWR] = KAL_TRUE;
                data.leds[i].status[LED_GPS] = KAL_TRUE;
                i++;
                data.leds[i].valid = KAL_TRUE;
                data.leds[i].delay = 100;
                i++;
                data.leds[i].valid = KAL_TRUE;
                data.leds[i].delay = 100;
                data.leds[i].status[LED_GSM] = KAL_TRUE;
                data.leds[i].status[LED_PWR] = KAL_TRUE;
                data.leds[i].status[LED_GPS] = KAL_TRUE;
                i++;
                data.leds[i].valid = KAL_TRUE;
                data.leds[i].delay = 500;
            }
            track_drv_led_loop(&data);
        }
    }
    else
    {
        if(((g_GT03D && track_cust_status_defences() >= 1) || (!g_GT03D && track_cust_status_defences() == 2)) && led_status == 1)
        {
            led_status = 2;
        }
        else if(((g_GT03D && track_cust_status_defences() == 0) || (!g_GT03D && track_cust_status_defences() != 2)) && led_status == 2)
        {
            led_status = 1;
        }
    }
#endif
}

/******************************************************************************
 *  Function    -  track_cust_led_alarm
 *
 *  Purpose     -  触发报警事件，如果LED在设防状态下，暂时退出30秒，之后恢复
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 12-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_led_alarm(void)
{
#if defined(__SAME_GT02__) 
    return;
#endif
    LOGD(L_APP, L_V5, "led_status=%d", led_status);
    if(led_status != 4 && track_cust_module_call_status() == 0)
    {
        led_status = 4;
        LED_PWR_StatusSet(led_rgb_last_status[0]);
        LED_GSM_StatusSet(led_rgb_last_status[1]);
        LED_GPS_StatusSet(led_rgb_last_status[2]);
    }
    tr_start_timer(TRACK_CUST_LED_ALARM_TIMER, 30000, led_alarm_exit);
}

void track_cust_led_status_view(char *out)
{
    int len = 0;
    if(track_cust_module_call_status() != 0)
    {
        len = sprintf(out, "通话中\t");
        out += len;
    }
    switch(track_cust_status_defences())
    {
        case 0:
            len = sprintf(out, "撤防\t");
            break;
        case 1:
            len = sprintf(out, "预设防\t");
            break;
        case 2:
            len = sprintf(out, "设防\t");
            break;
    }
    out += len;
    switch(led_rgb_last_status[0])
    {
        case PW_ON_STATE:
            len = sprintf(out, "红灯:刚开机\t");
            break;

        case PW_CHARGING_STATE:
            len = sprintf(out, "红灯:充电中\t");
            break;

        case PW_OFF_STATE:
            len = sprintf(out, "红灯:关机\t");
            break;

        case PW_NORMAL_STATE:
            len = sprintf(out, "红灯:正常显示\t");
            break;

        case PW_LOW_ALARM_STATE:
            len = sprintf(out, "红灯:低电显示\t");
            break;

        case PW_FULLCHARGED_STATE:
            len = sprintf(out, "红灯:充满电\t");
            break;
    }
    out += len;
    switch(led_rgb_last_status[1])
    {
        case GSM_COMING_CALL_STATE:
            len = sprintf(out, "绿灯:有新的来电\t");
            break;

        case GSM_IN_CALL_STATE:
            len = sprintf(out, "绿灯:通话中\t");
            break;

        case GPRS_CONNECT_STATE:
            len = sprintf(out, "绿灯:连线中\t");
            break;

        case GSM_NO_SIGNAL_STATE:
            len = sprintf(out, "绿灯:GSM无信号\t");
            break;

        case GSM_OFF_STATE:
            len = sprintf(out, "绿灯:GSM关闭\t");
            break;

        case GSM_INITIAL_STATE:
            len = sprintf(out, "绿灯:GSM初始化\t");
            break;

        case GSM_NORMAL_STATE:
            len = sprintf(out, "绿灯:GSM正常\t");
            break;
    }
    out += len;
    switch(led_rgb_last_status[2])
    {
        case GPS_LOCATION_STATE:
            len = sprintf(out, "蓝灯:GPS已定位\t");
            break;

        case GPS_PWON_STATE:
            len = sprintf(out, "蓝灯:GPS开启\t");
            break;

        case GPS_INVALID_STATE:
            len = sprintf(out, "蓝灯:GPS关闭\t");
            break;

        case GPS_SCAN_STATE:
            len = sprintf(out, "蓝灯:GPS搜星\t");
            break;
    }
    out += len;
}

