#if defined(__NF2319__)
#ifndef _TRACK_PROJECT_CONTROL_MF_H
#define _TRACK_PROJECT_CONTROL_MF_H

/****************************************************************************
*  Include Files                        包含头文件
- track_cust_paket_xq.h
*****************************************************************************/

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
    float                       speed;          //车辆速度，单位KM/H
    float                       distance;       //车辆移动的距离，单位M
    kal_uint8                   iChr;           //控制器的电流
    kal_uint8                   vChr;           //控制器的电压
    kal_uint8                   state1;         //控制状态
    kal_uint8                   state2;         //控制状态
} ctrl_data_struct;
/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
 void control_write_data();
 void track_ctrl_uart_rece(kal_uint8* buff, kal_uint16 len);
#endif  /* _TRACK_PROJECT_CONTROL_MF_H */
#endif
