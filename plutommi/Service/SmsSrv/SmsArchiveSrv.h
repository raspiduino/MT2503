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
 *  SmsArchiveSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Archive Internal Header File
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __SMS_ARCHIVE_SRV_H__
#define __SMS_ARCHIVE_SRV_H__

#include "MMI_features.h"
#ifdef __SRV_SMS_ARCHIVE__
#include "kal_general_types.h"
#include "customer_ps_inc.h"
#include "MMIDataType.h"
#include "SmsSrvGprot.h"
#include "ems.h"


#define SRV_SMS_MAX_ARCH_ENTRY              CM_SMS_MAX_ARMSG_NUM
#define SRV_SMS_ARCHIVE_INVALID_ENTRY_ID    0xFFFF

extern MMI_BOOL srv_sms_archive_init(void);
extern MMI_BOOL srv_sms_archive_is_msg_exist(U16 entry_id);
extern MMI_BOOL srv_sms_archive_is_msg_valid(U16 entry_id);

extern srv_sms_cause_enum srv_sms_archive_read_msg(
                            U16 entry_id,
                            MMI_BOOL change_status,
                            EMSData* ems_data,
                            srv_sms_msg_info_struct* msg_info);
extern srv_sms_cause_enum srv_sms_archive_save_msg(
                            U16* dest_entry_id,
                            EMSData* ems_data,
                            srv_sms_msg_info_struct* msg_info,
                            MMI_BOOL is_complete);

extern srv_sms_cause_enum srv_sms_archive_delete_msg(U16 entry_id);
extern srv_sms_cause_enum srv_sms_archive_change_msg_status(U16 entry_id, srv_sms_status_enum status);

extern S32 srv_sms_archive_get_fs_error(void);

extern void srv_sms_archive_get_msg_info(U16 entry_id, srv_sms_msg_info_struct *msg_info);

extern const char* srv_sms_archive_get_msg_address(U16 entry_id);
extern const char* srv_sms_archive_get_msg_content(U16 entry_id);
extern U32 srv_sms_archive_get_msg_timestamp_utc_sec(U16 entry_id);
extern srv_sms_pid_enum srv_sms_archive_get_msg_pid(U16 entry_id);
extern srv_sms_status_enum srv_sms_archive_get_msg_status(U16 entry_id);
extern srv_sms_sim_enum srv_sms_archive_get_msg_sim_id(U16 entry_id);
extern srv_sms_storage_enum srv_sms_archive_get_msg_storage_type(U16 entry_id);
extern MMI_BOOL srv_sms_archive_get_complete_flag(U16 entry_id);
extern U16 srv_sms_archive_get_msg_size(U16 entry_id);
extern MMI_BOOL srv_sms_archive_reset_all_msg(void);
#endif /* __SRV_SMS_ARCHIVE__ */
#endif /* __SMS_ARCHIVE_SRV_H__ */


