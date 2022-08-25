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
 *    SyncMLViewLog.c
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "GlobalResDef.h"
#include "kal_general_types.h"
#include "common_nvram_editor_data_item.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "mmi_rp_srv_syncml_def.h"
#include "wgui_categories_util.h"
#include "gui_typedef.h"
#include "gui_data_types.h"
#include "CustDataRes.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_text_viewer.h"
#include "GlobalConstants.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "MMI_conn_app_trc.h"
#include "mmi_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "SyncMLDef.h"
#include "SyncMLProt.h"
#include "SyncMLStruct.h"
#include "mmi2syncml_struct.h"


/*****************************************************************************
 * Static variable declaration
 *****************************************************************************/


/*****************************************************************************
 * Global variable declaration
 *****************************************************************************/
extern U8 g_syncml_display_info[1024];

#ifdef __MMI_SYNCML_DEVICE_SYNC__
extern mmi_syncml_device_sync_context_struct *const mmi_syncml_dev_p;
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */


/*****************************************************************************
 * Static function declaration
 *****************************************************************************/
static void mmi_syncml_read_sync_log_from_nvram(U8 record_id, void *nvram_buf);
static void mmi_syncml_reset_sync_log(void);
static void mmi_syncml_reset_sync_log_confirm(void);
static void mmi_syncml_reset_goback(void);
static mmi_ret mmi_syncml_sync_log_leave_proc(mmi_event_struct* param);


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_view_log_scr_del_callback
 * DESCRIPTION
 *  account view log delete callback screen. 
 * PARAMETERS
 *  void*       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_syncml_sync_log_leave_proc(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
#ifdef __MMI_SYNCML_DEVICE_SYNC__
            if (g_mmi_syncml_cntx.is_dev_log)
            {
                g_mmi_syncml_cntx.is_dev_log = MMI_FALSE;
            }
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
            break;

        default:
            break;
    }
    
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_entry_sync_log
 * DESCRIPTION
 *  "Sync log" screen for each account entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_entry_sync_log(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_view_log_struct current_view_log;
    U8 record_id;
    U8 *gui_buffer;
    U8 *title = NULL;
    U8 *server_addr = NULL;
    U8 temp_line[MMI_SYNCML_MAX_TIME_SIZE * ENCODING_LENGTH];
    U8 time_str[MMI_SYNCML_MAX_TIME_SIZE];
    S16 zero = 0;
    MYTIME curr_time;
    mmi_id parent_id = GRP_ID_SYNC_MAIN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*
     *  (Title) Sync log
     *  
     *  Account name
     *  Account 1
     *  Time
     *  2007/12/17 15:30:23
     *  Server address
     *  http://app.net.cn/sync
     *  Phonebook done/unfinished
     *  Add: 5
     *  Replace: 4
     *  Delete: 3
     *  Error: 2
     *
     *  Calendar done/unfinished
     *  ...
     */

#ifdef __MMI_SYNCML_DEVICE_SYNC__
     /*
     *  (Title) Sync log
     *  
     *  Near end
     *  Time
     *  2007/12/17 15:30:23
     *  Far End
     *  Phonebook done/unfinished
     *  Add: 5
     *  Replace: 4
     *  Delete: 3
     *  Error: 2
     *
     *  Calendar done/unfinished
     *  ...
     */
     
     /* Enter from device sync */
    if (g_mmi_syncml_cntx.is_dev_log)
    {
        mmi_syncml_device_read_sync_log(mmi_syncml_dev_p->selected_dev, &current_view_log);
    }
    else
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
    {
        record_id = g_mmi_syncml_cntx.selected_account + 1;
        mmi_syncml_read_sync_log_from_nvram(record_id, &current_view_log);
    }

    if (current_view_log.app_to_sync != 0)
    {
#ifdef __MMI_SYNCML_DEVICE_SYNC__
        if (!g_mmi_syncml_cntx.is_dev_log)
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
        {
            server_addr = (U8*)OslMalloc(MAX_SYNCML_SERVER_ADDR_LEN * ENCODING_LENGTH);
            title = g_mmi_syncml_cntx.account_name_display[g_mmi_syncml_cntx.selected_account];
            mmi_asc_to_ucs2((CHAR*)server_addr, (CHAR*)current_view_log.last_sync_server);
        }

        mmi_dt_utc_sec_2_mytime(current_view_log.last_sync_time, &curr_time, KAL_FALSE);

        mmi_ucs2cpy((CHAR*)g_syncml_display_info, (CHAR*)&zero); /* reset string */
#ifdef __MMI_SYNCML_DEVICE_SYNC__
        if (!g_mmi_syncml_cntx.is_dev_log)
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
        {
            mmi_ucs2cpy((CHAR*)g_syncml_display_info, (CHAR*)L""); /* reset string */
            mmi_ucs2cpy((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_PROFILE_NAME));
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) (get_string(STR_ID_SYNCML_COLON)));
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            mmi_ucs2cat((CHAR*)g_syncml_display_info, (CHAR*)title);
            mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
        }
        
        mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_GLOBAL_TIME));
        mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) (get_string(STR_ID_SYNCML_COLON)));
        mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");

        /* 
         * Get date string, use the phone date format
         *  such as:
         *  "12 17 2007" or "2007/12/17" ...
         */
        date_string(&curr_time, (UI_string_type)time_str, DT_IDLE_SCREEN);
        mmi_ucs2cpy((CHAR*)temp_line, (CHAR*)time_str);
        mmi_ucs2cat((CHAR*)temp_line, (CHAR*)L" ");
        /* 
         * Get time string, use the phone time format
         *  such as:
         *  "15:30 AM" or "15:30" ...
         */
        time_string(&curr_time, (UI_string_type)time_str, DT_IDLE_SCREEN);
        mmi_ucs2cat((CHAR*)temp_line, (CHAR*)time_str);        
        mmi_ucs2cat((CHAR*)temp_line, (CHAR*)L"\n");
        mmi_ucs2cat((CHAR*)g_syncml_display_info, (CHAR*)temp_line);

#ifdef __MMI_SYNCML_DEVICE_SYNC__
        if (!g_mmi_syncml_cntx.is_dev_log)
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
        {
            /* If device sync, the address should be far end device name */
            mmi_ucs2cat((CHAR*)g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_SERVER_ADDRESS));
            mmi_ucs2cat((CHAR*)g_syncml_display_info, (CHAR*) (get_string(STR_ID_SYNCML_COLON)));
            mmi_ucs2cat((CHAR*)g_syncml_display_info, (CHAR*) L"\n");
            mmi_ucs2cat((CHAR*)g_syncml_display_info, (CHAR*)server_addr);
            mmi_ucs2cat((CHAR*)g_syncml_display_info, (CHAR*) L"\n");
        }
   
        if (current_view_log.app_to_sync & SYNCML_DB_PHONEBOOK)
        {
            if (mmi_ucs2cmp((CHAR*)g_syncml_display_info, (CHAR*)L"") != 0)
            {
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            }
            if (current_view_log.db_sync_result & SYNCML_DB_PHONEBOOK)
            {
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_CON_NG));
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            }
            else
            {
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_CON_OK));
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");

                /* client sync state */
#ifdef __MMI_SYNCML_DEVICE_SYNC__
                if (g_mmi_syncml_cntx.is_dev_log)
                {
                    /* Near end device name */
                    mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_DEV_LOCAL));
                }
                else
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
                {
                    mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_CLIENT));
                }                              
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ADDED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.clt_con_ok_cnt[0]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPLACED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.clt_con_ok_cnt[1]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_DELETED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.clt_con_ok_cnt[2]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ERROR));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.clt_con_ng_cnt);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);

                /* server sync state */
#ifdef __MMI_SYNCML_DEVICE_SYNC__
                if (g_mmi_syncml_cntx.is_dev_log)
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
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.svr_con_ok_cnt[0]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPLACED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.svr_con_ok_cnt[1]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_DELETED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.svr_con_ok_cnt[2]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ERROR));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.svr_con_ng_cnt);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            }
        }

#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
        if (current_view_log.app_to_sync & SYNCML_DB_CALENDAR)
        {
            if (mmi_ucs2cmp((CHAR*)g_syncml_display_info, (CHAR*)L"") != 0)
            {
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            }
            
            if (current_view_log.db_sync_result & SYNCML_DB_CALENDAR)
            {
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_CAL_NG));
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            }
            else
            {
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_CAL_OK));
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
                
#ifdef __MMI_SYNCML_DEVICE_SYNC__
                if (g_mmi_syncml_cntx.is_dev_log)
                {
                    /* Far end device name */
                    mmi_ucs2cat((CHAR*) g_syncml_display_info, GetString(STR_ID_SYNC_DEV_LOCAL));
                }
                else
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
                {
                    mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_CLIENT));
                }
                
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ADDED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.clt_cal_ok_cnt[0]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPLACED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.clt_cal_ok_cnt[1]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_DELETED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.clt_cal_ok_cnt[2]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ERROR));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.clt_cal_ng_cnt);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                
#ifdef __MMI_SYNCML_DEVICE_SYNC__
                if (g_mmi_syncml_cntx.is_dev_log)
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
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.svr_cal_ok_cnt[0]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPLACED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.svr_cal_ok_cnt[1]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_DELETED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.svr_cal_ok_cnt[2]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ERROR));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.svr_cal_ng_cnt);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            }
        }
#endif /* __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
        
        if (current_view_log.app_to_sync & SYNCML_DB_TASK)
        {
            if (mmi_ucs2cmp((CHAR*)g_syncml_display_info, (CHAR*)L"") != 0)
            {
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            }

            if (current_view_log.db_sync_result & SYNCML_DB_TASK)
            {
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_TASK_NG));
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            }
            else
            {
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_TASK_OK));
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
                
#ifdef __MMI_SYNCML_DEVICE_SYNC__
                if (g_mmi_syncml_cntx.is_dev_log)
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
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.clt_task_ok_cnt[0]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPLACED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.clt_task_ok_cnt[1]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_DELETED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.clt_task_ok_cnt[2]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ERROR));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.clt_task_ng_cnt);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                
#ifdef __MMI_SYNCML_DEVICE_SYNC__
                if (g_mmi_syncml_cntx.is_dev_log)
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
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.svr_task_ok_cnt[0]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPLACED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.svr_task_ok_cnt[1]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_DELETED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.svr_task_ok_cnt[2]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ERROR));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.svr_task_ng_cnt);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
            }
        }

#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__     
        if (current_view_log.app_to_sync & SYNCML_DB_NOTE)
        {
            if (mmi_ucs2cmp((CHAR*)g_syncml_display_info, (CHAR*)L"") != 0)
            {
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            }

            if (current_view_log.db_sync_result & SYNCML_DB_NOTE)
            {
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_NOTE_NG));
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
            }
            else
            {
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPORT_NOTE_OK));
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) L"\n");
                
#ifdef __MMI_SYNCML_DEVICE_SYNC__
                if (g_mmi_syncml_cntx.is_dev_log)
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
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.clt_note_ok_cnt[0]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPLACED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.clt_note_ok_cnt[1]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_DELETED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.clt_note_ok_cnt[2]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ERROR));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.clt_note_ng_cnt);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                
#ifdef __MMI_SYNCML_DEVICE_SYNC__
                if (g_mmi_syncml_cntx.is_dev_log)
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
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.svr_note_ok_cnt[0]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_REPLACED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.svr_note_ok_cnt[1]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_DELETED));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.svr_note_ok_cnt[2]);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*)temp_line);
                mmi_ucs2cat((CHAR*) g_syncml_display_info, (CHAR*) get_string(STR_ID_SYNC_ERROR));
                kal_wsprintf((PU16) temp_line, "%d\n", current_view_log.svr_note_ng_cnt);
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

#ifdef __SYNCML_SYNC_EMAIL_SUPPORT__ 
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
#endif /* __MMI_SYNCML_EMAIL_SUPPORT__ */

        if (mmi_frm_group_is_present(GRP_ID_SYNC_MAIN))
        {
            parent_id = GRP_ID_SYNC_MAIN;
        }
#ifdef __MMI_SYNCML_DEVICE_SYNC__
        else if (mmi_frm_group_is_present(GRP_ID_SYNC_DEV_MAIN))
        {
            parent_id = GRP_ID_SYNC_DEV_MAIN;
        }
#endif
        else
        {
            ASSERT(0);
        }
        
        if (!mmi_frm_scrn_enter(
                parent_id,
                SCR_ID_SYNC_ACCOUNT_VIEW_LOG,
                NULL,
                mmi_syncml_entry_sync_log,
                MMI_FRM_UNKNOW_SCRN))
        {
            return;
        }
        
        gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        
        mmi_frm_scrn_set_leave_proc(parent_id, SCR_ID_SYNC_ACCOUNT_VIEW_LOG, mmi_syncml_sync_log_leave_proc);

		EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        ShowCategory74Screen(
            STR_ID_SYNC_SYNC_LOG,
            GetRootTitleIcon(MENU_ID_SYNCML_MAIN),
            STR_GLOBAL_RESET,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (U8*) g_syncml_display_info,
            mmi_ucs2strlen((const CHAR*)g_syncml_display_info),
            gui_buffer);
            
        SetLeftSoftkeyFunction(mmi_syncml_reset_sync_log_confirm, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_syncml_reset_sync_log_confirm, KEY_EVENT_UP);

        if (server_addr != NULL)
        { 
            OslMfree(server_addr);
        }
    }
    else
    {
		mmi_popup_display_simple(
			(WCHAR*)get_string(STR_GLOBAL_EMPTY), 
			MMI_EVENT_FAILURE, 
			GRP_ID_ROOT, 
			NULL);             
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_reset_sync_log_confirm
 * DESCRIPTION
 *  Confirm if reset
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_reset_sync_log_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id parent_id = GRP_ID_SYNC_MAIN;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_SYNC_MAIN))
    {
        parent_id = GRP_ID_SYNC_MAIN;
    }
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    else if (mmi_frm_group_is_present(GRP_ID_SYNC_DEV_MAIN))
    {
        parent_id = GRP_ID_SYNC_DEV_MAIN;
    }
#endif
    else
    {
        ASSERT(0);
    }
    
    mmi_syncml_confirm_display_with_proc(
        parent_id, 
        (WCHAR*)get_string(STR_ID_SYNC_RESET_LOG_ASK), 
        CNFM_TYPE_YESNO, 
        mmi_syncml_reset_sync_log, 
        mmi_syncml_reset_goback, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_reset_goback
 * DESCRIPTION
 *  Goback for confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_reset_goback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id parent_id = GRP_ID_SYNC_MAIN;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_SYNC_MAIN))
    {
        parent_id = GRP_ID_SYNC_MAIN;
    }
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    else if (mmi_frm_group_is_present(GRP_ID_SYNC_DEV_MAIN))
    {
        parent_id = GRP_ID_SYNC_DEV_MAIN;
    }
#endif
    else
    {
        ASSERT(0);
    }
    
    mmi_frm_scrn_close(parent_id, SCR_ID_SYNC_ACCOUNT_VIEW_LOG);
    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_reset_sync_log
 * DESCRIPTION
 *  Reset last time sync result to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_reset_sync_log(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_view_log_struct temp_view_log;
    S16 error;
    U8 record_id;
    mmi_id parent_id = GRP_ID_SYNC_MAIN;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_SYNC_MAIN))
    {
        parent_id = GRP_ID_SYNC_MAIN;
    }
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    else if (mmi_frm_group_is_present(GRP_ID_SYNC_DEV_MAIN))
    {
        parent_id = GRP_ID_SYNC_DEV_MAIN;
    }
#endif
    else
    {
        ASSERT(0);
    }
        
    mmi_popup_display_simple(
	    (WCHAR*)get_string(STR_GLOBAL_DONE), 
		MMI_EVENT_SUCCESS, 
		GRP_ID_SYNC_MAIN, 
		NULL); 
		
    memset(&temp_view_log, 0, sizeof(mmi_syncml_view_log_struct));
    
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    if (g_mmi_syncml_cntx.is_dev_log)
    {
        record_id = mmi_syncml_dev_p->selected_dev;
        WriteRecord(NVRAM_EF_SYNCML_DEV_SYNC_LOG_LID, record_id, &temp_view_log, NVRAM_EF_SYNCML_DEV_SYNC_LOG_SIZE, &error);         
    }
    else
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
    {
        record_id = g_mmi_syncml_cntx.selected_account + 1;
        WriteRecord(NVRAM_EF_SYNCML_VIEW_LOG_LID, record_id, &temp_view_log, NVRAM_EF_SYNCML_VIEW_LOG_SIZE, &error); 
    }

    mmi_frm_scrn_close(parent_id, SCR_ID_SYNC_ACCOUNT_VIEW_LOG);

    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_SYNC_RESET_SYNC_LOG_TO_NVRAM, error);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_read_sync_log_from_nvram
 * DESCRIPTION
 *  Read last time sync result from nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_syncml_read_sync_log_from_nvram(U8 record_id, void *nvram_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record_id == 0)
    {
        return; /* invalid id */
    }

    ReadRecord(NVRAM_EF_SYNCML_VIEW_LOG_LID, record_id, (void*)nvram_buf, NVRAM_EF_SYNCML_VIEW_LOG_SIZE, &error);    
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_SYNC_READ_SYNC_LOG_FROM_NVRAM, error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_syncml_update_sync_log_to_nvram
 * DESCRIPTION
 *  Update this time sync result to nvram
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_syncml_update_sync_log_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_syncml_view_log_struct temp_view_log;
    U32 curr_time;
    U8 record_id;
    S16 error;
    mmi_syncml_account_struct *temp_account = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef __MMI_SYNCML_DEVICE_SYNC__
    if (g_mmi_syncml_cntx.is_dev_log)
    {
        record_id = mmi_syncml_dev_p->selected_dev;
        temp_view_log.app_to_sync = mmi_syncml_dev_p->app_to_sync;
    }
    else
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
    {
        record_id = g_mmi_syncml_cntx.active_account;
        
        temp_account = (mmi_syncml_account_struct*) OslMalloc(sizeof(mmi_syncml_account_struct));
        
        mmi_syncml_read_account_from_nvram(record_id, temp_account);    
        
        memcpy(temp_view_log.last_sync_server, temp_account->server_address, sizeof(temp_view_log.last_sync_server));
        
        temp_view_log.app_to_sync = g_mmi_syncml_cntx.app_to_sync[g_mmi_syncml_cntx.active_account - 1];
    }

    
    temp_view_log.db_sync_result = g_mmi_syncml_cntx.db_sync_result;
    
    curr_time = mmi_syncml_get_current_time();
    temp_view_log.last_sync_time = curr_time;

    if (temp_view_log.app_to_sync & SYNCML_DB_PHONEBOOK)
    {
        if (!(temp_view_log.db_sync_result & SYNCML_DB_PHONEBOOK))
        {
            memcpy(temp_view_log.clt_con_ok_cnt, g_mmi_syncml_cntx.contact_ok_cnt, 3 * sizeof(g_mmi_syncml_cntx.contact_ok_cnt[0]));
            memcpy(temp_view_log.svr_con_ok_cnt, g_mmi_syncml_cntx.svr_contact_ok_cnt, 3 * sizeof(g_mmi_syncml_cntx.svr_contact_ok_cnt[0]));
            temp_view_log.clt_con_ng_cnt = g_mmi_syncml_cntx.contact_ng_cnt;
            temp_view_log.svr_con_ng_cnt = g_mmi_syncml_cntx.svr_contact_ng_cnt;
        }
    }   
#ifdef __MMI_SYNCML_SYNC_CALENDAR_SUPPORT__
    if (temp_view_log.app_to_sync & SYNCML_DB_CALENDAR)
    {
        if (!(temp_view_log.db_sync_result & SYNCML_DB_CALENDAR))
        {    
            memcpy(temp_view_log.clt_cal_ok_cnt, g_mmi_syncml_cntx.calendar_ok_cnt, 3 * sizeof(g_mmi_syncml_cntx.calendar_ok_cnt[0]));
            memcpy(temp_view_log.svr_cal_ok_cnt, g_mmi_syncml_cntx.svr_calendar_ok_cnt, 3 * sizeof(g_mmi_syncml_cntx.svr_calendar_ok_cnt[0]));            
            temp_view_log.clt_cal_ng_cnt = g_mmi_syncml_cntx.calendar_ng_cnt;
            temp_view_log.svr_cal_ng_cnt = g_mmi_syncml_cntx.svr_calendar_ng_cnt;
        }
    }
#endif/*__MMI_SYNCML_SYNC_CALENDAR_SUPPORT__*/

#ifdef __MMI_SYNCML_SYNC_TASK_SUPPORT__
    if (temp_view_log.app_to_sync & SYNCML_DB_TASK)
    {
        if (!(temp_view_log.db_sync_result & SYNCML_DB_TASK))
        {    
            memcpy(temp_view_log.clt_task_ok_cnt, g_mmi_syncml_cntx.task_ok_cnt, 3 * sizeof(g_mmi_syncml_cntx.task_ok_cnt[0]));
            memcpy(temp_view_log.svr_task_ok_cnt, g_mmi_syncml_cntx.svr_task_ok_cnt, 3 * sizeof(g_mmi_syncml_cntx.svr_task_ok_cnt[0]));            
            temp_view_log.clt_task_ng_cnt = g_mmi_syncml_cntx.task_ng_cnt;
            temp_view_log.svr_task_ng_cnt = g_mmi_syncml_cntx.svr_task_ng_cnt;
        }
    }
#endif /* __MMI_SYNCML_SYNC_TASK_SUPPORT__ */     

#ifdef __MMI_SYNCML_SYNC_NOTE_SUPPORT__
    if (temp_view_log.app_to_sync & SYNCML_DB_NOTE)
    {
        if (!(temp_view_log.db_sync_result & SYNCML_DB_NOTE))
        {    
            memcpy(temp_view_log.clt_note_ok_cnt, g_mmi_syncml_cntx.note_ok_cnt, 3 * sizeof(g_mmi_syncml_cntx.note_ok_cnt[0]));
            memcpy(temp_view_log.svr_note_ok_cnt, g_mmi_syncml_cntx.svr_note_ok_cnt, 3 * sizeof(g_mmi_syncml_cntx.svr_note_ok_cnt[0]));            
            temp_view_log.clt_note_ng_cnt = g_mmi_syncml_cntx.note_ng_cnt;
            temp_view_log.svr_note_ng_cnt = g_mmi_syncml_cntx.svr_note_ng_cnt;
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
#endif /*__MMI_SYNCML_SYNC_EMAIL_SUPPORT__*/ 

#ifdef __MMI_SYNCML_DEVICE_SYNC__
    if (g_mmi_syncml_cntx.is_dev_log)
    {
        WriteRecord(NVRAM_EF_SYNCML_DEV_SYNC_LOG_LID, record_id, &temp_view_log, NVRAM_EF_SYNCML_DEV_SYNC_LOG_SIZE, &error);      
    }
    else
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */
    {
        WriteRecord(NVRAM_EF_SYNCML_VIEW_LOG_LID, record_id, &temp_view_log, NVRAM_EF_SYNCML_VIEW_LOG_SIZE, &error);      
    }
    
    MMI_TRACE(MMI_CONN_TRC_G2_SYNCML, MMI_SYNCML_SYNC_WRITE_SYNC_LOG_TO_NVRAM, error);

    if (temp_account != NULL)
    {
        OslMfree(temp_account);
    }
}

#endif /* __SYNCML_SUPPORT__ */
