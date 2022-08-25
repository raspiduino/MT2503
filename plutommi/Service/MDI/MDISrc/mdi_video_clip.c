/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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

/*******************************************************************************
 * Filename:
 * ---------
 *  mdi_video_clip.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface to access video clipper related functions.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
#include "mdi_video_clip.h"
#ifdef __MDI_VIDEO_CLIP_SUPPORT__
#include "MMI_features.h" 
#include "med_vid_clip_struct.h"
#include "med_vid_clip_api.h"

#include "MMIDataType.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "mmi_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "stack_msgs.h"
#include "stack_config.h"
#include "mmi_rp_srv_mdi_def.h"
#include "GlobalResDef.h"
#include "med_main.h"
#include "fs_gprot.h"
#include "FileMgrSrvGProt.h"
#include "med_utility.h"
#include "mdi_include.h"
#include "Unicodexdcl.h"
#include "FileMgrResDef.h"

/***************************************************************************** 
* Typedef 
*****************************************************************************/
/* vid clip state machine */
typedef enum
{
    VIDEO_CLIP_STATE_IDLE = 0,
    VIDEO_CLIP_STATE_PROCESSING,
    
    VIDEO_CLIP_STATE_COUNT
    
}mdi_vid_clip_state_enum;


typedef struct
{
    U16     app_id;
    void*   user_data;
    S32     seq_num;
    WCHAR    temp_folderpath[SRV_FMGR_PATH_MAX_LEN + 1];
    mdi_vid_clip_state_enum state;
} mdi_vid_clip_cntx_struct;

mdi_vid_clip_cntx_struct g_mdi_vid_clip_cntx;

static mdi_video_clip_prepare_callback g_mdi_video_clip_prepare_callback;
static mdi_video_clip_result_callback g_mdi_video_clip_result_callback;


static int mdi_video_clip_get_temp_working_folder_path(WCHAR* dst_filepath, WCHAR* temp_folderpath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* ptr;
    U32 len;
    int ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if(!dst_filepath) return -1;

    for(ptr = dst_filepath; *ptr; ptr++);

    for(; *ptr!='\\' && ptr != (WCHAR*)dst_filepath; ptr--);

//    if(*ptr == '\\')
//        ptr++;

    len = (ptr - dst_filepath)+1;
    mmi_wcsncpy(temp_folderpath, dst_filepath, len);
    mmi_wcscat(temp_folderpath,(WCHAR*) L"temp\\");
    ret = FS_CreateDir((WCHAR *)temp_folderpath);

    return ret;
}


static void mdi_video_clip_delete_temp_working_folder(WCHAR* temp_folderpath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (temp_folderpath)
        FS_Delete(temp_folderpath);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_clip_prepare_hdlr
 * DESCRIPTION
 *  Video clip prepare handler
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  Percentage value
 *****************************************************************************/
static void mdi_video_clip_prepare_hdlr(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    media_vid_clip_prepare_cnf_struct *ind_p = (media_vid_clip_prepare_cnf_struct*)msg_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ind_p->result == MED_RES_OK)
        result = MDI_RES_VDOCLIP_SUCCEED;
    else
        result = MDI_RES_VDOCLIP_ERR_FAILED;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VDOCLIPPER_PREPARE_RESULT, result);
    
    if (g_mdi_video_clip_prepare_callback)
        g_mdi_video_clip_prepare_callback(result, g_mdi_vid_clip_cntx.user_data);

}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_clip_result_hdlr
 * DESCRIPTION
 *  Video clip result handler
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  Percentage value
 *****************************************************************************/
static void mdi_video_clip_result_hdlr(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT result;
    media_vid_clip_finish_ind_struct *ind_p = (media_vid_clip_finish_ind_struct*)msg_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ind_p->result == MED_RES_OK)
        result = MDI_RES_VDOCLIP_SUCCEED;
    else if (ind_p->result == MED_RES_DISC_FULL)
        result = MDI_RES_VDOCLIP_ERR_DISK_FULL;
    else if (ind_p->result == MED_RES_NO_DISC)
        result = MDI_RES_VDOCLIP_ERR_NO_DISK;    
    else
        result = MDI_RES_VDOCLIP_ERR_FAILED;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VDOCLIPPER_CLIP_RESULT, result);
    
    if (g_mdi_vid_clip_cntx.seq_num == ind_p->seq_num)
    {
        if (g_mdi_video_clip_result_callback)
            g_mdi_video_clip_result_callback(result, g_mdi_vid_clip_cntx.user_data);
    }
    mdi_video_clip_delete_temp_working_folder(g_mdi_vid_clip_cntx.temp_folderpath);
}


void *mdi_video_clip_alloc_mem(kal_uint8 mem_type, kal_uint32 mem_size, char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mdi_util_alloc_mem(g_mdi_vid_clip_cntx.app_id, mem_type, mem_size, file_p, line_p);
}


void mdi_video_clip_free_mem(kal_uint8 mem_type, void **mem_addr, char* file_p, long line_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_util_free_mem(g_mdi_vid_clip_cntx.app_id, mem_type, mem_addr, file_p, line_p);
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_clip_open
 * DESCRIPTION
 *  Stop clipping a video file
 * PARAMETERS
 *  user_data       [IN]        user data
 * RETURN VALUES
 *  MDI_RES_VDOCLIP_SUCCEED      Success
 *  MDI_RES_VDOCLIP_ERR_FAILED   Failure
 *****************************************************************************/
MDI_RESULT mdi_video_clip_open(U16 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ret = MED_RES_OK;
    MDI_RESULT error_code = MDI_RES_VDOCLIP_SUCCEED;
    media_vid_clip_open_req_struct data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mdi_vid_clip_cntx.app_id = app_id;

    data.alloc_mem = mdi_video_clip_alloc_mem;
    data.free_mem = mdi_video_clip_free_mem;
    #if defined(__MTK_TARGET__)
    ret = media_vid_clip_open(stack_get_active_module_id(), &data);
    #endif
    
    if (ret == MED_RES_OK)
    {
        error_code = MDI_RES_VDOCLIP_SUCCEED;
    }
    else
        error_code = MDI_RES_VDOCLIP_ERR_FAILED;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VDOCLIPPER_OPEN, error_code);

    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_clip_prepare
 * DESCRIPTION
 *  Prepare to clip a video file
 * PARAMETERS
 *  setting_p       [IN]        setting structure
 *  callback        [IN]        callback function pointer
 *  user_data       [IN]        user data
 * RETURN VALUES
 *  MDI_RES_VDOCLIP_SUCCEED      Success
 *  MDI_RES_VDOCLIP_ERR_FAILED   Failure
 *****************************************************************************/
MDI_RESULT mdi_video_clip_prepare(mdi_video_clip_prepare_struct* setting_p, mdi_video_clip_prepare_callback callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_clip_prepare_req_struct clip_data;
    U32 ret = MED_RES_OK;
    MDI_RESULT error_code = MDI_RES_VDOCLIP_SUCCEED;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mdi_vid_clip_cntx.user_data = user_data;
    
    // TODO: temp folder buffer moves to app memory
    mdi_video_clip_get_temp_working_folder_path(setting_p->dst_filepath, g_mdi_vid_clip_cntx.temp_folderpath);
    
    clip_data.start_time = setting_p->start_time;
    clip_data.end_time = setting_p->end_time;
    clip_data.src_filepath = (void*)setting_p->src_filepath;
    clip_data.dst_filepath = (void*)setting_p->dst_filepath;
    clip_data.work_filepath = g_mdi_vid_clip_cntx.temp_folderpath;
    
    g_mdi_video_clip_prepare_callback = callback;

    SetProtocolEventHandler(mdi_video_clip_prepare_hdlr, MSG_ID_MEDIA_VID_CLIP_PREPARE_CNF);

    #if defined(__MTK_TARGET__)
    ret = media_vid_clip_prepare(stack_get_active_module_id(), &clip_data);
    #endif
    
    if (ret == MED_RES_OK)
    {        
        error_code = MDI_RES_VDOCLIP_SUCCEED;
    }
    else
        error_code = MDI_RES_VDOCLIP_ERR_FAILED;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VDOCLIPPER_PREPARE, error_code);

    return error_code;
        
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_clip_start
 * DESCRIPTION
 *  Stop clipping a video file
 * PARAMETERS
 *  callback        [IN]        callback function pointer
 *  user_data       [IN]        user data
 * RETURN VALUES
 *  MDI_RES_VDOCLIP_SUCCEED      Success
 *  MDI_RES_VDOCLIP_ERR_FAILED   Failure
 *****************************************************************************/
MDI_RESULT mdi_video_clip_start(mdi_video_clip_result_callback callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ret = MED_RES_OK;
    MDI_RESULT error_code = MDI_RES_VDOCLIP_SUCCEED;
    media_vid_clip_start_req_struct data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mdi_vid_clip_cntx.user_data = user_data;
    data.seq_num = g_mdi_vid_clip_cntx.seq_num;

    SetProtocolEventHandler(mdi_video_clip_result_hdlr, MSG_ID_MEDIA_VID_CLIP_FINISH_IND);

    g_mdi_video_clip_result_callback = callback;

    #if defined(__MTK_TARGET__)
    ret = media_vid_clip_start(stack_get_active_module_id(), &data);
    #endif
    
    if (ret == MED_RES_OK)
    {
        error_code = MDI_RES_VDOCLIP_SUCCEED;
    }
    else
        error_code = MDI_RES_VDOCLIP_ERR_FAILED;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VDOCLIPPER_START, error_code);

    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_clip_stop
 * DESCRIPTION
 *  Stop clipping a video file
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOCLIP_SUCCEED      Success
 *  MDI_RES_VDOCLIP_ERR_FAILED   Failure
 *****************************************************************************/
MDI_RESULT mdi_video_clip_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ret = MED_RES_OK;
    MDI_RESULT error_code = MDI_RES_VDOCLIP_SUCCEED;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mdi_vid_clip_cntx.seq_num++;

    #if defined(__MTK_TARGET__)
    ret = media_vid_clip_stop(stack_get_active_module_id());
    #endif

    if (ret == MED_RES_OK)
    {
        error_code = MDI_RES_VDOCLIP_SUCCEED;
    }
    else
        error_code = MDI_RES_VDOCLIP_ERR_FAILED;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VDOCLIPPER_STOP, error_code);

    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_clip_close
 * DESCRIPTION
 *  Stop clipping a video file
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MDI_RES_VDOCLIP_SUCCEED      Success
 *  MDI_RES_VDOCLIP_ERR_FAILED   Failure
 *****************************************************************************/
MDI_RESULT mdi_video_clip_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ret = MED_RES_OK;
    MDI_RESULT error_code = MDI_RES_VDOCLIP_SUCCEED;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MTK_TARGET__)
    ret = media_vid_clip_close(stack_get_active_module_id());
    #endif

    if (ret == MED_RES_OK)
    {
        error_code = MDI_RES_VDOCLIP_SUCCEED;
        mdi_video_clip_delete_temp_working_folder(g_mdi_vid_clip_cntx.temp_folderpath);
    }
    else
        error_code = MDI_RES_VDOCLIP_ERR_FAILED;

    MMI_TRACE(MMI_MEDIA_TRC_G4_MDI, MDI_TRC_VDOCLIPPER_CLOSE, error_code);
    
    return error_code;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_clip_get_processing_ratio
 * DESCRIPTION
 *  Get the percentage of clipping process
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  Percentage value
 *****************************************************************************/
U32 mdi_video_clip_get_processing_ratio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_clip_get_param_req_struct data;
    U32 value;
    U32 ret = MED_RES_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: change to MPL param enum
    data.param_id = MDI_VIDEO_CLIP_PARAM_PROCESS_RATIO;
    data.value = &value;

    ret = media_vid_clip_get_param(stack_get_active_module_id(), &data);
     
    return value;
}


/*****************************************************************************
 * FUNCTION
 *  mdi_video_clip_get_error_info
 * DESCRIPTION
 *  Get the error string and error type
 * PARAMETERS
 *  error_code   [IN]     Error code got from MDI APIs
 *  popup_type   [OUT]    Popup_type of this error_code 
 * RETURNS
 *  string_id
 *****************************************************************************/
MMI_ID_TYPE mdi_video_clip_get_error_info(MDI_RESULT error_code, mmi_event_notify_enum* popup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE string_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *popup_type = MMI_EVENT_FAILURE;
    switch (error_code)
    {
        case MDI_RES_VDOCLIP_ERR_FAILED:
            string_id = STR_GLOBAL_ERROR;
            break;
        case MDI_RES_VDOCLIP_ERR_DISK_FULL:
            string_id = FMGR_FS_DISK_FULL_TEXT;
            break;
        case MDI_RES_VDOCLIP_ERR_NO_DISK:
            string_id = FMGR_FS_DRIVE_NOT_FOUND_TEXT;
            break;             
        default:
            string_id = STR_GLOBAL_ERROR;
            break;
    }
    return string_id;
}


#endif /* __MDI_VIDEO_CLIP_SUPPORT__ */
