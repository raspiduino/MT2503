/*****************************************************************************
 * Filename:
 * ---------
 * custom_video.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for customize some video parameters.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef ___CUSTOM_VIDEO_H_
#define ___CUSTOM_VIDEO_H_

#include "med_status.h"                 // for MEDIA_STATUS_CODE
#include "MP4SwEncDefs.h"
#include "med_api.h"

extern void vid_convert_quality_to_bitrate(
                kal_uint16 width,
                kal_uint16 height,
                kal_uint8 quality,
                kal_uint32 *bitrate_p,
                kal_uint8 *skip_frame_p);

extern void vid_convert_quality_to_bitrate_in_phone(
                kal_uint16 width,
                kal_uint16 height,
                kal_uint8 quality,
                kal_uint32 *bitrate_p,
                kal_uint8 *skip_frame_p);

#ifndef MED_NOT_PRESENT
extern void vid_convert_quality_to_record_setting(
                MP4SwEncRecordSetting *rec_set,
                MP4SwEncQualityLevel  quality);

extern void vid_convert_quality_to_bitrate_for_matv(
        kal_uint16 width,
        kal_uint16 height,
        kal_uint8 quality,
        kal_uint32 is_ntsc,
        kal_uint32 *bitrate_p,
        kal_uint8 *skip_frame_p);


// #if defined(MT6252) || defined(MT6252H)
/******************************************************************************
* This is the data structure for non-HAL frame rate table implementation.
******************************************************************************/
typedef struct
{
    kal_uint16 u2FrameRate;             /* frame rate x 10 */
    kal_uint16 u2NightModeFrameRate;    /* frame rate x 10 */
} VIDEO_RECORDER_FRAME_RATE_T;


typedef struct
{
    kal_uint16 u2Width;
    kal_uint16 u2Height;
    VIDEO_RECORDER_FRAME_RATE_T rFrameRate;
} VIDEO_RECORD_FRAME_RATE_TABLE_T;


extern MEDIA_STATUS_CODE video_recorder_get_frame_rate(kal_uint16 u2Width,
        kal_uint16 u2Height, VIDEO_RECORDER_FRAME_RATE_T *prFrameRate);
// #endif  // defined(MT6252) || defined(MT6252H)
#endif  // MED_NOT_PRESENT


#endif  // ___CUSTOM_VIDEO_H_
