/******************************************************************************
 * track_sensor_iic.c - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *        IIC 通信 
 * 
 * modification history
 * --------------------
 * v1.0   2013-02-28,  chengjun create this file
 * 
 ******************************************************************************/


#if defined (__TRACK_SENSOR__)

#include "kal_release.h"
#include "dcl.h"
#include "us_timer.h"               /* For ust_get_current_time() API*/
#include "track_sensor_iic.h"


kal_bool ms_i2c_configure_done = KAL_FALSE;

extern const char gpio_acc_sensor_sck_pin ;
extern const char gpio_acc_sensor_sda_pin ;

#define GPIO_SENSOR_SCK     gpio_acc_sensor_sck_pin
#define GPIO_SENSOR_SDA     gpio_acc_sensor_sda_pin


#if defined MCU_52M
kal_uint32 MS_DELAY_TIME	= 350;
#elif defined MCU_104M
kal_uint32 MS_DELAY_TIME	= 700;
#elif defined MCU_260M
kal_uint32 MS_DELAY_TIME	= 1800;
#elif defined MCU_364M 
kal_uint32 MS_DELAY_TIME	= 2500;
#else
#error not support
//与系统时钟有关
#endif


DCL_HANDLE ms_i2c_handle;
DCL_HANDLE ms_pmu_handle;

#define MS_I2C_DELAY \
{\
	volatile int count=0;\
	for(;count<MS_DELAY_TIME;count++);\
}


/******************************************************************************
 *  Function    -  track_drv_delay_1ms
 * 
 *  Purpose     -  MT2503D实测延时单位是1ms
 * 
 *  Description -   
 * 
 * modification history
 * ----------------------------------------
 * v1.0  , 2017-06-27,  chengjun  written
 * ----------------------------------------
 ******************************************************************************/
void track_drv_delay_1ms(kal_uint16 ms)
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

void ms_i2c_udelay(kal_uint32 delay)
{
    kal_uint32 ust = 0; //ust_get_current_time
    kal_uint32 count = 0;
    kal_uint32 break_count = 0;

    ust = ust_get_current_time();
    do
    {
        if(ust_get_current_time() != ust)
            count++;
        else
            break_count++;
    }
    while((count < delay) && (break_count < 0xFFFFFF));
}


void ms_i2c_configure(kal_uint32 slave_addr, kal_uint32 speed)
{
    I2C_CONFIG_T cfg;

    ms_i2c_configure_done = KAL_TRUE;
}


void ms_i2c_power_on(kal_bool ON, kal_uint32 ldo, kal_uint32 ldo_volt)
{
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE_EN pmu_ldo_voltage_en;
    PMU_CTRL_LDO_BUCK_SET_EN pmu_ldo_en;

    if(ms_pmu_handle == DCL_HANDLE_NONE)
        ms_pmu_handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);

    if(ON && (ldo_volt != 0))
    {
        pmu_ldo_voltage_en.mod = (PMU_LDO_BUCK_LIST_ENUM)ldo;
        pmu_ldo_voltage_en.voltage = (PMU_VOLTAGE_ENUM)ldo_volt;
        DclPMU_Control(ms_pmu_handle, LDO_BUCK_SET_VOLTAGE_EN, (DCL_CTRL_DATA_T *)& pmu_ldo_voltage_en);
    }
    else if(ON && (ldo_volt == 0))
    {
        pmu_ldo_en.mod = (PMU_LDO_BUCK_LIST_ENUM)ldo;
        pmu_ldo_en.enable = KAL_TRUE;
        DclPMU_Control(ms_pmu_handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&pmu_ldo_en);
    }
    else
    {
        pmu_ldo_en.mod = (PMU_LDO_BUCK_LIST_ENUM)ldo;
        pmu_ldo_en.enable = KAL_FALSE;
        DclPMU_Control(ms_pmu_handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&pmu_ldo_en);
    }
}

// Start bit of I2C waveform
void ms_i2c_start(void)
{
    DCL_HANDLE sda_handle, scl_handle;

    sda_handle = DclGPIO_Open(DCL_GPIO, GPIO_SENSOR_SDA);
    scl_handle = DclGPIO_Open(DCL_GPIO, GPIO_SENSOR_SCK);

    DclGPIO_Control(sda_handle, GPIO_CMD_SET_MODE_0, NULL);
    DclGPIO_Control(scl_handle, GPIO_CMD_SET_MODE_0, NULL);

    DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);
    DclGPIO_Control(scl_handle, GPIO_CMD_SET_DIR_OUT, NULL);

    DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_HIGH, NULL);
    DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);
    MS_I2C_DELAY;
    DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
    MS_I2C_DELAY;

    DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_LOW, NULL);
    MS_I2C_DELAY;
    DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
    MS_I2C_DELAY;

    DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_LOW, NULL);
    MS_I2C_DELAY;
    DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_LOW, NULL);
    MS_I2C_DELAY;

}

// Stop bit of I2C waveform
void ms_i2c_stop(void)
{
    DCL_HANDLE sda_handle, scl_handle;

    sda_handle = DclGPIO_Open(DCL_GPIO, GPIO_SENSOR_SDA);
    scl_handle = DclGPIO_Open(DCL_GPIO, GPIO_SENSOR_SCK);

    DclGPIO_Control(sda_handle, GPIO_CMD_SET_MODE_0, NULL);
    DclGPIO_Control(scl_handle, GPIO_CMD_SET_MODE_0, NULL);

    DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);
    DclGPIO_Control(scl_handle, GPIO_CMD_SET_DIR_OUT, NULL);

    DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_LOW, NULL);
    DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);
    MS_I2C_DELAY;
    DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
    MS_I2C_DELAY;

    DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_HIGH, NULL);
    MS_I2C_DELAY;
    DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
    MS_I2C_DELAY;

}

// Send one byte from host to client
kal_bool ms_i2c_send_byte(kal_uint8 ucData)
{
    //kal_bool bRet;
    int i;
    kal_bool ret;
    kal_uint8 ucMask;
    DCL_STATUS status = STATUS_INVALID_OPERATION;
    GPIO_CTRL_READ_T sda_read;
    I2C_CTRL_CONT_WRITE_T write;
    DCL_HANDLE sda_handle, scl_handle;

    sda_handle = DclGPIO_Open(DCL_GPIO, GPIO_SENSOR_SDA);
    scl_handle = DclGPIO_Open(DCL_GPIO, GPIO_SENSOR_SCK);

    DclGPIO_Control(sda_handle, GPIO_CMD_SET_MODE_0, NULL);
    DclGPIO_Control(scl_handle, GPIO_CMD_SET_MODE_0, NULL);

    DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);
    DclGPIO_Control(scl_handle, GPIO_CMD_SET_DIR_OUT, NULL);

    for(i = 0, ucMask = 0x80; i < 8; i++, ucMask >>= 1)
    {
        if(ucData & ucMask)
            DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_HIGH, NULL);
        else
            DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_LOW, NULL);
        MS_I2C_DELAY;
        DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
        MS_I2C_DELAY;
        DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_LOW, NULL);
        MS_I2C_DELAY;
    }
    DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_IN, NULL);

    DclGPIO_Control(sda_handle, GPIO_CMD_READ, (DCL_CTRL_DATA_T *)&sda_read);

    DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
    MS_I2C_DELAY;
    DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_LOW, NULL);
    MS_I2C_DELAY;

    ret = (sda_read.u1IOData == GPIO_IO_HIGH) ? KAL_TRUE : KAL_FALSE;

    return ret;
}

// Receive one byte form client to host
kal_uint8 ms_i2c_receive_byte(kal_bool bAck)
{
    kal_uint8 ucRet = 0;
    int i;
    I2C_CTRL_CONT_READ_T read;
    GPIO_CTRL_READ_T sda_read;
    DCL_STATUS status;
    DCL_HANDLE sda_handle, scl_handle;


    sda_handle = DclGPIO_Open(DCL_GPIO, GPIO_SENSOR_SDA);
    scl_handle = DclGPIO_Open(DCL_GPIO, GPIO_SENSOR_SCK);

    DclGPIO_Control(sda_handle, GPIO_CMD_SET_MODE_0, NULL);
    DclGPIO_Control(scl_handle, GPIO_CMD_SET_MODE_0, NULL);

    DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_IN, NULL);
    DclGPIO_Control(scl_handle, GPIO_CMD_SET_DIR_OUT, NULL);

    for(i = 7; i >= 0; i--)
    {
        DclGPIO_Control(sda_handle, GPIO_CMD_READ, (DCL_CTRL_DATA_T *)&sda_read);
        ucRet |= sda_read.u1IOData << i;

        DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
        MS_I2C_DELAY;
        DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_LOW, NULL);
        MS_I2C_DELAY;
    }

    DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);

    if(bAck)
        DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_HIGH, NULL);
    else
        DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_LOW, NULL);
    MS_I2C_DELAY;

    DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
    MS_I2C_DELAY;
    DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_LOW, NULL);
    MS_I2C_DELAY;


    return ucRet;
}

// I2C send data fuction
kal_bool ms_i2c_send(kal_uint8 ucDeviceAddr, kal_uint8 ucBufferIndex, kal_uint8* pucData, kal_uint32 unDataLength)
{
    kal_uint32 i;
    kal_uint8 write_buf[9];
    kal_bool bRet = KAL_TRUE;
    I2C_CTRL_CONT_WRITE_T write;
    DCL_STATUS status;


    ms_i2c_start();

    if(ms_i2c_send_byte(ucDeviceAddr & 0xFE) == MS_I2C_ACK)
    {
        if(ms_i2c_send_byte(ucBufferIndex) == MS_I2C_ACK)
        {
            for(i = 0; i < unDataLength; i++)
            {
                if(ms_i2c_send_byte(pucData[i]) == MS_I2C_NAK)
                {
                    bRet = KAL_FALSE;
                    break;
                }
            }
        }
        else
        {
            bRet = KAL_FALSE;
        }
    }
    else
    {
        bRet = KAL_FALSE;
    }
    ms_i2c_stop();

    return bRet;
}

kal_bool ms_i2c_send_ext(kal_uint8 ucDeviceAddr, kal_uint16 ucBufferIndex, kal_uint8* pucData, kal_uint32 unDataLength)
{
    kal_uint32 i;
    kal_uint8 write_buf[10];
    kal_bool bRet = KAL_TRUE;
    I2C_CTRL_CONT_WRITE_T write;
    DCL_STATUS status;
    kal_uint8 addr_h = (ucBufferIndex >> 8) & 0xFF;
    kal_uint8 addr_l = ucBufferIndex & 0xFF;
    kal_uint32 offset = 0;
    kal_uint8  pkt_len;


    ms_i2c_start();

    if(ms_i2c_send_byte(ucDeviceAddr & 0xFE) == MS_I2C_ACK)
    {
        if((ms_i2c_send_byte(addr_h) == MS_I2C_ACK) &&
                (ms_i2c_send_byte(addr_l) == MS_I2C_ACK))
        {
            for(i = 0; i < unDataLength; i++)
            {
                if(ms_i2c_send_byte(pucData[i]) == MS_I2C_NAK)
                {
                    bRet = KAL_FALSE;
                    break;
                }
            }
        }
        else
        {
            bRet = KAL_FALSE;
        }
    }
    else
    {
        bRet = KAL_FALSE;
    }
    ms_i2c_stop();

    return bRet;
}

// I2C receive data function
kal_bool ms_i2c_receive(kal_uint8 ucDeviceAddr, kal_uint8 ucBufferIndex, kal_uint8* pucData, kal_uint32 unDataLength)
{
    kal_uint32 i;
    kal_bool bRet = KAL_TRUE;
    I2C_CTRL_WRITE_AND_READE_T write_read;


    ms_i2c_start();

    if(ms_i2c_send_byte(ucDeviceAddr & 0xFE) == MS_I2C_ACK)
    {
        if(ms_i2c_send_byte(ucBufferIndex) == MS_I2C_ACK)
        {
            ms_i2c_start();

            if(ms_i2c_send_byte(ucDeviceAddr | 0x01) == MS_I2C_ACK)
            {
                for(i = 0; i < unDataLength - 1; i++)
                {
                    pucData[i] = ms_i2c_receive_byte((kal_bool)MS_I2C_ACK);
                }
                pucData[unDataLength - 1] = ms_i2c_receive_byte((kal_bool)MS_I2C_NAK);
            }
            else
            {
                bRet = KAL_FALSE;
            }
        }
        else
        {
            bRet = KAL_FALSE;
        }
    }
    else
    {
        bRet = KAL_FALSE;
    }
    ms_i2c_stop();

    return bRet;
}

// I2C receive data function
kal_bool ms_i2c_receive_ext(kal_uint8 ucDeviceAddr, kal_uint16 ucBufferIndex, kal_uint8* pucData, kal_uint32 unDataLength)
{
    kal_uint32 i;
    kal_bool bRet = KAL_TRUE;
    I2C_CTRL_WRITE_AND_READE_T write_read;
    kal_uint8 write_buf[2];
    kal_uint16 reg_addr = ucBufferIndex;
    kal_uint32 offset = 0;
    kal_uint8  pkt_len;
    kal_uint8 addr_h = (ucBufferIndex >> 8) & 0xFF;
    kal_uint8 addr_l = ucBufferIndex & 0xFF;


    ms_i2c_start();

    if(ms_i2c_send_byte(ucDeviceAddr & 0xFE) == MS_I2C_ACK)
    {
        if((ms_i2c_send_byte(addr_h) == MS_I2C_ACK) &&
                (ms_i2c_send_byte(addr_l) == MS_I2C_ACK))
        {
            ms_i2c_start();

            if(ms_i2c_send_byte(ucDeviceAddr | 0x01) == MS_I2C_ACK)
            {
                for(i = 0; i < unDataLength - 1; i++)
                {
                    pucData[i] = ms_i2c_receive_byte((kal_bool)MS_I2C_ACK);
                }
                pucData[unDataLength - 1] = ms_i2c_receive_byte((kal_bool)MS_I2C_NAK);
            }
            else
            {
                bRet = KAL_FALSE;
            }
        }
        else
        {
            bRet = KAL_FALSE;
        }
    }
    else
    {
        bRet = KAL_FALSE;
    }
    ms_i2c_stop();

    return bRet;
}

#endif /* __TRACK_SENSOR__ */

