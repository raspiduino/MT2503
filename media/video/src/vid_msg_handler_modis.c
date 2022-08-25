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
 *   vid_msg_handler_modis.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes message handle functions of video module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef MED_NOT_PRESENT

#if !defined(__MTK_TARGET__)
#include <windows.h>
/* system includes */
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_editor_data_item.h"

/* global includes */
#include "l1audio.h"

/* local includes */
#include "med_global.h"
#include "med_status.h"
#include "med_main.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_context.h"
#include "med_utility.h"
#include "med_main.h"
#include "vid_main.h"
#include "vid_if.h"
#include "lcd_if.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

#include "w32_av_types.h"
#include "w32_av_lib.h"

#if defined(__MED_VID_DEC_MOD__)
void vid_open_file_callback(w32_Video_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    { 
        case w32_VideoEvent_OK:
            break;
        case w32_VideoEvent_PlaybackFinished:
            if (VID_IN_STATE(VID_PLAY))
            {           
                w32_Video_Stop();
                vid_send_play_finish_ind(MED_RES_OK);
                VID_ENTER_STATE(VID_FILE_READY);
            }
            break;
        case w32_VideoEvent_Error:
            ASSERT(0);            
            break;
        case w32_VideoEvent_FrameIsReady:
            break;
    }
}


void vid_stop_req_hdlr_modis(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VID_IN_STATE(VID_PLAY))
    {
        w32_Video_Stop();
        vid_set_event(VID_EVT_STOP);
        VID_ENTER_STATE(VID_FILE_READY);
        return;
    }
    else
    {
        vid_set_result(MED_RES_VIDEO_ALREADY_STOPPED,__LINE__);
        vid_set_event(VID_EVT_STOP);
        return;
    }
}


void vid_open_req_hdlr_modis(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_open_req_struct *req_p;
    kal_int32 result;
    int width, height;
    kal_int64 total_time_duration;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    req_p = (media_vid_open_req_struct*) ilm_ptr->local_para_ptr;

    vid_context_p->src_mod = ilm_ptr->src_mod_id;
    vid_context_p->seq_num = req_p->seq_num;
    vid_context_p->media_mode = req_p->media_mode;
    vid_context_p->media_type = req_p->media_type;
    vid_context_p->current_time = 0;
    vid_context_p->blocking = req_p->blocking;

    vid_context_p->is_enable_aud_only = req_p->enable_aud_only;
    vid_context_p->force_seek = KAL_FALSE;


    if (VID_IN_STATE(VID_IDLE))
    {
    #ifdef __VENUS_3D_UI_ENGINE__
        vid_set_result(MED_RES_OPEN_FILE_FAIL,__LINE__);            
        vid_set_event(VID_EVT_OPEN);
        return;
    #endif /* __VENUS_3D_UI_ENGINE__ */
    
        if (vid_context_p->media_mode == MED_MODE_FILE)
        {
            kal_mem_cpy(vid_context_p->current_file_name, (void*)req_p->data, MAX_FILE_NAME_LEN * 2);
            w32_AV_Initialize();

            if (w32_Video_OpenFile(vid_context_p->current_file_name,vid_open_file_callback) == KAL_TRUE)
            {
                w32_Video_GetResolution((int*) &width, (int*)&height);
                vid_context_p->image_width = width;
                vid_context_p->image_height = height;

                w32_Video_GetDuration(&total_time_duration);
                vid_context_p->total_time = total_time_duration/10000;                
                VID_ENTER_STATE(VID_FILE_READY);

                if (!vid_context_p->blocking)
                {
                    vid_send_file_ready_ind(MED_RES_OK);
                }

                vid_set_result(MED_RES_OK,__LINE__);
                vid_set_event(VID_EVT_OPEN);
                return;
            }
            else
            {
                w32_AV_Uninitialize();
                vid_set_result(MED_RES_OPEN_FILE_FAIL,__LINE__);
                vid_set_event(VID_EVT_OPEN);
                return;
            }
        }
        else 
        {
            vid_set_result(MED_RES_OPEN_FILE_FAIL,__LINE__);            
            vid_set_event(VID_EVT_OPEN);
            return;
        }
        
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
        vid_set_event(VID_EVT_OPEN);
        return;
    }
}


void vid_close_req_hdlr_modis(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_close_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_vid_close_req_struct*) ilm_ptr->local_para_ptr;
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

        if ((VID_IN_STATE(VID_FILE_READY) || VID_IN_STATE(VID_OPEN_FILE)))
        {
            w32_Video_CloseFile();            
            w32_AV_Uninitialize();
            VID_ENTER_STATE(VID_IDLE);            
        }


    vid_set_event(VID_EVT_CLOSE);
}


void vid_play_req_hdlr_modis(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_play_req_struct *req_p;
    kal_int32 result = MED_RES_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_vid_play_req_struct*) ilm_ptr->local_para_ptr;

    if (VID_IN_STATE(VID_FILE_READY))
    {
        vid_context_p->seq_num = req_p->seq_num;
        vid_context_p->file_buffer_address = (kal_uint32)req_p->image_buffer_p;
        vid_context_p->display_width = req_p->display_width;
        vid_context_p->display_height = req_p->display_height;


        if(KAL_TRUE==w32_Video_Play((char*)vid_context_p->file_buffer_address,vid_context_p->display_width,vid_context_p->display_height ,w32_ColorDepth_RGB565,KAL_TRUE,1.0))
        {
            vid_set_result(MED_RES_OK, __LINE__);
            VID_ENTER_STATE(VID_PLAY);
        }
        else
        {
            vid_set_result(MED_RES_FAIL, __LINE__);
        }
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
    }

    vid_set_event(VID_EVT_PLAY);
}


void vid_seek_req_hdlr_modis(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_seek_req_struct *req_p;
    kal_int16 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_seek_req_struct*) ilm_ptr->local_para_ptr;

    if (VID_IN_STATE(VID_FILE_READY))
    {
        vid_context_p->blocking = req_p->blocking;            
        vid_context_p->seq_num = req_p->seq_num;
        vid_context_p->current_time = req_p->time;
        vid_context_p->get_frame = req_p->get_frame;
        vid_context_p->file_buffer_address = (kal_uint32) req_p->image_buffer_p;

        if (req_p->display_width == 0 && req_p->display_height == 0)
        {
            vid_context_p->display_width = LCD_WIDTH;
            vid_context_p->display_height = LCD_HEIGHT;
        }
        else
        {
            vid_context_p->display_width = req_p->display_width;
            vid_context_p->display_height = req_p->display_height;
        }
        VID_ENTER_STATE(VID_SEEK);

        if (KAL_FALSE != w32_Video_Seek(vid_context_p->current_time*10000))
        {
            if (vid_context_p->get_frame && vid_context_p->file_buffer_address)
            {
                w32_Video_PreviewFrame(vid_context_p->file_buffer_address, 
                                       vid_context_p->display_width,
                                       vid_context_p->display_height,
                                       w32_ColorDepth_RGB565,
                                       vid_context_p->current_time*10000);
            }
            
            result = MED_RES_OK;
        }
        else
        {
            result = MED_RES_FAIL;
        }

        VID_ENTER_STATE(VID_FILE_READY);


        if (vid_context_p->blocking)
        {
            vid_set_result(result, __LINE__);
        }
        else
        {
            vid_send_seek_done_ind(result);
        }

        vid_set_event(VID_EVT_SEEK);
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
        vid_set_event(VID_EVT_SEEK);
    }    
}


void vid_get_frame_req_hdlr_modis(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_frame_req_struct *req_p;
    kal_int16 result;
    w32_ColorDepth color;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    vid_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_vid_get_frame_req_struct*) ilm_ptr->local_para_ptr;

    if (VID_IN_STATE(VID_FILE_READY))
    {
        vid_context_p->file_buffer_address = (kal_uint32) req_p->image_buffer_p;

        if (req_p->display_width == 0 && req_p->display_height == 0)
        {
            vid_context_p->display_width = LCD_WIDTH;
            vid_context_p->display_height = LCD_HEIGHT;
        }
        else
        {
            vid_context_p->display_width = req_p->display_width;
            vid_context_p->display_height = req_p->display_height;
        }

        switch(req_p->image_data_format)
        {        
            case IMG_COLOR_FMT_RGB565:    
                color = w32_ColorDepth_RGB565;
                break;
            case IMG_COLOR_FMT_RGB888:
                color = w32_ColorDepth_RGB24;
                break;    
            default:
                color = w32_ColorDepth_RGB565;
                break;
        }

        if (vid_context_p->file_buffer_address)
        {
            w32_Video_PreviewFrame(vid_context_p->file_buffer_address,
                                   vid_context_p->display_width,
                                   vid_context_p->display_height,
                                   color,
                                   vid_context_p->current_time*10000);
        }

        result = MED_RES_OK;

        vid_set_result(MED_RES_OK, __LINE__);

        vid_set_event(VID_EVT_GET_FRAME);
    }
    else
    {
        vid_set_result(MED_RES_BUSY, __LINE__);
        vid_set_event(VID_EVT_GET_FRAME);
    }
}


void vid_update_layer_pause_req_hdlr_modis(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (VID_IN_STATE(VID_PLAY))
    {
        w32_Video_Stop();
    }
    
    vid_set_event(VID_EVT_BLOCK);
}


void vid_update_layer_resume_req_hdlr_modis(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_play_req_struct *req_p; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_vid_play_req_struct*) ilm_ptr->local_para_ptr;

    if (!VID_IN_STATE(VID_PLAY))
    {
        vid_set_result(MED_RES_OK, __LINE__);
        vid_set_event(VID_EVT_BLOCK);
    }
    
    vid_context_p->seq_num = req_p->seq_num;
    vid_context_p->file_buffer_address = (kal_uint32)req_p->image_buffer_p;
    vid_context_p->display_width = req_p->display_width;
    vid_context_p->display_height = req_p->display_height;


    if(KAL_TRUE==w32_Video_Play((char*)vid_context_p->file_buffer_address,vid_context_p->display_width,vid_context_p->display_height ,w32_ColorDepth_RGB565,KAL_TRUE,1.0))
    {
        vid_set_result(MED_RES_OK, __LINE__);
    }
    else
    {
        vid_set_result(MED_RES_FAIL, __LINE__);
    }        
    
    vid_set_event(VID_EVT_BLOCK);
}

    
void vid_get_param_req_hdlr_modis(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_vid_get_param_req_struct *req_p;    
    med_result_enum result = MED_RES_FAIL;    
    media_error_t ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    req_p = (media_vid_get_param_req_struct*) ilm_ptr->local_para_ptr;

    switch (req_p->param_id)
{
        case VID_PARAM_CONTENT_DESC:
{
            mpl_player_get_meta_t *meta = (mpl_player_get_meta_t *)req_p->value;;
    
            if (VID_IN_STATE(VID_FILE_READY))
{
                memset(meta->title_desc_ptr, 0, meta->title_desc_len);
                memset(meta->artist_desc_ptr, 0, meta->artist_desc_len);            
                memset(meta->album_desc_ptr, 0, meta->album_desc_len);            
                memset(meta->author_desc_ptr, 0, meta->author_desc_len);            
                memset(meta->copyright_desc_ptr, 0, meta->copyright_desc_len);            
                memset(meta->date_desc_ptr, 0, meta->date_desc_len);

                result = MED_RES_OK;
}
            break; 
}
        default:
            break;
}

    vid_set_result_and_event(result, VID_EVT_GET_INFO);    
}

#endif /* defined(__MED_VID_DEC_MOD__) */
#endif /* !defined(__MTK_TARGET__) */

#endif /* MED_NOT_PRESENT */
