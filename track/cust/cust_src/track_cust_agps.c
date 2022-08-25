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
#include "mtk_gps_type.h"
#include "track_os_ell.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/
typedef struct
{
    kal_uint8 a;
    char *b;
} error_msg_struct;

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static kal_uint32 file_flag = 0;
static kal_uint16 req_size = 0, file_crc = 0, recv_size = 0;
static kal_bool force_update = KAL_FALSE;      // 已经存在有效的EPO文件仍然强制更新
static kal_bool only_update = KAL_TRUE;        // 防止从服务器下回来的EPO就是无效的，仍然反复下载的问题
static int retry;
static kal_uint32 start_time_tick = 0;
static kal_uint8 _filetype = 0;
static kal_uint8 nowUpdateFile = 0;

static error_msg_struct error_msg[] =
{
    {0x00, ""},
    {0x01, "成功"},
    {0x02, "CRC校验失败"},
    {0x03, "包长度错误"},
    {0x04, "包类型错误"},
    {0x05, "文件类型错误"},
    {0x06, "IMEI无效"},
    {0x07, "芯片ID无效"},
    {0x08, "芯片ID与IMEI不匹配"},
    {0x09, "软件版本号无效"},
    {0x0A, "文件识别码错误"},
    {0x0B, "数据包长度错误"},
    {0x0C, "请求文件开始位置错误"},
    {0x0D, "未登录发送请求文件"},
    {0x0E, "未登录发送分割文件请求"},
    {0x0F, "未发送请求文件发送分割文件请求"},
    {0x10, "数据包错误"},
    {0x11, "服务器繁忙"},
    {0x12, "服务器文件过期"}
};

static float s_lat=0;
static float s_lon=0;
static kal_uint8 No_Last_Pos=0;//无上次一次定位点标志

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern kal_int8 track_send_assistance_data(kal_bool ischeck, kal_uint16 iYr, kal_uint8 iMo, kal_uint8 iDay, kal_uint8 iHr);
extern kal_int32 track_fun_decryption(kal_uint8 *dec, kal_uint8 *src, int size);
extern kal_int8 track_drv_gps_reset(kal_uint8 delay);
/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/

#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

void track_cust_agps_time_add_6hour(applib_time_struct *time)
{
    applib_time_struct diff_time = {0}, in_dt = {0};

    memcpy(&in_dt, time, sizeof(applib_time_struct));
    //将传入的时间推迟6小时
    diff_time.nHour = 6;
    
    applib_dt_increase_time(&in_dt, &diff_time, time);
}


/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

/******************************************************************************
 *  Function    -  track_cust_agps_restart
 *
 *  Purpose     -  如果当前GPS未完成定位，关闭GPS，重新开启，为了让EPO文件辅助加快定位
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 11-06-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_agps_restart(void)
{
    LOGD(L_APP, L_V5, "");
    if(GPS_STAUS_OFF != track_cust_gps_status())
    {
        track_drv_gps_reset(1);
    }
}
kal_uint8 track_cust_agps_check_from_time(mtk_param_epo_time_cfg *epo_time)
{
    kal_int8 r;
    kal_uint8 ret = 0;
    track_gps_data_struct *gpsLastPoint = NULL;
#if defined (__SECOND_SET__)
    return 0x01;// xzq 换取经纬度
#endif
    gpsLastPoint = track_cust_backup_gps_data(0, NULL);
    r = track_send_assistance_data(KAL_TRUE, epo_time->u2YEAR, epo_time->u1MONTH, epo_time->u1DAY, epo_time->u1HOUR);
    LOGD(L_APP, L_V4, "ret=%d, 登陆成功 %d-%0.2d-%0.2d %0.2d:%0.2d:%0.2d", ret,
         epo_time->u2YEAR, epo_time->u1MONTH, epo_time->u1DAY,
         epo_time->u1HOUR, epo_time->u1MIN, epo_time->u1SEC);
    if(force_update)
    {
        return 3;
    }
    if(gpsLastPoint->gprmc.status == 0)
    {
        ret |= 1;
    }
    if(only_update && r <= 4)
    {
        ret |= 2;
    }
    if(!ret && track_cust_gps_status() == GPS_STAUS_SCAN)
    {
        track_drv_gps_epo_start();
    }
    return ret;
}

/******************************************************************************
 *  Function    -  track_cust_agps_status
 *
 *  Purpose     -  记录当前是否处于AGPS的EPO文件更新流程中
 *
 *  Description -  参数     含义
 *                 0        退出更新流程
 *                 1        标记当前处于更新流程中
 *                 返回值
 *                     0    不在更新流程中
 *                     1    处于更新流程中
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 11-06-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_uint8 track_cust_agps_status(kal_uint8 par)
{
    static kal_uint8 status = 0;
    if(par == 0)
    {
        status = 0;
    }
    else if(par == 1)
    {
        status = 1;
    }
    else if(par == 99)
    {
        if(G_parameter.agps.sw == 0)
        {
            return 0;
        }
    }
    return status;
}

/******************************************************************************
 *  Function    -  track_cust_agps_main
 *
 *  Purpose     -  AGPS的EPO文件更新主函数，如果当前EPO文件是有效的，那么将跳过更新
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 11-06-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_agps_main(void)
{
    kal_uint8 agps_status = track_cust_agps_status(99);
    LOGD(L_APP, L_V5, "%d", agps_status);
    if(agps_status == 0)
    {
        retry = 0;
        track_cust_agps_status(1);
        track_cust_server2_conn((void*)1);
    }
}

/******************************************************************************
 *  Function    -  track_cust_agps_get_data_force
 *
 *  Purpose     -  强制更新AGPS的EPO文件，忽略当前已经存在有效的EPO文件
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 11-06-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_agps_get_data_force(kal_uint8 arg)
{
    LOGD(L_APP, L_V5, "");
    if(arg == 2) force_update = KAL_TRUE;
    track_cust_agps_status(0);
    track_cust_agps_start();
}

void track_cust_agps_start(void)
{
    applib_time_struct currTime = {0};
    kal_bool valid = KAL_TRUE;

    LOGD(L_APP, L_V5, "");
    
    track_os_intoTaskMsgQueue(track_cust_agps_main);

    if(track_cust_agps_valid(1))
    {
        track_fun_get_time(&currTime, KAL_TRUE, NULL);
        if(currTime.nYear == 2000 + (*OTA_DEFAULT_HARDWARE_YEAR) && currTime.nMonth == (*OTA_DEFAULT_HARDWARE_MON))
        {
            LOGD(L_APP, L_V5, "4");
            valid = KAL_FALSE;
        }
        else
        {
            kal_int8 ret = track_send_assistance_data(KAL_TRUE, currTime.nYear, currTime.nMonth, currTime.nDay, currTime.nHour);
            LOGD(L_APP, L_V4, "当前系统时间: %d-%0.2d-%0.2d %0.2d:%0.2d:%0.2d",
                 currTime.nYear, currTime.nMonth, currTime.nDay,
                 currTime.nHour, currTime.nMin, currTime.nSec);
            if(ret < 4)
            {
                LOGD(L_APP, L_V5, "5");
                valid = KAL_FALSE;
            }
        }

        if(valid && track_cust_gps_status() == GPS_STAUS_SCAN)
        {
            LOGD(L_APP, L_V5, "6");
            track_drv_gps_epo_start();
        }
    }
}

U8 track_cust_xor_buf(char* buf, U8 len)
{
	U8 ch,i=1;
	ch=buf[0];
	while(i<len)
	{
	    ch = ch^buf[i];
	    i++;
	}
	return ch;
}
/******************************************************************************
 *  Function    -  track_cust_secset
 *
 *  Purpose     -  注入上一次定位点参考位置
 *
 *  Description -  目前默认注入上一次定位点，后续个人佩带产品可以通过宏控制只注入服务器点
 *
 *  modification history
 * ----------------------------------------
 * v1.0   08-06-2016,  xzq
 * ----------------------------------------
*******************************************************************************/
static void track_cust_secset()
{
    float lat = 0, lon = 0, altitude=0;
    char singlebuf[100] = {0};
    U8 checksum = 0, gstus = 0;
    float fp = 2;
    track_gps_data_struct *gpsLastPoint2 = NULL;
    applib_time_struct currTime = {0};
    track_fun_get_time(&currTime, KAL_TRUE, NULL);//utc时间
    gpsLastPoint2 = track_cust_backup_gps_data(0, NULL);
    gstus = track_cust_gps_status();
    if(gstus > GPS_STAUS_SCAN)
    {
        LOGD(L_GPS, L_V6, "已定位，不再注入!");
        return;
    }
#if !(defined(__GT360__) || defined(__GT740__))
    if(gpsLastPoint2->gprmc.status == 1)
    {
		if(gpsLastPoint2->gprmc.EW == 'E')
        {
            lon = gpsLastPoint2->gprmc.Longitude;
        }
        else
        {
            lon = -gpsLastPoint2->gprmc.Longitude;
        }
        if(gpsLastPoint2->gprmc.NS == 'N')
        {
            lat = gpsLastPoint2->gprmc.Latitude;
        }
        else
        {
            lat = -gpsLastPoint2->gprmc.Latitude;
        }
		altitude = gpsLastPoint2->gpgga.msl_altitude;
    }
    else if(s_lat != 0 && s_lon != 0)
#else
	if(s_lat != 0 && s_lon != 0)// 手持项目不注入上次定位点，怕误差大
#endif
    {
        lat = s_lat;
        lon = s_lon;
		altitude = 0;
	}
    else
    {
        LOGD(L_GPS, L_V5, "无注入参考点！！");
        No_Last_Pos = 1;
        return;
    }
    snprintf(singlebuf, 99, "$PMTK713,%0.6f,%0.6f,%0.6f,%d,%d,%d,%d", lat, lon, altitude, 30000, 30000, 0, 1200);
    checksum = track_cust_xor_buf(&singlebuf[1], strlen(singlebuf) - 1);
    snprintf(singlebuf + strlen(singlebuf), 99, "*%02X", checksum);
    track_drv_uart2_write_data(singlebuf, strlen(singlebuf));
    LOGD(L_GPS, L_V5, "秒定功能:开启注入参考位置!!!");
}

/******************************************************************************
 *  Function    -  track_cust_secset_interface
 *
 *  Purpose     -  秒定注入上一次定位点唯一接口
 *
 *  Description -  
 *  modification history
 * ----------------------------------------
 * v1.0   08-06-2016,  xzq
 * ----------------------------------------
*******************************************************************************/
void track_cust_secset_interface()
{
	track_stop_timer(TRACK_DRV_ACTIVE_REFTIME_TIMER_ID);
	track_cust_secset();
}
/******************************************************************************
 *  Function    -  track_cust_decode_lbs
 *
 *  Purpose     -  服务器转换回来的经纬度
 *
 *  Description -  
 *  modification history
 * ----------------------------------------
 * v1.0   08-06-2016,  xzq
 * ----------------------------------------
*******************************************************************************/
void track_cust_decode_lbs(float* lat1,float* lon1)
{
	U8 singlebuf[100]={0},checksum;
	U8 gstus=0;
	gstus = track_cust_gps_status();
	s_lat=*lat1;
	s_lon=*lon1;
	if(No_Last_Pos && (gstus<GPS_STAUS_2D && gstus>GPS_STAUS_OFF))
	{
		snprintf(singlebuf, 99, "$PMTK713,%0.6f,%0.6f,%0.0f,%d,%d,%d,%d",s_lat,s_lon,0.00000,30000,30000,0,1200);
		checksum = track_cust_xor_buf(&singlebuf[1],strlen(singlebuf)-1);
   		snprintf(singlebuf+strlen(singlebuf), 99,"*%02X",checksum);
		track_drv_uart2_write_data(singlebuf, strlen(singlebuf));
		LOGD(L_GPS, L_V5, "%s",singlebuf);
		No_Last_Pos=KAL_FALSE;
	}
    LOGD(L_GPS, L_V5, "LBS转换回来的点 %f, %f, gps_status %d",s_lat,s_lon,gstus);
}

