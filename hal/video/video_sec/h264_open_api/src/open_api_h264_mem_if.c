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
 *   open_api_h264_mem_if.c
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

#if defined(__H264_SW_OPEN_API_SUPPORT__) || defined (__H264_HW_OPEN_API_SUPPORT__)

#include "drv_comm.h"
#include "cache_sw.h"
#include "mmu.h"
#include "open_api_h264_mem_if.h"
#include "med_status.h"
#include "vcodec_v2_trc.h"

static KAL_ADM_ID pBsAdmId = NULL;
static KAL_ADM_ID pFrmAdmId = NULL;

#define OPEN_API_BUF_RESERVED 256
#define OPEN_API_CACHELINE_ALIGN(data)                                 \
    (((kal_uint32)(data) + (kal_uint32)CPU_CACHE_LINE_SIZE_MASK) & ~((kal_uint32)CPU_CACHE_LINE_SIZE_MASK))

#if defined(DRV_FEATURE__MM_INTMEM_IF)   

#include "mm_intmem.h"

static OPEN_API_INTMEM_T gOpenApiIntMem;

void OpenAPIInitIntBuffer(void)
{
    kal_uint32 addr, size;

    mm_intmem_get(MM_SCEN__VIDEO_PLAYBACK, MM_INTMEM_SEG__SW_VIDEO, &addr, &size);
    
    gOpenApiIntMem.int_ram_start_ptr = (kal_uint32 *)addr;
    gOpenApiIntMem.int_ram_total_length = size;
    gOpenApiIntMem.int_ram_init = KAL_TRUE;
    gOpenApiIntMem.int_ram_index = 0;
}


kal_uint32 OpenAPIGetIntBuffer(kal_uint32 nSize)
{
    kal_uint32 nAddr;
    nAddr = (kal_uint32)&gOpenApiIntMem.int_ram_start_ptr[gOpenApiIntMem.int_ram_index];
    gOpenApiIntMem.int_ram_index += ((nSize + 3) >> 2);
    if ((gOpenApiIntMem.int_ram_index * 4) > gOpenApiIntMem.int_ram_total_length)
    {
        ASSERT(0);
    }
    return nAddr;
}


void OpenAPIDeInitIntBuffer(void)
{
    mm_intmem_free(MM_SCEN__VIDEO_PLAYBACK, MM_INTMEM_SEG__SW_VIDEO);
    gOpenApiIntMem.int_ram_total_length = 0;
    gOpenApiIntMem.int_ram_index = 0;
    gOpenApiIntMem.int_ram_init = KAL_FALSE;
}
#endif /*DRV_FEATURE__MM_INTMEM_IF*/

kal_bool OpenAPIIsExtBufferCacheable(kal_uint32 u4StartAddr, kal_uint32 u4Size)
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


kal_uint32 OpenAPIExtBufferCacheableSwitch(kal_uint32 u4StartAddr, kal_uint32 u4Size, OPEN_API_MEMORY_SWITCH_T eSwitch)
{
    kal_uint32 u4ShiftByte = 0;

    switch(eSwitch)
    {
    case OPEN_API_CACHEABLE:
        if (INT_QueryIsCachedRAM(u4StartAddr, u4Size))
        {
            ASSERT(0);
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

#if defined(__MTK_TARGET__)
        dynamic_switch_cacheable_region((void*)&u4StartAddr, u4Size, PAGE_CACHEABLE);
#endif
        break;

    case OPEN_API_NON_CACHEABLE:
        if (INT_QueryIsNonCachedRAM(u4StartAddr, u4Size))
        {
            ASSERT(0);
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
#if defined(__MTK_TARGET__)
        dynamic_switch_cacheable_region((void*)&u4StartAddr, u4Size, PAGE_NO_CACHE);
#endif
        break;

    default:
        ASSERT(0);
        break;
    }

    return (u4StartAddr + u4ShiftByte);
}


kal_uint32 OpenAPIExtBufferCacheableSwitchAlignMemory(kal_uint32 u4StartAddr, kal_uint32 u4Size, OPEN_API_MEMORY_SWITCH_T eSwitch)
{
    kal_uint32 u4ShiftByte = 0;

    switch(eSwitch)
    {
    case OPEN_API_CACHEABLE:
        if (INT_QueryIsCachedRAM(u4StartAddr, u4Size))
        {
            ASSERT(0);
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
#if defined(__MTK_TARGET__)
        dynamic_switch_cacheable_region((void*)&u4StartAddr, u4Size, PAGE_CACHEABLE);
#endif
        break;
    case OPEN_API_NON_CACHEABLE:
        if (INT_QueryIsNonCachedRAM(u4StartAddr, u4Size))
        {
            ASSERT(0);
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
#if defined(__MTK_TARGET__)
        dynamic_switch_cacheable_region((void*)&u4StartAddr, u4Size, PAGE_NO_CACHE);
#endif
        break;
    default:
        ASSERT(0);
        break;
    };

    return (u4StartAddr + u4ShiftByte);
}


MEDIA_STATUS_CODE VideoH264DecMemInit(kal_uint32 u4BsAddr, kal_uint32 u4BsSize, 
                                                                                kal_uint32 u4FrmAddr, kal_uint32 u4FrmSize)
{
    drv_trace4(TRACE_GROUP_10, OPEN_API_VIDEOH264DECMEMINIT, u4BsAddr, u4BsSize, u4FrmAddr, u4FrmSize);

    if ((!u4BsAddr) || (u4BsSize < OPEN_API_BUF_RESERVED) || (!u4FrmAddr) || (u4FrmSize < OPEN_API_BUF_RESERVED))
    {
        ASSERT(0);
        return VIDEO_ERROR;
    }
    
#if defined(DRV_FEATURE__MM_INTMEM_IF)      
    OpenAPIInitIntBuffer();
#endif


    if ((pBsAdmId != NULL) || (pFrmAdmId != NULL))
    {
        ASSERT(0);
        return VIDEO_ERROR;        
    }
    
    pBsAdmId = kal_adm_create((void*)u4BsAddr, u4BsSize, NULL, KAL_FALSE);
    if (pBsAdmId == NULL)
    {
        ASSERT(0);
        return VIDEO_ERROR;
    }
    
    pFrmAdmId = kal_adm_create((void*)u4FrmAddr, u4FrmSize, NULL, KAL_FALSE);
    if (pFrmAdmId == NULL)
    {
        ASSERT(0);
        return VIDEO_ERROR;
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    

    return MEDIA_STATUS_OK;
}


void VideoH264DecMemDeInit(void)
{
    drv_trace0(TRACE_GROUP_10,OPEN_API_VIDEOH264DECMEMDEINIT);
#if defined(DRV_FEATURE__MM_INTMEM_IF)    
    OpenAPIDeInitIntBuffer();
#endif

    if (pBsAdmId)
    {
        kal_adm_delete(pBsAdmId);
        pBsAdmId = NULL;
    }
    if (pFrmAdmId)
    {
        kal_adm_delete(pFrmAdmId);
        pFrmAdmId = NULL;
    }

    return;
}

kal_uint32 VideoH264DecMemGetBsBuffer(kal_uint32 u4Size)
{
    kal_uint32 u4Addr = 0;
#if defined(__H264_SW_OPEN_API_SUPPORT__)
    u4Addr = (kal_uint32)kal_adm_alloc_cacheable(pBsAdmId, u4Size, PAGE_SIZE_4KB);
#endif
#if defined(__H264_HW_OPEN_API_SUPPORT__)
    u4Addr = (kal_uint32)kal_adm_alloc_noncacheable(pBsAdmId, u4Size, PAGE_SIZE_4KB); 
#endif
    if (!u4Addr)
    {
        ASSERT(0);
    }

    drv_trace2(TRACE_GROUP_10,OPEN_API_VIDEOH264DECMEMGETBSBUFFER, u4Size, u4Addr);
    return u4Addr;
}

kal_uint32 VideoH264DecMemGetYUVBuffer(kal_uint32 u4Size)
{
    kal_uint32 u4Addr = 0;

    u4Addr = (kal_uint32)kal_adm_alloc_noncacheable(pFrmAdmId, u4Size, PAGE_SIZE_4KB);

    if (!u4Addr)
    {
        ASSERT(0);
    }

    drv_trace2(TRACE_GROUP_10,OPEN_API_VIDEOH264DECMEMGETYUVBUFFER, u4Size, u4Addr);
    return u4Addr;
}

void VideoH264DecMemFreeBsBuffer(kal_uint32 u4Addr)
{
    drv_trace1(TRACE_GROUP_10,OPEN_API_VIDEOH264DECMEMFREEBSBUFFER,u4Addr);
    kal_adm_free(pBsAdmId, (void *)u4Addr);
}

#endif /* H264_SW_OPEN_API_SUPPORT */

