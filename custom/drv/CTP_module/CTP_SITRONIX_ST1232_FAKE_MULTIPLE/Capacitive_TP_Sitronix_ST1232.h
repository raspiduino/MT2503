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
 *   Capacitive_TP_Sitronix_ST1232.h
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
#ifndef	ST1232_H
#define	ST1232_H

#include "gpio_sw.h"
#include "touch_panel_custom.h"


/*****************************************************************************/
/* 		Macro switch for I2C and Firmware updating feature							  */
/*																			  */
/*****************************************************************************/
/*define sw_I2C or hw_I2C for ctp */
//#define SW_I2C

/*define the macro for updating firmware*/
#define FW_UPDATE

/*****************************************************************************/
/* 		Macro definition for capacitive touch panel of SITRONIX ST1232				  */
/*																			  */
/*****************************************************************************/
/*Macro definition of the CTP controller parameter getting/setting flag*/
#define RESOLUTION_PARA	0x01
#define THRESHOLD_PARA	0x02
#define	IDLE_INTERVAL_PARA	0x04
#define	SLEEP_INTERVAL_PARA 0x08
#define DATAMODE_PARA	0x10
#define PROXIMITY_PARA	0x20
#define	GESTURE_PARA	0x40

/*Macro definition of the CTP controller register*/
#define REG_VER_ADDR	0x00
#define REG_STAT_ADDR	0x01
#define REG_CON_ADDR	0x02
#define	REG_IDLE_ADDR	0x03

#define RES_XY_ADDR		0x04
#define	RES_X_L_ADDR	0x05
#define RES_Y_L_ADDR	0x06

#define DRIFT_TH_ADDR	0x07

#define TOUCH0_XY_ADDR	0x12
#define TOUCH0_XL_ADDR	0x13
#define TOUCH0_YL_ADDR	0x14
#define TOUCH_Z0_ADDR	0x18

#define TOUCH1_XY_ADDR	0x15
#define TOUCH1_XL_ADDR	0x16
#define TOUCH1_YL_ADDR 	0x17
#define TOUCH_Z1_ADDR	0x19

#define TOUCH_VALID_FLAG	0x80
#define DEV_STAT_FLAG	0x0F

/*Macro definition of CTP controller mode*/
#define CTP_NORMAL_OPERATION 	0x01
#define CTP_ACTIVE_MODE 0x02
#define CTP_IDLE_MODE	0x04
#define CTP_SLEEP_MODE 	0x08
#define CTP_POWEROFF_MODE 		0x10
#define CTP_DEBUG_MODE 	0x20
#define CTP_GESTURE_DETECTION_MODE 	0x40
#define CTP_MULTIPLE_POINT_MODE 	0x80

/**/
#define IDLE_ENABLE 	0x0C
#define IDLE_DISABLE 	0x08
#define DEFAULT_IDLE_TIMEOUT	0x08

/*CTP controller device address*/
#define CTP_SLAVE_ADDR	0xAA	//0x55<<1	
#define DEFAULT_RES_X	2048
#define DEFAULT_RES_Y	2048


/*****************************************************************************/
/* 		Macro definition for software I2C of the capacitive touch panel      				  */
/*																			  */
/*****************************************************************************/
#ifdef SW_I2C
/*software i2c gpio setting*/
#define CTP_I2C_DATA_PIN			81
#define CTP_I2C_CLK_PIN				82

/*software i2c clk & data pin operation setting*/
#ifndef __CUST_NEW__
#define CTP_SET_I2C_CLK_OUTPUT				GPIO_InitIO_FAST(OUTPUT, CTP_I2C_CLK_PIN)
#define CTP_SET_I2C_DATA_OUTPUT				GPIO_InitIO_FAST(OUTPUT, CTP_I2C_DATA_PIN)
#define CTP_SET_I2C_DATA_INPUT				GPIO_InitIO_FAST(INPUT, CTP_I2C_DATA_PIN)
#define CTP_SET_I2C_CLK_HIGH				GPIO_WriteIO_FAST(1, CTP_I2C_CLK_PIN)
#define CTP_SET_I2C_CLK_LOW			        GPIO_WriteIO_FAST(0, CTP_I2C_CLK_PIN)

#define CTP_GET_I2C_CLK_BIT					GPIO_ReadIO_FAST(CTP_I2C_CLK_PIN)
#define CTP_SET_I2C_CLK_INPUT				GPIO_InitIO_FAST(INPUT, CTP_I2C_CLK_PIN)

#define CTP_SET_I2C_DATA_HIGH				GPIO_WriteIO_FAST(1, CTP_I2C_DATA_PIN)
#define CTP_SET_I2C_DATA_LOW				GPIO_WriteIO_FAST(0, CTP_I2C_DATA_PIN)
#define CTP_GET_I2C_DATA_BIT				GPIO_ReadIO_FAST(CTP_I2C_DATA_PIN)
#else
#define CTP_SET_I2C_CLK_OUTPUT				GPIO_InitIO(OUTPUT, CTP_I2C_CLK_PIN)
#define CTP_SET_I2C_DATA_OUTPUT				GPIO_InitIO(OUTPUT, CTP_I2C_DATA_PIN)
#define CTP_SET_I2C_DATA_INPUT				GPIO_InitIO(INPUT, CTP_I2C_DATA_PIN)
#define CTP_SET_I2C_CLK_HIGH				GPIO_WriteIO(1, CTP_I2C_CLK_PIN)
#define CTP_SET_I2C_CLK_LOW					GPIO_WriteIO(0, CTP_I2C_CLK_PIN)

#define CTP_GET_I2C_CLK_BIT					GPIO_ReadIO(CTP_I2C_CLK_PIN)
#define CTP_SET_I2C_CLK_INPUT				GPIO_InitIO(INPUT, CTP_I2C_CLK_PIN)

#define CTP_SET_I2C_DATA_HIGH				GPIO_WriteIO(1, CTP_I2C_DATA_PIN)
#define CTP_SET_I2C_DATA_LOW				GPIO_WriteIO(0, CTP_I2C_DATA_PIN)
#define CTP_GET_I2C_DATA_BIT				GPIO_ReadIO(CTP_I2C_DATA_PIN)
#endif	//__CUST_NEW__

/*software i2c delay time*/
#define CTP_BIT_DELAY_COUNT	100

#define CTP_I2C_DELAY \
{\
	volatile kal_uint32 cnt;\
	for(cnt=CTP_BIT_DELAY_COUNT; cnt>0; cnt--);\
}

/* software i2c header for  write & read */
#define CTP_WRITE_ID 	0xAA

#define CTP_READ_ID 	0xAB

#define CTP_ACK_CNT     50

/*software i2c start bit & stop bit*/
#define CTP_I2C_START_BIT \
{\
	CTP_SET_I2C_CLK_OUTPUT;\
	CTP_SET_I2C_DATA_OUTPUT;\
	\
	CTP_SET_I2C_DATA_HIGH;\
	CTP_SET_I2C_CLK_HIGH;\
	CTP_I2C_DELAY;\
	\
	CTP_SET_I2C_DATA_LOW;\
	CTP_I2C_DELAY;\
	\
	CTP_SET_I2C_CLK_LOW;\
	CTP_I2C_DELAY;\
}

#define CTP_I2C_STOP_BIT \
{\
	CTP_SET_I2C_CLK_OUTPUT;\
	CTP_SET_I2C_DATA_OUTPUT;\
	\
	CTP_SET_I2C_CLK_LOW;\
	CTP_SET_I2C_DATA_LOW;\
	CTP_I2C_DELAY;\
	\
	CTP_SET_I2C_CLK_HIGH;\
	CTP_I2C_DELAY;\
	\
	CTP_SET_I2C_DATA_HIGH;\
}
#endif	// SW_I2C


#ifdef NEED_RESET_PIN
/**********************************************************************/
/*		Macro definition for CTP reset pin									   */
/**********************************************************************/
/*gpio83 ==> reset pin*/
#define CTP_RESET_PIN				83
/*reset pin operation setting*/
#define CTP_SET_RESET_PIN_OUTPUT			GPIO_InitIO(OUTPUT, CTP_RESET_PIN)
#define CTP_SET_RESET_PIN_HIGH				GPIO_WriteIO(1, CTP_RESET_PIN)
#define CTP_SET_RESET_PIN_LOW				GPIO_WriteIO(0, CTP_RESET_PIN)
#endif	// NEED_RESET_PIN


/**********************************************************************/
/*		Macro definition for CTP update firmware							   */
/**********************************************************************/
#ifdef FW_UPDATE
/*Macro definition of the  command type for update firmware*/
#define STX_ISP_ERASE		0x80
#define STX_ISP_SEND_DATA	0x81
#define STX_ISP_WRITE_FLASH	0x82
#define STX_ISP_READ_FLASH	0x83
#define STX_ISP_RESET		0x84
#define STX_ISP_READY		0x8F

/*Macro definition for the information of ctp controller flash*/
#define ST1232_FLASH_SIZE		0x3C00
#define ST1232_ISP_PAGE_SIZE	0x200
#define ST1232_ROM_PARAM_ADR	0x3E00

/*define array for update firmware*/
kal_uint8 ST1232_FW_flash_buf[ST1232_ISP_PAGE_SIZE];
#endif	// FW_UPDATE

/********************************************************************/
/*		define struct for CTP	                                          				*/
/********************************************************************/
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

#endif	//TS1232_H
