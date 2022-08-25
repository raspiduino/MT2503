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
 *   widget_defs.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements widget view UI presentation
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _VAPP_WIDGET_MEMORY_H
#define _VAPP_WIDGET_MEMORY_H

/* Use for define 32 bits color format in details view */
#ifndef WIDGET_DETAILS_VIEW_ARGB8888_COLOR_FORMAT
#define WIDGET_DETAILS_VIEW_ARGB8888_COLOR_FORMAT
#endif


#ifdef WIDGET_DETAILS_VIEW_ARGB8888_COLOR_FORMAT
    #define COLOR_FORMAT_BITS_NUM 4
#else
    #define COLOR_FORMAT_BITS_NUM 2
#endif /*WIDGET_DETAILS_VIEW_ARGB8888_COLOR_FORMAT */

// Home screen page number is 5  

//
// Memory Configuration
// (1) Idle view
//      size = (max_width - margin)x(max_height - margin)xdouble bufferingx32-bits-color x screen page number)
// (2) Details view 
//      size = LCD_width x LCD_height x double buffering x (32-bits-color format + 1)
//      *why "+1"?  Keep a 16bits LCD size for playing video 
//

#if defined(__MMI_MAINLCD_240X320__)
    #define APP_WIDGET_IDLE_FG_SIZE   			((240 - (8 * 2))*(192 - (8 * 2))*(2)*(4)*(1))
    #define APP_WIDGET_DETAILS_FG_SIZE			(((240) * (320) * (2) * (COLOR_FORMAT_BITS_NUM + 1)))
#elif defined(__MMI_MAINLCD_240X400__)
    #define APP_WIDGET_IDLE_FG_SIZE				((240 - (8 * 2))*(275 - (8 * 2))*(2)*(4)*(1))
    #define APP_WIDGET_DETAILS_FG_SIZE			(((240) * (400) * (2) * (COLOR_FORMAT_BITS_NUM + 1)))  
#elif defined(__MMI_MAINLCD_320X480__)
    #define APP_WIDGET_IDLE_FG_SIZE				((320 - (10 * 2))*(320 - (10 * 2))*(2)*(4)*(1))
    #define APP_WIDGET_DETAILS_FG_SIZE			(((320) * (480) * (2) * (COLOR_FORMAT_BITS_NUM + 1)))
#elif defined(__MMI_MAINLCD_480X800__)
    #define APP_WIDGET_IDLE_FG_SIZE				((480 - (18 * 2))*(550 - (18 * 2))*(2)*(4)*(1))
    #define APP_WIDGET_DETAILS_FG_SIZE			(((480) * (800) * (2) * (COLOR_FORMAT_BITS_NUM + 1)))
#else
    #define APP_WIDGET_IDLE_FG_SIZE   			(LCD_WIDTH * LCD_HEIGHT *(2)*(4)*(1))
    #define APP_WIDGET_DETAILS_FG_SIZE			(LCD_WIDTH * LCD_HEIGHT * 2 * (COLOR_FORMAT_BITS_NUM + 1)))
#endif	/* defined(__MMI_MAINLCD_240X320__) */
		
#endif /* _VAPP_WIDGET_MEMORY_H */
