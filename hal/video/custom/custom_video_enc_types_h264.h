#ifndef CUSTOM_VIDEO_ENC_TYPES_H264_H
#define CUSTOM_VIDEO_ENC_TYPES_H264_H


#include "custom_video_enc_if.h"


/******************************************************************************
*
******************************************************************************/
typedef struct
{
    kal_uint16 u2SensorFrameRate;                   /* frame rate * 10 */
    kal_uint16 u2SensorNightFrameRate;              /* frame rate * 10 */
    kal_uint16 u2CodecFrameRate;                    /* frame rate * 10 */
    kal_uint16 u2CodecNightFrameRate;               /* frame rate * 10 */

    kal_uint32  u4bitrate;                           /* in 1000 bits */
    kal_uint32  u4KeyintMax;
    kal_uint32  u4AlgorithmSelect;
    kal_uint32  u4TargetComplexity;
    kal_uint32  u4AvgThLow;
    kal_uint32  u4AvgThHigh;
    kal_uint32  u4CurThLow;
    kal_uint32  u4CurThHigh;
} CUSTOM_VENC_REC_H264_LOWER_TABLE_T;


/******************************************************************************
*
******************************************************************************/
typedef struct
{
    CUSTOM_VENC_UPPER_TABLE_T rUpperTable;              /// rUpperTable is used by MED.
    CUSTOM_VENC_REC_H264_LOWER_TABLE_T rLowerTable;    /// rLowerTable is used by codec except for frame rate values which are also used by MED.
} VIDEO_ENC_REC_H264_FRAME_RATE_TABLE_T;


#endif  // CUSTOM_VIDEO_ENC_TYPES_H264_H

