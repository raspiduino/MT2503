/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *   Capacitive_TP_Goodix_GT818.h
 *
 *
 * Description:
 * ------------
 *   Capacitive Touch Panel I2C read/write Driver header file
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
 *****************************************************************************/
#include "Capacitive_TP_I2C.h"
 
#define CTP_SLAVE_ADDR            0xBA
#define CTP_CONFIG_REG_BASE       0x6A2
#define CTP_TOUCH_CHI_ID_REG_BASE   0x710
#define CTP_TOUCH_INFO_REG_BASE   0x712
#define CTP_TOUCH_KEY_REG_BASE   0x721
#define CTP_POINT_INFO_REG_BASE   0x722
#define CTP_VERSION_INFO_REG      0x713
#define CTP_POWER_MODE_REG        0x692
#define CTP_HANDSHAKING_START_REG 0xFFF
#define CTP_HANDSHAKING_END_REG   0x8000
#define CTP_SOFT_RESET_MODE       0x01
#define CTP_POINT_INFO_LEN        8
#define CTP_X_RES                 480
#define CTP_Y_RES                 800
#define TPD_MAX_POINTS            5
#define MAX_TRANSACTION_LENGTH    8
#define I2C_DEVICE_ADDRESS_LEN    2
extern const char gpio_ctp_reset_pin ;
#define CTP_RESET_PIN	gpio_ctp_reset_pin
/*software i2c gpio setting*/
extern const char gpio_ctp_i2c_scl_pin;
extern const char gpio_ctp_i2c_sda_pin;
#define CTP_I2C_DATA_PIN	gpio_ctp_i2c_sda_pin 
#define CTP_I2C_CLK_PIN		gpio_ctp_i2c_scl_pin 
#define GPIO_CTP_I2C_SDA_PIN  CTP_I2C_DATA_PIN
#define GPIO_CTP_I2C_SCL_PIN  CTP_I2C_CLK_PIN

#define CTP_STAT_NUMBER_TOUCH     0xF
//#define GPIO_CTP_INT_PIN          (52|0x80)
//#define GPIO_CTP_SHUTDN_PIN       (44|0x80)
//#define GPIO_CTP_EINT_NO          4


#if 1//def NEED_RESET_PIN
/**********************************************************************/
/*		Macro definition for CTP reset pin									   */
/**********************************************************************/
/*gpio83 ==> reset pin*/
//#define CTP_RESET_PIN				92
/*reset pin operation setting*/
#define CTP_SET_RESET_PIN_OUTPUT			GPIO_InitIO(OUTPUT, CTP_RESET_PIN)
#define CTP_SET_RESET_PIN_HIGH				GPIO_WriteIO(1, CTP_RESET_PIN)
#define CTP_SET_RESET_PIN_LOW				GPIO_WriteIO(0, CTP_RESET_PIN)
#endif	// NEED_RESET_PIN
#if 1//defined(CTP_USE_SW_I2C)

//#define CTP_I2C_DELAY_GT											100//500
//#define CTP_I2C_DATA_PIN										57
//#define CTP_I2C_CLK_PIN											56

#define CTP_I2C_DELAY_GT											100//500
//#define CTP_I2C_DATA_PIN										2
//#define CTP_I2C_CLK_PIN											9

#define OUTPUT 1
#define INPUT 0

#define CTP_WRITE             				0xBA
#define CTP_READ             					0xBB
#define CTP_ACK_COUNTER        			150

#ifndef __CUST_NEW__
#define CTP_SET_I2C_CLK_OUTPUT				GPIO_InitIO_FAST(OUTPUT,CTP_I2C_CLK_PIN)
#define CTP_SET_I2C_DATA_OUTPUT			GPIO_InitIO_FAST(OUTPUT,CTP_I2C_DATA_PIN)
#define CTP_SET_I2C_DATA_INPUT				GPIO_InitIO_FAST(INPUT,CTP_I2C_DATA_PIN)
#define CTP_SET_I2C_CLK_HIGH				GPIO_WriteIO_FAST(1,CTP_I2C_CLK_PIN)
#define CTP_SET_I2C_CLK_LOW			       GPIO_WriteIO_FAST(0,CTP_I2C_CLK_PIN)

#define CTP_GET_I2C_CLK_BIT					GPIO_ReadIO_FAST(CTP_I2C_CLK_PIN)
#define CTP_SET_I2C_CLK_INPUT				GPIO_InitIO_FAST(INPUT,CTP_I2C_CLK_PIN)

#define CTP_SET_I2C_DATA_HIGH				GPIO_WriteIO_FAST(1,CTP_I2C_DATA_PIN)
#define CTP_SET_I2C_DATA_LOW				GPIO_WriteIO_FAST(0,CTP_I2C_DATA_PIN)
#define CTP_GET_I2C_DATA_BIT				GPIO_ReadIO_FAST(CTP_I2C_DATA_PIN)
#else
#define CTP_SET_I2C_CLK_OUTPUT				GPIO_InitIO(OUTPUT,CTP_I2C_CLK_PIN)
#define CTP_SET_I2C_DATA_OUTPUT			GPIO_InitIO(OUTPUT,CTP_I2C_DATA_PIN)
#define CTP_SET_I2C_DATA_INPUT				GPIO_InitIO(INPUT,CTP_I2C_DATA_PIN)
#define CTP_SET_I2C_CLK_HIGH				GPIO_WriteIO(1,CTP_I2C_CLK_PIN)
#define CTP_SET_I2C_CLK_LOW				GPIO_WriteIO(0,CTP_I2C_CLK_PIN)

#define CTP_GET_I2C_CLK_BIT					GPIO_ReadIO(CTP_I2C_CLK_PIN)
#define SET_I2C_CLK_INPUT					GPIO_InitIO(INPUT,CTP_I2C_CLK_PIN)

#define CTP_SET_I2C_DATA_HIGH				GPIO_WriteIO(1,CTP_I2C_DATA_PIN)
#define CTP_SET_I2C_DATA_LOW				GPIO_WriteIO(0,CTP_I2C_DATA_PIN)
#define CTP_GET_I2C_DATA_BIT				GPIO_ReadIO(CTP_I2C_DATA_PIN)
#endif

#define CTP_I2C_START_BIT \
	{ \
		volatile kal_uint32 j; \
		CTP_SET_I2C_CLK_OUTPUT; \
		CTP_SET_I2C_DATA_OUTPUT; \
		CTP_SET_I2C_CLK_HIGH; \
		CTP_SET_I2C_DATA_HIGH; \
		for(j=0;j<CTP_I2C_DELAY_GT;j++);\
		CTP_SET_I2C_DATA_LOW; \
		for(j=0;j<CTP_I2C_DELAY_GT;j++);\
		CTP_SET_I2C_CLK_LOW; \
	}

	#define CTP_I2C_STOP_BIT \
	{ \
		volatile kal_uint32 j; \
		CTP_SET_I2C_CLK_OUTPUT; \
		CTP_SET_I2C_DATA_OUTPUT; \
		CTP_SET_I2C_CLK_LOW; \
		CTP_SET_I2C_DATA_LOW; \
		for(j=0;j<CTP_I2C_DELAY_GT;j++);\
		CTP_SET_I2C_CLK_HIGH; \
		for(j=0;j<CTP_I2C_DELAY_GT;j++);\
		CTP_SET_I2C_DATA_HIGH; \
		for(j=0;j<CTP_I2C_DELAY_GT;j++);\
	}
#endif //SW_I2CS


typedef struct 
{
    kal_uint8 vendor_id_1;
    kal_uint8 vendor_id_2;
    kal_uint8 product_id_1;
    kal_uint8 product_id_2;
    kal_uint8 version_1;
    kal_uint8 version_2;
} ctp_info_t;
