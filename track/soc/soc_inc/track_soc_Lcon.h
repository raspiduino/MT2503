#ifndef _TRACK_SOC_LCON_H
#define _TRACK_SOC_LCON_H

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "soc_api.h"
#include "track_soc.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/
#define MAX_SND_BUFFER_SIZE 1500

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/
typedef enum
{
    SOC_SEND_DATA_ERROR             = -2,           // 发送数据错误
    SOC_CONNECT_ERROR               = -1,           // 连接错误
    SOC_IDLE                        = 0,            // 空闲
    SOC_BEGIN_CONNECT               = 1,            // 开始连接
    SOC_CONNECT_SUCCESS             = 2,            // 连接成功
    SOC_CONNECT_ServerNotResponding = 3,            //服务器无反应
    SOC_SEND_DATA                   = 4,
    SOC_RECV_DATA                   = 5,            // 接收到新的数据
    SOC_RECV_DATA_MayNotBeComplete  = 6,            // 接收到新的数据，由于缓冲区已满，先将可能未完整接受完的数据返回再继续接收
    SOC_CONNECT_CLOSE               = 7,            // 已建立的连接被关闭
    SOC_RECV_HOST_BY_NAME           
} track_soc_status_enum;

typedef enum
{
    SOC_CONN_DISCONNECT,            // 连接断开
    SOC_CONN_FAILURE,               // 连接失败
    SOC_CONN_SUCCESSFUL,            // 连接成功
    SOC_CONN_CONNECTING,            // 正在连接
} track_soc_connstatus_enum;

typedef enum
{
    PACKET_ALARM_DATA               = 1,               // 1
    PACKET_NVRAM_BACKUP_DATA,            // 2
    PACKET_POSITION_DATA,            // 3
    PACKET_HEARTBEAT_DATA,            // 4
    PACKET_NET_LOG_DATA,             // 5
    PACKET_NET_CMD_DATA,              // 6
    PACKET_LBS_DATA,              // 7

    PACKET_MAX_DATA			 //
} track_packet_enum;

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/
typedef void (*track_soc_func_ptr)(void *);

typedef void (*Func_Ptr)(void *);

typedef struct
{
    kal_uint8          ref_count;
    kal_uint16         msg_len;
    kal_uint32         status;
} mmi_test_info_req_struct;

typedef struct
{
    track_soc_status_enum status;       // 回调类型
    kal_uint8 *recvBuff;                // 接收数据指针
    kal_int32 recvBuffLen;              // 接收数据的长度
    kal_uint8 *databak;                 // 发送的数据备份
    kal_uint8 queue_id;                 // 队列编号
    kal_uint8 packet_type;              // 数据包类型
    kal_uint32 no;                      // 序列号，与请求中的一致，仅仅是个标记，无其它意义
    kal_uint8 ip_from_hostname[4];      // 域名解析请求返回的IP地址
    kal_int8 errorid;                   // 错误代码
    kal_uint8 batchCount;               // 
} track_soc_Callback_struct;

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
*  Global Functions                     全局函数
******************************************************************************/

/******************************************************************************
 *  Function    -  
 *
 *  Purpose     -  回调函数
 *
 *  static void event(track_soc_Callback_struct *par)
 *  {
 *      
 *  }
 *
 *  Description -  参数         描述
 *                 ip_addr      需要连接的目标地址和端口的结构体
 *                 func         事件处理回调函数
 *                 no           序号（回调函数中返回，仅仅是个标记作用，默认为0即可）
 *
 *  return         0            正常
 *                 -1           回调函数未设置
 *                 -2           无效的IP地址或端口
 *                 -3           上一个连接请求还未结束，不能重复请求
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 06-08-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/

/******************************************************************************
 *  Function    -  track_soc_conn_req
 *
 *  Purpose     -  Socket连接请求函数
 *
 *  Description -  参数         描述
 *                 ip_addr      需要连接的目标地址和端口的结构体
 *                 func         事件处理回调函数
 *                 no           序号（回调函数中返回，仅仅是个标记作用，默认为0即可）
 *
 *  return         0            正常
 *                 -1           回调函数未设置
 *                 -2           无效的IP地址或端口
 *                 -3           上一个连接请求还未结束，不能重复请求
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 06-08-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
extern kal_int8 track_soc_conn_req(sockaddr_struct *ip_addr, Func_Ptr func, kal_uint32 no);

/******************************************************************************
 *  Function    -  track_soc_write_req
 *
 *  Purpose     -  Socket发送数据函数
 *
 *  Description -  参数         描述
 *                 data         需要发送的数据指针首地址
 *                 datalen      发送的数据字节数
 *                 packet_type  数据包类型
 *                 no           序号（回调函数中返回，仅仅是个标记作用，默认为0即可）
 *
 *  return         0            正常
 *                 -1           回调函数未设置，连接未建立，不能发送数据
 *                 -2           发送的数据长度大于4096字节
 *                 -3           上一个发送数据的请求还未结束，不能重复请求
 *                 -4           发送的数据指针为空
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 06-08-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
extern kal_int8 track_soc_write_req(kal_uint8 *data, kal_int32 datalen, kal_uint8 packet_type, kal_uint32 no);

/******************************************************************************
 *  Function    -  track_soc_gethostbyname
 *
 *  Purpose     -  Socket域名解析请求函数
 *
 *  Description -  参数         描述
 *                 hostname     需要解析的域名字符串
 *                 func         事件处理回调函数
 *                 no           序号（回调函数中返回，仅仅是个标记作用，默认为0即可）
 *
 *  return         0            正常
 *                 -1           回调函数未设置
 *                 -2           域名为空，或域名字符串长度超出了100个字符
 *                 -3           上一个域名解析请求还未结束，不能重复请求
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 06-08-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
extern kal_int8 track_soc_gethostbyname(char *hostname, Func_Ptr func);


extern kal_int8 track_soc_callback_register(Func_Ptr func);
#endif  /* _TRACK_SOC_LCON_H */

