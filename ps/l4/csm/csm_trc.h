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
 *	csm_trc.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is trace map definition.
 *
 * Author:
 * -------
 * -------
 *
  *==============================================================================
 * 				HISTORY
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

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#ifndef _CSM_TRC_H
#define _CSM_TRC_H

#ifndef GEN_FOR_PC

   //#ifndef _STACK_CONFIG_H
   //#error "stack_config.h should be included before tst_config.h"
   //#endif

#else
   #include "kal_trace.h"
#endif /* GEN_FOR_PC */


//#ifndef _KAL_TRACE_H
//   #error "kal_trace.h should be included before tst_trace.h"
//#endif

#include "stack_config.h"
#include "kal_trace.h"

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "csm_trc_gen.h"
#endif /* TST Trace Defintion */
#endif

BEGIN_TRACE_MAP(MOD_CSM)

   /***************TRC MSG FOR CSM CC BEGIN ********************/
   /* TRACE_FUNC trace class */
   TRC_MSG(FN_ENTRY_csmcc_dtmf_pause_timeout_handler, "->csmcc_dtmf_pause_timeout_handler()")
   TRC_MSG(FN_EXIT_csmcc_dtmf_pause_timeout_handler, "csmcc_dtmf_pause_timeout_handler()->")
    TRC_MSG(FN_ENTRY_csmcc_start_dtmf_pause_timer, "->csmcc_start_dtmf_pause_timer()")
   TRC_MSG(FN_ENTRY_csmcc_aoc_timeout_handler, "->csmcc_aoc_timeout_handler()")
   TRC_MSG(FN_EXIT_csmcc_aoc_timeout_handler, "csmcc_aoc_timeout_handler()->")
   TRC_MSG(FN_ENTRY_csmcc_start_aoc_timer, "->csmcc_start_aoc_timer()")
   TRC_MSG(FN_ENTRY_csmcc_stop_aoc_timer, "->csmcc_stop_aoc_timer()")
   TRC_MSG(FN_ENTRY_csmcc_rlc_timeout_handler, "->csmcc_rlc_timeout_handler()")
   TRC_MSG(FN_EXIT_csmcc_rlc_timeout_handler, "csmcc_rlc_timeout_handler()->")
   TRC_MSG(FN_ENTRY_csmcc_start_rlc_timer, "->csmcc_start_rlc_timer()")
   TRC_MSG(FN_ENTRY_csmcc_stop_rlc_timer, "->csmcc_stop_rlc_timer()")
   TRC_MSG(FN_ENTRY_csmcc_mncc_rel_cnf_handler, "->csmcc_mncc_rel_cnf_hdlr()")
   TRC_MSG(FN_EXIT_csmcc_mncc_rel_cnf_handler, "csmcc_mncc_rel_cnf_hdlr()->")
   TRC_MSG(FN_ENTRY_l4ccsm_cc_get_cnap_info, "->l4ccsm_cc_get_cnap_info()") //mtk01602:add for CNAP;
   TRC_MSG(FN_ENTRY_csmcc_start_call_confirm_timer, "->csmcc_start_call_confirm_timer()") 
   TRC_MSG(FN_ENTRY_csmcc_call_confirm_timeout_handler, "->csmcc_call_confirm_timeout_handler()")
   TRC_MSG(FN_ENTRY_csmcc_stop_call_confirm_timer, "->csmcc_stop_call_confirm_timer()")
  
   /* TRACE_STATE trace class */
   TRC_MSG(CSMCC_TRACE_STATE_CHANGE, "STATE CHANGE: CALL ID=%d, STATE=%d, MPTY STATE=%d, SRC ID=%d")
   TRC_MSG(CSMCC_TRACE_MPTY_STATE_CHANGE, "MPTY STATE CHANGE: CALL ID=%d, STATE=%d, MPTY STATE=%d, SRC ID=%d")   
   TRC_MSG(CSMCC_TRACE_STATE_INFO, "STATE INFO: CALL ID=%d, STATE=%d, MPTY STATE=%d, SRC ID=%d")

   /* TRACE_INFO trace class */
   TRC_MSG(CSMCC_TRACE_REQUEST_SAVE, "REQUEST SAVE: REQUEST=%Mcsmcc_req_enum, SRC ID=%d, CALL ID=%d")
   TRC_MSG(CSMCC_TRACE_REQUEST_UPDATE, "REQUEST UPDATE: REQUEST=%Mcsmcc_req_enu, SRC ID=%d, CALL ID=%d")
   TRC_MSG(CSMCC_TRACE_AUX_REQUEST_SAVE, "AUX REQUEST SAVE: AUX REQUEST=%d, AUX REQUEST CALL ID=%d, is_aux_proc=%d")
   TRC_MSG(CSMCC_TRACE_CHANNEL_ATTACH_STATUS, "CHANNEL ATTACH STATUS: ATTACH STATUS=%d, CHANNEL INFO=%d")
   TRC_MSG(CSMCC_TRACE_SYNC_IND, "SYNC IND: CAUSE=%Msync_ind_enum, CHANNEL TYPE=%Mchannel_type_enum, CHANNEL MODE=%Mchannel_mode_enum")
   TRC_MSG(CSMCC_TRACE_RAT_IND, "RAT IND: RAT CHANGE FROM %d TO %d")
   TRC_MSG(CSMCC_TRACE_RAT_MODE, "L4C SET RAT MODE FROM %d TO %d")
   TRC_MSG(CSMCC_TRACE_IS_SIM_REPLACED, "csmcc_is_sim_change=%d")
   TRC_MSG(CSMCC_TRACE_TI_AND_CALL_ID, "CSMCC TI=%d, CALL_ID=%d")
   TRC_MSG(CSMCC_TRACE_CTM_STATUS, "CTM STATUS=%d")
   TRC_MSG(CSMCC_TRACE_CCBS_STATUS, "CALL ID=%d, CCBS STATUS=%Mcsmcc_ccbs_status_enum")
   TRC_MSG(CSMCC_TRACE_CNAP_STATUS, "[CNAP] Name Present=%Ml4ccsm_cc_cnap_enum, CNAP info=%d, Tag=%d, Length=%d, dcs=%d")
   TRC_MSG(CSMCC_TRACE_RLC_STATUS, "CALL ID=%d, RLC STATUS=%Mcsmcc_rlc_enum")
   TRC_MSG(CSMCC_TRACE_TIMER_STATUS, "CALL ID=%d, EVENT ID=%d, DURATION=%d")
   TRC_MSG(CSMCC_TRACE_ACM_VALUE, "ACM=%d, PRE_ACM=%d, acm_before_write_sim=%d")

   /* TRACE_WARNING trace class */
   TRC_MSG(CSMCC_TRACE_BC1_CHECK_FAILURE, "BC1 CHECK FAILURE: ITC = %d")
   TRC_MSG(CSMCC_TRACE_BC2_CHECK_FAILURE, "BC2 CHECK FAILURE: ITC = %d")
   TRC_MSG(CSMCC_TRACE_ILLEGAL_INV_ID_RECEIVE, "ILLEGAL INVOKE ID RECEIVE: INVOKE ID = %d")
   TRC_MSG(CSMCC_TRACE_DERIVABLE_INV_ID, "DERIVABLE INVOKE ID")
   TRC_MSG(CSMCC_TRACE_DUPLICATE_L4C_REQ, "DUPLICATE L4C REQUEST RECEIVE = %d")
   TRC_MSG(CSMCC_TRACE_ATTACH_WITHOUT_SYNC_IND,"CSMCC_ATTACH_WITHOUT_SYNC_IND")
   TRC_MSG(CSMCC_TRACE_FILE_CHANGE_FOR_SIM_REFRESH,"FILE_CHANGE_FOR_SIM_REFRESH")
   TRC_MSG(CSMCC_TRACE_CALL_IS_RELEASED,"call has been released")
   TRC_MSG(CSMCC_TRACE_COMMAND_TO_DIFF_SIM,"Call table owned by SIM %Mmodule_type, but receive command from SIM %Mmodule_type")

   /* TRACE_ERROR trace class */   
   TRC_MSG(CSMCC_TRACE_WRONG_CHECK_STATE,"CSMCC GET CALL INFO WITH WRONG STATE:%d")
   TRC_MSG(CSMCC_TRACE_CALL_ID_NOT_MATCHED,"THE CALL ID IS NOT DATA CALL")
   TRC_MSG(CSMCC_TRACE_INVALID_DTMF_DIGIT, "INVALID DTMF DIGIT=%d")
   TRC_MSG(CSMCC_TRACE_SAT_TYPE_OF_MODIFICATION, "Invalid type of modification=%d")
   TRC_MSG(CSMCC_TRACE_NO_CALL,"NO CALL")
   TRC_MSG(CSMCC_TRACE_INVALID_RAT,"INVALID RAT = %d")
   TRC_MSG(CSMCC_TRACE_INVALID_ADDR_LEN, "INVALID ADDRESS LENGTH=%d")//[Cosine 070710] Add for SATCE, Open Channel CSD
   TRC_MSG(CSMCC_TRACE_MCD_UNPACK_ERROR,"MCD UNPACK ERROR, struct_id=%d, ss_error_code=%d")

   /* TRACE_GROUP1 */
   TRC_MSG(CSMCC_TRACE_CLEAR_DTMF, "csmcc_clear_dtmf, call_id=%d")
   TRC_MSG(CSMCC_CALL_INFO, "call_id=%d, orig=%d, state=%d, check_state=%d, cw_flag=%d")
   TRC_MSG(CSMCC_SET_PRE_STATE,"CSMCC SET PRE STATE: call_id=%d, prev_state=%d")
   TRC_MSG(CSMCC_RLC_REQ_CALL_ID, "rel_req call_id=%d")
   TRC_MSG(CSMCC_NOT_REL_SAT_CALL,"CSM NOT release the SAT IDLE call")
   TRC_MSG(CSMCC_VT_CALL_FROM_AT,"this is video call from AT")

   /* TRACE_GROUP2 */
   TRC_MSG(CSMCC_CALL_TYPE_AND_MODE, "CSMCC call type=%d, call mode=%d")
   TRC_MSG(CSMCC_CH_TYPE_AND_CH_MODE, "CSMCC channel_type=%d, channel mode=%d")
   TRC_MSG(CSMCC_ACTIVATE_FAX, "CSMCC_ACTIVATE_FAX")
   
   /* TRACE_GROUP_3 */
   TRC_MSG(CSMCC_READ_CSD_PROF_FROM_NVRAM,"CSMCC_READ_CSD_PROF:PDU SIZE=%d, struct size = %d")
   TRC_MSG(CSMCC_SAT_CSD_PROF_CONTEXT,"CSD_PROF[%d]={%x,%x,%x,%x}")
   TRC_MSG(CSMCC_TRACE_NVRAM_CSD_INFO, "rec num=%d, rec size=%d, batch num=%d, current rec=%d")
   TRC_MSG(CSMCC_TRACE_CSD_CALL, "CSD_CALL: profile_type = %Mcsmcc_profile_type_enum, profile_id = %d") //__DTCNT_SIM_PROFILES_SUPPORT__
   TRC_MSG(CSMCC_CSD_PROF_CONTEXT,"profile_type=%Mcsmcc_profile_type_enum, CSD_PROF[%d]={%x,%x,%x,%x}")
   
   /***************TRC MSG FOR CSM CC END ********************/
   
   /***************TRC MSG FOR CSM SS BEGIN ********************/
   
   /* TRACE_FUNC trace class */
   TRC_MSG(FN_ENTRY_csmss_startup_req_hdlr, "->csmss_startup_req_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_ss_parse_req_hdlr, "->csmss_ss_parse_req_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_ss_ctrl_cnf_hdlr, "->csmss_ss_ctrl_cnf_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_cf_begin_req_hdlr, "->csmss_cf_begin_req_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_cw_begin_req_hdlr, "->csmss_cw_begin_req_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_cb_begin_req_hdlr, "->csmss_cb_begin_req_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_emlpp_begin_req_hdlr, "->csmss_emlpp_begin_req_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_cli_begin_req_hdlr, "->csmss_cli_begin_req_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_ccbs_begin_req_hdlr, "->csmss_ccbs_begin_req_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_pussr_begin_req_hdlr, "->csmss_pussr_begin_req_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_begin_ind_hdlr, "->csmss_begin_ind_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_cf_end_cnf_hdlr, "->csmss_cf_end_cnf_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_cw_end_cnf_hdlr, "->csmss_cw_end_cnf_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_cb_end_cnf_hdlr, "->csmss_cb_end_cnf_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_emlpp_end_cnf_hdlr, "->csmss_emlpp_end_cnf_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_cli_end_cnf_hdlr, "->csmss_cli_end_cnf_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_ccbs_end_cnf_hdlr, "->csmss_ccbs_end_cnf_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_pussr_end_cnf_hdlr, "->csmss_pussr_end_cnf_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_ussr_end_cnf_hdlr, "->csmss_ussr_end_cnf_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_ussn_end_cnf_hdlr, "->csmss_ussn_end_cnf_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_sim_end_cnf_hdlr, "->csmss_sim_end_cnf_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_cb_fac_ind_hdlr, "->csmss_cb_fac_ind_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_ussr_fac_ind_hdlr, "->csmss_ussr_fac_ind_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_ussn_fac_ind_hdlr, "->csmss_ussn_fac_ind_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_cb_fac_res_hdlr, "->csmss_cb_fac_res_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_ussr_fac_res_hdlr, "->csmss_ussr_fac_res_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_ussn_fac_res_hdlr, "->csmss_ussn_fac_res_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_end_res_hdlr, "->csmss_end_res_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_cphs_deactivate_cfu_hdlr, "->csmss_cphs_deactivate_cfu_hdlr()")
   TRC_MSG(FN_ENTRY_csmss_cphs_start_cfu_hdlr, "->csmss_cphs_start_cfu_hdlr()")

   TRC_MSG(FN_ENTRY_csmss_ss_src_call_forward_req, "->csmss_ss_src_call_forward_req()")
   TRC_MSG(FN_ENTRY_csmss_ss_src_call_wait_req, "->csmss_ss_src_call_wait_req()")
   TRC_MSG(FN_ENTRY_csmss_ss_src_call_barring_req, "->csmss_ss_src_call_barring_req()")
   TRC_MSG(FN_ENTRY_csmss_ss_src_emlpp_req, "->csmss_ss_src_emlpp_req()")
   TRC_MSG(FN_ENTRY_csmss_ss_src_interrogate_req, "->csmss_ss_src_interrogate_req()")
   TRC_MSG(FN_ENTRY_csmss_ss_src_ccbs_req, "->csmss_ss_src_ccbs_req()")
   TRC_MSG(FN_ENTRY_csmss_ss_src_ussd_req, "->csmss_ss_src_ussd_req()")
   TRC_MSG(FN_ENTRY_csmss_send_ss_ctrl_req, "->csmss_send_ss_ctrl_req()")
   TRC_MSG(FN_ENTRY_csmss_send_ss_parse_cnf, "->csmss_send_ss_parse_cnf()")
   TRC_MSG(FN_ENTRY_csmss_ss_exe_call_forward_req, "->csmss_ss_exe_call_forward_req()")
   TRC_MSG(FN_ENTRY_csmss_ss_exe_call_wait_req, "->csmss_ss_exe_call_wait_req()")
   TRC_MSG(FN_ENTRY_csmss_ss_exe_call_barring_req, "->csmss_ss_exe_call_barring_req()")
   TRC_MSG(FN_ENTRY_csmss_ss_exe_emlpp_req, "->csmss_ss_exe_emlpp_req()")
   TRC_MSG(FN_ENTRY_csmss_ss_exe_interrogate_req, "->csmss_ss_exe_interrogate_req()")
   TRC_MSG(FN_ENTRY_csmss_ss_exe_ccbs_req, "->csmss_ss_exe_ccbs_req()")
   TRC_MSG(FN_ENTRY_csmss_ss_exe_ussd_req, "->csmss_ss_exe_ussd_req()")

   /* TRACE_STATE trace class */

   /* TRACE_INFO trace class */

   TRC_MSG(CSMSS_D,"D: %d")
   TRC_MSG(CSMSS_DD,"DD: %d, %d")
   TRC_MSG(CSMSS_DDD,"DDD: %d, %d, %d")
   TRC_MSG(CSMSS_DDDD,"DDDD: %d, %d, %d, %d")
   TRC_MSG(CSMSS_DDDDD,"DDDDD: %d, %d, %d, %d, %d")

   /* TRACE_WARNING trace class */

   /* TRACE_ERROR trace class */   
   TRC_MSG(CSMSS_ERR_UNEXPECTED_MESSAGE_SUBOP, "unknow message: %d")
   TRC_MSG(CSMSS_ERR_MSG_CORRUPTED_SUBOP, "local_para_ptr is null")
   TRC_MSG(CSMSS_ERR_NO_FREE_CALL_ID_IN_POOL, "no free call_id in pool")

   TRC_MSG(CSMSS_ERR_ALLOC_NULL_STRING, "alloc null string")

    /***************TRC MSG FOR CSM LCS SS START  ********************/
    /* TRACE_ERROR trace class */   
    TRC_MSG(CSMSS_LCS_DISCARD_DECODE_FAILED, "[LCSUnpack ERROR]: Discard message owing to decode failed")
    TRC_MSG(CSMSS_LCS_ENCODE_FAILED, "[LCSpack ERROR]: Discard message owing to encode failed")

    /***************TRC MSG FOR CSM LCS SS END    ********************/

   /***************TRC MSG FOR CSM SS END ********************/

END_TRACE_MAP(MOD_CSM)
#endif


