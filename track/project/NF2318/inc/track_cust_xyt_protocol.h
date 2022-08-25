
/*******************************************************************************************
 * Filename:    track_cust_xyt_procotol.h
 * Author :     lgs
 * Date :       2019-12-16
 * Comment:     行运兔平台协议接口头文件
 ******************************************************************************************/

#if defined(__NF2318__)

/****************************************************************************
* Include Files                         包含头文件
*****************************************************************************/
#include "track_cust.h"


/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#define XYT_PACKET_HEAD_LEN     22
#define XYT_IDENTIFIER_CODE_LEN 12
#define XYT_DEVICE_CODE         4
#define XYT_PACKET_MIN_LEN      25  /* (消息长度2) + (消息头22) + (消息体n) + (校验码1) */

#define XYT_STE_CODE            0x04000000  /* 注册ID */

/*****************************************************************************
 *  Struct                              数据结构定义
 *****************************************************************************/
typedef enum
{
    XYT_UL_REGISTER             = 0x8F,         // 注册命令
    XYT_UL_AUTH                 = 0x81,         // 终端鉴权
    XYT_UL_GPS                  = 0x82,         // GPS
    XYT_UL_HB                   = 0x83,         // 终端基础信息上报/心跳
    XYT_UL_REQUEST              = 0x8A,         // 主动请求数据
    XYT_UL_DEFAULT              = 0x8B,         // 恢复出厂设置命令
    XYT_UL_RESET                = 0x8C,         // 重启动命令
    XYT_UL_DEFENCE              = 0x90,         // 设防/撤防命令
    XYT_UL_ENGINE               = 0x91,         // 启动/关闭命令
    XYT_UL_SEEK                 = 0x97,         // 寻车信号命令
    XYT_UL_TURNOFF              = 0x98,         // 关机命令
    XYT_UL_UPG                  = 0xA0,         // 程序升级准备命令
    XYT_UL_BATT_LOCK            = 0xA8,         // 开电池盒锁命令
    XYT_UL_GPS_INTERVAL         = 0xA9,         // GPS数据上传时间设置命令
    XYT_UL_LOCK_PARAM           = 0xAB,         // 设置电机锁参数
    XYT_UL_SIM                  = 0xAD,         // SIM卡信息上报
    XYT_UL_STORE_ALM            = 0xC0,         // 存储的报警信息上报
    XYT_UL_STORE_BATT           = 0xC1,         // 存储的电池状态信息上报
    XYT_UL_DEVICE_ID            = 0x9D,         // 修改设备ID
    XYT_UL_PASSTHROUGH          = 0xAE,         // 文本数据透传命令
    XYT_UL_VOICE_PLAY_RSP       = 0xD1,         // 远程语音播报响应
    XYT_UL_VOICE_SYNC           = 0xD2,         // 语音数据编号同步请求报文
    XYT_UL_GET_HTTP_LINK        = 0xD3,         // 文件链接获取
    XYT_UL_VOICE_ADD            = 0xD4,         // 增加语音数据
    XYT_UL_VOICE_ADD_RST        = 0x64,         // 增加语音数据结果上报
    XYT_UL_VOICE_DEL            = 0xD5,         // 删除语音数据
    XYT_UL_VOICE_DEL_RST        = 0x65,         // 删除语音数据结果上报
    XYT_UL_UNKNOW
} xyt_uplink_cmd_type;

typedef enum
{
    XYT_DL_REGISTER             = 0x0F,         // 注册命令
    XYT_DL_AUTH                 = 0x01,         // 终端鉴权
    XYT_DL_GPS                  = 0x02,         // GPS
    XYT_DL_HB                   = 0x03,         // 终端基础信息上报/心跳
    XYT_DL_REQUEST              = 0x0A,         // 主动请求数据
    XYT_DL_DEFAULT              = 0x0B,         // 恢复出厂设置命令
    XYT_DL_RESET                = 0x0C,         // 重启动命令
    XYT_DL_DEFENCE              = 0x10,         // 设防/撤防命令
    XYT_DL_ENGINE               = 0x11,         // 启动/关闭命令
    XYT_DL_SEEK                 = 0x17,         // 寻车信号命令
    XYT_DL_TURNOFF              = 0x18,         // 关机命令
    XYT_DL_UPG                  = 0x20,         // 程序升级准备命令
    XYT_DL_BATT_LOCK            = 0x28,         // 开电池盒锁命令
    XYT_DL_GPS_INTERVAL         = 0x29,         // GPS数据上传时间设置命令
    XYT_DL_LOCK_PARAM           = 0x2B,         // 设置电机锁参数
    XYT_DL_SIM                  = 0x2D,         // SIM卡信息上报
    XYT_DL_STORE_ALM            = 0x40,         // 存储的报警信息上报
    XYT_DL_STORE_BATT           = 0x41,         // 存储的电池状态信息上报
    XYT_DL_DEVICE_ID            = 0x1D,         // 修改设备ID
    XYT_DL_PASSTHROUGH          = 0x2E,         // 文本数据透传命令
    XYT_DL_VOICE_PLAY           = 0x51,         // 远程语音播报
    XYT_DL_VOICE_SYNC           = 0x52,         // 语音数据编号同步响应
    XYT_DL_HTTP_LINK_RSP        = 0x53,         // 文件链接响应
    XYT_DL_VOICE_ADD            = 0x54,         // 增加语音数据
    XYT_DL_VOICE_DEL            = 0x55,         // 删除语音数据
    XYT_DL_UNKNOW
} xyt_downlink_cmd_type;


typedef struct 
{
    uint8           msg_id;                     // 消息ID
    uint16          body_len;                   // 消息体长度
    uint16          serial_id;                  // 消息流水号
    uint8           identify_code[XYT_IDENTIFIER_CODE_LEN]; // 识别码
    uint32          equipment_code;             // 设备编码
    uint8           supplier_code;              // 供应商代码
} xyt_pack_head;

typedef struct
{
    xyt_pack_head   hd;
    uint8         * body;
} xyt_pack_type;


/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
void    track_cust_packet_rabbit_init(void);
uint8   track_cust_packet_rabbit_calc_crc(uint8 * data, uint16 data_len);

void    track_cust_packet_rabbit_8F(void);
void    track_cust_packet_rabbit_81(void);
void    track_cust_packet_rabbit_82(void);
void    track_cust_packet_rabbit_83(void);
void    track_cust_packet_rabbit_8A(void);
void    track_cust_packet_rabbit_8B(void);
void    track_cust_packet_rabbit_8C(void);
void    track_cust_packet_rabbit_90(void);
void    track_cust_packet_rabbit_91(void);
void    track_cust_packet_rabbit_97(void);
void    track_cust_packet_rabbit_98(void);
void    track_cust_packet_rabbit_A0(void);
void    track_cust_packet_rabbit_A8(void);
void    track_cust_packet_rabbit_A9(void);
void    track_cust_packet_rabbit_AB(void);
void    track_cust_packet_rabbit_AD(void);
void    track_cust_packet_rabbit_C0(void);
void    track_cust_packet_rabbit_C1(void);
void    track_cust_packet_rabbit_9D(void);
void    track_cust_packet_rabbit_AE(void);
void    track_cust_packet_rabbit_D1(void);
void    track_cust_packet_rabbit_D2(void);
void    track_cust_packet_rabbit_D3(void);
void    track_cust_packet_rabbit_D4(void);
void    track_cust_packet_rabbit_D5(void);
void    track_cust_packet_rabbit_64(void);
void    track_cust_packet_rabbit_65(void);

#endif /* __NF2318__ */

