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
 * soc_abm.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains function prototypes of soc_abm.c.
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
#ifndef _SOC_ABM_H
#define _SOC_ABM_H


#include "abm2soc_struct.h"

#include "soc_feature.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "soc_struct.h"
#include "stack_config.h"
#include "cbm_consts.h"

extern void soc_abm_entry_func(ilm_struct *ilm_ptr);

extern kal_bool soc_find_acc_slot(kal_uint8 *idx, kal_uint32 acc_id);

extern void soc_account_pool_initialize(socket_context_struct *pool_ptr);

extern kal_int8 soc_do_activate_nwk_account(socket_struct *so,
                                  soc_app_proc_struct *app_proc, 
                                  kal_uint32 account_id);

extern kal_int8 soc_activate_nwk_account(socket_struct *so);

extern kal_int8 soc_deactivate_nwk_account(soc_app_id_struct *app,
                                           soc_app_account_struct *acc,
                                           kal_bool is_deact_by_soc);

extern void soc_add_socket_to_account(kal_uint32 id);

extern kal_bool is_valid_nwk_acct_id(kal_uint32 account_id);

extern void soc_auto_disc_check(kal_uint32 nw_acc_id);

extern kal_bool soc_is_bearer_ready(kal_uint32 account_id, kal_uint8 qos_id);

extern kal_bool soc_is_mod_bypass_ip(module_type mod_id);

extern kal_bool soc_is_bearer_existed(kal_bool by_type, cbm_bearer_enum bearer_type,
                                      kal_bool by_account_id, kal_uint32 account_id);

extern void soc_abm_notify_app_bearer_ready(kal_uint32 account_id, kal_uint8 qos_id);

extern
void soc_send_deactivate_req_to_abm(module_type src_mod_id,
                                    kal_uint32 acct_id,
                                    kal_uint8 qos_profile_id,
                                    kal_uint8 context_id,
                                    kal_uint16 cause);
extern
void soc_send_msg_to_abm(module_type src_mod_id,
                         kal_uint16 msg_id,
                         local_para_struct *local_para_ptr,
                         peer_buff_struct *peer_buff_ptr);

extern cbm_bearer_enum soc_abm_get_bearer(kal_uint32 acct_id);

extern void soc_reset_acc_slot(soc_account_struct *acct, kal_uint8 qos_id);

extern void soc_reset_nwk_status(kal_uint32 account_id, kal_uint8 qos_id);

#ifdef __APP_SECONDARY_PDP_SUPPORT__
extern kal_int8 soc_send_resume_qos_ctx_req_to_abm(kal_uint8 qos_profile);
#endif /* __APP_SECONDARY_PDP_SUPPORT__ */

#if defined(AUTO_DISCONNECT_BEARER) || defined(AUTO_DISCONNECT_GPRS_BEARER)
extern void soc_abm_start_auto_disc(kal_uint32 nw_acc_id);
extern void soc_abm_stop_auto_disc(kal_uint32 nw_acc_id);
#endif /* AUTO_DISCONNECT_BEARER */ 

kal_bool soc_free_pdp_slot(kal_uint8 qos_profile);

extern void soc_send_activate_req_to_abm(module_type src_mod_id,
                                         kal_uint32 acct_id, kal_uint8 qos_profile,
                                         kal_uint16 cause);
extern void soc_abm_activate_cnf_hdlr(soc_abm_activate_cnf_struct *cnf);
extern void soc_abm_deactivate_cnf_hdlr(soc_abm_deactivate_cnf_struct *cnf);
#endif /* !_SOC_ABM_H */

