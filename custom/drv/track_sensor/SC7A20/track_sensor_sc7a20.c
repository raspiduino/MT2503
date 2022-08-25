/******************************************************************************
 * track_sensor_sc7a20.c - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *        SC7A20 gSensor驱动 
 * 
 * modification history
 * --------------------
 * v1.0   2017-04-11,  chengjun create this file
 * 
 ******************************************************************************/
 
#if defined (__SILAN_SC7A20__)

#include "kal_release.h"
#include "custom_config.h"
#include "gpio_sw.h"
#include "drv_comm.h"
#include "eint.h"
#include "motion_sensor.h"
#include "track_sensor_iic.h"
#include "track_sensor_sc7a20.h"
#include "kal_trace.h"
#include "track_os_timer.h"
#include "track_drv_sensor.h"
#include "ell_os.h"

static kal_uint8 sc7a20_chip_id = 0XFF;

static void track_sensor_sc7a20_reset_int(void);

kal_bool sensor_sc7a20_write_byte(kal_uint8 ucBufferIndex, kal_uint8 pucData)
{
    return ms_i2c_send(SC7A20_I2C_SLAVE_ADDR, ucBufferIndex, &pucData, 1);
}


#define sensor_sc7a20_read(a,b,c) ms_i2c_receive(SC7A20_I2C_SLAVE_ADDR,a,b,c)


#if defined (__TRACK_SENSOR__)

static void  delay_1ms(kal_uint16 ms)
{
    volatile kal_uint16 i;
    while(ms--)
    {
        for(i = 0; i < 2048; i++)
        {
            ;
        }
    }
}
/******************************************************************************
 *
 *     Sensor 自定义部分
 *
 ******************************************************************************/
static void  sensor_sc7a20_init(void)
{
    unsigned char threshold = 0;

    ms_i2c_configure(SC7A20_I2C_SLAVE_ADDR, MS_DELAY_TIME);

    sensor_sc7a20_read(0x0F, &sc7a20_chip_id, 1);   //读取芯片ID

    sensor_sc7a20_write_byte(0x24, 0x80); //boot
    sensor_sc7a20_write_byte(0x20, 0x67); //ODR=200HZ  xyz enable
    sensor_sc7a20_write_byte(0x21, 0x0D); //High pass filter
    sensor_sc7a20_write_byte(0x23, 0x80); //2g
    sensor_sc7a20_write_byte(0x3B, 0x7F); //
    sensor_sc7a20_write_byte(0x38, 0x15); //click

    sensor_sc7a20_write_byte(0x3A, OTA_track_sensor_config_data->sensor_threshold);
    sensor_sc7a20_write_byte(0x3C, 0xC8); //200Hz/1s
    sensor_sc7a20_write_byte(0x22, 0x80); //click interrupt enable
}


/******************************************************************************
 *  Function    -  sensor_sc7a20_on
 *
 *  Purpose     -  sensor 寄存器和中断配置
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-12-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void sensor_sc7a20_on(void)
{
    sensor_sc7a20_init();
    track_sensor_sc7a20_interrput_configuration();
}

/******************************************************************************
 *  Function    -  sensor_sc7a20_pwr_down
 *
 *  Purpose     -  关闭sensor
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 05-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void sensor_sc7a20_pwr_down(void)
{
    sensor_sc7a20_write_byte(0x22, 0x00); //disbale all int. 
    track_drv_delay_1ms(10);
    sensor_sc7a20_write_byte(0x20, 0x07);//Power down mode
}

/******************************************************************************
 *  Function    -  track_sensor_sc7a20_reset
 *
 *  Purpose     -  sensor 复位
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 05-01-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_sensor_sc7a20_reset(void)
{
    //OTA_LOGD(L_DRV, L_V1, "sensor sc7a20 reset");
    sensor_sc7a20_pwr_down();
    OTA_tr_start_timer(MOTION_SENSOR_RESET_TIMER_ID,  10000, sensor_sc7a20_on);
}

/******************************************************************************
 *  Function    -  track_sensor_sc7a20_data_self_test
 *
 *  Purpose     -  sensor 工作异常监测
 *
 *  Description - 定时参数自检，若异常则重置
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-12-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_sensor_sc7a20_data_self_test(void)
{
    unsigned char reg38, threshold = 0;

    //sensor_sc7a20_write_byte(0x3A, OTA_track_sensor_config_data->sensor_threshold);
    sensor_sc7a20_read(0x3A, &threshold, 1);   //读取灵敏度

    //sensor_sc7a20_write_byte(0x38, 0x15); //click
    sensor_sc7a20_read(0x38, &reg38, 1);

    if((reg38 != 0x15)||(threshold != OTA_track_sensor_config_data->sensor_threshold))
    {
        OTA_LOGD(L_DRV, L_V1, "Sensor error (0x15-0x%02X,0x%02X-0x%02X", \
            reg38,threshold,OTA_track_sensor_config_data->sensor_threshold);

        OTA_tr_stop_timer(MOTION_SENSOR_DATA_TIMER_ID);
        OTA_tr_start_timer(MOTION_SENSOR_RESET_TIMER_ID,  3000, track_sensor_sc7a20_reset);
    }
    OTA_tr_start_timer(MOTION_SENSOR_DATA_TIMER_ID, 60000, track_sensor_sc7a20_data_self_test);
}


/******************************************************************************
 *  Function    -  track_sensor_sc7a20_interrput_configuration
 *
 *  Purpose     -  注册高电平(  震动) 响应
 *
 *  Description -
 *
 * 1、自动清标志
 * 2、软件防抖
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-12-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_sensor_sc7a20_interrput_configuration(void)
{
    OTA_LOGD(L_DRV, L_V1, "Sensor eint reg H");
    EINT_Mask(MOTION_SENSOR_EINT_NO);
    EINT_Registration(MOTION_SENSOR_EINT_NO, KAL_TRUE, 1, track_sensor_sc7a20_eint_hisr, KAL_TRUE);
    EINT_Set_Sensitivity(MOTION_SENSOR_EINT_NO, LEVEL_SENSITIVE);
    EINT_SW_Debounce_Modify(MOTION_SENSOR_EINT_NO, SENSOR_SW_DEBOUNCE_TIME);
    EINT_UnMask(MOTION_SENSOR_EINT_NO);

    if(!OTA_track_is_timer_run(MOTION_SENSOR_DATA_TIMER_ID))
    {
        OTA_tr_start_timer(MOTION_SENSOR_DATA_TIMER_ID, 10000, track_sensor_sc7a20_data_self_test);
    }
}


/******************************************************************************
 *  Function    -  track_sensor_sc7a20_get_xyz
 *
 *  Purpose     -  读取当前XYZ数值
 *
 *  Description -  2g /12bit
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-12-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_sensor_sc7a20_get_xyz(short*x, short*y, short*z)
{

}

/******************************************************************************
 *  Function    -  track_sensor_sc7a20_reset_int
 *
 *  Purpose     -  清除中断标志
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-12-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_sensor_sc7a20_reset_int(void)
{
    unsigned char fint;
    sensor_sc7a20_read(0x39, &fint, 1);
}

/******************************************************************************
 *  Function    -  track_sensor_sc7a20_eint_hisr
 *
 *  Purpose     -  震动高电平响应
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 07-09-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
static void track_sensor_sc7a20_eint_hisr(void)
{
    if(OTA_track_sensor_config_data->sensor_callback != NULL)
    {
        OTA_track_drv_sensor_interrupt_send_msg();
    }

    OTA_LOGC(L_DRV, L_V1, "sensor 震动 ");
}

/******************************************************************************
 *  Function    -  track_get_sensor_sc7a20_id
 *
 *  Purpose     -  读取sensor ID
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-12-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_uint8 track_get_sensor_sc7a20_id(void)
{
    return sc7a20_chip_id;
}


/******************************************************************************
 *  Function    -  track_sensor_sc7a20_calibration
 *
 *  Purpose     - sensor 三轴加速度初值校准
 *
 *  Description -  平放
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 25-11-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_sensor_sc7a20_calibration(void)
{

}


/******************************************************************************
 *  Function    -  track_sensor_sc7a20_on
 *
 *  Purpose     -  开启sensor 检测
 *
 *  Description -  motion_threshold  [in] : sensor 检测灵敏度
 *                       FuncPtr  [in] : sensor 触发回调函数
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-12-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_sensor_sc7a20_on(kal_uint8 threshold , FuncPtr callback)
{
    OTA_LOGD(L_DRV, L_V1, "threshold=%d", threshold);

    if((threshold <= 0) || (callback == NULL))
    {
        return;
    }

    OTA_track_sensor_config_data->sensor_threshold = threshold;
    OTA_track_sensor_config_data->sensor_callback = callback;

    sensor_sc7a20_on();

}

/******************************************************************************
 *  Function    -  track_sensor_sc7a20_off
 *
 *  Purpose     -  关闭sensor 检测
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 18-12-2012,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_sensor_sc7a20_off(void)
{
    OTA_tr_stop_timer(MOTION_SENSOR_DATA_TIMER_ID);
    OTA_tr_stop_timer(MOTION_SENSOR_RESET_TIMER_ID);
    sensor_sc7a20_pwr_down();
}

/******************************************************************************
 *  Function    -  track_sensor_sc7a20_type_check
 *
 *  Purpose     -  是否为SC7A20
 *
 *  Description -
 *
 * modification history
 * ----------------------------------------
 * v1.0  , 26-02-2013,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
kal_bool track_sensor_sc7a20_type_check(void)
{
    kal_uint8 sc7a20_check = 0XFF;

    ms_i2c_configure(SC7A20_I2C_SLAVE_ADDR, MS_DELAY_TIME);
    sensor_sc7a20_read(0x0F, &sc7a20_check, 1);
    OTA_LOGD(L_DRV, L_V1, "sensor id=%02X", sc7a20_check);
    if(sc7a20_check == 0x11)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

#endif /* __TRACK_SENSOR__ */

#endif /* __SILAN_SC7A20__ */
