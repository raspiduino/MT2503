#ifndef _TRACK_NVRAM_STRUCT_C_
#define _TRACK_NVRAM_STRUCT_C_

#include "audio_nvram_def.h"
#include "kal_general_types.h"
#include "nvram_data_items.h"
#include "custom_mmi_default_value.h"
#include "ps_public_enum.h"

typedef struct
{
    kal_uint8       start_flag;         // 开机标记
    kal_uint8       error_index;        // error index
    kal_uint8       errorCount;
    kal_uint8       error[20];          //
    kal_uint32      errortime[20];      //
    kal_uint32      start_count;        // 非软件逻辑调用重启的次数统计
} nvram_sys_abnormal_data_struct;


typedef struct
{
    //kal_uint16    total;          //储存的GPS的数据总数
    kal_uint16  data_first;
    kal_uint16  data_last;          //指向下一个储存GPS数据的空间
} nvram_gps_backup_data_param_struct;
/*  end  NVRAM备份定位数据   */

typedef struct
{
    MYTIME      Date_Time;
    kal_uint8   status;
    float       Latitude;
    kal_uint8   NS;
    float       Longitude;
    kal_uint8   EW;
    float       Speed;
    float       Course;
    kal_uint8   Magnetic_variation2;
    kal_uint8   Indicater2;
    kal_uint8   Mode;
} nvram_gps_gprmc_struct;

typedef struct
{
    kal_uint8 nHour;//时间
    kal_uint8 nMin;
    kal_uint8 nSec;
    float     Latitude;//纬度
    kal_uint8 NS;
    float     Longitude;//经度
    kal_uint8 EW;
    kal_uint8 posi_fix;//GPS状态 0=不可用/1=单点定位/2=差分定位/3-5 =不支持/6-正在估算
    kal_uint8 sat;//当前使用的卫星数
    float     HDOP;
    float     msl_altitude;//海拔
    kal_uint8 Units1;//单位m
    float     Geoid_Altitude;//地球椭球面相对大地水准面高度
    kal_uint8 Units2;//单位m
    float     Age;//差分时间
    kal_uint16 station_ID;//差分站ID
} nvram_gps_gpgga_struct;
typedef struct
{
    kal_uint16 mcc;
    kal_uint16 mnc;
    kal_uint16 lac;
    kal_uint16 cell_id;
    kal_int16 rxlev;          /*  rxlev  : 通过catcher 信息查看，这个值应该是被处理后的信号电平，算信号等级值，不是真正的信号强度值 */
    /* track_drv_convert_rxlev_to_rssi  -信号等级逆转换为信号强度 -- chengjun  2012-03-08*/
} nvram_Multi_Cell_Info_Struct;

typedef struct
{
    nvram_gps_gprmc_struct rmc;
    nvram_gps_gpgga_struct gga;
    nvram_Multi_Cell_Info_Struct     lbs;
    kal_uint32  distance;
} nvram_gps_last_data_struct;



typedef struct
{
    kal_uint8   flag;//0:默认无文件;1:载入文件;2:文件正常加载;
    kal_uint8   index;
    kal_uint8   unconditional;
    kal_uint8   filemd5[16];
    kal_uint8   version[100];
    kal_uint8   server[100];
    kal_uint16  port;
    kal_uint8   dateCount[3];   /*年月日*/
    kal_uint8   resetCount;     /*默认每天最多100次*/
    kal_uint8   resetDay;       /*默认连续最多10天*/
    kal_uint8   resetCountMax;  /*默认每天最多100次*/
    kal_uint8   resetDayMax;    /*默认连续最多10天*/
} nvram_check_ota_struct;



typedef struct
{
    kal_int8           sensor_type;            //sensor 类型
} nvram_drv_parameter_struct;


#endif

