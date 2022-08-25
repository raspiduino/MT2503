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
 * SndrecUtil.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for sound recorder.
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
#if defined(__MMI_SOUND_RECORDER__)
#include "FileMgrSrvGProt.h"
#include "SndrecProt.h"

#include "MMIDataType.h"
#include "mmi_rp_file_type_def.h"
#include "string.h"
#include "stack_config.h"
#include "SndrecDef.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "fs_errcode.h"
#include "Unicodexdcl.h"
#include "fs_func.h"
#include "fs_type.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_app_soundrecorder_def.h"
#include "wgui_categories_util.h"
#include "AlertScreen.h"
#include "gui_data_types.h"
#include "GlobalResDef.h"

/* For DCM */
#if defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
#include "mmi_ap_dcm_config.h"
#endif

#define __SNDREC_UTIL_FMGR__

#ifdef __MMI_SNDREC_SKIN__

/****************************************************************************
* Static Variable
*****************************************************************************/
#ifdef __MMI_AP_DCM_SNDREC__
#pragma arm section rodata = "DYNAMIC_CODE_SNDREC_RODATA",code = "DYNAMIC_CODE_SNDREC_ROCODE"
#endif

static mmi_sndrec_fmgr_reclist_struct g_sndrec_filelist;
extern mmi_sndrec_cntx g_sndrec_cntx;

#ifdef __MMI_AP_DCM_SNDREC__
#pragma arm section rodata , code
#endif

/****************************************************************************
* Function Body
*****************************************************************************/
static mmi_ret mmi_sndrec_util_reclist_create_proc_func(mmi_event_struct *param);
static mmi_ret mmi_sndrec_util_reclist_load_proc_func(mmi_event_struct *param);


#ifdef __MMI_AP_DCM_SNDREC__
#pragma arm section rodata = "DYNAMIC_CODE_SNDREC_RODATA",code = "DYNAMIC_CODE_SNDREC_ROCODE"
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_util_fmgr_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_util_fmgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_sndrec_filelist.is_created = MMI_FALSE;
    g_sndrec_filelist.curr_index = -1;
	g_sndrec_filelist.curr_index_async = -1;
    g_sndrec_filelist.fl_hdl = 0;
    g_sndrec_filelist.total_num = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_util_reclist_check_valid
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *   
 *****************************************************************************/
MMI_BOOL mmi_sndrec_util_reclist_check_valid(void)
{	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_sndrec_filelist.is_created)
	{
        ret = srv_fmgr_filelist_count(g_sndrec_filelist.fl_hdl);
		MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_SNDREC_CLIST_COUNT,ret);
		if ((ret == g_sndrec_filelist.total_num) && (ret > -1) && (g_sndrec_filelist.curr_index >= 0))
		{			
			return MMI_TRUE;
		}
		else
		{
			mmi_sndrec_util_reclist_free();
		}
	}
	return MMI_FALSE;	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_util_reclist_ready
 * DESCRIPTION
 *   This function is call after asyc create list success!
 * PARAMETERS
 *  fl_hdl      [IN]        
 *  total       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_util_reclist_ready(SRV_FMGR_FILELIST_HANDLE fl_hdl, S32 total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(fl_hdl);
    g_sndrec_filelist.is_created = MMI_TRUE;
    g_sndrec_filelist.is_process = MMI_FALSE;
    g_sndrec_filelist.fl_hdl = fl_hdl;
    g_sndrec_filelist.total_num = total;
    g_sndrec_filelist.curr_index_async = 0;
    g_sndrec_filelist.curr_index = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_util_get_info
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_util_get_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ASSERT(g_sndrec_filelist.fl_hdl);
    g_sndrec_filelist.total_num = srv_fmgr_filelist_count(g_sndrec_filelist.fl_hdl);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_util_check_created
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *   
 *****************************************************************************/
MMI_BOOL mmi_sndrec_util_check_created(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_sndrec_filelist.is_created) && (g_sndrec_filelist.curr_index != -1))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

MMI_BOOL mmi_sndrec_util_reclist_query_is_process()
{
    return g_sndrec_filelist.is_process;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_util_reclist_create_proc_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_sndrec_util_reclist_create_proc_func(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_count;
    srv_fmgr_filelist_refresh_result_event_struct *evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt = (srv_fmgr_filelist_refresh_result_event_struct*)param;
    
    switch(param->evt_id)
    {
        case EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT:
            {
                file_count = srv_fmgr_filelist_count(g_sndrec_filelist.fl_hdl);
                if (file_count == 0)
                {
                    mmi_sndrec_util_reclist_free();
                    break;
                }
                else
                {
                    mmi_sndrec_reclist_create_callback(evt->handle, 0, evt->total_count, evt->total_count);
                }
            }                  
            break;
        case EVT_ID_SRV_FMGR_FILELIST_LOAD_RESULT:
            {
                file_count = srv_fmgr_filelist_count(g_sndrec_filelist.fl_hdl);
                if (file_count == 0)
                {
                    mmi_sndrec_util_reclist_free();
                    break;
                }
                else
                {
                    /* Call the set async function */
                    mmi_sndrec_util_curridx_set_async();
                }
            }                  
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_util_reclist_create
 * DESCRIPTION
 *  Create a filelist by filemgr
 * PARAMETERS
 *  void
 * RETURNS
 *  file numbers in filelist
 *****************************************************************************/
S32 mmi_sndrec_util_reclist_create(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    FMGR_FILTER filter;
    S32  fs_ret = 0;	
     U16 filepath[MMI_SNDREC_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_util_filter_set(&filter);
    mmi_sndrec_get_file_path(filepath);
    g_sndrec_filelist.is_created = MMI_FALSE;
    fs_ret = srv_fmgr_folder_filelist_create((WCHAR*)filepath, &filter, 0, NULL, 0, &g_sndrec_filelist.fl_hdl);	
    srv_fmgr_filelist_refresh(
        g_sndrec_filelist.fl_hdl,
        NULL,
        0,
        0,
        mmi_sndrec_util_reclist_create_proc_func,
        (void*)NULL);
     g_sndrec_filelist.is_process = MMI_TRUE;
    return fs_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_util_reclist_free
 * DESCRIPTION
 *  free filelist create in filemgr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_util_reclist_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ASSERT(g_sndrec_filelist.fl_hdl); */
	//kal_prompt_trace(MOD_MMI,"[SNDREC][FMR REVISE]Free file list: %d", g_sndrec_filelist.fl_hdl);
	StopTimer(SNDREC_TIMER_FILELIST_SEEK);
	if (g_sndrec_filelist.fl_hdl > 0)
	{
        srv_fmgr_filelist_destroy(g_sndrec_filelist.fl_hdl);
	}    
    g_sndrec_filelist.fl_hdl = 0;
    g_sndrec_filelist.curr_index = -1;
	g_sndrec_filelist.curr_index_async = -1;
    g_sndrec_filelist.total_num = 0;    
	g_sndrec_filelist.is_created = MMI_FALSE;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_util_curridx_set_async
 * DESCRIPTION
 *  call mmi_sndrec_reclist_ready before call this function
 * PARAMETERS
 *  void
 *  filename(?)     [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_util_curridx_set_async(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    S32 result;
    U32 tmp_count;
    U8 res = 2; /* 0 -- set index fail, 1 -- set index success, 2 -- need next find, 3 -- need to reload list */
    WCHAR  get_filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if the curr_index_async if valid */
    g_sndrec_filelist.total_num = srv_fmgr_filelist_count(g_sndrec_filelist.fl_hdl);
    if (g_sndrec_filelist.curr_index_async >= g_sndrec_filelist.total_num || g_sndrec_filelist.curr_index_async < 0)
    {
        res = 0;
    }
    else 
    {
        for (tmp_count = 0 ; tmp_count < 50 ; tmp_count++)
        {
            ret = srv_fmgr_filelist_get_filename(
                g_sndrec_filelist.fl_hdl,
                g_sndrec_filelist.curr_index_async,
                (WCHAR*) get_filename,
                sizeof(get_filename));

            if (FS_NO_ERROR == ret)
            {	
                if (0 == mmi_wcscmp(g_sndrec_cntx.record.displayname, get_filename))
                {	
                    /*set index success*/
                    g_sndrec_filelist.curr_index = g_sndrec_filelist.curr_index_async;
                    res = 1;
                    break; 
                }
                else
                {
                    if(g_sndrec_filelist.curr_index_async++ >= g_sndrec_filelist.total_num)
                    {
                        /*set index success*/
                        res = 0;
                        break;
                    }
                }
            }
            else if ( ret == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY || ret == SRV_FMGR_FILELIST_ERROR_BUSY)
            {
                /* In case of File Not ready error, need to load the file at that index */
                result = srv_fmgr_filelist_load_file(
                    g_sndrec_filelist.fl_hdl,
                    g_sndrec_filelist.curr_index_async,
                    mmi_sndrec_util_reclist_create_proc_func,
                    NULL);
                if ( result == 0)
                {
                    /* successful in sending load request should exit this function, result will be in proc */
                    res = 3;
                    break;
                }
                else if ( result == SRV_FMGR_FILELIST_ERROR_FILE_READY)
                {
                    /* File already loaded in that case load_file will return this error */
                    /* In this case do nothing and continue with getting filename */
                    continue;
                }
                else
                {
                    /* some error */
                    res = 0;
                    break;
                }
            }
            else /* call filemgr function return error */
            {
                if ( srv_fmgr_filelist_is_dirty(g_sndrec_filelist.fl_hdl) == MMI_TRUE)
                {
                    mmi_sndrec_error_hdlr(ret, MMI_FALSE);
                }
                res = 0;
                break;
            }
        }
    }
    if (1 == res)
    {
        mmi_sndrec_reclist_set_callback(MMI_TRUE); 
    }
    else if (0 ==res)
    {
        mmi_sndrec_reclist_set_callback(MMI_FALSE);
    }
    else if (2 ==  res)
    {
        StartTimer(SNDREC_TIMER_FILELIST_SEEK, 40, mmi_sndrec_util_curridx_set_async);
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_SET_ASYNC_STATUS, res);    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_util_get_next_pre_rec
 * DESCRIPTION
 *  get next filename in filelist
 * PARAMETERS
 *  filename    [IN]
 *  displayname     [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_sndrec_util_get_next_pre_rec(MMI_BOOL is_next, CHAR *displayname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_sndrec_filelist.curr_index == -1 || g_sndrec_filelist.total_num <= 0)
    {
        return MMI_FALSE;
    }

    if (is_next == MMI_TRUE )
    {
        g_sndrec_filelist.curr_index++;
    }
    else
    {
        g_sndrec_filelist.curr_index--;
    }

    if(g_sndrec_filelist.curr_index >= g_sndrec_filelist.total_num)
    {
        g_sndrec_filelist.curr_index = 0; 
    }
    else if(g_sndrec_filelist.curr_index < 0)
    {
        g_sndrec_filelist.curr_index = g_sndrec_filelist.total_num - 1; 
    }

    result = mmi_sndrec_util_get_filename( (CHAR*) displayname);

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_util_get_filename
 * DESCRIPTION
 *  get filename in filelist
 * PARAMETERS
 *  
 *  displayname     [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_sndrec_util_get_filename(CHAR *displayname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    srv_fmgr_fileinfo_struct file_info;
    WCHAR get_filename[SRV_FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_fmgr_filelist_get_fileinfo(g_sndrec_filelist.fl_hdl, g_sndrec_filelist.curr_index, &file_info);
    srv_fmgr_filelist_get_filename(
        g_sndrec_filelist.fl_hdl,
        g_sndrec_filelist.curr_index,
        (WCHAR*) get_filename,
        SRV_FMGR_PATH_BUFFER_SIZE);

    if (FS_NO_ERROR == ret)
    {
        mmi_ucs2cpy(displayname, (CHAR *)get_filename);      
        return MMI_TRUE;
    }
    else if(ret == SRV_FMGR_FILELIST_ERROR_FILE_NOT_READY)
    {
        srv_fmgr_filelist_load_file(
            g_sndrec_filelist.fl_hdl,
            g_sndrec_filelist.curr_index,
            mmi_sndrec_util_reclist_load_proc_func,
            NULL);
        return MMI_FALSE;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_SNDREC_PLAY_NEXT_FAIL, ret);
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_util_reclist_load_proc_func
 * DESCRIPTION
 *  get next filename in filelist
 * PARAMETERS
 *  
 *  
 * RETURNS
 *  
 *****************************************************************************/

static mmi_ret mmi_sndrec_util_reclist_load_proc_func(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_count;
    //srv_fmgr_filelist_refresh_result_event_struct *evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
        case EVT_ID_SRV_FMGR_FILELIST_LOAD_RESULT:
            {
                file_count = srv_fmgr_filelist_count(g_sndrec_filelist.fl_hdl);
                if (file_count == 0)
                {
                    mmi_sndrec_util_reclist_free();
                    break;
                }
                else
                {
                    /* Able to laod the list successfully will get the filename and call the play function */
					mmi_sndrec_reclist_play_callback();
                }
            }                  
            break;
    }

    return MMI_RET_OK;
}

#endif /* __MMI_SNDREC_SKIN__ */ 

#define __SNDREC_UTIL_FS__


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_fs_check_folder
 * DESCRIPTION
 *  check folder if exist, if not, try to create a new one.
 * PARAMETERS
 *  filepath        [?]         
 *  filename(?)     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_sndrec_fs_check_folder(U16 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S32 attribut;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    attribut = FS_GetAttributes(filepath);
    if (((FS_ATTR_DIR & attribut) == 0) || attribut < 0)
    {
        result = FS_CreateDir(filepath);
        if (result < 0)
        {
            if (result == FS_MEDIA_CHANGED)
            {
                mmi_popup_display_ext(STR_GLOBAL_INSERT_MEMORY_CARD, MMI_EVENT_FAILURE, NULL);
			}
            else
            {
                /* Only show popup if happened due to some other error, not due to drive not present */
                if(srv_fmgr_drv_is_accessible((U8)SRV_FMGR_PUBLIC_DRV) != MMI_FALSE)
                {
                    mmi_popup_display_ext(srv_fmgr_fs_error_get_string(result),
                        (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(result),
                        NULL);
                }
            }
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_fs_check_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file        [IN]
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_sndrec_fs_check_file(U16 *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    U32 file_size = 0;
    U16 fullname[MMI_SNDREC_FULL_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sndrec_get_full_file_name(fullname,file);
    handle = FS_Open(fullname, FS_READ_ONLY);
    if (handle >= FS_NO_ERROR)
    {
       FS_GetFileSize(handle,&file_size);
       FS_Close(handle);
       #if defined (__MTK_TARGET__)     
        if(file_size == 0)
        {
            FS_Delete((const WCHAR*)file);            
            return MMI_FALSE;	  
        }
        else
        #endif	
        {
            return MMI_TRUE;
        } 
    }
    else
    {
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_sndrec_util_filter_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filter    [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sndrec_util_filter_set(FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);
#ifndef MT6205B
    FMGR_FILTER_SET(filter, FMGR_TYPE_WAV);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AMR);
#endif /* MT6205B */ 
#if defined(AMRWB_ENCODE) && defined(AMRWB_DECODE)
    FMGR_FILTER_SET(filter, FMGR_TYPE_AWB);
#endif 
    FMGR_FILTER_SET(filter, FMGR_TYPE_VM);
#ifdef __VORBIS_ENCODE__
    FMGR_FILTER_SET(filter, FMGR_TYPE_OGG);
#endif
}

#ifdef __MMI_AP_DCM_SNDREC__
#pragma arm section rodata , code
#endif

#endif /* (defined(__MMI_SOUND_RECORDER__)) */ 

