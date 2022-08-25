/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    motion_sensor_custom.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module is for motion sensor driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MOTION_SENSOR_CUSTOM_H
#define _MOTION_SENSOR_CUSTOM_H

#define XOUTL           0x00
#define XOUTH           0x01
#define YOUTL           0x02
#define YOUTH           0x03
#define ZOUTL           0x04
#define ZOUTH           0x05
#define XOUT8           0x06
#define YOUT8           0x07
#define ZOUT8           0x08
#define STATUS          0x09
#define DETSRC          0x0A
#define TOUT            0x0B
#define I2CAD           0x0D
#define USRINF          0x0E
#define WHOAMI          0x0F
#define XOFFL           0x10
#define XOFFH           0x11
#define YOFFL           0x12
#define YOFFH           0x13
#define ZOFFL           0x14
#define ZOFFH           0x15
#define MCTL            0x16
#define INTRST          0x17
#define CTL1            0x18
#define CTL2            0x19
#define LDTH            0x1A
#define PDTH            0x1B
#define PW              0x1C
#define LT              0x1D
#define TW              0x1E

//For motion sensor MEMSIC serial interface: motion_sensor_hw_define.h
extern const char gpio_acc_sensor_sck_pin;
extern const char gpio_acc_sensor_sda_pin;

/*GPIO for MEMSIC serial interface*/
#define ACC_SENSOR_SCK         gpio_acc_sensor_sck_pin
#define ACC_SENSOR_SDA         gpio_acc_sensor_sda_pin

#define SET_I2C_CLK_OUTPUT		   GPIO_InitIO(OUTPUT,ACC_SENSOR_SCK);
#define SET_I2C_DATA_OUTPUT		GPIO_InitIO(OUTPUT,ACC_SENSOR_SDA);
#define SET_I2C_DATA_INPUT		   GPIO_InitIO(INPUT,ACC_SENSOR_SDA);
#define SET_I2C_CLK_HIGH			GPIO_WriteIO(1,ACC_SENSOR_SCK);
#define SET_I2C_CLK_LOW			   GPIO_WriteIO(0,ACC_SENSOR_SCK);
#define SET_I2C_DATA_HIGH			GPIO_WriteIO(1,ACC_SENSOR_SDA);
#define SET_I2C_DATA_LOW			GPIO_WriteIO(0,ACC_SENSOR_SDA);
#define GET_I2C_DATA_BIT			GPIO_ReadIO(ACC_SENSOR_SDA)

#define ACC_0G_X      (2048+22) 
#define ACC_1G_X      (2048+83)
#define ACC_MINUS1G_X (2048+22-61)
#define ACC_0G_Y      (2048+2)
#define ACC_1G_Y      (2048+68)
#define ACC_MINUS1G_Y (2048+2-66)
#define ACC_0G_Z      (2048)
#define ACC_1G_Z      (2048+61)
#define ACC_MINUS1G_Z (2048-61)


typedef struct {
  kal_uint16  X;
  kal_uint16  Y;
  kal_uint16  Z;  
} SPARAMETERS;

void Calibration_XYZ(void);
void Sample_n_Times(kal_uint8 n, kal_uint16 *pX, kal_uint16 *pY, kal_uint16 *pZ);
kal_uint8 Data_Is_Ready(void);

extern void mma745x_init(void);										// IIC hardware init
extern void mma745x_ReadXYZ10(kal_uint16 *X, kal_uint16 *Y, kal_uint16 *Z);		// Read 10bit XYZ

void mma745x_IICWrite(kal_uint8 RegAdd, kal_uint8 Data);			// Write 1 byte
kal_int8 mma745x_IICRead(kal_uint8 RegAdd);						// Read 1 byte
void mma745x_ReadXYZ8(kal_int8 *X, kal_int8 *Y, kal_int8 *Z);		// Read 8bit XYZ 

extern void acc_sensor_pwr_up(void);
extern void acc_sensor_pwr_down(void);
extern void acc_sensor_get_5bytes(kal_uint16 *x_adc, kal_uint16 *y_adc, kal_uint16 *z_adc);
extern void acc_sensor_init(void);
extern void acc_test_cb(void *parameter, Motion_Sensor_BuffState_enum state);
extern MotionSensor_customize_function_struct *ms_GetFunc(void);
extern MotionSensor_custom_data_struct *ms_get_data(void);
extern kal_bool mma745_query_gesture(kal_uint16 ms_gest_type);
extern kal_bool mma745_get_sensor_params(kal_uint16 ms_params_type, MotionSensorQueryStruct *ms_params);
#endif
