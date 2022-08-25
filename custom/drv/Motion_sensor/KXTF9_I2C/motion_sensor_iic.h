/*****************************************************************************
 *
 * Filename:
 * ---------
 *    Motion_sensor_iic.h
 *
 * Project:
 * --------
 *    Motion Sensor KTXF9 I2C Interface
 *
 * Description:
 * ------------
 *   This Module defines Serial Interface.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 ****************************************************************************/

#ifndef MOTION_SENSOR_I2C_H
#define MOTION_SENSOR_I2C_H

#ifdef __CUST_NEW__
	extern const char gpio_ms_i2c_data_pin;
	extern const char gpio_ms_i2c_clk_pin;
	#define MS_I2C_CLK_PIN	gpio_ms_i2c_clk_pin		//define GPIO7 for i2c CLK Singal
	#define MS_I2C_DATA_PIN  gpio_ms_i2c_data_pin		//define GPIO6 for i2c DATA Singal
#else
	#define MS_I2C_CLK_PIN  7		//define GPIO7 for i2c CLK Singal
	#define MS_I2C_DATA_PIN  6  	//define GPIO6 for i2c DATA Singal
#endif

#define SET_MS_CLK_OUTPUT		GPIO_InitIO(OUTPUT,MS_I2C_CLK_PIN);
#define SET_MS_DATA_OUTPUT		GPIO_InitIO(OUTPUT,MS_I2C_DATA_PIN);
#define SET_MS_DATA_INPUT		GPIO_InitIO(INPUT,MS_I2C_DATA_PIN);
#define SET_MS_CLK_HIGH			GPIO_WriteIO(1,MS_I2C_CLK_PIN);
#define SET_MS_CLK_LOW			GPIO_WriteIO(0,MS_I2C_CLK_PIN);
#define SET_MS_DATA_HIGH		GPIO_WriteIO(1,MS_I2C_DATA_PIN);
#define SET_MS_DATA_LOW			GPIO_WriteIO(0,MS_I2C_DATA_PIN);
#define GET_MS_DATA				GPIO_ReadIO(MS_I2C_DATA_PIN)

#define MS_DELAY				1


void MS_Delay(kal_uint16 time);
void I2C_Start(void);
void I2C_Restart(void);
void I2C_Stop(void);
void motion_senosr_interface_init(void);
void motion_sensor_send_byte(kal_uint8 send_byte);
kal_uint8 motion_sensor_get_byte(void);
kal_uint16 motion_sensor_read_acc_data(kal_uint8 addr);
kal_uint8 motion_sensor_read_data(kal_uint8 addr);
void motion_sensor_write_data(kal_uint8 data, kal_uint8 addr);

#endif
