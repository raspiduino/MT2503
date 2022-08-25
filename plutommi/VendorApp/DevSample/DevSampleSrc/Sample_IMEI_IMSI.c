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
 *  Sample_IMEI_IMSI.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Sample code for get IMEI and IMSI number
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#include "stack_config.h"

extern task_indx_type mod_task_g[];

#include "mmi_msg_struct.h"
#include "APPSDKFrameworkGProt.h"
#include "APPSDKSystemServiceGProt.h"


/****************************************************************************
*
*  [Sample]
*  Purpose   : This sample code provides how to get the IMEI and IMSI numbers.
*  
*  Function  : How to send the message to L4 layer in order to get the IMEI or
*              IMSI number, and how to deal with the response when the number
*              comes back.
*  
*  Notice    : 
*  
*  Branch    : 08A, 08B, MAUI
*  
*  API Ref   : MSG_ID_MMI_NW_GET_IMEI_REQ & MSG_ID_MMI_NW_GET_IMEI_RSP
*              MSG_ID_MMI_SMU_GET_IMSI_REQ & MSG_ID_MMI_SMU_GET_IMSI_RSP
*  
*****************************************************************************/

#define MMI_SAMPLE_IMEI_LEN         (16)    /* IMEI */
#define MMI_SAMPLE_IMEI_SVN_LEN     (3)     /* IMEI SVN */
#define MMI_SAMPLE_IMSI_LEN         (17)    /* IMSI */

typedef struct
{
    kal_uint8   imei[MMI_SAMPLE_IMEI_LEN * ENCODING_LENGTH];    /* IMEI */
    kal_uint8   svn[MMI_SAMPLE_IMEI_SVN_LEN * ENCODING_LENGTH]; /* IMEI SVN */
}mmi_sample_imei_context_struct;

typedef struct
{
    kal_uint8   imsi[MMI_SAMPLE_IMSI_LEN * ENCODING_LENGTH];    /* IMSI */
}mmi_sample_imsi_context_struct;

static mmi_sample_imei_context_struct g_sample_imei_cntx;
static mmi_sample_imsi_context_struct g_sample_imsi_cntx;


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_get_imei_response
 * DESCRIPTION
 *  Call back function of the IMEI response message
 * PARAMETERS
 *  msg_ptr             [IN]        response date struct
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sample_get_imei_response(void * msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_get_imei_rsp_struct  * imei_rsp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear response handler */
    ClearProtocolEventHandler(MSG_ID_MMI_NW_GET_IMEI_RSP);
    
    /* convert the msg_ptr to imei_rep type */
    imei_rsp = (mmi_nw_get_imei_rsp_struct *)msg_ptr;

    /* check the response is correct or not */
    if (KAL_TRUE == imei_rsp->result)
    {
        /* get the IMEI number successful */
        mmi_asc_n_to_wcs((U16*)g_sample_imei_cntx.imei, (S8*) imei_rsp->imei, sizeof(imei_rsp->imei));
        mmi_asc_n_to_wcs((U16*)g_sample_imei_cntx.svn, (S8*) imei_rsp->svn, sizeof(imei_rsp->svn));
    }
    else
    {
        /* if it is aborted when get the imei, appliction just do nothing */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_get_imei_request
 * DESCRIPTION
 *  Send the message to L4 in order to get the IMEI number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_get_imei_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct  * ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set imei response handler */
    SetProtocolEventHandler(mmi_sample_get_imei_response, MSG_ID_MMI_NW_GET_IMEI_RSP);

    /* allocate the ilm struct memory */
    ilm_ptr = allocate_ilm(MOD_MMI);

    /* fill the member of the ilm struct */
    ilm_ptr->msg_id         = MSG_ID_MMI_NW_GET_IMEI_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct *) NULL;
    ilm_ptr->peer_buff_ptr  = (peer_buff_struct *) NULL;

    /* send the message */
    SEND_ILM(MOD_MMI, MOD_L4C, MMI_L4C_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_get_imsi_response
 * DESCRIPTION
 *  Call back function of the IMSI response message
 * PARAMETERS
 *  msg_ptr             [IN]        response date struct
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_sample_get_imsi_response(void * msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_get_imsi_rsp_struct *imsi_rsp = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear response handler */
    //ClearProtocolEventHandler(MSG_ID_MMI_SMU_GET_IMSI_RSP);
    mmi_frm_clear_protocol_event_handler(MSG_ID_MMI_SMU_GET_IMSI_RSP, mmi_sample_get_imsi_response);
    
    /* convert the msg_ptr to imsi_rsp type */
    imsi_rsp = (mmi_smu_get_imsi_rsp_struct *)msg_ptr;

    /* check the response is correct or not */
    if (KAL_TRUE == imsi_rsp->result)
    {
        /* get the IMSI number successful */
        mmi_asc_n_to_wcs((U16*)g_sample_imsi_cntx.imsi, (S8*) imsi_rsp->imsi, sizeof(imsi_rsp->imsi));
    }
    else
    {
        /* if it is aborted when get the imsi, appliction just do nothing */
    }
    return  0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sample_get_imsi_request
 * DESCRIPTION
 *  Send the message to L4 in order to get the IMSI number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sample_get_imsi_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set response handler */
    //SetProtocolEventHandler(mmi_sample_get_imsi_response, MSG_ID_MMI_SMU_GET_IMSI_RSP);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_GET_IMSI_RSP, mmi_sample_get_imsi_response, MMI_TRUE);

    /* allocate the ilm struct memory */
    ilm_ptr = allocate_ilm(MOD_MMI);

    /* fill the member of the ilm struct */
    ilm_ptr->msg_id         = MSG_ID_MMI_SMU_GET_IMSI_REQ;
    ilm_ptr->local_para_ptr = (local_para_struct *) NULL;
    ilm_ptr->peer_buff_ptr  = (peer_buff_struct *) NULL;
    
    /*
     * Send the message
     * [Note]: If the __MMI_DUAL_SIM__ is defined, and application wants to get the
     * IMSI of SIM2, the dest_mod must be set MOD_L4C_2. Otherwise, the IMSI of
     * SIM1 will come back.
     */
    SEND_ILM(MOD_MMI, MOD_L4C, MMI_L4C_SAP, ilm_ptr);
    /* SEND_ILM(MOD_MMI, MOD_L4C_2, MMI_L4C_SAP, ilm_ptr); */
}