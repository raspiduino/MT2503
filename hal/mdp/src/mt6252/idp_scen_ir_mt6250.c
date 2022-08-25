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
 *    idp_scen_image_resize_mt6255.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *
 *    RDMA -> CRZ ->  IPP -> MOUT -> RGBROT0
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
 * 01 21 2014 chrono.wu
 * removed!
 * 	.
 *
 * 02 18 2013 peter.wang
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
 * 07 03 2012 peter.wang
 * removed!
 * .
 *
 * 06 18 2012 peter.wang
 * removed!
 * .
 *
 * 06 05 2012 peter.wang
 * removed!
 * .
 *
 * 06 04 2012 peter.wang
 * removed!
 * .
 *
 * 05 31 2012 peter.wang
 * removed!
 * .
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* macros and options
****************************************************************************/
#define THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
/****************************************************************************/
/****************************************************************************
* include directives
****************************************************************************/

#include "drv_comm.h"
#include <idp_define.h>

// only MAV need image resize
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)

#include <idp_core.h>

#include <idp_image_resize.h>
#include <idp_camera_preview.h>
#include <mt6252/idp_engines.h>
#include <idp_cam_if.h>

#if defined(IDP_HISR_SUPPORT)
#include <mt6252/idp_hisr.h>
#endif
#include <mt6252/idp_scen_common_mt6252.h>

/****************************************************************************
* local variables
****************************************************************************/
static struct
{
    kal_uint32 intmem_start_address;  /* internal memory start address for hardware engine buffer */
    kal_uint32 intmem_size;           /* internal memory size for hardware engine buffer */
    kal_uint32 extmem_start_address;  /* external memroy start address for hardware engine buffer */
    kal_uint32 extmem_size;           /* external memory size for hardware engine buffer */

    MM_IMAGE_COLOR_FORMAT_ENUM src_color_fmt;
    MM_IMAGE_COLOR_FORMAT_ENUM dest_color_fmt;

    kal_uint32 src_image_address;  /* the source image buffer start address */
    kal_uint32 src_image_u_address;  /* the source image U buffer start address */
    kal_uint32 src_image_v_address;  /* the source image V buffer start address */
    kal_uint32 dest_image_address; /* the destination image buffer start address */

    kal_uint16 src_width;          /* the width of image source */
    kal_uint16 src_height;         /* the height of image source */

    kal_uint16 target_width;       /* the width of target image */
    kal_uint16 target_height;      /* the height of target image */

    kal_bool   enable_src_clip;
    kal_uint16 src_clip_left;
    kal_uint16 src_clip_right;
    kal_uint16 src_clip_top;
    kal_uint16 src_clip_bottom;

    kal_uint16 image_clip_width;
    kal_uint16 image_clip_height;

    kal_bool   target_clip;
    kal_uint16 target_clip_left;
    kal_uint16 target_clip_right;
    kal_uint16 target_clip_top;
    kal_uint16 target_clip_bottom;

    img_rot_angle_enum_t rot_angle;

    kal_bool   enable_pitch;
    kal_uint32 bg_image_width;

    kal_uint32 resizer_u_value;
    kal_uint32 resizer_d_value;

    idp_hisr_intr_cb_t        frame_done_cbfunc;
    void*                     frame_done_cbparam;

    kal_bool   end_config;
} config_ir;

//static idp_image_resize_error_code_t error_code = IDP_IMAGE_RESIZE_NO_ERROR;

static kal_uint16 idp_scen_ir_sm_y_offset;
static kal_uint16 idp_scen_ir_sm_uv_offset;

#if defined(IDP_HISR_SUPPORT)
static idp_hisr_handle_t _idp_scen_image_resize_frame_done_hisr_handle = NULL;
#endif

/****************************************************************************
* local function bodies -- HW config functions
****************************************************************************/
#if defined(__MTK_TARGET__)
static void
_idp_scen_ir__lisr_rotdma0__frame_done(void *user_data)
{
    idp_add_traced_lisr(IDP_TRACED_API_image_resize__________ROTDMA0_DONE_LISR);

#if defined(IDP_HISR_SUPPORT)
    idp_hisr_activate(_idp_scen_image_resize_frame_done_hisr_handle);
#endif
}

#if defined(IDP_HISR_SUPPORT)
static kal_bool
_idp_scen_ir__hisr_rotdma0__frame_done(void *param)
{
    if (NULL != config_ir.frame_done_cbfunc)
    {
        config_ir.frame_done_cbfunc(config_ir.frame_done_cbparam);
    }
    return KAL_TRUE;
}
#endif

static kal_bool
_idp_scen_ir_config_crz(
    idp_owner_t * const owner,
    kal_bool const config_to_hardware)
{
    kal_bool result;

    // Path control parameters
    crz_struct.input_src1 = IDP_MODULE_IMGDMA_RDMA0;
    crz_struct.mem_in_color_fmt1 = config_ir.src_color_fmt;

    if (config_ir.enable_src_clip == KAL_TRUE)
    {
        config_ir.image_clip_width = (config_ir.src_clip_right - config_ir.src_clip_left + 1);
        config_ir.image_clip_height = (config_ir.src_clip_bottom - config_ir.src_clip_top + 1);
    }
    else
    {
        config_ir.image_clip_width = config_ir.src_width;
        config_ir.image_clip_height = config_ir.src_height;
    }

    // Input sizes configs
    if ((0 == config_ir.image_clip_width) &&
        (0 == config_ir.image_clip_height))
    {
        crz_struct.src_width = config_ir.src_width;
        crz_struct.src_height = config_ir.src_height;
    }
    else
    {
        if (config_ir.image_clip_width > config_ir.src_width)
        {
            ASSERT(0);
            //return KAL_FALSE;
        }
        if (config_ir.image_clip_height > config_ir.src_height)
        {
            ASSERT(0);
            //return KAL_FALSE;
        }

        if (0 == (config_ir.image_clip_width & 0x01))
        {
            crz_struct.src_width = config_ir.image_clip_width;
        }
        else
        {
            crz_struct.src_width = config_ir.image_clip_width + 1;
        }

        if (0 == (config_ir.image_clip_height & 0x01))
        {
            crz_struct.src_height = config_ir.image_clip_height;
        }
        else
        {
            crz_struct.src_height = config_ir.image_clip_height + 1;
        }
    }

    // Output sizes configs
    crz_struct.tar_width = config_ir.target_width;
    crz_struct.tar_height = config_ir.target_height;

    if (0 != (crz_struct.tar_width & 0x1) && (config_ir.rot_angle == IMG_ROT_ANGLE_0))
    {
        ASSERT(0);
        //return KAL_FALSE;
    }
    if (0 != (crz_struct.tar_height & 0x1) && (config_ir.rot_angle == IMG_MIRROR_ROT_ANGLE_90))
    {
        ASSERT(0);
        //return KAL_FALSE;
    }

    // Source clip color is MM_IMAGE_COLOR_FORMAT_YUV420, y and uv offset need re-cauculate
    crz_struct.clip_en = config_ir.enable_src_clip; //only memory input valid
    crz_struct.org_width = config_ir.src_width; //only memory input valid

    idp_scen_ir_sm_y_offset = (config_ir.src_width * config_ir.src_clip_top) + config_ir.src_clip_left;
    idp_scen_ir_sm_uv_offset = (config_ir.src_width * (config_ir.src_clip_top >> 2)) + (config_ir.src_clip_left >> 1);


    // Target clip, change to source clip
    // Re-calculate src_width or src_height, and idp_scen_ir_sm_offset
    if (config_ir.target_clip == KAL_TRUE)
    {
        kal_uint32 h_ratio, v_ratio;
        kal_uint16 clip_w, clip_h, offset_x = 0, offset_y = 0;

        clip_w = config_ir.target_clip_right - config_ir.target_clip_left + 1;
        clip_h = config_ir.target_clip_bottom - config_ir.target_clip_top + 1;

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
            offset_y = (config_ir.image_clip_height - crz_struct.src_height) >> 1;

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

            offset_x = (config_ir.image_clip_width - crz_struct.src_width) >> 1;
            offset_y = 0;

            // re-cauculate offset_x to 2x offset allignment
            if ((offset_x & 0x1) == 1)
            {
                offset_x--;
            }
        }
        offset_x += config_ir.src_clip_left;
        offset_y += config_ir.src_clip_top;        

        // Source color is MM_IMAGE_COLOR_FORMAT_YUV420, y and uv offset need re-cauculate
        idp_scen_ir_sm_y_offset = (config_ir.src_width * offset_y) + offset_x;
        idp_scen_ir_sm_uv_offset = (config_ir.src_width * (offset_y >> 2)) + (offset_x >> 1);

        crz_struct.clip_en = KAL_TRUE;
    }

    // Config source address
    crz_struct.src_buff_y_addr = config_ir.src_image_address + idp_scen_ir_sm_y_offset;
    crz_struct.src_buff_u_addr = config_ir.src_image_u_address + idp_scen_ir_sm_uv_offset;
    crz_struct.src_buff_v_addr = config_ir.src_image_v_address + idp_scen_ir_sm_uv_offset;


    result = idp_resz_crz_config(owner->crz_key, &crz_struct, config_to_hardware);
    if (KAL_FALSE == result)
    {
        ASSERT(0);
        //return KAL_FALSE;
    }

    return KAL_TRUE;
}

static kal_bool
_idp_scen_ir_config_rotdma0(
    idp_owner_t * const owner,
    kal_bool const config_to_hardware)
{
    kal_bool result;

    if (KAL_TRUE == owner->have_config_imgdma_irt0)
    {
        return KAL_TRUE;
    }

    rotdma0_struct.rot_angle = config_ir.rot_angle;

    rotdma0_struct.yuv_color_fmt = config_ir.dest_color_fmt;
    rotdma0_struct.y_dest_start_addr = config_ir.dest_image_address;

    rotdma0_struct.src_width = crz_struct.tar_width;
    rotdma0_struct.src_height = crz_struct.tar_height;

    rotdma0_struct.pitch_enable = config_ir.enable_pitch;
    rotdma0_struct.pitch_bytes = (config_ir.bg_image_width) << 1;
    if (KAL_TRUE == rotdma0_struct.pitch_enable)
    {
        if (0x1 == (config_ir.bg_image_width & 0x1))
        {
            // pitch width 2x limitation
            ASSERT(0);
            //return KAL_FALSE;
        }
    }

    rotdma0_struct.fend_intr_en = KAL_TRUE;
    rotdma0_struct.fend_intr_cb = _idp_scen_ir__lisr_rotdma0__frame_done;

    rotdma0_struct.bus_control_threshold = ROTDMA_BUS_CONTROL_THRESHOLD;

    if (KAL_FALSE == rotdma_check_size_limitation(rotdma0_struct.src_width,
                                                  rotdma0_struct.src_height,
                                                  config_ir.dest_color_fmt,
                                                  rotdma0_struct.rot_angle))
    {
        ASSERT(0);
        //return KAL_FALSE;
    }

    result = idp_imgdma_rotdma0_config(owner->irt0_key, &rotdma0_struct, config_to_hardware);
    if (KAL_FALSE == result)
    {
        ASSERT(0);
        //return KAL_FALSE;
    }

    owner->have_config_imgdma_irt0 = KAL_TRUE;

    return KAL_TRUE;
}

#endif  // #if defined(__MTK_TARGET__)

/****************************************************************************
* local function bodies -- IDP scenario hook function bodies
****************************************************************************/
static void
idp_image_resize_init_config_hook(
  idp_owner_t * const owner)
{
#if defined(__MTK_TARGET__)

#if defined(IDP_HISR_SUPPORT)
    if (NULL == _idp_scen_image_resize_frame_done_hisr_handle)
    {
        _idp_scen_image_resize_frame_done_hisr_handle =
            idp_hisr_register(owner->key,
                              IDP_HISR_CB_TYPE_IMGDMA,
                              _idp_scen_ir__hisr_rotdma0__frame_done,
                              NULL);
    }
#endif

#if 0//defined(IDP_MM_COLOR_SUPPORT)
/* under construction !*/
#endif

    kal_mem_set(&config_ir, 0, sizeof(config_ir));
#endif
}

/****************************************************************************
* external function bodies -- IDP scenario hook function bodies
****************************************************************************/
kal_bool
idp_image_resize_close_hook(
    idp_owner_t * const owner)
{
#if defined(__MTK_TARGET__)

    idp_resz_crz_close(owner->crz_key, &crz_struct);
    idp_imgdma_rotdma0_close(owner->irt0_key, &rotdma0_struct);

#if defined(IDP_HISR_SUPPORT)
    idp_hisr_clear_all(owner->key, IDP_HISR_CB_TYPE_IMGDMA);

    _idp_scen_image_resize_frame_done_hisr_handle = NULL;
#endif

#if 0//defined(IDP_MM_COLOR_SUPPORT)
/* under construction !*/
/* under construction !*/
#endif

#endif //#if defined(__MTK_TARGET__)

    return KAL_TRUE;
}

kal_bool
idp_image_resize_read_user_config_fast_hook(
    idp_owner_t * const owner,
    kal_uint32 const para_type,
    kal_uint32 const para_value)
{
    return KAL_TRUE;
}

kal_bool
idp_image_resize_read_user_config_hook(
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

            case IDP_IMAGE_RESIZE_SRC_COLOR_FMT:
                config_ir.src_color_fmt = (MM_IMAGE_COLOR_FORMAT_ENUM) va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_SRC_IMAGE_ADDRESS:
                config_ir.src_image_address = va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_SRC_IMAGE_U_ADDRESS:
                config_ir.src_image_u_address = va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_SRC_IMAGE_V_ADDRESS:
                config_ir.src_image_v_address = va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_DEST_IMAGE_ADDRESS:
                config_ir.dest_image_address = va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_SRC_WIDTH:
                config_ir.src_width = va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_SRC_HEIGHT:
                config_ir.src_height = va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_TARGET_WIDTH:
                config_ir.target_width = va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_TARGET_HEIGHT:
                config_ir.target_height = va_arg(ap, kal_uint32);
                break;

            // Source clip
            case IDP_IMAGE_RESIZE_ENABLE_SRC_CLIP:
                config_ir.enable_src_clip = (kal_bool) va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_SRC_CLIP_LEFT:
                config_ir.src_clip_left = va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_SRC_CLIP_RIGHT:
                config_ir.src_clip_right = va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_SRC_CLIP_TOP:
                config_ir.src_clip_top = va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_SRC_CLIP_BOTTOM:
                config_ir.src_clip_bottom = va_arg(ap, kal_uint32);
                break;

            // Target clip
            case IDP_IMAGE_RESIZE_ENABLE_CLIP:
                config_ir.target_clip = (kal_bool)va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_CLIP_LEFT:
                config_ir.target_clip_left = va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_CLIP_RIGHT:
                config_ir.target_clip_right = va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_CLIP_TOP:
                config_ir.target_clip_top = va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_CLIP_BOTTOM:
                config_ir.target_clip_bottom = va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_DEST_COLOR_FMT: //UVYV422 only
                config_ir.dest_color_fmt = (MM_IMAGE_COLOR_FORMAT_ENUM) va_arg(ap, kal_uint32);
                ASSERT(config_ir.dest_color_fmt == MM_IMAGE_COLOR_FORMAT_PACKET_UYVY422);
                break;

            case IDP_IMAGE_RESIZE_ENABLE_PITCH:
                config_ir.enable_pitch = (kal_bool) va_arg(ap, kal_uint32);
                break;

            case IDP_IMAGE_RESIZE_BG_IMAGE_WIDTH:
                config_ir.bg_image_width = va_arg(ap, kal_uint32);
                break;

            // Check format
            case IDP_IMAGE_RESIZE_ROT_ANGLE:
                config_ir.rot_angle = (img_rot_angle_enum_t) va_arg(ap, kal_uint32);

                if (!((IMG_ROT_ANGLE_0 == config_ir.rot_angle) ||
                    (IMG_MIRROR_ROT_ANGLE_90 == config_ir.rot_angle)))
                {
                    ASSERT(0);
                    //return KAL_FALSE;
                }
                break;

            case IDP_IMAGE_RESIZE_FRAME_DONE_CB:
                config_ir.frame_done_cbfunc = va_arg(ap, idp_hisr_intr_cb_t);
                break;

            case IDP_IMAGE_RESIZE_FRAME_DONE_CB_PARAM:
                config_ir.frame_done_cbparam = va_arg(ap, void*);
                break;

            case IDP_IMAGE_RESIZE_ENG_CONFIG:
                config_ir.end_config = (kal_bool) va_arg(ap, kal_uint32);
                break;

            // Not support
            case IDP_IMAGE_RESIZE_INTMEM_START_ADDRESS:
            case IDP_IMAGE_RESIZE_INTMEM_SIZE:
            case IDP_IMAGE_RESIZE_EXTMEM_START_ADDRESS:
            case IDP_IMAGE_RESIZE_EXTMEM_SIZE:
            case IDP_IMAGE_RESIZE_RESIZER_U_VALUE:
            case IDP_IMAGE_RESIZE_RESIZER_V_VALUE:
            default:
                va_arg(ap, kal_uint32);
                break;
        }
    }

    return KAL_TRUE;
}

kal_bool
idp_image_resize_query_hook(
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

            case IDP_IMAGE_RESIZE_QUERY_ERROR_CODE:
                {
                    idp_image_resize_error_code_t * const error_code_place =
                    va_arg(ap, idp_image_resize_error_code_t *);

                    if (error_code_place != NULL)
                    {
                        (*error_code_place) = IDP_IMAGE_RESIZE_NO_ERROR; //error_code
                    }
                }
                break;

            default:
                return KAL_FALSE;
        }
    }

    return KAL_TRUE;
}

kal_bool
idp_image_resize_config_hook(
  idp_owner_t * const owner,
  kal_bool const config_to_hardware)
{
    kal_bool result = KAL_TRUE;

#if defined(__MTK_TARGET__)

    if (config_ir.end_config == KAL_FALSE)
    {
        return KAL_TRUE;
    }

    result = _idp_scen_ir_config_crz(owner, config_to_hardware);
    if (KAL_FALSE == result)
    {
        return KAL_FALSE;
    }

    result = _idp_scen_ir_config_rotdma0(owner, config_to_hardware);
    if (KAL_FALSE == result)
    {
        return KAL_FALSE;
    }

  #if 0//defined(IDP_MM_COLOR_SUPPORT)
/* under construction !*/
  #endif

#endif
    return result;
}


static hook_collect_t hook_collect =
{
    idp_image_resize_init_config_hook,
    idp_common_open_hook,//idp_image_resize_open_hook,
    idp_image_resize_close_hook,
    idp_common_stop_hook,//idp_image_resize_stop_hook,
    idp_image_resize_read_user_config_hook,
    idp_image_resize_read_user_config_fast_hook,
    idp_dummy_hook3,//idp_image_resize_finish_read_user_config_hook,
    idp_dummy_hook,//idp_image_resize_hardware_setting_have_been_changed_hook,
    idp_image_resize_config_hook,
    idp_image_resize_query_hook,
    idp_dummy_hook,//idp_image_resize_start_intermedia_pipe_hook,
    idp_common_start_input_hook,//idp_image_resize_start_input_hook,
    idp_common_start_output_hook,//idp_image_resize_start_output_hook,
    idp_dummy_hook2,//idp_image_resize_compute_mem_for_each_hw_hook,
    idp_common_is_busy_hook,//idp_image_resize_is_busy_hook,
    idp_common_is_in_use_hook,//idp_image_resize_is_in_use_hook,
    idp_dummy_hook2,//idp_image_resize_clear_setting_diff_hook,
    idp_dummy_hook//idp_image_resize_is_setting_diff_is_ok_when_busy_hook
};







//========= API ===================================================================
static IdpCheckReentrant idp_image_resize_check_reentrant = {KAL_NILTASK_ID, IDP_CALL_BY_HISR, IDP_CHECK_REENTRANT_PREV_OPEN, KAL_FALSE};

kal_bool
idp_image_resize_open_real(
    kal_uint32 * const key,
    char const * const filename,
    kal_uint32 const lineno)
{
    return idp_scenario_open(key,
                             &idp_image_resize_check_reentrant,
                             IDP_TRACED_API_image_resize_OPEN,
                             IDP_SCENARIO_image_resize,
                             &hook_collect);
}

kal_bool
idp_image_resize_is_in_use(void)
{
    return idp_scenario_is_in_use(&idp_image_resize_check_reentrant,
                                  IDP_TRACED_API_image_resize_IS_IN_USE,
                                  &hook_collect);
}

kal_bool
idp_image_resize_close(
    kal_uint32 const key)
{
    return idp_scenario_close(key,
                              &idp_image_resize_check_reentrant,
                              IDP_TRACED_API_image_resize_CLOSE,
                              &hook_collect);
}

kal_bool
idp_image_resize_stop(
    kal_uint32 const key)
{
    return idp_scenario_stop(key,
                             &idp_image_resize_check_reentrant,
                             IDP_TRACED_API_image_resize_STOP,
                             &hook_collect);
}

kal_bool
idp_image_resize_start_intermedia_pipe(
    kal_uint32 const key)
{
    return idp_scenario_start_intermedia_pipe(key,
                                              &idp_image_resize_check_reentrant,
                                              IDP_TRACED_API_image_resize_START_INTERMEDIA_PIPE,
                                              &hook_collect);
}

kal_bool
idp_image_resize_start_input(
    kal_uint32 const key)
{
    return idp_scenario_start_input(key,
                                    &idp_image_resize_check_reentrant,
                                    IDP_TRACED_API_image_resize_START_INPUT,
                                    &hook_collect);
}

kal_bool
idp_image_resize_start_output(
    kal_uint32 const key)
{
    return idp_scenario_start_output(key,
                                     &idp_image_resize_check_reentrant,
                                     IDP_TRACED_API_image_resize_START_OUTPUT,
                                     &hook_collect);
}

kal_bool
idp_image_resize_start_all(
    kal_uint32 const key)
{
    return idp_scenario_start_all(key,
                                  &idp_image_resize_check_reentrant,
                                  IDP_TRACED_API_image_resize_START_ALL,
                                  &hook_collect);
}

kal_bool
idp_image_resize_is_busy(
    kal_uint32 const key,
    kal_bool * const busy)
{
    return idp_scenario_is_busy(key,
                                busy,
                                IDP_TRACED_API_image_resize_IS_BUSY,
                                &hook_collect);
}

kal_bool
idp_image_resize_config_fast(
    kal_uint32 const key,
    kal_uint32 const para_type,
    kal_uint32 const para_value)
{
    return idp_scenario_config_fast(key,
                                    para_type,
                                    para_value,
                                    IDP_TRACED_API_image_resize_CONFIG_FAST,
                                    &hook_collect);
}

kal_bool
idp_image_resize_config(
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
                                 &idp_image_resize_check_reentrant,
                                 IDP_TRACED_API_image_resize_CONFIG,
                                 &hook_collect,
                                 ap);
    va_end(ap);
    return result;
}

kal_bool
idp_image_resize_configurable(
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
                                       &idp_image_resize_check_reentrant,
                                       IDP_TRACED_API_image_resize_CONFIGURABLE,
                                       &hook_collect,
                                       ap);
    va_end(ap);
    return result;
}

kal_bool
idp_image_resize_query(
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
                                &idp_image_resize_check_reentrant,
                                IDP_TRACED_API_image_resize_QUERY,
                                &hook_collect,
                                ap);
    va_end(ap);
    return result;
}

kal_bool idp_image_resize_config_and_start(
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
                                           &idp_image_resize_check_reentrant,
                                           IDP_TRACED_API_image_resize_CONFIG_AND_START,
                                           &hook_collect,
                                           ap);
    va_end(ap);
    return result;
}

#endif  // #if defined(__MULTIPLE_ANGLE_VIEW_SUPPORT__)
#endif  // #if defined(MT6250) || defined(MT6260)



