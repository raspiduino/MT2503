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
 *   open_api_h264_sw_driver.c
 *
 * Project:
 * --------
 *  MTK
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
 * removed!
 *
 *
 ****************************************************************************/
#include "drv_comm.h"

#ifdef __H264_DEC_SW_SUPPORT__
#ifdef __H264_SW_OPEN_API_SUPPORT__
#include "kal_release.h"      /* Basic data type */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"      /* Task creation */
#include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */
#include "stack_timer.h"      /* Stack timer */
#include "dcmgr.h"
#include "intrCtrl.h"
#include "H264SwDecApi.h"
#include "vcodec_v2_trc.h"
#include "h264_open_api_video_if.h"
#include "open_api_h264_mem_if.h"

//#define H264SW_OPENAPI_DUMMY_SEI_LENGTH 4
#define H264SW_OPENAPI_EOF 1
#define H264SW_DEC_DPB_SIZE (891*1024)
#define H264SW_QVGA 2
//static kal_uint8 _au1H264DummySei[H264DEC_DUMMY_SEI_LENGTH] = {0x06, 0x00, 0x07, 0x08};

// This macro works only when "x" is 2^n.
#define H264_ROUND_UP_TO_POWER_OF_TWO(data,x)                                 \
    (((kal_uint32)(data) + (kal_uint32)(x) - 1) & ~((kal_uint32)(x) - 1))

typedef struct
{
    kal_bool fgIsCodecInit;
    kal_bool fgBsBufferCacheable;
    kal_bool fgFrmBufferCacheable;
    kal_bool fgFrmBufferSwitch;
    kal_bool fgCropping;
    H264SwDecInst prH264DecInst;
    kal_uint16 u2FrameWidth;
    kal_uint16 u2FrameHeight;
    kal_uint16 u2RealWidth;
    kal_uint16 u2RealHeight;
    kal_uint32 u4BufferSize;
    KAL_ADM_ID pAdmId;
    void (*pfnSetFrameUnReference)(kal_uint32 u4Address);
    void (*pfnOutputOneFrame)(kal_uint32 u4Address, kal_bool fgCorruptedFrame);
    void (*pfnReturnBitstream)(kal_uint32 u4Address);
    kal_uint32 (*pfnGetYUVBuffer)(void);
}H264_SW_OPEN_API_CTRL_T;

static H264_SW_OPEN_API_CTRL_T rH264SwCtrl;

extern kal_uint32 query_opposite_switchable_cacheaddr_ram(kal_uint32 addr);
/*------------------------------------------------------------------------------

    Function name:  H264SwDecMalloc

    Purpose:
        Example implementation of H264SwDecMalloc function. Prototype of this
        function is given in H264SwDecApi.h. This implementation uses
        library function malloc for allocation of memory.

------------------------------------------------------------------------------*/
static void *VideoH264DecMalloc(unsigned int size)
{
    void *ptr = NULL;
    kal_uint32 u4Size;

    if (rH264SwCtrl.pAdmId == NULL)
    {
        ASSERT(0);
    }
    u4Size = H264_ROUND_UP_TO_POWER_OF_TWO(size, 4);

    ptr =  kal_adm_alloc(rH264SwCtrl.pAdmId, u4Size);
    if (ptr == NULL)
    {
        kal_uint32 u4LeftSize = kal_adm_get_total_left_size(rH264SwCtrl.pAdmId);
        EXT_ASSERT(0, u4LeftSize, (kal_uint32)size, 0);
    }
    drv_trace2(TRACE_GROUP_10,OPEN_API_SW_GETMEMORY,size,(kal_uint32)ptr);
    return ptr;
}

/*------------------------------------------------------------------------------

    Function name:  H264SwDecFree

    Purpose:
        Example implementation of H264SwDecFree function. Prototype of this
        function is given in H264SwDecApi.h. This implementation uses
        library function free for freeing of memory.

------------------------------------------------------------------------------*/
static void VideoH264DecFree(void *ptr)
{
    drv_trace1(TRACE_GROUP_10,OPEN_API_SW_FREEMEMORY,(kal_uint32)ptr);
    if (rH264SwCtrl.pAdmId == NULL)
    {
        ASSERT(0);
    }

    if (ptr != NULL)
    {
        kal_adm_free(rH264SwCtrl.pAdmId, (kal_uint8*)ptr);
    }
}

/*------------------------------------------------------------------------------

    Function name:  H264SwDecMemset

    Purpose:
        Example implementation of H264SwDecMemset function. Prototype of this
        function is given in H264SwDecApi.h. This implementation uses
        library function memset to set content of memory area pointed by ptr.

------------------------------------------------------------------------------*/
static void VideoH264DecMemset(void *ptr, int c, unsigned int size)
{
    void *rv = NULL;

    if (ptr != NULL)
    {
        rv = kal_mem_set(ptr, (kal_int32)c, (kal_uint32)size);
    }
    return;
}

/*------------------------------------------------------------------------------

    Function name:  H264SwDecMemcpy

    Purpose:
        Example implementation of H264SwDecMemcpy function. Prototype of this
        function is given in H264SwDecApi.h. This implementation uses
        library function memcpy to copy src to dest.

------------------------------------------------------------------------------*/
static void VideoH264DecMemcpy(void *dest, void *src, unsigned int count)
{
    ASSERT(dest != NULL);
    ASSERT(src != NULL);

    kal_mem_cpy(dest, src, count);
}


static void *VideoH264DecMallocDPB(void)
{
    kal_uint32 u4Buffer;
    kal_bool fgCurFrmBufferCacheable;

    if (!rH264SwCtrl.pfnGetYUVBuffer)
    {
        ASSERT(0);
        return (void *)NULL;
    }

    u4Buffer = rH264SwCtrl.pfnGetYUVBuffer();
    drv_trace1(TRACE_GROUP_10, OPEN_API_GETYUVBUFFER, u4Buffer);
    //must be 32 alignment
    if (u4Buffer & 0x1F)
    {
        drv_trace1(TRACE_GROUP_8, H264DEC_ALIGN_ERROR, u4Buffer);
        ASSERT(0);
        return (void *)NULL;
    }

    fgCurFrmBufferCacheable = OpenAPIIsExtBufferCacheable(u4Buffer, rH264SwCtrl.u4BufferSize);

    if (fgCurFrmBufferCacheable)
    {
        ASSERT(0);
    }

    if ((rH264SwCtrl.fgFrmBufferCacheable == KAL_TRUE) && (fgCurFrmBufferCacheable == KAL_FALSE))
    {
        rH264SwCtrl.fgFrmBufferSwitch = KAL_TRUE;
        u4Buffer = OpenAPIExtBufferCacheableSwitch(u4Buffer, rH264SwCtrl.u4BufferSize, OPEN_API_CACHEABLE);
    }
    else if ((rH264SwCtrl.fgFrmBufferCacheable == KAL_FALSE) && (fgCurFrmBufferCacheable == KAL_TRUE))
    {
        rH264SwCtrl.fgFrmBufferSwitch = KAL_TRUE;
        u4Buffer = OpenAPIExtBufferCacheableSwitch(u4Buffer, rH264SwCtrl.u4BufferSize, OPEN_API_NON_CACHEABLE);
    }

    return (void *)u4Buffer;
}

static void VideoH264DecFreeDPB(void *ptr)
{
    kal_uint32 u4Buffer = (kal_uint32)ptr;

    if (!rH264SwCtrl.pfnSetFrameUnReference)
    {
        ASSERT(0);
        return;
    }

    if (u4Buffer)
    {
        if (rH264SwCtrl.fgFrmBufferSwitch == KAL_TRUE)
        {
            u4Buffer = query_opposite_switchable_cacheaddr_ram(u4Buffer);
        }
        drv_trace1(TRACE_GROUP_10,OPEN_API_UNREFERENCEFRAME,u4Buffer);
        rH264SwCtrl.pfnSetFrameUnReference(u4Buffer);
    }
}

static void VideoH264DecFreeDisp(void *ptr)
{
    if (ptr == NULL)
    {
        ASSERT(0);
        return;
    }
    if (rH264SwCtrl.pfnOutputOneFrame)
    {
        drv_trace2(TRACE_GROUP_10,OPEN_API_OUTPUTFRAME, (kal_uint32)ptr,1);
        rH264SwCtrl.pfnOutputOneFrame((kal_uint32)ptr, KAL_TRUE);
    }
}

static void VideoH264DecReturnBitstream(H264SwDecReturnBs *pBs)
{
    if (rH264SwCtrl.pfnReturnBitstream)
    {
        drv_trace1(TRACE_GROUP_10,OPEN_API_RETURNBSBUFFER, (kal_uint32)pBs->pBsAddr);
        rH264SwCtrl.pfnReturnBitstream((kal_uint32)pBs->pBsAddr);
    }
    return;
}

static void VideoH264DecOutputPic(kal_uint32 u4FlushBuffer)
{
    H264SwDecPicture rDecPic;
    kal_uint32 u4OutAddr;

    if (!rH264SwCtrl.pfnOutputOneFrame)
    {
        ASSERT(0);
        return;
    }

    while (H264SwDecNextPicture(rH264SwCtrl.prH264DecInst, &rDecPic,
                                                u4FlushBuffer) == H264SWDEC_PIC_RDY)
    {
   	kal_bool fgError = KAL_FALSE;
        drv_trace1(TRACE_GROUP_8, H264DEC_OUTPUT_IDR, rDecPic.isIdrPicture);
        if (rDecPic.isEOF) break;
        if (rH264SwCtrl.fgFrmBufferSwitch == KAL_TRUE)
        {
            if (rH264SwCtrl.fgFrmBufferCacheable == KAL_TRUE)
            {
                u4OutAddr = OpenAPIExtBufferCacheableSwitch((kal_uint32)rDecPic.pOutputPicture,
                                                                rH264SwCtrl.u4BufferSize, OPEN_API_NON_CACHEABLE);
            }
            else
            {
                u4OutAddr = OpenAPIExtBufferCacheableSwitch((kal_uint32)rDecPic.pOutputPicture,
                                                                rH264SwCtrl.u4BufferSize, OPEN_API_CACHEABLE);
            }
        }
        else
        {
            u4OutAddr = (kal_uint32)rDecPic.pOutputPicture;
        }
        if (rDecPic.nbrOfErrMBs > 0)
        {
            fgError = KAL_TRUE;
        }
        drv_trace4(TRACE_GROUP_8, H264DEC_DISPLAY_INFO, u4OutAddr, rDecPic.displayWidth, 
                            rDecPic.displayHeight, u4FlushBuffer);
        drv_trace2(TRACE_GROUP_10,OPEN_API_OUTPUTFRAME, u4OutAddr,0);
        rH264SwCtrl.pfnOutputOneFrame(u4OutAddr, fgError);
    }
}

MEDIA_STATUS_CODE VideoH264DecOpen(void *param)
{
    H264SwDecCapability rDecCap;
    H264SwDecRet rCodecRet;
    H264SwDecMemManageFunc rFunc;
    H264_DEC_INIT_PARAM_TYPE_T *pInitParam = (H264_DEC_INIT_PARAM_TYPE_T*)param;
    kal_uint32 u4IntMemAddr = 0, u4IntMemSize = 0, u4NoReordering = 0;
#if defined(__MTK_TARGET__)
#if defined(MT6236) || defined(MT6236B)
    kal_uint32* pu4TCMBuff_S = NULL;
    kal_uint32 u4ValidTCMSize_S = 0;

    DCM_Load(DYNAMIC_CODE_264DEC_S, &pu4TCMBuff_S, &u4ValidTCMSize_S);
#endif
#endif
    drv_trace0(TRACE_GROUP_8, H264DEC_OPEN);
    drv_trace4(TRACE_GROUP_10, OPEN_API_ENTERVIDEOH264DECOPEN ,pInitParam->ext_mem_addr.p_addr,
        pInitParam->ext_mem_size,pInitParam->int_mem_addr.p_addr,pInitParam->int_mem_size);
    if (pInitParam == NULL)
    {
        drv_trace1(TRACE_GROUP_8, H264DEC_ARGUMENT_ERROR, __LINE__);
        ASSERT(0);
        return VIDEO_ERROR;
    }
    rH264SwCtrl.pAdmId = kal_adm_create((void*)pInitParam->ext_mem_addr.p_addr,
                                                                        pInitParam->ext_mem_size, NULL, KAL_FALSE);
    if (rH264SwCtrl.pAdmId == NULL)
    {
        ASSERT(0);
    }

    if (H264SWDEC_OK != H264SwDecQueryCapability(&rDecCap, H264SW_QVGA))
    {
        ASSERT(0);
    }
    else
    {
        rH264SwCtrl.fgBsBufferCacheable = (rDecCap.isBsCacheable == 1) ? KAL_TRUE : KAL_FALSE;
        rH264SwCtrl.fgFrmBufferCacheable = (rDecCap.isFrameCacheable == 1) ? KAL_TRUE : KAL_FALSE;
#if defined(DRV_FEATURE__MM_INTMEM_IF)         
        u4IntMemAddr = OpenAPIGetIntBuffer(rDecCap.intMemSize);  
        u4IntMemSize = rDecCap.intMemSize;
#else
        u4IntMemAddr = pInitParam->int_mem_addr;
        u4IntMemSize = pInitParam->int_mem_size;
#endif
        
    }

    u4NoReordering = (pInitParam->fgDisplayOrderMode) ? 0 : 1;
    
    drv_trace0(TRACE_GROUP_8, H264DEC_INIT);
    rFunc.Malloc = VideoH264DecMalloc;
    rFunc.Free = VideoH264DecFree;
    rFunc.Memcpy = VideoH264DecMemcpy;
    rFunc.Memset = VideoH264DecMemset;
    rFunc.MallocDPB = VideoH264DecMallocDPB;
    rFunc.FreeDPB = VideoH264DecFreeDPB;
    rFunc.ReturnBitstream = VideoH264DecReturnBitstream;
    rCodecRet = H264SwDecInit(&rH264SwCtrl.prH264DecInst, u4NoReordering, (u8*)u4IntMemAddr, 
                                                u4IntMemSize, (u32)H264SW_DEC_DPB_SIZE, (u32)0, &rFunc);

    if (rCodecRet != H264SWDEC_OK)
    {
        drv_trace1(TRACE_GROUP_8, H264DEC_INIT_ERROR, rCodecRet);
        ASSERT(0);
        return VIDEO_ERROR;
    }

    rH264SwCtrl.fgFrmBufferSwitch = KAL_FALSE;
    rH264SwCtrl.fgIsCodecInit = KAL_TRUE;
    rH264SwCtrl.u2FrameHeight = 0;
    rH264SwCtrl.u2FrameWidth = 0;
    rH264SwCtrl.u2RealHeight = 0;
    rH264SwCtrl.u2RealWidth = 0;
    rH264SwCtrl.u4BufferSize = 0;
    rH264SwCtrl.pfnSetFrameUnReference = pInitParam->pfnSetFrameUnReferenceCallback;
    rH264SwCtrl.pfnOutputOneFrame = pInitParam->pfnOutputOneFrameCallback;
    rH264SwCtrl.pfnGetYUVBuffer = pInitParam->pfnGetYUVBufferCallback;
    rH264SwCtrl.pfnReturnBitstream = pInitParam->pfnReturnBsBufferCallback;

    if ((rH264SwCtrl.pfnSetFrameUnReference == NULL) || (rH264SwCtrl.pfnOutputOneFrame == NULL) ||
        (rH264SwCtrl.pfnGetYUVBuffer == NULL))
    {
        ASSERT(0);
    }

    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE VideoH264DecClose(void)
{
    drv_trace0(TRACE_GROUP_10,OPEN_API_ENTERVIDEOH264DECCLOSE);
    VideoH264DecOutputPic((kal_uint32)H264SW_OPENAPI_EOF);

    if ( rH264SwCtrl.fgIsCodecInit == KAL_TRUE )
    {
        drv_trace0(TRACE_GROUP_8, H264DEC_DEINIT);
        H264SwDecRelease(rH264SwCtrl.prH264DecInst);
    }

    drv_trace0(TRACE_GROUP_8, H264DEC_CLOSE);
    if (rH264SwCtrl.pAdmId)
    {
        kal_adm_delete(rH264SwCtrl.pAdmId);
        rH264SwCtrl.pAdmId = NULL;
    }
    rH264SwCtrl.fgBsBufferCacheable = KAL_FALSE;
    rH264SwCtrl.fgFrmBufferCacheable = KAL_FALSE;
    rH264SwCtrl.fgFrmBufferSwitch = KAL_FALSE;
    rH264SwCtrl.fgIsCodecInit = KAL_FALSE;
    rH264SwCtrl.u2FrameHeight = 0;
    rH264SwCtrl.u2FrameWidth = 0;
    rH264SwCtrl.u2RealHeight = 0;
    rH264SwCtrl.u2RealWidth = 0;
    rH264SwCtrl.u4BufferSize = 0;
    rH264SwCtrl.pfnSetFrameUnReference = NULL;
    rH264SwCtrl.pfnOutputOneFrame = NULL;
    rH264SwCtrl.pfnGetYUVBuffer = NULL;

#if defined(__MTK_TARGET__)
#if defined(MT6236) || defined(MT6236B)
    DCM_Unload(DYNAMIC_CODE_264DEC_S);
#endif
#endif
    return MEDIA_STATUS_OK;
}

H264_DECODE_STATUS_CODE_T VideoH264DecNALu(VIDEO_DECODE_PARAM_T *prParam)
{
    H264SwDecInput rDecInput;
    H264SwDecOutput rDecOutput;
    H264SwDecReturnBs rBsInfo;
    H264SwDecInfo rDecInfo;
    H264SwDecRet rDecResult = H264SWDEC_OK;
    kal_bool fgNotSupport = KAL_FALSE;
    //kal_bool fgCurBsBufferCacheable;
    kal_bool fgAgain = KAL_FALSE;
    kal_bool fgCurrentBsCacheable = KAL_FALSE;

    if ((prParam == NULL) || (!rH264SwCtrl.fgIsCodecInit))
    {
        drv_trace1(TRACE_GROUP_8, H264DEC_ARGUMENT_ERROR, __LINE__);
        ASSERT(0);
        return H264_STATUS_ERROR;
    }
    

    if (prParam->u4AddrOfNALu == 0)
    {
        drv_trace1(TRACE_GROUP_8, H264DEC_ARGUMENT_ERROR, __LINE__);
        ASSERT(0);
        return H264_STATUS_ERROR;        
    }

    drv_trace4(TRACE_GROUP_10,OPEN_API_ENTERVIDEOH264DECNALU, prParam->u4AddrOfNALu,prParam->u4LengthOfNALu,
        ((*((kal_uint8*)prParam->u4AddrOfNALu))>>5)&0x3,(*((kal_uint8*)prParam->u4AddrOfNALu))&0x1F);
    
    fgCurrentBsCacheable = OpenAPIIsExtBufferCacheable(prParam->u4AddrOfNALu, prParam->u4LengthOfNALu);

    if (fgCurrentBsCacheable)
    {
        //ASSERT(0);
        //return H264_STATUS_ERROR;
        if (rH264SwCtrl.fgBsBufferCacheable)
        {
            rDecInput.pStream = (u8 *)prParam->u4AddrOfNALu;
        }
        else
        {
            rDecInput.pStream = (u8 *)OpenAPIExtBufferCacheableSwitchAlignMemory((kal_uint32)prParam->u4AddrOfNALu,
                prParam->u4LengthOfNALu, OPEN_API_NON_CACHEABLE);
        }            
    }
    else
    {
        if (rH264SwCtrl.fgBsBufferCacheable)
        {
            rDecInput.pStream = (u8 *)OpenAPIExtBufferCacheableSwitchAlignMemory((kal_uint32)prParam->u4AddrOfNALu,
                                                                                                        prParam->u4LengthOfNALu, OPEN_API_CACHEABLE);
        }
        else
        {
            rDecInput.pStream = (u8 *)prParam->u4AddrOfNALu;
        }
    }

    rBsInfo.pBsAddr = (u8 *)prParam->u4AddrOfNALu;
    rBsInfo.BsTotalLen = prParam->u4LengthOfNALu;
    rBsInfo.NaluCnt = 1;
    rBsInfo.totalNalu = 1;
    rDecInput.dataLen = prParam->u4LengthOfNALu;
    rDecInput.pBsBuffer = &rBsInfo;

    /* decode one decoding unit */
    do
    {
        rDecResult = H264SwDecDecode(rH264SwCtrl.prH264DecInst, &rDecInput, &rDecOutput);
        drv_trace2(TRACE_GROUP_8, H264DEC_DECODE_RESULT, rDecResult, rDecInput.dataLen);
        VideoH264DecOutputPic(0);
        switch(rDecResult)
        {
        case H264SWDEC_PIC_RDY_BUFF_NOT_EMPTY:            
            //decoding a frame, but buffer is too long, or below
            if (rDecOutput.pStrmCurrPos == rDecInput.pStream)
            {
                //only flush pic after change sps; need decoding next slice
                fgAgain = KAL_TRUE;
                break;
            }
            // do not break for the following action
        case H264SWDEC_PIC_RDY:
            //output pic            
            return H264_STATUS_DECODE_OK;
        case H264SWDEC_HDRS_RDY_BUFF_NOT_EMPTY:
            if (H264SwDecGetInfo(rH264SwCtrl.prH264DecInst, &rDecInfo) != H264SWDEC_OK)
            {
                drv_trace1(TRACE_GROUP_8, H264DEC_ARGUMENT_ERROR, __LINE__);
                ASSERT(0);
                return H264_STATUS_ERROR;
            }
            drv_trace4(TRACE_GROUP_8, H264DEC_BITSTREAM_INFO, rDecInfo.picWidth, rDecInfo.picHeight,
                             rDecInfo.maxDpb, rDecInfo.profile);

            //we do not support to change resolution
            if (((rDecInfo.picWidth != rH264SwCtrl.u2FrameWidth) && rH264SwCtrl.u2FrameWidth)
                || ((rDecInfo.picHeight != rH264SwCtrl.u2FrameHeight) && rH264SwCtrl.u2FrameHeight))
            {
                drv_trace0(TRACE_GROUP_8, H264DEC_SUPPORT_ERROR);
                fgNotSupport = KAL_TRUE;
            }

            if (fgNotSupport)
            {
                drv_trace0(TRACE_GROUP_8, H264DEC_SUPPORT_ERROR);
               H264SwDecReturnBitstream(&rBsInfo);
               return H264_STATUS_ERROR;
            }
            drv_trace0(TRACE_GROUP_8, H264DEC_CHANGE_SPS);
            rH264SwCtrl.u2FrameHeight = (kal_uint16)rDecInfo.picHeight;
            rH264SwCtrl.u2FrameWidth = (kal_uint16)rDecInfo.picWidth;
            rH264SwCtrl.u4BufferSize = (((kal_uint32)rH264SwCtrl.u2FrameHeight *
                                                    (kal_uint32)rH264SwCtrl.u2FrameWidth) *3) >> 1;
            rH264SwCtrl.fgCropping = (rDecInfo.croppingFlag == 0) ? KAL_FALSE : KAL_TRUE;
            rH264SwCtrl.u2RealHeight = (kal_uint16)rDecInfo.cropParams.cropOutHeight;
            rH264SwCtrl.u2RealWidth = (kal_uint16)rDecInfo.cropParams.cropOutWidth;
            fgAgain = KAL_TRUE;
            break;
        case H264SWDEC_STRM_PROCESSED:
            return H264_STATUS_OK;
        case H264SWDEC_PARAM_ERR:
            drv_trace1(TRACE_GROUP_8, H264DEC_ARGUMENT_ERROR, __LINE__);
            ASSERT(0);
            return H264_STATUS_ERROR;
        case H264SWDEC_PARAMSET_ERROR:
            return H264_STATUS_SPS_ERROR;
        case H264SWDEC_STRM_ERR:
            fgAgain = KAL_FALSE;
            //return H264_STATUS_DECODE_ERROR;
            break;
        default:
            drv_trace0(TRACE_GROUP_8, H264DEC_DECODE_ERROR);
            return H264_STATUS_ERROR;
        }
    }while(fgAgain == KAL_TRUE);

    //ASSERT(0);

    return H264_STATUS_OK;
}

void VideoH264DecGetParam(OPEN_API_PARAM_TYPE_T rType, void *pParam, kal_uint32 u4Size)
{
    H264SwDecInfo rDecInfo;
    H264SwDecCapability rDecCap;
    kal_uint32 *pu4Param;
    OPEN_API_MEM_INFO_T *prMemInfo;

    if (pParam == NULL)
    {
        ASSERT(0);
        return;
    }

    switch(rType)
    {
    case OPEN_API_PARAM_WIDTH:
        if ((u4Size != sizeof(kal_uint32)) || (!rH264SwCtrl.fgIsCodecInit))
        {
            ASSERT(0);
        }
        pu4Param = (kal_uint32 *)pParam;
        ASSERT(pu4Param);
        if (rH264SwCtrl.u2FrameWidth)
        {
            *pu4Param = (kal_uint32)rH264SwCtrl.u2FrameWidth;
        }
        else
        {
            if (H264SwDecGetInfo(rH264SwCtrl.prH264DecInst, &rDecInfo) != H264SWDEC_OK)
            {
                drv_trace1(TRACE_GROUP_8, H264DEC_ARGUMENT_ERROR, __LINE__);
                ASSERT(0);   
                *pu4Param = 0;
            }
            *pu4Param = rDecInfo.picWidth;        
        }
        break;
    case OPEN_API_PARAM_HEIGHT:
        if ((u4Size != sizeof(kal_uint32)) || (!rH264SwCtrl.fgIsCodecInit))
        {
            ASSERT(0);
        }
        pu4Param = (kal_uint32 *)pParam;
        ASSERT(pu4Param);
        if (rH264SwCtrl.u2FrameHeight)
        {
            *pu4Param = (kal_uint32)rH264SwCtrl.u2FrameHeight;
        }
        else
        {
            if (H264SwDecGetInfo(rH264SwCtrl.prH264DecInst, &rDecInfo) != H264SWDEC_OK)
            {
                drv_trace1(TRACE_GROUP_8, H264DEC_ARGUMENT_ERROR, __LINE__);
                ASSERT(0);                
                *pu4Param = 0;
            }
            *pu4Param = rDecInfo.picHeight;
        }
        break;
    case OPEN_API_PARAM_REAL_WIDTH:
        if ((u4Size != sizeof(kal_uint32)) || (!rH264SwCtrl.fgIsCodecInit))
        {
            ASSERT(0);
        }
        pu4Param = (kal_uint32 *)pParam;
        ASSERT(pu4Param);
        *pu4Param = (rH264SwCtrl.fgCropping) ? (kal_uint32)rH264SwCtrl.u2RealWidth:
                                                                    (kal_uint32)rH264SwCtrl.u2FrameWidth;
        break;
    case OPEN_API_PARAM_REAL_HEIGHT:
        if ((u4Size != sizeof(kal_uint32)) || (!rH264SwCtrl.fgIsCodecInit))
        {
            ASSERT(0);
        }
        pu4Param = (kal_uint32 *)pParam;
        ASSERT(pu4Param);
        *pu4Param = (rH264SwCtrl.fgCropping) ? (kal_uint32)rH264SwCtrl.u2RealHeight :
                                                                    (kal_uint32)rH264SwCtrl.u2FrameHeight;
        break;
    case OPEN_API_PARAM_MEM_INFO:
        if (H264SWDEC_OK != H264SwDecQueryCapability(&rDecCap, H264SW_QVGA))
        {
            ASSERT(0);       
        }
        
        if (u4Size != sizeof(OPEN_API_MEM_INFO_T))
        {
            ASSERT(0);
        }
        prMemInfo = (OPEN_API_MEM_INFO_T *)pParam;
        ASSERT(prMemInfo);
#if defined(DRV_FEATURE__MM_INTMEM_IF)        
        prMemInfo->u4IntMemSize = 0;
#else
        prMemInfo->u4IntMemSize = rDecCap.intMemSize;
#endif
        prMemInfo->u4ExtMemSize = rDecCap.extMemSize;
        prMemInfo->fgExtCacheable = KAL_TRUE;
        break;
    default:
        ASSERT(0);
        break;
    }
    drv_trace2(TRACE_GROUP_10,OPEN_API_ENTERVIDEOH264DECGETPARAM,rType,*((kal_uint32*)pu4Param));
}

void VideoH264DecSetParam(OPEN_API_PARAM_TYPE_T rType, void *pParam, kal_uint32 u4Size)
{
    if (pParam == NULL)
    {
        ASSERT(0);
        return;
    }
    drv_trace2(TRACE_GROUP_10,OPEN_API_ENTERVIDEOH264DECGETPARAM,rType,*((kal_uint32*)pParam));
    switch (rType)
    {
    case OPEN_API_PARAM_FLUSH_BUFFER_CMD:
        VideoH264DecOutputPic((kal_uint32)H264SW_OPENAPI_EOF);
        break;
    default:
        ASSERT(0);
        break;
    }
}

void VideoH264DecTimeoutReset(void)
{
    return;
}


#endif /* H264_SW_OPEN_API_SUPPORT */
#endif /* __H264_DEC_SW_SUPPORT__ */

