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
 *    va2_display_api_adapter.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    Adapter of Video Architecture V1 display API.
 *    Removed from mcu\media\video\common\src\video_comm_idp_if.c
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 ****************************************************************************/
#include "drv_comm.h"
#if defined (DRV_MP4_DEC_SUPPORT) || defined (DRV_H264_DEC_SUPPORT)

#if defined(__VIDEO_ARCHI_V2__)

#include "video_render_component_v2.h"
#include "video_types_v2.h"
#include "video_player_if_v2.h"
#include "med_status.h"
#include "va2_comp_video_renderer.h"
#include "img_common_enum.h"
#include "kal_public_api.h"
#include "lcd_if.h"

// TODO: Define this module and its functions...adaptor?
/*****************************************************************************
 *  Video Decode IDP IF Adapter -- START
 *  
 *  client: MED
 *  target: video_comm_idp_if
 *  adaptee: va2_comp_video_renderer
 *****************************************************************************/
#define VIDEO_DEC_IDP_IF__SET_RENDERER_HANDLE

typedef struct
{
    VIDEO_RENDER_MODE_T eRenderMode;
    kal_uint32          u4LCDID;
    kal_uint8           *pu1OutputBuff;
    kal_uint8           *pu1DisplyOutputBuff;
    kal_uint8           *pu1MemLCDBuff;
    kal_uint32          u4Width;
    kal_uint32          u4Height;
    kal_uint32          u4RealWidth;
    kal_uint32          u4RealHeitgh;
    kal_uint32          u4RealSize;
    kal_uint32          u4BuffSize;
} VIDEO_IDP_IF_T;

static VIDEO_IDP_IF_T _rVideoIDPInfo;
static VIDEO_COMPONENT_TYPE_T *_video_renderer_adapter_handle = NULL;

extern VIDEO_RENDER_TEST_STATE_T _rVideoRenderTestState;
#if !defined(VIDEO_DEC_IDP_IF__SET_RENDERER_HANDLE)
extern VIDEO_PLAY_STRUCT_T rVideoPlay;
#endif  // #if !defined(VIDEO_DEC_IDP_IF__SET_RENDERER_HANDLE)

MEDIA_STATUS_CODE video_dec_set_video_renderer_handle(VIDEO_COMPONENT_TYPE_T *handle)
{
    if (NULL == handle)
    {
        ASSERT(0);
        return VIDEO_ERROR; // TODO: check what is this...
    }

    _video_renderer_adapter_handle = handle;

    {
        VIDEO_STATE_TYPE_T state;

        if (VIDEO_ERROR_NONE != 
            _video_renderer_adapter_handle->pfnGetParameter(VIDEO_CONFIG_RENDERER_STATUS, 
                                                            (void*) &state))
        {
            ASSERT(0);
            return VIDEO_ERROR; // TODO: check what is this...
        }
    }
    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE video_dec_config_render(VIDEO_RENDER_MODE_T eMode, void* pParam)
{
    MP4DEC_IMGPATH_STRUCT *prHWDataInput; // TODO: Note this! defined in video_player_if_v2.h
    MP4DEC_MEMMODE_STRUCT *prSWDataInput; // TODO: Note this! defined in video_player_if_v2.h
    lcd_frame_update_struct *prLCDParam;

#if !defined(VIDEO_DEC_IDP_IF__SET_RENDERER_HANDLE)
    if (NULL == _video_renderer_adapter_handle)
    {
        _video_renderer_adapter_handle = rVideoPlay.prVideoRenderHandle;
    }
#endif  // #if !defined(VIDEO_DEC_IDP_IF__SET_RENDERER_HANDLE)

    //sw mode
    if(eMode == VIDEO_RENDER_MODE_SW)
    {
#if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
        prSWDataInput = (MP4DEC_MEMMODE_STRUCT*) pParam;

        // [6236_video_renderer] config video renderer
        {
            VA2_FRAME_SIZE_T display_size;
            va2_video_renderer_dst_fb_t display_fb;
            va2_video_renderer_post_process_config_t ipp;
            VA2_VIDEO_RENDERER_COLOR_FORMAT_T color_fmt;
            va2_video_renderer_rotate_flip_t rot;
            kal_bool trigger_lcd;
            VA2_VIDEO_RENDERER_RENDER_MODE_T render_mode;
            kal_bool bypass;

            bypass = KAL_FALSE;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_BYPASS, 
                                                                (void*) &bypass))
            {
                ASSERT(0);
            }

            display_size.u4_width = prSWDataInput->disp_width;
            display_size.u4_height = prSWDataInput->disp_height;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_DST_FB_SIZE, 
                                                                (void*) &display_size))
            {
                ASSERT(0);
            }
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_CONFIG_RENDERER_RESIZE_DST_SIZE, 
                                                                (void*) &display_size))
            {
                ASSERT(0);
            }

            display_fb.u2_index = 0;
            display_fb.r_fb_addr.u4_fb_addr_plane0 = prSWDataInput->lcd_buf_addr;
            display_fb.r_fb_addr.u4_fb_addr_plane1 = 0;
            display_fb.r_fb_addr.u4_fb_addr_plane2 = 0;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_DST_FB_ADDR, 
                                                                (void*) &display_fb))
            {
                ASSERT(0);
            }
            display_fb.u2_index = 1;
            display_fb.r_fb_addr.u4_fb_addr_plane0 = prSWDataInput->lcd_buf_addr_2;
            if (0 != display_fb.r_fb_addr.u4_fb_addr_plane0)
            {
                if (VIDEO_ERROR_NONE != 
                    _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_DST_FB_ADDR, 
                                                                    (void*) &display_fb))
                {
                    ASSERT(0);
                }
            }

            ipp.b_brightness = KAL_TRUE;
            ipp.b_contrast = KAL_TRUE;
            ipp.u1_brightness = prSWDataInput->brightness_level;
            ipp.u1_contrast = prSWDataInput->contrast_level;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_CONFIG_RENDERER_POST_PROCESS, 
                                                                (void*) &ipp))
            {
                ASSERT(0);
            }

            color_fmt = VIDEO_RENDERER_COLOR_RGB565;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_DST_COLOR_FORMAT, 
                                                                (void*) &color_fmt))
            {
                ASSERT(0);
            }

            switch (prSWDataInput->rotate_angle)
            {
            case IMG_ROT_ANGLE_0: 
                rot.u2_cw_rotate_angle = 0;
                break;
            case IMG_ROT_ANGLE_90: 
                rot.u2_cw_rotate_angle = 90;
                break;
            case IMG_ROT_ANGLE_180: 
                rot.u2_cw_rotate_angle = 180;
                break;
            case IMG_ROT_ANGLE_270: 
                rot.u2_cw_rotate_angle = 270;
                break;
            }
            rot.b_flip = KAL_FALSE;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_CONFIG_RENDERER_ROTATE_FLIP, 
                                                                (void*) &rot))
            {
                ASSERT(0);
            }

            trigger_lcd = KAL_FALSE;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_TRIGGER_DISPLAY, 
                                                                (void*) &trigger_lcd))
            {
                ASSERT(0);
            }

            render_mode = VIDEO_RENDERER_RENDER_MODE_STRETCH_TO_WINDOW;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_SEMI_AUTO_RENDER_MODE, 
                                                                (void*) &render_mode))
            {
                ASSERT(0);
            }

            color_fmt = VIDEO_RENDERER_COLOR_YUV420;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_CONFIG_RENDERER_SRC_COLOR_FORMAT, 
                                                                (void*) &color_fmt))
            {
                ASSERT(0);
            }
        }

        // TODO: what is _rVideoIDPInfo for?
        {
            VA2_FRAME_SIZE_T video_src_size;
            VA2_CLIP_WINDOW_T video_src_clip;

            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnGetParameter(VIDEO_CONFIG_RENDERER_SRC_SIZE, 
                                                                (void*) &video_src_size))
            {
                ASSERT(0);
            }
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnGetParameter(VIDEO_CONFIG_RENDERER_SRC_CLIP, 
                                                                (void*) &video_src_clip))
            {
                ASSERT(0);
            }

            _rVideoIDPInfo.eRenderMode = VIDEO_RENDER_MODE_SW;
            _rVideoIDPInfo.u4Width = video_src_size.u4_width;
            _rVideoIDPInfo.u4Height = video_src_size.u4_height;
            if (KAL_TRUE == video_src_clip.b_clip_enable)
            {
                _rVideoIDPInfo.u4RealWidth = video_src_clip.u4_clip_right - video_src_clip.u4_clip_left + 1;
                _rVideoIDPInfo.u4RealHeitgh = video_src_clip.u4_clip_bottom - video_src_clip.u4_clip_top + 1;
            }
            else
            {
                _rVideoIDPInfo.u4RealWidth = _rVideoIDPInfo.u4Width;
                _rVideoIDPInfo.u4RealHeitgh = _rVideoIDPInfo.u4Height;
            }
            _rVideoIDPInfo.u4BuffSize = _rVideoIDPInfo.u4Width * _rVideoIDPInfo.u4Height * 2; // TODO: why BPP always 2?
            _rVideoIDPInfo.u4RealSize = _rVideoIDPInfo.u4RealWidth * _rVideoIDPInfo.u4RealHeitgh * 2; // TODO: why BPP always 2?
        }
        
#else   // #if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
        prSWDataInput = (MP4DEC_MEMMODE_STRUCT*)pParam;
        //test code
        _rVideoIDPInfo.eRenderMode = VIDEO_RENDER_MODE_SW;
        _rVideoIDPInfo.u4Width = _rVideoRenderTestState.rConfigData.u4VideoWidth;
        _rVideoIDPInfo.u4Height = _rVideoRenderTestState.rConfigData.u4VideoHeight;
        _rVideoIDPInfo.u4RealWidth = _rVideoRenderTestState.rConfigData.u4VideoWidth;
        _rVideoIDPInfo.u4RealHeitgh = _rVideoRenderTestState.rConfigData.u4VideoHeight;
        _rVideoIDPInfo.u4BuffSize = _rVideoIDPInfo.u4Width * _rVideoIDPInfo.u4Height * 2;
        _rVideoIDPInfo.u4RealSize = _rVideoIDPInfo.u4Width * _rVideoIDPInfo.u4Height * 2;

        _rVideoIDPInfo.pu1MemLCDBuff = (kal_uint8*)prSWDataInput->lcd_buf_addr;
        _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDER_MODE, (void*)&_rVideoIDPInfo.eRenderMode);
#endif  // #if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    }
    else if(eMode == VIDEO_RENDER_MODE_HW)
    {
#if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
        prHWDataInput = (MP4DEC_IMGPATH_STRUCT*)pParam;
        prLCDParam = prHWDataInput->lcd_data;

        // [6236_video_renderer] config video renderer
        {
            VA2_FRAME_SIZE_T display_size;
            va2_video_renderer_dst_fb_t display_fb;
            va2_video_renderer_post_process_config_t ipp;
            VA2_VIDEO_RENDERER_COLOR_FORMAT_T color_fmt;
            va2_video_renderer_rotate_flip_t rot;
            kal_bool trigger_lcd;
            VA2_VIDEO_RENDERER_RENDER_MODE_T render_mode;
            va2_video_renderer_display_surface_t lcd_cfg;
            kal_bool bypass;

            bypass = KAL_FALSE;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_BYPASS, 
                                                                (void*) &bypass))
            {
                ASSERT(0);
            }

            display_size.u4_width = prHWDataInput->disp_width;
            display_size.u4_height = prHWDataInput->disp_height;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_DST_FB_SIZE, 
                                                                (void*) &display_size))
            {
                ASSERT(0);
            }
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_CONFIG_RENDERER_RESIZE_DST_SIZE, 
                                                                (void*) &display_size))
            {
                ASSERT(0);
            }

            display_fb.u2_index = 0;
            display_fb.r_fb_addr.u4_fb_addr_plane0 = prHWDataInput->lcd_buf_addr;
            display_fb.r_fb_addr.u4_fb_addr_plane1 = 0;
            display_fb.r_fb_addr.u4_fb_addr_plane2 = 0;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_DST_FB_ADDR, 
                                                                (void*) &display_fb))
            {
                ASSERT(0);
            }
            display_fb.u2_index = 1;
            display_fb.r_fb_addr.u4_fb_addr_plane0 = prHWDataInput->lcd_buf_addr_2;
            if (0 != display_fb.r_fb_addr.u4_fb_addr_plane0)
            {
                if (VIDEO_ERROR_NONE != 
                    _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_DST_FB_ADDR, 
                                                                    (void*) &display_fb))
                {
                    ASSERT(0);
                }
            }

            ipp.b_brightness = KAL_TRUE;
            ipp.b_contrast = KAL_TRUE;
            ipp.u1_brightness = prHWDataInput->brightness_level;
            ipp.u1_contrast = prHWDataInput->contrast_level;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_CONFIG_RENDERER_POST_PROCESS, 
                                                                (void*) &ipp))
            {
                ASSERT(0);
            }

            color_fmt = VIDEO_RENDERER_COLOR_RGB565;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_DST_COLOR_FORMAT, 
                                                                (void*) &color_fmt))
            {
                ASSERT(0);
            }

            switch (prHWDataInput->rotate_angle)
            {
            case IMG_ROT_ANGLE_0: 
                rot.u2_cw_rotate_angle = 0;
                break;
            case IMG_ROT_ANGLE_90: 
                rot.u2_cw_rotate_angle = 90;
                break;
            case IMG_ROT_ANGLE_180: 
                rot.u2_cw_rotate_angle = 180;
                break;
            case IMG_ROT_ANGLE_270: 
                rot.u2_cw_rotate_angle = 270;
                break;
            }
            rot.b_flip = KAL_FALSE;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_CONFIG_RENDERER_ROTATE_FLIP, 
                                                                (void*) &rot))
            {
                ASSERT(0);
            }

            trigger_lcd = KAL_TRUE;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_TRIGGER_DISPLAY, 
                                                                (void*) &trigger_lcd))
            {
                ASSERT(0);
            }

            render_mode = VIDEO_RENDERER_RENDER_MODE_STRETCH_TO_WINDOW;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_SEMI_AUTO_RENDER_MODE, 
                                                                (void*) &render_mode))
            {
                ASSERT(0);
            }

            color_fmt = VIDEO_RENDERER_COLOR_YUV420;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_CONFIG_RENDERER_SRC_COLOR_FORMAT, 
                                                                (void*) &color_fmt))
            {
                ASSERT(0);
            }

            kal_mem_cpy(&lcd_cfg.r_mtk_lcd_config, prLCDParam, sizeof(lcd_frame_update_struct));
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_DISPLAY_SURFACE, 
                                                                (void*) &lcd_cfg))
            {
                ASSERT(0);
            }
        }

        // TODO: what is _rVideoIDPInfo for?
        {
            VA2_FRAME_SIZE_T video_src_size;
            VA2_CLIP_WINDOW_T video_src_clip;

            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnGetParameter(VIDEO_CONFIG_RENDERER_SRC_SIZE, 
                                                                (void*) &video_src_size))
            {
                ASSERT(0);
            }
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnGetParameter(VIDEO_CONFIG_RENDERER_SRC_CLIP, 
                                                                (void*) &video_src_clip))
            {
                ASSERT(0);
            }

            _rVideoIDPInfo.eRenderMode = VIDEO_RENDER_MODE_HW;
            _rVideoIDPInfo.u4Width = video_src_size.u4_width;
            _rVideoIDPInfo.u4Height = video_src_size.u4_height;
            if (KAL_TRUE == video_src_clip.b_clip_enable)
            {
                _rVideoIDPInfo.u4RealWidth = video_src_clip.u4_clip_right - video_src_clip.u4_clip_left + 1;
                _rVideoIDPInfo.u4RealHeitgh = video_src_clip.u4_clip_bottom - video_src_clip.u4_clip_top + 1;
            }
            else
            {
                _rVideoIDPInfo.u4RealWidth = _rVideoIDPInfo.u4Width;
                _rVideoIDPInfo.u4RealHeitgh = _rVideoIDPInfo.u4Height;
            }
            _rVideoIDPInfo.u4BuffSize = _rVideoIDPInfo.u4Width * _rVideoIDPInfo.u4Height * 2; // TODO: why BPP always 2?
            _rVideoIDPInfo.u4RealSize = _rVideoIDPInfo.u4RealWidth * _rVideoIDPInfo.u4RealHeitgh * 2; // TODO: why BPP always 2?
        }

#else   // #if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
        prHWDataInput = (MP4DEC_IMGPATH_STRUCT*)pParam;
        prLCDParam = prHWDataInput->lcd_data;
        //test code
        _rVideoIDPInfo.eRenderMode = VIDEO_RENDER_MODE_HW;        
        _rVideoIDPInfo.u4Width = _rVideoRenderTestState.rConfigData.u4VideoWidth;
        _rVideoIDPInfo.u4Height = _rVideoRenderTestState.rConfigData.u4VideoHeight;
        _rVideoIDPInfo.u4RealWidth = _rVideoRenderTestState.rConfigData.u4VideoWidth;
        _rVideoIDPInfo.u4RealHeitgh = _rVideoRenderTestState.rConfigData.u4VideoHeight;
        _rVideoIDPInfo.u4BuffSize = _rVideoIDPInfo.u4Width * _rVideoIDPInfo.u4Height * 2;
        _rVideoIDPInfo.u4RealSize = _rVideoIDPInfo.u4Width * _rVideoIDPInfo.u4Height * 2;
        _rVideoIDPInfo.u4LCDID = prLCDParam->lcd_id;
        _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDER_MODE, (void*)&_rVideoIDPInfo.eRenderMode);
        
        lcd_fb_update(prLCDParam);
#endif  // #if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    }    
    else if(eMode == VIDEO_RENDER_MODE_NONE)
    {
#if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
        VIDEO_STATE_TYPE_T state;

        _rVideoIDPInfo.eRenderMode = VIDEO_RENDER_MODE_NONE;

        // If already in STOP state, do nothing...
        if (VIDEO_ERROR_NONE != 
            _video_renderer_adapter_handle->pfnGetParameter(VIDEO_CONFIG_RENDERER_STATUS, 
                                                           (void*) &state))
        {
            ASSERT(0);
        }

        if ((VIDEO_STATE_STOP == state) || 
            (VIDEO_STATE_IDLE == state))
        {
            kal_bool bypass;

            bypass = KAL_TRUE;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_BYPASS, 
                                                                (void*) &bypass))
            {
                ASSERT(0);
            }

            return MEDIA_STATUS_OK;
        }
        else
        {
            ASSERT(0);
        }
#else   // #if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
        if(_rVideoIDPInfo.eRenderMode == VIDEO_RENDER_MODE_HW)
        {
            // if from HW mode
            lcd_stop_hw_update(_rVideoIDPInfo.u4LCDID);
        }
        _rVideoIDPInfo.eRenderMode = VIDEO_RENDER_MODE_NONE;
        _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDER_MODE, (void*)&_rVideoIDPInfo.eRenderMode);
#endif  // #if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    }

    return MEDIA_STATUS_OK;
}

/**
 *  copy the the target RGB buffer to the specified frame buffer when in SW mode...
 *  Then switch renderer 
 */
void video_dec_render_frame_to_memory(void)
{
    // TODO: what is this for?
    // get buffer from render
    //_rVideoIDPInfo.pu1OutputBuff = (kal_uint8*) video_dec_get_display_addr();
    
    //vcodec_start_y2r((kal_uint32)_rVideoIDPInfo.pu1OutputBuff, (kal_uint32)_rVideoIDPInfo.pu1MemLCDBuff, KAL_FALSE, _rVideoIDPInfo.u4Width, _rVideoIDPInfo.u4Height);
    //kal_mem_cpy(_rVideoIDPInfo.pu1MemLCDBuff, _rVideoIDPInfo.pu1OutputBuff, _rVideoIDPInfo.u4RealSize);

#if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    {
        
        
#if !defined(VIDEO_DEC_IDP_IF__SET_RENDERER_HANDLE)
        if (NULL == _video_renderer_adapter_handle)
        {
            _video_renderer_adapter_handle = rVideoPlay.prVideoRenderHandle;
        }
#endif  // #if !defined(VIDEO_DEC_IDP_IF__SET_RENDERER_HANDLE)

        //  0. check if in STOP or IDLE state...
        {
            VIDEO_STATE_TYPE_T state;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnGetParameter(VIDEO_CONFIG_RENDERER_STATUS, 
                                                                (void*) &state))
            {
                ASSERT(0);
                return;
            }
            if ((VIDEO_STATE_IDLE != state) && (VIDEO_STATE_STOP != state))
            {
                ASSERT(0);
                return;
            }
        }

        //  1. set VIDEO_PARAM_RENDERER_KEEP_CURR_PTR to KAL_FALSE
        {
            kal_bool keep = KAL_FALSE;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_KEEP_CURR_PTR, 
                                                                (void*) &keep))
            {
                ASSERT(0);
                return;
            }
        }
        
        //  2. command video renderer to render
        {
            kal_uint32 dspl_fb_addr;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnGetParameter(VIDEO_PARAM_RENDERER_RENDER_DISPLAY_BUFFER, 
                                                               (void*) &dspl_fb_addr))
            {
                ASSERT(0);
                return;
            }
        }
    }
#endif  // #if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    return;
}

/**
 *  video_dec_render_prev_frame_to_memory
 *  @todo What is prev frame? What's the diff from video_dec_render_frame_to_memory()?
 *  @todo What should be done in this function?
 *  @todo What is the calling sequence...???????????
 */
void video_dec_render_prev_frame_to_memory(void)
{
    // TODO: what is this for?
    // get buffer from render
    //_rVideoIDPInfo.pu1OutputBuff = (kal_uint8*) video_dec_get_display_addr();

    //vcodec_start_y2r((kal_uint32)_rVideoIDPInfo.pu1OutputBuff, (kal_uint32)_rVideoIDPInfo.pu1MemLCDBuff, KAL_FALSE, _rVideoIDPInfo.u4Width, _rVideoIDPInfo.u4Height);
    //kal_mem_cpy(_rVideoIDPInfo.pu1MemLCDBuff, _rVideoIDPInfo.pu1OutputBuff, _rVideoIDPInfo.u4RealSize);

#if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    {
#if !defined(VIDEO_DEC_IDP_IF__SET_RENDERER_HANDLE)
        if (NULL == _video_renderer_adapter_handle)
        {
            _video_renderer_adapter_handle = rVideoPlay.prVideoRenderHandle;
        }
#endif  // #if !defined(VIDEO_DEC_IDP_IF__SET_RENDERER_HANDLE)

        //  0. check if in STOP or IDLE state...
        {
            VIDEO_STATE_TYPE_T state;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnGetParameter(VIDEO_CONFIG_RENDERER_STATUS, 
                                                                (void*) &state))
            {
                ASSERT(0);
                return;
            }
            if ((VIDEO_STATE_IDLE != state) && (VIDEO_STATE_STOP != state))
            {
                ASSERT(0);
                return;
            }
        }

        //  1. set VIDEO_PARAM_RENDERER_KEEP_CURR_PTR to KAL_TRUE
        {
            kal_bool keep = KAL_TRUE;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnSetParameter(VIDEO_PARAM_RENDERER_KEEP_CURR_PTR, 
                                                                (void*) &keep))
            {
                ASSERT(0);
                return;
            }
        }
        
        //  2. command video renderer to render
        {
            kal_uint32 dspl_fb_addr;
            if (VIDEO_ERROR_NONE != 
                _video_renderer_adapter_handle->pfnGetParameter(VIDEO_PARAM_RENDERER_RENDER_DISPLAY_BUFFER, 
                                                               (void*) &dspl_fb_addr))
            {
                ASSERT(0);
                return;
            }
        }
    }
#endif  // #if (KAL_TRUE == VA2_COMP_VIDEO_RENDERER_SUPPORTED)
    return;
}

#endif  // #if defined(__VIDEO_ARCHI_V2__)

#endif  // #if defined (DRV_MP4_DEC_SUPPORT) || defined (DRV_H264_DEC_SUPPORT)

