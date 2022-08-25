/******************************************************************************
 * track_gps_data_decode.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        GPS 数据流解码
 *
 * modification history
 * --------------------
 * v1.0   2012-07-24,  chengjun create this file
 *
 ******************************************************************************/

/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/
#include "track_drv_gps_decode.h"
#include "track_drv_gps_drive.h"
#include "stack_ltlcom.h"
#include "string.h"
#include "stdlib.h"
#include "c_RamBuffer.h"
#include "track_os_ell.h"
/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/


/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/


/*****************************************************************************
 *  Struct			    数据结构定义
*****************************************************************************/


/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/
static gps_gpgga_struct gpgga_data = {0};
static gps_gpgsa_struct gpgsa_data = {0};
static gps_gpgsv_struct gpgsv_data = {0};
static gps_gprmc_struct gprmc_data = {0};
static gps_gpvtg_struct gpvtg_data = {0};

static gps_gpgga_struct bdgga_data = {0};
static gps_gpgsa_struct bdgsa_data = {0};
static gps_gpgsv_struct bdgsv_data = {0};
static gps_gprmc_struct bdrmc_data = {0};
static gps_gpvtg_struct bdvtg_data = {0};

static gps_gpgll_struct gpgll_data = {0};
static gps_gpmss_struct gpmss_data = {0};
static gps_gpzda_struct gpzda_data = {0};

static track_gps_data_struct  track_gps_data = {0}; //全部GPS 解码数据，供外界使用

static track_gps_epo_struct track_gps_epo = {0};
static enum_gps_mode gps_working = GPS;
/****************************************************************************
* Global Variable           全局变量
*****************************************************************************/


/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/


/*****************************************************************************
 *  Global Functions	- Extern	    引用外部函数
*****************************************************************************/
extern void track_cust_gps_decode_done(track_gps_data_struct *track_gps_data);

/******************************************************************************
 *  Function    -  gps_DataVTG
 *
 *  Purpose     -  GPS数据VTG部分解析
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 17-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static kal_int8 gps_DataVTG(mtk_gps_position gpsdata)
{
    memset(&gpvtg_data, 0, sizeof(gps_gpvtg_struct));

    gpvtg_data.Course0 = gpsdata.heading;
    gpvtg_data.Reference0 = 'T';
    gpvtg_data.Course1 = 0;
    gpvtg_data.Reference1 = 'M';
    gpvtg_data.Speed0 = gpsdata.gspeed * 1.942795467;   //海里/小时
    gpvtg_data.Units0 = 'N';
    gpvtg_data.Speed1 = gpsdata.gspeed * 3.6;           //千米/小时
    gpvtg_data.Units1 = 'K';
    gpvtg_data.Mode = (gpsdata.fix_type >= MTK_GPS_FIX_TYPE_2D ?
                       (gpsdata.fix_quality == MTK_GPS_FIX_Q_DGPS ? 'D' : 'A') :
                           (gpsdata.fix_quality == MTK_GPS_FIX_Q_EST ? 'E' : 'N'));

    return 1;
}

/******************************************************************************
 *  Function    -  gps_DataGGA
 *
 *  Purpose     -  GPS数据GGA部分解析
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 17-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static kal_int8 gps_DataGGA(mtk_gps_position gpsdata)
{
    memset(&gpgga_data, 0, sizeof(gps_gpgga_struct));

    gpgga_data.nHour = gpsdata.utc_time.hour;
    gpgga_data.nMin = gpsdata.utc_time.min;
    gpgga_data.nSec = gpsdata.utc_time.sec;

    gpgga_data.Latitude = gpsdata.LLH[0];
    gpgga_data.Longitude = gpsdata.LLH[1];
    gpgga_data.NS = ((gpsdata.LLH[0] >= .0) ? 'N' : 'S');
    gpgga_data.EW = ((gpsdata.LLH[1] >= .0) ? 'E' : 'W');

    gpgga_data.posi_fix = gpsdata.fix_quality;
    gpgga_data.sat = gpsdata.sv_used_num;

    if(gpsdata.fix_type != MTK_GPS_FIX_TYPE_INVALID)
    {
        gpgga_data.HDOP = gpsdata.HDOP;
    }

    gpgga_data.msl_altitude = gpsdata.LLH[3];
    gpgga_data.Units1 = 'M';
    gpgga_data.Geoid_Altitude = gpsdata.LLH[2] - gpsdata.LLH[3];
    gpgga_data.Units2 = 'M';

    if(gpsdata.fix_quality == MTK_GPS_FIX_Q_DGPS)
    {
        gpgga_data.Age = gpsdata.DGPS_age;
        gpgga_data.station_ID = gpsdata.DGPS_station_ID;
    }
    return 1;
}


/******************************************************************************
 *  Function    -  gps_DataGSA
 *
 *  Purpose     -  GPS数据GSA部分解析
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 17-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static kal_int8 gps_DataGSA(mtk_gps_position gpsdata)
{
    kal_uint8 i;

    memset(&gpgsa_data, 0, sizeof(gps_gpgsa_struct));

    gpgsa_data.mode = 'A';
    gpgsa_data.status = gpsdata.fix_type;
    for(i = 0; i < MTK_GPS_SV_MAX_NUM; i++)
    {
        if(gpsdata.sv_used_prn_list[i] != 0)
        {
            gpgsa_data.satellite_used[i] = gpsdata.sv_used_prn_list[i];
        }
    }
    gpgsa_data.PDOP = gpsdata.PDOP;
    gpgsa_data.HDOP = gpsdata.HDOP;
    gpgsa_data.VDOP = gpsdata.VDOP;

    return 1;
}

/******************************************************************************
 *  Function    -  gps_DataGSV
 *
 *  Purpose     -  GPS数据GSV部分解析
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 17-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static kal_int8 gps_DataGSV(mtk_gps_position gpsdata)
{
    kal_uint8  i;

    memset(&gpgsv_data, 0, sizeof(gps_gpgsv_struct));

    if(gpsdata.sv_in_view_num > MTK_GPS_SV_MAX_NUM)
    {
        return -1;
    }
    gpgsv_data.Satellites_In_View = gpsdata.sv_in_view_num;

    for(i = 0; i < gpsdata.sv_in_view_num; i++)
    {
        if(gpsdata.sv_in_view_elev[i] > -5)
        {
            gpgsv_data.Satellite_ID[i] = gpsdata.sv_in_view_prn_list[i];
            gpgsv_data.Elevation[i] = gpsdata.sv_in_view_elev[i];
            gpgsv_data.Azimuth[i] = gpsdata.sv_in_view_azim[i];
        }
        else
        {
            gpgsv_data.Satellite_ID[i] = gpsdata.sv_in_view_prn_list[i];
        }

        if(gpsdata.sv_in_view_snr[i] > 0)
        {
            gpgsv_data.SNR[i] = gpsdata.sv_in_view_snr[i];
        }
    }

    return 1;
}

/******************************************************************************
 *  Function    -  gps_DataRMC
 *
 *  Purpose     -  GPS数据RMC部分解析
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 17-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static kal_int8 gps_DataRMC(mtk_gps_position gpsdata)
{
    memset(&gprmc_data, 0, sizeof(gps_gprmc_struct));

    gprmc_data.Date_Time.nYear = gpsdata.utc_time.year + 1900;
    gprmc_data.Date_Time.nMonth = gpsdata.utc_time.month + 1;
    gprmc_data.Date_Time.nDay = gpsdata.utc_time.mday;
    gprmc_data.Date_Time.nHour = gpsdata.utc_time.hour;
    gprmc_data.Date_Time.nMin = gpsdata.utc_time.min;
    gprmc_data.Date_Time.nSec = gpsdata.utc_time.sec;

    gprmc_data.status = (gpsdata.fix_type >= MTK_GPS_FIX_TYPE_2D ? 1 : 0);
    gprmc_data.Latitude = ((gpsdata.LLH[0] >= .0) ? gpsdata.LLH[0] : -gpsdata.LLH[0]);
    gprmc_data.NS = ((gpsdata.LLH[0] >= .0) ? 'N' : 'S');
    gprmc_data.Longitude = ((gpsdata.LLH[1] >= .0) ? gpsdata.LLH[1] : -gpsdata.LLH[1]);
    gprmc_data.EW = ((gpsdata.LLH[1] >= .0) ? 'E' : 'W');

    gprmc_data.Speed = gpsdata.gspeed * 3.6;           // m/s -> km/h
    gprmc_data.Course = gpsdata.heading;

    gprmc_data.Mode = (gpsdata.fix_type >= MTK_GPS_FIX_TYPE_2D ?
                       (gpsdata.fix_quality == MTK_GPS_FIX_Q_DGPS ? 'D' : 'A') :
                           (gpsdata.fix_quality == MTK_GPS_FIX_Q_EST ? 'E' : 'N'));

    return 1;
}

#if 0
/******************************************************************************
 *  Function    -  GPS_Data_Decode
 *
 *  Purpose     -  GPS 数据解码
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 17-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
__inline void GPS_Data_Decode(mtk_gps_position gpsdata)
{
    static kal_uint16 count = 0;
    track_check_tick(0, NULL);
    gps_DataGGA(gpsdata);
    gps_DataGSA(gpsdata);
    gps_DataGSV(gpsdata);
    gps_DataRMC(gpsdata);
    gps_DataVTG(gpsdata);

    //一次完整的解码结束
#if defined (GPS_DECODE_DEBUG)
    count++;
    if(count >= 600)
    {
        count = 0;
        LOGC(L_DRV, L_V5, "gps decode 600 times");
    }
#endif /* GPS_DECODE_DEBUG */

    track_gps_data_decode_backup(GPS);

    return;
}

__inline void GPS_Data_Decode3(track_gps_data_struct gpsdata)
{
    static kal_uint16 count = 0;
    track_check_tick(0, NULL);

//GPS
    memset(&gpgga_data, 0, sizeof(gps_gpgga_struct));
    memset(&gpgsa_data, 0, sizeof(gps_gpgsa_struct));
    memset(&gpgsv_data, 0, sizeof(gps_gpgsv_struct));
    memset(&gprmc_data, 0, sizeof(gps_gprmc_struct));
    memset(&gpvtg_data, 0, sizeof(gps_gpvtg_struct));
//BD
    memset(&bdgga_data, 0, sizeof(gps_gpgga_struct));
    memset(&bdgsa_data, 0, sizeof(gps_gpgsa_struct));
    memset(&bdgsv_data, 0, sizeof(gps_gpgsv_struct));
    memset(&bdrmc_data, 0, sizeof(gps_gprmc_struct));
    memset(&bdvtg_data, 0, sizeof(gps_gpvtg_struct));

    memcpy(&gpgga_data, &gpsdata.gpgga, sizeof(gps_gpgga_struct));
    memcpy(&gpgsa_data, &gpsdata.gpgsa, sizeof(gps_gpgsa_struct));
    memcpy(&gpgsv_data, &gpsdata.gpgsv, sizeof(gps_gpgsv_struct));
    memcpy(&gprmc_data, &gpsdata.gprmc, sizeof(gps_gprmc_struct));
    memcpy(&gpvtg_data, &gpsdata.gpvtg, sizeof(gps_gpvtg_struct));

    memcpy(&bdgga_data, &gpsdata.bdgga, sizeof(gps_gpgga_struct));
    memcpy(&bdgsa_data, &gpsdata.bdgsa, sizeof(gps_gpgsa_struct));
    memcpy(&bdgsv_data, &gpsdata.bdgsv, sizeof(gps_gpgsv_struct));
    memcpy(&bdrmc_data, &gpsdata.bdrmc, sizeof(gps_gprmc_struct));
    memcpy(&bdvtg_data, &gpsdata.bdvtg, sizeof(gps_gpvtg_struct));

    //一次完整的解码结束
#if defined (GPS_DECODE_DEBUG)
    count++;
    if(count >= 600)
    {
        count = 0;
        LOGC(L_DRV, L_V5, "gps decode 600 times");
    }
#endif /* GPS_DECODE_DEBUG */

    track_gps_data_decode_backup(gpsdata.gw_mode);

    return;
}



/******************************************************************************
 *  Function    -  GPS_NMEA_Decode_req
 *
 *  Purpose     -  GPS定位点结构体分解
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 17-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void GPS_NMEA_Decode_req(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_nmea_decode_req_struct *localBuff_p = (gps_nmea_decode_req_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    GPS_Data_Decode(localBuff_p->pData);
}

//3333模拟3336发解码的结构体到MMI
void GPS_NMEA_Decode_req2(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gps_nmea_decode_req_struct2 *localBuff_p = (gps_nmea_decode_req_struct2*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    GPS_Data_Decode3(localBuff_p->pData);
}
#endif


/******************************************************************************
 *  Function    -  track_gps_data_decode_backup
 *
 *  Purpose     -  一次解码完成
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 03-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_gps_data_decode_backup(enum_gps_mode gps_working)
{
    static BOOL first = TRUE;
    static kal_uint8 cnt = 0;

    memset(&track_gps_data, 0, sizeof(track_gps_data_struct));
    memcpy(&track_gps_data.gpgga, &gpgga_data, sizeof(gps_gpgga_struct));
    memcpy(&track_gps_data.gpgsa, &gpgsa_data, sizeof(gps_gpgsa_struct));
    memcpy(&track_gps_data.gpgsv, &gpgsv_data, sizeof(gps_gpgsv_struct));
    memcpy(&track_gps_data.gprmc, &gprmc_data, sizeof(gps_gprmc_struct));
    memcpy(&track_gps_data.gpvtg, &gpvtg_data, sizeof(gps_gpvtg_struct));
    track_gps_data.gw_mode = gps_working;

    memcpy(&track_gps_data.bdgga, &bdgga_data, sizeof(gps_gpgga_struct));
    memcpy(&track_gps_data.bdgsa, &bdgsa_data, sizeof(gps_gpgsa_struct));
    memcpy(&track_gps_data.bdgsv, &bdgsv_data, sizeof(gps_gpgsv_struct));
    memcpy(&track_gps_data.bdrmc, &bdrmc_data, sizeof(gps_gprmc_struct));
    memcpy(&track_gps_data.bdvtg, &bdvtg_data, sizeof(gps_gpvtg_struct));


#if defined (__GPS_UART__) || defined (__GPS_MT3333__)
    /*过滤前3秒的定位数据，精度差       --    chengjun  2017-07-12*/
    if(track_gps_data.gprmc.status != 0 || track_gps_data.bdrmc.status)
    {
        if(cnt < 4)
        {
            track_gps_data.status = 0;
            cnt++;
        }
        else if(BD == track_gps_data.gw_mode)
        {
            track_gps_data.status = bdgsa_data.status;
        }
        else
        {
            track_gps_data.status = gpgsa_data.status;
        }
    }
    else
    {
        cnt = 0;
        track_gps_data.status = 0;
    }
#else
    track_gps_data.status = gpgsa_data.status;
#endif

    if((gpgsa_data.status == 2) || (gpgsa_data.status == 3) || (bdgsa_data.status == 2) || (bdgsa_data.status == 3))
    {
        track_drv_cal_secset(2);
        track_drv_test_gps_fix_time();
        //应用层接口
        track_drv_gps_decode_ttff(); //本次开启GPS 首次定位时间TTFF
        track_cust_gps_location_time(2);
    }

    if((track_gps_data.status == 2) || (track_gps_data.status == 3))
    {

        if(first)
        {
            first = FALSE;
            track_fun_update_time_to_system(1, (BD == track_gps_data.gw_mode ? &bdrmc_data.Date_Time : &gprmc_data.Date_Time));
        }
        track_gps_epo.valid = KAL_TRUE;
        track_gps_epo.altitude = gpgga_data.msl_altitude;
        memcpy(&track_gps_epo.gprmc, &gprmc_data, sizeof(gps_gprmc_struct));
    }

    track_drv_gps_decode_done(&track_gps_data);
}

void GPS_NEMA_Decode_req3(void *msg)
{
    gps_nema_req_string *gstr = (gps_nema_req_string*)msg;
    kal_uint8 *buf = (kal_uint8*)gstr + sizeof(gps_nema_req_string);
    track_uart_decode(buf, gstr->len);
    LOGD(L_DRV, L_V7, "len %d", gstr->len);
}

/******************************************************************************
 *  Function    -  GPS_MSG_NMEA_Decode_req
 *
 *  Purpose     -  GPS解码请求
 *
 *  Description -  发送定位点结构体，直接使用
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 17-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void GPS_MSG_NMEA_Decode_req(mtk_gps_position * pvt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    gps_nmea_decode_req_struct *ind_p = NULL;
    static kal_uint16 count = 0;
    static kal_uint32 times;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(pvt == NULL)
    {
        return;
    }
#if defined (GPS_DECODE_DEBUG)
    count++;
    if(count >= 4200)
    {
        count = 0;
        LOGC(L_DRV, L_V2, "decode req 4200 times");
    }
#endif /* GPS_DECODE_DEBUG */

    ind_p = (gps_nmea_decode_req_struct*)construct_local_para(sizeof(gps_nmea_decode_req_struct), TD_CTRL);
    if(ind_p == NULL)
    {
        track_cust_restart(52, 0);
    }
    memset(&(ind_p->pData), 0, sizeof(mtk_gps_position));       //sizeof(mtk_gps_position)=416
    memcpy(&(ind_p->pData), pvt, sizeof(mtk_gps_position));

    ilm_ptr = (ilm_struct *)allocate_ilm(MOD_MNL);
    if(ilm_ptr == NULL)
    {
        track_cust_restart(53, 0);
    }
    ilm_ptr->src_mod_id = MOD_MNL;
    ilm_ptr->dest_mod_id = MOD_MMI;
    ilm_ptr->sap_id = INVALID_SAP;
    ilm_ptr->msg_id = MSG_ID_GPS_NMEA_DECODE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*)ind_p;
    ilm_ptr->peer_buff_ptr = NULL;
    msg_send_ext_queue(ilm_ptr);
    //LOGD(L_DRV, L_V9, "send count=%d", times++);
}

void track_drv_set_gps_glp_mode(U8 arg)
{
#if 1
    kal_uint8 length, GLen ;
    U8 g_mode = (U8)arg;
    char *GLP[2] = {"$PMTK262,0*28\r\n", "$PMTK262,3*2B\r\n"};
    if(g_mode > 2)
    {
        LOGD(L_DRV, L_V5, "max lend 2");
        return;
    }
    length = strlen((char*)GLP[g_mode]);
    U_PutUARTBytes(GPS_UART_PORT, GLP[g_mode], length);
    //LOGD(L_DRV, L_V6, "%s mode:%d",GLP[g_mode], g_mode);
    LOGS("%s", GLP[g_mode]);
    track_start_timer(TRACK_DRV_GLP_DELAY_TIMER_ID, 5000, track_Drv_gps_glp_Set, (void *)1);
#endif
}
/******************************************************************************
 *  Function    -  track_gps_data_clean
 *
 *  Purpose     -  GPS 关闭后清空数据
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 16-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_gps_data_clean(void)
{
    //track_gps_data.status=0;
    memset(&track_gps_data, 0, sizeof(track_gps_data_struct));
    memset(&gpgga_data, 0, sizeof(gps_gpgga_struct));
    memset(&gpgsa_data, 0, sizeof(gps_gpgsa_struct));
    memset(&gpgsv_data, 0, sizeof(gps_gpgsv_struct));
    memset(&gprmc_data, 0, sizeof(gps_gprmc_struct));
    memset(&gpvtg_data, 0, sizeof(gps_gpvtg_struct));

    memset(&bdgga_data, 0, sizeof(gps_gpgga_struct));
    memset(&bdgsa_data, 0, sizeof(gps_gpgsa_struct));
    memset(&bdgsv_data, 0, sizeof(gps_gpgsv_struct));
    memset(&bdrmc_data, 0, sizeof(gps_gprmc_struct));
    memset(&bdvtg_data, 0, sizeof(gps_gpvtg_struct));
}

/******************************************************************************
 *  Function    -  track_drv_get_gps_**
 *
 *  Purpose     -  读取GPS 解析后的数据
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 27-07-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/

gps_gpgga_struct * track_drv_get_gps_GGA(void)
{
    return &track_gps_data.gpgga;
}

gps_gpgsa_struct * track_drv_get_gps_GSA(void)
{
    return &track_gps_data.gpgsa;
}

gps_gpgsv_struct * track_drv_get_gps_GSV(void)
{
    return &track_gps_data.gpgsv;
}

gps_gprmc_struct* track_drv_get_gps_RMC(void)
{
    return &track_gps_data.gprmc;
}

gps_gpvtg_struct * track_drv_get_gps_VTG(void)
{
    return &track_gps_data.gpvtg;
}

track_gps_epo_struct * track_drv_get_gps_epo(void)
{
    return &track_gps_epo;
}

track_gps_data_struct * track_drv_get_gps_data(void)
{
    return &track_gps_data;
}


gps_gpgga_struct * track_drv_get_bd_GGA(void)
{
    return &track_gps_data.bdgga;
}

gps_gpgsa_struct * track_drv_get_bd_GSA(void)
{
    return &track_gps_data.bdgsa;
}

gps_gpgsv_struct * track_drv_get_bd_GSV(void)
{
    return &track_gps_data.bdgsv;
}

gps_gprmc_struct* track_drv_get_bd_RMC(void)
{
    return &track_gps_data.bdrmc;
}

gps_gpvtg_struct * track_drv_get_bd_VTG(void)
{
    return &track_gps_data.bdvtg;
}
void track_Drv_gps_glp_Set(void* op)
{
    U8 in = (U8)op;
    LOGD(L_GPS, L_V1, "5秒等待时间到，还未回复执行成功，重新发GLP指令!");
    track_drv_set_gps_glp_mode(in);
}
/******************************************************************************
 *  Function    -  hunan_getDateTimeString
 *
 *  Purpose     -  将GPS的字符串日期时间进行转换
 *
 *  PARAMETERS  -
 *      date               [IN]         例如: 021210
 *      time               [IN]         例如: 000546
 *  RETURN
 *
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 14-05-2011,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void Get_GPS_DateTime(char *date, char *time)
{
    MYTIME dt = {0};
    char temp[16] = {0};

    if(strlen(date) < 6 || strlen(time) < 6)
    {
        return;
    }

    memset(temp, 0, sizeof(temp));
    memcpy(temp, date, 2);
    dt.nDay   = atoi(temp);
    memcpy(temp, date + 2, 2);
    dt.nMonth = atoi(temp);
    memcpy(temp, date + 4, 2);
    dt.nYear  = 2000 + atoi(temp);
    memcpy(temp, time, 2);
    dt.nHour  = atoi(temp);
    memcpy(temp, time + 2, 2);
    dt.nMin   = atoi(temp);
    memcpy(temp, time + 4, 2);
    dt.nSec   = atoi(temp);
    memcpy(&gprmc_data.Date_Time, &dt, sizeof(MYTIME));
}
static float Get_GPS_Degrees(char *dm)
{
    char Buff[100];
    float f;
    int i;
    f = atof(dm);
    i = f / 100;
    f = (f - i * 100) / 60 + i;
    sprintf(Buff, "%f", f);
    return f;
}

/******************************************************************************
 *  Function    -  gps_nmea_analyse
 *
 *  Purpose     -  nmea数据流分段
 *
 *  Description -  str_data 	：需要拆分的字符串
 *                       tar_data	：拆分后用来放入分段数据指针数组
 *                       limit		：数组长度
 *  return
 *           >  0      正确分割后的段数
 *          <= 0      错误
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 20-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static kal_int16 gps_nmea_analyse(char *str_data, char **tar_data, int limit)
{
    static char *blank = {""};
    int len, i, j;
    char *p;

    if(!str_data)
    {
        return -1;
    }
    if(strchr(str_data, '*') == NULL)
    {
        return -2;
    }

    p = strchr(str_data, '$');
    if(!p)
    {
        return -3;
    }

    tar_data[0] = p;
    len = strlen(p);
    if((len > 200) || (len <= 0))
    {
        return -4;
    }

    for(i = 0, j = 1; i < len; i++, p++)
    {
        if(*p == '*')
        {
            *p = 0;
            break;
        }
        if(*p == ',')
        {
            *p = 0;

            if(*(p + 1) == '*' || *(p + 1) == ',')
            {
                tar_data[j++] = blank;
            }
            else
            {
                tar_data[j++] = p + 1;
            }
            if(j >= limit)
            {
                return -5;
            }
        }
    }

    for(i = j; i < limit; i++)
    {
        tar_data[i] = blank;
    }
    return j;
}
/******************************************************************************
 *  Function    -  gps_cmd_data
 *
 *  Purpose     -  GPS 内部指令
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-08-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
extern nvram_realtime_struct  G_realtime_data;

static kal_int8 gps_cmd_data(enum_gps_mode gw_mode, char* Data_p)
{
    LOGD(L_DRV, L_V8, "%s", Data_p);
#if defined __SECOND_SET__
    if(strstr(Data_p, "$PMTK001,740,3") != NULL)
    {
        LOGD(L_GPS, L_V5, "秒定功能参考时间 注入成功", Data_p);
        if(!track_is_timer_run(TRACK_CUST_GPS_SECSET_AIDING_TIMER_ID) && !track_is_timer_run(TRACK_DRV_ACTIVE_REFTIME_TIMER_ID) && G_parameter.agps.sw)
        {
            tr_start_timer(TRACK_CUST_GPS_SECSET_AIDING_TIMER_ID, 100, track_drv_epo_aid_interface);//避免重复注入
        }
    }
    else if(strstr(Data_p, "$PMTK001,741,3") != NULL)
    {
        LOGD(L_GPS, L_V5, "秒定功能注入参考位置成功! %s", Data_p);
        track_drv_cal_secset(3);
    }
    else if(strstr(Data_p, "$PMTK001,713,3") != NULL)
    {
        LOGD(L_GPS, L_V5, "秒定功能 713注入参考位置成功! %s", Data_p);
        track_drv_cal_secset(3);
    }
    else if(strstr(Data_p, "$PMTK001,741,2") != NULL)
    {
        LOGD(L_GPS, L_V5, "秒定功能注入参考位置失败! %s", Data_p);
    }
    else if(strstr(Data_p, "$PMTK001,713,2") != NULL)
    {
        LOGD(L_GPS, L_V5, "秒定功能713注入参考位置失败! %s", Data_p);
    }
    else if(strstr(Data_p, "$PMTK001,721,3,20") != NULL)
    {
        LOGD(L_GPS, L_V5, "秒定功能注入EPO完成!");
        if(G_parameter.agps.sw)
        {
            tr_start_timer(TRACK_CUST_GPS_SECSET_TIMER_ID, 200, track_cust_secset_interface);
        }
    }
#else
    if(strstr(Data_p, "$PMTK010,002") != NULL)
    {
        track_drv_gps_epo_start();
    }
#endif
    if(strstr(Data_p, "$PMTK010,001") != NULL)
    {
#if defined (__GT300S__) || defined(__GT370__)|| defined (__GT380__)
        if(G_realtime_data.glp)
        {
            if(!track_is_timer_run(TRACK_DRV_GLP_DELAY_TIMER_ID))
            {
                track_drv_set_gps_glp_mode(1);
            }
        }
#else
        if(G_realtime_data.glp)
        {
            track_drv_set_gps_glp_mode(1);
        }
#endif
    }
    else if(strstr(Data_p, "$PMTK001,262,3,3") != NULL)
    {
        LOGD(L_GPS, L_V5, "GLP 执行成功! %s", Data_p);
        track_stop_timer(TRACK_DRV_GLP_DELAY_TIMER_ID);
        if(track_is_testmode())
        {
            LOGS("GLP 执行成功! ");

        }
    }
    else if(strstr(Data_p, "$PMTK001,262,3,2") != NULL)
    {
        if(track_is_testmode())
        {
            LOGS("GLP 执行失败! ");

        }
        LOGD(L_GPS, L_V5, "GLP 执行失败! %s", Data_p);
    }
    return 1;
}



/******************************************************************************
 *  Function    -  gps_DataZDA
 *
 *  Purpose     -  GPS数据ZDA部分解析
 *
 *  Description -  NC --MT3336 不支持
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 07-03-2012,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
static kal_int8 gps_DataZDA2(enum_gps_mode gw_mode, char* Data_p)
{
    char Data_Temp[200] = {0};
    char  *gps_data[30];
    kal_int16 part;
    kal_uint8 temp[50] = {0};

    strncpy(Data_Temp, Data_p, 199);
    memset(&gpzda_data, 0, sizeof(gps_gpzda_struct));
    part = gps_nmea_analyse(Data_Temp, gps_data, 30);
    if(part <= 0)
    {
        return part;
    }

    memcpy(temp, gps_data[5], 2);
    gpzda_data.Date_Time.nHour = atoi((char*)temp);
    memcpy(temp, gps_data[5] + 2, 2);
    gpzda_data.Date_Time.nMin = atoi((char*)temp);
    memcpy(temp, gps_data[5] + 4, 2);
    gpzda_data.Date_Time.nSec = atoi((char*)temp);

    gpzda_data.Date_Time.nDay = atoi((char*)gps_data[2]);
    gpzda_data.Date_Time.nMonth = atoi((char*)gps_data[3]);
    gpzda_data.Date_Time.nYear = atoi((char*)gps_data[4]);
    gpzda_data.Local_zone_hour = atoi((char*)gps_data[5]);
    gpzda_data.Local_zone_minutes = atoi((char*)gps_data[6]);

    return 1;
}


/******************************************************************************
 *  Function    -  gps_DataGLL
 *
 *  Purpose     -  GPS数据GLL部分解析
 *
 *  Description -  NC--MT3336 不支持
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 07-03-2012,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
static kal_int8 gps_DataGLL2(enum_gps_mode gw_mode, char* Data_p)
{
    char Data_Temp[200] = {0};
    char  *gps_data[30];
    kal_int16 part;
    kal_uint8 temp[50] = {0};

    strncpy(Data_Temp, Data_p, 199);
    memset(&gpgll_data, 0, sizeof(gps_gpgll_struct));
    part = gps_nmea_analyse(Data_Temp, gps_data, 30);
    if(part <= 0)
    {
        return part;
    }

    gpgll_data.Latitude = Get_GPS_Degrees(gps_data[1]);
    gpgll_data.Longitude = Get_GPS_Degrees(gps_data[3]);
    gpgll_data.NS = gps_data[2][0];
    gpgll_data.EW = gps_data[4][0];
    memcpy(temp, gps_data[5], 2);
    gpgll_data.nHour = atoi((char*)temp);
    memcpy(temp, gps_data[5] + 2, 2);
    gpgll_data.nMin = atoi((char*)temp);
    memcpy(temp, gps_data[5] + 4, 2);
    gpgll_data.nSec = atoi((char*)temp);
    gpgll_data.Status = gps_data[6][0] ;
    gpgll_data.Mode = gps_data[7][0];

    return 1;
}


/******************************************************************************
 *  Function    -  gps_DataMSS
 *
 *  Purpose     -  GPS数据MSS部分解析
 *
 *  Description -  NC--MT3326不支持
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 07-03-2012,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
static kal_int8 gps_DataMSS2(enum_gps_mode gw_mode, char* Data_p)
{
    char Data_Temp[200];
    char  *gps_data[30];
    kal_int16 part;

    strncpy(Data_Temp, Data_p, 199);
    memset(&gpmss_data, 0, sizeof(gps_gpmss_struct));
    part = gps_nmea_analyse(Data_Temp, gps_data, 30);
    if(part <= 0)
    {
        return part;
    }

    gpmss_data.Signal_Strength = (U8)atoi((char*)gps_data[1]);
    gpmss_data.Signal_Ratio = (U8)atoi((char*)gps_data[2]);
    gpmss_data.Beacon_Frequency = atof((char*)gps_data[3]);
    gpmss_data.Beacon_Bit_Rate = (U8)atoi((char*)gps_data[4]);
    gpmss_data.Channel_Number = gps_data[5][0] - '0';

    return 1;
}


/******************************************************************************
 *  Function    -  gps_DataVTG
 *
 *  Purpose     -  GPS数据VTG部分解析
 *
 *  Description -   10 段
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 07-03-2012,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
static kal_int8 gps_DataVTG2(enum_gps_mode gw_mode, char* Data_p)
{
    char Data_Temp[200] = {0};
    char  *gps_data[30];
    kal_int16 part;
    gps_gpvtg_struct * gpvtg ;

    if(BD == gw_mode)
    {
        memset(&bdvtg_data, 0, sizeof(gps_gpvtg_struct));
        gpvtg = &bdvtg_data;
    }
    else if(GPS <= gw_mode)
    {
        memset(&gpvtg_data, 0, sizeof(gps_gpvtg_struct));
        gpvtg = &gpvtg_data;
    }
    else
    {
        return -1;
    }

    strncpy(Data_Temp, Data_p, 199);
    part = gps_nmea_analyse(Data_Temp, gps_data, 30);
    if(part <= 0)
    {
        return part;
    }
    if(part != 10)
    {
        return -6;
    }

    gpvtg->Course0 = atof((char*)gps_data[1]);
    gpvtg->Reference0 = gps_data[2][0];
    gpvtg->Course1 = atof((char*)gps_data[3]);
    gpvtg->Reference1 = gps_data[4][0];
    gpvtg->Speed0 = atof((char*)gps_data[5]);
    gpvtg->Units0 = gps_data[6][0];
    gpvtg->Speed1 = atof((char*)gps_data[7]);
    gpvtg->Units1 = gps_data[8][0];
    gpvtg->Mode = gps_data[9][0];

    return 1;
}


/******************************************************************************
 *  Function    -  gps_DataGGA
 *
 *  Purpose     -  GPS数据GGA部分解析
 *
 *  Description -  15 段
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 07-03-2012,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
static kal_int8 gps_DataGGA2(enum_gps_mode gw_mode, char* Data_p)
{
    char Data_Temp[200] = {0};
    char  *gps_data[30];
    kal_int16 part;
    kal_uint8 temp[10] = {0};
    gps_gpgga_struct * gpgga ;

    if(BD == gw_mode)
    {
        memset(&bdgga_data, 0, sizeof(gps_gpgga_struct));
        gpgga = &bdgga_data;
    }
    else if(GPS <= gw_mode)
    {
        memset(&gpgga_data, 0, sizeof(gps_gpgga_struct));
        gpgga = &gpgga_data;
    }
    else
    {
        return -1;
    }

    strncpy(Data_Temp, Data_p, 199);

    part = gps_nmea_analyse(Data_Temp, gps_data, 30);
    if(part <= 0)
    {
        return part;
    }
    if(part != 15)
    {
        return -6;
    }

    memcpy(temp, gps_data[1], 2);
    gpgga->nHour = atoi((char*)temp);
    memcpy(temp, gps_data[1] + 2, 2);
    gpgga->nMin = atoi((char*)temp);
    memcpy(temp, gps_data[1] + 4, 2);
    gpgga->nSec = atoi((char*)temp);
    gpgga->Latitude = Get_GPS_Degrees(gps_data[2]);
    gpgga->Longitude = Get_GPS_Degrees(gps_data[4]);
    gpgga->NS = gps_data[3][0];
    gpgga->EW = gps_data[5][0];
    gpgga->posi_fix = gps_data[6][0] - '0';
    gpgga->sat = atoi(gps_data[7]);
    gpgga->HDOP = atof(gps_data[8]);
    gpgga->msl_altitude = atof(gps_data[9]);
    gpgga->Units1 = gps_data[10][0];
    gpgga->Geoid_Altitude = atof(gps_data[11]);
    gpgga->Units2 = gps_data[12][0];
    gpgga->Age = atof(gps_data[13]);
    gpgga->station_ID = atoi(gps_data[14]);

    return 1;
}
/******************************************************************************
 *  Function    -  gps_DataGSA
 *
 *  Purpose     -  GPS数据GSA部分解析
 *
 *  Description -  18 段
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 07-03-2012,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
static kal_int8 gps_DataGSA2(enum_gps_mode gw_mode, char* Data_p)
{
    char Data_Temp[200] = {0};
    char  *gps_data[30];
    kal_int16 part, i;
    gps_gpgsa_struct * gpgsa ;

    if(BD == gw_mode)
    {
        memset(&bdgsa_data, 0, sizeof(gps_gpgsa_struct));
        gpgsa = &bdgsa_data;
    }
    else if(GPS == gw_mode)
    {
        memset(&gpgsa_data, 0, sizeof(gps_gpgsa_struct));
        gpgsa = &gpgsa_data;
    }
    else
    {
        return -1;
    }
    strncpy(Data_Temp, Data_p, 199);

    part = gps_nmea_analyse(Data_Temp, gps_data, 30);
    if(part <= 0)
    {
        return part;
    }
    if(part != 18)
    {
        return -6;
    }

    gpgsa->mode = gps_data[1][0];
    gpgsa->status = gps_data[2][0] - '0';
    for(i = 0; i < 12; i++)
    {
        gpgsa->satellite_used[i] = atoi(gps_data[i+3]);
    }
    gpgsa->PDOP = atof(gps_data[15]);
    gpgsa->HDOP = atof(gps_data[16]);
    gpgsa->VDOP = atof(gps_data[17]);

    return 1;
}

/******************************************************************************
 *  Function    -  gps_DataGSV
 *
 *  Purpose     -  GPS数据GSV部分解析
 *
 *  Description -   8、16、20 段 居多
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 07-03-2012,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
static kal_int8 gps_DataGSV2(enum_gps_mode gw_mode, char* Data_p)
{
    char Data_Temp[200] = {0};
    char  *gps_data[30];
    kal_int16 part ;
    kal_uint8 i, satind;
    gps_gpgsv_struct * gpgsv ;

    if(BD == gw_mode)
    {
        gpgsv = &bdgsv_data;
    }
    else if(GPS == gw_mode)
    {
        gpgsv = &gpgsv_data;
    }
    else
    {
        return -1;
    }

    strncpy(Data_Temp, Data_p, 199);
    part = gps_nmea_analyse(Data_Temp, gps_data, 30);

    if(part <= 0)
    {
        return part;
    }
    if((part % 4) != 0)
        //part 值与卫星数有关
    {
        return -6;
    }

    if(strlen((char*) gps_data[2]) == 1)
    {
        gpgsv->index = gps_data[2][0] - '0';
        if(gpgsv->index == 1)
        {
            memset((void *)gpgsv, 0, sizeof(gps_gpgsv_struct));
            gpgsv->index = 1;
        }
    }
    else
    {
        return -7;
    }

    satind = (gpgsv->index - 1) * 4;
    if(satind > MTK_GPS_SV_MAX_NUM)
    {
        LOGD(L_DRV, L_V9, "satind=%d", satind);
        return -8;
    }

    gpgsv->Number_Of_Messages = gps_data[1][0] - '0';
    gpgsv->Satellites_In_View = atoi(gps_data[3]);

    for(i = 0; i < 4; i++)
    {
        gpgsv->Satellite_ID[satind] = atoi(gps_data[i*4+4]);
        gpgsv->Elevation[satind] = atoi(gps_data[i*4+5]);
        gpgsv->Azimuth[satind] = atoi(gps_data[i*4+6]);
        gpgsv->SNR[satind] = atoi(gps_data[i*4+7]);
        LOGD(L_DRV, L_V9, "gpgsv_data.SNR[satind]=%d", gpgsv->SNR[satind]);
        satind++;
    }
    return 1;
}

/******************************************************************************
 *  Function    -  gps_DataRMC
 *
 *  Purpose     -  GPS数据RMC部分解析
 *
 *  Description -  13 段
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 07-03-2012,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
static kal_int8 gps_DataRMC2(enum_gps_mode gw_mode, char* Data_p)
{
    char Data_Temp[200] = {0};
    char  *gps_data[30];
    kal_int16 part;
    gps_gprmc_struct * gprmc ;

    if(BD == gw_mode)
    {
        memset(&bdrmc_data, 0, sizeof(gps_gprmc_struct));
        gprmc = &bdrmc_data;
    }
    else if(GPS <= gw_mode)
    {
        memset(&gprmc_data, 0, sizeof(gps_gprmc_struct));
        gprmc = &gprmc_data;
    }
    else
    {
        return -1;
    }
    gps_working = gw_mode;
    strncpy(Data_Temp, Data_p, 199);
    part = gps_nmea_analyse(Data_Temp, gps_data, 30);

    if(part <= 0)
    {
        return part;
    }
    if(part != 13)
    {
        return -6;
    }

    Get_GPS_DateTime(gps_data[9], gps_data[1]);

    if(gps_data[2][0] == 'A')
    {
        gprmc->status = KAL_TRUE;
    }
    else
    {
        gprmc->status = KAL_FALSE;
    }

    gprmc->Latitude = Get_GPS_Degrees(gps_data[3]);
    gprmc->NS = gps_data[4][0];
    gprmc->Longitude = Get_GPS_Degrees(gps_data[5]);
    gprmc->EW = gps_data[6][0];
    gprmc->Speed = (atof(gps_data[7])) * 1.852; // 1 海里= 1.85200 公里
    gprmc->Course = atof(gps_data[8]);
    gprmc->Magnetic_variation2 = gps_data[10][0];
    gprmc->Indicater2 = gps_data[11][0];
    gprmc->Mode = gps_data[12][0];

    return 1;
}



static BOOL asciitohex(char str, U8* data)
{
    if((str <= '9') && (str >= '0'))
    {
        *data = str - '0';
        return TRUE;
    }
    else if((str <= 'z') && (str >= 'a'))
    {
        *data = str - 'a' + 10;
        return TRUE;
    }
    else  if(str <= 'Z' && (str >= 'A'))
    {
        *data = str - 'A' + 10;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/******************************************************************************
 *  Function    -  gps_nmea_crc_check
 *
 *  Purpose     -  数据流校验
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 24-07-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static kal_int8 gps_nmea_crc_check(char* data, U16 len)
{
    int  crc = 0, checkSum = 0;
    U8 temp0, temp1;
    char *head = NULL, *end = NULL, *p_data = NULL;

    if(!data)
    {
        return -1;
    }

    head = strchr(data, '$');
    end = strchr(data, '*');

    if((head == NULL) || (end == NULL))
    {
        return -2;
    }

    if(((end - data) + 5) != len)
    {
        LOGD(L_DRV, L_V6, "len=%d,(end-data)+5)=%d", len, (end - data) + 5);
        return -3;
    }

    p_data = head + 1;
    while(*p_data != '*')
    {
        checkSum ^= *p_data;
        p_data += 1;
    }

    if((asciitohex(*(p_data + 1), &temp0)) && (asciitohex(*(p_data + 2), &temp1)))
    {
        crc = temp0 * 16 + temp1;
    }

    if(crc == checkSum)
    {
        return 1;
    }
    else
    {
        return -4;
    }
}

static GPS_Decode_struct  GPS_Decode[] =
{
    {"$GPGGA", gps_DataGGA2, GPS},
    {"$GPGSA", gps_DataGSA2, GPS},
    {"$GPGSV", gps_DataGSV2, GPS},
    {"$GPRMC", gps_DataRMC2, GPS},
    {"$GPVTG", gps_DataVTG2, GPS},
    {"$PMTK",  gps_cmd_data, GN},
    {"$GNGGA", gps_DataGGA2, GN},
    {"$GNVTG", gps_DataVTG2, GN},
    {"$GNRMC", gps_DataRMC2, GN},
    {"$BDGGA", gps_DataGGA2, BD},
    {"$BDGSA", gps_DataGSA2, BD},
    {"$BDGSV", gps_DataGSV2, BD},
    {"$BDRMC", gps_DataRMC2, BD},
    {"$BDVTG", gps_DataVTG2, BD},
    {NULL, NULL}
};

#define GPS_DECODE_ITEM_SIZE  (sizeof(GPS_Decode) / sizeof(GPS_Decode_struct))



/******************************************************************************
 *  Function    -  GPS_Data_Decode
 *
 *  Purpose     -  GPS 单条数据解码 最大长度是200
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 24-07-2012,  chengjun  written
 * v1.1  , 15-11-2013,  wangqi  jiangweijun modify
 * ----------------------------------------
 ******************************************************************************/
void GPS_Data_Decode2(U8* gpsdata, U16 length)
{
    U8  i;
    char *data_p;
    kal_int8 crc = -1, decode = -9;

    if(!gpsdata)
    {
        return;
    }

    crc = gps_nmea_crc_check((char*)gpsdata, length);
    if(crc < 0)
    {
        LOGD(L_DRV, L_V9, "CRC fail (%d):%s", crc, gpsdata);
        return;
    }
    for(i = 0; i < GPS_DECODE_ITEM_SIZE; i++)
    {
        data_p = strstr((char*)gpsdata, GPS_Decode[i].cmd_string);
        if(data_p != NULL)
        {
            decode = GPS_Decode[i].FuncPtr(GPS_Decode[i].gw_mode, (char*)data_p);
            if(decode <= 0)
            {
                LOGD(L_DRV, L_V9, "GPS decode non-support (%d):%s", decode , gpsdata);
            }
            else if(!strcmp("RMC", &GPS_Decode[i].cmd_string[3]))
            {
                LOGD(L_DRV, L_V9, "一次完成 %s", gpsdata); //一次完整的解码结束
                track_gps_data_decode_backup(gps_working);
            }
            break;
        }
    }
}


/************G3333星历*****************

$GNGGA,013343.000,2306.7022,N,11424.5563,E,1,5,1.74,75.5,M,-1.5,M,,*6A
$GPGSA,A,3,23,19,16,13,27,,,,,,,,2.00,1.74,0.99*0B
$BDGSA,A,3,,,,,,,,,,,,,2.00,1.74,0.99*13
$GPGSV,3,1,10,27,82,081,33,19,57,196,34,23,56,276,32,42,50,129,28*7C
$GPGSV,3,2,10,16,45,014,31,13,39,309,31,11,10,193,24,21,07,058,24*7B
$GPGSV,3,3,10,07,04,312,24,193,,,*76
$BDGSV,1,1,00*68
$GNRMC,013343.000,A,2306.7022,N,11424.5563,E,0.38,118.94,070814,,,A*75
$GNVTG,118.94,T,,M,0.38,N,0.70,K,A*2A


$GPGGA,013332.000,2306.7053,N,11424.5547,E,1,5,1.74,74.6,M,-1.5,M,,*70
$GPGSA,A,3,27,16,19,23,13,,,,,,,,2.00,1.74,0.99*0B
$GPGSV,3,1,10,27,82,082,33,19,57,196,33,23,56,277,32,42,50,129,26*77
$GPGSV,3,2,10,16,45,014,29,13,39,309,29,11,10,193,23,21,07,058,23*7B
$GPGSV,3,3,10,07,04,312,23,193,,,*71
$GPRMC,013332.000,A,2306.7053,N,11424.5547,E,0.36,61.56,070814,,,A*52
$GPVTG,61.56,T,,M,0.36,N,0.67,K,A*0D


$BDGGA,013319.000,,,,,0,0,,,M,,M,,*50
$BDGSA,A,1,,,,,,,,,,,,,,,*0F
$BDGSV,1,1,00*68
$BDRMC,013319.000,V,,,,,0.36,221.60,070814,,,N*5D
$BDVTG,221.60,T,,M,0.36,N,0.67,K,N*20

-----------------MT3333星历--------------------------------
$GNGGA,012827.000,2306.7001,N,11424.5539,E,1,11,0.82,106.7,M,-1.5,M,,*66
$GPGSA,A,3,29,18,21,193,05,02,20,24,30,13,15,,1.08,0.82,0.71*3B
$BDGSA,A,3,,,,,,,,,,,,,1.08,0.82,0.71*16
$GPGSV,3,1,12,13,73,037,40,15,63,239,41,193,60,056,37,29,46,278,39*46
$GPGSV,3,2,12,20,46,325,39,02,43,118,41,05,39,039,39,24,14,181,28*73
$GPGSV,3,3,12,30,11,055,36,21,07,317,30,18,06,277,35,06,03,129,28*70
$BDGSV,1,1,01,03,,,29*61
$GNRMC,012827.000,A,2306.7001,N,11424.5539,E,0.00,304.77,290116,,,A*7D
$GNVTG,304.77,T,,M,0.00,N,0.00,K,A*24
$GPACCURACY,11.3*3B

$BDGGA,015139.000,2306.6994,N,11424.5638,E,1,4,2.68,130.3,M,-1.5,M,,*5D
$BDGSA,A,3,01,07,06,03,,,,,,,,,2.85,2.68,0.96*1C
$BDGSV,2,1,06,03,61,189,37,06,56,357,36,01,49,131,32,07,24,161,28*6F
$BDGSV,2,2,06,09,,,36,02,,,34*67
$BDRMC,015139.000,A,2306.6994,N,11424.5638,E,1.31,86.94,290116,,,A*42
$BDVTG,86.94,T,,M,1.31,N,2.43,K,A*19
$GPACCURACY,30.6*3D

$GNGGA,015703.000,2306.7022,N,11424.5554,E,1,8,0.98,101.0,M,-1.5,M,,*51
$GPGSA,A,3,21,13,15,24,05,02,29,20,,,,,1.31,0.98,0.86*03
$GLGSA,A,3,,,,,,,,,,,,,1.31,0.98,0.86*12
$GPGSV,3,1,09,15,71,273,34,13,59,029,35,20,49,343,35,29,44,258,34*7C
$GPGSV,3,2,09,05,34,053,32,02,32,130,34,24,25,175,31,21,17,320,25*71
$GPGSV,3,3,09,193,,,*4B
$GLGSV,1,1,00*65
$GNRMC,015703.000,A,2306.7022,N,11424.5554,E,0.31,269.56,290116,,,A*72
$GNVTG,269.56,T,,M,0.31,N,0.57,K,A*2D
$GPACCURACY,13.1*3B

-----------------GPS星历--------------------------------

$GPGGA,014110.274,2306.7044,N,11424.5548,E,1,9,0.97,101.0,M,-1.5,M,,*48
$GPGSA,A,3,11,03,16,19,13,23,27,21,07,,,,1.21,0.97,0.71*06
$GPGSV,4,1,13,27,80,059,40,03,69,230,41,19,61,197,39,23,56,270,40*7A
$GPGSV,4,2,13,16,43,018,36,13,41,306,37,31,22,111,,11,13,191,38*74
$GPGSV,4,3,13,21,06,055,29,07,06,314,33,20,04,227,,32,04,192,*7B
$GPGSV,4,4,13,193,,,30*43
$GPRMC,014110.274,A,2306.7044,N,11424.5548,E,0.000,74.23,070814,,,A*6C
$GPVTG,74.23,T,,M,0.000,N,0.000,K,A*0F

$GPGGA,014111.272,2306.7044,N,11424.5548,E,1,9,0.97,101.0,M,-1.5,M,,*4F
$GPGSA,A,3,11,03,16,19,13,23,27,21,07,,,,1.21,0.97,0.71*06
$GPGSV,4,1,13,27,80,059,40,03,69,230,41,19,61,197,39,23,56,270,40*7A
$GPGSV,4,2,13,16,43,018,36,13,41,306,37,31,22,111,,11,13,191,38*74
$GPGSV,4,3,13,21,06,055,29,07,06,314,33,20,04,227,,32,04,192,*7B
$GPGSV,4,4,13,193,,,31*42
$GPRMC,014111.272,A,2306.7044,N,11424.5548,E,0.000,74.23,070814,,,A*6B
$GPVTG,74.23,T,,M,0.000,N,0.000,K,A*0F



#if defined(__GPS_G3337__)
static char EDNPACK[] = "$GPRMC";
static char EDNBDPACK[] = "$GNRMC";
#else
static char EDNPACK[] = "$GPVTG";//纯GPS时出这个
static char EDNBDPACK[] = "$BDVTG";//纯北斗时出这个
#endif
static char EDNGNPACK[] = "$GNVTG";//双模时输出这个

extern kal_uint16 track_cust_set_gps_mode(int g_mode);
char* track_drv_get_gps_endsign(void)
{
    kal_uint16 gpsMode = track_cust_set_gps_mode(0xFF);
    if(0 == gpsMode)//BD
    {
        return EDNBDPACK;
    }
    else if(1 == gpsMode)GPS
    {
        return EDNPACK;
    }
    else
    {
        return EDNGNPACK;
    }
}

*******************************/
