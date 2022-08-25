/*****************************************************************************
 * Filename:
 * ---------
 * custom_video_enc_types_mjpeg.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is to be included by the file with the implementaton of frame
 *   rate table.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/
#ifndef CUSTOM_VIDEO_ENC_TYPES_MJPEG_H
#define CUSTOM_VIDEO_ENC_TYPES_MJPEG_H


#include "custom_video_enc_if.h"


#if defined(__MMI_MAINLCD_240X320__)
    #define CUSTOM_VENC_WALLPAPER_WIDTH   240
    #define CUSTOM_VENC_WALLPAPER_HEIGHT   320
    #define CUSTOM_VENC_RESOLUTION_WALLPAPER   CUSTOM_VENC_RESOLUTION_240x320
#elif defined(__MMI_MAINLCD_320X240__)
    #define CUSTOM_VENC_WALLPAPER_WIDTH   320
    #define CUSTOM_VENC_WALLPAPER_HEIGHT   240
    #define CUSTOM_VENC_RESOLUTION_WALLPAPER   CUSTOM_VENC_RESOLUTION_320x240
#elif defined(__MMI_MAINLCD_240X400__)
    #define CUSTOM_VENC_WALLPAPER_WIDTH   240
    #define CUSTOM_VENC_WALLPAPER_HEIGHT   400
    #define CUSTOM_VENC_RESOLUTION_WALLPAPER   CUSTOM_VENC_RESOLUTION_240x400
#elif defined(__MMI_MAINLCD_400X240__)
    #define CUSTOM_VENC_WALLPAPER_WIDTH   400
    #define CUSTOM_VENC_WALLPAPER_HEIGHT   240
    #define CUSTOM_VENC_RESOLUTION_WALLPAPER   CUSTOM_VENC_RESOLUTION_400x240
#elif defined(__MMI_MAINLCD_240X432__)
    #define CUSTOM_VENC_WALLPAPER_WIDTH   240
    #define CUSTOM_VENC_WALLPAPER_HEIGHT   432
    #define CUSTOM_VENC_RESOLUTION_WALLPAPER   CUSTOM_VENC_RESOLUTION_240x432
#elif defined(__MMI_MAINLCD_432X240__)
    #define CUSTOM_VENC_WALLPAPER_WIDTH   432
    #define CUSTOM_VENC_WALLPAPER_HEIGHT   240
    #define CUSTOM_VENC_RESOLUTION_WALLPAPER   CUSTOM_VENC_RESOLUTION_432x240
#elif defined(__MMI_MAINLCD_320X480__)
    #define CUSTOM_VENC_WALLPAPER_WIDTH   320
    #define CUSTOM_VENC_WALLPAPER_HEIGHT   480
    #define CUSTOM_VENC_RESOLUTION_WALLPAPER   CUSTOM_VENC_RESOLUTION_320x480
#elif defined(__MMI_MAINLCD_480X320__)
    #define CUSTOM_VENC_WALLPAPER_WIDTH   480
    #define CUSTOM_VENC_WALLPAPER_HEIGHT   320
    #define CUSTOM_VENC_RESOLUTION_WALLPAPER   CUSTOM_VENC_RESOLUTION_480x320
#elif defined(__MMI_MAINLCD_480X800__)
    #define CUSTOM_VENC_WALLPAPER_WIDTH   480
    #define CUSTOM_VENC_WALLPAPER_HEIGHT   800
    #define CUSTOM_VENC_RESOLUTION_WALLPAPER   CUSTOM_VENC_RESOLUTION_480x800
#elif defined(__MMI_MAINLCD_800X480__)
    #define CUSTOM_VENC_WALLPAPER_WIDTH   800
    #define CUSTOM_VENC_WALLPAPER_HEIGHT   480
    #define CUSTOM_VENC_RESOLUTION_WALLPAPER   CUSTOM_VENC_RESOLUTION_800x480
#else
    // default as QCIF resolution
    #define CUSTOM_VENC_WALLPAPER_WIDTH   176
    #define CUSTOM_VENC_WALLPAPER_HEIGHT   144
    #define CUSTOM_VENC_RESOLUTION_WALLPAPER   CUSTOM_VENC_RESOLUTION_176x144
#endif


/******************************************************************************
*
******************************************************************************/
typedef struct
{
    kal_uint16 u2SensorFrameRate;                   /* frame rate * 10 */
    kal_uint16 u2SensorNightFrameRate;              /* frame rate * 10 */
    kal_uint16 u2CodecFrameRate;                    /* frame rate * 10 */
    kal_uint16 u2CodecNightFrameRate;               /* frame rate * 10 */

    kal_uint32 u4BitRate;
} CUSTOM_VENC_REC_MJPEG_LOWER_TABLE_T;


/******************************************************************************
*
******************************************************************************/
typedef struct
{
    CUSTOM_VENC_UPPER_TABLE_T rUpperTable;              /// rUpperTable is used by MED.
    CUSTOM_VENC_REC_MJPEG_LOWER_TABLE_T rLowerTable;    /// rLowerTable is used by codec except for frame rate values which are also used by MED.
} VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T;


#endif  // CUSTOM_VIDEO_ENC_TYPES_MJPEG_H

