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
 * lcd_power_ctrl_internal.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   LCD Power Control header file, used to declare internal used functions.
 *
 * Author:
 * ------- 
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 06 26 2011 tianshu.qiu
 * removed!
 * .
 *
 * 02 10 2011 chelun.tsai
 * removed!
 * modify drv_features.h include.
 *
 * 11 23 2010 sophie.chen
 * removed!
 * .
 *
 * 11 15 2010 sophie.chen
 * removed!
 * .
 *
 * 10 26 2010 sophie.chen
 * removed!
 * .
 *
 * 10 26 2010 sophie.chen
 * removed!
 * .
 *
 * 10 25 2010 sophie.chen
 * removed!
 * .
 *
 * 08 25 2010 sophie.chen
 * removed!
 * .
 *
 * 08 20 2010 sophie.chen
 * removed!
 * .
 *
 * 08 19 2010 sophie.chen
 * removed!
 * .
 *
 * 08 10 2010 sophie.chen
 * removed!
 * .
 *
 *******************************************************************************/

#ifndef __LCD_PWR_CTRL_COMMON_H__
#define __LCD_PWR_CTRL_COMMON_H__

#include "kal_release.h"
#include "drv_features_display.h"
#include "drv_sw_features_display.h"

typedef enum
{
    LCD_PWR_CTRL__INIT____________________X,
    LCD_PWR_CTRL__REGISTER________________X,
    LCD_PWR_CTRL__ENABLE____B_____________X,
    LCD_PWR_CTRL__ENABLE____E_____________X,
    LCD_PWR_CTRL__ENABLE____MMPWRMGR_ON___X,
    LCD_PWR_CTRL__ENABLE____SET_IF_REG____X,
    LCD_PWR_CTRL__DISABLE___B_____________X,
    LCD_PWR_CTRL__DISABLE___E_____________X,
    LCD_PWR_CTRL__DISABLE___MMPWRMGR_OFF__X,
    LCD_PWR_CTRL__ERROR_NOT_INITIALIZED___X,
    LCD_PWR_CTRL__ERROR_INVALID_MODULE____X
}LCD_POWER_CTRL__DEBUG_ENUM;

#define LCD_POWER_CTRL__DEBUG_CNT 32
typedef struct
{
    LCD_POWER_CTRL__DEBUG_ENUM id;
    kal_uint32 state;
    kal_uint32 caller_module_id;
    kal_uint32 ctrl_module_val;
    kal_uint32 lcd_clk_hw_sts;
}LCD_POWER_CTRL__DBG_STRUCT;

typedef struct
{
    kal_bool    lcd_power_ctrl_init;
    kal_uint32 lcd_power_ctrl_registered_module_count; //keep count of registered modules
    kal_uint32 lcd_power_ctrl_handle; //keep information about which module ask to turn on LCD power/Clock
}LCD_POWER_CTRL_CNXT_STRUCT;

#endif //__LCD_PWR_CTRL_H__

