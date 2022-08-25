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
 * BppMmi.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for BPP application implementation.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_BPP_SUPPORT__
#include "Drm_gprot.h"
#include "ProfilesSrvGprot.h"
#include "Conversions.h"
#include "GpioSrvGprot.h"
#include "FileMgrSrvGprot.h"

#include "MenuCuiGprot.h"
#include "InlineCuiGprot.h"
#include "AlertScreen.h"

#include "mmi_rp_app_bluetooth_def.h"
#include "BtcmSrvGprot.h"
#include "BtcmCuiGprot.h"
#include "BtMmiScrGprots.h"

#include "BppSrvGprot.h"
#include "BppCuiGprot.h"
#include "BppMmi.h"

/* kw check */
#include "MMIDataType.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "drm_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_public_api.h"
#include "BppXhtmlGprot.h"
#include "string.h"
#include "fs_type.h"
#include "fs_func.h"
#include "CommonScreensResDef.h"
#include "wgui_categories_util.h"
#include "kal_general_types.h"
#include "wgui_categories_list.h"
#include "custom_events_notify.h"
#include "wgui_categories_popup.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "GlobalConstants.h"
#include "wgui_categories.h"
#include "wgui_touch_screen.h"
#include "wgui_categories_multimedia.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_draw_manager.h"
#include "gdi_include.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "gui.h"
#include "gui_themes.h"
#include "wgui_inputs.h"
#include "fs_errcode.h"
#include "gui_typedef.h"
#include "Unicodexdcl.h"
#include "wgui_categories_inputs.h"
#include "ImeGprot.h"
#include "NotificationGprot.h"
#include "stdio.h"
/* kw check*/
#define STR_BPP_BUSY    STR_GLOBAL_CURRENTLY_NOT_AVAILABLE

#define BppValidDevice(addr)  \
            ((addr)->lap != 0 || \
             (addr)->uap != 0 || \
             (addr)->nap != 0)

#define BppSameDevice(addr1, addr2) \
            ((addr1)->lap == (addr2)->lap && \
             (addr1)->uap == (addr2)->uap && \
             (addr1)->nap == (addr2)->nap)


static bpp_mmi_cntx_struct mmi_bpp_cntx;
static bpp_mmi_cntx_struct *p_cntx = &mmi_bpp_cntx;

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 cui_bt_printing_launch(MMI_ID app_gid, U32 app_type, bt_print_data_struct *data, U32 option)
{
    bpp_inst_struct *inst;
    bpp_app_info_struct app;
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_MMI_LAUNCH, app_gid, app_type); 
    
    if (!bpp_is_ready())
        return 0;

    app.gid = app_gid;
    app.type = app_type;
    app.option = option;

    inst = bpp_new_inst(&app);
    if (!inst)
    {
        bpp_alert('std', 0, STR_BPP_BUSY, MMI_EVENT_FAILURE);
        return 0;
    }

    bpp_set_app_data(inst, data);

    if (app_type == BT_PRINT_IMAGE && data && !data->more)
    {
#ifdef __DRM_SUPPORT__
        U8 method = DRM_get_object_method(0, data->u.file);

        MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_MMI_DRM_METHOD, method);
        
        if (method == DRM_METHOD_NONE)
        {
            inst->flags |= FLAG_PREVIEW;
        }
#else
        inst->flags |= FLAG_PREVIEW;
#endif
    }

    inst->group_id = mmi_frm_group_create(app_gid, GRP_ID_BT_BPP, bpp_app_proc, inst);
    MMI_ASSERT(inst->group_id);

    mmi_frm_group_enter(inst->group_id, MMI_FRM_NODE_NONE_FLAG);

    bpp_start_app(inst);

    return (U32)inst;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bt_printing_set_data(U32 inst_hd, bt_print_data_struct *data)
{
    bpp_inst_struct *inst = (bpp_inst_struct *)inst_hd;

    if (!inst || inst->magic != BPP_MAGIC_NUMBER)
        return;

    bpp_set_app_data(inst, data);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_style_rules
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 cui_bt_printing_style_rules(U32 inst_hd, void *xhtml)
{
    bpp_inst_struct *inst = (bpp_inst_struct *)inst_hd;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_MMI_STYLE_RULE, inst); 
    
    if (!inst || inst->magic != BPP_MAGIC_NUMBER)
        return 0;

    if (!xhtml)
        return 0;

    return bpp_apply_app_style(inst, xhtml);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_get_version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
CHAR *cui_bt_printing_xhtml_version(U32 inst_hd)
{
    bpp_inst_struct *inst = (bpp_inst_struct *)inst_hd;
    PrinterAttribute attrs;

    if (!inst || inst->magic != BPP_MAGIC_NUMBER)
        return NULL;

    srv_bpp_get_info(inst->h_srv, inst->job_id, &attrs, BPP_INFO_PRINTER_ATTR);

    if (attrs.docFormat & BPP_DOC_XHTML_095)
        return XHTML_VER_095;

    return XHTML_VER_100;
}

U32 bpp_pixel_to_mm(U32 px)
{
    return (U32)((double)px * MmPerInch / DefaultPPI);
}

U32 bpp_mm_to_pixel(U32 mm)
{
    return (U32)((double)mm * DefaultPPI / MmPerInch);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bpp_app_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_app_init(void)
{
    BppSrvConfig config;

    memset(&config, 0, sizeof(config));

    config.storage = BPP_STORAGE_DRIVE;

    srv_bpp_init(&config);

#ifdef BPP_APP_DEBUG
    {
        WCHAR path[32];

        kal_wsprintf(path, "%c\\@bpp\\", SRV_FMGR_PUBLIC_DRV);
        if (FS_GetAttributes(path) < 0)
            FS_CreateDir(path);
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_conn_printer(srv_bt_cm_bt_addr bd_addr)
{
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_bpp_disc_printer(srv_bt_cm_bt_addr bd_addr, U32 g_conn_id)
{
    MMI_ID gid = mmi_frm_group_get_active_id();
    bpp_inst_struct *inst = (bpp_inst_struct *)mmi_frm_group_get_user_data(gid);
    
    if (!inst || inst->magic != BPP_MAGIC_NUMBER)
        return;

    p_cntx->flags |= FLAG_DISC;
}

void mmi_bt_bpp_delete_device_callback(const srv_bt_cm_bt_addr *bt_addr)
{
    BppHandle h_srv;
    U32 job_id;

    h_srv = srv_bpp_open(BPP_MODE_RDWRITE);
    if (!h_srv)
        return;

    if (srv_bpp_list(h_srv, 0, &job_id, 1))
    {
        PrinterAddr addr;
        srv_bpp_get_info(h_srv, job_id, &addr, BPP_INFO_PRINTER_ADDR);

        if ((bt_addr && BppSameDevice(&addr, bt_addr)) || !bt_addr)
            srv_bpp_delete(h_srv, job_id);
    }
    srv_bpp_close(h_srv);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET bpp_app_proc(mmi_event_struct *evt)
{
    bpp_inst_struct *inst = (bpp_inst_struct *)evt->user_data;
    
    switch (evt->evt_id) {
    OnGroupEvents:
        bpp_group_event_hdlr(inst, evt);
        break;

    OnMenuEvents:
        bpp_menu_event_hdlr(inst, (mmi_group_event_struct *)evt);
        break;

    OnCuiEvents:
        bpp_cui_event_hdlr(inst, (mmi_group_event_struct *)evt);
        break;

    OnInlineEvents:
        bpp_setting_event_hdlr(inst, (mmi_group_event_struct *)evt);
        break;

    OnAlertEvents:
        bpp_alert_event_hdlr(inst, (mmi_alert_result_evt_struct *)evt);
        break;

    default:
        break;
    }

    return MMI_RET_OK;
}

static MMI_RET bpp_data_helper_proc(evt_bpp_data_helper *evt)
{
    bpp_inst_struct *inst = (bpp_inst_struct *)evt->user_data;
    bt_print_data_struct data;
    S32 retval = E_OK;

    MMI_ASSERT(inst && inst->magic == BPP_MAGIC_NUMBER);

    if (evt->evt_id != EVT_BPP_DATA_HELPER)
        return MMI_RET_OK;

    data.u.file = evt->storage;

    switch (inst->app.data.content_type) {
    case BT_PRINT_CONTENT_IMAGE:
        retval = bpp_compose_image(inst, &data);
        break;

    case BT_PRINT_CONTENT_TEXT_PLAIN:
        retval = bpp_compose_text(inst, &data);
        break;

    default:
        retval = E_FAIL;
        break;
    }

    if (retval == E_OK)
        bpp_set_app_data(inst, &data);
    else
        bpp_set_app_data(inst, NULL);

    bpp_accept_data_req(inst);

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 bpp_srv_notify_hdlr(BppHandle h_srv, U32 notify, U32 para)
{
    bpp_inst_struct *inst = bpp_find_inst(h_srv);
    U32 job_id = para & 0xFFFF;
    
    para = para >> 16;

    if (!inst || job_id != inst->job_id) return 0;

    switch (notify) {
    case BPP_EV_JOB_UPDATE:
        
        if (para & BPP_INFO_PRINTER_ATTR)
            bpp_update_attr_hdlr(inst, E_OK);

        break;

    case BPP_EV_UPDATE_FAIL:

        bpp_update_attr_hdlr(inst, bpp_conv_result(para));

        break;

    case BPP_EV_JOB_START_REQ:

        bpp_job_start_hdlr(inst, para);

        break;

    case BPP_EV_JOB_REQUEST:

        if (para == BPP_REQUEST_DATA)
            bpp_data_req_hdlr(inst);
        else if (para == BPP_REQUEST_AUTH)
            bpp_show_auth(inst);

        break;

    case BPP_EV_JOB_PROGRESS:

        bpp_update_prog_info(inst, (U16)para);
        
        break;

    case BPP_EV_JOB_STATUS:

        bpp_job_status_hdlr(inst, para);

        break;

    case BPP_EV_JOB_FINISH:

        bpp_job_finish_hdlr(inst, bpp_conv_result(para));

        break;

    default:
        break;
    }

    return 0;
}

static S32 bpp_bearer_notify_hdlr(BppHandle h_srv, U32 notify, U32 para)
{
    U32 status = (para >> 16 & 0xffff);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_MMI_BEARER, p_cntx->flags, p_cntx->inst);
    
    switch (status) {
    case BPP_BEARER_UP:

        break;

    case BPP_BEARER_DOWN:

        if (p_cntx->flags & FLAG_DISC)
        {
            p_cntx->flags &= ~FLAG_DISC;
        }
        
    case BPP_BEARER_FAIL:

        srv_bpp_close(h_srv);
        if (h_srv == p_cntx->h_bearer)
            p_cntx->h_bearer = 0;
#ifdef __MMI_BT_AUTO_POWER_SWITCH__
        if (p_cntx->flags & FLAG_AUTO_ON && !p_cntx->inst)
        {
            mmi_bt_auto_off(SRV_BT_CM_BASIC_PRINTING);
            p_cntx->flags &= ~FLAG_AUTO_ON;
        }
#endif    

        break;
    }

    return 0;
}

static void bpp_cm_notify_hdlr(U32 event, void *para)
{
    srv_bt_cm_begin_deactivate_struct *arg = (srv_bt_cm_begin_deactivate_struct *)para;

    if (p_cntx->inst && (bpp_inst_struct *)(arg->user_data) == p_cntx->inst)
        bpp_stop_app(p_cntx->inst, E_ABORT);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_group_event_hdlr(bpp_inst_struct *inst, mmi_event_struct *evt)
{
    switch (evt->evt_id) {
    case EVT_ID_GROUP_ENTER:
        
        //bpp_start_app(inst);
        
        break;

    case EVT_ID_POST_CB_RST:

        bpp_event_result_hdlr(inst, (mmi_post_result_event_struct *)evt);

        break;
    case EVT_ID_GROUP_GOBACK:
    case EVT_ID_GROUP_DELETE_REQ:
        inst->flags |= FLAG_SELF_CLOSE;
        break;
    case EVT_ID_GROUP_GOBACK_IN_END_KEY:
    case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        inst->flags &= ~FLAG_SELF_CLOSE;
        break;

    case EVT_ID_GROUP_DEINIT:

        if (inst == p_cntx->inst)
        {
            inst->group_id = 0;
            if (inst->flags & FLAG_SELF_CLOSE)
                bpp_stop_app(inst, E_FAIL);
            else
                bpp_stop_app(inst, E_ABORT);
        }

        break;

    default:
        break;
    }
}

static void bpp_event_result_hdlr(bpp_inst_struct *inst, mmi_post_result_event_struct *evt)
{
    if (evt->evt_p->evt_id != EVT_BT_PRINT_DATA_REQ)
        return;

    if (inst->app.data.type != 'none' &&
        inst->app.data.content_type != BT_PRINT_CONTENT_XHTML)
        bpp_data_helper(inst);
    else
        bpp_accept_data_req(inst);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_menu_event_hdlr(bpp_inst_struct *inst, mmi_group_event_struct *evt)
{
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;

    switch ((U32)menu_evt->app_data) {
    case MENU_BPP_PREVIEW_OPTIONS:
        
        bpp_preview_menu_hdlr(inst, menu_evt);
        
        break;

    case MENU_BPP_SETTING_OPTIONS:

        bpp_setting_menu_hdlr(inst, menu_evt);

        break;

    default:
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_preview_menu_hdlr(bpp_inst_struct *inst, cui_menu_event_struct *evt)
{
    bpp_preview_struct *p = inst->preview;
    
    cui_menu_set_default_title_image(
                    evt->sender_id, 
                    get_image(GetRootTitleIcon(MENU_CONN_BT_MAIN)));
    switch (evt->evt_id) {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        
        if (bpp_zoom_enable(p, 'zin'))
            cui_menu_set_item_disabled(evt->sender_id, MENU_BPP_ZOOM_IN, MMI_FALSE);
        else
            cui_menu_set_item_disabled(evt->sender_id, MENU_BPP_ZOOM_IN, MMI_TRUE);
        
        if (bpp_zoom_enable(p, 'zout'))
            cui_menu_set_item_disabled(evt->sender_id, MENU_BPP_ZOOM_OUT, MMI_FALSE);
        else
            cui_menu_set_item_disabled(evt->sender_id, MENU_BPP_ZOOM_OUT, MMI_TRUE);
        
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
        
        switch (evt->highlighted_menu_id) {
        case MENU_BPP_PRINT:
            
            bpp_print_hdlr(inst);

            break;

        case MENU_BPP_ZOOM_IN:
            
            bpp_zoom_preview(inst, 'zin');
            cui_menu_close(evt->sender_id);
            
            break;

        case MENU_BPP_ZOOM_OUT:
            
            bpp_zoom_preview(inst, 'zout');
            cui_menu_close(evt->sender_id);

            break;

        default:
            break;
        }
        
        break;

    case EVT_ID_CUI_MENU_CLOSE_REQUEST:

        cui_menu_close(evt->sender_id);

        break;

    default:
        break;
    }

}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_setting_menu_hdlr(bpp_inst_struct *inst, cui_menu_event_struct *evt)
{
    switch (evt->evt_id) {
    case EVT_ID_CUI_MENU_LIST_ENTRY:

        bpp_init_setting_options(inst, evt->sender_id);
        
        break;

    case EVT_ID_CUI_MENU_ITEM_SELECT:
        
        switch (evt->highlighted_menu_id) {
        case MENU_BPP_PRINT:

            if (bpp_print_hdlr(inst))
                cui_inline_close(inst->cid_setting);

            break;
            
        case MENU_BPP_PREVIEW:
            
            bpp_show_preview(inst);
            
            break;
            
        case MENU_BPP_CHG_PRINTER:
            
            bpp_sel_device(inst);
            
            break;

        case MENU_BPP_GET_CAPBILITY:
            
            bpp_update_attr(inst);
            
            break;

        case MENU_BPP_SAVE_SETTING:
            
            bpp_apply_setting(inst);
            bpp_save_setting(inst);
            
            break;

        default:
            break;
        }
        
        break;

    case EVT_ID_CUI_MENU_CLOSE_REQUEST:

        cui_menu_close(evt->sender_id);

        break;

    default:
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_cui_event_hdlr(bpp_inst_struct *inst, mmi_group_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_CUI_BT_CM_POWER_ON_RESULT)
    {
        cui_event_bt_cm_power_on_result_struct * ev = 
            (cui_event_bt_cm_power_on_result_struct *)evt;
        
        bpp_power_on_hdlr(inst, ev->gid, ev->result);
    }
    else if (evt->evt_id == EVT_ID_CUI_BT_CM_DEVICE_SELECT)
    {
        cui_event_bt_cm_device_select_result_struct * ev = 
            (cui_event_bt_cm_device_select_result_struct *)evt;
        PrinterAddr addr;

        if (ev->gid != inst->cid_device)
            return;
        
        addr.lap = ev->lap;
        addr.uap = ev->uap;
        addr.nap = ev->nap;

        bpp_sel_device_hdlr(inst, ev->gid, ev->result, &addr);
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_power_on_hdlr(bpp_inst_struct *inst, MMI_ID cid, MMI_BOOL result)
{
    if (cid)
        cui_bt_power_on_close(cid);

    if (result)
        bpp_start_app(inst);
    else
        bpp_stop_app(inst, E_FAIL);

}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_sel_device_hdlr(bpp_inst_struct *inst, MMI_ID cid, MMI_BOOL result, PrinterAddr *addr)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BPP_GET_PRINTER_DONE, 
        inst, result, addr->lap, addr->uap, addr->nap);

    inst->cid_device = 0;

    if (!inst->job_id)
    {
        if (result)
        {
            inst->job_id = srv_bpp_create(inst->h_srv);
            srv_bpp_bind(inst->h_srv, inst->job_id, addr, 0);
            inst->flags |= FLAG_NEW_JOB;
            bpp_update_attr(inst);
        }
        else
        {
            bpp_stop_app(inst, E_FAIL);
        }
    }
    else
    {
        MMI_ASSERT(inst->setting);
        if (result)
        {
            if (BppSameDevice(addr, &inst->setting->addr))
            {
                /* Just to update printer name */
                bpp_fill_setting_items(inst->cid_setting, inst->setting);
            }
            else
            {
                srv_bpp_bind(inst->h_srv, inst->job_id, addr, 0);
                srv_bpp_set_option(inst->h_srv, inst->job_id, NULL);
                bpp_update_attr(inst);
            }
        }
    }

    cui_bt_device_select_screen_close(cid);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_update_attr(bpp_inst_struct *inst)
{
    PrinterAddr addr;
    
    srv_bpp_get_info(inst->h_srv, inst->job_id, &addr, BPP_INFO_PRINTER_ADDR);

    bpp_show_progress(inst, 'get');

    if (!p_cntx->h_bearer)
        p_cntx->h_bearer = srv_bpp_open(BPP_MODE_RDONLY);
    srv_bpp_set_notify(
        p_cntx->h_bearer, bpp_bearer_notify_hdlr, BPP_EV_BEARER_INFO, BPP_EV_OP_NEW);
        
    inst->op_code = BPP_OP_GET_ATTR;
    bpp_start_operation(inst);

}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_update_attr_hdlr(bpp_inst_struct *inst, U32 result)
{
    PrintOption opt;
    
    inst->op_code = BPP_OP_NONE;

    if (result == E_OK)
        srv_bpp_set_option(inst->h_srv, inst->job_id, NULL);
    /* Walk around for NCenter power off during updating case */
    else if (srv_bt_cm_get_power_status() != SRV_BT_CM_POWER_ON)
    {
        bpp_stop_app(inst, E_ABORT);
        return;
    }
        
    srv_bpp_get_info(inst->h_srv, inst->job_id, &opt, BPP_INFO_PRINT_OPTION);
    bpp_set_page_info(inst, opt.mediaSize, opt.orientation);

    if (inst->setting)
    {
        if (result != E_OK)
            bpp_show_update_fail(inst, result);

        bpp_update_setting(inst, inst->setting);
        bpp_fill_setting_items(inst->cid_setting, inst->setting);
    }
    else
    {
        if (result == E_OK)
            bpp_show_setting(inst);
        else
            bpp_show_update_fail(inst, result);
    }

    mmi_alert_dismiss(inst->pid_getting);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_show_update_fail(bpp_inst_struct *inst, U32 result)
{
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    mmi_frm_scrn_first_enter(
        inst->group_id, 
        SCR_BPP_TROUBLE,
        (FuncPtr)bpp_trouble_enter_hdlr,
        inst);

    srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_FAILURE), NULL);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET bpp_trouble_enter_hdlr(mmi_scrn_essential_struct *info)
{
    if (!mmi_frm_scrn_enter(
            info->group_id,
            info->scrn_id,
            (FuncPtr)bpp_trouble_exit_hdlr,
            (FuncPtr)bpp_trouble_enter_hdlr,
            MMI_FRM_FULL_SCRN))
    {
        mmi_frm_scrn_set_attribute(info->group_id, info->scrn_id, MMI_SCRN_ATTRIB_SMALL_SCRN);
        return MMI_RET_ERR;
    }
    
    ShowCategory165Screen(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,        
        0, 0,
        (UI_string_type)GetString(STR_BT_BPP_POPUP_GET_ATTR_FAILED),
        mmi_get_event_based_image(MMI_EVENT_FAILURE),
        NULL);

    SetLeftSoftkeyFunction(bpp_trouble_lsk_hdlr, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(bpp_trouble_lsk_hdlr, KEY_EVENT_UP);
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET bpp_trouble_exit_hdlr(mmi_scrn_essential_struct *info)
{
    srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_FAILURE));

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_trouble_lsk_hdlr(void)
{
    MMI_ID gid = mmi_frm_group_get_active_id();
    bpp_inst_struct *inst = 
        (bpp_inst_struct *)mmi_frm_scrn_get_user_data(gid, SCR_BPP_TROUBLE);

    MMI_ASSERT(inst && inst->magic == BPP_MAGIC_NUMBER);

    if (!inst->setting)
        bpp_show_setting(inst);

    mmi_frm_scrn_close(gid, SCR_BPP_TROUBLE);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_print_doc(bpp_inst_struct *inst)
{
    PrinterAddr addr;

    srv_bpp_get_info(inst->h_srv, inst->job_id, &addr, BPP_INFO_PRINTER_ADDR);

    bpp_show_progress(inst, 'prnt');

    if (!p_cntx->h_bearer)
        p_cntx->h_bearer = srv_bpp_open(BPP_MODE_RDONLY);
    srv_bpp_set_notify(
        p_cntx->h_bearer, bpp_bearer_notify_hdlr, BPP_EV_BEARER_INFO, BPP_EV_OP_NEW);
        
    inst->op_code = BPP_OP_PRINT_DOC;
    bpp_start_operation(inst);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_start_operation(bpp_inst_struct *inst)
{
    if (inst->op_code == BPP_OP_GET_ATTR)
    {
        srv_bpp_update(inst->h_srv, inst->job_id);
    }
    else if (inst->op_code == BPP_OP_PRINT_DOC)
    {
        srv_bpp_print(inst->h_srv, inst->job_id, BPP_PRINT_MODE_ADVANCED, NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_setting_event_hdlr(bpp_inst_struct *inst, mmi_group_event_struct *evt)
{
    switch (evt->evt_id) {
    case EVT_ID_CUI_INLINE_SUBMIT:

        bpp_show_setting_options(inst);

        break;

    case EVT_ID_CUI_INLINE_CSK_PRESS:

        if (bpp_print_hdlr(inst))
        {
            cui_inline_close(inst->cid_setting);
        }

        break;

    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(bpp_setting_tap_hdlr);
#endif

        break;

    case EVT_ID_CUI_INLINE_ABORT:

        bpp_setting_abort_hdlr(inst, (cui_event_inline_abort_struct *)evt);

        break;

    case EVT_ID_CUI_INLINE_NOTIFY:

        bpp_setting_notify_hdlr(inst, (cui_event_inline_notify_struct *)evt);

        break;

    case EVT_ID_CUI_INLINE_GROUP_DEINIT:

        bpp_del_setting(inst);
        inst->setting = NULL;

        break;
        
    default:
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  bpp_setting_print_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 bpp_print_hdlr(bpp_inst_struct *inst)
{
    U32 valid;
    S32 retval = 0;

    srv_bpp_get_info(inst->h_srv, inst->job_id, &valid, BPP_INFO_PRINTER_VALID);

    if (valid)
    {
        if (inst->app.type == BT_PRINT_IMAGE &&
            !bpp_compatible_image(inst, inst->obj.type))
        {
            bpp_alert('std', 0, STR_BT_BPP_UNSUPPORT_FORMAT, MMI_EVENT_FAILURE);
            bpp_stop_app(inst, E_FAIL);
        }
        else
        {
            bpp_apply_setting(inst);
            bpp_print_doc(inst);
            retval = 0;
        }
    }
    else
        bpp_show_confirm(inst, (WCHAR *)GetString(STR_BT_BPP_SETTING_WARNING));

    return retval;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_setting_abort_hdlr(
                bpp_inst_struct *inst,
                cui_event_inline_abort_struct *evt)
{
    bpp_abort_setting(inst);

    bpp_stop_app(inst, E_CANCEL);
    
    cui_inline_close(evt->sender_id);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_setting_notify_hdlr(
                bpp_inst_struct *inst,
                cui_event_inline_notify_struct *evt)
{
    bpp_setting_struct *set = inst->setting;
    bpp_item_struct *item;
    enum {indx_copies, indx_size, indx_orien, indx_side, indx_qlty};
    
    if (evt->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
    {
        switch (evt->item_id) {
        case ITEM_ID_COPIES:
        case ITEM_ID_SIZE:
        case ITEM_ID_ORIENT:
        case ITEM_ID_SIDES:
        case ITEM_ID_QUALITY:
            item = &set->items[(evt->item_id-ITEM_ID_COPIES)/2];
            if (item->focus == (U8)evt->param)
                break;
            
            item->focus = (U8)evt->param;

            if (evt->item_id == ITEM_ID_SIZE)
                bpp_set_page_info(inst, item->values[item->focus].data, 0);
            else if (evt->item_id == ITEM_ID_ORIENT)
                bpp_set_page_info(inst, 0, (U8)item->values[item->focus].data);
                
            bpp_apply_setting(inst);

            break;

        default:
            break;
        }
    }
}

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  bpp_setting_tap_hdlr
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
void bpp_setting_tap_hdlr(mmi_tap_type_enum tap_type, S32 index)
{
    mmi_group_node_struct info;
    bpp_inst_struct *inst;
    MMI_ID gid = mmi_frm_group_get_active_id();

    mmi_frm_group_get_info(gid, &info);

    inst = (bpp_inst_struct *)mmi_frm_group_get_user_data(info.parent);

    if (inst && inst->magic == BPP_MAGIC_NUMBER)
    {
        if (index == 1 && tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
        {
            bpp_sel_device(inst);
        }
    }
}
#endif /* __MMI_FTE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_show_setting_options(bpp_inst_struct *inst)
{
    MMI_ID id_menu;

    id_menu = cui_menu_create(
                inst->group_id, 
                CUI_MENU_SRC_TYPE_RESOURCE,
                CUI_MENU_TYPE_FROM_RESOURCE,
                MENU_BPP_SETTING_OPTIONS,
                MMI_TRUE,
                (void *)MENU_BPP_SETTING_OPTIONS);

    cui_menu_run(id_menu);
}

static void bpp_init_setting_options(bpp_inst_struct *inst, MMI_ID opt_id)
{
    U32 valid;

    cui_menu_set_default_title_image(
                    opt_id, 
                    get_image(GetRootTitleIcon(MENU_CONN_BT_MAIN)));
    if (inst->flags & FLAG_PREVIEW)
    {
        cui_menu_set_item_hidden(opt_id, MENU_BPP_PREVIEW, MMI_FALSE);
        if (bpp_preview_enable(&inst->app.data))
            cui_menu_set_item_disabled(opt_id, MENU_BPP_PREVIEW, MMI_FALSE);
        else
            cui_menu_set_item_disabled(opt_id, MENU_BPP_PREVIEW, MMI_TRUE);
    }
    else
        cui_menu_set_item_hidden(opt_id, MENU_BPP_PREVIEW, MMI_TRUE);
    
    srv_bpp_get_info(inst->h_srv, inst->job_id, &valid, BPP_INFO_PRINTER_VALID);
    
    if (valid)
        cui_menu_set_item_disabled(opt_id, MENU_BPP_SAVE_SETTING, MMI_FALSE);
    else
        cui_menu_set_item_disabled(opt_id, MENU_BPP_SAVE_SETTING, MMI_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_alert_event_hdlr(bpp_inst_struct *inst, mmi_alert_result_evt_struct *evt)
{
    switch (evt->result) {
    case MMI_ALERT_CNFM_YES:

        bpp_print_doc(inst);

        break;

    case MMI_ALERT_CNFM_NO:
        
        break;

    default:
        return;
    }

    mmi_alert_dismiss(evt->alert_id);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 bpp_power_on(bpp_inst_struct *inst)
{
    S32 retval = E_OK;
    MMI_BOOL result = MMI_TRUE;
    srv_bt_cm_power_status_enum status;
    MMI_ID cid;
    
    if (!mmi_bt_is_hw_ready(MMI_TRUE))
        return E_FAIL;

    status = srv_bt_cm_get_power_status();
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BPP_POWER_ON, p_cntx->flags, status);

    switch (status) {
    case SRV_BT_CM_POWER_ON:
        
#ifdef __MMI_BT_AUTO_POWER_SWITCH__
        result = mmi_bt_auto_on(SRV_BT_CM_BASIC_PRINTING,inst->group_id);
        p_cntx->flags |= FLAG_AUTO_ON;
#endif

        break;

    case SRV_BT_CM_POWER_OFF:

#ifdef __MMI_BT_AUTO_POWER_SWITCH__
        mmi_bt_register_power_on_callback_with_result(bpp_auto_on_hdlr);
        result = mmi_bt_auto_on(SRV_BT_CM_BASIC_PRINTING,inst->group_id);
        p_cntx->flags |= FLAG_AUTO_ON;
        retval = E_PENDING;
#else
        cid = cui_bt_power_on_create(inst->group_id);
        if (!cid)
            retval = E_FAIL;
        else
        {
            cui_bt_power_on_run(cid);
            retval = E_PENDING;
        }
#endif /* __MMI_BT_AUTO_POWER_SWITCH__ */

        break;

    default:
        bpp_alert('std', 0, STR_BPP_BUSY, MMI_EVENT_FAILURE);
        retval = E_BUSY;
        break;
    }

    if (!result)
    {
        p_cntx->flags &= ~FLAG_AUTO_ON;
        retval = E_FAIL;
    }

    return retval;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_start_app(bpp_inst_struct *inst)
{
    U32 count;
    S32 retval;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_MMI_START_APP, inst); 
    
    retval = bpp_power_on(inst);
    if (retval == E_PENDING)
        return;

    if (retval != E_OK)
    {
        mmi_frm_group_close(inst->group_id);
        return;
    }

    inst->h_srv = srv_bpp_open(BPP_MODE_RDWRITE);
    if (!inst->h_srv)
    {
        bpp_alert('std', 0, STR_BPP_BUSY, MMI_EVENT_FAILURE);
        bpp_stop_app(inst, E_FAIL);

        return;
    }
    inst->h_cm_srv = srv_bt_cm_set_notify(bpp_cm_notify_hdlr, SRV_BT_CM_EVENT_BEGIN_DEACTIVATE, inst);
    
    srv_bpp_set_notify(inst->h_srv, bpp_srv_notify_hdlr, 0xFFFF, BPP_EV_OP_NEW);
    
    count = srv_bpp_list(inst->h_srv, 0, NULL, 0);

    if (count)
    {
        PrintOption opt;
        
        srv_bpp_list(inst->h_srv, 0, &inst->job_id, 1);
        
        srv_bpp_get_info(inst->h_srv, inst->job_id, &opt, BPP_INFO_PRINT_OPTION);
        bpp_set_page_info(inst, opt.mediaSize, opt.orientation);

        bpp_show_setting(inst);
    }
    else
    {
        if (bpp_sel_device(inst) != E_OK)
            bpp_stop_app(inst, E_BUSY);
    }
}

static void bpp_stop_app(bpp_inst_struct *inst, U32 result)
{
    PrinterAddr addr;
    MMI_ID gid = inst->group_id;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_MMI_STOP_APP, inst, result); 
    
#ifdef __MMI_BT_AUTO_POWER_SWITCH__
    if (p_cntx->flags & FLAG_AUTO_ON && !p_cntx->h_bearer)
    {
        mmi_bt_auto_off(SRV_BT_CM_BASIC_PRINTING);
        p_cntx->flags &= ~FLAG_AUTO_ON;
    }
#endif

    bpp_notify_job_complete(inst, result);

    if (inst->cid_device)
    {
        cui_bt_device_select_screen_close(inst->cid_device);
        inst->cid_device = 0;
    }

    if (inst->h_srv)
    {
        srv_bpp_get_info(inst->h_srv, inst->job_id, &addr, BPP_INFO_PRINTER_ADDR);

        if (inst->flags & FLAG_NEW_JOB)
            srv_bpp_delete(inst->h_srv, inst->job_id);
        else
            srv_bpp_cancel(inst->h_srv, inst->job_id);

        srv_bpp_close(inst->h_srv);

        /* Save this for later bearer info update purpose */
        p_cntx->addr = addr;
        p_cntx->flags |= inst->flags;
    }

    srv_bt_cm_reset_notify(inst->h_cm_srv);

    bpp_del_inst(inst);

    if (gid)
        mmi_frm_group_close(gid);
}


#ifdef __MMI_BT_AUTO_POWER_SWITCH__
/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_auto_on_hdlr(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bpp_inst_struct *inst = p_cntx->inst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BPP_AUTO_ON_DONE, inst, result);

    if (!inst)
        return;

    bpp_power_on_hdlr(inst, 0, result);
}
#endif /* __MMI_BT_AUTO_POWER_SWITCH__ */

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 bpp_sel_device(bpp_inst_struct *inst)
{
    /* RENDERING_MAJOR_SERVICE_MASK |
       IMAGING_MAJOR_DEVICE_MASK |
       PRINTER_IMAGING_MINOR_DEVICE_CLASS */
    U32 cod = 0x040680;
    MMI_ID cid;

    cid = cui_bt_device_select_screen_create(inst->group_id);
    if (!cid)
        return E_FAIL;

    inst->cid_device = cid;

    cui_bt_device_select_screen_set_mask(cid, cod, 0);
    cui_bt_device_select_screen_run(cid);

    return E_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 bpp_show_preview(bpp_inst_struct *inst)
{
    inst->preview = bpp_new_preview(inst);

    mmi_frm_scrn_first_enter(
        inst->group_id,
        SCR_BPP_SP_PREVIEW,
        (FuncPtr)bpp_preview_enter_hdlr,
        inst);

    mmi_frm_scrn_set_leave_proc(
        inst->group_id,
        SCR_BPP_SP_PREVIEW,
        (mmi_proc_func)bpp_preview_scrn_hdlr);

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  bpp_preview_enter_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET bpp_preview_enter_hdlr(mmi_scrn_essential_struct *info)
{
    bpp_inst_struct *inst = (bpp_inst_struct *)info->user_data;
    bpp_preview_struct *p = inst->preview;

#ifdef __MMI_ICON_BAR_SUPPORT__
    U8 *enable_imgs[BPP_TOOLBAR_ICON_COUNT];
    U8 *disable_imgs[BPP_TOOLBAR_ICON_COUNT];
    U8 *icon_text[BPP_TOOLBAR_ICON_COUNT];
    U32 i;
#endif

    if (!mmi_frm_scrn_enter(
            info->group_id, info->scrn_id,
            (FuncPtr)bpp_preview_exit_hdlr,
            (FuncPtr)bpp_preview_enter_hdlr,
            MMI_FRM_FULL_SCRN))
        return MMI_RET_ERR;
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BPP_ENTRY_PREVIEW);
    
#ifdef __MMI_ICON_BAR_SUPPORT__
    if (p->flags & FLAG_ZOOM)
    {
        for (i = 0; i < BPP_TOOLBAR_ICON_COUNT; i++)
        {
            enable_imgs[i] = get_image(BppIcons[i].enable_id);
            disable_imgs[i] = get_image(BppIcons[i].disable_id);
            icon_text[i] = (U8 *)get_string(BppIcons[i].str_id);
        }

        wgui_icon_bar_setup(
            BPP_TOOLBAR_ICON_COUNT,
            enable_imgs, disable_imgs, icon_text,
            bpp_preview_toolbar_hdlr);
        wgui_icon_bar_set_item_enable_state(1, MMI_FALSE); 
        wgui_icon_bar_set_item_enable_state(2, MMI_FALSE);
    }
#endif
    if (inst->preview->flags & FLAG_ZOOM)
    {
        ShowCategory227Screen(
            (U8 *)GetString(STR_BT_BPP_SP_PREVIEW),
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            bpp_preview_draw_hdlr,
            NULL);
    }
    else
    {
        ShowCategory227Screen(
            (U8 *)GetString(STR_BT_BPP_SP_PREVIEW),
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            STR_GLOBAL_PRINT,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            bpp_preview_draw_hdlr,
            NULL);
    }

    SetLeftSoftkeyFunction(bpp_preview_lsk_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(bpp_preview_rsk_hdlr, KEY_EVENT_UP);
    
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(bpp_preview_csk_hdlr, KEY_EVENT_UP);

    if (inst->preview->flags & FLAG_ZOOM)
    {
        SetKeyHandler(bpp_preview_zoom_out_hdlr, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(bpp_preview_zoom_in_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
#ifdef __MMI_ICON_BAR_SUPPORT__
    if (p->flags & FLAG_ZOOM)
    {
        if (bpp_zoom_enable(p, 'zin'))
            wgui_icon_bar_set_item_enable_state(1, MMI_TRUE);

        if (bpp_zoom_enable(p, 'zout'))
            wgui_icon_bar_set_item_enable_state(2, MMI_TRUE);
        wgui_icon_bar_update();
    }
#endif
    return MMI_RET_OK;
}

static MMI_RET bpp_preview_exit_hdlr(mmi_scrn_essential_struct *info)
{
    bpp_inst_struct *inst = (bpp_inst_struct *)info->user_data;

    inst->obj.size = inst->preview->obj.size;

    return MMI_RET_OK;
}


static MMI_RET bpp_preview_scrn_hdlr(mmi_event_struct *evt)
{
    bpp_inst_struct *inst = (bpp_inst_struct *)evt->user_data;
    
    if (evt->evt_id == EVT_ID_SCRN_DEINIT)
    {
        bpp_del_preview(inst);
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_preview_draw_hdlr(dm_coordinates *screen)
{
    MMI_ID gid = mmi_frm_group_get_active_id();
    bpp_inst_struct *inst = 
        (bpp_inst_struct *)mmi_frm_scrn_get_user_data(gid, SCR_BPP_SP_PREVIEW);
    bpp_preview_struct *p;
    
    MMI_ASSERT(inst && inst->magic == BPP_MAGIC_NUMBER);

    if (!inst || inst->magic != BPP_MAGIC_NUMBER) return;

    p = inst->preview;

    p->bk_region.x1 = screen->s16X;
    p->bk_region.x2 = screen->s16X + screen->s16Width-1;
    p->bk_region.y1 = screen->s16Y;
    p->bk_region.y2 = screen->s16Y + screen->s16Height-1;

    bpp_draw_preview(inst, &p->bk_region);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_preview_lsk_hdlr(void)
{
    MMI_ID gid = mmi_frm_group_get_active_id();
    bpp_inst_struct *inst = 
        (bpp_inst_struct *)mmi_frm_scrn_get_user_data(gid, SCR_BPP_SP_PREVIEW);

    MMI_ASSERT(inst && inst->magic == BPP_MAGIC_NUMBER);

    if (inst->preview->flags & FLAG_ZOOM)
        bpp_show_preview_options(inst);
    else
        bpp_print_hdlr(inst);
}

/*****************************************************************************
 * FUNCTION
 *  bpp_preview_csk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_preview_csk_hdlr(void)
{
    MMI_ID gid = mmi_frm_group_get_active_id();
    bpp_inst_struct *inst = 
        (bpp_inst_struct *)mmi_frm_scrn_get_user_data(gid, SCR_BPP_SP_PREVIEW);

    MMI_ASSERT(inst && inst->magic == BPP_MAGIC_NUMBER);

    bpp_print_hdlr(inst);
}

/*****************************************************************************
 * FUNCTION
 *  bpp_preview_rsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_preview_rsk_hdlr(void)
{
    MMI_ID gid = mmi_frm_group_get_active_id();
    bpp_inst_struct *inst = 
        (bpp_inst_struct *)mmi_frm_scrn_get_user_data(gid, SCR_BPP_SP_PREVIEW);

    MMI_ASSERT(inst && inst->magic == BPP_MAGIC_NUMBER);

    mmi_frm_scrn_close(gid, SCR_BPP_SP_PREVIEW);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_preview_zoom_in_hdlr(void)
{
    MMI_ID gid = mmi_frm_group_get_active_id();
    bpp_inst_struct *inst = 
        (bpp_inst_struct *)mmi_frm_scrn_get_user_data(gid, SCR_BPP_SP_PREVIEW);

    MMI_ASSERT(inst && inst->magic == BPP_MAGIC_NUMBER);

    if (!inst || inst->magic != BPP_MAGIC_NUMBER) return;

    bpp_zoom_preview(inst, 'zin');
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_preview_zoom_out_hdlr(void)
{
    MMI_ID gid = mmi_frm_group_get_active_id();
    bpp_inst_struct *inst = 
        (bpp_inst_struct *)mmi_frm_scrn_get_user_data(gid, SCR_BPP_SP_PREVIEW);

    MMI_ASSERT(inst && inst->magic == BPP_MAGIC_NUMBER);

    if (!inst || inst->magic != BPP_MAGIC_NUMBER) return;

    bpp_zoom_preview(inst, 'zout');
}

#ifdef __MMI_ICON_BAR_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_preview_toolbar_hdlr(S32 idx)
{
    MMI_ID gid = mmi_frm_group_get_active_id();
    bpp_inst_struct *inst = 
        (bpp_inst_struct *)mmi_frm_scrn_get_user_data(gid, SCR_BPP_SP_PREVIEW);

    MMI_ASSERT(inst && inst->magic == BPP_MAGIC_NUMBER);

    if (!inst || inst->magic != BPP_MAGIC_NUMBER) return;

    switch (idx) {
    case 0:
        bpp_print_doc(inst);
        break;
    case 1:
        bpp_zoom_preview(inst, 'zin');
        break;
    case 2:
        bpp_zoom_preview(inst, 'zout');
        break;
    default:
        MMI_ASSERT(0);
        break;
    }
}
#endif /* __MMI_FTE_SUPPORT__ */

static bpp_preview_struct *bpp_new_preview(bpp_inst_struct *inst)
{
    bpp_preview_struct *p = NULL;

    p = get_ctrl_buffer(sizeof(*p));
    memset(p, 0, sizeof(*p));

    p->obj = inst->obj;
    p->obj_size = p->obj.size;

    if (inst->page.rotate)
    {
        p->page.width = bpp_mm_to_pixel(
            inst->page.height-inst->page.margin.top-inst->page.margin.bottom);
        p->page.height = bpp_mm_to_pixel(
            inst->page.width-inst->page.margin.left - inst->page.margin.right);
        p->flags |= FLAG_ROTATE;
    }
    else
    {
        p->page.width = bpp_mm_to_pixel(
            inst->page.width-inst->page.margin.left - inst->page.margin.right);
        p->page.height = bpp_mm_to_pixel(
            inst->page.height-inst->page.margin.top-inst->page.margin.bottom);
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_MMI_NEW_PREVIEW, 
        p->page.width, p->page.height, p->obj.type, p->obj.size.width, p->obj.size.height); 
    
    p->page_size = p->page;

    if (p->obj.type == BPP_IMAGE_JPEG)
    {
        p->flags |= FLAG_ZOOM;

        bpp_init_zoom(p->zoom_size, &p->zoom_level, &p->obj.size, &p->page_size);
    }
    p->result = 0;
    return p;
}

static void bpp_del_preview(bpp_inst_struct *inst)
{
    if (inst->preview)
    {
        free_ctrl_buffer(inst->preview);
        inst->preview = NULL;
    }
}

#define BPP_MAX(x,y)    ((x) < (y) ? (y) : (x))
#define BPP_MIN(x,y)    ((x) > (y) ? (y) : (x))

static void bpp_init_zoom(bpp_dimension *zoom_size, U32 *zoom_level,
                          bpp_dimension *obj_size, bpp_dimension *page_size)
{
    bpp_dimension max, min;
    U32 i, w_interval, h_interval;
    U32 diff[MAX_ZOOM_LEVEL];
    U32 min_diff;
    
    max_dimension(&max, obj_size, page_size);

    min.width = max.width / MAX_ZOOM_LEVEL;
    min.height = max.height / MAX_ZOOM_LEVEL;
    
    if (obj_size->width < min.width ||
        obj_size->height < min.height)
        min = *obj_size;

    if (!min.width) min.width = 1;
    if (!min.height) min.height = 1;

    w_interval = (max.width - min.width) / MAX_ZOOM_LEVEL;
    h_interval = (max.height - min.height) / MAX_ZOOM_LEVEL;
    
    for (i = 0; i < MAX_ZOOM_LEVEL; i++)
    {
        zoom_size[i].width = min.width + i * w_interval;
        zoom_size[i].height = min.height + i * h_interval;
    
        if (i == MAX_ZOOM_LEVEL - 1)
            zoom_size[i] = max;
    
        diff[i] = (BPP_MAX(zoom_size[i].width, obj_size->width) - 
                BPP_MIN(zoom_size[i].width, obj_size->width)) *
               (BPP_MAX(zoom_size[i].height,obj_size->height) -
                BPP_MIN(zoom_size[i].height,obj_size->height));
    }
    
    min_diff = diff[0];
    *zoom_level = 1;
    for (i = 1; i < MAX_ZOOM_LEVEL; i++)
        {
        if (diff[i] < min_diff)
        {
            min_diff = diff[i];
            *zoom_level = i + 1;
        }
               
    }

    zoom_size[*zoom_level-1] = *obj_size;
}

/*****************************************************************************
 * FUNCTION
 *  bpp_show_preview_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_show_preview_options(bpp_inst_struct *inst)
{
    MMI_ID id_menu;

    id_menu = cui_menu_create(
            inst->group_id, 
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_FROM_RESOURCE,
            MENU_BPP_PREVIEW_OPTIONS,
            MMI_TRUE,
            (void *)MENU_BPP_PREVIEW_OPTIONS);

    cui_menu_run(id_menu);
}

/*****************************************************************************
 * FUNCTION
 *  bpp_draw_preview
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 bpp_draw_preview(bpp_inst_struct *inst, bpp_region_struct *region)
{
    bpp_dimension area, page;
    bpp_preview_struct *p = inst->preview;

    if ((!p->last.width && !p->last.height)&&(p->result >= 0))
    {
        area.width = region->x2 - region->x1 + 1;
        area.height = region->y2 - region->y1 + 1;

        page.width = p->page_size.width;
        page.height = p->page_size.height;

        /* Keep 1 pixel space */
        area.width -= 2;
        area.height -= 2;

        adjust_dimension(&page, &area, 0);

        if (p->flags & FLAG_ROTATE)
        {
            p->pg_region.x1 = region->x1;
            p->pg_region.y1 = region->y1 + (area.height - page.height) / 2;
        }
        else
        {
            p->pg_region.x1 = region->x1 + (area.width - page.width) / 2;
            p->pg_region.y1 = region->y1;
        }
        p->pg_region.x2 = p->pg_region.x1 + page.width - 1;
        p->pg_region.y2 = p->pg_region.y1 + page.height - 1;

        p->page_size = page;

        p->obj_size.width = p->obj_size.width * p->page_size.width * 100 / p->page.width / 100;
        p->obj_size.height = p->obj_size.height * p->page_size.height * 100 / p->page.height /100;

        if (!p->obj_size.width) p->obj_size.width = 1;
        if (!p->obj_size.height) p->obj_size.height = 1;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_MMI_DRAW_PREVIEW, 
        region->x1, region->y1, region->x2, region->y2, p->page_size.width, p->page_size.height, p->obj_size.width, p->obj_size.height);
    
    gdi_layer_push_clip();

    bpp_draw_background(region);

    bpp_draw_paper(p);
    
    bpp_draw_image(p);

    gdi_layer_pop_clip();

    return E_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 bpp_draw_background(bpp_region_struct *region)
{
    gdi_layer_set_clip(region->x1, region->y1, region->x2, region->y2);

    gdi_draw_solid_rect(region->x1, region->y1, region->x2, region->y2,
        gdi_act_color_from_rgb(255, 200, 230, 245));

    return E_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 bpp_draw_paper(bpp_preview_struct *p)
{
    gdi_layer_set_clip(
        p->pg_region.x1,
        p->pg_region.y1,
        p->pg_region.x2,
        p->pg_region.y2);

    gdi_draw_solid_rect(
        p->pg_region.x1,
        p->pg_region.y1,
        p->pg_region.x2,
        p->pg_region.y2,
        GDI_COLOR_WHITE);

    return E_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 bpp_draw_image(bpp_preview_struct *p)
{
    bpp_region_struct img_region;
    GDI_RESULT retval = 0;

    img_region.x1 = p->pg_region.x1;
    img_region.y1 = p->pg_region.y1;
    img_region.x2 = img_region.x1 + p->obj_size.width - 1;
    img_region.y2 = img_region.y1 + p->obj_size.height - 1;

#ifdef __MMI_IMGADV_NONBLOCKING_DECODE__
    retval = gdi_anim_nb_draw_resized_file(
                img_region.x1,
                img_region.y1,
                p->obj_size.width,
                p->obj_size.height,
                p->obj.path);
#else
    if(p->hd_draw)
    {
       gdi_anim_stop(p->hd_draw);
       p->hd_draw = 0;
    }

    retval = gdi_anim_draw_file_resized(
                img_region.x1,
                img_region.y1,
                p->obj_size.width,
                p->obj_size.height,
                p->obj.path,
                &p->hd_draw);
#endif

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_MMI_DRAW_IMAGE,
        img_region.x1, img_region.y1, p->obj_size.width, p->obj_size.height, p->last.width, p->last.height, retval);

    p->result = retval;

    if (retval >= 0)
    {
        p->last = p->obj_size;
        return E_OK;
    }

    if ((!p->last.width && !p->last.height) ||
        (p->last.width == p->obj_size.width && p->last.height == p->obj_size.height))
    {
        MMI_STR_ID str_id = STR_BT_BPP_NO_PREVIEW;

        p->result = retval;
        bpp_draw_text((WCHAR *)GetString(str_id), &p->pg_region, &img_region);
        return E_FAIL;
    }
    
    p->obj_size = p->last;

    bpp_draw_image(p);

    return E_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 bpp_draw_text(WCHAR *text, bpp_region_struct *page, bpp_region_struct *img)
{
    color c;
    S32 text_width, offset = 0;
    S32 w_page = page->x2 - page->x1;
    S32 h_page = page->y2 - page->y1;

    c = gui_color(0, 0, 0);
    
    gdi_draw_solid_rect(img->x1, img->y1, img->x2, img->y2, GDI_COLOR_WHITE);
    
    gui_set_font(&MMI_small_font);
    gui_set_text_color(c);

    text_width =  gui_get_string_width(text);
    if (r2lMMIFlag)
        offset = text_width;
    
    if(text_width <= w_page)
        gui_move_text_cursor(
            offset + img->x1 + (w_page-text_width)/2,
            img->y1 + h_page/2);
    else
    {
        if (offset > w_page)
            offset = w_page;
        gui_move_text_cursor(
            offset + img->x1,
            img->y1 + h_page/2);
    }
    gui_print_text(text);

    return E_OK;
}

static S32 bpp_preview_enable(bpp_app_data_struct *obj_data)
{
    S32 retval;

    if ((retval = FS_Open(obj_data->u.file, FS_READ_ONLY)) < FS_NO_ERROR)
    {
        FS_Close(retval);
        return 0;
    }
    else
        FS_Close(retval);
    return 1;
}

static S32 bpp_zoom_enable(bpp_preview_struct *p, U32 opt)
{
    U32 level = p->zoom_level;

    if (p->result < 0)
        return 0;

    if ((level == 1 && opt == 'zout') ||
        (level == MAX_ZOOM_LEVEL && opt == 'zin'))
        return 0;

    return 1;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 bpp_zoom_preview(bpp_inst_struct *inst, U32 opt)
{
    bpp_preview_struct *p = inst->preview;
    U32 level = p->zoom_level;

    if (!bpp_zoom_enable(p, opt))
        return E_FAIL;

    if (opt == 'zout')
        level--;
    else
        level++;

    p->obj_size.width = p->zoom_size[level-1].width * p->page_size.width / p->page.width;
    p->obj_size.height = p->zoom_size[level-1].height * p->page_size.height / p->page.height;

    if (!p->obj_size.width) p->obj_size.width = 1;
    if (!p->obj_size.height) p->obj_size.height = 1;

    if (bpp_draw_preview(inst, &p->bk_region) == E_OK)
    {
        p->obj.size = p->zoom_size[level-1];
        p->zoom_level = level;

        if (mmi_frm_scrn_get_active_id() == SCR_BPP_SP_PREVIEW)
        {
            gdi_layer_blt_previous(
                p->bk_region.x1,
                p->bk_region.y1,
                p->bk_region.x2,
                p->bk_region.y2);
        }
    }
    else
    {
        p->obj_size = p->last;
    }

#ifdef __MMI_ICON_BAR_SUPPORT__
    if (bpp_zoom_enable(p, 'zin'))
        wgui_icon_bar_set_item_enable_state(1, MMI_TRUE);
    else
        wgui_icon_bar_set_item_enable_state(1, MMI_FALSE);
    
    if (bpp_zoom_enable(p, 'zout'))
        wgui_icon_bar_set_item_enable_state(2, MMI_TRUE);
    else
        wgui_icon_bar_set_item_enable_state(2, MMI_FALSE);

    wgui_icon_bar_update();
#endif    
    
    return E_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_show_setting(bpp_inst_struct *inst)
{
    MMI_ID cid;
    S32 i;

    if (!(inst->flags & FLAG_NEW_JOB))
        srv_bpp_edit(inst->h_srv, inst->job_id);
    
    cid = cui_inline_create(inst->group_id, &SettingProps);
    MMI_ASSERT(cid);

    cui_inline_set_title_icon(cid, GetRootTitleIcon(MENU_CONN_BT_MAIN));

    for (i = 0; i < ArrayCount(DynamicSetItems); i++)
    {
        cui_inline_insert_item(cid, CUI_INLINE_INSERT_TAIL, 
            (cui_inline_set_item_struct *)&DynamicSetItems[i]);
        cui_inline_set_softkey_text(
            cid, DynamicSetItems[i].item_id,
            MMI_LEFT_SOFTKEY, STR_GLOBAL_OPTIONS);
        cui_inline_set_softkey_text(
            cid, DynamicSetItems[i].item_id,
            MMI_RIGHT_SOFTKEY, STR_GLOBAL_BACK);
        cui_inline_set_softkey_icon(
            cid, DynamicSetItems[i].item_id,
            MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);
    }

    inst->setting = bpp_new_setting(inst);

    bpp_fill_setting_items(cid, inst->setting);

    inst->cid_setting = cid;

    cui_inline_run(cid);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static bpp_setting_struct *bpp_new_setting(bpp_inst_struct *inst)
{
    bpp_setting_struct *set;
    PrintOptionInfo info;

    set = get_ctrl_buffer(sizeof(*set));

    srv_bpp_get_info(inst->h_srv, inst->job_id, &info, BPP_INFO_JOB_OPTION);

    memset(set, 0, sizeof(*set));

    bpp_update_setting(inst, set);

    return set;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_update_setting(bpp_inst_struct *inst, bpp_setting_struct *set)
{
    PrinterAttribute attr;
    PrintOption option;
    S32 i;
    enum {indx_copies, indx_size, indx_orien, indx_side, indx_qlty};
    
    srv_bpp_get_info(inst->h_srv, inst->job_id, &set->addr, BPP_INFO_PRINTER_ADDR);
    srv_bpp_get_info(inst->h_srv, inst->job_id, &attr, BPP_INFO_PRINTER_ATTR);
    srv_bpp_get_info(inst->h_srv, inst->job_id, &option, BPP_INFO_PRINT_OPTION);

    set->items[indx_size].id = ITEM_ID_SIZE;
    bpp_set_setting_item(
        &set->items[indx_size],
        attr.mediaSize, option.mediaSize,
        sizeof(attr.mediaSize), (const U8 **)MediaSizeStr, NULL);

    set->items[indx_copies].id = ITEM_ID_COPIES;
    set->items[indx_copies].count = 
        (attr.maxCopies > BPP_MAX_COPIES) ? BPP_MAX_COPIES:attr.maxCopies;
    
    for (i = 0; i < set->items[indx_copies].count; i++)
    {
        set->items[indx_copies].values[i].data = i+1;
        set->items[indx_copies].values[i].str = (U8 *)GetString(CopiesStrID[i]);
        if (option.copies== (U8)(i+1))
            set->items[indx_copies].focus = (U8)i;
    }

    set->items[indx_orien].id = ITEM_ID_ORIENT;
    bpp_set_setting_item(
        &set->items[indx_orien],
        attr.orientation, option.orientation,
        sizeof(attr.orientation),
        NULL, OrientationStrID);
    
    set->items[indx_side].id = ITEM_ID_SIDES;
    bpp_set_setting_item(
        &set->items[indx_side],
        attr.sides, option.sides,
        sizeof(attr.sides),
        NULL, SidedStrID);

    set->items[indx_qlty].id = ITEM_ID_QUALITY;
    bpp_set_setting_item(
        &set->items[indx_qlty],
        attr.quality, option.quality,
        sizeof(attr.quality),
        NULL, QualityStrID);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_del_setting(bpp_inst_struct *inst)
{
    if (inst->setting)
    {
        free_ctrl_buffer(inst->setting);
        inst->setting = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_fill_setting_items(MMI_ID cid, bpp_setting_struct *set)
{
    U8 **list;
    S32 i, j;

    bpp_get_dev_name(set->dev_name, &set->addr);

    cui_inline_set_value(cid, ITEM_ID_NAME, set->dev_name);

    list = get_ctrl_buffer(sizeof(U8 *) * BPP_MAX_ITEM_VALUES);

    for (i = 0; i < ArrayCount(DynamicSetItems)/2; i++)
    {
        bpp_item_struct *item = &set->items[i];

        for (j = 0; j < item->count; j++)
            list[j] = item->values[j].str;

        cui_inline_set_item_select(cid, item->id, item->count, list, item->focus);
    }

    free_ctrl_buffer(list);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_set_setting_item(
                bpp_item_struct *item, 
                U64 scope, U64 select, U32 size,
                const U8 **str_list, const MMI_STR_ID *str_id_list)
{
    U32 i, j;
    U64 t;
    
    item->enable = 1;

    item->count = bpp_flag_count(scope);

    for (i = 0, j = 0, t = 1; i < size*8 && j < item->count; i++)
    {
        if (scope & t)
        {
            item->values[j].data = t;
            if (str_list)
                item->values[j].str = (U8 *)str_list[i];
            else
                item->values[j].str = (U8 *)GetString(str_id_list[i]);

            if (select == t)
                item->focus = (U8)j;
            j++;
        }
        
        t = t << 1;
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_apply_setting(bpp_inst_struct *inst)
{
    PrintOption option;
    U32 i;

    memset(&option, 0, sizeof(option));

    for (i = 0; i < ArrayCount(DynamicSetItems)/2; i++)
    {
        cui_inline_get_value(
            inst->cid_setting,
            inst->setting->items[i].id,
            &inst->setting->items[i].chosen);
    }

    for (i = 0; i < ArrayCount(DynamicSetItems)/2; i++)
    {
        bpp_item_struct *item = &inst->setting->items[i];

        switch (item->id) {
        case ITEM_ID_SIZE:
            option.mediaSize = item->values[item->chosen].data;
            break;

        case ITEM_ID_COPIES:
            option.copies = (U8)item->values[item->chosen].data;
            break;

        case ITEM_ID_ORIENT:
            option.orientation = (U8)item->values[item->chosen].data;
            break;

        case ITEM_ID_SIDES:
            option.sides = (U8)item->values[item->chosen].data;
            break;

        case ITEM_ID_QUALITY:
            option.quality = (U8)item->values[item->chosen].data;
            break;

        default:
            break;
        }
    }

    srv_bpp_set_option(inst->h_srv, inst->job_id, &option);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_abort_setting(bpp_inst_struct *inst)
{
    if (!(inst->flags & FLAG_NEW_JOB))
        srv_bpp_cancel(inst->h_srv, inst->job_id);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_save_setting(bpp_inst_struct *inst)
{
    inst->job_id = srv_bpp_save(inst->h_srv, inst->job_id);

    if (inst->flags & FLAG_NEW_JOB)
        inst->flags &= ~FLAG_NEW_JOB;

    /* We still in setting screen, keep editing status */
    srv_bpp_edit(inst->h_srv, inst->job_id);

    bpp_alert('std', inst->group_id, STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_show_progress(bpp_inst_struct *inst, U32 mode)
{
    if (mode == 'get')
    {
        mmi_confirm_property_struct arg;
        WCHAR *text = (WCHAR *)GetString(STR_BT_BPP_GETTING_CAPABILITY);
            
        mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);

        arg.parent_id = inst->group_id;
        arg.user_tag = inst;
        arg.f_enter_history = 1;
        arg.f_auto_dismiss = 0;

        inst->pid_getting = mmi_confirm_display(text, MMI_EVENT_PROGRESS, &arg);
    }
    else
    {
        inst->prog_rate = 0;
        mmi_frm_scrn_first_enter(
            inst->group_id,
            SCR_BPP_SP_PRINTING,
            (FuncPtr)bpp_printing_enter_hdlr,
            inst);

        mmi_frm_scrn_set_leave_proc(
            inst->group_id,
            SCR_BPP_SP_PRINTING,
            (mmi_proc_func)bpp_printing_scrn_proc);
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET bpp_printing_scrn_proc(mmi_event_struct *evt)
{
    bpp_inst_struct *inst = (bpp_inst_struct *)evt->user_data;
    
    if (evt->evt_id == EVT_ID_SCRN_DEINIT)
    {
        if (inst->txt_buff)
        {
            free_ctrl_buffer(inst->txt_buff);
            inst->txt_buff = NULL;
        }
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET bpp_printing_enter_hdlr(mmi_scrn_essential_struct *info)
{
    bpp_inst_struct *inst = (bpp_inst_struct *)info->user_data;

    if (!mmi_frm_scrn_enter(
            info->group_id, info->scrn_id, 
            (FuncPtr)bpp_printing_exit_hdlr,
            (FuncPtr)bpp_printing_enter_hdlr,
            MMI_FRM_FULL_SCRN))
        return MMI_RET_ERR;
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BPP_PRINTING, inst);

    if (!inst->txt_buff)
        inst->txt_buff = get_ctrl_buffer(sizeof(inst->txt_buff) * (BPP_TEXT_LEN+1));

    format_prog_text(inst->txt_buff, inst->prog_rate);

    ShowCategory402Screen(
        (U8*)GetString(STR_BT_BPP_PRINTING),
        GetRootTitleIcon(MENU_CONN_BT_MAIN),
        0, 0, 
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        NULL,
        inst->prog_rate,
        (U8 *)inst->txt_buff);

    SetRightSoftkeyFunction(bpp_printing_rsk_hdlr, KEY_EVENT_UP);

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET bpp_printing_exit_hdlr(mmi_scrn_essential_struct *info)
{
    bpp_inst_struct *inst = (bpp_inst_struct *)info->user_data;

    if (inst->txt_buff)
    {
        free_ctrl_buffer(inst->txt_buff);
        inst->txt_buff = NULL;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_printing_rsk_hdlr(void)
{
    MMI_ID gid = mmi_frm_group_get_active_id();
    bpp_inst_struct *inst = 
        (bpp_inst_struct *)mmi_frm_scrn_get_user_data(gid, SCR_BPP_SP_PRINTING);

    MMI_ASSERT(inst && inst->magic == BPP_MAGIC_NUMBER);

    srv_bpp_abort(inst->h_srv, inst->job_id);
    inst->flags |= FLAG_USER_CANCEL;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_ID bpp_show_confirm(bpp_inst_struct *inst, WCHAR *text)
{
    mmi_confirm_property_struct arg;
    
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);

    arg.parent_id = inst->group_id;
    arg.user_tag = inst;
    arg.f_enter_history = 1;
    arg.f_auto_dismiss = 0;

    return mmi_confirm_display(text, MMI_EVENT_QUERY, &arg);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_show_auth(bpp_inst_struct *inst)
{
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);

    if (!inst->auth_pass)
    {
        inst->auth_pass = get_ctrl_buffer((BPP_MAX_PASS_LEN+1)*2);
        inst->auth_pass[0] = '\0';
    }
    if (!inst->auth_title)
    {
        inst->auth_title = get_ctrl_buffer((BPP_MAX_AUTH_LEN+1)*2);
        inst->auth_title[0] = '\0';
    }

    mmi_frm_scrn_first_enter(
        inst->group_id,
        SCR_BPP_SP_PASSWORD_INPUT,
        (FuncPtr)bpp_auth_enter_hdlr,
        inst);
    
    mmi_frm_scrn_set_leave_proc(
        inst->group_id,
        SCR_BPP_SP_PASSWORD_INPUT,
        (mmi_proc_func)bpp_auth_scrn_proc);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET bpp_auth_enter_hdlr(mmi_scrn_essential_struct *info)
{
    bpp_inst_struct * inst = (bpp_inst_struct *)info->user_data;
    U8 *gui_buff;
    WCHAR *input_buff;

    if (!mmi_frm_scrn_enter(
            info->group_id,
            info->scrn_id,
            NULL,
            (FuncPtr)bpp_auth_enter_hdlr,
            MMI_FRM_FULL_SCRN))
        return MMI_RET_ERR;

    gui_buff = mmi_frm_scrn_get_gui_buf(info->group_id, info->scrn_id);
    input_buff = mmi_frm_scrn_get_input_buf(info->group_id, info->scrn_id);

    if (!input_buff)
    {
        WCHAR name[BPP_MAX_DEV_NAME+1];
        PrinterAddr addr;
        WCHAR *head = (WCHAR *)GetString(STR_BT_BPP_SP_AUTHENTICATING);

        srv_bpp_get_info(inst->h_srv, inst->job_id, &addr, BPP_INFO_PRINTER_ADDR);

        bpp_get_dev_name(name, &addr);

        kal_wsprintf(inst->auth_title, "%w(%w):", head, name);
    }
    else
    {
        mmi_wcscpy(inst->auth_pass, input_buff);
    }

    RegisterInputBoxValidationFunction(bpp_auth_valid_hdlr);
    ShowCategory111Screen_ext(
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8 *)inst->auth_title,
        IMM_INPUT_TYPE_NUMERIC_PASSWORD,
        (U8*)inst->auth_pass,
        BPP_MAX_PASS_LEN+1,
        NULL,
        0,
        gui_buff);

    if (!mmi_wcslen(inst->auth_pass))
        ChangeLeftSoftkey(0, 0);
    else
    {
        SetLeftSoftkeyFunction(bpp_auth_lsk_hdlr, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(bpp_auth_lsk_hdlr, KEY_EVENT_UP);
    }

    SetCategory111RightSoftkeyFunction(bpp_auth_rsk_hdlr, KEY_EVENT_UP);

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET bpp_auth_scrn_proc(mmi_event_struct *evt)
{
    bpp_inst_struct *inst = (bpp_inst_struct *)evt->user_data;
    
    if (evt->evt_id == EVT_ID_SCRN_DEINIT)
    {
        free_ctrl_buffer(inst->auth_title);
        free_ctrl_buffer(inst->auth_pass);
        
        inst->auth_title = inst->auth_pass = NULL;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_auth_valid_hdlr(U8 *text, U8 *cursor, S32 length)
{
    if (!length)
    {
        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0);
    }
    else
    {
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetLeftSoftkeyFunction(bpp_auth_lsk_hdlr, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(bpp_auth_lsk_hdlr, KEY_EVENT_UP);
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_auth_lsk_hdlr(void)
{
    MMI_ID gid = mmi_frm_group_get_active_id();
    bpp_inst_struct *inst = 
        (bpp_inst_struct *)mmi_frm_scrn_get_user_data(gid, SCR_BPP_SP_PASSWORD_INPUT);
    CHAR pass[BPP_MAX_PASS_LEN+1];

    MMI_ASSERT(inst && inst->magic == BPP_MAGIC_NUMBER);

    mmi_wcs_to_asc(pass, inst->auth_pass);

    srv_bpp_set_password(inst->h_srv, inst->job_id, pass);
    srv_bpp_accept(inst->h_srv, inst->job_id);

    mmi_frm_scrn_close(inst->group_id, SCR_BPP_SP_PASSWORD_INPUT);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_auth_rsk_hdlr(void)
{
    MMI_ID gid = mmi_frm_group_get_active_id();
    bpp_inst_struct *inst = 
        (bpp_inst_struct *)mmi_frm_scrn_get_user_data(gid, SCR_BPP_SP_PASSWORD_INPUT);

    MMI_ASSERT(inst && inst->magic == BPP_MAGIC_NUMBER);

    srv_bpp_abort(inst->h_srv, inst->job_id);
    inst->flags |= FLAG_USER_CANCEL;

    mmi_frm_scrn_close(inst->group_id, SCR_BPP_SP_PASSWORD_INPUT);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_set_page_info(bpp_inst_struct *inst, U64 media_size, U8 orient)
{
    bpp_page_struct *page = &inst->page;
    bpp_page_config_struct *config = &inst->app.page;
    U32 w_paper, h_paper;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_MMI_PAGE_INFO,
        inst->obj.real_size.width, inst->obj.real_size.height, inst->obj.size.width, inst->obj.size.height, media_size, orient);

    if (media_size || orient)
    {
        inst->obj.size = inst->obj.real_size;
    }

    if (media_size)
    {
        srv_bpp_media_size(media_size, &w_paper, &h_paper);

        page->width = w_paper;
        page->height = h_paper;

        page->margin.left = w_paper * config->l_margin / 100;
        page->margin.right = w_paper * config->r_margin / 100;
        page->margin.top = h_paper * config->t_margin / 100;
        page->margin.bottom = h_paper * config->b_margin / 100;
    }
    if (orient)
    {
        page->rotate = ((orient == BPP_PORTRAIT) ? 0 : 1);
    }

    /* When page info update, we need to sync object info */
    if (inst->obj.path)
    {
        bpp_dimension box;

        box.width = page->width - page->margin.left - page->margin.right;
        box.height = page->height - page->margin.top - page->margin.bottom;

        box.width = bpp_mm_to_pixel(box.width);
        box.height = bpp_mm_to_pixel(box.height);

        if (page->rotate)
        {
            S32 t = box.width;
            box.width = box.height;
            box.height = t;
        }

        adjust_dimension(&inst->obj.size, &box, 0);
        
        MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_MMI_UPD_PAGE_INFO,
            box.width, box.height, inst->obj.size.width, inst->obj.size.height);
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_update_prog_info(bpp_inst_struct *inst, U16 percent)
{
    inst->prog_rate = (U16)percent;

    if (inst->txt_buff)
    {
        MMI_ID scrn = mmi_frm_scrn_get_active_id();

        format_prog_text(inst->txt_buff, inst->prog_rate);
        if (scrn == SCR_BPP_SP_PRINTING &&
            (U32)inst == (U32)mmi_frm_scrn_get_user_data(inst->group_id, scrn))
        {
            UpdateCategory402Value(inst->prog_rate, (U8*)inst->txt_buff);
        }
    }
}

static void bpp_job_start_hdlr(bpp_inst_struct *inst, U32 status)
{
    bpp_notify_job_start(inst);
    
    srv_bpp_accept(inst->h_srv, inst->job_id);
}

static void bpp_notify_job_start(bpp_inst_struct *inst)
{
    evt_bt_print_start_struct evt;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_MMI_NOTIFY_START, inst, inst->page.width, inst->page.height); 
    
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_BT_PRINT_START, inst->group_id);
    evt.inst = (U32)inst;
    evt.page_info = inst->page;

    mmi_frm_group_post_to_parent(inst->group_id, (mmi_group_event_struct *)&evt);
}

/*****************************************************************************
 * FUNCTION
 *  bpp_data_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_data_req_hdlr(bpp_inst_struct *inst)
{
    if (inst->app.data.type == 'none')
        bpp_notify_data_req(inst);
    else
    {
        if (inst->app.data.content_type == BT_PRINT_CONTENT_XHTML)
            bpp_accept_data_req(inst);
        else
            bpp_data_helper(inst);
    }
}

/*****************************************************************************
 * FUNCTION
 *  bpp_accept_data_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_accept_data_req(bpp_inst_struct *inst)
{
    bpp_app_data_struct *app_data = &inst->app.data;
    PrintData print_data;

    if (app_data->type != 'none')
    {
        if (app_data->type == 'file')
        {
            print_data.type = BPP_DATA_FILE;
            print_data.u.file = app_data->u.file;
        }
        else
        {
            print_data.type = BPP_DATA_BUFF;
            print_data.u.buff = app_data->u.buff;
        }
        print_data.size = app_data->size;
        print_data.more = app_data->more;
        
        srv_bpp_set_data(inst->h_srv, inst->job_id, &print_data);
    }
        
    srv_bpp_accept(inst->h_srv, inst->job_id);
}

/*****************************************************************************
 * FUNCTION
 *  bpp_notify_data_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_notify_data_req(bpp_inst_struct *inst)
{
    evt_bt_print_data_req_struct evt;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_MMI_NOTIFY_DATA_REQ, inst, inst->app.type, inst->group_id); 

    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_BT_PRINT_DATA_REQ, inst->group_id);

    evt.inst = (U32)inst;

    switch (inst->app.type) {
    case 'imag':
        evt.storage.content_type = BT_PRINT_CONTENT_IMAGE;
        break;
    
    case 'text':
        evt.storage.content_type = BT_PRINT_CONTENT_TEXT_PLAIN;
        break;
    
    default:
        evt.storage.content_type = BT_PRINT_CONTENT_XHTML;
        break;
    }

    evt.storage.type = BT_PRINT_DATA_FILE;
    evt.storage.u.file = bpp_default_app_file(inst);

    mmi_frm_group_post_to_parent_ex(inst->group_id, (mmi_group_event_struct *)&evt);
}

/*****************************************************************************
 * FUNCTION
 *  bpp_data_helper
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_data_helper(bpp_inst_struct *inst)
{
    evt_bpp_data_helper evt;

    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_BPP_DATA_HELPER, inst->group_id);

    evt.storage = bpp_default_app_file(inst);

    mmi_frm_group_set_caller_proc(
        inst->group_id,
        (mmi_proc_func)bpp_data_helper_proc,
        inst);

    mmi_frm_group_post_to_caller_ex(inst->group_id, (mmi_group_event_struct *)&evt);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_job_status_hdlr(bpp_inst_struct *inst, U32 status)
{
    bpp_alert('intr', inst->group_id, PrintStatusStrID[status], MMI_EVENT_FAILURE);
}

/*****************************************************************************
 * FUNCTION
 *  bpp_job_finish_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_job_finish_hdlr(bpp_inst_struct *inst, U32 result)
{
    MMI_STR_ID str_id;

    switch (result) {
    case E_OK:
        str_id = STR_BT_BPP_SP_PRINT_DONE;
        break;

    case E_CANCEL:
        if (inst->flags & FLAG_USER_CANCEL)
            str_id = STR_BT_BPP_SP_PRINT_CANCEL;
        else
            str_id = STR_BT_BPP_SP_ERR_PRINT_ERROR;
        break;

    case E_DISK_FULL:
        str_id = STR_GLOBAL_NOT_ENOUGH_MEMORY;
        break;

    case E_BUSY:
        str_id = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
        break;

    case E_LINK_DISC:
    default:
        str_id = STR_BT_BPP_SP_ERR_PRINT_ERROR;
        break;
    }
        
    bpp_alert('intr', inst->group_id, str_id, 
        (result == E_OK) ? MMI_EVENT_SUCCESS : MMI_EVENT_FAILURE);

    bpp_stop_app(inst, result);
}

static void bpp_notify_job_complete(bpp_inst_struct *inst, U32 result)
{
    evt_bt_print_complete_struct evt;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_MMI_NOTIFY_COMPLETE, inst, result, inst->group_id); 

    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_BT_PRINT_COMPLETE, inst->group_id);

    evt.inst = (U32)inst;
    evt.result = (result == E_OK);
    evt.cause = result;

    if (result != E_ABORT)
        mmi_frm_group_post_to_parent(inst->group_id, (mmi_group_event_struct *)&evt);
    else
        mmi_frm_group_send_to_parent(inst->group_id, (mmi_group_event_struct *)&evt);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void format_prog_text(WCHAR *text, U16 prog_rate)
{
    kal_wsprintf(text, "%w %d", (WCHAR *)GetString(STR_BT_BPP_PRINTING), prog_rate);
    mmi_wcscat(text, L"%");
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_alert(U32 type, MMI_ID gid, MMI_STR_ID str_id, U32 event)
{
    WCHAR *text;

    text = (WCHAR *)GetString(str_id);

    if (type == 'intr')
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, event, text);
    else
    {
        if (gid)
        {
            if (mmi_frm_group_is_in_active_serial(gid))
                mmi_popup_display(text, event, NULL);
            else
                mmi_popup_display_simple(text, event, gid, NULL);
        }
        else
            mmi_popup_display(text, event, NULL);
    }
}

static void bpp_set_app_data(bpp_inst_struct *inst, bt_print_data_struct *data)
{
    bpp_app_data_struct *app_data = &inst->app.data;
    bpp_obj_desc_struct *obj = &inst->obj;

    if (!data)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_MMI_SET_DATA, inst, inst->app.type, 0); 
        app_data->type = 'none';
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, BPP_MMI_SET_DATA, inst, inst->app.type, data->size);

    app_data->content_type = data->content_type;
    app_data->size = data->size;
    app_data->more = data->more;

    if (app_data->type == 'file' && data->type != 'file')
    {
        free_ctrl_buffer(app_data->u.file);
        app_data->u.file = NULL;
    }

    switch (data->type) {
    case 'file':
        {
            S32 l_path = mmi_wcslen(data->u.file)+1;
            
            if (!app_data->u.file)
                app_data->u.file = get_ctrl_buffer(2 * l_path);
            else
            {
                if (mmi_wcslen(app_data->u.file) + 1 < l_path)
                {
                    free_ctrl_buffer(app_data->u.file);
                    app_data->u.file = get_ctrl_buffer(2 * l_path);
                }
            }
            mmi_wcscpy(app_data->u.file, data->u.file);
        }
        break;

    case 'buff':

        app_data->u.buff = data->u.buff;

        break;
    default:
        break;
    }
    
    app_data->type = data->type;

#ifdef BPP_APP_DEBUG
{
    if (data->content_type == BT_PRINT_CONTENT_XHTML && data->type == 'file')
    {
        static U32 seq;
        WCHAR path[64];

        kal_wsprintf(path, "%c\\@bpp\\%08X_%d.xhtml", 
            SRV_FMGR_PUBLIC_DRV, inst->app.type, seq++);
        
        FS_Move(app_data.u.file, path, FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0);
    }
}
#endif
    if (app_data->content_type == BT_PRINT_CONTENT_IMAGE)
    {
        S32 width, height;
        U16 type;

        obj->path = app_data->u.file;
        gdi_image_get_dimension_file((S8 *)obj->path, &width, &height);

        obj->real_size.width = width;
        obj->real_size.height = height;

        type = gdi_image_get_type_from_file((S8 *)obj->path);

        switch (type) {
        case GDI_IMAGE_TYPE_JPG :
        case GDI_IMAGE_TYPE_JPG_FILE :

            obj->type = BPP_IMAGE_JPEG;

            break;

        case GDI_IMAGE_TYPE_GIF :
        case GDI_IMAGE_TYPE_GIF_FILE :

            obj->type = BPP_IMAGE_GIF;

            break;
            
        case GDI_IMAGE_TYPE_BMP :
        case GDI_IMAGE_TYPE_BMP_FILE :

            obj->type = BPP_IMAGE_BMP;

            break;
            
        case GDI_IMAGE_TYPE_PNG :
        case GDI_IMAGE_TYPE_PNG_FILE:

            obj->type = BPP_IMAGE_PNG;

            break;
            
        case GDI_IMAGE_TYPE_WBMP :
        case GDI_IMAGE_TYPE_WBMP_FILE:

            obj->type = BPP_IMAGE_WBMP;

            break;
            
        case GDI_IMAGE_TYPE_SVG :
        case GDI_IMAGE_TYPE_SVG_FILE:

            obj->type = BPP_IMAGE_SVG;

            break;

        default:

            obj->type = 0;

            break;
        }
    }
}

static S32 bpp_compatible_image(bpp_inst_struct *inst, U32 img_type)
{
    PrinterAttribute attr;

    srv_bpp_get_info(inst->h_srv, inst->job_id, &attr, BPP_INFO_PRINTER_ATTR);

    if (attr.imageType & img_type)
        return 1;

    return 0;
}

static CHAR * get_image_mime(U32 img_type)
{
    S32 i;
    
    for (i = 0; i < ArrayCount(ImageMime); i++)
    {
        if (img_type & (1 << i))
            return (CHAR *)ImageMime[i];
    }

    return (CHAR *)ImageMime[0];
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 bpp_is_ready(void)
{
    srv_bt_cm_power_status_enum status = srv_bt_cm_get_power_status();

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BPP_IS_READY, p_cntx->flags, status);
    
    if (status == SRV_BT_CM_POWER_SWITCHING_ON ||
        status == SRV_BT_CM_POWER_SWITCHING_OFF)
    {
        bpp_alert('std', 0, STR_BPP_BUSY, MMI_EVENT_FAILURE);
        return 0;
    }
    
#ifdef __MMI_BT_AUTO_POWER_SWITCH__
    if (p_cntx->flags & FLAG_AUTO_ON)
    {
        bpp_alert('std', 0, STR_BPP_BUSY, MMI_EVENT_FAILURE);
        return 0;
    }
#endif

    if (p_cntx->inst)
    {
        bpp_alert('std', 0, STR_BPP_BUSY, MMI_EVENT_FAILURE);
        return 0;
    }

    if (!mmi_bt_is_permission(MMI_TRUE))
        return 0;
    
    return 1;
}

/*****************************************************************************
 * FUNCTION
 *  bpp_adjust_dimension
 * DESCRIPTION
 *    
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 adjust_dimension(bpp_dimension *obj, bpp_dimension *box, U32 b_rotate)
{
    U32 w_obj = obj->width, h_obj = obj->height;
    U32 w_box = box->width, h_box = box->height;
    double box_ratio, obj_ratio;
    S32 rotate = 0;

    if (w_obj <= w_box && h_obj <= h_box)
        return 0;

    if (w_obj <= h_box && h_obj <= w_box && b_rotate)
    {
        box->width = h_box;
        box->height = w_box;
        return 1;
    }

    if (((w_box > h_box && w_obj < h_obj) || 
        (w_box < h_box && w_obj > h_obj)) &&
        b_rotate)
    {
        w_box = box->height;
        h_box = box->width;

        rotate = 1;
    }
    
    box_ratio = (double)w_box / (double)h_box;
    obj_ratio = (double)w_obj / (double)h_obj;
    
    if (box_ratio <= obj_ratio)
    {
        obj->width = w_box;
        obj->height = w_box * h_obj / w_obj;
        if (!obj->height)
            obj->height = 1;
    }
    else
    {
        obj->width = h_box * w_obj / h_obj;
        obj->height = h_box;
        if (!obj->width)
            obj->width = 1;
    }

    return rotate;
}

static S32 max_dimension(bpp_dimension *max, bpp_dimension *obj, bpp_dimension *box)
{
    U32 w_obj = obj->width, h_obj = obj->height;
    U32 w_box = box->width, h_box = box->height;
    double box_ratio, obj_ratio;
    S32 rotate = 0;

    box_ratio = (double)w_box / (double)h_box;
    obj_ratio = (double)w_obj / (double)h_obj;
    
    if (box_ratio <= obj_ratio)
    {
        max->width = w_box;
        max->height = w_box * h_obj / w_obj;
        if (!max->height)
            max->height = 1;
    }
    else
    {
        max->width = h_box * w_obj / h_obj;
        max->height = h_box;
        if (!max->width)
            max->width = 1;
    }

    return rotate;
}


/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static bpp_inst_struct *bpp_new_inst(bpp_app_info_struct *app)
{
    bpp_inst_struct *inst = get_ctrl_buffer(sizeof(*inst));
    bpp_page_config_struct *page = &inst->app.page;

    memset(inst, 0, sizeof(*inst));

    inst->magic = BPP_MAGIC_NUMBER;
    inst->app.type = app->type;
    inst->app.gid = app->gid;
    inst->app.option = app->option;
    inst->app.data.type = 'none';
    
    switch (app->type) {
    case 'imag':

        memset(page, 0, sizeof(*page));
        page->l_margin = page->t_margin = 1;

        break;

    case 'text':

        page->l_margin = page->r_margin = 5;
        page->b_margin = 5;
        page->t_margin = 3;

        break;

    case 'cnta':
    case 'clnd':
    case 'msag':
    case 'mail':

        page->l_margin = page->r_margin = 6;
        page->t_margin = page->b_margin = 6;

        break;

    default:
        break;
    }

    {
        bpp_inst_struct *p;
        if (p_cntx->inst)
        {
            for (p = p_cntx->inst; p->next; p = p->next);
            p->next = inst;
        }
        else
        {
            p_cntx->inst = inst;
        }
    }

    return inst;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_del_inst(bpp_inst_struct *inst)
{
    bpp_inst_struct *p, *q;
    
    if (!inst || !p_cntx->inst) return;

    if (p_cntx->inst == inst)
        p_cntx->inst = inst->next;
    else
    {
        for (p = p_cntx->inst->next, q = p_cntx->inst; p; q = p, p = p->next)
        {
            if (p == inst)
            {
                q->next = p->next;
                break;
            }
        }
    }

    if (inst->app.data.type == 'file' &&
        inst->app.data.u.file)
        free_ctrl_buffer(inst->app.data.u.file);

    bpp_del_preview(inst);
    bpp_del_setting(inst);

    free_ctrl_buffer(inst);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static bpp_inst_struct *bpp_find_inst(BppHandle h_srv)
{
    bpp_inst_struct *p;

    for (p = p_cntx->inst; p; p = p->next)
    {
        if (p->h_srv == h_srv)
            return p;
    }

    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void bpp_get_dev_name(WCHAR *buff, PrinterAddr *addr)
{
    WCHAR name[BPP_MAX_DEV_NAME+1];
    
    srv_bt_cm_get_dev_name(addr, sizeof(name), (U8 *)name);
    mmi_chset_utf8_to_ucs2_string((U8 *)buff, sizeof(name), (U8 *)name);
}

static U32 bpp_conv_result(U32 srv_result)
{
    U32 result;

    switch (srv_result) {
    case BPP_E_NONE:
        result = E_OK;
        break;
        
    case BPP_E_GENERAL:
        result = E_FAIL;
        break;
        
    case BPP_E_REQ_CANCELLED:
    case BPP_E_USER_ABORT:
        result = E_CANCEL;
        break;
        
    case BPP_E_LINK_BROKEN:
        result = E_LINK_DISC;
        break;

    case BPP_E_OP_BUSY:
        result = E_BUSY;
        break;
        
    case BPP_E_SCO_REJECT:
    case BPP_E_INVALID_PARA:
    case BPP_E_INVALID_DATA:
    default:        
        result = E_FAIL;
        break;
    }

    return result;
}

static WCHAR *bpp_default_app_file(bpp_inst_struct *inst)
{
    static WCHAR path[BPP_MAX_FILE_PATH];
    static U8 seq = 0;

    kal_wsprintf(path, "%c:\\@bpp\\%08X_%02X.xhtml", 
        BPP_STORAGE_DRIVE, inst->app.type, seq++);

    return path;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bt_printing_set_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 bpp_flag_count(U64 num)
{
    S32 count;

    for (count = 0; num; count++)
        num = num & (num-1);

    return (U8)count;
}

static S32 bpp_apply_app_style(bpp_inst_struct *inst, void *xhtml)
{
    S32 i, count, flag = 0;
    const xhtml_rule_struct **rules;
    
    switch (inst->app.type) {
    case BT_PRINT_IMAGE:

        rules = ImageStyleRules;
        count = ArrayCount(ImageStyleRules);

        break;

    case BT_PRINT_TEXT:

        rules = TextStyleRules;
        count = ArrayCount(TextStyleRules);

        break;

    case BT_PRINT_CONTACT:
    
        rules = ContactStyleRules;
        count = ArrayCount(ContactStyleRules);
    
        break;
        
    case BT_PRINT_CALENDAR:
    
        rules = CalendarStyleRules;
        count = ArrayCount(CalendarStyleRules);
    
        break;

    case BT_PRINT_MESSAGE:
    
        rules = MessageStyleRules;
        count = ArrayCount(MessageStyleRules);
    
        break;

    case BT_PRINT_EMAIL:
    
        rules = MailStyleRules;
        count = ArrayCount(MailStyleRules);
    
        break;

    default:
        return 0;
    }

    for (i = 0; i < count; i++)
    {
        if (rules[i] == &SysBottomRule)
        {
            flag = 1;
            break;
        }
    }

    for (i = 0; i < count; i++)
    {
        if (rules[i] == &SysPageRule)
        {
            bpp_apply_page_style(xhtml, &inst->page);
            if (!flag)
                bpp_xhtml_rule_end(xhtml);
        }
        else if (rules[i] == &SysTopRule)
            bpp_apply_top_style(xhtml, &inst->page);
        else if (rules[i] == &SysBottomRule)
        {
            bpp_apply_bottom_style(xhtml, &inst->page);
            if (flag)
                bpp_xhtml_rule_end(xhtml);
        }
        else if (rules[i] == &TextClassRule)
            bpp_apply_text_class_style(xhtml, &inst->page);
        else
            bpp_xhtml_style_rule(xhtml, rules[i], 1);
    }

    return 1;
}

static S32 bpp_apply_page_style(void *xhtml, bpp_page_struct *page)
{
    xhtml_rule_struct rule;
    CHAR buff[128], *p_buff = buff;
    S32 i, len, retval;

    xhtml_prop_struct *props = get_ctrl_buffer(sizeof(PageProps));
    
    for (i = 0; i < ArrayCount(PageProps); i++)
    {
        const xhtml_prop_struct *p = &PageProps[i];
    
        props[i].name = p->name;
    
        if (strcmp(p->name, XHTML_PROP_SIZE) == 0)
        {
            if (page->rotate)
                len = sprintf(p_buff, p->value, page->height, page->width);
            else
                len = sprintf(p_buff, p->value, page->width, page->height);
        }
        else if (strcmp(p->name, XHTML_PROP_MARGIN_LEFT) == 0)
        {
            len = sprintf(p_buff, p->value, page->margin.left);
        }
        else if (strcmp(p->name, XHTML_PROP_MARGIN_TOP) == 0)
        {
            len = sprintf(p_buff, p->value, page->margin.top);
        }
        else if (strcmp(p->name, XHTML_PROP_MARGIN_RIGHT) == 0)
        {
            len = sprintf(p_buff, p->value, page->margin.right);
        }
        else if (strcmp(p->name, XHTML_PROP_MARGIN_BOTTOM) == 0)
        {
            len = sprintf(p_buff, p->value, page->margin.bottom);
        }
        else
        {
            props[i].value = p->value;
            continue;
        }
    
        props[i].value = p_buff;
        p_buff += len+1;
    }
    rule = SysPageRule;
    rule.props = props;
    rule.prop_count = ArrayCount(PageProps);

    retval = bpp_xhtml_rule_begin(xhtml, &rule);
    
    free_ctrl_buffer(props);

    return retval;
}

static S32 bpp_apply_top_style(void *xhtml, bpp_page_struct *page)
{
    xhtml_rule_struct rule;
    CHAR buff[128], *p_buff = buff;
    S32 i, len, retval;

    xhtml_prop_struct *props = get_ctrl_buffer(sizeof(TopProps));
    
    for (i = 0; i < ArrayCount(TopProps); i++)
    {
        const xhtml_prop_struct *p = &TopProps[i];
    
        props[i].name = p->name;
    
        if (strcmp(p->name, XHTML_PROP_CONTENT) == 0)
        {
            len = sprintf(p_buff, p->value, PageHeader);
        }
        else
        {
            props[i].value = p->value;
            continue;
        }
    
        props[i].value = p_buff;
        p_buff += len+1;
    }
    rule = SysTopRule;
    rule.props = props;
    rule.prop_count = ArrayCount(TopProps);

    retval = bpp_xhtml_style_rule(xhtml, &rule, 1);
    
    free_ctrl_buffer(props);

    return retval;
}

static S32 bpp_apply_bottom_style(void *xhtml, bpp_page_struct *page)
{
    xhtml_rule_struct rule;
    CHAR buff[128], *p_buff = buff;
    S32 i, len, retval;

    xhtml_prop_struct *props = get_ctrl_buffer(sizeof(BottomProps));
    
    for (i = 0; i < ArrayCount(BottomProps); i++)
    {
        const xhtml_prop_struct *p = &BottomProps[i];
    
        props[i].name = p->name;
    
        if (strcmp(p->name, XHTML_PROP_CONTENT) == 0)
        {
            len = sprintf(p_buff, p->value, PageFooter);
        }
        else if (strcmp(p->name, XHTML_PROP_WIDTH) == 0)
        {
            len = sprintf(p_buff, p->value, page->width);
        }
        else
        {
            props[i].value = p->value;
            continue;
        }
    
        props[i].value = p_buff;
        p_buff += len+1;
    }
    rule = SysBottomRule;
    rule.props = props;
    rule.prop_count = ArrayCount(BottomProps);

    retval = bpp_xhtml_style_rule(xhtml, &rule, 1);
    
    free_ctrl_buffer(props);

    return retval;
}

static S32 bpp_apply_text_class_style(void *xhtml, bpp_page_struct *page)
{
    xhtml_rule_struct rule;
    CHAR buff[128], *p_buff = buff;
    S32 i, len, retval;

    xhtml_prop_struct *props = get_ctrl_buffer(sizeof(TextClassProps));
    
    for (i = 0; i < ArrayCount(TextClassProps); i++)
    {
        const xhtml_prop_struct *p = &TextClassProps[i];
    
        props[i].name = p->name;
    
        if (strcmp(p->name, XHTML_PROP_SIZE) == 0)
        {
            len = sprintf(p_buff, p->value, page->width, page->height);
        }
        else
        {
            props[i].value = p->value;
            continue;
        }
    
        props[i].value = p_buff;
        p_buff += len+1;
    }
    rule = TextClassRule;
    rule.props = props;
    rule.prop_count = ArrayCount(TextClassProps);

    retval = bpp_xhtml_style_rule(xhtml, &rule, 1);

    free_ctrl_buffer(props);

    return retval;
}

static S32 bpp_compose_image(bpp_inst_struct *inst, bt_print_data_struct *store)
{
    xhtml_output_struct output;
    CHAR *version;
    void *xhtml;

    output.type = XHTML_OUT_FILE;
    output.u.file = store->u.file;

    version = cui_bt_printing_xhtml_version((U32)inst);
    
    xhtml = bpp_xhtml_open(version, &output);

    bpp_compose_image_head(xhtml, inst);
    
    bpp_compose_image_body(xhtml, inst);

    store->size = bpp_xhtml_close(xhtml);
    store->content_type = BT_PRINT_CONTENT_XHTML;
    store->type = BT_PRINT_DATA_FILE;
    store->more = MMI_FALSE;

    return E_OK;
}

static S32 bpp_compose_image_head(void *xhtml, bpp_inst_struct *inst)
{
    bpp_xhtml_element_begin(xhtml, XHTML_ELE_HEAD, NULL, 0);
    bpp_xhtml_empty_element(xhtml, XHTML_ELE_TITLE, NULL, 0);

    bpp_xhtml_style_begin(xhtml, NULL);

    cui_bt_printing_style_rules((U32)inst, xhtml);

    bpp_xhtml_style_end(xhtml);

    bpp_xhtml_element_end(xhtml, XHTML_ELE_HEAD);

    return E_OK;
}

static S32 bpp_compose_image_body(void *xhtml, bpp_inst_struct *inst)
{
    bpp_app_data_struct *data = &inst->app.data;
    xhtml_img_attr_struct img_attrs;
    xhtml_attr_struct attr;

    bpp_xhtml_element_begin(xhtml, XHTML_ELE_BODY, NULL, 0);

    attr.name = XHTML_ATTR_ALIGN;
    attr.value = XHTML_LEFT;

    bpp_xhtml_element_begin(xhtml, XHTML_ELE_DIV, &attr, 1);

    bpp_xhtml_element_begin(xhtml, XHTML_ELE_TABLE, NULL, 0);
    bpp_xhtml_element_begin(xhtml, XHTML_ELE_TABLE_ROW, NULL, 0);

    attr.name = XHTML_ATTR_CLASS;
    attr.value = (CHAR *)ImageClass;

    bpp_xhtml_element_begin(xhtml, XHTML_ELE_TABLE_CELL, &attr, 1);

    img_attrs.width = bpp_pixel_to_mm(inst->obj.size.width);
    img_attrs.height = bpp_pixel_to_mm(inst->obj.size.height);
    img_attrs.size = data->size;
    img_attrs.src = data->u.file;
    img_attrs.type = get_image_mime(inst->obj.type);
    bpp_xhtml_image_element(xhtml, &img_attrs);

    bpp_xhtml_element_end(xhtml, XHTML_ELE_TABLE_CELL);

    bpp_xhtml_element_end(xhtml, XHTML_ELE_TABLE_ROW);
    bpp_xhtml_element_end(xhtml, XHTML_ELE_TABLE);

    bpp_xhtml_element_end(xhtml, XHTML_ELE_DIV);

    bpp_xhtml_element_end(xhtml, XHTML_ELE_BODY);

    return E_OK;
}

static S32 bpp_compose_text(bpp_inst_struct *inst, bt_print_data_struct *store)
{
    xhtml_output_struct out;
    void *xhtml;
    CHAR *version;
    xhtml_obj_attr_struct obj;
    xhtml_attr_struct attr;

    out.type = XHTML_OUT_FILE;
    out.u.file = store->u.file;

    version = cui_bt_printing_xhtml_version((U32)inst);

    xhtml = bpp_xhtml_open(version, &out);

    bpp_xhtml_element_begin(xhtml, XHTML_ELE_HEAD, NULL, 0);
    
    bpp_xhtml_element_begin(xhtml, XHTML_ELE_TITLE, NULL, 0);
    bpp_xhtml_element_data(xhtml, TextTile);
    bpp_xhtml_element_end(xhtml, XHTML_ELE_TITLE);

    bpp_xhtml_style_begin(xhtml, NULL);

    cui_bt_printing_style_rules((U32)inst, xhtml);

    bpp_xhtml_style_end(xhtml);

    bpp_xhtml_element_end(xhtml, XHTML_ELE_HEAD);

    bpp_xhtml_element_begin(xhtml, XHTML_ELE_BODY, NULL, 0);

    attr.name = XHTML_ATTR_CLASS;
    attr.value = (CHAR *)TextClass;

    bpp_xhtml_element_begin(xhtml, XHTML_ELE_PARA, &attr, 1);

    obj.src = inst->app.data.u.file;
    obj.size = inst->app.data.size;
    obj.type = "text/plain";
    
    bpp_xhtml_object_element(xhtml, &obj);

    bpp_xhtml_element_end(xhtml, XHTML_ELE_PARA);

    bpp_xhtml_element_end(xhtml, XHTML_ELE_BODY);

    store->size = bpp_xhtml_close(xhtml);

    store->content_type = BT_PRINT_CONTENT_XHTML;
    store->type = BT_PRINT_DATA_FILE;
    store->more = MMI_FALSE;

    return E_OK;
}

mmi_ret mmi_bpp_card_plug_out_hdlr(mmi_event_struct *param)
{
    bpp_inst_struct *inst;
    
    inst = (bpp_inst_struct *)mmi_frm_group_get_user_data(GRP_ID_BT_BPP);
    if (inst != NULL)
    {
        if (inst->preview != NULL)
        {
            if (inst->app.data.u.file[0] == SRV_FMGR_CARD_DRV)
            mmi_frm_scrn_close(GRP_ID_BT_BPP, SCR_BPP_SP_PREVIEW);
        }
    }
    return MMI_RET_OK;
}

#endif /* __MMI_BPP_SUPPORT__ */
