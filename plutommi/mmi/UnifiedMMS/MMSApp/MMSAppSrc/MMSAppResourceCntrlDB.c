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
 * MMSAppResourceDB.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
// #include "MMI_include.h"
#ifdef __MMI_MMS_2__
#include "Fs_type.h"
#include "MMIDataType.h"
#include "MMSAppResDef.h"
// #include "mmi_rp_app_umms_mms_def.h"
#include "MMSAppResourceCntrlDB.h"
#include "MMSAppDataManager.h"
// #include "MMSAppUICommon.h"
#include "MMSAppUIController.h"
// #include "inlineCuiGprot.h"

#define MMI_UMMS_CNTRLR_DB_MAX (sizeof(g_umms_app_cntrlrDB)/sizeof(g_umms_app_cntrlrDB[0]))

const mmi_umms_app_cntrlr_struct g_umms_app_cntrlrDB[] = 
{

    {
     SCR_ID_UMMS_DRAFT_OPTION,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_get_option_scr_info_int,
     mmi_umms_app_dtmgr_check_option_scr_data_ready,

     },
    {
     SCR_ID_UMMS_INBOX_MMS_OPTION,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_get_option_scr_info_int,
     mmi_umms_app_dtmgr_check_option_scr_data_ready,
     },
    {
     SCR_ID_UMMS_INBOX_NOTIFICATION_OPTION,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_get_option_scr_info_int,
     mmi_umms_app_dtmgr_check_option_scr_data_ready,
     },
    {
     SCR_ID_UMMS_INBOX_DELIVERY_READ_OPTION,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_get_option_scr_info_int,
     mmi_umms_app_dtmgr_check_option_scr_data_ready,
     },
    {
     SCR_ID_UMMS_INBOX_JAVA_MMS_OPTION,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_get_option_scr_info_int,
     mmi_umms_app_dtmgr_check_option_scr_data_ready,
     },
    {
     SCR_ID_UMMS_SENT_OPTION,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_get_option_scr_info_int,
     mmi_umms_app_dtmgr_check_option_scr_data_ready,
     },
    {
     SCR_ID_UMMS_OUTBOX_OPTION,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_get_option_scr_info_int,
     mmi_umms_app_dtmgr_check_option_scr_data_ready,
     },
    {
     SCR_ID_UMMS_ARCHIVE_OPTION,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_get_option_scr_info_int,
     mmi_umms_app_dtmgr_check_option_scr_data_ready,
     },
 #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    {
     SCR_ID_UMMS_TEMPLATES_OPTIONS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_get_option_scr_info_int,
     mmi_umms_app_dtmgr_check_option_scr_data_ready,
     },
 #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
    {
     SCR_ID_UMMS_PROGRESS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_progress_data,
     mmi_umms_app_dtmgr_progress_ready_check},
    {
     SCR_ID_UMMS_PROGRESS_TMPLT,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_progress_data,
     mmi_umms_app_dtmgr_progress_ready_check},
    {
     SCR_ID_UMMS_MMS_VIEWER,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_get_viewer_data_ready,
     mmi_umms_app_dtmgr_check_viewer_scr_data_ready},
    {
     SCR_ID_UMMS_USE_NUMBER,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_get_use_details_ready,
     mmi_umms_app_dtmgr_check_use_details_ready},
    {
     SCR_ID_UMMS_USE_EMAIL,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_get_use_details_ready,
     mmi_umms_app_dtmgr_check_use_details_ready},
    {
     SCR_ID_UMMS_USE_URL,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_get_use_details_ready,
     mmi_umms_app_dtmgr_check_use_details_ready},
    {
     SCR_ID_UMMS_USE_SENDER,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_check_use_details_ready},
    /* -----------------------------Niraj-----------------------------------------------// */
    {
     SCR_ID_UMMS_MESSAGE_SETTINGS_FOR_COMMON_SETTINGS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_dtmgr_check_msg_info_ready, */
     },
    {
     SCR_ID_UMMS_MESSAGE_SETTINGS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_dtmgr_check_msg_info_ready, */
     },
    {
     SCR_ID_UMMS_COMPOSE_SETTINGS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_dtmgr_check_msg_info_ready, */
     },
    {
     SCR_ID_UMMS_RETRIEVAL_SETTINGS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_dtmgr_check_msg_info_ready, */
     },
    {
     SCR_ID_UMMS_SENDING_SETTINGS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_dtmgr_check_msg_info_ready, */
     },
    {
     SCR_ID_UMMS_COMPOSE_SIGNATURE_SETTINGS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_dtmgr_check_msg_info_ready, */
     },
    {
     SCR_ID_UMMS_RETRIEVAL_FILTERS_SETTINGS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_dtmgr_check_msg_info_ready, */
     },
    {
     SCR_ID_UMMS_COMPOSE_IMAGE_OPTION,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_dtmgr_check_msg_info_ready, */
     },
/*****************************************amit added ***************************/

    {
     SCR_ID_UMMS_MMS_MESSAGE_STATUS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_memory_status_data_ready_check */
     },
 #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) 
    {
     SCR_ID_UMMS_MMS_MESSAGE_STATUS_PHONE,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_memory_status_data_ready_check */
     },
    {
     SCR_ID_UMMS_MMS_MESSAGE_STATUS_CARD,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_memory_status_data_ready_check */
     },
 #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    {
     SCR_ID_UMMS_SAVE_OBJECT_ATTACHMENT_LIST,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_save_objects_attachment_data_ready_check */
     },
    {
     SCR_ID_UMMS_SAVE_OBJECT,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_save_objects_items_list_data_ready_check */
     },
    {
     SCR_ID_UMMS_RETRIEVED_MMS_PROPERTIES,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_mms_properties_data_ready_check */
     },
 #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
    {
     SCR_ID_UMMS_SORT_OPTION,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_progress_data,
     mmi_umms_app_dtmgr_progress_ready_check},
 #endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */ 
    {
     SCR_ID_UMMS_MMS_OPTIONS_USE_DETAILS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_use_details_menu_data_ready_check */
     },
 #ifdef __MMI_MMS_PREVIEW_GOTO__
    {
     SCR_ID_UMMS_PREVIEW_OPTIONS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_mms_preview_menu_data_ready_check */
     },
    {
     SCR_ID_UMMS_PREVIEW_SLIDE_LIST,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_mms_preview_menu_data_ready_check */
     },
 #endif /* __MMI_MMS_PREVIEW_GOTO__ */ 
    {
     SCR_ID_UMMS_JAVA_OPTIONS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_java_options_menu_data_ready_check */
     },
    {
     SCR_ID_UMMS_MESSAGE_SETTINGS_SIM_SELECTION,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_sim_selection_profile_menu_data_ready_check */
     },
    {
     SCR_ID_UMMS_NOTIFICATION_NEW_MMS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_notification_option_screen_data_ready_check */
     },
    {
     SCR_ID_UMMS_READ_DELIVERY_REPORT_OPTIONS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_show_report_options_screen_data_ready_check */
     },
    {
     SCR_ID_UMMS_SIM_OPTION,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_show_sim_options_resend_data_ready_check */
     },
    {
     SCR_ID_UMMS_OPTIONS_USE_DETAILS_ADDRESSES_OPTIONS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_show_use_details_addresses_options_data_ready_check */
     },
    {
     SCR_ID_UMMS_MESSAGE_STATUS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_show_use_message_status_data_ready_check */
     },
 #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    {
     SCR_ID_UMMS_TEMPLATES_DEFAULT_USER_DEFINED,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check},

    {SCR_ID_UMMS_TEMPLATES,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_get_user_template_scr_info_int,
     mmi_umms_app_dtmgr_check_template_scr_data_ready,
     },
    {SCR_ID_UMMS_FWD_EDIT_CLUBBED,  /* temporary for default template */
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_template_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_get_default_template_scr_info_int,
     mmi_umms_app_dtmgr_check_template_scr_data_ready,
     },
 #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
    {
     15,                                        /* SCR_POPUP_SCREEN, */
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_show_new_message_popup_data_ready_check */
     },
    {
     SCR_ID_UMMS_CONFIRM,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_progress_data,
     mmi_umms_app_dtmgr_progress_ready_check},
    {
     SCR_ID_UMMS_DISPLAY_POPUP,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_progress_data,
     mmi_umms_app_dtmgr_progress_ready_check},
    {
     SCR_ID_UMMS_CALLBACK_DISPLAY_POPUP,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     mmi_umms_app_dtmgr_progress_data,
     mmi_umms_app_dtmgr_progress_ready_check},
    {
     SCR_ID_UMMS_READ_DELIVERY_REPORT_VIEW_SCREEN,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check},
 #ifdef __MMI_MMS_ITERATOR_VIEWER__
    {
     SCR_ID_UMMS_HANDLE_ABNORMAL_VIEW_SCREEN,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check},
 #endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
 #if defined( __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && !defined(__MMI_MMS_ONLY_MEMORY_CARD_STORAGE_SUPPORT__)
    {
     SCR_ID_UMMS_MMS_PREFER_STORAGE,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_cntrl_check_data_ready},
#ifdef __MMI_MMS_MSG_STORAGE_FILTER_SUPPORT__
     {
     SCR_ID_UMMS_MMS_MSG_FILTER,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_cntrl_check_data_ready},
#endif
 #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    {
     SCR_ID_UMMS_DISPLAY_INFINITE_POPUP,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_notification_option_screen_data_ready_check */
     },
 #ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
    {
     SCR_ID_UMMS_MMS_DELIVERY_STATUS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_memory_status_data_ready_check */
     },
    {
     SCR_ID_UMMS_MMS_READ_STATUS,
     mmi_umms_app_cntrlr_create_func,
     mmi_umms_app_cntrlr_pre_func,
     mmi_umms_app_cntrlr_post_func,
     mmi_umms_app_cntrlr_show_func,
     NULL,
     mmi_umms_app_dtmgr_progress_ready_check    /* mmi_umms_app_memory_status_data_ready_check */
     },
 #endif /* __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__ */ 

    /* {
       SCR_ID_UMMS_PREVIEW_OPTIONS,
       mmi_umms_cntrlr_create_func,
       mmi_umms_cntrlr_pre_func,
       mmi_umms_cntrlr_post_func,
       mmi_umms_cntrlr_show_func,
       NULL,
       mmi_umms_app_prefer_mms_storage_data_ready_check
       }, tested for radio screen */
};


/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_resource_get_cntrlrDB
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scr_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const mmi_umms_app_cntrlr_struct *mmi_umms_app_resource_get_cntrlrDB(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    U16 maxCount = MMI_UMMS_CNTRLR_DB_MAX;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < maxCount; index++)
    {
        if (g_umms_app_cntrlrDB[index].scrn_id == scr_id)
        {
            return &g_umms_app_cntrlrDB[index];
        }
    }
    return NULL;
}

#endif /* __MMI_MMS_2__ */ 

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 

