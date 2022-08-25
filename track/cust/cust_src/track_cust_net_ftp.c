#if defined(__NET_FTP__)
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
#include "c_RamBuffer.h"
#include "track_cust_net_ftp.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/
#define MAX_SND_BUFFER_SIZE 1500

#define FTP_OTA_FILE_TMP       "test.bin"

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/
typedef struct
{
    char            *user;             //登陆名
    char            *password;         //密码
    char            *server;           //FTP服务器域名
    char            *path;             //文件路径
    char            *file;             //文件名字
    U8              *filehandle;       //文件数据
    U32             filesize;          //文件大小
    U32             receivedfilesize;  //接收文件大小
    U32             bufferlen;         //数据长度
    Func_Ptr        funBack;
    sockaddr_struct ip;                //FTP服务器IP
    sockaddr_struct ip2;
} track_ftp_data_struct;

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static track_ftp_data_struct    gFtp = {0};
static U8 recv_status = 0;      //接收状态： 0x01：被动数据接收中 0x02：被动数据连接断开 0x04：数据接收完成
static kal_uint8 g_yadea_updata_type = 0;//
static kal_uint8 g_yadea_updata_timelimt = 0;//更新时间限制
/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern kal_int32 track_write_file(char *filepath, kal_uint8 *data, kal_uint32 _len);

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
static void FtpDataEvent(track_soc_Callback_struct *par);
static void FtpEvent(track_soc_Callback_struct *par);
static kal_int8 ftp_net_write_req(kal_uint8 *data, kal_int32 datalen);

#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/
unsigned short track_fun_Get_CRC16_CCITT(unsigned char *ptr, unsigned int len)
{
    static unsigned short crc_table[16] ={0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7, 0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef};
    unsigned short crc = 0;
    unsigned char crc_H4;
    while( len-- )
    {
        crc_H4 = (unsigned char)(crc >> 12);
        crc = crc << 4;
        crc = crc ^ crc_table[ crc_H4 ^ (*ptr >> 4)];
        crc_H4 = (unsigned char)(crc >> 12);
        crc = crc << 4;
        crc = crc ^ crc_table[ crc_H4 ^ (*ptr & 0x0f)];
        ptr++;
    }
    return crc;
}

static kal_int8 ftp_net_write_req(kal_uint8 *data, kal_int32 datalen)
{
    kal_int8 ret;
    ret = Socket_write_req(2, data, datalen, 0, 0, 0, 1);
    LOGD(L_APP, L_V5, "ret:%d, data:%s", ret, data);
}

static void ftp_net_disconnect(void)
{
   
    LOGD(L_APP, L_V5, "#6");
    socket_disconnect(3);
    
    LOGD(L_APP, L_V5, "#7");
    socket_disconnect(2);
}

static void return_fun(kal_int8 ret, U8 *data, U32 len)
{
    static track_ftp_return_struct  returnData = {0};
    
    if(ret == 0 && gFtp.receivedfilesize > 0)
    {
        U16 crc;
        crc = track_fun_Get_CRC16_CCITT(gFtp.filehandle, gFtp.receivedfilesize);
        LOGD(L_APP, L_V5, "Recv File Size:%d\r\nCRC16 CCITT 算法(生成多项式 = 0x1021):%0.4X", gFtp.receivedfilesize, crc);
    }
    returnData.ret = ret;
    returnData.data = data;
    returnData.len = len;
    
    if(gFtp.funBack != NULL) 
    {
       LOGD(L_APP, L_V5, "#1");
        gFtp.funBack(&returnData);
    }
    
    if(gFtp.filehandle != NULL)
    {
        LOGD(L_APP, L_V5, "#2");
        Ram_Free(gFtp.filehandle);
    }
    
    if(gFtp.user != NULL) 
    {
        LOGD(L_APP, L_V5, "#3");
        Ram_Free(gFtp.user);
    }
}

void track_cust_project_OTA_FTP_start(void)
{
    if(1 == g_yadea_updata_type)
    {
        track_cust_net_ftp_getfile(G_parameter.yadea_ota.user,  G_parameter.yadea_ota.pass, 
                                   G_parameter.yadea_ota.domain, G_parameter.yadea_ota.port,
                                   G_parameter.yadea_ota.path, track_cust_dayea_GSM_firmware_from_FTP);   

    }
    else if(2 == g_yadea_updata_type)
    {
        track_cust_net_ftp_getfile(G_parameter.yadea_ota.user,  G_parameter.yadea_ota.pass, 
                                   G_parameter.yadea_ota.domain, G_parameter.yadea_ota.port,
                                   G_parameter.yadea_ota.path, track_cust_dayea_muc_firmware_from_FTP);   

    }

    tr_start_timer(TRACK_CUST_GSM_OTA_FTP_OVER_TIME_ID, g_yadea_updata_timelimt*60*1000, track_cust_project_OTA_FTP_overtime);
}


static void conn_ftp_server_data(void)
{
    kal_int8 ret;

    LOGD(L_APP, L_V5, "%d.%d.%d.%d:%d",
         gFtp.ip2.addr[0],
         gFtp.ip2.addr[1],
         gFtp.ip2.addr[2],
         gFtp.ip2.addr[3],
         gFtp.ip2.port);
    ret = Socket_conn_req(3, &gFtp.ip2, FtpDataEvent, 0);
    LOGD(L_APP, L_V5, "ret=%d", ret);
    if(ret < 0)
    {
        return_fun(-4, 0, 0);
    }
}

static void conn_ftp_server(void)
{
    kal_int8 ret;

    LOGD(L_APP, L_V5, "%d.%d.%d.%d:%d",
         gFtp.ip.addr[0],
         gFtp.ip.addr[1],
         gFtp.ip.addr[2],
         gFtp.ip.addr[3],
         gFtp.ip.port);
    ret = Socket_conn_req(2, &gFtp.ip, FtpEvent, 0);
    LOGD(L_APP, L_V5, "ret=%d", ret);
    if(ret < 0)
    {
        return_fun(-3, 0, 0);
    }
}

static void ftp_recv_data(char *data, int len)
{
    static U8 status = 0;
    LOGD(L_APP, L_V5, "[%d] %s", len, data);

    if(strstr(data, "220 ") == data)
    {
        if(strstr(data, "220 Welcome to yadea FTP service.") == data)
        {
            LOGD(L_APP, L_V5, "Welcome to yadea FTP service.");
        }
        else
        {
            char tmp[110] = {0};
            int l = snprintf(tmp, 110, "USER %s\r\n", gFtp.user);
            tr_stop_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID2);
            ftp_net_write_req(tmp, l);
            status = 0;
            recv_status = 0;
        }
    }
    else if(strstr(data, "221 ") == data) /*服务关闭控制连接。如果适当，请注销。*/
    {
        if(status == 0)
        {
            if(gFtp.receivedfilesize == gFtp.filesize)
            {
                return_fun(0, gFtp.filehandle, gFtp.receivedfilesize);
            }
            else
            {
                return_fun(-5, gFtp.filehandle, gFtp.receivedfilesize);
            }
        }
    }
    else if(strstr(data, "331 ") == data)
    {
        char tmp[110] = {0};
        int l = snprintf(tmp, 110, "PASS %s\r\n", gFtp.password);
        ftp_net_write_req(tmp, l);
    }
    else if(strstr(data, "230 ") == data)
    {
        if(strcmp(gFtp.path, "/"))
        {
            char tmp[110] = {0};
            int l = snprintf(tmp, 110, "CWD %s\r\n", gFtp.path);
            ftp_net_write_req(tmp, l);
        }
        else
        {
            ftp_net_write_req("PWD\r\n", 5);
        }
    }
    else if(strstr(data, "250 ") == data)
    {
        ftp_net_write_req("PWD\r\n", 5);
    }
    else if(strstr(data, "257 ") == data)
    {
        ftp_net_write_req("TYPE I\r\n", 8);
    }
    else if(strstr(data, "200 ") == data)
    {
        char tmp[110] = {0};
        int l = snprintf(tmp, 110, "SIZE %s\r\n", gFtp.file);
        ftp_net_write_req(tmp, l);
    }
    else if(strstr(data, "213 ") == data)
    {
        char *b;
        b = strchr(data, ' ');
        if(b == NULL)
        {
            LOGD(L_APP, L_V1, "ERROR:1");
            return;
        }
        
        gFtp.filesize = atoi(++b);
        if(gFtp.filesize == 0)
        {
            LOGD(L_APP, L_V1, "ERROR:2");
            return;
        }

        if(gFtp.filehandle == NULL)
        {
            gFtp.filehandle = (U8*)Ram_Alloc(7, gFtp.filesize + 10);
        }
        gFtp.receivedfilesize = 0;
        ftp_net_write_req("REST 0\r\n", 8);
    }
    else if(strstr(data, "350 ") == data)
    {
        ftp_net_write_req("PASV\r\n", 6);
    }
    else if(strstr(data, "226 ") == data)
    {
        LOGD(L_APP, L_V5, "recv_status:%d", recv_status);
        status = 1;
        recv_status |= 4;
        if((recv_status & 3) == 3) 
        {
            ftp_net_write_req("QUIT\r\n", 6);
        }
    }
    else if(strstr(data, "227 ") == data)
    {
        int i;
        char *p = data;
        U8 ip[4];
        
        LOGH(L_APP, L_V5, data, 80);
        p = strchr(p, '(');
        if(p == NULL)
        {
            LOGD(L_APP, L_V1, "ERROR:3");
            return;
        }
        p++;

        for(i = 0; i < 4; i++)
        {
            ip[i] = atoi(p);
            p = strchr(p, ',');
            if(p == NULL)
            {
                LOGD(L_APP, L_V1, "ERROR:4");
                return;
            }
            p++;
        }
        i = atoi(p);
        p = strchr(p, ',');
        p++;
        i = (i << 8) + atoi(p);

        memcpy(&gFtp.ip2, &gFtp.ip, sizeof(sockaddr_struct));
        gFtp.ip2.port = i;
        conn_ftp_server_data();
    }
    else if(strstr(data, "550 ") == data)
    {
        ftp_net_write_req("QUIT\r\n", 6);
    }
}

static void FtpDataEvent(track_soc_Callback_struct *par)
{
    LOGD(L_APP, L_V5, "status=%d error=%d", par->status, par->errorid);
    switch(par->status)
    {
        case SOC_CONNECT_SUCCESS:
            {
                char tmp[110] = {0};
                int l = snprintf(tmp, 110, "RETR %s\r\n", gFtp.file);
                ftp_net_write_req(tmp, l);
                break;
            }
        case SOC_CONNECT_ServerNotResponding:
            {
                break;
            }
        case SOC_CONNECT_CLOSE:
            {
                recv_status |= 2;
                LOGD(L_APP, L_V5, "recv_status:%d", recv_status);
                //if((recv_status & 4) == 4) 
                {
                    ftp_net_write_req("QUIT\r\n", 6);
                }
                
                LOGD(L_APP, L_V5, "#4");
                break;
            }
        case SOC_RECV_DATA:
            {
                LOGD(L_APP, L_V5, "filesize:%d, receivedfilesize:%d, recvBuffLen:%d", 
                    gFtp.filesize, gFtp.receivedfilesize + par->recvBuffLen, par->recvBuffLen);
                    
                if(gFtp.filesize - gFtp.receivedfilesize >= par->recvBuffLen)
                {
                    memcpy(&gFtp.filehandle[gFtp.receivedfilesize], par->recvBuff, par->recvBuffLen);
                    gFtp.receivedfilesize += par->recvBuffLen;

                    if(gFtp.filesize == gFtp.receivedfilesize)
                    {
                        return_fun(0, gFtp.filehandle, gFtp.receivedfilesize);
                        recv_status |= 1;
                        track_os_intoTaskMsgQueue(ftp_net_disconnect); 
                    }
                }
                else
                {
                    LOGD(L_APP, L_V1, "ERROR!!!");
                }
                    
                break;
            }
        case SOC_SEND_DATA:
            {
                if(par->errorid != 0)
                {
                    LOGD(L_APP, L_V1, "ERROR!!! id=%d", par->errorid);
                }
                break;
            }
    }
}

static recv_220(void)
{
    char *a = "220 ";
    ftp_recv_data(a, strlen(a));
}

static void FtpEvent(track_soc_Callback_struct *par)
{
    LOGD(L_APP, L_V5, "status=%d error=%d", par->status, par->errorid);
    switch(par->status)
    {
        case SOC_CONNECT_SUCCESS:
            {
                tr_start_timer(TRACK_CUST_NET_CONN_TIMEOUT_TIMER_ID2, 2000, recv_220);
                break;
            }
        case SOC_CONNECT_ServerNotResponding:
            {
                break;
            }
        case SOC_CONNECT_CLOSE:
            {
                LOGD(L_APP, L_V5, "#5");
                break;
            }
        case SOC_RECV_DATA:
            {
                char *p = (char*)par->recvBuff;
                char *q;
                while(*p != 0 && par->recvBuff + par->recvBuffLen > p)
                {
                    q = strchr(p, '\n');
                    if(q != NULL)
                    {
                        *q = 0;
                    }
                    ftp_recv_data(p, strlen(p));
                    p = q + 1;
                }
                break;
            }
        case SOC_SEND_DATA:
            {
                if(par->errorid != 0)
                {
                    LOGD(L_APP, L_V1, "ERROR!!! id=%d", par->errorid);
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
                    }
                    else
                    {
                    }
                }
                else
                {
                    kal_int8 ret;
                    LOGD(L_APP, L_V5, "hostname to IP:%d.%d.%d.%d:%d",
                         par->ip_from_hostname[0], par->ip_from_hostname[1],
                         par->ip_from_hostname[2], par->ip_from_hostname[3],
                         gFtp.ip.port);

                    memcpy(gFtp.ip.addr, par->ip_from_hostname, 4);
                    conn_ftp_server();
                }
                break;
            }
    }
}

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

kal_int8 track_cust_net_ftp_getfile(char *user, char *password, char *serveraddr, U16 port, char *filepath, Func_Ptr funBack)
{
    U16 l_user, l_password, l_server, l_file, l_path;
    U8 *file, *path;

    l_user = strlen(user);
    l_password = strlen(password);
    l_server = strlen(serveraddr);

    {
        char *l, *m;
        m = filepath;
        l = filepath;
        do
        {
            m = strchr(m + 1, '/');
            if(m != NULL) l = m;
        }
        while(m);
        l++;
        l_file = strlen(l);
        file = l;
        l_path = l - filepath;
        path = filepath;
    }

    if(l_user > 100 || l_password > 100 || l_server > 50 || l_path > 150 || l_file > 100)
    {
        return -3;
    }
    if(gFtp.user == NULL)
    {
        gFtp.bufferlen = l_user + l_password + l_server + l_path + l_file + 20;
        gFtp.user = (U8*)Ram_Alloc(7, gFtp.bufferlen);
    }
    else if(gFtp.bufferlen > l_user + l_password + l_server + l_path + l_file + 20)
    {
        memset(gFtp.user, 0, gFtp.bufferlen);
    }
    else
    {
        Ram_Free(gFtp.user);
        gFtp.bufferlen = l_user + l_password + l_server + l_path + l_file + 20;
        gFtp.user = (U8*)Ram_Alloc(7, gFtp.bufferlen);
    }
    memcpy(gFtp.user, user, l_user);
    gFtp.password = gFtp.user + l_user + 1;
    memcpy(gFtp.password, password, l_password);
    gFtp.server = gFtp.password + l_password + 1;
    memcpy(gFtp.server, serveraddr, l_server);
    gFtp.path = gFtp.server + l_server + 1;
    memcpy(gFtp.path, path, l_path);
    gFtp.file = gFtp.path + l_path + 1;
    memcpy(gFtp.file, file, l_file);
    gFtp.ip.addr_len = 4;
    gFtp.ip.port = port;
    gFtp.funBack = funBack;
    LOGD(L_APP, L_V5, "user:%s, pass:%s, server:%s:%d, path:%s, file:%s",
        gFtp.user, gFtp.password, gFtp.server, gFtp.ip.port, gFtp.path, gFtp.file);
        
    if(track_fun_check_ip(gFtp.server))
    {
        LOGD(L_APP, L_V5, "IP:%s", gFtp.server);
        track_fun_asciiIP2Hex(gFtp.server, gFtp.ip.addr);
        LOGH2(L_APP, L_V5, "IP:", gFtp.ip.addr, 4);
        conn_ftp_server();
    }
    else
    {
        LOGD(L_APP, L_V5, "HostServer");
        Socket_gethostbyname(gFtp.server, FtpEvent);
    }
    return -2;
}

void track_cust_net_ftp_disconnect(void)
{
    ftp_net_write_req("QUIT\r\n", 6);
    //track_os_intoTaskMsgQueue(ftp_net_disconnect); 
}

/************************************************************************************
*************************************************************************************
*************************************************************************************/
static U8 *buf = NULL;
static U32 file_size = 0;
kal_uint8* track_net_ftp_get_data(void)
{
    return buf;
}

kal_uint32 track_net_ftp_get_data_size(void)
{
    return file_size;
}
void track_net_ftp_free_data(void)
{
    if(buf != NULL)
    {
        Ram_Free(buf);
    }
}
    
static void ftp_test(void *par)
{
    kal_int32 ret = 0;
    track_ftp_return_struct *parm = (track_ftp_return_struct *)par;
    LOGD(L_APP, L_V5, "ret=%d FTP 文件下载完成，大小：%d!", parm->ret, parm->len);

    if(parm->ret < 0)
    {
        LOGD(L_APP, L_V5, "失败了");
    }
    else
    {
        ret = track_write_file(FTP_OTA_FILE_TMP, parm->data, parm->len);
        LOGD(L_APP, L_V4, "Recv OTA file check ok, write file %d", ret);
    }

}

void ftp_debug(void)
{
    track_cust_net_ftp_getfile(
        "ftpotagps", "q3lrJ4a6DmDxOBVI", "139.217.96.107", 21, 
        "/ota/firmware/BCM_00_01_XV0101_01_191229.bin",
        //"/pub/pthreads-win32/sources/pthreads-w32-2-9-1-release/PROGRESS",
        ftp_test);
}

void cmd_ftp_debug(CMD_DATA_STRUCT *cmd)
{
    char *domain, *user, *pass, *path, *p; 
    kal_uint16 port;

    LOGD(L_APP, L_V5, "{%s}", cmd->rcv_msg_source);
        
    p = cmd->pars[2];
    cmd->rcv_msg_source[(p - cmd->rcv_msg) + strlen(p)] = 0;
    user = cmd->rcv_msg_source + (p - cmd->rcv_msg);

    p = cmd->pars[3];
    cmd->rcv_msg_source[(p - cmd->rcv_msg) + strlen(p)] = 0;
    pass = cmd->rcv_msg_source + (p - cmd->rcv_msg);

    p = cmd->pars[4];
    cmd->rcv_msg_source[(p - cmd->rcv_msg) + strlen(p)] = 0;
    domain = cmd->rcv_msg_source + (p - cmd->rcv_msg);

    port = atoi(cmd->pars[5]);

    p = cmd->pars[6];
    cmd->rcv_msg_source[(p - cmd->rcv_msg) + strlen(p)] = 0;
    path = cmd->rcv_msg_source + (p - cmd->rcv_msg);
    
    LOGD(L_APP, L_V5, "user:%s, pass:%s, server:%s:%d, path:%s",
        user, pass, domain, port, path);
    
    track_cust_net_ftp_getfile(
        user, pass, domain, port, 
        path,
        ftp_test);
    /*track_cust_net_ftp_getfile(
        "anonymous", "anonymous@163.com", "sourceware.org", 21, 
        file,
        ddd);*/
}






/******************************************************************************
 *  Function    -  track_cust_yadea_platform_paket_0xF500
 * 
 *  Purpose     -  FTP服务器更新文件入口
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2020-03-23,  xiongweiming  written
 * ----------------------------------------
 ******************************************************************************/
void track_cust_yadea_platform_paket_0xF500(kal_uint8 *recv, kal_uint16 datalen)
{
    kal_uint8* SW_vsion = NULL;
    kal_uint8* HW_vsion = NULL;
    kal_uint16 port = 0;
    kal_uint16 path_len = 0;
    
    if(0x02 == recv[0])
    {
        g_yadea_updata_type = 2;
    }
    else if(0x05 == recv[0])
    {
        g_yadea_updata_type = 1;
        
        HW_vsion = &recv[1];
        SW_vsion = &recv[5];
        if(0 != memcmp(HW_vsion, G_parameter.yadea_viosn.HW_vsion, 4))
        {
        	//告诉服务器硬件版本号有问题
            //track_cust_yadea_platform_paket_0x0500_FD(0, 1, 1);
            return;
        }
        else if(0 == memcmp(SW_vsion, G_parameter.yadea_viosn.SW_vsion, 4))
        {
        	//告诉服务器软件版本号有问题
            //track_cust_yadea_platform_paket_0x0500_FD(0, 1, 2);
            return;
        }
        else //HW相同，SW不相同
        {
            memcpy(G_parameter.yadea_ota.ota_swvsion, SW_vsion, 4);
        }
    }

    //FTP服务器IP
    if(0 == recv[9] && 0 == recv[10])
    {
        memcpy(G_parameter.yadea_ota.domain, &recv[11], 4);
    }
    else
    {
        memcpy(G_parameter.yadea_ota.domain, &recv[11], 6);
    }

    //端口
    port = recv[15];
    port = (port << 8) + recv[16];

    //用户名
    memcpy(G_parameter.yadea_ota.user, &recv[17], 8);
    //密码
    memcpy(G_parameter.yadea_ota.pass, &recv[25], 16);
    //路径长度
    path_len = recv[41];
    if(path_len > 200)
    {
    	//告诉服务器路径有问题
        //track_cust_yadea_platform_paket_0x0500_FD(0, 1, 3);
        return;
    }
    else
    {
        memcpy(G_parameter.yadea_ota.path, &recv[42], path_len);
    }
    
    g_yadea_updata_timelimt = recv[42 + path_len];

    track_os_intoTaskMsgQueue(track_cust_project_OTA_FTP_start);
}

#endif /*__NET_FTP__*/