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
*  CallLogMain.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  
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
****************************************************************************/

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
#include "IdleNotificationManagerGprot.h"

#ifdef __DM_LAWMO_SUPPORT__
#include "DmUiGprot.h"
#endif 

#include "MMIDataType.h"

#if defined(__MMI_TELEPHONY_SUPPORT__) || defined(__MMI_BT_PBAP_CLIENT__)

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "string.h"

#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "NotificationGprot.h"
#include "mmi_frm_mem_gprot.h"
#include "wgui_categories_util.h"
#include "SimCtrlSrvGprot.h"

#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
#include "CallLogConfig.h"
#include "CallLogGprot.h"
#include "CallLogProt.h"
#include "CallLogLayout.h"
#include "CallLogViewer.h"
#include "CallLogAdpProt.h"
#include "mmi_rp_app_calllog_def.h"

#include "DmSrvGprot.h"

#include "NativeAppFactorySrvGprot.h"
#include "mmi_rp_app_bluetooth_def.h"
#ifdef __MMI_BT_NOTI_SRV__
#include "BTNotiSrvGprot.h"
#endif
#ifdef __MMI_NCENTER_SUPPORT__
#include "Vsrv_ncenter.h"
#endif

#ifdef __MMI_BT_PBAP_CLIENT__
#include "mmi_rp_app_ucmbt_def.h"
#endif
#include "custom_btcm_config.h"
#include "mmi_rp_srv_ucm_def.h"
#include "ucmbtsrvgprot.h"
#include "UcmSrvGprot.h"
/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
static mmi_clog_cntx_struct g_mmi_clog_cntx;
NMGR_HANDLE nmgr_handle = NULL;
#if defined( __MMI_BT_PBAP_CLIENT__) && defined (__MMI_BT_NOTI_SRV__)
#if SRV_PBAPC_LINK_NUM >= 2
NMGR_HANDLE bt_nmgr_handle[SRV_PBAPC_LINK_NUM];
#else
NMGR_HANDLE bt_nmgr_handle;
#endif
#endif

#if defined( __MMI_BT_PBAP_CLIENT__)
extern mmi_clog_rsp_missed_call g_is_missed_call;/*for build error.*/
#endif

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/

/*---------------------- Init & Context --------------------------------------*/

static S32 mmi_clog_is_cntx_ready(mmi_clog_cntx_struct *cntx);
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
static MMI_RET mmi_clog_srv_init(mmi_event_struct *evt);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
static void mmi_clog_others_init(void);
static S32 mmi_clog_has_new_event(void);

/*---------------------- Service Event ---------------------------------------*/
MMI_RET mmi_clog_srv_ready_evt_hdlr(mmi_event_struct *evt);
#ifdef __MMI_BT_PBAP_CLIENT__
MMI_RET mmi_clog_bt_dialer_evt_hdlr(mmi_event_struct *evt);
#ifdef __MMI_BT_NOTI_SRV__
MMI_RET mmi_clog_bt_dialer_missed_call_hdlr(mmi_event_struct *evt);
MMI_RET mmi_clog_bt_dialer_bt_disconn_hdlr(mmi_event_struct *evt);
#endif
#endif

/*---------------------- DM LAWMO --------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
//static void mmi_clog_lawmo_register(void);
mmi_ret mmi_clog_lawmo_wipe_data_hdlr(mmi_event_struct *evt);
static void mmi_clog_lawmo_wipe_all_logs(srv_dm_lawmo_wipe_report_cb_func_type cb);
static S32 mmi_clog_cb_lawmo_wipe_result(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            void *req_data,
            void *cnf_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret);
#endif /* __DM_LAWMO_SUPPORT__ */ 

/*---------------------- Special Feature -------------------------------------*/

#ifdef __MMI_CLOG_REBOOT_NO_UNREAD_SUPPORT__
static void mmi_clog_clear_all_read_status(void);
static S32 mmi_clog_clear_all_read_status_result(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            void *req_data,
            void *cnf_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret);
#endif /* __MMI_CLOG_REBOOT_NO_UNREAD_SUPPORT__ */ 

/*---------------------- NMGR ------------------------------------------------*/
#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
static void mmi_clog_nmgr_select(void *user_data);
#endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/
/*---------------------- Service Event ---------------------------------------*/
static MMI_RET mmi_clog_srv_evt_ready_hdlr(mmi_event_struct *evt);
static MMI_RET mmi_clog_srv_evt_log_action_hdlr(mmi_event_struct *evt);
static void mmi_clog_check_new_event(mmi_event_struct *evt);
static void mmi_clog_notify_others(void);
static S32 mmi_clog_check_notify(mmi_event_struct *evt);

static void mmi_clog_nmgr2_enter(void);
#ifdef __MMI_NCENTER_SUPPORT__
static void mmi_clog_enter_ncenter(mmi_event_struct *evt);
#endif /*__MMI_NCENTER_SUPPORT__*/
/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/
#define SEG_ID_MMI_CLOG_INIT


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_clog_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CLOG_IT_TRACE((MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_INIT, 0));

    mmi_clog_check_cfg_data();
#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
    mmi_clog_srv_init(evt);
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */
    mmi_clog_others_init();

    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_INIT, 1);
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_get_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
mmi_clog_cntx_struct *mmi_clog_get_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_mmi_clog_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_is_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_clog_is_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_clog_is_cntx_ready(mmi_clog_get_cntx());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_is_cntx_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_is_cntx_ready(mmi_clog_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx)
        return MMI_FALSE;

    return (MMI_CLOG_CHECK_BIT(cntx->flags, MMI_CLOG_CNTX_FLAG_IS_READY));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_receive_new_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_receive_new_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = mmi_clog_get_cntx();
    if (!mmi_clog_is_cntx_ready(cntx))
        return;

    MMI_CLOG_SET_BIT(cntx->flags, MMI_CLOG_CNTX_FLAG_HAS_NEW_EVENT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_has_new_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_clog_has_new_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = mmi_clog_get_cntx();
    if (!mmi_clog_is_cntx_ready(cntx))
        return 0;

    return MMI_CLOG_CHECK_BIT(cntx->flags, MMI_CLOG_CNTX_FLAG_HAS_NEW_EVENT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_clear_all_new_events
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_clear_all_new_events(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = mmi_clog_get_cntx();
    if (!mmi_clog_is_cntx_ready(cntx))
        return;

    MMI_CLOG_CLEAR_BIT(cntx->flags, MMI_CLOG_CNTX_FLAG_HAS_NEW_EVENT);

    MMI_CLOG_IT_TRACE((
        MMI_CLOG_TRC_INFO,
        TRC_MMI_CLOG_CLEAR_ALL_NEW_EVENTS,
        cntx->flags,
        MMI_CLOG_CHECK_BIT(cntx->flags, MMI_CLOG_CNTX_FLAG_HAS_NEW_EVENT)));
}


#ifndef __MMI_CLOG_SLIM_FOR_MT6261__
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_srv_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_clog_srv_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TELEPHONY_SUPPORT__
    srv_clog_init(evt);

    MMI_CLOG_IT_TRACE((MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_SRV_INIT_SET_SRV_STYLE, SRV_CLOG_STYLE_TYPE_NUM, MMI_CLOG_STYLE_NUM));
    srv_clog_set_def_style(SRV_CLOG_STYLE_TYPE_NUM, MMI_CLOG_STYLE_NUM, NULL);

    MMI_CLOG_IT_TRACE((MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_SRV_INIT_SET_SRV_STYLE, SRV_CLOG_STYLE_TYPE_MERGE, MMI_CLOG_STYLE_MERGE));
    srv_clog_set_def_style(SRV_CLOG_STYLE_TYPE_MERGE, MMI_CLOG_STYLE_MERGE, NULL);

    MMI_CLOG_IT_TRACE((MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_SRV_INIT_SET_SRV_STYLE, SRV_CLOG_STYLE_TYPE_MERGE, MMI_CLOG_STYLE_MERGE));
    srv_clog_set_def_style(SRV_CLOG_STYLE_TYPE_PHB_SYNC, MMI_CLOG_STYLE_PHB_SYNC, NULL);


    MMI_CLOG_IT_TRACE((MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_SRV_INIT_SET_SRV_STYLE, SRV_CLOG_STYLE_TYPE_SIM_SYNC, MMI_CLOG_STYLE_SIM_SYNC));

    srv_clog_set_def_style(SRV_CLOG_STYLE_TYPE_SIM_SYNC, MMI_CLOG_STYLE_SIM_SYNC, NULL);

    srv_clog_start();
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    return MMI_RET_OK;
}
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_others_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_others_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//#ifdef __DM_LAWMO_SUPPORT__
//    mmi_clog_lawmo_register();
//#endif 
}

#ifdef __DM_LAWMO_SUPPORT__


/* New, for DM lawmo*/
srv_dm_lawmo_wipe_report_cb_func_type g_dm_lawmo_hdlr = NULL;


mmi_ret mmi_clog_lawmo_wipe_data_hdlr(mmi_event_struct *evt)
{
	mmi_clog_cntx_struct *cntx = mmi_clog_get_cntx();
	
	srv_dm_lawmo_wipe_ind_evt_struct *lawmo_wipe_ind = 
		(srv_dm_lawmo_wipe_ind_evt_struct *)evt;

	if (lawmo_wipe_ind->cmd != SRV_DM_LAWMO_WIPE_CMD_APP_WIPE)
	{
			return MMI_RET_OK;
	}
	if (!mmi_clog_is_cntx_ready(cntx))
    {
    	g_dm_lawmo_hdlr = lawmo_wipe_ind->cb;
        MMI_CLOG_SET_BIT(cntx->flags, MMI_CLOG_CNTX_FLAG_NEED_WIPE_DATA);
        return MMI_RET_OK;
    }
    mmi_clog_lawmo_wipe_all_logs(lawmo_wipe_ind->cb);
	return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_clog_lawmo_wipe_all_logs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_lawmo_wipe_all_logs(srv_dm_lawmo_wipe_report_cb_func_type cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_clog_del_all_logs_req_struct req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_CLOG_ASSERT(cb != NULL);
	
    srv_clog_init_para(SRV_CLOG_PARA_DEL_ALL_LOGS_REQ, &req_data);
    ret = srv_clog_delete_all_logs(0, 0, &req_data, mmi_clog_cb_lawmo_wipe_result);
    if (ret <= SRV_CLOG_RET_OK)
    {
        MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_LAWMO_WIPE_ALL_LOGS, ret);

       // mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_CALL_LOG, MMI_DMUI_CMD_LAWMO_WIPE, MMI_DMUI_RESULT_FAILURE);
				(*cb)(MMI_FALSE,"Calllog");
	}
	else
	{
				(*cb)(MMI_TRUE,"Calllog");
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_cb_lawmo_wipe_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  req_data        [IN]         
 *  cnf_data        [IN]         
 *  more            [IN]        
 *  ret             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_cb_lawmo_wipe_result(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            void *req_data,
            void *cnf_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_dmui_result_enum dm_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ret == SRV_CLOG_RET_OK)
        dm_result = MMI_DMUI_RESULT_SUCCESS;
    else
        dm_result = MMI_DMUI_RESULT_FAILURE;

    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_CB_LAWMO_WIPE_RESULT, handle, pid, ret);

    mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_CALL_LOG, MMI_DMUI_CMD_LAWMO_WIPE, dm_result);
    return SRV_CLOG_RET_OK;
}

#endif /* __DM_LAWMO_SUPPORT__ */ 

#ifdef __MMI_CLOG_REBOOT_NO_UNREAD_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_clear_all_read_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_clear_all_read_status(void)
{
#ifdef __MMI_TELEPHONY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 unread_num;
    srv_clog_update_all_logs_req_struct req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    unread_num = srv_clog_get_unread_missed_call_num();
    if (unread_num == 0)
        return;

    srv_clog_init_para(SRV_CLOG_PARA_UPDATE_ALL_LOGS_REQ, &req_data);
    req_data.cate = SRV_CLOG_CATE_CALL;
    req_data.log_type = SRV_CLOG_CLT_MISSED;
    req_data.req_fields = SRV_CLOG_LOG_FIELD_UNREAD_NUM;
    req_data.read = MMI_TRUE;

    ret = srv_clog_update_all_logs(0, 0, &req_data, mmi_clog_clear_all_read_status_result);
    if (ret <= SRV_CLOG_RET_OK)
    {
        MMI_CLOG_IT_TRACE((MMI_CLOG_TRC_ERROR, TRC_MMI_CLOG_CLEAR_ALL_READ_STATUS, ret));
        MMI_CLOG_IT_ASSERT(!"Update fail");
        return;
    }
#endif /* __MMI_TELEPHONY_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_clear_all_read_status_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  pid             [IN]        
 *  req_data        [IN]         
 *  cnf_data        [IN]         
 *  more            [IN]        
 *  ret             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_clog_clear_all_read_status_result(
            SRV_CLOG_HANDLE handle,
            S32 pid,
            void *req_data,
            void *cnf_data,
            MMI_BOOL more,
            srv_clog_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_update_all_logs_cnf_struct *cnf = (srv_clog_update_all_logs_cnf_struct*) cnf_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CLOG_TRC_WARNING, TRC_MMI_CLOG_CLEAR_ALL_READ_STATUS_RESULT, ret, cnf->total_num, cnf->num_updated);

    mmi_clog_update_status_icon();
    return SRV_CLOG_RET_OK;
}
#endif /* __MMI_CLOG_REBOOT_NO_UNREAD_SUPPORT__ */ 


#ifdef __MMI_BT_PBAP_CLIENT__
#ifdef __MMI_HF_SUPPORT__
MMI_RET mmi_clog_bt_dialer_evt_hdlr(mmi_event_struct *evt)
{
    S32 count;
    srv_ucm_bt_release_call_ind_struct *para = NULL;

    srv_ucm_bt_ind_evt_struct *event = (srv_ucm_bt_ind_evt_struct *)evt;

    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_EVT_HDLR, event->evt_id, event->ind_type, 0);
    if (event->evt_id == EVT_ID_SRV_UCM_BT_INDICATION && event->ind_type == SRV_UCM_BT_RELEASE_IND)
    {
        para = (srv_ucm_bt_release_call_ind_struct *)event->ptr;
        count = srv_ucm_bt_query_call_count_ext(para->srv_hd, SRV_UCM_BT_CALL_STATE_ALL, NULL);
        MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_BT_DIALER_EVT_HDLR, event->evt_id, event->ind_type, 0);

        if (count == 0)
        {
            mmi_clog_update_log_by_end_call(para);
        }
    } 
    return MMI_RET_OK;
}
#endif

#endif
#define SEG_ID_MMI_CLOG_SRV_EVENT


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_srv_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_RET mmi_clog_srv_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CLOG_IT_TRACE((
        MMI_CLOG_TRC_INFO,
        TRC_MMI_CLOG_SRV_EVET_HDLR,
        evt->evt_id,
        EVT_ID_SRV_CLOG_READY,
        EVT_ID_SRV_CLOG_ADD_LOG,
        EVT_ID_SRV_CLOG_UPDATE_LOG,
        EVT_ID_SRV_CLOG_UPDATE_ALL,
        EVT_ID_SRV_CLOG_DEL_LOG,
        EVT_ID_SRV_CLOG_DEL_ALL));

    if (evt->evt_id == EVT_ID_SRV_CLOG_READY)
        return mmi_clog_srv_evt_ready_hdlr(evt);

    return mmi_clog_srv_evt_log_action_hdlr(evt);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_srv_evt_ready_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static MMI_RET mmi_clog_srv_evt_ready_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clog_cntx_struct *cntx = mmi_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CLOG_SET_BIT(cntx->flags, MMI_CLOG_CNTX_FLAG_IS_READY);

    MMI_CLOG_IT_TRACE((MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_SRV_READY_EVT_HDLR_RECVED));

#ifdef __DM_LAWMO_SUPPORT__
    if (MMI_CLOG_CHECK_BIT(cntx->flags, MMI_CLOG_CNTX_FLAG_NEED_WIPE_DATA))
    {
        MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_SRV_READY_EVT_HDLR_LAWMO);
        mmi_clog_lawmo_wipe_all_logs(g_dm_lawmo_hdlr);
    }
#endif /* __DM_LAWMO_SUPPORT__ */ 

#ifdef __MMI_CLOG_REBOOT_NO_UNREAD_SUPPORT__
    mmi_clog_clear_all_read_status();
    MMI_CLOG_IT_TRACE((MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_SRV_READY_EVT_HDLR_CLEAR));

#else /* __MMI_CLOG_REBOOT_NO_UNREAD_SUPPORT__ */ 

//    mmi_clog_update_status_icon();
#ifdef __MMI_TELEPHONY_SUPPORT__
    if (0 != srv_clog_get_unread_missed_call_num())
    {
        mmi_frm_nmgr_alert_struct alert_info;
         
         /* For NCenter2.0 */
    #ifdef __MMI_NCENTER_SUPPORT__
        mmi_clog_enter_ncenter(evt); /* Enter ncenter */
    #endif /*__MMI_NCENTER_SUPPORT__*/

        memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));	 
        alert_info.app_id = APP_CALLLOG;
        alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK;
        alert_info.behavior_mask = FORCE_ICON_ONLY;
        alert_info.alert_option = MMI_FRM_NMGR_DISABLE_TONE| MMI_FRM_NMGR_DISABLE_VIB;
        alert_info.status_bar_icon_para.icon_id = STATUS_ICON_MISSED_CALL;
        nmgr_handle = mmi_frm_nmgr_alert(&alert_info);
        //mmi_clog_nmgr2_enter();
    }
#endif /* __MMI_TELEPHONY_SUPPORT__ */
#endif /* __MMI_CLOG_REBOOT_NO_UNREAD_SUPPORT__ */ 
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_srv_evt_log_action_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static MMI_RET mmi_clog_srv_evt_log_action_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_CLOG_ASSERT(mmi_clog_is_ready());

#ifdef __MMI_CLOG_EVENT_REFRESH_SUPPORT__
    mmi_clog_mm_srv_evt_hdlr(evt);
    mmi_clog_lt_srv_evt_hdlr(evt);
#endif /* __MMI_CLOG_EVENT_REFRESH_SUPPORT__ */
    mmi_clog_vr_srv_evt_hdlr(evt);

    mmi_clog_check_new_event(evt);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_check_new_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_check_new_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // mmi_clog_update_status_icon();
    mmi_clog_notify_others();
    ret = mmi_clog_check_notify(evt);
    if (ret)
        mmi_clog_nmgr2_enter();
}

#ifdef __MMI_NCENTER_SUPPORT__

vsrv_notification_handle g_ncenter_hdl = NULL;


/* For NCenter2.0 */

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_ncenter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  NULL 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_ncenter_callback_handler(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 missed_call_num = 0;
	WCHAR ctext[50];
	srv_clog_get_last_log_req_struct req_data;
	srv_clog_get_last_log_cnf_struct cnf_data;
	srv_clog_call_log_struct *calllog;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     if (intent.type == VSRV_NINTENT_TYPE_LAUNCH)
     {
		// do launch APP here
		mmi_clog_mclt_launch();
     }
	 else if (intent.type == VSRV_NINTENT_TYPE_LANGUAGE_CHANGED)
	 {
		 // need to resend the notification with the changed language.
		 if(nhandle != NULL)
		 {
			vsrv_ngroup_handle clog_group = NULL;
			clog_group = vsrv_ncenter_query_ngroup(APP_CALLLOG);
			if(clog_group != NULL)
			{
				missed_call_num= srv_clog_get_unread_missed_call_num();
				mmi_wcscpy(ctext, (WCHAR *)GetString(STR_ID_CLOG_NCENTER_CALLS));    
				vsrv_ncenter_set_ngroup_title_str(clog_group, ctext);
					                    
				mmi_wcscpy(ctext, (WCHAR *)GetString(STR_ID_CLOG_NCENTER_MISSED_CALL));
				vsrv_ncenter_set_notification_maintext_str(nhandle, ctext);

				if (missed_call_num != 1)
				{
					kal_wsprintf((WCHAR *)ctext ,
					   "%d %w",missed_call_num,GetString(STR_ID_CLOG_NCENTER_MISSED_CALLS));
				}
				else if (missed_call_num == 1)
				{
					srv_clog_init_para(SRV_CLOG_PARA_GET_LAST_LOG_REQ, &req_data);
					srv_clog_init_para(SRV_CLOG_PARA_GET_LAST_LOG_CNF, &cnf_data);
					req_data.log_type = SRV_CLOG_CLT_MISSED;
				    
					srv_clog_get_last_log(0,
							(const srv_clog_get_last_log_req_struct *)&req_data,
							&cnf_data);
					calllog = &(cnf_data.log.data.call_log);				   

					 kal_wsprintf((WCHAR *)ctext ,
					   "%w",calllog->cid);
				}
				vsrv_ncenter_set_notification_subtext_str(nhandle, ctext);
				vsrv_ncenter_notify_notification(nhandle); 
			}
		 }
	 }
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_enter_ncenter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  NULL 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_enter_ncenter(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 missed_call_num = 0;
	//srv_clog_log_struct log;
	//srv_clog_evt_add_log_struct *add_evt;
	vsrv_notification_handle nhandle;
	WCHAR ctext[50];

	srv_clog_get_last_log_req_struct req_data;
    srv_clog_get_last_log_cnf_struct cnf_data;
	srv_clog_call_log_struct *calllog;
	applib_time_struct timestamp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    vsrv_ngroup_handle ghandle = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, APP_CALLLOG);
	 g_ncenter_hdl = nhandle = 
	                   vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT, ghandle, 0);
	                        
	//GetDateTime(&timestamp);
	DTGetRTCTime(&timestamp);
	vsrv_ncenter_set_notification_timestamp(nhandle,&timestamp);

	missed_call_num= srv_clog_get_unread_missed_call_num();
	//add_evt = (srv_clog_evt_add_log_struct*) evt;
	
	mmi_wcscpy(ctext, (WCHAR *)GetString(STR_ID_CLOG_NCENTER_CALLS));    
	vsrv_ncenter_set_ngroup_title_str(ghandle, ctext);
	                        
	mmi_wcscpy(ctext, (WCHAR *)GetString(STR_ID_CLOG_NCENTER_MISSED_CALL));
	vsrv_ncenter_set_notification_maintext_str(nhandle, ctext);
	                       
	//mmi_wcscpy(ctext, (WCHAR *)L"%d Missed Call");
	//vsrv_ncenter_set_notification_subtext(nhandle, ctext);

	if (missed_call_num != 1)
	    kal_wsprintf((WCHAR *)ctext ,
           "%d %w",missed_call_num,GetString(STR_ID_CLOG_NCENTER_MISSED_CALLS));
	else if (missed_call_num == 1)
	{

	/*
	    srv_clog_get_log_by_id(add_evt->handle,add_evt->new_idf.log_id,
	             0,&log);
	    kal_wsprintf((WCHAR *)ctext ,
           "%w",log.data.call_log.cid);
    */
        srv_clog_init_para(SRV_CLOG_PARA_GET_LAST_LOG_REQ, &req_data);
        srv_clog_init_para(SRV_CLOG_PARA_GET_LAST_LOG_CNF, &cnf_data);
        req_data.log_type = SRV_CLOG_CLT_MISSED;
        
        srv_clog_get_last_log(0,
                (const srv_clog_get_last_log_req_struct *)&req_data,
                &cnf_data);
        calllog = &(cnf_data.log.data.call_log);
	   

		 kal_wsprintf((WCHAR *)ctext ,
           "%w",calllog->cid);
	}
		

	//mmi_wsprintf_ex(ctext,(SRV_APPMGR_BADGE_MAX_LEN+1)*sizeof(WCHAR),
		//		(WCHAR *)L"%d Missed Call",missed_call_num);
	
	vsrv_ncenter_set_notification_subtext_str(nhandle, ctext);

	vsrv_ncenter_set_notification_intent_callback(nhandle, mmi_clog_ncenter_callback_handler, NULL, 0);
	                        
	vsrv_ncenter_notify_notification(nhandle); 
}

#endif /* __MMI_NCENTER_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_check_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_clog_check_notify(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 need_notify = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id != EVT_ID_SRV_CLOG_ADD_LOG && !mmi_clog_has_new_event())
        return MMI_FALSE;

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_CLOG_ADD_LOG:
        {
            srv_clog_evt_add_log_struct *add_evt;

            add_evt = (srv_clog_evt_add_log_struct*) evt;

            if (add_evt->new_idf.cate == SRV_CLOG_CATE_CALL && add_evt->new_idf.log_type == SRV_CLOG_CLT_MISSED)
            {
                MMI_CLOG_IT_TRACE((
                    MMI_CLOG_TRC_INFO,
                    TRC_MMI_CLOG_CHECK_NEW_EVENT,
                    evt->evt_id,
                    add_evt->old_idf.cate,
                    add_evt->old_idf.sim_id,
                    add_evt->old_idf.log_type,
                    add_evt->old_idf.sub_type,
                    add_evt->new_idf.cate,
                    add_evt->new_idf.sim_id,
                    add_evt->new_idf.log_type,
                    add_evt->new_idf.sub_type));

                mmi_clog_receive_new_event();
            }

            if (add_evt->new_idf.cate == SRV_CLOG_CATE_CALL && add_evt->new_idf.log_type == SRV_CLOG_CLT_MISSED ||
                add_evt->add_ret != SRV_CLOG_ADD_LOG_RET_PURE_ADD && add_evt->new_idf.cate == SRV_CLOG_CATE_CALL &&
                add_evt->old_idf.log_type == SRV_CLOG_CLT_MISSED)
            {
                need_notify = MMI_TRUE;
            }

			/*Update badge*/
	#ifdef __MMI_APP_MANAGER_SUPPORT__
			if (add_evt->new_idf.log_type == SRV_CLOG_CLT_MISSED)
			{
				srv_appmgr_update_app_info("calllog",EVT_ID_SRV_APPMGR_UPDATE_BADGE);
			}
	#endif /*__MMI_APP_MANAGER_SUPPORT__*/
	
		/* For NCenter2.0 */
	#ifdef __MMI_NCENTER_SUPPORT__
		if (add_evt->new_idf.log_type == SRV_CLOG_CLT_MISSED)
				mmi_clog_enter_ncenter(evt); /* Enter ncenter */
	#endif /*__MMI_NCENTER_SUPPORT__*/
        }
            break;

        case EVT_ID_SRV_CLOG_UPDATE_LOG:
        {
            srv_clog_evt_update_log_struct *upd_evt;

            upd_evt = (srv_clog_evt_update_log_struct*) evt;
            if (MMI_CLOG_CHECK_BIT(upd_evt->fields, SRV_CLOG_LOG_FIELD_UNREAD_NUM) &&
                upd_evt->log.cate == SRV_CLOG_CATE_CALL && upd_evt->log.data.call_log.log_type == SRV_CLOG_CLT_MISSED)
            {
                need_notify = MMI_TRUE;
            }
        }
            break;

        case EVT_ID_SRV_CLOG_UPDATE_ALL:
        {
            srv_clog_evt_update_all_struct *upd_all_evt;

            upd_all_evt = (srv_clog_evt_update_all_struct*) evt;
            if (MMI_CLOG_CHECK_BIT(upd_all_evt->fields, SRV_CLOG_LOG_FIELD_UNREAD_NUM) &&
                MMI_CLOG_CHECK_BIT(upd_all_evt->idt.cate, SRV_CLOG_CATE_CALL) &&
                MMI_CLOG_CHECK_BIT(upd_all_evt->idt.log_type, SRV_CLOG_CLT_MISSED))
            {
                need_notify = MMI_TRUE;
            }
        }
            break;

        case EVT_ID_SRV_CLOG_DEL_LOG:
        {
            srv_clog_evt_del_log_struct *del_evt;

            del_evt = (srv_clog_evt_del_log_struct*) evt;
            if (del_evt->idf.cate == SRV_CLOG_CATE_CALL && del_evt->idf.log_type == SRV_CLOG_CLT_MISSED)
            {
                need_notify = MMI_TRUE;
            }
        }
            break;

        case EVT_ID_SRV_CLOG_DEL_ALL:
        {
            srv_clog_evt_del_all_struct *del_all_evt;

            del_all_evt = (srv_clog_evt_del_all_struct*) evt;

            if (MMI_CLOG_CHECK_BIT(del_all_evt->idt.cate, SRV_CLOG_CATE_CALL) &&
                MMI_CLOG_CHECK_BIT(del_all_evt->idt.log_type, SRV_CLOG_CLT_MISSED))
            {
                need_notify = MMI_TRUE;
            }
        }
            break;

        default:
            break;
    }

    return need_notify;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_notify_others
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_notify_others(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    /*  Sidebar */
    mmi_clog_op11_hs32_sb_update();

    /* Shortcut */
    mmi_clog_op11_hs32_shct_update();

#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */ 

}

#define SEG_ID_MMI_CLOG_NMGR

/* mmi_chist_new_event_query */

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_nmgr_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_clog_nmgr_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    mmi_clog_cntx_struct *cntx = mmi_clog_get_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_clog_is_cntx_ready(cntx))
        return MMI_FALSE;

    if (!MMI_CLOG_CHECK_BIT(cntx->flags, MMI_CLOG_CNTX_FLAG_HAS_NEW_EVENT))
        return MMI_FALSE;
#ifdef __MMI_TELEPHONY_SUPPORT__
    ret = srv_clog_get_unread_missed_call_num();
    if (ret == 0)
        return MMI_FALSE;
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_nmgr_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_nmgr_enter(void)
{
#ifndef __MMI_NCENTER_SUPPORT__	
   mmi_clog_nmgr2_enter();
#endif /*__MMI_NCENTER_SUPPORT__*/
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clog_nmgr_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [IN] 
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
#if !defined( __MMI_NCENTER_SUPPORT__)	
static mmi_ret mmi_clog_nmgr_func(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH ||
        evt->evt_id == EVT_ID_NMGR_POPUP_APP_LAUNCH)
    {
    #ifdef __MMI_BT_PBAP_CLIENT__ 
         mmi_clog_view_from_idle_by_type(MMI_TRUE);
    #endif
         mmi_clog_mclt_launch();
    }
    mmi_clog_clear_all_new_events();
    return MMI_RET_OK;
}
#endif /*!defined( __MMI_NCENTER_SUPPORT__)*/


#ifdef __MMI_BT_PBAP_CLIENT__ 
#ifdef __MMI_BT_NOTI_SRV__
static mmi_ret mmi_clog_bt_nmgr_func(mmi_event_struct *evt)
{
    S32 index;
    if (evt->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH ||
    evt->evt_id == EVT_ID_NMGR_POPUP_APP_LAUNCH)
    {
    #if SRV_PBAPC_LINK_NUM >= 2
        mmi_clog_rsp_missed_call *data= (mmi_clog_rsp_missed_call *)evt->user_data;

        index = data->bt_index;
        kal_prompt_trace(MOD_MMI, "[TEST]mmi_clog_bt_nmgr_func: index = %d,lap =%0x, uap  =%0x", data->bt_index,g_is_missed_call.missed_bt_addr[index].lap,g_is_missed_call.missed_bt_addr[index].uap);
        srv_bt_noti_update_remote_missed_call(&g_is_missed_call.missed_bt_addr[index]);
    #else
        srv_bt_noti_update_remote_missed_call(&g_is_missed_call.missed_bt_addr);
    #endif
        mmi_clog_view_from_idle_by_type(MMI_FALSE);
        mmi_clog_mclt_launch();
    }
    return MMI_RET_OK;
}
#endif
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_nmgr2_enter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clog_nmgr2_enter(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
    mmi_frm_nmgr_alert_struct alert_info;
#if !defined(__MMI_NCENTER_SUPPORT__)
	WCHAR *buf;
	S32 total_num;	
    MMI_STR_ID str_id = STR_ID_CLOG_SINGLE_MISSED_CALL;
#endif /*!defined(__MMI_NCENTER_SUPPORT__)*/    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_NCENTER_SUPPORT__)

    if (!mmi_clog_is_ready())
    {
        return;
    }
#ifdef __MMI_TELEPHONY_SUPPORT__
    total_num = srv_clog_get_unread_missed_call_num();
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    if(total_num == 0)
        return;
    else if (total_num > 1)
        str_id = STR_ID_CLOG_MULTI_MISSED_CALLS;
    
    buf = OslMalloc(MMI_CLOG_TMP_BUF_SIZE);
    kal_wsprintf(buf, "%d %w", total_num, get_string(str_id));
    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));
	
	alert_info.app_id = APP_CALLLOG;
	alert_info.scen_id = MMI_SCENARIO_ID_MISSED_CALL;
	alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK|MMI_FRM_NMGR_UI_POPUP_MASK;
	alert_info.behavior_mask = FORCE_POPUP|FORCE_ICON_ONLY;
	alert_info.alert_option = MMI_FRM_NMGR_DISABLE_TONE| MMI_FRM_NMGR_DISABLE_VIB;
	alert_info.status_bar_icon_para.icon_id = STATUS_ICON_MISSED_CALL;
	
	alert_info.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
	alert_info.popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_VIEW);
    alert_info.popup_para.popup_button_str_id = STR_GLOBAL_VIEW;
	alert_info.popup_para.popup_string = buf;
	alert_info.app_proc_para.scrn_group_proc = mmi_clog_nmgr_func;
	alert_info.app_proc_para.user_data = NULL;
    alert_info.app_proc_para.data_size = 0;
	nmgr_handle = mmi_frm_nmgr_alert(&alert_info);
	OslMfree(buf);
#else /*!defined(__MMI_NCENTER_SUPPORT__)*/

    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));	 
	alert_info.app_id = APP_CALLLOG;
	alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK;
	alert_info.behavior_mask = FORCE_ICON_ONLY;
	alert_info.alert_option = MMI_FRM_NMGR_DISABLE_TONE| MMI_FRM_NMGR_DISABLE_VIB;
	alert_info.status_bar_icon_para.icon_id = STATUS_ICON_MISSED_CALL; 	 
	nmgr_handle = mmi_frm_nmgr_alert(&alert_info);
	mmi_clog_clear_all_new_events();
#endif /*!defined(__MMI_NCENTER_SUPPORT__)*/
}


#ifdef __MMI_BT_PBAP_CLIENT__ 
#ifdef __MMI_BT_NOTI_SRV__
mmi_ret mmi_clog_bt_dialer_missed_call_hdlr(mmi_event_struct *evt)
{

    mmi_frm_nmgr_alert_struct alert_info;
    WCHAR *buf;
    S32 total_num;
    S32 index;
    srv_bt_noti_missed_call_evt_struct *bt_noti = (srv_bt_noti_missed_call_evt_struct*)evt;
    MMI_STR_ID str_id = STR_ID_CLOG_SINGLE_MISSED_CALL;
#if SRV_PBAPC_LINK_NUM >= 2
    index = srv_pbapc_get_btd_index(&bt_noti->bt_addr, SRV_PBAPC_FLAG_CONNECTED);
    if (index < 0)
    {
        index = 0;
    }
    kal_prompt_trace(MOD_MMI, "mmi_clog_bt_dialer_missed_call_hdlr: lap =%x,udp =%x", bt_noti->bt_addr.lap, bt_noti->bt_addr.uap);
    g_is_missed_call.missed_bt_addr[index] = bt_noti->bt_addr;
    kal_prompt_trace(MOD_MMI, "[TEST]mmi_clog_bt_dialer_missed_call_hdlr: index = %d, lap =%x,udp =%x", index, g_is_missed_call.missed_bt_addr[index].lap, g_is_missed_call.missed_bt_addr[index].uap);
    g_is_missed_call.bt_index = index;
    total_num = bt_noti->missed_call_count;

    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_PBAPC_BT_MISSED_CALL, total_num, (U32)bt_nmgr_handle[index]);
#else
    g_is_missed_call.missed_bt_addr = bt_noti->bt_addr;

    total_num = bt_noti->missed_call_count;

    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_PBAPC_BT_MISSED_CALL, total_num, (U32)bt_nmgr_handle);

#endif
    if(total_num == 0)
    {
    #if SRV_PBAPC_LINK_NUM >= 2
        mmi_frm_nmgr_alert_cancel(bt_nmgr_handle[index]);
    #else
        mmi_frm_nmgr_alert_cancel(bt_nmgr_handle);
    #endif
        return;
    }
    else if (total_num > 1)
    str_id = STR_ID_CLOG_MULTI_MISSED_CALLS;

    buf = OslMalloc(MMI_CLOG_TMP_BUF_SIZE);
    kal_wsprintf(buf, "%d %w", total_num, get_string(str_id));
    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));

    alert_info.app_id = APP_CALLLOG;
    alert_info.scen_id = MMI_SCENARIO_ID_MISSED_CALL;
    alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK|MMI_FRM_NMGR_UI_POPUP_MASK;
    alert_info.behavior_mask = FORCE_POPUP|FORCE_ICON_ONLY;
    alert_info.alert_option = MMI_FRM_NMGR_DISABLE_TONE| MMI_FRM_NMGR_DISABLE_VIB;
    alert_info.status_bar_icon_para.icon_id = STATUS_ICON_MISSED_CALL;
    if(index == 0)
    {
        alert_info.event_type = MMI_EVENT_BT_MISSED_CALL;

    }
    else if (index == 1)
    {
        alert_info.event_type = MMI_EVENT_BT2_MISSED_CALL;

    }

    alert_info.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
    alert_info.popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_VIEW);
    alert_info.popup_para.popup_button_str_id = STR_GLOBAL_VIEW;
    alert_info.popup_para.popup_string = buf;
    alert_info.app_proc_para.scrn_group_proc = mmi_clog_bt_nmgr_func;
#if SRV_PBAPC_LINK_NUM >= 2
    alert_info.app_proc_para.user_data = (void*)&g_is_missed_call;
alert_info.app_proc_para.data_size = sizeof(mmi_clog_rsp_missed_call);

#else
    alert_info.app_proc_para.user_data = NULL;
    alert_info.app_proc_para.data_size = 0;

#endif
    
#if SRV_PBAPC_LINK_NUM >= 2
    bt_nmgr_handle[index] = mmi_frm_nmgr_alert(&alert_info);
#else
    bt_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);
#endif

    OslMfree(buf);
}
#endif


mmi_ret mmi_clog_bt_dialer_bt_disconn_hdlr(mmi_event_struct *evt)
{
    U8 index;
    srv_pbapc_notify_event_struct *notify_evt;

    notify_evt = (srv_pbapc_notify_event_struct *)evt;
    MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_PBAPC_DISCONN_V3, notify_evt->evt_id, notify_evt->type, notify_evt->bt_index);
    if(notify_evt->evt_id == EVT_ID_PBAP_NOTIFY && (notify_evt->type == EVT_ID_PBAPC_DISCONNECT_IND || notify_evt->type == EVT_ID_PBAPC_DISCONNECT_RSP))//EVT_ID_DIALER_DISCONN_EVENT_ID)
    {
	#ifdef __MMI_BT_NOTI_SRV__
			
		#if SRV_PBAPC_LINK_NUM >= 2
			MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_PBAPC_DISCONN, (U32)bt_nmgr_handle[notify_evt->bt_index],evt->evt_id);

			if (bt_nmgr_handle[notify_evt->bt_index])
			{
				mmi_frm_nmgr_alert_cancel(bt_nmgr_handle[notify_evt->bt_index]);
		
			}
		
		#else
			MMI_TRACE(MMI_CLOG_TRC_INFO, TRC_MMI_CLOG_PBAPC_DISCONN, (U32)bt_nmgr_handle,evt->evt_id);

			if (bt_nmgr_handle)
			{
				mmi_frm_nmgr_alert_cancel(bt_nmgr_handle);
			}
		#endif
	#endif      
        mmi_clog_set_bt_status(notify_evt->bt_index);
    }

    return MMI_RET_OK;
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_nmgr_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__ 
void mmi_clog_nmgr_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 total_num;
    mmi_nmgr_info_struct nmgr_info = {0};
    WCHAR *buf;
    MMI_STR_ID str_id = STR_ID_CLOG_SINGLE_MISSED_CALL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_clog_is_ready())
    {
        mmi_nmgr_answer(MMI_NMGR_APP_MISSED_CALL, MMI_NMGR_RESULT_OK, &nmgr_info, mmi_clog_nmgr_select);
        return;
    }
    
    buf = OslMalloc(MMI_CLOG_TMP_BUF_SIZE);
#ifdef __MMI_TELEPHONY_SUPPORT__
    total_num = srv_clog_get_unread_missed_call_num();
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    if (total_num > 1)
        str_id = STR_ID_CLOG_MULTI_MISSED_CALLS;

    kal_wsprintf(buf, "%d %w", total_num, get_string(str_id));
    nmgr_info.idle_text1 = (CHAR*) buf;
    nmgr_info.image = IMG_ID_CLOG_NEW_MISSED_CALL;
    nmgr_info.icon = IMG_ID_CLOG_MISSED_CALL;
    nmgr_info.total_num = total_num;

    mmi_nmgr_answer(MMI_NMGR_APP_MISSED_CALL, MMI_NMGR_RESULT_OK, &nmgr_info, mmi_clog_nmgr_select);
    OslMfree(buf);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clog_nmgr_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_clog_nmgr_select(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clog_mclt_launch();
}

#endif  /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/

#ifdef __MMI_APP_MANAGER_SUPPORT__

mmi_ret mmi_clog_appmgr_package_proc(mmi_event_struct *evt)
{	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_nativeappfactory_query_app_badge_evt_struct *badge_evt;
	U32 badge_num = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	badge_evt = (srv_nativeappfactory_query_app_badge_evt_struct*) evt;

	switch (evt->evt_id)
	{
		case EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_BADGE:
          #ifdef __MMI_TELEPHONY_SUPPORT__
			badge_num = srv_clog_get_unread_missed_call_num();
          #endif /* __MMI_TELEPHONY_SUPPORT__ */
			if (badge_num != 0)
			mmi_wsprintf_ex(badge_evt->badge,(SRV_APPMGR_BADGE_MAX_LEN+1)*sizeof(WCHAR),
				(WCHAR*)L"%d",badge_num);
			else
				mmi_wsprintf_ex(badge_evt->badge,(SRV_APPMGR_BADGE_MAX_LEN+1)*sizeof(WCHAR),
					(WCHAR*)L"",badge_num);
			return MMI_RET_OK;
		default:
			return MMI_RET_DONT_CARE;
	}
}

#endif /*__MMI_APP_MANAGER_SUPPORT__*/


#if defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_clog_handle_sim_ctrl_event
 * DESCRIPTION
 *  handle SimCtrl srv event, such as SIM Hot Swap event(SIM insert/remove)
 * PARAMETERS
 *  mmi_event_struct       [IN]       
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_clog_handle_sim_ctrl_event(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->evt_id)
    {
        case EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED:
        {
            S32 i;
            srv_sim_ctrl_event_detected_evt_struct *evt = (srv_sim_ctrl_event_detected_evt_struct *)event;
            switch (evt->type)
            {
                case SRV_SIM_CTRL_EVENT_DET_REMOVED:
                case SRV_SIM_CTRL_EVENT_DET_INSERTED:
                case SRV_SIM_CTRL_EVENT_DET_RECOVERY_START:
                case SRV_SIM_CTRL_EVENT_DET_RECOVERY_END:
                    /* only Callcost have relation with SIM's status, so need kill callcost screen */
                    #ifndef __MMI_CLOG_SLIM_FOR_MT6261__
                    for (i = GRP_ID_CLOG_CALL_COST; i < GRP_ID_CLOG_CALL_COST_LAST; i++)
                    {
                        if (mmi_frm_group_is_present((MMI_ID)i))
                            mmi_frm_group_close((MMI_ID)i);
                    }
                    break;
                    #endif 

                default:
                    break;
            }
            break;
        }

        default:
            break;
    }
    return ret;
}
#endif /* defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__) */

#else /* __MMI_TELEPHONY_SUPPORT__ || __MMI_BT_PBAP_CLIENT__ */

void mmi_clog_launch(void)
{
}

void mmi_clog_sendkey_launch(void)
{
}

MMI_BOOL mmi_clog_nmgr_check(void)
{
    return MMI_TRUE;
}

void mmi_clog_nmgr_enter(void)
{
}

#endif /* __MMI_TELEPHONY_SUPPORT__ || __MMI_BT_PBAP_CLIENT__ */
