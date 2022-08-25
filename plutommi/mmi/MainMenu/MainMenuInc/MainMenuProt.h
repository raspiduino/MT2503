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
 * MainMenuProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for main menu functions prototype
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
   Filename:      mainmenu_prot.h
   Author:
   Date Created:  September-07-2002
   Contains:      Main menu application
**********************************************************************************/

#ifndef MAINMENUPROT_H
#define MAINMENUPROT_H

#include "MMI_features.h"
#include "MMIDataType.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
extern void handle_mainmenu_right_softkey_up(void);
extern void highlight_mainmenu_phonebook(void);
extern void highlight_mainmenu_messages(void);
extern void highlight_mainmenu_funandgames(void);
extern void highlight_mainmenu_organizer(void);
extern void highlight_mainmenu_settings(void);
extern void highlight_mainmenu_connect(void);
extern void highlight_mainmenu_connectivity(void);
#ifdef __MMI_WLAN_FEATURES__
extern void highlight_mainmenu_WiFi_wizard(void);
#endif
#if 0
#ifdef __MMI_MESSAGES_CLUB__
/* under construction !*/
#endif 
#endif
#ifdef __MMI_MRE_MAIN_MENU__
extern void highlight_mainmenu_mre(void);
#endif
#ifndef __DISABLE_SHORTCUTS_IMPL__
extern void highlight_mainmenu_shortcuts(void);
#endif 
extern void highlight_mainmenu_services(void);
extern void initalize_main_menu_application(void);
extern void main_menu_shortcut_executer(S32 index);
extern void goto_main_menu(void);
extern void mmi_main_menu_entry(void);
extern void highlight_mainmenu_profiles(void);

extern void highlight_mainmenu_callcenter(void);
extern void highlight_mainmenu_multimedia(void);

#if 0
#if defined( __MMI_OP12_MENU_12MATRIX__)
/* under construction !*/
#endif
#if defined( __MMI_OP11_MENU_12MATRIX__) || defined( __MMI_OP12_MENU_12MATRIX__)
/* under construction !*/
#endif
#endif
#if !defined(__MMI_MAINLCD_96X64__)
extern void highlight_mainmenu_filemngr(void);
#endif
extern void highlight_mainmenu_extra(void);
extern void EntryMainExtra(void);
extern void mmi_entry_main_extra_screen(void);
extern void EntryMainMultimedia(void);
extern void mmi_entry_main_multimedia_screen(void);
extern void EntryMainFileMngr(void);
extern void ExitMainFileMngr(void);

#if 0
#if defined( __MMI_OP11_MENU_12MATRIX__) || defined( __MMI_OP12_MENU_12MATRIX__)
/* under construction !*/
#endif
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
/* under construction !*/
#if defined(__MMI_OP11_MENU_12MATRIX__) || defined(__MMI_OP12_MENU_12MATRIX__) || defined(__MMI_OP02_MAINMENU_12MATRIX__) || defined(__MMI_OP02_MAINMENU_9MATRIX__)
/* under construction !*/
#endif /* __MMI_OP11_MENU_12MATRIX__ || __MMI_OP12_MENU_12MATRIX__ || __MMI_OP02_MAINMENU_12MATRIX__ || __MMI_OP02_MAINMENU_9MATRIX__ */ 
/* under construction !*/
#if (defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_12MATRIX__)) && defined(WAP_SUPPORT)
/* under construction !*/
#endif /* __MMI_OP01_MENU_9MATRIX__ & WAP_SUPPORT */
#ifdef __MMI_CUSTOMER_SERVICE__
/* under construction !*/
#endif /* __MMI_CUSTOMER_SERVICE__ */
#ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
#endif /* __MMI_MOBILE_SERVICE__ */
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#endif /* __MMI_MY_FAVORITE__ */
#if defined(__MMI_OP01_MENU_NOSIM_LIST__) || defined(__MMI_OP02_0100__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_MENU_NOSIM_LIST__ || __MMI_OP02_0100__*/
/* under construction !*/
#if defined(__MMI_OP02_0100__) && defined(WAP_SUPPORT)
/* under construction !*/
#endif /* __MMI_OP02_0100__ & WAP_SUPPORT */
/* under construction !*/
#ifdef __OP02__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __OP02_0100__ */
/* under construction !*/
#ifdef __OP02_0200__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef BROWSER_SUPPORT
/* under construction !*/
#endif
#endif /* __OP02_0200__ */
/* under construction !*/
#ifdef __MMI_OP02_LEMEI__
/* under construction !*/
#endif
/* under construction !*/
#ifdef __OP01__
#if defined(__OP01_3G__) && defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
/* under construction !*/
#endif
#ifdef __MMI_139_PUSH_MAIL__
/* under construction !*/
#endif
#ifdef __MMI_MOBILE_VIDEO__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __OP01__ */
#endif

/* for 3D mainmenu auto test */
#ifdef __MMI_VUI_3D_MAINMENU__
typedef struct{
    LOCAL_PARA_HDR
    kal_uint16 menu_id;
}mmi_3d_mm_launch_app_req_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_uint8 result;
}mmi_3d_mm_launch_app_rsp_struct;

#endif /* __MMI_VUI_3D_MAINMENU__ */


extern void highlight_mainmenu_tools(void);
#if defined(__MMI_BT_DIALER_SUPPORT__)
extern void highlight_mainmenu_bt_dialer(void);
#endif
#ifndef __MMI_TELEPHONY_SUPPORT__
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
extern void highlight_mainmenu_camera(void);
#endif
#if defined(__MMI_IMAGE_VIEWER__)
extern void highlight_mainmenu_image_viewer(void);
#endif
#if defined(__MMI_VIDEO_PLAYER__)
extern void highlight_mainmenu_video_player(void);
#endif
#if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
extern void highlight_mainmenu_video_recorder(void);
#endif
#endif /* __BT_DIALER_PACKAGE__ */

#endif /* MAINMENUPROT_H */
