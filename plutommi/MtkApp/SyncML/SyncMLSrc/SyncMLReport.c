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
 *    SyncMLReport.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for SyncML appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================== 
 *******************************************************************************/
 
/*****************************************************************************
 * Include
 *****************************************************************************/
 
#include "MMI_features.h"

#ifdef __SYNCML_SUPPORT__

#include "MMIDataType.h"
#include "string.h"
#include "GlobalResDef.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "Unicodexdcl.h"
#include "wgui_categories_util.h"
#include "CustDataRes.h"
#include "kal_public_api.h"
#include "wgui_categories_text_viewer.h"
#include "GlobalConstants.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "NotificationGprot.h"
#include "SyncMLDef.h"
#include "SyncMLGprot.h"
#include "SyncMLProt.h"
#include "SyncMLStruct.h"
#include "mmi2syncml_struct.h"
#include "mmi_rp_srv_syncml_def.h"


/*****************************************************************************
 * Static variable declaration
 *****************************************************************************/


/*****************************************************************************
 * Global variable declaration
 *****************************************************************************/

#ifdef __MMI_SYNCML_DEVICE_SYNC__
extern mmi_syncml_device_sync_context_struct *const mmi_syncml_dev_p;
#endif 

U8 g_syncml_display_info[1024];


/*****************************************************************************
 * Static function declaration
 *****************************************************************************/
static mmi_ret mmi_syncml_sync_report_leave_proc(mmi_event_struct *param);
static void mmi_syncml_group_entry_sync_report(void);
static void mmi_syncml_entry_sync_report(void);

/*****************************************************************************
 * Function definition
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_init_sync_report
 * DESCRIPTION
 *  Initialize global variables for sync report
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_init_sync_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_syncml_cntx.db_sync_result = 0;

    memset(&g_mmi_syncml_cntx.contact_ok_cnt[0], 0, 3 * sizeof(U16));
    g_mmi_syncml_cntx.contact_ng_cnt = 0;
	
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    memset(&g_mmi_syncml_cntx.calendar_ok_cnt[0], 0, 3 * sizeof(U16));
    g_mmi_syncml_cntx.calendar_ng_cnt = 0;
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    memset(&g_mmi_syncml_cntx.task_ok_cnt[0], 0, 3 * sizeof(U16));
    g_mmi_syncml_cntx.task_ng_cnt = 0;
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    memset(&g_mmi_syncml_cntx.note_ok_cnt[0], 0, 3 * sizeof(U16));
    g_mmi_syncml_cntx.note_ng_cnt = 0;
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_set_database_sync_fail
 * DESCRIPTION
 *  Set database sync error flag
 * PARAMETERS
 *  db_type      [IN]            database type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_set_database_sync_fail(U8 db_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* SYNCML_DB_PHONEBOOK or SYNCML_DB_TODOLIST or SYNCML_DB_BOOKMARK  or SYNCML_DB_EMAIL*/
    g_mmi_syncml_cntx.db_sync_result |= db_type; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_sync_report_leave_proc
 * DESCRIPTION
 *  Sync report entry function
 * PARAMETERS
 *  void*
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_sync_report_leave_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_frm_end_scenario(MMI_SCENARIO_ID_SYNC_FINISH);
            
#ifdef __MMI_SYNCML_DEVICE_SYNC__
            if (mmi_syncml_is_device_sync()) /* Device sync always shows report */
            {
                g_mmi_syncml_cntx.is_dev_sync = MMI_FALSE;
            }
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
            if (mmi_syncml_is_pc_sync() && g_mmi_syncml_cntx.sync_report_status[g_mmi_syncml_cntx.active_account - 1])
            {
                g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1] = g_mmi_syncml_cntx.phn_app_to_sync;
                g_mmi_syncml_cntx.is_pc_sync = MMI_FALSE;     
            }
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */

#ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
            if (g_mmi_syncml_cntx.app_sync_menu)
            {
                mmi_syncml_app_sync_finish_hdlr((U8)(g_mmi_syncml_cntx.active_account - 1));
            }   
#endif /*__MMI_SYNCML_APP_SYNC_MENU_SUPPORT__*/ 

        }
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sync_report_proc
 * DESCRIPTION
 *  Sync report proc function
 * PARAMETERS
 *  mmi_event_struct *
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_syncml_entry_sync_report_proc (mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_group_entry_sync_report
 * DESCRIPTION
 *  Sync report entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_group_entry_sync_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_SYNC_FINISH, mmi_syncml_entry_sync_report_proc, NULL);
    mmi_frm_group_enter(GRP_ID_SYNC_FINISH, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_syncml_entry_sync_report();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_exit_sync_report
 * DESCRIPTION
 *  Sync report entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_exit_sync_report(void)
{
    mmi_frm_end_scenario(MMI_SCENARIO_ID_SYNC_FINISH);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sync_report
 * DESCRIPTION
 *  Sync report entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_entry_sync_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 temp_line[128];
    U8 account_index = g_mmi_syncml_cntx.active_account - 1;
    U8 app_to_sync;
	U16 title_icon;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*
    *  (Title) Sync Report
    *
    *  Contact done/unfinished
    *  Add: 5
    *  Replace: 4
    *  Delete: 3
    *  Error: 2
    *
    *  Calendar done/unfinished
    *  ...
    */
    mmi_frm_start_scenario(MMI_SCENARIO_ID_SYNC_FINISH);

    if (!mmi_frm_scrn_enter(
            GRP_ID_SYNC_FINISH,
            SCR_ID_SYNC_REPORT, 
            mmi_syncml_exit_sync_report, 
            mmi_syncml_entry_sync_report, 
            MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    mmi_frm_scrn_set_leave_proc(GRP_ID_SYNC_FINISH, SCR_ID_SYNC_REPORT, mmi_syncml_sync_report_leave_proc);
        
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    
    mmi_ucs2cpy((CHAR*)g_syncml_display_info, (CHAR*)L""); /* reset string */
    app_to_sync = g_mmi_syncml_cntx.app_to_sync[account_index];
   
#if defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__) 
    if (mmi_syncml_is_device_or_pc_sync())
    {   
#ifdef __MMI_SYNCML_DEVICE_SYNC__
        if (mmi_syncml_is_device_sync())
        {
            app_to_sync = mmi_syncml_dev_p->app_to_sync;
        }
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */  

        if (app_to_sync == 0)
    	{
            mmi_ucs2cpy((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_NO_SYNC_TATA));
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
    	}
    }
#endif /* defined(__MMI_SYNCML_DEVICE_SYNC__) || defined(__MMI_SYNCML_PC_SYNC_SUPPORT__)  */
	
    if (app_to_sync & SYNCML_DB_PHONEBOOK)
    {
        if (g_mmi_syncml_cntx.db_sync_result & SYNCML_DB_PHONEBOOK)
        {
            mmi_ucs2cpy((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_CON_NG));
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_CON_CK));
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
        }
        else
        {
            mmi_ucs2cpy((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_CON_OK));
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
			
#ifdef __MMI_SYNCML_DEVICE_SYNC__
			if (mmi_syncml_is_device_sync())
			{
				/* Near end device name */
				mmi_ucs2cat((CHAR*) g_syncml_display_info, GetString(STR_ID_SYNC_DEV_LOCAL));
			}
			else 
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
			{
				mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_CLIENT));    
			}
			
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ADDED));
			kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.contact_ok_cnt[0]);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPLACED));
			kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.contact_ok_cnt[1]);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_DELETED));
			kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.contact_ok_cnt[2]);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ERROR));
			kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.contact_ng_cnt);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);

#ifdef __MMI_SYNCML_DEVICE_SYNC__
			if (mmi_syncml_is_device_sync())
			{
				/* Far end device name */
				if (mmi_ucs2strlen((CHAR*)g_mmi_syncml_common_cntx.remote_dev_name))
				{
					mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)g_mmi_syncml_common_cntx.remote_dev_name);
				}
				else
				{
					mmi_ucs2cat((CHAR*) g_syncml_display_info, GetString(STR_ID_SYNC_DEV_REMOTE));                       
				}
			}
			else
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
			{
				mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_SERVER));
			}
			
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ADDED));
			kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.svr_contact_ok_cnt[0]);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPLACED));
			kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.svr_contact_ok_cnt[1]);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_DELETED));
			kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.svr_contact_ok_cnt[2]);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ERROR));
			kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.svr_contact_ng_cnt);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
        }
    }   
    
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    
    if (app_to_sync & SYNCML_DB_CALENDAR)
    {
        if (mmi_ucs2cmp((CHAR*)g_syncml_display_info, (CHAR*)L"") != 0)
        {
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
        }
        
        if (g_mmi_syncml_cntx.db_sync_result & SYNCML_DB_CALENDAR)
        {
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_CAL_NG));
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_CAL_CK));
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
        }
        else
        {
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_CAL_OK));
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            
#ifdef __MMI_SYNCML_DEVICE_SYNC__
			if (mmi_syncml_is_device_sync())
			{
				/* Near end device name */
				mmi_ucs2cat((CHAR*) g_syncml_display_info, GetString(STR_ID_SYNC_DEV_LOCAL));
			}
			else 
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
			{
				mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_CLIENT));
			}
            
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ADDED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.calendar_ok_cnt[0]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPLACED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.calendar_ok_cnt[1]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_DELETED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.calendar_ok_cnt[2]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ERROR));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.calendar_ng_cnt);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            
#ifdef __MMI_SYNCML_DEVICE_SYNC__
			if (mmi_syncml_is_device_sync())
			{
				/* Far end device name */
				if (mmi_ucs2strlen((CHAR*)g_mmi_syncml_common_cntx.remote_dev_name))
				{
					mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)g_mmi_syncml_common_cntx.remote_dev_name);
				}
				else
				{
					mmi_ucs2cat((CHAR*) g_syncml_display_info, GetString(STR_ID_SYNC_DEV_REMOTE));                       
				}
			}
			else
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */               
            {
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_SERVER));
            }
            
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ADDED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.svr_calendar_ok_cnt[0]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPLACED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.svr_calendar_ok_cnt[1]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_DELETED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.svr_calendar_ok_cnt[2]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ERROR));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.svr_calendar_ng_cnt);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
        }
    }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */
    
#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    if (app_to_sync & SYNCML_DB_TASK)
    {
        if (mmi_ucs2cmp((CHAR*)g_syncml_display_info, (CHAR*)L"") != 0)
        {
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
        }
        
        if (g_mmi_syncml_cntx.db_sync_result & SYNCML_DB_TASK)
        {
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_TASK_NG));
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_TASK_CK));
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
        }
        else
        {
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_TASK_OK));
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            
#ifdef __MMI_SYNCML_DEVICE_SYNC__
			if (mmi_syncml_is_device_sync())
			{
				/* Near end device name */
				mmi_ucs2cat((CHAR*) g_syncml_display_info, GetString(STR_ID_SYNC_DEV_LOCAL));
			}
			else 
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
                
            {
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_CLIENT));
            }
            
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ADDED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.task_ok_cnt[0]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPLACED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.task_ok_cnt[1]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_DELETED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.task_ok_cnt[2]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ERROR));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.task_ng_cnt);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            
#ifdef __MMI_SYNCML_DEVICE_SYNC__
			if (mmi_syncml_is_device_sync())
			{
				/* Far end device name */
				if (mmi_ucs2strlen((CHAR*)g_mmi_syncml_common_cntx.remote_dev_name))
				{
					mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)g_mmi_syncml_common_cntx.remote_dev_name);
				}
				else
				{
					mmi_ucs2cat((CHAR*) g_syncml_display_info, GetString(STR_ID_SYNC_DEV_REMOTE));                       
				}
			}
			else
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
                
            {
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_SERVER));
            }
            
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ADDED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.svr_task_ok_cnt[0]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPLACED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.svr_task_ok_cnt[1]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_DELETED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.svr_task_ok_cnt[2]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ERROR));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.svr_task_ng_cnt);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
        }
    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    if (app_to_sync & SYNCML_DB_NOTE)
    {
        if (mmi_ucs2cmp((CHAR*)g_syncml_display_info, (CHAR*)L"") != 0)
        {
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
        }
        
        if (g_mmi_syncml_cntx.db_sync_result & SYNCML_DB_NOTE)
        {
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_NOTE_NG));
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_NOTE_CK));
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
        }
        else
        {
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_NOTE_OK));
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            
#ifdef __MMI_SYNCML_DEVICE_SYNC__
			if (mmi_syncml_is_device_sync())
			{
				/* Near end device name */
				mmi_ucs2cat((CHAR*) g_syncml_display_info, GetString(STR_ID_SYNC_DEV_LOCAL));
			}
			else 
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
                
            {
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_CLIENT));
            }
            
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ADDED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.note_ok_cnt[0]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
			mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPLACED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.note_ok_cnt[1]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_DELETED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.note_ok_cnt[2]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ERROR));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.note_ng_cnt);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            
#ifdef __MMI_SYNCML_DEVICE_SYNC__
			if (mmi_syncml_is_device_sync())
			{
				/* Far end device name */
				if (mmi_ucs2strlen((CHAR*)g_mmi_syncml_common_cntx.remote_dev_name))
				{
					mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)g_mmi_syncml_common_cntx.remote_dev_name);
				}
				else
				{
					mmi_ucs2cat((CHAR*) g_syncml_display_info, GetString(STR_ID_SYNC_DEV_REMOTE));                       
				}
			}
			else
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
                
            {
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_SERVER));
            }
            
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ADDED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.svr_note_ok_cnt[0]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPLACED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.svr_note_ok_cnt[1]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_DELETED));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.svr_note_ok_cnt[2]);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ERROR));
            kal_wsprintf((PU16) temp_line, "%d\n", g_mmi_syncml_cntx.svr_note_ng_cnt);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
        }
    }
#endif /* __MMI_SYNCML_SYNC_NOTE_SUPPORT__ */

#ifdef __MMI_SYNCML_BOOKMARK_SUPPORT__
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
#endif /* __MMI_SYNCML_BOOKMARK_SUPPORT__ */
	
#ifdef __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ 
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
#endif /* __MMI_SYNCML_SYNC_EMAIL_SUPPORT__ */
	
#ifdef __MMI_OP01_SYNCML_SETTING__
/* under construction !*/
#else
    title_icon = GetRootTitleIcon(MENU_ID_SYNCML_MAIN);
#endif

    ShowCategory74Screen(
        STR_ID_SYNC_REPORT,
        title_icon,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) g_syncml_display_info,
        mmi_ucs2strlen((const CHAR*)g_syncml_display_info),
        guiBuffer);
	
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_sync_finish_popup_proc
 * DESCRIPTION
 *  Handle sync popup display by center control mechanism
 * PARAMETERS
 *  NULL
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_sync_finish_popup_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    mmi_alert_result_evt_struct *evt = 
            (mmi_alert_result_evt_struct *)param;
    
    mmi_syncml_display_popup_hdlr_struct* popup_status_ptr = 
                            (mmi_syncml_display_popup_hdlr_struct* )evt->user_tag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_POPUP_QUIT:
        {
            if (MMI_POPUP_NORMAL_EXIT == evt->result || MMI_POPUP_INTERRUPT_EXIT == evt->result)
            {
                if (popup_status_ptr->sync_result == SYNCML_OK)
                {
                    /* Device sync will always show sync report */
                    if (g_mmi_syncml_cntx.sync_report_status[g_mmi_syncml_cntx.active_account - 1]
#ifdef __MMI_SYNCML_DEVICE_SYNC__ 
                    || mmi_syncml_is_device_sync()
#endif
                        )
                    {
                        mmi_syncml_group_entry_sync_report();
                    }
                }
            }
            else
            {
                mmi_frm_end_scenario(MMI_SCENARIO_ID_SYNC_FINISH);
            }
            
            OslMfree(popup_status_ptr);
            
            break;
        }
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncl_entry_sync_finish_popup
 * DESCRIPTION
 *  Handle sync popup display by center control mechanism
 * PARAMETERS
 *  NULL
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_syncl_entry_sync_finish_popup(mmi_scenario_id scen_id, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    mmi_syncml_display_popup_hdlr_struct* popup_status_ptr = 
                            (mmi_syncml_display_popup_hdlr_struct* )param;

    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_start_scenario(MMI_SCENARIO_ID_SYNC_FINISH);

    mmi_popup_property_init(&arg);
    arg.parent_id = GRP_ID_ROOT;
    arg.callback = mmi_syncml_sync_finish_popup_proc;
    arg.user_tag = (void*)popup_status_ptr;
    arg.f_play_tone = 0;
    mmi_popup_display(
        (WCHAR *)get_string(popup_status_ptr->string_id), 
        (mmi_event_notify_enum)popup_status_ptr->emotion_id, 
        &arg);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_report_screen_hdlr
 * DESCRIPTION
 *  Handle sync popup display by center control mechanism
 * PARAMETERS
 *  NULL
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_report_screen_hdlr(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    mmi_syncml_finish_sync_ind_struct *local_data
        = (mmi_syncml_finish_sync_ind_struct*) param;
    
    mmi_syncml_display_popup_hdlr_struct *popup_status_ptr
        = OslMalloc(sizeof(mmi_syncml_display_popup_hdlr_struct));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(popup_status_ptr != NULL);
    memset(popup_status_ptr, 0, sizeof(mmi_syncml_display_popup_hdlr_struct));

    /* determine string to show */
    popup_status_ptr->string_id = STR_ID_SYNC_DEFAULT_FAIL;
    popup_status_ptr->emotion_id = MMI_EVENT_FAILURE;

    popup_status_ptr->sync_result = 
        (SYNCML_GET_OTHER_INFO(local_data->result) ? SYNCML_GET_OTHER_INFO(local_data->result) : SYNCML_GET_SYNC_STATUS(local_data->result));

    switch(popup_status_ptr->sync_result)
    {
        /* process local err */
        case SYNCML_LOCAL_DB_FULL:
            popup_status_ptr->string_id = STR_ID_SYNC_LOCALDB_FULL; 
            break;
            
        /* process server err */
        case SYNCML_OK: /* 200 */
            popup_status_ptr->string_id = STR_ID_SYNC_DONE;
            popup_status_ptr->emotion_id = MMI_EVENT_SUCCESS;
            break;

        case SYNCML_INVALID_CREDENTIAL: /* 401 */
            popup_status_ptr->string_id = STR_ID_SYNC_INVALID_CREDENTIAL;
            popup_status_ptr->emotion_id = MMI_EVENT_FAILURE;
            break;

        case SYNCML_MISSING_CREDENTIAL: /* 407 */
            popup_status_ptr->string_id = STR_ID_SYNC_MISSING_CREDENTIAL;
            break;

        case SYNCML_PAYMENT_REQUIRED: /* 402 */
            popup_status_ptr->string_id = STR_ID_SYNC_PAYMENT_REQUIRED;
            break;

        case SYNCML_CODE_FORBIDDEN: /* 403 */
            popup_status_ptr->string_id = STR_ID_SYNC_CODE_FORBIDDEN;
            break;
            
        case SYNCML_INCOMPLETE_CMD: /* 412 */
            popup_status_ptr->string_id = STR_ID_SYNC_INCOMPLETE_CMD;
            break;
            
        case SYNCML_DEVICE_FULL: /* 420 */
            popup_status_ptr->string_id = STR_ID_SYNC_SVR_DEVICE_FULL;
            break;

        case SYNCML_SERVICE_UNAVAILABLE: /* 503 */
            popup_status_ptr->string_id = STR_ID_SYNC_SERVICE_UNAVAILABLE;
            break;
            
        case SYNCML_DATASTORE_FAIL: /* 510 */
            popup_status_ptr->string_id = STR_ID_SYNC_DATASTORE_FAIL;
            break;
            
        case SYNCML_SVR_FAIL: /* 511 */
            popup_status_ptr->string_id = STR_ID_SYNC_SVR_FAIL;
            break;
            
        case SYNCML_ERR_OCCUR: /* 512 */
            popup_status_ptr->string_id = STR_ID_SYNC_ERR_OCCUR;
            break;

        case SYNCML_PROTOCOL_UNSUPPORT: /* 513 */
            popup_status_ptr->string_id = STR_ID_SYNC_PROTOCOL_UNSUPPORT;
            break;

        case SYNCML_FAIL: /* 500 */
			popup_status_ptr->string_id = STR_ID_SYNC_FAIL;
			break;
            
		case SYNCML_ABORT_SYNC:
            popup_status_ptr->string_id = STR_ID_SYNC_CANCELLED;
            popup_status_ptr->emotion_id = MMI_EVENT_SUCCESS;
            
            break;
        default:
            break;
    }
 
    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_SYNC_FINISH, (mmi_event_notify_enum)popup_status_ptr->emotion_id, mmi_syncl_entry_sync_finish_popup, (void *)popup_status_ptr);
}

#endif /* __SYNCML_SUPPORT__ */

