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
 *  MMI_features_type.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Type define fo MMI feature switch file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MMI_FEATURES_TYPE_H__
#define __MMI_FEATURES_TYPE_H__

/* general on/off/auto type */
#define __ON__          (-1)
#define __OFF__         (-2)
#define __AUTO__        (-3)

/* gui menu type */
#define __MATRIX__          (0)
#define __PAGE__            (1)
#define __LIST__            (2)
#define __CIRCULAR_3D__     (3)
#define __ROTATE__          (4)
#define __TAB__             (5)
#define __FIXED_GRID__      (6)
#define __ANI_BG_LIST__     (7)

/* resource type */
#define __RES_TYPE_GIF__        (0)
#define __RES_TYPE_BMP__        (1)
#define __RES_TYPE_JPG__        (2)
#define __RES_TYPE_SEQUENCE__   (3)
#define __RES_TYPE_PNG__        (4)

/* highlight effect */
#define  HIGHLIGHT_EFFECT_NONE          (0)     /* No Effect */
#define  HIGHLIGHT_EFFECT_TRANSPARENCY  (1)     /* Transparent with increasing opacity */
#define  HIGHLIGHT_EFFECT_FLASH_FEELING (2)     /* Flash effect with increase in Filler area */
#define  HIGHLIGHT_EFFECT_ANIMATION     (3)     /* Animatian with gif */
#define  HIGHLIGHT_EFFECT_SLIDE         (4)     /* slide effect */
#define  HIGHLIGHT_EFFECT_AUTO          (5)     /* auto-select */

/* softkey style */
#define  SOFTKEY_STYLE_NONE             (0)     /* No Special Effect */
#define  SOFTKEY_STYLE_DALMATIAN        (1)     /* Dalmatian Style */
#define  SOFTKEY_STYLE_TECHNO           (2)     /* Techno Stle */

/* status bar style */
#define  STATUSBAR_STYLE_NONE           (0)     /* No Special Effect */
#define  STATUSBAR_STYLE_DALMATIAN      (1)     /* Dalmatian Style */
#define  STATUSBAR_STYLE_TECHNO         (2)     /* Techno Stle */

/* ui animated title effect type */
#define __ONCE__        (0)
#define __CONTINUOUS__  (1)

/* ui fade effect style */
#define MMI_UI_FADE_EFFECT_STYLE_GRAY       (0)
#define MMI_UI_FADE_EFFECT_STYLE_DARKEN     (1)

/* dial style */
#define DIAL_TYPE_DEFAULT      (0)
#define DIAL_TYPE_ANIMATED     (1) 
#define DIAL_TYPE_MOTION       (2)

/* List menu smooth scrolling effect */

#define MENU_SMOOTH_SCROLLING_NONE           (0)
#define MENU_SMOOTH_SCROLLING_AUTO           (1)
#define MENU_SMOOTH_SCROLLING_PEN            (2) 
#define MENU_SMOOTH_SCROLLING_KEY            (3) 
#define MENU_SMOOTH_SCROLLING_PEN_AND_KEY    (4)

/* MMS image resizing setting menu */

#define __160x120__  (0)
#define __320x240__  (1)
#define __640x480__  (2) 

/* IMPS for diffirent country client */

#define __FRANCE__   (0)
#define __SPAIN__    (1)
#define __UK__       (2)

/* the screen flow type of downloading a file */
#define __DA_FLOW_1__  (0)
#define __DA_FLOW_2__  (1)
#define __DA_FLOW_3__  (2)  

/* unified message list style */
#define __UM_LIST_NORMAL__  (0)
#define __UM_LIST_INLINE__  (1)


/* keypad lock pattern */
#define __KEYPAD_LOCK_PATTERN1__  (0)
#define __KEYPAD_LOCK_PATTERN2__  (1)

/* SSE setting pattern */
#define SSE_SETTING_NONE   (0)
#define SSE_SETTING_SIMPLE (1)
#define SSE_SETTING_FULL   (2)

/*
 * Optional values of MMI_IVEX_MEM_SRC
 */
#define MMI_IMAGE_VIEWER_EX_MEM_SRC_ASM     (0)  //all the memory from ASM
#define MMI_IMAGE_VIEWER_EX_MEM_SRC_MED     (1)  //all the cache use MED 
#define MMI_IMAGE_VIEWER_EX_MEM_SRC_DEF     (2)  //only large cache use MED


/* Venus UI home screen type */
#define HOMESCREEN_VUI_NONE         (0)
#define HOMESCREEN_VUI_PIONEER      (1)
#define HOMESCREEN_VUI_LAUNCHER     (2)

/* Venus UI main menu type */
#define MAINMENU_VUI_NONE           (0)
#define MAINMENU_VUI_PIONEER        (1)
#define MAINMENU_VUI_3D             (2)
#define MAINMENU_VUI_LAUNCHER       (3)


/* Editor option menu style */
#define __STYLE_NONE__ (0)
#define __STYLE_1__    (1)
#define __STYLE_2__    (2)
#define __STYLE_3__    (3)

#define __MAINMENU_ICON_SEL_0__ (0)
#define __MAINMENU_ICON_SEL_1__ (1)
#define __MAINMENU_ICON_SEL_2__ (2)

/* MRE App mask start */

// use __MRE_APP_CLOSE__ to turn off, use __MRE_APP_DEFAULT__ to turn on as a normal version
#define __MRE_APP_CLOSE__       (0x00000000)
#define __MRE_APP_DEFAULT__     (0x40000000)
#define __MRE_APP_SHORTCUT__    (0x80000000)

// language range 0x00000001 ~ 0x00080000 (20)
#define __MRE_APP_LANG_ENG__    (0x00000001)
#define __MRE_APP_LANG_CHS__    (0x00000002)
#define __MRE_APP_LANG_CHT__    (0x00000004)

// version range 0x00100000 ~ 0x08000000 (8)
#define __MRE_APP_VER_XXX__     (0x00100000) // can be added/modified as V1, V2, STANDARD...

/* MRE App mask end */

// use __MMI_MMS_SETTING_SEL__ to control __MMI_MMS_SETTING__

#define MMS_SETTING_AUTO      (0)
#define MMS_SETTING_FULL      (1)
#define MMS_SETTING_OMA_ONLY  (2)
#define MMS_SETTING_NONE      (3)

// Option to set image cache location

#define __TCARD__             (0)
#define __SYS_DRIVE__         (1)
#define __PH_DRIVE__          (2)
#define __ASM__               (3)
#define __TCARD_PLUS_SYS__    (4)
#define __TCARD_PLUS_PH__     (5)


#endif /* __MMI_FEATURES_TYPE_H__ */
