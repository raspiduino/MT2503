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
 *  SmsAppUmSap.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to handle the Common SAP between UM and SMS applciation
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_TELEPHONY_SUPPORT__

/**************************************************************
 * Header Files Include
 **************************************************************/
#include "ProtocolEvents.h"
#include "SmsSrvGprot.h"
#include "UMGProt.h"

#include "SmsAppUtil.h"
#include "SmsAppResDef.h"
#include "UnifiedMessageResDef.h"
#include "SmsAppProt.h"
#include "DateTimeGprot.h"
#include "ModeSwitchSrvGProt.h"
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
#ifndef __MMI_MSG_UM_LOW_MEMORY_COST__
#include "app_usedetails.h"
#endif
#endif

#ifndef __UM_SUPPORT__
#include "SmsAppType.h"

#endif

/**************************************************************
* MARCO
**************************************************************/
#ifdef __UM_SUPPORT__
#define MMI_SMS_REPORT_SUBJECT_LEN      60


/**************************************************************
* Structure Declaration
**************************************************************/
#ifdef __MMI_MSG_UM_LOW_MEMORY_COST__
typedef struct
{    
    U32 app_id;
    srv_um_msg_box_enum msg_box_type;
    U16 total_num;
	U16 curr_index;
	MMI_BOOL is_complete;
	MMI_BOOL is_email;
    U16 msg_id[SRV_UM_MAX_GET_MSG_INFO_NUMBER];
    MMI_BOOL result[SRV_UM_MAX_GET_MSG_INFO_NUMBER];
	srv_um_msg_info_struct *msg_info;
} mmi_sms_um_lmc_struct;
#endif /* __MMI_MSG_UM_LOW_MEMORY_COST__ */

typedef struct
{
    srv_um_msg_box_enum msg_box_type;
} mmi_sms_um_del_folder_struct;

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
typedef struct
{
    kal_uint32 app_id;
    srv_um_msg_box_enum um_box_type;
    srv_um_mark_several_op_action_enum action_type;
    U16 curr_index;
    U16 total_num;
    U16 msg_id[SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP];
    MMI_BOOL result[SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP];
} mmi_sms_um_multi_op_cntx_struct;
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */


/**************************************************************
 * Global Variables Declaration
 **************************************************************/



/**************************************************************
 * Global Function Declaration
 **************************************************************/


/**************************************************************
 * Static Variables Defination
 **************************************************************/
static MMI_BOOL mmi_sms_is_in_delete_fodler = MMI_FALSE;

/**************************************************************
 * Static Function Declaration
 **************************************************************/
static MMI_BOOL mmi_sms_um_get_num_req_hdlr(void *inMsg);
static MMI_BOOL mmi_sms_um_get_list_info_req_hdlr(void *inMsg);
static MMI_BOOL mmi_sms_um_get_msg_info_req_hdlr(void *inMsg);
static MMI_BOOL mmi_sms_um_del_folder_req_hdlr(void *inMsg);

static void mmi_sms_um_get_msg_num(
                srv_um_get_msg_num_rsp_struct *rsp_data,
                srv_um_sim_enum um_sim_id);
static MMI_BOOL mmi_sms_um_get_msg_list_info_hdlr(
                    srv_um_get_msg_list_rsp_struct *rsp_data,
                    srv_um_get_msg_list_req_struct *req_data);
static void mmi_sms_um_get_msg_list_info(
                U16 msg_id,
                srv_um_msg_list_struct *list_info,
                srv_um_list_idx_data_union *list_idx_data,
                srv_um_list_idx_enum list_idx_type);
#if !defined(__MMI_MSG_UM_LOW_MEMORY_COST__) || defined (__UNIFIED_MESSAGE_LIST_INDEX_DATA__)
static void mmi_sms_um_get_msg_subject(WCHAR *subject, U16 msg_id, U32 subject_len);
#endif 

#ifdef __MMI_UM_REPORT_BOX__
static MMI_BOOL mmi_sms_um_get_report_list_info_hdlr(
                    srv_um_get_msg_list_rsp_struct *rsp_data,
                    srv_um_get_msg_list_req_struct *req_data);
static void mmi_sms_um_get_report_list_info(
                U16 report_id,
                srv_um_msg_list_struct *list_info,
                srv_um_list_idx_data_union *list_idx_data,
                srv_um_list_idx_enum list_idx_type);
static void mmi_sms_um_get_report_subject(
                WCHAR *subject,
                srv_sms_status_report_struct *report_data,
                U32 subject_len);
#endif /* __MMI_UM_REPORT_BOX__ */

#ifdef __MMI_MSG_UM_LOW_MEMORY_COST__
static void mmi_sms_um_lmc_get_msg_info_hdlr(srv_um_get_msg_info_req_struct *req_data);
static void mmi_sms_um_lmc_init_cntx(
                mmi_sms_um_lmc_struct *lmc_cntx,
                srv_um_get_msg_info_req_struct *req_data);
static void mmi_sms_um_lmc_handle(mmi_sms_um_lmc_struct *lmc_cntx);
static MMI_BOOL mmi_sms_um_lmc_get_info(
                    U16 msg_id,
                	srv_um_msg_info_struct *msg_info,
                    mmi_sms_um_lmc_struct *lmc_cntx);
static void mmi_sms_um_lmc_get_content_req(U16 msg_id, mmi_sms_um_lmc_struct *lmc_cntx);
static void mmi_sms_um_lmc_get_content_rsp(srv_sms_callback_struct* callback_data);
static void mmi_sms_um_lmc_convert_rsp_data(
                srv_um_get_msg_info_rsp_struct *rsp_data,
                mmi_sms_um_lmc_struct *lmc_cntx);
static void mmi_sms_um_lmc_send_rsp(mmi_sms_um_lmc_struct *lmc_cntx);
#else /* __MMI_MSG_UM_LOW_MEMORY_COST__ */
static void mmi_sms_um_get_msg_info_hdlr(srv_um_get_msg_info_req_struct *req_data);
static MMI_BOOL mmi_sms_um_get_msg_info_content(
                    srv_um_msg_info_struct *msg_info,
                    U16 msg_id,
                    srv_um_msg_box_enum msg_box_type);
#endif /* __MMI_MSG_UM_LOW_MEMORY_COST__ */
static void mmi_sms_um_get_msg_common_info(
                srv_um_msg_info_struct *msg_info,
                U16 msg_id,
                srv_um_msg_box_enum msg_box_type);
#ifdef __MMI_UM_REPORT_BOX__
static void mmi_sms_um_get_report_info_hdlr(srv_um_get_msg_info_req_struct *req_data);
static MMI_BOOL mmi_sms_um_get_report_info_content(srv_um_msg_info_struct *msg_info, U16 report_id);
#endif /*__MMI_UM_REPORT_BOX__*/

static void mmi_sms_um_del_folder_callback(srv_sms_callback_struct* callback_data);
static void mmi_sms_um_del_folder_hdlr(MMI_BOOL result, srv_um_msg_box_enum msg_box_type);

static U16 mmi_sms_um_get_box_size(srv_um_msg_box_enum um_box_type, srv_um_sim_enum um_sim_id);
static U16 mmi_sms_um_get_unread_msg_num(srv_um_sim_enum um_sim_id);

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
static MMI_BOOL mmi_sms_um_multi_op_req_hdlr(void *in_msg);
static void mmi_sms_um_multi_op_init(
                mmi_sms_um_multi_op_cntx_struct *cntx,
                srv_um_mark_several_op_req_struct *req_msg);
static void mmi_sms_um_multi_op_hdlr(mmi_sms_um_multi_op_cntx_struct *cntx);
static void mmi_sms_um_multi_op_callback(srv_sms_callback_struct* callback_data);
static void mmi_sms_um_multi_op_send_rsp_to_um(mmi_sms_um_multi_op_cntx_struct *cntx);
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
#ifndef __MMI_MSG_UM_LOW_MEMORY_COST__
static MMI_BOOL mmi_sms_um_traverse_msg_req_hdlr(void *inMsg);
static void mmi_sms_um_send_traverse_msg_rsp(kal_uint32 app_id, kal_uint16 msg_number, kal_bool more, kal_bool result);
static kal_bool mmi_sms_um_traverse_msg(
                    srv_um_msg_box_enum msg_box_type
                    ,kal_int16 start_entry
                    ,kal_uint16 *msg_number
                    ,kal_uint32 *msg_id_set
                #if (MMI_MAX_SIM_NUM >= 2)
                    ,srv_um_sim_enum sim_id
                #endif
                    ,kal_bool *more
                    ,srv_um_detail_field_enum field
                    ,srv_um_traverse_func traverse_func
                    ,kal_int32 user_data
                    );
static void mmi_sms_um_free_traverse_msg_buffer(srv_um_msg_detail_struct *msg_detail);
#endif /* __MMI_MSG_UM_LOW_MEMORY_COST__ */
#endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */

static void mmi_sms_um_send_message(module_type dest_mod, U16 msg_id, void *local_ptr);
static void mmi_sms_send_refresh_ind(srv_um_msg_box_enum msg_box_type, srv_um_refresh_enum refresh_type);


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_sap_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_um_sap_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_NUM_REQ, (PsIntFuncPtr)mmi_sms_um_get_num_req_hdlr, MMI_TRUE);
    mmi_frm_set_multi_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_NUM_REQ, (PsIntFuncPtr)mmi_sms_um_get_num_req_hdlr);
   // mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_LIST_REQ, (PsIntFuncPtr)mmi_sms_um_get_list_info_req_hdlr, MMI_TRUE);
   mmi_frm_set_multi_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_LIST_REQ, (PsIntFuncPtr)mmi_sms_um_get_list_info_req_hdlr);
    //mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_INFO_REQ, (PsIntFuncPtr)mmi_sms_um_get_msg_info_req_hdlr, MMI_TRUE);
    mmi_frm_set_multi_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_INFO_REQ, (PsIntFuncPtr)mmi_sms_um_get_msg_info_req_hdlr);
    //mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_DELETE_FOLDER_REQ, (PsIntFuncPtr)mmi_sms_um_del_folder_req_hdlr, MMI_TRUE);
    mmi_frm_set_multi_protocol_event_handler(MSG_ID_MMI_UM_DELETE_FOLDER_REQ, (PsIntFuncPtr)mmi_sms_um_del_folder_req_hdlr);
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
   // mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_MARK_SEVERAL_OP_REQ, (PsIntFuncPtr)mmi_sms_um_multi_op_req_hdlr, MMI_TRUE);
   mmi_frm_set_multi_protocol_event_handler(MSG_ID_MMI_UM_MARK_SEVERAL_OP_REQ, (PsIntFuncPtr)mmi_sms_um_multi_op_req_hdlr);
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
#ifndef __MMI_MSG_UM_LOW_MEMORY_COST__
    //mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_TRAVERSE_MSG_REQ, (PsIntFuncPtr)mmi_sms_um_traverse_msg_req_hdlr, MMI_TRUE);
    mmi_frm_set_multi_protocol_event_handler(MSG_ID_MMI_UM_TRAVERSE_MSG_REQ, (PsIntFuncPtr)mmi_sms_um_traverse_msg_req_hdlr);
#endif /* __MMI_MSG_UM_LOW_MEMORY_COST__ */
#endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_num_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_sms_um_get_num_req_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_num_req_struct *req_data = (srv_um_get_msg_num_req_struct*)inMsg;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_data->msg_type == SRV_UM_MSG_SMS)
    {
    #if (MMI_MAX_SIM_NUM >= 2)
        srv_um_sim_enum um_sim_id = req_data->sim_id;
    #else /* (MMI_MAX_SIM_NUM >= 2) */
        srv_um_sim_enum um_sim_id = SRV_UM_SIM_ALL;
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        srv_um_get_msg_num_rsp_struct *rsp_data;

        rsp_data = (srv_um_get_msg_num_rsp_struct*)OslConstructDataPtr(sizeof(srv_um_get_msg_num_rsp_struct));

        rsp_data->result = KAL_TRUE; 
        rsp_data->msg_type = SRV_UM_MSG_SMS;

        mmi_sms_um_get_msg_num(rsp_data, um_sim_id);

        mmi_sms_um_send_message(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_NUM_RSP, rsp_data);
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_msg_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void mmi_sms_um_get_msg_num(
                srv_um_get_msg_num_rsp_struct *rsp_data,
                srv_um_sim_enum um_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 inbox_box_size;
    U16 inbox_unread_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inbox_box_size = mmi_sms_um_get_box_size(SRV_UM_MSG_BOX_INBOX, um_sim_id);
    inbox_unread_num = mmi_sms_um_get_unread_msg_num(um_sim_id);

    rsp_data->inbox_unread_msg_number = inbox_unread_num;
    rsp_data->inbox_read_msg_number = inbox_box_size - inbox_unread_num;
    rsp_data->unsent_msg_number = mmi_sms_um_get_box_size(SRV_UM_MSG_BOX_UNSENT, um_sim_id);
    rsp_data->sent_msg_number = mmi_sms_um_get_box_size(SRV_UM_MSG_BOX_SENT, um_sim_id);
    rsp_data->draft_msg_number = mmi_sms_um_get_box_size(SRV_UM_MSG_BOX_DRAFT, um_sim_id);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    rsp_data->archive_msg_number = mmi_sms_um_get_box_size(SRV_UM_MSG_BOX_ARCHIVE, um_sim_id);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    rsp_data->sim_msg_number = mmi_sms_um_get_box_size(SRV_UM_MSG_BOX_SIM, um_sim_id);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __MMI_UM_REPORT_BOX__
    rsp_data->report_msg_number = mmi_sms_um_get_box_size(SRV_UM_MSG_BOX_REPORT, um_sim_id);
#endif /* __MMI_UM_REPORT_BOX__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_list_info_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sms_um_get_list_info_req_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_list_req_struct *req_data = (srv_um_get_msg_list_req_struct*) (inMsg);
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_data->msg_type == SRV_UM_MSG_SMS)
    {
        srv_um_get_msg_list_rsp_struct *rsp_data;

        rsp_data = (srv_um_get_msg_list_rsp_struct*)OslConstructDataPtr(sizeof(srv_um_get_msg_list_rsp_struct));

        rsp_data->msg_type = SRV_UM_MSG_SMS;
        rsp_data->msg_box_type = req_data->msg_box_type;
        rsp_data->start_entry = req_data->start_entry;

    #ifdef __MMI_UM_REPORT_BOX__
        if (req_data->msg_box_type == SRV_UM_MSG_BOX_REPORT)
        {
            rsp_data->result = mmi_sms_um_get_report_list_info_hdlr(rsp_data, req_data);
        }
        else
    #endif /* __MMI_UM_REPORT_BOX__ */
        {
            rsp_data->result = mmi_sms_um_get_msg_list_info_hdlr(rsp_data, req_data);
        }

        mmi_sms_um_send_message(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_LIST_RSP, rsp_data);
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_msg_list_info_hdlr
 * DESCRIPTION
 *  get sms list info
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  start_entry         [IN]        
 *  max_msg_number      [IN]        
 *  msg_number          [?]         
 *  list_info           [?]         
 *  more                [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sms_um_get_msg_list_info_hdlr(
                    srv_um_get_msg_list_rsp_struct *rsp_data,
                    srv_um_get_msg_list_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 list_index = req_data->start_entry;
    srv_sms_box_enum sms_box_type;
    U16 msg_box_size;
    U16 msg_count = 0;
#if (MMI_MAX_SIM_NUM >= 2)
    srv_um_sim_enum um_sim_id = req_data->sim_id;
    srv_sms_sim_enum sms_sim_id = SRV_SMS_SIM_1;
#endif /* (MMI_MAX_SIM_NUM >= 2) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_data->msg_box_type = req_data->msg_box_type;
    rsp_data->start_entry = list_index;

    sms_box_type = (srv_sms_box_enum)mmi_sms_um_um_box_to_sms(req_data->msg_box_type);
    msg_box_size = srv_sms_get_list_size(sms_box_type);       

#if (MMI_MAX_SIM_NUM >= 2)
    /* Get Start List Index */
    if (um_sim_id != SRV_UM_SIM_ALL)
    {
        U16 i ;
        U32 tmp_index = 0;

        sms_sim_id = mmi_sms_um_sim_to_sms_sim(um_sim_id);

        for (i = 0; i < msg_box_size; i++)
        {
            U16 msg_id = srv_sms_get_msg_id(sms_box_type, i);
            
            if (srv_sms_get_msg_sim_id(msg_id) == sms_sim_id)
            {
                if (tmp_index == list_index)
                {
                    list_index = i;
                    break;
                }
                else
                {
                    tmp_index++;
                }
            }
        }
    }
#endif /* (MMI_MAX_SIM_NUM >= 2) */

    while (msg_count < SRV_UM_MAX_GET_MSG_LIST_NUMBER)
    {
        U16 msg_id = srv_sms_get_msg_id(sms_box_type, list_index);

        if (msg_id != SRV_SMS_INVALID_MSG_ID)
        {
        #if (MMI_MAX_SIM_NUM >= 2)
            if ((um_sim_id == SRV_UM_SIM_ALL) ||
                (srv_sms_get_msg_sim_id(msg_id) == sms_sim_id))
        #endif /* (MMI_MAX_SIM_NUM >= 2) */
            {
                mmi_sms_um_get_msg_list_info(
                    msg_id,
                    &rsp_data->list_info[msg_count],
                #ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
                    &rsp_data->list_idx_data[msg_count],
                    req_data->list_idx_type
                #else /* __UNIFIED_MESSAGE_LIST_INDEX_DATA__ */
                    NULL,
                    SRV_UM_LIST_IDX_TIMESTAMP
                #endif /* __UNIFIED_MESSAGE_LIST_INDEX_DATA__ */
                    );

                msg_count++;
            }
  
            list_index++;
        }
        else
        {
            break;
        }
    }

    rsp_data->msg_number = msg_count;

    if (list_index < msg_box_size)
    {
        rsp_data->more = KAL_TRUE;
    }
    else
    {
        rsp_data->more = KAL_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_msg_list_info
 * DESCRIPTION
 *  get sms list info
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_get_msg_list_info(
                U16 msg_id,
                srv_um_msg_list_struct *list_info,
                srv_um_list_idx_data_union *list_idx_data,
                srv_um_list_idx_enum list_idx_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 timestamp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_info->msg_id = msg_id;

    timestamp = srv_sms_get_msg_timestamp_utc_sec(msg_id);
    list_info->timestamp = timestamp;
#if (MMI_MAX_SIM_NUM >= 2)
    list_info->sim_id = mmi_sms_sim_id_to_um_sim(srv_sms_get_msg_sim_id(msg_id));
#endif /* (MMI_MAX_SIM_NUM >= 2) */

#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
    switch(list_idx_type)
    {
        case SRV_UM_LIST_IDX_TIMESTAMP:
            break;

        case SRV_UM_LIST_IDX_MSG_SIZE:
            list_idx_data->msg_size = srv_sms_get_msg_size(msg_id);
            break;

        case SRV_UM_LIST_IDX_MSG_TYPE:
            list_idx_data->msg_type = SRV_UM_MSG_SMS;
            break;

        case SRV_UM_LIST_IDX_SUBJECT:
        {
            mmi_sms_um_get_msg_subject(
                list_idx_data->subject,
                msg_id,
                SRV_UM_MAX_LIST_INDEX_LEN);
            break;
        }

        case SRV_UM_LIST_IDX_ADDRESS:
        {
            S8 *temp_addr;

            temp_addr = (S8*)srv_sms_get_msg_asc_address(msg_id);

            mmi_asc_n_to_ucs2(
                (S8*)list_idx_data->address,
            	temp_addr,
            	SRV_UM_MAX_LIST_INDEX_LEN);

            list_idx_data->address[SRV_UM_MAX_LIST_INDEX_LEN] = 0;                	
            break;
        }

        case SRV_UM_LIST_IDX_READ_STATUS:
        {
            if ((srv_sms_get_msg_status(msg_id) & SRV_SMS_STATUS_UNREAD))
            {
                list_idx_data->read_status = KAL_FALSE;
            }
            else
            {
                list_idx_data->read_status = KAL_TRUE;
            }
            break;
        }

        default:
            MMI_ASSERT(0);
            break;
    }
#endif /* __UNIFIED_MESSAGE_LIST_INDEX_DATA__ */
}


#ifdef __MMI_UM_CONVERSATION_BOX_ENHANCE__
void mmi_sms_update_content_according_to_message_id(U16 msg_id, CHAR *content_buffer)
{
    /* sms internal handler */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum msg_status;
    MMI_ID string_id = 0;
    CHAR *continue_string = (CHAR *)L"...";
    S32 ignore_length = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ignore_length = mmi_ucs2strlen(continue_string);
    msg_status = srv_sms_get_msg_status(msg_id);
    
    if (srv_sms_is_msg_complete(msg_id) == MMI_FALSE)
    {
        string_id = STR_UM_INCOMPLETE_ID;
    }
    else if (srv_sms_get_msg_mti(msg_id) == SRV_SMS_MTI_STATUS_REPORT)
    {
        string_id = STR_SR_DELIVERD_ID;
    }
    else if (msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        string_id = STR_UM_NOT_SUPPORT_ID;
    }

    if (string_id != 0)
    {
        mmi_ucs2cpy((CHAR*)content_buffer, (CHAR*)get_string(string_id));
    }
    
    
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    if (srv_sms_get_msg_pid(msg_id) == SRV_SMS_PID_EMAIL)
    {
        U16 addr_length = 0;
        mmi_msg_get_email_and_subject_from_msgtxt(
            (CHAR *)content_buffer,
            mmi_ucs2strlen((CHAR *)content_buffer),
            NULL,
            (MMI_SMS_MAX_EMAIL_ADDR_LEN * ENCODING_LENGTH),
            NULL,
            0,
            &addr_length, 
            NULL);
        mmi_ucs2ncpy((CHAR *)content_buffer, 
                    (CHAR *)(content_buffer + addr_length * 2), 
                    mmi_ucs2strlen((CHAR *)content_buffer - addr_length);
    }
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
    if (mmi_ucs2strlen(content_buffer) > (MMI_SMS_UM_CONTENT_CACHE_CHARACTOR_NUMBER - ignore_length))
    {
        mmi_ucs2ncpy((CHAR *)(content_buffer + (MMI_SMS_UM_CONTENT_CACHE_CHARACTOR_NUMBER - ignore_length) * ENCODING_LENGTH), 
            (CHAR *)continue_string, 
            ignore_length);
    }

    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
#if (MMI_MAX_SIM_NUM == 2)
    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);
#endif
}
#endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */

#if !defined(__MMI_MSG_UM_LOW_MEMORY_COST__) || defined (__UNIFIED_MESSAGE_LIST_INDEX_DATA__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_msg_subject
 * DESCRIPTION
 *  get sms list info
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_get_msg_subject(WCHAR *subject, U16 msg_id, U32 subject_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum msg_status;
    MMI_ID string_id = 0;
    const CHAR *temp_content;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_status = srv_sms_get_msg_status(msg_id);

    if (srv_sms_is_msg_complete(msg_id) == MMI_FALSE)
    {
        string_id = STR_UM_INCOMPLETE_ID;
    }
    else if (srv_sms_get_msg_mti(msg_id) == SRV_SMS_MTI_STATUS_REPORT)
    {
        string_id = STR_SR_DELIVERD_ID;
    }
    else if (msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        string_id = STR_UM_NOT_SUPPORT_ID;
    }
    
    if(string_id != 0)
    {
        temp_content = (CHAR *)GetString(string_id);
    }
    else
    {
        temp_content = srv_sms_get_msg_content(msg_id);
        if (0 == mmi_ucs2strlen(temp_content))
        {
            temp_content = (CHAR *)GetString(STR_UM_EMPTY_CONTENT_ID);
        }
    }
    subject_len = subject_len > SRV_UM_MAX_SUBJECT_LEN ? SRV_UM_MAX_SUBJECT_LEN : subject_len;
    subject_len = subject_len > SRV_SMS_MSG_INFO_CONTENT_LEN ? SRV_SMS_MSG_INFO_CONTENT_LEN : subject_len;
    mmi_ucs2ncpy(
        (S8*)subject,
        temp_content,
        subject_len);

    subject[subject_len] = '\0';
}
#endif /* !defined(__MMI_MSG_UM_LOW_MEMORY_COST__) || defined (__UNIFIED_MESSAGE_LIST_INDEX_DATA__)*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_msg_info_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sms_um_get_msg_info_req_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_info_req_struct *req_data = (srv_um_get_msg_info_req_struct*)(inMsg);
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_data->msg_type == SRV_UM_MSG_SMS)
    {
    #ifdef __MMI_UM_REPORT_BOX__
        if (req_data->msg_box_type == SRV_UM_MSG_BOX_REPORT)
        {
            mmi_sms_um_get_report_info_hdlr(req_data);
        }
        else
    #endif /* __MMI_UM_REPORT_BOX__ */
        {
        #ifdef __MMI_MSG_UM_LOW_MEMORY_COST__
            mmi_sms_um_lmc_get_msg_info_hdlr(req_data);
        #else /* __MMI_MSG_UM_LOW_MEMORY_COST__ */
            mmi_sms_um_get_msg_info_hdlr(req_data);
        #endif /* __MMI_MSG_UM_LOW_MEMORY_COST__ */
        }
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}


#ifdef __MMI_MSG_UM_LOW_MEMORY_COST__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_lmc_get_msg_info_hdlr
 * DESCRIPTION
 *  handle get message info req from UM
 * PARAMETERS
 *  inMsg       [IN]     Input message data
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_lmc_get_msg_info_hdlr(srv_um_get_msg_info_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_lmc_struct *lmc_cntx;
    U32 alloc_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	alloc_len = sizeof(mmi_sms_um_lmc_struct) + 
					(sizeof(srv_um_msg_info_struct) * req_data->msg_number);

	lmc_cntx = OslMalloc(alloc_len);

	mmi_sms_um_lmc_init_cntx(lmc_cntx, req_data);
	mmi_sms_um_lmc_handle(lmc_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_lmc_init_data
 * DESCRIPTION
 *  initialize the lmc_cntx
 * PARAMETERS
 *  req_info	[IN]	Input request message data
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_lmc_init_cntx(
                mmi_sms_um_lmc_struct *lmc_cntx,
                srv_um_get_msg_info_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lmc_cntx->app_id = req_data->app_id;
	lmc_cntx->msg_box_type = req_data->msg_box_type;

	lmc_cntx->total_num = req_data->msg_number;
	lmc_cntx->curr_index = 0;

    for (i = 0; i < SRV_UM_MAX_GET_MSG_INFO_NUMBER; i++)
    {
    	lmc_cntx->msg_id[i] = (U16)req_data->msg_id[i];
        lmc_cntx->result[i] = MMI_FALSE;
    }

	lmc_cntx->msg_info = (srv_um_msg_info_struct*)((U8*)lmc_cntx + sizeof(mmi_sms_um_lmc_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_lmc_handle
 * DESCRIPTION
 *  handle geting each sms msg info
 * PARAMETERS
 *  void         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_lmc_handle(mmi_sms_um_lmc_struct *lmc_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_done = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_GET_MSG_INFO_HANDLE,  lmc_cntx->curr_index);

	while (lmc_cntx->curr_index < lmc_cntx->total_num)
	{
        U16 msg_id = lmc_cntx->msg_id[lmc_cntx->curr_index];

        if (srv_sms_is_msg_exist(msg_id))
        {
        	srv_um_msg_info_struct *msg_info = &lmc_cntx->msg_info[lmc_cntx->curr_index];

            if (mmi_sms_um_lmc_get_info(msg_id, msg_info, lmc_cntx))
            {
                lmc_cntx->result[lmc_cntx->curr_index] = MMI_TRUE;
                lmc_cntx->curr_index++;
            }
            else
            {
                is_done = MMI_FALSE;
                break;
            }
        }
        else
        {
            /* If msg is not existed, skip it */
            lmc_cntx->curr_index++;
        }
	}

	if (is_done)
	{
    	mmi_sms_um_lmc_send_rsp(lmc_cntx);
    	OslMfree(lmc_cntx);
	}
}

#ifdef __MMI_SMS_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_lmc_get_info
 * DESCRIPTION
 *  handle geting each sms msg info
 * PARAMETERS
 *  void         
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sms_um_lmc_get_info(
                    U16 msg_id,
                	srv_um_msg_info_struct *msg_info,
                    mmi_sms_um_lmc_struct *lmc_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL result = MMI_FALSE;
	srv_sms_mti_enum sms_mti;
	MMI_BOOL is_complete;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_GET_MSG_INFO_CONTENT, msg_id);

    mmi_sms_um_get_msg_common_info(msg_info, msg_id, lmc_cntx->msg_box_type);
    {
        mmi_sms_um_lmc_get_content_req(msg_id, lmc_cntx);
    }

    return result;
}


#else


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_lmc_get_info
 * DESCRIPTION
 *  handle geting each sms msg info
 * PARAMETERS
 *  void         
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sms_um_lmc_get_info(
                    U16 msg_id,
                	srv_um_msg_info_struct *msg_info,
                    mmi_sms_um_lmc_struct *lmc_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL result = MMI_TRUE;
	srv_sms_mti_enum sms_mti;
	MMI_BOOL is_complete;
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    MMI_BOOL is_email;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_GET_MSG_INFO_CONTENT, msg_id);

    mmi_sms_um_get_msg_common_info(msg_info, msg_id, lmc_cntx->msg_box_type);

    sms_mti = srv_sms_get_msg_mti(msg_id);

#ifdef __MMI_MESSAGES_SMS_EMAIL__
	if (srv_sms_get_msg_pid(msg_id) == SRV_SMS_PID_EMAIL)
	{
        is_email = MMI_TRUE;
	}
	else
	{
        is_email = MMI_FALSE;
	}

	if (!is_email)
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
	{
        if (sms_mti == SRV_SMS_MTI_STATUS_REPORT)
        {
            msg_info->address_type = SRV_UM_ADDR_PLAIN_TEXT;
            mmi_ucs2ncpy((S8*) msg_info->address, (S8*) GetString(STR_INBOX_REPORT_ID), SRV_UM_MAX_ADDR_LEN);
        }
        else
        {
            msg_info->address_type = SRV_UM_ADDR_PHONE_NUMBER;

            srv_sms_get_msg_address(msg_id, (S8*)msg_info->address);
        }

        msg_info->address_length = mmi_ucs2strlen((S8*)msg_info->address);
	}

    is_complete = srv_sms_is_msg_complete(msg_id);

    if (is_complete)
	{
		srv_sms_status_enum status;

        status = srv_sms_get_msg_status(msg_id);

		if (sms_mti == SRV_SMS_MTI_STATUS_REPORT)
	    {
	        mmi_ucs2ncpy(
	            (S8*)msg_info->subject,
	            (S8*)GetString(STR_SR_DELIVERD_ID),
	            SRV_UM_MAX_SUBJECT_LEN);
		}
	    else if (status & SRV_SMS_STATUS_UNSUPPORTED)
	    {
	        mmi_ucs2ncpy(
	            (S8*)msg_info->subject,
	            (S8*)GetString(STR_UM_NOT_SUPPORT_ID),
	            SRV_UM_MAX_SUBJECT_LEN);
	    }
	    else
	    {
	    	result = MMI_FALSE;
		}

        msg_info->subject_length = mmi_ucs2strlen((S8*)GetString(STR_UM_NOT_SUPPORT_ID));
	}
	else
	{
	#ifdef __MMI_MESSAGES_SMS_EMAIL__
        if (is_email)
        {
		    result = MMI_FALSE;
	    }
	#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

        mmi_ucs2ncpy(
            (S8*)msg_info->subject,
            (S8*)GetString(STR_UM_INCOMPLETE_ID),
            SRV_UM_MAX_SUBJECT_LEN);

        msg_info->subject_length = mmi_ucs2strlen((S8*)GetString(STR_UM_INCOMPLETE_ID));
    }

    if (!result)
    {
	#ifdef __MMI_MESSAGES_SMS_EMAIL__
        lmc_cntx->is_email = is_email;
        lmc_cntx->is_complete = is_complete;
	#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

        mmi_sms_um_lmc_get_content_req(msg_id, lmc_cntx);
    }

    return result;
}

#endif





/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_lmc_get_content_req
 * DESCRIPTION
 *  get list item display content request
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_lmc_get_content_req(U16 msg_id, mmi_sms_um_lmc_struct *lmc_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_GET_MSG_INFO_CONTENT_REQ,  msg_id);

    srv_sms_get_msg_content_async(
        msg_id,
        mmi_sms_um_lmc_get_content_rsp,
        lmc_cntx);
}

#ifdef __MMI_SMS_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_lmc_get_content_rsp
 * DESCRIPTION
 *  get list item display content response
 * PARAMETERS
 *  data        [IN]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_lmc_get_content_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_lmc_struct *lmc_cntx;
	srv_sms_mti_enum sms_mti = 0;
	MMI_BOOL is_complete;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lmc_cntx = (mmi_sms_um_lmc_struct*)callback_data->user_data;
	if (callback_data->result)
	{
	    srv_sms_get_msg_content_async_cb_struct *get_content_cb;
		srv_um_msg_info_struct *msg_info;

        get_content_cb = (srv_sms_get_msg_content_async_cb_struct*)callback_data->action_data;

		msg_info = &lmc_cntx->msg_info[lmc_cntx->curr_index];
		sms_mti  = srv_sms_get_msg_mti(msg_info->msg_id);
		{
            S32 len = mmi_ucs2strlen((S8*)get_content_cb->content);
            if (SRV_UM_MAX_SUBJECT_LEN < len)
            { 
                len = SRV_UM_MAX_SUBJECT_LEN;
            }
            if (0 != len)
            {
                mmi_ucs2ncpy((CHAR *)msg_info->subject, get_content_cb->content, len);	
            }
            else
            {
                mmi_ucs2cpy((CHAR *)msg_info->subject, (CHAR *)GetString(STR_UM_EMPTY_CONTENT_ID));
            }
            /* for address*/
             if (sms_mti == SRV_SMS_MTI_STATUS_REPORT)
        {
            msg_info->address_type = SRV_UM_ADDR_PLAIN_TEXT;
            mmi_ucs2ncpy((S8*) msg_info->address, (S8*) GetString(STR_INBOX_REPORT_ID), SRV_UM_MAX_ADDR_LEN);
        }
        else
        {
            msg_info->address_type = SRV_UM_ADDR_PHONE_NUMBER;
            mmi_ucs2ncpy((S8*) msg_info->address, (S8*) get_content_cb->address, SRV_UM_MAX_ADDR_LEN);
        }

        msg_info->address_length = mmi_ucs2strlen((S8*)msg_info->address);

	    }
	    is_complete = srv_sms_is_msg_complete(msg_info->msg_id);
	    if (is_complete)
	    {
				 srv_sms_status_enum status;
				 status = srv_sms_get_msg_status(msg_info->msg_id);
				if (sms_mti == SRV_SMS_MTI_STATUS_REPORT)
				{
					mmi_ucs2ncpy(
						(S8*)msg_info->subject,
						(S8*)GetString(STR_SR_DELIVERD_ID),
						SRV_UM_MAX_SUBJECT_LEN);
				}
				
				else if (status & SRV_SMS_STATUS_UNSUPPORTED)
				{
					mmi_ucs2ncpy(
						(S8*)msg_info->subject,
						(S8*)GetString(STR_UM_NOT_SUPPORT_ID),
						SRV_UM_MAX_SUBJECT_LEN);
				}
	    }
	    else
	    {
				mmi_ucs2ncpy(
            (S8*)msg_info->subject,
            (S8*)GetString(STR_UM_INCOMPLETE_ID),
            SRV_UM_MAX_SUBJECT_LEN);

	    }
		msg_info->subject_length = mmi_ucs2strlen((S8*)msg_info->subject);
	}

    lmc_cntx->result[lmc_cntx->curr_index] = callback_data->result;

	lmc_cntx->curr_index++;

	mmi_sms_um_lmc_handle(lmc_cntx);
}
#else
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_lmc_get_content_rsp
 * DESCRIPTION
 *  get list item display content response
 * PARAMETERS
 *  data        [IN]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_lmc_get_content_rsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_lmc_struct *lmc_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lmc_cntx = (mmi_sms_um_lmc_struct*)callback_data->user_data;
    
	if (callback_data->result)
	{
	    srv_sms_get_msg_content_async_cb_struct *get_content_cb;
		srv_um_msg_info_struct *msg_info;

        get_content_cb = (srv_sms_get_msg_content_async_cb_struct*)callback_data->action_data;

		msg_info = &lmc_cntx->msg_info[lmc_cntx->curr_index];

	#ifdef __MMI_MESSAGES_SMS_EMAIL__
		if (lmc_cntx->is_email)
		{
			if (lmc_cntx->is_complete)
			{
				mmi_msg_get_email_and_subject_from_msgtxt(
				    get_content_cb->content,
				    SRV_SMS_MSG_INFO_CONTENT_LEN,
				    (S8*)msg_info->address,
				    SRV_UM_MAX_ADDR_LEN * ENCODING_LENGTH,
				    (S8 *)msg_info->subject,
				    SRV_UM_MAX_SUBJECT_LEN * ENCODING_LENGTH,
				    NULL, 
				    NULL);
			}
			else
			{
				mmi_msg_get_email_and_subject_from_msgtxt(
				    get_content_cb->content,
				    SRV_SMS_MSG_INFO_CONTENT_LEN,
				    (S8*)msg_info->address,
				    SRV_UM_MAX_ADDR_LEN * ENCODING_LENGTH,
				    NULL,
				    0,
				    NULL,
				    NULL);
			}

			msg_info->address_length = mmi_ucs2strlen((S8*)msg_info->address);
            msg_info->address_type = SRV_UM_ADDR_EMAIL_ADDRESS;
		}
		else
	#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
		{
            S32 len = mmi_ucs2strlen((S8*)get_content_cb->content);
            if (SRV_UM_MAX_SUBJECT_LEN < len)
            { 
                len = SRV_UM_MAX_SUBJECT_LEN;
            }
            if (0 != len)
            {
                mmi_ucs2ncpy((CHAR *)msg_info->subject, get_content_cb->content, len);	
            }
            else
            {
                mmi_ucs2cpy((CHAR *)msg_info->subject, (CHAR *)GetString(STR_UM_EMPTY_CONTENT_ID));
            }
	    }
	
		msg_info->subject_length = mmi_ucs2strlen((S8*)msg_info->subject);
	}

    lmc_cntx->result[lmc_cntx->curr_index] = callback_data->result;

	lmc_cntx->curr_index++;

	mmi_sms_um_lmc_handle(lmc_cntx);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_lmc_convert_rsp_data
 * DESCRIPTION
 *  fill the um get msg info rsp data with the lmc_cntx
 * PARAMETERS
 *  msg			[OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_lmc_convert_rsp_data(
                srv_um_get_msg_info_rsp_struct *rsp_data,
                mmi_sms_um_lmc_struct *lmc_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_GET_MSG_INFO_FILL_RSP_DATA);

    for (i = 0; i < SRV_UM_MAX_GET_MSG_INFO_NUMBER; i++)
    {
    	rsp_data->msg_id[i] = lmc_cntx->msg_id[i];
        rsp_data->result[i] = lmc_cntx->result[i];
    }
    rsp_data->app_id = lmc_cntx->app_id;
    rsp_data->msg_type = SRV_UM_MSG_SMS;
    rsp_data->msg_box_type = lmc_cntx->msg_box_type;
    rsp_data->msg_number = lmc_cntx->total_num;

	memcpy(rsp_data->msg_info, lmc_cntx->msg_info, (sizeof(srv_um_msg_info_struct) * SRV_UM_MAX_GET_MSG_INFO_NUMBER));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msg_info_send_rsp
 * DESCRIPTION
 *  Send get msg info respone to UM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_lmc_send_rsp(mmi_sms_um_lmc_struct *lmc_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_um_get_msg_info_rsp_struct *rsp_data;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_GET_MSG_INFO_FILL_SEND_RSP_TO_UM);
	rsp_data = (srv_um_get_msg_info_rsp_struct*)OslConstructDataPtr(sizeof(srv_um_get_msg_info_rsp_struct));

	mmi_sms_um_lmc_convert_rsp_data(rsp_data, lmc_cntx);
	
    mmi_sms_um_send_message(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_INFO_RSP, rsp_data);
}

#else /* __MMI_MSG_UM_LOW_MEMORY_COST__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_msg_info_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_get_msg_info_hdlr(srv_um_get_msg_info_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_info_req_struct *msgReq = req_data;
    srv_um_get_msg_info_rsp_struct *rsp_msg;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_msg = (srv_um_get_msg_info_rsp_struct*)OslConstructDataPtr(sizeof(srv_um_get_msg_info_rsp_struct));

    rsp_msg->app_id = msgReq->app_id;
    rsp_msg->msg_type = SRV_UM_MSG_SMS;
    rsp_msg->msg_box_type = msgReq->msg_box_type;
    rsp_msg->msg_number = msgReq->msg_number;

    for (i = 0; i < msgReq->msg_number; i++)
    {
        U16 msg_id = (U16)msgReq->msg_id[i];
        srv_um_msg_info_struct *msg_info = &rsp_msg->msg_info[i];

        rsp_msg->msg_id[i] = msg_id;
        rsp_msg->result[i] = mmi_sms_um_get_msg_info_content(
                                msg_info,
                                msg_id,
                                msgReq->msg_box_type);
    }

    mmi_sms_um_send_message(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_INFO_RSP, rsp_msg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_msg_info_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sms_um_get_msg_info_content(
                    srv_um_msg_info_struct *msg_info,
                    U16 msg_id,
                    srv_um_msg_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_msg_exist( msg_id))
    {
        srv_sms_mti_enum sms_mti;

        mmi_sms_um_get_msg_common_info(msg_info, msg_id, msg_box_type);

        sms_mti = srv_sms_get_msg_mti(msg_id);

        /* Get Address */
        if (sms_mti == SRV_SMS_MTI_STATUS_REPORT)
        {
            msg_info->address_type = SRV_UM_ADDR_PLAIN_TEXT;
            mmi_ucs2ncpy((S8*) msg_info->address, (S8*) GetString(STR_INBOX_REPORT_ID), SRV_UM_MAX_ADDR_LEN);
        }
        else
        {
            msg_info->address_type = SRV_UM_ADDR_PHONE_NUMBER;

            srv_sms_get_msg_address(msg_id, (S8*)msg_info->address);
        }

        msg_info->address_length = mmi_ucs2strlen((S8*) msg_info->address);

        /* Get Subject */
        mmi_sms_um_get_msg_subject(msg_info->subject, msg_id, SRV_UM_MAX_SUBJECT_LEN );

        msg_info->subject_length = mmi_ucs2strlen((S8*)msg_info->subject);
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}
#endif /*__MMI_MSG_UM_LOW_MEMORY_COST__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_msg_common_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_get_msg_common_info(
                srv_um_msg_info_struct *msg_info,
                U16 msg_id,
                srv_um_msg_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info->msg_id = msg_id;
    msg_info->timestamp = srv_sms_get_msg_timestamp_utc_sec(msg_id);
    msg_info->icon_id = mmi_sms_get_icon(msg_id);

#if (MMI_MAX_SIM_NUM >= 2)
     msg_info->sim_id = mmi_sms_sim_id_to_um_sim(srv_sms_get_msg_sim_id(msg_id));
#endif /* MMI_MAX_SIM_NUM >= 2 */

    if (msg_box_type == SRV_UM_MSG_BOX_UNSENT)
    {
        msg_info->csk_icon_id = IMG_GLOBAL_OPTION_CSK;
    }
    else
    {
        msg_info->csk_icon_id = IMG_GLOBAL_COMMON_CSK;
    }
    if (srv_sms_get_msg_status(msg_id) & SRV_SMS_STATUS_UNSUPPORTED)
    {
        msg_info->csk_icon_id = IMG_GLOBAL_COMMON_CSK;
    }
}


#ifdef __MMI_UM_REPORT_BOX__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_msg_list_info_hdlr
 * DESCRIPTION
 *  get sms list info
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  start_entry         [IN]        
 *  max_msg_number      [IN]        
 *  msg_number          [?]         
 *  list_info           [?]         
 *  more                [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sms_um_get_report_list_info_hdlr(
                    srv_um_get_msg_list_rsp_struct *rsp_data,
                    srv_um_get_msg_list_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 list_index = req_data->start_entry;
    U16 msg_box_size;
    U16 msg_count = 0;
#if (MMI_MAX_SIM_NUM >= 2)
    srv_um_sim_enum um_sim_id = req_data->sim_id;
    srv_sms_sim_enum sms_sim_id = SRV_SMS_SIM_1;
#endif /* (MMI_MAX_SIM_NUM >= 2) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_box_size = srv_sms_get_report_list_size();       

#if (MMI_MAX_SIM_NUM >= 2)
    /* Get Start List Index */
    if (um_sim_id != SRV_UM_SIM_ALL)
    {
        U16 i ;
        U32 tmp_index = 0;

        sms_sim_id = mmi_sms_um_sim_to_sms_sim(um_sim_id);

        for (i = 0; i < msg_box_size; i++)
        {
            U16 report_id = srv_sms_get_report_id(i);
            
            if (srv_sms_get_report_sim_id(report_id) == sms_sim_id)
            {
                if (tmp_index == list_index)
                {
                    list_index = i;
                    break;
                }
                else
                {
                    tmp_index++;
                }
            }
        }
    }
#endif /* (MMI_MAX_SIM_NUM >= 2) */

    while ((msg_count < SRV_UM_MAX_GET_MSG_LIST_NUMBER) &&
           (list_index < msg_box_size))
    {
        U16 report_id = srv_sms_get_report_id(list_index);

        if (report_id != SRV_SMS_INVALID_MSG_ID)
        {
        #if (MMI_MAX_SIM_NUM >= 2)
            if ((um_sim_id == SRV_UM_SIM_ALL) ||
                (srv_sms_get_msg_sim_id(report_id) == sms_sim_id))
        #endif /* (MMI_MAX_SIM_NUM >= 2) */
            {
            #ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
                mmi_sms_um_get_report_list_info(
                    report_id,
                    &rsp_data->list_info[msg_count],
                    &rsp_data->list_idx_data[msg_count],
                    req_data->list_idx_type);
            #else /* __UNIFIED_MESSAGE_LIST_INDEX_DATA__ */
                mmi_sms_um_get_report_list_info(
                    report_id,
                    &rsp_data->list_info[msg_count],
                    NULL,
                    0);
            #endif /* __UNIFIED_MESSAGE_LIST_INDEX_DATA__ */

                msg_count++;
            }
  
            list_index++;
        }
        else
        {
            break;
        }
    }

    rsp_data->msg_number = msg_count;

    if (list_index < msg_box_size)
    {
        rsp_data->more = KAL_TRUE;
    }
    else
    {
        rsp_data->more = KAL_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_report_list_info
 * DESCRIPTION
 *  get sms list info
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_get_report_list_info(
                U16 report_id,
                srv_um_msg_list_struct *list_info,
                srv_um_list_idx_data_union *list_idx_data,
                srv_um_list_idx_enum list_idx_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_report_struct report_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_info->msg_id = srv_sms_report_id_to_msg_id(report_id);

    srv_sms_get_report_info(&report_data, report_id);

    list_info->timestamp = applib_dt_sec_local_to_utc(report_data.sec_timestamp);

#if (MMI_MAX_SIM_NUM >= 2)
     list_info->sim_id = mmi_sms_sim_id_to_um_sim(report_data.sim_id);
#endif /* MMI_MAX_SIM_NUM >= 2 */

#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
    switch(list_idx_type)
    {
        case SRV_UM_LIST_IDX_TIMESTAMP:
            break;

        case SRV_UM_LIST_IDX_MSG_SIZE:
            list_idx_data->msg_size = 0;
            break;

        case SRV_UM_LIST_IDX_MSG_TYPE:
            list_idx_data->msg_type = SRV_UM_MSG_SMS;
            break;

        case SRV_UM_LIST_IDX_SUBJECT:
        {
            mmi_sms_um_get_report_subject(
                list_idx_data->subject,
                &report_data,
                SRV_UM_MAX_LIST_INDEX_LEN);
            break;
        }

        case SRV_UM_LIST_IDX_ADDRESS:
        {
            mmi_wcsncpy(
                (WCHAR*)list_idx_data->address,
                report_data.number,
            	SRV_UM_MAX_LIST_INDEX_LEN);

            list_idx_data->address[SRV_UM_MAX_LIST_INDEX_LEN] = 0;                	
            break;
        }

        case SRV_UM_LIST_IDX_READ_STATUS:
        {
            list_idx_data->read_status = KAL_TRUE;
            break;
        }

        default:
            MMI_ASSERT(0);
            break;
    }
#endif /* __UNIFIED_MESSAGE_LIST_INDEX_DATA__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_report_subject
 * DESCRIPTION
 *  get sms list info
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_get_report_subject(
                WCHAR *subject,
                srv_sms_status_report_struct *report_data,
                U32 subject_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (report_data->status)
    {
        case SRV_SMS_SRS_PENDING:
        {
            if (report_data->total_seg > 1)
            {
                U32 unpending_num = report_data->fail_num + report_data->succ_num;
                U32 pending_num = report_data->total_seg - unpending_num;
                WCHAR tmp_subject[MMI_SMS_REPORT_SUBJECT_LEN + 1];

                MMI_ASSERT(unpending_num < report_data->total_seg);

                kal_wsprintf(tmp_subject, "%d/%d %w", pending_num, report_data->total_seg, (WCHAR*)GetString(STR_ID_SMS_PENDING));
                mmi_wcsncpy(subject, tmp_subject, subject_len);
            }
            else
            {
                mmi_wcsncpy(subject, (WCHAR*)GetString(STR_ID_SMS_PENDING), subject_len);
            }
            break;
        }

        case SRV_SMS_SRS_SUCC:
            mmi_wcsncpy(subject, (WCHAR*)GetString(STR_ID_SMS_DELIVERED), subject_len);
            break;

        case SRV_SMS_SRS_FAILED:
            mmi_wcsncpy(subject, (WCHAR*)GetString(STR_GLOBAL_FAILED), subject_len);
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

    subject[subject_len] = '\0';
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_msg_info_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_get_report_info_hdlr(srv_um_get_msg_info_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_info_req_struct *msgReq = req_data;
    srv_um_get_msg_info_rsp_struct *rsp_msg;
    U16 i;
    U16 sms_msg_box_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_msg = (srv_um_get_msg_info_rsp_struct*)OslConstructDataPtr(sizeof(srv_um_get_msg_info_rsp_struct));

    rsp_msg->app_id = msgReq->app_id;
    rsp_msg->msg_type = SRV_UM_MSG_SMS;
    rsp_msg->msg_box_type = msgReq->msg_box_type;
    rsp_msg->msg_number = msgReq->msg_number;

    for (i = 0; i < msgReq->msg_number; i++)
    {
        U32 msg_id = (U16)msgReq->msg_id[i];
        U16 report_id;

        rsp_msg->msg_id[i] = msg_id;
        rsp_msg->msg_info[i].msg_id = msg_id;

        report_id = srv_sms_msg_id_to_report_id((U16)msg_id);

        if (mmi_sms_um_get_report_info_content(&rsp_msg->msg_info[i], report_id))
        {
            rsp_msg->result[i] = KAL_TRUE;
        }
        else
        {
            rsp_msg->result[i] = KAL_FALSE;
        }
    }

    mmi_sms_um_send_message(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_INFO_RSP, rsp_msg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_report_info_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sms_um_get_report_info_content(srv_um_msg_info_struct *msg_info, U16 report_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (report_id != SRV_SMS_INVALID_MSG_ID)
    {
        srv_sms_status_report_struct report_data;

        srv_sms_get_report_info(&report_data, report_id);

        msg_info->timestamp = applib_dt_sec_local_to_utc(report_data.sec_timestamp);

        mmi_wcsncpy((WCHAR*)msg_info->address, report_data.number, SRV_UM_MAX_ADDR_LEN);
        msg_info->address_type = SRV_UM_ADDR_PHONE_NUMBER;
        msg_info->address_length = mmi_ucs2strlen((S8*)msg_info->address);

        mmi_sms_um_get_report_subject((WCHAR*)msg_info->subject, &report_data, SRV_UM_MAX_SUBJECT_LEN);
        msg_info->subject_length = mmi_wcslen((WCHAR*)msg_info->subject);

    #if (MMI_MAX_SIM_NUM >= 2)
         msg_info->sim_id = mmi_sms_sim_id_to_um_sim(report_data.sim_id);
    #endif /* MMI_MAX_SIM_NUM >= 2 */

    #if (MMI_MAX_SIM_NUM >= 2)
        if (report_data.sim_id == SRV_SMS_SIM_1)
        {
            msg_info->icon_id = IMG_ID_SMS_STATUS_REPORT_SIM1;
        }
        else if (report_data.sim_id == SRV_SMS_SIM_2)
        {
            msg_info->icon_id = IMG_ID_SMS_STATUS_REPORT_SIM2;
        }
    #if (MMI_MAX_SIM_NUM >= 3)	
        else if (report_data.sim_id == SRV_SMS_SIM_3)
        {
            msg_info->icon_id = IMG_ID_SMS_STATUS_REPORT_SIM2;
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)	
        else if (report_data.sim_id == SRV_SMS_SIM_4)
        {
            msg_info->icon_id = IMG_ID_SMS_STATUS_REPORT_SIM2;
        }
    #endif
    #else /* (MMI_MAX_SIM_NUM >= 2) */
        msg_info->icon_id = IMG_ID_SMS_STATUS_REPORT;
    #endif /* (MMI_MAX_SIM_NUM >= 2) */

        msg_info->csk_icon_id = 0;
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}
#endif /* __MMI_UM_REPORT_BOX__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_del_folder_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sms_um_del_folder_req_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_delete_folder_req_struct *req_data = (srv_um_delete_folder_req_struct*)inMsg;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_data->msg_type == SRV_UM_MSG_SMS)
    {
        srv_um_msg_box_enum um_box_type = req_data->msg_box_type;
        srv_sms_box_enum sms_box_type = SRV_SMS_BOX_NONE;
        srv_sms_sim_enum sim_id = SRV_SMS_SIM_1;

    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        if (um_box_type & SRV_UM_MSG_BOX_ARCHIVE)
        {
            sms_box_type |= SRV_SMS_BOX_ARCHIVE;
        }   
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        if (um_box_type & SRV_UM_MSG_BOX_SIM)
        {
            sms_box_type |= SRV_SMS_BOX_SIM;
        }
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

        if (um_box_type & SRV_UM_MSG_BOX_INBOX)
        {
            sms_box_type |= SRV_SMS_BOX_INBOX;
        }

        if (um_box_type & SRV_UM_MSG_BOX_SENT)
        {
            sms_box_type |= SRV_SMS_BOX_OUTBOX;
        }

        if (um_box_type & SRV_UM_MSG_BOX_UNSENT)
        {
            sms_box_type |= SRV_SMS_BOX_UNSENT;
        }

        if (um_box_type & SRV_UM_MSG_BOX_DRAFT)
        {
            sms_box_type |= SRV_SMS_BOX_DRAFTS;
        }

    #if (MMI_MAX_SIM_NUM >= 2)
         sim_id = mmi_sms_um_sim_to_sms_sim(req_data->sim_id);
    #endif /* (MMI_MAX_SIM_NUM >= 2) */

        if (sms_box_type != SRV_SMS_BOX_NONE)
        {
            mmi_sms_um_del_folder_struct *del_folder_cntx;
            mmi_sms_is_in_delete_fodler = MMI_TRUE;
            del_folder_cntx = OslMalloc(sizeof(mmi_sms_um_del_folder_struct));
    	
            del_folder_cntx->msg_box_type = um_box_type;

            srv_sms_delete_msg_list(
                sms_box_type,
                sim_id,
                mmi_sms_um_del_folder_callback,
                del_folder_cntx);
        }
        else
        {
        #ifdef __MMI_UM_REPORT_BOX__
            if (um_box_type == SRV_UM_MSG_BOX_REPORT)
            {
                mmi_sms_is_in_delete_fodler = MMI_TRUE;
                srv_sms_delete_all_status_report();
            }
        #endif /* __MMI_UM_REPORT_BOX__ */

            mmi_sms_um_del_folder_hdlr(MMI_TRUE, um_box_type);
        }
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_del_folder_callback
 * DESCRIPTION
 *  delete sms msg box
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_del_folder_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_del_folder_struct *del_folder_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    del_folder_cntx = (mmi_sms_um_del_folder_struct*)callback_data->user_data;

#ifdef __MMI_UM_REPORT_BOX__
    if (del_folder_cntx->msg_box_type & SRV_UM_MSG_BOX_REPORT)
    {
        srv_sms_delete_all_status_report();
    }
#endif /* __MMI_UM_REPORT_BOX__ */

    mmi_sms_um_del_folder_hdlr(callback_data->result, del_folder_cntx->msg_box_type);

    OslMfree(del_folder_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_del_folder_hdlr
 * DESCRIPTION
 *  delete sms msg box
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_del_folder_hdlr(MMI_BOOL result, srv_um_msg_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_delete_folder_rsp_struct *rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_sms_is_in_delete_fodler = MMI_FALSE;
    mmi_sms_send_refresh_ind(msg_box_type, SRV_UM_REFRESH_MSG_DELETED);

    rsp_data = (srv_um_delete_folder_rsp_struct*)OslConstructDataPtr(sizeof(srv_um_delete_folder_rsp_struct));

    rsp_data->msg_type = SRV_UM_MSG_SMS;

    rsp_data->result = (kal_bool)result;

    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
#if (MMI_MAX_SIM_NUM == 2)
    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);
#endif

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	mmi_msg_update_unsent_icon();

    if ((msg_box_type & SRV_UM_MSG_BOX_UNSENT) &&
        (srv_sms_get_list_size(SRV_SMS_BOX_UNSENT) != 0))
	{
	    rsp_data->result = KAL_FALSE;
	}
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

    mmi_sms_um_send_message(MOD_MMI, MSG_ID_MMI_UM_DELETE_FOLDER_RSP, rsp_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_box_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_sms_um_get_box_size(srv_um_msg_box_enum um_box_type, srv_um_sim_enum um_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 box_size;
    srv_sms_box_enum sms_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UM_REPORT_BOX__
    if (um_box_type == SRV_UM_MSG_BOX_REPORT)
    {
        box_size = srv_sms_get_report_list_size();
    }
    else
#endif /* __MMI_UM_REPORT_BOX__ */
    {
        sms_box_type = mmi_sms_um_um_box_to_sms(um_box_type);
        box_size = srv_sms_get_list_size(sms_box_type);
    }

#if (MMI_MAX_SIM_NUM >= 2)
    if (um_sim_id != SRV_UM_SIM_ALL)
    {
        srv_sms_sim_enum sms_sim_id;
        U16 real_num = 0;
        U16 i;

        sms_sim_id = mmi_sms_um_sim_to_sms_sim(um_sim_id);

    #ifdef __MMI_UM_REPORT_BOX__
        if (um_box_type == SRV_UM_MSG_BOX_REPORT)
        {
            for (i = 0; i < box_size; i++)
            {
                U16 report_id = srv_sms_get_report_id(i);
            
                if (srv_sms_get_report_sim_id(report_id) == sms_sim_id)
                {
                    real_num++;
                }
            }
        }
        else
    #endif /* __MMI_UM_REPORT_BOX__ */
        {
            for (i = 0; i < box_size; i++)
            {
                U16 msg_id = srv_sms_get_msg_id(sms_box_type, i);
            
                if (srv_sms_get_msg_sim_id(msg_id) == sms_sim_id)
                {
                    real_num++;
                }
            }
        }

        box_size = real_num;
    }
#endif /* (MMI_MAX_SIM_NUM >= 2) */

    return box_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_unread_msg_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_sms_um_get_unread_msg_num(srv_um_sim_enum um_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 uread_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    if (um_sim_id != SRV_UM_SIM_ALL)
    {
        U16 i;
        U16 inbox_total;
        srv_sms_sim_enum sms_sim_id;

        uread_num = 0;

        sms_sim_id = mmi_sms_um_sim_to_sms_sim(um_sim_id);

        inbox_total = srv_sms_get_list_size(SRV_SMS_BOX_INBOX);

        for (i = 0; i < inbox_total; i++)
        {
            U16 msg_id = srv_sms_get_msg_id(SRV_SMS_BOX_INBOX, i);
        
            if (srv_sms_get_msg_sim_id(msg_id) == sms_sim_id)
            {
                uread_num++;   
                if (srv_sms_get_msg_status(msg_id) & SRV_SMS_STATUS_UNREAD)
                {
                    uread_num++;
                }
            }
        }
    }
    else
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    {
        uread_num = srv_sms_get_unread_sms_num();
    }

    return uread_num;
}


#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_multi_op_req_hdlr
 * DESCRIPTION
 *  Handle UM multi-operate request
 * PARAMETERS
 *  in_msg		[IN] msg data
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sms_um_multi_op_req_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_um_mark_several_op_req_struct *req_msg = (srv_um_mark_several_op_req_struct*)in_msg;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_msg->msg_type == SRV_UM_MSG_SMS)
    {
        mmi_sms_um_multi_op_cntx_struct *cntx;

        cntx = OslMalloc(sizeof(mmi_sms_um_multi_op_cntx_struct));

        mmi_sms_um_multi_op_init(cntx, in_msg);
        mmi_sms_um_multi_op_hdlr(cntx);
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_init_data
 * DESCRIPTION
 *  init the data for UM multi-operate
 * PARAMETERS
 *  in_msg		[IN] multi-operate request data	
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_multi_op_init(
                mmi_sms_um_multi_op_cntx_struct *cntx,
                srv_um_mark_several_op_req_struct *req_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 total = req_msg->msg_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(total <= SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP);

    cntx->app_id = req_msg->app_id;
    cntx->um_box_type = req_msg->msg_box_type;
    cntx->action_type = req_msg->action_type;
    cntx->curr_index = 0;
    cntx->total_num = total;

    for (i = 0; i < total; i++)
    {
        cntx->msg_id[i] = (U16)req_msg->msg_id[i];
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_delete
 * DESCRIPTION
 *  Handle UM delete multi message
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_multi_op_hdlr(mmi_sms_um_multi_op_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_mark_several_op_action_enum action_type = cntx->action_type;
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    srv_um_msg_box_enum um_box_type = cntx->um_box_type;
#endif
    MMI_BOOL is_continue = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while (is_continue && (cntx->curr_index < cntx->total_num))
	{
    	U16 msg_id = cntx->msg_id[cntx->curr_index];

        is_continue = MMI_FALSE;

        switch (action_type)
        {
            case SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE:
            {
                srv_sms_delete_msg(
                    msg_id,
                    mmi_sms_um_multi_op_callback,
                    cntx);
                break;
            }

        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            case SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE:
            {
                MMI_BOOL is_valid = MMI_FALSE;
            
	            if ((um_box_type & SRV_UM_MSG_BOX_INBOX) || (um_box_type & SRV_UM_MSG_BOX_SENT))
	            {
                    srv_sms_mti_enum sms_mti;
                    srv_sms_status_enum status;

                    sms_mti = srv_sms_get_msg_mti(msg_id);
                    status = srv_sms_get_msg_status(msg_id);

                    if ((sms_mti != SRV_SMS_MTI_STATUS_REPORT) && 
                        (!(status & SRV_SMS_STATUS_UNSUPPORTED)))
                    {
                        is_valid = MMI_TRUE;
                    }
                }

                if (is_valid)
                {
                    srv_sms_move_msg_to_archive(
                        msg_id,
                        mmi_sms_um_multi_op_callback,
                        cntx);
                }
                else
                {
                    is_continue = MMI_TRUE;
                	cntx->result[cntx->curr_index] = MMI_FALSE;
                	cntx->curr_index++;
                }
                break;
            }
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

        #ifdef __MMI_MESSAGES_COPY__
            case SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_SIM:
            {
        	    srv_sms_move_msg(
        	        msg_id,
        	        SRV_SMS_STORAGE_SIM,
        	        mmi_sms_um_multi_op_callback,
        	        cntx);
                break;
            }

            case SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_PHONE:
            {
        	    srv_sms_move_msg(
        	        msg_id,
        	        SRV_SMS_STORAGE_ME,
        	        mmi_sms_um_multi_op_callback,
        	        cntx);
    	        break;
            }

            case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM:
            {
        	    srv_sms_copy_msg(
        	        msg_id,
        	        SRV_SMS_STORAGE_SIM,
        	        mmi_sms_um_multi_op_callback,
        	        cntx);
                break;
            }

            case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_PHONE:
            {
        	    srv_sms_copy_msg(
        	        msg_id,
        	        SRV_SMS_STORAGE_ME,
        	        mmi_sms_um_multi_op_callback,
        	        cntx);
    	        break;
            }
        #endif /* __MMI_MESSAGES_COPY__ */
        
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_ARCHIVE:
            {
                srv_sms_copy_msg_to_archive(
        	        msg_id,
        	        mmi_sms_um_multi_op_callback,
        	        cntx);
                break;
            }
        #endif
        
            case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM1:
            {
                srv_sms_copy_msg_ext(
        	        msg_id,
        	        SRV_SMS_STORAGE_SIM,
        	        SRV_SMS_SIM_1,
        	        mmi_sms_um_multi_op_callback,
        	        cntx);
                break;
            }

            case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM2:
            {
                srv_sms_copy_msg_ext(
        	        msg_id,
        	        SRV_SMS_STORAGE_SIM,
        	        SRV_SMS_SIM_2,
        	        mmi_sms_um_multi_op_callback,
        	        cntx);
                break;
            }

            default:
            {
                MMI_ASSERT(0);
                break;
            }
        }
	}

	if (cntx->curr_index == cntx->total_num)
	{
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
#if (MMI_MAX_SIM_NUM >= 2)
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_3);
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_4);
#endif
		mmi_sms_um_multi_op_send_rsp_to_um(cntx);
        OslMfree(cntx);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_multi_op_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_multi_op_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_um_multi_op_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (mmi_sms_um_multi_op_cntx_struct*)callback_data->user_data;

	cntx->result[cntx->curr_index] = callback_data->result;
	cntx->curr_index++;

    mmi_sms_um_multi_op_hdlr(cntx);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_multi_op_send_rsp_to_um
 * DESCRIPTION
 *  Send mulit operate respone to UM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_multi_op_send_rsp_to_um(mmi_sms_um_multi_op_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_um_mark_several_op_rsp_struct *rsp_msg;
    U16 i;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp_msg = (srv_um_mark_several_op_rsp_struct*)OslConstructDataPtr(sizeof(srv_um_mark_several_op_rsp_struct));

	rsp_msg->msg_type = SRV_UM_MSG_SMS;
	rsp_msg->app_id = cntx->app_id;
	rsp_msg->msg_box_type = cntx->um_box_type;
	rsp_msg->action_type = cntx->action_type;
	rsp_msg->msg_number = cntx->total_num;

    for (i = 0; i < cntx->total_num; i++)
    {
        rsp_msg->msg_id[i] = cntx->msg_id[i];
        rsp_msg->action_result[i] = (kal_bool)cntx->result[i];
    }
	
    mmi_sms_um_send_message(MOD_MMI, MSG_ID_MMI_UM_MARK_SEVERAL_OP_RSP, rsp_msg);
}
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */


#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
#ifndef __MMI_MSG_UM_LOW_MEMORY_COST__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_traverse_msg_req_hdlr
 * DESCRIPTION
 *  When open conversation box, um will need several boxes messges.
 * PARAMETERS
 *  inMsg       [IN]: Request structure from UM    
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sms_um_traverse_msg_req_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 start_entry; 
    kal_uint16 msg_number = 0;
    kal_bool more = KAL_FALSE;
    kal_bool result;
    srv_um_traverse_msg_req_struct *msgReq = (srv_um_traverse_msg_req_struct*) (inMsg);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (msgReq->msg_type != SRV_UM_MSG_SMS)
    {
        return MMI_FALSE;
    }
    if ((msgReq->msg_box_type == SRV_UM_MSG_BOX_PREDEF_TEMPLATES)
        || (msgReq->msg_box_type == SRV_UM_MSG_BOX_PREDEF_TEMPLATES))
    {
        MMI_ASSERT(0);
    }
    start_entry = msgReq->start_entry;         
    if (start_entry < 0)
    {
        msg_number = msgReq->msg_number;
    }
    result = mmi_sms_um_traverse_msg(
                    msgReq->msg_box_type
                    ,start_entry
                    ,&msg_number
                    ,msgReq->msg_id
                #if (MMI_MAX_SIM_NUM >= 2)
                    ,SRV_UM_SIM_ALL
                #endif /*(MMI_MAX_SIM_NUM >= 2)*/
                    ,&more
                    ,msgReq->field
                    ,msgReq->traverse_func
                    ,msgReq->user_data
                    );
    mmi_sms_um_send_traverse_msg_rsp(msgReq->app_id, msg_number, more, result);
    return MMI_TRUE;
}


/***********************************************************************************
 * FUNCTION
 *  mmi_sms_um_send_traverse_msg_rsp
 * DESCRIPTION
 *  Send MSG_ID_MMI_UM_TRAVERSE_MSG_RSP response back to UM
 * PARAMETERS
 *  app_id       [IN]: app id
 *  more         [IN]: Info um that whether there has more sms need to handle or not    
 *  result       [IN]: Info um traverse msg result
 * RETURNS
 *  void
 ***********************************************************************************/
void mmi_sms_um_send_traverse_msg_rsp(kal_uint32 app_id, kal_uint16 msg_number, kal_bool more, kal_bool result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_traverse_msg_rsp_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    msg = (srv_um_traverse_msg_rsp_struct*)OslConstructDataPtr(sizeof(srv_um_traverse_msg_rsp_struct));
    msg->msg_type = SRV_UM_MSG_SMS;
    msg->app_id   = app_id;
    msg->msg_number = msg_number;
    msg->more = more;
    msg->result = result;
    mmi_sms_um_send_message(MOD_MMI, MSG_ID_MMI_UM_TRAVERSE_MSG_RSP, msg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_traverse_msg
 * DESCRIPTION
 *  UM traverse message to get msg list info.
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  start_entry         [IN]        
 *  msg_number          [OUT]
 *  msg_id_set          [IN]
 *  sim_id              [IN]
 *  more                [OUT]
 *  field               [IN]
 *  traverse_func       [IN]
 *  user_data           [IN]
 * RETURNS
 *  KAL_TRUE
 *  KAL_FALSE
 *****************************************************************************/
kal_bool mmi_sms_um_traverse_msg(
                    srv_um_msg_box_enum msg_box_type
                    ,kal_int16 start_entry
                    ,kal_uint16 *msg_number
                    ,kal_uint32 *msg_id_set
                #if (MMI_MAX_SIM_NUM >= 2)
                    ,srv_um_sim_enum sim_id
                #endif
                    ,kal_bool *more
                    ,srv_um_detail_field_enum field
                    ,srv_um_traverse_func traverse_func
                    ,kal_int32 user_data
                    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_list_index = 0;
    U16 i = 0;
    kal_int32 traverse_ret;
    srv_sms_box_enum sms_msg_box_type = SRV_SMS_BOX_NONE;
    U16 sms_msg_box_size = 0;
    srv_sms_status_enum msg_status;
    srv_um_msg_detail_struct msg_detail;
    S8 *temp_addr;
    U16 msg_id;
    U16 invalid_cnt = 0;
    srv_sms_box_enum curr_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *more = KAL_TRUE;
    if (start_entry >= 0)
    {
        *msg_number = 0;
        if(mmi_sms_is_in_delete_fodler == MMI_TRUE)
        {
	        sms_msg_box_size = 0;  /*if delete folder condition is true then dont provide the list info to UM*/
        }    
        else
        {
        sms_msg_box_type = mmi_sms_um_um_box_to_sms(msg_box_type);
        sms_msg_box_size = srv_sms_get_list_size(sms_msg_box_type);   
	}
        msg_list_index = start_entry;
    }
    
    memset(&msg_detail, 0, sizeof(srv_um_msg_detail_struct));
    msg_detail.subject = (kal_wchar *)OslMalloc((SRV_UM_MAX_SUBJECT_LEN + 1) * sizeof(kal_wchar));
    msg_detail.address.addr = (kal_wchar *)OslMalloc((SRV_SMS_MAX_ADDR_LEN + 1) * sizeof(kal_wchar));
    while (1)
    {
        if (start_entry < 0)
        {
            if(i < *msg_number)
            {
                msg_id = (U16)msg_id_set[i];
                i++;
                if (srv_sms_is_msg_exist(msg_id) != MMI_TRUE)
                {
                    invalid_cnt++;
                    continue;
                }
                
            }
            else
            {
                *more = KAL_FALSE;
                break;
            }
        }
        else
        {
            /* Enclose the follow code */
            if (msg_list_index < sms_msg_box_size)
            {
                msg_id = srv_sms_get_msg_id(sms_msg_box_type, msg_list_index);
                msg_list_index++;
            }
            else
            {
                *more = KAL_FALSE;
                break;
            }
        }
        

        if (msg_id == SRV_SMS_INVALID_MSG_ID)
        {
            *more = KAL_FALSE;
            mmi_sms_um_free_traverse_msg_buffer(&msg_detail);
            return KAL_FALSE;
        }

    #if (MMI_MAX_SIM_NUM >= 2)
         msg_detail.sim_id = mmi_sms_sim_id_to_um_sim(srv_sms_get_msg_sim_id(msg_id));
    #endif /* MMI_MAX_SIM_NUM >= 2 */

        msg_detail.msg_type = SRV_UM_MSG_SMS;
        msg_detail.msg_id = (U32)msg_id;
        srv_sms_get_msg_list_index(&curr_box_type, msg_id);
        msg_detail.msg_box_type = mmi_sms_um_sms_box_to_um(curr_box_type);
        msg_detail.timestamp = srv_sms_get_msg_timestamp_utc_sec(msg_id);
        msg_detail.msg_size = srv_sms_get_msg_size(msg_id);
        /* Get message status */
        if ((srv_sms_get_msg_status(msg_id) & SRV_SMS_STATUS_UNREAD) == SRV_SMS_STATUS_UNREAD)
        {
            msg_detail.read_status = KAL_FALSE;
        }
        else
        {
            msg_detail.read_status = KAL_TRUE;
        }

        /* Get message Address */         /*bug: email*/
        msg_status = srv_sms_get_msg_status(msg_id);
        temp_addr = (S8 *)srv_sms_get_msg_asc_address(msg_id);
        mmi_asc_n_to_ucs2(
            (S8*)msg_detail.address.addr,
            temp_addr,
            SRV_SMS_MAX_ADDR_LEN);

        msg_detail.address.addr[SRV_SMS_MAX_ADDR_LEN] = 0;      
        msg_detail.address.next = NULL;
        msg_detail.address.previous = NULL;
        msg_detail.address.type = SRV_UM_ADDR_PHONE_NUMBER;

        if (msg_detail.address.addr[0] && (!applib_is_valid_number_unicode(msg_detail.address.addr)))
        {
            msg_detail.address.type = SRV_UM_ADDR_PLAIN_TEXT;
        }

        if ((msg_status & SRV_SMS_STATUS_UNREAD) || (msg_status & SRV_SMS_STATUS_READ))
        {
            msg_detail.address.group = SRV_UM_ADDR_GROUP_FROM;
        }
        else
        {
            msg_detail.address.group = SRV_UM_ADDR_GROUP_TO;
        }
        
        /* Get message subject*/
        mmi_sms_um_get_msg_subject(msg_detail.subject, msg_id, SRV_UM_MAX_SUBJECT_LEN);

        traverse_ret = traverse_func(user_data, &msg_detail);
        switch (traverse_ret)
        {
            case SRV_UM_RESULT_OK:
                break;

            case SRV_UM_RESULT_BUFFER_FULL:
                mmi_sms_um_free_traverse_msg_buffer(&msg_detail);
                return KAL_TRUE;

            case SRV_UM_RESULT_CANCELLLED:
                *more = KAL_FALSE;
                mmi_sms_um_free_traverse_msg_buffer(&msg_detail);
                return KAL_FALSE;

            default:
                MMI_ASSERT(0);
                break;
        }
        if(start_entry >= 0)
        {
            (*msg_number)++;       
        }
    }
    mmi_sms_um_free_traverse_msg_buffer(&msg_detail);
    if ((start_entry < 0) && (invalid_cnt > 0))
    {
        *msg_number = *msg_number - invalid_cnt;
        return KAL_FALSE;
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_free_traverse_msg_buffer
 * DESCRIPTION
 *  Free the control buffer for traverse msg.
 * PARAMETERS
 *  sms_traverse_cntx   [IN]: buffer need to free.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_free_traverse_msg_buffer(srv_um_msg_detail_struct *msg_detail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_detail->subject != NULL)
    {
        OslMfree(msg_detail->subject);
    }
    if (msg_detail->address.addr != NULL)
    {
        OslMfree(msg_detail->address.addr);
    }
}
#endif /* __MMI_MSG_UM_LOW_MEMORY_COST__ */
#endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_ready_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_um_ready_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_ready_ind_struct *ind_msg = NULL;
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_sms_ready_struct *event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_info = (srv_sms_event_sms_ready_struct*)event_data->event_info;
    ind_msg = (srv_um_ready_ind_struct*)OslConstructDataPtr(sizeof(srv_um_ready_ind_struct));

    ind_msg->result = (kal_bool)event_info->is_sms_ready;
    ind_msg->msg_type = SRV_UM_MSG_SMS;

    mmi_sms_um_send_message(MOD_MMI, MSG_ID_MMI_UM_READY_IND, ind_msg);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_new_msg_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_um_new_msg_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_new_sms_struct *event_info = (srv_sms_event_new_sms_struct*)event_data->event_info;
    
#if (defined (__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) || (MMI_MAX_SIM_NUM >= 2))
    srv_sms_new_msg_struct *msg_data = (srv_sms_new_msg_struct*)event_info->msg_data;
#endif

    U16 msg_id = event_info->msg_id;
    U32 timestamp;
    srv_um_msg_box_enum um_box_type;
    srv_um_new_msg_ind_struct *ind_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TELEPHONY_SUPPORT__
    if (0 != srv_mode_switch_is_network_service_available())
    {
        return MMI_RET_OK;
    }
#endif /* __MMI_TELEPHONY_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if (msg_data->storage_type == SRV_SMS_STORAGE_SIM)
    {
        um_box_type = SRV_UM_MSG_BOX_SIM;
    }
    else
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    {
        um_box_type = SRV_UM_MSG_BOX_INBOX;
    }

    timestamp = srv_sms_get_msg_timestamp_utc_sec(msg_id);

    ind_msg = (srv_um_new_msg_ind_struct*)OslConstructDataPtr(sizeof(srv_um_new_msg_ind_struct));

    ind_msg->msg_type = SRV_UM_MSG_SMS;
    ind_msg->msg_box_type = um_box_type;
    ind_msg->msg_id = msg_id;
    ind_msg->timestamp = timestamp;

#if (MMI_MAX_SIM_NUM >= 2)
     ind_msg->sim_id = mmi_sms_sim_id_to_um_sim(msg_data->sim_id);
#endif /* MMI_MAX_SIM_NUM >= 2 */

    mmi_sms_um_send_message(MOD_MMI, MSG_ID_MMI_UM_NEW_MSG_IND, ind_msg);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_msg_common_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_sms_um_msg_common_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_ready())
    {
        switch(event_data->evt_id)
        {
            case EVT_ID_SRV_SMS_DEL_MSG:
            {
                if (MMI_TRUE == mmi_sms_is_in_delete_fodler)
                {
                    break;
                }
            }
            case EVT_ID_SRV_SMS_ADD_MSG:
            {
                srv_sms_event_add_struct *event_info; /* add and del struct is same */
                srv_um_msg_box_enum msg_box_type;
                srv_um_refresh_enum refresh_type = SRV_UM_REFRESH_NONE;

                event_info = (srv_sms_event_add_struct*)event_data->event_info;

                msg_box_type = mmi_sms_um_get_um_box_type(
                                event_info->msg_info.status,
                                event_info->msg_info.folder_id,
                                event_info->msg_info.storage_type);

                if (event_data->evt_id == EVT_ID_SRV_SMS_DEL_MSG)
                {
                    refresh_type = SRV_UM_REFRESH_MSG_DELETED;
                }
                mmi_sms_send_refresh_ind(msg_box_type, refresh_type);
            }
                break;

            case EVT_ID_SRV_SMS_UPDATE_MSG:
            {
                srv_sms_event_update_struct *event_info;
                srv_um_msg_box_enum src_box_type;
                srv_um_msg_box_enum dest_box_type;

                event_info = (srv_sms_event_update_struct*)event_data->event_info;      

                src_box_type = mmi_sms_um_get_um_box_type(
                                event_info->old_msg_info.status,
                                event_info->old_msg_info.folder_id,
                                event_info->old_msg_info.storage_type);

                dest_box_type = mmi_sms_um_get_um_box_type(
                                    event_info->new_msg_info.status,
                                    event_info->new_msg_info.folder_id,
                                    event_info->new_msg_info.storage_type);

                if ((event_info->change_para_flag == SRV_SMS_PARA_STATUS) && 
                    ((event_info->old_msg_info.status == SRV_SMS_STATUS_UNREAD) ||
                     (event_info->old_msg_info.status == SRV_SMS_STATUS_READ)))
                {
                    mmi_sms_send_refresh_ind((srv_um_msg_box_enum)(src_box_type | dest_box_type), SRV_UM_REFRESH_MSG_STATUS_CHANGED);
                }
                else
                {
                    mmi_sms_send_refresh_ind((srv_um_msg_box_enum)(src_box_type | dest_box_type), SRV_UM_REFRESH_NONE);
                }
            }
                break;

            case EVT_ID_SRV_SMS_ADD_REPORT:
            case EVT_ID_SRV_SMS_DEL_REPORT:
            case EVT_ID_SRV_SMS_UPDATE_REPORT:
                mmi_sms_send_refresh_ind(SRV_UM_MSG_BOX_REPORT, SRV_UM_REFRESH_NONE);
                break;

        #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            case EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS:
                mmi_sms_send_refresh_ind(SRV_UM_MSG_BOX_UNSENT, SRV_UM_REFRESH_NONE);
                break;
        #endif

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
			case EVT_ID_SRV_SMS_REFRESH_MSG:
			mmi_sms_send_refresh_ind(SRV_UM_MSG_BOX_ALL, SRV_UM_REFRESH_NONE);
			break;
#endif

            default:
                break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_send_message
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_send_message(module_type dest_mod, U16 msg_id, void *local_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm((oslModuleType)dest_mod, (oslMsgType)msg_id, (oslParaType*)local_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_send_refresh_ind
 * DESCRIPTION
 *  send refresh ind to UM
 * PARAMETERS
 *  msg_box_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_send_refresh_ind(srv_um_msg_box_enum msg_box_type, srv_um_refresh_enum refresh_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_refresh_ind_struct *refresh_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    refresh_ind = (srv_um_refresh_ind_struct*)OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));

    refresh_ind->msg_type = SRV_UM_MSG_SMS;
    refresh_ind->msg_box_type = msg_box_type;
    refresh_ind->refresh_type = refresh_type;

    mmi_sms_um_send_message(MOD_MMI, MSG_ID_MMI_UM_REFRESH_IND, refresh_ind);
}

#endif /* __UM_FOLDER */
#endif /* __MMI_TELEPHONY_SUPPORT__ */

#ifdef __MMI_SMS_SLIM__

#ifdef __UM_SUPPORT__
#include "UmSrvDefs.h"
CHAR g_ucs2_addr_buff[(SRV_UM_MAX_ADDR_LEN+1)*ENCODING_LENGTH];
#else
CHAR g_ucs2_addr_buff[(SRV_SMS_MAX_ADDR_LEN+1)*ENCODING_LENGTH];
#endif

#endif

#ifdef __MMI_SMS_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_hilite_msg_addr
 * DESCRIPTION
 *  send refresh ind to UM
 * PARAMETERS
 *  msg_box_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_set_hilite_msg_addr(CHAR *address)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __UM_SUPPORT__
	mmi_ucs2ncpy((S8*)g_ucs2_addr_buff, (S8*)address, SRV_UM_MAX_ADDR_LEN);
	#else
	mmi_ucs2ncpy((S8*)g_ucs2_addr_buff, (S8*)address, SRV_SMS_MAX_ADDR_LEN);
	#endif
	
	return;
}
 void mmi_sms_get_hilite_msg_addr(CHAR *address)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __UM_SUPPORT__
	mmi_ucs2ncpy((S8*)address, (S8*)g_ucs2_addr_buff, SRV_UM_MAX_ADDR_LEN);
	#else
	mmi_ucs2ncpy((S8*)address, (S8*)g_ucs2_addr_buff, SRV_SMS_MAX_ADDR_LEN);
	#endif
	
	return;
}
#endif


#ifndef __UM_SUPPORT__
#ifdef __MMI_TELEPHONY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_get_msg_subject
 * DESCRIPTION
 *  get sms list info
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_um_get_msg_subject(WCHAR *subject, U16 msg_id, U32 subject_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum msg_status;
    MMI_ID string_id = 0;
    const CHAR *temp_content;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_status = srv_sms_get_msg_status(msg_id);

    if (srv_sms_is_msg_complete(msg_id) == MMI_FALSE)
    {
        string_id = STR_UM_INCOMPLETE_ID;
    }
    else if (srv_sms_get_msg_mti(msg_id) == SRV_SMS_MTI_STATUS_REPORT)
    {
        string_id = STR_SR_DELIVERD_ID;
    }
    else if (msg_status & SRV_SMS_STATUS_UNSUPPORTED)
    {
        string_id = STR_UM_NOT_SUPPORT_ID;
    }
    
    if(string_id != 0)
    {
        temp_content = (CHAR *)GetString(string_id);
    }
    else
    {
        temp_content = srv_sms_get_msg_content(msg_id);
        if (0 == mmi_ucs2strlen(temp_content))
        {
            temp_content = (CHAR *)GetString(STR_UM_EMPTY_CONTENT_ID);
        }
    }
    subject_len = subject_len > MMI_SMS_MAX_SUBJECT_LEN ? MMI_SMS_MAX_SUBJECT_LEN : subject_len;
    subject_len = subject_len > SRV_SMS_MSG_INFO_CONTENT_LEN ? SRV_SMS_MSG_INFO_CONTENT_LEN : subject_len;
    mmi_ucs2ncpy(
        (S8*)subject,
        temp_content,
        subject_len);

    subject[subject_len] = '\0';
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_msg_info_content
 * DESCRIPTION
 *  to get the information content for the message id provided
 * PARAMETERS
 *  mmi_sms_msg_info_struct
 *  U16
 *  srv_sms_box_enum
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_sms_get_msg_info_content(
                    mmi_sms_msg_info_struct *msg_info,
                    U16 msg_id,
                    srv_sms_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_msg_exist( msg_id))
    {
        srv_sms_mti_enum sms_mti;
		msg_info->msg_id = msg_id;
		msg_info->timestamp = srv_sms_get_msg_timestamp_utc_sec(msg_id);
		msg_info->icon_id = mmi_sms_get_icon(msg_id);
	
#if (MMI_MAX_SIM_NUM >= 2)
		 msg_info->sim_id = srv_sms_get_msg_sim_id(msg_id);
#endif /* MMI_MAX_SIM_NUM >= 2 */
	
		if (msg_box_type == SRV_SMS_BOX_OUTBOX)
		{
			msg_info->csk_icon_id = IMG_GLOBAL_OPTION_CSK;
		}
		else
		{
			msg_info->csk_icon_id = IMG_GLOBAL_COMMON_CSK;
		}
		if (srv_sms_get_msg_status(msg_id) & SRV_SMS_STATUS_UNSUPPORTED)
		{
			msg_info->csk_icon_id = IMG_GLOBAL_COMMON_CSK;
		}
        sms_mti = srv_sms_get_msg_mti(msg_id);

        /* Get Address */
        if (sms_mti == SRV_SMS_MTI_STATUS_REPORT)
        {
            mmi_ucs2ncpy((S8*) msg_info->address, (S8*) GetString(STR_INBOX_REPORT_ID), SRV_SMS_MAX_ADDR_LEN);
        }
        else
        {
            srv_sms_get_msg_address(msg_id, (S8*)msg_info->address);
        }

        msg_info->address_length = mmi_ucs2strlen((S8*) msg_info->address);

        /* Get Subject */
        mmi_sms_um_get_msg_subject(msg_info->subject, msg_id, MMI_SMS_MAX_SUBJECT_LEN);

        msg_info->subject_length = mmi_ucs2strlen((S8*)msg_info->subject);
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}

#endif

#endif /* __MMI_TELEPHONY_SUPPORT__ */

