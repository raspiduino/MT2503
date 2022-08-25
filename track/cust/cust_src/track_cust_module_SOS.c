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
#include "track_at_call.h"

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
#if defined(__GERMANY__)
static char* msg_alarm_sos_en = "Alarm am Fahrzeug!";
static char* msg_alarm_sos_en1 = "Alarm am Fahrzeug!";
#else
static char* msg_alarm_sos_en = "Emergency call!";
static char* msg_alarm_sos_en1 = "Emergency call!Please pay attention!";
#endif
static kal_uint8 msg_alarm_sos_cn[16] =   // 紧急呼叫！
{
    0x7D, 0x27, 0x60, 0x25, 0x54, 0x7C, 0x53, 0xEB, 0xFF, 0x01
};
static kal_uint8 msg_alarm_sos_cn1[18] = // 紧急呼叫!请关注！
{
    0x7D, 0x27, 0x60, 0x25, 0x54, 0x7C, 0x53, 0xEB, 0xFF, 0x01, 0x8B, 0xF7, 0x51, 0x73, 0x6C, 0xE8, 0xFF, 0x01
};

static struct_msg_send g_msg = {0};
static kal_uint8 g_call_status = 0;
static kal_uint8 g_monitor_call_status = 0;
static track_gps_data_struct gps_data_buf = {0};

static U16 g_last_alerm_no = 0;

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/
/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/
extern kal_uint8 g_alarm_gps_status;
extern char dail_num[TRACK_DEFINE_PHONE_NUMBER_LEN_MAX];
extern kal_uint32 dail_count;
/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern void track_cust_call(char *number);      // 呼叫
extern void track_cust_call_hangup(void);       // 挂断
extern kal_bool track_is_in_call(void);          //是否在通话状态
extern kal_uint8 track_cust_dial_makecall(void * arg);
/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
void track_cust_sos_call_status(kal_uint16 call_type, kal_uint16 callState);
void track_cust_make_call_function(void *arg);
void track_cust_send_paket_16(kal_uint32 flag, track_gps_data_struct *gd, kal_uint8 call_type);

#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/
static void Delayms(kal_uint16 data)
{
    kal_uint32 i;
    while(data--)
    {
        for(i = 0; i < 2000; i++) {}
    }
}

/*---------------------------------------------------------------------------
 * FUNCTION			ControlVibration
 *
 * DESCRIPTION		振动器持续振动0.5S
 *
 * PARAMETERS
 *		kal_bool
 * RETURNS
 *  		void
 *
 *---------------------------------------------------------------------------*/
void ControlVibration(void)
{
    track_drv_set_vibr(KAL_TRUE);
    Delayms(200);
    track_drv_set_vibr(KAL_FALSE);
    Delayms(100);
    track_drv_set_vibr(KAL_TRUE);
    Delayms(200);
    track_drv_set_vibr(KAL_FALSE);
}

/*---------------------------------------------------------------------------
 * FUNCTION			track_cust_Vibration_100ms
 *
 * DESCRIPTION		振动器持续振动100ms
 *
 * PARAMETERS
 *		kal_bool
 * RETURNS
 *  		void
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-10-2013,  wangqi  written
 * ----------------------------------------
 *---------------------------------------------------------------------------*/
void track_cust_Vibration_100ms(void)
{
    track_drv_set_vibr(KAL_TRUE);
    Delayms(100);
    track_drv_set_vibr(KAL_FALSE);
}

typedef struct
{
    kal_uint32 keep_on;
    kal_uint32 keep_off;
    kal_uint8   overtimer;
} vib_setting_struct;

vib_setting_struct * track_cust_vib_interval(kal_uint8 overtime, kal_uint32 ontime, kal_uint32 offtime)
{
    static vib_setting_struct vib_setting = {1000, 2000, 20};

    if(overtime || ontime || offtime)
    {
        vib_setting.overtimer = overtime;
        vib_setting.keep_on = ontime;
        vib_setting.keep_off = offtime;
    }

    LOGD(L_APP, L_V6, "on:%d, off:%d, count:%d", vib_setting.keep_on, vib_setting.keep_on, vib_setting.overtimer);
    return &vib_setting;
}
/*---------------------------------------------------------------------------
 * FUNCTION			track_cust_ring_Vibration
 *
 * DESCRIPTION		循环震动
 *  两秒震动一次 20次需要一分钟，打一次电话震动最长时间一分钟，如果有异常
 *  没有事件关闭震动，此函数可以自己主动关闭震动。
 * PARAMETERS
 *		kal_bool
 * RETURNS
 *  		void
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-10-2013,  wangqi  written
 * ----------------------------------------
 *---------------------------------------------------------------------------*/
void track_cust_ring_Vibration(void * go_on)
{
    static kal_uint8 vib_count = 0;
    int go_next = (int) go_on;
    vib_setting_struct *vib_setting = track_cust_vib_interval(0, 0, 0);

    LOGD(L_APP, L_V7, "go_on:%d, vib_count:%d", go_on, vib_count);

    if(go_next == 0 || vib_count > vib_setting->overtimer)
    {
        vib_count = 0;
        track_stop_timer(TRACK_CUST_RING_VIB_TIMER_ID);
        track_drv_set_vibr(KAL_FALSE);
    }
    else if(go_next == 1)
    {
        ++vib_count;
        track_drv_set_vibr(KAL_TRUE);

        track_start_timer(TRACK_CUST_RING_VIB_TIMER_ID, vib_setting->keep_on, track_cust_ring_Vibration, (void*)2);
    }
    else if(go_next == 2 && vib_setting->keep_off)
    {
        track_drv_set_vibr(KAL_FALSE);
        track_start_timer(TRACK_CUST_RING_VIB_TIMER_ID, vib_setting->keep_off, track_cust_ring_Vibration, (void*)1);
    }
}

/******************************************************************************
 *  Function    -  track_cust_sos_or_center_check
 *
 *  Purpose     -  输入号码与SOS号码和中心号码比较
 *
 *  Parameter   -
 *      type：
 *            1：与中心号码比对
 *            2：与SOS号码比对
 *            3：与中心号码、SOS比对
 *            4: 与FN号码对比较
 *            5: 与WN号码对比较
 *            6: 与SOS FN WN号码对比
 *      num：输入号码
 *
 *  Return      -
 *      0xff：输入号码为空

 *      1：中心号码已设置，但与输入号码不相符
 *      4：中心号码未设置
 *      7：与中心号码相符

 *      2：SOS已设置，但与输入号码不相符
 *      5：SOS未设置
 *      8：与SOS号码相符 8 16 32 40

 *      3：SOS或中心号码已设置，但与输入号码都不相符
 *      6：SOS、中心号码都未设置
 *      9：与SOS号码或中心号码号码相符
 *      10: 与FN号码号码相符
 *      11: 与WN号码号码相符
 *      12: 与SOS FN WN号码号码相符
 *      13: FN 号码已设置，但与输入号码不相符
 *      14: WN号码已设置，但与输入号码不相符
 *      15: SOS FN WN号码为空
 *      17: SOS FN WN号码已设置，但与输入号码不相符
 *  modification history
 * ----------------------------------------
 * v1.0  , 20-11-2012,  Cml  written
 * v1.1  , 12-12M-2013,  Wangqi  modify
 * ----------------------------------------
*******************************************************************************/
kal_uint8 track_cust_sos_or_center_check(kal_int8 type, char *number)
{
    int i;
    kal_uint8 ret, flag, fn = 0, wn = 0;
    kal_uint32 num, num2;

    if(strlen(number) == 0)
    {
        return 0xff;
    }

    num = track_fun_convert_phone_number_to_int(number);
    LOGD(L_APP, L_V6, "type=%d, num=%d", type, num);
    if(type == 1 || type == 3)
    {
        if(strlen(G_parameter.centerNumber) > 0)
        {
            num2 = track_fun_convert_phone_number_to_int(G_parameter.centerNumber);
            LOGD(L_APP, L_V6, "num2=%d", num2);
            if(num == num2)
            {
                ret = 7;
            }
            else
            {
                ret = 1;
            }
        }
        else
        {
            ret = 4;
        }
        if(type == 1)
        {
            return ret;
        }
    }

    if(type == 2 || type == 3 || type == 6)//SOS
    {
        flag = 5;
        for(i = 0; i < TRACK_DEFINE_SOS_COUNT; i++)
        {
            if(strlen(G_parameter.sos_num[i]) > 0)
            {
                num2 = track_fun_convert_phone_number_to_int(G_parameter.sos_num[i]);
                LOGD(L_APP, L_V6, "sos%d=%d", i, num2);
                if(num == num2)
                {
                    flag = 8 * (i + 1);
                    break;
                }
                else
                {
                    flag = 2;
                }
            }
        }
        if(type == 2)
        {
            return flag;
        }
    }

    if(type == 4 || type == 6)//FN
    {
        for(i = 0; i < TRACK_DEFINE_FN_COUNT; i++)
        {
            if(strlen(G_phone_number.fn_num[i]) > 0)
            {
                num2 = track_fun_convert_phone_number_to_int(G_phone_number.fn_num[i]);
                LOGD(L_APP, L_V6, "fn num%d=%d", i, num2);
                if(num == num2)
                {
                    fn = 10;
                    break;
                }
                else
                {
                    fn = 13;
                }
            }
        }
        if(type == 4)
        {
            return fn;
        }
    }

    if(type == 5 || type == 6)//WN
    {
        for(i = 0; i < TRACK_DEFINE_WN_COUNT; i++)
        {
            if(strlen(G_phone_number.white_num[i]) > 0)
            {
                num2 = track_fun_convert_phone_number_to_int(G_phone_number.white_num[i]);
                LOGD(L_APP, L_V6, "wn num%d=%d", i, num2);
                if(num == num2)
                {
                    wn = 11;
                    break;
                }
                else
                {
                    wn = 14;
                }
            }
        }
        if(type == 5)
        {
            return wn;
        }
    }

    if(type == 3)
    {
        if(ret == 7 || flag % 8 == 0)
        {
            return 9;
        }
        if(ret == 4 && flag == 5)
        {
            return 6;
        }
        return 3;
    }
    else if(type == 6)
    {
        if(fn == 10 || wn == 11 || flag % 8 == 0)
        {
            ret = 12;//至少有一个相等
        }
        else if(flag == 2 || fn == 13 || wn == 14)
        {
            ret = 17;//都他妈不相等
        }
        else
        {
            ret = 15;//纯洁的FN SOS WN
        }
    }
    return ret;
}

/******************************************************************************
 *  Function    -  track_cust_make_call
 *
 *  Purpose     -  循环呼叫结束控制
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
    kal_uint8 track_cust_make_call(void* arg)
{
    static kal_uint8 handUp = 0;
    static kal_uint8 flag = 0;
    kal_uint32 par = (kal_uint32)arg;
    LOGD(L_APP, L_V5, "%d, handUp=%d, flag=%d", par, handUp, flag);
    if(par == 99)
    {
        return flag;
    }
    else if(par == 0)
    {
        flag = 0;
        LOGD(L_APP, L_V4, "!!! 循环呼叫流程结束 !!!");
        track_cust_module_alarm_lock(99, 0);
    }
    else if(par == 1)
    {
        track_cust_dial_makecall((void *)0);//关闭主动循环拨打电话流程
        if(flag != 0)
        {
            LOGD(L_APP, L_V4, "当前存在正在进行的循环呼叫，本次请求忽略。");
            return flag;
        }

#if defined(__LUYING__)
                if(track_cust_is_recording(0xff))
                {
                    track_cust_close_record();
                }
#endif

        flag = 1;
        handUp = 0;
        track_os_intoTaskMsgQueueExt(track_cust_make_call_function, (void*)1);
    }
    else if(flag == 1 && par == 21)   // 接通电话
    {
        LOGD(L_APP, L_V4, "!!! 接通电话 !!!");
        handUp = 1;
        tr_stop_timer(TRACK_CUST_SCROLL_MAKECALL_TIMER);
    }
    else if(flag == 1 && par == 22)   // 挂断电话
    {
        if(handUp)
        {
            handUp = 0;
            flag = 0;
            LOGD(L_APP, L_V4, "!!! 循环呼叫流程结束 !!!defined");
            track_cust_module_alarm_lock(99, 0);
        }
        else
        {
            track_start_timer(TRACK_CUST_SCROLL_MAKECALL_TIMER, 20000, track_cust_make_call_function, NULL);
        }
    }
    else if(par == 23) //sos呼叫中主动挂机，停掉sos呼叫流程
    {
        tr_stop_timer(TRACK_CUST_SCROLL_MAKECALL_TIMER);
        handUp = 0;
        flag = 0;
        LOGD(L_APP, L_V4, "!!! 挂机循环呼叫流程结束 !!!defined");
        track_cust_module_alarm_lock(99, 0);
    }
    return flag;
}

/******************************************************************************
 *  Function    -  track_cust_soscall_OverTime_call
 *
 *  Purpose     -  循环呼叫超时，重置状态
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void track_cust_soscall_OverTime_call()
{
    track_cust_sos_call_status(CALL_MO_OUT, CALL_MO_NORSP);
}

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

/******************************************************************************
 *  Function    -  track_cust_make_call_function
 *
 *  Purpose     -  循环呼叫处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_make_call_function(void *arg)
{
    static kal_uint8 call_ind = 0;                  //轮流拨打每个设定的亲情号
    static kal_uint8 ScrollDialNumber = 0;    //亲情号码最多循环拨打三次
    kal_uint32 par = (kal_uint32)arg;
    kal_bool sms_send_status = track_sms_get_send_status();
    kal_int8 is_sos_alarm = track_cust_module_alarm_lock(TR_CUST_ALARM_SOS, 2);

    LOGD(L_APP, L_V5, "par=%d, ScrollDialNumber=%d,call_ind=%d,sms:%d, sos_alarm:%d",
         par, ScrollDialNumber, call_ind, sms_send_status, is_sos_alarm);

    if(par == 1)
    {
        call_ind = 0;
        ScrollDialNumber = 0;
        LOGD(L_APP, L_V4, "!!! 循环呼叫流程开始 !!!");
    }
    track_os_intoTaskMsgQueue(track_soc_disconnect); // 通过测试反馈，繁忙的GPRS通讯会影响电话的成功呼叫。
    if(sms_send_status != 0)
    {
        track_start_timer(TRACK_CUST_SCROLL_MAKECALL_TIMER, 1000, track_cust_make_call_function, NULL);
    }
    else if(track_is_in_call())
    {
        track_cust_key_dail_way(2);
        track_cust_call_hangup();
        track_start_timer(TRACK_CUST_SCROLL_MAKECALL_TIMER, 1000, track_cust_make_call_function, NULL);
    }
    else
    {
        if(call_ind == TRACK_DEFINE_SOS_COUNT)
        {
            call_ind = 0;
            ScrollDialNumber++;
        }
        if(ScrollDialNumber < G_parameter.redial_count)
        {
            if((G_phone_number.almrep[call_ind] || is_sos_alarm == 1) && strlen(G_parameter.sos_num[call_ind]))
            {
                g_call_status = 4;

                LED_GSM_StatusSet(GSM_IN_CALL_STATE);

#if defined(__AUDIO_RC__)
                track_cust_monitor_set_speaket(1);
#endif /* __AUDIO_RC__ */
                track_cust_key_dail_way(0x0);
                track_cust_call(G_parameter.sos_num[call_ind]);
                tr_start_timer(TRACK_CUST_SCROLL_MAKECALL_OVERTIME_TIMER, 120000, track_cust_soscall_OverTime_call);
                if(0 == G_parameter.Permission.AlarmNumCount)
                {
                    ScrollDialNumber++;
                }
                else
                {
                    call_ind++;
                }

            }
            else
            {
                call_ind++;
                track_cust_make_call_function(NULL);
            }
        }
        else
        {
            if(track_cust_make_call((void*)99))
            {
                track_cust_make_call((void*)0);
            }
        }
    }
}
void track_cust_sos_gps_dalay(void)
{
    track_cust_module_alarm_lock(TR_CUST_ALARM_SOS, 0);
    //track_cust_module_alarm_set_type(0);
    track_alarm_vec_queue_remove(2, 0, TR_CUST_ALARM_SOS);
}
/******************************************************************************
 *  Function    -  track_cust_soscall_OverTime_sendsms
 *
 *  Purpose     -  发送SOS报警短信
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
#if defined(__NF2318__)
void track_cust_soscall_OverTime_sendsms(void)
{;}
#else
void track_cust_soscall_OverTime_sendsms(void)
{
    track_gps_data_struct *gpsLastPoint = NULL;
    if(G_parameter.sos_alarm.sw)
    {

        if(G_parameter.sos_alarm.alarm_type > 0 && G_parameter.sos_alarm.alarm_type < 3)
        {
            memset(&g_msg, 0, sizeof(struct_msg_send));
#if defined (__GT370__)|| defined (__GT380__)|| defined(__ET310__)||defined(__GT300S__) || defined(__MT200__)
            LOGD(L_APP, L_V6, "g_alarm_gps_status = %d", g_alarm_gps_status);
            if(g_alarm_gps_status == 1 || track_cust_gps_status() > 2)
            {
                gpsLastPoint = track_cust_backup_gps_data(0, NULL);
                memcpy(&gps_data_buf, gpsLastPoint, sizeof(track_gps_data_struct));
                g_alarm_gps_status = 0;
            }
            LOGD(L_APP, L_V6, "gprmc.status = %d", gps_data_buf.gprmc.status);
            if(gpsLastPoint != NULL && gpsLastPoint->gprmc.status == 1) //gps_data_buf.gprmc.status == 1
            {
                g_msg.addUrl = KAL_TRUE;
            }
            else
            {
                g_msg.addUrl = KAL_FALSE;
            }
#else
            g_msg.addUrl = KAL_TRUE;
#endif
            g_msg.cm_type = CM_SMS;

            g_msg.not_need_almrep = 1;
            if(g_msg.addUrl == KAL_TRUE)
            {
#if defined(__SPANISH__)
                track_fun_strncpy(g_msg.msg_en, G_parameter.sos_alarm.alarm_sms_head, CM_PARAM_LONG_LEN_MAX);
#else
                track_fun_strncpy(g_msg.msg_en, msg_alarm_sos_en, CM_PARAM_LONG_LEN_MAX);
#endif
                g_msg.msg_cn_len = 10;                
                memcpy(g_msg.msg_cn, msg_alarm_sos_cn, g_msg.msg_cn_len);
            }
            else
            {

                track_fun_strncpy(g_msg.msg_en, msg_alarm_sos_en1, CM_PARAM_LONG_LEN_MAX);
                g_msg.msg_cn_len = 18;
                memcpy(g_msg.msg_cn, msg_alarm_sos_cn1, g_msg.msg_cn_len);
            }
            g_msg.is_sos_alarm_type = TRUE;
            track_cust_module_alarm_msg_send(&g_msg, &gps_data_buf);
        }
        else
        {
            LOGD(L_APP, L_V4, "SOS报警，报警类型设置无需短信通知！");
        }
    }

    if(G_parameter.sos_alarm.alarm_type == 2 || G_parameter.sos_alarm.alarm_type == 3)
    {
        track_start_timer(TRACK_CUST_SOS_MAKECALL_TIMER, 60000, track_cust_make_call, (void*)1);
    }
    else
    {
        track_cust_module_alarm_lock(TR_CUST_ALARM_SOS, 0);
    }
    //track_cust_module_alarm_set_type(0);
    track_alarm_vec_queue_remove(2, 0, TR_CUST_ALARM_SOS);
}
#endif
/******************************************************************************
 *  Function    -  track_cust_module_sos_trigger_button
 *
 *  Purpose     -  SOS按键
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 25-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
#if defined(__NF2318__)
void track_cust_module_sos_trigger_button(void){;};
#else
void track_cust_module_sos_trigger_button(void)
{
    track_gps_data_struct *gpsLastPoint = NULL;
    U16 sn;
    kal_uint8 call_state = track_get_call_state();

#if defined(__GT300S__)
    if(G_parameter.sos_alarm.sw)
    {
        ControlVibration();
    }
#endif
    if(track_cust_status_sim() != 1 || !G_parameter.sos_alarm.sw)
    {
        return;
    }

#if defined( __OLED__)
    track_cust_lcd_sos();
#endif /* __OLED__ */

    LOGD(L_APP, L_V4, "!!! SOS 报警 !!! call_state:%d", call_state);
    if(track_cust_module_alarm_lock(TR_CUST_ALARM_SOS, 2) != 0)
    {
        LOGD(L_APP, L_V4, "上一SOS请求未完成!");
        return;
    }
#if defined(__GT300S__)
    if(TR_CALL_SETUP <= call_state && call_state <= TR_CALL_DISCONNECT)
    {
        track_cust_key_dail_way(2);
        track_cust_call_hangup();
    }
#endif
#if defined(__NT36__)
    if(g_monitor_call_status == 2)
    {
        LOGD(L_APP, L_V4, "当前正在监听中，SOS被触发，强制挂断监听，处理SOS报警流程.");
        track_cust_call_hangup();
    }
#endif
    track_cust_module_alarm_lock(TR_CUST_ALARM_SOS, 1);
    LOGD(L_APP, L_V5, "gprson:%d, alarm_type:%d", G_parameter.gprson, G_parameter.sos_alarm.alarm_type);
    gpsLastPoint = track_cust_gpsdata_alarm();
    memcpy(&gps_data_buf, gpsLastPoint, sizeof(track_gps_data_struct));
    if(g_GT03D == KAL_TRUE)
    {
        g_alarm_gps_status = 0;
        track_cust_gprson_status(1);
        track_soc_gprs_reconnect((void*)307);

        if(track_cust_gps_status() > 2)
        {
            g_alarm_gps_status = 1;
        }
        else
        {
            track_cust_gps_work_req((void *)10);
            if(G_parameter.lang == 1 || track_cust_gprson_status(99) == 1)
            {
                track_cust_send_paket_16(2, gpsLastPoint, 0);
            }
            /*超时短信统一管理*/
        }
        if(track_cust_gprson_status(99) == 1)
        {
            track_cust_alarm_type(TR_CUST_ALARM_SOS);
            if(g_alarm_gps_status == 1)
            {
                sn = track_cust_paket_16(gpsLastPoint, track_drv_get_lbs_data(), TR_CUST_ALARM_SOS, KAL_TRUE, 1);
                g_last_alerm_no = sn;
                tr_start_timer(TRACK_CUST_SOS_SMS_OVERTIME_TIMER, 60 * 1000, track_cust_soscall_OverTime_sendsms);
            }
            else
            {
                sn = track_cust_paket_19(track_drv_get_lbs_data(), TR_CUST_ALARM_SOS, KAL_TRUE, 1);
                g_last_alerm_no = sn;

                tr_start_timer(TRACK_CUST_SOS_SMS_OVERTIME_TIMER, 5 * 60 * 1000, track_cust_soscall_OverTime_sendsms);

            }
        }

        if(G_parameter.sos_alarm.alarm_type == 3)
        {
            tr_stop_timer(TRACK_CUST_SOS_GPS_DELAY_TIMER_ID);
            tr_stop_timer(TRACK_CUST_SOS_SMS_OVERTIME_TIMER);
            track_alarm_vec_queue_remove(2, 0, TR_CUST_ALARM_SOS);

            track_start_timer(TRACK_CUST_SOS_MAKECALL_TIMER, 10 * 1000, track_cust_make_call, (void*)1);

        }

        else if(G_parameter.sos_alarm.alarm_type > 0)
        {
            if(G_parameter.lang == 0 || track_cust_gprson_status(99) == 0)
            {
                tr_stop_timer(TRACK_CUST_SOS_GPS_DELAY_TIMER_ID);
                tr_stop_timer(TRACK_CUST_SOS_SMS_OVERTIME_TIMER);
                track_os_intoTaskMsgQueue(track_cust_soscall_OverTime_sendsms);
            }
        }
        else
        {
            track_cust_module_alarm_lock(TR_CUST_ALARM_SOS, 0);
        }

    }
    else
    {
        if(G_parameter.gprson)
        {
            sn = track_cust_paket_16(gpsLastPoint, track_drv_get_lbs_data(), TR_CUST_ALARM_SOS, KAL_TRUE, 1);
            g_last_alerm_no = sn;
        }
        if(G_parameter.sos_alarm.alarm_type == 3)
        {
            track_alarm_vec_queue_remove(2, 0, TR_CUST_ALARM_SOS);
            track_cust_make_call((void*)1);
        }
        else if(G_parameter.sos_alarm.alarm_type > 0)
        {
            if(G_parameter.lang == 0 || G_parameter.gprson == 0)
            {
                track_os_intoTaskMsgQueue(track_cust_soscall_OverTime_sendsms);
            }
            else
            {
                tr_start_timer(TRACK_CUST_SOS_SMS_OVERTIME_TIMER, TRACK_ALARM_DELAY_TIME_SECONDS, track_cust_soscall_OverTime_sendsms);
            }
        }
        else
        {
            track_cust_module_alarm_lock(TR_CUST_ALARM_SOS, 0);
        }
    }
}
#endif
void track_call_sos_incall(void)
{
#if defined( __NT31__) 

#else
    track_cust_call_accept();
#endif
    g_monitor_call_status = 1;
}
/******************************************************************************
 *  Function    -  track_cust_sos_call_status
 *
 *  Purpose     -  呼叫状态变更
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * v1.1  , 29-10-2013,  Wangqi  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_sos_call_status(kal_uint16 call_type, kal_uint16 callState)
{
    static kal_bool is_incall = FALSE;
    static kal_bool flag = KAL_FALSE;
    CMD_DATA_STRUCT  Cmds = {0};
    static kal_bool is_host = KAL_FALSE;
    static kal_uint32 s_tick = 0, e_tick = 0;
    CMD_DATA_STRUCT cmd = {0};
    kal_int8 len = 0;

    LOGD(L_APP, L_V5, "call_type=%d,callState=%d, g_call_status=%d", call_type, callState, g_call_status);
    if(call_type == CALL_FREE)
    {
        return;
    }
    switch(callState)
    {
        case CALL_MO_SMS_BUSY:  /* 正在发送短信 */
        case TR_CALL_MT_BUSY:
        case CALL_MO_BUSY:
            break;

        case TR_CALL_SETUP:  /* 来电 */
            g_call_status = 1;
            break;

        case TR_CALL_RING: //响铃/
            g_call_status = 2;
            s_tick = kal_get_systicks();
            LOGD(L_APP, L_V5, "响铃 s_tick=%d, %d", s_tick, track_cust_get_work_mode());

	     flag = KAL_TRUE;

            if(flag)
            {
                kal_bool permit = KAL_FALSE;
                kal_uint8 snw_number = 0, sos_number = 0;
                char *num = track_cust_call_get_incomming_number();
#if defined (__NETWORK_LICENSE__) 
                track_drv_network_license_auto_answer_action();
                //直接全部自动接听
                break;
#endif /* __NETWORK_LICENSE__ */

#if defined(__LUYING__)
/*录音时不能通话       --    chengjun  2017-10-09*/
                if(track_cust_is_recording(0xff))
                {
                    track_cust_close_record();
                }
#endif


#if defined(__GT300S__)
                track_drv_sleep_enable(SLEEP_CALL_MOD, FALSE);
                snw_number = track_cust_sos_or_center_check(6, track_cust_call_get_incomming_number());
                sos_number = track_cust_sos_or_center_check(2, track_cust_call_get_incomming_number());
                LOGD(L_APP, L_V5, "snw_number = %d, sos:%d, num:%s", snw_number, sos_number, num);
                if(snw_number == 17&&(G_parameter.Permission.MonPermit != 3))
                {
                    track_cust_call_hangup();
                    break;
                }
                else if(sos_number % 8 != 0)
                {
#ifndef __GT300S__
                    if(!track_cust_is_working_mode4() && !track_cust_is_mute_mode())
                    {
                        track_cust_audio_play_voice(MT_RING);
                    }
#endif /* __GT300S__ */

					LED_GSM_StatusSet(GSM_IN_CALL_STATE);
                }
                else
                {
                    LOGD(L_APP, L_V5, "亲情号码%d呼入:num:%s", sos_number + 1, num);
                }
#elif defined(__SPANISH__)
                sos_number = track_cust_sos_or_center_check(2, track_cust_call_get_incomming_number());
                if(sos_number % 8 != 0)
                {
                    track_cust_call_hangup();
                    break;
                }
                else
                {
                    LED_GSM_StatusSet(GSM_IN_CALL_STATE);
                }
				
#else
                LED_GSM_StatusSet(GSM_IN_CALL_STATE);

#if defined (__NO_MIC__)
                return;
#endif /* __NO_MIC__ */
#endif
                LOGD(L_APP, L_V5, "flag=%d, MonPermit=%d, num:%s", flag, G_parameter.Permission.MonPermit, num);
                flag = KAL_FALSE;


                if(G_parameter.Permission.MonPermit == 3)
                {
                    permit = KAL_TRUE;
                }
                else
                {
                    kal_uint8 cen;
                    if(strlen(num) > 0)
                    {
                        if(G_parameter.Permission.MonPermit == 1)
                        {
                            cen = track_cust_sos_or_center_check(1, num);
                            if(cen == 7)
                            {
                                permit = KAL_TRUE;
                            }
                        }
                        else if(G_parameter.Permission.MonPermit == 2)
                        {
                            cen = track_cust_sos_or_center_check(3, num);
                            if(cen == 9)
                            {
                                permit = KAL_TRUE;
                            }
                        }
                        LOGD(L_APP, L_V5, "TR_CALL_SETUP, Call authentication %s,%d", num, cen);
                        /*if(cen <= 3)     // SOS号码或中心号码不为空且不相符自动挂断
                        {
                            track_cust_call_hangup();
                        }*/
                    }
                }

                if(permit)
                {
                    /*应刘工20140712日邮件要求通话时切换到免提*/
                    track_drv_sys_l4cuem_set_audio_mode(track_status_audio_mode(0xFF));
                    // 监听功能，SOS号码呼入自动接起//加300ms避免和RING上发时冲突RING两秒一次
                    LOGD(L_APP, L_V5, "TR_CALL_RING sos index:%s: %ds后自动接起", num, G_parameter.monitor_delay);
                    tr_start_timer(TRACK_CUST_SOS_IN_CALL_TIMER, G_parameter.monitor_delay * 1000 + 300, track_call_sos_incall);
                }

            }
            break;

        case TR_CALL_CONNECT: /* 接通 */

            track_stop_timer(TRACK_CUST_SCROLL_MAKECALL_OVERTIME_TIMER);
            g_call_status = 3;
            if(g_monitor_call_status == 1) g_monitor_call_status = 2;
            flag = KAL_FALSE;
            track_cust_make_call((void*)21);
            track_cust_dial_makecall((void*)21);
            if(track_is_timer_run(TRACK_CUST_SOS_IN_CALL_TIMER) == TRUE)
            {
                track_stop_timer(TRACK_CUST_SOS_IN_CALL_TIMER);
            }
#if (defined(__NT36__)) && defined(__AUDIO_RC__)
            if(call_type == CALL_MO_OUT)
            {
                track_cust_monitor_set_speaket(1);
            }
            else
            {
                track_cust_monitor_set_speaket(0);

            }
#else
            LED_GSM_StatusSet(GSM_IN_CALL_STATE);
#endif
            break;

        case CALL_MO_ATUNRSP:
        case TR_CALL_NULL_NO: /* 为空 */
        case TR_CALL_ERROR:
        case CALL_MO_SIMERROR:
        case CALL_MO_NUMBERERROR:
        case CALL_MO_UNKNOWERROR:
        case CALL_MO_NORSP:
        case CALL_GETNUMBERERROR:
            //track_cust_call_hangup();
        case TR_CALL_DISCONNECT:
            {
                kal_uint8 sos_hung_up = track_cust_key_dail_way(0xFF);
                LOGD(L_APP, L_V5, "tick %d,%d,%d,%d", s_tick, G_parameter.call_get_addr_sw, kal_get_systicks() - s_tick, 10 * KAL_TICKS_1_SEC);
                if(s_tick != 0 && G_parameter.call_get_addr_sw && kal_get_systicks() - s_tick < 10 * KAL_TICKS_1_SEC)
                {
                    static CMD_DATA_STRUCT cmd;
                    s_tick = 0;
                    memset(&cmd, 0, sizeof(CMD_DATA_STRUCT));
                    cmd.pars[0] = "DW";
                    cmd.return_sms.cm_type = CM_SMS;
                    snprintf(cmd.return_sms.ph_num, 32, "%s", track_cust_call_get_incomming_number());
                    track_cust_module_get_addr(&cmd);
                }

                track_cust_key_dail_way(0);

                track_stop_timer(TRACK_CUST_SCROLL_MAKECALL_OVERTIME_TIMER);
                flag = KAL_FALSE;
                g_call_status = 0;

                LED_GSM_StatusSet(GSM_NORMAL_STATE);

    #if defined(__GT300S__)
                if(track_cust_led_sleep(99) == 0 || G_realtime_data.key_status == 0 || track_cust_led_sleep(99) == 2)
                {
                    track_cust_led_sleep(2);
                }
                else
    #endif
                    if(track_cust_status_defences() == 2)
                    {
                        track_stop_timer(TRACK_CUST_MODULE_ALARM_VIBRATES_TIMER_ID);
                        track_cust_led_defences(2);
                    }
                //track_stop_timer(TRACK_CUST_INCOMING_CALL_PLAY_TONE_TIMER);
                track_cust_make_call((void*)22);
                track_cust_dial_makecall((void*)22);

#if defined(__NT31__)||defined(__NT36__)
                /*            if(track_is_timer_run(TRACK_CUST_SOS_IN_CALL_TIMER) == TRUE)
                            {
                                    track_stop_timer(TRACK_CUST_SOS_IN_CALL_TIMER);
                                    cmd.return_sms.cm_type = CM_SMS;
                                    memcpy(&cmd.return_sms.ph_num, track_cust_call_get_incomming_number(), strlen(track_cust_call_get_incomming_number()));
                                    track_cust_gt03_dw(&cmd);
                            }
                            */
#else
                if((track_is_timer_run(TRACK_CUST_SOS_IN_CALL_TIMER) == TRUE) && g_GT03D == KAL_TRUE && sos_hung_up != 2)
                {
                    track_stop_timer(TRACK_CUST_SOS_IN_CALL_TIMER);
                    memcpy(Cmds.return_sms.ph_num, track_cust_call_get_incomming_number(), strlen(track_cust_call_get_incomming_number()));
                    Cmds.return_sms.cm_type = CM_SMS;
                    if(track_cust_status_defences() != 0)
                    {
                        track_cust_check_sos_incall(&Cmds, 0);
                    }
                    else
                    {
                        track_cust_check_sos_incall(&Cmds, 2);
                    }
                }
                else
                {
                    track_stop_timer(TRACK_CUST_SOS_IN_CALL_TIMER);
                }
#endif
            }
            break;

        default:
            break;
    }

}

/******************************************************************************
 *  Function    -  track_cust_module_call_status
 *
 *  Purpose     -  返回呼叫状态
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_uint8 track_cust_module_call_status(void)
{
    LOGD(L_APP, L_V5, "g_call_status=%d", g_call_status);
    return g_call_status;
}

void track_cust_online_cmd(kal_uint8 *stamp, char *cmdstr)
{
    char        *data_ptr, split_ch = ',';
    int         cmd_Len, par_len, i, ll;
    char        *pars[17];
    char        *Success = "WN=Success!", *Fail = "WN=Fail!";
    kal_uint8   *sendData, *p;

    LOGD(L_APP, L_V5, "online cmd=%s", cmdstr);
    par_len = track_fun_str_analyse(cmdstr, pars, 17, NULL, "#", split_ch);
    LOGD(L_APP, L_V5, "online cmd[%d]=%s,%s,%s", par_len, pars[0], pars[1], pars[2]);
    if(par_len > 17 || par_len < 0)
    {
        track_cust_paket_msg_upload(stamp, KAL_TRUE, Fail, strlen(Fail));
        return;
    }

    if(!strcmp(pars[0], "WN"))
    {
        if(par_len == 17 && !strcmp(pars[1], "A"))
        {
            for(i = 0; i < TRACK_DEFINE_WN_COUNT; i++)
            {
                ll = strlen(pars[2 + i]);
                if(ll == 0)
                {
                    memset(G_phone_number.white_num[i], 0, TRACK_DEFINE_PHONE_NUMBER_LEN_MAX);
                }
                else if(ll < TRACK_DEFINE_PHONE_NUMBER_LEN_MAX && track_fun_check_phone_number(pars[2 + i]) >= 3)
                {
                    memset(G_phone_number.white_num[i], 0, TRACK_DEFINE_PHONE_NUMBER_LEN_MAX);
                    memcpy(G_phone_number.white_num[i], pars[2 + i], ll);
                    LOGD(L_APP, L_V5, "wn:%d,number=%s", i, G_phone_number.white_num[i]);
                }
                else
                {
                    Track_nvram_read(NVRAM_EF_PHONE_NUMBER_LID, 1, (void *)&G_phone_number, NVRAM_EF_PHONE_NUMBER_SIZE);
                    track_cust_paket_msg_upload(stamp, KAL_TRUE, Fail, strlen(Fail));
                    return;
                }
            }
            Track_nvram_write(NVRAM_EF_PHONE_NUMBER_LID, 1, (void *)&G_phone_number, NVRAM_EF_PHONE_NUMBER_SIZE);
            track_cust_paket_msg_upload(stamp, KAL_TRUE, Success, strlen(Success));
        }
        else if(par_len == 1)
        {
            sendData = (U8*)Ram_Alloc(5, 500);
            if(sendData == NULL)
            {
                LOGD(L_APP, L_V1, "Ram_Alloc NULL!!");
                return;
            }
            ll = snprintf(sendData, TRACK_DEFINE_PHONE_NUMBER_LEN_MAX, "WN=%s", G_phone_number.white_num[0]);
            p = sendData + ll;
            for(i = 1; i < TRACK_DEFINE_WN_COUNT; i++)
            {
                ll = sprintf(p, ",%s", G_phone_number.white_num[i]);
                p += ll;
                if(p - sendData > 450)
                {
                    LOGD(L_APP, L_V5, "长度超长!");
                    track_cust_paket_msg_upload(stamp, KAL_TRUE, Fail, strlen(Fail));
                    return;
                }
            }
            LOGD(L_APP, L_V6, "上传数据:%s", sendData);
            track_cust_paket_msg_upload(stamp, KAL_TRUE, sendData, strlen(sendData));
            Ram_Free(sendData);
        }
    }
}

kal_uint8 track_cust_get_SOS_callout(void)
{
    kal_uint8 issos = track_cust_sos_or_center_check(2, track_cust_call_get_incomming_number());
    kal_uint8 isFN_call = track_cust_key_dail_way(0xFF);
    kal_uint8 call_type = track_get_incall_type();
    LOGD(L_APP, L_V5, "SOS:%d,FN call:%d, call_type:%d", issos, isFN_call, call_type);

    if(issos % 8 == 0 && isFN_call == 0 && call_type == CALL_MO_OUT) //终端主动呼出
    {
        return 1;
    }
    return 0;
}

void track_cust_set_call_state(void)
{
    g_call_status = 1;
}



void track_cust_dial_makecall_function(void *arg)
{
    kal_uint32 status = (kal_uint32)arg;
    static kal_uint8 ScrollDialNumber = 0;    //亲情号码最多循环拨打三次
    static kal_uint8 ScrollDialCount = 1;//默认拨打一次电话
    kal_bool sms_send_status = track_sms_get_send_status();

    LOGD(L_APP, L_V5, "status=%d, ScrollDialNumber=%d,sms:%d ",
         status, ScrollDialNumber, sms_send_status);
    LOGD(L_APP, L_V5, "num=%s", dail_num);

    if(status == 1)
    {
        ScrollDialNumber = 0;
        if(dail_count > 0)
        {
            ScrollDialCount = dail_count;
        }
        else
        {
            ScrollDialCount = 1;
        }
        LOGD(L_APP, L_V4, "!!! 指令循环呼叫流程开始 !!!");
    }
    track_os_intoTaskMsgQueue(track_soc_disconnect); // 通过测试反馈，繁忙的GPRS通讯会影响电话的成功呼叫。
    if(sms_send_status != 0)
    {
        track_start_timer(TRACK_CUST_DAIL_MAKECALL_TIMER, 1000, track_cust_dial_makecall_function, NULL);
    }
    else if(track_is_in_call())
    {
        track_cust_key_dail_way(2);
        track_cust_call_hangup();
    }
    else
    {

        if(ScrollDialNumber < ScrollDialCount)
        {
            g_call_status = 4;

			LED_GSM_StatusSet(GSM_IN_CALL_STATE);


#if defined(__AUDIO_RC__)
            track_cust_monitor_set_speaket(1);
#endif /* __AUDIO_RC__ */
            track_cust_key_dail_way(0x0);
            track_cust_call(dail_num);
            tr_start_timer(TRACK_CUST_DAIL_MAKECALL_OVERTIME_TIMER, 120000, track_cust_soscall_OverTime_call);
            ScrollDialNumber++;
            LOGD(L_APP, L_V4, "!!!第(%d)次拨号总拨号(%d)次", ScrollDialNumber, ScrollDialCount);
        }
        else
        {
            if(track_cust_dial_makecall((void*)99))
            {
                track_cust_dial_makecall((void*)0);
            }
        }
    }
}
kal_uint8 track_cust_dial_makecall(void* arg)
{
    static kal_uint8 handUp = 0;
    static kal_uint8 flag = 0;
    kal_uint32 par = (kal_uint32)arg;
    LOGD(L_APP, L_V5, "%d, handUp=%d, flag=%d", par, handUp, flag);
    if(par == 99)
    {
        return flag;
    }
    else if(par == 0)
    {
        tr_stop_timer(TRACK_CUST_DAIL_MAKECALL_OVERTIME_TIMER);
        flag = 0;
        LOGD(L_APP, L_V4, "!!! 指令循环呼叫流程结束 !!!");
    }
    else if(par == 1)
    {
        if(flag != 0)
        {
            LOGD(L_APP, L_V4, "当前存在正在进行的指令循环呼叫，本次请求忽略。");
            return flag;
        }

    #if defined (__LUYING__)
        if(track_cust_is_recording(99) == 1)
        {
            LOGD(L_APP, L_V4, "正在录音,强制结束");
            track_cust_close_record();
        }
    #endif
    
        flag = 1;
        handUp = 0;
        track_os_intoTaskMsgQueueExt(track_cust_dial_makecall_function, (void*)1);
    }
    else if(flag == 1 && par == 21)   // 接通电话
    {
        handUp = 1;
        tr_stop_timer(TRACK_CUST_DAIL_MAKECALL_TIMER);
        tr_stop_timer(TRACK_CUST_DAIL_MAKECALL_OVERTIME_TIMER);
    }
    else if(flag == 1 && par == 22)   // 挂断电话
    {
        tr_stop_timer(TRACK_CUST_DAIL_MAKECALL_OVERTIME_TIMER);
        if(handUp)
        {
            handUp = 0;
            flag = 0;
            LOGD(L_APP, L_V4, "!!! 指令循环呼叫流程结束 !!!");
        }
        else
        {
            track_start_timer(TRACK_CUST_DAIL_MAKECALL_TIMER, 20000, track_cust_dial_makecall_function, NULL);
        }
    }
    else if(par == 23) //sos呼叫中主动挂机，停掉sos呼叫流程
    {
        tr_stop_timer(TRACK_CUST_DAIL_MAKECALL_TIMER);
        tr_stop_timer(TRACK_CUST_DAIL_MAKECALL_OVERTIME_TIMER);
        handUp = 0;
        flag = 0;
        LOGD(L_APP, L_V4, "!!! sos流程强制停止 !!!");
    }
    return flag;
}

U16 track_cust_sos_get_alarm_sn(void)
{
    return g_last_alerm_no;
}

