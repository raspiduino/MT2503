/*****************************************************************************
 * Filename:
 * ---------
 * hal_custom_video_codec_if.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for customization of video features
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __HAL_CUSTOM_VIDEO_CODEC_IF_H__
#define __HAL_CUSTOM_VIDEO_CODEC_IF_H__
#include "kal_general_types.h"

/******************************************************************************
* customization of "codec mode setting"
******************************************************************************/
typedef enum
{
    MPLY_CODEC_CUSTOM_FORMAT_MP4,
    MPLY_CODEC_CUSTOM_FORMAT_H264,
    MPLY_CODEC_CUSTOM_FORMAT_RM,
    MPLY_CODEC_CUSTOM_FORMAT_VP8,
    MPLY_CODEC_CUSTOM_FORMAT_NUM
} mply_codec_custom_format_enum;

typedef enum
{
    MPLY_CODEC_CUSTOM_ITEM_SET_PLAYBACK_MODE,
    MPLY_CODEC_CUSTOM_ITEM_GET_PLAYBACK_MODE,
    MPLY_CODEC_CUSTOM_ITEM_GET_PREVIOUS_MODE,
    MPLY_CODEC_CUSTOM_ITEM_SET_FLUENCY_LEVEL,
    MPLY_CODEC_CUSTOM_ITEM_GET_FLUENCY_LEVEL,
    MPLY_CODEC_CUSTOM_ITEM_NUM
} mply_codec_custom_item_enum;

typedef enum
{
    MPLY_CODEC_CUSTOM_PLAYBACK_MODE_QUALITY,
    MPLY_CODEC_CUSTOM_PLAYBACK_MODE_BALANCE,
    MPLY_CODEC_CUSTOM_PLAYBACK_MODE_FLUENT,
    MPLY_CODEC_CUSTOM_PLAYBACK_MODE_NUM
} mply_codec_custom_playback_mode_enum;

extern kal_uint64 mply_codec_custom_get_cust(mply_codec_custom_format_enum format, kal_uint32 idx); /* get value */
extern void mply_codec_custom_set_cust(mply_codec_custom_format_enum format, kal_uint32 idx, kal_uint64 cust); /* get value */
extern int mply_codec_custom_query(mply_codec_custom_format_enum format, mply_codec_custom_item_enum item, unsigned int value);
#endif //__HAL_CUSTOM_VIDEO_CODEC_IF_H__

