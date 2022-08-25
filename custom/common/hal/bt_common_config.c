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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	 bt_common_config.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains common configuration for Bluetooth customization
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "gpio_sw.h"
#include "eint.h"
#include "bt_common_config.h"
#include "dcl.h"
#ifdef MT6318
//#include "pmic6318_sw.h"
#endif
#if defined(MT6238PMU) || defined(MT6235PMU)
//#include "pmu_sw.h"
#endif
#ifdef __BT_USE_UART2__
//#include "uart_sw.h"
#endif

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "intrCtrl.h"
#include "string.h"
#include "stack_config.h"
#include "l1d_reg.h"

/********************************************************************************/
/********************************************************************************/

/*
 * terrence,2013/12/30,sniff parameter setting,usually you should not change that value
 */
 
/*
enum 
{
    MTK_SNIFF_PARA_SET     = 0,   //most of time, use peer device's sniff parameter,if your device is phone/mid
    MTK_SNIFF_PARA_DIALER  = 1,       //most of time,use our sniff parameter,if your device is dialer/box or you really want to use our device's sniff parameter
    MTK_SNIFF_PARA_DIALER1 = 2,      //most of time,use our sniff parameter,if your device is dialer/box or you really want to use our device's sniff parameter
    MTK_SNIFF_PARA_DIALER2 = 3       //most of time,use our sniff parameter,if your device is dialer/box or you really want to use our device's sniff parameter

};*/

#ifdef __BT_DIALER_SUPPORT__
kal_int8 sniff_level_config = 3;   
#else
kal_int8 sniff_level_config = -1;  
#endif

/*
 * terrence,2013/08/02,Class of device setting
 * use_bt_cod_from_custom
 *
 * KAL_TRUE: use cod value setting by custom,the default cod is for phone.
 *                 if your bt device is dialer/headset/A2dp speeker,you shoud set it ture and give the cod value
 * KAL_FALSE:do not use cod value setting by custom.
 * default value is KAL_FALSE(phone)
 */


kal_bool use_bt_cod_from_custom = KAL_FALSE;

kal_bool bqb_cod_from_custom = KAL_FALSE;
/*
 * bt_cod_from_custom
 * class of device(local),host will set this value to controller by HCI command(0x0C24)
 * if use_bt_cod_from_custom == KAL_TRUE, you should set the cod(3 bytes) based on specification
 * COD generater: http://bluetooth-pentest.narod.ru/software/bluetooth_class_of_device-service_generator.html
 */

kal_uint32 bt_cod_from_custom = 0x240404;  //BT box

#ifndef __BT_DISABLE_SSP_SUPPORT__
/**
 * SSP setting, you can config it when it is not defined __BT_DISABLE_SSP_SUPPORT__
 *
 * @authors    mawei
 * @date          2013/9/16
 */
kal_bool  bt_enable_ssp = KAL_TRUE;
#endif

/********************************************************************************/
/********************************************************************************/

//terrence,2013/12/31,unify pairing method config

/*
 *  BT pairing method default config 
 */
#if defined(__BT_JUST_WORK_SUPPORT__) || defined(__IOT__)
Pairing_Type bt_pairing_type_config = FIXED_PIN_AND_SSP_JUST_WORK;
#else
Pairing_Type bt_pairing_type_config = PIN_AND_SSP;
#endif

// BT fixed pin code
#define    BT_PIN_SIZE    4
kal_uint8  bt_pincode[BT_PIN_SIZE] = {0x30,0x30,0x30,0x30}; //default pin code:0000,unicode


/********************************************************************************/
/********************************************************************************/

/*
 * terrence,2013/06/26,BT dialer feature:Low power solution
 * Variables setting by custom
 */
#ifdef __BT_DIALER_SUPPORT__

/*
 * bt_dialer_low_power_support
 *
 * Enable/Disable low power feature for BT dialer.
 * KAL_TRUE: if bt dialer support and the max dialer device links should not more than one (our expected common design scene).
 * KAL_FLASE:if bt dialer support,but max dialer device links may be more than one (may be few customs use in special ).
 * default value is KAL_TRUE,custom can change it according to above rules.
 */
#if !defined( __BT_MAX_LINK_NUM__) || (__BT_MAX_LINK_NUM__ == 1)
kal_bool bt_dialer_low_power_support = KAL_TRUE;
#else
kal_bool bt_dialer_low_power_support = KAL_FALSE;
#endif

/*
 * bt_dialer_max_tx_power_level
 *
 * if disable low power feature,we will ignore this parameter.
 * the max transmit power level when we enable low power feature for BT dialer.
 * the BT tramsmit power level is 0,1,2,3,4,5,6,7 accroding to specification.
 * default value is 4,custom can change it 
 */

kal_uint8 bt_dialer_max_tx_power_level = 4;

#endif

/*
 * terrence,2012/09/12,disable BT controller LMP EDR feature by custom
 * default is enable
 */
 
//KAL_FALSE : Enable controller LMP EDR feature
//KAL_TRUE  : Disable controller LMP EDR feature
kal_bool  BT_EDR_SW_Disable = KAL_FALSE;
kal_bool  BT_EDR_ADV_Disable = KAL_FALSE;

#ifdef __MTK_BT_DUAL_PCM_SWITCH_SUPPORT__

	#if defined(MT6236) || defined(MT6236B)
	    //MT6236 HW_MISC register address:0x80000100
	    #define MT6236_HW_MISC ((APBADDR)(CONFIG_base+0x0100))

		//MT6236 AFE_VBT_CON register address:0x810D0014
		#define MT6236_AFE_VDB_CON ((APBADDR)(AFE_base+0x0014))
	#endif
#endif

/* Maximum bit rate of A2DP profile used,
   depends on the headset capability and the transmission distance,
   232 ~ 478 is suggested to trasfer SBC bitstream */
kal_uint16 BT_A2DP_MAX_BIT_RATE = 345;

//Maxium length for this pattern is 20
//For example: this pattern could be MTKGameStartReq
kal_uint8 SPPClientFirstConnDataPattern[20]={"AT+EMSPPTA"};
//This len is actually length of this pattern
kal_uint8 SPPClientFirstConnDataPatternLen = 10;

/*
* This value will be used as page timeout when we page other device or request name of other device,
* you can enlarger this value for page successful ratio, but the overrall time will be extended
* the measurement is slot, 1 slot=0.000625s,for example:0x3800 slots = 8.96s
* Specification value range:0x0001-0xFFFF,default vaue is 5.12s
*/
kal_uint32 BT_CUSTOM_PAGE_TIMEOUT = 0x3800;
/********************************/
/* Configuration for SPP */
/********************************/

#ifdef __BT_SPP_PROFILE__
kal_uint32 sppContext[SPP_CONTEXT_BUFFER_SIZE/4];
kal_uint32 sppSrvSdpContext[SPP_SRV_SDP_CONTEXT_BUFFER_SIZE/4];
#endif

/********************************/
/* End of configuration for SPP */
/********************************/


/********************************/
/* Configuration for HFP */
/********************************/
#ifdef __BT_HFG_PROFILE__
/*
 * HFG Supported Features
 */
kal_uint32 bt_hfg_features =(
							 #if (defined(VRSI_ENABLE) || defined(VR_ENABLE))
                              HFG_FEATURE_VOICE_RECOGNITION    |
                             #endif
                             #ifdef __BT_INBAND_RING__
                              HFG_FEATURE_RING_TONE            |
                             #endif
                             #ifdef __HF_V15__
                              HFG_FEATURE_ENHANCED_CALL_STATUS |
//                              HFG_FEATURE_ENHANCED_CALL_CTRL   |
//                              HFG_FEATURE_EXTENDED_ERRORS      |
                             #endif
                              HFG_FEATURE_REJECT               |
							  HFG_FEATURE_THREE_WAY_CALLS);
#endif
/********************************/
/* End of configuration for HFP */
/********************************/


#if defined(__BTMTK__)
kal_uint8 BT_MODULE_ID = 3;
#else
kal_uint8 BT_MODULE_ID = 0;
#endif

// The BT_CHIP_ID is used for META tool to check which BT chip is using now
// META will use the value to get the CapID for calibration in the specific NVRAM LID
#if defined(__BTMODULE_MT6601__)
kal_uint8 BT_CHIP_ID = 0x11;
#elif defined(__BTMODULE_MT6611__)
kal_uint8 BT_CHIP_ID = 0x12;
/*
#elif defined(__BTMODULE_RFMD3500__)
kal_uint8 BT_CHIP_ID = 0x21;
#elif defined(__BTMODULE_RFMD4020__)
kal_uint8 BT_CHIP_ID = 0x22;
*/
#elif defined(__BTMODULE_MT6612__) && defined(__BTMODULE_MT6622__) && defined(__BTMODULE_MT6626__)
kal_uint8 BT_CHIP_ID = 0x1A;    // 6612/6622/6626 co-driver
#elif defined(__BTMODULE_MT6612__)
kal_uint8 BT_CHIP_ID = 0x13;
#elif defined(__BTMODULE_MT6616__)
kal_uint8 BT_CHIP_ID = 0x14;
#elif defined(__BTMODULE_MT6236__)
kal_uint8 BT_CHIP_ID = 0x15;
#elif defined(__BTMODULE_MT6256__)
kal_uint8 BT_CHIP_ID = 0x16;
#elif defined(__BTMODULE_MT6276__)
kal_uint8 BT_CHIP_ID = 0x17;
#elif defined(__BTMODULE_MT6622__)
kal_uint8 BT_CHIP_ID = 0x18;
#elif defined(__BTMODULE_MT6626__)
kal_uint8 BT_CHIP_ID = 0x19;
#elif defined(__BTMODULE_MT6255__)
kal_uint8 BT_CHIP_ID = 0x1B;
#elif defined(__BTMODULE_MT6250__)
kal_uint8 BT_CHIP_ID = 0x1C;
#elif defined(__BTMODULE_MT6260__)
kal_uint8 BT_CHIP_ID = 0x1D;
#elif defined(__BTMODULE_MT6261__)
kal_uint8 BT_CHIP_ID = 0x1E;
#elif defined(__BTMODULE_MT2501__)
kal_uint8 BT_CHIP_ID = 0x1F;
#elif defined(__BTMODULE_MT2502__)
kal_uint8 BT_CHIP_ID = 0x20;
#else
kal_uint8 BT_CHIP_ID = 0;
#endif

/* For PTA and AFH customization */

kal_uint8 BT_CUSTOM_PTA_ON = 0;
kal_uint8 BT_CUSTOM_AFH_SETTING[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F};

#if defined(__BTMODULE_MT6601__)
/* No PTA Configuration for MT6601 */
#endif

#if defined(__BTMODULE_MT6611__)
kal_uint8 BT_CUSTOM_PTA_WIFI_CH = 0;
kal_uint8 BT_CUSTOM_PTA_WIFI_HB = 10;
#if defined (__WIFI_SUPPORT__)
kal_uint8 BT_CUSTOM_PTA_SETTING[] = {0xCF, 0x8B, 0xBF, 0x10, 0x08, 0xA2, 0x92, 0x96, 0x07, 0x1B};
#else
kal_uint8 BT_CUSTOM_PTA_SETTING[] = {0xC8, 0x8B, 0xBF, 0x10, 0x00, 0x52, 0x92, 0x96, 0x07, 0x1B};
#endif
#endif


#if defined(__BTMODULE_MT6612__) || defined(__BTMODULE_MT6622__) || defined(__BTMODULE_MT6626__)
kal_uint8 BT_CUSTOM_PTA_WIFI_CH_6612 = 0;
kal_uint8 BT_CUSTOM_PTA_WIFI_HB_6612 = 10;
#if defined (__WIFI_SUPPORT__)
kal_uint8 BT_CUSTOM_PTA_SETTING_6612[] = {0xCF, 0x8B, 0xBF, 0x10, 0x00, 0xA2, 0x8E, 0x92, 0x07, 0x1B};
#else
kal_uint8 BT_CUSTOM_PTA_SETTING_6612[] = {0xC8, 0x8B, 0xBF, 0x10, 0x00, 0x52, 0x8E, 0x92, 0x07, 0x1B};
#endif
#endif

#if defined(__BTMODULE_MT6616__)
kal_uint8 BT_CUSTOM_PTA_WIFI_CH = 0;
kal_uint8 BT_CUSTOM_PTA_WIFI_HB = 10;
#if defined (__WIFI_SUPPORT__)
kal_uint8 BT_CUSTOM_PTA_SETTING[] = {0xCF, 0x8B, 0xBF, 0x10, 0x00, 0x52, 0x89, 0x8C, 0x07, 0x1B};
#else
kal_uint8 BT_CUSTOM_PTA_SETTING[] = {0xC8, 0x8B, 0xBF, 0x10, 0x00, 0x52, 0x8E, 0x92, 0x07, 0x1B};
#endif
#endif

#if defined(__BTMODULE_MT6236__)|| defined(__BTMODULE_MT6276__)
kal_uint8 BT_CUSTOM_PTA_WIFI_CH = 0;
kal_uint8 BT_CUSTOM_PTA_WIFI_HB = 10;
#if defined (__WIFI_SUPPORT__)
#if defined (MT5931)
kal_uint8 BT_CUSTOM_PTA_SETTING[] = {0xCF, 0x8B, 0xBF, 0x00, 0x00, 0x74, 0x84, 0x88, 0x07, 0x1B};
#else
kal_uint8 BT_CUSTOM_PTA_SETTING[] = {0xCF, 0x8B, 0xBF, 0x00, 0x00, 0x72, 0x84, 0x88, 0x07, 0x1B};
#endif
#else
kal_uint8 BT_CUSTOM_PTA_SETTING[] = {0xC8, 0x8B, 0xBF, 0x10, 0x00, 0x52, 0x84, 0x88, 0x07, 0x1B};
#endif
#endif

#if defined(__BTMODULE_MT6256__) || defined(__BTMODULE_MT6255__) || defined(__BTMODULE_MT6250__) || defined(__BTMODULE_MT6260__)
kal_uint8 BT_CUSTOM_PTA_WIFI_CH = 0;
kal_uint8 BT_CUSTOM_PTA_WIFI_HB = 10;
#if defined (__WIFI_SUPPORT__)
#if defined (MT5931)
kal_uint8 BT_CUSTOM_PTA_SETTING[] = {0xCF, 0x8B, 0x1F, 0x04, 0x08, 0xA2, 0x62, 0x56, 0x1F, 0x1B};
#else
kal_uint8 BT_CUSTOM_PTA_SETTING[] = {0xCF, 0x8B, 0x1F, 0x02, 0x08, 0xA2, 0x62, 0x56, 0x1F, 0x1B};
#endif
#else
kal_uint8 BT_CUSTOM_PTA_SETTING[] = {0xCF, 0x8B, 0x1F, 0x02, 0x08, 0xA2, 0x62, 0x56, 0x1F, 0x1B};
#endif
#endif

#if defined(__BTMODULE_MT6261__) || defined(__BTMODULE_MT2501__) || defined(__BTMODULE_MT2502__)
kal_uint8 BT_CUSTOM_PTA_WIFI_CH = 0;
kal_uint8 BT_CUSTOM_PTA_WIFI_HB = 10;
#if defined (__WIFI_SUPPORT__)
#if defined (MT5931)
kal_uint8 BT_CUSTOM_PTA_SETTING[] = {0xC7, 0x8B, 0x1F, 0x01, 0x08, 0xA2, 0x14, 0x14, 0x14, 0x14};
#else
kal_uint8 BT_CUSTOM_PTA_SETTING[] = {0xCF, 0x8B, 0x1F, 0x02, 0x08, 0xA2, 0x62, 0x56, 0x1F, 0x1B};
#endif
#else
kal_uint8 BT_CUSTOM_PTA_SETTING[] = {0xCF, 0x8B, 0x1F, 0x02, 0x08, 0xA2, 0x62, 0x56, 0x1F, 0x1B};
#endif
#endif


#if defined(__BTMODULE_MT6612__) || defined(__BTMODULE_MT6622__) || defined(__BTMODULE_MT6626__)
kal_uint8 BT_CUSTOM_PTA_WIFI_CH_6622 = 0;
kal_uint8 BT_CUSTOM_PTA_WIFI_HB_6622 = 10;
#if defined (__WIFI_SUPPORT__)
#if defined (MT5931)
kal_uint8 BT_CUSTOM_PTA_SETTING_6622[] = {0xCF, 0x8B, 0x1F, 0x04, 0x08, 0xA2, 0x62, 0x56, 0x07, 0x1B};
#else
kal_uint8 BT_CUSTOM_PTA_SETTING_6622[] = {0xCF, 0x8B, 0x1F, 0x02, 0x08, 0xA2, 0x62, 0x56, 0x07, 0x1B};
#endif
#else
kal_uint8 BT_CUSTOM_PTA_SETTING_6622[] = {0xCF, 0x8B, 0x1F, 0x02, 0x08, 0xA2, 0x62, 0x56, 0x07, 0x1B};
#endif
#endif

#if defined(__BTMODULE_MT6612__) || defined(__BTMODULE_MT6622__) || defined(__BTMODULE_MT6626__)
kal_uint8 BT_CUSTOM_PTA_WIFI_CH_6626 = 0;
kal_uint8 BT_CUSTOM_PTA_WIFI_HB_6626 = 10;
#if defined (__WIFI_SUPPORT__)
#if defined (MT5931)
kal_uint8 BT_CUSTOM_PTA_SETTING_6626[] = {0xCF, 0x8B, 0x1F, 0x04, 0x08, 0xA2, 0x62, 0x56, 0x07, 0x1B};
#else
kal_uint8 BT_CUSTOM_PTA_SETTING_6626[] = {0xCF, 0x8B, 0x1F, 0x02, 0x08, 0xA2, 0x62, 0x56, 0x07, 0x1B};
#endif
#else
kal_uint8 BT_CUSTOM_PTA_SETTING_6626[] = {0xCF, 0x8B, 0x1F, 0x02, 0x08, 0xA2, 0x62, 0x56, 0x07, 0x1B};
#endif
#endif

#if 0
/* under construction !*/
/* under construction !*/
#if defined (__WIFI_SUPPORT__)
/* under construction !*/
#else
/* under construction !*/
#endif
#endif

#if defined (AD6548_RF) || defined (AD6546_RF)
kal_uint8 BT_SETTLE_TIME = 0x0C;
#if defined(__BTMODULE_MT6611__)
kal_uint8 LC_SRCLKEN_DLY = 0x0F;
#else
kal_uint8 LC_SRCLKEN_DLY = 0x0F;    //LC Mode = 00, 0x2F
#endif
#else
kal_uint8 BT_SETTLE_TIME = 0x06;
#if defined(__BTMODULE_MT6611__)
kal_uint8 LC_SRCLKEN_DLY = 0x0A;
#else
kal_uint8 LC_SRCLKEN_DLY = 0x0A;    //LC Mode = 00, 0x2A
#endif
#endif

#if defined (__BTMODULE_MT6601__) || defined (__BTMODULE_MT6611__) || defined (__BTMODULE_MT6612__) || defined (__BTMODULE_MT6616__) || defined (__BTMODULE_MT6622__) || defined (__BTMODULE_MT6626__) || defined (__BTMODULE_MT6236__)|| defined(__BTMODULE_MT6256__) || defined(__BTMODULE_MT6276__) || defined(__BTMODULE_MT6255__) || defined(__BTMODULE_MT6250__) || defined(__BTMODULE_MT6260__) || defined(__BTMODULE_MT6261__) || defined(__BTMODULE_MT2501__) || defined(__BTMODULE_MT2502__)

typedef  struct {
	unsigned char num_poweronBT;
	unsigned char pol_poweronBT;
	unsigned char num_resetBT;
	unsigned char pol_resetBT;
	unsigned char num_wakeupHost;
	unsigned char pol_wakeupHost;
	unsigned char num_lpoclk;
	unsigned char mode_lpoclk;
	unsigned char num_urxd3;
	unsigned char num_utxd3;
	unsigned char num_ucts3;
	unsigned char num_urts3;
	unsigned char num_pcmclk;
	unsigned char num_pcmsync;
	unsigned char num_pcmout;
	unsigned char num_pcmin;
} sGPIO4BT;
#if defined (__BTMODULE_MT6616__)
extern kal_uint8 wmt_pcmin_mode;
#else
extern kal_uint8 bt_pcmin_mode;
#endif

#ifdef __CUST_NEW__
extern const char gpio_bt_power_pin;
/*** Notice!!! Please use gpio_bt_reset_pin for BT reset ***/
//extern const char gpio_bt_wakeup_pin;
extern const char gpio_bt_reset_pin;
extern const char gpio_bt_32k_pin;
extern const char gpio_bt_utxd3_pin;
extern const char gpio_bt_urxd3_pin;
extern const char gpio_bt_ucts3_pin;
extern const char gpio_bt_urts3_pin;
extern const char gpio_bt_pcmclk_pin;
extern const char gpio_bt_pcmsync_pin;
extern const char gpio_bt_pcmin_pin;
extern const char gpio_bt_pcmout_pin;
extern const unsigned char  BT_EINT_NO;
#else /* #ifdef __CUST_NEW__ */
#define BT_GPO_MAGIC_NUM	100

extern const unsigned char bt_gpio_setting[16];
#endif /* #ifdef __CUST_NEW__ */

#if defined (__BTMODULE_MT6616__)
#if defined (__MT6616_NO_STP__)
extern void BtRadio_EintIsr(void);
#else
extern void wmt_eint_isr(void);
#endif /* __BTMODULE_MT6616__ */
#else
#if (!defined (__BTMODULE_MT6261__)) && (!defined (__BTMODULE_MT2501__)) && (!defined (__BTMODULE_MT2502__))
extern void BtRadio_EintIsr(void);
#endif
#endif /*__BTMODULE_MT6616__*/

//extern void DisplayPopup(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId);

void BT_HAL_GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
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
					ASSERT(0);
				}
		}
	DclGPIO_Close(handle);
}

void BT_HAL_GPO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada)
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

void BT_HAL_GPIO_InitIO(char direction, char port)
{
	DCL_HANDLE handle;
	handle=DclGPIO_Open(DCL_GPIO,port);
	if(0==direction)
		DclGPIO_Control(handle,GPIO_CMD_SET_DIR_IN,0);
	else if(1==direction)
		DclGPIO_Control(handle,GPIO_CMD_SET_DIR_OUT,0);
	else
		ASSERT(0);
	DclGPIO_Close(handle);
}

void BT_HAL_GPIO_WriteIO(char data, char port)
{
	DCL_HANDLE handle;
	handle=DclGPIO_Open(DCL_GPIO,port);
	if(0==data)
		DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
	else if(1==data)
		DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
	else
		{
			DclGPIO_Close(handle);
			ASSERT(0);
		}
	DclGPIO_Close(handle);
}

void BT_HAL_GPO_WriteIO(char data,char port)
{
	DCL_HANDLE handle;
	handle=DclGPIO_Open(DCL_GPO,port);
	if(0==data)
		DclGPIO_Control(handle,GPO_CMD_WRITE_LOW,0);
	else if(1==data)
		DclGPIO_Control(handle,GPO_CMD_WRITE_HIGH,0);
	else
		{
			DclGPIO_Close(handle);
			ASSERT(0);
		}
	DclGPIO_Close(handle);
}

void BT_HAL_GPIO_SetClkOut(char clk_num, gpio_clk_mode mode)
{
	DCL_HANDLE handle;
	GPIO_CTRL_SET_CLK_OUT_T data;
	handle=DclGPIO_Open(DCL_GPIO_CLK,clk_num);
	data.u2ClkNum=clk_num;
	data.u2Mode=mode;
	DclGPIO_Control(handle,GPIO_CMD_SET_CLK_OUT,(DCL_CTRL_DATA_T*)&data);
	DclGPIO_Close(handle);
}

/*
 * BT co-clock Source Code - Pure EINT
 */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined( __MTK_TARGET__ )
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined( __MTK_TARGET__ )
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif
/*****************************************************************************/

/*
 * BT co-clock Source Code - EINT Mux EINT
 */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined( __MTK_TARGET__ )
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined( __MTK_TARGET__ )
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif
/*****************************************************************************/

/*
 * BT co-clock shell needed for MT6626
 */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************/

void BtRadio_SetupGPIO(char val, unsigned char pin)
{
#ifdef __CUST_NEW__
	if (pin >= GPIO_MAGIC_NUM)
	{
		BT_HAL_GPIO_ModeSetup(pin, val);
	}
	else
	{
		BT_HAL_GPO_ModeSetup(pin, val);
	}
#else /* #ifdef __CUST_NEW__ */
	if (pin >= BT_GPO_MAGIC_NUM)
	{
		BT_HAL_GPO_ModeSetup((pin - BT_GPO_MAGIC_NUM), val);
	}
	else
	{
		BT_HAL_GPIO_ModeSetup(pin, val);
	}
#endif /* #ifdef __CUST_NEW__ */
}

void BtRadio_InitGPIO(char val, unsigned char pin)
{
#ifdef __CUST_NEW__
	if (pin >= GPIO_MAGIC_NUM)
	{
		BT_HAL_GPIO_InitIO(val, pin);
	}
#else /* #ifdef __CUST_NEW__ */
	if (pin < BT_GPO_MAGIC_NUM)
	{
		BT_HAL_GPIO_InitIO(val, pin);
	}
#endif /* #ifdef __CUST_NEW__ */
}

void BtRadio_WriteGPIO(char val, unsigned char pin)
{
#ifdef __CUST_NEW__
	if (pin >= GPIO_MAGIC_NUM)
	{
		BT_HAL_GPIO_WriteIO(val, pin);
	}
	else
	{
		BT_HAL_GPO_WriteIO(val, pin);
	}
#else /* #ifdef __CUST_NEW__ */
	if (pin >= BT_GPO_MAGIC_NUM)
	{
		BT_HAL_GPO_WriteIO(val, (pin - BT_GPO_MAGIC_NUM));
	}
	else
	{
		BT_HAL_GPIO_WriteIO(val, pin);
	}
#endif /* #ifdef __CUST_NEW__ */
}

kal_uint8 BtRadio_SetToGPIOMode(kal_uint8 pin)
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
		BT_HAL_GPO_ModeSetup(pin, gpio_mode);
		return 0;
	}
#else /* #ifdef __CUST_NEW__ */
	if (pin >= BT_GPO_MAGIC_NUM)
	{
		BT_HAL_GPO_ModeSetup((pin - BT_GPO_MAGIC_NUM), gpio_mode);
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

	BT_HAL_GPIO_ModeSetup(pin, gpio_mode);

	return 0;
}

#if defined(MT6238PMU) || defined(MT6235PMU)
static void bt_hal_pmu_set_vbt_sel(PMU_VOLTAGE_ENUM volt)
{
   DCL_HANDLE handle;
   PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
   val.voltage=volt;
   val.mod=VBT;
   handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
   DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
   DclPMU_Close(handle);
}

static void bt_hal_pmu_set_vbt_en(kal_bool enable)
{
   DCL_HANDLE handle;
   PMU_CTRL_LDO_BUCK_SET_EN val;
   val.enable=enable;
   val.mod=VBT;
   handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
   DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
   DclPMU_Close(handle);
}
#endif

void BtRadio_PowerOn(kal_uint8 polBT, kal_uint8 numBT)
{
	if (numBT == 0xFF)
	{
#if (defined(MT6318))
		pmic_vmc_sel(VMC_2_8V);
		pmic_vmc_enable(KAL_TRUE);
#elif defined(MT6238PMU) || defined(MT6235PMU)
    bt_hal_pmu_set_vbt_sel(PMU_VOLT_02_800000_V);
    bt_hal_pmu_set_vbt_en(KAL_TRUE);
#endif
	}
	else
	{
		BtRadio_WriteGPIO(polBT, numBT);  // turn on BT regulator
	}
}

void BtRadio_PowerOff(kal_uint8 polBT, kal_uint8 numBT)
{
#if defined(MT6253T) || defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
/* Set PCM Sync pin as input mode to avoid current leakage. */
    BtRadio_InitGPIO(0, gpio_bt_pcmsync_pin);             // set direction (Input mode)
#endif
	if (numBT == 0xFF)
	{
#if (defined(MT6318))
		pmic_vmc_enable(KAL_FALSE);
#elif defined(MT6238PMU) || defined(MT6235PMU)
    bt_hal_pmu_set_vbt_en(KAL_FALSE);
#endif
	}
	else
	{
		BtRadio_WriteGPIO((1 - polBT), numBT);  // turn off BT regulator
	}
}

#ifdef __CUST_NEW__
    // Nothing
#else
#define GPIO_MAGIC_NUM      (0x80)
#define GPO_MAGIC_NUM       (0x70)
#endif

kal_uint8 BtRadio_GetLpoMode(kal_uint8 numLpo_original)
{
	kal_uint8 modeLpo;
    kal_uint16 numLpo;

    modeLpo = 0xFF;
    numLpo  = 0xFF;
    // Use the same code to support both "CUST_NEW" and "not CUST_NEW"
    // if defined CUST_NEW, stay unchanged.
    // if not defined CUST_NEW, add magic number.
#ifdef __CUST_NEW__
    numLpo  = numLpo_original;
#else   //  __CUST_NEW__

    #if defined(MT6225)
        if ( numLpo_original == 2 )
        {
            numLpo = (GPO_MAGIC_NUM | 2);
        }
        else if ( numLpo_original == 6 )
        {
            numLpo = (GPIO_MAGIC_NUM | 6);
        }
    #else   //  defined(MT6225)
        numLpo = GPIO_MAGIC_NUM | numLpo_original;
    #endif  //  defined(MT6225)

#endif  //  __CUST_NEW__


#if defined(MT6217) || defined(MT6218B)
{
	modeLpo = 2;
}

#elif defined(MT6219) || defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
{
	modeLpo = 3;
}

#elif defined(MT6228) || defined(MT6229) || defined(MT6230)
{
	if (numLpo == (GPIO_MAGIC_NUM | 8))
		modeLpo = 1;
	else
		modeLpo = 3;
}

#elif defined(MT6225)
{
	if ((numLpo == (GPIO_MAGIC_NUM | 6)) || (numLpo == (GPO_MAGIC_NUM | 2)))
		modeLpo = 2;
	else
		modeLpo = 3;
}

#elif defined(MT6223) || defined(MT6223P)
{
	switch (numLpo)
	{
		case (GPIO_MAGIC_NUM | 21):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(0, 4);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 22):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(1, 4);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 23):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(2, 4);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 47):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(3, 4);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 48):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(4, 4);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 49):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(5, 4);
			#endif
			break;
	}
}

#elif defined(MT6238) || defined(MT6239)
{
	switch (numLpo)
	{
		case (GPIO_MAGIC_NUM | 57):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(0, 6);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 58):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(1, 6);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 65):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(2, 6);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 66):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(3, 6);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 8):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(3, 6);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 77):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(4, 6);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 78):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(5, 6);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 50):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(6, 6);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 55):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(7, 6);
			#endif
			break;
	}
}
#elif defined(MT6235) || defined(MT6235D) || defined(MT6235B)
{
	switch (numLpo)
	{
		case (GPIO_MAGIC_NUM | 0):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(0, 6);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 26):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(1, 6);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 27):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(2, 6);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 45):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(3, 6);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 57):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(4, 6);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 64):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(5, 6);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 65):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(6, 6);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 66):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(7, 6);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 73):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(8, 6);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 74):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(9, 6);
			#endif
			break;
	}
}
#elif defined(MT6268)
{
	switch (numLpo)
	{
		case (GPIO_MAGIC_NUM | 37):
		case (GPIO_MAGIC_NUM | 85):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(0, 0x40);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 38):
		case (GPIO_MAGIC_NUM | 90):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(1, 0x40);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 43):
		case (GPIO_MAGIC_NUM | 60):
		case (GPIO_MAGIC_NUM | 80):
		case (GPIO_MAGIC_NUM | 98):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(2, 0x40);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 44):
		case (GPIO_MAGIC_NUM | 81):
		case (GPIO_MAGIC_NUM | 99):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(3, 0x40);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 64):
		case (GPIO_MAGIC_NUM | 82):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(4, 0x40);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 83):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(5, 0x40);
			#endif
			break;
	}
}

#elif defined(MT6268T) || defined(MT6268A) || defined(MT6268H)
{
	switch (numLpo)
	{
		case (GPIO_MAGIC_NUM | 33):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(0, 0x40);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 34):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(1, 0x40);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 39):
		case (GPIO_MAGIC_NUM | 97):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(2, 0x40);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 40):
		case (GPIO_MAGIC_NUM | 98):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(3, 0x40);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 81):
		case (GPIO_MAGIC_NUM | 99):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(4, 0x40);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 100):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(5, 0x40);
			#endif
			break;
	}
}

#elif defined(MT6253T) || defined(MT6253)
{
	switch (numLpo)
	{
		case (GPIO_MAGIC_NUM | 18):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(0, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 3):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(1, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 75):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(2, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 62):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(3, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 61):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(4, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 15):
			modeLpo = 2;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(5, 4);
			#endif
			break;

		case (GPIO_MAGIC_NUM | 74):
			modeLpo = 1;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(6, 4);
			#endif
			break;
	}
}

#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
{
	switch (numLpo)
	{
		case (GPIO_MAGIC_NUM | 26):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(2, 4);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 33):
			modeLpo = 1;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(2, 4);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 34):
			modeLpo = 1;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(6, 4);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 42):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(4, 4);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 43):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(3, 4);
			#endif
			break;
		case (GPIO_MAGIC_NUM | 45):
			modeLpo = 3;
			#if defined(DRV_GPIO_CLK_OUT)
			BT_HAL_GPIO_SetClkOut(5, 4);
			#endif
			break;
	}
}
#else  /* Fix variable:numLpo was set but never used warning*/
{
   switch (numLpo)
   {
       default:
        break;
   }

}
#endif

	return modeLpo;
}



#ifdef __BT_USE_UART2__
#if defined(__BTMODULE_MT6616__)
#if defined(__MT6616_NO_STP__)
extern kal_uint8 bt_uart_port;
#else
extern kal_uint8 wmt_uart_port;
#endif /*__MT6616_NO_STP__*/
#else
extern kal_uint8 bt_uart_port;
#endif /*__BTMODULE_MT6616__*/
#endif

void BtRadio_AssignGpioPins(sGPIO4BT *gpio)
{
#if defined(__MTK_TARGET__)
#ifdef __CUST_NEW__

	// power on pin
	if (gpio_bt_power_pin != 0xFF)
	{
		gpio->num_poweronBT = gpio_bt_power_pin;
	}
	else
	{
		gpio->num_poweronBT = 0xFF;
	}

	gpio->pol_poweronBT = 1;

	// reset pin
	if (gpio_bt_reset_pin == 0xFF)
	{
		//DisplayPopup((kal_uint8*)L"Please assign the gpio_bt_reset_pin!", IMG_GLOBAL_ERROR, 0, 5000, 0);
		ASSERT(0);
	}
	else
	{
		gpio->num_resetBT = gpio_bt_reset_pin;
	}

	gpio->pol_resetBT = 1;

	// wakeup host pin
	if (BT_EINT_NO != EINT_CHANNEL_NOT_EXIST)
	{
		gpio->num_wakeupHost = BT_EINT_NO;
	}
	else
	{
		//DisplayPopup((kal_uint8*)L"Please assign the BT_EINT_NO!", IMG_GLOBAL_ERROR, 0, 5000, 0);
		ASSERT(0);
	}

	gpio->pol_wakeupHost = 1;

	// UART pin
	gpio->num_urxd3 = gpio_bt_urxd3_pin;
	gpio->num_utxd3 = gpio_bt_utxd3_pin;

	gpio->num_ucts3 = 0xFF;		// Non flow control
	gpio->num_urts3 = 0xFF;		// Non flow control

	// lpo clock pin
	gpio->num_lpoclk = gpio_bt_32k_pin;
	gpio->mode_lpoclk = BtRadio_GetLpoMode(gpio_bt_32k_pin);

	if (gpio->mode_lpoclk == 0xFF)
	{
		//DisplayPopup((kal_uint8*)L"Please check the 32KHz clock setting!", IMG_GLOBAL_ERROR, 0, 5000, 0);
		ASSERT(0);
	}

	// PCM pin
	gpio->num_pcmclk = gpio_bt_pcmclk_pin;
	gpio->num_pcmsync = gpio_bt_pcmsync_pin;
	gpio->num_pcmout = gpio_bt_pcmout_pin;
	gpio->num_pcmin = gpio_bt_pcmin_pin;
#else
	// power on pin
	gpio->num_poweronBT = bt_gpio_setting[0];
	gpio->pol_poweronBT = bt_gpio_setting[1];
	// reset pin
	gpio->num_resetBT = bt_gpio_setting[2];
	gpio->pol_resetBT = bt_gpio_setting[3];
	// wake up host pin
	gpio->num_wakeupHost = bt_gpio_setting[4];
	gpio->pol_wakeupHost = bt_gpio_setting[5];
	// UART pin
	gpio->num_urxd3 = bt_gpio_setting[6];
	gpio->num_utxd3 = bt_gpio_setting[7];
	gpio->num_ucts3 = bt_gpio_setting[8];
	gpio->num_urts3 = bt_gpio_setting[9];
	// lpo clock pin
	gpio->num_lpoclk = bt_gpio_setting[10];
//	gpio->mode_lpoclk = bt_gpio_setting[11];
	gpio->mode_lpoclk = BtRadio_GetLpoMode(gpio->num_lpoclk);

	// PCM pin
	gpio->num_pcmclk = bt_gpio_setting[12];
	gpio->num_pcmsync = bt_gpio_setting[13];
	gpio->num_pcmout = bt_gpio_setting[14];
	gpio->num_pcmin = bt_gpio_setting[15];
 #endif

#if defined(MT6253T) || defined(MT6253)
#if defined (__BTMODULE_MT6616__)
        wmt_pcmin_mode = 2;
#else
		bt_pcmin_mode = 2;
#endif
#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
#if defined (__BTMODULE_MT6616__)
        wmt_pcmin_mode = 1;
#else
		bt_pcmin_mode = 1;
#endif
#endif

	if (gpio->num_poweronBT != 0xFF)
	{
		BtRadio_InitGPIO(1, gpio->num_poweronBT);		// set direction (output)
		//BtRadio_SetupGPIO(0, gpio->num_poweronBT);		// set to gpio mode
		BtRadio_SetToGPIOMode(gpio->num_poweronBT);
		BtRadio_WriteGPIO(0, gpio->num_poweronBT);		// set ouput low
	}

	if(gpio->num_resetBT != 0xFF)
	{
		BtRadio_InitGPIO(1, gpio->num_resetBT);			// set direction (output)
		//BtRadio_SetupGPIO(0, gpio->num_resetBT);			// set to gpio mode
		BtRadio_SetToGPIOMode(gpio->num_resetBT);
		BtRadio_WriteGPIO(0, gpio->num_resetBT);			// set ouput low
	}

	BtRadio_InitGPIO(1, gpio->num_urxd3);					// set direction (output)
	//BtRadio_SetupGPIO(0, gpio->num_urxd3);				// set to gpio mode
	BtRadio_SetToGPIOMode(gpio->num_urxd3);
	BtRadio_WriteGPIO(0, gpio->num_urxd3);				// set ouput low

	BtRadio_InitGPIO(1, gpio->num_utxd3);					// set direction (output)
	//BtRadio_SetupGPIO(0, gpio->num_utxd3);				// set to gpio mode
	BtRadio_SetToGPIOMode(gpio->num_utxd3);
	BtRadio_WriteGPIO(0, gpio->num_utxd3);				// set ouput low

	if(gpio->num_ucts3 != 0xFF)
	{
		BtRadio_InitGPIO(1, gpio->num_ucts3);				// set direction (output)
		//BtRadio_SetupGPIO(0, gpio->num_ucts3);			// set to gpio mode
		BtRadio_SetToGPIOMode(gpio->num_ucts3);
		BtRadio_WriteGPIO(0, gpio->num_ucts3);			// set ouput low

		BtRadio_InitGPIO(1, gpio->num_urts3);				// set direction (output)
		//BtRadio_SetupGPIO(0, gpio->num_urts3);			// set to gpio mode
		BtRadio_SetToGPIOMode(gpio->num_urts3);
		BtRadio_WriteGPIO(0, gpio->num_urts3);			// set ouput low
	}

	if(gpio->num_lpoclk != 0xFF)
	{
		BtRadio_InitGPIO(1, gpio->num_lpoclk);				// set direction (output)
		//BtRadio_SetupGPIO(0, gpio->num_lpoclk);			// set to gpio mode
		BtRadio_SetToGPIOMode(gpio->num_lpoclk);
		BtRadio_WriteGPIO(0, gpio->num_lpoclk);			// set ouput low
	}

	if(gpio->num_pcmclk != 0xFF)
	{
		BtRadio_InitGPIO(1, gpio->num_pcmclk);			// set direction (output)
		//BtRadio_SetupGPIO(0, gpio->num_pcmclk);			// set to gpio mode
		BtRadio_SetToGPIOMode(gpio->num_pcmclk);
		BtRadio_WriteGPIO(0, gpio->num_pcmclk);			// set ouput low

		BtRadio_InitGPIO(1, gpio->num_pcmsync);			// set direction (output)
		//BtRadio_SetupGPIO(0, gpio->num_pcmsync);		// set to gpio mode
		BtRadio_SetToGPIOMode(gpio->num_pcmsync);
		BtRadio_WriteGPIO(0, gpio->num_pcmsync);		// set ouput low

		BtRadio_InitGPIO(1, gpio->num_pcmout);			// set direction (output)
		//BtRadio_SetupGPIO(0, gpio->num_pcmout);			// set to gpio mode
		BtRadio_SetToGPIOMode(gpio->num_pcmout);
		BtRadio_WriteGPIO(0, gpio->num_pcmout);			// set ouput low

		BtRadio_InitGPIO(1, gpio->num_pcmin);			// set direction (output)
		//BtRadio_SetupGPIO(0, gpio->num_pcmin);			// set to gpio mode
		BtRadio_SetToGPIOMode(gpio->num_pcmin);
		BtRadio_WriteGPIO(0, gpio->num_pcmin);			// set ouput low
	}
	// To prevent use wrong EINT
	if (gpio->num_wakeupHost != EINT_CHANNEL_NOT_EXIST)
	{
#if defined(MT6253T) || defined(MT6253)
		switch (gpio->num_wakeupHost)
		{
			case 0:
				BT_HAL_GPIO_ModeSetup(64, 1);
				break;
			case 1:
				BT_HAL_GPIO_ModeSetup(63, 1);
				break;
			case 2:
				BT_HAL_GPIO_ModeSetup(62, 1);
				break;
			case 3:
				BT_HAL_GPIO_ModeSetup(61, 1);
				break;
			case 4:
				BT_HAL_GPIO_ModeSetup(1, 2);
			  break;
			case 5:
				BT_HAL_GPIO_ModeSetup(8, 2);
			  break;
			case 6:
				BT_HAL_GPIO_ModeSetup(76, 2);
				break;
			default:
					//DisplayPopup((kal_uint8*)L"Please assign valid BT_EINT_NO!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}
#elif defined(MT6253E) || defined(MT6253L)
		switch (gpio->num_wakeupHost)
		{
			case 0:
				BT_HAL_GPIO_ModeSetup(42, 1);
				break;
			case 1:
				BT_HAL_GPIO_ModeSetup(43, 1);
				break;
			case 2:
				BT_HAL_GPIO_ModeSetup(26, 2);
				break;
			case 3:
				BT_HAL_GPIO_ModeSetup(45, 2);
				break;
			case 4:
				BT_HAL_GPIO_ModeSetup(1, 2);
			  break;
			case 5:
				BT_HAL_GPIO_ModeSetup(8, 2);
			  break;
			case 6:
				//EINT6 if GPIO_SPMODE [8] is 1, MCINS if GPIO_SPMODE [8] is 0
				BT_HAL_GPIO_ModeSetup(36, 1);
				break;
			default:
					//DisplayPopup((kal_uint8*)L"Please assign valid BT_EINT_NO!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}
#elif defined(MT6252H) || defined(MT6252)
		switch (gpio->num_wakeupHost)
		{
			case 0:
				BT_HAL_GPIO_ModeSetup(26, 1);
				break;
			case 1:
				BT_HAL_GPIO_ModeSetup(27, 1);
				break;
			case 2:
				BT_HAL_GPIO_ModeSetup(43, 2);
				break;
			case 3:
				BT_HAL_GPIO_ModeSetup(45, 2);
				break;
			case 4:
				BT_HAL_GPIO_ModeSetup(1, 2);
			  break;
			case 5:
				BT_HAL_GPIO_ModeSetup(8, 2);
			  break;
			case 6:
				//EINT6 if GPIO_SPMODE [8] is 1, MCINS if GPIO_SPMODE [8] is 0
				BT_HAL_GPIO_ModeSetup(36, 1);
				break;
			default:
					//DisplayPopup((kal_uint8*)L"Please assign valid BT_EINT_NO!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}
#elif defined(MT6268)
		switch (gpio->num_wakeupHost)
		{
			case 0:
				BT_HAL_GPIO_ModeSetup(94, 1);
			  break;
			case 1:
				BT_HAL_GPIO_ModeSetup(95, 1);
			  break;
			case 2:
				BT_HAL_GPIO_ModeSetup(49, 1);
			  break;
			case 3:
				BT_HAL_GPIO_ModeSetup(50, 1);
			  break;
			case 4:
				BT_HAL_GPIO_ModeSetup(96, 1);
				break;
			case 5:
				BT_HAL_GPIO_ModeSetup(97, 1);
				break;
			case 6:
				BT_HAL_GPIO_ModeSetup(82, 1);
				break;
			case 7:
				BT_HAL_GPIO_ModeSetup(83, 1);
				break;
			default:
					//DisplayPopup((kal_uint8*)L"Please assign valid BT_EINT_NO!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}
#elif defined(MT6268T) || defined(MT6268A) || defined(MT6268H)
		switch (gpio->num_wakeupHost)
		{
			case 2:
				BT_HAL_GPIO_ModeSetup(45, 1);
			  break;
			case 3:
				BT_HAL_GPIO_ModeSetup(46, 1);
			  break;
			case 4:
				BT_HAL_GPIO_ModeSetup(96, 1);
				break;
			case 6:
				BT_HAL_GPIO_ModeSetup(99, 1);
				break;
			case 7:
				BT_HAL_GPIO_ModeSetup(100, 1);
				break;
			default:
					//DisplayPopup((kal_uint8*)L"Please assign valid BT_EINT_NO!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}
#elif defined(MT6235) || defined(MT6235D) || defined(MT6235B)
		switch (gpio->num_wakeupHost)
		{
			case 3:
				/* GPIO44 = MODE1(GPIO input = EINT3) */
				BT_HAL_GPIO_ModeSetup(44, 1);
			  break;
			case 4:
				/* GPIO45 = MODE1(GPIO input = EINT4) */
				BT_HAL_GPIO_ModeSetup(45, 1);
			  break;
			case 5:
				/* GPIO46 = MODE1(GPIO input = EINT5) */
				BT_HAL_GPIO_ModeSetup(46, 1);
				break;
			case 6:
				/* GPIO47 = MODE1(GPIO input = EINT6) */
				BT_HAL_GPIO_ModeSetup(47, 1);
				break;
			case 7:
				/* GPIO48 = MODE1(GPIO input = EINT7) */
				BT_HAL_GPIO_ModeSetup(48, 1);
				break;
			default:
				if (gpio->num_wakeupHost > 7)
					//DisplayPopup((kal_uint8*)L"Please assign BT_EINT_NO < 8!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}
#elif defined(MT6238) || defined(MT6239)
		switch (gpio->num_wakeupHost)
		{
			case 0:
				/* GPIO77 = Mode1(EINT0) */
				BT_HAL_GPIO_ModeSetup(77, 1);
				break;
			case 1:
				/* GPIO78 = Mode1(EINT1) */
				BT_HAL_GPIO_ModeSetup(78, 1);
				break;
			case 2:
				/* GPIO79 = Mode1(EINT2) */
				BT_HAL_GPIO_ModeSetup(79, 1);
				break;
			case 3:
				/* GPIO33 = Mode1(EINT3) */
				BT_HAL_GPIO_ModeSetup(33, 1);
				break;
			case 4:
				/* GPIO34 = Mode1(EINT4) */
				BT_HAL_GPIO_ModeSetup(34, 1);
				break;
			case 5:
				/* GPIO35 = Mode1(EINT5) */
				BT_HAL_GPIO_ModeSetup(35, 1);
				break;
			case 6:
				/* GPIO36 = Mode1(EINT6) */
				BT_HAL_GPIO_ModeSetup(36, 1);
				break;
			case 7:
				/* GPIO37 = Mode1(EINT7) */
				BT_HAL_GPIO_ModeSetup(37, 1);
				break;
			default:
				if (gpio->num_wakeupHost > 7)
					//DisplayPopup((kal_uint8*)L"Please assign BT_EINT_NO < 8!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}
#elif defined (MT6223) || defined(MT6223P)
		switch (gpio->num_wakeupHost)
		{
			case 2:
				/* GPIO42 = Mode1(EINT2) */
				BT_HAL_GPIO_ModeSetup(42, 1);
				break;
			case 3:
				/* GPIO43 = Mode1(EINT3) */
				BT_HAL_GPIO_ModeSetup(43, 1);
				break;
			case 4:
				/* GPIO26 = Mode2(EINT4) */
				BT_HAL_GPIO_ModeSetup(26, 2);
				break;
			case 5:
				/* GPIO27 = Mode2(EINT5) */
				BT_HAL_GPIO_ModeSetup(27, 2);
				break;
			case 6:
				/* GPIO28 = Mode2(EINT6) */
				BT_HAL_GPIO_ModeSetup(28, 2);
				break;
			case 7:
				/* GPIO14 = Mode3(EINT7) */
				BT_HAL_GPIO_ModeSetup(14, 3);
				break;
			default:
				if (gpio->num_wakeupHost > 7)
					//DisplayPopup((kal_uint8*)L"Please assign BT_EINT_NO < 8!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}
#elif defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6227D)
		switch (gpio->num_wakeupHost)
		{
			case 4:
				/* GPIO36 = Mode3(EINT4) */
				BT_HAL_GPIO_ModeSetup(36, 3);
				break;
			case 5:
				/* GPIO34 = Mode2(EINT5) */
				BT_HAL_GPIO_ModeSetup(34, 2);
				break;
			case 6:
				/* GPIO35 = Mode3(EINT6) */
				BT_HAL_GPIO_ModeSetup(35, 3);
				break;
			case 7:
				/* GPIO33 = Mode2(EINT7) */
				BT_HAL_GPIO_ModeSetup(33, 2);
				break;
			default:
				if (gpio->num_wakeupHost > 7)
					//DisplayPopup((kal_uint8*)L"Please assign BT_EINT_NO < 8!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}
#elif defined(MT6225)
		switch (gpio->num_wakeupHost)
		{
			case 4:
				/* GPIO0 = MODE3(EINT4) */
				BT_HAL_GPIO_ModeSetup(0, 3);
				break;
			case 5:
				/* GPIO1 = MODE3(EINT5) */
				BT_HAL_GPIO_ModeSetup(1, 3);
				break;
			case 6:
				/* GPIO2 = MODE3(EINT6) */
				BT_HAL_GPIO_ModeSetup(2, 3);
				break;
			case 7:
				/* GPIO3 = MODE3(EINT7) */
				BT_HAL_GPIO_ModeSetup(3, 3);
				break;
			default:
				if (gpio->num_wakeupHost > 7)
					//DisplayPopup((kal_uint8*)L"Please assign BT_EINT_NO < 8!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}
#elif defined(MT6228)
		switch (gpio->num_wakeupHost)
		{
			case 4:
				/* no EINT4 */
				//DisplayPopup((kal_uint8*)L"Do not use EINT4 on this chip!", IMG_GLOBAL_ERROR, 0, 5000, 0);
				ASSERT(0);
				break;
			case 5:
				/* GPIO35 = MODE0(GPIO input = EINT5) */
				BT_HAL_GPIO_ModeSetup(35, 0);
				break;
			case 6:
				/* GPIO37 = MODE1(UART2 RXD = EINT5) */
				BT_HAL_GPIO_ModeSetup(37, 1);
				break;
			case 7:
				/* GPIO8 = MODE0(GPIO input = EINT7) */
				BT_HAL_GPIO_ModeSetup(8, 0);
				break;
			default:
				if (gpio->num_wakeupHost > 7)
					//DisplayPopup((kal_uint8*)L"Please assign BT_EINT_NO < 8!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}
#elif defined(MT6229) || defined(MT6230)
		switch (gpio->num_wakeupHost)
		{
			case 4:
				/* no EINT4 */
				//DisplayPopup((kal_uint8*)L"Do not use EINT4 on this chip!", IMG_GLOBAL_ERROR, 0, 5000, 0);
				ASSERT(0);
				break;
			case 5:
				/* GPIO35 = MODE0(GPIO input = EINT5) */
				BT_HAL_GPIO_ModeSetup(35, 0);
				break;
			case 6:
				/* GPIO37 = MODE1(UART2 RXD = EINT5) */
				BT_HAL_GPIO_ModeSetup(37, 1);
				break;
			case 7:
				/* GPIO8 = MODE0(GPIO input = EINT7) */
				BT_HAL_GPIO_ModeSetup(8, 0);
				break;
			case 8:
				/* GPIO63 = MODE2(EINT8) */
				BT_HAL_GPIO_ModeSetup(63, 2);
				break;
			default:
				if (gpio->num_wakeupHost > 8)
					//DisplayPopup((kal_uint8*)L"Please assign BT_EINT_NO < 9!", IMG_GLOBAL_ERROR, 0, 5000, 0);
					ASSERT(0);
				break;
		}
#elif defined(MT6236) || defined(MT6236B) || defined(MT6256) || defined(MT6276) || defined(MT6255) || defined(MT6250)

        // BB+BT integration chip doesn't need to config common GPIO.
#else
		// #error "This is new baseband chip, please modify GPIO/EINT configurations for bluetooth!"

		// We treat Non-Config GPIO chip as detaul as Integration Chip.
#endif
	}/*if (gpio->num_wakeupHost != EINT_CHANNEL_NOT_EXIST)*/

	if (gpio->num_wakeupHost != 0xFF)
	{
#if defined (__BTMODULE_MT6616__)
#if defined (__MT6616_NO_STP__)
		EINT_Registration(gpio->num_wakeupHost, (kal_bool)0/*no debounce*/, (kal_bool)gpio->pol_wakeupHost, BtRadio_EintIsr, (kal_bool)0/*no auto unmask*/);
#else
    EINT_Registration(gpio->num_wakeupHost, (kal_bool)0/*no debounce*/, (kal_bool)gpio->pol_wakeupHost, wmt_eint_isr, (kal_bool)0/*no auto unmask*/);
#endif /* __MT6616_NO_STP__ */
#else
#if (!defined (__BTMODULE_MT6261__)) && (!defined (__BTMODULE_MT2501__)) && (!defined (__BTMODULE_MT2502__))
		EINT_Registration(gpio->num_wakeupHost, (kal_bool)0/*no debounce*/, (kal_bool)gpio->pol_wakeupHost, BtRadio_EintIsr, (kal_bool)0/*no auto unmask*/);
#endif
#endif /* __BTMODULE_MT6616__ */
	}

#ifdef __BT_USE_UART2__
#if defined(__BTMODULE_MT6616__)
#if defined(__MT6616_NO_STP__)
	  bt_uart_port = uart_port2;
#else
    wmt_uart_port = uart_port2;
#endif /*__MT6616_NO_STP__*/
#else
	bt_uart_port = uart_port2;
#endif /*__BTMODULE_MT6616__*/
#endif
#endif
}

#endif /* #if defined (__BTMODULE_MT6601__) || defined (__BTMODULE_MT6611__) || defined (__BTMODULE_MT6612__) */
#ifdef __BT_SPP_PROFILE__

#ifdef MULTI_RF_CHANNEL
/* number of RFCOMM channels registered in each spp port*/
int spp_ch_number[] = {1, 1};
#endif

/* Check SPP context buffer size  */
kal_bool CheckSPPPortDynamicalSettingBufferSize(kal_uint32 osContextSize,
                                                kal_uint32 sdpServiceSize,
                                                kal_uint32 sdpAttrSize,
                                                kal_uint32 *osBufSize,
                                                kal_uint32 *sdpBufSize,
                                                kal_uint8 devNum,
                                                kal_uint8 scoDevNum)
{
    kal_uint8 sppDevs = 0;
	//kal_uint8 sppSrvDevs = 0;//not used
	kal_uint8 sppSrvNum, sppCliNum;

#if defined (__BT_SPP_SRV_NO_SCO__) || (__BT_SPP_SRV_WITH_SCO__)
    sppSrvNum = NUM_SPP_SERVERS;
#else
	sppSrvNum = 0;
#endif

#if defined (__BT_SPP_CLI_NO_SCO__) || (__BT_SPP_CLI_WITH_SCO__)
    sppCliNum = NUM_SPP_CLIENTS;
#else
    sppCliNum = 0;
#endif

    sppDevs = sppCliNum + sppSrvNum;
	*osBufSize = osContextSize * (sppDevs + devNum);

	if ((sppSrvNum - scoDevNum) >= 1)
	{
        *sdpBufSize = (sdpServiceSize * (sppSrvNum - scoDevNum)) + (sdpAttrSize * (sppSrvNum - scoDevNum - 1));
	}
	else
	{
        *sdpBufSize = 0;
	}

    if((*osBufSize > SPP_CONTEXT_BUFFER_SIZE) || (*sdpBufSize > SPP_SRV_SDP_CONTEXT_BUFFER_SIZE ))
    {
        return KAL_FALSE;
	}
	return KAL_TRUE;
}

/* spp use the context buffer/ sdp buffer/ server/client port num to implments port num dynamic configuatuion */
void BtGet_SPPCustomerConfigurationInfo(kal_uint8** contextBufPtr, kal_uint8** sdpBufPtr, kal_uint8* srvPortNum, kal_uint8* cliPortNum)
{
    *contextBufPtr = (kal_uint8*)sppContext;
	*sdpBufPtr = (kal_uint8*)sppSrvSdpContext;

#if defined (__BT_SPP_SRV_NO_SCO__) || (__BT_SPP_SRV_WITH_SCO__)
    *srvPortNum = NUM_SPP_SERVERS;
#else
	*srvPortNum = 0;
#endif

#if defined (__BT_SPP_CLI_NO_SCO__) || (__BT_SPP_CLI_WITH_SCO__)
    *cliPortNum = NUM_SPP_CLIENTS;
#else
    *cliPortNum = 0;
#endif
}

kal_uint8* BtGet_SPPClientFirstConnDataPattern(kal_uint8* len)
{
    if(SPPClientFirstConnDataPatternLen == 0)
    {
        //Using default setting; pattern = AT+EMSPPTA;
        memset(SPPClientFirstConnDataPattern,0,20);
        SPPClientFirstConnDataPatternLen = strlen("AT+EMSPPTA");
        memcpy(SPPClientFirstConnDataPattern,"AT+EMSPPTA",SPPClientFirstConnDataPatternLen);

    }
    *len = SPPClientFirstConnDataPatternLen;
    return SPPClientFirstConnDataPattern;
}


kal_uint8 CheckCustomSPPClientFirstConnDataPattern()
{

 return CUSTOM_SPP_CHECK_CLIENT_FIRSRT_CONN_DATA;

}

/*
 * The BTGet_Report_RSSI_Timer_Period(),BTGet_Decide_Report_RSSI_Sniff_Mode(),BTGet_Decide_SPP_SCO_Enter_Sniff_Mode()
 * are used by SPP if __BT_SPP_CLI_WITH_SCO__ or __BT_SPP_SRV_WITH_SCO__ is defined
 */
kal_uint16 BTGet_Report_RSSI_Timer_Period()
{
    return CUSTOM_SPP_SCO_READ_RSSI_TIMER_PERIOD_IN_MS;
}

kal_uint8 BTGet_Decide_Report_RSSI_Sniff_Mode()
{
    return CUSTOM_SPP_SCO_REPORT_RSSI_VALUE_IN_SNIFF_MODE;
}

kal_uint8 BTGet_Decide_SPP_SCO_Enter_Sniff_Mode()
{
    return CUSTOM_SPP_SCO_ENABLE_ENTER_SNIFF_FEATURE;
}


kal_bool CheckCustomSPPFlowControlSetting(module_type owner)
{
    /* If the customer change BT SPP Srv or Client Applications's Port owner from MOD_MMI to other MODs
      * to handle TX/RX data based on UART-related messages, once this spp connection is closed:
      * The port owner module must be return a MSG_ID_BT_SPP_UART_PLUGOUT_CNF backs to MOD_BT
      * -> Before BT revcives this msg, it will not reset the spp port owner to default module,
      *      It also implies that if this msg is not received, any incoming spp connection request after that will be rejected
      *      For MOD BT, if this msg is not received, it will think that org port owner is not finished yet!
      * Please fill the module of the SPP port in this function!
      * If the customer does not change the SPP Srv or SPP Client Port owner, it's owner will be MOD_MMI
      * Please see BTMMISPP.c file
      */
#ifdef __BCM_SUPPORT__      
    if ((owner == MOD_BCM))
#else
    if ((owner == MOD_MMI))
#endif
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}
#endif /* __BT_SPP_PROFILE__ */

/********************************/
/* Configuration for HFP        */
/********************************/
#ifdef __BT_HFG_PROFILE__
/*****************************************************************************
 * FUNCTION
 *  bt_hfg_get_supported_feature
 * DESCRIPTION
 *  This function is to get HFG supported features. Features
 *     that will be supported by the application must be advertised to the
 *     hands-free device, so that it knows the capabilities of the audio gateway.
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32	HFG supported features
 *****************************************************************************/
kal_uint32 bt_hfg_get_supported_feature(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	return bt_hfg_features;
}

/*****************************************************************************
 * FUNCTION
 *  bt_hfg_check_supported_feature
 * DESCRIPTION
 *  This function is to check HFG supported feature
 * PARAMETERS
 *  feature_flag	[IN] to check if HFG support this feature.
 * RETURNS
 *  kal_bool	KAL_FALSE means not support
 *				KAL_TRUE means support
 *****************************************************************************/
kal_bool bt_hfg_check_supported_feature(kal_uint32 feature_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_bool result = KAL_FALSE;
	kal_uint32 supported_features;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	supported_features = bt_hfg_get_supported_feature();
	if (supported_features & feature_flag)
	{
		result = KAL_TRUE;
	}
	else
	{
		result = KAL_FALSE;
	}
	return result;
}
#else
kal_uint32 bt_hfg_get_supported_feature(void)
{
    return 0;
}

kal_bool bt_hfg_check_supported_feature(kal_uint32 feature_flag)
{
    return KAL_FALSE;
}

#endif /* __BT_HFG_PROFILE__ */
/********************************/
/* End of configuration for HFP */
/********************************/



/*****************************************************************************
 * FUNCTION
 *  BtRadio_Get_Deafult_Flowcontrol_Setting
 * DESCRIPTION
 *  This function returns default UART3 flowcontrol setting
 * PARAMETERS
 *
 * RETURNS
 *  kal_uint8	0: non-fc
 *              1: hw-fc
 *              2: sw-fc
 *****************************************************************************/
kal_uint8 BtRadio_Get_Deafult_Flowcontrol_Setting(void)
{
    // defined(MT6236) || defined(MT6236B) || defined(MT6256) || defined(MT6276) || defined(MT6255) || defined(MT6250)  is ignored since
    // these chip will not invoke this function

    #if defined(MT6238) || defined(MT6239) || defined(MT6235) || defined(MT6235D) || defined(MT6235B) || defined (MT6223) || defined(MT6223P) || defined(MT6226) || defined(MT6226M) || defined(MT6227) || defined(MT6227D) || defined(MT6225) || defined(MT6228) || defined(MT6229) || defined(MT6230)
        // using non-flow control
        return 0x0;
    #else
        // #if defined(MT6253T) || defined(MT6253) || defined(MT6268) || defined(MT6268T) || defined(MT6268A) || defined(MT6268H) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
        // using software flow control for UART HW buffer
        return 0x2;
    #endif
}

/*
* The return value will be used as page timeout  when we page other device or request name of other device,
* the measurement is slot, 1 slot=0.000625s,for example: 0x3800 slots = 8.96s
** Specification value range:0x0001-0xFFFF,default vaue is 5.12s
*/

kal_uint32 BTGet_Custom_Page_Timeout(void)
{

     return BT_CUSTOM_PAGE_TIMEOUT;

}

kal_bool bt_custom_read_address_from_nvram(void)
{
    return KAL_FALSE;
}


void BtCoClk_Init_Shell(void)
{
}

void BtCoClk_Deinit_Shell(void)
{
}



#ifdef __MTK_BT_DUAL_PCM_SWITCH_SUPPORT__

/*************************************************************
*FUNCTION
*BtRadio_HW_Set_Switch_PCM
*DESCRIPTION
* Write the BT related settings of Baseband side when switch PCM path
* the settings maybe some GPIO or HW register configurations
* kal_uint8 pcm_slect :
* ---0x00:default internal PCM
* ---0x01:external PCM
*
*
**************************************************************/
void BtRadio_HW_Set_Switch_PCM(kal_uint8 pcm_slect)
{

    //A patch for 6236 project
	#if defined(__BTMODULE_MT6236__)


    	//HW_MISC[3]=0
    	//MT6236 HW_MISC register address:0x80000100

    	*MT6236_HW_MISC &= 0xFFF7;

		if (pcm_slect == 0x00)  //PCM1 to GSM
		{
        	//Set up GPIO47/48/49/51 as GPIO MODE(0)

			BtRadio_SetupGPIO(0,47);
			BtRadio_SetupGPIO(0,48);
			BtRadio_SetupGPIO(0,49);
			BtRadio_SetupGPIO(0,51);

            //AFE_VDB_CON[5][4]=11
            //MT6236 AFE_VBT_CON register address:0x810D0014

			*MT6236_AFE_VDB_CON |= 0x0030;

		}
		else if (pcm_slect == 0x01)  //PCM2 to CDMA
		{
        	//Set up GPIO47/48/49/51  as DCI MODE(1)
			BtRadio_SetupGPIO(1,47);
			BtRadio_SetupGPIO(1,48);
			BtRadio_SetupGPIO(1,49);
			BtRadio_SetupGPIO(1,51);

			//AFE_VDB_CON[5][4]=00
            //MT6236 AFE_VBT_CON register address:0x810D0014

			*MT6236_AFE_VDB_CON &= 0xFFCF;

		}

	#endif

}

#endif

// Stryker: Some Customer might disable BT feature on GSM_BT integrated IC. Here are the Temp solution for pack-back customer support
#if defined(MT6236) || defined(MT6236B) || defined(MT6256) || defined(MT6276) || defined(MT6255) || defined(MT6250)

// This part is used for Non-BT MT6236 projects.

    #if defined (__BTMODULE_MT6236__)

    #else

    kal_uint32 BT_CoCLK_Enable(kal_uint32 Mode)
    {
        return KAL_TRUE;
    }
    
    #endif

    #if defined(__BTMODULE_MT6236__) || defined(__BTMODULE_MT6276__) || defined(__BTMODULE_MT6256__) || defined(__BTMODULE_MT6255__) || defined(__BTMODULE_MT6250__) || defined(__BTMODULE_MT6260__) || defined(__BTMODULE_MT6261__) || defined(__BTMODULE_MT2501__) || defined(__BTMODULE_MT2502__)

    #else

    void BTIF_DMA_TX_Threshold_Handler_VFIFO(void)
    {

    }

    void BTIF_DMA_RX_Threshold_Handler_VFIFO(void)
    {

    }
    
    #endif

#endif    // #if defined(MT6236) || defined(MT6236B) || defined(MT6256) || defined(MT6276) || defined(MT6255) || defined(MT6250)

/************************************************************************
************************************************************************/
//Modem_Only project
//Below API just provided when BLUETOOTH_SUPPORT = NONE,if not, occure redefined error
#if (!defined (__BTMTK__)) 
//#ifdef __DUAL_TALK_MODEM_SUPPORT__
#include "dcl.h"

#ifdef __CUST_NEW__
extern const char gpio_bt_pcmclk_pin;
extern const char gpio_bt_pcmsync_pin;
extern const char gpio_bt_pcmin_pin;
extern const char gpio_bt_pcmout_pin;
#else /* #ifdef __CUST_NEW__ */
#define BT_GPO_MAGIC_NUM	100
extern const unsigned char bt_gpio_setting[16];
#endif /* #ifdef __CUST_NEW__ */
static void BT_GPIO_ModeSetup(DCL_UINT32 Pin, DCL_UINT32 Mode)
{
   const DCL_HANDLE Handle = DclGPIO_Open(DCL_GPIO, Pin);
   Mode&=0x3;
   if(Mode == 0)
   {
      DclGPIO_Control(Handle, GPIO_CMD_SET_MODE_0, 0);
   }
   else if(Mode == 1)
   {
      DclGPIO_Control(Handle, GPIO_CMD_SET_MODE_1, 0);
   }
   else if(Mode == 2)
   {
      DclGPIO_Control(Handle, GPIO_CMD_SET_MODE_2, 0);
   }
   else
   {
      DclGPIO_Control(Handle, GPIO_CMD_SET_MODE_3, 0);
   }
   DclGPIO_Close(Handle);
}


void BtRadio_PCM_GPIOSetup(kal_uint8 enable)
{
   
#if defined(__MTK_TARGET__)
//Not SOC
#if (!defined (__BTMODULE_MT6236__)) && (!defined (__BTMODULE_MT6256__)) &&(!defined (__BTMODULE_MT6276__)) &&(!defined (__BTMODULE_MT6255__))

char gpio_bt_pcmclk;
char gpio_bt_pcmsync;
char gpio_bt_pcmin;
char gpio_bt_pcmout;

//Get the PCM 4 Pin number

#ifdef __CUST_NEW__
gpio_bt_pcmclk  = gpio_bt_pcmclk_pin;
gpio_bt_pcmsync = gpio_bt_pcmsync_pin;
gpio_bt_pcmout  = gpio_bt_pcmout_pin;
gpio_bt_pcmin   = gpio_bt_pcmin_pin;
#else
gpio_bt_pcmclk  = bt_gpio_setting[12];
gpio_bt_pcmsync = bt_gpio_setting[13];
gpio_bt_pcmout  = bt_gpio_setting[14];
gpio_bt_pcmin   = bt_gpio_setting[15];
#endif

//Set up the GPIO mode
if (enable == 0x01)
{
		BT_GPIO_ModeSetup(gpio_bt_pcmclk,1);
		BT_GPIO_ModeSetup(gpio_bt_pcmsync,1);
		BT_GPIO_ModeSetup(gpio_bt_pcmout,1);
		BT_GPIO_ModeSetup(gpio_bt_pcmin,1);
}

else if (enable == 0x00)
{
		BT_GPIO_ModeSetup(gpio_bt_pcmclk,0);
		BT_GPIO_ModeSetup(gpio_bt_pcmsync,0);
		BT_GPIO_ModeSetup(gpio_bt_pcmout,0);
		BT_GPIO_ModeSetup(gpio_bt_pcmin,0);
}

#endif 

/**SOC**/

#endif //__MTK_TARGET__
}

/* BT NVRAM parameter structure,some value stored on NVTAM
typedef struct
{
    unsigned char BDAddr[6];
    unsigned char CapId[1];
    unsigned char LinkKeyType[1];
    unsigned char UnitKey[16];
    unsigned char Encryption[3];
    unsigned char PinCodeType[1];
    unsigned char Voice[2];
    unsigned char Codec[1];----->PCM Codec paprameter=nvram_ef_btradio_mtk_bt_chip_struct[30]
    unsigned char Radio[6];
    unsigned char Sleep[7];
    unsigned char Reserved[2];
    unsigned char ECLK_SEL;
}  nvram_ef_btradio_mtk_bt_chip_struct;
*/

// We can not get the BT pcm codec value from NVRAM since the NVRAM item just for BT chip
//We set this value by BB chip
static kal_uint8 BtRadio_Get_PCM_Codec(void)
{
    kal_uint8 pcm_codec;
	
	#if defined(MT6252)
        pcm_codec = 0x20;
	#else
        pcm_codec = 0x20;
	#endif
	
	return pcm_codec;
}

kal_bool BtRadio_Get_PCM_ShortSync(void)
{
    return (kal_bool)((BtRadio_Get_PCM_Codec() & 0x20) >> 5);
}

kal_bool BtRadio_Get_PCM_LSBFirst(void)
{   
   return (kal_bool)((BtRadio_Get_PCM_Codec() & 0x40) >> 6);
} 

kal_bool BtRadio_Get_PCM_SignExtension(void)
{
    return (kal_bool)((BtRadio_Get_PCM_Codec() & 0x80) >> 7);
}
#endif


/*
 * terrence,2013/06/26,BT dialer feature:Low power solution
 * API used by MTK
 */
#ifdef __BT_DIALER_SUPPORT__

kal_bool Custom_BTDialer_LowPower_Support(void)
{
    return bt_dialer_low_power_support;
}

kal_uint8 Custom_BTDialer_TXPower_Level(void)
{
   return bt_dialer_max_tx_power_level;
}
#endif
/*
 * terrence,2013/08/02,Class of device setting
 *return:
 *--kal_true:use cod
 *--kal_false:do not use cod
 *parameter:cod value setting by custom
 */
kal_bool Custom_Config_Get_BT_COD(kal_uint32 * cod)
{
    
    *cod = bt_cod_from_custom;
	return use_bt_cod_from_custom;
   
}

void Custom_Config_Set_BT_COD(kal_uint32 cod, kal_bool use_custom_cod)
{
	bt_cod_from_custom = cod;
	use_bt_cod_from_custom = use_custom_cod;
}

void Custom_Config_Get_BQB_COD(kal_bool * bqb_cod)
{   
    *bqb_cod = bqb_cod_from_custom;
}

void Custom_Config_Set_BQB_COD(kal_bool bqb_cod)
{
	   bqb_cod_from_custom = bqb_cod;
}
#ifndef __BT_DISABLE_SSP_SUPPORT__

/**
 * get current SSP setting.
 *
 * @param    void
 *
 * @return 
 * @retval KAL_TRUE       support SSP
 * @retval KAL_FALSE      not support
 *
 * @authors    mawei
 * @date          2013/9/16
 */
kal_bool Custom_Config_Get_BT_SSP_Support(void)
{
    return bt_enable_ssp;
}
#endif


/************************************************************************
************************************************************************/
//terrence,2013/12/30,provide sniff parameter interface 

/*
enum 
{
    MTK_SNIFF_PARA_SET     = 0,   //most of time, use peer device's sniff parameter,if your device is phone/mid
    MTK_SNIFF_PARA_DIALER  = 1,       //most of time,use our sniff parameter,if your device is dialer/box or you really want to use our device's sniff parameter
    MTK_SNIFF_PARA_DIALER1 = 2 ,      //most of time,use our sniff parameter,if your device is dialer/box or you really want to use our device's sniff parameter
    MTK_SNIFF_PARA_DIALER2 = 3       //most of time,use our sniff parameter,if your device is dialer/box or you really want to use our device's sniff parameter

};*/

/*
 * sniff_level:0~3,as above said,usually you should use (should not use that api)the default value. 
 */
void Custom_Set_BT_Sniff_Parameter(kal_int8 sniff_level)
{
	   sniff_level_config = sniff_level;
}

kal_int8 Custom_Get_BT_Sniff_Parameter(void)
{
	   return sniff_level_config;
}

/************************************************************************
************************************************************************/


/************************************************************************
************************************************************************/
//terrence,2013/12/31,unify pairing method config

/*
 *  set the bt pairing method
 */
void Custom_Set_BT_Pairing_Method(Pairing_Type config_type)
{
	 bt_pairing_type_config = config_type;
}

/*
 * get the bt pairing method
 */
Pairing_Type Custom_Get_BT_Pairing_Method(void)
{  
	 return bt_pairing_type_config;
}

/*
 * check paring method == just work of SSP and fixed pin code of PIN
 */
kal_bool Custom_BTPairing_AutoAccept_Support(void)
{   
	 if (Custom_Get_BT_Pairing_Method() == FIXED_PIN_AND_SSP_JUST_WORK) 
         return KAL_TRUE;
     else
   	     return KAL_FALSE;
}  

/*
 * check paring method == fixed pin code of PIN
 */
kal_bool BTParing_Fixed_PinCode_Only_Support(void)
{
    if (Custom_Get_BT_Pairing_Method() == FIXED_PIN_ONLY)
        return KAL_TRUE;
    else
        return KAL_FALSE;
}

/*
 * return the fixed pin code
 */
kal_uint8* Custom_BTPairing_AutoAccept_Pincode(kal_uint8 * pin_size)
{
    *pin_size = BT_PIN_SIZE;
	 return (kal_uint8 *)&bt_pincode[0];
}

/************************************************************************
************************************************************************/
