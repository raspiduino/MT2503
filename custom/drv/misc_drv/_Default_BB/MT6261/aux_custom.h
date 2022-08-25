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
 *    auxmain.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the AUX task
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
#ifndef __AUX_CUSTOM_H__
#define __AUX_CUSTOM_H__

#ifndef __L1_STANDALONE__

/*AUX state plug is low or high trigger*/
#define AUX_EINT_STATE		0  //0: LEVEL_LOW; 1: LEVEL_HIGH



#ifdef __LINE_IN_SUPPORT__	//for line in
#define LINE_IN_EINT_STATE		1  //0: LEVEL_LOW; 1: LEVEL_HIGH
#endif

#ifdef __BT_NFC_TAG_SUPPORT__	//for NFC TAG
#define NFC_TAG_EINT_STATE		1  //0: LEVEL_LOW; 1: LEVEL_HIGH
#endif


#ifdef TV_OUT_SUPPORT  
//If TV_OUT_SWITCH pin defined, add it here.
//	extern const char gpio_tv_out_switch_pin;
//  #define TV_OUT_SWITCH_GPIO		gpio_tv_out_switch_pin
#endif //TV_OUT_SUPPOR

//Clamshell and Slide
#if (defined(__PHONE_CLAMSHELL__) || defined(__PHONE_SLIDE__))
//if EINT_CLAM pin defined, add it here.
//#define EINT_CLAM_PIN		62
#endif //(defined(__PHONE_CLAMSHELL__) || defined(__PHONE_SLIDE__))

//UART
#define UART_ADC    (9999999)

//TV_OUT
#ifdef TV_OUT_SUPPORT 
#define TV_OUT_ADC_HIGH1    (2500000)   // 1.5V ~ 2.5V, only TV cable in w/o connection to TV
#define TV_OUT_ADC_LOW1     (1500000)
#define TV_OUT_ADC_LOW2     (300000)    // < 0.3V, TV cable in w/ connection to TV
#define TV_OUT_EARPHONE_LOW_LIMIT   (150000)    // 0.15V ~ 0.5V for TV
#define TV_OUT_EARPHONE_HIGH_LIMIT  (500000)
#endif //TV_OUT_SUPPORT 

//Earphone and SendKey
#define NORMAL_EARPHONE_ADC_HIGH    2800000
#define NORMAL_EARPHONE_ADC_LOW      500000/*0.5~2.8*/ 
#define SINGLE_EARPHONE_ADC_HIGH    2800000
#define SINGLE_EARPHONE_ADC_LOW      500000/*0.5~2.8*/
#define SENDKEY_ADC                  300000
#define POLLING_INTERVAL         50 /*polling interval*/
#define TURN_ON_BIAS_INTERVAL    10 /*measure adc interval*/    
#define PLUGIN_DEBOUNCE_TIME     50 /*unit=10ms*/
#define PLUGOUT_DEBOUNCE_TIME    5
#define HOOKKEY_DEBOUNCE_TIME    30
#define VOLTAGE_MEASURE_TIME     450  

//if usb_uart_switch_pin or earphone_usb_uart_switch_pin defined, add it here.
#ifdef __CUST_NEW__
//	extern const char gpio_usb_uart_switch_pin;          
//	extern const char gpio_earphone_usb_uart_switch_pin; 
//	#define USB_UART_SWITCH		gpio_usb_uart_switch_pin	
//	#define EARPHONE_USB_UART_SWITCH		gpio_earphone_usb_uart_switch_pin
#else // __CUST_NEW__
//	#define USB_UART_SWITCH		6
//	#define EARPHONE_USB_UART_SWITCH		63
#endif  // __CUST_NEW__

#endif //__L1_STANDALONE__
#endif //__AUX_CUSTOM_H__
