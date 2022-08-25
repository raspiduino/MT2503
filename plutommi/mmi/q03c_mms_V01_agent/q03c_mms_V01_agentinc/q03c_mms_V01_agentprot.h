/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 * q03c_mms_v01_agentprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file contains internal prototypes for MMS V01 Agent
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef Q03C_MMS_V01_AGENT_PROT_H
#define Q03C_MMS_V01_AGENT_PROT_H

#if defined(OBIGO_Q03C_MMS_V01)

#ifndef __MMI_FEATURES__
#include "mmi_features.h"
#endif

#include "mms_api.h"    /*For mms_content_entry_struct*/
#include "q03c_mms_v01_adp_struct.h"
#include "Wapprofiletype.h"


#define MMSV01_AGENT_INPROGRESS_TIME_OUT        (1000*(60*2))

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
typedef enum
{
     MMI_MMSV01_AGENT_CVM_STATE_NONE = 0X0,
     MMI_MMSV01_AGENT_CVM_STATE_CREATE_PROCESS = 0X01,
     MMI_MMSV01_AGENT_CVM_STATE_SEND_PROCESS = 0X02,
     MMI_MMSV01_AGENT_CVM_STATE_DELETE_PROCESS = 0X04
}mmi_mmsv01_agent_cvm_state_enum;
#endif /* __MMI_MMS_VENDOR_APP_SUPPORT__*/

typedef enum
{
    MMI_MMSV01_AGENT_STARTUP_MODE_NONE,
    MMI_MMSV01_AGENT_STARTUP_MODE_EDITOR, 
    MMI_MMSV01_AGENT_STARTUP_MODE_FOLDER,
    MMI_MMSV01_AGENT_STARTUP_MODE_INBOX,
    MMI_MMSV01_AGENT_STARTUP_MODE_TOTAL
} mmi_mmsv01_agent_startup_mode;

typedef struct
{
   union
   {
        mms_content_entry_struct editor_data;
        kal_uint8 folder;
   }data;
   kal_uint8 startup_mode;
} new_mms_data_cntx_struct;


typedef struct
{
#ifdef __MMI_URI_AGENT__
    char *mms_uri_param;           /*For holding the URI string*/
#endif /*#ifdef __MMI_URI_AGENT__*/
#ifdef __MMI_MMS_V01_USE_ASM__
    new_mms_data_cntx_struct *data;
#endif
#ifdef __MMI_MMS_DUAL_SIM__
    kal_uint8               is_sim1_valid;
    kal_uint8               is_sim2_valid;
#endif /* __MMI_MMS_DUAL_SIM__ */ 

#ifdef __MMI_MMS_BGSR_SUPPORT__
    kal_uint8   mmi_mms_bgsr_op;
    kal_uint32  mmi_mms_bgsr_op_msg_id;
#endif /* __MMI_MMS_BGSR_SUPPORT__ */ 
#ifdef __MMI_MMS_V01_USE_ASM__
    void* asm_pool_id;
    kal_bool is_forced_shutdown;
#endif
    S8 *url_req;
    kal_uint8 type;
    kal_uint8 is_mms_ready;
#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
    kal_uint8 cvm_state;
#endif
}mmi_mms_v01_agent_context_struct;


extern void mmi_mms_make_call_req_hdlr(void *number);
extern void mmi_mms_enter_sms_editor_hdlr(void *p);

#ifdef __MMI_MMS_BGSR_SUPPORT__
extern void mmi_mms_bgsr_send_msg_req(void *p);
#endif
#ifdef __MMI_URI_AGENT__
extern void mms_uri_insert_hdlr(kal_uint32 ura_appid,char * url,char * param,kal_uint32 options,void * cb);
#endif

#ifdef __MMI_MMS_DUAL_SIM__
extern U8 mmi_mms_v01_agent_sim_status_info_hdlr(void *in_msg);
#endif 

#ifdef __MMI_MMS_BGSR_SUPPORT__
extern void mmi_mms_bgsr_send_msg_req_hdlr(void *p);
extern void mmi_mms_bgsr_change_msg_req_hdlr(void *p);
extern void mmi_mms_bgsr_msg_req_hdlr(void *p);
extern void mmi_mms_bgsr_cancel_send_msg_req_hdlr(void *p);
extern void mmi_mms_bgsr_cancel_download_msg_req_hdlr(void *p);
extern void mmi_mms_bgsr_change_msg_bgsr_notify_hdlr(void *p);
extern void mmi_mms_bgsr_get_msg_info_req_hdlr(void *p);
#endif /* __MMI_MMS_BGSR_SUPPORT__ */ 

extern int mms_is_file_can_be_forwarded_to_mms(const char *filename);
extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);
extern kal_bool is_mms_storage_exported_to_pc(void);
extern void mmi_mmsv01_agent_send_obj_ind(kal_wchar* filepath, kal_uint8 sim_id);
extern void mmi_mms_obj_ind_res_hdlr(void *p);
extern void mmi_mms_mea_terminate_ind_hdlr(void *p);
extern void mmi_mms_insert_text_req_hdlr(void *p, int src_mod, void *message);
extern void mmi_mmsv01_set_profile_rsp_hdlr(void *p);
extern void mmi_mms_add_bookmark_req_hdlr(void *p);
extern void mmi_mms_brw_launch_req_hdlr(void *p);
extern void mmi_mms_ready_ind_hdlr(void *p);
extern void mmi_mms_terminate_ind_hdlr(void *p);
extern void mmi_mms_set_settings_rsp_hdlr(void *p);
extern void mmi_mms_get_settings_req_hdlr(void *p);

extern void mmi_mmsv01_agent_send_set_profile_req(mmi_wap_prof_profile_content_struct *content,
                                                  kal_uint8 sim_id);
extern void mmi_mmsv01_send_settings_data(kal_uint16 msg_id,
                                   mmsV01_agent_compose_settings_struct* compose_settings,
                                   mmsV01_agent_sending_settings_struct* sending_settings,
                                   mmsV01_agent_retrieval_settings_struct* retrival_settings);
extern void mmi_mmsv01_agent_send_add_bookmark_rsp(kal_uint8 *url, kal_uint8 result);
extern void mmi_mmsv01_agent_send_set_profile_req(mmi_wap_prof_profile_content_struct *content, 
                                                    kal_uint8 sim_id);
extern void mmi_mmsv01_jsr_get_mms_profile_req(void *msg, int mod_id);
/*app*/
/*For ASM*/
#ifdef __MMI_MMS_V01_USE_ASM__
extern void mmi_mmsv01_agent_asm_deinit(void);
extern kal_bool mmi_mmsV01_agent_asm_pool_init(void);
extern void mmi_mmsv01_agent_set_startup_mode_instance(mms_content_entry_struct *data, kal_uint8 mode);
extern void mmi_mmsv01_free_startup_mode_instance(void);
#endif
/*utils*/
extern kal_bool mmi_mmsv01_agent_check_popup(void);
extern void mmi_mmsv01_agent_wap_not_ready(void);
extern kal_int32 mmi_mmsv01_agent_get_error_string(kal_uint8 error);
extern void mmi_mmsv01_agent_display_confirm(U16 LSK_str, U16 LSK_img, U16 RSK_str, U16 RSK_img,
                                        U16* msg_string, U16 event_id);

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
void mmi_mmsv01_agent_vendor_create_req_hdlr(void *in_msg);
void mmi_mmsv01_agent_vendor_create_rsp_hdlr(void *in_msg);
void mmi_mmsv01_agent_send_vendor_create_rsp(U32 msg_id, U8 result);

void mmi_mmsv01_agent_vendor_send_req_hdlr(void *in_msg);
void mmi_mmsv01_agent_vendor_send_rsp_hdlr(void *in_msg);
void mmi_mmsv01_agent_send_vendor_send_rsp(U32 msg_id, U8 result);

void mmi_mmsv01_agent_vendor_delete_req_hdlr(void *in_msg);
void mmi_mmsv01_agent_vendor_delete_rsp_hdlr(void *in_msg);
void mmi_mmsv01_agent_send_vendor_delete_rsp(kal_uint32 msg_id, kal_uint8 resut);

void mmi_mmsv01_agent_vendor_cancel_send_req_hdlr(void *in_msg);
void mmi_mmsv01_agent_vendor_cancel_send_rsp_hdlr(void *in_msg);
#endif

extern mmi_mms_v01_agent_context_struct g_mmi_mms_V01_agent_ctx;

//Rahul TODO:: actual macro defined in mea_cfg.h
// Should define this macro in feature file 

#define MEA_CFG_WARNING_MODE_SUPPORT

#endif /* defined(OBIGO_Q03C_MMS_V01) */ 

#endif /* Q03C_MMS_V01_AGENT_PROT_H */ 

