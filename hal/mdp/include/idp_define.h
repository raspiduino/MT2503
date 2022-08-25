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
 *    idp_define.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    MDP internal driver features on or off...
 *    
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 09 21 2011 peter.wang
 * removed!
 * .
 *
 * 06 01 2011 peter.wang
 * removed!
 * .
 *
 * 12 17 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * 11 13 2010 cm.huang
 * NULL
 * .
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
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_define_h__
#define __idp_define_h__

#include "drv_features_mmsysmisc.h"

//#define IDP_DVT_LOAD
#define IDP_MAUI_LOAD

#if defined(IDP_DVT_LOAD)
/*****************************************************************************
 * DVT load, such as IVP load
 ****************************************************************************/

/* DVT load */
#include <typedefs.h>

#define DRV_IDP_6238_SERIES
#define IDP_FAKE_KAL_SUPPORT
#define ENABLE_UT 1

#elif defined(IDP_MAUI_LOAD)
/*****************************************************************************
 * MAUI load
 ****************************************************************************/
/* MAUI load */

#if (defined(ISP_SUPPORT) && defined(DRV_ISP_6238_SERIES))
//#define IDP_CHECK_ISP_CRZ_SIZE_IS_MATCH  //CM mark 20101113 ISP not support 
#endif // #if (defined(ISP_SUPPORT) && defined(DRV_ISP_6238_SERIES))

#define IDP_VP7_MIDDLE_BUFFER_WIDTH  (480)
#define IDP_VP7_MIDDLE_BUFFER_HEIGHT (320)
//#define IDP_VIDEO_DECODE_ENLARGE_FOR_TV

#define IDP_DRVPDN_SUPPORT
#define IDP_FULL_KAL_SUPPORT

#if !defined(MED_NOT_PRESENT)
#define IDP_HISR_SUPPORT
#endif

#define IDP_FULL_ISR_SUPPORT

//#define ENABLE_LOGGING_FOR_IS_BUSY
//#define ENABLE_VIDEO_DECODE_WAIT_SECOND_PATH_DONE
/**
 *  \def IDP_HW_BUG_MDP_DC_LCD_HANG
 *  This macro is defined to enable a SW work-around for a potential HW bug in MT6238 series MDP LCD direct couple mode 
 *  From past CRs, we found a case that MDP is busy sending pixels to LCD but LCD is not busy transferring pixel data to LCM...
 *  If this happens for consecutive 10 frames, we try to reset MDP HW...
 *  10 is a magical number...
 */
#define IDP_HW_BUG_MDP_DC_LCD_HANG
#define IDP_DC_LCD_HANG_RESET_LCD
#define IDP_RESET_MDP_LCD_WHEN_MDP_DC_LCD_HUNG

//#define IDP_ENABLE_BUS_MONITOR
#define ENABLE_UT 0

#if defined(__MTK_TARGET__)
#define IDP_USE_CLKG_DEFINE
#endif

// For H.264 slim mode
#ifdef __CAMCORDER_PACKAGE_SLIM__
#define IDP_H264_SLIM_MODE
#endif // #ifdef __CAMCORDER_PACKAGE_SLIM__

#else
/*****************************************************************************
 * Not DVT nor MAUI load
 ****************************************************************************/
#error "Plz define IDP_DVT_LOAD or IDP_MAUI_LOAD!"
#endif

#if defined(IDP_FULL_KAL_SUPPORT)
#include <kal_general_types.h>
#include <kal_release.h>
#include "IntrCtrl.h"
#elif defined(IDP_FAKE_KAL_SUPPORT)
#include <idp_fake_kal.h>
#else
#error
#endif

#if defined(IDP_DRVPDN_SUPPORT)
#include <drvpdn.h>
#endif // #if defined(IDP_DRVPDN_SUPPORT)

#if defined(DRV_FEATURE__MM_POWER_CTRL_IF)
#include "mm_power_ctrl.h"
#endif // #if defined(DRV_FEATURE__MM_POWER_CTRL_IF)

#endif // #ifndef __idp_define_h__

