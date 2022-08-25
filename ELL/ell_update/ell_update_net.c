/*******************************************************************************************
 *
 * Filename:
 * Author :
 * Date :
 * Comment:
 *
 ******************************************************************************************/

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "ell_update.h"
#include "flash_disk_internal.h"
#include "..\..\track\cust\cust_inc\track_version.h"
//track_version.h
/*****************************************************************************
*  Define                               宏定义
******************************************************************************/
//#define SOC_SOCKET_RECEIVE_DATA_MAX       11264  //接收缓冲区最大长度
#define SOC_SOCKET_SEND_DATA_MAX           4096  //发送缓冲区最大长度
#define SOC_SOCKET_TIMEOUT               130000  //操作超时(毫秒)
#define SOC_SOCKET_RESEND_COUNT               2  //发送数据若没有返回希望收到的数据，重发一遍

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/
typedef enum
{
    SOC_CONN_DISCONNECT,            // 连接断开
    SOC_CONN_FAILURE,               // 连接失败
    SOC_CONN_SUCCESSFUL,            // 连接成功
    SOC_CONN_CONNECTING,            // 正在连接
} track_soc_connstatus_enum;

typedef enum
{
    SOC_SEND_DATA_ERROR             = -2,           // 发送数据错误
    SOC_CONNECT_ERROR               = -1,           // 连接错误
    SOC_IDLE                        = 0,            // 空闲
    SOC_BEGIN_CONNECT               = 1,            // 开始连接
    SOC_CONNECT_SUCCESS             = 2,            // 连接成功
    SOC_CONNECT_ServerNotResponding = 3,            // 服务器无反应
    SOC_SEND_DATA                   = 4,
    SOC_RECV_DATA                   = 5,            // 接收到新的数据
    SOC_RECV_DATA_MayNotBeComplete  = 6,            // 接收到新的数据，由于缓冲区已满，先将可能未完整接受完的数据返回再继续接收
    SOC_CONNECT_CLOSE               = 7,            // 已建立的连接被关闭
    SOC_RECV_HOST_BY_NAME
} track_soc_status_enum;

typedef struct
{
    kal_uint16 nYear;
    kal_uint8 nMonth;
    kal_uint8 nDay;
    kal_uint8 nHour;
    kal_uint8 nMin;
    kal_uint8 nSec;
    kal_uint8 DayIndex; /* 0=Sunday */
} applib_time_struct;

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/
typedef struct
{
    S8                  socket_id;
    sockaddr_struct           server_ip_addr;
    U8                 state;
    Func_Ptr                  funcPtr;
    U32                SendDataCount;
    U8                 SendTheDataBuffer[SOC_SOCKET_SEND_DATA_MAX];
    //U8                 ReceiveTheDataBuffer[SOC_SOCKET_RECEIVE_DATA_MAX];
    S32                 LengthOfTheDataSent;
    S32                 LengthOfTheDataHasBeenSent;
    S32                 LengthOfTheDataReceived;
    S8                  reSend;                      //错误重连次数统计
    U8                 *databak;
    U8                 queue_id;
    U8                 packet_type;
    U8                 batchCount;
    U32                no;
    track_soc_connstatus_enum connStatus;
} ell_soc_socket_struct;

typedef struct
{
    kal_uint8   addr[100];
    kal_uint16  port;      // 十进制
} ell_server_addr_struct;

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
#define REQ_BUFFER_SIZE                   14336
#define ELL_UPDATE_BUF1_SIZE              REQ_BUFFER_SIZE + 2
#define ELL_UPDATE_BUF2_SIZE              REQ_BUFFER_SIZE + 2
#define ELL_UPDATE_BUF3_SIZE              REQ_BUFFER_SIZE + 2
#define ELL_UPDATE_BUF_SURPLUS            (EBUFFERLENGTH - ELL_UPDATE_BUF1_SIZE - ELL_UPDATE_BUF2_SIZE - ELL_UPDATE_BUF3_SIZE)

extern char ell_ram_buf[EBUFFERLENGTH];
static U8 *g_buf1         = ell_ram_buf;
static U8 *g_buf2         = ell_ram_buf + ELL_UPDATE_BUF1_SIZE;
static U8 *g_buf_soc_recv = ell_ram_buf + ELL_UPDATE_BUF1_SIZE + ELL_UPDATE_BUF2_SIZE;
static U8 *g_buf_surplus  = ell_ram_buf + ELL_UPDATE_BUF1_SIZE + ELL_UPDATE_BUF2_SIZE + ELL_UPDATE_BUF3_SIZE;

static ell_soc_socket_struct soc_status = {0};
static kal_bool md5_check_file_flag = KAL_FALSE, ell_check_file_flag = KAL_FALSE;

static char     hostname_req[100] = {0};
static int      ReConCount = 0;
static U32      start_time_tick = 0;
static kal_bool flag_value = KAL_FALSE;
static U8       ell_file_md5[16] = {0};
static U8       reference_md5[16] = {0};
static kal_bool finish = KAL_FALSE;

static U16 req_size = 0, recv_size = 0;
static U32 file_size = 0, file_offset = 0, file_flag = 0;
static U8  file_flag_old = 0;
static U16 file_crc = 0;
static U8  file_md5[16] = {0};
static U8  file_check_type = 0;

static U8  g_recved_data = 0;

/* */
static soc_dns_a_struct entry_ip[SOC_MAX_A_ENTRY];
static U8               entry_num_ip = 0;
static U8               entry_index  = 0;

static kal_int32  retry = 0;
static nvram_check_ota_struct g_ell_otacheck = {0};


const static char *error_msg[] =
{
    "",
    "成功",
    "CRC校验失败",
    "包长度错误",
    "包类型错误",
    "文件类型错误",
    "IMEI无效",
    "芯片ID无效",
    "芯片ID与IMEI不匹配",
    "软件版本号无效",
    "文件识别码错误",
    "数据包长度错误",
    "请求文件开始位置错误",
    "未登录发送请求文件",
    "未登录发送分割文件请求",
    "未发送请求文件发送分割文件请求",
    "数据包错误",
    "服务器繁忙",
    "服务器文件过期"
};

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern void ell_reset(void *arg);
extern U8 *ell_get_imei(U8 par);
extern char *ell_domain_decode(U8 *data);
extern int ell_erase_data(char *type);
extern int ell_data_write_to_file(char *file_path, U8 *data, U32 len);
extern ell_nvram_data_struct *ell_get_datadisk(void);

/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/
static void ell_socket_event(S8 mode);
static void ell_socket_connect();
void ell_update_begin(ell_server_addr_struct *server);
void ell_split_update(kal_bool isWrite, U8 *data, int filesize);

#if defined(Functions)
#endif /* Functions */

/******************************************************************************
 *  Function    -  socket_write_delay
 *
 *  Purpose     -  SOCKET发送数据成功送出
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void socket_write_delay(void)
{
    ell_stop_timer(ELL_SOC_TIMEOUT_TIMER_ID);
    ell_socket_event(SOC_SEND_DATA);
}

static S8 ell_soc_close_ex(S8 s)
{
    EllLog("%d", s);
    soc_shutdown(s, 2);
    return soc_close(s);
}

static void ell_restart_system(U32 arg)
{
    ell_stop_timer(ELL_SOC_TIMEOUT_TIMER_ID);
    ell_stop_timer(ELL_SOC_SEND_OVER_TIMER_ID);
    ell_stop_timer(TRACK_CUST_SERVER2_RESEND_TIMER);
    ell_stop_timer(ELL_SEND_DATA_OVERTIME_TIMER_ID);
    ell_stop_timer(ELL_SOC_CONN_TIMEOUT_TIMER_ID);
    ell_soc_close_ex(soc_status.socket_id - 1);
    ell_start_timer_ext(ELL_SERVER_OVERTIME_TIMER_ID, 3000, ell_reset, (U32)arg);
}

/******************************************************************************
 *  Function    -  ell_socket_get_send_success_count
 *
 *  Purpose     -  返回SOCKET底层Buffer数据发送情况
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static U32 ell_socket_get_send_success_count(void)
{
    static kal_uint64 soc_acked_data2 = 0;
    U32 count;
    S8 ret;

    if(soc_status.connStatus != SOC_CONN_SUCCESSFUL)
    {
        EllLog("connStatus:%d", soc_status.connStatus);
        return 0;
    }
    ret = soc_getsockopt(soc_status.socket_id - 1, SOC_TCP_ACKED_DATA, (void *)&soc_acked_data2, sizeof(kal_uint64));
    EllLog("ret:%d, socket_id:%d", ret, soc_status.socket_id);
    if(SOC_SUCCESS != ret)
    {
        //fail to get acked data
        EllLog("ACK Error:%d", ret);
        return 0;
    }
    count = soc_acked_data2;
    return count;
}

/******************************************************************************
 *  Function    -  ell_socket_send_data_ReCount
 *
 *  Purpose     -  根据Buffer发送情况处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void ell_socket_send_data_ReCount(void* arg)
{
    static int count = 0;
    U32 len;
    U32 par = (U32)arg;
    if(par == 1)
    {
        count = 0;
    }
    else
    {
        count++;
    }
    ell_stop_timer(ELL_SOC_SEND_OVER_TIMER_ID);
    if(count < 225)
    {
        len = ell_socket_get_send_success_count();
        EllLog("count=%d, len:%d-%d ? %d", count, len, soc_status.SendDataCount, soc_status.LengthOfTheDataSent);
        if(len - soc_status.SendDataCount >= soc_status.LengthOfTheDataSent)
        {
            EllLog("count=%d", count);
            soc_status.SendDataCount = len;
            socket_write_delay();
        }
        else
        {
            ell_start_timer_ext(ELL_SOC_SEND_OVER_TIMER_ID, 400, ell_socket_send_data_ReCount, (void*)2);
        }
    }
    else
    {
        EllLog("ERROR!!!");
    }
}

/******************************************************************************
 *  Function    -  ell_socket_GetId
 *
 *  Purpose     -  创建新的SOCKET连接，并返回ID
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static S8 ell_socket_GetId(socket_type_enum socket_type)
{
    S8 id, result;
    U8 val;

    id = soc_create(SOC_PF_INET, socket_type, 0, MOD_MMI, ell_get_vs_account_id());
    EllLog("socket id=%d", id);
    if(id < 0)
    {
        return -1;
    }
    else
    {
        val = SOC_WRITE | SOC_READ | SOC_CONNECT | SOC_CLOSE;
        result = soc_setsockopt(id, SOC_ASYNC, &val, sizeof(val));
        if(0 > result)
        {
            ell_soc_close_ex(id);
            return -3;
        }

        val = 1;
        result = soc_setsockopt(id, SOC_NBIO, &val, sizeof(val));
        if(0 > result)
        {
            ell_soc_close_ex(id);
            return -2;
        }
        return id;
    }
}

/******************************************************************************
 *  Function    -  ell_socket_reconnect
 *
 *  Purpose     -  Socket重连处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void ell_socket_reconnect(void *arg)
{
    static S8 mode = 1;
    int i;
    S8 ret;
    EllLog("%d", (U32)arg);
    if(soc_status.socket_id > 0)
    {
        ret = ell_soc_close_ex(soc_status.socket_id - 1);
        soc_status.socket_id = 0;
        EllLog("soc_close %d, ret=%d", soc_status.socket_id - 1, ret);
    }
    if(ell_get_data_parameter()->server != NULL)
    {
        ell_update_begin(NULL);
    }
    else
    {
        for(i=0; i<entry_num_ip; i++)
        {
            EllLog("域名解析[%d] (%d.%d.%d.%d)", i,
                entry_ip[i].address[0],
                entry_ip[i].address[1],
                entry_ip[i].address[2],
                entry_ip[i].address[3]);
        }
        if(entry_index < entry_num_ip)
        {
            memcpy(soc_status.server_ip_addr.addr, entry_ip[entry_index++].address, 4);
            ret = KAL_TRUE;
            if(soc_status.socket_id == 0)
            {
                ret = ell_socket_GetId(SOC_SOCK_STREAM);
                if(ret < 0)
                {
                    EllLog("error ret = %d", ret);
                    return;
                }
                soc_status.socket_id = ret + 1;
            }
            ell_socket_connect();
        }
        else
        {
            ell_update_begin(NULL);
        }
    }
}

static void ell_socket_reconnect_fun()
{
    soc_status.reSend++;
    EllLog("%d", soc_status.reSend);
    if(soc_status.reSend > 20) //失败重连，不能无限制的重连
    {
        soc_status.reSend = 21;
        ell_socket_event(-4);
        ell_start_timer_ext(ELL_SERVER_OVERTIME_TIMER_ID, 10000, ell_reset, (U32)4);
        return;
    }
    ell_start_timer_ext(ELL_SERVER_OVERTIME_TIMER_ID, 10000, ell_socket_reconnect, (void*)1);
}

/******************************************************************************
 *  Function    -  ell_socket_write
 *
 *  Purpose     -  Socket写入数据
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void ell_socket_write(void)
{
    S32 ret;
    ell_start_timer_ext(ELL_SOC_TIMEOUT_TIMER_ID, SOC_SOCKET_TIMEOUT, ell_socket_reconnect_fun, NULL);
    if(soc_status.socket_id <= 0)
    {
        EllLog("ERROR!");
        return;
    }
    ret = soc_send(soc_status.socket_id - 1, soc_status.SendTheDataBuffer + soc_status.LengthOfTheDataHasBeenSent, soc_status.LengthOfTheDataSent - soc_status.LengthOfTheDataHasBeenSent, 0);
    EllLog("ret=%d LengthOfTheDataHasBeenSent=%d,%d", ret, soc_status.LengthOfTheDataHasBeenSent, soc_status.LengthOfTheDataSent);
    if(ret >= 0)
    {
        soc_status.LengthOfTheDataHasBeenSent += ret;
        if(soc_status.LengthOfTheDataHasBeenSent >= soc_status.LengthOfTheDataSent)
        {
#if 1
            //服务器没有响应HTTP请求，重发请求
            U32 len;
            len = ell_socket_get_send_success_count();
            //ell_start_timer_ext(ELL_SOC_TIMEOUT_TIMER_ID, SOC_SOCKET_TIMEOUT, socket_send_data_timeOut, NULL);
            EllLog("len:%d, %d, %d", len, soc_status.SendDataCount, soc_status.LengthOfTheDataSent);
            if(len - soc_status.SendDataCount >= soc_status.LengthOfTheDataSent)
            {
                soc_status.SendDataCount = len;
                socket_write_delay();
            }
            else
            {
                ell_start_timer_ext(ELL_SOC_SEND_OVER_TIMER_ID, 200, ell_socket_send_data_ReCount, (void*)1);
            }
#else
            soc_status.SendDataCount = ret;
            ell_start_timer(ELL_SOCKET_SEND_TIMER_ID, 200, socket_write_delay);
#endif /* 0 */
        }
        else
        {
            ell_start_timer(ELL_SOCKET_SEND_TIMER_ID, 1000, ell_socket_write);
            //ell_socket_write();
        }
    }
    else if(SOC_WOULDBLOCK == ret)
    {
        ret = 0;
    }
    else
    {
        //ell_stop_timer(ELL_SOC_TIMEOUT_TIMER_ID);
        soc_status.state &= 0xFB;
    }
}

/******************************************************************************
 *  Function    -  ell_socket_read
 *
 *  Purpose     -  Socket读取数据
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void ell_socket_read()
{
    S32 ret, size;

    if(soc_status.socket_id <= 0)
    {
        EllLog("ERROR!");
        return;
    }
    size = REQ_BUFFER_SIZE - soc_status.LengthOfTheDataReceived;
    ret = soc_recv(soc_status.socket_id - 1, g_buf_soc_recv + soc_status.LengthOfTheDataReceived, size, 0);
    EllLog("ret=%d, LengthOfTheDataReceived=%d, size=%d", ret, soc_status.LengthOfTheDataReceived, size);
    if(ret > 0)
    {
        //EllHex(g_buf_soc_recv + soc_status.LengthOfTheDataReceived, ret);
        soc_status.LengthOfTheDataReceived += ret;
        if(soc_status.LengthOfTheDataReceived == REQ_BUFFER_SIZE)
        {
            // 缓冲区已满，先把已收到的数据返回
            ell_socket_event(SOC_RECV_DATA);
            ell_socket_read();
        }
        else if(soc_status.LengthOfTheDataReceived > REQ_BUFFER_SIZE)
        {
            ell_socket_event(-3);
            EllLog("error 1");
        }
        else
        {
            //这里需不需要用定时器回调?
            ell_socket_read();
        }
    }
    else if(ret == SOC_WOULDBLOCK || ret == 0)
    {
        //需要留意，当前这种处理办法会不会导致需要主动断开时出现问题
        ell_stop_timer(ELL_SOC_TIMEOUT_TIMER_ID);
        ell_socket_event(SOC_RECV_DATA);
    }
    else if(ret == SOC_PIPE)
    {
        ell_stop_timer(ELL_SOC_TIMEOUT_TIMER_ID);
        EllLog("error 2 连接通道已经关闭，不能接收数据!");
        ell_socket_event(-6); // 准备接收数据是，探测到已建立的连接已经断开，此时可能服务器下发的数据初始丢失的情况
    }
    else
    {
        ell_stop_timer(ELL_SOC_TIMEOUT_TIMER_ID);
        EllLog("error 3");
        ell_socket_event(-5);
    }
}

/******************************************************************************
 *  Function    -  ell_socket_connect
 *
 *  Purpose     -  SOCKET连接处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void ell_socket_connect()
{
    S8 ret;

    EllLog("socket_id:%d, addr:%d.%d.%d.%d:%d", soc_status.socket_id - 1,
           soc_status.server_ip_addr.addr[0],
           soc_status.server_ip_addr.addr[1],
           soc_status.server_ip_addr.addr[2],
           soc_status.server_ip_addr.addr[3],
           soc_status.server_ip_addr.port);
    ell_start_timer_ext(ELL_SOC_TIMEOUT_TIMER_ID, SOC_SOCKET_TIMEOUT, ell_socket_reconnect_fun, NULL);
    if(soc_status.socket_id <= 0)
    {
        EllLog("ERROR!");
        return;
    }
    ret = soc_connect(soc_status.socket_id - 1, &soc_status.server_ip_addr);
    EllLog("ret=%d", ret);
    switch(ret)
    {
        case SOC_SUCCESS:
            {
                ell_stop_timer(ELL_SOC_TIMEOUT_TIMER_ID);
                ell_socket_event(SOC_CONNECT_SUCCESS);
                break;
            }
        case SOC_WOULDBLOCK:
            {
                break;
            }
        default:
            {
                //ell_stop_timer(ELL_SOC_TIMEOUT_TIMER_ID);
                break;
            }
    }
}

static void ell_soc_write_req(U8* data, int len)
{
    EllHex(data, len);
    EllLog("%d", len);
    soc_status.LengthOfTheDataHasBeenSent = 0;
    soc_status.LengthOfTheDataSent = len;
    memcpy(soc_status.SendTheDataBuffer, data, soc_status.LengthOfTheDataSent);
    ell_socket_write();
}

S8 ell_soc_gethostbyname(char *hostname, U16 port)
{
    static U8 ip_from_hostname[4] = {0};
    S8 ret;
    U8 addr_len;
    U8 len = 0;

    soc_status.state |= 1;
    strncpy(hostname_req, hostname, 99);
    hostname_req[99] = 0;
    ret = soc_gethostbyname(
              KAL_FALSE,
              MOD_MMI,
              100,
              (kal_char*) hostname_req,
              ip_from_hostname,
              &len,
              0,
              ell_get_vs_account_id());

    EllLog("ret=%d, hostname_req=%s, account_id=%d", ret, hostname_req, ell_get_vs_account_id());
    if(ret == SOC_SUCCESS)
    {
        EllLog("%s -> %d.%d.%d.%d",
               (char*)hostname,
               ip_from_hostname[0],
               ip_from_hostname[1],
               ip_from_hostname[2],
               ip_from_hostname[3]);
        soc_status.state &= 0xFE;
        memcpy(soc_status.server_ip_addr.addr, ip_from_hostname, 4);
        soc_status.server_ip_addr.port = port;
        ell_socket_connect();
    }
    else if(ret == SOC_WOULDBLOCK)
    {
        /* waits for APP_SOC_GET_HOST_BY_NAME_IND */
    }
    else
    {
        EllLog("Error 2! ret=%d", ret);
        soc_status.state &= 0xFE;
    }
    return 0;
}

/******************************************************************************
 *  Function    -  ell_getSerialNumber
 *
 *  Purpose     -  取得流水号
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static U16 ell_getSerialNumber()
{
    static U16 g_SerialNumber = 0;
    return g_SerialNumber++;
}

/******************************************************************************
 *  Function    -  ell_DataPacketEncode78
 *
 *  Purpose     -  78协议打包
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 09-10-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static U16 ell_DataPacketEncode78(U8 cmd, U8 *sendData, U8 len)
{
    U16 tmp, tmp1;

    //起始位
    sendData[0] = 0x78;
    sendData[1] = 0x78;

    //长度
    sendData[2] = len - 5;

    //协议号
    sendData[3] = cmd;

    //信息序列号
    tmp = ell_getSerialNumber();
    sendData[len - 6] = (tmp & 0xFF00) >> 8;
    sendData[len - 5] = (tmp & 0x00FF);
    EllLog("SerialNumber:%.2X%.2X", sendData[len - 6], sendData[len - 5]);

    //CRC校验
    tmp1 = ell_GetCrc16(&sendData[2], len - 6);
    sendData[len - 4] = (tmp1 & 0xFF00) >> 8;
    sendData[len - 3] = (tmp1 & 0x00FF);

    //结束
    sendData[len - 2] = '\r';
    sendData[len - 1] = '\n';

    return tmp;
}

/******************************************************************************
 *  Function    -  DataPacking
 *
 *  Purpose     -  79协议打包
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 07-03-2012,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static U16 ell_DataPacketEncode79(U8 cmd, U8 *sendData, U16 len)
{
    U16 tmp;

    //起始位
    sendData[0] = 0x79;
    sendData[1] = 0x79;

    //长度
    sendData[2] = ((len - 6) & 0xFF00) >> 8;
    sendData[3] = ((len - 6) & 0x00FF);

    //协议号
    sendData[4] = cmd;

    //信息序列号
    tmp = ell_getSerialNumber();
    sendData[len - 6] = (tmp & 0xFF00) >> 8;
    sendData[len - 5] = (tmp & 0x00FF);
    EllLog("SerialNumber:%.2X%.2X", sendData[len - 6], sendData[len - 5]);

    //CRC校验
    tmp = ell_GetCrc16(&sendData[2], len - 6);
    sendData[len - 4] = (tmp & 0xFF00) >> 8;
    sendData[len - 3] = (tmp & 0x00FF);

    //结束
    sendData[len - 2] = '\r';
    sendData[len - 1] = '\n';

    return tmp;
}

char *ell_get_base_version(void)
{
    return (char*)_TRACK_VER_BASE_;
}

static S8 ell_paket_FD(U8 *data, U16 len)
{
    U8 sendData[300] = {0}, i = 5;
    int size, ret;
    size = 11 + 8/*imei*/ + 2/*ext data len*/ + len/*ext data*/;
    EllLog("len:%d, %d", len, size);

    // imei
    memcpy(&sendData[i], ell_get_imei(1), 8);
    i += 8;

    /* 透传数据的长度 */
    sendData[i++] = (len & 0xFF00) >> 8;
    sendData[i++] = (len & 0x00FF);

    /* 填充需要透传的数据 */
    memcpy(&sendData[i], data, len);

    ell_DataPacketEncode79(0xFD, sendData, size);
    ell_soc_write_req(sendData, size);
    ell_start_timer_ext(ELL_SEND_DATA_OVERTIME_TIMER_ID, 30000, ell_socket_reconnect, (void*)2);
    return ret;
}

static S8 ell_paket_driver_message(void)
{
    int i = 0, ver_str_len;
    U8 buf[200] = {0};
    char ver_string[200] = {0};
    U8 chip_rid[128] = {0};
    
    //1，OTA    2，OBD    3，软件基础版本
    //ver_str_len = snprintf(ver_string, 199, "{t:'3',v:'[BASE]%s [BUILD]%s'}", ell_get_base_version(), build_date_time());
    ver_str_len = snprintf(ver_string, 199, "{t:'3',v:'%s'}", ell_get_base_version());
    EllLog("%s", ver_string);

    // packet type
    buf[i++] = 0;

    // Chip ID
    SST_Get_ChipRID(chip_rid, 128);
    memcpy(&buf[i], chip_rid, 16);
    i += 16;

    // version string length
    buf[i++] = ver_str_len;

    // version string
    memcpy(&buf[i], ver_string, ver_str_len);
    i += ver_str_len;

    ell_paket_FD(buf, i);
}

static S8 ell_send_file_content(U32 data_type, U32 data_req_begin, U16 data_req_len)
{
    U8 sendData[12] = {0};
    int size;
    U8 i = 0;

    EllLog("data_type:%d, data_req_begin:%d, data_req_len:%d", data_type, data_req_begin, data_req_len);
    size = 2/*packet type*/ + 4/*data_type*/ + 4/*data_req_begin*/ + 2/*data_req_len*/;

    // packet type
    sendData[i++] = 2;
    sendData[i++] = 3;

    // data_type
    memcpy(&sendData[i], &data_type, 4);
    i += 4;

    // data_req_begin
    sendData[i++] = (data_req_begin & 0xFF000000) >> 24;
    sendData[i++] = (data_req_begin & 0x00FF0000) >> 16;
    sendData[i++] = (data_req_begin & 0x0000FF00) >> 8;
    sendData[i++] = (data_req_begin & 0x000000FF);

    // data_req_len
    sendData[i++] = (data_req_len & 0xFF00) >> 8;
    sendData[i++] = (data_req_len & 0x00FF);

    ell_paket_FD(sendData, size);
    return 0;
}

static void ell_resend_FD_04(void)
{
    EllLog( "file_offset:%d, file_size:%d", file_offset, file_size);
    if((file_offset - 1) < file_size)
    {
        if((file_offset - 1) + REQ_BUFFER_SIZE > file_size)
        {
            req_size = file_size - file_offset + 1;
        }
        else
        {
            req_size = REQ_BUFFER_SIZE;
        }
        EllLog( "retry:%d, file_size:%d, file_offset:%d, req_size:%d", retry, file_size, file_offset, req_size);
        if(retry < 5)
        {
            ell_send_file_content(file_flag, file_offset, req_size);
            retry++;
            ell_start_timer(TRACK_CUST_SERVER2_RESEND_TIMER, 30000, ell_resend_FD_04);
        }
        else
        {
            ell_soc_close_ex(soc_status.socket_id - 1);
        }
    }
}

static void ell_recv_file_head(U8 *data, U16 len)
{
    U32 _file_size = 0, _file_flag = 0;
    U16 _file_crc = 0;
    U8  _file_md5[16] = {0};
    U8  _file_check_type = 0;
    int i=3, ret;
    EllLog("file_flag_old:%d, file_flag:%X", file_flag_old, file_flag);
    
    memcpy(&_file_flag, &data[3], 4);            // 文件标识
    //_file_size = data[7];                        // 文件长度
    //_file_size = (_file_size << 8) + data[8];
    //_file_size = (_file_size << 8) + data[9];
    //_file_size = (_file_size << 8) + data[10];
    _file_size = (data[7] << 24) + (data[8] << 16) + (data[9] << 8) + (data[10]);
    // 全文件校验位
    _file_check_type = data[11];
    if(_file_check_type == 0)
    {
        _file_crc = data[12];
        _file_crc = (_file_crc << 8) + data[13];
    }
    else if(_file_check_type == 1)
    {
        memcpy(_file_md5, &data[12], 16);
    }

    if(file_flag_old && _file_size == file_size
        && _file_flag == file_flag
        && _file_crc == file_crc
        && !memcmp(_file_md5, file_md5, 16))
    {
        /* 断点续传 */
    }
    else
    {
        kal_int32 ret = 0;
        /* 重新接收 */
        file_size = _file_size;
        file_flag = _file_flag;
        file_crc = _file_crc;
        file_check_type = _file_check_type;
        memcpy(file_md5, _file_md5, 16);

        ret = ell_get_data_from_file(FOTA_MD5_FILE_PATH, ell_file_md5, 16);
        EllLog("ell_get_data_from_file FOTA_MD5_FILE_PATH %d", ret);
        if(!memcmp(ell_file_md5, file_md5, 16))
        {
            EllLog("与当前FAT中的FOTA MD5文件记录的信息相同, 忽略本次升级 %s ret:%d", FOTA_MD5_FILE_PATH, ret);
            EllHex(ell_file_md5, 16);
            finish = KAL_TRUE;
            ell_soc_close_ex(soc_status.socket_id - 1);
            ell_stop_timer(TRACK_CUST_SERVER2_RESEND_TIMER);
            return;
        }
        else
        {
            EllHex(ell_file_md5, 16);
            EllHex(file_md5, 16);
        }
        EllLog( "file_size:%d, file_check_type:%d", file_size, file_check_type);
        recv_size = 0;
        file_offset = 1;
    }
    retry = 0;
    start_time_tick = kal_get_systicks();
    ell_resend_FD_04();
    EllLog("9");
}

static void ell_recv_file_content(U8 *data, U16 len)
{
    U16 recv_len = 0, i = 3;
    U32 recv_begin = 0;
    int ret;
    U8 *buf = (U8 *)g_buf_surplus;
    
    if(memcmp(&file_flag, &data[i], 4))
    {
        EllLog("ERROR:返回的文件标识与请求的不一致");
        EllHex(&file_flag, 4);
        EllHex(&data[3], 4);
        return;
    }
    i += 4;
    recv_begin = (data[i] << 24) + (data[i+1] << 16) + (data[i+2] << 8) + (data[i+3]);
    i += 4;
    if(recv_begin != file_offset)
    {
        EllLog("ERROR:服务器返回的数据起始位与请求的不一致 %d,%d", recv_begin, file_offset);
        return;
    }
    recv_len = data[i++];
    recv_len = (recv_len << 8) + data[i++];
    if(recv_len + 15 != len)
    {
        EllLog("ERROR:返回的数据包大小与实际不符%d,%d", recv_len, len);
        return;
    }
    recv_size += recv_len;
    memcpy(&buf[file_offset - 1], &data[i++], recv_len);
    file_offset += recv_len;
    if(file_size > (file_offset - 1))
    {
        file_flag_old = 1;
        if(req_size != recv_size)
        {
            EllLog("Warning: 实际接收的数据大小与请求的不一致(file_offset:%d,req_size:%d,recv_size:%d,recv_len:%d)", file_offset , req_size, recv_size, recv_len);
        }
        else
        {
            retry = 0;
            recv_size = 0;
            ell_resend_FD_04();
        }
    }
    else
    {
        ell_stop_timer(TRACK_CUST_SERVER2_RESEND_TIMER);
        EllLog( "全部接收完毕 耗时%d秒", kal_ticks_to_milli_secs(kal_get_systicks() - start_time_tick) / 1000);
        recv_size = 0;
        file_flag = 0;
        file_offset = 1;
        file_flag = 0;
        file_flag_old = 0;
        //track_epo_write_file(buf, file_size);
        if(file_check_type == 0 && !ell_IsDataCrc16ext(buf, file_size, file_crc))
        {
            EllLog( "file crc error");
        }
        else if(file_check_type == 1 && !ell_IsDataMd5ext(buf, file_size, file_md5))
        {
            EllLog( "file md5 error");
        }
        else
        {
            ell_split_update(KAL_FALSE, buf, file_size);
            /* // OTA
                WCHAR FilePath[60] = {0}, FilePath_tmp[60] = {0};
                OTA_kal_wsprintf(FilePath, "%s", OBD_FILE_PATH);
                ret = OTA_FS_Delete(FilePath);
                EllLog( "Del %s %d", OBD_FILE_PATH, ret);
                ret = track_write_file(OTA_FILE_PATH_TMP, buf, file_size);
                EllLog( "Recv OTA file check ok, write file %d", 
                    ret);
                if(ret > 0)
                {
                    OTA_kal_wsprintf(FilePath, "%s", OTA_FILE_PATH);
                    OTA_kal_wsprintf(FilePath_tmp, "%s", OTA_FILE_PATH_TMP);
                    ret = OTA_FS_Delete(FilePath);
                    EllLog( "Del %s %d", OTA_FILE_PATH, ret);
                    ret = OTA_FS_Rename(FilePath_tmp, FilePath);
                    EllLog( "Rename %s->%s %d", "test.tmp", OTA_FILE_PATH, ret);
                    ell_save_md5_to_file(file_md5);
                    track_cust_restart(2, 20);
                }
                else
                {
                    OTA_kal_wsprintf(FilePath_tmp, "%s", OTA_FILE_PATH_TMP);
                    ret = OTA_FS_Delete(FilePath_tmp);
                    EllLog( "Del %s %d", OTA_FILE_PATH_TMP, ret);
                }
            */
        }
        ell_restart_system(5);
    }
}

static void ell_recv_login(U8 *data, U16 len)
{
    // 这里后期最好限定返回错误类型
    if(data[1] != 1)
    {
        /* 服务器返回登陆失败 */
        EllLog("login error %d", data[1]);
        ell_restart_system(6);
        return;
    }
    
    if(data[14] == 1)  // 0x01 为该终端OTA更新  0x02 为终端有OBD模块更新
    {
        U8 buf[2] = {0x02, 0x01};
        EllLog("OTA 有更新升级提供");
        ell_paket_FD(buf, 2);
        return;
    }
    else if(data[14] == 2)
    {
        EllLog("OBD 有更新升级提供");
    }
    else
    {
        EllLog("OTA/OBD 都无需升级");
    }
    ell_restart_system(7);
}

void ell_file_transport_decode_packet(U8 *data, U16 len)
{
    U8 packet_type, i = 0, req_result, queue;

    if(len < 200) EllHex(data, len);
    packet_type = data[i++];
    retry = 0;
    if(ell_is_timer_run(ELL_SEND_DATA_OVERTIME_TIMER_ID))
        ell_start_timer_ext(ELL_SEND_DATA_OVERTIME_TIMER_ID, 30000, ell_socket_reconnect, (void*)2);
    EllLog("packet_type:%d", packet_type);
    if(packet_type == 0) /* 登陆反馈 */
    {
        EllLog("收到数据0 retry:%d len:%d packet_type:%d, req_result:%d,%d",
             retry, len, packet_type, (U8)data[i + 1], (U8)data[i + 2]);
        ell_recv_login(data, len);
    }
    else if(packet_type == 1 || packet_type == 2) /* 文件接收过程 */
    {
        queue = data[i++];
        req_result = data[i++];
        if(queue == 2)  /* 文件信息头 */
        {
            EllLog( "收到数据1 retry:%d len:%d packet_type:%d, req_result:%d,%d, file_offset=%d, file_size=%d",
                 retry, len, packet_type, (U8)data[i + 1], (U8)data[i + 2], file_offset, file_size);
            if(req_result != 1)
            {
                /* 服务器返回错误 */
                EllLog( "recv error %d %s", req_result, error_msg[req_result]);
                return;
            }
            ell_recv_file_head(data, len);
            EllLog("ell_recv_file_head end");
        }
        else if(queue == 4)  /* 文件内容 */
        {
            if(req_result != 1)
            {
                /* 服务器返回错误 */
                EllLog( "recv error %d", req_result);
                return;
            }
            EllLog( "收到数据2 retry:%d len:%d packet_type:%d, req_result:%d,%d, file_offset=%d, file_size=%d  %d%%",
                 retry, len, packet_type, (U8)data[i + 1], (U8)data[i + 2], file_offset, file_size, file_offset*100/(file_size+1));
            ell_recv_file_content(data, len);
        }
    }
}

/******************************************************************************
 *  Function    -  track_cust_recv_net_cmd
 *
 *  Purpose     -  对接收到的数据包根据不同的协议号做出相应处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void ell_recv_net_cmd(U8 cmd, U8 *pdata, int packet_len)
{
    EllLog("cmd:%X, buflen:%d, SerialNumber:%.2X%.2X",
           cmd, packet_len, pdata[packet_len - 2], pdata[packet_len - 1]);
    //ell_stop_timer(ELL_SEND_DATA_OVERTIME_TIMER_ID);
    g_recved_data = 1;
    if(cmd == 0x01 || cmd == 0xFC)
    {
    }
    else if(cmd == 0x13)
    {
        /*心跳数据包的服务器回应*/
    }
    else if(cmd == 0xFD)
    {
        if(packet_len < 100) EllHex(pdata, packet_len);
        ell_file_transport_decode_packet(pdata + 11, packet_len - 11);
    }
}


/******************************************************************************
 *  Function    -  track_cust_recv_data
 *
 *  Purpose     -  对接收的数据包进行拆分处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void ell_recv_data(U8 *data, int len)
{
    static int buflen = 0;  /* 记录当前缓冲区已有数据长度 */
    U8 *buf = g_buf1;
    U8 *buf2 = g_buf2;
    U8 cmd = 0, *pdata = NULL, *tmp = NULL;
    U16 packet_len = 0; /* 数据包中的长度 */
    int len_size = 0, i = 0, j, flag = 1, backupbegin = -1;
    if(buflen < 0) buflen = 0;
    if(buflen + len >= REQ_BUFFER_SIZE)
    {
        EllLog("%d,%d 接收数据异常", len, buflen);
        buflen = 0;
        return;
    }
    EllLog("%p, len:%d", data, len);
    memcpy(&buf[buflen], data, len);
    buflen += len;
    while(buflen - i > 0)
    {
        if(buf[i] == 0x79 && buf[i + 1] == 0x79)
        {
            len_size = 2;
            flag = 1;
        }
        else if(buf[i] == 0x78 && buf[i + 1] == 0x78)
        {
            len_size = 1;
            flag = 1;
        }
        else
        {
            if(flag)
            {
                flag = 0;
                EllLog("buflen=%d,%d 不能解析的数据包3 !!!!", buflen, i);
                EllHex(&buf[i], buflen - i);
            }
            i++;
            continue;
        }
        if(len_size > 0)
        {
            packet_len = buf[i + 2];
            if(len_size == 2)
            {
                packet_len = (packet_len << 8) + buf[i + 3];
            }
            if(i + packet_len + len_size + 4 > buflen)
            {
                EllLog("i=%d, buflen=%d, packet_len=%d, len_size=%d 不能解析的数据包1 !!!!", i, buflen, packet_len, len_size);
                //EllHex(&buf[i], buflen - i);
                flag = 0;
                i++;
                continue;
            }
            if(buf[i + packet_len + len_size + 2] != 0x0D || buf[i + packet_len + len_size + 3] != 0x0A)
            {
                EllLog("i=%d, packet_len=%d, len_size=%d, buflen=%d 不能解析的数据包2 !!!!", i, packet_len, len_size, buflen);
                //EllHex(&buf[i], buflen - i);
                for(j = i + 2; j < buflen; j++)
                {
                    if((buf[j - 1] == 0x79 && buf[j] == 0x79) || (buf[j - 1] == 0x78 && buf[j] == 0x78))
                    {
                        break;
                    }
                }
                if(j < buflen)
                {
                    i = j - 1;
                    continue;
                }
                break;
            }
            if(!ell_IsDataCrc16(&buf[i + 2], packet_len + len_size))
            {
                EllLog("crc error");
                EllHex(&buf[i], buflen - i);
                i += packet_len + len_size + 4;
                continue;
            }
            i += len_size + 2;
            pdata = &buf[i];
            cmd = pdata[0];
            i += packet_len + 2;
            packet_len -= 2; // 减去头、长度、CRC、尾
        }
        if(pdata != NULL && packet_len > 0)
        {
            EllLog("cmd:%X, buflen:%d(%d), SerialNumber:%.2X%.2X", cmd, packet_len, i, pdata[packet_len - 2], pdata[packet_len - 1]);
            ell_recv_net_cmd(cmd, pdata, packet_len);
            backupbegin = i;
        }
    }
    if(backupbegin > 0 && buflen > 0)
    {
        buflen -= backupbegin;
        if(buflen > 0 && buflen < REQ_BUFFER_SIZE)
        {
            memcpy(buf2, &buf[backupbegin], buflen);
            memcpy(buf, buf2, buflen);
            EllLog("数据包未全部接收完,剩余%d", buflen);
        }
        return;
    }
    EllLog("end2");
    //buflen = 0;
}

static void ell_socket_event(S8 mode)
{
    EllLog("mode:%d", mode);
    if(mode == SOC_CONNECT_SUCCESS) /* 2 */
    {
        g_recved_data = 0;

        EllLog("{%02d-%02d-%02d} Count:%d/%d, Day:%d/%d", 
            g_ell_otacheck.dateCount[0]+2000, g_ell_otacheck.dateCount[1], g_ell_otacheck.dateCount[2],
            g_ell_otacheck.resetCount, g_ell_otacheck.resetCountMax,
            g_ell_otacheck.resetDay, g_ell_otacheck.resetDayMax);
        if(g_ell_otacheck.resetCountMax > 0 && g_ell_otacheck.resetDayMax > 0)
        {/*控制连接次数*/
            kal_bool isChange = KAL_FALSE;
            applib_time_struct tmpDate = {0};
            applib_dt_get_rtc_time(&tmpDate);
            if(tmpDate.nYear > 0)
            {
                tmpDate.nYear = tmpDate.nYear % 100;
            }
            EllLog("%02d-%02d-%02d", tmpDate.nYear, tmpDate.nMonth, tmpDate.nDay);
            if(g_ell_otacheck.dateCount[0] == tmpDate.nYear
                && g_ell_otacheck.dateCount[1] == tmpDate.nMonth
                && g_ell_otacheck.dateCount[2] == tmpDate.nDay)
            {
                if(g_ell_otacheck.resetCount < g_ell_otacheck.resetCountMax)
                {
                    g_ell_otacheck.resetCount++;
                    isChange = KAL_TRUE;
                }
                else
                {
                    EllLog("满足限制条件，不连AMS服务器");
                    ell_restart_system(10);
                    return;
                }
            }
            else
            {
                if(g_ell_otacheck.resetCount < g_ell_otacheck.resetCountMax)
                {
                    g_ell_otacheck.resetCount = 1;
                    g_ell_otacheck.resetDay = 1;
                    g_ell_otacheck.dateCount[0] = tmpDate.nYear;
                    g_ell_otacheck.dateCount[1] = tmpDate.nMonth;
                    g_ell_otacheck.dateCount[2] = tmpDate.nDay;
                    isChange = KAL_TRUE;
                }
                else if(g_ell_otacheck.resetDay < g_ell_otacheck.resetDayMax)
                {
                    g_ell_otacheck.resetCount = 1;
                    g_ell_otacheck.resetDay++;
                    g_ell_otacheck.dateCount[0] = tmpDate.nYear;
                    g_ell_otacheck.dateCount[1] = tmpDate.nMonth;
                    g_ell_otacheck.dateCount[2] = tmpDate.nDay;
                    isChange = KAL_TRUE;
                }
                else
                {
                    EllLog("满足限制条件，不连AMS服务器");
                    ell_restart_system(10);
                    return;
                }
            }
            if(isChange)
            {
                nvram_external_write_data(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_ell_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
            }
        }

        ell_start_timer_ext(ELL_RESTART_TIMER_ID, 130000, ell_reset, (U32)11);
        soc_status.connStatus = SOC_CONN_SUCCESSFUL;
        flag_value = KAL_TRUE;
        //paket_01();
        ell_paket_driver_message();
        //paket_FC();
    }
    else if(mode == SOC_SEND_DATA) /* 4 */
    {
    }
    else if(mode == SOC_CONNECT_ServerNotResponding) /* 3 */
    {
        ell_socket_reconnect_fun();
    }
    else if(mode == SOC_RECV_DATA) /* 5 */
    {
        ell_start_timer_ext(ELL_RESTART_TIMER_ID, 130000, ell_reset, (U32)12);
        ReConCount = 0;
        if(flag_value)
        {
            ell_recv_data(g_buf_soc_recv, soc_status.LengthOfTheDataReceived);
        }
        else
        {
            EllLog("Warning: 已经全部取完，仍然收到数据，需要关注。");
        }
        soc_status.LengthOfTheDataReceived = 0;
    }
    else if(mode == SOC_CONNECT_CLOSE) /* 7 */
    {
        static int count = 0;
        if((g_recved_data == 0 && count < 3) || g_recved_data != 0)
        {
            count++;
            ell_stop_timer(ELL_SOC_SEND_OVER_TIMER_ID);
            //ell_stop_timer(ELL_SERVER_OVERTIME_TIMER_ID);
            soc_status.connStatus = SOC_CONN_DISCONNECT;
            ell_start_timer_ext(ELL_SEND_DATA_OVERTIME_TIMER_ID, 10000, ell_socket_reconnect, (void*)3);
        }
        else
        {
            ell_restart_system(8);
        }
    }
    else
    {
        ell_socket_reconnect_fun();
    }
}


/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
#if Global_Functions
#endif /* 0 */

void ell_split_update(kal_bool isWrite, U8 *data, int filesize)
{
#if 0
    	int size = 2/*head*/ + 16/*MD5*/
		+ 2/*ver_flag*/ + 4/*len*/ + ver_len/*ver_string_len*/
		+ 2/*RO flag*/ + 4/*len*/ + 4/*begin_addr*/ + file_ro_len/*RO_content_len*/
		+ 2/*RW flag*/ + 4/*len*/ + 4/*begin_addr*/ + file_rw_len/*RW_content_len*/
		+ 2/*NVRAM flag*/ + 4/*len*/ + 4/*begin_addr*/ + file_nvram_len/*NVRAM_content_len*/;
#endif /* 0 */
    nvram_check_ota_struct g_ell_otacheck = {0};

    int i, j, ret;
    U8 *addr_ver;
    U8 hash_result[16] = {0};
    U8 *addr[3] = {0};
    U16 flag[3] = {0};
    U32 len[3] = {0}, begin[3] = {0}, len_ver;
    char version[200] = {0};
    
    if(data[0] != 0xFC || data[1] != 0xFC)
    {
        EllLog("Head error!");
        return;
    }
    if(!ell_IsDataMd5ext(&data[18], filesize - 18, &data[2]))
    {
        EllLog("MD5 not same!");
        return;
    }

    memcpy(&len_ver, &data[20], 4);
    addr_ver = &data[24];
    j = 24 + len_ver;
    if(len_ver < 200)
    {
        memcpy(version, &data[24], len_ver);
    }

    for(i=0; i < 3; i++)
    {
        memcpy(&flag[i], &data[j], 2);
        j += 2;
        memcpy(&len[i], &data[j], 4);
        len[i] -= 4;
        j += 4;
        memcpy(&begin[i], &data[j], 4);
        j += 4;
        addr[i] = &data[j];
        j += len[i];
        EllLog("%d\t%d\t%X", flag[i], len[i], begin[i]);
        if(j >= filesize - 8) break;
    }
    nvram_external_read_data(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_ell_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
    for(i=0; i<3; i++)
    {
        EllLog("(%d,%d) %d\t%d\t%X", g_ell_otacheck.unconditional, isWrite, flag[i], len[i], begin[i]);
        if(len[i] > 0)
        {
            U8 md5_hash[16];
            ell_GetDataMd5(addr[i], len[i], md5_hash);
            EllHex(md5_hash, 16);
            if(flag[i] == 1)
            {
                ell_erase_data("RO");
                ret = writeRawDiskData(&FlashDiskDriveData[1], begin[i], addr[i], len[i]);
                EllLog("write disk RO %d", ret);
            }
            else if(flag[i] == 2)
            {
                ell_erase_data("RW");
                ret = writeRawDiskData(&FlashDiskDriveData[1], begin[i], addr[i], len[i]);
                EllLog("write disk RW %d", ret);
            }
            else if(flag[i] == 3)
            {
                ell_erase_data("NVRAM");
                ret = writeRawDiskData(&FlashDiskDriveData[1], begin[i], addr[i], len[i]);
                EllLog("write disk NVRAM %d", ret);
            }
        }
    }
    if(g_ell_otacheck.unconditional != 0)
    {
        ell_reset_unconditional();
    }
    
    ell_GetDataMd5(data, filesize, hash_result);
    ret = ell_data_write_to_file(FOTA_MD5_FILE_PATH, hash_result, 16);
    EllLog("write TRACK MD5 file %d", ret);
    EllHex(hash_result, 16);
    
    ell_restart_system(13);
    //printf("\r\n\r\n");
}

kal_bool ell_analysis(void)
{
    int filesize;
    U8 *p = g_buf_surplus;
    //EllLog("");
    
    filesize = ell_get_data_from_file(FOTA_FILE_PATH, p, ELL_UPDATE_BUF_SURPLUS);
    //EllLog("ell_get_data_from_file %d", filesize);
    if(filesize <= 0)
    {
        //EllLog("file open error! %d", filesize);
        return KAL_FALSE;
    }
    L1SM_SleepDisable(L1SM_GetHandle());
    
    ell_watch_dog_main(1);
    
    pmu_drv_bl_isink(ISINK0, KAL_TRUE);
    
    ell_update_status_set(1);
    
    ell_split_update(KAL_TRUE, p, filesize);
    return KAL_TRUE;
}


void ell_update_begin(ell_server_addr_struct *server)
{
    static ell_server_addr_struct ser = {0};
    S32 ret;
    U8  ip[4] = {0};
    
    EllLog("");
    ell_start_timer_ext(ELL_RESTART_TIMER_ID, 130000, ell_reset, (U32)14);
    if(server != NULL)
    {
        memcpy(&ser, server, sizeof(ell_server_addr_struct));
    }
    else
    {
        server = &ser;
    }
    memset(&soc_status, 0, sizeof(ell_soc_socket_struct));
    if(soc_status.socket_id == 0)
    {
        ret = ell_socket_GetId(SOC_SOCK_STREAM);
        if(ret < 0)
        {
            EllLog("error ret = %d", ret);
            return;
        }
        soc_status.socket_id = ret + 1;
    }
    soc_status.server_ip_addr.addr_len = 4;
    soc_status.server_ip_addr.sock_type = SOC_SOCK_STREAM;
    soc_status.LengthOfTheDataHasBeenSent = 0;
    soc_status.LengthOfTheDataReceived = 0;

    soc_status.server_ip_addr.port = server->port;
    ret = ell_check_is_IPaddress(server->addr, ip);
    EllLog("ret:%d, %s(%d.%d.%d.%d) %d", ret, server->addr, ip[0], ip[1], ip[2], ip[3], server->port);
    if(!ret)
    {
        memcpy(soc_status.server_ip_addr.addr, ip, 4);
        ell_socket_connect();
    }
    else
    {
        ell_soc_gethostbyname(server->addr, server->port);
    }
}

void ell_update_begin2(void)
{
    ell_server_addr_struct server = {0};
    ell_data_parameter_struct *ell_data_parameter = ell_get_data_parameter();
    //nvram_check_ota_struct g_ell_otacheck = {0};
    nvram_external_read_data(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_ell_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
    if(ell_data_parameter->server == NULL)
    {
        applib_time_struct tmpDate = {0};
        applib_dt_get_rtc_time(&tmpDate);

        server.port = ell_get_datadisk()->port;
        snprintf(server.addr, 99, "%s", ell_get_datadisk()->server);
        
        EllLog("1 %s:%d", server.addr, server.port);
        EllLog("{%02d-%02d-%02d} Count:%d/%d, Day:%d/%d", 
            g_ell_otacheck.dateCount[0]+2000, g_ell_otacheck.dateCount[1], g_ell_otacheck.dateCount[2],
            g_ell_otacheck.resetCount, g_ell_otacheck.resetCountMax,
            g_ell_otacheck.resetDay, g_ell_otacheck.resetDayMax);
        if(g_ell_otacheck.resetCountMax > 0 && g_ell_otacheck.resetDayMax > 0)
        {/*控制连接次数*/
            if(tmpDate.nYear > 0)
            {
                tmpDate.nYear = tmpDate.nYear % 100;
            }
            EllLog("%02d-%02d-%02d", tmpDate.nYear, tmpDate.nMonth, tmpDate.nDay);
            if(g_ell_otacheck.dateCount[0] == tmpDate.nYear
                && g_ell_otacheck.dateCount[1] == tmpDate.nMonth
                && g_ell_otacheck.dateCount[2] == tmpDate.nDay)
            {
                if(g_ell_otacheck.resetCount >= g_ell_otacheck.resetCountMax)
                {
                    EllLog("满足限制条件，不连AMS服务器");
                    ell_restart_system(10);
                    return;
                }
            }
            else
            {
                if(g_ell_otacheck.resetCount >= g_ell_otacheck.resetCountMax
                    && g_ell_otacheck.resetDay >= g_ell_otacheck.resetDayMax)
                {
                    EllLog("满足限制条件，不连AMS服务器");
                    ell_restart_system(10);
                    return;
                }
            }
        }
    }
    else
    {
        snprintf(server.addr, 100, "%s", ell_data_parameter->server);
        server.port = ell_data_parameter->port;
        EllLog("2 %s:%d", ell_data_parameter->server, ell_data_parameter->port);
    }
    ell_update_begin(&server);
}

kal_bool ell_update_Socket_get_host_by_name(void* inMsg)
{
    int i;
    kal_bool ret;
    app_soc_get_host_by_name_ind_struct* dns_ind = (app_soc_get_host_by_name_ind_struct*)inMsg;

    EllLog("域名解析 request_id=%p, result=%d, error_cause=%d, num_entry=%d, addr_len=%d, (%d.%d.%d.%d)",
        dns_ind->request_id, dns_ind->result, dns_ind->error_cause, dns_ind->num_entry, dns_ind->addr_len,
        dns_ind->addr[0],
        dns_ind->addr[1],
        dns_ind->addr[2],
        dns_ind->addr[3]);
    memcpy(entry_ip, dns_ind->entry, sizeof(entry_ip));
    entry_num_ip = dns_ind->num_entry;
    entry_index = 0;
    for(i=0; i<entry_num_ip; i++)
    {
        EllLog("域名解析[%d] (%d.%d.%d.%d)", i,
            entry_ip[i].address[0],
            entry_ip[i].address[1],
            entry_ip[i].address[2],
            entry_ip[i].address[3]);
    }
    if(dns_ind && dns_ind->result)
    {
        i = kal_get_systicks() % dns_ind->num_entry;
        EllLog("随机命中[%d] (%d.%d.%d.%d)", i,
            dns_ind->entry[i].address[0],
            dns_ind->entry[i].address[1],
            dns_ind->entry[i].address[2],
            dns_ind->entry[i].address[3]);
        //memcpy(soc_status.server_ip_addr.addr, dns_ind->addr, 4);
        memcpy(soc_status.server_ip_addr.addr, dns_ind->entry[i].address, 4);
        ret = KAL_TRUE;
        ell_socket_connect();
    }
    else
    {
        EllLog("ERROR!!!");
        ret = KAL_FALSE;
    }
    soc_status.state &= 0xFE;
    return ret;
}

/******************************************************************************
 *  Function    -  Socket_notify
 *
 *  Purpose     -  Socket事件处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void ell_update_Socket_notify(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_soc_notify_ind_struct *Socket_notify = (app_soc_notify_ind_struct*) msg_ptr;
    S8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EllLog("socket_id=%d(%d) event_type=%d, result=%d", Socket_notify->socket_id, soc_status.socket_id - 1, Socket_notify->event_type, Socket_notify->result);
    if(Socket_notify->socket_id == soc_status.socket_id - 1)
    {
        //ell_stop_timer(ELL_SOC_TIMEOUT_TIMER_ID);
        switch(Socket_notify->event_type)
        {
            case SOC_WRITE:
                {
                    ell_socket_write();
                    break;
                }
            case SOC_READ:
                {
                    ell_socket_read();
                    break;
                }
            case SOC_CONNECT:
                {
                    ell_stop_timer(ELL_SOC_CONN_TIMEOUT_TIMER_ID);
                    if(Socket_notify->result)
                    {
                        ell_socket_event(SOC_CONNECT_SUCCESS);
                    }
                    else
                    {
                        ell_socket_event(SOC_CONNECT_ServerNotResponding);
                    }
                    break;
                }
            case SOC_CLOSE:
                {
                    if(!finish)
                        ell_socket_event(SOC_CONNECT_CLOSE);
                    break;
                }
            default:
                {
                    break;
                }
        }
    }
    else
    {
        ret = ell_soc_close_ex(Socket_notify->socket_id);
    }
}

