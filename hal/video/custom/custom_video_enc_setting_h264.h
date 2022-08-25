#ifndef VIDEO_RECORDER_SETTING_H264_H
#define VIDEO_RECORDER_SETTING_H264_H

/* __H264_ENC_SUPPORT__ is a global option. */
#ifdef __H264_ENC_SUPPORT__


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

    kal_uint32  u4bitrate;
    kal_uint32  u4KeyintMax;
    kal_uint32  u4AlgorithmSelect;
    kal_uint32  u4TargetComplexity;
    kal_uint32  u4AvgThLow;
    kal_uint32  u4AvgThHigh;
    kal_uint32  u4CurThLow;
    kal_uint32  u4CurThHigh;
} CUSTOM_VENC_REC_H264_LOWER_TABLE_T;

typedef struct
{
    CUSTOM_VENC_UPPER_TABLE_T rUpperTable;              /// rUpperTable is used by MED.
    CUSTOM_VENC_REC_H264_LOWER_TABLE_T rLowerTable;    /// rLowerTable is used by codec except for frame rate values which are also used by MED.
} VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T;

*******************************************************************************/


#if defined(MT6276)

/******************************************************************************
* MT6276
******************************************************************************/
static const VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T _rH264FrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {300, 150, 300, 150, 256000, 30, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {300, 150, 300, 150, 256000, 30, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {300, 150, 300, 150, 384000, 30, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {300, 150, 300, 150, 436000, 30, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {240, 150, 240, 150, 256000, 24, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {240, 150, 240, 150, 512000, 24, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {240, 150, 240, 150, 768000, 24, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {240, 150, 240, 150, 1050000, 24, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_400x240, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {180, 120, 180, 120, 248000, 18, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_400x240, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {180, 120, 180, 120, 496000, 18, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_400x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {180, 120, 180, 120, 744000, 18, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_400x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {180, 120, 180, 120, 985000, 18, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_352x288, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {180, 120, 180, 120, 256000, 18, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_352x288, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {180, 120, 180, 120, 512000, 18, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_352x288, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {180, 120, 180, 120, 768000, 18, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_352x288, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {180, 120, 180, 120, 1050000, 18, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {240, 120, 120, 120, 256000, 12, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {240, 120, 120, 120, 512000, 12, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {240, 120, 120, 120, 768000, 12, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {240, 120, 120, 120, 1050000, 12, 3, 0, 0, 0, 0, 0}
    }
};
#elif defined(MT6256)

/******************************************************************************
* MT6256
******************************************************************************/
static const VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T _rH264FrameRateTable[] =
{
#if defined(__FLAVOR_56_MM_HW_PERF_TEST__)
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {300, 150, 300, 150, 256000, 30, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {300, 150, 300, 150, 384000, 30, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {300, 150, 300, 150, 436000, 30, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {300, 150, 150, 150, 256000, 15, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {300, 150, 150, 150, 384000, 15, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {300, 150, 150, 150, 525000, 15, 3, 0, 0, 0, 0, 0}
    }
#else
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {250, 150, 250, 150, 215000, 30, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {250, 150, 250, 150, 320000, 30, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {250, 150, 250, 150, 364000, 30, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {150, 150, 150, 150, 256000, 15, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {150, 150, 150, 150, 384000, 15, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {150, 150, 150, 150, 525000, 15, 3, 0, 0, 0, 0, 0}
    }
#endif
};
#elif defined(MT6255)
/******************************************************************************
* MT6255
******************************************************************************/
#ifndef CUSTOM_VENC_USE_REDUCED_SELECTION
#error "the table was setup in nokia style. please replace it"
#endif

#ifdef CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
static const VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T _rH264FrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {150, 150, 150, 150, 320000, 30, 3, 0, 0, 0, 0, 0}
    }
};
#else
static const VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T _rH264FrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {150, 150, 150, 150, 128000, 30, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {150, 150, 150, 150, 192000, 30, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {150, 150, 150, 150, 256000, 30, 3, 0, 0, 0, 0, 0}
    },

    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {150, 150, 150, 150, 320000, 30, 3, 0, 0, 0, 0, 0}
    }
};
#endif
#elif defined(MT6260)
/******************************************************************************
* MT6260
******************************************************************************/
#ifndef CUSTOM_VENC_USE_REDUCED_SELECTION
#error "the table was setup in nokia style. please replace it"
#endif

#ifdef __STREAM_SERVER_SUPPORT__ 
static const VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T _rH264FrameRateTable[] =
{
    //QVGA 15fps, 384kbps
	//a=fmtp:96 profile-level-id=42C00D;sprop-parameter-sets=Z0LADatAoP0IAAADAAgAAAMA9HihVQ==,aM48gA==
	{
		/* Upper table begins. */
		{CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
		CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
		/* Lower table begins. */
		{300, 150, 150, 150, 384000, 15, 9, 0, 0, 0, 0, 0}
	},
	
    // QVGA 15fps, 256kbps
	//a=fmtp:96 profile-level-id=42C00D;sprop-parameter-sets=Z0LADatAoP0IAAADAAgAAAMA9HihVQ==,aM48gA==
	{
		/* Upper table begins. */
		{CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_NORMAL,
		CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
		/* Lower table begins. */
		{300, 150, 150, 150, 256000, 15, 9, 0, 0, 0, 0, 0}
	},
	
    // QCIF 15fps, 128 kbps
	//a=fmtp:96 profile-level-id=42C00C;sprop-parameter-sets=Z0LADKtBYnQgAAADACAAAAMD0eKFVA==,aM48gA==
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {300, 150, 150, 150, 128000, 15, 9, 0, 0, 0, 0, 0}
    },
    
     // QCIF 12fps, 64 kbps
     //a=fmtp:96 profile-level-id=42C00B;sprop-parameter-sets=Z0LAC6tBYnQgAAADACAAAAMDEeKFVA==,aM48gA==
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {240, 120, 120, 120, 64000, 12, 9, 0, 0, 0, 0, 0}
    }
    
};
#endif

#else

/******************************************************************************
* For unknown IC.
******************************************************************************/
static const VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T _rH264FrameRateTable[] =
{
    {
        /* Upper table begins. */
        {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_ALL,
        CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_H264},
        /* Lower table begins. */
        {300, 150, 300, 150, 128000, 30, 3, 0, 0, 0, 0, 0}
    }
};

#endif


#endif  // __H264_ENC_SUPPORT__


#endif  // VIDEO_RECORDER_SETTING_H264_H

