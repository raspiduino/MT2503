/*****************************************************************************
 * Filename:
 * ---------
 * custom_video_enc_if.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file can be modified for customied video parameters.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/

#ifndef CUSTOM_VIDEO_ENC_IF_H
#define CUSTOM_VIDEO_ENC_IF_H


#include "kal_release.h"


/*****************************************************************************
*
*****************************************************************************/
typedef enum
{
    CUSTOM_VENC_RESOLUTION_128x96 = 0,          // SQCIF
    CUSTOM_VENC_RESOLUTION_160x120,             // QQVGA
    CUSTOM_VENC_RESOLUTION_176x144,             // QCIF
    CUSTOM_VENC_RESOLUTION_320x240,             // QVGA
    CUSTOM_VENC_RESOLUTION_400x240,             // WQVGA
    CUSTOM_VENC_RESOLUTION_352x288,             // CIF
    CUSTOM_VENC_RESOLUTION_432x240,             // CIF
    CUSTOM_VENC_RESOLUTION_480x320,             // HVGA
    CUSTOM_VENC_RESOLUTION_640x368,             // HND
    CUSTOM_VENC_RESOLUTION_640x480,             // VGA
    CUSTOM_VENC_RESOLUTION_720x480,             // D1
    CUSTOM_VENC_RESOLUTION_800x480,             // WVGA
    CUSTOM_VENC_RESOLUTION_848x480,             // WVGA
    CUSTOM_VENC_RESOLUTION_720x576,             // D1
    CUSTOM_VENC_RESOLUTION_800x608,             // SVGA
    CUSTOM_VENC_RESOLUTION_1024x768,            // XGA
    CUSTOM_VENC_RESOLUTION_1280x720,            // 720P
    CUSTOM_VENC_RESOLUTION_1280x960,            // 4VGA
    CUSTOM_VENC_RESOLUTION_1280x1024,           // SXGA
    CUSTOM_VENC_RESOLUTION_1408x1152,           // 16CIF
    CUSTOM_VENC_RESOLUTION_1600x1200,           // 4SVGA
    CUSTOM_VENC_RESOLUTION_1920x1088,           // FHD
    CUSTOM_VENC_RESOLUTION_704x576,             // 4CIF
    CUSTOM_VENC_RESOLUTION_864x480,             // FWVGA
//rotate 90
    CUSTOM_VENC_RESOLUTION_96x128 = 200,        // SQCIF
    CUSTOM_VENC_RESOLUTION_120x160,             // QQVGA
    CUSTOM_VENC_RESOLUTION_144x176,             // QCIF
    CUSTOM_VENC_RESOLUTION_176x208,             // 176x220LCM
    CUSTOM_VENC_RESOLUTION_240x320,             // QVGA
    CUSTOM_VENC_RESOLUTION_240x400,             // WQVGA
    CUSTOM_VENC_RESOLUTION_288x352,             // CIF
    CUSTOM_VENC_RESOLUTION_240x432,             // CIF
    CUSTOM_VENC_RESOLUTION_320x480,             // HVGA
    CUSTOM_VENC_RESOLUTION_368x640,             // HND
    CUSTOM_VENC_RESOLUTION_480x640,             // VGA
    CUSTOM_VENC_RESOLUTION_480x720,             // D1
    CUSTOM_VENC_RESOLUTION_480x800,             // WVGA
    CUSTOM_VENC_RESOLUTION_480x848,             // WVGA
    CUSTOM_VENC_RESOLUTION_576x720,             // D1
    CUSTOM_VENC_RESOLUTION_608x800,             // SVGA
    CUSTOM_VENC_RESOLUTION_768x1024,            // XGA
    CUSTOM_VENC_RESOLUTION_720x1280,            // 720P
    CUSTOM_VENC_RESOLUTION_960x1280,            // 4VGA
    CUSTOM_VENC_RESOLUTION_1024x1280,           // SXGA
    CUSTOM_VENC_RESOLUTION_1152x1408,           // 16CIF
    CUSTOM_VENC_RESOLUTION_1200x1600,           // 4SVGA
    CUSTOM_VENC_RESOLUTION_1088x1920,           // FHD
    CUSTOM_VENC_RESOLUTION_576x704,             // 4CIF
    CUSTOM_VENC_RESOLUTION_480x864,             // FWVGA
    CUSTOM_VENC_RESOLUTION_UNKNOWN = 0x1FFFFFFF // Unknown
} CUSTOM_VENC_RESOLUTION_T;


/*****************************************************************************
*
*****************************************************************************/
typedef enum
{
    CUSTOM_VENC_QUALITY_ALL = 0,
    CUSTOM_VENC_QUALITY_LOW,
    CUSTOM_VENC_QUALITY_NORMAL,
    CUSTOM_VENC_QUALITY_GOOD,
    CUSTOM_VENC_QUALITY_FINE,
    CUSTOM_VENC_QUALITY_UNKNOWN = 0x1FFFFFFF        // Keep it at end.
} CUSTOM_VENC_QUALITY_T;


/*****************************************************************************
*
*****************************************************************************/
typedef enum
{
    CUSTOM_VENC_STORAGE_ALL = 0,
    CUSTOM_VENC_STORAGE_SD,
    CUSTOM_VENC_STORAGE_PHONE,
    CUSTOM_VENC_STORAGE_UNKNOWN = 0x1FFFFFFF
} CUSTOM_VENC_STORAGE_T;


/*****************************************************************************
*
*****************************************************************************/
typedef enum
{
    CUSTOM_VENC_CODEC_ALL = 0,
    CUSTOM_VENC_CODEC_MPEG4,
    CUSTOM_VENC_CODEC_H263,
    CUSTOM_VENC_CODEC_H264,
    CUSTOM_VENC_CODEC_MJPEG,
    CUSTOM_VENC_CODEC_UNKNOWN = 0x1FFFFFFF          // Keep it at end.
} CUSTOM_VENC_CODEC_T;

/*****************************************************************************
*
*****************************************************************************/
typedef enum
{
  CUSTOM_VENC_ROTATE_ALL  = 0,
  CUSTOM_VENC_ROTATE_NONE,
  CUSTOM_VENC_ROTATE_ENABLE,                       // using software rotation, which occupies CPU cycle and cause performance downgrade.
  CUSTOM_VENC_ROTATE_UNKNOWN = 0x1FFFFFFF          // Keep it at end.
} CUSTOM_VENC_ROTATE_T;

/******************************************************************************
* This data structure is used by MMI.
******************************************************************************/
typedef struct
{
    CUSTOM_VENC_RESOLUTION_T eResolution;
    CUSTOM_VENC_QUALITY_T eQuality;
    CUSTOM_VENC_STORAGE_T eStorage;
    CUSTOM_VENC_CODEC_T eCodec;
} CUSTOM_VENC_UPPER_TABLE_T;

typedef struct
{
    CUSTOM_VENC_RESOLUTION_T  eResolution;
    CUSTOM_VENC_QUALITY_T     eQuality;
    CUSTOM_VENC_STORAGE_T     eStorage;
    CUSTOM_VENC_CODEC_T       eCodec;
    CUSTOM_VENC_ROTATE_T      eRotate;
} CUSTOM_VENC_REC_MPEG4_UPPER_TABLE_T;


/*****************************************************************************
*
*****************************************************************************/
typedef enum
{
    CUSTOM_VENC_USER_REC_MPEG4 = 0,
    CUSTOM_VENC_USER_MATV_MPEG4_NTSC,
    CUSTOM_VENC_USER_MATV_MPEG4_PAL,
    CUSTOM_VENC_USER_REC_MJPEG,
    CUSTOM_VENC_USER_VT_MPEG4,
    CUSTOM_VENC_USER_REC_H264,
    CUSTOM_VENC_USER_MATV_MJPEG_NTSC,
    CUSTOM_VENC_USER_MATV_MJPEG_PAL,
    CUSTOM_VENC_USER_UNKNOWN = 0x1FFFFFFF           // Keep it at end.
} CUSTOM_VENC_USER_T;


/*****************************************************************************
*
*****************************************************************************/
typedef enum
{
    CUSTOM_VENC_ERROR_NONE = 0,
    CUSTOM_VENC_ERROR_SCENARIO,
    CUSTOM_VENC_ERROR_NO_MATCH,                     // No match is found.
    CUSTOM_VENC_ERROR_USE_DEFAULT,                  // Default value is used.
    CUSTOM_VENC_ERROR_NOT_SUPPORTED = 0x1FFFFFFF    // Keep it at end.
} CUSTOM_VENC_ERROR_T;


/*****************************************************************************
*
*****************************************************************************/
typedef enum
{
    CUSTOM_VENC_OP_SET_USER = 0,                    // Used by MED
    CUSTOM_VENC_OP_GET_NUM_OF_ENTRIES,              // Used by MED
    CUSTOM_VENC_OP_GET_ONE_ENTRY,                   // Used by MED

    CUSTOM_VENC_OP_SET_WIDTH,                       // Used by MED
    CUSTOM_VENC_OP_SET_HEIGHT,                      // Used by MED
    CUSTOM_VENC_OP_SET_QUALITY,                     // Used by MED
    CUSTOM_VENC_OP_SET_STORAGE,                     // Used by MED
    CUSTOM_VENC_OP_SET_CODEC,                       // Used by MED

    CUSTOM_VENC_OP_GET_SENSOR_FRAME_RATE,           // Used by MED/codec
    CUSTOM_VENC_OP_GET_SENSOR_NIGHT_FRAME_RATE,     // Used by MED/codec
    CUSTOM_VENC_OP_GET_ENCODER_FRAME_RATE,          // Used by MED/codec
    CUSTOM_VENC_OP_GET_ENCODER_NIGHT_FRAME_RATE,    // Used by MED/codec

    CUSTOM_VENC_OP_GET_INIT_Q,                      // Used by codec
    CUSTOM_VENC_OP_GET_MIN_QP,                      // Used by codec
    CUSTOM_VENC_OP_GET_MAX_QP,                      // Used by codec
    CUSTOM_VENC_OP_GET_INTRA_VOP_RATE,              // Used by MED/codec
    CUSTOM_VENC_OP_GET_ALGORITHM,                   // Used by codec
    CUSTOM_VENC_OP_GET_BIT_RATE,                    // Used by MED/codec
    CUSTOM_VENC_OP_GET_RATE_HARD_LIMIT,             // Used by codec
    CUSTOM_VENC_OP_GET_RATE_BALANCE,                // Used by codec
    CUSTOM_VENC_OP_GET_DYNAMIC_RANGE_REDUCTION,     // Used by codec
    CUSTOM_VENC_OP_GET_IS_CUSTOMER_SET_TABLE,       // Used by codec
    CUSTOM_VENC_OP_GET_DYNAMIC_RANGE_TABLE,         // Used by codec

    CUSTOM_VENC_OP_GET_LCM_OF_CODEC_FRAME_RATE,     // Used by MED
    CUSTOM_VENC_OP_GET_ONE_ENTRY_REC_MPEG4,         // used by MED
    
    CUSTOM_VENC_OP_SET_ROTATE,                      // used by MED in MPEG4

    CUSTOM_VENC_OP_GET_TARGET_COMPLEXITY,           // used by H264 ENC
    CUSTOM_VENC_OP_GET_THRESHOLD_AVG_LOW,           // used by H264 ENC
    CUSTOM_VENC_OP_GET_THRESHOLD_AVG_HIGH,          // used by H264 ENC
    CUSTOM_VENC_OP_GET_THRESHOLD_CUR_LOW,           // used by H264 ENC
    CUSTOM_VENC_OP_GET_THRESHOLD_CUR_HIGH,          // used by H264 ENC
    CUSTOM_VENC_OP_UNKNOWN = 0x1FFFFFFF             // Keep it at end.
} CUSTOM_VENC_OP_T;


/*****************************************************************************
* This OP code is used to set the user to be one of the MATV, MJPEG, MPEG4, or
* VT.
*
* For use with CUSTOM_VENC_OP_SET_USER.
* Input: a pointer to CUSTOM_VENC_USER_T for storing the user type.
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_GET_NUM_OF_ENTRIES.
* Input: None
* Output: a pointer to kal_uint32 for storing number of entries in the frame
*         rate table.
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_GET_ONE_ENTRY.
* Input: a pointer to kal_uint32 which stores the table index.
* Output: a pointer to CUSTOM_VENC_UPPER_TABLE_T for storing the upper frame
*         rate table.
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_SET_WIDTH.
* Input: a pointer to kal_uint32 which stores the image width.
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_SET_HEIGHT.
* Input: a pointer to kal_uint32 which stores the image height.
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_SET_QUALITY.
* Input: a pointer to CUSTOM_VENC_QUALITY_T which stores the quality value.
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_SET_STORAGE.
* Input: a pointer to CUSTOM_VENC_STORAGE_T which stores the storage value.
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_SET_CODEC.
* Input: a pointer to CUSTOM_VENC_CODEC_T which stores the codec value.
* Output: None
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_GET_SENSOR_FRAME_RATE.
* Input: None
* Output: a pointer to kal_uint32 for storing the sensor frame rate value.
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_GET_SENSOR_NIGHT_FRAME_RATE.
* Input: None
* Output: a pointer to kal_uint32 for storing the sensor night frame rate value.
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_GET_ENCODER_FRAME_RATE.
* Input: None
* Output: a pointer to kal_uint32 for storing the encoder frame rate value.
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_GET_ENCODER_NIGHT_FRAME_RATE.
* Input: None
* Output: a pointer to kal_uint32 for storing the encoder night frame rate value.
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_GET_INIT_Q.
* Input: None
* Output: a pointer to kal_uint32 for storing the initial Q value.
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_GET_MIN_QP.
* Input: None
* Output: a pointer to kal_uint32 for storing the minimal Qp value.
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_GET_MAX_QP.
* Input: None
* Output: a pointer to kal_uint32 for storing the maximal Qp value.
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_GET_INTRA_VOP_RATE.
* Input: None
* Output: a pointer to kal_uint32 for storing the intra VOP rate.
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_GET_ALGORITHM.
* Input: None
* Output: a pointer to kal_uint32 for storing the selected algorithm.
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_GET_BIT_RATE.
* Input: None
* Output: a pointer to kal_uint32 for storing the bit rate value.
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_GET_RATE_HARD_LIMIT.
* Input: None
* Output: a pointer to kal_uint32 for storing the hard limit of bit rate.
*****************************************************************************/


/*****************************************************************************
* For use with CUSTOM_VENC_OP_GET_RATE_BALANCE.
* Input: None
* Output: a pointer to kal_uint32 for storing the rate balance value.
*****************************************************************************/


/******************************************************************************
* Function prototypes
******************************************************************************/
extern CUSTOM_VENC_ERROR_T CustomVenc_Ctrl(CUSTOM_VENC_OP_T eOp,
    void *pvInput, kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize);

extern CUSTOM_VENC_ERROR_T CustomVenc_Ctrl_Get_NumOf_Recorder_Users(CUSTOM_VENC_USER_T **UserTable, kal_uint32 *u4NumUser);

typedef CUSTOM_VENC_ERROR_T (*PFN_CUSTOM_VENC_CTRL)(CUSTOM_VENC_OP_T eOp, void *pvInput, kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize);


#endif  // CUSTOM_VIDEO_ENC_IF_H

