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
 *  EngineerModeGPRS.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Engineer mode GPRS related items, inlcudes:
 *      - Auto attach
 *      - 1st PDP
 *      - 2nd PDP
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

/***************************************************************************** 
 * Include 
 *****************************************************************************/

#if defined(__MMI_EM_GPRS_PDP__) || defined (__MMI_EM_GPRS_AUTO_ATTACH__) || defined(__MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__)

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ps_public_struct.h"
#include "ps_public_enum.h"
//#include "l4c_common_enum.h"
#include "kal_public_api.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stdio.h"
#include "stack_msgs.h"
#include "EngineerModeResDef.h"
#include "mmi_frm_events_gprot.h"
//#include "l4c_nw_cmd.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalResDef.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "GlobalMenuItems.h"
#include "CustMenuRes.h"
#include "wgui_categories_list.h"
#include "wgui_categories_CM.h"
#include "mmi_frm_input_gprot.h"
#include "stdlib.h"

#include "CommonScreens.h"

#include "mmi_rp_app_engineermode1_def.h"
#include "EngineerModeUtil.h"
#include "EngineerModeDef.h"
#include "EngineerModeType.h"
#include "EngineerModeCommUI.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeGPRS.h"

#ifdef __MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__
#include "EngineerModeCnmgr.h"
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef  __MMI_EM_GPRS_PDP__ 
typedef enum {
   EM_GPRS_ACT_PDP_TYPE_1ST = 0 ,
   EM_GPRS_ACT_PDP_TYPE_2ND_PRIMARY ,
   EM_GPRS_ACT_PDP_TYPE_2ND_SECONDARY
}  EM_GPRS_ACT_PDP_TYPE_ENUM;


typedef struct
{
    U32 highlight;
    U32 cntx_index;
    EM_GPRS_ACT_PDP_TYPE_ENUM activate_pdp_type;
} mmi_em_gprs_act_1st_pdp_cntx_struct;

mmi_em_gprs_act_1st_pdp_cntx_struct *mmi_em_gprs_act_pdp_cntx_p = NULL;

MMI_EM_INIT_ASM(gprs_act_pdp, 
           mmi_em_gprs_act_pdp_cntx_p, 
           sizeof(mmi_em_gprs_act_1st_pdp_cntx_struct))


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/* gprs */
#ifdef __MOD_TCM__
kal_uint8 g_gprs_pdp_idx = 0;
kal_bool g_gprs_set_minqos_required = KAL_FALSE;

#ifdef __R99__
static const kal_uint16 pdp_context_idx[EM_GPRS_PDP_CONTEXT_MAX_NUM][2][18] = 
{
    1, 2, 4, 5, 5, 16, 4, 72, 72, 0, 0, 1, 150, 3, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context1] */
    1, 2, 4, 3, 5, 16, 4, 72, 72, 0, 0, 1, 150, 4, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context2] */
    1, 2, 4, 5, 5, 16, 4, 72, 72, 0, 0, 1, 150, 3, 4, 2, 0, 0, 0, 0, 4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context3] */
    1, 2, 4, 3, 6, 16, 4, 88, 88, 0, 0, 1, 150, 4, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context4] */
    1, 2, 4, 3, 5, 16, 4, 72, 72, 0, 0, 1, 150, 4, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context5] */
    1, 2, 4, 5, 6, 16, 4, 88, 88, 0, 0, 1, 150, 3, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context6] */
    1, 2, 4, 5, 6, 16, 4, 88, 88, 0, 0, 1, 150, 3, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context7] */
    1, 2, 4, 3, 5, 16, 4, 72, 72, 0, 0, 1, 150, 4, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context8] */
    1, 2, 4, 3, 5, 16, 4, 72, 72, 0, 0, 1, 150, 4, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context9] */
    1, 2, 4, 5, 5, 16, 4, 72, 72, 0, 0, 1, 150, 3, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context10] */
    1, 2, 4, 2, 5, 16, 4, 72, 72, 0, 0, 1, 150, 6, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context11] */
    1, 2, 4, 2, 5, 16, 4, 72, 72, 0, 0, 1, 150, 6, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context12] */
    1, 2, 4, 1, 5, 16, 4, 72, 72, 0, 0, 1, 150, 6, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context13] */
    1, 2, 4, 3, 5, 16, 4, 72, 72, 0, 0, 1, 150, 4, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context14] */
    1, 2, 1, 3, 7, 9, 4, 88, 88, 0, 0, 1, 150, 3, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     /* [PDP context15] */
    1, 2, 4, 5, 6, 17, 4, 88, 88, 0, 0, 1, 150, 3, 4, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,    /* [PDP context 30] */
    1, 2, 4, 3, 7, 17, 4, 120, 120, 0, 0, 1, 150, 4, 7, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,  /* [PDP context 31] */
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__)*/
};

#else /* __R99__ */ 
static const kal_uint16 pdp_context_idx[EM_GPRS_PDP_CONTEXT_MAX_NUM][2][6] = 
{
    1, 2, 4, 5, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context1] */
    1, 2, 4, 3, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context2] */
    1, 2, 4, 5, 5, 16, 0, 0, 4, 0, 2, 0,    /* [PDP context3] */
    1, 2, 4, 3, 6, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context4] */
    1, 2, 4, 3, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context5] */
    1, 2, 4, 5, 6, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context6] */
    1, 2, 4, 5, 6, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context7] */
    1, 2, 4, 3, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context8] */
    1, 2, 4, 3, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context9] */
    1, 2, 4, 5, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context10] */
    1, 2, 4, 2, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context11] */
    1, 2, 4, 2, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context12] */
    1, 2, 4, 1, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context13] */
    1, 2, 4, 3, 5, 16, 0, 0, 0, 0, 0, 0,    /* [PDP context14] */
    1, 2, 1, 3, 7, 9, 0, 0, 0, 0, 0, 0      /* [PDP context15] */
};
#endif /* __R99__ */ 

#endif /* __MOD_TCM__*/  
#endif /*__MMI_EM_GPRS_PDP__*/
/***************************************************************************** 
 * Local Function
 *****************************************************************************/

#ifdef __MMI_EM_GPRS_AUTO_ATTACH__
static void EntryEmAutoAttach(void);
#endif


#ifdef __MMI_EM_GPRS_PDP__
static void mmi_em_gprs_send_act_test_req(l4c_tcm_pdp_action_enum activity);
static mmi_em_gprs_set_qos_eqos_res_hdlr(MMI_BOOL success);
#endif




#ifdef __MMI_EM_GPRS_FAST_DORMANCY__
/* Fast dormancy */
/*static function*/
static void mmi_em_gprs_act_fast_dormancy_hdlr(void);
static void mmi_em_gprs_act_enter_fast_dormancy(void * inMsg);
static mmi_ret mmi_em_gprs_act_fast_dormancy_proc(mmi_event_struct *evt);
static void mmi_em_gprs_act_fast_dormancy_set_scr_fd();
static void mmi_em_gprs_act_set_fast_dormancy_done(void * inMsg);

#endif





/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
#ifdef __MMI_EM_GPRS_PDP__

#ifdef __MOD_TCM__
#ifdef __R99__
/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsActFillstruct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l4c_eqos_st     [?]         
 *  idx             [IN]        
 *  ismin           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void EngineerModeGprsActFillstruct(l4c_eqos_struct *l4c_eqos_st, kal_uint8 idx, kal_uint8 ismin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ismin != 0)
    {
        ismin = 1;
        l4c_eqos_st->qos_type = ATCI_MIN_QOS;
    }
    else
    {
        ismin = 0;
        l4c_eqos_st->qos_type = ATCI_REQ_QOS;
    }

    idx -= 1;

    MMI_ASSERT(idx <= EM_GPRS_PDP_CONTEXT_MAX_NUM);
        
    if (mmi_em_gprs_act_pdp_cntx_p->activate_pdp_type == EM_GPRS_ACT_PDP_TYPE_1ST)
    {
        l4c_eqos_st->context_id = TCM_EM_PDP_CID_1;
    }
    else
    {
        l4c_eqos_st->context_id = TCM_EM_PDP_CID_2;
    }

    l4c_eqos_st->traffic_class = (kal_uint8)pdp_context_idx[idx][ismin][6];
    l4c_eqos_st->delivery_order = (kal_uint8)pdp_context_idx[idx][ismin][11];
    l4c_eqos_st->delivery_of_err_sdu = (kal_uint8)pdp_context_idx[idx][ismin][15];
    l4c_eqos_st->max_sdu_size = (kal_uint8)pdp_context_idx[idx][ismin][12];
    l4c_eqos_st->max_bitrate_up_lnk = (kal_uint8)pdp_context_idx[idx][ismin][7];
    l4c_eqos_st->max_bitrate_down_lnk = (kal_uint8)pdp_context_idx[idx][ismin][8];
    l4c_eqos_st->residual_bit_err_rate = (kal_uint8)pdp_context_idx[idx][ismin][14];
    l4c_eqos_st->sdu_err_ratio = (kal_uint8)pdp_context_idx[idx][ismin][13];
    l4c_eqos_st->transfer_delay = (kal_uint8)pdp_context_idx[idx][ismin][16];
    l4c_eqos_st->traffic_hndl_priority = (kal_uint8)pdp_context_idx[idx][ismin][17];
    l4c_eqos_st->guarntd_bit_rate_up_lnk = (kal_uint8)pdp_context_idx[idx][ismin][9];
    l4c_eqos_st->guarntd_bit_rate_down_lnk = (kal_uint8)pdp_context_idx[idx][ismin][10];
}
#else /* __R99__ */ 


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsActFillstruct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l4c_qos_st      [?]         
 *  idx             [IN]        
 *  ismin           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void EngineerModeGprsActFillstruct(l4c_qos_struct *l4c_qos_st, kal_uint8 idx, kal_uint8 ismin)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ismin != 0)
    {
        ismin = 1;
        l4c_qos_st->qos_type = ATCI_MIN_QOS;
    }
    else
    {
        ismin = 0;
        l4c_qos_st->qos_type = ATCI_REQ_QOS;
    }

    idx -= 1;
    MMI_ASSERT(idx <= EM_GPRS_PDP_CONTEXT_MAX_NUM);

    if (mmi_em_gprs_act_pdp_cntx_p->activate_pdp_type == EM_GPRS_ACT_PDP_TYPE_1ST)
    {
        l4c_qos_st->context_id = TCM_EM_PDP_CID_1;
    }
    else	  
    {
        l4c_qos_st->context_id = TCM_EM_PDP_CID_2;
    }

    l4c_qos_st->delay_class = pdp_context_idx[idx][ismin][2];
    l4c_qos_st->reliability_class = pdp_context_idx[idx][ismin][3];
    l4c_qos_st->peak_throughput = pdp_context_idx[idx][ismin][4];
    l4c_qos_st->precedence_class = pdp_context_idx[idx][ismin][1];
    l4c_qos_st->mean_throughput = pdp_context_idx[idx][ismin][5];

}

#endif /* __R99__ */ 
#endif /* __MOD_TCM__ */ 


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsActivatePDPContext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pdp_idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsActivatePDPContext(kal_uint8 pdp_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
#if defined(__R99__) && defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
#endif /*defined(__R99__) && defined(__GSM_RAT__) && defined(__UMTS_RAT__)*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_em_gprs_act_pdp_cntx_p->activate_pdp_type == EM_GPRS_ACT_PDP_TYPE_1ST ||
        mmi_em_gprs_act_pdp_cntx_p->activate_pdp_type == EM_GPRS_ACT_PDP_TYPE_2ND_PRIMARY)
    {
        mmi_ps_set_definition_req_struct *msg_p;    
        
        msg_p = OslConstructDataPtr(sizeof(mmi_ps_set_definition_req_struct));
        if (EM_GPRS_ACT_PDP_TYPE_1ST == mmi_em_gprs_act_pdp_cntx_p->activate_pdp_type)
            msg_p->pdp.context_id = TCM_EM_PDP_CID_1;  /* 1st PDP */
        else
           msg_p->pdp.context_id = TCM_EM_PDP_CID_2;  /* 2nd PDP */

        msg_p->pdp.dcomp_algo = 0;
        msg_p->pdp.hcomp_algo = 0;
        msg_p->pdp.pdp_type = IPV4_ADDR_TYPE;
        msg_p->pdp.pdp_addr_len = IPV4_ADDR_LEN;
        
    #if defined(__R99__) && defined(__GSM_RAT__) && defined(__UMTS_RAT__)
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
    #endif /* defined(__R99__) && defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
        {
            msg_p->pdp.apn_length = 12;
            strcpy((kal_char*) msg_p->pdp.apn, "smg7.etsi.fr");
            msg_p->pdp.addr_val[0] = 192;
            msg_p->pdp.addr_val[1] = 168;
            msg_p->pdp.addr_val[2] = 1;
            msg_p->pdp.addr_val[3] = 1;
        }
        EngineerModeSendMsg_Check_Prefer_SIM(MSG_ID_MMI_PS_SET_DEFINITION_REQ, msg_p, NULL);
    } 
    else        
    {
        mmi_ps_set_sec_definition_req_struct *msg_p;    
        
        msg_p = OslConstructDataPtr(sizeof(mmi_ps_set_definition_req_struct));
        msg_p->pdp.context_id = TCM_EM_PDP_CID_2;  /* 2nd PDP */
        msg_p->pdp.prim_context_id = 2;  
        msg_p->pdp.dcomp_algo= 0;
        msg_p->pdp.hcomp_algo= 0;
        EngineerModeSendMsg_Check_Prefer_SIM(MSG_ID_MMI_PS_SET_SEC_DEFINITION_REQ, msg_p, NULL);          
    }
#endif /* __MOD_TCM__ */ 

#ifndef __MTK_TARGET__
    mmi_em_success_popup();
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsSetDefinitionRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsSetDefinitionRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
    mmi_ps_set_definition_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result == KAL_FALSE)
    {
        mmi_em_fail_popup();
    }
    else
    {

    #ifdef __R99__
        mmi_ps_set_eqos_req_struct *msg_p;

        msg_p = OslConstructDataPtr(sizeof(mmi_ps_set_eqos_req_struct));
        msg_p->qos_type = ATCI_REQ_QOS;
        EngineerModeGprsActFillstruct(&msg_p->min, g_gprs_pdp_idx, 0);

        EngineerModeSendMsg_Check_Prefer_SIM(MSG_ID_MMI_PS_SET_EQOS_REQ, msg_p, NULL);
    #else /* __R99__ */ 
        mmi_ps_set_qos_req_struct *msg_p;

        msg_p = OslConstructDataPtr(sizeof(mmi_ps_set_qos_req_struct));
        msg_p->qos_type = ATCI_REQ_QOS;
        EngineerModeGprsActFillstruct(&msg_p->min, g_gprs_pdp_idx, 0);

        EngineerModeSendMsg_Check_Prefer_SIM(MSG_ID_MMI_PS_SET_QOS_REQ, msg_p, NULL);
    #endif /* __R99__ */ 
    }
#endif /* __MOD_TCM__ */ 
}

#ifdef __MOD_TCM__
/*****************************************************************************
 * FUNCTION
 *  mmi_em_gprs_send_act_test_req
 * DESCRIPTION
 *   mmi_em_gprs_send_act_test_req
 * PARAMETERS
 *  activity       [in]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_gprs_send_act_test_req(l4c_tcm_pdp_action_enum activity)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ps_act_test_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Joseph: Do not set min QoS here. Set Min QoS manually from CATCHER */
    msg_p = OslConstructDataPtr(sizeof(mmi_ps_act_test_req_struct));
    msg_p->opcode = (U8)activity;

    if (mmi_em_gprs_act_pdp_cntx_p->activate_pdp_type == EM_GPRS_ACT_PDP_TYPE_1ST)
    {
        msg_p->cid = TCM_EM_PDP_CID_1;  /* 1st PDP */
    }
    else
    {
        msg_p->cid = TCM_EM_PDP_CID_2;  /* 2nd PDP */
    }    
    EngineerModeSendMsg_Check_Prefer_SIM(MSG_ID_MMI_PS_ACT_TEST_REQ, msg_p, NULL);
}

static mmi_em_gprs_set_qos_eqos_res_hdlr(MMI_BOOL success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (success)
    {
        mmi_em_gprs_send_act_test_req(TCM_PDP_ACTIVATE);
    }
    else
    {
        mmi_em_fail_popup();
    }     
}
#endif /*__MOD_TCM__*/

#ifdef __R99__
/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsSetEQosRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsSetEQosRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
    mmi_ps_set_eqos_rsp_struct *rsp_p = inMsg;
//    mmi_ps_act_test_req_struct *msg_p;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_gprs_set_qos_eqos_res_hdlr((MMI_BOOL)rsp_p->result);    
#endif /* __MOD_TCM__ */ 
}
#endif /* __R99__ */ 


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsSetQosRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsSetQosRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
    mmi_ps_set_qos_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_em_gprs_set_qos_eqos_res_hdlr((MMI_BOOL)rsp_p->result);    
#endif /* __MOD_TCM__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsActTestRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsActTestRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
    mmi_ps_act_test_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_display_notify_popup(rsp_p->result);
    
#endif /* __MOD_TCM__ */ 
}



/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsDeactivatePDPReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsDeactivatePDPReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_gprs_send_act_test_req(TCM_PDP_DEACTIVATE);
#endif /* __MOD_TCM__ */ /* __MOD_TCM */

#ifndef __MTK_TARGET__
    mmi_em_success_popup();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsDeactivatePDPRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsDeactivatePDPRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
    mmi_ps_act_test_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_display_notify_popup(rsp_p->result);    
#endif /* __MOD_TCM__ */ /* __MOD_TCM */
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsSendDataReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsSendDataReq(kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
    mmi_ps_send_data_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = OslConstructDataPtr(sizeof(mmi_ps_send_data_req_struct));

    if (mmi_em_gprs_act_pdp_cntx_p->activate_pdp_type == EM_GPRS_ACT_PDP_TYPE_1ST)
    {
        msg_p->cid = TCM_EM_PDP_CID_1;  /* 1st PDP */
    }
    else	 
    {
        msg_p->cid = TCM_EM_PDP_CID_2;  /* 2nd PDP */
    }    
    msg_p->size = size;

    EngineerModeSendMsg_Check_Prefer_SIM(MSG_ID_MMI_PS_SEND_DATA_REQ, msg_p, NULL);
#endif /* __MOD_TCM__ */ /* __MOD_TCM */

#ifndef __MTK_TARGET__
    mmi_em_success_popup();
#endif 

}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsSendDataRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsSendDataRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
    mmi_ps_send_data_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_display_notify_popup(rsp_p->result);    
#endif /* __MOD_TCM__ */ /* __MOD_TCM */
}

static void EMGPRSActivatePDPReq(void);
/*****************************************************************************
 * FUNCTION
 *  SendGprsActivatePDPContext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pdp_idx     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void SendGprsActivatePDPContext(U8 pdp_idx)
{
#ifdef __MOD_TCM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gprs_pdp_idx = pdp_idx;
    g_gprs_set_minqos_required = KAL_FALSE;
#endif /* __MOD_TCM__ */ 

    EngineerModeGprsActivatePDPContext(pdp_idx);
}

static void mmi_em_gprs_act_active_pdp_highlight_idx(S32 index);

static void mmi_em_gprs_act_fill_pdp_item_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;
    UI_string_type pdp_context;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pdp_context = get_string(STR_ID_EM_GPRS_PDP_CONTEXT);
    for(i = 0, j = 1; i<= EM_GPRS_PDP_CONTEXT_MAX_NUM; i++, j++)
    {
        
    #ifdef __R99__
        if ( i == EM_GPRS_PDP_CONTEXT_30)
            j = 30;
    #endif
    kal_wsprintf((WCHAR*)subMenuData[i], "%w %d", pdp_context, j);
    subMenuDataPtrs[i] = subMenuData[i];
    #ifdef __R99__
        if ( i == EM_GPRS_PDP_CONTEXT_31)
            break;
    #else
        if ( i == EM_GPRS_PDP_CONTEXT_15)
            break;
    #endif  /*__R99__*/   
        
    }
#ifdef __R99__
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*defined(__GSM_RAT__) && defined(__UMTS_RAT__)*/
#endif /*__R99__*/
}

static MMI_RET mmi_em_gprs_act_active_pdp_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            {
                mmi_frm_scrn_active_evt_struct *evt = (mmi_frm_scrn_active_evt_struct *)param;
                if (evt->is_first_active)
                {
                    mmi_em_gprs_act_fill_pdp_item_list();                
                    ShowCategory53Screen(STR_ID_EM_GPRS_ACTIVATE_PDP,
                                    0,
                                    STR_GLOBAL_OK,
                                    0,
                                    STR_GLOBAL_BACK,
                                    0,
                                    EM_GPRS_PDP_CONTEXT_MAX_NUM,
                                    subMenuDataPtrs,
                                    MMI_EM_INDEX_ICON_LIST,
                                    NULL,
                                    0,
                                    0,
                                    0);    
                }
                else
                {
                    mmi_frm_scrn_close_active_id();
                }                
            }
            break;

        case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
            {
                cat_evt_struct *evt = (cat_evt_struct *)param;
                mmi_em_gprs_act_active_pdp_highlight_idx(evt->item_index);
            }            
            break;

        case EVT_ID_WGUI_LSK_CLICK:
            EMGPRSActivatePDPReq();
            return MMI_RET_KEY_HANDLED;           


        case EVT_ID_SCRN_DELETE_REQ:
            mmi_frm_scrn_close_active_id();
            break;
    }
    return MMI_RET_OK;
}


static void mmi_em_gprs_act_active_pdp_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_create(mmi_em_get_root_group(),
                        SCR_ID_EM_GPRS_ACTIVATE_PDP_MENU,
                        mmi_em_gprs_act_active_pdp_proc,
                        NULL); 

}

static void mmi_em_gprs_act_active_pdp_highlight_idx(S32 index)
{
    if (NULL == mmi_em_gprs_act_pdp_cntx_p)
    {
         return;
    }
    mmi_em_gprs_act_pdp_cntx_p->cntx_index = index;
}

static void mmi_em_gprs_act_deactive_pdp_hdlr(void)
{
    if (!mmi_frm_scrn_enter(mmi_em_get_root_group(), GLOBAL_SCR_DUMMY, NULL, NULL, MMI_FRM_FULL_SCRN))
        return;
    EngineerModeGprsDeactivatePDPReq();
}

static void mmi_em_gprs_act_send_data_hdlr(MMI_STR_ID str_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_num_editor_struct data = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data.parent_gid = mmi_em_get_root_group();
    data.title_id = str_id;
    data.notify = EmSendDataScreenLSKHandler;
    data.max = 9999999;
    mmi_em_show_num_editor(&data);
}

/*****************************************************************************
 * FUNCTION
 *  EmSendDataScreenLSKHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EmSendDataScreenLSKHandler(MMI_BOOL is_accept, U32 output_num, MMI_ID editor_gid, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(mmi_em_get_root_group(), GLOBAL_SCR_DUMMY, NULL, NULL, MMI_FRM_FULL_SCRN))
        return;

    if (NULL == mmi_em_gprs_act_pdp_cntx_p)
    {
        MMI_ASSERT(0);
    }

    if (mmi_em_gprs_act_pdp_cntx_p->highlight== 0)
    {
        EngineerModeGprsSendDataReq(output_num);
    }
    else
    {
        EngineerModeGprsSendDataReq((U32) (output_num - EM_TCM_PDU_HDR));
    }

}

/*****************************************************************************
 * FUNCTION
 *  EMGPRSActivatePDPReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EMGPRSActivatePDPReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(mmi_em_get_root_group(), GLOBAL_SCR_DUMMY, NULL, NULL, MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    SendGprsActivatePDPContext((U8)(mmi_em_gprs_act_pdp_cntx_p->cntx_index+1));
}
#endif /*__MMI_EM_GPRS_PDP__*/


#ifdef __MMI_EM_GPRS_AUTO_ATTACH__
/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsAttachReq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsAttachReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__

    mmi_nw_set_attach_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* micha0120 */
    SetProtocolEventHandler(EngineerModeGprsAttachRes, MSG_ID_MMI_NW_SET_ATTACH_RSP);

    msg_p = OslConstructDataPtr(sizeof(mmi_nw_set_attach_req_struct));
    msg_p->type = RAC_PS;
    msg_p->opcode = RAC_ATTACH;
    msg_p->is_poweroff = KAL_FALSE;

    EngineerModeSendMsg_Check_Prefer_SIM(MSG_ID_MMI_NW_SET_ATTACH_REQ, msg_p, NULL);

#endif /* __MOD_TCM__ */ /* __MOD_TCM */

#ifndef __MTK_TARGET__
    mmi_em_success_popup();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  EngineerModeGprsAttachRes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void EngineerModeGprsAttachRes(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MOD_TCM__
    //micha0120 begin
    //L4 would send indication to change gprs status using msg_id_mmi_ps_gprs_status_update_ind
    mmi_nw_set_attach_rsp_struct *rsp_p = inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(NULL, MSG_ID_MMI_NW_SET_ATTACH_RSP);
    mmi_em_display_notify_popup(rsp_p->result);
  
    /* micha0120 end */
#endif /* __MOD_TCM__ */ /* __MOD_TCM */
}

/*****************************************************************************
 * FUNCTION
 *  EntryEmAutoAttach
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryEmAutoAttach(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1 Call Exit Handler */
    if (!mmi_frm_scrn_enter(mmi_em_get_root_group(), GLOBAL_SCR_DUMMY, NULL, NULL, MMI_FRM_FULL_SCRN))
        return;

    EngineerModeGprsAttachReq();
}
#endif /* __MMI_EM_GPRS_AUTO_ATTACH__ */

extern void mmi_em_gprs_menu_event_hdlr(cui_menu_event_struct *event)
{
    switch(event->highlighted_menu_id)
    {           

    #ifdef __MMI_EM_GPRS_AUTO_ATTACH__
        case MENU_ID_EM_GPRS_AUTO_ATTACH:
           EntryEmAutoAttach();
           break;
    #endif

    #ifdef __MMI_EM_GPRS_PDP__
        case MENU_ID_EM_GPRS_ACT:
            MMI_EM_ASM_INIT_FUNC(gprs_act_pdp);
            break; 
            
        case MENU_ID_EM_GPRS_PDP_1:
           mmi_em_gprs_act_pdp_cntx_p->activate_pdp_type = EM_GPRS_ACT_PDP_TYPE_1ST;
           break;
		
	case MENU_ID_EM_GPRS_ACTIVATE_PDP:
            mmi_em_gprs_act_active_pdp_hdlr();
            break;
		
	case MENU_ID_EM_GPRS_DEACTIVATE_PDP:
	case MENU_ID_EM_GPRS_PDP_2_DEACTIVATE_PDP:
            mmi_em_gprs_act_deactive_pdp_hdlr();
            break;

	case MENU_ID_EM_GPRS_SEND_DATA_NORM:
            MMI_ASSERT(mmi_em_gprs_act_pdp_cntx_p);
            mmi_em_gprs_act_pdp_cntx_p->highlight = 0;
            mmi_em_gprs_act_send_data_hdlr(STR_ID_EM_GPRS_SEND_DATA_NORM);
            break;

	case MENU_ID_EM_GPRS_SEND_DATA_HDR:
            MMI_ASSERT(mmi_em_gprs_act_pdp_cntx_p);
            mmi_em_gprs_act_pdp_cntx_p->highlight = 1;
            mmi_em_gprs_act_send_data_hdlr(STR_ID_EM_GPRS_SEND_DATA_HDR);
            break;

        case MENU_ID_EM_GPRS_PDP_2:
            mmi_em_gprs_act_pdp_cntx_p->activate_pdp_type = EM_GPRS_ACT_PDP_TYPE_2ND_PRIMARY;
            break;

        case MENU_ID_EM_GPRS_ACTIVATE_2ND_PDP_PRIMARY:
            mmi_em_gprs_act_pdp_cntx_p->activate_pdp_type = EM_GPRS_ACT_PDP_TYPE_2ND_PRIMARY;
            mmi_em_gprs_act_active_pdp_hdlr();
            break;

        case MENU_ID_EM_GPRS_ACTIVATE_2ND_PDP_SECOND:
            mmi_em_gprs_act_pdp_cntx_p->activate_pdp_type = EM_GPRS_ACT_PDP_TYPE_2ND_SECONDARY;
            mmi_em_gprs_act_active_pdp_hdlr();
            break;
        /*Fast dormancy*/
        
 #ifdef __MMI_EM_GPRS_FAST_DORMANCY__
		case MENU_ID_EM_GPRS_FAST_DORMANCY:
			mmi_em_gprs_act_fast_dormancy_hdlr();
			break;
#endif
			
    #endif /*__MMI_EM_GPRS_PDP__*/        

#ifdef __MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__
        case MENU_ID_EM_GPRS_CNMGR_SET_SCRI_LCD_ON_CHECK_TIME:
        case MENU_ID_EM_GPRS_CNMGR_UNSET_SCRI_LCD_ON_CHECK_TIME:
        case MENU_ID_EM_GPRS_CNMGR_SET_SCRI_LCD_OFF_CHECK_TIME:
        case MENU_ID_EM_GPRS_CNMGR_UNSET_SCRI_LCD_OFF_CHECK_TIME:
            mmi_em_cnmgr_scri_menu_select_handler(event);
            break;
#endif

        default:
            break;
    }
}

#ifdef __MMI_EM_GPRS_PDP__
extern void mmi_em_gprs_menu_list_exit_hdlr(cui_menu_event_struct *event)
{
    switch(event->parent_menu_id)
    {
        case MENU_ID_EM_GPRS_ACT:
            if (1 == event->cui_menu_event_flags)
            {
                MMI_EM_ASM_FREE_FUNC(gprs_act_pdp);
                MMI_EM_UNREG_STOP_FUNC(MMI_EM_ASM_STOP_FUNC(gprs_act_pdp));
            }
            break;

        default:
            break;		
    }
}
#endif /*__MMI_EM_GPRS_PDP__*/

void mmi_em_gprs_menu_entry_event_hdlr(cui_menu_event_struct *event)
{
    switch (event->parent_menu_id)
    {

#ifdef __MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__
    case MENU_ID_EM_GPRS_CNMGR_SCRI_CONFIG:
        mmi_em_cnmgr_scri_menu_entry_handler(event);
        break;
#endif

    default:
        break;
    }
}
#endif /*defined(__MMI_EM_GPRS_PDP__) || defined (CFG_MMI_EM_GPRS_AUTO_ATTACH) || defined(__MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__) */





#ifdef __MMI_EM_GPRS_FAST_DORMANCY__

/* Fast dormancy */
#define MMI_EM_GPRS_ACT_FAST_DORMANCY_CHK(_mode, _record)     ((_mode) & (_record))? (1) : (0)
#define MMI_EM_GPRS_ACT_FAST_DORMANCY_SET_ON(_mode, _record)     ((_mode) = (_mode) & (~(_record)))
#define MMI_EM_GPRS_ACT_FAST_DORMANCY_SET_OFF(_mode, _record)     ((_mode) = (_mode) | (_record))

/*static */
static mmi_em_get_conform_test_param_rsp_struct g_get_rsp_fast_dormancy;
static mmi_em_set_conform_test_param_req_struct g_set_req_fast_dormancy;
static MMI_ID g_fast_dormancy_menu_cui;

const MMI_ID mmi_em_gprs_act_fast_dormancy_sub_menu[2] = 
{
	MENU_ID_EM_GPRS_FAST_DORMANCY_ON,
	MENU_ID_EM_GPRS_FAST_DORMANCY_OFF
};

static void mmi_em_gprs_act_fast_dormancy_hdlr(void)
{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_GET_CONFORM_TEST_PARAM_RSP ,mmi_em_gprs_act_enter_fast_dormancy ,MMI_FALSE);
	EngineerModeSendMsg(MSG_ID_MMI_EM_GET_CONFORM_TEST_PARAM_REQ, NULL, NULL);  /*send message to get info*/
}

static void mmi_em_gprs_act_enter_fast_dormancy(void * inMsg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_em_get_conform_test_param_rsp_struct *rsp_p = inMsg;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (rsp_p->result < 0 || rsp_p == NULL)
    {
        mmi_display_popup(
            (UI_string_type)GetString(STR_GLOBAL_FAILED), 
            MMI_EVENT_FAILURE);
        return;                 /* getting L4C data fail */
    }

    g_get_rsp_fast_dormancy.conf_test_mode = rsp_p->conf_test_mode;
	g_get_rsp_fast_dormancy.test_profile = rsp_p->test_profile;
	g_get_rsp_fast_dormancy.result = rsp_p->result;

	g_set_req_fast_dormancy.conf_test_mode = rsp_p->conf_test_mode;
	g_set_req_fast_dormancy.test_profile = rsp_p->test_profile;

	

	mmi_frm_group_create(mmi_em_get_root_group(), GRP_ID_FAST_DORMANCY, mmi_em_gprs_act_fast_dormancy_proc, NULL);
    mmi_frm_group_enter(GRP_ID_FAST_DORMANCY, MMI_FRM_NODE_SMART_CLOSE_FLAG);


    g_fast_dormancy_menu_cui = cui_menu_create(
            GRP_ID_FAST_DORMANCY,
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_APPMAIN,
            MENU_ID_EM_GPRS_FAST_DORMANCY_ROOT,
            MMI_TRUE,
            NULL);
	 cui_menu_run(g_fast_dormancy_menu_cui);
	
	
}

static mmi_ret mmi_em_gprs_act_fast_dormancy_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*) evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
			cui_menu_set_currlist_highlighted_id(g_fast_dormancy_menu_cui ,
			mmi_em_gprs_act_fast_dormancy_sub_menu[MMI_EM_GPRS_ACT_FAST_DORMANCY_CHK(g_get_rsp_fast_dormancy.test_profile,GENERAL_BIT_FOR_DISABLE_SCRI_AND_FD)]);  /* Show setting status */
//			kal_prompt_trace(MOD_MMI,"[Fast dormancy entry] %x",g_get_rsp_fast_dormancy.test_profile);
            break;
        }

		case EVT_ID_CUI_MENU_ITEM_SELECT:
		{
			switch (menu_evt->highlighted_menu_id)
			{
				case MENU_ID_EM_GPRS_FAST_DORMANCY_ON:
					mmi_em_gprs_act_fast_dormancy_set_scr_fd(MMI_TRUE);
					break;
				case MENU_ID_EM_GPRS_FAST_DORMANCY_OFF:
					mmi_em_gprs_act_fast_dormancy_set_scr_fd(MMI_FALSE);
					break;
			}
			break;
		}
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
			cui_menu_close(g_fast_dormancy_menu_cui);
            break;
        }
		case EVT_ID_GROUP_DEINIT:
		case EVT_ID_GROUP_GOBACK:
		{
			cui_menu_close(g_fast_dormancy_menu_cui);
			mmi_frm_group_close(GRP_ID_FAST_DORMANCY);
			break;
		}
		default:
        {
            break;
        }
    }

    return MMI_RET_OK;
}


void mmi_em_gprs_act_fast_dormancy_set_scr_fd(MMI_BOOL status)
{	
	
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_em_set_conform_test_param_req_struct  *msg_set_req;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_set_req = OslConstructDataPtr(sizeof(mmi_em_set_conform_test_param_req_struct)); /* alloc contrl buffer for message*/

	if (status)
    {
		MMI_EM_GPRS_ACT_FAST_DORMANCY_SET_ON(g_set_req_fast_dormancy.test_profile, GENERAL_BIT_FOR_DISABLE_SCRI_AND_FD);
//	    kal_prompt_trace(MOD_MMI,"[Fast dormancy set on] %x",g_set_req_fast_dormancy.test_profile);
    }
	else
    {
		MMI_EM_GPRS_ACT_FAST_DORMANCY_SET_OFF(g_set_req_fast_dormancy.test_profile, GENERAL_BIT_FOR_DISABLE_SCRI_AND_FD);
//		kal_prompt_trace(MOD_MMI,"[Fast dormancy set off] %x",g_set_req_fast_dormancy.test_profile);

	}

	/*Generate message*/
	msg_set_req->test_profile = g_set_req_fast_dormancy.test_profile;
	msg_set_req->conf_test_mode = g_set_req_fast_dormancy.conf_test_mode;
	
	/*Send message*/
	EngineerModeSendMsg(MSG_ID_MMI_EM_SET_CONFORM_TEST_PARAM_REQ, msg_set_req, NULL);
	mmi_frm_set_protocol_event_handler(MSG_ID_MMI_EM_SET_CONFORM_TEST_PARAM_RSP ,mmi_em_gprs_act_set_fast_dormancy_done ,MMI_FALSE);
}

void mmi_em_gprs_act_set_fast_dormancy_done(void * inMsg)
{
	
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_em_set_conform_test_param_rsp_struct *rsp_p = inMsg;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_p->result < 0 || rsp_p == NULL)
	{
		/* un-successful */
		 mmi_display_popup(
            (UI_string_type)GetString(STR_GLOBAL_FAILED), 
            MMI_EVENT_FAILURE);
	}
	else if (rsp_p->result >= 0)
	{
		
		/* successful */
		mmi_display_popup(
            (UI_string_type)GetString(STR_GLOBAL_DONE), 
            MMI_EVENT_SUCCESS);
		g_get_rsp_fast_dormancy.test_profile = g_set_req_fast_dormancy.test_profile;
		g_get_rsp_fast_dormancy.conf_test_mode = g_set_req_fast_dormancy.conf_test_mode;
		
	}
	
}

#endif /* __MMI_EM_GPRS_FAST_DORMANCY__*/







