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
 * MainMenuDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for main menu defination 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      mainmenu_def.h
   Author:        
   Date Created:  September-07-2002
   Contains:      Main menu application
**********************************************************************************/

#ifndef MAINMENUDEF_H
#define MAINMENUDEF_H

#include "MMI_features.h"

#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#define MAX_MAIN_MENU_ITEMS                  20
//#define MAIN_MENU_SCREENID             (MAIN_MENU_BASE+1)
#if !defined(__PLUTO_MMI_PACKAGE__ ) || defined(__IOT__)
   #define MAIN_MENU_BASE 0
#endif

#if 0
/* under construction !*/
/* under construction !*/
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#ifdef __MAIN_MENU_SUPPORT_MATRIX_PAGE_MENU__
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_MAINMENU_MATRIX_SUPPORT__) && defined(__MMI_MAINLCD_240X400__) && defined(__MAIN_MENU_SUPPORT_MATRIX_PAGE_MENU__)
/* under construction !*/
#endif
/* under construction !*/
#endif

/* Main menu image IDs     */

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__

enum MAIN_MENU_IMG_ID
{
    IMG_MAIN_MENU_BG = MAIN_MENU_BASE + 1,
#ifndef __MMI_SUBLCD__
    IMG_SUBLCD_SYSTEM_SHUTDOWN,
#endif

#if 0
#ifdef __MMI_MATRIX_MAIN_MENU_FULL_BACKGROUND__
/* under construction !*/
#endif
#if defined(__MMI_OP02_MAINMENU_12MATRIX__) || defined(__MMI_OP02_MAINMENU_9MATRIX__)
/* under construction !*/
#endif /* __MMI_OP02_MAINMENU_12MATRIX__ || __MMI_OP02_MAINMENU_9MATRIX__*/
#endif

    MAIN_MENU_ICON_ANI_IMGBASE_MAX,
    MAIN_MENU_BG_IMAGE_BASE,
    MAIN_MENU_PHONEBOOK_BG_IMAGE,
    MAIN_MENU_MESSAGES_BG_IMAGE,
    MAIN_MENU_CALL_HISTORY_BG_IMAGE,
    MAIN_MENU_SETTINGS_BG_IMAGE,
    MAIN_MENU_FUNANDGAMES_BG_IMAGE,
    MAIN_MENU_PROFILES_BG_IMAGE,
    MAIN_MENU_ORGANIZER_BG_IMAGE,
    MAIN_MENU_SERVICES_BG_IMAGE,
    MAIN_MENU_SHORTCUTS_BG_IMAGE,

#if 0
#if (defined(__MMI_OP02_MAINMENU_12MATRIX__) || defined(__MMI_OP02_MAINMENU_9MATRIX__)) && defined(BROWSER_SUPPORT)
/* under construction !*/
#endif /* __MMI_OP02_MAINMENU_12MATRIX__ || __MMI_OP02_MAINMENU_9MATRIX__ */
#endif

    IMG_MAIN_MENU_CIRCULAR_BG,
};

#else /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 
/********************************************************
Note : __MMI_BI_DEGREE_MAIN_MENU_STYLE__ shall be enabled 
   only when __MMI_MAINMENU_STYLE_CHANGE_EN__ is disabled 
********************************************************/
enum MAIN_MENU_IMG_ID
{
    IMG_MAIN_MENU_BG = MAIN_MENU_BASE + 1,
#ifndef __MMI_SUBLCD__
    IMG_SUBLCD_SYSTEM_SHUTDOWN,
#endif
#if 0
#ifdef __MMI_MATRIX_MAIN_MENU_FULL_BACKGROUND__
/* under construction !*/
#endif 
#if defined(__MMI_OP02_MAINMENU_12MATRIX__) || defined(__MMI_OP02_MAINMENU_9MATRIX__)
/* under construction !*/
#endif /* __MMI_OP02_MAINMENU_12MATRIX__ || __MMI_OP02_MAINMENU_9MATRIX__*/
#endif

    MAIN_MENU_ICON_ANI_IMGBASE_MAX,
    MAIN_MENU_BG_IMAGE_BASE,
    MAIN_MENU_PHONEBOOK_BG_IMAGE,
    MAIN_MENU_MESSAGES_BG_IMAGE,
    MAIN_MENU_CALL_HISTORY_BG_IMAGE,
    MAIN_MENU_SETTINGS_BG_IMAGE,
    MAIN_MENU_FUNANDGAMES_BG_IMAGE,
    MAIN_MENU_PROFILES_BG_IMAGE,
    MAIN_MENU_ORGANIZER_BG_IMAGE,
    MAIN_MENU_SERVICES_BG_IMAGE,
    MAIN_MENU_SHORTCUTS_BG_IMAGE,

    MAIN_MENU_ICON_ANI_IMGBASE,
    MAIN_MENU_WLAN_ANIMATION,
    MAIN_MENU_MRE_ANIMATION,
    MAIN_MENU_MESSAGE_CLUB_ANIMATION,
    MAIN_MENU_CAMERA_ANIMATION,
#if 0
#if defined(__MMI_OP02_MAINMENU_12MATRIX__) || defined(__MMI_OP02_MAINMENU_9MATRIX__)
/* under construction !*/
#endif
#endif
};

#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 

#ifdef __MMI_SUBLCD_MASTER_MODE__
#define SUB_MAIN_MENU_SCREENID             (MAIN_MENU_BASE+1)
typedef enum
{
#if defined(__MMI_AUDIO_PLAYER__)
    MMI_SUB_MAIN_ENUM_AUDPLY,
#endif
			
#if defined(__MMI_FM_RADIO__)
    MMI_SUB_MAIN_ENUM_FMRADIO,
#endif

    MMI_SUB_MAIN_ENUM_TOTAL
} mmi_sub_main_menu_enum;
#endif /*__MMI_SUBLCD_MASTER_MODE__*/


#endif /* MAINMENUDEF_H */ 

