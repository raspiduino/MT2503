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
 * Filename:
 * ---------
 *  FileManagerDef.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager internal prototype header.
 *
 * Author:
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _FMGR_TABLE_H_
#define _FMGR_TABLE_H_

#ifndef _FMGR_TABLE_CONTENT_C_
#error "This file can only be included by FileMgrTable.c"
#endif

/****************************************************************************
* Include Files
*****************************************************************************/
#include "FileMgrGProt.h"
#include "FileMgrServiceHdlr.h"

/* include App's resource/callback prototype here */
#ifdef __MMI_IMAGE_VIEWER__
#include "mmi_rp_app_imageviewer_def.h"
#endif

#include "ABRepeaterResDef.h"
#include "VdoPlyResDef.h"
#ifdef __MMI_EBOOK_READER__
#include "mmi_rp_app_ebook_def.h"
#endif /* __MMI_EBOOK_READER__ */
#include "SWFlashResDef.h"
#include "CatScreenBrowserResDef.h"
#include "JavaAgencyGProt.h"
#include "MobileTVPlayerGprot.h"
#include "PhoneSetupGprots.h"
#include "VdorecGprot.h"
#include "VdoplyGprot.h"
#include "ImageViewerGprot.h"
#include "Mmi_rp_app_todolist_def.h"
#ifdef __UM_SUPPORT__
#include "mmi_rp_app_unifiedmessage_def.h"
#else
#include "mmi_rp_app_sms_def.h"
#endif

#include "mmi_rp_srv_wallpaper_def.h"
#include "mmi_rp_srv_screensaver_def.h"
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
#include "mmi_rp_srv_phnset_onoff_def.h"
#endif

#ifdef __MMI_FM_RADIO__ 
#include "mmi_rp_app_fmrdo_def.h"
#endif


#ifdef __MMI_RMGR__
#include "mmi_rp_app_rmgr_def.h"
#endif


#ifdef __MMI_CSB_BROWSER__
#include "mmi_rp_app_csb_def.h"
#endif
#include "mmi_rp_app_bluetooth_def.h"


#ifdef __MMI_EMAIL__
#include "mmi_rp_app_email_def.h"
#endif

#include "AnswerMachineResDef.h"

#ifdef __MMI_BARCODEREADER__
#include "MMI_features_barcodereader.h"
    #ifdef __MMI_OP01_BARCODEREADER__
/* under construction !*/
    #endif
#endif

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
#include "MMIThemesGprot.h"
#endif

#if defined(__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__)
#include "BTMMIObexGprots.h"
#endif

#if defined(__MMI_FM_RADIO_RECORD__)
BOOL mmi_fmgr_fmrdo_notify_hdlr(U32 notify_flag, void* para);
#endif


#if defined(__MMI_BARCODEREADER__) && defined(__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__)
#include "MMI_features_barcodereader.h"
#include "barcodereadergprot.h"
#endif

#include "MMI_features.h"

#if defined(__MMI_FILE_MANAGER__)
extern void mmi_rngc_option_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
extern void mmi_swflash_option_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
#endif

#ifdef __MMI_RMGR__
extern void mmi_rmgr_option_enabler_more_rits(mmi_menu_id menu_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo);
#endif

#ifdef __J2ME__
//extern void mmi_java_jad_option_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo);
#endif

#ifdef __QQIM_SUPPORT__
extern BOOL mmi_qqim_fmgr_notify_hdlr(U32 flag, void *para);
#endif

#ifdef __MMI_CAMCORDER__
//extern BOOL mmi_camco_notify_storage_change_hdlr(U32 notify_flag, void* para);
#endif

#if defined(__MMI_MY_FAVORITE__)
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_UDX_SUPPORT__
#include "mmi_rp_app_udx_def.h"
#endif

#ifdef __MMI_BG_SOUND_EFFECT__
#include "mmi_rp_app_callset_def.h"
#endif /* __MMI_BG_SOUND_EFFECT__ */

#ifdef __MMI_SLIDESHOW__
#include "mmi_rp_app_slideshow_def.h"
#define APP_INFO_SLIDESHOW \
APP_INFO(APP_SLIDESHOW,    0,       MENU_ID_SLIDSHOW_APP)
#else
#define APP_INFO_SLIDESHOW
#endif

#ifdef __MMI_MOTION_APP__
#include "mmi_rp_app_funandgames_def.h"
#define APP_INFO_GAME \
APP_INFO(APP_FUNANDGAMES,    0,       MENU_ID_MOTION_APP)
#else
#define APP_INFO_GAME
#endif
#include "mmi_rp_app_profiles_def.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "FileMgrSrvGProt.h"
#include "FileMgrProt.h"
#include "FileMgrType.h"

#ifdef __MMI_VIDEO_PLAYER__
#include "mmi_rp_app_vdoply_def.h"
#endif
/****************************************************************************
* Define
*****************************************************************************/

/***** Macro *****/

#if defined(__MMI_FILE_MANAGER__)


#ifndef __MMI_ULTRA_SLIM_FILE_MANAGER__
/****************************************************************************/
/*
 *  App type information
 */
#define APP_INFO(app_id, string_id, root_menu_id)


#ifdef __MMI_AUTO_ANSWER_MACHINE__
#define APP_INFO_ANSWER_MACHINE
#else
#define APP_INFO_ANSWER_MACHINE
#endif

#ifdef __MMI_OP01_BARCODEREADER__
/* under construction !*/
/* under construction !*/
#else
#define APP_INFO_BARCODE_OP01
#endif

#ifdef __MMI_BCR__
#include "mmi_rp_app_bcr_def.h"
#define APP_INFO_BCR \
    APP_INFO(APP_BCR,    0,       MENU_ID_BCR_APP   )
#else
#define APP_INFO_BCR
#endif

#ifdef __MMI_SWFLASH__
#define APP_INFO_SWFLASH \
    APP_INFO(APP_SWFLASH,          STR_ID_SWFLASH_APP,                  0                           )
#else
#define APP_INFO_SWFLASH 
#endif

#ifdef __MMI_CSB_BROWSER__
#define APP_INFO_CSB \
    APP_INFO(APP_CSB,              STR_ID_CSB_TEXT,                     MAIN_MENU_FILE_MNGR_MENUID                           )
#else
#define APP_INFO_CSB 
#endif


#define APP_INFO_COMPOSER

#ifdef __MMI_VIDEO_PLAYER__
#define APP_INFO_VDOPLY \
    APP_INFO(APP_VDOPLY,           STR_ID_VDOPLY_APP_NAME,              MENU_ID_VDOPLY_APP          )     
#else
#define APP_INFO_VDOPLY 
#endif

#if (defined(__MMI_BG_SOUND_EFFECT__) && !defined(__COSMOS_MMI_PACKAGE__))
#define APP_INFO_BGSOUND \
    APP_INFO(APP_BGSOUND,          0,                                   MENU_ID_CALLSET_CALL_SETTING    )
#else
#define APP_INFO_BGSOUND
#endif

#ifdef __MMI_TODOLIST__   
#define APP_INFO_TODOLIST \ 
    APP_INFO(APP_TODOLIST,         0,                                   ORGANIZER_TODOLIST_MENU     )
#else
#define APP_INFO_TODOLIST
#endif    

#if defined(__MMI_FWU_VIA_FILE__)
#define APP_INFO_FWU \
    APP_INFO(APP_DEVICE_MANAGEMENT,0,                                   SERVICES_FWU_MENU_ID        )
#else
#define APP_INFO_FWU
#endif
/* UDX_SUPPORT */
#ifdef __MMI_UDX_SUPPORT__
#define APP_INFO_UDX \
    APP_INFO(APP_UDX,              0,                                   MENU_ID_UDX_MAIN_MENU)
#else
#define APP_INFO_UDX
#endif
/* UDX_SUPPORT */

#ifdef __MMI_FM_RADIO__ 
#define APP_INFO_FMRDO \
    APP_INFO(APP_FMRDO,            0,                                   MENU_ID_FMRDO_MAIN          )
#else
#define APP_INFO_FMRDO
#endif


#ifdef __MMI_RMGR__ 
#define APP_INFO_RMGR \
    APP_INFO(APP_RMGR,            0,                                   MENU_ID_RMGR          )
#else
#define APP_INFO_RMGR
#endif

#if (defined(__MMI_FILE_MANAGER__) && defined(__PLUTO_MMI_PACKAGE__))
#define APP_INFO_FMGR \
    APP_INFO(APP_FILEMANAGER,      STR_FMGR_TITLE,                      MAIN_MENU_FILE_MNGR_MENUID  )
#else
#define APP_INFO_FMGR
#endif

#ifdef __MMI_EMAIL__
#ifdef __COSMOS_MMI_PACKAGE__
#define APP_INFO_EMAIL \
    APP_INFO(VAPP_EMAIL,            0,                                   0          )
#else
#define APP_INFO_EMAIL \
    APP_INFO(APP_EMAIL,            0,                                   0          )
#endif
#else
#define APP_INFO_EMAIL
#endif

#ifdef __MMI_IMPS__
/* under construction !*/
/* under construction !*/
#else
#define APP_INFO_IMPS
#endif

#ifdef __MMI_IMAGE_VIEWER__
#define APP_INFO_IMGVIEW \
    APP_INFO(APP_IMAGEVIEWER,      STR_ID_IMGVIEW_NAME,                 MENU_ID_IMGVIEW_APP         )
#else
#define APP_INFO_IMGVIEW
#endif

#define FMGR_APP_TABLE_COL \
    APP_INFO_FMGR \
    APP_INFO(APP_DOWNLOADAGENT,    STR_FMGR_TITLE,                      MAIN_MENU_FILE_MNGR_MENUID  ) \
    APP_INFO(APP_PHONEBOOK,        0,                                   MAIN_MENU_PHONEBOOK_MENUID  ) \
    APP_INFO(APP_SETTINGS,         0,                                   MAIN_MENU_SETTINGS_MENUID   ) \
    APP_INFO(APP_PROFILES,         0,                                   MAIN_MENU_PROFILES_MENUID   ) \
    APP_INFO(APP_MESSAGES,         0,                                   MAIN_MENU_MESSAGES_MENUID   ) \
    APP_INFO(APP_WAP,              0,                                   SERVICES_WAP_MENU_ID        ) \
    APP_INFO_IMGVIEW \
    APP_INFO_COMPOSER \
    APP_INFO_VDOPLY \
    APP_INFO(APP_VDOEDT,           0,                                   MENU_ID_VDOEDT_APP          ) \
    APP_INFO_SLIDESHOW  \
    APP_INFO_BARCODE_OP01 \
    APP_INFO_BCR \
    APP_INFO_EMAIL \
    APP_INFO(APP_EXTDEVICE,        0,                                   MAIN_MENU_FILE_MNGR_MENUID  ) \
    APP_INFO(APP_FTP,              0,                                   MENU_CONN_BT_MAIN           ) \
    APP_INFO(APP_BIP,              0,                                   MENU_CONN_BT_MAIN           ) \
    APP_INFO(APP_EBOOK,            0,               0      ) \
    APP_INFO(APP_MYFAVORITE,       0,                                   0                           ) \
    APP_INFO_FMRDO \
    APP_INFO(APP_JAVA,             0,                                   0                           ) \
    APP_INFO_GAME \
    APP_INFO_BGSOUND \
    APP_INFO_RMGR \
    APP_INFO_SWFLASH \
    APP_INFO_CSB \
    APP_INFO(APP_DCD,              0,                                   0                           ) \
    APP_INFO_FWU \
    APP_INFO_UDX \
    APP_INFO_IMPS \

#endif /*__MMI_ULTRA_SLIM_FILE_MANAGER__*/
/****************************************************************************/
/*
 *
 */

/****************************************************************************/
/*  menu_id:    forward(use or send) menuitem id
 *  enabler:    mmi_fmgr_enabler_callback, enable logic handler
 */
#define FE_INFO(menu_id, enabler)

#define FMGR_FWD_ENABLER_COL \
    /* Use - Image/Video */ \
    /* Use - Audio */ \
    FE_INFO_BG_SOUND \
    /* Send */ \
    FE_INFO_SMS \
    FE_INFO_EMAIL \
    FE_INFO_IRDA \
	FE_INFO_BT_MUL \

#ifdef __MMI_BG_SOUND_EFFECT__		
#define FE_INFO_BG_SOUND \
    FE_INFO(MENU_ID_FMGR_FWD_BGSOUND,           mmi_fmgr_forward_bgsound_enabler)
#else
#define FE_INFO_BG_SOUND
#endif

#if !defined (__MMI_MESSAGES_NO_SEND_BY_SMS_OPTION__)
#define FE_INFO_SMS \
    FE_INFO(MENU_ID_FMGR_FWD_SMS,               mmi_fmgr_forward_sms_enabler)
#else
#define FE_INFO_SMS
#endif

/* 
#ifdef __MMI_MMS__
#define FE_INFO_MMS \
    //FE_INFO(MENU_ID_FMGR_FWD_MMS,               mmi_fmgr_forward_mms_enabler)
#else
#define FE_INFO_MMS
#endif
*/
#ifdef __MMI_EMAIL__
#define FE_INFO_EMAIL \
    FE_INFO(MENU_ID_FMGR_FWD_EMAIL,             mmi_fmgr_forward_email_enabler)
#else
#define FE_INFO_EMAIL
#endif

#if defined __MMI_IRDA_SUPPORT__ && !defined(__MMI_SLIM_FILE_MANAGER__)
#define FE_INFO_IRDA \
    FE_INFO(MENU_ID_FMGR_FWD_IRDA,              mmi_fmgr_forward_peripheral_enabler)
#else
#define FE_INFO_IRDA
#endif

/* Bluetooth sending API revise */
//#ifdef __MMI_BT_SEND_SUPPORT__
//#define FE_INFO_BT \
//    FE_INFO(MENU_ID_FMGR_FWD_BT,                mmi_fmgr_forward_peripheral_enabler)
//#else
//#define FE_INFO_BT
//#endif

#if defined(__MMI_FMGR_MULTI_SELECT_SUPPORT__) && defined(__MMI_OPP_SUPPORT__) && !defined(__MMI_SLIM_FILE_MANAGER__)
#define FE_INFO_BT_MUL \
    FE_INFO(MENU_ID_FMGR_MARK_OPTION_TO_BT,     mmi_fmgr_forward_peripheral_enabler)
#else
#define FE_INFO_BT_MUL
#endif


/****************************************************************************/
/*  menu_id:    Application menuitem id
 *  enabler:    mmi_fmgr_enabler_callback, enable logic handler
 */

#define FMGR_APP_ENABLER_COL \
    FE_INFO(MENU_ID_FMGR_AUD_TYPE_OPTIONS,          mmi_fmgr_option_audio_enabler) \
    FE_INFO(MENU_ID_FMGR_IMG_TYPE_OPTIONS,          mmi_fmgr_option_image_enabler) \
    FE_INFO_RNGC \
    FE_INFO_SWFLASH \
    FE_INFO_RMGR \
    FE_INFO_VDOPLY \



#define FE_INFO_RNGC

#ifdef __MMI_SWFLASH__
#define FE_INFO_SWFLASH \
    FE_INFO(MENU_ID_SWFLASH_OPTION,                 mmi_swflash_option_enabler)
#else
#define FE_INFO_SWFLASH
#endif

#ifdef __MMI_RMGR__
#define FE_INFO_RMGR \
    FE_INFO(MENU_ID_FMGR_GEN_OPTION_MORE_RITS,      mmi_rmgr_option_enabler_more_rits)
#else
#define FE_INFO_RMGR
#endif


#if defined(__MMI_VIDEO_PLAYER__) 
#define FE_INFO_VDOPLY \
    FE_INFO(MENU_ID_VDOPLY_FILE_OPTION,           mmi_vdoply_file_option_enabler) \
    FE_INFO(MENU_ID_VDOPLY_EMPTY_FOLDER_OPTION,           mmi_vdoply_empty_option_enabler)
#else
#define FE_INFO_VDOPLY
#endif
#if 0
#ifdef __J2ME__
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
#endif


#ifdef __FMGR_HYPERLINK_SUPPORT__

/****************************************************************************/
/*  app_id:     application id that hyper link is enabled
 *  path:       folder path that hyper link is enabled, Ex: "SWFlash\", drive path is not supported yet.
 *  callback:   query hyperlink detail information, see mmi_fmgr_hyperlink_callback
 */
#define HL_INFO(app_id, path, callback)

#define FMGR_HYPERLINK_COL \
    HL_INFO_MYFAVORITE \
    HL_INFO_JAVA \
    
#if defined(__MMI_JAVA_FMGR_HYPERLINK__) && defined(__PLUTO_MMI_PACKAGE__)
#define HL_INFO_JAVA \
    HL_INFO(APP_FILEMANAGER,     FMGR_DEFAULT_FOLDER_ROOT,    mmi_java_fmgr_hyperlink_callback)
#else
#define HL_INFO_JAVA
#endif


#if defined(__MMI_MY_FAVORITE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if defined(__MMI_MY_FAVORITE_IMAGES_HYPERLINK__)
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
    #endif 
/* under construction !*/
    #if defined(__MMI_MY_FAVORITE_AUDIO_HYPERLINK__)
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
    #endif 
/* under construction !*/
    #if defined(__MMI_MY_FAVORITE_VIDEO_HYPERLINK__)
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
    #endif 
/* under construction !*/
    #if defined(__MMI_MY_FAVORITE_MMSBOX_HYPERLINK__)
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
    #endif 
/* under construction !*/
#if defined(__MMI_MY_FAVORITE_SWFLASH_HYPERLINK__)
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
    #endif 
/* under construction !*/
    #if defined(__MMI_MY_FAVORITE_THEME_HYPERLINK__)
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
    #endif
/* under construction !*/
    #if defined(__MMI_MY_FAVORITE_OTHERS_HYPERLINK__)
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
    #endif
/* under construction !*/
#else
#define HL_INFO_MYFAVORITE
#endif

#endif /* __FMGR_HYPERLINK_SUPPORT__ */

#ifdef __FMGR_CUSTOM_ROOT_SUPPORT__
/****************************************************************************/
/*  
 *  
 *
 */
#define CR_LINK2_INFO(string_id, icon_id, lsk_string_id, lsk_hdlr, rarrow_hdlr)
#define CR_LINK_INFO(path, string_id, icon_id)
#define CR_DRV_INFO(drive_type, string_id, icon_id)

#ifdef __MMI_MY_FAVORITE_IMAGES__
#define FMGR_CR_MYFAV_IMAGES \
    CR_LINK_INFO(FMGR_DEFAULT_FOLDER_IMAGES,    STR_ID_MY_FAVORITE_FOLDER_IMAGES,       IMG_ID_MY_FAVORITE_FOLDER_IMAGES)
#else
#define FMGR_CR_MYFAV_IMAGES
#endif

#ifdef __MMI_MY_FAVORITE_AUDIO__
#define FMGR_CR_MYFAV_AUDIO \
    CR_LINK_INFO(FMGR_DEFAULT_FOLDER_AUDIO,     STR_ID_MY_FAVORITE_FOLDER_AUDIO,        IMG_ID_MY_FAVORITE_FOLDER_AUDIO)
#else
#define FMGR_CR_MYFAV_AUDIO
#endif

#ifdef __MMI_MY_FAVORITE_VIDEO__
#define FMGR_CR_MYFAV_VIDEO \
    CR_LINK_INFO(FMGR_DEFAULT_FOLDER_VIDEO,     STR_ID_MY_FAVORITE_FOLDER_VIDEO,        IMG_ID_MY_FAVORITE_FOLDER_VIDEO)
#else
#define FMGR_CR_MYFAV_VIDEO
#endif

#ifdef __MMI_MY_FAVORITE_MMSBOX__
#define FMGR_CR_MYFAV_MMSBOX \
    CR_LINK_INFO(FMGR_DEFAULT_FOLDER_MMSBOX,    STR_ID_MY_FAVORITE_FOLDER_MMSBOX,       IMG_ID_MY_FAVORITE_FOLDER_MMSBOX)
#else
#define FMGR_CR_MYFAV_MMSBOX
#endif

#ifdef __MMI_MY_FAVORITE_SWFLASH__
#define FMGR_CR_MYFAV_SWFLASH \
    CR_LINK_INFO(FMGR_DEFAULT_FOLDER_SWFLASH,   STR_ID_MY_FAVORITE_FOLDER_SWFLASH,      IMG_ID_MY_FAVORITE_FOLDER_SWFLASH)
#else
#define FMGR_CR_MYFAV_SWFLASH
#endif

#ifdef __MMI_MY_FAVORITE_THEME__
#define FMGR_CR_MYFAV_THEME \
    CR_LINK_INFO(FMGR_DEFAULT_FOLDER_THEMES,    STR_ID_MY_FAVORITE_FOLDER_THEME,        IMG_ID_MY_FAVORITE_FOLDER_THEME)
#else
#define FMGR_CR_MYFAV_THEME
#endif

#ifdef __MMI_MY_FAVORITE_OTHERS__
#define FMGR_CR_MYFAV_OTHERS \
    CR_LINK_INFO(FMGR_DEFAULT_FOLDER_RECEIVED,  STR_ID_MY_FAVORITE_FOLDER_OTHERS,       IMG_ID_MY_FAVORITE_FOLDER_OTHERS)
#else
#define FMGR_CR_MYFAV_OTHERS
#endif

#ifdef __MMI_MY_FAVORITE_MEMORYCARD__
#define FMGR_CR_MYFAV_CARD \
    CR_DRV_INFO (SRV_FMGR_DRV_CARD_TYPE,        STR_GLOBAL_MEMORY_CARD,  IMG_ID_MY_FAVORITE_FOLDER_MEMORY_CARD)
#else
#define FMGR_CR_MYFAV_CARD
#endif

#ifdef __MMI_MY_FAVORITE_JAVABOX__
#ifdef __MMI_JAVA_CATEGORY_SUPPORT__
#define FMGR_CR_MYFAV_JAVABOX \
    CR_LINK2_INFO (STR_ID_MY_FAVORITE_FOLDER_JAVABOX,  IMG_ID_MY_FAVORITE_FOLDER_JAVABOX, STR_GLOBAL_OPTIONS, mmi_my_favorite_entry_javabox_option, mmi_java_category_magicbox_filter_callback)
#else
extern void EntryScrJavaMenu(void);
#define FMGR_CR_MYFAV_JAVABOX \
    CR_LINK2_INFO (STR_ID_MY_FAVORITE_FOLDER_JAVABOX,  IMG_ID_MY_FAVORITE_FOLDER_JAVABOX, STR_GLOBAL_OPTIONS, mmi_my_favorite_entry_javabox_option, EntryScrJavaMenu)
#endif
#else
#define FMGR_CR_MYFAV_JAVABOX
#endif

#ifdef __MMI_MY_FAVORITE_GPLUSGAME__
#define FMGR_CR_MYFAV_GPLUSGAME \
    CR_LINK2_INFO (STR_ID_MY_FAVORITE_FOLDER_GPLUSGAME,  IMG_ID_MY_FAVORITE_FOLDER_GPLUSGAME, STR_GLOBAL_OPEN, mmi_java_category_gplus_filter_callback, mmi_java_category_gplus_filter_callback)
#else
#define FMGR_CR_MYFAV_GPLUSGAME
#endif

#ifdef __OP12__
extern void mmi_fmgr_display_memory_status(void);
#define FMGR_CR_MYFAV_MEM_DETAIL \
    CR_LINK2_INFO (STR_GLOBAL_MEMORY_STATUS,  IMG_ID_FMGR_ICON_FILE_TYPE_FOLDER, STR_GLOBAL_OPEN, mmi_fmgr_display_memory_status, NULL)
#else
#define FMGR_CR_MYFAV_MEM_DETAIL
#endif

#if defined(__MMI_MY_FAVORITE__)
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
#else
#define FMGR_CUST_ROOT_COL
#endif


#endif /* __FMGR_CUSTOM_ROOT_SUPPORT__ */

#endif /* __MMI_FILE_MANAGER__ */
/****************************************************************************
* Global variable
*****************************************************************************/


/****************************************************************************
* Global Function
*****************************************************************************/


#endif /* _FMGR_TABLE_H_ */


