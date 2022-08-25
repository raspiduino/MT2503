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
 *	l4a_cmd.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for L4A.
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
#ifdef __MOD_L4A__
//#include "kal_non_specific_general_types.h"
//#include "kal_release.h"      	/* Basic data type */
//#include "stack_common.h"
//#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
//#include "stacklib.h"        	/* Basic type for dll, evshed, stacktimer */
//#include "app_buff_alloc.h"
//#include "stack_timer.h"
//#include "event_shed.h"

//#include "l4a.h"
//#include "l4a_cmd.h"
//#include "csmss_aux_msg_hdlr.h"
//#include "mnsms_struct.h"
//#include "smsal_peer_struct.h"
//#include "l3_inc_enums.h"
//#include "smsal_structs.h"
//#include "smsal_cb.h"

#include "layer4_context.h"

//#include "l4_trc.h"
#include "rmmi_parser.h"
#include "l4c_common_enum.h"
//#include "med_struct.h"
#include "med_aud_hal_struct.h"
#include "l4c_eq_cmd.h"
#include "l4c_ss_parse.h"
#include "rmmi_context.h"
#include "rmmi_common_enum.h"
#include "l4c_cc_cmd.h"
#include "l4c_nw_cmd.h"
//#include "l4c_aux_struct.h"
#include "l4c_sms_cmd.h"
//#include "smsal_l4c_enum.h"
#include "l4c2smsal_struct.h"
#include "l4c_sim_cmd.h"
#include "ps2sat_struct.h"
#include "string.h"
#include "mcd_ps2sat_peer.h"
#include "l4c2csm_cc_struct.h"
#include "l4c_context.h"
#include "mcd_l4_common.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "kal_public_api.h"

/*
* FUNCTION                                                            
*	l4a_eq_get_audio_profile_req
* DESCRIPTION                                                           
*	send get audio profile request to l4c
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_eq_get_audio_profile_req(kal_uint8 src_id,
										audio_profile_struct* audio_prof_in)
{
//	*audio_prof_out = *audio_prof_in;
	return l4c_eq_get_audio_profile_req(src_id,audio_prof_in->mode);
}


#if defined(__NONE_USED_L4MMI_MESSAGE__)
/*
* FUNCTION                                                            
*	l4a_wap_cc_send_dtmf_req
* DESCRIPTION                                                           
*	send dtmf request to l4a
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_wap_cc_send_dtmf_req(kal_uint8 src_id, kal_uint8 digit)
{
	//mtk01616_081119:if call_id is not specified,modem will decide the call_id
	return l4c_cc_exe_send_dtmf_req(WAP_SRC,digit,0,RMMI_MAX_CMD_NUM);
}
/*
* FUNCTION                                                            
*	l4a_wap_cc_stop_dtmf_req
* DESCRIPTION                                                           
*	send stop dtmf request to l4a
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_wap_cc_stop_dtmf_req(kal_uint8 src_id)
{
	//mtk01616_081119:if call_id is not specified,modem will decide the call_id
	return l4c_cc_exe_stop_dtmf_req(WAP_SRC,0);
}
/*
* FUNCTION                                                            
*	l4a_wap_cc_call_setup_req
* DESCRIPTION                                                           
*	send call setup request to l4a
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_wap_cc_call_setup_req(kal_uint8 src_id, l4c_number_struct dest, kal_uint8 redial_count, kal_uint8 call_type, kal_uint8 clir_flag, kal_bool cug_option)
{
	return l4c_cc_exe_call_setup_req(WAP_SRC,
		dest,redial_count,call_type,clir_flag,cug_option,ALS_DIAL_BY_SETTING,INFO_ECC_CHECK_BY_MODEM);
}
/*
* FUNCTION                                                            
*	l4a_wap_phb_exe_write_entry_req
* DESCRIPTION                                                           
*	send phonebook write entry request to l4a
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_wap_phb_exe_write_entry_req(kal_uint8 src_id, kal_uint8 type, kal_uint16 no_data, l4c_phb_entry_struct* list)
{
	return l4c_phb_exe_write_entry_req(WAP_SRC,type,no_data,list);
}
#endif

/*
* FUNCTION                                                            
*	l4a_ss_string_req
* DESCRIPTION                                                           
*	send ss string request to l4c
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_ss_string_req (kal_uint8 src_id,
	    kal_uint8	input[MAX_DIGITS_USSD],
	    kal_uint8	dcs,
	    kal_uint8	length,
	    kal_uint8	ip_string[21],
	    kal_uint8	source_id,
        kal_uint8   call_type,
        kal_bool    is_sim_operation,
        kal_uint8   als_type,
        kal_uint8   ecc_info) 
{
	l4c_ss_string_info_struct info;
	rmmi_string_struct string;
    kal_bool ret_val;

    input[length] = RMMI_END_OF_STRING_CHAR;
	string.index = 0;
	string.string_ptr = input;
	string.ip_string = ip_string; 

	#ifdef __UCM_SUPPORT__
		src_id = source_id;
	#endif

	ret_val = l4c_ss_string_parsing(src_id,dcs,&string,length,&info, call_type, is_sim_operation,als_type,ecc_info);

    #if  defined(__FWP_NC_LAI_INFO__)		
 		L4C_PTR->is_cell_lock_call = KAL_FALSE;
	#endif

	return ret_val;
}


kal_bool l4a_cc_exe_ata_req (kal_uint8 src_id,kal_uint8 source_id)
{
	#ifdef __UCM_SUPPORT__
		src_id = source_id;
	#endif
	
	return l4c_cc_exe_ata_req(src_id);
}

kal_bool l4a_cc_exe_ath_req (kal_uint8 src_id,l4c_ath_req_enum op_code,kal_uint8 source_id)
{
#ifndef __UCM_SUPPORT__
  return l4c_cc_exe_ath_req(src_id,op_code);
#else 
  return KAL_TRUE;
#endif 
}

kal_bool l4a_cc_exe_chld_req (kal_uint8 src_id,
                                 kal_uint8 opcode,   /* csmcc_crss_req_enum */
                                 kal_uint8 call_id,
                                 kal_uint8 source_id)
{
    kal_bool ret_val;

    #ifdef __UCM_SUPPORT__
    src_id = source_id;
    #endif

    ret_val = l4c_cc_exe_chld_req(src_id, opcode, call_id);

    #if defined(__UCM_SUPPORT__) && defined(__BT_SUPPORT__) 
    if ((ret_val == KAL_FALSE )&&(source_id == RMMI_COMM_PTR->rmmi_hf_src) && (RMMI_PTR->send_ciev_callheld == KAL_TRUE))
    {
        RMMI_PTR->send_ciev_callheld = KAL_FALSE;
    }
    #endif

    return ret_val;
}


/*
* FUNCTION                                                            
*	l4a_cc_exe_send_dtmf_req
* DESCRIPTION                                                           
*	send dtmf request to l4c
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_cc_exe_send_dtmf_req(kal_uint8 src_id, kal_uint8 digit,kal_uint8 call_id)
{
	//mtk01616_081119:if call_id is not specified,modem will decide the call_id
	return l4c_cc_exe_send_dtmf_req(src_id,digit,call_id,RMMI_MAX_CMD_NUM);
}

//FastCampOn 20081104
kal_bool l4a_nw_exe_cops_req(kal_uint8 src_id, kal_uint8 opcode, kal_uint8 * oper, kal_uint8 rat)
{
    return (kal_bool) l4c_nw_exe_cops_req(src_id, opcode, oper, rat, 0xFFFF, 0);
}

//mtk01616_080830: MMI SMS use LMMI_SRC to do foreground action and LMMI_SRC2 to do background action
kal_bool l4a_sms_exe_post_command_req(
                    kal_uint8 src_id,
                    kal_uint8 fo,
                    kal_uint8 ct,
                    kal_uint8 mn,
                    kal_uint8 pid,
                    l4c_number_struct dest,
                    kal_uint8 length,
                    kal_uint8 *cmd,
                    kal_uint8 source_id)
{
	return  l4c_sms_exe_post_command_req(source_id,fo,ct,mn,pid,dest,length,cmd);
}

kal_bool l4a_sms_exe_delete_msg_req(
                    kal_uint8 src_id,
                    kal_uint8 del_flag,
                    kal_uint16 index,
                    kal_uint8 *del_bitmap,
                    kal_uint8 source_id)
{
	return l4c_sms_exe_delete_msg_req(source_id,del_flag,index,del_bitmap);
}


kal_bool l4a_sms_send_from_storage_req(
                    kal_uint8 src_id,
                    kal_uint16 index,
                    kal_bool addr_present,
                    l4c_number_struct da,
                    kal_uint8 source_id,
                    kal_uint8 profile_no_tag,
                    kal_uint8 profile_no)
{
	return l4c_sms_send_from_storage_req(source_id,index,addr_present,da,profile_no_tag,profile_no);
}
kal_bool l4a_sms_set_status_req(
                    kal_uint8 src_id,
                    kal_uint8 new_status,
                    kal_uint16 index,
		      kal_uint8 source_id)
{
	return l4c_sms_set_status_req(source_id,new_status,index);
}                    

kal_bool l4a_sms_exe_read_msg_req(kal_uint8 src_id, kal_uint16 index, kal_bool change_status,kal_uint8 source_id)
{
	return l4c_sms_exe_read_msg_req(source_id,index,change_status);
}	

//mtk01616_080830
kal_bool l4a_sms_exe_post_msg_req(
                    kal_uint8 src_id,
                    kal_uint8 profile,
                    kal_uint16 reply_index,
                    l4c_number_struct dest,
                    kal_uint16 para,
                    l4c_number_struct sc_addr,
                    kal_uint8 vp,
                    smsal_pid_enum pid,
                    kal_uint8 udhi,
                    smsal_dcs_enum dcs,
                    kal_uint16 length,
                    kal_uint8 *msg,
                    kal_uint8 seq_num,
                    kal_uint8 mms_mode,
                    kal_uint8 source_id,
                    kal_uint8 tp_srr,
                    kal_uint8 tp_rp)
{
	return l4c_sms_exe_post_msg_req(source_id,profile,reply_index,dest,para,sc_addr,vp,
										pid,udhi,dcs,length,msg,seq_num,mms_mode,tp_srr,tp_rp);
}                    

kal_bool l4a_sms_exe_write_msg_req(
                    kal_uint8 src_id,
                    kal_uint8 profile,
                    kal_uint8 status,
                    l4c_number_struct dest,
                    kal_uint16 para,
                    l4c_number_struct sc_addr,
                    kal_uint8 *scts,
                    kal_uint8 vp,
                    kal_uint8 pid,
                    kal_uint8 udhi,
                    kal_uint8 dcs,
                    kal_uint16 index,
                    kal_uint16 length,
                    kal_uint8 *msg,
                    kal_uint8 source_id,
                    kal_uint8 tp_srr, 
                    kal_uint8 tp_mms,
                    kal_uint8 tp_rp,
                    kal_uint8 tp_sri)
{
	return l4c_sms_exe_write_msg_req(source_id,profile,status,dest,para,sc_addr,scts,
										vp,pid,udhi,dcs,index,length,msg,tp_srr,tp_mms,tp_rp,tp_sri);
}

kal_bool l4a_sms_exe_abort_req(kal_uint8 src_id,kal_uint8 source_id, kal_uint8 seq_num)
{
	l4c_sms_exe_abort_req(source_id, seq_num);
	return KAL_TRUE;
}	

kal_bool l4a_sms_copy_msg_req(kal_uint8 src_id, kal_uint8 action, kal_uint8 dst_storage, kal_uint16 src_index,kal_uint8 source_id)
{
	return l4c_sms_copy_msg_req(source_id,action,dst_storage,src_index);
}	
	
kal_bool l4a_sms_get_preferred_mem_req(kal_uint8 src_id, smsal_prefer_storage_struct *info)
{
    l4c_sms_get_preferred_mem_req(src_id, info);
    return KAL_TRUE;
}
	
kal_bool l4a_sms_reg_port_num_req(
                    kal_uint8 src_id,
                    kal_bool enable,
                    kal_uint32 port_num,
                    kal_uint16 mod_id,
                    kal_uint8 source_id,
                    kal_uint16 *cause,
                    kal_uint32 *ret_port_num,
                    kal_uint16 *ret_mod_id,
                    kal_uint8 *ret_source_id)
{
	return l4c_sms_reg_port_num_req(source_id,enable,port_num,mod_id,cause,ret_port_num,ret_mod_id,ret_source_id);
}	

kal_bool l4a_sms_exe_send_smma_req(kal_uint8 src_id,kal_uint8  source_id)
{
	return l4c_sms_exe_send_smma_req(source_id);
}

kal_bool l4a_sms_exe_set_msg_waiting_req(kal_uint8 src_id,kal_uint8  source_id,kal_uint8  line_no,kal_uint8  waiting_num,kal_uint8  ind_type)
{
	return l4c_sms_exe_set_msg_waiting_req(source_id,line_no,waiting_num,ind_type);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if defined(__NONE_USED_L4MMI_MESSAGE__)
/*
* FUNCTION                                                            
*	l4a_set_timer_req
* DESCRIPTION                                                           
*	set timer to l4c
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_set_timer_req(void* timeout_hdlr, kal_uint16 time, void *param,eventid *id,void **ret_param)
{
	*ret_param = param;
	*id = l4c_set_timer_req(timeout_hdlr,time,param);
	return KAL_TRUE;
}
#endif
/*
* FUNCTION                                                            
*	l4a_eq_write_nvram_req
* DESCRIPTION                                                           
*	send write nvram request to l4c
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_eq_write_nvram_req(
            kal_uint8 src_id,
            kal_uint16 file_idx,
            kal_uint16 para,
            kal_uint16 length,
            kal_uint8 *data)
{

	return l4c_eq_write_nvram_req(src_id,file_idx,para,data,length);
}
/*
* FUNCTION                                                            
*	l4a_smu_get_preferred_oper_list_req
* DESCRIPTION                                                           
*	send get preferred operator list request to l4c
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_smu_get_preferred_oper_list_req(kal_uint8 src_id, kal_uint8 index, kal_uint16 num, kal_uint16 file_idx_req, kal_uint16* retnum, kal_uint8* oper_list, kal_uint8* rat_list, kal_uint16* file_idx_rsp)
{
	*retnum = num;
	return l4c_smu_get_preferred_oper_list_req(src_id,index,file_idx_req,retnum,oper_list,rat_list,file_idx_rsp);
}

#ifdef __SAT__
#define STRUCT_ASSIGN_VALUE(DEST,MEMBER)     DEST.MEMBER = MEMBER
#define STRUCT_ASSIGN_ARRAY(DEST,MEMBER,LEN) memcpy(DEST.MEMBER,MEMBER,LEN)

/*
* FUNCTION                                                            
*	l4a_sat_dspl_text_res
* DESCRIPTION                                                           
*	simtoolkit display text res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_dspl_text_res(
								kal_uint8 cmd_detail[5],
								kal_uint8 res,
								kal_uint8 additional_info)
{
	sat_dspl_text_res_struct l;

	STRUCT_ASSIGN_ARRAY(l,cmd_detail,5);
	STRUCT_ASSIGN_VALUE(l,res);
	STRUCT_ASSIGN_VALUE(l,additional_info);

	return l4c_sat_dspl_text_res(&l);
}
/*
* FUNCTION                                                            
*	l4a_sat_get_input_res
* DESCRIPTION                                                           
*	simtoolkit get input res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_get_inkey_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res,
									kal_uint8 is_yes_selected,

									kal_uint8 dcs_of_text_string,
									kal_uint8 no_text_string,
									kal_uint8 text_string[1]
									)
{
	sat_get_inkey_res_struct l;
	sat_get_inkey_res_peer_struct p;

	STRUCT_ASSIGN_ARRAY(l,cmd_detail,5);
	STRUCT_ASSIGN_VALUE(l,res);	
	STRUCT_ASSIGN_VALUE(l,is_yes_selected);	
	STRUCT_ASSIGN_VALUE(p,dcs_of_text_string);	
	STRUCT_ASSIGN_VALUE(p,no_text_string);
	STRUCT_ASSIGN_VALUE(p,text_string);

	return l4c_sat_get_inkey_res(&l,&p);
}
/*
* FUNCTION                                                            
*	l4a_sat_get_input_res
* DESCRIPTION                                                           
*	simtoolkit get input res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_get_input_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res,

									kal_uint8 dcs_of_text_string,
									kal_uint8 no_text_string,
									kal_uint8 text_string[1]
									)
{
	sat_get_input_res_struct l;
	sat_get_input_res_peer_struct p;

	STRUCT_ASSIGN_ARRAY(l,cmd_detail,5);
	STRUCT_ASSIGN_VALUE(l,res);	
	
	STRUCT_ASSIGN_VALUE(p,dcs_of_text_string);	
	STRUCT_ASSIGN_VALUE(p,no_text_string);
	STRUCT_ASSIGN_VALUE(p,text_string);

	return l4c_sat_get_input_res(&l,&p);
}
/*
* FUNCTION                                                            
*	l4a_sat_setup_menu_res
* DESCRIPTION                                                           
*	simtoolkit setup menu res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_setup_menu_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res

								)
{
	sat_setup_menu_res_struct l;

	STRUCT_ASSIGN_ARRAY(l,cmd_detail,5);
	STRUCT_ASSIGN_VALUE(l,res);	

	return l4c_sat_setup_menu_res(&l);
}
/*
* FUNCTION                                                            
*	l4a_sat_select_item_res
* DESCRIPTION                                                           
*	simtoolkit select item res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_select_item_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res,
									kal_uint8 item_id
								 )
{
	sat_select_item_res_struct l;

	STRUCT_ASSIGN_ARRAY(l,cmd_detail,5);
	STRUCT_ASSIGN_VALUE(l,res);	
	STRUCT_ASSIGN_VALUE(l,item_id);	

	return l4c_sat_select_item_res(&l);
}
/*
* FUNCTION                                                            
*	l4a_sat_play_tone_res
* DESCRIPTION                                                           
*	simtoolkit play tone res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_play_tone_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res
								)
{
	sat_play_tone_res_struct l;

	STRUCT_ASSIGN_ARRAY(l,cmd_detail,5);
	STRUCT_ASSIGN_VALUE(l,res);		

	return l4c_sat_play_tone_res(&l);
}
/*
* FUNCTION                                                            
*	l4a_sat_exe_menu_select_req
* DESCRIPTION                                                           
*	simtoolkit execute the menu select request
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_exe_menu_select_req(
									 kal_uint8 item_id,
									 kal_uint8 is_help_info_requested
									 )
{
	sat_menu_select_req_struct l;

	STRUCT_ASSIGN_VALUE(l,item_id);
	STRUCT_ASSIGN_VALUE(l,is_help_info_requested);

	return l4c_sat_exe_menu_select_req(&l);
}
/*
* FUNCTION                                                            
*	l4a_sat_call_setup_req
* DESCRIPTION                                                           
*	simtoolkit call setup request
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_call_setup_req(
								kal_uint8 sat_call_type,
								kal_uint8 no_addr,
								kal_uint8 addr[41],
								kal_uint8 no_sub_addr,
								kal_uint8 sub_addr[21],
								kal_uint8 no_ccp,
								kal_uint8 ccp[MAX_SAT_SIZE_OF_CCP], //MAUI_02863694
								kal_uint8 type_of_modification
								)
{
    kal_bool ret_val;
    l4ccsm_cc_sat_setup_req_struct *l= NULL;
    l  = get_ctrl_buffer((kal_uint16)sizeof(l4ccsm_cc_sat_setup_req_struct));
    kal_mem_set(l,0,sizeof(l4ccsm_cc_sat_setup_req_struct));

    l->src_id = SAT_SRC;
    l->sat_call_type = sat_call_type;

    l->called_sub_addr_present = (no_sub_addr)?1:0;

    l->called_sub_addr.sub_addr_len = no_sub_addr;
    memcpy(l->called_sub_addr.sub_addr,sub_addr,21);

    l->ccp_present = (no_ccp)?1:0;
    memcpy(l->ccp, ccp, MAX_SAT_SIZE_OF_CCP); //MAUI_02863694
    l->size_of_ccp = no_ccp;

    l->type_of_modification = type_of_modification; 
    l->l4c_retry = KAL_FALSE;
    //mtk01616_090417: apply clir option setting for sat callsetup
    if (L4C_PTR->clir_flag == CLIR_AUTO)
    {
        l->clir_info_present = KAL_FALSE;
    }
    else
    {
        l->clir_info_present = KAL_TRUE;
        l->clir_info = L4C_PTR->clir_flag;
    }

    if(no_addr > 0 && addr[0] == 0xa1)
        addr[0] = 0x81;
	   	
    ret_val = l4c_sat_call_setup_req(l, addr, (kal_uint16)no_addr);
    free_ctrl_buffer(l);
   
    return ret_val;
}
/*
* FUNCTION                                                            
*	l4a_sat_setup_call_res
* DESCRIPTION                                                           
*	simtoolkit setup call res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_setup_call_res(
								kal_uint8 cmd_detail[5],
								kal_uint8 res,
								kal_uint8 cause
								)
{
	sat_setup_call_res_struct *l=(sat_setup_call_res_struct *)
				           construct_local_para((kal_uint16)sizeof(sat_setup_call_res_struct),
                                             TD_RESET);
	memcpy(l->cmd_detail,cmd_detail,5);
	l->res = res;
	l->cause = cause;

	return l4c_sat_setup_call_res(l);
}
/*
* FUNCTION                                                            
*	l4a_sat_send_sms_req
* DESCRIPTION                                                           
*	simtoolkit send sms request
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_send_sms_req(
								kal_uint8 is_sms_packed_required,
								kal_uint8 no_addr,
								kal_uint8 addr[41],
								kal_uint8 tpdu_length,
								kal_uint8 tpdu[175]
							  )
{
	l4csmsal_sat_send_req_struct *l=(l4csmsal_sat_send_req_struct *)
				           construct_local_para((kal_uint16)sizeof(l4csmsal_sat_send_req_struct),
                                             TD_RESET);
	l->src_id = LMMI_SRC;
	l->is_sms_packed_required = is_sms_packed_required;
	l->sc_addr.addr_length = no_addr;
	memcpy(l->sc_addr.addr_bcd,addr,no_addr);

    l->tpdu_length = tpdu_length;
	memcpy(l->tpdu,tpdu,175);

	return l4c_sat_send_sms_req(l);
}
/*
* FUNCTION                                                            
*	l4a_sat_send_sms_res
* DESCRIPTION                                                           
*	simtoolkit send sms res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_send_sms_res(
							  kal_uint8 cmd_detail[5],
							  kal_uint8 res,
							  kal_uint8 cause
							  )
{
	sat_send_sms_res_struct* l= (sat_send_sms_res_struct *)
				           construct_local_para((kal_uint16)sizeof(sat_send_sms_res_struct),
                                             TD_RESET);
	memcpy(l->cmd_detail,cmd_detail,5);
	l->res = res;
	l->cause = cause;

	return l4c_sat_send_sms_res(l);
}
/*
* FUNCTION                                                            
*	l4a_sat_send_ss_res
* DESCRIPTION                                                           
*	simtoolkit send ss string res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_send_ss_res(
							 kal_uint8 cmd_detail[5],
							 kal_uint8 res,
							 kal_uint8 size_of_additional_info,
							 kal_uint8 additional_info[255]
							 )
{
	sat_send_ss_res_struct* l= (sat_send_ss_res_struct *)
				           construct_local_para((kal_uint16)sizeof(sat_send_ss_res_struct),
                                             TD_RESET);
	memcpy(l->cmd_detail,cmd_detail,5);
	l->res = res;
	l->size_of_additional_info = size_of_additional_info;
	memcpy(l->additional_info,additional_info,255);

	return l4c_sat_send_ss_res(l);
}

/*
* FUNCTION                                                            
*	l4a_sat_send_ussd_res
* DESCRIPTION                                                           
*	simtoolkit send ussd string res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_send_ussd_res(
							  kal_uint8 cmd_detail[5],
							  kal_uint8 res,
							 kal_uint8 size_of_additional_info,
							 kal_uint8 additional_info[255]
							   )
{
	sat_send_ussd_res_struct* l= (sat_send_ussd_res_struct *)
				           construct_local_para((kal_uint16)sizeof(sat_send_ussd_res_struct),
                                             TD_RESET);
	memcpy(l->cmd_detail,cmd_detail,5);
	l->res = res;
	l->size_of_additional_info = size_of_additional_info;
	kal_mem_cpy(l->additional_info, additional_info, size_of_additional_info);

	return l4c_sat_send_ussd_res(l);
}

/*
* FUNCTION                                                            
*	l4a_sat_setup_idle_dspl_res
* DESCRIPTION                                                           
*	simtoolkit setup idle screen display res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_setup_idle_dspl_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res
								)
{
	sat_setup_idle_dspl_res_struct* l= (sat_setup_idle_dspl_res_struct *)
				           construct_local_para((kal_uint16)sizeof(sat_setup_idle_dspl_res_struct),
                                             TD_RESET);

	memcpy(l->cmd_detail, cmd_detail, 5);
	l->res = res;

	return l4c_sat_setup_idle_dspl_res(l);
}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*
* FUNCTION                                                            
*	l4a_sat_lang_notify_res
* DESCRIPTION                                                           
*	simtoolkit language notify res
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_sat_lang_notify_res(
									kal_uint8 cmd_detail[5],
									kal_uint8 res
								)
{
	sat_lang_notify_res_struct* l= (sat_lang_notify_res_struct *)
				           construct_local_para((kal_uint16)sizeof(sat_lang_notify_res_struct),
                                             TD_RESET);

	memcpy(l->cmd_detail, cmd_detail, 5);
	l->res = res;

	return l4c_sat_lang_notify_res(l);
}


#endif // __SAT__

/*
* FUNCTION                                                            
*	l4a_eq_exe_volume_req
* DESCRIPTION                                                           
*	send execute volume request to l4c
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_eq_exe_volume_req(kal_uint8 src_id,
                                kal_uint8 volume_type,
                                kal_uint8 volume_level,
								kal_uint8 *ret_volume_type)
{
	*ret_volume_type = volume_type;
	return l4c_eq_exe_volume_req(src_id,volume_type,volume_level);
}
/*
* FUNCTION                                                            
*	l4a_eq_exe_mute_mode_req
* DESCRIPTION                                                           
*	send execute mute volume request
* CALLS  
* 	l4a_recv_msg
* PARAMETERS
* 	src_id: LMMI_SRC
* RETURNS
* 	none
* GLOBALS AFFECTED
*   none
*/
kal_bool l4a_eq_exe_mute_mode_req(kal_uint8 src_id, kal_uint8 audio_device, kal_bool mute_onoff,kal_uint8 *ret_audio_device)
{
	*ret_audio_device = audio_device;
	return l4c_eq_exe_mute_req(src_id,audio_device,mute_onoff);
}

#endif


