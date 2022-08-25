/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001-2007
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
 * Filename:
 * ---------
 * lcd_power_ctrl.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   LCD Power Control Interface.
 *
 * Author:
 * ------- 
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 08 02 2011 bin.han
 * removed!
 * .
 *
 * 06 23 2011 bin.han
 * removed!
 * .
 *
 * 03 30 2011 chelun.tsai
 * removed!
 * lcd_if_hw.h move to HAL.
 *
 * 02 10 2011 chelun.tsai
 * removed!
 * modify drv_features.h include.
 *
 * 12 06 2010 sophie.chen
 * removed!
 * .
 *
 * 12 03 2010 chelun.tsai
 * removed!
 * move kcd if & power manager headers to mcu\interface.
 *
 * 11 23 2010 sophie.chen
 * removed!
 * .
 *
 * 11 15 2010 sophie.chen
 * removed!
 * .
 *
 *******************************************************************************/
 
#ifndef __LCD_PWR_CTRL_H__
#define __LCD_PWR_CTRL_H__

#include "kal_release.h"

/*! \mainpage LCD Power Control Interface
 *  @author  Sophie Chen
 *  @version 1.0
 *  @date    2010/08/03
 *
 * \section Introduction
 *
 * This document is an introduction of LCD Power Control Interface. \n
 * For MT6268/MT6236, WIFI and TD will use LCD HW to generate NFI waveforms to 
 * access external modules, meaning WIFI/TD/LCD will share LCD power/clock and data bus. \n
 * We create this module to control LCD power for LCD/TD/WIFI SW driver to avoid fatal race condition.\n
 * Arbitration of data bus will be handled by LCD HW.\n
 *
 * This module takes only power on/off request into considerations.\n
 * No control state of LCD/TD/WIFI is concerned in this module, which
 * shall be handled in relative module driver.\n
 * EX: If moduleA turns on LCD power on Task level, and then power off in ISR level.\n
 * Then module A shall handle the race condition by itself.\n\n
 *
 *                            
 *    Turn_on Power (Task) -->  Turn_off Power (ISR) -->  Access Register\n\n\n
 *                             
 *    
 *
 *
 * Before calling API to request turning on/off LCD power, You SHALL
 * register your module to LCD Power Control first.\n 
 * Each module registers itself ONLY ONCE.\n
 * No deregister API is supported, thus the caller shall keep the Handle value in its driver
 * when registering.\n
 *
 *
 * The header file is in \\mcu\\drv\\include\\lcd_power_ctrl.h\n\n
 *
 * The API is supported after W10.33 for ASTRO36E2_DEV branch. \n\n\n\n\n
 *
 *
 *
 *
 *
 * \section History
 *
 *
 *  @date    2010/08/04\n
 *  1.   Remove IOCTRL ID: LCD_POWER_IOCTRL__QRY_INIT_STATUS\n
 *  2.   Modify LCD_POWER_CTRL__IF_TIMING_STRUCT: add more necessary feilds to set IF timing.\n
 *  3.   Add an example to illustracte how to use LCD_POWER_IOCTRL__SET_IF_TIMING_VAL to set HW IF register.\n\n\n
 *
 *
 *
 *
 *
 *
 *
 *
 */
 
 

/// The enum LCD_POWER_IOCTRL_ID_ENUM defines io-control ID for user when calling IOCTRL
typedef enum
{

  LCD_POWER_IOCTRL__QRY_INIT_STATUS = 0,
/*!< LCD_POWER_IOCTRL__QRY_INIT_STATUS: Query if LCD Power control layer has been initialized\n
 * param in_val:  NA\n
 * param out_val:  NA\n
 * return: TRUE if LCD Power control layer has been initialized\n\n\n
 */ 


  LCD_POWER_IOCTRL__QRY_CLK_STATUS,
/*!< LCD_POWER_IOCTRL__QRY_CLK_STATUS: Query if LCD clock has been turn on\n
 * param in_val: NA\n
 * param out_val:  NA\n
 * return: TRUE if LCD clock has been on\n\n\n
 */ 


  LCD_POWER_IOCTRL__SET_IF_TIMING_VAL,
/*!< LCD_POWER_IOCTRL__SET_IF_TIMING_VAL: Set LCD parellel/serial numberN interface timing\n
 * param in_val: LCD_POWER_CTRL__IF_TIMING_STRUCT*\n
 * param out_val:  NA\n
 * return: NA\n\n\n
 */ 


  LCD_POWER_IOCTRL__QRY_IF_TIMING_VAL,
/*!< LCD_POWER_IOCTRL__QRY_IF_TIMING_VAL: Query LCD parellel/serial numberN interface timing\n
 * param in_val: LCD_POWER_CTRL__IF_TIMING_STRUCT* \n
 * param out_val:  kal_uint32*: interface timing will store in this pointer \n
 * return: NA\n\n\n
 */ 


  LCD_POWER_IOCTRL__SET_ROI_CTRL,
/*!< LCD_POWER_IOCTRL__SET_ROI_CTRL: Set LCD interface ROI control register (only for LCD driver)\n
 * param in_val: kal_uint32*: parameter\n
 * param out_val:  NA\n
 * return: NA\n\n\n
 */ 


  LCD_POWER_IOCTRL__SET_PERIOD,
/*!< LCD_POWER_IOCTRL__SET_PERIOD: Set LCD interface period value\n
 * param in_val: NA\n
 * param out_val:  NA\n
 * return: TRUE If the period is accepted by LCD Power control layer.\n\n\n
 */ 


  LCD_POWER_IOCTRL__QRY_PERIOD,
/*!< LCD_POWER_IOCTRL__QRY_PERIOD: Query LCD interface period value\n
 * param in_val: NA\n
 * param out_val:  kal_uint32*: interface period will store in this pointer\n
 * return: NA\n\n\n
 */ 



  LCD_POWER_IOCTRL__SET_TE_CTRL,
/*!< LCD_POWER_IOCTRL__SET_TE_CTRL: Set LCD interface TE control register (only for LCD driver)\n
 * param in_val: kal_uint32*: parameter\n
 * param out_val:  NA\n
 * return: NA\n\n\n
 */ 



  LCD_POWER_IOCTRL__SET_GMC_CTRL,
/*!< LCD_POWER_IOCTRL__SET_GMC_CTRL: Set LCD interface GMC control register (only for LCD driver)\n
 * param in_val: kal_uint32*: parameter\n
 * param out_val:  NA\n
 * return: NA\n\n\n
 */ 



  LCD_POWER_IOCTRL__SET_DITHER_CTRL
/*!< LCD_POWER_IOCTRL__SET_DITHER_CTRL: Set LCD interface Dither control register (only for LCD driver)\n
 * param in_val: kal_uint32*: parameter\n
 * param out_val:  NA\n
 * return: NA\n\n\n
 */ 

}LCD_POWER_IOCTRL_ID_ENUM;



/** The structure LCD_POWER_CTRL__IF_TIMING_STRUCT defines needed information when calling IOCTRL with \n
      ID: LCD_POWER_IOCTRL__SET_IF_TIMING_VAL \n
*/
typedef struct
{
   kal_bool parallel_if;
   kal_uint32 if_num;
   kal_uint32 if_val;

   kal_uint32 clock;
   kal_uint32 bus_width;
   kal_uint32 write_hold_time;
   kal_uint32 write_setup_time;
   kal_uint32 write_wait_time;

   kal_uint32 read_hold_time;
   kal_uint32 read_setup_time;
   kal_uint32 read_latency_time;

}LCD_POWER_CTRL__IF_TIMING_STRUCT;



/******************************************************************************
 * API functions
 *****************************************************************************/

/** DESCRIPTION :
 * Register to LCD_POWER_CTRL layer, and get the module_bit ID for the caller.
 * The return value will be used as the input parameter
 * in lcd_power_ctrl__enable() and lcd_power_ctrl__disable()
 *
 *
 * @param module  The definition of LCD Power module bit for the module to be 
 *                        turned on. 
 * 
 * @param return   0xFFFFFFFF means a invalidate value. The caller shall do error handler. 
 *
 * @remark Please try prevent to call this function in ISR level...and 
 *             please do not use i-bit to protect this function.
 *             This API shall be called once for each module. No deregister API is supported.
 */
kal_uint32 lcd_power_ctrl__register_module(void);



	
/** DESCRIPTION :
 * Turn on LCD module clock. And rollback LCD Interface registers setting.
 * 
 * @param module  The definition of LCD Power module bit for the module to be 
 *                turned on. 
 * 
 * @remark Please try prevent to call this function in ISR level...and 
 *         please do not use i-bit to protect this function.
 */
extern void lcd_power_ctrl__enable(kal_uint32 module);




/** DESCRIPTION :
 * Turn off LCD module clock. 
 * 
 * @param module  The definition of LCD Power module bit for the module to be 
 *                turned off. 
 * 
 * @remark Please try prevent to call this function in ISR level...and 
 *         please do not use i-bit to protect this function.
 */
extern void lcd_power_ctrl__disable(kal_uint32 module);


#endif //__LCD_PWR_CTRL_H__

