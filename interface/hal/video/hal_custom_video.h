/*****************************************************************************
 * Filename:
 * ---------
 * hal_custom_video.h
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
#ifndef __HAL_CUSTOM_VIDEO_H__
#define __HAL_CUSTOM_VIDEO_H__
#include "drv_features_video.h"
#include "video_codec_mem_custom_v2.h"
#include "hal_custom_video_if.h"
#include "kal_general_types.h"

/******************************************************************************
* How to add custom settings (v1.0)
* 1. Add definitions of custom setting in custom\video\hal_custom_video_if.h
* 2. Add definitions of customization types of HAL below
* 3. Add switch case in HalCustomQueryVideoSettings()
******************************************************************************/

/******************************************************************************
* Customization types of HAL,
* the first parameter, u4Param,of HalCustomQueryVideoSettings()
******************************************************************************/
#define HALC_INVALID_PARAM  0
#define HALC_I_FRM_RATE     1

typedef enum
{
    VC_ERR_NONE =   0,
    VC_ERR_INVALID_PARAM,
    VC_ERR_MAX  =   32767   // Unused enumerator ensuring that at least two bytes are used.
}VIDEO_CUSTOM_ERR_T;

VIDEO_CUSTOM_ERR_T HalCustomQueryVideoSettings(kal_uint32 u4Param, void* pOutput);

/******************************************************************************
* customization of "A/V sync. mechanism"
******************************************************************************/
typedef enum
{
    MPLY_CUSTOM_FORMAT_MP4,
    MPLY_CUSTOM_FORMAT_H264,
    MPLY_CUSTOM_FORMAT_RM,
    MPLY_CUSTOM_FORMAT_VP8,
    MPLY_CUSTOM_FORMAT_NUM
} mply_custom_format_enum;

#define CUS_IDX_PLAYER_SETTING_START 0
#define CUS_IDX_JUMP2I  CUS_IDX_PLAYER_SETTING_START
#define CUS_IDX_AVRESYNC  1
#define CUS_IDX_FIND_KEYFRAME  2
#define CUS_IDX_MAX_TIME2JUMP  3
#define CUS_IDX_RESERVED 4

#define CUS_IDX_STREAMING_SETTING_START 5
#define CUS_IDX_STREAMING_JUMP2I  CUS_IDX_STREAMING_SETTING_START
#define CUS_IDX_STREAMING_AVRESYNC  6
#define CUS_IDX_STREAMING_FIND_KEYFRAME  7
#define CUS_IDX_STREAMING_MAX_TIME2JUMP  8
#define CUS_IDX_STREAMING_RESERVED 9

#define CUS_IDX_CMMB_SETTING_START 10
#define CUS_IDX_CMMB_JUMP2I  CUS_IDX_CMMB_SETTING_START
#define CUS_IDX_CMMB_AVRESYNC  11
#define CUS_IDX_CMMB_FIND_KEYFRAME  12
#define CUS_IDX_CMMB_MAX_TIME2JUMP  13
#define CUS_IDX_CMMB_RESERVED 14

/* Dutatoin to resume jump to I checking */
#define MPLY_RESET_RECOVER_ELAPSE (2000)

extern kal_uint64 mply_custom_get_cust(mply_custom_format_enum format, kal_uint32 idx); /* get value */
extern void mply_custom_set_cust(mply_custom_format_enum format, kal_uint32 idx, kal_uint64 cust); /* get value */

#endif //__HAL_CUSTOM_VIDEO_INTERNAL_H__

