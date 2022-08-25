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
 * soc_app.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains function prototypes of soc_app.c.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _SOC_APP_H
#define _SOC_APP_H

#include "soc_feature.h"
#include "soc_struct.h"
#include "soc_consts.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "app_ltlcom.h"

#ifndef _SOC_STRUCT_H
#error include soc_struct.h before soc_app.h
#endif /* !_SOC_STRUCT_H */

extern void soc_notify_application(socket_struct *so,
                                   soc_event_enum event,
                                   kal_bool result,
                                   kal_int8 cause,
                                   kal_int32 detail_cause);

extern soc_app_proc_struct *soc_find_app_proc(soc_app_id_struct *app);
extern void soc_app_slot_reset(soc_app_proc_struct *app);
extern void soc_app_pool_initialize(soc_app_proc_struct app_proc[]);

extern void soc_send_msg_to_app(module_type dest_id,
                                kal_uint16 msg_id,
                                local_para_struct *local_para_ptr,
                                peer_buff_struct *peer_buff_ptr);

extern void soc_send_linger_timeout_event_to_all_app(kal_uint32 nw_acc_id, kal_uint8 bearer);

extern kal_bool soc_find_app_acc_slot(soc_app_proc_struct *app_proc,
                                      kal_uint8 *idx,
                                      kal_uint32 acc_id,
                                      kal_uint8  qos_profile_id);

extern kal_bool soc_find_app_free_acc_slot(soc_app_proc_struct *app_proc,
                                           kal_uint8 *idx);

extern kal_int8 soc_app_activate_req_hdlr(module_type mod_id, 
                                   kal_uint32 account_id);

extern void soc_app_deactivate_req_hdlr(module_type mod_id,
                                        kal_uint32 nw_acct_id, 
                                        kal_uint8 qos_profile);

extern void soc_app_auto_deactivate_req(module_type mod_id,
                                        kal_uint32 nw_acct_id, 
                                        kal_uint8 qos_profile_id,
                                        kal_bool is_used_by_soc);  

extern kal_bool soc_check_all_sockets_closed(soc_app_id_struct *app, 
                                             soc_app_account_struct *account);

extern kal_int8 soc_auto_deact_bearer(socket_struct *so);

extern
kal_uint32 soc_get_gprs_linger_time_val(kal_uint32 account_id);

extern
kal_bool soc_set_gprs_linger_time_val(kal_uint16 time_val, kal_uint8 account_id);

extern
kal_bool soc_is_recv_queue_ready(socket_struct *so);

#endif /* !_SOC_APP_H */

