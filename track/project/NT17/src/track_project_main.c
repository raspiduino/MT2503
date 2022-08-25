/******************************************************************************
 * track_project_main.c -
 *
 * Copyright .
 *
 * DESCRIPTION: -
 *        各项目不同的入口处理 ,每个项目都存在这样的同名文件，不得重命名
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
#include "track_drv_gps_decode.h"
#include "track_drv_uart.h"
#include "track_cust.h"
#include "track_os_timer.h"
/*****************************************************************************
 *  Define					宏定义
 *****************************************************************************/
#define MCU_UART_PORT               uart_port3
#define MCU_UART_BAND               9600



/*****************************************************************************
* Typedef  Enum         枚举
*****************************************************************************/



/*****************************************************************************
 *  Struct                              数据结构定义
 *****************************************************************************/



/*****************************************************************************
 *  Global Functions			全局变量
 *****************************************************************************/


/*****************************************************************************
 *  Local Functions			本地函数
 *****************************************************************************/
static void track_uart_read_mcu_version(void);
static void track_drv_set_protection_voltage(void);
void track_drv_mcu_send_data(kal_uint8 cmd);

/*****************************************************************************
*  Global Functions                     全局函数
******************************************************************************/
extern void track_cust_key_led_sleep();

/******************************************************************************
 *  Function    -  track_project_main_init
 *
 *  Purpose     -  开机后执行一次，各项目按需求执行初始化事件
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-06-30,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_project_main_init(void)
{
    track_cust_LBS_upload();
#if defined (__BLE_GATT__)
     track_drv_ble_gatt_switch(1);
#endif

}



/******************************************************************************
 *  Function    -  track_project_gpio_init
 *
 *  Purpose     -  GPIO端口初始化，无特殊操作则为空函数
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-12,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_project_gpio_init(void)
{

}

kal_uint8 track_project_uart_init(void)
{
    track_drv_uart_config(MCU_UART_PORT, MOD_MMI, MCU_UART_BAND);

    return YES_GO_ON;
}

/******************************************************************************
 *  Function    -  track_project_keypad_init
 *
 *  Purpose     -  仅针对矩阵键盘注册
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-12,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_project_keypad_init()
{

}

/******************************************************************************
 *  Function    -  track_project_gps_work_and_fix_nitify
 *
 *  Purpose     -  GPS从不定位到定位消息
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-12,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_project_gps_work_and_fix_nitify(track_gps_data_struct * gps_data)
{


}

void track_cust_gps_search_overtime_wifi_upload(void)
{
}

/******************************************************************************
 *  Function    -  track_project_gps_work_no_fix_nitify
 *
 *  Purpose     -  GPS从定位到不定位消息
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-12,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_project_gps_work_no_fix_nitify(void)
{
    track_cust_gps_search_overtime_wifi_upload();

}

/******************************************************************************
 *  Function    -  track_project_gsensor_shocked_event
 *
 *  Purpose     -  发生震动事件，是否继续原来的流程？
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-12,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_project_gsensor_shocked_event(void)
{
    return YES_GO_ON;
}


/******************************************************************************
 *  Function    -  track_project_enters_quiescent_state_notify
 *
 *  Purpose     -  一段时间未检测到震动，进入静止状态
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-12,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_project_enters_quiescent_state_notify(void)
{

}

/******************************************************************************
 *  Function    -  track_project_status_eint_notify
 *
 *  Purpose     -  中断事件通知
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-13,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_project_status_eint_notify(U8 eint, U8 level)
{
    return YES_GO_ON;
}


/******************************************************************************
 *  Function    -  track_drv_mcu_uart_write_data
 *
 *  Purpose     -  向单片机发送
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-10-10,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_mcu_uart_write_data(kal_uint8* data, kal_uint16 len)
{
    track_drv_write_exmode(data, len);
}

static void trak_mcu_extvolt_convey(kal_uint32 ext_volt)
{
    track_drv_set_mcu_external_voltage(ext_volt);
    #if 0
    if(ext_volt > 20000000)
    {
        LOGD(L_MCU, L_V4, "不使用单片机结果");
    }
    else
    {
        track_cust_chargestatus_vbtstatus_check(PMIC_VBAT_STATUS, 99, ext_volt);
    }
    #endif
}

static kal_uint8 track_mcu_uart_send_no_ack_resend(kal_uint8 count)
{
    static kal_uint8 number_of_times = 0;

    if(count == 0)
    {
        number_of_times = 0;
        return 0;
    }
    else if(count == 1)
    {
        if(number_of_times < 20)
        {
            number_of_times++;
        }
        return number_of_times;
    }
    else
    {
        return number_of_times;
    }
}


static kal_uint8 mcu_version[4]={0};
kal_uint8* track_drv_get_mcu_version(void)
{
    return mcu_version;
}

static void track_uart_read_mcu_version(void)
{
    track_drv_mcu_send_data(MCU_CMD_GET_VERSION);
}

static void track_drv_set_protection_voltage(void)
{
    kal_uint16 adc_l, adc_h; //低电保护和恢复电压的ADC值
    kal_uint8 buff[8] = {0};

    // adc=2048*volt/11
    //adc_l = 2048 * 11.5 / 11;
    //adc_h = 2048 * 12 / 11;

    adc_l=G_parameter.power_extbatcut.threshold * 18.618182;
    adc_h=G_parameter.power_extbatcut.recover_threshold * 18.618182;

    buff[0] = 0x53;
    buff[1] = (adc_l >> 8) & 0xFF;
    buff[2] = (adc_l & 0xFF);
    buff[3] = (adc_h >> 8) & 0xFF;
    buff[4] = (adc_h & 0xFF);
    buff[5] = 0x0D;
    track_drv_mcu_uart_write_data(buff, 6);
}


void track_cmd_extbatcut_change_update_to_mcu(void)
{
    if(G_parameter.power_extbatcut.sw==0)
    {
        track_drv_mcu_send_data(MCU_CMD_SET_EXTCUT_DISABLE);
    }
    else
    {
        track_drv_mcu_send_data(MCU_CMD_SET_EXTCUT_ENABLE);
    }
}


/******************************************************************************
 *  Function    -  track_mcu_uart_rece
 *
 *  Purpose     -  接收单片机的数据处理
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-06-19,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_mcu_uart_rece(kal_uint8* buff, kal_uint16 len)
{
    kal_uint8* p = NULL;
    kal_uint8 data[10] = {0};

    if((buff == NULL) || (len == 0))
    {
        return;
    }

    if(len > 9)
    {
        len = 9;
    }
    memcpy(data, buff, len);

    LOGH(L_MCU, L_V4, data, len);
    //LOGD(L_MCU, L_V4, "%s", data);

    if(track_is_timer_run(TRACK_DRV_MCU_NOACK_RESEND_TIMER_ID))
    {
        track_mcu_uart_send_no_ack_resend(0);
        track_stop_timer(TRACK_DRV_MCU_NOACK_RESEND_TIMER_ID);
    }

    if(strstr(data, "AONN") != NULL) //点火
    {
        LOGD(L_DRV, L_V1, "点火");
    }
    else if(strstr(data, "AOFF") != NULL) //熄火
    {
        LOGD(L_DRV, L_V1, "熄火");
    }
    else if(strstr(data, "PTON") != NULL) //单片机主动断外电
    {
        LOGD(L_DRV, L_V1, "低电保护");
        track_drv_mcu_uart_write_data("PTON\r\n", 6);
        track_cust_module_mcu_control_extbat(0);
    }
    else if(strstr(data, "PTOF") != NULL) //单片机恢复外电
    {
        LOGD(L_DRV, L_V1, "外电接通");
        track_drv_mcu_uart_write_data("PTOF\r\n", 6);
        track_cust_module_mcu_control_extbat(1);
    }
    else if(strstr(data, "PCUT") != NULL) //外电断开，断电报警
    {
        LOGD(L_DRV, L_V1, "外电断开");
        track_drv_mcu_uart_write_data("PCUT\r\n", 6);
        
        track_cust_pwrcut_alm_form_mcu();
    }    
    else if(strstr(data, "VR") != NULL) //单片机软件版本
    {
        p = strstr(data, "VR");
        p += 2;

        LOGD(L_DRV, L_V1, "version:%c.%c", *p, *(p + 1));
        mcu_version[0]=(*p);
        mcu_version[1]=(*(p + 1));
        track_drv_set_protection_voltage();//设置低电保护参数
    }
    else if(strstr(data, "VT") != NULL) //单片机检测到的外电电压
    {
        float v_ext;
        kal_uint32 mcu_extVolt;
        p = strstr(data, "VT");
        p += 2;

        v_ext = (((*p) << 8) | (*(p + 1))) * 11.0 / 2048.0;
        mcu_extVolt = v_ext * 1000000;
        LOGD(L_DRV, L_V5, "mcu ext %f", v_ext);
        trak_mcu_extvolt_convey(mcu_extVolt);
    }
    else if(strstr(data, "OEON") != NULL) //允许单片机断外电
    {
        LOGD(L_DRV, L_V5, "允许单片机断外电");
        track_drv_set_protection_voltage();
    }
    else if(strstr(data, "OEOF") != NULL) //禁止单片机断外电
    {
        LOGD(L_DRV, L_V5, "禁止单片机断外电");
    }
    else if(strstr(data, "ELOW") != NULL) //强制断外电
    {
        LOGT("ELOW");
    }
    else if(strstr(data, "EHIG") != NULL) //强制接通外电
    {
        LOGT("EHIG");
    }    
    else if(data[0] == 0x53) //外电低电保护电压和回复电压
    {
        float v1, v2;
        v1 = ((data[1] << 8) | data[2]) * 11.0 / 2048.0;
        v2 = ((data[3] << 8) | data[4]) * 11.0 / 2048.0;
        LOGT("PRO_VOLT=%fV,%fV", v1, v2);
    }    
    else
    {
        LOGD(L_DRV, L_V1, "%s", "error");
    }
}


void track_drv_mcu_send_data(kal_uint8 cmd)
{
    switch(cmd)
    {
        case MCU_CMD_GET_VERSION:
            track_drv_mcu_uart_write_data("GTVR\r\n", 6);
            break;

        case MCU_CMD_SET_ACC_ON:
            track_drv_mcu_uart_write_data("AONN\r\n", 6);
            break;

        case MCU_CMD_SET_ACC_OFF:
            track_drv_mcu_uart_write_data("AOFF\r\n", 6);
            break;

        case MCU_CMD_SET_EXTCUT_ENABLE:
            track_drv_mcu_uart_write_data("OEON\r\n", 6);
            break;

        case MCU_CMD_SET_EXTCUT_DISABLE:
            track_drv_mcu_uart_write_data("OEOF\r\n", 6);
            break;
            
        case MCU_CMD_SET_EXT_ON:
            track_drv_mcu_uart_write_data("EHIG\r\n", 6);
            break;

        case MCU_CMD_SET_EXT_OFF:
            track_drv_mcu_uart_write_data("ELOW\r\n", 6);
            break;
            
        case MCU_CMD_SET_VOLT:
            track_drv_set_protection_voltage();
            break;

        default:
            return;
    }

    if(track_mcu_uart_send_no_ack_resend(1)<10)
    {
        track_start_timer(TRACK_DRV_MCU_NOACK_RESEND_TIMER_ID, 2000, track_drv_mcu_send_data, (void*)cmd);
    }
}


void track_cust_acc_status_update_to_mcu(kal_uint32 acc)
{
    static kal_uint8 first=0;

    if(first==0)
    {
        first=1;        
        track_start_timer(TRACK_DRV_MCU_SEND_DELAY_TIMER_ID, 10000, track_cust_acc_status_update_to_mcu, (void*)acc);
        return;
    }
    if(acc)
    {
        track_drv_mcu_send_data(MCU_CMD_SET_ACC_ON);
    }
    else
    {
        track_drv_mcu_send_data(MCU_CMD_SET_ACC_OFF);
    }

    if(first==1)
    {
        first=2;
        tr_start_timer(TRACK_DRV_MCU_SEND_DELAY_TIMER_ID, 3000, track_uart_read_mcu_version);
    }
}

/******************************************************************************
 *  Function    -  track_project_uart_receice_data_notify
 *
 *  Purpose     -  串口收到数据通知
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-07-13,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_project_uart_receice_data_notify(UART_PORT port, kal_uint8* data, kal_uint16 len)
{
    if(port == uart_port3)
    {
        track_mcu_uart_rece(data, len);  //单独去解析
        return NO_STOP;
    }
    return YES_GO_ON;
}





