/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   video_codec_if_v2.h
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *
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
 *
 *
 *
 ****************************************************************************/
#ifndef VIDEO_DECODER_CODEC_IF_V2_H
#define VIDEO_DECODER_CODEC_IF_V2_H

#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__

#include "kal_general_types.h"
#include "video_types_v2.h"
#include "video_codec_type_v2.h"
#include "drv_features_chip_select.h"

//#define DECODER_TEST
/***************************************************
*
*   ReDefine APIs from SS
*
***************************************************/
#if defined(__VE_MTK_TARGET__)
#define DCM_LOAD_MTK_TARGET(v1, v2, v3) DCM_Load(v1, v2, v3)
#define DCM_UNLOAD_MTK_TARGET(v1) DCM_Unload(v1)
#else
#define DCM_LOAD_MTK_TARGET(v1, v2, v3) do {} while (0)
#define DCM_UNLOAD_MTK_TARGET(v1) do {} while (0)
#endif//(__VE_MTK_TARGET__)

/***************************************************
*
*   Chip definitions and Series definitions
*
***************************************************/
#if defined(MT6236) || defined(MT6236B)
#define MT6236_CODEC_SERIES
#elif defined(MT6253) || defined(MT6253T)
#define MT6253_CODEC_SERIES
#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
#define MT6253EL_CODEC_SERIES
#elif defined(MT6256)
#define MT6256_CODEC_SERIES
#elif defined(MT6276)
#define MT6276_CODEC_SERIES
#elif defined(MT6235) || defined(MT6235B)
#define MT6235_CODEC_SERIES
#endif

typedef struct
{
    kal_uint32  u4MaxWidth;
    kal_uint32  u4MaxHeight;
    //kal_uint32  u4MaxResolutionDefine;
    kal_uint64  u8MaxResolution;
} MPEG4_DECODER_CUSTOM_SETTING_T;

typedef struct
{
    kal_uint32  u4MaxWidth;
    kal_uint32  u4MaxHeight;
    //kal_uint32  u4MaxResolutionDefine;
    kal_uint32  u4DPBSize;
    kal_uint64  u8MaxResolution;

} H264_DECODER_CUSTOM_SETTING_T;

typedef struct
{
    //kal_uint32  u4MaxWidth;
    //kal_uint32  u4MaxHeight;
    kal_uint32  u4MaxResolutionDefine;
    kal_uint64  u8MaxResolution;
} RV9_DECODER_CUSTOM_SETTING_T;

typedef struct
{
    kal_uint32  u4MaxWidth;
    kal_uint32  u4MaxHeight;
    //kal_uint32  u4MaxResolutionDefine;
    kal_uint64  u8MaxResolution;
} MJPEG_DECODER_CUSTOM_SETTING_T;

typedef struct
{
    kal_uint32 u4InternalSize;
    kal_uint32 u4ExternalSize;
} VIDEO_CODEC_MEMORY_T;

typedef struct
{
    //input
    kal_uint32 u4Width;
    kal_uint32 u4Height;

    //output
    kal_uint32 u4InternalSize;
    kal_uint32 u4ExternalSize;
} VIDEO_ENC_MEMORY_T;


typedef struct
{
    kal_uint8 *pu1ParamStream;
    kal_uint32 u4ParamLength;
    kal_uint32 *pu4Width;
    kal_uint32 *pu4Height;
} VIDEO_DECODER_QUERY_FRAME_SIZE_TYPE_T;


typedef struct
{
    kal_bool    fgUpdateTime;
    kal_bool    fgYUVSeperated;
    kal_bool    fgRepeatLastFrame;
    kal_bool    fgNotDisplay;
    kal_bool    fgEOF;

    kal_uint64 u8TimeStamp;

    kal_uint16 u2FrameWidth;
    kal_uint16 u2FrameHeight;
    kal_uint16 u2ClipTop;
    kal_uint16 u2ClipBottom;
    kal_uint16 u2ClipLeft;
    kal_uint16 u2ClipRight;

    VIDEO_CODEC_FRAME_TYPE_T eFrameType;

    kal_uint8* pu1YStartAddr;
    kal_uint8* pu1UStartAddr;
    kal_uint8* pu1VStartAddr;

    kal_int32  i4AspectRatioWidth;
    kal_int32  i4AspectRatioHeight;

} VIDEO_DECODER_PRIVATE_OUTPUT_T;


typedef struct
{
    kal_uint32 u4SupportWidth;
    kal_uint32 u4SupportHeight;
    kal_uint32 u4SupportResolution;
    kal_uint32 u4SupportProfile;
    kal_uint32 u4SupportLevel;
} VIDEO_DECODER_CODEC_CAPABILITY_T;


typedef struct
{
    VIDEO_DECODER_CODEC_ERROR_T (*pfnOpen)(void);
    VIDEO_DECODER_CODEC_ERROR_T (*pfnInit)(void);
    VIDEO_DECODER_CODEC_ERROR_T (*pfnGetParameter)(VIDEO_DECODER_PARAM_TYPE_T , void *);
    VIDEO_DECODER_CODEC_ERROR_T (*pfnSetParameter)(VIDEO_DECODER_PARAM_TYPE_T , void *);
    VIDEO_DECODER_CODEC_ERROR_T (*pfnDecodeOneUnit)(VIDEO_BUFFERHEADER_TYPE_T * );
    VIDEO_DECODER_CODEC_ERROR_T (*pfnDeInit)(void);
    VIDEO_DECODER_CODEC_ERROR_T (*pfnClose)(void);
    VIDEO_DECODER_CODEC_ERROR_T (*pfnGetNextDisplay)(kal_uint8**, VIDEO_DECODER_PRIVATE_OUTPUT_T*);
} VIDEO_DECODER_CODEC_API_T;


extern void* VideoDecoderMalloc(kal_uint32 u4Size);
extern void VideoDecoderFree(void *pVoid);
extern void* VideoDecoderMallocCacheLineAlign(kal_uint32 u4Size, kal_bool fgCacheable);
extern void VideoDecoderFreeCacheLineAlign(void *pVoid);
extern void* VideoDecoderMemSet(void *pVoid, kal_int32 u4Value, kal_uint32 u4Size);
extern void VideoDecoderMemCopy(void *pDest, void *pSrc, kal_uint32 u4Size);
extern kal_uint32 VideoDecoderIntBuffer(kal_uint32 u4RequestSize);
extern void VideoDecoderResetIntBuffer(void);
extern kal_bool VideoDecoderCheckIntBuffer(void);

extern kal_bool VideoDecoderSetYUVBuffer(kal_uint32* pu4Width, kal_uint32* pu4Height, kal_uint8 u1Alignment, kal_uint32 u4Offset, kal_uint32 u4ReduceLength);
extern kal_uint8* VideoDecoderGetYUVBuffer(void);
extern kal_bool VideoDecoderRefFreeYUVBuffer(kal_uint8* pu1BufferAddr);
extern kal_bool VideoDecoderDisplayFreeYUVBuffer(kal_uint8* pu1BufferAddr);

extern kal_uint32 VideoDecoderGetAvailableYUV(void);
extern kal_uint32 VideoDecoderGetTotalYUV(void);
extern kal_uint32 VideoDecoderGetAvailableDisplay(void);
extern kal_uint32 VideoDecoderGetRealAvailableDisplay(void);
extern kal_bool VideoDecodecIsYUVBufferInit(void);

extern void VideoDecoderReturnBitstream(kal_uint8* pu1Addr, kal_uint32 u4Length);
extern void VideoDecoderGetCustomSetting(void* pVoid);

extern kal_uint64 VideoDecoderGetCurrPlayTime(void);
extern kal_uint64 VideoDecoderGetLastDeliverTime(void);
extern void VideoDecoderFreeIntMem(kal_uint8* pu1FreeAddr, kal_uint32 u4FreeSize);
extern void VideoDecoderGetResizerFactor(VIDEO_RESIZE_FACTOR_TYPE_T* pResizeFactor);
extern VIDEO_CONTAINER_INFO_T* VideoDecoderGetContainerInfo(void);

// --------------- VT support begings ---------------
// FIXME (Leroy): Replace MAX_NUM_OF_VIDEO_PACKETS with MP4_MAX_PACKET_COUNT in the encoder.
#define VIDEO_ENCODER_MAX_PKTS_IN_A_CHASSIS 99
#define VIDEO_ENCODER_MAX_CHASSIS_NUM       (32 + 1)

typedef struct
{
    kal_uint32 u4Addr;
    kal_uint32 u4Size;
} VIDEO_ENCODER_PACKET_INFO_T;


// Note the first two items in the next structure must be (in order):
// 1. number of Packets
// 2. pointer to the packet info
typedef struct
{
    kal_uint32 u4NumOfPkts;
    VIDEO_ENCODER_PACKET_INFO_T *parPktInfo;
    VIDEO_ENCODER_CHASSIS_STATUS_T eChassisStatus;
    VIDEO_ENCODER_PACKET_INFO_T arPktInfo[VIDEO_ENCODER_MAX_PKTS_IN_A_CHASSIS];
} VIDEO_ENCODER_CHASSIS_T;


typedef struct
{
    VIDEO_ENCODER_CHASSIS_T *prChassisStart;
    VIDEO_ENCODER_CHASSIS_T *prChassisEnd;
    VIDEO_ENCODER_CHASSIS_T *prChassisRp;
    VIDEO_ENCODER_CHASSIS_T *prChassisWp;
    kal_uint32 u4MaxChassis;            // max set/number of Chassis
    kal_uint32 u4UsedChassis;           // current number of chassis used
    // kal_uint32 u4UsedAndReservedChassis;
    kal_uint32 u4BufferSize;            // buffer size
} VIDEO_ENCODER_CHASSIS_MGR_T;


typedef struct
{
    VIDEO_CODEC_FRAME_TYPE_T eFrameType;
    kal_uint8*  pu1BitstreamAddr;
    kal_uint32 u4BitstreamLength;
    kal_bool fgEndOfFrame;
#ifdef __VE_VIDEO_VT_SUPPORT__
    VIDEO_ENCODER_CHASSIS_T *prChassis;
#endif  // __VE_VIDEO_VT_SUPPORT__
#if defined(__VE_ENABLE_CODEC_ADJUST_TIME__)
    kal_bool    fgUpdateTimeStamp;
    kal_uint64  u8TimeStamp;
#endif
} VIDEO_ENCODER_PRIVATE_OUTPUT_T;
// --------------- VT support ends ---------------

typedef struct
{
    VIDEO_ENCODER_CODEC_ERROR_T (*pfnOpen)(void);
    VIDEO_ENCODER_CODEC_ERROR_T (*pfnInit)(void);
    VIDEO_ENCODER_CODEC_ERROR_T (*pfnGetParameter)(VIDEO_ENCODER_PARAM_TYPE_T , void *);
    VIDEO_ENCODER_CODEC_ERROR_T (*pfnSetParameter)(VIDEO_ENCODER_PARAM_TYPE_T , void *);
    VIDEO_ENCODER_CODEC_ERROR_T (*pfnGenerateHeader)(void);
    VIDEO_ENCODER_CODEC_ERROR_T (*pfnEncodeOneUnit)(VIDEO_BUFFERHEADER_TYPE_T *);
    VIDEO_ENCODER_CODEC_ERROR_T (*pfnDeInit)(void);
    VIDEO_ENCODER_CODEC_ERROR_T (*pfnClose)(void);
    VIDEO_ENCODER_CODEC_ERROR_T (*pfnGetNextBitstream)(kal_uint8**, VIDEO_ENCODER_PRIVATE_OUTPUT_T*);
} VIDEO_ENCODER_CODEC_API_T;

typedef void (*pfnReleaseFrame_t)(kal_uint8 *);   //extern void VideoEncoderReleaseYUV(kal_uint8 *pu1Buff);
typedef void (*pfnEncoderPaused_t)(kal_uint8 *);  //extern void VideoEncoderPaused(kal_uint8* pu1ReadPtr);
typedef void (*pfnGenBitstream_t)(void);          //extern void VideoEncoderGenBistream(void)

typedef struct
{
    pfnReleaseFrame_t   pfnReleaseFrame;
    pfnEncoderPaused_t  pfnEncoderPaused;
    pfnGenBitstream_t   pfnGenBitstream;
    PFN_VCALL_GET_UPLINKINFO_T  pfnGetLinkInfo;
}VIDEO_ENCODER_ADAPT_CALLBACK_T;

extern void* VideoEncoderMallocAligned(kal_uint32 u4Size);
extern void VideoEncoderFreeAligned(void* pVoid);

extern void* VideoEncoderMallocCacheLineAlign(kal_uint32 u4Size, kal_bool fgCacheable);
extern void VideoEncoderFreeCacheLineAlign(void *pVoid);

extern void* VideoEncoderMemSet(void *pVoid, kal_int32 u4Value, kal_uint32 u4Size);
extern void VideoEncoderMemCopy(void *pDest, void *pSrc, kal_uint32 u4Size);

extern void VideoEncoderResetIntMem(void);
extern kal_uint32 VideoEncoderGetBitstreamBufferAvailableSize(void);

#endif /* __VE_VIDEO_ARCHI_V2__ */
#endif /* VIDEO_CODEC_IF_V2_H */

