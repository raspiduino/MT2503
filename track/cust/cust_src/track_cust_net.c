/*******************************************************************************************
 * Filename:
 * Author :
 * Date :
 * Comment:
 ******************************************************************************************/

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "l4c2smsal_struct.h"

#include "track_cust.h"
/*****************************************************************************
*  Define                               宏定义
******************************************************************************/

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static kal_uint8 net_conn_status = 0;
static kal_bool Login_Information_Success = KAL_FALSE;
static kal_uint32 reconnect_count = 0, reconnect_count2 = 0;
static kal_bool isDomainLogin = KAL_FALSE;
static sockaddr_struct domainAnalysisIpAddr = {0};
static kal_bool backup_addr_link = KAL_FALSE;
static kal_uint8 Flag_Get_DynamicServer = 0;
static kal_uint8 gt02_ip_from_hostname[4];
static kal_uint32 lte_reconnect_count = 0;
static kal_uint8 packet_9104_status = 0;
static U8 g_exit_fly_mode = 0;
static kal_bool gsm_scan_network = KAL_FALSE;
static kal_bool g_net_conn_readly = 0;

#if defined(__AMS_LOG__)
static kal_uint8 last_local_ip_from_hostname[4] = {0};    // 域名解析请求返回的IP地址
extern 	void track_cust_nw_reset();
#endif
/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/
static kal_uint8 gprs_status = 1;

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/
extern nvram_importance_parameter_struct G_importance_parameter_data;

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern void track_gps_dataupload_modular(void);
extern BOOL track_terminal_sleepwork_get(void);
extern void track_cust_net_conn(void);
extern void track_cust_paket_01();
extern track_soc_connstatus_enum Socket_get_conn_status(kal_uint8 app);
extern void track_cmd_net_recv(char *data, kal_uint8 *stamp);
extern void track_soc_send(void *par);
extern void track_soc_queue_all_to_nvram(void);
extern kal_uint8 track_get_server_ip_status(void);
extern void track_set_server_ip_status(kal_uint8 flg);
extern void gprs_login_data_send(void);
extern void heartbeat_packets_cq(void);
extern kal_int8 track_cust_recv_cmd_online(char *data, int len, Cmd_Type type);
extern void information_packets(void);
extern void track_cust_paket_9404_handle(void);
extern void track_cust_server3_recv_net_cmd(kal_uint8 cmd, kal_uint8 *pdata, int packet_len);
//extern void track_cust_LBS_upload(void);
#if defined(__NF2318__)
extern void track_cust_N07_data(kal_uint8* data, kal_int32 len);
extern U8 track_is_fly(void* isflymode);
#endif

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
void track_soc_gprs_reconnect(void *arg);
void track_soc_bakup_data(void *par);

#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/


/******************************************************************************
 *  Function    -  track_cust_net_conn_first
 *
 *  Purpose     -  首次联网成功，判断是连AGPS服务器还是应用服务器
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void track_cust_net_conn_first(void)
{
    static kal_bool valid = KAL_TRUE;
    kal_uint8 i_url = strlen((char*)G_importance_parameter_data.server.url);
    LOGD(L_APP, L_V5, "%d", i_url);
    track_drv_statistics_conn_time(2);
#if defined( __NULL_SERVER__)
    if(0 == i_url)
    {
        tr_start_timer(TRACK_CUST_NET_CONN_TIMER_ID, 5000, track_cust_net_conn_first);
        return;
    }
#endif /* __NULL_SERVER__ */
    if(valid)
    {
        valid = KAL_FALSE;
        if(!track_is_testmode())
        {
            track_cust_net_conn();
            g_net_conn_readly = 1;
            track_cust_server2_file_retry();
            track_cust_server2_conn((void*)6);
        }
    }
}
#if 0
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
 * v1.1  , 14-10-2013,  wangqi  written
 * ----------------------------------------
*******************************************************************************/
static void track_cust_recv_net_cmd(kal_uint8 cmd, kal_uint8 *pdata, int packet_len)
{
    static kal_bool login1st = KAL_TRUE;
    LOGD(L_APP, L_V5, "login:%d, cmd:%X, buflen:%d, SerialNumber:%.2X%.2X",
         Login_Information_Success, cmd, packet_len, pdata[packet_len - 2], pdata[packet_len - 1]);
    if(cmd == 0x01)
    {
        tr_stop_timer(TRACK_CUST_NET_LOGIN_TIMEOUT_TIMER_ID);
        tr_stop_timer(TRACK_CUST_NET_LOGIN_RESEND_TIMER_ID);
        tr_stop_timer(TRACK_CUST_NET_CONN_BAKDATA_TIMER_ID);
        LED_GSM_StatusSet(GPRS_CONNECT_STATE);
        track_soc_conn_status(KAL_TRUE);
#if defined(__GT300S__) || defined(__GT370__)|| defined (__GT380__)
        reconnect_count = 0;
#endif
        if(!Login_Information_Success)
        {
            Login_Information_Success = KAL_TRUE;
            reconnect_count = 0;
            track_cust_gpsmode_net_new_conn();
            if(login1st)
            {
                login1st = KAL_FALSE;
                track_cust_paket_8A();//太磨叽,实际联网1分钟了才发出去  chengj
                track_cust_up_900a_handle();
#if defined (__BLE_GATT__)
                track_cust_paket_98();
#endif
#if defined(__GT740__)
                track_cust_upload_param();
                if(track_is_timer_run(TRACK_CUST_EXTCHIP_DELAY_CLOSE_TIMER_ID))
                {
                    kal_uint32 tick, sec;
                    tick = kal_get_systicks();
                    sec = kal_ticks_to_secs(tick);
                    if(sec > (MAX_RUN_TIME_MIN - 1) * 60)
                    {
                        track_cust_module_delay_close(60);
                        track_cust_send03((void*)90);
                    }
                }
#endif

            }
            track_soc_send((void*)99);
            track_soc_bakup_data((void*)2);
        }

        track_os_intoTaskMsgQueueExt(heartbeat_packets, (void *)113);//直接调用会出现透传不到4G的问题

        track_os_intoTaskMsgQueueExt(track_soc_send, (void*)9);
#if defined(__EXT_VBAT_ADC__)
        track_os_intoTaskMsgQueue(information_packets);
#endif
    }
    else if(cmd == 0x13 || cmd == 0x23)
    {
        track_cust_gprs_conn_fail((void*)1);
        track_check_tick(1, NULL);
        /*心跳数据包的服务器回应*/
        LOGD(L_APP, L_V6, "服务器响应心跳数据包");
        tr_stop_timer(TRACK_CUST_NET_HEARTBEAT_OVER_TIMER_ID);
        reconnect_count2 = 0;
#if defined(__BACKUP_SERVER__)
        if(isDomainLogin && G_importance_parameter_data.server.conecttype == 1 && !backup_addr_link)
#elif defined(__GT740__)
        if(isDomainLogin && G_importance_parameter_data.server.conecttype == 1)
#else
        if(isDomainLogin && G_importance_parameter_data.server.conecttype == 1 && memcmp(G_realtime_data.server_ip, domainAnalysisIpAddr.addr, 4))
#endif
        {
            memcpy(G_realtime_data.server_ip, domainAnalysisIpAddr.addr, 4);
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        }
        if(packet_9104_status == 0)
        {
            if(track_is_timer_run(TRACK_CUST_PACKET_94O4_DELAY_ID))
                tr_stop_timer(TRACK_CUST_PACKET_94O4_DELAY_ID);
#if defined(__PARAM_CHANGE_UPDATE_SERVER__)
            tr_start_timer(TRACK_CUST_PACKET_94O4_DELAY_ID, 60000, track_cust_paket_9404_handle);
#endif
            packet_9104_status = 1;
        }
    }
    else if(cmd == 0x16 || cmd == 0x26)
    {
        track_cust_decode_packet_16(pdata, packet_len);
    }
    else if(cmd == 0x17 || cmd == 0x1A)
    {
        /*0x17 is LBS get address ,0x1A is GPS get address ,Sever Send Chinese Address Information*/
        track_cust_decode_packet_17(pdata, packet_len);
        track_soc_send((void*)98);
    }
    else if(cmd == 0x21)
    {
        /*Online Command Set*/
        track_cust_decode_packet_21(pdata, packet_len);
    }
    else if(cmd == 0x2D || cmd == 0x2E)
    {
#if defined(__GT740__)
        /*Online Command Set*/
        if(0 == G_parameter.new_position_sw)
        {
            LOGD(L_APP, L_V4, "平台已回复新定位包，不再发送旧协议定位包!");
            G_parameter.new_position_sw = 1;
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
            //track_soc_position_clr();
        }
        else if(1 == G_parameter.new_position_sw)
        {
            if(G_parameter.extchip.mode != 1)
            {
                //track_soc_position_clr();
            }
        }
#endif /* __GT740__ */
    }
    else if(cmd == 0x80)
    {
        /*Online Command Set*/
        track_cust_decode_packet_80(pdata, packet_len);
    }
    else if(cmd == 0x8A)
    {
        track_cust_decode_packet_8A(pdata, packet_len);
    }
    else if(cmd == 0x8B)
    {
        track_cust_decode_lbs_packet(pdata, packet_len);
    }
    else if(cmd == 0x8C)
    {
    }
    else if(cmd == 0x8D)
    {
    }
#ifdef __0BD2__
    else if(cmd == 0x8F)
    {
        //track_cust_decode_packet_8F(pdata, packet_len);//wangqi编译不过
    }
#endif /* __0BD2__ */
    else if(cmd == 0x96 || cmd == 0x97 || cmd == 0x9A)
    {
        track_cust_decode_packet_97(pdata, packet_len);
    }
    else if(cmd == 0xFD)
    {
        //track_cust_decode_packet_FD(pdata, packet_len);
    }
    else if(cmd == 0xFE)
    {
        //track_cust_server2_decode_packet(pdata, packet_len);
    }

#if defined (__CUST_RS485__)
    else if(cmd == 0x9B)
    {
        track_cust_decode_packet_9B(pdata, packet_len);
    }
#endif /* __CUST_RS485__ */

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
void track_cust_recv_data(kal_uint8 *data, int len)
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
#if defined (__SAME_GT02__)
        /* GT02 旧协议心跳包特殊处理 */
        else if(buf[i] == 0x54 && buf[i + 1] == 0x68 && buf[i + 2] == 0x1A && buf[i + 3] == 0x0D && buf[i + 4] == 0x0A)
        {

            track_cust_recv_net_cmd(0x13, &buf[i], 5);
            if(Login_Information_Success == KAL_FALSE)
            {
                if(power_on)
                {
                    power_on = 0;
                    if(G_importance_parameter_data.dserver.ip_update == 0 && G_importance_parameter_data.dserver.conecttype == 1 && G_importance_parameter_data.dserver.server_type == 1)
                    {
                        memcpy(G_importance_parameter_data.dserver.server_ip, gt02_ip_from_hostname, 4);
                        G_importance_parameter_data.dserver.ip_update = 1;
                        Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
                    }
                    else if(G_importance_parameter_data.dserver.ip_update == 0 && G_importance_parameter_data.server.conecttype == 1 && G_importance_parameter_data.dserver.server_type == 0)
                    {
                        memcpy(G_importance_parameter_data.server.server_ip, gt02_ip_from_hostname, 4);
                        G_importance_parameter_data.dserver.ip_update = 1;
                        Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
                    }
                    track_cust_paket_8A();
                    track_cust_up_900a_handle();
                }
                tr_stop_timer(TRACK_CUST_NET_LOGIN_TIMEOUT_TIMER_ID);
                tr_stop_timer(TRACK_CUST_NET_LOGIN_RESEND_TIMER_ID);
                tr_stop_timer(TRACK_CUST_NET_CONN_BAKDATA_TIMER_ID);
                LED_GSM_StatusSet(GPRS_CONNECT_STATE);
                track_soc_conn_status(KAL_TRUE);
                heartbeat_packets((void *)2);//GT02这里只是用于开启心跳定时器，不做心跳发送 所以直接调用以便启动定时器track_os_intoTaskMsgQueue(heartbeat_packets);
                Login_Information_Success = KAL_TRUE;
                reconnect_count = 0;
                track_cust_gpsmode_net_new_conn();
                track_soc_send((void*)99);
                track_soc_bakup_data((void*)2);
                track_os_intoTaskMsgQueueExt(track_soc_send, (void*)9);

            }
            i += 5;
            backupbegin = i;
            flag = 0;
            continue;
        }
        else if(buf[i] == 0x88 && buf[i + 1] == 0x88)
        {
            int len_temp = buf[i + 2];
            LOGD(L_APP, L_V4, "%d,%d", len_temp, i);
            if(buf[i + len_temp + 3] == 0x0D &&  buf[i + len_temp + 4] == 0x0A)
            {
                track_cust_recv_net_cmd(0x1C, &buf[i + 3], len_temp);
            }

            i += len_temp + 5;
            backupbegin = i;
            flag = 0;
            continue;
        }
#endif /* __SAME_GT02__ */

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
            track_cust_recv_net_cmd(cmd, pdata, packet_len);

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
#endif
/******************************************************************************
 *  Function    -  packet_login
 *
 *  Purpose     -  登陆包（协议号：0x01）发送周期控制
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void packet_login(void *par)
{
    static kal_uint8 count = 0, recv_count = 0;
#if defined __GT740__
    char buf[100] = {0};
    sprintf(buf, "(E)(%d)%d,%d,%d ", (kal_get_systicks() - 0) / KAL_TICKS_1_SEC, (kal_uint32)par, count, recv_count);
#endif

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
            track_os_intoTaskMsgQueueExt(track_soc_gprs_reconnect, (void *)24);
        }
        return;
    }
    if(count < 3)
    {
        count++;
#if defined (__SAME_GT02__)
        if(G_importance_parameter_data.dserver.server_type && track_get_server_ip_status() == 0)
        {
            Send_IP_Request_data(track_drv_get_lbs_data());
        }
        else
        {
            Heartbeat_Data_Packet(NULL, NULL, NULL);
        }
#elif defined(__NF2318__)
#if defined(__EL100_XYT__)
        track_cust_packet_rabbit_8F();
#else
        track_cust_n07_packet_00();
#endif
#else
        track_cust_paket_01();
#if defined (__AMS_LOG__)
        track_cust_cache_netlink(buf, strlen(buf));
#endif
#endif /* __SAME_GT02__ */
        if(!track_is_timer_run(TRACK_CUST_NET_LOGIN_RESEND_TIMER_ID))
            track_start_timer(TRACK_CUST_NET_LOGIN_RESEND_TIMER_ID, G_parameter.ste_param.dfttimeout * 1000, packet_login, (void*)2);
        if(!track_is_timer_run(TRACK_CUST_NET_LOGIN_TIMEOUT_TIMER_ID))
            track_start_timer(TRACK_CUST_NET_LOGIN_TIMEOUT_TIMER_ID, 60000, track_soc_gprs_reconnect, (void *)25);
    }
}

kal_bool track_check_ip_corr(kal_uint8* ip_str)
{
    if(ip_str[0] != 0 && ip_str[1] != 0 && ip_str[2] != 0 && ip_str[3] != 0)
    {
        LOGD(L_SOC, L_V6, "%d.%d.%d.%d", ip_str[0], ip_str[1], ip_str[2], ip_str[3]);
        return KAL_TRUE;
    }
    return KAL_FALSE;
}
/******************************************************************************
 *  Function    -  event
 *
 *  Purpose     -  网络事件响应函数
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void event(track_soc_Callback_struct *par)
{
    static kal_uint32 re_conn = 0;
#if defined __GT740__
    char buf[100] = {0};
    //sprintf(buf,"(I)(%d),%d,%d ",(kal_get_systicks()-0)/KAL_TICKS_1_SEC,par->status, par->errorid);
#endif

    LOGD(L_APP, L_V5, "status=%d error=%d", par->status, par->errorid);
    switch(par->status)
    {
        case SOC_CONNECT_SUCCESS:
            {
                re_conn = 0;
                tr_stop_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID);
                tr_stop_timer(TRACK_CUST_NET_CONN_TIMEOUT_ID);
                tr_stop_timer(TRACK_CUST_VOICE_VERSION_UPDATE_RECONNECT_TIMER_ID);//取消语音下载后的重连
                heartbeat_packets((void *)0);
                track_os_intoTaskMsgQueueExt(packet_login, NULL);

                break;
            }
        case SOC_CONNECT_ServerNotResponding:
            {

                LED_GSM_StatusSet(GSM_NORMAL_STATE);

                if(!track_is_timer_run(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID))
                {
                    track_start_timer(TRACK_CUST_NET_CONN_TIMER_ID, 10000, track_soc_gprs_reconnect, (void*)1);
                }
                break;
            }
        case SOC_CONNECT_CLOSE:
            {
                Login_Information_Success = KAL_FALSE;
                tr_stop_timer(TRACK_LOGIN_DATA_SEND_DELAY_TIMER_ID);

                LED_GSM_StatusSet(GSM_NORMAL_STATE);

                if(re_conn < 5)
                {
                    re_conn++;

                    track_start_timer(TRACK_CUST_NET_CONN_TIMER_ID, 10000, track_soc_gprs_reconnect, (void*)1);

                }
                else if(!track_is_timer_run(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID))
                {
                    track_start_timer(TRACK_CUST_NET_CONN_TIMER_ID, 30000, track_soc_gprs_reconnect, (void*)1);
                }

#if defined (__CUST_FAKECELL__)
                track_cust_check_gprs_after_fake_cell(KAL_FALSE);
#endif /* __CUST_FAKECELL__ */

                break;
            }
        case SOC_RECV_DATA:
            {
#if defined(__NF2318__)
#if defined(__EL100_XYT__)
                track_cust_packet_rabbit_dl_parse(par->recvBuff, par->recvBuffLen);
#else
                track_cust_N07_data(par->recvBuff, par->recvBuffLen);
#endif
#else
                //track_cust_recv_data(par->recvBuff, par->recvBuffLen);
#endif

#if defined (__CUST_FAKECELL__)
                track_cust_check_gprs_after_fake_cell(KAL_TRUE);
#endif /* __CUST_FAKECELL__ */

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
                    if(par->packet_type == 1)
                        track_os_intoTaskMsgQueueExt(packet_login, (void*)1);
                }
                break;
            }
        case SOC_RECV_HOST_BY_NAME:
            {
                if(par->errorid != 0)
                {
                    static kal_uint8 count = 0;
                    LOGD(L_APP, L_V1, "errorid=%d", par->errorid);
#if defined (__AMS_LOG__)
                    sprintf(buf + strlen(buf), "(I)(%d)%d", (kal_get_systicks() - 0) / KAL_TICKS_1_SEC, par->errorid);
                    track_cust_cache_netlink(buf, strlen(buf));
#endif

                    if(count < 10 && par->errorid == -14)
                    {
                        count++;
                        track_soc_disconnect();
                        track_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID, 3000, track_soc_gprs_reconnect, (void*)4);
                    }
                    else
                    {
                        track_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID, 60000, track_soc_gprs_reconnect, (void*)1);
                    }
                }
                else
                {
                    kal_int8 ret;
#if defined(__SAME_GT02__)
                    sockaddr_struct ip_addr = {0};
                    memcpy(gt02_ip_from_hostname, par->ip_from_hostname, 4);
                    if((track_get_server_ip_status() == 0) && (G_importance_parameter_data.dserver.server_type == 1))
                    {
                        memcpy(G_importance_parameter_data.dserver.server_ip, par->ip_from_hostname, 4);
                        ip_addr.port = G_importance_parameter_data.dserver.server_port;//8442 9080 10008
                    }
                    else
                    {
                        memcpy(G_importance_parameter_data.server.server_ip, par->ip_from_hostname, 4);
                        ip_addr.port = G_importance_parameter_data.server.server_port;//8442 9080 10008
                    }
                    ip_addr.addr_len = 4;
                    memcpy(ip_addr.addr, par->ip_from_hostname, 4);
                    memcpy(domainAnalysisIpAddr.addr, par->ip_from_hostname, 4);
                    domainAnalysisIpAddr.port = ip_addr.port;//8442 9080 10008
                    Login_Information_Success = KAL_FALSE;
                    isDomainLogin = KAL_TRUE;
                    LOGD(L_APP, L_V5, "hostname to IP:%d.%d.%d.%d:%d",
                         ip_addr.addr[0], ip_addr.addr[1],
                         ip_addr.addr[2], ip_addr.addr[3],
                         ip_addr.port);
                    ret = track_soc_conn_req(&ip_addr, event, 0);
#else
#if defined (__AMS_LOG__)
                    if(last_local_ip_from_hostname[0] != par->ip_from_hostname[0]
                            || last_local_ip_from_hostname[1] != par->ip_from_hostname[1]
                            || last_local_ip_from_hostname[2] != par->ip_from_hostname[2]
                            || last_local_ip_from_hostname[3] != par->ip_from_hostname[3])
                    {
                        last_local_ip_from_hostname[0] = par->ip_from_hostname[0];
                        last_local_ip_from_hostname[1] = par->ip_from_hostname[1];
                        last_local_ip_from_hostname[2] = par->ip_from_hostname[2];
                        last_local_ip_from_hostname[3] = par->ip_from_hostname[3];
                        sprintf(buf + strlen(buf), "(I)(%d)IP:%d.%d.%d.%d:%d",
                                (kal_get_systicks() - 0) / KAL_TICKS_1_SEC,
                                par->ip_from_hostname[0], par->ip_from_hostname[1],
                                par->ip_from_hostname[2], par->ip_from_hostname[3],
                                domainAnalysisIpAddr.port);
                        track_cust_cache_netlink(buf, strlen(buf));
                    }
#endif
#if defined(__BACKUP_SERVER__)
                    if(backup_addr_link)
                    {
                        domainAnalysisIpAddr.port = G_importance_parameter_data.bserver.server_port;//8442 9080 10008
                    }
                    else
                    {
                        domainAnalysisIpAddr.port = G_importance_parameter_data.server.server_port;//8442 9080 10008
                    }
#else
                    domainAnalysisIpAddr.port = G_importance_parameter_data.server.server_port;//8442 9080 10008
#endif
                    LOGD(L_APP, L_V5, "result,hostname to IP:%d.%d.%d.%d:%d",
                         par->ip_from_hostname[0], par->ip_from_hostname[1],
                         par->ip_from_hostname[2], par->ip_from_hostname[3],
                         domainAnalysisIpAddr.port);

                    isDomainLogin = KAL_TRUE;
                    domainAnalysisIpAddr.addr_len = 4;
                    memcpy(domainAnalysisIpAddr.addr, par->ip_from_hostname, 4);
                    Login_Information_Success = KAL_FALSE;
                    ret = track_soc_conn_req(&domainAnalysisIpAddr, event, 0);
#endif
                    LOGD(L_APP, L_V5, "ret=%d", ret);
                }
                break;
            }
    }
}

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

/******************************************************************************
 *  Function    -  track_soc_bakup_data
 *
 *  Purpose     -  登陆超时处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_soc_bakup_data(void *par)
{
    static kal_int8 status = 0;
    kal_uint32 arg = (kal_uint32)par;
    LOGD(L_APP, L_V5, "%d", arg);
    if(arg == 1)
    {
        // 连接请求
        //20min仍然没有成功连接登陆系统，进行GPS数据备份至NVRAM
        if(status != 1 && !track_is_timer_run(TRACK_CUST_NET_CONN_BAKDATA_TIMER_ID))
            track_start_timer(TRACK_CUST_NET_CONN_BAKDATA_TIMER_ID, 1200000, track_soc_bakup_data, (void*)3);
        status = 1;
    }
    else if(arg == 2)
    {
        // 连接正常，并登陆成功
        tr_stop_timer(TRACK_CUST_NET_CONN_BAKDATA_TIMER_ID);
        status = 2;
    }
    else if(arg == 3)
    {
        track_soc_queue_all_to_nvram();
        if(!track_is_timer_run(TRACK_CUST_NET_CONN_BAKDATA_TIMER_ID))
            track_start_timer(TRACK_CUST_NET_CONN_BAKDATA_TIMER_ID, 300000, track_soc_bakup_data, (void*)3);
    }
}

/******************************************************************************
 *  Function    -  track_cust_net_conn
 *
 *  Purpose     -  联网请求主函数
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_net_conn(void)
{
    sockaddr_struct ip_addr = {0};
    kal_int8 ret;
    kal_uint16 crc;
    char *domain;
    kal_int8 num = 0, str_len = 0;
    char temp[50];
    kal_bool value = KAL_FALSE;
    kal_uint8 i_url = strlen((char*)G_importance_parameter_data.server.url);
    static U8 ip_conn_first = 1;
#if defined(__BACKUP_SERVER__)
    nvram_importance_parameter_struct* imp_para = &G_importance_parameter_data;
#endif
    LOGD(L_APP, L_V5, "i_url:%d", i_url);

#if defined (__NETWORK_LICENSE__)
    return;
    //禁止GPRS链接后台
#endif /* __NETWORK_LICENSE__ */
#if defined( __NULL_SERVER__)
    if(0 == i_url)
    {
        return;
    }
#endif /* __NULL_SERVER__ */

    if(track_is_testmode())
    {
        LOGD(L_APP, L_V5, "测试模式不联网");
        return;
    }

    if(track_cust_status_sim() != 1)
    {
        if(track_is_testmode())
        {
            return;
        }
        LOGD(L_APP, L_V4, "SIM卡检测有误!");
        track_cust_get_sim_status();
        tr_start_timer(TRACK_CUST_NET_CONN_TIMER_ID, 5000, track_cust_net_conn);
        return;
    }

    if(!track_cust_is_china_sales())
    {
        LOGD(L_APP, L_V4, " 国外卡直接锁定");
        return;
    }


#if defined(__FLY_MODE__)
    if(track_cust_flymode_set(198))//飞行模式中
    {
        LOGD(L_APP, L_V4, "当前正在飞行中");
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

    track_soc_bakup_data((void*)1);

    if(!G_parameter.gprson)
    {
        return;
    }
    isDomainLogin = KAL_FALSE;
    // 停止心跳包
    tr_stop_timer(TRACK_CUST_NET_HEARTBEAT_TIMER_ID);
    tr_stop_timer(TRACK_CUST_NET_HEARTBEAT_OVER_TIMER_ID);
    // 停止登陆包
    //   tr_stop_timer(TRACK_CUST_NET_LOGIN_TIMEOUT_TIMER_ID);
    tr_stop_timer(TRACK_CUST_NET_CONN_TIMER_ID);
    tr_stop_timer(TRACK_CUST_NET_LOGIN_RESEND_TIMER_ID);
    tr_stop_timer(TRACK_CUST_NET_LOGIN_TIMEOUT_TIMER_ID);
    track_soc_set_batch_paket(G_parameter.group_package.batch_paket);
#if 0
#if defined(__GUMI__)&&!defined(__SAME_GT02__)
    crc = GetCrc16(G_importance_parameter_data.server.url, strlen((char*)G_importance_parameter_data.server.url));
    LOGD(L_APP, L_V5, "%X", crc);
    if(crc == 0xE3F1/*hgt06.szdatasource.com*/ || crc == 0xB300/*www.topstargps.com*/)
    {
        track_soc_gethostbyname((char *)G_importance_parameter_data.server.url, event);
    }
#endif
#endif
//#elif defined(__NF2318__)
#if 1//defined(__NF2318__)
    LOGD(L_APP, L_V5, "realtime,IP %d.%d.%d.%d", G_realtime_data.server_ip[0], G_realtime_data.server_ip[1], G_realtime_data.server_ip[2], G_realtime_data.server_ip[3]);

    domain = track_domain_decode(G_importance_parameter_data.server.url);
    LOGD(L_APP, L_V5, "reconnect_count2=%d", reconnect_count2);
    if(G_importance_parameter_data.server.conecttype == 0
            && (G_importance_parameter_data.server.server_ip[0] != 0
                || G_importance_parameter_data.server.server_ip[1] != 0
                || G_importance_parameter_data.server.server_ip[2] != 0
                || G_importance_parameter_data.server.server_ip[3] != 0))
    {
        LOGD(L_APP, L_V5, "initiate IP Link");
        ip_addr.addr[0] = G_importance_parameter_data.server.server_ip[0]; //112
        ip_addr.addr[1] = G_importance_parameter_data.server.server_ip[1];//91
        ip_addr.addr[2] = G_importance_parameter_data.server.server_ip[2];//114
        ip_addr.addr[3] = G_importance_parameter_data.server.server_ip[3];//235
        value = KAL_TRUE;

    }
    else if(G_importance_parameter_data.server.conecttype == 1
            && ip_conn_first
            && (G_realtime_data.server_ip[0] != 0
                || G_realtime_data.server_ip[1] != 0
                || G_realtime_data.server_ip[2] != 0
                || G_realtime_data.server_ip[3] != 0))
    {
        LOGD(L_APP, L_V5, "storage IP link 1");

        ip_addr.addr[0] = G_realtime_data.server_ip[0]; //112
        ip_addr.addr[1] = G_realtime_data.server_ip[1];//91
        ip_addr.addr[2] = G_realtime_data.server_ip[2];//114
        ip_addr.addr[3] = G_realtime_data.server_ip[3];//235
        value = KAL_TRUE;
        ip_conn_first = KAL_FALSE;
        reconnect_count2 = 0;
    }
    else if(G_importance_parameter_data.server.conecttype == 1 && strlen(domain) > 0
            && (reconnect_count2 < 3
                || (G_realtime_data.server_ip[0] == 0
                    && G_realtime_data.server_ip[1] == 0
                    && G_realtime_data.server_ip[2] == 0
                    && G_realtime_data.server_ip[3] == 0)
               )
           )
    {
        LOGD(L_APP, L_V5, "initiate domain link,domain:%s", domain);
        track_soc_gethostbyname(domain, event);//"www.163.com"
        reconnect_count2++;
    }
    else
    {
        LOGD(L_APP, L_V5, "storage IP link 2");
        ip_addr.addr[0] = G_realtime_data.server_ip[0]; //112
        ip_addr.addr[1] = G_realtime_data.server_ip[1];//91
        ip_addr.addr[2] = G_realtime_data.server_ip[2];//114
        ip_addr.addr[3] = G_realtime_data.server_ip[3];//235
        value = KAL_TRUE;
        reconnect_count2 = 0;
    }
    if(value)
    {
        ip_addr.port = (unsigned short)G_importance_parameter_data.server.server_port;//8442 9080 10008
        ip_addr.addr_len = 4;
        LOGD(L_APP, L_V5, "%d.%d.%d.%d:%d ",
             ip_addr.addr[0],
             ip_addr.addr[1],
             ip_addr.addr[2],
             ip_addr.addr[3],
             G_importance_parameter_data.server.server_port);
        Login_Information_Success = KAL_FALSE;
        track_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_ID , 50 * 1000, track_soc_gprs_reconnect, (void*)4);

        ret = track_soc_conn_req(&ip_addr, event, 0);
        LOGD(L_APP, L_V5, "ret=%d", ret);
        if(ret < 0)
        {
        	tr_stop_timer(TRACK_CUST_NET_CONN_TIMEOUT_ID);
            tr_start_timer(TRACK_CUST_NET_CONN_TIMER_ID, 5000, track_cust_net_conn);
        }
    }
    else
    {
        //防止开机第一次域名解析失败，导致一直不连网的问题
        track_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_ID , 60 * 1000, track_soc_gprs_reconnect, (void*)4);
    }

#else
    domain = track_domain_decode(G_importance_parameter_data.server.url);
    LOGD(L_APP, L_V5, "reconnect_count2=%d", reconnect_count2);
#if defined(__BACKUP_SERVER__)
    backup_addr_link = KAL_FALSE;
    if(G_importance_parameter_data.server.conecttype == 0
            && (reconnect_count2 < 3 && (G_importance_parameter_data.server.server_ip[0] != 0
                                         || G_importance_parameter_data.server.server_ip[1] != 0
                                         || G_importance_parameter_data.server.server_ip[2] != 0
                                         || G_importance_parameter_data.server.server_ip[3] != 0)))
#else
    if(G_importance_parameter_data.server.conecttype == 0
            && (G_importance_parameter_data.server.server_ip[0] != 0
                || G_importance_parameter_data.server.server_ip[1] != 0
                || G_importance_parameter_data.server.server_ip[2] != 0
                || G_importance_parameter_data.server.server_ip[3] != 0))
#endif

    {
        ip_addr.addr[0] = G_importance_parameter_data.server.server_ip[0]; //112
        ip_addr.addr[1] = G_importance_parameter_data.server.server_ip[1];//91
        ip_addr.addr[2] = G_importance_parameter_data.server.server_ip[2];//114
        ip_addr.addr[3] = G_importance_parameter_data.server.server_ip[3];//235
        value = KAL_TRUE;
    }
#if defined(__BACKUP_SERVER__)
    else if(G_importance_parameter_data.server.conecttype == 1
            && ip_conn_first
            && (G_realtime_data.server_ip[0] != 0
                && G_realtime_data.server_ip[1] != 0
                && G_realtime_data.server_ip[2] != 0
                && G_realtime_data.server_ip[3] != 0))
    {
        LOGD(L_APP, L_V5, "IP %d.%d.%d.%d %d ", G_realtime_data.server_ip[0], G_realtime_data.server_ip[1], G_realtime_data.server_ip[2], G_realtime_data.server_ip[3]);
        ip_addr.addr[0] = G_realtime_data.server_ip[0]; //112
        ip_addr.addr[1] = G_realtime_data.server_ip[1];//91
        ip_addr.addr[2] = G_realtime_data.server_ip[2];//114
        ip_addr.addr[3] = G_realtime_data.server_ip[3];//235
        value = KAL_TRUE;
        ip_conn_first = KAL_FALSE;
        reconnect_count2 = 0;
    }
    else if(reconnect_count2 > 2 && ((strlen((char*)imp_para->bserver.url) > 0 && imp_para->bserver.conecttype == 1) || (imp_para->bserver.conecttype == 0 && track_check_ip_corr(imp_para->bserver.server_ip))))
    {
        if(G_importance_parameter_data.bserver.conecttype == 1)
        {
            domain = track_domain_decode(G_importance_parameter_data.bserver.url);
            LOGD(L_APP, L_V5, "domain:%s", domain);
            track_soc_gethostbyname(domain, event);//"www.163.com"
        }
        else
        {
            ip_addr.addr[0] = G_importance_parameter_data.bserver.server_ip[0]; //112
            ip_addr.addr[1] = G_importance_parameter_data.bserver.server_ip[1];//91
            ip_addr.addr[2] = G_importance_parameter_data.bserver.server_ip[2];//114
            ip_addr.addr[3] = G_importance_parameter_data.bserver.server_ip[3];//235
            ip_addr.port = (unsigned short)G_importance_parameter_data.bserver.server_port;//8442 9080 10008
            ip_addr.addr_len = 4;
            ret = track_soc_conn_req(&ip_addr, event, 0);
            LOGD(L_APP, L_V5, "ret=%d", ret);
            if(ret < 0)
            {
                tr_start_timer(TRACK_CUST_NET_CONN_TIMER_ID, 5000, track_cust_net_conn);
            }
        }
        backup_addr_link = KAL_TRUE;
        if(reconnect_count2 > 5)
        {
            reconnect_count2 = 0;
        }
    }
#endif
    else if(G_importance_parameter_data.server.conecttype == 1 && strlen(domain) > 0
            && (reconnect_count2 < 3
                || (G_realtime_data.server_ip[0] == 0
                    && G_realtime_data.server_ip[1] == 0
                    && G_realtime_data.server_ip[2] == 0
                    && G_realtime_data.server_ip[3] == 0)
               )
           )
    {
        LOGD(L_APP, L_V5, "domain:%s", domain);
        track_soc_gethostbyname(domain, event);//"www.163.com"
        //这里应该加上一个超时，要是没有解析到域名，又么有返回就重新去解析

        tr_start_timer(TRACK_CUST_NET_CONN_TIMER_ID, 15000, track_cust_net_conn);
        reconnect_count2++;
    }
    else
    {
        ip_addr.addr[0] = G_realtime_data.server_ip[0]; //112
        ip_addr.addr[1] = G_realtime_data.server_ip[1];//91
        ip_addr.addr[2] = G_realtime_data.server_ip[2];//114
        ip_addr.addr[3] = G_realtime_data.server_ip[3];//235
        value = KAL_TRUE;
        reconnect_count2 = 0;
    }
    if(value)
    {
        ip_addr.port = (unsigned short)G_importance_parameter_data.server.server_port;//8442 9080 10008
        ip_addr.addr_len = 4;
        LOGD(L_APP, L_V5, "%d.%d.%d.%d:%d",
             ip_addr.addr[0],
             ip_addr.addr[1],
             ip_addr.addr[2],
             ip_addr.addr[3],
             G_importance_parameter_data.server.server_port);
        Login_Information_Success = KAL_FALSE;
        ret = track_soc_conn_req(&ip_addr, event, 0);
        LOGD(L_APP, L_V5, "ret=%d", ret);
        if(ret < 0)
        {
            tr_start_timer(TRACK_CUST_NET_CONN_TIMER_ID, 5000, track_cust_net_conn);
        }
        else
        {
            track_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_ID , 50 * 1000, track_soc_gprs_reconnect, (void*)4);
        }
    }
    reconnect_count2++;
#endif /* __GUMI__ */
#if 0
    if(G_parameter.gprs_obstruction_alarm.sw && !track_sms_get_send_status() && !track_is_in_call() && track_cust_make_call((void*)99) == 0)
    {
        reconnect_count++;
        track_cust_module_alarm(&reconnect_count);
    }
#endif
#if defined(__AMS_LOG__)
    track_cust_cache_netlink(ams_buf, strlen(ams_buf));
#endif

}

/******************************************************************************
 *  Function    -  track_soc_gprs_reconnect
 *
 *  Purpose     -  重连处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_soc_gprs_reconnect(void *arg)
{
    static kal_uint8    reconnect_cnt = 0;
    kal_uint32 value = (kal_uint32)arg;
    track_soc_connstatus_enum conStatus = Socket_get_conn_status(0);
    kal_uint8 i_url = strlen((char*)G_importance_parameter_data.server.url);
    LOGD(L_APP, L_V5, "%d, conStatus=%d i_url:%d", value, conStatus, i_url);
    //packet_login(NULL);
#if defined(__FLY_MODE__)
    if(track_cust_flymode_set(197))
    {
        return;
    }
#endif
#if defined(__NF2318__)
    if(track_is_fly((void*)99) == 1)
    {
        LOGD(L_APP, L_V4, "深度睡眠中");
        return;
    }
    if(value == 27 || value == 28)
    {
        track_cust_login(0x01);
    }
#endif
#if defined(__NETWORK_LICENSE__)
    return;
#endif
#if defined( __NULL_SERVER__)
    if(0 == i_url)
    {
        return;
    }
#endif /* __NULL_SERVER__ */

    if(!g_net_conn_readly)
    {
        LOGD(L_APP, L_V5, "WARN: 网络未准备好!");
        return;
    }

    if(track_sms_get_send_status() || track_is_in_call())
    {
        track_start_timer(TRACK_CUST_NET_CONN_TIMER_ID, 5000, track_soc_gprs_reconnect, arg);
        LOGD(L_APP, L_V5, "当前正在拨打电话或发短信过程中，GPRS重连延后执行");
        return;
    }
#if defined (__SAME_GT02__)
    if(reconnect_cnt > 2)
    {
        if(track_get_server_ip_status())
        {
            track_set_server_ip_status(0);
        }
        reconnect_cnt = 0;
    }
    else
    {
        reconnect_cnt++;
    }
#endif /* __SAME_GT02__ */

    if(value == 1)
    {
        if(conStatus <= SOC_CONN_FAILURE)
        {
            track_cust_net_conn();
        }
        track_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID, 60000, track_soc_gprs_reconnect, (void*)308);
    }
    else if(value >= 20 && value <= 29)
    {
        if(conStatus <= SOC_CONN_FAILURE)
        {
            track_cust_net_conn();
            track_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID, 60000, track_soc_gprs_reconnect, (void*)309);
        }
        else track_soc_disconnect();
    }
    else if(value >= 300 && value <= 399)
    {
        // 连接超时
        if(conStatus != SOC_CONN_SUCCESSFUL)
        {
            track_soc_disconnect();
            track_cust_net_conn();
            track_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID, 60000, track_soc_gprs_reconnect, (void*)4);
        }
    }
    else if(value == 4)
    {
        // 强制连接
        tr_stop_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID);
        track_cust_net_conn();
    }
#if defined (__SAME_GT02__)
    else if(value == 5)
    {
        // GT02获取ip之后，进行连接的通道
        track_set_server_ip_status(1);
        tr_stop_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID);
        track_cust_net_conn();
    }
#endif /* __SAME_GT02__ */
}

/******************************************************************************
 *  Function    -  track_soc_conn_valid
 *
 *  Purpose     -  连接失败的响应函数
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_bool track_soc_conn_valid(void)
{
    if(Socket_get_conn_status(0) <= SOC_CONN_FAILURE)
        return KAL_FALSE;
    return KAL_TRUE;
}

/******************************************************************************
 *  Function    -  track_soc_login_status
 *
 *  Purpose     -  连接服务器成功且登陆数据包得到正常返回TRUE
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 05-02-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
kal_bool track_soc_login_status(void)
{
    return Login_Information_Success;
}

void track_set_login_status(kal_bool sta)
{
    Login_Information_Success = sta;
}
/******************************************************************************
 *  Function    -  track_soc_thorough_disconnect
 *
 *  Purpose     -  禁止应用逻辑重连网络，且关闭当前已经建立的连接
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 30-01-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_soc_thorough_disconnect(void)
{
    G_parameter.gprson = 0;
    track_soc_disconnect();
}

/******************************************************************************
 *  Function    -  track_soc_view_server_addr
 *
 *  Purpose     -  返回当前设置的服务器地址
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 30-01-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
char *track_soc_view_server_addr(void)
{
    static char tmp[100] = {0};
    if(G_importance_parameter_data.server.conecttype == 0)
    {
        snprintf(tmp, 100, "%d.%d.%d.%d:%d",
                 G_importance_parameter_data.server.server_ip[0], G_importance_parameter_data.server.server_ip[1],
                 G_importance_parameter_data.server.server_ip[2], G_importance_parameter_data.server.server_ip[3],
                 G_importance_parameter_data.server.server_port);
    }
    else
    {
        snprintf(tmp, 100, "%s:%d",
                 track_domain_decode(G_importance_parameter_data.server.url), G_importance_parameter_data.server.server_port);
    }
    return tmp;
}

/******************************************************************************
 *  Function    -  track_check_tick
 *
 *  Purpose     -  各种重启的保障性处理
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_check_tick(kal_uint8 st, char *outstring)
{
    static kal_uint32 next_tick = 0;
    static kal_uint32 sms_reset = 0;
    kal_uint32 tick = 0;

    tick = kal_get_systicks();
    if(st == 1 || next_tick == 0)
    {
        // 收到心跳包，重置30分钟后重启
        next_tick = tick + kal_secs_to_ticks(1800); // 1800 * KAL_TICKS_1_SEC  KAL_TICKS_1_MIN
    }
    else if(st == 2)
    {
        // 指令查询用
        sprintf(outstring, "%d,%d(%d),%d(%d)", tick, next_tick, kal_ticks_to_secs(next_tick - tick), sms_reset, kal_ticks_to_secs(sms_reset - tick));
    }
    else if(st == 3)
    {
        // 应用逻辑要求重启，延时20毫秒
        sms_reset = tick + kal_secs_to_ticks((kal_uint32)outstring);
        LOGD(L_APP, L_V5, "%d,%d(%d),%d", tick, sms_reset, kal_ticks_to_secs(sms_reset - tick), (kal_uint32)outstring);
    }
    /*else if((G_realtime_data.netLogControl & 128) == 1)
    {
        return;
    }*/
    else if(sms_reset > 0 && tick >= sms_reset)
    {
        track_cust_restart(34, 0);
    }
    else if(tick == 0)
    {
        track_cust_restart(32, 0);
    }
    else if(next_tick > 0 && tick >= next_tick && (track_is_notquit() == KAL_FALSE))
    {
        if(track_drv_get_sim_type() == 2)
        {
            LOGD(L_APP, L_V4, "白卡暂不重启");
            return;
        }

#if defined( __NULL_SERVER__)
        if(0 == strlen((char*)G_importance_parameter_data.server.url))
        {
            next_tick = tick + kal_secs_to_ticks(1800); // 1800 * KAL_TICKS_1_SEC  KAL_TICKS_1_MIN
            LOGD(L_APP, L_V4, "域名为空延时30分钟重启");
            return;
        }
#endif /* __NULL_SERVER__ */
#if defined(__GT370__) || defined (__GT380__)||defined(__GT300S__)
        if(track_cust_get_work_mode() != WORK_MODE_3 && G_parameter.gprson == 1 && !track_is_in_call() && track_cust_make_call((void*)99) == 0)
        {
            track_cust_restart(35, 0);
        }
        else
        {
            next_tick = tick + kal_secs_to_ticks(1800); // 1800 * KAL_TICKS_1_SEC  KAL_TICKS_1_MIN
        }
#else
#if defined(__FLY_MODE__)
        if(!track_cust_flymode_set(196) && G_parameter.gprson == 1 && !track_is_in_call() && track_cust_make_call((void*)99) == 0)
#elif defined(__NF2318__)
        if(G_parameter.ste_status.lease == 0 && G_realtime_data.sleep != 16 && G_parameter.gprson == 1 && !track_is_in_call() && track_cust_make_call((void*)99) == 0 && track_getIsDownLoadFile() == 0)
#else
        if(G_parameter.gprson == 1 && !track_is_in_call() && track_cust_make_call((void*)99) == 0)
#endif
        {
            track_cust_restart(35, 0);
        }
        else
        {
            next_tick = tick + kal_secs_to_ticks(1800); // 1800 * KAL_TICKS_1_SEC  KAL_TICKS_1_MIN
        }
#endif
    }
}

kal_bool  track_soc_gprs_attach_status(kal_uint8 op)
{
    static kal_bool gprs_status = KAL_FALSE;
    if(gprs_status != 99)
    {
        gprs_status =  op;
    }
    return gprs_status;
}

/******************************************************************************
 *  Function    -  track_soc_nw_attach_ind
 *
 *  Purpose     -  搜网成功响应处理函数
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 29-07-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_soc_nw_attach_ind(void *msg)
{
    static kal_uint32 limited_service_tick = 0;
    static kal_uint8 first = 1;
    mmi_nw_attach_ind_struct *nw_attach_ind = (mmi_nw_attach_ind_struct*)msg;
    kal_uint32 tick = 0;
    char *imsi;
#if defined(__AMS_LOG__)
    static U8 last_ind_status = 99;
    static U8 last_ind_gprs_status = 99;
    char buf[20];
    if(first != 3)
    {
        if(last_ind_status != nw_attach_ind->status || last_ind_gprs_status != nw_attach_ind->gprs_status)
        {
            if(last_ind_status == 99)
            {
                sprintf(buf, "(K)(0)%d,%d ", nw_attach_ind->status, nw_attach_ind->gprs_status);
            }
            else
            {
                sprintf(buf, "(K)(%d)%d,%d ", (kal_get_systicks() - 0) / KAL_TICKS_1_SEC, nw_attach_ind->status, nw_attach_ind->gprs_status);
            }
            track_cust_cache_netlink(buf, strlen(buf));
            last_ind_status = nw_attach_ind->status;
            last_ind_gprs_status = nw_attach_ind->gprs_status;

        }
    }

#endif

    tick = kal_get_systicks();
    LOGD(L_APP, L_V4, "status:%d, %d, %d, %d", nw_attach_ind->status, nw_attach_ind->gprs_status, first, g_exit_fly_mode);

    if(nw_attach_ind->status == L4C_RAC_OK && nw_attach_ind->gprs_status == L4C_GPRS_ATTACHED)
    {
        gsm_scan_network = KAL_TRUE;
    }
    else
    {
        gsm_scan_network = KAL_FALSE;
    }

#if defined( __NETWORK_LICENSE__)
    if(nw_attach_ind->status == L4C_RAC_OK && first == 1)
    {
        first = 2;
        track_drv_network_license_gprs_attach_req(); // GPRS附着
    }
    LOGD(L_APP, L_V5, "track_soc_nw_attach_ind __NETWORK_LICENSE__ return");
    return;
#endif /* __NETWORK_LICENSE__ */

    if(nw_attach_ind->status == L4C_RAC_LIMITED_SERVICE)
    {
#if !defined (__GT740__)
        if(tick < KAL_TICKS_1_MIN * 3) return;//????
#endif
        if(track_is_testmode())
        {
            return;
        }
        if(limited_service_tick == 0)
        {
            limited_service_tick = tick;
            track_cust_sim_restart((void*)0);
            LOGD(L_APP, L_V5, "OK! Restart the SIM card after 60 seconds...");
        }
        else if(tick > limited_service_tick + KAL_TICKS_1_MIN * 3)
        {
            if(G_realtime_data.restart_system_limited_service < 3)
            {
                G_realtime_data.restart_system_limited_service++;
                Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
                // 不等待20分钟联网失败检测，关喂狗信号，等待152重启
                if((G_realtime_data.netLogControl & 128) == 0)
                {
                    track_cust_restart(63, 0);
                }
            }
        }
    }
    else if(nw_attach_ind->status < L4C_RAC_SEARCHING)
    {
        limited_service_tick = 0;
    }
    if(nw_attach_ind->status == L4C_RAC_OK)
    {
        track_cust_sim_restart((void*)99);

        imsi = (char *)track_drv_get_imsi(0);
        if(strcmp(imsi, "000000000000000") == 0)
        {
            LOGD(L_APP, L_V4, "SIM卡异常后恢复重读IMSI");
            track_read_imsi_data();
        }

        if(G_realtime_data.restart_system_limited_service != 0)
        {
            G_realtime_data.restart_system_limited_service = 0;
            Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
        }
        if(first == 1)
        {
            first = 2;
            track_cust_eind();
            track_socket_apn_auto_set();
            track_drv_network_license_gprs_attach_req(); // GPRS附着
            tr_start_timer(TRACK_GPRS_ATTACHED_OVERTIME_TIMER, 15000, track_cust_net_conn_first);
        }
        if(first == 2 && nw_attach_ind->gprs_status == L4C_GPRS_ATTACHED)
        {

#if defined(__GT740__)
            track_stop_timer(TRACK_CUST_EXTCHIP_NW_RESET_TIMER_ID);
            if(G_realtime_data.nw_reset_sign != 0)
            {
                G_realtime_data.nw_reset_sign = 0;
                Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
            }
#endif
            first = 3;
            track_stop_timer(TRACK_GPRS_ATTACHED_OVERTIME_TIMER);
            track_cust_net_conn_first();
            track_soc_gprs_attach_status(1);
        }
#if defined(__FLY_MODE__)
        if(first == 3 && g_exit_fly_mode == 1)
        {
            g_exit_fly_mode = 0;
            track_soc_gprs_reconnect((void*)310);
            //track_os_intoTaskMsgQueue(track_cust_LBS_upload);
        }
#endif /* __FLY_MODE__ */
#if defined(__NF2318__)
        if(track_is_fly((void*)99) == 1 && first == 3 && g_exit_fly_mode == 1)
        {
            g_exit_fly_mode = 0;
            track_is_fly((void*)0);
            track_soc_gprs_reconnect((void*)310);
        }
#endif
    }

#if defined(__GT740__)
    if(G_parameter.extchip.mode != 1 && !track_is_testmode())
    {
        if(!track_is_timer_run(TRACK_CUST_EXTCHIP_NW_RESET_TIMER_ID) && (nw_attach_ind->status != L4C_RAC_OK) && (nw_attach_ind->gprs_status != L4C_GPRS_ATTACHED) && (track_cust_get_rssi(-1) != 99) && track_cust_status_sim())
        {
            if(G_realtime_data.nw_reset_sign > 0)
            {
                track_cust_gps_off_req((void*)6);
            }
            tr_start_timer(TRACK_CUST_EXTCHIP_NW_RESET_TIMER_ID, 3 * 60 * 1000, track_cust_nw_reset);
        }
    }
#endif
}

kal_bool track_cust_soc_scan_network()
{
    return gsm_scan_network;
}

void track_soc_exit_fly_only(void)
{
    g_exit_fly_mode = 1;
}

/******************************************************************************
 *  Function    -  Send_IP_Request_data
 *
 *  Purpose     -  LBS数据接收的回调函数
 *
 *  Description -  NULL
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 06-12-2010,  Cml  written
 * ----------------------------------------
 ******************************************************************************/
void Send_IP_Request_data(LBS_Multi_Cell_Data_Struct *lbs_data)
{
    S32 ret = -1;
    kal_uint8 lbsfulldata[40];
    LBS_Full_Packet(lbs_data, lbsfulldata, 28);
    track_soc_write_req(lbsfulldata, 28, 1, 0);
}


void track_set_server_ip_status(kal_uint8 flg)
{
    Flag_Get_DynamicServer = flg;
}

kal_uint8 track_get_server_ip_status(void)
{
    return Flag_Get_DynamicServer;
}

/*************************************************/
/************GT02B旧协议逻辑**************/
/*************************************************/
/******************************************************************************
 *  Function    -  Analysis_ServerData
 *
 *  Purpose     -  解析谷米服务器收到的数据,从中获得IP地址和端口
 *
 *  Description -  NULL
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 06-12-2010,  Cml  written
 * ----------------------------------------
 ******************************************************************************/
#if 0//defined(__SAME_GT02__)
void Analysis_ServerData(kal_uint8*data, int len)
{
    kal_uint16 crc;
    char i = 0;
    LOGD(L_APP, L_APP, "");
    if(data[0] != 0x78 || data[1] != 0x78)
    {
    }
    else if(data[len - 2] != 0x0D || data[len - 1] != 0x0A)
    {
    }
    else if(data[2] != len - 5)
    {
    }
    else
    {
        crc = GetCrc16(&data[2], len - 6);   //--CRC校验--
        if(data[len - 4] != ((crc >> 8) & 0x00FF) || data[len - 3] != (crc & 0x00FF))
        {
        }
        else
        {
            i = 4;
            G_importance_parameter_data.server.server_ip[0] = data[i++];
            G_importance_parameter_data.server.server_ip[1] = data[i++];
            G_importance_parameter_data.server.server_ip[2] = data[i++];
            G_importance_parameter_data.server.server_ip[3] = data[i++];
            G_importance_parameter_data.server.conecttype = 0;
            G_importance_parameter_data.server.soc_type = 0;
            G_importance_parameter_data.server.server_port = ((U16)(data[i] * 256)) + data[++i];
            LOGD(L_APP, L_V5, "Analysis_ServerData()  get dynamic IP [%d.%d.%d.%d:%d]",
                 G_importance_parameter_data.server.server_ip[0],
                 G_importance_parameter_data.server.server_ip[1],
                 G_importance_parameter_data.server.server_ip[2],
                 G_importance_parameter_data.server.server_ip[3],
                 G_importance_parameter_data.server.server_port);

            track_set_server_ip_status(1);
            track_stop_timer(TRACK_SERVER_OVERTIME_TIMER);
            track_soc_gprs_reconnect((void*)5);
            return;
        }
    }
    if(!track_is_timer_run(TRACK_SERVER_OVERTIME_TIMER))
    {
        track_start_timer(TRACK_SERVER_OVERTIME_TIMER, 2 * 60 * 1000, track_soc_gprs_reconnect, (void*)4); // 请求服务器回复超时
    }
}
#endif
void track_soc_view_IP(char *out)
{

    snprintf(out, 300, "isDomainLogin:%d,IP:%d.%d.%d.%d:%d",
             isDomainLogin,
             domainAnalysisIpAddr.addr[0], domainAnalysisIpAddr.addr[1],
             domainAnalysisIpAddr.addr[2], domainAnalysisIpAddr.addr[3],
             domainAnalysisIpAddr.port);
}
kal_uint8* track_soc_get_IP(void)
{
    static kal_uint8 out[100] = {0};
    snprintf(out, 100, "GET IP:%d.%d.%d:%d",
             domainAnalysisIpAddr.addr[0], domainAnalysisIpAddr.addr[1],
             domainAnalysisIpAddr.addr[2], domainAnalysisIpAddr.addr[3]);
    return out;
}
void track_soc_reset_reconnect_count2(void)
{
    reconnect_count2 = 0;
}

char *track_soc_ip_from_domain(void)
{
    static char tmp[100] = {0};
    snprintf(tmp, 100, "%d.%d.%d.%d",
             domainAnalysisIpAddr.addr[0], domainAnalysisIpAddr.addr[1],
             domainAnalysisIpAddr.addr[2], domainAnalysisIpAddr.addr[3]);
    return tmp;
}
/******************************************************************************
 *  Function    -  track_cust_ip_addr_link
 * 
 *  Purpose     -  7号单车IP存储
 * 
 *  Description -  NULL
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2019-07-20,  Liujw  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_ip_addr_link()
{
    LOGD(L_APP, L_V4, "storage ip,%d", isDomainLogin);
    reconnect_count2 = 0;
    if(isDomainLogin && G_importance_parameter_data.server.conecttype == 1 && memcmp(G_realtime_data.server_ip, domainAnalysisIpAddr.addr, 4))
    {
        LOGD(L_APP, L_V4, "ip,2",);
        memcpy(G_realtime_data.server_ip, domainAnalysisIpAddr.addr, 4);
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    }
}

