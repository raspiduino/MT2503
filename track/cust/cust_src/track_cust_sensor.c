/*******************************************************************************************
 * Filename:
 * Author :
 * Date :
 * Comment:
 ******************************************************************************************/

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "track_cust.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static kal_bool gSensor_shocked_valid = KAL_FALSE;

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern void track_cust_intermittent_send_LBS(void *arg);
/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
kal_uint8 track_cust_sensor_count(kal_uint8 par);

/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

/******************************************************************************
 *  Function    -  track_sensor_shocked_valid_timeout
 *
 *  Purpose     -  Sensor长时间未检测到震动，开始进入静止
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void track_sensor_shocked_valid_timeout(void)
{
    gSensor_shocked_valid = KAL_FALSE;
    LOGD(L_APP, L_V5, "进入静止状态");
    track_project_enters_quiescent_state_notify();
}


/******************************************************************************
 *  Function    -  xzx_sensor_callback_work
 *
 *  Purpose     -  sensor检测震动后回调函数
 *
 *  Description -  return Null
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 21-07-2012,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
static void sensor_callback_work(void)
{
    if(track_is_testmode())
    {
        LOGS("SENSOR OK3#");//白卡自动进测试模式，但震动不会亮LED  chengj
    }
    else
    {
        LOGD(L_APP, L_V4, "检测到震动");
        //track_project_hallsig_out();
    }

    if(track_project_gsensor_shocked_event() == 0)
    {
        return;
    }

    if(track_cust_status_defences() == 2 && track_is_in_call() && G_parameter.callmode > 0 && track_get_incall_type() == 1)
    {
        LOGD(L_APP, L_V5, "设防来电震动返回");
        return;
    }

    if(G_realtime_data.power_saving_mode == 1 || (g_GT03D == KAL_TRUE && track_cust_get_work_mode() == WORK_MODE_1 && track_cust_status_defences() == 0))
    {
        tr_stop_timer(TRACK_CUST_MODULE_ALARM_VIBRATES_DELAY_TIMER_ID);
        LOGD(L_APP, L_V6, "省电模式直接返回");
        return;
    }
    track_cust_sensor_count(1);
    gSensor_shocked_valid = KAL_TRUE;
	
#if defined(__NF2318__)
	track_cust_is_shock();
	//track_cust_vehicle_moving(1);
#endif
    if(G_parameter.gps_work.static_filter_sw & 4)
    {
        tr_start_timer(TRACK_CUST_SENSOR_DELAY_VALID_TIMER_ID, 30000, track_sensor_shocked_valid_timeout);
    }
    else
    {
        tr_start_timer(TRACK_CUST_SENSOR_DELAY_VALID_TIMER_ID, 300000, track_sensor_shocked_valid_timeout);
    }

    track_cust_sensor_add_position((void*)0);

    track_cust_module_gps_vibrates_wake();

	if(!track_is_timer_run(TRACK_CUST_LEASE_OFF_NO_ALARM_TIMER_ID))
	{
    	track_cust_module_alarm_vibrates((void *)1);
		track_cust_vibrates_voice_alarm((void*)1);
	}
    track_cust_periodic_restart((void*)1);
    //track_motor_lock_change_status(MOTOR_SENSOR_IND);
}

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

/******************************************************************************
 *  Function    -  track_cust_sensor_count
 *
 *  Purpose     -  Sensor振动累计计数
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_uint8 track_cust_sensor_count(kal_uint8 par)
{
    static kal_uint8 count = 0;
    kal_uint8 tmp;
    if(par == 1)
    {
        // 累加计数
        count++;
        tmp = count;
    }
    else if(par == 2)
    {
        // 查询返回值
        tmp = count;
    }
    else if(par == 3)
    {
        // 返回且清零
        tmp = count;
        count = 0;
    }
    return tmp;
}

/******************************************************************************
 *  Function    -  track_cust_is_sensor_shocked_valid
 * 
 *  Purpose     -  查询是否处于振动有效期内
 * 
 *  Description -  TRUE=刚发生了震动 或GPS得常开模式
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-12,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_bool track_cust_is_sensor_shocked_valid()
{
    if(G_parameter.sensor_gps_work == 0)
    {
        return  TRUE;
    }
    return gSensor_shocked_valid;
}


/******************************************************************************
 *  Function    -  track_cust_sensor_init
 *
 *  Purpose     -  sensor初始化处理函数
 *
 *  Description -  return Null
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 21-07-2012,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
 extern void track_cust_driver_behaviour();
void track_cust_sensor_init(void)
{
    kal_int8 sensor_l = 0;
    if(track_is_testmode())
    {
        return;
    }
    sensor_l = G_parameter.vibrates_alarm.sensitivity_level;
    LOGD(L_APP, L_V5, "sensitivity level:%d,%d", G_parameter.vibrates_alarm.sensitivity_level, sensor_l);
    track_drv_sensor_on(sensor_l, sensor_callback_work) ;
}

