/*******************************************************************************************
 * Filename:    track_cust_xyt_protocol.c
 * Author :     lgs
 * Date :       2019-12-16
 * Comment:     行运兔平台协议接口
 ******************************************************************************************/

#if defined(__NF2318__)


/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "track_cust.h"
#include "track_cust_xyt_protocol.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/



/*****************************************************************************
* Local variable				局部变量
*****************************************************************************/



/*****************************************************************************
* Global variable				全部变量
*****************************************************************************/
UINT16  g_rabbit_terminal_serial_number = 0;
UINT8   g_rabbit_identifier_string[XYT_IDENTIFIER_CODE_LEN] = {0};
UINT32  g_rabbit_device_code = 0;   /*设备编码无符号四字节整型*/
UINT8   g_rabbit_supplier_code = 0; /*供应商代码  用户厂家代码编号,1字节*/
UINT8   g_rabbit_recive_buff[2048];

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/


/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/


/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_0F
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  注册命令
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_0F(void * data, uint16 len)
{
    /*
        1   注册状态        BYTE    01 第一次注册
                                    02 已注册（第二次，第三次）
                                    03 非法注册
        1   注册信息长度    BYTE    注册信息长度
        N   注册信息        BYTE[n] 终端提供的注册码（鉴权码流）
        4   注册ID          DWORD   终端注册ID码
    */
    int i = 0;
    uint8 register_status;
    uint8 auth_len;
    uint32 ste_code;
    uint8 * ptr = (uint8 *)data;

    LOGH2(L_APP, L_V5, "", data, len);

    if(data == NULL || len == 0)
    {
        return;
    }

    register_status = ptr[i++];
    auth_len = ptr[i++]; //鉴权码流长度
    if(auth_len > 32)
    {
        LOGD(L_APP, L_V5, "鉴权码过长!");
        return;
    }
    memset(G_parameter.ste_param.auth_code, 0, sizeof(G_parameter.ste_param.auth_code));
    memcpy(G_parameter.ste_param.auth_code, &ptr[i], auth_len);
    G_parameter.ste_param.auth_len = auth_len;
    i += auth_len;
    // 平台下发的注册ID码 应该与设备上行的是一致的,此处保留但不做判断
    ste_code = (uint32)(ptr[  i] << 24)
             | (uint32)(ptr[i+1] << 16)
             | (uint32)(ptr[i+2] <<  8)
             | (uint32)(ptr[i+3] <<  0);

    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);

    if(register_status != 0x03)
    {
        track_cust_packet_rabbit_81();
    }
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_01
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  终端鉴权应答
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_01(void * data, uint16 len)
{
    /*
    
    1   登录状态    BYTE    1、表示允许登录请求
                            2、此设备未注册，需要重新注册
                            3、系统无此设备信息，拒绝登录请求
                            4、其它原因，禁止登录请求 
    6   服务器端时钟 BYTE[N] 终端可根据服务器端时间，调整时钟
                            BYTE[0] 年  2016 =2000+ BYTE[0]
                            BYTE[1] 月
                            BYTE[2] 日
                            BYTE[3] 时
                            BYTE[4] 分
                            BYTE[5] 秒
    */

    int i = 0;
    uint8 auth_status;
    uint8 * ptr = (uint8 *)data;
    applib_time_struct sys_time;
    
    LOGH2(L_APP, L_V5, "", data, len);

    if(data == NULL || len < 7)
    {
        return;
    }
    auth_status = ptr[i++];

    memset(&sys_time, 0, sizeof(applib_time_struct));

    sys_time.nYear  = ptr[i++] + 2000;
    sys_time.nMonth = ptr[i++];
    sys_time.nDay   = ptr[i++];
    sys_time.nHour  = ptr[i++];
    sys_time.nMin   = ptr[i++];
    sys_time.nSec   = ptr[i++];

    if(auth_status == 1)
    {
        // 鉴权成功,登录成功
        tr_stop_timer(TRACK_CUST_NET_LOGIN_TIMEOUT_TIMER_ID);
        tr_stop_timer(TRACK_CUST_NET_LOGIN_RESEND_TIMER_ID);

        track_set_login_status(KAL_TRUE);
    }
    else if(auth_status == 2)
    {
        // 需要重新注册
        track_cust_packet_rabbit_8F();
    }
    else
    {
        LOGD(L_APP, L_V5, "平台拒绝登录,或者禁止登录 err_code[%d]", auth_status);
        return;
    }
    // 同步时间
    track_fun_update_time_to_system(2, &sys_time);
    LOGD(L_APP, L_V5, "服务器日期:%d-%02d-%02d,时间:%02d:%02d:%02d", sys_time.nYear, sys_time.nMonth, sys_time.nDay, sys_time.nHour, sys_time.nMin, sys_time.nSec);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_02
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  GPS应答
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_02(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_03
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  终端基础信息上报/心跳
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_03(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}


/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_0A
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  平台主动请求数据
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_0A(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_0B
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  恢复出厂设置命令
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_0B(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}


/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_0C
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  重启动命令
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_0C(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}


/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_10
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  设防/撤防命令
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_10(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}


/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_11
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  启动/关闭命令
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_11(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_17
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  寻车信号命令
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_17(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_18
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  关机命令
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_18(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_20
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  程序升级准备命令
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_20(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_28
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  开电池盒锁命令
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_28(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_29
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  GPS数据上传时间设置命令
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_29(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_2B
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  设置电机锁参数
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_2B(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_2D
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  SIM卡信息上报应答
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_2D(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_40
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  服务器收到终端数据透传后,对数据进行回复
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_40(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_dl_parse
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  存储的电池状态信息上报的应答
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_41(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_1D
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  修改设备ID
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_1D(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_2E
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  文本数据透传命令的应答
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_2E(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_51
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  远程语音播报
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_51(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_52
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  语音数据编号同步响应
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_52(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_53
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  文件链接响应
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_53(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_54
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  增加语音数据
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_54(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_55
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -  删除语音数据
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_rabbit_55(void * data, uint16 len)
{
    LOGD(L_APP, L_V5, "");
    LOGH2(L_APP, L_V5, "", data, len);
}


/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_dl_parse
 *
 *  Purpose     -  行运兔下行数据解析接口
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_dl_parse(void * data_ptr, uint16 data_len)
{
    /*
    *   消息长度	消息头	 消息体	    校验码
    *   2 Bytes     22 Bytes  n Bytes   1 Byte
    */
    uint16  msg_len = 0;
    uint16 len = data_len;
    xyt_pack_type msg;
    uint8 temp[1024] = {0};
    uint8 cs;

    LOGH2(L_APP, L_V5, "", data_ptr, data_len);

    if(data_ptr == NULL || data_len < XYT_PACKET_MIN_LEN)
    {
        LOGD(L_APP, L_V5, "传入参数错误");
        return;
    }

    memset(&msg, 0, sizeof(xyt_pack_type));

    memcpy(g_rabbit_recive_buff, data_ptr, len);

    while(len > 0)
    {
        msg_len = ((uint16)g_rabbit_recive_buff[0] << 0) & 0x00FF
                | ((uint16)g_rabbit_recive_buff[1] << 8) & 0xFF00;

        if(msg_len > len)
        {
            LOGD(L_APP, L_V5, "%d, 长度错误!解析出的长度与实际长度不一致!", __LINE__);
            break;
        }
        // 注意:此处temp保存的数据为 "消息头+消息体+校验码"
        memcpy(temp, &g_rabbit_recive_buff[2], msg_len);

        cs = track_cust_packet_rabbit_calc_crc(temp, msg_len - 1);
        if(cs == temp[msg_len - 1])
        {
            // 消息头
            msg.hd.msg_id = temp[0];
            msg.hd.body_len = ((uint16)temp[1] << 0) & 0x00FF | ((uint16)temp[2] << 8) & 0xFF00;
            msg.hd.serial_id = ((uint16)temp[3] << 0) & 0x00FF | ((uint16)temp[4] << 8) & 0xFF00;
            memcpy(msg.hd.identify_code, &temp[5], XYT_IDENTIFIER_CODE_LEN);
            msg.hd.equipment_code = ((uint32)temp[17] <<  0) & 0x000000FF
                                  | ((uint32)temp[18] <<  8) & 0x0000FF00
                                  | ((uint32)temp[19] << 16) & 0x00FF0000
                                  | ((uint32)temp[20] << 24) & 0xFF000000;
            msg.hd.supplier_code = temp[21];

            if(msg.hd.body_len > 0)
            {
                // 消息体
                msg.body = (uint8 *)Ram_Alloc(5, msg.hd.body_len);
                if(msg.body != NULL)
                {
                    memcpy(msg.body, &temp[22], msg.hd.body_len);
                }
            }

            switch(msg.hd.msg_id)
            {
                case XYT_DL_REGISTER:           // 注册命令
                    track_cust_packet_rabbit_0F(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_AUTH:               // 终端鉴权
                    track_cust_packet_rabbit_01(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_GPS:                // GPS
                    track_cust_packet_rabbit_02(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_HB:                 // 终端基础信息上报/心跳
                    track_cust_packet_rabbit_03(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_REQUEST:            // 主动请求数据
                    track_cust_packet_rabbit_0A(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_DEFAULT:            // 恢复出厂设置命令
                    track_cust_packet_rabbit_0B(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_RESET:              // 重启动命令
                    track_cust_packet_rabbit_0C(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_DEFENCE:            // 设防/撤防命令
                    track_cust_packet_rabbit_10(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_ENGINE:             // 启动/关闭命令
                    track_cust_packet_rabbit_11(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_SEEK:               // 寻车信号命令
                    track_cust_packet_rabbit_17(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_TURNOFF:            // 关机命令
                    track_cust_packet_rabbit_18(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_UPG:                // 程序升级准备命令
                    track_cust_packet_rabbit_20(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_BATT_LOCK:          // 开电池盒锁命令
                    track_cust_packet_rabbit_28(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_GPS_INTERVAL:       // GPS数据上传时间设置命令
                    track_cust_packet_rabbit_29(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_LOCK_PARAM:         // 设置电机锁参数
                    track_cust_packet_rabbit_2B(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_SIM:                // SIM卡信息上报
                    track_cust_packet_rabbit_2D(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_STORE_ALM:          // 存储的报警信息上报
                    track_cust_packet_rabbit_40(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_STORE_BATT:         // 存储的电池状态信息上报
                    track_cust_packet_rabbit_41(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_DEVICE_ID:          // 修改设备ID
                    track_cust_packet_rabbit_1D(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_PASSTHROUGH:        // 文本数据透传命令
                    track_cust_packet_rabbit_2E(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_VOICE_PLAY:         // 远程语音播报
                    track_cust_packet_rabbit_51(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_VOICE_SYNC:         // 语音数据编号同步响应
                    track_cust_packet_rabbit_52(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_HTTP_LINK_RSP:      // 文件链接响应
                    track_cust_packet_rabbit_53(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_VOICE_ADD:          // 增加语音数据
                    track_cust_packet_rabbit_54(msg.body, msg.hd.body_len);
                    break;

                case XYT_DL_VOICE_DEL:          // 删除语音数据
                    track_cust_packet_rabbit_55(msg.body, msg.hd.body_len);
                    break;

                default:
                    LOGD(L_APP, L_V5, "命令不支持");
                    break;
            }

            if(msg.body != NULL)
            {
                Ram_Free(msg.body);
            }
        }

        len = len - (msg_len + 2);
        memcpy(g_rabbit_recive_buff, &g_rabbit_recive_buff[msg_len + 2], len);
    }
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_calc_crc
 * 
 *  Purpose     -  BCC（异或校验）法
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-13,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
uint8 track_cust_packet_rabbit_calc_crc(uint8 * data, uint16 data_len)
{
    uint8 crc;
    uint16 i = 0;

    if(data == NULL || data_len == 0)
    {
        LOGD(L_APP, L_V3, "参数错误!");
        return 0xFF;
    }

    crc = data[i];
    while(++i < data_len)
    {
        crc ^= data[i];
    }

    return crc;
}


/******************************************************************************
 *  Function    -  track_cust_packet_ul_pack_head
 *
 *  Purpose     -  行运兔消息头组包信息
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-13,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
static void track_cust_packet_ul_pack_head(xyt_uplink_cmd_type cmd, uint8 * out_info, uint16 body_len)
{
    uint8 temp[XYT_PACKET_HEAD_LEN] = {0};
    int pos = 0;

    if(out_info == NULL)
    {
        LOGD(L_APP, L_V5, "传入参数错误");
        return;
    }

    // 命令
    temp[pos++] = cmd;

    // 消息体长度
    temp[pos++] = (uint8)((body_len & 0x00FF) >> 0);
    temp[pos++] = (uint8)((body_len & 0xFF00) >> 8);

    // 流水号
    temp[pos++] = (uint8)((g_rabbit_terminal_serial_number & 0x00FF) >> 0);
    temp[pos++] = (uint8)((g_rabbit_terminal_serial_number & 0xFF00) >> 8);

    // 识别码
    memcpy(&temp[pos], G_importance_parameter_data.identify, XYT_IDENTIFIER_CODE_LEN);
    pos += XYT_IDENTIFIER_CODE_LEN;

    // 注册ID
    temp[pos++] = (uint8)((XYT_STE_CODE & 0xFF000000) >> 24);
    temp[pos++] = (uint8)((XYT_STE_CODE & 0x00FF0000) >> 16);
    temp[pos++] = (uint8)((XYT_STE_CODE & 0x0000FF00) >>  8);
    temp[pos++] = (uint8)((XYT_STE_CODE & 0x000000FF) >>  0);

    // 供应商代码
    temp[pos++] = G_importance_parameter_data.cs_code;

    memcpy(out_info, temp, pos);

    g_rabbit_terminal_serial_number++;
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_8F
 *
 *  Purpose     -  注册命令
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_8F(void)
{
    /*
    1   注册信息长度    BYTE    注册信息长度
    N   注册信息        BYTE[n] 终端提供的注册码
    4   注册ID          DWORD   终端注册ID码(设备编码)
    */
    int main_pos = 2; // 预留两位存放长度
    int body_pos = 0;
    uint8 * code = NULL;
    uint8 main_buff[512] = {0};
    uint8 body_buff[256] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    code = track_drv_get_imei(0);

    // 注册信息长度
    body_buff[body_pos++] = strlen(code);

    // 终端提供的注册码 用IMEI字符替代
    memcpy(&body_buff[body_pos], code, strlen(code));
    body_pos += strlen((char *)code);

    // 终端注册ID码(设备编码)
    body_buff[body_pos++] = (uint8)((XYT_STE_CODE & 0xFF000000) >> 24);
    body_buff[body_pos++] = (uint8)((XYT_STE_CODE & 0x00FF0000) >> 16);
    body_buff[body_pos++] = (uint8)((XYT_STE_CODE & 0x0000FF00) >>  8);
    body_buff[body_pos++] = (uint8)((XYT_STE_CODE & 0x000000FF) >>  0);

    track_cust_packet_ul_pack_head(XYT_UL_REGISTER, head_buff, body_pos);

    memcpy(&main_buff[main_pos], head_buff, XYT_PACKET_HEAD_LEN);
    main_pos += XYT_PACKET_HEAD_LEN;
    memcpy(&main_buff[main_pos], body_buff, body_pos);
    main_pos += body_pos;

    // calculate 校验码
    main_buff[main_pos] = track_cust_packet_rabbit_calc_crc(&main_buff[2], main_pos - 2);
    main_pos += 1;

    // 注意!!! 消息的整体长度，不包括本身两个字节
    main_buff[0] = (uint8)(((main_pos - 2) & 0x00FF) >> 0);
    main_buff[1] = (uint8)(((main_pos - 2) & 0xFF00) >> 8);

    LOGH2(L_APP, L_V5, "", main_buff, main_pos);
    track_soc_write_req(main_buff, main_pos, XYT_UL_REGISTER, 0);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_81
 *
 *  Purpose     -  终端鉴权
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_81(void)
{
    /*
        2   登录流水号      WORD    自增长，由1到65535(如超过65535则再次从1开始)
        1   鉴权码流长度    BYTE    鉴权码流的长度
        N   鉴权码流        BYTE[N] 鉴权码流，通过注册命令获取
        1   蓝牙ID长度      BYTE    蓝牙ID的长度
        N   蓝牙ID          BYTE[N] 蓝牙ID
    */
    uint16 body_pos = 0;
    uint16 main_pos = 2;
    uint8 main_buff[512] = {0};
    uint8 body_buff[256] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};


    // 登录流水号与消息流水号相同, 此次 +1也是为了保持同一报文中的消息流水号与登录流水号一致
    body_buff[body_pos++] = (uint8)((g_rabbit_terminal_serial_number+1 & 0x00FF) >> 0);
    body_buff[body_pos++] = (uint8)((g_rabbit_terminal_serial_number+1 & 0xFF00) >> 8);

    body_buff[body_pos++] = G_parameter.ste_param.auth_len;

    memcpy(&body_buff[body_pos], G_parameter.ste_param.auth_code, G_parameter.ste_param.auth_len);
    body_pos += G_parameter.ste_param.auth_len;

    body_buff[body_pos++] = 17;
    memcpy(&body_buff[body_pos], G_importance_parameter_data.device_id, 17);
    body_pos += 17;
    
    track_cust_packet_ul_pack_head(XYT_UL_AUTH, head_buff, body_pos);

    memcpy(&main_buff[main_pos], head_buff, XYT_PACKET_HEAD_LEN);
    main_pos += XYT_PACKET_HEAD_LEN;
    memcpy(&main_buff[main_pos], body_buff, body_pos);
    main_pos += body_pos;

    // calculate 校验码
    main_buff[main_pos] = track_cust_packet_rabbit_calc_crc(&main_buff[2], main_pos - 2);
    main_pos += 1;

    // 注意!!! 消息的整体长度，不包括本身两个字节
    main_buff[0] = (uint8)(((main_pos - 2) & 0x00FF) >> 0);
    main_buff[1] = (uint8)(((main_pos - 2) & 0xFF00) >> 8);

    LOGH2(L_APP, L_V5, "", main_buff, main_pos);

    track_soc_write_req(main_buff, main_pos, XYT_UL_AUTH, 0);
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_82
 *
 *  Purpose     -  GPS定位信息上传
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_82(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_GPS, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_83
 *
 *  Purpose     -  心跳
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_83(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_HB, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_8A
 *
 *  Purpose     -  主动请求数据
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_8A(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_REQUEST, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_8B
 *
 *  Purpose     -  恢复出厂设置命令执行结果应答
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_8B(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_DEFAULT, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_8C
 *
 *  Purpose     -  重启动命令执行结果应答
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_8C(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_RESET, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_90
 *
 *  Purpose     -  设防/撤防命令执行结果应答
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_90(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_DEFENCE, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_91
 *
 *  Purpose     -  启动/关闭命令执行结果应答
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_91(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_ENGINE, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_97
 *
 *  Purpose     -  寻车信号命令执行结果应答
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_97(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_SEEK, head_buff, body_pos);
    // todo...
    // 发送
}


/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_98
 *
 *  Purpose     -  关机命令执行结果应答
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_98(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_TURNOFF, head_buff, body_pos);
    // todo...
    // 发送
}


/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_A0
 *
 *  Purpose     -  收到 程序升级准备命令执行结果应答
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_A0(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_UPG, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_A8
 *
 *  Purpose     -  开电池盒锁命令执行结果应答
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_A8(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_BATT_LOCK, head_buff, body_pos);
    // todo...
    // 发送
}


/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_A9
 *
 *  Purpose     -  GPS数据上传时间设置命令应答
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_A9(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_GPS_INTERVAL, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_AB
 *
 *  Purpose     -  设置电机锁参数应答
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_AB(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_LOCK_PARAM, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_AD
 *
 *  Purpose     -  SIM卡信息上报
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_AD(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_SIM, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_C0
 *
 *  Purpose     -  存储的报警信息上报
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_C0(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_STORE_ALM, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_C1
 *
 *  Purpose     -  存储的电池状态信息上报
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_C1(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_STORE_BATT, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_9D
 *
 *  Purpose     -  修改设备ID
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_9D(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_DEVICE_ID, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_AE
 *
 *  Purpose     -  文本数据透传命令
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_AE(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_PASSTHROUGH, head_buff, body_pos);
    // todo...
    // 发送
}


/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_D1
 *
 *  Purpose     -  远程语音播报响应
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_D1(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_VOICE_PLAY_RSP, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_D2
 *
 *  Purpose     -  语音数据编号同步请求报文
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_D2(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_VOICE_SYNC, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_D3
 *
 *  Purpose     -  文件链接获取
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_D3(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_GET_HTTP_LINK, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_D4
 *
 *  Purpose     -  增加语音数据
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_D4(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_VOICE_ADD, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_64
 *
 *  Purpose     -  增加语音数据结果上报
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_64(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_VOICE_ADD_RST, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_D5
 *
 *  Purpose     -  删除语音数据
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_D5(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_VOICE_DEL, head_buff, body_pos);
    // todo...
    // 发送
}

/******************************************************************************
 *  Function    -  track_cust_packet_rabbit_65
 *
 *  Purpose     -  删除语音数据结果上报
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-12-19,  lgs  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_packet_rabbit_65(void)
{
    uint16 body_pos = 0;
    uint8 main_buff[512] = {0};
    uint8 head_buff[XYT_PACKET_HEAD_LEN] = {0};

    track_cust_packet_ul_pack_head(XYT_UL_VOICE_DEL_RST, head_buff, body_pos);

    // todo...
    // 发送
}

#endif /* __NF2318__ */

