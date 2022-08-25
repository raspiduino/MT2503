/*******************************************************************************************
 * Filename:
 * Author :
 * Date :
 * Comment:
 ******************************************************************************************/

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "Conversions.h"
#include "l4c2smsal_struct.h"

#include "track_cust.h"
#include "track_cust_main.h"
#include "track_at_call.h"
#include "track_at_sim.h"
#include "track_os_ell.h"
#include "track_version.h"

#include "l4c_common_enum.h"
#include "gps_struct.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/
#define PI    3.14159265358979
#define T_PI  0.01745329251994    /* PI/180.0 */
#define EARTH_RAD 6378.1370       /* 取WGS84标准参考椭球中的地球长半径(单位:km) */
#define MAX_STATIC_DIFFDATA	  0.03


/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/
#if defined(__GT300S__) || defined(__GT370__)|| defined (__GT380__)
kal_bool g_GT03D = KAL_TRUE;
#else
kal_bool g_GT03D = KAL_FALSE;
#endif
/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern void track_testmode_eint_handler(U8 eint, U8 level);
extern void track_TM_autotest_call_status_change(kal_uint16 callType, kal_uint16 callState);
extern void track_soc_clear_dw_queue(void);
extern void track_cust_key_led_sleep(void);
extern void acc_status_change(void *arg);
extern void track_cust_molude_simalarm_sms(void);
extern kal_int8 strtoime(const char *data, const char *time, applib_time_struct *t);
extern void track_drv_lte_reset_pwron(void* op);
extern void track_cust_intermittent_send_LBS(void *arg);
extern void track_cust_module_sw_init(void);

extern kal_bool track_drv_nvram_write_switch(kal_uint8 sw);

#if defined (__MCU_SW_UPDATE__)
extern kal_uint8* track_get_mcu_sw_version(void);
#endif /* __MCU_SW_UPDATE__ */
#if defined(__OBD__)
extern char *track_obd_get_version(void);
#endif
#if defined(__NF2318__)
extern void track_cust_N07_sms_relay(track_sms_param *sms_rev);
extern void track_cust_str_to_hex();
extern void track_cust_is_chargein_poweron(void* arg);
#endif
extern void track_sms_clean_all_sms_by_timing();

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/

/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/
/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
static kal_bool sendmessage = KAL_FALSE;
/*****************************************/
/*    OS -> APP                          */
/*****************************************/
/******************************************************************************
 *  Function    -  track_translate_gsm_4level
 *
 *  Purpose     -  GSM信号强度由[0-32]转换为4级
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
int track_translate_gsm_4level(int qdbm)
{
    int level = 0;
    if(qdbm == 99)
    {
        level = 0;
    }
    else
    {
        level = qdbm / 8;
    }
    return level;
}
/******************************************************************************
 *  Function    -  track_cust_get_rssi
 *
 *  Purpose     -  GSM信号强度上报函数
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
int track_cust_get_rssi(int arg)
{
    static int cur_rssi = 99;
    if(arg != -1)
    {
        if(arg <= 15)
        {
            LOGD(L_APP, L_V1, "请检查GSM天线，信号偏弱 %d -> %d", cur_rssi, arg);
        }
        cur_rssi = arg;
    }
    else
    {
        LOGD(L_CMD, L_V9, "cur_rssi:%d, %d", cur_rssi, arg);
    }

    return cur_rssi;
}

/******************************************************************************
 *  Function    -  track_cust_get_rssi_level
 *
 *  Purpose     -  对GSM信号强度分等级
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
int track_cust_get_rssi_level(void)
{
    int tmp, ret;
    tmp = track_cust_get_rssi(-1);
    LOGD(L_APP, L_V6, "rssi=%d", tmp);
    if(tmp == 99)
        ret = 0;//返回-1会影响效果，返回0
#if defined(__NF2318__)
	else if(tmp == 0)
		ret = 0;
	else if(tmp <= 3)
		ret = 1;
	else if(tmp <= 6)
		ret = 2;
	else if(tmp <= 9)
		ret = 3;
	else if(tmp <= 12)
		ret = 4;
	else if(tmp <= 17)
		ret = 5;
	else if(tmp <= 21)
		ret = 6;
	else if(tmp <= 24)
		ret = 7;
	else if(tmp <= 28)
		ret = 8;
	else
		ret = 9;
#else
    else if(tmp == 0)
        ret = 0;
    else if(tmp <= 9)
        ret = 1;
    else if(tmp <= 12)
        ret = 2;
    else if(tmp <= 15)
        ret = 3;
    else
        ret = 4;
#endif
    return ret;
}

/******************************************************************************
 *  Function    -  track_cust_at_simulation_online_cmd
 *
 *  Purpose     -  在线指令处理（暂时未从这里处理）
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_at_simulation_online_cmd(U8* data, int len, kal_uint32 no)
{
    LOGD(L_APP, L_V5, "not support!");
}
/******************************************************************************
 *  Function    -  track_cust_at_cmd
 *
 *  Purpose     -  AT指令串口函数
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_bool track_cust_at_cmd(CMD_DATA_STRUCT *cmd)
{
    return track_cust_cmd(cmd);
}
kal_uint8 track_is_sms_cmd(kal_uint8 status)
{
    static kal_uint8 cmd_status = 0;
    if(status == 99)
    {
        return cmd_status;
    }
    cmd_status = status;
}
kal_bool track_cust_message_status()
{
    return sendmessage;
}
/******************************************************************************
 *  Function    -  track_app_receive_sms
 *
 *  Purpose     -  对接收到的短信进行号码处理
 *
 *  Description -
 *                 识别飞信来源
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_app_receive_sms(track_sms_param *sms_rev)
{
	kal_bool findStr = KAL_FALSE;
	int headTYpe = 0;
    char *p = NULL;
    CMD_DATA_STRUCT sms_cmd = {0};

    if(sms_rev == NULL)
    {
        return;
    }
    sms_cmd.return_sms.cm_type = CM_SMS;
    sms_cmd.return_sms.num_type = sms_rev->P_TYPE;
    track_is_sms_cmd(0);
    memcpy(&sms_cmd.return_sms.ph_num[0], sms_rev->TPA, sms_rev->ODAL);
    /*at指令不大于90*/
    if(sms_rev->TP_DCS == GSM_7BIT || sms_rev->TP_DCS == GSM_8BIT)
    {
    	kal_uint8 *start = NULL, *end = NULL;
        LOGD(L_CMD, L_V5, "TYPE:%d, TP_DCS:%d, TP_UDL:%d, CTX:%s, NUM:%s", sms_rev->P_TYPE, sms_rev->TP_DCS, sms_rev->TP_UDL, sms_rev->TP_UD, sms_rev->TPA);
        if(strstr(sms_rev->TPA, "12520")) //飞信号码
        {
            p = strstr(sms_rev->TP_UD, ": ");
        }

        if(p)
        {
            p += 2;
			start = strstr(p, "$");
			if(start != NULL)
			{
				end = strstr(start+1, "$");
			}
			if(end != NULL)
			{	
				findStr = KAL_TRUE;
				sms_cmd.rcv_length = end - start;
				memcpy(sms_cmd.rcv_msg, start, sms_cmd.rcv_length);
			}
			else
			{
            	sms_cmd.rcv_length = sms_rev->TP_UDL - (p  - sms_rev->TP_UD);
				memcpy(sms_cmd.rcv_msg, p, sms_cmd.rcv_length);
			}
        }
        else
        {
        	start = strstr(sms_rev->TP_UD, "$");
			if(start != NULL)
			{
				end = strstr(start + 1, "$");
			}
			if(end != NULL)
			{	
				findStr = KAL_TRUE;
				sms_cmd.rcv_length = end - start;
            	memcpy(sms_cmd.rcv_msg, start, sms_rev->TP_UDL);
			}
			else
			{
            	sms_cmd.rcv_length = sms_rev->TP_UDL;
            	memcpy(sms_cmd.rcv_msg, sms_rev->TP_UD, sms_rev->TP_UDL);
			}
        }
        LOGD(L_APP, L_V5, "%d:cmd:%s,num:%s", sms_cmd.rcv_length, sms_cmd.rcv_msg, sms_cmd.return_sms.ph_num);
    }
    else if(sms_rev->TP_DCS == GSM_UCS2)
    {
        kal_uint8 wchr3[2] = {0xFF, 0x0C};  // ，
        kal_uint8 wchr4[2] = {0x00, 0x2C};  // ,
        kal_uint8 wchr5[2] = {0xFF, 0x03};  // ＃
        kal_uint8 wchr6[2] = {0x00, 0x23};  // #
        kal_uint8 wchr7[2] = {0x00, 0x5D};	//]
        kal_uint8 wchr8[2] = {0x30, 0x11};	//】
        kal_uint8 wchr9[2] = {0x00, 0x24};	//$
        kal_uint8 *start, *end;
        LOGD(L_APP, L_V4, "来短信(%d,%d):%s", sms_rev->P_TYPE, sms_rev->TP_UDL, sms_rev->TPA);
        LOGH(L_APP, L_V6, sms_rev->TP_UD, sms_rev->TP_UDL);
        track_fun_str_replace_chr(wchr3, wchr4, sms_rev->TP_UD, sms_rev->TP_UDL);
        track_fun_str_replace_chr(wchr5, wchr6, sms_rev->TP_UD, sms_rev->TP_UDL);
        //track_fun_str_replace_chr(wchr8, wchr7, sms_rev->TP_UD, sms_rev->TP_UDL);
        if(strstr(sms_rev->TPA, "12520") == sms_rev->TPA)   //飞信号码
        {
            kal_uint8 wchr1[2] = {0x00, 0x3A};  // :
            kal_uint8 wchr2[2] = {0x00, 0x23};  // #
            start = track_fun_strWchr(wchr1, sms_rev->TP_UD, sms_rev->TP_UDL);
            if(start == NULL)
            {
                LOGD(L_APP, L_V5, "error 1");
                track_fun_view_UTF16BE_string(sms_rev->TP_UD, sms_rev->TP_UDL);
                start = (kal_uint8 *)sms_rev->TP_UD;
            }
            else
            {
                if(start[2] == 0x00 && start[3] == 0x20) start += 4;
                else start += 2;
            }
            end = track_fun_strWchr(wchr2, start, sms_rev->TP_UDL - (start - sms_rev->TP_UD));
            if(end == NULL)
            {
                track_fun_view_UTF16BE_string(sms_rev->TP_UD, sms_rev->TP_UDL);
                track_cust_fetion_auto_authorize(sms_rev); // 飞信自动授权，测试用
                track_cust_sms_relay(sms_rev);
				#if defined(__NF2318__)
				track_cust_N07_sms_relay(sms_rev);
				#endif
                return;
            }
            end += 2;
            LOGH(L_APP, L_V6, start, end - start);
            track_fun_UTF16BE_to_GB2312(start, end - start, sms_cmd.rcv_msg, CM_PARAM_LONG_LEN_MAX);
            sms_cmd.rcv_length = strlen(sms_cmd.rcv_msg);
            LOGH(L_APP, L_V6, sms_cmd.rcv_msg, CM_PARAM_LONG_LEN_MAX);
        }
        else
        {
        #if defined(__NF2318__)
		    kal_uint8 *starts = NULL;
			kal_uint8 *endss = NULL;
			kal_uint16 tempLen = 0; 
			int len = 0;
			endss = track_fun_strWchr(wchr9, sms_rev->TP_UD, sms_rev->TP_UDL);
			if(endss != NULL)
			{
				tempLen = (endss - sms_rev->TP_UD);
				starts = track_fun_strWchr(wchr9, sms_rev->TP_UD, tempLen);
				if(starts != NULL)
				{
					findStr = KAL_TRUE;
					len = endss - starts;
				}
			}
			if(len != 0)
			{
			    LOGD(L_APP, L_V6, "长度：%d", len);
				track_fun_UTF16BE_to_GB2312(starts, len, sms_cmd.rcv_msg, CM_PARAM_LONG_LEN_MAX);
			    sms_cmd.rcv_length = strlen(sms_cmd.rcv_msg);
            	LOGD(L_APP, L_V6, "长度：%d,%d", len,sms_cmd.rcv_length);
			}
			else
#if 0
			starts = track_fun_strWchr(wchr8, sms_rev->TP_UD, sms_rev->TP_UDL);
			if(starts != NULL)
			{
				len = sms_rev->TP_UDL - (starts - sms_rev->TP_UD) - 2;
            	LOGD(L_APP, L_V6, "长度：%d", len);
				track_fun_UTF16BE_to_GB2312(starts+2, len, sms_cmd.rcv_msg, CM_PARAM_LONG_LEN_MAX);
			    sms_cmd.rcv_length = strlen(sms_cmd.rcv_msg);
            	LOGD(L_APP, L_V6, "长度：%d,%d", len,sms_cmd.rcv_length);
			}
			else
#endif
		#endif
			{
            	track_fun_UTF16BE_to_GB2312(sms_rev->TP_UD, sms_rev->TP_UDL, sms_cmd.rcv_msg, CM_PARAM_LONG_LEN_MAX);
			    sms_cmd.rcv_length = strlen(sms_cmd.rcv_msg);
			}
            //LOGD(L_APP, L_V4, "发送短信内容：|%s|", sms_cmd.rcv_msg);
            LOGH(L_APP, L_V6, sms_cmd.rcv_msg, strlen(sms_cmd.rcv_msg));
        }
        sms_cmd.character_encode = 1;
    }
    else
    {
        LOGD(L_CMD, L_V5, "TP_DCS:%d, TP_UDL:%d, NUM:%s", sms_rev->TP_DCS, sms_rev->TP_UDL, sms_rev->TPA);
        LOGH(L_CMD, L_V5, sms_rev->TP_UD, sms_rev->TP_UDL);
    }
    if(sms_cmd.rcv_length)
    {
    	//在此区分是不是7号短信协议头
    	if(findStr)
    	{
    		headTYpe = track_cust_cmd_header(&sms_cmd);
    	}
    	if(headTYpe > 0 || !findStr)
        track_command_operate(&sms_cmd);
    }

    track_cust_sms_relay(sms_rev);
#if defined(__NF2318__)
	track_cust_N07_sms_relay(sms_rev);
#endif

}

/******************************************************************************
 *  Function    -  track_cust_gps_decode_done
 *
 *  Purpose     -  GPS数据接口
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_gps_decode_done(track_gps_data_struct *track_gps_data)
{
    track_gps_locate_data_receive(track_gps_data);
}

/******************************************************************************
 *  Function    -  track_cust_eint_trigger_response
 *
 *  Purpose     -  中断响应接口
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_eint_trigger_response(U8 eint, U8 level)
{
    if(track_is_testmode())
    {
        track_testmode_eint_handler(eint, level);
    }
    else
    {
        track_cust_status_eint_check_set(eint, level);
    }
}

/******************************************************************************
 *  Function    -  track_cust_chargestatus_vbtstatus_check
 *
 *  Purpose     -  电源状态信息上报
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_chargestatus_vbtstatus_check(pmic_status_enum status, battery_level_enum level, kal_uint32 volt)
{
    if(track_is_testmode())
    {
        LOGD(L_APP, L_V7, "status=%d, level=%d, volt=%d", status, level, volt);
    }
    else
    {
        track_cust_status_chargestatus_vbtstatus_check(status, level, volt);
    }
}

/******************************************************************************
 * FUNCTION:  - track_cust_call_status_change
 *
 * DESCRIPTION: - 电话状态切换
    switch (callState)
    {
        case TR_CALL_SETUP:  // 来电 /
            break;
        case TR_CALL_RING: //响铃/
            break;
        case TR_CALL_CONNECT:// 接通 /
            break;
        case TR_CALL_MT_BUSY://对方忙/
            break;
        case TR_CALL_NULL_NO://号码为空/
            break;
        case TR_CALL_DISCONNECT:  // 挂断 //
            break;
        default:
            break;
    }
 *
 * modification history
 * --------------------
 * v1.0  , 14-11-2012,  wangqi  written
 * --------------------
 ******************************************************************************/
void track_cust_call_status_change(void * msg)
{
    call_state_struct *ptr = (call_state_struct *) msg;
    kal_uint16 _type = ptr->type;/*call_type_enum*/
    kal_uint16 callState = ptr->status;/*track_call_state_enum*/
    LOGD(L_APP, L_V5, "type:%d,status:%d", ptr->type, ptr->status);

    if(track_is_testmode())
    {
        track_TM_call_status_change(_type, callState);
    }
    else
    {
        track_cust_sos_call_status(_type, callState);
    }
}

/******************************************************************************
 *  Function    -  track_cust_sos_and_center_permit
 *
 *  Purpose     -  SOS、中心号码的指令控制
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 20-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_bool track_cust_sos_and_center_permit(char *num)
{
    if(G_parameter.Permission.SOSPermit == 0)
    {
        LOGD(L_APP, L_V5, "1");
        return KAL_TRUE;
    }
    if(track_cust_sos_or_center_check(3, num) == 3)
    {
        LOGD(L_APP, L_V5, "2");
        return KAL_FALSE;
    }
    LOGD(L_APP, L_V5, "3");
    return KAL_TRUE;
}

/******************************************************************************
 *  Function    -  track_cust_password_sw
 *
 *  Purpose     -  指令密码控制函数
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_bool track_cust_password_sw(void)
{
    if(G_parameter.Permission.password_sw)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/******************************************************************************
 *  Function    -  track_cust_password_check
 *
 *  Purpose     -  指令密码检查函数
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_uint8 track_cust_password_check(char *password)
{
    kal_uint8 ret = 0;

    LOGD(L_CMD, L_V5, "%s,%s",password, G_parameter.Permission.password);
        
#if defined(__SAME_GT02__)
    if(!strcmp(password, G_parameter.Permission.superCmd))
    {
        ret |= 2;
    }
    else
#endif
    {
        if(!strcmp(password, G_parameter.Permission.password))
        {
            ret |= 1;
        }
    }
    return ret;
}

kal_bool track_cmd_super_cmd(CMD_DATA_STRUCT *command)
{
    char super_cmd[20] = {0};
    int len;

    len = strlen(command->pars[0]);
    if(len >= 20)
    {
        return KAL_FALSE;   // 验证超级指令头
    }
    memcpy(super_cmd, command->rcv_msg_source + (command->pars[0] - command->rcv_msg), len);
    if(!strcmp(super_cmd, G_parameter.Permission.superCmd))
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}
/******************************************************************************
 *  Function    -  track_app_sms_rsp
 *
 *  Purpose     -  短信发送回执
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_app_sms_rsp(sms_send_rsp_struct *rsps)
{
    LOGD(L_APP, L_V5, "短信发送反馈 index:%d,status:%d,result:%d,at:%d",
         rsps->index, rsps->status, rsps->result, track_get_vs_at_status());
}


/******************************************************************************
 *  Function    -  track_cust_agps_valid
 *
 *  Purpose     -  AGPS状态
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_bool track_cust_agps_valid(kal_uint8 par)
{
    if(par == 1)
    {
        return G_parameter.agps.sw;
    }
    else if(par == 2)
    {
        return G_parameter.agps.last_position_valid;
    }
}
static float track_fun_get_GPS_Points_distance(double lat1, double lon1, double lat2, double lon2)
{
    double radLat1, radLat2, aLat, aLon, s;
    float ret;
    LOGD(L_APP, L_V5, "%f,%f,%f,%f", lat1, lon1, lat2, lon2);

    radLat1 = lat1 * T_PI;
    radLat2 = lat2 * T_PI;

    aLat = radLat1 - radLat2;       //纬度之差
    aLon = (lon1 - lon2) * T_PI;    //经度之差

    s = 2 * asin(sqrt(pow(sin(aLat / 2), 2) + cos(radLat1) * cos(radLat2) * pow(sin(aLon / 2), 2)));
    s = s * EARTH_RAD * 1000;
    ret = s;
    return ret;
}
/******************************************************************************
 *  Function    -  track_cust_agps_get_last_position
 *
 *  Purpose     -  供AGPS使用的上一个定位点
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_agps_get_last_position(kal_uint8 type, mtk_param_epo_pos_cfg *epo_pos_cfg)
{
    static mtk_param_epo_pos_cfg epo_pos_cfg_from_lbs = {0};
    float  distance;
    track_gps_data_struct *gpsLastPoint = NULL;
    mtk_param_epo_pos_cfg epo_pos_cfg1;
    gpsLastPoint = track_cust_backup_gps_data(0, NULL);
    /*
    if(gpsLastPoint->gprmc.status != 0 && type==2)
    {
        memcpy(&epo_pos_cfg1, epo_pos_cfg, sizeof(mtk_param_epo_pos_cfg));
        LOGD(L_APP, L_V5, "%f,%f,%f,%f", epo_pos_cfg1.dfLAT,epo_pos_cfg1.dfLON, gpsLastPoint->gprmc.Latitude, gpsLastPoint->gprmc.Longitude);
        distance = track_fun_get_GPS_Points_distance(epo_pos_cfg1.dfALT,epo_pos_cfg1.dfLON, gpsLastPoint->gprmc.Latitude, gpsLastPoint->gprmc.Longitude);
        LOGD(L_APP, L_V5, "LBS与GPS距离相差=%f", distance);
    }
    */
    if(type == 1)
    {
        LOGD(L_APP, L_V5, "track_cust_backup_gps_data=%d", gpsLastPoint->gprmc.status);
        if(gpsLastPoint->gprmc.status != 0)
        {
            epo_pos_cfg->dfALT = gpsLastPoint->gpgga.msl_altitude;
            if(gpsLastPoint->gprmc.NS == 'S')
            {
                epo_pos_cfg->dfLAT = -gpsLastPoint->gprmc.Latitude;
            }
            else
            {
                epo_pos_cfg->dfLAT = gpsLastPoint->gprmc.Latitude;
            }
            if(gpsLastPoint->gprmc.EW == 'W')
            {
                epo_pos_cfg->dfLON = -gpsLastPoint->gprmc.Longitude;
            }
            else
            {
                epo_pos_cfg->dfLON = gpsLastPoint->gprmc.Longitude;
            }
            epo_pos_cfg->u2YEAR  = gpsLastPoint->gprmc.Date_Time.nYear;
            epo_pos_cfg->u1MONTH = gpsLastPoint->gprmc.Date_Time.nMonth;
            epo_pos_cfg->u1DAY = gpsLastPoint->gprmc.Date_Time.nDay;
            epo_pos_cfg->u1HOUR = gpsLastPoint->gprmc.Date_Time.nHour;
            epo_pos_cfg->u1MIN = gpsLastPoint->gprmc.Date_Time.nMin;
            epo_pos_cfg->u1SEC = gpsLastPoint->gprmc.Date_Time.nSec;
        }
        else
        {
            memcpy(epo_pos_cfg, &epo_pos_cfg_from_lbs, sizeof(mtk_param_epo_pos_cfg));
        }
    }
    else if(type == 2)
    {
        memcpy(&epo_pos_cfg_from_lbs, epo_pos_cfg, sizeof(mtk_param_epo_pos_cfg));
    }
}

/******************************************************************************
 *  Function    -  track_cust_epo_int
 *
 *  Purpose     -  epo_int是秒定注入必须执行函数，不然在拿到时间后并不会注入EPO
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 28-06-2016,  xzq  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_epo_int()
{
    static kal_uint8 epo_status = 0;
    applib_time_struct currTime = {0};
    applib_dt_get_rtc_time(&currTime);

    LOGD(L_GPS, L_V2, "%0.2d-%0.2d-%0.2d %0.2d:%0.2d:%0.2d   %d",
         currTime.nYear, currTime.nMonth, currTime.nDay,
         currTime.nHour, currTime.nMin, currTime.nSec, (*OTA_DEFAULT_HARDWARE_YEAR + 2000));
    if(currTime.nYear != (*OTA_DEFAULT_HARDWARE_YEAR + 2000) && epo_status == 0)
    {
        epo_status = 1;
        tr_stop_timer(TRACK_CUST_EPO_INT_TIMER_ID);
        if(G_parameter.agps.sw == 1)
        {
            ilm_struct *send_ilm;
            gps_assist_ind_struct *myMsgPtr = NULL;
            myMsgPtr = (gps_assist_ind_struct*) construct_local_para(sizeof(gps_assist_ind_struct), TD_RESET);
            myMsgPtr->account_id = Socket_get_account_id();
            track_fun_msg_send(MSG_ID_ENABLE_EPO_DOWNLOAD, myMsgPtr, MOD_MMI, MOD_GPS);// 防止开机开GPS时因为系统时间复位导致将EPO错误删除 xzq
            LOGD(L_GPS, L_V2, "秒定功能:EPO 初始化", myMsgPtr->account_id);
        }
    }
    else if(currTime.nYear == (*OTA_DEFAULT_HARDWARE_YEAR + 2000))
    {
        tr_start_timer(TRACK_CUST_EPO_INT_TIMER_ID, 5000, track_cust_epo_int);
    }
}

void track_cust_poweron_open_gps()
{
#if defined(__ET310__)
    static kal_bool def_tmp = 0;
    if(def_tmp == 0 && G_realtime_data.defense_mode == 1)   /* 手动设防模式 */
    {
        def_tmp = 1;
        if(G_realtime_data.defences_status >= 2 && !track_is_timer_run(TRACK_CUST_STATUS_DEFENCES_TIMER_ID))
        {
            track_os_intoTaskMsgQueueExt(track_cust_status_defences_change, (void *)2);
        }
    }
    track_cust_gps_work_req((void *)2);    // gps on
#elif defined(__GT300S__) || defined(__GT370__)|| defined (__GT380__)
    {
        //模式切换
        if(G_parameter.work_mode.sw == 1)
        {
            if(track_cust_get_work_mode() != WORK_MODE_2)
            {
#if defined(__GT300S__)
                track_drv_sensor_off();
#endif
                // gps on
                track_cust_gps_work_req((void *)13);
            }
            else
            {
                track_cust_gps_work_req((void *)2);
            }
            if(G_realtime_data.defences_status >= 2 && !track_is_timer_run(TRACK_CUST_STATUS_DEFENCES_TIMER_ID))
            {
                track_os_intoTaskMsgQueueExt(track_cust_status_defences_change, (void *)2);
            }
        }
        else
        {
            // gps on
            track_cust_gps_work_req((void *)2);
        }
    }

#else
    track_cust_gps_work_req((void *)2);    // gps on
#endif

}

/******************************************************************************
 *  Function    -  track_cust_eind
 *
 *  Purpose     -  EIND事件处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * v2.0  , 28-06-2016,   xzq  GPS开启函数放到 track_cust_poweron_open_gps
 * ----------------------------------------
*******************************************************************************/
void track_cust_eind(void)
{
    static kal_bool isFirst = KAL_TRUE;
    nvram_gps_time_zone_struct *zone_p;

    LOGD(L_APP, L_V5, "");
    if(isFirst)
    {
        isFirst = KAL_FALSE;
        track_cust_poweron_open_gps();
        track_cust_get_sim_status();
        if(track_is_timer_run(TRACK_QUERY_SIM_TYPE_TIMER_ID))
        {
            track_stop_timer(TRACK_QUERY_SIM_TYPE_TIMER_ID);
            track_drv_query_sim_type();
        }
        //track_sim_clean_allsms();//清空所有短信，IMEI备份的短信也将被删除
        track_read_imsi_data();
        //track_cust_check_simalm();//换卡报警
        if(track_cust_is_upload_UTC_time() && G_parameter.zone.timezone_auto)
        {
            zone_p = track_mcc_to_timezone();
            if(zone_p != NULL)
            {
                memcpy(&G_parameter.zone, zone_p, sizeof(nvram_gps_time_zone_struct));
            }
        }

#if defined (__GT370__)|| defined (__GT380__)
        track_cust_paket_8A();//放在登录包回复后面，开机报警包已经入队列，导致发出去非准确时间，必须先放队列
#endif /* __GT370__ */

        /* 延后开机自动检测备份参数至SIM卡的时间，避开工厂测试环节 */
        //track_cust_sim_backup_for_parameter();
        tr_start_timer(TRACK_CUST_SIM_BACKUP_PARAM_TIMER, 300000, track_cust_sim_backup_for_parameter);
        if(PWRKEYPWRON == mmi_Get_PowerOn_Type() || CHRPWRON == mmi_Get_PowerOn_Type())
        {
#if defined (__GT370__)|| defined (__GT380__)
            tr_start_timer(TRACK_CUST_bootalm_sms_TIMER, 60000, track_cust_alarm_boot);
//#else
            //tr_start_timer(TRACK_CUST_bootalm_sms_TIMER, 3000, track_cust_alarm_boot);
#endif /* __GT370__ */
        }
        else
        {
            LOGD(L_APP, L_V5, "mmi_Get_PowerOn_Type:%d", mmi_Get_PowerOn_Type());
        }
        tr_start_timer(TRACK_CUST_CLEAN_SMS_TIMER, 30 * 1000, track_sim_clean_allsms);//track_sim_clean_reveicebox
     
		tr_start_timer(TRACK_CUST_UNREAD_SMS_CHECK_TWO_TIMER_ID, 180*60*1000, track_sms_clean_all_sms_by_timing);
    }
}

/******************************************************************************
 *  Function    -  track_nw_attach_ind
 *
 *  Purpose     -  从系统L4层上报来的GSM网络搜索情况
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_nw_attach_ind(void *msg)
{
    track_soc_nw_attach_ind(msg);
}
/******************************************************************************
 *  Function    -  track_cust_init
 *
 *  Purpose     -  应用初始化主函数
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_init(void)
{
    tr_start_timer(TRACK_CUST_LED_START_TIMER, POWER_ON_LED_WORK_TIME_SEC * 1000, track_cust_led_first_start);

    LED_PWR_StatusSet(PW_NORMAL_STATE);    //增加电池灯

    LED_GSM_StatusSet(GSM_INITIAL_STATE);
	
	track_start_timer(TRACK_CUST_CHARGEIN_POWERON_OVERTIME_TIME_ID, 10*1000, track_cust_is_chargein_poweron, (void *)0);

    LOGD(L_APP, L_V4, "开机%d;%d", G_parameter.work_mode.sw, track_cust_get_work_mode());

    //Shock sensor
    track_cust_sensor_init();

    // 24小时周期性重启
    track_start_timer(TRACK_CUST_PERIODIC_RESTART_TIMER_ID, track_drv_get_one_day_reset_time(), track_cust_periodic_restart, (void*)2);//24h=86400s
    CTimer_Start(CTIMER_24HOUR_RESET, track_drv_get_one_day_reset_time(), track_cust_periodic_restart, (void*)2);

    //20分钟不能连接上服务器，自动重启
    track_cust_gprs_conn_fail((void*)1);

#if defined (__EXT_VBAT_ADC__)
    track_start_timer(TRACK_CUST_ACC_INIT_OVERTIME_ID, 20000, acc_status_change, (void*)0);
#elif  defined(__NT55__)
	track_start_timer(TRACK_CUST_ACC_INIT_OVERTIME_ID, 5000, acc_status_change, (void*)0);
#endif /* __EXT_VBAT_ADC__ */

#if defined(__BLE_N07__)
	//每次开机都将设备ID传到蓝牙那边
	track_cust_save_device_id_to_bcm();
#endif
}

/******************************************************************************
 *  Function    -  track_os_nvram_init
 *
 *  Purpose     -  开机NVRAM初始化主函数
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_os_nvram_init(void)
{
    track_cust_nvram_data_init();
}


/*****************************************/
/*    APP -> OS                          */
/*****************************************/

char *track_get_app_version(void)
{
    static kal_bool first = KAL_TRUE;
    static char tmp[100], *src_ver, *ver, *p, *m;
    int i = 0;
    if(first)
    {
        first = KAL_FALSE;
        memset(tmp, 0, 100);
        src_ver = _TRACK_VER_APP_;
        p = strstr(src_ver, "_V");
        if(p != NULL)
        {
            m = p + 2;
            while(*m)
            {
                if(*m >= '0' && *m <= '9')
                {
                    i++;
                }
                else if(*m == '_')
                {
                    break;
                }
                else
                {
                    p = NULL;
                    break;
                }
                m++;
            }
        }
        if(i > 5) p = NULL;
        ver = G_importance_parameter_data.version_string2;
        if(p && ver && strlen(p) > 0 && strlen(ver) > 0)
        {
            int len = p - src_ver;
            if(len > 99) len = 99;
            memcpy(tmp, src_ver, len);
            sprintf(tmp + len, "_%s%s", ver, p);
        }
        else
        {
            strncpy(tmp, src_ver, 99);
        }
    }
    return tmp;
}

char *track_get_app_version_datetime(void)
{
    //Sep 28 2014 09:02:45
    //2014/09/28 08:58
    applib_time_struct t = {0};
    static char datetime[50];
    kal_int8 ret;
    ret = strtoime(__DATE__, __TIME__, &t);
    //snprintf(datetime, 50, "%s %s", __DATE__, __TIME__);
    snprintf(datetime, 50, "%02d/%02d/%02d %02d:%02d", t.nYear, t.nMonth, t.nDay, t.nHour, t.nMin);
    return datetime;
}

char *track_get_base_version(void)
{
    return (char*)_TRACK_VER_BASE_;
}

char *track_cust_get_version_for_upload_server(void)
{
    static char ver_string[200] = {0};
    int ver_str_len = 0;
    char *ver;
    //1，OTA    2，OBD    3，软件基础版本"
    //ver_str_len += snprintf(ver_string, 199, "{t:'3',v:'[BASE]%s [BUILD]%s'}", track_get_base_version(), build_date_time());
    ver_str_len += snprintf(ver_string, 199, "{t:'3',v:'%s'}", track_get_base_version());
#if defined(__TRACK_FOTA_UPDATE__)
    ver = track_get_app_version();
    if(strlen(ver) <= 0)
    {
        ver = (char*)release_verno();
    }
    ver_str_len += snprintf(ver_string + ver_str_len, 199 - ver_str_len, ",{t:'1',v:'%s'}" , ver);
#endif /* __TRACK__ */
#if defined (__MCU_SW_UPDATE__)
    if(strlen(track_get_mcu_sw_version()) > 0)
    {
        ver_str_len += snprintf(ver_string + ver_str_len, 199 - ver_str_len, ",{t:'4',v:'%s'}", track_get_mcu_sw_version());
    }
#endif /* __MCU_SW_UPDATE__ */
#if defined(__OBD__)
	if(strlen(track_obd_get_version()) > 0)
	{
		ver_str_len += snprintf(ver_string + ver_str_len, 199 - ver_str_len, ",{t:'2',v:'%s'}", track_obd_get_version());
	}
#endif /* __OBD__ */

    return ver_string;
}

/******************************************************************************
 *  Function    -  track_cmd_net_recv
 *
 *  Purpose     -  网络下发的指令
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 30-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cmd_net_recv(char *data, kal_uint8 *stamp)
{
    int len;
    len = strlen(data);
    if(len < CM_PARAM_LONG_LEN_MAX - 2)
    {
        CMD_DATA_STRUCT cmd = {0};
        cmd.return_sms.cm_type = CM_ONLINE;
        cmd.rcv_length = len;
        memcpy(cmd.return_sms.stamp, stamp, 4);
        strcpy(cmd.rcv_msg, data);
        track_command_operate(&cmd);
    }
}

void track_cmd_netlog_recv(char *data)
{
    int len;
    len = strlen(data);
    if(len < CM_PARAM_LONG_LEN_MAX - 2)
    {
        CMD_DATA_STRUCT cmd = {0};
        cmd.return_sms.cm_type = CM_AT;
        cmd.rcv_length = len;
        strcpy(cmd.rcv_msg, data);
        track_command_operate(&cmd);
    }
}

void track_cmd_params_recv(char *data, Cmd_Type source)
{
    int len;
    char *start = NULL, *end = NULL, *endF = NULL;
    kal_bool valid = KAL_FALSE;
    U16 cmd_length = 0;

    LOGD(L_APP, L_V5, "source:%d", source);
    track_drv_nvram_write_switch(0);
    start = (char*)data;
    len = strlen(data);
    endF = start + len;
    do
    {
        end = strchr(start, '#');
        if(end != NULL)
        {
            *end = 0;
        }
        else
        {
            end = strchr(start, '\n');
            if(end != NULL)
            {
                *end = 0;
            }
        }
        start = track_fun_trim2(start);
        cmd_length = strlen(start);
        if(*start != '#' && cmd_length < CM_PARAM_LONG_LEN_MAX - 2 && cmd_length > 0)
        {
            CMD_DATA_STRUCT cmd = {0};
            cmd.return_sms.cm_type = source;
            cmd.rcv_length = cmd_length;
            strcpy(cmd.rcv_msg, start);
            LOGS("%s", cmd.rcv_msg);
            track_command_operate(&cmd);
            valid = KAL_TRUE;
        }
        if(end == NULL)
        {
            break;
        }
        if(end + 1 >= endF)
        {
            break;
        }
        start = end + 1;
    }
    while(end != NULL);
    track_drv_nvram_write_switch(1);
    if(valid)
    {
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
        Track_nvram_write(NVRAM_EF_PHONE_NUMBER_LID, 1, (void *)&G_phone_number, NVRAM_EF_PHONE_NUMBER_SIZE);
    }
}
/******************************************************************************
 *  Function    -  track_cust_sms_send
 *
 *  Purpose     -  发送短信
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 25-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_sms_send(kal_uint8 number_type, char *number, kal_bool isChar, kal_uint8 *data, kal_uint16 len)
{
    static kal_uint32 index = 0;
    sms_msg_struct ssms = {0};
    int len2, number_len;
    //track_os_intoTaskMsgQueue(track_soc_disconnect); // 通过测试反馈，繁忙的GPRS通讯会影响短信的成功发送。
    index++;
    if(number == NULL || strlen(number) <= 0)
    {
        LOGD(L_APP, L_V1, "WARN: 发送异常，号码为空");
        return;
    }
    if(0xFF == number_type)
    {
        LOGD(L_APP, L_V1, "WARN: 忽略发送，号码类型为0xFF");
        return;
    }
#if defined(__GT740__)
    if(G_parameter.extchip.mode != 1)
    {
        sendmessage = KAL_TRUE;
    }
#elif defined(__GT300S__) || defined(__GT370__)|| defined (__GT380__)
    if(G_parameter.work_mode.mode == 3)
    {
        sendmessage = KAL_TRUE;
    }
#elif defined(__GT370__)|| defined (__GT380__)
    if(G_parameter.work_mode.mode == 1)
    {
        sendmessage = KAL_TRUE;
    }
#endif
    if(isChar)
    {
        len2 = strlen((char*)data);
        if(len > len2)
        {
            LOGD(L_APP, L_V4, "短信发送请求: index=%d, len=%d -> %d, num(%d)=%s|%s|", index, len, len2, number_type, number, data);
            len = len2;
        }
        else
        {
            LOGD(L_APP, L_V4, "短信发送请求: index=%d, len=%d, num(%d)=%s|%s|", index, len, number_type, number, data);
        }
    }
    else
    {
        track_fun_view_UTF16BE_string(data, len);
        len2 = mmi_chset_utf16_strlen(data, MMI_CHSET_UTF16BE) * 2;
        if(len > len2)
        {
            LOGD(L_APP, L_V4, "短信发送请求: index=%d, len=%d -> %d, num(%d)=%s", index, len, len2, number_type, number);
            len = len2;
        }
        else
        {
            LOGD(L_APP, L_V4, "短信发送请求: index=%d, len=%d, num(%d)=%s", index, len, number_type, number);
        }
    }
    LOGH(L_APP, L_V7, data, len);
    ssms.codetype = isChar;
    ssms.num_type = number_type;
    ssms.nocount = 1;
    ssms.numbers[0] = number;
    ssms.ctxlen = len;//(len > 120 ? 120 : len);
    ssms.ctx = data;
    ssms.index = index;
    track_sms_sender(&ssms);
    if((G_realtime_data.netLogControl & 64) && len < 256)
    {
        kal_uint8 *sendData;
        number_len = strlen(number);
        sendData = (kal_uint8*)Ram_Alloc(5, len + number_len + 2);
        sendData[0] = isChar;
        sendData[1] = number_len;
        memcpy(&sendData[2], number, number_len);
        memcpy(&sendData[2 + number_len], data, len);
        cust_packet_log_data(2, sendData, len + number_len + 2);
        Ram_Free(sendData);
    }
}

/******************************************************************************
 *  Function    -  track_cust_call_get_incomming_number
 *
 *  Purpose     -  取得当前来电号码
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 14-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
char* track_cust_call_get_incomming_number(void)
{
    return track_get_incomming_call_number();
}

/******************************************************************************
 *  Function    -  track_cust_call
 *
 *  Purpose     -  呼叫号码
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 25-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_call(char *number)
{
    track_make_call(number);
}

/******************************************************************************
 *  Function    -  track_cust_call_hangup
 *
 *  Purpose     -  挂断当前通话
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 25-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_call_hangup(void)
{
    track_hangup_call();
}

/******************************************************************************
 *  Function    -  track_cust_call_accept
 *
 *  Purpose     -  接起来电
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 14-11-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_call_accept(void)
{
    track_send_at_accept_call();
}

/******************************************************************************
 *  Function    -  track_cust_gps_location_time
 *
 *  Purpose     -  定位时间计算
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_gps_location_time(kal_uint8 status)
{
    static kal_uint32 tick;
    if(status == 1 && (tick == 0 || tick > kal_secs_to_ticks(600)))
    {
        LOGD(L_APP, L_V4, "请求开启GPS");
        tick = kal_get_systicks();
    }
    else if(status == 2 && tick > 0)
    {
        kal_uint32 curr_tick;
        curr_tick = kal_get_systicks();
        LOGD(L_APP, L_V4, "本次有开启定位到完成定位耗时%d秒", kal_ticks_to_secs(curr_tick - tick));
        tick = 0;
    }
}

/******************************************************************************
 *  Function    -  track_cust_gps_switch
 *
 *  Purpose     -  GPS开关接口
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_gps_switch(U8 status)
{
    static U8 fst = 0;
    switch(status)
    {
        case 0:
            track_drv_gps_switch(0);
            LED_GPS_StatusSet(GPS_INVALID_STATE);
            LOGD(L_APP, L_V4, "GPS 关闭");
#if defined (__GT740__)
            track_cust_module_gps_cal_time();
            track_cust_module_gps_sleep_time();
#endif

            break;

        case 1:
            track_drv_gps_switch(status);
            LED_GPS_StatusSet(GPS_PWON_STATE);
            LOGD(L_APP, L_V4, "GPS 开启");
#if defined (__GT740__)
            track_cust_module_gps_boot_time();
            track_cust_module_gps_cal_sleep_time();
#endif

            break;
    }
}
#if 0

/******************************************************************************
 *  Function    -  track_cust_oil_cut
 *
 *  Purpose     -  断油电控制
 *
 *  Description -  1 = 油电断开
 *                 0 = 油电接通
 *                 other  其它值查询返回当前的状态
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 30-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_int8 track_cust_oil_cut(kal_uint8 value)
{
    LOGD(L_APP, L_V5, "%d,%d", value, G_realtime_data.oil_status);
    return track_drv_gpio_cut_oil_elec(value);
}
/******************************************************************************
 *  Function    -  track_cust_motor_lock
 *
 *  Purpose     -  锁电机
 *
 *  Description -  1 = 锁电机
 *                 0 = 解锁电机
 *                 other  其它值查询返回当前的状态
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 10-05-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_int8 track_cust_motor_lock(kal_int8 value)
{
    kal_int8 ret;
    if(value == 1 && track_cust_status_charger() == 0)
    {
        LOGD(L_APP, L_V1, "锁电机失败，外电未接入");
        ret = track_drv_gpio_cut_oil_elec(0);
    }
    else
    {
        ret = track_drv_gpio_cut_oil_elec(value);
    }
    LOGD(L_APP, L_V5, "%d,%d", value, ret);
    return ret;
}
#endif
#if (defined (__GB110__)||defined(__NF2318__)) && defined(__BLE_GATT__)
void track_cust_del_blemacfile(void)
{
	FS_Delete((WCHAR *)L"Z:\\@bt\\le");
}
#endif /* __GB110__ */

/******************************************************************************
 *  Function    -  track_cust_restart
 *
 *  Purpose     -  重启控制接口
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_restart(kal_uint8 mode, kal_uint32 sec)
{
    static int lte_reset  = 0;
    static kal_uint8 pre_mode = 0;//记录实际重启参数
#if defined( __NULL_SERVER__)
    kal_uint8 iLeng = strlen((char*)G_importance_parameter_data.server.url);
    LOGD(L_APP, L_V4, "域名为空不重启mode%d", mode);

    if(0 == iLeng &&  3 != mode && 2 != mode)
    {
        return;
    }
#endif /* __NULL_SERVER__ */
#if defined(__AMS_HEX_LOG__)
{
    kal_uint8 data[8] = {0};
    data[0] = mode;
    track_os_file_log(1, 0x05, data);
}
#endif

#if defined (__NETWORK_LICENSE__)
    return;
#endif /* __NETWORK_LICENSE__ */

#if defined (__MCU_SW_UPDATE__)
    if(track_is_in_update_bootload_cmd())
    {
        LOGD(L_DRV, L_V1, "MCU升级中禁止自动重启");
        return;
    }
#endif /* __MCU_SW_UPDATE__ */

    if(mode != 3 && (pre_mode != 3))
    {
        track_soc_queue_all_to_nvram();
        track_cust_backup_gps_data(4, NULL);
    }
    if(mode != 34)
    {
        pre_mode = mode;
        track_os_log_abnormal_data(mode);
    }
    socket_free();
#if 0//(defined(__GB110__)||defined(__NF2318__)) && defined(__BLE_GATT__)
	track_cust_del_blemacfile();
#endif /* __GB110__ */
	//测试nf2318 行车情况，关闭重启
	//return;
    if(sec == 0)
    {
        LOGD(L_APP, L_V4, "(%d)即将重启，立即进行重启前的数据备份工作。", mode);
        track_drv_watch_dog_close(0);
        if(mode == 28 && track_os_log_abnormal_is_net_error())
        {
            char *tmp = (char *)40;
            track_check_tick(3, (char*)tmp);
        }
        else
#if !(defined(__GT300S__) || defined(__GT370__)|| defined (__GT380__))
            if(mode != 63)
#endif /* __GT300S__ */
            {
                track_device_reset(0);
            }
    }
    else
    {
        LOGD(L_APP, L_V4, "(%d)即将在%d秒后重启，立即进行重启前的数据备份工作。", mode, sec);
        track_device_reset(sec);
    }
}


/******************************************************************************
 *  Function    -  track_cust_get_sim_status
 *
 *  Purpose     -  获取当前SIM卡状态
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 24-01-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_int8 track_cust_get_sim_status(void)
{
    kal_int8 sim_type;
    sim_type = track_drv_get_sim_type();
    if(sim_type == 1)
        track_cust_status_sim_set(1);
    else
        track_cust_status_sim_set(0);
    LOGD(L_APP, L_V6, "%d", sim_type);
    return sim_type;
}

/******************************************************************************
 *  Function    -  track_cust_is_upload_UTC_time
 *
 *  Purpose     -  当前项目是否使用上传 UTC 时间
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 05-03-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_bool track_cust_is_upload_UTC_time(void)
{
#if defined(__WM_OLD06__) || defined(__SAME_GT02__) || defined(__NT36__)
    return KAL_FALSE;
#else
    return KAL_TRUE;
#endif
}

/******************************************************************************
 *  Function    -  track_cust_is_china_sales
 *
 *  Purpose     -  销售区域限制
 *
 *  Description -  KAL_TRUE=允许使用
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 13-05-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_bool track_cust_is_china_sales(void)
{
    char *mcc = track_drv_get_mcc_from_imsi();

#if defined (__SAME_GT02__)
    if(!G_importance_parameter_data.app_version.support_WM)
    {
        LOGD(L_APP, L_V4, "仅限国内大陆区域使用!");
        if(!strcmp(mcc, "460") || !strcmp(mcc, "461"))  // 中国大陆
        {
            /*符合条件允许使用*/
            return KAL_TRUE;
        }
        LOGD(L_APP, L_V4, "使用受限!");
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
#endif /* __SAME_GT02__ */

#if defined(__LIMIT_SALES_AREA__)
    LOGD(L_APP, L_V4, "仅限国内大陆区域使用!");
    if(!strcmp(mcc, "460") || !strcmp(mcc, "461"))  // 中国大陆
    {
        /*符合条件允许使用*/
        return KAL_TRUE;
    }
    LOGD(L_APP, L_V4, "使用受限!");
    return KAL_FALSE;
#elif defined(__LIMIT_SALES_AREA_SOUTH_AMERICA__)
    //定制版，封锁以下三个国家地区使用
    LOGD(L_APP, L_V4, "阿根廷、巴西、巴拉圭3个国家限制使用!");
    if(!strcmp(mcc, "722")/*Argentina*/ || !strcmp(mcc, "724")/*Brazil*/ || !strcmp(mcc, "744")/*Paraguay*/)  // 南美洲
    {
        /*符合条件禁止使用*/
        LOGD(L_APP, L_V4, "使用受限!");
        return KAL_FALSE;
    }
    return KAL_TRUE;
#elif defined(__BLOCK_SALES_AREA_INDIA_ET__)
//定制版，封锁以下五个国家地区使用
    LOGD(L_APP, L_V4, "印度、肯尼亚、阿根廷、巴西、巴拉圭5个国家限制使用!");
    if(!strcmp(mcc, "404")/*印度*/ || !strcmp(mcc, "405")/*印度*/ || !strcmp(mcc, "639")/*肯尼亚*/ || !strcmp(mcc, "722")/*阿根廷*/ || !strcmp(mcc, "724")/*巴西*/ || !strcmp(mcc, "744")/*巴拉圭*/)
    {
        /*符合条件禁止使用*/
        LOGD(L_APP, L_V4, "使用受限!");
        return KAL_FALSE;
    }
    return KAL_TRUE;
#else

    LOGD(L_APP, L_V4, "无使用区域限制!");
    return KAL_TRUE;
#endif
}

/******************************************************************************
 *  Function    -  track_cust_sleep_mode
 *
 *  Purpose     -  深度休眠，gsm待机
 *
 *  Description -  NULL
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 07-08-2013,  ZengPing && Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_sleep_mode(void)
{
    track_stop_timer(TRACK_CUST_ALARM_GPS_WORK_TIMER);
    track_stop_timer(TRACK_CUST_POWERON_CLOSE_GPS_TIMER);
    tr_stop_timer(TRACK_CUST_GPS_EPHEMERIS_UPDATE_TIMER_ID);

    LOGD(L_APP, L_V6, "work_mode = %d", track_cust_get_work_mode());
    if(track_cust_gps_status() != 0)
    {
        track_cust_gps_off_req((void*)4);
    }
    track_os_intoTaskMsgQueue2(track_drv_sensor_off);
    track_os_intoTaskMsgQueue2(track_soc_disconnect);
    track_os_intoTaskMsgQueue2(track_soc_clear_dw_queue);

}

kal_uint16 track_cust_get_pack_time(void)
{
    kal_bool moving = track_cust_is_sensor_shocked_valid();

    if(moving)
    {
        return G_parameter.gps_work.Fti.interval_acc_on;
    }
    else
    {
        return G_parameter.gps_work.Fti.interval_acc_off;
    }

}


/******************************************************************************
 *  Function    -  track_cust_wake_mode
 *
 *  Purpose     -  唤醒休眠
 *
 *  Description -  NULL
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 07-08-2013,  ZengPing && Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_wake_mode(void)
{
#if defined(__GT370__)|| defined (__GT380__)
    LOGD(L_APP, L_V5, "");
    track_cust_mode_change(0);
#else
    if((track_cust_get_work_mode() == WORK_MODE_2) || (track_cust_get_work_mode() == WORK_MODE_4))
    {
        track_cust_gps_work_req((void*)3);
        track_cust_sensor_init();
    }
    else if(track_cust_get_work_mode() == WORK_MODE_1)
    {
        track_cust_gps_work_req((void*)13);

        if(track_cust_status_defences() != 0)
        {
            track_cust_sensor_init();
        }
        else
        {
            track_drv_sensor_off();
        }
    }
#endif

    track_soc_gprs_reconnect((void*)304);
}

/******************************************************************************
 *  Function    -  track_cust_external_batter_measure_done
 *
 *  Purpose     -  外电检测控制GPIO28
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 08-10-2013,  ZengPing  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_external_batter_measure_done(kal_int32 ext_volt)
{
    char exe = 0;
    LOGD(L_APP, L_V6, "%d", ext_volt);
    if((ext_volt <= 12500000))
    {
        exe = GPIO_ReadIO(28);
        if(exe == 1)
        {
            return;
        }
        GPIO_ModeSetup(28, 0);
        GPIO_InitIO(1, 28);
        GPIO_WriteIO(1, 28);
        LOGD(L_APP, L_V6, "GPIO 28 H");
    }
    else if(ext_volt >= 13000000)
    {
        exe = GPIO_ReadIO(28);
        if(exe == 0)
        {
            return;
        }
        GPIO_ModeSetup(28, 0);
        GPIO_InitIO(1, 28);
        GPIO_WriteIO(0, 28);
        exe = GPIO_ReadIO(28);
        LOGD(L_APP, L_V6, "GPIO 28 L");
    }

}

kal_uint32 track_cust_gprson_status(kal_uint32 flag)
{
    static kal_uint32 short_login = 0;
    LOGD(L_APP, L_V5, "flag:%d short_login:%d mod:%d gprson:%d", flag, short_login, G_parameter.work_mode.mode, G_parameter.gprson);
    if(flag == 1 || flag == 0)
    {
        return (short_login = flag);
    }

    if(g_GT03D == KAL_TRUE)
    {
        LOGD(L_APP, L_V6, "mode:%d;gprson:%d;short_login:%d", G_parameter.work_mode.mode, G_parameter.gprson, short_login);
#if defined (__GT300S__) || defined(__GT370__)|| defined (__GT380__)
        return G_parameter.gprson;
#else
        if(G_parameter.work_mode.mode != 3)
        {
            return G_parameter.gprson;
        }
        else
        {
            if(G_parameter.gprson == 1 && short_login == 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
#endif /* __GT300S__ */
    }
    else
    {
        return G_parameter.gprson;
    }
}
#if 0
/******************************************************************************
 *  Function    -  track_cust_check_simalm
 *
 *  Purpose     -  检测是否需要上报换卡报警
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 08-11-2014,  ZengPing && Liujunwu  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_check_simalm(void)
{
    kal_uint32 sim_nvram_flag = 0;
    char *imsi;

    if(G_parameter.sim_alarm.sw == 1)
    {
        imsi = (char *)track_drv_get_imsi(0);
        LOGD(L_APP, L_V5, "IMSI imsi=%s", imsi);
        LOGD(L_APP, L_V5, "IMSI nvram imsi=%s sim_alm=%d", G_parameter.sim_alarm.sim_imsi, G_realtime_data.sim_alm);
        if((!strcmp(G_parameter.sim_alarm.sim_imsi, "0000000000000000")) && ((strcmp(imsi, "000000000000000")) != 0))
        {
            LOGD(L_APP, L_V5, "IMSI NONE");
            sim_nvram_flag = 1;
            sprintf(G_parameter.sim_alarm.sim_imsi, "%s", imsi);
        }
        else if(((strcmp(G_parameter.sim_alarm.sim_imsi, imsi)) == 0) && G_realtime_data.sim_alm == 1)
        {
            LOGD(L_APP, L_V5, "IMSI the same");
            sim_nvram_flag = 2;
            G_realtime_data.sim_alm = 0;
        }
        else if(((strcmp(G_parameter.sim_alarm.sim_imsi, imsi)) != 0) && (G_realtime_data.sim_alm == 0))
        {
            LOGD(L_APP, L_V5, "IMSI CHANGE");
            G_realtime_data.sim_alm = 1;
            sim_nvram_flag = 2;
            track_cust_molude_simalarm_sms();
        }
        else if(G_realtime_data.sim_alm == 1)
        {
            LOGD(L_APP, L_V5, "IMSI @SMS@ has been sent");
        }
        if(sim_nvram_flag != 0)
        {
            LOGD(L_APP, L_V5, "sim alm write to nvram  sim_nvram_flag =%d", sim_nvram_flag);
            if(sim_nvram_flag == 1)
            {
                Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
            }
            else if(sim_nvram_flag == 2)
            {
                Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
            }
        }
    }
}

//extern void track_cust_mode3_update_LBS(void *f);

void track_cust_mode3_work_check(void* flag)
{
    kal_uint32 f = (kal_uint32)flag;
    U8 coutdown = 10;
    LOGD(L_APP, L_V5, "@@flag:%d:interval:%d mins:countdown:%d mins:work_mode:%d,up:%d", f, G_parameter.mode3_work_interval,
         G_realtime_data.work3_countdowm, track_cust_get_work_mode(), G_parameter.mode3_up_counts);

    if(G_parameter.mode3_work_interval <= 0)
    {
        return;
    }

    if(0 == f) /*重新设置*/
    {
        G_realtime_data.work3_countdowm = G_parameter.mode3_work_interval;
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    }

    if(WORK_MODE_3 != track_cust_get_work_mode())
    {
        return;
    }

    if(1 == f && mmi_Get_PowerOn_Type() != PWRKEYPWRON)
    {
        if(G_realtime_data.work3_countdowm + 10 < G_parameter.mode3_work_interval)
        {
            G_realtime_data.work3_countdowm += 5;//异常重启补尝
        }
    }

    if(G_realtime_data.work3_countdowm > G_parameter.mode3_work_interval)
    {
        G_realtime_data.work3_countdowm = G_parameter.mode3_work_interval;
    }

    if(G_realtime_data.work3_countdowm > 10)
    {
        LOGD(L_APP, L_V5, "深度休眠还有%d分钟结束!!!!", G_realtime_data.work3_countdowm);
        G_realtime_data.work3_countdowm -= 10;
    }
    else
    {
        G_realtime_data.work3_countdowm = G_parameter.mode3_work_interval;

        LOGD(L_APP, L_V5, "MODE3定时时间到");

        track_cust_gprson_status(1);
        track_soc_gprs_reconnect((void*)305);
        //唤醒GPS工作
        track_cust_gps_work_req((void*)15);
        track_cust_mode3_uping(1);
        track_start_timer(TRACK_CUST_LBS_UPDATE_L_TIMER_ID, 185 * 1000, track_cust_mode3_update_LBS, (void *)0);

    }

    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    /*以10分钟为步进向前推*/
    track_start_timer(TRACK_CUST_WORK_MODE3_TIMER_ID, coutdown * 60 * 1000, track_cust_mode3_work_check, (void*)99);
}
#endif
static kal_uint8 sw_status[sw_max]={0};

kal_uint8 track_project_save_switch(U8 op, sw_type type)
{
    if(type<sw_max)
    {
        if(op==1 || op==0)
        {
            sw_status[type]=op;
        }
        return sw_status[type];
    }
    return 0;
}


