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
 *   video_buffer_management_v2.c
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
 *
 ****************************************************************************/
#include "drv_features_video.h"

#ifdef __VE_VIDEO_COMMON__
#include "drv_comm.h"
#include "video_buffer_management_v2.h"
#include "Cache_sw.h"
#include "mmu.h"
#include "vcodec_v2_trc.h"
#include "video_comm_v2.h"
#include "kal_trace.h"
#include "mm_intmem.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "video_codec_mem_v2.h"



#if defined(__VE_SPECIAL_MEM_ALLOCATION_FOR_RENDERER__)
    #include "va2_video_renderer_mem_req.h"
    #include "video_memory_usage_v2.h"
#endif
/******************************************************************************
*
*   Macros
*
******************************************************************************/

#define N_BIT_MASK(n)   ((1<<(n+1))-1)
#define ADM_OVERHEAD        256

#ifdef __VE_MM_DCM_SUPPORT__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VECOM_ROCODE", rodata = "DYNAMIC_CODE_VECOM_RODATA"
#endif

#if defined(__VE_DYNAMIC_SWITCH_CACHEABILITY__)

VIDEO_EXTMEM_HANDLER_T* VideoInitExtBufferInternal(kal_uint32 u4StartAddr, kal_uint32 u4Size, VIDEO_SCENARIO_T eScenario)
{
    VIDEO_EXTMEM_HANDLER_T* prMgr = (VIDEO_EXTMEM_HANDLER_T*)get_ctrl_buffer(sizeof(VIDEO_EXTMEM_HANDLER_T));
    kal_uint32 u4CacheableBufferSize = 0;
    kal_uint32 u4InitAddr = u4StartAddr;
    kal_uint32 u4InitSize = u4Size;

    drv_trace4(TRACE_GROUP_10, V2BUF_EXT_INIT_INTERNAL, u4InitAddr, u4InitSize, eScenario, (kal_uint32)prMgr);

    // Initialize the conreolling structure
    kal_mem_set((void*)(prMgr), 0, sizeof(*prMgr));

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
    prMgr->rVideoExtBufferADM = kal_adm_create((void*)(u4InitAddr), u4InitSize, NULL, KAL_TRUE);
    #endif

    u4CacheableBufferSize = kal_adm_get_max_alloc_size(prMgr->rVideoExtBufferADM);
    if ((u4CacheableBufferSize&CPU_CACHE_LINE_SIZE_MASK) != 0)
    {
        u4CacheableBufferSize -= (kal_uint32)(u4CacheableBufferSize & CPU_CACHE_LINE_SIZE_MASK);
    }
    prMgr->pu1ExtStartAddr = (kal_uint8*) kal_adm_alloc_cacheable(prMgr->rVideoExtBufferADM , u4CacheableBufferSize - ADM_OVERHEAD, PAGE_SIZE_4KB);

    ASSERT(prMgr->pu1ExtStartAddr != NULL);

    prMgr->u4ExtMemLength =   u4CacheableBufferSize;
    prMgr->fgInitExtMem   =   KAL_TRUE;
    prMgr->u4ExtMemUsed   =   0;

    return prMgr;
}


kal_uint32 VideoGetExtBuffer(VIDEO_EXTMEM_HANDLER_T* prMgr, kal_uint32 u4RequestSize)
{
    kal_uint8*  pu1MemAddr = NULL;
    kal_uint32  u4AllocateSize = u4RequestSize;

    ASSERT(KAL_TRUE == prMgr->fgInitExtMem);

    //Instead of assert non-cacheline-aligned allocation, we make it cacheline-aligned
    if((u4AllocateSize&CPU_CACHE_LINE_SIZE_MASK) != 0)
    {
        u4AllocateSize += (kal_uint32)(0x1<<CPU_CACHE_LINE_BIT_OFFSET) - (kal_uint32)(u4AllocateSize & CPU_CACHE_LINE_SIZE_MASK);
    }

    if  (prMgr->u4ExtMemUsed + u4AllocateSize > prMgr->u4ExtMemLength)
    {
        //Total memory size used is larger than defined
        drv_trace4(TRACE_GROUP_10, V2BUF_EXT_GET_FAIL, u4RequestSize, u4AllocateSize, prMgr->u4ExtMemLength, ((prMgr->u4ExtMemUsed + u4AllocateSize) - prMgr->u4ExtMemLength)); 
        return 0;
    }

    pu1MemAddr  =   prMgr->pu1ExtStartAddr + prMgr->u4ExtMemUsed;
    prMgr->u4ExtMemUsed   +=  u4AllocateSize;

    drv_trace4(TRACE_GROUP_10, V2BUF_EXT_GET, u4RequestSize, (kal_uint32)pu1MemAddr,
        u4AllocateSize, (kal_uint32)prMgr);

    return  (kal_uint32)(pu1MemAddr);
}


void VideoSetExtCacheBuffer(VIDEO_EXTMEM_HANDLER_T* prMgr, kal_uint32 u4Size)
{
    return;
}

kal_uint32 VideoGetExtCacheBuffer(VIDEO_EXTMEM_HANDLER_T* prMgr, kal_uint32 u4Size)
{
    return VideoGetExtBuffer(prMgr, u4Size);
}

void VideoDeInitExtBuffer(VIDEO_EXTMEM_HANDLER_T* prMgr)
{
    drv_trace2(TRACE_GROUP_10, V2BUF_EXT_DEINIT, prMgr->fgInitExtMem, (kal_uint32)(prMgr));

    if (prMgr->fgInitExtMem == KAL_TRUE)
    {
        kal_adm_free(prMgr->rVideoExtBufferADM, prMgr->pu1ExtStartAddr);
        kal_adm_delete(prMgr->rVideoExtBufferADM);
    }

    // Initialize the conreolling structure
    //kal_mem_set((void*)(prMgr), 0, sizeof(*prMgr));

    free_ctrl_buffer((void*)prMgr);
}



/******************************************************************************
* xxx
*
* Context: xxx
*
* Side effect: xxx
******************************************************************************/
kal_bool VideoCommIsExtBufferCacheable(kal_uint32 u4StartAddr, kal_uint32 u4Size)
{
    ASSERT((u4StartAddr != 0) && (u4Size != 0));

    if (INT_QueryIsCachedRAM(u4StartAddr, u4Size))
    {
        return KAL_TRUE;
    }
    else if (INT_QueryIsNonCachedRAM(u4StartAddr, u4Size))
    {
        return KAL_FALSE;
    }

    EXT_ASSERT(0, 0, u4StartAddr, u4Size);
    return KAL_FALSE;
}


/******************************************************************************
* xxx
*
* Context: xxx
*
* Side effect: xxx
******************************************************************************/
kal_uint32 VideoCommExtBufferCacheableSwitch(kal_uint32 u4StartAddr, kal_uint32 u4Size, VIDEO_MEMORY_SWITCH_T eSwitch)
{
    kal_uint32 u4ShiftByte = 0;

    switch(eSwitch)
    {
    case VIDEO_CACHEABLE:
        if (INT_QueryIsCachedRAM(u4StartAddr, u4Size))
        {
            return u4StartAddr;
        }

        if((u4StartAddr&CPU_CACHE_LINE_SIZE_MASK) != 0)
        {
            ASSERT(0);
        }

        if((u4Size&CPU_CACHE_LINE_SIZE_MASK) != 0)
        {
            ASSERT(0);
        }

#if defined(__VE_MTK_TARGET__)
        dynamic_switch_cacheable_region((void*)&u4StartAddr, u4Size, PAGE_CACHEABLE);
#endif
        break;

    case VIDEO_NON_CACHEABLE:
        if (INT_QueryIsNonCachedRAM(u4StartAddr, u4Size))
        {
            return u4StartAddr;
        }

        if((u4StartAddr&CPU_CACHE_LINE_SIZE_MASK) != 0)
        {
            ASSERT(0);
        }

        if((u4Size&CPU_CACHE_LINE_SIZE_MASK) != 0)
        {
            ASSERT(0);
        }
#if defined(__VE_MTK_TARGET__)
        dynamic_switch_cacheable_region((void*)&u4StartAddr, u4Size, PAGE_NO_CACHE);
#endif
        break;

    default:
        ASSERT(0);
        break;
    }

    return (u4StartAddr + u4ShiftByte);
}


/******************************************************************************
* xxx
*
* Context: xxx
*
* Side effect: xxx
******************************************************************************/
kal_uint32 VideoCommExtBufferCacheableSwitchAlignMemory(kal_uint32 u4StartAddr, kal_uint32 u4Size, VIDEO_MEMORY_SWITCH_T eSwitch)
{
    kal_uint32 u4ShiftByte = 0;

    switch(eSwitch)
    {
    case VIDEO_CACHEABLE:
        if (INT_QueryIsCachedRAM(u4StartAddr, u4Size))
        {
            return u4StartAddr;
        }

        if((u4StartAddr&CPU_CACHE_LINE_SIZE_MASK) != 0)
        {
            u4ShiftByte = (kal_uint32)(u4StartAddr & CPU_CACHE_LINE_SIZE_MASK);
            u4StartAddr -= u4ShiftByte;
        }
        u4Size += u4ShiftByte;

        if((u4Size&CPU_CACHE_LINE_SIZE_MASK) != 0)
        {
            u4Size += (kal_uint32)(0x1<<CPU_CACHE_LINE_BIT_OFFSET) - (kal_uint32)(u4Size & CPU_CACHE_LINE_SIZE_MASK);
        }
#if defined(__VE_MTK_TARGET__)
        dynamic_switch_cacheable_region((void*)&u4StartAddr, u4Size, PAGE_CACHEABLE);
#endif
        break;
    case VIDEO_NON_CACHEABLE:
        if (INT_QueryIsNonCachedRAM(u4StartAddr, u4Size))
        {
            return u4StartAddr;
        }

        if((u4StartAddr&CPU_CACHE_LINE_SIZE_MASK) != 0)
        {
            u4ShiftByte = (kal_uint32)(u4StartAddr & CPU_CACHE_LINE_SIZE_MASK);
            u4StartAddr -= u4ShiftByte;
        }
        u4Size += u4ShiftByte;

        if((u4Size&CPU_CACHE_LINE_SIZE_MASK) != 0)
        {
            u4Size += (kal_uint32)(0x1<<CPU_CACHE_LINE_BIT_OFFSET) - (kal_uint32)(u4Size & CPU_CACHE_LINE_SIZE_MASK);
        }
#if defined(__VE_MTK_TARGET__)
        dynamic_switch_cacheable_region((void*)&u4StartAddr, u4Size, PAGE_NO_CACHE);
#endif
        break;
    default:
        ASSERT(0);
        break;
    };

    return (u4StartAddr + u4ShiftByte);
}

kal_uint32 VideoCommFlushBuffer(kal_uint32 u4StartAddr, kal_uint32 u4Size)
{
    drv_trace2(TRACE_GROUP_10, V2BUF_EXT_FLUSH, u4StartAddr, u4Size);
    return clean_dcache(u4StartAddr, u4Size);
}

kal_uint32 VideoCommInvalidateBuffer(kal_uint32 u4StartAddr, kal_uint32 u4Size)
{
    drv_trace2(TRACE_GROUP_10, V2BUF_EXT_INVALIDATE, u4StartAddr, u4Size);
    return invalidate_dcache(u4StartAddr, u4Size);
}

#elif defined(__VE_MTK_L1CACHEABLE__)
/******************************************************************************
* Allocate aligned and cacheable external memory by using ADM.  The macro
* ROUND_UP_TO_POWER_OF_TWO() can be used in place of the round-up operation
* in this function.
*
* Context: xxx
*
* Side effect: xxx
******************************************************************************/
#define BITNUMBER_OF_32K    15
#define L1CACHE_OVERHEAD    4096

VIDEO_EXTMEM_HANDLER_T* VideoInitExtBufferInternal(kal_uint32 u4StartAddr, kal_uint32 u4Size, VIDEO_SCENARIO_T eScenario)
{
    VIDEO_EXTMEM_HANDLER_T* prMgr = (VIDEO_EXTMEM_HANDLER_T*)get_ctrl_buffer(sizeof(VIDEO_EXTMEM_HANDLER_T));
    kal_uint32  u4AllocateBufferSize = u4Size;
    kal_uint32  u4EndAddr   =   u4StartAddr + u4Size;
    kal_int32   i4IsWTCache = 0;

    drv_trace4(TRACE_GROUP_10, V2BUF_EXT_INIT_INTERNAL, u4StartAddr, u4Size, eScenario, (kal_uint32)prMgr);

    //Assumed video driver would always need external memory somewhere
    ASSERT((u4StartAddr != NULL)&&(u4Size > 0));

    // Initialize the conreolling structure
    kal_mem_set((void*)(prMgr), 0, sizeof(*prMgr));

    prMgr->fgInitExtCacheMem  =   KAL_FALSE;
    prMgr->fgInitExtMem       =   KAL_FALSE;

    // Check if the write through is enable at init
    i4IsWTCache = INT_QueryIsWriteThroughCachedRAM(u4StartAddr, u4Size);
    prMgr->fgWriteThrough = (i4IsWTCache == 0)?(KAL_FALSE):(KAL_TRUE);

    if (KAL_TRUE == prMgr->fgWriteThrough)
    {
        if ((u4StartAddr&CPU_CACHE_LINE_SIZE_MASK) != 0)
        {
            u4StartAddr += (kal_uint32)(0x1<<CPU_CACHE_LINE_BIT_OFFSET) - (kal_uint32)(u4StartAddr & CPU_CACHE_LINE_SIZE_MASK);
        }

        prMgr->rVideoExtBufferADM = kal_adm_create((void*)(u4StartAddr), u4AllocateBufferSize - CPU_CACHE_LINE_SIZE, NULL, KAL_TRUE);

        u4AllocateBufferSize = kal_adm_get_max_alloc_size(prMgr->rVideoExtBufferADM);
        if ((u4AllocateBufferSize&CPU_CACHE_LINE_SIZE_MASK) != 0)
        {
            u4AllocateBufferSize -= (kal_uint32)(u4AllocateBufferSize & CPU_CACHE_LINE_SIZE_MASK);
        }
        prMgr->pu1ExtStartAddr = kal_adm_alloc_align(prMgr->rVideoExtBufferADM, u4AllocateBufferSize - ADM_OVERHEAD, CPU_CACHE_LINE_SIZE);

        ASSERT(prMgr->pu1ExtStartAddr != NULL);

        prMgr->u4ExtMemLength     =   u4AllocateBufferSize;
        prMgr->u4ExtMemUsed       =   0;
        prMgr->fgInitExtMem       =   KAL_TRUE;
        prMgr->fgInitExtCacheMem  =   KAL_TRUE;
    }
    else
    {
        prMgr->u4SpareMemLength           =   0;
        prMgr->u4ExtCacheMemLength        =   0;
        prMgr->u4ExtCacheMemUsed          =   0;
        prMgr->rVideoExtCacheBufferADM    =   NULL;
        prMgr->pu1ExtCacheStartAddr       =   NULL;

        switch(eScenario)
        {
            case VIDEO_SCENARIO_DECODE:
            case VIDEO_SCENARIO_ENCODE:
            case VIDEO_SCENARIO_SRC_PROVIDER:
                prMgr->fgInitExtCacheMem = KAL_FALSE;
                break;
            case VIDEO_SCENARIO_VCALL:
            case VIDEO_SCENARIO_MERGE_FILE:
                prMgr->fgInitExtCacheMem = KAL_TRUE;
                break;
            default:
                ASSERT(0);
                break;
        };

        u4AllocateBufferSize = u4EndAddr - u4StartAddr;

        prMgr->u4ExtMemLength     =   u4AllocateBufferSize;
        prMgr->u4ExtMemUsed       =   0;

        prMgr->rVideoExtBufferADM =   kal_adm_create((void*) u4StartAddr, prMgr->u4ExtMemLength, NULL, KAL_TRUE);

        prMgr->u4ExtMemLength -=  ADM_OVERHEAD;

        prMgr->pu1ExtStartAddr = kal_adm_alloc_align(prMgr->rVideoExtBufferADM, prMgr->u4ExtMemLength, CPU_CACHE_LINE_SIZE);

        if  (NULL == prMgr->pu1ExtStartAddr)
        {
            ASSERT(0);
        }

        prMgr->fgInitExtMem       =   KAL_TRUE;
    }

    return prMgr;
}

kal_uint32 VideoGetExtBuffer(VIDEO_EXTMEM_HANDLER_T* prMgr, kal_uint32 u4RequestSize)
{
    kal_uint32  u4AllocateSize = u4RequestSize;
    kal_uint8*  pu1MemAddr = NULL;

    ASSERT(KAL_TRUE == prMgr->fgInitExtMem);

    //ASSERT(nSize&CPU_CACHE_LINE_SIZE_MASK == 0);
    //Instead of assert non-cacheline-aligned allocation, we make it cacheline-aligned
    if((u4AllocateSize&CPU_CACHE_LINE_SIZE_MASK) != 0)
    {
        u4AllocateSize += (kal_uint32)(0x1<<CPU_CACHE_LINE_BIT_OFFSET) - (kal_uint32)(u4AllocateSize & CPU_CACHE_LINE_SIZE_MASK);
    }

    if  (prMgr->u4ExtMemUsed + u4AllocateSize > prMgr->u4ExtMemLength)
    {
        //Total memory size used is larger than defined
        return 0;
    }

    pu1MemAddr  =   prMgr->pu1ExtStartAddr + prMgr->u4ExtMemUsed;

    prMgr->u4ExtMemUsed   +=  u4AllocateSize;

    drv_trace4(TRACE_GROUP_10, V2BUF_EXT_GET, u4RequestSize, (kal_uint32)pu1MemAddr,
        u4AllocateSize, (kal_uint32)prMgr);

    return  (kal_uint32)(pu1MemAddr);
}

void VideoSetExtCacheBuffer(VIDEO_EXTMEM_HANDLER_T* prMgr, kal_uint32 u4Size)
{
    if (KAL_TRUE == prMgr->fgWriteThrough)
    {
        prMgr->fgInitExtCacheMem  =   KAL_TRUE;
    }
    else
    {
        // Allocate a memory from the one MED brought in
        kal_uint32 u4CacheStartAddr  =   VideoGetExtBuffer(prMgr, u4Size + 32*1024 + 31*1024 + L1CACHE_OVERHEAD);
        kal_uint32 u4AllocateCacheBufferSize = u4Size + 32*1024 + 31*1024 + L1CACHE_OVERHEAD;
        kal_uint32 u4SpareMemLength =   0;
        kal_uint32 u4CacheStartAddr32k     =   0;

        ASSERT(KAL_FALSE == prMgr->fgInitExtCacheMem);

        // 32 * 1024 needs 15 bits
        // Start address needs to be 31k byte aligned
        u4CacheStartAddr32k = u4CacheStartAddr + 1024;
        if(((u4CacheStartAddr32k) & N_BIT_MASK(BITNUMBER_OF_32K)) != 0)
        {
            u4SpareMemLength += (kal_uint32)(0x1<<BITNUMBER_OF_32K) - (kal_uint32)(u4CacheStartAddr32k & N_BIT_MASK(BITNUMBER_OF_32K - 1));
            u4CacheStartAddr += u4SpareMemLength;
            u4AllocateCacheBufferSize  -=  u4SpareMemLength;
        }

        // Length needs to be 32k byte aligned
        u4AllocateCacheBufferSize -= ADM_OVERHEAD;
        if((u4AllocateCacheBufferSize & N_BIT_MASK(BITNUMBER_OF_32K)) != 0)
        {
            kal_uint32  u4TempMemLength = (kal_uint32)(u4AllocateCacheBufferSize & N_BIT_MASK(BITNUMBER_OF_32K - 1));

            u4SpareMemLength += u4TempMemLength;
            u4AllocateCacheBufferSize  -=  u4TempMemLength;
        }

        prMgr->u4ExtCacheMemLength     =   u4AllocateCacheBufferSize;
        prMgr->u4ExtCacheMemUsed       =   0;
        prMgr->rVideoExtCacheBufferADM =   kal_adm_create((void*) u4CacheStartAddr, prMgr->u4ExtCacheMemLength, NULL, KAL_TRUE);

        prMgr->u4ExtCacheMemLength -= L1CACHE_OVERHEAD;
        prMgr->pu1ExtCacheStartAddr  =   kal_adm_alloc_mtkL1_cacheable(prMgr->rVideoExtCacheBufferADM, prMgr->u4ExtCacheMemLength, ADM_CACHE_ALL_CHANNEL_COVER);

        if  (NULL == prMgr->pu1ExtCacheStartAddr)
        {
            ASSERT(0);
        }

        prMgr->fgInitExtCacheMem  =   KAL_TRUE;
    }
}

kal_uint32 VideoGetExtCacheBuffer(VIDEO_EXTMEM_HANDLER_T* prMgr, kal_uint32 u4Size)
{
    kal_uint8*  pu1MemAddr = NULL;
    kal_uint32  u4ReqSize = u4Size;

    ASSERT(KAL_TRUE == prMgr->fgInitExtCacheMem);

    if (KAL_TRUE == prMgr->fgWriteThrough)
    {
        pu1MemAddr = (kal_uint8*)VideoGetExtBuffer(prMgr, u4ReqSize);
    }
    else
    {
        //ASSERT(nSize&CPU_CACHE_LINE_SIZE_MASK == 0);
        //Instead of assert non-cacheline-aligned allocation, we make it cacheline-aligned
        if ((u4ReqSize&CPU_CACHE_LINE_SIZE_MASK) != 0)
        {
            u4ReqSize += (kal_uint32)(0x1<<CPU_CACHE_LINE_BIT_OFFSET) - (kal_uint32)(u4ReqSize & CPU_CACHE_LINE_SIZE_MASK);
        }

        if (prMgr->u4ExtCacheMemUsed + u4ReqSize > prMgr->u4ExtCacheMemLength)
        {
            //Total memory size used is larger than defined
            return 0;
        }

        pu1MemAddr  =   prMgr->pu1ExtCacheStartAddr + prMgr->u4ExtCacheMemUsed;

        prMgr->u4ExtCacheMemUsed   +=  u4ReqSize;
    }

    return  (kal_uint32)(pu1MemAddr);
}

void VideoDeInitExtBuffer(VIDEO_EXTMEM_HANDLER_T* prMgr)
{
    drv_trace2(TRACE_GROUP_10, V2BUF_EXT_DEINIT, prMgr->fgInitExtMem, (kal_uint32)(prMgr));

    if (KAL_TRUE == prMgr->fgInitExtMem)
    {
        if (NULL != prMgr->rVideoExtBufferADM)
        {
            kal_adm_free(prMgr->rVideoExtBufferADM, prMgr->pu1ExtStartAddr);
            kal_adm_delete(prMgr->rVideoExtBufferADM);
            prMgr->rVideoExtBufferADM = NULL;
        }

        if (NULL != prMgr->rVideoExtCacheBufferADM)
        {
            kal_adm_free(prMgr->rVideoExtCacheBufferADM, prMgr->pu1ExtCacheStartAddr);
            kal_adm_delete(prMgr->rVideoExtCacheBufferADM);
            prMgr->rVideoExtCacheBufferADM = NULL;
        }
    }

    prMgr->fgInitExtMem       =   KAL_FALSE;
    prMgr->fgInitExtCacheMem  =   KAL_FALSE;

    free_ctrl_buffer((void*)prMgr);
}



/******************************************************************************
* xxx
*
* Context: xxx
*
* Side effect: xxx
******************************************************************************/
kal_bool VideoCommIsExtBufferCacheable(kal_uint32 u4StartAddr, kal_uint32 u4Size)
{
    ASSERT((u4StartAddr != 0) && (u4Size != 0));

    if (INT_QueryIsCachedRAM(u4StartAddr, u4Size))
    {
        return KAL_TRUE;
    }
    else if (INT_QueryIsNonCachedRAM(u4StartAddr, u4Size))
    {
        return KAL_FALSE;
    }
}

__inline static kal_uint32 _VideoCommInvalidateCache(kal_uint32 u4StartAddr, kal_uint32 u4Size)
{
#if defined(__VE_MTK_TARGET__)
    if (KAL_TRUE == INT_QueryIsWriteThroughCachedRAM(u4StartAddr, u4Size))
    {
        return invalidate_wt_cache(u4StartAddr, u4Size);
    }
    else
    {
        return invalidate_l1cache(u4StartAddr, u4Size);
    }
#endif
}
/******************************************************************************
* xxx
*
* Context: xxx
*
* Side effect: xxx
******************************************************************************/
kal_uint32 VideoCommExtBufferCacheableSwitch(kal_uint32 u4StartAddr, kal_uint32 u4Size, VIDEO_MEMORY_SWITCH_T eSwitch)
{
    switch(eSwitch)
    {
    case VIDEO_CACHEABLE:
        if (INT_QueryIsCachedRAM(u4StartAddr, u4Size))
        {
            return u4StartAddr;
        }

        if (0 == _VideoCommInvalidateCache(u4StartAddr, u4Size))
        {
            return u4StartAddr;
        }
        else
        {
            ASSERT(0);
        }
        break;

    case VIDEO_NON_CACHEABLE:
        if (INT_QueryIsNonCachedRAM(u4StartAddr, u4Size))
        {
            return u4StartAddr;
        }
        break;
    default:
        ASSERT(0);
        //break;
    }

    return (u4StartAddr);
}


/******************************************************************************
* xxx
*
* Context: xxx
*
* Side effect: xxx
******************************************************************************/
kal_uint32 VideoCommExtBufferCacheableSwitchAlignMemory(kal_uint32 u4StartAddr, kal_uint32 u4Size, VIDEO_MEMORY_SWITCH_T eSwitch)
{
    kal_uint32 u4ShiftByte = 0;

    switch(eSwitch)
    {
    case VIDEO_CACHEABLE:
        if (INT_QueryIsCachedRAM(u4StartAddr, u4Size))
        {
            return u4StartAddr;
        }

        if((u4StartAddr&CPU_CACHE_LINE_SIZE_MASK) != 0)
        {
            u4ShiftByte = (kal_uint32)(u4StartAddr & CPU_CACHE_LINE_SIZE_MASK);
            u4StartAddr -= u4ShiftByte;
        }
        u4Size += u4ShiftByte;

        if((u4Size&CPU_CACHE_LINE_SIZE_MASK) != 0)
        {
            u4Size += (kal_uint32)(0x1<<CPU_CACHE_LINE_BIT_OFFSET) - (kal_uint32)(u4Size & CPU_CACHE_LINE_SIZE_MASK);
        }

        if (0 == _VideoCommInvalidateCache(u4StartAddr, u4Size))
        {
            return (u4StartAddr + u4ShiftByte);
        }
        else
        {
            ASSERT(0);
        }
        break;
    case VIDEO_NON_CACHEABLE:
        if (INT_QueryIsNonCachedRAM(u4StartAddr, u4Size))
        {
            return u4StartAddr;
        }

        break;
    default:
        ASSERT(0);
        //break;
    };

    return (u4StartAddr + u4ShiftByte);
}

kal_uint32 VideoCommFlushBuffer(kal_uint32 u4StartAddr, kal_uint32 u4Size)
{
    drv_trace2(TRACE_GROUP_10, V2BUF_EXT_FLUSH, u4StartAddr, u4Size);
    return 0;
}

kal_uint32 VideoCommInvalidateBuffer(kal_uint32 u4StartAddr, kal_uint32 u4Size)
{
    drv_trace2(TRACE_GROUP_10, V2BUF_EXT_INVALIDATE, u4StartAddr, u4Size);

    if (0 == _VideoCommInvalidateCache(u4StartAddr, u4Size))
    {
        return u4StartAddr;
    }
    else
    {
        ASSERT(0);
    }

    return 0;
}

#else
VIDEO_EXTMEM_HANDLER_T* VideoInitExtBufferInternal(kal_uint32 u4StartAddr, kal_uint32 u4Size, VIDEO_SCENARIO_T eScenario){return;}
kal_uint32 VideoGetExtBuffer(VIDEO_EXTMEM_HANDLER_T* prMgr, kal_uint32 u4RequestSize){return;}
void VideoSetExtCacheBuffer(VIDEO_EXTMEM_HANDLER_T* prMgr, kal_uint32 u4Size){return;}
kal_uint32 VideoGetExtCacheBuffer(VIDEO_EXTMEM_HANDLER_T* prMgr, kal_uint32 u4Size){return;}
void VideoDeInitExtBuffer(VIDEO_EXTMEM_HANDLER_T* prMgr){return;}
kal_bool VideoCommIsExtBufferCacheable(kal_uint32 u4StartAddr, kal_uint32 u4Size){return KAL_FALSE;}
kal_uint32 VideoCommExtBufferCacheableSwitch(kal_uint32 u4StartAddr, kal_uint32 u4Size, VIDEO_MEMORY_SWITCH_T eSwitch){return 0;}
kal_uint32 VideoCommExtBufferCacheableSwitchAlignMemory(kal_uint32 u4StartAddr, kal_uint32 u4Size, VIDEO_MEMORY_SWITCH_T eSwitch){return 0;}
kal_uint32 VideoCommFlushBuffer(kal_uint32 u4StartAddr, kal_uint32 u4Size){return 0;}
kal_uint32 VideoCommInvalidateBuffer(kal_uint32 u4StartAddr, kal_uint32 u4Size){return 0;}
#endif

#if defined(__VE_SPECIAL_MEM_ALLOCATION_FOR_RENDERER__)
    VIDEO_EXTMEM_RENDERER_T rRendererMemMgr;
#endif

VIDEO_EXTMEM_HANDLER_T* VideoInitExtBuffer(kal_uint32 u4StartAddr, kal_uint32 u4Size, VIDEO_SCENARIO_T eScenario)
{
    //drv_trace4(TRACE_GROUP_10, V2BUF_EXT_INIT, u4InitAddr, u4InitSize, eScenario, (kal_uint32)prMgr);

#if defined(__VE_SPECIAL_MEM_ALLOCATION_FOR_RENDERER__)
    if (VIDEO_SCENARIO_DECODE == eScenario)
    {
        if ((u4StartAddr & 0xFF000000) == ((u4StartAddr + VA2_VR_VP_SW_RESIZER_BUFFER_SIZE) & 0xFF000000))
        {
            //in this case, we allocate the memory for VA2_VR_VP_SW_RESIZER_BUFFER_SIZE in the head
            rRendererMemMgr.pu1ExtStartAddr = (kal_uint8*)u4StartAddr;
            u4StartAddr += VA2_VR_VP_SW_RESIZER_BUFFER_SIZE;
        }
        else
        {
            //in this case, we allocate the memory for VA2_VR_VP_SW_RESIZER_BUFFER_SIZE in the tail
            rRendererMemMgr.pu1ExtStartAddr = (kal_uint8*)(u4StartAddr + u4Size - VA2_VR_VP_SW_RESIZER_BUFFER_SIZE);
        }
        u4Size -= VA2_VR_VP_SW_RESIZER_BUFFER_SIZE;
        rRendererMemMgr.u4Size = VA2_VR_VP_SW_RESIZER_BUFFER_SIZE;
    }
#endif

    return VideoInitExtBufferInternal(u4StartAddr, u4Size, eScenario);
}

VIDEO_INTMEM_HANDLER_T*  VideoInitIntBuffer(
    kal_uint32 u4StartAddr,
    kal_uint32 u4InitSize,
    VIDEO_SCENARIO_T eScenario)
{
    kal_uint32 u4Addr = u4StartAddr, u4Size = u4InitSize;
    VIDEO_INTMEM_HANDLER_T* prHandler = (VIDEO_INTMEM_HANDLER_T*)get_ctrl_buffer(sizeof(VIDEO_INTMEM_HANDLER_T));
    kal_bool fgRet = KAL_FALSE;

    drv_trace4(TRACE_GROUP_10, V2BUF_INT_INIT,
            u4StartAddr, u4InitSize,
            eScenario, (kal_uint32)prHandler);

    // Initialize the structure of the handler
    kal_mem_set((void*)prHandler, 0, sizeof(*prHandler));

    prHandler->eScenario = eScenario;

#if defined(__VE_MM_INTMEM_IF__)
#if defined(__VIDEO_V2_MT6268_SERIES__)
    switch(eScenario)
    {
        case VIDEO_SCENARIO_ENCODE:
            fgRet = mm_intmem_get(MM_SCEN__VIDEO_RECORD, MM_INTMEM_SEG__HW_VIDEO, &u4Addr, &u4Size);
            break;
        case VIDEO_SCENARIO_DECODE:
            fgRet = mm_intmem_get(MM_SCEN__VIDEO_PLAYBACK, MM_INTMEM_SEG__HW_VIDEO, &u4Addr, &u4Size);
            break;
        case VIDEO_SCENARIO_VCALL:
            fgRet = mm_intmem_get(MM_SCEN__VIDEO_TELEPHONY, MM_INTMEM_SEG__HW_VIDEO, &u4Addr, &u4Size);
            break;
        default:
            ASSERT(0);
            break;
    }
#endif //__VIDEO_V2_MT6268_SERIES__
#if defined (__VIDEO_V2_MT6236_SERIES__)
    switch(eScenario)
    {
        case VIDEO_SCENARIO_ENCODE:
            fgRet = mm_intmem_get(MM_SCEN__VIDEO_RECORD, MM_INTMEM_SEG__SW_VIDEO, &u4Addr, &u4Size);
            break;
        case VIDEO_SCENARIO_DECODE:
            fgRet = mm_intmem_get(MM_SCEN__VIDEO_PLAYBACK, MM_INTMEM_SEG__SW_VIDEO, &u4Addr, &u4Size);
            break;
        case VIDEO_SCENARIO_VCALL:
            fgRet = mm_intmem_get(MM_SCEN__VIDEO_TELEPHONY, MM_INTMEM_SEG__SW_VIDEO, &u4Addr, &u4Size);
            break;
        default:
            ASSERT(0);
            break;
    }
#endif	//__VIDEO_V2_MT6236_SERIES__
#if defined (__VIDEO_V2_MT6276_SERIES__)
    switch(eScenario)
    {
        case VIDEO_SCENARIO_ENCODE:
            fgRet = mm_intmem_get(MM_SCEN__VIDEO_RECORD, MM_INTMEM_SEG__SW_VIDEO, &u4Addr, &u4Size);
            break;
        case VIDEO_SCENARIO_DECODE:
            fgRet = mm_intmem_get(MM_SCEN__VIDEO_PLAYBACK, MM_INTMEM_SEG__SW_VIDEO, &u4Addr, &u4Size);
            break;
        case VIDEO_SCENARIO_VCALL:
            u4Addr  =   0;
            u4Size  =   0;
            break;
        default:
            ASSERT(0);
            break;
    }
#endif	//__VIDEO_V2_MT6276_SERIES__
#if defined(MT6253) || defined(MT6253T)
    switch(eScenario)
    {
        case VIDEO_SCENARIO_ENCODE:
            fgRet = mm_intmem_get(MM_SCEN__VIDEO_RECORD, MM_INTMEM_SEG__SW_VIDEO, &u4Addr, &u4Size);
            break;
        case VIDEO_SCENARIO_DECODE:
            fgRet = mm_intmem_get(MM_SCEN__VIDEO_PLAYBACK, MM_INTMEM_SEG__SW_VIDEO, &u4Addr, &u4Size);
            break;
        default:
            ASSERT(0);
            break;
    }
#endif
#endif  // __VE_MM_INTMEM_IF__


    prHandler->pu1Start = (kal_uint8*)u4Addr;
    prHandler->u4Size = u4Size;
    prHandler->fgInit = fgRet;

    if(KAL_TRUE == prHandler->fgInit)
    {
        prHandler->arFreeMemory[0].pu1Addr = prHandler->pu1Start;
        prHandler->arFreeMemory[0].u4Size = prHandler->u4Size;
        prHandler->u4Partition = 1;
    }

    drv_trace4(TRACE_GROUP_10, V2BUF_INT_INIT_END,
            u4Addr, u4Size,
            eScenario, (kal_uint32)prHandler);

    return prHandler;
}

void VideoResetIntBuffer(VIDEO_INTMEM_HANDLER_T* prHandler)
{
    drv_trace1(TRACE_GROUP_10, V2BUF_INT_RESET, (kal_uint32)prHandler);
    kal_mem_set(&prHandler->arFreeMemory[0], 0, _MAX_ALLOCATE_NUMBER*sizeof(prHandler->arFreeMemory[0]));
    if(KAL_TRUE == prHandler->fgInit)
    {
        prHandler->arFreeMemory[0].pu1Addr = (kal_uint8*)prHandler->pu1Start;
        prHandler->arFreeMemory[0].u4Size = prHandler->u4Size;
        prHandler->u4Partition = 1;
    }
}

kal_uint32 VideoGetIntBuffer(
    VIDEO_INTMEM_HANDLER_T* prHandler,
    kal_uint32 u4RequestSize)
{
    kal_uint32  u4Addr = 0;
    kal_uint32  u4Size = ((u4RequestSize + 3)>>2)<<2;
    kal_uint32  i;

    i = 0;
    do{
        VIDEO_INTMEM_ATOM_T* prAtom = &prHandler->arFreeMemory[i];

        if (prAtom->u4Size >= u4Size)
        {
            u4Addr = (kal_uint32)prAtom->pu1Addr;
            prAtom->u4Size -= u4Size;
            prAtom->pu1Addr += u4Size;
            break;
        }
    }while(++i < prHandler->u4Partition);

    drv_trace4(TRACE_GROUP_10, V2BUF_INT_GET,
        u4RequestSize, u4Addr,
        u4Size, (kal_uint32)prHandler);

    return u4Addr;
}

kal_uint32 VideoFreeIntBuffer(
    VIDEO_INTMEM_HANDLER_T* prHandler,
    kal_uint8* pu1FreeAddr,
    kal_uint32 u4FreeSize)
{
    kal_uint32  i;
    kal_uint32 u4Size = ((u4FreeSize + 3)>>2)<<2;
    kal_uint8* pu1FreeEnd = pu1FreeAddr + u4Size;
    kal_bool fgFreed = KAL_FALSE;

    drv_trace4(TRACE_GROUP_10, V2BUF_INT_FREE,
        (kal_uint32)pu1FreeAddr, u4FreeSize,
        u4Size, (kal_uint32)prHandler);

    // Check range
    if ((pu1FreeAddr < prHandler->pu1Start) ||
        (pu1FreeEnd > (prHandler->pu1Start + prHandler->u4Size)))
    {
        ASSERT(0);
    }

    i = 0;
    do{
        VIDEO_INTMEM_ATOM_T* prAtom = &prHandler->arFreeMemory[i];

        if (pu1FreeAddr == (prAtom->pu1Addr + prAtom->u4Size))
        {
            prAtom->u4Size += u4Size;
            fgFreed = KAL_TRUE;
            break;
        }
        else if (pu1FreeEnd == prAtom->pu1Addr)
        {
            prAtom->pu1Addr -= u4Size;
            prAtom->u4Size += u4Size;
            fgFreed = KAL_TRUE;
            break;
        }
    }while(++i < prHandler->u4Partition);

    if (KAL_FALSE == fgFreed)
    {
        VIDEO_INTMEM_ATOM_T* prAtom;

        if (prHandler->u4Partition >= _MAX_ALLOCATE_NUMBER)
        {
            ASSERT(0);
        }
        else
        {
            prAtom = &prHandler->arFreeMemory[prHandler->u4Partition];
            prAtom->pu1Addr = pu1FreeAddr;
            prAtom->u4Size = u4Size;
            prHandler->u4Partition++;
        }
    }
    
    return 0;
}

void VideoDeInitIntBuffer(
    VIDEO_INTMEM_HANDLER_T* prHandler,
    VIDEO_SCENARIO_T eScenario)
{
    drv_trace4(TRACE_GROUP_10, V2BUF_INT_DEINIT, prHandler->fgInit, eScenario, (kal_uint32)prHandler, 0);

    if (KAL_TRUE == prHandler->fgInit)
    {
    #if defined(__VE_MM_INTMEM_IF__)
    #if defined(__VIDEO_V2_MT6268_SERIES__)
        switch(eScenario)
        {
            case VIDEO_SCENARIO_ENCODE:
                mm_intmem_free(MM_SCEN__VIDEO_RECORD, MM_INTMEM_SEG__HW_VIDEO);
                break;
            case VIDEO_SCENARIO_DECODE:
                mm_intmem_free(MM_SCEN__VIDEO_PLAYBACK, MM_INTMEM_SEG__HW_VIDEO);
                break;
            case VIDEO_SCENARIO_VCALL:
                mm_intmem_free(MM_SCEN__VIDEO_TELEPHONY, MM_INTMEM_SEG__HW_VIDEO);
                break;
            default:
                ASSERT(0);
                break;
        }
    #endif  // __VIDEO_V2_MT6268_SERIES__
    #if defined (__VIDEO_V2_MT6236_SERIES__)
        switch(eScenario)
        {
            case VIDEO_SCENARIO_ENCODE:
                mm_intmem_free(MM_SCEN__VIDEO_RECORD, MM_INTMEM_SEG__SW_VIDEO);
                break;
            case VIDEO_SCENARIO_DECODE:
                mm_intmem_free(MM_SCEN__VIDEO_PLAYBACK, MM_INTMEM_SEG__SW_VIDEO);
                break;
            case VIDEO_SCENARIO_VCALL:
                mm_intmem_free(MM_SCEN__VIDEO_TELEPHONY, MM_INTMEM_SEG__SW_VIDEO);
                break;
            default:
                ASSERT(0);
                break;
        }
    #endif	//__VIDEO_V2_MT6236_SERIES__
    #if defined (__VIDEO_V2_MT6276_SERIES__)
        switch(eScenario)
        {
            case VIDEO_SCENARIO_ENCODE:
                mm_intmem_free(MM_SCEN__VIDEO_RECORD, MM_INTMEM_SEG__SW_VIDEO);
                break;
            case VIDEO_SCENARIO_DECODE:
                mm_intmem_free(MM_SCEN__VIDEO_PLAYBACK, MM_INTMEM_SEG__SW_VIDEO);
                break;
            case VIDEO_SCENARIO_VCALL:
                break;
            default:
                ASSERT(0);
                break;
        }
    #endif	//__VIDEO_V2_MT6276_SERIES__
    #if defined(MT6253) || defined(MT6253T)
        switch(eScenario)
        {
            case VIDEO_SCENARIO_ENCODE:
                mm_intmem_free(MM_SCEN__VIDEO_RECORD, MM_INTMEM_SEG__SW_VIDEO);
                break;
            case VIDEO_SCENARIO_DECODE:
                mm_intmem_free(MM_SCEN__VIDEO_PLAYBACK, MM_INTMEM_SEG__SW_VIDEO);
                break;
            default:
                ASSERT(0);
                break;
        }
    #endif
    #endif  // __VE_MM_INTMEM_IF__
    }

    free_ctrl_buffer((void*)prHandler);
}

kal_bool GetVideoIntBufferInitStatus(VIDEO_INTMEM_HANDLER_T* prHandler)
{
    return prHandler->fgInit;
}

#ifdef __VE_MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

kal_uint32 VideoGetRendererExtBuffer(VIDEO_EXTMEM_HANDLER_T* prMgr, kal_uint32 u4RequestSize)
{
#if defined(__VE_SPECIAL_MEM_ALLOCATION_FOR_RENDERER__)
    if (KAL_FALSE == prMgr->fgInitExtMem)
    {
        ASSERT(0);
    }

    if (rRendererMemMgr.u4Size!= u4RequestSize)
    {
        ASSERT(0);
    }

    return (kal_uint32)(rRendererMemMgr.pu1ExtStartAddr);
#else
    ASSERT(0);
    return 0;
#endif
}

#endif /*__VE_VIDEO_COMMON__*/

