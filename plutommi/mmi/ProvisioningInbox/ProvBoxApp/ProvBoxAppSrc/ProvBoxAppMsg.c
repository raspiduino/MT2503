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
 * ProvBoxUIMain.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Provisioning Inbox UI main procedure.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__
/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMIDataType.h"
#include "mmi_inet_app_trc.h"

#include "mmi_rp_app_provbox_def.h"
#include "mmi_rp_srv_provbox_def.h"

#ifdef __MMI_PROV_IN_UM__
#include "UMSrvGProt.h"
#endif

#include "ProvBoxSrvGProt.h"
#include "ProvBoxSrvIProt.h"
#include "ProvBoxAppGProt.h"
#include "ProvBoxAppProt.h"

/*****************************************************************************
 * Static Declaration
 *****************************************************************************/
static void mmi_provbox_event_notify_hdlr(mmi_event_struct *evt);

static void mmi_provbox_event_new_msg_hdlr(mmi_event_struct *evt);


#ifdef __MMI_PROV_IN_UM__
static void mmi_provbox_evt_hdlr_um_set_msg_info_ind(mmi_event_struct *para);

static void mmi_provbox_evt_hdlr_um_set_sort_info_ind(mmi_event_struct *para);

static void mmi_provbox_evt_hdlr_um_set_traverse_process_msg_deatil_ind(mmi_event_struct *evt);
#endif

/*****************************************************************************
 * Static variables Declaration
 *****************************************************************************/
static mmi_provbox_event_hdlr_struct g_provbox_event_hdlr[] = 
{
    {/* SRV_PROVBOX_EVT_TYPE_BOX_FULL_IND */ 
        mmi_provbox_event_notify_hdlr},
    {/* SRV_PROVBOX_EVT_TYPE_NEW_MSG_IND */
        mmi_provbox_event_new_msg_hdlr},
#ifdef __MMI_PROV_IN_UM__
    {/* SRV_PROVBOX_EVT_TYPE_SET_MSG_INFO_IND */
        mmi_provbox_evt_hdlr_um_set_msg_info_ind},
    {/* SRV_PROVBOX_EVT_TYPE_SET_SORT_INFO_IND */
        mmi_provbox_evt_hdlr_um_set_sort_info_ind},
    {/* SRV_PROVBOX_EVT_TYPE_SET_MSG_DETAIL_IND */
        mmi_provbox_evt_hdlr_um_set_traverse_process_msg_deatil_ind},
#endif /* __MMI_PROV_IN_UM__ */
    { NULL }
};

/*****************************************************************************
 * Local function
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_event_hdlr
 *
 * DESCRIPTION
 *  this function is to process all premitive message
 *
 * PARAMETERS
 *  mmi_event_struct*       [IN]
 *
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_provbox_event_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_event_struct *evt_ind = (srv_provbox_event_struct*)evt;
    mmi_provbox_event_hdlr_funcp event_hdlr_func_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_EVENT_HANDLE, evt_ind->evt_type);

    if (evt_ind->evt_type >= SRV_PROVBOX_EVT_TYPE_BOX_FULL_IND && evt_ind->evt_type <= SRV_PROVBOX_EVT_TYPE_SET_MSG_DETAIL_IND)
    {
        //(*g_provbox_event_hdlr[evt_ind->evt_type])(evt);
        event_hdlr_func_p = g_provbox_event_hdlr[evt_ind->evt_type].call_bacl_func;
        (* event_hdlr_func_p)(evt);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_event_notify_hdlr
 *
 * DESCRIPTION
 *  this function is to process notify event
 *
 * PARAMETERS
 *  mmi_event_struct*       [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_event_notify_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_evt_notify_struct *notify = (srv_provbox_evt_notify_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_EVENT_NOTIFY_HDLR, notify->type);
    
    mmi_provbox_notify_popup(notify->type);
    switch(notify->type)
    {
        case SRV_PROVBOX_NOTIFY_TYPE_INBOX_FULL:
            #ifdef __MMI_NCENTER_SUPPORT__
            mmi_provbox_ncenter_notify_inbox_full();
            #endif
            break;
            
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_event_new_msg_hdlr
 *
 * DESCRIPTION
 *  this function is to process new message event
 *
 * PARAMETERS
 *  mmi_event_struct*       [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_event_new_msg_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_evt_new_msg_ind_struct *new_msg_evt = (srv_provbox_evt_new_msg_ind_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_EVENT_NEW_MSG_HDLR);

    mmi_provbox_handle_new_msg_ind(new_msg_evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_msg_handle_cca_process_prov_msg_cnf
 *
 * DESCRIPTION
 *  this function is to process install message confirm
 *
 * PARAMETERS
 *  void*       [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_msg_handle_cca_process_prov_msg_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_process_prov_msg_cnf_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_cca_process_prov_msg_cnf_struct*) msg;
    
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_MSG_HDLR_CCA_PROCESS_PROV_MSG_CNF, data->trans_id);

    if (data->trans_id != MMI_PROVBOX_TRANS_ID_CCA_PROCESS_MSG)
    {
        return;
    }

    mmi_provbox_msg_install_done(data);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_send_cca_process_prov_msg_req
 *
 * DESCRIPTION
 *  this function is to process install message request
 *
 * PARAMETERS
 *  U32       [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_provbox_send_cca_process_prov_msg_req(U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_process_prov_msg_req_struct *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data = (srv_cca_process_prov_msg_req_struct*) OslConstructDataPtr(sizeof(srv_cca_process_prov_msg_req_struct));

    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_MSG_HDLR_CCA_PROCESS_PROV_MSG_CNF, msg_id);
    
    data->trans_id = MMI_PROVBOX_TRANS_ID_CCA_PROCESS_MSG;
    data->msg_id   = msg_id;

    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_CCA_PROCESS_PROV_MSG_REQ, (oslParaType*) data, 0);
}


#ifdef __MMI_PROV_IN_UM__
/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_msg_handle_um_entry_folder
 *
 * DESCRIPTION
 *  this function is to process um entry folder messsage
 *
 * PARAMETERS
 *  mmi_event_struct *       [IN]
 *
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_provbox_msg_handle_um_entry_folder(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_entry_folder_evt_struct* evt = (mmi_um_entry_folder_evt_struct*) para;
    mmi_provbox_context_struct *cntx = mmi_provbox_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_MSG_HDLR_UM_ENTRY_FOLDER, evt->msg_box);

    if (((SRV_UM_MSG_BOX_INBOX & evt->msg_box) || (SRV_UM_MSG_BOX_ARCHIVE & evt->msg_box)) && (evt->is_entry == KAL_TRUE))
    {
        mmi_provbox_nmgr_cancel();
		if (mmi_provbox_scrn_group_get_id() != GRP_ID_INVALID) // &&
			//MMI_PROVBOX_GET_BIT_VALUE(g_provbox_context.flags, MMI_PROVBOX_FLAG_BIT_IDX_INSTALL, MMI_PROVBOX_FLAG_BIT_INSTALL))
		{
			MMI_PROVBOX_SET_BIT_VALUE(cntx->flags, MMI_PROVBOX_FLAG_BIT_CLOSING_WIDGET_INST);
			mmi_provbox_scrn_group_close();
		}
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_evt_hdlr_um_set_msg_info_ind
 *
 * DESCRIPTION
 *  this function is to set provisioning message information for um request
 *
 * PARAMETERS
 *  mmi_event_struct *       [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_evt_hdlr_um_set_msg_info_ind(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_evt_msg_info_struct *msg_info_evt = (srv_provbox_evt_msg_info_struct*)para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_EVT_HDLR_UM_SET_MSG_INFO_IND);

    mmi_provbox_um_set_msg_info(msg_info_evt->um_msg_info, msg_info_evt->msg_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_evt_hdlr_um_set_sort_info_ind
 *
 * DESCRIPTION
 *  this function is to set provisioning message sort information for um request
 *
 * PARAMETERS
 *  mmi_event_struct *       [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_evt_hdlr_um_set_sort_info_ind(mmi_event_struct *para)
{
#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_evt_sort_info_struct* sort_info_evt = (srv_provbox_evt_sort_info_struct*)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_EVT_HDLR_UM_SET_SORT_INFO_IND);

    mmi_provbox_um_set_sort_info(
        sort_info_evt->list_data,
        sort_info_evt->msg_info,
        sort_info_evt->msg_size,
        sort_info_evt->list_idx_type);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provbox_evt_hdlr_um_set_traverse_process_msg_deatil_ind
 *
 * DESCRIPTION
 *  this function is to set traverse process message detail information
 *  for um request
 *
 * PARAMETERS
 *  mmi_event_struct *       [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_provbox_evt_hdlr_um_set_traverse_process_msg_deatil_ind(mmi_event_struct *evt)
{
#ifdef __MMI_UM_CONVERSATION_BOX__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_evt_msg_detail_struct *msg_detail_evt = (srv_provbox_evt_msg_detail_struct *)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_PROVBOXAPP_TRC_INFO, MMI_PROVBOXAPP_TRC_EVT_HDLR_UM_SET_TRAVERSE_PROCESS_MSG_DETAIL_IND);

    if (NULL == msg_detail_evt)
    {
        return;
    }

    msg_detail_evt->traverse_ret = mmi_provbox_um_traverse_process_msg_detail(
                                       msg_detail_evt->info,
                                       msg_detail_evt->msg_size,
                                       msg_detail_evt->um_user_data,
                                       msg_detail_evt->um_detail_field,
                                       msg_detail_evt->um_traverse_callback);
#endif /* __MMI_UM_CONVERSATION_BOX__ */
}

#endif /* __MMI_PROV_IN_UM__ */

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */
