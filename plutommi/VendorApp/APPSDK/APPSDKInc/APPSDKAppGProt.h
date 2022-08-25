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
 *  SDKMisc.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _SDKMISC_H_
#define _SDKMISC_H_

#include "MMI_features.h"

//#include "browser_api.h"

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/****************************************************************************
 * SmsAppGprot.h
 ****************************************************************************/
#ifndef __COSMOS_MMI_PACKAGE__
#include "SmsAppGprot.h"

extern void mmi_sms_write_msg_lanch(mmi_id parent_gid, mmi_sms_write_msg_para_struct *para);
#endif
/****************************************************************************
 * SmsSrvGprot.h
 ****************************************************************************/
#include "SmsSrvGprot.h"
extern SMS_HANDLE srv_sms_get_send_handle(void);  
extern MMI_BOOL srv_sms_is_bg_send_action_busy(void);
extern MMI_BOOL srv_sms_set_address(SMS_HANDLE sms_handle, S8 *ucs2_addr);
extern void srv_sms_set_content_dcs(SMS_HANDLE sms_handle, srv_sms_dcs_enum dcs);
extern void srv_sms_set_content(SMS_HANDLE sms_handle, S8 *content_buff, U16 content_size);
extern void srv_sms_set_sim_id(SMS_HANDLE sms_handle, srv_sms_sim_enum sim_id);
extern void srv_sms_send_msg(SMS_HANDLE send_handle, SrvSmsCallbackFunc callback_func, void *user_data);
extern void srv_sms_abort_send(SMS_HANDLE sms_handle);



/****************************************************************************
 * Ucmgprot.h
 ****************************************************************************/
#include "UcmGprot.h"

extern void mmi_ucm_app_make_call(mmi_ucm_call_type_enum call_type, U8 *num_uri);
extern void mmi_ucm_init_call_para(mmi_ucm_make_call_para_struct *make_call_para);
extern S32 srv_ucm_query_call_count(srv_ucm_call_state_enum call_state, srv_ucm_call_type_enum call_type, srv_ucm_index_info_struct *index_list);


/****************************************************************************
 * gpioInc.h
 ****************************************************************************/
//#include "gpioInc.h"
#include "GeneralDeviceGprot.h"



/****************************************************************************
 * Mms_api.h
 ****************************************************************************/
//#include "Mms_api.h"
extern void mms_text_insert_hdlr(char * subject, unsigned int subject_len, char * text, unsigned int text_len);


/****************************************************************************
 * App_datetime.h
 ****************************************************************************/
#include "App_datetime.h"

extern void applib_dt_get_date_time(applib_time_struct *t);
extern void applib_dt_get_rtc_time(applib_time_struct *t);
extern kal_uint32 applib_dt_mytime_2_utc_sec(applib_time_struct *currTime, kal_bool daylightSaving);
extern kal_int64 applib_dt_mytime_2_utc_sec_ext(applib_time_struct *currTime, kal_bool daylightSaving);
extern kal_uint8 applib_dt_utc_sec_2_mytime(kal_uint32 utc_sec, applib_time_struct *result, kal_bool daylightSaving);
extern kal_uint8 applib_dt_utc_sec_2_mytime_ext(kal_int64 utc_sec, applib_time_struct *result, kal_bool daylightSaving);
extern kal_uint32 applib_dt_sec_utc_to_local(kal_uint32 utc_sec);
extern kal_uint32 applib_dt_sec_local_to_utc(kal_uint32 local_sec);


/****************************************************************************
 * che_api.h
 ****************************************************************************/
#include "che_api.h"

void che_init(STCHE* che_context, kal_uint32 type);
void che_deinit(STCHE* che_context);

#define che_key_action(che_context, key_act, key, key_len)                 \
                                                                           \
   ((void)TRICK_##key_act, run_##key_act##_process(che_context, key, key_len))
void che_set_iv(STCHE* che_context, kal_uint8 *iv, kal_uint32 iv_len);
   
#define che_process(che_context, type, mode, act, source, dest, source_length, final)                       \
                                                                                                                 \
   ((void)TRICK_##type, run_##type##_process(che_context, type, mode, act, source, dest, source_length, final, 0))

#define che_process_from_file(che_context, type, mode, act, pstFSAL, dest)                                      \
																													\
	   ((void)TRICK_##type, run_##type##_process(che_context, type, mode, act, 0, dest, 0, 0, pstFSAL)) 				   

extern kal_int32 che_rsa_public_encrypt(STCHE *ctx, kal_uint8 *src, kal_uint32 src_len, kal_uint8 *dst, kal_uint32 *dst_len, che_rsa_padding_mode_enum padding);
extern kal_int32 che_rsa_private_encrypt(STCHE *ctx, kal_uint8 *src, kal_uint32 src_len, kal_uint8 *dst, kal_uint32 *dst_len, che_rsa_padding_mode_enum padding);
extern kal_int32 che_rsa_public_decrypt(STCHE *ctx, kal_uint8 *src, kal_uint32 src_len, kal_uint8 *dst, kal_uint32 *dst_len, che_rsa_padding_mode_enum padding);
extern kal_int32 che_rsa_private_decrypt(STCHE *ctx, kal_uint8 *src, kal_uint32 src_len, kal_uint8 *dst, kal_uint32 *dst_len, che_rsa_padding_mode_enum padding);

/****************************************************************************
 * mmi_frm_history_gprot.h
 ****************************************************************************/


/****************************************************************************
 * USBDeviceGprot.h
 ****************************************************************************/
//#include "USBDeviceGprot.h"

extern pBOOL mmi_usb_is_in_mass_storage_mode(void);
extern pBOOL mmi_usb_check_path_exported(S8 *path);
void mmi_usb_app_unavailable_popup(U16 stringID);


/****************************************************************************
 * SimDetectionGprot.h
 ****************************************************************************/
#include "sim_common_enums.h"
#include "l4c2phb_enums.h"


/****************************************************************************
 * Mtpnp_ad_master_common_def.h
 ****************************************************************************/
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/****************************************************************************
 * NetworkGProt.h
 ****************************************************************************/

extern U8 mmi_nw_get_signal_strength_in_percentage(const sim_interface_enum required_sim);

/****************************************************************************
 * PhoneBookGport.h
 ****************************************************************************/
#include "PhbSrvGprot.h"

extern MMI_BOOL srv_phb_sdk_is_phb_ready(void);
extern void srv_phb_sdk_add_contact(srv_phb_sdk_add_req_struct* req_info, srv_phb_sdk_callback_type cb);
extern void srv_phb_sdk_update_contact(srv_phb_sdk_update_req_struct* req_info, srv_phb_sdk_callback_type cb);
extern void srv_phb_sdk_delete_contact(srv_phb_sdk_delete_req_struct* req_info, srv_phb_sdk_callback_type cb);
extern S32 srv_phb_sdk_get_contact(srv_phb_sdk_get_req_struct* req_info);
extern S32 srv_phb_sdk_search_contact(srv_phb_sdk_search_req_struct* req_info);
extern S32 srv_phb_sdk_get_total_contacts(phb_storage_enum storage);
extern S32 srv_phb_sdk_get_used_contacts(srv_phb_contact_pos_struct* pos_array, phb_storage_enum storage);
extern U8 srv_phb_datamgr_get_group_list(U8* group_array, U16* group_name);


#endif /* _SDKMISC_H_ */ 

