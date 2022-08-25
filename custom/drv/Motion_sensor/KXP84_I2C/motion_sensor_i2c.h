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
 *    serial_interface.c
 *
 * Project:
 * --------
 *   Maui_Software
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
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MOTION_SENSOR_I2C_H
#define MOTION_SENSOR_I2C_H

//For motion sensor I2C pins
extern const char gpio_ms_i2c_addr_pin;
extern const char gpio_ms_i2c_clk_pin;
extern const char gpio_ms_i2c_data_pin;
extern const char gpio_ms_i2c_cs_pin;
extern const char gpio_ms_i2c_reset_pin;

/*GPIO for KXP I2C interface*/
#define MS_I2C_ADDR_PIN           gpio_ms_i2c_addr_pin
#define MS_I2C_CLK_PIN            gpio_ms_i2c_clk_pin
#define MS_I2C_DATA_PIN           gpio_ms_i2c_data_pin
#define MS_I2C_CS_PIN             gpio_ms_i2c_cs_pin
#define MS_I2C_RESET_PIN          gpio_ms_i2c_reset_pin

#define SET_MS_CLK_OUTPUT		GPIO_InitIO(OUTPUT,MS_I2C_CLK_PIN);
#define SET_MS_DATA_OUTPUT		GPIO_InitIO(OUTPUT,MS_I2C_DATA_PIN);
#define SET_MS_DATA_INPUT		GPIO_InitIO(INPUT,MS_I2C_DATA_PIN);
#define SET_MS_CLK_HIGH			GPIO_WriteIO(1,MS_I2C_CLK_PIN);
#define SET_MS_CLK_LOW			GPIO_WriteIO(0,MS_I2C_CLK_PIN);
#define SET_MS_DATA_HIGH		GPIO_WriteIO(1,MS_I2C_DATA_PIN);
#define SET_MS_DATA_LOW			GPIO_WriteIO(0,MS_I2C_DATA_PIN);
#define GET_MS_DATA_BIT			GPIO_ReadIO(MS_I2C_DATA_PIN)

#define MS_DELAY				1

#define MS_RESTART_TRANSMISSION()	\
{\
	kal_uint16 i;\
	SET_MS_DATA_OUTPUT;\
   SET_MS_DATA_HIGH;\
   SET_MS_CLK_HIGH;\
   SET_MS_DATA_LOW;\
   for (i=0;i<MS_DELAY;i++);\
	SET_MS_CLK_LOW;\
	for (i=0;i<MS_DELAY;i++);\
}

#define MS_START_TRANSMISSION()	\
{\
	kal_uint16 i;\
	SET_MS_DATA_OUTPUT;\
   SET_MS_DATA_LOW;\
   for (i=0;i<MS_DELAY;i++);\
	SET_MS_CLK_LOW;\
	for (i=0;i<MS_DELAY;i++);\
}

#define MS_STOP_TRANSMISSION()	\
{\
	kal_uint16 i;\
	SET_MS_DATA_OUTPUT;\
	SET_MS_DATA_LOW;\
	for (i=0;i<MS_DELAY;i++);\
   SET_MS_CLK_HIGH;\
   for (i=0;i<MS_DELAY;i++);\
	SET_MS_DATA_HIGH;\
	for (i=0;i<MS_DELAY;i++);\
}

void motion_sensor_write_data(kal_uint8 data, kal_uint8 addr);
void motion_senosr_serial_init(void);
void motion_sensor_send_byte(kal_uint8 send_byte);
kal_uint8 motion_sensor_get_byte(void);
kal_uint16 motion_sensor_read_control(kal_uint8 addr);
kal_uint16 motion_sensor_read_data(kal_uint8 addr);
void motion_sensor_delay(kal_uint32 delay);

#endif
