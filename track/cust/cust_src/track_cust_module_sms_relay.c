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

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
kal_uint8 track_cust_sms_relay_status(kal_uint8 type, char *number);
#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/
/******************************************************************************
 *  Function    -  sms_relay_status_reset
 *
 *  Purpose     -  超时重置短信转发状态
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void sms_relay_status_reset(void)
{
    LOGD(L_APP, L_V5, "");
    track_cust_sms_relay_status(4, NULL);
}

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

/******************************************************************************
 *  Function    -  track_cust_sms_relay_status
 *
 *  Purpose     -  标记是否处于短信转发的有效时间周期内
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_uint8 track_cust_sms_relay_status(kal_uint8 type, char *number)
{
    static kal_uint8 status = 0;
    static char num[32] = {0};
    static kal_uint8 num_type = 0;
    int len = 0;
    
    if(type == 1 && status == 1)
    {
        len = strlen(num);
        if(len > 0 && len < 30)
        {
            strcpy(number, num);
        }
        else
        {
            LOGD(L_APP, L_V4, "num error: %s", num);
            status = 0;
        }
    }
    else if(type == 1 && status == 2)
    {
        memcpy(number, num, 4);
    }
    else if(type == 2)
    {
        len = strlen(number);
        if(len > 30 || track_fun_check_str_is_number(1, number) <= 0)
        {
            LOGD(L_APP, L_V4, "number error:%s", number);
            status = 0;
        }
        else
        {
            strcpy(num, number);
            status = 1;
            tr_start_timer(TRACK_CUST_MODULE_SMS_RELAY_TIMER_ID, 600000, sms_relay_status_reset);
        }
    }
    else if(type == 3)
    {
        status = 2;
        memset(num, 0, 32);
        memcpy(num, number, 4);
        tr_start_timer(TRACK_CUST_MODULE_SMS_RELAY_TIMER_ID, 600000, sms_relay_status_reset);
    }
    else if(type == 4)
    {
        status = 0;
        memset(num, 0, 32);
    }
    else if(type == 5)
    {
        return num_type;
    }
    else
    {
        num_type = type;//wangqi
    }
    
    if(status == 1)
    {
        LOGD(L_APP, L_V5, "status:%d type:%d number:%s", status, type, number);
    }
    else
    {
        LOGD(L_APP, L_V5, "status:%d type:%d", status, type);
    }
    return status;
}

/******************************************************************************
 *  Function    -  track_cust_sms_relay
 *
 *  Purpose     -  判断来源，确定是否进行短信转发
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_sms_relay(track_sms_param *sms_rev)
{
    char phone_number[32] = {0};
    kal_uint8 ret;
    char sms_data[500] = {0};
    char sms_data_ucs2[1000] = {0};
    char serverid[4] = {0xff, 0xff, 0xff, 0xff};

    ret = track_cust_sms_relay_status(1, phone_number);
    LOGD(L_APP, L_V5, "ret:%d,%d,TP_UDL=%d", ret, sms_rev->TP_DCS,sms_rev->TP_UDL);
    if((G_realtime_data.netLogControl & 64) && sms_rev->TP_UDL < 512)
    {
        int number_len;
        kal_uint8 *sendData;
        number_len = strlen(sms_rev->TPA);
        sendData = (kal_uint8*)Ram_Alloc(5, sms_rev->TP_UDL + number_len + 2);
        if(sms_rev->TP_DCS == GSM_7BIT || sms_rev->TP_DCS == GSM_8BIT)
        {
            sendData[0] = 1;
        }
        sendData[1] = number_len;
        memcpy(&sendData[2], sms_rev->TPA, number_len);
        memcpy(&sendData[2+number_len], sms_rev->TP_UD, sms_rev->TP_UDL);
        cust_packet_log_data(1, sendData, sms_rev->TP_UDL + number_len + 2);
        Ram_Free(sendData);
    }

        if(G_parameter.smstc.sw&&track_is_sms_cmd(99)==0)
    {
            if(sms_rev->TP_DCS == GSM_7BIT || sms_rev->TP_DCS == GSM_8BIT)
            {
                sprintf(sms_data, "%s:%s", sms_rev->TPA, sms_rev->TP_UD);
                track_cust_paket_21(serverid, KAL_TRUE, sms_data, strlen(sms_data));
            }
            else if(sms_rev->TP_DCS == GSM_UCS2)
            {
                sprintf(sms_data, "%s:", sms_rev->TPA);
                track_fun_asc_str_to_ucs2_str(sms_data_ucs2, sms_data);
                memcpy(sms_data_ucs2 + 2 * strlen(sms_data), sms_rev->TP_UD, sms_rev->TP_UDL);
                track_cust_paket_21(serverid, KAL_FALSE,sms_data_ucs2, sms_rev->TP_UDL + 2 *(strlen(sms_rev->TPA) + 2));
            }
    }
    if(ret == 1)
    {
        if(strstr(phone_number, sms_rev->TPA))
        {
            LOGD(L_APP, L_V5, "与原号码相同不转发 %s,%s", phone_number, sms_rev->TPA);
            return;
        }
        sms_rev->P_TYPE = track_cust_sms_relay_status(5, NULL);
        if(sms_rev->TP_DCS == GSM_7BIT || sms_rev->TP_DCS == GSM_8BIT)
        {
            sprintf(sms_data,"%s:%s",sms_rev->TPA,sms_rev->TP_UD);
            track_cust_sms_send(sms_rev->P_TYPE, phone_number, KAL_TRUE, sms_data, strlen(sms_data));
        }
        else if(sms_rev->TP_DCS == GSM_UCS2)
        {
            sprintf(sms_data,"%s:",sms_rev->TPA);
            track_fun_asc_str_to_ucs2_str(sms_data_ucs2,sms_data);
            memcpy(sms_data_ucs2+2*strlen(sms_data),sms_rev->TP_UD,sms_rev->TP_UDL);
            track_cust_sms_send(sms_rev->P_TYPE, phone_number, KAL_FALSE, sms_data_ucs2, sms_rev->TP_UDL+2*(strlen(sms_rev->TPA)+2));
        }
        else
        {
            LOGD(L_APP, L_V5, "TP_DCS:%d TP_UDL:%d", sms_rev->TP_DCS, sms_rev->TP_UDL);
        }
    }
    else if(ret == 2&&G_parameter.smstc.sw==0)
    {
        if(sms_rev->TP_DCS == GSM_7BIT || sms_rev->TP_DCS == GSM_8BIT)
        {
            track_cust_paket_21(phone_number, KAL_TRUE, sms_rev->TP_UD, sms_rev->TP_UDL);
        }
        else if(sms_rev->TP_DCS == GSM_UCS2)
        {
            track_cust_paket_21(phone_number, KAL_FALSE, sms_rev->TP_UD, sms_rev->TP_UDL);
        }
    }

}

