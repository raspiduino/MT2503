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
 *  mtvsmsiprot.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  sms with mtv internal header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MTV_SMS_IPROT_H_
#define _MTV_SMS_IPROT_H_

/**************************************************************
 * Header Files Include
 **************************************************************/
#include "MMI_include.h"
#ifdef __ATV_SMS_SUPPORT__

#include "MMIDataType.h"
#include "UMSrvDefs.h"
#include "UmSrvGprot.h"
#include "SmsSrvGprot.h"
#include "MtvSmsgprot.h"
#include "mmi_rp_app_mtv_sms_def.h"
#include "PhbSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "mtvsmsgprot.h"

#ifndef __MMI_DUAL_SIM_MASTER__
#endif
/**************************************************************
 * MARCO
 **************************************************************/
#define MMI_MTV_SMS_SMS_TYPE SRV_UM_MSG_SMS
#define MMI_MTV_SMS_INVALID_INDEX  0xFFFF 
#define EMS_ESCAPE_CHARACTER  (27)
#define MMI_MTV_SMS_INVALID_INDEX       0xFFFF 
#define MMI_MTV_SMS_MAX_NUM_LEN             MAX_DIGITS_SMS
#define MMI_MTV_SMS_MAX_ADDR_LEN            MMI_MTV_SMS_MAX_NUM_LEN
/* #define MMI_MTV_SMS_MAX_RECIPIENTS_NUM      20 */
#define MTV_MTV_SMS_MAX_ADDR_LEN SRV_SMS_MAX_ADDR_LEN
#define MMI_MTV_SMS_MAX_RECIPIENTS_NUM 1
#define MMI_MTV_SMS_MAX_BUFFER_FOR_ONE  (160 * 6 * 2)


/**************************************************************
 * enum Declaration
 **************************************************************/

typedef enum
{
    MMI_MTV_SMS_INBOX = 0,          
    MMI_MTV_SMS_DARFTBOX,
    MMI_MTV_SMS_OUTBOX,
    MMI_MTV_SMS_SENTBOX,
    MMI_MTV_SMS_ALLBOX
}mmi_mtv_sms_box_enum;

typedef enum
{
    MMI_MTV_SMS_NOTIFY_INFO,
    MMI_MTV_SMS_NOTIFY_OK,
    MMI_MTV_SMS_NOTIFY_FAILURE,
    MMI_MTV_SMS_MESSAGE_SENT,
    MMI_MTV_SMS_LOADING
}mmi_mtv_event_notify_enum;


typedef enum
{
    MTV_SMS_SEND_RESULT_OK,
    MTV_SMS_SEND_RESULT_ERROR,
    MTV_SMS_SEND_RESULT_NOT_READY,
    MTV_SMS_SEND_RESULT_DATA_EXCEED,
    MTV_SMS_SEND_RESULT_DATA_INVALID,
    MTV_SMS_SEND_RESULT_EMAIL_NO_SPACE,
    MTV_SMS_SEND_RESULT_MEM_FULL,
    MTV_SMS_SEND_RESULT_SAVE_TO_DRAFTS,
    MTV_SMS_SEND_RESULT_GROUP_GOBACK,
    MTV_SMS_SEND_RESULT_CANCEL,
    MTV_SMS_SEND_RESULT_SENT_AND_SAVED,
    MTV_SMS_SEND_RESULT_SENT_BUT_SAVE_FAIL,
    MTV_SMS_SEND_RESULT_SEND_FAIL_BUT_SAVED,
    MTV_SMS_SEND_RESULT_SEND_FAIL_AND_SAVE_FAIL,
    MTV_SMS_SEND_RESULT_TOTAL
} mtv_sms_result_enum;

typedef enum
{
    MTV_SMS_RESULT_OK,
    MTV_SMS_RESULT_ERROR,
    MTV_SMS_RESULT_NOT_READY,
    MTV_SMS_RESULT_DATA_EXCEED,
    MTV_SMS_RESULT_DATA_INVALID,
    MTV_SMS_RESULT_MEM_FULL,
    MTV_SMS_RESULT_CANCEL,
    MTV_SMS_RESULT_SENT_AND_SAVED,
    MTV_SMS_RESULT_SENT_BUT_SAVE_FAIL,
    MTV_SMS_RESULT_SEND_FAIL_BUT_SAVED,
    MTV_SMS_RESULT_SEND_FAIL_AND_SAVE_FAIL,
    MTV_SMS_RESULT_TOTAL
}mmi_mtv_sms_result_enum;

typedef enum
{
  MMI_MTV_SMS_LIST_NONE,
  MMI_MTV_SMS_LIST_INBOX,
  MMI_MTV_SMS_LIST_OUTBOX,
  MMI_MTV_SMS_LIST_DRAFTS,
  MMI_MTV_SMS_LIST_UNSENT,
  MMI_MTV_SMS_LIST_ARCHIVE,
  MMI_MTV_SMS_LIST_SIMBOX,
  MMI_MTV_SMS_LIST_REPORT,
  MMI_MTV_SMS_LIST_MESSAGING_DATA,
  MMI_MTV_SMS_LIST_RECENT_EVENT,
  MMI_MTV_SMS_LIST_TOOLBAR,
  MMI_MTV_SMS_LIST_TOTAL
}mmi_mtv_sms_list_enum;


typedef enum
{
	MTV_SMS_SEND_CASE_NONE,
	MTV_SMS_SEND_CASE_WRITE_NEW_MSG,
    MTV_SMS_SEND_CASE_REPLY,
    MTV_SMS_SEND_CASE_ARCHIVE_REPLY,
	MTV_SMS_SEND_CASE_EDIT_DRAFT,
	MTV_SMS_SEND_CASE_EDIT_UNSENT,
	MTV_SMS_SEND_CASE_FORWARD,
	MTV_SMS_SEND_CASE_RESEND,
	MTV_SMS_SEND_CASE_SEND_DRAFT,

	MTV_SMS_SEND_CASE_WRITE_FROM_OTHER_APP,
	MTV_SMS_SEND_CASE_SEND_FROM_OTHER_APP,
    MTV_SMS_SEND_CASE_SEND_DATA_MSG,

    MTV_SMS_SEND_CASE_TOTAL
}mmi_mtv_sms_send_case_enum;

typedef enum
{
    MMI_MTV_SMS_STATUS_UNREAD,
    MMI_MTV_SMS_STATUS_INBOX,
    MMI_MTV_SMS_STATUS_SENT,
    MMI_MTV_SMS_STATUS_UNSENT,
    MMI_MTV_SMS_STATUS_DRAFTS,
    MMI_MTV_SMS_STATUS_DELIVERY_REPORT,
    MMI_MTV_SMS_STATUS_PENDING_REPORT,
    MMI_MTV_SMS_STATUS_UNSUPPORT,
    MMI_MTV_SMS_STATUS_TOTAL
}mmi_mtv_sms_msg_status_enum;

typedef enum
{
    MMI_MTV_SMS_PHB_NAME_REQ,
    MMI_MTV_SMS_PHB_NUMBER_REQ,
    MMI_MTV_SMS_PHB_SEND_SMS_REQ,
    MMI_MTV_SMS_PHB_TOTAL
}mmi_mtv_sms_phb_list_req_enum;


/**************************************************************
 * Structure Declaration
 **************************************************************/

typedef struct
{
   /* srv_sms_sim_enum sim_id;      */           /* sim id */
    U16 total_number[MMI_MTV_SMS_ALLBOX];                   /* inbox message number */
}mmi_mtv_sms_msg_num_struct;

typedef struct
{
    MMI_ID current_scrn;
    U32 current_index;
    mmi_mtv_sms_msg_num_struct* number_cntx;
}mmi_mtv_sms_scrn_cntx_struct;


typedef struct
{
    srv_sms_sim_enum sim_id;
    mmi_mtv_sms_list_enum curr_list_type;
    srv_sms_box_enum curr_box_type;
    mmi_mtv_sms_msg_status_enum curr_msg_status;
    
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    srv_sms_send_status_enum send_status;
    U16 unsent_box_list_index;
#endif

    U16 curr_msg_type;
    U16 curr_msg_id;
    
    S32 curr_list_index;

    EMSData *edit_ems_data;
    EMSData *view_ems_data;
} mmi_mtv_sms_context_struct;


typedef void(*v_func_v)(void) ;
typedef void (*MtvSmsSendCBFuncPtr)(mtv_sms_result_enum);
typedef void (*mmi_mtv_sms_get_template_handle_fuct_t)(S8*);
typedef void (*SmsMtvCBFuncPtr) (mmi_mtv_sms_result_enum, void*);
typedef void (*PHBCallBackFuncPtr)(U16);

/**************************************************************
 * Global Variables Declaration
 **************************************************************/
extern mmi_mtv_sms_scrn_cntx_struct g_mtv_sms_scrn_cntx;
extern mmi_mtv_sms_context_struct g_mtv_sms_cntx;
extern void* video_layer_buffer_ptr;
extern void* util_layer_buffer_ptr;
extern KAL_ADM_ID adm_id;
extern show_video_func mmi_mtv_sms_video_player_callback;
extern FuncPtr mmi_mtv_sms_video_player_stop_callback;

/**************************************************************
 * Global Function Declaration
 **************************************************************/
/* common screens*/
extern void mmi_mtv_sms_display_popup(MMI_ID string, mmi_mtv_event_notify_enum event_id);
extern void mmi_mtv_sms_entry_common_options(MMI_ID scr_id, MMI_ID root_id);
extern void mmi_mtv_sms_entry_confirm_generic(U16 scrn_id, U16 str_id, FuncPtr lskfunc, FuncPtr rskfunc);
extern void mmi_mtv_sms_scrn_close(MMI_ID scrn_id);
extern void mmi_mtv_sms_scrn_back(void);
extern void mmi_mtv_sms_pre_entry_processing_screen(
             MMI_ID scr_id, 
             U16 caption_id, 
             U16 Lsk_string,
             v_func_v lsk_func, 
             U16 rsk_string, 
             v_func_v rsk_func, 
             U16 processing_str_id);
extern MMI_BOOL mmi_mtv_sms_scrn_replace(U16 out_scrn_id, U16 in_scrn_id, FuncPtr in_src_func);
extern MMI_BOOL mmi_mtv_sms_is_send_enable(void);

/* ems */
extern U8 MTVCopyEMSViewToEditBuffer(void);
extern EMSData *MtvGetEMSDataForView(EMSData **p, U8 force);
extern EMSData *MtvGetEMSDataForEdit(EMSData **p, U8 force);
extern void MTVReleaseEMSViewBuffer(void);
extern void MTVReleaseEMSEditBuffer(void);
extern void mmi_mtv_sms_copy_ems_parameters(EMSData* pEMS_dst, EMSData* pEMS_src);

/*common*/
extern void mmi_mtv_sms_read_msg(U16 msg_id, MMI_BOOL change_status, SmsMtvCBFuncPtr callback_func);
extern MMI_BOOL mmi_mtv_sms_get_address(U16 msg_id, S8* address, U8 max_address_len);
extern void mmi_mtv_sms_set_confirm_generic(U16 scrn_id, U16 str_id, FuncPtr lskfunc, FuncPtr rskfunc);
extern void mmi_mtv_sms_entry_confirm(void);
extern void mmi_mtv_sms_entry_confirm_no_csk(void);

/*editor*/
extern void mmi_mtv_sms_start_send_msg_get_sendcase(void);
extern void mmi_mtv_sms_pre_entry_editor(void);
extern void mmi_mtv_sms_save_hilite_sim1(void);
extern void mmi_mtv_sms_save_hilite_sim2(void);
extern void mmi_mtv_sms_editor_option_send_hilite(void);
extern void mtv_mmi_sms_ed_opt_input_method_hilite(void);
extern void mmi_mtv_sms_editor_option_insert_template_hilite(void);
extern void mmi_mtv_sms_editor_option_insert_name_hilite(void);
extern void mmi_mtv_sms_editor_option_insert_number_hilite(void);
extern void mmi_mtv_sms_editor_option_save_hilite(void);

/* template */
#ifdef __MMI_MESSAGES_TEMPLATE__
extern void mmi_mtv_sms_entry_template_list(void);
extern void mmi_mtv_sms_register_get_template_callback(mmi_mtv_sms_get_template_handle_fuct_t call_back);
#endif

/*send*/
extern void mmi_mtv_sms_set_send_msg_case(mmi_mtv_sms_send_case_enum send_msg_case);
extern MMI_BOOL mmi_mtv_sms_get_is_sent(void);
extern void mmi_mtv_sms_entry_write_msg_ems_cut_confirm(void);
extern void mmi_mtv_sms_reset_recipient_data(void);
extern void mmi_mtv_sms_edit_send_entry(void);
extern void  mmi_mtv_sms_send_sms(void);
extern mmi_mtv_sms_send_case_enum mmi_mtv_sms_get_send_msg_case(void);
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
#endif
extern void mmi_mtv_sms_send_register_call_back(MtvSmsSendCBFuncPtr call_back);
extern void mmi_mtv_sms_set_is_recipient_modify(MMI_BOOL set);
extern void mmi_mtv_sms_sending_hilite_sim1(void);
extern void mmi_mtv_sms_sending_hilite_sim2(void);

/* list */
extern void mmi_mtv_sms_set_is_sent_false(void);
extern void mmi_mtv_sms_set_is_sent_true(void);
extern void mmi_mtv_sms_pre_entry_msgbox_list(srv_sms_box_enum list_type);
extern void mmi_mtv_sms_list_view_hilite(void);
extern void mmi_mtv_sms_list_reply_hilite(void);
extern void mmi_mtv_sms_list_resend_hilite(void);
extern void mmi_mtv_sms_list_send_hilite(void);
extern void mmi_mtv_sms_list_forward_hilite(void);
extern void mmi_mtv_sms_list_delete_hilite(void);
extern void mmi_mtv_sms_list_deleteall_hilite(void);
extern void mmi_mtv_sms_list_edit_hilite(void);


/* view */
extern void mmi_mtv_sms_list_opt_pre_view(void);
extern MMI_BOOL mmi_mtv_sms_check_is_valid_oa_addr(U16 msg_id);

/* PHB list */
extern MMI_BOOL mmi_matv_sms_entry_phb_list_group(mmi_mtv_sms_phb_list_req_enum type);
extern void mmi_matv_sms_register_phb_list_callback(PHBCallBackFuncPtr func_ptr);
extern void mmi_matv_sms_phb_list_close(void);

extern void mmi_mtv_sms_write_msg_hilite_handler(void);
extern void mmi_mtv_sms_hilite_inbox(void);
extern void mmi_mtv_sms_hilite_draftbox(void);
extern void mmi_mtv_sms_hilite_outbox(void);
extern void mmi_mtv_sms_hilite_sentbox(void);

extern void mmi_mtv_sms_viewer_reply_hilite(void);
extern void mmi_mtv_sms_viewer_resend_hilite(void);
extern void mmi_mtv_sms_viewer_send_hilite(void);
extern void mmi_mtv_sms_viewer_forward_hilite(void);
extern void mmi_mtv_sms_viewer_delete_hilite(void);
extern void mmi_mtv_sms_viewer_edit_hilite(void);
/**************************************************************
 * Static Variables Defination
 **************************************************************/


/**************************************************************
 * Static Function Declaration
 **************************************************************/

#endif /* _MMI_ATV_SMS_SUPPORT__ */

#endif /*  _MTV_SMS_IPROT_H_ */


