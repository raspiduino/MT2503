
#if !(defined(__GT740__)|| defined(__GT370__)|| defined(__GT380__) || defined(__NF2318__))
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
static struct_msg_send msg = {0};

static char str_p_already_cut_en[] = "Already in the state of  Power supply cut off, the command is not running!";
static kal_uint8 str_p_already_cut_cn[36] =   // 终端已处于断电状态,本指令不再执行!
{
    0x7E, 0xC8, 0x7A, 0xEF, 0x5D, 0xF2, 0x59, 0x04, 0x4E, 0x8E, 0x65, 0xAD, 0x75, 0x35, 0x72, 0xB6,
    0x60, 0x01, 0x00, 0x2C, 0x67, 0x2C, 0x63, 0x07, 0x4E, 0xE4, 0x4E, 0x0D, 0x51, 0x8D, 0x62, 0x67,
    0x88, 0x4C, 0xFF, 0x01
};

static char str_p_already_en[] = "Already in the state of Power supply to resume, the command is not running!";
static kal_uint8 str_p_already_cn[40] =   // 终端已处于恢复电源状态，本指令不再执行！
{
    0x7E, 0xC8, 0x7A, 0xEF, 0x5D, 0xF2, 0x59, 0x04, 0x4E, 0x8E, 0x60, 0x62, 0x59, 0x0D, 0x75, 0x35,
    0x6E, 0x90, 0x72, 0xB6, 0x60, 0x01, 0xFF, 0x0C, 0x67, 0x2C, 0x63, 0x07, 0x4E, 0xE4, 0x4E, 0x0D,
    0x51, 0x8D, 0x62, 0x67, 0x88, 0x4C, 0xFF, 0x01
};

static char str_p_cut_oil_success_en[] = "Cut off the power supply: Success!";
static kal_uint8 str_p_cut_oil_success_cn[10] =   // 断电成功！
{
    0x65, 0xAD, 0x75, 0x35, 0x62, 0x10, 0x52, 0x9F, 0xFF, 0x01
};
static char str_p_cut_oil_delay_en[] = "Cut off the power supply: Delay! speed limit: km/h.";
static kal_uint8 str_p_cut_oil_delay_cn[38] =    // 速度超限：公里/时，切断电源延后执行！
{
    0x90, 0x1F, 0x5E, 0xA6, 0x8D, 0x85, 0x96, 0x50, 0xFF, 0x1A, 0x51, 0x6C, 0x91, 0xCC, 0x00, 0x2F,
    0x65, 0xF6, 0xFF, 0x0C, 0x52, 0x07, 0x65, 0xAD, 0x75, 0x35, 0x6E, 0x90, 0x5E, 0xF6, 0x54, 0x0E,
    0x62, 0x67, 0x88, 0x4C, 0xFF, 0x01
};
static char str_p_cut_oil_delay2_en[] = "Cut off the power supply: Delay! GPS not location.";
static kal_uint8 str_p_cut_oil_delay2_cn[30] =   // 切断电源延后执行，GPS未定位
{
    0x52, 0x07, 0x65, 0xAD, 0x75, 0x35, 0x6E, 0x90, 0x5E, 0xF6, 0x54, 0x0E, 0x62, 0x67, 0x88, 0x4C,
    0xFF, 0x0C, 0x00, 0x47, 0x00, 0x50, 0x00, 0x53, 0x67, 0x2A, 0x5B, 0x9A, 0x4F, 0x4D
};
static char str_p_resume_oil_en[] = "Restore Power supply: Success!";
static kal_uint8 str_p_resume_oil_cn[14] =   //恢复电源成功！
{
    0x60, 0x62, 0x59, 0x0D, 0x75, 0x35, 0x6E, 0x90, 0x62, 0x10, 0x52, 0x9F, 0xFF, 0x01
};
static char str_p_cancel_oil_command_en[] = "cancelled the command of cutting-off Power supply; power supply is on.";
static kal_uint8 str_p_cancel_oil_command_cn[34] =   // 断电指令已取消。电源现为接通状态。
{
    0x65, 0xAD, 0x75, 0x35, 0x63, 0x07, 0x4E, 0xE4, 0x5D, 0xF2, 0x53, 0xD6, 0x6D, 0x88, 0x30, 0x02,
    0x75, 0x35, 0x6E, 0x90, 0x73, 0xB0, 0x4E, 0x3A, 0x63, 0xA5, 0x90, 0x1A, 0x72, 0xB6, 0x60, 0x01,
    0x30, 0x02
};


#if defined(__GERMANY__)
static char str_already_cut_en[] = "Ausgang ist bereits aktiviert!";
#elif defined(__SPANISH__)
static char str_already_cut_en[] = "Corte en estado activo, el comando no puede ejecutarse otra vez!";
#else
static char str_already_cut_en[] = "Already in the state of fuel supply cut off, the command is not running!";
#endif
static kal_uint8 str_already_cut_cn[38] =   // 终端已处于断油电状态，本指令不再执行！
{
    0x7E, 0xC8, 0x7A, 0xEF, 0x5D, 0xF2, 0x59, 0x04, 0x4E, 0x8E, 0x65, 0xAD, 0x6C, 0xB9, 0x75, 0x35,
    0x72, 0xB6, 0x60, 0x01, 0xFF, 0x0C, 0x67, 0x2C, 0x63, 0x07, 0x4E, 0xE4, 0x4E, 0x0D, 0x51, 0x8D,
    0x62, 0x67, 0x88, 0x4C, 0xFF, 0x01
};
#if defined(__GERMANY__)
static char str_already_en[] = "Ausgang ist bereits abgeschaltet!";
#elif defined(__SPANISH__)
static char str_already_en[] = "El corte de combustible se encuentra liberado, No puede ejecutarse el comando otra vez!";
#else
static char str_already_en[] = "Already in the state of fuel supply to resume, the command is not running!";
#endif
static kal_uint8 str_already_cn[40] =   // 终端已处于恢复油电状态，本指令不再执行！
{
    0x7E, 0xC8, 0x7A, 0xEF, 0x5D, 0xF2, 0x59, 0x04, 0x4E, 0x8E, 0x60, 0x62, 0x59, 0x0D, 0x6C, 0xB9,
    0x75, 0x35, 0x72, 0xB6, 0x60, 0x01, 0xFF, 0x0C, 0x67, 0x2C, 0x63, 0x07, 0x4E, 0xE4, 0x4E, 0x0D,
    0x51, 0x8D, 0x62, 0x67, 0x88, 0x4C, 0xFF, 0x01
};

#if defined(__GERMANY__)
static char str_cut_oil_success_en[] = "Ausgang erfolgreich geschaltet! Geschwindigkeit: km/h";
#elif defined(__SPANISH__)
static char str_cut_oil_success_en[] = "Corte del suministro de combustible realizado con exito! Velocidad: km/h.";
#else
static char str_cut_oil_success_en[] = "Cut off the fuel supply: Success! Speed: km/h.";
#endif
static kal_uint8 str_cut_oil_success_cn[28] =   // 切断油电成功！速度：公里/时
{
    0x52, 0x07, 0x65, 0xAD, 0x6C, 0xB9, 0x75, 0x35, 0x62, 0x10, 0x52, 0x9F, 0xFF, 0x01, 0x90, 0x1F,
    0x5E, 0xA6, 0xFF, 0x1A, 0x51, 0x6C, 0x91, 0xCC, 0x00, 0x2F, 0x65, 0xF6
};

#if defined(__GERMANY__)
static char str_cut_oil_delay_en[] = "Geschwindigkeit zu hoch: Km/h Ausgang wird verzoegert geschaltet.";
#else
static char str_cut_oil_delay_en[] = "Cut off the fuel supply: Delay! speed limit: km/h.";
#endif
static kal_uint8 str_cut_oil_delay_cn[38] =    // 速度超限：公里/时，切断油电延后执行！
{
    0x90, 0x1F, 0x5E, 0xA6, 0x8D, 0x85, 0x96, 0x50, 0xFF, 0x1A, 0x51, 0x6C, 0x91, 0xCC, 0x00, 0x2F,
    0x65, 0xF6, 0xFF, 0x0C, 0x52, 0x07, 0x65, 0xAD, 0x6C, 0xB9, 0x75, 0x35, 0x5E, 0xF6, 0x54, 0x0E,
    0x62, 0x67, 0x88, 0x4C, 0xFF, 0x01
};

#if defined(__GERMANY__)
static char str_cut_oil_delay2_en[] = "GPS nicht erkannt - Ausgang wird verzoegert geschaltet.";
#elif defined(__SPANISH__)
static char str_cut_oil_delay2_en[] = "Sin adquirir posicion GPS!!!  El comando de corte se ejecutara posteriormente.";
#else
static char str_cut_oil_delay2_en[] = "GPS not fixed, Cut off the fuel supply operation delay execution!";
#endif
static kal_uint8 str_cut_oil_delay2_cn[30] =   // 切断油电延后执行，GPS未定位
{
    0x52, 0x07, 0x65, 0xAD, 0x6C, 0xB9, 0x75, 0x35, 0x5E, 0xF6, 0x54, 0x0E, 0x62, 0x67, 0x88, 0x4C,
    0xFF, 0x0C, 0x00, 0x47, 0x00, 0x50, 0x00, 0x53, 0x67, 0x2A, 0x5B, 0x9A, 0x4F, 0x4D
};

#if defined(__GERMANY__)
static char str_resume_oil_en[] = "Ausgang abgeschaltet!";
#elif defined(__SPANISH__)
static char str_resume_oil_en[] = "El suministro de combustible se ha restablecido con exito!";
#else
static char str_resume_oil_en[] = "Restore fuel supply: Success!";
#endif
static kal_uint8 str_resume_oil_cn[14] =   // 恢复油电成功！
{
    0x60, 0x62, 0x59, 0x0D, 0x6C, 0xB9, 0x75, 0x35, 0x62, 0x10, 0x52, 0x9F, 0xFF, 0x01
};

#if defined(__GERMANY__)
static char str_cancel_oil_command_en[] = "Schalten des Ausgangs abgebrochen!";
#elif defined(__SPANISH__)
static char str_cancel_oil_command_en[] = "El comando de corte de combustible en demora de ejecucion, se ha cancelado con exito!";
#else
static char str_cancel_oil_command_en[] = "cancelled the command of cutting-off fuel supply; fuel supply is on.";
#endif
static kal_uint8 str_cancel_oil_command_cn[36] =   // 断油电指令已取消，油电现为接通状态。
{
    0x65, 0xAD, 0x6C, 0xB9, 0x75, 0x35, 0x63, 0x07, 0x4E, 0xE4, 0x5D, 0xF2, 0x53, 0xD6, 0x6D, 0x88,
    0xFF, 0x0C, 0x6C, 0xB9, 0x75, 0x35, 0x73, 0xB0, 0x4E, 0x3A, 0x63, 0xA5, 0x90, 0x1A, 0x72, 0xB6,
    0x60, 0x01, 0x30, 0x02
};

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/


/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern kal_uint8 track_cust_status_acc(void);
extern kal_uint8 track_cust_oil_cut(kal_uint8 value);
extern void track_cust_433_control(kal_uint32 mode);
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
 /******************************************************************************
 *  Function    -  track_cust_oil_cut_req
 *
 *
 *  Purpose     -  油电开关切换功能
 *
 *
 *  Description -  参数         描述
 *                 0            标记油电恢复
 *                 1            标记油电断开
 *                 2            请求断开，GPS未定位
 *                 3            请求断开，但是当前还未能满足断开的条件 未发因超速延缓执行的短信
 *                 4            请求断开，但是当前还未能满足断开的条件 已发因超速延缓执行的短信
 *                 99           查询当前标记状态
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-01-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_int8 track_cust_oil_cut_req(kal_uint8 value)
{
    kal_int8 ret;
    kal_int8 temp;
    if (G_parameter.oil_sw == 0)
    {
        return -1;
    }
    temp = G_realtime_data.oil_status;
    ret = track_cust_oil_cut(value);
    if (value >= 0 && value <= 1)
    {
        G_realtime_data.oil_status = value;
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        if (value != ret)
        {
            LOGD(L_APP, L_V1, "ERROR:%d,%d 断油电或恢复油电执行失败", value, ret);
        }
    }
    else if (value >= 2 && value <= 4 && ret == 0)
    {
        if (G_realtime_data.oil_status >= 2 && G_realtime_data.oil_status <= 4)
        {
            if (value > G_realtime_data.oil_status)
            {
                G_realtime_data.oil_status = value;
                Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
            }
        }
        else
        {
            G_realtime_data.oil_status = value;
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        }
    }
    if (ret == 1 || ((G_realtime_data.oil_status == 0 || G_realtime_data.oil_status == 1) && ret == 0))
    {
        if (G_realtime_data.oil_status != ret)
        {
            G_realtime_data.oil_status = ret;
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        }
    }
    if(value!=99)
    {
        //只有参数有改变，才会上传这个包
#if defined (__PARAM_CHANGE_UPDATE_SERVER__)
        if(temp!=value)
        track_cust_paket_9404_handle();
#endif
    }
    return G_realtime_data.oil_status;
}

/******************************************************************************
 *  Function    -  track_cust_oil_cut_boot
 *
 *  Purpose     -  如果记录状态是断油电的状态，开机时自动执行，持续锁电机的状态
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_oil_cut_boot(void)
{
    if (G_parameter.oil_sw == 0)
    {
        return;
    }
    LOGD(L_APP, L_V5, "oil_status=%d, oil_cmd_source=%d", G_realtime_data.oil_status, G_realtime_data.oil_cmd_source);
    msg.cm_type = G_realtime_data.oil_cmd_source;
    track_fun_strncpy(msg.phone_num, G_parameter.centerNumber, CM_HEAD_PWD_MXA);
    if (G_realtime_data.oil_status == 1 || G_realtime_data.oil_status == 0)
    {
        track_cust_oil_cut_req(G_realtime_data.oil_status);
    }
    else if (G_realtime_data.oil_status >= 2)
    {
        if (track_cust_status_acc() == 0)
        {
            track_cust_oil_cut_req(1);
#if defined(__GERMANY__)
            snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Ausgang erfolgreich geschaltet!");
#elif defined(__SPANISH__)
            snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Corte del suministro de combustible realizado con exito!");
#else
            snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Cut off the fuel supply: Success!");
#endif
            msg.msg_cn_len = 14;
            track_fun_strncpy(msg.phone_num, G_parameter.centerNumber, CM_HEAD_PWD_MXA);
            memcpy(msg.msg_cn, str_cut_oil_success_cn, msg.msg_cn_len);
            track_cust_module_alarm_msg_send(&msg, NULL);
        }
    }
}
static void track_cust_oli_cut_pwm_delay_rsp()
{
    track_cust_oil_cut_req(1);
    snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Cut off the fuel supply: Success!");
    msg.msg_cn_len = 14;
    memcpy(msg.msg_cn, str_cut_oil_success_cn, msg.msg_cn_len);
    track_cust_module_alarm_msg_send(&msg, NULL);
}
void track_cust_module_oil_cut_pulse(CMD_DATA_STRUCT *cmd, kal_bool cut)
{
    kal_int8 pre_status;

    memset(&msg, 0, sizeof(struct_msg_send));
    msg.cm_type = cmd->return_sms.cm_type;
    G_realtime_data.oil_cmd_source = msg.cm_type;
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    memcpy(msg.stamp, cmd->return_sms.stamp, 4);
    track_fun_strncpy(msg.phone_num, G_parameter.centerNumber, CM_HEAD_PWD_MXA);

    if(cut == 0) //恢复油电
    {
        if(track_is_timer_run(TRACK_DRV_OIL_CUT_PULSE_TIMER_ID))
        {
            tr_stop_timer(TRACK_DRV_OIL_CUT_PULSE_TIMER_ID);
        }
        if(track_is_timer_run(TRACK_CUST_OIL_CUT_PWM_DELAY_TIMER_ID))
        {
            tr_stop_timer(TRACK_CUST_OIL_CUT_PWM_DELAY_TIMER_ID);
        }
          
        pre_status = track_cust_oil_cut_req(99);
        if(pre_status == 0)
        {
            // 终端已处于恢复油电状态，本指令不再执行！
            snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "%s", str_already_en);
            msg.msg_cn_len = 40;
            memcpy(msg.msg_cn, str_already_cn, msg.msg_cn_len);
            track_cust_module_alarm_msg_send(&msg, NULL);
        }
        else if(pre_status >= 2 && pre_status <= 4)
        {
            // 断油电指令已取消。油电现为接通状态
            track_cust_oil_cut_req(0);
            snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "%s", str_cancel_oil_command_en);
            msg.msg_cn_len = 36;
            memcpy(msg.msg_cn, str_cancel_oil_command_cn, msg.msg_cn_len);
            track_cust_module_alarm_msg_send(&msg, NULL);
        }
        else
        {
            track_cust_oil_cut_req(0);
            snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "%s", str_resume_oil_en);
            msg.msg_cn_len = 14;
            memcpy(msg.msg_cn, str_resume_oil_cn, msg.msg_cn_len);
            track_cust_module_alarm_msg_send(&msg, NULL);
        }
    }
    else  //断油电
    {
        track_gps_data_struct *p_gpsdata = track_drv_get_gps_data();

        if(track_cust_oil_cut_req(99) == 1)
        {
            snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "%s", str_already_cut_en);
            msg.msg_cn_len = 38;
            memcpy(msg.msg_cn, str_already_cut_cn, msg.msg_cn_len);
            track_cust_module_alarm_msg_send(&msg, NULL);
        }
        else if(track_cust_status_acc() == 0) //熄火
        {
            track_cust_oil_cut_req(1);
            snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Cut off the fuel supply: Success!");
            msg.msg_cn_len = 14;
            memcpy(msg.msg_cn, str_cut_oil_success_cn, msg.msg_cn_len);
            track_cust_module_alarm_msg_send(&msg, NULL);
        }
        else if((p_gpsdata->status >= 2) && (p_gpsdata->gprmc.Speed <= 20)) //定位+低速
        {
            track_cust_oil_cut_req(1);
            snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Cut off the fuel supply: Success!");
            msg.msg_cn_len = 14;
            memcpy(msg.msg_cn, str_cut_oil_success_cn, msg.msg_cn_len);
            track_cust_module_alarm_msg_send(&msg, NULL);
        }
        else  //ACC ON/GPS不定位或高速
        {
            track_cust_oil_cut_req(1);//1分钟后才是真正断油电
            LOGD(L_APP, L_V4, "继电器断续导通切断油电(ACC ON/GPS不定位或高速)");
            track_drv_oli_cut_pwm((void*)60);
            tr_start_timer(TRACK_CUST_OIL_CUT_PWM_DELAY_TIMER_ID, 65 * 1000, track_cust_oli_cut_pwm_delay_rsp);
        }
    }
}

/******************************************************************************
 *  Function    -  track_cust_module_oil_cut
 *
 *  Purpose     -  断油电函数
 *
 *  Description -  参数：value = FALSE   恢复油电通路
 *                       value = TRUE    断开油电
 *
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 24-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_module_oil_cut_cmd(CMD_DATA_STRUCT *cmd, kal_bool value, kal_bool force)
{
    if (G_parameter.oil_sw == 0)
    {
        return;
    }
    LOGD(L_APP, L_V5, "cm_type=%d, oil_status=%d, oil_cmd_source=%d", cmd->return_sms.cm_type, G_realtime_data.oil_status, G_realtime_data.oil_cmd_source);

    memset(&msg, 0, sizeof(struct_msg_send));
    msg.cm_type = cmd->return_sms.cm_type;
    G_realtime_data.oil_cmd_source = msg.cm_type;
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    memcpy(msg.stamp, cmd->return_sms.stamp, 4);
#if defined(__MEX__)
    if(!strcmp(cmd->pars[0], "SRELAY"))
    {
        track_fun_strncpy(msg.phone_num, cmd->return_sms.ph_num, CM_HEAD_PWD_MXA);
    }
    else
#endif
    {
#if defined(__SPANISH__)
        track_fun_strncpy(msg.phone_num, cmd->return_sms.ph_num, CM_HEAD_PWD_MXA);
#else
        track_fun_strncpy(msg.phone_num, G_parameter.centerNumber, CM_HEAD_PWD_MXA);
#endif
    }
    if (value)
    {
#if defined(__ET310__) || defined(__MT200__)
        if (force == KAL_TRUE)
        {
            if (track_cust_oil_cut_req(99) == 1)
            {
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "%s", str_p_already_cut_en);
                msg.msg_cn_len = 36;
                memcpy(msg.msg_cn, str_p_already_cut_cn, msg.msg_cn_len);
                track_cust_module_alarm_msg_send(&msg, NULL);
            }
            else
            {
                track_cust_oil_cut_req(1);
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "%s", str_p_cut_oil_success_en);
                msg.msg_cn_len = 10;
                memcpy(msg.msg_cn, str_p_cut_oil_success_cn, msg.msg_cn_len);
                track_cust_module_alarm_msg_send(&msg, NULL);
            }
        }
        else
#endif
        {
            if (track_cust_oil_cut_req(99) == 1)
            {
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "%s", str_already_cut_en);
                msg.msg_cn_len = 38;
                memcpy(msg.msg_cn, str_already_cut_cn, msg.msg_cn_len);
                track_cust_module_alarm_msg_send(&msg, NULL);
            }
            else if (force || track_cust_status_acc() == 0)
            {
                track_cust_oil_cut_req(1);
#if defined(__GERMANY__)
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Ausgang erfolgreich geschaltet!");
#elif defined(__SPANISH__)
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Corte del suministro de combustible realizado con exito!");
#else
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Cut off the fuel supply: Success!");
#endif
                msg.msg_cn_len = 14;
                memcpy(msg.msg_cn, str_cut_oil_success_cn, msg.msg_cn_len);
                track_cust_module_alarm_msg_send(&msg, NULL);
            }
            else if (track_cust_gps_status() < GPS_STAUS_2D)
            {
                LOGD(L_APP, L_V4, "切断油电延后执行，GPS未定位");
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "%s", str_cut_oil_delay2_en);
                msg.msg_cn_len = 30;
                memcpy(msg.msg_cn, str_cut_oil_delay2_cn, msg.msg_cn_len);
                track_cust_module_alarm_msg_send(&msg, NULL);
                track_cust_oil_cut_req(2);
            }
            else
            {
                LOGD(L_APP, L_V5, "切断油电延后执行，GPS定位");
                track_cust_oil_cut_req(3);
            }

        }

    }
    else
    {
        kal_int8 ret = track_cust_oil_cut_req(99);
#if defined(__ET310__) || defined(__MT200__)
        if (force == KAL_TRUE)
        {
            if (ret == 0)
            {
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "%s", str_p_already_en);
                msg.msg_cn_len = 40;
                memcpy(msg.msg_cn, str_p_already_cn, msg.msg_cn_len);
                track_cust_module_alarm_msg_send(&msg, NULL);
            }
            else if (ret >= 2 && ret <= 4)
            {
                track_cust_oil_cut_req(0);
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "%s", str_p_cancel_oil_command_en);
                msg.msg_cn_len = 34;
                memcpy(msg.msg_cn, str_p_cancel_oil_command_cn, msg.msg_cn_len);
                track_cust_module_alarm_msg_send(&msg, NULL);
            }
            else
            {
                track_cust_oil_cut_req(0);
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "%s", str_p_resume_oil_en);
                msg.msg_cn_len = 14;
                memcpy(msg.msg_cn, str_p_resume_oil_cn, msg.msg_cn_len);
                track_cust_module_alarm_msg_send(&msg, NULL);
            }
        }
        else
#endif
        {
            if (ret == 0)
            {
                // 终端已处于恢复油电状态，本指令不再执行！
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "%s", str_already_en);
                msg.msg_cn_len = 40;
                memcpy(msg.msg_cn, str_already_cn, msg.msg_cn_len);
                track_cust_module_alarm_msg_send(&msg, NULL);
            }
            else if (ret >= 2 && ret <= 4)
            {
                // 断油电指令已取消。油电现为接通状态
                track_cust_oil_cut_req(0);
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "%s", str_cancel_oil_command_en);
                msg.msg_cn_len = 36;
                memcpy(msg.msg_cn, str_cancel_oil_command_cn, msg.msg_cn_len);
                track_cust_module_alarm_msg_send(&msg, NULL);
            }
            else
            {
                track_cust_oil_cut_req(0);
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "%s", str_resume_oil_en);
                msg.msg_cn_len = 14;
                memcpy(msg.msg_cn, str_resume_oil_cn, msg.msg_cn_len);
                track_cust_module_alarm_msg_send(&msg, NULL);
            }
        }
    }
}

/******************************************************************************
 *  Function    -  track_cust_module_oil_cut_gps
 *
 *  Purpose     -  根据GPS数据中的速度判断是否进行断油电
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_module_oil_cut_gps(track_gps_data_struct *gps_data)
{
    static kal_uint8 Speed_cnt = 0;
    kal_uint8 speed_temp = 20;
    kal_uint8 count_temp = 10;
    if (G_parameter.oil_sw == 0)
    {
        return;
    }
    if (G_realtime_data.oil_status >= 2 && G_realtime_data.oil_status <= 4)
    {
        char tmp[20] = {0};
        int len, speed;
        speed = gps_data->gprmc.Speed;
        if (speed < speed_temp)
        {
            if (Speed_cnt < count_temp)
            {
                Speed_cnt++;
            }
            else
            {
                track_cust_oil_cut_req(1);
#if defined(__GERMANY__)
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Ausgang erfolgreich geschaltet! Geschwindigkeit: %dkm/h.", speed);
#elif defined(__SPANISH__)
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Corte del suministro de combustible realizado con exito! Velocidad: %dkm/h.", speed);
#else
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Cut off the fuel supply: Success! Speed: %dkm/h.", speed);
#endif
                snprintf(tmp, 20, "%d", speed);
                memcpy(msg.msg_cn, str_cut_oil_success_cn, 20);                 // 切断油电成功！速度：
                len = track_fun_asc_str_to_ucs2_str(&msg.msg_cn[20], tmp) - 2;
                msg.msg_cn_len = 28 + len;
                if (CM_PARAM_LONG_LEN_MAX <= msg.msg_cn_len) return;
                memcpy(&msg.msg_cn[len + 20], &str_cut_oil_success_cn[20], 8);  // 公里/时
                track_cust_module_alarm_msg_send(&msg, NULL);
            }
        }
        else
        {
            Speed_cnt = 0;
            if (G_realtime_data.oil_status != 4)
            {
#if defined(__GERMANY__)
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Geschwindigkeit zu hoch: %dkm/h Ausgang wird verzoegert geschaltet.", speed);
#elif defined(__SPANISH__)
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "La velocidad excede el limite de seguridad: %dkm/h. El comando se ejecutara posteriormente!", speed);
#else                
                snprintf(msg.msg_en, CM_PARAM_LONG_LEN_MAX, "Speed  exceeds the safety limit: %dkm /h, Cut off the fuel supply operation delay execution!", speed);
#endif
                snprintf(tmp, 20, "%d", speed);
                memcpy(msg.msg_cn, str_cut_oil_delay_cn, 10);
                len = track_fun_asc_str_to_ucs2_str(&msg.msg_cn[10], tmp) - 2;
                msg.msg_cn_len = 38 + len;
                if (CM_PARAM_LONG_LEN_MAX <= msg.msg_cn_len) return;
                memcpy(&msg.msg_cn[len + 10], &str_cut_oil_delay_cn[10], 28);
                track_cust_module_alarm_msg_send(&msg, NULL);
                track_cust_oil_cut_req(4);
            }
        }
    }
    else
    {
        Speed_cnt = 0;
    }
}
#endif
#if defined(__GERMANY__)
/******************************************************************************
 *  Function    -  track_cust_module_Preheat_System
 *
 *  Purpose     -  根据时间判断断油电继电器接通时间(引擎预热系统)
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 22-12-2016,  Cjj  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_module_Preheat_System(kal_uint8 time)
{
    if(track_cust_status_acc() == 1)
    {
        return;
    }
        switch(time)
        {
            case 0:
                if(track_is_timer_run(TRACK_CUST_PREHET_SYSTEM_TIMER_ID))
                {
                    track_stop_timer(TRACK_CUST_PREHET_SYSTEM_TIMER_ID);
                }
                track_cust_oil_cut_req(1);
                break;
            case 1:
                track_cust_oil_cut_req(0);
                break;
            case 2:
                track_cust_oil_cut_req(0);
                track_start_timer(TRACK_CUST_PREHET_SYSTEM_TIMER_ID, 2*1000, track_cust_oil_cut_req, (void*)1);
                break;
            case 10:
                track_cust_oil_cut_req(0);
                track_start_timer(TRACK_CUST_PREHET_SYSTEM_TIMER_ID, 10*60*1000, track_cust_oil_cut_req, (void*)1);
                break;
            case 20:
                track_cust_oil_cut_req(0);
                track_start_timer(TRACK_CUST_PREHET_SYSTEM_TIMER_ID, 20*60*1000, track_cust_oil_cut_req, (void*)1);
                break;
            case 30:
                track_cust_oil_cut_req(0);
                track_start_timer(TRACK_CUST_PREHET_SYSTEM_TIMER_ID, 30*60*1000, track_cust_oil_cut_req, (void*)1);
                break;
            default:
                if(track_is_timer_run(TRACK_CUST_PREHET_SYSTEM_TIMER_ID))
                {
                    track_stop_timer(TRACK_CUST_PREHET_SYSTEM_TIMER_ID);
                }
                break;
        }
}
#endif
