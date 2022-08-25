/*******************************************************************************************
 * Filename:                                                                              *
 * Author  :                                                                              *
 * Date    :                                                                              *
 * Comment :                                                                              *
*******************************************************************************************/

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

#if defined(__GERMANY__)
static char *str_gprs_block_en = "Achtung der GPS Tracker ist offline!";
#else
static char *str_gprs_block_en = "Attention!The device is offline!";
#endif
static kal_uint8 str_gprs_block_cn[28] =   //注意！终端GPRS已离线！
{
    0x6C, 0xE8, 0x61, 0x0F, 0xFF, 0x01, 0x7E, 0xC8, 0x7A, 0xEF, 0x00, 0x47,
    0x00, 0x50, 0x00, 0x52, 0x00, 0x53, 0x5D, 0xF2, 0x79, 0xBB, 0x7E, 0xBF, 0xFF, 0x01, 0x00, 0x00
};
#endif

/******************************************************************************
*  Global Variable                      全局变量
******************************************************************************/

/******************************************************************************
*  Global Variable - Extern             引用全局变量
******************************************************************************/

/******************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/

/******************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/

#if 0
#endif /* 0 */
/******************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

/******************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

/******************************************************************************
 *  Function    -  track_cust_module_alarm
 *
 *  Purpose     -  GPRS阻塞报警处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
******************************************************************************/
void track_cust_module_alarm(kal_uint32 *count)
{
#if defined(__NF2318__)
;
#else
    static kal_uint8  flag = 3;
    LOGD(L_APP, L_V5, "count:%d, sw:%d, set:%d, flag:%d %d", *count, G_parameter.gprs_obstruction_alarm.sw, 
		G_parameter.gprs_obstruction_alarm.link, flag, track_cust_get_work_mode());
	if(track_cust_get_work_mode() == WORK_MODE_3)
	{
		return;
	}	

    if(flag == 3)
    {
        flag = G_realtime_data.reconnect_send_flg;
        if(G_realtime_data.reconnect_send_flg == 0)
        {
            *count = G_parameter.gprs_obstruction_alarm.link+1;
        }
    }
    if(!G_parameter.gprs_obstruction_alarm.sw)
    {
        return;
    }

    if(G_parameter.gprs_obstruction_alarm.link <= *count && flag)
    {
        struct_msg_send g_msg = {0};
        flag = 0;
        g_msg.addUrl = KAL_FALSE;
        g_msg.cm_type = CM_SMS;
        snprintf(g_msg.msg_en, CM_PARAM_LONG_LEN_MAX, str_gprs_block_en);
        g_msg.msg_cn_len = 28;

        memcpy(g_msg.msg_cn, str_gprs_block_cn, g_msg.msg_cn_len);
        if(!track_cust_module_alarm_msg_send(&g_msg, NULL))
        {
            flag = 1;
        }
    }
    else if(G_parameter.gprs_obstruction_alarm.link >= *count)
    {
        flag = 1;
    }
    if(G_realtime_data.reconnect_send_flg != flag)
    {
        G_realtime_data.reconnect_send_flg = flag;
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    }
#endif
}

