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
 *   Capacitive_TP_Cypress_CY8CTMA340.h
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "Capacitive_TP_I2C.h"

#define CTP_I2C_LDO         VCAMD //MT6276E2 use VACMA, MT6276E1 use VCAMD
#define CTP_I2C_LDO_VOLTAGE PMU_VOLT_02_800000_V
#define CTP_SLAVE_ADDR	    0x70

//Controller parameter getting/setting flag
#define CTP_RESOLUTION 0x1
#define CTP_THRESHOLD 0x2
#define CTP_IDLE_INTERVAL 0x4
#define CTP_SLEEP_INTERVAL 0x8
//#define CTP_DATA_MODE 0x10
//#define CTP_GESTURE_DISTANCE 0x20
//#define CTP_CHANGE_STATE_DELAY 0x40
//#define CTP_CALIBRATION 0x80

//Controller Mode
#define CTP_NORMAL_OPERATION 0x0B
#define CTP_SYSTEM_INFORMATION 0x1B
#define CTP_ACTIVE_MODE 0x4B


#define CTP_IDLE_MODE 0x8
#define CTP_SLEEP_MODE 0x10
#define CTP_DEBUG_MODE 0x1B

#define CTP_GESTURE_DETECTION_MODE 0x40
#define CTP_MULTIPLE_POINT_MODE 0x80



//#define CTP_SLAVE_ADDR		0xCE

//ADDRESS
#define HST_MODE_ADDR 0x0  
//DATA 
#define HST_MODE_NORMAL 0x1B   
#define HST_MODE_SYSTEM_INFORMATION 0x1B
#define HST_MODE_TEST  0X4B

#define GEST_ID_ADDR 0x1  
#define GEST_ID_NUMBER 0xFF  

#define TD_STAT_ADDR 0x2
#define TD_STAT_NUMBER_TOUCH 0x07
#define TT_MODE_BUFFER_INVALID 0x08//1-5 VALIDE

/*
#define TT_MODE_ADDR 0x1
#define TT_MODE_BUFFER_INVALID 0x20

#define TT_STAT_ADDR 0x2
#define TT_STAT_NUMBER_TOUCH 0xF
*/
#define TOUCH1_XH_ADDR 0x03
#define TOUCH1_EVEN_FLAG 0xC0
#define TOUCH1_XL_ADDR 0x4
#define TOUCH1_YH_ADDR 0x5
#define TOUCH1_ID 0xF0
#define TOUCH1_YL_ADDR 0x6


//#define TOUCH1_Z_ADDR  0x7

#define TOUCH2_XH_ADDR 0x09
#define TOUCH2_EVEN_FLAG 0xC0
#define TOUCH2_XL_ADDR 0xA
#define TOUCH2_YH_ADDR 0xB
#define TOUCH2_ID 0xF0
#define TOUCH2_YL_ADDR 0xC
//#define TOUCH2_Z_ADDR  0xD

#define TOUCH3_XH_ADDR 0x0F
#define TOUCH3_EVEN_FLAG 0xC0
#define TOUCH3_XL_ADDR 0x10
#define TOUCH3_YH_ADDR 0x11
#define TOUCH3_ID 0xF0
#define TOUCH3_YL_ADDR 0x12
//#define TOUCH3_Z_ADDR  0x14

#define TOUCH4_XH_ADDR 0x15
#define TOUCH4_EVEN_FLAG 0xC0
#define TOUCH4_XL_ADDR 0x16
#define TOUCH4_YH_ADDR 0x17
#define TOUCH4_ID 0xF0
#define TOUCH4_YL_ADDR 0x18
//#define TOUCH4_Z_ADDR  0x1A

#define TOUCH5_XH_ADDR 0x1B
#define TOUCH5_EVEN_FLAG 0xC0
#define TOUCH5_XL_ADDR 0x1C
#define TOUCH5_YH_ADDR 0x1D
#define TOUCH5_ID 0xF0
#define TOUCH5_YL_ADDR 0x1E



#define CTP_BL_FILE          0
#define CTP_BL_CMD           0xFF
#define CTP_BL_EXIT          0xA5
#define CTP_BL_SECUTITY_KEY1 0x0
#define CTP_BL_SECUTITY_KEY2 0x1
#define CTP_BL_SECUTITY_KEY3 0x2
#define CTP_BL_SECUTITY_KEY4 0x3
#define CTP_BL_SECUTITY_KEY5 0x4
#define CTP_BL_SECUTITY_KEY6 0x5
#define CTP_BL_SECUTITY_KEY7 0x6
#define CTP_BL_SECUTITY_KEY8 0x7
#define ACT_INTRVL_ADDR  0x1D

//need 80us to turn on vcamd
#define CTP_USE_SW_I2C
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

#define CTP_I2C_DELAY_FT											50//200//500
//#define CTP_I2C_DATA_PIN										2
//#define CTP_I2C_CLK_PIN											9
/*software i2c gpio setting*/
/*reset pin*/
extern const char gpio_ctp_reset_pin ;
#define CTP_RESET_PIN	gpio_ctp_reset_pin

extern const char gpio_ctp_i2c_scl_pin;
extern const char gpio_ctp_i2c_sda_pin;
#define CTP_I2C_DATA_PIN	gpio_ctp_i2c_sda_pin 
#define CTP_I2C_CLK_PIN		gpio_ctp_i2c_scl_pin 
#define GPIO_CTP_I2C_SDA_PIN  CTP_I2C_DATA_PIN
#define GPIO_CTP_I2C_SCL_PIN  CTP_I2C_CLK_PIN

#define OUTPUT 1
#define INPUT 0

#define CTP_WRITE             				0x70
#define CTP_READ             					0x71
#define CTP_ACK_COUNTER        			10//150

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
		for(j=0;j<CTP_I2C_DELAY_FT;j++);\
		CTP_SET_I2C_DATA_LOW; \
		for(j=0;j<CTP_I2C_DELAY_FT;j++);\
		CTP_SET_I2C_CLK_LOW; \
	}

	#define CTP_I2C_STOP_BIT \
	{ \
		volatile kal_uint32 j; \
		CTP_SET_I2C_CLK_OUTPUT; \
		CTP_SET_I2C_DATA_OUTPUT; \
		CTP_SET_I2C_CLK_LOW; \
		CTP_SET_I2C_DATA_LOW; \
		for(j=0;j<CTP_I2C_DELAY_FT;j++);\
		CTP_SET_I2C_CLK_HIGH; \
		for(j=0;j<CTP_I2C_DELAY_FT;j++);\
		CTP_SET_I2C_DATA_HIGH; \
		for(j=0;j<CTP_I2C_DELAY_FT;j++);\
	}
#endif //SW_I2CS


typedef struct
{   
   kal_uint32 mode;
}CTP_device_mode_struct;

typedef struct
{   
	kal_uint32 start_offset;
	kal_uint32 write_flash_pointer;
	kal_uint32 read_flash_pointer;
	kal_uint32 value;
}CTP_firmware_struct;
