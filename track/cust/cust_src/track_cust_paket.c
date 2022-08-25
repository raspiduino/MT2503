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
#include "track_os_ell.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/
//static char *blank = {""}, *s_ON = {"ON"}, *s_OFF = {"OFF"}, *s_Error = {"ERROR"};
//#define ON_OFF(value) (value==0?s_OFF:(value==1?s_ON:s_Error))

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static kal_uint16 g_SerialNumber = 0;

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern void track_gps_dataupload_modular(void);
extern BOOL track_terminal_sleepwork_get(void);
extern kal_uint8 track_cust_sensor_count(kal_uint8 par);
extern char *track_cust_get_version_for_upload_server(void);
extern nvram_GPRS_APN_struct *track_socket_get_use_apn(void);
extern kal_int8 track_cust_paket_FD(kal_uint8 *data, kal_uint16 len, U8 packet_type);
extern kal_bool track_drv_nvram_write_switch(kal_uint8 sw);

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
void track_cust_decode_packet_17(kal_uint8 *data, kal_uint16 len);
kal_uint16 track_cust_check_gprsdata(kal_uint32 flag, kal_uint16 sn);
extern void track_cust_paket_94(kal_uint8 datatype, kal_uint8 *data, kal_uint16 len);
U16 track_cust_lock_serial_no(int no);
#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/


/******************************************************************************
 *  Function    -  getSerialNumber
 *
 *  Purpose     -  取得流水号
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static kal_uint16 getSerialNumber()
{
    return g_SerialNumber++;
}

/******************************************************************************
 *  Function    -  DataPacketEncode78
 *
 *  Purpose     -  78协议打包
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static kal_uint16 DataPacketEncode78(U8 cmd, U8 *sendData, U8 len)
{
    U16 tmp, tmp1;

    //起始位
    sendData[0] = 0x78;
    sendData[1] = 0x78;

    //长度
    sendData[2] = len - 5;

    //协议号
    sendData[3] = cmd;

    //信息序列号
    tmp = getSerialNumber();
    sendData[len - 6] = (tmp & 0xFF00) >> 8;
    sendData[len - 5] = (tmp & 0x00FF);
    LOGD(L_APP, L_V5, "SerialNumber:%.2X%.2X", sendData[len - 6], sendData[len - 5]);

    //CRC校验
    tmp1 = GetCrc16(&sendData[2], len - 6);
    sendData[len - 4] = (tmp1 & 0xFF00) >> 8;
    sendData[len - 3] = (tmp1 & 0x00FF);

    //结束
    sendData[len - 2] = '\r';
    sendData[len - 1] = '\n';

    return tmp;
}

/******************************************************************************
 *  Function    -  DataPacking
 *
 *  Purpose     -  79协议打包
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 07-03-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static kal_uint16 DataPacketEncode79(U8 cmd, U8 *sendData, U16 len)
{
    kal_uint16 tmp, tmp1;

    //起始位
    sendData[0] = 0x79;
    sendData[1] = 0x79;

    //长度
    sendData[2] = ((len - 6) & 0xFF00) >> 8;
    sendData[3] = ((len - 6) & 0x00FF);

    //协议号
    sendData[4] = cmd;

    //信息序列号
    tmp = getSerialNumber();
    sendData[len - 6] = (tmp & 0xFF00) >> 8;
    sendData[len - 5] = (tmp & 0x00FF);
    LOGD(L_APP, L_V5, "SerialNumber:%.2X%.2X", sendData[len - 6], sendData[len - 5]);

    //CRC校验
    tmp1 = GetCrc16(&sendData[2], len - 6);
    sendData[len - 4] = (tmp1 & 0xFF00) >> 8;
    sendData[len - 3] = (tmp1 & 0x00FF);

    //结束
    sendData[len - 2] = '\r';
    sendData[len - 1] = '\n';

    return tmp;
}

/******************************************************************************
 *  Function    -  DataPackingDatetime_6
 *
 *  Purpose     -  填充日期时间字段
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void DataPackingDatetime_6(U8 *sendbuf, track_gps_data_struct *gd)
{
    applib_time_struct time = {0};
    applib_time_struct *currTime = NULL;
    if(gd == NULL)
    {
        currTime = &time;
        if(track_cust_is_upload_UTC_time())
        {
            track_fun_get_time(currTime, KAL_TRUE, NULL);
        }
        else
        {
            track_fun_get_time(currTime, KAL_FALSE, &G_parameter.zone.zone);
        }
    }
    else
    {
        currTime = (applib_time_struct *)&gd->gprmc.Date_Time;
    }
    LOGD(L_APP, L_V7, "time: %0.2d-%0.2d-%0.2d %0.2d:%0.2d:%0.2d",
         currTime->nYear,
         currTime->nMonth,
         currTime->nDay,
         currTime->nHour,
         currTime->nMin,
         currTime->nSec);
    sendbuf[0] = currTime->nYear - 2000;
    sendbuf[1] = currTime->nMonth;
    sendbuf[2] = currTime->nDay;
    sendbuf[3] = currTime->nHour;
    sendbuf[4] = currTime->nMin;
    sendbuf[5] = currTime->nSec;
}

/******************************************************************************
 *  Function    -  track_fun_LongitudeLatitudeToHex
 *
 *  Purpose     -  转换经纬度格式
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_fun_LongitudeLatitudeToHex(kal_uint8 *dec, float value)
{
    kal_uint32 tmp;
    tmp = value * 1800000;
    track_fun_reverse_32(dec, tmp);
}

/******************************************************************************
 *  Function    -  track_fun_signed_LongitudeLatitudeToHex
 *
 *  Purpose     -  转换带符号的经纬度格式
 *
 *  Description -  东经为正，北纬为正
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-03-10,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_fun_signed_LongitudeLatitudeToHex(kal_uint8 *dec, float value)
{
    kal_int32 signed_tmp, tmp;
    signed_tmp = value * 1000000;
    tmp = (kal_uint32)signed_tmp;
    track_fun_reverse_32(dec, tmp);
}


/******************************************************************************
 *  Function    -  DataPackingGps_12
 *
 *  Purpose     -  填充GPS数据字段区间
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void DataPackingGps_12(U8 *sendbuf, track_gps_data_struct *gd)
{
    kal_uint16 Course;
    kal_uint8 sat;

    LOGD(L_APP, L_V6, "status:%d,%d, sat:%d,%d, Latitude:%f%c, Longitude:%f%c, Speed:%f, Course:%f",
         gd->gprmc.status, gd->gpgga.posi_fix, gd->gpgga.sat, gd->bdgga.sat, gd->gprmc.Latitude, gd->gprmc.NS, gd->gprmc.Longitude, gd->gprmc.EW, gd->gprmc.Speed, gd->gprmc.Course);

    sat = gd->gpgga.sat + gd->bdgga.sat;
    if(sat > 15)
    {
        sat = 15;
    }
    sendbuf[0] = ((12 << 4) | sat);

    track_fun_LongitudeLatitudeToHex(&sendbuf[1], gd->gprmc.Latitude);
    track_fun_LongitudeLatitudeToHex(&sendbuf[5], gd->gprmc.Longitude);
    sendbuf[9] = gd->gprmc.Speed;
    Course = gd->gprmc.Course;
    track_fun_reverse_16(&sendbuf[10], Course);
    if(gd->gprmc.NS == 'N')
    {
        sendbuf[10] |= 1 << 2;
    }
    if(gd->gprmc.EW == 'W')
    {
        sendbuf[10] |= 1 << 3;
    }
    if(gd->gprmc.status == 1)
    {
        sendbuf[10] |= 1 << 4;
    }
    if(gd->gpgga.posi_fix == 2)
    {
        sendbuf[10] |= 1 << 5;
    }
#if defined(__PACKAGE_WITH_ACC__) || defined(__WM_OLD06__)
    sendbuf[10] |= 1 << 6;
    if(track_cust_status_acc() == 1)
    {
        sendbuf[10] |= 1 << 7;
    }
#endif /* __PACKAGE_WITH_ACC__ */
}

/******************************************************************************
 *  Function    -  DataPackingLbs_8
 *
 *  Purpose     -  填充LBS字段区间
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void DataPackingLbs_8(U8 *sendbuf, LBS_Multi_Cell_Data_Struct *lbs)
{
    //LOGD(L_APP, L_V6, "mcc:%d, mnc:%d, lac:%d, cell id:%d",
    //     lbs->MainCell_Info.mcc, lbs->MainCell_Info.mnc, lbs->MainCell_Info.lac, lbs->MainCell_Info.cell_id);
    track_fun_reverse_16(&sendbuf[0], lbs->MainCell_Info.mcc);
    sendbuf[2] = (U8)lbs->MainCell_Info.mnc;
    track_fun_reverse_16(&sendbuf[3], lbs->MainCell_Info.lac);
    track_fun_reverse_16(&sendbuf[6], lbs->MainCell_Info.cell_id);
}

/******************************************************************************
 *  Function    -  DataPackingLbs_46
 *
 *  Purpose     -  多基站数据打包
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 08-08-2013,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
static void DataPackingLbs_46(U8 *sendbuf, LBS_Multi_Cell_Data_Struct *lbs)
{
    char i = 0, num;
    //LOGD(L_APP, L_V6, "mcc:%d, mnc:%d, lac:%d, cell id:%d",
    //     lbs->MainCell_Info.mcc, lbs->MainCell_Info.mnc, lbs->MainCell_Info.lac, lbs->MainCell_Info.cell_id);
    track_fun_reverse_16(&sendbuf[0], lbs->MainCell_Info.mcc);
    sendbuf[2] = (U8)lbs->MainCell_Info.mnc;
    track_fun_reverse_16(&sendbuf[3], lbs->MainCell_Info.lac);
    track_fun_reverse_16(&sendbuf[6], lbs->MainCell_Info.cell_id);
    sendbuf[8] = (U8)lbs->MainCell_Info.rxlev;
    num = 9;
    for(i = 0; i < 6; i++)
    {
        track_fun_reverse_16(&sendbuf[num + i * 6], lbs->NbrCell_Info[i].lac);
        track_fun_reverse_16(&sendbuf[num + i * 6 + 3], lbs->NbrCell_Info[i].cell_id);
        sendbuf[num + i * 6 + 5] = (U8)lbs->NbrCell_Info[i].rxlev;
    }
    sendbuf[45] = lbs->ta;
}

static void DataPackingLbs_38(U8 *sendbuf, LBS_Multi_Cell_Data_Struct *lbs)
{
    char i = 0, num;
    //LOGD(L_APP, L_V6, "mcc:%d, mnc:%d, lac:%d, cell id:%d",
    //     lbs->MainCell_Info.mcc, lbs->MainCell_Info.mnc, lbs->MainCell_Info.lac, lbs->MainCell_Info.cell_id);
    track_fun_reverse_16(&sendbuf[0], lbs->MainCell_Info.mcc);
    sendbuf[2] = (U8)lbs->MainCell_Info.mnc;
    track_fun_reverse_16(&sendbuf[3], lbs->MainCell_Info.lac);
    track_fun_reverse_16(&sendbuf[5], lbs->MainCell_Info.cell_id);
    sendbuf[7] = (U8)lbs->MainCell_Info.rxlev;
    num = 8;
    for(i = 0; i < 6; i++)
    {
        track_fun_reverse_16(&sendbuf[num + i * 5], lbs->NbrCell_Info[i].lac);
        track_fun_reverse_16(&sendbuf[num + i * 5 + 2], lbs->NbrCell_Info[i].cell_id);
        sendbuf[num + i * 5 + 4] = (U8)lbs->NbrCell_Info[i].rxlev;
    }
}


/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

/******************************************************************************
 *  Function    -  track_cust_paket_01
 *
 *  Purpose     -  协议数据包：0x01——登陆包
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-10-2012,  Cml  written
 * v1.1  , 30-09-2013,  WangQi modify
 * ----------------------------------------
*******************************************************************************/
#if 1
void track_cust_paket_01()
{;}
#else
void track_cust_paket_01()
{
    kal_uint8 *sendData;
    kal_uint16 no, zone;
    int size;
#if defined(__GT300S__) || defined(__GT370__)|| defined (__GT380__)//wangqi
    //酷米客协议要上传类型码和时区语言
    size = 10 + 8 + 2 + 2;
#else
    if(track_cust_is_upload_UTC_time())
    {
        size = 10 + 8 + 2 + 2;
    }
    else
    {
        size = 10 + 8;
    }
#endif
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    // imei
    memcpy(&sendData[4], track_drv_get_imei(1), 8);
#if defined(__GT300S__) || defined(__GT370__)|| defined (__GT380__)//wangqi
    //酷米客协议要上传类型码和时区语言
#else
    if(track_cust_is_upload_UTC_time())
#endif
    {
        // 类型识别码
        sendData[12] = ((TRACK_DEVICE_ID >> 8) & 0xFF);
        sendData[13] = (TRACK_DEVICE_ID & 0xFF);

        // 时区语言
        zone = G_parameter.zone.time;
        zone *= 100;
        zone += G_parameter.zone.time_min;
        zone <<= 4;
        if(G_parameter.zone.zone == 'W')
        {
            zone |= (1 << 3);
        }

        if(G_parameter.lang == 1)
        {
            zone |= 0x02;
        }
        else
        {
            zone |= 0x01;
        }

        LOGD(L_APP, L_V5, "%x", zone);
        sendData[14] = (zone >> 8);
        sendData[15] = (zone & 0x00FF);
        LOGD(L_APP, L_V5, "%x,%x", sendData[14], sendData[15]);
    }

    no = DataPacketEncode78(0x01, sendData, size);

    track_soc_write_req(sendData, size, 1, no);

    Ram_Free(sendData);
}
#endif
//日志信息存放AMS
int track_cust_paket_09(char* st_buf, U16 len)
{
    U8 *sendData, i = 0;
    U16 no;
    int size, ret;
    size = 1  + 2/*log len*/ + len;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return;
    }
    memset(sendData, 0, size);
    //pack_type
    sendData[i++] = 0x09;
    /* 透传数据的长度 */
    sendData[i++] = (len & 0xFF00) >> 8;
    sendData[i++] = (len & 0x00FF);

    /* 填充需要透传的数据 */
    memcpy(&sendData[i], st_buf, len);
    ret = track_cust_paket_FD(sendData, size, 0x09);
    Ram_Free(sendData);
    return ret;
}

/******************************************************************************
 *  Function    -  track_cust_paket_10
 *
 *  Purpose     -  协议数据包：0x10——GPS定位数据上报
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-10-2012,  Jiangweijun  written
 * ----------------------------------------
*******************************************************************************/
#if 1
kal_uint16 track_cust_paket_10(track_gps_data_struct *gd)
{return 0;}
kal_uint16 track_cust_paket_11(LBS_Multi_Cell_Data_Struct *lbs)
{return 0;}
kal_uint16 track_cust_paket_12(track_gps_data_struct *gd, LBS_Multi_Cell_Data_Struct *lbs)
{return 0;}
void track_cust_paket_13(kal_uint8* data, kal_uint16 *len, kal_uint16 *sn)
{;}
void track_cust_paket_15(kal_uint8 *serverid, kal_uint8 *outstr, kal_uint8 outstrlen)
{;}
kal_uint16 track_cust_paket_16(
    track_gps_data_struct *gd,
    LBS_Multi_Cell_Data_Struct *lbs,
    enum_alarm_type alarm_type,
    kal_bool isReturn,
    kal_uint8 call_type)
{return 0;}
kal_uint16 track_cust_paket_17(LBS_Multi_Cell_Data_Struct *lbs, char *number)
{return 0;}
kal_uint16 track_cust_paket_2E(LBS_Multi_Cell_Data_Struct *lbs)
{return 0;}
#else
kal_uint16 track_cust_paket_10(track_gps_data_struct *gd)
{
    U8 *sendData;
    U16 no;
    int size;

    size = 10 + 6/*datatime*/ + 12/*gps*/ + 2;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    // datetime
    DataPackingDatetime_6(&sendData[4], gd);

    // gps
    DataPackingGps_12(&sendData[10], gd);

    //语言位
    if(G_parameter.lang == 1)
    {
        sendData[23] = 0x01;
    }
    else
    {
        sendData[23] = 0x02;
    }

    no = DataPacketEncode78(0x10, sendData, size);

    track_socket_queue_position_send_reg(sendData, size, 0x10, no);
    Ram_Free(sendData);
    return no;
}

/******************************************************************************
 *  Function    -  track_cust_paket_11
 *
 *  Purpose     -  协议数据包：0x11——LBS定位数据
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 07-30-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_uint16 track_cust_paket_11(LBS_Multi_Cell_Data_Struct *lbs)
{
    U8 *sendData;
    U16 no;
    int size;

    size = 10 + 6/*datatime*/ + 8/*lbs*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "Ram_Alloc NULL!!");
        return;
    }
    memset(sendData, 0, size);

    // datetime
    DataPackingDatetime_6(&sendData[4], NULL);

    // lbs
    DataPackingLbs_8(&sendData[10], lbs);

    no = DataPacketEncode78(0x11, sendData, size);

    track_socket_queue_position_send_reg(sendData, size, 0x11, no);
    Ram_Free(sendData);

    return no;
}

/******************************************************************************
 *  Function    -  track_cust_paket_12
 *
 *  Purpose     -  协议数据包：0x12——GPS&LBS定位数据上报
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_uint16 track_cust_paket_12(track_gps_data_struct *gd, LBS_Multi_Cell_Data_Struct *lbs)
{
    U8 *sendData;
    U16 no;
    int size;

    size = 10 + 6/*datatime*/ + 12/*gps*/ + 8/*lbs*/;
    if(G_parameter.mileage_statistics.sw)
    {
        size += 4;
    }
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "Ram_Alloc NULL!!");
        return;
    }
    memset(sendData, 0, size);

    // datetime
    DataPackingDatetime_6(&sendData[4], gd);

    // gps
    DataPackingGps_12(&sendData[10], gd);

    // lbs
    DataPackingLbs_8(&sendData[22], lbs);

    // 里程统计
    if(G_parameter.mileage_statistics.sw)
    {
        LOGD(L_APP, L_V1, "%d, %X", track_get_gps_mileage(), track_get_gps_mileage());
        track_fun_reverse_32(&sendData[30], track_get_gps_mileage());
    }

    no = DataPacketEncode78(0x12, sendData, size);

    track_socket_queue_position_send_reg(sendData, size, 0x12, no);

    Ram_Free(sendData);

    return no;
}

/******************************************************************************
 *  Function    -  track_cust_paket_13
 *
 *  Purpose     -  协议数据包：0x13——状态信息\心跳包
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_paket_13(kal_uint8* data, kal_uint16 *len, kal_uint16 *sn)
{
    U8 *sendData;
    U8 tmp, i = 4;
    U16 no;
    int size, ret;

    LOGD(L_SOC, L_V5, "");
    size = 10 + 5/*status*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    /*
        Bit7       1：油电断开     0：油电接通
        Bit6       1：GPS已定位    0：GPS未定位
        Bit3~Bit5  100：SOS 求救 0x20
                   011：低电报警 0x18
                   010：断电报警 0x10
                   001：震动报警 0x08
                   000：正常
        Bit2       1：已接电源充电 0：未接电源充电
        Bit1       1：ACC高        0：ACC低
        Bit0       1：设防         0：撤防
    */
    //设防/撤防
    if(track_cust_status_defences() == 2)
    {
        sendData[i] |= 0x01;
    }
    //acc
    if(track_cust_status_acc() == 1)
    {
        sendData[i] |= 0x02;
    }
    //充电器
    if(track_cust_status_charger())
    {
        sendData[i] |= 0x04;
    }
    //报警类型

    //GPS定位与否
    if(track_cust_gps_status() >= GPS_STAUS_2D)
    {
        sendData[i] |= 0x40;
    }
    //油电状态 或 锁电机状态
    if(track_cust_oil_cut(99) || track_cust_motor_lock(99))
    {
        sendData[i] |= 0x80;
    }
    i++;

    //电压等级
    sendData[i++] = track_cust_get_battery_level();

    /*GSM信号强度
    0：无信号；
    1：信号极弱
    2：信号较弱
    3：信号良好
    4：信号强*/
    ret = track_cust_get_rssi_level();
    if(ret >= 1 && ret <= 4)
    {
        sendData[i] = ret;
    }
    else
    {
        sendData[i] = 0;
    }
    i++;

    /*
        0x00：正常
        0x01：SOS 求救
        0x02：断电报警
        0x03: 震动报警
        0x04: 进围栏报警
        0x05: 出围栏报警
        0x06: 超速报警
        0x07: 位移报警
    */
    i++;

    //语言 0x01: 中文；0x02: 英文
    //sendData[i++] = language;
    if(G_parameter.lang == 1)
    {
        sendData[i++] = 1;
    }
    else
    {
        sendData[i++] = 2;
    }
    no = DataPacketEncode78(0x13, sendData, size);
    memcpy(data, sendData, size);
    *len = size;
    *sn = no;
    Ram_Free(sendData);
}

/******************************************************************************
 *  Function    -  track_cust_paket_15
 *
 *  Purpose     -  回应服务器下发的数据包(旧)
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_paket_15(kal_uint8 *serverid, kal_uint8 *outstr, kal_uint8 outstrlen)
{
    U8 *sendData, tmp, i = 4;
    U16 no;
    int size;
    outstrlen = strlen(outstr);
    if(outstrlen <= 0 || outstrlen > 200)
    {
        LOGD(L_APP, L_V1, "ERROR: outstrlen=%d", outstrlen);
        return;
    }
    size = 10 + 1/*command len*/ + 4/*server id*/ + outstrlen/*content*/ + 2/*language*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    //指令长度
    sendData[i++] = outstrlen + 4;

    //服务器标志位
    memcpy(&sendData[i], serverid, 4);
    i += 4;

    //指令内容
    memcpy(&sendData[i], outstr, outstrlen);
    i += outstrlen;

    //语言 0x01: 中文；0x02: 英文
    sendData[i++] = 0;
    if(G_parameter.lang == 1)
    {
        sendData[i++] = 1;
    }
    else
    {
        sendData[i++] = 2;
    }
    no = DataPacketEncode78(0x15, sendData, size);

    track_socket_queue_send_netcmd_reg(sendData, size, 0x15, no);

    Ram_Free(sendData);
}

/******************************************************************************
 *  Function    -  track_cust_paket_16
 *
 *  Purpose     -  报警状态包
 *
 *  Description -  language ：0x01: 中文；0x02: 英文
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 25-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_uint16 track_cust_paket_16(
    track_gps_data_struct *gd,
    LBS_Multi_Cell_Data_Struct *lbs,
    enum_alarm_type alarm_type,
    kal_bool isReturn,
    kal_uint8 call_type)
{
    U8 *sendData;
    U8 tmp, i = 4;
    U16 sn;
    int size, ret;
    kal_uint8 a_type = 0;
    kal_uint32  curr_tick = kal_get_systicks();

    LOGD(L_APP, L_V5, "alarm_type:%d", alarm_type);
#if defined(__MORE_FENCE__)
    size = 10 + 6/*datatime*/ + 12/*gps*/ + 1/*lbs len*/ + 8/*lbs*/ + 5/*status & alarm*/ + 1/*电子围栏序列号*/;
#else
    size = 10 + 6/*datatime*/ + 12/*gps*/ + 1/*lbs len*/ + 8/*lbs*/ + 5/*status & alarm*/;
#endif
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    // datetime
#if defined (__GT740__)
    if(track_fun_update_time_to_system(99, NULL) > 0 || alarm_type != TR_CUST_ALARM_PRE_REMOVE)
    {
        DataPackingDatetime_6(&sendData[i], gd);
    }
    else
    {
        sendData[i] = 0;
        sendData[i + 1] = 0;
        memcpy(&sendData[i + 2], &curr_tick, 4);
        LOGD(L_APP, L_V7, "打包ticks:%d", curr_tick);
    }
#else
    DataPackingDatetime_6(&sendData[i], gd);
#endif

    i += 6;

    // gps
    DataPackingGps_12(&sendData[i], gd);
    i += 12;

    // lbs
    sendData[i++] = 9;
    DataPackingLbs_8(&sendData[i], lbs);
    i += 8;

    /*
        Bit7       1：油电断开     0：油电接通
        Bit6       1：GPS已定位    0：GPS未定位
        Bit3~Bit5  100：SOS 求救 0x20
                   011：低电报警 0x18
                   010：断电报警 0x10
                   001：震动报警 0x08
                   000：正常
        Bit2       1：已接电源充电 0：未接电源充电
        Bit1       1：ACC高        0：ACC低
        Bit0       1：设防         0：撤防
    */
    //设防/撤防
    if(track_cust_status_defences() == 2)
    {
        sendData[i] |= 0x01;
    }
    //acc
    if(track_cust_status_acc() == 1)
    {
        sendData[i] |= 0x02;
    }
    //充电器
    if(track_cust_status_charger())
    {
        sendData[i] |= 0x04;
    }
    //报警类型
    if(alarm_type == TR_CUST_ALARM_Vibration)
    {
        sendData[i] |= 0x08;
    }
    else if(alarm_type == TR_CUST_ALARM_PowerFailure)
    {
        sendData[i] |= 0x10;
    }
    else if(alarm_type == TR_CUST_ALARM_LowBattery)
    {
        sendData[i] |= 0x18;
    }
    else if(alarm_type == TR_CUST_ALARM_SOS)
    {
        sendData[i] |= 0x20;
    }
    //GPS定位与否
    if(gd->gprmc.status == 1)
    {
        sendData[i] |= 0x40;
    }
    //油电状态
    if(track_cust_oil_cut(99))
    {
        sendData[i] |= 0x80;
    }
    i++;

    //电压等级
    sendData[i++] = track_cust_get_battery_level();

    /*GSM信号强度
    0：无信号；
    1：信号极弱
    2：信号较弱
    3：信号良好
    4：信号强*/
    ret = track_cust_get_rssi_level();
    if(ret >= 1 && ret <= 4)
    {
        sendData[i++] = ret;
    }
    else
    {
        sendData[i++] = 0;
    }

    //报警类型
    if(alarm_type == TR_CUST_ALARM_ACC_ON)
        sendData[i++] = 0xFE;
    else if(alarm_type == TR_CUST_ALARM_ACC_OFF)
        sendData[i++] = 0xFF;
    else
        sendData[i++] = alarm_type;

    // 服务器回复报警所用语言
    if(isReturn)
    {
        if(G_parameter.lang == 1)
        {
            sendData[i++] = 1; //中文
        }
        else
        {
            sendData[i++] = 2; //英文
        }
    }
    else
    {
        sendData[i++] = 0; //不需要平台回复（暂不支持，原有的设计，报警队列必须有回复的）
    }

#if defined(__MORE_FENCE__)
    if(alarm_type == TR_CUST_ALARM_OutFence || alarm_type == TR_CUST_ALARM_InFence)
    {
        sendData[i++] = track_cust_module_get_fence_id();
        a_type = G_parameter.fence[track_cust_module_get_fence_id()].alarm_type;//根据围栏ID 获取报警方式
        LOGD(L_APP, L_V5, "围栏=%d,报警模式:%d", track_cust_module_get_fence_id() + 1, a_type);
    }
    else
    {
        sendData[i++] = 0xff;
    }
    sn = DataPacketEncode78(0x27, sendData, size);
    track_cust_check_gprsdata(1, sn);
    if(a_type == 1)
    {
        call_type |= 0x02;//sms 10
    }
    else if(a_type == 2)
    {
        call_type |= 0x03;//call&&sms 11
    }
    else if(a_type == 3)
    {
        call_type |= 0x01;//call 01
    }
    LOGD(L_APP, L_V5, "call_type:%d,fenceid=%d", call_type, track_cust_module_get_fence_id() + 1);
#else
    if(track_cust_is_upload_UTC_time())
    {
        sn = DataPacketEncode78(0x26, sendData, size);
    }
    else
    {
        sn = DataPacketEncode78(0x16, sendData, size);
    }
#endif

#if defined(__FLY_MODE__)
    if(alarm_type == TR_CUST_ALARM_Ext_LowBattery_Fly)
    {
        /* 由于进飞行模式之前一般会发送外电低电报警包，那么为了不因报警队列堵塞造成进入飞行模式都还未送出数据 */
        track_socket_queue_position_send_reg(sendData, size, 0x16, sn);
    }
    else
    {
        if(isReturn)
        {
            track_alarm_vec_queue_push(alarm_type, sn, call_type);
        }
        track_socket_queue_alarm_send_reg(sendData, size, 0x16, sn);
    }
#elif defined(__MORE_FENCE__)
    if(isReturn || a_type)
    {
        track_alarm_vec_queue_push(alarm_type, sn, call_type);
    }

    track_socket_queue_alarm_send_reg(sendData, size, 0x16, sn);
#else
    if(isReturn)
    {
        track_alarm_vec_queue_push(alarm_type, sn, call_type);
    }

    track_socket_queue_alarm_send_reg(sendData, size, 0x16, sn);
#endif
    Ram_Free(sendData);

    return sn;
}

/******************************************************************************
 *  Function    -  track_cust_paket_17
 *
 *  Purpose     -   LBS、电话号码查询地址信息包(0X17)
 *
 *  Description -  DW、Positoin 获取 LBS 位置信息
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 30-07-2013,  Cml  written
 * v1.0  , 14-10-2013,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
kal_uint16 track_cust_paket_17(LBS_Multi_Cell_Data_Struct *lbs, char *number)
{
    kal_uint8 *sendData;
    kal_uint16 no;
    int size;

    LOGD(L_APP, L_V5, "number:%s", number);
    size = 10 + 8/*lbs*/ + 21/*number*/ + 2/*hold 保留位,语言*/;

    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return 0;
    }
    memset(sendData, 0, size);

    // lbs
    DataPackingLbs_8(&sendData[4], lbs);

    // number(Max:21)
    snprintf(&sendData[12], 20, number);

    //hold 保留位,语言
    sendData[33] = 0;
    if(G_parameter.lang == 1)
    {
        sendData[34] = 1;
    }
    else
    {
        sendData[34] = 2;
    }

    no = DataPacketEncode78(0x17, sendData, size);
    track_socket_queue_alarm_send_reg(sendData, size, 0x17, no);
    Ram_Free(sendData);

    return no;
}

/******************************************************************************
 *  Function    -  track_cust_paket_2E
 *
 *  Purpose     -  多基站协议 0X2E   LBS扩张包
 *
 *  Description -   需回复
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 29-08-2016,  Xzq  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint16 track_cust_paket_2E(LBS_Multi_Cell_Data_Struct *lbs)
{
    U8 *sendData;
    U16 no;
    int size;
    LOGD(L_APP, L_V5, "");
    size = 10 + 6/*datatime*/ + 46/*lbs*/ + 2;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "Ram_Alloc NULL!!");
        return;
    }
    memset(sendData, 0, size);
    // datetime
    DataPackingDatetime_6(&sendData[4], NULL);
    // lbs
    DataPackingLbs_46(&sendData[10], lbs);
    sendData[56] = 0;
    //语言位
    if(G_parameter.lang == 1)
    {
        sendData[57] = 0x01;
    }
    else
    {
        sendData[57] = 0x02;
    }
    LOGH(L_APP, L_V7, sendData, size);
    no = DataPacketEncode78(0x2E, sendData, size);
    //track_socket_queue_send_log_reg(sendData, size, 0x28, no);
    track_socket_queue_position_send_reg(sendData, size, 0x2E, no);
    Ram_Free(sendData);

    return no;
}
#endif

/******************************************************************************
 *  Function    -  track_cust_paket_18
 *
 *  Purpose     -  多基站协议 0x18/0x28
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 08-08-2013,  jwj  written
 * ----------------------------------------
 ******************************************************************************/
#if defined(__NF2318__)
kal_int8 track_cust_paket_18(LBS_Multi_Cell_Data_Struct *lbs, kal_uint8 type)
{
	return 0;
}
kal_uint16 track_cust_paket_19(LBS_Multi_Cell_Data_Struct *lbs, enum_alarm_type alarm_type, kal_bool isReturn, kal_uint8 call_type)
{
	return 0;
}
kal_uint16 track_cust_paket_1A(track_gps_data_struct *gd, char *number){return 0;}
void track_cust_paket_21(kal_uint8 *serverid, kal_bool isASCII, kal_uint8 *data, int datalen){;}
kal_uint16 track_cust_paket_22(
    track_gps_data_struct *gd,
    LBS_Multi_Cell_Data_Struct *lbs,
    kal_uint8 packet_type,
    kal_uint8 packet_status)
{return 0;}
#else
kal_int8 track_cust_paket_18(LBS_Multi_Cell_Data_Struct *lbs, kal_uint8 type)
{
    U8 *sendData;
    S8 ret = 0;
    U16 no;
    int size;
    LOGD(L_APP, L_V5, "");

    size = 10 + 6/*datatime*/ + 46/*lbs*/ + 2;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "Ram_Alloc NULL!!");
        return;
    }

    // datetime
    DataPackingDatetime_6(&sendData[4], NULL);

    // lbs
    DataPackingLbs_46(&sendData[10], lbs);
    sendData[56] = 0;
    //语言位
    if(G_parameter.lang == 1)
    {
        sendData[57] = 0x01;
    }
    else
    {
        sendData[57] = 0x02;
    }
    if(track_cust_is_upload_UTC_time())
    {
        LOGH(L_APP, L_V7, sendData, size);
        no = DataPacketEncode78(0x28, sendData, size);
        if(type == 1)
            ret = Socket_write_req(0, sendData, size, PACKET_LBS_DATA, 0x13, no, 1);
        else
            track_socket_queue_position_send_reg(sendData, size, 0x28, no);
    }
    else
    {
        no = DataPacketEncode78(0x18, sendData, size);
        if(type == 1)
            ret = Socket_write_req(0, sendData, size, PACKET_LBS_DATA, 0x13, no, 1);
        else
            track_socket_queue_position_send_reg(sendData, size, 0x18, no);
    }

    Ram_Free(sendData);

    return ret;
}

/******************************************************************************
 *  Function    -  track_cust_paket_19
 *
 *  Purpose     -  SOS、震动报警时获取 LBS 对应位置信息
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 30-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_uint16 track_cust_paket_19(LBS_Multi_Cell_Data_Struct *lbs, enum_alarm_type alarm_type, kal_bool isReturn, kal_uint8 call_type)
{
    kal_uint8 *sendData;
    kal_uint16 sn;
    int size, i, ret;

    LOGD(L_APP, L_V5, "");
    size = 10 + 8/*lbs*/ + 3/*status*/ + 2/*扩展位*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return 0;
    }
    memset(sendData, 0, size);

    // lbs
    DataPackingLbs_8(&sendData[4], lbs);
    i = 12;

    /*
        Bit7       1：油电断开     0：油电接通
        Bit6       1：GPS已定位    0：GPS未定位
        Bit3~Bit5  100：SOS 求救 0x20
                   011：低电报警 0x18
                   010：断电报警 0x10
                   001：震动报警 0x08
                   000：正常
        Bit2       1：已接电源充电 0：未接电源充电
        Bit1       1：ACC高        0：ACC低
        Bit0       1：设防         0：撤防
    */
    if(track_cust_status_charger() > 0)
    {
        sendData[i] = 0x04;
    }

    if(track_cust_status_defences() == 2)
    {
        sendData[i] |= 0x01;//0000 0001
    }

    if(G_parameter.fence[0].sw == 1)
    {
        sendData[i] |= 0x02;//0000 0010
    }

    if(alarm_type == TR_CUST_ALARM_SOS)
    {
        sendData[i] |= 0x20;
    }
    else if(alarm_type == TR_CUST_ALARM_PowerFailure)
    {
        sendData[i] |= 0x10;
    }
    else if(alarm_type == TR_CUST_ALARM_Vibration)  //震动报警001//0000 1000
    {
        sendData[i] |= 0x08;//0000 1000
    }
    else if(alarm_type == TR_CUST_ALARM_LowBattery)
    {
        sendData[i] |= 0x18;//0001 1000
    }

    //GPS定位状态
    if(track_cust_gps_status() > 2)
    {
        sendData[i] |= 0x40;
    }
    i++;

    //电压等级
    sendData[i++] = track_cust_get_battery_level();

    /*GSM信号强度
    0：无信号；
    1：信号极弱
    2：信号较弱
    3：信号良好
    4：信号强*/
    ret = track_cust_get_rssi_level();
    if(ret >= 1 && ret <= 4)
    {
        sendData[i++] = ret;
    }
    else
    {
        sendData[i++] = 0;
    }

    //报警类型
    if(alarm_type == TR_CUST_ALARM_ACC_ON)
        sendData[i++] = 0xFE;
    else if(alarm_type == TR_CUST_ALARM_ACC_OFF)
        sendData[i++] = 0xFF;
    else
        sendData[i++] = alarm_type;

    if(G_parameter.lang == 1)
    {
        sendData[i++] = 1; //中文
    }
    else
    {
        sendData[i++] = 2; //英文
    }

    sn = DataPacketEncode78(0x19, sendData, size);

    if(isReturn)
    {
        track_alarm_vec_queue_push(alarm_type, sn, call_type);
    }
    track_socket_queue_alarm_send_reg(sendData, size, 0x19, sn);
    Ram_Free(sendData);

    return sn;
}

/******************************************************************************
 *  Function    -  track_cust_paket_1A
 *
 *  Purpose     -  向服务器请求查询经纬度对应的中文地址
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_uint16 track_cust_paket_1A(track_gps_data_struct *gd, char *number)
{
    kal_uint8 *sendData;
    kal_uint16 no;
    int size;

    LOGD(L_APP, L_V5, "number:%s", number);
    size = 10 + 6/*datatime*/ + 12/*gps*/ + 21/*number*/ + 2/*language*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return 0;
    }
    memset(sendData, 0, size);

    // datetime
    DataPackingDatetime_6(&sendData[4], gd);

    // gps
    DataPackingGps_12(&sendData[10], gd);

    // number(Max:21)
    snprintf(&sendData[22], 20, number);

    // language  0x01: 中文；0x02: 英文
    sendData[43] = 0x00;
    if(G_parameter.lang == 1)
    {
        sendData[44] = 1;
    }
    else
    {
        sendData[44] = 2;
    }
    if(track_cust_is_upload_UTC_time())
    {
        no = DataPacketEncode78(0x2A, sendData, size);
    }
    else
    {
        no = DataPacketEncode78(0x1A, sendData, size);
    }
    track_socket_queue_alarm_send_reg(sendData, size, 0x1A, no);
    Ram_Free(sendData);

    return no;
}

/******************************************************************************
 *  Function    -  track_cust_paket_21
 *
 *  Purpose     -  回应服务器下发的数据包
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_paket_21(kal_uint8 *serverid, kal_bool isASCII, kal_uint8 *data, int datalen)
{
#if 1//__NF2318__
	;
#else
    U8 *sendData, i = 5;
    U16 no;
    int size;

    if(datalen <= 0 || datalen > 1000)
    {
        LOGD(L_APP, L_V1, "ERROR: outstrlen=%d", datalen);
        return;
    }

    size = 11 + 4/*server id*/ + 1/*code_page*/ + datalen/*data*/;

    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return;
    }
    memset(sendData, 0, size);

    //服务器标志位
    memcpy(&sendData[i], serverid, 4);
    i += 4;

    //code_page
    if(isASCII)
    {
        sendData[i++] = 1;
    }
    else
    {
        sendData[i++] = 2;
    }

    //内容
    memcpy(&sendData[i], data, datalen);
    i += datalen;

    no = DataPacketEncode79(0x21, sendData, size);
    track_socket_queue_send_netcmd_reg(sendData, size, 0x21, no);

    Ram_Free(sendData);
#endif
}

/******************************************************************************
 *  Function    -  track_cust_paket_22
 *
 *  Purpose     -  GPS&LBS定位数据上报(UTC时间)
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_uint16 track_cust_paket_22(
    track_gps_data_struct *gd,
    LBS_Multi_Cell_Data_Struct *lbs,
    kal_uint8 packet_type,
    kal_uint8 packet_status)
{
    U8 *sendData;
    U16 no;
    int size;

    {
        // 注意size的值不能大于 BACKUP_DATA_PACKET_MAX 宏定义
        size = 10 + 6/*datatime*/ + 12/*gps*/ + 8/*lbs*/ + 3;
    }
    if(G_parameter.mileage_statistics.sw)
    {
        size += 4;
    }
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "Ram_Alloc NULL!!");
        return;
    }
    memset(sendData, 0, size);

    // datetime
    DataPackingDatetime_6(&sendData[4], gd);

    // gps
    DataPackingGps_12(&sendData[10], gd);

    // lbs
    DataPackingLbs_8(&sendData[22], lbs);

    // ACC
    if(track_cust_status_acc() == 1)
    {
        sendData[30] = 1;
    }

    // GPS 数据点上报类型
    // 0x00 定时上报
    // 0x01 定距上报
    // 0x02 拐点上传
    // 0x03 ACC 状态改变上传
    // 0x04 从运动变为静止状态后，补传最后一个定位点
    // 0x05 网络断开重连后，上报之前最后一个有效上传点
    sendData[31] = packet_type;

    // GPS 实时补传
    // 0x00 实时上传
    // 0x01 补传
    sendData[32] = packet_status;
    if(G_parameter.mileage_statistics.sw)
    {
        LOGD(L_APP, L_V1, "%d, %X", track_get_gps_mileage(), track_get_gps_mileage());
        track_fun_reverse_32(&sendData[33], track_get_gps_mileage());
    }
    no = DataPacketEncode78(0x22, sendData, size);

    track_socket_queue_position_send_reg(sendData, size, 0x12, no);

    Ram_Free(sendData);

    return no;
}
#endif
/******************************************************************************
 *  Function    -  track_cust_paket_2D
 *
 *  Purpose     -  GPS&LBS定位数据上报(UTC时间)
 *
 *  Description -  需平台回复
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-08-2016,  XZQ  written
 * ----------------------------------------
*******************************************************************************/
kal_uint16 track_cust_paket_2D(
    track_gps_data_struct *gd,
    LBS_Multi_Cell_Data_Struct *lbs,
    kal_uint8 packet_type,
    kal_uint8 packet_status)
{
#if 1//__NF2318__
	return 1;
#else
    U8 *sendData;
    U16 no;
    int size;
    {
        // 注意size的值不能大于 BACKUP_DATA_PACKET_MAX 宏定义
        size = 10 + 6/*datatime*/ + 12/*gps*/ + 8/*lbs*/ + 3;
    }
    if(G_parameter.mileage_statistics.sw)
    {
        size += 4;
    }
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "Ram_Alloc NULL!!");
        return;
    }
    memset(sendData, 0, size);

    // datetime
    DataPackingDatetime_6(&sendData[4], gd);

    // gps
    DataPackingGps_12(&sendData[10], gd);

    // lbs
    DataPackingLbs_8(&sendData[22], lbs);

    // ACC
    if(track_cust_status_acc() == 1)
    {
        sendData[30] = 1;
    }

    // GPS 数据点上报类型
    // 0x00 定时上报
    // 0x01 定距上报
    // 0x02 拐点上传
    // 0x03 ACC 状态改变上传
    // 0x04 从运动变为静止状态后，补传最后一个定位点
    // 0x05 网络断开重连后，上报之前最后一个有效上传点
    sendData[31] = packet_type;

    // GPS 实时补传
    // 0x00 实时上传
    // 0x01 补传
    sendData[32] = packet_status;
    if(G_parameter.mileage_statistics.sw)
    {
        LOGD(L_APP, L_V1, "%d, %X", track_get_gps_mileage(), track_get_gps_mileage());
        track_fun_reverse_32(&sendData[33], track_get_gps_mileage());
    }
    no = DataPacketEncode78(0x2D, sendData, size);
#if defined(__CQYD_2SERVER__)
    track_cust_server3_queue_send_reg(sendData, size, 0x12, no);
#else
    track_socket_queue_position_send_reg(sendData, size, 0x2D, no);
#endif
    Ram_Free(sendData);

    return no;
#endif
}
#if !defined(__NF2318__)
void track_cust_paket_23(kal_uint8* data, kal_uint16 *len, kal_uint16 *sn)
{
    U8 *sendData;
    U8 tmp, i = 4;
    U16 no, volt2;
    U32 volt;
    int size, ret;

    LOGD(L_SOC, L_V5, "");
    size = 10 + 6/*status*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    /*
        Bit7       1：油电断开     0：油电接通
        Bit6       1：GPS已定位    0：GPS未定位
        Bit3~Bit5  100：SOS 求救 0x20
                   011：低电报警 0x18
                   010：断电报警 0x10
                   001：震动报警 0x08
                   000：正常
        Bit2       1：已接电源充电 0：未接电源充电
        Bit1       1：ACC高        0：ACC低
        Bit0       1：设防         0：撤防
    */
    //设防/撤防
    if(track_cust_status_defences() == 2)
    {
        sendData[i] |= 0x01;
    }
    //acc
    if(track_cust_status_acc() == 1)
    {
        sendData[i] |= 0x02;
    }
    //充电器
    if(track_cust_status_charger())
    {
        sendData[i] |= 0x04;
    }
    //报警类型

    //GPS定位与否
    if(track_cust_gps_status() >= GPS_STAUS_2D)
    {
        sendData[i] |= 0x40;
    }
    //油电状态 或 锁电机状态
    if(track_cust_oil_cut(99) || track_cust_motor_lock(99))
    {
        sendData[i] |= 0x80;
    }
    i++;

    //电压
    volt = track_cust_get_battery_volt();
    if(volt > 0) volt /= 10000;
    volt2 = volt;
    sendData[i++] = (volt2 >> 8);
    sendData[i++] = (volt2 & 0x00FF);

    /*GSM信号强度
    0：无信号；
    1：信号极弱
    2：信号较弱
    3：信号良好
    4：信号强*/
    ret = track_cust_get_rssi_level();
    if(ret >= 1 && ret <= 4)
    {
        sendData[i] = ret;
    }
    else
    {
        sendData[i] = 0;
    }
    i++;

    /*
        0x00：正常
        0x01：SOS 求救
        0x02：断电报警
        0x03: 震动报警
        0x04: 进围栏报警
        0x05: 出围栏报警
        0x06: 超速报警
        0x07: 位移报警
    */
    i++;

    //语言 0x01: 中文；0x02: 英文
    //sendData[i++] = language;
    if(G_parameter.lang == 1)
    {
        sendData[i++] = 1;
    }
    else
    {
        sendData[i++] = 2;
    }
    no = DataPacketEncode78(0x23, sendData, size);
    memcpy(data, sendData, size);
    *len = size;
    *sn = no;
    Ram_Free(sendData);

}
#endif
#if 1
void track_cust_paket_29(kal_uint8* data, kal_uint16 *len, kal_uint16 *sn){;}
#else
/******************************************************************************
 *  Function    -  track_cust_paket_29
 *
 *  Purpose     -  协议数据包：0x29——状态信息\心跳包( 伴车安定制)
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 18-05-2015,  chenjiajun  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_paket_29(kal_uint8* data, kal_uint16 *len, kal_uint16 *sn)
{
    U8 *sendData;
    U8 tmp, i = 4;
    U16 no;
    int size, ret;
    U8 voltage;

    LOGD(L_SOC, L_V5, "");
    size = 10 + 9/*status*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    /*
        Bit7       1：油电断开     0：油电接通
        Bit6       1：GPS已定位    0：GPS未定位
        Bit3~Bit5  100：SOS 求救 0x20
                   011：低电报警 0x18
                   010：断电报警 0x10
                   001：震动报警 0x08
                   000：正常
        Bit2       1：已接电源充电 0：未接电源充电
        Bit1       1：ACC高        0：ACC低
        Bit0       1：设防         0：撤防
    */
    //设防/撤防
    if(track_cust_status_defences() == 2)
    {
        sendData[i] |= 0x01;
    }
    //acc
    if(track_cust_status_acc() == 1)
    {
        sendData[i] |= 0x02;
    }
    //充电器
    if(track_cust_status_charger())
    {
        sendData[i] |= 0x04;
    }
    //报警类型

    //GPS定位与否
    if(track_cust_gps_status() >= GPS_STAUS_2D)
    {
        sendData[i] |= 0x40;
    }
    //油电状态 或 锁电机状态
    if(track_cust_oil_cut(99) || track_cust_motor_lock(99))
    {
        sendData[i] |= 0x80;
    }
    i++;

    //电压等级
    sendData[i++] = track_cust_get_battery_level();


    /*GSM信号强度
    0：无信号；
    1：信号极弱
    2：信号较弱
    3：信号良好
    4：信号强*/
    ret = track_cust_get_rssi_level();
    if(ret >= 1 && ret <= 4)
    {
        sendData[i] = ret;
    }
    else
    {
        sendData[i] = 0;
    }
    i++;

    /*
        0x00：正常
        0x01：SOS 求救
        0x02：断电报警
        0x03: 震动报警
        0x04: 进围栏报警
        0x05: 出围栏报警
        0x06: 超速报警
        0x07: 位移报警
    */
    i++;

    //语言 0x01: 中文；0x02: 英文
    //sendData[i++] = language;
    if(G_parameter.lang == 1)
    {
        sendData[i++] = 1;
    }
    else
    {
        sendData[i++] = 2;
    }
    //i++;
#if defined (__EXT_VBAT_ADC__)
    LOGD(L_APP, L_V5, "%d", track_drv_get_external_voltage_change());
//电压信息
    voltage = track_drv_get_external_voltage_change() / 10;
    LOGD(L_APP, L_V5, "%d", voltage);
    track_fun_reverse_16(&sendData[i++], voltage);
    i++;
#endif
    /*
        Bit7~Bit15  保留
        Bit6       1：超速报警开   0：超速报警关
        Bit5       1：低电报警开    0：低电报警关
        Bit4       1:     断电报警开 0:断电报警关
        Bit2~Bit3  震动报警方式     00 : 仅GPRS      =0
                                                                 01 : CALL+GPRS  =3
                                                                 10 : SMS+GPRS   =1
                                                                 11 : CALL+SMS+GPRS  =2
        Bit1       1：震动报警开       0：震动报警关
        Bit0       1：围栏报警开       0：围栏报警关
    */
    i++;
    //围栏报警开关状态
    if(G_parameter.fence[0].sw == 1)
    {
        sendData[i] |= 0x01;
    }
    //震动报警开关状态
    if(G_parameter.vibrates_alarm.sw == 1)
    {
        sendData[i] |= 0x02;
    }
    // 震动报警方式
    if(G_parameter.vibrates_alarm.alarm_type == 0)
    {
        sendData[i] |= 0x00;
    }
    else if(G_parameter.vibrates_alarm.alarm_type == 3)
    {
        sendData[i] |= 0x04;
    }
    else if(G_parameter.vibrates_alarm.alarm_type == 1)
    {
        sendData[i] |= 0x08;
    }
    else if(G_parameter.vibrates_alarm.alarm_type == 2)
    {
        sendData[i] |= 0x0c;
    }
    //断电报警开关状态
    if(G_parameter.power_fails_alarm.sw == 1)
    {
        sendData[i] |= 0x10;
    }
    //低电报警开关状态
    if(G_parameter.low_power_alarm.sw == 1)
    {
        sendData[i] |= 0x20;
    }
    //超速报警开 关状态
    if(G_parameter.speed_limit_alarm.sw == 1)
    {
        sendData[i] |= 0x40;
    }
    no = DataPacketEncode78(0x29, sendData, size);
    memcpy(data, sendData, size);
    *len = size;
    *sn = no;
    Ram_Free(sendData);
}
#endif
/******************************************************************************
 *  Function    -  track_cust_paket_8A
 *
 *  Purpose     -  与应用服务器校时
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 16-07-2015,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_paket_8A(void)
{
#if 1//__NF2318__
	;
#else
    LBS_Multi_Cell_Data_Struct *lbs = track_drv_get_lbs_data();
    kal_uint8 *sendData;
    kal_uint16 no;
    int size, i, ret;

    LOGD(L_APP, L_V5, "");
    size = 10;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    no = DataPacketEncode78(0x8A, sendData, size);

    track_socket_queue_alarm_send_reg(sendData, size, 0x8A, no);

    Ram_Free(sendData);
#endif
}

void track_cust_paket_8B(void)
{
#if 1//__NF2318__
	;
#else
    LBS_Multi_Cell_Data_Struct *lbs = track_drv_get_lbs_data();
    kal_uint8 *sendData;
    kal_uint16 no;
    int size, i, ret;

    LOGD(L_APP, L_V5, "");
    size = 10 + 8/*lbs*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    // lbs
    DataPackingLbs_8(&sendData[4], lbs);

    no = DataPacketEncode78(0x8B, sendData, size);
    track_socket_queue_alarm_send_reg(sendData, size, 0x8B, no);
    Ram_Free(sendData);
#endif
}

void track_cust_paket_8C(kal_uint8 queue, kal_uint8 acc_status, kal_uint8 *data, kal_uint16 len)
{
#if 1//__NF2318__
	;
#else
    kal_uint8 *sendData;
    kal_uint16 no;
    int size, i = 5;
    track_gps_data_struct *gd = track_cust_gpsdata_alarm();

    LOGD(L_APP, L_V5, "");
    if(len > 1000 || len <= 0)
    {
        LOGD(L_APP, L_V1, "ERROR: Data length abnormalities(%d)!", len);
        return;
    }
    size = 11 + 6/*datatime*/ + 1/*acc*/ + len/*OBD*/ + 12/*gps*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    // datetime
    DataPackingDatetime_6(&sendData[i], gd);
    i += 6;

    // ACC
    sendData[i] = acc_status;
    /*if(track_cust_status_acc() == 1)
    {
        sendData[i] = 1;
    }*/
    i++;

    // OBD
    memcpy(&sendData[i], data, len);
    i += len;

    // gps
    DataPackingGps_12(&sendData[i], gd);

    no = DataPacketEncode79(0x8C, sendData, size);
    if(queue == 1)
        track_socket_queue_position_send_reg(sendData, size, 0x8C, 0);
    else
        track_socket_queue_send_netcmd_reg(sendData, size, 0x8C, 0);
    Ram_Free(sendData);
#endif
}

/*开启__LUYING__的项目要注意，这个会上传到server4       --    chengjun  2017-09-27*/
void track_cust_paket_8D(
    U8  filetype,   /*文件类型*/
    U32 filelen,    /*文件总长度*/
    U8  errorCheck, /*文件错误校验类型*/
    U8 *checkData,  /*文件错误校验*/
    U32 begin,      /*开始位置*/
    U16 datalen,    /*当前内容长度*/
    U8 *data)       /*内容*/
{
    kal_uint8 *sendData;
    kal_uint16 no;
    int size, i = 5;

#if defined(__LUYING__)
    extern kal_uint8* track_get_LY_stamp(void);
#endif


    LOGD(L_APP, L_V5, "filetype:%d, filelen:%d, errorCheck:%d, begin:%d, datalen:%d", filetype, filelen, errorCheck, begin, datalen);
    if(datalen > 1000 || datalen <= 0)
    {
        LOGD(L_APP, L_V1, "ERROR: Data length abnormalities(%d)!", datalen);
        return;
    }
    size = 11 + 1/*filetype*/ + 4/*filelen*/ + 1/*errorCheck*/ + 4/*begin*/ + 2/*datalen*/ + datalen/*data*/;
    if(errorCheck == 0)/*CRC*/
    {
        size += 2/*checkData*/;
    }
    else if(errorCheck == 1)/*MD5*/
    {
        size += 8/*checkData*/;
    }
    else
    {
        LOGD(L_APP, L_V1, "ERROR: errorCheck");
        return;
    }
    if(filetype == 0)
    {
        size += 6/*alerm Datatime*/;
    }
    else if(filetype == 1)
    {
        size += 2/*alerm NO*/;
    }
#if defined(__LUYING__)
    else if(filetype == 3)
    {
        size += 6/*alerm NO*/;
    }
#endif

    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    /*文件类型*/
    sendData[i++] = filetype;

    /*文件总长度*/
    track_fun_reverse_32(&sendData[i], filelen);
    i += 4;

    /*文件错误校验类型*/
    sendData[i++] = errorCheck;

    /*文件错误校验*/
    if(errorCheck == 0)/*CRC*/
    {
        sendData[i++] = checkData[1];
        sendData[i++] = checkData[0];
    }
    else if(errorCheck == 1)/*MD5*/
    {
        memcpy(&sendData[i], checkData, 8);
        i += 8;
    }

    /*开始位置*/
    track_fun_reverse_32(&sendData[i], begin);
    i += 4;

    /*当前内容长度*/
    track_fun_reverse_16(&sendData[i], datalen);
    i += 2;

    /*内容*/
    memcpy(&sendData[i], data, datalen);
    i += datalen;

    if(filetype == 0)
    {
        /*alerm Datatime*/
        DataPackingDatetime_6(&sendData[i], NULL);
    }
    else if(filetype == 1)
    {
        /*alerm NO*/
        U16 tmp = track_cust_sos_get_alarm_sn();
        sendData[i] = (tmp & 0xFF00) >> 8;
        sendData[i + 1] = (tmp & 0x00FF);
    }
#if defined(__LUYING__)
    else if(filetype == 3)
    {
        memcpy(&sendData[i], track_get_LY_stamp(), 6);
    }
#endif

    no = DataPacketEncode79(0x8D, sendData, size);

#if defined (__LUYING__)
    track_cust_server4_queue_send_reg(sendData, size, 0x8D, 0);
#else
    track_socket_queue_send_log_reg(sendData, size, 0x8D, 0);
#endif /* __LUYING__ */

    Ram_Free(sendData);
}

void track_cust_paket_8E(kal_uint8 *data, kal_uint16 len)
{
#if 1//__NF2318__
	;
#else
    kal_uint8 *sendData;
    kal_uint16 no;
    int size, i = 5;
    track_gps_data_struct *gd = track_cust_gpsdata_alarm();

    LOGD(L_APP, L_V5, "");
    if(len > 1000 || len <= 0)
    {
        LOGD(L_APP, L_V1, "ERROR: Data length abnormalities(%d)!", len);
        return;
    }
    size = 11 + 6/*datatime*/ + len/*OBD*/ + 12/*gps*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    // datetime
    DataPackingDatetime_6(&sendData[i], gd);
    i += 6;

    // OBD
    memcpy(&sendData[i], data, len);
    i += len;

    // gps
    DataPackingGps_12(&sendData[i], gd);

    no = DataPacketEncode79(0x8E, sendData, size);
    if(track_soc_login_status())
        track_socket_queue_position_send_reg(sendData, size, 0x8E, 0);
    else
        track_socket_queue_send_netcmd_reg(sendData, size, 0x8E, 0);
    Ram_Free(sendData);
#endif
}

void track_cust_paket_94(kal_uint8 datatype, kal_uint8 *data, kal_uint16 len)
{
#if 1//__NF2318__
	;
#else
    kal_uint8 *sendData;
    kal_uint16 no;
    int size, i = 5;
    kal_int16 volt = 0;
    track_gps_data_struct *gd = track_cust_gpsdata_alarm();
#if defined(__EXT_VBAT_ADC__)
    volt = track_drv_get_external_voltage_change();
//   LOGS("volt:%d", volt);
#endif  /*__JIMISHARE__*/
    LOGD(L_APP, L_V5, "");
#if defined(__SPANISH__)
    if(G_parameter.itp_sw == 1)
    {
        return;
    }
#endif
    if(len > 1000 || len <= 0)
    {
        LOGD(L_APP, L_V1, "ERROR: Data length abnormalities(%d)!", len);
        return;
    }
    size = 11 + 1/*datatype*/ + len;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    sendData[i++] = datatype;

    if(datatype == 0)
    {
        track_fun_reverse_16(&sendData[i++], volt);
    }
    else
    {
        memcpy(&sendData[i], data, len);
        i += len;
    }

    no = DataPacketEncode79(0x94, sendData, size);
    track_socket_queue_send_netcmd_reg(sendData, size, 0x94, 0);
    Ram_Free(sendData);
#endif

}


kal_uint16 track_cust_paket_98_data(kal_uint8 *getData , kal_uint8 type, kal_uint8 *sendData, kal_uint16 len)
{
    getData[0] = type;
    getData[1] = (len & 0xFF00) >> 8;
    getData[2] = (len & 0x00FF);
    memcpy(&getData[3], sendData, len);
}

kal_uint16 track_cust_paket_98(void)
{
#if 1//__NF2318__
	return 1;
#else
    U8 *sendData, *chip_id;
    U16 no;
    int size, i, ret, index, tmp_i, tmp_j;
    kal_uint8 Data[23] = {0};
    kal_uint8 tmp_Data[12] = {0};


    size = 11 + (8 + 3)/*imei*/ + (8 + 3)/*imsi*/ + 10 + 3/*iccid*/ + 16 + 3/*chip id*/ + 6 + 3/*bt mac*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "Ram_Alloc NULL!!");
        return;
    }
    memset(sendData, 0, size);
    // imei
    track_cust_paket_98_data(&sendData[5], 0x00, track_drv_get_imei(1), 8);

    //imsi
    track_cust_paket_98_data(&sendData[16], 0x01, track_drv_get_imsi(1), 8);
    //iccid
    memcpy(Data, (kal_uint8*)OTA_ell_get_iccid(), 20);
    LOGD(L_APP, L_V5, "iccid:%s", Data);
    track_cust_paket_98_data(&sendData[27], 0x02, track_fun_stringtohex(Data, 20), 10);
    // Chip ID
    chip_id = track_drv_get_chip_id();
    track_cust_paket_98_data(&sendData[40], 0x03, chip_id, 16);

#if defined (__BLE_GATT__)
    //bt_mac 
    track_cust_paket_98_data(&sendData[59], 0x04, &track_bt_addr.addr[0], 6);
#endif /* __CUST_BT__ */

    no = DataPacketEncode79(0x98, sendData, size);
    LOGH(L_APP, L_V5, sendData, size);
    track_socket_queue_send_netcmd_reg(sendData, size, 0x98, 0);
    Ram_Free(sendData);

    return no;
#endif
}

void track_cust_up_900a_handle(void)
{
    kal_uint8 sendData[50] = {0};
    kal_uint8 Data[23] = {0};
    kal_uint8 tmp_Data[12] = {0};
    kal_uint8 i, j;

    memcpy(sendData, track_drv_get_imei(1), 8);
    memcpy(&sendData[8], track_drv_get_imsi(1), 8);
    memcpy(Data, (kal_uint8*)OTA_ell_get_iccid(), 20);
    memcpy(&sendData[16], track_fun_stringtohex(Data, 20), 10);
    track_cust_paket_94(0x0A, sendData, 26);
}

#if defined(__AMS_HEX_LOG__)
void AMS_HEXlog_upload(U8 *data, U16 len)
{
    U8 *sendData, i = 0;
    int size;

    size = 1/*packet type*/ + 1/*module ID*/ + 2/*module length*/ + 1/*不同的十六进制的格式*/ + len/*module data*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return;
    }

    // packet type
    sendData[i++] = 0x77;

    // module ID (Hex log == 0x05)
    sendData[i++] = 0x05;

    // module length (2 byte)
    PUT_UINT16_BE(len + 1, sendData, i);
    i += 2;

    // hex type
    sendData[i++] = 0x01;

    // module data
    memcpy(&sendData[i], data, len);
    i += len;

    track_cust_paket_FD(sendData, size, 0);
    LOGH(L_APP, L_V6, sendData, size);
    Ram_Free(sendData);
}
#endif /* __AMS_HEX_LOG__ */


/******************************************************************************
 *  Function    -  track_cust_paket_9404_handle
 *
 *  Purpose     -
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 10-09-2015,  Cjj  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_paket_9404_handle(void)
{
    kal_uint8 *sendData;
    char data[200] = {0}, sos[68] = {0}, center[26] = {0}, fence[70] = {0};
    char in_out[10] = {0}, mode_st[24] = {0};
#if defined(__SAME_GT02__)
    return;
#endif /* __SAME_GT02__ */
    if(!track_soc_login_status())
    {
        tr_start_timer(TRACK_CUST_PACKET_94O4_DELAY_ID, 60000, track_cust_paket_9404_handle);
        return;

    }
    sendData = (U8*)Ram_Alloc(5, 5);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, 5);
    /*
    第7   Bit,震动报警   开关
    第6   Bit,网络报警
    第5   Bit,电话报警
    第4   Bit,短信报警

    第3   Bit,位移报警   开关
    第2   Bit,网络报警
    第1   Bit,电话报警
    第0   Bit,短信报警
    */
    if(G_parameter.displacement_alarm.alarm_type == 0)
    {
        sendData[0] |= 0x04;
    }
    if(G_parameter.displacement_alarm.alarm_type == 1)
    {
        sendData[0]   |= 0x05;
    }
    if(G_parameter.displacement_alarm.alarm_type == 2)
    {
        sendData[0]   |= 0x07;
    }
    if(G_parameter.displacement_alarm.alarm_type == 3)
    {
        sendData[0]   |= 0x06;
    }
    if(G_parameter.displacement_alarm.sw == 1)
    {
        sendData[0]   |= 0x08 ;
    }
    if(G_parameter.vibrates_alarm.alarm_type == 0)
    {
        sendData[0]  |= 0x40;
    }
    if(G_parameter.vibrates_alarm.alarm_type == 1)
    {
        sendData[0]   |= 0x50 ;
    }
    if(G_parameter.vibrates_alarm.alarm_type == 2)
    {
        sendData[0]   |= 0x70;
    }
    if(G_parameter.vibrates_alarm.alarm_type == 3)
    {
        sendData[0]   |= 0x60;
    }
    if(G_parameter.vibrates_alarm.sw == 1)
    {
        sendData[0]   |= 0x80;
    }
    LOGD(L_APP, L_V5, "ALM1=%x", sendData[0]);
    /*
    第7   Bit,内部低电报警   开关
    第6   Bit,网络报警
    第5   Bit,电话报警
    第4   Bit,短信报警

    第3   Bit,外部低电报警   开关
    第2   Bit,网络报警
    第1   Bit,电话报警
    第0   Bit,短信报警
        */
    if(G_parameter.power_extbatalm.alarm_type == 0)
    {
        sendData[1] |= 0x04;
    }
    if(G_parameter.power_extbatalm.alarm_type == 1)
    {
        sendData[1]   |= 0x05;
    }
    if(G_parameter.power_extbatalm.alarm_type == 2)
    {
        sendData[1]   |= 0x07;
    }
    if(G_parameter.power_extbatalm.alarm_type == 3)
    {
        sendData[1]   |= 0x06;
    }
    if(G_parameter.power_extbatalm.sw == 1)
    {
        sendData[1]   |= 0x08 ;
    }
    if(G_parameter.low_power_alarm.alarm_type == 0)
    {
        sendData[1]  |= 0x40;
    }
    if(G_parameter.low_power_alarm.alarm_type == 1)
    {
        sendData[1]   |= 0x50 ;
    }
    if(G_parameter.low_power_alarm.alarm_type == 2)
    {
        sendData[1]   |= 0x70;
    }
    if(G_parameter.low_power_alarm.alarm_type == 3)
    {
        sendData[1]   |= 0x60;
    }
    if(G_parameter.low_power_alarm.sw == 1)
    {
        sendData[1]   |= 0x80;
    }

    /*
    第7   Bit,超速报警   开关
    第6   Bit,网络报警
    第5   Bit,电话报警
    第4   Bit,短信报警

    第3   Bit,断电报警   开关
    第2   Bit,网络报警
    第1   Bit,电话报警
    第0   Bit,短信报警
        */
    if(G_parameter.power_fails_alarm.alarm_type == 0)
    {
        sendData[2] |= 0x04;
    }
    if(G_parameter.power_fails_alarm.alarm_type == 1)
    {
        sendData[2]   |= 0x05;
    }
    if(G_parameter.power_fails_alarm.alarm_type == 2)
    {
        sendData[2]   |= 0x07;
    }
    if(G_parameter.power_fails_alarm.alarm_type == 3)
    {
        sendData[2]   |= 0x06;
    }
    if(G_parameter.power_fails_alarm.sw == 1)
    {
        sendData[2]   |= 0x08 ;
    }
    if(G_parameter.speed_limit_alarm.alarm_type == 0)
    {
        sendData[2]  |= 0x40;
    }
    if(G_parameter.speed_limit_alarm.alarm_type == 1)
    {
        sendData[2]   |= 0x50 ;
    }
    if(G_parameter.speed_limit_alarm.alarm_type == 2)
    {
        sendData[2]   |= 0x70;
    }
    if(G_parameter.speed_limit_alarm.alarm_type == 3)
    {
        sendData[2]   |= 0x60;
    }
    if(G_parameter.speed_limit_alarm.sw == 1)
    {
        sendData[2]   |= 0x80;
    }

    /*
    第7   Bit,设防状态  设防置1
    第6   Bit,自动设防
    第5   Bit,手动设防
    第4   Bit,

    第3   Bit,
    第2   Bit,
    第1   Bit,
    第0   Bit,
    */
    if(G_realtime_data.defense_mode == 1)
    {
        sendData[3]   |= 0x20 ; //手动
    }
    else
    {
        sendData[3]   |= 0x40 ; //自动
    }
    if(G_realtime_data.defences_status == 3)
    {
        sendData[3]   |= 0x80 ;
    }
#if defined(__GT370__)|| defined (__GT380__)||defined(__GT300S__)
    if(G_realtime_data.switch_down == 1)
    {
        sendData[3] |= 0x02;
    }
    if(G_parameter.teardown_str.sw == 1) //防拆报警开关
    {
        sendData[3] |= 0x01;
    }
#endif
    /*
    第7   Bit,
    第6   Bit,
    第5   Bit,
    第4   Bit,

    第3   Bit,请求断开，因超速未发
    第2   Bit,请求断开，未定位
    第1   Bit,断开油电
    第0   Bit,接通油电
        */
    if(G_realtime_data.oil_status == 0)
    {
        sendData[4] |= 0x01;
    }
    if(G_realtime_data.oil_status == 1)
    {
        sendData[4]   |= 0x02;
    }
    if(G_realtime_data.oil_status == 2)
    {
        sendData[4]   |= 0x04;
    }
    if(G_realtime_data.oil_status == 3)
    {
        sendData[4]   |= 0x08 ;
    }
    /*      if(G_realtime_data.oil_status == 4)
          {
              sendData  |= 0x10;
          } */

    //SOS号码
    sprintf(sos, "SOS=%s,%s,%s", G_parameter.sos_num[0], G_parameter.sos_num[1], G_parameter.sos_num[2]);
    //中心号码
    sprintf(center, "CENTER=%s",  G_parameter.centerNumber);
//围栏
    if(G_parameter.fence[0].in_out == 0)
        sprintf(in_out, "IN");
    else if(G_parameter.fence[0].in_out == 1)
        sprintf(in_out, "OUT");
    else if(G_parameter.fence[0].in_out == 2)
        sprintf(in_out, "IN or OUT");
    if(G_parameter.fence[0].square == 0)
    {
        sprintf(fence, "Fence,%s,%d,%.6f,%.6f,%d,%s,%d",
                ON_OFF(G_parameter.fence[0].sw),
                G_parameter.fence[0].square,
                G_parameter.fence[0].lat,
                G_parameter.fence[0].lon,
                G_parameter.fence[0].radius * 100,
                in_out, G_parameter.fence[0].alarm_type);
    }
    else
    {
        sprintf(fence, "Fence,%s,%d,%.6f,%.6f,%.6f,%.6f,%s,%d",
                ON_OFF(G_parameter.fence[0].sw),
                G_parameter.fence[0].square,
                G_parameter.fence[0].lat,
                G_parameter.fence[0].lon,
                G_parameter.fence[0].lat2,
                G_parameter.fence[0].lon2,
                in_out, G_parameter.fence[0].alarm_type);
    }
#if defined(__GT370__)|| defined (__GT380__)
    if(G_parameter.work_mode.mode == 3)
    {
        sprintf(mode_st, "MODE,%d,%d:%d,%d", 2, G_parameter.work_mode.datetime / 60, G_parameter.work_mode.datetime % 60,  G_parameter.work_mode.mode3_timer / 60);
    }
    else
    {
        sprintf(mode_st, "MODE,%d,%d,%d", 1, G_parameter.gps_work.Fti.interval_acc_on, G_parameter.gps_work.Fti.interval_acc_off);
    }
    sprintf(data, "ALM1=%0.2X;ALM2=%0.2X;ALM3=%0.2X;STA1=%0.2X;DYD=%0.2X;%s;%s;FENCE=%s;ICCID=%s;MODE=%s;", \
            sendData[0], sendData[1], sendData[2], sendData[3], sendData[4], sos, center, fence, \
            OTA_ell_get_iccid(), mode_st);
#elif  defined(__GT300S__)
    if(G_parameter.work_mode.mode == 2)
    {
        sprintf(mode_st, "MODE,%d,%d", G_parameter.work_mode.mode, G_parameter.gps_work.Fti.interval_acc_on);
    }
    else  if(G_parameter.work_mode.mode == 1)
    {
        sprintf(mode_st, "MODE,%d,%d",  G_parameter.work_mode.mode, G_parameter.work_mode.mode1_timer);

    }
    else if(G_parameter.work_mode.mode == 3)
    {

        sprintf(mode_st, "MODE,%d,%0.2d:%0.2d,%d",  G_parameter.work_mode.mode,
                G_parameter.work_mode.datetime / 60,  G_parameter.work_mode.datetime % 60,  G_parameter.work_mode.mode3_timer / 60);

    }
    sprintf(data, "ALM1=%0.2X;ALM2=%0.2X;ALM3=%0.2X;STA1=%0.2X;DYD=%0.2X;%s;%s;FENCE=%s;ICCID=%s;MODE=%s;", \
            sendData[0], sendData[1], sendData[2], sendData[3], sendData[4], sos, center, fence, \
            OTA_ell_get_iccid(), mode_st);

#else
    sprintf(data, "ALM1=%0.2X;ALM2=%0.2X;ALM3=%0.2X;STA1=%0.2X;DYD=%0.2X;%s;%s;FENCE=%s;", sendData[0], sendData[1], sendData[2], sendData[3], sendData[4], sos, center, fence);
#endif
    LOGD(L_APP, L_V5, "%d,sos=%d,cen=%d,fencen=%d", strlen(data), strlen(sos), strlen(center), strlen(fence));
    LOGD(L_APP, L_V5, "%s", data);
    track_cust_paket_94(04, data, strlen(data));
    Ram_Free(sendData);
}

/******************************************************************************
 *  Function    -  track_cust_paket_position
 *
 *  Purpose     -  判断上传的数据包是否使用带UTC时间
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_uint16 track_cust_paket_position(
    track_gps_data_struct *gd,
    LBS_Multi_Cell_Data_Struct *lbs,
    kal_uint8 packet_type,
    kal_uint8 packet_status)
{
    kal_uint16 no;
#if defined(__SAME_GT02__)
    LOGD(L_APP, L_V7, "02 要打包啦packet_type :%d; packet_status :%d", packet_type, packet_status);
    no = track_cust_paket_gpsdata(gd, lbs);
#elif defined(__NF2318__)
	track_cust_N07_paket_02(gd, lbs);
#else
    if(track_cust_is_upload_UTC_time())
    {
        no = track_cust_paket_22(gd, lbs, packet_type, packet_status);
    }
    else
    {
#if defined(__TRACK_HAND_DEVICE__)
        no = track_cust_paket_10(gd);
#elif defined (__TRACK_CAR_DEVICE__)
    no = track_cust_paket_12(gd, lbs);
#else
    no = track_cust_paket_12(gd, lbs);
#endif
    }
#endif
    return no;
}

/******************************************************************************
 *  Function    -  track_cust_paket_msg_upload
 *
 *  Purpose     -  判断回应服务器下发的指令是否使用使用新的协议
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_paket_msg_upload(kal_uint8 *serverid, kal_bool isASCII, kal_uint8 *data, int datalen)
{
#if defined(__SAME_GT02__)
    if(datalen < 255)
    {
        Server_GPRS_Command(serverid, isASCII, data, datalen);
    }
    else
    {
        track_cust_paket_21(serverid, isASCII, data, datalen);
    }
#else

    if(track_cust_is_upload_UTC_time())
    {
        track_cust_paket_21(serverid, isASCII, data, datalen);
    }
    else if(isASCII)
    {
        if(datalen < 200)
        {
            track_cust_paket_15(serverid, data, datalen);
        }
        else
        {
            track_cust_paket_21(serverid, isASCII, data, datalen);
        }
    }
    else
    {
        track_cust_paket_21(serverid, isASCII, data, datalen);
    }
#endif
}

kal_int8 track_cust_paket_FD(kal_uint8 *data, kal_uint16 len, U8 packet_type)
{
    U8 *sendData, i = 5;
    U16 no;
    int size, ret;
    size = 11 + 8/*imei*/ + 2/*ext data len*/ + len/*ext data*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return;
    }
    memset(sendData, 0, size);

    // imei
    memcpy(&sendData[i], track_drv_get_imei(1), 8);
    i += 8;

    /* 透传数据的长度 */
    sendData[i++] = (len & 0xFF00) >> 8;
    sendData[i++] = (len & 0x00FF);

    /* 填充需要透传的数据 */
    memcpy(&sendData[i], data, len);

    no = DataPacketEncode79(0xFD, sendData, size);
    LOGD(L_APP, L_V5, "");
    LOGH(L_APP, L_V7, sendData, size);
    track_cust_server2_write_req(0, sendData, size, packet_type);
    Ram_Free(sendData);
    return ret;
}

kal_int8 track_cust_paket_terminal_ID(void)
{
    U8 *sendData, *chip_id, i = 0;
    U16 no;
    char *ver_string = track_cust_get_version_for_upload_server();
    int size, ver_str_len = strlen(ver_string);

    size = 1/*packet type*/ + 16/*Chip ID*/ + 1/*version string length*/ + ver_str_len/*version string*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return -1;
    }
    memset(sendData, 0, size);

    // packet type
    sendData[i++] = 0;

    // Chip ID
    chip_id = track_drv_get_chip_id();
    memcpy(&sendData[i], chip_id, 16);
    i += 16;

    // version string length
    sendData[i++] = ver_str_len;

    // version string
    memcpy(&sendData[i], ver_string, ver_str_len);
    i += ver_str_len;
    LOGD(L_APP, L_V5, "%s", ver_string);

    track_cust_paket_FD(sendData, size, 0);
    LOGH(L_APP, L_V4, sendData, size);
    Ram_Free(sendData);
    return 0;
}


kal_int8 track_cust_paket_epo_file_head(kal_uint8 filetype)
{
    kal_uint8 buf[2];
    buf[0] = filetype;
    buf[1] = 0x01;
    track_cust_paket_FD(buf, 2, 0);
}

kal_int8 track_cust_paket_epo_file_content(kal_uint8 filetype, kal_uint32 data_type, kal_uint32 data_req_begin, kal_uint16 data_req_len)
{
    U8 *sendData, i = 0;
    U16 no;
    int size;
    kal_int8 ret;

    size = 2/*packet type*/ + 4/*data_type*/ + 4/*data_req_begin*/ + 2/*data_req_len*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return -1;
    }
    memset(sendData, 0, size);

    // packet type
    sendData[i++] = filetype;
    sendData[i++] = 3;

    // data_type
    memcpy(&sendData[i], &data_type, 4);
    i += 4;

    // data_req_begin
    sendData[i++] = (data_req_begin & 0xFF000000) >> 24;
    sendData[i++] = (data_req_begin & 0x00FF0000) >> 16;
    sendData[i++] = (data_req_begin & 0x0000FF00) >> 8;
    sendData[i++] = (data_req_begin & 0x000000FF);

    // data_req_len
    sendData[i++] = (data_req_len & 0xFF00) >> 8;
    sendData[i++] = (data_req_len & 0x00FF);

    track_cust_paket_FD(sendData, size, 0);
    LOGD(L_APP, L_V5, "");
    Ram_Free(sendData);
    return 0;
}

void track_cust_paket_FD2(kal_uint8 *data, kal_uint16 len)
{
    U8 i = 5;

    // imei
    memcpy(&data[i], track_drv_get_imei(1), 8);
    i += 8;

    DataPacketEncode79(0xFD, data, len);
    LOGD(L_APP, L_V5, "");
    LOGH(L_APP, L_V7, data, len);
}

kal_int8 track_cust_net2_param(kal_uint16 len, kal_uint8* data)
{
    LBS_Multi_Cell_Data_Struct *lbs = track_drv_get_lbs_data();
    U8 *sendData, i = 13;
    U16 volt;
    int size;
    kal_int8 ret;

    len += 1/*packet type*/;
    size = 11 + 8/*imei*/ + 2/*ext data len*/ + len/*ext data*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return -1;
    }
    memset(sendData, 0, size);

    /* 透传数据的长度 */
    sendData[i++] = (len & 0xFF00) >> 8;
    sendData[i++] = (len & 0x00FF);

    // packet type
    sendData[i++] = 0x0a;

    memcpy(&sendData[i], data, len);
    i += len;

    track_cust_paket_FD2(sendData, size);
    track_cust_server2_write_req(1, sendData, size, 0);
    LOGD(L_APP, L_V5, "");
    Ram_Free(sendData);
    return 0;
}

void track_cust_paket_param(kal_uint8 type)
{
    kal_uint8 data[1000] = {0};
    kal_uint8 tmp[200] = {0};
    kal_uint32 len = 2000, l = 0;
    char PRN[5] = {0};
    kal_uint8  i, j, x, sat = 0;
    char GPS_PRN[80] = {0};
    track_gps_data_struct *gd = track_drv_get_gps_data();
    kal_bool head = KAL_TRUE;
    char *ver;
    nvram_GPRS_APN_struct *use_apn = track_socket_get_use_apn();
    charge_measure_struct charge_measure = {0};
    track_bmt_get_ADC_result(&charge_measure);
    ver = track_get_app_version();
    if(strlen(ver) <= 0)
    {
        ver = (char*)release_verno();
    }

    l += OTA_snprintf(data + l, len - l, "IMEI:%s\r\n", (char *)track_drv_get_imei(0));

    if(strlen(G_importance_parameter_data.version_string) > 0)
    {
        l += OTA_snprintf(data + l, len - l, "VERSION:%s_%s\r\n", ver, G_importance_parameter_data.version_string);
    }
    else
    {
        l += OTA_snprintf(data + l, len - l, "VERSION:%s\r\n", ver);
    }

    if(G_importance_parameter_data.dserver.server_type)
    {
        if(G_importance_parameter_data.dserver.conecttype == 0)
        {
            l += OTA_snprintf(data + l, len - l, "DSERVER:0,%d.%d.%d.%d,%d,%d\r\n",
                              G_importance_parameter_data.dserver.server_ip[0], G_importance_parameter_data.dserver.server_ip[1],
                              G_importance_parameter_data.dserver.server_ip[2], G_importance_parameter_data.dserver.server_ip[3],
                              G_importance_parameter_data.dserver.server_port, G_importance_parameter_data.dserver.soc_type);
        }
        else
        {
            l += OTA_snprintf(data + l, len - l, "DSERVER:%d,%s,%d,%d\r\n",
                              G_importance_parameter_data.dserver.conecttype,
                              track_domain_decode(G_importance_parameter_data.dserver.url),
                              G_importance_parameter_data.dserver.server_port,
                              G_importance_parameter_data.dserver.soc_type);
        }
    }
    else
    {
        if(G_importance_parameter_data.server.conecttype == 0)
        {
            l += OTA_snprintf(data + l, len - l, "SERVER:0,%d.%d.%d.%d,%d,%d\r\n",
                              G_importance_parameter_data.server.server_ip[0], G_importance_parameter_data.server.server_ip[1],
                              G_importance_parameter_data.server.server_ip[2], G_importance_parameter_data.server.server_ip[3],
                              G_importance_parameter_data.server.server_port, G_importance_parameter_data.server.soc_type);
        }
        else
        {
            l += OTA_snprintf(data + l, len - l, "SERVER:%d,%s,%d,%d\r\n",
                              G_importance_parameter_data.server.conecttype,
                              track_domain_decode(G_importance_parameter_data.server.url),
                              G_importance_parameter_data.server.server_port,
                              G_importance_parameter_data.server.soc_type);
        }
    }
    l += OTA_snprintf(data + l, len - l, "%s\r\n", track_soc_get_IP());



    l += OTA_snprintf(data + l, len - l, "APN:%s,%d\r\n", use_apn->apn, !G_importance_parameter_data.apn.custom_apn_valid);

    l += OTA_snprintf(data + l, len - l, "CSQ:%d\r\n",  track_cust_get_rssi(-1));


    l += OTA_snprintf(data + l, len - l, "GPRS:%d\r\n", G_parameter.gprson);

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
    i = track_cust_gps_status();
    if(i > 2)i = 1;
    else if(i > 0)i = 2;
    else i = 0;
    l += OTA_snprintf(data + l, len - l, "GPS:%d,%d,%s\r\n", i, gd->gpgga.sat, GPS_PRN);

    l += OTA_snprintf(data + l, len - l, "BAT:%d\r\n", (float)charge_measure.bmt_vBat);


    l += OTA_snprintf(data + l, len - l, "POWER:%d\r\n", (float)track_drv_get_batter_voltage() / 1000000.0);
    if(G_parameter.gps_work.Fti.sw)
    {
        l += OTA_snprintf(data + l, len - l, "TIMER:%d,%d\r\n", G_parameter.gps_work.Fti.interval_acc_on, G_parameter.gps_work.Fti.interval_acc_off);
    }
    if(G_parameter.gps_work.Fd.sw)
    {
        l += OTA_snprintf(data + l, len - l, "DISTANCE:%%d\r\n", G_parameter.gps_work.Fd.distance);
    }
    if(4 == TRACK_DEFINE_SOS_COUNT)
    {
        l += OTA_snprintf(data + l, len - l, "SOS NUM:%s ,%s,%s ,%s\r\n", G_parameter.sos_num[0], G_parameter.sos_num[1], G_parameter.sos_num[2], G_parameter.sos_num[3]);
    }
    else
    {
        l += OTA_snprintf(data + l, len - l, "SOS NUM:%s ,%s,%s \r\n", G_parameter.sos_num[0], G_parameter.sos_num[1], G_parameter.sos_num[2]);

    }
    l += OTA_snprintf(data + l, len - l, "SOS NUM:%s ,%s,%s\r\n", G_parameter.sos_num[0], G_parameter.sos_num[1], G_parameter.sos_num[2]);
    l += OTA_snprintf(data + l, len - l, "FN NUM:%s,%s \r\n", G_phone_number.fn_num[0], G_phone_number.fn_num[1]);

    l += OTA_snprintf(data + l, len - l, "CENTER NUM:%s \r\n", G_parameter.centerNumber);
    l += OTA_snprintf(data + l, len - l, "ICCID:%s \r\n", OTA_ell_get_iccid());
    l += OTA_snprintf(data + l, len - l, "EURL:%s \r\n", G_parameter.url);
    l += OTA_snprintf(data + l, len - l, "BAT TEMP:%d \r\n", charge_measure.bmt_vTemp / 100000);
    if(type == CM_ONLINE)
    {
        track_cust_paket_94(0x8, data, strlen(data));
    }
    else if(type == CM_AT)
    {
        LOGS(data);
    }
    else if(type == CM_ONLINE2)
    {
        track_cust_net2_param(strlen(data), data);
    }
}
kal_int8 track_cust_paket_volt(U8 type)
{
    LBS_Multi_Cell_Data_Struct *lbs = track_drv_get_lbs_data();
    U8 *sendData, i = 13;
    U16 volt, len;
    int size;
    kal_int8 ret;

    len = 1/*packet type*/ + 2/*volt*/;
    size = 11 + 8/*imei*/ + 2/*ext data len*/ + len/*ext data*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return -1;
    }
    memset(sendData, 0, size);

    /* 透传数据的长度 */
    sendData[i++] = (len & 0xFF00) >> 8;
    sendData[i++] = (len & 0x00FF);

    // packet type
    sendData[i++] = 0x06;
// volt
#if defined(__GT740__)
    if(track_cust_get_real_battery_volt() > 10000)
        volt = track_cust_get_real_battery_volt() / 10000;
    else
        volt = 0;
#else
    if(track_cust_get_ext_volt() > 10000)
        volt = track_cust_get_ext_volt() / 10000;
    else
        volt = 0;
#endif


    sendData[i++] = (volt & 0xFF00) >> 8;
    sendData[i++] = (volt & 0x00FF);

    track_cust_paket_FD2(sendData, size);
    track_cust_server2_write_req(1, sendData, size, 0);
    LOGD(L_APP, L_V5, "");
    Ram_Free(sendData);
    return 0;
}

kal_int8 track_cust_paket_lbs(void)
{
    LBS_Multi_Cell_Data_Struct *lbs = track_drv_get_lbs_data();
    U8 *sendData, i = 0;
    U16 no;
    int size;
    kal_int8 ret;

    size = 1/*packet type*/ + 38/*lbs*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return -1;
    }
    memset(sendData, 0, size);

    // packet type
    sendData[0] = 0x03;

    // lbs
    DataPackingLbs_38(&sendData[1], lbs);

    track_cust_paket_FD(sendData, size, 0);
    LOGD(L_APP, L_V5, "");
    Ram_Free(sendData);
    return 0;
}

void track_cust_paket_FD_cmd(kal_uint8 *serverid, kal_bool isASCII, kal_uint8 *data, int datalen)
{
    U8 *sendData, i = 0;
    U16 no;
    int size;

    if(datalen <= 0 || datalen > 1000)
    {
        LOGD(L_APP, L_V1, "ERROR: outstrlen=%d", datalen);
        return;
    }

    size = 1/*packet type*/ + 4/*server id*/ + 1/*code_page*/ + datalen/*data*/;

    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return;
    }
    memset(sendData, 0, size);

    // packet type
    sendData[i++] = 0x04;

    //服务器标志位
    memcpy(&sendData[i], serverid, 4);
    i += 4;

    //code_page
    if(isASCII)
    {
        sendData[i++] = 1;
    }
    else
    {
        sendData[i++] = 2;
    }

    //内容
    memcpy(&sendData[i], data, datalen);
    i += datalen;

    track_cust_paket_FD(sendData, size, 0);
    LOGD(L_APP, L_V5, "");
    Ram_Free(sendData);
}

/******************************************************************************
 *  Function    -  cust_packet_log
 *
 *  Purpose     -  在线网络日志
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void cust_packet_log(kal_uint8 errorid, kal_uint8 type, kal_uint8 filter, kal_uint16 sn, float _distance, float lat, float lon)
{
    U8 *sendData;
    int size, i;
    applib_time_struct currTime = {0};
    kal_uint32 tmp;
    char tt[10] = {0};
    U16 no;
    track_gps_data_struct * gpsdata = track_drv_get_gps_data();

    applib_dt_get_rtc_time(&currTime);
    size = 49;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    i = 4;
    /* 时分秒 */
    sprintf(tt, "%0.2d%0.2d%0.2d", currTime.nHour, currTime.nMin, currTime.nSec);
    sendData[i++] = ((tt[0] - 0x30) << 4) + (tt[1] - 0x30);
    sendData[i++] = ((tt[2] - 0x30) << 4) + (tt[3] - 0x30);
    sendData[i++] = ((tt[4] - 0x30) << 4) + (tt[5] - 0x30);

    /* 日志类型 */
    sendData[i++] = errorid;

    /* 位置上传类型 */
    sendData[i++] = type;

    /* 过滤编号 */
    sendData[i++] = filter;

    /* 流水号 */
    sendData[i++] = ((sn & 0xFF00) >> 8);
    sendData[i++] = (sn & 0x00FF);

    /* GSM信号等级 */
    sendData[i++] = track_cust_get_rssi(-1);

    /* Sensor距离上一次检测到的次数 */
    sendData[i++] = track_cust_sensor_count(3);

    /* ACC */
    sendData[i++] = track_cust_status_acc();

    /* 外接电源 */
    sendData[i++] = track_cust_status_charger();

    /* GPS当前的工作状态 开/关，3D/2D定位 */
    sendData[i++] = track_cust_gps_status();

    /* GPS当前正在使用的卫星数 */
    sendData[i++] = gpsdata->gpgga.sat;

    /* 最强信号的3颗卫星的平均信号值 */
    sendData[i++] = gpsdata->gpgsa.satellite_SNR_used_average;

    /* GPS水平精度因子 */
    tmp = gpsdata->gpgsa.HDOP * 100;
    track_fun_reverse_32(&sendData[i], tmp);
    i += 4;

    /* 速度 */
    tmp = gpsdata->gprmc.Speed * 100;
    track_fun_reverse_32(&sendData[i], tmp);
    i += 4;

    /* 角度 */
    tmp = gpsdata->gprmc.Course * 100;
    track_fun_reverse_32(&sendData[i], tmp);
    i += 4;

    /* 距离 */
    if(_distance > 0)
    {
        tmp = _distance * 100;
    }
    else
    {
        tmp = 0;
    }
    track_fun_reverse_32(&sendData[i], tmp);
    i += 4;

    /* 纬度 */
    if(lat > 0)
    {
        track_fun_LongitudeLatitudeToHex(&sendData[i], lat);
    }
    i += 4;

    /* 经度 */
    if(lon > 0)
    {
        track_fun_LongitudeLatitudeToHex(&sendData[i], lon);
    }
    i += 4;

    no = DataPacketEncode78(0xFF, sendData, size);
    //no = (sendData[size-5] << 8) + sendData[size-4];
    LOGD(L_APP, L_V6, "no=%d HDOP=%f, speed=%f, Course=%f, distance=%d, lat=%f, lon=%f",
         no, gpsdata->gpgsa.HDOP, gpsdata->gprmc.Speed, gpsdata->gprmc.Course, _distance, lat, lon);
    track_socket_queue_send_log_reg(sendData, size, 0xFF, no);
    Ram_Free(sendData);

}

/******************************************************************************
 *  Function    -  cust_packet_log_data
 *
 *  Purpose     -  在线网络日志（自定义数据）
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void cust_packet_log_data(kal_uint8 type, kal_uint8 *data, kal_uint16 len)
{
    U8 *sendData;
    int size, i;
    applib_time_struct currTime = {0};
    char tt[10] = {0};
    U16 no;

    if(len > 1024 || len == 0) return;
    size = 11 + 5 + len;
    applib_dt_get_rtc_time(&currTime);
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    i = 5;
    /* 时分秒 */
    sprintf(tt, "%0.2d%0.2d%0.2d", currTime.nHour, currTime.nMin, currTime.nSec);
    sendData[i++] = ((tt[0] - 0x30) << 4) + (tt[1] - 0x30);
    sendData[i++] = ((tt[2] - 0x30) << 4) + (tt[3] - 0x30);
    sendData[i++] = ((tt[4] - 0x30) << 4) + (tt[5] - 0x30);

    /* 日志类型 */
    sendData[i++] = 64;

    /* 日志类型 */
    sendData[i++] = type;

    /* 填充日志数据 */
    memcpy(&sendData[i], data, len);

    no = DataPacketEncode79(0xFF, sendData, size);
    LOGD(L_APP, L_V6, "");
    track_socket_queue_send_log_reg(sendData, size, 0xFF, no);
    Ram_Free(sendData);
}
void cust_packet_log_data_ext2(kal_uint8 type, char *head, kal_uint8 *data, kal_uint16 len)
{
    U8 *sendData;
    int size, i, head_len = 0;
    applib_time_struct currTime = {0};
    char tt[10] = {0};
    U16 no;

    if(len > 1024 || len == 0) return;
    if(head != NULL) head_len = strlen(head);
    size = 11 + 5 + len + head_len;
    applib_dt_get_rtc_time(&currTime);
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    i = 5;
    /* 时分秒 */
    sprintf(tt, "%0.2d%0.2d%0.2d", currTime.nHour, currTime.nMin, currTime.nSec);
    sendData[i++] = ((tt[0] - 0x30) << 4) + (tt[1] - 0x30);
    sendData[i++] = ((tt[2] - 0x30) << 4) + (tt[3] - 0x30);
    sendData[i++] = ((tt[4] - 0x30) << 4) + (tt[5] - 0x30);

    /* 日志类型 */
    sendData[i++] = 64;

    /* 日志类型 */
    sendData[i++] = type;

    /* 填充日志数据 */
    if(head_len > 0)
    {
        memcpy(&sendData[i], head, head_len);
        i += head_len;
    }
    memcpy(&sendData[i], data, len);

    no = DataPacketEncode79(0xFF, sendData, size);
    LOGD(L_APP, L_V6, "");
    track_socket_queue_send_log_reg(sendData, size, 0xFF, no);
    Ram_Free(sendData);
}

/******************************************************************************
 *  Function    -  track_cust_ram_alarm
 *
 *  Purpose     -  内存异常网络日志
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_ram_alarm(kal_uint32 freesize, kal_uint32 mem_size)
{
    U8 sendData[30] = {0};
    int size, i;
    applib_time_struct currTime = {0};
    char tt[10] = {0};
    U16 no;

    applib_dt_get_rtc_time(&currTime);
    size = 10 + 3 + 1 + 8;

    i = 4;
    /* 时分秒 */
    sprintf(tt, "%0.2d%0.2d%0.2d", currTime.nHour, currTime.nMin, currTime.nSec);
    sendData[i++] = ((tt[0] - 0x30) << 4) + (tt[1] - 0x30);
    sendData[i++] = ((tt[2] - 0x30) << 4) + (tt[3] - 0x30);
    sendData[i++] = ((tt[4] - 0x30) << 4) + (tt[5] - 0x30);

    /* 日志类型 */
    sendData[i++] = 0xFE;

    memcpy(&sendData[i], &freesize, 4);
    i += 4;
    memcpy(&sendData[i], &mem_size, 4);

    no = DataPacketEncode78(0xFF, sendData, size);
    LOGD(L_APP, L_V6, "freesize=%d, mem_size=%d", freesize, mem_size);
    track_socket_queue_send_log_reg(sendData, size, 0xFF, no);
}

/******************************************************************************
 *  Function    -  track_cust_paket_position_change_renew
 *
 *  Purpose     -  改变备份中的定位包为补传方式
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 05-03-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_paket_position_change_renew(kal_uint8 *data, int len)
{
    int size;
    size = 10 + 6/*datatime*/ + 12/*gps*/ + 8/*lbs*/ + 3;
#if defined(__GT740__)
    if(len == size
            && data[0] == 0x78
            && data[1] == 0x78
            && (data[3] == 0x22 || data[3] == 0x2D)
            && data[32] == 0x00)
#else
    if(data[0] == 0x78
            && data[1] == 0x78
            && data[3] == 0x22
            && data[32] == 0x00)
#endif
    {
        U16 tmp;
        // GPS 实时补传
        // 0x00 实时上传
        // 0x01 补传
        data[32] = 0x01;

        //更新 CRC
        tmp = GetCrc16(&data[2], len - 6);
        data[len - 4] = (tmp & 0xFF00) >> 8;
        data[len - 3] = (tmp & 0x00FF);
        LOGD(L_APP, L_V5, "SerialNumber:%.2X%.2X", data[len - 6], data[len - 5]);
    }
}

/******************************************************************************
 *  Function    -  track_cust_paket_9409_handle
 *
 *  Purpose     -
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 14-02-2017,  Cjj  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_paket_9409_handle(void)
{
    kal_uint8 *sendData;
    kal_bool flag = 0;
    int size;
    kal_uint8 u = 0, i = 0, m, x, n;
    kal_uint8 temp1 = 0, temp2 = 0;
    track_gps_data_struct *gd = track_drv_get_gps_data();


    size = 8/*GPS模块标志+BD模块标志+扩展长度+扩展位+4个卫星数量统计*/ + gd->gpgsv.Satellites_In_View + gd->bdgsv.Satellites_In_View/*有几个可见星*/;
    LOGD(L_APP, L_V1, "size=%d", size);
    if(gd->gpgsv.Satellites_In_View == 0 && gd->bdgsv.Satellites_In_View == 0)
    {
        size = size - 4;
    }
    else if(gd->gpgsv.Satellites_In_View == 0 || gd->bdgsv.Satellites_In_View == 0)
    {
        size = size - 2;
    }
    LOGD(L_APP, L_V1, "size=%d", size);
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);
    if(gd == NULL)
    {
        LOGD(L_APP, L_V1, "无GPS数据");
        return;
    }
#if 1
// GPS
    LOGD(L_APP, L_V1, "gw_mode=%d", gd->gw_mode);
    if(gd->gw_mode == GPS || gd->gw_mode == GN) //有GPS模块
    {
        LOGD(L_APP, L_V1, "gps_status=%d", gd->status);
        if(gd->status == 0)
            sendData[i++] = 0x04;
        else if(gd->status == 3)
            sendData[i++] = 0x03;
        else if(gd->status == 2)
            sendData[i++] = 0x02;
        else if(gd->status == 1)
            sendData[i++] = 0x01;
        LOGD(L_APP, L_V1, "sendData[%d]", i);
        //  GPS定位星数
        if(gd->gpgsv.Satellites_In_View != 0) //搜不到任何星
        {
            LOGD(L_APP, L_V1, "gpgga.sat=%d,Satellites_In_View=%d", gd->gpgga.sat, gd->gpgsv.Satellites_In_View);
            sendData[i++] = gd->gpgga.sat;
            LOGD(L_APP, L_V1, "sendData[%d]gpgga.sat", i);
            if(gd->status == 2 || gd->status == 3)
            {
                for(m = 0; m < gd->gpgga.sat && m < MTK_GPS_SV_MAX_NUM; m++)
                {
                    for(x = 0; x < MTK_GPS_SV_MAX_NUM; x++)
                    {
                        if(gd->gpgsa.satellite_used[m] == gd->gpgsv.Satellite_ID[x])
                        {
                            sendData[i++] = gd->gpgsv.SNR[x];
                            //data[m] = x;
                            // memcpy(&data[m],&x,sizeof(x));
                            LOGD(L_APP, L_V1, "sendData[%d]", i);
                            break;
                        }
                    }
                }

                //GPS可见不参与定位星数
                LOGD(L_APP, L_V1, "可见不参与定位星数%d", (gd->gpgsv.Satellites_In_View - gd->gpgga.sat));
                sendData[i++] = (gd->gpgsv.Satellites_In_View - gd->gpgga.sat);
                temp1 = i;
                LOGD(L_APP, L_V1, "可见不参与定位星数sendData[%d]", i);
                for(x = 0, n = 0; x < MTK_GPS_SV_MAX_NUM; x++, flag = 0)
                {
                    if(gd->gpgsv.SNR[x] != 0)
                    {
                        for(m = 0; m < gd->gpgga.sat; m++)
                        {
                            if(gd->gpgsv.Satellite_ID[x] == gd->gpgsa.satellite_used[m])
                            {
                                flag = 1;
                                break;
                            }
                        }
                        if(flag == 0)
                        {
                            n += 1;
                            sendData[i++] = gd->gpgsv.SNR[x];
                            LOGD(L_APP, L_V1, "sendData[%d]", i);
                        }
                    }
                    if(n == (gd->gpgsv.Satellites_In_View - gd->gpgga.sat))
                    {
                        break;
                    }
                }
                temp2 = i - temp1;
                for(m = temp2; m < (gd->gpgsv.Satellites_In_View - gd->gpgga.sat); m++)
                {
                    sendData[i++] = 0x00;
                    LOGD(L_APP, L_V1, "sendData[%d]", i);
                }
            }
            else//gd->gpgga.sat==0
            {
                LOGD(L_APP, L_V1, "可见不参与定位星数%d", (gd->gpgsv.Satellites_In_View - gd->gpgga.sat));
                sendData[i++] = (gd->gpgsv.Satellites_In_View - gd->gpgga.sat);
                temp1 = i;
                LOGD(L_APP, L_V1, "可见不参与定位星数sendData[%d]", i);
                for(m = 0, n = 0; m < MTK_GPS_SV_MAX_NUM; m++)
                {
                    if(gd->gpgsv.SNR[m] != 0)
                    {
                        n += 1;
                        sendData[i++] = gd->gpgsv.SNR[m];
                        LOGD(L_APP, L_V1, "sendData[%d]", i);
                    }
                    if(n == (gd->gpgsv.Satellites_In_View - gd->gpgga.sat))
                    {
                        break;
                    }
                }
                temp2 = i - temp1;
                for(m = temp2; m < (gd->gpgsv.Satellites_In_View - gd->gpgga.sat); m++)
                {
                    sendData[i++] = 0x00;
                    LOGD(L_APP, L_V1, "sendData[%d]", i);
                }

            }
        }
    }
    else
    {
        sendData[i++] = 0x00; //没有GPS模块
        LOGD(L_APP, L_V1, "没有GPS模块=sendData[i]", i);
    }
#endif

#if 1
// BD
    LOGD(L_APP, L_V1, "gw_mode=%d", gd->gw_mode);
    if(gd->gw_mode == BD || gd->gw_mode == GN) //有GPS模块
    {
        LOGD(L_APP, L_V1, "gps_status=%d", gd->status);
        if(gd->status == 0)
            sendData[i++] = 0x04;
        else if(gd->status == 3)
            sendData[i++] = 0x03;
        else if(gd->status == 2)
            sendData[i++] = 0x02;
        else if(gd->status == 1)
            sendData[i++] = 0x01;
        LOGD(L_APP, L_V1, "sendData[%d]", i);
        //  bd定位星数
        if(gd->bdgsv.Satellites_In_View != 0) //搜不到任何星
        {
            LOGD(L_APP, L_V1, "bdgga.sat=%d,Satellites_In_View=%d", gd->bdgga.sat, gd->bdgsv.Satellites_In_View);
            sendData[i++] = gd->gpgga.sat;
            LOGD(L_APP, L_V1, "sendData[%d]bdgga.sat", i);
            if(gd->status == 2 || gd->status == 3)
            {
                for(m = 0; m < gd->bdgga.sat && m < MTK_GPS_SV_MAX_NUM; m++)
                {
                    for(x = 0; x < MTK_GPS_SV_MAX_NUM; x++)
                    {
                        if(gd->bdgsa.satellite_used[m] == gd->bdgsv.Satellite_ID[x])
                        {
                            sendData[i++] = gd->bdgsv.SNR[x];
                            //data[m] = x;
                            // memcpy(&data[m],&x,sizeof(x));
                            LOGD(L_APP, L_V1, "sendData[%d]", i);
                            break;
                        }
                    }
                }

                //bd可见不参与定位星数
                LOGD(L_APP, L_V1, "可见不参与定位星数%d", (gd->bdgsv.Satellites_In_View - gd->bdgga.sat));
                sendData[i++] = (gd->bdgsv.Satellites_In_View - gd->bdgga.sat);
                temp1 = i;
                LOGD(L_APP, L_V1, "可见不参与定位星数sendData[%d]", i);
                for(x = 0, n = 0; x < MTK_GPS_SV_MAX_NUM; x++, flag = 0)
                {
                    if(gd->bdgsv.SNR[x] != 0)
                    {
                        for(m = 0; m < gd->bdgga.sat; m++)
                        {
                            if(gd->bdgsv.Satellite_ID[x] == gd->bdgsa.satellite_used[m])
                            {
                                flag = 1;
                                break;
                            }
                        }
                        if(flag == 0)
                        {
                            n += 1;
                            sendData[i++] = gd->bdgsv.SNR[x];
                            LOGD(L_APP, L_V1, "sendData[%d]", i);
                        }
                    }
                    if(n == (gd->bdgsv.Satellites_In_View - gd->bdgga.sat))
                    {
                        break;
                    }
                }
                temp2 = i - temp1;
                for(m = temp2; m < (gd->bdgsv.Satellites_In_View - gd->bdgga.sat); m++)
                {
                    sendData[i++] = 0x00;
                    LOGD(L_APP, L_V1, "sendData[%d]", i);
                }
            }
            else//gd->gpgga.sat==0
            {
                LOGD(L_APP, L_V1, "可见不参与定位星数%d", (gd->bdgsv.Satellites_In_View - gd->bdgga.sat));
                sendData[i++] = (gd->bdgsv.Satellites_In_View - gd->bdgga.sat);
                temp1 = i;
                LOGD(L_APP, L_V1, "可见不参与定位星数sendData[%d]", i);
                for(m = 0, n = 0; m < MTK_GPS_SV_MAX_NUM; m++)
                {
                    if(gd->bdgsv.SNR[m] != 0)
                    {
                        n += 1;
                        sendData[i++] = gd->bdgsv.SNR[m];
                        LOGD(L_APP, L_V1, "sendData[%d]", i);
                    }
                    if(n == (gd->bdgsv.Satellites_In_View - gd->bdgga.sat))
                    {
                        break;
                    }
                }
                temp2 = i - temp1;
                for(m = temp2; m < (gd->bdgsv.Satellites_In_View - gd->bdgga.sat); m++)
                {
                    sendData[i++] = 0x00;
                    LOGD(L_APP, L_V1, "sendData[%d]", i);
                }
            }
        }
    }
    else
    {
        sendData[i++] = 0x00; //没有bd模块
        LOGD(L_APP, L_V1, "没有bd模块=sendData[i]", i);
    }
#endif

//扩展
    sendData[i++] = 0x00;
    if(sendData[i-1] == 0)
    {
        size = size - 1;
    }
    LOGD(L_APP, L_V1, "size=%d", size);
    track_cust_paket_94(9, sendData, size);
    Ram_Free(sendData);
}
#if 1
void track_cust_decode_packet_16(kal_uint8 *data, kal_uint16 len){;}
void track_cust_decode_packet_17(kal_uint8 *data, kal_uint16 len){;}
#else
/******************************************************************************
 *  Function    -  track_cust_decode_packet_16
 *
 *  Purpose     -  响应服务器下发的0x16数据包处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * v1.1  , 28-09-2013,  WQ  modify
 * ----------------------------------------
*******************************************************************************/
void track_cust_decode_packet_16(kal_uint8 *data, kal_uint16 len)
{
    LOGD(L_APP, L_V4, "服务器响应终端上报的报警数据包（不含地址）");

#if defined(__GT300S__) || defined(__GT370__)|| defined (__GT380__)
    track_cust_decode_packet_17(data, len);
    track_soc_send((void*)98);
#endif
}

/******************************************************************************
 *  Function    -  track_cust_decode_packet_17
 *
 *  Purpose     -  响应服务器下发的0x17数据包处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * v1.1 , 28-08-2013,   J W  written
 * ----------------------------------------
*******************************************************************************/

void track_cust_decode_packet_17(kal_uint8 *data, kal_uint16 len)
{
    kal_uint8 packelen = 0, serverId[4] = {0}, *p, *s;
    kal_uint16 sn = 0, l;
    char *wchr = "&&";               // 分隔符 &&
    char *addr = "ADDRESS", *alarm = "ALARMSMS";
    char tmp[50] = {0}, *number = NULL;
    kal_uint8 check_num[20] = {0x00};

    memset((void *)check_num, 0x00, sizeof((char *)check_num));

    LOGH(L_APP, L_V6, data, len);
    LOGH(L_APP, L_V6, check_num, 20);
    // 指令长度
    packelen = data[1];

    // 服务器标志位
    memcpy(serverId, &data[2], 4);

    // 流水号
    sn = (data[len - 2] << 8) & 0xFF00;
    sn |= data[len - 1];
    LOGD(L_APP, L_V2, "sn=%d", sn);

    s = (kal_uint8*)strstr((char*)&data[6], wchr);
    if(s == NULL)
    {
        LOGD(L_APP, L_V2, "error 1");
        return;
    }
    if(s - &data[6] >= 50)
    {
        LOGD(L_APP, L_V2, "error 2");
        return;
    }
    memcpy(tmp, &data[6], s - &data[6]);
    s += 2;
    if(!strcmp(tmp, addr) || !strcmp(tmp, alarm))
    {
        p = track_fun_strWchr((U8*)wchr, s, len - (s - data));
        if(p == NULL)
        {
            LOGD(L_APP, L_V2, "error 3");
            return;
        }
        l = p - s;
        number = p + 2;
        LOGH(L_APP, L_V6, number, 28);
        if(strstr(number, "000000000000000000000"))
        {
            number[0] = 0;
        }

        LOGD(L_APP, L_V5, "Number:%s, %0.4X", number, sn);

        if(!strcmp(tmp, addr))
        {
            if(strlen(number) == 0)/*W J*/
            {
                track_cust_module_alarm_recv_addr(number, s, l, sn);
            }
            else
            {
                track_cust_module_recv_addr(number, s, l, sn);
            }
        }
        else if(!strcmp(tmp, alarm))
        {
            track_cust_module_alarm_recv_addr(number, s, l, sn);
        }
    }
    else
    {
        LOGH(L_APP, L_V6, &data[6], len - 6);
    }
}
#endif
void track_cust_decode_packet_21(kal_uint8 *data, kal_uint16 len)
{
    kal_uint8 serverId[4] = {0};
    kal_bool isAscii;
    U8 *sendData;

    memcpy(serverId, &data[1], 4);
    if(data[5] == 1)
    {
        isAscii = KAL_TRUE;
    }
    else
    {
        isAscii = KAL_FALSE;
    }
    sendData = (U8*)Ram_Alloc(5, len);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "Ram_Alloc NULL!!");
        return;
    }
    memcpy(sendData, &data[6], len - 6);
    track_cust_online_cmd(serverId, (char *)sendData);
    Ram_Free(sendData);
}

/******************************************************************************
 *  Function    -  track_cust_decode_packet_97
 *
 *  Purpose     -  响应服务器下发的0x17数据包处理
 *
 *  Description -
 * 78 78 00 B7 97 00 B0 00 00 00 01 41 44 44 52 45 53 53 26 26 00 50 00 72 00 65 00 63 00 69 00 73 00 65 00 6C 00 79 00 20 00 4C 00 6F 00 63 00 61 00 74 00 69 00 6E 00 67 00 3A 00 68 00 74 00 74 00 70 00 3A 00 2F 00 2F 00 6D 00 61 00 70 00 73 00 2E 00 67 00 6F 00 6F 00 67 00 6C 00 65 00 2E 00 63 00 6F 00 6D 00 2F 00 6D 00 61 00 70 00 73 00 3F 00 71 00 3D 00 32 00 33 00 2E 00 31 00 31 00 31 00 38 00 31 00 35 00 2C 00 31 00 31 00 34 00 2E 00 34 00 30 00 39 00 32 00 39 00 37 26 26 31 32 35 32 30 31 35 38 31 32 35 35 35 37 32 39 00 00 00 00 00 23 23 03 47 B3 28 0D 0A
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * v1.1 , 28-08-2013,  J W  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_decode_packet_97(kal_uint8 *data, kal_uint16 len)
{
    kal_uint16 packelen = 0;
    kal_uint8    serverId[4] = {0}, *p, *s;
    char        *wchr = "&&";               // 分隔符 &&
    kal_uint16 sn = 0, l;
    char *addr = {"ADDRESS"}, *alarm = {"ALARMSMS"};
    char tmp[50] = {0}, *number = NULL;
    kal_uint8 check_num[20] = {0x00};
    LOGD(L_APP, L_V4, "服务器响应终端位置查询数据包");

    memset((void *)check_num, 0x00, sizeof((char *)check_num));

    LOGH(L_APP, L_V6, data, len);
    LOGH(L_APP, L_V6, check_num, 20);
    // 指令长度
    packelen = data[1];
    packelen = (packelen << 8) + data[2];
    // 服务器标志位
    memcpy(serverId, &data[3], 4);

    // 流水号
    sn = (data[len - 2] << 8) & 0xFF00;
    sn |= data[len - 1];
    LOGD(L_APP, L_V2, "sn=%d", sn);

    s = (kal_uint8*)strstr((char*)&data[7], (char*)wchr);
    if(s == NULL)
    {
        LOGD(L_APP, L_V2, "error 1");
        return;
    }
    if(s - &data[7] >= 50)
    {
        LOGD(L_APP, L_V2, "error 2");
        return;
    }
    memcpy(tmp, &data[7], s - &data[7]);
    s += 2;
    if(!strcmp(tmp, addr) || !strcmp(tmp, alarm))
    {
        p = track_fun_strWchr(wchr, s, len - (s - data));
        if(p == NULL)
        {
            LOGD(L_APP, L_V2, "error 3");
            return;
        }
        l = p - s;
        number = p + 2;
        LOGH(L_APP, L_V6, number, 28);
        if(strstr(number, "000000000000000000000"))
        {
            number[0] = 0;
        }

        LOGD(L_APP, L_V5, "Number:%s, %0.4X", number, sn);

        if(!strcmp(tmp, addr))
        {
            if(strlen(number) == 0)/*W J*/
            {
                track_cust_module_alarm_recv_addr(number, s, l, sn);
            }
            else
            {
                track_cust_module_recv_addr(number, s, l, sn);
            }
        }
        else if(!strcmp(tmp, alarm))
        {
            track_cust_module_alarm_recv_addr(number, s, l, sn);
        }
    }
    else
    {
        LOGH(L_APP, L_V6, &data[6], len - 6);
    }
    track_soc_send((void*)98);

}

/******************************************************************************
 *  Function    -  track_cust_decode_packet_80
 *
 *  Purpose     -  响应服务器下发的0x80数据包（在线指令）处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_decode_packet_80(kal_uint8 *data, kal_uint16 len)
{
    kal_uint8 packelen = 0, serverId[4] = {0};
    char *p = NULL;
    char tmp[256] = {0}, *number = NULL;
    int cmdlen;

    LOGH(L_APP, L_V6, data, len);
    // 指令长度
    packelen = data[1];

    // 服务器标志位
    memcpy(serverId, &data[2], 4);

    p = strchr((char*)&data[6], '#');
    if(p == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Not to '#' end, instruction format wrong!");
        LOGH(L_APP, L_V1, data, len);
        return;
    }
    cmdlen = p - &data[6];
#if !defined(__SAME_GT02__)//GT02没有序列号和校验位
    if(cmdlen > len - 8 || cmdlen > 255)
    {
        LOGD(L_APP, L_V1, "ERROR: cmdlen=%d", cmdlen);
        LOGH(L_APP, L_V1, data, len);
        return;
    }
#endif

    memcpy(tmp, &data[6], cmdlen);
    LOGD(L_APP, L_V4, "收到在线指令：%s", tmp);
    track_cmd_net_recv(tmp, serverId);
}

void track_cust_decode_packet_8A(kal_uint8 *data, kal_uint16 len)
{
    static mtk_param_epo_time_cfg epo_time = {0};
    kal_uint8 req_result, i;

    LOGH(L_APP, L_V5, data, len);
    i = 1;
    epo_time.u2YEAR  = 2000 + data[i++];
    epo_time.u1MONTH = data[i++];
    epo_time.u1DAY   = data[i++];
    epo_time.u1HOUR  = data[i++];
    epo_time.u1MIN   = data[i++];
    epo_time.u1SEC   = data[i++];
    LOGD(L_APP, L_V4, "%d-%02d-%02d %02d:%02d:%02d", epo_time.u2YEAR, epo_time.u1MONTH, epo_time.u1DAY, epo_time.u1HOUR, epo_time.u1MIN, epo_time.u1SEC);
    track_fun_update_time_to_system(2, (applib_time_struct *)(&epo_time));
    track_soc_send((void*)98);
}

void track_cust_decode_packet_FD_cmd(kal_uint8 *data, kal_uint16 len)
{
    kal_uint8 serverId[4] = {0};
    kal_bool isAscii;
    U8 *sendData;

    LOGH(L_APP, L_V6, data, len);
    memcpy(serverId, &data[1], 4);
    if(data[5] == 1)
        isAscii = KAL_TRUE;
    else
        isAscii = KAL_FALSE;
    sendData = (U8*)Ram_Alloc(5, len);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "Ram_Alloc NULL!!");
        return;
    }
    memcpy(sendData, &data[6], len - 6);
    LOGD(L_APP, L_V4, "收到在线指令：%s", sendData);
    len = strlen(sendData);
    {
        char *start = NULL, *end = NULL;
        kal_bool valid = KAL_FALSE;
        U16 cmd_length = 0;

        track_drv_nvram_write_switch(0);
        start = (char*)sendData;
        do
        {
            end = strchr(start, '#');
            if(end != NULL || strlen(start) > 1)
            {
                if(end != NULL) *end = 0;

                start = track_fun_trim2(start);
                cmd_length = strlen(start);
                if(*start != '#' && cmd_length < CM_PARAM_LONG_LEN_MAX - 2 && cmd_length > 0)
                {
                    CMD_DATA_STRUCT cmd = {0};
                    cmd.return_sms.cm_type = CM_ONLINE2;
                    cmd.rcv_length = cmd_length;
                    memcpy(cmd.return_sms.stamp, serverId, 4);
                    strcpy(cmd.rcv_msg, start);
                    track_command_operate(&cmd);
                    valid = KAL_TRUE;
                }
                start = end + 1;
            }
        }
        while(end != NULL);
        track_drv_nvram_write_switch(1);
        track_cust_server2_write_req(0, NULL, 0, 0);
        if(valid)
        {
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
            Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
            Track_nvram_write(NVRAM_EF_PHONE_NUMBER_LID, 1, (void *)&G_phone_number, NVRAM_EF_PHONE_NUMBER_SIZE);
        }
    }
    Ram_Free(sendData);
}

void track_cust_decode_lbs_packet(kal_uint8 *data, kal_uint16 len)
{
    mtk_param_epo_pos_cfg epo_pos_cfg_from_lbs = {0};
    kal_uint8 *sendData;
    kal_uint8 nw = 0;
    kal_uint16 no;
    int size, i = 1, tmp1, tmp2;
    float lan_temp = 0.0, lon_temp = 0.0;
    track_gps_data_struct gps_data = {0};
    applib_time_struct date = {0};
    track_gps_data_struct *gpsLastPoint = NULL;
    LBS_Multi_Cell_Data_Struct *lbs = track_drv_get_lbs_data();
    static U8 flg = 0;
    gpsLastPoint = track_cust_backup_gps_data(2, NULL);
    if(track_cust_is_upload_UTC_time())
    {
        track_fun_get_time(&date , KAL_TRUE, NULL);
    }
    else
    {
        track_fun_get_time(&date , KAL_FALSE, &G_parameter.zone.zone);
    }
    epo_pos_cfg_from_lbs.u2YEAR = date.nYear;
    epo_pos_cfg_from_lbs.u1MONTH = date.nMonth;
    epo_pos_cfg_from_lbs.u1DAY = date.nDay;
    epo_pos_cfg_from_lbs.u1HOUR = date.nHour;
    epo_pos_cfg_from_lbs.u1MIN = date.nMin  ;
    epo_pos_cfg_from_lbs.u1SEC = date.nSec  ;


    i = 0;
    memcpy(&tmp1, &data[i], 4);
    track_fun_reverse_32((kal_uint8 *)&tmp2, tmp1);
    epo_pos_cfg_from_lbs.dfLAT = tmp2;
    epo_pos_cfg_from_lbs.dfLAT /= 1800000;
    if((nw & 0x02)) //00000010 最低位为经度0-东 1-西 ，第二位是纬度  0南  1北
    {
        epo_pos_cfg_from_lbs.dfLAT = -epo_pos_cfg_from_lbs.dfLAT;
    }
    i += 4;
    memcpy(&tmp1, &data[i], 4);
    track_fun_reverse_32((kal_uint8 *)&tmp2, tmp1);
    epo_pos_cfg_from_lbs.dfLON = tmp2;
    epo_pos_cfg_from_lbs.dfLON /= 1800000;
    if(nw & 0x01) //00000010 最低位为经度0-东 1-西 ，第二位是纬度  0南  1北
    {
        epo_pos_cfg_from_lbs.dfLON = -epo_pos_cfg_from_lbs.dfLON;
    }
    ///jiangweijun
    memcpy(&gps_data.gprmc.Date_Time, &date, sizeof(date));
    if(!(nw & 0x02))
    {
        gps_data.gprmc.Latitude = epo_pos_cfg_from_lbs.dfLAT;
        gps_data.gprmc.NS = 'N';
    }
    else
    {
        gps_data.gprmc.Latitude = -epo_pos_cfg_from_lbs.dfLAT;
        gps_data.gprmc.NS = 'S';
    }
    if(!(nw & 0x01))
    {
        gps_data.gprmc.Longitude = epo_pos_cfg_from_lbs.dfLON;
        gps_data.gprmc.EW = 'E';

    }
    else
    {
        gps_data.gprmc.Longitude = -epo_pos_cfg_from_lbs.dfLON;
        gps_data.gprmc.EW = 'W';

    }
    gps_data.gprmc.status = 1;

    track_cust_decode_lbs(&gps_data.gprmc.Latitude, &gps_data.gprmc.Longitude);

    //jiangweijun

    LOGD(L_APP, L_V5, "nw:%d, lat:%c%f, lon:%c%f", nw, gps_data.gprmc.NS, epo_pos_cfg_from_lbs.dfLAT, gps_data.gprmc.EW, epo_pos_cfg_from_lbs.dfLON);
    if(epo_pos_cfg_from_lbs.u2YEAR > 2013)
    {
        if(track_cust_gps_status() < 3 && flg == 0)
        {
            flg = 1;
            if(lbs->MainCell_Info.lac != gpsLastPoint->lbs.lac)
            {
                /*if(mmi_Get_PowerOn_Type() == PWRKEYPWRON || CHRPWRON == mmi_Get_PowerOn_Type())
                {
                    track_cust_paket_position(&gps_data, track_drv_get_lbs_data(), TR_CUST_POSITION_LBS, 0);
                }*/
                track_cust_agps_get_last_position(2, &epo_pos_cfg_from_lbs);
            }
        }
    }
}

void track_cust_decode_packet_FD(kal_uint8 *data, kal_uint16 len)
{
    //LOGH(L_APP, L_V6, data, len);
    LOGD(L_APP, L_V5, "len:%d", len);
    if(len > 11)
    {
        track_cust_server2_decode_packet(data + 11, len - 11);
    }
}



/******************************************************************************
 *  Function    -  track_cust_check_gprsdata
 *
 *  Purpose     -  用于检测GPS报警的流水号
 *
 *  Description -  主要用于GT300 模式3
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 14-01-2014,  ZengPing && Liujw  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint16 track_cust_check_gprsdata(kal_uint32 flag, kal_uint16 sn)
{
    static kal_uint16  gps_sn =  0xffff;
    LOGD(L_APP, L_V5, "flag:%d;sn:%d", flag, sn);
    if(flag == 0)
    {
        track_stop_timer(TRACK_CUST_ALARM_GPS_WORK_TIMER);
        gps_sn = 0xffff;
        track_cust_gps_location_timeout(5);
    }
    else if(flag == 1)
    {
        gps_sn = sn;
        LOGD(L_APP, L_V5, "@1gps_sn:%d;sn=%d", gps_sn, sn);
    }
    else
    {
        LOGD(L_APP, L_V5, "@2gps_sn:%d", gps_sn);
        return gps_sn;
    }
}

/*************************************************/
/************GT02B旧协议包开始**************/
/*************************************************/

/******************************************************************************
 *  Function    -  track_cust_paket_gpsdata
 *
 *  Purpose     -  GPS定位包
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-11-2013,  ZengPing && Liujw  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint16 track_cust_paket_gpsdata(track_gps_data_struct *gd, LBS_Multi_Cell_Data_Struct *lbs)
{

    U8 *sendData;
    U16 no;
    int size;
    U16 temp4 = 0;
    kal_uint16 Course;

    size = 42;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "Ram_Alloc NULL!!");
        return;
    }
    memset(sendData, 0, size);
    //Head
    sendData[0] = 0x68;
    sendData[1] = 0x68;

    //长度
    sendData[2] = 24 + 13;
    //HOLD
    sendData[3] = (lbs->MainCell_Info.lac >> 8) & 0x00FF;
    sendData[4] = lbs->MainCell_Info.lac & 0x00FF;


    //终端ID
    memcpy(&sendData[5], track_drv_get_imei(1), 8);

    //信息序列号
    no = getSerialNumber();
    sendData[13] = (no & 0xFF00) >> 8;
    sendData[14] = (no & 0x00FF);

    //协议号
    sendData[15] = 0x10;

    //定位信息
    //定位内容
    //日期时间
    DataPackingDatetime_6(&sendData[16], gd);

    //纬度
    track_fun_LongitudeLatitudeToHex(&sendData[22], gd->gprmc.Latitude);

    //经度
    track_fun_LongitudeLatitudeToHex(&sendData[26], gd->gprmc.Longitude);
    LOGD(L_APP, L_V5, "len:%f,%f",  gd->gprmc.Longitude, gd->gprmc.Latitude);

    //速度
    sendData[30] = gd->gprmc.Speed;

    //航向状态
    Course = gd->gprmc.Course;
    track_fun_reverse_16(&sendData[31], Course);

    //保留位
    sendData[33] = 0;
    sendData[34] = 0;
    sendData[35] = 0;

    //状态位
    sendData[36] = 0;
    sendData[37] = 0;
    sendData[38] = 0;
    if(gd->gprmc.EW == 'E')
        sendData[39] |= 0x04;
    if(gd->gprmc.NS == 'N')
        sendData[39] |= 0x02;
    if(gd->gprmc.status == 1)
        sendData[39] |= 0x01;

    //结束
    sendData[40] = 0x0d;
    sendData[41] = 0x0a;

    //track_socket_queue_position_send_reg(sendData, size, 0x10, no);
    Ram_Free(sendData);

    return no;
}

#if !defined(__NF2318__)
void Heartbeat_Data_Packet(kal_uint8* data, kal_uint16 *len, kal_uint16 *sn)
{
    U8 i, k;
    U32 Temp;
    U8 *sendData;
    U16 no;
    int size, ret;

    gps_gpgsv_struct *gpgsv_data = track_drv_get_gps_GSV();
    size = 20 + gpgsv_data->Satellites_In_View;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "Ram_Alloc NULL!!");
        return;
    }
    memset(sendData, 0, size);
    //包头
    sendData[0] = 0x68;
    sendData[1] = 0x68;
    //内容长度
    sendData[2] = 15 + gpgsv_data->Satellites_In_View;
    //电压等级
    sendData[3] = track_cust_get_battery_level();
    //GSM信号等级
    ret = track_cust_get_rssi_level();
    if(ret >= 1 && ret <= 4)
    {
        sendData[4] = ret;
    }
    else
    {
        sendData[4] = 0;
    }
    //终端ID
    memcpy(&sendData[5], track_drv_get_imei(1), 8);

    //信息序列号
    no = getSerialNumber();
    sendData[13] = (no & 0xFF00) >> 8;
    sendData[14] = (no & 0x00FF);

    //协议号
    sendData[15] = 0x1A;

    //定位状态
    if(track_cust_gps_status() == GPS_STAUS_OFF)
    {
        sendData[16] = 0;
    }
    else  if(track_cust_gps_status() >= GPS_STAUS_2D)
    {
        sendData[16] = 1;
    }
    else if(track_cust_gps_status() == GPS_STAUS_ON)
    {
        sendData[16] = 3;
    }
    else  if(track_cust_gps_status() == GPS_STAUS_SCAN)
    {
        sendData[16] = 4;
    }
    sendData[17] = gpgsv_data->Satellites_In_View;
    if(gpgsv_data->Satellites_In_View)
    {
        k = 18;
        for(i = 0; i < gpgsv_data->Satellites_In_View; i++)
        {
            sendData[k] = gpgsv_data->SNR[i];
            k++;
        }
    }
    else
    {
        k = 18;
    }
    sendData[k] = 0x0D;
    k++;
    sendData[k] = 0x0A;



    if(!track_soc_login_status())
    {
        LOGD(L_APP, L_V5, "@1");
        track_soc_write_req(sendData, size, 1, no);
    }
    else
    {
        memcpy(data, sendData, size);
        *len = size;
        *sn = no;
    }
    Ram_Free(sendData);

}
#endif
static kal_uint16 DataPacketEncode68(U8 cmd, U8 *sendData, U8 len)
{
    U16 tmp, tmp1;

    //起始位
    sendData[0] = 0x68;
    sendData[1] = 0x68;

    //长度
    sendData[2] = len - 5;

    //协议号
    sendData[3] = cmd;

    //信息序列号
    tmp = getSerialNumber();
    sendData[len - 6] = (tmp & 0xFF00) >> 8;
    sendData[len - 5] = (tmp & 0x00FF);
    LOGD(L_APP, L_V5, "SerialNumber:%.2X%.2X", sendData[len - 6], sendData[len - 5]);

    //CRC校验
    tmp1 = GetCrc16(&sendData[2], len - 6);
    sendData[len - 4] = (tmp1 & 0xFF00) >> 8;
    sendData[len - 3] = (tmp1 & 0x00FF);

    //结束
    sendData[len - 2] = '\r';
    sendData[len - 1] = '\n';

    return tmp;
}

void track_Online_Command_Set_Handle(kal_uint8 * Recbuf, kal_uint16 RecLen)
{
    LOGD(L_APP, L_V5, "");
    track_cust_decode_packet_80(Recbuf, RecLen);
}
void track_cust_paket_1C(kal_uint8 *serverid, kal_bool isASCII, kal_uint8 *outstr, kal_uint8 outstrlen)
{
#if 1//__NF2318__
	;
#else
    U8 *sendData, tmp, i = 4;
    U16 no;
    int size;

    outstrlen = strlen(outstr);
    if(outstrlen <= 0 || outstrlen > 200)
    {
        LOGD(L_APP, L_V1, "ERROR: outstrlen=%d", outstrlen);
        return;
    }
    size = 10 + 1/*command len*/ + 4/*server id*/ + outstrlen + 1/*code page*/; /*content*/// + 2/*language*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    //指令长度
    sendData[i++] = outstrlen + 4;

    //服务器标志位
    memcpy(&sendData[i], serverid, 4);
    i += 4;
    //code_page
    if(isASCII)
    {
        sendData[i++] = 1;
    }
    else
    {
        sendData[i++] = 2;
    }
    //指令内容
    memcpy(&sendData[i], outstr, outstrlen);
    i += outstrlen;

    no = DataPacketEncode68(0x1C, sendData, size);

    track_socket_queue_send_netcmd_reg(sendData, size, 0x1C, no);
    Ram_Free(sendData);
#endif
}

void Server_GPRS_Command(kal_uint8 *serverid, kal_bool isASCII, kal_uint8 *outstr, kal_uint8 outstrlen)
{
#if 1//__NF2318__
	;
#else
    U8 *sendData, tmp, i = 3;
    U16 no;
    int size;

    outstrlen = strlen(outstr);
    if(outstrlen <= 0 || outstrlen > 200)
    {
        LOGD(L_APP, L_V1, "ERROR: outstrlen=%d", outstrlen);
        return;
    }
    size = 2 + 1 + 2 /*保留位*/ + 8/*IMEI*/ + 2/*信息序列号*/ + 1/*协议号*/ + 1/*command len*/ + 4/*server id*/ + outstrlen + 2; /*content*/ // + 2/*language*/;
    LOGD(L_APP, L_V1, ": size=%d,%d", size, outstrlen);
    LOGD(L_APP, L_V1, ": outstr=%s,%d", outstr, outstrlen);
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);
    //起始位
    sendData[0] = 0x68;
    sendData[1] = 0x68;

    //包长度
    sendData[2] = outstrlen + 2 + 8 + 2 + 1 + 4 + 1;

    //保留位
    sendData[i++] = 0;
    sendData[i++] = 0;

    //终端ID
    // imei
    memcpy(&sendData[i], track_drv_get_imei(1), 8);

    i += 8;

    //信息序列号
    tmp = getSerialNumber();
    sendData[i++] = (tmp & 0xFF00) >> 8;
    sendData[i++] = (tmp & 0x00FF);
    LOGD(L_APP, L_V5, "SerialNumber:%.2X%.2X", sendData[i - 1], sendData[i - 2]);
    //协议号
    sendData[i++] = 0x1C;

    //指令长度
    sendData[i++] = outstrlen + 4;

    //服务器标志位
    memcpy(&sendData[i], serverid, 4);
    i += 4;

    //指令内容
    memcpy(&sendData[i], outstr, outstrlen);

    i += outstrlen;

    //结束
    sendData[i++] = 0x0D;
    sendData[i] = 0x0A;
    track_socket_queue_send_netcmd_reg(sendData, size, 0x1C, tmp);
    Ram_Free(sendData);
#endif
}

/****************************************
* Function    track_cust_lock_serial_no

* Parameter

* Purpose     记录定位包的序列号

* Modification
******************************************/
U16 track_cust_lock_serial_no(int no)
{
    static U16 serial_no = 0;
    LOGD(L_UART, L_V3, "serial_no %d, no %d", serial_no, no);

    if(no == -1)
    {
        return serial_no;
    }
    else
    {
        serial_no = no;
    }

}
#if 1
kal_uint16 track_cust_paket_1B(track_gps_data_struct *gd, char *number)
{return 0;}
#else
kal_uint16 track_cust_paket_1B(track_gps_data_struct *gd, char *number)
{
    kal_uint8 *sendData;
    kal_uint16 no;
    int size , i = 0;
    kal_uint32 tmp;
    LBS_Multi_Cell_Data_Struct* lbs = NULL;
    kal_uint16 Course;

    LOGD(L_APP, L_V5, "number:%s", number);
    size = 2 + 1 + 2/*LAC*/ + 8/*终端ID*/ + 2/*信息序列号*/ + 1/*协议号*/ + 24/*datatime*//*gps*/ + 21/*number*/ + 1/*language*/ + 2;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return 0;
    }
    memset(sendData, 0, size);
    //起始位
    sendData[i++] = 0x68;
    sendData[i++] = 0x68;

    //包长度
    sendData[i++] = size - 5;

    //保留位0x0000//保留位放小区码
    lbs = track_drv_get_lbs_data();
    sendData[i++] = (lbs->MainCell_Info.lac >> 8) & 0x00FF;
    sendData[i++] = lbs->MainCell_Info.lac & 0x00FF;

    //终端ID
    // imei
    memcpy(&sendData[i], track_drv_get_imei(1), 8);
    i += 8;

    //信息序列号
    tmp = getSerialNumber();
    sendData[i++] = (tmp & 0xFF00) >> 8;
    sendData[i++] = (tmp & 0x00FF);
    LOGD(L_APP, L_V5, "SerialNumber:%.2X%.2X", sendData[i - 1], sendData[i - 2]);

    //协议号
    sendData[i++] = 0x1B;

    //定位信息
    if(gd->status >= 2)
    {

        //定位内容
        //日期时间
        DataPackingDatetime_6(&sendData[i], gd);
        i += 6;
        //纬度
        track_fun_LongitudeLatitudeToHex(&sendData[i], gd->gprmc.Latitude);
        i += 4;
        //经度
        track_fun_LongitudeLatitudeToHex(&sendData[i], gd->gprmc.Longitude);
        i += 4;
        //速度
        sendData[i++] = gd->gprmc.Speed;

        //航向状态
        Course = gd->gprmc.Course;
        track_fun_reverse_16(&sendData[i], Course);
    }
    i += 2;
    sendData[i++] = lbs->MainCell_Info.mnc;
    sendData[i++] = (lbs->MainCell_Info.cell_id >> 8) & 0x00FF;//基站码前1字节
    sendData[i++] = lbs->MainCell_Info.cell_id & 0x00FF;//基站码后1字节;

    //状态位
    sendData[i++] = 0;
    sendData[i++] = 0;
    sendData[i++] = 0;
    if(gd->gprmc.EW == 'E')
        sendData[i] |= 0x04;
    if(gd->gprmc.NS == 'N')
        sendData[i] |= 0x02;
    if(gd->gprmc.status == 1)
        sendData[i] |= 0x01;
    i += 1;
    // number(Max:21)
    snprintf(&sendData[i], 21, number);
    i += 21;
    // language  0x01: 中文；0x02: 英文
    //sendData[i++] = 0x00;
    if(G_parameter.lang == 1)
    {
        sendData[i] = 1;
    }
    else
    {
        sendData[i] = 2;
    }
    i += 1;
    sendData[i++] = 0x0D;
    sendData[i] = 0x0A;

    track_socket_queue_alarm_send_reg(sendData, size, 0x1B, tmp);
    Ram_Free(sendData);
    return no;
}
#endif
/******************************************************************************
 *  Function    -  public_packet_handle
 *
 *  Purpose     -  向谷米请求的数据公共部分
 *
 *  Description -  NULL
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 06-12-2010,  Cml  written
 * ----------------------------------------
 ******************************************************************************/
static void public_packet_handle(kal_uint8* plbsfulldata, U8 len, kal_uint8 type)
{
    static kal_uint16 serial = 0;
    kal_uint16 crc;
    U8 i = 0;
    //--起始位--
    plbsfulldata[i++] = 0x78;
    plbsfulldata[i++] = 0x78;

    //--长度--
    plbsfulldata[i++] = len - 5;

    //--协议号--
    plbsfulldata[i++] = type;

    i = len - 6;
    // --预留扩展位--

    //--信息序列号--
    plbsfulldata[i++] = (serial >> 8) & 0x00FF;
    plbsfulldata[i++] = serial & 0x00FF;
    serial++;

    //--CRC校验--
    crc = GetCrc16((U8 *)&plbsfulldata[2], len - 6);
    plbsfulldata[i++] = (crc >> 8) & 0x00FF;
    plbsfulldata[i++] = crc & 0x00FF;

    //--结束--
    plbsfulldata[i++] = 0x0D;
    plbsfulldata[i++] = 0x0A;
}
/******************************************************************************
 *  Function    -  LBS_Full_Packet
 *
 *  Purpose     -  填充LBS信息进数据包
 *
 *  Description -  NULL
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 06-12-2010,  Cml  written
 * ----------------------------------------
 ******************************************************************************/
void LBS_Full_Packet(LBS_Multi_Cell_Data_Struct *pdata, kal_uint8* plbsfulldata, U8 len)
{
    kal_uint8 i, j = 0;
    U8 imeiHex[8] = {0};

    // --IMEI NO--
    i = 4;
    //if(!GPS_string2Hex(IMEI_DATA, &plbsfulldata[i], 16))
    //   ASSERT(0);
    memcpy(&plbsfulldata[i], track_drv_get_imei(1), 8);

    // --产品编号--
    i = 12;
    plbsfulldata[i++] = 0x30;
    plbsfulldata[i++] = 0x01;

    // --LBS信息--
    // MCC
    plbsfulldata[i++] = (pdata->MainCell_Info.mcc >> 8) & 0x00FF;
    plbsfulldata[i++] = pdata->MainCell_Info.mcc & 0x00FF;
    // MNC
    plbsfulldata[i++] = pdata->MainCell_Info.mnc;
    // LAC
    plbsfulldata[i++] = (pdata->MainCell_Info.lac >> 8) & 0x00FF;
    plbsfulldata[i++] = pdata->MainCell_Info.lac & 0x00FF;
    // Cell Id
    i++;
    plbsfulldata[i++] = (pdata->MainCell_Info.cell_id >> 8) & 0x00FF;
    plbsfulldata[i++] = pdata->MainCell_Info.cell_id & 0x00FF;

    // --预留扩展位--

    // 封包公共处理部分
    public_packet_handle(plbsfulldata, len, 0x00);
}
/*************************************************/
/************GT02B旧协议包结束**************/
kal_uint8 track_cust_wifi_packet_option(kal_uint8 sends)
{
    static kal_uint8 send_op = 0;
    if(sends == 0 || sends == 1)
    {
        send_op = sends;
    }
    return send_op;
}
#if defined __CUSTOM_WIFI_FEATURES_SWITCH__
/******************************************************************************
 *  Function    -  track_cust_paket_2C
 *
 *  Purpose     -  GT300S  WIFI包
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 06-05-2016,  ZengPing  written
 * ----------------------------------------
 ******************************************************************************/
#if 1
kal_uint16 track_cust_paket_2C(void)
{return 0;}
#else
kal_uint16 track_cust_paket_2C(void)
{
    static kal_uint8 last_ssid[20]={"no wifi"};
    kal_uint8 *sendData;
    kal_uint16 no;
    int size, i, ret, index, tmp_i, tmp_j;
    kal_uint8 hex_mac[7] = {0};
    track_gps_data_struct *gd = track_cust_gpsdata_alarm();
    LBS_Multi_Cell_Data_Struct *lbs = track_drv_get_lbs_data();
    applib_time_struct currTime = {0};

    LOGD(L_APP, L_V5, "sum=%d", wifi_status.wifi_sum);

    if(wifi_status.wifi_sum == 0)
    {
        LOGD(L_APP, L_V1, "搜到WIFI个数为0");
        return;
    }

    LOGD(L_APP, L_V5, "ssid %s ? %d", last_ssid,wifi_status.wifi_mac[0]);
    if(strncmp(last_ssid, wifi_status.wifi_mac[0], strlen(wifi_status.wifi_mac[0]))==0)
    {
        LOGD(L_APP, L_V1, "wifi最强信号热点MAC未变，过滤不上报");
        return;
    }

    strncpy(last_ssid, wifi_status.wifi_mac[0], strlen(wifi_status.wifi_mac[0]));
    
#if defined(__GT740__)
    {
        if(wifi_status.wifi_sum == 0)
        {
            LOGD(L_APP, L_V1, "搜到WIFI个数为零!!!!");
            if(G_parameter.extchip.mode != 1)
            {
                track_os_intoTaskMsgQueueExt(track_cust_send_lbs, (void*)4);
            }
            return;
        }

        track_fun_get_time(&currTime, KAL_FALSE, &G_parameter.zone.zone);
        if(currTime.nYear == (*OTA_DEFAULT_HARDWARE_YEAR + 2000))
        {
            LOGD(L_APP, L_V1, "注意!!系统时间未更新!!");
            if(G_parameter.extchip.mode != 1)
            {
                track_cust_wifi_packet_option(1);
            }
            return;
        }
    }
#endif
    size = 10 + 6 + 7 * wifi_status.wifi_sum + 46 + 1;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);
    // datetime
    DataPackingDatetime_6(&sendData[4], gd);

    DataPackingLbs_46(&sendData[10], lbs);

    index = 56;
    sendData[index] = wifi_status.wifi_sum;
    index++;
    for(i = 0; i < wifi_status.wifi_sum; i++)
    {
        //LOGD(L_APP, L_V5, "");;
        if(strstr(wifi_status.wifi_mac[i], "LAST"))
        {
            LOGD(L_APP, L_V7, "1");
            break;
        }
        else if(wifi_status.wifi_rssi[i] == 0)
        {
            LOGD(L_APP, L_V7, "2");
            continue;
        }
        else
        {
            LOGD(L_APP, L_V7, "3");
            if(strlen(wifi_status.wifi_mac[i]) > 0 && wifi_status.wifi_rssi[i] != 0)
            {
                memcpy(&sendData[index], track_fun_stringtohex(wifi_status.wifi_mac[i], 6), 6);
                index = index + 6;
                sendData[index] = wifi_status.wifi_rssi[i];
                index++;
            }
        }
    }
    no = DataPacketEncode78(0x2C, sendData, size);

    LOGH(L_APP, L_V5, sendData, size);
#ifndef __NF2318__
    track_socket_queue_position_send_reg(sendData, size, 0x2C, no);
#endif

    Ram_Free(sendData);
    return no;
}
#endif
#endif


#if defined (__BAT_TEMP_TO_AMS__)
/*采集电池温度上报AMS服务器       --    chengjun  2016-11-16*/

#define  TEMP_LEN    5
#define  TEMP_COUNT  70

kal_int8 track_cust_net2_bat_temperatrue_param(kal_uint16 len, kal_uint8* data)
{
    LBS_Multi_Cell_Data_Struct *lbs = track_drv_get_lbs_data();
    U8 *sendData, i = 13;
    U16 volt, len2;
    int size;
    kal_int8 ret;

    len2 = len + 3/*packet type+temp string len*/;
    size = 11 + 8/*imei*/ + 2/*ext data len*/ + len2/*ext data*/;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
        return -1;
    }
    memset(sendData, 0, size);

    /* 透传数据的长度 */
    sendData[i++] = (len2 & 0xFF00) >> 8;
    sendData[i++] = (len2 & 0x00FF);

    // packet type
    sendData[i++] = 0x0F;

    //温度字符串长度2个字节
    sendData[i++] = (len >> 8) & 0xFF;
    sendData[i++] = len & 0xFF;

    memcpy(&sendData[i], data, len);

    track_cust_paket_FD2(sendData, size);
    track_cust_server2_write_req(1, sendData, size, 0);

    LOGD(L_APP, L_V5, "");
    Ram_Free(sendData);
    return 0;
}


void track_cust_bat_temperatrue_data(void)
{
    char Temperature[TEMP_LEN] = {0};
    kal_int16 temporary = 0;
    int counts = 0;
    charge_measure_struct charge_measure = {0};

    tr_start_timer(TRACK_CUST_TEPERATURE_DATA_TIMER_ID, 2 * 60 * 1000, track_cust_bat_temperatrue_data);
    if(track_cust_status_charger() == 0)
    {
        return;
    }
    track_bmt_get_ADC_result(&charge_measure);
    temporary = (kal_int16)(charge_measure.bmt_vTemp / 1000.00);

    snprintf(Temperature, TEMP_LEN, "%d", temporary);
    counts = G_realtime_data.temp_count;

    memcpy(&G_realtime_data.temperature_data[counts], &Temperature, TEMP_LEN);

    LOGD(L_APP, L_V5, "BatTemp[%d]=%s,%s", counts, Temperature, G_realtime_data.temperature_data[G_realtime_data.temp_count]);
    G_realtime_data.temp_count ++;
    if(G_realtime_data.temp_count >= TEMP_COUNT)
    {
        G_realtime_data.temp_count = 0;
    }

    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
}

void track_cust_send_bat_temperature_data(void)
{
    char temp[1024] = {0};
    int i = 0, n = 0;

    for(i = 0; i < TEMP_COUNT; i++)
    {
        if(strlen(G_realtime_data.temperature_data[i]))
        {
            n += sprintf(temp + n, "%s;", G_realtime_data.temperature_data[i]);
        }
        memset(&G_realtime_data.temperature_data[i], 0, TEMP_LEN);
    }

    LOGD(L_APP, L_V5, "%s,%d,%d", temp, strlen(temp), n);
    if(strlen(temp) <= 0)
    {
        LOGD(L_APP, L_V5, "no bat temperature data to ams");
        return;
    }

    track_cust_net2_bat_temperatrue_param(strlen(temp), temp);
}

#endif /* __BAT_TEMP_TO_AMS__ */


#if defined (__CUST_RS485__)

/*RS485数据网络透传       --    chengjun  2017-03-02*/

/******************************************************************************
 *  Function    -  track_cust_decode_packet_9B
 *
 *  Purpose     -  解析服务器下发的透传数据
 *
 *  Description -   data 已结去除了包头 包长度 CRC 包尾，len为data长度
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-03-02,  chengjun  written
 * ----------------------------------------
 //79 79 00 1E 9B 01 AA 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 C2 00 C0 01 80 A2 DB 00 0B 79 2B 0D 0A
 //            9B 01 AA 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 C2 00 C0 01 80 A2 DB 00 0B
 ******************************************************************************/
void track_cust_decode_packet_9B(kal_uint8 *data, kal_uint16 len)
{
    kal_uint8 packelen = 0, device;
    char *p = NULL;
    char tmp[256] = {0}, *number = NULL;
    kal_uint16 cmdlen;

    LOGH(L_APP, L_V3, data, len);
    //透传数据长度
    cmdlen = len - 4;
    if(cmdlen < 16)
    {
        LOGD(L_APP, L_V4, "len error", len);
        return;
    }

    if(data[0] != 0x9B)
    {
        LOGD(L_APP, L_V4, "cmd %02X error", data[4]);
        return;
    }
    device = data[1];

    p = &data[2];

    LOGD(L_APP, L_V4, "收到外设透传指令");
    track_rs485_write_server_data_to_device(p, cmdlen);
}

/******************************************************************************
 *  Function    -  track_cust_paket_9C
 *
 *  Purpose     -  收到服务器下发的9C透传，执行后将结果反馈到服务器
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-03-02,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_paket_9C(kal_uint8* data, kal_uint16 len, kal_uint8 device)
{
#if 1//__NF2318__
	;
#else
    U8 *sendData;
    U8 tmp;
    U16 no;
    kal_uint16 size, ret;

    LOGD(L_SOC, L_V5, "");
    size = 12 + len;
    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    sendData[5] = device;
    memcpy(&sendData[6], data, len);

    no = DataPacketEncode79(0x9C, sendData, size);
    track_socket_queue_send_netcmd_reg(sendData, size, 0x9C, no);
    Ram_Free(sendData);
	#endif
}
#else
#if 1
void track_cust_packet_9B(kal_uint8 *data,kal_uint8 len)
{;}
#else
void track_cust_packet_9B(kal_uint8 *data,kal_uint8 len)
{
    U16 no;
    kal_uint16 size, ret;
	kal_uint8 *senddata;

	if(len <= 0) return;
	
	size = len+12;
	
	senddata = (U8*)Ram_Alloc(5, size);
	senddata[5] = 0x03;//艾泰克
	memcpy(&senddata[6], data, len);
	no = DataPacketEncode79(0x9B, senddata, size);
	track_socket_queue_send_netcmd_reg(senddata, size, 0x9B, no);
	Ram_Free(senddata);
}
#endif
#endif /* __CUST_RS485__ */


/******************************************************************************
 *  Function    -  track_cust_paket_77
 *
 *  Purpose     -  设备拼包透传AMS协议包
 *
 *  Description -  协议可以同时上报多个模块短包，但该接口只能发一个模块短包
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-03-09,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_paket_77(kal_uint8* data, kal_uint16 len, kal_uint8 device)
{
    U8 *sendData;
    int size;
    kal_int8 ret, i = 0;

    size = len + 4/*packet type + device type + len2B*/;

    LOGD(L_SOC, L_V5, "0x%02x", device);
    sendData = (U8*)Ram_Alloc(7, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    sendData[0] = 0x77;
    sendData[1] = device;
    sendData[2] = (len >> 8) & 0xFF;
    sendData[3] = len & 0xFF;;

    memcpy(&sendData[4], data, len);

    LOGH(L_SOC, L_V7, sendData, size);

    track_cust_paket_FD(sendData, size, 0);

    Ram_Free(sendData);
}

//录音上报服务器的登录包
#if defined (__LUYING__)
void track_cust_paket_server4_01(void)
{
    kal_uint8 *sendData;
    kal_uint16 no, zone;
    int size;

    if(track_cust_is_upload_UTC_time())
    {
        size = 10 + 8 + 2 + 2;
    }
    else
    {
        size = 10 + 8;
    }

    sendData = (U8*)Ram_Alloc(5, size);
    if(sendData == NULL)
    {
        return;
    }
    memset(sendData, 0, size);

    // imei
    memcpy(&sendData[4], track_drv_get_imei(1), 8);

    if(track_cust_is_upload_UTC_time())
    {
        // 类型识别码
        sendData[12] = ((TRACK_DEVICE_ID >> 8) & 0xFF);
        sendData[13] = (TRACK_DEVICE_ID & 0xFF);
        
        // 时区语言
        zone = G_parameter.zone.time;
        zone *= 100;
        zone += G_parameter.zone.time_min;
        zone <<= 4;
        if(G_parameter.zone.zone == 'W')
        {
            zone |= (1 << 3);
        }

        if(G_parameter.lang == 1)
        {
            zone |= 0x02;
        }
        else
        {
            zone |= 0x01;
        }

        LOGD(L_APP, L_V5, "%x", zone);
        sendData[14] = (zone >> 8);
        sendData[15] = (zone & 0x00FF);
        LOGD(L_APP, L_V5, "%x,%x", sendData[14], sendData[15]);
    }

    no = DataPacketEncode78(0x01, sendData, size);
    LOGH(L_APP, L_V5, sendData, size);

    Socket_write_req(2, sendData, size, 0, 1, 1, 1);
    Ram_Free(sendData);
}
#endif /* __LUYING__ */

