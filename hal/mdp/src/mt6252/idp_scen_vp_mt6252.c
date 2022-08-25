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
 *    idp_scen_vp_mt6252.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    VIDEO DEOCDE(YUV420) -> CRZ -> ROTDMA -> MEM(YUV422PS) -> LCD
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 03 27 2014 chrono.wu
 * removed!
 * .
 *
 * 03 25 2014 chrono.wu
 * removed!
 * .
 *
 * 03 24 2014 chrono.wu
 * removed!
 * .
 *
 * 01 21 2014 chrono.wu
 * removed!
 * 	.
 *
 * 12 26 2013 chrono.wu
 * removed!
 * .
 *
 * 12 12 2013 chrono.wu
 * removed!
 * .
 *
 * 12 12 2013 chrono.wu
 * removed!
 * .
 *
 * 02 22 2013 peter.wang
 * removed!
 * .
 *
 * 01 21 2013 peter.wang
 * removed!
 * .
 *
 * 01 11 2013 peter.wang
 * removed!
 * .
 *
 * 12 13 2012 peter.wang
 * removed!
 * .
 * 
 * 09 24 2012 peter.wang
 * removed!
 * .
 * 
 * 09 11 2012 peter.wang
 * removed!
 * .
 *
 * 06 18 2012 peter.wang
 * removed!
 * .
 *
 * 05 08 2012 peter.wang
 * removed!
 * .
 *
 * 04 25 2012 peter.wang
 * removed!
 * .
 *
 * 04 16 2012 peter.wang
 * removed!
 * .
 *
 * 03 16 2012 peter.wang
 * removed!
 * .
 *
 * 03 05 2012 peter.wang
 * removed!
 * .
 *
 * 02 15 2012 peter.wang
 * removed!
 * .
 *
 * 12 28 2011 peter.wang
 * removed!
 * .
 *
 * 12 27 2011 peter.wang
 * removed!
 * .
 *
 * 11 29 2011 peter.wang
 * removed!
 * .
 *
 * 11 29 2011 peter.wang
 * removed!
 * .
 *
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/****************************************************************************
 * macros and options
 ****************************************************************************/
#define THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL

/****************************************************************************
 * include directives
 ****************************************************************************/
#include "drv_comm.h"
#include <idp_define.h>

#if defined(DRV_IDP_6252_SERIES)

#include <idp_core.h>

#include <idp_video_decode.h>
#include <mt6252/idp_engines.h>

#if defined(IDP_HISR_SUPPORT)
#include <mt6252/idp_hisr.h>
#endif
#include <mt6252/idp_scen_common_mt6252.h>

//include wfc check busy api
#include <wfc/inc/wfc_mm_api.h>

#define IDP_VIDEO_DECODE_TRACE
#define IDP_KMV_VIDEO_SUPPORT

IDP_COMMON_API_DECLARATION(video_decode)
/****************************************************************************
 * local variables
 ****************************************************************************/
static struct
{
    kal_uint16      source_width; /**< video frame width w/ padding. The YUV frame buffer shall align to this size. */
    kal_uint16      source_height; /**< video frame height w/ padding. The YUV frame buffer shall align to this size. */

    kal_bool        src_clip; /**< KAL_TRUE to enable source clipping, clipping after resizing */
    kal_uint16      src_clip_left; /**< clip top before resize, restriction: bottom-top+1 must be even */
    kal_uint16      src_clip_right; /**< clip bottom before resize, restriction: bottom-top+1 must be even */
    kal_uint16      src_clip_top; /**< clip left before resize, restriction: bottom-top+1 must be even */
    kal_uint16      src_clip_bottom; /**< clip right before resize, restriction: bottom-top+1 must be even */

    kal_uint16      video_frame_real_width; /**< video frame real width w/o padding, shall be in the range [source_width-15, source_width] */
    kal_uint16      video_frame_real_height; /**< video frame real height w/o padding, shall be in the range [source_height-15, source_height] */

    kal_uint16      target_width; /**< resize output width, resized from video_frame_real_width */
    kal_uint16      target_height; /**< resize output height, resized from video_frame_real_height */

    kal_bool        target_clip; /**< KAL_TRUE to enable destination (target) clipping, clipping after resizing */
    kal_uint16      target_clip_top; /**< clip top after resize, restriction: bottom-top+1 must be even */
    kal_uint16      target_clip_bottom; /**< clip bottom after resize, restriction: bottom-top+1 must be even */
    kal_uint16      target_clip_left; /**< clip left after resize, restriction: bottom-top+1 must be even */
    kal_uint16      target_clip_right; /**< clip right after resize, restriction: bottom-top+1 must be even */

    kal_bool        pitch; /**< KAL_TRUE to enable pitch function. */
    kal_uint16      pitch_width; /** pitch width in pixel, must be even, this is a MT6252 HW limitation. */

    kal_uint32      out_frame_buffer_addr_1; /**< YUV422PS frame buffer 1 for display */

    void            (*frame_done_cb)(void*);

    img_rot_angle_enum_t          rot_angle; /**< rotate direction */

} config_vp;

#if defined(IDP_HISR_SUPPORT) || defined(IDP_KMV_VIDEO_SUPPORT)
static kal_bool idp_scen_vp_busy;
#endif

#if defined(IDP_HISR_SUPPORT)
static idp_hisr_handle_t idp_video_decode_frame_done_hisr_handle;
#endif

#if defined(IDP_VIDEO_DECODE_2PASS_ROTATE_TRICK)
enum idp_video_decode_2pass_state_enum
{
    IDP_VIDEO_DECODE_2PASS_STATE_NULL,
    IDP_VIDEO_DECODE_2PASS_STATE_CONFIG,
    IDP_VIDEO_DECODE_2PASS_STATE_RUN
};
typedef enum idp_video_decode_2pass_state_enum idp_video_decode_2pass_state_t;

static idp_video_decode_2pass_state_t vp_2pass_state = IDP_VIDEO_DECODE_2PASS_STATE_NULL;

static kal_uint16 final_tar_width;
static kal_uint16 final_tar_height;
static kal_uint32 final_y_dest_start_addr;
#endif

static kal_uint16 idp_scen_vp_sm_y_offset;
static kal_uint16 idp_scen_vp_sm_uv_offset;

#if defined(IDP_KMV_VIDEO_SUPPORT)
static void (*videoRenderCb)(void*) = NULL;
static kal_uint32 cbParam = 0;
static kal_uint32 videoRenderKey = 0;
static kal_bool isRenderLocked = KAL_FALSE;
static kal_uint32 startTime = 0;
static kal_uint32 endTime = 0;
static kal_uint32 maxExecTime = 0;
#endif

/****************************************************************************
 * Utilities
 ****************************************************************************/
#if defined(IDP_VIDEO_DECODE_TRACE)
enum idp_video_decode_trace_id_enum
{
    IDP_VIDEO_DECODE_TRACE_NONE,
    IDP_VIDEO_DECODE_DONE_HISR,
    IDP_VIDEO_DECODE_START_LISR,
    IDP_VIDEO_DECODE_OPEN,
    IDP_VIDEO_DECODE_CLOSE,
    IDP_VIDEO_DECODE_START,
    IDP_VIDEO_DECODE_STOP,
    IDP_VIDEO_DECODE_CONFIG,
    IDP_VIDEO_DECODE_NOT_BUSY,
    IDP_VIDEO_DECODE_IS_BUSY
};
typedef enum idp_video_decode_trace_id_enum idp_video_decode_trace_id_t;

struct idp_video_decode_trace_entry_struct
{
    idp_video_decode_trace_id_t     trace_id;
    kal_uint32                      drv_time;
    kal_uint32                      param;
};
typedef struct idp_video_decode_trace_entry_struct idp_video_decode_trace_entry_t;

#define IDP_VIDEO_DECODE_LOG_SIZE (64)
static kal_uint32 idp_video_decode_log_idx = 0;
static idp_video_decode_trace_entry_t idp_video_decode_log[IDP_VIDEO_DECODE_LOG_SIZE];

static void
idp_video_decode_trace(idp_video_decode_trace_id_t id, kal_uint32 param)
{
#if defined(__MTK_TARGET__)
    kal_uint32 savedMask = SaveAndSetIRQMask();
    kal_uint32 log_idx = idp_video_decode_log_idx;

    // To prevent too many IS_BUSY from a pooling loop.
    if (IDP_VIDEO_DECODE_IS_BUSY == id)
    {
        kal_uint32 prev_log_idx = (0 == log_idx)?(IDP_VIDEO_DECODE_LOG_SIZE-1):(log_idx-1);

        if (IDP_VIDEO_DECODE_IS_BUSY == idp_video_decode_log[prev_log_idx].trace_id)
        {
            log_idx = prev_log_idx;
            idp_video_decode_log_idx = prev_log_idx;
        }
    }

    idp_video_decode_log[log_idx].trace_id = id;
    idp_video_decode_log[log_idx].drv_time = drv_get_current_time();
    idp_video_decode_log[log_idx].param = param;

    ++idp_video_decode_log_idx;
    idp_video_decode_log_idx &= (IDP_VIDEO_DECODE_LOG_SIZE - 1);

    RestoreIRQMask(savedMask);
#endif

    return;
}
#endif  // #if defined(IDP_VIDEO_DECODE_TRACE)

/****************************************************************************
 * local function bodies -- LISR
 ****************************************************************************/
#if defined(__MTK_TARGET__)
static void
_idp_scen_vp__lisr_crz__frame_start(void *user_data)
{
    idp_add_traced_lisr(IDP_TRACED_API_video_decode__________CRZ_START_LISR);

    #if defined(IDP_VIDEO_DECODE_TRACE)
    idp_video_decode_trace(IDP_VIDEO_DECODE_START_LISR, REG_IMGDMA_ROT_DMA_Y_DST_STR_ADDR);
    #endif
}

static void
_idp_scen_vp__lisr_rotdma0__frame_done(void *user_data)
{
    idp_add_traced_lisr(IDP_TRACED_API_video_decode__________IRT0_LISR);

    #if defined(IDP_HISR_SUPPORT)
    idp_hisr_activate(idp_video_decode_frame_done_hisr_handle);
    #endif
}

static void
_idp_scen_vp__lisr_crz__pixel_dropped(void *user_data)
{
    idp_add_traced_lisr(IDP_TRACED_API_video_decode__________CRZ_PIXEL_DROPPED_LISR);
    ASSERT(0);
}

/****************************************************************************
 * local function bodies -- HISR
 ****************************************************************************/
#if defined(IDP_HISR_SUPPORT)
static kal_bool
_idp_scen_vp__hisr_rotdma0__frame_done(void *user_data)
{
    kal_uint32 save_irq_mask;
    kal_bool triggerDisplay = KAL_TRUE;
    kal_uint32 execTime = 0;
        
    idp_add_traced_lisr(IDP_TRACED_API_video_decode__________IRT0_DONE_HISR);

    #if defined(IDP_VIDEO_DECODE_TRACE)
    idp_video_decode_trace(IDP_VIDEO_DECODE_DONE_HISR, REG_IMGDMA_ROT_DMA_Y_DST_STR_ADDR);
    #endif

#if defined(IDP_VIDEO_DECODE_2PASS_ROTATE_TRICK)
    // Pass2 enlarge only
    if (vp_2pass_state == IDP_VIDEO_DECODE_2PASS_STATE_RUN)
    {
        // Change CRZ input fomat, src address/width/hight and target width/hight, clip width
        crz_struct.mem_in_color_fmt1 = MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422;
        crz_struct.src_buff_y_addr = rotdma0_struct.y_dest_start_addr;
        crz_struct.src_width = crz_struct.tar_height;
        crz_struct.src_height = crz_struct.tar_width;
        crz_struct.org_width = crz_struct.src_width;
        crz_struct.tar_width = final_tar_width;
        crz_struct.tar_height = final_tar_height;

        // Pass1 do pitch, so pass2 need CRZ src clip 
        // The sm_offset don't need re-calculate, because we start clip at first pixel, that is 0
        if (rotdma0_struct.pitch_enable == KAL_TRUE)
        {
            crz_struct.org_width =  (rotdma0_struct.pitch_bytes >> 1);
        }

        // Change ROTDMA src width/hight, dest address and rot angle
        rotdma0_struct.src_width = final_tar_width;
        rotdma0_struct.src_height = final_tar_height;
        rotdma0_struct.y_dest_start_addr = final_y_dest_start_addr;
        rotdma0_struct.rot_angle = IMG_ROT_ANGLE_0;

        idp_resz_crz_config_real(&crz_struct, KAL_TRUE);
        idp_imgdma_rotdma0_config_real(&rotdma0_struct, KAL_TRUE);

        idp_imgdma_rotdma0_start_real(&rotdma0_struct);
        idp_resz_crz_start_real(&crz_struct);

        vp_2pass_state = IDP_VIDEO_DECODE_2PASS_STATE_NULL;

        return KAL_TRUE;
    }
#endif

    save_irq_mask = SaveAndSetIRQMask();
#if defined(IDP_KMV_VIDEO_SUPPORT)
    if (KAL_TRUE == isRenderLocked)
#endif
    idp_scen_vp_busy = KAL_FALSE;
    RestoreIRQMask(save_irq_mask);
    
    /* update LCD */
    if (NULL != config_vp.frame_done_cb)
    {
#if defined(IDP_KMV_VIDEO_SUPPORT)
        if (KAL_FALSE == isRenderLocked)
    {
            config_vp.frame_done_cb(&cbParam);
        if (NULL != videoRenderCb)
        {
                triggerDisplay = KAL_FALSE;
            videoRenderCb(&triggerDisplay);
        }
    }
        else
        {
            config_vp.frame_done_cb(&triggerDisplay);
            videoRenderCb = config_vp.frame_done_cb;
        }
    #else
        config_vp.frame_done_cb(&triggerDisplay);
#endif
    }

    execTime = drv_get_duration_ms(startTime);
    if (maxExecTime < execTime)
        maxExecTime = execTime;

    return KAL_TRUE;
}
#endif  // #if defined(IDP_HISR_SUPPORT)

/****************************************************************************
 * local function bodies -- HW config functions
 ****************************************************************************/
static kal_bool
_idp_scen_vp__config_crz(
    idp_owner_t * const owner,
    kal_bool const config_to_hardware)
{
    crz_struct.two_pass_resize_en = KAL_FALSE;

    crz_struct.input_src1 = IDP_MODULE_IMGDMA_RDMA0;
    crz_struct.mem_in_color_fmt1 = MM_IMAGE_COLOR_FORMAT_YUV420;

    crz_struct.fstart1_intr_en = KAL_TRUE;
    crz_struct.fstart1_intr_cb = _idp_scen_vp__lisr_crz__frame_start;

    crz_struct.pixel_dropped_intr_en = KAL_TRUE;
    crz_struct.pixel_dropped_intr_cb = _idp_scen_vp__lisr_crz__pixel_dropped;

    if (config_vp.src_clip == KAL_TRUE)
    {
        config_vp.video_frame_real_width = (config_vp.src_clip_right - config_vp.src_clip_left + 1);
        config_vp.video_frame_real_height = (config_vp.src_clip_bottom - config_vp.src_clip_top + 1);
    }

    // [MAUI_01669210] Use the limited source clipping function to clip off the padding
    if ((0 == config_vp.video_frame_real_width) &&
        (0 == config_vp.video_frame_real_height))
    {
        crz_struct.src_width = config_vp.source_width;
        crz_struct.src_height = config_vp.source_height;

        return KAL_FALSE;
    }
    else
    {
        if (config_vp.video_frame_real_width > config_vp.source_width)
        {
            return KAL_FALSE;
        }
        if (config_vp.video_frame_real_height > config_vp.source_height)
        {
            return KAL_FALSE;
        }

        // [MAUI_01759065] If the width/height are odd numbers, the original behavior is no support for this kind of file.
        // In this CR, we add a dummy line for odd number of width/height in order to support this kind of files.
        // The side effect is that MAYBE we will see a garbage line at the video's right or down side.
        if (0 == (config_vp.video_frame_real_width & 0x01))
        {
            crz_struct.src_width = config_vp.video_frame_real_width;
        }
        else
        {
            crz_struct.src_width = config_vp.video_frame_real_width + 1;
        }

        if (0 == (config_vp.video_frame_real_height & 0x01))
        {
            crz_struct.src_height = config_vp.video_frame_real_height;
        }
        else
        {
            crz_struct.src_height = config_vp.video_frame_real_height + 1;
        }
    }

    crz_struct.tar_width = config_vp.target_width;
    crz_struct.tar_height = config_vp.target_height;

    // Target width check even because format alignment, target format is UYVY422
    // Heigth might odd if use outside mode of target clip width/height
    if (0 != (crz_struct.tar_width & 0x1) && (config_vp.rot_angle == IMG_ROT_ANGLE_0))
    {
        return KAL_FALSE;
    }
    if (0 != (crz_struct.tar_height & 0x1) && (config_vp.rot_angle == IMG_MIRROR_ROT_ANGLE_90))
    {
        return KAL_FALSE;
    }

    // Source clip color is MM_IMAGE_COLOR_FORMAT_YUV420, y and uv offset need re-cauculate
    idp_scen_vp_sm_y_offset = (config_vp.source_width * config_vp.src_clip_top) + config_vp.src_clip_left;
    idp_scen_vp_sm_uv_offset = (config_vp.source_width * (config_vp.src_clip_top >> 2)) + (config_vp.src_clip_left >> 1);

    crz_struct.src_buff_y_addr += idp_scen_vp_sm_y_offset;
    crz_struct.src_buff_u_addr += idp_scen_vp_sm_uv_offset;
    crz_struct.src_buff_v_addr += idp_scen_vp_sm_uv_offset;

    // Target clip, change to source clip
    // Re-calculate src_width or src_height, and idp_scen_vp_sm_offset
    if (config_vp.target_clip == KAL_TRUE)
    {
        kal_uint32 h_ratio, v_ratio;
        kal_uint16 clip_w, clip_h, offset_x = 0, offset_y = 0;

        clip_w = config_vp.target_clip_right - config_vp.target_clip_left + 1;
        clip_h = config_vp.target_clip_bottom - config_vp.target_clip_top + 1;

        crz_struct.tar_width = clip_w;
        crz_struct.tar_height = clip_h;

        h_ratio = (clip_w<<16) / crz_struct.src_width;
        v_ratio = (clip_h<<16) / crz_struct.src_height;

        if (h_ratio > v_ratio)
        {
            // src_height needs to be changed...
            clip_h = (clip_h<<16) / h_ratio;
            crz_struct.src_height = ((clip_h+1)>>1) << 1;

            offset_x = 0;
            offset_y = (config_vp.video_frame_real_height - crz_struct.src_height) >> 1;

            // re-cauculate offset_y to 2x offset allignment
            if ((offset_y & 0x1) == 1)
            {
                offset_y--;
            }
        }
        else if (h_ratio < v_ratio)
        {
            // src_width needs to be changed...
            clip_w = (clip_w<<16) / v_ratio;
            crz_struct.src_width = ((clip_w+1)>>1) << 1;

            offset_x = (config_vp.video_frame_real_width - crz_struct.src_width) >> 1;
            offset_y = 0;

            // re-cauculate offset_x to 2x offset allignment
            if ((offset_x & 0x1) == 1)
            {
                offset_x--;
            }
        }
        offset_x += config_vp.src_clip_left;
        offset_y += config_vp.src_clip_top;

        // Source color is MM_IMAGE_COLOR_FORMAT_YUV420, y and uv offset need re-cauculate
        idp_scen_vp_sm_y_offset = (config_vp.source_width * offset_y) + offset_x;
        idp_scen_vp_sm_uv_offset = (config_vp.source_width * (offset_y >> 2)) + (offset_x >> 1);
    }

#if defined(IDP_VIDEO_DECODE_2PASS_ROTATE_TRICK)
    #if defined(MT6252H) || defined(MT6252)
    // Check if need 2 pass
    if ((config_vp.target_width > 320) && (config_vp.rot_angle == IMG_MIRROR_ROT_ANGLE_90))
    {
        // Pass1 rotate and shrink to width = 320
        final_tar_width = crz_struct.tar_height;
        final_tar_height = crz_struct.tar_width;
        crz_struct.tar_width = 320;

        vp_2pass_state = IDP_VIDEO_DECODE_2PASS_STATE_CONFIG;
    }
    #elif defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    // 50 limit is 480 rotate 90
    if ((config_vp.target_width > 480) && (config_vp.rot_angle == IMG_MIRROR_ROT_ANGLE_90))
    {
        // Pass1 rotate and shrink to width = 480
        final_tar_width = crz_struct.tar_height;
        final_tar_height = crz_struct.tar_width;
        crz_struct.tar_width = 480;

        vp_2pass_state = IDP_VIDEO_DECODE_2PASS_STATE_CONFIG;
    }
    #endif
#endif

    crz_struct.clip_en = KAL_TRUE; //only memory input valid
    crz_struct.org_width = config_vp.source_width; //only memory input valid

    // [MAUI_01670831] return error code instead of assertion...
    if (KAL_FALSE == crz_check_size_limitation(crz_struct.src_width,
                                                crz_struct.src_height,
                                                crz_struct.tar_width,
                                                crz_struct.tar_height,
                                                IDP_MODULE_IMGDMA_RDMA0,
                                                MM_IMAGE_COLOR_FORMAT_YUV420))
    {
        return KAL_FALSE;
    }

    return idp_resz_crz_config(owner->crz_key, &crz_struct, config_to_hardware);
}


static kal_bool
_idp_scen_vp__config_rotdma0(
    idp_owner_t * const owner,
    kal_bool const config_to_hardware)
{
    rotdma0_struct.rot_angle = config_vp.rot_angle;

    rotdma0_struct.src_width = crz_struct.tar_width;
    rotdma0_struct.src_height = crz_struct.tar_height;

#if defined(IDP_KMV_VIDEO_SUPPORT)
    if (KAL_FALSE == isRenderLocked)
    {
        rotdma0_struct.yuv_color_fmt = MM_IMAGE_COLOR_FORMAT_YUV420;
        rotdma0_struct.y_dest_start_addr = config_vp.out_frame_buffer_addr_1;
        rotdma0_struct.u_dest_start_addr = rotdma0_struct.y_dest_start_addr + 
                                           (rotdma0_struct.src_width * rotdma0_struct.src_height);
        rotdma0_struct.v_dest_start_addr = rotdma0_struct.u_dest_start_addr + 
                                           ((rotdma0_struct.src_width * rotdma0_struct.src_height) >> 2);
    }
    else
#endif
    {
        rotdma0_struct.yuv_color_fmt = MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422;
        rotdma0_struct.y_dest_start_addr = config_vp.out_frame_buffer_addr_1;
    }

    rotdma0_struct.pitch_enable = config_vp.pitch;
    rotdma0_struct.pitch_bytes = (config_vp.pitch_width) << 1;
    if (KAL_TRUE == rotdma0_struct.pitch_enable)
    {
        if (0x1 == (config_vp.pitch_width & 0x1))
        {
            // pitch width 2x limitation
            return KAL_FALSE;
        }
    }

    rotdma0_struct.fend_intr_en = KAL_TRUE;
    rotdma0_struct.fend_intr_cb = _idp_scen_vp__lisr_rotdma0__frame_done;

    rotdma0_struct.bus_control_threshold = ROTDMA_BUS_CONTROL_THRESHOLD;

#if defined(IDP_VIDEO_DECODE_2PASS_ROTATE_TRICK)
    // Check if need 2nd pass
    if (vp_2pass_state == IDP_VIDEO_DECODE_2PASS_STATE_CONFIG)
    {
        final_y_dest_start_addr = rotdma0_struct.y_dest_start_addr;

        if (rotdma0_struct.pitch_enable == KAL_TRUE)
        {
            // If we not do pitch in pass1, we need clear side border used by pass1 output buffer to black
            // So we just keep ptich setting.
            // Rotate 90, the crz_struct.tar_height is become 1st output(2nd input) width
            // crz_struct.tar_width is become 1st output(2nd input) height
            // final_tar_height = 400, crz_struct.tar_width = 320
            // idp_cfg->pitch_width = 240
            rotdma0_struct.y_dest_start_addr += 
                (((final_tar_height - crz_struct.tar_width) * config_vp.pitch_width) << 1);
        }
        else
        {
            // final_tar_height = 400, final_tar_width = crz_struct.tar_height = 240
            // crz_struct.tar_width = 320
            rotdma0_struct.y_dest_start_addr +=
                (((final_tar_height - crz_struct.tar_width) * final_tar_width) << 1);
        }
    }
#endif

    if (KAL_FALSE == rotdma_check_size_limitation(rotdma0_struct.src_width,
                                                  rotdma0_struct.src_height,
                                                  MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422,
                                                  rotdma0_struct.rot_angle))
    {
        return KAL_FALSE;
    }

    return idp_imgdma_rotdma0_config(owner->irt0_key, &rotdma0_struct, config_to_hardware);
}

#if defined(MDP_SUPPORT_FAST_POWER_ON_OFF)
void _idp_video_decode_power_on(void)
{
#if defined(DRV_FEATURE__MM_POWER_CTRL_IF)
    mm_enable_power(MMPWRMGR_RESZ);
    mm_enable_power(MMPWRMGR_ROTDMA);
#endif
}


void _idp_video_decode_power_off(void)
{
#if defined(DRV_FEATURE__MM_POWER_CTRL_IF)
    mm_disable_power(MMPWRMGR_RESZ);
    mm_disable_power(MMPWRMGR_ROTDMA);
#endif
}
#endif

#endif  // #if defined(__MTK_TARGET__)

/****************************************************************************
 * local function bodies -- IDP scenario hook function bodies
 ****************************************************************************/
static void
idp_video_decode_init_config_hook(
    idp_owner_t * const owner)
{
#if defined(__MTK_TARGET__)

    #if defined(IDP_HISR_SUPPORT)
    idp_video_decode_frame_done_hisr_handle =
        idp_hisr_register(owner->key,
                        IDP_HISR_CB_TYPE_IMGDMA,
                        _idp_scen_vp__hisr_rotdma0__frame_done,
                        NULL);
    #endif

    #if defined(IDP_MM_COLOR_SUPPORT)
    colorWrapperOpen(&mm_color_handle, COLOR_SCENARIO_VIDEO_PLAYBACK);
    colorWrapperEnable(mm_color_handle, crz_struct.tar_width);
    #endif

    kal_mem_set(&config_vp, 0, sizeof(config_vp));

#endif
}

kal_bool
idp_video_decode_open_hook(
    idp_owner_t * const owner)
{
#if defined(__MTK_TARGET__)
    kal_bool result;

    #if defined(IDP_VIDEO_DECODE_TRACE)
    idp_video_decode_trace(IDP_VIDEO_DECODE_OPEN, 0);
    #endif

    result = idp_common_open_hook(owner);
    if (KAL_FALSE == result)
    {
        return KAL_FALSE;
    }

#if defined(IDP_KMV_VIDEO_SUPPORT)
    // record Video Renderer key
    if (0 != owner->key)
    {
        videoRenderKey = owner->key;
    }
#endif
#endif
    return KAL_TRUE;
}

static void
idp_video_decode_busy_wait(
    kal_uint32 const key)
{
    kal_bool busy;
    kal_uint32 last_time = drv_get_current_time();

    // Check if video decode busy, if busy over 1000 tick, stop anyway...
    do
    {
        idp_video_decode_is_busy(key, &busy);

    } while ((KAL_TRUE == busy) &&
        (1000 > drv_get_duration_tick(last_time, drv_get_current_time())));
}

kal_bool
idp_video_decode_close_hook(
    idp_owner_t * const owner)
{
#if defined(__MTK_TARGET__)
    #if defined(IDP_VIDEO_DECODE_TRACE)
    idp_video_decode_trace(IDP_VIDEO_DECODE_CLOSE, 0);
    #endif

    idp_video_decode_busy_wait(owner->key);

    idp_common_stop_hook(owner);

    idp_resz_crz_close(owner->crz_key, &crz_struct);
    idp_imgdma_rotdma0_close(owner->irt0_key, &rotdma0_struct);

    #if defined(IDP_HISR_SUPPORT)
    idp_hisr_clear_all(owner->key, IDP_HISR_CB_TYPE_IMGDMA);
    idp_video_decode_frame_done_hisr_handle = NULL;
    #endif

    #if defined(IDP_MM_COLOR_SUPPORT)
    colorWrapperDisable(mm_color_handle);
    colorWrapperClose(mm_color_handle);
    #endif

#endif

    return KAL_TRUE;
}

kal_bool
idp_video_decode_stop_hook(
    idp_owner_t * const owner)
{
#if defined(__MTK_TARGET__)
    #if defined(IDP_VIDEO_DECODE_TRACE)
    idp_video_decode_trace(IDP_VIDEO_DECODE_STOP, 0);
    #endif

    idp_video_decode_busy_wait(owner->key);

    idp_common_stop_hook(owner);

    return KAL_TRUE;
#else
    return KAL_FALSE;
#endif
}



kal_bool
idp_video_decode_read_user_config_fast_hook(
    idp_owner_t * const owner,
    kal_uint32 const para_type,
    kal_uint32 const para_value)
{
#if defined(__MTK_TARGET__)
#if defined(MDP_SUPPORT_FAST_POWER_ON_OFF)
    switch (para_type)
    {
        case IDP_VIDEO_DECODE_POWER_CTRL:
            if (KAL_TRUE == (kal_bool) para_value)
            {
                _idp_video_decode_power_on();
            }
            else
            {
                _idp_video_decode_power_off();
            }
            break;

        default:
            return KAL_FALSE;
    }
#endif
#endif

    return KAL_TRUE;
}


kal_bool
idp_video_decode_read_user_config_hook(
    idp_owner_t * const owner,
    va_list ap)
{
    kal_uint32 para_type;
    kal_bool finish = KAL_FALSE;

    while (KAL_FALSE == finish)
    {
        para_type = va_arg(ap, kal_uint32);

        switch (para_type)
        {
            case 0:
                finish = KAL_TRUE;
                break;

            case IDP_VIDEO_DECODE_SRC_WIDTH:
                config_vp.source_width = (kal_uint16) va_arg(ap, kal_uint32);
                break;

            case IDP_VIDEO_DECODE_SRC_HEIGHT:
                config_vp.source_height = (kal_uint16) va_arg(ap, kal_uint32);
                break;

            case IDP_VIDEO_DECODE_ENABLE_CLIP:
                config_vp.src_clip = (kal_bool) va_arg(ap, kal_uint32);
                break;

            case IDP_VIDEO_DECODE_CLIP_LEFT:
                config_vp.src_clip_left = (kal_uint16) va_arg(ap, kal_uint32);
                break;

            case IDP_VIDEO_DECODE_CLIP_RIGHT:
                config_vp.src_clip_right = (kal_uint16) va_arg(ap, kal_uint32);
                break;

            case IDP_VIDEO_DECODE_CLIP_TOP:
                config_vp.src_clip_top = (kal_uint16) va_arg(ap, kal_uint32);
                break;

            case IDP_VIDEO_DECODE_CLIP_BOTTOM:
                config_vp.src_clip_bottom = (kal_uint16) va_arg(ap, kal_uint32);
                break;

            case IDP_VIDEO_DECODE_TARGET_WIDTH:
                config_vp.target_width = (kal_uint16) va_arg(ap, kal_uint32);
                break;

            case IDP_VIDEO_DECODE_TARGET_HEIGHT:
                config_vp.target_height = (kal_uint16) va_arg(ap, kal_uint32);
                break;

            case IDP_VIDEO_DECODE_DST_CLIP:
                config_vp.target_clip = (kal_bool) va_arg(ap, kal_uint32);
                config_vp.target_clip_top = va_arg(ap, kal_uint32);
                config_vp.target_clip_bottom = va_arg(ap, kal_uint32);
                config_vp.target_clip_left = va_arg(ap, kal_uint32);
                config_vp.target_clip_right = va_arg(ap, kal_uint32);
                break;

            case IDP_VIDEO_DECODE_ENABLE_PITCH:
                config_vp.pitch = (kal_bool) va_arg(ap, kal_uint32);
                break;

            case IDP_VIDEO_DECODE_BG_IMAGE_WIDTH:
                config_vp.pitch_width = (kal_uint16) va_arg(ap, kal_uint32);
                break;

            case IDP_VIDEO_DECODE_FRAME_BUFFER_ADDRESS:
                config_vp.out_frame_buffer_addr_1 = va_arg(ap, kal_uint32);
                break;

            case IDP_VIDEO_DECODE_DONE_CB:
                config_vp.frame_done_cb = (void (*)(void *)) va_arg(ap, kal_uint32);
                break;

        #if defined(IDP_KMV_VIDEO_SUPPORT)
            case IDP_VIDEO_DECODE_DONE_CB_PARAM: 
                cbParam = (kal_uint32)va_arg(ap, kal_uint32);
                break;
        #endif

            case IDP_VIDEO_DECODE_ROT_ANGLE:
                config_vp.rot_angle = (img_rot_angle_enum_t) va_arg(ap, kal_uint32);
                break;

            case IDP_VIDEO_DECODE_VIDEO_Y_BUFFER_ADDRESS:
                crz_struct.src_buff_y_addr = va_arg(ap, kal_uint32);
                break;

            case IDP_VIDEO_DECODE_VIDEO_U_BUFFER_ADDRESS:
                crz_struct.src_buff_u_addr = va_arg(ap, kal_uint32);
                break;

            case IDP_VIDEO_DECODE_VIDEO_V_BUFFER_ADDRESS:
                crz_struct.src_buff_v_addr = va_arg(ap, kal_uint32);
                break;

            default:
                va_arg(ap, kal_uint32);
                break;
        }
    }

    return KAL_TRUE;
}


#if defined(IDP_KMV_VIDEO_SUPPORT)
kal_bool
idp_video_decode_get_key(
    kal_uint32 * idpKey)
{
    *idpKey = videoRenderKey;
    
    if (0 != *idpKey)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}
#endif


kal_bool
idp_video_decode_query_hook(
    idp_owner_t * const owner,
    va_list ap)
{
#if defined(__MTK_TARGET__)

    kal_uint32 para_type;
    kal_bool finish = KAL_FALSE;

    while (KAL_FALSE == finish)
    {
        para_type = va_arg(ap, kal_uint32);

        switch (para_type)
        {
            case 0:
                finish = KAL_TRUE;
                break;

                case IDP_VIDEO_DECODE_QUERY_ERROR_CODE:
                {
                    idp_video_decode_error_code_t * const error_code_place =
                    va_arg(ap, idp_video_decode_error_code_t *);

                    if (error_code_place != NULL)
                    {
                        (*error_code_place) = IDP_VIDEO_DECODE_NO_ERROR;
                    }
                }
                break;

            case IDP_VIDEO_DECODE_QUERY_CURRENT_DECODABLE_VIDEO_YUV_BUFFER_ADDR:
                {
                    kal_uint8 ** const y_addr_place = va_arg(ap, kal_uint8 **);
                    kal_uint8 ** const u_addr_place = va_arg(ap, kal_uint8 **);
                    kal_uint8 ** const v_addr_place = va_arg(ap, kal_uint8 **);

                    (*y_addr_place) = (kal_uint8 *)(crz_struct.src_buff_y_addr);
                    (*u_addr_place) = (kal_uint8 *)(crz_struct.src_buff_u_addr);
                    (*v_addr_place) = (kal_uint8 *)(crz_struct.src_buff_v_addr);
                }
                break;

        #if defined(IDP_KMV_VIDEO_SUPPORT)
            case IDP_VIDEO_DECODE_QUERY_AND_LOCK_IDP_DRIVER:
                {
                    kal_bool * const idpLockResult = va_arg(ap, kal_bool *);
                    kal_uint32 isRenderUsage = va_arg(ap, kal_uint32);

                    kal_uint32 save_irq_mask = SaveAndSetIRQMask();
                    if (KAL_FALSE == idp_scen_vp_busy)
                    {
                        idp_scen_vp_busy = KAL_TRUE;
                        *idpLockResult = KAL_TRUE;

                        if (KAL_TRUE == isRenderUsage)
                        {
                            isRenderLocked = KAL_TRUE;
                        }
                        else
                        {
                            isRenderLocked = KAL_FALSE;
                        }
                    }
                    else
                    {
                        *idpLockResult = KAL_FALSE;
                    }
                    RestoreIRQMask(save_irq_mask);
                }
                break;

            case IDP_VIDEO_DECODE_QUERY_AND_UNLOCK_IDP_DRIVER:
                {
                    kal_uint32 save_irq_mask = SaveAndSetIRQMask();
                    if (KAL_TRUE == idp_scen_vp_busy)
                    {
                        idp_scen_vp_busy = KAL_FALSE;
                    }
                    RestoreIRQMask(save_irq_mask);
                }
                break;
        #endif
        
            default:
                return KAL_FALSE;
                //break;
        }
    }
#endif
    return KAL_TRUE;
}

kal_bool
idp_video_decode_start_input_hook(
    idp_owner_t * const owner)
{
#if defined(__MTK_TARGET__)

#if defined(IDP_HISR_SUPPORT) && !defined(IDP_KMV_VIDEO_SUPPORT)
    {
      kal_uint32 savedMask = SaveAndSetIRQMask();
      idp_scen_vp_busy = KAL_TRUE;
      RestoreIRQMask(savedMask);
    }
#endif

    idp_resz_crz_start(owner->crz_key, &crz_struct);

    startTime = drv_get_current_time();

    #if defined(IDP_VIDEO_DECODE_2PASS_ROTATE_TRICK)
    if (vp_2pass_state == IDP_VIDEO_DECODE_2PASS_STATE_CONFIG)
    {
        vp_2pass_state = IDP_VIDEO_DECODE_2PASS_STATE_RUN;
    }
    #endif

#endif

    return KAL_TRUE;
}

kal_bool
idp_video_decode_is_busy_hook(
    idp_owner_t const * const owner,
    kal_bool * const busy)
{
#if defined(__MTK_TARGET__)

    *busy = KAL_FALSE;
    idp_common_is_busy_hook(owner, busy);

    #if 0//!defined(VP_USE_DOUBLE_BUFFER)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    #if defined(IDP_VIDEO_DECODE_2PASS_ROTATE_TRICK)
    // Pass 1 is runing. Pass2 will run soon.
    if (vp_2pass_state == IDP_VIDEO_DECODE_2PASS_STATE_RUN)
    {
        *busy = KAL_TRUE;
    }
    #endif

    #if defined(IDP_HISR_SUPPORT)
    {
      kal_uint32 savedMask = SaveAndSetIRQMask();    
      if (idp_scen_vp_busy == KAL_TRUE)
      {
          *busy = KAL_TRUE;
      }
      RestoreIRQMask(savedMask);
    }
    #endif

    #if defined(IDP_VIDEO_DECODE_TRACE)
    idp_video_decode_trace(((KAL_TRUE == *busy) ? IDP_VIDEO_DECODE_IS_BUSY : IDP_VIDEO_DECODE_NOT_BUSY), 0);
    #endif

#endif

    return KAL_TRUE;
}


kal_bool
idp_video_decode_config_hook(
    idp_owner_t * const owner,
    kal_bool const config_to_hardware)
{
    kal_bool result = KAL_TRUE;

#if defined(__MTK_TARGET__)
    #if defined(IDP_VIDEO_DECODE_TRACE)
    idp_video_decode_trace(IDP_VIDEO_DECODE_CONFIG, 0);
    #endif

    result = _idp_scen_vp__config_crz(owner, config_to_hardware);
    if (KAL_FALSE == result)
    {
        return KAL_FALSE;
    }

    result = _idp_scen_vp__config_rotdma0(owner, config_to_hardware);
    if (KAL_FALSE == result)
    {
        return KAL_FALSE;
    }

#endif
    return result;
}

static hook_collect_t hook_collect =
{
    idp_video_decode_init_config_hook,
    idp_video_decode_open_hook,
    idp_video_decode_close_hook,
    idp_video_decode_stop_hook,
    idp_video_decode_read_user_config_hook,
    idp_video_decode_read_user_config_fast_hook,
    idp_dummy_hook3,//idp_video_decode_finish_read_user_config_hook,
    idp_dummy_hook,//idp_video_decode_hardware_setting_have_been_changed_hook,
    idp_video_decode_config_hook,
    idp_video_decode_query_hook,
    idp_dummy_hook,//idp_video_decode_start_intermedia_pipe_hook,
    idp_video_decode_start_input_hook,
    idp_common_start_output_hook,//idp_video_decode_start_output_hook,
    idp_dummy_hook2,//idp_video_decode_compute_mem_for_each_hw_hook,
    idp_video_decode_is_busy_hook,
    idp_common_is_in_use_hook,//idp_video_decode_is_in_use_hook,
    idp_dummy_hook2,//idp_video_decode_clear_setting_diff_hook,
    idp_dummy_hook//idp_video_decode_is_setting_diff_is_ok_when_busy_hook
};





static IdpCheckReentrant idp_video_decode_check_reentrant = {KAL_NILTASK_ID, IDP_CALL_BY_HISR, IDP_CHECK_REENTRANT_PREV_OPEN, KAL_FALSE};

kal_bool
idp_video_decode_open_real(
    kal_uint32 * const key,
    char const * const filename,
    kal_uint32 const lineno)
{
    return idp_scenario_open(key,
                             &idp_video_decode_check_reentrant,
                             IDP_TRACED_API_video_decode_OPEN,
                             IDP_SCENARIO_video_decode,
                             &hook_collect);
}

kal_bool
idp_video_decode_is_in_use(void)
{
    return idp_scenario_is_in_use(&idp_video_decode_check_reentrant,
                                  IDP_TRACED_API_video_decode_IS_IN_USE,
                                  &hook_collect);
}

kal_bool
idp_video_decode_close(
    kal_uint32 const key)
{
    return idp_scenario_close(key,
                              &idp_video_decode_check_reentrant,
                              IDP_TRACED_API_video_decode_CLOSE,
                              &hook_collect);
}

kal_bool
idp_video_decode_stop(
    kal_uint32 const key)
{
    return idp_scenario_stop(key,
                             &idp_video_decode_check_reentrant,
                             IDP_TRACED_API_video_decode_STOP,
                             &hook_collect);
}

kal_bool
idp_video_decode_start_intermedia_pipe(
    kal_uint32 const key)
{
    return idp_scenario_start_intermedia_pipe(key,
                                              &idp_video_decode_check_reentrant,
                                              IDP_TRACED_API_video_decode_START_INTERMEDIA_PIPE,
                                              &hook_collect);
}

kal_bool
idp_video_decode_start_input(
    kal_uint32 const key)
{
    return idp_scenario_start_input(key,
                                    &idp_video_decode_check_reentrant,
                                    IDP_TRACED_API_video_decode_START_INPUT,
                                    &hook_collect);
}

kal_bool
idp_video_decode_start_output(
    kal_uint32 const key)
{
    return idp_scenario_start_output(key,
                                     &idp_video_decode_check_reentrant,
                                     IDP_TRACED_API_video_decode_START_OUTPUT,
                                     &hook_collect);
}

kal_bool
idp_video_decode_start_all(
    kal_uint32 const key)
{
    return idp_scenario_start_all(key,
                                  &idp_video_decode_check_reentrant,
                                  IDP_TRACED_API_video_decode_START_ALL,
                                  &hook_collect);
}

kal_bool
idp_video_decode_is_busy(
    kal_uint32 const key,
    kal_bool * const busy)
{
    return idp_scenario_is_busy(key,
                                busy,
                                IDP_TRACED_API_video_decode_IS_BUSY,
                                &hook_collect);
}

kal_bool
idp_video_decode_config_fast(
    kal_uint32 const key,
    kal_uint32 const para_type,
    kal_uint32 const para_value)
{
    return idp_scenario_config_fast(key,
                                    para_type,
                                    para_value,
                                    IDP_TRACED_API_video_decode_CONFIG_FAST,
                                    &hook_collect);
}

kal_bool
idp_video_decode_config(
    kal_uint32 const key,
    ...)
{
    va_list ap;
    kal_bool result;
    if (0 == key)
    {
        return KAL_FALSE;
    }

    va_start(ap, key);

    result = idp_scenario_config(key,
                                 &idp_video_decode_check_reentrant,
                                 IDP_TRACED_API_video_decode_CONFIG,
                                 &hook_collect,
                                 ap);
    va_end(ap);
    return result;

}

kal_bool
idp_video_decode_configurable(
    kal_uint32 const key,
    ...)
{
    va_list ap;
    kal_bool result;
    if (0 == key)
    {
        return KAL_FALSE;
    }

    va_start(ap, key);

    result = idp_scenario_configurable(key,
                                       &idp_video_decode_check_reentrant,
                                       IDP_TRACED_API_video_decode_CONFIGURABLE,
                                       &hook_collect,
                                       ap);
    va_end(ap);
    return result;
}


kal_bool
idp_video_decode_query(
    kal_uint32 const key,
    ...)
{
    va_list ap;
    kal_bool result;
    if (0 == key)
    {
        return KAL_FALSE;
    }

    va_start(ap, key);

    result = idp_scenario_query(key,
                                &idp_video_decode_check_reentrant,
                                IDP_TRACED_API_video_decode_QUERY,
                                &hook_collect,
                                ap);
    va_end(ap);
    return result;
}


kal_bool idp_video_decode_config_and_start(
    kal_uint32 const key,
    ...)
{
    va_list ap;
    kal_bool result;
    if (0 == key)
    {
        return KAL_FALSE;
    }

    va_start(ap, key);

    result = idp_scenario_config_and_start(key,
                                           &idp_video_decode_check_reentrant,
                                           IDP_TRACED_API_video_decode_CONFIG_AND_START,
                                           &hook_collect,
                                           ap);
    va_end(ap);
    return result;
}


#endif  // #if defined(DRV_IDP_6252_SERIES)


