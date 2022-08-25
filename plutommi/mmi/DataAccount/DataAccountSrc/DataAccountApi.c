/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  DataAccountApi.c
 *
 * Project:
 * --------
 *  Pluto
 *
 * Description:
 * ------------
 *  This file provide basic interfaces.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __TCPIP__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "SimCtrlSrvGprot.h"
#include "DataaccountProt.h"
#include "cbm_api.h"
#include "TetheringSrvGprot.h"
#include "mmi_frm_utility_gprot.h"

/***************************************************************************** 
 * Variable
 *****************************************************************************/

/***************************************************************************** 
 * Apis
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_get_available_sim_num
 * DESCRIPTION
 *  This function is used to get available SIM number
 * PARAMETERS
 *  void
 * RETURNS
 *  available SIM number
 *****************************************************************************/
U32 mmi_dtcnt_get_available_sim_num(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_sim_enum sim_id;
    U32 available_sim_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        sim_id = mmi_frm_index_to_sim(i);
        if (srv_sim_ctrl_is_available(sim_id))
        {
            available_sim_num++;
        }
    }
    return available_sim_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_is_account_in_use
 * DESCRIPTION
 *  This function is used to check account is in use or not
 * PARAMETERS     
 *  account_id       [IN]     account id
 * RETURNS
 *  return MMI_TRUE if account is used, or MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_dtcnt_is_account_in_use(U32 account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                     */
    /*----------------------------------------------------------------*/
    cbm_bearer_state_enum status = CBM_DEACTIVATED;
    srv_dtcnt_sim_type_enum sim_info = SRV_DTCNT_SIM_TYPE_1;
    cbm_sim_id_enum sim_id = CBM_SIM_ID_SIM1;
    U32 acct_id;
    U32 decoded_pure_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                           */
    /*----------------------------------------------------------------*/
    srv_dtcnt_get_sim_info(account_id, &sim_info);    
    sim_id = (cbm_sim_id_enum)(sim_info - 1);
    acct_id = cbm_encode_data_account_id(account_id, sim_id, 0, KAL_FALSE);
    
    status = (cbm_bearer_state_enum)cbm_get_bearer_status(acct_id);
    
    if (status == CBM_ACTIVATED || 
        status == CBM_ACTIVATING ||
        status == CBM_DEACTIVATING)
    {
        return MMI_TRUE;
    }

    decoded_pure_id = (U32)cbm_get_original_account(srv_tethering_usb_qurey_acct_id());
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_DTCNT_IS_ACCOUNT_IN_USE, decoded_pure_id, account_id);
    if (account_id == decoded_pure_id)
    {
        acct_id = cbm_encode_data_account_id(CBM_USB_TR_PS_ACCT_ID, sim_id, 0, KAL_FALSE);    
        status = (cbm_bearer_state_enum)cbm_get_bearer_status(acct_id);        
        if (status == CBM_ACTIVATED || 
            status == CBM_ACTIVATING ||
            status == CBM_DEACTIVATING)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


#endif /* __TCPIP__ */


