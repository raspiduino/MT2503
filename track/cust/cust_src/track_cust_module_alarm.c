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
#include "c_vector.h"

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
static enum_alarm_type s_alarm_type = 0;
static c_vector* vec_alarm_queue = NULL;

#if defined(__ACC_ALARM__)
#if defined(__GERMANY__)
static char *str_accalm_changeoff_en = "Achtung! Zuendung ausgeschaltet";
#else
static char *str_accalm_changeoff_en = "Attention please!ACC OFF";
#endif
static char str_accalm_changeoff_cn[16] = //请注意！车辆熄火
{0x8B, 0xF7, 0x6C, 0xE8, 0x61, 0x0F, 0xFF, 0x01, 0x8F, 0x66, 0x8F, 0x86, 0x71, 0x84, 0x70, 0x6B};

#if defined(__GERMANY__)
static char *str_accalm_changeon_en = "Achtung! Zuendung eingeschaltet";
#else
static char *str_accalm_changeon_en = "Attention please!ACC ON";
#endif
static char str_accalm_changeon_cn[16] = // 请注意！车辆点火
{0x8B, 0xF7, 0x6C, 0xE8, 0x61, 0x0F, 0xFF, 0x01, 0x8F, 0x66, 0x8F, 0x86, 0x70, 0xB9, 0x70, 0x6B};
#endif
/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/
kal_uint8 g_alarm_gps_status = 0;//报警记录报警期间GPS定位情况//0,不定位;1,定位

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/
extern kal_uint8 g_test_flag;
/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern void track_cus_alarm_vibrates_overTime_sendsms(void);
extern void track_cust_soscall_OverTime_sendsms(void);
/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
extern kal_uint16 track_cust_check_gprsdata(kal_uint32 flag, kal_uint16 sn);
#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

/******************************************************************************
 *  Function    -  track_alarm_vec_queue_push
 *
 *  Purpose     -  报警数据包请求压入队列
 *
 *  Description -
 *  多围栏项目需要有单个围栏报警方式
 *  所以是增加一个围栏 编号，还是增加
 *  是否发短信标示，目前暂时加一个短信标示，for GT500 only Liujw 2014-06-10
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_alarm_vec_queue_push(kal_uint8 alarm_type, kal_uint16 sn, kal_uint8 call_type)
{
    kal_uint32 value = 0;
    kal_uint8 *p = (kal_uint8 *)&value;
    if(NULL == vec_alarm_queue)
    {
        VECTOR_CreateInstance(vec_alarm_queue);
    }
    if(VECTOR_Size(vec_alarm_queue) > 20)
    {
        LOGD(L_APP, L_V4, "报警队列中已经有%d条报警记录了", VECTOR_Size(vec_alarm_queue));
        VECTOR_Erase(vec_alarm_queue, 0, 1);
    }
    memcpy(p, &sn, 2);
    memcpy(p + 2, &alarm_type, 1);
    memcpy(p + 3, &call_type, 1);
    LOGD(L_APP, L_V5, "alarm_type:%d, sn:%0.4X, value:%X", alarm_type, sn, value);
    VECTOR_PushBack(vec_alarm_queue, (void*)value);
}

/******************************************************************************
 *  Function    -  track_alarm_vec_queue_remove
 *
 *  Purpose     -  从队列中移除报警
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_uint32* track_alarm_vec_queue_remove(kal_uint8 mode, kal_uint16 sn, kal_uint8 alarm_type)
{
    kal_uint32 *value;
    kal_uint8    _alarm_type;
    kal_uint16    _sn;
    int max, i;
    if(NULL == vec_alarm_queue)
    {
        VECTOR_CreateInstance(vec_alarm_queue);
    }
    max = VECTOR_Size(vec_alarm_queue);
    LOGD(L_APP, L_V5, "mode:%d, sn:%0.4X, VECTOR_Size(vec_alarm_queue):%d", mode, sn, max);
    if(max <= 0)
    {
        return 0;
    }
    for(i = 0; i < max; i++)
    {
        value = VECTOR_At(vec_alarm_queue, i);
        memcpy(&_sn, (kal_uint8 *)&value, 2);
        memcpy(&_alarm_type, ((kal_uint8 *)(&value)) + 2, 1);
        LOGD(L_APP, L_V5, "alarm_type:%d, sn:%0.4X, value:%X", _alarm_type, _sn, value);
        if(mode == 1 && _sn == sn)
        {
            VECTOR_Erase(vec_alarm_queue, i, 1);
            return value;
        }
        else if(mode == 2 && _alarm_type == alarm_type)
        {
            VECTOR_Erase(vec_alarm_queue, i, 1);
            return track_alarm_vec_queue_remove(mode, sn, alarm_type);
        }
        else if(mode == 3)
        {
            VECTOR_Erase(vec_alarm_queue, i, 1);
            return value;
        }
    }
    return 0;
}
kal_uint32 track_alarm_vec_queue_check(kal_uint8 alarm_type)
{
    kal_uint32 *value;
    kal_uint8    _alarm_type;
    kal_uint16    _index = 0;
    int max, i;
    if(NULL == vec_alarm_queue)
    {
        VECTOR_CreateInstance(vec_alarm_queue);
    }
    max = VECTOR_Size(vec_alarm_queue);
    LOGD(L_APP, L_V5, "VECTOR_Size(vec_alarm_queue):%d", max);
    if(max <= 0)
    {
        return 0;
    }
    for(i = 0; i < max; i++)
    {
        value = VECTOR_At(vec_alarm_queue, i);
        memcpy(&_alarm_type, ((kal_uint8 *)(&value)) + 2, 1);
        LOGD(L_APP, L_V5, "alarm_type:%d,value:%X", _alarm_type, value);
        if(_alarm_type == alarm_type)
        {
            _index++;
        }
    }
    LOGD(L_APP, L_V5, "_index:%d", _index);
    return _index;
}
/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

/******************************************************************************
 *  Function    -  track_cust_module_alarm_lock
 *
 *  Purpose     -  报警状态记录，避免同一报警未处理完，又有新的报警触发
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_int8 track_cust_module_alarm_lock(enum_alarm_type type, kal_uint8 value)
{
    static kal_uint8 status[TR_CUST_ALARM_MAX] = {0};
    LOGD(L_APP, L_V4, "%d,%d", type, value);

	if(type == 98)
    {
        int i;
        for(i = 0; i < TR_CUST_ALARM_MAX; i++)
        {
            if(status[i] == 1) return 1;
        }
        return 0;
    }
    else if(type == 99)
    {
        memset(status, 0, sizeof(status));
        return 0;
    }
    else if(type >= 0 && type < TR_CUST_ALARM_MAX)
    {
        if(value == 0 || value == 1)
        {
            status[type] = value;
        }
        return status[type];
    }
    return -1;
}

static void track_blank(void)
{

}
#if defined(__NF2318__)
void track_cust_module_alarm_recv_addr(char *number, kal_uint8 *content, int content_len, kal_uint16 sn){;}
#else
/******************************************************************************
 *  Function    -  track_cust_module_alarm_recv_addr
 *
 *  Purpose     -  从网络接收到得报警包
 *
 *  Description -  暂时无法区分收到的报警包是什么类型的报警
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 27-02-2013,  Cml  written
 * v1.1  , 14-10-2013,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_module_alarm_recv_addr(char *number, kal_uint8 *content, int content_len, kal_uint16 sn)
{
    U8 phbNumIndex = 0;
    kal_bool flag = KAL_TRUE, on = KAL_FALSE, call = KAL_FALSE;

    kal_uint32* value;
    kal_uint8 alarm_type, call_type;

    value = track_alarm_vec_queue_remove(1, sn, 0);
    memcpy(&call_type, (kal_uint8 *)&value + 3, 1);
    memcpy(&alarm_type, ((kal_uint8 *)(&value)) + 2, 1);
    LOGD(L_APP, L_V4, "收到服务器下发的报警地址，向SOS号码发送报警短信 sn=%X, alarm_type=%d call_type=%d", sn, alarm_type, call_type);
    /*if(alarm_type == 0xFFFF)
    {
        alarm_type = track_alarm_vec_queue_remove(3, 0, 0);
        LOGD(L_APP, L_V4, "不能在队列中找到对应的报警请求，直接移除最早一个报警 %d, alarm_type=%d", sn, alarm_type);
    }*/
#if defined (__GT370__)|| defined (__GT380__) || defined(__ET310__)||defined(__GT300S__) || defined(__MT200__)
    if(track_cust_check_gprsdata(99, 0xff) == sn)
    {
        track_cust_check_gprsdata(0, 0xff);
    }
#endif

    //*************START********************//用于LBS GPS双报警报流程判断其它可以屏蔽这段
    if((call_type == 0) && (track_alarm_vec_queue_check(alarm_type) >= 1))
    {
        call_type = 1;
        LOGD(L_APP, L_V6, "重置报警电话标志");
    }
    //*************END*********************//


    switch(alarm_type)
    {
        case TR_CUST_ALARM_NORMAL:
            //on = KAL_TRUE;
            LOGD(L_APP, L_V4, "该报警无需短信通知用户!");
            track_fun_view_UTF16BE_string(content, content_len);
            return;
            break;
        case TR_CUST_ALARM_SOS:
            tr_stop_timer(TRACK_CUST_SOS_SMS_OVERTIME_TIMER);
            if(G_parameter.sos_alarm.alarm_type == 0)
            {
                break;
            }
            else if((G_parameter.sos_alarm.alarm_type >= 2) && ((call_type & 1) == 1))
            {
                call = KAL_TRUE;
            }
            on = KAL_TRUE;
            break;
        case TR_CUST_ALARM_PowerFailure:
            tr_stop_timer(TRACK_CUST_ALARM_power_fails_OVERTIME_TIMER);
            if(G_parameter.power_fails_alarm.alarm_type == 0)
            {
                break;
            }
            else if((G_parameter.power_fails_alarm.alarm_type == 2 || G_parameter.power_fails_alarm.alarm_type == 3) && ((call_type & 1) == 1))
            {
                call = KAL_TRUE;
            }
            if(G_parameter.power_fails_alarm.alarm_type != 3)
            {
                on = KAL_TRUE;
            }
            break;
        case TR_CUST_ALARM_Vibration:
            tr_stop_timer(TRACK_CUST_ALARM_alarm_vibrates_OVERTIME_TIMER);
            if(G_parameter.vibrates_alarm.alarm_type == 0)
            {
                break;
            }
            if((G_parameter.vibrates_alarm.alarm_type == 2 || G_parameter.vibrates_alarm.alarm_type == 3) && ((call_type & 1) == 1))
            {
                call = KAL_TRUE;
            }
            if(G_parameter.vibrates_alarm.alarm_type != 3)
            {
                on = KAL_TRUE;
            }
            break;
        case TR_CUST_ALARM_LowBattery:
            tr_stop_timer(TRACK_CUST_ALARM_LowBattery_OVERTIME_TIMER);
            if(G_parameter.low_power_alarm.alarm_type == 0)
            {
                break;
            }
            //on = KAL_TRUE; //低电报警取消服务器返回带地址的报警
            break;
        case TR_CUST_ALARM_InFence:
        case TR_CUST_ALARM_OutFence:
            tr_stop_timer(TRACK_CUST_FENCE_OVERTIME_TIMER);
#if defined(__MORE_FENCE__)
            if(call_type & 1)
            {
                call = KAL_TRUE;
            }
            if(!(call_type & 2))
#else
            if(G_parameter.fence[0].alarm_type == 0)
#endif
            {
                LOGD(L_APP, L_V4, "电子围栏不做短信报警");
                break;
            }

            on = KAL_TRUE;
            break;
        case TR_CUST_ALARM_Speed_Limit:
            //tr_stop_timer(TRACK_CUST_ALARM_speed_limit_SMS_OVERTIME_TIMER);
            if(G_parameter.speed_limit_alarm.alarm_type == 0)
            {
                break;
            }
            //on = KAL_TRUE;
            break;
        case TR_CUST_ALARM_displacement:
            tr_stop_timer(TRACK_CUST_ALARM_displacement_OVERTIME_TIMER);
            if(G_parameter.displacement_alarm.alarm_type == 0)
            {
                break;
            }
            if((G_parameter.displacement_alarm.alarm_type == 2 || G_parameter.displacement_alarm.alarm_type == 3) && ((call_type & 1) == 1))
            {
                call = KAL_TRUE;
            }
            on = KAL_TRUE;

    #if defined (__NT33__)
        track_cust_no_acc_disable_moving_once_alarm();
    #endif
            break;
        case TR_CUST_ALARM_PRE_REMOVE:
#if defined(__GT740__)
			if(track_cust_remove_alarm_lock(99))
			{
				return;
			}
			track_cust_remove_alarm_lock(1);
                        tr_stop_timer(TRACK_CUST_EXTCHIP_DELAY_SEND_ALARM_MSG_TIMER_ID);
#endif
            if(G_parameter.teardown_str.alarm_type == 0)
            {
                break;
            }
            if((G_parameter.teardown_str.alarm_type == 2 || G_parameter.teardown_str.alarm_type == 3) && ((call_type & 1) == 1))
            {
                call = KAL_TRUE;
            }
            if(G_parameter.teardown_str.alarm_type != 3)
            {
#if defined (__GT370__)|| defined (__GT380__)
            if(track_is_timer_run(TRACK_CUST_PRE_REMOVEL_SMS_FILTER_TIMER_ID))
            {
                LOGD(L_APP, L_V4, "3分钟内已发拆除短信");
                 on = KAL_FALSE;
            }
            else
            {
                tr_start_timer(TRACK_CUST_PRE_REMOVEL_SMS_FILTER_TIMER_ID, 170*1000, track_blank);
                 on = KAL_TRUE;
            }

#else
                on = KAL_TRUE;
#endif /* __GT370__ */
            }
            break;

        case TR_CUST_ALARM_OPEN_SHELL:
#if defined (__GT370__)|| defined (__GT380__)
            tr_stop_timer(TRACK_CUST_SEND_OPEN_SHELL_SMS_TIMEOVER_TIMER_ID);
            if(G_parameter.open_shell_alarm.alarm_type == 0)
            {
                break;
            }
            if((G_parameter.open_shell_alarm.alarm_type == 2 || G_parameter.open_shell_alarm.alarm_type == 3) && ((call_type & 1) == 1))
            {
                call = KAL_TRUE;
            }
            if(G_parameter.open_shell_alarm.alarm_type != 3)
            {
                if(track_is_timer_run(TRACK_CUST_OPEN_SHELL_SMS_FILTER_TIMER_ID))
                {
                    LOGD(L_APP, L_V4, "3分钟内已发开盖短信");
                     on = KAL_FALSE;
                }
                else
                {
                    tr_start_timer(TRACK_CUST_OPEN_SHELL_SMS_FILTER_TIMER_ID, 170*1000, track_blank);
                     on = KAL_TRUE;
                }
            }
#endif /* __GT370__ */
            break;
    }

    LOGD(L_APP, L_V4, "准备就绪，发送地址短信给sos号码哦 on=%d,g_test_flag=%d", on, g_test_flag);
    if(on || g_test_flag)
    {
        for(phbNumIndex = 0; phbNumIndex < TRACK_DEFINE_SOS_COUNT; phbNumIndex++)
        {
            if((TR_CUST_ALARM_SOS == alarm_type || G_phone_number.almrep[phbNumIndex]) && strlen(G_parameter.sos_num[phbNumIndex]))
            {
                track_cust_sms_send(0, G_parameter.sos_num[phbNumIndex], 0, content, content_len);
                flag = KAL_FALSE;

                if(!G_parameter.Permission.AlarmNumCount)
                {
                    break;
                }
            }
        }
        if(flag)
        {
            LOGD(L_APP, L_V4, "SOS号码未设置，报警短信发送不成功");
        }
    }
    s_alarm_type = 0;
    if(call)
    {
        LOGD(L_APP, L_V4, "60 秒后拨打电话。");
        track_start_timer(TRACK_CUST_ALARM_MAKECALL_TIMER, 60000, track_cust_make_call, (void*)1);
    }
    else
    {
        if(G_parameter.sos_alarm.alarm_type < 2 || alarm_type != TR_CUST_ALARM_SOS)
        {
            track_cust_module_alarm_lock(99, 0);
        }
    }
}
#endif
/******************************************************************************
 *  Function    -  track_cust_module_alarm_msg_send
 *
 *  Purpose     -  触发报警后，发送短信的统一处理函数
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * v1.1  , 11-10-2013,  wangqi modify
 * ----------------------------------------
*******************************************************************************/
kal_bool track_cust_module_alarm_msg_send(struct_msg_send *msg, track_gps_data_struct *gps_data)
{
    int len, len2;
    kal_bool flag = KAL_FALSE;

    LOGD(L_APP, L_V5, "cm_type=%d, %s, almrep:%d", msg->cm_type, msg->msg_en, msg->not_need_almrep);
    if(msg->addUrl)
    {
        char tmp[320] = {0};
        if(gps_data != NULL)
        {
            if(gps_data->gprmc.status)
            {
                track_cust_get_url_str(tmp, &gps_data->gprmc);
                len = strlen(tmp);
                len2 = strlen(msg->msg_en);
                if(len2 + len < CM_PARAM_LONG_LEN_MAX)
                {
                    sprintf(&msg->msg_en[len2], "%s", tmp);
                }
                if((msg->msg_cn_len + len * 2) < CM_PARAM_LONG_LEN_MAX)
                {
                    if(msg->msg_cn_len == 12 && msg->msg_cn[10] == 0xFF && msg->msg_cn[11] == 0x01)
                    {
                        // 为了保证一条短信能发送完，节省短信，适当去掉提示信息中的感叹号。
                        msg->msg_cn_len = 10;
                    }
                    len = track_fun_asc_str_to_ucs2_str(&msg->msg_cn[msg->msg_cn_len], tmp) - 2;
                    LOGH(L_APP, L_V6, &msg->msg_cn[msg->msg_cn_len], len);
                    msg->msg_cn_len += len;
                }
            }
            else
            {
                LOGD(L_APP, L_V5, "gprmc.status:%d", gps_data->gprmc.status);
            }
        }
    }
    if(msg->cm_type == CM_ONLINE)
    {
        track_cust_paket_msg_upload(msg->stamp, KAL_TRUE, msg->msg_en, strlen(msg->msg_en));
        flag = KAL_TRUE;
    }
    else if(msg->cm_type == CM_ONLINE2)
    {
        track_cust_paket_FD_cmd(msg->stamp, KAL_TRUE, msg->msg_en, strlen(msg->msg_en));
        flag = KAL_TRUE;
    }
    else if(msg->cm_type == CM_SMS)
    {
        int i;
        kal_bool isChar = KAL_TRUE;
        char *data;

        if(G_parameter.lang == 1)
        {
            isChar = KAL_FALSE;
            len = msg->msg_cn_len;
            data = msg->msg_cn;
        }
        else
        {
            isChar = KAL_TRUE;
            len = strlen(msg->msg_en);
            data = msg->msg_en;
        }
        if(strlen(msg->phone_num) == 0)
        {
            LOGH(L_APP, L_V6, data, len);
            for(i = 0; i < TRACK_DEFINE_SOS_COUNT; i++)
            {
                if((msg->not_need_almrep == 1 || G_phone_number.almrep[i]) && strlen((S8*) G_parameter.sos_num[i]))
                {
                    track_cust_sms_send(0, G_parameter.sos_num[i], isChar, data, len);
                    flag = KAL_TRUE;
                    if(!G_parameter.Permission.AlarmNumCount)
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            track_cust_sms_send(0, msg->phone_num, isChar, data, len);
        }
    }
    else if(msg->cm_type == CM_AT)
    {
        LOGS("%s", msg->msg_en);
        flag = KAL_TRUE;
    }
    return flag;
}

/******************************************************************************
 *  Function    -  track_cust_alarm_type
 *
 *  Purpose     -  设置报警类型
 *
 *  Description -   type == 0  为查询当前报警类型
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 09-08-2013,  ZengPing && Liujw  written
 * ----------------------------------------
 ******************************************************************************/
enum_alarm_type track_cust_alarm_type(enum_alarm_type type)
{
    static enum_alarm_type s_alarm_type = 0;
    if(type != 0)
    {
        s_alarm_type = type;
    }
    return s_alarm_type;
}


/******************************************************************************
 *  Function    -  track_cust_send_paket_16
 *
 *  Purpose     -  GPS位置请求
 *
 *  Description -   flag :0:不上传1:上传2: 设定上传期望值
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 05-08-2013,  ZengPing && Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_send_paket_16(kal_uint32 flag, track_gps_data_struct *gd, kal_uint8 call_type)
{
    U16 sn, waiting_time = 60;
    static kal_uint32 status = 0;
    if(flag == 0)
    {
        status = 0;
    }
    else if(flag == 1 &&  status == 1)
    {
        status = 0;
        g_alarm_gps_status = 1;
        LOGD(L_APP, L_V6, "g_alarm_gps_status =%d,status:%d", g_alarm_gps_status, track_soc_login_status());

        sn = track_cust_paket_16(gd, track_drv_get_lbs_data(), track_cust_alarm_type(0), KAL_TRUE, call_type);

        if(track_is_timer_run(TRACK_CUST_SOS_SMS_OVERTIME_TIMER))
        {
            tr_start_timer(TRACK_CUST_SOS_SMS_OVERTIME_TIMER, 60 * 1000, track_cust_soscall_OverTime_sendsms);
        }

        if(track_is_timer_run(TRACK_CUST_ALARM_alarm_vibrates_OVERTIME_TIMER))
        {
#if defined(__GT370__)|| defined (__GT380__)
            if(track_soc_login_status() == 0)
            {
                waiting_time = 2;
            }
#endif
            tr_start_timer(
                TRACK_CUST_ALARM_alarm_vibrates_OVERTIME_TIMER,
                waiting_time * 1000,
                track_cus_alarm_vibrates_overTime_sendsms);
        }
    }
    else if(flag == 2)
    {
        status = 1;
    }
}
#if defined(__ACC_ALARM__)
/******************************************************************************
 *  Function    -  accalm_sendsms
 *
 *  Purpose     -  发送ACC变化报警短信
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 27-10-2016,  Cjj  written
 * ----------------------------------------
*******************************************************************************/
void accalm_sendsms(kal_uint8 par)
{
    struct_msg_send g_msg = {0};
    if(G_parameter.accalm.accalm_type != 1)
    {
        return;
    }
    LOGD(L_APP, L_V5, "");
    g_msg.addUrl = KAL_FALSE;
    g_msg.cm_type = CM_SMS;
    if(par == 0)
    {
        snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, str_accalm_changeoff_en);
        g_msg.msg_cn_len = 16;
        memcpy(g_msg.msg_cn, str_accalm_changeoff_cn, g_msg.msg_cn_len);
    }
    else
    {
        snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, str_accalm_changeon_en);
        g_msg.msg_cn_len = 16;
        memcpy(g_msg.msg_cn, str_accalm_changeon_cn, g_msg.msg_cn_len);
    }
    track_cust_module_alarm_msg_send(&g_msg, NULL);

}
void track_cust_acc_change_alarm(void *arg)
{
    kal_uint32 par = (kal_uint32)arg;
    if(G_parameter.accalm.accalm_sw == 1)
    {
        if(par == 0)
        {
           if(G_parameter.accalm.accalm_cause == 0 || G_parameter.accalm.accalm_cause == 1)
           {
            track_cust_paket_16(track_cust_gpsdata_alarm(), track_drv_get_lbs_data(), TR_CUST_ALARM_ACC_OFF, KAL_TRUE, 1);
            accalm_sendsms(0);
           }
        }
        else
        {
          if(G_parameter.accalm.accalm_cause == 0 || G_parameter.accalm.accalm_cause == 2)
          {
            track_cust_paket_16(track_cust_gpsdata_alarm(), track_drv_get_lbs_data(), TR_CUST_ALARM_ACC_ON, KAL_TRUE, 1);
            accalm_sendsms(1);
          }
        }
    }

}
#endif
#if !defined(__NF2318__)
void track_cust_alarm_acc_change(void *arg)
{
    kal_uint32 par = (kal_uint32)arg;
    LOGD(L_APP, L_V5, "");
    if(G_parameter.accalm_sw == 1)
    {
        char *on  = "Attention please! ACC ON";
        char *off = "Attention please! ACC OFF";
        char *out_string;
        int i;
        if(par == 0)
        {
            out_string = off;
        }
        else if(par == 1)
        {
            out_string = on;
        }
        for(i = 0; i < TRACK_DEFINE_SOS_COUNT; i++)
        {
            if(G_phone_number.almrep[i] && strlen((S8*)G_parameter.sos_num[i]))
            {
                track_cust_sms_send(0, G_parameter.sos_num[i], KAL_TRUE, out_string, strlen(out_string));
                if(!G_parameter.Permission.AlarmNumCount)
                {
                    break;
                }
            }
        }
    }
}
#endif
