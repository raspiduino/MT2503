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
 * MMSAppDataManager.h
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
#ifndef MMS_APP_DATA_MGR_H
#define MMS_APP_DATA_MGR_H
#include "MMI_features.h"
#if defined (__MMI_MMS_2__) && !defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)
#include "UMGProt.h"
// #include "App_usedetails.h"
#include "MmsSrvGprot.h"
#include "MMSAppInterfaceGProt.h"
#include "inlineCuiGprot.h"
#include "wap_adp.h"
#include "MMIDataType.h"
#include "mma_struct.h"
#include "mma_api.h"
#include "gui_typedef.h"
#include "MmsXMLDefSrv.h"
#include "wgui_categories_MMS_viewer.h"
#include "kal_public_defs.h"
#include "UmSrvDefs.h"
#include "MMSAppUICommon.h"
#include "FileMgrSrvGProt.h"
#include "MMI_features_switch.h"
#include "MMI_features_type.h"
#include "UmSrvGprot.h"
#include "fs_type.h"
#include "kal_general_types.h"

#define MMI_UMMS_MAX_DTMGR_HANDLES 10
#define DTMGR_MMS_UNBLOCK_TIME (50)
/* context structures of data manager */

typedef enum
{
    MMI_UMMS_POPUP_NORMAL,
    MMI_UMMS_POPUP_NO_SOUND,
    MMI_UMMS_POPUP_NO_POPUP,
    MMI_UMMS_POPUP_TOTAL_NUM
} srv_mms_popup_type_enum;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_MMS_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #endif /* __MMI_MMS_DUAL_SIM__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 

typedef enum
{
    MMI_UMMS_APP_DTMGR_GET_DATA_NONE,
    MMI_UMMS_APP_DTMGR_GET_MSG_INFO_WAIT,
    MMI_UMMS_APP_DTMGR_GET_CONTENT_INFO_WAIT,
    MMI_UMMS_APP_DTMGR_MSG_INFO_DONE,
    MMI_UMMS_APP_DTMGR_ASM_INFO_WAIT,
    //    MMI_UMMS_APP_DTMGR_MSG_PARSE_DATA_WAIT,
    //    MMI_UMMS_APP_DTMGR_MSG_PARSE_DRM_WAIT,
    MMI_UMMS_APP_DTMGR_MSG_DATA_READY,
    MMI_UMMS_APP_DTMGR_USE_DETAIL_START,
    MMI_UMMS_APP_DTMGR_USE_DETAIL_NUMBER,
    MMI_UMMS_APP_DTMGR_USE_DETAIL_EMAIL,
    MMI_UMMS_APP_DTMGR_USE_DETAIL_URL,
    MMI_UMMS_APP_DTMGR_USE_DETAIL_SORT,
    MMI_UMMS_APP_DTMGR_TOTAL
} mmi_umms_app_dtmgr_state_enum;

typedef struct
{
    void *data; /* data will be requirement specific */
    U16 req_type;
    U16 uid;
    BOOL is_used;
    mmi_umms_app_dtmgr_state_enum state;
} mmi_umms_app_dtmgr_context;

typedef enum
{
    MMI_UMMS_ADDRESS_TYPE_PHONE_NUMBER,
    MMI_UMMS_ADDRESS_TYPE_EMAIL,
    MMI_UMMS_ADDRESS_TYPE_TOTAL_NUM
} mmi_umms_address_type_enum;

typedef enum
{
    MMI_UMMS_ADDRESS_GROUP_TYPE_TO,
    MMI_UMMS_ADDRESS_GROUP_TYPE_CC,
    MMI_UMMS_ADDRESS_GROUP_TYPE_BCC,
    MMI_UMMS_ADDRESS_GROUP_TYPE_FROM,
    MMI_UMMS_ADDRESS_GROUP_TYPE_TOTAL_NUM
} mmi_umms_address_group_type_enum;

typedef enum
{
    MMI_UMMS_APP_DTMGR_COMPOSE,
    MMI_UMMS_APP_DTMGR_SENDING,
    MMI_UMMS_APP_DTMGR_RETRIEVAL,
    MMI_UMMS_APP_DTMGR_SETTINGS_TOTAL
} mmi_umms_app_dtmgr_settings_type_enum;

typedef enum
{
    MMI_UMMS_APP_DTMGR_REQ_MSG_INFO = 1,
    MMI_UMMS_APP_DTMGR_REQ_HEADER_INFO,
    MMI_UMMS_APP_DTMGR_REQ_MSG_AND_HEADER_INFO,
    MMI_UMMS_APP_DTMGR_REQ_CONTENT_INFO,
    MMI_UMMS_APP_DTMGR_REQ_VIEWER_INFO,
#ifdef __MMI_MMS_ITERATOR_VIEWER__
    MMI_UMMS_APP_DTMGR_REQ_UM_USER_DATA,
    MMI_UMMS_APP_DTMGR_REQ_OTHER_MSG_INFO,
    MMI_UMMS_APP_DTMGR_REQ_UM_GRP_ID,
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
    MMI_UMMS_APP_DTMGR_REQ_VIEWER_CAT_CONTEXT,
    MMI_UMMS_APP_DTMGR_REQ_VIEWER_TEXT_BUFFERS,
    MMI_UMMS_APP_DTMGR_REQ_GET_MMS_SETTING,
    MMI_UMMS_APP_DTMGR_REQ_GET_TEMPLATE_LIST,
    MMI_UMMS_APP_DTMGR_REQ_GET_USE_DETAILS_LIST,
    MMI_UMMS_APP_DTMGR_REQ_GET_ATTACHMENT_LIST,
    MMI_UMMS_APP_DTMGR_REQ_GET_SLIDE_LIST,
    MMI_UMMS_APP_DTMGR_REQ_CONFIRM_SCRN_DATA,
    MMI_UMMS_APP_DTMGR_REQ_TOTAL
} mmi_umms_app_dtmgr_req_type_enum;

#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__

typedef struct
{
    kal_wchar current_selected_sender_address[MMA_MAX_ADDR_LEN];
    U8 current_selected_sender_address_type;
    mma_folder_enum current_selected_folde_type;
#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
    MMI_BOOL is_hs_active;
    MMI_BOOL is_hs_recent_event_active;
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */ 
} mmi_umms_app_dtmgr_phb_notify_struct;

#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 

typedef struct
{
    U16 scr_id;
    S32 item_index;
    U16 number_of_items;
    gui_iconlist_menu_item *menuData;
} mmi_umms_app_dtmgr_async_data_struct;

typedef struct
{
    U8 result;
    U8 media_type;
    kal_uint8 from_address_type;
    kal_uint8 msg_class;
    /* kal_uint8 msg_status; */
    kal_uint32 msg_size;
    kal_uint32 date;
    kal_uint32 receive_date;
    kal_uint32 expiry_date;
    kal_bool is_read;
    kal_bool need_read_report;
#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
    kal_bool need_delivery_report;
#endif 
    kal_bool is_forward_lock;
    kal_bool isDRM;
    kal_bool is_follow_phone_mms_content_class;
    kal_bool hasAttachment;
    kal_uint8 msg_type;
    kal_uint8 msg_sim_id;
    kal_wchar from_address[MMA_MAX_ADDR_LEN];
    kal_wchar subject[MMA_MAX_SUBJECT_LEN];
    kal_uint8 is_lock_mode;
    kal_uint8 notification_error_type;
    kal_uint8 prev_folder;
    kal_uint8 msg_storage;  /*  0 for phone 1 for card */
    kal_wchar app_id[SRV_MMS_MAX_COMM_STRING_LENGTH];
    kal_wchar reply_app_id[SRV_MMS_MAX_COMM_STRING_LENGTH];
    kal_uint8 priority;
#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
    kal_uint32 user_element_size;
#endif 
} mmi_umms_app_dtmgr_msg_info_data_struct;

typedef struct
{
    srv_mms_addr_struct *to;
    srv_mms_addr_struct *cc;
    srv_mms_addr_struct *bcc;
    srv_mms_addr_struct *from;
    srv_mms_viewer_slide_struct *slide_head;
    srv_mms_viewer_slide_struct *current_slide;
    srv_mms_viewer_object_struct **object_head;
    srv_mms_viewer_attachment_info_struct *attachment_head;
    U32 background_color;
    U32 foreground_color;
    U32 date;
    U32 msgsize;
    U32 download_size;
    U32 reported_msg_id;
    U32 delivery_time;  /* mma_delivery_time_enum + java uses it for time in secs */
    U8 java_app_id[100 *ENCODING_LENGTH];
    U8 java_reply_app_id[100 *ENCODING_LENGTH];

    U16 subject[SRV_MMS_XML_MAX_SUBJECT_LEN + 1];
    U16 reported_subject[SRV_MMS_XML_MAX_SUBJECT_LEN + 1];
    U16 slide_timing;
    U16 email_num;
    U16 ph_num;
    U8 mms_version[SRV_MMS_VERSION_LEN];
    U8 to_num;
    U8 cc_num;
    U8 bcc_num;
    U8 priority;    /* mma_priority_enum */
    U8 expiry_time; /* mma_expiry_time_enum */
    U8 msgStatus;   /* mma_msg_status_enum */
    U8 msgclass;    /* mma_msg_class_enum */
    U8 total_slide_num;
    U8 current_slide_num;
    U8 total_object_num;
    U8 total_attachment_num;
    U8 total_addresses;
    U8 status;
    BOOL sender_visibility;
    BOOL read_report;
    BOOL delivery_report;
    /* mma_slide_layout_enum */ U8 layout;
} mmi_umms_app_dtmgr_xml_header_info_struct;

typedef enum
{
    UMMS_FROM,
    UMMS_TO_LIST,
    UMMS_CC_LIST,
    UMMS_BCC_LIST,
    UMMS_ADDR_LIST_TOTAL
} umms_addr_list_enum;

typedef struct
{
#ifdef __MMI_MMS_NOT_ALLOW_USER_DOWNLOAD_CORRUPTED_MMS_MSG__
    U8 download_rsp_result;
#endif 
    U8 uc_mode;
    U8 is_preview;
    U8 set_read_mark;
    U16 *xml_file_path;
    U32 msg_id;
    BOOL is_already_viewed;
    U8 action;
    mma_folder_enum folder_id;
    mmi_umms_app_dtmgr_xml_header_info_struct *header_info;
    mmi_umms_app_dtmgr_msg_info_data_struct *msg_info;
    srv_mms_bgsr_msg_info_struct *bgsr_msg_info;
#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
    wap_mma_mms_msg_report_status_struct *status_list;
#endif 
    U8 *msg_path;
    U8 *file_path;
} mmi_umms_app_dtmgr_option_scr_data_struct;

typedef struct
{
    S32 start_index;
    S32 end_index;
    S32 total_items;
    void *data;
} mmi_umms_app_dtmgr_async_data_rsp_struct;

typedef struct
{
    mmi_umms_app_dtmgr_async_data_struct dt_cntx;
    U8 type_usedetail;
} mmi_umms_app_dtmgr_use_detail_data_struct;
typedef struct
{
    KAL_ADM_ID adm_pool_id;
    MMI_BOOL asm_result;
} mmi_umms_app_dtmgr_asm_context;

typedef struct
{
    U16 req_type;
    /* U32 msg_id; */
} mmi_umms_app_dtmgr_ready_check;

typedef struct
{
    srv_mms_viewer_xml_msg_struct *msg_cntx;
    PU8 slide_txt_buffer;   /* final buffer with UCS2 encoding */
    PU8 src_buffer;         /* buffer with source encoding */
    PU8 inputbox_buffer;
    U32 ptxtbuffersize;

} mmi_umms_app_dtmgr_viewer_cateory_info_data;

typedef struct
{
    //U16 *xml_file_path;
    //mmi_umms_app_dtmgr_viewer_cateory_info_data *cat_info;
    srv_mms_viewer_use_details_list *list_head;
    U16 shown_slide_num;
} mmi_umms_app_dtmgr_viewer_info_data;

typedef struct
{
    /* mmi_umms_templates_type_enum */ U8 msg_box_type;
    srv_um_msg_info_struct *msg_info;
} mmi_umms_app_dtmgr_template_info_data;

/* MMS Setting related data managerment */
typedef struct
{
    U16 scr_id;
    mmi_umms_app_dtmgr_settings_type_enum setting_type;
} mmi_umms_app_dtmgr_settings_req_struct;

   /* context structures for data manager */

typedef struct
{
    U8 applib_addr_type;
    srv_mms_get_use_details_enum mms_umms_app_slide;
    S8 *hilited_data;
    S32 hilite_index;
#ifdef __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__
    S32 curr_index;
    MMI_BOOL is_more;
#endif /* __MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__ */ 
    srv_mms_get_use_details_rsp_struct get_use_details_rsp;
} mmi_umms_app_dtmgr_use_details_struct;

typedef enum
{
    UMMS_DTMGR_DATA_TYPE_ANSII,
    UMMS_DTMGR_DATA_TYPE_UCS2,
    UMMS_DTMGR_TOTAL_DATA_TYPES
} umms_dtmgr_data_type_enum;

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
/* extern S32 mmi_umms_app_dtmgr_get_hilighted_items(void); */
extern void mmi_umms_app_dtmgr_set_add_to_recipient(MMI_BOOL temp);
extern void mmi_umms_app_dtmgr_set_add_cc_recipient(MMI_BOOL temp);
extern void mmi_umms_app_dtmgr_set_add_bcc_recipient(MMI_BOOL temp);
extern void mmi_umms_app_dtmgr_set_hilite_item(S32 temp);
extern S32 mmi_umms_app_dtmgr_get_hilite_item(void);
extern S32 mmi_umms_app_dtmgr_get_recipient_list_aysnc(S32 item_index, gui_iconlist_menu_item *menuData, S32 num_item);

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_save_msg_info(void *msgrsp);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_check_use_details_ready(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_use_details_ready(U16 scr_id);
extern void mmi_umms_app_dtmgr_get_use_details_list_cb(void *msgrsp);
extern S32 mmi_umms_app_dtmgr_get_use_details_aysnc(S32 item_index, gui_iconlist_menu_item *menuData, S32 num_item);
extern S32 mmi_umms_app_dtmgr_get_use_details_total_items(void);


extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_reset_use_details_list_data(U16 scr_id);

//extern U32 mmi_umms_app_dtmgr_get_total_slides(void);
//extern U16 mmi_umms_app_dtmgr_get_current_slide_num(void);

extern void mmi_umms_app_dtmgr_set_infinite_popup_screen_para(U16 *string_id, U16 image_id, U16 tone_id);

extern void *mmi_umms_app_dtmgr_get_popup_screen_data(void);

extern void *mmi_umms_app_dtmgr_get_data(U8 req_type);
extern void mmi_umms_app_dtmgr_reset_template_list_data(void);
extern void mmi_umms_app_dtmgr_set_current_message_index(S32 index);
extern void mmi_umms_app_dtmgr_set_attachment_list_hilighted_item(S32 index);
extern void mmi_umms_app_dtmgr_delete_viewer_data(U16 scr_id);

/******************************************************************************/
extern srv_mms_viewer_use_details_list *mmi_umms_app_dtmgr_get_use_details_for_viewer(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_user_template_dynamic_list_data(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_template_data_ready_check(U16 scr_id);

extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_template_menu_static_data(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_template_menu_data_ready_check(U16 scr_id);

extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_check_viewer_scr_data_ready(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_viewer_data_ready(U16 scr_id);

/* extern mmi_umms_app_dtmgr_option_scr_data_struct* mmi_umms_app_dtmgr_get_data_for_scr(U16 scr_id); */
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_option_scr_info_int(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_check_option_scr_data_ready(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_option_scr_sync_data(
                        mmi_umms_app_dtmgr_option_scr_data_struct *data,
                        MMI_BOOL is_viewer_flow,
                        void *success_cb);

extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_progress_data(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_progress_ready_check(U16 scr_id);

/* update state of data manager */
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_update_state(void *data, U16 req_type, U8 new_state);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_data_check(U16 scr_id);
extern mmi_umms_app_dtmgr_option_scr_data_struct *mmi_umms_app_dtmgr_get_msg_info_int(
                                                    mmi_umms_app_dtmgr_ready_check *indata);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_viewer_data_check(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_viewer_data_ready(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_settings_ready_check(mmi_umms_app_dtmgr_settings_req_struct *setting_req);
extern void *mmi_umms_app_dtmgr_get_settings(mmi_umms_app_dtmgr_settings_req_struct *setting_req);

/* below will be changed */
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_template_list(mmi_umms_app_dtmgr_async_data_struct *async_data);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_async_data_use_details(mmi_umms_app_dtmgr_async_data_struct *async_data);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_async_data_slide_list(mmi_umms_app_dtmgr_async_data_struct *async_data);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_async_data_attachment_list(
                        mmi_umms_app_dtmgr_async_data_struct *async_data);
extern S32 mmi_umms_app_dtmgr_get_async_total_number(U16 scr_id);

extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_set_confirm_screen_data(void *cfrm_data);
extern void *mmi_umms_app_dtmgr_get_confirm_screen_data(void);

extern void mmi_umms_app_dtmgr_get_option_scr_info_cb(srv_mms_result_enum result, void *msgrsp, S32 user_data);
extern void mmi_umms_app_dtmgr_get_viewer_data_ready_cb(srv_mms_result_enum result, void *msgrsp, void *user_data);

extern mmi_umms_app_dtmgr_context *mmi_umms_app_dtmgr_get_current_cntx_from_uid(U16 uid);
extern mmi_umms_app_dtmgr_context *mmi_umms_app_dtmgr_get_current_cntx(U16 scr_id);

#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
extern void mmi_umms_app_dtmgr_set_data_for_phb_notify(void);
extern mmi_umms_app_dtmgr_phb_notify_struct *mmi_umms_app_dtmgr_get_data_for_phb_notify(void);
#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 

/* Amitesh for progress */

/* */

//extern void mmi_umms_app_core_set_setting_rsp_cb(U8 result, void *rsp_data, S32 user_data);
//extern void mmi_umms_app_core_get_list_info_cb(U8 result, void *rsp_data, S32 user_data);
extern void mmi_umms_app_core_get_template_msg_info_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data);
extern void mmi_umms_app_dtmgr_set_get_list_info_rsp_data(void *msg);
extern void *mmi_umms_app_dtmgr_get_template_scr_info_int(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_check_template_scr_data_ready(U16 scr_id);
extern S32 mmi_umms_get_um_list_info_rsp(S32 pid, srv_um_get_msg_list_result *rsp, S32 para);

extern void mmi_umms_app_template_get_msg_info(U8 msg_number, U16 msg_box_type);

/* extern void mmi_umms_app_core_get_template_delete_all_cb(U8 result, void *rsp_data, S32 user_data); */

extern void mmi_umms_app_core_get_create_template_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data);
extern void mmi_umms_app_core_get_template_save_cb(srv_mms_result_enum result, void *rsp_data, S32 user_data);
extern void mmi_umms_app_dtmgr_reset_data(void);

/**************************amit added for save objects*************************************/

/*********************************amit ends here for save objects****************************/
/********************************************************************************************/

/* amit adeed for templates here *********************************************************** */

/* amit added for template ********************************************************** */
#define MAX_PREDEFINED_TEMPLATE  5
#define MAX_USERDEF_TEMPLATE 5
#define UMMS_MMI_MAX_SUBJECT_LEN (40)

typedef enum
{
    MMI_UMMS_DEFAULT_TYPE,
    MMI_UMMS_USER_DEFINED_TYPE,
    MMI_UMMS_TYPE_NONE
} mmi_umms_templates_type_enum;

#ifdef MMS_IN_LARGE_STORAGE
#define UMMS_MMI_MAKE_MMS_TEMPLATE_XML_FILE_PATH(x, d)   \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\Template\\template.xml",/* SRV_FMGR_PUBLIC_DRV */SRV_FMGR_PUBLIC_DRV);
#else /* MMS_IN_LARGE_STORAGE */ 
#define UMMS_MMI_MAKE_MMS_TEMPLATE_XML_FILE_PATH(x, d)   \
   kal_wsprintf( (kal_uint16 *)x, "%c:\\Template\\template.xml",/* SRV_FMGR_SYSTEM_DRV */SRV_FMGR_SYSTEM_DRV);
#endif /* MMS_IN_LARGE_STORAGE */ 




typedef struct
{

    U8 file_path[(MMA_MAX_INTERNAL_FILENAME_LENGTH + 1) *ENCODING_LENGTH];
    U8 buffer_index;
    mmi_umms_templates_type_enum template_type;
    FS_HANDLE file_handle;
    U8 *msg_path;
    U32 request_id;
    U32 xml_file_size;
    U32 msg_id;
    S32 current_msg_index;

} mmi_umms_app_dtmgr_create_mms_struct; /* common for default and userdef */

typedef struct
{
    U8 delete_and_stop;
    MMI_BOOL default_creation_progress;
} mmi_umms_app_dtmgr_template_state_struct;

typedef struct
{
    U16 strId;
    U16 imageId;
    U16 audioId;
} mmi_umms_template_info_struct;

/* memory card */

/* memory card */
extern void mmi_umms_app_dtmgr_default_template_list_info_req(void);
extern void mmi_umms_app_dtmgr_send_create_template_req(void);
extern void mmi_umms_app_dtmgr_delete_all_default_template(void);
extern void mmi_umms_app_ui_plug_in_reset_template_msg(void);
extern void mmi_umms_app_ui_plug_in_get_template_resource(void);
extern U8 mmi_umms_app_ui_plug_in_start_generate_template_xml(
            const S8 *subject,
            const U16 image_id,
            const U8 *audio_buff,
            const U32 audio_len);
/* extern void mmi_ummsapp_ui_plug_in_reset_template_msg(void); */
extern void mmi_umms_app_ui_plug_in_set_template_create_file_handle(FS_HANDLE handle);
extern void mmi_umms_app_ui_plug_in_close_template_create_file_handle(void);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_user_template_scr_info_int(U16 scr_id);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_get_default_template_scr_info_int(U16 scr_id);
extern MMI_BOOL mmi_umms_app_dtmgr_check_template_count(void);
extern S32 mmi_umms_app_dtmgr_init_template_folder(MMI_BOOL is_bootup);
extern void mmi_umms_app_dtmgr_handle_template_create_rsp(void *rsp_data);
extern void mmi_umms_app_dtmgr_handle_template_save_rsp(void *rsp_data);

extern void mmi_umms_app_dtmgr_set_template_msg_info(void *rsp_data);
extern void mmi_umm_app_dtmgr_handle_delete_all_response(void);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_check_use_details_for_viewer(U16 scr_id);

extern U8 mmi_umms_app_dtmgr_get_template_count(void);
extern mmi_umms_templates_type_enum mmi_umms_app_dtmgr_get_current_template_type(void);
extern U16 mmi_umms_app_dtmgr_get_template_list_csk_icon_id(void);
extern U32 mmi_umms_app_dtmgr_get_current_hilighted_msg_id(void);
extern void mmi_umms_app_dtmgr_reset_data_for_phb_notify(void);
extern S8 *mmi_umms_app_dtmgr_get_use_details_string(void);
extern void mmi_umms_app_dtmgr_free_data(U8 req_type);
extern U16 mmi_umms_app_dtmgr_change_use_detail_title(void);
extern void mmi_umms_app_dtmgr_update_read_status(U32 msg_id, MMI_BOOL read_status);

extern void mmi_umms_app_dtmgr_reset_template_state_on_end_key(void);
extern void mmi_umms_app_dtmgr_set_template_delete_and_stop_handling(U8 flag);
extern U8 mmi_umms_app_dtmgr_get_template_delete_and_stop_handling(void);
extern void mmi_umms_app_dtmgr_reset_template_msg(void);
extern void mmi_umms_app_dtmgr_set_template_default_creation_progress_check(U8 flag);
extern U8 mmi_umms_app_dtmgr_get_template_default_creation_progress_check(void);
extern MMI_RET mmi_umms_app_dtmgr_set_userdef_template_del_from_phone_suite_flag(mmi_event_struct *);
extern void mmi_umms_app_dtmgr_reset_userdef_template_del_from_phone_suite_flag(void);
extern U8 mmi_umms_app_dtmgr_get_userdef_template_del_from_phone_suite_flag(void);
extern void mmi_umms_app_dtmgr_deinit_viewer_service_through_dtmgr(void);
extern void mmi_umms_app_dtmgr_app_timer_expire(void);
extern void mmi_umms_app_dtmgr_viewer_timer_expire(void);
extern void mmi_umms_app_dtmgr_set_phone_book_cui_id(U16 phb_cui_id);
extern U16 mmi_umms_app_dtmgr_get_phone_book_cui_id(void);
extern void mmi_umms_app_dtmgr_set_bookmark_cui_id(U16 phb_cui_id);
extern U16 mmi_umms_app_dtmgr_get_bookmark_cui_id(void);
extern void mmi_umms_dtmgr_update_for_option(mmi_umms_app_start_struct *data, U16 scr_id, U8 new_state);
extern void mmi_umms_dtmgr_update_for_viewer(mmi_umms_app_start_struct *data, U16 scr_id, U8 new_state);
extern U16 mmi_umms_app_dtmgr_prop_convert_umbox_type_to_mma_folder(U16 um_box_type);
extern S32 mmi_umms_app_dtmgr_get_current_message_index(void);
extern U16 mmi_umms_app_dtmgr_get_use_details_list_no_data_string(void);
extern MMI_BOOL mmi_umms_app_dtmgr_state_asm_waiting(void);

#ifdef __MMI_MMS_ITERATOR_VIEWER__
extern U32 mmi_umms_app_dtmgr_get_msg_id_by_index(U16 index);
extern void mmi_umms_app_dtmgr_handle_action_on_curr_msg(
                mmi_um_iter_viewer_result_struct other_msg_data,
                U8 folder_id,
                void *user_data,
                mmi_id parent_id);
extern MMI_BOOL mmi_umms_app_dtmgr_update_indexing_data_from_um(mmi_event_struct *param);
extern void mmi_umms_app_dtmgr_set_iterator_status(MMI_BOOL is_active);
extern MMI_BOOL mmi_umms_app_dtmgr_get_iterator_status(void);
extern void mmi_umms_app_dtmgr_refresh_templates(void);
extern void mmi_umms_app_dtmgr_set_refresh_flag(MMI_BOOL flag);
extern MMI_BOOL mmi_umms_app_dtmgr_get_refresh_flag(void);
extern void mmi_umms_app_dtmgr_set_um_data(void *user_data);
extern void *mmi_umms_app_dtmgr_get_um_data(void);
#endif /* __MMI_MMS_ITERATOR_VIEWER__ */ 
extern MMI_BOOL mmi_umms_app_dtmgr_add_node_to_addr_list(
                    srv_mms_addr_struct **list,
                    srv_mms_msg_addr_info_struct *node);
extern void mmi_umms_app_dtmgr_forward_option_scrn_data(S32 result, U32 user_data);
extern void mmi_umms_app_dtmgr_forward_viewer_option_scrn_data(S32 result, void *user_data);

/*****************************************************************************************/
/*****************************************************************************************/
/* memory card  */
//extern void mmi_umms_app_dtmgr_set_prefered_storage(U8 prefStorage, BOOL flag);
//extern U8 mmi_umms_app_dtmgr_get_prefered_storage(void);
/* memory card */

#ifdef __MMI_MMS_REPORT_STATUS_MENU_SUPPORT__
extern void mmi_umms_app_dtmgr_reset_status_data(wap_mma_mms_msg_report_status_struct *status_list);
#endif 
extern S32 *mmi_umms_app_dtmgr_get_parent_file_hdl(void);

#if(MMI_MAX_SIM_NUM >= 3)
/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_sim_sel_cui_id
 * DESCRIPTION
 *  get the global cui id value
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
extern void mmi_umms_app_dtmgr_set_sim_sel_cui_id(U16 cui_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_umms_app_dtmgr_set_sim_sel_cui_id
 * DESCRIPTION
 *  get the global cui id value
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
extern U16 mmi_umms_app_dtmgr_get_sim_sel_cui_id(void);
#endif /* (MMI_MAX_SIM_NUM >= 3) */ 
#endif /* defined (__MMI_MMS_2__) && !defined(__MMI_MMS_SIMPLIFIED_UI_SUPPORT__) */ 
#ifdef __MMI_MMS_2__
/* amit added for settings******************************************************** */
#include "UMGProt.h"
// #include "App_usedetails.h"
#include "MmsSrvGprot.h"
#include "MMSAppInterfaceGProt.h"
#include "inlineCuiGprot.h"
#include "wap_adp.h"
#include "MMIDataType.h"
#include "mma_struct.h"
#include "mma_api.h"
#include "gui_typedef.h"
#include "MmsXMLDefSrv.h"
#include "wgui_categories_MMS_viewer.h"
#include "kal_public_defs.h"
#include "UmSrvDefs.h"
#include "MMSAppUICommon.h"
#include "FileMgrSrvGProt.h"
#include "MMI_features_switch.h"
#include "MMI_features_type.h"
#include "UmSrvGprot.h"
#include "fs_type.h"
#include "kal_general_types.h"

/* amit added for settings******************************************************** */

#ifndef __MMI_MMS_OMA_CONF_273__
#define __MMI_MMS_OMA_CONF_273__
#endif 

#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
#define UMMS_IMAGE_SIZE_CHECK          (300*1024)
#endif 
#define __MMI_MMS_2_CREATION_MODE_WARNING_SUPPORT__
#define UMMS_POPUP_TIME    UI_POPUP_NOTIFYDURATION_TIME_2000
#define UMMS_SIGNATURE_OBJECTS         3

#define UMMS_MAX_NO_PAGES_INPUT          2
#define  UMMS_MAX_DEFAULT_SLIDE_TIME_INPUT  2

#define  UMMS_MAX_DEADLINE_TIME_VALUE_INPUT 2
#define  UMMS_MAX_REPLY_CHARGE_SIZE_INPUT      3
#define  UMMS_MAX_FILTER_MSG_SIZE_INPUT     3
#define UMMS_MMI_INPROGRESS_TIME_OUT        (1000*(60*2))
#define UMMS_MEMORY_STATUS_TEMP_BUF       (20)
#define UMMS_MEMORY_STATUS_MAX_LENGTH     (106)
#define UMMS_GOBACK_ONE_LEVEL       1

#define UMMS_COMPOSE_SIGNATURE_IMAGE_ADDED   0x01
#define UMMS_COMPOSE_SIGNATURE_AUDIO_ADDED   0x02
#define UMMS_COMPOSE_SIGNATURE_VIDEO_ADDED   0x04
#define UMMS_COMPOSE_SIGNATURE_TEXT_ADDED 0x08
#define UMMS_COMPOSE_SIGNATURE_AUDIO_DAF_ADDED  0x10

typedef enum
{
    AUDIO_EXT = 0,
    IMAGE_EXT,
    VIDEO_EXT,
    TOTAL_EXT
} umms_object_ext;

typedef enum
{
    E_USE_NVRAM_SETTINGS = 1,
    E_USE_LOCAL_SETTINGS,
    E_USE_TOTAL
} umms_use_settings_enum;

typedef enum
{
    E_SET_VALIDITY_PERIOD_MAX,
    E_SET_VALIDITY_PERIOD_1HR,
#ifndef __MMI_OP12_MMS_SUPPORT_SETTINGS__
    E_SET_VALIDITY_PERIOD_6HRS,
#endif 
    E_SET_VALIDITY_PERIOD_12HRS,
    E_SET_VALIDITY_PERIOD_1DAY,
    E_SET_VALIDITY_PERIOD_1WEEK,
    SET_VALIDITY_PERIOD_TOTAL
} umms_validity_period_enum;

typedef enum
{
    E_SET_CREAT_MODE_RESTRICTED,
    E_SET_CREAT_MODE_FREE,
#ifdef __MMI_MMS_2_CREATION_MODE_WARNING_SUPPORT__
    E_SET_CREAT_MODE_WARNING,
#endif 
    SET_CREATION_MODES_TOTAL
} umms_creation_modes_enum;

typedef enum
{
    E_SET_IMMEDIATE,
    E_SET_1_HR,
    E_SET_12_HRS,
    E_SET_24_HRS,
    DELIEVERY_TOTAL
} umms_delievery_time_enum;

typedef struct
{
    S8 *allow_reject_list[2];
    S8 *on_off_list[2];
} mmi_umms_app_dtmgr_common_inline_lists_struct;

typedef enum
{
#ifdef __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__
    E_SENDING_VALIDITY_PERIOD_CAPTION = CUI_INLINE_ITEM_ID_BASE,
    E_SENDING_VALIDITY_PERIOD,
    E_SENDING_DELIVERY_REPORT_CAPTION,
#else /* __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__ */ 
    E_SENDING_DELIVERY_REPORT_CAPTION = CUI_INLINE_ITEM_ID_BASE,
#endif /* __MMI_MMS_SETTINGS_VALIDITY_PERIOD_VISIBILITY__ */ 
    E_SENDING_DELIVERY_REPORT,
    E_SENDING_READ_REPORT_CAPTION,
    E_SENDING_READ_REPORT,
    E_SENDING_PRIORITY_CAPTION,
    E_SENDING_PRIORITY,
    E_SENDING_DELIVERY_TIME_CAPTION,
    E_SENDING_DELIVERY_TIME,
#ifdef __MMI_MMS_HIDE_SENDER_SUPPORT__
    E_SENDING_HIDE_SENDER_CAPTION,
    E_SENDING_HIDE_SENDER,
#endif /* __MMI_MMS_HIDE_SENDER_SUPPORT__ */ 

    E_SENDING_SEND_AND_SAVE_CAPTION,
    E_SENDING_SEND_AND_SAVE,

#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
    E_SENDING_SIZE_LIMIT_CAPTION,
    E_SENDING_SIZE_LIMIT,
#endif /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 
    SENDING_INLINE_TOTAL
} umms_sending_inline_items_enum;

typedef enum
{
    E_SENDING_REPLY_CHARGING_REQUEST_TYPE_CAPTION,
    E_SENDING_REPLY_CHARGING_REQUEST_TYPE,
    E_SENDING_REPLY_CHARGING_DEADLINE_CAPTION,
    E_SENDING_REPLY_CHARGING_DEADLINE,
    E_SENDING_REPLY_CHARGING_SIZE_CAPTION,
    E_SENDING_REPLY_CHARGING_SIZE,
    SENDING_REPLY_CHARGING_INLINE_TOTAL
} umms_sending_reply_charging_inline_items_enum;

typedef enum
{

    E_RETRIEVAL_HOME_NETWORK_CAPTION = CUI_INLINE_ITEM_ID_BASE,
    E_RETRIEVAL_HOME_NETWORK,
    E_RETRIEVAL_ROAMING_CAPTION,
    E_RETRIEVAL_ROAMING,

    E_RETRIEVAL_FILTERS_CAPTION,
    E_RETRIEVAL_READ_REPORT_CAPTION,
    E_RETRIEVAL_READ_REPORT,
    E_RETRIEVAL_DELIVERY_REPORT_CAPTION,
    E_RETRIEVAL_DELIVERY_REPORT,

    RETRIEVAL_INLINE_TOTAL
} umms_retrieval_inline_items_enum;

typedef enum
{
    E_RETRIEVAL_FILTERS_ANONYMOUS_CAPTION = CUI_INLINE_ITEM_ID_BASE,
    E_RETRIEVAL_FILTERS_ANONYMOUS,
#ifndef __MMI_MMS_OMA_CONF_273__
    E_RETRIEVAL_FILTERS_MAX_MSG_SIZE_CAPTION,
    E_RETRIEVAL_FILTERS_MAX_MSG_SIZE,
#endif /* __MMI_MMS_OMA_CONF_273__ */ 
    E_RETRIEVAL_FILTERS_ADVERTISEMENT_CAPTION,
    E_RETRIEVAL_FILTERS_ADVERTISEMENT,
    RETRIEVAL_FILTER_INLINE_TOTAL
} umms_retrieval_filters_inline_items_enum;

typedef enum
{
    E_COMPOSE_SIGNATURE_TEXT_CAPTION = CUI_INLINE_ITEM_ID_BASE,
    E_COMPOSE_SIGNATURE_TEXT,
#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
    E_COMPOSE_SIGNATURE_IMAGE_CAPTION,
    E_COMPOSE_SIGNATURE_IMAGE,
#endif /* __MMI_MMS_UMMS_IMAGE_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
    E_COMPOSE_SIGNATURE_VIDEO_CAPTION,
    E_COMPOSE_SIGNATURE_VIDEO,
#endif /* __MMI_MMS_UMMS_VIDEO_FEATURE__ */ 
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
    E_COMPOSE_SIGNATURE_AUDIO_CAPTION,
    E_COMPOSE_SIGNATURE_AUDIO,
#endif /* __MMI_MMS_UMMS_AUDIO_FEATURE__ */ 
    COMPOSE_SIGNATURE_INLINE_TOTAL
} umms_compose_signature_inline_items_enum;

typedef enum
{
    E_COMPOSE_DEFAULT_SLIDE_TIME_CAPTION = CUI_INLINE_ITEM_ID_BASE,
    E_COMPOSE_DEFAULT_SLIDE_TIME,
#ifdef __LAYOUT_SUPPORT__
    E_COMPOSE_LAYOUT_CAPTION,
    E_COMPOSE_LAYOUT,
#endif /* __LAYOUT_SUPPORT__ */ 
#ifdef __DRM_SUPPORT__
#ifdef __UMMS_DRM_SUPPORT__
    E_COMPOSE_ADD_DRM_CAPTION,
    E_COMPOSE_ADD_DRM,
#endif /* __UMMS_DRM_SUPPORT__ */ 
#endif /* __DRM_SUPPORT__ */ 
    E_COMPOSE_CREATION_MODES_CAPTION,
    E_COMPOSE_CREATION_MODES,
#ifdef __MMI_MMS_MEGA_PIXEL_SUPPORT__
    E_COMPOSE_IMAGE_RESIZE_CAPTION,
    E_COMPOSE_IMAGE_RESIZING,
#endif /* __MMI_MMS_MEGA_PIXEL_SUPPORT__ */ 
#ifdef __MAX_PAGE_SUPPORTED__
    E_COMPOSE_MAX_NO_PAGES_CAPTION,
    E_COMPOSE_MAX_NO_PAGES,
#endif /* __MAX_PAGE_SUPPORTED__ */ 
#ifdef __MMI_MMS_BEST_PAGE_UISETTING_OPTION_SUPPORT__
    E_COMPOSE_BEST_PAGE_DURATION_CAPTION,
    E_COMPOSE_BEST_PAGE_DURATION,
#endif /* __MMI_MMS_BEST_PAGE_UISETTING_OPTION_SUPPORT__ */ 
    /* PMT VIKAS START 20060403 */
#ifdef __MMI_MMS_SIGNATURE__
    E_COMPOSE_AUTO_SIGNATURE_CAPTION,
    E_COMPOSE_AUTO_SIGNATURE,
    E_COMPOSE_AUTO_SIGNATURE_CONTENT,
#endif /* __MMI_MMS_SIGNATURE__ */ 
    /* PMT VIKAS END 20060403 */
    COMPOSE_INLINE_TOTAL
} umms_compose_inline_items_enum;

typedef struct
{
    S32 home_network;
    S32 roaming;
    S32 anonymous_filter;
    S32 advertisement_filter;
    S32 read_report;
    S32 delivery_report;

#if defined(__MMI_OP12_MMS_SUPPORT_SETTINGS__)
    S8 *home_network_list[2];
#else 
    S8 *home_network_list[HOME_NETWORK_TOTAL - 1];
#endif 
    S8 *roaming_list[ROAMING_TOTAL];
    S8 *read_report_list[READ_REPORT_SEND_TOTAL];
    /* U8 msg_size_filter_buffer[(UMMS_MAX_FILTER_MSG_SIZE_INPUT + 1) *ENCODING_LENGTH]; */
} umms_inline_retrieval_items_struct;

typedef struct
{
    /* /new */
    S32 validity_period;
    S32 delivery_report;
    S32 read_report;
    S32 priority;
    S32 delivery_time;
    S32 reply_charging;
    S32 request_type;
    S32 hide_sender;
    S32 send_and_save;
    S32 size;
    S8 *validity_period_list[VALIDITY_PERIOD_TOTAL];
    S8 *priority_list[PRIORITY_TOTAL];
    S8 *delivery_time_list[DELIEVERY_TOTAL];
    S8 *reply_charging_request_list[REPLY_CHARGING_TYPE_TOTAL];
    S8 *sending_size_limit_list[SENDING_SIZE_LIMIT_TOTAL];
    U8 deadline_for_reply_buffer[(UMMS_MAX_DEADLINE_TIME_VALUE_INPUT + 1) *ENCODING_LENGTH];
    U8 reply_msg_size_buffer[(UMMS_MAX_REPLY_CHARGE_SIZE_INPUT + 1) *ENCODING_LENGTH];

} umms_inline_sending_items_struct;
typedef struct
{
    S32 layout;
#ifdef __DRM_SUPPORT__
    S32 add_drm;
#endif 
    S32 creation_mode;
    S32 image_resize_option;
    S32 best_page_duration;

    S8 *layout_list[LAYOUT_TOTAL];
    S8 *creation_modes_list[SET_CREATION_MODES_TOTAL];
    S8 *image_resize_list[IMAGE_RESIZE_TOTAL];
    U8 max_num_pages_buffer[(UMMS_MAX_NO_PAGES_INPUT + 1) *ENCODING_LENGTH];
    U8 defualt_slide_time_buffer[(UMMS_MAX_DEFAULT_SLIDE_TIME_INPUT + 1) *ENCODING_LENGTH];
    U8 auto_signature_content[(UMMS_MAX_AUTO_SIGN_LENGTH + 1) *ENCODING_LENGTH];
#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
    U8 auto_signature_image_file[(MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) *ENCODING_LENGTH];
#endif 
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
    U8 auto_signature_audio_file[(MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) *ENCODING_LENGTH];
#endif 
#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
    U8 auto_signature_video_file[(MMA_MAX_EXTERNAL_FILE_PATH_LEN + 1) *ENCODING_LENGTH];
#endif 
    /* PMT VIKAS START 20060403 */
#ifdef __MMI_MMS_SIGNATURE__
    S32 auto_signature;
    U8 signature_flag;
    U8 signature_out_class_flag;
#endif /* __MMI_MMS_SIGNATURE__ */ 
    /* PMT VIKAS END 20060403 */
} umms_inline_compose_items_struct;

typedef struct
{
    umms_inline_compose_items_struct compose_items_list;
    umms_inline_sending_items_struct sending_items_list;
    umms_inline_retrieval_items_struct retrieval_items_list;
} umms_setings_inline_items_struct;

typedef struct
{
    umms_setings_inline_items_struct umms_inline_items;
    mmi_umms_app_dtmgr_common_inline_lists_struct *umms_inline_lists;

} mmi_umms_app_dtmgr_inline_settings_struct;

typedef struct
{
    U8 g_compose_signature_done;
    U8 compose_signature_remove_objects_done;
    U16 g_signature_current_highlighted;
} mmi_umms_app_dtmgr_compose_signature_ui_handling_struct;

#if defined(__MMI_MMS_UMMS_VIDEO_FEATURE__) || defined(__MMI_MMS_UMMS_AUDIO_FEATURE__) || defined(__MMI_MMS_UMMS_IMAGE_FEATURE__)
typedef struct
{
#ifdef __MMI_MMS_UMMS_AUDIO_FEATURE__
    S8 *g_disp_buffer_audio;
#endif 
#ifdef __MMI_MMS_UMMS_IMAGE_FEATURE__
    S8 *g_disp_buffer_image;
#endif 
#ifdef __MMI_MMS_UMMS_VIDEO_FEATURE__
    S8 *g_disp_buffer_video;
#endif 
} mmi_umms_app_dtmgr_compose_sig_displaybale_path_struct;
#endif /* defined(__MMI_MMS_UMMS_VIDEO_FEATURE__) || defined(__MMI_MMS_UMMS_AUDIO_FEATURE__) || defined(__MMI_MMS_UMMS_IMAGE_FEATURE__) */ 

#ifdef WAP_SUPPORT
extern void mmi_umms_app_dtmgr_sim_validation(void);
extern U8 mmi_umms_app_dtmgr_get_active_sim(void);
#endif /* WAP_SUPPORT__ */ 
extern void mmi_umms_app_dtmgr_set_inline_compose_settings_to_nvram(void);
extern void mmi_umms_app_dtmgr_set_inline_sending_settings_to_nvram(void);
extern void mmi_umms_app_dtmgr_set_inline_retrieval_settings_to_nvram(void);
extern umms_inline_retrieval_items_struct *mmi_umms_app_dtmgr_get_retrieval_settings_inline_item_list(U8 flag);

/*****************amit added for seignature and settings**********************************/
extern void mmi_umms_app_dtmgr_set_signature_image_disp_path(S8 *path);
extern void mmi_umms_app_dtmgr_set_signature_audio_disp_path(S8 *path);
extern void mmi_umms_app_dtmgr_set_signature_video_disp_path(S8 *path);
extern S8 *mmi_umms_app_dtmgr_get_signature_image_disp_path(void);
extern S8 *mmi_umms_app_dtmgr_get_signature_audio_disp_path(void);
extern S8 *mmi_umms_app_dtmgr_get_signature_video_disp_path(void);
extern void mmi_umms_app_dtmgr_set_recieve_filters_done(U8 flag);
extern U8 mmi_umms_app_dtmgr_get_recieve_filters_done(void);

typedef enum
{
    MMI_UMMS_APP_DTMGR_MSG_STATE_SENDING_OUTBOX,
    MMI_UMMS_APP_DTMGR_MSG_STATE_NOTIFICATION_DOWNLOADING,
    MMI_UMMS_APP_DTMGR_MSG_STATE_NORMAL_MMS_IN_INBOX,
    MMI_UMMS_APP_DTMGR_MSG_STATE_ALL
} mmi_umms_app_dtmgr_msg_state_enum;

#define         UMMS_CONVERT_INDEX                10
#define         TEMP_BUFFER_SIZE                  60
#define         MAX_PROGRESS_STRING_LENGTH       100
#define         MMI_UMMS_MAX_ADDRESSES            30
#define        UMMS_MEMSET_BUFFER_1       6
#define        UMMS_MEMSET_BUFFER_2       4
#define         MMI_UMMS_MAX_URL_LENGTH           WAP_MAX_URL_LENGTH

#define         MMI_UMMS_MAX_POPUP_LENGTH          50

typedef struct
{
    U16 lsk_str_id;     /* String id of LSK */
    U16 lsk_icon_id;    /* Icon id of LSK */
    U16 rsk_str_id;     /* String id of RSK */
    U16 rsk_icon_id;
    U16 message[MMI_UMMS_MAX_POPUP_LENGTH];
    U16 mmi_event;
    MMI_BOOL need_history;
    MMI_BOOL need_csk;
    void (*lsk_handler) (void);
    void (*rsk_handler) (void);
    void (*exit_screen) (void);
    mmi_ret del_scr_handler;
} mmi_umms_app_dtmgr_confrim_screen_struct;
typedef struct
{
    U16 string_id[MMI_UMMS_MAX_POPUP_LENGTH];
    U16 event_type;
} mmi_umms_app_dtmgr_popup_screen_struct;

typedef struct
{
    U16 string_id[MMI_UMMS_MAX_POPUP_LENGTH];
    U16 image_id;
    U16 tone_id;
} mmi_umms_app_dtmgr_infinite_popup_screen_struct;

typedef struct
{
    U16 string[MMI_UMMS_MAX_POPUP_LENGTH];
    U16 event_type;
    void (*success_callback) (void);
    void (*failure_callback) (void);
} mmi_umms_app_dtmgr_callback_popup_screen_struct;

typedef struct
{
    U16 title_str_id;
    U16 display_id;
    /* U16 lsk_icon;
       U16 lsk_str_id;
       U16 rsk_icon;
       U16 rsk_str_id;kal ko */
} mmi_umms_app_dtmgr_progress_scrn_struct;

#ifdef __MMI_MMS_IMAGE_VIEW_ENHANCEMENT__
typedef struct
{
	U8 *mms_image_buff;
	U16 *src_path;
	U32 mms_gdi_handle;
	U32 mms_gdi_dec_handle;
	U32 width_orig;
	U32 height_orig;
	U32 width_final;
	U32 height_final;
	U16 slide_id;
	U16 last_decoded_result;
}mmi_umms_app_dtmgr_image_decode_struct;

 extern mmi_umms_app_dtmgr_image_decode_struct g_umms_viewer_image_decoder_struct;
 extern void mmi_umms_app_dtmgr_gdi_close_decoder(wgui_mv_image_decode_status_enum result, U16 *file_path, MMI_BOOL notify_cat);
 extern void mmi_umms_app_dtmgr_stop_image_decode(void);

#endif

extern umms_inline_compose_items_struct *mmi_umms_app_dtmgr_get_compose_settings_inline_item_list(U8 flag);
extern umms_inline_sending_items_struct *mmi_umms_app_dtmgr_get_sending_settings_inline_item_list(U8 flag);
extern umms_inline_retrieval_items_struct *mmi_umms_app_dtmgr_get_retrieval_settings_inline_item_list(U8 flag);
extern umms_inline_compose_items_struct *mmi_umms_app_dtmgr_get_current_compose_settings_list(void);
extern umms_inline_sending_items_struct *mmi_umms_app_dtmgr_get_current_sending_settings_list(void);
extern umms_inline_retrieval_items_struct *mmi_umms_app_dtmgr_get_current_retrieval_settings_list(void);
extern MMI_RET mmi_umms_app_dtmgr_send_set_settings_to_service(mmi_event_struct *);

/* Screen Group */
#define mmi_umms_dtmgr_set_inline_gid(U16)mmi_umms_app_dtmgr_set_common_cui_id(U16)
#define mmi_umms_app_dtmgr_set_phone_book_cui_id(U16)mmi_umms_app_dtmgr_set_common_cui_id(U16)
#define mmi_umms_dtmgr_set_inline_gid_ext(U16)mmi_umms_app_dtmgr_set_common_cui_id_ext(U16)

#define mmi_umms_dtmgr_get_inline_gid(void)mmi_umms_app_dtmgr_get_common_cui_id(void)
#define mmi_umms_app_dtmgr_get_phone_book_cui_id(void)mmi_umms_app_dtmgr_get_common_cui_id(void)
#define mmi_umms_dtmgr_get_inline_gid_ext(void)mmi_umms_app_dtmgr_get_common_cui_id_ext(void)

extern void mmi_umms_dtmgr_set_group_id(MMI_ID);
extern MMI_ID mmi_umms_dtmgr_get_group_id(void);
extern void mmi_umms_dtmgr_set_group_flag(MMI_BOOL);
extern MMI_BOOL mmi_umms_dtmgr_check_group_flag(void);
void mmi_umms_app_dtmgr_set_fmgr_file_select_cui_id(U16 phb_cui_id);
U16 mmi_umms_app_dtmgr_get_fmgr_file_select_cui_id(void);
extern void mmi_umms_app_dtmgr_set_parent_grp_id(MMI_ID parent_grp_id);
extern MMI_ID mmi_umms_app_dtmgr_get_parent_grp_id(void);
extern void mmi_umms_app_dtmgr_set_um_back_up_id(MMI_ID parent_grp_id);
extern MMI_ID mmi_umms_app_dtmgr_get_um_back_up_id(void);

extern void mmi_umms_dtmgr_set_proc_flag(MMI_BOOL);
extern MMI_BOOL mmi_umms_dtmgr_get_proc_flag(void);
extern void mmi_umms_dtmgr_set_inline_gid(MMI_ID id);
extern MMI_ID mmi_umms_dtmgr_get_inline_gid(void);
extern void mmi_umms_dtmgr_set_inline_gid_ext(MMI_ID id);
extern MMI_ID mmi_umms_dtmgr_get_inline_gid_ext(void);
extern void mmi_umms_dtmgr_set_compose_image_gid(MMI_ID id);
extern MMI_ID mmi_umms_dtmgr_use_compose_image_gid(void);
extern void mmi_umms_app_dtmgr_set_progress_scrn_data(U16 title_str_id, U16 display_id);
extern mmi_umms_app_dtmgr_progress_scrn_struct *mmi_umms_app_dtmgr_get_progress_data(void);
extern MMI_UMMS_ERROR mmi_umms_app_dtmgr_set_confirm_screen_data(void *cfrm_data);
extern void *mmi_umms_app_dtmgr_get_confirm_screen_data(void);
extern void mmi_umms_app_dtmgr_set_common_cui_id(U16 cui_id);
extern U16 mmi_umms_app_dtmgr_get_common_cui_id(void);
extern void mmi_umms_app_dtmgr_set_common_cui_id_ext(U16 cui_id);
extern U16 mmi_umms_app_dtmgr_get_common_cui_id_ext(void);
extern void mmi_umms_app_dtmgr_set_menu_cui_id(U16 cui_id);
extern U16 mmi_umms_app_dtmgr_get_menu_cui_id(void);

extern MMI_BOOL mmi_umms_dtmgr_check_tenplate_group_flag(void);
extern void mmi_umms_dtmgr_set_tenplate_group_flag(kal_bool flag);

/*REMOVED FROM SLIM ONLY DEFINITION*/
extern void mmi_umms_app_dtmgr_set_popup_screen_para(U16 *string_id, U16 event_type);
extern void *mmi_umms_app_dtmgr_get_infinite_popup_screen_data(void);
extern void mmi_umms_app_dtmgr_set_confirm_screen_para(U16 lsk_str_id,  /* String id of LSK */
                                                       U16 lsk_icon_id, /* Icon id of LSK */
                                                       U16 rsk_str_id,  /* String id of RSK */
                                                       U16 rsk_icon_id,
                                                       U16 *message,
                                                       U16 mmi_event,
                                                       MMI_BOOL need_history,
                                                       MMI_BOOL need_csk,
                                                       void (*lsk_handler) (void),
                                                       void (*rsk_handler) (void), void (*exit_screen) (void),
                                                       mmi_ret del_scr_handler);
extern void mmi_umms_app_dtmgr_set_callback_popup_screen_para(U16 *string, U16 event_type,
                                                              void (*success_callback) (void),
                                                              void (*failure_callback) (void));
extern void mmi_umms_app_dtmgr_abort_send_read_report(U32 msg_id);
extern void mmi_umms_app_dtmgr_set_readmark(U32 msg_id, MMI_BOOL read);
extern void mmi_umms_app_dtmgr_send_read_report(U32 msg_id, U8 sim_id, U8 storage_location);
extern U8 mmi_umms_app_dtmgr_get_flag_for_signature_remove_objects(void);
extern void mmi_umms_app_dtmgr_set_change_in_compose_signature(U8 flag);
extern U16 mmi_umms_app_dtmgr_get_current_object_hilighted_in_signature(void);
extern void *mmi_umms_app_dtmgr_get_callback_popup_screen_data(void);
extern void mmi_umms_app_dtmgr_set_flag_for_signature_remove_objects(U8 flag);
extern void mmi_umms_app_dtmgr_set_current_object_hilighted_in_signature(U16 flag);
extern MMI_BOOL mmi_umms_app_dtmgr_check_save_object_count(void);
extern U8 mmi_umms_app_dtmgr_get_change_in_compose_signature(void);

#endif /* __MMI_MMS_2__ */ 

#endif /* MMS_APP_DATA_MGR_H */ 

