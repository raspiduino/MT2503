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
//#include "Conversions.h"

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
//Your Vehicle's Speed: 50km/h, Please Check!

static kal_uint8 str_speed_limit_cn[48] =   //车辆超速！速度 KM/H,请减速慢行，安全驾驶！
{
    0x8F, 0x66, 0x8F, 0x86, 0x8D, 0x85, 0x90, 0x1F, 0xFF, 0x01, 0x90, 0x1F, 0x5E, 0xA6, 0x00, 0x20,
    0x00, 0x4B, 0x00, 0x4D, 0x00, 0x2F, 0x00, 0x48, 0x00, 0x2C, 0x8B, 0xF7, 0x51, 0xCF, 0x90, 0x1F,
    0x61, 0x62, 0x88, 0x4C, 0xFF, 0x0C, 0x5B, 0x89, 0x51, 0x68, 0x9A, 0x7E, 0x9A, 0x76, 0xFF, 0x01
};
//车辆已超速(68km/h)，请减速慢行，安全驾驶！
static kal_uint8 str_2_1[12] =
{
    0x8F, 0x66, 0x8F, 0x86, 0x5D, 0xF2, 0x8D, 0x85, 0x90, 0x1F, 0x00, 0x28
};
static kal_uint8 str_2_2[34] =
{
    0x00, 0x6B, 0x00, 0x6D, 0x00, 0x2F, 0x00, 0x68, 0x00, 0x29, 0xFF, 0x0C, 0x8B, 0xF7, 0x51, 0xCF,
    0x90, 0x1F, 0x61, 0x62, 0x88, 0x4C, 0xFF, 0x0C, 0x5B, 0x89, 0x51, 0x68, 0x9A, 0x7E, 0x9A, 0x76,
    0xFF, 0x01
};
static track_gps_data_struct gps_data_tmp = {0};
static float g_max_speed = 0;
static kal_uint8 speed_limit_status = 0;
static kal_uint8 ringPlay = 0;
static U32 maxTime = 0;
static U32 currTime = 0;
//20190916
static kal_uint8 speelt_sta = 0;
/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
//20190916
extern void Substantiv_voice_id(kal_uint8 voice_sta);
extern kal_uint8 track_get_voice_numid_sta(void);
kal_uint8 track_cust_get_speelt_sta(kal_uint8 value);
/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/

#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/
void track_cust_module_speed_limit_cmd_update(void);

/******************************************************************************
 *  Function    -  speed_limit_overTime
 *
 *  Purpose     -  发送超速报警短信
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void speed_limit_overTime(void *arg)
{
    LOGD(L_APP, L_V5, "");
    if(!G_parameter.speed_limit_alarm.alarm_type || G_parameter.speed_limit_alarm.alarm_type == 3)
    {
        LOGD(L_APP, L_V4, "超速报警，报警类型设置无需短信通知！");
    }
    else
    {
        struct_msg_send g_msg = {0};
        char tmp[100] = {0};
        int len;
        kal_uint32 speed = (kal_uint32)arg;
        g_msg.addUrl = KAL_FALSE;
        g_msg.cm_type = CM_SMS;
#if defined(__GERMANY__)
       snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Geschwindigkeit zu hoch!");
#else
        snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Speeding! The speed of %dKM/H, please slow down, drive safely!", speed);
#endif
        snprintf(tmp, 50, "%d", speed);
        memcpy(g_msg.msg_cn, str_speed_limit_cn, 16);
        len = track_fun_asc_str_to_ucs2_str(&g_msg.msg_cn[16], tmp) - 2;
        g_msg.msg_cn_len = len + 48;
        if(CM_PARAM_LONG_LEN_MAX > g_msg.msg_cn_len)
        {
            memcpy(&g_msg.msg_cn[16+len], &str_speed_limit_cn[16], 32);
            track_cust_module_alarm_msg_send(&g_msg, NULL);
        }
    }
    if(G_parameter.speed_limit_alarm.alarm_type  == 2 || G_parameter.speed_limit_alarm.alarm_type  == 3)
    {
        track_start_timer(TRACK_CUST_ALARM_LowBattery_Call_TIMER, 60000, track_cust_make_call, (void*)1);
    }
    track_alarm_vec_queue_remove(2, 0, TR_CUST_ALARM_Speed_Limit);
}
void speed_selice()
{
	LOGD(L_APP, L_V5, "超速语音静默时间到");
}
void speed_time_max()
{
	G_parameter.osd.osdmaxstatus = 1;
	track_cust_module_speed_limit_cmd_update();
}
//---------设置MP3音量
 extern void track_set_on_off_volume(kal_uint8 value);
void speed_voice_play()
{
	kal_uint8 ringIDHex[3];
	kal_uint8 voiceIDHex[3];
	int playresult = 0;
	char GPIO_S = 0; 
	GPIO_S = GPIO_ReadIO(EINT_A_GPIO);
    LOGD(L_APP, L_V5, "GPIO_S:%d,ringPlay:%d,maxTime:%d,G_parameter.osd.osdtimemax:%d,lease:%d,acc:%d,defense:%d",GPIO_S,ringPlay,maxTime,G_parameter.osd.osdtimemax,G_parameter.ste_status.lease,track_cust_status_acc(),G_realtime_data.defences_status);
	//撤防或者ACC故障导致的控制器无输出，会导致一直报警,目前只考虑撤防的情况.问题已经复现，增加开锁状态如果acc为低，则不判断超速
	//if(ringPlay == 2 && (G_realtime_data.defences_status == 1 || (G_parameter.ste_status.lease == 1 && track_cust_status_acc() == 0)))
	if(ringPlay == 2 && (G_realtime_data.defences_status == 1 || GPIO_S == 1))
	{
		track_cust_module_speed_limit_cmd_update();
		return;
	}
	if(ringPlay == 0 || ringPlay == 2)
	{
		if(ringPlay == 0)
		{
			ringPlay = 1;
		}
		if(G_parameter.osd.osdtimemax != 0 && (maxTime/60) >= G_parameter.osd.osdtimemax)
		{
			currTime = 0;
			G_parameter.osd.osdmaxstatus = 1;
			track_cust_module_speed_limit_cmd_update();
		}
		memcpy(ringIDHex, &G_parameter.osd.osdringid, 3);
		if((ringIDHex[2] == 0x0F && ringIDHex[0] == 0 && ringIDHex[1] == 0) || !AUDIO_id_macth(ringIDHex))
		{
			play_voice(13);
		}
		else
		{	if(track_set_audio_file_play(99)==0)
        	{
            	track_set_audio_file_play(1);
            	track_set_on_off_volume(6);
				playresult = AUDIO_file_play(ringIDHex);
				if(playresult)
				{
					//track_set_audio_file_play(0);
					Substantiv_voice_id(track_get_voice_numid_sta());
				}
			}
		}
	}
	else if(ringPlay == 1)
	{
		ringPlay = 2;
		memcpy(voiceIDHex, &G_parameter.osd.osdvoiceid, 3);
		if((voiceIDHex[2] == 0x0E && voiceIDHex[0] == 0 && voiceIDHex[1] == 0) || !AUDIO_id_macth(voiceIDHex))
		{
			play_voice(14);
		}
		else
		{
			if(track_set_audio_file_play(99)==0)
			{
				track_set_audio_file_play(1);
				track_set_on_off_volume(6);
				playresult = AUDIO_file_play(voiceIDHex);
				if(playresult)
				{
					//track_set_audio_file_play(0);
					Substantiv_voice_id(track_get_voice_numid_sta());
				}
			}
		}
	}
}
/******************************************************************************
 *  Function    -  speed_over_ind
 *
 *  Purpose     -  确定触发超速报警
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void speed_over_ind(void)
{
    kal_uint32 sp =  g_max_speed;
    LOGD(L_APP, L_V5, "%d时间到，超速报警", kal_ticks_to_secs(kal_get_systicks()));

    g_max_speed = 0;
    speed_limit_status = 2;
#if defined(__NF2318__)
	speed_voice_play();
	if(G_parameter.osd.osdtimemax != 0)
	{
		currTime = kal_get_systicks();
		tr_start_timer(TRACK_CUST_SPEED_LIMIT_MAXTIME_TIME_ID, G_parameter.osd.osdtimemax * 1000, speed_time_max);
	}
#else
    if(G_parameter.gprson)
    {
        /*超速报警只需通知平台，无需等待平台返回的地址*/
        track_cust_paket_16(&gps_data_tmp, track_drv_get_lbs_data(), TR_CUST_ALARM_Speed_Limit, KAL_FALSE, 0);

    }
    speed_limit_overTime((void*)sp);
#endif
}

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

/******************************************************************************
 *  Function    -  track_cust_module_speed_limit
 *
 *  Purpose     -  判断是否超速？
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_module_speed_limit(track_gps_data_struct *gps_data,kal_uint8 tmpspeed)
{
	kal_uint32 tick = OTA_kal_get_systicks();
	kal_uint8 sw = G_parameter.osd.osdswitch;
	kal_uint8 threshold = G_parameter.osd.osdspeed;
	
	LOGD(L_APP, L_V5, "%d,%d,%d,%d,%d",G_parameter.osd.osdtimemax,G_parameter.osd.osdmaxstatus,tmpspeed,speed_limit_status,maxTime);
#if 0
	if(gps_data != NULL)
	{
		LOGD(L_APP, L_V1,"有GPS数据过来，NF2318不需要");
		return;
	}
#endif
	if(G_parameter.osd.osdtimemax != 0 && (maxTime >= G_parameter.osd.osdtimemax))
	{
		G_parameter.osd.osdmaxstatus = 1;
		track_cust_module_speed_limit_cmd_update();
	}
	LOGD(L_APP, L_V5, "%d,%d,%d,%d",sw,G_parameter.osd.osdswitch,ringPlay,threshold);
    if(sw == 0 || G_parameter.osd.osdmaxstatus == 1)
    {
        return;
    }
/*	if(track_is_timer_run(TRACK_CUST_SPEED_LIMIT_SILENCE_TIME_ID))
	{
		LOGD(L_APP, L_V5, "超速语音静默时间");
		return;
	}
	*/
    if(sw)
    {
        //if((tmpspeed == 0 && gps_data != NULL && gps_data->status >= 2 && gps_data->gprmc.Speed >= threshold) || (tmpspeed != 0 && tmpspeed >= threshold))
        if(tmpspeed != 0 && tmpspeed >= threshold)
        {
            if(speed_limit_status != 2)
            {
				g_max_speed = tmpspeed;
            }
            if(speed_limit_status == 0 && !track_is_timer_run(TRACK_CUST_ALARM_speed_limit_OVERTIME_TIMER))
            {
                LOGD(L_APP, L_V5, "%d,%d已超速，计时开始", kal_ticks_to_secs(kal_get_systicks()), G_parameter.speed_limit_alarm.delay_time);
                speed_limit_status = 1;
                tr_start_timer(
                    TRACK_CUST_ALARM_speed_limit_OVERTIME_TIMER,
                    G_parameter.speed_limit_alarm.delay_time * 1000,
                    speed_over_ind);
            }
        }
        else
        {
        	if(currTime != 0)
        	{
        		maxTime += kal_ticks_to_secs(tick - currTime);
				currTime = 0;
        	}
        	//LOGD(L_APP, L_V5, "------------>>>33333  %d %d",track_is_timer_run(TRACK_CUST_ALARM_speed_limit_OVERTIME_TIMER),speed_limit_status);
			if(speed_limit_status == 2)
			{
				track_cust_get_speelt_sta(0x00);
            	Substantiv_voice_id(track_get_voice_numid_sta());//超速报警完了之后看是否有缓存语音
				;//tr_start_timer(TRACK_CUST_SPEED_LIMIT_SILENCE_TIME_ID, G_parameter.osd.osdtimeinterval*60*1000, speed_selice);
			}
            speed_limit_status = 0;
			ringPlay = 0;
			tr_stop_timer(TRACK_CUST_SPEED_LIMIT_MAXTIME_TIME_ID);

            if(track_is_timer_run(TRACK_CUST_ALARM_speed_limit_OVERTIME_TIMER))
            {
                LOGD(L_APP, L_V5, "速度恢复正常，计时终止开始");
                track_stop_timer(TRACK_CUST_ALARM_speed_limit_OVERTIME_TIMER);
                g_max_speed = 0;
                

            }
        }
    }
}

/******************************************************************************
 *  Function    -  track_cust_module_speed_limit_cmd_update
 *
 *  Purpose     -  指令更新超速报警状态
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_module_speed_limit_cmd_update(void)
{
	 /*LOGD(L_APP, L_V5, "------------->>>>>>555555555");
	if(speed_limit_status != 0)
	{
		track_cust_get_speelt_sta(0x00);
    	Substantiv_voice_id(track_get_voice_numid_sta());//超速报警完了之后看是否有缓存语音
	}*/
    speed_limit_status = 0;
    track_stop_timer(TRACK_CUST_ALARM_speed_limit_OVERTIME_TIMER);

    g_max_speed = 0;
	ringPlay = 0;
	maxTime = 0;
	currTime = 0;
	tr_stop_timer(TRACK_CUST_SPEED_LIMIT_MAXTIME_TIME_ID);
	tr_stop_timer(TRACK_CUST_SPEED_LIMIT_SILENCE_TIME_ID);
}
kal_uint8 track_cust_get_limit_status()
{
	return speed_limit_status;
}
kal_uint8 track_cust_get_alarm_status(kal_uint8 volue)
{
	if(volue !=99)
	{
		ringPlay = volue;
	}
	return ringPlay;
}
kal_uint8 track_cust_get_speelt_sta(kal_uint8 value)
{
	if(value != 99)
	{
		speelt_sta = value;
	}
	return speelt_sta;
}


