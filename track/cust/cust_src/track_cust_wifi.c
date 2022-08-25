#if defined __CUSTOM_WIFI_FEATURES_SWITCH__
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
#include "track_fun_common.h"
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
static kal_bool wifi_send = KAL_FALSE;
static kal_bool wifi_scaning = KAL_FALSE;
/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/
track_wifi_struct wifi_status = {0};
/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern     void track_cust_paket_2C(void);

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/


/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/


/*****************************************************************************

*  Global Functions                     全局函数
******************************************************************************/
void track_cust_wifidata(kal_uint8* data, kal_uint32 len)
{
    kal_uint8 buf_data[10][200] = {0};
    kal_uint8 *pars[6];
    kal_uint8 tmp[7] = {0};
    int index = 0, buf_len = 0, data_index = 0;
    track_wifi_struct track_wifi_tmp = {0};
    kal_uint8 max_rssi = 255;
    kal_uint8 i, j, max_data;

    LOGD(L_APP, L_V5, "%s", data);
    memset(buf_data, 0x00, sizeof(buf_data));
    memset(&wifi_status, 0x00, sizeof(track_wifi_struct));

    memcpy(buf_data, data, sizeof(buf_data));

    for(index = 0, data_index = 0; index < len; index++)
    {
        buf_len = strlen(buf_data[index]);
        //LOGD(L_APP, L_V7, "%d", buf_len);
        //LOGD(L_APP, L_V6, "buf_data%s", buf_data[index]);
        //LOGD(L_APP, L_V6, "data%s", data[index]);
        //LOGH(L_APP, L_V7, buf_data[index], buf_len);

        track_fun_str_analyse(buf_data[index], pars, 6, ':', "\r\n", ',');

        if(strlen(pars[0]) && strlen(pars[3]))
        {
            memcpy(track_wifi_tmp.wifi_mac[data_index], pars[0], strlen(pars[0]));
            memcpy(tmp, pars[3], strlen(pars[3]));

            //LOGD(L_APP, L_V7, "mac = %s", track_wifi_tmp.wifi_mac[data_index]);
            //LOGD(L_APP, L_V7, "rssi = %d", track_wifi_tmp.wifi_rssi[data_index]);
            //LOGD(L_APP, L_V7, "@@%s", buf_data[index]);
            track_fun_del_string(track_wifi_tmp.wifi_mac[data_index], ":");
            track_fun_del_string(tmp, "-");
            track_wifi_tmp.wifi_rssi[data_index] = OTA_atoi(tmp);
            LOGD(L_APP, L_V7, "@@%s,%d", tmp, track_wifi_tmp.wifi_rssi[data_index]);


            //LOGD(L_APP, L_V7, "mac = %s", track_wifi_tmp.wifi_mac[data_index]);
            //LOGH(L_APP, L_V7, track_wifi_tmp.wifi_mac[data_index], strlen(wifi_status.wifi_mac[data_index]));
            //LOGD(L_APP, L_V7, "rssi = %d", track_wifi_tmp.wifi_rssi[data_index]);
            data_index++;
        }
    }
    track_wifi_tmp.wifi_sum = data_index;
    if(track_wifi_tmp.wifi_sum > 10)
    {
        track_wifi_tmp.wifi_sum = 10;
    }

    memset(&wifi_status, 0, sizeof(track_wifi_struct));//排序算法
    for(j = 0; j < track_wifi_tmp.wifi_sum; j++)
    {
        for(i = 0; i < track_wifi_tmp.wifi_sum; i++)
        {
            if(max_rssi > track_wifi_tmp.wifi_rssi[i])
            {
                memcpy(wifi_status.wifi_mac[j], track_wifi_tmp.wifi_mac[i], 20);
                wifi_status.wifi_rssi[j] = track_wifi_tmp.wifi_rssi[i];
                max_rssi = track_wifi_tmp.wifi_rssi[i];
                max_data = i;
                // track_wifi_tmp.wifi_rssi[i]=0;
            }
        }
        track_wifi_tmp.wifi_rssi[max_data] = 255;
        max_rssi = 255;
    }
    wifi_status.wifi_sum = track_wifi_tmp.wifi_sum;

    for(i = 0; i < wifi_status.wifi_sum; i++)
    {
        LOGD(L_APP, L_V5, "mac:%s,rssi:%d", track_wifi_tmp.wifi_mac[i], track_wifi_tmp.wifi_rssi[i]);
    }

    for(i = 0; i < wifi_status.wifi_sum; i++)
    {
        LOGD(L_APP, L_V5, "MAC:%s,rssi:%d", wifi_status.wifi_mac[i], wifi_status.wifi_rssi[i]);
    }
#if defined(__GT740__)
    if(G_parameter.gpswake == 0) //若要开启GPS关机不由此处控制，在bootsendlbs
    {
        wifi_send = KAL_TRUE;
    }
#endif
    wifi_scaning = KAL_FALSE;
    track_cust_paket_2C();
    tr_stop_timer(TRACK_CUST_WIFI_OFF_TIMER_ID);
    tr_stop_timer(TRACK_CUST_WIFI_SCAN_TIMER_ID);
    track_drv_wifi_cmd(0);

}

kal_bool track_cust_get_wifi_upload_sign()
{
    return wifi_send;
}

void track_drv_wifi_work_mode(void)
{
    track_cust_sendWIFI_paket();

    if(track_cust_get_work_mode() == WORK_MODE_3)
    {
        return;
    }
    if(G_parameter.wifi.sw == 0)
    {
        return;
    }
    if(G_parameter.wifi.work_timer != 0)
    {
        LOGD(L_APP, L_V1, "WIFI定时搜索开启,%d分钟后搜索!", G_parameter.wifi.work_timer / 60);
        tr_start_timer(TRACK_CUST_WIFI_WORK_TIMER_ID, (G_parameter.wifi.work_timer + G_parameter.wifi.sacn_timer) * 1000, track_drv_wifi_work_mode);
    }
}

/******************************************************************************
 *  Function    -  track_cust_WIFI_off_paket
 *
 *  Purpose     -  搜索wifi超时
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-02-27,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_WIFI_off_paket(void)
{
    memset(&wifi_status, 0, sizeof(track_wifi_struct));
#if defined(__GT300S__)
    track_cust_paket_2C();
#elif defined (__GT370__)|| defined (__GT380__)
    //需求变更，无wifi只上报LBS
    LOGD(L_APP, L_V5, "超时未搜索到WIFI，上传LBS");
    track_os_intoTaskMsgQueueExt(track_cust_send_lbs, (void*)4);
#elif defined(__GT740__)
    memset(&wifi_status, 0, sizeof(track_wifi_struct));
    if(G_parameter.extchip.mode != 1)
    {
        LOGD(L_APP, L_V5, "超时没有搜索到WIFI，上传LBS!!");
        track_os_intoTaskMsgQueueExt(track_cust_send_lbs, (void*)4);
        track_cust_gps_work_req((void *)19);
    }
#endif
    wifi_scaning = KAL_FALSE;
    tr_stop_timer(TRACK_CUST_WIFI_OFF_TIMER_ID);
    tr_stop_timer(TRACK_CUST_WIFI_SCAN_TIMER_ID);
    track_drv_wifi_cmd(0);

}

void track_cust_sendWIFI_paket(void)
{
    kal_uint16 wifi_close = G_parameter.wifi.sacn_timer + 1;
    kal_uint16 wifi_scan = G_parameter.wifi.sacn_timer - 2;
    static U8 count = 0;

    LOGD(L_APP, L_V5, "count %d", count);
#if defined(__GT740__)
    if(track_sms_get_send_status())
    {
        if(count < 5)
        {
            count++;
            tr_start_timer(TRACK_CUST_WIFI_WORK_TIMER_ID, 5 * 1000, track_drv_wifi_work_mode);
            return;
        }
    }
    else
    {
        count = 0;
    }
#endif


    wifi_scaning = KAL_TRUE;

    if(track_drv_wifi_status(99) != 1)
    {
        track_drv_wifi_cmd(1);
#if defined(__GT370__)|| defined (__GT380__)
        if(G_parameter.wifi.sacn_timer >= track_gt370_get_upload_time())
        {
            wifi_close = track_gt370_get_upload_time() + 1;
            wifi_scan = track_gt370_get_upload_time() - 2;
        }
        if(KAL_FALSE == track_is_timer_run(TRACK_CUST_WIFI_OFF_TIMER_ID))
        {
            tr_start_timer(TRACK_CUST_WIFI_OFF_TIMER_ID, wifi_close * 1000, track_cust_WIFI_off_paket);
        }
        if(KAL_FALSE == track_is_timer_run(TRACK_CUST_WIFI_SCAN_TIMER_ID))
        {
            track_start_timer(TRACK_CUST_WIFI_SCAN_TIMER_ID, wifi_scan * 1000, track_drv_wifi_cmd, (void *)2); //开启WIFI 跟查询必须做间隔
        }
#else
        if(!track_is_timer_run(TRACK_CUST_WIFI_OFF_TIMER_ID))
        {
            tr_start_timer(TRACK_CUST_WIFI_OFF_TIMER_ID, G_parameter.wifi.sacn_timer * 1000 + 5 * 1000, track_cust_WIFI_off_paket);
        }
        if(!track_is_timer_run(TRACK_CUST_WIFI_SCAN_TIMER_ID))
        {
            track_start_timer(TRACK_CUST_WIFI_SCAN_TIMER_ID, G_parameter.wifi.sacn_timer * 1000 + 1000, track_drv_wifi_cmd, (void *)2); //开启WIFI 跟查询必须做间隔
        }
#endif

    }
    else
    {
        track_drv_wifi_cmd(2);
    }

}

kal_bool track_cust_wifi_scan_status()
{
    return wifi_scaning;
}

void track_cust_wifi_work_mode(void)
{
	kal_uint16 interval_timer = 0;
	if(track_cust_status_acc())
    {
        interval_timer = G_parameter.gps_work.Fti.interval_acc_on;
    }
    else
    {
        interval_timer = G_parameter.gps_work.Fti.interval_acc_off;
    }
	if(track_drv_wifi_status(99) == 0)
	{
		track_drv_wifi_cmd(1);
		//track_drv_wifi_cmd(2);
		track_start_timer(TRACK_CUST_WIFI_WORK_TIMER_ID,600,track_drv_wifi_cmd,(void*)2);
	}
	else
	{
		track_drv_wifi_cmd(2);
	}

	tr_start_timer(TRACK_CUST_WIFI_WORKMODE_INTERVAL_TIMER_ID,interval_timer-2000, track_cust_wifi_work_mode);
}
#endif
