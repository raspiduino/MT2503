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
 *
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_PICT_BRIDGE_SUPPORT__
#include "PictBridgeDef.h"
#include "PictBridgeProt.h"
#include "PictBridgeStruct.h"
#include "pictcuigprot.h"
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "CommonScreensResDef.h"
#include "mmi_rp_srv_pict_bridge_def.h"
#include "Unicodexdcl.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "kal_general_types.h"
#include "PictBridgeResDef.h"
#include "fs_errcode.h"
#include "FileMgrSrvGProt.h"
/* auto add by kw_check end */
/****************************************************************************
* Static Variable
*****************************************************************************/
static cui_pict_result_enum g_pict_result;
static U8 g_pict_total_count;
mmi_id g_pict_gid = GRP_ID_INVALID;

/****************************************************************************
* Global Variable
*****************************************************************************/
extern pict_bridge_context_struct g_pict_bridge_context;

/*****************************************************************************
 * FUNCTION
 *  cui_pict_send_result_to_parent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void cui_pict_send_result_to_parent(cui_pict_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_pict_result_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    evt.evt_id = EVT_ID_CUI_PICT_RESULT;
    evt.result = result;

    mmi_frm_group_send_to_parent(g_pict_gid, (mmi_group_event_struct*)&evt);
    mmi_frm_group_close(g_pict_gid);

	g_pict_gid = GRP_ID_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  cui_pict_post_evt_to_parent
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void cui_pict_post_evt_to_parent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct evt;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_CUI_PICT_GET_FILE_INFO);        
    
    mmi_frm_group_post_to_parent(g_pict_gid, &evt);
}

/*****************************************************************************
 * FUNCTION
 *  cui_pict_proc
 * DESCRIPTION
 *  Pictbridge CUI proc function.
 * PARAMETERS
 *  evt     [IN]        Event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_pict_proc(mmi_event_struct *evt)
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
 *  cui_pict_popup_callback
 * DESCRIPTION
 *  Pictbridge CUI proc function.
 * PARAMETERS
 *  evt     [IN]        Event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret cui_pict_popup_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_ALERT_QUIT:
        cui_pict_send_result_to_parent(g_pict_result);
        break;
            
    default :
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_pict_create
 * DESCRIPTION
 *  Create Pictbridge CUI.
 * PARAMETERS
 *  parent_gid      [IN]        App's Group ID
 * RETURNS
 *  Pictbridge CUI group ID
 *****************************************************************************/
static mmi_id cui_pict_create(mmi_id parent_gid, U8 total_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_pict_gid = mmi_frm_group_create(parent_gid, GRP_ID_AUTO_GEN, cui_pict_proc, NULL);
    g_pict_total_count = total_count;
    
    return g_pict_gid;
}


/*****************************************************************************
 * FUNCTION
 *  cui_pict_run
 * DESCRIPTION
 *  Pictbridge CUI run function. 
 * PARAMETERS
 *  g_pict_gid        [IN]        Pictbridge CUI Group ID
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_pict_run(mmi_id gid, MMI_BOOL is_multi_sel, const cui_pict_file_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* use 0 not SMART_CLOSE_FLAG, otherwise group will automatically close and can't send 
       print result to parent, such as press RSK "back" in setting screen" */

    mmi_frm_group_enter(g_pict_gid, MMI_FRM_NODE_NONE_FLAG);

    /* printer is not present */
    if (!mmi_pict_is_dps_device_present())
    {        
        cui_pict_disp_popup(CUI_PICT_RESULT_NOT_READY, STR_ID_PICT_PRINTER_REMOVED, MMI_EVENT_FAILURE);        
        return;
    }

    if (!mmi_pict_is_configure_ready())
    {    
        /* waiting for initialization with the printer */        
        cui_pict_disp_popup(CUI_PICT_RESULT_NOT_READY, STR_ID_PICT_CONFIGURATION, MMI_EVENT_FAILURE);        
        return;
    }

    if (g_pict_bridge_context.printing != PICT_PRINTING_NONE)
    {
        cui_pict_disp_popup(CUI_PICT_RESULT_BUSY, STR_GLOBAL_BUSY_TRY_LATER, MMI_EVENT_FAILURE);
        return;
    }
    
#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__    
    if (is_multi_sel)
    {
        mmi_pict_reset_files_info();        
        mmi_pict_entry_file_processing_screen();
        
        if (info != NULL)
        {
			mmi_pict_record_file_info(info->full_path, info->info);                
        }        

        if (g_pict_total_count == 1)
        {
            mmi_pict_prepare_file_done();
        }
        else
        {
            cui_pict_post_evt_to_parent();
        }
    }
    else
#endif
    {
        if (info != NULL)
        {            
            mmi_ucs2cpy((S8*) g_pict_bridge_context.printing_filepath, (S8*) info->full_path);
        
            if (!mmi_pict_jpg_format_validation((S8*) g_pict_bridge_context.printing_filepath))
            {
                /* invalid file */                    
                cui_pict_disp_popup(CUI_PICT_RESULT_ERROR, STR_ID_PICT_INVALID_JPG_FILE, MMI_EVENT_FAILURE);                    
                return;
            }
#ifdef __DRM_SUPPORT__
            if (!mmi_pict_drm_jpg_file_check(g_pict_bridge_context.printing_filepath))
            {
                cui_pict_disp_popup(CUI_PICT_RESULT_ERROR, STR_GLOBAL_DRM_PROHIBITED, MMI_EVENT_FAILURE);                    
                return;
            }
#endif /* __DRM_SUPPORT__ */
#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
            mmi_pict_prepare_single_file_data(); //prepare data for multiple file buffer
#else
            mmi_pict_get_file_date();
#endif
            mmi_pict_entry_print_settings();
        }
    }    
}


/*****************************************************************************
 * FUNCTION
 *  cui_pict_disp_popup
 * DESCRIPTION
 *  Pictbridge CUI run function. 
 * PARAMETERS
 *  g_pict_gid        [IN]        Pictbridge CUI Group ID
 * RETURNS
 *  void
 *****************************************************************************/
void cui_pict_disp_popup(cui_pict_result_enum result, MMI_STR_ID string_id, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pict_result = result;

    mmi_popup_property_init(&arg);
    arg.callback = cui_pict_popup_callback;

    mmi_popup_display((WCHAR*)GetString(string_id), event_id, &arg);

    mmi_frm_scrn_close(g_pict_gid, SCR_ID_PICT_PROCESSING);
}

/*****************************************************************************
 * FUNCTION
 *  cui_pict_run
 * DESCRIPTION
 *  Pictbridge CUI run function. 
 * PARAMETERS
 *  g_pict_gid        [IN]        Pictbridge CUI Group ID
 * RETURNS
 *  void
 *****************************************************************************/
void cui_pict_print_next_file(mmi_id cui_id, const cui_pict_file_info_struct *info, S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
    if (info == NULL || cui_id != g_pict_gid)
        return;

    
    if (result != FS_NO_ERROR)
    {        
        cui_pict_disp_popup(CUI_PICT_RESULT_ERROR, srv_fmgr_fs_error_get_string(result), MMI_EVENT_FAILURE);
        
        mmi_frm_scrn_close(g_pict_gid, SCR_ID_PICT_PROCESSING);

        return;
    }

    mmi_pict_record_file_info(info->full_path, info->info);

    if (g_pict_total_count == info->index)
    {
        mmi_pict_prepare_file_done();
    }
    else
    {
        cui_pict_post_evt_to_parent();
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  cui_pict_launch
 * DESCRIPTION
 *  Create Pictbridge CUI.
 * PARAMETERS
 *  parent_gid      [IN]        App's Group ID
 * RETURNS
 *  Pictbridge CUI group ID
 *****************************************************************************/
mmi_id cui_pict_print_launch(mmi_id parent_gid, MMI_BOOL is_multi_sel, U8 total_count, 
                     const cui_pict_file_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cui_pict_create(parent_gid, total_count);
	cui_pict_run(g_pict_gid, is_multi_sel, info);

    return g_pict_gid;
}

#endif
