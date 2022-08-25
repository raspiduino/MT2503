/******************************************************************************
 * track_sensor_iic.h - 
 * 
 * Copyright .
 * 
 * DESCRIPTION: - 
 *        IIC м╗пе  
 * 
 * modification history
 * --------------------
 * v1.0   2013-02-28,  chengjun create this file
 * 
 ******************************************************************************/

#if defined (__TRACK_SENSOR__)

#ifndef _TRACK_SENSOR_IIC_H
#define _TRACK_SENSOR_IIC_H

#define MS_I2C_LOW				0
#define MS_I2C_HIGH         			1
#define MS_I2C_ACK				MS_I2C_LOW
#define MS_I2C_NAK				MS_I2C_HIGH

extern kal_uint32 MS_DELAY_TIME;

//delay
void ms_i2c_udelay(kal_uint32 delay);

//power on I2C
void ms_i2c_power_on(kal_bool ON, kal_uint32 ldo, kal_uint32 ldo_volt);

//configure SW I2C or HW I2C parameters
void ms_i2c_configure(kal_uint32 slave_addr, kal_uint32 speed);

// Start bit of I2C waveform
extern void ms_i2c_start(void);

// Stop bit of I2C waveform
extern void ms_i2c_stop(void);

// Send one byte from host to client
extern kal_bool ms_i2c_send_byte(kal_uint8 ucData);

// Receive one byte form client to host 
extern kal_uint8 ms_i2c_receive_byte(kal_bool bAck);

// I2C send data fuction
extern kal_bool ms_i2c_send(kal_uint8 ucDeviceAddr, kal_uint8 ucBufferIndex, kal_uint8* pucData, kal_uint32 unDataLength);

// I2C receive data function
extern kal_bool ms_i2c_receive(kal_uint8 ucDeviceAddr, kal_uint8 ucBufferIndex, kal_uint8* pucData, kal_uint32 unDataLength);

// I2C send data for 16 bits address fuction
extern kal_bool ms_i2c_send_ext(kal_uint8 ucDeviceAddr, kal_uint16 ucBufferIndex, kal_uint8* pucData, kal_uint32 unDataLength);

// I2C receive data for 16 bits address function
extern kal_bool ms_i2c_receive_ext(kal_uint8 ucDeviceAddr, kal_uint16 ucBufferIndex, kal_uint8* pucData, kal_uint32 unDataLength);

void track_drv_delay_1ms(kal_uint16 ms);

#endif  /* _TRACK_SENSOR_IIC_H */

#endif /* __TRACK_SENSOR__ */
