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
 *  UDXHdlr.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intended for UDX Agent message handler.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_features.h"

#ifdef __MMI_UDX_SUPPORT__
#include "ProtocolEvents.h"
#include "mmi2udx_struct.h"
#include "UDXGprot.h"
#include "UDXProt.h"
#include "PhoneSetupGprots.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static void mmi_udx_builder_header_rsp_hdlr(void *ilm_ptr);
static void mmi_udx_builder_data_rsp_hdlr(void *ilm_ptr);
static void mmi_udx_builder_abort_rsp_hdlr(void *ilm_ptr);
static void mmi_udx_builder_end_rsp_hdlr(void *ilm_ptr);

static void mmi_udx_parser_header_rsp_hdlr(void *ilm_ptr);
static void mmi_udx_parser_body_rsp_hdlr(void *ilm_ptr);
static void mmi_udx_parser_data_rsp_hdlr(void *ilm_ptr);
static void mmi_udx_parser_abort_rsp_hdlr(void *ilm_ptr);
static void mmi_udx_parser_finish_ind_hdlr(void *ilm_ptr);

static MMI_BOOL mmi_udx_agent_set_error_code(U8 error_code, U8 udx_state);


/***************************************************************************** 
 * extern Declaration
 *****************************************************************************/


#define MMI_UDX_INIT_PROTOCOL
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_init_protocol
 * DESCRIPTION
 *  UDX agent init protocol handlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_init_protocol(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MSG_ID_MMI_UDX_BUILD_HEADER_REQ */
    SetProtocolEventHandler((PsFuncPtr)mmi_udx_builder_header_rsp_hdlr, MSG_ID_MMI_UDX_BUILD_HEADER_RSP);

    /* MSG_ID_MMI_UDX_BUILD_DATA_REQ */
    SetProtocolEventHandler((PsFuncPtr)mmi_udx_builder_data_rsp_hdlr, MSG_ID_MMI_UDX_BUILD_DATA_RSP);

    /* MSG_ID_MMI_UDX_BUILD_END_REQ */
    SetProtocolEventHandler((PsFuncPtr)mmi_udx_builder_end_rsp_hdlr, MSG_ID_MMI_UDX_BUILD_END_RSP);

    /* MSG_ID_MMI_UDX_BUILD_ABORT_REQ */
    SetProtocolEventHandler((PsFuncPtr)mmi_udx_builder_abort_rsp_hdlr, MSG_ID_MMI_UDX_BUILD_ABORT_RSP);

    /* MSG_ID_MMI_UDX_PARSE_HEADER_REQ */
    SetProtocolEventHandler((PsFuncPtr)mmi_udx_parser_header_rsp_hdlr, MSG_ID_MMI_UDX_PARSE_HEADER_RSP);

    /* MSG_ID_MMI_UDX_PARSE_BODY_REQ */
    SetProtocolEventHandler((PsFuncPtr)mmi_udx_parser_body_rsp_hdlr, MSG_ID_MMI_UDX_PARSE_BODY_RSP);

    /* MSG_ID_MMI_UDX_PARSE_DATA_REQ */
    SetProtocolEventHandler((PsFuncPtr)mmi_udx_parser_data_rsp_hdlr, MSG_ID_MMI_UDX_PARSE_DATA_RSP);

    SetProtocolEventHandler((PsFuncPtr)mmi_udx_parser_finish_ind_hdlr, MSG_ID_MMI_UDX_PARSE_FINISH_IND);

    /* MSG_ID_MMI_UDX_PARSE_ABORT_REQ */
    SetProtocolEventHandler((PsFuncPtr)mmi_udx_parser_abort_rsp_hdlr, MSG_ID_MMI_UDX_PARSE_ABORT_RSP);
}


#define MMI_UDX_BUILDER_HANDLR
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_header_req
 * DESCRIPTION
 *  UDX agent buider header req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_builder_header_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_build_header_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_ucs2strlen((const CHAR *) g_mmi_udx_cntx.file_path));

    MMI_UDX_AGENT_STATE_TRANS(MMI_UDX_BUILDER_HEADER_REQ);
    
    req = (mmi_udx_build_header_req_struct*)OslConstructDataPtr(sizeof(mmi_udx_build_header_req_struct));

    /* set msg value */
    mmi_ucs2cpy((CHAR *) req->file_path, (const CHAR *) g_mmi_udx_cntx.file_path);
    
    memset(req->user_name, 0, 2);
    mmi_udx_get_user_info((CHAR*)req->user_name);
    
    req->type_mask = g_mmi_udx_cntx.udx_agent.type_selected;
    req->vcard_count = g_mmi_udx_cntx.udx_agent.vcard_num;
    req->vcalendar_count = g_mmi_udx_cntx.udx_agent.vcalendar_num;
    req->sms_count = g_mmi_udx_cntx.udx_agent.sms_num;
    req->mms_count = g_mmi_udx_cntx.udx_agent.mms_num;
    req->email_count = g_mmi_udx_cntx.udx_agent.email_num;

    /* use current system date format to build UDX file date */
    req->separator_format = PhnsetGetDateSeperatorFormat();
    req->date_format = PhnsetGetDateFormat();

    /* set msg to udx task */
    mmi_udx_send_msg(MSG_ID_MMI_UDX_BUILD_HEADER_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_header_rsp_hdlr
 * DESCRIPTION
 *  UDX agent builder begin rsp hdlr
 * PARAMETERS
 *  ilm_ptr             [IN]        msg point
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_header_rsp_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_build_header_rsp_struct *rsp = (mmi_udx_build_header_rsp_struct*) ilm_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_udx_agent_set_error_code(rsp->error_code, MMI_UDX_BUILDER_HEADER_REQ))
    {
        mmi_udx_builder_run(MMI_UDX_BUILDER_HEADER_RSP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_data_req
 * DESCRIPTION
 *  after get data from app, then send it to UDX task
 * PARAMETERS
 *  data_buffer         [IN]        get data buffer
 *  sequence            [IN]        sequence to build
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_builder_data_req(void* data_buffer, U16 sequence)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_build_data_req_struct* data_req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_udx_cntx.udx_agent.state != MMI_UDX_BUILDER_DATA_REQ)
    {
        if (data_buffer != NULL)
        {
            OslMfree(data_buffer);
        }
        return;
    }

	if (data_buffer != NULL)
	{
		MMI_ASSERT(sequence <= g_mmi_udx_cntx.udx_agent.sequence_max);
        MMI_ASSERT(sequence == g_mmi_udx_cntx.udx_agent.sequence);
	}
        
    data_req = (mmi_udx_build_data_req_struct*) OslConstructDataPtr(sizeof(mmi_udx_build_data_req_struct));
    
    switch (g_mmi_udx_cntx.udx_agent.type_curr)
    {
        case UDX_TYPE_VCARD:
            data_req->data_type = UDX_TYPE_VCARD;
            data_req->sequence = sequence;
            if (data_buffer == NULL)
            {
                memset(&(data_req->u.vcard_data), 0, sizeof(udx_vcard_data_struct));
            }
            else
            {
                memcpy(&(data_req->u.vcard_data), data_buffer, sizeof(udx_vcard_data_struct));
            }
            break;

        /* if support the type, need to add code like above */
        case UDX_TYPE_VCALENDAR:            
        case UDX_TYPE_SMS:            
        case UDX_TYPE_MMS:            
        case UDX_TYPE_EMAIL:            
        default:
            MMI_ASSERT(0);
            break;
    }

    if (data_buffer != NULL)
    {
        OslMfree(data_buffer);
    }
    
    mmi_udx_send_msg(MSG_ID_MMI_UDX_BUILD_DATA_REQ, data_req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_data_rsp_hdlr
 * DESCRIPTION
 *  UDX agent builder data rsp hdlr
 * PARAMETERS
 *  ilm_ptr             [IN]        msg point
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_data_rsp_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_build_data_rsp_struct *rsp = (mmi_udx_build_data_rsp_struct*) ilm_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_udx_agent_set_error_code(rsp->error_code, MMI_UDX_BUILDER_DATA_REQ))
    {
        mmi_udx_builder_run(MMI_UDX_BUILDER_DATA_RSP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_end_req
 * DESCRIPTION
 *  UDX agent buider end req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_builder_end_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_AGENT_STATE_TRANS(MMI_UDX_BUILDER_END_REQ);

    /* release data list index buffer for each database */
    mmi_udx_builder_app_list_cui_close();
  
    mmi_udx_send_msg(MSG_ID_MMI_UDX_BUILD_END_REQ, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_end_rsp_hdlr
 * DESCRIPTION
 *  UDX agent builder end rsp hdlr
 * PARAMETERS
 *  ilm_ptr             [IN]        msg point
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_builder_end_rsp_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_build_end_rsp_struct *rsp = (mmi_udx_build_end_rsp_struct*) ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_udx_agent_set_error_code(rsp->error_code, MMI_UDX_BUILDER_END_REQ))
    {
        mmi_udx_builder_run(MMI_UDX_BUILDER_END_RSP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_abort_req
 * DESCRIPTION
 *  UDX agent buider abort req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_builder_abort_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_AGENT_STATE_TRANS(MMI_UDX_BUILDER_ABORT_REQ);
    
    mmi_udx_send_msg(MSG_ID_MMI_UDX_BUILD_ABORT_REQ, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_builder_abort_rsp_hdlr
 * DESCRIPTION
 *  UDX agent builder abort rsp hdlr
 * PARAMETERS
 *  ilm_ptr             [IN]        msg point
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_builder_abort_rsp_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_build_abort_rsp_struct *rsp = (mmi_udx_build_abort_rsp_struct*) ilm_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_udx_agent_set_error_code(rsp->error_code, MMI_UDX_BUILDER_ABORT_REQ))
    {
        mmi_udx_builder_run(MMI_UDX_BUILDER_ABORT_RSP);
    }
}


#define MMI_UDX_PARSER_HANDLR
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_body_req
 * DESCRIPTION
 *  UDX agent parser body req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_parser_header_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_parse_header_req_struct *req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_ucs2strlen((const CHAR *) g_mmi_udx_cntx.file_path));

    MMI_UDX_AGENT_STATE_TRANS(MMI_UDX_PARSER_HEADER_REQ);

    req = (mmi_udx_parse_header_req_struct*)OslConstructDataPtr(sizeof(mmi_udx_parse_header_req_struct));

    mmi_ucs2cpy((CHAR *) req->file_path, (const CHAR *) g_mmi_udx_cntx.file_path);
    
    mmi_udx_send_msg(MSG_ID_MMI_UDX_PARSE_HEADER_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_header_rsp_hdlr
 * DESCRIPTION
 *  UDX agent parser header rsp hdlr
 * PARAMETERS
 *  ilm_ptr             [IN]        msg point
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_parser_header_rsp_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_parse_header_rsp_struct *rsp = (mmi_udx_parse_header_rsp_struct*) ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_udx_agent_set_error_code(rsp->error_code, MMI_UDX_PARSER_HEADER_REQ))
    {
        memcpy(&(g_mmi_udx_cntx.udx_agent.header_info), &(rsp->h_info), sizeof(udx_header_info_struct));

        mmi_udx_parser_run(MMI_UDX_PARSER_HEADER_RSP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_body_req
 * DESCRIPTION
 *  UDX agent parser body req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_parser_body_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_parse_body_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_AGENT_STATE_TRANS(MMI_UDX_PARSER_BODY_REQ);
    
    MMI_ASSERT(mmi_ucs2strlen((const CHAR *) g_mmi_udx_cntx.file_path));

    req = (mmi_udx_parse_body_req_struct*)OslConstructDataPtr(sizeof(mmi_udx_parse_body_req_struct));

    mmi_ucs2cpy((CHAR *) req->file_path, (const CHAR *) g_mmi_udx_cntx.file_path);
    req->type_mask = g_mmi_udx_cntx.udx_agent.type_selected;
    
    mmi_udx_send_msg(MSG_ID_MMI_UDX_PARSE_BODY_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_body_rsp_hdlr
 * DESCRIPTION
 *  UDX agent parser body rsp hdlr
 * PARAMETERS
 *  ilm_ptr             [IN]        msg point
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_parser_body_rsp_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_parse_body_rsp_struct *rsp = (mmi_udx_parse_body_rsp_struct*) ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_udx_agent_set_error_code(rsp->error_code, MMI_UDX_PARSER_BODY_REQ))
    {
        mmi_udx_parser_run(MMI_UDX_PARSER_BODY_RSP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_data_req
 * DESCRIPTION
 *  UDX agent parser get next data req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_parser_data_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_parse_data_req_struct *req; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_UDX_AGENT_STATE_TRANS(MMI_UDX_PARSER_BODY_REQ);

    req = (mmi_udx_parse_data_req_struct*)OslConstructDataPtr(sizeof(mmi_udx_parse_data_req_struct));

    req->mem_full = g_mmi_udx_cntx.udx_agent.parse_log[mmi_udx_get_data_type_index(g_mmi_udx_cntx.udx_agent.type_curr)].storage_full;
    
    mmi_udx_send_msg(MSG_ID_MMI_UDX_PARSE_DATA_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_data_rsp_hdlr
 * DESCRIPTION
 *  UDX agent parser data ind hdlr
 * PARAMETERS
 *  ilm_ptr             [IN]        msg point
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_parser_data_rsp_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_parse_data_rsp_struct *ind = (mmi_udx_parse_data_rsp_struct*) ilm_ptr;
    U8 type = MMI_UDX_TYPE_TOTAL;
    void* data_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_udx_agent_set_error_code(ind->error_code, MMI_UDX_PARSER_BODY_REQ))
    {
        return;
    }
    
    if (ind->error_code != UDX_CODE_NO_ERROR)
    {
        mmi_udx_parser_run(MMI_UDX_PARSER_BODY_RSP);
        return;
    }

    if (!(ind->data_type & g_mmi_udx_cntx.udx_agent.type_selected))
    {
        mmi_udx_parser_run(MMI_UDX_PARSER_BODY_RSP);
        return;
    }
        
    /* add new type */
    switch (ind->data_type)
    {
    #ifdef __MMI_UDX_VCARD_SUPPORT__
        case UDX_TYPE_VCARD:
            type = MMI_UDX_TYPE_VCARD;
            data_buffer = &(ind->u.vcard_data);
            break;
    #endif
    
        case UDX_TYPE_VCALENDAR:            
        case UDX_TYPE_SMS:            
        case UDX_TYPE_MMS:            
        case UDX_TYPE_EMAIL:            
        default:
            MMI_ASSERT(0);
            break;
    }
    
    g_mmi_udx_cntx.udx_agent.sequence = ind->sequence;
    g_mmi_udx_cntx.udx_agent.type_curr = ind->data_type;

    if (ind->lost_count)
    {
        g_mmi_udx_cntx.udx_agent.parse_log[type].lost_count = ind->lost_count;
    }
        
    (udx_support_type_func_tbl[type].store_data)(data_buffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_finish_ind_hdlr
 * DESCRIPTION
 *  UDX agent parser finish ind hdlr
 * PARAMETERS
 *  ilm_ptr             [IN]        msg point
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_udx_parser_finish_ind_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_parse_finish_ind_struct *ind = (mmi_udx_parse_finish_ind_struct*) ilm_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_udx_agent_set_error_code(ind->error_code, MMI_UDX_PARSER_BODY_REQ))
    {
        mmi_udx_parser_run(MMI_UDX_PARSER_END_IND);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_abort_req
 * DESCRIPTION
 *  UDX agent parser abort req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_parser_abort_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_AGENT_STATE_TRANS(MMI_UDX_PARSER_ABORT_REQ);
    
    mmi_udx_send_msg(MSG_ID_MMI_UDX_PARSE_ABORT_REQ, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_udx_parser_abort_rsp_hdlr
 * DESCRIPTION
 *  UDX agent parser abort rsp hdlr
 * PARAMETERS
 *  ilm_ptr         [IN]        msg point
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_udx_parser_abort_rsp_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_parse_abort_rsp_struct *rsp = (mmi_udx_parse_abort_rsp_struct*) ilm_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_udx_agent_set_error_code(rsp->error_code, MMI_UDX_PARSER_ABORT_REQ))
    {
        mmi_udx_parser_run(MMI_UDX_PARSER_ABORT_RSP);
    }
    else
    {
        MMI_ASSERT(0);
    }
}


#define MMI_UDX_HDLR_UTIL
/*****************************************************************************
 * FUNCTION
 *  mmi_udx_agent_set_error_code
 * DESCRIPTION
 *  UDX agent builder set error
 * PARAMETERS
 *  builder_state        [IN]        builder statee
 *  error_code          [IN]        builder error code
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_udx_agent_set_error_code(U8 error_code, U8 udx_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_UDX_LOG1(MMI_UDX_AGENT_SET_ERROR_CODE, error_code);
    
    if (g_mmi_udx_cntx.udx_agent.state != udx_state)
    {
        return MMI_FALSE;
    }
    
    g_mmi_udx_cntx.udx_agent.error_code = error_code;

    return MMI_TRUE;
}

#endif /* __MMI_UDX_SUPPORT__ */
