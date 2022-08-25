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
 *  DmAppOtap.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  DM application over the air provisioning.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "mmi_features.h"
#if defined(SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)
#include "MMIDataType.h"
#include "NotificationGprot.h"
#include "Wgui_categories_util.h"
#include "mmi_frm_input_gprot.h"
#include "AlertScreen.h"
#include "DmAppOtap.h"
#include "DmSrvIprot.h"
#include "mmi_rp_srv_dm_def.h"
#include "TimerEvents.h"
#include "custom_events_notify.h"
#include "GlobalResDef.h"
#include "CcaSrvGprot.h"
#include "mmi_rp_app_cca_def.h"
#include "Wgui_categories_text_viewer.h" // category74
#include "CentralConfigAgentGProt.h"

/****************************************************************************
 * Global Variable
 ****************************************************************************/

/****************************************************************************
 * Static Variable
 ****************************************************************************/

/****************************************************************************
 * Local Function
 ****************************************************************************/
mmi_ret mmi_dm_otap_scrn_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_EXIT:
            mmi_frm_scrn_set_leave_proc(
                GRP_ID_DMAPP_OTA,
                SCR_ID_DM_OTA_PROVISIONING_INFO,
                NULL);
            mmi_frm_scrn_set_leave_proc(
                GRP_ID_DMAPP_OTA,
                SCR_ID_DM_OTA_SERVERID_LIST,
                NULL);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


void mmi_dm_otap_entry_installation_pre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(
        mmi_cca_get_root_group(),
        GRP_ID_DMAPP_OTA,
        mmi_dm_otap_scrn_group_proc,
        (void*)NULL);
    mmi_frm_group_enter(GRP_ID_DMAPP_OTA, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_dm_otap_entry_installation();
}


void mmi_dm_otap_entry_installation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR info1[512] = {0};
    WCHAR info2[512] = {0};
    WCHAR *info = (WCHAR*)subMenuData;
    U8 *gui_buffer;
    S32 curr_valid_num = srv_dm_otap_get_curr_valid_prof_num();
    U8 curr_iter = srv_dm_otap_get_curr_prof_iter();
    U8 *server_id = srv_dm_otap_get_curr_prof_server_id();
    U8 *server_addr = srv_dm_otap_get_curr_prof_server_addr();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    kal_wsprintf(
        info1,
        "%w\n%w%d/%d\n",
        (WCHAR*)GetString(STR_ID_CCA_SYNCMLDM),
        (WCHAR*)GetString(STR_ID_DM_OTA_PROFILE),
        curr_valid_num,
        srv_dm_otap_get_valid_prof_num());

    kal_wsprintf(
        info2,
        "\n%w%s\n%w%s\n",
        GetString(STR_ID_DM_OTA_SERVERID),
        server_id,
        GetString(STR_ID_DM_OTA_SERVER_ADDRESS),
        server_addr);

    if (srv_dm_otap_check_curr_prof_is_to_udpate() == MMI_TRUE)
    {
        kal_wsprintf(
            info,
            "%w%w\n%w",
            info1,
            GetString(STR_ID_CCA_UPDATE_PROFILE),
            info2);
    }
    else
    {
        kal_wsprintf(
            info,
            "%w%w",
            info1,
            info2);
    }
#else /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    kal_wsprintf(
        info,
        "%w: %s\n\n%w%d/%d\n\n%w%s\n\n",
        GetString(STR_ID_CCA_SYNCMLDM),
        server_id,
        GetString(STR_ID_DM_OTA_PROFILE),
        curr_valid_num,
        srv_dm_otap_get_valid_prof_num(),
        GetString(STR_ID_DM_OTA_SERVER_ADDRESS),
        server_addr);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    if (MMI_TRUE == mmi_frm_scrn_enter(
                        GRP_ID_DMAPP_OTA,
                        SCR_ID_DM_OTA_PROVISIONING_INFO,
                        NULL,
                        mmi_dm_otap_entry_installation, 
                        MMI_FRM_FULL_SCRN))
    {
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();

        mmi_frm_scrn_set_leave_proc(
            GRP_ID_DMAPP_OTA,
            SCR_ID_DM_OTA_PROVISIONING_INFO,
            mmi_dm_otap_install_leave_proc);

        ShowCategory74Screen(
            STR_ID_CCA_INSTALL_SETTING,
            IMG_ID_DMUI_MAIN,
            STR_GLOBAL_INSTALL,
            0,
            STR_ID_CCA_SKIP,
            0,
            (U8*)info,
            MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
            gui_buffer);
        SetLeftSoftkeyFunction(mmi_dm_otap_install_prof, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_dm_otap_display_skip_cnf, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_dm_otap_install_prof, KEY_EVENT_UP);
    }
}


mmi_ret mmi_dm_otap_install_leave_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SCRN_GOBACK_IN_END_KEY ||
        evt->evt_id == EVT_ID_SCRN_DELETE_REQ_IN_END_KEY)
    {
        srv_dm_otap_install_prof_app_rsp(SRV_CCA_STATUS_ENDKEY_PRESSED);
    }

    return MMI_RET_ALLOW_CLOSE;
}


void mmi_dm_otap_install_prof(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(GRP_ID_DMAPP_OTA, SCR_ID_DM_OTA_PROVISIONING_INFO);
    srv_dm_otap_install_prof_app_rsp(SRV_CCA_STATUS_OK);
}


void mmi_dm_otap_display_skip_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_cca_ui_common_cancel_with_sg(
        GRP_ID_DMAPP_OTA,
        STR_ID_CCA_SKIP_PROFILE,
        mmi_dm_otap_skip_install);
}


void mmi_dm_otap_skip_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(GRP_ID_DMAPP_OTA);
    srv_dm_otap_install_prof_app_rsp(SRV_CCA_STATUS_SETTING_SKIPPED);
}
#endif /* defined(SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__) */
