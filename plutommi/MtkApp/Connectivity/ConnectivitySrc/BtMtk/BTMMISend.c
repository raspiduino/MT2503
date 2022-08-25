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
 * BTMMISend.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for dispatch primitive from goep obex to different applications.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#include "MMI_features.h"
#ifdef __MMI_BT_SUPPORT__
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif
#include "drm_gprot.h"
#include "BTMMIScrGprots.h"
#include "BtcmSrvGprot.h"
#include "Bluetooth_struct.h"
#include "btsendcuigprot.h"
#include "BTMMISend.h"
#include "ProfilesSrvGprot.h"
#include "custom_events_notify.h"
#include "app_mine.h"
#include "AlertScreen.h"
#include "Conversions.h"
#include "PhoneSetupGprots.h"

#if defined (__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
#include "BTMMIFtpGprots.h"
#endif
#ifdef __MMI_OPP_SUPPORT__
#include "BTMMIOppGprots.h"
#include "OppSrvGprot.h"
#endif

#ifdef __MMI_BIP_SUPPORT__
#include "BTMMIBipGprot.h"
#include "BipSrvGprot.h"

#endif

#ifdef __MMI_OPP_SUPPORT__
#include "BtCMCUIGprot.h"
/* auto add by kw_check begin */
#include "mmi_rp_app_bluetooth_def.h"
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_list.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "MMI_conn_app_trc.h"
#include "kal_trace.h"
#include "string.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "fs_type.h"
#include "Unicodexdcl.h"
#include "FileMgrSrvGProt.h"
#include "mmi_frm_nvram_gprot.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"
#include "mmi_res_range_def.h"
#include "CustDataRes.h"
#ifdef __MMI_USB_SUPPORT__
#include "mmi_rp_app_usbmmi_def.h"
#endif
#include "NotificationGprot.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "wgui_categories_popup.h"
#include "mmi_frm_timer_gprot.h"
#include "CustMenuRes.h"
#include "FileMgrGProt.h"
#include "app_mem.h"
#include "stack_config.h"
#include "wgui_categories_text_viewer.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "lcd_sw_rnd.h"
#ifdef __BT_DIALER_SUPPORT__
#include "bt_common_config.h"
#endif
#ifdef __MMI_BT_SUPPORT__
#include "Mmi_rp_srv_btcm_def.h"
#endif
/* RHR add end */
typedef enum
{   
    EVT_ID_BTSEND_CONTINUE = SCR_BT_SEND_DUMMY,
    EVT_ID_BTSEND_MAX        
}btsend_event_enum;

/*****************************************************************
    INTERNAL STATIC FUNCTIONS
*****************************************************************/
static mmi_ret cui_bt_sending_launch_proc(mmi_event_struct *evt);
static void btsend_select_device(btsend_inst_struct *inst, U8 option);
static mmi_ret btsend_group_proc(mmi_event_struct *evt);
static void mmi_btsend_popup(btsend_inst_struct *inst, U32 result, MMI_BOOL flag);
static void mmi_btsend_display_popup(btsend_inst_struct *inst, UI_string_type string, mmi_event_notify_enum event_id);
static U8   mmi_btsend_check_power_status(void);
static U8   mmi_btsend_power_on(void);
static void btsend_to_device(
                btsend_inst_struct *inst, 
                btsend_device_struct *dev);

#ifdef __MMI_BT_DEF_SEND_DEVICE__
static void mmi_btsend_confirm_to_default(void);
static void btsend_save_defdev(
                btsend_inst_struct *inst, 
                btsend_device_struct *device);
static void btsend_clear_defdev(btsend_inst_struct *inst);
static btsend_device_struct *btsend_get_default_device(btsend_inst_struct *inst);
#endif

//static U8 btsend_get_dev_prof(U32 lap, U8 uap, U16 nap);

static U32 btsend_obj_available(btsend_inst_struct *inst);
static void btsend_save_userdata(btsend_inst_struct *inst, const cui_bt_sending_para_struct* obj);

#if 0
/* under construction !*/
#endif

static void btsend_init(btsend_inst_struct *inst);
static void btsend_begin(btsend_inst_struct *inst, btsend_device_struct *dev);
static void btsend_continue(btsend_inst_struct *inst);

static void  btsend_save_obj(btsend_inst_struct *inst, const cui_bt_sending_obj_struct *obj);
static void btsend_post_message(btsend_inst_struct *inst, MMI_ID id);
static void btsend_result_hdlr(btsend_inst_struct *inst, U32 result);
static MMI_BOOL btsend_is_last_obj(btsend_inst_struct *inst);
static U16 *mmi_send_get_file_name_ext(U16 *name);


#ifdef __MMI_BT_DEF_SEND_DEVICE__
static void btsend_retrieve_defdev(
                btsend_inst_struct *inst,
                btsend_device_struct *dev);
static void btsend_delete_defdev(void);

static void mmi_btsend_entry_to_default_cnf(void);
static void mmi_btsend_to_default_lsk_hdlr(void);
static void mmi_btsend_to_default_rsk_hdlr(void);
static UI_string_type mmi_btsend_compose_def_string(void);
static void mmi_btsend_show_confirm(U16 scrn_id, UI_string_type string,
                                    FuncPtr exit_func, FuncPtr entry_func);
#endif

static U16 *mmi_send_compose_string(U8 type);
static void mmi_send_update_prog_tohdlr(void);
static void mmi_send_entry_sending_scr(void);
static void mmi_send_cancel(void);
static void mmi_send_entry_cancelling_scr(void);
static void mmi_send_exit_sending_scr(void);
static mmi_ret mmi_send_sending_screen_proc(mmi_event_struct *evt);

#ifdef __MMI_OPP_SUPPORT__
static void mmi_oppc_send_file_to_dev(btsend_inst_struct *inst);
static void mmi_oppc_send_obj(btsend_inst_struct *inst);

static U8 *mmi_oppc_alloc_buffer(void);
static void mmi_oppc_free_buffer(U8 *buffer);
static void mmi_oppc_asm_alloc_callback(void);
static void mmi_oppc_asm_not_alloc_callback(mmi_frm_appmem_evt_struct *evt);
static void mmi_oppc_asm_stop_app_callback(void);
static S32 mmi_oppc_event_handle(S32 srv_hd, U32 event_id, void *para);
static void mmi_oppc_pre_send(srv_bt_cm_bt_addr bt_addr);
static S32 mmi_oppc_send_begin(U8 *buffer, U32 buf_size, srv_bt_cm_bt_addr dst_dev);
static void mmi_oppc_send_finish(void);
static void mmi_oppc_send_ind_handle(void *para);
static void mmi_oppc_connect_ind_handle(void *para);

static MMI_BOOL mmi_oppc_is_Jar_file(U16 *name, U16 *path);
static void mmi_opp_sending_scr_del(void);
static void mmi_oppc_send_cancel(void);
static U8 mmi_oppc_calculate_persent(void);


mmi_oppc_cntx_struct mmi_oppc_cntx;
mmi_oppc_cntx_struct *mmi_oppc_p = &mmi_oppc_cntx;

#endif /* __MMI_OPP_SUPPORT__ */ 

#define TMP_BUFF_SIZE   (192)
static WCHAR tmp_buff[TMP_BUFF_SIZE];  /* for file name buffer */

btsend_context_struct g_btsend_cntx;


static MMI_BOOL MMIOPP_FLAG_IS_ON(U32 a)
{
	return ((mmi_oppc_p->flag) & a);

}
static void MMIOPP_SET_FLAG(U32 a)
{
	(mmi_oppc_p->flag) |= a;
}
static void MMIOPP_RESET_FLAG(U32 a)
{
	(mmi_oppc_p->flag) &= ~a;

}

#ifdef __MMI_BT_APK_SMART_INSTALL_SUPPORT__
static void mmi_oppc_connect_ind_handle_for_smart_install(void *para);

static void mmi_oppc_send_ind_handle_for_smart_install(void* para);
#endif
/*****************************************************************************
 * FUNCTION
 *  cui_bt_send_create
 * DESCRIPTION
 *  This function is to create bt send cui
 * PARAMETERS
 *  parent_id [IN]
 * RETURNS
 *  mmi_id
 *****************************************************************************/
MMI_ID cui_bt_sending_create(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gid = mmi_frm_group_create(
        parent_id, GRP_ID_AUTO_GEN, 
        btsend_group_proc, 0);
    
    mmi_frm_group_set_proc_data(gid, btsend_group_proc, (void*)gid);
    
    return gid;
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_send_run
 * DESCRIPTION
 *  This function is to run bt send cui
 * PARAMETERS
 *  id [IN]
 *  para [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_sending_run(MMI_ID id, const cui_bt_sending_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    btsend_inst_struct *inst;
    btsend_device_struct dev;
    cui_bt_sending_evt_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_SENDING_CUI_RUN);
	
    mmi_frm_group_enter(id, MMI_FRM_NODE_NONE_FLAG);
    
    inst = &g_btsend_cntx.inst;
    
    if (inst->state != BTSEND_STATE_NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_SENDING_CUI_RUN_FAIL);
        /* Must be re-entry case */
        mmi_btsend_popup(NULL, BTSEND_COD_FORBIDDEN, MMI_FALSE);
        /* post DONE event */
        MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_BT_SENDING_DONE, id);
        mmi_frm_group_post_to_caller(id, (mmi_group_event_struct * )&evt);
        return;
    }
    
    inst->state = BTSEND_STATE_PREPARE;
    inst->gid = id;

    btsend_save_userdata(inst, para);
    btsend_init(inst);

    if (!srv_oppc_is_idle())
    {
        btsend_result_hdlr(inst, BTSEND_COD_SERV_NOT_AVAILABLE);
        return;
    }
    
    if (CUI_BT_SENDIND_OPT_SPECIFIC_DEVICE == para->option)
    {
        dev.lap = para->addr.lap;
        dev.nap = para->addr.nap;
        dev.uap = para->addr.uap;
        btsend_to_device(inst, &dev);
    }
    else
    {
#ifdef __MMI_BT_DEF_SEND_DEVICE__
        if (SEND_TO_DEFAULT())
            mmi_btsend_confirm_to_default();
        else
#endif
            btsend_select_device(inst, (U8)para->option);
    }

}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_sending_continue
 * DESCRIPTION
 *  This function is to send next object
 * PARAMETERS
 *  id [IN]
 *  obj   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_sending_continue(MMI_ID id, const cui_bt_sending_obj_struct *obj)
{
#ifdef __MMI_OPP_SUPPORT__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    btsend_inst_struct *inst;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_SENDING_CUI_CONTINUE, id);
    inst = &g_btsend_cntx.inst;
    
    MMI_ASSERT(inst->gid == id);
//    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_OBEX_BTSEND_OBJ, inst);
    if (obj == NULL)
    {
        if (inst->obj.total > 1)
        {
            srv_oppc_send_end(mmi_oppc_p->srv_hd);
        }
        return;
    }
    switch (inst->state)
    {
        case BTSEND_STATE_NULL:
        case BTSEND_STATE_PREPARE:
        case BTSEND_STATE_SENDING:
            MMI_ASSERT(0);
            break;

        case BTSEND_STATE_READY:
            btsend_save_obj(inst, obj);
            btsend_post_message(inst, id);
            break;
        default:
            break;
    }
#endif

}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_sending_close
 * DESCRIPTION
 *  This function is to close sending cui
 * PARAMETERS
 *  id [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_sending_close(MMI_ID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    btsend_inst_struct *inst;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_SENDING_CUI_CLOSE, id);
    inst = &g_btsend_cntx.inst;
    
    if (inst->gid != id)
    {
        if(id != GRP_ID_INVALID)
        {
            mmi_frm_group_close(id);
        }
        return;
    }
    if (inst->state >= BTSEND_STATE_READY)
    {
        mmi_btsend_popup(inst, BTSEND_COD_DONE, MMI_TRUE);
        inst->state = BTSEND_STATE_END;
        mmi_opp_sending_scr_del();
        return;
    }
   
#ifdef __MMI_BT_AUTO_POWER_SWITCH__
    /* we have to do power off when automatic power on has been activated */
    mmi_bt_auto_off(SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID);
#endif

    if (inst->gid != GRP_ID_INVALID)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_SENDING_CUI_GROUP_CLOSE, inst->gid);
        mmi_frm_group_close(inst->gid);
        inst->gid = GRP_ID_INVALID;
    }
    inst->state = BTSEND_STATE_NULL;

}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_sending_launch
 * DESCRIPTION
 *  This function is to send single file
 * PARAMETERS
 *  para [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_sending_launch(MMI_ID parent_id, const cui_bt_sending_para_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_id;
    cui_bt_sending_para_struct *data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_btsend_cntx.launch_flag = 0;
    data = (cui_bt_sending_para_struct *)para;
    cui_id = cui_bt_sending_create(parent_id);
    mmi_frm_group_set_caller_proc(cui_id, cui_bt_sending_launch_proc,NULL);
    data->total = 1;
    cui_bt_sending_run(cui_id, data);
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_sending_launch
 * DESCRIPTION
 *  This function is to send single file
 * PARAMETERS
 *  para [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_bt_sending_launch_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_bt_sending_evt_struct *event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event = (cui_bt_sending_evt_struct *)evt;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_SENDING_CUI_LAUNCH_PROC, event->evt_id);
    switch (event->evt_id)
    {
        case EVT_ID_CUI_BT_SENDING_DONE:
            if (g_btsend_cntx.launch_flag == 1)
            {
                event->evt_id = EVT_ID_CUI_BT_SENDING_SUCC;
            }
            else
            {
                event->evt_id = EVT_ID_CUI_BT_SENDING_FAIL;
            }            
            mmi_frm_group_send_to_parent(event->sender_id, (mmi_group_event_struct * )event);
            cui_bt_sending_close(event->sender_id);
            break;
        case EVT_ID_CUI_BT_SENDING_SUCC:
            g_btsend_cntx.launch_flag = 1;
            break;
        case EVT_ID_CUI_BT_SENDING_FAIL:
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}


static void btsend_sel_device_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    btsend_inst_struct *inst = &g_btsend_cntx.inst;
    cui_event_bt_cm_device_select_result_struct *sel = 
        (cui_event_bt_cm_device_select_result_struct *)evt;
    btsend_device_struct device;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_SENDING_CUI_SEL_DEVICE_HDLR);
    if (inst->hd_dev != sel->gid)
        return;
    
    inst->hd_dev = GRP_ID_INVALID;
    
    if (sel->result)
    {
        device.lap = sel->lap;
        device.uap = sel->uap;
        device.nap = sel->nap;
        btsend_to_device(inst, &device);
    }
    else
    {
        btsend_result_hdlr(inst, BTSEND_COD_USER_ABORT);
    }
    cui_bt_device_select_screen_close(sel->gid);
}


static void btsend_set_default_hdlr(mmi_event_struct *evt)
{
#ifdef __MMI_BT_DEF_SEND_DEVICE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_bt_cm_set_default_device_result_struct *set = 
        (cui_event_bt_cm_set_default_device_result_struct *)evt;
    btsend_inst_struct *inst = &g_btsend_cntx.inst;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (set->result)
    {
        btsend_device_struct dev;
        srv_bt_cm_bt_addr addr;
        addr.lap = set->lap;
        addr.uap = set->uap;
        addr.nap = set->nap;

#ifdef __MMI_BT_AUTHORIZE__
        if (srv_bt_cm_dev_property_check(&addr, SRV_BT_CM_DEV_PROPERTY_BLOCK))
        {
            mmi_btsend_popup(inst, BTSEND_COD_DEVICE_BLOCKED, MMI_TRUE);
            return;
        }
#endif
        dev.lap = set->lap;
        dev.uap = set->uap;
        dev.nap = set->nap;
        dev.prof = BTSEND_PROF_OPP;
        btsend_save_defdev(inst, &dev);
        cui_bt_device_select_screen_set_default_device(
            set->gid, set->lap, set->uap, set->nap);
    }
    else
    {
        btsend_clear_defdev(inst);
        cui_bt_device_select_screen_set_default_device(
            set->gid, 0, 0, 0);
    }
#endif    
}

static void btsend_power_on_hdlr(mmi_event_struct *evt)
{
#ifdef __MMI_BT_DEF_SEND_DEVICE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    btsend_inst_struct *inst = &g_btsend_cntx.inst;
    cui_event_bt_cm_power_on_result_struct *on = 
        (cui_event_bt_cm_power_on_result_struct*)evt;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inst->hd_pwr != on->gid)
        return;
    
    inst->hd_pwr = GRP_ID_INVALID;

    if (on->result)
    {
        g_btsend_cntx.flag |= BTSEND_PWR_ON;
        btsend_to_device(inst, &inst->def_dev);
    }
    else
    {
        btsend_result_hdlr(inst, BTSEND_COD_USER_ABORT);
    }
    cui_bt_power_on_close(on->gid);
#endif
}

static void btsend_continue_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    btsend_inst_struct *inst = &g_btsend_cntx.inst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inst->state != BTSEND_STATE_READY)
        return;
    
    inst->state = BTSEND_STATE_SENDING;
    btsend_continue(inst);
}


static mmi_ret btsend_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    btsend_inst_struct *inst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BT_SENDING_GROUP_PROC, evt->user_data, evt->evt_id);
    inst = &g_btsend_cntx.inst;
    if (inst->gid != (U32)evt->user_data)
    {
        return MMI_RET_OK;
    }

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            mmi_opp_sending_scr_del();
            if (inst->hd_dev != GRP_ID_INVALID ||
                inst->hd_pwr != GRP_ID_INVALID)
            {
                if (inst->hd_dev != GRP_ID_INVALID)
                {
                    cui_bt_device_select_screen_close(inst->hd_dev);
                    inst->hd_dev = GRP_ID_INVALID;
                }
                if (inst->hd_pwr != GRP_ID_INVALID)
                {
                    cui_bt_power_on_close(inst->hd_pwr);
                    inst->hd_pwr = GRP_ID_INVALID;
                }
                /* To avoid close group in DEINIT process */

            }
            inst->gid = GRP_ID_INVALID;
            if (inst->state <= BTSEND_STATE_PREPARE)
            {
                btsend_result_hdlr(inst, BTSEND_COD_USER_ABORT);
            }
            break;

        case EVT_ID_CUI_BT_CM_DEVICE_SELECT:
            btsend_sel_device_hdlr(evt);
            break;

        case EVT_ID_CUI_BT_CM_DEFAULT_DEVICE:
            btsend_set_default_hdlr(evt);
            break;
            
        case EVT_ID_CUI_BT_CM_POWER_ON_RESULT:
            btsend_power_on_hdlr(evt);
            break;

        case EVT_ID_BTSEND_CONTINUE:
            btsend_continue_hdlr(evt);
            break;
    }

    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  btsend_result_hdlr
 * DESCRIPTION
 *  This function is the default callback function for BT sending
 * PARAMETERS
 *  result [IN]
 *  para [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void btsend_result_hdlr(btsend_inst_struct *inst, U32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 evt_id;
    cui_bt_sending_evt_struct evt;
    MMI_BOOL abnormal_end = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_OBEX_BTSEND_APPCALLBACK, result, inst);
    
    /* We are not currently in Sending */
    if (inst == NULL)
    {
        return;
    }

    switch (result)
    {
        case BTSEND_COD_SUCCESS:
            inst->obj.sent++;
            evt_id = EVT_ID_CUI_BT_SENDING_SUCC;
            inst->state = BTSEND_STATE_READY;
            break;
        case BTSEND_COD_FAIL:
        case BTSEND_COD_BAD_OBJECT:
        case BTSEND_COD_DRM_PROHIB:
            evt_id = EVT_ID_CUI_BT_SENDING_FAIL;
            inst->state = BTSEND_STATE_READY;
            break;
        case BTSEND_COD_DONE:
            evt_id = EVT_ID_CUI_BT_SENDING_DONE;
            inst->state = BTSEND_STATE_NULL;
			break;
        default:
            evt_id = EVT_ID_CUI_BT_SENDING_DONE;
            abnormal_end = MMI_TRUE;
            inst->state = BTSEND_STATE_NULL;
            break;
    }
    
    
    /* We don't show popup when user abort the operation */
    if (((evt_id == EVT_ID_CUI_BT_SENDING_DONE) || (abnormal_end == MMI_TRUE))
        && (result != BTSEND_COD_USER_ABORT) && (result != BTSEND_COD_ABNORMAL_DONE))
    {
        mmi_btsend_popup(inst, result, MMI_TRUE);
    }

    MMI_FRM_INIT_GROUP_EVENT(&evt, evt_id, inst->gid);
    mmi_frm_group_post_to_caller(inst->gid, (mmi_group_event_struct *)&evt);

    if (evt_id == EVT_ID_CUI_BT_SENDING_DONE)
    {
    
#ifdef __MMI_BT_AUTO_POWER_SWITCH__
        /* we have to do power off when automatic power on has been activated */
        mmi_bt_auto_off(SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID);
#endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  btsend_obj_available
 * DESCRIPTION
 *  This function is judge whether object to be sent is valid
 * PARAMETERS
 *  obj [IN]
 * RETURNS
 *  U32
 *****************************************************************************/
static U32 btsend_obj_available(btsend_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Currently we just use file based object, 
        so file path is enough to do this validation */
    U16 *file = inst->obj.ptr->data.u.file.path;
    S32 retval;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* USB check: if USB in normal mode */
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        if (srv_usb_check_path_exported((WCHAR*)file))
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_OBEX_BTSEND_USBMODE);
            return BTSEND_COD_USB_UNAVAILABLE;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    if ((retval = FS_Open(file, FS_READ_ONLY)) < FS_NO_ERROR)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_OBEX_BTSEND_BADOBJECT);
        inst->reason = retval;
        return BTSEND_COD_BAD_OBJECT;
    }
    FS_Close(retval);
    /* DRM check: if allow to forward out */
#if defined(__DRM_SUPPORT__)
    if (!DRM_interdev_movable(0, file))
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_OBEX_BTSEND_DRMFORBIDDEN);
        return BTSEND_COD_DRM_PROHIB;
    }
#endif /* defined(__DRM_SUPPORT__) */

    return BTSEND_COD_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  btsend_save_user_data
 * DESCRIPTION
 *  This function is to save user data
 * PARAMETERS
 *  inst [IN]
 *  obj [IN]
 *  app [IN]
 *  prof [IN]
 *  option [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void btsend_save_userdata(btsend_inst_struct *inst, const cui_bt_sending_para_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
    MMI_ASSERT(obj->total > 0);
    MMI_ASSERT((S8 *)obj->obj->data.u.file.path);
    
    /* Save APP data */
    inst->obj.total = obj->total;
    inst->obj.sent = 0;
    inst->obj.cur_send_cnt = 0;
    btsend_save_obj(inst, obj->obj);
    
    if (CUI_BT_SENDIND_OPT_DEFAULT_DEVICE == obj->option)
    {
#ifdef __MMI_BT_DEF_SEND_DEVICE__    
        inst->option = CUI_BT_SENDIND_OPT_DEFAULT_DEVICE;
#else
        inst->option = CUI_BT_SENDIND_OPT_NORMAL;
#endif
    }
    else
    {
        inst->option = CUI_BT_SENDIND_OPT_NORMAL;
    }

}

static void btsend_save_obj(btsend_inst_struct *inst, const cui_bt_sending_obj_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    btsend_obj_in_struct *store = &inst->obj.store;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);

    /* We do not support AP type and name assignment now */
    store->type.mime_type = 0;
    store->type.mime_subtype = 0;
    store->type.mime_string = NULL;

    store->name = NULL;

    store->data.obj_type = CUI_BT_SENDIND_USE_FILE;
    mmi_wcscpy(store->data.u.file.path, obj->data.u.file.path);

    inst->obj.ptr = store;

}


/*****************************************************************************
 * FUNCTION
 *  btsend_select_device
 * DESCRIPTION
 *  This function is to call My device
 * PARAMETERS
 *  prof [IN]
 *  option [IN]
 *  dev [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void btsend_select_device(btsend_inst_struct *inst, U8 option)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 status;
#ifdef __MMI_BT_DEF_SEND_DEVICE__
    U32 opt = CUI_BT_CM_DEVICE_SELECT_OPTION_SELECT | 
        CUI_BT_CM_DEVICE_SELECT_OPTION_SET_DEFAULT;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_AUTO_POWER_SWITCH__
    status = mmi_btsend_power_on();
    if (status == BTSEND_COD_PENDING)
    {
        return;
    }
    if (status != BTSEND_COD_SUCCESS)
    {
        btsend_result_hdlr(inst, status);
        return;
    }
#else
    status = mmi_btsend_check_power_status();
    if (BTSEND_COD_POWERFAIL == status)
    {
        btsend_result_hdlr(inst, BTSEND_COD_USER_ABORT);
        return;
    }
#endif

    inst->hd_dev = cui_bt_device_select_screen_create(inst->gid);
    if (inst->hd_dev == GRP_ID_INVALID)
    {
        btsend_result_hdlr(inst, BTSEND_COD_USER_ABORT);
        return;
    }

    cui_bt_device_select_screen_set_mask(
        inst->hd_dev, 
        MMI_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK,
        0);
    
#ifdef __MMI_BT_DEF_SEND_DEVICE__
    /* We need to retrieve default device here to 
        guarentee device has not been deleted */
    btsend_retrieve_defdev(inst, NULL);

    if (option == CUI_BT_SENDIND_OPT_DEFAULT_DEVICE) 
    {
        btsend_device_struct *device = btsend_get_default_device(inst);

        cui_bt_device_select_screen_set_option_flag(inst->hd_dev, opt);

        if (device != NULL)
        {
            cui_bt_device_select_screen_set_default_device(
                inst->hd_dev, device->lap, device->uap, device->nap);
        }
    }
#endif

    cui_bt_device_select_screen_run(inst->hd_dev);
}


static void btsend_to_device(
                btsend_inst_struct *inst, 
                btsend_device_struct *dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined( __MMI_BT_AUTHORIZE__) || defined(__BT_DIALER_SUPPORT__)
    srv_bt_cm_bt_addr addr;

	addr.lap = dev->lap;
	addr.uap = dev->uap;
	addr.nap = dev->nap;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_AUTHORIZE__
    if (srv_bt_cm_dev_property_check(&addr, SRV_BT_CM_DEV_PROPERTY_BLOCK))
    {
        btsend_result_hdlr(inst, BTSEND_COD_DEVICE_BLOCKED);
        return;
    }
#endif

    inst->prof = BTSEND_PROF_OPP;    
    inst->state = BTSEND_STATE_READY;   
#ifdef __BT_DIALER_SUPPORT__
	if (mmi_bt_dialer_app_is_connected())
	{
		if ((Custom_BTDialer_LowPower_Support() &&
			MMI_FALSE == mmi_bt_dialer_app_is_connected_ex(&addr)) || 
			(srv_bt_cm_get_linked_dev_list_idx() == 2 && 
			srv_bt_cm_is_dev_in_link_table((const srv_bt_cm_bt_addr*)&addr) == MMI_FALSE))
		{
			cui_bt_sending_evt_struct evt;
			U16 err_str_id = STR_ID_FAILED_SHARE_AS_DILAER_CONNED;
			#ifdef __MMI_BTD_BOX_UI_STYLE__
				err_str_id = STR_ID_FAILED_SHARE_AS_BTBOX_CONNED;
			#endif

			inst->state = BTSEND_STATE_NULL;
		    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_BT_SENDING_DONE, inst->gid);
        	mmi_frm_group_post_to_caller(inst->gid, (mmi_group_event_struct * )&evt);
			mmi_popup_display_simple((WCHAR*)GetString(err_str_id), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);

			return;
	}
	}
#endif
    btsend_begin(inst, dev);
}


static void btsend_init(btsend_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_btsend_cntx.flag = BTSEND_PWR_OFF;
    inst->flag = 0;
    inst->hd_dev = GRP_ID_INVALID;
    inst->hd_pwr = GRP_ID_INVALID;
    
#ifdef __MMI_BT_DEF_SEND_DEVICE__
    if (inst->option == CUI_BT_SENDIND_OPT_DEFAULT_DEVICE)
    {
        btsend_retrieve_defdev(inst, NULL);
        if (btsend_get_default_device(inst) != NULL)
        {
            inst->flag |= BTSEND_TO_DEFAULT;
        }
    }
#endif

}

/*****************************************************************************
 * FUNCTION
 *  btsend_begin
 * DESCRIPTION
 *  This function is to begin the sending job
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
static void btsend_begin(btsend_inst_struct *inst, btsend_device_struct *dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inst->state == BTSEND_STATE_END)
    {
        btsend_result_hdlr(inst, BTSEND_COD_USER_ABORT);
        return;
    }

    inst->addr.lap = dev->lap;
    inst->addr.uap = dev->uap;
    inst->addr.nap = dev->nap;

    inst->obj.cur_send_cnt += 1;
    inst->state = BTSEND_STATE_SENDING;
    mmi_oppc_send_file_to_dev(inst);

}


static void btsend_continue(btsend_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst->obj.cur_send_cnt += 1;
    mmi_oppc_send_obj(inst);
}

static void btsend_post_message(btsend_inst_struct *inst, MMI_ID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    btsend_evt_continue cont;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&cont, EVT_ID_BTSEND_CONTINUE);
    mmi_frm_post_event((mmi_event_struct *)&cont, btsend_group_proc, (void*)id);
}


#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  btsend_is_last_obj
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL btsend_is_last_obj(btsend_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    
    /* btsend_callback callback; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inst->obj.total - inst->obj.cur_send_cnt > 0)
    {
        result = MMI_FALSE;
        return result;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_send_get_file_name_ext
 * DESCRIPTION
 *  this func to get file name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 *mmi_send_get_file_name_ext(U16 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 len = (U16) mmi_wcslen(name);
    U16 *tname = name;
    U16 deter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    deter = '\\';

    while (len > 0)
    {
        len--;
        /* This is a Byte Order dependency algorithm
           need to guarantee name is Little Endian */
        if (tname[len] == deter)
        {
            break;
        }
    }

    if (len == 0)
    {
        return name;
    }

    return &tname[len + 1];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_sending_fmgr_notify_hdlr
 * DESCRIPTION
 *  this func will be called when memory card plug out
 * PARAMETERS
 *  mmi_event_struct
 * RETURNS
 *  MMI_RET
 *****************************************************************************/
MMI_RET mmi_bt_sending_fmgr_notify_hdlr(mmi_event_struct *param)
{
    srv_fmgr_notification_dev_plug_event_struct* event;
    btsend_inst_struct *inst = &g_btsend_cntx.inst;
    U32 i;
    U8 drive;
    
    switch(param->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
            event = (srv_fmgr_notification_dev_plug_event_struct*)param;
            drive = inst->obj.ptr->data.u.file.path[0];
            for (i = 0; i < event->count; i++)
            {
                if (event->drv_letters[i] == drive)
                {
                    mmi_frm_group_close(inst->gid);
                    inst->gid = GRP_ID_INVALID;
                    return MMI_RET_OK;
                }
            }
            break;
    }
    return MMI_RET_OK;
}


#ifdef __MMI_BT_DEF_SEND_DEVICE__

/*****************************************************************************
 * FUNCTION
 *  btsend_retrieve_defdev
 * DESCRIPTION
 *  This function is to retrieve default device
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void btsend_retrieve_defdev(
                btsend_inst_struct *inst,
                btsend_device_struct *dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = NVRAM_READ_SUCCESS;
    btsend_device_struct *def_dev;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(inst || dev);

    if (inst)
        def_dev = &inst->def_dev;
    else
        def_dev = dev;
    
    ReadRecord(NVRAM_EF_BT_DEFDEVICE_LID, 1,
        (void *)def_dev, NVRAM_EF_BT_DEFDEVICE_SIZE, &error);
    if (error == NVRAM_READ_SUCCESS)
    {
        if (def_dev->app > APP_DEFAULT_END)
        {
            /* Invalid record */
            memset(def_dev, 0, sizeof(*def_dev));
            btsend_delete_defdev();
        }
    }
    else
    {
        memset(def_dev, 0, sizeof(*def_dev));
    }
}

/*****************************************************************************
 * FUNCTION
 *  btsend_save_defdev
 * DESCRIPTION
 *  This function is to save default device
 * PARAMETERS
 *  dev [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void btsend_save_defdev(btsend_inst_struct *inst, btsend_device_struct *dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    btsend_device_struct *def_dev;
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inst != NULL)
    {
        def_dev = &inst->def_dev;
        def_dev->lap = dev->lap;
        def_dev->uap = dev->uap;
        def_dev->nap = dev->nap;
        def_dev->prof = dev->prof;
        WriteRecord(NVRAM_EF_BT_DEFDEVICE_LID, 1, (void *)def_dev, sizeof(*dev), &error);
    }
}

/*****************************************************************************
 * FUNCTION
 *  btsend_clear_defdev
 * DESCRIPTION
 *  This function is to clear default device setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void btsend_clear_defdev(btsend_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    btsend_device_struct *dev = &inst->def_dev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(dev, 0, sizeof(*dev));
    btsend_save_defdev(inst, dev);
}


static void btsend_delete_defdev(void)
{
    btsend_device_struct dev;
    S16 error;

    memset(&dev, 0, sizeof(dev));

    WriteRecord(NVRAM_EF_BT_DEFDEVICE_LID, 1, (void *)&dev, sizeof(dev), &error);
}


/*****************************************************************************
 * FUNCTION
 *  btsend_get_default_device
 * DESCRIPTION
 *  This function is to get default device
 * PARAMETERS
 *  void
 * RETURNS
 *  btsend_device_struct *
 *****************************************************************************/
btsend_device_struct * btsend_get_default_device(btsend_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    btsend_device_struct *dev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inst == NULL)
        return NULL;

    dev = &inst->def_dev;
    if (dev->lap == 0 && dev->nap == 0 && dev->uap == 0)
    {
        return NULL;
    }

    return dev;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_btsend_delete_device_callback
 * DESCRIPTION
 *  This function is the callback of CM delete device
 * PARAMETERS
 *  dev [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_btsend_delete_device_callback(void* dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    btsend_device_struct def_dev;
    srv_bt_cm_bt_addr *addr = (srv_bt_cm_bt_addr *)dev;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dev == NULL)
    {
        btsend_delete_defdev();
    }
    else
    {
        btsend_retrieve_defdev(NULL, &def_dev);
        if (def_dev.lap == addr->lap &&
            def_dev.uap == addr->uap &&
            def_dev.nap == addr->nap)
        {
            btsend_delete_defdev();
        }
    }
}

#endif /*__MMI_BT_DEF_SEND_DEVICE__*/


#define MMI_BT_SEND_SCREEN


/*****************************************************************************
 * FUNCTION
 *  mmi_btsend_popup
 * DESCRIPTION
 *  This function is used to 
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_btsend_popup(btsend_inst_struct *inst, U32 result, MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 strID;
    U16 *string = NULL, *tbuff = NULL;
    mmi_event_notify_enum popup_class;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_OBEX_BTSEND_POPUP, result);

#ifdef __USB_IN_NORMAL_MODE__
    if (result == BTSEND_COD_USB_UNAVAILABLE)
    {
        mmi_btsend_display_popup(inst,
            (UI_string_type)GetString(STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE), MMI_EVENT_FAILURE);
        return;
    }
#endif
#ifdef __MMI_BT_AUTHORIZE__
    if (result == BTSEND_COD_DEVICE_BLOCKED)
    {
        mmi_btsend_display_popup(inst,
            (UI_string_type)GetString(STR_BT_DEVICE_BLOCKED), MMI_EVENT_FAILURE);
        return;
    }
#endif
    if (inst == NULL)
    {
        popup_class = MMI_EVENT_FAILURE;
    }
    else if (inst->obj.total == 1)
    {
        if (inst->obj.sent == 1)
        {
            popup_class = MMI_EVENT_SUCCESS;
        }
        else
        {
            popup_class = MMI_EVENT_FAILURE;
        }
    }
    else
    {
        if (inst->obj.sent == inst->obj.total)
        {
            string = (U16 *)GetString(STR_BT_SEND_ALL_SENT);
            popup_class = MMI_EVENT_SUCCESS;
        }
        else if (inst->obj.sent > 0)
        {
            popup_class = MMI_EVENT_SUCCESS;
            tbuff = (U16 *)get_ctrl_buffer(MAX_TBUFF_SIZE);
            if (inst->obj.sent == 1)
            {
                kal_wsprintf(tbuff, "%d %w", 
                    inst->obj.sent, 
                    (U16 *)GetString(STR_BT_SEND_PARTIAL_1));
            }
            else
            {
                kal_wsprintf(tbuff, "%d %w", 
                    inst->obj.sent, 
                    (U16 *)GetString(STR_BT_SEND_PARTIAL));
            }
            string = tbuff;
        }
        else
        {
            popup_class = MMI_EVENT_FAILURE;
        }
    }        
    
    switch (result)
    {
    case BTSEND_COD_DONE:
			strID = STR_GLOBAL_DONE;
            if (inst->obj.sent < inst->obj.total)
            {
                strID = STR_GLOBAL_UNFINISHED;
            }
        break;

    case BTSEND_COD_SERV_NOT_AVAILABLE:
			strID = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
        break;

    case BTSEND_COD_FORBIDDEN:
    case BTSEND_COD_BUSY:
			strID = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
        break;

    case BTSEND_COD_BAD_OBJECT:
			strID = srv_fmgr_fs_error_get_string(inst->reason);
        break;
#ifdef __MMI_OPP_SUPPORT__

    case BTSEND_COD_UNSUPPORT_FILE_TYPE:
			strID = STR_OPP_UNSUPPORT_FILE_TYPE;
        break;
#endif
#ifdef __DRM_SUPPORT__
    case BTSEND_COD_DRM_PROHIB:
			strID = STR_GLOBAL_DRM_PROHIBITED;
        break;
#endif        
        
    case BTSEND_COD_FAIL:
    default:
			strID = STR_GLOBAL_UNFINISHED;
        break;
    }

    if (string == NULL)
    {
        string = (U16 *)GetString(strID);
    }

     mmi_btsend_display_popup(inst,
            (UI_string_type)string, popup_class);

	if (tbuff)
	{
		free_ctrl_buffer(tbuff);
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_btsend_popup
 * DESCRIPTION
 *  This function is used to 
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_btsend_display_popup(btsend_inst_struct *inst, UI_string_type string, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inst == NULL)
    {
        mmi_popup_display(string, event_id, NULL);
    }
    else
    {
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, event_id, string);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_btsend_check_power_status
 * DESCRIPTION
 *  This function is used to 
 * PARAMETERS
 *  
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_btsend_check_power_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_power_status_enum status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = srv_bt_cm_get_power_status();
    switch (status)
    {
    case SRV_BT_CM_POWER_OFF:
        return BTSEND_COD_POWEROFF;
        
    case SRV_BT_CM_POWER_SWITCHING_ON:
    case SRV_BT_CM_POWER_SWITCHING_OFF:
        return BTSEND_COD_POWERFAIL;

    case SRV_BT_CM_POWER_ON:
        break;
    }

    return BTSEND_COD_POWERON;
}


#ifdef __MMI_BT_AUTO_POWER_SWITCH__
/*****************************************************************************
 * FUNCTION
 *  btsend_power_on_callback
 * DESCRIPTION
 *  This function is the callback when power on has been done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void btsend_power_on_callback(MMI_BOOL succ)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	btsend_inst_struct *inst = &g_btsend_cntx.inst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bt_register_power_on_callback_with_result(NULL);
    
    if (inst == NULL)
    {
        /* We are not in sending, just ignore this notify */
        return;
    }
    if (inst->gid == GRP_ID_INVALID)
    {
        return;
    }
    if (!succ)
    {
        btsend_result_hdlr(inst, BTSEND_COD_USER_ABORT);
        return;
    }

    g_btsend_cntx.flag |= BTSEND_PWR_ON;

#ifdef __MMI_BT_DEF_SEND_DEVICE__
    if (SEND_TO_DEFAULT())
    {
        btsend_to_device(inst, &inst->def_dev);
    }
    else
#endif
    {
        btsend_select_device(inst, inst->option);
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_btsend_power_on
 * DESCRIPTION
 *  This function is used to 
 * PARAMETERS
 *  
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_btsend_power_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_BT_DEF_SEND_DEVICE__) && !defined(__MMI_BT_AUTO_POWER_SWITCH__)
    /* In this case, CM will responsible for power on procedure */
    g_btsend_cntx.flag |= BTSEND_PWR_ON;
    return BTSEND_COD_SUCCESS;
#else
    U8 status, retval = BTSEND_COD_SUCCESS;
    btsend_context_struct *cntx = &g_btsend_cntx;
    
    if (cntx->flag & BTSEND_PWR_ON)
    {
        return BTSEND_COD_SUCCESS;
    }

    status = mmi_btsend_check_power_status();
    if (BTSEND_COD_POWERFAIL == status)
    {
        /* In this case, we already showed popup to notify user,
            so handle this case as User abort to avoid popup
            overlapped */
        return BTSEND_COD_USER_ABORT;
    }

    if (BTSEND_COD_POWEROFF == status)
    {
#ifdef __MMI_BT_AUTO_POWER_SWITCH__
        mmi_bt_register_power_on_callback_with_result(btsend_power_on_callback);
        if (mmi_bt_auto_on(SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID,g_btsend_cntx.inst.gid))
        {
            retval = BTSEND_COD_PENDING;
        }
        else
        {
            retval = BTSEND_COD_USER_ABORT;
        }
#elif defined __MMI_BT_DEF_SEND_DEVICE__
        if (!SEND_TO_DEFAULT())
        {
            cntx->flag |= BTSEND_PWR_ON;
            retval = BTSEND_COD_SUCCESS;
        }
        else
        {
            cntx->inst->hd_pwr = cui_bt_power_on_create(cntx->inst->gid);
            if (cntx->inst->hd_pwr == GRP_ID_INVALID)
                retval = BTSEND_COD_USER_ABORT;
            else
            {
                cui_bt_power_on_run(cntx->inst->hd_pwr);
                retval = BTSEND_COD_PENDING;
            }
        }
#endif
    }
    else
    {
        cntx->flag |= BTSEND_PWR_ON;
#ifdef __MMI_BT_AUTO_POWER_SWITCH__
        /* Even in power on status, we still need to check
            auto_on operation whether success, since in some 
            cases CM need to block this procedure */
        if (mmi_bt_auto_on(SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID,g_btsend_cntx.inst.gid))
        {
            retval = BTSEND_COD_SUCCESS;
        }
        else
        {
            retval = BTSEND_COD_USER_ABORT;
        }
#else
        retval = BTSEND_COD_SUCCESS;
#endif
    }

    return retval;

#endif /* __MMI_BT_AUTO_POWER_SWITCH__ */
}


#ifdef __MMI_BT_DEF_SEND_DEVICE__


/*****************************************************************************
 * FUNCTION
 *  mmi_btsend_confirm_to_default
 * DESCRIPTION
 *  This function is used to 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_btsend_confirm_to_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_btsend_entry_to_default_cnf();
    srv_prof_play_tone(SRV_PROF_TONE_GENERAL_TONE, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  btsend_to_default_cnf_scrn_proc
 * DESCRIPTION
 *  This function is used to 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret btsend_to_default_cnf_scrn_proc(mmi_event_struct *evt)
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
            btsend_result_hdlr(&g_btsend_cntx.inst, BTSEND_COD_USER_ABORT);
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_btsend_entry_to_default_cnf
 * DESCRIPTION
 *  This function is used to 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_btsend_entry_to_default_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_btsend_show_confirm(
        SCR_BT_SEND_CNF_TO_DEFAULT,
        mmi_btsend_compose_def_string(),
        NULL, mmi_btsend_entry_to_default_cnf);

    mmi_frm_scrn_set_leave_proc(
        g_btsend_cntx.inst.gid,
        SCR_BT_SEND_CNF_TO_DEFAULT,
        btsend_to_default_cnf_scrn_proc);

    SetLeftSoftkeyFunction(mmi_btsend_to_default_lsk_hdlr, KEY_EVENT_UP);
    ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_btsend_to_default_lsk_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_btsend_to_default_rsk_hdlr, KEY_EVENT_UP);
}


extern kal_int32 mmi_chset_utf8_to_ucs2_string(kal_uint8*, kal_int32, kal_uint8 *);

/*****************************************************************************
 * FUNCTION
 *  mmi_btsend_compose_def_string
 * DESCRIPTION
 *  This function is used to 
 * PARAMETERS
 *  
 * RETURNS
 *  UI_string_type
 *****************************************************************************/
static UI_string_type mmi_btsend_compose_def_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    btsend_device_struct *def_dev;
    S8 * name;
    srv_bt_cm_bt_addr addr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(tmp_buff, (WCHAR*)GetString(STR_BT_SEND_CNF_TO_DEFAULT));
    mmi_wcscat(tmp_buff, L"\r\n");

    len = mmi_wcslen(tmp_buff);
    len *= ENCODING_LENGTH;

    def_dev = btsend_get_default_device(&g_btsend_cntx.inst);
    MMI_ASSERT(def_dev != NULL);

    name = (S8 *)get_ctrl_buffer(BTCOMN_CNF_BUFF_SIZE);
    
    addr.lap = def_dev->lap;
    addr.uap = def_dev->uap;
    addr.nap = def_dev->nap;
    srv_bt_cm_get_dev_name(
            &addr, (U8)(sizeof(tmp_buff) - len - ENCODING_LENGTH), (U8 *)name);
    mmi_chset_utf8_to_ucs2_string((U8 *)&tmp_buff[len/ENCODING_LENGTH], 
        sizeof(tmp_buff) - len - ENCODING_LENGTH, (U8 *)name);
    free_ctrl_buffer(name);

    return (UI_string_type)tmp_buff;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_btsend_to_default_lsk_hdlr
 * DESCRIPTION
 *  This function is used to 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_btsend_to_default_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 status;
    btsend_inst_struct *inst = &g_btsend_cntx.inst;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_set_leave_proc(inst->gid, SCR_BT_SEND_CNF_TO_DEFAULT, NULL);

    status = mmi_btsend_power_on();
    if (status == BTSEND_COD_SUCCESS)
    {
        btsend_to_device(inst, &inst->def_dev);
    }
    else if (status != BTSEND_COD_PENDING)
    {
        btsend_result_hdlr(inst, status);
    }

    mmi_frm_scrn_close(inst->gid, SCR_BT_SEND_CNF_TO_DEFAULT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_btsend_to_default_rsk_hdlr
 * DESCRIPTION
 *  This function is used to 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_btsend_to_default_rsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    btsend_inst_struct *inst = &g_btsend_cntx.inst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst->flag &= (~BTSEND_TO_DEFAULT);

    btsend_select_device(inst, CUI_BT_SENDIND_OPT_DEFAULT_DEVICE);

    mmi_frm_scrn_set_leave_proc(inst->gid, SCR_BT_SEND_CNF_TO_DEFAULT, NULL);
    mmi_frm_scrn_close(inst->gid, SCR_BT_SEND_CNF_TO_DEFAULT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_btsend_show_confirm
 * DESCRIPTION
 *  This function is used to 
 * PARAMETERS
 *  scrn_id
 *  string
 *  exit_func
 *  entry_func
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_btsend_show_confirm(U16 scrn_id, UI_string_type string, FuncPtr exit_func, FuncPtr entry_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    btsend_inst_struct *inst = &g_btsend_cntx.inst;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_enter(inst->gid, scrn_id, exit_func, entry_func, MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_gui_buf(inst->gid, scrn_id);

        ShowCategory66Screen(
            STR_GLOBAL_BLUETOOTH,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            (U8 *)string,
            (U16)IMG_GLOBAL_QUESTION,
            guiBuffer);
    }
}

#endif /*__MMI_BT_DEF_SEND_DEVICE__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_send_compose_string
 * DESCRIPTION
 *  This function is to compose displaying string for viarious event
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static U16 *mmi_send_compose_string(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Use nPrintableStr to save memory */
    static U16 *string = tmp_buff;
    S32 len;
    btsend_inst_struct *inst = &g_btsend_cntx.inst;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMI_OPP_NOTIFY_ABORT:
            return (U16*) GetString(STR_GLOBAL_CANCELLING);

        case MMI_OPP_NOTIFY_PERCENT:
        {
            mmi_wcscpy(string, (WCHAR *)GetString(STR_GLOBAL_SENT));
            len = mmi_wcslen(string);
            if(inst->obj.cur_send_cnt == 0)
            {
                kal_wsprintf(
                    &string[len],
                    "(%d%c%d)\r\n%d%c",
                    inst->obj.cur_send_cnt + 1,
                    '/',
                    inst->obj.total,
                    mmi_oppc_calculate_persent(),
                    '%');
            }
            else
            {
                kal_wsprintf(
                    &string[len],
                    "(%d%c%d)\r\n%d%c",
                    inst->obj.cur_send_cnt,
                    '/',
                    inst->obj.total,
                    mmi_oppc_calculate_persent(),
                    '%');
            }
        }
            break;

        default:
            MMI_ASSERT(0);
            return NULL;
    }

    return string;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_send_update_prog_tohdlr
 * DESCRIPTION
 *  This function is the handler for showing the progress of transfer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_send_update_prog_tohdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(SCR_OPP_SENDING == mmi_frm_scrn_get_active_id())
    {
        mmi_send_compose_string(MMI_OPP_NOTIFY_PERCENT);
        cat66_update_progress_string();
        StartTimer(BT_PROG_UPDATE_TIMER, OPP_PROG_UPD_DUR, mmi_send_update_prog_tohdlr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_send_entry_sending_scr
 * DESCRIPTION
 *  This function is the handler for showing the progress of transfer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_send_entry_sending_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    btsend_inst_struct *inst = &g_btsend_cntx.inst;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_scrn_enter(inst->gid, SCR_OPP_SENDING, mmi_send_exit_sending_scr,
        mmi_send_entry_sending_scr, MMI_FRM_FULL_SCRN))
    {
        /* Show Sending screen */
        ShowCategory66Screen(
            STR_GLOBAL_SENDING,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            0,
            0,
            STR_GLOBAL_CANCEL,
            0,
            (U8*) mmi_send_compose_string(MMI_OPP_NOTIFY_PERCENT),
            mmi_get_event_based_image(MMI_EVENT_PROGRESS),
            NULL);

        /* Set Right softkey function to abort sending */
        SetRightSoftkeyFunction(mmi_send_cancel, KEY_EVENT_UP);
        mmi_frm_scrn_set_leave_proc(
            inst->gid,
            SCR_OPP_SENDING,
            mmi_send_sending_screen_proc);

        StartTimer(BT_PROG_UPDATE_TIMER, OPP_PROG_UPD_DUR, mmi_send_update_prog_tohdlr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_send_cancel
 * DESCRIPTION
 *  This is common function to abort sending object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_send_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_send_entry_cancelling_scr();
    mmi_frm_scrn_set_leave_proc(g_btsend_cntx.inst.gid, SCR_OPP_SENDING, NULL);
    mmi_oppc_send_cancel();
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_send_entry_cancelling_scr
 * DESCRIPTION
 *  This function is the handler for showing the aborting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_send_entry_cancelling_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_scrn_enter(g_btsend_cntx.inst.gid, SCR_OPP_ABORTING, NULL,
        mmi_send_entry_cancelling_scr, MMI_FRM_FULL_SCRN))
    {
        ShowCategory66Screen(
            STR_GLOBAL_CANCELLING,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            0,
            0,
            0,
            0,
            (U8*) mmi_send_compose_string(MMI_OPP_NOTIFY_ABORT),
            mmi_get_event_based_image(MMI_EVENT_PROGRESS),
            NULL);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_send_exit_sending_scr
 * DESCRIPTION
 *  This function is the exit function for the send through file manager screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_send_exit_sending_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BT_PROG_UPDATE_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_send_sending_screen_proc
 * DESCRIPTION
 *  This function is the callback funcion for deleting sending screen
 * PARAMETERS
 *  p       [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_send_sending_screen_proc(mmi_event_struct *evt)
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
            mmi_opp_sending_scr_del();
            break;
    }
    return MMI_RET_OK;
    
}

void mmi_fmgr_forward_bt_send_enabler(U16 menu_id, const WCHAR* filepath, 
                                                    const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_bt_is_to_display_bt_menu())
    {
        mmi_frm_hide_menu_item(menu_id);
        return;
    }
    
}

void mmi_fmgr_to_bt_hdlr(mmi_menu_id item_id, const WCHAR* filepath, 
                     const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id adp_grp;
    cui_bt_sending_para_struct para;
    cui_bt_sending_obj_struct obj;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&para, 0, sizeof(para));
    memset(&obj, 0, sizeof(obj));
    para.total = 1;
    #ifdef __MMI_BT_DEF_SEND_DEVICE__
    para.option = CUI_BT_SENDIND_OPT_DEFAULT_DEVICE;
    #endif
    para.obj = &obj;

    obj.data.obj_type = CUI_BT_SENDIND_USE_FILE;
    obj.data.u.file.path = (WCHAR *)filepath;
    
    adp_grp = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_dummy_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_bt_sending_launch(adp_grp, &para);
    mmi_fmgr_close_option_screen();
    
}

#ifdef __MMI_OPP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_oppc_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    MMI_OPPC_LOG(MMI_OPP_INIT); 

    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_BT_OPP,
        STR_OPP_APPNAME,
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        mmi_oppc_asm_stop_app_callback);

    mmi_oppc_p->flag = 0;
    mmi_oppc_p->srv_hd = 0;
    mmi_oppc_p->buffer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_oppc_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_opp_close(mmi_oppc_p->srv_hd);
    mmi_oppc_p->srv_hd = 0;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_send_file_to_dev
 * DESCRIPTION
 *  send file to the specified dst dev
 * PARAMETERS
 *  inst            [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_oppc_send_file_to_dev(btsend_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check if the OPC channel is already used */
    /* Add forward path compare to avoid re-entry case */
    if (APPLIB_MEM_AP_ID_BT_OPP == mmi_frm_appmem_check_prompt_screen())
    {
        btsend_result_hdlr(inst, BTSEND_COD_FORBIDDEN);
        return;
    }
    
    mmi_oppc_p->flag = 0;
    mmi_oppc_p->inst = inst;

    if (inst->obj.total > 1)
    {
        MMIOPP_SET_FLAG(MMIOPP_MASK_MULTI_SEND);
    }
//    MMI_OPPC_LOG(MMI_OPP_SEND_FILE_TO_DEV); 

    mmi_oppc_pre_send(inst->addr);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_send_obj
 * DESCRIPTION
 *  This function is to send object by OPP
 * PARAMETERS
 *  inst        [IN]              
 * RETURNS
 *  MMI_OPP_SND_ERR_TYPE(?)(?)
 *****************************************************************************/
static void mmi_oppc_send_obj(btsend_inst_struct *inst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *name;
    U16 *obj_name;
    U16 *path;
    U32 retval;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retval = btsend_obj_available(inst);
    if (retval != BTSEND_COD_SUCCESS)
    {
        if (btsend_is_last_obj(inst))
        {
            srv_oppc_send_end(mmi_oppc_p->srv_hd);
        }
        if ((retval == BTSEND_COD_USB_UNAVAILABLE) && (inst->obj.total == 1))
            MMIOPP_SET_FLAG(MMIOPP_MASK_ABORT_PRESS);
        btsend_result_hdlr(inst, retval);
        return;
    }

    path = inst->obj.ptr->data.u.file.path;
    MMI_ASSERT(path);
    mmi_oppc_p->inst = inst;

    obj_name = OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);
        
    /* get obj name */
    name = mmi_send_get_file_name_ext(path);

    mmi_wcscpy(obj_name, name);

    if (MMIOPP_FLAG_IS_ON(MMIOPP_MASK_SDP_FORMAT))
    {
        if (mmi_oppc_is_Jar_file(obj_name, path))
        {
            if (btsend_is_last_obj(inst))
            {
                srv_oppc_send_end(mmi_oppc_p->srv_hd);
                MMIOPP_SET_FLAG(MMIOPP_MASK_FILE_TYPE);
            }
            
            OslMfree(obj_name);
            btsend_result_hdlr(inst, BTSEND_COD_FAIL);
            return;
        }
    }

    srv_oppc_send_obj(mmi_oppc_p->srv_hd, path, obj_name);
    OslMfree(obj_name);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_alloc_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static U8 *mmi_oppc_alloc_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPPC_LOG(MMI_OPP_ALLOC_BUFF);
    mmi_oppc_p->buffer = (U8*) applib_mem_ap_alloc(APPLIB_MEM_AP_ID_BT_OPP, OPPC_MAX_OBEX_PACKET_LENGTH);

    if (mmi_oppc_p->buffer == NULL)
    {
        mmi_frm_appmem_prompt_to_release_mem(
            APPLIB_MEM_AP_ID_BT_OPP,
            0,
            OPPC_MAX_OBEX_PACKET_LENGTH,
            mmi_oppc_asm_alloc_callback);

        mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_BT_OPP, mmi_oppc_asm_not_alloc_callback);

    }

    return mmi_oppc_p->buffer;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_free_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_oppc_free_buffer(U8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer)
    {
        MMI_OPPC_LOG(MMI_OPP_FREE_BUFF);

        applib_mem_ap_free(buffer);

        if (MMIOPP_FLAG_IS_ON(MMIOPP_MASK_ASMSTOP))
        {
            applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_BT_OPP, KAL_TRUE);
        }     
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_asm_alloc_callback
 * DESCRIPTION
 *  This function is to handle ASM success allocate memory event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_oppc_asm_alloc_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 result;
    //btsend_callback callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPPC_LOG(MMI_OPP_ASM_ALLOC_CALLBACK);
    mmi_oppc_pre_send(mmi_oppc_p->inst->addr);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_asm_not_alloc_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_oppc_asm_not_alloc_callback(mmi_frm_appmem_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPPC_LOG(MMI_OPP_ASM_NOT_ALLOC_CALLBACK);
    
#ifdef __MMI_BT_AUTO_POWER_SWITCH__
    mmi_bt_auto_off(SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID);
#endif 
    btsend_result_hdlr(mmi_oppc_p->inst, BTSEND_COD_USER_ABORT);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_asm_stop_app_callback
 * DESCRIPTION
 *  This function is to handle ASM stop APP event.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_oppc_asm_stop_app_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPPC_LOG(MMI_OPP_ASM_STOP_APP_CALLBACK);
    
    if (mmi_oppc_p->buffer == NULL)
    {
        applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_BT_OPP, KAL_TRUE);
        return;
    }

    MMIOPP_SET_FLAG(MMIOPP_MASK_ASMSTOP);
    srv_oppc_send_end(mmi_oppc_p->srv_hd);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_send_file_obj
 * DESCRIPTION
 *  This function is to send file object.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns(?)
 *  b(?)        [IN]            Second variable(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_opp_send_file_obj(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_event_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_hd          [IN]        
 *  event_id        [IN]        
 *  para            [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_oppc_event_handle(S32 srv_hd, U32 event_id, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opp_disconn_notify_struct *disconn_notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_hd <= 0)
        return SRV_OPP_RESULT_INVALID_HANDLE;

    if (srv_hd == mmi_oppc_p->srv_hd)
    {
        switch (event_id)
        {
            case SRV_OPP_EVENT_CONN_NOTIFY:
			#ifdef __MMI_BT_APK_SMART_INSTALL_SUPPORT__
				mmi_oppc_connect_ind_handle_for_smart_install(para);
			#endif
                mmi_oppc_connect_ind_handle(para);
                break;

            case SRV_OPP_EVENT_SND_NOTIFY:
			#ifdef __MMI_BT_APK_SMART_INSTALL_SUPPORT__
				mmi_oppc_send_ind_handle_for_smart_install(para);
			#endif
                mmi_oppc_send_ind_handle(para);
                break;

            case SRV_OPP_EVENT_DISCONN_NOTIFY:
                disconn_notify = (srv_opp_disconn_notify_struct*) para;
                mmi_bt_reject_passkey_ind(
                    disconn_notify->bt_addr.lap,
                    disconn_notify->bt_addr.uap,
                    disconn_notify->bt_addr.nap);
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
 *  mmi_oppc_send_begin
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer          [?]         [?]
 *  buf_size        [IN]        
 *  dst_dev         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
 static void mmi_oppc_pre_send(srv_bt_cm_bt_addr bt_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_oppc_p->buffer = mmi_oppc_alloc_buffer();

    if (mmi_oppc_p->buffer == NULL)
    {
        return;
    }
    result = mmi_oppc_send_begin(mmi_oppc_p->buffer, BUF_LENGTH, bt_addr);

    MMI_OPPC_LOG1(MMI_OPP_SEND_CONN_REQ, result);

    if (result < 0)
    {
        btsend_result_hdlr(mmi_oppc_p->inst, BTSEND_COD_FORBIDDEN);

        mmi_oppc_send_finish();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_send_begin
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buffer          [?]         [?]
 *  buf_size        [IN]        
 *  dst_dev         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_oppc_send_begin(U8 *buffer, U32 buf_size, srv_bt_cm_bt_addr dst_dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 event_mask;
    S32 result;

    /* MMI_BOOL conn_result; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_oppc_p->srv_hd = srv_opp_open(SRV_OPP_ROLE_CLIENT);

    if (mmi_oppc_p->srv_hd < 0)
        return SRV_OPP_RESULT_INVALID_HANDLE;

    event_mask = SRV_OPP_EVENT_CONN_NOTIFY | SRV_OPP_EVENT_SND_NOTIFY | SRV_OPP_EVENT_DISCONN_NOTIFY;

    srv_opp_set_notify(mmi_oppc_p->srv_hd, event_mask, (bt_notify) mmi_oppc_event_handle);

    result = srv_oppc_send_begin(mmi_oppc_p->srv_hd, (void*)&dst_dev, buffer, buf_size);

    if (result >= 0)
    {
        mmi_send_entry_sending_scr();
    }
    else
    {
        MMI_OPPC_LOG(MMI_OPP_PRE_SEND_FAIL);
        if (mmi_oppc_p->buffer != NULL)
        {
            mmi_oppc_free_buffer(mmi_oppc_p->buffer);
            mmi_oppc_p->buffer = NULL;
        }
    
        if (MMIOPP_FLAG_IS_ON(MMIOPP_MASK_MULTI_SEND))
        {
            MMIOPP_RESET_FLAG(MMIOPP_MASK_MULTI_SEND);
        }
    
        btsend_result_hdlr(mmi_oppc_p->inst, BTSEND_COD_FORBIDDEN);
    
            
#ifdef __MMI_BT_AUTO_POWER_SWITCH__
        mmi_bt_auto_off(SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID);
#endif 
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_send_finish
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_oppc_send_finish(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_oppc_free_buffer(mmi_oppc_p->buffer);
    mmi_oppc_p->buffer = NULL;

#ifdef __MMI_BT_AUTO_POWER_SWITCH__
    mmi_bt_auto_off(SRV_BT_CM_OBEX_OBJECT_PUSH_CLIENT_UUID);
#endif 
    srv_opp_close(mmi_oppc_p->srv_hd);

    mmi_oppc_p->srv_hd = 0;



}


/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_send_result_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_oppc_send_ind_handle(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opp_snd_notify_struct *snd_result = (srv_opp_snd_notify_struct*) para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPPC_LOG1(MMI_OPP_SEND_IND_HANDLE, snd_result->type);

    switch (snd_result->type)
    {    
        case SRV_OPP_SND_READY:
            if (snd_result->type == SRV_OPP_SND_READY)
            {
            #if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)

                if (snd_result->supported_formats != 0xFF)
                {
                    MMIOPP_SET_FLAG(MMIOPP_MASK_SDP_FORMAT);
                }
            #endif /* defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__) */ 

                mmi_oppc_send_obj(mmi_oppc_p->inst);

            }

            break;

        case SRV_OPP_SND_SUCC:
            btsend_result_hdlr(mmi_oppc_p->inst, BTSEND_COD_SUCCESS);
            if (btsend_is_last_obj(mmi_oppc_p->inst))
            {
                srv_oppc_send_end(mmi_oppc_p->srv_hd);
            }
            break;

        case SRV_OPP_SND_FAIL:
            if (btsend_is_last_obj(mmi_oppc_p->inst))
            {
                srv_oppc_send_end(mmi_oppc_p->srv_hd);
            }
            btsend_result_hdlr(mmi_oppc_p->inst, BTSEND_COD_FAIL);
            break;

        case SRV_OPP_SND_FAIL_BY_SERVER:
            srv_oppc_send_end(mmi_oppc_p->srv_hd);
            break;

        case SRV_OPP_SND_PERSENT:
            mmi_send_update_prog_tohdlr();
            break;

        case SRV_OPP_SND_DONE:

            if (MMIOPP_FLAG_IS_ON(MMIOPP_MASK_SENDING_DELE) || MMIOPP_FLAG_IS_ON(MMIOPP_MASK_USB_PLUG_IND))
            {
                /* when user press end key or plug in usb, shall not popup "unfinished" */
                btsend_result_hdlr(mmi_oppc_p->inst, BTSEND_COD_ABNORMAL_DONE);
            }
            else if (MMIOPP_FLAG_IS_ON(MMIOPP_MASK_ABORT_PRESS))
            {
                btsend_result_hdlr(mmi_oppc_p->inst, BTSEND_COD_USER_ABORT);
            }
            else
            {
                btsend_result_hdlr(mmi_oppc_p->inst, BTSEND_COD_DONE);
            }

            mmi_oppc_send_finish();

            break;

        default:
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_connect_result_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  para        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_oppc_connect_ind_handle(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opp_conn_notify_struct *conn_notify = (srv_opp_conn_notify_struct*) para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (conn_notify->type != SRV_OPP_CONN_SUCC)
    {
        if (conn_notify->type == SRV_OPP_CONN_SCO_REJECT)
        {
            /* sco link support for MT6601 */
            mmi_bt_popup_operation_not_allowed();
        }
        mmi_bt_reject_passkey_ind(
            conn_notify->bt_addr.lap,
            conn_notify->bt_addr.uap,
            conn_notify->bt_addr.nap);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_usb_plugin_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_oppc_usb_plugin_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_oppc_is_sending())
    {
        MMI_OPPC_LOG(MMI_OPP_USB_PLUG_IN);
        MMIOPP_SET_FLAG(MMIOPP_MASK_USB_PLUG_IND);
        srv_oppc_send_end(mmi_oppc_p->srv_hd);
    }
}


#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
extern kal_bool jvm_util_is_midlet_msg_file(kal_wchar *midlet_msg_path);
#endif 
/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_is_Jar_file
 * DESCRIPTION
 *  This function is to justify whether the file is midlet or dcf file
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL, if false, it is midlet or dcf file
 *****************************************************************************/
static MMI_BOOL mmi_oppc_is_Jar_file(U16 *name, U16 *path)
{
#ifndef __MMI_BT_SLIM__
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 mime_subtype;
    applib_mime_type_struct *mime_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mime_type = applib_mime_get_file_type((kal_wchar*) name);

    mime_subtype = mime_type?mime_type->mime_subtype:MIME_SUBTYPE_NONE;
    if (jvm_util_is_midlet_msg_file(path) ||
        mime_subtype == MIME_SUBTYPE_DRM_CONTENT)
    {
        MMI_OPPC_LOG1(MMI_OPP_JUSTFY_JAR_FILE, mime_subtype);

        return MMI_TRUE;
    }
    else
    {
        //return MMI_TRUE;
        return MMI_FALSE;
    }
#endif
#endif
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_sending_scr_del
 * DESCRIPTION
 *  This function is the callback funcion for deleting sending screen
 * PARAMETERS
 *  p       [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_opp_sending_scr_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == srv_oppc_is_sending())
    {
        MMIOPP_SET_FLAG(MMIOPP_MASK_SENDING_DELE);
        srv_oppc_send_end(mmi_oppc_p->srv_hd);

    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_oppc_send_cancel
 * DESCRIPTION
 *  This is common function to abort sending object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_oppc_send_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_OPPC_LOG(MMI_OPP_SEND_CANCEL);
    MMIOPP_SET_FLAG(MMIOPP_MASK_ABORT_PRESS);  
    srv_oppc_send_end(mmi_oppc_p->srv_hd);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_send_calculate_persent
 * DESCRIPTION
 *  This function is the handler for showing the progress of transfer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_oppc_calculate_persent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opp_obj_info_struct obj_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_oppc_get_obj_info(&obj_info);
    if (obj_info.total_obj_len == 0)
    {
        return 0;
    }
    return (U8) (((double)(obj_info.total_obj_len - obj_info.remain_put_len) /
                  (double)obj_info.total_obj_len) * 100.0);
}
#ifdef __MMI_BT_APK_SMART_INSTALL_SUPPORT__
#define BT_SEND_APK L"MTK_SmartDevice_V1.4.0.apk"

void mmi_oppc_connect_ind_handle_for_smart_install(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opp_conn_notify_struct *conn_notify = (srv_opp_conn_notify_struct*) para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_opps_is_idle())
		return;

	srv_oppc_handle_smart_install(MMI_TRUE,(MMI_BOOL)(conn_notify->type == SRV_OPP_CONN_SUCC));
}

void mmi_oppc_send_ind_handle_for_smart_install(void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_opp_snd_notify_struct *snd_result = (srv_opp_snd_notify_struct*) para;

	if (snd_result->type == SRV_OPP_SND_SUCC)
	{
		srv_oppc_handle_smart_install(MMI_FALSE, MMI_TRUE);
	}
}

void mmi_bt_send_smart_phone_apk(MMI_ID parent_id, srv_bt_cm_bt_addr* dev_addr)
{
	U8 drv = SRV_FMGR_CARD_DRV;
	U16 file_path[(SRV_FMGR_PATH_MAX_LEN+1)<<1] = {0};
	cui_bt_sending_para_struct para;
	cui_bt_sending_obj_struct obj;
	extern void srv_bt_cm_copy_addr(void *dest,void *src);

	kal_wsprintf(file_path,
				  "%c:\\%w",
				  drv,
				  BT_SEND_APK);

	memset(&para, 0, sizeof(cui_bt_sending_para_struct));
	memset(&obj, 0, sizeof(cui_bt_sending_obj_struct));

	obj.data.obj_type = CUI_BT_SENDIND_USE_FILE;
	obj.data.u.file.path = file_path;
	para.obj = &obj;
	
	para.option = CUI_BT_SENDIND_OPT_SPECIFIC_DEVICE;
	srv_bt_cm_copy_addr(&para.addr, dev_addr);
	kal_prompt_trace(MOD_MMI_CONN_APP, "BTMMISend:mmi_bt_send_smart_phone_apk(), launch cui, parent_id=0x%08x", parent_id);

	cui_bt_sending_launch(parent_id, &para);
}

void mmi_bt_oppc_disconn_for_smart_install(srv_bt_cm_bt_addr *dev_addr, void* cb_ptr)
{
	if(cb_ptr)
	{
		((srv_oppc_cm_cb)cb_ptr)(dev_addr, SRV_BT_CM_OPPC_CONNECTION, MMI_FALSE, MMI_FALSE, MMI_FALSE);
	}
}

void mmi_bt_oppc_conn_for_smart_install(srv_bt_cm_bt_addr *dev_addr, void* cb_ptr)
{
	U16 sp_pushed_mask;
	MMI_BOOL is_headset;
	MMI_BOOL is_dialer = srv_bt_cm_is_bt_dialer((const srv_bt_cm_bt_addr*)dev_addr);
	S32 index = srv_bt_cm_get_dev_index((const srv_bt_cm_bt_addr *)dev_addr,SRV_BT_CM_ALL_DEV);
	const srv_bt_cm_dev_struct* dev_info = srv_bt_cm_get_dev_info(dev_addr);
	is_headset = srv_bt_cm_is_headset(dev_info->cod);
	
	MMI_BT_ASSERT(index!=-1 && dev_info != NULL);


	ReadValueSlim(NVRAM_BT_OPP_PUSHED_FLAG, &sp_pushed_mask, DS_SHORT);
	kal_prompt_trace(MOD_MMI_CONN_APP, "BTMMISend: mmi_bt_send_smart_phone_apk() is_dialer[%d], is_headset[%d], push_mask[%d]",
			is_dialer, is_headset, sp_pushed_mask);

	if ((sp_pushed_mask & (1 << index)) || (is_dialer || is_headset) || srv_oppc_is_sending())
	{
		((srv_oppc_cm_cb)cb_ptr)(dev_addr, SRV_BT_CM_OPPC_CONNECTION, MMI_FALSE, MMI_TRUE, MMI_FALSE);
		return;
	}

	srv_oppc_set_conn_app_cb(cb_ptr);
	mmi_bt_send_smart_phone_apk(GRP_ID_ROOT, dev_addr);
}
#endif
#endif /*__MMI_OPP_SUPPORT__ */

#endif /*__MMI_OPP_SUPPORT__*/
#endif /*__MMI_BT_SUPPORT__*/

