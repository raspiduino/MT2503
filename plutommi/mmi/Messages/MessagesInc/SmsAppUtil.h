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
 *  SmsAppUtil.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __SMS_APP_UTIL_H__
#define __SMS_APP_UTIL_H__
#include "MMI_features.h"
#include "MMIDataType.h"
#include "Ems.h"
#include "SmsAppType.h"

#include "kal_general_types.h"
#include "SmsSrvGprot.h"
#include "UmSrvDefs.h"
#if (MMI_MAX_SIM_NUM >= 2)
#if defined(__MMI_MMS_STANDALONE_COMPOSER__) || defined(__MMI_UNIFIED_COMPOSER__)
#include "UcSrvGprot.h"
#endif
#endif

typedef MMI_BOOL (*mmi_sms_sim_op_check_func_t)(mmi_sim_enum sim);

extern void mmi_sms_get_address(U16 msg_id, S8* address, U8 max_address_len);
extern void mmi_sms_get_msg_date_time(U16 msg_id, S8 *date_str, S8 *time_str);
extern U16 mmi_sms_get_icon(U16 msg_id);

extern MMI_BOOL mmi_sms_check_sms_num_exceeded(S8* ucs2_num);

extern MMI_BOOL mmi_sms_is_unread_msg(U16 msg_id);

extern U8* mmi_sms_get_msg_address(U16 msg_index);
extern MMI_BOOL mmi_sms_is_empty_address(U16 msg_id);
extern MMI_BOOL mmi_sms_is_sms_ready(void);

#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
MMI_BOOL mmi_sms_save_contact(U16 scrid, U16 type);
#endif

extern EMSTATUS mmi_sms_add_text_to_ems_data(EMSData *ems_data, S8* ucs2_content);
extern EMSTATUS mmi_sms_add_gsm_text_to_ems_data(EMSData *ems_data, S8* ucs2_content);
extern EMSTATUS mmi_sms_add_data_to_ems_data(
                            EMSData *ems_data,
                            U16 src_port,
                            U16 dest_port,
                            S8 *file_path,
                            S8 *content_buff,
                            U32 buff_size);
extern U16 mmi_sms_convert_to_extension_char_buff(S8 *dest_buf, S8 *src_buf, U16 char_num);
extern void mmi_sms_asc_to_wchar(S8 *dest_buf, S8 *src_buf, U32 src_buf_len);

extern MMI_BOOL mmi_sms_is_ems_content_empty(EMSData *ems_data);
#ifdef __MMI_MESSAGES_SMS_EMAIL__
extern MMI_BOOL mmi_sms_is_sms_email(U16 msg_id);
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

extern MMI_BOOL mmi_sms_is_send_enable(void);

extern MMI_BOOL mmi_sms_check_is_valid_oa_addr(U16 msg_index);

extern void mmi_sms_set_msg_icon(MMI_BOOL is_set_mem_icon, srv_sms_sim_enum sim_id);
extern void mmi_sms_hide_msg_icon(srv_sms_sim_enum sim_id);

extern MMI_BOOL mmi_sms_is_exist_unread_sms(srv_sms_sim_enum sim_id);

extern srv_sms_sim_enum mmi_sms_get_um_filter_sim_id(void);

extern MMI_BOOL mmi_sms_gui_check_ucs2(S8* ucs2_text_buff, U16 char_num);

#ifdef __UM_SUPPORT__

extern srv_um_msg_box_enum mmi_sms_um_get_um_box_type(
                                srv_sms_status_enum status_type, 
                                srv_sms_folder_enum folder_type,
                                srv_sms_storage_enum storage_type);
extern srv_sms_box_enum mmi_sms_um_um_box_to_sms(srv_um_msg_box_enum um_box_type);
extern srv_um_msg_box_enum mmi_sms_um_sms_box_to_um(srv_sms_box_enum sms_box_type);

#endif

extern U32 mmi_sms_get_valid_sim_op_count(mmi_sms_sim_op_check_func_t hdlr);
#if (MMI_MAX_SIM_NUM >= 2)  
#if defined(__MMI_MMS_STANDALONE_COMPOSER__) || defined(__MMI_UNIFIED_COMPOSER__)
extern srv_uc_sim_id mmi_sms_sim_id_to_uc_sim(srv_sms_sim_enum sms_sim_id);
#endif
extern U16 mmi_sms_get_sim_str_id(mmi_sim_enum mmi_sim);

#ifdef __UM_SUPPORT__
extern srv_sms_sim_enum mmi_sms_um_sim_to_sms_sim(srv_um_sim_enum um_sim_id);
extern srv_um_sim_enum mmi_sms_sim_id_to_um_sim(srv_sms_sim_enum sms_sim_id);
#endif
#endif

#if (MMI_MAX_SIM_NUM >= 2) 
extern void mmi_sms_set_save_send_select_sim_leaf_item(MMI_ID cui_menu_gid, MMI_MENU_ID menu_id, mmi_sms_sim_op_check_func_t hdlr);
#endif

#ifdef  __GENERAL_TTS__
extern void mmi_sms_play_msg_by_content(U16 msg_id);
extern void mmi_sms_play_msg_without_content(U16 msg_id);
#endif

#endif /* __SMS_APP_UTIL_H__ */

