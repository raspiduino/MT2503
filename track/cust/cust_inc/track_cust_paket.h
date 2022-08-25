
#ifndef _TRACK_CUST_PAKET_H
#define _TRACK_CUST_PAKET_H

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "track_drv_gps_decode.h"
#include "track_drv_lbs_data.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/
typedef enum
{
    TR_CUST_POSITION_TIMING             = 0,    //定时上报
    TR_CUST_POSITION_DISTANCE           = 1,    //定距上报
    TR_CUST_POSITION_ANGLEREP           = 2,    //拐点上传
    TR_CUST_POSITION_ACC_CHANGE         = 3,    //ACC 状态改变上传
    TR_CUST_POSITION_STATIC             = 4,    //从运动变为静止状态后，补传最后一个定位点
    TR_CUST_POSITION_RECONNECT          = 5,    //网络断开重连后，上报之前最后一个有效上传点
    TR_CUST_POSITION_MODE_GPSUPDATE     = 6,    //星历更新强制上传GPS点
    TR_CUST_POSITION_KEY                = 7,    //按键上传定位点
    TR_CUST_POSITION_POWER_ON           = 8,    //开机上报位置信息
    TR_CUST_POSITION_LBS                = 9,    //未使用
    TR_CUST_POSITION_STATIC_LAST_TIME   = 10,   //设备静止后上报最后的经纬度，但时间更新
    TR_CUST_POSITION_LJDW               =12,    //LJDW上传点
    TR_CUST_POSITION_GPSOFF             =13,    // 静态上传    
    TR_CUST_POSITION_GPSDUP             =14,    // gpsdup上传    
    TR_CUST_POSITION_MAX
} enum_CUST_POSITION_type;

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
extern kal_uint16 track_cust_paket_gpsdata(track_gps_data_struct *gd, LBS_Multi_Cell_Data_Struct *lbs);
extern void track_cust_paket_1C(kal_uint8 *serverid, kal_bool isASCII, kal_uint8 *outstr, kal_uint8 outstrlen);
extern void Server_GPRS_Command(kal_uint8 *serverid, kal_bool isASCII, kal_uint8 *outstr, kal_uint8 outstrlen);
extern kal_uint16 track_cust_paket_1B(track_gps_data_struct *gd, char *number);
extern void Send_IP_Request_data(LBS_Multi_Cell_Data_Struct *lbs_data);
//extern void Analysis_ServerData(U8 *data, int len);
#endif  /* _TRACK_CUST_PAKET_H */

