/*******************************************************************************************
 * Filename:
 * Author :
 * Date :
 * Comment:
 ******************************************************************************************/

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "custom_data_account.h"
#include "app2soc_struct.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "L4c_common_enum.h"
#include "cbm_api.h"

#include "track_os_data_types.h"
#include "track_os_timer.h"
#include "Track_soc.h"
#include "track_soc_Lcon.h"
#include "track_os_ell.h"
#include "track_cust.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/
#define SOC_SOCKET_TIMEOUT               130000  //操作超时(毫秒)
#define SOC_SOCKET_RESEND_COUNT              2  //发送数据若没有返回希望收到的数据，重发一遍

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/
typedef struct
{
    kal_int8                  socket_id;
    sockaddr_struct           server_ip_addr;
    socket_type_enum          socket_type;
    kal_uint8                 state;
    Func_Ptr                  funcPtr;
    kal_uint32                SendDataCount;               //本次连接建立以来已经成功发送的数据总长度
    kal_uint8                 SendTheDataBuffer[SOC_SOCKET_SEND_DATA_MAX];
    kal_uint8                 ReceiveTheDataBuffer[SOC_SOCKET_RECEIVE_DATA_MAX];
    kal_int32                 LengthOfTheDataSent;         //本次待发送数据的总长度
    kal_int32                 LengthOfTheDataHasBeenSent;  //本次已发送数据的长度
    kal_int32                 LengthOfTheDataReceived;
    kal_int8                  reSend;                      //错误重连次数统计
    kal_uint8                 *databak;
    kal_uint8                 queue_id;
    kal_uint8                 packet_type;
    kal_uint8                 batchCount;
    kal_uint32                no;
    track_soc_connstatus_enum connStatus;
} soc_Socket_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	type;   /* l4c_gprs_connect_type_enum */
}nw_set_gprs_connect_type_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool	result;
}nw_set_gprs_connect_type_rsp_struct;

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static soc_Socket_struct soc_status[3] = {0};
//static char hostname_req[100];

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern void track_soc_status_callback(track_soc_Callback_struct *par);
/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
static void socket_event(kal_uint8 app, kal_int8 mode);
static void socket_error_ind(kal_uint8 app, track_soc_status_enum mode, kal_int8 errorid);
static void socket_reconnect_fun();
kal_int8 Socket_write_req3(kal_uint8 workmode, kal_uint8 app, kal_uint8 *data, kal_int32 datalen, sockaddr_struct *addr);
static void data4G_transfer(void* arg);
#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/
/******************************************************************************
 *  Function    -  socket_close
 *
 *  Purpose     -  关闭SOCKET连接
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static kal_int8 socket_close(kal_uint8 app)
{
    kal_int8 ret;
    if(soc_status[app].socket_id <= 0)
    {
        LOGD2(L_SOC, L_V1, "ERROR!");
        return -99;
    }
    if(soc_status[app].socket_id >= 1)
    {
        ret = soc_close(soc_status[app].socket_id - 1);
    }
    soc_status[app].connStatus = SOC_CONN_DISCONNECT;
    soc_status[app].socket_id = 0;
    LOGD2(L_SOC, L_V5,  "ret=%d", ret);
    return ret;
}

/******************************************************************************
 *  Function    -  socket_GetId
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
static kal_int8 socket_GetId(socket_type_enum socket_type)
{
    kal_int8 id, result;
    kal_uint8 val;

    id = soc_create(SOC_PF_INET, socket_type, 0, MOD_MMI, Socket_get_account_id());
    LOGD2(L_SOC, L_V5,  "socket id=%d", id);
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
            soc_close(id);
            return -3;
        }

        val = 1;
        result = soc_setsockopt(id, SOC_NBIO, &val, sizeof(val));
        if(0 > result)
        {
            soc_close(id);
            return -2;
        }
        return id;
    }
}

void socket_free(void)
{
    int i;
    for(i=0; i < MAX_IP_SOCKET_NUM; i++)
    {
        if(i != soc_status[0].socket_id - 1 && i != soc_status[1].socket_id - 1)
        {
            soc_close(i);
        }
    }
}

/******************************************************************************
 *  Function    -  socket_connect
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
static void socket_connect(kal_uint8 app)
{
    kal_int8 ret;
    kal_uint32 par = app;
    LOGD2(L_SOC, L_V5,  "addr:%d.%d.%d.%d:%d,%d", soc_status[app].server_ip_addr.addr[0], soc_status[app].server_ip_addr.addr[1], soc_status[app].server_ip_addr.addr[2], soc_status[app].server_ip_addr.addr[3], soc_status[app].server_ip_addr.port,par);
    track_start_timer(TRACK_SOC_TIMEOUT_TIMER_ID + app, SOC_SOCKET_TIMEOUT, socket_reconnect_fun, (void*)par);
    if(soc_status[app].socket_id <= 0)
    {
        LOGD2(L_SOC, L_V1, "ERROR!");
        return;
    }
    ret = soc_connect(soc_status[app].socket_id - 1, &soc_status[app].server_ip_addr);
    LOGD2(L_SOC, L_V5,  "ret=%d", ret);
#if defined(__AMS_LOG__)
    if(0==app && ret!=-2)
    {
		char buf[20]={0};
		sprintf(buf,"(D)(%d)%d ",(kal_get_systicks()-0)/KAL_TICKS_1_SEC,ret);
		track_cust_cache_netlink(buf,strlen(buf));
    }
#endif
    switch(ret)
    {
        case SOC_SUCCESS:
            {
                track_stop_timer(TRACK_SOC_TIMEOUT_TIMER_ID + app);
                socket_event(app, SOC_CONNECT_SUCCESS);
                break;
            }
        case SOC_WOULDBLOCK:
            {
                break;
            }
        default:
            {
                track_stop_timer(TRACK_SOC_TIMEOUT_TIMER_ID + app);
                socket_error_ind(app, SOC_BEGIN_CONNECT, ret);
                soc_status[app].state &= 0xFD;
                break;
            }
    }
}

/******************************************************************************
 *  Function    -  socket_reconnect
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
static void socket_reconnect(kal_uint8 app)
{
    kal_int8 ret;
    if(soc_status[app].socket_id <= 0)
    {
        LOGD2(L_SOC, L_V1, "ERROR!");
        return;
    }
    ret = soc_close(soc_status[app].socket_id - 1);
    LOGD2(L_SOC, L_V5,  "ret=%d", ret);
    if(soc_status[app].reSend > 2)
    {
        //重连两次仍然失败，释放CBM，再重试
        //cbm_release_bearer(MOD_MMI, 1);
        //track_start_timer(SOC_SOCKET_CBM_RELEASE_TIMER_ID, 5000, event_soc_reg, &mode);
    }
    else
    {
        socket_event(app, 1);
    }
}

/******************************************************************************
 *  Function    -  socket_reconnect_fun
 *
 *  Purpose     -  重连超时处理
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void socket_reconnect_fun(void* arg)
{
    kal_uint8 app = (kal_uint32)arg;
    LOGD2(L_SOC, L_V5,  "");
#if defined(__GT740__)
	if(0==app)
	{
		char buf[100]={0};
		sprintf(buf+strlen(buf),"(L)(%d) %d",(kal_get_systicks()-0)/KAL_TICKS_1_SEC,soc_status[app].reSend);
		track_cust_cache_netlink(buf,strlen(buf));
		if(2==G_parameter.extchip.mode)
		{
		    //track_soc_bakup_data((void*)3);
		}
	}
#endif

	
    soc_status[app].reSend++;
    if(soc_status[app].reSend > 1) //失败重连，不能无限制的重连
    {
        soc_status[app].reSend = 0;
        socket_event(app, -4);
        return;
    }
    socket_reconnect(app);
}

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
static void socket_write_delay(void* arg)
{
    kal_uint8 app = (kal_uint32)arg;
    track_stop_timer(TRACK_SOC_TIMEOUT_TIMER_ID + app);
    socket_event(app, SOC_SEND_DATA);
}

#if 1
/******************************************************************************
 *  Function    -  Socket_get_send_success_count
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
static kal_uint32 Socket_get_send_success_count(kal_uint8 app)
{
    static kal_uint64 soc_acked_data2 = 0;
    kal_uint32 count;
    kal_int8 ret;

    if(soc_status[app].connStatus != SOC_CONN_SUCCESSFUL)
    {
        LOGD2(L_SOC, L_V2, "connStatus:%d", soc_status[app].connStatus);
        return 0;
    }
    ret = soc_getsockopt(soc_status[app].socket_id - 1, SOC_TCP_ACKED_DATA, (void *)&soc_acked_data2, sizeof(kal_uint64));
    if(SOC_SUCCESS != ret)
    {
        //fail to get acked data
        LOGD2(L_SOC, L_V2, "ACK Error : %d", ret);
        return 0;
    }
    count = soc_acked_data2;
    return count;
}

/******************************************************************************
 *  Function    -  socket_send_data_ReCount
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
static void socket_send_data_ReCount(void* arg)
{
    static int count = 0;
    kal_uint32 len;
    kal_uint32 par = (kal_uint32)arg;
    kal_uint8 app = (par & 0x000000FF);
    if((par & 0x0000FF00) > 0) 
    {
        count = 0;
    }
    else
    {
        count++;
    }
    track_stop_timer(TRACK_SOC_SEND_OVER_TIMER_ID + app);
    if(count < 225)
    {
        len = Socket_get_send_success_count(app);
        LOGD2(L_SOC, L_V7,  "count=%d, len:%d-%d ? %d", count, len, soc_status[app].SendDataCount, soc_status[app].LengthOfTheDataSent);
        if(len - soc_status[app].SendDataCount >= soc_status[app].LengthOfTheDataSent)
        {
            LOGD2(L_SOC, L_V6,  "count=%d", count);
            soc_status[app].SendDataCount = len;
            socket_write_delay((void*)(par & 0x000000FF));
        }
        else
        {
            track_start_timer(TRACK_SOC_SEND_OVER_TIMER_ID + app, 400, socket_send_data_ReCount, (void*)par);
        }
    }
    else
    {
        LOGD2(L_SOC, L_V1,  "ERROR!!!");
        socket_error_ind(app, SOC_SEND_DATA, -50);
    }
}
#endif /* 0 */

/******************************************************************************
 *  Function    -  data_copy
 *
 *  Purpose     -  状态复制
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void data_copy(kal_uint8 app, track_soc_Callback_struct *cb)
{
    cb->databak = soc_status[app].databak;
    cb->no = soc_status[app].no;
    cb->packet_type = soc_status[app].packet_type;
    cb->queue_id = soc_status[app].queue_id;
    cb->batchCount = soc_status[app].batchCount;
}

static void sovket_write_error(U32 app)
{
    track_stop_timer(TRACK_SOC_TIMEOUT_TIMER_ID + app);
    socket_error_ind(app, SOC_SEND_DATA, -99);
    soc_status[app].state &= 0xFB;
#if defined(__AMS_LOG__)
	if(0==app)
	{
			char buf[100]={0};
			sprintf(buf+strlen(buf),"(M)(%d)",(kal_get_systicks()-0)/KAL_TICKS_1_SEC);
			track_cust_cache_netlink(buf,strlen(buf));
			if(2==G_parameter.extchip.mode)
			{
			    //track_soc_bakup_data((void*)3);
			}
	}
#endif

}

/******************************************************************************
 *  Function    -  socket_write
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
static void socket_write(void* arg)
{
    kal_int32 ret;
    kal_uint8 app = (kal_uint32)arg;
    track_start_timer(TRACK_SOC_TIMEOUT_TIMER_ID + app, SOC_SOCKET_TIMEOUT, sovket_write_error, arg);
    if(soc_status[app].socket_id <= 0)
    {
        LOGD2(L_SOC, L_V1, "ERROR!");
        return;
    }
    ret = soc_send(soc_status[app].socket_id - 1, soc_status[app].SendTheDataBuffer + soc_status[app].LengthOfTheDataHasBeenSent, soc_status[app].LengthOfTheDataSent - soc_status[app].LengthOfTheDataHasBeenSent, 0);
    LOGD2(L_SOC, L_V5,  "app=%d,ret=%d LengthOfTheDataHasBeenSent=%d,%d", app,ret, soc_status[app].LengthOfTheDataHasBeenSent, soc_status[app].LengthOfTheDataSent);
    if(ret >= 0)
    {
        soc_status[app].LengthOfTheDataHasBeenSent += ret;
        if(soc_status[app].LengthOfTheDataHasBeenSent >= soc_status[app].LengthOfTheDataSent)
        {
#if 1
            //服务器没有响应HTTP请求，重发请求
            kal_uint32 len;
            len = Socket_get_send_success_count(app);
            //LOGD2(L_SOC, L_V9,  "len:%d, %d, %d", soc_status[app].LengthOfTheDataSent, len, soc_status[app].SendDataCount);
            if(len - soc_status[app].SendDataCount >= soc_status[app].LengthOfTheDataSent)
            {
                soc_status[app].SendDataCount = len;
                socket_write_delay(arg);
            }
            else
            {
                kal_uint32 par = app;
                track_start_timer(TRACK_SOC_SEND_OVER_TIMER_ID + app, 200, socket_send_data_ReCount, (void*)(par | 0x00000100));
            }
#else
            soc_status[app].SendDataCount = ret;
            track_start_timer(TRACK_SOCKET_SEND_TIMER_ID + app, 200, socket_write_delay, arg);
#endif /* 0 */
        }
        else
        {
            track_start_timer(TRACK_SOCKET_SEND_TIMER_ID + app, 1000, socket_write, arg);
        }
    }
    else if(SOC_WOULDBLOCK == ret)
    {
        ret = 0;
    }
    else
    {
        track_stop_timer(TRACK_SOC_TIMEOUT_TIMER_ID + app);
        socket_error_ind(app, SOC_SEND_DATA, ret);
        soc_status[app].state &= 0xFB;
    }
}
#if 0
static void socket_write_dgram(void* arg)
{
    kal_int32 ret;
    kal_uint8 app = (kal_uint32)arg;
    track_start_timer(TRACK_SOC_TIMEOUT_TIMER_ID + app, SOC_SOCKET_TIMEOUT, socket_reconnect_fun, arg);
    if(soc_status[app].socket_id <= 0)
    {
        LOGD2(L_SOC, L_V1, "ERROR!");
        return;
    }
    ret = soc_send(soc_status[app].socket_id - 1, soc_status[app].SendTheDataBuffer + soc_status[app].LengthOfTheDataHasBeenSent, soc_status[app].LengthOfTheDataSent - soc_status[app].LengthOfTheDataHasBeenSent, 0);
    LOGD2(L_SOC, L_V5,  "ret=%d LengthOfTheDataHasBeenSent=%d,%d", ret, soc_status[app].LengthOfTheDataHasBeenSent, soc_status[app].LengthOfTheDataSent);
    if(ret >= 0)
    {
        if(ret >= soc_status[app].LengthOfTheDataSent)
        {
#if 1
            //服务器没有响应HTTP请求，重发请求
            kal_uint32 len;
            len = Socket_get_send_success_count(app);
            //LOGD2(L_SOC, L_V9,  "len:%d, %d, %d", soc_status[app].LengthOfTheDataSent, len, soc_status[app].SendDataCount);
            if(len - soc_status[app].SendDataCount >= soc_status[app].LengthOfTheDataSent)
            {
                soc_status[app].SendDataCount = len;
                socket_write_delay(arg);
            }
            else
            {
                kal_uint32 par = app;
                track_start_timer(TRACK_SOC_SEND_OVER_TIMER_ID + app, 200, socket_send_data_ReCount, (void*)(par | 0x00000100));
            }
#else
            soc_status[app].SendDataCount = ret;
            track_start_timer(TRACK_SOCKET_SEND_TIMER_ID + app, 200, socket_write_delay, arg);
#endif /* 0 */
        }
        else
        {
            soc_status[app].LengthOfTheDataHasBeenSent = ret;
            track_start_timer(TRACK_SOCKET_SEND_TIMER_ID + app, 1000, socket_write, arg);
        }
    }
    else if(SOC_WOULDBLOCK == ret)
    {
        ret = 0;
    }
    else
    {
        track_stop_timer(TRACK_SOC_TIMEOUT_TIMER_ID + app);
        socket_error_ind(app, SOC_SEND_DATA, ret);
        soc_status[app].state &= 0xFB;
    }
}
#endif
/******************************************************************************
 *  Function    -  socket_read
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
static void socket_read(void* arg)
{
    kal_int32 ret;
    kal_uint8 app = (kal_uint32)arg;
    if(soc_status[app].socket_id <= 0)
    {
        LOGD2(L_SOC, L_V1, "ERROR! socket_id:%d", soc_status[app].socket_id);
        return;
    }
    ret = soc_recv(soc_status[app].socket_id - 1, soc_status[app].ReceiveTheDataBuffer + soc_status[app].LengthOfTheDataReceived, SOC_SOCKET_RECEIVE_DATA_MAX - soc_status[app].LengthOfTheDataReceived, 0);
    LOGD2(L_SOC, L_V5,  "ret=%d, LengthOfTheDataReceived=%d", ret, soc_status[app].LengthOfTheDataReceived);
    if(ret > 0)
    {
        //LOGH2(L_SOC, L_V7, "socket_read()", soc_status[app].ReceiveTheDataBuffer + soc_status[app].LengthOfTheDataReceived, ret);
        soc_status[app].LengthOfTheDataReceived += ret;
        if(soc_status[app].LengthOfTheDataReceived == SOC_SOCKET_RECEIVE_DATA_MAX)
        {
            // 缓冲区已满，先把已收到的数据返回
            socket_event(app, SOC_RECV_DATA);
            socket_read(arg);
        }
        else if(soc_status[app].LengthOfTheDataReceived > SOC_SOCKET_RECEIVE_DATA_MAX)
        {
            socket_event(app, -3);
            LOGD2(L_SOC, L_V1,  "error LengthOfTheDataReceived:%d", soc_status[app].LengthOfTheDataReceived);
        }
        else
        {
            //这里需不需要用定时器回调?
            socket_read(arg);
        }
    }
    else if(ret == SOC_WOULDBLOCK || ret == 0)
    {
        //需要留意，当前这种处理办法会不会导致需要主动断开时出现问题
        track_stop_timer(TRACK_SOC_TIMEOUT_TIMER_ID + app);
        socket_event(app, SOC_RECV_DATA);
    }
    else if(ret == SOC_PIPE)
    {
        track_stop_timer(TRACK_SOC_TIMEOUT_TIMER_ID + app);
        LOGD2(L_SOC, L_V1,  "error 2 连接通道已经关闭，不能接收数据!");
        socket_event(app, -6); // 准备接收数据是，探测到已建立的连接已经断开，此时可能服务器下发的数据初始丢失的情况
    }
    else
    {
        track_stop_timer(TRACK_SOC_TIMEOUT_TIMER_ID + app);
        LOGD2(L_SOC, L_V1,  "error 3");
        socket_event(app, -5);
    }
}

/******************************************************************************
 *  Function    -  socket_event
 *
 *  Purpose     -  Socket响应事件
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void socket_event(kal_uint8 app, kal_int8 mode)
{
    LOGD2(L_SOC, L_V5,  "mode=%d,app=%d", mode,app);
    if(mode <= 0)
    {
        track_soc_Callback_struct cb = {0};
        data_copy(app, &cb);
        cb.status = mode;
        if(soc_status[app].funcPtr != NULL) 
        {
            soc_status[app].funcPtr(&cb);
        }
        if(mode < 0)
        {
            socket_close(app); //立即断开
        }
        return;
    }
    switch(mode)
    {
        case SOC_BEGIN_CONNECT: //连接服务器
            {
                kal_int8 ret;
                ret = socket_GetId(soc_status[app].socket_type);
                if(ret < 0)
                {
                    LOGD2(L_SOC, L_V1,  "error ret = %d", ret);
                    return;
                }
                soc_status[app].socket_id = ret + 1;
                soc_status[app].LengthOfTheDataHasBeenSent = 0;
                soc_status[app].LengthOfTheDataReceived = 0;
                socket_connect(app);
                break;
            }

        case SOC_CONNECT_SUCCESS:   //连接成功
            {
                track_soc_Callback_struct cb = {0};
                data_copy(app, &cb);
                cb.status = mode;
                soc_status[app].state &= 0xFD;
                soc_status[app].connStatus = SOC_CONN_SUCCESSFUL;
                soc_status[app].SendDataCount = 0;
                if(soc_status[app].funcPtr != NULL)
                {
                    soc_status[app].funcPtr(&cb);
                }
                break;
            }
        case SOC_CONNECT_ServerNotResponding://连接服务器失败重连
            {
                kal_int8 ret;
                track_soc_Callback_struct cb = {0};
                ret = socket_close(app);
                soc_status[app].connStatus = SOC_CONN_FAILURE;
                data_copy(app, &cb);
                LOGD2(L_SOC, L_V5,  "ret=%d");
                //if(ret == 0)
                {
                    cb.status = mode;
                    if(soc_status[app].funcPtr != NULL)
                    {
                        soc_status[app].funcPtr(&cb);
                    }
                }
                break;
            }
        case SOC_SEND_DATA://发送数据
            {
                track_soc_Callback_struct cb = {0};
                data_copy(app, &cb);
                cb.status = mode;
                if(soc_status[app].funcPtr != NULL)
                {
                    soc_status[app].funcPtr(&cb);
                }
                soc_status[app].state &= 0xFB;
                break;
            }
        case SOC_RECV_DATA://接收到数据
            {
                track_soc_Callback_struct cb = {0};
                data_copy(app, &cb);
                cb.status = mode;
                cb.recvBuffLen = soc_status[app].LengthOfTheDataReceived;
                cb.recvBuff = soc_status[app].ReceiveTheDataBuffer;
                if(soc_status[app].state & 4)
                {
                    kal_uint32 par = app;
                    socket_send_data_ReCount((void*)(par | 0x00000100));
                }
                if(soc_status[app].funcPtr != NULL)
                {
                    soc_status[app].funcPtr(&cb);
                }
                soc_status[app].LengthOfTheDataReceived = 0;
                memset(soc_status[app].ReceiveTheDataBuffer, 0, SOC_SOCKET_RECEIVE_DATA_MAX);
                break;
            }

        case SOC_RECV_DATA_MayNotBeComplete://接收到数据
            {
                track_soc_Callback_struct cb = {0};
                data_copy(app, &cb);
                cb.status = mode;
                cb.recvBuffLen = soc_status[app].LengthOfTheDataReceived;
                cb.recvBuff = soc_status[app].ReceiveTheDataBuffer;
                if(soc_status[app].funcPtr != NULL)
                {
                    soc_status[app].funcPtr(&cb);
                }
                soc_status[app].LengthOfTheDataReceived = 0;
                memset(soc_status[app].ReceiveTheDataBuffer, 0, SOC_SOCKET_RECEIVE_DATA_MAX);
            }

        case SOC_CONNECT_CLOSE://远程服务器断开(数据发送成功了，但没有收到任何回馈信息)
            {
                kal_int8 ret;
                track_soc_Callback_struct cb = {0};
                track_stop_timer(TRACK_SOC_SEND_OVER_TIMER_ID + app);
                ret = socket_close(app);
                data_copy(app, &cb);
                cb.status = mode;
                if(soc_status[app].funcPtr != NULL)
                {
                    soc_status[app].funcPtr(&cb);
                }
                soc_status[app].socket_id = 0;
                soc_status[app].connStatus = SOC_CONN_DISCONNECT;
                break;
            }
        default:
            break;
    }
}


/******************************************************************************
 *  Function    -  socket_error_ind
 *
 *  Purpose     -  Socket错误处理
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void socket_error_ind(kal_uint8 app, track_soc_status_enum mode, kal_int8 errorid)
{
    track_soc_Callback_struct cb = {0};
    data_copy(app, &cb);
    cb.databak = NULL;
    cb.status = mode;
    cb.errorid = errorid;
    if(soc_status[app].funcPtr != NULL) soc_status[app].funcPtr(&cb);
}

static void Socket_gethostbyname_return(Func_Ptr func, kal_uint8 *ip, kal_int8 errorid)
{
    track_soc_Callback_struct cb = {0};
    cb.errorid = errorid;
    cb.status = SOC_RECV_HOST_BY_NAME;
    if(ip[0] == 0 && ip[1] == 0 && ip[2] == 0 && ip[3] == 0)
    {
        cb.errorid = -99;
    }
    else
    {
        cb.errorid = errorid;
        memcpy(cb.ip_from_hostname, ip, 4);
    }
    if(func != NULL) func(&cb);
}

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

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
void Socket_notify(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    app_soc_notify_ind_struct *Socket_notify = (app_soc_notify_ind_struct*) msg_ptr;
    kal_int8 ret;
    int i;
    U32 app = 99;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0; i<3; i++)
    {
        LOGD2(L_SOC, L_V5, "soc_status[%d].socket_id=%d", i, soc_status[i].socket_id);
        if(Socket_notify->socket_id == soc_status[i].socket_id - 1 && soc_status[i].connStatus >= SOC_CONN_SUCCESSFUL)
        {
            app = i;
            break;
        }

    }

#if defined(__AMS_LOG__)
	if(0==app)
	{
			char buf[100]={0};
			sprintf(buf+strlen(buf),"(C)(%d),%d,%d",(kal_get_systicks()-0)/KAL_TICKS_1_SEC, Socket_notify->event_type, Socket_notify->result);
			track_cust_cache_netlink(buf,strlen(buf));
	}
#endif

    LOGD2(L_SOC, L_V5, "app:%d socket_id=%d(%d,%d) event_type=%d, result=%d", 
        app, Socket_notify->socket_id, soc_status[0].socket_id - 1, soc_status[1].socket_id - 1, Socket_notify->event_type, Socket_notify->result);
    if(app == 99)
    {
        ret = soc_close(Socket_notify->socket_id);
    }
    else
    {
        track_stop_timer(TRACK_SOC_TIMEOUT_TIMER_ID + app);
        switch(Socket_notify->event_type)
        {
            case SOC_WRITE:
                {
                    socket_write((void *)app);
                    break;
                }
            case SOC_READ:
                {
                    socket_read((void *)app);
                    break;
                }
            case SOC_CONNECT:
                {
                    if(Socket_notify->result)
                    {
                        socket_event(app, SOC_CONNECT_SUCCESS);
                    }
                    else
                    {
                        socket_event(app, SOC_CONNECT_ServerNotResponding);
                    }
                    break;
                }
            case SOC_CLOSE:
                {
                    socket_event(app, SOC_CONNECT_CLOSE);
                    break;
                }
        }
    }
}

/******************************************************************************
 *  Function    -  Socket_get_host_by_name
 *
 *  Purpose     -  域名解析结果
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void Socket_get_host_by_name(void* inMsg)
{
    int i;
    kal_bool ret;
    app_soc_get_host_by_name_ind_struct* dns_ind = (app_soc_get_host_by_name_ind_struct*)inMsg;

    LOGD2(L_SOC, L_V5, "域名解析 request_id=%p, result=%d, error_cause=%d, num_entry=%d, addr_len=%d, (%d.%d.%d.%d)",
        (Func_Ptr)dns_ind->request_id, dns_ind->result, dns_ind->error_cause, dns_ind->num_entry, dns_ind->addr_len,
        dns_ind->addr[0],
        dns_ind->addr[1],
        dns_ind->addr[2],
        dns_ind->addr[3]);
    for(i=0;i<dns_ind->num_entry; i++)
    {
        LOGD2(L_SOC, L_V5, "域名解析[%d] (%d.%d.%d.%d)", i,
            dns_ind->entry[i].address[0],
            dns_ind->entry[i].address[1],
            dns_ind->entry[i].address[2],
            dns_ind->entry[i].address[3]);
    }
    if(dns_ind->request_id)
    {
        if(dns_ind && dns_ind->result)
        {
            i = kal_get_systicks() % dns_ind->num_entry;
            LOGD2(L_SOC, L_V5, "随机命中[%d] (%d.%d.%d.%d)", i,
                dns_ind->entry[i].address[0],
                dns_ind->entry[i].address[1],
                dns_ind->entry[i].address[2],
                dns_ind->entry[i].address[3]);
            //Socket_gethostbyname_return((Func_Ptr)dns_ind->request_id, dns_ind->addr, 0);
            Socket_gethostbyname_return((Func_Ptr)dns_ind->request_id, dns_ind->entry[i].address, 0);
        }
        else
        {
            //dns analyse error.
            if(dns_ind->error_cause == 0)
                Socket_gethostbyname_return((Func_Ptr)dns_ind->request_id, dns_ind->addr, -99);
            else
                Socket_gethostbyname_return((Func_Ptr)dns_ind->request_id, dns_ind->addr, dns_ind->error_cause);
        }
    }
}

/******************************************************************************
 *  Function    -  Socket_gethostbyname
 *
 *  Purpose     -  请求域名解析
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_int8 Socket_gethostbyname(char *hostname, Func_Ptr func)
{
    kal_int8 ret;
    kal_uint8 addr_len;
    int len, i;
    kal_uint32 account_id;
    kal_uint8 ip_from_hostname[20] = {0};
    
    len = strlen(hostname);
    if(len >= 100)
    {
        LOGD2(L_SOC, L_V1, "Error! len>=100");
        return -2;
    }
    account_id = Socket_get_account_id();
    len = 4;
    ret = soc_gethostbyname(
              KAL_FALSE,
              MOD_MMI,
              (kal_int32) func,
              (kal_char*) hostname,
              (kal_uint8*) ip_from_hostname,
              (kal_uint8*) &len,
              0,
              account_id);

    LOGD2(L_SOC, L_V5, "func:%p, ret:%d, account_id:%d", func, ret, account_id);
    if(ret == SOC_SUCCESS)
    {
        LOGD2(L_SOC, L_V5, "%s -> %d.%d.%d.%d",
             (S8*)hostname,
             ip_from_hostname[0],
             ip_from_hostname[1],
             ip_from_hostname[2],
             ip_from_hostname[3]);
        if(func) Socket_gethostbyname_return(func, ip_from_hostname, ret);
    }
    else if(ret == SOC_WOULDBLOCK)
    {
        /* waits for APP_SOC_GET_HOST_BY_NAME_IND */
    }
    else
    {
        LOGD2(L_SOC, L_V1, "Error 2! ret=%d", ret);
        if(func) Socket_gethostbyname_return(func, ip_from_hostname, ret);
    }
    return 0;
}

/******************************************************************************
 *  Function    -  Socket_conn_req
 *
 *  Purpose     -  Socket连接请求
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_int8 Socket_conn_req(kal_uint8 app, sockaddr_struct *ip_addr, Func_Ptr func, kal_uint32 no)
{
    if(app < 0 || app > 2)
    {
        LOGD2(L_SOC, L_V1, "Error :app");
        return -1;
    }
    LOGD2(L_SOC, L_V5, "%d.%d.%d.%d:%d, state=%X, connStatus=%d",
         ip_addr->addr[0], ip_addr->addr[1], ip_addr->addr[2], ip_addr->addr[3], ip_addr->port,
         soc_status[app].state, soc_status[app].connStatus);
    if(ip_addr->addr[0] == 0 || ip_addr->port == 0)
    {
        return -2;
    }
    if(soc_status[app].connStatus == SOC_CONN_CONNECTING)
    {
        // 正在连接服务器，请稍后
        return -3;
    }
    //socket_free();
    soc_status[app].state |= 2;
    soc_status[app].socket_type = SOC_SOCK_STREAM;
    if(soc_status[app].connStatus == SOC_CONN_SUCCESSFUL)
    {
        if(memcmp(&soc_status[app].server_ip_addr, ip_addr, sizeof(sockaddr_struct)) != 0 || soc_status[app].funcPtr != func)
        {
            //目标服务器地址变更，断开之前的重新连接
            socket_close(app);
        }
        else
        {
            socket_event(app, SOC_CONNECT_SUCCESS);
        }
    }
	
    if(soc_status[app].connStatus != SOC_CONN_SUCCESSFUL)
    {
        memset(&soc_status[app], 0, sizeof(soc_Socket_struct));
        soc_status[app].connStatus = SOC_CONN_CONNECTING;
        soc_status[app].socket_id = 0;
        memcpy(&soc_status[app].server_ip_addr, ip_addr, sizeof(sockaddr_struct));
        soc_status[app].funcPtr = func;
        soc_status[app].no = no;
        track_stop_timer(TRACK_SOC_SEND_OVER_TIMER_ID + app);
        socket_event(app, SOC_BEGIN_CONNECT);
    }
    return 0;
}
/******************************************************************************
 *  Function    -  Socket_write_req
 *
 *  Purpose     -  数据发送请求
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_int8 Socket_write_req(kal_uint8 app, kal_uint8 *data, kal_int32 datalen, kal_uint8 queue_id, kal_uint8 packet_type, kal_uint32 no, kal_uint8 batchCount)
{
    kal_uint32 par;
    if(app < 0 || app > 2)
    {
        LOGD2(L_SOC, L_V1, "Error :-1");
        return -1;
    }
    LOGD2(L_SOC, L_V5, "app=%d,datalen=%d, no=%0.4X,connstatus=%d,%d", app,datalen, no, soc_status[app].connStatus, soc_status[app].state);
    if(datalen < 0 || datalen >= SOC_SOCKET_SEND_DATA_MAX)
    {
        LOGD2(L_SOC, L_V1, "Error :-2");
        return -2;
    }
    if(soc_status[app].connStatus != SOC_CONN_SUCCESSFUL)
    {
        LOGD2(L_SOC, L_V1, "Error :-3");
        return -3;
    }
    if(datalen == 0) return 0;
    if(soc_status[app].state & 4)
    {
        // 正在使用，不支持并发，队列发送数据
        LOGD2(L_SOC, L_V1, "Error :-4");
        return -4;
    }
    soc_status[app].state |= 4;
    soc_status[app].LengthOfTheDataSent = datalen;
    soc_status[app].reSend = 0;
    soc_status[app].no = no;
    soc_status[app].batchCount = batchCount;
    soc_status[app].packet_type = packet_type;
    soc_status[app].queue_id = queue_id;
    soc_status[app].LengthOfTheDataHasBeenSent = 0;
    memcpy(&soc_status[app].SendTheDataBuffer, data, soc_status[app].LengthOfTheDataSent);
    //LOGD2(L_SOC, L_V5, "LengthOfTheDataSent=%d", soc_status[app].LengthOfTheDataSent);
    par = app;
    socket_write((void *)par);
    //LOGD2(L_SOC, L_V5, "LengthOfTheDataSent=%d", soc_status[app].LengthOfTheDataSent);
    return 0;
}

kal_int8 Socket_write_req3(kal_uint8 workmode, kal_uint8 app, kal_uint8 *data, kal_int32 datalen, sockaddr_struct *addr)
{
    static kal_uint8  buf1[2000] = {0}, buf2[2000] = {0};
    static kal_uint16 buf1_len = 0, buf2_len = 0;
    static applib_time_struct time = {0};
    kal_uint32 par;
    int ret;
  /*  if(app != 0 && app != 1 && app != 2)
    {
        LOGD2(L_SOC, L_V1, "Error :app");
        return;
    }*/
    if(workmode == 1)
    {
        LOGD2(L_SOC, L_V8, "datalen=%d", datalen);
        if(datalen < 0 || datalen >= 1997)
        {
            return -2;
        }
       /* if(soc_status[app].connStatus != SOC_CONN_SUCCESSFUL)
        {
            return -3;
        }*/
        if(datalen == 0) return 0;
        /*if(track_cust_is_upload_UTC_time())
        {
            track_fun_get_time(&time, KAL_TRUE, NULL);
        }
        else*/
        {
            //extern fat_parameter_struct G_parameter;
            track_fun_get_time(&time, KAL_FALSE, &G_parameter.zone.zone);
        }
        if(soc_status[app].state & 4)
        {
            // 正在使用，不支持并发，队列发送数据
            if(buf1_len + datalen < 1997)
            {
                sprintf(&buf1[buf1_len], "[%0.2d:%0.2d:%0.2d]", time.nHour, time.nMin, time.nSec);
                buf1_len += 10;
                memcpy(&buf1[buf1_len], data, datalen);
                buf1_len += datalen;
                buf1[buf1_len++] = 0x0D;
                buf1[buf1_len++] = 0x0A;
            }
            return -4;
        }
        else if(buf1_len > 0)
        {
            memcpy(buf2, buf1, buf1_len);
            buf2_len = buf1_len;
            if(buf2_len + datalen < 1997)
            {
                sprintf(&buf2[buf2_len], "[%0.2d:%0.2d:%0.2d]", time.nHour, time.nMin, time.nSec);
                buf2_len += 10;
                memcpy(&buf2[buf2_len], data, datalen);
                buf2_len += datalen;
                buf2[buf2_len++] = 0x0D;
                buf2[buf2_len++] = 0x0A;
            }
        }
        else
        {
            sprintf(buf2, "[%0.2d:%0.2d:%0.2d]", time.nHour, time.nMin, time.nSec);
            buf2_len = 10;
            memcpy(&buf2[buf2_len], data, datalen);
            buf2_len += datalen;
            buf2[buf2_len++] = 0x0D;
            buf2[buf2_len++] = 0x0A;
        }
        soc_status[app].state |= 4;
        soc_status[app].socket_type = SOC_SOCK_DGRAM;
        if(soc_status[app].socket_id <= 0)
        {
            kal_int8 ret;
            ret = socket_GetId(soc_status[app].socket_type);
            if(ret < 0)
            {
                LOGD2(L_SOC, L_V1,  "error ret = %d", ret);
                return;
            }
            soc_status[app].socket_id = ret + 1;
        }
        memcpy(&soc_status[app].server_ip_addr, addr, sizeof(sockaddr_struct));
    }
    //soc_status[app].LengthOfTheDataSent = datalen;
    //soc_status[app].reSend = 0;
    //soc_status[app].LengthOfTheDataHasBeenSent = 0;
    //memcpy(&soc_status[app].SendTheDataBuffer, data, soc_status[app].LengthOfTheDataSent);
    //LOGD2(L_SOC, L_V8, "LengthOfTheDataSent=%d", soc_status[app].LengthOfTheDataSent);
    //par = app;
    ret = OTA_soc_sendto(
        soc_status[app].socket_id - 1, 
        buf2, 
        buf2_len, 
        0,
        &soc_status[app].server_ip_addr);
    LOGD2(L_SOC, L_V8,  "ret=%d", ret);
    if(ret >= 0)
    {
        soc_status[app].state &= 0xFB;
    }
    else if(SOC_WOULDBLOCK == ret)
    {
        ret = 0;
    }
    else
    {
        socket_error_ind(app, SOC_SEND_DATA, ret);
        soc_status[app].state &= 0xFB;
    }
    return 0;
}

/******************************************************************************
 *  Function    -  Socket_get_write_status
 *
 *  Purpose     -  数据发送状态查询
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_bool Socket_get_write_status(kal_uint8 app)
{
    if(app < 0 || app > 2)
    {
        LOGD2(L_SOC, L_V1, "Error :app");
        return;
    }
    return (soc_status[app].state & 4);
}

/******************************************************************************
 *  Function    -  Socket_get_conn_status
 *
 *  Purpose     -  Socket连接状态查询
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
track_soc_connstatus_enum Socket_get_conn_status(kal_uint8 app)
{
    if(app < 0 || app > 2)
    {
        LOGD2(L_SOC, L_V1, "Error :app");
        return;
    }
    return soc_status[app].connStatus;
}

/******************************************************************************
 *  Function    -  socket_disconnect
 *
 *  Purpose     -  断开连接请求
 *
 *  Description -  
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void socket_disconnect(kal_uint8 app)
{
    if(app < 0 || app > 2)
    {
        LOGD2(L_SOC, L_V1, "Error :app");
        return;
    }
    if(soc_status[app].connStatus != 0)
    {
        socket_event(app, SOC_CONNECT_CLOSE);
    }
}

/******************************************************************************
 *  Function    -  track_drv_network_license_gprs_attach_req
 * 
 *  Purpose     -  GPRS附着请求
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 02-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_network_license_gprs_attach_req(void)
{
    ilm_struct *ilm_ptr;
    nw_set_gprs_connect_type_req_struct *myMsgPtr = NULL;
    LOGD2(L_SOC, L_V5, "GPRS 附着请求");
    myMsgPtr = (nw_set_gprs_connect_type_req_struct*) construct_local_para(sizeof(nw_set_gprs_connect_type_req_struct),TD_CTRL);
    myMsgPtr->type = L4C_ALWAYS;//L4C_WHEN_NEEDED;

    ilm_ptr = (ilm_struct *)allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = MOD_L4C;
    ilm_ptr->sap_id = INVALID_SAP;
    ilm_ptr->msg_id = (msg_type) MSG_ID_MMI_NW_SET_GPRS_CONNECT_TYPE_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct*) myMsgPtr;
    ilm_ptr->peer_buff_ptr = NULL;
    msg_send_ext_queue(ilm_ptr);  
}

/******************************************************************************
 *  Function    -  track_drv_network_license_gprs_attach_rsp
 * 
 *  Purpose     -  GPRS附着响应 
 * 
 *  Description -  MOD工程裁剪，L4C收到了设置请求后，但不返回结果，因此该函数不会被执行! 
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 02-04-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_network_license_gprs_attach_rsp(void *msg)
{
    nw_set_gprs_connect_type_rsp_struct *gprs_type=(nw_set_gprs_connect_type_rsp_struct *)msg;

    LOGS("gprs_attach result=%d",gprs_type->result);    
}


void socket_send_status(kal_uint8 app, track_soc_status_enum mode, kal_int8 errorid,kal_uint8 queue_id)
{
    track_soc_Callback_struct cb = {0};
    data_copy(app, &cb);
    cb.databak = NULL;
    cb.status = mode;
    cb.errorid = errorid;
    cb.queue_id = queue_id;
    track_soc_status_callback(&cb);
}
kal_int8 socket_data_event_request(kal_uint8 app, Func_Ptr func)
{
    LOGD2(L_SOC, L_V1, "");
    soc_status[app].funcPtr = func;
    return 1;
}
