/******************************************************************************
 * track_drv_bt.h -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        BT（CSR1012）驱动
 *
 * modification history
 * --------------------
 * v1.0   2016-08-30,  chengjun create this file
 *
 ******************************************************************************/
#if defined(__CUST_BT__)
/****************************************************************************
* Include Files                         包含头文件
*****************************************************************************/
#ifndef _TRACK_DRV_BT_H
#define _TRACK_DRV_BT_H

#include "stack_msgs.h"
#include "stack_ltlcom.h"
#include "drvsignals.h"
#include "kal_public_defs.h"

/*****************************************************************************
* Typedef  Enum                         枚举定义
*****************************************************************************/
typedef enum
{
    BT_RESTORY_FACTORY_REQ,
    BT_VERSINO_REQ,
    BT_DATA_TC_REQ,//万能透传指令，除指令头外自定义数据
    BT_ACTION_REQUEST_MAX,
} bt_action_request_enum;

/*****************************************************************************
 *  Struct                              数据结构定义
 *****************************************************************************/
 #define BT_UART_BUFF_LEN_MAX 32
typedef struct
{
    kal_uint8 event;
    kal_uint8 data[BT_UART_BUFF_LEN_MAX];
} bt_msg_struct;

typedef struct
{
    LOCAL_PARA_HDR
    bt_msg_struct msg_body;
} bt_events_msg_struct;


/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#define BT_CMD_ERROR            (0x00)     //错误标记
#define BT_POWON_INIT_EVENT     (0x01)     //上电初始化 
#define BT_LISTEN_RECEIVE_DATA  (0x07)     //监听数据 
#define BT_SET_CONCOX_PARAM     (0x54)     // 设置蓝牙Concox广播参数
#define BT_GET_CONCOX_PARAM     (0x55)     // 查询蓝牙Concox广播参数
#define BT_SET_SCAN_TIME        (0x56)     // 设置蓝牙扫描时间
#define BT_GET_SCAN_TIME        (0x57)     // 查询蓝牙扫描时间
#define BT_GET_RUN_STATUS       (0x58)     // 查询蓝牙运行状态
#define BT_SET_WORK_TIME        (0x60)     // 设置蓝牙工作时间
#define BT_GET_WORK_TIME        (0x61)     // 查询蓝牙工作时间
#define BT_SET_BROADCAST_PARAM  (0x62)     // 设置广播参数
#define BT_GET_BROADCAST_PARAM  (0x63)     // 查询广播参数  broadcast
#define BT_SET_FACTORY          (0xFE)     // 恢复出厂设置
#define BT_GET_SW_VERSION       (0xFF)     // 查询软件版本号

/*****************************************************************************
* Local variable                        局部变量
*****************************************************************************/

/****************************************************************************
* Global Variable                       全局变量
*****************************************************************************/


/****************************************************************************
* Global Variable - Extern              引用全局变量
*****************************************************************************/


/*****************************************************************************
 *  Global Functions    - Extern        引用外部函数
 *****************************************************************************/

/*****************************************************************************
 *  Local Functions                     本地函数
 *****************************************************************************/


/*****************************************************************************
 *  Global Functions			全局函数
 *****************************************************************************/
extern void track_drv_set_bt_broadcast_param(kal_uint8*device_string, kal_uint8* imei_hex);

#endif  /* _TRACK_DRV_BT_H */

#endif  /*__CUST_BT__*/


