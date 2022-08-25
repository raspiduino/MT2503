/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *    PictBridgeFMGR.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for PictBridge appliction.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_PICT_BRIDGE_SUPPORT__


#include "FileMgrSrvGprot.h"

#include "GlobalResDef.h"
#include "PictBridgeResDef.h"
#include "mmi_rp_srv_pict_bridge_def.h"
#include "PictBridgeDef.h"
#include "PictBridgeProt.h"
#include "PictBridgeStruct.h"

#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"
#endif
/* RHR add */
#include "MMIDataType.h"
#include "mmi_frm_mem_gprot.h"
#include "Pictcuigprot.h"
#include "PictBridgeResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_text_viewer.h"
#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "kal_general_types.h"
#include "FontRes.h"
#include "SSCStringTable.h"
#include "string.h"
#include "kal_public_api.h"
#include "CustDataRes.h"
#include "mmi_rp_srv_pict_bridge_def.h"
#include "fs_type.h"
#include "drm_def.h"
#include "fs_errcode.h"
#include "wgui_categories_popup.h"
#include "mmi_frm_events_gprot.h"
#include "custom_events_notify.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_rp_file_type_def.h"
#include "custom_mmi_default_value.h"
#include "fs_func.h"
/* RHR add end */

#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__

/*
 * Global Variable
 */
extern pict_bridge_context_struct g_pict_bridge_context;
extern pict_bridge_setting_struct g_pict_bridge_setting;
extern mmi_id g_pict_gid;

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_mem_allocate_file_stat_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_mem_allocate_file_stat_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_pict_bridge_context.file_stat_buffer)
    {
         g_pict_bridge_context.file_stat_buffer = OslMalloc(1024);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_mem_free_file_stat_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_mem_free_file_stat_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_pict_bridge_context.file_stat_buffer)
    {
        OslMfree(g_pict_bridge_context.file_stat_buffer);
        g_pict_bridge_context.file_stat_buffer = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_cancel_multiple_print
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_cancel_multiple_print(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pict_mem_free_file_stat_buffer();
    cui_pict_send_result_to_parent(CUI_PICT_RESULT_CANCEL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_continue_multiple_print
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_continue_multiple_print(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pict_mem_free_file_stat_buffer();
    mmi_pict_entry_print_settings();
    mmi_frm_scrn_close(g_pict_gid, SCR_ID_PICT_FILES);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_delete_final_statistics_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
mmi_ret mmi_pict_delete_final_statistics_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pict_mem_free_file_stat_buffer();
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_mark_several_final_statistics
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_mark_several_final_statistics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(g_pict_gid, SCR_ID_PICT_FILES, NULL, 
        mmi_pict_entry_mark_several_final_statistics, MMI_FRM_UNKNOW_SCRN))
        return;
    
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();;

    if (g_pict_bridge_context.multi_file_select > 0)
    {
        ShowCategory74Screen(
            STR_GLOBAL_PRINT,
            mmi_pict_return_title_icon(),
            STR_GLOBAL_YES,
            IMG_GLOBAL_YES,
            STR_GLOBAL_NO,
            IMG_GLOBAL_NO,
            g_pict_bridge_context.file_stat_buffer,
            mmi_ucs2strlen((const S8*) g_pict_bridge_context.file_stat_buffer),
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_pict_continue_multiple_print, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_pict_continue_multiple_print, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
    else
    {
        ShowCategory74Screen(
            STR_GLOBAL_PRINT,
            mmi_pict_return_title_icon(),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_pict_bridge_context.file_stat_buffer,
            mmi_ucs2strlen((const S8*) g_pict_bridge_context.file_stat_buffer),
            guiBuffer);
    }

    SetRightSoftkeyFunction(mmi_pict_cancel_multiple_print, KEY_EVENT_UP);

    mmi_frm_scrn_set_leave_proc(g_pict_gid, SCR_ID_PICT_FILES, (mmi_proc_func) mmi_pict_delete_final_statistics_callback);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_wsprintf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_wsprintf(WCHAR *outstr, U8 cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern sLanguageDetails *gLanguageArray;
    extern U16 gCurrLangIndex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_TCHINESE) == 0)
    {
        kal_wsprintf(outstr, "%d", cnt);
    }
    else if (strcmp((PS8) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SCHINESE) == 0)
    {
        kal_wsprintf(outstr, "%d", cnt);
    }
    else
    {
        kal_wsprintf(outstr, "%d ", cnt);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_prepare_mark_several_final_statistics
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_prepare_mark_several_final_statistics(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_line[64];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_pict_wsprintf((PU16) temp_line, g_pict_bridge_context.jpg_file_cnt);
    mmi_ucs2cpy((PS8) g_pict_bridge_context.file_stat_buffer, (PS8) temp_line);
    if (g_pict_bridge_context.jpg_file_cnt == 1)
    {
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, GetString(STR_ID_PICT_JPG_FILE_SELECTED));
    }
    else
    {
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, GetString(STR_ID_PICT_JPG_FILES_SELECTED));
    }
    mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, (PS8) L"\n");

    if (g_pict_bridge_context.jpg_file_cnt > 20)
    {
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, GetString(STR_ID_PICT_JPG_FILES_LIMITATION));
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, (PS8) L"\n\n");
    }
    else
    {
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, (PS8) L"\n");
    }

    if (g_pict_bridge_context.inv_file_cnt != 0)
    {
        mmi_pict_wsprintf((PU16) temp_line, g_pict_bridge_context.inv_file_cnt);
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, (PS8) temp_line);
        if (g_pict_bridge_context.inv_file_cnt == 1)
        {
            mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, GetString(STR_ID_PICT_INV_FILE_SELECTED));
        }
        else
        {
            mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, GetString(STR_ID_PICT_INV_FILES_SELECTED));
        }
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, (PS8) L"\n");
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, GetString(STR_ID_PICT_INV_FILES_LIMITATION));
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, (PS8) L"\n\n");
    }

    if (g_pict_bridge_context.drm_file_cnt != 0)
    {
        mmi_pict_wsprintf((PU16) temp_line, g_pict_bridge_context.drm_file_cnt);
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, (PS8) temp_line);
        if (g_pict_bridge_context.drm_file_cnt == 1)
        {
            mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, GetString(STR_ID_PICT_DRM_FILE_SELECTED));
        }
        else
        {
            mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, GetString(STR_ID_PICT_DRM_FILES_SELECTED));
        }
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, (PS8) L"\n");
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, GetString(STR_ID_PICT_DRM_FILES_LIMITATION));
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, (PS8) L"\n\n");
    }

    if (g_pict_bridge_context.bad_file_cnt != 0)
    {
        mmi_pict_wsprintf((PU16) temp_line, g_pict_bridge_context.bad_file_cnt);
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, (PS8) temp_line);
        if (g_pict_bridge_context.bad_file_cnt == 1)
        {
            mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, GetString(STR_ID_PICT_BAD_FILE_SELECTED));
        }
        else
        {
            mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, GetString(STR_ID_PICT_BAD_FILES_SELECTED));
        }
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, (PS8) L"\n");
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, GetString(STR_ID_PICT_BAD_FILES_LIMITATION));
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, (PS8) L"\n\n");
    }

    if (g_pict_bridge_context.multi_file_select > 0)
    {
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, GetString(STR_ID_PICT_CONFIRM_FMGR_TO_PRINT));
    }
    else
    {
        mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, GetString(STR_ID_PICT_CONFIRM_FMGR_GO_BACK));
    }
    mmi_ucs2cat((PS8) g_pict_bridge_context.file_stat_buffer, (PS8) L"\n");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_file_processing_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_file_processing_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(g_pict_gid, SCR_ID_PICT_PROCESSING, NULL, 
        mmi_pict_entry_file_processing_screen, MMI_FRM_UNKNOW_SCRN))
        return;

    ShowCategory66Screen(
        STR_GLOBAL_PRINT,
        mmi_pict_return_title_icon(),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    SetKeyHandler(NULL, KEY_END, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_reset_files_info
 * DESCRIPTION
 *  FMGR multiple selection callback for print
 * PARAMETERS
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_pict_reset_files_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pict_bridge_context.bad_file_cnt = 0;
    g_pict_bridge_context.drm_file_cnt = 0;
    g_pict_bridge_context.inv_file_cnt = 0;
    g_pict_bridge_context.jpg_file_cnt = 0;
    g_pict_bridge_context.error_index = 0;
    g_pict_bridge_context.curr_index = 0;
    
    memset(g_pict_bridge_context.printing_filepath, 0, 2);
    for (i = 0; i < PICT_MAX_MULTI_FILES; i++)
    {
        memset(g_pict_bridge_context.multi_file_path[i], 0, 2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_record_file_info
 * DESCRIPTION
 *  FMGR multiple selection callback for print
 * PARAMETERS
 *  full_path       [IN]
 *  file_info       [IN] 
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_pict_record_file_info(const WCHAR *full_path, const srv_fmgr_fileinfo_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (info->type == FMGR_TYPE_JPG || info->type == FMGR_TYPE_JPEG)
	{
		if (mmi_ucs2strlen((S8*) g_pict_bridge_context.printing_filepath) == 0)
		{
			mmi_ucs2cpy((S8*) g_pict_bridge_context.printing_filepath, (S8*) full_path);
		}

#ifdef __DRM_SUPPORT__
		if (!mmi_pict_drm_jpg_file_check((U8*)full_path))
		{
			g_pict_bridge_context.drm_file_cnt++;
		}
		else 
#endif /* __DRM_SUPPORT__ */
		if (!mmi_pict_jpg_format_validation((S8*) full_path))
		{
			g_pict_bridge_context.inv_file_cnt++;
		}
		else
		{
			if (g_pict_bridge_context.jpg_file_cnt < PICT_MAX_MULTI_FILES)
			{
				/* JPG count 0 ~ 19 */
				mmi_ucs2cpy((S8*) g_pict_bridge_context.multi_file_path[g_pict_bridge_context.jpg_file_cnt], 
                    (S8*)srv_fmgr_path_get_filename_ptr((WCHAR*)full_path));
				/* size */
				g_pict_bridge_context.multi_file_size[g_pict_bridge_context.jpg_file_cnt] = info->size;
				/* date 
				 * since FileManager just get file information with FS_DOSDateTime(bit strcut)
				 * so here no data overflow
				*/
				g_pict_bridge_context.multi_file_date[g_pict_bridge_context.jpg_file_cnt].Year1980 = info->datetime.nYear - 1980;
				g_pict_bridge_context.multi_file_date[g_pict_bridge_context.jpg_file_cnt].Month = info->datetime.nMonth;
				g_pict_bridge_context.multi_file_date[g_pict_bridge_context.jpg_file_cnt].Day = info->datetime.nDay;
			}
			g_pict_bridge_context.jpg_file_cnt++;
		}
	}
	else
	{
		g_pict_bridge_context.bad_file_cnt++;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_prepare_file_done
 * DESCRIPTION
 *  FMGR multiple selection callback for print
 * PARAMETERS
 *  full_path       [IN]
 *  file_info       [IN] 
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_pict_prepare_file_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pict_bridge_context.multi_file_select =
        (g_pict_bridge_context.jpg_file_cnt > PICT_MAX_MULTI_FILES)
        ? PICT_MAX_MULTI_FILES
        : g_pict_bridge_context.jpg_file_cnt;
    
    mmi_pict_mem_allocate_file_stat_buffer();
    mmi_pict_prepare_mark_several_final_statistics();
    
    if (mmi_frm_scrn_get_active_id() != SCR_ID_PICT_PROCESSING)
    {
        mmi_frm_node_struct node;
        mmi_frm_node_info_init(&node);
        node.id = SCR_ID_PICT_FILES;
        node.entry_proc = (mmi_proc_func)mmi_pict_entry_mark_several_final_statistics;
        mmi_frm_scrn_replace(g_pict_gid, SCR_ID_PICT_PROCESSING, &node);            
    }
    else
    {
        mmi_pict_entry_mark_several_final_statistics();
        mmi_frm_scrn_close(g_pict_gid, SCR_ID_PICT_PROCESSING);            
    }                
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_prepare_single_file_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_prepare_single_file_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fs_handle;
    FS_FileInfo fs_fileinfo;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pict_bridge_context.multi_file_select = 1;
    g_pict_bridge_context.curr_index = 0;
    g_pict_bridge_context.error_index = 0;

    mmi_ucs2cpy((S8*) g_pict_bridge_context.multi_file_path[0], 
        (S8*)srv_fmgr_path_get_filename_ptr((WCHAR*) g_pict_bridge_context.printing_filepath));

    fs_handle = FS_Open((U16*) g_pict_bridge_context.printing_filepath, FS_READ_ONLY);
    if (FS_GetFileInfo(fs_handle, &fs_fileinfo) == FS_NO_ERROR)
    {    
        g_pict_bridge_context.multi_file_size[0] = fs_fileinfo.DirEntry->FileSize;
        g_pict_bridge_context.multi_file_date[0] = fs_fileinfo.DirEntry->DateTime;
    }
    FS_Close(fs_handle);
}


#endif /* defined(__MMI_FMGR_MULTI_SELECT_SUPPORT__) */

#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_drm_jpg_file_check
 * DESCRIPTION
 *  Check if the selected file is DRM protected
 * PARAMETERS
 *  path            [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_pict_drm_jpg_file_check(U8 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE drm_handle;
    MMI_BOOL rtn = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drm_handle = DRM_open_file((PU16) path, FS_READ_ONLY, DRM_PERMISSION_PRINT);

    if (drm_handle > FS_NO_ERROR)
    {
        rtn = DRM_validate_permission(drm_handle, NULL, DRM_PERMISSION_PRINT);
        DRM_close_file(drm_handle);
    }
    else
    {
        rtn = MMI_FALSE;
    }

    return rtn;
}
#endif /* __DRM_SUPPORT__ */

#endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

