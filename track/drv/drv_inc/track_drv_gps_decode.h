/******************************************************************************
 * track_gps_data_decode.h -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        GPS 解码
 *
 * modification history
 * --------------------
 * v1.0   2012-07-24,  chengjun create this file
 *
 ******************************************************************************/

#ifndef _TRACK_DRV_GPS_DECODE_H
#define _TRACK_DRV_GPS_DECODE_H

/****************************************************************************
* Include Files             包含头文件
*****************************************************************************/
#include "track_os_data_types.h"
#include "custom_mmi_default_value.h"
#include "kal_public_defs.h"
#include "mtk_gps_type.h"
#include "track_drv_lbs_data.h"

/*****************************************************************************
 *  Define			    宏定义
*****************************************************************************/
//#define GPS_DECODE_DEBUG

#define NMEA_BUFF_SIZE  200

/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/
typedef enum
{
    GPS,
    BD,
    GN,
    GLONASS,
    GPS_GLONASS,
    BDS_GLONASS,
    GPS_BDS_GLONASS,
    GPS_MODE_MAX
}enum_gps_mode;

/*****************************************************************************
 *  Struct			    数据结构定义
*****************************************************************************/
typedef struct
{
    kal_uint8 nHour;//时间
    kal_uint8 nMin;
    kal_uint8 nSec;
    float Latitude;//纬度
    kal_uint8 NS;
    float Longitude;//经度
    kal_uint8 EW;
    kal_uint8 posi_fix;//GPS状态
                               //0=不可用/1=单点定位/2=差分定位/3-5 =不支持/6-正在估算
    kal_uint8 sat;//当前使用的卫星数
    float HDOP;
    float msl_altitude;//海拔
    kal_uint8  Units1;//单位m
    float  Geoid_Altitude;//地球椭球面相对大地水准面高度
    kal_uint8  Units2;//单位m
    float Age;//差分时间
    kal_uint16 station_ID;//差分站ID
} gps_gpgga_struct;

typedef struct
{
    kal_uint8 mode;//定位模式A=允许自动2D  或3D 切换/M=强制在2D 或3D工作
    kal_uint8 status;//定位类型1=未定位/2=2D定位/3=3D定位
    kal_uint8 satellite_used[MTK_GPS_SV_MAX_NUM];//PRN码(伪随机噪声码)
    kal_uint8 satellite_SNR_used[MTK_GPS_SV_MAX_NUM];//信噪比
    kal_uint8 satellite_SNR_used_average;//最强3个的平均信噪比
    float  PDOP;
    float  HDOP;
    float  VDOP;
} gps_gpgsa_struct;

typedef struct
{
    kal_uint8 Number_Of_Messages;//语句总数
    kal_uint8 index;//本次是总数的第几条
    kal_uint8 Satellites_In_View;//可见卫星数,MTK 不按国际标准，实际测出4*4
    kal_uint8 Satellite_ID[MTK_GPS_SV_MAX_NUM];//PRN码
    kal_uint8 Elevation[MTK_GPS_SV_MAX_NUM];//卫星仰角
    kal_uint16 Azimuth[MTK_GPS_SV_MAX_NUM];//卫星方位角
    kal_uint8 SNR[MTK_GPS_SV_MAX_NUM];//信噪比
} gps_gpgsv_struct;


typedef struct
{
    MYTIME Date_Time;//时间日期
    kal_uint8 status;//状态【 0=不定位 / 1=定位 / 2=不定位(修改过时间的) 】
    float Latitude;//纬度
    kal_uint8 NS;
    float Longitude;//经度
    kal_uint8 EW;
    float Speed;//速度( 解码后单位转为km/h)
    float Course;//方位角
    kal_uint8 Magnetic_variation2;//磁偏角
    kal_uint8 Indicater2;//磁偏角方向(E/W)
    kal_uint8 Mode;
} gps_gprmc_struct;


typedef struct
{
    float Course0;//运动角度
    kal_uint8  Reference0;//真北参考系
    float Course1;//运动角度
    kal_uint8  Reference1;//磁北参考系
    float Speed0;//速度
    kal_uint8 Units0;//单位:节
    float Speed1;//速度
    kal_uint8 Units1;//单位:km/h
    kal_uint8 Mode;
} gps_gpvtg_struct;


typedef struct
{
    float Latitude;
    kal_uint8 NS;
    float Longitude;
    kal_uint8 EW;
    kal_uint8 nHour;
    kal_uint8 nMin;
    kal_uint8 nSec;
    kal_uint8 Status;
    kal_uint8 Mode;
} gps_gpgll_struct;

typedef struct
{
    kal_uint8  Signal_Strength;
    kal_uint8  Signal_Ratio;
    float   Beacon_Frequency;
    kal_uint8   Beacon_Bit_Rate;
    kal_uint8   Channel_Number;
} gps_gpmss_struct;



typedef struct
{
    MYTIME Date_Time;
    kal_uint8  Local_zone_hour ;
    kal_uint8  Local_zone_minutes;
} gps_gpzda_struct;

typedef kal_int8 (*gpsFuncPtrEx) (enum_gps_mode, char*);
    
typedef struct
{
    const S8        *cmd_string;
    gpsFuncPtrEx    FuncPtr;
    enum_gps_mode   gw_mode;
} GPS_Decode_struct;

typedef struct
{
    LOCAL_PARA_HDR
    mtk_gps_position pData;
} gps_nmea_decode_req_struct;



typedef struct
{
    kal_uint8 status;//0=gps off 1=未定位 2=2D 定位 3=3D 定位，与$GPGSA 的第2字段同步
    kal_uint8 filter;//大于20为标记成过滤的数据类型
    enum_gps_mode     gw_mode;
    gps_gpgga_struct  gpgga;
    gps_gpgsa_struct  gpgsa;
    gps_gpgsv_struct  gpgsv; 
    gps_gprmc_struct  gprmc;
    gps_gpvtg_struct  gpvtg;
    
    gps_gpgga_struct  bdgga;
    gps_gpgsa_struct  bdgsa;
    gps_gpgsv_struct  bdgsv; 
    gps_gprmc_struct  bdrmc;
    gps_gpvtg_struct  bdvtg;
    
    Multi_Cell_Info_Struct   lbs;
} track_gps_data_struct;//GPS 解码后完整数据
typedef struct
{
    LOCAL_PARA_HDR
    track_gps_data_struct pData;
} gps_nmea_decode_req_struct2;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 len;
}gps_nema_req_string;

typedef struct
{
    kal_bool valid;
    float altitude;
    gps_gprmc_struct  gprmc;
} track_gps_epo_struct;//用于AGPS  EPO 
/*track_gps_data_struct 用于上层获取GPS 数据，使用前作时区校准，
    不再是原始数据，不能用于AGPS EPO 功能*/

/*****************************************************************************
* Local variable            局部变量
*****************************************************************************/


/****************************************************************************
* Global Variable           全局变量
*****************************************************************************/


/****************************************************************************
* Global Variable - Extern          引用全局变量
*****************************************************************************/


/*****************************************************************************
 *  Global Functions	- Extern	    引用外部函数
*****************************************************************************/
extern void track_drv_test_gps_fix_time(void);

/*****************************************************************************
 *  Local Functions	            本地函数
*****************************************************************************/
static void track_gps_data_decode_backup(enum_gps_mode gps_working);

/*****************************************************************************
 *  Global Functions            全局函数
*****************************************************************************/
extern void track_gps_data_clean(void);

#endif  /* _TRACK_DRV_GPS_DECODE_H */

