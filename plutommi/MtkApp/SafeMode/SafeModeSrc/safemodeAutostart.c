/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *  safemodeAutostart.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements autostart mre app in the safe mode.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_MRE_AUTO_START__)

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "wgui_categories_util.h"
#include "SafeModeSrvGprot.h"
#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "app_datetime.h"
#include "ProfilesSrvGprot.h"
#include "AppMgrSrvGprot.h"
#include "MreAppMgrSrvGprot.h"
#include "MreSrvGprot.h"
#include "globalresdef.h"
#include "alertscreen.h"
#include "commonscreensResdef.h"
#include "mmi_rp_app_safemode_def.h"

extern srv_mre_launch_app_result_enum srv_mre_launch_app_ex(U16 *app_path, srv_mre_launch_app_cb_t app_cb);
/*****************************************************************************
 * Global Variable
 *****************************************************************************/
static mmi_app_package_name_struct *g_autostart_app_list_p = NULL;
static S32 g_autostart_app_num = 0;
static S32 g_autostart_active_app = 0;

/*****************************************************************************
 * Prototype
 *****************************************************************************/
static void mmi_safe_mode_autostart_launch_app_callback(U16 *app_path, srv_mre_launch_app_evt_enum evt);
static mmi_ret mmi_safe_mode_check_autostart_query_confirm_cb(mmi_alert_result_evt_struct *evt);
static void mmi_safe_mode_autostart_launch_app_popup(void);
static void mmi_safe_mode_autostart_launch_app(void);
static void mmi_safe_mode_check_autostart_query_popup();
static mmi_ret mmi_safe_mode_autostart_launch_app_confirm_cb(mmi_alert_result_evt_struct *evt);


/*****************************************************************************
 * Function
 *****************************************************************************/
static void mmi_safe_mode_autostart_launch_app_popup(void)
{
	mmi_confirm_property_struct arg;
	WCHAR str[51]; // popup string limit
	srv_app_info_struct info;
	mmi_ret result;

	if(g_autostart_app_num == g_autostart_active_app)
	{
		OslMfree(g_autostart_app_list_p);
		return;
	}
	memset(str, 0, sizeof(str));
    result = srv_appmgr_get_app_package_info(g_autostart_app_list_p[g_autostart_active_app], &info);

	mmi_ucs2cpy((CHAR*) str, (CHAR*) get_string(STR_ID_SAFE_MODE_QUERY_LAUNCH));
	mmi_wcsncat(str, info.string, 51 - mmi_wcslen(str));

	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	arg.callback = (mmi_proc_func)mmi_safe_mode_autostart_launch_app_confirm_cb;
	arg.f_auto_question_mark = MMI_TRUE;
	arg.f_enter_history = MMI_TRUE;
    mmi_confirm_display(
        	str, 
        	MMI_EVENT_QUERY, 
        	&arg);
}


static mmi_ret mmi_safe_mode_autostart_launch_app_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
	        case MMI_ALERT_CNFM_YES:
	        	mmi_safe_mode_autostart_launch_app();
	        	break;
	        	
	        case MMI_ALERT_CNFM_NO:
	        	g_autostart_active_app++;
	        	mmi_safe_mode_autostart_launch_app_popup();
	        	break;
	        default:
            	break;
        }

    }
    return MMI_RET_OK;
}

void mmi_safe_mode_autostart_launch_app(void)
{
	for(; g_autostart_active_app < g_autostart_app_num; g_autostart_active_app++)
	{
		if(srv_mre_appmgr_get_autostart(g_autostart_app_list_p[g_autostart_active_app]) == 1)
		{
			U16 filepath[SRV_MRE_APPMGR_FILEPATH_LEN];
			srv_mre_launch_app_result_enum ret;

			memset(filepath,0,sizeof(filepath));
			srv_mre_appmgr_get_file_path(g_autostart_app_list_p[g_autostart_active_app], filepath);
			ret = srv_mre_launch_app_ex(filepath, mmi_safe_mode_autostart_launch_app_callback);

			if(ret == SRV_MRE_LAUNCH_APP_SUCCESS)
			{
				break;// wait for callback
			}
			else
			{
				g_autostart_active_app++;
				mmi_safe_mode_autostart_launch_app_popup();
				break;
			}
		}
	};
}

static void mmi_safe_mode_autostart_launch_app_callback(U16 *app_path, srv_mre_launch_app_evt_enum evt)
{
	if(evt == SRV_MRE_LAUNCH_APP_EVT_SUCCESS)
	{
		g_autostart_active_app++;
		mmi_safe_mode_autostart_launch_app_popup();
	}
}

static mmi_ret mmi_safe_mode_check_autostart_query_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
	        case MMI_ALERT_CNFM_YES:
				// find first autostart application.
				for(; g_autostart_active_app < g_autostart_app_num; g_autostart_active_app++)
				{
					if(srv_mre_appmgr_get_autostart(g_autostart_app_list_p[g_autostart_active_app]) == 1)
					{
						break;
					}
				}
				mmi_safe_mode_autostart_launch_app_popup();
	        	break;
	        	
	        case MMI_ALERT_CNFM_NO:
				// free memory if user don't launch application
				OslMfree(g_autostart_app_list_p);
	        	break;
	        default:
            	break;
        }
    }
  return MMI_RET_OK;
}

// Ask user if launch auto start app one by one.
static void mmi_safe_mode_check_autostart_query_popup()
{
	mmi_confirm_property_struct arg;
	
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	arg.callback = (mmi_proc_func)mmi_safe_mode_check_autostart_query_confirm_cb;
	arg.f_enter_history = MMI_TRUE;
    mmi_confirm_display_ext(
        	STR_ID_SAFE_MODE_QUERY_CHECK, 
        	MMI_EVENT_QUERY, 
        	&arg);
}

void mmi_safe_mode_autostart_time_out()
{
	if(srv_safe_mode_is_active())
	{
		//S32 appCount = srv_mre_appmgr_get_installed_app_num();

		mmi_app_package_name_struct *appList = NULL;
		S32 i, j;
        S32 auto_start_app_num = 0;
        S32 auto_start_vsp_num = 0;
        S32 appCount = 0;
    	auto_start_app_num= srv_mre_appmgr_get_app_num(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE);
        auto_start_vsp_num = srv_mre_appmgr_get_app_num(SRV_APPMGR_INSTALLED_VSP_FLAG_TYPE);
                //g_autostart_app_num = auto_start_app_num + auto_start_vsp_num;
		appCount = auto_start_app_num + auto_start_vsp_num;
	//	mmi_app_package_name_struct *appList = NULL;
		if(appCount > 0)
		{
			appList = OslMalloc(appCount * sizeof(mmi_app_package_name_struct));
			memset(appList, 0, sizeof(mmi_app_package_name_struct) * appCount);
			//srv_mre_appmgr_get_installed_app_list(appList, appCount);
			if(auto_start_app_num>0)
            {
			    srv_mre_appmgr_get_app_list(SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE, appList, auto_start_app_num);
            }
            if(auto_start_vsp_num>0)
            {
                srv_mre_appmgr_get_app_list(SRV_APPMGR_INSTALLED_VSP_FLAG_TYPE, appList+auto_start_app_num, auto_start_vsp_num);
            }

			// check how much autostart app
			g_autostart_app_num = 0;
			for(i = 0; i < appCount; i++)
			{
				if(srv_mre_appmgr_get_autostart(appList[i]) == 1)
				{
					g_autostart_app_num ++;
				}
			}
			
			// copy autostart app list
			if(g_autostart_app_num > 0)
			{
				g_autostart_app_list_p = OslMalloc(g_autostart_app_num * sizeof(mmi_app_package_name_struct));
				j = 0;
				for(i = 0; i < appCount; i++)
				{
					if(srv_mre_appmgr_get_autostart(appList[i]) == 1)
					{
						memcpy((mmi_app_package_char*)(g_autostart_app_list_p[j]), (mmi_app_package_char*)(appList[i]), MMI_APP_NAME_MAX_LEN);
						j ++;
					}
				}
				// query user if launch autostart mre app one by one
				mmi_safe_mode_check_autostart_query_popup();
			}
			OslMfree(appList);
		}
	}
}
mmi_ret mmi_safe_mode_autostart_init(mmi_event_struct *event)
{
	StartTimer(100, 2000, mmi_safe_mode_autostart_time_out);
	return MMI_RET_OK;
}
mmi_ret mmi_safe_mode_autostart_evt_hdlr(mmi_event_struct *event)
{
    mmi_ret ret;

    MMI_ASSERT(event);

    switch (event->evt_id)
    {
		case EVT_ID_SRV_BOOTUP_COMPLETED:
			ret = mmi_safe_mode_autostart_init(event);
			break;
			
        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}

#endif /* defined(__MMI_SAFE_MODE__) */
