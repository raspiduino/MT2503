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
 *  video_codec_buffer_mgr_v2.h
 *
 * Project:
 * --------
 *	Video Architecture 2
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
 *
 ****************************************************************************/

#ifndef VIDEO_CODEC_BUFFER_MGR_V2_H
#define VIDEO_CODEC_BUFFER_MGR_V2_H

#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__

#include "kal_general_types.h"
#include "video_codec_mem_v2.h"

/********************************************
*
*   Definitions
*
********************************************/



///////////////////////////////////////////////////////
//      YUV buffer management
///////////////////////////////////////////////////////

typedef struct
{
    kal_uint8  *pau1Buff[VIDEO_DECODER_MAX_YUV_BUF_NUM];
    kal_uint8   au1BuffDisplayCount[VIDEO_DECODER_MAX_YUV_BUF_NUM];
    kal_uint32 u4CurrentDisplayNum;
    kal_uint32 u4TotalNum;
    kal_uint32 u4VideoDecoderBufferRefBitMap;
    kal_uint32 u4VideoDecoderBufferDisplayBitMap;
    kal_uint32 u4VideoDecoderBufferMask;
    kal_uint32 u4VideoDecoderBufferAvailable;
    kal_bool fgInit;
} VIDEO_YUV_BUFFER_T;

kal_uint32 VideoDecGetTotalYUVNumber(VIDEO_YUV_BUFFER_T *prBufferMgr);
kal_bool VideoDecIsYUVBufferInit(VIDEO_YUV_BUFFER_T *prBufferMgr);
void VideoDecoderDeInitYUVBuffer(VIDEO_YUV_BUFFER_T *prBufferMgr);
kal_uint32 VideoDecoderInitYUVBuffer(kal_uint8 *pu1StartAddr, kal_uint32 u4BufferSize, kal_uint32 u4FrameSize, VIDEO_YUV_BUFFER_T *prBufferMgr);
void VideoDecoderResetYUVBuffer(VIDEO_YUV_BUFFER_T* prBufferMgr);
void VideoDecoderResetYUVBufferDisplay(VIDEO_YUV_BUFFER_T* prBufferMgr);
kal_uint8* VideoDecGetYUVBuffer(VIDEO_YUV_BUFFER_T* prBufferMgr);
kal_bool VideoDecYUVBufRefFree(kal_uint8 *pu1Addr, VIDEO_YUV_BUFFER_T* prBufferMgr);
kal_bool VideoDecYUVBufDisFree(kal_uint8 *pu1Addr, VIDEO_YUV_BUFFER_T* prBufferMgr);
kal_uint8 VideoDecoderGetYUVBufferIdx(kal_uint8 *pu1Addr, VIDEO_YUV_BUFFER_T* prBufferMgr);
kal_bool VideoDecoderCheckAvailability(VIDEO_YUV_BUFFER_T* prBufferMgr);
//kal_uint8 VideoDecoderGetAvailableBufferIdx(VIDEO_YUV_BUFFER_T* prBufferMgr);
kal_uint32 VideoDecoderGetAvailableYUVNumber(VIDEO_YUV_BUFFER_T* prBufferMgr);
kal_uint32 VideoDecoderGetAvailableDisplayNumber(VIDEO_YUV_BUFFER_T* prBufferMgr);
kal_uint32 VideoDecoderGetRealAvailableDisplayNumber(VIDEO_YUV_BUFFER_T* prBufferMgr);
void VideoDecYUVBufAddDisplayCount(kal_uint8 *pu1Addr, VIDEO_YUV_BUFFER_T *prBufferMgr);
kal_uint32 VideoDecoderGetRepeatedYUVNumber(VIDEO_YUV_BUFFER_T* prBufferMgr);

///////////////////////////////////////////////////////
//      REF & DIS Bit-map management
///////////////////////////////////////////////////////

typedef kal_uint32 BITGROUP_T;     // bit group
typedef kal_uint32 ARX;
typedef kal_uint32 U32;
typedef kal_int32 Word32;
//typedef unsigned long long            U40;
typedef kal_uint64                      U40;
typedef signed short int                S16;
#define NUM_VALID_BITS_IN_BITGROUP      32
#define __ASSEMBLY_OPTIMIZE_            0
#define MAGIC_POS                       255

__inline Word32 clz(Word32 absx)
{
    Word32 lz;
#if __ASSEMBLY_OPTIMIZE_
    __asm { clz lz, absx; }
#else
    U32 j = 1U << 31;
    for(lz=0; lz<32; lz++, j>>=1) if( absx&j ) break;
#endif
    return lz;
}

__inline ARX bitrev_rN_dis(ARX VAR1)
{
    S16 i;
    U32 result;
    U32 input = (U32)VAR1;
    U32 j = 1U << (sizeof(ARX)*8 - 1);
    for(i=0, result = 0; i<sizeof(ARX)*8; i++, j >>= 1, input >>= 1)
    {
        if(input & 1)
        {
            result |= j;
        }
    }
    return (ARX)result;
}

__inline int exp_acW_acZ(U32 VAR1)
{
    return clz(VAR1) - 1;
}

__inline int mov_arX_acZ_u(ARX VAR1)
{
    return (unsigned int)VAR1;
}

#define BGMAX     ((BITGROUP_T)(1U << (NUM_VALID_BITS_IN_BITGROUP - 1)))
#define BGMIN     ((BITGROUP_T)(1U))
#define BGConvertFromLittle(_val) (BITGROUP_T)mov_arX_acZ_u(bitrev_rN_dis((ARX)(_val)))
#define INT2BG(_i)   ((U32)(_i))
#define BGCreate(_n) INT2BG(((U40)1 << (_n)) - 1)
#define BGInvalidateAll(_bg) do { (_bg) = 0; } while(0)
#define BGInvalidate(_bg, _pos) do { (_bg) &= (BITGROUP_T)(~(BGMIN << (U32)(_pos))); } while(0)
#define BGValidate(_bg, _pos) do { (_bg) |= (BITGROUP_T)(BGMIN << (U32)(_pos)); } while(0)
#define BGIsValid(_bg, _pos) (((BITGROUP_T)(_bg)&(BITGROUP_T)(BGMIN << (U32)(_pos))) != 0)
#define BGFindFirstValid(_bg, _pos) do{ \
    BITGROUP_T __x = (BITGROUP_T)(_bg);\
    if(__x != 0) { _pos = exp_acW_acZ((int)BGConvertFromLittle(__x)) - (31 - NUM_VALID_BITS_IN_BITGROUP); } \
    else { _pos = MAGIC_POS; } \
} while(0)
#define BGFindFirstValidMaskAny(_bg, _mask, _pos) do{ \
    BITGROUP_T __x; \
    __x = (BITGROUP_T)(_bg) & INT2BG(_mask); \
    if(__x != 0) { _pos = exp_acW_acZ((int)BGConvertFromLittle(__x)) - (31 - NUM_VALID_BITS_IN_BITGROUP); } \
    else { _pos = MAGIC_POS; } \
} while(0)
#define BGFindFirstValidMaskAll(_bg, _mask, _pos) do{ \
    BITGROUP_T __x, __m; \
    __m = INT2BG(_mask); \
    __x = (BITGROUP_T)(_bg) & __m; \
    if(__x == __m) { BGFindFirstValid(__m, _pos); } \
    else { _pos = MAGIC_POS; } \
} while(0)


#endif /* __VE_VIDEO_ARCHI_V2__  */
#endif /* VIDEO_CODEC_BUFFER_MGR_V2_H */
