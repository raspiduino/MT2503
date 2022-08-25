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
#if !defined(__NF2318__)
static gps_gprmc_struct tmp_gpsrmc = {0};
static struct_msg_send g_msg = {0};
static U8 fence_status = 0;
static track_gps_data_struct gps_data_buf = {0};
static kal_uint8 fence_last_status[TRACK_DEFINE_FENCE_SUM] = {0};
static U8 g_fence_id = 0;
#endif
/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern void track_cust_sms_send(kal_uint8 number_type, char *number, kal_bool isChar, kal_uint8 *data, kal_uint16 len);

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/

#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
/******************************************************************************
 *  Function    -  track_cust_fence_OverTime_sendsms
 *
 *  Purpose     -  满足进出围栏条件的短信发送
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
#if 0
void track_cust_fence_OverTime_sendsms(void *arg)
{
    char buf[320] = {0};
    U32 ret;
    if(G_parameter.fence[g_fence_id].sw)
    {
        static kal_uint8 in[10] =
        {
            // 进围栏报警
            0x8F, 0xDB, 0x56, 0xF4, 0x68, 0x0F, 0x62, 0xA5, 0x8B, 0x66
        };
        static kal_uint8 out[10] =
        {
            // 出围栏报警
            0x51, 0xFA, 0x56, 0xF4, 0x68, 0x0F, 0x62, 0xA5, 0x8B, 0x66
        };

        memset(&g_msg, 0, sizeof(struct_msg_send));
        g_msg.addUrl = KAL_TRUE;
        g_msg.cm_type = CM_SMS;
        if((kal_uint32)arg == 0)
        {
            if(TRACK_DEFINE_FENCE_SUM > 1)
            {
                sprintf(buf, "出围栏%d报警！", g_fence_id + 1);
                ret = track_fun_GB2312_to_UTF16BE(buf, strlen(buf), g_msg.msg_cn, 320);
                g_msg.msg_cn_len = ret - 2;
#if defined(__GERMANY__)
                snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, "GeoFence %d Alarm - Ausfahrt! ", g_fence_id + 1);
#else
                snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Out The Fence %d Alarm!", g_fence_id + 1);
#endif
            }
            else
            {
#if defined(__GERMANY__)
                 snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, "GeoFence Alarm - Ausfahrt! ");
#else
                snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Out The Fence Alarm!");
#endif
                g_msg.msg_cn_len = 10;
                memcpy(g_msg.msg_cn, out, g_msg.msg_cn_len);
            }
            track_alarm_vec_queue_remove(2, 0, TR_CUST_ALARM_OutFence);
        }
        else
        {
            if((TRACK_DEFINE_FENCE_SUM > 1))
            {
                sprintf(buf, "进围栏%d报警！", g_fence_id + 1);
                ret = track_fun_GB2312_to_UTF16BE(buf, strlen(buf), g_msg.msg_cn, 320);
                g_msg.msg_cn_len = ret - 2;
#if defined(__GERMANY__)
                snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, "GeoFence %d Alarm - Ainfahrt! ", g_fence_id + 1);
#else
                snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Enter The Fence %d Alarm!", g_fence_id + 1);
#endif
            }
            else
            {
#if defined(__GERMANY__)
                snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, "GeoFence Alarm - Einfahrt! ");
#else
                snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Enter The Fence Alarm!");
#endif
                g_msg.msg_cn_len = 10;
                memcpy(g_msg.msg_cn, in, g_msg.msg_cn_len);
            }
            track_alarm_vec_queue_remove(2, 0, TR_CUST_ALARM_InFence);
        }
#if defined(__MORE_FENCE__)
        if(G_parameter.fence[g_fence_id].alarm_type >= 1&&G_parameter.fence[g_fence_id].alarm_type  != 3)
        {
            track_cust_module_alarm_msg_send(&g_msg, &gps_data_buf);
        }
#else
        track_cust_module_alarm_msg_send(&g_msg, &gps_data_buf);
#endif

          if(G_parameter.fence[g_fence_id].alarm_type  == 2||G_parameter.fence[g_fence_id].alarm_type  == 3)
          {
            track_start_timer(TRACK_CUST_ALARM_LowBattery_Call_TIMER, 60000, track_cust_make_call, (void*)1);
          }
    }
    //track_cust_module_alarm_set_type(0);
}

/******************************************************************************
 *  Function    -  fence_alart
 *
 *  Purpose     -  围栏报警处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void fence_alart(track_gps_data_struct *gps_data, kal_uint8 fence_id, kal_bool in)
{
    kal_uint16 sn;
    kal_uint8 call_type;

    kal_bool isReturn=FALSE;

    LOGD(L_APP, L_V4, "fence_id=%d", fence_id);
    memcpy(&tmp_gpsrmc, &gps_data->gprmc, sizeof(gps_gprmc_struct));
    if(G_parameter.fence[fence_id].alarm_type == 1||G_parameter.fence[fence_id].alarm_type == 2)
    {
       isReturn=TRUE;
    }
    if(G_parameter.gprson)
    {
        if(G_parameter.fence[fence_id].alarm_type == 2)
        {
			call_type = 1;
        }
        else
        {
			call_type = 0;
        }
        if(in)
        {
            sn = track_cust_paket_16(gps_data, track_drv_get_lbs_data(), TR_CUST_ALARM_InFence, isReturn, call_type);
        }
        else
        {
            sn = track_cust_paket_16(gps_data, track_drv_get_lbs_data(), TR_CUST_ALARM_OutFence, isReturn, call_type);
        }
        if(G_realtime_data.netLogControl & 16)
        {
            cust_packet_log(16, 6, in, G_realtime_data.in_or_out[g_fence_id], 0, G_parameter.fence[g_fence_id].lat, G_parameter.fence[g_fence_id].lon);
        }
        LOGD(L_APP, L_V4, "围栏%d,报警模式%d", fence_id + 1, G_parameter.fence[fence_id].alarm_type);
		
        if(G_parameter.fence[fence_id].alarm_type == 1 || G_parameter.fence[fence_id].alarm_type == 2)
        {
        	//0 gprs 1 gprs+sms 2 gprs+sms+call 3 gprs_call
            if(track_is_timer_run(TRACK_CUST_FENCE_OVERTIME_TIMER))
            {
                LOGD(L_APP, L_V4, "上一电子围栏报警请求未完成!");
            }
            else
            {
                if(G_parameter.lang == 0)

                {
                    if(in)
                    {
                        track_cust_fence_OverTime_sendsms((void*)1);
                    }
                    else
                    {
                        track_cust_fence_OverTime_sendsms((void*)0);
                    }
                }
                else
                {
                    if(in)
                    {
                        track_start_timer(TRACK_CUST_FENCE_OVERTIME_TIMER, TRACK_ALARM_DELAY_TIME_SECONDS, track_cust_fence_OverTime_sendsms, (void*)1);
                    }
                    else
                    {
                        track_start_timer(TRACK_CUST_FENCE_OVERTIME_TIMER, TRACK_ALARM_DELAY_TIME_SECONDS, track_cust_fence_OverTime_sendsms, (void*)0);
                    }
                }
            }
        }
		else if(G_parameter.fence[fence_id].alarm_type == 3){
			track_start_timer(TRACK_ALARM_DELAY_TIME_SECONDS, 60000, track_cust_make_call, (void*)1);
		}
		
		
		
    }
    else
    {
        if(G_parameter.fence[fence_id].alarm_type >= 1)
        {
            if(in)
            {
                track_os_intoTaskMsgQueueExt(track_cust_fence_OverTime_sendsms, (void*)1);
            }
            else
            {
                track_os_intoTaskMsgQueueExt(track_cust_fence_OverTime_sendsms, (void*)0);
            }
        }
    }
}

/******************************************************************************
 *  Function    -  fence_status_ind
 *
 *  Purpose     -  确定报警是围栏内还是围栏外
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void fence_status_ind(void *par)
{
    kal_uint32 st = (kal_uint32)par;
    char  data[250];
    if(st == 1)
    {
        // 外
        LOGD(L_APP, L_V5, "[%d]10秒稳定 围栏外, %d, %d", g_fence_id, G_parameter.fence[g_fence_id].in_out, G_realtime_data.in_or_out[g_fence_id]);
        if(G_realtime_data.netLogControl & 8)
        {
            sprintf(data, "fence_status_ind  fence  %dout,%d,%d in\n", g_fence_id, G_parameter.fence[g_fence_id].in_out, G_realtime_data.in_or_out[g_fence_id]);
            cust_packet_log_data(8, (kal_uint8 *)data, strlen((char *)(data)));
        }
        if(G_parameter.fence[g_fence_id].in_out >= 1 && G_realtime_data.in_or_out[g_fence_id] == 1)
        {
            LOGD(L_APP, L_V5, "围栏外 报警");

            fence_alart(&gps_data_buf, g_fence_id, 0);
        }
        if(G_realtime_data.in_or_out[g_fence_id] != 2)
        {
            if(G_realtime_data.in_or_out[g_fence_id] == 0)
            {
                LOGD(L_APP, L_V5, "围栏设置首次不报");
            }
            G_realtime_data.in_or_out[g_fence_id] = 2;
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        }
    }
    else if(st == 2)
    {
        // 内
        LOGD(L_APP, L_V6, "[%d]10秒稳定 围栏内, %d, %d", g_fence_id, G_parameter.fence[g_fence_id].in_out, G_realtime_data.in_or_out[g_fence_id]);
        if(G_realtime_data.netLogControl & 8)
        {
            sprintf(data, "fence_status_ind  fence  %d in,%d,%d in\n", g_fence_id, G_parameter.fence[g_fence_id].in_out, G_realtime_data.in_or_out[g_fence_id]);
            cust_packet_log_data(8, (kal_uint8 *)data, strlen((char *)(data)));
        }
        if(G_parameter.fence[g_fence_id].in_out != 1 && G_realtime_data.in_or_out[g_fence_id] == 2)
        {
            LOGD(L_APP, L_V5, "围栏内 报警 g_fence_id=%d", g_fence_id);
            fence_alart(&gps_data_buf, g_fence_id, 1);
        }
        if(G_realtime_data.in_or_out[g_fence_id] != 1)
        {
            if(G_realtime_data.in_or_out[g_fence_id] == 0)
            {
                LOGD(L_APP, L_V5, "围栏设置首次不报");
            }
            G_realtime_data.in_or_out[g_fence_id] = 1;
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        }
    }
}

/******************************************************************************
 *  Function    -  track_cust_module_fence_check_InOut
 *
 *  Purpose     -  围栏报警控制，防止重复报围栏内或围栏外
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_module_fence_check_InOut(track_gps_data_struct *gps_data, kal_uint8 fence_id, kal_uint8 status)
{
    char  data[250];
    memcpy(&gps_data_buf, gps_data, sizeof(track_gps_data_struct));
    if(status)
    {
        LOGD(L_APP, L_V7, "%d围栏外, alart type=%d, in_or_out=%d, fence_last_status=%d",
             fence_id, G_parameter.fence[fence_id].in_out,
             G_realtime_data.in_or_out[fence_id], fence_last_status[fence_id]);
        // 外
        if(fence_last_status[fence_id] != 1)
        {
            LOGD(L_APP, L_V6, "围栏外, alart type=%d, in_or_out=%d在，fence_id=%d,g_fence_id=%d",
                 G_parameter.fence[fence_id].in_out,
                 G_realtime_data.in_or_out[fence_id], fence_id, g_fence_id);
            //定时器开启的情况下并且id如果不相等则不做报警提示判断
            if(!(track_is_timer_run(TRACK_CUST_FENCE_TRIGGER_TIMER) && g_fence_id != fence_id) && !track_is_timer_run(TRACK_CUST_FENCE_OVERTIME_TIMER))
            {
                LOGD(L_APP, L_V6, "围栏外=%d，10秒之后触发", fence_id);
                if(G_realtime_data.netLogControl & 8)
                {
                    sprintf(data, "track_cust_module_fence_check_InOut  fence %d out\n", fence_id);
                    cust_packet_log_data(8, (kal_uint8 *)data, strlen((char *)(data)));
                }
                fence_last_status[fence_id] = 1;
                track_start_timer(TRACK_CUST_FENCE_TRIGGER_TIMER, 10000, fence_status_ind, (void*)1);
                g_fence_id = fence_id;
            }
        }
    }
    else
    {

        // 内
        if(fence_last_status[fence_id] != 2)
        {
            if(G_realtime_data.netLogControl & 8)
            {
                sprintf(data, "track_cust_module_fence_check_InOut  fence %d in\n", fence_id);
                cust_packet_log_data(8, (kal_uint8 *)data, strlen((char *)(data)));
            }
            LOGD(L_APP, L_V6, "围栏内, alart type=%d, in_or_out=%d在，fence_id=%d,g_fence_id=%d",
                 G_parameter.fence[fence_id].in_out,
                 G_realtime_data.in_or_out[fence_id], fence_id, g_fence_id);
            //定时器开启的情况下并且id如果不相等则不做报警提示判断
            if(!(track_is_timer_run(TRACK_CUST_FENCE_TRIGGER_TIMER) && g_fence_id != fence_id) && !track_is_timer_run(TRACK_CUST_FENCE_OVERTIME_TIMER))
            {
                LOGD(L_APP, L_V5, "围栏内=%d，10秒之后触发", fence_id);
                fence_last_status[fence_id] = 2;
                g_fence_id = fence_id;
                track_start_timer(TRACK_CUST_FENCE_TRIGGER_TIMER, 10000, fence_status_ind, (void*)2);
            }
        }
    }
}

/******************************************************************************
 *  Function    -  track_cust_module_fence_gps
 *
 *  Purpose     -  围栏报警触发条件判断
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_module_fence_gps(track_gps_data_struct *gps_data, int fence_id)
{
    U16 sn, i = 0;
    i = fence_id;
#if defined(__GT370__)|| defined (__GT380__)
	if(track_cust_get_work_mode() == WORK_MODE_3)
	{
		return;
	}
#endif
    if(G_parameter.fence[fence_id].sw)
    {
        float lat, lon;

        if(gps_data->gprmc.EW == 'E')
            lon = gps_data->gprmc.Longitude;
        else
            lon = gps_data->gprmc.Longitude * -1;
        if(gps_data->gprmc.NS == 'N')
            lat = gps_data->gprmc.Latitude;
        else
            lat = gps_data->gprmc.Latitude * -1;
        if(G_parameter.fence[i].square == 0)
        {
            float ret = track_fun_get_GPS_2Points_distance(G_parameter.fence[i].lat, G_parameter.fence[i].lon, lat, lon);
            LOGD(L_APP, L_V7, "fence_id=%d圆形, lat:%.6f, lon:%.6f, radius:=%.1fm < %dm", fence_id, lat, lon, ret, G_parameter.fence[i].radius * 100);
            if(ret <= G_parameter.fence[i].radius * 100)
            {
                // 内
                track_cust_module_fence_check_InOut(gps_data, i, 0);
            }
            else
            {
                // 外
                track_cust_module_fence_check_InOut(gps_data, i, 1);
            }
        }
        else if(G_parameter.fence[i].square == 1)
        {
            kal_uint8 flag = 0;
            //LOGD(L_APP, L_V7, "矩形, lon:%.6f, lat:%.6f", lon, lat);
            if(G_parameter.fence[i].lat < G_parameter.fence[i].lat2)
            {
                if(lat >= G_parameter.fence[i].lat) flag |= 1;
                if(lat <= G_parameter.fence[i].lat2) flag |= 2;
            }
            else
            {
                if(lat <= G_parameter.fence[i].lat) flag |= 1;
                if(lat >= G_parameter.fence[i].lat2) flag |= 2;
            }
            if(G_parameter.fence[i].lon < G_parameter.fence[i].lon2)
            {
                if(lon >= G_parameter.fence[i].lon) flag |= 4;
                if(lon <= G_parameter.fence[i].lon2) flag |= 8;
            }
            else
            {
                if(lon <= G_parameter.fence[i].lon) flag |= 4;
                if(lon >= G_parameter.fence[i].lon2) flag |= 8;
            }
            if(flag == 15)
            {
                // 内
                track_cust_module_fence_check_InOut(gps_data, i, 0);
            }
            else
            {
                // 外
                char tmp[5] = {0};
                track_cust_module_fence_check_InOut(gps_data, i, 1);
                if((flag & 3) == 1)
                    sprintf(tmp, "北");
                else if((flag & 3) == 2)
                    sprintf(tmp, "南");
                else
                    sprintf(tmp, "中");

                if((flag & 12) == 4)
                    LOGD(L_APP, L_V7, "矩形, lon:%.6f, lat:%.6f 东西(东) 南北(%s)", lon, lat, tmp);
                else if((flag & 12) == 8)
                    LOGD(L_APP, L_V7, "矩形, lon:%.6f, lat:%.6f 东西(西) 南北(%s)", lon, lat, tmp);
                else
                    LOGD(L_APP, L_V7, "矩形, lon:%.6f, lat:%.6f 东西(中) 南北(%s)", lon, lat, tmp);
            }
        }
    }
}

/******************************************************************************
 *  Function    -  track_cust_module_fence_cmd_update
 *
 *  Purpose     -  指令更新围栏的相关参数
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_module_fence_cmd_update(kal_uint8  fence_id)
{
    if(fence_id == g_fence_id)
    {
        track_stop_timer(TRACK_CUST_FENCE_TRIGGER_TIMER);
    }
    G_realtime_data.in_or_out[fence_id] = 0;
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    fence_last_status[fence_id] = 0;
    if(G_realtime_data.netLogControl & 16)
    {
        cust_packet_log(16, 5, G_parameter.fence[0].square, G_realtime_data.in_or_out[g_fence_id], G_parameter.fence[0].radius, G_parameter.fence[0].lat, G_parameter.fence[0].lon);
    }
}
kal_uint8 track_cust_module_get_fence_id(void)
{
    return g_fence_id;
}
void track_cust_module_set_out(void)
{
    memset(fence_last_status, 1, TRACK_DEFINE_FENCE_SUM);
    memset(G_realtime_data.in_or_out, 2, TRACK_DEFINE_FENCE_SUM);

}

void track_cust_module_set_in(void)
{
    memset(fence_last_status, 2, TRACK_DEFINE_FENCE_SUM);
    memset(G_realtime_data.in_or_out, 1, TRACK_DEFINE_FENCE_SUM);
}
void track_cust_module_init(void)
{
    memset(fence_last_status, 0, TRACK_DEFINE_FENCE_SUM);
    memset(G_realtime_data.in_or_out, 0, TRACK_DEFINE_FENCE_SUM);
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
}
void cmd_seefence(CMD_DATA_STRUCT *cmd)
{
    char msg[50];
    U8   j;
    if(cmd->part == 0)
    {
        for(j = 0; j < TRACK_DEFINE_FENCE_SUM; j++)
        {
            if(j == TRACK_DEFINE_FENCE_SUM - 1)
            {
                sprintf(msg, "fence status%d:%d", j + 1, G_realtime_data.in_or_out[j]);
            }
            else
            {
                sprintf(msg, "fence status%d:%d,", j + 1, G_realtime_data.in_or_out[j]);
            }
            strcat(cmd->rsp_msg, msg);
        }
        return;
    }
    else
    {
        sprintf(cmd->rsp_msg, "error");
    }
}
#else
void cmd_seefence(CMD_DATA_STRUCT *cmd){;}
void track_cust_module_init(void){;}
void track_cust_module_set_in(void){;}
void track_cust_module_set_out(void){;}
kal_uint8 track_cust_module_get_fence_id(void){return 0;}
void track_cust_module_fence_cmd_update(kal_uint8  fence_id){;};
void track_cust_module_fence_gps(track_gps_data_struct *gps_data, int fence_id){;}
void track_cust_module_fence_check_InOut(track_gps_data_struct *gps_data, kal_uint8 fence_id, kal_uint8 status){;}
void fence_status_ind(void *par){;}
static void fence_alart(track_gps_data_struct *gps_data, kal_uint8 fence_id, kal_bool in){;}
void track_cust_fence_OverTime_sendsms(void *arg){;}
#endif
