/*******************************************************************************************
 * Filename:    track_cust_xyt_uart.h
 * Author :     lgs
 * Date :       2019-12-16
 * Comment:     行运兔控制器,BMS 接口头文件
 ******************************************************************************************/

#if defined(__NF2318__)

/****************************************************************************
* Include Files                         包含头文件
*****************************************************************************/
#include "track_cust.h"


/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#define C_SIGN                          0x10    // 控制器数据标识位
#define B_SIGN                          0x20    // BMS 数据标识位

#define XYT_CONTROL_VER                 0x03    // 协议版本号(该值固定为3)

// 厂商代码
#define MANUFACTURER_JH                 1       // 晶汇
#define MANUFACTURER_GB                 2       // 高标
#define MANUFACTURER_SZ                 3       // 松正
#define MANUFACTURER_HY                 4       // 浩悦
#define MANUFACTURER_OURMETER           5       // ourmeter
#define MANUFACTURER_JF                 6       // 金丰
#define MANUFACTURER_YZ                 7       // 永卓

#define XYT_CONTROLLER_PACK_MIN         6       // 控制器报文最小长度

/*****************************************************************************
 *  Struct                              数据结构定义
 *****************************************************************************/

typedef void (* ctrl_handler_type) (void * data_ptr, uint16 data_len);

typedef struct
{
    uint8               cmd;
    ctrl_handler_type   handler;
} xyt_ctrl_handler_map_type;

typedef struct 
{
    uint8               add;                    // 地址
    uint8               cmd;                    // 命令
    uint8               len;                    // 长度
    uint8               data[255];              // 数据
} xyt_controller_type;

typedef enum
{
    XYT_CMD_ERR             = 0x00,             // 获取最后一次错误代码
    XYT_CMD_INFO            = 0x11,             // 获取控制器信息
    XYT_CMD_SPEED           = 0x12,             // 修改最高时速
    XYT_CMD_VOLT            = 0x13,             // 修改欠压保护值
    XYT_CMD_CURR            = 0x14,             // 修改限流值
    XYT_CMD_LOWSTART        = 0x15,             // 修改是否缓启动
    XYT_CMD_LIGHT           = 0x16,             // 控制大灯开关
    XYT_CMD_ACC             = 0x17,             // 打开ACC
    XYT_CMD_SW              = 0x18,             // 设置控制器的功能开关
    XYT_CMD_FD              = 0x19,             // 防盗开关
    XYT_CMD_UPG_START       = 0x1A,             // 开始升级
    XYT_CMD_UPG_DATA        = 0x1B,             // 发送升级数据
    XYT_CMD_UPG_END         = 0x1C,             // 升级结束
    XYT_CMD_UNKNOW          = 0xFF
} xyt_controller_cmd_type;

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
void track_cust_xyt_uart_read(uint8 * data, uint16 data_len);


#endif /* __NF2318__ */

