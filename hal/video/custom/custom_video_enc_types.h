/*****************************************************************************
 * Filename:
 * ---------
 * custom_video_enc_types.h
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

#ifndef CUSTOM_VIDEO_ENC_TYPES_H
#define CUSTOM_VIDEO_ENC_TYPES_H

#include "custom_rec_config.h"

#include "custom_video_enc_if.h"
#include "custom_video_enc_types_matv.h"
#include "custom_video_enc_types_mjpeg.h"
#include "custom_video_enc_types_mpeg4.h"
#include "custom_video_enc_types_h264.h"
#include "custom_video_enc_types_vt.h"


extern CUSTOM_VENC_ERROR_T CustomVenc_MapWidthAndHeightToResolution(kal_uint16 u2Width,
        kal_uint16 u2Height, CUSTOM_VENC_RESOLUTION_T *peResolution);

/******************************************************************************
* Macro to determine multi-codec co-exist
*
* Do not modify it
*******************************************************************************/

#undef CODEC_COUNT_MPEG4
#undef CODEC_COUNT_MJPEG
#undef CODEC_COUNT_H264


#ifdef __MPEG4_ENC_SUPPORT__
#define CODEC_COUNT_MPEG4		1
#else
#define CODEC_COUNT_MPEG4		0
#endif

#ifdef __AVI_ENC_SUPPORT__
#define CODEC_COUNT_MJPEG		1
#else
#define CODEC_COUNT_MJPEG		0
#endif

#ifdef __H264_ENC_SUPPORT__
#define CODEC_COUNT_H264		1
#else
#define CODEC_COUNT_H264		0
#endif

#define CODEC_COUNT_ALL			(CODEC_COUNT_MPEG4 + CODEC_COUNT_MJPEG + CODEC_COUNT_H264)

#if (CODEC_COUNT_ALL > 1)
#define CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
#endif

#ifdef __RECORDER_CUSTOM_CONFIG__
#define CUSTOM_VENC_USE_REDUCED_SELECTION
#endif

#endif  // CUSTOM_VIDEO_ENC_TYPES_H

