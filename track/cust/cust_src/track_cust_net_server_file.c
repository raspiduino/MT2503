/*******************************************************************************************
 * Filename:
 * Author :
 * Date :
 * Comment:

    错误代码	错误类型	说明
    01	成功	　
    02	CRC校验失败	CRC错误
    03	包长度错误	包长度与实际长度不符
    04	包类型错误	数据包类型
    05	文件类型错误	例如服务器无此服务
    06	IMEI无效	数据库中无此终端IMEI
    07	芯片ID无效	数据库中无此终端芯片ID
    08	芯片ID与IMEI不匹配	例如数据库中芯片ID与IMEI不匹配
    09	软件版本号无效	例如数据库中无此软件版本号
    0A	文件识别码错误	例如终端请求文件识别码服务器没有此文件
    0B	数据包长度错误	例如文件长度为102,数据请求长度为103
    0C	请求文件开始位置错误	例如文件长度为102,数据开始位置为103
    0D	未登录发送请求文件	例如未收到登录包或链接断开后收到文件请求
    0E	未登录发送分割文件请求	例如未收到登录包或链接断开后收到文件分割请求
    0F	未发送请求文件发送分割文件请求	例如未收到文件请求后收到文件分割请求
    10	数据包错误	例包头不为 79 79
    11	服务器繁忙	例服务器繁忙无法提供服务
    12	服务器文件过期	服务器文件一天有效期，如过期服务器返回错误代码
    13	LBS解析错误	查询不到该LBS信息
    14	未登录发送LBS请求	不需要更新发送OTA文件请求
    15	不需要更新发送OTA文件请求	不需要更新发送OTA文件请求

 ******************************************************************************************/

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "track_cust.h"
#include "Track_drv_gps_drive.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/
#define REQ_BUFFER_SIZE                   14336

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static kal_uint32 start_time_tick = 0;
static kal_int32  retry = 0;
static kal_uint8  updatefiletype = 0;
static kal_uint8  nowUpdateFile = 0;  /* 1:AGPS   2:OTA/OBD   7:PARAM */
static kal_uint8  updateforagpsfile = 0;
static kal_uint8  file_check_type = 0;
static kal_uint8  *buf = NULL;
static kal_uint8  _filetype = 0;
static kal_uint16 req_size = 0, recv_size = 0;
static kal_uint32 file_size = 0, file_offset = 0, file_flag = 0;
static kal_uint8  file_flag_old = 0;
static kal_uint16 file_crc = 0;
static kal_uint8  file_md5[16] = {0};
static kal_uint32 tick_time = 0;
static kal_uint8  g_conn_status = 0;
static kal_uint8  param_crc[2] = {0};
static kal_uint8  mserver_cnt = 0;
kal_uint8 is_rev_data = 0;//只要收到数据，多域名不起作用

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern void track_socket_check_apn_diskdata(void);

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/

#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/
static void DataToHex(char *ptr, void * buff, int size)
{
    char *ptr1;
    int i = 0, j;
    ptr1 = (char*)buff;

    if(size <= 0)
    {
        return;
    }
    while(i < size)
    {
        sprintf(ptr, "%0.2X", *ptr1);
        ptr += 2;
        ptr1++;
        i++;
    }
}
int track_cust_data_write_to_file(char *file_path, U8 *data, U32 len)
{
    FS_HANDLE fp = NULL;
    WCHAR FilePath[60] = {0};
    U32 writelen;
    int fs_result, ret;

    kal_wsprintf(FilePath, file_path);
    fp = FS_Open(FilePath, FS_READ_WRITE | FS_CREATE);
    if(fp < 0)
    {
        LOGD(L_APP, L_V5, "FS_Open %d", fs_result);
        return fp;
    }
    fs_result = FS_Seek(fp, 0, FS_FILE_BEGIN);
    if(fs_result < FS_NO_ERROR)
    {
        FS_Close(fp);
        LOGD(L_APP, L_V5, "FS_Seek %d", fs_result);
        return fs_result;
    }
    while(len > 0)
    {
        if(len > 50000)
        {
            fs_result = FS_Write(fp, data, 50000, &writelen);
        }
        else
        {
            fs_result = FS_Write(fp, data, len, &writelen);
        }
        if(fs_result < FS_NO_ERROR)
        {
            FS_Close(fp);
            LOGD(L_APP, L_V5, "fs_result:%d, %d, %d", fs_result, len, writelen);
            ret = FS_Delete(FilePath);
            LOGD(L_APP, L_V5, "2 FS_Delete=%d", ret);
            return fs_result;
        }
        FS_Commit(fp);
        len -= writelen;
        if(len > 0)
        {
            data += writelen;
        }
    }
    FS_GetFileSize(fp, &writelen);
    LOGD(L_APP, L_V5, "%s文件写入FAT, 大小:%d", file_path, writelen);//"EPO文件写入FAT大小:%d"
    FS_Close(fp);
    return 0;
}
S32 track_cust_get_data_from_file(char *file_path, U8 *data, U32 len)
{
    FS_HANDLE fp = NULL;
    WCHAR FilePath[60] = {0};
    U32 filelen, readsize;
    int fs_result;

    kal_wsprintf(FilePath, file_path);
    fp = FS_Open(FilePath, FS_READ_ONLY);
    if(fp < 0)
    {
        LOGD(L_APP, L_V5, "FS_Open %d", fp);
        return fp;
    }
    FS_GetFileSize(fp, &filelen);
    if(filelen > len)
    {
        FS_Close(fp);
        LOGD(L_APP, L_V5, "filelen:%d, len:%d", filelen, len);
        return -4;
    }
    len = filelen;
    fs_result = FS_Seek(fp, 0, FS_FILE_BEGIN);
    if(fs_result < FS_NO_ERROR)
    {
        FS_Close(fp);
        LOGD(L_APP, L_V5, "FS_Seek %d", fs_result);
        return fs_result;
    }
    while(len > 0)
    {
        if(len > 50000)
        {
            fs_result = FS_Read(fp, data, 50000, &readsize);
        }
        else
        {
            fs_result = FS_Read(fp, data, len, &readsize);
        }
        if(fs_result < FS_NO_ERROR)
        {
            FS_Close(fp);
            LOGD(L_APP, L_V5, "fs_result:%d, %d, %d", fs_result, readsize, len);
            return fs_result;
        }
        len -= readsize;
        data += readsize;
    }
    FS_Close(fp);
    return filelen;
}

static void save_md5_to_file(kal_uint8 *src)
{
    FS_HANDLE fp = NULL;
    WCHAR FilePath[60] = {0};
    kal_uint32 writelen;
    int fs_result;
    kal_uint8 data[50] = {0};

    DataToHex(data, src, 16);
    LOGD(L_APP, L_V5, "%s", data);
    OTA_kal_wsprintf(FilePath, MD5_FILE_PATH);
    OTA_FS_Delete(FilePath);
    fp = OTA_FS_Open(FilePath, FS_READ_WRITE | FS_CREATE);
    if(fp < 0)
    {
        OTA_FS_Close(fp);
        LOGD(L_APP, L_V5, "fp:%d", fp);
        return;
    }
    fs_result = OTA_FS_Seek(fp, 0, FS_FILE_BEGIN);
    if(fs_result < FS_NO_ERROR)
    {
        OTA_FS_Close(fp);
        LOGD(L_APP, L_V5, "fs_result:%d", fs_result);
        return;
    }
    fs_result = OTA_FS_Write(fp, data, 32, &writelen);
    OTA_FS_Commit(fp);
    OTA_FS_GetFileSize(fp, &writelen);
    LOGD(L_APP, L_V5, "MD5文件写入FAT大小:%d", writelen);
    OTA_FS_Close(fp);
    return;
}

/******************************************************************************
 *  Function    -  track_cust_server2_exit
 *
 *  Purpose     -  退出AGPS更新流程
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 11-06-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_server2_exit(void *arg)
{
    nvram_importance_parameter_struct importancer_data;
    nvram_check_ota_struct  ota_tmp;
    extern kal_uint8 G_ip_from_hostname[];
    extern void track_cust_server2_conn(void *arg);

    LOGD(L_APP, L_V5, "%d,%d,%d,%d", (U32)arg, g_conn_status, retry, mserver_cnt);

    if(retry == -1)
    {
        return;
    }
    if(is_rev_data == 0)
    {
        if(mserver_cnt < 4)
        {
            memcpy(&G_importance_parameter_data.server2, &G_importance_parameter_data.mserver2[mserver_cnt], sizeof(nvram_server_addr_struct));
            LOGD(L_APP, L_V5, " 启用第 %d个SERVER", mserver_cnt + 1);
            track_cust_server2_check(0);
            mserver_cnt++;
            retry = 0;
            track_cust_server2_disconnect();
            track_stop_timer(TRACK_CUST_SERVER2_RESEND_TIMER);
            track_start_timer(TRACK_CUST_NET_CONN_TIMER_ID2, 1000, track_cust_server2_conn, (void*)12);
            return;
        }
        else
        {
            tr_stop_timer(TRACK_CUST_NET2_CHECK_TIMER_ID);
        }
    }
    else
    {
        if(mserver_cnt == 0)
        {
            if(G_importance_parameter_data.server2.conecttype == 1)
            {
                memcpy(G_importance_parameter_data.server2.server_ip, G_ip_from_hostname, 4);
                G_importance_parameter_data.server2.conecttype = 0;
                //先干掉存储Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
                LOGD(L_APP, L_V5, "保存ip");
            }
            else
            {
                LOGD(L_APP, L_V5, "SERVER2不改变");
            }
        }
        else
        {

            Track_nvram_read(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&importancer_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);

            if(memcmp(&importancer_data.mserver2[mserver_cnt - 1], &importancer_data.server2, sizeof(nvram_server_addr_struct)) != 0 && G_importance_parameter_data.server2.conecttype < 10)
            {

                memcpy(&G_importance_parameter_data.server2, &importancer_data.mserver2[mserver_cnt - 1], sizeof(nvram_server_addr_struct));
                if(G_importance_parameter_data.server2.conecttype == 1)
                {
                    memcpy(G_importance_parameter_data.server2.server_ip, G_ip_from_hostname, 4);
                    G_importance_parameter_data.server2.conecttype = 0;
                    G_importance_parameter_data.server2.server_port = importancer_data.mserver2[mserver_cnt - 1].server_port;
                    LOGD(L_APP, L_V5, "保存第%d 个域名解析的ip", mserver_cnt);
                }
                else
                {
                    LOGD(L_APP, L_V5, "保存第%d 个ip", mserver_cnt);
                }
                //先干掉存储Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
                Track_nvram_read(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&ota_tmp, NVRAM_EF_CHECK_OTA_SIZE);
                if(G_importance_parameter_data.server2.conecttype)
                {
                    memcpy(ota_tmp.server, &G_importance_parameter_data.mserver2[mserver_cnt - 1].url, 100);
                }
                else
                {
                    snprintf(ota_tmp.server, 100, "%d.%d.%d.%d",
                             G_importance_parameter_data.server2.server_ip[0],
                             G_importance_parameter_data.server2.server_ip[1],
                             G_importance_parameter_data.server2.server_ip[2],
                             G_importance_parameter_data.server2.server_ip[3]);
                }
                ota_tmp.port = G_importance_parameter_data.mserver2[mserver_cnt - 1].server_port;
                Track_nvram_write(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&ota_tmp, NVRAM_EF_CHECK_OTA_SIZE);

            }
        }
    }
    if((U32)arg != 6)
    {
        retry = -1; /*本次请求彻底退出*/
        g_conn_status = 0;
        track_stop_timer(TRACK_CUST_NET2_CHECK_TIMER_ID);
        track_stop_timer(TRACK_CUST_NET_CONN_TIMER_ID2);
    }

    track_cust_server2_disconnect();

    track_stop_timer(TRACK_CUST_SERVER2_RESEND_TIMER);
    track_stop_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER);
    //track_cust_agps_status(0);
}

/******************************************************************************
 *  Function    -  track_cust_server2_login
 *
 *  Purpose     -  连接成功AGPS更新服务器后需要发送的登陆数据包
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 11-06-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
void track_cust_server2_login(void)
{
    LOGD(L_APP, L_V5, "retry:%d", retry);
    track_cust_paket_terminal_ID();
    if(retry < 3 && retry != -1)
    {
        retry++;
        tr_start_timer(TRACK_CUST_SERVER2_RESEND_TIMER, 10000, track_cust_server2_login);
    }
    else
    {
        track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 60 * 1000, track_cust_server2_exit, (void *)1);
    }
}

/******************************************************************************
 *  Function    -  resend_FE_02
 *
 *  Purpose     -  发送EPO文件请求
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 11-06-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void resend_FE_02(kal_uint32 filetype)
{
    LOGD(L_APP, L_V5, "retry:%d,%d,%d", retry, _filetype, filetype);
    if(filetype > 0 || (filetype == 0 && _filetype > 0))
    {
        if(filetype > 0) _filetype = filetype;
        if(retry < 2)
        {
            track_cust_paket_epo_file_head(_filetype);
            retry++;
            track_start_timer(TRACK_CUST_SERVER2_RESEND_TIMER, 10000, resend_FE_02, NULL);
        }
        else
        {
            track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)2);
        }
    }
}

U32 resend_rety()
{
    return retry;
}

static void resend_FE_03()
{
    LBS_Multi_Cell_Data_Struct *lbs = track_drv_get_lbs_data();
    LOGD(L_APP, L_V5, "");
    if(retry < 2)
    {
        if(lbs->MainCell_Info.mcc == 0 && lbs->MainCell_Info.mnc == 0 && lbs->MainCell_Info.lac == 0)
        {
            LOGD(L_APP, L_V1, "异常：基站信息为0");
        }
        else
        {
            track_cust_paket_lbs();
        }
        retry++;
        tr_start_timer(TRACK_CUST_SERVER2_RESEND_TIMER, 10000, resend_FE_03);
    }
    else
    {
        LOGD(L_APP, L_V5, " 基站转经纬度获取失败");
        if(updateforagpsfile & 0x02) /* 基站转经纬度获取失败，获取EPO文件 */
        {
#if defined(__ZKE_EPO__)
            nowUpdateFile = 8;
#else
            nowUpdateFile = 1;
#endif
            resend_FE_02(nowUpdateFile); // 请求EPO文件
        }
        else
        {
            /*2503平台使用的GPS是内置的，AGPS功能也是独立实现的*/
            if(updatefiletype != 0)
            {
                nowUpdateFile = 2;
                resend_FE_02(nowUpdateFile);
            }
            else
            {
                track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)3);
            }
        }
    }
}

/******************************************************************************
 *  Function    -  resend_FE_04
 *
 *  Purpose     -  请求EPO文件的局部数据块
 *
 *  Description -  NULL
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 11-06-2013,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void resend_FE_04(void)
{
    LOGD(L_APP, L_V5, "_filetype:%d, retry:%d, file_size:%d, file_offset:%d, req_size:%d", _filetype, retry, file_size, file_offset, req_size);
    if(_filetype > 0 && file_offset < file_size)
    {
        if(file_offset + REQ_BUFFER_SIZE > file_size)
        {
            req_size = file_size - file_offset + 1;
        }
        else
        {
            req_size = REQ_BUFFER_SIZE;
        }
        if(retry < 5)
        {
            track_cust_paket_epo_file_content(_filetype, file_flag, file_offset, req_size);
            retry++;
            tr_start_timer(TRACK_CUST_SERVER2_RESEND_TIMER, 30000, resend_FE_04);
        }
        else
        {
            track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)4);
        }
    }
}

kal_uint8 track_cust_ota_update(kal_uint8 st)
{
    static U8 ota = 0;
    if(st == 0 || st == 1)
    {
        ota = st;
    }
    LOGD(L_UART, L_V7, "OTA Update Status %d st %d", ota, st);
    return ota;
}

static void recv_login(kal_uint8 *data, kal_uint16 len)
{
    static mtk_param_epo_time_cfg epo_time = {0};
    kal_uint8 req_result, i;
    static kal_uint8 flg = 0;

#ifdef __GT300S__
    extern   void track_send_07(void);
#endif /* __GT300S__ */

    LOGD(L_APP, L_V4, "%d", len);
    LOGH(L_APP, L_V6, data, len);
    i = 2;
    epo_time.u2YEAR  = 2000 + data[i++];
    epo_time.u1MONTH = data[i++];
    epo_time.u1DAY   = data[i++];
    epo_time.u1HOUR  = data[i++];
    epo_time.u1MIN   = data[i++];
    epo_time.u1SEC   = data[i++];
    track_fun_update_time_to_system(3, (applib_time_struct *)(&epo_time));

#if defined(__NF2318__)//开锁状态下，不升级
	if(G_parameter.ste_status.lease == 1 || (track_cust_vehicle_moving(11) & 6) != 0)
	{
		data[14] = 0;
	}
#endif
    if(G_parameter.agps.sw)
        updateforagpsfile = track_cust_agps_check_from_time(&epo_time);  /* AGPS是否需要更新 */
    else
        updateforagpsfile = 0;
    if(data[14] == 1)
    {
        updatefiletype = data[14];  // 0x01 为该终端OTA更新  0x02 为终端有OBD模块更新
        LOGD(L_APP, L_V4, "OTA 有更新升级提供");
    }
    
#if defined(__MCU_SW_UPDATE__)
    else if(data[14] == 4) /* MCU */
    {
        updatefiletype = data[14]; //
        LOGD(L_APP, L_V4, "MCU 有更新升级提供");
        track_cust_ota_update(1);
        track_cust_ota_cmd();
        LOGD(L_APP, L_V4, "MCU单片机升级指令延迟15分钟关机!!!");
    }
#endif
#if defined(__OBD__)
	else if(data[14] == 2)
	{
		updatefiletype = data[14];	// 0x01 为该终端OTA更新  0x02 为终端有OBD模块更新
		LOGD(L_APP, L_V4, "OBD 有更新升级提供");
	}
#endif /* __OBD__ */

    else
    {
        updatefiletype = 0;
        LOGD(L_APP, L_V4, "OTA/OBD 都无需升级");
#if defined( __SAME_GT02__)

#elif defined(__LANG_ENGLISH__)
    /*外贸不连AGPS       --    chengjun  2017-07-12*/
        if(G_parameter.agps.sw == 0 && G_importance_parameter_data.server2.conecttype < 10)
        {
            G_importance_parameter_data.server2.conecttype += 10;
            Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
        }
#endif /* __LANG_ENGLISH__ */
    }

#if defined(__ET310__) || defined(__MT200__)||defined (__GT740__)
    /* 向AMS上报采集的外电电压，用于检测设备因外电过高烧毁的情况 */
    track_cust_paket_volt(1);
#endif

#if defined (__AMS_LOG__)
        if(	1==G_realtime_data.ams_push)
        {
			track_file_stlog_upload();
		}
#endif
#if defined(__NF2318__)
		if(track_cust_rtinfo_upload(99))
		{
			track_cust_N07_realtime_info();
			track_cust_rtinfo_upload(0);
		}
		else 
		{
			track_cust_N07_realtime_info();
		}
#endif
    if(G_realtime_data.up_param && flg == 0)
    {
        CMD_DATA_STRUCT cmd_data = {0};
        flg = 1;
        cmd_data.return_sms.cm_type = CMD_NET2;
        cmd_check(&cmd_data);
    }

#if defined (__BAT_TEMP_TO_AMS__)
    track_cust_send_bat_temperature_data();
#endif /* __BAT_TEMP_TO_AMS__ */

#if defined (__NT33__)||defined (__NT31__)
	track_cust_fake_cell_alrm_info_to_ams();
#endif /* __NT33__ */

    track_cust_server2_write_req(0, NULL, 0,0);

    LOGD(L_APP, L_V5, "paramFileCrc:%X%X, file_crc:%X%X,updateforagpsfile=%d", G_parameter.paramFileCrc[0], G_parameter.paramFileCrc[1], data[15], data[16], updateforagpsfile);
    if(len >= 19 && memcmp(&data[15], G_parameter.paramFileCrc, 2))
    {
        memcpy(param_crc, &data[15], 2);
        nowUpdateFile = 7;
        resend_FE_02(nowUpdateFile);
    }
    else if(updatefiletype != 0)
    {
        nowUpdateFile = 2;
        resend_FE_02(nowUpdateFile);
    }
    else if(updateforagpsfile & 0x01)
    {
        nowUpdateFile = 1;
        resend_FE_03();  /* 获取经纬度 */
    }
    else if(updateforagpsfile & 0x02)
    {
        nowUpdateFile = 1;
        resend_FE_02(nowUpdateFile); /* 请求EPO文件 */
    }
#if defined(__AMS_HEX_LOG__)
    else if(G_realtime_data.AMS_HEX_sw_log == 1 && track_os_file_log_get_block() > 0)
   {
        track_os_file_log_send();
        track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 10000, track_cust_server2_exit, (void *)17);
   }
#endif
#if defined(__NF2318__)
	else if(1)
	{
		track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 10000, track_cust_server2_exit, (void *)3);
	}
#endif
    else
    {
        track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)3);
    }
}

static void recv_file_head(kal_uint8 *data, kal_uint16 len)
{
    kal_uint32 _file_size = 0, _file_flag = 0;
    kal_uint16 _file_crc = 0;
    kal_uint8  _file_md5[16] = {0};
    kal_uint8  _file_check_type = 0;
    LOGD(L_APP, L_V5, "file_flag_old:%d, buf:%X, file_flag:%X", file_flag_old, buf, file_flag);

    memcpy(&_file_flag, &data[3], 4);            // 文件标识
    _file_size = data[7];                        // 文件长度
    _file_size = (_file_size << 8) + data[8];
    _file_size = (_file_size << 8) + data[9];
    _file_size = (_file_size << 8) + data[10];
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

        LOGD(L_APP, L_V5, "buf:%X,  file_size:%d, file_check_type:%d, nowUpdateFile:%d, updatefiletype:%d",
             buf, file_size, file_check_type, nowUpdateFile, updatefiletype);
        if(buf)
        {
            Ram_Free(buf);
            buf = 0;
        }
        if(nowUpdateFile == 1)  /* AGPS */
        {
            ret = track_file_check(file_md5, MTKEPO_FILE_PATH);
            if(ret == 1)
            {
                LOGD(L_APP, L_V5, "与当前FAT中的AGPS MD5文件记录的信息相同, 忽略本次升级 %s ret:%d", MTKEPO_FILE_PATH, ret);
                if(updatefiletype != 0)
                {
                    nowUpdateFile = 2;
                    resend_FE_02(nowUpdateFile);
                }
#if defined(__AMS_HEX_LOG__)
                else if(G_realtime_data.AMS_HEX_sw_log == 1 && track_os_file_log_get_block() > 0)
                {
                    track_os_file_log_send();
                    track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 10000, track_cust_server2_exit, (void *)19);
                }
#endif
                else
                {
                    track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)12);
                }
                return;
            }
            LOGD(L_APP, L_V5, "%s ret:%d", MTKEPO_FILE_PATH, ret);
        }
        else if(nowUpdateFile == 2 && updatefiletype == 1) /* OTA */
        {
            nvram_check_ota_struct g_otacheck = {0};
            U8 md5_for_file[16] = {0};
            track_cust_get_data_from_file(FOTA_MD5_FILE_PATH, md5_for_file, 16);
            if(!memcmp(md5_for_file, file_md5, 16))
            {
                LOGD(L_APP, L_V5, "与当前FAT中的FOTA MD5文件记录的信息相同, 忽略本次升级 %s ret:%d", FOTA_MD5_FILE_PATH, ret);
#if defined(__AMS_HEX_LOG__)
                if(G_realtime_data.AMS_HEX_sw_log == 1 && track_os_file_log_get_block() > 0)
                {
                    track_os_file_log_send();
                    track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 10000, track_cust_server2_exit, (void *)3);
                }
                else track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)8);
#else
                track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)8);
#endif
                return;
            }
            LOGD(L_APP, L_V5, "%s ret:%d", FOTA_MD5_FILE_PATH, ret);

            Track_nvram_read(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
            /*if(G_importance_parameter_data.server2.conecttype == 1)
            {
                char *domain = track_domain_decode(G_importance_parameter_data.server2.url);
                LOGD(L_APP, L_V5, "domain:%s", domain);
                snprintf(g_otacheck.server, 100, "%s", domain);
            }
            else
            {
                snprintf(g_otacheck.server, 100, "%d.%d.%d.%d",
                    G_importance_parameter_data.server2.server_ip[0],
                    G_importance_parameter_data.server2.server_ip[1],
                    G_importance_parameter_data.server2.server_ip[2],
                    G_importance_parameter_data.server2.server_ip[3]);
            }
            g_otacheck.port = G_importance_parameter_data.server2.server_port;*/
            g_otacheck.unconditional = 98;
            Track_nvram_write(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
#if 0//defined(__GT740__)
            track_cust_module_online_update_delay();
#endif /* __GT740__ */
            track_socket_check_apn_diskdata();
#ifdef __GT300S__
            track_send_07();
#endif /* __GT300S__ */
            LOGD(L_APP, L_V5, "The terminal will restart after 5sec for Update!");
            track_cust_restart(2, 5);
            track_stop_timer(TRACK_CUST_SERVER2_RESEND_TIMER);
            return;
        }
        else if(nowUpdateFile == 2 && updatefiletype == 2)  /* OBD */
        {
            ret = track_md5_file_check(file_md5, OBD_MD5_FILE_PATH);
            if(ret == 1)
            {
                LOGD(L_APP, L_V5, "与当前FAT中的OBD MD5文件记录的信息相同, 忽略本次升级 %s ret:%d", OBD_FILE_PATH, ret);
                track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)13);
                return;
            }
            LOGD(L_APP, L_V5, "%s ret:%d", OBD_FILE_PATH, ret);
        }
        else if(nowUpdateFile == 2 && updatefiletype == 7)  /* 参数下载 */
        {
            ret = memcmp(&file_crc, &G_parameter.paramFileCrc, 2);
            if(ret != 0)
            {
                LOGD(L_APP, L_V5, "当前参数文件已经下载 ret:%d", ret);
#if defined(__AMS_HEX_LOG__)
                if(G_realtime_data.AMS_HEX_sw_log == 1 && track_os_file_log_get_block() > 0)
                {
                    track_os_file_log_send();
                    track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 10000, track_cust_server2_exit, (void *)3);
                }
                else track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)13);

#else
                track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)13);
#endif

                return;
            }
            LOGD(L_APP, L_V5, "%s ret:%d", OBD_FILE_PATH, ret);
        }
        recv_size = 0;
        file_offset = 1;
        buf = (U8*)Ram_Alloc(6, file_size + 100);
        if(buf == NULL)
        {
            LOGD(L_APP, L_V1, "ERROR:buf缓冲区为失败");
            return;
        }
    }
    retry = 0;
    start_time_tick = OTA_kal_get_systicks();
    resend_FE_04();
}

static void recv_file_content(kal_uint8 *data, kal_uint16 len)
{
    kal_uint16 recv_len = 0, i = 3;
    kal_uint32 recv_begin = 0;
    int ret;
    if(buf == NULL)
    {
        LOGD(L_APP, L_V1, "ERROR:Buf缓冲区的申请异常");
        return;
    }
    if(memcmp(&file_flag, &data[i], 4))
    {
        LOGD(L_APP, L_V1, "ERROR:返回的文件标识与请求的不一致");
        LOGH(L_APP, L_V6, &file_flag, 4);
        LOGH(L_APP, L_V6, &data[3], 4);
        return;
    }
    i += 4;
    recv_begin = data[i++];
    recv_begin = (recv_begin << 8) + data[i++];
    recv_begin = (recv_begin << 8) + data[i++];
    recv_begin = (recv_begin << 8) + data[i++];
    if(recv_begin != file_offset)
    {
        LOGD(L_APP, L_V1, "ERROR:服务器返回的数据起始位与请求的不一致 %d,%d", recv_begin, file_offset);
        return;
    }
    recv_len = data[i++];
    recv_len = (recv_len << 8) + data[i++];
    if(recv_len + 15 != len)
    {
        LOGD(L_APP, L_V1, "ERROR:返回的数据包大小与实际不符%d,%d", recv_len, len);
        return;
    }
    recv_size += recv_len;
    memcpy(&buf[file_offset - 1], &data[i++], recv_len);
    file_offset += recv_len;
    LOGD(L_APP, L_V6, "file_size:%d, file_offset:%d, req_size:%d, recv_size:%d", file_size, file_offset, req_size, recv_size);
    if(file_size > file_offset)
    {
        file_flag_old = 1;
        if(req_size != recv_size)
        {
            LOGD(L_APP, L_V6, "Warning: 实际接收的数据大小与请求的不一致(file_offset:%d,req_size:%d,recv_size:%d,recv_len:%d)", file_offset , req_size, recv_size, recv_len);
        }
        else
        {
            retry = 0;
            recv_size = 0;
            resend_FE_04();
        }
    }
    else
    {
        track_stop_timer(TRACK_CUST_SERVER2_RESEND_TIMER);
        LOGD(L_APP, L_V4, "全部接收完毕 耗时%d秒", OTA_kal_ticks_to_milli_secs(OTA_kal_get_systicks() - start_time_tick) / 1000);
        recv_size = 0;
        file_flag = 0;
        file_offset = 1;
        file_flag = 0;
        file_flag_old = 0;
        //track_epo_write_file(buf, file_size);
        if(file_check_type == 0 && !IsDataCrc16ext(buf, file_size, file_crc))
        {
            LOGD(L_APP, L_V1, "file crc error");
        }
        else if(file_check_type == 1 && !IsDataMd5ext(buf, file_size, file_md5))
        {
            LOGD(L_APP, L_V1, "file md5 error");
        }
        else if(nowUpdateFile == 1)
        {
            kal_uint32 flag = 0;
            applib_time_struct rtc;
            kal_uint32 epo_gps_hour, epo_gps_hour_end, current_gps_hour;
            memcpy(&flag, buf, 4);
            if(flag == 0)
            {
                kal_uint8 *buftmp = NULL;
                buftmp = (U8*)Ram_Alloc(6, file_size);
                if(buftmp)
                {
                    ret = OTA_track_fun_decryption(buftmp, buf, file_size);
                    if(ret > 0)
                    {
                        memcpy(&epo_gps_hour, buftmp, 3);
                        memcpy(&epo_gps_hour_end, (buftmp + ret - 72), 3);
                        epo_gps_hour &= 0x00FFFFFF;
                        epo_gps_hour_end &= 0x00FFFFFF;
                        OTA_applib_dt_get_rtc_time(&rtc);
                        current_gps_hour = track_utc_to_gps_hour(rtc.nYear, rtc.nMonth, rtc.nDay, rtc.nHour);

                        if(current_gps_hour <= epo_gps_hour_end)
                        {
                            applib_time_struct result1 = {0}, result2 = {0};
                            LOGD(L_APP, L_V4, "Recv file2 check crc ok, write file %d, epo_gps_hour:%d/%d",
                                 track_epo_write_file(buftmp, file_size - 6), epo_gps_hour, current_gps_hour);
                            OTA_track_gps_hour_to_utc(epo_gps_hour, &result1);
                            OTA_track_gps_hour_to_utc(epo_gps_hour_end, &result2);
                            track_cust_agps_time_add_6hour(&result2);
                            LOGD(L_APP, L_V4, "EPO file validity: %d-%0.2d-%0.2d %0.2d:00:00 ～ %d-%0.2d-%0.2d %0.2d:00:00",
                                 result1.nYear, result1.nMonth, result1.nDay, result1.nHour,
                                 result2.nYear, result2.nMonth, result2.nDay, result2.nHour);
                        }
                        else
                        {
                            LOGD(L_APP, L_V4, "Error: Recv file check crc ok, but no valid time data(epo_gps_hour:%d-%d %d)",
                                 epo_gps_hour, epo_gps_hour_end, current_gps_hour);
                        }
                    }
                    else
                    {
                        LOGD(L_APP, L_V4, "Error: 解密错误, ret=%d", ret);
                    }
                    Ram_Free(buftmp);
                }
            }
            else
            {
                memcpy(&epo_gps_hour, buf, 4);
                memcpy(&epo_gps_hour_end, (buf + file_size - 72), 4);
                epo_gps_hour &= 0x00FFFFFF;
                epo_gps_hour_end &= 0x00FFFFFF;
                OTA_applib_dt_get_rtc_time(&rtc);
                current_gps_hour = track_utc_to_gps_hour(rtc.nYear, rtc.nMonth, rtc.nDay, rtc.nHour);
                if(current_gps_hour <= epo_gps_hour_end)
                {
                    applib_time_struct result1 = {0}, result2 = {0};
                    LOGD(L_APP, L_V4, "Recv file check crc ok, write file %d(epo_gps_hour:%d-%d %d)",
                         track_epo_write_file(buf, file_size), epo_gps_hour, epo_gps_hour_end, current_gps_hour);
                    OTA_track_gps_hour_to_utc(epo_gps_hour, &result1);
                    OTA_track_gps_hour_to_utc(epo_gps_hour_end, &result2);
                    track_cust_agps_time_add_6hour(&result2);
                    LOGD(L_APP, L_V4, "EPO file validity: %d-%0.2d-%0.2d %0.2d:00:00 ～ %d-%0.2d-%0.2d %0.2d:00:00",
                         result1.nYear, result1.nMonth, result1.nDay, result1.nHour,
                         result2.nYear, result2.nMonth, result2.nDay, result2.nHour);
                    {
                        nvram_check_ota_struct g_otacheck = {0};
                        Track_nvram_read(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
                        if(g_otacheck.resetDay != 1)
                        {
                            g_otacheck.resetDay = 1;
                            Track_nvram_write(NVRAM_EF_CHECK_OTA_LID, 1, (void *)&g_otacheck, NVRAM_EF_CHECK_OTA_SIZE);
                        }
                    }
                }
                else
                {
                    LOGD(L_APP, L_V4, "Error: Recv file check crc ok, but no valid time data(epo_gps_hour:%d-%d %d)",
                         epo_gps_hour, epo_gps_hour_end, current_gps_hour);
                }
            }
            //track_epo_update_time(&epo_time);
            //track_epo_data_day(2, buf, file_size);
            if(track_cust_gps_status() == GPS_STAUS_SCAN)
            {
                //track_cust_agps_restart();
                track_drv_gps_epo_start();
            }
            if(updatefiletype != 0)
            {
                nowUpdateFile = 2;
                resend_FE_02(nowUpdateFile);
                return;
            }
        }
        else if(nowUpdateFile == 2)
        {
            if(updatefiletype == 1) /* OTA */
            {
                WCHAR FilePath[60] = {0}, FilePath_tmp[60] = {0};
                OTA_kal_wsprintf(FilePath, "%s", OBD_FILE_PATH);
                ret = OTA_FS_Delete(FilePath);
                LOGD(L_APP, L_V4, "Del %s %d", OBD_FILE_PATH, ret);
                ret = track_write_file(OTA_FILE_PATH_TMP, buf, file_size);
                LOGD(L_APP, L_V4, "Recv OTA file check ok, write file %d",
                     ret);
                if(ret > 0)
                {
                    OTA_kal_wsprintf(FilePath, "%s", OTA_FILE_PATH);
                    OTA_kal_wsprintf(FilePath_tmp, "%s", OTA_FILE_PATH_TMP);
                    ret = OTA_FS_Delete(FilePath);
                    LOGD(L_APP, L_V4, "Del %s %d", OTA_FILE_PATH, ret);
                    ret = OTA_FS_Rename(FilePath_tmp, FilePath);
                    LOGD(L_APP, L_V4, "Rename %s->%s %d", "test.tmp", OTA_FILE_PATH, ret);
                    save_md5_to_file(file_md5);
                    track_cust_restart(2, 20);
                }
                else
                {
                    OTA_kal_wsprintf(FilePath_tmp, "%s", OTA_FILE_PATH_TMP);
                    ret = OTA_FS_Delete(FilePath_tmp);
                    LOGD(L_APP, L_V4, "Del %s %d", OTA_FILE_PATH_TMP, ret);
                }
            }
#if defined(__MCU_SW_UPDATE__)
            else if(updatefiletype == 4)  /* MCU */
            {
                LOGD(L_APP, L_V4, "Recv SingleChip file check ok, Begin updata mcu...");
                track_cust_module_mcu_fireware_file(buf, file_size);
                buf = NULL;
                file_size = 0;
            }           
#endif
#if defined(__OBD__)
			else if(updatefiletype == 2)  /* OBD */
			{
				LOGD(L_APP, L_V4, "Recv OBD file check ok, Begin updata OBD...", ret);
				track_cust_obd_update_fireware(buf, file_size);
				buf = NULL;
				file_size = 0;
			}
#endif /* __OBD__ */

        }
        else if(nowUpdateFile == 7)
        {
            LOGD(L_APP, L_V5, "paramFileCrc:%X%X, file_crc:%X, [%d]\r\n%s", G_parameter.paramFileCrc[0], G_parameter.paramFileCrc[1], file_crc, file_size, buf);
            LOGH(L_APP, L_V5, buf, file_size);
            G_parameter.paramFileCrc[0] = (file_crc & 0xFF00) >> 8;
            G_parameter.paramFileCrc[1] = (file_crc & 0x00FF);
            track_cmd_params_recv(buf, CM_ONLINE2);
            if(updatefiletype != 0)
            {
                nowUpdateFile = 2;
                resend_FE_02(nowUpdateFile);
                return;
            }
            else if(updateforagpsfile & 0x01)
            {
                nowUpdateFile = 1;
                resend_FE_03();  /* 获取经纬度 */
                return;
            }
            else if(updateforagpsfile & 0x02)
            {
                nowUpdateFile = 1;
                resend_FE_02(nowUpdateFile); /* 请求EPO文件 */
                return;
            }
        }
        if(buf)
        {
            //   Ram_Free(buf);
        }
#if defined(__AMS_HEX_LOG__)
        if(G_realtime_data.AMS_HEX_sw_log == 1 && track_os_file_log_get_block() > 0)
        {
            track_os_file_log_send();
            track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 10000, track_cust_server2_exit, (void *)3);
        }
        else track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)5);
#else
        track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)5);
#endif
    }
}

#if 0
#endif /* 0 */
/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
void track_cust_server2_file_retry(void)
{
    tick_time = OTA_kal_get_systicks();
    retry = 0;
}

void track_cust_server2_decode_packet(kal_uint8 *data, kal_uint16 len)
{
    kal_uint8 packet_type, i = 0, req_result, queue;

    LOGH(L_APP, L_V7, data, len);
    packet_type = data[i++];
    retry = 0;
    track_start_timer(TRACK_CUST_SERVER2_RESEND_TIMER, 90000, track_cust_server2_exit, (void*)6);
    LOGD(L_APP, L_V5, "packet_type:%d", packet_type);
    is_rev_data = 1;
    if(packet_type == 0) /* 登陆反馈 */
    {
        g_conn_status = 1;
        track_cust_server2_check(0xff);
        req_result = data[i++];
        // 这里后期最好限定返回错误类型
        if(req_result != 1)
        {
            /* 服务器返回登陆失败 */
            LOGD(L_APP, L_V4, "login error %d", req_result);
 #if defined(__AMS_HEX_LOG__)
            if(G_realtime_data.AMS_HEX_sw_log == 1 && track_os_file_log_get_block() > 0)
            {
                track_os_file_log_send();
                track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 10000, track_cust_server2_exit, (void *)3);
                track_stop_timer(TRACK_CUST_SERVER2_RESEND_TIMER);
            }
            else track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)12);
#elif defined(__NF2318__)
			if(track_cust_rtinfo_upload(99))
			{
				track_cust_N07_realtime_info();
				track_cust_rtinfo_upload(0);
				track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 10000, track_cust_server2_exit, (void *)3);
				track_stop_timer(TRACK_CUST_SERVER2_RESEND_TIMER);
			}
			else 
			{
				track_cust_N07_realtime_info();
				track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)12);
			}
#else
            track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)12);
#endif

            return;
        }

        LOGD(L_APP, L_V5, "收到数据0 retry:%d len:%d packet_type:%d, req_result:%d,%d",
             retry, len, packet_type, (kal_uint8)data[i + 1], (kal_uint8)data[i + 2]);
        recv_login(data, len);
    }
    else if(packet_type == 1 || packet_type == 2 || packet_type == 7) /* 文件接收过程 */
    {
        queue = data[i++];
        req_result = data[i++];
        if(queue == 2)  /* 文件信息头 */
        {
            LOGD(L_APP, L_V5, "收到数据1 retry:%d len:%d packet_type:%d, req_result:%d,%d, file_offset=%d, file_size=%d",
                 retry, len, packet_type, (kal_uint8)data[i + 1], (kal_uint8)data[i + 2], file_offset, file_size);
            if(req_result != 1)
            {
                /* 服务器返回错误 */
                LOGD(L_APP, L_V4, "服务器返回错误 recv error %d", req_result);
  #if defined(__AMS_HEX_LOG__)
            if(G_realtime_data.AMS_HEX_sw_log == 1 && track_os_file_log_get_block() > 0)
                {
                    track_os_file_log_send();
                    track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 10000, track_cust_server2_exit, (void *)3);
                }
                else track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)9);

#else
                track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)9);
#endif

                return;
            }
            recv_file_head(data, len);
        }
        else if(queue == 4)  /* 文件内容 */
        {
            if(req_result != 1)
            {
                /* 服务器返回错误 */
                LOGD(L_APP, L_V4, "服务器返回错误 recv error %d", req_result);
  #if defined(__AMS_HEX_LOG__)
               if(G_realtime_data.AMS_HEX_sw_log == 1 && track_os_file_log_get_block() > 0)
                {
                    track_os_file_log_send();
                    track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 10000, track_cust_server2_exit, (void *)3);
                }
                else track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)10);
  

#else
                track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)10);
#endif
                return;
            }
            LOGD(L_APP, L_V5, "收到数据2 retry:%d len:%d packet_type:%d, req_result:%d,%d, file_offset=%d, file_size=%d  %d%%",
                 retry, len, packet_type, (kal_uint8)data[i + 1], (kal_uint8)data[i + 2], file_offset, file_size, file_offset * 100 / (file_size + 1));
            recv_file_content(data, len);
        }
    }
    else if(packet_type == 3) /* 基站信息转经纬度 */
    {
        req_result = data[i++];
        if(req_result != 1)
        {
            /* 服务器返回错误 */
            LOGD(L_APP, L_V4, "收到数据  基站信息转经纬度 recv error %d", req_result);
            //track_cust_server2_exit((void *)11);
            //return;
        }
        else
        {
            LOGD(L_APP, L_V5, "收到数据  基站信息转经纬度");
            track_cust_decode_lbs_packet(&data[2], len - 1);
        }
#if defined (__SECOND_SET__)
        updateforagpsfile = 0;
#endif
        if(updateforagpsfile & 0x02) /* 基站转经纬度获取成功，获取EPO文件 */
        {
            nowUpdateFile = 1;
            resend_FE_02(nowUpdateFile); // 请求EPO文件
        }
#if 0
        else if(G_parameter.agps.sw && track_cust_gps_status() == GPS_STAUS_SCAN) /* 已有EPO文件，尝试注入 */
        {
            //track_cust_agps_restart();
            track_drv_gps_epo_start();
        }
#endif /* 0 */
        if(updatefiletype != 0)
        {
            nowUpdateFile = 2;
            resend_FE_02(nowUpdateFile);
        }
#if defined(__AMS_HEX_LOG__)
        else if(G_realtime_data.AMS_HEX_sw_log == 1 && track_os_file_log_get_block() > 0)
        {
            track_os_file_log_send();
            track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 10000, track_cust_server2_exit, (void *)3);
        }
#endif
        else
        {
            track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)7);
        }
    }
    else if(packet_type == 4) /* 在线指令 */
    {
        //LOGH(L_APP, L_V6, &data[i], len);
        track_cust_decode_packet_FD_cmd(data, len);
        if(track_is_timer_run(TRACK_CUST_SERVER2_OVERTIME_TIMER))
        {
#if defined(__AMS_HEX_LOG__)
        if(G_realtime_data.AMS_HEX_sw_log == 1 && track_os_file_log_get_block() > 0)
            {
                track_os_file_log_send();
                track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 10000, track_cust_server2_exit, (void *)3);
            }
            else track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)3);

 #else
            track_start_timer(TRACK_CUST_SERVER2_OVERTIME_TIMER, 5000, track_cust_server2_exit, (void *)3);
#endif

        }
    }
}

kal_bool track_cust_server2_status_retry(void)
{
    static int count = 0;
    kal_uint32 tick = OTA_kal_get_systicks() - tick_time;
    LOGD(L_APP, L_V5, "retry:%d, tick:%d", retry, tick);
    if(retry != -1 && tick < KAL_TICKS_1_MIN * 10 && ((count < 3 && g_conn_status == 0) || g_conn_status != 0))
    {
        count++;
        return KAL_TRUE;
    }
    count = 0;
    return KAL_FALSE;
}

kal_bool track_cust_server2_conn_status(void)
{
    if(is_rev_data == 0)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

