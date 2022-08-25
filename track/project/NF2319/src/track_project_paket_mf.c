/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "track_cust.h"
#include "track_os_ell.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/
static char *blank = {""}, *s_ON = {"ON"}, *s_OFF = {"OFF"}, *s_Error = {"ERROR"};
#define ON_OFF(value) (value==0?s_OFF:(value==1?s_ON:s_Error))

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

/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

/******************************************************************************
 *  Function    -  
 *
 *  Purpose     -  
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 01-11-2017,  Cjj  written
 * ----------------------------------------
*******************************************************************************/

/******************************************************************************
 *  Function    -  track_fun_ASCII_to_BCD8
 *
 *  Purpose     -  以BCD格式编码(8位)
 *                      data(ascii)=123456789012345
 *                      BCD(hex)   =01 23 45 67 89 01 23 45
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 01-11-2017,  Cjj  written
 * ----------------------------------------
*******************************************************************************/
void track_fun_ASCII_to_BCD8(kal_uint8 *dec,kal_uint8 *src)
{
    char data[17] = {0};
    char BCD[8];
    int len,i;
    len = strlen(src);
    if(len > 16)
    {
        LOGD(L_APP, L_V5,"Error: Number length exceeds 16 characters!");
        return;
    }
    sprintf(data,"%016s",src);
    len = strlen(data);
    if(len%2 > 0)len += 1;
    for(i=0;i<len;i+=2)
    {
        BCD[i/2]=(data[i]<<4)|(data[i+1]&0x0F);
    }
    LOGD(L_APP, L_V5,"BCD=%02x%02x%02x%02x%02x%02x%02x%02x\n",BCD[0],BCD[1],BCD[2],BCD[3],BCD[4]
        ,BCD[5],BCD[6],BCD[7]);
    LOGH(L_APP, L_V5, BCD, 8);
    memcpy(dec, BCD, 8);
}
/******************************************************************************
 *  Function    -  track_fun_ASCII_to_BCD2
 *
 *  Purpose     -  以BCD格式编码(2位)
 *                      data(ascii)=123
 *                      BCD(hex)   =01 23 
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 01-11-2017,  Cjj  written
 * ----------------------------------------
*******************************************************************************/
void track_fun_ASCII_to_BCD2(kal_uint8 *dec,kal_uint8 *src)
{
    char data[5] = {0};
    char BCD[2];
    int len,i;
    len = strlen(src);
    if(len > 4)
    {
        LOGD(L_APP, L_V5,"Error: Number length exceeds 4 characters!");
        return;
    }
    sprintf(data,"%04s",src);
    len = strlen(data);
    if(len%2 > 0)len += 1;
    for(i=0;i<len;i+=2)
    {
        BCD[i/2]=(data[i]<<4)|(data[i+1]&0x0F);
    }
    LOGD(L_APP, L_V5,"BCD=%02x%02x\n",BCD[0],BCD[1]);
    LOGH(L_APP, L_V5, BCD, 2);
    memcpy(dec, BCD, 2);
}

/******************************************************************************
 *  Function    -  DataPacketEncode67
 *
 *  Purpose     -  67协议打包
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 01-11-2017,  Cjj  written
 * ----------------------------------------
*******************************************************************************/
static kal_uint16 DataPacketEncode67(U8 cmd, U8 *sendData, U8 len)
{
    U16 tmp, tmp1;

    //起始位
    sendData[0] = 0x67;
    sendData[1] = 0x67;

    //协议号
    sendData[2] = cmd;
    
    //长度
    track_fun_reverse_16(&sendData[3],(len - 7));

    //信息序列号
    tmp = getSerialNumber();
    track_fun_reverse_16(&sendData[5],tmp);
    LOGD(L_APP, L_V5, "SerialNumber:%.2X%.2X", sendData[5], sendData[6]);

    //CRC校验
    tmp1 = GetCrc16(sendData, len - 2);
    sendData[len - 2] = (tmp1 & 0xFF00) >> 8;
    sendData[len - 1] = (tmp1 & 0x00FF);

    return tmp;
}

/******************************************************************************
 *  Function    -  DataPackingLocation_Mask
 *
 *  Purpose     -  定位掩码
 *
 *  Description -  当所有数据都能获取时:GPS定位(GPS发送)，则发一条LBS和WIFI；
 *              GPS不定位时(GPS不发送)，则发三条LBS和WIFI。    
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 01-11-2017,  Cjj  written
 * ----------------------------------------
*******************************************************************************/
static void DataPackingLocation_Mask(U8 *sendbuf, track_gps_data_struct *gd,LBS_Multi_Cell_Data_Struct *lbs)
{
    if(gd->status >=2 )//定位
    {
        sendbuf[0] |= 0x01;//定位数据发送
        if(lbs->MainCell_Info.cell_id != 0)
        {
            sendbuf[0] |= 0x02;//LBS数据发送
        }
        if(wifi_status.wifi_sum !=0)
        {
            sendbuf[0] |= 0x10;//WIFI数据发送
        }
    }
    else//未定位
    {
        if(lbs->MainCell_Info.cell_id != 0)
        {
            sendbuf[0] |= 0x02;//LBS1数据发送
        }
        if(lbs->NbrCell_Info[0].cell_id != 0)
        {
            sendbuf[0] |= 0x04;//LBS2数据发送
        }
        if(lbs->NbrCell_Info[1].cell_id != 0)
        {
            sendbuf[0] |= 0x08;//LBS3数据发送
        }
        if(wifi_status.wifi_sum ==1)
        {
            sendbuf[0] |= 0x10;//WIFI1数据发送
        } 
        if(wifi_status.wifi_sum ==2)
        {
            sendbuf[0] |= 0x20;//WIFI2数据发送
        } 
        if(wifi_status.wifi_sum >=3)
        {
            sendbuf[0] |= 0x40;//WIFI3数据发送
        }        
    }
}

/******************************************************************************
 *  Function    -  DataPackingGps_15
 *
 *  Purpose     -  填充GPS数据字段区间
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 01-11-2017,  Cjj  written
 * ----------------------------------------
*******************************************************************************/
static void DataPackingGps_15(U8 *sendbuf, kal_uint8 l_mask, track_gps_data_struct *gd, U8 *size)
{
    kal_uint16 Course,speed;
    kal_uint8 totalsat = 0;
    int i, x, j;
    kal_uint8 snr[2] = {0};    
    if(!(l_mask&1))
    {
       LOGD(L_SOC, L_V6, "GPS is not located, do not need to send GPS data");
       return;
    }
    *size +=15;
    
    LOGD(L_APP, L_V6, "status:%d,%d, sat:%d,%d, Latitude:%f%c, Longitude:%f%c, Speed:%f, Course:%f",
         gd->gprmc.status, gd->gpgga.posi_fix, gd->gpgga.sat, gd->bdgga.sat, gd->gprmc.Latitude, gd->gprmc.NS, gd->gprmc.Longitude, gd->gprmc.EW, gd->gprmc.Speed, gd->gprmc.Course);
    //纬度、经度8
    track_fun_LongitudeLatitudeToHex(&sendbuf[0], gd->gprmc.Latitude);
    track_fun_LongitudeLatitudeToHex(&sendbuf[4], gd->gprmc.Longitude);

    //最大两个SNR值2
    for(i = 0, j = 0; i < gd->gpgga.sat; i++)
    {
        for(x = 0; x < 16; x++)
        {
            if(gd->gpgsa.satellite_used[i] == gd->gpgsv.Satellite_ID[x])
            {
                gd->gpgsa.satellite_SNR_used[i] = gd->gpgsv.SNR[x];
                if(i < 2)
                {
                    snr[i] = gd->gpgsa.satellite_SNR_used[i];
                }
                else
                {
                    for(j = 0; j < 2; j++)
                    {
                        if(snr[j] < gd->gpgsa.satellite_SNR_used[i])
                        {
                            snr[j] = gd->gpgsa.satellite_SNR_used[i];
                            break;
                        }
                    }
                }
                break;
            }
        }
        LOGD(L_SOC, L_V4, "satellite:[%d]%d", gd->gpgsa.satellite_used[i], gd->gpgsa.satellite_SNR_used[i]);
    }  
    memcpy(&sendbuf[8], snr, 2);
    
    //速度2
    speed = gd->gprmc.Speed*100;
    track_fun_reverse_16(&sendbuf[10], speed);
    //航向2
    Course = gd->gprmc.Course;
    track_fun_reverse_16(&sendbuf[12], Course);
    if(gd->gprmc.NS == 'N')
    {
        sendbuf[10] |= 1 << 2;
    }
    if(gd->gprmc.EW == 'W')
    {
        sendbuf[10] |= 1 << 3;
    }
    //有效定位卫星数1
    totalsat = gd->gpgga.sat + gd->bdgga.sat;
    if(totalsat > 15)
        totalsat = 15;
    sendbuf[14] = totalsat;
}

/******************************************************************************
 *  Function    -  DataPackingLbs_25
 *
 *  Purpose     -  多基站数据打包
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 01-11-2017,  Cjj  written
 * ----------------------------------------
 ******************************************************************************/
static void DataPackingLbs_25(U8 *sendbuf, kal_uint8 l_mask, LBS_Multi_Cell_Data_Struct *lbs, U8 *size)
{   
     U8 i = 0, num,j;
    if(lbs->MainCell_Info.cell_id ==0)
    {
       LOGD(L_SOC, L_V6, "Is not LBS, do not need to send LBS data");
       return;       
    }
    //LOGD(L_APP, L_V6, "mcc:%d, mnc:%d, lac:%d, cell id:%d",
    //     lbs->MainCell_Info.mcc, lbs->MainCell_Info.mnc, lbs->MainCell_Info.lac, lbs->MainCell_Info.cell_id);
    track_fun_reverse_16(&sendbuf[0], lbs->MainCell_Info.mcc);
    track_fun_reverse_16(&sendbuf[2], lbs->MainCell_Info.mnc);
    track_fun_reverse_16(&sendbuf[4], lbs->MainCell_Info.lac);
    track_fun_reverse_32(&sendbuf[6], lbs->MainCell_Info.cell_id);
    sendbuf[10] = (U8)lbs->MainCell_Info.rxlev;
    num = 11;
    *size += 11;
    if(!(l_mask&1))
    {
        LOGD(L_SOC, L_V6, "GPS is not located");
        if((l_mask&4) && (l_mask&10))
        {
            j=2;
            *size += 14;
        }
        else if(l_mask&4)
        {
            j=1;
            *size += 7;
        }
        else if(l_mask&10)
        {
            j=1;
            num +=7;
            *size += 7;
        }
        else
        {
            j=0;
        }
        for(i = 0; i < j; i++)
        {
            track_fun_reverse_16(&sendbuf[num + i * 7], lbs->NbrCell_Info[i].lac);
            track_fun_reverse_32(&sendbuf[num + i * 7 + 4], lbs->NbrCell_Info[i].cell_id);
            sendbuf[num + i * 6 + 6] = (U8)lbs->NbrCell_Info[i].rxlev;
        }
    }
}

/******************************************************************************
 *  Function    -  DataPackingWifi_21
 *
 *  Purpose     -  WIFI数据打包
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 01-11-2017,  Cjj  written
 * ----------------------------------------
 ******************************************************************************/
static void DataPackingWifi_21(U8 *sendbuf, kal_uint8 l_mask, U8 *size)
{   U8 num = 1;
    kal_uint8 i;
    int index = 0;
    if(wifi_status.wifi_sum == 0)
    {
        LOGD(L_APP, L_V1, "Is not WIFI, do not need to send WIFI data");
        return;
    }
    
    if(!(l_mask&1))
    {
        LOGD(L_SOC, L_V6, "GPS is not located");
        if((l_mask&40) && (l_mask&100))
        {
            num = 3;
        }
        else if(l_mask&40)
        {
            num = 2;            
        }
        else if(l_mask&100)
        {
            //跑不到这里的，WIFI是RSII从值低排序好的。
            num = 2;
        }
        else
        {
            num = 1;
        }
    }
    for(i = 0; i < num; i++)
    {
        if(strstr(wifi_status.wifi_mac[i], "LAST"))
        {
            LOGD(L_APP, L_V7, "1");
            break;
        }
        else if(wifi_status.wifi_rssi[i] == 0)
        {
            LOGD(L_APP, L_V7, "rssi理想状态下才能为0?");
            continue;
        }
        else
        {
            LOGD(L_APP, L_V7, "3");
            if(strlen(wifi_status.wifi_mac[i]) > 0 && wifi_status.wifi_rssi[i] != 0)
            {
                memcpy(&sendbuf[index], track_fun_stringtohex(wifi_status.wifi_mac[i], 6), 6);
                index = index + 6;
                sendbuf[index] = wifi_status.wifi_rssi[i];
                index++;
                *size += 7;
            }
        }
    }
}   

/******************************************************************************
 *  Function    -  DataPacking_Indefinable
 *
 *  Purpose     -  GPS、WIFI、LBS、车辆信息(电池信息、里程、速度)数据打包
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 01-11-2017,  Cjj  written
 * ----------------------------------------
*******************************************************************************/
static void DataPacking_Indefinable(U8 *sendbuf, track_gps_data_struct *gd,LBS_Multi_Cell_Data_Struct *lbs)
{
    char imei_data[17];
    applib_time_struct currTime = {0};
    kal_uint8 i = 0;
    kal_uint8 location_mask = 0;
    kal_uint32 sec;
    charge_measure_struct charge_measure = {0};
    kal_int16 temporary = 0;
    //boxcode(同终端ID)
    sprintf(imei_data, "%s", (char *)track_drv_get_imei(0));
    track_fun_ASCII_to_BCD8(&sendbuf[i],imei_data);
    i+=8;
    
    //时间
    applib_dt_get_rtc_time(&currTime);
    sec = applib_dt_mytime_2_utc_sec(&currTime, 0);   
    track_fun_reverse_32(&sendbuf[i],sec);
    i+=4;
    
    //定位掩码
    DataPackingLocation_Mask(&sendbuf[i],gd,lbs);
    location_mask = sendbuf[i];
    i+=1;

    //GPS数据
    DataPackingGps_15(&sendbuf[i],location_mask,gd,&i);

    //LBS数据
    DataPackingLbs_25(&sendbuf[i],location_mask,lbs,&i);

    //WIFI数据
    DataPackingWifi_21(&sendbuf[i],location_mask,&i);

    //电池剩余电量
    i+=2;
    //电池电压
    i+=2;
    //满充容量
    i+=2;
    //订单里程
    i+=4;
    //车速    
    i+=2;
    
    //电池温度
    track_bmt_get_ADC_result(&charge_measure);
    temporary = (kal_int16)(charge_measure.bmt_vTemp / 1000.00); 
    track_fun_reverse_16(&sendbuf[i], temporary);
    i+=2;
}

