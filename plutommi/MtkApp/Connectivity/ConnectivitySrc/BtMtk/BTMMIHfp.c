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
 * BTMMIHFP.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for HFP/HSP application.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifdef __MMI_HFP_SUPPORT__
/***************************************************************************** 
* Included files
*****************************************************************************/
#include "AlertScreen.h"

#include "BtcmSrvGprot.h"
#include "BTMMIScrGprots.h"
#include "BTMMIHfpGprots.h"
#include "BTMMIHfp.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_popup.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "CustDataRes.h"
#include "custom_events_notify.h"
#include "string.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "Unicodexdcl.h"
#include "NotificationGprot.h"
#ifdef __MMI_BT_DIALER_SUPPORT__
#include "nvram_common_defs.h"
#endif
/***************************************************************************** 
* External Variable
*****************************************************************************/
#ifndef __MMI_BTBOX_NOLCD__
/***************************************************************************** 
* Globol Variable
*****************************************************************************/
static mmi_btaud_cntx_struct g_mmi_btaud_cntx;
static mmi_btaud_cntx_struct *btaud_cntx = &g_mmi_btaud_cntx;

/***************************************************************************** 
* Function
*****************************************************************************/
static MMI_RET btaud_prog_entry(mmi_scrn_essential_struct *info)
{
    MMI_ID text;

    if (mmi_frm_scrn_enter(
            info->group_id, info->scrn_id,
            NULL, (FuncPtr)btaud_prog_entry,
            MMI_FRM_FULL_SCRN))
    {
        mmi_btaud_cntx_struct *cntx = (mmi_btaud_cntx_struct *)info->user_data;

        if (cntx->flags & FLAG_RELEASE)
            text = STR_BT_RELEASING;
        else
            text = STR_GLOBAL_CONNECTING;
        
#ifndef __MMI_BT_DIALER_SUPPORT__
        ShowCategory66Screen(
            text,
            GetRootTitleIcon(MENU_CONN_BT_MAIN),
            0, 0, 0, 0, 
            (U8 *)GetString(text),
            mmi_get_event_based_image(MMI_EVENT_PROGRESS),
            NULL);
#else
        ShowCategory163Screen(
            0,
            0,
            0,
            0,
            (UI_string_type)GetString(text),
            mmi_get_event_based_image(MMI_EVENT_PROGRESS),
            NULL);

#endif
    }

    return MMI_RET_OK;
}


void mmi_btaud_init(void)
{
    U32 events = BTAUD_EV_ATTACH_IND |
                 BTAUD_EV_ATTACH_FAIL |
                 BTAUD_EV_DETACH_IND |
                 BTAUD_EV_SWITCH_IND |
                 BTAUD_EV_SWITCH_FAIL |
                 BTAUD_EV_CHNL_UPDATE |
                 BTAUD_EV_ATTACH_REQ |
                 BTAUD_EV_VOLUME_IND |
                 BTAUD_EV_ATTACH_ABORT;
    
    memset(btaud_cntx, 0, sizeof(*btaud_cntx));

    srv_btaud_init();

    btaud_cntx->srv_hd = srv_btaud_open(BTAUD_LEVEL_ADMIN, BTAUD_CHNL_ANY);
    srv_btaud_set_notify(btaud_cntx->srv_hd, events,(BtAudNotify)btaud_notify_hdlr, NULL);
}

void mmi_btaud_deinit(void)
{
    srv_btaud_close(btaud_cntx->srv_hd);
    btaud_cntx->srv_hd = 0;
    srv_btaud_deinit();
}

MMI_BOOL mmi_btaud_attach(MMI_ID group_id, srv_bt_cm_bt_addr *addr)
{
    MMI_ID text;
    btaud_device_info *info = &btaud_cntx->dev_info;

    if (!addr)
    {
        text = STR_BT_NO_DEFAULT_HEADSET;
        goto Attach_Fail;
    }

#ifdef __MMI_BT_AUTHORIZE__
    if (srv_bt_cm_dev_property_check(addr, SRV_BT_CM_DEV_PROPERTY_BLOCK))
    {
        text = STR_BT_DEVICE_BLOCKED;
        goto Attach_Fail;
    }
#endif

    if (btaud_cntx->dev_info.chnls &&
        (info->addr.lap != addr->lap ||
         info->addr.uap != addr->uap ||
         info->addr.nap != addr->nap))
    {
        btaud_cntx->flags |= FLAG_RELEASE;
        btaud_cntx->pend_dev = *addr;

        srv_btaud_detach(btaud_cntx->srv_hd);
    }
    else
    {
        if (!srv_btaud_attach(btaud_cntx->srv_hd, addr))
        {
            text = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
            goto Attach_Fail;
        }
    }

    btaud_cntx->gid = mmi_frm_group_create_ex(
                        group_id ? group_id : GRP_ID_ROOT,
                        GRP_ID_AUTO_GEN,
                        btaud_group_proc,
                        btaud_cntx,
                        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if (btaud_cntx->flags & FLAG_RELEASE)
    {
        mmi_frm_scrn_first_enter(
            btaud_cntx->gid,
            SCR_HF_RELEASING,
            (FuncPtr)btaud_prog_entry,
            btaud_cntx);
    }
    else
    {
        mmi_frm_scrn_first_enter(
            btaud_cntx->gid,
            SCR_HF_CONNECTING,
            (FuncPtr)btaud_prog_entry,
            btaud_cntx);
    }

    return MMI_TRUE;

Attach_Fail:
    mmi_popup_display_ext(text, MMI_EVENT_FAILURE, NULL);
    return MMI_FALSE;
}

static MMI_RET btaud_group_proc(mmi_event_struct *evt)
{
    mmi_btaud_cntx_struct *cntx = (mmi_btaud_cntx_struct *)evt->user_data;

    switch (evt->evt_id) {
    case EVT_ID_GROUP_GOBACK_IN_END_KEY:
    case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:

        srv_btaud_abort(cntx->srv_hd);
        mmi_frm_scrn_close(cntx->gid, SCR_HF_CONNECTING);

        break;

    case EVT_ID_GROUP_DEINIT:
        cntx->gid = GRP_ID_INVALID;
        break;
    }

    return MMI_RET_OK;
}

static void btaud_authorize_rsp(srv_bt_cm_bt_addr *bt_addr, U32 prof_id, U32 result)
{
    if (result)
        srv_btaud_accept(btaud_cntx->srv_hd);
    else
        srv_btaud_reject(btaud_cntx->srv_hd);
}


static S32 btaud_notify_hdlr(U32 event, U32 arg, void *user_data)
{
    switch (event) {
    case BTAUD_EV_ATTACH_REQ:
        
        btaud_auth_ind();
        
        break;

    case BTAUD_EV_ATTACH_ABORT:
        
        btaud_auth_aborted();
        
        break;

    case BTAUD_EV_ATTACH_IND:
        
        btaud_attach_ind(arg);
        
        break;

    case BTAUD_EV_ATTACH_FAIL:
        
        btaud_attach_fail();
        
        break;

    case BTAUD_EV_CHNL_UPDATE:
        
        btaud_chnl_update(arg);
        
        break;

    case BTAUD_EV_DETACH_IND:
        
        btaud_detach_ind(arg);
        
        break;

    case BTAUD_EV_SWITCH_IND:
        break;

#ifdef __BT_SPK_VOL_CONTROL__
    case BTAUD_EV_VOLUME_IND:
        
        mdi_audio_sync_volume_from_bt((U8)arg);
        
        break;
#endif

    default:
        break;
    }

    return 0;
}

static void btaud_auth_ind(void)
{
    btaud_device_info info;

    srv_btaud_get_device_info(BTAUD_CHNL_ANY, &info);

    mmi_bt_authorize_ind_notify(
        NULL,
        &info.addr,
        SRV_BT_CM_HFG_PROFILE_UUID,
        (void *)btaud_authorize_rsp);
}

static void btaud_auth_aborted(void)
{
    mmi_bt_authorize_screen_close(SRV_BT_CM_HFG_PROFILE_UUID);
}

static void btaud_attach_ind(U32 chnl)
{
    srv_btaud_get_device_info(chnl, &btaud_cntx->dev_info);
    btaud_attach_done(MMI_TRUE);
}

static void btaud_attach_fail(void)
{
    btaud_attach_done(MMI_FALSE);
}

static void btaud_chnl_update(U32 chnls)
{
}

static void btaud_detach_ind(U32 passive)
{
    btaud_cntx->dev_info.chnls = 0;
    
    if (btaud_cntx->flags & FLAG_RELEASE)
    {
        btaud_cntx->flags &= ~FLAG_RELEASE;

        if (btaud_cntx->gid)
        {
            if (srv_btaud_attach(btaud_cntx->srv_hd, &btaud_cntx->pend_dev))
                mmi_frm_scrn_first_enter(
                    btaud_cntx->gid,
                    SCR_HF_CONNECTING,
                    (FuncPtr)btaud_prog_entry,
                    btaud_cntx);
            else
                mmi_popup_display_ext(
                    STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                    MMI_EVENT_FAILURE, NULL);
            mmi_frm_scrn_close(btaud_cntx->gid, SCR_HF_RELEASING);
        }
    }
#ifndef __MMI_BT_DIALER_SUPPORT__
    else if (passive)
    {
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_FAILURE,
            (WCHAR *)GetString(STR_BT_AUDIO_DISC_ED));
    }
  #endif
}

static void btaud_attach_done(MMI_BOOL result)
{
#ifdef __MMI_BT_DIALER_SUPPORT__
	srv_bt_cm_dev_struct* dev_p ;
	WCHAR string[NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE] = {0};
	btaud_device_info *info = &btaud_cntx->dev_info;
	dev_p = (srv_bt_cm_dev_struct*)srv_bt_cm_get_dev_info(&info->addr);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_BT_CONN_BTAUD_ATTACH_DONE, result);

    if (result)
    {
		mmi_bt_show_dialor_conn_success((srv_bt_cm_dev_struct *)srv_bt_cm_get_dev_info(&info->addr));
		mmi_bt_dialer_set_headset_flag(MMI_TRUE);
		srv_bt_cm_set_dev_link_state(&info->addr,MMI_TRUE);
    }
    else
    {
    	mmi_chset_utf8_to_ucs2_string(
					(kal_uint8*)string,
					(SRV_BT_CM_BD_UCS2_NAME_LEN * 2),
					(kal_uint8*)dev_p->name);
	    mmi_wcscat((WCHAR*)string, (WCHAR*)GetString(STR_BT_CONN_FAILED));
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR*)string);
    }

#else

    if (result)
    {
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_SUCCESS, (WCHAR *)GetString(STR_BT_AUDIO_CONN_ED));
    }
    else
    {
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR *)GetString(STR_BT_CONN_FAILED));
	}

#endif/*__MMI_BT_DIALER_SUPPORT__*/
    if (btaud_cntx->gid)
    {
        mmi_frm_scrn_close(btaud_cntx->gid, SCR_HF_CONNECTING);
    }
}
#else
MMI_BOOL mmi_btaud_attach(MMI_ID group_id, srv_bt_cm_bt_addr *addr)
{
    return MMI_FALSE;
}
void mmi_btaud_deinit(void)
{
}
void mmi_btaud_init(void)
{
}
#endif /* __MMI_BTBOX_NOLCD__ */
#endif /* __MMI_HFP_SUPPORT__ */ 



