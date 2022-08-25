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
 *    idp_val.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    Provide a set of API to utilize IDP HW for video playback related 
 *    scenarios. After 11A, this is mainly for intergation with ISDB-T 
 *    (one of DTV standards).
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
 * 09 30 2011 ct.fang
 * removed!
 * .
 *
 * 04 11 2011 ct.fang
 * removed!
 * .
 *
 * 02 10 2011 ct.fang
 * removed!
 * .
 *
 * 12 17 2010 cm.huang
 * removed!
 * .
 *
 * 12 06 2010 cm.huang
 * removed!
 * .
 *
 * 12 03 2010 cm.huang
 * removed!
 * .
 *
 * 12 02 2010 cm.huang
 * removed!
 * .
 *
 * 12 02 2010 cm.huang
 * removed!
 * .
 *
 * 12 01 2010 cm.huang
 * removed!
 * .
 *
 * 12 01 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * 11 13 2010 cm.huang
 * NULL
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * 
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_val_h__
#define __idp_val_h__

/// \defgroup adaptation_layer
/// \ingroup idp
/// @{

/// \defgroup idp_val
/// \ingroup idp
/// @{

#include <drv_features.h>

#if defined(DRV_IDP_SUPPORT)

#include "kal_general_types.h"
#include "img_common_enum.h"

/***************************************************
 *                Video Processing
 ***************************************************/
/**
 *  \defgroup idp_val_vp
 *  \ingroup idp_val
 *  \brief This module defines the functionalities of IDP video process in idp_val.
 *  
 *  The input of this module is specific to video frame buffers, the 
 *  output is specific to display frame buffers, and the process includes 
 *  source pitch/clip, resize, contrast/brightness adjustment, rotation, 
 *  color format conversion, destination clip and pitch. \n
 *  This module does not control LCD, so the Display Driver will 
 *  not in auto mode. The user needs to bitblt the output buffers of 
 *  idp_val_vp via GDI API. \n
 *  The idp_val_vp_start() API is not a blocking API and it returns 
 *  once it set HW to work. \n
 *  This API set belongs to HAL and it is chip independent. \n
 * 
 *  \n
 *  The calling sequence is as follows: \n
 *  1. idp_val_vp_open() \n
 *  2. idp_val_vp_is_busy() \n
 *  3. idp_val_vp_config() \n
 *  4. idp_val_vp_config_src_buffer_addr() \n
 *  5. idp_val_vp_config_dst_buffer_addr() \n
 *  6. idp_val_vp_start() \n
 *  7. repeat step 2, 3, 4, 5 to display each video frame \n
 *  8. idp_val_vp_stop() \n
 *  9. idp_val_vp_close() \n
 *  \n
 *  Once configuration for video processing is set via idp_val_vp_config(), 
 *  those can be applied to each video frame set as input. Users only need to 
 *  invoke idp_val_vp_config_src_buffer_addr() and idp_val_vp_config_dst_buffer_addr() 
 *  for each frame if video frame buffers and display frame buffers are changed. 
 *  If callback function is set, once HW is done, idp_val_vp will callback to notify the user.
 *  \n
 *  MTK Chip supporting list: \n
 *  MT6236, MT6236B \n
 *  MT6276\n
 *  MT6256
 *  @{
 */

typedef struct 
{
    kal_uint32            ext_working_buffer_addr; /**< Working buffer adddress in external memory. optional */
    kal_uint32            ext_working_buffer_size; /**< Working buffer size in external memory. optional. */

    kal_uint32            video_src_width; /**< Video frame source width, including dummy columns. */
    kal_uint32            video_src_height; /**< Video frame source height, including dummy rows. */
    
    kal_uint32            src_color_format; /**< ENUM defined in img_color_fmt_rgb_enum_t or img_color_fmt_yuv_enum_t, usually IMG_COLOR_FMT_YUV420. */

    kal_uint32            src_clip_left; /**< [0, video_src_width - 1] */
    kal_uint32            src_clip_right; /**< [src_clip_left, video_src_width - 1] */
    kal_uint32            src_clip_top; /**< [0, video_src_height - 1] */
    kal_uint32            src_clip_bottom; /**< [src_clip_bottom, video_src_height - 1] */

    kal_uint8             contrast_level; /**< Default 0x20 */
    kal_uint8             brightness_level; /**< Default 0x20 */

    kal_uint32            dst_width; /**< The target width before rotation. */
    kal_uint32            dst_height; /**< The target height before rotation. */

    kal_uint32            dst_clip_left; /**< dst clipping window after resize and before rotation, currently not in use, please set to 0. */
    kal_uint32            dst_clip_right; /**< dst clipping window after resize and before rotation, currently not in use, please set to (dst_width - 1). */
    kal_uint32            dst_clip_top; /**< dst clipping window after resize and before rotation, currently not in use, please set to 0. */
    kal_uint32            dst_clip_bottom; /**< dst clipping window after resize and before rotation, currently not in use, please set to (dst_height - 1). */

    img_rot_angle_enum_t  rotation_angle; /**< Specifies the rotation angle and flip. */

    kal_uint32            dst_color_format; /**< ENUM defined in img_color_fmt_rgb_enum_t or img_color_fmt_yuv_enum_t, usually IMG_COLOR_FMT_RGB565 or IMG_COLOR_FMT_PACKET_YUYV422. */
    
    kal_bool              pitch_enable; /**< enable pitch, then the dst addresses are the start address instead of frame buffer base addresses. */
    kal_uint32            pitch_width; /**< pitch width in pixel. */

    kal_bool              (*frame_done_cb)(void*); /**< frame done callback executed in HISR, please send ILM messages to your own task(s) for further handling. */
    void*                 frame_done_cb_param; /**< param you set and will be carried to you in callback function. NULL is OK. */
} idp_val_vp_param_t;

/**
 *  Open idp_val_vp for processing video frame buffers. Callers obtain a key for 
 *  following idp_val_vp API calls.
 * 
 *  \param [in,out] key Of type kal_uint32 * const. User must provide a 
 *                      pointer to a kal_uint32 for storing the key, which 
 *                      should be used in all the following API function calls.
 * 
 *  \return KAL_TRUE idp_val_vp is opened successfully.
 *  \return KAL_FALSE Otherwise. If KAL_FALSE is returned, key will be 0x0.
 * 
 *  \remark User must check if idp_val_vp is opened successfully to use the following API function calls.
 */
extern kal_bool 
idp_val_vp_open(
    kal_uint32 * const key);

/**
 *  This function close the idp_val_vp. This function must be invoked after 
 *  using idp_val_vp and all allocated resources including HW engines and 
 *  internal memory are released. If not called once finished using idp_val_vp, 
 *  other IDP paths may not be opened due to resources not released. 
 * 
 *  \param [in] key Of type kal_uint32 const. The key obtained after a 
 *                  successful call to idp_val_vp_open().
 * 
 *  \remark No idp_val_vp related functions except idp_val_vp_open() should be 
 *          invoked after this function is invoked.
 */
extern kal_bool
idp_val_vp_close(
    kal_uint32 const key);

/**
 *  This function commands idp_val_vp to start working based on the 
 *  configuration set before this function call. This is not a blocking call, 
 *  it returns immediately once it starts the HW.
 * 
 *  \param [in] key Of type kal_uint32 const. The key obtained after a 
 *                  successful call to idp_val_vp_open().
 *  
 *  \remark Callers should configure idp_val_vp correctly before invoking this 
 *          function.
 */
extern kal_bool
idp_val_vp_start(
    kal_uint32 const key);

/**
 *  This function commands idp_val_vp to stop working. This function may 
 *  waiting HW to fully stopped, please do not invoke this function in ISR.
 * 
 *  \param [in] key Of type kal_uint32 const. The key obtained after a 
 *              successful call to idp_val_vp_open().
 *  
 *  \remark Unless in error handling, callers are suggested to use 
 *          idp_val_vp_is_busy() to check if HW finishes rather than calling 
 *          this function to force HW to stop.
 */
extern kal_bool
idp_val_vp_stop(
    kal_uint32 const key);

/**
 *  Check if idp_val_vp is still busy processing the last video frame.
 * 
 *  \param [in] key Of type kal_uint32 const. The key obtained after a 
 *                  successful call to idp_val_vp_open().
 *  \param [out] busy Of type kal_bool * const. If this function returns 
 *                    KAL_TRUE, this output parameter will carry the boolean 
 *                    value to indicate if idp_val_vp is still busy.
 * 
 *  \return KAL_TRUE This function call works OK.
 *  \return KAL_FALSE Otherwise.
 * 
 *  \remark Users must check if return value is KAL_TRUE to use the busy output 
 *          parameter.
 */
extern kal_bool 
idp_val_vp_is_busy(
    kal_uint32 const key,
    kal_bool * const busy);

/**
 *  Configure idp_val_vp for processing video frames.
 * 
 *  \param [in] key Of type kal_uint32 const. The key obtained after a 
 *                  successful call to idp_val_vp_open().
 *  \param [in] param Type idp_val_vp_param_t*. The parameters about how to 
 *                    process the video frames.
 *  
 *  \return KAL_TRUE No error. Do any following steps before making sure this 
 *                   function returns KAL_TRUE!
 *  \return KAL_FALSE Otherwise.
 */
extern kal_bool 
idp_val_vp_config(
    kal_uint32 const key,
    idp_val_vp_param_t* param);

/** 
 *  This function sets the YUV420 video frame buffer base addresses for 
 *  processing. Once the idp_val_vp is set up OK with the previous calls to 
 *  idp_val_vp_config() and idp_val_vp_config_dst_buffer_addr(), each following 
 *  video frame can apply the same settings by just give new YUV420 frame 
 *  buffers to idp_val_vp.
 * 
 *  \param [in] key Of type kal_uint32 const. The key obtained after a 
 *                  successful call to idp_val_vp_open().
 *  \param [in] addr0 Y component start address of YUV420 video frame buffer. 
 *                    Must be at least 4x aligned non-cacheable memory.
 *  \param [in] addr1 U component start address of YUV420 video frame buffer. 
 *                    Must be at least 4x aligned non-cacheable memory.
 *  \param [in] addr2 V component start address of YUV420 video frame buffer. 
 *                    Must be at least 4x aligned non-cacheable memory.
 * 
 *  \return KAL_TRUE OK.
 *  \return KAL_FALSE Otherwise.
 * 
 *  \remark The YUV420 video frame buffer is of 4x4 block-based format output 
 *          by MTK HW video decoder on MT6268 but currently this API does not 
 *          support MT6268. It should be scan-line based for other MTK BB 
 *          projects such as MT6236 and MT6276.
 */
extern kal_bool 
idp_val_vp_config_src_buffer_addr(
    kal_uint32 const key,
    kal_uint32 addr0, 
    kal_uint32 addr1, 
    kal_uint32 addr2);

/** 
 *  This function sets the destination frame buffer "start" addresses. Here 
 *  start address is which idp_val_vp starts to write the output buffer. If 
 *  destination pitch is enabled, it is the pitch start address rather than 
 *  frame buffer base address. Once the idp_val_vp is set up OK with 
 *  idp_val_vp_config() and idp_val_vp_config_src_buffer_addr(), changing 
 *  destination frame buffer addresses can just invoke this function. If the 
 *  destination color format is single plane, e.g. RGB or UYVY, just use 
 *  parameter addr0. If the destination color format consists of three planes, 
 *  such as YUV420 planar format, uses addr0, addr1, and addr2 for Y, U, and V 
 *  plane separately.
 * 
 *  \param [in] key Of type kal_uint32 const. The key obtained after a 
 *                  successful call to idp_val_vp_open().
 *  \param [in] addr0 Start address of 1st component of destination frame 
 *                    buffer. Must be at least format-aligned and non-cacheable.
 *  \param [in] addr1 Start address of 2nd component of destination frame 
 *                    buffer. Must be at least format-aligned and non-cacheable.
 *  \param [in] addr2 Start address of 3rd component of destination frame 
 *                    buffer. Must be at least format-aligned and non-cacheable.
 * 
 *  \return KAL_TRUE OK.
 *  \return KAL_FALSE Otherwise.
 * 
 *  \remark If there is address alignment or cacheability issues, HW would hang.
 */
extern kal_bool 
idp_val_vp_config_dst_buffer_addr(
    kal_uint32 const key,
    kal_uint32 addr0, 
    kal_uint32 addr1, 
    kal_uint32 addr2);



/// @}
/// @}
/// @}

#endif  //#if defined(DRV_IDP_SUPPORT)

#endif  // #ifndef __idp_val_h__


