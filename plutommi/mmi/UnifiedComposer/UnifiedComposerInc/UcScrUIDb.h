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
*  Copyright Statement: *  -------------------- *  This software is protected by 
Copyright and the information contained *  herein is confidential. The software 
may not be copied and the information *  contained herein may not be used or 
disclosed except with the written *  permission of MediaTek Inc. (C) 2002 * 
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * UcScrUIDb.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines local enum, constant and prototypes for Unified Composer
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _MMI_UNIFIED_COMPOSER_SCREEN_UI_DB_H
#define _MMI_UNIFIED_COMPOSER_SCREEN_UI_DB_H

#ifdef __MMI_MMS_POSTCARD__
#include "UcPcrdProt.h"
#endif 
//suggested add
    #include "MMI_features.h"
    #include "UcScrUIProt.h"
   // #include "mmi_rp_app_unifiedcomposer_def.h"
    #include "GlobalResDef.h"
    #include "UcAppProt.h"
    #include "mmi_frm_events_gprot.h"

const mmi_uc_frm_resourceDB_struct g_uc_frm_resourceDB[] = 
{
    {   /* MMI_UC_FLOW_INSTANCE_ID_DUMMY_START */
     0, 0, 0, 0, 0, 0,
     },
    {   /* MMI_UC_FLOW_INSTANCE_ID_PROCESSING */
     0, 0, 0, 0, 0, 0,
     },
    {   /* MMI_UC_FLOW_INSTANCE_ID_EDITOR */
     STR_UC_WRITE_MSG_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS, STR_GLOBAL_EXIT, IMG_GLOBAL_BACK,
     },
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT */
     STR_GLOBAL_OPTIONS, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
#ifndef __MMI_SLIM_MMS_2__
    {   /* MMI_UC_FLOW_INSTANCE_ID_MSG_DETAIL */
     STR_GLOBAL_DETAILS, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 0},
#endif
    {   /* MMI_UC_FLOW_INSTANCE_ID_MSG_PREVIEW */
     0, 0, 0, 0, 0, 0,
     },
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_INSERT */
     0, 0, 0, 0, 0, 0,
     },
    {   /* MMI_UC_FLOW_INSTANCE_ID_ADD_PICTURE_OPTIONS */
     STR_UC_ADD_PICTURE_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
    {   /* MMI_UC_FLOW_INSTANCE_ID_ADD_SOUND_OPTIONS */
     STR_UC_ADD_SOUND_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
#ifdef __MMI_MMS_VIDEO_FEATURE__
    {   /* MMI_UC_FLOW_INSTANCE_ID_ADD_VIDEO_OPTIONS */
     STR_UC_ADD_VIDEO_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
#endif
    {   /* MMI_UC_FLOW_INSTANCE_ID_ADVANCED_OPTIONS */
     STR_UC_ADVANCED_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_REMOVE */
     STR_GLOBAL_REMOVE, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
#ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_REPLACE */
     STR_GLOBAL_REPLACE, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
#endif
    {   /* MMI_UC_FLOW_INSTANCE_ID_PICTURE_OPTIONS */
     STR_UC_PICTURE_OPTIONS_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
    {   /* MMI_UC_FLOW_INSTANCE_ID_SOUND_OPTIONS */
     STR_UC_SOUND_OPTIONS_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
    {   /* MMI_UC_FLOW_INSTANCE_ID_VIDEO_OPTIONS */
     STR_UC_VIDEO_OPTIONS_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
    {   /* MMI_UC_FLOW_INSTANCE_ID_ATTACHMENT_OPTIONS */
     STR_UC_ATTACHMENT_OPTIONS_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 0},
#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
    {   /* MMI_UC_FLOW_INSTANCE_ID_TEXT_OPTIONS */
     STR_UC_TEXT_OPTIONS_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 0},
#endif
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_ADD_RECIPIENT */
     0, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_SELECT, 0, STR_GLOBAL_BACK, 0},
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_ADD_RECIPIENT_OPTIONS */
     STR_GLOBAL_OPTIONS, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_ENTER_RECIPIENT */
     STR_UC_ENTER_RECIPIENT_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OPTIONS, 0, STR_GLOBAL_BACK, 0, 0},
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_EDIT_RECIPIENT */
     STR_UC_EDIT_RECIPIENT_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OPTIONS, 0, STR_GLOBAL_BACK, 0, 0},
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
#if defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__) && defined(__MMI_TOUCH_SCREEN__)
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_ATTACH_LIST */
     STR_UC_ATTACHMENT_LIST_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
#else
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_ATTACHMENT_REMOVE */
     STR_UC_ATTACHMENT_LIST_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 0},
#ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_ATTACHMENT_REPLACE */
     STR_UC_ATTACHMENT_LIST_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 0},
#endif
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT */
     STR_UC_SLIDE_OPTION_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
#ifdef __MMI_MMS_2__
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_SLIDE_TIMING */
     STR_UC_SLIDE_TIMING_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, 0, STR_GLOBAL_BACK, 0, 0},
#endif
#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_TEXT_TIMING */
     STR_UC_SLIDE_TEXT_TIMING_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 0},
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_IMAGE_TIMING */
     STR_UC_SLIDE_IMAGE_TIMING_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 0},
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_AUDIO_TIMING */
     STR_UC_SLIDE_AUDIO_TIMING_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 0},
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_VIDEO_TIMING */
     STR_UC_SLIDE_VIDEO_TIMING_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 0},
#endif
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_SEND_OPT */
     STR_UC_SEND_OPTION_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     0, 0, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 0},
#ifndef __MMI_FTE_SUPPORT__
    {   /* MMI_UC_FLOW_INSTANCE_ID_EXIT_OPT */
     STR_GLOBAL_OPTIONS, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 0},
#endif
#ifndef __MMI_SLIM_MMS_2__
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_INSERT_NEW_MM_OBJECT */
     0, 0, 0, 0, 0, 0,
     },
#endif
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    {   /* MMI_UC_FLOW_INSTANCE_ID_SUBJECT_EDITOR */
     STR_GLOBAL_SUBJECT, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
    {   /* MMI_UC_FLOW_INSTANCE_ID_CONFIRM */
     0, 0,
     STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
     },
    {   /* MMI_UC_FLOW_INSTANCE_ID_SIG_CONFIRM */
     0, 0,
     STR_GLOBAL_YES, IMG_GLOBAL_YES, STR_GLOBAL_NO, IMG_GLOBAL_NO,
     },
    {   /* MMI_UC_FLOW_INSTANCE_ID_INPUT_METHOD_AND_DONE */
     STR_GLOBAL_OPTIONS, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    {   /* MMI_UC_FLOW_INSTANCE_ID_ENTER_RECIPIENT_OPTIONS */
     STR_GLOBAL_OPTIONS, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
 #if !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && !defined(__MMI_MMS_STANDALONE_COMPOSER__)
    {   /* MMI_UC_FLOW_INSTANCE_ID_SENDING_FORGROUND_SMS */
     STR_GLOBAL_SENDING, 0,
     0, 0, STR_GLOBAL_CANCEL, 0, 0},
 #endif /* !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
 #if !defined(__MMI_MMS_BGSR_SUPPORT__)
    {   /* MMI_UC_FLOW_INSTANCE_ID_SENDING_FORGROUND_MMS */
     STR_UC_SENDING_MMS_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     0, 0, STR_GLOBAL_CANCEL, IMG_GLOBAL_BACK, 0}, 
 #endif /* !defined(__MMI_MMS_BGSR_SUPPORT__) */ 
  #if (MMI_MAX_SIM_NUM >=2)
    {   /* MMI_UC_FLOW_INSTANCE_ID_SIM_OPT */
     0, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
 #endif  /* #if (MMI_MAX_SIM_NUM ==2) */ 
 #ifdef __MMI_MMS_POSTCARD__
    {   /* MMI_UC_FLOW_INSTANCE_ID_WRITE_MSG_SELECTION */
     STR_UC_WRITE_MSG_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
    {   /* MMI_UC_FLOW_INSTANCE_ID_POSTCARD_RECIPIENT_OPTION */
     STR_UC_TO_OPTION_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
    {   /* MMI_UC_FLOW_INSTANCE_ID_POSTCARD_ADDRESS */
     STR_GLOBAL_ADDRESS, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
     },
 #endif /* __MMI_MMS_POSTCARD__ */ 
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    {   /* MMI_UC_FLOW_INSTANCE_ID_OPT_ADD_OBJECT */
     STR_GLOBAL_OPTIONS, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,
    },
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
     {/* MMI_UC_FLOW_INSTANCE_ID_OPT_HEADER_FIELDS*/
     STR_UC_HEADER_OPTIONS_ID, IMG_UC_ENTRY_SCRN_CAPTION_ID,
     STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK,     
     },
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
    {   /* MMI_UC_FLOW_INSTANCE_ID_TOTAL */
     0, 0,
     }
};

const mmi_uc_frm_screenDB_struct g_uc_frm_screenDB[] = 
{
    {
     SCR_ID_UC_DUMMY,
     MMI_UC_FLOW_INSTANCE_ID_DUMMY_START,
     0,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_ui_generic_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_dummy_screen_draw_func,
     NULL,
     mmi_uc_entry_dummy_screen,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UC_PROCESSING,
     MMI_UC_FLOW_INSTANCE_ID_PROCESSING,
     0,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_progress_pre_func,
     mmi_uc_frm_app_ui_plug_in_progress_post_func,
     mmi_uc_frm_ui_progress_screen_draw_func,
     mmi_uc_exit_processing_generic,
     mmi_uc_entry_processing,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UC_EDITOR,
     MMI_UC_FLOW_INSTANCE_ID_EDITOR,
     0,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_content_editor_pre_func,
     mmi_uc_frm_app_ui_plug_in_content_editor_post_func,
     mmi_uc_frm_ui_content_editor_draw_func,
     mmi_uc_exit_write_msg,
     mmi_uc_entry_write_msg,
     mmi_uc_pre_entry_option,
     mmi_uc_go_back_from_write_msg,
     NULL,
     mmi_uc_frm_sh_content_editor_delete_screen},
    {
     SCR_ID_UC_OPT,
     MMI_UC_FLOW_INSTANCE_ID_OPT,
     MENU_ID_UC_OPT,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_uc_editor_option_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_uc_opt,
     mmi_uc_entry_option,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
#ifndef __MMI_SLIM_MMS_2__
    {
     SCR_ID_UC_MSG_DETAIL,
     MMI_UC_FLOW_INSTANCE_ID_MSG_DETAIL,
     MENU_ID_UC_OPT_MSG_DETAIL,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_msg_detail_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_full_text_screen_draw_func,
     mmi_uc_exit_generic,
     mmi_uc_entry_msg_detail,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     NULL,
     NULL},
#endif
    {
     SCR_ID_UC_MSG_PREVIEW,
     MMI_UC_FLOW_INSTANCE_ID_MSG_PREVIEW,
     0,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_preview_screen_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_is_back_empty_body_draw_func,
     mmi_uc_exit_generic,
     mmi_uc_entry_preview,
     0,
     0,
     0,
     mmi_uc_preview_delete_screen},
    {
     SCR_ID_UC_OPT_INSERT,
     MMI_UC_FLOW_INSTANCE_ID_OPT_INSERT,
     0, 0, 0, 0, 0, 0,
     },
    {
     SCR_ID_UC_OPT_INSERT,
     MMI_UC_FLOW_INSTANCE_ID_ADD_PICTURE_OPTIONS,
     MENU_ID_UC_OPT_ADD_PICTURE,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_add_picture_options_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_add_picture_options,
     mmi_uc_add_picture_options,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
    {
     SCR_ID_UC_OPT_INSERT,
     MMI_UC_FLOW_INSTANCE_ID_ADD_SOUND_OPTIONS,
     MENU_ID_UC_OPT_ADD_SOUND,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_add_sound_options_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_add_sound_options,
     mmi_uc_add_sound_options,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
#ifdef __MMI_MMS_VIDEO_FEATURE__
    {
     SCR_ID_UC_OPT_INSERT,
     MMI_UC_FLOW_INSTANCE_ID_ADD_VIDEO_OPTIONS,
     MENU_ID_UC_OPT_ADD_VIDEO,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_add_video_options_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_add_video_options,
     mmi_uc_add_video_options,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
#endif
    {
     SCR_ID_UC_OPT_INSERT,
     MMI_UC_FLOW_INSTANCE_ID_ADVANCED_OPTIONS,
     MENU_ID_UC_OPT_ADVANCED,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_advanced_options_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_advance_options,
     mmi_uc_advanced_options,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
    {
     SCR_ID_UC_OPT_REMOVE,
     MMI_UC_FLOW_INSTANCE_ID_OPT_REMOVE,
     MENU_ID_UC_OPT_REMOVE,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_remove_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_remove_options,
     mmi_uc_entry_remove,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
#ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
    {
     SCR_ID_UC_OPT_REPLACE,
     MMI_UC_FLOW_INSTANCE_ID_OPT_REPLACE,
     MENU_ID_UC_OPT_REPLACE,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_replace_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_replace_options,
     mmi_uc_entry_replace,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
#endif
    {
     SCR_ID_PICTURE_OPTIONS,
     MMI_UC_FLOW_INSTANCE_ID_PICTURE_OPTIONS,
     MENU_ID_UC_OPT_PICTURE_OPTIONS,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_opt_picture_opt_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_opt_picture_options,
     mmi_uc_opt_picture_option,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
    {
     SCR_ID_SOUND_OPTIONS,
     MMI_UC_FLOW_INSTANCE_ID_SOUND_OPTIONS,
     MENU_ID_UC_OPT_SOUND_OPTIONS,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_opt_sound_opt_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_opt_sound_options,
     mmi_uc_opt_sound_option,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
    {
     SCR_ID_VIDEO_OPTIONS,
     MMI_UC_FLOW_INSTANCE_ID_VIDEO_OPTIONS,
     MENU_ID_UC_OPT_VIDEO_OPTIONS,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_opt_video_opt_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_opt_video_options,
     mmi_uc_opt_video_option,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
    {
     SCR_ID_ATTACHMENT_OPTIONS,
     MMI_UC_FLOW_INSTANCE_ID_ATTACHMENT_OPTIONS,
     MENU_ID_UC_OPT_ATTACHMENT_OPTIONS,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_attachment_option_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_opt_attachment_options,
     mmi_uc_opt_attachment_option,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
    {
     SCR_ID_TEXT_OPTIONS, MMI_UC_FLOW_INSTANCE_ID_TEXT_OPTIONS,
     MENU_ID_UC_OPT_TEXT_OPTIONS,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_attachment_option_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_opt_text_options,
     mmi_uc_opt_text_option,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
#endif
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    {
     SCR_ID_UC_OPT_ADD_RECIPIENT,
     MMI_UC_FLOW_INSTANCE_ID_OPT_ADD_RECIPIENT,
     MENU_ID_UC_OPT_ADD_RECIPIENT,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_add_recipient_pre_func,
     mmi_uc_frm_app_ui_plug_in_add_recipient_post_func,
     mmi_uc_frm_ui_dynamic_list_draw_func,
     mmi_uc_frm_sh_add_recipient_exit_func,
     mmi_uc_entry_add_recipient,
     NULL,
     mmi_uc_frm_app_sh_add_recipient_rsk_handler,
     mmi_uc_frm_app_sh_add_recipient_hilite_handler,
     mmi_uc_app_recipient_list_delete_screen},
    {
     SCR_ID_UC_OPT_ADD_RECIPIENT_OPTIONS,
     MMI_UC_FLOW_INSTANCE_ID_OPT_ADD_RECIPIENT_OPTIONS,
     MENU_ID_UC_OPT_ADD_RECIPIENT,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_add_recipient_options_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_add_recipients_options,
     mmi_uc_entry_add_recipients_options,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
    {
     SCR_ID_UC_OPT_ENTER_RECIPIENT,
     MMI_UC_FLOW_INSTANCE_ID_OPT_ENTER_RECIPIENT,
     MENU_ID_UC_OPT_EDIT_RECIPIENT,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_add_recipient_editor_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_recipient_editor_draw_func,
     mmi_uc_exit_enter_recipient,
     mmi_uc_entry_enter_recipient,
     mmi_uc_entry_enter_recipient_options,
     mmi_uc_frm_sh_static_list_rsk_handler,
     NULL,
     NULL},
    {
     SCR_ID_UC_OPT_ENTER_RECIPIENT,
     MMI_UC_FLOW_INSTANCE_ID_OPT_EDIT_RECIPIENT,
     MENU_ID_UC_OPT_EDIT_RECIPIENT,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_add_recipient_editor_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_recipient_editor_draw_func,
     mmi_uc_exit_edit_recipient,
     mmi_uc_entry_edit_recipient,
     mmi_uc_entry_enter_recipient_options,
     mmi_uc_frm_sh_static_list_rsk_handler,
     NULL,
     NULL},
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
#if defined(__MMI_MSG_EDITOR_WITH_RECIPIENT__) && defined(__MMI_TOUCH_SCREEN__)
    {
     SCR_ID_UC_OPT_ATTACHMENT_LIST,
     MMI_UC_FLOW_INSTANCE_ID_OPT_ATTACH_LIST,
     0,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_attachment_list_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_single_buffer_list_draw_func,
     mmi_uc_exit_opt_attachment_list,
     mmi_uc_opt_attachment_list,
     mmi_uc_opt_attachment_option,
     mmi_uc_frm_sh_static_list_rsk_handler,
     mmi_uc_set_index,
     NULL},
#else
    {
     SCR_ID_UC_OPT_ATTACHMENT_LIST,
     MMI_UC_FLOW_INSTANCE_ID_OPT_ATTACHMENT_REMOVE,
     MENU_ID_UC_OPT_ATTACH_OPT_ATTACHMENT_REMOVE,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_attachment_list_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_single_buffer_list_draw_func,
     mmi_uc_exit_opt_attachment_option_remove,
     mmi_uc_opt_attachment_option_remove,
     mmi_uc_remove_object,
     mmi_uc_frm_sh_static_list_rsk_handler,
     mmi_uc_set_index,
     NULL},
#ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
    {
     SCR_ID_UC_OPT_ATTACHMENT_LIST,
     MMI_UC_FLOW_INSTANCE_ID_OPT_ATTACHMENT_REPLACE,
     MENU_ID_UC_OPT_ATTACH_OPT_ATTACHMENT_REPLACE,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_attachment_list_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_single_buffer_list_draw_func,
     mmi_uc_exit_opt_attachment_option_replace,
     mmi_uc_opt_attachment_option_replace,
     mmi_uc_select_fmgr_object,
     mmi_uc_frm_sh_static_list_rsk_handler,
     mmi_uc_set_index,
     NULL},
#endif
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
    {
     SCR_ID_UC_OPT_SLIDE_OPT,
     MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT,
     MENU_ID_UC_OPT_SLIDE_OPT,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_opt_slide_opt_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_slide_opt,
     mmi_uc_entry_slide_opt,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
#ifdef __MMI_MMS_2__
    {
     SCR_ID_UC_OPT_SLIDE_OPT_SLIDE_TIMING,
     MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_SLIDE_TIMING,
     MENU_ID_UC_OPT_SLIDE_OPT_TIMING,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_slide_time_editor_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_slide_time_editor_draw_func,
     mmi_uc_exit_slide_timing,
     mmi_uc_entry_slide_timing,
     mmi_uc_entry_slide_timing_done,
     mmi_uc_frm_sh_static_list_rsk_handler,
     NULL,
     NULL},
#endif
#if defined(__MMI_MMS_2__) && !defined(__MMI_SLIM_MMS_2__)
    {
     SCR_ID_UC_OPT_SLIDE_OPT_SLIDE_TIMING,
     MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_TEXT_TIMING,
     MENU_ID_UC_OPT_SLIDE_OPT_TEXT_TIMING,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_object_timing_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_app_ui_draw_object_timing_inline_cui_draw_func,
     mmi_uc_frm_sh_text_timing_exit_func,
     mmi_uc_show_text_timing,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     NULL,
     NULL},
    {
     SCR_ID_UC_OPT_SLIDE_OPT_SLIDE_TIMING,
     MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_IMAGE_TIMING,
     MENU_ID_UC_OPT_SLIDE_OPT_IMAGE_TIMING,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_object_timing_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_app_ui_draw_object_timing_inline_cui_draw_func,
     mmi_uc_frm_sh_image_timing_exit_func,
     mmi_uc_show_image_timing,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     NULL,
     NULL},
    {
     SCR_ID_UC_OPT_SLIDE_OPT_SLIDE_TIMING,
     MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_AUDIO_TIMING,
     MENU_ID_UC_OPT_SLIDE_OPT_AUDIO_TIMING,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_object_timing_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_app_ui_draw_object_timing_inline_cui_draw_func,
     mmi_uc_frm_sh_audio_timing_exit_func,
     mmi_uc_show_audio_timing,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     NULL,
     NULL},
    {
     SCR_ID_UC_OPT_SLIDE_OPT_SLIDE_TIMING,
     MMI_UC_FLOW_INSTANCE_ID_OPT_SLIDE_OPT_VIDEO_TIMING,
     MENU_ID_UC_OPT_SLIDE_OPT_VIDEO_TIMING,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_object_timing_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_app_ui_draw_object_timing_inline_cui_draw_func,
     mmi_uc_frm_sh_video_timing_exit_func,
     mmi_uc_show_video_timing,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     NULL,
     NULL},
#endif
    {
     SCR_ID_UC_OPT_SEND_OPT,
     MMI_UC_FLOW_INSTANCE_ID_OPT_SEND_OPT,
     MENU_ID_UC_OPT_SEND_OPT,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_send_opt_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_app_ui_draw_send_opt_inline_cui_draw_func,
     mmi_uc_exit_send_opt,
     mmi_uc_entry_send_opt,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     NULL,
     NULL},
#ifndef __MMI_FTE_SUPPORT__
    {
     SCR_ID_UC_EXIT_OPT,
     MMI_UC_FLOW_INSTANCE_ID_EXIT_OPT,
     MENU_ID_UC_EXIT_OPT,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_exit_opt_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_option,
     mmi_uc_entry_exit_option,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
#endif
#ifndef __MMI_SLIM_MMS_2__
    {
     SCR_ID_UC_OPT_INSERT_NEW_MM_OBJECT,
     MMI_UC_FLOW_INSTANCE_ID_OPT_INSERT_NEW_MM_OBJECT,
     0,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_enter_multimedia_screen_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_is_back_empty_body_draw_func,
     mmi_uc_exit_multimedia_generic,
     mmi_uc_enter_multimedia_app,
     0,
     0,
     0,
     NULL},
#endif
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    {
     SCR_ID_UC_SUBJECT_EDITOR,
     MMI_UC_FLOW_INSTANCE_ID_SUBJECT_EDITOR,
     MENU_ID_UC_OPT_EDIT_SUBJECT,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_subject_editor_pre_func,
     mmi_uc_frm_app_ui_plug_in_subject_editor_post_func,
     mmi_uc_frm_ui_subject_editor_draw_func,
     mmi_uc_exit_edit_subject,
     mmi_uc_entry_edit_subject,
     mmi_uc_entry_input_method_and_done,
     mmi_uc_restore_subject_after_back_from_edit_subject,
     NULL,
     NULL},
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
    {
     SCR_ID_UC_CONFIRM,
     MMI_UC_FLOW_INSTANCE_ID_CONFIRM,
     0,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_confirmation_screen_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_confirmation_screen_draw_func,
     mmi_uc_exit_displayConfirm,
     mmi_uc_entry_displayConfirm,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UC_SIG_CONFIRM,
     MMI_UC_FLOW_INSTANCE_ID_SIG_CONFIRM,
     0,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_sig_confirmation_screen_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_confirmation_screen_draw_func,
     mmi_uc_exit_sig_displayConfirm,
     mmi_uc_entry_sig_displayConfirm,
     NULL,
     NULL,
     NULL,
     NULL},
    {
     SCR_ID_UC_INPUT_METHOD_AND_DONE,
     MMI_UC_FLOW_INSTANCE_ID_INPUT_METHOD_AND_DONE,
     MENU_ID_UC_EDITOR_OPTION,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_input_method_and_done_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_input_method_and_done,
     mmi_uc_entry_input_method_and_done,
     mmi_uc_input_method_and_done_go_back_to_option,
     mmi_uc_frm_sh_static_list_rsk_handler,
     mmi_uc_frm_app_sh_input_method_and_done_hilite_handler,
     NULL},
#ifndef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    {
     SCR_ID_UC_INPUT_METHOD_AND_DONE,
     MMI_UC_FLOW_INSTANCE_ID_ENTER_RECIPIENT_OPTIONS,
     MENU_ID_UC_EDITOR_OPTION,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_enter_recipient_option_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_enter_recipient_options,
     mmi_uc_entry_enter_recipient_options,
     mmi_uc_enter_recipient_done,
     mmi_uc_frm_sh_static_list_rsk_handler,
     mmi_uc_highlight_enter_recipient_done,
     NULL},
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
 #if !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && !defined(__MMI_MMS_STANDALONE_COMPOSER__)
    {
     SCR_ID_UC_SENDING,
     MMI_UC_FLOW_INSTANCE_ID_SENDING_FORGROUND_SMS,
     MENU_ID_UC_OPT_DONE_SEND,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_progress_screen_for_send_cancellation_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_progress_screen_for_send_cancellation_draw_func,
     mmi_uc_exit_sending_sms,
     mmi_uc_entry_sending_sms,
     NULL,
     NULL,
     NULL,
     NULL},
 #endif /* !defined(__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__) && !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
 #if !defined(__MMI_MMS_BGSR_SUPPORT__)
    {
     SCR_ID_UC_SENDING,
     MMI_UC_FLOW_INSTANCE_ID_SENDING_FORGROUND_MMS,
     MENU_ID_UC_OPT_DONE_SEND,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_sending_mms_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_progress_meter_draw_func,
     mmi_uc_exit_sending_mms,
     mmi_uc_entry_sending_mms,
     NULL,
     mmi_uc_abort_send_mms,
     NULL,
     NULL},
 #endif /* !defined(__MMI_MMS_BGSR_SUPPORT__) */ 
  #if (MMI_MAX_SIM_NUM >=2)
    {
     SCR_ID_UC_SIM_OPT,
     MMI_UC_FLOW_INSTANCE_ID_SIM_OPT,
     MENU_ID_UC_OPT_SEND,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_sim_opt_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_sim_option,
     mmi_uc_entry_sim_option,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
 #endif  /* #if (MMI_MAX_SIM_NUM ==2) */ 
 #ifdef __MMI_MMS_POSTCARD__
    {
     SCR_ID_UC_WRITE_MSG_SELECTION,
     MMI_UC_FLOW_INSTANCE_ID_WRITE_MSG_SELECTION,
     MENU_ID_UC_WRITE_MSG_SELECTION,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_write_msg_selection_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_write_msg_selection,
     mmi_uc_entry_write_msg_selection,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     mmi_uc_app_write_msg_selection_delete_screen},
    {
     SCR_ID_POSTCARD_RECIPIENT_OPTION,
     MMI_UC_FLOW_INSTANCE_ID_POSTCARD_RECIPIENT_OPTION,
     MENU_ID_UC_WRITE_MSG_SELECTION,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_entry_multiple_recipient_option_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_entry_multiple_recipient_option,
     mmi_postcard_entry_multiple_recipient_option,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
    {
     SCR_ID_POSTCARD_ADDRESS,
     MMI_UC_FLOW_INSTANCE_ID_POSTCARD_ADDRESS,
     0,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_recipient_address_editor_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_app_ui_draw_postcard_addr_inline_cui_draw_func,
     mmi_frm_sh_postcard_exit_recipient_address_editor,
     mmi_postcard_entry_recipient_address_editor,
     NULL,
     NULL,
     NULL,
     mmi_postcard_delete_address_editor_callback},
 #endif /* __MMI_MMS_POSTCARD__ */ 
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
     {
      SCR_ID_UC_OPT_INSERT,
      MMI_UC_FLOW_INSTANCE_ID_OPT_ADD_OBJECT,
      MENU_ID_UC_OPT_INSERT,
      mmi_uc_frm_sh_create_func,
      mmi_uc_frm_app_ui_plug_in_entry_add_object_option_pre_func,
      mmi_uc_frm_app_ui_plug_in_generic_post_func,
      mmi_uc_frm_ui_static_list_cui_draw_func,
      mmi_uc_exit_add_object_selection,     
      mmi_uc_entry_add_object_selection,
      NULL,
      mmi_uc_frm_sh_static_list_rsk_handler,
      ExecuteCurrHiliteHandler,
      NULL
    },
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_MSG_EDITOR_WITH_RECIPIENT__
    {
     0,
     MMI_UC_FLOW_INSTANCE_ID_OPT_HEADER_FIELDS,
     MENU_ID_UC_OPT_HEADER_OPTIONS,
     mmi_uc_frm_sh_create_func,
     mmi_uc_frm_app_ui_plug_in_header_options_pre_func,
     mmi_uc_frm_app_ui_plug_in_generic_post_func,
     mmi_uc_frm_ui_static_list_cui_draw_func,
     mmi_uc_exit_generic,
     mmi_uc_enter_header_field,
     NULL,
     mmi_uc_frm_sh_static_list_rsk_handler,
     ExecuteCurrHiliteHandler,
     NULL},
#endif /* __MMI_MSG_EDITOR_WITH_RECIPIENT__ */
    {
     0,
     MMI_UC_FLOW_INSTANCE_ID_TOTAL,
     0, 0,
     }
};

#endif /* _MMI_UNIFIED_COMPOSER_SCREEN_UI_DB_H */ 
