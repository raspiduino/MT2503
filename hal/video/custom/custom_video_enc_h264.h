#ifndef CUSTOM_VIDEO_ENC_H264_H
#define CUSTOM_VIDEO_ENC_H264_H


#include "custom_video_enc_if.h"


/******************************************************************************
*
******************************************************************************/
#define CUSTOM_VENC_H264_UNKNOWN_WIDTH                 0
#define CUSTOM_VENC_H264_UNKNOWN_HEIGHT                0
#define CUSTOM_VENC_H264_UNKNOWN_TABLE_ENTRIES         0xFFFF
#define CUSTOM_VENC_H264_UNKNOWN_TABLE_INDEX           0xFFFF


/******************************************************************************
*
******************************************************************************/
typedef struct
{
    kal_uint16 u2Width;
    kal_uint16 u2Height;
    kal_uint16 u2TableEntries;
    kal_uint16 u2TableIndex;
    CUSTOM_VENC_RESOLUTION_T eResolution;
    CUSTOM_VENC_QUALITY_T eQuality;
    CUSTOM_VENC_STORAGE_T eStorage;
    CUSTOM_VENC_CODEC_T eCodec;
} CUSTOM_VENC_H264_MGR_T;


/******************************************************************************
* Function prototypes
******************************************************************************/
extern CUSTOM_VENC_ERROR_T CustomVenc_GetH264CtrlFunction(PFN_CUSTOM_VENC_CTRL *ppfnCustomVencCtrl);


#endif  // CUSTOM_VIDEO_ENC_H264_H

