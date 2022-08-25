/*******************************************************************************************
 * Filename:
 * Author :
 * Date :
 * Comment:
 ******************************************************************************************/

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "track_cust.h"
#include "c_vector.h"
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
    kal_uint8   buffer[MAX_SND_BUFFER_SIZE];
    int         status; /* 状态:  0 等待中  ;   1 正在发送 */
    int         len;
    kal_uint32  no;
    kal_uint8   packet_type;              // 数据包类型
    kal_uint8   lock;                     // 正在发送数据时避免进行删除
} vec_gprs_socket_send_struct;
/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static nvram_check_ota_struct g_otacheck = {0};
kal_uint8 G_ip_from_hostname[20] = {0};
static c_vector* vec_send_queue = NULL;
static kal_uint32 reconnect_count3 = 0;
static kal_bool heartbeat_packets_need_send = KAL_FALSE;
static kal_bool Login_Information_Success = KAL_FALSE;
static void track_cust_server3_heartbeat_packets(void);
extern void track_cust_server3_reconnect(void *arg);

#if defined(__LUYING__)
static c_vector* vec_send_audio_queue = NULL;
static kal_bool Login4_Information_Success = KAL_FALSE;
extern void track_cust_paket_server4_01(void);
extern void track_cust_stop_server4_conn(void);
#endif//(__LUYING__)

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern void track_cust_server2_login(void);
extern void track_cust_server2_exit(void *arg);
extern void track_cust_server3_conn(void);
extern void track_cust_server3_queue_send_reg(kal_uint8* data, int len, kal_uint8 packet_type, kal_uint32 no);
#if defined(__GT740__)
extern void track_resend_amslog();
#endif

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
void track_cust_server2_conn(void *arg);
static void send_data(void *par);
kal_int8 track_cust_server2_write_req(U8 type, kal_uint8 *data, kal_int32 datalen,U8 packet_type);
#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/
static void track_cust_recv_net_cmd2(kal_uint8 cmd, kal_uint8 *pdata, int packet_len)
{
    LOGD(L_APP, L_V5, "cmd:%X, buflen:%d, SerialNumber:%.2X%.2X",
         cmd, packet_len, pdata[packet_len - 2], pdata[packet_len - 1]);
    if(cmd == 0xFD)
    {
        track_cust_decode_packet_FD(pdata, packet_len);
    }
    else if(cmd == 0xFE)
    {
    }
}

static void track_cust_recv_data2(kal_uint8 *data, int len)
{
    static kal_uint8 *buf = NULL;
    static int buflen = 0;
    kal_uint8 cmd = 0, *pdata = NULL, *tmp = NULL;
    kal_uint16 packet_len = 0;
    int len_size = 0, i = 0, j, flag = 1, backupbegin = -1;

    if(buf == NULL)
    {
        buf = (U8*)Ram_Alloc(6, 11264);
        if(buf == NULL)
        {
            LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
            track_cust_restart(64, 0);
            return;
        }
    }

    if(buflen < 0) buflen = 0;
    if(buflen + len >= 11264)
    {
        LOGD(L_APP, L_V4, "%d,%d 接收数据异常", len, buflen);
        buflen = 0;
        return;
    }
    memcpy(&buf[buflen], data, len);
    buflen += len;
    while(buflen - i > 0)
    {
        if(buf[i] == 0x79 && buf[i + 1] == 0x79)
        {
            len_size = 2;
            flag = 1;
        }
        /*else if(buf[i] == 0x78 && buf[i + 1] == 0x78 && buf[i + 4] == 0x97)
        {
            len_size = 2;
            flag = 1;
        }*/
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
                LOGD(L_APP, L_V4, "len=%d, buflen=%d,%d 不能解析的数据包(无法确定数据包的起点) !!!!", len, buflen, i);
                LOGH(L_APP, L_V6, &buf[i], buflen - i);
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
                LOGD(L_APP, L_V4, "len=%d, i=%d, buflen=%d, packet_len=%d 不能解析的数据包(未完整接收整包长度) !!!!", len, i, buflen, packet_len);
                LOGH(L_APP, L_V9, &buf[i], buflen - i);
                flag = 0;
                i++;
                continue;
            }
            if(buf[i + packet_len + len_size + 2] != 0x0D || buf[i + packet_len + len_size + 3] != 0x0A)
            {
                LOGD(L_APP, L_V4, "buflen=%d,%d,%d,%d 不能解析的数据包(无法确定数据包的结束点) !!!!", buflen, i, packet_len, len_size);
                LOGH(L_APP, L_V6, &buf[i], buflen - i);
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
            if(!IsDataCrc16(&buf[i + 2], packet_len + len_size))
            {
                LOGD(L_APP, L_V1, "crc error");
                LOGH(L_APP, L_V4, &buf[i], buflen - i);
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
            //LOGD(L_APP, L_V5, "cmd:%X, buflen:%d, SerialNumber:%.2X%.2X", cmd, packet_len, pdata[packet_len - 2], pdata[packet_len - 1]);
            track_cust_recv_net_cmd2(cmd, pdata, packet_len);
            backupbegin = i;
        }
    }
    if(backupbegin > 0 && buflen > 0)
    {
        buflen -= backupbegin;
        if(buflen > 0 && buflen < 5120)
        {
            tmp = (U8*)Ram_Alloc(6, buflen);
            memcpy(tmp, &buf[backupbegin], buflen);
            memcpy(buf, tmp, buflen);
            Ram_Free(tmp);
        }
        return;
    }
}

static void event2(track_soc_Callback_struct *par)
{
    static kal_uint32 re_conn = 0;
    extern kal_int8 track_cust_paket_agps_lbs(void);

    LOGD(L_APP, L_V5, "status=%d error=%d packet_type %x", par->status, par->errorid,par->packet_type);
    switch(par->status)
    {
        case SOC_CONNECT_SUCCESS:
            {
                LOGD(L_APP, L_V4, "{%02d-%02d-%02d} Count:%d/%d, Day:%d/%d",
                     g_otacheck.dateCount[0] + 2000, g_otacheck.dateCount[1], g_otacheck.dateCount[2],
                     g_otacheck.resetCount, g_otacheck.resetCountMax,
                     g_otacheck.resetDay, g_otacheck.resetDayMax);
#if defined(__AMS_HEX_LOG__)
                track_cust_ams_updata(0);
#endif
                if(g_otacheck.resetCountMax > 0 && g_otacheck.resetDayMax > 0)
                {
                    /*控制连接次数*/
                    kal_bool isChange = KAL_FALSE;
                    applib_time_struct tmpDate = {0};
                    applib_dt_get_rtc_time(&tmpDate);
                    if(tmpDate.nYear > 0)
                    {
                        tmpDate.nYear = tmpDate.nYear % 100;
                    }
                    LOGD(L_APP, L_V5, "%02d-%02d-%02d", tmpDate.nYear, tmpDate.nMonth, tmpDate.nDay);
                    if(g_otacheck.dateCount[0] == tmpDate.nYear
                            && g_otacheck.dateCount[1] == tmpDate.nMonth
                            && g_otacheck.dateCount[2] == tmpDate.nDay)
                    {
                        if(g_otacheck.resetCount < g_otacheck.resetCountMax)
                        {
                            g_otacheck.resetCount++;
                            isChange = KAL_TRUE;
                        }
                        else
                        {
                            track_stop_timer(TRACK_CUST_NET_CONN_TIMER_ID2);
                            socket_disconnect(1);
                            LOGD(L_APP, L_V4, "满足限制条件，不连AMS服务器");
                            return;
                        }
                    }
                    else
                    {
                        if(g_otacheck.resetCount < g_otacheck.resetCountMax)
                        {
                            g_otacheck.resetCount = 1;
                            g_otacheck.resetDay = 1;
                            g_otacheck.dateCount[0] = tmpDate.nYear;
                            g_otacheck.dateCount[1] = tmpDate.nMonth;
                            g_otacheck.dateCount[2] = tmpDate.nDay;
                            isChange = KAL_TRUE;
                        }
                        else if(g_otacheck.resetDay < g_otacheck.resetDayMax)
                        {
                            g_otacheck.resetCount = 1;
                            g_otacheck.resetDay++;
                            g_otacheck.dateCount[0] = tmpDate.nYear;
                            g_otacheck.dateCount[1] = tmpDate.nMonth;
                            g_otacheck.dateCount[2] = tmpDate.nDay;
                            isChange = KAL_TRUE;
                        }
                        else
                        {
                            track_stop_timer(TRACK_CUST_NET_CONN_TIMER_ID2);
                            socket_disconnect(1);
                            LOGD(L_APP, L_V4, "满足限制条件，不连AMS服务器");
                            return;
                        }
                    }
                    if(isChange)
                    {
                        Track_nvram_write(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
                    }
                }
                re_conn = 0;
                track_cust_server2_write_req(0, NULL, 0xFFFFFFFF,0);
                track_os_intoTaskMsgQueueExt(track_cust_server2_login, NULL);
                break;
            }
        case SOC_CONNECT_ServerNotResponding:
            {
                /*if(!track_is_timer_run(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID))
                {
                    track_start_timer(TRACK_CUST_NET_CONN_TIMER_ID, 5000, track_soc_gprs_reconnect, (void*)1);
                }*/
#if defined(__AMS_HEX_LOG__)
                track_cust_ams_updata(0);
#endif
                break;
            }
        case SOC_CONNECT_CLOSE:
            {
#if defined(__AMS_HEX_LOG__)
                track_cust_ams_updata(0);
#endif
                if(track_cust_server2_status_retry())
                {
                    track_cust_server2_file_retry();
                    track_os_intoTaskMsgQueueExt(track_cust_server2_conn, (void*)7);
                }
                track_cust_server2_write_req(0, NULL, 0xFFFFFFFF,0);
                /*if(re_conn < 5)
                {
                    re_conn++;
                    track_start_timer(TRACK_CUST_NET_CONN_TIMER_ID, 3000, track_soc_gprs_reconnect, (void*)1);
                }
                else if(!track_is_timer_run(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID))
                {
                    track_start_timer(TRACK_CUST_NET_CONN_TIMER_ID, 30000, track_soc_gprs_reconnect, (void*)1);
                }*/
                break;
            }
        case SOC_RECV_DATA:
            {
                track_cust_recv_data2(par->recvBuff, par->recvBuffLen);
                break;
            }
        case SOC_SEND_DATA:
            {
                if(par->errorid != 0)
                {
                    LOGD(L_APP, L_V1, "ERROR!!! id=%d", par->errorid);
                }
                else
                {
#if defined(__AMS_HEX_LOG__)
                if(G_realtime_data.AMS_HEX_sw_log == 1 && track_os_file_log_get_block() > 0&&track_cust_ams_updata(0xff))
               {
                    track_os_file_log_send();
               }
#endif

#if defined (__GT740__)
                    if(par->packet_type == 0x09)
                        track_os_intoTaskMsgQueue(track_resend_amslog);
#endif

                }
                break;
            }
        case SOC_RECV_HOST_BY_NAME:
            {
                if(par->errorid != 0)
                {
                    static kal_uint8 count = 0;
                    LOGD(L_APP, L_V1, "errorid=%d", par->errorid);
                    if(count < 10 && par->errorid == -14)
                    {
                        count++;
                        socket_disconnect(1);
                        //track_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID, 3000, track_soc_gprs_reconnect, (void*)4);
                    }
                    else
                    {
                        //track_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID, 60000, track_soc_gprs_reconnect, (void*)1);
                    }
                }
                else
                {
                    sockaddr_struct ip_addr = {0};
                    kal_int8 ret;
                    ip_addr.port = G_importance_parameter_data.server2.server_port;//8442 9080 10008
                    LOGD(L_APP, L_V5, "hostname to IP:%d.%d.%d.%d:%d",
                         par->ip_from_hostname[0], par->ip_from_hostname[1],
                         par->ip_from_hostname[2], par->ip_from_hostname[3],
                         ip_addr.port);
                    ip_addr.addr_len = 4;
                    memcpy(ip_addr.addr, par->ip_from_hostname, 4);
                    memcpy(G_ip_from_hostname, par->ip_from_hostname, 4);
                    ret = Socket_conn_req(1, &ip_addr, event2, 0);
                    LOGD(L_APP, L_V5, "ret=%d", ret);
                }
                break;
            }
    }
}

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
void track_cust_server2_check(kal_uint8 flg)
{
    static kal_uint8 cnt = 0;
    LOGD(L_APP, L_V5, "cnt=%d", cnt);
    if(flg == 0)
    {
        cnt = 0;
        return;
    }
    if(cnt == 0XFF)
    {
        return;
    }
    if(track_cust_server2_conn_status())
    {
        cnt = 0XFF; //规定时间连接成功清零，已经链接成功过
        tr_stop_timer(TRACK_CUST_NET2_CHECK_TIMER_ID);
    }
    else if(cnt > 2)
    {
        cnt = 0; //规定时间内3次没有获取服务器数据，不在用这个域名继续链接
        tr_stop_timer(TRACK_CUST_NET2_CHECK_TIMER_ID);
        track_cust_server2_exit((void *)15);
    }
    else
    {
        cnt++;  //小于3次没获取到数据，继续链接SERVER2
        track_start_timer(TRACK_CUST_NET2_CHECK_TIMER_ID, 60000, track_cust_server2_conn, (void*)8);
        socket_disconnect(1);
    }
}
void track_cust_server2_conn(void *arg)
{
    sockaddr_struct ip_addr = {0};
    kal_int8 ret;
    kal_uint16 crc;
    kal_int8 num = 0, str_len = 0;
    char temp[50];

    LOGD(L_APP, L_V5, "%d", (U32)arg);

#if defined (__NETWORK_LICENSE__)
    return;
    //禁止GPRS链接后台
#endif /* __NETWORK_LICENSE__ */
    if(track_cust_status_sim() != 1)
    {
        if(track_is_testmode())
        {
            return;
        }
        LOGD(L_APP, L_V4, "SIM卡检测有误!");
        track_cust_get_sim_status();
        track_start_timer(TRACK_CUST_NET_CONN_TIMER_ID2, 5000, track_cust_server2_conn, (void*)9);
        return;
    }
    if((g_GT03D && track_cust_gprson_status(99) == 0) || !G_parameter.gprson)
    {
        LOGD(L_APP, L_V5, " 不联网");
        return;
    }
    if(track_is_timer_run(TRACK_CUST_NET2_CHECK_TIMER_ID))
    {
        LOGD(L_APP, L_V5, " 前一个链接未结束");
        return;
    }
    if(G_importance_parameter_data.server2.conecttype >= 10)
    {
        LOGD(L_APP, L_V5, " ams关闭");
        return;
    }

#if defined(__FLY_MODE__)
    if(track_cust_flymode_set(195))//飞行模式中
    {
        LOGD(L_APP, L_V4, "当前正在飞行中");
        track_start_timer(TRACK_CUST_NET_CONN_TIMER_ID2, 300000, track_cust_server2_conn, (void*)10);
        return;
    }
#endif /* __FLY_MODE__*/
#if defined(__NF2318__)
	if(track_is_fly((void*)99) == 1)
	{
		LOGD(L_APP, L_V4, "深度睡眠中");
		return;
	}
#endif
#if !defined(__GT740__)
    {
        Track_nvram_read(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
        LOGD(L_APP, L_V4, "{%02d-%02d-%02d} Count:%d/%d, Day:%d/%d",
             g_otacheck.dateCount[0] + 2000, g_otacheck.dateCount[1], g_otacheck.dateCount[2],
             g_otacheck.resetCount, g_otacheck.resetCountMax,
             g_otacheck.resetDay, g_otacheck.resetDayMax);
        if(g_otacheck.resetCountMax > 0 && g_otacheck.resetDayMax > 0)
        {
            /*控制连接次数*/
            applib_time_struct tmpDate = {0};
            applib_dt_get_rtc_time(&tmpDate);
            if(tmpDate.nYear > 0)
            {
                tmpDate.nYear = tmpDate.nYear % 100;
            }
            LOGD(L_APP, L_V5, "%02d-%02d-%02d", tmpDate.nYear, tmpDate.nMonth, tmpDate.nDay);
            if(g_otacheck.dateCount[0] == tmpDate.nYear
                    && g_otacheck.dateCount[1] == tmpDate.nMonth
                    && g_otacheck.dateCount[2] == tmpDate.nDay)
            {
                if(g_otacheck.resetCount >= g_otacheck.resetCountMax)
                {
                    track_stop_timer(TRACK_CUST_NET_CONN_TIMER_ID2);
                    socket_disconnect(1);
                    LOGD(L_APP, L_V4, "满足限制条件，不连AMS服务器");
                    return;
                }
            }
            else
            {
                if(g_otacheck.resetCount >= g_otacheck.resetCountMax
                        && g_otacheck.resetDay >= g_otacheck.resetDayMax)
                {
                    track_stop_timer(TRACK_CUST_NET_CONN_TIMER_ID2);
                    socket_disconnect(1);
                    LOGD(L_APP, L_V4, "满足限制条件，不连AMS服务器");
                    return;
                }
            }
        }
    }
#endif
    track_cust_server2_check(0xff);

    if(G_importance_parameter_data.server2.conecttype == 1)
    {
        char *domain = track_domain_decode(G_importance_parameter_data.server2.url);
        LOGD(L_APP, L_V5, "domain:%s", domain);
        Socket_gethostbyname(domain, event2);
    }
    else if(G_importance_parameter_data.server2.conecttype == 0)
    {
        memcpy(ip_addr.addr, G_importance_parameter_data.server2.server_ip, 4);
        ip_addr.port = (unsigned short)G_importance_parameter_data.server2.server_port;
        ip_addr.addr_len = 4;
        LOGD(L_APP, L_V5, "%d.%d.%d.%d:%d",
             ip_addr.addr[0],
             ip_addr.addr[1],
             ip_addr.addr[2],
             ip_addr.addr[3],
             ip_addr.port);
        ret = Socket_conn_req(1, &ip_addr, event2, 0);
        LOGD(L_APP, L_V5, "ret=%d", ret);
        if(ret < 0)
        {
            track_start_timer(TRACK_CUST_NET_CONN_TIMER_ID2, 5000, track_cust_server2_conn, (void*)11);
        }
    }
}

static void resend(void *pt)
{
	U8 op = (U8)pt;
    track_cust_server2_write_req(0, NULL, 0,(U8)op);
}
kal_int8 track_cust_server2_write_req(U8 type, kal_uint8 *data, kal_int32 datalen,U8 packet_type)
{
    static U8 buf[2048];
    static int len = 0;
    kal_int8 ret;
    LOGD(L_SOC, L_V5, "type:%d, len:%d, data:%X, datalen:%X", type, len, data, datalen);
    if(len == 0 && datalen == 0) return;
    if(datalen == 0xFFFFFFFF)
    {
        len = 0;
        track_stop_timer(TRACK_CUST_NET2_RESEND_TIMER_ID);
        return -11;
    }
    if(track_cust_status_sim() != 1)
    {
        return;
    }
#if defined(__FLY_MODE__)
    if(track_cust_flymode_set(194))//飞行模式中
    {
        LOGD(L_APP, L_V4, "当前正在飞行中");
        return;
    }
#endif /* __FLY_MODE__*/
    if(len + datalen >= 2047)
    {
        LOGD(L_SOC, L_V1, "ERROR : %d,%d", len, datalen);
        len = 0;
        if(datalen >= 2047) datalen = 2047;
    }
    if(datalen > 0)
    {
        LOGH(L_SOC, L_V7, data, datalen);
        memcpy(&buf[len], data, datalen);
        len += datalen;
    }
    if(type == 1) return 0;
    track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 60000, track_cust_server2_exit, (void *)14);
    ret = Socket_write_req(1, buf, len, 0, packet_type, 0, 1);
    if(ret == 0)
    {
        len = 0;
    }
    else if(ret == -4)
    {
        track_start_timer(TRACK_CUST_NET2_RESEND_TIMER_ID, 500, resend,(void*)packet_type);
    }
    else
    {
        LOGD(L_SOC, L_V1, "ERROR : %d", ret);
    }
    return 0;
}
void track_cust_server2_disconnect(void)
{
    track_cust_server2_write_req(0, NULL, 0xFFFFFFFF,0);
    socket_disconnect(1);
}

void track_cust_lte_recv_data2(kal_uint8 *data, int len)
{
    track_cust_recv_data2(data, len);
}

void track_lte_event2_recv(track_soc_Callback_struct *par)
{
    event2(par);
}
/*****************************************************************************
*  Global Functions                     
******************************************************************************/


/*录音上报开启server4，上传完成后断开       --    chengjun  2017-09-27*/
#if defined(__LUYING__)
extern void track_cust_server4_reconnect(void *arg);
extern void track_cust_server4_conn(void);

static void track_cust_recv4_net_cmd(kal_uint8 cmd, kal_uint8 *pdata, int packet_len)
{
    static kal_uint8 flg = 0;
    LOGD(L_APP, L_V5, "login:%d, cmd:%X, buflen:%d, SerialNumber:%.2X%.2X",
         Login4_Information_Success, cmd, packet_len, pdata[packet_len - 2], pdata[packet_len - 1]);
    if(cmd == 0x01)
    {
        if(!Login4_Information_Success)
        {
            Login4_Information_Success = KAL_TRUE;
            tr_stop_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID4);
            track_stop_timer(TRACK_CUST_NET4_LOGIN_TIMEOUT_TIMER_ID);
            track_stop_timer(TRACK_CUST_NET4_LOGIN_RESEND_TIMER_ID);
            track_stop_timer(TRACK_LY_TIMEOUT_TEIMER_ID);
            track_os_intoTaskMsgQueueExt(send_data, (void*)0);
        }
    }

    else if(cmd == 0x8C)
    {
    }
    else if(cmd == 0x8D)
    {
        track_os_intoTaskMsgQueueExt(send_data, (void*)1);
        LOGD(L_APP, L_V5, "收到录音回复包");
    }

    else if(cmd == 0xFD)
    {
    }
    else if(cmd == 0xFE)
    {
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
void track_cust_recv4_data(kal_uint8 *data, int len)
{
    static kal_uint8 *buf = NULL;
    static int buflen = 0;
    static int power_on = 1;
    kal_uint8 cmd = 0, *pdata = NULL, *tmp = NULL;
    kal_uint16 packet_len = 0;
    int len_size = 0, i = 0, j, flag = 1, backupbegin = -1;

    if(buf == NULL)
    {
        buf = (U8*)Ram_Alloc(5, 11264);
        if(buf == NULL)
        {
            LOGD(L_APP, L_V1, "ERROR: Ram_Alloc");
            return;
        }
    }

    if(buflen < 0) buflen = 0;
    if(buflen + len >= 11264)
    {
        LOGD(L_APP, L_V4, "%d,%d 接收数据异常", len, buflen);
        buflen = 0;
        return;
    }
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
            if((buf[i + 4] == 0x97 || buf[i + 4] == 0x9A) && buf[i + 2] < buflen - i && buf[buf[i + 2] + 3] != 0x0D && buf[buf[i + 2] + 4] != 0x0A)
            {
                len_size = 2;
            }
            else
            {
                len_size = 1;
            }
            flag = 1;
        }
        else
        {
            if(flag)
            {
                flag = 0;
                LOGD(L_APP, L_V4, "len=%d, buflen=%d,%d 不能解析的数据包3 !!!!", len, buflen, i);
                LOGH(L_APP, L_V4, &buf[i], buflen - i);
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
                LOGD(L_APP, L_V4, "len=%d, i=%d, buflen=%d, packet_len=%d 不能解析的数据包1 !!!!", len, i, buflen, packet_len);
                LOGH(L_APP, L_V4, &buf[i], buflen - i);
                flag = 0;
                i++;
                continue;
            }
            if(buf[i + packet_len + len_size + 2] != 0x0D || buf[i + packet_len + len_size + 3] != 0x0A)
            {
                LOGD(L_APP, L_V4, "buflen=%d ,i=%d,packet_len=%d,len_size=%d,buf[1]=%x,buf[2]=%x不能解析的数据包2 !!!!", buflen, i, packet_len, len_size, buf[i + packet_len + len_size + 3], buf[i + packet_len + len_size + 2]);
                LOGH(L_APP, L_V4, &buf[i], buflen - i);
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
            if(!IsDataCrc16(&buf[i + 2], packet_len + len_size))
            {
                LOGD(L_APP, L_V1, "crc error");
                LOGH(L_APP, L_V4, &buf[i], buflen - i);
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
            //LOGD(L_APP, L_V5, "cmd:%X, buflen:%d, SerialNumber:%.2X%.2X", cmd, packet_len, pdata[packet_len - 2], pdata[packet_len - 1]);
            track_cust_recv4_net_cmd(cmd, pdata, packet_len);
            backupbegin = i;
        }
    }
    if(backupbegin > 0 && buflen > 0)
    {
        buflen -= backupbegin;
        if(buflen > 0 && buflen < 5120)
        {
            tmp = (U8*)Ram_Alloc(5, buflen);
            memcpy(tmp, &buf[backupbegin], buflen);
            memcpy(buf, tmp, buflen);
            Ram_Free(tmp);
        }
        return;
    }
    //buflen = 0;
}


static void server4_packet_login(void *par)
{
    static kal_uint8 count = 0, recv_count = 0;

    LOGD(L_APP, L_V5, "par=%d, count=%d, recv_count=%d", (kal_uint32)par, count, recv_count);
    if(par == NULL)
    {
        recv_count = 0;
        count = 0;
    }
    else if((U32)par == 1)
    {
        recv_count++;
        if(recv_count == 4)
        {
            track_os_intoTaskMsgQueueExt(track_cust_server4_reconnect, (void*)7);
        }
        return;
    }
    if(count < 3)
    {
        count++;
        track_cust_paket_server4_01();
        if(!track_is_timer_run(TRACK_CUST_NET4_LOGIN_RESEND_TIMER_ID))
            track_start_timer(TRACK_CUST_NET4_LOGIN_RESEND_TIMER_ID, 10000, track_cust_paket_server4_01, (void*)2);
        if(!track_is_timer_run(TRACK_CUST_NET4_LOGIN_TIMEOUT_TIMER_ID))
            track_start_timer(TRACK_CUST_NET4_LOGIN_TIMEOUT_TIMER_ID, 30000, track_cust_server4_reconnect, (void*)6);
    }
}

void track_cust_server4_disconnect(void)
{
    socket_disconnect(2);
}

void track_cust_stop_server4_conn(void)
{
    tr_stop_timer(TRACK_CUST_NET_CONN_TIMER_ID4);
    tr_stop_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID4);
    tr_stop_timer(TRACK_LY_TIMEOUT_10min_TEIMER_ID);
    track_stop_timer(TRACK_CUST_NET4_LOGIN_TIMEOUT_TIMER_ID);
    track_stop_timer(TRACK_CUST_NET4_LOGIN_RESEND_TIMER_ID);
    track_stop_timer(TRACK_CUST_NET_STOP_CONN_TIMER_ID4);
    track_cust_server4_disconnect();
    if(track_get_audio_queue() != 0 && !track_is_timer_run(TRACK_CUST_NET_STOP_CONN_TIMER_ID4))
    {
        tr_start_timer(TRACK_CUST_NET_STOP_CONN_TIMER_ID4, 60 * 60000, track_cust_server4_conn);
    }
}

static void event4(track_soc_Callback_struct *par)
{
    static kal_uint32 re_conn = 0;

    LOGD(L_APP, L_V5, "status=%d error=%d", par->status, par->errorid);
    switch(par->status)
    {
        case SOC_CONNECT_SUCCESS:
            {
                Login4_Information_Success = KAL_FALSE;
                re_conn = 0;
                tr_stop_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID4);

                track_os_intoTaskMsgQueueExt(server4_packet_login, NULL);
                break;
            }
        case SOC_CONNECT_ServerNotResponding:
            {
                if(!track_is_timer_run(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID4))
                {
                    tr_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID4, 5000, track_cust_server4_conn);
                }
                break;
            }
        case SOC_CONNECT_CLOSE:
            {
                LOGD(L_APP, L_V5, "连接4关闭");
                Login4_Information_Success = KAL_FALSE;
                if((track_get_audio_queue() == 0) && track_cust_is_recording() == 0 || (!track_is_timer_run(TRACK_LY_TIMEOUT_10min_TEIMER_ID)))
                {
                    LOGD(L_APP, L_V5, "连接4关闭");
                    track_cust_stop_server4_conn();
                    return;
                }
                if(re_conn < 10)
                {
                    re_conn++;
                    tr_start_timer(TRACK_CUST_NET_CONN_TIMER_ID4, 3000, track_cust_server4_conn);
                }
                else if(!track_is_timer_run(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID4))
                {
                    tr_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID4, 30000, track_cust_server4_conn);
                }
                break;
            }
        case SOC_RECV_DATA:
            {
                //track_cust_recv_data2(par->recvBuff, par->recvBuffLen);
                LOGH(L_APP, L_V5, par->recvBuff, par->recvBuffLen);

                track_cust_recv4_data(par->recvBuff, par->recvBuffLen);
                break;
            }
        case SOC_SEND_DATA:
            {
                if(par->errorid != 0)
                {
                    LOGD(L_APP, L_V1, "ERROR!!! id=%d", par->errorid);
                }
                else
                {
                    LOGD(L_APP, L_V5, "录音上传成功!!! id=%d", par->errorid);
                }
                break;
            }
        case SOC_RECV_HOST_BY_NAME:
            {
                if(par->errorid != 0)
                {
                    static kal_uint8 count = 0;
                    LOGD(L_APP, L_V1, "errorid=%d", par->errorid);
                    if(count < 10 && par->errorid == -14)
                    {
                        count++;
                        socket_disconnect(2);
                        tr_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID4, 3000, track_cust_server4_conn);//4
                    }
                    else
                    {
                        tr_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID4, 30000, track_cust_server4_conn);//1
                    }
                }
                else
                {
                    sockaddr_struct ip_addr = {0};
                    kal_int8 ret;
                    ip_addr.port = G_importance_parameter_data.server4.server_port;
                    LOGD(L_APP, L_V5, "hostname to IP:%d.%d.%d.%d:%d",
                         par->ip_from_hostname[0], par->ip_from_hostname[1],
                         par->ip_from_hostname[2], par->ip_from_hostname[3],
                         ip_addr.port);
                    ip_addr.addr_len = 4;
                    memcpy(ip_addr.addr, par->ip_from_hostname, 4);
                    ret = Socket_conn_req(2, &ip_addr, event4, 0);
                    LOGD(L_DRV, L_V1, "ret=%d", ret);
                }
                break;
            }
    }
}

static void send_data(void *par)
{
    vec_gprs_socket_send_struct *buf = NULL;
    kal_uint32 tt = (U32)par;
    //kal_int8 ret = 0;//Socket_get_status(2);
    kal_int8 ret = Socket_get_write_status(2);
    int size;
    LOGD(L_APP, L_V5, "");
    if(Login4_Information_Success == KAL_FALSE)
    {
        LOGD(L_APP, L_V5, "Login_Information_Success:%d", Login_Information_Success);
        return;
    }
    if(ret && Login4_Information_Success)
    {
        LOGD(L_APP, L_V5, "Error : %d, Login_Information_Success:%d", ret, Login4_Information_Success);
        //正在写,不能并发
        track_start_timer(TRACK_CUST_NET4_RESEND_TIMER_ID, 5000, send_data, 0);
        return;
    }
    if(NULL == vec_send_audio_queue)
    {
        VECTOR_CreateInstance(vec_send_audio_queue);
    }
    if(tt == 1)
    {
        size = VECTOR_Size(vec_send_audio_queue);
        if(size <= 0)
        {
            LOGD(L_APP, L_V5, "Warning: 1 size=0");
            return;
        }
        VECTOR_Erase2(vec_send_audio_queue, 0, 1, KAL_FALSE);
    }

    size = VECTOR_Size(vec_send_audio_queue);
    if(size <= 0)
    {
        LOGD(L_APP, L_V5, "Warning: 2 size=0");
        return;
    }
    buf = VECTOR_At(vec_send_audio_queue, 0);
    if(!buf)
    {
        LOGD(L_APP, L_V5, "Error : VECTOR_At is NULL");
        return;
    }
    buf->lock = 1;
    Socket_write_req(2, buf->buffer, buf->len, 0, buf->packet_type, buf->no, 1);
    track_start_timer(TRACK_CUST_NET4_RESEND_TIMER_ID, 30000, send_data, 0);
}

int track_get_audio_queue(void)
{
    if(NULL == vec_send_audio_queue)
    {
        VECTOR_CreateInstance(vec_send_audio_queue);
    }
    return VECTOR_Size(vec_send_audio_queue);
}
void track_cust_server4_queue_send_reg(kal_uint8* data, int len, kal_uint8 packet_type, kal_uint32 no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ret;
    vec_gprs_socket_send_struct* buf;
    int v_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LOGD(L_SOC, L_V5,  "data_len=%d, packet_type=%X", len, (U8)packet_type);

#if defined (__NETWORK_LICENSE__)
    return;
#endif /* __NETWORK_LICENSE__ */
    if(NULL == vec_send_audio_queue)
    {
        VECTOR_CreateInstance(vec_send_audio_queue);
    }
    if(len > MAX_SND_BUFFER_SIZE || len <= 0)
    {
        LOGD(L_SOC, L_V5,  "数据长度超出范围");
        return;
    }
    else
    {
        v_size = VECTOR_Size(vec_send_audio_queue);
        if(v_size >= 100)
        {
            LOGD(L_SOC, L_V1, "内存报警队列数值已经满%d条，删除早期数据，保留最新数据!!!", v_size);
            VECTOR_Erase2(vec_send_audio_queue, 0, 50, KAL_TRUE);
        }
        buf = (vec_gprs_socket_send_struct*)Ram_Alloc(3, sizeof(vec_gprs_socket_send_struct));
        if(buf)
        {
            buf->status = 0;
            memcpy(buf->buffer , data , len);
            buf->len = len;
            buf->no = no;
            buf->packet_type = packet_type;
            VECTOR_PushBack(vec_send_audio_queue, buf);
        }
        else
        {
            LOGD(L_SOC, L_V1, "Ram_Alloc 申请临时内存空间失败!!!");
            track_cust_restart(22, 0);
        }
        track_os_intoTaskMsgQueueExt(send_data, (void*)0);
    }
}

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
void track_cust_server4_conn(void)
{
    sockaddr_struct ip_addr = {0};
    kal_int8 ret;
    kal_uint16 crc;
    char *domain;

    LOGD(L_APP, L_V5, "Server4联网");

#if defined (__NETWORK_LICENSE__)
    return;
    //禁止GPRS链接后台
#endif /* __NETWORK_LICENSE__ */
    if(NULL == vec_send_audio_queue)
    {
        VECTOR_CreateInstance(vec_send_audio_queue);
    }

    if(track_cust_status_sim() != 1)
    {
        if(track_is_testmode())
        {
            return;
        }
        LOGD(L_APP, L_V4, "SIM卡检测有误!");
        track_cust_get_sim_status();
        tr_start_timer(TRACK_CUST_NET_CONN_TIMER_ID4, 5000, track_cust_server4_conn);
        return;
    }

    if(!G_parameter.gprson)
    {
        LOGD(L_APP, L_V5, " 不联网");
        return;
    }
    tr_stop_timer(TRACK_CUST_NET_HEARTBEAT_TIMER_ID4);
    tr_stop_timer(TRACK_CUST_NET_HEARTBEAT_OVER_TIMER_ID4);

    domain = track_domain_decode(G_importance_parameter_data.server4.url);
    if(G_importance_parameter_data.server4.conecttype == 1 && strlen(domain) > 0)
    {
        LOGD(L_APP, L_V5, "domain:%s", domain);
        Socket_gethostbyname(domain, event4);
    }
    else
    {
        ip_addr.addr[0] = G_importance_parameter_data.server4.server_ip[0]; //112
        ip_addr.addr[1] = G_importance_parameter_data.server4.server_ip[1];//91
        ip_addr.addr[2] = G_importance_parameter_data.server4.server_ip[2];//114
        ip_addr.addr[3] = G_importance_parameter_data.server4.server_ip[3];//235
        ip_addr.port = (unsigned short)G_importance_parameter_data.server4.server_port;//8442 9080 10008
        ip_addr.addr_len = 4;
        LOGD(L_APP, L_V5, "%d.%d.%d.%d:%d",
             G_importance_parameter_data.server4.server_ip[0],
             G_importance_parameter_data.server4.server_ip[1],
             G_importance_parameter_data.server4.server_ip[2],
             G_importance_parameter_data.server4.server_ip[3],
             G_importance_parameter_data.server4.server_port);
        //Login_Information_Success = KAL_FALSE;
        ret = Socket_conn_req(2, &ip_addr, event4, 0);
        LOGD(L_APP, L_V5, "ret=%d", ret);
        if(ret < 0)
        {
            tr_start_timer(TRACK_CUST_NET_CONN_TIMER_ID4, 5000, track_cust_server4_conn);
        }
    }
    tr_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID4, 30000, track_cust_server4_conn);
}

void track_cust_server4_queue_init(void)
{
    if(NULL == vec_send_audio_queue)
    {
        VECTOR_CreateInstance(vec_send_audio_queue);
    }
}
void track_cust_server4_reconnect(void *arg)
{
    kal_uint32  value = (kal_uint32)arg;
    track_soc_connstatus_enum conStatus = Socket_get_conn_status(2);
    LOGD(L_APP, L_V5, "value=%d,%d", value, conStatus);

    // 连接超时
    if(value > 4)
    {
        if(conStatus <= SOC_CONN_FAILURE)
        {
            track_cust_server4_conn();
            track_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID4, 30000, track_cust_server4_reconnect, (void*)3);
        }
        else track_cust_server4_disconnect();
    }
    else if(value == 3)
    {
        if(conStatus != SOC_CONN_SUCCESSFUL)
        {
            track_cust_server4_conn();
            track_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID4, 30000, track_cust_server4_reconnect, (void*)4);
        }
    }
    else if(value == 4)
    {
        // 强制连接
        tr_stop_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID4);
        track_cust_server4_conn();
    }
}
kal_bool track_soc_server4_login_status(void)
{
    return Login4_Information_Success;
}
#endif

