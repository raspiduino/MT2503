#if defined(__OBD_SRD__)
/*******************************************************************************************
 * Filename:  速锐得OBD
 * Author :
 * Date :
 * Comment:

volt	volt	电压，	303	13.5,	float
rotation rate	rotation rate	转速，	363	824,	int
speed	speed	速度，	353	0,	int
Throttle opening		节气门开度，		17.25,	float
Engine load		发动机负荷，		38.43 ,	float
CoolantTEMP		冷却液温度，	2D3	105,	int
Instantaneous fuel consumption	Instantaneous fuel consumption	瞬时油耗，	384	1.50,	float
Average fuel consumption	Average fuel consumption	平均油耗，	374	12.02,	float
The driving range		本次行驶里程，		12.05,	float
Total mileage	Total mileage	总里程，	284	12,	int
oil consumption	oil consumption	本次耗油量，	2C4	1.55,	float
Total fuel consumption		累计耗油量，		1.55,	float
Current fault code/number		当前故障码 数量，		0,	int
Rapid acceleration times		本次急加速次数，		8,	int
Rapid deceleration times		本次急减速次数		1	int

 ******************************************************************************************/

/****************************************************************************
*  Include Files                        包含头文件
*****************************************************************************/
#include "track_cust.h"
#include "c_vector.h"

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/
#define OBD_PARAMETER_MAX   30

/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/


/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static S8 obd_acc = 0;
static S8 idling = 0;
static S8 upload_type = 1;
static char g_obd_vin[20] = {0};
static char g_obd_type[20] = {0};   //OBD协议类型
static char g_obd_sn[20] = {0};     //OBD模块SN号
static char g_obd_hw_ver[20] = {0}; //硬件版本
static char g_obd_ver[20] = {0};    //软件版本
static char *obd_parameters[OBD_PARAMETER_MAX] = {0};
static float value_RT[OBD_PARAMETER_MAX] = {0};
static U8 value_RT_valid[OBD_PARAMETER_MAX] = {0};
static float value_TT[OBD_PARAMETER_MAX] = {0};
static U8 value_TT_valid[OBD_PARAMETER_MAX] = {0};
const static char *obd_status_RT_string[][2] =
{
    "电压",              "303",         /* 0 */
    "转速",              "363",
    "速度",              "353",
    "节气门开度",        "443",
    "发动机负荷",        "433",
    "冷却液温度",        "2D3",         /* 5 */
    "瞬时油耗",          "384",
    "平均油耗",          "374",
    "本次行驶里程",      "",
    "总里程",            "284",
    "本次耗油量",        "2C4",         /* 10 */
    "累计耗油量",        "",
    "当前故障码 数量",   "",
    "本次急加速次数",    "",
    "本次急减速次数",    "",
    "ACC",               "223"          /* 15 */
};
const static char *obd_status_TT_string[][2] =
{
    "本次热车时长",             "844",         /* 0 */
    "本次怠速时长",             "814",
    "本次行驶时长",             "",
    "本次行驶里程",             "",
    "本次怠速油耗",             "",
    "本次行驶耗油",             "",            /* 5 */
    "本次最高转速",             "",
    "本次最高车速",             "804",
    "本次急加速测试",           "",
    "本次急减速测试",           ""
};
static c_vector* vec_send_uart_queue = NULL;
static CMD_DATA_STRUCT *obd_odometer_data = NULL;
static CMD_DATA_STRUCT *obd_clear_data = NULL;
static CMD_DATA_STRUCT *obd_version_data = NULL;
static CMD_DATA_STRUCT *obd_vin_data = NULL;

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
void track_cust_obd_write(kal_uint8 *data, int len);
static void obd_data_upload(U32 arg);
static void track_obd_odometer(CMD_DATA_STRUCT *cmd);
void track_obd_getVIN(CMD_DATA_STRUCT * cmd);
void track_obd_clear(CMD_DATA_STRUCT * cmd);
void track_obd_version(CMD_DATA_STRUCT * cmd);
void track_cust_cmd_reply(cmd_return_struct *return_sms, char *data, int len);
void obd_upload_time_update_parameter(void *arg);
#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/

static void track_cust_obd_data_powerOn(S8 on)
{
    static S8 _on = -1;
    if(_on != on)
    {
        if(on)
        {
            obd_acc = 1;
            value_RT[15] = 1;
            value_RT_valid[15] = 1;
            acc_status_change((void*)1);
            LOGD(L_OBD, L_V5, "点火");
            track_os_intoTaskMsgQueueExt(obd_data_upload, (void*)1);
        }
        else
        {
            obd_acc = 0;
            value_RT[15] = 0;
            value_RT_valid[15] = 1;
            acc_status_change((void*)0);
            LOGD(L_OBD, L_V5, "熄火");
            track_os_intoTaskMsgQueueExt(obd_data_upload, (void*)1);
        }
        _on = on;
    }
}

static void track_cust_obd_cmd_get_errorId(void)
{
    char * cmd = "AT400\r\n";
    track_cust_obd_write(cmd, strlen(cmd));
}

static void track_cust_obd_data_idling(S8 st)
{
    static S8 idling = -1;
    if(idling != st)
    {
        if(st)
        {
            LOGD(L_OBD, L_V5, "怠速");
            track_cust_obd_cmd_get_errorId();
        }
        else
        {
            LOGD(L_OBD, L_V5, "非怠速状态");
        }
        idling = st;
    }
}

static void track_cust_obd_dramatic_changes_in_speed(S8 type, U32 st)
{
    const char *plus_str = "824=DC", *less_str = "834=14D";
    static U32 plus = 0, less = 0;
    char *buf = NULL;
    LOGD(L_OBD, L_V5, "");
    if(type && st != plus)
    {
        plus = st;
        buf = (char *)plus_str;
        LOGD(L_OBD, L_V5, "急加速");
    }
    else if(!type && st != less)
    {
        less = st;
        buf = (char *)less_str;
        LOGD(L_OBD, L_V5, "急减速");
    }

    if(buf != NULL)
    {
        if(track_soc_login_status())
            track_cust_paket_8C(0, obd_acc, buf, strlen(buf));
        else
            track_cust_paket_8C(1, obd_acc, buf, strlen(buf));
    }
}

static void obd_data_for_errorId_upload(char *data)
{
    int i, j = 0, obd_parameters_count = 0;
    static char buf[1000];
    static char buf_last[1000];
    char *p = buf;
    char *s = strchr(data, ',');
    if(s == NULL) return;
    s++;
    if(!strcmp(data, buf_last)) return;
    snprintf(buf_last, 999, "%s", data);
    obd_parameters_count = track_fun_str_analyse(s, obd_parameters, OBD_PARAMETER_MAX, NULL, "\r\n", '|');

    LOGD(L_OBD, L_V5, "obd_parameters_count:%d\r\n", obd_parameters_count);
    memset(buf, 0, 1000);
    for(i = 0; i < obd_parameters_count; i++)
    {
        if(obd_parameters[i][0] == 'P')
        {
            if(!j)
            {
                j = sprintf(p, "999=03%s", &obd_parameters[i][1]);
            }
            else
            {
                j = sprintf(p, ",999=03%s", &obd_parameters[i][1]);
            }
            p += j;
            if(p - buf > 999)
            {
                LOGD(L_OBD, L_V1, "ERROR : Data too long!");
                return;
            }
        }
    }

    if(buf != NULL && track_soc_login_status())
        track_cust_paket_8C(0, obd_acc, buf, strlen(buf));
    else
        track_cust_paket_8C(1, obd_acc, buf, strlen(buf));
}
static int track_cust_obd_data_flow_RT(char *data)
{
    static kal_bool first = 1;
    int i, obd_parameters_count = 0;
    obd_parameters_count = track_fun_str_analyse(data, obd_parameters, OBD_PARAMETER_MAX, NULL, "\r\n", ',');
    if(obd_parameters_count != 15)
    {
        LOGD(L_OBD, L_V5, "个数不对! obd_parameters_count:%d", obd_parameters_count);
        return -1;
    }
    LOGD(L_OBD, L_V6, "obd_parameters_count:%d", obd_parameters_count);

    for(i = 0; i < obd_parameters_count && i < OBD_PARAMETER_MAX; i++)
    {
        if(value_RT[i] != atof(obd_parameters[i]))
        {
            value_RT[i] = atof(obd_parameters[i]);
            if(i == 10) value_RT[i] *= 100000;
			else if(i == 0) value_RT[i] *= 1000000;
            else value_RT[i] *= 100;
            value_RT_valid[i] = 1;
        }
        if(strlen(obd_status_RT_string[i][1]) > 0)
            LOGD(L_OBD, L_V6, "%s[%s]:%0.2f,%d", obd_status_RT_string[i][0], obd_status_RT_string[i][1], value_RT[i], value_RT_valid[i]);
    }
    first = 0;
    if(value_RT[0] > 0) track_drv_set_volt_from_obd(value_RT[0]);
    if(value_RT[1] > 0) track_cust_obd_data_powerOn(1);
    if(value_RT[13] > 0) track_cust_obd_dramatic_changes_in_speed(1, value_RT[13]);
    if(value_RT[14] > 0) track_cust_obd_dramatic_changes_in_speed(0, value_RT[14]);
    if(value_RT[1] > 0 && value_RT[2] == 0) track_cust_obd_data_idling(1);
    else track_cust_obd_data_idling(0);
    return 0;
}

static int track_cust_obd_data_flow_TT(char *data)
{
    static kal_bool first = 1;
    int i, obd_parameters_count = 0;
    obd_parameters_count = track_fun_str_analyse(data, obd_parameters, OBD_PARAMETER_MAX, NULL, "\r\n", ',');
    if(obd_parameters_count != 10)
    {
        LOGD(L_OBD, L_V5, "个数不对! obd_parameters_count:%d", obd_parameters_count);
        return -1;
    }
    LOGD(L_OBD, L_V6, "obd_parameters_count:%d", obd_parameters_count);

    for(i = 0; i < obd_parameters_count && i < 10; i++)
    {
        if(value_TT[i] != atof(obd_parameters[i]))
        {
            value_TT[i] = atof(obd_parameters[i]);
            if(i == 1) value_TT[i] *= 6000;
            else value_TT[i] *= 100;
            value_TT_valid[i] = 1;
        }
        if(strlen(obd_status_TT_string[i][1]) > 0)
            LOGD(L_OBD, L_V6, "%s[%s]:%0.2f,%d", obd_status_TT_string[i][0], obd_status_TT_string[i][1], value_TT[i], value_TT_valid[i]);
    }
    first = 0;
    return 0;
}

/******************************************************************************
 *  Function    -  obd_get_data
 *
 *  Purpose     -  取得数据并上传平台
 *
 *  Description -
 *
 *  modification history
 * ----------------------------------------
 * v1.0  , 02-04-2014,  Cml  written
 * ----------------------------------------
*******************************************************************************/
static void obd_data_upload(U32 arg)
{
    static char buf[1000];
    U32 va = 0;
    int i, j = 0, k;
    kal_bool acc_low = 0;
    char *p = buf;
    
    memset(buf, 0, 1000);
    LOGD(L_OBD, L_V5, "arg:%d, upload_type:%d", arg, upload_type);
    if(upload_type == 1) upload_type = 0;
    k = sizeof(obd_status_RT_string) / 8;
    for(i = 0; i < OBD_PARAMETER_MAX && i < k; i++)
    {
        if((arg == 1 || value_RT_valid[i] == 1) && strlen(obd_status_RT_string[i][1])>0)
        {
            if(p - buf > 950)
            {
                LOGD(L_OBD, L_V1, "ERROR : Data too long!");
                return;
            }
            va = value_RT[i];
            if(!j)
            {
                j = sprintf(p, "%s=%X", obd_status_RT_string[i][1], va);
            }
            else
            {
                j = sprintf(p, ",%s=%X", obd_status_RT_string[i][1], va);
            }
            p += j;
            if(i == 15)
            {
                if(va == 0) acc_low = 1;
                value_RT_valid[i] = 0;
            }
        }
    }
    if(acc_low)
    {
        k = sizeof(obd_status_TT_string) / 8;
        for(i = 0; i < OBD_PARAMETER_MAX && i < k; i++)
        {
            if((arg == 1 || value_TT_valid[i] == 1) && strlen(obd_status_TT_string[i][1])>0)
            {
                if(p - buf > 950)
                {
                    LOGD(L_OBD, L_V1, "ERROR : Data too long!");
                    return;
                }
                va = value_TT[i];
                if(!j)
                {
                    j = sprintf(p, "%s=%X", obd_status_TT_string[i][1], va);
                }
                else
                {
                    j = sprintf(p, ",%s=%X", obd_status_TT_string[i][1], va);
                }
                p += j;
                value_TT_valid[i] = 0;
            }
        }
    }
    //LOGD(L_OBD, L_V1, "ALL: %s\r\n", buf);
    if(p == buf)
    {
        LOGD(L_OBD, L_V5, "OBD无变化的数据需要上传");
        return;
    }
    /*if(track_soc_login_status())
        track_cust_paket_8C(0, obd_acc, buf, strlen(buf));
    else*/
        track_cust_paket_8C(1, obd_acc, buf, strlen(buf));
}



/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
void track_cust_obd_data(kal_uint8 *data, int len)
{
    static kal_uint8  buf[2000] = {0};
    static kal_uint32 flag = 0;
    static kal_uint32 tick = 0;
    static int last_len = 0;
    kal_uint8 *start = NULL, *end = NULL;
    int j = 0, x;

    //LOGD(L_OBD, L_V7, "[1 recv] %s", data);

    if(len <= 1) return;

    /* if(tick > 0 && OTA_kal_get_systicks() - tick > OTA_kal_secs_to_ticks(20))
     {
         flag = 0;
     }
     tick = OTA_kal_get_systicks();*/

    if(flag + len < 1999)
    {
        for(j = 0; j < len; j++)
        {
            if(data[j] > 0 && data[j] <= 128)
            {
                buf[flag++] = data[j];
            }
        }
        buf[flag] = 0;
    }
    else
    {
        if(len > 1999)
        {
            LOGD(L_OBD, L_V1, "ERROR : Data too long!");
            return;
        }
        for(j = 0, flag = 0; j < len; j++)
        {
            if(data[j] > 0 && data[j] <= 126)
            {
                buf[flag++] = data[j];
            }
        }
        buf[flag] = 0;
    }
    //  LOGD(L_OBD, L_V5, "[recv](%d,%d,%d): %s", strlen(buf), flag, len, data);
    //  LOGH(L_OBD, 6, buf, flag);
    if(flag <= 0) return;
    buf[flag] = 0;
    //if(len == 2 && data[0] == 0x0D && data[1] == 0x0A) return;
    //LOGD(L_OBD, L_V2, "[%d] %s", len, data);
    //LOGD(L_OBD, L_V6, "1 flag:%d, buf:%p, start:%p, end:%p", flag, buf, start, end);
    LOGD(L_OBD, L_V9, "[recv] %s", buf);
    for(j = 0; j < flag - 5; j++)
    {
        if(buf[j] == '$')
        {
            obd_upload_time_update_parameter((void*)0);
            start = &buf[j] + 1;
            end = strchr(start, '\n');
            if(end == NULL) break;
            *end = 0;
            LOGD(L_OBD, L_V7, "[recv %d] %s", j, &buf[j]);
            j = end - buf;
            if(start == strstr(start, "OBD-RT,"))
            {
                if(track_cust_obd_data_flow_RT(start + 7) < 0) continue;
            }
            else if(start == strstr(start, "OBD-TT,"))
            {
                track_cust_obd_data_powerOn(0);
                if(track_cust_obd_data_flow_TT(start + 7) < 0) continue;
            }
            else if(start == strstr(start, "296="))
            {
                //$296=1D4GP00R55B123456
                snprintf(g_obd_vin, 19, "%s", start + 4);
                LOGD(L_OBD, L_V6, "VIN:%s", g_obd_vin);
                track_obd_getVIN(obd_vin_data);
            }
            else if(start == strstr(start, "400="))
            {
                //LOGD(L_OBD, L_V6, "obd故障码:%s\r\n", start+4);
                obd_data_for_errorId_upload(start + 4);
            }
            else if(start == strstr(start, "500="))
            {
                //$500=OBD协议类型，   OBD模块SN号，硬件版本， 软件版本
                //$500=CANBUS_11B_250K,944131078177,V160402_M5,V7.5.6
                start += 4;
                end = strchr(start, ',');
                if(end == NULL)
                {
                    snprintf(g_obd_type, 19, "%s", start);
                    continue;
                }
                *end = 0;
                snprintf(g_obd_type, 19, "%s", start);
                start = end + 1;
                end = strchr(start, ',');
                if(end == NULL)
                {
                    snprintf(g_obd_sn, 19, "%s", start);
                    continue;
                }
                *end = 0;
                snprintf(g_obd_sn, 19, "%s", start);
                start = end + 1;
                end = strchr(start, ',');
                if(end == NULL)
                {
                    snprintf(g_obd_hw_ver, 19, "%s", start);
                    continue;
                }
                *end = 0;
                snprintf(g_obd_hw_ver, 19, "%s", start);
                start = end + 1;
                end = strchr(start, ',');
                if(end != NULL)
                {
                    *end = 0;
                }
                snprintf(g_obd_ver, 19, "%s", start);
                track_obd_version(obd_version_data);
            }
            else if(start == strstr(start, "EST527,"))
            {
                start += 7;
                if(start == strstr(start, "STATUS ON"))
                {
                    track_cust_obd_data_powerOn(1);
                }
                else if(start == strstr(start, "STATUS OFF"))
                {
                    track_cust_obd_data_powerOn(0);
                }
                else if(start == strstr(start, "System sleeping"))
                {
                    track_cust_obd_data_powerOn(0);
                    track_stop_timer(TRACK_CUST_OBD_CXALL_TIMER_ID);
                }
                else if(strstr(start, "System running..."))
                {

                }
                else if(strstr(start, "Erase data OK"))
                {
                    track_obd_clear(obd_clear_data);
                }
                else if(strstr(start, "AT302"))
                {
                    track_obd_odometer(obd_odometer_data);
                }
            }
        }
    }
    //LOGD(L_OBD, L_V2, "2 flag:%d, buf:%p, start:%p, end:%p", flag, buf, start, end);
    if(start == NULL)
    {
        return;
    }
    if(end == 0 && start > buf)
    {
        return;
    }
    if(end > buf)
    {
        kal_uint8 *bb;
        if(*(end + 1) == 0x0a) end += 2;
        if(flag == (end - buf))
        {
            flag = 0;
        }
        else if(flag > (end - buf))
        {
            flag -= (end - buf);
            if(flag > 2000)
            {
                LOGD(L_OBD, L_V1, "error");
                return;
            }
            bb = (U8*)Ram_Alloc(6, flag);
            if(bb == NULL)
            {
                LOGD(L_OBD, L_V1, "error 2");
                return;
            }
            memcpy(bb, end, flag);
            memset(buf, 0, 2000);
            memcpy(buf, bb, flag);
            Ram_Free(bb);
        }
    }
    // LOGD(L_OBD, L_V6, "3 flag:%d, buf:%p, start:%p, end:%p", flag, buf, start, end);
    //if(upload_type > 0) obd_data_upload(0);
}

static void obd_write_data()
{
    static U8 cc = 0;
    int v_size;
    if(NULL == vec_send_uart_queue)
    {
        VECTOR_CreateInstance(vec_send_uart_queue);
    }
    v_size = VECTOR_Size(vec_send_uart_queue);
    LOGD(L_OBD, L_V5,  "VECTOR:%d", v_size);
    if(v_size <= 0)
    {
        LOGD(L_OBD, L_V5, "No data to be sent.");
        return;
    }
    {
        if(v_size > 0)
        {
            U8 *buf;
            buf = VECTOR_At(vec_send_uart_queue, 0);
            if(buf != NULL)
            {
                U16 len;
                len = (buf[0] << 8) + buf[1];
                track_drv_uart3_write_data(&buf[2], len);
            }
            VECTOR_Erase(vec_send_uart_queue, 0, 1);
            v_size--;
        }
    }
    if(v_size > 0) tr_start_timer(TRACK_CUST_OBD_UART_WRITE_ID, 200, obd_write_data);
}

void track_cust_obd_write(kal_uint8 *data, int len)
{
    int v_size;
    LOGD(L_OBD, L_V4, "%d,%d", strlen(data), len);
    LOGH(L_OBD, L_V2, data, len);
    if(len > 2048)
    {
        LOGD(L_OBD, L_V1, "ERROR");
        return;
    }
    else
    {
        U8 *buf = (U8*)Ram_Alloc(3, len + 10);

        if(NULL == vec_send_uart_queue)
        {
            VECTOR_CreateInstance(vec_send_uart_queue);
        }
        v_size = VECTOR_Size(vec_send_uart_queue);
        LOGD(L_OBD, L_V5,  "VECTOR:%d, data_len=%d", v_size, len);
        if(buf)
        {
            buf[0] = (len >> 8);
            buf[1] = (len & 0x00FF);
            memcpy(&buf[2], data, len);
            VECTOR_PushBack(vec_send_uart_queue, buf);
            if(!track_is_timer_run(TRACK_CUST_OBD_UART_WRITE_ID))
                tr_start_timer(TRACK_CUST_OBD_UART_WRITE_ID, 200, obd_write_data);
        }
    }
}

char *track_obd_get_version(void)
{
    if(strlen(g_obd_hw_ver) > 0 || strlen(g_obd_ver) > 0)
    {
        static char data[100] = {0};
        sprintf(data, "HARDWARE: %s, SOFTWARE: %s", g_obd_hw_ver, g_obd_ver);
        return data;
    }
    else return "";
}

void obd_poweron(kal_uint32 on)
{
	if(on >= 30)
	{
		GPIO_WriteIO(1, OBD_POWER_GPIO);
	}
	else
	{
		GPIO_WriteIO(0, OBD_POWER_GPIO);
	}
}

void obd_upload_time_update_parameter(void *arg)
{
    /* 定时上报数据的间隔时间 */
    /* G_parameter.obd.upload_time */
    if((U32)arg == 2)
    {/* 指令修改间隔时间，仅仅在定时器有效的状态下才立即刷新 */
        if(track_is_timer_run(TRACK_CUST_OBD_CXALL_TIMER_ID))
            track_start_timer(TRACK_CUST_OBD_CXALL_TIMER_ID,
                      G_parameter.obd.upload_time * 1000,
                      obd_upload_time_update_parameter,
                      (void*)1);
        return;
    }
    else if((U32)arg == 1 && upload_type == 0)
    {
        track_os_intoTaskMsgQueueExt(obd_data_upload, (void*)0);;
    }
    if(!track_is_timer_run(TRACK_CUST_OBD_CXALL_TIMER_ID))
        track_start_timer(TRACK_CUST_OBD_CXALL_TIMER_ID,
                      G_parameter.obd.upload_time * 1000,
                      obd_upload_time_update_parameter,
                      (void*)1);
}

void track_cust_obd_tc(char *cmd, int len)
{
    track_cust_obd_write(cmd, len);
    LOGD(L_OBD, L_V4, "%d,%d", strlen(cmd), len);
    LOGH(L_OBD, L_V2, cmd, len);
}

void track_cust_obd_testcmd(char *outString, CMD_DATA_STRUCT * cmd)
{
    
}

void track_obd_clsobd(CMD_DATA_STRUCT * cmd)
{
    //char *str = "AT^U=CLSOBD,";
    //track_cust_obd_write(str, strlen(str));
}

void track_obd_getErrorId(CMD_DATA_STRUCT * cmd)
{
    /*char *str = "AT^U=READOBD,";
    track_cust_obd_write(str, strlen(str));
    if(cmd != NULL)
    {
        memcpy(&reply, &cmd->return_sms, sizeof(reply));
        tr_start_timer(TRACK_CUST_OBD_CMD_TIMER_ID, 60000, track_obd_cmd_overtime);
    }
    else
    {
        tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 30000, obd_cx_cycle);
    }*/
}

void track_obd_version(CMD_DATA_STRUCT * cmd)
{
    if(cmd == NULL) return;
    LOGD(L_OBD, L_V4, "%d", cmd->supercmd);
    if(cmd->supercmd == 0)
    {
        if(strlen(g_obd_hw_ver) > 0 || strlen(g_obd_ver) > 0)
        {
            sprintf(cmd->rsp_msg, "HARDWARE: %s, SOFTWARE: %s", g_obd_hw_ver, g_obd_ver);
			//LOGS("OBD--HARDWARE: %s, SOFTWARE: %s", g_obd_hw_ver, g_obd_ver);
        }
        else
        {
            CMD_DATA_STRUCT *return_sms;
            return_sms = (CMD_DATA_STRUCT *)Ram_Alloc(5, sizeof(CMD_DATA_STRUCT));
            memcpy(return_sms, cmd, sizeof(CMD_DATA_STRUCT));
            return_sms->supercmd = 2;
            obd_version_data = return_sms;
            track_start_timer(TRACK_CUST_OBD_CMD_VERSION_TIMER_ID, 20000, track_obd_version, return_sms);
            track_cust_obd_write("AT500\r\n", 7);
        }
    }
    else if(cmd->supercmd == 2 && obd_version_data != NULL)
    {
        char data[60] = {0};
        sprintf(data, "Fail to search, please try again.");
        if(track_is_timer_run(TRACK_CUST_OBD_CMD_VERSION_TIMER_ID))
        {
            if(strlen(g_obd_hw_ver) > 0 || strlen(g_obd_ver) > 0)
                sprintf(data, "HARDWARE: %s, SOFTWARE: %s", g_obd_hw_ver, g_obd_ver);
        }
        track_cust_cmd_reply(&cmd->return_sms, data, strlen(data));
        track_stop_timer(TRACK_CUST_OBD_CMD_VERSION_TIMER_ID);
        Ram_Free(cmd);
        obd_version_data = NULL;
    }
}

void track_obd_clear(CMD_DATA_STRUCT * cmd)
{
    if(cmd == NULL) return;
    if(cmd->supercmd == 0)
    {
        CMD_DATA_STRUCT *return_sms;
        if(obd_version_data != NULL)
        {
            sprintf(cmd->rsp_msg, "The system is busy, try again.");
            return;
        }
        return_sms = (CMD_DATA_STRUCT *)Ram_Alloc(5, sizeof(CMD_DATA_STRUCT));
        memcpy(return_sms, cmd, sizeof(CMD_DATA_STRUCT));
        return_sms->supercmd = 2;
        obd_clear_data = return_sms;
        track_start_timer(TRACK_CUST_OBD_CMD_CLEAR_TIMER_ID, 20000, track_obd_clear, return_sms);
        track_cust_obd_write("AT501\r\n", 7);
    }
    else if(cmd->supercmd == 2 && obd_clear_data != NULL)
    {
        char data[60] = {0};
        if(track_is_timer_run(TRACK_CUST_OBD_CMD_CLEAR_TIMER_ID))
        {
            snprintf(data, 50, "Erase data OK.");
        }
        else
        {
            snprintf(data, 50, "Erase data Failed, please try again.");
        }
        track_cust_cmd_reply(&cmd->return_sms, data, strlen(data));
        track_stop_timer(TRACK_CUST_OBD_CMD_CLEAR_TIMER_ID);
        Ram_Free(cmd);
        obd_clear_data = NULL;
    }
}

void track_obd_getVIN(CMD_DATA_STRUCT * cmd)
{
	LOGD(L_OBD, L_V6, "supercmd:%d",cmd->supercmd);
//	LOGD(L_OBD, L_V6, "VIN:%s", g_obd_vin);
//	LOGD(L_OBD, L_V6, "VIN:%d", strlen(g_obd_vin));
    if(cmd->supercmd == 0)
    {
        if(strlen(g_obd_vin) > 0)
        {
        	if(cmd != NULL)
            sprintf(cmd->rsp_msg, "VIN:%s", g_obd_vin);
        }
        else
        {
            CMD_DATA_STRUCT *return_sms;
            return_sms = (CMD_DATA_STRUCT *)Ram_Alloc(5, sizeof(CMD_DATA_STRUCT));
            memcpy(return_sms, cmd, sizeof(CMD_DATA_STRUCT));
            return_sms->supercmd = 2;
            obd_vin_data = return_sms;
            track_start_timer(TRACK_CUST_OBD_CMD_VIN_TIMER_ID, 20000, track_obd_getVIN, return_sms);
            track_cust_obd_write("AT296\r\n", 7);
        }
    }
    else if(cmd->supercmd == 2 && obd_vin_data != NULL)
    {
        char data[60] = {0};
        sprintf(data, "VIN: (Fail to search, the current device may not support.)");
        if(track_is_timer_run(TRACK_CUST_OBD_CMD_VIN_TIMER_ID))
        {
            if(strlen(g_obd_vin) > 0)
                snprintf(data, 50, "VIN: %s", g_obd_vin);
        }
        track_cust_cmd_reply(&cmd->return_sms, data, strlen(data));
        Ram_Free(cmd);
        obd_vin_data = NULL;
    }
}

static void track_obd_odometer(CMD_DATA_STRUCT *cmd)
{
    if(obd_odometer_data)
    {
        char data[50] = {0};
        if(track_is_timer_run(TRACK_CUST_OBD_CMD_ODOMETER_TIMER_ID))
        {
            sprintf(data, "OK.");
        }
        else
        {
            sprintf(data, "Setting failed, please try again.");
        }
        if(cmd)
        {
            track_cust_cmd_reply(&cmd->return_sms, data, strlen(data));
            Ram_Free(cmd);
        }
    }
    track_stop_timer(TRACK_CUST_OBD_CMD_ODOMETER_TIMER_ID);
    obd_odometer_data = NULL;
}

void track_obd_setcar_and_odometer(CMD_DATA_STRUCT * cmd, U8 car, U32 total_mileage)
{
    if(total_mileage > 0)
    {
        CMD_DATA_STRUCT *return_sms;
        char data[50] = {0};
        if(obd_odometer_data != NULL)
        {
            sprintf(cmd->rsp_msg, "The system is busy, try again.");
            return;
        }
        snprintf(data, 50, "AT302=%d\r\n", total_mileage);
        return_sms = (CMD_DATA_STRUCT *)Ram_Alloc(5, sizeof(CMD_DATA_STRUCT));
        memcpy(return_sms, cmd, sizeof(CMD_DATA_STRUCT));
        return_sms->supercmd = 2;
        obd_odometer_data = return_sms;
        track_start_timer(TRACK_CUST_OBD_CMD_ODOMETER_TIMER_ID, 20000, track_obd_odometer, return_sms);
        track_cust_obd_write(data, strlen(data));
    }
}

void track_cust_obd_update_fireware(U8 *data, U32 len)
{
    
}

void track_cust_module_ext_vbat_to_obd(kal_uint32 volt)
{
}

void track_obd_acc(void *arg)
{

}

void track_cust_obd_opendata(void)
{
    obd_upload_time_update_parameter((void*)1);
}

kal_uint8 track_cust_module_obd_get_acc(void)
{
    return (U8)obd_acc;
}
#endif /* __OBD_SRD__ */
