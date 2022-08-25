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


#ifdef __CUST_NEW__
extern const char gpio_ms_i2c_clk_pin;
extern const char gpio_ms_i2c_data_pin;

#define MS_SCL	gpio_ms_i2c_clk_pin
#define MS_SDA	gpio_ms_i2c_data_pin

#else	//__CUST_NEW__
#define MS_SCL	55
#define	MS_SDA	56
#endif	//__CUST_NEW__

/******************************************************
	Motion sensor controller register macro define
*******************************************************/
#define MS_CHIP_ID		0x00
#define MS_ACC_REG		0x04
#define MS_LPWR_CON		0x1E
#define MS_RANGE_REG	0x22
#define MS_SUSPEND_REG	0x30
#define MS_SWRST_REG	0x32

/******************************************************
	Motion sensor controller bit macro define
*******************************************************/
#define SLEEP_EN_BIT		0x40
#define	X_CHANNEL_EN_BIT	0x04
#define Y_CHANNEL_EN_BIT	0x02
#define Z_CHANNEL_EN_BIT	0x01

/******************************************************
	Motion sensor controller others macro define
*******************************************************/
/*sleep during macro define*/
#define	PWR_ON_SLEEP_DUR	0x00			//sleep dur is 2ms
#define PWR_OFF_SLEEP_DUR	0x10			//sleep dur is 25ms
#define SLEEP_ENABLE		0x40
#define SLEEP_DISABLE		0x00
/*channel enable macro define*/
#define XYZ_CHANNEL_EN		0x07
#define X_CHANNEL_EN		0x04
#define Y_CHANNEL_EN		0x02
#define Z_CHANNEL_EN		0x01
#define XYZ_CHANNEL_DISABLE	0xF8
#define X_CHANNEL_DISABLE	0xFB
#define Y_CHANNEL_DISABLE	0xFD
#define Z_CHANNEL_DISABLE	0xFE
/*range setting macro define*/
#define BMA220_RANGE_2G		0x00
#define BMA220_RANGE_4G		0x01
#define BMA220_RANGE_8G		0x02
#define BMA220_RANGE_16G	0x03

/******************************************************
	I2C header (slaver address|W/R)   macro define
*******************************************************/
#define MS_SLAVEADDR_W	0x16	//0x0001 0110
#define MS_SLAVEADDR_R	0x17	//0x0001 0111

/******************************************************
	GPIO macro define for software I2C
*******************************************************/
#define MS_CLK_PIN_GPIO_MODE		GPIO_ModeSetup(MS_SCL,0)
#define	MS_DATA_PIN_GPIO_MODE		GPIO_ModeSetup(MS_SDA,0)
#define MS_I2C_CLK_OUTPUT			GPIO_InitIO(OUTPUT,MS_SCL)
#define MS_I2C_DATA_OUTPUT			GPIO_InitIO(OUTPUT,MS_SDA)
#define MS_I2C_DATA_INPUT		   	GPIO_InitIO(INPUT,MS_SDA)
#define MS_I2C_CLK_HIGH				GPIO_WriteIO(1,MS_SCL)
#define MS_I2C_CLK_LOW				GPIO_WriteIO(0,MS_SCL)
#define MS_I2C_DATA_HIGH			GPIO_WriteIO(1,MS_SDA)
#define MS_I2C_DATA_LOW				GPIO_WriteIO(0,MS_SDA)
#define MS_I2C_GET_BIT				GPIO_ReadIO(MS_SDA)


/*****************************************************
	ADC value configure of 0g 1g and -1g in X,Y,Z axis
******************************************************/				
#define ACC_0G_X      (2048) 			
#define ACC_1G_X      (2048+(15<<6))
#define ACC_MINUS1G_X (2048-(15<<6))
#define ACC_0G_Y      (2048)
#define ACC_1G_Y      (2048+(15<<6))
#define ACC_MINUS1G_Y (2048-(15<<6))
#define ACC_0G_Z      (2048)
#define ACC_1G_Z      (2048+(15<<6))
#define ACC_MINUS1G_Z (2048-(15<<6))


/******************************************************
	Global struct variable
*******************************************************/
typedef struct {
  kal_uint16  X;
  kal_uint16  Y;
  kal_uint16  Z;  
} SPARAMETERS;


extern MotionSensor_customize_function_struct *ms_GetFunc(void);

/*
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
*/

#endif	//_MOTION_SENSOR_CUSTOM_H