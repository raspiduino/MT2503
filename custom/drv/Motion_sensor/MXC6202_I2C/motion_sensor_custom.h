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

/* I2C slave address for MXC6202 series. */
#if defined(MXC62020)
	#define MXC6202_I2C_SLAVE_ADDR      0x20  /* MXC62020 */
#elif defined(MXC62021)
 	#define MXC6202_I2C_SLAVE_ADDR      0x22  /* MXC62021 */
#elif defined(MXC62022)
	#define MXC6202_I2C_SLAVE_ADDR      0x24  /* MXC62022 */
#elif defined(MXC62023)
	#define MXC6202_I2C_SLAVE_ADDR      0x26  /* MXC62023 */
#elif defined(MXC62024)
	#define MXC6202_I2C_SLAVE_ADDR      0x28  /* MXC62024 */
#elif defined(MXC62025)
	#define MXC6202_I2C_SLAVE_ADDR      0x2A  /* MXC62025 */
#elif defined(MXC62026)
	#define MXC6202_I2C_SLAVE_ADDR      0x2C  /* MXC62026 */
#elif defined(MXC62027)
	#define MXC6202_I2C_SLAVE_ADDR      0x2E  /* MXC62027 */
#endif

#define ACC_0G_X      (2059) 
#define ACC_1G_X      (2059+512)
#define ACC_MINUS1G_X (2059-512)
#define ACC_0G_Y      (2059)
#define ACC_1G_Y      (2059+512)
#define ACC_MINUS1G_Y (2059-512)
#define ACC_0G_Z      (0)
#define ACC_1G_Z      (0)
#define ACC_MINUS1G_Z (0)

extern void acc_sensor_pwr_up(void);
extern void acc_sensor_pwr_down(void);
extern void acc_sensor_get_5bytes(kal_uint16 *x_adc, kal_uint16 *y_adc, kal_uint16 *z_adc);
extern void acc_sensor_init(void);
extern void acc_test_cb(void *parameter, Motion_Sensor_BuffState_enum state);
extern MotionSensor_customize_function_struct *ms_GetFunc(void);
extern MotionSensor_custom_data_struct *ms_get_data(void);
extern kal_bool mxc6202_query_gesture(kal_uint16 ms_gest_type);
extern kal_bool mxc6202_get_sensor_params(kal_uint16 ms_params_type, MotionSensorQueryStruct *ms_params);


#endif
