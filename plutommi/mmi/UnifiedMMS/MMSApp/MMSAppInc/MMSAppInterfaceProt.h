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
 * MMSAppInterfaceProt.h
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
 * removed!
 *
 * removed!
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
#ifndef MMS_APP_INTERFACE_PROT_H
#define MMS_APP_INTERFACE_PROT_H
#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "MmsSrvProt.h"
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
#include "MmsContextSrvLE.h"
#endif 
/* This structure defines the request parameters for uc launch API mmi_umms_start_uc */
typedef struct
{
    U32 msg_id;         /* Message id */
    U8 sim_id;          /* Sim id, mmi_sim_id_enum */
    U8 uc_mode;         /* UC mode, mma_mode_enum */
    U8 edit_mode;       /* Edit mode, srv_uc_MMS_edit_mode_enum */
    U8 storage_type;    /* mma_msg_storage_type_enum, storage type */
} mmi_umms_start_uc_struct;

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
#define MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO 1
#define MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO 2
typedef srv_mms_base_data_struct mmi_umms_app_dtmgr_option_scr_data_struct;
typedef srv_mms_app_dtmgr_viewer_info_data mmi_umms_app_dtmgr_viewer_info_data;

#define mmi_umms_app_dtmgr_get_data(U16) mmi_umms_app_if_dummy_get_data()
#define mmi_umms_app_dtmgr_reset_data(void) mmi_umms_app_if_dummy_reset_data()
#define mmi_umms_app_dtmgr_deinit_viewer_service_through_dtmgr(void)mmi_umms_app_if_dummy_reset_data()
#define mmi_umms_app_dtmgr_delete_viewer_data(U16)mmi_umms_app_if_dummy_reset_data()
extern void *mmi_umms_app_if_dummy_get_data(void);

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 

/* Internal Interface */
#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
extern void mmi_umms_app_if_show_recipient_addresses_options(void);
extern void mmi_umms_app_if_show_mms_option_screens(void);
extern void mmi_umms_app_if_show_composer_option(void);
//extern void mmi_umms_app_if_show_slim_reply_option(void);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
extern void mmi_umms_app_if_show_viewer_screen(void);
extern void mmi_umms_app_if_show_draft_option(void);
extern void mmi_umms_app_if_show_inbox_mms_option(void);
extern void mmi_umms_app_if_show_inbox_read_delivery_option(void);
extern void mmi_umms_app_if_show_inbox_notification_option(void);
extern void mmi_umms_app_if_show_inbox_java_option(void);
extern void mmi_umms_app_if_show_sent_option(void);
extern void mmi_umms_app_if_show_archive_option(void);
extern void mmi_umms_app_if_show_outbox_option(void);

#if (MMI_MAX_SIM_NUM == 2)      /* RESEND MENU LIST FOR DUAL SIM */
extern void mmi_umms_app_if_show_sim_option(void);
#endif 
extern void mmi_umms_app_if_show_mms_template_option(void);

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
extern void mmi_umms_app_if_show_user_template_list(void);
#endif 
extern void mmi_umms_app_if_show_progress_screen(void);
extern void mmi_umms_app_if_show_sort_selection_menu(void);
extern void mmi_umms_app_if_show_display_confirm_screen(void);

/*  Proprietary Interface API */
extern void mmi_umms_app_interface_prop_mms_only_options(void *data);
extern void mmi_umms_app_if_show_property_screen(void);
extern void mmi_umms_app_if_show_error_pop_up(const U8 error_result);

#ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
extern void mmi_umms_app_if_show_sort_by_screen(void);
#endif 
/* --------------------------------Niraj Added------------------------------------// */
extern void mmi_umms_app_if_show_message_settings_menu(void);
extern void mmi_umms_app_if_show_mms_message_settings_menu(void);
extern void mmi_umms_app_if_show_compose_settings_menu(void);
extern void mmi_umms_app_if_show_retrieval_settings_menu(void);
extern void mmi_umms_app_if_show_retrieval_filters_settings_menu(void);
extern void mmi_umms_app_if_show_sending_settings_menu(void);
extern void mmi_umms_app_if_show_compose_signature_settings_menu(void);
extern void mmi_umms_app_if_show_signature_options_menu(void);
extern void mmi_umms_app_show_message_settings_menu(void);
extern void mmi_umms_app_show_template_menu(void);

/*********************************Amit Added*****************************************/
extern void mmi_umms_app_if_show_memory_status_screen(void);
extern void mmi_umms_app_if_show_save_objects_attchement_list(void);
extern void mmi_umms_app_if_show_save_objects_item_list(void);
extern void mmi_umms_app_if_show_mms_properties_screen(void);
extern void mmi_umms_app_if_show_sort_by_selection_menu(void);
extern void mmi_umms_app_if_show_use_details_menu(void);
extern void mmi_umms_app_if_show_preview_mms_menu(void);
extern void mmi_umms_app_if_show_java_mms_options(void);
extern void mmi_umms_app_if_show_sim_selection_profile_menu(void);
extern void mmi_umms_app_if_show_notification_option_screen(void);
extern void mmi_umms_app_if_show_report_options_screen(void);
extern void mmi_umms_app_if_show_sim_options_for_resend(void);
extern void mmi_umms_app_if_show_use_details_addresses_options(void);
extern void mmi_umms_app_if_show_message_status_screen(void);
extern void mmi_umms_app_if_show_new_message_popup(void);

/*  Proprietary Interface API */
extern void mmi_umms_app_interface_prop_show_viewer_screen(void *data, U8 new_state);
extern void mmi_umms_app_interface_prop_mms_only_options(void *data);
extern MMI_BOOL mmi_umms_app_interface_entry_from_um(U16 key, U32 msg_id, void *user_data, mmi_id parent_grp_id);

extern void mmi_umms_if_show_user_defined_template_list(void);
extern void mmi_umms_if_show_default_template_list(void);

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
extern void mmi_umms_app_if_show_default_template_list(void);
#endif 
extern void mmi_umms_app_if_show_display_popup_screen(void);
extern void mmi_umms_app_if_show_display_callback_popup_screen(void);
extern void mmi_umms_app_if_preview_uc_send(void);
extern void mmi_umms_app_if_show_uc_add_address_screen(void);
extern void mmi_umms_app_if_show_mms_template_option(void);
extern void mmi_umms_app_if_show_preview_option(void);
extern void mmi_umms_app_if_show_preview_slide_list(void);
extern void mmi_umms_app_if_show_edit_profile_screen(void);
extern void mmi_umms_app_if_show_rr_dr_view_screen(void);
extern BOOL mmi_umms_app_if_is_viewer_init(void);

#ifdef __MMI_MMS_ITERATOR_VIEWER__
extern void mmi_umms_app_if_show_abnormal_view_screen(void);
#endif 

extern MMI_BOOL mmi_umms_get_app_asm_memory(void);
extern void mmi_umms_init_pools(void);

/************** ADDED FOR REMOVING NULL ENTRY FUNCTION *****************/
extern void mmi_umms_app_dummy_entry_function(void);
extern void mmi_umms_start_uc(mmi_umms_start_uc_struct *para);

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
typedef void (*uc_func_ptr) (void *);
typedef kal_int8 *(*uc_func_ptr_general_insert_get_addr_fn) (kal_uint16 index, kal_uint16 *type);
typedef struct
{
    mma_mms_addr_list_struct *addr;         /* Addresses linklist */
    kal_uint8 *file_path;                   /* File path */
    kal_uint8 *text_buffer;                 /* File path */
    kal_uint8 *subject;                     /* File path */
    void *info;                             /* Info. SMS use msg ID/Index to pass */
    uc_func_ptr callback;                   /* Callback function specified by caller of object forward, for calling after use of object */
    void *callback_para;                    /* Input paramter to callback function above */
    uc_func_ptr_general_insert_get_addr_fn get_address_callback;        /* Callback function specified by caller to call if multiple addresses forwarded */
    kal_uint16 text_num;                    /* File path */
    kal_uint8 addr_num;                     /* Max addresses */
    U8 sim_id;                              /* srv_uc_sim_id */
    srv_mms_msg_type_enum msg_type;         /* srv_uc_msg_type_enum */
    srv_mms_uc_info_type_enum info_type;    /* srv_uc_info_type_enum */
} mmi_umms_uc_entry_write_struct;

extern void mmi_umms_app_ui_callback_entry_write_msg_with_content(
                srv_mms_state_enum type,
                mmi_umms_uc_entry_write_struct *data);

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
#endif /* __MMI_MMS_2__ */ 
#endif /* MMS_APP_INTERFACE_PROT_H */ 

