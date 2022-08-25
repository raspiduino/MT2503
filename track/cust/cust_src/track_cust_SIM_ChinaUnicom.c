#if defined(__SIM_CU_CALL__)
/*******************************************************************************************
 * Filename:
 * Author :
 * Date :
 * Comment:
 ******************************************************************************************/

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "custom_nvram_editor_data_item.h"
#include "app_datetime.h"

#include "track_cust.h"
#include "track_os_data_types.h"
#include "track_os_log.h"
#include "track_os_ell.h"
#include "track_soc_Lcon.h"
#include "c_RamBuffer.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/
#define APP_NO    2

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/


/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static char *g_http_head[] = {
    "POST /cxsz/api/", 
    "call/findSignal.json", 
    "balance/findBalance.json", 
    "?json={", 
    "} HTTP/1.1\r\nHost: ", 
    "plat.cxsz.com.cn", 
    "\r\nUser-Agent: Firefox/33.0\r\nContent-Type: application/json\r\nConnection: close\r\nPragma: no-cache\r\nCache-Control: no-cache\r\nContent-Length: 0\r\n\r\n"};
static char *g_dq = "%22";
static char *g_publicKey = "4865ea99b04569e15406eb7159870cb4";
static char *g_privateKey = "d18835d6f61094d48498a67c86396e4a";
static char g_callee[16] = {0};          // 机主手机号码
static char g_caller[21] = {0};          // 设备内置号码或IMSI
static char g_nonceStr[21] = {0};        // 20位随机字符串
static char g_timestamp[11] = {0};       // 时间戳
static char g_signature[41] = {0};       // 签名
static kal_hisr_func_ptr fun = NULL;

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/

/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/

/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/

/******************************************************************************
 *  Function    -  get_rand_str
 *
 *  Purpose     -  随机生成字符串
 *
 *  Description -
 *    如果是在一个程序的循环中不断调用这个函数，那么是没有效果的
 *    虽然也是使用的系统的时间函数来初始化随机数发生器，但程序的
 *    执行速度太快了，可能执行1000次循环返回的秒数都是一样的
 *    time返回时间戳
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 18-10-2016,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static char *get_rand_str(char s[], int num)
{
    //定义随机生成字符串表
    char *str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int i, lstr;
    char ss[2] = {0};
    
    lstr = strlen(str);//计算字符串长度
    OTA_srand((unsigned int)OTA_kal_get_systicks());//使用系统时间来初始化随机数发生器
    for(i = 1; i <= num; i++) //按指定大小返回相应的字符串
    {
        sprintf(ss, "%c", str[(OTA_rand() % lstr)]); //rand()%lstr 可随机返回0-71之间的整数, str[0-71]可随机得到其中的字符
        strcat(s, ss); //将随机生成的字符串连接到指定数组后面
    }
    return s;
}

static void init(void)
{
    applib_time_struct currTime = {0};
    //static char g_callee[16] = {0};          // 机主手机号码
    // 设备内置号码或IMSI
    snprintf(g_caller, 21, "%s", (char *)track_drv_get_imsi(0));
    LOGD(L_APP, L_V4, "caller:%s", g_caller);
    // 20位随机字符串
    get_rand_str(g_nonceStr, 20);
    LOGD(L_APP, L_V4, "nonceStr:%s", g_nonceStr);
    // 时间戳
    track_fun_get_time(&currTime, KAL_TRUE, NULL);
    snprintf(g_timestamp, 21, "%d-%0.2d-%0.2d", currTime.nYear, currTime.nMonth, currTime.nDay);
    LOGD(L_APP, L_V4, "timestamp:%s", g_timestamp);
}

static void SIM_findBalance()
{
    U8 *p = (U8*)Ram_Alloc(5, 1501);
    U8 *m = p + 1000;
    
    init();
    snprintf(p, 1000, "%sappId%snonceStr%snumber%stimestamp%s%s", 
        g_privateKey, g_publicKey, 
        g_nonceStr, 
        g_caller, 
        g_timestamp, 
        g_privateKey);
    LOGD(L_APP, L_V4, "1[%d]=%s", strlen(p), p);
    track_fun_SHA1_Perform_string(p, strlen(p), g_signature);
    LOGD(L_APP, L_V4, "2[%d]=%s", strlen(g_signature), g_signature);
    memset(p, 0, 1501);
    snprintf(m, 500, "%sappId%s:%s%s%s,%stimestamp%s:%s%s%s,%snonceStr%s:%s%s%s,%ssignature%s:%s%s%s,%snumber%s:%s%s%s", 
        g_dq, g_dq, g_dq,
        g_publicKey,
        g_dq, g_dq, g_dq, g_dq,
        g_timestamp,
        g_dq, g_dq, g_dq, g_dq,
        g_nonceStr,
        g_dq, g_dq, g_dq, g_dq,
        g_signature,
        g_dq, g_dq, g_dq, g_dq,
        g_caller,
        g_dq);
    LOGD(L_APP, L_V4, "3[%d]=%s", strlen(m), m);
    snprintf(p, 1000, "%s%s%s%s%s%s%s", g_http_head[0], g_http_head[2], g_http_head[3], m, g_http_head[4], g_http_head[5], g_http_head[6]);
    LOGD(L_APP, L_V4, "4[%d]=%s", strlen(p), p);
    LOGD(L_APP, L_V4, "5[%d]", (S8)Socket_write_req(APP_NO, p, strlen(p), 0, 0, 0, 1));
    Ram_Free(p);
}

static void SIM_findSignal()
{
    U8 *p = (U8*)Ram_Alloc(5, 1501);
    U8 *m = p + 1000;

    init();
    snprintf(p, 1000, "%sappId%scallee%scaller%snonceStr%stimestamp%s%s", 
        g_privateKey, g_publicKey, 
        g_callee,
        g_caller, 
        g_nonceStr, 
        g_timestamp, 
        g_privateKey);
    LOGD(L_APP, L_V4, "1[%d]=%s", strlen(p), p);
    track_fun_SHA1_Perform_string(p, strlen(p), g_signature);
    LOGD(L_APP, L_V4, "2[%d]=%s", strlen(g_signature), g_signature);
    memset(p, 0, 1501);
    snprintf(m, 500, "%sappId%s:%s%s%s,%stimestamp%s:%s%s%s,%snonceStr%s:%s%s%s,%ssignature%s:%s%s%s,%scallee%s:%s%s%s,%scaller%s:%s%s%s", 
        g_dq, g_dq, g_dq,
        g_publicKey,
        g_dq, g_dq, g_dq, g_dq,
        g_timestamp,
        g_dq, g_dq, g_dq, g_dq,
        g_nonceStr,
        g_dq, g_dq, g_dq, g_dq,
        g_signature,
        g_dq, g_dq, g_dq, g_dq,
        g_callee,
        g_dq, g_dq, g_dq, g_dq,
        g_caller,
        g_dq);
    LOGD(L_APP, L_V4, "3[%d]=%s", strlen(m), m);
    snprintf(p, 1000, "%s%s%s%s%s%s%s", g_http_head[0], g_http_head[1], g_http_head[3], m, g_http_head[4], g_http_head[5], g_http_head[6]);
    LOGD(L_APP, L_V4, "4[%d]=%s", strlen(p), p);
    LOGD(L_APP, L_V4, "5[%d]", (S8)Socket_write_req(APP_NO, p, strlen(p), 0, 0, 0, 1));
    Ram_Free(p);
}

static void connect_success(void)
{
    if(fun == NULL) socket_disconnect(2);
    else fun();
}

static void event3(track_soc_Callback_struct *par)
{
    static kal_uint32 re_conn = 0;
    LOGD(L_APP, L_V4, "status=%d error=%d", par->status, par->errorid);
    switch(par->status)
    {
        case SOC_CONNECT_SUCCESS:
            {
                if(fun == NULL) socket_disconnect(APP_NO);
                else fun();
                break;
            }
        case SOC_CONNECT_ServerNotResponding:
            {
                break;
            }
        case SOC_CONNECT_CLOSE:
            {
                LOGD(L_APP, L_V4, "连接3关闭");
                break;
            }
        case SOC_RECV_DATA:
            {
                if(strstr(par->recvBuff, "200 OK\r\n"))
                {
                    char *m, *p = strstr(par->recvBuff, "\"message\":\"");
                    if(p && par->recvBuffLen > p - par->recvBuff + 27)
                    {
                        p += 11;
                        m = strstr(par->recvBuff, "\\n");
                        *m = 0;
                        LOGD(L_APP, L_V4, "结果: %s", p);
                    }
                }
                else
                {
                    char *p = strstr(par->recvBuff, "\r\n\r\n");
                    if(p)
                    {
                        LOGD(L_APP, L_V4, "结果: %s", p);
                        LOGD(L_APP, L_V6, "%s", par->recvBuff);
                        LOGH(L_APP, L_V6, par->recvBuff, par->recvBuffLen);
                    }
                    else
                    {
                        LOGD(L_APP, L_V4, "%s", par->recvBuff);
                        LOGH(L_APP, L_V4, par->recvBuff, par->recvBuffLen);
                    }
                }
                break;
            }
        case SOC_SEND_DATA:
            {
                break;
            }
        case SOC_RECV_HOST_BY_NAME:
            {
                if(par->errorid != 0)
                {
                    LOGD(L_APP, L_V1, "errorid=%d", par->errorid);
                }
                else
                {
                    sockaddr_struct ip_addr = {0};
                    kal_int8 ret;
                    ip_addr.port = 80;
                    LOGD(L_APP, L_V4, "hostname to IP:%d.%d.%d.%d:%d",
                         par->ip_from_hostname[0], par->ip_from_hostname[1],
                         par->ip_from_hostname[2], par->ip_from_hostname[3],
                         ip_addr.port);
                    ip_addr.addr_len = 4;
                    memcpy(ip_addr.addr, par->ip_from_hostname, 4);
                    ret = Socket_conn_req(APP_NO, &ip_addr, event3, 0);
                    LOGD(L_APP, L_V1, "ret=%d", ret);
                }
                break;
            }
    }
}

static void track_cust_server3_conn(void)
{
    sockaddr_struct ip_addr = {0};
    kal_int8 ret;
    kal_uint16 crc;
    char *domain;

    LOGD(L_APP, L_V4, "连接3联网入口");
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
        tr_start_timer(TRACK_CUST_NET_CONN_TIMER_ID3, 5000, track_cust_server3_conn);
        return;
    }

    if(!G_parameter.gprson)
    {
        LOGD(L_APP, L_V4, " 不联网");
        return;
    }

    Socket_gethostbyname("plat.cxsz.com.cn", event3);
}

void track_cust_SIM_call(char *phone)
{
    snprintf(g_callee, 16, "%s", phone);
    fun = SIM_findSignal;
    track_cust_server3_conn();
}

void track_cust_SIM_findBalance()
{
    fun = SIM_findBalance;
    track_cust_server3_conn();
}
#endif /* __SIM_CU_CALL__ */

