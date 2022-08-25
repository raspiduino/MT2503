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
 * OPPMMIScr.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for MMI OPP service.
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

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_OPP_SUPPORT__


/*  Include: MMI header file */
#include "vObjects.h"

#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#endif

/* External Device Header Files */
#if defined(__MMI_BT_SUPPORT__)

#include "BtcmSrvGprot.h"
#include "app_mine.h"
#include "BTMMIObexGprots.h"
#include "OppSrvGprot.h"
#include "BTMMIOpp.h"
#include "IdleGprot.h"

#endif /* defined(__MMI_BT_SUPPORT__) */ 

#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif 
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "BTMMISendGprots.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "NotificationGprot.h"
#include "kal_general_types.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "fs_type.h"
#include "fs_func.h"
#include "FileMgrSrvGProt.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "mmi_rp_file_type_def.h"
#include "GpioSrvGprot.h"
#include "kal_public_api.h"
#include "GlobalResDef.h"
#include "fs_errcode.h"
#include "drm_def.h"
#include "drm_errcode.h"
#include "mmi_frm_history_gprot.h"
#include "wgui_categories_text_viewer.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
/* RHR add end */
mmi_opp_struct mmi_opp_cntx;
mmi_opp_struct *mmi_opp_p = &mmi_opp_cntx;

#define OPPC_TMP_BUFF_SIZE   (192)
static U16 g_opp_tmp_buff[OPPC_TMP_BUFF_SIZE];  /* for file name buffer */

/***************************************************************************** 
* External Functions
*****************************************************************************/

/***************************************************************************** 
 * External Variable
 *****************************************************************************/


/***************************************************************************** 
* Internal Functions
*****************************************************************************/
static S32 mmi_opps_event_handle(S32 srv_hd, U32 event_id, void *para);
static void mmi_opps_init_cntx(void);
static void mmi_opps_accept_file_recv(void);
#ifdef __MMI_BT_RECV_OBJ_DETAIL__
static void mmi_opps_reject_file_recv(void);
#endif
static void mmi_opps_authorize_ind_handle(void *para);
static void mmi_opps_disconn_ind_handle(void *para);
static void mmi_opps_recv_ind_handle(void *para);

static MMI_BOOL mmi_opp_is_vobject(const U16 *obj_name);
static void mmi_opp_scr_recv_obj_ind(void);
static U16 mmi_opp_get_fs_string(S32 err_code);
static void mmi_opp_cancel_request_hdlr(void);
static void mmi_opp_notify_err_request_hdlr(UI_string_type string, mmi_event_notify_enum event_id);
static U16 *mmi_opps_compose_string(U8 type);
static void mmi_opps_delete_screen(U16 scrn_id);
static void mmi_opps_recv_notify(S32 hd, U32 event, S32 retval);
extern void  mmi_bt_authorize_screen_close(U32 profile_id);
extern void mmi_bt_authorize_ind_notify(U8* dev_name, srv_bt_cm_bt_addr *dev_addr, U32 profile_id, void *callback);
#ifdef __DRM_SUPPORT__
static MMI_BOOL mmi_opp_check_drm_right(U16 *file_path);
#endif

extern void srv_opps_send_disconnect_request();
#ifdef __MMI_BT_RECV_OBJ_DETAIL__

static void mmi_opp_print_size(U32 sz, U16 *tmp_str, MMI_BOOL b_print_0byte);
static void mmi_opp_compose_obj_detail(U16 *out);
static mmi_ret mmi_opps_detail_confirm_proc(mmi_event_struct *evt);
static void mmi_opps_entry_detail_confirm_scr(void);
static void mmi_opps_exit_detail_confirm_scr(void);
static MMI_BOOL mmi_opps_notify_entry_hdlr(mmi_scenario_id scen_id, void *arg);
static mmi_ret mmi_opps_detail_confirm_scr_leave_proc(mmi_event_struct *evt);

#endif /* __MMI_BT_RECV_OBJ_DETAIL__ */ 



/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_OPP_INIT); 

    srv_opp_init();
    mmi_oppc_init();
    mmi_opps_init_cntx();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opp_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_OPP_DEINIT); 
    srv_opp_deinit();
    mmi_oppc_deinit();

    srv_opp_close(mmi_opp_p->opps_cntx.srv_hd);
    mmi_opp_p->opps_cntx.srv_hd = 0;
}

#define MMI_OPP_SERVER
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_opp_authorize_rsp_hdler
 * DESCRIPTION
 *  This function is to deal whether user accpet or reject the file
 * PARAMETERS
 *  bd_addr     [IN]        
 *  result      [IN]        
 *  msg         [?](?)(?)
 *  a(?)        [IN/OUT]        First variable, used as returns(?)(?)
 *  b(?)        [IN]            Second variable(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_opp_authorize_rsp_hdler(srv_bt_cm_bt_addr *bd_addr, U32 prof_id, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG1(MMI_OPP_AUTHORIZE_RSP_HDLR,result);
    
    if (prof_id != SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID)
        return;
    if (result)
    {
    #if defined(__MMI_BT_RECV_OBJ_DETAIL__)

        mmi_frm_nmgr_notify_by_app(
            MMI_SCENARIO_ID_BT_ACCESS_REQ,
            MMI_EVENT_INFO,
            mmi_opps_notify_entry_hdlr,
            NULL);
    #else /* defined(__MMI_BT_RECV_OBJ_DETAIL__) */ 
        {
            mmi_opps_accept_file_recv();
        }
    #endif /* defined(__MMI_BT_RECV_OBJ_DETAIL__) */ 
    }
    else
    {
        srv_opps_reject(mmi_opp_p->opps_cntx.srv_hd);
		srv_opps_send_disconnect_request();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opps_event_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_hd          [IN]        
 *  event_id        [IN]        
 *  para            [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_opps_event_handle(S32 srv_hd, U32 event_id, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_hd <= 0)
        return SRV_OPP_RESULT_INVALID_HANDLE;

    if (srv_hd == mmi_opp_p->opps_cntx.srv_hd)
    {
        switch (event_id)
        {
            case SRV_OPP_EVENT_AUTHORIZE_NOTIFY:
                mmi_opps_authorize_ind_handle(para);
                break;
            case SRV_OPP_EVENT_RECV_NOTIFY:
                mmi_opps_recv_ind_handle(para);
                break;
            case SRV_OPP_EVENT_DISCONN_NOTIFY:
                mmi_opps_disconn_ind_handle(para);
                break;
            default:
                return SRV_OPP_RESULT_INVALID_PARAM;
        }

        return SRV_OPP_RESULT_OK;
    }
    return SRV_OPP_RESULT_INVALID_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opps_init_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opps_init_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 event_mask;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_opp_p->opps_cntx.disconn_from_cm = MMI_FALSE;
    mmi_opp_p->opps_cntx.obj_len = 0;
    mmi_opp_p->opps_cntx.cur_recv_file_cnt = 0;
    mmi_opp_p->opps_cntx.gid = 0;
    //mmi_opp_p->opps_cntx.recv_drv = 0;
    mmi_opp_p->opps_cntx.srv_hd = srv_opp_open(SRV_OPP_ROLE_SERVER);

    if (mmi_opp_p->opps_cntx.srv_hd < 0)
         return;
    
    event_mask = SRV_OPP_EVENT_AUTHORIZE_NOTIFY |
                 SRV_OPP_EVENT_DISCONN_NOTIFY | SRV_OPP_EVENT_RECV_NOTIFY;

    srv_opp_set_notify(mmi_opp_p->opps_cntx.srv_hd, event_mask, (bt_notify) mmi_opps_event_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opps_accept_file_recv
 * DESCRIPTION
 *  This function is to accept receving file object.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)(?)
 *  b(?)        [IN]            Second variable(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opps_accept_file_recv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_recv_obj_info obj;
    bt_recv_storage storage;
    mmi_opps_cntx_struct *opps = &mmi_opp_p->opps_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_OPP_ACCEPT_FILE_RECV);
    StopTimer(BT_OPP_PUSH_IND_TIMER);
    
    obj.name = opps->obj_name;
    obj.mime = opps->obj_mime;
    obj.size = opps->obj_len;
    obj.type = 0;
    
    if (mmi_opp_is_vobject(obj.name))
    {
        storage.drive = SRV_FMGR_PUBLIC_DRV;
        storage.folder = NULL;
        mmi_opp_p->opps_cntx.recv_hd = mmi_bt_start_receive(mmi_opps_recv_notify, &obj, &storage, 0);
    }
    else
    {
        mmi_opp_p->opps_cntx.recv_hd = mmi_bt_start_receive(mmi_opps_recv_notify, &obj, NULL, 0);
    }
    if (mmi_opp_p->opps_cntx.gid != 0)
    {
        mmi_frm_scrn_set_leave_proc(
                    mmi_opp_p->opps_cntx.gid,
                    SCR_OPP_NOTY_RECV_ACCEPT,
                    NULL);
        mmi_frm_group_close(mmi_opp_p->opps_cntx.gid);
    }
}

#ifdef __MMI_BT_RECV_OBJ_DETAIL__
/*****************************************************************************
 * FUNCTION
 *  mmi_opps_reject_file_recv
 * DESCRIPTION
 *  This function is to reject receving file object.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)(?)
 *  b(?)        [IN]            Second variable(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opps_reject_file_recv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG(MMI_OPP_REJECT_FILE_RECV);

    StopTimer(BT_OPP_PUSH_IND_TIMER);

    srv_opps_reject(mmi_opp_p->opps_cntx.srv_hd);

    if (mmi_opp_p->opps_cntx.gid != 0)
    {
        mmi_frm_scrn_set_leave_proc(
                    mmi_opp_p->opps_cntx.gid,
                    SCR_OPP_NOTY_RECV_ACCEPT,
                    NULL);
        mmi_frm_group_close(mmi_opp_p->opps_cntx.gid);
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_opps_authorize_notify_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opps_authorize_ind_handle(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //srv_opp_authorize_notify_struct *auth_notify = (srv_opp_authorize_notify_struct*) para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        srv_opps_reject(mmi_opp_p->opps_cntx.srv_hd);
        return;
    }
    #endif /* __USB_IN_NORMAL_MODE__ */ 
    
    if (mmi_bt_receiving_disabled())
    {
        srv_opps_reject(mmi_opp_p->opps_cntx.srv_hd);
        return;
    }
    srv_opps_accept(mmi_opp_p->opps_cntx.srv_hd, (U16*) NULL);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opps_disconn_notify_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opps_disconn_ind_handle(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BT_OPP_PUSH_IND_TIMER);
    mmi_opp_cancel_request_hdlr();

    if (mmi_opp_p->opps_cntx.recv_hd > 0)
    {
        mmi_bt_stop_receive(mmi_opp_p->opps_cntx.recv_hd, SRV_OPP_RECEIVE_FAIL);
    }
    mmi_opps_delete_screen(SCR_OPP_NOTY_RECV_ACCEPT);
    mmi_bt_authorize_screen_close(SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID);
    if (mmi_opp_p->opps_cntx.cur_recv_file_cnt > 0)
    {
        //mmi_opp_p->opps_cntx.recv_file_cnt += mmi_opp_p->opps_cntx.cur_recv_file_cnt;
        mmi_opp_scr_recv_obj_ind();
    }
    mmi_opp_p->opps_cntx.disconn_from_cm = MMI_FALSE;
    mmi_opp_p->opps_cntx.obj_len = 0;
    mmi_opp_p->opps_cntx.cur_recv_file_cnt = 0;
    mmi_opp_p->opps_cntx.gid = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opps_recv_notify_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opps_recv_ind_handle(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opp_recv_notify_struct *recv_notify = (srv_opp_recv_notify_struct*) para;
    bt_recv_storage storage;
    bt_recv_obj_info obj;
    U8 dev_name[SRV_BT_CM_BD_FNAME_LEN];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG1(MMI_OPP_RECV_IND_HANDLE, recv_notify->type);
    
    switch (recv_notify->type)
    {
        case SRV_OPP_RECV_READY:
            {   
                mmi_wcscpy(mmi_opp_p->opps_cntx.obj_name, recv_notify->u.detail.name);
                strcpy(mmi_opp_p->opps_cntx.obj_mime, (S8 *)recv_notify->u.detail.mime_type);

                mmi_opp_p->opps_cntx.obj_len = recv_notify->u.detail.total_len;
                srv_bt_cm_get_dev_name(
                    &recv_notify->bt_addr,
                    sizeof(dev_name),
                    dev_name);
                mmi_bt_authorize_ind_notify(dev_name,
                    &recv_notify->bt_addr,
                    SRV_BT_CM_OBEX_OBJECT_PUSH_SERVICE_UUID,
                    (void*)mmi_bt_opp_authorize_rsp_hdler);
            }
            break;
            
        case SRV_OPP_RECV_BEGIN:
            mmi_wcscpy(mmi_opp_p->opps_cntx.obj_name, recv_notify->u.detail.name);
            strcpy(mmi_opp_p->opps_cntx.obj_mime, (S8 *)recv_notify->u.detail.mime_type);
            mmi_opp_p->opps_cntx.obj_len = recv_notify->u.detail.total_len;
        #if defined(__MMI_BT_RECV_OBJ_DETAIL__)
            mmi_frm_nmgr_notify_by_app(
                MMI_SCENARIO_ID_BT_ACCESS_REQ,
                MMI_EVENT_INFO,
                mmi_opps_notify_entry_hdlr,
                NULL);
        #else /* defined(__MMI_BT_RECV_OBJ_DETAIL__) */ 
            {
                storage.folder = NULL;
                obj.name = mmi_opp_p->opps_cntx.obj_name;
                obj.size = mmi_opp_p->opps_cntx.obj_len;
                obj.mime = mmi_opp_p->opps_cntx.obj_mime;
                obj.type = 0;
                if (mmi_opp_is_vobject(mmi_opp_p->opps_cntx.obj_name))
                {
                    storage.drive = SRV_FMGR_PUBLIC_DRV;
                    mmi_opp_p->opps_cntx.recv_hd = mmi_bt_start_receive(
					    mmi_opps_recv_notify, &obj, &storage, 0);
                }
                else
                {
                    if (mmi_opp_p->opps_cntx.cur_recv_file_cnt > 0)
                    {
                        storage.drive = mmi_opp_p->opps_cntx.recv_drv;
                        mmi_opp_p->opps_cntx.recv_hd = mmi_bt_start_receive(
			    mmi_opps_recv_notify, &obj, &storage, 0);
                    }
                    else
                    {
                        mmi_opp_p->opps_cntx.recv_hd = mmi_bt_start_receive(
			    mmi_opps_recv_notify, &obj, NULL, 0);
                    }
                }
            }
        #endif /* defined(__MMI_BT_RECV_OBJ_DETAIL__) */ 
            break;

        case SRV_OPP_RECV_SUCCESS:
#ifdef __DRM_SUPPORT__
            if (mmi_opp_check_drm_right(mmi_opp_p->opps_cntx.recv_path))
            {
                if (mmi_opp_p->opps_cntx.recv_hd > 0)
                {
                    mmi_bt_stop_receive(mmi_opp_p->opps_cntx.recv_hd, SRV_OPP_DRM);
                }
                return;
            }
#endif /* __DRM_SUPPORT__ */ 
            if (mmi_opp_is_vobject(mmi_opp_p->opps_cntx.obj_name))
            {
                mmi_opp_p->opps_cntx.mime = recv_notify->u.obj.mime;
            }
            if (mmi_opp_p->opps_cntx.recv_hd > 0)
            {
                mmi_bt_stop_receive(mmi_opp_p->opps_cntx.recv_hd, BTRECV_RET_SUCC);
            }
            break;

        case SRV_OPP_RECV_FAIL:
            if (mmi_opp_p->opps_cntx.recv_hd > 0)
            {
                mmi_bt_stop_receive(mmi_opp_p->opps_cntx.recv_hd, recv_notify->u.err_code);
            }
            break;
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_opps_recv_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opps_recv_notify(S32 hd, U32 event, S32 retval)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;
    S32 ret;
    WCHAR tmp_name[OPP_MAX_OBJ_NAME_LENGTH + 60];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPP_LOG2(MMI_OPP_RECV_NOTIFY, event, retval);
    switch (event)
    {
        case BTRECV_EV_START:
            if (retval != BTRECV_RET_SUCC)
            {
                srv_opps_reject(mmi_opp_p->opps_cntx.srv_hd);
                switch (retval)
                {
                    case BTRECV_RET_MEMORY_FULL:
                        ret = SRV_OPP_DISK_FULL;
                        break;
                    case BTRECV_RET_MSDC_MISSED:
                        ret = SRV_OPP_MEDIA_CHANGED;
                        break;
                    default:
                        return;
                }
                string_id = mmi_opp_get_fs_string(ret);
                mmi_opp_notify_err_request_hdlr(
                        (UI_string_type) GetString(string_id), MMI_EVENT_FAILURE);
                return;
            }
            
            mmi_bt_get_receive_info(hd, (void*)tmp_name, BTRECV_INFO_STORAGE);
            mmi_opp_p->opps_cntx.recv_drv = (U8)tmp_name[0];
            srv_opps_accept(
                mmi_opp_p->opps_cntx.srv_hd,
                tmp_name);
            break;
        case BTRECV_EV_DONE:
            mmi_opp_p->opps_cntx.recv_hd = -1;
            switch (retval)
            {
                case BTRECV_RET_SUCC:
                    ret = 0;
                    if (mmi_opp_is_vobject(mmi_opp_p->opps_cntx.obj_name))
                    {
#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
                        mmi_bt_get_receive_info(hd, 
                            (void*)tmp_name, BTRECV_INFO_OBJ_PATH);
                        mmi_vobj_opp_receive_ind((void*)tmp_name, 
                            mmi_opp_p->opps_cntx.mime);
#endif
                    }
                    else
                    {
                        mmi_opp_p->opps_cntx.cur_recv_file_cnt++;
                        mmi_opp_p->opps_cntx.recv_file_cnt++;
                        mmi_bt_get_receive_info(hd, 
                        (void*)mmi_opp_p->opps_cntx.recv_path, BTRECV_INFO_OBJ_FLDR);

#if defined(__MMI_NCENTER_SUPPORT__)
                        mmi_bt_ncenter_notify_notification();
#endif
                    }
                    break;
                case BTRECV_RET_USER_ABORT:
                    ret = 0;
                    break;
                case BTRECV_RET_FAIL:
                    ret = SRV_OPP_RECEIVE_FAIL;
                    break;
                case BTRECV_RET_MEMORY_FULL:
                    ret = SRV_OPP_DISK_FULL;
                    break;
                case BTRECV_RET_MSDC_MISSED:
                    ret = SRV_OPP_MEDIA_CHANGED;
                    break;
                default:
                    ret = retval;
                    break;
            }
            if ((ret > 0) && (ret != SRV_OPP_USER_ABORT) && (ret != SRV_OPP_WRITE_FAIL))
            {
                string_id = mmi_opp_get_fs_string(ret);                
                if (mmi_opp_p->opps_cntx.cur_recv_file_cnt == 0)
                {
                    mmi_opp_notify_err_request_hdlr(
                        (UI_string_type) GetString(string_id), MMI_EVENT_FAILURE);
                }
            }
            break;
        default:
            break;
    }
}

#define MMI_OPP_QUERY

/*****************************************************************************
 * FUNCTION
 *  mmi_opp_is_receiving
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)(?)
 *****************************************************************************/
MMI_BOOL mmi_opp_is_receiving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_opps_is_receiving();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_accepted_file
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)(?)
 *****************************************************************************/
MMI_BOOL mmi_opp_accepted_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_opps_is_accepted();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_is_vobject
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj_name        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_opp_is_vobject(const U16 *obj_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 obj_type = (U32) srv_fmgr_types_find_type_by_filename_str((WCHAR*)obj_name);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (obj_type)
    {
    #if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__)
    #ifdef __MMI_VCARD__
        case FMGR_TYPE_VCF:
    #endif 
    #ifdef __MMI_VCALENDAR__
        case FMGR_TYPE_VCS:
    #endif 
    #ifdef __MMI_VBOOKMARK__
        case FMGR_TYPE_URL:
        case FMGR_TYPE_VBM:
    #endif /* __MMI_VBOOKMARK__ */ 
            return MMI_TRUE;
    #endif /* defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__) || defined(__MMI_VBOOKMARK__) */ 
        default:
            return MMI_FALSE;
    }
}


#define MMI_OPP_LIB

/*****************************************************************************
 * FUNCTION
 *  mmi_opp_scr_recv_obj_ind
 * DESCRIPTION
 *  This function is to display popup sceren when receiving file
 * PARAMETERS
 *  void
 *  cause(?)        [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opp_scr_recv_obj_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_opp_notify_err_request_hdlr((UI_string_type) mmi_opps_compose_string(MMI_OPP_NOTIFY_RECV), MMI_EVENT_SUCCESS);

    if (mmi_idle_is_active() || GetActiveScreenId() == SCR_OPP_NOTY_FILE_RECV)
    {
        mmi_idle_display();
    }

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_get_path
 * DESCRIPTION
 *  This function is to update part of path
 * PARAMETERS
 *  void
 *  path(?)     [IN](?)
 *  fldr(?)     [OUT](?)
 * RETURNS
 *  U16 *
 *****************************************************************************/
S8 *mmi_opp_get_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* S8 *path = (S8*) g_opp_tmp_buff; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S8*) mmi_opp_p->opps_cntx.recv_path;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_get_fs_string
 * DESCRIPTION
 *  This function is to set fs error flag
 * PARAMETERS
 *  err_code        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
static U16 mmi_opp_get_fs_string(S32 err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (err_code)
    {
        case SRV_OPP_PUT_TYPE:
            string_id = STR_OPP_UNKNOWN_FILE_TYPE;
            break;

        case SRV_OPP_DRM:
            string_id = STR_BT_DRM_PROHIBITED;
            break;

        case SRV_OPP_DISK_FULL:
            string_id = STR_GLOBAL_MEMORY_FULL;
            break;

        case SRV_OPP_ROOT_DIR_FULL:
            string_id = STR_OPP_RECV_ROOT_DIR_FULL;
            break;

        case SRV_OPP_DEVICE_BUSY:
            string_id = srv_fmgr_fs_error_get_string(FS_DEVICE_BUSY);
            break;

        case SRV_OPP_MEDIA_CHANGED:
            string_id = STR_BT_NO_CARD;
            break;

        case SRV_OPP_WRITE_PROTECT:
            string_id = srv_fmgr_fs_error_get_string(FS_WRITE_PROTECTION);
            break;

        case SRV_OPP_WRITE_FAIL:
            string_id = STR_BT_WRITE_FILE_FAIL;
            break;
        case SRV_OPP_RECEIVE_FAIL:
            string_id = STR_BT_RECEIVE_FAIL;
            break;

        default:
            string_id = STR_BT_WRITE_FILE_FAIL;
            break;
    }

    return string_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_set_recv_files_cnt
 * DESCRIPTION
 *  This function is to set received files count.
 *  
 *  PARAMETERS: U8 cnt
 *  cnt     [IN]        
 *  RETURNS: viod(?)(?)(?)
 *****************************************************************************/
void mmi_opp_set_recv_files_cnt(U16 cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_opp_p->opps_cntx.recv_file_cnt = cnt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_get_recv_files_cnt
 * DESCRIPTION
 *  This function is to get received files count.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)(?)(?)
 *****************************************************************************/
U16 mmi_opp_get_recv_files_cnt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_opp_p->opps_cntx.recv_file_cnt;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_cancel_request_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opp_cancel_request_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_RECV_OBJ_DETAIL__

    /* MMI_OPP_LOG(MMI_BT_OPP_CANCEL_REQUEST_HDLR); */
    mmi_frm_nmgr_cancel_deferred_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ, mmi_opps_notify_entry_hdlr, NULL);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_notify_err_request_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string          [IN]        
 *  event_id        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opp_notify_err_request_hdlr(UI_string_type string, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__

    if (srv_usb_is_in_mass_storage_mode())
    {
        /* usb mode: don't popup */
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, event_id, string);

}

#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_opp_check_drm_right
 * DESCRIPTION
 *  check drm file whether is correct
 * PARAMETERS
 *  file_path       [?]     
 *  uuid(?)
 *  drv(?)
 *  selected(?)
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_opp_check_drm_right(U16 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    S32 size = DRM_MAX_URL_LENGTH;
    U8 method;
    S8 url[DRM_MAX_URL_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = DRM_open_file((kal_wchar*) file_path, FS_READ_ONLY, DRM_PERMISSION_NONE);
    if (handle < DRM_RESULT_OK)
    {
        return MMI_FALSE;   /* not a valid file */
    }
    else
    {
        method = DRM_get_object_method(handle, NULL);

        if ((method & DRM_METHOD_SEPARATE_DELIVERY) || method == DRM_METHOD_V2 || method == DRM_METHOD_PDCF)
        {
            if (DRM_RESULT_OK > DRM_get_rights_issuer(handle, (kal_char*) url, (kal_uint32*) & size))
            {
                size = 0;
            }
        }

        DRM_close_file(handle);
    }

    if (size == 0)
    {
        FS_Delete((kal_wchar*) file_path);
        return MMI_TRUE;

    }
	return MMI_FALSE;
}
#endif
#ifdef __MMI_USB_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_opp_usb_plugin_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret  mmi_opp_usb_plugin_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_opp_is_receiving())
    {
        srv_opp_close_temp_obj();
        if (mmi_opp_p->opps_cntx.recv_hd > 0)
        {
            mmi_bt_stop_receive(mmi_opp_p->opps_cntx.recv_hd, SRV_OPP_USER_ABORT);
        }
        srv_opps_disconn_client(mmi_opp_p->opps_cntx.srv_hd);
    }
    mmi_oppc_usb_plugin_hdlr();

#if !defined(__MMI_NCENTER_SUPPORT__)
    mmi_opp_set_recv_files_cnt(0);
#endif

    return MMI_RET_OK;
}
#else
mmi_ret  mmi_opp_usb_plugin_hdlr(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}
#endif

#define MMI_OPP_UI_SCREEN

/*****************************************************************************
 * FUNCTION
 *  mmi_opps_compose_string
 * DESCRIPTION
 *  This function is to compose displaying string for viarious event
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U16 *mmi_opps_compose_string(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Use nPrintableStr to save memory */
    U16 *string = g_opp_tmp_buff;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
    #ifdef __MMI_BT_RECV_OBJ_DETAIL__
        case MMI_OPP_NOTIFY_DETAIL:
        {
            mmi_opp_compose_obj_detail(string);
        }
            break;

    #endif /* __MMI_BT_RECV_OBJ_DETAIL__ */ 
        case MMI_OPP_NOTIFY_RECV:
        {
            /* Here we need to clarify single or plural object received */
        #ifdef __MMI_BT_RECV_FDR_SWITCH__
            if (mmi_opp_p->opps_cntx.cur_recv_file_cnt > 1)
            {
                mmi_wcscpy(string, (U16 *)GetString(STR_OPP_RECV_FILES_IND2));
            }
            else
            {
                mmi_wcscpy(string, (U16 *)GetString(STR_OPP_RECV_FILE_IND2));
            }
        #else /* __MMI_BT_RECV_FDR_SWITCH__ */ 

            if (mmi_opp_p->opps_cntx.cur_recv_file_cnt > 1)
            {
                mmi_wcscpy(string, (U16 *)GetString(STR_OPP_RECV_FILES_IND));
            }
            else
            {
                mmi_wcscpy(string, (U16 *)GetString(STR_OPP_RECV_FILE_IND));
            }
            mmi_wcscat(string,  (U16 *)L" '");
            len = mmi_wcslen(string);
            mmi_bt_get_fldr_name(&string[len], mmi_opp_p->opps_cntx.recv_path);
            mmi_wcscat(string, (U16 *) L"' ");
            mmi_wcscat(string, (U16 *)GetString(STR_OPP_NOTY_RECV_FOLDER));
        #endif /* __MMI_BT_RECV_FDR_SWITCH__ */ 
        }
            break;
            }
    return string;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opps_delete_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  scrn_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opps_delete_screen(U16 scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_opp_p->opps_cntx.gid != 0)
    {
        mmi_frm_scrn_set_leave_proc(
                    mmi_opp_p->opps_cntx.gid,
                    SCR_OPP_NOTY_RECV_ACCEPT,
                    NULL);
    }
    if (scrn_id == mmi_frm_scrn_get_active_id())
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        mmi_frm_scrn_close(mmi_opp_p->opps_cntx.gid, scrn_id);
    }
}

#ifdef __MMI_BT_RECV_OBJ_DETAIL__


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_print_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sz                  [IN]        
 *  tmp_str             [?]         [?]         [?]
 *  b_print_0byte       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opp_print_size(U32 sz, U16 *tmp_str, MMI_BOOL b_print_0byte)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sz > 1024 * 1024)
    {
        sz = sz / 1024;
        kal_wsprintf(tmp_str, "%d.%dMB", (U16) (sz / 1024), (U16) ((sz % 1024) / 103));
    }
    else if (sz > 1024)
    {
        kal_wsprintf(tmp_str, "%d.%dKB", (U16) (sz / 1024), (U16) ((sz % 1024) / 103));
    }
    else if (sz > 0)    /* less than 1024 */
    {
        kal_wsprintf(tmp_str, "%dB", (U16) (sz));
    }
    else if (b_print_0byte)
    {
        kal_wsprintf(tmp_str, "%dB", 0);
    }
    else
    {
        tmp_str[0] = 0;
        tmp_str[1] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_compose_obj_detail
 * DESCRIPTION
 *  This function is to compose object detail information
 * PARAMETERS
 *  out     [?]     [?]
 *  type(?)     [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opp_compose_obj_detail(U16 *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    U16 tmp_str[32];
    applib_mime_type_struct *mime_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    mmi_wcscpy(out, (U16 *)GetString(STR_BT_OBJ_TILE));
    mmi_wcscat(out, (U16 *)GetString(STR_BT_QUESTION_MARK));
    mmi_wcscat(out, (U16 *) L"\r\n\r\n");
    
    mmi_wcscat(out, (U16 *)GetString(STR_BT_OBJ_NAME));

    mmi_wcscat(out, (U16 *) mmi_opp_p->opps_cntx.obj_name);
    mmi_wcscat(out, (U16 *) L"\r\n");
    mmi_wcscat(out, (U16 *)GetString(STR_BT_OBJ_TYPE));

    if (strlen((S8*) mmi_opp_p->opps_cntx.obj_mime) > 0)
    {
        if (strcmp((S8*) mmi_opp_p->opps_cntx.obj_mime, MMI_OPP_SND_DEFAULT_OBJTYPE))
        {
            len = mmi_wcslen(out);
            kal_wsprintf(&out[len], "%s", mmi_opp_p->opps_cntx.obj_mime);
        }
        else
        {
            mmi_wcscat(out, (U16 *)GetString(STR_BT_OBJ_UNKNOWN));
        }
    }
    else
    {
        /* Get object mime type */
        //mime = mmi_bt_opp_get_file_mime_type(mmi_opp_p->opps_cntx.obj_name);
        mime_type = applib_mime_get_file_type(mmi_opp_p->opps_cntx.obj_name);

        if (mime_type == NULL)
        {
            /* OBEX allows to send a object without MIME */
            mmi_wcscat(out, (U16 *)GetString(STR_BT_OBJ_UNKNOWN));
        }
        else
        {
            len = mmi_wcslen(out);
            kal_wsprintf(&out[len], "%s", mime_type->mime_string);
        }
    }

    mmi_wcscat(out, (U16 *) L"\r\n");
    mmi_wcscat(out, (U16 *)GetString(STR_BT_OBJ_SIZE));

    mmi_opp_print_size(mmi_opp_p->opps_cntx.obj_len, tmp_str, MMI_TRUE);
    mmi_wcscat(out, tmp_str);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opps_notify_entry_hdlr
 * DESCRIPTION
 *  This function is to when incoming call is received, display our screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_opps_notify_entry_hdlr(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_opp_p->opps_cntx.gid = mmi_frm_group_create_ex(
                                        GRP_ID_ROOT, 
                                        GRP_ID_AUTO_GEN, 
                                        mmi_opps_detail_confirm_proc, 
                                        NULL,
                                        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_opps_entry_detail_confirm_scr();

	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 * mmi_opps_detail_confirm_proc
 * DESCRIPTION
 *  This function is to reject the connect when confirm screen is deleted
 * PARAMETERS
 *  p       [?]     [?]     [?]
 *  a(?)        [IN/OUT]        First variable, used as returns(?)(?)
 *  b(?)        [IN]            Second variable(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_opps_detail_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            mmi_opp_p->opps_cntx.gid = 0;
            break;
            
        default:
            break;
          
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opps_entry_detail_confirm_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opps_entry_detail_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_scrn_enter(
                mmi_opp_p->opps_cntx.gid, 
                SCR_OPP_NOTY_RECV_ACCEPT, 
                mmi_opps_exit_detail_confirm_scr, 
                mmi_opps_entry_detail_confirm_scr, 
                MMI_FRM_FULL_SCRN))
    {
        mmi_frm_start_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);

    SetDelScrnIDCallbackHandler(SCR_OPP_NOTY_RECV_ACCEPT, NULL);
    DeleteScreenIfPresent(SCR_OPP_NOTY_RECV_ACCEPT);
    guiBuff = mmi_frm_scrn_get_active_gui_buf();

    ShowCategory7Screen(
        STR_GLOBAL_BLUETOOTH,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
            (U8*) mmi_opps_compose_string(MMI_OPP_NOTIFY_DETAIL),
        guiBuff);

    SetLeftSoftkeyFunction(mmi_opps_accept_file_recv, KEY_EVENT_UP);
        ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_opps_accept_file_recv, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_opps_reject_file_recv, KEY_EVENT_UP);
        mmi_frm_scrn_set_leave_proc(
                    mmi_opp_p->opps_cntx.gid,
                    SCR_OPP_NOTY_RECV_ACCEPT,
                    (mmi_proc_func) mmi_opps_detail_confirm_scr_leave_proc);

    srv_backlight_turn_on(1);
    StartTimer(BT_OPP_PUSH_IND_TIMER, OPP_PUSH_IND_PROG_UPD_DUR, mmi_opps_reject_file_recv);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_opps_exit_detail_confirm_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opps_exit_detail_confirm_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_end_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opps_obj_detail_scrn_leave_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_opps_detail_confirm_scr_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            srv_opps_reject(mmi_opp_p->opps_cntx.srv_hd);
            break;

        default:
            break;
    }

    return MMI_RET_OK;

}

#endif /* __MMI_BT_RECV_OBJ_DETAIL__ */ 
#endif /* __MMI_OPP_SUPPORT__ */ 

