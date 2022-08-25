/******************************************************************************
 * track_cust_module_blind.c - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *        各种小报警功能
 *
 *  GPS盲区报警 关机报警 换卡报警 伪基站报警 摘除报警 开盖报警
 * 
 * modification history
 * --------------------
 * v1.0   2017-03-23,  chengjun create this file
 * 
 ******************************************************************************/
/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "track_cust.h"
#include "dcl_pw.h"
#include "dcl.h"


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
#if 0
#if defined(__GERMANY__)
static char *str_blind_in_en = "Achtung! GPS Signal ist schlecht - Position kann nicht bestimmt werden.";
#else
static char *str_blind_in_en = "Attention! GPS signal is weak, unable to locate in the region.";
#endif
static char str_blind_in_cn[34] =   //进入GPS信号盲区！
{
    0X8F , 0XDB, 0X51 , 0X65 , 0X00 , 0X47 , 0X00 , 0X50 , 0X00 , 0X53 , 0X4F , 0XE1 , 0X53 , 0XF7 , 0X76 , 0XF2 , 0X53 , 0X3A , 0XFF , 0X01
};

#if defined(__GERMANY__)
static char *str_blind_out_en = "GPS-Positionierung erfolgreich!";
#else
static char *str_blind_out_en = "GPS re-positioning successful!";
#endif
static char str_blind_out_cn[34] =   // 已离开GPS信号盲区！
{
    0X5D  , 0XF2  , 0X79  , 0XBB  , 0X5F  , 0X00  , 0X00  , 0X47  , 0X00  , 0X50  , 0X00  , 0X53 , 0X4F  , 0XE1 , 0X53  , 0XF7  , 0X76  , 0XF2  , 0X53  , 0X3A  , 0X00  , 0X21
};
static char  blind_status = 2; //0为处于盲区中，1为退出盲区，2为初始值不报
static char str_door_cn[22] =/*注意! 车门被打开 .*/
{
    0x6C , 0xE8 , 0x61 , 0x0F , 0x00 , 0x21 , 0x00 , 0x20 , 0x8F , 0x66 , 0x95 , 0xE8 , 0x88 , 0xAB , 0x62 , 0x53 , 0x5F , 0x00 , 0x00 , 0x20 , 0x00 , 0x2E
};

static char *str_door_en = "Attention! Vehicle side door is opened."; /*Attention! The door is open!*/
#if 0
static char *str_boot_en = "The The monitoring phone is power-on!";
static char str_boot_cn[16] =/*监护手机已开机！*/
{
    0x76, 0xD1 , 0x62, 0xA4 , 0x62 , 0x4B , 0x67 , 0x3A , 0x5D , 0xF2 , 0x5F , 0x00 , 0x67 , 0x3A , 0xFF , 0x01
};
#endif

static char *str_boot_en = "Terminal boot successfully!";
static char str_boot_cn[14] = /* 终端开机成功！ */
{
    0x7E, 0xC8, 0x7A, 0xEF, 0x5F, 0x00, 0x67, 0x3A, 0x62, 0x10, 0x52, 0x9F, 0xFF, 0x01
};


static char *str_gps_successfully_en = "GPS Successful positioning!";
static char str_gps_successfully_cn[16] =/*GPS定位成功!*/
{
    0X00 , 0X47 , 0X00 , 0X50 , 0X00 , 0X53 , 0X5B , 0X9A , 0X4F , 0X4D , 0X62 , 0X10 , 0X52 , 0X9F , 0X00 , 0X21
};

static char *str_sim_alarm_en = "The monitoring phone SIM card has been changed,please pay attention!";
static char str_sim_alarm_cn[32] =/*监护手机SIM卡已更换，请关注！*/
{
    0x76, 0xD1, 0x62, 0xA4, 0x62, 0x4B, 0x67, 0x3A, 0x00, 0x53, 0x00, 0x49, 0x00, 0x4D, 0x53, 0x61, 0x5D, 0xF2, 0x66, 0xF4, 0x63, 0x62, 0xFF, 0x0C, 0x8B, 0xF7, 0x51, 0x73, 0x6C, 0xE8, 0xFF, 0x01
};
static char *str_pwoffalm_en = "Attention! The monitoring phone is power-off!";
static char str_pwoffalm_cn[24] =/*请注意！监护手机已关机！*/
{
    0x8B, 0xF7, 0x6C, 0xE8, 0x61, 0x0F, 0xFF, 0x01, 0x76, 0xD1, 0x62, 0xA4, 0x62, 0x4B, 0x67, 0x3A, 0x5D, 0xF2, 0x51, 0x73, 0x67, 0x3A, 0xFF, 0x01
};
static char *str_teardown_en = "Attention!The device has been torn down!";
static char str_teardown_cn[18] = /*注意！设备被摘除！*/
{
    0x6C, 0xE8, 0x61, 0x0F, 0xFF, 0x01, 0x8B, 0xBE, 0x59, 0x07, 0x88, 0xAB, 0x64, 0x58, 0x96, 0x64, 0xFF, 0x01
};

static char *str_open_shell_en = "Attention!The device has been opened!";
static char str_open_shell_cn[18] = /*注意！设备被打开！*/
{
    0x6C, 0xE8, 0x61, 0x0F, 0xFF, 0x01, 0x8B, 0xBE, 0x59, 0x07, 0x88, 0xAB, 0x62, 0x53, 0x5F, 0x00, 0xFF, 0x01
};

static struct_msg_send g_msg = {0};
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
extern void track_fun_signed_LongitudeLatitudeToHex(kal_uint8 *dec, float value);
extern float track_fun_get_GPS_2Points_distance(float lat1, float lon1, float lat2, float lon2);
/*不要删除这个函数声明！ -- chengjun  2017-03-10*/

#if defined (__GT370__)|| defined (__GT380__)
extern void track_cust_poweroff_ready(void);
#endif /* __GT370__ */

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/

#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

PW_CTRL_POWER_ON_REASON mmi_Get_PowerOn_Type(void)
{
    extern kal_bool track_os_log_abnormal_is_net_error(void);
    static S8 count = 5;
    if(count > 0)
    {
        count--;
        LOGD(L_APP, L_V5, "gps_PWRon =%d", *OTA_gps_PWRon);
    }
    if(track_os_log_abnormal_is_net_error() == TRUE)
    {
        track_os_log_abnormal_net_error_set();
        LOGD(L_APP, L_V5, "主动拉152重启不开机报警");
        *OTA_gps_PWRon = 0XF9;
#if defined(__AMS_HEX_LOG__)
        track_os_file_log(1, 0x06, NULL);
#endif
    }
    return *OTA_gps_PWRon;
}
#if 0

/******************************************************************************
 *  Function    -  boot_sendsms
 *
 *  Purpose     -  发送开机短信
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 02-08-2013,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
void boot_sendsms(void)
{
    struct_msg_send g_msg = {0};
    LOGD(L_APP, L_V5, "开机短信发送");
    g_msg.addUrl = KAL_FALSE;
    g_msg.cm_type = CM_SMS;
    snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, str_boot_en);
    g_msg.msg_cn_len = sizeof(str_boot_cn);

    memcpy(g_msg.msg_cn, str_boot_cn, g_msg.msg_cn_len);
    track_cust_module_alarm_msg_send(&g_msg, NULL);
    track_alarm_vec_queue_remove(2, 0, TR_CUST_ALARM_boot);
}

/******************************************************************************
 *  Function    -  gps_successfully_sendsms
 *
 *  Purpose     -  gps定位成功短信
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 02-08-2013,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
void gps_successfully_sendsms(void)
{
    struct_msg_send g_msg = {0};
    LOGD(L_APP, L_V5, "GPS开机短信发送");

    g_msg.addUrl = KAL_FALSE;
    g_msg.cm_type = CM_SMS;
    snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, str_gps_successfully_en);
    g_msg.msg_cn_len = 16;
    memcpy(g_msg.msg_cn, str_gps_successfully_cn, g_msg.msg_cn_len);
    track_cust_module_alarm_msg_send(&g_msg, NULL);
    track_alarm_vec_queue_remove(2, 0, TR_CUST_ALARM_gps_successfully);
}

/******************************************************************************
 *  Function    -  track_cust_alarm_boot
 *
 *  Purpose     -  开机报警
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 02-08-2013,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_alarm_boot(void)
{
    track_gps_data_struct *gpsLastPoint = NULL;
    LOGD(L_APP, L_V5, "开机报警G_parameter.boot.alarm_type=%d,%d", G_parameter.boot.alarm_type, G_parameter.boot.sw);

    if(G_parameter.boot.sw == 0)
    {
        return;
    }
    gpsLastPoint = track_cust_gpsdata_alarm();
    if(G_parameter.gprson)
    {
        track_cust_paket_16(gpsLastPoint, track_drv_get_lbs_data(), TR_CUST_ALARM_boot, KAL_TRUE, 0);
    }
    if(G_parameter.boot.alarm_type == 1)
    {
        boot_sendsms();
    }
}
/******************************************************************************
 *  Function    -  track_cust_alarm_gps_successfully
 *
 *  Purpose     -  gps定位成功
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 02-08-2013,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_alarm_gps_successfully(void)
{
    track_gps_data_struct *gpsLastPoint = NULL;
    LOGD(L_APP, L_V5, " sw=%d  alarm_type=%d", G_parameter.boot.sw, G_parameter.boot.alarm_type);
    if(G_parameter.boot.sw == 0)
    {
        return;
    }
    gpsLastPoint = track_cust_gpsdata_alarm();
    if(G_parameter.gprson)
    {
        track_cust_paket_16(gpsLastPoint, track_drv_get_lbs_data(), TR_CUST_ALARM_gps_successfully, KAL_TRUE, 0);
    }
    if(G_parameter.boot.alarm_type == 1)
    {
        gps_successfully_sendsms();
    }
}
/******************************************************************************
 *  Function    -  blind_in_sendsms
 *
 *  Purpose     -盲区出报警短信发送
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 25-10-2012,  JWJ  written
 * ----------------------------------------
*******************************************************************************/
static void blind_out_sendsms(void)
{
    struct_msg_send g_msg = {0};
    LOGD(L_APP, L_V5, "GPS盲区报警出");
    g_msg.addUrl = KAL_FALSE;
    g_msg.cm_type = CM_SMS;
    snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, str_blind_out_en);
    g_msg.msg_cn_len = 34;
    memcpy(g_msg.msg_cn, str_blind_out_cn, g_msg.msg_cn_len);
    track_cust_module_alarm_msg_send(&g_msg, NULL);
    track_alarm_vec_queue_remove(2, 0, TR_CUST_ALARM_OUT_blind);
}
/******************************************************************************
 *  Function    -  blind_in_sendsms
 *
 *  Purpose     -盲区进报警
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 25-10-2012,  JWJ  written
 * ----------------------------------------
*******************************************************************************/
static void blind_in_sendsms(void)
{
    struct_msg_send g_msg = {0};
    LOGD(L_APP, L_V5, "GPS盲区报警进");
    g_msg.addUrl = KAL_FALSE;
    g_msg.cm_type = CM_SMS;
    snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, str_blind_in_en);
    g_msg.msg_cn_len = 34;
    memcpy(g_msg.msg_cn, str_blind_in_cn, g_msg.msg_cn_len);
    track_cust_module_alarm_msg_send(&g_msg, NULL);
    track_alarm_vec_queue_remove(2, 0, TR_CUST_ALARM_IN_blind);
}
/******************************************************************************
 *  Function    -  track_cust_alarm_blind_in
 *
 *  Purpose     -盲区进报警
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 25-10-2012,  JWJ  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_alarm_blind_in(void)
{
    track_gps_data_struct *gpsLastPoint = NULL;
    if(G_parameter.gps_blind.sw == 0)
    {
        return;
    }
    gpsLastPoint = track_cust_gpsdata_alarm();
    blind_status = 0;
    if(G_parameter.gprson)
    {
        track_cust_paket_16(gpsLastPoint, track_drv_get_lbs_data(), TR_CUST_ALARM_IN_blind, KAL_TRUE, 0);
    }
    if(G_parameter.gps_blind.alarm_type == 1 || G_parameter.gps_blind.alarm_type == 2)
    {
        blind_in_sendsms();
    }
    G_realtime_data.blind_status = blind_status;
    if(G_parameter.gps_blind.alarm_type == 2 || G_parameter.gps_blind.alarm_type == 3)
    {
        track_start_timer(TRACK_CUST_ALARM_MAKECALL_TIMER, 60000, track_cust_make_call, (void*)1);
    }

    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
}
/******************************************************************************
 *  Function    -  track_cust_alarm_blind_out
 *
 *  Purpose     -盲区出报警
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 25-10-2012,  JWJ  written
 * ----------------------------------------
*******************************************************************************/
track_cust_alarm_blind_out(void)
{
    track_gps_data_struct *gpsLastPoint = NULL;
    if(G_parameter.gps_blind.sw == 0)
    {
        return;
    }
    gpsLastPoint = track_cust_gpsdata_alarm();
    if(G_parameter.gprson)
    {
        track_cust_paket_16(gpsLastPoint, track_drv_get_lbs_data(), TR_CUST_ALARM_OUT_blind, KAL_FALSE, 0);
    }
    blind_status = 1;
    if(G_parameter.gps_blind.alarm_type == 1 || G_parameter.gps_blind.alarm_type == 2)
    {
        blind_out_sendsms();
    }
    G_realtime_data.blind_status = blind_status;
    if(G_parameter.gps_blind.alarm_type == 2 || G_parameter.gps_blind.alarm_type == 3)
    {
        track_start_timer(TRACK_CUST_ALARM_MAKECALL_TIMER, 60000, track_cust_make_call, (void*)1);
    }
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);

}

/******************************************************************************
 *  Function    -  track_cust_module_alarm_blind
 *
 *  Purpose     -gps盲区检测
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 25-10-2012,  JWJ  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_module_alarm_blind(void)
{
    if(G_parameter.gps_blind.sw == 0 || track_cust_get_work_mode() == WORK_MODE_3)
    {
        return;
    }
 LOGD(L_APP, L_V5, "盲区检测G_parameter.gps_blind.sw=%d,%d,%d,blind_status=%d", G_parameter.gps_blind.sw,
         G_parameter.gps_blind.blind_in_time, G_parameter.gps_blind.blind_out_time, blind_status);
 
    if(G_realtime_data.blind_status == 0 && blind_status == 2)
    {
        blind_status = G_realtime_data.blind_status;
    }
    if(track_cust_gps_status() > GPS_STAUS_SCAN && blind_status == 0)
    {
        tr_stop_timer(TRACK_CUST_GPS_BLINDALM_IN_TIMER_ID);
        if(!track_is_timer_run(TRACK_CUST_GPS_BLINDALM_OUT_TIMER_ID))
            tr_start_timer(TRACK_CUST_GPS_BLINDALM_OUT_TIMER_ID,  G_parameter.gps_blind.blind_out_time * 1000, track_cust_alarm_blind_out);
    }
    else if(track_cust_gps_status() == GPS_STAUS_SCAN && blind_status == 1)
    {
        tr_stop_timer(TRACK_CUST_GPS_BLINDALM_OUT_TIMER_ID);
        if(!track_is_timer_run(TRACK_CUST_GPS_BLINDALM_IN_TIMER_ID))
            tr_start_timer(TRACK_CUST_GPS_BLINDALM_IN_TIMER_ID, G_parameter.gps_blind.blind_in_time * 1000, track_cust_alarm_blind_in);
    }
    else if(track_cust_gps_status() == 0)
    {
        tr_stop_timer(TRACK_CUST_GPS_BLINDALM_IN_TIMER_ID);
        tr_stop_timer(TRACK_CUST_GPS_BLINDALM_OUT_TIMER_ID);
        if(blind_status)
        {
            blind_status = 2;
        }
    }
    else if(track_cust_gps_status() > GPS_STAUS_SCAN && blind_status == 2)
    {
        blind_status = 1;
    }
    else if(track_cust_gps_status() > GPS_STAUS_SCAN)
    {
        tr_stop_timer(TRACK_CUST_GPS_BLINDALM_IN_TIMER_ID);
    }
    else if(track_cust_gps_status() == GPS_STAUS_SCAN)
    {
        tr_stop_timer(TRACK_CUST_GPS_BLINDALM_OUT_TIMER_ID);
    }
    LOGD(L_APP, L_V5, "盲区检测G_parameter.gps_blind.sw=%d,%d,%d,blind_status=%d", G_parameter.gps_blind.sw,
         G_parameter.gps_blind.blind_in_time, G_parameter.gps_blind.blind_out_time, blind_status);
}

void track_cust_module_alarm_blind_init(void)
{
    LOGD(L_APP, L_V5, "");
    G_realtime_data.blind_status = 2;
    blind_status = 2;
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    track_cust_module_alarm_blind();

}

/******************************************************************************
 *  Function    -  track_cust_molude_simalarm_sms
 *
 *  Purpose     -  换卡报警短信
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 22-09-2014,  ZengPing && Liujunwu  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_molude_simalarm_sms(void)
{
    struct_msg_send g_msg = {0};
    track_gps_data_struct *gpsLastPoint = NULL;
    gpsLastPoint = track_cust_gpsdata_alarm();
    if(G_parameter.gprson)
    {
        track_cust_paket_16(gpsLastPoint, track_drv_get_lbs_data(), TR_CUST_ALARM_SIM_ALARM, KAL_FALSE, 0);
    }
    if(G_parameter.sim_alarm.simalm_type == 1)
    {
        g_msg.addUrl = KAL_FALSE;
        g_msg.cm_type = CM_SMS;
        snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, str_sim_alarm_en);
        g_msg.msg_cn_len = 32;
        memcpy(g_msg.msg_cn, str_sim_alarm_cn, g_msg.msg_cn_len);
        track_cust_module_alarm_msg_send(&g_msg, NULL);
    }
}

/******************************************************************************
 *  Function    -  track_cust_check_sosnum
 *
 *  Purpose     -  检查有多少个SOS号码
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 25-09-2014,  ZengPing && Liujunwu  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint32 track_cust_check_sosnum(void)
{
    kal_uint32 phone_index = 0;
    kal_uint32 i = 0;
    for(i = 0; i < TRACK_DEFINE_SOS_COUNT; i++)
    {
        if((G_phone_number.almrep[i]) && strlen((S8*) G_parameter.sos_num[i]))
        {
            phone_index++;
        }
    }
    LOGD(L_APP, L_V5, "phone_index=%d", phone_index);
    return phone_index;
}
/******************************************************************************
 *  Function    -  track_cust_alarm_pwoffalm
 *
 *  Purpose     -  关机报警
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 25-09-2014,  ZengPing && Liujunwu  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_pwoffalm_sendsms(void)
{
    struct_msg_send g_msg = {0};
    LOGD(L_APP, L_V5, "关机短信发送");
    g_msg.addUrl = KAL_FALSE;
    g_msg.cm_type = CM_SMS;
    snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, str_pwoffalm_en);
    g_msg.msg_cn_len = 24;
    memcpy(g_msg.msg_cn, str_pwoffalm_cn, g_msg.msg_cn_len);
    track_cust_module_alarm_msg_send(&g_msg, NULL);
    track_alarm_vec_queue_remove(2, 0, TR_CUST_ALARM_boot);
}

void track_cust_alarm_pwoffalm(void)
{
    track_gps_data_struct *gpsLastPoint = NULL;
    LOGD(L_APP, L_V5, "关机报警G_parameter.pwroff.alarm_type=%d,%d", G_parameter.pwroff.alarm_type, G_parameter.pwroff.sw);

    if(G_parameter.pwroff.sw == 0)
    {
        return;
    }
    gpsLastPoint = track_cust_gpsdata_alarm();
    if(G_parameter.gprson)
    {
        track_cust_paket_16(gpsLastPoint, track_drv_get_lbs_data(), TR_CUST_ALARM_PWROFF, KAL_FALSE, 0);
    }
    if(G_parameter.pwroff.alarm_type == 1)
    {
        tr_start_timer(TRACK_CUST_SEND_SMS_PWROFFALM_TIMER_ID, 2 * 1000, track_cust_pwoffalm_sendsms);
    }
}


void door_sendsms(void)
{
    struct_msg_send g_msg = {0};
    LOGD(L_APP, L_V5, "门报警");
    g_msg.addUrl = KAL_FALSE;
    g_msg.cm_type = CM_SMS;
    snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, str_door_en);
    g_msg.msg_cn_len = 22;
    memcpy(g_msg.msg_cn, str_door_cn, g_msg.msg_cn_len);
    track_cust_module_alarm_msg_send(&g_msg, NULL);
}


/******************************************************************************
 *  Function    -  track_cust_alarm_door
 *
 *  Purpose     -  门报警
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 02-08-2013,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_alarm_door(void)
{
    track_gps_data_struct *gpsLastPoint = NULL;
    LOGD(L_APP, L_V5, "");

    if(G_parameter.door_alarm.sw == 0)
    {
        return;
    }

    gpsLastPoint = track_cust_gpsdata_alarm();
    if(G_parameter.gprson)
    {
        track_cust_paket_16(gpsLastPoint, track_drv_get_lbs_data(), TR_CUST_ALARM_door, KAL_FALSE, 0);
    }
    if(G_parameter.door_alarm.alarm_type == 1)
    {
        door_sendsms();
    }
    if(G_parameter.door_alarm.alarm_type == 2)
    {
        door_sendsms();
        track_start_timer(TRACK_CUST_ALARM_DOOR_Call_TIMER, 60000, track_cust_make_call, (void*)1);
    }
}

//摘除报警
void track_cust_teardown_alarm()
{
    struct_msg_send g_msg = {0};
    LOGD(L_APP, L_V5, "防拆短信发送");
    g_msg.addUrl = KAL_FALSE;
    g_msg.cm_type = CM_SMS;
    snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, str_teardown_en);
    g_msg.msg_cn_len = 18;
    memcpy(g_msg.msg_cn, str_teardown_cn, g_msg.msg_cn_len);
    track_cust_module_alarm_msg_send(&g_msg, NULL);
    //track_alarm_vec_queue_remove(2, 0, TR_CUST_ALARM_PRE_REMOVE);
}

void teardown_alarm_overtime(void)
{
    track_gps_data_struct *  gps_data = NULL;
    if(track_cust_gps_status() > 2)
    {
        gps_data = track_cust_backup_gps_data(2, NULL);
    }
    if(G_parameter.teardown_str.sw)
    {
        if(!G_parameter.teardown_str.alarm_type || G_parameter.teardown_str.alarm_type == 3)
        {
            LOGD(L_APP, L_V4, "防拆报警，报警类型设置无需短信通知！");
            return;
        }
        memset(&g_msg, 0, sizeof(struct_msg_send));
        g_msg.addUrl = KAL_TRUE;
        g_msg.cm_type = CM_SMS;
        track_fun_strncpy(g_msg.msg_en, str_teardown_en, CM_PARAM_LONG_LEN_MAX);
        g_msg.msg_cn_len = 20;
        memcpy(g_msg.msg_cn, str_teardown_cn, g_msg.msg_cn_len);
        track_cust_module_alarm_msg_send(&g_msg, gps_data);
        track_cust_module_alarm_lock(TR_CUST_ALARM_PRE_REMOVE, 0);
    }
    else
    {
        track_cust_module_alarm_lock(TR_CUST_ALARM_PRE_REMOVE, 0);
    }
    //track_cust_module_alarm_set_type(0);
    track_alarm_vec_queue_remove(2, 0, TR_CUST_ALARM_PRE_REMOVE);
}

#endif

#if defined (__GT370__)|| defined (__GT380__)
void track_cust_receive_power_off_msg(void)
{
    kal_uint32 index = 0;
    LOGD(L_APP, L_V5, "");

    if(!track_is_timer_run(TRACK_CUST_PWROFFALM_TIMER_ID))
    {
        if(G_parameter.pwrlimit_sw == 0)
        {
            if(G_parameter.pwroff.sw == 1)
            {
                track_cust_led_sleep(2);
                index = track_cust_check_sosnum();
                track_cust_alarm_pwoffalm();
                if(G_parameter.pwroff.alarm_type == 1 && index != 0)
                {
                    tr_start_timer(TRACK_CUST_PWROFFALM_TIMER_ID, (index * 15) * 1000, track_cust_poweroff_ready);
                }
                else
                {
                    tr_start_timer(TRACK_CUST_PWROFFALM_TIMER_ID, 5 * 1000, track_cust_poweroff_ready);
                }
            }
            else
            {
                tr_start_timer(TRACK_CUST_PWROFFALM_TIMER_ID, 5 * 1000, track_cust_poweroff_ready);
            }
        }
        else
        {
            LOGD(L_APP, L_V5, "限制关机!");
        }
    }
    else
    {
        LOGD(L_APP, L_V5, "关机报警中");
    }
}

//开外壳报警
void track_cust_open_shell_alarm()
{
    struct_msg_send g_msg = {0};
    LOGD(L_APP, L_V5, "开盖报警短信发送");
    g_msg.addUrl = KAL_FALSE;
    g_msg.cm_type = CM_SMS;
    snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, str_open_shell_en);
    g_msg.msg_cn_len = 18;
    memcpy(g_msg.msg_cn, str_open_shell_cn, g_msg.msg_cn_len);
    track_cust_module_alarm_msg_send(&g_msg, NULL);
}

void track_open_shell_alarm_overtime(void)
{
    track_gps_data_struct *  gps_data = NULL;
    if(track_cust_gps_status() > 2)
    {
        gps_data = track_cust_backup_gps_data(2, NULL);
    }
    if(G_parameter.open_shell_alarm.sw)
    {
        if(!G_parameter.open_shell_alarm.alarm_type || G_parameter.open_shell_alarm.alarm_type == 3)
        {
            LOGD(L_APP, L_V4, "开盖报警，报警类型设置无需短信通知！");
            return;
        }
        memset(&g_msg, 0, sizeof(struct_msg_send));
        g_msg.addUrl = KAL_TRUE;
        g_msg.cm_type = CM_SMS;
        track_fun_strncpy(g_msg.msg_en, str_open_shell_en, CM_PARAM_LONG_LEN_MAX);
        g_msg.msg_cn_len = 20;
        memcpy(g_msg.msg_cn, str_open_shell_cn, g_msg.msg_cn_len);
        track_cust_module_alarm_msg_send(&g_msg, gps_data);
        track_cust_module_alarm_lock(TR_CUST_ALARM_OPEN_SHELL, 0);
    }
    else
    {
        track_cust_module_alarm_lock(TR_CUST_ALARM_OPEN_SHELL, 0);
    }
    track_alarm_vec_queue_remove(2, 0, TR_CUST_ALARM_OPEN_SHELL);
}

#endif

