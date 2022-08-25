/*****************************************************************************
 * Filename:
 * ---------
 * custom_video_enc_setting_matv_mjpeg.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines the frame rate table for MATV.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/
#ifndef VIDEO_RECORDER_SETTING_MATV_MJPEG_H
#define VIDEO_RECORDER_SETTING_MATV_MJPEG_H


/// __ATV_RECORD_SUPPORT__ is a global option.
#ifdef __ATV_RECORD_SUPPORT__


///#include "custom_video_enc_types.h"
#include "custom_video_enc_if.h"
#include "custom_video_enc_types_matv_mjpeg.h"


#if defined(MT6236) || defined(MT6236B) || defined(MT6255)

static const VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T _rMatvMjpegNTSCFrameRateTable[] =
{
    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {150, 75, 150, 75, 1843200}
    },

    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {150, 75, 150, 75, 921600}
    }
};

static const VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T _rMatvMjpegPALFrameRateTable[] =
{
    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {125, 75, 125, 75, 1536000}
    },

    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {125, 75, 125, 75, 768000}
    }
};

#elif defined(MT6253)

static const VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T _rMatvMjpegNTSCFrameRateTable[] =
{
    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {200, 100, 100, 50, 614400}
    },

    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {300, 150, 150, 72, 304128}
    }
};

static const VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T _rMatvMjpegPALFrameRateTable[] =
{
    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {200, 100, 83, 50, 509952}
    },

    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {250, 150, 125, 75, 253440}
    }
};

#elif defined(MT6252) || defined(MT6252H)

static const VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T _rMatvMjpegNTSCFrameRateTable[] =
{
    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {150, 100, 75, 50, 460800}
    },

    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {200, 100, 100, 50, 202752}
    }
};

static const VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T _rMatvMjpegPALFrameRateTable[] =
{
    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {125, 75, 63, 50, 384000}
    },

    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {200, 100, 83, 50, 168284}
    }
};

#elif defined(MT6235) || defined(MT6235B)

static const VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T _rMatvMjpegNTSCFrameRateTable[] =
{
    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {300, 150, 150, 75, 921600}
    },

    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {300, 150, 150, 75, 304128}
    }
};

static const VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T _rMatvMjpegPALFrameRateTable[] =
{
    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {250, 150, 125, 75, 768000}
    },

    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {250, 150, 125, 75, 253440}
    }
};

#elif defined(MT6256)

static const VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T _rMatvMjpegNTSCFrameRateTable[] =
{
    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {300, 150, 300, 150, 3686400}
    },

    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {300, 150, 300, 150, 1843200}
    }
};

static const VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T _rMatvMjpegPALFrameRateTable[] =
{
    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {250, 125, 250, 125, 3072000}
    },

    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {250, 125, 250, 125, 1536000}
    }
};

#else

/******************************************************************************
* For unknown IC.
******************************************************************************/
static const VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T _rMatvMjpegNTSCFrameRateTable[] =
{
    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {150, 75, 150, 75, 304218}
    }
};

static const VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T _rMatvMjpegPALFrameRateTable[] =
{
    {
        /// Upper table begins.
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
        /// Lower table begins.
        {150, 75, 150, 75, 304218}
    }
};

#endif  // MT6236


#endif  // __ATV_RECORD_SUPPORT__


#endif  // VIDEO_RECORDER_SETTING_MATV_H

