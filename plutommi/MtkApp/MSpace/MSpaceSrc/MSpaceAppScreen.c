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
 *   MSpaceAppScreen.c
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   M Space Src
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_features.h" 
#ifdef __MMI_MRE_MSPACE__

/***************************************************************************** 
* Include header files
*****************************************************************************/
#include "MMIDataType.h"
#include "MenuCuiGprot.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "MMI_mre_trc.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "wgui_categories_util.h"
#include "wgui_categories_popup.h"
#include "gui_data_types.h"
#include "GlobalConstants.h"
#include "stdio.h"
#include "gui.h"
#include "gdi_include.h"
#include "gdi_const.h"
	
#include "vmopt.h"
#include "MRESrvGProt.h"
#include "MREAppMgrSrvGprot.h"
#include "Conversions.h"
	
#include "vmio.h"
#include "vmcert_sdk.h"
#include "vmgettag_sdk.h"
#include "app_str.h"
#include "GlobalConstants.h"
	
#include "MASSrvGprot.h"

#include "MSpaceDef.h"
#include "MSpaceGprot.h"
#include "MSpaceMainScreen.h"
#include "MSpaceAppScreen.h"
#include "MSpaceAs.h"
#include "GeneralSettingSrvGprot.h"

	
#include "mmi_rp_app_mspace_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "liblist.h"


/*****************************************************************************/
/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/* global variables */
extern mmi_mspace_ms_struct g_mspace_cntx;

/***************************************************************************** 
* Local Function
*****************************************************************************/

/***************************************************************************** 
* Extern Function
*****************************************************************************/



void mmi_mspace_get_date_string(WCHAR *date_buff, U32 nYear, U32 nMonth, U32 nDay)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_setting_date_format_enum date_format;
	srv_setting_date_seperator_enum date_seperator;
    char sper = '/';
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	date_format = srv_setting_get_date_format();
	date_seperator = srv_setting_get_date_seperator();
	switch (date_seperator)
	{
		case  SETTING_DATE_SEPERATOR_DOT:
			sper = '.';
			break;
		case  SETTING_DATE_SEPERATOR_COLON:
			sper = ':';
			break;
		case  SETTING_DATE_SEPERATOR_SLOPE: 
			sper = '/';
			break;
		case  SETTING_DATE_SEPERATOR_LINE:
			sper = '-';
			break;
		default:
			break;
	}
	switch (date_format)
	{
		case SETTING_DATE_FORMAT_DD_MM_YYYY:
		    kal_wsprintf((kal_wchar*)date_buff, "%02d%c%02d%c%04d", nDay, sper, nMonth, sper, nYear);
			break;
		case SETTING_DATE_FORMAT_MM_DD_YYYY:
			kal_wsprintf((kal_wchar*)date_buff, "%02d%c%02d%c%04d", nMonth, sper, nDay, sper, nYear);
			break;
		case SETTING_DATE_FORMAT_YYYY_MM_DD:
			kal_wsprintf((kal_wchar*)date_buff, "%04d%c%02d%c%02d", nYear, sper, nMonth, sper, nDay);
			break;
		default:
			break;
	}
}


void mmi_mspace_app_scrn_lsk_install_hdlr(void)
{
	mmi_mspace_as_app_install();
}

void mmi_mspace_app_scrn_lsk_update_hdlr(void)
{
	mmi_mspace_as_app_update();
}

static void mmi_mspace_entry_open_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U8 *gui_buffer;
    S32 buf_size = 0;
	srv_as_app_node_t *app_static_info_ptr = NULL;
	srv_as_app_info_t *app_dynamic_info_ptr = NULL;	
	U8 *app_item_icon_ptr = NULL;
	WCHAR date_buf[MSPACE_MAX_STRING];
	WCHAR size_buf[MSPACE_MAX_STRING];
	WCHAR *description;
	U32 pos;
	U32 len;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_OPEN_SCRN_ENTRY_S);

	app_static_info_ptr = g_mspace_cntx.cur_app_static_info;	
	app_dynamic_info_ptr = g_mspace_cntx.cur_app_dynamic_info;
	app_item_icon_ptr = g_mspace_cntx.cur_app_icon;

    ret = mmi_frm_scrn_enter(
            GRP_ID_MSPACE,
            SCR_ID_MSPACE_APP_MAIN,
            NULL,
            mmi_mspace_entry_open_scrn,
            MMI_FRM_FULL_SCRN);

    if (ret == MMI_FALSE)
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    /* set leave proc */
    //mmi_frm_scrn_set_leave_proc(GRP_ID_AM, SCR_ID_AM_DETAILS, mmi_am_leave_details_scrn);


	memset(size_buf, 0, MSPACE_MAX_STRING * 2);	
	pos = 0;	
	mmi_wcsncpy(size_buf + pos, get_string(STR_ID_MSPACE_APP_SIZE), MSPACE_MAX_STRING);
	pos = mmi_wcslen(size_buf);	
	size_buf[pos] = L':';
	pos++;
	size_buf[pos] = L' ';
	pos++;
	mmi_wcs_itow(app_static_info_ptr->app_size, size_buf + pos, 10);
	pos = mmi_wcslen(size_buf);	
	mmi_wcsncpy(size_buf + pos, L"KB", MSPACE_MAX_STRING - pos);


	memset(date_buf, 0, MSPACE_MAX_STRING * 2);
	pos = 0;	
	mmi_wcsncpy(date_buf + pos, get_string(STR_ID_MSPACE_APP_TIME), MSPACE_MAX_STRING);
	pos = mmi_wcslen(date_buf);
	date_buf[pos] = L':';
	pos++;
	date_buf[pos] = L' ';
	pos++;
	mmi_mspace_get_date_string(date_buf + pos, app_static_info_ptr->year, app_static_info_ptr->month, app_static_info_ptr->day);
	

	description = (WCHAR *)kal_adm_alloc_dbg(g_mspace_cntx.adm_pool_id, ( MSPACE_APP_DES_MAX_STRING + MSPACE_MAX_STRING + MSPACE_MAX_STRING ) * 2, __FILE__, __LINE__);
	memset(description, 0, ( MSPACE_APP_DES_MAX_STRING + MSPACE_MAX_STRING + MSPACE_MAX_STRING ) * 2);

	pos = 0;
	
	*(description + pos) = GUI_INPUT_MARKER_MEDIUM;
	pos++;
	*(description + pos) = GUI_INPUT_MARKER_BOLD;
	pos++;	
	mmi_wcsncpy(description + pos, get_string(STR_ID_MSPACE_APP_PROVIDER), MSPACE_MAX_STRING);
	pos = mmi_wcslen(description);
	*(description + pos) = GUI_INPUT_MARKER_RESET_FORMAT;
	pos++;
	*(description + pos) = 0x000A;	
	pos++;	

	*(description + pos) = GUI_INPUT_MARKER_SMALL;
	pos++;	
	mmi_wcsncpy(description + pos, app_static_info_ptr->provider, MSPACE_MAX_STRING);
	pos = mmi_wcslen(description);
	*(description + pos) = 0x000A;	
	pos++;	
	

	*(description + pos) = GUI_INPUT_MARKER_MEDIUM;
	pos++;
	*(description + pos) = GUI_INPUT_MARKER_BOLD;
	pos++;	
	mmi_wcsncpy(description + pos, get_string(STR_ID_MSPACE_APP_INTRODUCTION), MSPACE_MAX_STRING);
	pos = mmi_wcslen(description);
	*(description + pos) = GUI_INPUT_MARKER_RESET_FORMAT;
	pos++;
	*(description + pos) = 0x000A;	
	pos++;	

	*(description + pos) = GUI_INPUT_MARKER_SMALL;
	pos++;		
	mmi_wcsncpy(description + pos, app_static_info_ptr->des, MSPACE_APP_DES_MAX_STRING);


	// define different left key and soft key for cat3006 based for different condition

	MMI_TRACE(MMI_MRE_TRC_G3, TRC_MMI_MSPACE_EOS_APP_STATUS, app_dynamic_info_ptr->status);

	switch (app_dynamic_info_ptr->status) {
		case SRV_AS_APP_STATUS_NEW:	//  APP is not installed
		case SRV_AS_APP_STATUS_GONE:	// APP is installed, but not exist	
		{
			EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
			
			wgui_cat3006_show(
				app_static_info_ptr->dis_name,
				NULL,
				(WCHAR *) GetString(STR_GLOBAL_INSTALL),
				(PU8)GetImage(IMG_GLOBAL_OK),
				(WCHAR *) GetString(STR_GLOBAL_BACK),
				(PU8)GetImage(IMG_GLOBAL_BACK),
				(U8 *)description,
				gui_buffer,
				size_buf,
				date_buf,
				app_item_icon_ptr,
				0,
				NULL,
				NULL,
				0,
				NULL,
				NULL);
			
			SetLeftSoftkeyFunction(mmi_mspace_app_scrn_lsk_install_hdlr, KEY_EVENT_UP);
			SetCenterSoftkeyFunction(mmi_mspace_app_scrn_lsk_install_hdlr, KEY_EVENT_UP);
		}
			break;
		case SRV_AS_APP_STATUS_AVAIL_UPDATE:	//  APP is not installed
		{
			EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
			
			wgui_cat3006_show(
				app_static_info_ptr->dis_name,
				NULL,
				(WCHAR *) GetString(STR_GLOBAL_UPDATE),
				(PU8)GetImage(IMG_GLOBAL_OK),
				(WCHAR *) GetString(STR_GLOBAL_BACK),
				(PU8)GetImage(IMG_GLOBAL_BACK),
				(U8 *)description,
				gui_buffer,
				size_buf,
				date_buf,
				app_item_icon_ptr,
				0,
				NULL,
				NULL,
				0,
				NULL,
				NULL);
			
			SetLeftSoftkeyFunction(mmi_mspace_app_scrn_lsk_update_hdlr, KEY_EVENT_UP);
			SetCenterSoftkeyFunction(mmi_mspace_app_scrn_lsk_update_hdlr, KEY_EVENT_UP);
		}	
			break;
		case SRV_AS_APP_STATUS_NO_AVAIL_UPDATE:	//	APP is not installed
		{
			wgui_cat3006_show(
				app_static_info_ptr->dis_name,
				NULL,
				NULL,
				NULL,
				(WCHAR *) GetString(STR_GLOBAL_BACK),
				(PU8)GetImage(IMG_GLOBAL_BACK),
				(U8 *)description,
				gui_buffer,
				size_buf,
				date_buf,
				app_item_icon_ptr,
				0,
				NULL,
				NULL,
				0,
				NULL,
				NULL);
		}
			break;
		default:
			// error handling
		{
			wgui_cat3006_show(
				app_static_info_ptr->dis_name,
				NULL,
				NULL,
				NULL,
				(WCHAR *) GetString(STR_GLOBAL_BACK),
				(PU8)GetImage(IMG_GLOBAL_BACK),
				(U8 *)description,
				gui_buffer,
				size_buf,
				date_buf,
				app_item_icon_ptr,
				0,
				NULL,
				NULL,
				0,
				NULL,
				NULL);
		}
			break;
	}
	

    kal_adm_free(g_mspace_cntx.adm_pool_id, description);

}

void mmi_mspace_os_app_open(void)
{
    mmi_mspace_entry_open_scrn();
}

void mmi_mspace_os_app_install(void)
{
    mmi_mspace_as_app_install();
}

void mmi_mspace_os_app_update(void)
{
    mmi_mspace_as_app_update();
}


#endif /* __MMI_MRE_MSPACE__ */ 

