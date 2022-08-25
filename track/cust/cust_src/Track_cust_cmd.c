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
#include "Conversions.h"
#include <math.h>
#include "us_timer.h"
#include "uem_context.h"
#include "track_at_call.h"
#include "track_os_ell.h"
#include "track_nvram_default_value.h"
#include "track_version.h"
#include "track_os_paramete.h"
/*****************************************************************************
*  Define                               宏定义
******************************************************************************/
//#define ON_OFF(value) (value==0?s_OFF:(value==1?s_ON:s_Error))


/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/
typedef struct
{
    char**          cmd;
    kal_uint8       count;
    Cmd_Type        type;
} cmd_online_struct;

typedef void(*Func_CustRecvCmdPtr)(char*, char*, Cmd_Type);

typedef struct
{
    char                    *cmd_string;
    Func_CustRecvCmdPtr     func_ptr;
} cust_recv_cmd_struct;

typedef void(*Func_CustRecvPtr)(CMD_DATA_STRUCT*);

typedef struct
{
    const char           *cmd_string;
    Func_CustRecvPtr     func_ptr;
} cust_recv_struct;


/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
#if defined(__GERMANY__)
static char  *s_ON = {"EIN"}, *s_OFF = {"AUS"}, *s_Error = {"Fehler"};
#else
static char  *s_ON = {"ON"}, *s_OFF = {"OFF"}, *s_Error = {"ERROR"};
#endif
#if defined(__NF2318__)
static char querydata[640] = {0};
static char setdata[640] = {0};
static int rsplen = 0;
static U8 rspcount = 0;
#endif
/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/
kal_uint8 g_test_flag = 0;
char dail_num[TRACK_DEFINE_PHONE_NUMBER_LEN_MAX] = {0};
kal_uint32 dail_count = 0;
static kal_uint32 ft_timer = 0;
static kal_uint32  ft_work_timer = 0;

#if defined (__SAME_GT02__)
/*单GT02使用，关起来节约空间       --    chengjun  2017-04-13*/
const nvram_importance_parameter_struct NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT_SERVER_COOACCESS =
{
    {__DATE__},
    {__TIME__},
    {"WM"},
    {_TRACK_VER_PARAMETER_},
    {KAL_FALSE, "CMNET", "", ""},
    {
        /*www.cooaccess.net*/
        {0xE7, 0xF0, 0xF3, 0xE4, 0xE5, 0xF6, 0xAE, 0xF4, 0xF2, 0xE1, 0xE3, 0xEB, 0xF3, 0xEF, 0xEC, 0xE9, 0xE4, 0xAE, 0xE3, 0xEF, 0xED},
        1, {183, 60, 142, 137}, 21101, 0, 0, 0, 0
    }
    , {
        /*agps.topstargps.com:12283*/
        {0xE4 , 0xE5 , 0xF6 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE3 , 0xEC , 0xEF , 0xF5 , 0xE4 , 0xAE , 0xE3 , 0xEF , 0xED},
        1, {183, 63, 53, 246}, 12283, 0, 0, 0
    },
    {
        {

            {0XF7 , 0xF7 , 0xF7 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE1 , 0xE7 , 0xF0 , 0xF3 , 0xAE , 0xE3 , 0xEF , 0xED},
            1, {116, 204, 8, 57}, 12283, 0, 0, 0
        }
        , {
            {0xF7 , 0xF7 , 0xF7 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE1 , 0xED , 0xF3 , 0xAE , 0xE3 , 0xEF , 0xED},
            1, {116, 204, 8, 57}, 12283, 0, 0, 0
        }
        , {
            {0xE4 , 0xE5 , 0xF6 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE3 , 0xEC , 0xEF , 0xF5 , 0xE4 , 0xAE , 0xE3 , 0xEF , 0xED},
            1, {116, 204, 8, 57}, 12283, 0, 0, 0
        }
        , {
            {0xE1, 0xE7, 0xF0, 0xF3, 0xAE, 0xF4, 0xEF, 0xF0, 0xF3, 0xF4, 0xE1, 0xF2, 0xE7, 0xF0, 0xF3, 0xAE, 0xE3, 0xEF, 0xED},
            0, {114, 67, 59, 162}, 12283, 0, 0, 0
        }
    }
    , {
        {0xE7 , 0xF4, 0xB0 , 0xB2, 0xAE , 0xE7 , 0xEF, 0xEF, 0xED , 0xE5 , 0xE7, 0xF0, 0xF3, 0xAE, 0xEE, 0xE5 , 0xF4},
        1,
        {202, 104, 149, 80},
        9888,
        0,
        0,
        0,
        0,
    }
    , {3, 1, 1, 0} //外贸版本，SENSOR，支持国外版功能

};

const nvram_importance_parameter_struct NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT_SERVER_TUQIANG =
{
    {__DATE__},
    {__TIME__},
    {"TQ"},
    {_TRACK_VER_PARAMETER_},
    {KAL_FALSE, "CMNET", "", ""},
    {
        /*atr02.tuqianggps.com*/
        {0xE7, 0xF0, 0xF3, 0xE4, 0xE5, 0xF6, 0xAE, 0xEA, 0xE9, 0xED, 0xE9, 0xE3, 0xEC, 0xEF, 0xF5, 0xE4, 0xAE, 0xE3, 0xEF, 0xED},
        1, {202, 70, 2, 53}, 21101, 0, 0, 0, 0
    }
    , {
        /*agps.topstargps.com:12283*/
        {0xE4 , 0xE5 , 0xF6 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE3 , 0xEC , 0xEF , 0xF5 , 0xE4 , 0xAE , 0xE3 , 0xEF , 0xED},
        1, {183, 63, 53, 246}, 12283, 0, 0, 0
    }
    ,
    {
        {

            {0XF7 , 0xF7 , 0xF7 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE1 , 0xE7 , 0xF0 , 0xF3 , 0xAE , 0xE3 , 0xEF , 0xED},
            1, {116, 204, 8, 57}, 12283, 0, 0, 0
        }
        , {
            {0xF7 , 0xF7 , 0xF7 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE1 , 0xED , 0xF3 , 0xAE , 0xE3 , 0xEF , 0xED},
            1, {116, 204, 8, 57}, 12283, 0, 0, 0
        }
        , {
            {0xE4 , 0xE5 , 0xF6 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE3 , 0xEC , 0xEF , 0xF5 , 0xE4 , 0xAE , 0xE3 , 0xEF , 0xED},
            1, {116, 204, 8, 57}, 12283, 0, 0, 0
        }
        , {
            {0xE1, 0xE7, 0xF0, 0xF3, 0xAE, 0xF4, 0xEF, 0xF0, 0xF3, 0xF4, 0xE1, 0xF2, 0xE7, 0xF0, 0xF3, 0xAE, 0xE3, 0xEF, 0xED},
            0, {114, 67, 59, 162}, 12283, 0, 0, 0
        }
    }
    , {
        {0xE7 , 0xF4, 0xB0 , 0xB2, 0xAE , 0xE7 , 0xEF, 0xEF, 0xED , 0xE5 , 0xE7, 0xF0, 0xF3, 0xAE, 0xEE, 0xE5 , 0xF4},
        1,
        {202, 104, 149, 80},
        9888,
        0,
        0,
        0,
        0,
    }
    , {4, 1, 0, 0} //图强版本，支持SENSOR，不支持国外版功能


};


const nvram_importance_parameter_struct NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT_SERVER_GUMI =
{
    {__DATE__},
    {__TIME__},
    {"GM"},
    {_TRACK_VER_PARAMETER_},
    {KAL_FALSE, "CMNET", "", ""},
    {
        /*atr02.tuqianggps.com*/
        {0xE1, 0xF4, 0xF2, 0xB0, 0xB2, 0xAE, 0xF4, 0xF5, 0xF1, 0xE9, 0xE1, 0xEE, 0xE7, 0xE7, 0xF0, 0xF3, 0xAE, 0xE3, 0xEF, 0xED},
        1, {202, 70, 2, 53}, 8821, 0, 0, 0, 0
    }
    , {
        /*agps.topstargps.com:12283*/
        {0xE4 , 0xE5 , 0xF6 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE3 , 0xEC , 0xEF , 0xF5 , 0xE4 , 0xAE , 0xE3 , 0xEF , 0xED},
        1, {183, 63, 53, 246}, 12283, 0, 0, 0, 0
    },
    {
        {

            {0XF7 , 0xF7 , 0xF7 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE1 , 0xE7 , 0xF0 , 0xF3 , 0xAE , 0xE3 , 0xEF , 0xED},
            1, {116, 204, 8, 57}, 12283, 0, 0, 0
        }
        , {
            {0xF7 , 0xF7 , 0xF7 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE1 , 0xED , 0xF3 , 0xAE , 0xE3 , 0xEF , 0xED},
            1, {116, 204, 8, 57}, 12283, 0, 0, 0
        }
        , {
            {0xE4 , 0xE5 , 0xF6 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE3 , 0xEC , 0xEF , 0xF5 , 0xE4 , 0xAE , 0xE3 , 0xEF , 0xED},
            1, {116, 204, 8, 57}, 12283, 0, 0, 0
        }
        , {
            {0xE1, 0xE7, 0xF0, 0xF3, 0xAE, 0xF4, 0xEF, 0xF0, 0xF3, 0xF4, 0xE1, 0xF2, 0xE7, 0xF0, 0xF3, 0xAE, 0xE3, 0xEF, 0xED},
            0, {114, 67, 59, 162}, 12283, 0, 0, 0
        }
    }
    , {
        //gt02.goomegps.net
        {0xE7 , 0xF4, 0xB0 , 0xB2, 0xAE , 0xE7 , 0xEF, 0xEF, 0xED , 0xE5 , 0xE7, 0xF0, 0xF3, 0xAE, 0xEE, 0xE5 , 0xF4},
        1,
        {202, 104, 149, 80},
        9888,
        0,
        1,
        0,
        0,
    }

    , {1, 1, 0, 1} //谷米版本，不支持SENSOR，不支持国外版功能

};

const nvram_importance_parameter_struct NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT_GUMI_GENERAL =
{
    {__DATE__},
    {__TIME__},
    {"TY"},
    {_TRACK_VER_PARAMETER_},
    {KAL_FALSE, "CMNET", "", ""},
    {
        /*atr02.tuqianggps.com*/
        {0xE1, 0xF4, 0xF2, 0xB0, 0xB2, 0xAE, 0xF4, 0xF5, 0xF1, 0xE9, 0xE1, 0xEE, 0xE7, 0xE7, 0xF0, 0xF3, 0xAE, 0xE3, 0xEF, 0xED},
        1, {202, 70, 2, 53}, 8821, 0, 0, 0, 0
    }
    , {
        /*agps.topstargps.com:12283*/
        {0xE4 , 0xE5 , 0xF6 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE3 , 0xEC , 0xEF , 0xF5 , 0xE4 , 0xAE , 0xE3 , 0xEF , 0xED},
        1, {183, 63, 53, 246}, 12283, 0, 0, 0
    }
    ,
    {
        {

            {0XF7 , 0xF7 , 0xF7 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE1 , 0xE7 , 0xF0 , 0xF3 , 0xAE , 0xE3 , 0xEF , 0xED},
            1, {116, 204, 8, 57}, 12283, 0, 0, 0
        }
        , {
            {0xF7 , 0xF7 , 0xF7 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE1 , 0xED , 0xF3 , 0xAE , 0xE3 , 0xEF , 0xED},
            1, {116, 204, 8, 57}, 12283, 0, 0, 0
        }
        , {
            {0xE4 , 0xE5 , 0xF6 , 0xAE , 0xEA , 0xE9 , 0xED , 0xE9 , 0xE3 , 0xEC , 0xEF , 0xF5 , 0xE4 , 0xAE , 0xE3 , 0xEF , 0xED},
            1, {116, 204, 8, 57}, 12283, 0, 0, 0
        }
        , {
            {0xE1, 0xE7, 0xF0, 0xF3, 0xAE, 0xF4, 0xEF, 0xF0, 0xF3, 0xF4, 0xE1, 0xF2, 0xE7, 0xF0, 0xF3, 0xAE, 0xE3, 0xEF, 0xED},
            0, {114, 67, 59, 162}, 12283, 0, 0, 0
        }
    }

    , {
        //gt02.goomegps.net
        {0xE7 , 0xF4, 0xB0 , 0xB2, 0xAE , 0xE7 , 0xEF, 0xEF, 0xED , 0xE5 , 0xE7, 0xF0, 0xF3, 0xAE, 0xEE, 0xE5 , 0xF4},
        1,
        {202, 104, 149, 80},
        9888,
        0,
        1,
        0,
        0,
    }
    , {2, 1, 0, 0} //谷米通用版本，不支持SENSOR，不支持国外版功能

};

#endif /* __SAME_GT02__ */

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/
extern nvram_parameter_struct     G_parameter;
extern nvram_importance_parameter_struct G_importance_parameter_data;
extern nvram_phone_number_struct       G_phone_number;

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern void track_cust_module_sd_acc(void *arg);
extern nvram_GPRS_APN_struct *track_socket_get_use_apn(void);
extern void track_soc_send(void *par);
extern void track_cust_sleep_mode(void);
extern void track_cust_wake_mode(void);
extern void cmd_seefence(CMD_DATA_STRUCT *cmd);
extern kal_uint8 track_cust_dial_makecall(void* arg);
extern void track_cust_server2_conn(void *arg);
extern char *track_get_app_version_datetime(void);
extern kal_char *build_date_time(void);
extern char *track_cust_get_version_for_upload_server(void);
extern S32 track_cust_get_data_from_file(char *file_path, U8 *data, U32 len);
extern U32 track_get_gps_distance(void);
extern void track_set_gps_distance(U32 distance);
extern kal_bool track_is_recv_cmd_after_boot(kal_uint8 par);
extern kal_uint32 track_cust_gpson_timer(kal_uint32 time);
extern void track_socket_check_apn_diskdata(void);
extern void lbs_cmd_send(CMD_DATA_STRUCT * cmd);
#if defined(__GT370__)|| defined (__GT380__)
extern void track_cust_module_sw_init(void);
#endif
#ifdef __WIFI__
extern void track_drv_wifi_work_mode(void);
#endif /* __WIFI__ */
#if defined(__BLE_GATT__)
extern void track_drv_syn_le_btaddr();
#endif
extern U8 track_cust_querycmd();

extern void test_desired_value(int value , int type);
extern void track_soc_clear_dw_queue(void);
/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/

#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

/******************************************************************************
 *  Function    -  cmd_updata_to_net
 *
 *  Purpose     -  在非在线指令情况下同步传数据到后台
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 04-01-2014,  ZengPing && Liujw  written
 * ----------------------------------------
 ******************************************************************************/
static void cmd_updata_to_net(CMD_DATA_STRUCT * cmd)
{
    if(cmd->return_sms.reply_character_encode == 0)
    {
        cmd->rsp_length = strlen(cmd->rsp_msg);
        if(cmd->rsp_length > 0)
        {
            if(cmd->return_sms.cm_type != CM_ONLINE)
            {
                track_cust_paket_msg_upload(cmd->return_sms.stamp, KAL_TRUE, cmd->rsp_msg, cmd->rsp_length);
            }
        }
    }
    else
    {
        if(cmd->return_sms.cm_type != CM_ONLINE && cmd->rsp_length > 0)
        {
            track_cust_paket_msg_upload(cmd->return_sms.stamp, KAL_FALSE, cmd->rsp_msg, cmd->rsp_length);
        }
    }
}

static kal_bool enter_lat_lon(kal_bool NS, kal_uint8 *str, float *value)
{
    if(track_fun_check_str_is_number(3, str) != 0)
    {
        *value = atof(str);
    }
    else if(NS && (str[0] == 'N' || str[0] == 'S') && track_fun_check_str_is_number(2, &str[1]) != 0)
    {
        if(str[0] == 'N')
        {
            *value = atof(&str[1]);
        }
        else
        {
            *value = -atof(&str[1]);
        }
    }
    else if(!NS && (str[0] == 'E' || str[0] == 'W') && track_fun_check_str_is_number(2, &str[1]) != 0)
    {
        if(str[0] == 'E')
            *value = atof(&str[1]);
        else
            *value = -atof(&str[1]);
    }
    else return KAL_FALSE;
    return KAL_TRUE;
}

static void return_message(CMD_DATA_STRUCT *cmd, char *english_string, char *chinese_string)
{
    /* 由于考虑到服务器的兼容性问题，在线指令仅进行英文信息回复 */
    if(G_parameter.lang == 1 && cmd->return_sms.cm_type != CM_ONLINE && cmd->return_sms.cm_type != CM_ONLINE2)
    {
        if(cmd->return_sms.cm_type == CM_AT)
        {
            cmd->rsp_length = strlen(chinese_string);
            if(cmd->rsp_length >= CM_PARAM_LONG_LEN_MAX)
            {
                cmd->rsp_length = CM_PARAM_LONG_LEN_MAX - 2;
            }
            memcpy(cmd->rsp_msg, chinese_string, cmd->rsp_length);
            cmd->return_sms.reply_character_encode = 2;
        }
        else
        {
            cmd->rsp_length = track_fun_GB2312_to_UTF16BE(chinese_string, strlen(chinese_string), cmd->rsp_msg, 320);
            cmd->return_sms.reply_character_encode = 1;
        }
    }
    else
    {
        snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, "%s", english_string);
    }
}

#if defined(__AUDIO_RC__)
/******************************************************************************
 *  Function    -  track_call_mode_stop_action
 *
 *  Purpose     -
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 21-11-2013,  WangQ  written
 * ----------------------------------------
*******************************************************************************/
static void track_call_mode_stop_action(void* flag)
{
    int f = (int)flag;
    LOGD(L_APP, L_V5, "f:%d", f);

    if(f)
    {
        if(G_parameter.callmode == 0 || G_parameter.callmode == 2)
        {
            track_cust_audio_play_voice(MT_RING);
        }

        if(G_parameter.callmode >= 1)
        {
            track_cust_ring_Vibration((void*)0);
            track_cust_vib_interval(0, 5000, 0);
            track_cust_ring_Vibration((void*)1);
        }
    }
    else
    {
        track_cust_audio_play_voice(MT_DISCONNECT);

        if(TR_CALL_RING == track_get_call_state())
        {
            track_cust_audio_play_voice(MT_RING);
        }
    }
}
#endif /* __AUDIO_RC__ */

/**********************************************************************/
/**********************************************************************/
static void cmd_Uart2_PassThrough(CMD_DATA_STRUCT * cmd)
{
    int len, j;
    j = cmd->pars[1] - cmd->rcv_msg;
    //LOGD(L_APP, L_V2, "%p,%p,%p,{%s},{%s},{%s}",
    //    cmd->rcv_msg_source, cmd->pars[1], cmd->rcv_msg, cmd->pars[1], cmd->rcv_msg, cmd->rcv_msg_source);
    len = strlen(cmd->rcv_msg_source);
    LOGD(L_APP, L_V2, "%d,%d,%d", len, j, strlen(cmd->rcv_msg_source));
    LOGH(L_APP, L_V2, cmd->rcv_msg_source, strlen(cmd->rcv_msg_source));
    if(cmd->rcv_msg_source[len - 1] == 0x0D)
    {
        cmd->rcv_msg_source[len] = 0x0A;
        cmd->rcv_msg_source[len + 1] = 0x00;
        len++;
    }
    if(len > 0 && len < 200 && j > 0)
    {
        track_drv_uart2_write_data(cmd->rcv_msg_source + j, len - j);
    }
}


static void cmd_set_version2(CMD_DATA_STRUCT * cmd)
{
    char *ver;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s", G_importance_parameter_data.version_string);
        return;
    }
    else if(cmd->part != 1)
    {
        sprintf(cmd->rsp_msg, "ERROR:100");//指令长度不正确
        return;
    }
    if(strlen(cmd->pars[1]) >= 20)
    {
        sprintf(cmd->rsp_msg, "parameter error! string length must be less than 20.");
        return;
    }
    strcpy(G_importance_parameter_data.version_string, cmd->pars[1]);
    ver = track_get_app_version();
    if(strlen(ver) <= 0)
    {
        ver = (char*)release_verno();
    }
    sprintf(cmd->rsp_msg, "[VERSION]%s_%s\r\n[BUILD]%s\r\n", ver, G_importance_parameter_data.version_string, build_date_time());
}

/******************************************************************************
 *  Function    -  cmd_get_app_version
 *
 *  Purpose     -  获取软件版本号
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_get_base_version(CMD_DATA_STRUCT * cmd)
{
    if(cmd->part == 1 && !strcmp(cmd->pars[1], "BUILD"))
    {
        sprintf(cmd->rsp_msg, "[BASE]%s [BUILD]%s", track_get_base_version(), build_date_time());
        return;
    }
    else if(cmd->part != 0)
    {
        sprintf(cmd->rsp_msg, "ERROR:100");//指令长度不正确
        return;
    }
    sprintf(cmd->rsp_msg, "[BASE]%s", track_get_base_version());
}

/******************************************************************************
 *  Function    -  cmd_get_SW_version
 *
 *  Purpose     -  获取软件版本号
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_get_version(CMD_DATA_STRUCT * cmd)
{
    char *ver, *build,*sw;
	extern char *track_get_appversion();
    ver = track_get_app_version();
    build = track_get_app_version_datetime();
    if(strlen(ver) <= 0)
    {
        ver = (char*)release_verno();
        build = build_date_time();
    }
	sw = track_get_appversion();
    if(cmd->part == 1 && !strcmp(cmd->pars[1], "BUILD"))
    {
        if(strlen(G_importance_parameter_data.version_string) > 0)
        {
            sprintf(cmd->rsp_msg, "[VERSION]%s_%s [BUILD]%s", ver, G_importance_parameter_data.version_string, build);
        }
        else
        {
            sprintf(cmd->rsp_msg, "[VERSION]%s [BUILD]%s [SW]%s", ver, build,sw);
        }
        return;
    }
    else if(cmd->part != 0)
    {
        sprintf(cmd->rsp_msg, "ERROR:100");//指令长度不正确
        return;
    }
    if(strlen(G_importance_parameter_data.version_string) > 0)
    {
        sprintf(cmd->rsp_msg, "[VERSION]%s_%s", ver, G_importance_parameter_data.version_string);
    }
    else
    {
        sprintf(cmd->rsp_msg, "[VERSION]%s", ver);
    }
}

static void cmd_test_net_log(CMD_DATA_STRUCT * cmd)
{
    kal_uint32 value;
    int ret;

    if(cmd->part == 1)
    {
        ret = atoi((char*)cmd->pars[1]);
        value = ret;
        G_realtime_data.netLogControl = value;
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        LOGD(L_CMD, L_V4, "Custom_ReStart() netLogControl=%d", G_realtime_data.netLogControl);
        sprintf(cmd->rsp_msg, "OK");
    }
    else
    {
        sprintf(cmd->rsp_msg, "netLogControl=%d", G_realtime_data.netLogControl);
    }
}

static void cmd_up_param(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        char tmp[20] = {0};
        if(G_realtime_data.up_param == 0) strcpy(tmp, "OFF");
        else if(G_realtime_data.up_param == 1) strcpy(tmp, "ON");
        else strcpy(tmp, "ERROR");
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], tmp);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    if(!strcmp(cmd->pars[1], "ON"))
    {
        G_realtime_data.up_param = 1;
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        G_realtime_data.up_param = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    if(Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

#if defined(__WIFI__)
void track_ljdw_1min_overtime(void *stamp)
{
    track_gps_data_struct *gd = track_drv_get_gps_data();
    if(gd->bdgga.sat >= 2)
    {
        return;
    }
    track_drv_wifi_work_mode();
    tr_stop_timer(TRACK_CUST_LJDW_OVERTIME_2MIN_TIMER_ID);
    track_cust_paket_msg_upload((kal_uint8*)stamp, KAL_TRUE, "GPS TIMEOUT", strlen("GPS TIMEOUT"));
}

void track_ljdw_2min_overtime(void *stamp)
{
    track_drv_wifi_work_mode();
    track_cust_paket_msg_upload((kal_uint8*)stamp, KAL_TRUE, "GPS TIMEOUT", strlen("GPS TIMEOUT"));
}

static void cmd_ljdw(CMD_DATA_STRUCT *cmd)
{
    static kal_uint8 stamp[4] = {0};
    track_drv_wifi_work_mode();
    track_cust_gps_work_req((void*)17);
    memcpy(stamp, cmd->return_sms.stamp, 4);
    track_start_timer(TRACK_CUST_LJDW_OVERTIME_1MIN_TIMER_ID, 60000, track_ljdw_1min_overtime, (void*) stamp); // 定位超时
    track_start_timer(TRACK_CUST_LJDW_OVERTIME_2MIN_TIMER_ID, 120000, track_ljdw_2min_overtime, (void*)stamp); // 定位超时
}
#endif /* __WIFI__ */
#if 0
static void cmd_dw(CMD_DATA_STRUCT *cmd)
{
    LOGD(L_APP, L_V5, "%s, %s, %s, %s", cmd->return_sms.ph_num, cmd->pars[0], cmd->pars[1], cmd->pars[2]);
    if(cmd->part == 0 || ((cmd->return_sms.cm_type == CM_ONLINE || cmd->return_sms.cm_type == CM_ONLINE2) && cmd->part == 1 && !strcmp(cmd->pars[1], "000000")))    //超级密码写死？  chengj
    {
        track_cust_module_get_addr(cmd);
    }
}
#endif
/******************************************************************************
 *  Function    -  cmd_eurl
 *
 *  Purpose     -  编辑默认的URL连接
 *
 *  Description -
        EURL,网络链接#
            设置经纬度连接；默认值：http://maps.google.com/maps?q=
        EURL#
            查询设置的值
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 24-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_eurl(CMD_DATA_STRUCT *cmd)
{
#if defined(__NF2318__)
;
#else
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s", G_parameter.url);
        return;
    }
    if(strlen(cmd->pars[1]) == 0 || cmd->part != 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(strlen(cmd->pars[1]) >= 100)
    {
        sprintf(cmd->rsp_msg, "Error: URL string is too long!");
        return;
    }
    else
    {
        char tmp[100] = {0};
        int len;
        memset(G_parameter.url, 0, 100);
        len = strlen(cmd->pars[1]);
        memcpy(tmp, cmd->rcv_msg_source + (cmd->pars[1] - cmd->rcv_msg), (len >= 100 ? 99 : len));
        snprintf(G_parameter.url, 100, "%s", tmp);
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        sprintf(cmd->rsp_msg, "OK!");
    }
	#endif
}

static void cmd_smstc(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d(1=ON, 0=OFF)", cmd->pars[0], G_parameter.smstc.sw);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(!strcmp(cmd->pars[1], "1") || !strcmp(cmd->pars[1], "ON"))
    {
        G_parameter.smstc.sw = 1;
    }
    else if(!strcmp(cmd->pars[1], "0") || !strcmp(cmd->pars[1], "OFF"))
    {
        G_parameter.smstc.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (0/1)");
        return;
    }

    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#if defined(__NF2318__)
#else
static void cmd_ledsleep(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        char tmp[20] = {0};
        if(G_parameter.led_sleep == 2) strcpy(tmp, ON_OFF(0));
        else if(G_parameter.led_sleep == 1) strcpy(tmp, ON_OFF(1));
        else if(G_parameter.led_sleep == 3) strcpy(tmp, "LED ALWAYS OFF");
        else strcpy(tmp, "ERROR");
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], tmp);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    if(!strcmp(cmd->pars[1], "ON"))
    {
        G_parameter.led_sleep = 1;
#if defined(__SAME_GT02__)
        if(track_cust_gps_status() == GPS_STAUS_OFF || G_realtime_data.key_status == 0)
        {
            track_cust_led_sleep(2);
        }
        else
        {
            track_cust_led_sleep(1);
        }
#else
        G_realtime_data.key_status = 1;
        if(track_cust_gps_status() == GPS_STAUS_OFF)
        {
            track_cust_led_sleep(2);
        }
        else
        {
            track_cust_led_sleep(1);
        }
#endif /* __SAME_GT02__ */
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        G_parameter.led_sleep = 2;

#if defined(__SAME_GT02__)
        if(G_realtime_data.key_status)
        {
            track_cust_led_sleep(1);
        }
#else
        G_realtime_data.key_status = 1;
        track_cust_led_sleep(1);
#endif /* __SAME_GT02__ */
    }
    else if(!strcmp(cmd->pars[1], "LED_ALWAYS_OFF"))
    {
        G_parameter.led_sleep = 3;
        track_cust_led_sleep(2);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#endif
static void cmd_ledsw(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        char tmp[20] = {0};
        if(G_realtime_data.key_status == 0) strcpy(tmp, "OFF");
        else if(G_realtime_data.key_status == 1) strcpy(tmp, "ON");
        else strcpy(tmp, "ERROR");
        sprintf(cmd->rsp_msg, "%s=%s", cmd->pars[0], tmp);
        return;
    }
    else if(cmd->part > 1)
    {
        //sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        sprintf(cmd->rsp_msg, "LEDSW=FAIL");
        return;
    }

    if(!strcmp(cmd->pars[1], "ON"))
    {
        G_realtime_data.key_status = 1;
		tr_stop_timer(TRACK_LED_SLEEP_OVERTIME_TIMER_ID);
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        G_realtime_data.key_status = 0;
    }
    else
    {
        //sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        sprintf(cmd->rsp_msg, "LEDSW=FAIL");
        return;
    }

    if(G_realtime_data.key_status == 0)
    {
        track_cust_led_sleep(2);
    }
    else if(G_realtime_data.key_status == 1)
    {
        track_cust_led_sleep(1);
    }

    if(Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE))
    {
        //sprintf(cmd->rsp_msg, "OK!");
        sprintf(cmd->rsp_msg, "%s=OK",cmd->pars[0]);
    }
    else
    {
        //sprintf(cmd->rsp_msg, "Error!");
        sprintf(cmd->rsp_msg, "%s=FAIL",cmd->pars[0]);
    }
}

static void cmd_lockip(CMD_DATA_STRUCT *cmd)
{
    if(cmd->supercmd != 1 && cmd->return_sms.cm_type == CM_SMS)
    {
        if(track_cust_sos_or_center_check(3, cmd->return_sms.ph_num) != 9)
        {
#if defined(__GERMANY__)
            sprintf(cmd->rsp_msg, "SMS kommt nicht von der Center-Nr. und wird nicht aktiviert.");

#else
            sprintf(cmd->rsp_msg, "Error: only SOS number and center number is able to execute the command.");
#endif/*__GERMANY__*/

            return;
        }
    }
    if(cmd->part == 0)
    {
        G_importance_parameter_data.server.lock = 1;
        sprintf(cmd->rsp_msg, "Domain successfully locked!");
        Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
        //track_os_intoTaskMsgQueue(track_cust_write_sim_backup_for_parameter);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
}

static void cmd_qlockip(CMD_DATA_STRUCT *cmd)
{
    if(cmd->supercmd != 1 && cmd->return_sms.cm_type == CM_SMS)
    {
        if(track_cust_sos_or_center_check(3, cmd->return_sms.ph_num) != 9)
        {
#if defined(__GERMANY__)
            sprintf(cmd->rsp_msg, "SMS kommt nicht von der Center-Nr. und wird nicht aktiviert.");

#else
            sprintf(cmd->rsp_msg, "Error: only SOS number and center number is able to execute the command.");
#endif/*__GERMANY__*/

            return;
        }
    }
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d(0:unlock  1:lock)", cmd->pars[0],
                G_importance_parameter_data.server.lock);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
    }
    return;
}


#if defined(__GERMANY__)
/********************************************************************************

        ausgang,1#
            A=0/1；1 接通电路，0 断开电路
            A=2；执行接通电路, 保持2秒后断开
            A=10;执行接通电路, 保持10分钟后断开
            A=20;执行接通电路, 保持20分钟后断开
            A=30;执行接通电路, 保持30分钟后断开
        ausgang#
            查询已设置的参数
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 02-23-2017,  cjj  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_ausgang(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 time;
    if(track_cust_status_acc() == 1)
    {
        sprintf(cmd->rsp_msg, "Zuendung ist eingeschaltet");
        return;
    }
    if(cmd->part != 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(cmd->return_sms.cm_type == CM_SMS && track_fun_convert_phone_number_to_int(cmd->return_sms.ph_num) != track_fun_convert_phone_number_to_int(G_parameter.centerNumber))
    {
#if defined(__GERMANY__)
        return_message(
            cmd,
            "SMS kommt nicht von der Center-Nr.und wird nicht aktiviert.",
            "来自非法中心号码的指令不执行！");
#else
        return_message(
            cmd,
            "The command is not from the center number, The command is not executed!",
            "来自非法中心号码的指令不执行！");
#endif
        return;
    }
    if(!strcmp(cmd->pars[1], "0") || !strcmp(cmd->pars[1], "1") || !strcmp(cmd->pars[1], "2") ||
            !strcmp(cmd->pars[1], "10") || !strcmp(cmd->pars[1], "20") || !strcmp(cmd->pars[1], "30"))
    {
        time = track_fun_atoi(cmd->pars[1]);
        track_cust_module_Preheat_System(time);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 error");
        return;
    }

    sprintf(cmd->rsp_msg, "OK!");
}
#endif
#if defined(__NF2318__)
#else
static void cmd_gtimer(CMD_DATA_STRUCT *cmd)
{
    int value = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0],
                G_parameter.gps_work.Fti.mode1_gps_time);
        return;
    }

    if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 0 || value > 300)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (0-300)");
        return;
    }
    G_parameter.gps_work.Fti.mode1_gps_time = value;
    if(value != 0)
    {
        LOGD(L_CMD, L_V5, "mode1_gps_time = %d;value=%d", G_parameter.gps_work.Fti.mode1_gps_time, value);
        track_cust_gps_work_req((void*)13);
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
static void cmd_lcd(CMD_DATA_STRUCT *cmd)
{
    int value = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.lcd_on_time);
        return;
    }

    if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value != 0 && (value < 5 || value > 60))
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (0,5-60)");
        return;
    }
    G_parameter.lcd_on_time = value;
    if(0 == G_parameter.lcd_on_time)
    {
        track_stop_timer(TRACK_CUST_SOS_KEY_LED_ON_TIMER);
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#endif
/******************************************************************************
 *  Function    -  cmd_lang
 *
 *  Purpose     -  语言设置
 *
 *  Description -
        LANG,X#
            X=1/2；1 中文，2 英文；默认值为：1
        LANG#
            返回当前设置的语言
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_lang(CMD_DATA_STRUCT *cmd)
{
    int value;
    if(cmd->part == 0)
    {
    #if defined(__NF2318__)
	sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.lang);
	#else
        sprintf(cmd->rsp_msg, "%s:%d (0=English, 1=Chinese)", cmd->pars[0], G_parameter.lang);
	#endif
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 0 || value > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Range error. (0=English, 1=Chinese)");
        return;
    }
    G_parameter.lang = value;
	

    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
#if defined(__NF2318__)
	{
		sprintf(cmd->rsp_msg, "%s=OK",cmd->pars[0]);
	}
	else
	{
		sprintf(cmd->rsp_msg, "%s=FAIL",cmd->pars[0]);
	}
#else
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
#endif
}

static void cmd_apn(CMD_DATA_STRUCT *cmd)
{
    nvram_GPRS_APN_struct apn = {0};
    char tmp[100] = {0};
    int len;
    if(cmd->part == 0)
    {
        nvram_GPRS_APN_struct *use_apn = track_socket_get_use_apn();
#if defined(__GERMANY__)
        sprintf(cmd->rsp_msg, "Eingestellter APN:%s,%s,%s\r\nAPN Auto Set:%s",
                use_apn->apn,
                use_apn->username,
                use_apn->password,
                (G_importance_parameter_data.apn.custom_apn_valid ? s_OFF : s_ON));
#else
        sprintf(cmd->rsp_msg, "Currently use APN:%s,%s,%s\r\nAPN Auto Set:%s",
                use_apn->apn,
                use_apn->username,
                use_apn->password,
                (G_importance_parameter_data.apn.custom_apn_valid ? s_OFF : s_ON));
#endif
        return;
    }
    else if(cmd->part > 3)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    memcpy(&apn, &G_importance_parameter_data.apn, sizeof(nvram_GPRS_APN_struct));
    len = strlen(cmd->pars[1]);
    if(len > 0 && len < 100)
    {
        memcpy(tmp, cmd->rcv_msg_source + (cmd->pars[1] - cmd->rcv_msg), len);
        strcpy(apn.apn, tmp);
        memset(apn.username, 0, 32);
        memset(apn.password, 0, 32);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameters one of the wrong length!");
        return;
    }
    if(cmd->part >= 2)
    {
        len = strlen(cmd->pars[2]);
        if(len >= 0 && len < 32)
        {
            memcpy(tmp, cmd->rcv_msg_source + (cmd->pars[2] - cmd->rcv_msg), len);
            tmp[len] = 0;
            strcpy(apn.username, tmp);
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Parameters two of the wrong length!");
            return;
        }
    }
    if(cmd->part == 3)
    {
        len = strlen(cmd->pars[3]);
        if(len >= 0 && len < 32)
        {
            memcpy(tmp, cmd->rcv_msg_source + (cmd->pars[3] - cmd->rcv_msg), len);
            tmp[len] = 0;
            strcpy(apn.password, tmp);
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Parameters three of the wrong length!");
            return;
        }
    }
    apn.custom_apn_valid = 1;  //APN设置后，自适应APN需自动关闭
    if(memcmp(&G_importance_parameter_data.apn, &apn, sizeof(nvram_GPRS_APN_struct)))
    {
        memcpy(&G_importance_parameter_data.apn, &apn, sizeof(nvram_GPRS_APN_struct));
        Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
#if defined(__GERMANY__)
        sprintf(cmd->rsp_msg, "OK! Zum Speichern des neuen APN erfolgt ein Neustart in 10 Sek.");
#else
        sprintf(cmd->rsp_msg, "OK! for the newly-set APN to take effect, the device will reboot after 10s.");
#endif
        track_socket_check_apn_diskdata();
        //track_os_intoTaskMsgQueue(track_cust_write_sim_backup_for_parameter);
        track_cust_restart(59, 15);
    }
    else
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
}

static void cmd_asetapn(CMD_DATA_STRUCT *cmd)
{
    kal_bool value;
    if(cmd->part == 0)
    {
        nvram_GPRS_APN_struct *use_apn = track_socket_get_use_apn();
#if defined(__GERMANY__)
        sprintf(cmd->rsp_msg, "%s:%s\r\nEingestellter APN:%s,%s,%s", cmd->pars[0],
                (G_importance_parameter_data.apn.custom_apn_valid ? s_OFF : s_ON),
                use_apn->apn,
                use_apn->username,
                use_apn->password);
#else
        sprintf(cmd->rsp_msg, "%s:%s\r\nCurrently use APN:%s,%s,%s", cmd->pars[0],
                (G_importance_parameter_data.apn.custom_apn_valid ? s_OFF : s_ON),
                use_apn->apn,
                use_apn->username,
                use_apn->password);
#endif
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(!strcmp(cmd->pars[1], "ON"))  // APN 自适应有效
    {
        value = 0;
    }
    else if(!strcmp(cmd->pars[1], "OFF"))  // APN 自适应失效
    {
        value = 1;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    if(value != G_importance_parameter_data.apn.custom_apn_valid)
    {
        G_importance_parameter_data.apn.custom_apn_valid = value;
        Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
#if defined(__GERMANY__)
        sprintf(cmd->rsp_msg, "OK! Zum Speichern des neuen APN erfolgt ein Neustart in 10 Sek.");
#else
        sprintf(cmd->rsp_msg, "OK! for the newly-set APN to take effect, the device will reboot after 10s.");
#endif
        //track_os_intoTaskMsgQueue(track_cust_write_sim_backup_for_parameter);
        track_cust_restart(59, 10);
    }
    else
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
}
#if defined(__BLE_GATT__)
static void cmd_btaddr(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        //sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], (char *)track_drv_ble_get_mac(2));
        
        sprintf(cmd->rsp_msg,"Error!");
        return;
    }
	if(cmd->part == 1 && !strcmp(cmd->pars[1], "READMAC"))
	{
	    sprintf(cmd->rsp_msg, "BT MAC:\"%s\"",(char *)track_drv_ble_get_mac(2));
        return;
	}
    else if(cmd->part == 2 && !strcmp(cmd->pars[1], "MAC"))
    {
        nvram_ef_btradio_mtk_bt_chip_struct read_struct;
        int len, i, j;
        char ble_tmp[17];
        len = strlen(cmd->pars[2]);
        if(track_drv_ble_gatt_switch(99)==1)
        {
            //sprintf(cmd->rsp_msg, "Error: BT is ON, SHUT DWON FIRST!");
            //return;
        }
        if(len != 12)
        {
            sprintf(cmd->rsp_msg, "Error: length!");
            return;
        }
        Track_nvram_read(NVRAM_EF_BTRADIO_MTK_BT_CHIP_LID, 1, (void *)&read_struct, NVRAM_EF_BTRADIO_MTK_BT_CHIP_SIZE);
        sprintf(ble_tmp, "%s", cmd->pars[2]);
        LOGD(L_APP, L_V5, "%s", ble_tmp);
        if(track_fun_check_mac(ble_tmp))
        {
            LOGH(L_APP, L_V5, read_struct.BDAddr, 6);
            track_fun_macToarr(read_struct.BDAddr, ble_tmp);
            if(Track_nvram_write(NVRAM_EF_BTRADIO_MTK_BT_CHIP_LID, 1, (void *)&read_struct, NVRAM_EF_BTRADIO_MTK_BT_CHIP_SIZE))
            {
                track_read_btaddr_data();
            }
            else
            {
                sprintf(cmd->rsp_msg, "Error!");
                return;
            }
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2(0-F)!");
            return;
        }

    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter!");
        return;
    }
    sprintf(cmd->rsp_msg, "OK! %s", (char *)track_drv_ble_get_mac(2));
    track_os_intoTaskMsgQueue(track_cust_write_sim_backup_for_parameter);
    track_os_intoTaskMsgQueue(track_drv_syn_le_btaddr);
}

#endif
static void cmd_imei(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], (char *)track_drv_get_imei(0));
        return;
    }
    if(cmd->part == 2 && !strcmp(cmd->pars[1], "1"))
    {
        nvram_ef_imei_imeisv_struct imei_data = {0};
        int len, i, j;
        char imei_tmp[17];
        len = strlen(cmd->pars[2]);
        if(len != 15)
        {
            sprintf(cmd->rsp_msg, "Error: length!");
            return;
        }
        Track_nvram_read(NVRAM_EF_IMEI_IMEISV_LID, 1, (void *)&imei_data, NVRAM_EF_IMEI_IMEISV_SIZE);
        sprintf(imei_tmp, "%s0", cmd->pars[2]);
        LOGD(L_APP, L_V5, "%s", imei_tmp);
        for(i = 0, j = 0; i < 8; i++)
        {
            if(imei_tmp[j] < 0x30 || imei_tmp[j] > 0x39)
            {
                sprintf(cmd->rsp_msg, "Error: The %d non-numeric characters!", j);
                return;
            }
            imei_data.imei[i] = imei_tmp[j++] - 0x30;
            if(imei_tmp[j] < 0x30 || imei_tmp[j] > 0x39)
            {
                sprintf(cmd->rsp_msg, "Error: The %d non-numeric characters!", j);
                return;
            }
            imei_data.imei[i] |= ((imei_tmp[j++] - 0x30) << 4);
        }
        LOGH(L_APP, L_V5, imei_data.imei, 10);
        Track_nvram_write(NVRAM_EF_IMEI_IMEISV_LID, 1, (void *)&imei_data, NVRAM_EF_IMEI_IMEISV_SIZE);
        track_read_imei_data();
		get_imei(0);
        track_soc_gprs_reconnect((void*)21);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter!");
        return;
    }
    sprintf(cmd->rsp_msg, "OK! %s", (char *)track_drv_get_imei(0));
    track_os_intoTaskMsgQueue(track_cust_write_sim_backup_for_parameter);
}

static void cmd_imsi(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], (char *)track_drv_get_imsi(0));
        return;
    }
}

static void cmd_iccid(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], (char *)OTA_ell_get_iccid());
        return;
    }
}

static void cmd_viewip(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
#if defined (__SAME_GT02__)
        if(G_importance_parameter_data.dserver.server_type == 1)
        {
            sprintf(cmd->rsp_msg, "Default:%s,%s,%s,%d.%d.%d.%d:%d; ",
                    G_importance_parameter_data.dserver.conecttype == 0 ? "IP" : "domain",
                    G_importance_parameter_data.dserver.soc_type == 0 ? "TCP" : "UDP",
                    track_domain_decode(G_importance_parameter_data.dserver.url),
                    G_importance_parameter_data.dserver.server_ip[0],
                    G_importance_parameter_data.dserver.server_ip[1],
                    G_importance_parameter_data.dserver.server_ip[2],
                    G_importance_parameter_data.dserver.server_ip[3],
                    G_importance_parameter_data.dserver.server_port
                   );
            track_soc_view_IP(cmd->rsp_msg + strlen(cmd->rsp_msg));
            return;
        }
#endif /* __SAME_GT02__ */

        sprintf(cmd->rsp_msg, "Default:%s,%s,%s,%d.%d.%d.%d:%d; ",
                G_importance_parameter_data.server.conecttype == 0 ? "IP" : "domain",
                G_importance_parameter_data.server.soc_type == 0 ? "TCP" : "UDP",
                track_domain_decode(G_importance_parameter_data.server.url),
                G_importance_parameter_data.server.server_ip[0],
                G_importance_parameter_data.server.server_ip[1],
                G_importance_parameter_data.server.server_ip[2],
                G_importance_parameter_data.server.server_ip[3],
                G_importance_parameter_data.server.server_port
               );
        track_soc_view_IP(cmd->rsp_msg + strlen(cmd->rsp_msg));
    }
}


/******************************************************************************
 *  Function    -  cmd_server
 *
 *  Purpose     -  设置定位服务器地址参数
 *
 *  Description -  SERVER,<使用密码>, <模式>,<地址>,<端口>,<传输协议模式>#
 *                 SERVER,0,202.173.231.112,8821,0#
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 08-01-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_server(CMD_DATA_STRUCT *cmd)
{
    int value, plen;
    nvram_server_addr_struct server = {0};
    extern  nvram_importance_parameter_struct NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT;
#if defined (__SAME_GT02__)
    if(G_importance_parameter_data.app_version.server_lock && strcmp(cmd->pars[0], "SERVER1"))
    {
        return ;
    }
    if(G_importance_parameter_data.dserver.server_type == 1 && (cmd->part == 0))
    {
        if(G_importance_parameter_data.dserver.conecttype == 0)
        {
            sprintf(cmd->rsp_msg, "DSERVER,0,%d.%d.%d.%d,%d,%d",
                    G_importance_parameter_data.dserver.server_ip[0], G_importance_parameter_data.dserver.server_ip[1],
                    G_importance_parameter_data.dserver.server_ip[2], G_importance_parameter_data.dserver.server_ip[3],
                    G_importance_parameter_data.dserver.server_port, G_importance_parameter_data.dserver.soc_type);
        }
        else
        {
            sprintf(cmd->rsp_msg, "DSERVER,%d,%s,%d,%d",
                    G_importance_parameter_data.dserver.conecttype,
                    track_domain_decode(G_importance_parameter_data.dserver.url),
                    G_importance_parameter_data.dserver.server_port,
                    G_importance_parameter_data.dserver.soc_type);
        }
        return;
    }
#endif /* __SAME_GT02__ */

    if(cmd->part == 0)
    {
        if(G_importance_parameter_data.server.conecttype == 0)
        {
            sprintf(cmd->rsp_msg, "SERVER,0,%d.%d.%d.%d,%d,%d",
                    G_importance_parameter_data.server.server_ip[0], G_importance_parameter_data.server.server_ip[1],
                    G_importance_parameter_data.server.server_ip[2], G_importance_parameter_data.server.server_ip[3],
                    G_importance_parameter_data.server.server_port, G_importance_parameter_data.server.soc_type);
        }
        else
        {
            sprintf(cmd->rsp_msg, "SERVER,%d,%s,%d,%d",
                    G_importance_parameter_data.server.conecttype,
                    track_domain_decode(G_importance_parameter_data.server.url),
                    G_importance_parameter_data.server.server_port,
                    G_importance_parameter_data.server.soc_type);
        }
        return;
    }
    else if(cmd->part == 1 && !strcmp(cmd->pars[CM_Par1], "RESET"))
    {
        //extern nvram_importance_parameter_struct NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT[];
        memcpy(&G_importance_parameter_data.server, &NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT.server, sizeof(nvram_server_addr_struct));
        Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
        sprintf(cmd->rsp_msg, "reset OK!");
        return;
    }
    else if(cmd->part == 1 && !strcmp(cmd->pars[CM_Par1], "NULL"))
    {
        memset(&G_importance_parameter_data.server, 0, sizeof(nvram_server_addr_struct));
        Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
        sprintf(cmd->rsp_msg, "OK");
        track_soc_disconnect();
        //track_os_intoTaskMsgQueue(track_cust_write_sim_backup_for_parameter);
        return;
    }
    if(cmd->part != 3 && cmd->part != 4)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(G_importance_parameter_data.server.lock != 0)
    {
#if defined(__GERMANY__)
        sprintf(cmd->rsp_msg, "Fehler! Die Plattform Adresse wird nicht erkannt!");
#else
        sprintf(cmd->rsp_msg, "Error: The platform addresses are Locked modify!");
#endif
        return;
    }
    memset(cmd->rsp_msg, 0, sizeof(cmd->rsp_msg));

    memcpy(&server, &G_importance_parameter_data.server, sizeof(nvram_server_addr_struct));

    value = track_fun_atoi(cmd->pars[CM_Par1]);
    if(value != 0 && value != 1)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (0/1)");
        return;
    }
    server.conecttype = value;

    plen = strlen(cmd->pars[CM_Par2]);
    if(plen <= 0)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 2 is empty!");
        return;
    }
    if(plen >= 99)
    {
        sprintf(cmd->rsp_msg, "Error: Parameters 2 characters too long!");
        return;
    }
    if(track_fun_check_ip(cmd->pars[CM_Par2]))
    {
        if(server.conecttype != 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 domain is not formatted correctly!");
            return;
        }
        memset(server.server_ip, 0, 4);
        if(!track_fun_asciiIP2Hex(cmd->pars[CM_Par2], (void*)&server.server_ip[0]))
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 is not a valid IP address format!");
            return;
        }
        server.url[0] = 0;
    }
    else
    {
        if(server.conecttype != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 is not a valid IP address format!");
            return;
        }
        if(strstr(cmd->pars[CM_Par2], "http://"))
        {
            sprintf(cmd->rsp_msg, "Error: The domain name does not include \"http://\"!");
            return;
        }
        {
            char domain[TRACK_MAX_URL_SIZE] = {0};
            memcpy(domain, cmd->rcv_msg_source + (cmd->pars[CM_Par2] - cmd->rcv_msg), plen);
            track_domain_encode(domain, server.url);
            memset(server.server_ip, 0, 4);
            memcpy(G_realtime_data.server_ip, server.server_ip, 4);
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        }
    }

    if(!track_fun_check_data_is_port(cmd->pars[CM_Par3]))
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 3 (0~65535)");
        return;
    }
    server.server_port = track_fun_string2U16(cmd->pars[CM_Par3]);

    if(cmd->part == 4)
    {
        value = track_fun_atoi(cmd->pars[CM_Par4]);
        if(value != 0 && value != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 4 (0/1)");
            return;
        }
    }
    server.soc_type = 0; // 当前只支持TCP
    memcpy(&G_importance_parameter_data.server, &server, sizeof(nvram_server_addr_struct));
#if defined(__SAME_GT02__)
    G_importance_parameter_data.dserver.server_type = 0;
    track_set_server_ip_status(0);
    G_importance_parameter_data.dserver.ip_update = 0;
    G_importance_parameter_data.server.ip_update = 0;
#endif

    Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
    sprintf(cmd->rsp_msg, "OK");
    track_soc_reset_reconnect_count2();
	if(track_drv_nvram_write_switch(99) == KAL_TRUE)
	{
		track_cust_login(0x02);
	}
    track_os_intoTaskMsgQueueExt(track_soc_gprs_reconnect, (void*)22);//修改域名后，重新建立连接
    //track_os_intoTaskMsgQueue(track_cust_write_sim_backup_for_parameter);
}

static void cmd_server2(CMD_DATA_STRUCT *cmd)
{
    int value, plen;
    nvram_server_addr_struct server = {0};

    if(cmd->part == 0)
    {
        if(G_importance_parameter_data.server2.conecttype == 0)
        {
            sprintf(cmd->rsp_msg, "SERVER2,0,%d.%d.%d.%d,%d,%d",
                    G_importance_parameter_data.server2.server_ip[0], G_importance_parameter_data.server2.server_ip[1],
                    G_importance_parameter_data.server2.server_ip[2], G_importance_parameter_data.server2.server_ip[3],
                    G_importance_parameter_data.server2.server_port, G_importance_parameter_data.server2.soc_type);
        }
        else if(G_importance_parameter_data.server2.conecttype == 1)
        {
            sprintf(cmd->rsp_msg, "SERVER2,%d,%s,%d,%d",
                    G_importance_parameter_data.server2.conecttype,
                    track_domain_decode(G_importance_parameter_data.server2.url),
                    G_importance_parameter_data.server2.server_port,
                    G_importance_parameter_data.server2.soc_type);
        }
        else
        {
            sprintf(cmd->rsp_msg, "SERVER2,OFF");
        }
        return;
    }
    if(cmd->part != 3 && cmd->part != 4)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(G_importance_parameter_data.server2.lock != 0)
    {
#if defined(__GERMANY__)
        sprintf(cmd->rsp_msg, "Fehler! Die Plattform Adresse wird nicht erkannt!");
#else
        sprintf(cmd->rsp_msg, "Error: The platform addresses are Locked modify!");
#endif
        return;
    }
    memset(cmd->rsp_msg, 0, sizeof(cmd->rsp_msg));

    memcpy(&server, &G_importance_parameter_data.server2, sizeof(nvram_server_addr_struct));

    value = track_fun_atoi(cmd->pars[CM_Par1]);
    if(value != 0 && value != 1)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (0/1)");
        return;
    }
    server.conecttype = value;

    plen = strlen(cmd->pars[CM_Par2]);
    if(plen <= 0)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 2 is empty!");
        return;
    }
    if(plen >= 99)
    {
        sprintf(cmd->rsp_msg, "Error: Parameters 2 characters too long!");
        return;
    }
    if(track_fun_check_ip(cmd->pars[CM_Par2]))
    {
        if(server.conecttype != 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 domain is not formatted correctly!");
            return;
        }
        memset(server.server_ip, 0, 4);
        if(!track_fun_asciiIP2Hex(cmd->pars[CM_Par2], (void*)&server.server_ip[0]))
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 is not a valid IP address format!");
            return;
        }
    }
    else
    {
        if(server.conecttype != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 is not a valid IP address format!");
            return;
        }
        if(strstr(cmd->pars[CM_Par2], "http://"))
        {
            sprintf(cmd->rsp_msg, "Error: The domain name does not include \"http://\"!");
            return;
        }
        {
            char domain[TRACK_MAX_URL_SIZE] = {0};
            memcpy(domain, cmd->rcv_msg_source + (cmd->pars[CM_Par2] - cmd->rcv_msg), plen);
            track_domain_encode(domain, server.url);
        }
    }

    if(!track_fun_check_data_is_port(cmd->pars[CM_Par3]))
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 3 (0~65535)");
        return;
    }
    server.server_port = track_fun_string2U16(cmd->pars[CM_Par3]);

    if(cmd->part == 4)
    {
        value = track_fun_atoi(cmd->pars[CM_Par4]);
        if(value != 0 && value != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 4 (0/1)");
            return;
        }
    }
    server.soc_type = 0; // 当前只支持TCP
    memcpy(&G_importance_parameter_data.server2, &server, sizeof(nvram_server_addr_struct));
    if(Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
        track_socket_check_apn_diskdata();
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}


#if defined (__LUYING__)
static void cmd_server4(CMD_DATA_STRUCT *cmd)
{
    int value, plen;
    nvram_server_addr_struct server = {0};

    if(cmd->part == 0)
    {
        if(G_importance_parameter_data.server4.conecttype == 0)
        {
            sprintf(cmd->rsp_msg, "SERVER4,0,%d.%d.%d.%d,%d,%d",
                    G_importance_parameter_data.server4.server_ip[0], G_importance_parameter_data.server4.server_ip[1],
                    G_importance_parameter_data.server4.server_ip[2], G_importance_parameter_data.server4.server_ip[3],
                    G_importance_parameter_data.server4.server_port, G_importance_parameter_data.server4.soc_type);
        }
        else if(G_importance_parameter_data.server4.conecttype == 1)
        {
            sprintf(cmd->rsp_msg, "SERVER4,%d,%s,%d,%d",
                    G_importance_parameter_data.server4.conecttype,
                    track_domain_decode(G_importance_parameter_data.server4.url),
                    G_importance_parameter_data.server4.server_port,
                    G_importance_parameter_data.server4.soc_type);
        }
        else
        {
            sprintf(cmd->rsp_msg, "SERVER4,OFF");
        }
        return;
    }
    if(cmd->part != 3 && cmd->part != 4)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(G_importance_parameter_data.server4.lock != 0)
    {
        sprintf(cmd->rsp_msg, "Error: The platform addresses are Locked modify!");
        return;
    }
    memset(cmd->rsp_msg, 0, sizeof(cmd->rsp_msg));

    memcpy(&server, &G_importance_parameter_data.server4, sizeof(nvram_server_addr_struct));

    value = track_fun_atoi(cmd->pars[CM_Par1]);
    if(value != 0 && value != 1)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (0/1)");
        return;
    }
    server.conecttype = value;

    plen = strlen(cmd->pars[CM_Par2]);
    if(plen <= 0)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 2 is empty!");
        return;
    }
    if(plen >= 99)
    {
        sprintf(cmd->rsp_msg, "Error: Parameters 2 characters too long!");
        return;
    }
    if(track_fun_check_ip(cmd->pars[CM_Par2]))
    {
        if(server.conecttype != 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 domain is not formatted correctly!");
            return;
        }
        memset(server.server_ip, 0, 4);
        if(!track_fun_asciiIP2Hex(cmd->pars[CM_Par2], (void*)&server.server_ip[0]))
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 is not a valid IP address format!");
            return;
        }
    }
    else
    {
        if(server.conecttype != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 is not a valid IP address format!");
            return;
        }
        if(strstr(cmd->pars[CM_Par2], "http://"))
        {
            sprintf(cmd->rsp_msg, "Error: The domain name does not include \"http://\"!");
            return;
        }
        {
            char domain[TRACK_MAX_URL_SIZE] = {0};
            memcpy(domain, cmd->rcv_msg_source + (cmd->pars[CM_Par2] - cmd->rcv_msg), plen);
            track_domain_encode(domain, server.url);
        }
    }

    if(!track_fun_check_data_is_port(cmd->pars[CM_Par3]))
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 3 (0~65535)");
        return;
    }
    server.server_port = track_fun_string2U16(cmd->pars[CM_Par3]);

    if(cmd->part == 4)
    {
        value = track_fun_atoi(cmd->pars[CM_Par4]);
        if(value != 0 && value != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 4 (0/1)");
            return;
        }
    }
    server.soc_type = 0; // 当前只支持TCP
    memcpy(&G_importance_parameter_data.server4, &server, sizeof(nvram_server_addr_struct));
    if(Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
        track_socket_check_apn_diskdata();
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#endif /* __LUYING__ */

static void cmd_agps(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], ON_OFF(G_parameter.agps.sw));
        return;
    }
    /* else if(cmd->part > 1)
     {
         sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
         return;
     }*/
    if(!strcmp(cmd->pars[1], "ON"))
    {
        G_parameter.agps.sw = 1;
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        G_parameter.agps.sw = 0;
    }
#if 0/*2503平台使用的GPS是内置的，AGPS功能也是独立实现的*/
    else if(!strcmp(cmd->pars[1], "LPON"))
    {
        G_parameter.agps.last_position_valid = 1;
    }
    else if(!strcmp(cmd->pars[1], "LPOFF"))
    {
        G_parameter.agps.last_position_valid = 0;
    }
    else if(!strcmp(cmd->pars[1], "UPDATE2"))
    {
        track_cust_server2_login();
        sprintf(cmd->rsp_msg, "OK!");
        return;
    }
    else if(!strcmp(cmd->pars[1], "UPDATE"))
    {
        track_cust_agps_get_data_force(2);
        sprintf(cmd->rsp_msg, "OK!");
        return;
    }
    else if(!strcmp(cmd->pars[1], "MODE"))
    {
        sprintf(cmd->rsp_msg, "MODE:%d", G_parameter.agps.server_mode);
        return;
    }
    else if(!strcmp(cmd->pars[1], "MODE0"))
    {
        G_parameter.agps.server_mode = 0;
    }
    else if(!strcmp(cmd->pars[1], "MODE1"))
    {
        G_parameter.agps.server_mode = 1;
    }
    else if(!strcmp(cmd->pars[1], "STATUS"))
    {
        int l;
        l = sprintf(cmd->rsp_msg, "%s:%s\r\n", cmd->pars[0], ON_OFF(G_parameter.agps.sw));
        track_gps_hour_to_utc_view(cmd->rsp_msg + l);
        //sprintf(cmd->rsp_msg, "OK!");
        return;
    }
    else if(!strcmp(cmd->pars[1], "DELEPO"))
    {
        kal_int8 result = track_epo_delete_file();
        if(result)
        {
            sprintf(cmd->rsp_msg, "Del EPO Error %d", result);
        }
        else
        {
            sprintf(cmd->rsp_msg, "OK");
        }
        return;
    }
#endif /* 0 */
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1");
        return;
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

/******************************************************************************
 *  Function    -  cmd_ams
 *
 *  Purpose     -  AMS Server2服务器开关控制
 *
 *  Description -
 *       G_importance_parameter_data.server2.conecttype
 *             开     关
 *          =  0      10
 *          =  1      11
 * modification history
 * ----------------------------------------
 * v1.0  , 05-06-2015,  Cml  written
 * ----------------------------------------
 ******************************************************************************/
static void cmd_ams(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        if(G_importance_parameter_data.server2.conecttype >= 2)
            sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], ON_OFF(0));
        else
            sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], ON_OFF(1));
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(G_importance_parameter_data.server2.conecttype >= 10)
            G_importance_parameter_data.server2.conecttype -= 10;
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(G_importance_parameter_data.server2.conecttype < 10)
            G_importance_parameter_data.server2.conecttype += 10;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    if(Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

static void cmd_amsconn(CMD_DATA_STRUCT *cmd)
{
    S32 value;
    nvram_check_ota_struct g_otacheck = {0};
    Track_nvram_read(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], g_otacheck.resetCountMax);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 1 || value > 100)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (1 to 100)");
        return;
    }
    g_otacheck.resetCountMax = value;
    if(Track_nvram_write(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_otacheck, NVRAM_EF_CHECK_OTA_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

static void cmd_asetgmt(CMD_DATA_STRUCT *cmd)
{
    if(!track_cust_is_upload_UTC_time())
    {
        return;
    }
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s; Current Timezone(GMT):%c,%d,%d", cmd->pars[0],
                ON_OFF(G_parameter.zone.timezone_auto), G_parameter.zone.zone,
                G_parameter.zone.time, G_parameter.zone.time_min);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(!strcmp(cmd->pars[1], "ON"))
    {
        G_parameter.zone.timezone_auto = 1;
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        G_parameter.zone.timezone_auto = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
    if(G_parameter.zone.timezone_auto == 1)
    {
        nvram_gps_time_zone_struct *zone_p;
        zone_p = track_mcc_to_timezone();
        if(zone_p != NULL)
        {
            memcpy(&G_parameter.zone, zone_p, sizeof(nvram_gps_time_zone_struct));
        }
    }
}

void cmd_check(CMD_DATA_STRUCT *cmd)
{
    int n, g, i, j, x;// signal = 0;
    char tmp[1000] = {0}, PRN[80] = {0},BD_PRN[80] = {0};
    kal_bool head = 1;
    float volt = track_cust_get_battery_volt();
    nvram_GPRS_APN_struct *use_apn = track_socket_get_use_apn();
    track_gps_data_struct *gd = track_drv_get_gps_data();
    charge_measure_struct charge_measure = {0};
    track_bmt_get_ADC_result(&charge_measure);
    n = snprintf(tmp, 999, "IMEI:%s;VERSION:%s;",
                 (char *)track_drv_get_imei(0),
                 track_get_app_version());

    if(G_importance_parameter_data.server.conecttype == 0)
    {
        n += sprintf(tmp + n, "SERVER:%d.%d.%d.%d,%d;",
                     G_importance_parameter_data.server.server_ip[0], G_importance_parameter_data.server.server_ip[1],
                     G_importance_parameter_data.server.server_ip[2], G_importance_parameter_data.server.server_ip[3],
                     G_importance_parameter_data.server.server_port);
    }
    else
    {
        n += sprintf(tmp + n, "SERVER:%s,%d;",
                     track_domain_decode(G_importance_parameter_data.server.url),
                     G_importance_parameter_data.server.server_port);
        n += sprintf(tmp + n, "GET IP:%s;", track_soc_ip_from_domain());
    }

    n += sprintf(tmp + n, "APN:%s,%d;CSQ:%d;GPRS:%d;",
                 use_apn->apn, (G_importance_parameter_data.apn.custom_apn_valid ? 0 : 1),
                 track_cust_get_rssi(-1),
                 track_soc_login_status());

    g = track_cust_gps_status();

    /* 找出信号强度大于40db的卫星个数 */
    //  for(x = 0; x < MTK_GPS_SV_MAX_NUM; x++)
    //      if(gd->gpgsv.SNR[x] > 40) signal++;

    for(i = 0, j = 0; i < gd->gpgga.sat && i < MTK_GPS_SV_MAX_NUM && i < 12; i++)
    {
        for(x = 0; x < MTK_GPS_SV_MAX_NUM; x++)
        {
            if(gd->gpgsv.Satellite_ID[x] == gd->gpgsa.satellite_used[i])
            {
                if(head)
                    j += snprintf(PRN + j, 5, "%d", gd->gpgsv.SNR[x]);
                else
                    j += snprintf(PRN + j, 5, ",%d", gd->gpgsv.SNR[x]);
                head = 0;
                break;
            }
            else if(x == MTK_GPS_SV_MAX_NUM - 1)
            {
                LOGD(L_APP, L_V5, "not find:%d", gd->gpgsa.satellite_used[i]);
            }
        }
    }
#ifdef __TRACK_TYPE_GPS_BEIDOU__
	head = 1;
	for (i = 0, j = 0; i < gd->bdgga.sat && i < MTK_BEDO_SV_MAX_NUM && i < 12; i++)
	{
		for (x = 0; x < MTK_BEDO_SV_MAX_NUM; x++)
		{
			if (gd->bdgsv.Satellite_ID[x] == gd->bdgsa.satellite_used[i])
			{
				 if (head)
					j += snprintf(BD_PRN + j, 5, "%d", gd->bdgsv.SNR[x]);
				else
					j += snprintf(BD_PRN + j, 5, ",%d", gd->bdgsv.SNR[x]);
				head = 0;
	 // 		  j += snprintf(BD_PRN + j, 5, "%d", gd->bdgsv.SNR[x]);
				break;
			}
			else if (x == MTK_BEDO_SV_MAX_NUM - 1)
			{
				LOGD(L_APP, L_V5, "not find:%d", gd->bdgsa.satellite_used[i]);
			}
		}
	}
#endif /* __TRACK_TYPE_GPS_BEIDOU__ */

    if(g >= GPS_STAUS_2D)
    {
        //1 GPS已定位
        n += sprintf(tmp + n, "GPS:1,%d,%s;",
                     gd->gpgga.sat, PRN);
    }
    else if(g == GPS_STAUS_OFF)
    {
        //2 GPS未开启
        n += sprintf(tmp + n, "GPS:2;");
    }
    else
    {
        //3 GPS搜星中
        n += sprintf(tmp + n, "GPS:3,%d,%s;",
                     gd->gpgga.sat, PRN);
    }
#ifdef __TRACK_TYPE_GPS_BEIDOU__
	if (gd->gpgsa.status>= 2)
	{
		//已定位
		n += sprintf(tmp + n, "BDS:1,%d,%s;",
					 gd->bdgga.sat, BD_PRN);
	}
	else if (gd->gpgsa.status == 1)
	{
		n += sprintf(tmp + n, "BDS:3,%d,%s;",
					 gd->bdgga.sat, BD_PRN);
	}
#endif /* __TRACK_TYPE_GPS_BEIDOU__ */

    n += sprintf(tmp + n, "BAT:%.2f;", volt / 1000000);

#ifdef __EXT_VBAT_ADC__
    /* 外部电压，部分项目具备 */
    n += sprintf(tmp + n, "POWER:%0.2f;", (float)track_cust_get_ext_volt() / 1000000.0) ;
#endif /* __EXT_VBAT_ADC__ */

#if defined (__NT33__)
    if(G_parameter.gps_work.Fti.sw)
        n += sprintf(tmp + n, "TIMER:%d,%d;", G_parameter.gps_work.Fti.interval_acc_off, G_parameter.gps_work.Fti.lbs_interval);
#else
    if(G_parameter.gps_work.Fti.sw)
        n += sprintf(tmp + n, "TIMER:%d,%d;", G_parameter.gps_work.Fti.interval_acc_on, G_parameter.gps_work.Fti.interval_acc_off);
#endif

    if(G_parameter.gps_work.Fd.sw)
        n += sprintf(tmp + n, "DISTANCE:%d;", G_parameter.gps_work.Fd.distance);

    /* SOS */
    if(3 == TRACK_DEFINE_SOS_COUNT)
    {
        n += sprintf(tmp + n, "SOS NUM:%s,%s,%s;", G_parameter.sos_num[0], G_parameter.sos_num[1], G_parameter.sos_num[2]);
    }
    if(4 == TRACK_DEFINE_SOS_COUNT)
    {
        n += sprintf(tmp + n, "SOS NUM:%s,%s,%s,%s;", G_parameter.sos_num[0], G_parameter.sos_num[1], G_parameter.sos_num[2], G_parameter.sos_num[3]);
    }

#if defined (__NT33__)

#else
    /* 中心号码 */
    n += sprintf(tmp + n, "CENTER:%s;", G_parameter.centerNumber);
#endif /* __NT33__ */

    /* 亲情号码 */
    //n += sprintf(tmp+n, "FN NUM:");

    /* iccid */
    n += sprintf(tmp + n, "ICCID:%s;", (char *)OTA_ell_get_iccid());

    /*imsi*/
    n += sprintf(tmp + n, "IMSI:%s;", (char *)track_drv_get_imsi(0));

    /* eurl */
    n += sprintf(tmp + n, "EURL:%s;", G_parameter.url);

#if defined(__NT33__)||defined(__NF2318__)
    n += sprintf(tmp + n, "BAT TEMP:%d;", (kal_uint32)charge_measure.bmt_vTemp / 1000);
	n += sprintf(tmp + n, "SN:%s;",(char*)G_importance_parameter_data.SequenceNumber);
#endif

    if(n > 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            if(n > 320)
            {
                track_cust_sms_send(cmd->return_sms.num_type, cmd->return_sms.ph_num, KAL_TRUE, tmp, 320);
                track_cust_sms_send(cmd->return_sms.num_type, cmd->return_sms.ph_num, KAL_TRUE, tmp + 320, n - 320);

            }
            else
                track_cust_sms_send(cmd->return_sms.num_type, cmd->return_sms.ph_num, KAL_TRUE, tmp, n);
        }
        else if(cmd->return_sms.cm_type == CM_ONLINE)
        {
            track_cust_paket_msg_upload(cmd->return_sms.stamp, KAL_TRUE, tmp, n);
        }
        else if(cmd->return_sms.cm_type == CM_ONLINE2)
        {
            track_cust_paket_FD_cmd(cmd->return_sms.stamp, KAL_TRUE, tmp, n);
        }
    }
    LOGS("%s", tmp);
    if(cmd->return_sms.cm_type == CMD_NET2)
        track_cust_net2_param(strlen(tmp), tmp);
    memset(cmd->rsp_msg, 0, 320);
}

static void cmd_status(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 1 && !strcmp(cmd->pars[1], "BD"))
    {
        track_gps_data_struct *gd = track_drv_get_gps_data();
        char GPS_status[40] = {0};
        char GPS_PRN[80] = {0};
        char PRN[5] = {0};
        kal_uint8 tmp, i, j, x, sat = 0;
        kal_bool head = KAL_TRUE;
//BD
        tmp = track_cust_gps_status();
        if(tmp == GPS_STAUS_ON)
            snprintf(GPS_status, 40, "ON, Uart no data");
        else if(tmp == GPS_STAUS_SCAN)
            snprintf(GPS_status, 40, "Searching satellite");
        else if(tmp >= GPS_STAUS_2D)
            snprintf(GPS_status, 40, "Successful positioning");
        else
            snprintf(GPS_status, 40, "OFF");

        if(tmp != 0)
        {
            for(i = 0, j = 80; i < gd->bdgga.sat; i++)
            {
                for(x = 0; x < MTK_GPS_SV_MAX_NUM; x++)
                {
                    if(gd->bdgsv.Satellite_ID[x] == gd->bdgsa.satellite_used[i])
                    {
                        if(head)
                            snprintf(PRN, 5, "%d", gd->bdgsv.SNR[x]);
                        else
                            snprintf(PRN, 5, ",%d", gd->bdgsv.SNR[x]);
                        j -= 5;
                        strncat(GPS_PRN, PRN, j);
                        head = KAL_FALSE;
                        break;
                    }
                    else if(x == MTK_GPS_SV_MAX_NUM - 1)
                    {
                        LOGD(L_APP, L_V5, "not find:%d", gd->bdgsa.satellite_used[i]);
                    }
                }
            }
            sat = gd->bdgga.sat;
        }

        if(tmp != GPS_STAUS_OFF)
        {
            snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, "BD:%s, SVS Used in fix:%d(%d), BD Signal Level:%s;",
                     GPS_status, sat, gd->bdgsv.Satellites_In_View, GPS_PRN);
        }
        else
        {
            snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, "BD:%s", GPS_status);
        }

    }
    else if(cmd->part == 0)
    {
        kal_uint8 tmp, i, j, x, sat = 0;
        track_gps_data_struct *gd = track_drv_get_gps_data();
#if defined (__NT33__)
        char Battery[128] = {0};
        char Battery_ext[60] = {0};
#else
        char Battery[60] = {0};
#endif
        char GPRS[40] = {0};
        char GSMSignalLevel[40] = {0};
        char GPS_status[40] = {0};
        char GPS_PRN[100] = {0};
        char GPS_Use[30] = {0};
        char PRN[5] = {0};
        kal_bool head = KAL_TRUE;
        char ACC[10] = {0};
        char Defense[16] = {0};
        float volt = 0;
        char power_saving_mode[20] = {0};

        //电池等级
        volt = track_cust_get_battery_volt();

#if defined (__SAME_GT02__)  //最简版
        if(volt == 0)
        {
            sprintf(Battery, "Battery:(Checking);");
        }
        else
        {
            volt = volt / 1000000;
            tmp = track_cust_get_battery_level();
            if(tmp > 2)
            {
                sprintf(Battery, "Battery:NORMAL;");
            }
            else if(tmp == 2)
            {
                sprintf(Battery, "Battery:LOW;");
            }
            else
            {
                sprintf(Battery, "Battery:Battery too low! Warning;");
            }
        }
#elif defined (__NT33__)    //带电压、温度、充电状态
        if(volt == 0)
        {
            sprintf(Battery, "; Battery:(Checking)");
        }
        else
        {
            kal_int8 bat_temperature;
            kal_uint8 chargerStatus;
            charge_measure_struct charge_measure = {0};

            volt = volt / 1000000;
            tmp = track_cust_get_battery_level();

            chargerStatus = track_cust_status_charger();
            track_bmt_get_ADC_result(&charge_measure);
            bat_temperature = (kal_int8)((kal_uint16)charge_measure.bmt_vTemp / 1000);

            if(chargerStatus == 0)
            {
                sprintf(Battery_ext, "charge out;");
            }
            else
            {
                sprintf(Battery_ext, "charge in,Temp:%d'C;", bat_temperature);
            }


            if(tmp > 2)
            {
                sprintf(Battery, "Battery:%.2fV,NORMAL;", volt);
            }
            else if(tmp == 2)
            {
                sprintf(Battery, "Battery:%.2fV,LOW;", volt);
            }
            else
            {
                sprintf(Battery, "Battery:%.2fV,Battery too low! Warning;", volt);
            }
            strcat(Battery, Battery_ext);

        }

#else   //带电压
        if(volt == 0)
        {
            sprintf(Battery, "; Battery:(Checking)");
        }
        else
        {
            volt = volt / 1000000;
            tmp = track_cust_get_battery_level();
            if(tmp > 2)
            {
                sprintf(Battery, "Battery:%.2fV,NORMAL;", volt);
            }
            else if(tmp == 2)
            {
                sprintf(Battery, "Battery:%.2fV,LOW;", volt);
            }
            else
            {
                sprintf(Battery, "Battery:%.2fV,Battery too low! Warning;", volt);
            }
        }

#endif

        //GPRS连接状态
        if(track_soc_login_status())
            snprintf(GPRS, 40, "GPRS:Link Up");
        else
            snprintf(GPRS, 40, "GPRS:Link Down");

        //GSM信号
        switch(track_cust_get_rssi_level())
        {
#if defined(__NF2318__)
			case -1:
				snprintf(GSMSignalLevel, 35, "GSM Signal Level:Invaild;");
				break;
			case 0:
				snprintf(GSMSignalLevel, 35, "GSM Signal Level:No Singal;");
				break;
			case 1:
			case 2:
			case 3:
				snprintf(GSMSignalLevel, 35, "GSM Signal Level:Weak;");
				break;
			case 4:
				snprintf(GSMSignalLevel, 35, "GSM Signal Level:Low;");
				break;
			case 5:
			case 6:
				snprintf(GSMSignalLevel, 35, "GSM Signal Level:Good;");
				break;
			case 7:
			case 8:
			case 9:
				snprintf(GSMSignalLevel, 35, "GSM Signal Level:Strong;");
				break;
			default:
				snprintf(GSMSignalLevel, 35, "GSM Signal Level:Invaild;");
				break;
#else
            case -1:
                snprintf(GSMSignalLevel, 35, "GSM Signal Level:Invaild;");
                break;
            case 0:
                snprintf(GSMSignalLevel, 35, "GSM Signal Level:No Singal;");
                break;
            case 1:
                snprintf(GSMSignalLevel, 35, "GSM Signal Level:Weak;");
                break;
            case 2:
                snprintf(GSMSignalLevel, 35, "GSM Signal Level:Low;");
                break;
            case 3:
                snprintf(GSMSignalLevel, 35, "GSM Signal Level:Good;");
                break;
            case 4:
                snprintf(GSMSignalLevel, 35, "GSM Signal Level:Strong;");
                break;
            default:
                snprintf(GSMSignalLevel, 35, "GSM Signal Level:Invaild;");
                break;
#endif
        }

        //GPS
        tmp = track_cust_gps_status();
        if(tmp == GPS_STAUS_ON)
            snprintf(GPS_status, 40, "GPS:ON, Uart no data;");
        else if(tmp == GPS_STAUS_SCAN)
            snprintf(GPS_status, 40, "GPS:Searching satellite;");
        else if(tmp >= GPS_STAUS_2D)
            snprintf(GPS_status, 40, "GPS:Successful positioning;");
        else
            snprintf(GPS_status, 40, "GPS:OFF;");

        if(tmp != 0)
        {
            snprintf(GPS_PRN, 40, ", GPS Signal Level:");
            for(i = 0, j = 80; i < gd->gpgga.sat && i < MTK_GPS_SV_MAX_NUM; i++)
            {
                for(x = 0; x < MTK_GPS_SV_MAX_NUM; x++)
                {
                    if(gd->gpgsv.Satellite_ID[x] == gd->gpgsa.satellite_used[i])
                    {
                        if(head)
                            snprintf(PRN, 5, "%d", gd->gpgsv.SNR[x]);
                        else
                            snprintf(PRN, 5, ",%d", gd->gpgsv.SNR[x]);
                        j -= 5;
                        strncat(GPS_PRN, PRN, j);
                        head = KAL_FALSE;
                        break;
                    }
                    else if(x == MTK_GPS_SV_MAX_NUM - 1)
                    {
                        LOGD(L_APP, L_V5, "not find:%d", gd->gpgsa.satellite_used[i]);
                    }
                }
            }
            sat = gd->gpgga.sat;
            LOGD(L_APP, L_V4, "sat:%d, j:%d, %d(%s)", gd->bdgga.sat, j, strlen(GPS_PRN), GPS_PRN);
            for(i = 0; i < gd->bdgga.sat && i < MTK_GPS_SV_MAX_NUM; i++)
            {
                for(x = 0; x < MTK_GPS_SV_MAX_NUM; x++)
                {
                    if(gd->bdgsv.Satellite_ID[x] != 0 && gd->bdgsv.Satellite_ID[x] == gd->bdgsa.satellite_used[i])
                    {
                        LOGD(L_APP, L_V4, "Satellite_ID:%d, satellite_used:%d", gd->bdgsv.Satellite_ID[x], gd->bdgsa.satellite_used[i]);
                        if(head)
                            snprintf(PRN, 5, "%d", gd->bdgsv.SNR[x]);
                        else
                            snprintf(PRN, 5, ",%d", gd->bdgsv.SNR[x]);
                        j -= 5;
                        strncat(GPS_PRN, PRN, j);
                        head = KAL_FALSE;
                        break;
                    }
                    else if(x == MTK_GPS_SV_MAX_NUM - 1)
                    {
                        LOGD(L_APP, L_V5, "not find:%d;", gd->bdgsa.satellite_used[i]);
                    }
                }
            }
            sat += gd->bdgga.sat;
            sprintf(GPS_Use, "SVS Used in fix:%d(%d);", sat, gd->gpgsv.Satellites_In_View + gd->bdgsv.Satellites_In_View);
        }

#if !defined(__NO_ACC__)
        //ACC
        if(track_cust_status_acc() == 1)
            snprintf(ACC, 10, "ACC:ON;");
        else
            snprintf(ACC, 10, "ACC:OFF;");
#endif /* __NO_ACC__ */

        //Defense
#if !defined(__NO_DEFENSE__)//无设防只需添加此功能宏
        if(track_cust_status_defences() == 2)
            snprintf(Defense, 15, "Defense:ON;");
        else
            snprintf(Defense, 15, "Defense:OFF;");
#endif /* __NO_DEFENSE__ */

        if(track_cust_gps_status() == GPS_STAUS_OFF)
        {
            snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, "%s %s %s %s %s %s %s",
                     Battery, GPRS, GSMSignalLevel, GPS_status, ACC, Defense, power_saving_mode);
        }
        else
        {
            snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, "%s %s %s %s %s %s %s %s %s",
                     Battery, GPRS, GSMSignalLevel, GPS_status, GPS_Use, GPS_PRN, ACC, Defense, power_saving_mode);
        }
        //个别空字符串前后空白，导致结果难看 chengj
    }
}

static void cmd_param(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        //  IMEI:353419032348877;           --- 设备IMEI号
        //  TIMER:10,10;            --- GPS数据上传间隔为10秒。GPRS上传时间间隔（GPRS Interval）
        //  Distance:500;                   --- 定距上传，间隔距离，单位米
        //  SENDS:5;                        --- ACC OFF情况下震动触发GPS工作的时间，设置范围：1-300分钟,默认：300分钟。
        //  SOS:15942703401;                --- SOS号码，最大可设置3个SOS号码，用于报警及监听。
        //  Center Number:15942703401;      --- 服务中心号码，用于断油电和恢复油电，仅能设置一个服务中心号码。
        //  Sensorset:10,3,1,180;           --- 在10秒内检测3次震动; 震动报警延时180秒
        //  Defense time:10;                --- 设防延时为10分钟。
        //  TimeZone:E,8,0;                 --- 时区为东八区。时区（TimeZone）
        char tmp[50] = {0}, tmp2[50] = {0}, num_tmp[TRACK_DEFINE_PHONE_NUMBER_LEN_MAX * TRACK_DEFINE_SOS_COUNT + 3] = {0};
        char center[40] = {0}, defense[40] = {0};
        int ret, j, num_len = 0;
        char *p = num_tmp;
        if(G_parameter.gps_work.Fti.sw == 1)
        {
#if defined(__GPS_INTERMITTENT_START__)

#if defined(__GT370__)|| defined (__GT380__)
            snprintf(tmp, 50, "TIMER:%d; ", G_parameter.gps_work.Fti.lbs_interval);
#else
            snprintf(tmp, 50, "TIMER:%d,%d,%d; ", G_parameter.gps_work.Fti.lbs_interval, G_parameter.gps_work.Fti.interval_acc_on, G_parameter.gps_work.Fti.mode1_gps_time);
#endif
#elif defined(__NT33__)
            snprintf(tmp, 50, "TIMER:%d,%d; ", G_parameter.gps_work.Fti.interval_acc_off, G_parameter.gps_work.Fti.lbs_interval);
#elif defined(__NO_ACC__)
            snprintf(tmp, 50, "TIMER:%d,%d; ", G_parameter.gps_work.Fti.lbs_interval, G_parameter.gps_work.Fti.interval_acc_off);
#else
            snprintf(tmp, 50, "TIMER:%d,%d; ", G_parameter.gps_work.Fti.interval_acc_on, G_parameter.gps_work.Fti.interval_acc_off);
#endif /* __GPS_INTERMITTENT_START__ */
        }

        if(G_parameter.gps_work.Fd.sw == 1)
        {
            snprintf(tmp2, 50, "Distance:%d; ", G_parameter.gps_work.Fd.distance);
        }

        if(g_GT03D == KAL_FALSE)
        {
#if defined(__GERMANY__)
            snprintf(center, 40, "Center Nummer:%s; ", G_parameter.centerNumber);
#else
            snprintf(center, 40, "Center Number:%s; ", G_parameter.centerNumber);
#endif/*__GERMANY__*/

            snprintf(defense, 40, "Defense time:%d; ", G_parameter.defense_time / 60);
        }

        for(j = 0; j < TRACK_DEFINE_SOS_COUNT; j++)
        {
            if(j == 0)
            {
                num_len = TRACK_DEFINE_PHONE_NUMBER_LEN_MAX * TRACK_DEFINE_SOS_COUNT + 3;
                ret = snprintf(p, num_len, "%s", G_parameter.sos_num[j]);
            }
            else
            {
                ret = snprintf(p, num_len, ",%s", G_parameter.sos_num[j]);
            }
            p += ret;
        }

        snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, "IMEI:%s; %s%sSENDS:%d; SOS:%s; %sSensorset:%d,%d,%d,%d; %sTimeZone:%c,%d,%d;",
                 track_drv_get_imei(0), tmp, tmp2,
                 G_parameter.sensor_gps_work, num_tmp,
                 center,
                 G_parameter.vibrates_alarm.detection_time, G_parameter.gps_work.vibrates.detection_count, G_parameter.vibrates_alarm.detection_count, G_parameter.vibrates_alarm.sampling_interval,
                 defense, G_parameter.zone.zone, G_parameter.zone.time, G_parameter.zone.time_min);

    }
}

static void cmd_scxsz(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        /*
        网络名,网络ID,运营商代理IP,用户名,密码;
        acc on GPS上传时间间隔,acc off GPS上传时间间隔 / 定距上传的最短距离;
        检到一次Sensor触发开启GPS工作的时长;
        时区,半时区;
        模式（1 域名，0 IP）,后台域名或IP,端口号,协议（0 TCP，1 UPD）;
        SOS号码1,SOS号码2,SOS号码3;
        中心号码;
        震动传感器检测时间;
        设防时间;
        语言（1中文，0英文）;*/
        char server[100] = {0};
        char tmp[50] = {0}, tmp2[50] = {0}, num_tmp[TRACK_DEFINE_PHONE_NUMBER_LEN_MAX * TRACK_DEFINE_SOS_COUNT + 3] = {0};
        int ret, j, num_len = 0;
        char *p = num_tmp;
        nvram_GPRS_APN_struct *use_apn = track_socket_get_use_apn();
        if(G_importance_parameter_data.server.conecttype == 0)
            snprintf(server, 100, "%d.%d.%d.%d", G_importance_parameter_data.server.server_ip[0], G_importance_parameter_data.server.server_ip[1], G_importance_parameter_data.server.server_ip[2], G_importance_parameter_data.server.server_ip[3]);
        else snprintf(server, 100, "%s", track_domain_decode(G_importance_parameter_data.server.url));

        for(j = 0; j < TRACK_DEFINE_SOS_COUNT; j++)
        {
            if(j == 0)
            {
                num_len = TRACK_DEFINE_PHONE_NUMBER_LEN_MAX * TRACK_DEFINE_SOS_COUNT + 3;
                ret = snprintf(p, num_len, "%s", G_parameter.sos_num[j]);
            }
            else
            {
                ret = snprintf(p, num_len, ",%s", G_parameter.sos_num[j]);
            }
            p += ret;
        }
        if(G_parameter.gps_work.Fti.sw == 1)
        {
            snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX,
                     "%s,%s,%s;%d,%d;%d;%c%d,%d;%d,%s,%d,%d;%s;%s;%d;%d;%d;",
                     use_apn->apn, use_apn->username, use_apn->password,
                     G_parameter.gps_work.Fti.interval_acc_on, G_parameter.gps_work.Fti.interval_acc_off,
                     G_parameter.sensor_gps_work,
                     G_parameter.zone.zone, G_parameter.zone.time, G_parameter.zone.time_min,
                     G_importance_parameter_data.server.conecttype, server, G_importance_parameter_data.server.server_port, G_importance_parameter_data.server.soc_type,
                     num_tmp,
                     G_parameter.centerNumber,
                     G_parameter.vibrates_alarm.detection_time,
                     G_parameter.defense_time / 60,
                     G_parameter.lang);
        }
        else
        {
            snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX,
                     "%s,%s,%s;%d;%d;%c%d,%d;%d,%s,%d,%d;%s;%s;%d;%d;%d;",
                     use_apn->apn, use_apn->username, use_apn->password,
                     G_parameter.gps_work.Fd.distance,
                     G_parameter.sensor_gps_work,
                     G_parameter.zone.zone, G_parameter.zone.time, G_parameter.zone.time_min,
                     G_importance_parameter_data.server.conecttype, server, G_importance_parameter_data.server.server_port, G_importance_parameter_data.server.soc_type,
                     num_tmp,
                     G_parameter.centerNumber,
                     G_parameter.vibrates_alarm.detection_time,
                     G_parameter.defense_time,
                     G_parameter.lang);
        }
    }
}

static void cmd_gprsset(CMD_DATA_STRUCT *cmd)
{
    char GPRS[5] = {0};
    char server[99] = {0};
    nvram_GPRS_APN_struct *use_apn = track_socket_get_use_apn();
    //GPRS连接状态
    if(G_parameter.gprson)
        snprintf(GPRS, 20, "ON");
    else
        snprintf(GPRS, 20, "OFF");
#if defined (__SAME_GT02__)
    if(G_importance_parameter_data.dserver.server_type && track_get_server_ip_status() == 0)
    {
        if(G_importance_parameter_data.dserver.conecttype == 0)
        {
            //ip
            snprintf(server, 20, "%d.%d.%d.%d", G_importance_parameter_data.dserver.server_ip[0], G_importance_parameter_data.dserver.server_ip[1], G_importance_parameter_data.dserver.server_ip[2], G_importance_parameter_data.dserver.server_ip[3]);
        }
        else
        {
            //Domain name
            snprintf(server, 98, "%s", track_domain_decode(G_importance_parameter_data.dserver.url));
        }

        snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, "GPRS:%s; Currently use APN:%s,%s,%s; DServer:%d,%s,%d,%d; URL:%s;",
                 GPRS,
                 use_apn->apn,
                 use_apn->username,
                 use_apn->password,
                 G_importance_parameter_data.dserver.conecttype,
                 server,
                 G_importance_parameter_data.dserver.server_port,
                 G_importance_parameter_data.dserver.soc_type,
                 G_parameter.url);
    }
    else
    {
        if(G_importance_parameter_data.server.conecttype == 0)
        {
            //ip
            snprintf(server, 20, "%d.%d.%d.%d", G_importance_parameter_data.server.server_ip[0], G_importance_parameter_data.server.server_ip[1], G_importance_parameter_data.server.server_ip[2], G_importance_parameter_data.server.server_ip[3]);
        }
        else
        {
            //Domain name
            snprintf(server, 98, "%s", track_domain_decode(G_importance_parameter_data.server.url));
        }

        snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, "GPRS:%s; Currently use APN:%s,%s,%s; Server:%d,%s,%d,%d; URL:%s;",
                 GPRS,
                 use_apn->apn,
                 use_apn->username,
                 use_apn->password,
                 G_importance_parameter_data.server.conecttype,
                 server,
                 G_importance_parameter_data.server.server_port,
                 G_importance_parameter_data.server.soc_type,
                 G_parameter.url);
    }
#else
    if(G_importance_parameter_data.server.conecttype == 0)
    {
        //ip
        snprintf(server, 20, "%d.%d.%d.%d", G_importance_parameter_data.server.server_ip[0], G_importance_parameter_data.server.server_ip[1], G_importance_parameter_data.server.server_ip[2], G_importance_parameter_data.server.server_ip[3]);
    }
    else
    {
        //Domain name
        snprintf(server, 98, "%s", track_domain_decode(G_importance_parameter_data.server.url));
    }

#if defined(__GERMANY__)
    snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, "GPRS:%s; Eingestellter APN:%s,%s,%s; Server:%d,%s,%d,%d; URL:%s;",
             GPRS,
             use_apn->apn,
             use_apn->username,
             use_apn->password,
             G_importance_parameter_data.server.conecttype,
             server,
             G_importance_parameter_data.server.server_port,
             G_importance_parameter_data.server.soc_type,
             G_parameter.url);

#else
    snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, "GPRS:%s; Currently use APN:%s,%s,%s; Server:%d,%s,%d,%d; URL:%s;",
             GPRS,
             use_apn->apn,
             use_apn->username,
             use_apn->password,
             G_importance_parameter_data.server.conecttype,
             server,
             G_importance_parameter_data.server.server_port,
             G_importance_parameter_data.server.soc_type,
             G_parameter.url);
#endif/*__GERMANY__*/

#endif
}

/******************************************************************************
 *  Function    -  cmd_level
 *
 *  Purpose     -  Sensor灵敏度等级设置指令
 *
 *  Description -  数值越大越不灵敏
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 27-09-2014,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_level(CMD_DATA_STRUCT *cmd)
{
    int value;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.vibrates_alarm.sensitivity_level);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 1 || value > 5)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (1-5)");
        return;
    }
    G_parameter.vibrates_alarm.sensitivity_level = value;
    track_cust_sensor_init();
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

/******************************************************************************
 *  Function    -  cmd_sos
 *
 *  Purpose     -  SOS设置
 *
 *  Description -
        SOS,<A>,<号码 1>[,号码 2][,号码 3]#
            添加SOS号码
        SOS,<D>,<号码序号 1>[,号码序号 2][,号码序号 3]#
            根据序号，删除对应的SOS号码
        SOS,<D>,<电话号码>#
            根据号码，全匹配，删除对应的SOS号码
        SOS#
            查询设置的SOS号码
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * v1.1  , 11-10-2013,  WangQi modify TRACK_DEFINE_SOS_COUNT
 * ----------------------------------------
*******************************************************************************/
#if !defined(__NF2318__)
static void cmd_sos(CMD_DATA_STRUCT *cmd)
{
    char num[TRACK_DEFINE_SOS_COUNT][TRACK_DEFINE_PHONE_NUMBER_LEN_MAX] = {0};
    LOGD(L_APP, L_V5, "");
    memcpy(num, G_parameter.sos_num, TRACK_DEFINE_SOS_COUNT * TRACK_DEFINE_PHONE_NUMBER_LEN_MAX);
    if(cmd->part == 0)
    {
        if(4 == TRACK_DEFINE_SOS_COUNT)
        {
            sprintf(cmd->rsp_msg, "SOS1:%s SOS2:%s SOS3:%s SOS4:%s", num[0], num[1], num[2], num[3]);
        }
        else
        {
            sprintf(cmd->rsp_msg, "SOS1:%s SOS2:%s SOS3:%s", num[0], num[1], num[2]);
        }
        return;
    }
    else if(cmd->part == 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(cmd->supercmd != 1 && cmd->return_sms.cm_type == CM_SMS && G_parameter.Permission.Permit && track_cust_sos_or_center_check(3, cmd->return_sms.ph_num) != 9)
    {
#if defined(__GERMANY__)
        sprintf(cmd->rsp_msg, "Fehler! Nur die SOS- und Center-Nr.kann Befehl senden.");

#else
        sprintf(cmd->rsp_msg, "Error! Only center phone number and SOS phone numbers are allowed to set.");
#endif/*__GERMANY__*/
        return;
    }
    if(!strcmp(cmd->pars[1], "A"))
    {
        int len, i, add = 0, count = 0;
        if(cmd->part > (TRACK_DEFINE_SOS_COUNT + 1))
        {
#if defined (__GERMANY__)
            sprintf(cmd->rsp_msg, "Fehler: Max. %d Nummern eingeben!", TRACK_DEFINE_SOS_COUNT);
#else
            sprintf(cmd->rsp_msg, "Error: At most once to add %d numbers!", TRACK_DEFINE_SOS_COUNT);
#endif
            return;
        }
        for(i = 2; i <= cmd->part; i++)
        {
            len = strlen(cmd->pars[i]);
            if(len > 0)
            {
                if(track_fun_check_str_is_number(1, cmd->pars[i]) == 0)
                {
                    sprintf(cmd->rsp_msg, "Error: Number contains non-numeric characters!");
                    return;
                }
                if(len >= TRACK_DEFINE_PHONE_NUMBER_LEN_MAX)
                {
                    sprintf(cmd->rsp_msg, "Error: Number length exceeds 20 characters!");
                    return;
                }
                else if(len < 3)
                {
#if defined (__GERMANY__)
                    sprintf(cmd->rsp_msg, "Fehler: Mindestens 3 Zeichen eingeben!");
#else
                    sprintf(cmd->rsp_msg, "Error: Number length must exceeds 3 characters!");
#endif
                    return;
                }
                strcpy(num[i - 2], cmd->pars[i]);
                add++;
            }
        }
        if(add || cmd->return_sms.cm_type == CM_ONLINE)
        {
            memcpy(G_parameter.sos_num, num, TRACK_DEFINE_SOS_COUNT * TRACK_DEFINE_PHONE_NUMBER_LEN_MAX);
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
            if(4 == TRACK_DEFINE_SOS_COUNT)
            {
                sprintf(cmd->rsp_msg, "OK! \r\nSOS1:%s SOS2:%s SOS3:%s SOS4:%s", G_parameter.sos_num[0], G_parameter.sos_num[1], G_parameter.sos_num[2], G_parameter.sos_num[3]);
            }
            else
            {
                sprintf(cmd->rsp_msg, "OK! \r\nSOS1:%s SOS2:%s SOS3:%s", G_parameter.sos_num[0], G_parameter.sos_num[1], G_parameter.sos_num[2]);
            }
        }
#if defined(__PARAM_CHANGE_UPDATE_SERVER__)
        track_cust_paket_9404_handle();
#endif
    }
    else if(!strcmp(cmd->pars[1], "D"))
    {
        if(cmd->part > (TRACK_DEFINE_SOS_COUNT + 1))
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        if(strlen(cmd->pars[2]) == 1)
        {
            // 序号
            int no, j;
            for(j = 2; j <= cmd->part; j++)
            {
                if(strlen(cmd->pars[j]) > 0)
                {
                    no = track_fun_atoi(cmd->pars[j]);
                    if(no < 1 || no > TRACK_DEFINE_SOS_COUNT)
                    {
                        sprintf(cmd->rsp_msg, "Error: serial number can only from 1 to %d in!", TRACK_DEFINE_SOS_COUNT);
                        return;
                    }
                    if(strlen(num[no - 1]) == 0)
                    {
                        sprintf(cmd->rsp_msg, "Error: The number %d does not exist in the sos number!", no);
                        return;
                    }
                    memset(num[no - 1], 0, TRACK_DEFINE_PHONE_NUMBER_LEN_MAX);
                }
            }
            memcpy(G_parameter.sos_num, num, TRACK_DEFINE_SOS_COUNT * TRACK_DEFINE_PHONE_NUMBER_LEN_MAX);
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
            if(4 == TRACK_DEFINE_SOS_COUNT)
            {
                sprintf(cmd->rsp_msg, "OK! \r\nSOS1:%s SOS2:%s SOS3:%s SOS4:%s", G_parameter.sos_num[0], G_parameter.sos_num[1], G_parameter.sos_num[2], G_parameter.sos_num[3]);
            }
            else
            {
                sprintf(cmd->rsp_msg, "OK! \r\nSOS1:%s SOS2:%s SOS3:%s", G_parameter.sos_num[0], G_parameter.sos_num[1], G_parameter.sos_num[2]);
            }
#if defined(__PARAM_CHANGE_UPDATE_SERVER__)
            track_cust_paket_9404_handle();
#endif
        }
        else
        {
            // 号码
            int i;
            if(track_fun_check_str_is_number(1, cmd->pars[2]) == 0)
            {
                sprintf(cmd->rsp_msg, "Error: Number contains non-numeric characters!");
                return;
            }
            if(strlen(cmd->pars[2]) >= TRACK_DEFINE_PHONE_NUMBER_LEN_MAX)
            {
                sprintf(cmd->rsp_msg, "Error: Number length exceeds 20 characters!");
                return;
            }
            if(cmd->part > 2)
            {
                sprintf(cmd->rsp_msg, "only remove one number by once!");
                return;
            }
            for(i = 0; i < TRACK_DEFINE_SOS_COUNT; i++)
            {
                if(!strcmp(cmd->pars[2], G_parameter.sos_num[i]) && strlen(G_parameter.sos_num[i]) > 0)
                {
                    memset(G_parameter.sos_num[i], 0, TRACK_DEFINE_PHONE_NUMBER_LEN_MAX);
                    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
                    if(4 == TRACK_DEFINE_SOS_COUNT)
                    {
                        sprintf(cmd->rsp_msg, "OK! \r\nSOS1:%s SOS2:%s SOS3:%s SOS4:%s", G_parameter.sos_num[0], G_parameter.sos_num[1], G_parameter.sos_num[2], G_parameter.sos_num[3]);
                    }
                    else
                    {
                        sprintf(cmd->rsp_msg, "OK! \r\nSOS1:%s SOS2:%s SOS3:%s", G_parameter.sos_num[0], G_parameter.sos_num[1], G_parameter.sos_num[2]);
                    }
                }
            }
#if defined(__PARAM_CHANGE_UPDATE_SERVER__)
            track_cust_paket_9404_handle();
#endif
        }
    }
    else if(track_cust_password_sw())
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 2 is not a valid!");
        return;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 is not a valid!");
        return;
    }
}
static void cmd_almrep(CMD_DATA_STRUCT *cmd)
{
    int len, i, add = 0, count = 0, value = 0;
    kal_bool almrep[TRACK_DEFINE_SOS_COUNT] = {0};

    LOGD(L_APP, L_V5, "");
    memcpy(almrep, G_phone_number.almrep, TRACK_DEFINE_SOS_COUNT);

    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "SOS1:%d,SOS2:%d,SOS3:%d", almrep[0], almrep[1], almrep[2]);
        return;
    }
    else if(cmd->part > TRACK_DEFINE_SOS_COUNT)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    for(i = 1; i <= cmd->part; i++)
    {
        len = strlen(cmd->pars[i]);
        if(len > 0)
        {
            value = track_fun_atoi(cmd->pars[i]);

            if(0 != value && 1 != value)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter %d (0/1)", i);
                return;
            }
            almrep[i - 1] = value;
            LOGD(L_APP, L_V5, "value:%d,arlmrep[%d]:%d", value, i, almrep[i - 1]);
            add++;
        }
    }
    if(add)
    {
        memcpy(G_phone_number.almrep, almrep, TRACK_DEFINE_SOS_COUNT);
        Track_nvram_write(NVRAM_EF_PHONE_NUMBER_LID, 1, (void *)&G_phone_number, NVRAM_EF_PHONE_NUMBER_SIZE);
        sprintf(cmd->rsp_msg, "OK! \r\SOS1:%d,SOS2:%d,SOS3:%d", G_phone_number.almrep[0], G_phone_number.almrep[1], G_phone_number.almrep[2]);
    }
    else
    {
        sprintf(cmd->rsp_msg, "SOS1:%d,SOS2:%d,SOS3:%d", almrep[0], almrep[1], almrep[2]);
    }
}

static void cmd_see_sos(CMD_DATA_STRUCT *cmd)
{
    char num[TRACK_DEFINE_SOS_COUNT][TRACK_DEFINE_PHONE_NUMBER_LEN_MAX] = {0};
    LOGD(L_APP, L_V5, "type:%d", cmd->return_sms.cm_type);

    if(cmd->return_sms.cm_type == CM_ONLINE)
    {
        memcpy(num, G_parameter.sos_num, TRACK_DEFINE_SOS_COUNT * TRACK_DEFINE_PHONE_NUMBER_LEN_MAX);

        cmd->rsp_length = sprintf(cmd->rsp_msg, "SEESOS:%s,%s,%s,%s#", num[0], num[1], num[2], num[3]);
    }
}
#endif
/******************************************************************************
 *  Function    -  cmd_sosalm
 *
 *  Purpose     -  SOS 开/关 模式 设置
 *
 *  Description -  SOS 报警指令：SOSALM,ON[,M]#
 *
 *                 ON=开启 SOS 报警；OFF=关闭 SOS 报警；（默认为开启）
 *
 *                 M=报警上报方式（默认为 1）
 *                     M=0 仅GPRS;
 *                     M=1 SMS+GPRS;
 *                     M=2 GPRS+SMS+电话；
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 25-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_sosalm(CMD_DATA_STRUCT *cmd)
{
    nvram_sos_alarm_struct alarm = {0};
    LOGD(L_APP, L_V5, "");
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s mode:%d(0=only GPRS,1=GPRS+SMS,2=GPRS+SMS+Call,3=GPRS+Call)", cmd->pars[0],
                ON_OFF(G_parameter.sos_alarm.sw), G_parameter.sos_alarm.alarm_type);
        return;
    }
    memcpy(&alarm, &G_parameter.sos_alarm, sizeof(nvram_sos_alarm_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part != 1 && cmd->part != 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 1;
        if(cmd->part == 2)
        {
            if(!strcmp(cmd->pars[2], "0"))
            {
                alarm.alarm_type = 0;
            }
            else if(!strcmp(cmd->pars[2], "1"))
            {
                alarm.alarm_type = 1;
            }
            else if(!strcmp(cmd->pars[2], "2"))
            {
                alarm.alarm_type = 2;
            }
            else if(!strcmp(cmd->pars[2], "3"))
            {
                alarm.alarm_type = 3;
            }
            else
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1/2/3)");
                return;
            }
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.sos_alarm, &alarm, sizeof(nvram_sos_alarm_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

/******************************************************************************
 *  Function    -  cmd_defense
 *
 *  Purpose     -  延时设防设置
 *
 *  Description -
        DEFENSE,<A>#
            A:1～60分钟，设防延时时间，默认值为：10分钟
        DEFENSE#
            查询已设置的参数
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
/*设置时间单位为秒，保存单位为秒       --    chengjun  2017-10-09*/
static void cmd_defense2(CMD_DATA_STRUCT *cmd)
{
    int value;
    LOGD(L_APP, L_V5, "");
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.defense_time);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 1 || value > 3600)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (1 to 3600)");
        return;
    }
    if(G_parameter.defense_time != value)
    {
        G_parameter.defense_time = value;
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    }

    if(G_realtime_data.defense_mode == 0)
    {
        track_cust_status_defences_update_time();
    }
    sprintf(cmd->rsp_msg, "OK!");
}


/*设置时间单位为分钟，保存单位为秒       --    chengjun  2017-10-09*/
static void cmd_defense(CMD_DATA_STRUCT *cmd)
{
    int value;
    int temp;
    LOGD(L_APP, L_V5, "");
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%dmin", cmd->pars[0], G_parameter.defense_time / 60);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 1 || value > 60)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (1 to 60)");
        return;
    }
    temp = value * 60;
    if(temp != G_parameter.defense_time)
    {
        G_parameter.defense_time = value * 60;
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    }

    if(G_realtime_data.defense_mode == 0)
    {
        track_cust_status_defences_update_time();
    }

    sprintf(cmd->rsp_msg, "OK!");
}

static void cmd_factory(CMD_DATA_STRUCT *cmd)
{
    S32 adc4_offset = G_parameter.adc4_offset;
    nvram_FCFALM_struct alarm = {0};
	kal_uint8 SequenceNumber[11] = {0};
	kal_uint8 voiceVer[4]={0};

    kal_uint8 fake_cell_enable = G_parameter.fake_cell_enable;
//     memcpy( &alarm ,&G_parameter.fcfalm,sizeof(nvram_FCFALM_struct));

    extern void gps_data_backup_manage(kal_uint8 type , kal_uint8 * data, kal_uint32  id, kal_uint32  len);
#if defined(__NF2318__)
		//memcpy(SequenceNumber, G_parameter.ste_param.SequenceNumber, 11);
	memcpy(SequenceNumber, G_importance_parameter_data.SequenceNumber, 11);
	memcpy(voiceVer, G_parameter.voice_ver, 4);
#endif

    if(cmd->part == 0)
    {
        if(!strcmp(cmd->pars[0], "FACTORYALL"))
        {
            Track_nvram_write(NVRAM_EF_LOGD_LID, 1, OTA_NVRAM_EF_LOGD_DEFAULT, NVRAM_EF_LOGD_SIZE);
            Track_nvram_write(NVRAM_EF_PORT_SETTING_LID, 1, OTA_NVRAM_EF_PORT_SETTING_DEFAULT, NVRAM_EF_PORT_SETTING_SIZE);
        }
        else
        {
            nvram_ef_logd_struct log_setting_tmp = {0};
            nvram_ef_logd_struct log_setting = {0};
            Track_nvram_read(NVRAM_EF_LOGD_LID, 1, (void *)&log_setting, NVRAM_EF_LOGD_SIZE);
            memcpy(&log_setting_tmp, OTA_NVRAM_EF_LOGD_DEFAULT, sizeof(nvram_ef_logd_struct));
            log_setting_tmp.logd_target = log_setting.logd_target;
            Track_nvram_write(NVRAM_EF_LOGD_LID, 1, &log_setting_tmp, NVRAM_EF_LOGD_SIZE);
        }
        track_soc_clear_queue();
        gps_data_backup_manage(5, NULL, 0, 0);
        Track_nvram_write(NVRAM_EF_GPS_BACKUP_DATA_PARAM_LID, 1, OTA_NVRAM_EF_GPS_BACKUP_DATA_PARAM_DEFAULT, NVRAM_EF_GPS_BACKUP_DATA_PARAM_SIZE);
        GPS_NVRAM_Backup_Init();

        track_cust_backup_gps_data(5, NULL);

        /*if(G_importance_parameter_data.server.lock != 1)
        {
            memcpy(&G_importance_parameter_data, OTA_NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
        }
        Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
        */
        memcpy(&G_parameter, OTA_NVRAM_EF_PARAMETER_DEFAULT, NVRAM_EF_PARAMETER_SIZE);
#if defined(__SAME_GT02__) && defined(__SYS_VERSION__)
        track_set_server_ip_status(0);
        track_os_intoTaskMsgQueueExt(track_soc_gprs_reconnect, (void*)22);//修改域名后，重新建立连接
        if(G_importance_parameter_data.app_version.version == 1)
        {
            G_parameter.lang = 1;
            //     G_parameter.sensor_gps_work = 0;
        }
        else if(G_importance_parameter_data.app_version.version == 2)
        {
            G_parameter.lang = 1;
            //  G_parameter.sensor_gps_work = 0;
        }
        else if(G_importance_parameter_data.app_version.version == 3)
        {
            G_parameter.lang = 0;
            G_parameter.sensor_gps_work = 5;
            G_parameter.agps.sw = 0;
            memcpy(&G_parameter.url, "http://maps.google.com/maps?q=", strlen("http://maps.google.com/maps?q="));

        }
        else if(G_importance_parameter_data.app_version.version == 4)
        {
            G_parameter.lang = 1;
            //   G_parameter.sensor_gps_work = 5;
        }
        /* else
        {
             memcpy(&G_parameter, OTA_NVRAM_EF_PARAMETER_DEFAULT, NVRAM_EF_PARAMETER_SIZE);
         }
         */
#elif defined(__ET310__)
        G_parameter.adc4_offset = adc4_offset;
#endif
#if defined(__NF2318__)
	//memcpy(G_parameter.ste_param.SequenceNumber,SequenceNumber,11);
	memcpy(G_importance_parameter_data.SequenceNumber,SequenceNumber,11);
	//G_realtime_data.file_update_style = 2;
	//LOGD(5, 5, "%d", G_realtime_data.file_update_style);

	if((G_realtime_data.file_update_style&2) == 2)//有语音更新
	{
		memcpy(G_parameter.voice_ver, voiceVer, 4);
	}
	else
	{
		memset(G_realtime_data.voice_list.void_id, 0, sizeof(voice_id_struct));
		G_realtime_data.voice_max = 100;
    	AUDIO_file_delete(0);//认为下载列表为空，清除所有语音
		G_realtime_data.voice_max = 0;
		tr_stop_timer(TRACK_CUST_NVRAM_WRITE_DELEY_TIMER_ID);
	}
#endif
        G_parameter.fake_cell_enable = fake_cell_enable; //格式化不清除防伪功能，只受加密串口指令
        //  memcpy(&G_parameter.fcfalm, &alarm, sizeof(nvram_FCFALM_struct));
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);

        memcpy(&G_realtime_data, OTA_NVRAM_EF_REALTIME_DEFAULT, NVRAM_EF_REALTIME_SIZE);
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);

        memcpy(&G_phone_number, OTA_NVRAM_EF_PHONE_NUMBER_DEFAULT, NVRAM_EF_PHONE_NUMBER_SIZE);
        Track_nvram_write(NVRAM_EF_PHONE_NUMBER_LID, 1, (void *)&G_phone_number, NVRAM_EF_PHONE_NUMBER_SIZE);
        {
#if defined(__GERMANY__)
            sprintf(cmd->rsp_msg, "OK - der Tracker startet in 60 Sek.neu.");
#elif defined(__SPANISH__)
            sprintf(cmd->rsp_msg, "La terminal se reiniciara despues de 60 segundos!");
//#elif defined(__NF2318__)

#else
            sprintf(cmd->rsp_msg, "OK!\r\nThe terminal will restart after 60s!");
#endif
        }

#if defined(__ET310__)
        {
            nvram_check_ota_struct g_otacheck = {0};
            memcpy(&g_otacheck, NVRAM_EF_CHECK_OTA_DEFAULT, NVRAM_EF_CHECK_OTA_SIZE);
            Track_nvram_write(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
        }
#endif /* __ET310__ */


        track_cust_restart(3, 60);
    }
}
void track_factory()
{
	CMD_DATA_STRUCT cmd = {0};
	cmd.part = 0;
	//cmd.return_sms.cm_type = CM_AT;
	//LOGD(5, 1, "%s", cmd.pars[0]);
	cmd_factory(&cmd);
}
static void cmd_factory_all(CMD_DATA_STRUCT *cmd)
{
	kal_uint8 SequenceNumber[11] = {0};
    if(cmd->part == 0)
    {
#if defined (__SAME_GT02__)
        track_set_server_ip_status(0);
        track_os_intoTaskMsgQueueExt(track_soc_gprs_reconnect, (void*)22);//修改域名后，重新建立连接
#if defined(__SAME_GT02__) && defined(__SYS_VERSION__)
        if(G_importance_parameter_data.app_version.version == 1)
        {
            memcpy(&G_importance_parameter_data, &NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT_SERVER_GUMI, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
        }
        else if(G_importance_parameter_data.app_version.version == 2)
        {
            memcpy(&G_importance_parameter_data, &NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT_GUMI_GENERAL, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
        }
        else if(G_importance_parameter_data.app_version.version == 3)
        {

            memcpy(&G_importance_parameter_data, &NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT_SERVER_COOACCESS, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
        }
        else if(G_importance_parameter_data.app_version.version == 4)
        {
            memcpy(&G_importance_parameter_data, &NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT_SERVER_TUQIANG, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
        }
        else
#endif
        {
            memcpy(&G_importance_parameter_data, OTA_NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
        }
        memcpy(G_importance_parameter_data.build_date, OTA_NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT->build_date, 15);
        memcpy(G_importance_parameter_data.build_time, OTA_NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT->build_time, 15);

#else
		memcpy(SequenceNumber, G_importance_parameter_data.SequenceNumber, 11);

        memcpy(&G_importance_parameter_data, (void*)track_drv_get_importPara_default(), NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
		memcpy(G_importance_parameter_data.SequenceNumber,SequenceNumber,11);

#endif /* __SAME_GT02__ */
        Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
        cmd_factory(cmd);
    }
}
/******************************************************************************
 *  Function    -  cmd_center
 *
 *  Purpose     -  中心号码设置
 *
 *  Description -
        CENTER,A,<中心号码>#
            添加中心号码
        CENTER,D#
            删除中心号码
        CENTER#
            查询设置的中心号码
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_center(CMD_DATA_STRUCT *cmd)
{
    LOGD(L_APP, L_V5, "");
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], G_parameter.centerNumber);
        return;
    }
    if(cmd->supercmd != 1 && cmd->return_sms.cm_type == CM_SMS)
    {
        if(G_parameter.Permission.Permit == 0 && track_cust_sos_or_center_check(3, cmd->return_sms.ph_num) != 9)
        {
#if defined(__GERMANY__)
            sprintf(cmd->rsp_msg, "Fehler! Nur die SOS- und Center-Nr.kann Befehl senden.");
#else
            sprintf(cmd->rsp_msg, "Error! Only center phone number and SOS phone numbers are allowed to set.");
#endif
            return;
        }
        else if(G_parameter.Permission.Permit == 1 && track_cust_sos_or_center_check(1, cmd->return_sms.ph_num) == 1)
        {
            sprintf(cmd->rsp_msg, "Error! Only center phone number to set.");
            return;
        }
    }

    if(!strcmp(cmd->pars[1], "A"))
    {
        int len, i;
        if(cmd->part != 2)
        {
#if defined (__GERMANY__)
            sprintf(cmd->rsp_msg, "Fehler: Max. 1 Nummern eingeben!");
#else
            sprintf(cmd->rsp_msg, "Error: At most once to add one numbers!");
#endif
            return;
        }
        len = strlen(cmd->pars[2]);
        if(len > 0)
        {
            if(track_fun_check_str_is_number(1, cmd->pars[2]) == 0)
            {
                sprintf(cmd->rsp_msg, "Error: Number contains non-numeric characters!");
                return;
            }
            if(len > 20)
            {
                sprintf(cmd->rsp_msg, "Error: Number length exceeds 20 characters!");
                return;
            }
            else if(len < 3)
            {
#if defined (__GERMANY__)
                sprintf(cmd->rsp_msg, "Fehler: Mindestens 3 Zeichen eingeben!");
#else
                sprintf(cmd->rsp_msg, "Error: Number length must exceeds 3 characters!");
#endif
                return;
            }
            strcpy(G_parameter.centerNumber, cmd->pars[2]);
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
#if defined (__GERMANY__)
            sprintf(cmd->rsp_msg, "OK-\r\nCenter Nummer:%s", G_parameter.centerNumber);
#else
            sprintf(cmd->rsp_msg, "OK\r\nCenter Number:%s", G_parameter.centerNumber);
#endif
        }
    }
    else if(!strcmp(cmd->pars[1], "D"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        memset(G_parameter.centerNumber, 0, TRACK_DEFINE_PHONE_NUMBER_LEN_MAX);
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
#if defined (__GERMANY__)
        sprintf(cmd->rsp_msg, "OK-\r\nCenter Nummer:%s", G_parameter.centerNumber);
#else
        sprintf(cmd->rsp_msg, "OK\r\nCenter Number:%s", G_parameter.centerNumber);
#endif
    }
#if defined(__PARAM_CHANGE_UPDATE_SERVER__)
    track_cust_paket_9404_handle();
#endif
}
#if defined(__NF2318__)
#else
static void cmd_delay(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%ds", cmd->pars[0], G_parameter.monitor_delay);
        return;
    }
    else if(cmd->part == 1)
    {
        int value;
        if(track_fun_check_str_is_number(1, cmd->pars[1]) == 0)
        {
            sprintf(cmd->rsp_msg, "Error: The first parameter is not a number!");
            return;
        }
        value = track_fun_atoi(cmd->pars[1]);
        if(value < 5 || value > 18)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (5-18)");
            return;
        }
        G_parameter.monitor_delay = value;
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
}
#endif

/******************************************************************************
 *  Function    -  cmd_monpermit
 *
 *  Purpose     -  监听权限控制
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 21-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_monpermit(CMD_DATA_STRUCT *cmd)
{
#if defined(__NF2318__)
	;
#else
    int value;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.Permission.MonPermit);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(cmd->supercmd != 1 && cmd->return_sms.cm_type == CM_SMS && track_cust_sos_or_center_check(3, cmd->return_sms.ph_num) != 9)
    {
#if defined(__GERMANY__)
        sprintf(cmd->rsp_msg, "Fehler! Nur die SOS- und Center-Nr.kann Befehl senden.");

#else
        sprintf(cmd->rsp_msg, "Error! Only center phone number and SOS phone numbers are allowed to set.");
#endif/*__GERMANY__*/
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 0 || value > 3)
    {
        sprintf(cmd->rsp_msg, "Error: Value only in from 0 to 3!");
        return;
    }
    G_parameter.Permission.MonPermit = value;
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
#endif
}
#if !defined(__NF2318__)
static void cmd_permit(CMD_DATA_STRUCT *cmd)
{
    int value;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.Permission.Permit);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(cmd->supercmd != 1 && cmd->return_sms.cm_type == CM_SMS && track_cust_sos_or_center_check(3, cmd->return_sms.ph_num) != 9)
    {
        sprintf(cmd->rsp_msg, "Error! Only center phone number and SOS phone numbers are allowed to set.");
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 0 || value > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Value only in from 0 to 1!");
        return;
    }
    G_parameter.Permission.Permit = value;
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

/******************************************************************************
 *  Function    -  cmd_sospermit
 *
 *  Purpose     -  SOS权限设置指令
 *
 *  Description -
        SOSPERMIT,<A>[,B]#
            A=0-1；参数设置查询权限范围；默认值：0
            B=0-1；报警号码权限；  默认值：1
        SOSPERMIT#
            查询 SOS 号码参数设置查询权限
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 19-03-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_sospermit(CMD_DATA_STRUCT *cmd)
{
    int SOSPermit, AlarmNumCount;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d,%d", cmd->pars[0], G_parameter.Permission.SOSPermit, G_parameter.Permission.AlarmNumCount);
        return;
    }
    else if(cmd->part > 2)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(cmd->supercmd != 1 && cmd->return_sms.cm_type == CM_SMS && track_cust_sos_or_center_check(3, cmd->return_sms.ph_num) != 9)
    {
#if defined(__GERMANY__)
        sprintf(cmd->rsp_msg, "Fehler! Nur die SOS- und Center-Nr. kann Befehl senden.");
#else
        sprintf(cmd->rsp_msg, "Error! Only center phone number and SOS phone numbers are allowed to set.");
#endif/*__GERMANY__*/

        return;
    }
    SOSPermit = track_fun_atoi(cmd->pars[1]);
    if(SOSPermit < 0 || SOSPermit > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Value only in from 0 to 1!");
        return;
    }
    if(cmd->part == 2)
    {
        AlarmNumCount = track_fun_atoi(cmd->pars[2]);
        if(AlarmNumCount < 0 || AlarmNumCount > 1)
        {
            sprintf(cmd->rsp_msg, "Error: Value only in from 0 to 1!");
            return;
        }
        G_parameter.Permission.AlarmNumCount = AlarmNumCount;
    }
    G_parameter.Permission.SOSPermit = SOSPermit;
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

static void cmd_pwdsw(CMD_DATA_STRUCT *cmd)
{
    int value;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], ON_OFF(G_parameter.Permission.password_sw));
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(cmd->supercmd != 1 && cmd->return_sms.cm_type == CM_SMS && track_cust_sos_or_center_check(3, cmd->return_sms.ph_num) != 9)
    {
#if defined(__GERMANY__)
        sprintf(cmd->rsp_msg, "Fehler! Nur die SOS- und Center-Nr. kann Befehl senden.");
#else
        sprintf(cmd->rsp_msg, "Error! Only center phone number and SOS phone numbers are allowed to set.");
#endif/*__GERMANY__*/

        return;
    }
    if(!strcmp(cmd->pars[1], "ON"))
        G_parameter.Permission.password_sw = 1;
    else if(!strcmp(cmd->pars[1], "OFF"))
        G_parameter.Permission.password_sw = 0;
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

static void cmd_password(CMD_DATA_STRUCT *cmd)
{
    int value, len;
    char newpassword[20] = {0}, oldpassword[20] = {0};
    //LOGD(L_APP, L_V5, "%s,%s", G_parameter.Permission.password, G_parameter.Permission.superPassword);
    if(G_parameter.Permission.password_sw)
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        len = strlen(cmd->pars[1]);
        if(len == 0)
        {
            sprintf(cmd->rsp_msg, "Error: new password can not be empty!");
            return;
        }
        if(len > 19)
        {
            sprintf(cmd->rsp_msg, "Error: Character length should be less than 20 characters!");
            return;
        }

        memcpy(newpassword, cmd->rcv_msg_source + (cmd->pars[1] - cmd->rcv_msg), len);
    }
    else
    {
        if(cmd->part != 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        len = strlen(cmd->pars[2]);
        if(strlen(cmd->pars[1]) == 0 || len == 0)
        {
            sprintf(cmd->rsp_msg, "Error: Old password or new password can not be empty!");
            return;
        }
        if(len > 19)
        {
            sprintf(cmd->rsp_msg, "Error: Character length should be less than 20 characters!");
            return;
        }

        memcpy(oldpassword, cmd->rcv_msg_source + (cmd->pars[1] - cmd->rcv_msg), strlen(cmd->pars[1]));
        if(strcmp(oldpassword, G_parameter.Permission.password))
        {
            sprintf(cmd->rsp_msg, "Error: Old password error!");
            return;
        }
        memcpy(newpassword, cmd->rcv_msg_source + (cmd->pars[2] - cmd->rcv_msg), len);
    }
    if(track_fun_check_str_is_number_and_string(0, newpassword) <= 0)
    {
        sprintf(cmd->rsp_msg, "Error: password characters can only be numbers or letters.");
        return;
    }
    //LOGD(L_APP, L_V5, "old:|%s|", G_parameter.Permission.password);
    if(!strcmp(G_parameter.Permission.password, newpassword))
    {
        sprintf(cmd->rsp_msg, "The new password and the same old password!");
        return;
    }
    track_fun_strncpy(G_parameter.Permission.password, newpassword, 20);
    //LOGD(L_APP, L_V5, "new:|%s|", G_parameter.Permission.password);
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
static void cmd_recover(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        if(cmd->supercmd == 1)
        {
            memcpy(G_parameter.Permission.password, OTA_NVRAM_EF_PARAMETER_DEFAULT->Permission.password, 20);
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
            sprintf(cmd->rsp_msg, "OK!");
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Not authorized!");
            return;
        }
    }
}
#endif
static kal_uint8 string3_en[] = {"The terminal is in Deep Sleep, please wake up!"};

/******************************************************************************
 *  Function    -  cmd_BLINDALM
 *
 *  Purpose     -  GPS盲区报警
 *
 *  Description -
        BLINDALM,ON,20,60,1#
        BLINDALM#
            查询已设置的参数
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  JWJ  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_BLINDALM(CMD_DATA_STRUCT *cmd)
{
#if 1
	;
#else
    nvram_blind_struct alarm = {0};
    int value;
    extern  void track_cust_module_alarm_blind_init(void);

    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d,%d", cmd->pars[0], ON_OFF(G_parameter.gps_blind.sw), G_parameter.gps_blind.blind_in_time, G_parameter.gps_blind.blind_out_time, G_parameter.gps_blind.alarm_type);
        return;
    }
    if(track_cust_get_work_mode() == WORK_MODE_3)
    {
        snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, string3_en);
        return;
    }
    memcpy(&alarm, &G_parameter.gps_blind, sizeof(nvram_blind_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 4)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 1;
        if(cmd->part >= 2)
        {
            value = track_fun_atoi(cmd->pars[2]);
            if(value < 5 || value > 600)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (5-600)");
                return;
            }
            alarm.blind_in_time = value;
        }
        if(cmd->part >= 3)
        {
            value = track_fun_atoi(cmd->pars[3]);
            if(value < 5 || value > 600)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (5-600)");
                return;
            }
            alarm.blind_out_time = value;
        }
        if(cmd->part >= 4)
        {
            value = track_fun_atoi(cmd->pars[4]);
#if defined(__NT36__)
            if(value < 0 || value > 1)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 4 (0/1)");
                return;
            }
#elif defined(__EL100__)
            if(value < 0 || value > 1)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 4 (Only 0)");
                return;
            }
#else
            if(value < 0 || value > 3)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 4 (0/1/2/3)");
                return;
            }
#endif
            alarm.alarm_type = value;
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.gps_blind, &alarm, sizeof(nvram_blind_struct));
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);

//   track_cust_defences_cmd_update();
    sprintf(cmd->rsp_msg, "OK!");
#endif
}


/******************************************************************************
 *  Function    -  cmd_fence
 *
 *  Purpose     -  电子围栏参数设置
 *
 *  Description -
 *        FENCE,<B>,0,<D>,<E>,<F>[,X][,M]#
 *            圆形区域
 *            B=ON/OFF；开启/关闭围栏报警；默认值为：关闭
 *            D=圆心纬度
 *            E=圆心经度
 *            F=100～9999；围栏半径，单位：米
 *            X=IN/OUT；IN：入围栏报警，OUT：出围栏报警，为空：进/出围栏报警；默认为进出围栏都报警
 *            M=0/1；报警上报方式，0：仅GPRS，1：SMS+GPRS，默认为：1
 *        FENCE,<B>,1,<D>,<E>,<F>,<G>[,X][,M]#
 *            方形区域设置
 *            B=ON/OFF；开启/关闭围栏报警；默认值为：关闭
 *            D=坐标1纬度
 *            E=坐标1经度
 *            F=坐标2纬度
 *            G=坐标2经度
 *            X=0/1；0 入围栏报警，1 出围栏报警，2 进/出围栏报警；默认为2
 *            M=0/1；报警上报方式，0：仅GPRS，1：SMS+GPRS，默认为：1
 *        FENCE#
 *            查询围栏设置参数
 *
 *        FENCE#
 *        FENCE,OFF#
 *        FENCE,ON,0,,,1#
 *        FENCE,ON,0,23.10267,114.39671,1#
 *        FENCE,ON,0,23.10267,114.39671,1,2,1#
 *        FENCE,ON,1,23.10267,114.39671,23.20267,114.49671#
 *        FENCE,ON,1,23.10267,114.39671,23.20267,114.59671,2,1#
 *  modification history
 * ----------------------------------------
 * v1.0  , 25-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_fence(CMD_DATA_STRUCT *cmd)
{
#if 1
	;
#else
    nvram_electronic_fence_struct fence = {0};
    track_gps_data_struct *gpsPoint = NULL;
    kal_bool autoLatLon = KAL_FALSE;
    int sn = 0, tmp, i = 1;

    if(cmd->part > 0 && !strcmp(cmd->pars[0], "SEEFENCE")) return;
    if(cmd->part == 0 || !strcmp(cmd->pars[0], "SEEFENCE"))
    {
        char NS[2] = {0}, EW[2] = {0}, NS2[2] = {0}, EW2[2] = {0}, in_out[10] = {0};
        float lat, lon, lat2, lon2;
        if(G_parameter.fence[sn].lat >= 0)
        {
            if(G_parameter.fence[sn].lat != 0) *NS = 'N';
            lat = G_parameter.fence[sn].lat;
        }
        else
        {
            if(G_parameter.fence[sn].lat != 0) *NS = 'S';
            lat = -G_parameter.fence[sn].lat;
        }

        if(G_parameter.fence[sn].lon >= 0)
        {
            if(G_parameter.fence[sn].lon != 0) *EW = 'E';
            lon = G_parameter.fence[sn].lon;
        }
        else
        {
            if(G_parameter.fence[sn].lon != 0) *EW = 'W';
            lon = -G_parameter.fence[sn].lon;
        }
        if(G_parameter.fence[sn].in_out == 0)
            sprintf(in_out, "IN");
        else if(G_parameter.fence[sn].in_out == 1)
            sprintf(in_out, "OUT");
        else if(G_parameter.fence[sn].in_out == 2)
            sprintf(in_out, "IN or OUT");
        if(G_parameter.fence[sn].square)
        {
            if(G_parameter.fence[sn].lat2 >= 0)
            {
                if(G_parameter.fence[sn].lat2 != 0) *NS2 = 'N';
                lat2 = G_parameter.fence[sn].lat2;
            }
            else
            {
                if(G_parameter.fence[sn].lat2 != 0) *NS2 = 'S';
                lat2 = -G_parameter.fence[sn].lat2;
            }
            if(G_parameter.fence[sn].lon2 >= 0)
            {
                if(G_parameter.fence[sn].lon2 != 0) *EW2 = 'E';
                lon2 = G_parameter.fence[sn].lon2;
            }
            else
            {
                if(G_parameter.fence[sn].lon2 != 0) *EW2 = 'W';
                lon2 = -G_parameter.fence[sn].lon2;
            }
#if defined(__GERMANY__)
            sprintf(cmd->rsp_msg, "GeoFence Typ:Square, %s, Latitude1:%s%.6f, Longitude1:%s%.6f, Latitude2:%s%.6f, Longitude2:%s%.6f, REIN RAUS:%s, Alarm typ:%d",
                    ON_OFF(G_parameter.fence[sn].sw),
                    NS, lat, EW, lon,
                    NS2, lat2, EW2, lon2,
                    in_out, G_parameter.fence[sn].alarm_type);
#else
            sprintf(cmd->rsp_msg, "FenceType:Square, %s, Latitude1:%s%.6f, Longitude1:%s%.6f, Latitude2:%s%.6f, Longitude2:%s%.6f, in out:%s, alarm type:%d",
                    ON_OFF(G_parameter.fence[sn].sw),
                    NS, lat, EW, lon,
                    NS2, lat2, EW2, lon2,
                    in_out, G_parameter.fence[sn].alarm_type);
#endif
        }
        else
        {
#if defined(__GERMANY__)
            sprintf(cmd->rsp_msg, "GeoFence Typ:Kreis, %s, Latitude:%s%.6f, Longitude:%s%.6f, Radius:%dm, REIN RAUS:%s, Alarm typ:%d",
                    ON_OFF(G_parameter.fence[sn].sw),
                    NS, lat, EW, lon, G_parameter.fence[sn].radius * 100,
                    in_out, G_parameter.fence[sn].alarm_type);
#else
            sprintf(cmd->rsp_msg, "FenceType:Circle, %s, Latitude:%s%.6f, Longitude:%s%.6f, radius:%dm, in out:%s, alarm type:%d",
                    ON_OFF(G_parameter.fence[sn].sw),
                    NS, lat, EW, lon, G_parameter.fence[sn].radius * 100,
                    in_out, G_parameter.fence[sn].alarm_type);
#endif
        }
        return;
    }
    memcpy(&fence, &G_parameter.fence[sn], sizeof(nvram_electronic_fence_struct));
    if(!strcmp(cmd->pars[i], "ON"))
    {
        char *lat1, *lon1, *lat2, *lon2;
        fence.sw = 1;
        i++;
        LOGD(L_APP, L_V6, "%d,%d", fence.sw, cmd->part);
        tmp = track_fun_atoi(cmd->pars[i++]);
        if(tmp != 0 && tmp != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1)");
            return;
        }
        fence.square = tmp;

        if(fence.square == 0)
        {
            //圆形
            if(cmd->part < 5 || cmd->part > 7)
            {
                sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
                return;
            }
            lat1 = cmd->pars[i];
            lon1 = cmd->pars[i + 1];
            if((!strcmp(lat1, "0") || *lat1 == 0) && (!strcmp(lon1, "0") || *lon1 == 0))
            {
                if(track_cust_gps_status() < GPS_STAUS_2D)
                {
                    if(track_cust_gps_status() == GPS_STAUS_OFF)
                        track_cust_gps_work_req((void*)5);
#if defined(__GERMANY__)
                    return_message(
                        cmd,
                        "GPS nicht erkannt. Bitte erneut senden, wenn GPS erkannt wird.",
                        "当前卫星定位未定位，请在卫星定位后设置！");
#else
#if defined (__TRACK_TYPE_GPS_BEIDOU__)
                    return_message(
                        cmd,
                        "BD/GPS not fixed, Please set again after BD/GPS fixed!",
                        "当前卫星定位未定位，请在卫星定位后设置！");
#else
                    return_message(
                        cmd,
                        "GPS not fixed, Please set again after GPS fixed!",
                        "当前卫星定位未定位，请在卫星定位后设置！");
#endif/*__GERMANY__*/
#endif /* __TRACK_TYPE_GPS_BEIDOU__ */

                    return;
                }
                fence.lat = 0;
                fence.lon = 0;
                gpsPoint = track_drv_get_gps_data();
                if(gpsPoint->gprmc.NS == 'S')
                    fence.lat = -gpsPoint->gprmc.Latitude;
                else
                    fence.lat = gpsPoint->gprmc.Latitude;
                if(gpsPoint->gprmc.EW == 'W')
                    fence.lon = -gpsPoint->gprmc.Longitude;
                else
                    fence.lon = gpsPoint->gprmc.Longitude;
                autoLatLon = KAL_TRUE;
            }
            else if(strlen(lat1) > 0 || strlen(lon1) > 0)
            {
                if(!enter_lat_lon(1, lat1, &fence.lat))
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 3!");
                    return;
                }
                if(!enter_lat_lon(0, lon1, &fence.lon))
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 4!");
                    return;
                }
                if(fence.lat == 0 || fence.lon == 0)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 3 or Parameter 4 !\r\nlat:%s, lon:%s, (%f,%f)", &lat1[1], &lon1[1], fence.lat, fence.lon);
                    return;
                }
                if(fence.lat > 90 || fence.lat < -90 || fence.lon > 180 || fence.lon < -180)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 3 or Parameter 4.");
                    return;
                }
            }
            else
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 or Parameter 4!");
                return;
            }
            i += 2;
            if(cmd->part >= i)
            {
                tmp = track_fun_atoi(cmd->pars[i]);
                if(tmp < 1 || tmp > 9999)
                {
#if defined(__GERMANY__)
                    sprintf(cmd->rsp_msg, "Fehler: Parameter 5 (1-9999) Einheit = 100m");
#else
                    sprintf(cmd->rsp_msg, "Error: Parameter 5 (1-9999) (Unit: hundred meters)");
#endif
                    return;
                }
                fence.radius = tmp;
            }
            i++;
            //fence.lat2 = 0;
            //fence.lon2 = 0;
        }
        else if(fence.square == 1)
        {
            //方形
            if(cmd->part < 6 || cmd->part > 8)
            {
                sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
                return;
            }
            lat1 = cmd->pars[i];
            lon1 = cmd->pars[i + 1];
            lat2 = cmd->pars[i + 2];
            lon2 = cmd->pars[i + 3];
            LOGD(L_CMD, L_V5, "%s;%s;%s;%s", cmd->pars[i], cmd->pars[i + 1], cmd->pars[i + 2], cmd->pars[i + 3]);
            LOGD(L_CMD, L_V5, "%s;%s;%s;%s", lat1, lon1, lat2, lon2);
            if(strlen(lat1) > 0 && strlen(lon1) > 0 && strlen(lat2) > 0 && strlen(lon2) > 0)
            {
                if(!enter_lat_lon(1, lat1, &fence.lat))
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 3!");
                    return;
                }
                if(!enter_lat_lon(0, lon1, &fence.lon))
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 4!");
                    return;
                }
                if(!enter_lat_lon(1, lat2, &fence.lat2))
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 5!");
                    return;
                }
                if(!enter_lat_lon(0, lon2, &fence.lon2))
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 6!");
                    return;
                }
                /*if(fence.lat == 0 || fence.lon == 0 || fence.lat2 == 0 || fence.lon2 == 0)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameters 3 to 6 can not be zero!");
                    return;
                }*/
                if(fence.lat > 90 || fence.lat < -90 || fence.lon > 180 || fence.lon < -180
                        || fence.lat2 > 90 || fence.lat2 < -90 || fence.lon2 > 180 || fence.lon2 < -180)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameters 3 to 6.");
                    return;
                }
                LOGD(L_CMD, L_V5, "%.6f;%.6f;%.6f;%.6f", fence.lat, fence.lon, fence.lat2, fence.lon2);
                if(fence.lat == fence.lat2 || fence.lon == fence.lon2)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameters 3 and 5 of the same or parameters 4 and 6 of the same!");
                    return;
                }
            }
            else
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 to 6!");
                return;
            }
            i += 4;
            //fence.radius = 0;
        }
        fence.in_out = OTA_NVRAM_EF_PARAMETER_DEFAULT->fence[sn].in_out;
        if(cmd->part >= i)
        {
            if(!strcmp("IN", cmd->pars[i]))
            {
                fence.in_out = 0;
            }
            else if(!strcmp("OUT", cmd->pars[i]))
            {
                fence.in_out = 1;
            }
            else if(strlen(cmd->pars[i]) == 0)
            {
                fence.in_out = 2;
            }
            else
            {
                sprintf(cmd->rsp_msg, "Error: Parameter %d (IN/OUT)", i);
                return;
            }
        }
        i++;
        fence.alarm_type = OTA_NVRAM_EF_PARAMETER_DEFAULT->fence[sn].alarm_type;
        if(cmd->part >= i)
        {
            tmp = track_fun_atoi(cmd->pars[i]);
            if(tmp != 0 && tmp != 1)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter %d (0/1)", i);
                return;
            }
            fence.alarm_type = tmp;
        }
    }
    else if(!strcmp(cmd->pars[i], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        fence.sw = 0;
        fence.lat = 0;
        fence.lon = 0;
        fence.lat2 = 0;
        fence.lon2 = 0;
        fence.in_out = OTA_NVRAM_EF_PARAMETER_DEFAULT->fence[sn].in_out;
        fence.alarm_type = OTA_NVRAM_EF_PARAMETER_DEFAULT->fence[sn].alarm_type;
        if(G_parameter.lang == 1 && cmd->return_sms.cm_type != CM_ONLINE && cmd->return_sms.cm_type != CM_ONLINE2)
        {
            char buf[320] = {0};
            int ret;
            char *tmp = NULL, *str_in = "入", *str_out = "出", *str_in_and_out = "出入";
            if(fence.in_out == 0)
            {
                tmp = str_in;
            }
            else if(fence.in_out == 2)
            {
                tmp = str_in_and_out;
            }
            else
            {
                tmp = str_out;
            }
            if(fence.square == 0)
            {
                snprintf(buf, 320, "设置成功！圆形围栏已关闭。");
                /*snprintf(buf, 320, "设置成功！圆形围栏，报警已关闭；圆心：0.000000，0.000000，半径：%d米，%s围栏报警，报警类型：%d",
                             fence.radius * 100, tmp, fence.alarm_type);*/
            }
            else
            {
                snprintf(buf, 320, "设置成功！矩形围栏已关闭。");
                /*snprintf(buf, 320, "设置成功！矩形围栏，报警已关闭；纬度1：0.000000，经度1：0.000000，纬度2：0.000000，经度2：0.000000；%s围栏报警，报警类型：%d",
                             tmp, fence.alarm_type);*/
            }
            if(cmd->return_sms.cm_type == CM_AT)
            {
                cmd->rsp_length = strlen(buf);
                memcpy(cmd->rsp_msg, buf, cmd->rsp_length);
                cmd->return_sms.reply_character_encode = 2;
            }
            else
            {
                cmd->rsp_length = track_fun_GB2312_to_UTF16BE(buf, strlen(buf), cmd->rsp_msg, 320);
                cmd->return_sms.reply_character_encode = 1;
            }
        }
        else
        {
            char *tmp = NULL, *str_in = "IN", *str_out = "OUT", *str_in_and_out = "IN or OUT";
            if(fence.in_out == 0)
            {
                tmp = str_in;
            }
            else if(fence.in_out == 2)
            {
                tmp = str_in_and_out;
            }
            else
            {
                tmp = str_out;
            }
            if(fence.square == 0)
            {
#if defined(__GERMANY__)
                sprintf(cmd->rsp_msg, "OK! GeoZonen Alarm deaktiviert !");
#else
                sprintf(cmd->rsp_msg, "OK!Disable Circle Fence set successfully!");
                /*sprintf(cmd->rsp_msg, "OK! FenceType:Circle, OFF, Latitude:0.000000, Longitude:0.000000, radius:%dm, in out:%s, alarm type:%d.",
                            fence.radius * 100, tmp, fence.alarm_type);*/
#endif
            }
            else
            {
#if defined(__GERMANY__)
                sprintf(cmd->rsp_msg, "OK! GeoZonen Alarm deaktiviert !");
#else
                sprintf(cmd->rsp_msg, "OK!Disable Square Fence set successfully!");
                /*sprintf(cmd->rsp_msg, "OK! FenceType:Square, OFF, Latitude1:0.000000, Longitude1:0.000000, Latitude2:0.000000, Longitude2:0.000000, in out:%s, alarm type:%d.",
                            tmp, fence.alarm_type);*/
#endif
            }
        }
    }
    else if(!strcmp(cmd->pars[i], "C") && fence.square == 0)
    {
        float tmp, lat, lon;
        tmp = fence.radius * 100;
        tmp = tmp / 111000;
        lat = fence.lat;
        lon = fence.lon;
        fence.lat = lat - tmp;
        fence.lon = lon + tmp;
        fence.lat2 = lat + tmp;
        fence.lon2 = lon - tmp;
        fence.square = 1;
#if defined(__GERMANY__)
        sprintf(cmd->rsp_msg, "GeoFence Typ:Square, %s, Latitude1:%.6f, Longitude1:%.6f, Latitude2:%.6f, Longitude2:%.6f, REIN RAUS :%d, alarm typ:%d",
                ON_OFF(fence.sw),
                fence.lat, fence.lon,
                fence.lat2, fence.lon2,
                fence.in_out, fence.alarm_type);
#else
        sprintf(cmd->rsp_msg, "FenceType:Square, %s, Latitude1:%.6f, Longitude1:%.6f, Latitude2:%.6f, Longitude2:%.6f, in out:%d, alarm type:%d",
                ON_OFF(fence.sw),
                fence.lat, fence.lon,
                fence.lat2, fence.lon2,
                fence.in_out, fence.alarm_type);
#endif
    }
    else if(!strcmp(cmd->pars[i], "SEE"))
    {
        if(G_parameter.fence[0].lat > 0 && G_parameter.fence[0].lon > 0)
        {
            float res = 0;
            if(track_cust_gps_status() >= GPS_STAUS_2D)
            {
                res = track_fun_get_GPS_2Points_distance(
                          G_parameter.fence[0].lat, G_parameter.fence[0].lon,
                          track_drv_get_gps_RMC()->Latitude, track_drv_get_gps_RMC()->Longitude);
                sprintf(cmd->rsp_msg, "Distance from the origin : %.2fM", res);
            }
            else
            {
                sprintf(cmd->rsp_msg, "No location!");
            }
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Origin of longitude and latitude is no set!");
        }
        return;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.fence[sn], &fence, sizeof(nvram_electronic_fence_struct));
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    if(fence.sw == 1 && !strlen(cmd->rsp_msg))
    {
        applib_time_struct time = {0};
        char NS, EW, NS2, EW2;
        float lat, lon, lat2, lon2;
        if(fence.lat >= 0)
        {
            NS = 'N';
            lat = fence.lat;
        }
        else
        {
            NS = 'S';
            lat = -fence.lat;
        }
        if(fence.lon >= 0)
        {
            EW = 'E';
            lon = fence.lon;
        }
        else
        {
            EW = 'W';
            lon = -fence.lon;
        }
        if(fence.square == 1)
        {
            if(fence.lat2 >= 0)
            {
                NS2 = 'N';
                lat2 = fence.lat2;
            }
            else
            {
                NS2 = 'S';
                lat2 = -fence.lat2;
            }
            if(fence.lon2 >= 0)
            {
                EW2 = 'E';
                lon2 = fence.lon2;
            }
            else
            {
                EW2 = 'W';
                lon2 = -fence.lon2;
            }
        }
        /* GPS数据中的时间加上时区校正 */
        if(track_cust_is_upload_UTC_time())
        {
            track_drv_utc_timezone_to_rtc(&time, (applib_time_struct*)&gpsPoint->gprmc.Date_Time, G_parameter.zone);
        }
        else
        {
            memcpy(&time, &gpsPoint->gprmc.Date_Time, sizeof(applib_time_struct));
        }
        if(G_parameter.lang == 1 && cmd->return_sms.cm_type != CM_ONLINE && cmd->return_sms.cm_type != CM_ONLINE2)
        {
            char buf[320] = {0};
            int ret;
            char *tmp = NULL, *str_in = "入", *str_out = "出", *str_in_and_out = "出入";
            if(fence.in_out == 0)
            {
                tmp = str_in;
            }
            else if(fence.in_out == 2)
            {
                tmp = str_in_and_out;
            }
            else
            {
                tmp = str_out;
            }
            if(autoLatLon)
            {
                sprintf(buf, "OK！已自动获取圆心位置：%c%.6f,%c%.6f，时间：%.2d-%.2d-%.2d %.2d:%.2d:%.2d",
                        NS, lat, EW, lon,
                        time.nYear, time.nMonth, time.nDay,
                        time.nHour, time.nMin, time.nSec);

            }
            else if(fence.square == 0)
            {
                sprintf(buf, "设置成功！圆形围栏，报警已开启；圆心：%c%.6f，%c%.6f，半径：%d米，%s围栏报警，报警类型：%d",
                        NS, lat, EW, lon,
                        fence.radius * 100, tmp, fence.alarm_type);
            }
            else
            {
                sprintf(buf, "设置成功！矩形围栏，报警已开启；纬度1：%c%.6f，经度1：%c%.6f，纬度2：%c%.6f，经度2：%c%.6f；%s围栏报警，报警类型：%d",
                        NS, lat, EW, lon, NS2, lat2, EW2, lon2,
                        tmp, fence.alarm_type);
            }
            if(cmd->return_sms.cm_type == CM_AT)
            {
                cmd->rsp_length = strlen(buf);
                memcpy(cmd->rsp_msg, buf, cmd->rsp_length);
                cmd->return_sms.reply_character_encode = 2;
            }
            else
            {
                cmd->rsp_length = track_fun_GB2312_to_UTF16BE(buf, strlen(buf), cmd->rsp_msg, 320);
                cmd->return_sms.reply_character_encode = 1;
            }
        }
        else
        {
            char *tmp = NULL, *str_in = "IN", *str_out = "OUT", *str_in_and_out = "IN or OUT";
            if(fence.in_out == 0)
            {
                tmp = str_in;
            }
            else if(fence.in_out == 2)
            {
                tmp = str_in_and_out;
            }
            else
            {
                tmp = str_out;
            }
            if(autoLatLon)
            {
#if defined(__GERMANY__)
                sprintf(cmd->rsp_msg, "OK! GPS automatisch erkennen! Latitude:%c%.6f Longitude:%c%.6f",
                        NS, lat, EW, lon
                       );
#else
                sprintf(cmd->rsp_msg, "OK! Automatically obtain latitude:%c%.6f Longitude:%c%.6f, in the time %.2d-%.2d-%.2d %.2d:%.2d:%.2d",
                        NS, lat, EW, lon,
                        time.nYear, time.nMonth, time.nDay,
                        time.nHour, time.nMin, time.nSec);
#endif
            }
            else if(fence.square == 0)
            {
#if defined(__GERMANY__)
                sprintf(cmd->rsp_msg, "OK! GeoFence Typ:Kreis,EIN,Latitude:%c%.6f, Longitude:%c%.6f, Radius:%dm, REIN RAUS:%s, Alarm typ:%d.",
                        NS, lat, EW, lon,
                        fence.radius * 100, tmp, fence.alarm_type);
#else
                sprintf(cmd->rsp_msg, "OK! FenceType:Circle, ON, Latitude:%c%.6f, Longitude:%c%.6f, radius:%dm, in out:%s, alarm type:%d.",
                        NS, lat, EW, lon,
                        fence.radius * 100, tmp, fence.alarm_type);
#endif
            }
            else
            {
#if defined(__GERMANY__)
                sprintf(cmd->rsp_msg, "OK! GeoFence Typ:Square,EIN,Latitude1:%c%.6f, Longitude1:%c%.6f, Latitude2:%c%.6f, Longitude2:%c%.6f, REIN RAUS:%s, Alarm typ:%d.",
                        NS, lat, EW, lon, NS2, lat2, EW2, lon2,
                        tmp, fence.alarm_type);
#else
                sprintf(cmd->rsp_msg, "OK! FenceType:Square, ON, Latitude1:%c%.6f, Longitude1:%c%.6f, Latitude2:%c%.6f, Longitude2:%c%.6f, in out:%s, alarm type:%d.",
                        NS, lat, EW, lon, NS2, lat2, EW2, lon2,
                        tmp, fence.alarm_type);
#endif
            }
        }
    }
    if(!strlen(cmd->rsp_msg) && cmd->rsp_length == 0) sprintf(cmd->rsp_msg, "OK!");
    track_cust_module_fence_cmd_update(0);
#if defined(__PARAM_CHANGE_UPDATE_SERVER__)
    track_cust_paket_9404_handle();
#endif
#endif
}

/******************************************************************************
 *  Function    -  cmd_gfence
 *
 *  Purpose     -  电子围栏参数设置
 *
 *  Description -
 *        FENCE,<N>,<B>,0,<D>,<E>,<F>[,X][,M]#
 *            圆形区域
 *            N=1-5,1到5的围栏
 *            B=ON/OFF；开启/关闭围栏报警；默认值为：关闭
 *            D=圆心纬度
 *            E=圆心经度
 *            F=100～9999；围栏半径，单位：米
 *            X=IN/OUT；IN：入围栏报警，OUT：出围栏报警，为空：进/出围栏报警；默认为进出围栏都报警
 *            M=0/1；报警上报方式，0：仅GPRS，1：SMS+GPRS，默认为：1
 *        FENCE,<N>,<B>,1,<D>,<E>,<F>,<G>[,X][,M]#
 *            方形区域设置
 *            N=1-5,1到5的围栏
 *            B=ON/OFF；开启/关闭围栏报警；默认值为：关闭
 *            D=坐标1纬度
 *            E=坐标1经度
 *            F=坐标2纬度
 *            G=坐标2经度
 *            X=0/1；0 入围栏报警，1 出围栏报警，2 进/出围栏报警；默认为2
 *            M=0/1；报警上报方式，0：仅GPRS，1：SMS+GPRS，默认为：1
 *        FENCE#
 *            查询围栏设置参数
 *
 *        GFENCE#
 *        GFENCE,1,OFF#
 *        GFENCE,1,ON,0,,,1#
 *        GFENCE,1,ON,0,23.10267,114.39671,1#
 *        GFENCE,1,ON,0,23.10267,114.39671,1,2,1#
 *        GFENCE,1,ON,1,23.10267,114.39671,23.20267,114.49671#
 *        GFENCE,1,ON,1,23.10267,114.39671,23.20267,114.59671,2,1#
 *  modification history
 * ----------------------------------------
 * v1.0  , 25-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_gfence(CMD_DATA_STRUCT *cmd)
{
#if 1
	;
#else
    nvram_electronic_fence_struct fence = {0};
    track_gps_data_struct *gpsPoint = NULL;
    kal_bool autoLatLon = KAL_FALSE;
    U8 j;
    char msg[50];
    int sn = 0, tmp, i = 1;

    if(cmd->part == 0)
    {
        for(j = 0; j < TRACK_DEFINE_FENCE_SUM; j++)
        {
            if(j == TRACK_DEFINE_FENCE_SUM - 1)
            {
                sprintf(msg, "fence%d:%s", j + 1, ON_OFF(G_parameter.fence[j].sw));
            }
            else
            {
                sprintf(msg, "fence%d:%s,", j + 1, ON_OFF(G_parameter.fence[j].sw));
            }
            strcat(cmd->rsp_msg, msg);
        }
        return;
    }
    if(track_cust_get_work_mode() == WORK_MODE_3)
    {
        snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, string3_en);
        return;
    }
    sn = track_fun_atoi(cmd->pars[i]) - 1;
    i++;
    if(sn < 0 || sn > TRACK_DEFINE_FENCE_SUM - 1)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 2 (1-%d)", TRACK_DEFINE_FENCE_SUM);
        return;
    }

    if(cmd->part == 1)
    {
        if(G_parameter.fence[sn].sw)
        {
            char NS[2] = {0}, EW[2] = {0}, NS2[2] = {0}, EW2[2] = {0}, in_out[10] = {0};
            float lat, lon, lat2, lon2;
            if(G_parameter.fence[sn].lat >= 0)
            {
                if(G_parameter.fence[sn].lat != 0) *NS = 'N';
                lat = G_parameter.fence[sn].lat;
            }
            else
            {
                if(G_parameter.fence[sn].lat != 0) *NS = 'S';
                lat = -G_parameter.fence[sn].lat;
            }

            if(G_parameter.fence[sn].lon >= 0)
            {
                if(G_parameter.fence[sn].lon != 0) *EW = 'E';
                lon = G_parameter.fence[sn].lon;
            }
            else
            {
                if(G_parameter.fence[sn].lon != 0) *EW = 'W';
                lon = -G_parameter.fence[sn].lon;
            }
            if(G_parameter.fence[sn].in_out == 0)
                sprintf(in_out, "IN");
            else if(G_parameter.fence[sn].in_out == 1)
                sprintf(in_out, "OUT");
            else if(G_parameter.fence[sn].in_out == 2)
                sprintf(in_out, "IN or OUT");
            if(G_parameter.fence[sn].square)
            {
                if(G_parameter.fence[sn].lat2 >= 0)
                {
                    if(G_parameter.fence[sn].lat2 != 0) *NS2 = 'N';
                    lat2 = G_parameter.fence[sn].lat2;
                }
                else
                {
                    if(G_parameter.fence[sn].lat2 != 0) *NS2 = 'S';
                    lat2 = -G_parameter.fence[sn].lat2;
                }
                if(G_parameter.fence[sn].lon2 >= 0)
                {
                    if(G_parameter.fence[sn].lon2 != 0) *EW2 = 'E';
                    lon2 = G_parameter.fence[sn].lon2;
                }
                else
                {
                    if(G_parameter.fence[sn].lon2 != 0) *EW2 = 'W';
                    lon2 = -G_parameter.fence[sn].lon2;
                }
                sprintf(cmd->rsp_msg, "Fence %d Type:Square, %s, Latitude1:%s%.6f, Longitude1:%s%.6f, Latitude2:%s%.6f, Longitude2:%s%.6f, in out:%s, alarm type:%d",
                        sn + 1, ON_OFF(G_parameter.fence[sn].sw),
                        NS, lat, EW, lon,
                        NS2, lat2, EW2, lon2,
                        in_out, G_parameter.fence[sn].alarm_type);
            }
            else
            {
                sprintf(cmd->rsp_msg, "Fence %d Type:Circle, %s, Latitude:%s%.6f, Longitude:%s%.6f, radius:%dm, in out:%s, alarm type:%d",
                        sn + 1, ON_OFF(G_parameter.fence[sn].sw),
                        NS, lat, EW, lon, G_parameter.fence[sn].radius * 100,
                        in_out, G_parameter.fence[sn].alarm_type);
            }
        }
        else
        {
            sprintf(cmd->rsp_msg, "%s %d:OFF" , cmd->pars[0], sn + 1);
        }
        return;
    }
    memcpy(&fence, &G_parameter.fence[sn], sizeof(nvram_electronic_fence_struct));
    if(!strcmp(cmd->pars[i], "ON"))
    {
        char *lat1, *lon1, *lat2, *lon2;
        fence.sw = 1;
        i++;
        LOGD(L_APP, L_V6, "%d,%d", fence.sw, cmd->part);
        tmp = track_fun_atoi(cmd->pars[i++]);
        if(tmp != 0 && tmp != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 3 (0/1)");
            return;
        }
        fence.square = tmp;

        if(fence.square == 0)
        {
            //圆形
            if(cmd->part < 6 || cmd->part > 8)
            {
                sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
                return;
            }
            lat1 = cmd->pars[i];
            lon1 = cmd->pars[i + 1];
            if((!strcmp(lat1, "0") || *lat1 == 0) && (!strcmp(lon1, "0") || *lon1 == 0))
            {
                if(track_cust_gps_status() == GPS_STAUS_OFF)
                {
                    return_message(
                        cmd,
                        "GPS is not working, Please open the GPS first!",
                        "当前GPS未开启，请开启GPS定位！");
                    return;
                }
                else if(track_cust_gps_status() < GPS_STAUS_2D)
                {
                    return_message(
                        cmd,
                        "GPS not fixed, Please set again after GPS fixed!",
                        "当前GPS未定位，请在GPS定位后设置！");
                    return;
                }
                fence.lat = 0;
                fence.lon = 0;
                gpsPoint = track_drv_get_gps_data();
                if(gpsPoint->gprmc.NS == 'S')
                    fence.lat = -gpsPoint->gprmc.Latitude;
                else
                    fence.lat = gpsPoint->gprmc.Latitude;
                if(gpsPoint->gprmc.EW == 'W')
                    fence.lon = -gpsPoint->gprmc.Longitude;
                else
                    fence.lon = gpsPoint->gprmc.Longitude;
                autoLatLon = KAL_TRUE;
            }
            else if(strlen(lat1) > 0 || strlen(lon1) > 0)
            {
                if(!enter_lat_lon(1, lat1, &fence.lat))
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 4!");
                    return;
                }
                if(!enter_lat_lon(0, lon1, &fence.lon))
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 5!");
                    return;
                }
                if(fence.lat == 0 || fence.lon == 0)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 4or Parameter 5 !\r\nlat:%s, lon:%s, (%f,%f)", &lat1[1], &lon1[1], fence.lat, fence.lon);
                    return;
                }
                if(fence.lat > 90 || fence.lat < -90 || fence.lon > 180 || fence.lon < -180)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 4 or Parameter 5.");
                    return;
                }
            }
            else
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 4 or Parameter 5!");
                return;
            }
            i += 2;
            if(cmd->part >= i)
            {
                tmp = track_fun_atoi(cmd->pars[i]);
                if(tmp < 1 || tmp > 9999)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 6 (1-9999) (Unit: hundred meters)");
                    return;
                }
                fence.radius = tmp;
            }
            i++;
            //fence.lat2 = 0;
            //fence.lon2 = 0;
        }
        else if(fence.square == 1)
        {
            //方形
            if(cmd->part < 7 || cmd->part > 9)
            {
                sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
                return;
            }
            lat1 = cmd->pars[i];
            lon1 = cmd->pars[i + 1];
            lat2 = cmd->pars[i + 2];
            lon2 = cmd->pars[i + 3];
            LOGD(L_CMD, L_V5, "%s;%s;%s;%s", cmd->pars[i], cmd->pars[i + 1], cmd->pars[i + 2], cmd->pars[i + 3]);
            LOGD(L_CMD, L_V5, "%s;%s;%s;%s", lat1, lon1, lat2, lon2);
            if(strlen(lat1) > 0 && strlen(lon1) > 0 && strlen(lat2) > 0 && strlen(lon2) > 0)
            {
                if(!enter_lat_lon(1, lat1, &fence.lat))
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 4!");
                    return;
                }
                if(!enter_lat_lon(0, lon1, &fence.lon))
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 5!");
                    return;
                }
                if(!enter_lat_lon(1, lat2, &fence.lat2))
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 6!");
                    return;
                }
                if(!enter_lat_lon(0, lon2, &fence.lon2))
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 7!");
                    return;
                }
                if(fence.lat == 0 || fence.lon == 0 || fence.lat2 == 0 || fence.lon2 == 0)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameters 4 to 7 can not be zero!");
                    return;
                }
                if(fence.lat > 90 || fence.lat < -90 || fence.lon > 180 || fence.lon < -180
                        || fence.lat2 > 90 || fence.lat2 < -90 || fence.lon2 > 180 || fence.lon2 < -180)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameters 4 to 7.");
                    return;
                }
                LOGD(L_CMD, L_V5, "%.6f;%.6f;%.6f;%.6f", fence.lat, fence.lon, fence.lat2, fence.lon2);
                if(fence.lat == fence.lat2 || fence.lon == fence.lon2)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameters 4 and 6 of the same or parameters 4 and 6 of the same!");
                    return;
                }
            }
            else
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 4 to 6!");
                return;
            }
            i += 4;
            //fence.radius = 0;
        }
        fence.in_out = OTA_NVRAM_EF_PARAMETER_DEFAULT->fence[sn].in_out;
        if(cmd->part >= i)
        {
            if(!strcmp("IN", cmd->pars[i]))
            {
                fence.in_out = 0;
            }
            else if(!strcmp("OUT", cmd->pars[i]))
            {
                fence.in_out = 1;
            }
            else if(strlen(cmd->pars[i]) == 0)
            {
                fence.in_out = 2;
            }
            else
            {
                sprintf(cmd->rsp_msg, "Error: Parameter %d (IN/OUT)", i);
                return;
            }
        }
        i++;
        fence.alarm_type = OTA_NVRAM_EF_PARAMETER_DEFAULT->fence[sn].alarm_type;
        if(cmd->part >= i)
        {
            tmp = track_fun_atoi(cmd->pars[i]);
            if(tmp != 0 && tmp != 1 && tmp != 2 && tmp != 3)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter %d (0/1/2/3)", i);
                return;
            }
            fence.alarm_type = tmp;
        }
    }
    else if(!strcmp(cmd->pars[i], "OFF"))
    {
        if(cmd->part != 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        fence.sw = 0;
        fence.lat = 0;
        fence.lon = 0;
        fence.lat2 = 0;
        fence.lon2 = 0;
        fence.in_out = OTA_NVRAM_EF_PARAMETER_DEFAULT->fence[sn].in_out;
        fence.alarm_type = OTA_NVRAM_EF_PARAMETER_DEFAULT->fence[sn].alarm_type;
        if(G_parameter.lang == 1 && cmd->return_sms.cm_type != CM_ONLINE && cmd->return_sms.cm_type != CM_ONLINE2)
        {
            char buf[320] = {0};
            int ret;
            char *tmp = NULL, *str_in = "入", *str_out = "出", *str_in_and_out = "出入";
            if(fence.in_out == 0)
            {
                tmp = str_in;
            }
            else if(fence.in_out == 2)
            {
                tmp = str_in_and_out;
            }
            else
            {
                tmp = str_out;
            }
            if(fence.square == 0)
            {
                sprintf(buf, "圆形围栏%d已关闭!", sn + 1);
            }
            else
            {
                sprintf(buf, "矩形围栏%d已关闭!", sn + 1);
            }
            if(cmd->return_sms.cm_type == CM_AT)
            {
                cmd->rsp_length = strlen(buf);
                memcpy(cmd->rsp_msg, buf, cmd->rsp_length);
                cmd->return_sms.reply_character_encode = 2;
            }
            else
            {
                cmd->rsp_length = track_fun_GB2312_to_UTF16BE(buf, strlen(buf), cmd->rsp_msg, 320);
                cmd->return_sms.reply_character_encode = 1;
            }
        }
        else
        {
            char *tmp = NULL, *str_in = "IN", *str_out = "OUT", *str_in_and_out = "IN or OUT";
            if(fence.in_out == 0)
            {
                tmp = str_in;
            }
            else if(fence.in_out == 2)
            {
                tmp = str_in_and_out;
            }
            else
            {
                tmp = str_out;
            }
            if(fence.square == 0)
            {
                sprintf(cmd->rsp_msg, "Disable Circle Fence %d set successfully! ", sn + 1);
            }
            else
            {
                sprintf(cmd->rsp_msg, "Disable Square Fence %d set successfully!", sn + 1);
            }
        }
    }
    else if(!strcmp(cmd->pars[i], "C") && fence.square == 0)
    {
        float tmp, lat, lon;
        tmp = fence.radius * 100;
        tmp = tmp / 111000;
        lat = fence.lat;
        lon = fence.lon;
        fence.lat = lat - tmp;
        fence.lon = lon + tmp;
        fence.lat2 = lat + tmp;
        fence.lon2 = lon - tmp;
        fence.square = 1;
        sprintf(cmd->rsp_msg, "Fence %d set successfully!FenceType:Square, %s, Latitude1:%.6f, Longitude1:%.6f, Latitude2:%.6f, Longitude2:%.6f, in out:%d, alarm type:%d",
                ON_OFF(fence.sw),
                fence.lat, fence.lon,
                fence.lat2, fence.lon2,
                fence.in_out, fence.alarm_type);
    }
    else if(!strcmp(cmd->pars[i], "SEE"))
    {
        if(G_parameter.fence[sn].lat > 0 && G_parameter.fence[sn].lon > 0)
        {
            float res = 0;
            if(track_cust_gps_status() >= GPS_STAUS_2D)
            {
                res = track_fun_get_GPS_2Points_distance(
                          G_parameter.fence[sn].lat, G_parameter.fence[sn].lon,
                          track_drv_get_gps_RMC()->Latitude, track_drv_get_gps_RMC()->Longitude);
                sprintf(cmd->rsp_msg, "Distance from the origin : %.2fM", res);
            }
            else
            {
                sprintf(cmd->rsp_msg, "No location!");
            }
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Origin of longitude and latitude is no set!");
        }
        return;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 2 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.fence[sn], &fence, sizeof(nvram_electronic_fence_struct));
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    if(fence.sw == 1 && !strlen(cmd->rsp_msg))
    {
        applib_time_struct time = {0};
        char NS, EW, NS2, EW2;
        float lat, lon, lat2, lon2;
        if(fence.lat >= 0)
        {
            NS = 'N';
            lat = fence.lat;
        }
        else
        {
            NS = 'S';
            lat = -fence.lat;
        }
        if(fence.lon >= 0)
        {
            EW = 'E';
            lon = fence.lon;
        }
        else
        {
            EW = 'W';
            lon = -fence.lon;
        }
        if(fence.square == 1)
        {
            if(fence.lat2 >= 0)
            {
                NS2 = 'N';
                lat2 = fence.lat2;
            }
            else
            {
                NS2 = 'S';
                lat2 = -fence.lat2;
            }
            if(fence.lon2 >= 0)
            {
                EW2 = 'E';
                lon2 = fence.lon2;
            }
            else
            {
                EW2 = 'W';
                lon2 = -fence.lon2;
            }
        }
        /* GPS数据中的时间加上时区校正 */
        if(track_cust_is_upload_UTC_time())
        {
            track_drv_utc_timezone_to_rtc(&time, (applib_time_struct*)&gpsPoint->gprmc.Date_Time, G_parameter.zone);
        }
        else
        {
            memcpy(&time, &gpsPoint->gprmc.Date_Time, sizeof(applib_time_struct));
        }
        if(G_parameter.lang == 1 && cmd->return_sms.cm_type != CM_ONLINE && cmd->return_sms.cm_type != CM_ONLINE2)
        {
            char buf[320] = {0};
            int ret;
            char *tmp = NULL, *str_in = "入", *str_out = "出", *str_in_and_out = "出入";
            if(fence.in_out == 0)
            {
                tmp = str_in;
            }
            else if(fence.in_out == 2)
            {
                tmp = str_in_and_out;
            }
            else
            {
                tmp = str_out;
            }
            if(autoLatLon)
            {
                sprintf(buf, "OK！围栏%d已自动获取圆心位置：%c%.6f,%c%.6f，时间：%.2d-%.2d-%.2d %.2d:%.2d:%.2d",
                        sn + 1, NS, lat, EW, lon,
                        time.nYear, time.nMonth, time.nDay,
                        time.nHour, time.nMin, time.nSec);

            }
            else if(fence.square == 0)
            {
                sprintf(buf, "围栏%d设置成功！圆形围栏，报警已开启；圆心：%c%.6f，%c%.6f，半径：%d米，%s围栏报警，报警类型：%d",
                        sn + 1, NS, lat, EW, lon,
                        fence.radius * 100, tmp, fence.alarm_type);
            }
            else
            {
                sprintf(buf, "围栏%d设置成功！矩形围栏，报警已开启；纬度1：%c%.6f，经度1：%c%.6f，纬度2：%c%.6f，经度2：%c%.6f；%s围栏报警，报警类型：%d",
                        sn + 1, NS, lat, EW, lon, NS2, lat2, EW2, lon2,
                        tmp, fence.alarm_type);
            }
            if(cmd->return_sms.cm_type == CM_AT)
            {
                cmd->rsp_length = strlen(buf);
                memcpy(cmd->rsp_msg, buf, cmd->rsp_length);
                cmd->return_sms.reply_character_encode = 2;
            }
            else
            {
                cmd->rsp_length = track_fun_GB2312_to_UTF16BE(buf, strlen(buf), cmd->rsp_msg, 320);
                cmd->return_sms.reply_character_encode = 1;
            }
        }
        else
        {
            char *tmp = NULL, *str_in = "IN", *str_out = "OUT", *str_in_and_out = "IN or OUT";
            if(fence.in_out == 0)
            {
                tmp = str_in;
            }
            else if(fence.in_out == 2)
            {
                tmp = str_in_and_out;
            }
            else
            {
                tmp = str_out;
            }
            if(autoLatLon)
            {
                sprintf(cmd->rsp_msg, "OK!The Fence %d Automatically obtain latitude:%c%.6f Longitude:%c%.6f, in the time %.2d-%.2d-%.2d %.2d:%.2d:%.2d",
                        sn + 1, NS, lat, EW, lon,
                        time.nYear, time.nMonth, time.nDay,
                        time.nHour, time.nMin, time.nSec);
            }
            else if(fence.square == 0)
            {
                sprintf(cmd->rsp_msg, "Fence %d set successfully! FenceType:Circle, ON, Latitude:%c%.6f, Longitude:%c%.6f, radius:%dm, in out:%s, alarm type:%d.",
                        sn + 1, NS, lat, EW, lon,
                        fence.radius * 100, tmp, fence.alarm_type);
            }
            else
            {
                sprintf(cmd->rsp_msg, "Fence %d set successfully! FenceType:Square, ON, Latitude1:%c%.6f, Longitude1:%c%.6f, Latitude2:%c%.6f, Longitude2:%c%.6f, in out:%s, alarm type:%d.",
                        sn + 1, NS, lat, EW, lon, NS2, lat2, EW2, lon2,
                        tmp, fence.alarm_type);
            }
        }
    }
    if(!strlen(cmd->rsp_msg) && cmd->rsp_length == 0) sprintf(cmd->rsp_msg, "OK!");
    track_cust_module_fence_cmd_update(sn);
#endif
}
#if defined(__NT31__)
static void cmd_clearalm(CMD_DATA_STRUCT *cmd)
{
    G_realtime_data.power_fails_flg = 0;
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    track_stop_timer(TRACK_CUST_POWER_FAILS_TIMER_ID);
    sprintf(cmd->rsp_msg, "OK!");

}
/******************************************************************************
 *  Function    -  cmd_power_fails_alarm
 *
 *  Purpose     -  断电报警
 *
 *  Description -
        POWERALM,<A>[,T[,M[,S]]]#
            A =ON/OFF；默认值：ON
            M =0～2；0 仅GPRS，1 SMS+GPRS，2 GPRS+SMS+电话；默认值：2；
            T1=2～3600，单位：秒，默认值：5,通电时间
            T2=2～3600，单位：秒；默认值：5，断开时间
            T3=1～3600 秒；ACC ON to OFF 跳变禁止报警时间
        POWERALM,OFF#
            关闭断电报警
        POWERALM#
            查询已设置的参数
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_poweralm(CMD_DATA_STRUCT *cmd)
{
    nvram_power_fails_alarm_struct alarm = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d,%d,%d,%d", cmd->pars[0],
                ON_OFF(G_parameter.power_fails_alarm.sw),
                G_parameter.power_fails_alarm.alarm_type,
                G_parameter.power_fails_alarm.delay_time_off,
                G_parameter.power_fails_alarm.delay_time_on,
                G_parameter.power_fails_alarm.delay_time_acc_on_to_off,
                G_parameter.power_fails_alarm.send_alarm_time);
        return;
    }
    memcpy(&alarm, &G_parameter.power_fails_alarm, sizeof(nvram_power_fails_alarm_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 6)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 1;
        if(cmd->part > 1)
        {
            alarm.alarm_type = track_fun_atoi(cmd->pars[2]);
            if(alarm.alarm_type < 0 || alarm.alarm_type > 3)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1/2/3)");
                return;
            }
        }
        if(cmd->part > 2)
        {
            alarm.delay_time_off = track_fun_atoi(cmd->pars[3]);
            alarm.delay_time_off = track_fun_atoi(cmd->pars[3]);
            if(alarm.delay_time_off < 2 || alarm.delay_time_off > 3600)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (2 ~ 3600)");
                return;
            }
        }
        if(cmd->part > 3)
        {
            alarm.delay_time_on = track_fun_atoi(cmd->pars[4]);
            if(alarm.delay_time_on < 1 || alarm.delay_time_on > 3600)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 4 (1 ~ 3600)");
                return;
            }
        }
        if(cmd->part > 4)
        {
            alarm.delay_time_acc_on_to_off = track_fun_atoi(cmd->pars[5]);
            if(alarm.delay_time_acc_on_to_off < 0 || alarm.delay_time_acc_on_to_off > 3600)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 5 (0 ~ 3600)");
                return;
            }
        }
        if(cmd->part > 5)
        {
            alarm.send_alarm_time = track_fun_atoi(cmd->pars[6]);
            if((alarm.send_alarm_time < 5 || alarm.send_alarm_time > 3600) && alarm.send_alarm_time != 0)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 6 (0,5 ~ 3600)");
                return;
            }
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.power_fails_alarm, &alarm, sizeof(nvram_power_fails_alarm_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

#else
/******************************************************************************
 *  Function    -  cmd_power_fails_alarm
 *
 *  Purpose     -  断电报警
 *
 *  Description -
        POWERALM,<A>[,T[,M[,S]]]#
            A =ON/OFF；默认值：ON
            M =0～2；0 仅GPRS，1 SMS+GPRS，2 GPRS+SMS+电话；默认值：2；
            T1=2～3600，单位：秒，默认值：5,通电时间
            T2=2～3600，单位：秒；默认值：5，断开时间
            T3=1～3600 秒；ACC ON to OFF 跳变禁止报警时间
        POWERALM,OFF#
            关闭断电报警
        POWERALM#
            查询已设置的参数
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_poweralm(CMD_DATA_STRUCT *cmd)
{
    nvram_power_fails_alarm_struct alarm = {0};

#if defined (__NO_ACC__) || defined(__NT55__)
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d,%d", cmd->pars[0],
                ON_OFF(G_parameter.power_fails_alarm.sw),
                G_parameter.power_fails_alarm.alarm_type,
                G_parameter.power_fails_alarm.delay_time_off,
                G_parameter.power_fails_alarm.delay_time_on);
        return;
    }
#else
if(cmd->part == 0)
{
    sprintf(cmd->rsp_msg, "%s:%s,%d,%d,%d,%d", cmd->pars[0],
            ON_OFF(G_parameter.power_fails_alarm.sw),
            G_parameter.power_fails_alarm.alarm_type,
            G_parameter.power_fails_alarm.delay_time_off,
            G_parameter.power_fails_alarm.delay_time_on,
            G_parameter.power_fails_alarm.delay_time_acc_on_to_off);
    return;
}
#endif

    memcpy(&alarm, &G_parameter.power_fails_alarm, sizeof(nvram_power_fails_alarm_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 5)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 1;
        if(cmd->part > 1)
        {
            alarm.alarm_type = track_fun_atoi(cmd->pars[2]);
#if defined(__EL100__)
            if(alarm.alarm_type != 0)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (Only 0)");
                return;
            }
#else
if(alarm.alarm_type < 0 || alarm.alarm_type > 3)
{
    sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1/2/3)");
    return;
}
#endif
        }
        if(cmd->part > 2)
        {
            alarm.delay_time_off = track_fun_atoi(cmd->pars[3]);
            if(alarm.delay_time_off < 2 || alarm.delay_time_off > 3600)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (2 ~ 3600)");
                return;
            }
        }
        if(cmd->part > 3)
        {
            alarm.delay_time_on = track_fun_atoi(cmd->pars[4]);
            if(alarm.delay_time_on < 1 || alarm.delay_time_on > 3600)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 4 (1 ~ 3600)");
                return;
            }
        }
        if(cmd->part > 4)
        {
            alarm.delay_time_acc_on_to_off = track_fun_atoi(cmd->pars[5]);
            if(alarm.delay_time_acc_on_to_off < 0 || alarm.delay_time_acc_on_to_off > 3600)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 5 (0 ~ 3600)");
                return;
            }
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.power_fails_alarm, &alarm, sizeof(nvram_power_fails_alarm_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
#if defined(__PARAM_CHANGE_UPDATE_SERVER__)
    track_cust_paket_9404_handle();
#endif
}
#endif

/******************************************************************************
 *  Function    -  cmd_low_power_alarm
 *
 *  Purpose     -  低电报警
 *
 *  Description -
        BATALM,<A>[,M]#
            A=ON/OFF；默认值：ON
            M=0～1；默认值：1；
        BATALM,OFF#
            关闭电池低电报警
        BATALM#
            查询已设置的参数
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_batalm(CMD_DATA_STRUCT *cmd)
{
    nvram_low_power_alarm_struct alarm = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d", cmd->pars[0],
                ON_OFF(G_parameter.low_power_alarm.sw), G_parameter.low_power_alarm.alarm_type);
        return;
    }
    memcpy(&alarm, &G_parameter.low_power_alarm, sizeof(nvram_low_power_alarm_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 1;
        if(cmd->part >= 2)
        {
            alarm.alarm_type = track_fun_atoi(cmd->pars[2]);
#if defined(__ET310__)||defined(__NT36__)||defined(__MT200__) || defined(__NT55__)
            if(alarm.alarm_type < 0 || alarm.alarm_type > 1)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1)");
                return;
            }
#elif defined(__EL100__)
            if(alarm.alarm_type != 0)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (Only 0)");
                return;
            }
#else
            if(alarm.alarm_type < 0 || alarm.alarm_type > 3)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1/2/3)");
                return;
            }
#endif /* __ET310__ */
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.low_power_alarm, &alarm, sizeof(nvram_low_power_alarm_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
#if defined(__PARAM_CHANGE_UPDATE_SERVER__)
    track_cust_paket_9404_handle();
#endif
}

/******************************************************************************
 *  Function    -  cmd_vibrates_alarm
 *
 *  Purpose     -  震动报警
 *
 *  Description -
        SENALM,<A>[,M]#
            A=ON/OFF；默认值：OFF
            M=0/1；报警上报方式，0 仅GPRS，1 SMS+GPRS；默认值：0
        SENALM,OFF#
            关闭震动报警
        SENALM#
            查询已设置的参数
 *
 2016/8/24 11:15:16 经过与谭工沟通，以下面的描述为准：
     在自动设防的状态下，震动报警功能开/关影响到设/撤防状态；
     在手动设防的状态下，震动报警功能开/关不会影响到设防（关闭震动报警会导致虽然处于设防模式，但无法触发震动报警）
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_senalm(CMD_DATA_STRUCT *cmd)
{
    nvram_vibrates_alarm_struct alarm = {0};
    kal_uint8 defences = 0;
    kal_int8 sw_tmp = 0;

    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d", cmd->pars[0],
                ON_OFF(G_parameter.vibrates_alarm.sw), G_parameter.vibrates_alarm.alarm_type);
        return;
    }
    sw_tmp = G_parameter.vibrates_alarm.sw;
    memcpy(&alarm, &G_parameter.vibrates_alarm, sizeof(nvram_vibrates_alarm_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 1;
        if(cmd->part >= 2)
        {
            alarm.alarm_type = track_fun_atoi(cmd->pars[2]);
#if defined(__EL100__)
            if(alarm.alarm_type != 0)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (Only 0)");
                return;
            }
#else
            if(alarm.alarm_type < 0 || alarm.alarm_type > 3)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1/2/3)");
                return;
            }
#endif
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.vibrates_alarm, &alarm, sizeof(nvram_vibrates_alarm_struct));
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
#if defined(__PARAM_CHANGE_UPDATE_SERVER__)
    track_cust_paket_9404_handle();
#endif
#if defined(__GT370__)|| defined (__GT380__)
    /*手持机设防有单独指令控制,震动报警关闭时更新设防状态*/
    if(G_parameter.vibrates_alarm.sw == 0)
    {
        track_cust_defences_cmd_update();
    }
#elif defined(__ET310__)|| defined(__MT200__)||defined(__NT13V__)||defined (__NT17__)
    defences = track_cust_status_defences();
    if(G_realtime_data.defense_mode == 0 && G_parameter.vibrates_alarm.sw != sw_tmp)
    {
        track_cust_defences_cmd_update();
    }
    LOGD(L_APP, L_V5, "defences=%d,%d,%d", defences, sw_tmp, G_parameter.vibrates_alarm.sw);
    if(defences != 0 && G_parameter.vibrates_alarm.sw == 0 && sw_tmp == 1)
    {
        track_cust_check_sos_incall(cmd, 3);
        return;
    }
#else
    //无ACC自动控制的
    track_cust_defences_cmd_update();
#endif
    sprintf(cmd->rsp_msg, "OK!");
}

/******************************************************************************
 *  Function    -  cmd_sensor
 *
 *  Purpose     -  震动参数设置
 *
 *  Description -  SENSOR,<A>[,B][,C]#
 *      A : 检测时间（秒）        取值范围：10-300  默认值：10
 *      B : 报警延时（秒）        取值范围：10-300  默认值：180
 *      C : 最短报警间隔（分）    取值范围：1-3000  默认值：30
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 27-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_sensor2(CMD_DATA_STRUCT *cmd)
{
    nvram_vibrates_alarm_struct alarm = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "SENSOR:%d,%d,%d",
                G_parameter.vibrates_alarm.detection_time, G_parameter.vibrates_alarm.alarm_delay_time,
                G_parameter.vibrates_alarm.alarm_interval);
        return;
    }
    else if(cmd->part > 3)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    memcpy(&alarm, &G_parameter.vibrates_alarm, sizeof(nvram_vibrates_alarm_struct));
    alarm.detection_time = track_fun_atoi(cmd->pars[1]);
#if defined(__ET310__)
    if(alarm.detection_time < 1 || alarm.detection_time > 300)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (1 to 300)");
        return;
    }
#else
    if(alarm.detection_time < 10 || alarm.detection_time > 300)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (10 to 300)");
        return;
    }
#endif /* __ET310__ */
    if(cmd->part >= 2)
    {
        alarm.alarm_delay_time = track_fun_atoi(cmd->pars[2]);
#if defined(__ET310__) || defined(__MT200__)||defined (__NT13V__)
        if(alarm.alarm_delay_time < 1 || alarm.alarm_delay_time > 300)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (1 to 300)");
            return;
        }
#elif defined (__NT33__)
        if(alarm.alarm_delay_time < 1 || alarm.alarm_delay_time > 10)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (1 to 10)");
            return;
        }
#else
        if(alarm.alarm_delay_time < 10 || alarm.alarm_delay_time > 300)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (10 to 300)");
            return;
        }
#endif
    }
    if(cmd->part >= 3)
    {
        alarm.alarm_interval = track_fun_atoi(cmd->pars[3]);
#if defined(__ET310__) || defined(__MT200__)
        if(alarm.alarm_interval < 10 || alarm.alarm_interval > 180000)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 3 (10 to 180000)");
            return;
        }
        track_cust_shocks_quiet_time_update(alarm.alarm_interval);  // 更新静默时间
#else
        if(alarm.alarm_interval < 1 || alarm.alarm_interval > 3000)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 3 (1 to 3000)");
            return;
        }
        track_cust_shocks_quiet_time_update(alarm.alarm_interval);  // 更新静默时间
#endif
    }
    memcpy(&G_parameter.vibrates_alarm, &alarm, sizeof(nvram_vibrates_alarm_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

static void cmd_sensor(CMD_DATA_STRUCT *cmd)
{
    nvram_vibrates_alarm_struct alarm = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "SENSOR:%d,%d,%d",
                G_parameter.vibrates_alarm.detection_time, G_parameter.vibrates_alarm.alarm_delay_time,
                G_parameter.vibrates_alarm.alarm_interval / 60);
        return;
    }
    else if(cmd->part > 3)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    memcpy(&alarm, &G_parameter.vibrates_alarm, sizeof(nvram_vibrates_alarm_struct));
    alarm.detection_time = track_fun_atoi(cmd->pars[1]);
#if defined(__ET310__)||defined(__MT200__)||defined (__NT13V__)
    if(alarm.detection_time < 1 || alarm.detection_time > 300)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (1 to 300)");
        return;
    }
#else
    if(alarm.detection_time < 10 || alarm.detection_time > 300)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (10 to 300)");
        return;
    }
#endif /* __ET310__ */
    if(cmd->part >= 2)
    {
        alarm.alarm_delay_time = track_fun_atoi(cmd->pars[2]);
        if(alarm.alarm_delay_time < 10 || alarm.alarm_delay_time > 300)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (10 to 300)");
            return;
        }
    }
    if(cmd->part >= 3)
    {
        alarm.alarm_interval = track_fun_atoi(cmd->pars[3]);

        if(alarm.alarm_interval < 1 || alarm.alarm_interval > 3000)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 3 (1 to 3000)");
            return;
        }
        alarm.alarm_interval = alarm.alarm_interval * 60;
        track_cust_shocks_quiet_time_update(alarm.alarm_interval);  // 更新静默时间
    }
    memcpy(&G_parameter.vibrates_alarm, &alarm, sizeof(nvram_vibrates_alarm_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

/******************************************************************************
 *  Function    -  cmd_gmt
 *
 *  Purpose     -  时区设置
 *
 *  Description -  GMT,<E/W>,<0～12>[,0/15/30/45]
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 24-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_gmt(CMD_DATA_STRUCT *cmd)
{
    nvram_gps_time_zone_struct zone = {0};
    int value;
    kal_bool flag = 1;
    if(cmd->part == 0)
    {
        if(G_parameter.zone.timezone_auto == 1)
        {
            sprintf(cmd->rsp_msg, "%s:%c,%d,%d (AUTO)", cmd->pars[0],
                    G_parameter.zone.zone, G_parameter.zone.time, G_parameter.zone.time_min);
        }
        else
        {
            sprintf(cmd->rsp_msg, "%s:%c,%d,%d", cmd->pars[0],
                    G_parameter.zone.zone, G_parameter.zone.time, G_parameter.zone.time_min);
        }
        return;
    }
    else if(cmd->part < 1 || cmd->part > 3)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    memcpy(&zone, &G_parameter.zone, sizeof(nvram_gps_time_zone_struct));
    if(!strcmp(cmd->pars[1], "AUTO"))
    {
        zone.timezone_auto = 1;
    }
    else if(!strcmp(cmd->pars[1], "E") || !strcmp(cmd->pars[1], "W"))
    {
        zone.timezone_auto = 0;
        zone.zone = cmd->pars[1][0];
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (E/W)");
        return;
    }
    if(cmd->part >= 2)
    {
        value = track_fun_atoi(cmd->pars[2]);
        if(value < 0 || value > 12)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (0 to 12)");
            return;
        }
        zone.time = value;
        flag = 0;
    }
    if(cmd->part == 3)
    {
        value = track_fun_atoi(cmd->pars[3]);
        if(value != 0 && value != 15 && value != 30 && value != 45)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 3 (0/15/30/45)");
            return;
        }
        zone.time_min = value;
    }
    memcpy(&G_parameter.zone, &zone, sizeof(nvram_gps_time_zone_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

static void cmd_extbatalm(CMD_DATA_STRUCT *cmd)
{
    int value;
    nvram_power_extbatalm_struct extbatalm = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d,%d,%d", cmd->pars[0], ON_OFF(G_parameter.power_extbatalm.sw),
                G_parameter.power_extbatalm.alarm_type, G_parameter.power_extbatalm.threshold,
                G_parameter.power_extbatalm.recover_threshold, G_parameter.power_extbatalm.detection_time);
        return;
    }
    memcpy(&extbatalm, &G_parameter.power_extbatalm, sizeof(nvram_power_extbatalm_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 5)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        extbatalm.sw = 1;
        if(cmd->part >= 2)
        {
            value = track_fun_atoi(cmd->pars[2]);
            if(value != 0 && value != 1)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1)");
                return;
            }
            extbatalm.alarm_type = value;
        }
        if(cmd->part >= 3)
        {
            value = track_fun_atoi(cmd->pars[3]);
            if(value < 10 || value > 360)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (10～360)");
                return;
            }
            extbatalm.threshold = value;
        }
        if(cmd->part >= 4)
        {
            value = track_fun_atoi(cmd->pars[4]);
            if(value < 10 || value > 360)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 4 (10～360)");
                return;
            }
            if(value <= extbatalm.threshold)
            {
                sprintf(cmd->rsp_msg, "Error: The fourth parameter can not be less than the third parameter");
                return;
            }
            extbatalm.recover_threshold = value;
        }
        if(cmd->part >= 5)
        {
            value = track_fun_atoi(cmd->pars[5]);
            if(value < 1 || value > 300)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 5 (1～300)");
                return;
            }
            extbatalm.detection_time = value;
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        extbatalm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.power_extbatalm, &extbatalm, sizeof(nvram_power_extbatalm_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
#if defined(__PARAM_CHANGE_UPDATE_SERVER__)
    track_cust_paket_9404_handle();
#endif
}

static void cmd_extbatacc(CMD_DATA_STRUCT *cmd)
{
#if defined( __EXT_VBAT_ADC__)
    int value;
    nvram_ext_vbat_check_acc_struct vbat_check_acc = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:L:%d,H:%d, The current value:%d", cmd->pars[0],
                G_parameter.vbat_check_acc.acc_l_threshold_vbat,
                G_parameter.vbat_check_acc.acc_h_thresholdvbat,
                track_drv_get_external_batter(1));
        return;
    }
    memcpy(&vbat_check_acc, &G_parameter.vbat_check_acc, sizeof(nvram_ext_vbat_check_acc_struct));
    if(cmd->part == 1 && !strcmp(cmd->pars[1], "HIGH"))
    {
        value = track_drv_get_external_batter(1) / 100000 - 1;
        vbat_check_acc.acc_h_thresholdvbat = value;
    }
    else if(cmd->part == 1 && !strcmp(cmd->pars[1], "LOW"))
    {
        value = track_drv_get_external_batter(1) / 100000 + 1;
        vbat_check_acc.acc_l_threshold_vbat = value;
    }
    else if(cmd->part == 2)
    {
        value = track_fun_atoi(cmd->pars[1]);
        if(value < 10 || value > 360)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (10～360)");
            return;
        }
        vbat_check_acc.acc_l_threshold_vbat = value;

        value = track_fun_atoi(cmd->pars[2]);
        if(value < 10 || value > 360)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (10～360)");
            return;
        }
        vbat_check_acc.acc_h_thresholdvbat = value;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    memcpy(&G_parameter.vbat_check_acc, &vbat_check_acc, sizeof(nvram_ext_vbat_check_acc_struct));
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    sprintf(cmd->rsp_msg, "OK! %s:L:%d,H:%d, The current value:%d", cmd->pars[0],
            G_parameter.vbat_check_acc.acc_l_threshold_vbat,
            G_parameter.vbat_check_acc.acc_h_thresholdvbat,
            track_drv_get_external_batter(1));
#endif /* __EXT_VBAT_ADC__ */
}

static void cmd_extbatcut(CMD_DATA_STRUCT *cmd)
{
    int value;
    nvram_power_extbatcut_struct extbatcut = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d,%d,%d", cmd->pars[0], ON_OFF(G_parameter.power_extbatcut.sw),
                G_parameter.power_extbatcut.alarm_type, G_parameter.power_extbatcut.threshold,
                G_parameter.power_extbatcut.recover_threshold, G_parameter.power_extbatcut.detection_time);
        return;
    }
    memcpy(&extbatcut, &G_parameter.power_extbatcut, sizeof(nvram_power_extbatcut_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 5)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        extbatcut.sw = 1;
        if(cmd->part >= 2)
        {
            value = track_fun_atoi(cmd->pars[2]);
            if(value != 0 && value != 1)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1)");
                return;
            }
            extbatcut.alarm_type = value;
        }
        if(cmd->part >= 3)
        {
            value = track_fun_atoi(cmd->pars[3]);
            if(value < 10 || value > 360)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (10～360)");
                return;
            }
            extbatcut.threshold = value;
        }
        if(cmd->part >= 4)
        {
            value = track_fun_atoi(cmd->pars[4]);
            if(value < 10 || value > 360)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 4 (10～360)");
                return;
            }
            if(value <= extbatcut.threshold)
            {
                sprintf(cmd->rsp_msg, "Error: The fourth parameter can not be less than the third parameter");
                return;
            }
            extbatcut.recover_threshold = value;
        }
        if(cmd->part >= 5)
        {
            value = track_fun_atoi(cmd->pars[5]);
            if(value < 1 || value > 300)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 5 (1～300)");
                return;
            }
            extbatcut.detection_time = value;
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        extbatcut.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.power_extbatcut, &extbatcut, sizeof(nvram_power_extbatcut_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");

#if defined (__MCU_BJ8M601A_NT13V__)
        //结果同步到单片机
        track_cmd_extbatcut_change_update_to_mcu();
#endif /* __MCU_BJ8M601A_NT13V__ */        
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

static void cmd_gprson(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d(1=ON, 0=OFF)", cmd->pars[0], G_parameter.gprson);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(!strcmp(cmd->pars[1], "1"))
    {
        G_parameter.gprson = 1;
        track_soc_gprs_reconnect((void*)301);
    }
    else if(!strcmp(cmd->pars[1], "0"))
    {
        G_parameter.gprson = 0;
        track_soc_disconnect();
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (0/1)");
        return;
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

static void cmd_link(CMD_DATA_STRUCT *cmd)
{
    int value = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.gprs_obstruction_alarm.link);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 1 || value > 10)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (1-10)");
        return;
    }
    G_parameter.gprs_obstruction_alarm.link = value;
    if(track_soc_conn_valid()) track_soc_gprs_reconnect((void*)23);     //LINK指令设置后，当前处于连接状态，重新建立连接
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

/******************************************************************************
 *  Function    -  cmd_hbt
 *
 *  Purpose     -  心跳包间隔时间设置
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 01-06-2013,  Cml       written
 * v1.1  , 31-07-2013,  zengping  written
 * v1.2  , 01-08-2013,  Cml       written
 * v1.3  , 06-25-2015,  Cml       written
 * ----------------------------------------
*******************************************************************************/
static void cmd_hbt(CMD_DATA_STRUCT *cmd)
{
    int hbt_acc_on = G_parameter.hbt_acc_on;
    int hbt_acc_off = G_parameter.hbt_acc_off;
#if defined(__NO_ACC__)
    if(cmd->part == 0)
    {
        if(G_parameter.hbt_acc_off % 60 == 0)
            sprintf(cmd->rsp_msg, "%s:%dmin", cmd->pars[0], G_parameter.hbt_acc_off / 60);
        else
            sprintf(cmd->rsp_msg, "%s:%dsec", cmd->pars[0], G_parameter.hbt_acc_off);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(cmd->pars[1][0] == 'S')
    {
        hbt_acc_on = track_fun_atoi(&cmd->pars[1][1]);
        if(hbt_acc_on < 10 || hbt_acc_on > 18000)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (10 - 18000)");
            return;
        }
    }
    else
    {
        hbt_acc_on = track_fun_atoi(cmd->pars[1]);
        if(hbt_acc_on < 1 || hbt_acc_on > 300)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (1-300)");
            return;
        }
        hbt_acc_on *= 60;
        hbt_acc_off = hbt_acc_on;
    }
#else
    if(cmd->part == 0)
    {
        if(G_parameter.hbt_acc_on % 60 == 0 && G_parameter.hbt_acc_off % 60 == 0)
            sprintf(cmd->rsp_msg, "%s:%dmin, %dmin", cmd->pars[0], G_parameter.hbt_acc_on / 60, G_parameter.hbt_acc_off / 60);
        else
            sprintf(cmd->rsp_msg, "%s:%dsec, %dsec", cmd->pars[0], G_parameter.hbt_acc_on, G_parameter.hbt_acc_off);
        return;
    }
    else if(cmd->part > 2)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(cmd->pars[1][0] == 'S')
    {
        hbt_acc_on = track_fun_atoi(&cmd->pars[1][1]);
        if(hbt_acc_on < 10 || hbt_acc_on > 18000)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (10sec - 18000sec)");
            return;
        }
    }
    else
    {
        hbt_acc_on = track_fun_atoi(cmd->pars[1]);
        if(hbt_acc_on < 1 || hbt_acc_on > 300)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (1min - 300min)");
            return;
        }
        hbt_acc_on *= 60;
    }
    if(cmd->part == 2)
    {
        if(cmd->pars[2][0] == 'S')
        {
            hbt_acc_off = track_fun_atoi(&cmd->pars[2][1]);
            if(hbt_acc_off < 1 || hbt_acc_off > 300)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (10sec - 18000sec)");
                return;
            }
        }
        else
        {
            hbt_acc_off = track_fun_atoi(cmd->pars[2]);
            if(hbt_acc_off < 1 || hbt_acc_off > 300)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (1min - 300min)");
                return;
            }
            hbt_acc_off *= 60;
        }
    }
#endif /* __NO_ACC__ */
    G_parameter.hbt_acc_off = hbt_acc_off;
    G_parameter.hbt_acc_on = hbt_acc_on;
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
    track_stop_timer(TRACK_CUST_NET_HEARTBEAT_OVER_TIMER_ID);
    heartbeat_packets((void *)112);
}

/******************************************************************************
 *  Function    -  cmd_report
 *
 *  Purpose     -  定位上报方式设置
 *
 *  Description -
        REPORT,<0>,<T1>[,T2]#              // 定时上传
        REPORT,<1>,<D>#                    // 定距上传
        REPORT,<2>,<T1>,<T2>,<D>#          // 定时+定距 开
        REPORT,<3>#                        // 定时+定距 关
            X=0/1；0 定时上传，1 定距上传，2 定时+定距 开，3 定时+定距 关；默认值 0;
            T1=0、5～18000秒；ACC ON 状态下上传间隔；默认值：10
            T2=0、5～18000秒；ACC OFF 状态下上传间隔；默认值：0
            D=0、50～10000米；定距距离；默认值：300
        REPORT#
            查询当前是定时上传还是定距上传，及对应的参数
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 08-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
#if defined(__NT36__)
static void cmd_report(CMD_DATA_STRUCT *cmd)
{
    nvram_gps_work_struct tmp = {0};
    int value = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "Timing report:(%s, acc on:%d, acc off:%d); Fixed pitch:(%s, distance:%d)",
                ON_OFF(G_parameter.gps_work.Fti.sw), G_parameter.gps_work.Fti.interval_acc_on, G_parameter.gps_work.Fti.interval_acc_off,
                ON_OFF(G_parameter.gps_work.Fd.sw), G_parameter.gps_work.Fd.distance);
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 0 || value > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (0-1)");
        return;
    }
    memcpy(&tmp, &G_parameter.gps_work, sizeof(nvram_gps_work_struct));
    switch(value)
    {
        case 0:
            tmp.Fti.sw = 1;
            tmp.Fd.sw = 0;
            if(cmd->part < 1 || cmd->part > 3)
            {
                sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
                return;
            }
            if(cmd->part >= 2)
            {
                value = track_fun_atoi(cmd->pars[2]);
                if((value < 5 || value > 18000) && value != 0)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 2 (0, 5-18000)");
                    return;
                }
                tmp.Fti.interval_acc_on = value;
            }
            if(cmd->part == 3)
            {
                value = track_fun_atoi(cmd->pars[3]);
                if((value < 5 || value > 18000) && value != 0)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 3 (0, 5-18000)");
                    return;
                }
                tmp.Fti.interval_acc_off = value;
            }
            break;
        case 1:
            tmp.Fti.sw = 0;
            tmp.Fd.sw = 1;
            if(cmd->part < 1 || cmd->part > 2)
            {
                sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
                return;
            }
            if(cmd->part >= 2)
            {
                value = track_fun_atoi(cmd->pars[2]);
                if((value < 50 || value > 10000) && value != 0)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 2 (0, 50-10000)");
                    return;
                }
                tmp.Fd.distance = value;
            }
            break;
        case 2:
            tmp.Fti.sw = 1;
            tmp.Fd.sw = 1;
            if(cmd->part < 1 || cmd->part > 4)
            {
                sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
                return;
            }
            if(cmd->part >= 2)
            {
                value = track_fun_atoi(cmd->pars[2]);
                if(value < 0 || value > 18000)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 2 (5-18000)");
                    return;
                }
                tmp.Fti.interval_acc_on = value;
            }
            if(cmd->part >= 3)
            {
                value = track_fun_atoi(cmd->pars[3]);
                if(value < 0 || value > 18000)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 3 (5-18000)");
                    return;
                }
                tmp.Fti.interval_acc_off = value;
            }
            if(cmd->part >= 4)
            {
                value = track_fun_atoi(cmd->pars[4]);
                if((value < 50 || value > 10000) && value != 0)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 4 (0,50-10000)");
                    return;
                }
                tmp.Fd.distance = value;
            }
            break;
        case 3:
            tmp.Fti.sw = 0;
            tmp.Fd.sw = 0;
            if(cmd->part != 1)
            {
                sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
                return;
            }
            break;
    }
    memcpy(&G_parameter.gps_work, &tmp, sizeof(nvram_gps_work_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#endif

static void cmd_gt03_timer(CMD_DATA_STRUCT *cmd)
{
    nvram_gps_work_struct tmp = {0};
    int value = 0;
    kal_bool flag = 1;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d,%d", cmd->pars[0],
                G_parameter.gps_work.Fti.lbs_interval, G_parameter.gps_work.Fti.interval_acc_off);

        return;
    }
    memcpy(&tmp, &G_parameter.gps_work, sizeof(nvram_gps_work_struct));
    tmp.Fti.sw = 1;
    tmp.Fd.sw = 0;

    if(cmd->part > 2)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(strlen(cmd->pars[1]) > 0)
    {
        value = track_fun_atoi(cmd->pars[1]);
        if((value < 1 || value > 60))
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (1-60)");
            return;
        }

        tmp.Fti.lbs_interval = value;
        flag = 0;
    }

    if(cmd->part == 2 && strlen(cmd->pars[2]) > 0)
    {
        value = track_fun_atoi(cmd->pars[2]);
        if((value < 5 || value > 18000) && value != 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (0, 5-18000)");
            return;
        }
        tmp.Fti.interval_acc_off = value;
        tmp.Fti.interval_acc_on = value;
        flag = 0;
    }

    if(flag)
    {
        sprintf(cmd->rsp_msg, "Error: Parameters are as empty!");
        return;
    }
    else
    {
        memcpy(&G_parameter.gps_work, &tmp, sizeof(nvram_gps_work_struct));
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        sprintf(cmd->rsp_msg, "OK!");
    }
}

static void cmd_timer(CMD_DATA_STRUCT *cmd)
{
    nvram_gps_work_struct tmp = {0};
    int value = 0;
    kal_bool flag = 1;
    if(cmd->part == 0)
    {
        //这个值在check同步到服务器，但是没按项目分别处理  chengj
#if defined(__GPS_INTERMITTENT_START__)&&!(defined(__GT370__)|| defined (__GT380__))
        sprintf(cmd->rsp_msg, "%s:%d,%d,%d", cmd->pars[0],
                G_parameter.gps_work.Fti.lbs_interval, G_parameter.gps_work.Fti.interval_acc_off, G_parameter.gps_work.Fti.mode1_gps_time);
#elif defined(__GT370__)|| defined (__GT380__)
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.gps_work.Fti.lbs_interval);
#elif defined(__NT33__)
        //GPS和LBS上报间隔，单位都是秒
        sprintf(cmd->rsp_msg, "%s:%d,%d", cmd->pars[0],
                G_parameter.gps_work.Fti.interval_acc_off, G_parameter.gps_work.Fti.lbs_interval);
#elif defined(__NO_ACC__)
        sprintf(cmd->rsp_msg, "%s:%d,%d", cmd->pars[0],
                G_parameter.gps_work.Fti.lbs_interval, G_parameter.gps_work.Fti.interval_acc_off);
#else
        sprintf(cmd->rsp_msg, "%s:%d,%d", cmd->pars[0],
                G_parameter.gps_work.Fti.interval_acc_on, G_parameter.gps_work.Fti.interval_acc_off);
#endif /* __NO_ACC__ */
        return;
    }
    memcpy(&tmp, &G_parameter.gps_work, sizeof(nvram_gps_work_struct));
    tmp.Fti.sw = 1;
    tmp.Fd.sw = 0;
    if(cmd->part > 2)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
#if defined(__GT370__)|| defined (__GT380__)
    if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(strlen(cmd->pars[1]) > 0)
    {
        value = track_fun_atoi(cmd->pars[1]);
        if((value < 1 || value > 60))
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (1-60)");
            return;
        }
        tmp.Fti.lbs_interval = value;
        flag = 0;
    }
#elif defined(__GPS_INTERMITTENT_START__)
    if(strlen(cmd->pars[1]) > 0)
    {
        value = track_fun_atoi(cmd->pars[1]);
        if((value < 1 || value > 60))
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (1-60)");
            return;
        }
        tmp.Fti.lbs_interval = value;
        flag = 0;
    }
    if(cmd->part >= 2 && strlen(cmd->pars[2]) > 0)
    {
        value = track_fun_atoi(cmd->pars[2]);
        if((value < 5 || value > 18000) && value != 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (0, 5-18000)");
            return;
        }
        tmp.Fti.interval_acc_off = value;
        tmp.Fti.interval_acc_on = value;
        flag = 0;
    }
    if(cmd->part >= 3 && strlen(cmd->pars[3]) > 0)
    {
        value = track_fun_atoi(cmd->pars[3]);
        if((value < 5 || value > 300))
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 3 (5-300)");
            return;
        }
        tmp.Fti.mode1_gps_time = value;
        flag = 0;
    }
#elif defined (__NT33__)
    if(strlen(cmd->pars[1]) > 0)
    {
        value = track_fun_atoi(cmd->pars[1]);
        if((value < 5 || value > 18000) && value != 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (0, 5-18000)");
            return;
        }
        tmp.Fti.interval_acc_off = value;
        tmp.Fti.interval_acc_on = value;
        flag = 0;
    }

    if((cmd->part >= 2) && (strlen(cmd->pars[2]) > 0))
    {
        value = track_fun_atoi(cmd->pars[2]);
        if((value < 5 || value > 18000) && value != 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (0, 5-18000)");
            return;
        }
        tmp.Fti.lbs_interval = value;
        flag = 0;
    }

#elif defined(__NO_ACC__)
    if(strlen(cmd->pars[1]) > 0)
    {
        value = track_fun_atoi(cmd->pars[1]);
        if((value < 0 || value > 60))
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (0-60)");
            return;
        }
        tmp.Fti.lbs_interval = value;
        flag = 0;
    }
    if(cmd->part >= 2 && strlen(cmd->pars[2]) > 0)
    {
        value = track_fun_atoi(cmd->pars[2]);
        if((value < 5 || value > 18000) && value != 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (0, 5-18000)");
            return;
        }
        tmp.Fti.interval_acc_off = value;
        tmp.Fti.interval_acc_on = value;
        flag = 0;
    }
#else
    if(strlen(cmd->pars[1]) > 0)
    {
        value = track_fun_atoi(cmd->pars[1]);
        if((value < 5 || value > 18000) && value != 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (0, 5-18000)");
            return;
        }
        tmp.Fti.interval_acc_on = value;
        flag = 0;
    }
    if(cmd->part >= 2 && strlen(cmd->pars[2]) > 0)
    {
        value = track_fun_atoi(cmd->pars[2]);
        if((value < 5 || value > 18000) && value != 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (0, 5-18000)");
            return;
        }
        tmp.Fti.interval_acc_off = value;
        flag = 0;
    }
#endif /* __NO_ACC__ */
    if(flag)
    {
        sprintf(cmd->rsp_msg, "Error: Parameters are as empty!");
        return;
    }
    else
    {
        memcpy(&G_parameter.gps_work, &tmp, sizeof(nvram_gps_work_struct));
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
#if defined(__GPS_INTERMITTENT_START__)
        if(track_cust_get_work_mode() == WORK_MODE_1)
        {
#if defined(__GT370__)|| defined (__GT380__)

#else
            //track_start_timer(TRACK_CUST_WORK_MODE_GPSUPDATE_TIMER_ID, G_parameter.gps_work.Fti.mode1_gps_time * 60 * 1000, track_cust_gps_work_req, (void *)13);
#endif
        }
        else
        {
            //tr_stop_timer(TRACK_CUST_WORK_MODE_GPSUPDATE_TIMER_ID);
            tr_stop_timer(TRACK_CUST_WORK_MODE_GPSUPDATE_OVERTIME_TIMER_ID);
        }
#endif /* __GPS_INTERMITTENT_START__ */
        sprintf(cmd->rsp_msg, "OK!");
    }
}

static void cmd_distance(CMD_DATA_STRUCT *cmd)
{
    nvram_gps_work_struct tmp = {0};
    int value = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.gps_work.Fd.distance);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    memcpy(&tmp, &G_parameter.gps_work, sizeof(nvram_gps_work_struct));
    tmp.Fti.sw = 0;
    tmp.Fd.sw = 1;
    value = track_fun_atoi(cmd->pars[1]);
    if((value < 50 || value > 10000) && value != 0)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (0, 50-10000)");
        return;
    }
    tmp.Fd.distance = value;
    memcpy(&G_parameter.gps_work, &tmp, sizeof(nvram_gps_work_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}


/******************************************************************************
 *  Function    -  cmd_anglerep
 *
 *  Purpose     -  拐点补传
 *
 *  Description -
        ANGLEREP,<X>,<A>,<B>#
            X=ON/OFF，默认值：ON
            A=30～180度，默认值：60度，偏转角度
            B=2～10秒，默认值：5秒，检测时间
        ANGLEREP,OFF#
            关闭拐点补传
        ANGLEREP#
            查询拐点补传功能是否启用，对应的参数设置值
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 08-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_anglerep(CMD_DATA_STRUCT *cmd)
{
    nvram_gps_anglerep_struct anglerep = {0};
    int value = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d", cmd->pars[0],
                ON_OFF(G_parameter.gps_work.anglerep.sw),
                G_parameter.gps_work.anglerep.angleOfDeflection,
                G_parameter.gps_work.anglerep.detection_time);
        return;
    }
    memcpy(&anglerep, &G_parameter.gps_work.anglerep, sizeof(nvram_gps_anglerep_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part > 3)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        anglerep.sw = 1;
        if(cmd->part >= 2)
        {
            if(strlen(cmd->pars[2]) > 0)
            {
                value = track_fun_atoi(cmd->pars[2]);
                if(value < 5 || value > 180)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 2 (5-180)");
                    return;
                }
                anglerep.angleOfDeflection = value;
            }
            else
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (5-180)");
                return;
            }
        }
        if(cmd->part == 3)
        {
            if(strlen(cmd->pars[3]) > 0)
            {
                value = track_fun_atoi(cmd->pars[3]);
                if(value < 2 || value > 5)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 3 (2-5)");
                    return;
                }
                anglerep.detection_time = value;
            }
            else
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (2-5)");
                return;
            }
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        anglerep.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.gps_work.anglerep, &anglerep, sizeof(nvram_gps_anglerep_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

/******************************************************************************
 *  Function    -  cmd_accrep
 *
 *  Purpose     -  ACC 状态变化补传
 *
 *  Description -
        ACCREP,X#
            X=ON/OFF，状态变化补传，默认开启
        ACCREP#
            查询当前ACC状态变化补传功能开启还是关闭
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 08-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_accrep(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], ON_OFF(G_parameter.gps_work.accrep));
        return;
    }
    else if(cmd->part != 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(!strcmp(cmd->pars[1], "ON"))
        G_parameter.gps_work.accrep = 1;
    else if(!strcmp(cmd->pars[1], "OFF"))
        G_parameter.gps_work.accrep = 0;
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

/******************************************************************************
 *  Function    -  cmd_batch
 *
 *  Purpose     -  GPS 数据打包发送设置
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_batch(CMD_DATA_STRUCT *cmd)
{
    nvram_group_package_struct group_package = {0};
    int value = 0;//, j = 1000 / BACKUP_DATA_PACKET_MAX
    kal_bool flag = KAL_FALSE;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d", cmd->pars[0], ON_OFF(G_parameter.group_package.sw), G_parameter.group_package.at_least_pack);
        return;
    }
    memcpy(&group_package, &G_parameter.group_package, sizeof(nvram_group_package_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part > 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        group_package.sw = 1;
        if(cmd->part > 1)
        {
            value = track_fun_atoi(cmd->pars[2]);
            if(value < 1 || value > 50)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (1-50)");
                return;
            }
            group_package.at_least_pack = value;
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part > 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        group_package.sw = 0;
    }
    else if(!strcmp(cmd->pars[1], "ON2"))
    {
        if(cmd->part == 1)
        {
            sprintf(cmd->rsp_msg, "%s:%s,%d,%d", cmd->pars[0], ON_OFF(G_parameter.group_package.sw), G_parameter.group_package.at_least_pack, G_parameter.group_package.batch_paket);
            return;
        }
        if(cmd->part > 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        if(cmd->part > 1)
        {
            group_package.batch_paket = track_fun_atoi(cmd->pars[2]);
            if(group_package.batch_paket < 1 || group_package.batch_paket > 50)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (2-50)");
                return;
            }
            flag = KAL_TRUE;
        }
        else
        {
            sprintf(cmd->rsp_msg, "%s:batch_paket=%d", cmd->pars[0], G_parameter.group_package.batch_paket);
            return;
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.group_package, &group_package, sizeof(nvram_group_package_struct));
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    if(flag) track_soc_set_batch_paket(G_parameter.group_package.batch_paket);
    sprintf(cmd->rsp_msg, "OK!");
}

/******************************************************************************
 *  Function    -  cmd_sends
 *
 *  Purpose     -  SENSOR 控制 GPS 时间
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_sends(CMD_DATA_STRUCT *cmd)
{
    int value = 0;
#if defined (__SAME_GT02__)
    if(!G_importance_parameter_data.app_version.support_sensor)
    {
        return;
    }
#endif

    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.sensor_gps_work);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 0 || value > 300)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (0,1-300)");
        return;
    }
    if(G_parameter.sensor_gps_work != value)
    {
        G_parameter.sensor_gps_work = value;
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        track_cust_gps_cmd_change_set();
    }
    sprintf(cmd->rsp_msg, "OK!");
}

/******************************************************************************
 *  Function    -  cmd_dsreset
 *
 *  Purpose     -  重置设防状态指令
 *
 *  Description -
        DSRESET#
            强制设置撤防状态

2016/8/23 15:47:01 康凯丝 谭志强:
    DSRESET是暂时取消设防状态的一个指令。比如ACC OFF ，进入设防，发这个指令可撤销设防状态，而当后续ACC 再一次由ON切换为OFF时，又会进入设防。
    DSRESET 这个指令目前很少用。作用跟000不完全一样
    主要在自动模式起作用，在手动模式下，作用就于000差不多
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_dsreset(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        if(G_realtime_data.defense_mode == 0)
        {
            track_cust_status_defences_change((void*)0);
            sprintf(cmd->rsp_msg, "OK!");
        }
        else
        {
            track_cust_check_sos_incall(cmd, 0);
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
}

/******************************************************************************
 *  Function    -  cmd_clear
 *
 *  Purpose     -  备份数据清除指令
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_clear(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
    	track_os_intoTaskMsgQueue2(track_soc_clear_dw_queue);
        track_soc_clear_queue();
		#if defined(__NF2318__)
        sprintf(cmd->rsp_msg, "%s=OK",cmd->pars[0]);
		#else
        sprintf(cmd->rsp_msg, "OK!");
		#endif
        return;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
}

static void cmd_dwdepo(CMD_DATA_STRUCT *cmd)
{
    int value;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], ON_OFF(G_parameter.dwd_epo_sw));
        return;
    }
    if(!strcmp(cmd->pars[1], "ON"))
    {
        G_parameter.dwd_epo_sw = 1;
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        G_parameter.dwd_epo_sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

/******************************************************************************
 *  Function    -  cmd_sf
 *
 *  Purpose     -  静态数据过滤开关
 *
 *  Description -
        SF,X#
            X=ON/OFF，默认值：ON
        SF#
            查询已设置的参数
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_sf(CMD_DATA_STRUCT *cmd)
{
    int value;
    U8 static_filter_sw;
    U16 static_filter_distance;
    if(cmd->part == 0 && G_parameter.gps_work.static_filter_sw != 5)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d", cmd->pars[0], ON_OFF(G_parameter.gps_work.static_filter_sw),
                G_parameter.gps_work.static_filter_distance);
        return;
    }
    else if(cmd->part == 0 && G_parameter.gps_work.static_filter_sw == 5)
    {
        sprintf(cmd->rsp_msg, "%s:ON2,%d", cmd->pars[0], G_parameter.gps_work.static_filter_distance);
        return;
    }
    static_filter_sw = G_parameter.gps_work.static_filter_sw;
    static_filter_distance = G_parameter.gps_work.static_filter_distance;
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part > 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        if(cmd->part >= 1)
        {
            static_filter_sw = 1;
        }
        if(cmd->part > 1)
        {
            value  = track_fun_atoi(cmd->pars[2]);
            if(value < 10 || value > 1000)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (10 to 1000)");
                return;
            }
            static_filter_distance = value;
        }
    }
    else if(!strcmp(cmd->pars[1], "ON2"))
    {
        if(cmd->part > 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        if(cmd->part >= 1)
        {
            static_filter_sw = 5;
        }
        if(cmd->part > 1)
        {
            value  = track_fun_atoi(cmd->pars[2]);
            if(value < 10 || value > 1000)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (10 to 1000)");
                return;
            }
            static_filter_distance = value;
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        static_filter_sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    G_parameter.gps_work.static_filter_sw = static_filter_sw;
    G_parameter.gps_work.static_filter_distance = static_filter_distance;
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

#ifdef __WIFI__
static void cmd_WIFION(CMD_DATA_STRUCT *cmd)
{
    track_drv_wifi_work_mode();
    sprintf(cmd->rsp_msg, "OK!");
}

static void cmd_WF(CMD_DATA_STRUCT *cmd)
{
    int value;
    nvram_wifi_struct wifi = {0};
    memcpy(&wifi, &G_parameter.wifi, sizeof(nvram_wifi_struct));

    if(cmd->part == 0)
    {
#if defined(__GT740__)||defined (__GT370__)|| defined (__GT380__)
        sprintf(cmd->rsp_msg, "%s:%s,%d", cmd->pars[0], ON_OFF(G_parameter.wifi.sw),
                G_parameter.wifi.sacn_timer);
#else
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d", cmd->pars[0], ON_OFF(G_parameter.wifi.sw),
                G_parameter.wifi.sacn_timer, G_parameter.wifi.work_timer);
#endif

        return;
    }
    if(!strcmp(cmd->pars[1], "ON"))
    {
        wifi.sw = 1;
        if(cmd->part > 1)
        {
            value  = track_fun_atoi(cmd->pars[2]);
            if(value < 1 || value > 60)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (1 to 60)");
                return;
            }
            wifi.sacn_timer = value;
        }
        if(cmd->part > 2)
        {
#if defined(__GT740__)||defined (__GT370__)|| defined (__GT380__)
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
#else
            value  = track_fun_atoi(cmd->pars[3]);
            if(value < 10 || value > 18000)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3(10 to 18000)");
                return;
            }
            wifi.work_timer = value;
#endif
        }
        if(cmd->part > 3)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        wifi.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.wifi, &wifi, sizeof(nvram_wifi_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }

    if(G_parameter.wifi.sw == 1)
    {
        track_drv_wifi_work_mode();
    }
}
#endif /* __WIFI__ */
#if defined(__NT36__)||defined(__GT370__)|| defined (__GT380__)
/******************************************************************************
 *  Function    -  cmd_eph
 *
 *  Purpose     -  GPS 星历更新时间设置
 *
 *  Description -
        EPH,<A>#
            A=60～240分钟，默认值：60分钟
        EPH#
            查询已设置的参数
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_eph(CMD_DATA_STRUCT *cmd)
{
    int value = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.gps_work.ephemeris_interval);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(!strcmp(cmd->pars[1], "OFF"))
    {
        value = 0;
    }
    else
    {
        value = track_fun_atoi(cmd->pars[1]);
        if(value < 60 || value > 240)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (60-240)");
            return;
        }
    }
    G_parameter.gps_work.ephemeris_interval = value;
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#endif
/******************************************************************************
 *  Function    -  cmd_call
 *
 *  Purpose     -  电话重拨次数
 *
 *  Description -
        CALL,N#
            N=1～3；默认值：3；针对所有电话报警
        CALL#
            查询已设置的参数
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_call(CMD_DATA_STRUCT *cmd)
{
    int value = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.redial_count);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 1 || value > 3)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (1-3)");
        return;
    }
    G_parameter.redial_count = value;
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

/******************************************************************************
 *  Function    -  cmd_moving
 *
 *  Purpose     -  位移报警设置
 *
 *  Description -
 *      MOVING,<A>,<R>[,M]#
 *          A=ON/OFF；默认值：OFF
 *          R=100～1000；默认值：300；位移半径
 *          M=0～2；0 仅GPRS，1 SMS+GPRS，2 GPRS+SMS+电话；默认值：1；
 *      MOVING,OFF#
 *          关闭位移报警
 *      MOVING#
 *          查询当前位移开启还是关闭的状态，设置的半径，报警方式，位移原点
 *
 *  Example    -
 *      MOVING,ON,100#
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_moving(CMD_DATA_STRUCT *cmd)
{
    nvram_displacement_alarm_struct displacement_alarm = {0};
    int value = 0;
    if(cmd->part == 0 || (cmd->part == 1 && !strcmp(cmd->pars[1], "STATUS")))
    {
        if(G_parameter.displacement_alarm.sw)
        {
            if(G_realtime_data.latitude == 0 || G_realtime_data.longitude == 0)
            {
#if defined(__GERMANY__)
                sprintf(cmd->rsp_msg, "Bewegungsalarm:%s; Lat:NONE; Lon:NONE; Radius:%dm; Alarmtyp:%d",
                        ON_OFF(G_parameter.displacement_alarm.sw),
                        G_parameter.displacement_alarm.radius, G_parameter.displacement_alarm.alarm_type);
#else
                sprintf(cmd->rsp_msg, "Moving Switch:%s; Lat:NONE; Lon:NONE; Radius:%dm; Alarm type:%d",
                        ON_OFF(G_parameter.displacement_alarm.sw),
                        G_parameter.displacement_alarm.radius, G_parameter.displacement_alarm.alarm_type);
#endif
            }
            else
            {
                char EW[2] = {0}, NS[2] = {0};
                float lon, lat;
                if(G_realtime_data.longitude > 0)
                {
                    if(G_realtime_data.longitude != 0) *EW = 'E';
                    lon = G_realtime_data.longitude;
                }
                else
                {
                    if(G_realtime_data.longitude != 0) *EW = 'W';
                    lon = G_realtime_data.longitude * -1;
                }
                if(G_realtime_data.latitude > 0)
                {
                    if(G_realtime_data.latitude != 0) *NS = 'N';
                    lat = G_realtime_data.latitude;
                }
                else
                {
                    if(G_realtime_data.latitude != 0) *NS = 'S';
                    lat = G_realtime_data.latitude * -1;
                }
#if defined(__GERMANY__)
                sprintf(cmd->rsp_msg, "Bewegungsalarm:%s; Lat:%s%.6f; Lon:%s%.6f; Radius:%dm; Alarmtyp:%d",
                        ON_OFF(G_parameter.displacement_alarm.sw),
                        NS, lat, EW, lon,
                        G_parameter.displacement_alarm.radius, G_parameter.displacement_alarm.alarm_type);

#else
                sprintf(cmd->rsp_msg, "Moving Switch:%s; Lat:%s%.6f; Lon:%s%.6f; Radius:%dm; Alarm type:%d",
                        ON_OFF(G_parameter.displacement_alarm.sw),
                        NS, lat, EW, lon,
                        G_parameter.displacement_alarm.radius, G_parameter.displacement_alarm.alarm_type);
#endif
                if(!strcmp(cmd->pars[1], "STATUS"))
                {
                    char *p;
                    kal_uint8 gpsStatus;
                    p = cmd->rsp_msg + strlen(cmd->rsp_msg);
                    gpsStatus = track_cust_gps_status();
                    if(gpsStatus == GPS_STAUS_OFF)
                    {
                        sprintf(p, " (GPS Close!)");
                    }
                    else if(gpsStatus == GPS_STAUS_ON)
                    {
                        sprintf(p, " (GPS ON!)");
                    }
                    else if(gpsStatus == GPS_STAUS_SCAN)
                    {
                        sprintf(p, " (GPS Searching!)");
                    }
                    else if(gpsStatus >= GPS_STAUS_2D)
                    {
                        float res = 0;
                        res = track_fun_get_GPS_2Points_distance(
                                  G_realtime_data.latitude, G_realtime_data.longitude,
                                  track_drv_get_gps_RMC()->Latitude, track_drv_get_gps_RMC()->Longitude);
                        sprintf(p, " (Distance far point:%.2fM)", res);
                    }
                }
            }
        }
        else
        {
#if defined(__GERMANY__)
            sprintf(cmd->rsp_msg, "Bewegungsalarm:%s; Radius:%dm; Alarmtyp:%d",
                    ON_OFF(G_parameter.displacement_alarm.sw),
                    G_parameter.displacement_alarm.radius, G_parameter.displacement_alarm.alarm_type);
#else
            sprintf(cmd->rsp_msg, "Moving Switch:%s; Radius:%dm; Alarm type:%d",
                    ON_OFF(G_parameter.displacement_alarm.sw),
                    G_parameter.displacement_alarm.radius, G_parameter.displacement_alarm.alarm_type);
#endif
        }
        return;
    }
    memcpy(&displacement_alarm, &G_parameter.displacement_alarm, sizeof(nvram_displacement_alarm_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 3)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        displacement_alarm.sw = 1;
        if(cmd->part >= 2)
        {
            value = track_fun_atoi(cmd->pars[2]);
            if(value < 100 || value > 1000)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (100-1000)");
                return;
            }
            displacement_alarm.radius = value;
        }
        if(cmd->part == 3)
        {
            value = track_fun_atoi(cmd->pars[3]);
#if defined(__EL100__)
            if(value != 0)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (Only 0)");
                return;
            }
#else
            if(value < 0 || value > 3)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (0/1/2/3)");
                return;
            }
#endif
            displacement_alarm.alarm_type = value;
        }
        if(track_cust_status_acc() == 1)
        {
            track_os_intoTaskMsgQueueExt(track_cust_module_sd_acc, (void *)4);
        }
        else
        {
            track_os_intoTaskMsgQueueExt(track_cust_module_sd_acc, (void *)3);
        }
        if(G_parameter.lang == 1 && cmd->return_sms.cm_type != CM_ONLINE && cmd->return_sms.cm_type != CM_ONLINE2)
        {
            char buf[320] = {0};
            int ret;
            sprintf(buf, "设置成功! 位移报警开启；位移半径：%dM；报警类型：%d",
                    displacement_alarm.radius, displacement_alarm.alarm_type);
            if(cmd->return_sms.cm_type == CM_AT)
            {
                cmd->rsp_length = strlen(buf);
                memcpy(cmd->rsp_msg, buf, cmd->rsp_length);
                cmd->return_sms.reply_character_encode = 2;
            }
            else
            {
                cmd->rsp_length = track_fun_GB2312_to_UTF16BE(buf, strlen(buf), cmd->rsp_msg, 320);
                cmd->return_sms.reply_character_encode = 1;
            }
        }
        else
        {
#if defined(__GERMANY__)
            sprintf(cmd->rsp_msg, "Bewegungsalarm:EIN; Radius:%dm; Alarmtyp:%d",
                    displacement_alarm.radius, displacement_alarm.alarm_type);
#else
            sprintf(cmd->rsp_msg, "OK! Moving Switch:ON; Radius:%dm; Alarm type:%d",
                    displacement_alarm.radius, displacement_alarm.alarm_type);
#endif
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        displacement_alarm.sw = 0;
        track_cust_module_sd_stop();
        if(G_parameter.lang == 1 && cmd->return_sms.cm_type != CM_ONLINE && cmd->return_sms.cm_type != CM_ONLINE2)
        {
            char buf[320] = {0};
            int ret;
            sprintf(buf, "设置成功！位移报警已关闭。");
            if(cmd->return_sms.cm_type == CM_AT)
            {
                cmd->rsp_length = strlen(buf);
                memcpy(cmd->rsp_msg, buf, cmd->rsp_length);
                cmd->return_sms.reply_character_encode = 2;
            }
            else
            {
                cmd->rsp_length = track_fun_GB2312_to_UTF16BE(buf, strlen(buf), cmd->rsp_msg, 320);
                cmd->return_sms.reply_character_encode = 1;
            }
        }
        else
        {
#if defined(__GERMANY__)
            sprintf(cmd->rsp_msg, "Bewegungsalarm: AUS.",
                    displacement_alarm.radius, displacement_alarm.alarm_type);
#else
            sprintf(cmd->rsp_msg, "OK! Moving Switch:OFF.",
                    displacement_alarm.radius, displacement_alarm.alarm_type);
#endif

        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.displacement_alarm, &displacement_alarm, sizeof(nvram_displacement_alarm_struct));
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    //if(!strlen(cmd->rsp_msg)) sprintf(cmd->rsp_msg, "OK!");
#if defined(__PARAM_CHANGE_UPDATE_SERVER__)
    track_cust_paket_9404_handle();
#endif
}

static void cmd_wn(CMD_DATA_STRUCT * cmd)
{
    int index = 0, length = 0 , total = 0;
    char str[50] = {0};
    for(; index < TRACK_DEFINE_WN_COUNT; index++)
    {
        length = strlen(G_phone_number.white_num[index]);
        if(length > 0 && length < TRACK_DEFINE_PHONE_NUMBER_LEN_MAX)
        {
            length = snprintf(str, 49, "%d,%s;", index, G_phone_number.white_num[index]);
            LOGD(L_APP, L_V5, "length:%d,total:", length, total);
            total += length;

            if(total > CM_PARAM_LONG_LEN_MAX - 1)break;
            strcat(cmd->rsp_msg, G_phone_number.white_num[index]);
        }
    }
}
#if 0
/******************************************************************************
 *  Function    -  cmd_park
 *
 *  Purpose     -  停车超时提醒设置
 *
 *  Description -
        PARK,<A>,<B>,[M]#
            A=ON/OFF；默认值：OFF
            B=5～3600分钟；停车时长；默认值：60
            M=0/1；报警上报方式，0 仅GPRS，1 SMS+GPRS；默认值：1
        PARK#
            查询已设置的参数
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_park(CMD_DATA_STRUCT *cmd)
{
    nvram_carpark_alarm_struct carpark_alarm = {0};
    int value = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d", cmd->pars[0], ON_OFF(G_parameter.carpark_alarm.sw), G_parameter.carpark_alarm.time, G_parameter.carpark_alarm.alarm_type);
        return;
    }
    memcpy(&carpark_alarm, &G_parameter.carpark_alarm, sizeof(nvram_carpark_alarm_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 2 || cmd->part > 3)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        carpark_alarm.sw = 1;
        value = track_fun_atoi(cmd->pars[2]);
        if(value < 5 || value > 3600)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (5-3600)");
            return;
        }
        carpark_alarm.time = value;
        if(cmd->part == 3)
        {
            value = track_fun_atoi(cmd->pars[3]);
            if(value < 0 || value > 1)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (0-1)");
                return;
            }
            carpark_alarm.alarm_type = value;
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        carpark_alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.carpark_alarm, &carpark_alarm, sizeof(nvram_carpark_alarm_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#endif
/******************************************************************************
 *  Function    -  cmd_speed
 *
 *  Purpose     -  超速提醒设置
 *
 *  Description -
        SPEED,<A>,<B>,<C>,[M]#
            A=ON/OFF；超速报警；默认值：OFF
            B=5～600秒；时间范围；默认值：20秒
            C=1～255km/h；超速门限范围；默认值：100km/h
            M=0/1；报警上报方式，0 仅GPRS，1 SMS+GPRS；默认值：1
        SPEED#
            查询已设置的参数
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_speed(CMD_DATA_STRUCT *cmd)
{
    nvram_speed_limit_alarm_struct speed_limit_alarm = {0};
    int value = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d,%d", cmd->pars[0],
                ON_OFF(G_parameter.speed_limit_alarm.sw), G_parameter.speed_limit_alarm.delay_time,
                G_parameter.speed_limit_alarm.threshold, G_parameter.speed_limit_alarm.alarm_type);
        return;
    }
    if(track_cust_get_work_mode() == WORK_MODE_3)
    {
        snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, string3_en);
        return;
    }
    memcpy(&speed_limit_alarm, &G_parameter.speed_limit_alarm, sizeof(nvram_speed_limit_alarm_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part > 4)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        speed_limit_alarm.sw = 1;
        if(cmd->part >= 2)
        {
            value = track_fun_atoi(cmd->pars[2]);
            if(value < 5 || value > 600)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (5-600)");
                return;
            }
            speed_limit_alarm.delay_time = value;
        }
        if(cmd->part >= 3)
        {
            value = track_fun_atoi(cmd->pars[3]);
            if(value < 1 || value > 255)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (1-255)");
                return;
            }
            speed_limit_alarm.threshold = value;
        }
        if(cmd->part == 4)
        {
            value = track_fun_atoi(cmd->pars[4]);
#if defined(__ET310__)||defined(__NT36__)||defined(__MT200__)||defined (__NT13V__)
            if(value < 0 || value > 1)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 4 (0-1)");
                return;
            }
#else
            if(value < 0 || value > 3)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 4 (0-3)");
                return;
            }
#endif /* __ET310__ */
            speed_limit_alarm.alarm_type = value;
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        speed_limit_alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.speed_limit_alarm, &speed_limit_alarm, sizeof(nvram_speed_limit_alarm_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
#if defined(__PARAM_CHANGE_UPDATE_SERVER__)
    track_cust_paket_9404_handle();
#endif
    track_cust_module_speed_limit_cmd_update();
}
#if 0
/******************************************************************************
 *  Function    -  cmd_fdt
 *
 *  Purpose     -  疲劳驾驶报警设置
 *
 *  Description -
        FDT,<A>,<T1>,<T2>[,M]#
            A=ON/OFF；超速报警；默认值：OFF
            T1=1～3600分钟；疲劳驾驶持续时间；默认值：
            T2=1～3600分钟；驾驶清零计时时间；默认值：
            M=0/1；报警上报方式，0 仅GPRS，1 SMS+GPRS；默认值：0
        FDT#
            查询已设置的参数
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_fdt(CMD_DATA_STRUCT *cmd)
{
    nvram_fatigue_driving_alarm_struct fatigue_driving_alarm = {0};
    int value = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d,%d", cmd->pars[0],
                ON_OFF(G_parameter.fatigue_driving_alarm.sw), G_parameter.fatigue_driving_alarm.delay_time,
                G_parameter.fatigue_driving_alarm.delay_reset, G_parameter.fatigue_driving_alarm.alarm_type);
        return;
    }
    memcpy(&fatigue_driving_alarm, &G_parameter.fatigue_driving_alarm, sizeof(nvram_fatigue_driving_alarm_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 3 || cmd->part > 4)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        fatigue_driving_alarm.sw = 1;
        value = track_fun_atoi(cmd->pars[2]);
        if(value < 1 || value > 3600)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (1-3600)");
            return;
        }
        fatigue_driving_alarm.delay_time = value;
        value = track_fun_atoi(cmd->pars[3]);
        if(value < 1 || value > 3600)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (1-3600)");
            return;
        }
        fatigue_driving_alarm.delay_reset = value;
        if(cmd->part == 4)
        {
            value = track_fun_atoi(cmd->pars[4]);
            if(value < 0 || value > 1)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (0-1)");
                return;
            }
            fatigue_driving_alarm.alarm_type = value;
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        fatigue_driving_alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.fatigue_driving_alarm, &fatigue_driving_alarm, sizeof(nvram_fatigue_driving_alarm_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
static void cmd_BOOTALM(CMD_DATA_STRUCT *cmd)
{
    nvram_boot_struct alarm = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d", cmd->pars[0],
                ON_OFF(G_parameter.boot.sw), G_parameter.boot.alarm_type);
        return;
    }
    memcpy(&alarm, &G_parameter.boot, sizeof(nvram_boot_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 1;
        if(cmd->part >= 2)
        {
            alarm.alarm_type = track_fun_atoi(cmd->pars[2]);
            if(alarm.alarm_type != 0 && alarm.alarm_type != 1)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1)");
                return;
            }
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.boot, &alarm, sizeof(nvram_boot_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#endif

#if !defined(__NF2318__)
static void cmd_accalm(CMD_DATA_STRUCT *cmd)
{
#if defined(__ACC_ALARM__)
    kal_uint8 time;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s: %s,%d,%d,%d", cmd->pars[0],
                ON_OFF(G_parameter.accalm.accalm_sw), G_parameter.accalm.accalm_type, G_parameter.accalm.accalm_time, G_parameter.accalm.accalm_cause);
        return;
    }
#else
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s: %s", cmd->pars[0],
                ON_OFF(G_parameter.accalm_sw));
        return;
    }
#endif
    if(!strcmp(cmd->pars[1], "ON"))
    {
#if defined(__ACC_ALARM__)
        if(cmd->part < 1 || cmd->part > 4)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        else if(cmd->part >= 2)
        {
            time = track_fun_atoi(cmd->pars[2]);
            if(time < 0 || time > 1)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1)");
                return;
            }
            G_parameter.accalm.accalm_type = time;
            if(cmd->part >= 3)
            {
                time = track_fun_atoi(cmd->pars[3]);
                if(time < 5 || time > 60 || time != track_fun_atoi(cmd->pars[3]))
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 3 (5~60)");
                    return;
                }
                G_parameter.accalm.accalm_time = time;
            }
            if(cmd->part >= 4)
            {
                time = track_fun_atoi(cmd->pars[4]);
                if(time < 0 || time > 2 || time != track_fun_atoi(cmd->pars[4]))
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 4 (0~2)");
                    return;
                }
                G_parameter.accalm.accalm_cause = time;
            }
        }
        G_parameter.accalm.accalm_sw = 1;
#else
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        G_parameter.accalm_sw = 1;
#endif
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
#if defined(__ACC_ALARM__)
        G_parameter.accalm.accalm_sw = 0;
#else
        G_parameter.accalm_sw = 0;
#endif
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    sprintf(cmd->rsp_msg, "OK!");
}
#endif
/******************************************************************************
 *  Function    -  cmd_mileage
 *
 *  Purpose     -  里程设置指令
 *
 *  Description -
        MILEAGE,<A>,<N>#
            A=ON/OFF；超速报警；默认值：OFF
            N=0～5000000 km/h；里程初值；默认为：0
        MILEAGE,ON,0#
            里程归零
        MILEAGE,OFF#
            关闭里程统计
        MILEAGE#
            查询总里程，及设置的初值
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_mileage(CMD_DATA_STRUCT *cmd)
{
    nvram_mileage_statistics_struct mileage_statistics = {0};
    double value = 0;
    U32 gps_mileage;
    if(cmd->part == 0)
    {
        gps_mileage = track_get_gps_mileage() / 1000;
        sprintf(cmd->rsp_msg, "%s:%s, Total Mileage:%dkm,K:%d", cmd->pars[0], ON_OFF(G_parameter.mileage_statistics.sw),
                gps_mileage, G_parameter.mileage_statistics.K);
        return;
    }
    memcpy(&mileage_statistics, &G_parameter.mileage_statistics, sizeof(nvram_mileage_statistics_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part > 3)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        mileage_statistics.sw = 1;
        if(cmd->part >= 2 && cmd->part < 4)
        {
            if(track_fun_check_str_is_number(2, cmd->pars[2]) == 0)
            {
                sprintf(cmd->rsp_msg, "Error: Number contains non-numeric characters!");
                return;
            }
            value = atof(cmd->pars[2]);
            if(value < 0 || value > 999999)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0-999999)");
                return;
            }
            mileage_statistics.mileage = value * 1000;
            track_set_gps_distance(0);
            if(cmd->part == 3)
            {
                value = track_fun_atoi(cmd->pars[3]);
                if(value < 1000 || value > 1200)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 3 (1000 to 1200)");
                    return;
                }
                mileage_statistics.K = value;
            }
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        mileage_statistics.sw = 0;
        mileage_statistics.mileage = 0;
        track_set_gps_distance(0);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.mileage_statistics, &mileage_statistics, sizeof(nvram_mileage_statistics_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

/******************************************************************************
 *  Function    -  cmd_sensorset
 *
 *  Purpose     -  触发震动报警条件
 *
 *  Description -
        SENSORALM,<A>,<B>,<C>[,D]#
            A=1-300 秒；SENSOR检测时间范围；默认值：10秒
            B=1-300 次；震动激活GPS触发次数门限；默认值：1次
            C=1-300 次；震动触发次数门限；默认值：3次
            D=1-4 秒;   SENSOR 检测间隔（C 秒），默认值：1

            限制条件：A ≥ C * D ≥ B * D
        SENSORALM#
            查询设置的震动报警触发条件
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 13-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_sensorset(CMD_DATA_STRUCT *cmd)
{
    nvram_vibrates_alarm_struct alarm = {0};
    nvram_vibrates_start_gps_struct vibrates = {0};
    int value;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d,%d,%d,%d", cmd->pars[0],
                G_parameter.vibrates_alarm.detection_time,
                G_parameter.gps_work.vibrates.detection_count,
                G_parameter.vibrates_alarm.detection_count,
                G_parameter.vibrates_alarm.sampling_interval);
        return;
    }
    else if(cmd->part > 4)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    memcpy(&alarm, &G_parameter.vibrates_alarm, sizeof(nvram_vibrates_alarm_struct));
    memcpy(&vibrates, &G_parameter.gps_work.vibrates, sizeof(nvram_vibrates_start_gps_struct));
    value  = track_fun_atoi(cmd->pars[1]);
#if defined(__ET310__)||defined(__MT200__)||defined (__NT13V__)
    if(value < 1 || value > 300)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (1 to 300)");
        return;
    }
#else
    if(value < 10 || value > 300)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (10 to 300)");
        return;
    }
#endif /* __ET310__ */
    alarm.detection_time = value;
    vibrates.detection_time = value;
    if(cmd->part > 1)
    {
        value = track_fun_atoi(cmd->pars[2]);
        if(value < 1 || value > 20)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (1 to 20)");
            return;
        }
        vibrates.detection_count = value;
    }
    if(cmd->part > 2)
    {
        value = track_fun_atoi(cmd->pars[3]);
        if(value < 1 || value > 20)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 3 (1 to 20)");
            return;
        }
        alarm.detection_count = value;
    }
    if(cmd->part > 3)
    {
        value = track_fun_atoi(cmd->pars[4]);
        if(value < 1 || value > 3)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 4 (1 to 3)");
            return;
        }
        alarm.sampling_interval = value;
    }
    if(alarm.detection_time < alarm.detection_count * alarm.sampling_interval)
    {
#if defined(__GERMANY__)
        return_message(
            cmd,
            "Fehler! Eintrag 3 und 4 sollen geringer o. gleich als Eintrag 1 sein.",
            "错误！参数3和参数4之乘积应不大于参数1。");
#else
        return_message(
            cmd,
            "Error! The parameters 3 and parameters 4 of the product should be less than or equal to the value of parameter 1.",
            "错误！参数3和参数4之乘积应不大于参数1。");
#endif
        return;
    }
    else if(alarm.detection_count < vibrates.detection_count)
    {
#if defined(__GERMANY__)
        return_message(
            cmd,
            "Fehler! Eintrag 2 sollte geringer o. gleich als Eintrag 3 sein.",
            "错误！参数2应不大于参数3。");
#else
        return_message(
            cmd,
            "Error! The value of parameters 2 should be less than or equal to the value of parameter 3.",
            "错误！参数2应不大于参数3。");
#endif
        return;
    }
    memcpy(&G_parameter.vibrates_alarm, &alarm, sizeof(nvram_vibrates_alarm_struct));
    memcpy(&G_parameter.gps_work.vibrates, &vibrates, sizeof(nvram_vibrates_start_gps_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

static void cmd_gprsalm(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], ON_OFF(G_parameter.gprs_obstruction_alarm.sw));
        return;
    }
    else if(track_cust_get_work_mode() == WORK_MODE_3)
    {
        snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, string3_en);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(!strcmp(cmd->pars[1], "ON"))
    {
        G_parameter.gprs_obstruction_alarm.sw = 1;
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        G_parameter.gprs_obstruction_alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

/******************************************************************************
 *  Function    -  cmd_staticrep
 *
 *  Purpose     -  静止上报最后位置开关指令
 *
 *  Description -
 *                 STATICREP,<A>[,B[,C]]#
 *                     A=ON/OFF；SENSOR 检测静止上报最后位置开关；默认值：OFF
 *                     B=10～300 秒；时间范围；默认值：180 秒
 *                     C=0～100 km/h，最小速度
 *                     D=0～20 连续监测的个数
 *                 STATICREP#
 *                     查询 STATICREP# 设置参数
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 01-03-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_staticrep(CMD_DATA_STRUCT *cmd)
{
    nvram_staticrep_struct staticrep = {0};
    int value;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d,%d", cmd->pars[0], ON_OFF(G_parameter.staticrep.sw),
                G_parameter.staticrep.detection_time, G_parameter.staticrep.speed, G_parameter.staticrep.count);
        return;
    }
    memcpy(&staticrep, &G_parameter.staticrep, sizeof(nvram_staticrep_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part > 4)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        staticrep.sw = 1;
        if(cmd->part > 1)
        {
            value  = track_fun_atoi(cmd->pars[2]);
            if(value < 10 || value > 300)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (10 to 300)");
                return;
            }
            staticrep.detection_time = value;
        }
        if(cmd->part > 2)
        {
            value  = track_fun_atoi(cmd->pars[3]);
            if(value < 0 || value > 100)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (0 to 100)");
                return;
            }
            staticrep.speed = value;
        }
        if(cmd->part > 3)
        {
            value  = track_fun_atoi(cmd->pars[4]);
            if(value < 1 || value > 20)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 4 (1 to 20)");
                return;
            }
            staticrep.count = value;
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        staticrep.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.staticrep, &staticrep, sizeof(nvram_staticrep_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

/******************************************************************************
 *  Function    -  cmd_RENEW
 *
 *  Purpose     -  平台或SMS 短信透传短信内容
 *
 *  Description -  FW，设定号码，信息内容#
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 07-05-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_RENEW(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        char num[32] = {0};
        if(track_cust_sms_relay_status(1, num) == 1)
        {
            sprintf(cmd->rsp_msg, "%s:ON relay num:%s", cmd->pars[0], num);
        }
        else
        {
            sprintf(cmd->rsp_msg, "%s:OFF", cmd->pars[0]);
        }
        return;
    }
    else if(cmd->part < 2)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(track_fun_check_str_is_number(1, cmd->pars[2]) <= 0)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (phone number)");
        return;
    }
    else
    {
        char buf[320] = {0};
        int len;

        len = strlen(cmd->pars[1]);
        if(len > 318)
        {
            len = 318;
        }
        memcpy(buf, cmd->rcv_msg_source + (cmd->pars[1] - cmd->rcv_msg), len);
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            track_cust_sms_relay_status(2, cmd->return_sms.ph_num);
            track_cust_sms_relay_status(cmd->return_sms.num_type, cmd->return_sms.ph_num);
        }
        else if(cmd->return_sms.cm_type == CM_ONLINE || cmd->return_sms.cm_type == CM_ONLINE2)
        {
            track_cust_sms_relay_status(3, cmd->return_sms.stamp);
        }
        if(cmd->character_encode == 1)
        {
            int ret;
            char buf1[320] = {0};
            ret = track_fun_GB2312_to_UTF16BE(buf, strlen(buf), buf1, 320);
            track_cust_sms_send(0, cmd->pars[2], KAL_FALSE, buf1, ret);
        }
        else
        {
            track_cust_sms_send(0, cmd->pars[2], KAL_TRUE, buf, strlen(buf));
        }
        LOGD(L_APP, L_V3, "%s", cmd->rcv_msg_source);
        cmd->rsp_msg[0] = 0;
    }
}

/******************************************************************************
 *  Function    -  cmd_fw
 *
 *  Purpose     -  平台或SMS 短信透传短信内容
 *
 *  Description -  FW，设定号码，信息内容#
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 07-05-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_fw(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        char num[32] = {0};
        if(track_cust_sms_relay_status(1, num) == 1)
        {
            sprintf(cmd->rsp_msg, "%s:ON relay num:%s", cmd->pars[0], num);
        }
        else if(track_cust_sms_relay_status(1, num) == 2)
        {
            sprintf(cmd->rsp_msg, "%s:ON ", cmd->pars[0]);
        }
        else
        {
            sprintf(cmd->rsp_msg, "%s:OFF", cmd->pars[0]);
        }
        return;
    }
    else if(cmd->part < 2)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(strlen(cmd->pars[1]) == 0 || track_fun_check_str_is_number(1, cmd->pars[1]) <= 0)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (phone number)");
        return;
    }
    else
    {
        char buf[320] = {0};
        int len;

        // len = strlen(cmd->pars[2]);
        //  len=len-1;
        //   len = strlen(cmd->rcv_msg_source + (cmd->pars[2] - cmd->rcv_msg));
        if(strlen(cmd->pars[2]) == 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (FW content can't null)");
            return;
        }
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            len = strlen(cmd->rcv_msg_source + (cmd->pars[2] - cmd->rcv_msg)) - 1;
        }
        else
        {
            len = strlen(cmd->rcv_msg_source + (cmd->pars[2] - cmd->rcv_msg));
        }
        LOGD(L_APP, L_V3, "%d", len);
        if(len > 318)
        {
            len = 318;
        }
        memcpy(buf, cmd->rcv_msg_source + (cmd->pars[2] - cmd->rcv_msg), len);
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            track_cust_sms_relay_status(2, cmd->return_sms.ph_num);
            track_cust_sms_relay_status(cmd->return_sms.num_type, cmd->return_sms.ph_num);
        }
        else if(cmd->return_sms.cm_type == CM_ONLINE || cmd->return_sms.cm_type == CM_ONLINE2)
        {
            track_cust_sms_relay_status(3, cmd->return_sms.stamp);
        }
        if(cmd->character_encode == 1)
        {
            int ret;
            char buf1[320] = {0};
            ret = track_fun_GB2312_to_UTF16BE(buf, strlen(buf), buf1, 320);
            track_cust_sms_send(0, cmd->pars[1], KAL_FALSE, buf1, ret);
        }
        else
        {
            track_cust_sms_send(0, cmd->pars[1], KAL_TRUE, buf, strlen(buf));
        }
        LOGD(L_APP, L_V3, "%s", cmd->rcv_msg_source);
        cmd->rsp_msg[0] = 0;
    }
}

#if defined (__GT740__)||defined (__GT370__)||defined (__GT380__) || defined(__NF2318__)
/*手持项目无需断油电相关功能       --    chengjun  2017-04-18*/
#else
static void cmd_motorset(CMD_DATA_STRUCT *cmd)
{
    nvram_motor_lock_struct motor_lock = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d,%d", cmd->pars[0],
                ON_OFF(G_parameter.motor_lock.sw),
                G_parameter.motor_lock.lock_continue_time,
                G_parameter.motor_lock.lock_on_time,
                G_parameter.motor_lock.lock_off_time);
        return;
    }
    memcpy(&motor_lock, &G_parameter.motor_lock, sizeof(nvram_motor_lock_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 4)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        motor_lock.sw = 1;
        if(cmd->part > 1)
        {
            motor_lock.lock_continue_time = track_fun_atoi(cmd->pars[2]);
            if(motor_lock.lock_continue_time < 1 || motor_lock.lock_continue_time > 86400)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (1 ~ 86400)");
                return;
            }
        }
        if(cmd->part > 2)
        {
            motor_lock.lock_on_time = track_fun_atoi(cmd->pars[3]);
            if(motor_lock.lock_on_time < 40 || motor_lock.lock_on_time > 30000)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (40 ~ 30000)");
                return;
            }
        }
        if(cmd->part > 3)
        {
            motor_lock.lock_off_time = track_fun_atoi(cmd->pars[4]);
            if(motor_lock.lock_off_time < 40 || motor_lock.lock_off_time > 10000)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 4 (40 ~ 10000)");
                return;
            }
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        motor_lock.sw = 0;
        track_motor_lock_change_status(MOTOR_END_REQ);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.motor_lock, &motor_lock, sizeof(nvram_motor_lock_struct));
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    track_cust_defences_cmd_update();
    sprintf(cmd->rsp_msg, "OK!");
}
#if 0
static void cmd_motor1(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%d", track_cust_motor_lock(2));
        return;
    }
    else if(cmd->part != 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(!strcmp(cmd->pars[1], "ON"))
    {
        track_cust_motor_lock(1);
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        track_cust_motor_lock(0);
    }
    else if(!strcmp(cmd->pars[1], "MODE0"))
    {
        if(G_parameter.motor_lock.mode != 0)
        {
            G_parameter.motor_lock.mode = 0;
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        }
    }
    else if(!strcmp(cmd->pars[1], "MODE1"))
    {
        if(G_parameter.motor_lock.mode != 1)
        {
            G_parameter.motor_lock.mode = 1;
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    sprintf(cmd->rsp_msg, "OK!");
}

/********************************************************************************

        RELAY,1#
            A=0/1；0 接通油电，1 断开油电；默认值为：0
        RELAY#
            查询已设置的参数
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_relay(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], track_cust_oil_cut(99));
        return;
    }
    else if(cmd->part != 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
#if !defined(__SPANISH__)
#if defined(__MEX__)
    if(!strcmp(cmd->pars[0], "SRELAY"))
    {
        //墨西哥版本，任意号码可断油电。
    }
    else
#endif
    {
        if(cmd->return_sms.cm_type == CM_SMS && track_fun_convert_phone_number_to_int(cmd->return_sms.ph_num) != track_fun_convert_phone_number_to_int(G_parameter.centerNumber))
        {
#if defined(__GERMANY__)
            return_message(
                cmd,
                "SMS kommt nicht von der Center-Nr.und wird nicht aktiviert.",
                "来自非法中心号码的指令不执行！");
#else
return_message(
    cmd,
    "The command is not from the center number, The command is not executed!",
    "来自非法中心号码的指令不执行！");
#endif
            return;
        }
    }
#else//__SPANISH__
if(cmd->return_sms.cm_type == CM_SMS && (track_cust_sos_or_center_check(2, cmd->return_sms.ph_num) % 8) != 0 && cmd->supercmd != 1)
{
    return_message(
        cmd,
        "Error: El comando no se ejecutara. No fue enviado de un numero SOS!",
        "来自非法SOS号码的指令不执行！");
    return;
}
#endif/*__SPANISH__*/
#if defined(__GERMANY__)
    track_cust_module_Preheat_System(99);
#endif
    if(!strcmp(cmd->pars[1], "0"))
    {
        track_cust_module_oil_cut_cmd(cmd, KAL_FALSE, KAL_FALSE);
    }
    else if(!strcmp(cmd->pars[1], "1"))
    {
        track_cust_module_oil_cut_cmd(cmd, KAL_TRUE, KAL_FALSE);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (0/1)");
    }
}

/********************************************************************************

        RELAY,1#
            A=0/1；0 接通油电，1 断开油电；默认值为：0
        RELAY#
            查询已设置的参数
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_prelay(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], track_cust_oil_cut(99));
        return;
    }
    else if(cmd->part != 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
#if !defined(__SPANISH__)
    if(cmd->return_sms.cm_type == CM_SMS && track_fun_convert_phone_number_to_int(cmd->return_sms.ph_num) != track_fun_convert_phone_number_to_int(G_parameter.centerNumber))
    {
#if defined(__GERMANY__)
        return_message(
            cmd,
            "SMS kommt nicht von der Center-Nr.und wird nicht aktiviert.",
            "来自非法中心号码的指令不执行！");
#else
return_message(
    cmd,
    "The command is not from the center number, The command is not executed!",
    "来自非法中心号码的指令不执行！");
#endif
        return;
    }
#else
if(cmd->return_sms.cm_type == CM_SMS && (track_cust_sos_or_center_check(2, cmd->return_sms.ph_num) % 8) != 0 && cmd->supercmd != 1)
{
    return_message(
        cmd,
        "Error: El comando no se ejecutara. No fue enviado de un numero SOS!",
        "来自非法SOS号码的指令不执行！");
    return;
}
#endif/*__SPANISH__*/
    if(!strcmp(cmd->pars[1], "0"))
    {
        track_cust_module_oil_cut_cmd(cmd, KAL_FALSE, KAL_TRUE);
    }
    else if(!strcmp(cmd->pars[1], "1"))
    {
        track_cust_module_oil_cut_cmd(cmd, KAL_TRUE, KAL_TRUE);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (0/1)");
    }
}


/******************************************************************************
 *  Function    -  cmd_dyd
 *
 *  Purpose     -  油电控制
 *
 *  Description -  旧的指令，由于服务器使用了，被迫继续兼容；但不支持该短信指令
 *      DYD,000000#
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_dyd(CMD_DATA_STRUCT *cmd)
{
    if(cmd->return_sms.cm_type == CM_SMS) return;
    if(cmd->part != 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(!strcmp(cmd->pars[1], "000000"))
    {
        track_cust_module_oil_cut_cmd(cmd, KAL_TRUE);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: password error!");
        return;
    }
}
/******************************************************************************
 *  Function    -  cmd_frelay
 *
 *  Purpose     -  强制减速断油电
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2016-08-08,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void cmd_frelay(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], track_cust_oil_cut(99));
        return;
    }
    else if(cmd->part != 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(cmd->return_sms.cm_type == CM_SMS && track_fun_convert_phone_number_to_int(cmd->return_sms.ph_num) != track_fun_convert_phone_number_to_int(G_parameter.centerNumber))
    {
        return_message(cmd, "The command is not from the center number, The command is not executed!", "来自非法中心号码的指令不执行！");
        return;
    }
    if(!strcmp(cmd->pars[1], "0"))
    {
        track_cust_module_oil_cut_pulse(cmd, 0);
    }
    else if(!strcmp(cmd->pars[1], "1"))
    {
        track_cust_module_oil_cut_pulse(cmd, 1);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (0/1)");
        return;
    }
}

/******************************************************************************
 *  Function    -  cmd_hdyd
 *
 *  Purpose     -  恢复油电
 *
 *  Description -  旧的指令，由于服务器使用了，被迫继续兼容；但不支持该短信指令
 *      HDYD,000000#
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_hdyd(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part != 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(!strcmp(cmd->pars[1], "000000"))
    {
        track_cust_module_oil_cut_cmd(cmd, KAL_FALSE);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: password error!");
        return;
    }
}

/******************************************************************************
 *  Function    -  cmd_work_mode_set
 *
 *  Purpose     -  终端工作模式设置
 *
 *  Description -  NULL
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 07-08-2013,  ZengPing && Liujw  written
 * ----------------------------------------
 ******************************************************************************/
static void cmd_work_mode_set(CMD_DATA_STRUCT *cmd)
{
    int value;

    if(G_parameter.work_mode.sw == 0)
    {
        sprintf(cmd->rsp_msg, "Error:Mode Not On!");
        return;
    }
    if(cmd->part == 0)
    {
        value = G_parameter.work_mode.mode;
        LOGD(L_CMD, L_V5, "value =%d;work_mode.mode =%d ", value, G_parameter.work_mode.mode);

        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], value);
        return;
    }
    if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);

    if(value < 1 || value > 3)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter (1-3)");
        return;
    }


    G_parameter.work_mode.mode = value;
    if(value == 3)
    {
        track_cust_sleep_mode();
        //track_cust_mode3_work_check((void*)0);
    }
    else
    {
        track_cust_wake_mode();
    }
    if(value != 1)
    {
        //tr_stop_timer(TRACK_CUST_WORK_MODE_GPSUPDATE_TIMER_ID);
        tr_stop_timer(TRACK_CUST_WORK_MODE_GPSUPDATE_OVERTIME_TIMER_ID);
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
/********************************************************************************

        RELAY,1#
            A=0/1；0 接通油电，1 断开油电；默认值为：0
          apagar# = relay,1#
        encender# = relay,0#

 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 30-3-2017,  Cjj  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_spanish_relay(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part > 0)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(cmd->return_sms.cm_type == CM_SMS && (track_cust_sos_or_center_check(2, cmd->return_sms.ph_num) % 8) != 0 && cmd->supercmd != 1)
    {
        return_message(
            cmd,
            "The command is not from the SOS number, The command is not executed!",
            "来自非法SOS号码的指令不执行！");
        return;
    }
    if(!strcmp(cmd->pars[0], "ENCENDER"))
    {
        cmd->pars[0] = "RELAY";
        cmd->pars[1] = "0";
        track_cust_module_oil_cut_cmd(cmd, KAL_FALSE, KAL_FALSE);
    }
    else if(!strcmp(cmd->pars[0], "APAGAR"))
    {
        cmd->pars[0] = "RELAY";
        cmd->pars[1] = "1";
        track_cust_module_oil_cut_cmd(cmd, KAL_TRUE, KAL_FALSE);
    }

}
#endif
#endif
static void cmd_ebat(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        kal_int32 external_voltage;
        float external_batter;
        external_voltage = track_drv_get_external_voltage_status();
        if(external_voltage == -1)
        {
            sprintf(cmd->rsp_msg, "External batter may over the range");
        }
        else if(external_voltage == 0)
        {
            sprintf(cmd->rsp_msg, "No external batter");
        }
        else
        {
            external_batter = (float)external_voltage / 1000000.0;
            sprintf(cmd->rsp_msg, "%s:%4.1fV", cmd->pars[0], external_batter);
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
}


#if defined (__EXT_VBAT_ADC__)
static cmd_exbat(CMD_DATA_STRUCT *cmd)
{
    int current_ext_v = 0;
    if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    current_ext_v = track_drv_get_external_voltage_status();

    if(current_ext_v < 0) 
    {
        current_ext_v = 0;
    }
    sprintf(cmd->rsp_msg, "Current vehicle battery voltage:%0.2fVdc", (float)current_ext_v / 1000000);
}
#endif /* __EXT_VBAT_ADC__ */

/******************************************************************************
 *  Function    -  cmd_DefenseOn
 *
 *  Purpose     -  短信设防
 *
 *  Description -  NULL
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 01-08-2013,  ZengPing & Liujw  written
 * ----------------------------------------
 ******************************************************************************/
static void cmd_DefenseOn(CMD_DATA_STRUCT * Cmds)
{
    if(Cmds->part == 0)
    {
        if(Cmds->supercmd == 1 || (track_cust_sos_or_center_check(2, Cmds->return_sms.ph_num) % 8) == 0 || Cmds->return_sms.cm_type == CM_ONLINE || Cmds->return_sms.cm_type == CM_AT)
        {
            track_cust_check_sos_incall(Cmds, 2);
        }
        else
        {
            sprintf(Cmds->rsp_msg, "Error! Only SOS  phone numbers are allowed to fortification.");
        }
    }
}

/******************************************************************************
 *  Function    -  cmd_DefenseOff
 *
 *  Purpose     -  短信撤防
 *
 *  Description -  NULL
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 01-08-2013,  ZengPing & Liujw  written
 * ----------------------------------------
 ******************************************************************************/
static void cmd_DefenseOff(CMD_DATA_STRUCT * Cmds)
{
    if(Cmds->part == 0)
    {
        if(Cmds->supercmd == 1 || (track_cust_sos_or_center_check(2, Cmds->return_sms.ph_num) % 8) == 0 || Cmds->return_sms.cm_type == CM_ONLINE || Cmds->return_sms.cm_type == CM_AT)
        {
            track_cust_check_sos_incall(Cmds, 0);
        }
        else
        {
            sprintf(Cmds->rsp_msg, "Error! Only SOS  phone numbers are allowed to disarm.");
        }
    }
}

static void cmd_delay_make_sos(void* index)
{
    if(strlen(G_parameter.sos_num[(int)index]))
    {
        track_drv_sys_audio_set_volume(2/*VOL_TYPE_MIC*/, 3/*GAIN_NOR_MIC_VOL6*/);
#if defined(__AUDIO_RC__)
        track_cust_monitor_set_speaket(1);
#endif /* __AUDIO_RC__ */
        track_cust_call(G_parameter.sos_num[(int)index]);
    }
    else
    {
        LOGD(L_APP, L_V5, "SOS %d 已经改变", index);
    }
}
/******************************************************************************
 *  Function    -  cmd_JT
 *
 *  Purpose     -  短信触发回拨监听
 *
 *  Description -  NULL
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 12-12M-2013,  WangQi  written
 * ----------------------------------------
 ******************************************************************************/
static void cmd_JT(CMD_DATA_STRUCT * cmd)
{
#if defined(__GW100__) || defined(__NT55__)
		if(cmd->return_sms.cm_type == CM_ONLINE || cmd->return_sms.cm_type == CM_AT)
		{
			track_cust_record(0, 1, 10);
			sprintf(cmd->rsp_msg, "OK!");
		}
		else if(cmd->return_sms.cm_type == CM_SMS)
		{
			if(cmd->supercmd == 1 || (track_cust_sos_or_center_check(2, cmd->return_sms.ph_num) %  8) == 0)
			{
				track_cust_record(0, 1, 10);
				sprintf(cmd->rsp_msg, "OK!");
			}
			else
			{
#if defined(__GERMANY__)
				sprintf(cmd->rsp_msg, "Fehler: SMS kommt nicht von der Center-Nr. und wird nicht aktiviert.");
#else
				sprintf(cmd->rsp_msg, "Error! Only SOS phone numbers are allowed to listen.");
#endif
			}
		}
#else
    kal_uint8 ret = track_cust_sos_or_center_check(2, cmd->return_sms.ph_num);
    kal_int8 index = 0;
#if defined(__GT740__)
    if(G_parameter.extchip.mode != 1)
    {
        return;
    }
#endif
    LOGD(L_APP, L_V5, "mode:%d,ret:%d,index:%d", track_cust_get_work_mode(), ret, ret / 8);
    if(track_cust_get_work_mode() == WORK_MODE_3)
    {
        return;
    }

    if(cmd->supercmd == 1 || (ret %  8) == 0)
    {
        index = ret / 8 - 1;
        if(0 <= index && index < TRACK_DEFINE_SOS_COUNT)
        {
            sprintf(cmd->rsp_msg, "OK!");
            track_start_timer(TRACK_DELAY_MAKECALL_TEIMER_ID, 30000, cmd_delay_make_sos, (void *)index);
        }
    }
    else
    {
#if defined(__GERMANY__)
        sprintf(cmd->rsp_msg, "Fehler: SMS kommt nicht von der Center-Nr. und wird nicht aktiviert.");
#else
        sprintf(cmd->rsp_msg, "Error! Only SOS phone numbers are allowed to listen.");
#endif
    }
#endif
}
#if 0//现在没有SLEEP跟WAKE模式

/******************************************************************************
 *  Function    -  cmd_SLEEPSET
 *  Purpose     T为休眠间隔，范围：0-1000小时，,0,表示持续休眠（除非退出休眠模式），默认：0
                N为上传点数, 范围：1-10，默认为1；（当T1为非0时）
                （当需要传一个以上的点时，上传间隔为1秒）；
 *  Description -  NULL
 * modification history
 * ----------------------------------------
 * v1.0  , 20141117,  WangQi  written
 * ----------------------------------------
 ******************************************************************************/
static void cmd_SLEEPSET(CMD_DATA_STRUCT * cmd)
{
    int value = 0, value1 = 0;

    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "SLEEPSET,%d,%d", G_parameter.mode3_work_interval / 60, G_parameter.mode3_up_counts);
        return;
    }
    if(cmd->part > 2)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    value = track_fun_atoi(cmd->pars[1]);
    if(value < 0 || value > 1000)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 [0-1000]");
        return;
    }

    if(cmd->part > 1)
    {
        value1 = track_fun_atoi(cmd->pars[2]);
        if(value1 < 1 || value1 > 10)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 [1-10]");
            return;
        }
    }
    LOGD(L_CMD, L_V5, "%d %d,%d", cmd->part, value, value1);
    G_parameter.mode3_work_interval = value * 60;
    G_parameter.mode3_up_counts = (value1 > 0 ? value1 : G_parameter.mode3_up_counts);

    track_cust_mode3_work_check((void*)0);

    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }


}
/******************************************************************************
 *  Function    -  cmd_sleep_set
 *
 *  Purpose     -  深度休眠模式
 *
 *  Description -  NULL
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 07-08-2013,  ZengPing && Liujw  written
 * ----------------------------------------
 ******************************************************************************/
static void cmd_sleep_set(CMD_DATA_STRUCT *cmd)
{
    int value;
    struct_msg_send g_msg = {0};
    kal_bool isChar = KAL_TRUE;
    char *data;
    int len;
    kal_uint8 string1_cn[36] =
    {
        0x95, 0x19, 0x8B, 0xEF, 0xFF, 0x01, 0x8B, 0xF7, 0x57, 0x28, 0x97,
        0x5E, 0x6D, 0xF1, 0x5E, 0xA6, 0x4F, 0x11, 0x77, 0x20, 0x4E, 0x0B,
        0x4F, 0x7F, 0x75, 0x28, 0x6B, 0x64, 0x63, 0x07, 0x4E, 0xE4, 0x30,
        0x02, 0x00, 0x00
    };
    kal_uint8 string1_en[] = "Error!Please use this command at non-deep sleep mode.";
    if(G_parameter.work_mode.sw == 0)
    {

        sprintf(cmd->rsp_msg, "Error:Mode Not On!");
        return;
    }
    if(cmd->part > 0)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    value = G_parameter.work_mode.mode;
    if(value == 1 || value == 2)
    {
        G_parameter.work_mode.mode = value + 3;//用于复用这里在SLEEP,WAKE会进行+2处理
    }
    else if(value == 3)
    {
        g_msg.addUrl = KAL_FALSE;
        g_msg.cm_type = CM_SMS;
        snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, string1_en);
        g_msg.msg_cn_len = 36;
        memcpy(g_msg.msg_cn, string1_cn, g_msg.msg_cn_len);

        if(G_parameter.lang == 1)
        {
            isChar = KAL_FALSE;
            len = g_msg.msg_cn_len;
            data = g_msg.msg_cn;
        }
        else
        {
            isChar = KAL_TRUE;
            len = strlen(g_msg.msg_en);
            data = g_msg.msg_en;
        }
        if(g_msg.msg_cn_len)
        {
            /*  指令解析执行体只填充信息，全部在此发出*/
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                //track_cmd_sms_rsp(cmd);
                track_cust_sms_send(cmd->return_sms.num_type, cmd->return_sms.ph_num, isChar, data, len);
            }
            else if(cmd->return_sms.cm_type == CM_ONLINE)
            {
                track_cust_paket_msg_upload(cmd->return_sms.stamp, isChar, data, len);
            }
            else if(cmd->return_sms.cm_type == CM_ONLINE2)
            {
                track_cust_paket_FD_cmd(cmd->return_sms.stamp, isChar, data, len);
            }
            else if(cmd->return_sms.cm_type ==  CM_AT)
            {
                sprintf(cmd->rsp_msg, "Error!Please use this command at non-deep sleep mode.");
            }
        }
        return;
    }
    track_cust_sleep_mode();
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }

}

/******************************************************************************
 *  Function    -  cmd_wake_set
 *
 *  Purpose     -  退出深度休眠
 *
 *  Description -  NULL
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 07-08-2013,  ZengPing && Liujw  written
 * ----------------------------------------
 ******************************************************************************/
static void cmd_wake_set(CMD_DATA_STRUCT *cmd)
{
    int value;
    struct_msg_send g_msg = {0};
    kal_bool isChar = KAL_TRUE;
    char *data;
    int len;
    kal_uint8 string1_cn[36] = {0x95, 0x19, 0x8B, 0xEF, 0xFF, 0x01, 0x8B, 0xF7, 0x57, 0x28, 0x97,
                                0x5E, 0x6D, 0xF1, 0x5E, 0xA6, 0x4F, 0x11, 0x77, 0x20, 0x4E, 0x0B, 0x4F, 0x7F, 0x75, 0x28, 0x6B, 0x64, 0x63, 0x07, 0x4E, 0xE4, 0x30, 0x02, 0x00, 0x00
                               };
    kal_uint8 string1_en[] = "Error!Please use this command at non-deep sleep mode.";
    if(G_parameter.work_mode.sw == 0)
    {

        sprintf(cmd->rsp_msg, "Error:Mode Not On!");
        return;
    }
    if(cmd->part > 0)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    value = G_parameter.work_mode.mode;
    LOGD(L_CMD, L_V5, "value =%d;work_mode.mode =%d ", value, G_parameter.work_mode.mode);
    if(value == 5 || value == 4)
    {
        G_parameter.work_mode.mode = value - 3;//用于复用这里在SLEEP,WAKE会进行+2处理
    }
    else if(value == 3)
    {
        g_msg.addUrl = KAL_FALSE;
        g_msg.cm_type = CM_SMS;
        snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, string1_en);
        g_msg.msg_cn_len = 36;
        memcpy(g_msg.msg_cn, string1_cn, g_msg.msg_cn_len);

        if(G_parameter.lang == 1)
        {
            isChar = KAL_FALSE;
            len = g_msg.msg_cn_len;
            data = g_msg.msg_cn;
        }
        else
        {
            isChar = KAL_TRUE;
            len = strlen(g_msg.msg_en);
            data = g_msg.msg_en;
        }
        if(g_msg.msg_cn_len)
        {
            /*  指令解析执行体只填充信息，全部在此发出*/
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                //track_cmd_sms_rsp(cmd);
                track_cust_sms_send(cmd->return_sms.num_type, cmd->return_sms.ph_num, isChar, data, len);
            }
            else if(cmd->return_sms.cm_type == CM_ONLINE)
            {
                track_cust_paket_msg_upload(cmd->return_sms.stamp, isChar, data, len);
            }
            else if(cmd->return_sms.cm_type == CM_ONLINE2)
            {
                track_cust_paket_FD_cmd(cmd->return_sms.stamp, isChar, data, len);
            }
            else if(cmd->return_sms.cm_type ==  CM_AT)
            {
                sprintf(cmd->rsp_msg, "Error!Please use this command at non-deep sleep mode.");
            }
        }
        return;
    }
    LOGD(L_CMD, L_V5, "value =%d;work_mode.mode =%d ", value, G_parameter.work_mode.mode);
    track_cust_wake_mode();
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#endif

#if 0
static void cmd_lbs(CMD_DATA_STRUCT *cmd)
{
    LBS_Multi_Cell_Data_Struct *lbs;
    if(cmd->part > 0)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    lbs = track_drv_get_lbs_data();
    track_cust_paket_18(lbs, 0);
    sprintf(cmd->rsp_msg, "OK!");
    return;

    /*直接上报平台，不回复短信       --    chengjun  2017-10-09*/
    //lbs_cmd_send(cmd);
}
static void cmd_lbson(CMD_DATA_STRUCT *cmd)
{
    nvram_lbson_struct lbson = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d", cmd->pars[0],
                ON_OFF(G_parameter.lbson.sw), G_parameter.lbson.t1, G_parameter.lbson.t2);
        return;
    }
    else if(cmd->part > 3)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    memcpy(&lbson, &G_parameter.lbson, sizeof(nvram_lbson_struct));
    if(!strcmp(cmd->pars[1], "ON"))
        lbson.sw = 1;
    else if(!strcmp(cmd->pars[1], "OFF"))
        lbson.sw = 0;
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    if(cmd->part >= 2)
    {
        lbson.t1 = track_fun_atoi(cmd->pars[2]);
        if(lbson.t1 < 10 || lbson.t1 > 3600)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (10 - 3600)");
            return;
        }
    }
    if(cmd->part >= 3)
    {
        lbson.t2 = track_fun_atoi(cmd->pars[3]);
        if(lbson.t2 < 10 || lbson.t2 > 3600)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 3 (10 - 3600)");
            return;
        }
    }
    memcpy(&G_parameter.lbson, &lbson, sizeof(nvram_lbson_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
        track_cust_LBS_upload();
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#endif

static void cmd_defmode(CMD_DATA_STRUCT *cmd)
{
    int value = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s: %d", cmd->pars[0],
                G_realtime_data.defense_mode);
        return;
    }

    if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    value = track_fun_atoi(cmd->pars[1]);
    if(value < 0 || value > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter (0-1)");
        return;
    }

    G_realtime_data.defense_mode = value;
    if(Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
    if(G_realtime_data.defense_mode == 0)
    {
        track_cust_defences_cmd_update();
    }
#if defined(__PARAM_CHANGE_UPDATE_SERVER__)
    track_cust_paket_9404_handle();
#endif
}
#if defined(__ET310__) || defined(__MT200__)

static void cmd_ps(CMD_DATA_STRUCT *cmd)
{
    int value;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], ON_OFF(G_realtime_data.location_switch));
        return;
    }
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        G_realtime_data.location_switch = 1;
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        G_realtime_data.location_switch = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    if(Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
/******************************************************************************
*  Function    -  track_cust_led_on
*
*  Purpose     -  开启led灯
*
*  Description -
*
*  modification history
* ----------------------------------------
* v1.0  , 01 - 06 - 2013,  jwj       written
* ----------------------------------------
*******************************************************************************/
void track_cust_led_on(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        if(track_cust_led_sleep(99) != 1)
        {
            track_cust_led_sleep(1);
        }
        G_realtime_data.key_status = 1;
        //Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
    }
}

/******************************************************************************
 *  Function    -  track_cust_led_off
 *
 *  Purpose     -  开启led灯
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 01-06-2013,  jwj       written
 * ----------------------------------------
*******************************************************************************/
void track_cust_led_off(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        if(track_cust_led_sleep(99) == 1)
        {
            track_cust_led_sleep(2);
        }
        G_realtime_data.key_status = 0;
        //Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
    }
}
#endif
/******************************************************************************
 *  Function    -  cmd_tql
 *
 *  Purpose     -  电话查询位置
 *
 *  Description -
        TQL,<X>#
            X=ON/OFF；ON:开启电话查询位置；OFF:关闭电话查询位置；默认开关状态为OFF
        TQL#
            查询总里程，及设置的初值
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 11-25-2014,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_tql(CMD_DATA_STRUCT *cmd)
{
    U8 call_get_addr_sw = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], ON_OFF(G_parameter.call_get_addr_sw));
        return;
    }
    call_get_addr_sw = G_parameter.call_get_addr_sw;
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        call_get_addr_sw = 1;
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        call_get_addr_sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    G_parameter.call_get_addr_sw = call_get_addr_sw;
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    sprintf(cmd->rsp_msg, "OK!");
}

static void cmd_sys(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "");
        return;
    }
    if(!strcmp(cmd->pars[1], "A"))
    {
        track_test_view_backup(cmd->rsp_msg);
        track_test_view_queue(cmd->rsp_msg + strlen(cmd->rsp_msg));
        Ram_view(cmd->rsp_msg + strlen(cmd->rsp_msg));
    }
    else if(!strcmp(cmd->pars[1], "B"))
    {
        if(!strcmp(cmd->pars[2], "DEL"))
        {
            track_os_log_abnormal_data_reset();
        }
        track_os_log_abnormal_data_view(cmd->rsp_msg);
    }
    else if(!strcmp(cmd->pars[1], "C"))
    {
        kal_uint32 addr = NULL;
        int len;
        if(cmd->part != 3)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        addr = track_fun_parse4(cmd->pars[2]);
        len  = track_fun_atoi(cmd->pars[3]);
        if(len < 1 || len > 1000)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (1 to 1000)");
            return;
        }
        LOGD(L_APP, L_V3, "%p", (void*)addr);
        LOGH(L_APP, L_V4, (void*)addr, len);
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            track_fun_mem_to_ascii(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, (void*)addr, len);
        }
    }
    else if(!strcmp(cmd->pars[1], "MIAN"))
    {
        track_drv_sys_l4cuem_set_audio_mode(atoi(cmd->pars[2]));
    }
    else if(!strcmp(cmd->pars[1], "FLASH"))
    {
        G_realtime_data.flashtime=atoi(cmd->pars[2]);
       // G_realtime_data.tracking_time = atoi(cmd->pars[3]);
    }
#if defined(__EL100__)
    else if(!strcmp(cmd->pars[1], "DIDI"))
    {
        track_project_didi();
    }
#endif
    else if(!strcmp(cmd->pars[1], "D") || !strcmp(cmd->pars[1], "START_TIME"))
    {
        kal_uint32 tick, ms, sec, min, hour, day;
        tick = kal_get_systicks();
        ms = kal_ticks_to_milli_secs(tick);
        if(ms > 86400000)
        {
            day = ms / 86400000;
            ms -= day * 86400000;
            hour = ms / 3600000;
            ms -= hour * 3600000;
            min = ms / 60000;
            ms -= min * 60000;
            sec = ms / 1000;
            ms -= sec * 1000;
            sprintf(cmd->rsp_msg, "Start system:%dday %dhour %dmin %dsec %dms", day, hour, min, sec, ms);
        }
        else if(ms > 3600000)
        {
            hour = ms / 3600000;
            ms -= hour * 3600000;
            min = ms / 60000;
            ms -= min * 60000;
            sec = ms / 1000;
            ms -= sec * 1000;
            sprintf(cmd->rsp_msg, "Start system:%dhour %dmin %dsec %dms", hour, min, sec, ms);
        }
        else if(ms > 60000)
        {
            min = ms / 60000;
            ms -= min * 60000;
            sec = ms / 1000;
            ms -= sec * 1000;
            sprintf(cmd->rsp_msg, "Start system:%dmin %dsec %dms", min, sec, ms);
        }
        else if(ms > 1000)
        {
            sec = ms / 1000;
            ms -= sec * 1000;
            sprintf(cmd->rsp_msg, "Start system:%dsec %dms", sec, ms);
        }
        else
        {
            sprintf(cmd->rsp_msg, "Start system:%dms, ", ms);
        }
    }
    else if(!strcmp(cmd->pars[1], "TIME"))
    {
        applib_time_struct currTime = {0};
        applib_dt_get_rtc_time(&currTime);
        sprintf(cmd->rsp_msg, "%0.2d-%0.2d-%0.2d %0.2d:%0.2d:%0.2d",
                currTime.nYear, currTime.nMonth, currTime.nDay,
                currTime.nHour, currTime.nMin, currTime.nSec);
    }
    else if(!strcmp(cmd->pars[1], "SERVER2OFF"))
    {
        G_importance_parameter_data.server2.conecttype = 2;
        if(Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "OK!");
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error!");
        }

    }
    else if(!strcmp(cmd->pars[1], "SLEEPTEST"))
    {
        track_drv_sleep_enable(atoi(cmd->pars[2]), atoi(cmd->pars[3]));
        sprintf(cmd->rsp_msg, "SLEEP Test,%d,%d", atoi(cmd->pars[2]), atoi(cmd->pars[3]));
    }
    else if(!strcmp(cmd->pars[1], "E"))
    {
        track_cust_led_status_view(cmd->rsp_msg);
    }
    else if(!strcmp(cmd->pars[1], "F") && cmd->part == 3)
    {
        track_test_ram(cmd->rsp_msg, track_fun_atoi(cmd->pars[2]), track_fun_atoi(cmd->pars[3]));
    }
    else if(!strcmp(cmd->pars[1], "G") || !strcmp(cmd->pars[1], "GPS"))
    {
        if(!strcmp(cmd->pars[2], "ON"))
        {
            track_cust_gps_control(1);
            sprintf(cmd->rsp_msg, "GPS ON");
        }
        else if(!strcmp(cmd->pars[2], "OFF"))
        {
            track_cust_gps_control(0);
            sprintf(cmd->rsp_msg, "GPS OFF");
        }
        else if(!strcmp(cmd->pars[2], "RESET_STATUS"))
        {
            track_drv_gps_epo_start();
        }
    }
    else if(!strcmp(cmd->pars[1], "BMT"))
    {
        uem_bmt_struct bmt_status = {0};
        uem_get_bat_status(&bmt_status);
        sprintf(cmd->rsp_msg, "OK! vbat_percentage:%d, status:%d, volt:%d, adc:%f",
                uem_get_vbat_percentage(),
                (kal_uint8)bmt_status.status,
                (kal_uint32)bmt_status.volt,
                (double)bmt_status.adc);
    }
    else if(!strcmp(cmd->pars[1], "TIMER"))
    {
        track_timer_Remaining(cmd->rsp_msg, atoi(cmd->pars[2]));
    }
    else if(!strcmp(cmd->pars[1], "RESET1"))
    {
        DRV_RESET();
        LOGD(L_APP, L_V5, "DRV_RESET");
    }
    else if(!strcmp(cmd->pars[1], "POWER_OFF"))
    {
        uem_drv_power_off();
        LOGD(L_APP, L_V5, "uem_drv_power_off");
    }
    else if(!strcmp(cmd->pars[1], "L4_POWER_OFF"))
    {
        l4cuem_power_off_req();
        LOGD(L_APP, L_V5, "l4cuem_power_off_req");
    }
    else if(!strcmp(cmd->pars[1], "ASSERT"))
    {
        ASSERT(0);
        sprintf(cmd->rsp_msg, "OK!");
    }
    else if(!strcmp(cmd->pars[1], "ASSERT2"))
    {
        *OTA_INT_MemoryDumpFlag = 0x26409001;
        ASSERT(0);
        //sprintf(cmd->rsp_msg, "OK!");
    }
    else if(!strcmp(cmd->pars[1], "ASSERT_NOT_R"))
    {
        *OTA_INT_MemoryDumpFlag = 0x26409001;
        sprintf(cmd->rsp_msg, "OK! ASSERT can not be restart.");
    }
    else if(!strcmp(cmd->pars[1], "WATCH_DOG_S"))
    {
        track_drv_watch_dog_close(0);
        sprintf(cmd->rsp_msg, "Watch dog OFF");
    }
    else if(!strcmp(cmd->pars[1], "DELFILE"))
    {
        int result;
        WCHAR FilePath[60] = {0};
        kal_wsprintf(FilePath, cmd->pars[2]);
        result = FS_Delete(FilePath);
        sprintf(cmd->rsp_msg, "Del %s = %d", cmd->pars[2], result);
        return;
    }
    else if(!strcmp(cmd->pars[1], "RECONNSERVER2"))
    {
        extern kal_uint8  is_rev_data;
        is_rev_data = 0;
        track_cust_server2_file_retry();
        track_os_intoTaskMsgQueueExt(track_cust_server2_conn, (void*)2);
        sprintf(cmd->rsp_msg, "OK");
    }
    else if(!strcmp(cmd->pars[1], "VER"))
    {
        char ver_string[300] = {0};
        int ver_str_len = 0;
        kal_uint8 *result;
        result = track_drv_get_chip_id();
        ver_str_len += snprintf(ver_string + ver_str_len, 299, "Chip RID:%0.2X%0.2X%0.2X%0.2X%0.2X%0.2X%0.2X%0.2X%0.2X%0.2X%0.2X%0.2X%0.2X%0.2X%0.2X%0.2X, ",
                                result[0], result[1], result[2], result[3], result[4], result[5], result[6], result[7],
                                result[8], result[9], result[10], result[11], result[12], result[13], result[14], result[15]);
        ver_str_len += snprintf(ver_string + ver_str_len, 299, "IMEI:%s, %s", (char*)track_drv_get_imei(0), track_cust_get_version_for_upload_server());
        sprintf(cmd->rsp_msg, "[%d]%s", ver_str_len, ver_string);
    }
    else if(!strcmp(cmd->pars[1], "VIEWIP"))
    {
        track_soc_view_IP(cmd->rsp_msg);
    }
    else if(!strcmp(cmd->pars[1], "TWO"))
    {
        if(!strcmp(cmd->pars[2], "R"))
        {
            int a = atoi(cmd->pars[3]);
            int B = atoi(cmd->pars[4]);
            track_drv_led_switch(LED_GREEN, KAL_FALSE);
            LED_Set_Flash(LED_RED, a, B);
        }
        else if(!strcmp(cmd->pars[2], "G"))
        {
            int a = atoi(cmd->pars[3]);
            int B = atoi(cmd->pars[4]);

            track_drv_led_switch(LED_RED, KAL_FALSE);
            LED_Set_Flash(LED_GREEN, a, B);

        }
        else
        {
            int a = atoi(cmd->pars[3]);
            int B = atoi(cmd->pars[4]);
            LED_Set_Flash(LED_GREEN, a, B);
            LED_Set_Flash(LED_RED, a, B);
        }

    }
    else if(!strcmp(cmd->pars[1], "RESTARTSYSTEM"))
    {
        int len;
        nvram_check_ota_struct g_otacheck = {0};
        Track_nvram_read(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
        len = sprintf(cmd->rsp_msg, "[%02d-%02d-%02d] Count:%d/%d, Day:%d/%d",
                      g_otacheck.dateCount[0] + 2000, g_otacheck.dateCount[1], g_otacheck.dateCount[2],
                      g_otacheck.resetCount, g_otacheck.resetCountMax,
                      g_otacheck.resetDay, g_otacheck.resetDayMax);
        if(cmd->part > 2)
        {
            g_otacheck.resetCount    = track_fun_atoi(cmd->pars[2]);
            g_otacheck.resetCountMax = track_fun_atoi(cmd->pars[3]);
            g_otacheck.resetDay      = track_fun_atoi(cmd->pars[4]);
            g_otacheck.resetDayMax   = track_fun_atoi(cmd->pars[5]);
            sprintf(cmd->rsp_msg + len, " change (Count:%d/%d, Day:%d/%d)",
                    g_otacheck.resetCount, g_otacheck.resetCountMax,
                    g_otacheck.resetDay, g_otacheck.resetDayMax);
            Track_nvram_write(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
        }
    }
    else
    {
        int value = track_fun_atoi(cmd->pars[1]);
        switch(value)
        {
            case 11:
                {
                    track_cust_fetion_auto_authorize_valid((void*)1);
                    sprintf(cmd->rsp_msg, "OK!");
                    break;
                }
            case 111:
                {
                    extern kal_bool test_test_test;
                    if(!strcmp(cmd->pars[2], "0"))
                    {
                        test_test_test = 0;
                    }
                    else
                    {
                        test_test_test = 1;
                    }
                    break;
                }
            case 112:
                {
                    sprintf(cmd->rsp_msg, "SUM:%d, G_importance_parameter_data:%d, G_parameter:%d, G_realtime_data:%d",
                            sizeof(G_importance_parameter_data) + sizeof(G_parameter) + sizeof(G_realtime_data),
                            sizeof(G_importance_parameter_data), sizeof(G_parameter), sizeof(G_realtime_data));
                    break;
                }
            case 113:
                {
                    sprintf(cmd->rsp_msg, "FS_GetDiskInfo:%d", track_fun_FS_GetDiskInfo());
                    break;
                }
            case 114:
                {
                    //track_read_imsi_data();
                    track_socket_apn_auto_set();
                    break;
                }
            case 115:
                {
#if defined(__JSON__)
                    main44();
#endif /* __JSON__ */
                    sprintf(cmd->rsp_msg, "main44!");
                    break;
                }
            case 12:
                {
                    // ASCII
                    if(G_importance_parameter_data.server.conecttype == 0)
                    {
                        sprintf(cmd->rsp_msg, "IMEI:%s, SERVER,0,%d.%d.%d.%d,%d,%d, [VERSION]%s\r\n[BUILD]%s\r\n", (char *)track_drv_get_imei(0),
                                G_importance_parameter_data.server.server_ip[0], G_importance_parameter_data.server.server_ip[1],
                                G_importance_parameter_data.server.server_ip[2], G_importance_parameter_data.server.server_ip[3],
                                G_importance_parameter_data.server.server_port, G_importance_parameter_data.server.soc_type,
                                release_verno(), build_date_time());
                    }
                    else
                    {
                        sprintf(cmd->rsp_msg, "IMEI:%s, SERVER,%d,%s,%d,%d, [VERSION]%s\r\n[BUILD]%s\r\n", (char *)track_drv_get_imei(0),
                                G_importance_parameter_data.server.conecttype,
                                track_domain_decode(G_importance_parameter_data.server.url),
                                G_importance_parameter_data.server.server_port,
                                G_importance_parameter_data.server.soc_type,
                                release_verno(), build_date_time());
                    }
                    if(strlen(cmd->pars[2]) > 0)
                    {
                        track_cust_sms_send(cmd->return_sms.num_type, cmd->pars[2], KAL_TRUE, cmd->rsp_msg, strlen(cmd->rsp_msg));
                        if(cmd->return_sms.cm_type == CM_SMS) cmd->rsp_msg[0] = 0;
                    }
                    break;
                }
            case 121:
                {
                    track_drv_sys_cfun(0);
                    sprintf(cmd->rsp_msg, "turn off radio and SIM power!");
                    break;
                }
            case 122:
                {
                    track_drv_sys_cfun(1);
                    sprintf(cmd->rsp_msg, "fly mode!");
                    break;
                }
            case 123:
                {
                    track_drv_sys_cfun(4);
                    sprintf(cmd->rsp_msg, "exit fly mode!");
                    break;
                }
            case 131:
                {
                    track_epo_file_size();
                    sprintf(cmd->rsp_msg, "OK!");
                    break;
                }
            case 132:
                {
                    /* 1422748800 = 2015-02-01 00:00:00*/
                    U32 t1, t2, t3;
                    applib_time_struct *time = (applib_time_struct*)Ram_Alloc(1, sizeof(applib_time_struct));
                    time->DayIndex = 0;
                    time->nHour = 0;
                    time->nMin = 0;
                    time->nSec = 0;
                    time->nDay = 1;
                    time->nMonth = 2;
                    time->nYear = 2017;
                    t1 = OTA_applib_dt_mytime_2_utc_sec(time, 0);
                    time->nMonth = 1;
                    t2 = OTA_applib_dt_mytime_2_utc_sec(time, 0);
                    time->nYear = 2015;
                    time->nMonth = 2;
                    t3 = OTA_applib_dt_mytime_2_utc_sec(time, 0);
                    sprintf(cmd->rsp_msg, "%d,%d, 2015 %d", t1, t2, t3);
                    Ram_Free(time);
                    break;
                }
            case 133:
                {
                    G_parameter.gps_work.static_filter_sw = 2;
                    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
                    sprintf(cmd->rsp_msg, "Two static inhibition open!");
                    break;
                }
            case 134:
                {
                    nvram_check_ota_struct g_otacheck = {0};
                    Track_nvram_read(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
                    g_otacheck.unconditional = track_fun_atoi(cmd->pars[2]);
                    Track_nvram_write(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
                    sprintf(cmd->rsp_msg, "g_otacheck.unconditional=%d", g_otacheck.unconditional);
                    break;
                }
            case 135:
                {
                    U8 md5_for_file[16] = {0};
                    track_cust_get_data_from_file(FOTA_MD5_FILE_PATH, md5_for_file, 16);
                    track_fun_mem_to_ascii(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, (void*)md5_for_file, 16);
                }
            case 14:
                {
                    G_parameter.gps_work.Fd.sw = 0;
                    G_parameter.gps_work.Fti.sw = 1;
                    G_parameter.gps_work.Fti.interval_acc_off = track_fun_atoi(cmd->pars[2]);
                    G_parameter.gps_work.Fti.interval_acc_on = track_fun_atoi(cmd->pars[2]);
                    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
                    sprintf(cmd->rsp_msg, "OK!");
                    break;
                }
            case 146:
                {
                    nvram_gps_last_data_struct backup = {0};
                    track_cust_nvram_gps_last_rmc(1, (kal_uint8*)&backup);
                    LOGD(L_APP, L_V5, "status=%d, nYear=%d,month=%d,nDay=%d, Lat:%0.6f, Lon:%0.6f",
                         backup.rmc.status, backup.rmc.Date_Time.nYear, backup.rmc.Date_Time.nMonth, backup.rmc.Date_Time.nDay, backup.rmc.Latitude, backup.rmc.Longitude);
                    break;
                }
            case 15:
                {
                    extern void track_cust_sim_restart(void * arg);
                    track_cust_sim_restart((void*)1);
                    sprintf(cmd->rsp_msg, "OK! Restarting SIM...");
                    break;
                }

            case 161:
                {
                    sprintf(cmd->rsp_msg, "%d (MOD_ATCI:%d, MOD_MMI:%d, MOD_L4C:%d, MOD_DRV_HISR:%d, MOD_EINT_HISR:%d)",
                            kal_get_active_module_id(),
                            MOD_ATCI,
                            MOD_MMI,
                            MOD_L4C,
                            MOD_DRV_HISR,
                            MOD_EINT_HISR);
                    break;
                }
            case 163:
                {
                    track_at_to_atci_send("at+csq\r\n", 8);
                    sprintf(cmd->rsp_msg, "OK!");
                    break;
                }
            case 164:
                {
                    track_cust_sim_backup_for_parameter();
                    sprintf(cmd->rsp_msg, "OK!");
                    break;
                }
            case 3:
                {
                    extern void track_soc_queue_all_to_nvram(void);
                    track_os_intoTaskMsgQueue(track_soc_queue_all_to_nvram);
                    sprintf(cmd->rsp_msg, "OK!");
                }
                break;

            case 32:
                {
                    //track_cust_ram_alarm(1034004, 16);
                    //sprintf(cmd->rsp_msg, "tick=%d", kal_secs_to_ticks(30*60));
                    track_check_tick(2, cmd->rsp_msg);
                }
                break;

            case 4:
                g_test_flag = track_fun_atoi(cmd->pars[2]);
                sprintf(cmd->rsp_msg, "OK!");
                break;

            case 41:
                track_cust_write_sim_backup_for_parameter();
                sprintf(cmd->rsp_msg, "OK!");
                break;

            case 42:
                break;

            case 423:/*时间测试*/
                {
                    U32 timep;
                    static applib_time_struct tmp = {0};
                    applib_dt_get_rtc_time(&tmp);
                    LOGS("time: %0.2d-%0.2d-%0.2d %0.2d:%0.2d:%0.2d", tmp.nYear, tmp.nMonth, tmp.nDay, tmp.nHour, tmp.nMin, tmp.nSec);

                    /*获得当前时间的秒数*/
                    /*timep = OTA_app_getcurrtime();
                    applib_dt_utc_sec_2_mytime(timep, &tmp, 0);
                    LOGS("time: %0.2d-%0.2d-%0.2d %0.2d:%0.2d:%0.2d", tmp.nYear, tmp.nMonth, tmp.nDay, tmp.nHour, tmp.nMin, tmp.nSec);

                    tmp.nYear = 2015;
                    tmp.nMonth = 2;
                    tmp.nDay = 1;
                    tmp.nHour = 0;
                    tmp.nMin = 0;
                    tmp.nSec = 0;
                    timep = applib_dt_mytime_2_utc_sec(&tmp, 0);
                    LOGS("距离2014年秒数:%d, %d", timep, OTA_app_getcurrtime() - timep);*/

                    /* 1420070400 = 2015-01-01 00:00:00*/

                    tmp.nYear = 2015;
                    tmp.nMonth = 1;
                    tmp.nDay = 1;
                    tmp.nHour = 0;
                    tmp.nMin = 0;
                    tmp.nSec = 0;
                    timep = applib_dt_mytime_2_utc_sec(&tmp, 0);
                    LOGS("2015年秒数:%d", timep);

                    tmp.nYear = 2015;
                    tmp.nMonth = 2;
                    tmp.nDay = 1;
                    tmp.nHour = 0;
                    tmp.nMin = 0;
                    tmp.nSec = 0;
                    timep = applib_dt_mytime_2_utc_sec(&tmp, 0);
                    LOGS("2015年2月秒数:%d", timep);
                }
                break;

            case 43:
                G_realtime_data.in_or_out[0] = track_fun_atoi(cmd->pars[2]);
                sprintf(cmd->rsp_msg, "OK!");
                break;

#if defined(__SIM_CU_CALL__)
            case 431:
                track_cust_SIM_findBalance();
                sprintf(cmd->rsp_msg, "话费查询 OK!");
                break;

            case 432:
                track_cust_SIM_call("10086");
                sprintf(cmd->rsp_msg, "OK!");
                break;
#endif /* __SIM_CU_CALL__ */

            case 44:
                {
                    unsigned char Plain2[16] =
                    {
                        0xA5, 0x6C, 0x7D, 0x75, 0x48, 0xDE, 0xFF, 0xEF, 0xE7, 0xAC, 0x1E, 0xA9, 0xBC, 0xCE, 0x66, 0xE6
                    };
                    unsigned char Plain[16] =
                    {
                        0x06, 0x01, 0x01, 0x01, 0x2D, 0x1A, 0x68, 0x3D, 0x48, 0x27, 0x1A, 0x18, 0x31, 0x6E, 0x47, 0x1A
                    };
                    unsigned char key[16] =
                    {
                        0x3A, 0x60, 0x43, 0x2A, 0x5C, 0x01, 0x21, 0x1F, 0x29, 0x1E, 0x0F, 0x4E, 0x0C, 0x13, 0x28, 0x25
                    };
                    unsigned char pCipherText[16] = {0};
                    AES_Init(key);
                    LOGH2(L_APP, L_V1, "密匙:", key, 16);
                    LOGH2(L_APP, L_V1, "原文:", Plain, 16);
                    AES_Encrypt(Plain, pCipherText, 16, NULL);
                    LOGH2(L_APP, L_V1, "密文:", pCipherText, 16);
                    memset(Plain, 0, 16);
                    AES_Decrypt(Plain, pCipherText, 16, NULL);
                    LOGH2(L_APP, L_V1, "解密:", Plain, 16);
                    memset(Plain, 0, 16);
                    AES_Decrypt(Plain, Plain2, 16, NULL);
                    LOGH2(L_APP, L_V1, "解密2:", Plain, 16);
                    sprintf(cmd->rsp_msg, "OK!");
                }
                break;
        }
    }
}

static void cmd_(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "");
        return;
    }
    else if(cmd->part < 3 || cmd->part > 4)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
}
static void cmd_gpson(CMD_DATA_STRUCT *cmd)
{
    nvram_gps_work_struct tmp = {0};
    int value = 0;
    kal_bool flag = 1;
    extern   void track_cust_module_init(void);

    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "OK!");
        track_cust_gpson_timer(0);
        track_cust_gps_work_req((void *)14);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 5 || value > 300)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (5-300)");
        return;
    }
    track_cust_gpson_timer(value);
    track_cust_gps_work_req((void *)14);
    sprintf(cmd->rsp_msg, "OK!");
}
#if defined(__NF2318__)
#else
/******************************************************************************
 *  Function    -  cmd_server
 *
 *  Purpose     -  设置定位服务器地址参数
 *
 *  Description -  SERVER,<使用密码>, <模式>,<地址>,<端口>,<传输协议模式>#
 *                 SERVER,0,202.173.231.112,8821,0#
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 08-01-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_dserver(CMD_DATA_STRUCT *cmd)
{
    int value, plen;
    nvram_server_addr_struct server = {0};
#if defined (__SAME_GT02__)
    if(G_importance_parameter_data.app_version.version == 2)
    {
        return ;
    }
#endif
	return;

    if(cmd->part == 0)
    {
        if(G_importance_parameter_data.dserver.conecttype == 0)
        {
            sprintf(cmd->rsp_msg, "DSERVER,0,%d.%d.%d.%d,%d,%d",
                    G_importance_parameter_data.dserver.server_ip[0], G_importance_parameter_data.dserver.server_ip[1],
                    G_importance_parameter_data.dserver.server_ip[2], G_importance_parameter_data.dserver.server_ip[3],
                    G_importance_parameter_data.dserver.server_port, G_importance_parameter_data.dserver.soc_type);
        }
        else
        {
            sprintf(cmd->rsp_msg, "SERVER,%d,%s,%d,%d",
                    G_importance_parameter_data.dserver.conecttype,
                    track_domain_decode(G_importance_parameter_data.dserver.url),
                    G_importance_parameter_data.dserver.server_port,
                    G_importance_parameter_data.dserver.soc_type);
        }
        return;
    }
    if(cmd->part != 3 && cmd->part != 4)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(G_importance_parameter_data.server.lock != 0)
    {
        sprintf(cmd->rsp_msg, "Error: The platform addresses are Locked modify!");
        return;
    }
    memset(cmd->rsp_msg, 0, sizeof(cmd->rsp_msg));

    memcpy(&server, &G_importance_parameter_data.dserver, sizeof(nvram_server_addr_struct));

    value = track_fun_atoi(cmd->pars[CM_Par1]);
    if(value != 0 && value != 1)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (0/1)");
        return;
    }
    server.conecttype = value;

    plen = strlen(cmd->pars[CM_Par2]);
    if(plen <= 0)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 2 is empty!");
        return;
    }
    if(plen >= 99)
    {
        sprintf(cmd->rsp_msg, "Error: Parameters 2 characters too long!");
        return;
    }
    if(track_fun_check_ip(cmd->pars[CM_Par2]))
    {
        if(server.conecttype != 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 domain is not formatted correctly!");
            return;
        }
        memset(server.server_ip, 0, 4);
        if(!track_fun_asciiIP2Hex(cmd->pars[CM_Par2], (void*)&server.server_ip[0]))
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 is not a valid IP address format!");
            return;
        }
    }
    else
    {
        if(server.conecttype != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 is not a valid IP address format!");
            return;
        }
        if(strstr(cmd->pars[CM_Par2], "http://"))
        {
            sprintf(cmd->rsp_msg, "Error: The domain name does not include \"http://\"!");
            return;
        }
        {
            char domain[TRACK_MAX_URL_SIZE] = {0};
            memcpy(domain, cmd->rcv_msg_source + (cmd->pars[CM_Par2] - cmd->rcv_msg), plen);
            track_domain_encode(domain, server.url);
        }
    }

    if(!track_fun_check_data_is_port(cmd->pars[CM_Par3]))
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 3 (0~65535)");
        return;
    }
    server.server_port = track_fun_string2U16(cmd->pars[CM_Par3]);

    if(cmd->part == 4)
    {
        value = track_fun_atoi(cmd->pars[CM_Par4]);
        if(value != 0 && value != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 4 (0/1)");
            return;
        }
    }
    server.soc_type = 0; // 当前只支持TCP
    server.server_type = 1;
    memcpy(&G_importance_parameter_data.dserver, &server, sizeof(nvram_server_addr_struct));
    G_importance_parameter_data.dserver.ip_update = 0;
    G_importance_parameter_data.server.ip_update = 0;
    Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
    sprintf(cmd->rsp_msg, "OK");
    track_set_server_ip_status(0);

    track_os_intoTaskMsgQueueExt(track_soc_gprs_reconnect, (void*)22);//修改域名后，重新建立连接
    //track_os_intoTaskMsgQueue(track_cust_write_sim_backup_for_parameter);
}

/******************************************************************************
 *  Function    -  sms_cmd_see_parameters
 *
 *  Purpose     -  查看SOS,IMEI,及震动,油控状态
 *
 *  Description - PARAM#
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 17-05-2010,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
static void gt02_param(CMD_DATA_STRUCT *cmd)
{
    S8 temp[300], data[300];
    int i = 0;
    U32 time = 0;
    if(cmd->part != 0)
    {
        sprintf((char *)cmd->rsp_msg, "ERROR:100");
        return;
    }
    memset(data, 0, sizeof(data));
    memset(temp, 0, sizeof(temp));

    sprintf(temp, "IMEI:%s;", track_drv_get_imei(0));
    strcpy(data, temp);
    memset(temp, 0, sizeof(temp));

    sprintf(temp, "TimeZone:%c,%d,%d;", G_parameter.zone.zone, G_parameter.zone.time, G_parameter.zone.time_min);
    strcat(data, temp);
    memset(temp, 0, sizeof(temp));
#if defined (__SAME_GT02__)
    if(G_importance_parameter_data.app_version.support_sensor)
#endif
    {
        strcat(data, "Sends:");
        sprintf(temp, "%d;", G_parameter.sensor_gps_work) ;
        strcat(data, temp);

        strcat(data, "Level:");
        sprintf(temp, "%d;", G_parameter.vibrates_alarm.sensitivity_level);
        strcat(data, temp);
        memset(temp, 0, 300);
    }


    //默认语言
    sprintf(temp, "Language:%d;", G_parameter.lang);
    strcat(data, temp);
    memset(temp, 0, 300);

    sprintf(temp, "HBT:%d;", G_parameter.hbt_acc_off);
    strcat(data, temp);
    memset(temp, 0, 300);
    if(G_parameter.gps_work.anglerep.sw)
    {
        sprintf(temp, "Angler:ON,%d;", G_parameter.gps_work.anglerep.angleOfDeflection, G_parameter.gps_work.anglerep.detection_time);
        strcat(data, temp);
        memset(temp, 0, 300);
    }
    else
    {
        sprintf(temp, "Angler:OFF");
        strcat(data, temp);
        memset(temp, 0, 300);
    }

    if(G_parameter.gps_work.Fti.sw == 1)
    {
        sprintf(temp, "Timer:%d", G_parameter.gps_work.Fti.interval_acc_off);
        strcat(data, temp);
        memset(temp, 0, 300);
    }
    else
    {
        sprintf(temp, "Distance:%d,", G_parameter.gps_work.Fd.distance);
        strcat(data, temp);
        memset(temp, 0, 300);
    }
    if(G_parameter.group_package.sw)
    {
        sprintf(temp, ";Batch:ON,%d", G_parameter.group_package.at_least_pack);
        strcat(data, temp);
        memset(temp, 0, 300);
    }
    else
    {
        sprintf(temp, ";batch:OFF");
        strcat(data, temp);
        memset(temp, 0, 300);
    }
    strcpy((char *)cmd->rsp_msg, (char *)data);
}
/******************************************************************************
 *  Function    -  sms_cmd_see_set
 *
 *  Purpose     -  查看终端设置参数
 *
 *  Description -SCXSZ[,使用密码]
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 11-05-2010,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
static void gt02_scxsz(CMD_DATA_STRUCT *cmd)
{
    char temp[300], temp1[300];
    char i;
    U16 RingId = 0;
    nvram_GPRS_APN_struct *use_apn = track_socket_get_use_apn();
    char GPRS[5] = {0};
    char server[99] = {0};
    if(cmd->part != 0)
    {
        sprintf(cmd->rsp_msg, "ERROR:100");
        return;
    }
    memset(cmd->rsp_msg, 0, sizeof(cmd->rsp_msg));
    memset(temp, 0, 300);
    memset(temp1, 0, 300);

    if(G_parameter.gprson)
        snprintf(GPRS, 20, "ON");
    else
        snprintf(GPRS, 20, "OFF");
    if(G_parameter.gps_work.Fti.sw == 1)
    {
        sprintf(temp1, "Timer:%d,%d,%d;", G_parameter.gps_work.Fti.lbs_interval,
                G_parameter.gps_work.Fti.interval_acc_off, G_parameter.gps_work.ephemeris_interval);
    }
    if(G_parameter.gps_work.Fd.sw == 1)
    {
        snprintf(temp1, 50, "Distance:%d; ", G_parameter.gps_work.Fd.distance);
    }
    strcat(temp, temp1);
    memset(temp1, 0, 300);
    if(G_importance_parameter_data.dserver.server_type && track_get_server_ip_status() == 0)
    {
        if(G_importance_parameter_data.dserver.conecttype == 0)
        {
            //ip
            snprintf(server, 20, "%d.%d.%d.%d", G_importance_parameter_data.dserver.server_ip[0], G_importance_parameter_data.dserver.server_ip[1], G_importance_parameter_data.dserver.server_ip[2], G_importance_parameter_data.dserver.server_ip[3]);
        }
        else
        {
            //Domain name
            snprintf(server, 98, "%s", track_domain_decode(G_importance_parameter_data.dserver.url));
        }

        snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, "GPRS:%s; Currently use APN:%s,%s,%s; DServer:%d,%s,%d,%d; URL:%s,%s",
                 GPRS,
                 use_apn->apn,
                 use_apn->username,
                 use_apn->password,
                 G_importance_parameter_data.dserver.conecttype,
                 server,
                 G_importance_parameter_data.dserver.server_port,
                 G_importance_parameter_data.dserver.soc_type,
                 G_parameter.url, temp);
    }
    else
    {
        if(G_importance_parameter_data.server.conecttype == 0)
        {
            //ip
            snprintf(server, 20, "%d.%d.%d.%d", G_importance_parameter_data.server.server_ip[0], G_importance_parameter_data.server.server_ip[1], G_importance_parameter_data.server.server_ip[2], G_importance_parameter_data.server.server_ip[3]);
        }
        else
        {
            //Domain name
            snprintf(server, 98, "%s", track_domain_decode(G_importance_parameter_data.server.url));
        }

        snprintf(cmd->rsp_msg, CM_PARAM_LONG_LEN_MAX, "GPRS:%s; Currently use APN:%s,%s,%s; Server:%d,%s,%d,%d; URL:%s,%s",
                 GPRS,
                 use_apn->apn,
                 use_apn->username,
                 use_apn->password,
                 G_importance_parameter_data.server.conecttype,
                 server,
                 G_importance_parameter_data.server.server_port,
                 G_importance_parameter_data.server.soc_type,
                 G_parameter.url, temp);
    }

}
/******************************************************************************
 *  Function    -  cmd_cancel
 *
 *  Purpose     -  撤销拆卸报警指令
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 2015-12-08,  xzq  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_cancel(CMD_DATA_STRUCT *cmd)
{
#if defined(__GT370__)|| defined (__GT380__)
    extern    void track_mode2_to_mode1(void);
#endif

    if(cmd->part > 0)
    {
        sprintf(cmd->rsp_msg, "ERROR: NO PARAMETERS!");
        return;
    }
#if defined(__GT370__)|| defined (__GT380__)
    if(track_is_timer_run(TRACK_CUST_EXTCHIP_MODE_AUTO_SW_TIMER_ID) || (G_realtime_data.tracking_mode == 1))
    {
        track_stop_timer(TRACK_CUST_EXTCHIP_MODE_AUTO_SW_TIMER_ID);
        tr_start_timer(TRACK_CUST_EXTCHIP_MODE_AUTO_SW_TIMER_ID, 20 * 1000, track_mode2_to_mode1);
    }
#elif defined(__GT740__)
    track_cust_module_track_mode_timeout();
#endif
    sprintf(cmd->rsp_msg, "OK!");

}

static void cmd_track_status(CMD_DATA_STRUCT *cmd)
{
    U32 timep;
    static applib_time_struct tmp = {0};
    OTA_applib_dt_get_rtc_time(&tmp);
    timep = OTA_applib_dt_mytime_2_utc_sec(&tmp, 0);

    if(G_realtime_data.tracking_time >= 1422748800 && timep >= 1422748800 && G_realtime_data.tracking_mode)
    {
        if(G_realtime_data.tracking_time + 60 * 60 >= timep)
        {
            timep = G_realtime_data.tracking_time + 60 * 60 - timep;
            LOGD(L_UART, L_V4, "模式一工作%d分钟%d秒之后，自动切换至模式二", timep / 60, timep % 60);
            sprintf(cmd->rsp_msg, "tracking_mode:%s,old mode:%d,time:%d", ON_OFF(G_realtime_data.tracking_mode), G_realtime_data.tracking_status_mode, timep / 60);
            return;
        }
    }
    sprintf(cmd->rsp_msg, "tracking_mode:%s,old mode:%d", ON_OFF(G_realtime_data.tracking_mode), G_realtime_data.tracking_status_mode);


}
#endif
/******************************************************************************
 *  Function    -  cmd_adt
 *
 *  Purpose     -  信息传输开关(几米国际上传外电压值)
 *
 *  Description -  ADC,A[,T]#
 *                          A=ON/OFF,  ON 开启AD数据上传，OFF为关闭AD数据上传，默认为ON状态;
 *                          T为上传间隔，5~3600秒；默认为60秒;
 *                          ADT#,查询当前设置信息
 *  modification history
 * ----------------------------------------
 * v1.0  , 07-23-2012,  Cjjl  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_adt(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 time = 0;
    if(cmd->part > 2)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d", cmd->pars[0], ON_OFF(G_parameter.info_up.sw), G_parameter.info_up.time);
        return;
    }
    if(!strcmp(cmd->pars[1], "ON") || !strcmp(cmd->pars[1], "1"))
    {
        if(cmd->part == 1)
        {
            G_parameter.info_up.sw = 1;
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
            sprintf(cmd->rsp_msg, "%s,%d", ON_OFF(G_parameter.info_up.sw), G_parameter.info_up.time);
        }
        else if(cmd->part == 2)
        {
            G_parameter.info_up.sw = 1;
            time = track_fun_atoi(cmd->pars[2]);
            if(time < 5 || time > 3600)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (5~3600)");
                return;
            }
            else
            {
                G_parameter.info_up.time = time;
                Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
                sprintf(cmd->rsp_msg, "%s,%d", ON_OFF(G_parameter.info_up.sw), G_parameter.info_up.time);
            }
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF") || !strcmp(cmd->pars[1], "0"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        G_parameter.info_up.sw = 0;
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        sprintf(cmd->rsp_msg, "%s,%d", ON_OFF(G_parameter.info_up.sw), G_parameter.info_up.time);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
    information_packets();
}


#if defined(__GT740__)||defined(__GT300S__) || defined (__GT370__)|| defined (__GT380__)
#if defined(__GT300S__) || defined (__GT370__)|| defined (__GT380__)
static void cmd_remset(CMD_DATA_STRUCT * cmd)
{
    int value;
    nvram_work_mode_struct chip = {0};

    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d,%d", cmd->pars[0],  G_parameter.work_mode.teardown_mode, G_parameter.work_mode.teardown_time);
        return;
    }
    if(cmd->part > 2)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    memcpy(&chip, &G_parameter.work_mode, sizeof(nvram_work_mode_struct));
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 1 || value > 2)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter (1-2)");
        return;
    }
    chip.teardown_mode = value;

    value = track_fun_atoi(cmd->pars[2]);
    if(value < 3 || value > 120)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter (3-120)");
        return;
    }

    chip.teardown_time = value;
    memcpy(&G_parameter.work_mode, &chip, sizeof(nvram_work_mode_struct));

    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }

}
static void cmd_tracktime(CMD_DATA_STRUCT *cmd)
{
    U8 value = 0;
    kal_int32 min = 5;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s,%d", cmd->pars[0], G_parameter.work_mode.teardown_time);
        return;
    }
    if(cmd->part == 1)
    {
        if(strlen(cmd->pars[1]) > 0)
        {
            value = track_fun_atoi(cmd->pars[1]);
            if((value < min || value > 60))
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 1 (%d-60)", min);
                return;
            }
            G_parameter.work_mode.teardown_time = value;
            if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
            {
                sprintf(cmd->rsp_msg, "OK!");
            }
            else
            {
                sprintf(cmd->rsp_msg, "Write Nvram Error!");
                return;
            }

        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (%d-60)", min);
            return;
        }

    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }


}

#endif
static void cmd_mode_view(CMD_DATA_STRUCT * cmd)
{
    if(cmd->part == 1 && !strcmp(cmd->pars[1], "MODE"))
    {
        if(G_parameter.extchip.mode == 1)
        {
            sprintf(cmd->rsp_msg, "MODE:%d,%d,%d", G_parameter.extchip.mode,
                    G_parameter.gps_work.Fti.interval_acc_off, G_parameter.extchip.mode1_par2);
        }
        else if(G_parameter.extchip.mode == 2)
        {
            if(G_parameter.extchip.mode2_par2 % 60 == 0)
            {
                sprintf(cmd->rsp_msg, "MODE:%d,%0.2d:%0.2d,%d", G_parameter.extchip.mode,
                        G_parameter.extchip.mode2_par1 / 60, G_parameter.extchip.mode2_par1 % 60, G_parameter.extchip.mode2_par2 / 60);
            }
            else
            {
                sprintf(cmd->rsp_msg, "MODE:%d,%0.2d:%0.2d,%d(MIN)", G_parameter.extchip.mode,
                        G_parameter.extchip.mode2_par1 / 60, G_parameter.extchip.mode2_par1 % 60, G_parameter.extchip.mode2_par2);
            }
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Parameter");
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter");
    }
}

static void cmd_teardown(CMD_DATA_STRUCT * cmd)
{
    nvram_teardown_struct alarm = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s mode:%d(0=only GPRS,1=GPRS+SMS)", cmd->pars[0],
                ON_OFF(G_parameter.teardown_str.sw), G_parameter.teardown_str.alarm_type);
        return;
    }
    memcpy(&alarm, &G_parameter.teardown_str, sizeof(nvram_teardown_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part != 1 && cmd->part != 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 1;
        if(cmd->part == 2)
        {
            if(!strcmp(cmd->pars[2], "0"))
            {
                alarm.alarm_type = 0;
            }
            else if(!strcmp(cmd->pars[2], "1"))
            {
                alarm.alarm_type = 1;
            }
#if defined(__GT740__)
            else
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1)");
                return;
            }
#else
            else if(!strcmp(cmd->pars[2], "2"))
            {
                alarm.alarm_type = 2;
            }
            else if(!strcmp(cmd->pars[2], "3"))
            {
                alarm.alarm_type = 3;
            }
            else
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1/2/3)");
                return;
            }
#endif

        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    if(memcmp(&G_parameter.teardown_str, &alarm, sizeof(nvram_teardown_struct)))
    {
#if defined(__GT740__)
        if(G_parameter.teardown_str.sw != alarm.sw)
        {
            track_cust_notify_st_remove_alarm_modify(alarm.sw);
        }
#endif
        memcpy(&G_parameter.teardown_str, &alarm, sizeof(nvram_teardown_struct));
        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "OK!");
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error!");
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
}

#if defined (__GT370__)|| defined (__GT380__)
static void cmd_remalmf(CMD_DATA_STRUCT * cmd)
{
    nvram_open_shell_alarm_struct alarm = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d", cmd->pars[0],
                ON_OFF(G_parameter.open_shell_alarm.sw), G_parameter.open_shell_alarm.alarm_type);
        return;
    }
    memcpy(&alarm, &G_parameter.open_shell_alarm, sizeof(nvram_open_shell_alarm_struct));

    if(strcmp(cmd->pars[1], "ON") == 0)
    {
        if(cmd->part != 1 && cmd->part != 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 1;
        if(cmd->part == 2)
        {
            if(!strcmp(cmd->pars[2], "0"))
            {
                alarm.alarm_type = 0;
            }
            else if(!strcmp(cmd->pars[2], "1"))
            {
                alarm.alarm_type = 1;
            }
            else
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1)");
                return;
            }
        }
    }
    else if(strcmp(cmd->pars[1], "OFF") == 0)
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }

    memcpy(&G_parameter.open_shell_alarm, &alarm, sizeof(nvram_open_shell_alarm_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#endif

#if defined(__GT740__) || defined (__GT370__)|| defined (__GT380__)
static void cmd_extchip(CMD_DATA_STRUCT * cmd)
{
    int len, j;
    U8 buf[100] = {"AT^GT_CM="};
    extern void track_cust_module_power_cmd(cmd_return_struct * return_sms, kal_uint8 * data, int len);

    j = cmd->pars[1] - cmd->rcv_msg;
    len = strlen(cmd->rcv_msg_source);
    LOGD(L_APP, L_V2, "%d,%d,%d", len, j, strlen(cmd->rcv_msg_source));
    LOGH(L_APP, L_V2, cmd->rcv_msg_source, strlen(cmd->rcv_msg_source));
    if(cmd->rcv_msg_source[len - 1] == 0x0D)
    {
        cmd->rcv_msg_source[len] = 0x0A;
        cmd->rcv_msg_source[len + 1] = 0x00;
        len++;
    }
    else if(strstr(cmd->rcv_msg_source, "\n") == NULL)
    {
        cmd->rcv_msg_source[len] = 0x0D;
        cmd->rcv_msg_source[len + 1] = 0x0A;
        cmd->rcv_msg_source[len + 2] = 0x00;
        len += 2;
    }
    if(len > 0 && len < 200 && j > 0 && len - j < 90)
    {
        memcpy(&buf[9], cmd->rcv_msg_source + j, len - j);
        track_cust_module_power_cmd(&cmd->return_sms, buf, 9 + len - j);
        //track_drv_uart2_write_data(buf, 9 + len - j);
    }
}

#endif

#if defined ( __GT300S__)
static void cmd_extchip(CMD_DATA_STRUCT * cmd)
{
    int len, j;
    U8 buf[100] = {"AT^GT_CM="};
    extern void track_cust_module_power_cmd(cmd_return_struct * return_sms, kal_uint8 * data, int len);
    j = cmd->pars[1] - cmd->rcv_msg;
    len = strlen(cmd->rcv_msg_source);
    LOGD(L_APP, L_V2, "%d,%d,%d", len, j, strlen(cmd->rcv_msg_source));
    LOGH(L_APP, L_V2, cmd->rcv_msg_source, strlen(cmd->rcv_msg_source));
    if(cmd->rcv_msg_source[len - 1] == 0x0D)
    {
        cmd->rcv_msg_source[len - 1] = 0x00;
        len--;
    }
    if(len > 0 && len < 200 && j > 0 && len - j < 90)
    {
        memcpy(&buf[9], cmd->rcv_msg_source + j, len - j);
        track_cust_module_power_cmd(&cmd->return_sms, buf, 9 + len - j);
        //track_drv_uart2_write_data(buf, 9 + len - j);
    }
}

static void cmd_mode(CMD_DATA_STRUCT * cmd)
{
    nvram_work_mode_struct chip = {0};
    int value = 0;
    int value1 = 0;
    int value2 = 0;
    int mode = 0;
    extern void track_cust_module_extchip_shutdown(void);



    if(cmd->part == 0)
    {
        if(G_parameter.work_mode.mode == 2)
        {
            sprintf(cmd->rsp_msg, "%s:%d,%d", cmd->pars[0], G_parameter.work_mode.mode, G_parameter.gps_work.Fti.interval_acc_on);
        }
        else  if(G_parameter.work_mode.mode == 1)
        {
            sprintf(cmd->rsp_msg, "%s:%d,%d", cmd->pars[0], G_parameter.work_mode.mode, G_parameter.work_mode.mode1_timer);

        }
        else if(G_parameter.work_mode.mode == 3)
        {

            sprintf(cmd->rsp_msg, "%s:%d,%0.2d:%0.2d,%d", cmd->pars[0], G_parameter.work_mode.mode,
                    G_parameter.work_mode.datetime / 60,  G_parameter.work_mode.datetime % 60,  G_parameter.work_mode.mode3_timer / 60);

        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Parameter");
        }
        return;
    }
    memcpy(&chip, &G_parameter.work_mode, sizeof(nvram_work_mode_struct));
    if(!strcmp(cmd->pars[1], "2"))
    {
        /*
            T1 为定时上传间隔: 10～1800 秒
            T2 为持续工作时间:  5～43200 分钟
        */
        U16 par;

        if(cmd->part != 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error! %d", cmd->part);
            return;
        }
        //if (cmd->part >= 2)
        {
            value  = track_fun_atoi(cmd->pars[2]);
            if(value < 10 || value > 1800)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (10 to 1800)");
                return;
            }
            chip.mode = 2;
            G_parameter.gps_work.Fti.interval_acc_off = value ;
            G_parameter.gps_work.Fti.interval_acc_on = value ;
        }
    }
    else if(!strcmp(cmd->pars[1], "1"))
    {
        chip.mode = 1;
        value = track_fun_atoi(cmd->pars[2]);
        if((value < 5 || value > 7200) && value != 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 :0,5 to 7200");
            return;
        }

        chip.mode1_timer =  value;

    }
    else if(!strcmp(cmd->pars[1], "3"))
    {
        /*
            T1 起始时间
            T2 间隔时间
        */
        if(cmd->part != 3)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error! %d", cmd->part);
            return;
        }
        if(cmd->part >= 2)
        {
            char *par = strchr(cmd->pars[2], ':');
            mode = track_fun_atoi(cmd->pars[1]);
            if(NULL == par || strlen(cmd->pars[2]) > 5 || strlen(cmd->pars[2]) < 3)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (HH:MM)");
                return;
            }
            *par = 0;
            value  = track_fun_atoi(cmd->pars[2]);
            if(value < 0 || value > 23)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (HH:MM) HH:0～23");
                return;
            }
            value1  = track_fun_atoi(par + 1);
            if(value1 < 0 || value1 > 59)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (HH:MM) MM:0～59");
                return;
            }
            value2 = track_fun_atoi(cmd->pars[3]);
            if(value2 < 1 || value2 > 24)
            {
                if(mode == 2 && value2 != 0)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 3 0~24");
                    return;
                }
                if(mode == 3)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 3 1~24");
                    return;
                }
            }
            if(mode <= 0 || mode > 3)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter1 1~3");
                return;
            }
            chip.mode = mode;
            chip.datetime = value * 60 + value1;
            chip.mode3_timer =  value2 * 60;
            if(chip.mode3_timer == 0)
            {

            }
            else if((24 % (chip.mode3_timer / 60) != 0) && chip.mode3_timer != 0)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter3  0,1,2,3,4,6,8,12,24");
                return;
            }
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter1 1~3");
        return;
    }
    memcpy(&G_parameter.work_mode, &chip, sizeof(nvram_work_mode_struct));
    if(G_realtime_data.tracking_mode)
    {
        G_realtime_data.tracking_mode = 0;
        G_realtime_data.tracking_time = 0;
        G_realtime_data.tracking_status_mode = 0;
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
        track_cust_module_sw_init();
        track_cust_wake_mode();
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

#elif defined(__GT740__)

//__GT370__/GT740 UART
static void cmd_RESETPRO(CMD_DATA_STRUCT * cmd)
{
    track_cust_module_resetpro();
    sprintf(cmd->rsp_msg, "OK!");
}


static void cmd_gpswakeup(CMD_DATA_STRUCT * cmd)
{
    U8 static_filter_sw;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], ON_OFF(G_parameter.gpswake));
        return;
    }
    static_filter_sw = G_parameter.gpswake;
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part > 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        static_filter_sw = 1;
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        static_filter_sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    G_parameter.gpswake = static_filter_sw;
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}


static void cmd_amslog(CMD_DATA_STRUCT * cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s" , cmd->pars[0],
                ON_OFF(G_realtime_data.ams_log));
        return;
    }
    if(!strcmp(cmd->pars[1], "ON"))
    {
        G_realtime_data.ams_log = 1;
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        G_realtime_data.ams_log = 0;

    }
    else if(!strcmp(cmd->pars[1], "DEL"))
    {
        int rst = 0;
        rst = track_cust_netlog_del();
        sprintf(cmd->rsp_msg, "del %d", rst);
        return;

    }
    else if(!strcmp(cmd->pars[1], "PUSH"))
    {
        U8 resetlt = 0;
        LOGD(L_UART, L_V5, "PUSH");
        if(!strcmp(cmd->pars[2], "STOP"))
        {
            G_realtime_data.ams_push = 0;
            sprintf(cmd->rsp_msg, "%s", ON_OFF(G_realtime_data.ams_push));
        }
        else
        {
            G_realtime_data.ams_push = 1;
            sprintf(cmd->rsp_msg, "%s", ON_OFF(G_realtime_data.ams_push));
        }
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        return;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1");
        return;
    }
    if(Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
}

static void cmd_gpsup(CMD_DATA_STRUCT * cmd)
{
    nvram_gpsup_struct gpsup = {0};
    kal_uint16 Inveltime;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s interval:%d", cmd->pars[0],
                ON_OFF(G_parameter.gpsup_struct.sw), G_parameter.gpsup_struct.up_interval_time);
        return;
    }
    memcpy(&gpsup, &G_parameter.gpsup_struct, sizeof(nvram_gpsup_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part != 1 && cmd->part != 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        gpsup.sw = 1;
        if(cmd->part == 2)
        {
            Inveltime = atoi(cmd->pars[2]);
            if(Inveltime >= 10 && Inveltime <= 1800)
            {
                gpsup.up_interval_time = Inveltime;
            }
            else
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (10-1800)");
                return;
            }
        }
        if(G_parameter.extchip.mode == 1 && track_cust_gps_status() == 0)
        {
            track_cust_gpsoff_gpsup((void*)track_cust_gps_before_off_status());
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        gpsup.sw = 0;
        track_stop_timer(TRACK_CUST_GPSUP_SEND_TIMER_ID);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    if(memcmp(&G_parameter.gpsup_struct, &gpsup, sizeof(nvram_gpsup_struct)))
    {
        memcpy(&G_parameter.gpsup_struct, &gpsup, sizeof(nvram_gpsup_struct));
        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "OK!");
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error!");
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
}

static void cmd_tracktime(CMD_DATA_STRUCT *cmd)
{
    U32 value = 0;
#if defined(__GT370__)
    kal_int32 min = 5;
#else
kal_int32 min = 1;
#endif
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s,%d", cmd->pars[0], G_realtime_data.tracking_time);
        return;
    }
    if(cmd->part == 1)
    {
        if(strlen(cmd->pars[1]) > 0)
        {
            value = track_fun_atoi(cmd->pars[1]);
            if((value < 1 || value > 60))
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 1 (%d-60)", value);
                return;
            }
            G_realtime_data.tracking_time = value;
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
            sprintf(cmd->rsp_msg, "OK!");

        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (%d-60)", min);
            return;
        }

    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }


}
static void cmd_RESETBAT(CMD_DATA_STRUCT * cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "RESETBAT:OK");
        track_cust_resetbat();
        return;
    }
}
static void cmd_RESETBATDIS(CMD_DATA_STRUCT * cmd)
{
    if(!strcmp(cmd->pars[1], "ON"))
    {
        G_parameter.cal_time_sw = 1;
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        G_parameter.cal_time_sw = 0;
    }
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
}

static void cmd_mode(CMD_DATA_STRUCT * cmd)
{
    nvram_ext_chip_struct chip = {0};
    int value;
    if(cmd->part == 0)
    {
        if(G_parameter.extchip.mode == 1)
        {
            sprintf(cmd->rsp_msg, "%s:%d,%d,%d", cmd->pars[0], G_parameter.extchip.mode,
                    G_parameter.gps_work.Fti.interval_acc_off, G_parameter.extchip.mode1_par2);
        }
        else if(G_parameter.extchip.mode == 2)
        {
            if(G_parameter.extchip.mode2_par2 % 60 == 0)
            {
                sprintf(cmd->rsp_msg, "%s:%d,%0.2d:%0.2d,%d", cmd->pars[0], G_parameter.extchip.mode,
                        G_parameter.extchip.mode2_par1 / 60, G_parameter.extchip.mode2_par1 % 60, G_parameter.extchip.mode2_par2 / 60);
            }
            else
            {
                sprintf(cmd->rsp_msg, "%s:%d,%0.2d:%0.2d,%d(MIN)", cmd->pars[0], G_parameter.extchip.mode,
                        G_parameter.extchip.mode2_par1 / 60, G_parameter.extchip.mode2_par1 % 60, G_parameter.extchip.mode2_par2);
            }
        }
        else if(G_parameter.extchip.mode == 3)
        {
            sprintf(cmd->rsp_msg, "%s:%d,%d,%0.2d:%0.2d", cmd->pars[0], G_parameter.extchip.mode, G_parameter.extchip.mode3_par1,
                    G_parameter.extchip.mode3_par2 / 60, G_parameter.extchip.mode3_par2 % 60);
        }
        else if(G_parameter.extchip.mode == 4)
        {
            char m_buf[100] = {0};
            U8 vle = G_parameter.extchip.mode4_par1, i = 0;
            for(; i < vle; i++)
            {
                if(0 == i)
                {
                    snprintf(m_buf + strlen(m_buf), 99, "%0.2d:%0.2d", G_parameter.extchip.mode4_par2[i] / 60, G_parameter.extchip.mode4_par2[i] % 60);
                }
                else
                {
                    snprintf(m_buf + strlen(m_buf), 99, ",%0.2d:%0.2d", G_parameter.extchip.mode4_par2[i] / 60, G_parameter.extchip.mode4_par2[i] % 60);
                }
            }
            sprintf(cmd->rsp_msg, "%s:%d,%d,%s", cmd->pars[0], G_parameter.extchip.mode, G_parameter.extchip.mode4_par1, m_buf);
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Parameter");
        }
        return;
    }
    memcpy(&chip, &G_parameter.extchip, sizeof(nvram_ext_chip_struct));
    if(!strcmp(cmd->pars[1], "1"))
    {
        /*
            T1 为定时上传间隔: 10～1800 秒
            T2 为持续工作时间:  5～43200 分钟
        */
        U16 par;
        if(!strcmp(cmd->pars[2], "VIEW"))
        {
            track_cust_module_auto_sw_mode();
            return;
        }
        if(cmd->part != 3)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error! %d", cmd->part);
            return;
        }
        if(G_parameter.extchip.mode != 1)
        {
            chip.premode = G_parameter.extchip.mode;
        }
        chip.mode = 1;
        par = G_parameter.gps_work.Fti.interval_acc_on;
        if(cmd->part >= 2)
        {
            value  = track_fun_atoi(cmd->pars[2]);
            if(value < 10 || value > 1800)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (10 to 1800)");
                return;
            }
            chip.mode1_par1 = value;
        }
        if(cmd->part >= 3)
        {
            value  = track_fun_atoi(cmd->pars[3]);
            if(value < 5 || value > 43200)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (5 to 43200)");
                return;
            }
            chip.mode1_par2 = value;
            {
                static applib_time_struct tmp = {0};
                OTA_applib_dt_get_rtc_time(&tmp);
                chip.mode1_time = OTA_applib_dt_mytime_2_utc_sec(&tmp, 0) + chip.mode1_par2 * 60;
                LOGD(L_UART, L_V5, "time: %0.2d-%0.2d-%0.2d %0.2d:%0.2d:%0.2d    sec:%d",
                     tmp.nYear, tmp.nMonth, tmp.nDay,
                     tmp.nHour, tmp.nMin, tmp.nSec);
            }
        }
        if(G_parameter.gps_work.Fti.interval_acc_on != chip.mode1_par1 || G_parameter.gps_work.Fti.interval_acc_off != chip.mode1_par1)
        {
            G_parameter.gps_work.Fti.interval_acc_on = chip.mode1_par1;
            G_parameter.gps_work.Fti.interval_acc_off = chip.mode1_par1;
            G_parameter.gps_work.Fti.lbs_interval = chip.mode1_par1;
        }
    }
    else if(!strcmp(cmd->pars[1], "2"))
    {
        if(cmd->part < 2 || cmd->part > 3)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error! %d", cmd->part);
            return;
        }
        if(cmd->part >= 2)
        {
            int value1;
            char *par = strchr(cmd->pars[2], ':');
            if(NULL == par || strlen(cmd->pars[2]) > 5 || strlen(cmd->pars[2]) < 3)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (HH:MM)");
                return;
            }
            *par = 0;
            value  = track_fun_atoi(cmd->pars[2]);
            if(value < 0 || value > 23)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (HH:MM) HH:0～23");
                return;
            }
            value1  = track_fun_atoi(par + 1);
            if(value1 < 0 || value1 > 59)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (HH:MM) MM:0～59");
                return;
            }
            chip.mode = 2;
            chip.mode2_par1 = value * 60 + value1;
        }
        if(cmd->part >= 3)
        {
            if(strstr(cmd->pars[3], "MIN") == cmd->pars[3])
            {
                value  = track_fun_atoi(cmd->pars[3] + 3);
                if(value < 5)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 3(%d < 5MIN)", value);
                    return;
                }
                chip.mode2_par2 = value;
            }
            else
            {
                value  = track_fun_atoi(cmd->pars[3]);
                if(value != 1 && value != 2 && value != 3 && value != 4 && value != 6 && value != 8 && value != 12 && value != 24)
                {
                    if(value != 48 && value != 72 && value != 96 && value != 120 && value != 144 && value != 168 && value != 192 && value != 216)
                    {
                        if(value != 240 && value != 264 && value != 288 && value != 312 && value != 336 && value != 360)
                        {
                            //sprintf(cmd->rsp_msg, "Error: Parameter 3 (1-120)");
                            sprintf(cmd->rsp_msg, "Error: Parameter 3 (1,2,3,4,6,8,12,24,48,72,96,120,144,168,192,216,240,264,288,312,336,360)");
                            return;
                        }
                    }

                }
                chip.mode2_par2 = value * 60;
            }
        }
    }
    else if(!strcmp(cmd->pars[1], "3"))
    {
        kal_int32 vle = 0;
        if(cmd->part < 2 || cmd->part > 3)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error! %d", cmd->part);
            return;
        }
        if(cmd->part >= 2)
        {
            vle = track_fun_atoi2(4, cmd->pars[2]);
            if(-99 == vle)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 Number contains non-numeric characters or range out(1-7)!");
                return;
            }
            else if(strlen(cmd->pars[2]) > 7)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 Number length MAX 7!");
                return;
            }
            chip.mode3_par1 = vle;
        }
        if(cmd->part >= 3)
        {
            int value1;
            char *par = strchr(cmd->pars[3], ':');
            if(NULL == par || strlen(cmd->pars[3]) > 5 || strlen(cmd->pars[3]) < 3)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (HH:MM)");
                return;
            }
            *par = 0;
            value  = track_fun_atoi(cmd->pars[3]);
            if(value < 0 || value > 23)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (HH:MM) HH:0～23");
                return;
            }
            value1  = track_fun_atoi(par + 1);
            if(value1 < 0 || value1 > 59)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (HH:MM) MM:0～59");
                return;
            }
            chip.mode = 3;
            chip.mode3_par2 = value * 60 + value1;
        }
    }
    else if(!strcmp(cmd->pars[1], "4"))
    {
        int vle = 0;
        if(cmd->part < 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error! %d", cmd->part);
            return;
        }
        if(cmd->part >= 2)
        {
            vle = atoi(cmd->pars[2]);
            if(vle < 1 || vle > 12)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (1-12)");
                return;
            }
            chip.mode4_par1 = vle;
        }
        if(cmd->part - 2 == vle) //mode,4,12,11:00,,,,,,,
        {
            int value1, i = 0;
            for(; i < vle; i++)
            {
                char *par = strchr(cmd->pars[3 + i], ':');
                if(NULL == par || strlen(cmd->pars[3 + i]) > 5 || strlen(cmd->pars[3 + i]) < 3)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter %d (HH:MM)", 3 + i);
                    return;
                }
                *par = 0;
                value  = track_fun_atoi(cmd->pars[3 + i]);
                if(value < 0 || value > 23)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter %d (HH:MM) HH:0～23", 3 + i);
                    return;
                }
                value1  = track_fun_atoi(par + 1);
                if(value1 < 0 || value1 > 59)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter %d (HH:MM) MM:0～59", 3 + i);
                    return;
                }
                chip.mode4_par2[i] = value * 60 + value1;
            }
            chip.mode = 4;
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!(HH:MM) %d", vle);
            return;
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (1/2/3/4)");
        return;
    }
    if(!memcmp(&G_parameter.extchip, &chip, sizeof(nvram_ext_chip_struct)))
    {
        sprintf(cmd->rsp_msg, "OK!");
        LOGD(L_CMD, L_V5, "no change! %d,%d", G_parameter.extchip.mode, chip.mode);
        return;
    }
    if(chip.mode == 1)
    {
        track_cust_gps_work_req((void *)18);
    }
    memcpy(&G_parameter.extchip, &chip, sizeof(nvram_ext_chip_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
#if defined(__GT740__)
        track_cust_module_update_mode();
        track_cust_upload_param();
        track_stop_timer(TRACK_CUST_EXTCHIP_TRACK_MODE_TIMEROUT_TIMER_ID);
        if(G_parameter.extchip.mode == 1)
        {
            if(track_is_timer_run(TRACK_CUST_EXTCHIP_DELAY_CLOSE_TIMER_ID))
            {
                tr_stop_timer(TRACK_CUST_EXTCHIP_DELAY_CLOSE_TIMER_ID);
            }

        }
        if(track_cust_module_tracking_mode(99))
        {
            track_cust_module_tracking_mode(0);
        }
#endif
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#elif defined(__GT370__)|| defined (__GT380__)
static void cmd_mode(CMD_DATA_STRUCT * cmd)
{
    nvram_work_mode_struct chip = {0};
    int value = 0;
    int value1 = 0;
    int value2 = 0;
    int mode = 0;

    if(cmd->part == 0)
    {
        mode = (G_parameter.work_mode.mode > 1 ? G_parameter.work_mode.mode - 1 : G_parameter.work_mode.mode);
        if(mode == 1)
        {
            sprintf(cmd->rsp_msg, "%s:%d,%d,%d", cmd->pars[0], mode, \
                    G_parameter.gps_work.Fti.interval_acc_on, G_parameter.gps_work.Fti.interval_acc_off);
        }
        else if(mode == 2)
        {
            //sprintf(cmd->rsp_msg, "%s:%d,%0.2d:%0.2d,%d", cmd->pars[0], mode,
            //        G_parameter.work_mode.datetime / 60,  G_parameter.work_mode.datetime % 60,  G_parameter.work_mode.mode3_timer / 60);

            if(G_parameter.work_mode.mode3_timer < 60)
            {
                sprintf(cmd->rsp_msg, "%s:%d,%0.2d:%0.2d,%dmin (test)", cmd->pars[0], G_parameter.extchip.mode,
                        G_parameter.work_mode.datetime / 60,  G_parameter.work_mode.datetime % 60,  G_parameter.work_mode.mode3_timer);
            }
            else
            {
                sprintf(cmd->rsp_msg, "%s:%d,%0.2d:%0.2d,%d", cmd->pars[0], mode,
                        G_parameter.work_mode.datetime / 60,  G_parameter.work_mode.datetime % 60,  G_parameter.work_mode.mode3_timer / 60);
            }

        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Parameter");
        }
        return;
    }
    memcpy(&chip, &G_parameter.work_mode, sizeof(nvram_work_mode_struct));
    if(!strcmp(cmd->pars[1], "1"))
    {
        /*     T1 为定时上传间隔: 10～3600 秒
               T2 为持续工作时间: 10～86400 秒        */
        U16 par;

        if(cmd->part != 3)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error! %d", cmd->part);
            return;
        }

        value  = track_fun_atoi(cmd->pars[2]);
        if(value < 10 || value > 3600)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (10 to 3600)");
            return;
        }

        G_parameter.gps_work.Fti.interval_acc_on = value ;

        value = track_fun_atoi(cmd->pars[3]);
        if((value < 10 || value > 86400) && value != 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 :10 to 86400");
            return;
        }
        G_parameter.gps_work.Fti.interval_acc_off = value ;
        chip.mode1_timer =	G_parameter.gps_work.Fti.interval_acc_on;

        //chip.mode1_timer =	value;
        if(G_parameter.gps_work.Fti.interval_acc_on > 120)
        {
            chip.mode = 1;
        }
        else
        {
            chip.mode = 2;
        }

    }
    else if(!strcmp(cmd->pars[1], "2"))
    {
        /* T1 起始时间
           T2 间隔时间 */
        if(cmd->part != 3)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error! %d", cmd->part);
            return;
        }
        if(cmd->part >= 2)
        {
            char *par = strchr(cmd->pars[2], ':');
            mode = track_fun_atoi(cmd->pars[1]);//无聊不?
            if(NULL == par || strlen(cmd->pars[2]) > 5 || strlen(cmd->pars[2]) < 3)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (HH:MM)");
                return;
            }
            *par = 0;
            value  = track_fun_atoi(cmd->pars[2]);
            if(value < 0 || value > 23)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (HH:MM) HH:0～23");
                return;
            }
            value1  = track_fun_atoi(par + 1);
            if(value1 < 0 || value1 > 59)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (HH:MM) MM:0～59");
                return;
            }

            /*小范围便于测试       --    chengjun  2017-04-01*/
            if(strstr(cmd->pars[3], "MIN") == cmd->pars[3])
            {
                value2  = track_fun_atoi(cmd->pars[3] + 3);
                if(value2 < 5)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 3(%d < 5MIN)", value2);
                    return;
                }
                chip.mode = 3;
                chip.datetime = value * 60 + value1;
                chip.mode3_timer =  value2;
            }
            else
            {
                value2 = track_fun_atoi(cmd->pars[3]);
                if(value2 < 1 || value2 > 72)
                {
                    if(mode == 2)
                    {
                        sprintf(cmd->rsp_msg, "Error: Parameter 3 1~72");
                        return;
                    }
                }

                if(mode <= 0 || mode > 2)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter1 1~2");
                    return;
                }
                chip.mode = 3;
                chip.datetime = value * 60 + value1;
                chip.mode3_timer =  value2 * 60;
            }
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter1 1~2");
        return;
    }
    memcpy(&G_parameter.work_mode, &chip, sizeof(nvram_work_mode_struct));
    if(G_realtime_data.tracking_mode)
    {
        G_realtime_data.tracking_mode = 0;
        G_realtime_data.tracking_time = 0;
        G_realtime_data.tracking_status_mode = 0;
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
        track_cust_module_sw_init();
        if(G_parameter.work_mode.mode != 3)
        {
            track_stop_timer(TRACK_POWER_RESET_TIMER_ID);
        }
        track_cust_wake_mode();
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

#endif
#endif

static void cmd_dial(CMD_DATA_STRUCT * Cmds)
{
    kal_uint32 len = 0;
    kal_uint32 value = 0;
    LOGD(L_CMD, L_V5, "part= %d", Cmds->part);
    if(Cmds->part > 2)
    {
        sprintf(Cmds->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    len = strlen(Cmds->pars[1]);
    if(len > 0)
    {
        if(len > 0)
        {
            if(track_fun_check_str_is_number(1, Cmds->pars[1]) == 0)
            {
                sprintf(Cmds->rsp_msg, "Error: Number contains non-numeric characters!");
                return;
            }
            if(len >= TRACK_DEFINE_PHONE_NUMBER_LEN_MAX)
            {
                sprintf(Cmds->rsp_msg, "Error: Number length exceeds 20 characters!");
                return;
            }
            else if(len < 3)
            {
#if defined (__GERMANY__)
                sprintf(Cmds->rsp_msg, "Fehler: Mindestens 3 Zeichen eingeben!");
#else
                sprintf(Cmds->rsp_msg, "Error: Number length must exceeds 3 characters!");
#endif
                return;
            }
            memset(dail_num, 0, sizeof(dail_num));
            dail_count = 0;
            strcpy(dail_num, Cmds->pars[1]);
        }
        if(strlen(Cmds->pars[2]) != 0)
        {
            value = track_fun_atoi(Cmds->pars[2]);
            if((value < 1 || value > 3))
            {
                sprintf(Cmds->rsp_msg, "Error: Parameter 2 (1-3)");
                return;
            }
            dail_count = value;
        }
        if(strlen(Cmds->pars[2]) != 0)
        {
            LOGD(L_CMD, L_V5, "pars[1] = %s;dail_num=%s", Cmds->pars[1], dail_num);
            LOGD(L_CMD, L_V5, "pars[2] = %s;dail_count=%s", Cmds->pars[2], dail_count);
        }
        else
        {
            LOGD(L_CMD, L_V5, "pars[1] = %s;dail_num=%s", Cmds->pars[1], dail_num);
        }
        sprintf(Cmds->rsp_msg, "OK");
        track_start_timer(TRACK_CUST_DIAL_NUM_TIMER_ID, 5 * 1000, track_cust_dial_makecall, (void*)1);
    }
    else
    {
        sprintf(Cmds->rsp_msg, "ERROR:100");
    }
}

#if defined(__SPANISH__)
/******************************************************************************
 *  Function    -  cmd_sosbt
 *
 *  Purpose     -  sos报警触发模式
 *
 *  Description -
                SOSBT,0# 短按(按一次 触发)
                SOSBT,1# 长按(长按 3秒)
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 13-9-2014,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_sosbt(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 value;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.sos_alarm.key_type);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    else
    {
        value = track_fun_atoi(cmd->pars[1]);
        if(value != 1 && value != 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (0-1)");
            return;
        }
        else if(G_parameter.sos_alarm.key_type != value)
        {
            G_parameter.sos_alarm.key_type = value;
        }
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
/******************************************************************************
 *  Function    -  cmd_esos
 *
 *  Purpose     -  SOS报警短信自定义
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 13-9-2014,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_esos(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s", G_parameter.sos_alarm.alarm_sms_head);
        return;
    }
    if(strlen(cmd->pars[1]) == 0 || cmd->part != 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(strlen(cmd->pars[1]) >= 100)
    {
        sprintf(cmd->rsp_msg, "Error: string is too long!");
        return;
    }
    else
    {
        char tmp[100] = {0};
        int len;
        memset(G_parameter.sos_alarm.alarm_sms_head, 0, 100);
        len = strlen(cmd->pars[1]);
        memcpy(tmp, cmd->rcv_msg_source + (cmd->pars[1] - cmd->rcv_msg), (len >= 100 ? 99 : len));
        sprintf(G_parameter.sos_alarm.alarm_sms_head, tmp);
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        sprintf(cmd->rsp_msg, "OK!");
    }
}
/******************************************************************************
 *  Function    -  cmd_itp
 *
 *  Purpose     -  itp,1# 关闭94包上传功能
                   itp,0# 打开      默认:1
                   itp# 查询当前状态
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 30-3-2017,  Cjj  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_itp(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 value;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.itp_sw);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    else
    {
        value = track_fun_atoi(cmd->pars[1]);
        if(value != 1 && value != 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (0-1)");
            return;
        }
        else if(G_parameter.itp_sw != value)
        {
            G_parameter.itp_sw = value;
        }
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#endif

#if defined(__EXT_VBAT_ADC__)
void cmd_adc_bc(CMD_DATA_STRUCT * Cmds)
{
    kal_int32 parm = 0;
    kal_int32 parm1 = 0;
    float volt_plus = 0;
    kal_int32 vol = 0;
    kal_uint8 buffer[10] = NULL;

    //extern kal_int32 track_drv_get_external_voltage_status(void);
    if(Cmds->part > 2)
    {
        sprintf(Cmds->rsp_msg, "ERROR:part %d", Cmds->part);
        return;
    }
    if(Cmds->part == 0)
    {
        volt_plus = G_parameter.adc4_offset;
        sprintf(Cmds->rsp_msg, "ADC4 Offset:%0.2fV", volt_plus / 1000000);
        return;
    }
    if(Cmds->part >= 1 && !strcmp(Cmds->pars[1], "OFF"))
    {
        volt_plus = 0;
    }
    else if(Cmds->part >= 1 && !strcmp(Cmds->pars[1], "A"))
    {
        if(strlen(Cmds->pars[2]))
        {
            volt_plus = (atof(Cmds->pars[2]) * 1000000);
        }
        else
        {
            sprintf(Cmds->rsp_msg, "BC_D Fail: %0.2fV", volt_plus / 1000000);
            return;
        }
    }
    else if(Cmds->part >= 1 && !strcmp(Cmds->pars[1], "B"))
    {
        LOGD(L_CMD, L_V4, "offset=%d;", atoi(Cmds->pars[2]));
        if(strlen(Cmds->pars[2]))
        {
            volt_plus = atoi(Cmds->pars[2]);
        }
        else
        {
            sprintf(Cmds->rsp_msg, "BC_D Fail: %0.2fV", volt_plus / 1000000);
            return;
        }
    }
    else
    {
        if(Cmds->part >= 1 && strlen(Cmds->pars[1]))
        {
            parm = (atof(Cmds->pars[1]) * 1000000);
        }
        if(strlen(Cmds->pars[2]))
        {
            parm1 = (atof(Cmds->pars[2]) * 1000000);
        }
        LOGC(L_CMD, L_V5, "BC parm: %d,parm1:%d", parm, parm1);

#if defined (__MCU_BJ8M601A_NT13V__)        
        vol = track_drv_get_external_voltage_form_gsm() - G_parameter.adc4_offset; //得出终端实际测量值
#else
        vol = track_drv_get_external_voltage_status() - G_parameter.adc4_offset; //得出终端实际测量值
#endif /* __MCU_BJ8M601A_NT13V__ */
        
        LOGC(L_CMD, L_V5, "BC_A VOL: %d", vol);
        if(vol <= 0)
        {
            sprintf(Cmds->rsp_msg, "BC_D Fail: no charge");
            return;
        }
        volt_plus = parm - vol;
        if(strlen(Cmds->pars[2]))
        {
            LOGC(L_CMD, L_V5, "BC volt_plus: %d,parm1:%d", volt_plus, parm1);
            if(volt_plus > parm1 || volt_plus < (-parm1))
            {
                sprintf(Cmds->rsp_msg, "BC_D Fail: %0.2fV", volt_plus / 1000000);
                return;
            }

        }
        else
        {
            if((volt_plus > 350000) || (volt_plus < (-350000)))
            {
                sprintf(Cmds->rsp_msg, "BC_D Fail: %0.2fV", volt_plus / 1000000);
                return;
            }

        }
    }
    G_parameter.adc4_offset = volt_plus;

#if defined (__MCU_BJ8M601A_NT13V__)        
    vol = track_drv_get_external_voltage_form_gsm();
#else
    vol = track_drv_get_external_voltage_status();
#endif /* __MCU_BJ8M601A_NT13V__ */

    sprintf(Cmds->rsp_msg, "BC_B VOL: %d", vol);
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    //track_os_intoTaskMsgQueue(track_cust_write_sim_backup_for_parameter);
}

#endif /* __EXT_VBAT_ADC__ */

static void cmd_hst(CMD_DATA_STRUCT *cmd)
{
    int value = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0],
                G_parameter.speed_limit);
        return;
    }

    if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 0 || value > 255)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (0-255)");
        return;
    }
    G_parameter.speed_limit = value;
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#if 0
static void cmd_PWRONALM(CMD_DATA_STRUCT *cmd)
{
    nvram_boot_struct alarm = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d", cmd->pars[0],
                ON_OFF(G_parameter.boot.sw), G_parameter.boot.alarm_type);
        return;
    }
    memcpy(&alarm, &G_parameter.boot, sizeof(nvram_boot_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 1;
        if(cmd->part >= 2)
        {
            alarm.alarm_type = track_fun_atoi(cmd->pars[2]);
            if(alarm.alarm_type != 0 && alarm.alarm_type != 1)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1)");
                return;
            }
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.boot, &alarm, sizeof(nvram_boot_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

static void cmd_PWROFFALM(CMD_DATA_STRUCT *cmd)
{
    nvram_boot_struct alarm = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d", cmd->pars[0],
                ON_OFF(G_parameter.pwroff.sw), G_parameter.pwroff.alarm_type);
        return;
    }
    memcpy(&alarm, &G_parameter.pwroff, sizeof(nvram_boot_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 1;
        if(cmd->part >= 2)
        {
            alarm.alarm_type = track_fun_atoi(cmd->pars[2]);
            if(alarm.alarm_type != 0 && alarm.alarm_type != 1)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1)");
                return;
            }
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.pwroff, &alarm, sizeof(nvram_boot_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

static void cmd_simalm(CMD_DATA_STRUCT *cmd)
{
    int value = 0;
    nvram_sim_alm_struct alarm = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s mode:%d(0=only GPRS,1=GPRS+SMS)", cmd->pars[0],
                ON_OFF(G_parameter.sim_alarm.sw), G_parameter.sim_alarm.simalm_type);
        LOGD(L_CMD, L_V5, "IMSI=%s", G_parameter.sim_alarm.sim_imsi);
        return;
    }
    memcpy(&alarm, &G_parameter.sim_alarm, sizeof(nvram_sim_alm_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part != 1 && cmd->part != 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 1;
        if(cmd->part == 2)
        {
            if(!strcmp(cmd->pars[2], "0"))
            {
                alarm.simalm_type = 0;
            }
            else if(!strcmp(cmd->pars[2], "1"))
            {
                alarm.simalm_type = 1;
            }
            else
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1)");
                return;
            }
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.sim_alarm, &alarm, sizeof(nvram_sos_alarm_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
static void cmd_clearsim(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    sprintf(G_parameter.sim_alarm.sim_imsi, "%s", "0000000000000000");
    G_realtime_data.sim_alm = 0;
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#endif

static void cmd_pwrlimit(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0],
                ON_OFF(G_parameter.pwrlimit_sw));
        return;
    }
    if(cmd->supercmd != 1 && cmd->return_sms.cm_type == CM_SMS && track_cust_sos_or_center_check(3, cmd->return_sms.ph_num) != 9)
    {
#if defined(__GT370__)|| defined (__GT380__)
        sprintf(cmd->rsp_msg, "Error! Only SOS phone numbers are allowed to set.");
#else
#if defined(__GERMANY__)
        sprintf(cmd->rsp_msg, "Fehler! Nur die SOS- und Center-Nr.kann Befehl senden.");

#else
        sprintf(cmd->rsp_msg, "Error! Only center phone number and SOS phone numbers are allowed to set.");
#endif/*__GERMANY__*/
#endif
        return;
    }
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        G_parameter.pwrlimit_sw = 1;
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        G_parameter.pwrlimit_sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
#if defined(__GT300S__) || defined(__GT370__)|| defined (__GT380__)
    track_cust_module_sw_init();
#endif /* __GT300S__ */

}
static void cmd_almsms(CMD_DATA_STRUCT *cmd)
{
    int AlarmNumCount;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.Permission.AlarmNumCount);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    AlarmNumCount = track_fun_atoi(cmd->pars[1]);
    if(AlarmNumCount > 1 || AlarmNumCount < 0)
    {
        sprintf(cmd->rsp_msg, "Error: Value only in from 0 to 1!");
        return;
    }
    G_parameter.Permission.AlarmNumCount = AlarmNumCount;
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }

}

static void cmd_smsclear(CMD_DATA_STRUCT *cmd)
{
    if(track_cust_status_sim() == 1)
    {
        track_sim_clean_allsms();
        sprintf(cmd->rsp_msg, "OK!");
    }
}

/* BALANCE,*888## */
static void cmd_balance(CMD_DATA_STRUCT *cmd)
{
    char *p;
    int len;
    if(cmd->part < 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error! %d", cmd->part);
        return;
    }
    p = cmd->rcv_msg_source + (cmd->pars[1] - cmd->rcv_msg);
    len = strlen(p);
    if(len > 318)
    {
        len = 318;
    }
    if(p[len - 2] == 0x0D && p[len - 1] == 0x0A)
    {
        len -= 2;
    }
    else if(p[len - 1] == 0x0D)
    {
        len--;
    }
    if(p[len - 1] == '#')
    {
        len--;
    }
    track_ussd_req(cmd, p, len);

    sprintf(cmd->rsp_msg, "The request is issued, please receive the return result later.");
}

#if defined (__SAME_GT02__)
/*单GT02使用，关起来节约空间       --    chengjun  2017-04-13*/
static void cmd_SYS_VERSION(CMD_DATA_STRUCT *cmd)
{
    char *p;
    int len;
    kal_uint8 chip_rid[16];
    kal_uint16 CRC, CRC_IN = 0;
    char version;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "version:%d", G_importance_parameter_data.app_version.version);
        return;
    }
    else if(!strcmp(cmd->pars[1], "A007700"))
    {
        memcpy(chip_rid, track_drv_get_chip_id(), 16);
        CRC = GetCrc16(chip_rid, 16);
        CRC_IN = track_fun_atoi(cmd->pars[2]);
        sprintf(cmd->rsp_msg, "CRC=%d", CRC);
        return;
    }
    else if(cmd->part > 2)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    memcpy(chip_rid, track_drv_get_chip_id(), 16);
    CRC = GetCrc16(chip_rid, 16);
    CRC_IN = track_fun_atoi(cmd->pars[2]);
    if(CRC != CRC_IN)
    {
        sprintf(cmd->rsp_msg, "Error:password error!");
        return;
    }
    G_parameter.agps.sw = 1;


    version = track_fun_atoi(cmd->pars[1]);
    if(version == 1)
    {
        G_parameter.lang = 1;
        //   G_parameter.sensor_gps_work = 0;
        memcpy(&G_importance_parameter_data, &NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT_SERVER_GUMI, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);


    }
    else if(version == 2)
    {

        G_parameter.lang = 1;
        //  G_parameter.sensor_gps_work = 0;
        memcpy(&G_importance_parameter_data, &NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT_GUMI_GENERAL, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);


    }
    else if(version == 3)
    {
        G_parameter.agps.sw = 0;
        G_parameter.lang = 0;
        //G_parameter.sensor_gps_work = 5;
        memcpy(&G_importance_parameter_data, &NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT_SERVER_COOACCESS, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);

    }
    else if(version == 4)
    {
        G_parameter.lang = 1;
        // G_parameter.sensor_gps_work = 5;
        memcpy(&G_importance_parameter_data, &NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT_SERVER_TUQIANG, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);

    }
    else if(version == 0)
    {
        memcpy(&G_parameter, OTA_NVRAM_EF_PARAMETER_DEFAULT, NVRAM_EF_PARAMETER_SIZE);
        memcpy(&G_importance_parameter_data, OTA_NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Value only in from 0 to 4!");
        return;
    }
    if(G_parameter.lang == 1)
    {
        memset(G_parameter.url, 0x00, 100);
        memcpy(&G_parameter.url, "http://ditu.google.cn/maps?q=", strlen("http://ditu.google.cn/maps?q="));
    }
    else
    {
        memset(G_parameter.url, 0x00, 100);
        memcpy(&G_parameter.url, "http://maps.google.com/maps?q=", strlen("http://maps.google.com/maps?q="));
    }
    memcpy(G_importance_parameter_data.build_date, OTA_NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT->build_date, 15);
    memcpy(G_importance_parameter_data.build_time, OTA_NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT->build_time, 15);
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
    sprintf(cmd->rsp_msg, "OK");
    track_set_server_ip_status(0);
    track_os_intoTaskMsgQueueExt(track_soc_gprs_reconnect, (void*)22);//修改域名后，重新建立连接

    //track_os_intoTaskMsgQueue(track_cust_write_sim_backup_for_parameter);
}
#endif /* __SAME_GT02__ */

#if defined(__NF2318__)
#else
#if defined(__TRACK_CAR_DEVICE__)
void  cmd_DOOR(CMD_DATA_STRUCT *cmd)
{
    int value;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d",  cmd->pars[0], G_parameter.door_alarm.door_status);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 0 || value > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Range error. ");
        return;
    }
    G_parameter.door_alarm.door_status = value;
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
void track_find_car(void)
{
    static kal_uint8 cnt = 0;
    if(cnt < 12)
    {
        cnt++;
        if(cnt % 2 == 0)
        {
            track_drv_gpio_out1(0);
        }
        else
        {
            track_drv_gpio_out1(1);
        }
        tr_start_timer(TRACK_CUST_FIND_CAR_TIMER_ID, 1000, track_find_car);
    }
    else
    {
        track_drv_gpio_out1(0);
        cnt = 0;
    }

}
void cmd_FIND(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "OK!");
        track_find_car();
        return;
    }
}

/******************************************************************************
 *  Function    -  cmd_door_alarm
 *
 *  Purpose     -  报警
 *
 *  Description -
        DOORALM,<A>[,M]#
            A=ON/OFF；默认值：OFF
            M=0/1；报警上报方式，0 仅GPRS，1 SMS+GPRS；默认值：0
        DOOR,OFF#
            关闭震动报警
        DOOR#
            查询已设置的参数
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void cmd_dooralm(CMD_DATA_STRUCT *cmd)
{
    nvram_door_alarm_struct  alarm = {0};
    kal_uint8 defences = 0;
    kal_int8 sw_tmp = 0;

    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s: %s, %d", cmd->pars[0],
                ON_OFF(G_parameter.door_alarm.sw), G_parameter.door_alarm.alarm_type);
        return;
    }
    sw_tmp = G_parameter.door_alarm.sw;
    memcpy(&alarm, &G_parameter.door_alarm, sizeof(nvram_door_alarm_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 1;
        if(cmd->part >= 2)
        {
            alarm.alarm_type = track_fun_atoi(cmd->pars[2]);
            if(alarm.alarm_type != 0 && alarm.alarm_type != 1 && alarm.alarm_type != 2)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1/2)");
                return;
            }

        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.door_alarm, &alarm, sizeof(nvram_door_alarm_struct));
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    sprintf(cmd->rsp_msg, "OK!");
}
#endif
#endif

static void cmd_mserveri(CMD_DATA_STRUCT *cmd)
{
    int value, plen;
    nvram_server_addr_struct server = {0};
    char domain[TRACK_MAX_URL_SIZE] = {0};
    U8 i = 0;
    if(strstr(cmd->pars[0], "MSERVER1"))
    {
        i = 0;
    }
    else if(strstr(cmd->pars[0], "MSERVER2"))
    {
        i = 1;
    }
    else if(strstr(cmd->pars[0], "MSERVER3"))
    {
        i = 2;
    }
    else if(strstr(cmd->pars[0], "MSERVER4"))
    {
        i = 3;
    }
    if(cmd->part == 0)
    {
        if(G_importance_parameter_data.mserver2[i].conecttype == 0)
        {
            sprintf(cmd->rsp_msg, "%s,0,%d.%d.%d.%d,%d,%d", cmd->pars[0],
                    G_importance_parameter_data.mserver2[i].server_ip[0], G_importance_parameter_data.mserver2[i].server_ip[1],
                    G_importance_parameter_data.mserver2[i].server_ip[2], G_importance_parameter_data.mserver2[i].server_ip[3],
                    G_importance_parameter_data.mserver2[i].server_port, G_importance_parameter_data.mserver2[i].soc_type);
        }
        else
        {
            sprintf(cmd->rsp_msg, "%s,%d,%s,%d,%d", cmd->pars[0],
                    G_importance_parameter_data.mserver2[i].conecttype,
                    track_domain_decode(G_importance_parameter_data.mserver2[i].url),
                    G_importance_parameter_data.mserver2[i].server_port,
                    G_importance_parameter_data.mserver2[i].soc_type);
        }
        return;
    }
    if(cmd->part != 3 && cmd->part != 4 && cmd->part != 5)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(G_importance_parameter_data.mserver2[i].lock != 0)
    {
#if defined(__GERMANY__)
        sprintf(cmd->rsp_msg, "Fehler! Die Plattform Adresse wird nicht erkannt!");
#else
        sprintf(cmd->rsp_msg, "Error: The platform addresses are Locked modify!");
#endif
        return;
    }
    memset(cmd->rsp_msg, 0, sizeof(cmd->rsp_msg));

    memcpy(&server, &G_importance_parameter_data.mserver2[i], sizeof(nvram_server_addr_struct));

    value = track_fun_atoi(cmd->pars[CM_Par1]);
    if(value != 0 && value != 1)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (0/1)");
        return;
    }
    server.conecttype = value;

    plen = strlen(cmd->pars[CM_Par2]);
    if(plen <= 0)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 2 is empty!");
        return;
    }
    if(plen >= 98)
    {
        sprintf(cmd->rsp_msg, "Error: Parameters 2 characters too long!");
        return;
    }
    if(track_fun_check_ip(cmd->pars[CM_Par2]))
    {
        if(server.conecttype != 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 domain is not formatted correctly!");
            return;
        }
        memset(server.server_ip, 0, 4);
        if(!track_fun_asciiIP2Hex(cmd->pars[CM_Par2], (void*)&server.server_ip[0]))
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 is not a valid IP address format!");
            return;
        }
        server.url[0] = 0;
    }
    else
    {
        if(server.conecttype != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 is not a valid IP address format!");
            return;
        }
        if(strstr(cmd->pars[CM_Par2], "http://"))
        {
            sprintf(cmd->rsp_msg, "Error: The domain name does not include \"http://\"!");
            return;
        }
        {
            memcpy(domain, cmd->rcv_msg_source + (cmd->pars[CM_Par2] - cmd->rcv_msg), plen);
            track_domain_encode(domain, server.url);
            memset(server.server_ip, 0, 4);
        }
    }

    if(!track_fun_check_data_is_port(cmd->pars[CM_Par3]))
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 3 (0~65535)");
        return;
    }
    server.server_port = track_fun_string2U16(cmd->pars[CM_Par3]);

    if(cmd->part == 4)
    {
        value = track_fun_atoi(cmd->pars[CM_Par4]);
        if(value != 0 && value != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 4 (0/1)");
            return;
        }
    }
    server.soc_type = 0; // 当前只支持TCP
    memcpy(&G_importance_parameter_data.mserver2[i], &server, sizeof(nvram_server_addr_struct));
    Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
    sprintf(cmd->rsp_msg, "OK");
}

static void cmd_bat(CMD_DATA_STRUCT *cmd)
{	
    charge_measure_struct charge_measure = {0};
	kal_int32 vbat = 0,ichr = 0,vchr = 0;
    kal_int32 BatTemp = 0;
    float charger = 0;
    if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    track_bmt_get_ADC_result(&charge_measure);
    charger = track_cust_status_charger();
    if(charger > 1) charger = 1;
    //BatTemp = (float)charge_measure.bmt_vTemp/1000;
#if defined(__NF2318__)
	LOGD(L_APP, L_V5,"%f,%f",charge_measure.bmt_vBat,charge_measure.bmt_iChr);
	vbat = charge_measure.bmt_vBat * 1000000;
	ichr = charge_measure.bmt_iChr * 1000000;
	vchr = charge_measure.bmt_vChr * 1000000;
	if(track_cust_status_charger() == 0)
	{
		vbat = track_drv_get_batter_voltage();
	}
	if(!strcmp(cmd->pars[0], "BAT"))
	{
		sprintf(cmd->rsp_msg, "battery temp:%f ,VBAT:%f ,charge:%s", charge_measure.bmt_vTemp / 1000.00, (vbat/1000000.00), ON_OFF(charger));//charge_measure.bmt_vBat
	}
	else
	{
		sprintf(cmd->rsp_msg, "VBAT=%d:%d:%d",vbat,vchr,ichr);
	}
#else
    sprintf(cmd->rsp_msg, "battery temp:%f ,VBAT:%f ,charge:%s", charge_measure.bmt_vTemp / 1000.00, charge_measure.bmt_vBat, ON_OFF(charger));
#endif
}

static void cms_mserver(CMD_DATA_STRUCT *cmd)
{
    U8 i = 0;
    char tmp[100] = {0};
    if(cmd->part == 0)
    {
        for(i = 0; i < 4; i++)
        {
            if(G_importance_parameter_data.mserver2[i].conecttype == 0)
            {
                sprintf(tmp, "[%d]:0,%d.%d.%d.%d,%d,%d;", i + 1,
                        G_importance_parameter_data.mserver2[i].server_ip[0], G_importance_parameter_data.mserver2[i].server_ip[1],
                        G_importance_parameter_data.mserver2[i].server_ip[2], G_importance_parameter_data.mserver2[i].server_ip[3],
                        G_importance_parameter_data.mserver2[i].server_port, G_importance_parameter_data.mserver2[i].soc_type);
            }
            else
            {
                sprintf(tmp, "[%d]:%d,%s,%d,%d", i + 1,
                        G_importance_parameter_data.mserver2[i].conecttype,
                        track_domain_decode(G_importance_parameter_data.mserver2[i].url),
                        G_importance_parameter_data.mserver2[i].server_port,
                        G_importance_parameter_data.mserver2[i].soc_type);
            }
            strcat(cmd->rsp_msg, tmp);
        }
        return;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error! %d", cmd->part);
        return;
    }
}
#if defined(__NF2318__)
#else
static void cmd_fixmode(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s,%d,%d", cmd->pars[0], G_parameter.fixmode.gps_fix_sw, G_parameter.fixmode.wf_lbs_fix_sw);
        return;
    }
    if(cmd->part == 2)
    {
        U8 g, w;
        g = atoi(cmd->pars[1]);
        w = atoi(cmd->pars[2]);
        if(g < 0 || g > 1)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (0-1)");
            return;
        }
        if(w < 0 || w > 1)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (0-1)");
            return;
        }
        G_parameter.fixmode.gps_fix_sw = g;
        G_parameter.fixmode.wf_lbs_fix_sw = w;
        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "OK!");
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error!");
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

}

static void cmd_FIXPRI(CMD_DATA_STRUCT *cmd)
{
    int value;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.fixmode.fix_level);
        return;
    }
    else if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value < 0 || value > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Range error(0-1)");
        return;
    }
    G_parameter.fixmode.fix_level = value;
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#endif


#if defined __CUSTOM_WIFI_FEATURES_SWITCH__
static void cms_wificmd(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "Error!");
        return;
    }
    if(!strcmp(cmd->pars[1], "ON"))
    {
        track_drv_wifi_cmd(1);
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        track_drv_wifi_cmd(0);
    }
    else if(!strcmp(cmd->pars[1], "SCAN"))
    {
        track_drv_wifi_cmd(2);
    }
    sprintf(cmd->rsp_msg, "OK!");
}
#endif

kal_uint32 track_get_ft_timer(void)
{
    return ft_timer;
}
kal_uint32 track_get_ft_work_timer(void)
{
    return ft_work_timer;
}
static void cmd_FT(CMD_DATA_STRUCT * cmd)
{
    int value, timer1, timer2;
    if(G_parameter.group_package.sw == 0)
    {
        sprintf(cmd->rsp_msg, "Error: batch:OFF");
        return;
    }
    if(cmd->part > 0)
    {
        if(cmd->part == 2)
        {

            value  = track_fun_atoi(cmd->pars[1]);
            if(value < 1 || value > 18000)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 1 (1 to 18000)");
                return;
            }
            ft_timer = value;

            value  = track_fun_atoi(cmd->pars[2]);
            ft_work_timer = value;
            if(value < 10 || value > 18000)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2(10 to 18000)");
                return;
            }

        }
        else if(cmd->part == 1)
        {
            value  = track_fun_atoi(cmd->pars[1]);
            if(value == 0)
            {
                sprintf(cmd->rsp_msg, "OK!");
                tr_stop_timer(TRACK_CUST_FT_WORK_TIMER_ID);
                track_cust_gps_location_timeout(10);
                return;
            }
            else
            {
                sprintf(cmd->rsp_msg, "Error: Number of parameters error! %d", cmd->part);
                return;
            }

        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error! %d", cmd->part);
            return;
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error! %d", cmd->part);
        return;
    }
    track_cust_gps_work_req((void *)16);
    sprintf(cmd->rsp_msg, "OK!");
}


#if defined(__FLY_MODE__)
static void cmd_flycut(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0],
                ON_OFF(G_parameter.flycut));
        return;
    }
    if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    if(!strcmp(cmd->pars[1], "ON"))
    {
        G_parameter.flycut = 1;
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(G_parameter.flycut == 1)
        {
            track_cust_flymode_set(0);
        }
        G_parameter.flycut = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }

    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#endif

#if defined (__CUST_FAKECELL__)
/******************************************************************************
 *  Function    -  cmd_fakecell
 *
 *  Purpose     -  防伪基站功能使能
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2016-11-11,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void cmd_fakecell(CMD_DATA_STRUCT *cmd)
{
    char *p;
    int len;
    kal_uint8 chip_rid[16];
    kal_uint16 CRC, CRC_IN = 0;
    char enable;

    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "fake cell:%d", G_parameter.fake_cell_enable);
        return;
    }

    if(cmd->return_sms.cm_type != CM_AT)
    {
        sprintf(cmd->rsp_msg, "Error:support AT!");
        return;
    }

    if(cmd->part != 2)
    {
        sprintf(cmd->rsp_msg, "Error:Number of parameters error!");
        return;
    }

    memcpy(chip_rid, track_drv_get_chip_id(), 16);
    CRC = GetCrc16(chip_rid, 16);
    CRC_IN = track_fun_atoi(cmd->pars[2]);
    if(CRC != CRC_IN)
    {
        sprintf(cmd->rsp_msg, "Error:password error!");
        return;
    }

    enable = track_fun_atoi(cmd->pars[1]);
    if(enable != 0 && enable != 1)
    {
        sprintf(cmd->rsp_msg, "Error:Parameter 1 ");
        return;
    }

    if(G_parameter.fake_cell_enable != enable)
    {
        G_parameter.fake_cell_enable = enable;
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        OTA_track_custom_fake_cell_feature_enable(enable);
    }

    sprintf(cmd->rsp_msg, "OK");
}


static void cmd_fakebs(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 fake_cell_enable;
    kal_uint8 fake_cell_to_ams;
    kal_int32 tmp;

    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d", cmd->pars[0], ON_OFF(G_parameter.fake_cell_enable), G_parameter.fake_cell_to_ams);
        return;
    }
    else if(cmd->part > 2)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    fake_cell_enable = G_parameter.fake_cell_enable;
    fake_cell_to_ams = G_parameter.fake_cell_to_ams;

    if(strcmp(cmd->pars[1], "ON") == 0)
    {
        if(cmd->part < 1 || cmd->part > 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        fake_cell_enable = 1;
        if(cmd->part >= 2)
        {
            tmp = track_fun_atoi(cmd->pars[2]);
            if(tmp < 0 || tmp > 1)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0 to 1)");
                return;
            }
            fake_cell_to_ams = tmp;
        }
    }
    else if(strcmp(cmd->pars[1], "OFF") == 0)
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        fake_cell_enable = 0;
    }
    else if(strcmp(cmd->pars[1], "TEST") == 0)//便于测试查看当前是否防伪基站
    {
        if(cmd->part == 1)
        {
            sprintf(cmd->rsp_msg, "fakeCell temp status:%d", G_parameter.fake_cell_auto_temp);
            return;
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }

    if(G_parameter.fake_cell_enable != fake_cell_enable)
    {
        G_parameter.fake_cell_enable = fake_cell_enable;
        OTA_track_custom_fake_cell_feature_enable(fake_cell_enable);
    }

    G_parameter.fake_cell_to_ams = fake_cell_to_ams;
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);

    sprintf(cmd->rsp_msg, "OK");
}

static void cmd_fcfalm(CMD_DATA_STRUCT *cmd)
{
    nvram_FCFALM_struct alarm = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d", cmd->pars[0],
                ON_OFF(G_parameter.fcfalm.sw), G_parameter.fcfalm.alarm_type, G_parameter.fcfalm.alarm_filter);
        return;
    }
    memcpy(&alarm, &G_parameter.fcfalm, sizeof(nvram_FCFALM_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 3)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 1;
        if(cmd->part >= 2)
        {
            alarm.alarm_type = track_fun_atoi(cmd->pars[2]);
            if(alarm.alarm_type != 0 && alarm.alarm_type != 1 && alarm.alarm_type != 2 && alarm.alarm_type != 3)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/1/2/3)");
                return;
            }
        }

        if(cmd->part == 3)
        {
            alarm.alarm_filter = track_fun_atoi(cmd->pars[3]);
            if(alarm.alarm_filter < 15  || alarm.alarm_filter > 120)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (15-120)");
                return;
            }
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.fcfalm, &alarm, sizeof(nvram_FCFALM_struct));

    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#endif /* __CUST_FAKECELL__ */


#if defined (__CUST_BT__)
/******************************************************************************
 *  Function    -  cmd_ble
 *
 *  Purpose     -  蓝牙设置
 *
 *  Description -  ON/OFF，广播时间，监听时间，休眠时间   (秒)
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2016-11-17,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static cmd_ble(CMD_DATA_STRUCT *cmd)
{
    nvram_bt_struct bt;
    kal_int32 tmp;

    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d,%d", cmd->pars[0], ON_OFF(G_parameter.bt.sw), \
                G_parameter.bt.broadcast_time, G_parameter.bt.listen_time, G_parameter.bt.sleep_time);
        return;
    }
    else if(cmd->part > 4)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    memcpy(&bt, &G_parameter.bt, sizeof(nvram_bt_struct));


    if(strcmp(cmd->pars[1], "ON") == 0)
    {
        bt.sw = 1;
    }
    else if(strcmp(cmd->pars[1], "OFF") == 0)
    {
        bt.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }

    if(cmd->part >= 2)
    {
        tmp = track_fun_atoi(cmd->pars[2]);
        if(tmp < 0 || tmp > 255)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (0 to 255)");
            return;
        }
        bt.broadcast_time = tmp;
    }

    if(cmd->part >= 3)
    {
        tmp = track_fun_atoi(cmd->pars[3]);
        if(tmp < 0 || tmp > 255)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 3 (0 to 255)");
            return;
        }
        bt.listen_time = tmp;
    }

    if(cmd->part >= 4)
    {
        tmp = track_fun_atoi(cmd->pars[4]);
        if(tmp < 0 || tmp > 65535)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 4 (0 to 65535)");
            return;
        }
        bt.sleep_time = tmp;
    }

    memcpy(&G_parameter.bt, &bt, sizeof(nvram_bt_struct));
    track_cust_bt_init();

    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}

#endif /* __CUST_BT__ */

#if defined (__NOFIX_GPSDUP__)
static void cmd_gpsdup(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 gpsdup;

    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], ON_OFF(G_parameter.gpsDup));
        return;
    }

    if(cmd->part != 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    if(strcmp(cmd->pars[1], "ON") == 0)
    {
        gpsdup = 1;
    }
    else if(strcmp(cmd->pars[1], "OFF") == 0)
    {
        gpsdup = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }

    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        G_parameter.gpsDup = gpsdup;
        track_cust_gpsdup_switch(gpsdup);
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }

}
#endif /* __NOFIX_GPSDUP__ */


void cmd_sncovery(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        track_os_importance_backup_read();
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
    }
}

#if defined(__BACKUP_SERVER__)
static void cmd_Bserver(CMD_DATA_STRUCT *cmd)
{
    {
        int value, plen;
        nvram_server_addr_struct server = {0};
        extern  nvram_importance_parameter_struct NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT;
        if(cmd->part == 0)
        {
            if(G_importance_parameter_data.bserver.conecttype == 0)
            {
                sprintf(cmd->rsp_msg, "BSERVER,0,%d.%d.%d.%d,%d,%d",
                        G_importance_parameter_data.bserver.server_ip[0], G_importance_parameter_data.bserver.server_ip[1],
                        G_importance_parameter_data.bserver.server_ip[2], G_importance_parameter_data.bserver.server_ip[3],
                        G_importance_parameter_data.bserver.server_port, G_importance_parameter_data.bserver.soc_type);
            }
            else
            {
                sprintf(cmd->rsp_msg, "BSERVER,%d,%s,%d,%d",
                        G_importance_parameter_data.bserver.conecttype,
                        track_domain_decode(G_importance_parameter_data.bserver.url),
                        G_importance_parameter_data.bserver.server_port,
                        G_importance_parameter_data.bserver.soc_type);
            }
            return;
        }
        else if(cmd->part == 1 && !strcmp(cmd->pars[CM_Par1], "RESET"))
        {
            //extern nvram_importance_parameter_struct NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT[];
            memcpy(&G_importance_parameter_data.bserver, &NVRAM_EF_IMPORTANCE_PARAMETER_DEFAULT.bserver, sizeof(nvram_server_addr_struct));
            Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
            sprintf(cmd->rsp_msg, "reset OK!");
        }
        else if(cmd->part == 1 && !strcmp(cmd->pars[CM_Par1], "NULL"))
        {
            memset(&G_importance_parameter_data.bserver, 0, sizeof(nvram_server_addr_struct));
            Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
            sprintf(cmd->rsp_msg, "OK");
            track_soc_disconnect();
            //track_os_intoTaskMsgQueue(track_cust_write_sim_backup_for_parameter);

            return;
        }
        if(cmd->part != 3 && cmd->part != 4)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        if(G_importance_parameter_data.bserver.lock != 0)
        {
            sprintf(cmd->rsp_msg, "Error: The platform addresses are Locked modify!");
            return;
        }
        memset(cmd->rsp_msg, 0, sizeof(cmd->rsp_msg));

        memcpy(&server, &G_importance_parameter_data.bserver, sizeof(nvram_server_addr_struct));

        value = track_fun_atoi(cmd->pars[CM_Par1]);
        if(value != 0 && value != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (0/1)");
            return;
        }
        server.conecttype = value;

        plen = strlen(cmd->pars[CM_Par2]);
        if(plen <= 0)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 is empty!");
            return;
        }
        if(plen >= 99)
        {
            sprintf(cmd->rsp_msg, "Error: Parameters 2 characters too long!");
            return;
        }
        if(track_fun_check_ip(cmd->pars[CM_Par2]))
        {
            if(server.conecttype != 0)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 domain is not formatted correctly!");
                return;
            }
            memset(server.server_ip, 0, 4);
            if(!track_fun_asciiIP2Hex(cmd->pars[CM_Par2], (void*)&server.server_ip[0]))
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 is not a valid IP address format!");
                return;
            }
            server.url[0] = 0;
        }
        else
        {
            if(server.conecttype != 1)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 is not a valid IP address format!");
                return;
            }
            if(strstr(cmd->pars[CM_Par2], "http://"))
            {
                sprintf(cmd->rsp_msg, "Error: The domain name does not include \"http://\"!");
                return;
            }
            {
                char domain[TRACK_MAX_URL_SIZE] = {0};
                memcpy(domain, cmd->rcv_msg_source + (cmd->pars[CM_Par2] - cmd->rcv_msg), plen);
                track_domain_encode(domain, server.url);
            }
        }

        if(!track_fun_check_data_is_port(cmd->pars[CM_Par3]))
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 3 (0~65535)");
            return;
        }
        server.server_port = track_fun_string2U16(cmd->pars[CM_Par3]);

        if(cmd->part == 4)
        {
            value = track_fun_atoi(cmd->pars[CM_Par4]);
            if(value != 0 && value != 1)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 4 (0/1)");
                return;
            }
        }
        server.soc_type = 0; // 当前只支持TCP
        memcpy(&G_importance_parameter_data.bserver, &server, sizeof(nvram_server_addr_struct));
#if defined(__GT740__)
        track_cust_module_resetpro();
        G_realtime_data.TPRO_COUNT = 0;
        G_parameter.new_position_sw = 0;
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
#endif
        Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
        sprintf(cmd->rsp_msg, "OK");
        track_soc_reset_reconnect_count2();
        //track_os_intoTaskMsgQueue(track_cust_write_sim_backup_for_parameter);
    }
}
static void cmd_BsClear(CMD_DATA_STRUCT *cmd)
{
    nvram_server_addr_struct server = {0};
    if(cmd->part == 0)
    {
        memcpy(&G_importance_parameter_data.bserver, &server, sizeof(nvram_server_addr_struct));
        Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    sprintf(cmd->rsp_msg, "OK");
}
#endif

#if defined(__LUYING__)
extern  void track_cust_server4_conn(void);
extern void track_cust_stop_server4_conn(void);

kal_uint8* track_get_LY_stamp(void)
{
    LOGH(L_DRV, L_V5, G_realtime_data.record_stamp, 6);
    return G_realtime_data.record_stamp;
}

void track_ly_timeout(void)
{
    track_cust_paket_msg_upload(track_get_LY_stamp(), KAL_TRUE, "LY fail", strlen("LY fail"));
}

static void cmd_LY(CMD_DATA_STRUCT * cmd)
{
    int value;

    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s,%d", cmd->pars[0], G_realtime_data.record_time);
        return;
    }

    if(track_cust_is_recording(2) || track_get_audio_queue() != 0)
    {
        track_os_intoTaskMsgQueue(track_cust_server4_conn);
        sprintf(cmd->rsp_msg, "Recording,Please try again later!");
        return;
    }
    
    if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    memset(G_realtime_data.record_stamp, 0, 4);
    if(cmd->return_sms.cm_type == CM_ONLINE)
    {
        memcpy(G_realtime_data.record_stamp, cmd->return_sms.stamp, 4);
    }
    
    value = track_fun_atoi(cmd->pars[1]);

    if(value < 10 || value > 300)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter (10-300)");
    }
    else
    {

        track_os_intoTaskMsgQueue(track_cust_server4_conn);
        track_cust_record(3, 1, RECORD_INTERVAL);
        G_realtime_data.record_time  = value;
        G_realtime_data.record_cnt = value / RECORD_INTERVAL;
        G_realtime_data.record_last_time = value % RECORD_INTERVAL;
        G_realtime_data.record_file = 0;
        G_realtime_data.record_up = 0;
        tr_start_timer(TRACK_LY_TIMEOUT_TEIMER_ID, (60 + value) * 1000, track_ly_timeout);
        tr_start_timer(TRACK_LY_TIMEOUT_10min_TEIMER_ID, (10 * 60 + value) * 1000, track_cust_stop_server4_conn);

        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE) || (Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE)))
        {
            sprintf(cmd->rsp_msg, "OK!");
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error!");
        }
    }
}
#endif


#if defined(__DROP_ALM__)
static void cmd_dropalm(CMD_DATA_STRUCT * cmd)
{
    U8 value;
    nvram_drop_alarm nv_drop_alm = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d(0=only GPRS,1=GPRS+SMS,2=GPRS+SMS+CALL,3=GPRS+CALL)", cmd->pars[0], ON_OFF(G_parameter.drop_alm.sw));
        return;
    }
    else if(cmd->part != 2)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(!strcmp(cmd->pars[1], "ON"))
        nv_drop_alm.sw = 1;
    else if(!strcmp(cmd->pars[1], "OFF"))
        nv_drop_alm.sw = 0;
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    value = atoi(cmd->pars[2]);

    if(value > 3)
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 2 (0/3)");
        return;

    }
    nv_drop_alm.alarm_type = value;
    memcpy(&G_parameter.drop_alm, &nv_drop_alm, sizeof(nvram_drop_alarm));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#endif


static void cmd_sv(CMD_DATA_STRUCT *cmd)
{
    U16 value;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%ds,%dmin", cmd->pars[0],
                ON_OFF(G_parameter.sv.sw), G_parameter.sv.t1, G_parameter.sv.t2);
        return;
    }
    if(cmd->part > 3)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    else
    {
        if(!strcmp(cmd->pars[1], "ON"))
        {
            G_parameter.sv.sw = 1;
        }
        else if(!strcmp(cmd->pars[1], "OFF"))
        {
            G_parameter.sv.sw = 0;
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
            return;
        }

        if(cmd->part > 1)
        {
            value = track_fun_atoi(cmd->pars[2]);
            if(value < 5 || value > 18000)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (5-18000)");
                return;
            }
            else
            {
                G_parameter.sv.t1 = value;
            }
            if(cmd->part > 2)
            {
                value = track_fun_atoi(cmd->pars[3]);
                if(value < 0 || value > 3600)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 3 (0-3600)");
                    return;
                }
                else
                {
                    G_parameter.sv.t2 = value;
                }
            }
        }
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }

    if(G_parameter.sv.sw == 1)
    {
        track_cust_paket_9409_handle();
    }
}

static void cmd_cxsv(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        track_cust_paket_9409_handle();
    }
}

static void cmd_nbver(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 sw_nbver;

    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], ON_OFF(G_parameter.sw_nbver));
        return;
    }
    if(cmd->part != 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    if(strcmp(cmd->pars[1], "ON") == 0)
    {
        sw_nbver = 1;
    }
    else if(strcmp(cmd->pars[1], "OFF") == 0)
    {
        sw_nbver = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    G_parameter.sw_nbver = sw_nbver;
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
#if defined(__SMT_BMS__)
static void cmd_bms(CMD_DATA_STRUCT * cmd)
{
    nvram_bmsfault_struct alarm = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s,%d,%d", cmd->pars[0],
                ON_OFF(G_parameter.Bmsfault_struct.sw), G_parameter.Bmsfault_struct.alarm_type, G_parameter.Bmsfault_struct.readtimer);
        return;
    }
    memcpy(&alarm, &G_parameter.Bmsfault_struct, sizeof(nvram_bmsfault_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 3)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 1;
        if(cmd->part >= 2)
        {
            alarm.alarm_type = track_fun_atoi(cmd->pars[2]);
            if(alarm.alarm_type != 0)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (Only 0)");
                return;
            }
        }

        if(cmd->part == 3)
        {
            alarm.readtimer = track_fun_atoi(cmd->pars[3]);
            if(alarm.readtimer < 1  || alarm.readtimer > 300)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 3 (1-300)");
                return;
            }
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.Bmsfault_struct, &alarm, sizeof(nvram_bmsfault_struct));

    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
static void cmd_BMSTC(CMD_DATA_STRUCT *cmd)
{
    U8 evt, len, data[16] = {0};
    int i;
    if(cmd->part == 0)
    {
        return;
    }
    else if(cmd->part == 1)
    {
        track_cust_bms_packet_event(atoi(cmd->pars[1]));
    }
    else
    {
        len = atoi(cmd->pars[2]);
        evt = atoi(cmd->pars[1]);
        if(len > 16)len = 16;
        for(i = 0; i < len; i++)
        {
            data[i] = atoi(cmd->pars[i+3]);
        }
        track_drv_write_packet_bms_data(evt, data, len);
    }
    //track_drv_write_bms_data(atoi(cmd->pars[1]));
}
#endif
static void cmd_OBD_cmd(CMD_DATA_STRUCT * cmd)
{
#if defined(__OBD__)
    int len, j;
    char *data;
    j = cmd->pars[1] - cmd->rcv_msg;
    len = strlen(cmd->rcv_msg_source) - j;
    data = cmd->rcv_msg_source + (cmd->pars[1] - cmd->rcv_msg);
    LOGD(L_APP, L_V2, "%d,%d,%p,%p,{%s},{%s},{%s}", j, len, cmd->rcv_msg_source,
         cmd->pars[1], cmd->rcv_msg, cmd->pars[1], cmd->rcv_msg, data);
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%s", cmd->pars[0], ON_OFF(G_parameter.obd.sw));
        return;
    }
    else if(len > 0 && j > 0)
    {
        if(!strcmp(cmd->pars[1], "ON"))
        {
            G_parameter.obd.sw = 1;
            obd_poweron(33);
            sprintf(cmd->rsp_msg, "OBD: ON");
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        }
        else if(!strcmp(cmd->pars[1], "OFF"))
        {
            G_parameter.obd.sw = 0;
            obd_poweron(4);
            sprintf(cmd->rsp_msg, "OBD: OFF");
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        }
        else if(!strcmp(cmd->pars[1], "VERSION"))
        {
            track_obd_version(cmd);
            //sprintf(cmd->rsp_msg, "OBD Version:%s", track_obd_get_version());
        }
        else if(!strcmp(cmd->pars[1], "UPLOADTIME")) /*定时上报数据的间隔时间*/
        {
            int value = 0;
            if(cmd->part == 1)
            {
                sprintf(cmd->rsp_msg, "%s %s:%d", cmd->pars[0], cmd->pars[1], G_parameter.obd.upload_time);
                return;
            }
            else if(cmd->part > 2)
            {
                sprintf(cmd->rsp_msg, "ERROR:100");//指令长度不正确
                return;
            }
            if(strlen(cmd->pars[2]) > 0)
                value = atoi(cmd->pars[2]);
            if(value < 10 || value > 3600)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (10～3600)");
                return;
            }
            G_parameter.obd.upload_time = value;
            sprintf(cmd->rsp_msg, "%s %s: %d", cmd->pars[0], cmd->pars[1], G_parameter.obd.upload_time);
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
            obd_upload_time_update_parameter((void*)1);
        }
        else if(!strcmp(cmd->pars[1], "CAR"))
        {
            int car = 0, total_mileage = 0;
            if(cmd->part == 1)
            {
                sprintf(cmd->rsp_msg, "%s %s:%d (total mileage:%d)", cmd->pars[0], cmd->pars[1], G_parameter.obd.car, G_parameter.obd.total_mileage);
                return;
            }
            else if(cmd->part > 3)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter!");
                return;
            }
            if(cmd->part >= 2)
            {
                if(strlen(cmd->pars[2]) > 0)
                    car = atoi(cmd->pars[2]);
                if(car <= 0 || car > 28)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 2 (1～28)");
                    return;
                }
            }
            if(cmd->part == 3)
            {
                if(strlen(cmd->pars[3]) > 0)
                    total_mileage = atoi(cmd->pars[3]);
                if(total_mileage < 0 || total_mileage > 0x00FFFFFF)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 3 (0～16777215)");
                    return;
                }
            }
            if(car != G_parameter.obd.car || G_parameter.obd.total_mileage != total_mileage)
            {
                G_parameter.obd.car = car;
                G_parameter.obd.total_mileage = total_mileage;
                track_obd_setcar_and_odometer(cmd, car, total_mileage);
                Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
            }
            sprintf(cmd->rsp_msg, "%s %s:%d (total mileage:%d)", cmd->pars[0], cmd->pars[1], G_parameter.obd.car, G_parameter.obd.total_mileage);
        }
        else if(!strcmp(cmd->pars[1], "ODOMETER"))
        {
            int total_mileage = 0;
            if(cmd->part == 1)
            {
                sprintf(cmd->rsp_msg, "%s %s:%d", cmd->pars[0], G_parameter.obd.total_mileage);
                return;
            }
            else if(cmd->part > 2)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter!");
                return;
            }
            if(cmd->part >= 2)
            {
                if(strlen(cmd->pars[2]) > 0)
                    total_mileage = atoi(cmd->pars[2]);
                if(total_mileage < 0 || total_mileage > 0x00FFFFFF)
                {
                    sprintf(cmd->rsp_msg, "Error: Parameter 2 (0～16777215)");
                    return;
                }
            }
            if(G_parameter.obd.total_mileage != total_mileage)
            {
                G_parameter.obd.total_mileage = total_mileage;
                track_obd_setcar_and_odometer(cmd, 1, total_mileage);
                Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
            }
            sprintf(cmd->rsp_msg, "%s %s:%d", cmd->pars[0], cmd->pars[1], G_parameter.obd.total_mileage);
        }
        else if(!strcmp(cmd->pars[1], "UPLOADTYPE"))
        {
            int value = 0;
            if(strlen(cmd->pars[2]) > 0)
                value = atoi(cmd->pars[2]);
            if(value > 0 && value < 10)
                G_parameter.obd.upload_type = value;
            sprintf(cmd->rsp_msg, "upload type: %d", G_parameter.obd.upload_type);
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        }
        else if(!strcmp(cmd->pars[1], "VIN"))
        {
            track_obd_getVIN(cmd);
        }
        else if(!strcmp(cmd->pars[1], "CLEAR"))
        {
            track_obd_clear(cmd);
        }
        else if(!strcmp(cmd->pars[1], "ERROR_ID"))
        {
            if(cmd->part == 1)
            {
                track_obd_getErrorId(cmd);
            }
            else if(cmd->part == 2 && !strcmp(cmd->pars[2], "CLEAN"))
            {
                track_obd_clsobd(cmd);
            }
            else
            {
                sprintf(cmd->rsp_msg, "Error: Parameter!");
                return;
            }
        }
        else
        {
            track_cust_obd_testcmd(cmd->rsp_msg, cmd);
        }
    }
#endif /* __OBD__ */
}
static void cmd_OBD_PassThrough_mode(CMD_DATA_STRUCT * cmd)
{
#if defined(__OBD__)
    int len, j;
    j = cmd->pars[1] - cmd->rcv_msg;
    //LOGD(L_APP, L_V2, "%p,%p,%p,{%s},{%s},{%s}",
    //    cmd->rcv_msg_source, cmd->pars[1], cmd->rcv_msg, cmd->pars[1], cmd->rcv_msg, cmd->rcv_msg_source);
    len = strlen(cmd->rcv_msg_source);
    LOGD(L_APP, L_V2, "%d,%d,%d", len, j, strlen(cmd->rcv_msg_source));
    LOGH(L_APP, L_V2, cmd->rcv_msg_source, strlen(cmd->rcv_msg_source));
    if(cmd->rcv_msg_source[len - 1] == 0x0D)
    {
        cmd->rcv_msg_source[len] = 0x0A;
        cmd->rcv_msg_source[len + 1] = 0x00;
        len++;
    }
    if(len > 0 && len < 200 && j > 0)
    {
        track_cust_obd_tc(cmd->rcv_msg_source + j, len - j);
    }
#endif /* __OBD__ */
}

#if 0
void cmd_test_msg_con(CMD_DATA_STRUCT *cmd)
{
	int valu;
	int typ;
	if(cmd->part == 2)
	{
		valu = track_fun_atoi(cmd->pars[1]);
		typ = track_fun_atoi(cmd->pars[2]);
		test_desired_value(valu,typ);
		sprintf(cmd->rsp_msg, "ojbk");
	}
	else
	sprintf(cmd->rsp_msg, "erro");
}
#endif

static cust_recv_struct cust_recv_table[] =
{
    {"SET_VER2",    cmd_set_version2,       },          // 软件版本
    {"BASEVERSION", cmd_get_base_version,   },          // 软件版本
    {"VERSION",     cmd_get_version,        },          // 软件版本查询
    {"NETLOG",      cmd_test_net_log,       },          // 临时测试使用
#if defined(__SMT_BMS__)
    {"BMSTC",      cmd_BMSTC,       },
    {"BMS",cmd_bms,    },
#endif

#if defined(__LUYING__)
    {"LY",      cmd_LY,             },
    {"REC",      cmd_LY,             },
    {"SERVER4",   cmd_server4,      },          //录音上报服务器地址
#endif
#if defined(__DROP_ALM__)
    {"DROPALM", cmd_dropalm,        },
#endif

#if defined(__GERMANY__)
    {"GPS",       cmd_dw,                 },          //
#endif
#if defined(__NF2318__)
#else
    {"FIXMODE",  cmd_fixmode,               },
    {"FIXPRI",  cmd_FIXPRI,               },
#endif
    //{"DW",          cmd_dw,                 },          // 取中文地址
    //{"POSITION",    cmd_dw,                 },          //
    //{"123",         cmd_dw,                 },          //
    //{"DWXX",        cmd_dw,                 },          // 在线查询位置指令
    //{"WHERE",       cmd_dw,                 },          //
    //{"URL",         cmd_dw,                 },          //
#if defined(__SPANISH__)
    {"LOCALIZAR",         cmd_dw,                 },          //
#endif
    {"EURL",        cmd_eurl,               },          //
    {"LOCKIP",      cmd_lockip,             },          //
    {"QLOCKIP",     cmd_qlockip,            },          //
#if defined(__NF2318__)
#else
    {"GTIMER",      cmd_gtimer,             },          // 手表手机定时定位功能
    {"LCD",         cmd_lcd,                },          // 屏显控制
#endif
    {"SMSTC",       cmd_smstc,              },

    {"LANG",        cmd_lang,               },          //
    {"APN",         cmd_apn,                },          //
    {"ASETAPN",     cmd_asetapn,            },          //
    {"IMEI",        cmd_imei,               },          //
    {"IMSI",        cmd_imsi,               },          //
    {"ICCID",       cmd_iccid,              },          //
    {"VIEWIP",      cmd_viewip,             },          //
#if!(defined(__GT300S__))
#if !defined(__NF2318__)
    {"LEDSLEEP",    cmd_ledsleep,           },          //
#endif
    {"LEDSW",       cmd_ledsw,              },          //

#endif
#if defined(__ET310__) || defined(__MT200__)
    {"LEDON",       track_cust_led_on,      },          // LED灯控制
    {"LEDOFF",      track_cust_led_off,     },          // LED灯控制
    {"PS",          cmd_ps,                 },
#endif

    {"DEFMODE",     cmd_defmode,            },
    {"SERVER1",     cmd_server,             },          //
    {"SERVER",      cmd_server,             },          //

    {"SERVER2",     cmd_server2,            },          //
    {"AGPS",        cmd_agps,               },          // APGS Server
    {"AMS",         cmd_ams,                },          // APGS Server
    {"AMSCONN",     cmd_amsconn,            },          // 设置每天连接AMS次数上限
    {"ASETGMT",     cmd_asetgmt,            },          // 时区自适应状态查询
    {"GMT",         cmd_gmt,                },          // 时区设置

    {"STATUS",      cmd_status,             },          //
#if defined (__SAME_GT02__)
    {"PARAM",      gt02_param,              },          //
    {"DSERVER",      cmd_dserver,           },          //
    {"DSERVER2",      cmd_dserver,          },          //
#else
    {"PARAM",       cmd_param,              },          //
#endif /* __SAME_GT02__ */

#if defined (__SAME_GT02__)
    {"SCXSZ",       gt02_scxsz,             },          //
#else
    {"SCXSZ",       cmd_scxsz,              },          //
#endif /* __SAME_GT02__ */

    {"GPRSSET",     cmd_gprsset,            },          //
    {"LEVEL",       cmd_level,              },          //
    {"FACTORY",     cmd_factory,            },          //
    {"FACTORYALL",  cmd_factory_all,        },          //
#if!(defined(__SAME_GT02__)||defined(__NF2318__))
    {"SOS",         cmd_sos,                },          // 三组SOS号码设置
    {"ALMREP",      cmd_almrep,             },          // 设置接收报警号码（除SOS报警）
#endif
#if defined(__GT370__) || defined (__GT380__)||defined(__GT300S__)
    {"SEESOS",      cmd_see_sos,      		},          // 在线查看SOS号码
#endif
#if !defined(__NF2318__)
    {"PERMIT",      cmd_permit,             },          // 中心号码与邋SOS号码权限分配
#if !(defined(__GT300S__)|| defined(__GT370__)|| defined (__GT380__))
    {"SOSPERMIT",   cmd_sospermit,          },          // 参数的查询设置权限，报警的发送号码个数
#endif
    {"PWDSW",       cmd_pwdsw,              },          //
    {"PASSWORD",    cmd_password,           },          //
    {"RECOVER",     cmd_recover,            },          //
#endif
    //{"SPWD",        cmd_spwd,               },          //

#if defined(__ALM_SOS__)
    {"SOSALM",      cmd_sosalm,             },          // SOS 开/关 模式 设置
#endif /* __ALM_SOS__ */
#if !defined(__NF2318__)
    {"DELAY",       cmd_delay,              },          // 延时监听
#endif
    {"MONPERMIT",   cmd_monpermit,          },          // 监听权限控制
#if !(defined(__GT740__)|| defined(__GT370__)|| defined(__GT380__) || defined(__NF2318__))
    {"HFYD",        cmd_hdyd,               },          // 恢复油电（旧指令，因为网络指令用，暂不能移除）
#endif

#if defined(__GFENCE__)
    {"GFENCE",      cmd_gfence,             },          // 电子围栏设置
#elif defined(__FENCE__)
    {"FENCE",       cmd_fence,              },          // 电子围栏设置
    {"SEEFENCE",    cmd_fence,              },          // 电子围栏设置
#endif
    {"SPEED",       cmd_speed,              },          // 超速提醒设置
    {"POWERALM",    cmd_poweralm,           },          // 断电报警设置
    {"BATALM",      cmd_batalm,             },          // 低电报警设置
    {"SENALM",      cmd_senalm,             },          // 震动报警设置

//两者功能一致，仅参数3单位不同 chengjun
    {"SENSOR",      cmd_sensor,             },          // 震动设置
    {"SENSOR2",      cmd_sensor2,           },          // 震动设置


    {"GPRSON",      cmd_gprson,             },          //
    {"LINK",        cmd_link,               },          //
    {"HBT",         cmd_hbt,                },          // 心跳包设置间隔
#if defined(__NT36__)
    {"REPORT",      cmd_report,             },          // GPS 数据发送模式选择
#endif

    {"DEFENSE2",     cmd_defense2,},          // 延时设防设置
    {"DEFENSE",     cmd_defense,},            // 延时设防设置，功能一样，设置时间单位不同

    {"TIMER",       cmd_timer,              },          // GPS 数据上传间隔

    {"DISTANCE",    cmd_distance,           },          // GPS 数据定距上传
    {"ANGLEREP",    cmd_anglerep,           },          // 拐点补传设置
    {"ACCREP",      cmd_accrep,             },          // ACC 状态变化补传
    {"BATCH",       cmd_batch,              },          // GPS 数据打包发送设置
    {"SENDS",       cmd_sends,              },          // SENSOR 控制 GPS 时间
#if !(defined(__GT300S__)|| defined(__GT370__)|| defined (__GT380__)||defined (__NT33__))
    {"DSRESET",     cmd_dsreset,            },          // 重置设防状态指令
#endif
    {"CLEAR",       cmd_clear,              },          // 备份数据清除指令

    {"SF",          cmd_sf,                 },          // 静态数据过滤开关
    {"GPSON",		cmd_gpson,				},

#if defined(__NT36__)||defined(__GT370__)|| defined (__GT380__)
    {"EPH",         cmd_eph,                },          //
#endif
    {"CALL",        cmd_call,               },          // 电话重拨次数

    //{"PARK",        cmd_park,               },          // 停车超时提醒设置
    //{"FDT",         cmd_fdt,                },          // 疲劳驾驶报警设置
    {"SENSORSET",   cmd_sensorset,          },          // 设置触发震动报警条件
    {"GPRSALM",     cmd_gprsalm,            },          //
    {"STATICREP",   cmd_staticrep,          },          // SENSOR 检测静止上报最后位置开关指令
    {"FW",          cmd_fw,                 },          // 平台或SMS 短信透传短信内容

#if defined(__ALM_BOOT__)
    //{"PWRONALM",    cmd_PWRONALM,            },          //开机报警设置
    //{"PWROFFALM",   cmd_PWROFFALM,          },          //关机报警设置
#endif


#if defined(__ACC_ALARM__)
    {"ACCALM",      cmd_accalm,    },
#endif
    {"BLINDALM",    cmd_BLINDALM,           },          // GPS盲区

    /*********************************************************************************************/
    /*ADC4检测特有的指令       --    chengjun  2017-07-12*/
#if defined(__EXT_VBAT_ADC__)
    {"EBAT",        cmd_ebat,               },
    {"EXBATALM",    cmd_extbatalm,          },          // 外部电源低电报警
    {"EXBATCUT",    cmd_extbatcut,          },          // 外部低电保护电压提醒
    {"EXBAT",       cmd_exbat,              },
    {"ADC_BC",      cmd_adc_bc,    },          // ADC补偿值
    {"ADT",       cmd_adt,                  },
#endif
    /*********************************************************************************************/

    /*********************************************************************************************/
    /*车载设备特有的指令       --    chengjun  2017-07-12*/
#if defined (__TRACK_CAR_DEVICE__) && !defined(__NF2318__)
#if defined(__GERMANY__)
    {"STOP",       cmd_relay,              },          // 断油电
    {"AUSGANG",       cmd_ausgang,              },          // 断油电
#endif
#if defined(__SPANISH__)
    {"APAGAR",       cmd_spanish_relay,              },          // =RELAY,1#
    {"ENCENDER",       cmd_spanish_relay,              },          // =RELAY,0#
#endif
#if defined(__MEX__)
    {"SRELAY",       cmd_relay,              },          // 断油电
#endif

    //{"RELAY",       cmd_relay,              },          // 断油电
    //{"DYD",         cmd_dyd,                },          // 断油电（旧指令，因为网络指令用，暂不能移除）
    //{"PRELAY",      cmd_prelay,             },          // 国贸定制需求，无条件断油电
    //{"FRELAY",       cmd_frelay,              },          // 断油电
    {"MOVING",      cmd_moving,             },          // 位移报警设置
#endif /* __TRACK_CAR_DEVICE__ */

#if defined(__NF2318__)
#else
#if defined (__TRACK_CAR_DEVICE__)
    {"DOOR",       cmd_DOOR,                 },//边门检测
    {"FIND",       cmd_FIND,                 },//声光寻车
    {"DOORALM",    cmd_dooralm,              },//边门检测
#endif /* __TRACK_CAR_DEVICE__ */
#endif

    {"CENTER",      cmd_center,             },          // 中心号码设置

    /*********************************************************************************************/

    {"111",         cmd_DefenseOn,          },          //
    {"000",         cmd_DefenseOff,         },          //
#if !defined(__NO_MIC__)
    {"JT",          cmd_JT,    },          //
    {"MONITOR",     cmd_JT,                 },          //
    //{"SLEEPSET",    cmd_SLEEPSET,           },          //
#endif
    {"WN",          cmd_wn,                 },

#if defined (__BLE_GATT__)
    {"BCM",    cmd_btaddr,             	},     //蓝牙地址
#endif

#if defined(__GT300S__)
    {"REMSET",		 cmd_remset,},
#elif defined (__GT370__)|| defined (__GT380__)
    {"TRACKTIME",    cmd_tracktime,         },
    {"REMALMF",      cmd_remalmf          },
#endif /* __GT300S__ */

#if defined(__GT740__)||defined(__GT300S__)||defined (__GT370__)|| defined (__GT380__)
    {"MODE",        cmd_mode    },          //
    {"QUERY",       cmd_mode_view,          },          //
    {"EXTCHIP",     cmd_extchip             },  //单片机数据透传发
    {"TEARDOWN",      cmd_teardown          },  //摘除报警
    {"REMALM",        cmd_teardown          },  //摘除报警
#if defined(__GT740__)
    {"TRACKTIME",	  cmd_tracktime 		},
    {"RESETPRO",		cmd_RESETPRO,	 },
    {"AMSLOG",		  cmd_amslog,	 },
    {"GPSDUP",		  cmd_gpsup,	},
    {"RESETBAT",	   cmd_RESETBAT,		  },		  //
    {"RESETBATDIS", 	  cmd_RESETBATDIS,			},			//
    {"GPSWAKE",          cmd_gpswakeup,            },
#endif
#elif defined(__NF2318__)

#else
    {"MODE",        cmd_work_mode_set,      },          //
#endif /* __GT740__ */

    //{"LBS",         cmd_lbs,                },

    //{"LBSON",       cmd_lbson,              },

    {"SEEGFENCE",   cmd_seefence,           },

    {"DIAL",        cmd_dial,               },          // 先能网络拨打电话

    {"UART2TC",     cmd_Uart2_PassThrough   },          // UART2 透传

    //{"MILEAGE",     cmd_mileage,            },          // 里程设置指令

    {"TQL",         cmd_tql,                },
    {"HST",         cmd_hst,                },          // 电动车限速阀值
    {"_SYS",        cmd_sys,                },
    {"RENEW",       cmd_RENEW,              },
    //{"SIMALM",      cmd_simalm,             },          // 换卡报警
    //{"CLEARSIM",    cmd_clearsim,           },          // 清除换卡报警
    {"PWRLIMIT",    cmd_pwrlimit,           },          // 限制关机
    {"ALMSMS",      cmd_almsms,             },          // 短信报警设置
#if defined(__NF2318__)
	{"CLEARSIM",	cmd_smsclear,			},			// 清空短信箱
#else
    {"SMSCLEAR",    cmd_smsclear,           },          // 清空短信箱
#endif
    {"BALANCE",     cmd_balance,            },          // USSD String

#if defined (__SAME_GT02__)
    {"SYS_VERSION", cmd_SYS_VERSION,        },          //VERSION
#endif /* __SAME_GT02__ */
#if !defined(__NF2318__)
    {"CANCEL",   cmd_cancel,                },//撤销拆卸报警
#endif
    {"MSERVER",     cms_mserver,             },
    {"MSERVER1",    cmd_mserveri,             },
    {"MSERVER2",     cmd_mserveri,             },
    {"MSERVER3",     cmd_mserveri,             },
    {"MSERVER4",     cmd_mserveri,             },

#if defined __CUSTOM_WIFI_FEATURES_SWITCH__
    {"WIFI_CMD",       cms_wificmd,              },
#endif

#if defined (__WIFI__)
    {"WF",        cmd_WF,              },
    {"WIFION",        cmd_WIFION,              },
    {"FT",        cmd_FT,              },
#endif /* __WIFI__ */

    {"CHECK",        cmd_check,              },

#if defined(__FLY_MODE__) && !defined(__MT200__)
    {"FLYCUT",      cmd_flycut,             },
#endif
    {"DWDEPO", cmd_dwdepo,                },
#if defined(__NT36__)||defined (__NT33__) || defined(__NF2318__)
    {"BAT",       cmd_bat,},
#endif
	{"VBAT",	  cmd_bat,},

    {"UP_PARAM",       cmd_up_param,},

    {"SNCOVERY",      cmd_sncovery,             },          // server3设置


#ifdef __NT31__
    {"CLEARALM",      cmd_clearalm,             },
#endif /* __NT31__ */

#if defined (__NOFIX_GPSDUP__)
    {"GPSDUP",    cmd_gpsdup,       },      //GPS数据补传
#endif

#if defined (__NT33__)|| defined (__NT31__)
#if defined (__CUST_BT__)
    {"BLE",         cmd_ble,       },      //蓝牙
#endif /* __CUST_BT__ */
#endif

#if defined (__CUST_FAKECELL__)
    {"FAKECELL",    cmd_fakecell,   },      //防伪基站使能
    {"FAKEBS",    cmd_fakebs,       },      //防伪基站功能使能开关，功能同FAKECELL，但是不需要密码
    {"FCFALM",    cmd_fcfalm,       },      //防伪基站报警
#endif /* __CUST_FAKECELL__ */

#ifdef __GT300S__
    {"LJDW",    cmd_ljdw,       },
#endif /* __GT300S__ */

#if defined(__BACKUP_SERVER__)
    {"BSERVER",      cmd_Bserver,             },          //
    {"BSCLEAR",      cmd_BsClear,             },          //清空副域名
#endif
#if defined(__SPANISH__)
    {"SOSBT",      cmd_sosbt,             },
    {"ESOS",      cmd_esos,             },
    {"ITP",      cmd_itp,             },
#endif
    {"SV",          cmd_sv,                 },
    {"CXSV",        cmd_cxsv,               },
    {"NBVER",        cmd_nbver,               },
#if defined(__OBD__)
	{"OBDTC",		cmd_OBD_PassThrough_mode	},			// OBD 透传
	{"OBDCMD",		cmd_OBD_cmd,			},			// OBD 透传
#endif /* __OBD__ */
	//{"NFMSG",   cmd_test_msg_con,  },
    {" ", NULL}
};

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
void track_cmd_set_attr()
{
	rspcount = 0;
	rsplen = 0;
	memset(setdata, 0, 640);
	memset(querydata, 0, 640);
}
U8 track_get_setcmd_state(void)//是否在设置参数
{
	LOGD(L_APP, 1, "%d,%d", track_cust_setcmd(),rspcount);
	if((track_cust_setcmd() > 0) || (rspcount > 0))
	{
		return 1;
	}
	return 0;
}
void cmd_set_important_param()
{
	//Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
	Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
}

void track_cust_cmd_reply(cmd_return_struct * return_sms, char * data, int len)
{
	static U8 ImportantParam = 0;
	U8 TempCount = 0;
    LOGD(L_APP, L_V6, "len:%d", len);
    if(return_sms->reply_character_encode == 0)
    {
        len = strlen(data);
        LOGD(L_APP, L_V6, "len:%d", len);
        if(len > 0)
        {
            if(return_sms->cm_type == CM_SMS)
            {
                track_cust_sms_send(return_sms->num_type, return_sms->ph_num, KAL_TRUE, data, len);
            }
            else if(return_sms->cm_type == CM_ONLINE)
            {
                track_cust_paket_msg_upload(return_sms->stamp, KAL_TRUE, data, len);
            }
            else if(return_sms->cm_type == CM_ONLINE2)
            {
                track_cust_paket_FD_cmd(return_sms->stamp, KAL_TRUE, data, len);
            }
#if defined(__NF2318__)
			else if(return_sms->cm_type == CMD_ONLINE_NF2318)
			{
				if(return_sms->stamp[0] == 0x07 && return_sms->stamp[3] == 0x01)
				{
					LOGD(L_BMS, L_V1, "%d,%d,%d,%s",rspcount,rsplen,track_cust_querycmd(),data);
					if(rspcount == 0)
					{
						rsplen = snprintf(querydata,640,"%s;",data);
						rspcount = 1;
					}else
					{
						rsplen += sprintf(querydata+rsplen,"%s;",data);
						rspcount ++;
						if(rsplen>=460)//500-32
						{
							rsplen = rsplen - (len+1);
							//rspcount = track_cust_querycmd();
							LOGD(L_BMS, L_V1, "Too lang query command！！！！！");
						}
					}
					if(254 == track_cust_querycmd())//(rspcount == track_cust_querycmd())
					{
						rspcount = 0;
						LOGD(L_BMS, L_V1, "%d,%s",rsplen,querydata);
						track_cust_N07_paket_87(querydata, rsplen);
						memset(querydata, 0, 640);
						rsplen = 0;
						track_cust_set_query_count();//计数清零
					}
				}
				else if(return_sms->stamp[0] == 0x07 && return_sms->stamp[3] == 0x02)
				{
					//track_cust_no7_paket_88(data, len);
					if(strstr(data, "DOMAIN=OK"))// || strstr(data, "DEVICESN")
					{
						ImportantParam = 1;
						LOGD(1, 1, "important param set:%d",ImportantParam);
					}
					LOGD(L_BMS, L_V1, "%d,%d,%d,%s",rspcount,rsplen,track_cust_setcmd(),data);
					if(rspcount == 0)
					{
						rsplen = snprintf(setdata,640,"%s;",data);
						rspcount = 1;
					}else
					{
						rsplen += sprintf(setdata+rsplen,"%s;",data);
						rspcount ++;
						if(rsplen>=465)//500-32
						{
							rsplen = rsplen - (len+1);
							//rspcount = track_cust_setcmd();
							LOGD(L_BMS, L_V1, "Too lang set command！！！！！");
						}
					}
					if(254 == track_cust_setcmd())//(rspcount == track_cust_querycmd())
					{
						TempCount = rspcount;
						rspcount = 0;
						LOGD(L_BMS, L_V1, "%d,%s",rsplen,setdata);
						track_cust_no7_paket_88(setdata, rsplen);
						memset(setdata, 0, 640);
						rsplen = 0;
						track_cust_set_count();
						if(ImportantParam)
						{
							ImportantParam = 0;
							Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
							if(TempCount > 1)
							{
								tr_start_timer(TRACK_CUST_SET_PARAMS_TIMER_ID, 3000, cmd_set_important_param);
							}
						}
						else
						{
							cmd_set_important_param();
						}
						#if 0
						if(TempCount > 1 || (TempCount == 1 && ImportantParam == 0))
						{
							Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
						}
						if(ImportantParam)
						{
							ImportantParam = 0;
							if(TempCount == 1)
								cmd_set_important_param();
							else
							tr_start_timer(TRACK_CUST_SET_PARAMS_TIMER_ID, 3000, cmd_set_important_param);
						}
						#endif
					}
					if(track_is_timer_run(GPRS_SOCKET_INIT_TIMER_ID))
					{
						track_start_timer(GPRS_SOCKET_INIT_TIMER_ID, 5000, track_soc_gprs_reconnect, (void*)4);
					}
				}
			}
			/*
			else
			{
				track_cmd_set_attr();
			}*/
#endif
        }
        LOGS("%s", data);
    }
    else// if(return_sms->reply_character_encode == 1)
    {
        if(return_sms->cm_type == CM_SMS && len > 0)
        {
            track_cust_sms_send(return_sms->num_type, return_sms->ph_num, KAL_FALSE, data, len);
        }
        else if(return_sms->cm_type == CM_AT && len > 0)
        {
            LOGS("%s", data);
        }
        else if(return_sms->cm_type == CM_ONLINE && len > 0)
        {
            track_cust_paket_msg_upload(return_sms->stamp, KAL_FALSE, data, len);
        }
        else if(return_sms->cm_type == CM_ONLINE2 && len > 0)
        {
            track_cust_paket_FD_cmd(return_sms->stamp, KAL_FALSE, data, len);
        }
    }
}

kal_bool track_cust_cmd(CMD_DATA_STRUCT * cmd)
{
    int i, size, ret;
    kal_bool find = KAL_FALSE, pass_status = KAL_FALSE;
    size = sizeof(cust_recv_table) / sizeof(cust_recv_struct);
    LOGD(L_APP, L_V6, "num_type:%d, len:%d, data:%s   [%d/%d]%s|%s|%s|%s|%s",
         cmd->return_sms.num_type, cmd->rcv_length, cmd->rcv_msg_source, cmd->part, size, cmd->pars[0], cmd->pars[1], cmd->pars[2], cmd->pars[3], cmd->pars[4]);

    if(cmd->rcv_length >= 1024)
    {
        return KAL_TRUE;
    }

    for(i = 0; i < size; i++)
    {
        ret = strcmp(cmd->pars[0], cust_recv_table[i].cmd_string);
        LOGD(L_APP, L_V9, "ret=%d|%s,%s|%p", ret, cmd->pars[0], cust_recv_table[i].cmd_string, cust_recv_table[i].cmd_string);
        if(!ret)
        {
            find = KAL_TRUE;
            cmd->rsp_length = 0;
            memset(cmd->rsp_msg, 0, sizeof(cmd->rsp_msg));
            track_is_sms_cmd(1);
            pass_status = track_cmd_check_authentication(cmd);
            if(cmd->supercmd == 1 || cmd->return_sms.cm_type != CM_SMS || pass_status)
            {
                if(cust_recv_table[i].func_ptr != NULL)
                {
                    track_is_recv_cmd_after_boot(1);
                    cust_recv_table[i].func_ptr(cmd);
                    break;
                }
            }
            else
            {
                LOGD(L_APP, L_V4, "Password error!");
                sprintf(cmd->rsp_msg, "Password error!");      //密码错误
            }
            break;
        }
    }
#if defined(__NF2318__)
	if(cmd->return_sms.cm_type == CMD_ONLINE_NF2318 && find == KAL_FALSE)
	{
		LOGD(L_APP, L_V5, "==online invalid==");
		sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
		find = KAL_TRUE;
	}
#endif
    if(find)
    {
        /*  指令解析执行体只填充信息，全部在此发出*/
        track_cust_cmd_reply(&cmd->return_sms, cmd->rsp_msg, cmd->rsp_length);
    }
    else
    {
        LOGD(L_APP, L_V5, "invalid command!");
    }
    return KAL_TRUE;        // 执行操作后删除短信
}

/******************************************************************************
 *  Function    -  track_execute_cust_cmd
 *
 *  Purpose     -  回复权限错误
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 11-10-2014,  ZengPing && Liujunwu  written
 * ----------------------------------------
 ******************************************************************************/
void track_execute_cust_cmd(CMD_DATA_STRUCT * gps_cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    int i, size, ret;
    kal_bool find = KAL_FALSE;
    struct_msg_send g_msg = {0};
    kal_bool isChar = KAL_TRUE;
    char *data;
    int len;
    static char *str_cmd_error_en = "Error: Not authorized!";
    static char str_cmd_error_cn[18] =
    {
        0x95, 0x19, 0x8B, 0xEF, 0xFF, 0x01, 0x97, 0x5E, 0x63, 0x88, 0x67, 0x43, 0x53, 0xF7, 0x78, 0x01, 0xFF, 0x01
    };
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LOGD(L_APP, L_V5, "%d,%d,%s", gps_cmd->return_sms.cm_type, gps_cmd->rcv_length, gps_cmd->pars[CM_Main]);
    size = sizeof(cust_recv_table) / sizeof(cust_recv_struct);
    for(index = 0; index < size; index++)
    {
        if(!strcmp((S8*)cust_recv_table[index].cmd_string, gps_cmd->pars[CM_Main]))
        {
            find = TRUE;
            break;
        }
    }
    if(find)
    {

        snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, str_cmd_error_en);
        g_msg.msg_cn_len = 18;
        memcpy(g_msg.msg_cn, str_cmd_error_cn, g_msg.msg_cn_len);
        if(G_parameter.lang == 1)
        {
            isChar = KAL_FALSE;
            len = g_msg.msg_cn_len;
            data = g_msg.msg_cn;
        }
        else
        {
            isChar = KAL_TRUE;
            len = strlen(g_msg.msg_en);
            data = g_msg.msg_en;
        }
        if(g_msg.msg_cn_len)
        {
            /*  指令解析执行体只填充信息，全部在此发出*/
            if(gps_cmd->return_sms.cm_type == CM_SMS)
            {
                //track_cmd_sms_rsp(cmd);
                track_cust_sms_send(gps_cmd->return_sms.num_type, gps_cmd->return_sms.ph_num, isChar, data, len);
            }
            else if(gps_cmd->return_sms.cm_type == CM_ONLINE)
            {
                track_cust_paket_msg_upload(gps_cmd->return_sms.stamp, isChar, data, len);
            }
            else if(gps_cmd->return_sms.cm_type == CM_ONLINE2)
            {
                track_cust_paket_FD_cmd(gps_cmd->return_sms.stamp, isChar, data, len);
            }
            else
            {
                LOGS("%s", g_msg.msg_en);
            }
        }
    }
}
void track_cmd_xcws_factory(void)
{
    CMD_DATA_STRUCT cmd = {0};
    cmd_factory(&cmd);
}

