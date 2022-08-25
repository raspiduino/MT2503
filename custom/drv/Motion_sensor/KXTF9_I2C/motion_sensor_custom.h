/*****************************************************************************
 *
 * Filename:
 * ---------
 *    Motion_sensor_custom.c
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
#ifndef _MOTION_SENSOR_CUSTOM_H
#define _MOTION_SENSOR_CUSTOM_H

/*KXTF9 8bit register*/
#define  MOTION_SENSOR_XOUT_HPF_L   0x00
#define  MOTION_SENSOR_XOUT_HPF_H   0x01
#define  MOTION_SENSOR_YOUT_HPF_L   0x02
#define  MOTION_SENSOR_YOUT_HPF_H   0x03
#define  MOTION_SENSOR_ZOUT_HPF_L	0x04
#define  MOTION_SENSOR_ZOUT_HPF_H	0x05
#define  MOTION_SENSOR_XOUT_L    	0x06
#define  MOTION_SENSOR_XOUT_H    	0x07
#define  MOTION_SENSOR_YOUT_L    	0x08
#define  MOTION_SENSOR_YOUT_H    	0x09
#define  MOTION_SENSOR_ZOUT_L    	0x0A
#define  MOTION_SENSOR_ZOUT_H    	0x0B

#define  MOTION_SENSOR_CTRL_REGA 	0x1b
#define  MOTION_SENSOR_CTRL_REGB 	0x1c
#define  MOTION_SENSOR_CTRL_REGC 	0x1d

#define  MOTION_SENSOR_INT_CTRL_REG1 0x1e
#define  MOTION_SENSOR_INT_CTRL_REG2 0x1f
#define  MOTION_SENSOR_INT_CTRL_REG3 0x20

#define  MOTION_SENSOR_WUF_TIMER 	0x29
#define  MOTION_SENSOR_WUF_THRESH 	0x5A

/*kxtf9 slave address and read write bit*/
#define MOTION_SENSOR_ADDRESS    	0x1e
#define MOTION_SENSOR_READ       	0x1
#define MOTION_SENSOR_WRITE      	0x0

/*interrupt configuration*/
#define MOTION_SENSOR_INT_SUPPORT   KAL_FALSE
#define MOTION_SENSOR_INT           4
#define MOTION_SENSOR_INT_LEVEL     LEVEL_HIGH
#define MOTION_SENSOR_LOW_G_MASK    0x1
#define MOTION_SENSOR_HIGH_G_MASK   0x2

/*KXTF9 12bit acceleration*/
#define ACC_0G_X      (2048)
#define ACC_1G_X      (2048+256)
#define ACC_MINUS1G_X (2048-256)
#define ACC_0G_Y      (2048)    
#define ACC_1G_Y      (2048+256)
#define ACC_MINUS1G_Y (2048-256)
#define ACC_0G_Z      (2048)    
#define ACC_1G_Z      (2048+256)
#define ACC_MINUS1G_Z (2048-256)

/*function*/
void acc_sensor_read_int_status(kal_bool *low_g, kal_bool *high_g);
void acc_sensor_clear_int_status(void);
void acc_sensor_get_acc(kal_uint16 *x_adc, kal_uint16 *y_adc, kal_uint16 *z_adc);
void acc_sensor_pwr_up(void);
void acc_sensor_pwr_down(void);
void acc_sensor_configure_low_g(kal_uint32 debounce, kal_uint32 threshold);
void acc_sensor_configure_high_g(kal_uint32 debounce, kal_uint32 threshold);
void acc_sensor_init(void);
MotionSensor_custom_data_struct *ms_get_data(void);
MotionSensor_customize_function_struct *ms_GetFunc(void);
extern kal_bool KXTF9_query_gesture(kal_uint16 ms_gest_type);
extern kal_bool KXTF9_get_sensor_params(kal_uint16 ms_params_type, MotionSensorQueryStruct *ms_params);
#endif
