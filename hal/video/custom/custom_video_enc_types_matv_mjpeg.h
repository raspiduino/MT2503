/*****************************************************************************
 * Filename:
 * ---------
 * custom_video_enc_types_matv_mjpeg.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/
#ifndef CUSTOM_VIDEO_ENC_TYPES_MATV_MJPEG_H
#define CUSTOM_VIDEO_ENC_TYPES_MATV_MJPEG_H


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

    kal_uint32 u4BitRate;
} CUSTOM_VENC_MATV_MJPEG_LOWER_TABLE_T;


/******************************************************************************
*
******************************************************************************/
typedef struct
{
    CUSTOM_VENC_UPPER_TABLE_T rUpperTable;              /// rUpperTable is used by MED.
    CUSTOM_VENC_MATV_MJPEG_LOWER_TABLE_T rLowerTable;   /// rLowerTable is used by codec except for frame rate values which are also used by MED.
} VIDEO_ENC_MATV_MJPEG_FRAME_RATE_TABLE_T;


#endif  // CUSTOM_VIDEO_ENC_TYPES_MATV_MJPEG_H

