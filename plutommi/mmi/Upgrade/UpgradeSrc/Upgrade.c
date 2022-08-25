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
 * Upgrade.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file implements application functions for Upgrade feature.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VPP_UPGRADE__

#include "GlobalResDef.h"
#include "CustDataRes.h"
#include "Gui_typedef.h"
#include "wgui_categories_popup.h"
#include "CommonScreensResDef.h"
#include "AlertScreen.h"

#ifdef __MMI_NCENTER_SUPPORT__
#include "vsrv_ncenter.h"
#endif

#ifdef __MMI_DOWNLOAD_AGENT__
#include "DLAgentSrvGprot.h"
#endif

#include "UpgradeSrvGprot.h"
#include "mmi_rp_srv_upgrade_def.h"

#include "mmi_rp_app_upgrade_def.h"


/**************************************************************
 * MARCO                                                      * 
 **************************************************************/


/**************************************************************
 * Structure Declaration                                      *
 **************************************************************/
typedef struct
{
    U32 count[SRV_UPGRADE_ORIGINATOR_ALL];
    MMI_BOOL notify[SRV_UPGRADE_ORIGINATOR_ALL];
} mmi_upgrade_context_struct;


/**************************************************************
 * Static Variables Defination                                *
 **************************************************************/
static mmi_upgrade_context_struct mmi_upgrade_context;
U32 g_mmi_upgrade_context_count;

/**************************************************************
 * Static Function Declaration                                *
 **************************************************************/
static void mmi_upgrade_check_notify(void);
static mmi_ret mmi_upgrade_comfirm_proc(mmi_event_struct *evt);

#ifdef __MMI_NCENTER_SUPPORT__
void mmi_upgrade_ncenter_event_callback(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize);

#endif


/**************************************************************
 * Function Defination                                        *
 **************************************************************/
mmi_ret mmi_upgrade_download_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_UPGRADE_DOWNLOAD_REQ:
        {
            srv_upgrade_evt_download_req_struct *req = (srv_upgrade_evt_download_req_struct *)evt;
            mmi_upgrade_context.count[req->info->originator] = req->info->count;
            mmi_upgrade_context.notify[req->info->originator] = MMI_TRUE;

            mmi_upgrade_check_notify();
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}


void mmi_upgrade_check_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_NCENTER_SUPPORT__
    vsrv_ngroup_handle ghandle;
    vsrv_notification_handle nhandle;
    mmi_image_src_struct icon;
    mmi_frm_nmgr_alert_struct alert_info;

#endif

    WCHAR string[30];
    U32 i;
    U32 total = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_UPGRADE_ORIGINATOR_ALL; i ++)
    {
        if (mmi_upgrade_context.notify[i])
        {
            total += mmi_upgrade_context.count[i];
            mmi_upgrade_context.notify[i] = MMI_FALSE;
        }
    }
	g_mmi_upgrade_context_count = total;
    if (total > 0)
    {
    #ifdef __MMI_NCENTER_SUPPORT__
        ghandle = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, APP_UPGRADE);
        vsrv_ncenter_set_ngroup_title_str(ghandle, (WCHAR *)GetString(STR_ID_UPGRADE_APP));

        nhandle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT, ghandle, 0);

        icon.type = MMI_IMAGE_SRC_TYPE_RES_ID;
        icon.data.res_id = IMG_ID_UPGRADE_NC_ICON;
        vsrv_ncenter_set_notification_icon(nhandle, icon);

        if (total > 1)
        {
            kal_wsprintf(string, "%d %w", total, GetString(STR_ID_UPGRADE_NEW_UPGRADES));
        }
        else
        {
            kal_wsprintf(string, "%d %w", total, GetString(STR_ID_UPGRADE_NEW_UPGRADE));
        }
        vsrv_ncenter_set_notification_maintext_str(nhandle, string);

        vsrv_ncenter_set_notification_subtext_str(nhandle, (WCHAR *)GetString(STR_ID_UPGRADE_TAP_TO_DOWNLOAD));

        vsrv_ncenter_set_notification_intent_callback(nhandle, mmi_upgrade_ncenter_event_callback, NULL, 0);
        vsrv_ncenter_notify_notification(nhandle);

        memset(&alert_info, 0x00, sizeof(mmi_frm_nmgr_alert_struct));
        alert_info.app_id = APP_UPGRADE;
        alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK;
        alert_info.behavior_mask = FORCE_ICON_ONLY;
        alert_info.status_bar_icon_para.icon_id = STATUS_ICON_UPGRADE;

        mmi_frm_nmgr_alert(&alert_info);

    #else
        mmi_confirm_property_struct arg;
        mmi_confirm_property_init(&arg, CNFM_TYPE_OKCANCEL);
        arg.callback = mmi_upgrade_comfirm_proc;
        arg.f_enter_history = 1;
        
        if (total > 1)
        {
            kal_wsprintf(string, "%d %w, %w", total, GetString(STR_ID_UPGRADE_NEW_UPGRADES), GetString(STR_ID_UPGRADE_DOWNLOAD));
        }
        else
        {
            kal_wsprintf(string, "%d %w, %w", total, GetString(STR_ID_UPGRADE_NEW_UPGRADE), GetString(STR_ID_UPGRADE_DOWNLOAD));
        }
        
        mmi_confirm_display(string, MMI_EVENT_QUERY, &arg);

    #endif
    }
}


#ifdef __MMI_NCENTER_SUPPORT__
static void mmi_upgrade_clear_status_icon(void)
{
    NMGR_HANDLE ngmr_handle = mmi_frm_nmgr_compose_alert_handle(APP_UPGRADE, MMI_EVENT_DEFAULT, STATUS_ICON_UPGRADE);
    mmi_frm_nmgr_alert_cancel(ngmr_handle);
}


void mmi_upgrade_ncenter_event_callback(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 total = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (intent.type)
    {
        case VSRV_NINTENT_TYPE_LAUNCH:
            srv_upgrade_download(SRV_UPGRADE_ORIGINATOR_ALL);
            mmi_upgrade_clear_status_icon();
        #ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
            srv_da_display_download_list();
        #endif
            break;

        case VSRV_NINTENT_TYPE_CLEAR:
            srv_upgrade_cancel(SRV_UPGRADE_ORIGINATOR_ALL);
            mmi_upgrade_clear_status_icon();
            break;
	case VSRV_NINTENT_TYPE_LANGUAGE_CHANGED:
		{
			vsrv_ngroup_handle ghandle;
			WCHAR string[30];
			ghandle = vsrv_ncenter_query_ngroup(APP_UPGRADE);

			if(ghandle == NULL)	  
			ghandle = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, APP_UPGRADE);
			vsrv_ncenter_set_ngroup_title_str(ghandle, (WCHAR *)GetString(STR_ID_UPGRADE_APP));
			total = g_mmi_upgrade_context_count;
		if(total > 0)
		{
			if (total > 1)
			{
				kal_wsprintf(string, "%d %w", total, GetString(STR_ID_UPGRADE_NEW_UPGRADES));
			}
			else
			{
				kal_wsprintf(string, "%d %w", total, GetString(STR_ID_UPGRADE_NEW_UPGRADE));
			}
			vsrv_ncenter_set_notification_maintext_str(nhandle, string);
			vsrv_ncenter_set_notification_subtext_str(nhandle, (WCHAR *)GetString(STR_ID_UPGRADE_TAP_TO_DOWNLOAD));
			vsrv_ncenter_notify_notification(nhandle);
		}
		}

			break;

        case VSRV_NINTENT_TYPE_TERMINATE:
            break;

        default:
            break;
    }
}

#endif


mmi_ret mmi_upgrade_comfirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alter = (mmi_alert_result_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alter->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alter->result)
        {
            case MMI_ALERT_CNFM_OK:
                srv_upgrade_download(SRV_UPGRADE_ORIGINATOR_ALL);
            #ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
                srv_da_display_download_list();
            #endif
                break;

            case MMI_ALERT_CNFM_CANCEL:
                srv_upgrade_cancel(SRV_UPGRADE_ORIGINATOR_ALL);
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}


void mmi_upgrade_test(void)
{
	mmi_upgrade_check_notify();
}

#endif /*__MMI_VPP_UPGRADE__ */
