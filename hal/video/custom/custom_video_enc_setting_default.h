/*****************************************************************************
 * Filename:
 * ---------
 * custom_video_enc_setting_default.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines the default frame rate table for various applications.
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
 * removed!
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
#ifndef VIDEO_RECORDER_SETTING_DEFAULT_H
#define VIDEO_RECORDER_SETTING_DEFAULT_H



/******************************************************************************
* Always define a default frame rate table for MPEG-4 MATV video recorder.
******************************************************************************/
#ifdef __ATV_RECORD_SUPPORT__ 

#include "custom_video_enc_setting_matv.h"
#include "custom_video_enc_setting_matv_mjpeg.h"

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rDefaultMatvFrameRateTable[1] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_ALL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 1, 31, 30, 7, 450000, 256, 60}
    }
};

static const VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T _rDefaultMatvMjpegFrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_ALL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /* Lower table begins. */
        {150, 75, 150, 75, 304218}
    }
};

#endif

/******************************************************************************
* Always define a default frame rate table for MJPEG video recorder.
******************************************************************************/
#ifdef __AVI_ENC_SUPPORT__

#include "custom_video_enc_setting_mjpeg.h"

static const VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T _rDefaultMjpegFrameRateTable[1] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_ALL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /* Lower table begins. */
        {150, 75, 150, 75, 304218}
    }
};

#endif


/******************************************************************************
* Always define a default frame rate table for MPEG-4 video recorder.
******************************************************************************/
#ifdef __MPEG4_ENC_SUPPORT__ 

#include "custom_video_enc_setting_mpeg4.h"

static const VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T _rDefaultMpeg4FrameRateTable[1] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_ALL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
#if defined(MT6236)
        {150, 75, 150, 75, 10, 1, 31, 1, 1, 384000, 256, 60}
#elif defined(MT6261) || defined(MT6260) || defined(MT6235) || defined(MT6235B) || defined(MT6253) || defined(MT6252) || defined(MT6252H) // sensor frame rate doubles that of recorder
        {300, 150, 150, 75, 10, 1, 31, 1, 1, 384000, 256, 60}
#elif defined(MT6250) // sensor frame rate doubles that of recorder
        {300, 150, 150, 75, 10, 1, 31, 1, 14, 384000, 256, 60}
#elif defined(MT6276)
        {150, 75, 150, 75, 10, 1, 31, 15, 3, 384000, 256, 60}
#elif defined(MT6256)
        {150, 75, 150, 75, 10, 1, 31, 15, 12, 384000, 256, 60}
#else
        {150, 75, 150, 75, 10, 1, 31, 15, 1, 384000, 256, 60}
#endif
    }
};
#endif

/******************************************************************************
* Always define a default frame rate table for VT encoder.
******************************************************************************/
#ifdef __MEDIA_VT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/******************************************************************************
* Always define a default frame rate table for H264 video recorder.
******************************************************************************/
#ifdef __H264_ENC_SUPPORT__

#include "custom_video_enc_setting_h264.h"

static const VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T _rDefaultH264FrameRateTable[1] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_ALL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
#if defined(MT6276) || defined(MT6256)
        {300, 150, 300, 150, 128000, 30, 3, 0, 0, 0, 0, 0}
#else
        {300, 150, 300, 150, 128000, 30, 3, 0, 0, 0, 0, 0}
#endif        
    }
};
#endif

static const CUSTOM_VENC_USER_T _rVideoEncRecUserSupport[] =
{
CUSTOM_VENC_USER_UNKNOWN                              /* don't remove this line */
#if defined(__MPEG4_ENC_SUPPORT__) 
,CUSTOM_VENC_USER_REC_MPEG4
#endif
#if defined(__AVI_ENC_SUPPORT__)
,CUSTOM_VENC_USER_REC_MJPEG
#endif
#if defined(MT6276) || defined(MT6256) || defined(MT6255)
#if defined(__H264_ENC_SUPPORT__)
,CUSTOM_VENC_USER_REC_H264
#endif
#endif
};


#endif  // VIDEO_RECORDER_SETTING_DEFAULT_H

