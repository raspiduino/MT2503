/*****************************************************************************
 * Filename:
 * ---------
 * custom_video_enc_setting_mpeg4.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines the frame rate table for MPEG-4.
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

#ifndef VIDEO_RECORDER_SETTING_MPEG4_H
#define VIDEO_RECORDER_SETTING_MPEG4_H


/* __MPEG4_ENC_SUPPORT__ is a global option. */
#ifdef __MPEG4_ENC_SUPPORT__


#include "custom_video_enc_types.h"

/******************************************************************************
 										        Field Description


typedef struct
{
    CUSTOM_VENC_RESOLUTION_T  eResolution;
    CUSTOM_VENC_QUALITY_T     eQuality;
    CUSTOM_VENC_STORAGE_T     eStorage;
    CUSTOM_VENC_CODEC_T       eCodec;
    CUSTOM_VENC_ROTATE_T      eRotate;
} CUSTOM_VENC_REC_MPEG4_UPPER_TABLE_T;

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
} CUSTOM_VENC_REC_MPEG4_LOWER_TABLE_T;

typedef struct
{
    CUSTOM_VENC_REC_MPEG4_UPPER_TABLE_T     rUpperTable;              /// rUpperTable is used by MED.
    CUSTOM_VENC_REC_MPEG4_LOWER_TABLE_T     rLowerTable;    /// rLowerTable is used by codec except for frame rate values which are also used by MED.
} VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T;

*******************************************************************************/


#if defined(MT6236)

#ifdef MT6921

/******************************************************************************
* MT6921
******************************************************************************/
static const VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T _rMpeg4FrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 5, 2, 31, 15, 1, 750000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 5, 2, 31, 15, 1, 500000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 10, 1, 31, 15, 1, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 10, 1, 31, 30, 1, 96000, 256, 60}
    }
};
#else

/******************************************************************************
* MT6236
******************************************************************************/
static const VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T _rMpeg4FrameRateTable[] =
{
#ifdef CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
#ifdef __VIDEO_ENC_D1_SUPPORT__
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_720x480, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {75, 50, 75, 50, 4, 4, 15, 1, 1, 3500000, 2304, 60}
    },


    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 10, 1, 31, 15, 1, 750000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 10, 1, 31, 30, 1, 96000, 256, 60}
    }

#else
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {120, 75, 120, 75, 4, 4, 15, 1, 1, 3500000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 5, 2, 31, 15, 1, 750000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 10, 1, 31, 30, 1, 96000, 256, 60}
    }
#endif    
#else
#ifdef __VIDEO_ENC_D1_SUPPORT__
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_720x480, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {75, 50, 75, 50, 4, 4, 15, 1, 1, 3500000, 2304, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 5, 2, 31, 1, 1, 1500000, 1024, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 10, 1, 31, 15, 1, 750000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 10, 1, 31, 30, 1, 96000, 256, 60}
    }

//-----------------------------Rotation-----------------------------
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x720, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {75, 50, 75, 50, 4, 4, 15, 1, 1, 3500000, 2304, 60}
    },
#else
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {120, 75, 120, 75, 4, 4, 15, 1, 1, 3500000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 5, 2, 31, 15, 1, 750000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 10, 1, 31, 15, 1, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 10, 1, 31, 30, 1, 96000, 256, 60}
    },

//-----------------------------Rotation-----------------------------
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x480, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {120, 75, 120, 75, 4, 4, 15, 1, 1, 3500000, 768, 60}
    }
#endif
#endif
};
#endif

#elif defined(MT6255)     // provide Nokia style only

#if defined(MT6922) && !defined(NAND_SUPPORT)

/******************************************************************************
* MT6922
******************************************************************************/
#ifdef CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
static const VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T _rMpeg4FrameRateTable[] =
{
#ifdef __OP01__
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },
#else
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 5, 2, 31, 15, 1, 750000, 768, 60}
    },

#endif


    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 200, 150, 100,  10, 1, 31, 15, 1, 96000, 256, 60}
    }
};

#else
static const VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T _rMpeg4FrameRateTable[] =
{
#ifdef __OP01__
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 5, 1, 31, 15, 1, 384000, 256, 60}
    },
    
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 8, 1, 31, 15, 1, 256000, 256, 60}
    },    
#else
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 5, 2, 31, 15, 1, 750000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 5, 2, 31, 15, 1, 500000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 10, 1, 31, 15, 1, 384000, 256, 60}
    },
#endif


    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 10, 1, 31, 30, 1, 96000, 256, 60}
    }
};
#endif
#else
/******************************************************************************
* MT6255
******************************************************************************/
#ifndef CUSTOM_VENC_USE_REDUCED_SELECTION
#error "the table was setup in nokia style. please replace it"
#endif

#ifdef CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
static const VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T _rMpeg4FrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75,  4, 4, 15, 1, 1, 4375000, 768, 60}
    },
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 200, 150, 100,  10, 1, 31, 15, 1, 96000, 256, 60}
    }
};

#else

static const VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T _rMpeg4FrameRateTable[] =
{
	/***************************** MPEG-4 HVGA ******************************************/
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75,  4, 4, 15, 1, 1, 4375000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 200, 150, 5, 2, 31, 20, 1, 1000000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 1, 31, 30, 1, 750000, 256, 60}
    },


    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 200, 150, 100,  10, 1, 31, 15, 1, 64000, 256, 60}
    },
};
#endif
#endif



#elif defined(MT6253)

/******************************************************************************
* MT6253
******************************************************************************/
static const VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T _rMpeg4FrameRateTable[] =
{
#ifdef CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
#ifdef __CONTOUR_IMPROVEMENT_SUPPORT__
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {180, 150, 90, 75, 4, 4, 15, 1, 1, 1300000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 100, 75, 10, 1, 31, 30, 1, 170000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 100, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    }
#else    
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 100, 75, 4, 4, 15, 1, 1, 1300000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 30, 1, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    }
#endif
#else
#ifdef __CONTOUR_IMPROVEMENT_SUPPORT__
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {180, 150, 90, 75, 4, 4, 15, 1, 1, 1300000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 100, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 100, 75, 10, 1, 31, 30, 1, 170000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 100, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    },

//-----------------------------Rotation-----------------------------
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {180, 150, 90, 75, 4, 4, 15, 1, 1, 1300000, 256, 60}
    }
#else
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 100, 75, 4, 4, 15, 1, 1, 1300000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 30, 1, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    },

//-----------------------------Rotation-----------------------------
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 100, 75, 4, 4, 15, 1, 1, 1300000, 256, 60}
    }
#endif
#endif
};

#elif defined(MT6252) || defined(MT6252H)
/******************************************************************************
* MT6253
******************************************************************************/
static const VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T _rMpeg4FrameRateTable[] =
{
#ifdef CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 100, 75, 4, 4, 15, 1, 1, 1300000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {240, 150, 120, 75, 10, 4, 31, 12, 1, 200000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {240, 150, 120, 75, 10, 4, 31, 90, 1, 51200, 256, 60}
    },

#else	
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 100, 75, 4, 4, 15, 1, 1, 1300000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {240, 150, 120, 75, 4, 4, 15, 1, 1, 1560000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {240, 150, 120, 75, 10, 4, 31, 12, 1, 200000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {240, 150, 120, 75, 10, 4, 31, 90, 1, 51200, 256, 60}
    },

//-----------------------------Rotation-----------------------------
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 100, 75, 4, 4, 15, 1, 1, 1300000, 256, 60}
    },
#endif    
};

#elif defined(MT6261)     // provide Nokia style only
/******************************************************************************
* MT6261
******************************************************************************/
static const VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T _rMpeg4FrameRateTable[] =
{
#ifdef CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
#if defined(__MED_VIDEO_ULC__)      //ULC(ultra low cost) mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 15, 1, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    },
#elif defined(__MPEG4_ENC_SW_SLIM__)//SLIM mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    },
#else                               //NORMAL mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    },
#endif
#else  //CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
#if defined(__MED_VIDEO_ULC__)      //ULC(ultra low cost) mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 15, 1, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 15, 1, 256000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    },
#elif defined(__MPEG4_ENC_SW_SLIM__)//SLIM mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 15, 1, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    },

    //-----------------------------Rotation-----------------------------
    //Video live Wallpaper
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },
#else                               //NORMAL mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 15, 1, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    },

    //-----------------------------Rotation-----------------------------
    //Video live Wallpaper
#if defined(__MMI_MAINLCD_320X240__)
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },
#else //if defined(__MMI_MAINLCD_240X320__)
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },
#endif
#endif
#endif //CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
};

#elif defined(MT6260)     // provide Nokia style only
/******************************************************************************
* MT6260
******************************************************************************/
static const VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T _rMpeg4FrameRateTable[] =
{
#ifdef __STREAM_SERVER_SUPPORT__
	{
		/* Upper table begins. */
		{CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
		CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
		/* Lower table begins. */
		{300, 150, 150, 75, 4, 1, 31, 15, 1, 512000, 512, 60}
	},
	//a=fmtp:96 profile-level-id=3; config=000001b003000001b509000001000000012000844025a85020f0a21f\r\n\
	
	{
		/* Upper table begins. */
		{CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_NORMAL,
		CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
		/* Lower table begins. */
		{300, 150, 150, 75, 10, 1, 31, 15, 1, 384000, 256, 60}
	},
	//a=fmtp:96 profile-level-id=3; config=000001b003000001b509000001000000012000844025a85020f0a21f\r\n\
	
	{
		/* Upper table begins. */
		{CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
		CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
		/* Lower table begins. */
		{300, 150, 150, 75, 10, 1, 31, 15, 1, 384000, 256, 60}
	},
	//a=fmtp:96 profile-level-id=8; config=000001b008000001b509000001000000012000844025a82c2090a21f\r\n\
		
	{
		/* Upper table begins. */
		{CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
		CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
		/* Lower table begins. */
		{300, 150, 150, 75, 10, 1, 31, 15, 1, 256000, 256, 60}
	}
	//a=fmtp:96 profile-level-id=8; config=000001b008000001b509000001000000012000844025a82c2090a21f\r\n\
	
#else


#ifdef CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
#if defined(__MED_VIDEO_ULC__)      //ULC(ultra low cost) mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 15, 1, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    },
#elif defined(__MPEG4_ENC_SW_SLIM__)//SLIM mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    },
#else                               //NORMAL mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 4375000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 1, 31, 15, 1, 750000, 512, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    },
#endif
#else  //CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
#if defined(__MED_VIDEO_ULC__)      //ULC(ultra low cost) mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 15, 1, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 15, 1, 256000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    },
#elif defined(__MPEG4_ENC_SW_SLIM__)//SLIM mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 15, 1, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    },

    //-----------------------------Rotation-----------------------------
    //Video live Wallpaper
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },
#else                               //NORMAL mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 4375000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 1, 31, 15, 1, 750000, 512, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 15, 1, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    },

    //-----------------------------Rotation-----------------------------
    //Video live Wallpaper
#if defined(__MMI_MAINLCD_432X240__)
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_432x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 1, 31, 15, 1, 1012500, 512, 60}
    },
#elif defined(__MMI_MAINLCD_240X432__)
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_240x432, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 1, 31, 15, 1, 1012500, 512, 60}
    },
#elif defined(__MMI_MAINLCD_400X240__)
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_400x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 1, 31, 15, 1, 937500, 512, 60}
    },
#elif defined(__MMI_MAINLCD_240X400__)
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_240x400, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 1, 31, 15, 1, 937500, 512, 60}
    },
#elif defined(__MMI_MAINLCD_320X240__)
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },
#elif defined(__MMI_MAINLCD_240X320__)
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },
#else
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x480, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 4375000, 768, 60}
    },
#endif
#endif
#endif //CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
#endif //__STREAM_SERVER_SUPPORT__ 
};

#elif defined(MT6250)     // provide Nokia style only
/******************************************************************************
* MT6250
******************************************************************************/
static const VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T _rMpeg4FrameRateTable[] =
{
#ifdef CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
#if defined(__MED_VIDEO_ULC__)      //ULC(ultra low cost) mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 14, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 15, 14, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 14, 96000, 256, 60}
    },
#elif defined(__MPEG4_ENC_SW_SLIM__)//SLIM mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 14, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 14, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 14, 96000, 256, 60}
    },
#else                               //NORMAL mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {240, 120, 120, 60, 4, 4, 15, 1, 14, 3500000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_400x240, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 1, 31, 15, 14, 937500, 512, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 14, 96000, 256, 60}
    },
#endif
#else  //CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
#if defined(__MED_VIDEO_ULC__)      //ULC(ultra low cost) mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 14, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 15, 14, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 15, 14, 256000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 14, 96000, 256, 60}
    },
#elif defined(__MPEG4_ENC_SW_SLIM__)//SLIM mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 14, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 14, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 15, 14, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 14, 96000, 256, 60}
    },

    //-----------------------------Rotation-----------------------------
    //Video live Wallpaper
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 14, 1950000, 256, 60}
    },
#else                               //NORMAL mode
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {240, 120, 120, 60, 4, 4, 15, 1, 14, 3500000, 768, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_400x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 1, 31, 15, 14, 937500, 512, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 15, 14, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 14, 96000, 256, 60}
    },

    //-----------------------------Rotation-----------------------------
    //Video live Wallpaper
#if defined(__MMI_MAINLCD_432X240__)
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_432x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 1, 31, 15, 14, 1012500, 512, 60}
    },
#elif defined(__MMI_MAINLCD_240X432__)
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_240x432, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 1, 31, 15, 14, 1012500, 512, 60}
    },
#elif defined(__MMI_MAINLCD_400X240__)
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_400x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 1, 31, 15, 14, 937500, 512, 60}
    },
#elif defined(__MMI_MAINLCD_240X400__)
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_240x400, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 1, 31, 15, 14, 937500, 512, 60}
    },
#elif defined(__MMI_MAINLCD_320X240__)
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 14, 1950000, 256, 60}
    },
#elif defined(__MMI_MAINLCD_240X320__)
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 14, 1950000, 256, 60}
    },
#else
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x480, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {240, 120, 120, 60, 4, 4, 15, 1, 14, 3500000, 768, 60}
    },
#endif 
#endif
#endif //CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
};

#elif defined(MT6268)

/******************************************************************************
* MT6268
******************************************************************************/
static const VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T _rMpeg4FrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_720x480, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_NONE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 3000000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_720x480, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_NONE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 2200000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_720x480, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_NONE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 750000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_720x480, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_NONE},
        /* Lower table begins. */
        {150, 75, 150, 75, 0, 0, 0, 128, 0, 187500, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x480, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_NONE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 3400000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x480, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_NONE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 2550000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x480, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_NONE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 850000, 0, 0}
    },

{
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x480, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_NONE},
        /* Lower table begins. */
        {150, 75, 150, 75, 0, 0, 0, 128, 0, 187500, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_NONE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 800000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_NONE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 650000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_NONE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 350000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_NONE},
        /* Lower table begins. */
        {150, 75, 150, 75, 0, 0, 0, 128, 0, 87500, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_NONE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 512000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_NONE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 384000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_NONE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 128000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_NONE},
        /* Lower table begins. */
        {150, 75, 150, 75, 0, 0, 0, 128, 0, 9600, 0, 0}
    },
// Rotation
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_720x480, CUSTOM_VENC_QUALITY_FINE,
    	CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ENABLE},
        /* Lower table begins. */
    	{150, 150, 150, 150, 0, 0, 0, 128, 0, 3000000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_720x480, CUSTOM_VENC_QUALITY_GOOD,
    	CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ENABLE},
        /* Lower table begins. */
    	{150, 150, 150, 150, 0, 0, 0, 128, 0, 2200000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_720x480, CUSTOM_VENC_QUALITY_NORMAL,
    	CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ENABLE},
        /* Lower table begins. */
    	{150, 150, 150, 150, 0, 0, 0, 128, 0, 750000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_720x480, CUSTOM_VENC_QUALITY_LOW,
    	CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ENABLE},
        /* Lower table begins. */
        {150, 75, 150, 75, 0, 0, 0, 128, 0, 187500, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x480, CUSTOM_VENC_QUALITY_FINE,
    	CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ENABLE},
        /* Lower table begins. */
    	{150, 150, 150, 150, 0, 0, 0, 128, 0, 3400000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x480, CUSTOM_VENC_QUALITY_GOOD,
    	CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ENABLE},
        /* Lower table begins. */
    	{150, 150, 150, 150, 0, 0, 0, 128, 0, 2550000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x480, CUSTOM_VENC_QUALITY_NORMAL,
    	CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ENABLE},
        /* Lower table begins. */
    	{150, 150, 150, 150, 0, 0, 0, 128, 0, 850000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x480, CUSTOM_VENC_QUALITY_LOW,
    	CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ENABLE},
        /* Lower table begins. */
        {150, 75, 150, 75, 0, 0, 0, 128, 0, 187500, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
    	CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ENABLE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 800000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
    	CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ENABLE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 650000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_NORMAL,
    	CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ENABLE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 350000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_LOW,
    	CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ENABLE},
        /* Lower table begins. */
        {150, 75, 150, 75, 0, 0, 0, 128, 0, 87500, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
    	CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ENABLE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 512000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
    	CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ENABLE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 384000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
    	CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ENABLE},
        /* Lower table begins. */
        {300, 150, 300, 150, 0, 0, 0, 128, 0, 128000, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
    	CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ENABLE},
        /* Lower table begins. */
        {150, 75, 150, 75, 0, 0, 0, 128, 0, 9600, 0, 0}
    }
};

#elif defined(MT6256)

/******************************************************************************
* MT6256
******************************************************************************/
static const VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T _rMpeg4FrameRateTable[] =
{
/*--------------------------------------MP4 Encoder-----------------------------------------*/
//default WVGA
#ifdef __RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_800x480, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 100, 150, 100, 4, 3, 31, 15, 11, 3750000, 1886, 60}
    },
#else
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_800x480, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 100, 200, 100, 4, 3, 31, 20, 11, 5000000, 1886, 60}
    },
#endif

//-----------------------------Rotation-----------------------------
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x800, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 100, 150, 100, 4, 3, 31, 15, 11, 3750000, 1886, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x800, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 100, 150, 100, 4, 3, 31, 15, 11, 3000000, 1886, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x800, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 100, 150, 100, 4, 3, 31, 15, 11, 2250000, 1886, 60}
    },

#ifndef __FLAVOR_56_MM_HW_PERF_TEST__
/*--------------------------------------MP4 Encoder-----------------------------------------*/

#if 0
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

#ifdef __RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__
//WVGA
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_800x480, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 100, 150, 100, 4, 3, 31, 15, 11, 3000000, 1886, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_800x480, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 100, 150, 100, 4, 3, 31, 15, 11, 2250000, 1886, 60}
    },

//nHD
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 200, 150, 4, 3, 31, 20, 11, 3000000, 1131, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 200, 150, 4, 3, 31, 20, 11, 2400000, 1131, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 200, 150, 4, 3, 31, 20, 11, 1800000, 1131, 60}
    },
#else
//WVGA
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_800x480, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 100, 200, 100, 4, 3, 31, 20, 11, 4000000, 1886, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_800x480, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 100, 200, 100, 4, 3, 31, 20, 11, 3000000, 1886, 60}
    },

//nHD
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {250, 150, 250, 150, 4, 3, 31, 30, 11, 3750000, 1131, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {250, 150, 250, 150, 4, 3, 31, 30, 11, 3000000, 1131, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {250, 150, 250, 150, 4, 3, 31, 30, 11, 2250000, 1131, 60}
    },
#endif

//QVGA
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {250, 150, 250, 150, 4, 3, 31, 30, 12, 1250000, 512, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {250, 150, 250, 150, 4, 3, 31, 30, 12, 1000000, 512, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {250, 150, 250, 150, 4, 3, 31, 30, 12, 780000, 512, 60}
    },

//QCIF
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {250, 150, 250, 150, 4, 3, 31, 30, 12, 625000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {250, 150, 250, 150, 4, 3, 31, 30, 12, 500000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {250, 150, 250, 150, 4, 3, 31, 30, 12, 375000, 256, 60}
    },

/*--------------------------------------H.263 Encoder-----------------------------------------*/
//4CIF
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_704x576, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 4, 3, 31, 30, 11, 3960000, 1990, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_704x576, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 4, 3, 31, 30, 11, 3168000, 1990, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_704x576, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 4, 3, 31, 15, 11, 1536000, 1990, 60}
    },

//CIF
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_352x288, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {250, 150, 250, 150, 4, 3, 31, 30, 12, 1650000, 512, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_352x288, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {250, 150, 250, 150, 4, 3, 31, 30, 12, 1320000, 512, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_352x288, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 4, 3, 31, 15, 12, 384000, 512, 60}
    },

//QCIF
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {250, 150, 250, 150, 4, 3, 31, 30, 12, 625000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {250, 150, 250, 150, 4, 3, 31, 30, 12, 500000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 10, 3, 31, 15, 12, 96000, 256, 60}
    },
#else
/*--------------------------------------MP4 Encoder-----------------------------------------*/

#if 0
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

#ifdef __RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__
//WVGA
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_800x480, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 100, 200, 150, 4, 3, 31, 15, 11, 3000000, 1886, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_800x480, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 100, 150, 100, 4, 3, 31, 15, 11, 2250000, 1886, 60}
    },

//nHD
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 200, 150, 4, 3, 31, 20, 11, 3000000, 1131, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 200, 150, 4, 3, 31, 20, 11, 2400000, 1131, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 200, 150, 4, 3, 31, 20, 11, 1800000, 1131, 60}
    },
#else
//WVGA
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_800x480, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 100, 200, 100, 4, 3, 31, 20, 11, 4000000, 1886, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_800x480, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 100, 200, 100, 4, 3, 31, 20, 11, 3000000, 1886, 60}
    },

//nHD
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 3, 31, 30, 11, 4500000, 1131, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 3, 31, 30, 11, 3600000, 1131, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 3, 31, 30, 11, 2700000, 1131, 60}
    },
#endif

//QVGA
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 3, 31, 30, 12, 1500000, 512, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 3, 31, 30, 12, 1200000, 512, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 3, 31, 30, 12, 937500, 512, 60}
    },

//QCIF
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 3, 31, 30, 12, 750000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 3, 31, 30, 12, 600000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 3, 31, 30, 12, 450000, 256, 60}
    },

/*--------------------------------------H.263 Encoder-----------------------------------------*/
//4CIF
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_704x576, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 4, 3, 31, 30, 11, 3960000, 1990, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_704x576, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 4, 3, 31, 30, 11, 3168000, 1990, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_704x576, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 4, 3, 31, 15, 11, 1536000, 1990, 60}
    },

//CIF
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_352x288, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 3, 31, 30, 12, 1980000, 512, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_352x288, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 3, 31, 30, 12, 1584000, 512, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_352x288, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 4, 3, 31, 15, 12, 384000, 512, 60}
    },

//QCIF
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 3, 31, 30, 12, 750000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 3, 31, 30, 12, 600000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 10, 3, 31, 15, 12, 96000, 256, 60}
    },
#endif
};

#elif defined(MT6276)

/******************************************************************************
* MT6276
******************************************************************************/
static const VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T _rMpeg4FrameRateTable[] =
{
#ifndef __MPEG4_ENC_SW_SLIM__
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_800x480, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 3, 31, 8, 13, 4000000, 1886, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_800x480, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 3, 31, 8, 13, 3200000, 1886, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_800x480, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 3, 31, 8, 13, 2400000, 1886, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_800x480, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 3, 31, 8, 13, 1800000, 1886, 60}
    },

//-----------------------------Rotation-----------------------------
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x800, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 3, 31, 8, 13, 4000000, 1886, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x800, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 3, 31, 8, 13, 3200000, 1886, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x800, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 3, 31, 8, 13, 2400000, 1886, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x800, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 3, 31, 8, 13, 1800000, 1886, 60}
    },

//-------------------------------------------------------------------
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 100, 200, 100, 4, 1, 31, 20, 10, 3000000, 800, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 100, 200, 100, 4, 1, 31, 20, 10, 2400000, 800, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 100, 200, 100, 4, 1, 31, 20, 10, 1875000, 800, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 100, 200, 100, 4, 1, 31, 20, 10, 1350000, 800, 60}
    },
#endif

#ifdef __MPEG4_ENC_SW_SLIM__
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {240, 120, 240, 120, 4, 1, 31, 24, 10, 2400000, 512, 60}
    },
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {240, 120, 240, 120, 4, 1, 31, 24, 10, 1920000, 512, 60}
    },
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {240, 120, 240, 120, 4, 1, 31, 24, 10, 1440000, 512, 60}
    },
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {240, 120, 240, 120, 4, 1, 31, 24, 10, 1080000, 512, 60}
    },

//-----------------------------Rotation-----------------------------
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x480, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {240, 120, 240, 120, 4, 1, 31, 24, 10, 2400000, 512, 60}
    },
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x480, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {240, 120, 240, 120, 4, 1, 31, 24, 10, 1920000, 512, 60}
    },
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x480, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {240, 120, 240, 120, 4, 1, 31, 24, 10, 1440000, 512, 60}
    },
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x480, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {240, 120, 240, 120, 4, 1, 31, 24, 10, 1080000, 512, 60}
    },

//-------------------------------------------------------------------
#endif
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 1, 31, 30, 10, 1500000, 512, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 1, 31, 30, 10, 1200000, 512, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 1, 31, 30, 10, 937500, 512, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 1, 31, 30, 10, 675000, 512, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 1, 31, 30, 7, 750000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 1, 31, 30, 7, 600000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 300, 150, 4, 1, 31, 30, 7, 450000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 10, 1, 31, 15, 7, 96000, 256, 60}
    }
};

#elif defined(MT6235) || defined(MT6235B)

/******************************************************************************
* MT6235
******************************************************************************/
static const VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T _rMpeg4FrameRateTable[] =
{
#ifdef CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
    {
#ifdef __VIDEO_MP4_RECORD_SUPPORT_HVGA_6235__
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 100, 75, 4, 4, 15, 1, 1, 3000000, 768, 60}
#else
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_352x288, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 2600000, 512, 60}
#endif
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 30, 1, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    }
#else
    {
#ifdef __VIDEO_MP4_RECORD_SUPPORT_HVGA_6235__
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {200, 150, 100, 75, 4, 4, 15, 1, 1, 3000000, 768, 60}
#else
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_352x288, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 2600000, 512, 60}
#endif
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 30, 1, 384000, 256, 60}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H263, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 10, 1, 31, 90, 1, 96000, 256, 60}
    },

//-----------------------------Rotation-----------------------------
      {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {300, 150, 150, 75, 4, 4, 15, 1, 1, 1950000, 256, 60}
    }
#endif        
};

#else

/******************************************************************************
* For unknown IC.
******************************************************************************/
static const VIDEO_ENC_REC_MPEG4_FRAME_RATE_TABLE_V2_T _rMpeg4FrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_ALL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MPEG4, CUSTOM_VENC_ROTATE_ALL},
        /* Lower table begins. */
        {150, 75, 150, 75, 10, 1, 31, 15, 1, 384000, 256, 60}
    }
};

#endif  // MT6236


#endif  // __MPEG4_ENC_SUPPORT__


#endif  // VIDEO_RECORDER_SETTING_MPEG4_H

