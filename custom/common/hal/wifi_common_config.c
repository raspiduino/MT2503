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
 *  wndrv_rf_ah.c
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  Airoha RF related Functions
 *
 * Author:
 * -------
 * -------
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
 * removed!
 *
 * removed!
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
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_release.h"      	/* Basic data type */
#ifdef __MTK_TARGET__

#if !defined(__CUSTOM_WIFI_FEATURES_SWITCH__)
#include "syscomp_config.h"
#include "stack_config.h"
#include "supc_inc.h"
#include "wndrv_ft_types.h"
#include "wndrv_ft_msg.h"
#include "MMIDataType.h"
#if defined(__HOTSPOT_SUPPORT__)
#include "wndrv_flc_msg.h"
#include "flc2_ent_functions.h"
#endif /* __HOTSPOT_SUPPORT__ */
#endif /* !__CUSTOM_WIFI_FEATURES_SWITCH__ */
#if defined(__WIFI_SUPPORT__)
/*******************************************************************************
*                E X T E R N A L   R E F E R E N C E S
********************************************************************************
*/
//#include "gpio_hw.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "eint.h"
#include "GlobalDefs.h"
#include "wifi_common_config.h"
#include "lcd_power_mgr.h"
#include "lcd_if_manager.h"
#include "lcd_if.h"
#include "nli_arb.h"
#include "custom_EMI_release.h"

#include "drv_features.h"
#ifdef DRV_HIF_V2
#include "hif_hal.h"
#endif /* DRV_HIF_V2 */

#include "us_timer.h"
#include "dcl.h"
#if defined( WIFI_BB_MT5911 )
#include "precomp.h"
#endif

//#include "kal_non_specific_general_types.h"
#include "l1_interface.h"
#include "intrCtrl.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

#include "wndrv_api.h"

#include "wndrv_ft_types.h"
#include "wndrv_ft_msg.h"
#if defined(__HOTSPOT_SUPPORT__)
#include "wndrv_flc_msg.h"
#include "flc2_ent_functions.h"
#endif /* __HOTSPOT_SUPPORT__ */

#include "nld_central_ctrl.h"

//extern void DisplayPopup(kal_uint8 *string, kal_uint16 imageId, kal_uint8 imageOnBottom, kal_uint32 popupDuration, kal_uint8 toneId);
extern kal_uint8 wndrv_get_lcd_channel( void );
extern kal_uint8 wndrv_set_lcd_driving_current (void);
/*******************************************************************************
*                                      IO Part
********************************************************************************
*/

//20081110 modify by saker for MT5921 support
#if defined (MT5931) || defined (WIFI_BB_MT5921) || defined (WIFI_BB_MT5911)

#ifdef __CUST_NEW__

extern const char gpio_wifi_enable_pin;
extern const char gpio_wifi_32k_pin;
extern const char gpio_wifi_eint_enable_pin;
extern const char gpio_wifi_ext_rst_pin;

#define WiFi_LPO_GPIO_NUM GPIO_MAGIC_NUM
#define WiFi_LPO_GPO_NUM  GPO_MAGIC_NUM

#else

#define WiFi_GPO_MAGIC_NUM	100
#define WiFi_LPO_GPIO_NUM 0
#define WiFi_LPO_GPO_NUM  WiFi_GPO_MAGIC_NUM
extern const unsigned char WiFi_IO_setting[5];

#endif
kal_uint32 wifi_lcd_power_ctrl_handle = 0xFFFFFFFF;
kal_uint32 wifi_lcd_if_mgr_port_handle = 0xFFFFFFFF;
LCD_IOCTRL_DEVICE_IF_T wifi_if_setting;
kal_uint32 wndrv_get_bus_config(void);

/* move from interface/wifi/wifi_bt_coexistence.c */
extern kal_uint8      WNDRV_PTA_isOFF;
extern kal_uint32     BT_STATE_Report2WLAN;
extern kal_uint32     Protocol_Status4WLAN;
extern kal_uint32 SaveAndSetIRQMask( void );
extern void RestoreIRQMask( kal_uint32 mask );

/*----------------------------------------------------------------------------*/
/* Loop count for time measurement                                            */
/*----------------------------------------------------------------------------*/
#if defined(MCU_13M)
/* 1T ~= 77 ns */
#define COUNTER_50US (325)
#define COUNTER_20US (130)
#define COUNTER_15US (97)
#define COUNTER_10US (65)
#define COUNTER_05US (32)
#define COUNTER_350NS (3)

#elif defined(MCU_15_36M)
/* 1T ~= 65 ns */
#define COUNTER_50US (384)
#define COUNTER_20US (153)
#define COUNTER_15US (174)
#define COUNTER_10US (76)
#define COUNTER_05US (38)
#define COUNTER_350NS (4)

#elif defined(MCU_26M)
/* 1T ~= 38 ns */
#define COUNTER_50US (658)
#define COUNTER_20US (263)
#define COUNTER_15US (197)
#define COUNTER_10US (132)
#define COUNTER_05US (66)
#define COUNTER_350NS (5)

#elif defined(MCU_30_72M)
/* 1T ~= 33 ns */
#define COUNTER_50US (757)
#define COUNTER_20US (303)
#define COUNTER_15US (227)
#define COUNTER_10US (151)
#define COUNTER_05US (75)
#define COUNTER_350NS (6)

#elif defined(MCU_39M)
/* 1T ~= 25 ns */
#define COUNTER_50US (1000)
#define COUNTER_20US (400)
#define COUNTER_15US (300)
#define COUNTER_10US (200)
#define COUNTER_05US (100)
#define COUNTER_350NS (7)

#elif defined(MCU_52M)
/* 1T ~= 19 ns */
#define COUNTER_50US (1316)
#define COUNTER_20US (526)
#define COUNTER_15US (395)
#define COUNTER_10US (263)
#define COUNTER_05US (132)
#define COUNTER_350NS (10)

#elif defined(MCU_61_44M)
/* 1T ~= 16 ns */
#define COUNTER_50US (1563)
#define COUNTER_20US (625)
#define COUNTER_15US (468)
#define COUNTER_10US (312)
#define COUNTER_05US (156)
#define COUNTER_350NS (11)

#elif defined(MCU_65M)
/* 1T ~= 15 ns */
#define COUNTER_50US (1666)
#define COUNTER_20US (666)
#define COUNTER_15US (500)
#define COUNTER_10US (333)
#define COUNTER_05US (166)
#define COUNTER_350NS (12)

#elif defined(MCU_78M)
/* 1T ~= 13 ns */
#define COUNTER_50US (1923)
#define COUNTER_20US (769)
#define COUNTER_15US (576)
#define COUNTER_10US (384)
#define COUNTER_05US (192)
#define COUNTER_350NS (13)

#elif defined(MCU_91M)
/* 1T ~= 11 ns */
#define COUNTER_50US (2272)
#define COUNTER_20US (909)
#define COUNTER_15US (681)
#define COUNTER_10US (454)
#define COUNTER_05US (227)
#define COUNTER_350NS (15)

#elif defined(MCU_104M)
/* 1T ~= 9.6 ns */
#define COUNTER_50US (2604)
#define COUNTER_20US (1042)
#define COUNTER_15US (781)
#define COUNTER_10US (521)
#define COUNTER_05US (260)
#define COUNTER_350NS (19)

#elif defined(MCU_122_88M)
/* 1T ~= 8.1 ns */
#define COUNTER_50US (3086)
#define COUNTER_20US (1235)
#define COUNTER_15US (925)
#define COUNTER_10US (617)
#define COUNTER_05US (308)
#define COUNTER_350NS (22)

#elif defined(MCU_208M)
/* 1T ~= 4.8 ns */
#define COUNTER_50US (5208)
#define COUNTER_20US (2084)
#define COUNTER_15US (1562)
#define COUNTER_10US (1042)
#define COUNTER_05US (520)
#define COUNTER_350NS (37)

#elif defined(MCU_245_76M)
/* 1T ~= 4.0 ns */
#define COUNTER_50US (6172)
#define COUNTER_20US (2470)
#define COUNTER_15US (1850)
#define COUNTER_10US (1234)
#define COUNTER_05US (616)
#define COUNTER_350NS (44)

#elif defined(MCU_260M)
/* 1T ~= 3.66 ns */
#define COUNTER_50US (13662)
#define COUNTER_20US (5465)
#define COUNTER_15US (4100)
#define COUNTER_10US (2733)
#define COUNTER_05US (1367)
#define COUNTER_350NS (96)

#elif defined(MCU_312M)
/* 1T ~= 3.3 ns */
#define COUNTER_50US (10000)
#define COUNTER_20US (3000)
#define COUNTER_15US (2000)
#define COUNTER_10US (1500)
#define COUNTER_05US (1000)
#define COUNTER_350NS (60)

#elif defined(MCU_364M) //MT6260
/* 1T ~= 2.62 ns */
#define COUNTER_50US (19084)
#define COUNTER_20US (7634)
#define COUNTER_15US (5725)
#define COUNTER_10US (3817)
#define COUNTER_05US (1908)
#define COUNTER_350NS (134)

#elif defined(MCU_416M) //MT6255
/* 1T ~= 2.4 ns */
#define COUNTER_50US (20800)
#define COUNTER_20US (8320)
#define COUNTER_15US (6240)
#define COUNTER_10US (4160)
#define COUNTER_05US (2080)
#define COUNTER_350NS (146)

#elif defined(MCU_512M) //MT6256
/* 1T ~= 1.9 ns */
#define COUNTER_50US (20000)
#define COUNTER_20US (6000)
#define COUNTER_15US (4000)
#define COUNTER_10US (3000)
#define COUNTER_05US (2000)
#define COUNTER_350NS (120)
#elif defined(MCU_650M) //MT6276
/* 1T ~= 1.5 ns */
#define COUNTER_50US (20000)
#define COUNTER_20US (6000)
#define COUNTER_15US (4000)
#define COUNTER_10US (3000)
#define COUNTER_05US (2000)
#define COUNTER_350NS (120)
#elif defined(MCU_611M) //MT6276 E2
/* 1T ~= 1.64 ns */
#define COUNTER_50US (30488)
#define COUNTER_20US (12195)
#define COUNTER_15US (9146)
#define COUNTER_10US (6098)
#define COUNTER_05US (3049)
#define COUNTER_350NS (213)
#elif defined(MCU_520M) //MT6270
/* 1T ~= 1.92 ns */
#define COUNTER_50US (26042)
#define COUNTER_20US (10417)
#define COUNTER_15US (7813)
#define COUNTER_10US (5208)
#define COUNTER_05US (2604)
#define COUNTER_350NS (182)
#elif defined(MCU_156M)
/* 1T ~= 6.41 ns */
#define COUNTER_50US (7800)
#define COUNTER_20US (3120)
#define COUNTER_15US (2340)
#define COUNTER_10US (1560)
#define COUNTER_05US (780)
#define COUNTER_350NS (55)
#else

#error "Unsupported MCU clock rate for single bank support V2!"

#endif

//lcko modify

static void WiFi_US_Delay(kal_uint32 u4MicroSec)
{
    kal_uint32             start_qbit;      ///< Starting TDMA Qbit
    kal_uint32             curr_qbit;       ///< Current TDMA Qbit
    kal_uint32             elapse_qbit;     ///< Elapse number of Qbit

    // Qbit may not be ready in system initialization stage, use for-loop instead
    if (kal_query_systemInit()) {

       // minimum delay is 5
       if (u4MicroSec < 5)
          u4MicroSec = 5;

       // delay = delay / 5 ~= delay * 52 / 2^8;
       u4MicroSec = (u4MicroSec * 52) >> 8;

       // for-loop to wait
       for (; u4MicroSec > 0; --u4MicroSec)
          for (curr_qbit = COUNTER_05US; curr_qbit > 0; --curr_qbit);

       return;
    }

    // Read start qbit
    start_qbit = ust_get_current_time();

    /*******************************************************************//**
     * Calculate how many qbit should be waited. Store the result to "delay".
     * delay = delay * 13 / 12 ~= delay * 13 * 21.3333 / 2^8
     * => Limit: Maximum delay is 15,449,521 us = 15,449 ms = 15 sec
     ***********************************************************************/

    // delay * 13 * 21.333 ~= delay * 278
    u4MicroSec = u4MicroSec * 278;

    // delay / 2^8 ~= (delay >> 8) + 1 (for saving code, add one more qbit in all cases. Actually we only have to do such thing when "delay & 255 == 1"
    u4MicroSec = (u4MicroSec >> 8) + 1;

    // wait until "delay" qbits are all elapsed
    do {
       curr_qbit   = ust_get_current_time();
       elapse_qbit = ust_get_duration(start_qbit, curr_qbit);
    } while (elapse_qbit < u4MicroSec);

    return;


}

static void WiFi_GPIO_SetClkOut(char clk_num, gpio_clk_mode mode)
{
	DCL_HANDLE handle;
	GPIO_CTRL_SET_CLK_OUT_T data;
	handle=DclGPIO_Open(DCL_GPIO_CLK,clk_num);
	data.u2ClkNum=clk_num;
	data.u2Mode=mode;
	DclGPIO_Control(handle,GPIO_CMD_SET_CLK_OUT,(DCL_CTRL_DATA_T*)&data);
	DclGPIO_Close(handle);	
}

#if defined(MT6276) || defined(MT6256) || defined(MT6255) || defined(MT6250) || defined(MT6260)
static void WiFi_GPIO_SetClkDiv(char clk_num, gpio_clk_div div)
{
    DCL_HANDLE handle;
    GPIO_CTRL_SET_CLK_DIV_T data;
    handle = DclGPIO_Open(DCL_GPIO_CLK, clk_num);
    data.u2ClkNum = clk_num;
    data.u2Div = div;
    DclGPIO_Control(handle, GPIO_CMD_SET_CLK_DIV, (DCL_CTRL_DATA_T*)&data);
    DclGPIO_Close(handle);
}
#endif /* MT6276 || MT6256 */

static void WiFi_GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
{
	DCL_HANDLE handle;
	handle=DclGPIO_Open(DCL_GPIO,pin);	
	switch(conf_dada)
		{
			case 0:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_0,0);
				break;
			case 1:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_1,0);
				break;
			case 2:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_2,0);
				break;
			case 3:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_3,0);	
				break;
			case 4:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_4,0);	
				break;
			case 5:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_5,0);	
				break;
			case 6:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_6,0);	
				break;
			case 7:
				DclGPIO_Control(handle,GPIO_CMD_SET_MODE_7,0);	
				break;
			default:
				{
					DclGPIO_Close(handle);
                    // Warnning: fail to set WiFi pin for GPIO mode
                	kal_wap_trace(MOD_WNDRV, TRACE_ERROR, "[WIFI Error] fail to set WiFi for GPIO pin[%d] mode[%d]: wrong setting", pin, conf_dada);
					//ASSERT(0);
				}
		}
	DclGPIO_Close(handle);
}

static void WiFi_GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
{
	DCL_HANDLE handle;
	handle=DclGPIO_Open(DCL_GPO,pin);
	switch(conf_dada)
		{
			case 0:
				DclGPIO_Control(handle,GPO_CMD_MODE_SET_0,0);
				break;
			case 1:
				DclGPIO_Control(handle,GPO_CMD_MODE_SET_1,0);
				break;
			case 2:
				DclGPIO_Control(handle,GPO_CMD_MODE_SET_2,0);
				break;
			case 3:
				DclGPIO_Control(handle,GPO_CMD_MODE_SET_3,0);
				break;
			default:
				{
					DclGPIO_Close(handle);
					ASSERT(0);	
				}
		}
		DclGPIO_Close(handle);
}

kal_uint8 WiFi_SetToGPIOMode(kal_uint8 pin)
{
	kal_uint8 gpio_mode = 0;
	kal_uint8 gpio_pin = pin;

#ifdef __CUST_NEW__
	if (pin >= GPIO_MAGIC_NUM)
	{
		gpio_pin -= GPIO_MAGIC_NUM;
	}
	else
	{
		//GPO_ModeSetup(pin, gpio_mode);
		WiFi_GPO_ModeSetup(pin, gpio_mode);
		return 0;
	}
#else /* #ifdef __CUST_NEW__ */
	if (pin >= WiFi_GPO_MAGIC_NUM)
	{
		//GPO_ModeSetup((pin - WiFi_GPO_MAGIC_NUM), gpio_mode);
		WiFi_GPO_ModeSetup((pin - WiFi_GPO_MAGIC_NUM), gpio_mode);
		return 0;
	}
#endif /* #ifdef __CUST_NEW__ */

	switch (gpio_pin)
	{
#if defined(MT6223)
		case 44:
		case 50:
			gpio_mode = 1;
			break;
#elif defined(MT6228) || defined(MT6229) || defined(MT6230)
		case 26: case 27: case 28: case 29: case 30: case 31: 
		case 44: case 45: case 46: case 47:
		case 54: case 55: case 56: case 57: case 58: case 59: case 60: case 61: case 62:
		case 68: case 69: case 70: case 71: case 72: case 73: case 74:
			gpio_mode = 1;
			break;
#endif	
		default:
			gpio_mode = 0;
	}

	//GPIO_ModeSetup(pin, gpio_mode);
	WiFi_GPIO_ModeSetup(pin, gpio_mode);
	return 0;
}

//
void WiFi_SetupGPIO(char val, unsigned char pin)
{
#ifdef __CUST_NEW__
	if (pin >= GPIO_MAGIC_NUM)
	{
		//GPIO_ModeSetup(pin, val);
		WiFi_GPIO_ModeSetup(pin, val);
	}
	else
	{
		//GPO_ModeSetup(pin, val);
	    WiFi_GPO_ModeSetup(pin, val);	
	}
#else
	if (pin >= WiFi_GPO_MAGIC_NUM)
	{
		//GPO_ModeSetup((pin - WiFi_GPO_MAGIC_NUM), val);
		WiFi_GPO_ModeSetup((pin - WiFi_GPO_MAGIC_NUM), val);
	}
	else
	{
		//GPIO_ModeSetup(pin, val);
		WiFi_GPIO_ModeSetup(pin, val);
	}
#endif
}
#pragma arm section code = "SECONDARY_ROCODE"
void WiFi_InitGPIO(char direction, unsigned char pin)
{
	DCL_HANDLE handle;
	handle=DclGPIO_Open(DCL_GPIO,pin);
	if(0==direction)
		DclGPIO_Control(handle,GPIO_CMD_SET_DIR_IN,0);
	else if(1==direction)
		DclGPIO_Control(handle,GPIO_CMD_SET_DIR_OUT,0);
	else
		ASSERT(0);
	DclGPIO_Close(handle);
}
#pragma arm section code

#pragma arm section code = "SECONDARY_ROCODE"
void WiFi_WriteGPIO(char val, unsigned char pin)
{
	DCL_HANDLE handle;
	    
#ifdef __CUST_NEW__
	if (pin >= GPIO_MAGIC_NUM)
	{
		//GPIO_WriteIO(val, pin);
		handle=DclGPIO_Open(DCL_GPIO,pin);	
	    if(0==val)
	    	DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
	    else if(1==val)
	    	DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
	    DclGPIO_Close(handle);			
	}
	else
	{
		//GPO_WriteIO(val, pin);
		handle=DclGPIO_Open(DCL_GPO,pin);	
	    if(0==val)
		    DclGPIO_Control(handle,GPO_CMD_WRITE_LOW,0);
	    else if(1==val)
		    DclGPIO_Control(handle,GPO_CMD_WRITE_HIGH,0);
		DclGPIO_Close(handle);
	}
#else
	if (pin >= WiFi_GPO_MAGIC_NUM)
	{
		//GPO_WriteIO(val, (pin - WiFi_GPO_MAGIC_NUM));
		handle=DclGPIO_Open(DCL_GPO,(pin - WiFi_GPO_MAGIC_NUM));	
	    if(0==val)
		    DclGPIO_Control(handle,GPO_CMD_WRITE_LOW,0);
	    else if(1==val)
		    DclGPIO_Control(handle,GPO_CMD_WRITE_HIGH,0);
		DclGPIO_Close(handle);
	}
	else
	{
		//GPIO_WriteIO(val, pin);
		handle=DclGPIO_Open(DCL_GPIO,pin);	
	    if(0==val)
	    	DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
	    else if(1==val)
	    	DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
	    DclGPIO_Close(handle);
	}
#endif
    
}
#pragma arm section code

kal_uint8 WiFi_GetLpoMode(kal_uint8 numLpo)
{
	kal_uint8 modeLpo = 0xFF;

#if defined(MT6228) || defined(MT6229)|| defined(MT6230)
{
	if (numLpo == (WiFi_LPO_GPIO_NUM | 8))
		modeLpo = 1;
	else
		modeLpo = 3;
}
#elif defined(MT6225)
{
	if ((numLpo == (WiFi_LPO_GPIO_NUM | 6)) || (numLpo == (WiFi_LPO_GPO_NUM | 2)))
		modeLpo = 2;	
	else
		modeLpo = 3;
}
#elif (defined(MT6238)||defined(MT6239))
{
	switch (numLpo)
	{
		case (WiFi_LPO_GPIO_NUM | 8):
			modeLpo = 3;
#if defined(DRV_GPIO_CLK_OUT)
			//GPIO_SetClkOut(3, 6);    // CLK ouput 4
			WiFi_GPIO_SetClkOut(3, 6);
#endif
			break;
		case (WiFi_LPO_GPIO_NUM | 50):
			modeLpo = 2;
#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(6, 6);    // CLK ouput 7
#endif
			break;
		case (WiFi_LPO_GPIO_NUM | 55):
			modeLpo = 2;
#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(7, 6);    // CLK ouput 8
#endif
			break;
		case (WiFi_LPO_GPIO_NUM | 57):
			modeLpo = 2;
#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(0, 6);    // CLK ouput 1
#endif
			break;
		case (WiFi_LPO_GPIO_NUM | 58):
			modeLpo = 2;
#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(1, 6);    // CLK ouput 2
#endif
			break;
		case (WiFi_LPO_GPIO_NUM | 65):
			modeLpo = 2;
#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 6);    // CLK ouput 3   
#endif
			break;
		case (WiFi_LPO_GPIO_NUM | 66):
			modeLpo = 2;
#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(3, 6);    // CLK ouput 4
#endif
			break;
		case (WiFi_LPO_GPIO_NUM | 77):
			modeLpo = 2;
#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(4, 6);    // CLK ouput 5
#endif
			break;
		case (WiFi_LPO_GPIO_NUM | 78):
			modeLpo = 2;
#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(5, 6);    // CLK ouput 6
#endif
			break;
	}
}

#elif (defined(MT6235)||defined(MT6235B))
{
	switch (numLpo)
	{
		case (WiFi_LPO_GPIO_NUM | 0):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(0, 6);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 26):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(1, 6);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 27):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 6);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 45):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(3, 6);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 57):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(4, 6);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 64):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(5, 6);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 65):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(6, 6);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 66):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(7, 6);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 73):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(8, 6);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 74):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(9, 6);
			#endif
			break;
	}
}
#elif defined (MT6236) || defined (MT6236B)
{
	switch (numLpo)
    {
		case (WiFi_LPO_GPIO_NUM | 8): //CLKM0
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(0, mode_f32k_ck);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 17): //CLKM1
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(1, mode_f32k_ck);
			#endif
			break;
			        
		case (WiFi_LPO_GPIO_NUM | 20): //CLKM3
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(3, mode_f32k_ck);
			#endif
			break;			

		case (WiFi_LPO_GPIO_NUM | 22): //CLKM3
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(3, mode_f32k_ck);
			#endif
			break;			
			
		case (WiFi_LPO_GPIO_NUM | 31): //CLKM3
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(3, mode_f32k_ck);
			#endif
			break;	

		case (WiFi_LPO_GPIO_NUM | 32): //CLKM4
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(4, mode_f32k_ck);
			#endif
			break;
			
		case (WiFi_LPO_GPIO_NUM | 33): //CLKM5
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(5, mode_f32k_ck);
			#endif
			break;	

		case (WiFi_LPO_GPIO_NUM | 36): //CLKM2
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, mode_f32k_ck);
			#endif
			break;		

		case (WiFi_LPO_GPIO_NUM | 41): //CLKM4
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(4, mode_f32k_ck);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 42): //CLKM5
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(5, mode_f32k_ck);
			#endif
			break;		

		case (WiFi_LPO_GPIO_NUM | 54): //CLKM3
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(3, mode_f32k_ck);
			#endif
			break;		
			
		case (WiFi_LPO_GPIO_NUM | 58): //CLKM4
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(4, mode_f32k_ck);
			#endif
			break;	
			
		case (WiFi_LPO_GPIO_NUM | 63): //CLKM5
			modeLpo = 1;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(5, mode_f32k_ck);
			#endif
			break;																								
    }    
}
#elif defined(MT6268)
{
	switch (numLpo)
    {
		case (WiFi_LPO_GPIO_NUM | 37): //CLKM0
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(0, 64);
			#endif
			break;
			
		case (WiFi_LPO_GPIO_NUM | 38): //CLKM1
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(1, 64);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 43): //CLKM2
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 64);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 44): //CLKM3
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(3, 64);
			#endif
			break;										

		case (WiFi_LPO_GPIO_NUM | 60): //CLKM2
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 64);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 64): //CLKM4
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(4, 64);
			#endif
			break;					

		case (WiFi_LPO_GPIO_NUM | 80): //CLKM2
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 64);
			#endif
			break;
			
		case (WiFi_LPO_GPIO_NUM | 81): //CLKM3
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(3, 64);
			#endif
			break;					

		case (WiFi_LPO_GPIO_NUM | 82): //CLKM4
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(4, 64);
			#endif
			break;			

		case (WiFi_LPO_GPIO_NUM | 83): //CLKM5
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(5, 64);
			#endif
			break;		

		case (WiFi_LPO_GPIO_NUM | 85): //CLKM0
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(0, 64);
			#endif
			break;				
			
		case (WiFi_LPO_GPIO_NUM | 90): //CLKM1
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(1, 64);
			#endif
			break;			

		case (WiFi_LPO_GPIO_NUM | 98): //CLKM2
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 64);
			#endif
			break;			

		case (WiFi_LPO_GPIO_NUM | 99): //CLKM3
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(3, 64);
			#endif
			break;			
    }    
} 
#elif defined(MT6253T) || defined(MT6253)
    switch (numLpo) 
    {
		    case (GPIO_MAGIC_NUM | 18):
		    	modeLpo = 2;
		    	#if defined(DRV_GPIO_CLK_OUT)
		    	WiFi_GPIO_SetClkOut(0, 4);
		    	#endif
		    	break;
        
		    case (GPIO_MAGIC_NUM | 3):
		    	modeLpo = 2;
		    	#if defined(DRV_GPIO_CLK_OUT)
		    	WiFi_GPIO_SetClkOut(1, 4);
		    	#endif
		    	break;
        
		    case (GPIO_MAGIC_NUM | 75):
		    	modeLpo = 3;
		    	#if defined(DRV_GPIO_CLK_OUT)
		    	WiFi_GPIO_SetClkOut(2, 4);
		    	#endif
		    	break;
        
		    case (GPIO_MAGIC_NUM | 62):
		    	modeLpo = 3;
		    	#if defined(DRV_GPIO_CLK_OUT)
		    	WiFi_GPIO_SetClkOut(3, 4);
		    	#endif
		    	break;
        
		    case (GPIO_MAGIC_NUM | 61):
		    	modeLpo = 2;
		    	#if defined(DRV_GPIO_CLK_OUT)
		    	WiFi_GPIO_SetClkOut(4, 4);
		    	#endif
		    	break;
        
		    case (GPIO_MAGIC_NUM | 15):
		    	modeLpo = 2;
		    	#if defined(DRV_GPIO_CLK_OUT)
		    	WiFi_GPIO_SetClkOut(5, 4);
		    	#endif
		    	break;
        
		    case (GPIO_MAGIC_NUM | 74):
		    	modeLpo = 1;
		    	#if defined(DRV_GPIO_CLK_OUT)
		    	WiFi_GPIO_SetClkOut(6, 4);
		    	#endif
		    	break;
    }
#elif defined(MT6253E) 
{
	switch (numLpo)
	{
		case (GPIO_MAGIC_NUM | 3):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(1, 4);
			#endif
			break;
        
		case (GPIO_MAGIC_NUM | 26):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 4);
			#endif
			break;
        
		case (GPIO_MAGIC_NUM | 33):
			modeLpo = 1;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 4);
			#endif
			break;
        
		case (GPIO_MAGIC_NUM | 8):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(3, 4);
			#endif
			break;
        
		case (GPIO_MAGIC_NUM | 43):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(3, 4);
			#endif
			break;
        
		case (GPIO_MAGIC_NUM | 42):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(4, 4);
			#endif
			break;
        
		case (GPIO_MAGIC_NUM | 45):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(5, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 34):
			modeLpo = 1;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(6, 4);
			#endif
			break;
	}
}    
#elif defined(MT6252H) 
{
	switch (numLpo)
	{
		case (GPIO_MAGIC_NUM | 1):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(0, 4);
			#endif
			break;
        
		case (GPIO_MAGIC_NUM | 3):
			modeLpo = 5;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(1, 4);
			#endif
			break;
        
		case (GPIO_MAGIC_NUM | 8):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(3, 4);
			#endif
			break;
        
		case (GPIO_MAGIC_NUM | 23):
			modeLpo = 5;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 4);
			#endif
			break;
        
		case (GPIO_MAGIC_NUM | 26):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(4, 4);
			#endif
			break;
        
		case (GPIO_MAGIC_NUM | 27):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(3, 4);
			#endif
			break;
        
		case (GPIO_MAGIC_NUM | 33):
			modeLpo = 1;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 34):
			modeLpo = 1;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(6, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 43):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 45):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(5, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 64):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 70):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 4);
			#endif
			break;
	}
}

#elif defined(MT6252)
{
	switch (numLpo)
	{
		case (GPIO_MAGIC_NUM | 1):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(0, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 3):
			modeLpo = 5;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(1, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 8):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(3, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 23):
			modeLpo = 5;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 26):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(4, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 27):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(3, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 33):
			modeLpo = 1;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 34):
			modeLpo = 1;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(6, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 43):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 45):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(5, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 64):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 70):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			WiFi_GPIO_SetClkOut(2, 4);
			#endif
			break;
	}
}

#elif defined(MT6276)
{
	switch (numLpo)
    {
#if defined(MT6276_S00) // MT6276 E1
		case (WiFi_LPO_GPIO_NUM | 13): //CLKM1
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(1, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(1, 0);
			#endif
			break;

        case (WiFi_LPO_GPIO_NUM | 51): //CLKM2
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(2, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(2, 0);
			#endif
			break;

        case (WiFi_LPO_GPIO_NUM | 101): //CLKM3
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(3, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(3, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 14): //CLKM4
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(4, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(4, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 15): //CLKM5
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(5, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(5, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 27): //CLKM6
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(6, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(6, 0);
			#endif
			break;

#elif defined(MT6276_S01) // MT6276 E2
		case (WiFi_LPO_GPIO_NUM | 9): //CLKM1
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(1, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(1, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 99): //CLKM2
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(2, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(2, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 32): //CLKM3
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(3, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(3, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 33): //CLKM4
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(4, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(4, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 34): //CLKM5
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(5, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(5, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 45): //CLKM6
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(6, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(6, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 11): //CLKM7
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(7, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(7, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 12): //CLKM8
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(8, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(8, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 5): //CLKM9
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(9, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(9, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 8): //CLKM10
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(10, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(10, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 71): //CLKM11
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(11, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(11, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 72): //CLKM12
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(12, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(12, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 105): //CLKM13
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(13, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(13, 0);
			#endif
			break;
#else // Other MT6276 ECO chips
		case (WiFi_LPO_GPIO_NUM | 9): //CLKM1
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(1, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(1, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 99): //CLKM2
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(2, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(2, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 32): //CLKM3
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(3, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(3, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 33): //CLKM4
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(4, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(4, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 34): //CLKM5
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(5, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(5, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 45): //CLKM6
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(6, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(6, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 11): //CLKM7
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(7, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(7, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 12): //CLKM8
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(8, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(8, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 5): //CLKM9
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(9, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(9, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 8): //CLKM10
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(10, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(10, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 71): //CLKM11
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(11, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(11, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 72): //CLKM12
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(12, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(12, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 105): //CLKM13
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6276)
			WiFi_GPIO_SetClkOut(13, mode_f32k_ck); //001xb	f32k_ck
			WiFi_GPIO_SetClkDiv(13, 0);
			#endif
			break;
#endif	/* #if defined(MT6276_S00) */
    }
}

#elif defined(MT6256)
{
	switch (numLpo)
    {
		case (WiFi_LPO_GPIO_NUM | 95): //CLKM0
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6256)
			WiFi_GPIO_SetClkOut(0, mode_f32k_ck);
            WiFi_GPIO_SetClkDiv(0, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 0): //CLKM1
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6256)
			WiFi_GPIO_SetClkOut(1, mode_f32k_ck);
            WiFi_GPIO_SetClkDiv(1, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 8): //CLKM2
			modeLpo = 5;
			#if defined(DRV_GPIO_REG_AS_6256)
			WiFi_GPIO_SetClkOut(2, mode_f32k_ck);
            WiFi_GPIO_SetClkDiv(2, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 5): //CLKM3
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6256)
			WiFi_GPIO_SetClkOut(3, 64);
            WiFi_GPIO_SetClkDiv(3, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 68):  //CLKM4
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6256)
			WiFi_GPIO_SetClkOut(4, mode_f32k_ck);
            WiFi_GPIO_SetClkDiv(4, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 79):  //CLKM5
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6256)
			WiFi_GPIO_SetClkOut(5, mode_f32k_ck);
            WiFi_GPIO_SetClkDiv(5, 0);





			#endif
			break;
    }
}

#elif defined(MT6255)
{
	switch (numLpo)
    {
		case (WiFi_LPO_GPIO_NUM | 95): //CLKM0
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6255)
			WiFi_GPIO_SetClkOut(0, mode_f32k_ck);
            WiFi_GPIO_SetClkDiv(0, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 0): //CLKM1
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6255)
			WiFi_GPIO_SetClkOut(1, mode_f32k_ck);
            WiFi_GPIO_SetClkDiv(1, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 8): //CLKM2
			modeLpo = 5;
			#if defined(DRV_GPIO_REG_AS_6255)
			WiFi_GPIO_SetClkOut(2, mode_f32k_ck);
            WiFi_GPIO_SetClkDiv(2, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 5): //CLKM3
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6255)
			WiFi_GPIO_SetClkOut(3, mode_f32k_ck);
            WiFi_GPIO_SetClkDiv(3, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 68):  //CLKM4
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6255)
			WiFi_GPIO_SetClkOut(4, mode_f32k_ck);
            WiFi_GPIO_SetClkDiv(4, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 79):  //CLKM5
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6255)
			WiFi_GPIO_SetClkOut(5, mode_f32k_ck);
            WiFi_GPIO_SetClkDiv(5, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 61):  //CLKM6
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6255)
			WiFi_GPIO_SetClkOut(6, mode_f32k_ck);
            WiFi_GPIO_SetClkDiv(6, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 62):  //CLKM7
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6255)
			WiFi_GPIO_SetClkOut(7, mode_f32k_ck);
            WiFi_GPIO_SetClkDiv(7, 0);
			#endif
			break;

		case (WiFi_LPO_GPIO_NUM | 104):  //CLKM8
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6255)
			WiFi_GPIO_SetClkOut(8, mode_f32k_ck);
            WiFi_GPIO_SetClkDiv(8, 0);

			#endif
			break;
    }
}
#elif defined(MT6250)
{
	switch (numLpo)
    {
		case (WiFi_LPO_GPIO_NUM | 0): //CLKO0
			modeLpo = 1;
			#if defined(DRV_GPIO_REG_AS_6250)
			WiFi_GPIO_SetClkOut(0, 4);
            WiFi_GPIO_SetClkDiv(0, 0);
			#endif
			break;
		case (WiFi_LPO_GPIO_NUM | 4): //CLKO5
			modeLpo = 3;
			#if defined(DRV_GPIO_REG_AS_6250)
			WiFi_GPIO_SetClkOut(5, 4);
            WiFi_GPIO_SetClkDiv(5, 0);
			#endif
			break;
		case (WiFi_LPO_GPIO_NUM | 11): //CLKO1
			modeLpo = 6;
			#if defined(DRV_GPIO_REG_AS_6250)
			WiFi_GPIO_SetClkOut(1, 4);
			WiFi_GPIO_SetClkDiv(1, 0);
			#endif
			break;	
		case (WiFi_LPO_GPIO_NUM | 18): //CLKO6
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6250)
			WiFi_GPIO_SetClkOut(6, 4);
			WiFi_GPIO_SetClkDiv(6, 0);
			#endif
			break;
		case (WiFi_LPO_GPIO_NUM | 21): //CLKO2
			modeLpo = 1;
			#if defined(DRV_GPIO_REG_AS_6250)
			WiFi_GPIO_SetClkOut(2, 4);
			WiFi_GPIO_SetClkDiv(2, 0);
			#endif
			break;
		case (WiFi_LPO_GPIO_NUM | 24): //CLKO7
			modeLpo = 4;
			#if defined(DRV_GPIO_REG_AS_6250)
			WiFi_GPIO_SetClkOut(7, 4);
			WiFi_GPIO_SetClkDiv(7, 0);
			#endif
			break;		
		case (WiFi_LPO_GPIO_NUM | 50): //CLKO4
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6250)
			WiFi_GPIO_SetClkOut(4, 4);
			WiFi_GPIO_SetClkDiv(4, 0);
			#endif
			break;
		case (WiFi_LPO_GPIO_NUM | 48): //CLKO3
			modeLpo = 2;
			#if defined(DRV_GPIO_REG_AS_6250)
			WiFi_GPIO_SetClkOut(3, 4);
			WiFi_GPIO_SetClkDiv(3, 0);
			#endif
			break;

		}
}
#elif defined(MT6260)
{
	switch (numLpo)
    {
		case (WiFi_LPO_GPIO_NUM | 21): //CLKO0
			modeLpo = 3;
			WiFi_GPIO_SetClkOut(0, 4);
            //WiFi_GPIO_SetClkDiv(0, 0);6260 remove CLKDIV function
			break;
			
		case (WiFi_LPO_GPIO_NUM | 45): //CLKO1
			modeLpo = 3;
			WiFi_GPIO_SetClkOut(1, 4);
            //WiFi_GPIO_SetClkDiv(1, 0);
			break;
		}
}
#elif (defined(MT6261)||defined(MT2501)||defined(MT2502))
{
	switch (numLpo)
    {
		case (WiFi_LPO_GPIO_NUM | 18): //CLKO0
			modeLpo = 3;
			WiFi_GPIO_SetClkOut(0, 4);
			break;
			
		case (WiFi_LPO_GPIO_NUM | 25): //CLKO1
			modeLpo = 3;
			WiFi_GPIO_SetClkOut(1, 4);
			break;
			
		case (WiFi_LPO_GPIO_NUM | 36): //CLKO2
			modeLpo = 3;
			WiFi_GPIO_SetClkOut(2, 4);
			break;
			
		case (WiFi_LPO_GPIO_NUM | 41): //CLKO3
			modeLpo = 2;
			WiFi_GPIO_SetClkOut(3, 4);
			break;
			
		case (WiFi_LPO_GPIO_NUM | 46): //CLKO4
			modeLpo = 4;
			WiFi_GPIO_SetClkOut(4, 4);
			break;
			
		case (WiFi_LPO_GPIO_NUM | 50): //CLKO5
			modeLpo = 9;
			WiFi_GPIO_SetClkOut(5, 4);
			break;
		}
}

#else
	//DisplayPopup((kal_uint8*)L"The chip doesn't define the pin of GPIO for lpoclk !", IMG_GLOBAL_ERROR, 0, 5000, 0); 
	ASSERT(0);
#endif
	return modeLpo;
}

void WiFi_InitIO (sWiFi_IO *GPIO)
{
#ifdef __CUST_NEW__

    // Enable pin
    GPIO->num_poweronWiFi = gpio_wifi_enable_pin;
    GPIO->pol_poweronWiFi = 1;
    
    // ext reset pin
    GPIO->num_resetWiFi = gpio_wifi_ext_rst_pin;

    // lpo clock pin
    GPIO->num_lpoclk = gpio_wifi_32k_pin;
    if (0xFF != GPIO->num_lpoclk)
    {
        GPIO->mode_lpoclk = WiFi_GetLpoMode(GPIO->num_lpoclk);
        if (0xFF == GPIO->mode_lpoclk)
        {
            //DisplayPopup((kal_uint8*)L"The pin of GPIO for lpoclk is wrong!", IMG_GLOBAL_ERROR, 0, 5000, 0);   
            //ASSERT(0);
        }
    }

    GPIO->num_IndicateWiFi = gpio_wifi_eint_enable_pin;

#else
    // power on pin
    GPIO->num_poweronWiFi = WiFi_IO_setting[0];
    GPIO->pol_poweronWiFi = WiFi_IO_setting[1];
    // lpo clock pin
    GPIO->num_lpoclk = WiFi_IO_setting[2];
    if (0xFF != GPIO->num_lpoclk)
    {
        GPIO->mode_lpoclk = WiFi_GetLpoMode(GPIO->num_lpoclk);
        if (0xFF == GPIO->mode_lpoclk)
        {
            //DisplayPopup((kal_uint8*)L"The pin of GPIO for lpoclk is wrong!", IMG_GLOBAL_ERROR, 0, 5000, 0); 
            //ASSERT(0);    
        }
    }
    GPIO->num_IndicateWiFi = WiFi_IO_setting[3];
#endif

    //Setting external reset
    if (0xFF != GPIO->num_resetWiFi)
    {
        WiFi_InitGPIO(1, GPIO->num_resetWiFi);  // set direction (output)
        WiFi_SetToGPIOMode(GPIO->num_resetWiFi);        
        //WiFi_WriteGPIO(1, GPIO->num_resetWiFi); //set rst high //091113 removed        
        WiFi_WriteGPIO(0, GPIO->num_resetWiFi); //set rst low        
    }

    if (0xFF != GPIO->num_poweronWiFi)
    {
        WiFi_InitGPIO(1, GPIO->num_poweronWiFi);  // set direction (output)
        //WiFi_SetupGPIO(0, GPIO->num_poweronWiFi); // set to gpio mode
        //lcko modify
        WiFi_SetToGPIOMode(GPIO->num_poweronWiFi);
        WiFi_WriteGPIO(1, GPIO->num_poweronWiFi); // set ouput high, prevent current leakage
                                                  // goes from eHPI, chip must always turns ON.
    }
                                                  // Because the WiFi chip always turns ON,
                                                   
    if (0xFF != GPIO->num_resetWiFi)
    {   
        //keep ext_reset > 500us
        WiFi_US_Delay(550);
        WiFi_WriteGPIO(1, GPIO->num_resetWiFi); //set rst high
    }
                                                   
    if (0xFF != GPIO->num_lpoclk)                  // We can turn on 32K CLK mode here.
    {
        WiFi_SetupGPIO(GPIO->mode_lpoclk, GPIO->num_lpoclk);
    }

    if (0xFF != GPIO->num_IndicateWiFi)
    {
        WiFi_InitGPIO(1, GPIO->num_IndicateWiFi);       // set direction (output)
        //WiFi_SetupGPIO(0, GPIO->num_IndicateWiFi);      // set to gpio mode
        //lcko modify
        WiFi_SetToGPIOMode(GPIO->num_IndicateWiFi);
        WiFi_WriteGPIO(0, GPIO->num_IndicateWiFi);      // set ouput low
    }
}

void WiFi_InitLCDBus (kal_uint32 *hpi_ctrl_addr, kal_uint32 *hpi_data_addr)
{
    kal_uint8 wndrv_lcd_channel = 0;
    kal_uint32 if_c2ws = 0; ///< write setup time, unit is T
    kal_uint32 if_wst = 0; ///< write wait state, unit is T
    kal_uint32 if_c2wh = 0; ///< write hold time, unit is T
    kal_uint32 if_c2rs = 0; ///< read setup time, unit is T
    kal_uint32 if_c2rh = 0; ///< read hold time, unit is T
    kal_uint32 if_rlt = 0; ///< read latency time, unit is T
    kal_uint32 if_clk_freq = 0; ///< unit is Hz

#if !defined(__NLD_CENTRAL_CTRL__)

#if defined (MT5931) || defined(WIFI_BB_MT5921) || defined(MT6252H) || defined(MT6252)
    /* for adjust LCD Driving current */   
    kal_uint8 wndrv_lcd_current;
    wndrv_lcd_current = wndrv_set_lcd_driving_current();
    
    if (0 == wndrv_lcd_current)
    {
        //for 2.8V NFI
        set_lcd_driving_current(LCD_DRIVING_6MA);
    }
    else if (1 == wndrv_lcd_current)
    {
        //for 1.8V NFI
        set_lcd_driving_current(LCD_DRIVING_8MA);
    }
    else
    {
        //should not be here, set the default value
        set_lcd_driving_current(LCD_DRIVING_6MA);
    }
#endif

#endif  /* defined(__NLD_CENTRAL_CTRL__) */

    wndrv_lcd_channel = wndrv_get_lcd_channel();    

    if (0 == wndrv_lcd_channel)
    {
#if defined(MT6276) || defined(MT6256)|| defined(MT6255)
        /* set LCD bus timing */
        if_clk_freq = 104 * 1000000;
        if_c2wh = WNDRV_EHPI_C2WH_TIME;
        if_c2ws = WNDRV_EHPI_C2WS_TIME;
        if_wst = WNDRV_EHPI_WST_TIME;
        if_c2rh = WNDRV_EHPI_C2RH_TIME;
        if_c2rs = WNDRV_EHPI_C2RS_TIME;
        if_rlt = WNDRV_EHPI_RLT_TIME;
#else
        /* Adjust WiFi appropriate LCD bus timing for 52Mhz */
         if_c2ws = WNDRV_EHPI_CE2WR_SETUP_TIME;
         if_c2wh = 0;
#if defined (MT5931)
        if_c2rs = 1;
        if_c2rh = 1;
#else         
        if_c2rs = WNDRV_EHPI_C2RS_TIME;
#endif
         if_wst = WNDRV_EHPI_WR_WAIT_STATE_TIME;
#if defined (WIFI_BB_MT5911)
         if_rlt = 4;
#elif defined (MT5931) || defined (WIFI_BB_MT5921)
         if_rlt = WNDRV_EHPI_RD_LATENCY_TIME;
#endif
#if defined(MT6238) || defined(MT6235) || defined(MT6235B) || defined(MT6239)
        /* MT6238 LCD bus clock / 2 = 104Mhz / 2 = 52Mhz */ 
        if_clk_freq = 26 * 1000000;
#elif defined(MT6268)
        if_clk_freq = 61 * 1000000;
    #elif defined(MT6253) || defined(MT6253E) || defined(MT6252H) || defined(MT6252)
        if_clk_freq = 52 * 1000000;        
#elif defined(MT6236) || defined(MT6236B)        
        if_clk_freq = 52 * 1000000;        
#endif
#endif /* #if defined(MT6276) || defined(MT6256) */
   }
   else if(1 == wndrv_lcd_channel)
   {
#if defined(MT6276) || defined(MT6256)|| defined(MT6255)
        /* set LCD bus timing */
        if_clk_freq = 104 * 1000000;
        if_c2wh = WNDRV_EHPI_C2WH_TIME;
        if_c2ws = WNDRV_EHPI_C2WS_TIME;
        if_wst = WNDRV_EHPI_WST_TIME;
        if_c2rh = WNDRV_EHPI_C2RH_TIME;
        if_c2rs = WNDRV_EHPI_C2RS_TIME;
        if_rlt = WNDRV_EHPI_RLT_TIME;
#else
        /* Adjust WiFi appropriate LCD bus timing for 52Mhz */     	  
        if_c2ws = WNDRV_EHPI_CE2WR_SETUP_TIME;
        if_c2wh = 0;
#if defined (MT5931)
        if_c2rs = 1;
        if_c2rh = 1;
#else        
        if_c2rs = WNDRV_EHPI_C2RS_TIME;
#endif
        if_wst = WNDRV_EHPI_WR_WAIT_STATE_TIME;
#if defined (WIFI_BB_MT5911)
        if_rlt = 4;
#elif defined (MT5931) || defined (WIFI_BB_MT5921)
        if_rlt = WNDRV_EHPI_RD_LATENCY_TIME;
#endif


#if defined(MT6238) || defined(MT6235) || defined(MT6235B) || defined(MT6239)
        /* MT6238 LCD bus clock / 2 = 104Mhz / 2 = 52Mhz */ 
        if_clk_freq = 26 * 1000000;
#elif defined(MT6268)
        if_clk_freq = 61 * 1000000;
#elif defined(MT6253) || defined(MT6253E) || defined(MT6252H) || defined(MT6252)
        if_clk_freq = 52 * 1000000;
#elif defined(MT6236) || defined(MT6236B)      
        if_clk_freq = 52 * 1000000;
#endif
#endif /* #if defined(MT6276) || defined(MT6256) */
   }
#if !defined(MT6253) && !defined(MT6253E) && !defined(MT6252H) || !defined(MT6252) // 6253 no channel 2
   else if(2 == wndrv_lcd_channel)
   {
        /* Adjust WiFi appropriate LCD bus timing for 52Mhz */
#if defined(MT6276) || defined(MT6256)|| defined(MT6255)
        /* set LCD bus timing */
        if_clk_freq = 104 * 1000000;
        if_c2wh = WNDRV_EHPI_C2WH_TIME;
        if_c2ws = WNDRV_EHPI_C2WS_TIME;
        if_wst = WNDRV_EHPI_WST_TIME;
        if_c2rh = WNDRV_EHPI_C2RH_TIME;
        if_c2rs = WNDRV_EHPI_C2RS_TIME;
        if_rlt = WNDRV_EHPI_RLT_TIME;
#else
   	    if_c2ws = WNDRV_EHPI_CE2WR_SETUP_TIME;
        if_c2wh = 0;
#if defined (MT5931)
        if_c2rs = 1;
        if_c2rh = 1;
#else
        if_c2rs = WNDRV_EHPI_C2RS_TIME;
#endif
        if_wst = WNDRV_EHPI_WR_WAIT_STATE_TIME;
        if_rlt = 3;
#if defined (WIFI_BB_MT5911)
        if_rlt = 4;
#elif defined (MT5931) || defined (WIFI_BB_MT5921)
        if_rlt = WNDRV_EHPI_RD_LATENCY_TIME;
#endif

               
#if defined(MT6238) || defined(MT6235) || defined(MT6235B) || defined(MT6239)
        /* MT6238 LCD bus clock / 2 = 104Mhz / 2 = 52Mhz */ 
        if_clk_freq = 26 * 1000000;
#elif defined(MT6268)
        if_clk_freq = 61 * 1000000;
#elif defined(MT6253) || defined(MT6253E) || defined(MT6252H) || defined(MT6252)
        if_clk_freq = 52 * 1000000;
#elif defined(MT6236) || defined(MT6236B)        
        if_clk_freq = 52 * 1000000;
#endif      
#endif /* #if defined(MT6276) || defined(MT6256) */      
   }
#endif /*!defined(MT6253) */   

    //get power control handle
    {
        wifi_lcd_power_ctrl_handle =  lcd_power_ctrl__register_module();
        lcd_power_ctrl__enable(wifi_lcd_power_ctrl_handle);
    }

    // Register LCD I/F manager... (for WIFI)
    {
        LCD_IOCTRL_RESULT_E err;

        // get handle
        wifi_lcd_if_mgr_port_handle = lcd_get_ioctrl_device_if_handle(LCD_IF_USER_WIFI);
        wifi_if_setting.if_type = LCD_IF_TYPE_DBI_PARALLEL;
        wifi_if_setting.if_cs_no = wndrv_lcd_channel; //chip select number (0, 1, 2 ?)
        wifi_if_setting.if_settings.dbi_parallel_if.if_cs_no =  wndrv_lcd_channel;
#if defined (MT5931)
        if (wndrv_get_bus_config() == WNDRV_BUS_EHPI_8BIT) {
            wifi_if_setting.if_settings.dbi_parallel_if.if_bus_width = 8;//desired bus width
        }
        else if (wndrv_get_bus_config() == WNDRV_BUS_EHPI_16BIT) {
            wifi_if_setting.if_settings.dbi_parallel_if.if_bus_width = 16;//desired bus width
        }
#else
#if SUPPORT_EHPI_8
        wifi_if_setting.if_settings.dbi_parallel_if.if_bus_width = 8;//desired bus width
#else
        wifi_if_setting.if_settings.dbi_parallel_if.if_bus_width = 16;//desired bus width
#endif
#endif
        wifi_if_setting.if_settings.dbi_parallel_if.if_c2ws = if_c2ws;         //write setup time(check LCD spec for more information)
        wifi_if_setting.if_settings.dbi_parallel_if.if_wst = if_wst;           //write wait state time(check LCD spec for more information)
        wifi_if_setting.if_settings.dbi_parallel_if.if_c2wh = if_c2wh;        //write hold time(check LCD spec for more information)
        wifi_if_setting.if_settings.dbi_parallel_if.if_c2rs = if_c2rs;          //read setup time(check LCD spec for more information)
        wifi_if_setting.if_settings.dbi_parallel_if.if_c2rh = if_c2rh;         //read hold time(check LCD spec for more information)
        wifi_if_setting.if_settings.dbi_parallel_if.if_rlt = if_rlt;             //read latency time (check LCD spec for more information)
        wifi_if_setting.if_settings.dbi_parallel_if.if_set_common_period = KAL_FALSE;  ///< KAL_TRUE to set HW register as below if_period value
        wifi_if_setting.if_settings.dbi_parallel_if.if_clk_freq = if_clk_freq;   //desired interface frequency value ex: 104 * 1000000 (104MHz)

        //wifi_if_setting.if_settings.dbi_parallel_if.add_driving_current = ; //you can ignore this field now¡K

        // Configure LCD HW register by calling the following function
       err = lcd_ioctrl_device_if_settings(wifi_lcd_if_mgr_port_handle, 
                                           LCD_IOCTRL_CONFIG_DEVICE_IF, 
                                           &wifi_if_setting, 
                                           sizeof(LCD_IOCTRL_DEVICE_IF_T));
       if (LCD_IOCTRL_OK != err)
       {
          // do error handling
          ASSERT(0);
       }

       //Backup IF register setting...
       err = lcd_ioctrl_device_if_settings(wifi_lcd_if_mgr_port_handle,
                                           LCD_IOCTRL_QUERY_DEVICE_IF, 
                                           &wifi_if_setting, 
                                           sizeof(LCD_IOCTRL_DEVICE_IF_T));

       *hpi_ctrl_addr = wifi_if_setting.if_settings.dbi_parallel_if.if_data_port_addr;
       *hpi_data_addr = wifi_if_setting.if_settings.dbi_parallel_if.if_cmd_port_addr;
    }
}

#ifdef DRV_HIF_V2
void WiFi_InitHIFBus(HIF_HANDLE *hif_handle_ptr, HIF_CONFIG_T *hif_config_param_ptr)
{
    HIF_RESULT status;
#if !defined(__NLD_CENTRAL_CTRL__)   
   NLI_ARB_SET_QUERY_HANDOVER_COUNT_STRUCT lcd_handover_data;

   /* for adjust NLI arbiter handover time start */    
#if defined(MT6255)
    lcd_handover_data.handover_en = NLI_ARB_HANDOVER_LEAVE_HIF0_EN;
    lcd_handover_data.enable = KAL_TRUE;
    lcd_handover_data.handover_cycle = 1;
    
    NLI_ARB_init();
    NLI_ARB_IOCtrl( NLI_ARB_USER_HIF0, NLI_ARB_SET_HANDOVER_COUNT, &lcd_handover_data );
#endif
    /* for adjust NLI arbiter handover time end */

#endif  /* defined(__NLD_CENTRAL_CTRL__) */
#if defined(__FLAVOR_16BITLCM_WIFI__) && defined(MT6250)  
   *hif_handle_ptr = hif_open(3);
#else
	 *hif_handle_ptr = hif_open(1);
#endif
   status = hif_power_ctrl(*hif_handle_ptr, KAL_TRUE);
   ASSERT( status == HIF_RESULT_OK );

#if defined(MT6276) || defined(MT6256)|| defined(MT6255) || defined(MT6250) || defined(MT6260)
    #if defined(MT5931)
#if defined(MT6276)
   hif_config_param_ptr->hif_time_c2ws = 0x3;
   hif_config_param_ptr->hif_time_c2wh = 0x1;
   hif_config_param_ptr->hif_time_wst = 0x7;
   hif_config_param_ptr->hif_time_chw = 0x6;
   hif_config_param_ptr->hif_time_c2rs = 0x1;
   hif_config_param_ptr->hif_time_c2rh = 0x0;
   hif_config_param_ptr->hif_time_rlt = 0x5;
   hif_config_param_ptr->hif_base_clk = 122;
#elif defined(MT6256)|| defined(MT6255)
	hif_config_param_ptr->hif_time_c2ws = 0x4;
   hif_config_param_ptr->hif_time_c2wh = 0x3;
   hif_config_param_ptr->hif_time_wst = 0xD;
   hif_config_param_ptr->hif_time_chw = 0xA;
   hif_config_param_ptr->hif_time_c2rs = 0x1;
   hif_config_param_ptr->hif_time_c2rh = 0x0;
   hif_config_param_ptr->hif_time_rlt = 0xA;
   hif_config_param_ptr->hif_base_clk = 104;
#elif defined(MT6250)
   hif_config_param_ptr->hif_time_c2ws = 0x2;
   hif_config_param_ptr->hif_time_c2wh = 0x1;
   hif_config_param_ptr->hif_time_wst = 0x7;
   hif_config_param_ptr->hif_time_chw = 0x6;
   hif_config_param_ptr->hif_time_c2rs = 0x1;
   hif_config_param_ptr->hif_time_c2rh = 0x0;
   hif_config_param_ptr->hif_time_rlt = 0x5;
   hif_config_param_ptr->hif_base_clk = 130;
#elif defined(MT6260)
   #if defined(__EMI_CLK_166MHZ__)
   hif_config_param_ptr->hif_time_c2ws = 0x2;
   hif_config_param_ptr->hif_time_c2wh = 0x1;
   hif_config_param_ptr->hif_time_wst = 0x8;
   hif_config_param_ptr->hif_time_chw = 0x7;
   hif_config_param_ptr->hif_time_c2rs = 0x1;
   hif_config_param_ptr->hif_time_c2rh = 0x0;
   hif_config_param_ptr->hif_time_rlt = 0x6;
   hif_config_param_ptr->hif_base_clk = 166;
   #elif defined(__EMI_CLK_130MHZ__)
   hif_config_param_ptr->hif_time_c2ws = 0x2;
   hif_config_param_ptr->hif_time_c2wh = 0x1;
   hif_config_param_ptr->hif_time_wst = 0x6;
   hif_config_param_ptr->hif_time_chw = 0x6;
   hif_config_param_ptr->hif_time_c2rs = 0x1;
   hif_config_param_ptr->hif_time_c2rh = 0x0;
   hif_config_param_ptr->hif_time_rlt = 0x5;
   hif_config_param_ptr->hif_base_clk = 130;
   #elif defined(__EMI_CLK_104MHZ__)
   hif_config_param_ptr->hif_time_c2ws = 0x2;
   hif_config_param_ptr->hif_time_c2wh = 0x1;
   hif_config_param_ptr->hif_time_wst = 0x5;
   hif_config_param_ptr->hif_time_chw = 0x5;
   hif_config_param_ptr->hif_time_c2rs = 0x1;
   hif_config_param_ptr->hif_time_c2rh = 0x0;
   hif_config_param_ptr->hif_time_rlt = 0x4;
   hif_config_param_ptr->hif_base_clk = 104;
   #else
   # error, unsupported 6260 HIF clock.
   #endif
#endif /* #if defined(MT6276) */
    #else
   hif_config_param_ptr->hif_time_c2ws = 0x4;
   hif_config_param_ptr->hif_time_c2wh = 0x3;
   hif_config_param_ptr->hif_time_wst = 0xD;
   hif_config_param_ptr->hif_time_chw = 0xA;
   hif_config_param_ptr->hif_time_c2rs = 0x1;
   hif_config_param_ptr->hif_time_c2rh = 0x0;
   hif_config_param_ptr->hif_time_rlt = 0xA;
#if defined(MT6276)
   hif_config_param_ptr->hif_base_clk = 122;
#elif defined(MT6256)|| defined(MT6255)
   hif_config_param_ptr->hif_base_clk = 104;
#endif   
		#endif
#endif /* #if defined(MT6276) */ 
#if defined (MT5931)
   if (wndrv_get_bus_config() == WNDRV_BUS_EHPI_8BIT) {
       hif_config_param_ptr->hif_bus_width = 8;
   }
   else if (wndrv_get_bus_config() == WNDRV_BUS_EHPI_16BIT) {
       hif_config_param_ptr->hif_bus_width = 16;
   }
#else
   #if SUPPORT_EHPI_8
   hif_config_param_ptr->hif_bus_width = 8;
   #else
   hif_config_param_ptr->hif_bus_width = 16;
   #endif /* SUPPORT_EHPI_8 */
#endif
   status = hif_config(*hif_handle_ptr, hif_config_param_ptr);
   ASSERT( status == HIF_RESULT_OK );

}
#endif /* DRV_HIF_V2 */

void WiFi_AssignEINT (void)
{
    kal_uint8 wndrv_eint_channel;
    wndrv_eint_channel = custom_eint_get_channel( wifi_eint_chann );
    // To prevent use wrong EINT
    if (wndrv_eint_channel != EINT_CHANNEL_NOT_EXIST)
    {
#if defined(MT6225) 
        switch (wndrv_eint_channel)
        {
            case 4:
                /* GPIO0 = MODE3(EINT4) */
	            WiFi_GPIO_ModeSetup(0, 3);
	            break;
	        case 5:
                /* GPIO1 = MODE3(EINT5) */
                WiFi_GPIO_ModeSetup(1, 3);
                break;
            case 6:
                /* GPIO2 = MODE3(EINT6) */
                WiFi_GPIO_ModeSetup(2, 3);
                break;
            case 7:
                /* GPIO3 = MODE3(EINT7) */
                WiFi_GPIO_ModeSetup(3, 3);
                break;
            default:
            /* only handle EINT4~7*/
            break;
        }              
#elif defined(MT6228) || defined(MT6229) || defined(MT6230)
        switch (wndrv_eint_channel)
        {
            case 4:
                /* no EINT4 */
                //DisplayPopup((kal_uint8*)L"Do not use EINT4 on this chip!", IMG_GLOBAL_ERROR, 0, 5000, 0);
                ASSERT(0);
                break;
            case 5:
                /* GPIO35 = MODE0(GPIO input = EINT5) */
                WiFi_GPIO_ModeSetup(35, 0);
                //GPIO_InitIO(0, 35);/* 0=input, 1=output*/
                WiFi_InitGPIO(0, 35);/* 0=input, 1=output*/
                break;
            case 6:
                /* GPIO37 = MODE1(UART2 RXD = EINT6) */
                //DisplayPopup((kal_uint8*)L"Do not use EINT6 on this chip!", IMG_GLOBAL_ERROR, 0, 5000, 0);
                ASSERT(0);
                break;
            case 7:
                /* GPIO8 = MODE0(GPIO input = EINT7) */
                WiFi_GPIO_ModeSetup(8, 0);
                //GPIO_InitIO(0, 8);/* 0=input, 1=output*/
                WiFi_InitGPIO(0, 8);
                break;
#if defined(MT6229) || defined(MT6230)
				   case 8:
                /* GPIO63 = MODE2(USB-OTG ID = EINT8) */
               	WiFi_GPIO_ModeSetup(63, 2);
                //GPIO_InitIO(0, 63);/* 0=input, 1=output*/	
                WiFi_InitGPIO(0, 63);			
                break;
#endif
            default:
                /* only handle EINT4~7(8)*/
                break;
        }
#elif (defined(MT6238)||defined(MT6239))
        switch (wndrv_eint_channel)
        {
            case 0:
                /* GPIO77 = Mode1(EINT0) */
                WiFi_GPIO_ModeSetup(77, 1);
                break;
            case 1:
                /* GPIO78 = Mode1(EINT1) */
                WiFi_GPIO_ModeSetup(78, 1);
                break;
            case 2:
                /* GPIO79 = Mode1(EINT2) */
                WiFi_GPIO_ModeSetup(79, 1);
                break;
            case 3:
                /* GPIO33 = Mode1(EINT3) */
                WiFi_GPIO_ModeSetup(33, 1);
                break;
            case 4:
                /* GPIO34 = Mode1(EINT4) */
                WiFi_GPIO_ModeSetup(34, 1);
                break;
            case 5:
                /* GPIO35 = Mode1(EINT5) */
                WiFi_GPIO_ModeSetup(35, 1);
                break;
            case 6:
                /* GPIO36 = Mode1(EINT6) */
                WiFi_GPIO_ModeSetup(36, 1);
                break;
            case 7:
                /* GPIO37 = Mode1(EINT7) */
                WiFi_GPIO_ModeSetup(37, 1);
                break;
        }
        
#elif (defined(MT6235)||defined(MT6235B))
        switch (wndrv_eint_channel)
        {
        case 3:
        	/* GPIO44 = MODE1(GPIO input = EINT3) */
        	WiFi_GPIO_ModeSetup(44, 1);
          break;
        case 4:
        	/* GPIO45 = MODE1(GPIO input = EINT4) */
        	WiFi_GPIO_ModeSetup(45, 1);
          break;
        case 5:
        	/* GPIO46 = MODE1(GPIO input = EINT5) */
        	WiFi_GPIO_ModeSetup(46, 1);
        	break;
        case 6:
        	/* GPIO47 = MODE1(GPIO input = EINT6) */
        	WiFi_GPIO_ModeSetup(47, 1);
        	break;
        case 7:
        	/* GPIO48 = MODE1(GPIO input = EINT7) */
        	WiFi_GPIO_ModeSetup(48, 1);
        	break;
        default:
        	/* only handle EINT4~7*/
        	break;
        }
#elif defined(MT6236) || defined(MT6236B)
    switch (wndrv_eint_channel)
    {
            case 0:
                /* GPIO41 = Mode1(EINT0) */
                WiFi_GPIO_ModeSetup(41, 1);
                break;
            case 1:
                /* GPIO42 = Mode1(EINT1) */
                WiFi_GPIO_ModeSetup(42, 1);
                break;
            case 2:
                /* GPIO43 = Mode1(EINT2) */
                WiFi_GPIO_ModeSetup(43, 1);
                break;
            case 3:
                /* GPIO44 = Mode1(EINT3) */
                WiFi_GPIO_ModeSetup(44, 1);
                break;
            case 4:
                /* GPIO52 = Mode1(EINT4) */
                WiFi_GPIO_ModeSetup(52, 1);
                break;
            case 5:
                /* GPIO53 = Mode1(EINT5) */
                WiFi_GPIO_ModeSetup(53, 1);
                break;
            case 6:
                /* GPIO54 = Mode1(EINT6) */
                WiFi_GPIO_ModeSetup(54, 1);
                break;
    }
    
#elif defined(MT6268)
    switch (wndrv_eint_channel)
    {
            case 0:
                /* GPIO94 = Mode1(EINT0) */
                WiFi_GPIO_ModeSetup(94, 1);
                break;
            case 1:
                /* GPIO95 = Mode1(EINT1) */
                WiFi_GPIO_ModeSetup(95, 1);
                break;        
            case 2:
                /* GPIO49 = Mode1(EINT2) */
                WiFi_GPIO_ModeSetup(49, 1);
                break;
            case 3:
                /* GPIO50 = Mode1(EINT3) */
                WiFi_GPIO_ModeSetup(50, 1);
                break;
            case 4:
                /* GPIO96 = Mode1(EINT4) */
                WiFi_GPIO_ModeSetup(96, 1);
                break;
            case 5:
                /* GPIO97 = Mode1(EINT5) */
                WiFi_GPIO_ModeSetup(97, 1);
                break;
            case 6:
                /* GPIO82 = Mode1(EINT6) */
                WiFi_GPIO_ModeSetup(82, 1);
                break;
            case 7:
                /* GPIO83 = Mode1(EINT7) */
                WiFi_GPIO_ModeSetup(83, 1);
                break;
    }
#elif defined(MT6253T) || defined(MT6253) 
    switch (wndrv_eint_channel)
    {
            case 0:
                /* GPIO64 = Mode1(EINT0) */
                WiFi_GPIO_ModeSetup(64, 1);
                break;
            case 1:
                /* GPIO63 = Mode1(EINT1) */
                WiFi_GPIO_ModeSetup(63, 1);
                break;        
            case 2:
                /* GPIO62 = Mode1(EINT2) */
                WiFi_GPIO_ModeSetup(62, 1);
                break;
            case 3:
                /* GPIO61 = Mode1(EINT3) */
                WiFi_GPIO_ModeSetup(61, 1);
                break;
            case 4:
                /* GPIO01 = Mode2(EINT4) */
                WiFi_GPIO_ModeSetup(1, 2);
                break;
            case 5:
                /* GPIO08 = Mode2(EINT5) */
                WiFi_GPIO_ModeSetup(8, 2);
                break;
            case 6:
                /* GPIO76 = Mode2(EINT6) */
                WiFi_GPIO_ModeSetup(76, 2);
                break;        
    }
#elif defined(MT6253E)
		switch (wndrv_eint_channel)
		{
			case 0:
				/* GPIO42 = Mode1(EINT0) */
				WiFi_GPIO_ModeSetup(42, 1);
				break;
			case 1:
				/* GPIO43 = Mode1(EINT1) */
				WiFi_GPIO_ModeSetup(43, 1);
				break;	
			case 2:
				/* GPIO26 = Mode2(EINT2) */
				WiFi_GPIO_ModeSetup(26, 2);
				break;
			case 3:
				/* GPIO45 = Mode2(EINT3) */
				WiFi_GPIO_ModeSetup(45, 2);
				break;
			case 4:
				/* GPIO01 = Mode2(EINT4) */
				WiFi_GPIO_ModeSetup(1, 2);
			  break;
			case 5:
				/* GPIO08 = Mode2(EINT5) */
				WiFi_GPIO_ModeSetup(8, 2);
			  break;
			case 6:
				/* GPIO36 = Mode1(EINT6) */
				//EINT6 if GPIO_SPMODE [8] is 1, MCINS if GPIO_SPMODE [8] is 0
				WiFi_GPIO_ModeSetup(36, 1);
				break;
			default:
					//DisplayPopup((kal_uint8*)L"Please assign valid BT_EINT_NO!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}            
#elif defined(MT6252H) 
		switch (wndrv_eint_channel)
		{
			case 0:
				/* GPIO26 = Mode1(EINT0) */
				WiFi_GPIO_ModeSetup(26, 1);
				break;
			case 1:
				/* GPIO27 = Mode1(EINT1) */
				WiFi_GPIO_ModeSetup(27, 1);
				break;	
			default:
					//DisplayPopup((kal_uint8*)L"Please assign valid BT_EINT_NO!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					//ASSERT(0);
					//EINT 2~6 may go to one of their two GPIO pins, not configure here
				break;
		}

#elif defined(MT6252)
		switch (wndrv_eint_channel)
		{
			case 0:
				/* GPIO26 = Mode1(EINT0) */
				WiFi_GPIO_ModeSetup(26, 1);
				break;
			case 1:
				/* GPIO27 = Mode1(EINT1) */
				WiFi_GPIO_ModeSetup(27, 1);
				break;
			case 2:
				/* GPIO43 = Mode2(EINT2) */
				WiFi_GPIO_ModeSetup(43, 2);
				break;
			case 3:
				/* GPIO45 = Mode2(EINT3) */
				WiFi_GPIO_ModeSetup(45, 2);
				break;
			case 4:
				/* GPIO01 = Mode2(EINT4) */
				WiFi_GPIO_ModeSetup(1, 2);
			  break;
			case 5:
				/* GPIO24 = Mode2(EINT5) */
				WiFi_GPIO_ModeSetup(24, 5);
			  break;
			case 6:
				/* GPIO36 = Mode1(EINT6) */
				//EINT6 if GPIO_SPMODE [8] is 1, MCINS if GPIO_SPMODE [8] is 0
				WiFi_GPIO_ModeSetup(36, 5);
				break;
			default:
					//DisplayPopup((kal_uint8*)L"Please assign valid BT_EINT_NO!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					//ASSERT(0);
					//EINT 2~6 may go to one of their two GPIO pins, not configure here
			    break;
		}

#elif defined(MT6276)
    switch (wndrv_eint_channel)
    {
#if defined(MT6276_S00) // MT6276 E1
            case 0:
                /* GPIO14 = Mode1(EINT0) */
                WiFi_GPIO_ModeSetup(14, 1);
                break;
            case 1:
                /* GPIO15 = Mode1(EINT1) */
                WiFi_GPIO_ModeSetup(15, 1);
                break;
            case 2:
                /* GPIO16 = Mode1(EINT2) */
                WiFi_GPIO_ModeSetup(16, 1);
                break;
            case 3:
                /* GPIO54 = Mode1(EINT3) */
                WiFi_GPIO_ModeSetup(54, 1);
                break;
            case 4:
                /* GPIO90 = Mode3(EINT4) */
                WiFi_GPIO_ModeSetup(90, 3);
                break;
            case 5:
                /* GPIO91 = Mode3(EINT5) */
                WiFi_GPIO_ModeSetup(91, 3);
                break;
            case 6:
                /* GPIO30 = Mode2(EINT6) */
                WiFi_GPIO_ModeSetup(30, 2);
                break;
            case 7:
                /* GPIO31 = Mode2(EINT7) */
                WiFi_GPIO_ModeSetup(31, 2);
                break;
            case 8:
                /* GPIO50 = Mode3(EINT8) */
                WiFi_GPIO_ModeSetup(50, 3);
                break;
            case 9:
                /* GPIO4 = Mode3(EINT9) */
                WiFi_GPIO_ModeSetup(4, 3);
                break;
            case 10:
                /* GPIO101 = Mode2(EINT10) */
                WiFi_GPIO_ModeSetup(101, 2);
                break;
            case 11:
                /* GPIO81 = Mode3(EINT11) */
                WiFi_GPIO_ModeSetup(81, 3);
                break;
            case 12:
                /* GPIO85 = Mode2(EINT12) */
                WiFi_GPIO_ModeSetup(85, 2);
                break;
            case 13:
                /* GPIO86 = Mode2(EINT13) */
                WiFi_GPIO_ModeSetup(86, 2);
                break;
            case 14:
                /* GPIO20 = Mode2(EINT14) */
                WiFi_GPIO_ModeSetup(20, 2);
                break;
            case 15:
                /* GPIO21 = Mode2(EINT15) */
                WiFi_GPIO_ModeSetup(21, 2);
                break;
            case 16:
                /* GPIO28 = Mode2(EINT16) */
                WiFi_GPIO_ModeSetup(28, 2);
                break;
            case 17:
                /* GPIO29 = Mode2(EINT17) */
                WiFi_GPIO_ModeSetup(86, 2);
                break;

#elif defined(MT6276_S01)// MT6276 E2
            case 0:
                /* GPIO33 = Mode1(EINT0) */
                WiFi_GPIO_ModeSetup(33, 1);
                break;
            case 1:
                /* GPIO34 = Mode1(EINT1) */
                WiFi_GPIO_ModeSetup(34, 1);
                break;
            case 2:
                /* GPIO35 = Mode1(EINT2) */
                WiFi_GPIO_ModeSetup(35, 1);
                break;
            case 3:
                /* GPIO20 = Mode1(EINT3) */
                WiFi_GPIO_ModeSetup(20, 1);
                break;
            case 4:
                /* GPIO21 = Mode1(EINT4) */
                // Do not configure this EINT, becasue this EINT4 may go to GPIO21 Mode1 or GPIO88 Mode3
                //WiFi_GPIO_ModeSetup(21, 1);
                break;
            case 5:
                /* GPIO89 = Mode3(EINT5) */
                WiFi_GPIO_ModeSetup(89, 3);
                break;
            case 6:
                /* GPIO14 = Mode3(EINT6) */
                WiFi_GPIO_ModeSetup(14, 3);
                break;
            case 7:
                /* GPIO13 = Mode3(EINT7) */
                WiFi_GPIO_ModeSetup(13, 3);
                break;
            case 8:
                /* GPIO31 = Mode3(EINT8) */
                WiFi_GPIO_ModeSetup(31, 3);
                break;
            case 9:
                /* GPIO0 = Mode3(EINT9) */
                WiFi_GPIO_ModeSetup(0, 3);
                break;
            case 10:
                /* GPIO99 = Mode2(EINT10) */
                WiFi_GPIO_ModeSetup(99, 2);
                break;
            case 11:
                /* GPIO73 = Mode3(EINT11) */
                WiFi_GPIO_ModeSetup(73, 3);
                break;
            case 12:
                /* GPIO77 = Mode2(EINT12) */
                WiFi_GPIO_ModeSetup(77, 2);
                break;
            case 13:
                /* GPIO78 = Mode2(EINT13) */
                WiFi_GPIO_ModeSetup(78, 2);
                break;
            case 14:
                /* GPIO38 = Mode2(EINT14) */
                WiFi_GPIO_ModeSetup(38, 2);
                break;
            case 15:
                /* GPIO39 = Mode2(EINT15) */
                WiFi_GPIO_ModeSetup(39, 2);
                break;
            case 16:
                /* GPIO46 = Mode2(EINT16) */
                WiFi_GPIO_ModeSetup(46, 2);
                break;
            case 17:
                /* GPIO47 = Mode2(EINT17) */
                WiFi_GPIO_ModeSetup(47, 2);
                break;
#else // Other MT6276 ECO chips
            case 0:
                /* GPIO33 = Mode1(EINT0) */
                WiFi_GPIO_ModeSetup(33, 1);
                break;
            case 1:
                /* GPIO34 = Mode1(EINT1) */
                WiFi_GPIO_ModeSetup(34, 1);
                break;
            case 2:
                /* GPIO35 = Mode1(EINT2) */
                WiFi_GPIO_ModeSetup(35, 1);
                break;
            case 3:
                /* GPIO20 = Mode1(EINT3) */
                WiFi_GPIO_ModeSetup(20, 1);
                break;
            case 4:
                /* GPIO21 = Mode1(EINT4) */
                // Do not configure this EINT, becasue this EINT4 may go to GPIO21 Mode1 or GPIO88 Mode3
                //WiFi_GPIO_ModeSetup(21, 1);
                break;
            case 5:
                /* GPIO89 = Mode3(EINT5) */
                WiFi_GPIO_ModeSetup(89, 3);
                break;
            case 6:
                /* GPIO14 = Mode3(EINT6) */
                WiFi_GPIO_ModeSetup(14, 3);
                break;
            case 7:
                /* GPIO13 = Mode3(EINT7) */
                WiFi_GPIO_ModeSetup(13, 3);
                break;
            case 8:
                /* GPIO31 = Mode3(EINT8) */
                WiFi_GPIO_ModeSetup(31, 3);
                break;
            case 9:
                /* GPIO0 = Mode3(EINT9) */
                WiFi_GPIO_ModeSetup(0, 3);
                break;
            case 10:
                /* GPIO99 = Mode2(EINT10) */
                WiFi_GPIO_ModeSetup(99, 2);
                break;
            case 11:
                /* GPIO73 = Mode3(EINT11) */
                WiFi_GPIO_ModeSetup(73, 3);
                break;
            case 12:
                /* GPIO77 = Mode2(EINT12) */
                WiFi_GPIO_ModeSetup(77, 2);
                break;
            case 13:
                /* GPIO78 = Mode2(EINT13) */
                WiFi_GPIO_ModeSetup(78, 2);
                break;
            case 14:
                /* GPIO38 = Mode2(EINT14) */
                WiFi_GPIO_ModeSetup(38, 2);
                break;
            case 15:
                /* GPIO39 = Mode2(EINT15) */
                WiFi_GPIO_ModeSetup(39, 2);
                break;
            case 16:
                /* GPIO46 = Mode2(EINT16) */
                WiFi_GPIO_ModeSetup(46, 2);
                break;
            case 17:
                /* GPIO47 = Mode2(EINT17) */
                WiFi_GPIO_ModeSetup(47, 2);
                break;
#endif // #if defined(MT6276_S00)

    }

#elif defined(MT6255)
    switch (wndrv_eint_channel)
    {
            case 0:
                /* GPIO61 = Mode1(EINT0) */
                WiFi_GPIO_ModeSetup(61, 1);
                break;
            case 1:
                /* GPIO62 = Mode1(EINT1) */
                WiFi_GPIO_ModeSetup(62, 1);
                break;
            case 2:
                /* GPIO63 = Mode1(EINT2) */
                WiFi_GPIO_ModeSetup(63, 1);
                break;
            case 3:
                /* GPIO15 = Mode2(EINT3) */
                WiFi_GPIO_ModeSetup(15, 2);
                break;
            case 4:
                /* GPIO16 = Mode2(EINT4) */
                WiFi_GPIO_ModeSetup(16, 2);
                break;
            case 5:
                /* GPIO1 = Mode2(EINT5) */
                WiFi_GPIO_ModeSetup(1, 2);
                break;
            case 6:
                /* GPIO2 = Mode2(EINT6) */
                WiFi_GPIO_ModeSetup(2, 2);
                break;
            case 7:
                /* GPIO76 = Mode2(EINT7) */
                WiFi_GPIO_ModeSetup(76, 2);
                break;
            case 8:
                /* GPIO77 = Mode2(EINT8) */
                WiFi_GPIO_ModeSetup(77, 2);
                break;
            case 9:
                /* GPIO60 = Mode2(EINT9) */
                WiFi_GPIO_ModeSetup(60, 2);
                break;
            case 10:
                /* GPIO59 = Mode2(EINT10) */
                WiFi_GPIO_ModeSetup(59, 2);
                break;
            case 11:
                /* GPIO71 = Mode1(EINT11) */
                WiFi_GPIO_ModeSetup(71, 1);
                break;
            case 12:
                /* GPIO1 = Mode4(EINT12) */
                WiFi_GPIO_ModeSetup(1, 4);
                break;
    }

#elif defined(MT6256)
    switch (wndrv_eint_channel)
    {
            case 0:
                /* GPIO72 = Mode1(EINT0) */
                WiFi_GPIO_ModeSetup(61, 1);
                break;
            case 1:
                /* GPIO73 = Mode1(EINT1) */
                WiFi_GPIO_ModeSetup(62, 1);
                break;
            case 2:
                /* GPIO74 = Mode1(EINT2) */
                WiFi_GPIO_ModeSetup(63, 1);
                break;
            case 3:
                /* GPIO15 = Mode2(EINT3) */
                WiFi_GPIO_ModeSetup(64, 1);
                break;
            case 4:
                /* GPIO16 = Mode2(EINT4) */
                WiFi_GPIO_ModeSetup(65, 1);
                break;
            case 5:
                /* GPIO1 = Mode2(EINT5) */
                WiFi_GPIO_ModeSetup(72, 2);
                break;
            case 6:
                /* GPIO2 = Mode2(EINT6) */
                WiFi_GPIO_ModeSetup(79, 5);
                break;
            case 7:
                /* GPIO76 = Mode2(EINT7) */
                WiFi_GPIO_ModeSetup(6, 3);
                break;
            case 8:
                /* GPIO77 = Mode2(EINT8) */
                WiFi_GPIO_ModeSetup(7, 3);
                break;
            case 9:
                /* GPIO60 = Mode2(EINT9) */
                WiFi_GPIO_ModeSetup(103, 2);
                break;
            case 10:
                /* GPIO59 = Mode2(EINT10) */
                WiFi_GPIO_ModeSetup(12, 3);
                break;
            case 11:
                /* GPIO71 = Mode1(EINT11) */
                WiFi_GPIO_ModeSetup(78, 2);
                break;
    }
#elif defined(MT6250)
		switch (wndrv_eint_channel)
		{
			case 0:
				/* GPIO66 = Mode1(EINT0) */
				WiFi_GPIO_ModeSetup(66, 1);
				break;
			case 1:
				/* GPIO28 = Mode6(EINT1) */
				WiFi_GPIO_ModeSetup(28, 6);
				break;
			case 2:
				/* GPIO5 = Mode5(EINT2) */
				WiFi_GPIO_ModeSetup(5, 5);
				break;
			case 3:
				/* GPIO11 = Mode2(EINT3) */
				WiFi_GPIO_ModeSetup(11, 2);
				break;
			case 4:
				/* GPIO27 = Mode1(EINT4) */
				WiFi_GPIO_ModeSetup(27, 1);
				break;
			case 5:
				/* GPIO29 = Mode1(EINT5) */
				WiFi_GPIO_ModeSetup(29, 1);
				break;
			case 6:
				/* GPIO33 = Mode4(EINT6) */
				WiFi_GPIO_ModeSetup(33, 4);
				break;
			case 7:
				/* GPIO34 = Mode2(EINT7) */
				WiFi_GPIO_ModeSetup(34, 2);
				break;
			case 8:
				/* GPIO51 = Mode2(EINT8) */
				WiFi_GPIO_ModeSetup(51, 2);
				break;
			case 9:
				/* GPIO60 = Mode2(EINT9) */
				WiFi_GPIO_ModeSetup(60, 2);
				break;
			case 10:
				/* GPIO74 = Mode2(EINT10) */
				WiFi_GPIO_ModeSetup(74, 2);
				break;
			case 11:
				/* GPIO25 = Mode3(EINT11) */
				WiFi_GPIO_ModeSetup(25, 3);
				break;
			case 22:
				/* GPIO107 = Mode1(EINT22) */
				WiFi_GPIO_ModeSetup(107, 1);
				break;
			default:
                break;
		}    
#elif defined(MT6260)
		switch (wndrv_eint_channel)
		{
			/************D-DIE**********/
			case 1:
				/*GPIO5 mode 3 == EINT1*/
				WiFi_GPIO_ModeSetup(5, 3);
				break;
			case 2:
				/*GPIO10 mode 3 == EINT2*/
				WiFi_GPIO_ModeSetup(10, 3);
				break;
			case 3:
				/*GPIO11 mode 3 == EINT3*/
				WiFi_GPIO_ModeSetup(11, 3);
				break;
			case 4:
				/*GPIO22 mode 3 == EINT4*/
				WiFi_GPIO_ModeSetup(22, 3);
				break;
			case 5:
				/*GPIO24 mode 1 == EINT5*/
				WiFi_GPIO_ModeSetup(24, 1);
				break;
			case 6:
				/*GPIO44 mode 3 == EINT6*/
				WiFi_GPIO_ModeSetup(44, 3);
				break;
			case 7:
				/*GPIO56 mode 3 == EINT7*/
				WiFi_GPIO_ModeSetup(56, 3);
				break;
			case 8:
				/*GPIO61 mode 3 == EINT8*/
				WiFi_GPIO_ModeSetup(61, 3);
				break;
				
			/************A-DIE**********/
			case 30:
				/*AGPI75 mode 2 == EINT30*/
				WiFi_GPIO_ModeSetup(75, 2);
				break;
			case 31:
				/*AGPI76 mode 2 == EINT31*/
				WiFi_GPIO_ModeSetup(76, 2);
				break;
			case 32:
				/*AGPI77 mode 2 == EINT32*/
				WiFi_GPIO_ModeSetup(77, 2);
				break;
			case 33:
				/*AGPI78 mode 2 == EINT33*/
				WiFi_GPIO_ModeSetup(78, 2);
				break;
			case 34:
				/*AGPI80 mode 1 == EINT34*/
				WiFi_GPIO_ModeSetup(80, 1);
				break;
			case 35:
				/*AGPI81 mode 1 == EINT35*/
				WiFi_GPIO_ModeSetup(81, 1);
				break;
			case 36:
				/*AGPI82 mode 1 == EINT36*/
				WiFi_GPIO_ModeSetup(82, 1); //default
				break;
			default:
				break;
		}  
#elif (defined(MT6261)||defined(MT2501)||defined(MT2502))
		switch (wndrv_eint_channel)
		{
			case 0:
				/*GPIO0 mode 1 == EINT0*/
				WiFi_GPIO_ModeSetup(0, 1);
				break;
			case 1:
				/*GPIO1 mode 2 == EINT1*/
				WiFi_GPIO_ModeSetup(1, 2);
				break;
			case 2:
				/*GPIO2 mode 1 == EINT2*/
				WiFi_GPIO_ModeSetup(2, 1);
				break;
			case 3:
				/*GPIO4 mode 1 == EINT3*/
				WiFi_GPIO_ModeSetup(4, 1);
				break;
			case 4:
				/*GPIO5 mode 1 == EINT4*/
				WiFi_GPIO_ModeSetup(5, 1);
				break;
			case 5:
				/*GPIO6 mode 1 == EINT5*/
				WiFi_GPIO_ModeSetup(6, 1);
				break;
			case 6:
				/*GPIO7 mode 1 == EINT6*/
				WiFi_GPIO_ModeSetup(7, 1);
				break;
			case 7:
				/*GPIO8 mode 1 == EINT7*/
				WiFi_GPIO_ModeSetup(8, 1);
				break;
			case 8:
				/*GPIO9 mode 1 == EINT8*/
				WiFi_GPIO_ModeSetup(9, 1);
				break;
			case 9:
				/*GPIO10 mode 3 == EINT9*/
				WiFi_GPIO_ModeSetup(10, 3);
				break;
			case 10:
				/*GPIO11 mode 3 == EINT10*/
				WiFi_GPIO_ModeSetup(11, 3);
				break;
			case 11:
				/*GPIO13 mode 2 == EINT11*/
				WiFi_GPIO_ModeSetup(13, 2);
				break;
			case 12:
				/*GPIO14 mode 2 == EINT12*/
				WiFi_GPIO_ModeSetup(14, 2);
				break;
			case 13:
				/*GPIO18 mode 2 == EINT13*/
				WiFi_GPIO_ModeSetup(18, 2);
				break;
			case 14:
				/*GPIO20 mode 2 == EINT14*/
				WiFi_GPIO_ModeSetup(20, 2);
				break;
			case 15:
				/*GPIO25 mode 4 == EINT15*/
				WiFi_GPIO_ModeSetup(25, 4);
				break;
			case 16:
				/*GPIO30 mode 4 == EINT16*/
				WiFi_GPIO_ModeSetup(30, 4);
				break;
			case 17:
				/*GPIO34 mode 2 == EINT17*/
				WiFi_GPIO_ModeSetup(34, 2);
				break;
			case 18:
				/*GPIO35 mode 2 == EINT18*/
				WiFi_GPIO_ModeSetup(35, 2);
				break;
			case 19:
				/*GPIO36 mode 2 == EINT19*/
				WiFi_GPIO_ModeSetup(36, 2);
				break;
			case 20:
				/*GPIO46 mode 2 == EINT20*/
				WiFi_GPIO_ModeSetup(46, 2);
				break;
			case 21:
				/*GPIO48 mode 2 == EINT21*/
				WiFi_GPIO_ModeSetup(48, 2);
				break;
			case 22:
				/*GPIO50 mode 2 == EINT22*/
				WiFi_GPIO_ModeSetup(50, 2);
				break;
			case 23:
				/*GPIO52 mode 1 == EINT23*/
				WiFi_GPIO_ModeSetup(52, 1);
				break;
			case 24:
				/*GPIO53 mode 2 == EINT24*/
				WiFi_GPIO_ModeSetup(53, 2);
				break;
			default:
				break;
		}
#else
	#error this is a new baseband chip, please notify CS6 to modify GPIO/EINT configurations for WiFi!
#endif
    }/*if (gpio->num_wakeupHost != EINT_CHANNEL_NOT_EXIST)*/
}
#if defined (MT5931)
kal_uint8 WiFi_GetCoclockMode(kal_uint8 numCoclk)
{
    kal_uint8 modeCoclk = 0xFF;
#if defined(MT6276)
	  switch (numCoclk)
    {
        case (GPIO_MAGIC_NUM | 14): //SRCLKENAI0
			      modeCoclk = 4;
			      break;
        case (GPIO_MAGIC_NUM | 19): //SRCLKENAI1
			      modeCoclk = 3;
			      break;
			  case (GPIO_MAGIC_NUM | 21): //SRCLKENAI2
			      modeCoclk = 3;
			      break;
        case (GPIO_MAGIC_NUM | 80): //SRCLKENAI3
			      modeCoclk = 3;
			      break;
			  case (GPIO_MAGIC_NUM | 81): //SRCLKENAI3
			      modeCoclk = 3;
			      break;
			  default:
				    break;
    }
#elif defined(MT6256)
    switch (numCoclk)
    {
    	  case (GPIO_MAGIC_NUM | 6): //SRCLKENAI
			      modeCoclk = 4;
			      break;
        case (GPIO_MAGIC_NUM | 11): //SRCLKENAI
			      modeCoclk = 5;
			      break;
			  case (GPIO_MAGIC_NUM | 78): //SRCLKENAI
			      modeCoclk = 3;
			      break;
			  default:
			  	  break;
    }
#elif defined(MT6255)
    switch (numCoclk)
    {
    	case (GPIO_MAGIC_NUM | 6): //SRCLKENAI
			      modeCoclk = 4;
			      break;
        case (GPIO_MAGIC_NUM | 11): //SRCLKENAI
			      modeCoclk = 5;
			      break;
		case (GPIO_MAGIC_NUM | 78): //SRCLKENAI
			      modeCoclk = 3;
			      break;
        case (GPIO_MAGIC_NUM | 95): //SRCLKENAI
			      modeCoclk = 5;
			      break;
        case (GPIO_MAGIC_NUM | 101): //SRCLKENAI
			      modeCoclk = 5;
			      break;
	    default:
			  	  break;
    }
#elif defined(MT6250)
		switch (numCoclk)
		{
			case (GPIO_MAGIC_NUM | 105): //SRCLKENAI
					  modeCoclk = 1;
					  break;
			default:
					  break;
		}
#elif defined(MT6260)
		switch (numCoclk)
		{
			case (GPIO_MAGIC_NUM | 73): //SRCLKENAI
					  modeCoclk = 1;
					  break;
			default:
					  break;
		}
#elif (defined(MT6261)||defined(MT2501)||defined(MT2502))
		switch (numCoclk)
		{
			case (GPIO_MAGIC_NUM | 53): //SRCLKENAI
					  modeCoclk = 1;
					  break;
			default:
					  break;
		}

#endif
    return modeCoclk;    			    
}

kal_uint32 wndrv_get_bus_config(void)
{
#if defined (__WIFI_EHPI_8BIT__)
    return WNDRV_BUS_EHPI_8BIT;
#elif defined (__WIFI_EHPI_16BIT__)
    return WNDRV_BUS_EHPI_16BIT;
#endif
}
#endif /* MT5931 */
#endif //#if defined (MT5931) || defined (WIFI_BB_MT5921) || defined (WIFI_BB_MT5911)

/*******************************************************************************
*                                      RF part
********************************************************************************
*/
/*******************************************************************************
*                                      AL2236
********************************************************************************
*/
#endif /* __WIFI_SUPPORT__ */


/* COEXISTENCE */
/* move from \interface\wifi\wifi_bt_coexistence.c */
/*******************************************************************************
* FUNCTION
**      This routine is called to set the user configured Tx Power
**      level in percentage for Airoha RF chipset.
**  parameters:
**      adapter_p - Pointer to the Adapter structure
**      pu1Txpow - buffer of tx power level in percentage
*   BT_exist
*
* DESCRIPTION
*   Set PTA status to ON
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
**      adapter_p - Pointer to the Adapter structure
**      floatLevel - The current ED float level
**  results:
**      marginAGCED_p - Pointer to the AGC ED margin
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_uint8 BT_exist (void)
{
#if defined(__BTMTK__)
    return 1;
#else
    return 0;
#endif
}
#if !defined(__CUSTOM_WIFI_FEATURES_SWITCH__)
/* SYSTEM */
kal_uint32 dymDebounce = 0;
kal_uint8 wndrv_eint_chan;
kal_eventgrpid supc_sim_block_ev_id;

kal_bool  wndrv_chip_isOK (void)
{
    return KAL_FALSE;
}

kal_bool wndrv_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct wndrv_handler_info =
   {
      NULL,  /* task entry function */
      NULL,              /* task initialization function */
      NULL,              /* task configuration function */
      NULL,              /* task reset handler */
      NULL               /* task termination handler */
   };

   *handle = (comptask_handler_struct *)&wndrv_handler_info;
   return KAL_TRUE;
}

kal_bool supc_create(comptask_handler_struct **handle)
{
   static comptask_handler_struct wpa_handler_info =
	{
      NULL,       /* task entry function */
      NULL,         /* task initialization function */
	    NULL,		/* task configuration function */
      NULL,           /* task reset handler */
      NULL          /* task termination handler */
	};

   *handle = &wpa_handler_info;
	return KAL_TRUE;
}

#if defined(__HOTSPOT_SUPPORT__)
kal_bool hostap_task_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct hostap_handler_info =
    {
        NULL,  /* task entry function */
        NULL,  /* task initialization function */
        NULL,           /* task configuration function */
        NULL,           /* task reset handler */
        NULL,           /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*)&hostap_handler_info;

    return KAL_TRUE;
}
#endif /* __HOTSPOT_SUPPORT__ */

void wndrv_HWinit(void)
{
  /* empty */
}

void wndrv_PS_Enable (kal_uint8 handle)
{
	/* empty */
}

/* NVRAM */
void wndrv_cal_dac_dc_offset( wndrv_cal_dac_dc_offset_struct *dcOffset )
{
	/* empty */
}

void wndrv_cal_macaddr( wndrv_cal_mac_addr_struct *mac )
{ 
	/* empty */
}

void wndrv_cal_tx_ALC_power_2400M ( wndrv_cal_tx_ALC_2400M_struct *txALC )
{ 
	/* empty */
}

void wndrv_cal_txpwr_2400M( wndrv_cal_txpwr_2400M_struct *txpwr )
{ 
	/* empty */
}

void wndrv_cal_txpwr_5000M( wndrv_cal_txpwr_5000M_struct *txpwr )
{ 
	/* empty */
}

void wndrv_cal_ALC_Slope_2400M ( wndrv_cal_ALC_Slope_2400M_struct *pALCSlope )
{
	/* empty */
}

/* FT */
kal_bool bwcs_query_single_antenna_capability( void )
{
	return KAL_FALSE;
}

void bwcs_set_antenna_path( kal_bool fgAntForBT )
{
	/* empty */
}

void wndrv_cal_query_chip_capability( wndrv_query_chip_capability_struct *cap )
{
}

/* ABM */
void wndrv_PS_Disable (kal_uint8 handle)
{
	/* empty */
}

kal_uint8 wndrv_PS_GetHandle (kal_int8 *psName)
{
    return 0;
}

/* MMI */
/*kal_int32  wndrv_hdl_lcd_sleep_in(void *event)*/
mmi_ret wndrv_hdl_lcd_sleep_in(mmi_event_struct *event)
{
    return 0;
}

/*kal_int32  wndrv_hdl_lcd_sleep_out(void *event)*/
mmi_ret wndrv_hdl_lcd_sleep_out(mmi_event_struct *event)
{
    return 0;
}
/*can be removed */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*can be removed */

/* TCPIP */
kal_uint32     wndrv_UAPSD_isEnable = KAL_FALSE; 

void wndrv_set_Protocol_Status (kal_uint32 value, kal_uint32 mask)
{
    /* empty */
}

/* EM Mode */
void RFTool_WiFi_BBCR_Write(kal_uint32 bbcr_index, kal_uint8 bbcr)
{
    /* empty */
}

void RFTool_WiFi_BBCR_Read(kal_uint32 bbcr_index, kal_uint8 *bbcr)
{
    /* empty */
}

void RFTool_WiFi_CarrierSupp(kal_uint8 country_code[2], wndrv_test_tx_struct carrier_supp)
{
    /* empty */
}

void RFTool_WiFi_ContTx(kal_uint8 country_code[2], wndrv_test_tx_struct cont_tx)
{
    /* empty */
}

void RFTool_WiFi_DacDCOffset(kal_uint8 *i_ch, kal_uint8 *q_ch)
{
    /* empty */
}

void RFTool_WiFi_EEPROM_Read(kal_uint32 eeprom_index, kal_uint16 *eeprom)
{
    /* empty */
}

void RFTool_WiFi_EEPROM_Write(kal_uint32 eeprom_index, kal_uint16 eeprom)
{
    /* empty */
}

void RFTool_WiFi_EFUSE_Read(kal_uint32 efuse_index, kal_uint32 *efuse)
{
    /* empty */
}

void RFTool_WiFi_EFUSE_Write(kal_uint32 efuse_index, kal_uint32 efuse)
{
    /* empty */
}

void RFTool_WiFi_EnterNormalMode(void)
{
    /* empty */
}

void RFTool_WiFi_EnterTestMode(void)
{
    /* empty */
}

void RFTool_WiFi_LocalFreq(kal_uint8 country_code[2], wndrv_test_tx_struct local_freq)
{
    /* empty */
}

void RFTool_WiFi_MCR16_Read(kal_uint32 mcr_index, kal_uint16 *mcr16)
{
    /* empty */
}

void RFTool_WiFi_MCR16_Write(kal_uint32 mcr_index, kal_uint16 mcr16)
{
    /* empty */
}

void RFTool_WiFi_MCR32_Read(kal_uint32 mcr_index, kal_uint32 *mcr32)
{
    /* empty */
}

void RFTool_WiFi_MCR32_Write(kal_uint32 mcr_index, kal_uint32 mcr32)
{
    /* empty */
}

void RFTool_WiFi_PktRx(kal_uint32 ch_freq, void (* callback) (wndrv_test_rx_status_struct* result))
{
    /* empty */
}

void RFTool_WiFi_PktTx(kal_uint8 country_code[2], wndrv_test_pkt_tx_struct pkt_tx)
{
    /* empty */
}

void RFTool_WiFi_PwrMgt(wndrv_test_pwr_mgt_enum pwr_mgt)
{
    /* empty */
}

void RFTool_WiFi_Stop(void)
{
    /* empty */
}

kal_uint32 wndrv_query_chip_capability(void)
{
    return 0;
}
void wpa_supplicant_set_mode(WPA_SUPC_MODE_TYPE mode)
{
    /* empty */
}
#if defined(__HOTSPOT_SUPPORT__)
void flc2_spdu_hs_callback(flc2_thres_hit_enent_enum event, flc2_pool_id_enum pool_id, void *user_info_ptr)
{
	/* empty */
}
#endif
#endif /* __CUSTOM_WIFI_FEATURES_SWITCH__ */
#endif /* __MTK_TARGET__ */
/* also use for MODIS*/
/* Customer WIFI Feature Switch Query API */
kal_bool WiFi_Feature_Exist(void)
{
#if defined(__WIFI_SUPPORT__)&&(__CUSTOM_WIFI_FEATURES_SWITCH__)
    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}

/*******************************************************************************
* FUNCTION
*   BT_State_Report2WLAN
*
* DESCRIPTION
*   Report BT_State
*
* CALLS
*   None
*
* PARAMETERS
*   kal_uint32 value, kal_uint32 mask
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
void BT_State_Report2WLAN (kal_uint32 value, kal_uint32 mask)
{
#if defined(__WIFI_SUPPORT__)&&(__MTK_TARGET__)&&(__CUSTOM_WIFI_FEATURES_SWITCH__)
    //kal_uint32 _savedMask;

    //_savedMask = SaveAndSetIRQMask();
    kal_take_mutex(wifi_mutex);
    
    BT_STATE_Report2WLAN &= ~mask;
    BT_STATE_Report2WLAN |= value;
    
    kal_give_mutex(wifi_mutex);
    //RestoreIRQMask(_savedMask);
#endif
}

/*******************************************************************************
* FUNCTION
*   WLAN_State_Report2BT
*
* DESCRIPTION
*   Report WLAN State
*
* CALLS
*   None
*
* PARAMETERS
*                             M A C R O S
********************************************************************************
*/

/*******************************************************************************
*              F U N C T I O N   D E C L A R A T I O N S
********************************************************************************
* RETURNS
*   Report WLAN State
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
kal_uint32 WLAN_State_Report2BT (void)
{
#if defined(__WIFI_SUPPORT__)&&(__MTK_TARGET__) && (__CUSTOM_WIFI_FEATURES_SWITCH__)
    kal_uint32 Ret = 0;

    if (Protocol_Status4WLAN & PROTOCOL_VOIP_SIPLOGIN)
    {
        Ret = WLAN_STATE_SIP_LOGIN;
    }
    else if (Protocol_Status4WLAN & PROTOCOL_POC_SIPLOGIN)
    {
        Ret = WLAN_STATE_SIP_LOGIN;
    }
    else
    {
        Ret = 0;
    }
    return Ret;
#else
    return 0;
#endif
}

/*******************************************************************************
* FUNCTION
*   wndrv_PTA_isOFF
*
* DESCRIPTION
*   Set PTA status to OFF
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
void wndrv_PTA_isOFF (void)
{
#if defined(__WIFI_SUPPORT__)&&(__MTK_TARGET__)&&(__CUSTOM_WIFI_FEATURES_SWITCH__)
    //kal_uint32 _savedMask;

    //_savedMask = SaveAndSetIRQMask();
    kal_take_mutex(wifi_mutex);
    
    WNDRV_PTA_isOFF = 1;
    
    kal_give_mutex(wifi_mutex);
    //RestoreIRQMask(_savedMask);
#endif
}

/*******************************************************************************
* FUNCTION
*   wndrv_PTA_isON
*
* DESCRIPTION
*   Set PTA status to ON
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECTED
*   None
*******************************************************************************/
void wndrv_PTA_isON (void)
{
#if defined(__WIFI_SUPPORT__)&&(__MTK_TARGET__)&&(__CUSTOM_WIFI_FEATURES_SWITCH__)
    //kal_uint32 _savedMask;

    //_savedMask = SaveAndSetIRQMask();
    kal_take_mutex(wifi_mutex);
    
    WNDRV_PTA_isOFF = 0;
    
    kal_give_mutex(wifi_mutex);
    //RestoreIRQMask(_savedMask);
#endif
}
void wndrv_dump_gpio_reg (void)
{
#define __WNDRV_DUMP_GPIO_REG__ 
#if defined(__WIFI_SUPPORT__)&&(__MTK_TARGET__)&&(__CUSTOM_WIFI_FEATURES_SWITCH__)&&defined(__WNDRV_DUMP_GPIO_REG__)

	#if defined(MT6250)
		//pmu_en
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "PMUEN_PIN_MOD: reg:0xA0020C10 val:%x",*((volatile unsigned int*)(0xA0020C10)));
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "PMUEN_PIN_DIR: reg:0xA0020000 val:%x",*((volatile unsigned int*)(0xA0020000)));
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "PMUEN_PIN_VAL: reg:0xA0020300 val:%x",*((volatile unsigned int*)(0xA0020300)));
		//rst
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "RESET_PIN_MOD: reg:0xA0020C20 val:%x",*((volatile unsigned int*)(0xA0020C20)));
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "RESET_PIN_DIR: reg:0xA0020010 val:%x",*((volatile unsigned int*)(0xA0020010)));
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "RESET_PIN_VAL: reg:0xA0020310 val:%x",*((volatile unsigned int*)(0xA0020310)));
		//32k
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "__32K_PIN_MOD: reg:0xA0020C30 val:%x",*((volatile unsigned int*)(0xA0020C30)));
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "__32K_CLK_MOD: reg:0xA0020E70 val:%x",*((volatile unsigned int*)(0xA0020E70)));
		//26m
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "__26M_PIN_MOD: reg:0xA0730168 val:%x",*((volatile unsigned int*)(0xA0730168)));
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "_26M_BUFFER_2: reg:0xA0700FE8 val:%x",*((volatile unsigned int*)(0xA0700FE8)));
		//eint
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "EINT_GPIO_MOD: reg:0xA0020C30 val:%x",*((volatile unsigned int*)(0xA0020C30)));
	#elif defined(MT6255)
		//Not ready
	#elif defined(MT6260)
		//pmu_en
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "PMUEN_PIN_VAL: reg:0xA0730138 val:%x",*((volatile unsigned int*)(0xA0730138)));
		//rst
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "RESET_PIN_MOD: reg:0xA0020C20 val:%x",*((volatile unsigned int*)(0xA0020C20)));
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "RESET_PIN_DIR: reg:0xA0020010 val:%x",*((volatile unsigned int*)(0xA0020010)));
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "RESET_PIN_VAL: reg:0xA0020310 val:%x",*((volatile unsigned int*)(0xA0020310)));
		//32k
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "__32K_PIN_MOD: reg:0xA0020C20 val:%x",*((volatile unsigned int*)(0xA0020C20)));
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "__32K_CLK_MOD: reg:0xA0020E00 val:%x",*((volatile unsigned int*)(0xA0020E00)));
		//26m
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "__26M_PIN_MOD: reg:0xA0730144 val:%x",*((volatile unsigned int*)(0xA0730144)));
		//eint
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "EINT_GPIO_MOD: reg:0xA073014C val:%x",*((volatile unsigned int*)(0xA073014C)));
		//bus current/handover cycle/timing
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "_DRV_DATA_PIN: reg:0xA0020800 val:%x",*((volatile unsigned int*)(0xA0020800)));
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "HANDOVER_CYCL: reg:0xA01B001C val:%x",*((volatile unsigned int*)(0xA01B001C)));
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "_HIF_TIMING_1: reg:0xA0190014 val:%x",*((volatile unsigned int*)(0xA0190014)));
		kal_wap_trace(MOD_WNDRV, TRACE_INFO, "_HIF_TIMING_2: reg:0xA0190018 val:%x",*((volatile unsigned int*)(0xA0190018)));
	#endif

#endif
}


#if defined(__WIFI_SUPPORT__)&&(__CUSTOM_WIFI_FEATURES_SWITCH__)

#include "wndrv_cal.h"
#include "wifi_common_config.h"
wndrv_cal_mac_addr_struct wndrv_default_mac_addr = WIFI_DEFAULT_MAC_ADDERSS;

#if defined(WIFI_BB_MT5911)
    #if defined( WIFI_RF_AL2236 )
   const wndrv_cal_txpwr_2400M_struct wndrv_default_txpwr_2400M 
   = WIFI_DEFAULT_TXPWR_2400M;
   #else
   const wndrv_cal_txpwr_2400M_struct wndrv_default_txpwr_2400M
   = WIFI_DEFAULT_TXPWR_2400M;
    #endif
//20081110 add by saker for MT5921 support
#elif defined(WIFI_BB_MT5921) || defined(MT5931)
  const wndrv_cal_txpwr_2400M_struct wndrv_default_txpwr_2400M
  = WIFI_DEFAULT_TXPWR_2400M;
#endif

const wndrv_cal_txpwr_5000M_struct wndrv_default_txpwr_5000M = 
{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 
  1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };

const wndrv_cal_dac_dc_offset_struct wndrv_default_dac_dc_offset= WIFI_DEFAULT_DAC_DC_OFFSET;

const wndrv_cal_tx_ALC_2400M_struct wndrv_default_tx_ALC_pwr = WIFI_DEFAULT_ALC_POWER;

const wndrv_cal_ALC_Slope_2400M_struct wndrv_default_ALC_Slope = WIFI_DEFAULT_ALC_SLOPE;

const wndrv_cal_txpwr_cal_free_flow_struct wndrv_default_TPCFF = WIFI_DEFAULT_TPCFF;

const wndrv_cal_setting_trim_thermo_struct wndrv_cal_setting_trim_thermo= WIFI_DEFAULT_TRIM_THERMO_VAL;

#endif
