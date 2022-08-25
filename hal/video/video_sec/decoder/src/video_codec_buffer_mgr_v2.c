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
 *  video_codec_buffer_mgr_v2.c
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
 *
 ****************************************************************************/

#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__
#include "kal_general_types.h"
#include "video_codec_buffer_mgr_v2.h"
#include "video_codec_mem_v2.h"
#include "kal_public_api.h"

#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VEDEC_ROCODE", rodata = "DYNAMIC_CODE_VEDEC_RODATA"
#endif

static kal_uint8 _VideoDecoderGetAvailableBufferIdx(VIDEO_YUV_BUFFER_T* prBufferMgr)
{
    kal_uint32 u4Result;
    kal_uint8  u1Pos;

    u4Result = prBufferMgr->u4VideoDecoderBufferMask &
              (prBufferMgr->u4VideoDecoderBufferRefBitMap &
               prBufferMgr->u4VideoDecoderBufferDisplayBitMap);

    BGFindFirstValid(u4Result, u1Pos);
    if (u1Pos == MAGIC_POS)
    {
        ASSERT(0);
    }
    BGInvalidate(prBufferMgr->u4VideoDecoderBufferRefBitMap, u1Pos);
    BGInvalidate(prBufferMgr->u4VideoDecoderBufferDisplayBitMap, u1Pos);

    prBufferMgr->u4VideoDecoderBufferAvailable =
        prBufferMgr->u4VideoDecoderBufferRefBitMap &
        prBufferMgr->u4VideoDecoderBufferDisplayBitMap;

    return u1Pos;
}


///////////////////////////////////////////////////////
//      YUV buffer management
///////////////////////////////////////////////////////


kal_uint32 VideoDecoderGetAvailableDisplayNumber(VIDEO_YUV_BUFFER_T* prBufferMgr)
{
    kal_uint32 u4Counter = 0;
    kal_uint32 i = 0;
    for (;i<prBufferMgr->u4TotalNum;i++)
    {
        kal_uint32 u4BitMask = (0x1<<i);
        if (!(u4BitMask & prBufferMgr->u4VideoDecoderBufferDisplayBitMap))
        {
            u4Counter++;
        }
    }

    return u4Counter;
    
    //return prBufferMgr->u4CurrentDisplayNum;
}

kal_uint32 VideoDecoderGetRealAvailableDisplayNumber(VIDEO_YUV_BUFFER_T* prBufferMgr)
{
    return prBufferMgr->u4CurrentDisplayNum;
}

kal_uint32 VideoDecoderGetAvailableYUVNumber(VIDEO_YUV_BUFFER_T* prBufferMgr)
{
    kal_uint32 u4Counter = 0;
    kal_uint32 i = 0;
    for (;i<prBufferMgr->u4TotalNum;i++)
    {
        kal_uint32 u4BitMask = (0x1<<i);
        if ((u4BitMask) & (prBufferMgr->u4VideoDecoderBufferRefBitMap) & (prBufferMgr->u4VideoDecoderBufferDisplayBitMap))
        {
            u4Counter++;
        }
    }

    return u4Counter;
}


/******************************************************************************
* Set the "reference", "display", "mask", and "available" bitmaps to the
* default value.
*
* Leroy: bad naming (change the name to VideoDecoderResetYUVBitmaps())
*
* Side effect: "reference", "display", "mask", and "available" bitmaps
******************************************************************************/
void VideoDecoderResetYUVBuffer(VIDEO_YUV_BUFFER_T *prBufferMgr)
{
    const kal_uint32 u4Bitmap = BGCreate(prBufferMgr->u4TotalNum);

    prBufferMgr->u4VideoDecoderBufferRefBitMap = u4Bitmap;
    prBufferMgr->u4VideoDecoderBufferDisplayBitMap = u4Bitmap;
    prBufferMgr->u4VideoDecoderBufferMask = u4Bitmap;
    prBufferMgr->u4VideoDecoderBufferAvailable = prBufferMgr->u4VideoDecoderBufferRefBitMap & prBufferMgr->u4VideoDecoderBufferDisplayBitMap;
}


/******************************************************************************
* xxx
*
* Side effect:
******************************************************************************/
void VideoDecoderResetYUVBufferDisplay(VIDEO_YUV_BUFFER_T* prBufferMgr)
{
    prBufferMgr->u4VideoDecoderBufferDisplayBitMap = BGCreate(prBufferMgr->u4TotalNum);
    prBufferMgr->u4VideoDecoderBufferAvailable = prBufferMgr->u4VideoDecoderBufferRefBitMap & prBufferMgr->u4VideoDecoderBufferDisplayBitMap;
}


/******************************************************************************
* Calculate the number of YUV frames that can be accommodated in the YUV buffer.
* Set the YUV buffer to the default values.  Finally, reset the bitmaps
* associated to the YUV buffer management.
*
* Side effect: YUV buffer and the associated bitmaps
******************************************************************************/
kal_uint32 VideoDecoderInitYUVBuffer(kal_uint8 *pu1StartAddr, kal_uint32 u4BufferSize,
        kal_uint32 u4FrameSize, VIDEO_YUV_BUFFER_T *prBufferMgr)
{
    // kal_bool fgRet = KAL_TRUE;
    kal_uint8 u1Index;
    kal_uint8 *pu1CurAddr;
    const kal_uint32 u4Frames = u4BufferSize / u4FrameSize;

    if (u4Frames < VIDEO_DECODER_MAX_YUV_BUF_NUM)
    {
        prBufferMgr->u4TotalNum = u4Frames;
    }
    else
    {
        prBufferMgr->u4TotalNum = VIDEO_DECODER_MAX_YUV_BUF_NUM;
    }

    pu1CurAddr = pu1StartAddr;
    for (u1Index = 0; u1Index < prBufferMgr->u4TotalNum; u1Index++)
    {
        prBufferMgr->pau1Buff[u1Index] = pu1CurAddr;
        pu1CurAddr += u4FrameSize;
        //Set YUV to black, supposed YUV420
        kal_mem_set((void*)(prBufferMgr->pau1Buff[u1Index]), 0, ((u4FrameSize << 1) / 3));
        kal_mem_set((void*)(prBufferMgr->pau1Buff[u1Index] + ((u4FrameSize << 1) / 3)), 128, (u4FrameSize / 3));
    }

    kal_mem_set((void*)(&prBufferMgr->au1BuffDisplayCount[0]), 0, VIDEO_DECODER_MAX_YUV_BUF_NUM * sizeof(prBufferMgr->au1BuffDisplayCount[0]));
    prBufferMgr->u4CurrentDisplayNum = 0;

    VideoDecoderResetYUVBuffer(prBufferMgr);

    prBufferMgr->fgInit = KAL_TRUE;

    return prBufferMgr->u4TotalNum;
}

void VideoDecoderDeInitYUVBuffer(VIDEO_YUV_BUFFER_T *prBufferMgr)
{
    prBufferMgr->fgInit = KAL_FALSE;
}

kal_bool VideoDecIsYUVBufferInit(VIDEO_YUV_BUFFER_T *prBufferMgr)
{
    return prBufferMgr->fgInit;
}

kal_uint32 VideoDecGetTotalYUVNumber(VIDEO_YUV_BUFFER_T *prBufferMgr)
{
    return prBufferMgr->u4TotalNum;
}

/******************************************************************************
* xxx
*
* Side effect:
******************************************************************************/
kal_uint8* VideoDecGetYUVBuffer(VIDEO_YUV_BUFFER_T *prBufferMgr)
{
    kal_uint8 u1Index = _VideoDecoderGetAvailableBufferIdx(prBufferMgr);

    if (u1Index < VIDEO_DECODER_MAX_YUV_BUF_NUM)
    {
        ASSERT(prBufferMgr->au1BuffDisplayCount[u1Index] == 0);
        prBufferMgr->au1BuffDisplayCount[u1Index]++;
        prBufferMgr->u4CurrentDisplayNum++;
        
        return prBufferMgr->pau1Buff[u1Index];
    }
    else
    {
        ASSERT(0);
        return prBufferMgr->pau1Buff[0];
    }
}


/******************************************************************************
* xxx
*
* Side effect:
******************************************************************************/
kal_uint8 VideoDecoderGetYUVBufferIdx(kal_uint8 *pu1Addr,VIDEO_YUV_BUFFER_T *prBufferMgr)
{
    kal_uint8 u1Pos;

    if (pu1Addr == NULL)
    {
        ASSERT(0);
    }

    for (u1Pos = 0; u1Pos < prBufferMgr->u4TotalNum ; u1Pos++)
    {
        if (prBufferMgr->pau1Buff[u1Pos] == pu1Addr)
        {
            break;
        }
    }

    if (u1Pos == prBufferMgr->u4TotalNum)
    {
        ASSERT(0);
    }

    return u1Pos;
}


/******************************************************************************
* xxx
*
* Side effect:
******************************************************************************/
kal_bool VideoDecYUVBufRefFree(kal_uint8 *pu1Addr, VIDEO_YUV_BUFFER_T *prBufferMgr)
{
    kal_uint8 u1Pos;

    u1Pos = VideoDecoderGetYUVBufferIdx(pu1Addr, prBufferMgr);
    BGValidate(prBufferMgr->u4VideoDecoderBufferRefBitMap, u1Pos);

    prBufferMgr->u4VideoDecoderBufferAvailable = prBufferMgr->u4VideoDecoderBufferRefBitMap & prBufferMgr->u4VideoDecoderBufferDisplayBitMap;

    return KAL_TRUE;
}

void VideoDecYUVBufAddDisplayCount(kal_uint8 *pu1Addr, VIDEO_YUV_BUFFER_T *prBufferMgr)
{
    kal_uint8 u1Pos;

    u1Pos = VideoDecoderGetYUVBufferIdx(pu1Addr, prBufferMgr);
    prBufferMgr->au1BuffDisplayCount[u1Pos]++;    
    prBufferMgr->u4CurrentDisplayNum++;
    BGInvalidate(prBufferMgr->u4VideoDecoderBufferDisplayBitMap, u1Pos);
    
    // kal_uint8 can only count 255, repeating frame number should not be larger than this number
    ASSERT(prBufferMgr->au1BuffDisplayCount[u1Pos] < 255);
}

/******************************************************************************
* xxx
*
* Side effect:
******************************************************************************/
kal_bool VideoDecYUVBufDisFree(kal_uint8 *pu1Addr, VIDEO_YUV_BUFFER_T *prBufferMgr)
{
    kal_uint8 u1Pos;

    u1Pos = VideoDecoderGetYUVBufferIdx(pu1Addr, prBufferMgr);
    prBufferMgr->au1BuffDisplayCount[u1Pos]--;
    prBufferMgr->u4CurrentDisplayNum--;

    if (prBufferMgr->au1BuffDisplayCount[u1Pos] == 0)
    {
        BGValidate(prBufferMgr->u4VideoDecoderBufferDisplayBitMap, u1Pos);
    }

    prBufferMgr->u4VideoDecoderBufferAvailable = prBufferMgr->u4VideoDecoderBufferRefBitMap & prBufferMgr->u4VideoDecoderBufferDisplayBitMap;

    return KAL_TRUE;
}


///////////////////////////////////////////////////////
//      Reference & Display Bit-map Management
///////////////////////////////////////////////////////

kal_bool VideoDecoderCheckAvailability(VIDEO_YUV_BUFFER_T* prBufferMgr)
{
    kal_uint32 u4Result;

    u4Result = prBufferMgr->u4VideoDecoderBufferMask &
              (prBufferMgr->u4VideoDecoderBufferRefBitMap &
               prBufferMgr->u4VideoDecoderBufferDisplayBitMap);

    if(u4Result && 
        (prBufferMgr->u4CurrentDisplayNum < VIDEO_DECODER_MAX_YUV_BUF_NUM))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

kal_uint32 VideoDecoderGetRepeatedYUVNumber(VIDEO_YUV_BUFFER_T* prBufferMgr)
{
    kal_uint32 u4Counter = 0;
    kal_uint32 i = 0;
    for (;i<prBufferMgr->u4TotalNum;i++)
    {
    	if (prBufferMgr->au1BuffDisplayCount[i]>1)
        {
        	u4Counter += (prBufferMgr->au1BuffDisplayCount[i]-1);        	
        }    	
    }

    return u4Counter;
}

#ifdef __VE_DCM_WITH_COMPRESSION__
#pragma arm section code, rodata
#endif

#endif /* __VE_VIDEO_ARCHI_V2__ */
