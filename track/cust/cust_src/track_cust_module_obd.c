#if defined(__OBD_1__)
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

/*****************************************************************************
*  Define                               宏定义
******************************************************************************/
#define OBD_PARAMETER_MAX   130


/*****************************************************************************
*  Typedef  Enum                        枚举定义
*****************************************************************************/

/*****************************************************************************
*  Struct                               数据结构定义
******************************************************************************/
typedef void (*Func_CustRecvPtr)(void);

typedef struct
{
    const char           *cmd_string;
    Func_CustRecvPtr     func_ptr;
} cust_recv_struct;

typedef struct
{
    kal_bool        valid;
    kal_bool        update_valid;
    kal_uint8       source;             /*不支持为0，支持1为CAN、2为诊断、3为OBD、4为模块计算返回*/
    kal_uint32      value;
} obd_data_struct;

/*****************************************************************************
*  Local variable                       局部变量
*****************************************************************************/
static char *obd_parameters[OBD_PARAMETER_MAX] = {0};
static obd_data_struct obd_datas[OBD_PARAMETER_MAX] = {0};
static char obd_errorids[20][7] = {0};
static char obd_ver[30] = {0};
static int obd_parameters_count = 0;
static kal_uint8 acc_status = 0;
static kal_bool mode_hex_decode = KAL_FALSE, mode_auto_update = KAL_FALSE;
static kal_uint8 update_file_block = 0, mode_update = 0;
static kal_uint8 *obdfiledatabuf = NULL;
static kal_uint32 obdfilefilesize = 0;
static kal_uint32 obdupdateblock = 4096;
static kal_bool obd_start_status = KAL_FALSE;
static kal_uint8 obd_acc_status = 1;
static kal_uint8 obd_type = 0;  /*1: NT23 */
static cmd_return_struct reply = {0};
static U32 g_tick_new = 0;
static kal_bool obd_sleep_status = KAL_TRUE;
static kal_bool obd_opendata_status = KAL_FALSE;

/****************************************************************************
*  Global Variable                      全局变量
*****************************************************************************/

/****************************************************************************
*  Global Variable - Extern             引用全局变量
*****************************************************************************/

/*****************************************************************************
*  Global Functions - Extern            引用外部函数
******************************************************************************/
extern void track_cust_server2_conn(void *arg);
extern kal_int32 track_drv_get_external_batter(kal_uint8 flag);
/*****************************************************************************
*  Local Functions Define               本地函数声明
******************************************************************************/
void track_cust_obd_write(kal_uint8 *data, int len);
void track_obd_acc(void *arg);
void track_cust_obd_clear(void);
static void obd_opendata(int par);
static void obd_variety_on(void);
static void obd_send_cmd_ver(void);
static void obd_send_cmd_update_filename(void);
static void obd_send_cmd_update_data(void);
static void obd_getcar(void);
static void obd_send_cmd_md5_check(void);
static void obd_cmd_hex(kal_uint8 *src, int len);
static void obd_send_cmd_restart(void);
static void obd_restart(void);
static void obd_scan_ok(void);
static void obd_vin(void);
static void obd_vin_cmd(void);
static void obd_cmd_hex2(FuncPtr funcPtr);
static void obd_closedata(void);
static void obd_obdsleep_ok(void);
static void obd_sleep_turnon(void);
#if 0
#endif /* 0 */
/*****************************************************************************
*  Local Functions                      本地函数
******************************************************************************/
const static char *obd_source_string[] = {
	"",
	"CAN",
	"诊断",
	"OBD",
	"计算"
};

const static char *obd_status_string[] = {
	"灯状态(远光灯)",
	"灯状态(近光灯)",
	"灯状态(示宽灯)",
	"灯状态(雾灯)",
	"灯状态(左转向)",
	"灯状态(右转向)",
	"灯状态(危险灯)",
	"门状态(左前门)",
	"门状态(右前门)",
	"门状态(左后门)",
	"门状态(右后门)",
	"门状态(后备箱)",
	"门锁(全车)",
	"门锁(左前门)",
	"门锁(右前门)",
	"门锁(左后门)",
	"门锁(右后门)",
	"门锁(后备箱)",
	"窗状态(左前窗)",
	"窗状态(右前窗)",
	"窗状态(左后窗)",
	"窗状态(右后窗)",
	"窗状态(天窗)",
	"故障信号(ECM)",
	"故障信号(ABS)",
	"故障信号(SRS)",
	"报警信号(机油)",
	"报警信号(胎压)",
	"报警信号(保养)",
	"安全气囊状态",
	"手刹状态",
	"刹车状态(脚刹)",
	"安全带(驾驶员)",
	"安全带(副驾)",
	"ACC信号",
	"钥匙状态",
	"遥控信号",
	"雨刮状态",
	"空调开关",
	"档位",
	"总里程(km)",
	"续航里程(km)",
	"剩余油量(L)",
	"剩余油量(%)",
	"单次用油量(ml)",
	"水温(发动机冷却液℃)",
	"发动机进气温度(℃)",
	"空调车内温度(℃)",
	"电池当前电压(V)",
	"左前轮轮速(km/h)",
	"右前轮轮速(km/h)",
	"左后轮轮速(km/h)",
	"右后轮轮速(km/h)",
	"车速(km/h)",
	"转速(rpm)",
	"平均油耗(L/100KM)",
	"瞬时油耗(L/100KM)",
	"瞬时油耗(L/H)",
	"机油寿命(%)",
	"机油压力(kPa)",
	"空气流量(g/s)",
	"进气歧管绝对压力(kPa)",
	"喷油脉宽(ms)",
	"油门踏板相对位置(%)",
	"油门踏板状态",
	"方向盘转角角度（°）",
	"方向盘转向角状态"
};
#ifndef __EXT_VBAT_ADC__
	/*NT55 暂无adc电压检测，这是一个假函数*/
kal_int32 track_drv_get_external_batter(kal_uint8 flag)
{
	kal_int32 vcc = 60000;
	return vcc;
}
#endif

void obd_poweron(kal_uint32 on)
{
    static U8 ss = 2;
    kal_int8 ret;
    LOGD(L_UART, L_V6, "last:%d, %d", ss, on);
    if(on > 20)
    {/*开*/
        if(ss != 1)
        {
            ret = track_drv_gpio_set(1, OBD_POWER_GPIO);
            if(ret != 0 && ret != 1)
            {
                LOGD(L_UART, L_V1, "ERROR1 ret:%d", ret);
            }
            else ss = 1;
            tr_start_timer(TRACK_CUST_OBD_SLEEP_TIMER_ID, 60000, obd_sleep_turnon);
        }
        if(!track_drv_charget_usb_status() && track_drv_get_external_batter(1) < 8000000)
        {
            track_start_timer(TRACK_CUST_OBD_START_TIMER_ID, 10000, obd_poweron, (void *)34);
            return;
        }
        track_drv_sleep_enable(SLEEP_OBD_MOD, KAL_FALSE);
        if(G_realtime_data.netLogControl & 256)
        {
            char buf[50];
            sprintf(buf, "obd_poweron %d", on);
            cust_packet_log_data(8, (kal_uint8 *)buf, strlen((char *)buf));
        }
    }
    else if(on < 20)
    {
        track_drv_sleep_enable(SLEEP_OBD_MOD, KAL_TRUE);
        if(ss != 0)
        {/*关*/
            track_stop_timer(TRACK_CUST_OBD_START_TIMER_ID);
            if(G_realtime_data.netLogControl & 256)
            {
                char buf[50];
                sprintf(buf, "obd_poweron %d", on);
                cust_packet_log_data(8, (kal_uint8 *)buf, strlen((char *)buf));
            }
            obd_sleep_status = KAL_TRUE;
            ret = track_drv_gpio_set(0, OBD_POWER_GPIO);
            if(ret != 0 && ret != 1)
            {
                LOGD(L_UART, L_V1, "ERROR2 ret:%d", ret);
            }
            else ss = 0;
        }
    }
}

static void obd_sleep_turnon(void)
{
    LOGD(L_UART, L_V2, "obd_acc_status=%d, obd_type=%d", obd_acc_status, obd_type);
    if(obd_acc_status > 0)
    {
        tr_start_timer(TRACK_CUST_OBD_SLEEP_TIMER_ID, 60000, obd_sleep_turnon);
    }
    else
    {
        obd_obdsleep_ok();
    }
}

void obd_power_off_and_restart(void)
{
    LOGD(L_UART, L_V5, "");
    mode_hex_decode = KAL_FALSE;
    obd_poweron(1);
    track_stop_timer(TRACK_CUST_OBD_CXALL_TIMER_ID);
    track_start_timer(TRACK_CUST_OBD_RESTART_TIMER_ID, 1000, obd_poweron, (void *)32);
}

void obd_upload_time_update_parameter(void)
{
    if(track_is_timer_run(TRACK_CUST_OBD_CXALL_TIMER_ID))
    {
        tr_start_timer(TRACK_CUST_OBD_CXALL_TIMER_ID, G_parameter.obd.upload_time * 1000, obd_scan_ok);
    }
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
static void obd_get_data(kal_uint8 type, char *obd_error_id)
{
    int i, j = 0;
    static char buf[2000];
    char *p = buf;
    float tt;
    kal_bool login_status = track_soc_login_status();
    memset(buf, 0, 2000);
    LOGD(L_UART, L_V5, "%d", type);
    {
        applib_time_struct time = {0};
        track_fun_get_time(&time, KAL_TRUE, NULL);
        if(time.nYear < 2014)
        {
            if(G_realtime_data.netLogControl & 256)
            {
                char *tmp="Equipment time is not synchronized, OBD data temporarily uploaded.";
                cust_packet_log_data(8, (kal_uint8 *)tmp, strlen(tmp));
            }
            LOGD(L_UART, L_V5, "设备时间未同步，OBD数据暂不上传");
            return;
        }
    }
    for(i=0; i<OBD_PARAMETER_MAX; i++)
    {
        if(obd_datas[i].valid && ((type & 0x01) == 0 || ((type & 0x01) == 1 && obd_datas[i].update_valid)))
        {
            if(i == 40 && obd_datas[i].value == (U32)0x7FFFFFFF) continue;
            if(i != 0x22 && i != 0x28 && obd_datas[0x22].update_valid && !login_status) continue;
            if(obd_datas[i].value == 0 || obd_datas[i].value == 1)
            {
                LOGD(L_UART, L_V4, "{%d,%d}%s,%s=%X", i, obd_datas[i].source, 
                    obd_source_string[obd_datas[i].source], (sizeof(obd_status_string)/sizeof(char*) < i ? "未知" : obd_status_string[i]), obd_datas[i].value);
            }
            else
            {
                tt = (S32)obd_datas[i].value;
                LOGD(L_UART, L_V4, "{%d,%d}%s,%s=%0.2f(%X)", i, obd_datas[i].source, 
                    obd_source_string[obd_datas[i].source], (sizeof(obd_status_string)/sizeof(char*) < i ? "未知" : obd_status_string[i]), tt/100, obd_datas[i].value);
            }
            if(!j)
            {
                j = sprintf(p, "%02X%X=%X", i, obd_datas[i].source, obd_datas[i].value);
            }
            else
            {
                j = sprintf(p, ",%02X%X=%X", i, obd_datas[i].source, obd_datas[i].value);
            }
            p += j;
            if(p - buf > 1900)
            {
                LOGD(L_UART, L_V1, "ERROR : Data too long!");
                return;
            }
            if((type & 0x02) > 0)
                obd_datas[i].update_valid = KAL_FALSE;
        }
    }
    if(obd_error_id != NULL) sprintf(p, "%s", obd_error_id);
    LOGD(L_UART, L_V1, "ALL: %s", buf);
    if((type & 0x04) > 0)
    {
        if(login_status)
            track_cust_paket_8C(0, acc_status, buf, strlen(buf));
        else
            track_cust_paket_8C(1, acc_status, buf, strlen(buf));
    }
}

//AT^U=CX,ALL,38F1
static void obd_cx(void)
{
    char *str = "AT^U=CX,ALL,";
    track_cust_obd_write(str, strlen(str));
}

//AT^D=CX,ALL,DATA_INVALID,C8AC
static void obd_cx_ok(void)
{
}

//AT^U=KEEPLINK,7D16
static void obd_keeplink(void)
{
    char *str = "AT^U=KEEPLINK,";
    track_cust_obd_write(str, strlen(str));
}

static void obd_keeplink_ok(void)
{
    if(obd_acc_status)
    {
        char *str = "AT^D=KEEPLINK_OK,";
        track_cust_obd_write(str, strlen(str));
    }
    else
    {
        track_stop_timer(TRACK_CUST_OBD_CXALL_TIMER_ID);
    }
    if(!obd_start_status)
    {
        tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, obd_restart);
    }
    tr_start_timer(TRACK_CUST_OBD_SLEEP_TIMER_ID, 60000, obd_sleep_turnon);
}

static void obd_update(void)
{
    char *str = "AT^U=UPDATE,";
    kal_uint8 buffer[25] = {0};
    track_cust_obd_write(str, strlen(str));
}

static void obd_getobdversion(void)
{
    char *str = "AT^U=OBDVERSION,";
    track_cust_obd_write(str, strlen(str));
}

static void obd_obdversion_ok(void)
{
    int len;
    char *ver;
    LOGD(L_UART, L_V5, "ver:\r\n%s\r\n%s\r\n%s\r\n%s\r\n", 
        obd_parameters[1], obd_parameters[2], obd_parameters[3], obd_parameters[4]);
    ver = track_fun_trim(obd_parameters[2]);
    len = strlen(ver);
    if(len > 0 && len < 30 && strcmp(obd_ver, ver) != 0)
    {
        snprintf(obd_ver, 30, "OBD_%s", ver);
        //Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    }
    if(mode_update == 2)
    {
        mode_update = 0;
        LOGD(L_UART, L_V4, "OBD: 升级成功重新连接服务器提交新版本!");
        track_cust_server2_file_retry();
        track_os_intoTaskMsgQueueExt(track_cust_server2_conn, (void*)4);
    }
    if(mode_auto_update)
        tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, obd_update);
    else
        tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, obd_getcar);
}

//AT^U=GETCAR,A6B3
static void obd_getcar(void)
{
    char *str = "AT^U=GETCAR,";
    track_cust_obd_write(str, strlen(str));
}

void track_obd_setcar(void)
{
    char str[50] = {0};
    if(obd_type == 1)
    {
        sprintf(str, "AT^U=ODOMETER,%d,", G_parameter.obd.total_mileage);
    }
    else
    {
        //AT^U=SETCAR,0002,00000000,000000,00,
        sprintf(str, "AT^U=SETCAR,%04X,00000000,%06X,00,",G_parameter.obd.car, G_parameter.obd.total_mileage);
    }
    track_cust_obd_write(str, strlen(str));
}

void track_obd_setcar_and_odometer(U8 car, U32 total_mileage)
{
    char str[100] = {0};
    if(obd_type == 1)
    {
        if(G_parameter.obd.total_mileage != total_mileage)
        {/*OBD 单位km*/
            G_parameter.obd.total_mileage = total_mileage;
            sprintf(str, "AT^U=ODOMETER,%d,", G_parameter.obd.total_mileage);
            track_cust_obd_write(str, strlen(str));
        }
    }
    else
    {
        if(car != G_parameter.obd.car)
        {
            G_parameter.obd.total_mileage = total_mileage;
            G_parameter.obd.car = car;
            track_cust_obd_clear();
            obd_power_off_and_restart();
        }
        else
        {
            if(G_parameter.obd.total_mileage != total_mileage)
            {/*公里数*/
                G_parameter.obd.total_mileage = total_mileage;
                sprintf(str, "AT^U=SETCAR,%04X,00000000,%06X,00,",G_parameter.obd.car, G_parameter.obd.total_mileage);
                track_cust_obd_write(str, strlen(str));
            }
        }
    }
}

//AT^D=GETCAR,0006,FFFFFFFF,000000,FF,FC88
static void obd_gercar_ok(void)
{
    int car;
    char tmp[5] = {0};
    strncpy(tmp, obd_parameters[1], 4);
    car = strtol(tmp,NULL,16);
    // = OTA_atoi(obd_parameters[1]);
    LOGD(L_UART, L_V4, "GETCAR:%s,%d", obd_parameters[1], car);
    if(G_parameter.obd.car == 0)
    {
        G_parameter.obd.car = 1;
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    }
    if(car != G_parameter.obd.car)
    {
        track_obd_setcar();
    }
    else
    {
        obd_variety_on();
    }
}

static void obd_setcar_ok(void)
{
    tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, obd_variety_on);
}

static void obd_worka_ok(void)
{
    char *str = "AT^U=OBD_WORK_OK,";
    if(mode_update == 1)
    {
        mode_update = 2;
        LOGS("OBD: 升级过程全部完毕!");
    }
    track_stop_timer(TRACK_CUST_OBD_CXALL_TIMER_ID);
    track_stop_timer(TRACK_CUST_OBD_RESTART_TIMER_ID);
    track_cust_obd_write(str, strlen(str));
    tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, obd_getobdversion);
    obd_start_status = KAL_TRUE;
    obd_type = 0;
}

static void obd_work_ok(void)
{
    int len;
    char *str = "AT^U=OBD_WORK_OK,", *ver;
    if(mode_update == 1)
    {
        mode_update = 2;
        LOGS("OBD: 升级过程全部完毕!");
    }
    track_stop_timer(TRACK_CUST_OBD_CXALL_TIMER_ID);
    track_stop_timer(TRACK_CUST_OBD_RESTART_TIMER_ID);
    track_cust_obd_write(str, strlen(str));
    LOGD(L_UART, L_V4, "obd_work_ok,%s,%s", obd_parameters[1], obd_parameters[2]);
    obd_type = 1;
    obd_start_status = KAL_TRUE;
    ver = track_fun_trim(obd_parameters[2]);
    len = strlen(ver);
    if(len > 0 && len < 30 && strcmp(obd_ver, ver) != 0)
    {
        snprintf(obd_ver, 30, "OBD_%s", ver);
    }
    if(mode_update == 2)
    {
        mode_update = 0;
        LOGD(L_UART, L_V4, "OBD: 升级成功重新连接服务器提交新版本!");
        track_cust_server2_file_retry();
        track_os_intoTaskMsgQueueExt(track_cust_server2_conn, (void*)5);
    }
    if(mode_auto_update)
        tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, obd_update);
    else
        obd_opendata(1);
}

static void obd_sleep_ok(void)
{
    char *str = "AT^U=OBD_SLEEP_OK,";
    obd_sleep_status = KAL_TRUE;
    track_stop_timer(TRACK_CUST_OBD_CXALL_TIMER_ID);
    obd_sleep_turnon();
    track_cust_obd_write(str, strlen(str));
}

static void obd_restart(void)
{
    char *str = "AT^U=RESTART,";
    LOGD(L_UART, L_V5, "");
    track_stop_timer(TRACK_CUST_OBD_CXALL_TIMER_ID);
    obd_poweron(22);
    obd_start_status = KAL_TRUE;
    track_cust_obd_write(str, strlen(str));
    tr_start_timer(TRACK_CUST_OBD_RESTART_TIMER_ID, 5000, obd_power_off_and_restart);
}

static void obd_cx_cycle(void)
{
    obd_cx();
    tr_start_timer(TRACK_CUST_OBD_CXALL_TIMER_ID, G_parameter.obd.upload_time * 1000, obd_cx_cycle);
}

static void obd_scan_ok(void)
{
    if(obd_opendata_status)
    {
        obd_opendata_status = KAL_FALSE;
        if(obd_type == 1)
        {
            char *str = "AT^U=OBD_SCAN_OK,";
            track_cust_obd_write(str, strlen(str));
            tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, obd_vin_cmd);
        }
        else
        {
            obd_cx_cycle();
        }
    }
}

static void obd_scan_fail(void)
{
    LOGD(L_UART, L_V1, "obd_scan_fail");
}

static void obd_opendata(int par)
{
    U32 tick = OTA_kal_get_systicks() - g_tick_new;
    if(G_realtime_data.netLogControl & 256)
    {
        char buf[100];
        snprintf(buf, 100, "obd_opendata(%d)%d,%d,%d", par, obd_sleep_status, obd_acc_status, tick);
        cust_packet_log_data(8, (kal_uint8 *)buf, strlen(buf));
    }
    if(par || obd_sleep_status || (tick > KAL_TICKS_1_MIN * 2))
    {
        char *str = "AT^U=OPENDATA,";
        obd_opendata_status = KAL_TRUE;
        track_cust_obd_write(str, strlen(str));
    }
}

static void obd_opendata_ok(void)
{
    LOGD(L_UART, L_V1, "obd_opendata_ok");
    obd_sleep_status = KAL_FALSE;
}

static void obd_reset_update_item(void)
{
    int i;
    for(i=0; i<OBD_PARAMETER_MAX; i++)
    {
        if(obd_datas[i].valid)
        {
            obd_datas[i].update_valid = KAL_TRUE;
        }
    }
}

static void obd_decode_data(void)
{
    int i, j, l;
    char tmp[9] = {0};
    kal_uint8 source;
    kal_uint32 value;
    LOGD(L_UART, L_V1, "size:%d", sizeof(obd_datas));
    for(i=1; i<obd_parameters_count-1; i++)
    {
        tmp[0] = obd_parameters[i][0];
        tmp[1] = obd_parameters[i][1];
        tmp[2] = 0;
        j = strtol(tmp,NULL,16);
        if(j < OBD_PARAMETER_MAX)
        {
            obd_datas[j].valid = KAL_TRUE;
            tmp[0] = obd_parameters[i][2];
            tmp[1] = 0;
            source = strtol(tmp,NULL,16);
            l = strlen(&obd_parameters[i][4]);
            l = l > 8 ? 8 : l;
            memcpy(tmp, &obd_parameters[i][4], l);
            tmp[l] = 0;
            value = strtol(tmp,NULL,16);
            if(obd_datas[j].source != source || obd_datas[j].value != value)
            {
                obd_datas[j].update_valid = KAL_TRUE;
                obd_datas[j].source = source;
                obd_datas[j].value = value;
                if(j == 34)
                {
                    obd_reset_update_item();
                    LOGD(L_UART, L_V5, "【ACC %d】", value);
                    if(value == 0)
                    {
                        acc_status = 0;
                        track_os_intoTaskMsgQueueExt(track_obd_acc, (void*)10);
                        tr_start_timer(TRACK_CUST_OBD_SLEEP_TIMER_ID, 60000, obd_sleep_turnon);
                    }
                    else
                    {
                        acc_status = 1;
                        track_os_intoTaskMsgQueueExt(track_obd_acc, (void*)11);
                    }
                }
            }
        }
        LOGD(L_UART, L_V1, "{%d,%d,%d}%s, %s", i, j, obd_datas[j].source, obd_parameters[i], tmp);
    }
    LOGD(L_UART, L_V1, "------------------------------------------------------------------");
}

//AT^D=ALL,224=1,284=00000000,2B3=00000000,2D3=00000000,2E3=00000000,303=00000000,353=00000000,363=00000000,393=00000000,3C3=00000000,3D3=00000000,3F3=00000000,DD93
static void obd_all(void)
{
    obd_decode_data();
    obd_get_data(G_parameter.obd.upload_type, NULL);
    tr_start_timer(TRACK_CUST_OBD_CXALL_TIMER_ID, G_parameter.obd.upload_time * 1000, obd_cx_cycle);
}

static void obd_accup_ok(void)
{
    char *str = "AT^D=ACCUP_OK,";
    track_cust_obd_write(str, strlen(str));
}

static void obd_accdown_ok(void)
{
    char *str = "AT^D=ACCDOWN_OK,";
    track_cust_obd_write(str, strlen(str));
}

//AT^D=ACCUP,224=1,284=00000D8B,2B3=000007D0,2C4=00013472,2D3=00002774,2E3=0000044C,303=000009A3,353=00004268,363=00077A10,374=000096C8,384=000096C8,393=00010054,3C3=00000000,3D3=000013EC,3F3=000007D0,59BB
static void obd_accup(void)
{
    char *str = "AT^U=ACCUP_OK,";
    obd_decode_data();
    obd_get_data(G_parameter.obd.upload_type, NULL);
    track_cust_obd_write(str, strlen(str));
}

//AT^D=ACCDOWN,071=1,081=1,091=1,0A1=1,0B1=1,0C1=0,0D1=1,0E1=1,0F1=0,101=1,1E1=1,1F1=0,201=1,221=0,231=1,241=0,281=03224CAC,2B3=000007D0,2C4=000A155D,2D3=000032C8,2E3=0000044C,303=000004D1,353=00004268,363=0007A120,374=000096C8,384=000096C8,393=00010054,3C3=000043AE,3D3=000013EC,3F3=000007D0,7324
static void obd_accdown(void)
{
    char *str = "AT^U=ACCDOWN_OK,";
    obd_decode_data();
    obd_get_data(G_parameter.obd.upload_type, NULL);
    track_cust_obd_write(str, strlen(str));
    if(obd_type == 1)
    {
        tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, obd_closedata);
    }
}

static void track_obd_cmd_overtime(void)
{
    char *str = "Read Error!";
    track_stop_timer(TRACK_CUST_OBD_CMD_TIMER_ID);
    track_cust_cmd_reply(&reply, str, strlen(str));
    memset(&reply, 0, sizeof(reply));
}

void track_obd_getVIN(CMD_DATA_STRUCT * cmd)
{
    char *str = "AT^U=VIN,";
    track_cust_obd_write(str, strlen(str));
    memcpy(&reply, &cmd->return_sms, sizeof(reply));
    tr_start_timer(TRACK_CUST_OBD_CMD_TIMER_ID, 60000, track_obd_cmd_overtime);
}

void track_obd_getErrorId(CMD_DATA_STRUCT * cmd)
{
    char *str = "AT^U=READOBD,";
    track_cust_obd_write(str, strlen(str));
    if(cmd != NULL)
    {
        memcpy(&reply, &cmd->return_sms, sizeof(reply));
        tr_start_timer(TRACK_CUST_OBD_CMD_TIMER_ID, 60000, track_obd_cmd_overtime);
    }
    else
    {
        tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 30000, obd_cx_cycle);
    }
}

void track_obd_clsobd(CMD_DATA_STRUCT * cmd)
{
    char *str = "AT^U=CLSOBD,";
    track_cust_obd_write(str, strlen(str));
    memcpy(&reply, &cmd->return_sms, sizeof(reply));
    tr_start_timer(TRACK_CUST_OBD_CMD_TIMER_ID, 60000, track_obd_cmd_overtime);
}

//AT^D=READOBD,0,17A7
//AT^D=READOBD,02,070205,070093,0006
//AT^D=READOBD,02,030101,030095,9398
static void obd_readobd(void)
{
    char buf[100] = {0}, *p;
    int ret, i, value = atoi(obd_parameters[1]);
    kal_bool flag = KAL_FALSE;
    
    if(track_is_timer_run(TRACK_CUST_OBD_CMD_TIMER_ID))
    {
        track_stop_timer(TRACK_CUST_OBD_CMD_TIMER_ID);
        flag = KAL_TRUE;
        ret = sprintf(buf, "OBD_ERROR_ID:");
        p = buf + ret;
    }
    else
    {
        p = buf;
    }
    if(value > 0)
    {
        for(i=0; i<value; i++)
        {
            if(flag && i==0)
            {
                ret = snprintf(p, 100-(p-buf), "%s", obd_parameters[2+i]);
            }
            else if(flag)
            {
                ret = snprintf(p, 100-(p-buf), ",%s", obd_parameters[2+i]);
            }
            else if(i==0)
            {
                ret = snprintf(p, 100-(p-buf), "999=%s", obd_parameters[2+i]);
            }
            else
            {
                ret = snprintf(p, 100-(p-buf), ",999=%s", obd_parameters[2+i]);
            }
            p += ret;
        }
    }
    else
    {
        ret = sprintf(buf, "NOT_ERROR_ID");
    }
    if(flag)
    {
        track_cust_cmd_reply(&reply, buf, strlen(buf));
        memset(&reply, 0, sizeof(reply));
    }
    else
    {
        LOGD(L_UART, L_V5, "%s", buf);
        obd_get_data(G_parameter.obd.upload_type, buf);
    }
}

//AT^D=ERROR_ID,08,P0143,P0196,P0134,P0105,P0258,P0118,P0203,P0115,785B
static void obd_error_id(void)
{
    char buf[100] = {0}, *p, *dect;
    int ret, i, value = atoi(obd_parameters[1]), len;
    kal_bool flag = KAL_FALSE;
    
    if(track_is_timer_run(TRACK_CUST_OBD_CMD_TIMER_ID))
    {
        track_stop_timer(TRACK_CUST_OBD_CMD_TIMER_ID);
        flag = KAL_TRUE;
        ret = sprintf(buf, "OBD_ERROR_ID:");
        p = buf + ret;
    }
    else
    {
        p = buf;
    }
    if(value > 0)
    {
        for(i=0; i<value; i++)
        {
            len = strlen(obd_parameters[2+i]);
            if(len == 5 || len == 6)
            {
                dect = obd_parameters[2+i];
                if(flag && i==0)
                {
                    ret = snprintf(p, 100-(p-buf), "%s", dect);
                }
                else if(flag)
                {
                    ret = snprintf(p, 100-(p-buf), ",%s", dect);
                }
                else if(i==0)
                {
                    ret = snprintf(p, 100-(p-buf), "999=%s", dect);
                }
                else
                {
                    ret = snprintf(p, 100-(p-buf), ",999=%s", dect);
                }
            }
            p += ret;
        }
    }
    else if(flag)
    {
        ret = sprintf(buf, "NOT_ERROR_ID");
    }
    LOGD(L_UART, L_V5, "%s", buf);
    if(flag)
    {
        track_cust_cmd_reply(&reply, buf, strlen(buf));
        memset(&reply, 0, sizeof(reply));
    }
    else if(strlen(buf) > 0)
    {
        obd_get_data(G_parameter.obd.upload_type, buf);
    }
    if(track_is_timer_run(TRACK_CUST_OBD_OPENDATA_TIMER_ID))
        tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, obd_cx_cycle);
}

static void obd_vin_cmd(void)
{
    char *str = "AT^U=VIN,";
    track_cust_obd_write(str, strlen(str));
    track_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 10000, track_obd_getErrorId, NULL);
}

//AT^D=VIN,XXXXXXXXXXXX,<CRC>,<结束位>
static void obd_vin(void)
{
    if(track_is_timer_run(TRACK_CUST_OBD_CMD_TIMER_ID))
    {
        char buf[100] = {0};
        track_stop_timer(TRACK_CUST_OBD_CMD_TIMER_ID);
        sprintf(buf, "VIN:%s", obd_parameters[1]);
        track_cust_cmd_reply(&reply, buf, strlen(buf));
        memset(&reply, 0, sizeof(reply));
    }
    else
    {
        LOGD(L_UART, L_V5, "VIN:%s", obd_parameters[1]);
    }
    if(obd_type == 1)
    {
        track_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, track_obd_getErrorId, NULL);
    }
}

static void obd_vin_fail(void)
{
    if(track_is_timer_run(TRACK_CUST_OBD_CMD_TIMER_ID))
    {
        char *str = "VIN, can not read!";
        track_stop_timer(TRACK_CUST_OBD_CMD_TIMER_ID);
        track_cust_cmd_reply(&reply, str, strlen(str));
        memset(&reply, 0, sizeof(reply));
    }
    else
    {
        LOGD(L_UART, L_V5, "VIN:%s", obd_parameters[1]);
    }
    if(obd_type == 1)
    {
        track_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, track_obd_getErrorId, NULL);
    }
}

static void obd_clsobd_ok(void)
{
    char *str = "OK!";
    track_stop_timer(TRACK_CUST_OBD_CMD_TIMER_ID);
    track_cust_cmd_reply(&reply, str, strlen(str));
    memset(&reply, 0, sizeof(reply));
}

static void obd_obdsleep_on(void)
{
    char *str = "AT^U=OBDSLEEP,";
    track_cust_obd_write(str, strlen(str));
}

static void obd_obdsleep_ok(void)
{
    LOGD(L_UART, L_V1, "obd_obdsleep_ok");
    track_stop_timer(TRACK_CUST_OBD_CXALL_TIMER_ID);
    track_stop_timer(TRACK_CUST_OBD_SLEEP_TIMER_ID);
    track_drv_sleep_enable(SLEEP_OBD_MOD, KAL_TRUE);
}

static void obd_closedata(void)
{
    char *str = "AT^U=CLOSEDATA,";
    track_cust_obd_write(str, strlen(str));
}

static void obd_closedata_ok(void)
{
    LOGD(L_UART, L_V1, "obd_closedata_ok");
    obd_obdsleep_on();
}

static void obd_variety_on(void)
{
    char *str = "AT^U=VARIETY,ON,";
    track_cust_obd_write(str, strlen(str));
}

static void obd_variety_ok(void)
{
    char *str = "AT^D=VARIETY_OK,";
    track_cust_obd_write(str, strlen(str));
}

static void obd_event_up_ok(void)
{
    char *str = "AT^D=EVENT_UP_OK,";
    track_cust_obd_write(str, strlen(str));
}

/*AT^D=EVENT_UP,n,X,CRC*/
static void obd_event_up(void)
{
    int value1 = atoi(obd_parameters[1]);
    int value2 = atoi(obd_parameters[2]);
    LOGD(L_UART, L_V5, "%d,%d", value1, value2);
    obd_event_up_ok();
}

static void obd_event_set(U8 mode, U8 value)
{
    char str[50] = {0};
    snprintf(str, 50, "AT^U=EVENT_SET,%d,%d,", mode, value);
    track_cust_obd_write(str, strlen(str));
}

static void obd_setenginel(U16 value)
{
    char str[50] = {0};
    snprintf(str, 50, "AT^U=SETENGINEL,%d,", value);
    track_cust_obd_write(str, strlen(str));
}
 
static void obd_setbgoil(U16 value)
{
    char str[50] = {0};
    snprintf(str, 50, "AT^U=SETBGOIL,%d,", value);
    track_cust_obd_write(str, strlen(str));
}

//AT^D=VARIETY,ON_OK,6603
static void obd_variety(void)
{
    if(!strcmp(obd_parameters[1], "ON_OK"))
    {
        obd_opendata(3);
    }
    else if(strchr(obd_parameters[1], '=') != NULL)
    {
        obd_decode_data();
        obd_get_data(G_parameter.obd.upload_type, NULL);
        obd_variety_ok();
    }
}

static void obd_update_ready_ok(void)
{
    mode_hex_decode = KAL_TRUE;
    tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, obd_send_cmd_ver);
    //obd_send_cmd_ver();
}

static void obd_acchigh(void)
{
    char *str = "AT^U=ACCHIGH_OK,";
    float value1 = atof(obd_parameters[1]);
    LOGD(L_UART, L_V5, "%f", value1);
    track_obd_acc((void*)11);
    track_cust_obd_write(str, strlen(str));
}

static cust_recv_struct OBD_Data[] =
{
    {"KEEPLINK",        obd_keeplink_ok},
    {"KEEPLINK_OK",     NULL},
    {"OBD_WORKA",       obd_worka_ok},
    {"OBD_WORKB",       obd_worka_ok},
    {"OBD_WORK",        obd_work_ok},
    {"OBD_SLEEP",       obd_sleep_ok},
    {"OBDSLEEP_OK",     obd_obdsleep_ok},
    {"OBDVERSION",      obd_obdversion_ok},
    {"OPENDATA_OK",     obd_opendata_ok},
    {"ALL",             obd_all},
    {"CX",              obd_cx_ok},
    {"ACCUP",           obd_accup},
    {"ACCDOWN",         obd_accdown},
    {"ACCHIGH",         obd_acchigh},
    {"VIN",             obd_vin},
    {"VIN_FAIL",        obd_vin_fail},
    //{"READOBD",         obd_readobd},
    {"READOBD",         obd_error_id},
    {"ERROR_ID",        obd_error_id},
    {"CLSOBD_OK",       obd_clsobd_ok},
    {"CLOSEDATA_OK",    obd_closedata_ok},
    {"OBD_SCAN_OK",     obd_scan_ok},
    {"OBD_SCAN_FAIL",   obd_scan_fail},
    {"GETCAR",          obd_gercar_ok},
    {"SETCAR_OK",       obd_setcar_ok},
    {"VARIETY",         obd_variety},
    {"UPDATE_READY",    obd_update_ready_ok},
    //{"EVENT_UP",        obd_event_up},
    {"EVENT_SET_OK",    NULL},
    {"SETENGINEL_OK",   NULL},
    {"SETBGOIL_OK",     NULL},
    {"RESTART_OK",      NULL}
};

kal_uint8 get_no(kal_uint8 arg)
{
    static kal_uint8 i = 1;
    if(arg == 1)
    {
        return i;
    }
    else
    {
        i+=2;
        return i;
    }
}

static kal_int32 obd_read_file_data(void)
{
    static kal_uint8 *p;
    FS_HANDLE fp = NULL;
    WCHAR FilePath[60] = {0};
    kal_uint32 readsize = 0, len;
    int fs_result;
    U32 size;
    
    OTA_kal_wsprintf(FilePath, OBD_FILE_PATH);
    fp = OTA_FS_Open(FilePath, FS_READ_ONLY);
    if(fp < 0)
    {
        LOGD(L_UART, L_V1, "FS_Open Error:%d", fp);
        return fp;
    }
    OTA_FS_GetFileSize(fp, &size);
    if(size > 0)
    {
        if(size != obdfilefilesize)
        {
            if(obdfiledatabuf != NULL)
            {
                Ram_Free(obdfiledatabuf);
            }
            obdfiledatabuf = (U8*)Ram_Alloc(6, size);
        }
        else if(obdfiledatabuf == NULL)
        {
            obdfiledatabuf = (U8*)Ram_Alloc(6, size);
        }
        if(obdfiledatabuf == NULL)
        {
            LOGD(L_UART, L_V1, "Error: Ram_Alloc %d NULL!!", obdfilefilesize);
            return -1;
        }
        obdfilefilesize = size;
    }
    else
    {
        if(obdfiledatabuf != NULL)
        {
            Ram_Free(obdfiledatabuf);
            obdfiledatabuf = NULL;
            obdfilefilesize = 0;
        }
        LOGD(L_UART, L_V1, "Error: obdfilefilesize=%d", size);
        return -2;
    }
    fs_result = OTA_FS_Seek(fp, 0, FS_FILE_BEGIN);
    if(fs_result < FS_NO_ERROR)
    {
        OTA_FS_Close(fp);
        return fs_result;
    }
    len = obdfilefilesize;
    p = obdfiledatabuf;
    while(len > 0)
    {
        if(len > 50000)
        {
            fs_result = OTA_FS_Read(fp, p, 50000, &readsize);
        }
        else
        {
            fs_result = OTA_FS_Read(fp, p, len, &readsize);
        }
        if(fs_result < FS_NO_ERROR)
        {
            OTA_FS_Close(fp);
            LOGD(L_UART, L_V1, "fs_result:%d, %d, %d", fs_result, readsize, len);
            return fs_result;
        }
        len -= readsize;
        p += readsize;
    }
    OTA_FS_Close(fp);
    return obdfilefilesize;
}

static kal_uint8 get_xor(kal_uint8 *data, int len)
{
    kal_uint8 _xor = data[0];
    int i;
    for(i=1;i<len;i++)
    {
        _xor ^= data[i];
    }
    return _xor;
}

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
kal_uint8 track_cust_module_obd_get_acc(void)
{
    return acc_status;
}

void track_obd_acc(void *arg)
{
    U32 status = (U32)arg;
    LOGD(L_UART, L_V3, "%d,%d", status, obd_acc_status);
    switch(status)
    {
        case 0:
        {
            obd_acc_status &= 0xFE;
            break;
        }
        case 1:
        {
            obd_poweron(22);
            obd_opendata(0);
            //if(!track_is_timer_run(TRACK_CUST_OBD_SLEEP_TIMER_ID))
                tr_start_timer(TRACK_CUST_OBD_SLEEP_TIMER_ID, 60000, obd_sleep_turnon);
            obd_acc_status |= 1;
            break;
        }
        case 10:
        {
            obd_acc_status &= 0xFD;
            track_stop_timer(TRACK_CUST_OBD_CXALL_TIMER_ID);
            break;
        }
        case 11:
        {
            obd_poweron(23);
            tr_start_timer(TRACK_CUST_OBD_SLEEP_TIMER_ID, 60000, obd_sleep_turnon);
            obd_acc_status |= 2;
            if(obd_type == 0 && !track_is_timer_run(TRACK_CUST_OBD_CXALL_TIMER_ID))
            {
                obd_cx_cycle();
            }
            break;
        }
    }
}

void track_cust_obd_clear(void)
{
    memset(obd_datas, 0, sizeof(obd_datas));
}

void track_cust_obd_write(kal_uint8 *data, int len)
{
    static kal_uint8 buf[100];
    memset(buf, 0, 100);
    if(len > 92)
    {
        LOGD(L_UART, L_V1, "Error:too long!");
        return;
    }
    memcpy(buf, data, len);
    while(1)
    {
        U16 crc;
        char *p1;
        p1 = strstr(buf, "AT^U=");
        if(p1 != buf)
        {
            p1 = strstr(buf, "AT^D=");
        }
        if(p1 != buf) break;
        if(!(p1[len-1] == ',' || (p1[len-3] == ',' && p1[len-2] == '\r' && p1[len-1] == '\n')))
        {
            break;
        }
        if(p1[len-2] == '\r' && p1[len-1] == '\n')
        {
            len -= 2;
            p1[len] = 0;
        }
        p1 += 5;
        crc = GetCrc16((U8*)p1, strlen(p1));
        sprintf(buf+strlen(buf), "%X\r\n", crc);
        len += 6;
        buf[len] = 0;
        break;
    }
    LOGD(L_UART, L_V4, "[send]: %s", buf);
    if(G_realtime_data.netLogControl & 256)
    {
        cust_packet_log_data_ext2(8, "[send]", (kal_uint8 *)buf, len);
    }
    track_drv_uart1_write_data(buf, len);
}

void track_cust_obd_update_fireware(U8 *data, U32 len)
{
    if(data != NULL && len > 0)
    {
        if(obdfiledatabuf != NULL)
        {
            Ram_Free(obdfiledatabuf);
        }
        obdfiledatabuf = data;
        obdfilefilesize = len;
    }
    if(obdfiledatabuf != NULL)
    {
        mode_auto_update = KAL_TRUE;
        //tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 10000, obd_update_ready_ok);
        //obd_update();
        mode_hex_decode = KAL_FALSE;
        track_cust_obd_clear();
        obd_restart();
        obd_power_off_and_restart();
        tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 10000, obd_send_cmd_ver);
    }
    else
    {
        LOGD(L_UART, L_V4, "ERROR: 无可供升级OBD的数据");
    }
}

void track_cust_obd_tc(char *cmd, int len)
{
    track_cust_obd_write(cmd, len);
    LOGD(L_UART, L_V4, "%d,%d", strlen(cmd), len);
    LOGH(L_UART, L_V2, cmd, len);
}

void track_cust_obd_testcmd(char *outString, CMD_DATA_STRUCT * cmd)
{
    LOGD(L_UART, L_V5, "CMD: %s", cmd->pars[1]);
    //mode_auto_update = KAL_FALSE;
    if(!strcmp(cmd->pars[1], "EVENT_SET"))  /*急加速(急减速)门限值设置*/
    {
        int value1 = 0, value2 = 0;
        if(cmd->part == 1)
        {
            sprintf(cmd->rsp_msg, "%s %s:%d,%d", cmd->pars[0], cmd->pars[1], G_parameter.obd.hard_acceleration, G_parameter.obd.rapid_deceleration);
            return;
        }
        else if(cmd->part != 3)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter!");
            return;
        }
        value1 = atoi(cmd->pars[2]);
        if(value1 != 1 && value1 != 2)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (1～2)");
            return;
        }
        value2 = atoi(cmd->pars[3]);
        if(value2 < 0 || value2 > 5)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 3 (0～5)");
            return;
        }
        if(value1 == 1 && G_parameter.obd.hard_acceleration != value2)
        {
            G_parameter.obd.hard_acceleration = value2;
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        }
        else if(value1 == 2 && G_parameter.obd.rapid_deceleration != value2)
        {
            G_parameter.obd.rapid_deceleration = value2;
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        }
        sprintf(cmd->rsp_msg, "%s %s:%d,%d", cmd->pars[0], cmd->pars[1], value1, value2);
    }
    else if(!strcmp(cmd->pars[1], "SETENGINEL"))    /*车子排量，单位0.1L*/
    {
        int value = 0;
        if(cmd->part == 1)
        {
            sprintf(cmd->rsp_msg, "%s %s:%d", cmd->pars[0], cmd->pars[1], G_parameter.obd.displacement);
            return;
        }
        else if(cmd->part > 2)
        {
            sprintf(cmd->rsp_msg, "ERROR:100");//指令长度不正确
            return;
        }
        if(strlen(cmd->pars[2]) > 0)
            value = atoi(cmd->pars[2]);
        if(value < 10 || value > 1000)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (10～1000)");
            return;
        }
        G_parameter.obd.displacement = value;
        sprintf(cmd->rsp_msg, "%s %s:%d", cmd->pars[0], cmd->pars[1], G_parameter.obd.displacement);
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        obd_setenginel(G_parameter.obd.displacement);
    }
    else if(!strcmp(cmd->pars[1], "SETBGOIL"))    /*百公里平均油耗设置*/
    {
        int value = 0;
        if(cmd->part == 1)
        {
            sprintf(cmd->rsp_msg, "%s %s:%d", cmd->pars[0], cmd->pars[1], G_parameter.obd.fuel_consumption);
            return;
        }
        else if(cmd->part > 2)
        {
            sprintf(cmd->rsp_msg, "ERROR:100");//指令长度不正确
            return;
        }
        if(strlen(cmd->pars[2]) > 0)
            value = atoi(cmd->pars[2]);
        if(value < 10 || value > 5000)
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 2 (10～5000)");
            return;
        }
        G_parameter.obd.fuel_consumption = value;
        sprintf(cmd->rsp_msg, "%s %s:%d", cmd->pars[0], cmd->pars[1], G_parameter.obd.fuel_consumption);
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        obd_setbgoil(G_parameter.obd.fuel_consumption);
    }
    else if(!strcmp(cmd->pars[1], "CLEAR"))
    {
        track_cust_obd_clear();
    }
    else if(!strcmp(cmd->pars[1], "CHANGE"))
    {
        int value = 0;
        if(strlen(cmd->pars[2]) > 1)
        {
            value = OTA_atoi(cmd->pars[2]);
            if(value > 500 & value < 10000)
                obdupdateblock = value;
        }
        OTA_sprintf(outString, "obdupdateblock=%d", obdupdateblock);
    }
    else if(!strcmp(cmd->pars[1], "MD5"))
    {
        applib_md5_ctx md5_ctx;
        U8 hash_result[16] = {0};

        OTA_applib_md5_init(&md5_ctx);
        OTA_applib_md5_update(&md5_ctx, (kal_uint8 *)obdfiledatabuf, obdfilefilesize);
        OTA_applib_md5_final(hash_result, &md5_ctx);
        OTA_sprintf(outString, "hash_result=%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", 
            hash_result[0], hash_result[1], hash_result[2], hash_result[3], hash_result[4],
            hash_result[5], hash_result[6], hash_result[7], hash_result[8], hash_result[9],
            hash_result[10], hash_result[11], hash_result[12], hash_result[13], hash_result[14], hash_result[15]);
    }
    /*else if(!strcmp(cmd->pars[1], "MD5"))
    {
        mode_hex_decode = KAL_TRUE;
        obd_send_cmd_md5_check();
    }*/
    else if(!strcmp(cmd->pars[1], "GETALLUPDATE"))
    {
        mode_hex_decode = KAL_FALSE;
        obd_get_data(7, NULL);
    }
    else if(!strcmp(cmd->pars[1], "GETALL"))
    {
        mode_hex_decode = KAL_FALSE;
        obd_get_data(4, NULL);
    }
    else if(!strcmp(cmd->pars[1], "DL_OFF"))
    {
        mode_hex_decode = KAL_FALSE;
        mode_auto_update = KAL_FALSE;
    }
    else if(!strcmp(cmd->pars[1], "DL1"))
    {
        mode_hex_decode = KAL_TRUE;
    }
    else if(!strcmp(cmd->pars[1], "DL2"))
    {
        mode_auto_update = KAL_TRUE;
    }
    else if(!strcmp(cmd->pars[1], "UPDATE"))
    {
        if(obdfiledatabuf == NULL)
        {
            int ret = obd_read_file_data();
            if(ret <= 0)
            {
                LOGS("OBD: Error(%d)! 不存在“OBD.BIN”文件! 本次升级退出.", ret);
                return;
            }
        }
        LOGS("OBD: 升级前准备...");
        mode_hex_decode = KAL_FALSE;
        mode_auto_update = KAL_TRUE;
        obd_restart();
        tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 10000, obd_update_ready_ok);
    }
    else if(!strcmp(cmd->pars[1], "DL4"))
    {
        int ret;
        WCHAR FilePath[60] = {0};
        OTA_kal_wsprintf(FilePath, OBD_FILE_PATH);
        ret = OTA_FS_Delete(FilePath);
        OTA_sprintf(outString, "Del %s %d", OBD_FILE_PATH, ret);
    }
    else if(!strcmp(cmd->pars[1], "DL"))
    {
        track_cust_obd_update_fireware(NULL, 0);
    }
    else if(!strcmp(cmd->pars[1], "VER_HEX"))
    {
        mode_hex_decode = KAL_TRUE;
        obd_send_cmd_ver();
    }
    else if(!strcmp(cmd->pars[1], "NAME"))
    {
        mode_hex_decode = KAL_TRUE;
        obd_send_cmd_update_filename();
    }
    else if(!strcmp(cmd->pars[1], "UPDATE2"))
    {
        mode_hex_decode = KAL_TRUE;
        update_file_block++;
        obd_send_cmd_update_data();
    }
    else if(!strcmp(cmd->pars[1], "UPDATE1"))
    {
        mode_hex_decode = KAL_TRUE;
        update_file_block = 0;
        obd_send_cmd_update_data();
    }
    else if(!strcmp(cmd->pars[1], "UPDATE3"))
    {
        mode_hex_decode = KAL_TRUE;
        obd_send_cmd_update_data();
    }
    else if(!strcmp(cmd->pars[1], "RESTART3"))
    {
        mode_hex_decode = KAL_FALSE;
        obd_restart();
    }
    else if(!strcmp(cmd->pars[1], "RESTART2"))
    {
        mode_hex_decode = KAL_TRUE;
        obd_send_cmd_restart();
    }
    else if(!strcmp(cmd->pars[1], "RESTART"))
    {
        track_cust_obd_clear();
        obd_power_off_and_restart();
    }
    else if(!strcmp(cmd->pars[1], "SLEEP"))
    {
        OTA_sprintf(outString, "obd_acc_status:%d", obd_acc_status);
    }
    else if(!strcmp(cmd->pars[1], "SLEEPON"))
    {
        obd_poweron(3);
        OTA_sprintf(outString, "SLEEP ON");
    }
    else if(!strcmp(cmd->pars[1], "SLEEPOFF"))
    {
        obd_poweron(24);
        OTA_sprintf(outString, "SLEEP OFF");
    }
    else if(!strcmp(cmd->pars[1], "ACC"))
    {
        track_obd_acc((void*)OTA_atoi(cmd->pars[2]));
        OTA_sprintf(outString, "SLEEP OFF");
    }
}

void track_cust_obd_opendata(void)
{
    tr_start_timer(TRACK_CUST_OBD_SLEEP_TIMER_ID, 60000, obd_sleep_turnon);
}

static void obd_send_cmd_run_app(void)  /*Run App*/
{
    kal_uint8 data[] = {
        //0x55, 0xAA, 0xF0, 0xF8, 0x00, 0x03, 0x1A, 0x21, 0x14, 0x24, 
        0x55, 0xAA, 0xF0, 0xF8, 0x00, 0x03, 0x1C, 0x21, 0x11, 0x27//, 
        //0x55, 0xAA, 0xF0, 0xF8, 0x00, 0x03, 0x1D, 0x21, 0x14, 0x23
    };
    obd_poweron(25);
    track_drv_uart1_write_data(data, sizeof(data));
    LOGS("OBD: 加载升级后的数据 运行...");
    mode_update = 1;
}

static void obd_send_cmd_restart(void)  /*Restart*/
{
    kal_uint8 data[] = {
	0x55, 0xAA, 0xF0, 0xF8, 0x00, 0x03, 0x01, 0x25, 0x05, 0x2A
    };
    data[6] = get_no(0); /*计数器*/
    data[sizeof(data)-1] = get_xor(&data[2], sizeof(data)-3);
    obd_poweron(26);
    track_drv_uart1_write_data(data, sizeof(data));
    LOGD(L_UART, L_V4, "Send: Restart");
}

static void obd_updata_fail(void)
{
    tr_stop_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID);
    LOGS("OBD: 超时，升级失败!");
    obdfilefilesize = 0;
    if(obdfiledatabuf) Ram_Free(obdfiledatabuf);
    update_file_block = 0;
    obd_cmd_hex2(obd_send_cmd_run_app);
    mode_auto_update = KAL_FALSE;
    obd_power_off_and_restart();
}

static void obd_send_cmd_ver(void)  /*版本查询*/
{
    kal_uint8 data[] = {
    	0x55, 0xAA, 0xF0, 0xF8, 0x00, 0x03, 0x2B, 0x21, 0x05, 0x04
    };
    data[6] = get_no(0); /*计数器*/
    data[sizeof(data)-1] = get_xor(&data[2], sizeof(data)-3);
    obd_poweron(27);
    mode_hex_decode = KAL_TRUE;
    track_drv_uart1_write_data(data, sizeof(data));
    LOGS("OBD: 版本查询");
    tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 10000, obd_send_cmd_update_filename);
}

static void obd_send_cmd_update_filename(void)  /*升级数据文件名发送命令*/
{
    kal_uint8 data[] = {
	0x55, 0xAA, 0xF0, 0xF8, 0x00, 0x16, 0x2F, 0x24, 0x02, 0x00, 0x0D, 0x44, 0x4F, 0x57, 0x4E, 0x4C, 
	0x4F, 0x41, 0x44, 0x2E, 0x42, 0x49, 0x4E, 0x00, 0x00, 0x03, 0x60, 0x00, 0x06
    };
    data[6] = get_no(0); /*计数器*/
    data[sizeof(data)-1] = get_xor(&data[2], sizeof(data)-3);
    obd_poweron(28);
    track_drv_uart1_write_data(data, sizeof(data));
    LOGS("OBD: 写入将要升级的文件名");
    tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 5000, obd_send_cmd_update_filename);
    tr_start_timer(TRACK_CUST_OBD_SEND_OVERTIME_TIMER_ID, 120000, obd_updata_fail);
}

static void obd_send_cmd_md5_check(void)  /*升级数据文件内容校验数据命令*/
{
    kal_uint8 data[] = {
	0x55, 0xAA, 0xF0, 0xF8, 0x00, 0x23, 0x00, 0x24, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    applib_md5_ctx md5_ctx;
    kal_uint8 hash_result[16] = {0}, _xor;
    int i=0, j=9;

    OTA_applib_md5_init(&md5_ctx);
    OTA_applib_md5_update(&md5_ctx, (kal_uint8 *)obdfiledatabuf, obdfilefilesize);
    OTA_applib_md5_final(hash_result, &md5_ctx);

    for(i=0; i<16; i++)
    {
        sprintf(&data[j], "%0.2x", (kal_uint8)hash_result[i]);
        j += 2;
    }

    data[6] = get_no(0); /*计数器*/
    _xor = get_xor(&data[2], 39);
    data[41] = _xor;
    obd_poweron(29);
    track_drv_uart1_write_data(data, sizeof(data));
    LOGH(L_UART, L_V1, data, sizeof(data));
    LOGS("OBD: 写入升级数据的MD5校验");
    tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 5000, obd_send_cmd_md5_check);
    tr_start_timer(TRACK_CUST_OBD_SEND_OVERTIME_TIMER_ID, 120000, obd_updata_fail);
}

static void obd_send_cmd_update_begin(void *arg)
{
    static U8 re = 0;
    U8 _xor, data[10] = {
	0x55, 0xAA, 0xF0, 0xF8, 0x00, 0x03, 0x01, 0x24, 0x07, 0x00
    };
    data[6] = get_no(0); /*计数器*/
    _xor = get_xor(&data[2], 7);
    data[9] = _xor;
    track_drv_uart1_write_data(data, sizeof(data));
    LOGH(L_UART, L_V1, data, sizeof(data));
    LOGS("OBD: 发送“启动更新固件命令”");
    if((U32)arg == 1)
    {
        if(re > 3)
        {
            LOGS("OBD: 发送“启动更新固件命令”失败，跳过");
            tr_stop_timer(TRACK_CUST_OBD_SEND_OVERTIME_TIMER_ID);
            re = 0;
            obd_cmd_hex2(obd_send_cmd_update_filename);
        }
        else
        {
            re++;
            track_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, obd_send_cmd_update_begin, (void*)1);
        }
    }
    else
    {
        re = 0;
        track_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, obd_send_cmd_update_begin, (void*)1);
    }
}

static void obd_send_cmd_update_data(void)  /*升级数据发送命令*/
{
    static U32 hstick = 0;
    kal_int32 ret, i = 0;
    kal_uint16 packetlen, datalen = obdupdateblock, len;
    kal_uint8 *packet_buf, *p, _xor;
    kal_uint32 begin;
    if(obdfiledatabuf == NULL)
    {
        LOGD(L_UART, L_V5, "Error: 用于升级的OBD数据未准备好!");
        ret = obd_read_file_data();
        if(ret <= 0)
        {
            LOGS("OBD: Error(%d)! 不存在“OBD.BIN”文件! 本次升级退出.", ret);
            return;
        }
        LOGS("OBD: “OBD.BIN”文件成功打开.");
    }
    LOGD(L_UART, L_V1, "update_file_block:%d, datalen:%d, obdfilefilesize:%d", update_file_block, datalen, obdfilefilesize);
    if(update_file_block * datalen < obdfilefilesize)
    {
        if(update_file_block == 0) hstick = kal_get_systicks();
        p = obdfiledatabuf + update_file_block * datalen;
        ret = obdfilefilesize - update_file_block * datalen;
        len = (ret > datalen ? datalen : ret);
    }
    else
    {
        LOGS("OBD: 写入升级数据 100%%");
        LOGS("OBD: 写入升级数据耗时%d秒", kal_ticks_to_secs(kal_get_systicks() - hstick));
        tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, obd_send_cmd_md5_check);
        return;
    }

    packetlen = len + 6 + 3;
    
    packet_buf = (U8*)Ram_Alloc(6, packetlen + 7);
    if(packet_buf == NULL)
    {
        LOGD(L_UART, L_V1, "Ram_Alloc NULL!!");
        return;
    }

    packet_buf[i++] = 0x55;  /*起始位*/
    packet_buf[i++] = 0xAA;
    packet_buf[i++] = 0xF0;  /*原地址*/
    packet_buf[i++] = 0xF8;  /*目标地址*/

    packet_buf[i++] = (packetlen & 0xFF00) >> 8;  /*包长度*/
    packet_buf[i++] = (packetlen & 0x00FF);
    // <起始标志>+<目标地址>+<源地址>+<包长度>+<计数器>+<命令字>+<数据区>+<包校验>

    packet_buf[i++] = get_no(0); /*计数器*/
    
    packet_buf[i++] = 0x24; /*命令字*/
    packet_buf[i++] = 0x03;

    /*数据区*/
    begin = update_file_block * datalen;  /*写入位置*/
    packet_buf[i++] = (begin & 0xFF000000) >> 24;
    packet_buf[i++] = (begin & 0x00FF0000) >> 16;
    packet_buf[i++] = (begin & 0x0000FF00) >> 8;
    packet_buf[i++] = (begin & 0x000000FF);
    //i += 4;

    /*原厂自带工具长度是4096，在波特率57600的情况下，从测试结果看单包4096与2048，实际耗费的总时间无差别*/
    packet_buf[i++] = (len & 0xFF00) >> 8;  /*数据长度*/
    packet_buf[i++] = (len & 0x00FF);

    memcpy(&packet_buf[i], obdfiledatabuf + update_file_block * datalen, len);
    i += len;

    _xor = get_xor(&packet_buf[2], 7+6+len);
    packet_buf[i++] = _xor;
    //LOGH(L_UART, L_V1, &_xor, 1);
    obd_poweron(30);
    track_drv_uart1_write_data(packet_buf, packetlen + 7);
    LOGS("OBD: 写入升级数据 (%d,%d,%d) %d%%", update_file_block, begin, len, begin * 100 / obdfilefilesize);
    Ram_Free(packet_buf);
}

static void obd_cmd_hex2(FuncPtr funcPtr)
{
    static kal_uint8 count = 0;
    static FuncPtr _funcPtr = NULL;
    if(funcPtr != NULL)
    {
        _funcPtr = funcPtr;
        count = 0;
    }
    if(count < 5)
    {
        count++;
        track_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 3000, obd_cmd_hex2, NULL);
        if(_funcPtr != NULL)
        {
            _funcPtr();
        }
    }
}

static void obd_cmd_hex(kal_uint8 *data, int len)
{
    static kal_uint8 status = 0;
    LOGD(L_UART, L_V5, "收到二进制数据%d 命令字: %0.2X %0.2X", len, data[0], data[1]);
    LOGH(L_UART, L_V1, data, len);
    track_stop_timer(TRACK_CUST_OBD_START_TIMER_ID);
    tr_stop_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID);
    g_tick_new = OTA_kal_get_systicks();
    if(data[0] == 0x61 && data[1] == 0x05)   /*查询版本反馈*/
    {
        kal_uint16 i = 2, l1 = 0, l2 = 0, l3 = 0;
        char *s1="", *s2="", *s3="";
        l1 = (data[i] << 8) | data[i+1];
        s1 = &data[i+2];
        i += l1 + 2;
        if(i < len)
        {
            l2 = (data[i] << 8) | data[i+1];
            s2 = &data[i+2];
            i += l2 + 2;
            if(i < len)
            {
                l3 = (data[i] << 8) | data[i+1];
                s3 = &data[i+2];
            }
        }
        LOGS("版本查询成功: [%s]\t[%s]\t[%s]", s1, s2, s3);
        status = 1;
        tr_stop_timer(TRACK_CUST_OBD_SEND_OVERTIME_TIMER_ID);
        if(mode_auto_update && obd_type == 0)
        {
            track_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, obd_send_cmd_update_begin, (void*)0);
            //obd_cmd_hex2(obd_send_cmd_restart);
        }
        else if(mode_auto_update && obd_type == 1)
        {
            obd_cmd_hex2(obd_send_cmd_update_filename);
        }
    }
    else if(data[0] == 0x61 && (data[1] == 0x11 || data[1] == 0x14))  /* 切换入APP */
    {
        if(data[2] != 0)
        {
            LOGS("OBD: 升级数据文件名异常!");
        }
        else
        {
            tr_stop_timer(TRACK_CUST_OBD_SEND_OVERTIME_TIMER_ID);
            mode_hex_decode = KAL_FALSE;
        }
    }
    else if(data[0] == 0x64 && data[1] == 0x02)  /* 升级数据文件名发送命令，反馈 */
    {
        if(data[2] != 0)
        {
            LOGS("OBD: 升级数据文件名异常!");
        }
        else
        {
            LOGS("OBD: 写入将要升级的文件名 成功");
            tr_stop_timer(TRACK_CUST_OBD_SEND_OVERTIME_TIMER_ID);
            update_file_block = 0;
            obd_cmd_hex2(obd_send_cmd_update_data);
            status = 2;
        }
    }
    else if(data[0] == 0x64 && data[1] == 0x03)  /* 升级数据文件内容发送，确认反馈 */
    {
        static U8 re = 0;
        if(data[2] != 0)
        {
            re++;
            if(re > 3)
            {
                LOGS("OBD: 烧录的升级数据块有误 %d, %d次重试仍然失败放弃继续写入.", data[2], re);
                return;
            }
            LOGS("OBD: 烧录的升级数据块有误 %d, 第%d次重复尝试写入", data[2], re);
        }
        else
        {
            tr_stop_timer(TRACK_CUST_OBD_SEND_OVERTIME_TIMER_ID);
            re = 0;
            update_file_block++;
            //get_no(0);
        }
        obd_cmd_hex2(obd_send_cmd_update_data);
        status = 3;
    }
    else if(data[0] == 0x64 && data[1] == 0x04)  /* 升级数据文件内容校验数据，确认反馈 */
    {
        static U8 re = 0;
        if(data[2] != 0)
        {
            re++;
            if(re > 3)
            {
                LOGS("OBD: 烧录的升级数据文件内容校验有误%d!", data[2]);
                return;
            }
            LOGS("OBD: 烧录的升级数据文件内容校验有误%d!, 第%d次重复尝试写入", data[2], re);
            tr_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, obd_send_cmd_md5_check);
        }
        else
        {
            tr_stop_timer(TRACK_CUST_OBD_SEND_OVERTIME_TIMER_ID);
            re = 0;
            {
                S32 ret;
                applib_md5_ctx md5_ctx;
                U8 hash_result[16] = {0};

                OTA_applib_md5_init(&md5_ctx);
                OTA_applib_md5_update(&md5_ctx, (kal_uint8 *)obdfiledatabuf, obdfilefilesize);
                OTA_applib_md5_final(hash_result, &md5_ctx);
                ret = track_write_file(OBD_MD5_FILE_PATH, hash_result, 16);
                LOGD(L_APP, L_V4, "write OBD MD5 file %d", ret);
            }
            update_file_block = 0;
            obdfilefilesize = 0;
            if(obdfiledatabuf) Ram_Free(obdfiledatabuf);
            LOGS("OBD: 校验通过");
            status = 4;
            {
                int ret;
                WCHAR FilePath[60] = {0};
                OTA_kal_wsprintf(FilePath, OBD_FILE_PATH);
                ret = OTA_FS_Delete(FilePath);
            }
            //obd_cmd_hex2(obd_send_cmd_restart);
            mode_auto_update = KAL_FALSE;
            mode_hex_decode = KAL_FALSE;
            mode_update = 1;
            obd_power_off_and_restart();
        }
    }
    else if(data[0] == 0x64 && data[1] == 0x07)  /* 回应？ */
    {
        static U8 re = 0;
        if(data[2] != 0)
        {
            re++;
            if(re > 3)
            {
                LOGS("OBD: 有误 %d, %d次重试仍然失败放弃继续写入.", data[2], re);
                return;
            }
            LOGS("OBD: 有误 %d, 第%d次重复尝试写入", data[2], re);
            track_start_timer(TRACK_CUST_OBD_OPENDATA_TIMER_ID, 1000, obd_send_cmd_update_begin, (void*)0);
            return;
        }
        LOGS("OBD: 发送“启动更新固件命令”成功");
        tr_stop_timer(TRACK_CUST_OBD_SEND_OVERTIME_TIMER_ID);
        re = 0;
        obd_cmd_hex2(obd_send_cmd_update_filename);
        //obd_cmd_hex2(obd_send_cmd_restart);
    }
    else if(data[0] == 0x65 && data[1] == 0x05)  /* 重启回应？ */
    {
        tr_stop_timer(TRACK_CUST_OBD_SEND_OVERTIME_TIMER_ID);
        if(mode_auto_update && status == 1)
        {
            obd_cmd_hex2(obd_send_cmd_update_filename);
        }
        else if(status == 4)
        {
            obd_cmd_hex2(obd_send_cmd_run_app);
            mode_auto_update = KAL_FALSE;
        }
        else
        {
            LOGS("OBD: 升级完成, OBD重启...");
        }
    }
}

static void track_cust_obd_data_hex(kal_uint8 *data, int len)
{
    static kal_uint8  buf[2000] = {0};
    static kal_uint32 flag = 0;
    static kal_uint32 tick = 0;
    kal_uint16 packet_len = 0, cmd;
    kal_uint8 *start = NULL, *end = NULL;
    kal_uint8 no = 0;
    int j = 0;

    if(len <= 0) return;
    if(tick > 0 && OTA_kal_get_systicks() - tick > OTA_kal_secs_to_ticks(20))
    {
        flag = 0;
    }
    tick = OTA_kal_get_systicks();
    if(flag + len < 1999)
    {
        memcpy(&buf[flag], data, len);
        flag += len;
        buf[flag] = 0;
    }
    else
    {
        if(len > 1999)
        {
            LOGD(L_UART, L_V1, "ERROR : Data too long!");
            return;
        }
        memcpy(buf, data, len);
        flag = len;
        buf[flag] = 0;
    }
    LOGD(L_UART, L_V2, "[recv](%d)", len);
    //LOGH(L_UART, L_V2, data, len);
    LOGH(L_UART, L_V2, buf, flag);
    for(j=0; j<flag-5; j++)
    {
        if(buf[j] == 0x55 && buf[j+1] == 0xAA && buf[j+2] == 0xF8 && buf[j+3] == 0xF0)
        {
            packet_len = (buf[j+4] << 8) | buf[j+5];
            no = buf[j+6];

            start = &buf[j];
            if(j+6+packet_len <= flag)
            {
                end = &buf[j+6+packet_len];
                obd_cmd_hex(&buf[j+7], packet_len - 1);

                LOGD(L_UART, L_V1, "flag:%d,%d", flag, end - buf);
                j = end - buf;
                if(j > flag)
                {
                    LOGD(L_UART, L_V1, "ERROR");
                    memset(buf, 0, 2000);
                    flag = 0;
                    return;
                }
            }
        }
    }
    //LOGD(L_UART, L_V2, "2 flag:%d, buf:%p, start:%p, end:%p", flag, buf, start, end);
    if(start == NULL)
    {
        return;
    }
    if(end < start && start > buf)
    {
        end = start;
    }
    if(end > buf)
    {
        kal_uint8 *bb;
        if(*(end+1) == 0x0a) end+=2;
        if(flag == (end - buf))
        {
            flag = 0;
        }
        else if(flag > (end - buf))
        {
            flag -= (end - buf);
            if(flag > 2000)
            {
                LOGD(L_UART, L_V1, "error");
                return;
            }
            bb = (U8*)Ram_Alloc(6, flag);
            if(bb == NULL)
            {
                LOGD(L_UART, L_V1, "error 2");
                return;
            }
            memcpy(bb, end, flag);
            memset(buf, 0, 2000);
            memcpy(buf, bb, flag);
            Ram_Free(bb);
        }
    }
    LOGD(L_UART, L_V2, "3 flag:%d, buf:%p, start:%p, end:%p", flag, buf, start, end);
}


void track_cust_obd_data(kal_uint8 *data, int len)
{
    static kal_uint8  buf[2000] = {0};
    static kal_uint32 flag = 0;
    static kal_uint32 tick = 0;
    static int last_len = 0;
    kal_uint8 *start = NULL, *end = NULL;
    int j = 0, x;
    
    if(mode_hex_decode)
    {
        track_stop_timer(TRACK_CUST_OBD_CXALL_TIMER_ID);
        track_cust_obd_data_hex(data, len);
        return;
    }

    if(len <= 0 || (len == 1 && (*data == 0 || *data == 0xFF))) return;
    
    if(tick > 0 && OTA_kal_get_systicks() - tick > OTA_kal_secs_to_ticks(20))
    {
        flag = 0;
    }
    tick = OTA_kal_get_systicks();
    
    if(flag + len < 1999)
    {
        for(j=0; j < len; j++)
        {
            if(data[j] >0 && data[j] <= 128)
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
            LOGD(L_UART, L_V1, "ERROR : Data too long!");
            return;
        }
        for(j=0, flag=0; j < len; j++)
        {
            if(data[j] >0 && data[j] <= 126)
            {
                buf[flag++] = data[j];
            }
        }
        buf[flag] = 0;
    }
    LOGD(L_UART, L_V5, "[recv](%d,%d,%d): %s", strlen(buf), flag, len, data);
    LOGH(L_UART, 6, buf, flag);
    if(flag <= 0) return;
    buf[flag] = 0;
    //if(len == 2 && data[0] == 0x0D && data[1] == 0x0A) return;
    //LOGD(L_UART, L_V2, "[%d] %s", len, data);
    LOGD(L_UART, L_V6, "1 flag:%d, buf:%p, start:%p, end:%p", flag, buf, start, end);
    for(j=0; j<flag-5; j++)
    {
        if(buf[j] == 'A' && buf[j+1] == 'T' && buf[j+2] == '^' && buf[j+3] == 'D' && buf[j+4] == '=')
        {
            start = &buf[j];
            end = strstr(start, "\r\n");
            if(end != NULL)
            {
                int size, i, ret;
                j = end - buf;
                if(j > flag)
                {
                    LOGD(L_UART, L_V1, "ERROR");
                    memset(buf, 0, 2000);
                    flag = 0;
                    return;
                }
                if(*(end - 5) == ',')
                {
                    static kal_uint8  crc[4] = {0};
                    static char *keeplink_crc = "7D16";
                    if(!memcmp(end-4,crc,4) && memcmp(end-4,keeplink_crc,4))
                    {
                        *end = 0;
                        //LOGH(L_UART, L_V2, crc, 4);
                        LOGD(L_UART, L_V1, "重复，跳过(%s)", start);
                        g_tick_new = OTA_kal_get_systicks();
                        continue;
                    }
                    memcpy(crc, end-4, 4);
                }
                if(G_realtime_data.netLogControl & 256)
                {
                    cust_packet_log_data_ext2(8, "[Recv]", (kal_uint8 *)buf, strlen((char *)buf));
                }
                obd_parameters_count = track_fun_str_analyse(start + 5, obd_parameters, OBD_PARAMETER_MAX, NULL, "\r\n", ',');
                size = sizeof(OBD_Data) / sizeof(cust_recv_struct);
                LOGD(L_UART, L_V1, "[%d] %s", obd_parameters_count, start + 5);
                track_stop_timer(TRACK_CUST_OBD_START_TIMER_ID);
                for(i = 0; i < size; i++)
                {
                    ret = strcmp(obd_parameters[0], OBD_Data[i].cmd_string);
                    //LOGD(L_UART, L_V9, "ret=%d|%s,%s", ret, obd_parameters[0], OBD_Data[i].cmd_string);
                    if(!ret)
                    {
                        LOGD(L_UART, L_V9, "[%d], %s", i, OBD_Data[i].cmd_string);
                        if(OBD_Data[i].func_ptr != NULL)
                        {
                            OBD_Data[i].func_ptr();
                            LOGD(L_UART, L_V1, "run [%d], %s", i, OBD_Data[i].cmd_string);
                            g_tick_new = OTA_kal_get_systicks();
                        }
                        break;
                    }
                }
                LOGD(L_UART, L_V1, "flag:%d,%d", flag, end - buf);
            }
        }
    }
    //LOGD(L_UART, L_V2, "2 flag:%d, buf:%p, start:%p, end:%p", flag, buf, start, end);
    if(start == NULL)
    {
        return;
    }
    if(end == 0 && start > buf)
    {
        end = start;
    }
    if(end > buf)
    {
        kal_uint8 *bb;
        if(*(end+1) == 0x0a) end+=2;
        if(flag == (end - buf))
        {
            flag = 0;
        }
        else if(flag > (end - buf))
        {
            flag -= (end - buf);
            if(flag > 2000)
            {
                LOGD(L_UART, L_V1, "error");
                return;
            }
            bb = (U8*)Ram_Alloc(6, flag);
            if(bb == NULL)
            {
                LOGD(L_UART, L_V1, "error 2");
                return;
            }
            memcpy(bb, end, flag);
            memset(buf, 0, 2000);
            memcpy(buf, bb, flag);
            Ram_Free(bb);
        }
    }
    LOGD(L_UART, L_V6, "3 flag:%d, buf:%p, start:%p, end:%p", flag, buf, start, end);
}

void track_cust_module_ext_vbat_to_obd(kal_uint32 volt)
{
    static kal_bool st = KAL_FALSE;
    U8 acc = track_cust_status_acc();
    if(volt >= 8000000 && !st && acc == 1)
    {
        st = KAL_TRUE;
        obd_poweron(31);
    }
    else if(volt < 8000000 && st && acc != 1)
    {
        st = KAL_FALSE;
    }
}

char *track_obd_get_version(void)
{
    int len = strlen(obd_ver);
    LOGD(L_UART, L_V5, "");
    if(G_parameter.obd.sw != 1)
    {
        return "(OBD OFF)";
    }
    //"(Need to be upgraded)"
    if(!track_drv_charget_usb_status() && track_drv_get_external_batter(1) < 8000000)
    {
        return "(ACC no charger)";
    }
    if(len <= 0)
    {
        return "(No readed version)";
    }
    return obd_ver;
}

#endif /* __OBD__ */
