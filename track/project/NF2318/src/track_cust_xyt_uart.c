/*******************************************************************************************
 * Filename:    track_cust_xyt_uart.c
 * Author :     lgs
 * Date :       2019-12-16
 * Comment:     行运兔控制器,BMS 接口
 ******************************************************************************************/

#if defined(__NF2318__)


/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "track_cust.h"
#include "track_cust_xyt_uart.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
static void xyt_ctrl_handler_err(const uint8 * data, uint16 len);
static void xyt_ctrl_handler_info(const uint8 * data, uint16 len);
static void xyt_ctrl_handler_speed(const uint8 * data, uint16 len);
static void xyt_ctrl_handler_volt(const uint8 * data, uint16 len);
static void xyt_ctrl_handler_curr(const uint8 * data, uint16 len);
static void xyt_ctrl_handler_lowstart(const uint8 * data, uint16 len);
static void xyt_ctrl_handler_light(const uint8 * data, uint16 len);
static void xyt_ctrl_handler_acc(const uint8 * data, uint16 len);
static void xyt_ctrl_handler_sw(const uint8 * data, uint16 len);
static void xyt_ctrl_handler_fd(const uint8 * data, uint16 len);
static void xyt_ctrl_handler_upg_start(const uint8 * data, uint16 len);
static void xyt_ctrl_handler_upg_data(const uint8 * data, uint16 len);
static void xyt_ctrl_handler_end(const uint8 * data, uint16 len);

/*****************************************************************************
* Local variable				        局部变量
*****************************************************************************/
static xyt_ctrl_handler_map_type cmd_handler_map[] = 
{
    { XYT_CMD_ERR,            (ctrl_handler_type)xyt_ctrl_handler_err       }, 
    { XYT_CMD_INFO,           (ctrl_handler_type)xyt_ctrl_handler_info      }, 
    { XYT_CMD_SPEED,          (ctrl_handler_type)xyt_ctrl_handler_speed     },
    { XYT_CMD_VOLT,           (ctrl_handler_type)xyt_ctrl_handler_volt      },
    { XYT_CMD_CURR,           (ctrl_handler_type)xyt_ctrl_handler_curr      },
    { XYT_CMD_LOWSTART,       (ctrl_handler_type)xyt_ctrl_handler_lowstart  },
    { XYT_CMD_LIGHT,          (ctrl_handler_type)xyt_ctrl_handler_light     },
    { XYT_CMD_ACC,            (ctrl_handler_type)xyt_ctrl_handler_acc       },
    { XYT_CMD_SW,             (ctrl_handler_type)xyt_ctrl_handler_sw        },
    { XYT_CMD_FD,             (ctrl_handler_type)xyt_ctrl_handler_fd        },
    { XYT_CMD_UPG_START,      (ctrl_handler_type)xyt_ctrl_handler_upg_start },
    { XYT_CMD_UPG_DATA,       (ctrl_handler_type)xyt_ctrl_handler_upg_data  },
    { XYT_CMD_UPG_END,        (ctrl_handler_type)xyt_ctrl_handler_end       }
};


/*****************************************************************************
* Global variable				        全部变量
*****************************************************************************/


/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/


/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/


/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

/******************************************************************************
 *  Function    -  xyt_ctrl_handler_err
 *
 *  Purpose     -  行运兔控制器接口
 *
 *  Description -  获取最后一次错误代码
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-16,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void xyt_ctrl_handler_err(const uint8 * data, uint16 len)
{
}

/******************************************************************************
 *  Function    -  xyt_ctrl_handler_info
 *
 *  Purpose     -  行运兔控制器接口
 *
 *  Description -  获取控制器信息
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-16,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void xyt_ctrl_handler_info(const uint8 * data, uint16 len)
{
}

/******************************************************************************
 *  Function    -  xyt_ctrl_handler_speed
 *
 *  Purpose     -  行运兔控制器接口
 *
 *  Description -  修改最高时速
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-16,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void xyt_ctrl_handler_speed(const uint8 * data, uint16 len)
{
}

/******************************************************************************
 *  Function    -  xyt_ctrl_handler_volt
 *
 *  Purpose     -  行运兔控制器接口
 *
 *  Description -  修改欠压保护值
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-16,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void xyt_ctrl_handler_volt(const uint8 * data, uint16 len)
{
}

/******************************************************************************
 *  Function    -  xyt_ctrl_handler_curr
 *
 *  Purpose     -  行运兔控制器接口
 *
 *  Description -  修改限流值
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-16,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void xyt_ctrl_handler_curr(const uint8 * data, uint16 len)
{
}

/******************************************************************************
 *  Function    -  xyt_ctrl_handler_lowstart
 *
 *  Purpose     -  行运兔控制器接口
 *
 *  Description -  修改是否缓启动
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-16,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void xyt_ctrl_handler_lowstart(const uint8 * data, uint16 len)
{
}

/******************************************************************************
 *  Function    -  xyt_ctrl_handler_light
 *
 *  Purpose     -  行运兔控制器接口
 *
 *  Description -  控制大灯开关
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-16,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void xyt_ctrl_handler_light(const uint8 * data, uint16 len)
{
}

/******************************************************************************
 *  Function    -  xyt_ctrl_handler_acc
 *
 *  Purpose     -  行运兔控制器接口
 *
 *  Description -  打开ACC
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-16,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void xyt_ctrl_handler_acc(const uint8 * data, uint16 len)
{
}

/******************************************************************************
 *  Function    -  xyt_ctrl_handler_sw
 *
 *  Purpose     -  行运兔控制器接口
 *
 *  Description -  设置控制器的功能开关
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-16,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void xyt_ctrl_handler_sw(const uint8 * data, uint16 len)
{
}

/******************************************************************************
 *  Function    -  xyt_ctrl_handler_fd
 *
 *  Purpose     -  行运兔控制器接口
 *
 *  Description -  防盗开关
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-16,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void xyt_ctrl_handler_fd(const uint8 * data, uint16 len)
{
}

/******************************************************************************
 *  Function    -  xyt_ctrl_handler_upg_start
 *
 *  Purpose     -  行运兔控制器接口
 *
 *  Description -  开始升级
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-16,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void xyt_ctrl_handler_upg_start(const uint8 * data, uint16 len)
{
}

/******************************************************************************
 *  Function    -  xyt_ctrl_handler_upg_data
 *
 *  Purpose     -  行运兔控制器接口
 *
 *  Description -  发送升级数据
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-16,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void xyt_ctrl_handler_upg_data(const uint8 * data, uint16 len)
{
}

/******************************************************************************
 *  Function    -  xyt_ctrl_handler_end
 *
 *  Purpose     -  行运兔控制器接口
 *
 *  Description -  升级结束
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-16,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void xyt_ctrl_handler_end(const uint8 * data, uint16 len)
{
}

/******************************************************************************
 *  Function    -  xyt_ctrl_calc_cs
 *
 *  Purpose     -  行运兔计算校验和
 *
 *  Description -  
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-16,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static uint8 xyt_ctrl_calc_cs(const uint8 * data, uint16 len)
{
    int i = 0;
    uint8 cs = 0;

    if(data == NULL || len == 0)
    {
        LOGD(L_UART, L_V5, "line %d, 参数错误!");
    }

    while(i < len)
    {
        cs += data[i++];
    }

    return cs;
}

/******************************************************************************
 *  Function    -  track_cust_xyt_controller_parse
 *
 *  Purpose     -  行运兔串口接收处理接口
 *
 *  Description -  控制器解析处理函数
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-16,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
#if 1
void track_cust_xyt_controller_parse(uint8 * raw_data, uint16 raw_len)
{
    int i;
    uint8 cs; // 数据长度
    xyt_controller_type ctrl;

    LOGH(L_UART, L_V5, raw_data, raw_len);

    if(raw_data == NULL || raw_len < XYT_CONTROLLER_PACK_MIN)
    {
        LOGD(L_UART, L_V5, "line=%d,数据错误!", __LINE__);
        return;
    }

    memset(&ctrl, 0, sizeof(xyt_controller_type));

    if(raw_data[0] == 0xAA && raw_data[1] == 0x55)
    {
        cs = xyt_ctrl_calc_cs(&raw_data[2], raw_len - 3);
        if(cs != raw_data[raw_len - 1])
        {
            LOGD(L_UART, L_V5, "line=%d,数据错误!", __LINE__);
            LOGH(L_UART, L_V5, raw_data, raw_len);
            return;
        }

        ctrl.add = raw_data[2];
        ctrl.cmd = raw_data[3];
        ctrl.len = raw_data[4];
        if(ctrl.len > 0)
        {
            memcpy(ctrl.data, &raw_data[5], ctrl.len);
        }

        for(i = 0; i < sizeof(cmd_handler_map) / sizeof(cmd_handler_map[0]); i++)
        {
            if(ctrl.cmd == cmd_handler_map[i].cmd)
            {
                cmd_handler_map[i].handler(ctrl.data, ctrl.len);
            }
        }
        if(i == sizeof(cmd_handler_map) / sizeof(cmd_handler_map[0]))
        {
            LOGD(L_UART, L_V5, "指令错误[%02x]", ctrl.cmd);
        }
    }
    else
    {
        LOGD(L_UART, L_V5, "line=%d,控制器报文错误!", __LINE__);
    }
}
#else
void track_cust_xyt_controller_parse(uint8 * raw_data, uint16 raw_len)
{
    /*
        起始符  地址    命令字  数据长度    数据    校验和
        2bytes  1byte   1byte   1byte       N bytes 1byte
    */
    int i, pos = 0;
    int remain_len; // 剩余长度
    int data_len; // 数据长度
    static uint8 buffer[1024] = {0};
    static int buffer_len = 0;
    static bool is_waiting = FALSE; // 等待下次数据标志, 两次数据都不够一个完整包,则放弃
    uint8 temp[1024] = {0};
    uint8 pack[378] = {0};
    int pack_len;
    uint8 cs; // check sum, 校验和
    uint8 calc_cs; // 计算得出的校验和
    xyt_controller_type ctrl;

    if(raw_data == NULL || raw_len == 0)
    {
        return;
    }

    // 垃圾数据满,清空残余垃圾数据
    if(buffer_len + raw_len > sizeof(buffer))
    {
        memset(buffer, 0, sizeof(buffer));
        buffer_len = 0;
    }

    memcpy(&buffer[buffer_len], raw_data, raw_len);
    buffer_len += raw_len;

    // 小于控制器报文的最小长度,表示未收全数据,或者数据被拆分,不解析数据.
    if(buffer_len < XYT_CONTROLLER_PACK_MIN)
    {
        LOGD(L_UART, L_V5, "line=%d, 行运兔控制器数据不完整或者被拆分,等待数据完整!", __LINE__);
        LOGH(L_UART, L_V5, buffer, buffer_len);
        return;
    }

    while(pos < buffer_len)
    {
        // 找到报文头
        if(buffer[pos] == 0xAA && buffer[pos+1] == 0x55)
        {
            remain_len = buffer_len - pos;
            memcpy(temp, &buffer[pos], remain_len);

            // 行运兔控制器数据找到报文头,但长度不对,等待后续接收数据! 数据缓存起来
            if(remain_len < XYT_CONTROLLER_PACK_MIN)
            {
                LOGD(L_UART, L_V5, "line=%d, 行运兔控制器数据找到报文头,但长度不对,等待后续接收数据,退出解析!", __LINE__);
                LOGH(L_UART, L_V5, temp, remain_len);
                memcpy(buffer, temp, remain_len);
                buffer_len = remain_len;
                break; // 跳出循环
            }
            else
            {
                data_len = temp[4]; // 注意temp[4]即为报文中'数据长度'
                // 剩余数据不足数据长度
                if(data_len > remain_len - XYT_CONTROLLER_PACK_MIN)
                {
                    if(!is_waiting)
                    {
                        LOGD(L_UART, L_V5, "line=%d, 行运兔控制器数据找到报文头,但长度不对,等待后续接收数据,退出解析!", __LINE__);
                        LOGH(L_UART, L_V5, temp, remain_len);
                        memcpy(buffer, temp, remain_len);
                        buffer_len = remain_len;
                        is_waiting = TRUE; // 等待下次数据
                        break; // 跳出循环
                    }
                    else
                    {
                        LOGD(L_UART, L_V5, "line=%d, 行运兔控制器数据找到报文头,但两次接收到的数据都不足一个包,跳过该报文头继续扫描!", __LINE__);
                        memcpy(buffer, &temp[2], remain_len - 2);
                        buffer_len = remain_len - 2;
                        pos = 0;
                        is_waiting = FALSE;
                        continue;
                    }
                }
                memcpy(pack, temp, data_len + XYT_CONTROLLER_PACK_MIN);
                pack_len = data_len + XYT_CONTROLLER_PACK_MIN;
                cs = pack[pack_len - 1];
                // 计算校验和为地址,命令字,数据长度和数据的累加和,不考虑进位
                calc_cs = xyt_ctrl_calc_cs(&pack[2], pack_len - 3); // -3 即除去0xAA 0x55 及 报文校验

                // 校验成功
                if(cs == calc_cs)
                {
                    memset(&ctrl, 0, sizeof(xyt_controller_type));
                    ctrl.add = pack[2];
                    ctrl.cmd = pack[3];
                    ctrl.len = pack[4];
                    if(ctrl.len > 0)
                    {
                        memcpy(ctrl.data, &pack[5], ctrl.len); 
                    }

                    for(i = 0; i < sizeof(cmd_handler_map) / sizeof(cmd_handler_map[0]); i++)
                    {
                        if(ctrl.cmd == cmd_handler_map[i].cmd)
                        {
                            cmd_handler_map[i].handler(ctrl.data, ctrl.len);
                        }
                    }
                    if(i == sizeof(cmd_handler_map) / sizeof(cmd_handler_map[0]))
                    {
                        LOGD(L_UART, L_V5, "指令错误[%02x]", ctrl.cmd);
                    }
                    buffer_len = remain_len - pack_len;
                    memcpy(buffer, &temp[pack_len], buffer_len);
                    pos = 0;// 从头扫描
                }
                else
                { // 跳过该报文头继续扫描!
                    memcpy(buffer, &temp[2], remain_len - 2);
                    buffer_len = remain_len - 2;
                    pos = 0;
                    is_waiting = FALSE;
                    continue;
                }
            }
        }

        pos++;
    }
}
#endif

/******************************************************************************
 *  Function    -  track_cust_xyt_uart_read
 *
 *  Purpose     -  行运兔串口接收处理接口
 *
 *  Description -  UART数据接收
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-16,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_xyt_uart_read(uint8 * data, uint16 data_len)
{
    if(data == NULL || data_len == 0)
    {
        return;
    }

    LOGH(L_UART, L_V5, data, data_len);

    track_cust_xyt_controller_parse(data, data_len);
}

#endif /* __NF2318__ */

