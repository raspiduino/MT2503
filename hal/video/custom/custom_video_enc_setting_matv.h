/*****************************************************************************
 * Filename:
 * ---------
 * custom_video_enc_setting_matv.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/

#ifndef VIDEO_RECORDER_SETTING_MATV_H
#define VIDEO_RECORDER_SETTING_MATV_H


/* __ATV_RECORD_SUPPORT__ is a global option. */
#ifdef __ATV_RECORD_SUPPORT__


#include "custom_video_enc_types.h"


/******************************************************************************
 										        Field Description

typedef struct
{
    CUSTOM_VENC_RESOLUTION_T eResolution;
    CUSTOM_VENC_QUALITY_T eQuality;
    CUSTOM_VENC_STORAGE_T eStorage;
    CUSTOM_VENC_CODEC_T eCodec;
} CUSTOM_VENC_UPPER_TABLE_T;

typedef struct
{
    kal_uint16 u2SensorFrameRate;
    kal_uint16 u2SensorNightFrameRate;
    kal_uint16 u2CodecFrameRate;
    kal_uint16 u2CodecNightFrameRate;

    kal_uint8 u1InitQ;
    kal_uint8 u1MinQp;
    kal_uint8 u1MaxQp;
    kal_uint16 u2IntraVopRate;
    kal_uint16 u2Algorithm;
    kal_uint32 u4BitRate;
    kal_uint32 u4RateHardLimit;
    kal_uint32 u4RateBalance;
} CUSTOM_VENC_MATV_MPEG4_LOWER_TABLE_T;

typedef struct
{
    CUSTOM_VENC_UPPER_TABLE_T rUpperTable;              /// rUpperTable is used by MED.
    CUSTOM_VENC_MATV_MPEG4_LOWER_TABLE_T rLowerTable;   /// rLowerTable is used by codec except for frame rate values which are also used by MED.
} VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T;

*******************************************************************************/

#if defined(MT6236)

#ifdef MT6921

/******************************************************************************
* MT6921
******************************************************************************/
static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvNTSCFrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {150, 75, 150, 75, 4, 4, 15, 1, 1,1950000, 256, 60}
    },
};

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvPALFrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {125, 75, 125, 75, 4, 4, 15, 1, 1,1950000, 256, 60}
    },
};

#else
/******************************************************************************
* MT6236
******************************************************************************/
static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvNTSCFrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {150, 75, 150, 75, 4, 4, 15, 1, 1, 3000000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {150, 75, 150, 75, 4, 4, 15, 1, 1,1950000, 256, 60}
    },
};

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvPALFrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {125, 75, 125, 75, 4, 4, 15, 1, 1, 3000000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {125, 75, 125, 75, 4, 4, 15, 1, 1,1950000, 256, 60}
    },
};
#endif

#elif defined(MT6253)

/******************************************************************************
* MT6253
******************************************************************************/
static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvNTSCFrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {200, 75, 100, 75, 4, 4, 15, 1, 1, 1300000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
#ifdef __CONTOUR_IMPROVEMENT_SUPPORT__
        {200, 75, 100, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
#else
        {300, 75, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
#endif
    },
};

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvPALFrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {166, 75, 83, 75, 4, 4, 15, 1, 1, 1300000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
#ifdef __CONTOUR_IMPROVEMENT_SUPPORT__
        {166, 75, 83,  75, 4, 4, 15, 1, 1, 1950000, 256, 60}
#else
        {250, 75, 125, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
#endif
    },
};

#elif defined(MT6252) || defined(MT6252H)

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvNTSCFrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {150, 75, 75, 75, 4, 4, 15, 1, 1, 1300000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {200, 75, 100, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },
};

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvPALFrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {125, 75, 63, 75, 4, 4, 15, 1, 1, 1300000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {166, 75, 83, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },
};

#elif defined(MT6261)

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvNTSCFrameRateTable[] =
{
#if defined(__MED_VIDEO_ULC__)  //ULC (ultra low cost) mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {200, 75, 100, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },
#else                           //NORMAL mode & SLIM mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {200, 75, 100, 75, 4, 4, 15, 1, 1, 1300000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {200, 75, 100, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },
#endif
};

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvPALFrameRateTable[] =
{
#if defined(__MED_VIDEO_ULC__)  //ULC (ultra low cost) mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {166, 75, 83, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },
#else                           //NORMAL mode & SLIM mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {166, 75, 83, 75, 4, 4, 15, 1, 1, 1300000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {166, 75, 83, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },
#endif
};

#elif defined(MT6260)

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvNTSCFrameRateTable[] =
{
#if defined(__MED_VIDEO_ULC__)  //ULC (ultra low cost) mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {300, 75, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },
#else                           //NORMAL mode & SLIM mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {300, 75, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {300, 75, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },
#endif
};

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvPALFrameRateTable[] =
{
#if defined(__MED_VIDEO_ULC__)  //ULC (ultra low cost) mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {250, 75, 125, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },
#else                           //NORMAL mode & SLIM mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {250, 75, 125, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {250, 75, 125, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },
#endif
};

#elif defined(MT6250)

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvNTSCFrameRateTable[] =
{
#if defined(__MED_VIDEO_ULC__)  //ULC (ultra low cost) mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {300, 75, 150, 75, 4, 4, 15, 1, 14, 1950000, 256, 60}
    },
#else                           //NORMAL mode & SLIM mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {300, 75, 150, 75, 4, 4, 15, 1, 14, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {300, 75, 150, 75, 4, 4, 15, 1, 14, 1950000, 256, 60}
    },
#endif
};

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvPALFrameRateTable[] =
{
#if defined(__MED_VIDEO_ULC__)  //ULC (ultra low cost) mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {250, 75, 125, 75, 4, 4, 15, 1, 14, 1950000, 256, 60}
    },
#else                           //NORMAL mode & SLIM mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {250, 75, 125, 75, 4, 4, 15, 1, 14, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {250, 75, 125, 75, 4, 4, 15, 1, 14, 1950000, 256, 60}
    },
#endif
};

#elif defined(MT6235) || defined(MT6235B)

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvNTSCFrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {300, 75, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {300, 75, 150, 75, 4, 4, 31, 15, 1, 384000, 256, 60}
    },
};

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvPALFrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {250, 75, 125, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {250, 75, 125, 75, 4, 4, 31, 15, 1, 384000, 256, 60}
    },
};

#elif defined(MT6268)

/******************************************************************************
* MT6268
******************************************************************************/

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvNTSCFrameRateTable[] =
    {
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 1, 31, 30,  10, 3000000, 512, 60}
    },
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 1, 31, 30, 10, 1500000, 512, 60}
    },
};

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvPALFrameRateTable[] =
    {
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {250, 150, 250, 150, 4, 1, 31, 30,  10, 3000000, 512, 60}
    },
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {250, 150, 250, 150, 4, 1, 31, 30, 10, 1500000, 512, 60}
    },
};

#elif defined(MT6256)

/******************************************************************************
* MT6256
******************************************************************************/
static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvNTSCFrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {300, 150, 300, 150, 10, 1, 31, 30,  11, 3000000, 512, 60}
    },
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {300, 150, 300, 150, 10, 1, 31, 30, 11, 1500000, 512, 60}
    },
};

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvPALFrameRateTable[] =
    {
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {250, 150, 250, 150, 10, 1, 31, 30,  11, 3000000, 512, 60}
    },
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {250, 150, 250, 150, 10, 1, 31, 30, 11, 1500000, 512, 60}
    },
};

#elif defined(MT6276)

/******************************************************************************
* MT6276
******************************************************************************/
static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvNTSCFrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 30,  10, 1500000, 512, 60}
    },
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {300, 150, 300, 150, 10, 1, 31, 30, 10, 1500000, 512, 60}
    },
};

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvPALFrameRateTable[] =
    {
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {250, 150, 125, 75, 10, 1, 31, 30,  10, 1500000, 512, 60}
    },
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {250, 150, 250, 150, 10, 1, 31, 30, 10, 1500000, 512, 60}
    },
};

#elif defined(MT6255)

/******************************************************************************
* MT6255
******************************************************************************/
static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvNTSCFrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {150, 75, 150, 75, 4, 4, 15, 1, 1, 3000000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {150, 75, 150, 75, 4, 4, 15, 1, 1,1950000, 256, 60}
    },
};

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvPALFrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {125, 75, 125, 75, 4, 4, 15, 1, 1, 3000000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {125, 75, 125, 75, 4, 4, 15, 1, 1,1950000, 256, 60}
    },
};

#else

/******************************************************************************
* For unknown IC.
******************************************************************************/
static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvNTSCFrameRateTable[] =
    {
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_ALL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 1, 31, 30, 1, 450000, 256, 60}
    }
};

static const VIDEO_ENC_MATV_MPEG4_FRAME_RATE_TABLE_T _rMatvPALFrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_ALL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 1, 31, 30, 1, 450000, 256, 60}
    }
};

#endif  // MT6236


#endif  // __ATV_RECORD_SUPPORT__


#endif  // VIDEO_RECORDER_SETTING_MATV_H

