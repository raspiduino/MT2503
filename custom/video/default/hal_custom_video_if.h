/*****************************************************************************
 * Filename:
 * ---------
 * hal_custom_video_if.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for customization of video features
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __HAL_CUSTOM_VIDEO_IF_H__
#define __HAL_CUSTOM_VIDEO_IF_H__
#include "drv_features_video.h"
#include "video_codec_custom_type.h"

/******************************************************************************
*
*  Note that the definitions in this interface file should NOT be removed
*
******************************************************************************/


/******************************************************************************
* Settings of the buffer of video decoder
******************************************************************************/
//MPEG4 Decode
//#define MPEG4_DEC_CUSTOM_FRAME_SETTING_ENABLE
#ifdef MPEG4_DEC_CUSTOM_FRAME_SETTING_ENABLE
    #define MPEG4_CUSTOM_EXTRA_BUFFER_NUM_SP           (3)
    #define MPEG4_CUSTOM_MAX_NORMAL_MODE_RESOLUTION_SP (RESOLUTION_720x480)
    //#define MPEG4_CUSTOM_SUPPORT_RESOLUTION_1_TO_2_SP  (RESOLUTION_720x480)
    #define MPEG4_CUSTOM_SUPPORT_RESOLUTION_SP         (RESOLUTION_720x480)
    #define MPEG4_CUSTOM_SUPPORT_RESOLUTION_1_TO_8_SP  (RESOLUTION_720x480)

    #ifdef __MP4_DEC_SW_SUPPORT_ASP__
        #define MPEG4_CUSTOM_EXTRA_BUFFER_NUM_ASP           (3)
        #define MPEG4_CUSTOM_MAX_NORMAL_MODE_RESOLUTION_ASP (RESOLUTION_720x480)
        //#define MPEG4_CUSTOM_SUPPORT_RESOLUTION_1_TO_2_ASP  (RESOLUTION_720x480)
        #define MPEG4_CUSTOM_SUPPORT_RESOLUTION_ASP         (RESOLUTION_720x480)
        #define MPEG4_CUSTOM_SUPPORT_RESOLUTION_1_TO_8_ASP  (RESOLUTION_720x480)
    #endif

#endif /* MPEG4_DEC_CUSTOM_FRAME_SETTING_ENABLE */

//H264 Decode
//#define H264_DEC_CUSTOM_FRAME_SETTING_ENABLE
#ifdef H264_DEC_CUSTOM_FRAME_SETTING_ENABLE
    #define H264_CUSTOM_EXTRA_BUFFER_NUM_BP            (6)
    #define H264_CUSTOM_SUPPORT_RESOLUTION_BP          (RESOLUTION_848x480)
    #define H264_CUSTOM_MAX_NORMAL_MODE_RESOLUTION_BP  (RESOLUTION_848x480)
    #define H264_CUSTOM_DECODER_LEVEL_BP               (Level_22)

    #ifdef __H264_DEC_SW_SUPPORT_MAINHIGH__
        #define H264_CUSTOM_EXTRA_BUFFER_NUM_MPHP            (6)
        #define H264_CUSTOM_SUPPORT_RESOLUTION_MPHP          (RESOLUTION_848x480)
        #define H264_CUSTOM_MAX_NORMAL_MODE_RESOLUTION_MPHP  (RESOLUTION_848x480)
        #define H264_CUSTOM_DECODER_LEVEL_MPHP               (Level_22)
    #endif

#endif /* H264_DEC_CUSTOM_FRAME_SETTING_ENABLE */

//RM Decode
//#define RV_DEC_CUSTOM_FRAME_SETTING_ENABLE
#ifdef RV_DEC_CUSTOM_FRAME_SETTING_ENABLE
    #define RV_CUSTOM_EXTRA_BUFFER_NUM            (0)
    #define RV_CUSTOM_SUPPORT_RESOLUTION          (RESOLUTION_720x576)
    #define RV_CUSTOM_MAX_NORMAL_MODE_RESOLUTION  (RESOLUTION_640x480)
#endif /* RV_DEC_CUSTOM_FRAME_SETTING_ENABLE */

//Motion Jpeg Decode
//#define MJPEG_DEC_CUSTOM_FRAME_SETTING_ENABLE
#ifdef MJPEG_DEC_CUSTOM_FRAME_SETTING_ENABLE
    #define MJPEG_CUSTOM_EXTRA_BUFFER_NUM            (1)
    #define MJPEG_CUSTOM_SUPPORT_RESOLUTION          (RESOLUTION_352x288)
    #define MJPEG_CUSTOM_MAX_QTY_MODE_RESOLUTION  (RESOLUTION_352x288)
    #define MJPEG_CUSTOM_MAX_NORMAL_MODE_RESOLUTION  (RESOLUTION_352x288)
#endif /* MJPEG_DEC_CUSTOM_FRAME_SETTING_ENABLE */

//VP8 Decode
//#define VP8_DEC_CUSTOM_FRAME_SETTING_ENABLE
#ifdef VP8_DEC_CUSTOM_FRAME_SETTING_ENABLE
    #define VP8_CUSTOM_EXTRA_BUFFER_NUM            (0)
    #define VP8_CUSTOM_SUPPORT_RESOLUTION          (RESOLUTION_720x576)
    #define VP8_CUSTOM_MAX_NORMAL_MODE_RESOLUTION  (RESOLUTION_640x480)
#endif /* VP8_DEC_CUSTOM_FRAME_SETTING_ENABLE */

/**********************************************************************************
* Settings of the buffer of video encoder
*
* Explanation
* 1. ~EXTRA_YUV_NUM: Additional frame buffer for video encoder (Unit: frame)
* 2. ~BIT_BUFFER_SIZE: The size of bitstream buffer (Unit: Byte)
* 3. ~SUPPORT_RESOLUTION: The maximum resolution supporter  (Unit: pixel x pixel)
**********************************************************************************/
//MPEG4 Encode
//#define MPEG4_ENC_CUSTOM_FRAME_SETTING_ENABLE
#ifdef MPEG4_ENC_CUSTOM_FRAME_SETTING_ENABLE
    #define MPEG4_ENC_CUSTOM_EXTRA_YUV_FRAME_NUM       (0)
    #define MPEG4_ENC_CUSTOM_BIT_BUFFER_SIZE           (262144)
    #define MPEG4_ENC_CUSTOM_SUPPORT_RESOLUTION        (RESOLUTION_800x480)
#endif /* MPEG4_ENC_CUSTOM_FRAME_SETTING_ENABLE */

//MJPEG Encode
//#define MJPEG_ENC_CUSTOM_FRAME_SETTING_ENABLE
#ifdef MJPEG_ENC_CUSTOM_FRAME_SETTING_ENABLE
    #define MJPEG_ENC_CUSTOM_EXTRA_YUV_FRAME_NUM       (0)
    #define MJPEG_ENC_CUSTOM_BIT_BUFFER_SIZE           (262144)
    #define MJPEG_ENC_CUSTOM_SUPPORT_RESOLUTION        (RESOLUTION_176x144)
#endif /* MJPEG_ENC_CUSTOM_FRAME_SETTING_ENABLE */

//H264 Encode
//#define H264_ENC_CUSTOM_FRAME_SETTING_ENABLE
#ifdef H264_ENC_CUSTOM_FRAME_SETTING_ENABLE
    #define H264_ENC_CUSTOM_EXTRA_YUV_FRAME_NUM       (0)
    #define H264_ENC_CUSTOM_BIT_BUFFER_SIZE           (262144)
    #define H264_ENC_CUSTOM_SUPPORT_RESOLUTION        (RESOLUTION_480x320)
#endif /* H264_ENC_CUSTOM_FRAME_SETTING_ENABLE */

//MPEG4 HW Encode
//#define MPEG4_HW_ENC_CUSTOM_FRAME_SETTING_ENABLE
#ifdef MPEG4_HW_ENC_CUSTOM_FRAME_SETTING_ENABLE
    #define MPEG4_HW_ENC_CUSTOM_EXTRA_YUV_FRAME_NUM       (0)
    #define MPEG4_HW_ENC_CUSTOM_BIT_BUFFER_SIZE           (262144)
#endif /* MPEG4_HW_ENC_CUSTOM_FRAME_SETTING_ENABLE */

//MJPEG HW Encode (directly coupled)
// Management of multiple fixed-sized bitstream buffers are utilized for
// MJPG HW Encode
//#define MJPEG_HW_ENC_CUSTOM_FRAME_SETTING_ENABLE
#ifdef MJPEG_HW_ENC_CUSTOM_FRAME_SETTING_ENABLE
    // This is the extra size of each bitstream buffer
    #define MJPEG_HW_ENC_CUSTOM_EXTRA_BITSTREAM                 (0)
    // This is the extra number of the bitstream buffer
    #define MJPEG_HW_ENC_CUSTOM_EXTRA_BITSTREAM_BUFFER_NUM      (1)
#endif /* MJPEG_HW_ENC_CUSTOM_FRAME_SETTING_ENABLE */

/******************************************************************************
* Settings of Muxer
******************************************************************************/
// MP4 muxer
//#define ENABLE_MP4_MUXER_CUSTOM_SETTING
#ifdef ENABLE_MP4_MUXER_CUSTOM_SETTING
    #define CUSTOM_MP4_STTS_ARRAY_SIZE_IN_BYTE     (8096)
    #define CUSTOM_MP4_STSZ_ARRAY_SIZE_IN_BYTE     (8096)
    #define CUSTOM_MP4_STCO_ARRAY_SIZE_IN_BYTE     (8096)
    #define CUSTOM_MP4_STSS_ARRAY_SIZE_IN_BYTE     (8096)
#endif //ENABLE_MP4_MUXER_CUSTOM_SETTING

// AVI muxer
//#define ENABLE_AVI_MUXER_CUSTOM_SETTING
#ifdef ENABLE_AVI_MUXER_CUSTOM_SETTING
    #define CUSTOM_AVI_ONE_DATA_BUFF_SIZE       (64*1024)
    #define CUSTOM_AVI_DATA_BUFF_EXTRA_NUM      (0)
    #define CUSTOM_AVI_ONE_IDX_BUFF_SIZE        (4*1024)
    #define CUSTOM_AVI_IDX_BUFF_EXTRA_NUM       (0)
#endif //ENABLE_AVI_MUXER_CUSTOM_SETTING

/******************************************************************************
* Setting of rate control (6268 only)
******************************************************************************/
// The interval between intra frames (Unit: second)
#define I_FRAME_REFRESH_RATE (2)

/******************************************************************************
* Setting of custom array table, for jump to i & lossy setting
******************************************************************************/
/* MP4 custom table */
//#define MP4_CUSTOM_TABLE_SETTING_ENABLE
#ifdef MP4_CUSTOM_TABLE_SETTING_ENABLE
    // MP4 custom arrary element
    //TABLE_SETTING_0   : the delta time of A/V to trigger jump to i event. delta time: millisecond
    //TABLE_SETTING_1   : the delta time of A/V to trigger stop audio and re-sync A/V event. delta time: millisecond
    //TABLE_SETTING_2   : the delta time to find the jumping target. delta time: millisecond
    #define MP4_CUSTOM_TABLE_SETTING_0       (500)
    #define MP4_CUSTOM_TABLE_SETTING_1       (3000)
    #define MP4_CUSTOM_TABLE_SETTING_2       (400)
    #define MP4_CUSTOM_TABLE_SETTING_3       (2000)

#endif /* MP4_CUSTOM_TABLE_SETTING_ENABLE */

/* RM custom table */
//#define RM_CUSTOM_TABLE_SETTING_ENABLE
#ifdef RM_CUSTOM_TABLE_SETTING_ENABLE
    // RM custom arrary element
    //TABLE_SETTING_0   : the delta time of A/V to trigger jump to i event. delta time: millisecond
    //TABLE_SETTING_1   : the delta time of A/V to trigger stop audio and re-sync A/V event. delta time: millisecond
    //TABLE_SETTING_2   : the delta time to find the jumping target. delta time: millisecond
    #define RM_CUSTOM_TABLE_SETTING_0       (30)
    #define RM_CUSTOM_TABLE_SETTING_1       (10000)
    #define RM_CUSTOM_TABLE_SETTING_2       (400)
    #define RM_CUSTOM_TABLE_SETTING_3       (2000)

#endif /* RM_CUSTOM_TABLE_SETTING_ENABLE */

/* H264 custom table */
//#define H264_CUSTOM_TABLE_SETTING_ENABLE
#ifdef H264_CUSTOM_TABLE_SETTING_ENABLE
    // H264 custom arrary element
    //TABLE_SETTING_0   : the delta time of A/V to trigger jump to i event. delta time: millisecond
    //TABLE_SETTING_1   : the delta time of A/V to trigger stop audio and re-sync A/V event. delta time: millisecond
    //TABLE_SETTING_2   : the delta time to find the jumping target. delta time: millisecond
    #define H264_CUSTOM_TABLE_SETTING_0       (500)
    #define H264_CUSTOM_TABLE_SETTING_1       (3000)
    #define H264_CUSTOM_TABLE_SETTING_2       (400)
    #define H264_CUSTOM_TABLE_SETTING_3       (2000)

#endif /* H264_CUSTOM_TABLE_SETTING_ENABLE */

/* VP8 custom table */
//#define VP8_CUSTOM_TABLE_SETTING_ENABLE
#ifdef VP8_CUSTOM_TABLE_SETTING_ENABLE
    // VP8 custom arrary element
    //TABLE_SETTING_0   : the delta time of A/V to trigger jump to i event. delta time: millisecond
    //TABLE_SETTING_1   : the delta time of A/V to trigger stop audio and re-sync A/V event. delta time: millisecond
    //TABLE_SETTING_2   : the delta time to find the jumping target. delta time: millisecond
    #define VP8_CUSTOM_TABLE_SETTING_0       (500)
    #define VP8_CUSTOM_TABLE_SETTING_1       (3000)
    #define VP8_CUSTOM_TABLE_SETTING_2       (400)
    #define VP8_CUSTOM_TABLE_SETTING_3       (2000)

#endif /* VP8_CUSTOM_TABLE_SETTING_ENABLE */

/******************************************************************************
* Setting of the maximum numbers of subtitle track
******************************************************************************/
//#define CUSTOMIZE_MAX_SUBTITLE_TRACK_NUMBER
#ifdef CUSTOMIZE_MAX_SUBTITLE_TRACK_NUMBER
    #define CUSTOM_SUBTITLE_TRACK_NUMBER 5  //Can be ranged from [1:16]
#endif

/* Video Clipper custom table */
//#define ENABLE_VIDEO_CLIPPER_CUSTOM_SETTING
#ifdef ENABLE_VIDEO_CLIPPER_CUSTOM_SETTING
    #define CUSTOM_MPLVC_ONE_VIDEO_BUFFER_SIZE (512 * 1024)
    #define CUSTOM_MPLVC_ONE_AUDIO_BUFFER_SIZE (32 * 1024)
#endif /* ENABLE_VIDEO_CLIPPER_CUSTOM_SETTING */

#endif // __HAL_CUSTOM_VIDEO_IF_H__

