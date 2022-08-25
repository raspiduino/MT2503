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
 *  SmsAppMsg.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __SMS_APP_MSG_H__
#define __SMS_APP_MSG_H__
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"

#include "SmsAppType.h"
#include "SmsSrvGprot.h"

extern void mmi_sms_read_msg(U16 msg_id, MMI_BOOL change_status, SmsCBFuncPtr callback_func);
extern void mmi_sms_delete_msg(U16 msg_id, SmsCBFuncPtr callback_func);
#ifdef __MMI_MESSAGES_COPY__
extern void mmi_sms_copy_msg(U16 msg_id, srv_sms_storage_enum dest_storage, SmsCBFuncPtr callback_func);
extern void mmi_sms_move_msg(U16 msg_id, srv_sms_storage_enum dest_storage, SmsCBFuncPtr callback_func);
extern void mmi_sms_copy_msg_ext(U16 msg_id, srv_sms_storage_enum dest_storage, srv_sms_sim_enum sim_id, SmsCBFuncPtr callback_func);
extern void mmi_sms_move_msg_ext(U16 msg_id, srv_sms_storage_enum dest_storage, srv_sms_sim_enum sim_id, SmsCBFuncPtr callback_func);

extern void mmi_sms_copy_all_sms(
                srv_sms_box_enum msg_box_type,
                srv_sms_storage_enum dest_storage,
                srv_sms_sim_enum sim_id,
                SmsCBFuncPtr callback_func);
extern void mmi_sms_move_all_sms(
                srv_sms_box_enum msg_box_type,
                srv_sms_storage_enum dest_storage,
                srv_sms_sim_enum sim_id,
                SmsCBFuncPtr callback_func);
 #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
  extern void mmi_sms_copy_all_sms_tcard(
                srv_sms_box_enum msg_box_type,
                srv_sms_storage_enum src_storage,
                srv_sms_storage_enum dest_storage,
                srv_sms_sim_enum sim_id,
                SmsCBFuncPtr callback_func);
 extern void mmi_sms_move_all_sms_tcard(
                srv_sms_box_enum msg_box_type,
                srv_sms_storage_enum src_storage,
                srv_sms_storage_enum dest_storage,
                srv_sms_sim_enum sim_id,
                SmsCBFuncPtr callback_func);
 #endif               
#endif /* __MMI_MESSAGES_COPY__ */
extern void mmi_sms_change_sms_status(U16 msg_id, srv_sms_status_enum status, SmsCBFuncPtr callback_func);

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
extern void mmi_sms_move_msg_to_archive(U16 msg_id, SmsCBFuncPtr callback_func);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
extern void mmi_sms_change_unsent_sending_status(U16 msg_id, srv_sms_send_status_enum status);
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

#endif /* __SMS_APP_MSG_H__ */

