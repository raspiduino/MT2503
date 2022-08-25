/******************************************************************************
 * track_project_cmd.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        各项目特殊的指令解析，优先级最高，和标准版同名的，只解析本文件的指令
 *
 * modification history
 * --------------------
 * v1.0   2017-06-30,  chengjun create this file
 *
 ******************************************************************************/

/****************************************************************************
* Include Files                         包含头文件
*****************************************************************************/
#include "track_os_data_types.h"
#include "kal_public_defs.h"
#include "track_os_log.h"
#include "track_cmd.h"

#include "track_cust.h"
#include "Conversions.h"
#include <math.h>
#include "us_timer.h"
#include "uem_context.h"
#include "track_at_call.h"
#include "track_os_ell.h"
#include "track_nvram_default_value.h"
#include "track_version.h"
#include "track_os_paramete.h"
//20191008
#include "track_cust_controller_protocol.h"

/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/

static char *blank = {""}, *s_ON = {"ON"}, *s_OFF = {"OFF"}, *s_Error = {"ERROR"};
#define ON_OFF(value) (value==0?s_OFF:(value==1?s_ON:s_Error))

/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/


/*****************************************************************************
 *  Struct                              数据结构定义
 *****************************************************************************/
typedef void(*Func_CustRecvPtr)(CMD_DATA_STRUCT*);

typedef struct
{
    const char           *cmd_string;
    Func_CustRecvPtr     func_ptr;
    BOOL                valid;
} track_project_cmd_table_struct;
//设置成功
static kal_uint8 setok[10] =
{
    0xFF, 0x0C, 0x8B, 0xBE, 0x7F, 0x6E, 0x62, 0x10, 0x52, 0x9F
};
//设置失败
static kal_uint8 setfail[10] =
{
    0xFF, 0x0C, 0x8B, 0xBE, 0x7F, 0x6E, 0x59, 0x31, 0x8D, 0x25
};
//查询成功
static kal_uint8 cxok[10] =
{
    0x67, 0xE5, 0x8B, 0xE2, 0x62, 0x10, 0x52, 0x9F, 0xFF, 0x0C
};
//查询失败
static kal_uint8 cxfail[10] =
{
    0x67, 0xE5, 0x8B, 0xE2, 0x59, 0x31, 0x8D, 0x25, 0xFF, 0x0C
};

static char rsp_msg[80] = {0};
static U8 smsStyle = 0;//1-查询 2-设置成功 3-设置失败
static CMD_DATA_STRUCT msg_str = {0};
static U8 isSmsCode = 0;


/*****************************************************************************
 *  Global Functions			全局变量
 *****************************************************************************/
extern controller_data_struct cData;
extern kal_uint8 realtime_disarm_tmp;
/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/
//extern void track_cust_N07BT_recv(kal_uint8 *data, kal_uint16 len);
static kal_uint8 voice_swtich = 1;

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
extern kal_int8 track_drv_ble_gatt_switch(kal_uint8 status);
extern void track_cust_vehicle_status(kal_uint8 *src);
extern void track_cust_N07_paket_06(kal_uint8 *data, kal_uint8 len, kal_uint8 entype, kal_uint16 execode);
//-------------
extern void track_cust_acc_fault_alarm(void *  arg);
extern void Substantiv_voice_id(kal_uint8 voice_sta);
void xc_play(void* time);

//20191008
extern void request_static_packet(void* param);


//---------------------------------
static void cmd_set_volume(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 voice_level , audio_mode;
    int volume = 0;
    audio_mode = track_drv_sys_aud_get_active_audio_mode();
    voice_level = track_drv_sys_aud_get_volume_level(audio_mode, 6/*VOL_TYPE_MEDIA*/);

    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d,%d", cmd->pars[0], voice_level, audio_mode);
        return;
    }
    volume = track_fun_atoi(cmd->pars[1]);
    if(volume < 7 && volume > 0)
    {
        track_drv_sys_audio_set_volume(6/*VOL_TYPE_MEDIA*/, volume);
        sprintf(cmd->rsp_msg, "SETVOLUME OK");
    }
    else
    {
        sprintf(cmd->rsp_msg, "ERROR!");
    }
}
static int dotime = 0;
static kal_uint8 doring = 0;

void track_cust_gpio_spk(void* arg)
{
    U8 param = (U8)arg;
    if(param % 2 == 0)
    {
        GPIO_WriteIO(1, 41);
    }
    else
    {
        GPIO_WriteIO(0, 41);
    }
    LOGD(L_APP, L_V5, "喇叭%d", param);
    if(param == 8)
    {
        GPIO_WriteIO(1, 41);
        track_cust_play_amr_ring(doring, 6);
        //sprintf(cmd->rsp_msg, "THE %d'RING.", doring);
    }
    else
    {
        param++;
        track_start_timer(TRACK_CUST_TEST_RING_TIMER_ID, dotime, track_cust_gpio_spk, (void *)param);
    }

}
static void cmd_test_ting(CMD_DATA_STRUCT * cmd)
{
    char exe = 0;
    char dd = cmd->pars[1][0];
    kal_uint8 ring = 0;
    //ring = track_fun_atoi(cmd->pars[1]);
    exe = track_GPIO_ReadIO(41);
    if(dd >= 'A' && dd <= 'F')
    {
        ring = (dd - 'A' + 10);
    }
    else if(dd >= '0' && dd <= '9')
    {
        ring = (dd - '0');
    }
    track_cust_play_voice_by_mp3(ring, 6);
#if 0
    exe = track_GPIO_ReadIO(41);
    track_cust_monitor_set_speaket(1);
    if(cmd->part >= 1)
    {
        ring = track_fun_atoi(cmd->pars[1]);
        doring = ring;
    }
    if(cmd->part == 2)
    {
        dotime = track_fun_atoi(cmd->pars[2]);
    }
    if(exe != 1)
    {
        GPIO_ModeSetup(41, 0);
        GPIO_InitIO(1, 41);
        GPIO_WriteIO(1, 41);
    }
    track_cust_gpio_spk((void*)2);
    //track_cust_play_amr_ring(ring, 6);
    sprintf(cmd->rsp_msg, "THE %d'RING.", ring);
#endif
}
static void track_mma_delay(kal_uint16 time)               //Time delay function
{
    kal_uint16 i;
    for(i = 0; i < time; i++) ;             //Software loop for time delay
}

static U8 bt_ele_swon(void*par)
{
    int exe = 0;
    U8 expect = (U8)par;

    LOGD(L_APP, L_V5, "开锁%d,%d", expect, GPIO_ReadIO(ELE_SWT_ON_GPIO), track_GPIO_ReadIO(ELE_SWT_ON_GPIO));
    if(expect)
    {
        exe = GPIO_ReadIO(ELE_SWT_ON_GPIO);
        if(!exe)
        {
            GPIO_WriteIO(1, ELE_SWT_ON_GPIO);
            if(track_GPIO_ReadIO(ELE_SWT_ON_GPIO) == 0)//(GPIO_ReadIO(ELE_SWT_ON_GPIO) == 0)
                return 0x01;
            track_start_timer(TRACK_CUST_ELE_SW_TIMER_ID, 1500, bt_ele_swon, (void *) 0);
        }
        else
        {
            return 0x02;
        }
    }
    else
    {
        GPIO_WriteIO(0, ELE_SWT_ON_GPIO);
    }
    return 0x00;
}

static U8 bt_ele_swoff(void*par)
{
    int exe = 0;
    U8 expect = (U8)par;
    LOGD(L_APP, L_V5, "关锁%d,%d", expect, GPIO_ReadIO(ELE_SWT_OFF_GPIO), track_GPIO_ReadIO(ELE_SWT_OFF_GPIO));
    //track_drv_gpio_set

    if(expect)
    {
        exe = GPIO_ReadIO(ELE_SWT_OFF_GPIO);
        if(!exe)
        {
            GPIO_WriteIO(1, ELE_SWT_OFF_GPIO);
            if(track_GPIO_ReadIO(ELE_SWT_OFF_GPIO) == 0)//(GPIO_ReadIO(ELE_SWT_OFF_GPIO) == 0)
                return 0x01;
            track_start_timer(TRACK_CUST_ELE_SW_TIMER_ID, 1500, bt_ele_swoff, (void *) 0);
        }
        else
        {
            return 0x02;
        }
    }
    else
    {
        GPIO_WriteIO(0, ELE_SWT_OFF_GPIO);
    }
    return 0x00;
}
static U8 bt_wheel_lock_swon(void*par)
{
    int exe = 0;
    U8 expect = (U8)par;

    if(expect)
    {
        exe = GPIO_ReadIO(ROSE_GATE_OPEN_GPIO);
        if(!exe)
        {
            GPIO_WriteIO(1, ROSE_GATE_OPEN_GPIO);
            LOGD(L_BMS, L_V5, "%d:%d", GPIO_ReadIO(ROSE_GATE_OPEN_GPIO), track_GPIO_ReadIO(ROSE_GATE_OPEN_GPIO));

            if(track_GPIO_ReadIO(ROSE_GATE_OPEN_GPIO) == 0)//(GPIO_ReadIO(ROSE_GATE_OPEN_GPIO) == 0)
            {
                return 0x01;
            }
            track_start_timer(TRACK_CUST_WHEEL_LOCK_TIMER_ID, 1100, bt_wheel_lock_swon, (void *) 0);
        }
        else
        {
            return 0x02;
        }
    }
    else
    {
        GPIO_WriteIO(0, ROSE_GATE_OPEN_GPIO);
    }
    return 0x00;
}

static U8 bt_wheel_lock_swoff(void*par)
{
    int exe = 0;
    U8 expect = (U8)par;

    if(expect)
    {
        exe = GPIO_ReadIO(ROSE_GATE_CLOSE_GPIO);
        if(!exe)
        {
            GPIO_WriteIO(1, ROSE_GATE_CLOSE_GPIO);

            LOGD(L_BMS, L_V5, "%d:%d", GPIO_ReadIO(ROSE_GATE_CLOSE_GPIO), track_GPIO_ReadIO(ROSE_GATE_CLOSE_GPIO));
            if(track_GPIO_ReadIO(ROSE_GATE_CLOSE_GPIO) == 0)//(GPIO_ReadIO(ROSE_GATE_CLOSE_GPIO) == 0)
                return 0x01;
            track_start_timer(TRACK_CUST_WHEEL_LOCK_TIMER_ID, 1100, bt_wheel_lock_swoff, (void *) 0);
        }
        else
        {
            return 0x02;
        }
    }
    else
    {
        GPIO_WriteIO(0, ROSE_GATE_CLOSE_GPIO);
    }
    return 0x00;
}

kal_uint8 track_light_status(void* arg)
{
    kal_uint8 param = (kal_uint8)arg;
    kal_int8 exe = GPIO_ReadIO(HEAD_LIGHT_GPIO);
    if(exe != param)
    {
        GPIO_WriteIO(param, HEAD_LIGHT_GPIO);
        return 1;
    }
    return 0;
}

kal_uint8 track_acc_status(void* arg)
{
    static int accState = 0;
    kal_uint8 param = (kal_uint8)arg;
    kal_int8 exe = track_GPIO_ReadIO(ELE_LOCK_GPIO);//GPIO_ReadIO(ELE_LOCK_GPIO);

    LOGD(L_BMS, L_V5, "%d:%d:%d:%d", track_GPIO_ReadIO(ELE_LOCK_GPIO), exe, param, accState);
    if(param == 3)
    {
        return accState;
    }
    if(param == 2)
    {
        param = 1;
        accState = 1;
    }
    else
    {
        accState = 0;
    }
	track_start_timer(TRACK_CUST_ACC_ALRM_ID, 2000, track_cust_acc_fault_alarm, (void *)param);//2019
    if(param == 0 || param == 1)
    {
        if(exe != param)
        {
            int i;
            for(i = 0; i < 3; i++)
            {
                // 最多重复设置3次，防止设置失败。
                GPIO_WriteIO(param, ELE_LOCK_GPIO);
                exe = track_GPIO_ReadIO(ELE_LOCK_GPIO);
                if(exe == param)
                {
                    return exe;
                }
            }
            if(exe != param)
            {
                return 99;
            }
        }
    }

    return 99;
}

void cmd_light(CMD_DATA_STRUCT *cmd)//201904
{

    if(cmd->part == 0)
    {
        kal_int8 vlue = GPIO_ReadIO(HEAD_LIGHT_GPIO);
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], vlue);
        return;
    }
    else if(cmd->part == 1)
    {
        if(!strcmp(cmd->pars[1], "ON"))
        {
            GPIO_WriteIO(1, HEAD_LIGHT_GPIO);
            sprintf(cmd->rsp_msg, "%s = ON", cmd->pars[0]);
            return;
        }
        else if(!strcmp(cmd->pars[1], "OFF"))
        {
            GPIO_WriteIO(0, HEAD_LIGHT_GPIO);
            sprintf(cmd->rsp_msg, "%s = OFF", cmd->pars[0]);
            return;
        }
        else
        {
            sprintf(cmd->rsp_msg, "%s = FAIL", cmd->pars[0]);
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error! Number of Parameters Error!");
        return;
    }

}


void cmd_test_acc(CMD_DATA_STRUCT * cmd)
{
    GPIO_ModeSetup(ELE_LOCK_GPIO, 0);
    GPIO_InitIO(1, ELE_LOCK_GPIO);
    if(!strcmp(cmd->pars[1], "H"))
    {
        track_acc_status((void*)1);
    }
    else if(!strcmp(cmd->pars[1], "L"))
    {
        track_acc_status((void*)0);
    }
    if(strcmp(cmd->pars[1], "H") && strcmp(cmd->pars[1], "L")) return;
    sprintf(cmd->rsp_msg, "OK!");
}
void cmd_exbatlockon(CMD_DATA_STRUCT * cmd)
{
    bt_ele_swon((void*)1);
}
void cmd_exbatlockoff(CMD_DATA_STRUCT * cmd)
{
    bt_ele_swoff((void*)1);
}
void cmd_rearwheelon(CMD_DATA_STRUCT * cmd)
{
    bt_wheel_lock_swoff((void *)1);
}
void cmd_rearwheeloff(CMD_DATA_STRUCT * cmd)
{
    bt_wheel_lock_swon((void *)1);
}
#if defined(__NF2318__)
extern void request_static_packet(void* param);
static kal_uint8 datareq[11] = {0x4f , 0x2a, 0x66 , 0x03 , 0xa2 , 0x52 , 0x00 , 0x87 , 0x01 , 0x0d , 0x0a}; //{0x4F ,0x2A ,0x66, 0x03,0xB8 ,0x00 ,0x00 ,0x4B ,0x01 ,0x0D ,0x0A };//{0x4f,0x2a,0x66,0x03,0xa2,0x52,0x00,0x87,0x01,0x0d,0x0a};
static void data_reques(CMD_DATA_STRUCT *cmd)
{
    //LOGH2(L_UART, L_V1, "", datareq, 11);
    request_static_packet((void*)99);

    //U_PutUARTBytes(uart_port3, datareq, 11);
}
#endif
static void cmd_uart1test(CMD_DATA_STRUCT *cmd)
{
    track_drv_bms_uart_test();
}
static cmd_N07jiami(CMD_DATA_STRUCT *cmd)
{
    if(!strcmp(cmd->pars[1], "0"))
    {

        //extern void rsa_test_cml(void);
        //rsa_test_cml();
        //track_cust_N07_data(rz,266);
    }
    else if(!strcmp(cmd->pars[1], "1"))
    {
        //track_cust_N07_data(denglu,22);
    }
    else if(!strcmp(cmd->pars[1], "2"))
    {
        track_cust_n07_packet_00();
    }
    else if(!strcmp(cmd->pars[1], "3"))
    {
        track_cust_no7_paket_01();
    }
}
kal_uint8 split(const char *data)
{
    kal_uint8 temp = 0;
    char d1 = 0, d2 = 0;
    kal_int8 t1, t2;

    d1 = data[0];
    d2 = data[1];
    LOGD(L_UART, L_V1, "%c,%c", d1, d2);
    if('A' <= d1 && d1 <= 'F')
        t1 = d1 - 'A' + 10;
    if('0' <= d1 && d1 <= '9')
        t1 = d1 - '0';
    //temp = t1;
    if('A' <= d2 && d2 <= 'F')
        t2 = d2 - 'A' + 10;
    if('0' <= d2 && d2 <= '9')
        t2 = d2 - '0';
    LOGD(L_UART, L_V1, "%x,%x", t1, t2);
    temp = (t1 << 4) | t2;
    //LOGD(L_UART, L_V1, "%x",temp);
    return temp;
}

static cmd_bt_test(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 tmp = 0;
    kal_uint8 data[2];
    data[0] = 0x4F;
    tmp = split(cmd->pars[1]);
    data[1] = tmp;
    //track_cust_N07BT_recv(data, 2);
}

void command_split(kal_uint8 *data, kal_uint8 len)
{
    int i = 0;
    kal_uint8 tmp[100];
    memcpy(tmp, data, len);
    for(i = 0; i < len; i++)
    {
        if(tmp[i] == 0x3D)
        {
            tmp[i] = 0x2C;
        }
    }
    LOGH2(L_APP, L_V5, "", data, len);

}
void cmd_at(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 tmp[20];
    kal_uint8 len = 0;
    len = strlen(cmd->pars[1]);
    memcpy(tmp, cmd->pars[1], len);
    command_split(tmp, len);
}
extern
char *track_get_app_version_datetime(void);

extern kal_char *build_date_time(void);
static bool cmd_softversion(CMD_DATA_STRUCT *cmd)
{
    U8 sw[3] = {0};

    extern void track_get_softversionHex(kal_uint8 * src);
    if(cmd->part != 0)
    {
        sprintf(cmd->rsp_msg, "Error! Number of Parameters Error!");
        return;
    }
    track_get_softversionHex(sw);
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 1;
    }
    sprintf(cmd->rsp_msg, "SOFTVERSION=%02X%02X%02X", sw[0], sw[1], sw[2]);

#if 0
    //char buf[128] = {0};
    kal_uint8 len = 0;
    kal_int8 ret;
    char versionchr[50];
    char *ver;
    char *build;
    if(cmd->part == 0)
    {
        ver = track_get_app_version();
        build = track_get_app_version_datetime();
        if(strlen(ver) <= 0)
        {
            ver = (char*)release_verno();
            build = build_date_time();
        }
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "VERSION:%s BUILD:%s", ver, build);
    }
#endif
}
static bool cmd_gsm(CMD_DATA_STRUCT *cmd)
{
    //char buf[128] = {0};
    kal_uint8 len = 0;
    char num[10] = {0};
    kal_uint8 level = 0;
    float signal = 0.0;
    int tmp = 0;
    /*
        tmp = track_cust_get_rssi(-1);
        LOGD(L_APP, L_V5, "gsm_level %d,tmp %d", level, tmp);
    	if(tmp == 99) tmp = 0;
        else if(tmp > 27) tmp = 9;
        else
        {
            tmp = tmp / 3;
        }
    */
    tmp = track_cust_get_rssi_level();

    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 1;
    }
    sprintf(cmd->rsp_msg, "GSM=%d", tmp); //98%
}
static void cmd_bat(CMD_DATA_STRUCT *cmd)
{
    charge_measure_struct charge_measure = {0};
    kal_int32 vbat = 0, ichr = 0, vchr = 0;
    kal_int32 BatTemp = 0;
    float charger = 0;
    if(cmd->part > 1)
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }
    track_bmt_get_ADC_result(&charge_measure);
    charger = track_cust_status_charger();
    if(charger > 1) charger = 1;
    //BatTemp = (float)charge_measure.bmt_vTemp/1000;
    LOGD(L_APP, L_V5, "%f,%f", charge_measure.bmt_vBat, charge_measure.bmt_iChr);
    vbat = charge_measure.bmt_vBat * 1000000;
    ichr = charge_measure.bmt_iChr * 1000000;
    vchr = charge_measure.bmt_vChr * 1000000;
    if(track_cust_status_charger() == 0 || vbat <= 3618807)
    {
        vbat = track_drv_get_batter_voltage();
        LOGD(L_APP, L_V5, "重新算%d", vbat);
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 1;
    }
    sprintf(cmd->rsp_msg, "VBAT=%d:%d:%d", vbat, vchr, ichr);
}

static bool cmd_vin(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 vinh = cData.totalValtage[0];
    kal_uint8 vinl = cData.totalValtage[1];
    kal_uint16 vin = 0;
    if(track_cust_status_charger() != 0)
    {
        if(cData.totalValtage[0] == 0 && cData.totalValtage[1] == 0)
        {
            //exVBAT = track_cust_get_ext_volt();
            vin = (float)track_cust_get_ext_volt() / 1000.0;
            LOGD(L_BMS, L_V5, "电池电压3:%d", vin);
        }
        else
        {
            vin = (vinh & 0x00FF) << 8;
            vin = vin | (vinl & 0x00FF);
        }
    }
    else
    {
        vin = 0;
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 1;
    }

    sprintf(cmd->rsp_msg, "VIN=%d", vin);
}
static bool cmd_batver(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 verS = cData.versionNum[0];
    kal_uint8 verH = cData.versionNum[1];
    kal_uint16 version = 0;
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 1;
    }

    sprintf(cmd->rsp_msg, "BATVER=%02X", verH);
}
static bool cmd_BATMANUFACTURE(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 temp[10] = {0x50, 0x48, 0x59, 0x4C, 0x49, 0x4F, 0x4E, 0x20, 0x47, 0x58};
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 1;
    }
    //kal_uint8 temp[15] = {0x50, 0x48, 0x59, 0x4c, 0x49, 0x4f, 0x4e, 0x20, 0x42, 0x41, 0x54, 0x54, 0x45, 0x52, 0x59};
    sprintf(cmd->rsp_msg, "BATMANUFACTURE=%s", cData.valtageManufacturer);
}

static bool cmd_BATSN(CMD_DATA_STRUCT *cmd)
{
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 1;
    }
    sprintf(cmd->rsp_msg, "BATSN=%s", cData.barCode);
}

static bool cmd_DEVICESTATUS(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 tmp = 0;
    kal_uint8 sta[2] = {0};
    track_cust_vehicle_status(sta);
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 1;
    }
    sprintf(cmd->rsp_msg, "DEVICESTATUS=%02X%02X", sta[0], sta[1]);
    //tmp = (sta[0]&0x00FF) << 8;
    //tmp |= sta[1];
    //sprintf(cmd->rsp_msg, "DEVICESTATUS=%d",tmp);
}

kal_uint8 cmd_soh(controller_data_struct data)
{
    kal_uint16 tmp = 0;
    float tmp2 = 0;
    float tmp1  = 0;
    kal_uint8 result = 0;
    tmp = (data.leftCapatiryH & 0x00FF) << 8 | data.leftCapatiryL;
    //LOGD(L_APP, L_V5, "tmp:0x%04X,0x%02X,0x%02X,0x%02X", tmp,cData_temp.relativeCapacityPer,cData_temp.absoluteFullCapacity[0],cData_temp.absoluteFullCapacity[1]);
    tmp1 = (float)tmp / (float)data.relativeCapacityPer;
    tmp2 = (float)((data.absoluteFullCapacity[0] & 0x00FF) << 8 | data.absoluteFullCapacity[1]) * 1.00;
    LOGD(L_APP, L_V5, "tmp1:%f,tmp2:%f", tmp1, tmp2); //0x%04X
    result = (tmp1 * 100 / tmp2) * 100;
    return result;
}
void cmd_bms_sigle_battery_voltage(kal_uint8 *dec, kal_uint8 *src)
{
    int i = 0, j = 1;
    for(i = 0; i < 28; i += 2)
    {
        dec[i+1] = src[j-1];
        dec[i] = src[j];
        j += 2;
    }
    LOGH(L_APP, L_V5, dec, 28);
}

static bool cmd_BMSSTATUS(CMD_DATA_STRUCT *cmd)
{
    int i = 0, l = 0, len = 1000;
    char vols[1000];
    char codebar[16];
    kal_uint8 fnamelen = 0;
    char vols_tmp[10];
    kal_uint8 volstmp[28];
    kal_uint16 soc = 0; //相对 SOC 百分比
    kal_uint16 arc = 0; // 可用剩余电量
    kal_uint16 asoc = 0; // 绝对SOC
    kal_uint16 afc = 0; // 绝对满电容量
    kal_uint16 soh = 0; //    锂电池组的健康状况
    kal_uint16 tem = 0; // 锂电池组表面温度
    kal_uint16 ele = 0; // 电流
    kal_uint16 vol = 0; // 锂电池组总电压
    kal_uint16 chaT = 0; // 锂电池组的循环次数
    //kal_uint16 vols = 0;//[1~14] 第1~14节电池电压
    kal_uint16 ccd = 0; // 锂电池组当前充电间隔时间
    kal_uint16 mcd = 0; // 最大充电间隔时间
    kal_uint16 batSn = 0;// 锂电池组的成品条形码
    kal_uint16 rVer = 0;//    锂电池 BMS 模块的版本号
    //kal_uint16 fname = 0; //锂电池组的制造厂商名称


    //kal_uint8 tt[15] = {0x50, 0x48, 0x59, 0x4c, 0x49, 0x4f, 0x4e, 0x20, 0x42, 0x41, 0x54, 0x54, 0x45, 0x52, 0x59};
    //kal_uint8 tt1[15] = {0x50, 0x48, 0x59, 0x4c, 0x49, 0x4f, 0x4e, 0x20, 0x42, 0x41, 0x54, 0x54, 0x45, 0x52, 0x59};

    controller_data_struct bms_data = {0};

    track_bms_struct_copy(&bms_data);
    soc = bms_data.relativeCapacityPer;
    arc = ((bms_data.leftCapatiryH & 0x00FF) << 8 | bms_data.leftCapatiryL);
    asoc = bms_data.absoluteCapacityPer;
    afc = ((bms_data.absoluteFullCapacity[0] & 0x00FF) << 8 | bms_data.absoluteFullCapacity[1]);
    soh = cmd_soh(bms_data);
    tem = ((bms_data.temperature[0] & 0x00FF) << 8 | bms_data.temperature[1]);
    if(tem != 0)
    {
        tem = ((tem - 2731) / 10);
    }
    ele = ((bms_data.currentH & 0x00FF) << 8 | bms_data.currentL);
    vol = ((bms_data.totalValtage[0] & 0x00FF) << 8 | bms_data.totalValtage[1]);
    chaT = ((bms_data.circulationOfBat[0] & 0x00FF) << 8 | bms_data.circulationOfBat[1]);
    ccd = ((bms_data.chargeInterval[0] & 0x00FF) << 8 | bms_data.chargeInterval[1]);
    mcd = (bms_data.largeChargeInterval[0] & 0x00FF) << 8 | bms_data.largeChargeInterval[1];
    cmd_bms_sigle_battery_voltage(volstmp, &bms_data.valtage[0]);
    //sprintf(vols, "vols:");
    for(i = 0; i < 28; i += 2)
    {
        kal_uint16 tmp = 0;
        memset(vols_tmp, 0, 10);
        tmp = ((volstmp[i] & 0x00FF) << 8 | volstmp[i+1]);
        ///sprintf(vols_tmp, "%d,",tmp);
        //strcat(vols,vols_tmp);
        l += snprintf(vols + l, len - l, "%d,", tmp);
    }

    //sprintf(cmd->rsp_msg, "BMSSTATUS=%d;arc:%d;asoc:%d;afc:%d;soh:%d;tem:%d", soc, arc, asoc, afc, soh, tem);

    sprintf(cmd->rsp_msg, "BMSSTATUS=soc:%d;arc:%d;asoc:%d;afc:%d;soh:%d;tem:%d;ele:%d;vol:%d;chaT:%d;vols:%s;ccd:%d;mcd:%d;batsn:%s;rVer:%02X%02X;fname:%s", soc, arc, asoc, afc, soh, tem\
            , ele, vol, chaT, vols, ccd, mcd, bms_data.barCode, bms_data.versionNum[0], bms_data.versionNum[1], bms_data.valtageManufacturer);
}

static void cmd_devicesn(CMD_DATA_STRUCT *cmd)
{
    kal_bool formaterror = KAL_FALSE;
    kal_int16 temp = 0;

    char sn_tmp[11];
    kal_uint8 sn_data[5];
    int i = 0, j = 0;
    kal_bool check = KAL_FALSE;

    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "%s=%s", cmd->pars[0], G_importance_parameter_data.SequenceNumber);
        return;
    }
    if(formaterror == KAL_FALSE && cmd->part == 1)
    {
        temp = strlen(cmd->pars[1]);

        if(temp > 8 && temp <= 10)
        {
            //memcpy(G_importance_parameter_data.SequenceNumber, cmd->pars[1], 10);
            //if(temp < 10)
            //{
            sprintf(sn_tmp, "%s", cmd->pars[1]);
            //}
            LOGD(L_APP, L_V5, "%s", sn_tmp);
            for(i = 0; i < temp; i++)
            {
                if('A' <= sn_tmp[i] && sn_tmp[i] <= 'F');
                else if('0' <= sn_tmp[i] && sn_tmp[i] <= '9');
                else
                {
                    formaterror = KAL_TRUE;
                    break;
                }
            }
        }
        else
        {
            formaterror = KAL_TRUE;
        }
    }
    else
    {
        formaterror = KAL_TRUE;
    }

    if(!formaterror)
    {
        memset(G_importance_parameter_data.SequenceNumber, 0, 10);
        memcpy(G_importance_parameter_data.SequenceNumber, cmd->pars[1], temp);
        track_cust_str_to_hex();
        if(Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE))//(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "OK!");
            //track_cust_sn_bak(NULL,1);
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error!");
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }
}
static cmd_domain(CMD_DATA_STRUCT *cmd)
{
    //www.cheweishi.cn:8500
    //120.195.105.20:8500
    kal_uint8 len = 0;
    char *port;//buf[128] = {0};
    kal_uint8 IP[4], dnsLen = 0;
    kal_bool flag = KAL_FALSE;
    kal_uint16 portInt = 0;
    nvram_server_addr_struct server = {0};
    char domain[TRACK_MAX_URL_SIZE] = {0};

    do
    {
        if(cmd->part == 0)
        {
            char tmp[100] = {0};
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                smsStyle = 1;
            }
            if(G_importance_parameter_data.server.conecttype == 1)
            {
                snprintf(cmd->rsp_msg, 99, "DOMAIN=%s:%d", track_domain_decode(G_importance_parameter_data.server.url), G_importance_parameter_data.server.server_port);
            }
            else if(G_importance_parameter_data.server.conecttype == 0)
            {
                snprintf(cmd->rsp_msg, 99, "DOMAIN=%d.%d.%d.%d:%d",
                         G_importance_parameter_data.server.server_ip[0],
                         G_importance_parameter_data.server.server_ip[1],
                         G_importance_parameter_data.server.server_ip[2],
                         G_importance_parameter_data.server.server_ip[3],
                         G_importance_parameter_data.server.server_port);
            }
            else
            {
                break;
            }
            return 1;
        }
        if((port = strchr(cmd->pars[1], ':')) == NULL) break;
        *port++ = '\0';
        LOGD(L_APP, L_V5, "Server:%s:%s", cmd->pars[1], port);
        if((dnsLen = strlen(cmd->pars[1])) > 99/*sizeof(gps_server_param.url)*/)break;

        if(track_fun_asciiIP2Hex(cmd->pars[1], IP) == KAL_FALSE) memset(IP, 0, 4);

        if(track_fun_check_data_is_port(port) == KAL_FALSE || (portInt = track_fun_parseInt(port)) <= 0) break;
        flag = KAL_TRUE;
    }
    while(0);
    if(flag)
    {
        if(IP[0] == 0 && IP[3] == 0)
        {
            G_importance_parameter_data.server.conecttype = 1;
            memset((void *)G_importance_parameter_data.server.url, 0, sizeof(G_importance_parameter_data.server.url));//以前当设置为url时发送的信息会有2个端口号这里改正
            //memcpy((void *)&G_importance_parameter_data.server.url, (void *)parameter, dnsLen);
            memcpy(domain, (void *)cmd->pars[1], dnsLen);
            track_domain_encode(domain, G_importance_parameter_data.server.url);
        }
        else
        {
            G_importance_parameter_data.server.conecttype = 0;
            memcpy(G_importance_parameter_data.server.server_ip, IP, 4);
        }
        G_importance_parameter_data.server.soc_type = 0;
        G_importance_parameter_data.server.server_port = portInt;
        flag = Track_nvram_write(NVRAM_EF_IMPORTANCE_PARAMETER_LID, 1, (void *)&G_importance_parameter_data, NVRAM_EF_IMPORTANCE_PARAMETER_SIZE);
    }

    if(flag)
    {
        track_cust_login(0x02);
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 2;
            sprintf(cmd->rsp_msg, "DOMAIN=%s:%d", cmd->pars[1], portInt);
        }
        else
        {
            sprintf(cmd->rsp_msg, "DOMAIN=OK");
        }
        track_start_timer(GPRS_SOCKET_INIT_TIMER_ID, 5000, track_soc_gprs_reconnect, (void*)4);
        return;
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        if(G_importance_parameter_data.server.conecttype == 1)
        {
            snprintf(cmd->rsp_msg, 99, "DOMAIN=%s:%d", track_domain_decode(G_importance_parameter_data.server.url), G_importance_parameter_data.server.server_port);
        }
        else if(G_importance_parameter_data.server.conecttype == 0)
        {
            snprintf(cmd->rsp_msg, 99, "DOMAIN=%d.%d.%d.%d:%d",
                     G_importance_parameter_data.server.server_ip[0],
                     G_importance_parameter_data.server.server_ip[1],
                     G_importance_parameter_data.server.server_ip[2],
                     G_importance_parameter_data.server.server_ip[3],
                     G_importance_parameter_data.server.server_port);
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "DOMAIN=FAIL");
    }
}
void static cmd_dfttimeout(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 dfttime = 0 ;
    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.dfttimeout);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    dfttime = track_fun_atoi(cmd->pars[1]);
    if(dfttime > 0 && dfttime < 61 && dfttime == track_fun_atoi(cmd->pars[1]))
    {
        G_parameter.ste_param.dfttimeout = dfttime;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                smsStyle = 2;
                sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.dfttimeout);
            }
            else
                sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.dfttimeout);
    }
    else
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}
void static cmd_dftlockvoiceplayt(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 dfttime = 0 ;
    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.dftlockvoiceplayt);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    dfttime = track_fun_atoi(cmd->pars[1]);
    if(dfttime >= 10 && dfttime <= 45 && dfttime == track_fun_atoi(cmd->pars[1]))
    {
        G_parameter.ste_param.dftlockvoiceplayt = dfttime;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                smsStyle = 2;
                sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.dftlockvoiceplayt);
            }
            else
                sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.dftlockvoiceplayt);
    }
    else
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}
void static cmd_freq(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 dfttime = 0 ;
    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.gps_work.Fti.interval_acc_on);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    dfttime = track_fun_atoi(cmd->pars[1]);
    if(dfttime >= 10 && dfttime <= 120 && dfttime == track_fun_atoi(cmd->pars[1]))
    {
        G_parameter.gps_work.Fti.interval_acc_on = dfttime;
        G_parameter.gps_work.Fti.interval_acc_off = dfttime;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                smsStyle = 2;
                sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.gps_work.Fti.interval_acc_on);
            }
            else
            {
                sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            }
            return;
        }
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.gps_work.Fti.interval_acc_on);
    }
    else
    {
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
    }

}
void static cmd_dormantfreq(CMD_DATA_STRUCT *cmd)
{
    kal_uint32 dfttime = 0 ;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.dormantfreq);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    dfttime = track_fun_atoi(cmd->pars[1]);
    if(dfttime >= 10 && dfttime <= 18000 && dfttime == track_fun_atoi(cmd->pars[1]))
    {
        G_parameter.ste_param.dormantfreq = dfttime;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }

    sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}
void static cmd_pulse(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 dfttime = 0 ;
    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.hbt_acc_on);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    dfttime = track_fun_atoi(cmd->pars[1]);
    if(dfttime >= 60 && dfttime <= 300)
    {
        G_parameter.hbt_acc_on = dfttime;
        G_parameter.hbt_acc_off = dfttime;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                smsStyle = 2;
                sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.hbt_acc_on);
            }
            else
            {
                sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            }
            return;
        }
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.hbt_acc_on);
    }
    else
    {
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
    }

}
void static cmd_sleept(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 dfttime = 0 ;
    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.sleept);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    dfttime = track_fun_atoi(cmd->pars[1]);
    if(dfttime >= 1 && dfttime <= 30)
    {
        G_parameter.ste_param.sleept = dfttime;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                smsStyle = 2;
                sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.sleept);
            }
            else
            {
                sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            }
            return;
        }
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.sleept);
    }
    else
    {
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

    }

}
void static cmd_pwrsave(CMD_DATA_STRUCT *cmd)
{
    sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
    G_parameter.ste_status.pwrsave = 1;
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    track_mode_shift((void*)17);//进入全休眠

}
void static cmd_volume(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 dfttime = 0 ;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.volume);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    dfttime = track_fun_atoi(cmd->pars[1]);
    if(dfttime >= 0 && dfttime <= 7)
    {
        G_parameter.ste_param.volume = dfttime;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }

    sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}
void static cmd_blekg(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    kal_uint8 sw  = G_parameter.ste_param.btsw;
    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.btsw);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value == 0 || value == 1)
    {
        G_parameter.ste_param.btsw = value;
        if(sw != value && value == 1)
        {
            track_drv_ble_gatt_switch(1);
        }
        else if(sw != value && value == 0)
        {
            track_drv_ble_gatt_switch(0);
        }

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                smsStyle = 2;
                sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.btsw);
            }
            else
            {
                sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            }
            return;
        }
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.btsw);
    }
    else
    {
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
    }

}
void static cmd_btmac(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%s", cmd->pars[0], (char *)track_drv_ble_get_mac(2));
        return;
    }
    if(cmd->part == 1)
    {
        nvram_ef_btradio_mtk_bt_chip_struct read_struct;
        int len, i, j;
        char ble_tmp[17];
        len = strlen(cmd->pars[1]);
        if(track_drv_ble_gatt_switch(99) == 1)
        {
            //sprintf(cmd->rsp_msg, "Error: BT is ON, SHUT DWON FIRST!");
            LOGD(L_BMS, L_V3, "BT is ON, SHUT DWON FIRST!");
            /*
            sprintf(cmd->rsp_msg, "%s=FAIL",cmd->pars[0]);
            return;*/
        }
        if(len != 12)
        {
            //sprintf(cmd->rsp_msg, "Error: length!");

            LOGD(L_BMS, L_V3, "Error: length!");
            sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
            return;
        }
        Track_nvram_read(NVRAM_EF_BTRADIO_MTK_BT_CHIP_LID, 1, (void *)&read_struct, NVRAM_EF_BTRADIO_MTK_BT_CHIP_SIZE);
        sprintf(ble_tmp, "%s", cmd->pars[1]);
        LOGD(L_APP, L_V5, "%s", ble_tmp);
        if(track_fun_check_mac(ble_tmp))
        {
            LOGH(L_APP, L_V5, read_struct.BDAddr, 6);
            track_fun_macToarr(read_struct.BDAddr, ble_tmp);

            if(Track_nvram_write(NVRAM_EF_BTRADIO_MTK_BT_CHIP_LID, 1, (void *)&read_struct, NVRAM_EF_BTRADIO_MTK_BT_CHIP_SIZE))
            {
                track_read_btaddr_data();
            }
            else
            {
                sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
                return;
            }
        }
        else
        {
            LOGD(L_BMS, L_V3, "not legal!");
            sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
            return;
        }

    }
    else
    {
        LOGD(L_BMS, L_V3, "parameters error!");
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
        return;
    }
    //sprintf(cmd->rsp_msg, "OK! %s", (char *)track_drv_ble_get_mac(2));
    sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
    track_os_intoTaskMsgQueue(track_cust_write_sim_backup_for_parameter);
    track_os_intoTaskMsgQueue(track_drv_syn_le_btaddr);

#if 0
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.bt.sw);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 0 && value <= 7)
    {
        G_parameter.bt.sw = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }
#endif
    //sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}
void static cmd_btname(CMD_DATA_STRUCT *cmd)
{
#if 1
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%s", cmd->pars[0], G_parameter.ste_param.bt_name);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = strlen(cmd->pars[1]);
    if(value >= 2 && value <= 20)
    {
        sprintf(G_parameter.ste_param.bt_name, "%s", cmd->pars[1]);

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }
#endif
    sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}
void track_cmd_resetbt(void* param)
{
    kal_uint8 bt_status[20] = {0};
    kal_uint8 sw = (kal_uint8)param;
    static U8 cont = 0;
    OTA_track_ble_bt_status(bt_status);

    LOGD(L_APP, L_V1, "Blue tooth status:%d,%d,cont:%d", bt_status[0], bt_status[1], cont);
    if(!sw)
    {
        if(!track_is_timer_run(TRACK_CUST_BLE_RESET_TIMER_ID) && !track_is_timer_run(TRACK_BT_RESET_OVERTIME_TIMER_ID))
        {
            track_drv_ble_gatt_switch(0);
            track_start_timer(TRACK_CUST_BLE_RESET_TIMER_ID, 4000, track_cmd_resetbt, (void *)1);
        }
    }
    else if(sw == 1)
    {
        LOGD(L_APP, L_V1, "Blue tooth status:%d,%d", bt_status[0], bt_status[1]);
        track_drv_ble_gatt_switch(1);
        track_start_timer(TRACK_BT_RESET_OVERTIME_TIMER_ID, 5000, track_cmd_resetbt, (void *)2);
    }
    else if(sw == 2)
    {
        if(bt_status[0] != 1)
        {
            if(cont < 5)
            {
                cont ++;
                track_drv_ble_gatt_switch(1);
                track_start_timer(TRACK_BT_RESET_OVERTIME_TIMER_ID, 5000, track_cmd_resetbt, (void *)2);
            }
            else
            {
                cont = 0;
                LOGD(L_APP, L_V1, "Blue tooth OPEN ERROR");
            }
        }
        else
        {
            cont = 0;
        }
    }
}
void static cmd_btreset(CMD_DATA_STRUCT *cmd)
{
    track_cmd_resetbt((void*)0);
    sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
}
void voice_delay(U8 ring)
{
    if(G_parameter.ste_param.volume >= 7)
        track_cust_play_amr_ring(ring, 6);
    else track_cust_play_amr_ring(ring, G_parameter.ste_param.volume);
}
static kal_uint8 delaytime = 1;//72 =50微秒

/*static */
void audio_amplifier(void* param)
{
    kal_uint8 arg = (kal_uint8)param;
    static int value = 0;
    //kal_uint8 delaytime = 50;//72 =50微秒
    if(arg == 1)
    {
        if(value == 0)//if(!track_is_timer_run(TRACK_CUST_AUDIO_AMPLIFIER_DELAY_TIMER_ID))
        {
            GPIO_WriteIO(1, 41);
            track_mma_delay(delaytime);
            GPIO_WriteIO(0, 41);

            track_mma_delay(delaytime);
            GPIO_WriteIO(1, 41);

            track_mma_delay(delaytime);
            GPIO_WriteIO(0, 41);

            track_mma_delay(delaytime);
            GPIO_WriteIO(1, 41);

            track_mma_delay(delaytime);
            GPIO_WriteIO(0, 41);

            track_mma_delay(delaytime);

            GPIO_WriteIO(1, 41);
            value  = 1;
        }
        //track_start_timer(TRACK_CUST_AUDIO_AMPLIFIER_DELAY_TIMER_ID, 20 * 1000, audio_amplifier, (void *)0);
    }
    else
    {
        value = 0;
        GPIO_WriteIO(0, 41);
    }
}
//-------------
static kal_uint16  playtimes = 0;
extern kal_uint8 track_get_muc_sta(void);
void play_voice(U8 ring)
{
    static int value = 0;
    LOGD(L_BMS, L_V1, "语音播放:%d sta:%d", ring,track_set_audio_file_play(99));
    //try one try 
    if(track_set_audio_file_play(99) == 1)
    {
    	if(ring == 13)
    	{
			track_cust_get_speelt_sta(0x01);
    	}
		return;
    }

    //LOGD(5, 5, "jjjjjjjjj---------> %d %d %d", track_set_audio_file_play(99),track_get_muc_sta(),track_is_timer_run(TRACK_CUST_TEST_RING_TIMER_ID));
    if((track_set_audio_file_play(99) == 0) && (track_get_muc_sta() == 1) && (track_is_timer_run(TRACK_CUST_TEST_RING_TIMER_ID) == 0))
    {//防止在播放MP3，还有缓存的语音未播放，在播放完一条的间隙间有其他想要播放从而打乱了MP3的播放
		if(track_cust_get_speelt_sta(99)==2)
		{
			
		}
		else
		{
    		return;
    	}
    }
	
    //return;
    //kal_uint8 delaytime = 60;//72 =50微秒
    if(voice_swtich == 0 || G_parameter.ste_param.volume == 0)
    {

        return;
    }
    if(ring != 99)
    {
        if(ring == 13 && track_cust_get_speelt_sta(99)!=2)
    	{
			track_cust_get_speelt_sta(0x02);
   		}
    	track_set_audio_file_play(1);
        audio_amplifier((void*)1);
#if 0
        if(value == 0)
        {
#if 1//验证是否由于这里导致播放语音时重启
            GPIO_WriteIO(1, 41);
            track_mma_delay(delaytime);
            GPIO_WriteIO(0, 41);

            track_mma_delay(delaytime);
            GPIO_WriteIO(1, 41);

            track_mma_delay(delaytime);
            GPIO_WriteIO(0, 41);

            track_mma_delay(delaytime);
            GPIO_WriteIO(1, 41);

            track_mma_delay(delaytime);
            GPIO_WriteIO(0, 41);

            track_mma_delay(delaytime);
#endif
            GPIO_WriteIO(1, 41);
            value = 1;
        }
#endif
        //if(G_parameter.ste_param.volume >= 7)
        //track_cust_play_amr_ring(ring, 6);
        //else track_cust_play_amr_ring(ring, G_parameter.ste_param.volume);
        //track_start_timer(TRACK_CUST_RING_OVERTIME_TIMER_ID, 30000, play_voice, (void *) 99);
        //track_start_timer(TRACK_CUST_RING_OVERTIME_TIMER_ID, 1000, voice_delay, (void *)ring);

        track_mma_delay(10);
        voice_delay(ring);
    }
    else
    {
        //验证波语音重启，用定时器关闭41口
        /*
            value = 0;
            GPIO_WriteIO(0, 41);*/
    }
}
static void cmd_test_ting1(CMD_DATA_STRUCT * cmd)
{
    static int doith = 0;
    char exe = 0;
    kal_uint8 ring = 0;
    exe = track_GPIO_ReadIO(41);
    //track_cust_monitor_set_speaket(1);
    if(cmd->part >= 1)
    {
        ring = track_fun_atoi(cmd->pars[1]);
    }
    audio_amplifier((void*)1);
    track_cust_play_amr_ring(ring, 6);

    //GPIO_WriteIO(0, 41);
    sprintf(cmd->rsp_msg, "THE %d'RING.", ring);
}

static kal_uint8 find_flashlight(kal_uint8 i)
{
    static kal_uint8 count = 1;
    if(i == 99)count = 1;
    if(count > 200)return;
    if(i == 1 || count == 1)
    {
        GPIO_WriteIO(1, 47);
        track_start_timer(TRACK_FLASHLIGHT_TIME_ID, 1000, find_flashlight, (void *)0);
    }
    if(i == 0)
    {
        GPIO_WriteIO(0, 47);
        track_start_timer(TRACK_FLASHLIGHT_TIME_ID, 1000, find_flashlight, (void *)1);
    }
    count++;
}
//static kal_uint16  playtimes = 0;
void track_cust_playtime(kal_uint16 c)
{
    playtimes = c;
}
//20191008
static kal_uint8 count_xc = 0;
extern void track_cust_controller_enable(U8 enable);
kal_uint8 track_get_xc_sta(kal_uint8 value)
{
	if(value != 99)
	{
		count_xc = value;
	}
	return count_xc;
}

void track_xc_coner_tim(void)
{
	request_static_packet((void*)99);

    tr_start_timer(TRACK_CUST_XC_CON_TIM, 300, track_xc_coner_tim);	
}
void xc_play(void* time)
{
//	kal_uint8 arg = (kal_uint8)time;

//	if(arg)
//	{
//    	times = 0;
//	}
	
    LOGD(L_APP, L_V5, "times=%d", playtimes);

    //playtimes--;
    if(playtimes != 0)
    {
        playtimes--;
        if((G_realtime_data.defences_status ==1 || G_parameter.ste_status.lease !=1 ) && count_xc == 0)
        {
        	count_xc = 1;
        	//request_static_packet((void *) 88);
        	track_cust_controller_enable(1);
        	//request_static_packet((void*)99);
        	track_xc_coner_tim();
        	LOGD(L_APP, L_V5, "---------------------->>>>>buyaole %d",count_xc);
        }
        track_start_timer(TRACK_CUST_TEST_RING_TIMER_ID, 6000 + 3000, xc_play, (void *)0);
    }
    else
    {	
    	if(count_xc)
    	{
			count_xc = 0;
			//request_static_packet((void *) 77);
			//track_cust_controller_enable(0);
			//request_static_packet((void*)99);
			if(track_is_timer_run(TRACK_CUST_XC_CON_TIM))
			tr_stop_timer(TRACK_CUST_XC_CON_TIM);
			LOGD(L_APP, L_V5, "---------------------->>>>>huifu %d",count_xc);
    	}
        if(G_parameter.ste_status.lease != 1 || G_realtime_data.defences_status == 1)
        {
            track_acc_status((void *)0);//GPIO_WriteIO(0, ELE_LOCK_GPIO);
        }
        if(track_set_audio_file_play(99) == 0)Substantiv_voice_id(0);

        return;
    }

    play_voice(1);

}
void static cmd_xc(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value1 = 0 ;
    if(cmd->part == 0)
    {
        playtimes = 1;//G_parameter.ste_param.xctime / 5;
    }
    if(cmd->part == 1)
    {
        value1 = track_fun_atoi(cmd->pars[1]);
        if(value1 >= 10 && value1 <= 6000)
        {
            playtimes = value1 / 5;
        }
        else
        {
            sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
            return;
        }
    }
    if(cmd->part > 1)
    {
        return;
    }
    if(1)//(G_parameter.ste_status.lease == 0)
    {
    	if(track_set_audio_file_play(99))return;//不寻车
        xc_play((void*)0);
        track_acc_status((void *)2);//GPIO_WriteIO(1, ELE_LOCK_GPIO);

        sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
    }
    else
    {
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
    }
    //find_flashlight(99);
}
void static cmd_xcset(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.xctime);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 10 && value <= 6000)
    {
        G_parameter.ste_param.xctime = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }

    sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}
void static cmd_maxecuspeed(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ele_data.turn_limit);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 1 && value <= 7)
    {
        G_parameter.ele_data.turn_limit = value;
        //if(G_parameter.ste_status.lease == 0)
        //request_static_packet((void*)99);

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                smsStyle = 2;
                sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ele_data.turn_limit);
            }
            else
            {
                sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            }
            return;
        }
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ele_data.turn_limit);
    }
    else
    {
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
    }

}
void static cmd_diameter(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.diameter);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 1 && value <= 40)
    {
        G_parameter.ste_param.diameter = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                smsStyle = 2;
                sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.diameter);
            }
            else
                sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.diameter);
    }
    else
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}

void static cmd_alniconum(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.alnicounum);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 1 && value <= 100)
    {
        G_parameter.ste_param.alnicounum = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                smsStyle = 2;
                sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.alnicounum);
            }
            else
                sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.alnicounum);
    }
    else
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}

void static cmd_lockdomain(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%s", cmd->pars[0], ON_OFF(G_parameter.ste_param.lockdomain));
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value == 1 || value == 0)
    {
        G_parameter.ste_param.lockdomain = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }

    sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}

void static cmd_alarmreq(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.alarmreq);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 1 && value <= 60)
    {
        G_parameter.ste_param.alarmreq = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                smsStyle = 2;
                sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.alarmreq);
            }
            else
                sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.alarmreq);
    }
    else
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}
void static cmd_dftoutpoffiltert(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.power_fails_alarm.delay_time_off);
        //sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.dftoutpoffiltert);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 3 && value <= 10)
    {
        //G_parameter.ste_param.dftoutpoffiltert = value;
        G_parameter.power_fails_alarm.delay_time_off = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                smsStyle = 2;
                sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.power_fails_alarm.delay_time_off);
            }
            else
            {
                sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            }
            return;
        }
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.power_fails_alarm.delay_time_off);
    }
    else
    {
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
    }

}
void static cmd_vibl(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;

    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.viblmg);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 0 && value <= 2000)
    {
        G_parameter.ste_param.viblmg = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                smsStyle = 2;
                sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.viblmg);
            }
            else
            {
                sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            }
            return;
        }
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.viblmg);
    }
    else
    {
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
    }

}
void static cmd_senalm(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%s", cmd->pars[0], ON_OFF(G_parameter.vibrates_alarm.sw));
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    /*
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 0 && value <= 1)
    {
        G_parameter.vibrates_alarm.sw = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }
    */
    if(!strcmp(cmd->pars[1], "ON"))
    {
        G_parameter.vibrates_alarm.sw = 1;
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        G_parameter.vibrates_alarm.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
        return;
    }
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
        return;
    }
    sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}
void static cmd_sentime(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.vibrates_alarm.detection_time);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 1 && value <= 300)
    {
        G_parameter.vibrates_alarm.detection_time = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }

    sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}

void static cmd_senalmset(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.vibrates_alarm.detection_count);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 1 && value <= 20)
    {
        G_parameter.vibrates_alarm.detection_count = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }

    sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}

void static cmd_senspkset(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.senspkset);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 1 && value <= 20)
    {
        G_parameter.ste_param.senspkset = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }

    sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}

void static cmd_sensor(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.vibrates_alarm.alarm_interval / 60);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 1 && value <= 3000)
    {
        G_parameter.vibrates_alarm.alarm_interval = value * 60; //分钟//value * 1000;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }

    sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}
void static cmd_wheelmovtime(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.wheelmovtime);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 0 && value <= 60)
    {
        G_parameter.ste_param.wheelmovtime = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }

    sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}
void static cmd_wheelmov(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.ste_param.wheelmov);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 1 && value <= 50)
    {
        G_parameter.ste_param.wheelmov = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }

    sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}
void static cmd_sv(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%s", cmd->pars[0], ON_OFF(G_parameter.sv.sw));
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 0 && value <= 1)
    {
        G_parameter.sv.sw = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }

    sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}
#if 0
void static cmd_ledsw(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%s", cmd->pars[0], ON_OFF(G_realtime_data.key_status));
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 0 && value <= 1)
    {
        G_realtime_data.key_status = value;

        if(Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE))
        {
            sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }

    sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}

void static cmd_pubkey(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%s", cmd->pars[0], G_parameter.ste_param.publickey);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 0 && value <= 128)
    {
        G_realtime_data.key_status = value;

        if(Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE))
        {
            sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            return;
        }
    }

    sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}
#endif

void static cmd_battemp(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    bat_temp_struct bat = {0};
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s,%s,%d", cmd->pars[0], ON_OFF(G_parameter.bat_temp.sw), G_parameter.bat_temp.interval);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    memcpy(&bat, &G_parameter.bat_temp, sizeof(bat_temp_struct));
    if(!strcmp(cmd->pars[1], "ON"))
    {
        if(cmd->part < 1 || cmd->part > 2)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        bat.sw = 1;
        if(cmd->part == 2)
        {
            bat.interval = track_fun_atoi(cmd->pars[2]);

            if(bat.interval < 1 || bat.interval > 24)
            {
                sprintf(cmd->rsp_msg, "Error: Parameter 2 (1-24)");
                return;
            }
        }
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        if(cmd->part != 1)
        {
            sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
            return;
        }
        bat.sw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Parameter 1 (ON/OFF)");
        return;
    }
    memcpy(&G_parameter.bat_temp, &bat, sizeof(bat_temp_struct));
    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "OK!");
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error!");
    }


}
void static cmd_lease(CMD_DATA_STRUCT *cmd)
{
    int value  = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.ste_status.lease);
        return;
    }
    if(cmd->part == 1)
    {
        value = track_fun_atoi(cmd->pars[1]);
        if(value == 0 || value == 1)
        {
            G_parameter.ste_status.lease = value;
        }
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    }
}
void static cmd_meliage(CMD_DATA_STRUCT *cmd)
{
    int value1  = 0;
    int value2  = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d,%d", cmd->pars[0], G_parameter.ele_data.oncemileage, G_parameter.ele_data.totalmileage);
        return;
    }
    if(cmd->part == 2)
    {
        value1 = track_fun_atoi(cmd->pars[1]);
        value2 = track_fun_atoi(cmd->pars[2]);
        if(1)
        {
            G_parameter.ele_data.oncemileage = value1;
            G_parameter.ele_data.totalmileage = value2;
        }
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    }
}
//--------------记得删除
extern kal_uint8 test_lesea_off_sta_wheel(kal_uint8 value);
//------------------
void static cmd_nftest(CMD_DATA_STRUCT *cmd)
{
    int value  = 0;
    value = track_fun_atoi(cmd->pars[1]);
    if(value == 1)
    {
        //track_mode_lease_on(0);
        track_cust_lease_on_precondition((void*)1);
    }
    else if(value == 0)
    {
        track_mode_lease_off(0);
    }
    else if(value == 2)//撤防
    {
        track_mode_disarm();
    }
    else if(value == 3)//判断文件是否存在
    {
        track_file_test(0);
    }
    else if(value == 4)//判断文件是否存在
    {
        track_file_test(1);
    }
    else if(value == 5)
    {
        test_desired_value(1, 0);
    }
    else if(value == 6)
    {
        test_desired_value(2, 1);
    }
    else if(value == 7)
    {
        test_desired_value(2, 3);
    }
    else if(value == 8)
    {
        test_desired_value(0, 0);
    }
    else if(value == 9 || value == 10 || value ==11)
    {
		test_lesea_off_sta_wheel(value);
    }
}
void static cmd_bmsmsg(CMD_DATA_STRUCT *cmd)
{
    track_cust_N07_paket_03();
}
/*
kal_uint8 ss[10] ={0x86,0x15,0x81,0x63,0x75,0x37,0x5F,0xFF,0xFF,0xFF};
static int BCD_TO_NUM(kal_uint8 *src)//,char* dec)
{
	char tt[15] = {0};
    int i = 0, j = 0;
    kal_uint8 tmp[11];
    kal_uint8 num1 = 0, num2  = 0;
    for(i = 0; i < 10; i++)
    {
        num1 = (src[i] & 0xF0) >> 4;
        num2 = src[i] & 0x0F;
        if(num1 != 0x0F)
        {
        	j += sprintf(tt+j,"%c",(num1 + '0'));
            //tmp[j++] = num1;
        }
		else break;
		if(num2 != 0x0F)
		{
			//tmp[j++] = num2;
			j += sprintf(tt+j,"%c",(num2 + '0'));
		}
		else break;
    }
	sprintf(tt+j, "\0");
	LOGD(L_BMS, L_V5, "%d,%s",j,tt);
	//dec = tmp;
	//sprintf(dec,"%s",tmp);
	return j;
}
static void cmd_dd(CMD_DATA_STRUCT *cmd)
{
	BCD_TO_NUM(ss);

}
*/
static cmd_encodetype(CMD_DATA_STRUCT *cmd)
{
    U8 value  = 0;
    if(cmd->part == 0)
    {
        //extern void test_md5();
        //test_md5();
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.ste_status.encode_type);
        return;
    }

    if(cmd->part == 1)
    {
        value  = track_fun_atoi2(0, cmd->pars[1]);
        if(value == 0 || value == 1)
        {
            G_parameter.ste_status.encode_type = value;
        }
        else
        {
            sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
        }
    }

    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
    }
    else
    {
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
    }
}
#if 0
kal_uint8 srctmp[9] = {0xE6 , 0x88 , 0x91 , 0xE7 , 0x88 , 0xB1 , 0xE4 , 0xBD , 0xA0};
kal_uint8 srctmp1[26] = {0xE6 , 0x88 , 0x91 , 0xE4 , 0xBB , 0xAC , 0xE5 , 0xA4 , 0xA7 , 0xE5 , 0xAE , 0xB6 , 0xE4 , 0xB8 , 0x80 , 0xE8 , 0xB5 , 0xB7 , 0xE6 , 0x9D , 0xA5 , 0x68 , 0x65 , 0x6C , 0x6C , 0x6F};
kal_uint8 message[30] = {0x00 , 0xFF , 0x5A , 0x79 , 0x14 , 0x1B , 0x00 , 0x00 , 0x15 , 0x81 , 0x63 , 0x75 , 0x37 , 0x5F , 0xFF , 0xFF , 0xFF , 0xFF , 0xE6 , 0x88 , 0x91 , 0xE5 , 0x9C , 0xA8 , 0xE6 , 0xB5 , 0x8B , 0xE8 , 0xAF , 0x95};

void cmd_testsms(CMD_DATA_STRUCT *cmd)
{
    U32 len = 0;
    kal_uint8 smstmp[320];
    if(strstr(cmd->pars[1], "1"))
    {
        checkmsg(message, 30);
    }
    else
    {
        len = track_fun_UTF8_to_UCS(srctmp1, 26, smstmp, 320);
        track_cust_sms_send(0, "15816375375", KAL_FALSE, smstmp, len);
    }
}
#endif
static void cmd_wifitest(CMD_DATA_STRUCT *cmd)
{
    track_wifi_information();
}
static void cmd_paging(CMD_DATA_STRUCT *cmd)
{
    //track_cust_paging_command();
    track_instructions_get_paging();
    sprintf(cmd->rsp_msg, "%s OK", cmd->pars[0]);
}
static void cmd_amplifier(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 value  = track_fun_atoi(cmd->pars[1]);
    delaytime = value;
}
static void cmd_advtype(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 value  = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_parameter.ste_status.btadvtype);
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value != 0 && value != 1)
    {
        return;
    }
    G_parameter.ste_status.btadvtype = value;
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    sprintf(cmd->rsp_msg, "%s=OK,%d", cmd->pars[0], G_parameter.ste_status.btadvtype);
}
static void cmd_voicetype(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 value  = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], voice_swtich);
        return;
    }
    value = track_fun_atoi(cmd->pars[1]);
    if(value != 0 && value != 1)
    {
        return;
    }
    voice_swtich = value;
    sprintf(cmd->rsp_msg, "%s=OK,%d", cmd->pars[0], voice_swtich);
}
void cmd_test_time(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value1 = 0;
    kal_uint16 value2 = 0;
    value1 = track_fun_atoi(cmd->pars[1]);
    value2 = track_fun_atoi(cmd->pars[2]);
    if(value1 == 1) //开锁
    {
        GPIO_WriteIO(1, ELE_SWT_ON_GPIO);
        track_start_timer(TRACK_CUST_ELE_SW_TIMER_ID, value2, bt_ele_swon, (void *) 0);

    }
    else
    {
        GPIO_WriteIO(1, ELE_SWT_OFF_GPIO);
        track_start_timer(TRACK_CUST_ELE_SW_TIMER_ID, value2, bt_ele_swoff, (void *) 0);
    }
}
void cmd_disarm(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 value1 = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s:%d", cmd->pars[0], G_realtime_data.defences_status);
        return;
    }
    value1 = track_fun_atoi(cmd->pars[1]);
    if(realtime_disarm_tmp == 1)
    {
        value1 = 1;
        realtime_disarm_tmp = 0;
    }
    if(value1 != 0 && value1 != 1)
    {
        return;
    }
    else
    {
        G_realtime_data.defences_status = value1;
    }
    Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
}
extern void track_cust_test_http(char * filename, kal_uint8 voice_id);
extern track_cust_N07_paket_0E();
//extern void track_test_fat(kal_uint8 arg);
#if 0//调试代码
void cmd_testhttp(CMD_DATA_STRUCT *cmd)
{
#if 1
    char name[50];
    int len = 0;
    kal_uint8 voiceID = 0;
    kal_uint8 value1 = 0;
    //value1 = track_fun_atoi(cmd->pars[1]);
    len = sprintf(name, "%s", cmd->pars[1]);
    voiceID = track_fun_atoi(cmd->pars[2]);
    G_realtime_data.http_server.filestyle = track_fun_atoi(cmd->pars[3]);
    name[len] = '\0';
    track_cust_test_http(name, voiceID);
    //track_cust_N07_paket_0E();
    //track_test_fat(value1);
#endif
}
#endif
#define VOICE_PATCH "Z:\\"
//#define DEL_NAME "AUDIO_FILE"
#define DEL_NAME "AUDIO_FILE1"

void cmd_httpurl(CMD_DATA_STRUCT *cmd)
{
    int dd = 0;
    int result1 = 0;
    int voicesize = 0;
#if 0//调试代码
    kal_uint8 testid1[12] = {0x00, 0x00, 0x03, 0xEA, 0x00, 0x00, 0x03, 0xE9, 0x00, 0x00, 0x03, 0xEB};
    kal_uint8 testid2[12] = {0x00, 0x00, 0x03, 0xE2, 0x00, 0x00, 0x03, 0xE3, 0x00, 0x00, 0x03, 0xE4};
#endif
    if(cmd->part == 0)//"总大小:%d,已下载大小:%d,下载完成:%d,是否更新:%d,文件类型:%d,下载的文件类型 1 固件 2 语音"
    {
        sprintf(cmd->rsp_msg, "TS:%d,HS:%d,Over:%d,Update:%d,Type:%d,CT:%d", \
                G_realtime_data.http_server.file_length, G_realtime_data.http_server.load_length, G_realtime_data.http_server.isdownload, \
                G_realtime_data.http_server.etag, G_realtime_data.http_server.filestyle, G_realtime_data.file_update_style);
        return;
    }
    dd = track_fun_atoi(cmd->pars[1]);
    if(dd == 1)
    {
        G_realtime_data.file_update_style = 0;
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    }
    else if(dd == 2)
    {
        G_realtime_data.file_update_style = 0;
        memset(&G_realtime_data.http_server, 0, sizeof(nvram_http_server_struct));
        memset(&G_realtime_data.voice_version_tmp, 0, 4);
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    }
    else if(dd == 3)
    {
        LOGD(5, 5, "%d,%d,%d,%d", G_parameter.voice_ver[0], G_parameter.voice_ver[1], G_parameter.voice_ver[2], G_parameter.voice_ver[3]);
    }
#if 0//调试代码
    else if(dd == 4)
    {
        memset(&G_realtime_data.voice_list, 0, sizeof(voice_list_struct));
        memcpy(&G_realtime_data.voice_list, testid1, 12);
        G_realtime_data.voice_max = 3;
        AUDIO_file_delete(1);
    }
    else if(dd == 5)
    {
        memset(&G_realtime_data.voice_list, 0, sizeof(voice_list_struct));
        memcpy(&G_realtime_data.voice_list, testid2, 12);
        G_realtime_data.voice_max = 3;
        AUDIO_file_delete(1);
    }
#endif
    else if(dd == 6)
    {
        G_realtime_data.httpdowncount = 0;//次数清零
    }
    /*
    else if(dd == 7)
    	track_factory();*/
    else if(dd == 9)
    {
        char fn[14] = {"TRACK.BIN"};
        static  WCHAR       fat_file_name[40];

        LOGD(5, 5, "删除真正的bin");
        OTA_kal_wsprintf(fat_file_name, "%s", fn);//固件bin文件
        FS_Delete(fat_file_name);
        memset(fat_file_name, 0, 40);
    }
    else if(dd == 8)
    {
        char fn[14] = {"TEMPTRACK.BIN"};
        static  WCHAR       fat_file_name[40];

        LOGD(5, 5, "删除临时的bin");
        OTA_kal_wsprintf(fat_file_name, "%s", fn);//干掉临时的bin文件
        FS_Delete(fat_file_name);
        memset(fat_file_name, 0, 40);
    }
    else if(dd == 10)
    {
        U32 diskspace = 0;
        diskspace = track_fun_FS_GetDiskInfo();
        LOGD(5, 5, "%d", diskspace);
    }
    else if(dd == 11)
    {
        kal_uint8 Ver_Voice[4] = {0x30, 0x00, 0x03, 0xE8}; //语音文件版本

        memset(G_realtime_data.voice_list.void_id, 0, sizeof(voice_id_struct));
        G_realtime_data.voice_max = 100;
        AUDIO_file_delete(0);//认为下载列表为空，清除所有语音
        G_realtime_data.voice_max = 0;
        memcpy(G_parameter.voice_ver, Ver_Voice, 4);
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    }
    else if(dd == 12)
    {
        FS_HANDLE hFile;
        kal_wchar namepattern[32];
        kal_wchar filename[32];
        FS_DOSDirEntry fileinfo;
        kal_uint32 count = 0;
        WCHAR Fileid_Store[30];
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        //删除语音ID存储文件
        OTA_kal_wsprintf(Fileid_Store, "%s", DEL_NAME);
        AUDIO_file_init(2, NULL, 0);
        FS_Delete(Fileid_Store);
        //清楚mp3
        kal_wsprintf(namepattern, "%s*.mp3", VOICE_PATCH);
        hFile = OTA_FS_FindFirst(namepattern, 0, 0x10, &fileinfo, filename, sizeof(filename));

        if(hFile > 0)
        {
            do
            {
                FS_Delete(filename);
            }
            while(OTA_FS_FindNext(hFile, &fileinfo, filename, sizeof(filename)) == 0);
            //FS_FindClose(hFile);
        }
        //清楚amr
        kal_wsprintf(namepattern, "%s*.amr", VOICE_PATCH);
        hFile = OTA_FS_FindFirst(namepattern, 0, 0x10, &fileinfo, filename, sizeof(filename));
        if(hFile > 0)
        {
            do
            {
                FS_Delete(filename);
            }
            while(OTA_FS_FindNext(hFile, &fileinfo, filename, sizeof(filename)) == 0);
            //FS_FindClose(hFile);
        }


        track_cust_restart(77, 5);
    }
    else if(dd == 13)
    {
        WCHAR Fileid_Store[30];
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        //删除语音ID存储文件
        OTA_kal_wsprintf(Fileid_Store, "%s", DEL_NAME);
        AUDIO_file_init(2, NULL, 0);
        result1 = FS_Delete(Fileid_Store);
#if 0
        if(result1 == 0)
        {
            G_parameter.voicefilesize = 0;
            Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
        }
#endif
    }
    else if(dd == 14)
    {
        voicesize = track_fun_atoi(cmd->pars[2]);
        if(voicesize == 0)
        {
            sprintf(cmd->rsp_msg, "OK,%d", G_parameter.voicefilesize);
            return;
        }
        G_parameter.voicefilesize = voicesize;
        Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    }
    sprintf(cmd->rsp_msg, "OK,%d", result1);
#if 0

    else if(dd == 10)//验证下载失败后回滚下载
    {
        G_realtime_data.file_update_style = 1;
        HTTP_abnormal_restart_roll_back();
    }
    else if(dd == 11)
    {
        G_realtime_data.file_update_style = 2;
        HTTP_abnormal_restart_roll_back();
    }
    else if(dd == 12)//验证排序函数
    {
        kal_uint8 testl[28] = {0x00, 0x00 , 0x04 , 0x4F , 0x00, 0x00, 0x04, 0x4C, 0x00, 0x00 , 0x04 , 0x4D , 0x00, 0x00 , 0x04 , 0x4E ,  0x00, 0x00 , 0x04 , 0x50 , 0x00, 0x00 , 0x04 , 0x51 , 0x00, 0x00 , 0x04 , 0x52};

        kal_uint8 test2[28] = {0x01, 0x00, 0x04, 0x4C, 0x01, 0x00 , 0x04 , 0x4D ,  0x01, 0x00 , 0x04 , 0x4F , 0x01, 0x00 , 0x04 , 0x50 , 0x01, 0x00 , 0x04 , 0x51 , 0x01, 0x00 , 0x04 , 0x4E , 0x01, 0x00 , 0x04 , 0x52};
        voice_list_struct ls = {0};
        memcpy(&ls.void_id, testl, 28);
        track_cust_voice_list_sort(ls, 7);
        memcpy(&ls.void_id, test2, 28);
        track_cust_voice_list_sort(ls, 7);
    }
#endif
}

void cmd_allparam(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 vinh = cData.totalValtage[0];
    kal_uint8 vinl = cData.totalValtage[1];
    kal_uint16 vin = 0;
    charge_measure_struct charge_measure = {0};
    kal_int32 vbat = 0, ichr = 0, vchr = 0;
    int n, g, i, j, x;// signal = 0;
    char tmp[1000] = {0}, PRN[80] = {0};
    kal_bool head = 1;
    kal_uint8 len = 0;
    kal_int8 ret;
    char versionchr[50];
    char *ver;
    char *build;
    int g_tmp = 0;
    kal_uint8 sta[2] = {0};


    ver = track_get_app_version();
    build = track_get_app_version_datetime();
    if(strlen(ver) <= 0)
    {
        ver = (char*)release_verno();
        build = build_date_time();
    }
    n = snprintf(tmp, 999, "VERSION:%s;BUILD:%s;",
                 ver,
                 build);
    /*
    g_tmp = track_cust_get_rssi(-1);
    if(g_tmp > 27) g_tmp = 9;
    else
    {
        g_tmp = g_tmp / 3;
    }*/
    g_tmp = track_cust_get_rssi_level();
    n += sprintf(tmp + n, "GSM=%d;", g_tmp);
    track_bmt_get_ADC_result(&charge_measure);
    vbat = charge_measure.bmt_vBat * 1000000;
    ichr = charge_measure.bmt_iChr * 1000000;
    vchr = charge_measure.bmt_vChr * 1000000;
    n += sprintf(tmp + n, "VBAT=%d:%d:%d;", vbat, vchr, ichr);

    if(track_cust_status_charger() != 0)
    {
        if(cData.totalValtage[0] == 0 && cData.totalValtage[1] == 0)
        {
            //exVBAT = track_cust_get_ext_volt();
            vin = (float)track_cust_get_ext_volt() / 1000.0;
            LOGD(L_BMS, L_V5, "电池电压3:%d", vin);
        }
        else
        {
            vin = (vinh & 0x00FF) << 8;
            vin = vin | (vinl & 0x00FF);
        }
    }
    else
    {
        vin = 0;
    }

    n += sprintf(tmp + n, "VIN=%d;", vin);
    n += sprintf(tmp + n, "DEVICESN=%s;", G_importance_parameter_data.SequenceNumber);
    track_cust_vehicle_status(sta);
    n += sprintf(tmp + n, "DEVICESTATUS=%02X%02X;", sta[0], sta[1]);

    n += sprintf(tmp + n, "BATVER=%02X;", cData.versionNum[1]);

    n += sprintf(tmp + n, "BATMANUFACTURE=%s;", cData.valtageManufacturer);

    n += sprintf(tmp + n, "BATSN=%s;", cData.barCode);

    n += sprintf(tmp + n, "VIBL=%d;", G_parameter.ste_param.viblmg);

    n += sprintf(tmp + n, "FREQ=%d;", G_parameter.gps_work.Fti.interval_acc_on);

    n += sprintf(tmp + n, "PULSE=%d;", G_parameter.hbt_acc_on);
    if(G_importance_parameter_data.server.conecttype == 1)
    {
        n += sprintf(tmp + n, "DOMAIN=%s:%d;", track_domain_decode(G_importance_parameter_data.server.url), G_importance_parameter_data.server.server_port);
    }
    else if(G_importance_parameter_data.server.conecttype == 0)
    {
        n += sprintf(tmp + n, "DOMAIN=%d.%d.%d.%d:%d;",
                     G_importance_parameter_data.server.server_ip[0],
                     G_importance_parameter_data.server.server_ip[1],
                     G_importance_parameter_data.server.server_ip[2],
                     G_importance_parameter_data.server.server_ip[3],
                     G_importance_parameter_data.server.server_port);
    }

    n += sprintf(tmp + n, "BLEKG=%d;", G_parameter.ste_param.btsw);

    n += sprintf(tmp + n, "SLEEPT=%d;", G_parameter.ste_param.sleept);

    n += sprintf(tmp + n, "MAXECUSPEED=%d;",  G_parameter.ele_data.turn_limit);

    n += sprintf(tmp + n, "DFTOUTPOFFILTERT=%d;", G_parameter.power_fails_alarm.delay_time_off);

    n += sprintf(tmp + n, "DFTLOCKVOICEPLAYT=%d;", G_parameter.ste_param.dftlockvoiceplayt);

    n += sprintf(tmp + n, "DIAMETER=%d;", G_parameter.ste_param.diameter);

    n += sprintf(tmp + n, "ALNICONUM=%d;", G_parameter.ste_param.alnicounum);

    n += sprintf(tmp + n, "DFTTIMEOUT=%d;", G_parameter.ste_param.dfttimeout);

    n += sprintf(tmp + n, "BTNAME=%s;", G_parameter.ste_param.bt_name);

    //LOGS("%s",tmp);
    track_cust_N07_paket_87(tmp, n);
}
void cmd_testsds(CMD_DATA_STRUCT *cmd)
{
    extern void test_sds();
    test_sds();
}
void cmd_avb(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 dd = 0, dd1, dd2;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%02X,%02X,%02X", cmd->pars[0], G_parameter.voice_ver[1], G_parameter.voice_ver[2], G_parameter.voice_ver[3]);
        return;
    }
    dd = track_fun_atoi(cmd->pars[1]);
    dd1 = track_fun_atoi(cmd->pars[2]);
    dd2 = track_fun_atoi(cmd->pars[3]);
    LOGD(5, 5, "version:%d,%d,%d", dd, dd1, dd2);
    LOGD(5, 5, "version:%02X,%02X,%02X", dd, dd1, dd2);
    G_parameter.voice_ver[1] = dd;
    G_parameter.voice_ver[2] = dd1;
    G_parameter.voice_ver[3] = dd2;
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);

}
void cmd_exset(CMD_DATA_STRUCT *cmd)
{
    int exeCode = 0;
    /*
    if(cmd->part == 3)
    {
    	memset(msg_str, 0, sizeof(CMD_DATA_STRUCT));
    	memcpy(msg_str, cmd, sizeof(CMD_DATA_STRUCT));
    	exeCode = track_fun_atoi(cmd->pars[2]);
    	if(exeCode != 0)
    	{
    		isSmsCode = 1;
    		track_cust_N07_paket_06(NULL, 0, 0, exeCode);
    	}
    }
    LOGD(5, 5, "%s:%s:%s:%s", cmd->pars[0],cmd->pars[1],cmd->pars[2],cmd->pars[3]);
    */
}
#if 1
void static cmd_osdswitch(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.osd.osdswitch);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }

    value = track_fun_atoi(cmd->pars[1]);
    if(value == 0 || value == 1)
    {
        if(G_parameter.osd.osdswitch == 1 && value == 0)
        {
            track_cust_module_speed_limit_cmd_update();
        }
        G_parameter.osd.osdswitch = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                smsStyle = 2;
                sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.osd.osdswitch);
            }
            else
            {
                sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            }
            return;
        }
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.osd.osdswitch);
    }
    else
    {
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
    }
}
void static cmd_osdspeed(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.osd.osdspeed);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }

    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 0 && value <= 60)
    {
        G_parameter.osd.osdspeed = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                smsStyle = 2;
                sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.osd.osdspeed);
            }
            else
            {
                sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            }
            return;
        }
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.osd.osdspeed);
    }
    else
    {
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
    }
}
void static cmd_osdtimeinterval(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.osd.osdtimeinterval);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }

    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 0 && value <= 60)
    {
        G_parameter.osd.osdtimeinterval = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                smsStyle = 2;
                sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.osd.osdtimeinterval);
            }
            else
            {
                sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            }
            return;
        }
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.osd.osdtimeinterval);
    }
    else
    {
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
    }
}
void static cmd_osdtimemax(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.osd.osdtimemax);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }

    value = track_fun_atoi(cmd->pars[1]);
    if(value >= 0 && value <= 1800)
    {
        G_parameter.osd.osdtimemax = value;

        if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
        {
            if(cmd->return_sms.cm_type == CM_SMS)
            {
                smsStyle = 2;
                sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.osd.osdtimemax);
            }
            else
            {
                sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
            }
            return;
        }
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.osd.osdtimemax);
    }
    else
    {
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
    }
}
void static cmd_osdring(CMD_DATA_STRUCT *cmd)
{
    kal_uint32 value1 = 0 , value2 = 0;
    kal_uint32 ringID = 0;
    kal_uint8 ringIDHEX[3];
    kal_uint32 voiceID = 0;
    kal_uint8 voiceIDHEX[3];
    char *p = NULL;
    int strLen = 0;
    if(cmd->part == 0)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            smsStyle = 1;
        }
        memcpy(ringIDHEX, &G_parameter.osd.osdringid, 3);
        memcpy(voiceIDHEX, &G_parameter.osd.osdvoiceid, 3);
        ringID = (ringIDHEX[0] << 16) | (ringIDHEX[1] << 8) | ringIDHEX[2];
        voiceID = (voiceIDHEX[0] << 16) | (voiceIDHEX[1] << 8) | voiceIDHEX[2];
        //sprintf(cmd->rsp_msg, "%s=%d:%d", cmd->pars[0],voiceID, ringID);
        sprintf(cmd->rsp_msg, "%s=0x%02X%02X%02X:0x%02X%02X%02X", cmd->pars[0], G_parameter.osd.osdvoiceid[0], G_parameter.osd.osdvoiceid[1], G_parameter.osd.osdvoiceid[2], \
                G_parameter.osd.osdringid[0], G_parameter.osd.osdringid[1], G_parameter.osd.osdringid[2]);
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    strLen = strlen(cmd->pars[1]);
    p = strchr(cmd->pars[1], ':');
    if(p != NULL)
    {
        *p = '\0';
        value1 = track_fun_atoi(cmd->pars[1]);
        value2 = track_fun_atoi(p + 1);
        LOGD(L_APP, L_V5, "%d,%d", value1, value2);

        if(value1 >= 0 && value1 <= 16777215 && value2 >= 0 && value2 <= 16777215)
        {
            voiceIDHEX[0] = (value1 & 0xFF0000) >> 16;
            voiceIDHEX[1] = (value1 & 0xFF00) >> 8;
            voiceIDHEX[2] = value1 & 0xFF;
            ringIDHEX[0] = (value2 & 0xFF0000) >> 16;
            ringIDHEX[1] = (value2 & 0xFF00) >> 8;
            ringIDHEX[2] = value2 & 0xFF;
            memcpy(&G_parameter.osd.osdvoiceid, voiceIDHEX, 3);
            memcpy(&G_parameter.osd.osdringid, ringIDHEX, 3);
            if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
            {
                if(cmd->return_sms.cm_type == CM_SMS)
                {
                    smsStyle = 2;
                    sprintf(cmd->rsp_msg, "%s=0x%02X%02X%02X:0x%02X%02X%02X", cmd->pars[0], G_parameter.osd.osdvoiceid[0], G_parameter.osd.osdvoiceid[1], G_parameter.osd.osdvoiceid[2], G_parameter.osd.osdringid[0], G_parameter.osd.osdringid[1], G_parameter.osd.osdringid[2]);
                }
                else
                {
                    sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
                }
                return;
            }
        }
    }
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 3;
        sprintf(cmd->rsp_msg, "%s=0x%02X%02X%02X:0x%02X%02X%02X", cmd->pars[0], G_parameter.osd.osdvoiceid[0], G_parameter.osd.osdvoiceid[1], G_parameter.osd.osdvoiceid[2], G_parameter.osd.osdringid[0], G_parameter.osd.osdringid[1], G_parameter.osd.osdringid[2]);
    }
    else
    {
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
    }
}
static void cmd_rtinfo(CMD_DATA_STRUCT *cmd)
{
    track_cust_N07_realtime_info();
}
static void cmd_bwtopen(CMD_DATA_STRUCT *cmd)//后轮锁开锁
{
    kal_uint16 topen = 0;
    if(cmd->part == 0)
    {
        topen = G_parameter.bwtopen * 100;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], topen);
        return;
    }
    if(cmd->part == 1)
    {
        topen = track_fun_atoi2(0, cmd->pars[1]);
        if(topen >= 1800 && topen <= 3000)
        {
            G_parameter.bwtopen = (topen / 100);
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (1800-3000)");
            return;
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);

    sprintf(cmd->rsp_msg, "OK!");
}
static void cmd_bwtclose(CMD_DATA_STRUCT *cmd)//后轮锁关锁
{
    kal_uint16 tclose = 0;
    if(cmd->part == 0)
    {
        tclose = G_parameter.bwtclose * 100;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], tclose);
        return;
    }
    if(cmd->part == 1)
    {
        tclose = track_fun_atoi2(0, cmd->pars[1]);
        if(tclose >= 1800 && tclose <= 3000)
        {
            G_parameter.bwtclose = (tclose / 100);
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (1800-3000)");
            return;
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);

    sprintf(cmd->rsp_msg, "OK!");
}
static void cmd_eletopen(CMD_DATA_STRUCT *cmd)//电池锁开锁
{
    kal_uint16 topen = 0;
    if(cmd->part == 0)
    {
        topen = G_parameter.eletopen * 100;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], topen);
        return;
    }
    if(cmd->part == 1)
    {
        topen = track_fun_atoi2(0, cmd->pars[1]);
        if(topen >= 1800 && topen <= 3000)
        {
            G_parameter.eletopen = (topen / 100);
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (1800-3000)");
            return;
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);

    sprintf(cmd->rsp_msg, "OK!");
}
static void cmd_eletclose(CMD_DATA_STRUCT *cmd)//电池锁关锁
{
    kal_uint16 tclose = 0;
    if(cmd->part == 0)
    {
        tclose = G_parameter.eletclose * 100;
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], tclose);
        return;
    }
    if(cmd->part == 1)
    {
        tclose = track_fun_atoi2(0, cmd->pars[1]);
        if(tclose >= 1800 && tclose <= 3000)
        {
            G_parameter.eletclose = (tclose / 100);
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error: Parameter 1 (1800-3000)");
            return;
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error: Number of parameters error!");
        return;
    }

    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);

    sprintf(cmd->rsp_msg, "OK!");
}
static void cmd_bmsoc(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 value = 0 ;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.BMSOC);
        return;
    }
    if(cmd->part > 2)
    {
        sprintf(cmd->rsp_msg, "Error! Number of Parameters Error!");
        return;
    }

    value = track_fun_atoi2(0, cmd->pars[1]);
    if(value == 0 || value == 1)
    {
        G_parameter.BMSOC = value;
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error! Parameter1 (0/1)");
        return;
    }

    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    sprintf(cmd->rsp_msg, "OK!");

}
static void cmd_rreason(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 resetReason = 0;
    resetReason = track_fun_atoi2(0, cmd->pars[1]);
    if(resetReason == 1)
    {
        G_realtime_data.fota_update = 1;
        Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
    }
}
static void cmd_MP3T(CMD_DATA_STRUCT *cmd)
{
    kal_uint8 mps[6] = 0;
    kal_uint8 mpstmp[3] = 0;
    track_fun_ASCII_to_HEX(cmd->pars[1], mps, 6);
    LOGH(L_APP, L_V1, mps, 6);
    mpstmp[0] = mps[0] << 4 & mps[1];
    mpstmp[1] = mps[2] << 4 & mps[3];
    mpstmp[2] = mps[4] << 4 & mps[5];

    LOGH(L_APP, L_V1, mpstmp, 3);
    AUDIO_file_play(mps);
}
static void cmd_test_nf(CMD_DATA_STRUCT *cmd)
{
    U8 value1 = 0;
    if(cmd->part == 0) return;
    value1 = track_fun_atoi2(0, cmd->pars[1]);
    if(value1 == 1)
    {
        LOGD(L_APP, L_V1, "EINT_A_GPIO:%d,ELE_LOCK_GPIO:%d", GPIO_ReadIO(EINT_A_GPIO), GPIO_ReadIO(ELE_LOCK_GPIO));
    }
    else if(value1 == 2)
    {
        track_cust_acc_status_confirm();
    }
}
static void cmd_hardversion(CMD_DATA_STRUCT *cmd)
{
    //char *hw = NULL;
    U8 hw[3] = {0};
    //extern char *track_get_hardversion();
    extern void track_get_hardversionHex(kal_uint8 * src);
    if(cmd->part != 0)
    {
        sprintf(cmd->rsp_msg, "Error! Number of Parameters Error!");
        return;
    }
    //hw = track_get_hardversion();
    track_get_hardversionHex(hw);
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 1;
    }
    sprintf(cmd->rsp_msg, "HARDVERSION=%02X%02X%02X", hw[0], hw[1], hw[2]);

    //sprintf(cmd->rsp_msg, "HARDVERSION=%s", hw);

}
static void cmd_voiceversion(CMD_DATA_STRUCT *cmd)
{
    kal_uint32 vs = 0;
    if(cmd->part != 0)
    {
        sprintf(cmd->rsp_msg, "Error! Number of Parameters Error!");
        return;
    }
    //vs = G_parameter.voice_ver[3];
    //vs |= (G_parameter.voice_ver[2] & 0x00FF) << 8;
    //vs |= (G_parameter.voice_ver[1] & 0x0000FF) << 16;

    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 1;
    }

    //sprintf(cmd->rsp_msg, "VOICEVERSION=%d", vs);
    sprintf(cmd->rsp_msg, "VOICEVERSION=%02X%02X%02X", G_parameter.voice_ver[1], G_parameter.voice_ver[2], G_parameter.voice_ver[3]);

}

#endif
static void cmd_viblvoicesw(CMD_DATA_STRUCT *cmd)
{
    kal_uint16 value = 0 ;
    kal_uint8 tmp_sw = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%s", cmd->pars[0], ON_OFF(G_parameter.viblvoicesw));
        return;
    }
    if(cmd->part > 2)
    {
        return;
    }
    tmp_sw = G_parameter.viblvoicesw;
    if(!strcmp(cmd->pars[1], "ON"))
    {
        G_parameter.viblvoicesw = 1;
    }
    else if(!strcmp(cmd->pars[1], "OFF"))
    {
        G_parameter.viblvoicesw = 0;
    }
    else
    {
        sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);
        return;
    }

    if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
    {
        if(G_parameter.viblvoicesw == 1 && tmp_sw != G_parameter.viblvoicesw)
        {
            track_cust_vibrates_voice_alarm((void*)2);
        }
        sprintf(cmd->rsp_msg, "%s=OK", cmd->pars[0]);
        return;
    }
    sprintf(cmd->rsp_msg, "%s=FAIL", cmd->pars[0]);

}
static void cmd_voiceleftspace(CMD_DATA_STRUCT *cmd)
{
    kal_uint32 disksize = 0;
    U32 FATDiskSpace = 0;
    if(cmd->part != 0)
    {
        sprintf(cmd->rsp_msg, "Error! Number of Parameters Error!");
        return;
    }
    disksize = 4 * 1024 * 1024;
    FATDiskSpace = track_fun_FS_GetDiskInfo();//总共要留500K给动态使用，固件+备份+realtime+audio+md5 400+80+2K+5K
    //800*1024  = 819200  byte
#if 0
    if((FATDiskSpace + G_parameter.voicefilesize) < disksize)
    {
        disksize = (FATDiskSpace + G_parameter.voicefilesize);
    }
#endif
    if(cmd->return_sms.cm_type == CM_SMS)
    {
        smsStyle = 1;
    }
    if(FATDiskSpace <= 819200)
    {
        sprintf(cmd->rsp_msg, "VOICELEFTSPACE=0");
    }
    else
    {
        disksize = FATDiskSpace - 819200;
        sprintf(cmd->rsp_msg, "VOICELEFTSPACE=%d", disksize);
    }
#if 0
    else if(disksize >= G_parameter.voicefilesize)
    {
        disksize -= G_parameter.voicefilesize;
        sprintf(cmd->rsp_msg, "VOICELEFTSPACE=%d", disksize);
    }
    else
        sprintf(cmd->rsp_msg, "VOICELEFTSPACE=0");
#endif
}
#if 0
static void cmd_voicesize(CMD_DATA_STRUCT *cmd)
{
    kal_uint32 value1 = 0;
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=%d", cmd->pars[0], G_parameter.voicefilesize);
        return;
    }
    if(cmd->part == 1)
    {
        value1 = track_fun_atoi2(0, cmd->pars[1]);
        if(value1 > 0 && value1 <= VOICE_FILES_SIZE)
        {
            G_parameter.voicefilesize = value1;
        }
        else
        {
            sprintf(cmd->rsp_msg, "Error111");
            return;
        }
    }
    else
    {
        sprintf(cmd->rsp_msg, "Error222");
        return;
    }
    Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE);
    sprintf(cmd->rsp_msg, "OK!");
}
#endif
static void cmd_normalinfo(CMD_DATA_STRUCT *cmd)
{
    if(cmd->part == 0)
    {
        sprintf(cmd->rsp_msg, "%s=1", cmd->pars[0]);
        return;
    }
    if(cmd->part == 1)
    {
        sprintf(cmd->rsp_msg, "NORMALINFO=OK");
    }
}
//20190723 单纯的查询 没有鸡巴卵用

extern void track_cust_bms_status_alarm(kal_uint8 s_type);
extern void track_cust_controller_malfunction_alarm(kal_uint8 s_type);
extern void bett_sn_20to16(kal_uint8*data16,kal_uint8*data20);
void cmd_bms_con_test(CMD_DATA_STRUCT *cmd)
{

	kal_uint8 value1=0;
	if(cmd->part == 0)
	{
		return;
	}
	else if(cmd->part >= 1)
	{
		value1 = track_fun_atoi( cmd->pars[1]);
 		if(value1 != 99)
 		{
 			if(value1 >= 50)
 			{
 			 	value1 -= 50;
 			 	track_cust_bms_status_alarm(value1);
 			 }
 			 else
 			{
 				track_cust_controller_malfunction_alarm(value1);
 			 }
 		}
 	}
	else
	{
		sprintf(cmd->rsp_msg, "err");
	}
}

void bt_pass_world_save(CMD_DATA_STRUCT *cmd)
{
	if(cmd->part == 0)
	{
		sprintf(cmd->rsp_msg, "btpass:%s",G_parameter.encode_token_s);
	}
	else if(cmd->part == 1)
	{
		
		memcpy(G_parameter.encode_token_s,cmd->pars[1],50);
		if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
		{
			sprintf(cmd->rsp_msg, "btpass is ok");
		}
	}
	else
	{
		sprintf(cmd->rsp_msg, "err");
	}
}
void new_bt_pass_world_save(CMD_DATA_STRUCT *cmd)
{
	if(cmd->part == 0)
	{
		sprintf(cmd->rsp_msg, "newbtpass:%s",G_parameter.new_encode_token_s);
	}
	else if(cmd->part == 1)
	{
		
		memcpy(G_parameter.new_encode_token_s,cmd->pars[1],50);
		if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
		{
			sprintf(cmd->rsp_msg, "newbtpass is ok");
		}
	}
	else
	{
		sprintf(cmd->rsp_msg, "err");
	}	
}
void new_bt_pass_world_sta(CMD_DATA_STRUCT *cmd)
{
	kal_uint8 value = 0;
	if(cmd->part == 0)
	{
		sprintf(cmd->rsp_msg, "newbtpass_sta:%d",G_parameter.bt_token_mark);
	}
	else if(cmd->part == 1)
	{
		
		value = track_fun_atoi(cmd->pars[1]);
		G_parameter.bt_token_mark = value;
		if(Track_nvram_write(NVRAM_EF_PARAMETER_LID, 1, (void *)&G_parameter, NVRAM_EF_PARAMETER_SIZE))
		{
			sprintf(cmd->rsp_msg, "newbtpass_sta is ok");
		}
	}
	else
	{
		sprintf(cmd->rsp_msg, "err");
	}	
}
//-----------------------记录关锁失败成功的标志以及是否播放关锁语音标志 20191010
void cmd_set_lesae_off_volume_sta(CMD_DATA_STRUCT *cmd)
{
	if(cmd->part == 0)
	{
		sprintf(cmd->rsp_msg,"%s:lesea_off_sta:%d lesea_volume_sta:%d",cmd->pars[0],G_realtime_data.lesea_off_to_sta,G_realtime_data.lesea_off_to_volume_sta);
	}
	else if(cmd->part == 2)
	{
		G_realtime_data.lesea_off_to_sta = track_fun_atoi(cmd->pars[1]);
		G_realtime_data.lesea_off_to_volume_sta = track_fun_atoi(cmd->pars[2]);
		Track_nvram_write(NVRAM_EF_REALTIME_LID, 1, (void *)&G_realtime_data, NVRAM_EF_REALTIME_SIZE);
	}
	else
	{
		sprintf(cmd->rsp_msg, "err");
	}
	
}
//TRUE  表示使用项目自定义的功能，覆盖标准版
//FALSE 表示不支持该指令，同时标准版的也不会执行
static track_project_cmd_table_struct track_project_cmd_table[] =
{
    {"WF", NULL,   FALSE},
    //{"VOLUME", cmd_set_volume,   TRUE},
    {"TEST_RING", cmd_test_ting,   TRUE},
    {"TEST_RING1", cmd_test_ting1,   TRUE},

    {"EXBATLOCKON", cmd_exbatlockon,   TRUE},
    {"EXBATLOCKOFF", cmd_exbatlockoff,   TRUE},
    {"REARWHEELON", cmd_rearwheelon,   TRUE},
    {"REARWHEELOFF", cmd_rearwheeloff,   TRUE},
//#if defined(__NF2318__)
    {"CONCMD", data_reques,   TRUE},
//#endif
    {"ACCTEST", cmd_test_acc,   TRUE},
    {"JMTEST", cmd_N07jiami,   TRUE},
    {"BTPTEST", cmd_bt_test,   TRUE},
    {"ATTEST", cmd_at,   TRUE},
    {"BMSTEST", cmd_uart1test,	 TRUE},
    {"DEVICESN", cmd_devicesn,	 TRUE},
    {"SOFTVERSION", cmd_softversion,	 TRUE},
    {"GSM", cmd_gsm,	 TRUE},
    {"VBAT", cmd_bat,	 TRUE},
    {"VIN", cmd_vin,	 TRUE},
    {"BATVER", cmd_batver,	 TRUE},
    {"BATMANUFACTURE", cmd_BATMANUFACTURE,	 TRUE},
    {"BATSN", cmd_BATSN,	 TRUE},
    {"DEVICESTATUS", cmd_DEVICESTATUS,	 TRUE},
    {"BMSSTATUS", cmd_BMSSTATUS,	 TRUE},

//设置
    {"DOMAIN", cmd_domain,	 TRUE},
    {"DFTTIMEOUT", cmd_dfttimeout,	 TRUE},
    {"DFTLOCKVOICEPLAYT", cmd_dftlockvoiceplayt,	TRUE},

    {"FREQ", cmd_freq,	TRUE},
    {"DORMANTFREQ", cmd_dormantfreq,	TRUE},
    {"PULSE", cmd_pulse,	TRUE},
    {"SLEEPT", cmd_sleept,	TRUE},
    {"PWRSAVE", cmd_pwrsave,	TRUE},
    {"VOLUME", cmd_volume,	TRUE},
    {"BLEKG", cmd_blekg,	TRUE},
    {"BTMAC", cmd_btmac,	TRUE},
    {"BTNAME", cmd_btname,	TRUE},
    {"BTRESET", cmd_btreset,	TRUE},
    {"XC", cmd_xc,	TRUE},
    {"XCSET", cmd_xcset,	TRUE},
    {"MAXECUSPEED", cmd_maxecuspeed,	TRUE},
    {"DIAMETER", cmd_diameter,	TRUE},

    {"ALNICONUM", cmd_alniconum,	TRUE},
    {"LOCKDOMAIN", cmd_lockdomain,	TRUE},
    {"ALARMFREQ", cmd_alarmreq,	TRUE},
    {"DFTOUTPOFFILTERT", cmd_dftoutpoffiltert,	TRUE},
    {"VIBL", cmd_vibl,	TRUE},
    {"SENALM", cmd_senalm,	TRUE},
    {"SENTIME", cmd_sentime,	TRUE},
    {"SENALMSET", cmd_senalmset,	TRUE},

    {"SENSPKSET", cmd_senspkset,	TRUE},

    {"SENSOR", cmd_sensor,	TRUE},
    {"WHEELMOVTIME", cmd_wheelmovtime,	TRUE},
    {"WHEELMOV", cmd_wheelmov,	TRUE},
    {"SV", cmd_sv,	TRUE},
    //{"LEDSW", cmd_ledsw,	TRUE},
    //{"PUBKEY", cmd_pubkey,	TRUE},

    {"BATTEMP", cmd_battemp,	TRUE},
    {"LEASE", cmd_lease,	TRUE},
    {"MELIAGE", cmd_meliage,	TRUE},

    {"NFTEST", cmd_nftest,	TRUE},

    {"BMSMSG", cmd_bmsmsg,	TRUE},
    //{"DD", cmd_dd,	TRUE},
    {"ENCODETYPE", cmd_encodetype,	TRUE},
    //{"UTFTEST", cmd_testsms,	TRUE},
    {"WIFITEST", cmd_wifitest,	TRUE},

    {"PAGING", cmd_paging,	TRUE},//上传定位包

    {"AMPL", cmd_amplifier,	TRUE},//调试功放

    {"ADVTYPE", cmd_advtype,	TRUE},//广播方式
    {"VOICETYPE", cmd_voicetype,	TRUE},//关闭语音播放

    {"TESTIME", cmd_test_time,	TRUE},
    {"DISARM", cmd_disarm,	TRUE},
    //{"HTTPTEST", cmd_testhttp,	TRUE},////调试代码
    {"HTTPURL", cmd_httpurl,	TRUE},
    {"ALL", cmd_allparam,	TRUE},
    {"TESTSDS", cmd_testsds,	TRUE},
    {"AVB", cmd_avb,	TRUE},
    {"$EXSET", cmd_exset,	TRUE},
#if 1
    {"OSDSWITCH", cmd_osdswitch,	TRUE},
    {"OSDSPEED", cmd_osdspeed,	TRUE},
    {"OSDTIMEINTERVAL", cmd_osdtimeinterval,	TRUE},
    {"OSDTIMEMAX", cmd_osdtimemax, TRUE},
    {"OSDRING", cmd_osdring, TRUE},
#endif
    {"RTINFO", cmd_rtinfo, TRUE},

    {"BWOT", cmd_bwtopen, TRUE},
    {"BWCT", cmd_bwtclose, TRUE},
    {"ELEOT", cmd_eletopen, TRUE},
    {"ELECT", cmd_eletclose, TRUE},
    {"BMSOC", cmd_bmsoc, TRUE},
    {"RREASON", cmd_rreason, TRUE},
    {"MP3T", cmd_MP3T, TRUE},
    {"TEST_NF", cmd_test_nf, TRUE},
    {"HARDVERSION", cmd_hardversion, TRUE},
    {"VOICEVERSION", cmd_voiceversion, TRUE},
    {"LIGHT", cmd_light, TRUE},//201904
    {"VIBLVOICESW", cmd_viblvoicesw, TRUE},//20190711

    {"VOICELEFTSPACE", cmd_voiceleftspace, TRUE},//20190711
    //{"VOICESIZE", cmd_voicesize, TRUE},//20190711
    {"NORMALINFO", cmd_normalinfo, TRUE},//20190801
    {"ALMTEST",     cmd_bms_con_test ,       TRUE},//20190723
    {"BTPASSWD",    bt_pass_world_save , TRUE},
    {"NEWBTPSWD",    new_bt_pass_world_save , TRUE},
    {"NEWBTPSTA",    new_bt_pass_world_sta , TRUE},
    //----------------20191010
    {"LESOFF",     cmd_set_lesae_off_volume_sta , TRUE},

};


kal_bool track_project_command(CMD_DATA_STRUCT * cmd)
{
    int len = 0;
    int i, size, ret;
    kal_bool find = KAL_FALSE, pass_status = KAL_FALSE;
    size = sizeof(track_project_cmd_table) / sizeof(track_project_cmd_table_struct);

    LOGD(L_APP, L_V5, "num_type:%d, len:%d, data:%s   [%d/%d]%s|%s|%s|%s|%s",
         cmd->return_sms.num_type, cmd->rcv_length, cmd->rcv_msg_source, cmd->part, size, cmd->pars[0], cmd->pars[1], cmd->pars[2], cmd->pars[3], cmd->pars[4]);

    if(cmd->rcv_length >= 1024)
    {
        return KAL_TRUE;
    }

    for(i = 0; i < size; i++)
    {
        ret = strcmp(cmd->pars[0], track_project_cmd_table[i].cmd_string);
        LOGD(L_APP, L_V9, "ret=%d|%s,%s|%p", ret, cmd->pars[0], track_project_cmd_table[i].cmd_string, track_project_cmd_table[i].cmd_string);
        if(!ret)
        {
            find = KAL_TRUE;
            cmd->rsp_length = 0;
            memset(cmd->rsp_msg, 0, sizeof(cmd->rsp_msg));
            track_is_sms_cmd(1);

            if(!track_project_cmd_table[i].valid)
            {
                LOGD(L_APP, L_V5, "this project disable %s", cmd->pars[0]);
                return KAL_TRUE;
            }

            pass_status = track_cmd_check_authentication(cmd);
            if(cmd->supercmd == 1 || cmd->return_sms.cm_type != CM_SMS || pass_status)
            {
                if(track_project_cmd_table[i].func_ptr != NULL)
                {
                    track_is_recv_cmd_after_boot(1);
                    track_project_cmd_table[i].func_ptr(cmd);
                    break;
                }
            }
            else
            {
                LOGD(L_APP, L_V4, "Password error!");
                sprintf(cmd->rsp_msg, "Password error!");      //密码错误
            }
            break;
        }
    }
    if(find)
    {
        if(cmd->return_sms.cm_type == CM_SMS)
        {
            //len = cmd->rsp_length;//strlen(cmd->rsp_msg);//

            len = track_fun_asc_str_to_ucs2_str(&rsp_msg, cmd->rsp_msg) - 2;
            memset(cmd->rsp_msg, 0, CM_PARAM_LONG_LEN_MAX);
            if(smsStyle == 1)
            {
                memcpy(cmd->rsp_msg, cxok, 10);
                memcpy(&cmd->rsp_msg[10], rsp_msg, len);
            }
            else if(smsStyle == 2)
            {
                memcpy(cmd->rsp_msg, rsp_msg, len);
                memcpy(&cmd->rsp_msg[len], setok, 10);
            }
            else if(smsStyle == 3)
            {
                memcpy(cmd->rsp_msg, rsp_msg, len);
                memcpy(&cmd->rsp_msg[len], setfail, 10);
            }
            cmd->rsp_length = len + 10;

            cmd->return_sms.reply_character_encode = 1;
        }
        //else
        {
            /*  指令解析执行体只填充信息，全部在此发出*/
            track_cust_cmd_reply(&cmd->return_sms, cmd->rsp_msg, cmd->rsp_length);
        }
        return KAL_TRUE;        // 执行操作后删除短信
    }
    else
    {
        LOGD(L_APP, L_V5, "invalid project command!");
        return KAL_FALSE;
    }
}
const char szWA205Default[] = "TBIT_WA205";
const char szMask[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ*#";
void sh_get_wa205_supper_psw(char *szSrc, char *szOut)
{
    char szPsw[20];
    U8 i;
    U8 c;
    U8 iLen = strlen(szSrc);
    for(i = 0; i < 10; i++)
    {
        if(i < iLen)
        {
            c = szSrc [ iLen - 1 - i]; // 取最后 10 位
        }
        else
        {
            c = '0'; // 不够就补 0
        }
        c = szWA205Default[i] ^ c; // 执行运算
        c = c % strlen(szMask); // 取模
        szOut [i] = szMask[c]; // 获取值
    }
    szOut [i] = 0; // 最后加 0 变成字符串
}
static char smsCmdMsgID[128];
static char smsRcvTel[32];
static char * r_strchr(const char *p, int len, char ch)
{
    int last_pos = -1;
    int i = 0;
    while(*(p + i) != '\0')
    {
        if(*(p + i) == ch)last_pos = i;
        if(++i >= len)break;
    }
    return last_pos >= 0 ? (char*)(p + last_pos) : NULL;
}

int track_cust_cmd_header(CMD_DATA_STRUCT * command)
{
    char cmdHeader[15] = {"$EXSET"};
    char szcmdHeader[15] = {"$SZCS"};
    char cxcmdHeader[15] = {"$CXCS"};
    char tempRcvMsg[CM_PARAM_LONG_LEN_MAX];
    U16  tempRcvLen = 0;
    char execode[10];
    U8 len = 0;
    int intexecode = 0;

    char *p = NULL, *q = NULL;
    int i = 0;

    memcpy(tempRcvMsg, command->rcv_msg, command->rcv_length);
    tempRcvLen = command->rcv_length;
    tempRcvMsg[tempRcvLen] = '\0';
    track_fun_toUpper(tempRcvMsg);    //转换成大写
    p = strstr(tempRcvMsg, cmdHeader);
    LOGD(L_APP, L_V4, "7号短信,%s:", tempRcvMsg);
    if(p != NULL)
    {
        isSmsCode = 0;
        q = strstr(p + 7, ",");
        if(q == NULL)
            return -4;
        p = r_strchr(p + 7, command->rcv_length - 7, ',');
        if((p - q - 1) != 3) return -3;

        memcpy(execode, q + 1, p - q - 1);
        len = p - q - 1;
        execode[len] = '\0';
        len = strlen(p + 1);
        memcpy(smsCmdMsgID, p + 1, len);
        smsCmdMsgID[len] = '\0';
        intexecode = track_fun_atoi(execode);

        memset(&msg_str, 0, sizeof(CMD_DATA_STRUCT));
        memcpy(&msg_str, command, sizeof(CMD_DATA_STRUCT));

        if(intexecode != 0)
        {
            isSmsCode = 1;
            track_cust_N07_paket_06(NULL, 0, 0, intexecode);
        }
        else
            return -5;
        LOGD(L_APP, L_V4, "控制指令：%d,%s:%s", intexecode, execode, smsCmdMsgID);

        return 0;
    }
    p = strstr(tempRcvMsg, szcmdHeader);
    if(p != NULL)
    {
        LOGD(L_APP, L_V4, "短信设置");
        q = strstr(tempRcvMsg, "=");
        if(q == NULL)
            return -1;

        p = strstr(tempRcvMsg + 6, ",");
        tempRcvLen = strlen(p + 1);
        //memcpy(tempRcvMsg, p+1, tempRcvLen);
        memset(command->rcv_msg, 0, CM_PARAM_LONG_LEN_MAX);
        memcpy(command->rcv_msg, p + 1, tempRcvLen);
        command->rcv_msg[tempRcvLen] = '#';
        command->rcv_length = tempRcvLen + 1;
        return 1;
    }
    p = strstr(tempRcvMsg, cxcmdHeader);
    if(p != NULL)
    {
        LOGD(L_APP, L_V4, "短信查询");
        q = strstr(tempRcvMsg, "=");
        if(q != NULL)
            return -2;

        p = strstr(tempRcvMsg + 6, ",");
        tempRcvLen = strlen(p + 1);
        //memcpy(tempRcvMsg, p+1, tempRcvLen);
        memset(command->rcv_msg, 0, CM_PARAM_LONG_LEN_MAX);
        memcpy(command->rcv_msg, p + 1, tempRcvLen);
        command->rcv_msg[tempRcvLen] = '#';
        command->rcv_length = tempRcvLen + 1;
        return 2;
    }
    return 99;
}
void track_cust_sms_command(kal_uint8 flag)
{

    kal_uint8 result = 0;
    int len = 0;

    LOGD(L_APP, L_V4, "短信回复,flag:%d", flag);
    if(flag == 0x00)
        sprintf(msg_str.rsp_msg, "RESULT,200,%s", smsCmdMsgID);
    else
        sprintf(msg_str.rsp_msg, "RESULT,201,%s", smsCmdMsgID);

    msg_str.return_sms.reply_character_encode = 0;
    track_cust_cmd_reply(&msg_str.return_sms, msg_str.rsp_msg, msg_str.rsp_length);
    isSmsCode = 0;
    memset(smsCmdMsgID, 0, 128);
}
U8 track_get_code()
{
    return isSmsCode;
}

