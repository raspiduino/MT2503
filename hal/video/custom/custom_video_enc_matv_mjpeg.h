/*****************************************************************************
 * Filename:
 * ---------
 * custom_video_enc_matv_mjpeg.h
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
#ifndef CUSTOM_VIDEO_ENC_MATV_MJPEG_H
#define CUSTOM_VIDEO_ENC_MATV_MJPEG_H


#include "custom_video_enc_if.h"


/******************************************************************************
*
******************************************************************************/
#define CUSTOM_VENC_MATV_MJPEG_UNKNOWN_WIDTH                  0
#define CUSTOM_VENC_MATV_MJPEG_UNKNOWN_HEIGHT                 0
#define CUSTOM_VENC_MATV_MJPEG_UNKNOWN_TABLE_ENTRIES          0xFFFF
#define CUSTOM_VENC_MATV_MJPEG_UNKNOWN_TABLE_INDEX            0xFFFF

#define CUSTOM_VENC_MATV_MJPEG_TV_FORMAT_NTSC                 1
#define CUSTOM_VENC_MATV_MJPEG_TV_FORMAT_PAL                  0

#define VENC_MATV_MJPEG_ASSERT(expr) do {if(!(expr)) ASSERT(0); } while (0)

/******************************************************************************
*
******************************************************************************/
typedef struct
{
    kal_uint16 u2Width;
    kal_uint16 u2Height;
    kal_uint16 u2TableEntries;
    kal_uint16 u2TableIndex;
    kal_uint16 u2TVFormat;
    CUSTOM_VENC_RESOLUTION_T eResolution;
    CUSTOM_VENC_QUALITY_T eQuality;
    CUSTOM_VENC_STORAGE_T eStorage;
    CUSTOM_VENC_CODEC_T eCodec;
} CUSTOM_VENC_MATV_MJPEG_MGR_T;


/******************************************************************************
* Function prototypes
******************************************************************************/
extern CUSTOM_VENC_ERROR_T CustomVenc_GetMatvMjpegCtrlFunction(PFN_CUSTOM_VENC_CTRL *ppfnCustomVencCtrl);


#endif  // CUSTOM_VIDEO_ENC_MATV_MJPEG_H

