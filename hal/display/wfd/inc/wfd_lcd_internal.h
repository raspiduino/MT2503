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
 * wfd_lcd_internal.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * ------- 
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 03 11 2011 sophie.chen
 * removed!
 * .
 *
 * 03 07 2011 chelun.tsai
 * removed!
 * wfd header move to hal
 *
 * 03 03 2011 chelun.tsai
 * removed!
 * 6268 use dedicate blt fuction..
 *
 * 02 10 2011 chelun.tsai
 * removed!
 * modify drv_features.h include.
 *
 * 12 24 2010 sophie.chen
 * removed!
 * .
 *
 * 11 23 2010 sophie.chen
 * removed!
 * .
 *
 * 11 18 2010 sophie.chen
 * removed!
 * .
 *
 * 11 15 2010 sophie.chen
 * removed!
 * .
 *
 *******************************************************************************/
 
#ifndef __WFD_LCD_INTERNAL_H__
#define __WFD_LCD_INTERNAL_H__



/*****************************************************************************
 *  Local macro definitions
 ****************************************************************************/

/*****************************************************************************
 *  Include directives
 ****************************************************************************/
#include "drv_comm.h"
#include "wfd\inc\wfd_hwdevice.h"
#include "wfd\inc\wfd.h"
#include "drv_features_display.h"
#include "drv_sw_features_display.h"
#include "kal_release.h"
#include "lcd_if_manager.h"

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 *  External symbols
 ****************************************************************************/

/*****************************************************************************
 *  Local type definitions
 ****************************************************************************/

/*****************************************************************************
 *  Local variables
 ****************************************************************************/

/**
 *  Used to indicate the maxinum supported number of Port Modes
 */
#define WFD_PORT_MAX_PORT_MODE_CNT 1


void
__wfd_lcd_SetError(WFDDevice device, WFDErrorCode status);


typedef enum
{
  WFDLCD___________________NONE,
  WFDLCD___________________HISR,
  WFDLCD_______________HISR_END,
  WFDLCD___________ERROR_HAPPEN,
  WFDLCD__LOST_COMPLETE_INT_BUG,
  WFDLCD_____CB_______EXEC_DONE,
  WFDLCD_____CB__EXEC_ACTIVE_CB,

  WFDLCD_____CB_________CMP_EVT,
  WFDLCD_____CB__________TE_EVT,
  
  WFDLCD______________BEING_BLT,
  WFDLCD______________BEING_FLT,
  WFDLCD__PIPELINE_________BIND,
  WFDLCD__PIPELINE______COMMMIT,
  WFDLCD__PIPELINE_______CREATE,
  WFDLCD__PIPELINE______DESTROY,  
  WFDLCD__________DEVICE_COMMIT,
  WFDLCD__________LCM_SLEEP__IN,
  WFDLCD__________LCM_SLEEP_OUT,
  WFDLCD____RESET_WFD_LCD_EVENT,
  WFDLCD_____________TIMEOUT_CB,
  WFDLCD___TIMEOUT_CB________TE,
  WFDLCD___TIMEOUT_CB____OTHERS, 

 
  //WFDLCD_______TEAR______CONFIG,
  //WFDLCD_______TEAR______xSTART,
  WFDLCD________WATCHDOG_START0,
  WFDLCD________WATCHDOG_START1,
  WFDLCD________WATCHDOG___END0,
  WFDLCD________WATCHDOG___END1,
  WFDLCD_____ROLLBACK_REG_START,
  WFDLCD_____ROLLBACK_REG_END__,
  WFDLCD___________________RSVD
}WFDLCDDbgIdEnum;


#ifdef __cplusplus
}
#endif

#endif //__WFD_LCD_INTERNAL_H__
