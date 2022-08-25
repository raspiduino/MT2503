/******************************************************************************
 * track_factory_test.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        工厂测试模式
 *
 * modification history
 * --------------------
 * v1.0   2012-08-18,  wangqi create this file
 *
 ******************************************************************************/
/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/
#include "track_cmd.h"
//#include "track_os_call.h"
#include "track_drv_led.h"
#include "track_drv_eint_gpio.h"
#include "track_at_context.h"
#include "GlobalConstants.h"
#include "track_at_call.h"
#include "Track_at.h"
/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/
#define PWRLED 0
#define GSMLED 1
#define GPSLED 2

#define __OIL_CUT__
/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/
#define  TEST_KEY_MAX    4
/*****************************************************************************
*  Struct			    数据结构定义
*****************************************************************************/
typedef struct
{
    LED_Mode PWR_LED;
    LED_Mode GPS_LED;
    LED_Mode GSM_LED;
} LED_SATAUS;
/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/

/****************************************************************************
* Global Variable           全局变量
*****************************************************************************/
static LED_SATAUS last_mode = {0};
/*****************************************************************************
 *  Local Functions	            本地函数
*****************************************************************************/

kal_uint32 track_test_acc_flag(kal_uint32 flag);
static void track_ft_led_off(LED_Type Type);
kal_uint8 key_flag[TEST_KEY_MAX] = {0};
/*****************************************************************************
 *  Global Functions            全局函数
*****************************************************************************/
extern void ControlVibration(void);


static void track_ft_led_on(LED_Type Type)
{
    if (Type < LED_Num1 || Type > LED_Num_Max)
    {
        LOGC(L_TEST, L_V4, "track_ft_led_on Type Error!");
        return;
    }
    track_drv_led_status_lock(0);

    if (Type == LED_Num_Max)
    {
        track_drv_led_set_all_on();
    }
    else
    {
        track_drv_led_set_status(Type, LedMode_ON);
    }
    track_drv_led_status_lock(1);

}


static void led_site_restoration(void)
{
    track_ft_led_off(LED_Num_Max);
}

static void track_ft_led_off(LED_Type Type)
{
    if (Type < LED_Num1 || Type > LED_Num_Max)
    {
        LOGC(L_TEST, L_V4, "track_ft_led_on Type Error!");
        return;
    }
    track_drv_led_status_lock(0);

    if (Type == LED_Num_Max)
    {
        track_drv_led_set_all_off();
    }
    else
    {
        track_drv_led_set_status(Type, LedMode_OFF);
    }
    track_drv_led_status_lock(1);

}
void track_makecall_test(CMD_DATA_STRUCT * Cmds)
{
    LOGC(L_TEST, L_V4, "track_makecall_test= %d", Cmds->part);
    if (Cmds->part == 1)
    {
        LOGC(L_TEST, L_V4, "track_makecall_test= %s", Cmds->pars[1]);
        track_drv_sys_l4cuem_set_audio_mode(track_status_audio_mode(0xFF));
        track_make_call((char *) Cmds->pars[1]);
    }
    else
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");
    }
}
/******************************************************************************
 * FUNCTION:  - track_set_testmode(kal_bool mode)
 * DESCRIPTION: - 设置当前是否是测试模式
 * Input:
 * Output:
 * Returns:
 * modification history
 * --------------------
 * v1.0  , 18-08-2012,  ZengPing & Liujw  written
 * --------------------
 ******************************************************************************/
void track_set_testmode(kal_uint8 mode)
{
    track_drv_uart_log_mode(2);
    track_status_test(1);
    track_ft_led_off(LED_Num_Max);
    LOGC(L_TEST, L_V4, "track_set_testmode = %d", track_status_test(2));
}

kal_bool track_is_testmode(void)
{
    return track_status_test(2);
}

void track_query_sim_type(kal_int8 sim_type)
{
    if (sim_type == 2)
    {
        track_set_testmode(1);
    }
}
extern void track_send_at_accept_call(void);
void track_TM_call_status_change(kal_uint16 callType, kal_uint16 callState)
{
    LOGD(L_TEST, L_V5, "type:%d,status:%d", callType, callState);
    if (callType == CALL_MT_IN)
    {
        switch (callState)
        {
                LOGD(L_TEST, L_V5, "2 type:%d,status:%d", callType, callState);
            case TR_CALL_RING:
                LOGD(L_TEST, L_V5, "3 type:%d,status:%d", callType, callState);
                track_ft_led_off(LED_Num_Max);

                track_send_at_accept_call();

                custom_cmd_send("RING_OK", KAL_FALSE);//RING
                break;
            case TR_CALL_CONNECT:
                track_drv_led_set_status(GSMLED, LedMode_ON);
                custom_cmd_send("THROUGH", KAL_FALSE);
                break;
            case TR_CALL_DISCONNECT:
                custom_cmd_send("DISCONNECT", KAL_FALSE);
                break;
            default:
                break;
        }
    }
    else if (callType == CALL_MO_OUT)
    {
        switch (callState)
        {
            case TR_CALL_RING:
                track_ft_led_off(LED_Num_Max);
                custom_cmd_send("RING_OK", KAL_FALSE);
                break;
            case TR_CALL_CONNECT:
                track_ft_led_off(LED_Num_Max);
                track_ft_led_on(GSMLED);
                custom_cmd_send("THROUGH", KAL_FALSE);
                break;
            case TR_CALL_DISCONNECT:
                custom_cmd_send("DISCONNECT", KAL_FALSE);
                break;
            default:
                break;
        }
    }
}
void track_cust_call_status_change_test(void* msg)
{
    call_state_struct *ptr = (call_state_struct *) msg;
    kal_uint16 _type = ptr->type;/*call_type_enum*/
    kal_uint16 callState = ptr->status;/*track_call_state_enum*/
    LOGD(L_TEST, L_V5, "type:%d,status:%d", ptr->type, ptr->status);

    track_TM_call_status_change(_type, callState);
}

static void Sensor_Callback_Test(void)
{
    custom_cmd_send("Sensor_OK", KAL_FALSE);
    track_ft_led_on(LED_Num_Max);
    tr_start_timer(TRACK_FACTORY_RSTORE_LED_TIME_ID, 1000, led_site_restoration);
}

void track_cust_sensor_test_init(void)
{
    LOGC(L_TEST, L_V4, "SENSOR INIT#");
    track_drv_sensor_on(3, Sensor_Callback_Test);
}

/******************************************************************************
 *  Function    -  track_test_acc_flag
 *
 *  Purpose     -  得出当前ACC状态
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 08-03-2013,  ZengPing & Liujw  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint32 track_test_acc_flag(kal_uint32 flag)
{
    static int status = 0;
    if (flag == 0 || flag == 1)
    {
        status = flag;
    }
    return status;
}
/******************************************************************************
 *  Function    -  track_test_acc_high_mode *
 *  Purpose     -  acc 高处理函数 *
 *  Description -  return Null *
 *  modification history
 * ----------------------------------------
 * v1.0  , 18-08-2012,  ZengPing & Liujw  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_acc_high_mode(void)
{
    LOGC(L_TEST, L_V4, "ACC IS HIGH ^ Realys ON");
    track_stop_timer(TRACK_FACTORY_RSTORE_LED_TIME_ID);
    LOGS("ACC_H");
    track_test_acc_flag(1);
}
/******************************************************************************
 *  Function    -  track_test_acc_low_mode *
 *  Purpose     -  acc 低处理函数 *
 *  Description -  return Null *
 *  modification history
 * ----------------------------------------
 * v1.0  , 18-08-2012,  ZengPing & Liujw  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_acc_low_mode(void)
{
    LOGC(L_TEST, L_V4, "ACC IS LOW V Realys OFF");
    custom_cmd_send("ACC_L", KAL_FALSE);
    track_test_acc_flag(0);
}

/******************************************************************************
 *  Function    -  track_test_acc_status_set *
 *  Purpose     -  acc 状态处理函数 *
 *  Description -  return Null *
 *  modification history
 * ----------------------------------------
 * v1.0  , 18-08-2012,  ZengPing & Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_test_set_acc_status(kal_uint8 status)
{
    LOGC(L_TEST, L_V4, "%d", status);
    if (status)
    {
        tr_start_timer(TRACK_FACTORY_ACC_CHECK_TIME_ID, 500, track_test_acc_low_mode);
    }
    else
    {
        tr_start_timer(TRACK_FACTORY_ACC_CHECK_TIME_ID, 500, track_test_acc_high_mode);
    }
}
/******************************************************************************
 *  Function    -  track_test_acc_status_set *
 *  Purpose     -  车轮 状态处理函数 *
 *  Description -  return Null *
 *  modification history
 * ----------------------------------------
 * v1.0  , 15-12-2017,  Cjj  written
 * ----------------------------------------
 ******************************************************************************/
void track_autotest_set_wheel_status(kal_uint8 status)
{
    LOGC(L_TEST, L_V4, "%d", status);
    if(status)
    {
        LOGS("wheel_L");
    }
    else
    {
        LOGS("wheel_H");
    }
}

void track_test_set_key_status(kal_uint8 eintno, kal_uint8 status)
{
    LOGC(L_TEST, L_V4, "%d,%d", eintno, status);
    if (status == 1)
    {
    #if defined(__NF2318__)
	        LOGS("EINT%d_H", eintno);
	#else
        track_ft_led_off(LED_Num_Max);
        LOGS("EINT:%d,LEVEL:%d,KEY_OFF", eintno, status);
		#endif
    }
    else
    {
    
#if defined(__NF2318__)
		LOGS("EINT%d_L", eintno, status);
#else
        track_ft_led_on(LED_Num_Max);
        LOGS("EINT:%d,LEVEL:%d,KEY_ON", eintno, status);
		#endif
    }
}

/******************************************************************************
 *  Function    -  track_test_Akey_high_mode *
 *  Purpose     -   高处理函数 *
 *  Description -  return Null *
 *  modification history
 * ----------------------------------------
 * v1.0  , 18-08-2012,  ZengPing & Liujw  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_Akey_high_mode(void)
{
    LOGC(L_TEST, L_V4, "KEY IS HIGH ^ LED ON ");
    //track_save_scene();
    track_ft_led_on(LED_Num_Max);
    track_cust_sensor_test_init();
}
/******************************************************************************
 *  Function    -  track_test_Akey_low_mode *
 *  Purpose     -   低处理函数 *
 *  Description -  return Null *
 *  modification history
 * ----------------------------------------
 * v1.0  , 18-08-2012,  ZengPing & Liujw  written
 * ----------------------------------------
 ******************************************************************************/
static void track_test_Akey_low_mode(void)
{
    //LOGC(L_TEST, L_V4, "KEY IS LOW V LED OFF ");
    track_ft_led_off(LED_Num_Max);

}
static void track_test_key_set_callback(void)
{
    static kal_uint32 key_flag = 0;
    LOGC(L_TEST, L_V4, "KEY IS LOW V LED OFF ");
    if (key_flag == 0)
    {
        track_ft_led_on(LED_Num_Max);
        LOGS("LEDKEY_ON");
        key_flag = 1;
    }
    else
    {
        track_ft_led_off(LED_Num_Max);
        LOGS("LEDKEY_OFF");
        key_flag = 0;
    }
}
static void cmd_test_set_keyflag(kal_uint32 key)
{
    int i = 0;
    LOGD(L_TEST, L_V4, "");
    if (key == 99)
    {
        memset(&key_flag, 0, sizeof(key_flag));
    }
    else if (key == 88)
    {
        for (i = 0; i < TEST_KEY_MAX; i++)
        {
            if (key_flag[i] == 0)
            {
                return;
            }
        }
        LOGS("KEY_ALL_OK");
        ControlVibration();
    }
    else
    {
        key_flag[key] = 1;
    }
}
static void track_test_key0_set_callback(void)
{
    cmd_test_set_keyflag(0);
    LOGD(L_TEST, L_V4, "");
    LOGS("KEY0_OK");
    cmd_test_set_keyflag(88);
}
static void track_test_key1_set_callback(void)
{
    cmd_test_set_keyflag(1);
    LOGD(L_TEST, L_V4, "");
    LOGS("KEY1_OK");
    cmd_test_set_keyflag(88);
}
static void track_test_key2_set_callback(void)
{
    cmd_test_set_keyflag(2);
    LOGD(L_TEST, L_V4, "");
    LOGS("KEY2_OK");
    cmd_test_set_keyflag(88);
}
static void track_test_key3_set_callback(void)
{
    cmd_test_set_keyflag(3);
    LOGD(L_TEST, L_V4, "");
    LOGS("KEY3_OK");
    cmd_test_set_keyflag(88);
}
static void cmd_test_allkey(void)
{

}
void track_test_key_set_init(void)
{
#if defined(__KEYPAD_MOD__)
 //   track_drv_set_key_handler(track_test_key_set_callback, KEY_SOS, KEY_EVENT_DOWN);
#endif /* __KEYPAD_MOD__ */
}

void track_testmode_eint_handler(U8 eint, U8 level)
{
    switch (eint)
    {
        #if ACC_EINT_NO!=GPIO_EINT_NO_USE
        {
        case ACC_EINT_NO:
            track_test_set_acc_status(level);
            break;
        }
        #endif
        
#if defined (__WHEEL_CHECK__)
        #if EXTRA_WHEEL_EINT_NO!=GPIO_EINT_NO_USE
        {
        case EXTRA_WHEEL_EINT_NO:
            track_autotest_set_wheel_status(level);
            break;
        }
        #endif
#endif /* __WHEEL_CHECK__ */
  
        default:
            if(eint!=GPIO_EINT_NO_USE)
            {
                track_test_set_key_status(eint, level);
            }
            break;
    }
}
void track_test_ALLLED(char* part)
{
    if (strcmp((S8*)part, "ON") == 0)
    {
        track_ft_led_on(LED_Num_Max);
        LOGS("ALLLED_ON_OK");
    }
    else if (strcmp((S8*)part, "OFF") == 0)
    {
        track_ft_led_off(LED_Num_Max);
        LOGS("ALLLED_OFF_OK");
    }
}


/******************************************************************************
 *  Function    -  track_factoty_autotest_gps_fix_time_output
 *
 *  Purpose     -  自动化GPSTC时间查询
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 26-02-2013,  ZengPing  written
 * ----------------------------------------
 *
 *  说明:使用本地时间差计算定位时间，因为GPS定位后校准时间，部分代码必须按固定顺序，否则计算错误
 *  改用开机tick计算则没有关联，不存在顺序问题
 *
 * v2.0  , 16-05-2013,  ZengPing & Liujw  written 
 * ----------------------------------------
 ******************************************************************************/
void track_factoty_autotest_gps_fix_time_output(kal_uint32 output)
{
    static kal_uint32 start_tick=0;
    kal_uint32 fix_tick,time_diff = 0;
    static kal_int8 buffer[100];
    static kal_uint32 gpscold_flag = 0;
    static kal_int8 starttimebuff[100];
    static kal_int8 fixtimebuff[100];

    if((gpscold_flag == 0 && output != 0) || (gpscold_flag == 2 &&  output == 1))
    {
        return;
    }
    LOGC(L_TEST, L_V4, "output = %d ;gpscold_flag =%d", output, gpscold_flag);
    if(output == 0)//初始设置
    {
        start_tick= kal_get_systicks( );
        gpscold_flag = 1;
    }
    else if(gpscold_flag == 1 && output == 2)//未定位时做查询,回显未定位时间
    {
        fix_tick= kal_get_systicks( );
        time_diff = kal_ticks_to_secs(fix_tick-start_tick);
        memset(buffer, 0, sizeof(buffer));
        sprintf((char *)buffer, "GPS positioning satellite (cold TTFF=%ds) ", time_diff);
        LOGS("%s", buffer);
    }
    else if(gpscold_flag == 1 && output == 1)//定位自动保存耗费时间
    {
        fix_tick= kal_get_systicks( );
        time_diff = kal_ticks_to_secs(fix_tick-start_tick);        
        memset(buffer, 0, sizeof(buffer));
        sprintf((char *)buffer, "FSTTIME_%d#", time_diff);
        gpscold_flag = 2;
        LOGS("GPS_STATE_OK");
    }
    else if(gpscold_flag == 2 && output == 2)//回显查询时间
    {
        LOGS("%s", buffer);
    }
    else// if(gpscold_flag == 0 && output == 2)//未下发冷启指令,直接查询
    {
        LOGS("GPSCOLD_ERROR");
    }

}
kal_uint32 track_factoty_autotest_gpscold_setmode(kal_uint32 mode)
{
    static kal_uint32 mode_flag = 0;
    if(mode == 0 || mode == 1)
    {
        mode_flag = mode;
    }
    return mode_flag;
}

void track_factoty_autotest_gpscold_ttff(void)
{
    if(track_factoty_autotest_gpscold_setmode(3) == 1)
    {
        track_factoty_autotest_gpscold_setmode(0);
        track_factoty_autotest_gps_fix_time_output(1);
    }
}

