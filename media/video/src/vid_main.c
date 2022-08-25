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

/*******************************************************************************
 * Filename:
 * ---------
 *   vid_main.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of video module.
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

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =========*/


#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

/* local includes */
#include "med_global.h"
#include "med_vid_clip_features.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "vid_main.h"

#if defined (__MED_VID_DEC_MOD__) || defined (__MED_VID_ENC_MOD__)
#include "vid_if.h"
#include "fs_type.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "fs_func.h"
#include "mpl_player.h"
#include "drv_features.h"


vid_context_struct *vid_context_p = &(med_context.vid_context);
#ifdef __MED_VID_CLIP_MOD__
vid_clip_context_struct *vid_clip_context_p = &(med_context.vid_clip_context);
#endif
#define DUMMY_VIDEO_FILE_CONTENT L"d:\\video\\dummy.3gp\0\0\0\0\0\0\0\0\0\0\0\0"
#include "mpl_recorder.h"

#if defined(__VIDEO_CLIPPER_SUPPORT__)
#include "mpl_clipper.h"
#endif

#ifdef __MED_VID_ENC_MOD__
#if defined(MP4_ENCODE)
extern void mp4_recorder_main(ilm_struct *ilm_ptr);
#endif
#if defined(MJPG_ENCODE)
extern void avi_recorder_main(ilm_struct *ilm_ptr);
#endif

#if defined(__STREAM_SERVER_SUPPORT__) 
extern void rtp_recorder_main(ilm_struct *ilm_ptr);
#endif

#endif /* __MED_VID_ENC_MOD__ */

/*****************************************************************************
 * FUNCTION
 *  vid_create_dummy_video_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vid_create_dummy_video_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd = -1;
    kal_uint32 len;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __NVRAM_IN_USB_MS__
    if (stack_query_boot_mode() == USBMS_BOOT)
    {
        return;
    }
#endif /* __NVRAM_IN_USB_MS__ */ 

    /* creat folder */
    fd = FS_Open((kal_uint16*)VID_SYSTEM_FOLDER, FS_OPEN_DIR | FS_READ_ONLY);

    if (fd  >= 0)
    {
        /* path already exist */        
        FS_Close(fd);
    }
    else
    {
        /* file not exist */
        fd = FS_CreateDir((kal_uint16*)VID_SYSTEM_FOLDER);
    }

    if ((fd = FS_Open((kal_wchar*) VID_DUMMY_INIT_FILE, FS_READ_ONLY)) >= 0)
    {
        FS_Close(fd);
        return;
    }
    else if ((fd = FS_Open((kal_wchar*) VID_INIT_FILE, FS_READ_ONLY)) >= 0)
    {
        FS_Close(fd);
        /* FS_Rename((kal_wchar*)VID_INIT_FILE, (kal_wchar*)VID_DUMMY_INIT_FILE); */
        return;
    }
    fd = FS_Open((kal_wchar*) VID_DUMMY_INIT_FILE, FS_CREATE | FS_READ_WRITE);
    if (fd >= 0)
    {
        FS_Write(fd, DUMMY_VIDEO_FILE_CONTENT, kal_wstrlen(DUMMY_VIDEO_FILE_CONTENT) * ENCODE_BYTE, &len);
        FS_Close(fd);
    }

}




/*****************************************************************************
 * FUNCTION
 *  vid_startup_hdlr
 * DESCRIPTION
 *  This function is handle startup procedure of video module.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vid_startup_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

//    vid_create_dummy_video_file();

}

extern void med_mpl_async_callback_req_hdlr(ilm_struct *ilm_ptr);

/*****************************************************************************
 * FUNCTION
 *  vid_main
 * DESCRIPTION
 *  This function is main message dispatching function of video module.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vid_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(MP4_ENCODE)
    if ((ilm_ptr->msg_id >= MSG_ID_MEDIA_MP4_RECORDER_BEGIN  && ilm_ptr->msg_id <= MSG_ID_MEDIA_MP4_RECORDER_ENG))
    {
        mp4_recorder_main(ilm_ptr);
        return;
    }
#endif

#if defined(MJPG_ENCODE)
    if ((ilm_ptr->msg_id >= MSG_ID_MEDIA_AVI_RECORDER_BEGIN  && ilm_ptr->msg_id <= MSG_ID_MEDIA_AVI_RECORDER_ENG))
    {
        avi_recorder_main(ilm_ptr);
        return;
    }
#endif

#if defined(__VIDEO_CLIPPER_SUPPORT__)
    if ((ilm_ptr->msg_id >= MSG_ID_MEDIA_VIDEO_CLIPPER_RECORDER_BEGIN  && ilm_ptr->msg_id <= MSG_ID_MEDIA_VIDEO_CLIPPER_RECORDER_ENG))
    {
        video_clipper_main(ilm_ptr);
        return;
    }
#endif

#if defined(__STREAM_SERVER_SUPPORT__)
	if ((ilm_ptr->msg_id >= MSG_ID_MEDIA_RTP_RECORDER_BEGIN  && ilm_ptr->msg_id <= MSG_ID_MEDIA_RTP_RECORDER_ENG))
	{
		rtp_recorder_main(ilm_ptr);
		return;
	}
#endif


    switch (ilm_ptr->msg_id)
    {
    #if defined(__MED_VID_DEC_MOD__)
    /**********************************************
     * VID DEC -- Target
     **********************************************/
    #if defined(__MTK_TARGET__)
        case MSG_ID_MEDIA_VID_OPEN_REQ:
            vid_open_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_STOP_REQ:
            vid_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_CLOSE_REQ:
            vid_close_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_PLAY_REQ:
            vid_play_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_SEEK_REQ:
            vid_seek_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_GET_FRAME_REQ:
            vid_get_frame_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_GET_PLAY_TIME_REQ: 
            vid_get_play_time_req_hdlr(ilm_ptr);
            break;  
    
        case MSG_ID_MEDIA_VID_SET_PARAM_REQ:
            vid_set_param_req_hdlr(ilm_ptr);
            break;
       
        case MSG_ID_MEDIA_VID_GET_PARAM_REQ:
            vid_get_param_req_hdlr(ilm_ptr);
            break;    
      
    #if !defined(__MED_IN_ASM__)        
        case MSG_ID_MEDIA_VID_CHECK_MED_READY_REQ:
            vid_check_med_ready_req_hdlr(ilm_ptr);
            break;
    #endif        
        case MSG_ID_MEDIA_VID_PAUSE_VISUAL_UPDATE_REQ:
            vid_pause_visual_update_req_hdlr(ilm_ptr);
            break;            
        case MSG_ID_MEDIA_VID_RESUME_VISUAL_UPDATE_REQ:
            vid_resume_visual_update_req_hdlr(ilm_ptr);
            break;    

    #else /* __MTK_TARGET__ */
    
    /**********************************************
     * VID DEC -- MoDIS
     **********************************************/
        case MSG_ID_MEDIA_VID_OPEN_REQ:
            vid_open_req_hdlr_modis(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_STOP_REQ:
            vid_stop_req_hdlr_modis(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_CLOSE_REQ:
            vid_close_req_hdlr_modis(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_PLAY_REQ:
            vid_play_req_hdlr_modis(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_SEEK_REQ:
            vid_seek_req_hdlr_modis(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_GET_FRAME_REQ:
            vid_get_frame_req_hdlr_modis(ilm_ptr);
            break;           
        case MSG_ID_MEDIA_VID_PAUSE_VISUAL_UPDATE_REQ:
            vid_update_layer_pause_req_hdlr_modis(ilm_ptr);
            break;            
        case MSG_ID_MEDIA_VID_RESUME_VISUAL_UPDATE_REQ:
            vid_update_layer_resume_req_hdlr_modis(ilm_ptr);
            break;    
        case MSG_ID_MEDIA_VID_GET_PARAM_REQ:
            vid_get_param_req_hdlr_modis(ilm_ptr);
            break;
    #endif /* __MTK_TARGET__ */
    #endif /* defined(__MED_VID_DEC_MOD__)  */


    #if defined(__MED_VID_PDL_MOD__)
        case MSG_ID_MEDIA_VID_GET_PDL_PRECENT_REQ:
            vid_get_pdl_percent_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_GET_PDL_MAX_TIME_REQ:
            vid_get_pdl_max_time_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_CHECK_IS_PDL_REQ:
            vid_check_is_pdl_req_hdlr(ilm_ptr);
            break;
    #endif /* defined(__MED_VID_PDL_MOD__) */

    #if defined(__MED_VID_ENC_MOD__)
        case MSG_ID_MEDIA_VID_EVENT_IND:
            vid_event_ind_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_REC_SET_PARAM_REQ:
            vid_recorder_set_param_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_GET_FAST_ZOOM_FACTOR_REQ:
            vid_get_fast_zoom_factor_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_STOP_FAST_ZOOM_REQ:
            vid_stop_fast_zoom_req_hdlr(ilm_ptr);        
            break;
        case MSG_ID_MEDIA_VID_START_FAST_ZOOM_REQ:
            vid_start_fast_zoom_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_GET_RESERVED_DISC_SIZE_REQ:
            vid_get_reserved_disc_size_req_hdlr(ilm_ptr);
            break;

        case MSG_ID_MEDIA_VID_POWER_UP_REQ:
            vid_power_up_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_POWER_DOWN_REQ:
            vid_power_down_req_hdlr(ilm_ptr);
            break;
#ifdef __CAM_AUTO_FOCUS__
        case MSG_ID_MEDIA_VID_GET_FOCUS_ZONE_REQ:
            vid_get_focus_zone_req_hdlr(ilm_ptr);
            break;
#endif           
        case MSG_ID_MEDIA_VID_PREVIEW_REQ:        
            vid_preview_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_REC_STOP_REQ:
            vid_rec_stop_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_RECORD_REQ:
            vid_record_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_PAUSE_REQ:
            vid_pause_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_RESUME_REQ:
            vid_resume_req_hdlr(ilm_ptr);
            break;            
        case MSG_ID_MEDIA_VID_FILE_MERGE_REQ:
            vid_file_merge_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_UPDATE_BLT_PAUSE_REQ:
            vid_update_blt_pause_req_hdlr(ilm_ptr);
            break;            
        case MSG_ID_MEDIA_VID_UPDATE_BLT_RESUME_REQ:
            vid_update_blt_resume_req_hdlr(ilm_ptr);
            break;             
        case MSG_ID_MEDIA_VID_CLEAN_FILE_REQ:
            vid_clean_file_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_GET_RECORD_TIME_REQ:
            vid_get_record_time_req_hdlr(ilm_ptr);    
            break;
        case MSG_ID_MEDIA_VID_GET_RECORD_FRAME_NUM_REQ:
            vid_get_record_frame_num_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_GET_RECORD_SIZE_REQ:
            vid_get_record_size_req_hdlr(ilm_ptr);
            break;
        #ifndef __LOW_COST_SUPPORT_COMMON__         
        case MSG_ID_MEDIA_VID_RECORD_YUV_REQ:
            vid_rec_set_record_yuv_req(ilm_ptr);
            break;
        #endif    
    #endif /* defined(__MED_VID_ENC_MOD__) */
    
        case MSG_ID_MEDIA_MPL_ASYNC_CALLBACK_REQ:
            {
                med_mpl_async_callback_req_hdlr(ilm_ptr);
                break;
            }

    #ifdef __MED_VID_CLIP_MOD__
        case MSG_ID_MEDIA_VID_CLIP_OPEN_REQ:
            vid_clipper_open_req_hdlr(ilm_ptr);
            break; 
        case MSG_ID_MEDIA_VID_CLIP_PREPARE_REQ:
            vid_clipper_prepare_req_hdlr(ilm_ptr);
            break;             
        case MSG_ID_MEDIA_VID_CLIP_START_REQ:
            vid_clipper_start_req_hdlr(ilm_ptr);
            break;        
        case MSG_ID_MEDIA_VID_CLIP_STOP_REQ:
            vid_clipper_stop_req_hdlr(ilm_ptr);
            break;   
        case MSG_ID_MEDIA_VID_CLIP_CLOSE_REQ:
            vid_clipper_close_req_hdlr(ilm_ptr);
            break;  
        case MSG_ID_MEDIA_VID_CLIP_GET_PARAM_REQ:
            vid_clipper_get_param_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_VID_CLIP_EVENT_IND:
            vid_clipper_event_ind_hdlr(ilm_ptr);
            break;
    #endif /* __MED_VID_CLIP_MOD__ */
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vid_init
 * DESCRIPTION
 *  This function is used to init video module of media task.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
#ifdef __MED_VID_DEC_MOD__
extern mpl_player_t *player_p;
#endif
kal_bool vid_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //VAL_Init();
    vid_context_p->is_power_on = KAL_FALSE;
    vid_context_p->state = VID_IDLE;
    //vid_context_p->aud_state = VID_AUD_IDLE;
    vid_context_p->vid_event = kal_create_event_group("vid_events");
    vid_context_p->em_mode = VID_EM_MODE_DISABLED;
    vid_context_p->vt_mode = KAL_FALSE;
    
    vid_context_p->bit_stream_type = MPL_RECORDER_FORMAT_MAX; /* not initialized */

#ifdef __MED_VID_DEC_MOD__
    player_p = NULL;
#endif
    vid_context_p->current_time = 0;
    vid_context_p->total_time = 0;
    vid_context_p->display_width = 0;
    vid_context_p->display_height = 0;
    vid_context_p->image_width = 0;
    vid_context_p->image_height = 0;
    vid_context_p->file_size = 0;
    vid_context_p->storing_path[0] = 0;

#ifdef __MED_VID_CLIP_MOD__ 
    vid_clip_context_p->state = 0;
    vid_clip_context_p->seq_num = 0;
#endif
    return KAL_TRUE;
}
 
#endif /* defined (__MED_VID_DEC_MOD__) || defined (__MED_VID_ENC_MOD__) */
#endif /* MED_NOT_PRESENT */ 

