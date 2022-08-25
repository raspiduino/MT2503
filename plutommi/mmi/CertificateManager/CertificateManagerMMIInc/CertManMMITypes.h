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
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/
 /*****************************************************************************
 *
 * Filename:
 * ---------
 *  CertManMMITypes.h
 *
 * Project:
 * --------
 * 
 *
 * Description:
 * ------------
 * This file contains constants, enums and structures
 *
 * Author:
 * ------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
************************************************************************************/
#ifdef __PLUTO_MMI_PACKAGE__ 
#ifndef MMI_CERTMAN_TYPES_H
#define MMI_CERTMAN_TYPES_H

#ifdef __CERTMAN_SUPPORT__

#include "InlineCuiGprot.h"
#include "MMIDataType.h"
#include "certman_defs.h"
#include "certman_struct.h"
#include "custpack_certs.h"
#include "CertManMMIGprots.h"
#include "stack_config.h"
#include "kal_general_types.h"
#include "kal_release.h"
#include "nvram_common_defs.h"

#define MMI_CERTMAN_MIN_PASSWORD_LENGTH  0
#define MMI_CERTMAN_MAX_KEY_PURPOSE_LENGTH   50
#define MMI_CERTMAN_MAX_PROTECTION_METHODS 3
#define MMI_CERTMAN_POPUP_DURATION UI_POPUP_NOTIFYDURATION_TIME_2000
#define MMI_CERTMAN_MAX_FIELD_SIZE 256
#define MMI_CERTMAN_QUEUE_LENGTH 5
#define MMI_CERTMAN_OVERHEAD_BUFFER 1024

/* Define whether there should be a must be passed option in OCSP settings*/
//#define __MMI_CERTMAN_OCSP_MUST_BE_PASSED_OPTION__

typedef enum
{
    MMI_CERTMAN_IDLE,
    MMI_CERTMAN_IMPORT,
    MMI_CERTMAN_LAUNCH,
    MMI_CERTMAN_SELECT,
    MMI_CERTMAN_VIEW,
    MMI_CERTMAN_INVALID,
    MMI_CERTMAN_USER_CERT_LIST
} mmi_certman_status_enum;

typedef enum
{
    MMI_CERTMAN_PRIVATE_KEY_IDLE,
    MMI_CERTMAN_PRIVATE_KEY_PWD,
    MMI_CERTMAN_PRIVATE_KEY_CONFIRM
} mmi_certman_priv_key_status_enum;

#ifdef __OCSP_SUPPORT__
typedef enum
{
    MMI_CERTMAN_OCSP_ON,
    MMI_CERTMAN_OCSP_OFF,
#ifdef __MMI_CERTMAN_OCSP_MUST_BE_PASSED_OPTION__
    MMI_CERTMAN_OCSP_MUST_BE_PASSED,
#endif /* __MMI_CERTMAN_OCSP_MUST_BE_PASSED_OPTION__ */
    MMI_CERTMAN_OCSP_END
} mmi_certman_ocsp_status_enum;
#endif /*__OCSP_SUPPORT__*/
/**************************************************************************/
/*****************************IMPORT CERTIFICATES**************************/
/**************************************************************************/

typedef enum
{
    MMI_CERTMAN_IMPORT_IDLE = 0,
    MMI_CERTMAN_IMPORT_CHECK_ENCODING,
    MMI_CERTMAN_IMPORT_GET_DECR_PWD,
    MMI_CERTMAN_IMPORT_PARSING,
    MMI_CERTMAN_IMPORT_DISPLAY_TOTAL_PCERT,
    MMI_CERTMAN_IMPORT_DISPLAY_FILE_INFO,
    MMI_CERTMAN_IMPORT_DETAIL_REQUEST,
    MMI_CERTMAN_IMPORT_DISPLAY,
    MMI_CERTMAN_IMPORT_GET_CERT_INFO,
    MMI_CERTMAN_IMPORT_IMPORT,
    MMI_CERTMAN_IMPORT_SET_KEY_PURPOSE,
    MMI_CERTMAN_IMPORT_END_PARSING
} mmi_certman_import_state_enum;

typedef struct
{
    U16 grp_id;
    U16 title;                    /* title label */
    U16 title_icon;               /* title icon */
    U16 lsk_label;
    U16 lsk_icon;
    U16 rsk_label;
    U16 rsk_icon;
    U16 id;
    U32 input_mode;
    U32 buffer_len;
    U32 input_len;
    U8* buffer;
    void(*submit_fp)(void);
    void (*cancel_fp)(void);
}mmi_certman_fseditor_struct;

typedef struct
{
    cui_inline_struct *inline_struct;
    U16 grp_id;
}mmi_certman_inline_struct;


typedef struct
{
    U8 password[CERTMAN_PASSWORD_SIZE *ENCODING_LENGTH];
    /*Password to allow user to use private key*/
    /*Buffer size = (33*2) so user can enter 32 characters*/
    U8 privatekey_pwd[CERTMAN_PASSWORD_SIZE *ENCODING_LENGTH];
    U8 privatekey_cnf_pwd[CERTMAN_PASSWORD_SIZE *ENCODING_LENGTH];
    U8 certificate_label[CERTMAN_LABEL_SIZE];
    U16 job_id;
    U16 cert_total;
    U16 count;
    U16 num_priv_key;
    U16 num_authority_cert;
    U16 num_user_cert;
    U16 current_state;
    mmi_certman_fseditor_struct* fseditor;
    U32 protection_method;
    U32 cert_ref_ids[CERTMAN_NUM_PARSED_CERT];
    U32 trans_id;
    U32 ext_trans_id;
    U32 cert_group;
    U32 key_purpose;
    U32 key_purpose_all;
    U32 cert_id;
    mmi_id inline_cui_id;
    certman_error_enum file_encoding;
    certman_ctx_parse_struct *ctx_parse_p;
    certman_ctx_import_struct *ctx_import_p;
    certman_parsed_data_struct *parsed_data_p;
} mmi_certman_import_context_struct;

/**************************************************************************/
/*****************************LAUNCH / SELECT CERTIFICATES*****************/
/**************************************************************************/
typedef enum
{
    MMI_CERTMAN_LAUNCH_SELECT_IDLE = 0,
    MMI_CERTMAN_LAUNCH_SELECT_GROUP_REQ,
    MMI_CERTMAN_LAUNCH_SELECT_CREATE_LIST,
    MMI_CERTMAN_LAUNCH_SELECT_DISPLAY_LIST,
    MMI_CERTMAN_LAUNCH_SELECT_VIEW_CERT
} mmi_certman_launch_select_state_enum;

typedef struct
{
    U32 cert_id;
    U32 cert_prop;
    U32 cert_group;
    U32 key_purpose;
    U32 certificate_dcs;
    U32 key_purpose_change;
    U32 key_purpose_all;
    U8 cert_label[CERTMAN_LABEL_SIZE];
} mmi_certman_certificate_list_struct;

typedef struct
{
    U32 count;
    U32 *cert_ids;
} mmi_certman_certificate_ids_struct;

typedef struct
{
    U16 job_id;
    U16 selected_index;
    U16 current_state;
    U32 key_type;
    U32 trans_id;
    U32 cert_group;
    S32 multiple_selection_flag;
    U32 certificate_count;
    certman_cert_display_struct *display_p;
    U8 *is_selected;
    mmi_certman_certificate_list_struct  *certificate_list;
#ifdef __OCSP_SUPPORT__
    U8 *all_oscp_options[MMI_CERTMAN_OCSP_END];
    mmi_id oscp_inline_cui_id;
#endif /* __OCSP_SUPPORT__ */
} mmi_certman_launch_select_context_struct;

/**************************************************************************/
/*****************************Private Key Protection Method****************/
/**************************************************************************/

typedef struct
{
    U8 label[CERTMAN_LABEL_SIZE];
    U8 privatekey_pwd[CERTMAN_PASSWORD_SIZE *ENCODING_LENGTH];
    U32 cert_id;
    U32 trans_id;
    certman_fp_pwd_cb pwd_callback;
} mmi_certman_private_key_context_struct;

/***************************************************************************/
/*****************************View / Invalid Certificate********************/
/***************************************************************************/
typedef enum
{
    MMI_CERTMAN_VIEW_INVALID_IDLE = 0,
    MMI_CERTMAN_VIEW_INVALID_PARSING,
    MMI_CERTMAN_VIEW_INVALID_DETAIL,
    MMI_CERTMAN_VIEW_INVALID_DISPLAY,
    MMI_CERTMAN_VIEW_INVALID_OPTIONS,
    MMI_CERTMAN_VIEW_INVALID_CERT_LABEL,
    MMI_CERTMAN_VIEW_INVALID_IMPORT,
    MMI_CERTMAN_VIEW_INVALID_PARSE_END
} mmi_certman_view_invalid_state_enum;

typedef struct
{
    pBOOL install_option;
    U8 label[CERTMAN_LABEL_SIZE];
    U16 job_id;
    U16 current_state;
    U32 trans_id;
    U32 error;
    U32 cert_id;
    U32 ref_id;
    mmi_certman_fseditor_struct* fseditor;
    U16 mod_name;
    certman_ctx_parse_struct *ctx_parse_p;
    certman_ctx_import_struct *ctx_import_p;
    certman_parsed_data_struct *parsed_data_p;
} mmi_certman_view_invalid_context_struct;

/***************************************************************************/
/*****************************User Certificate List*************************/
/***************************************************************************/

typedef enum
{
    MMI_CERTMAN_USER_CERT_LIST_IDLE = 0,
    MMI_CERTMAN_USER_CERT_LIST_BY_ISSUERS_FILE_REQ,
    MMI_CERTMAN_USER_CERT_LIST_BY_ISSUERS_DATA_IND,
    MMI_CERTMAN_USER_CERT_LIST_DISPLAY
} mmi_certman_user_cert_list_state_enum;

typedef enum
{
    MMI_CERTMAN_POPUP_CALLBACK_NOT_EXECUTED = 0,
    MMI_CERTMAN_POPUP_CALLBACK_EXECUTED_BY_TIMEOUT,
    MMI_CERTMAN_POPUP_CALLBACK_EXECUTED_BY_ASYNC_EVENT
} mmi_certman_popup_callback_state;

typedef struct
{
    U16 current_state;
    U16 cert_count;
    U16 selected_index;
    U32 trans_id;
    U32 cert_group;
    U32 key_purpose;
    U16 mod_name;
    U8 label[CERTMAN_LABEL_SIZE];
    U32 certificate_dcs;
    mmi_certman_certificate_list_struct *certificate_list;
} mmi_certman_user_certificates_list;

typedef struct mmi_certman_task_queue_struct_
{
    U16 event_id;
    module_type src_module;
    void *data;
    struct mmi_certman_task_queue_struct_ *prev;
    struct mmi_certman_task_queue_struct_ *next;
} mmi_certman_task_queue_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} mmi_certman_read_queue_ind_struct;

#define MMI_CERTMAN_MEM_SIZE (sizeof(mmi_certman_launch_select_context_struct)                                                                    \
                        + sizeof(mmi_certman_private_key_context_struct)                                                                          \
                        + ((sizeof(mmi_certman_select_user_cert_ind_struct) + sizeof(mmi_certman_task_queue_struct)) * MMI_CERTMAN_QUEUE_LENGTH)  \
                        + ((sizeof(certman_privkey_usage_password_ind_struct) + sizeof(mmi_certman_task_queue_struct))* MMI_CERTMAN_QUEUE_LENGTH) \
						+ MMI_CERTMAN_CERTIFICATES_MAX + MMI_CERTMAN_CERTIFICATES_MAX*sizeof(mmi_certman_certificate_list_struct) \
                        + MMI_CERTMAN_OVERHEAD_BUFFER)

typedef struct
{
    mmi_certman_import_context_struct *import_context_p;    /* Import */
    mmi_certman_launch_select_context_struct *launch_select_context_p;  /* Launch Select */
    mmi_certman_private_key_context_struct *priv_key_context_p; /* Private key protection */
    mmi_certman_view_invalid_context_struct *view_invalid_context_p;
    mmi_certman_user_certificates_list *user_cert_list_context_p;
    U8 show_string[MMI_CERTMAN_TOTAL_KEY_USAGE *(MMI_CERTMAN_MAX_KEY_PURPOSE_LENGTH + ENCODING_LENGTH)];
    U8 key_usage_list[MMI_CERTMAN_TOTAL_KEY_USAGE][MMI_CERTMAN_MAX_KEY_PURPOSE_LENGTH];
    U8 *selected_protection_method[MMI_CERTMAN_MAX_PROTECTION_METHODS];
#ifdef __OCSP_SUPPORT__
    mmi_certman_ocsp_status_enum selected_ocsp_option;
    U8 default_ocsp_responder[NVRAM_EF_CERTMAN_OCSP_URL_SIZE];
#endif /*__OCSP_SUPPORT__*/
    U8 list_of_state[MMI_CERTMAN_TOTAL_KEY_USAGE];
    U32 count_key_usages;
    KAL_ADM_ID adm_id;
    kal_uint32 mem_pool[MMI_CERTMAN_MEM_SIZE / 4];
    U16 popup_string_id;
    kal_int32 g_mmi_certman_active_grp;
    U32 current_status;
    U32 curr_handle_value;
    U32 private_key_status;
    void (*entry_fun) (void);
    void (*popup_handler_callback) (void);
    module_type src_module;
    module_type curr_module;
    FuncPtr display_popup_callback;
    U8 display_popup_tone;
    U8 display_popup_timeout_complete;
    mmi_certman_task_queue_struct *head_task_queue;
    mmi_certman_task_queue_struct *head_priv_key_queue;
	pBOOL string_status;
} mmi_certman_context_struct;

#endif /* __CERTMAN_SUPPORT__ */ 
#endif /* MMI_CERTMAN_TYPES_H */ 
#endif /* __PLUTO_MMI_PACKAGE__ */
