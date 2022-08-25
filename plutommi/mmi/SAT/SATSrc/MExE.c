/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   MExE.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intended for MExE appliction.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_MExE_SUPPORT__

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "sim_common_enums.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "MMIDataType.h"
#include "string.h"
#include "SIMAccessSrvGprot.h"
#include "mexe_struct.h"
#include "MExEGProt.h"
#include "sim_common_enums.h"
#include "sim_public_api.h"

#if (MMI_MAX_SIM_NUM >=2)
#include "ps_public_utility.h"
#endif


/*
 * Local Variable
 */
static mexe_context_struct g_MExE_context;


/*****************************************************************************
 * FUNCTION
 *  mmi_mexe_init
 * DESCRIPTION
 *  MExE initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mexe_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(mmi_mexe_get_sim_certificate_req, MSG_ID_MMI_GET_SIM_CERTIFICATE_REQ);

    memset(&g_MExE_context, 0, sizeof(mexe_context_struct));

#if (MMI_MAX_SIM_NUM >=2)
    if (sim_service_table_query(SERVICE_MEXE, l4c_gemini_get_switched_sim_id(SIM1)) == SERVICE_SUPPORT)
#else
    if (sim_service_table_query(SERVICE_MEXE) == SERVICE_SUPPORT)
#endif
    {
        /* search for MExE service table */
        mmi_mexe_read_service_table_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mexe_get_sim_certificate_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mexe_get_sim_certificate_req(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_get_sim_certificate_req_struct *sim_certificate_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_certificate_req = (mmi_get_sim_certificate_req_struct*) info;

    g_MExE_context.idx_certificate = 0;
    g_MExE_context.sender_module = sim_certificate_req->mod_id;

    if (!g_MExE_context.MExE_valid)
    {
        mmi_mexe_get_sim_certificate_rsp();
        return;
    }

    g_MExE_context.required_type = sim_certificate_req->type;
    g_MExE_context.ORPK_finish = 0;
    g_MExE_context.ARPK_finish = 0;
    g_MExE_context.TPRPK_finish = 0;
    g_MExE_context.key_identifier = OslMalloc(MAX_MExE_IDENTIFIER_LEN);
    g_MExE_context.certificate_identifier = OslMalloc(MAX_MExE_IDENTIFIER_LEN);
    g_MExE_context.certificate_data = OslMalloc(MAX_MExE_DATA_LEN);

    SetProtocolEventHandler(mmi_mexe_send_sim_certificate_record_res, MSG_ID_MMI_SEND_SIM_CERTIFICATE_RECORD_RES);

    mmi_mexe_retrieve_certificate_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mexe_get_sim_certificate_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mexe_get_sim_certificate_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_get_sim_certificate_rsp_struct *sim_certificate_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(MSG_ID_MMI_SEND_SIM_CERTIFICATE_RECORD_RES);

    if (g_MExE_context.key_identifier != NULL)
    {
        OslMfree(g_MExE_context.key_identifier);
        g_MExE_context.key_identifier = NULL;
    }
    if (g_MExE_context.certificate_identifier != NULL)
    {
        OslMfree(g_MExE_context.certificate_identifier);
        g_MExE_context.certificate_identifier = NULL;
    }
    if (g_MExE_context.certificate_data != NULL)
    {
        OslMfree(g_MExE_context.certificate_data);
        g_MExE_context.certificate_data = NULL;
    }

    sim_certificate_rsp = OslAllocDataPtr(mmi_get_sim_certificate_rsp_struct);
    sim_certificate_rsp->total = g_MExE_context.idx_certificate;

    mmi_frm_send_ilm(g_MExE_context.sender_module, MSG_ID_MMI_GET_SIM_CERTIFICATE_RSP, (oslParaType*) sim_certificate_rsp, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mexe_send_sim_certificate_record_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mexe_send_sim_certificate_record_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_send_sim_certificate_record_ind_struct *sim_certificate_record_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_certificate_record_ind = OslAllocDataPtr(mmi_send_sim_certificate_record_ind_struct);

    sim_certificate_record_ind->idx = g_MExE_context.file_index; //g_MExE_context.idx_certificate++;
    sim_certificate_record_ind->authority_certificate = g_MExE_context.authority_certificate;
    sim_certificate_record_ind->certificate_type = g_MExE_context.certificate_type;
    sim_certificate_record_ind->key_identifier_length = g_MExE_context.key_identifier_length;
    memcpy(sim_certificate_record_ind->key_identifier, g_MExE_context.key_identifier, sim_certificate_record_ind->key_identifier_length);
    sim_certificate_record_ind->certificate_identifier_length = g_MExE_context.certificate_identifier_length;
    if (g_MExE_context.certificate_identifier_length != 0)
    {
        memcpy(sim_certificate_record_ind->certificate_identifier, g_MExE_context.certificate_identifier, sim_certificate_record_ind->certificate_identifier_length);
    }
    sim_certificate_record_ind->data_length = g_MExE_context.certificate_file_length;
    memcpy(sim_certificate_record_ind->data, g_MExE_context.certificate_data, g_MExE_context.certificate_file_length);

    mmi_frm_send_ilm(g_MExE_context.sender_module, MSG_ID_MMI_SEND_SIM_CERTIFICATE_RECORD_IND, (oslParaType*) sim_certificate_record_ind, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mexe_send_sim_certificate_record_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mexe_send_sim_certificate_record_res(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_send_sim_certificate_record_res_struct *sim_certificate_record_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_certificate_record_res = (mmi_send_sim_certificate_record_res_struct*) info;

    if (sim_certificate_record_res->next != 0)
    {
        mmi_mexe_retrieve_certificate_handler();
    }
    else
    {
        mmi_mexe_get_sim_certificate_rsp();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mexe_read_service_table_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mexe_read_service_table_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sim_read_binary(
        FILE_MEXE_ST_IDX, /* sim_file_index_enum */
        NULL, /* sim_file_id_enum */
        0,
        1,
        MMI_SIM1,
        mmi_mexe_read_service_table_rsp,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mexe_read_service_table_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mexe_read_service_table_rsp(srv_sim_cb_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_data_struct *sim_data = (srv_sim_data_struct *) param->data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->result == MMI_TRUE)
    {
        if (*(sim_data->data) & 0x03) /* 0000 0011 */
        {
            g_MExE_context.ORPK_support = MMI_TRUE;
        }

        if (*(sim_data->data) & 0x0C) /* 0000 1100 */
        {
            g_MExE_context.ARPK_support = MMI_TRUE;
        }

        if (*(sim_data->data) & 0x30) /* 0011 0000 */
        {
            g_MExE_context.TPRPK_support = MMI_TRUE;
        }

        if (g_MExE_context.ORPK_support || g_MExE_context.ARPK_support || g_MExE_context.TPRPK_support)
        {
            g_MExE_context.MExE_valid = MMI_TRUE;
        }
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 0 */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mexe_read_rpk_file_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mexe_read_rpk_file_info_req(U8 file_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sim_get_file_info(
        file_id,
        NULL,
        MMI_SIM1,
        mmi_mexe_read_rpk_file_info_rsp,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mexe_read_rpk_file_info_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mexe_read_rpk_file_info_rsp(srv_sim_cb_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_file_info_struct *sim_info = (srv_sim_file_info_struct *) param->data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->result == MMI_TRUE)
    {
        g_MExE_context.rpk_record_length = (U8) (sim_info->file_size / sim_info->num_of_rec);
        g_MExE_context.rpk_record_total = (U8) sim_info->num_of_rec;
        g_MExE_context.rpk_record_read = 0;
    }
    else
    {
        /* error handler for allocated and activated file not found */
        mmi_mexe_finish_rpk_file(MMI_FALSE);
    }

    mmi_mexe_retrieve_certificate_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mexe_read_rpk_file_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mexe_read_rpk_file_req(U8 file_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sim_read_record(
        file_id, /* sim_file_index_enum */
        NULL, /* sim_file_id_enum */
        g_MExE_context.rpk_record_read,
        g_MExE_context.rpk_record_length,
        MMI_SIM1,
        mmi_mexe_read_rpk_file_rsp,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mexe_read_rpk_file_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mexe_read_rpk_file_rsp(srv_sim_cb_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_data_struct *sim_data = (srv_sim_data_struct *) param->data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param->result == MMI_TRUE)
    {
        if ((++g_MExE_context.rpk_record_read) == g_MExE_context.rpk_record_total)
        {
            mmi_mexe_finish_rpk_file(MMI_TRUE);
        }

        if (sim_data->data[0] == 0xFF)
        {
            /* certificate descriptor is invalid */
            mmi_mexe_retrieve_certificate_handler();
            return;
        }

        if (g_MExE_context.required_type != MExE_CERTIFICATE_ALL && g_MExE_context.required_type != sim_data->data[2])
        {
            /* certificate type is not desired */
            mmi_mexe_retrieve_certificate_handler();
            return;
        }

        /* prepare parameters to read instance */
        memcpy(&g_MExE_context.certificate_file_id[0], &sim_data->data[3], 2);
        g_MExE_context.certificate_file_length = sim_data->data[7] * 256 + sim_data->data[8];
        g_MExE_context.certificate_file_read_cycle = 0;
        if ((g_MExE_context.certificate_file_length % 256) == 0 && (g_MExE_context.certificate_file_length / 256) > 0)
        {
            g_MExE_context.certificate_file_total_cycle = g_MExE_context.certificate_file_length / 256 - 1;
        }
        else
        {
            g_MExE_context.certificate_file_total_cycle = g_MExE_context.certificate_file_length / 256;
        }

        memset(g_MExE_context.key_identifier, 0, MAX_MExE_IDENTIFIER_LEN);
        memset(g_MExE_context.certificate_identifier, 0, MAX_MExE_IDENTIFIER_LEN);

        /* keep the root public key description file */
        g_MExE_context.authority_certificate = sim_data->data[1];
        g_MExE_context.certificate_type = sim_data->data[2];
        g_MExE_context.key_identifier_length = sim_data->data[9];
        memcpy(g_MExE_context.key_identifier, sim_data->data + 10, g_MExE_context.key_identifier_length);

        if (sim_data->data[10 + g_MExE_context.key_identifier_length] != 0 && sim_data->data[10 + g_MExE_context.key_identifier_length] != 0xFF)
        {
            g_MExE_context.certificate_identifier_length = sim_data->data[10 + g_MExE_context.key_identifier_length];
            memcpy(g_MExE_context.certificate_identifier, sim_data->data + 11 + g_MExE_context.key_identifier_length, g_MExE_context.certificate_identifier_length);
        }
        else
        {
            g_MExE_context.certificate_identifier_length = 0;
        }

        mmi_mexe_read_rpk_instance_req();
    }
    else
    {
        /* error handler for allocated and activated file not found */
        mmi_mexe_finish_rpk_file(MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mexe_finish_rpk_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mexe_finish_rpk_file(pBOOL done_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_MExE_context.ORPK_support && !g_MExE_context.ORPK_finish)
    {
        if (done_flag)
        {
            g_MExE_context.ORPK_finish = 1;
            g_MExE_context.rpk_record_length = 0;
        }
        else
        {
            g_MExE_context.ORPK_support = 0;
        }
        return;
    }

    if (g_MExE_context.ARPK_support && !g_MExE_context.ARPK_finish)
    {
        if (done_flag)
        {
            g_MExE_context.ARPK_finish = 1;
            g_MExE_context.rpk_record_length = 0;
        }
        else
        {
            g_MExE_context.ARPK_support = 0;
        }
        return;
    }

    if (g_MExE_context.TPRPK_support && !g_MExE_context.TPRPK_finish)
    {
        if (done_flag)
        {
            g_MExE_context.TPRPK_finish = 1;
            g_MExE_context.rpk_record_length = 0;
        }
        else
        {
            g_MExE_context.TPRPK_support = 0;
        }
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mexe_read_rpk_instance_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mexe_read_rpk_instance_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 path[6] = {0x7F, 0x20, 0x5F, 0x3C, 0, 0};
    U16 length, offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    path[4] = g_MExE_context.certificate_file_id[0];
    path[5] = g_MExE_context.certificate_file_id[1];

    offset = g_MExE_context.certificate_file_read_cycle * 256;
    length = (g_MExE_context.certificate_file_total_cycle == g_MExE_context.certificate_file_read_cycle) ? g_MExE_context.certificate_file_length - offset : 256;

    g_MExE_context.sim_data_path = OslMalloc(6);
    memcpy(g_MExE_context.sim_data_path, path, 6);

    srv_sim_read_binary(
        FILE_NONE,
        g_MExE_context.sim_data_path,
        offset,
        length,
        MMI_SIM1,
        mmi_mexe_read_rpk_instance_rsp,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mexe_read_rpk_instance_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mexe_read_rpk_instance_rsp(srv_sim_cb_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_data_struct *sim_data = (srv_sim_data_struct *) param->data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(g_MExE_context.certificate_data + (g_MExE_context.certificate_file_read_cycle * 256), sim_data->data, sim_data->length);

    OslMfree(g_MExE_context.sim_data_path);

    if (g_MExE_context.certificate_file_total_cycle == g_MExE_context.certificate_file_read_cycle)
    {
        mmi_mexe_send_sim_certificate_record_ind();
    }
    else
    {
        g_MExE_context.certificate_file_read_cycle++;
        mmi_mexe_read_rpk_instance_req();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mexe_retrieve_certificate_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mexe_retrieve_certificate_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* read EF ORPK */
    if (g_MExE_context.ORPK_support && !g_MExE_context.ORPK_finish)
    {
        g_MExE_context.file_index = ROOT_PUBLIC_KEY_OPERATOR;
        if (g_MExE_context.rpk_record_length == 0)
        {
            mmi_mexe_read_rpk_file_info_req(FILE_ORPK_IDX);
        }
        else
        {
            mmi_mexe_read_rpk_file_req(FILE_ORPK_IDX);
        }
        return;
    }

    /* read EF ARPK */
    if (g_MExE_context.ARPK_support && !g_MExE_context.ARPK_finish)
    {
        g_MExE_context.file_index = ROOT_PUBLIC_KEY_ADMINISTRATOR;
        if (g_MExE_context.rpk_record_length == 0)
        {
            mmi_mexe_read_rpk_file_info_req(FILE_ARPK_IDX);
        }
        else
        {
            mmi_mexe_read_rpk_file_req(FILE_ARPK_IDX);
        }
        return;
    }

    /* read EF TPRPK */
    if (g_MExE_context.TPRPK_support && !g_MExE_context.TPRPK_finish)
    {
        g_MExE_context.file_index = ROOT_PUBLIC_KEY_PARTY;
        if (g_MExE_context.rpk_record_length == 0)
        {
            mmi_mexe_read_rpk_file_info_req(FILE_TPRPK_IDX);
        }
        else
        {
            mmi_mexe_read_rpk_file_req(FILE_TPRPK_IDX);
        }
        return;
    }

    g_MExE_context.file_index = ROOT_PUBLIC_KEY_NONE;
    mmi_mexe_get_sim_certificate_rsp();
}

#endif /* __MMI_MExE_SUPPORT__ */

