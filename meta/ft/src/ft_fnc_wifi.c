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
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   ft_fnc_wifi.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   WiFi calibration functions 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined(__WIFI_SUPPORT__)

/*************************************************************************
* Include Statements for KAL
 *************************************************************************/
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#ifdef MTK_TARGET
#include "app_buff_alloc.h"
#endif /* MTK_TARGET */


/*************************************************************************
* Include Statements for MAUI
 *************************************************************************/
#include "ft_msg.h"
#include "ft_private.h"
#include "wndrv_cal.h"
#include "wndrv_ft_msg.h"
#include "fctycomp_config.h"
#include "stack_config.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "wifi_common_config.h"
/* for build warning */
extern void wndrv_cal_ALC_Slope_2400M( wndrv_cal_ALC_Slope_2400M_struct *t);

/*******************************************************************************
*
*  WiFi Driver SET Operation 
*
*******************************************************************************/
void  FT_WiFi_Set_Req(const FT_WIFI_WNDRV_SET_REQ  *req, peer_buff_struct *p_peer_buff_ptr)
{
	ilm_struct* ilm_ptr;
	wndrv_test_set_req_struct *ptrMsg;
    /* check the custom switch WiFi Feature */
    if(WiFi_Feature_Exist() != KAL_TRUE)
    {
        return;
    }
	ilm_ptr = FT_ALLOC_OTHER_MSG( sizeof(wndrv_test_set_req_struct) );
	/* if ptrMsg != NULL*/
	ptrMsg = (wndrv_test_set_req_struct *)ilm_ptr->local_para_ptr;
	ptrMsg->token = req->header.token;
	ptrMsg->type = req->op;
	kal_mem_cpy(&ptrMsg->data, &req->data, sizeof(ptrMsg->data));
	// assign peer buf 
	ilm_ptr->peer_buff_ptr = p_peer_buff_ptr;
	/* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
	FT_SEND_MSG(MOD_FT, MOD_WNDRV, FT_WNDRV_SAP, MSG_ID_WNDRV_TEST_SET_REQ, ilm_ptr);
}

void  FT_WiFi_Set_Cnf(const wndrv_test_set_cnf_struct  *wndrv_cnf)
{
	ilm_struct	*ilm_ptr;
	FT_WIFI_WNDRV_SET_CNF	*ilm_cnf;
    /* check the custom switch WiFi Feature */
    if(WiFi_Feature_Exist() != KAL_TRUE)
    {
        return;
    }
	// allocate confirm primitive 
	if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_WIFI_WNDRV_SET_CNF))) ) {
		return;
	}
	ilm_cnf = (FT_WIFI_WNDRV_SET_CNF *)ilm_ptr->local_para_ptr;
	// assign primitive id
	ilm_cnf->header.ft_msg_id = FT_WIFI_WNDRV_SET_CNF_ID;
	// assign op 
	ilm_cnf->op = wndrv_cnf->type;
	// assign return status 
	ilm_cnf->status = wndrv_cnf->successful;

	// FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) 
	_FT_SendFtMsgByToken(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr, wndrv_cnf->token);
}

/*******************************************************************************
*
*  WiFi Driver QUERY Operation 
*
*******************************************************************************/
void  FT_WiFi_Query_Req(const FT_WIFI_WNDRV_QUERY_REQ  *req, peer_buff_struct *p_peer_buff_ptr)
{
	ilm_struct* ilm_ptr;
	wndrv_test_query_req_struct *ptrMsg;
    /* check the custom switch WiFi Feature */
    if(WiFi_Feature_Exist() != KAL_TRUE)
    {
        return;
    }	
	ilm_ptr = FT_ALLOC_OTHER_MSG( sizeof(wndrv_test_query_req_struct) );
	/* if ptrMsg != NULL*/
	ptrMsg = (wndrv_test_query_req_struct *)ilm_ptr->local_para_ptr;
	ptrMsg->token = req->header.token;
	ptrMsg->type = req->op;
	// assign peer buf 
	ilm_ptr->peer_buff_ptr = p_peer_buff_ptr;
	/* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
	FT_SEND_MSG(MOD_FT, MOD_WNDRV, FT_WNDRV_SAP, MSG_ID_WNDRV_TEST_QUERY_REQ, ilm_ptr);
}

void  FT_WiFi_Query_Cnf(const wndrv_test_query_cnf_struct  *wndrv_cnf, peer_buff_struct *p_peer_buff_ptr)
{
	ilm_struct	*ilm_ptr;
	FT_WIFI_WNDRV_QUERY_CNF	*ilm_cnf;
    /* check the custom switch WiFi Feature */
    if(WiFi_Feature_Exist() != KAL_TRUE)
    {
        return;
    }
	// allocate confirm primitive 
	if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_WIFI_WNDRV_QUERY_CNF))) ) {
		return;
	}
	ilm_cnf = (FT_WIFI_WNDRV_QUERY_CNF *)ilm_ptr->local_para_ptr;
	// assign primitive id
	ilm_cnf->header.ft_msg_id = FT_WIFI_WNDRV_QUERY_CNF_ID;
	// assign op 
	ilm_cnf->op = wndrv_cnf->type;
	// assign return status 
	ilm_cnf->status = FT_CNF_OK;
	// assign return structure 
	kal_mem_cpy(&ilm_cnf->result, &wndrv_cnf->result, sizeof(ilm_cnf->result));
	// assign peer buf 
	ilm_ptr->peer_buff_ptr = p_peer_buff_ptr;

	// FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) 
	_FT_SendFtMsgByToken(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr, wndrv_cnf->token);
}

/*******************************************************************************
*
*  WiFi Operation
*
*******************************************************************************/
void  FT_WiFi_Operation(const FT_WIFI_REQ *req, peer_buff_struct *peer_buff_in)
{
	kal_uint16	pdu_length=0;
	kal_char	*pdu_ptr=NULL;
	ilm_struct	*ilm_ptr;
	FT_WIFI_CNF	*ilm_cnf;
    /* check the custom switch WiFi Feature */
    if(WiFi_Feature_Exist() != KAL_TRUE)
    {
        return;
    }
	// get peer buf 
	if( NULL != peer_buff_in ) {
		pdu_ptr = get_pdu_ptr( peer_buff_in, &pdu_length );
	}

	// allocate confirm primitive 
	if( NULL == (ilm_ptr=FT_ALLOC_MSG(sizeof(FT_WIFI_CNF))) ) {
		return;
	}
	ilm_cnf = (FT_WIFI_CNF *)ilm_ptr->local_para_ptr;
	// assign primitive id
	ilm_cnf->header.ft_msg_id = FT_WIFI_CNF_ID;
	// assign op 
	ilm_cnf->op = req->op;
	ilm_cnf->status = FT_CNF_OK;

	switch(req->op) {
	case FT_WIFI_OP_QUERY_CHIP_CAPABILITY:
		// get wifi chip capability 
		wndrv_cal_query_chip_capability(&(ilm_cnf->result.capability));
		break;
	case FT_WIFI_OP_SET_MAC_ADDR:
		// set mac addr 
		if( pdu_ptr != NULL)
		    wndrv_cal_macaddr((wndrv_cal_mac_addr_struct *)pdu_ptr);
		break;
	case FT_WIFI_OP_SET_TXPWR_2400M:
		// set 2.4G tx power table
		if( pdu_ptr != NULL) 
		    wndrv_cal_txpwr_2400M((wndrv_cal_txpwr_2400M_struct *)pdu_ptr);
		break;
	case FT_WIFI_OP_SET_TXPWR_5000M:
		// set 5G tx power table 
		if( pdu_ptr != NULL)
		   wndrv_cal_txpwr_5000M((wndrv_cal_txpwr_5000M_struct *)pdu_ptr);
		break;
	case FT_WIFI_OP_SET_DAC_DC_OFFSET:
		// set DAC DC offset 
		if( pdu_ptr != NULL)
		   wndrv_cal_dac_dc_offset((wndrv_cal_dac_dc_offset_struct *)pdu_ptr);
		break;
	case FT_WIFI_OP_SET_TXALC_2400M:
		if( pdu_ptr != NULL)
		    wndrv_cal_ALC_Slope_2400M((wndrv_cal_ALC_Slope_2400M_struct *)pdu_ptr );
    break;
	default:
		// unknown op 
		ilm_cnf->status = FT_CNF_FAIL;
		break;
	}

	// FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) 
	_FT_SendFtMsgByToken(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr, req->header.token);
}

#endif // #if defined(__WIFI_SUPPORT__)
