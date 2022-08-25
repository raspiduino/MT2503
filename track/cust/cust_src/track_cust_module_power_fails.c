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
#include "track_os_ell.h"

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
static struct_msg_send g_msg = {0};

#if defined(__GERMANY__) 
static char *str_power_fails_en = "Stromversorgung unterbrochen! ";
static char *str_power_fails_en1 = "Stromversorgung unterbrochen!";
#elif defined(__SPANISH__)
static char *str_power_fails_en = "Corte de corriente!";
#else
static char *str_power_fails_en = "Cut off Power Alarm! ";
static char *str_power_fails_en1 = "Cut off Power Alarm!Please Attention!";
#endif

static kal_uint8 str_power_fails_cn[10] =    // 断电报警！
{
    0x65, 0xAD, 0x75, 0x35, 0x62, 0xA5, 0x8B, 0x66, 0xFF, 0x01
};

static track_gps_data_struct gps_data_buf = {0};
/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/
extern kal_uint8 g_alarm_gps_status;//报警记录报警期间GPS定位情况//0,不定位;1,定位
/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern void track_cust_key_led_sleep(void);
extern void track_instructions_get_paging(void);//20190916
/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

/******************************************************************************
 *  Function    -  track_cus_power_fails_overTime_sendsms
 *
 *  Purpose     -  断电报警发送短信
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void track_cus_power_fails_overTime_sendsms(void)
{
    track_gps_data_struct *gpsLastPoint = NULL;
    LOGD(L_APP, L_V5, "");
    if(G_parameter.power_fails_alarm.sw && G_parameter.power_fails_alarm.alarm_type)
    {
        memset(&g_msg, 0, sizeof(struct_msg_send));

        g_msg.addUrl = KAL_TRUE;
        g_msg.cm_type = CM_SMS;
        track_fun_strncpy(g_msg.msg_en, str_power_fails_en, CM_PARAM_LONG_LEN_MAX);
        g_msg.msg_cn_len = 10;
        memcpy(g_msg.msg_cn, str_power_fails_cn, g_msg.msg_cn_len);

        track_cust_module_alarm_msg_send(&g_msg, &gps_data_buf);
        if(G_parameter.power_fails_alarm.alarm_type == 2)
        {
            track_start_timer(TRACK_CUST_ALARM_power_fails_Call_TIMER, 60000, track_cust_make_call, (void*)1);
        }
        else
        {
            track_cust_module_alarm_lock(TR_CUST_ALARM_PowerFailure, 0);
        }
    }
    else
    {
        //track_cust_module_alarm_lock(TR_CUST_ALARM_PowerFailure, 0);
        LOGD(L_APP, L_V4, "断电报警，报警类型设置无需短信通知！");
    }
    //track_cust_module_alarm_set_type(0);
    track_alarm_vec_queue_remove(2, 0, TR_CUST_ALARM_PowerFailure);
}

#ifdef __NT31__
void track_power_fails_delay_timer(void)
{
        track_gps_data_struct *gpsLastPoint = NULL;
      if(!G_parameter.power_fails_alarm.sw)
      {
         return;
      }
        if(track_cust_status_charger())
        {
            LOGD(L_APP, L_V5, "已经充电，不再发送");
            return;
        }
        if(G_parameter.power_fails_alarm.send_alarm_time==0)
        {
            LOGD(L_APP, L_V5, "不在报低电报警");
           return;
        }
        if(G_realtime_data.power_fails_flg==0)
        {
         LOGD(L_APP, L_V5, "标志位不清楚，不报警");
          return;
        }
         if(!track_soc_login_status())
        {
          tr_start_timer(TRACK_CUST_POWER_FAILS_TIMER_ID, G_parameter.power_fails_alarm.send_alarm_time*1000, track_power_fails_delay_timer);
          return;
        }
        gpsLastPoint = track_cust_gpsdata_alarm();
        track_cust_paket_16(gpsLastPoint, track_drv_get_lbs_data(), TR_CUST_ALARM_PowerFailure, KAL_FALSE, 0);
         tr_start_timer(TRACK_CUST_POWER_FAILS_TIMER_ID, G_parameter.power_fails_alarm.send_alarm_time*1000, track_power_fails_delay_timer);
}
#endif /* __NT31__ */
#if defined(__NF2318__)
void track_cust_powerfail_alarm(U8 arg)
{
	static kal_uint8 iswrite = KAL_FALSE;
	kal_uint8 position = 0;
    if(arg == 1 && iswrite == KAL_FALSE)
    {
        track_cust_N07_paket_04(ALARM_CHARGE_OUT, 0x01);
		iswrite = KAL_TRUE;
		position = 1;
    }
    else if(arg == 0 && iswrite == KAL_TRUE)
    {
        track_cust_N07_paket_04(ALARM_CHARGE_OUT, 0x00);
		iswrite = KAL_FALSE;
		position = 1;
    }
	if(position == 1)
	{
		track_cust_paging_command();//上传定位点
		//track_instructions_get_paging();
	}
}

#endif
/******************************************************************************
 *  Function    -  power_fails
 *
 *  Purpose     -  触发断电报警动作
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void power_fails(void)
{
    track_gps_data_struct *gpsLastPoint = NULL;
    
    LOGD(L_APP, L_V5, "");

    if(!G_parameter.power_fails_alarm.sw)
    {
        return;
    }
    if(track_cust_module_alarm_lock(TR_CUST_ALARM_PowerFailure, 2) != 0)
    {
        LOGD(L_APP, L_V4, "上一断电报警请求未完成!");
        return;
    }
#if defined(__FLY_MODE__)
    track_cust_flymode_set(30);
#endif /*__FLY_MODE__*/    
    LOGD(L_APP, L_V4, "!!! 外电断开 !!!");
#if defined(__NF2318__)
	track_cust_powerfail_alarm(1);
	//track_cust_N07_paket_02(track_drv_get_gps_data(), track_drv_get_lbs_data());

#else	
    track_cust_led_alarm();
    track_cust_module_alarm_lock(TR_CUST_ALARM_PowerFailure, 1);
    gpsLastPoint = track_cust_gpsdata_alarm();

    memcpy(&gps_data_buf, gpsLastPoint, sizeof(track_gps_data_struct));
    if(track_cust_gps_status() > 2)
    {
        g_alarm_gps_status = 1;
    }
    if(G_parameter.gprson)
    {
        track_cust_paket_16(gpsLastPoint, track_drv_get_lbs_data(), TR_CUST_ALARM_PowerFailure, KAL_TRUE, 1);
    }

    if(G_parameter.power_fails_alarm.alarm_type > 0)
    {

        if(G_parameter.power_fails_alarm.alarm_type == 3)
        {
            track_alarm_vec_queue_remove(2, 0, TR_CUST_ALARM_PowerFailure);
            track_start_timer(TRACK_CUST_ALARM_power_fails_Call_TIMER, 10 * 1000, track_cust_make_call, (void*)1);
        }
        else
        {
            if(G_parameter.lang == 0 || G_parameter.gprson == 0)
            {
                track_os_intoTaskMsgQueue(track_cus_power_fails_overTime_sendsms);
            }
            else
            {
                if(track_is_timer_run(TRACK_CUST_ALARM_power_fails_OVERTIME_TIMER))
                {
                    LOGD(L_APP, L_V4, "上一断电报警请求未完成!");
                }
                else
                {
                    tr_start_timer(TRACK_CUST_ALARM_power_fails_OVERTIME_TIMER, TRACK_ALARM_DELAY_TIME_SECONDS, track_cus_power_fails_overTime_sendsms);
                }
            }
        }
    }
    else
    {
        track_cust_module_alarm_lock(TR_CUST_ALARM_PowerFailure, 0);
    }
#endif
#ifdef __NT31__
   G_realtime_data.power_fails_flg=1;
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
     tr_start_timer(TRACK_CUST_POWER_FAILS_TIMER_ID, G_parameter.power_fails_alarm.send_alarm_time*1000, track_power_fails_delay_timer);
#endif /* __NT31__ */

}

#if defined (__NT13V__) || defined (__NT17__)
void track_cust_pwrcut_alm_form_mcu(void)
{
    LOGD(L_APP, L_V4, "MCU 断电报警");
    track_os_intoTaskMsgQueue(power_fails);
}
#else
void track_cust_pwrcut_alm_form_mcu(void)
{

}
#endif /* __NT13V__ */
/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

/******************************************************************************
 *  Function    -  track_cust_module_power_fails
 *
 *  Purpose     -  断电报警判断
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 26-02-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_module_power_fails(void *arg)
{
    static kal_uint8 poweralm_filter = 1;
    static kal_uint8 T2 = 1;
    static kal_uint32 T3 = 0, last_tick = 0;
    kal_uint32 par = (kal_uint32)arg;
    kal_uint32 tick = 0;
    kal_bool valid = KAL_TRUE;
    
#if defined(__NETWORK_LICENSE__)
    LOGD(L_APP, L_V4, "par:%d __NETWORK_LICENSE__", par);
    return;
#endif
    if(!G_parameter.power_fails_alarm.sw)
    {
        return;
    }
    if(par == 21)/* ACC ON */
    {
        T3 = 0;
        last_tick = 0;
        LOGD(L_APP, L_V5, "清除断电报警保护时间");
        return;
    }
    tick = OTA_kal_get_systicks();
    if(par == 20)/* ACC OFF */
    {
        last_tick = tick + 217;
        T3 = tick + kal_secs_to_ticks(G_parameter.power_fails_alarm.delay_time_acc_on_to_off);
        LOGD(L_APP, L_V5, "更新断电报警保护时间 T3=%d, tick=%d", T3, tick);
        return;
    }
    LOGD(L_APP, L_V7, "par=%d, T2=%d, sw=%d, delay_time_on=%d, delay_time_off=%d, T3=%d, last_tick=%d, tick=%d, poweralm_filter:%d, delay_time_acc_on_to_off:%d",
         par, T2,
         G_parameter.power_fails_alarm.sw,
         G_parameter.power_fails_alarm.delay_time_on,
         G_parameter.power_fails_alarm.delay_time_off,
         T3, last_tick, tick, poweralm_filter,
         G_parameter.power_fails_alarm.delay_time_acc_on_to_off);
    switch(par)
    {
        case 0: // 断开充电
        case 1:
#if defined (__EXT_VBAT_ADC__) && !defined(__EXT_VBAT_Protection__) && !defined(__NT36__)&& !defined(__NT13V__) &&!defined(__NT17__)&&!defined(__NF2318__)
            if((track_drv_ext_disconnect() == KAL_FALSE))
            {
                if(G_realtime_data.disExtBattery2 == 1)
                {
                    G_realtime_data.disExtBattery2 = 0;
                    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
                }
                LOGD(L_APP, L_V5, "根据当前的外电压值，判断是因低电主动断开外电不触发断电报警");//因外电电压低，主动断开外电不触发断电报警
                break;
            }
#endif /* __EXT_VBAT_ADC__ */
            if(G_parameter.power_fails_alarm.delay_time_acc_on_to_off != 0 && T3 != 0 && tick < T3)
            {
                return;
            }
    
            if(T2 || poweralm_filter)//CJJ,20161029,解决第一次断电报警没有以T1时间为条件的BUG
            {
            	#if 0
                track_start_timer(
                    TRACK_CUST_MODULE_ALARM_POWER_FAILS_TIMER_ID,
                    G_parameter.power_fails_alarm.delay_time_off * 1000+10000,/* T1 参数时间 */
                    track_cust_module_power_fails,
                    (void*)10);
                #endif//根据需求断电报警的判断时间改为3秒
                track_start_timer(
                    TRACK_CUST_MODULE_ALARM_POWER_FAILS_TIMER_ID,
                    G_parameter.power_fails_alarm.delay_time_off * 1000,/* T1 参数时间 */
                    track_cust_module_power_fails,
                    (void*)10);
                #if !defined(__EXT_VBAT_Protection__)
                    track_at_vs_send("AT+EADC=1\r\n");
                #endif /* __ET310__ */

            }
            else
            {
                track_stop_timer(TRACK_CUST_MODULE_ALARM_POWER_FAILS_TIMER_ID);
            }
            if(G_realtime_data.netLogControl & 32)
            {
                cust_packet_log(32, 0, 0, 0, 0, 0, 0);
            }
            break;

        case 5: // 接入充电
        case 6:
#ifdef __NT31__
                    track_stop_timer(TRACK_CUST_POWER_FAILS_TIMER_ID);
#endif /* __NT31__ */

            track_start_timer(
                TRACK_CUST_MODULE_ALARM_POWER_FAILS_TIMER_ID,
                G_parameter.power_fails_alarm.delay_time_on * 1000,
                track_cust_module_power_fails,
                (void*)11);
            if(G_realtime_data.netLogControl & 32)
            {
                cust_packet_log(32, 1, 0, 0, 0, 0, 0);
            }
            T2 = 0;
            break;

        case 10: // 断开充电 确认
#if defined (__EXT_VBAT_ADC__) && !defined(__NT36__) && !defined(__EXT_VBAT_Protection__)&& !defined (__NT13V__) &&!defined (__NT17__)&&!defined(__NF2318__)
            if((track_drv_ext_disconnect() == KAL_FALSE))
            {
                LOGD(L_APP, L_V5, "根据当前的外电压值，判断是因低电主动断开外电不触发断电报警");//因外电电压低，主动断开外电不触发断电报警
                break;
            }
#endif /* __EXT_VBAT_ADC__ */

#if defined (__NT13V__) || defined (__NT17__)
                LOGD(L_APP, L_V5, "chr out");
                break;

#endif /* __NT13V__ */

            if(poweralm_filter ==1 )
            {
                track_os_intoTaskMsgQueue(power_fails);
                poweralm_filter = 0;
            }
            break;

        case 11: // 接入充电 确认
#if defined(__NF2318__)
			track_cust_powerfail_alarm(0);
			track_cust_N07_paket_02(track_drv_get_gps_data(), track_drv_get_lbs_data());
#endif

#if defined (__NT13V__)|| defined (__NT17__)
        track_cust_module_mcu_control_extbat(1);//解决首次上电单片机不上报的问题
#endif /* __NT13V__ */
        
            LOGD(L_APP, L_V5, "确认连接");
            T2 = 1;
            poweralm_filter =1;
            break;
    }
}



/******************************************************************************
 *  Function    -  track_cust_module_ext_voltage_values
 *
 *  Purpose     -  设备未接独立的ACC检测线，通过外电电压模拟判断ACC状态
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 12-08-2016,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_module_ext_voltage_values(kal_uint32 volt)
{
    static kal_uint32 lasttick = 0, jj = 0;
    kal_uint32 tick = kal_get_systicks();
    U8 acc = track_cust_status_acc();
    LOGD(L_APP, L_V7, "VOLT:%d,%d", volt, G_realtime_data.disExtBattery2);
    if(volt < 5000000)
    {
        if(lasttick == 0 || jj != 1)
        {
            lasttick = kal_get_systicks() + 3 * KAL_TICKS_1_SEC;
        }
        jj = 1;
        if(lasttick < tick)
        {
            if(acc)
            {
                LOGD(L_APP, L_V5, "ACC 高，等待ACC低才触发");
                return;
            }
            if(G_realtime_data.disExtBattery2 == 0)
            {
                track_cust_module_power_fails((void *)0);
                lasttick = 0;
                G_realtime_data.disExtBattery2 = 1;
                Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
            }

        }
    }
    else if(volt > 6000000)
    {
        if(lasttick == 0 || jj != 2)
        {
            lasttick = kal_get_systicks() + 3 * KAL_TICKS_1_SEC;
        }
        jj = 2;
        if(lasttick < tick)
        {
            if(G_realtime_data.disExtBattery2 == 1)
            {
                track_cust_module_power_fails((void *)5);
                lasttick = 0;
                G_realtime_data.disExtBattery2 = 0;
                Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
            }

        }
    }
}
