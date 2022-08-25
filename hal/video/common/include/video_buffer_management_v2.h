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
 *   video_buffer_management_v2.h
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
 ****************************************************************************/
#ifndef VIDEO_BUFFER_MANAGEMENT_V2_H
#define VIDEO_BUFFER_MANAGEMENT_V2_H

#include "drv_features_video.h"

#include "video_comm_v2.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"

///////////////////////////////////////////////////////
//                        Buffer pool management
///////////////////////////////////////////////////////

typedef struct 
{
    kal_uint32  *ext_ram_start_ptr;
    kal_uint32  ext_ram_total_length;
    kal_uint32  ext_ram_index;
    kal_uint32  *int_ram_start_ptr;
    kal_uint32  int_ram_total_length;
    kal_uint32  int_ram_index;
    kal_bool    ext_ram_init;
    kal_bool    int_ram_init;
    KAL_ADM_ID rVideoExtBufferADM;
}VIDEO_MEM_STRUCT;

typedef struct 
{
    kal_bool    fgInitExtMem;
    kal_bool    fgInitExtCacheMem;    
    kal_bool    fgWriteThrough;
    kal_uint8*  pu1ExtStartAddr;
    kal_uint32  u4ExtMemUsed;
    kal_uint32  u4ExtMemLength;
    kal_uint32  u4SpareMemLength;
    kal_uint8*  pu1ExtCacheStartAddr;
    kal_uint32  u4ExtCacheMemUsed;
    kal_uint32  u4ExtCacheMemLength;
    kal_uint32  u4SpareCacheMemLength;
    
    kal_uint8*  pu1IntStartAddr;
    kal_uint32  u4IntMemLength;

    KAL_ADM_ID rVideoExtBufferADM;
    KAL_ADM_ID rVideoExtCacheBufferADM;    
}VIDEO_EXTMEM_HANDLER_T;

typedef struct
{
    kal_uint8*  pu1ExtStartAddr;
    kal_uint32  u4Size;
}VIDEO_EXTMEM_RENDERER_T;

typedef struct
{
    kal_uint8* pu1Addr;
    kal_uint32 u4Size;
}VIDEO_INTMEM_ATOM_T;

#define _MAX_ALLOCATE_NUMBER (2)
typedef struct
{
    kal_uint8  *pu1Start;
    kal_uint32  u4Size;
    kal_bool    fgInit;
    VIDEO_SCENARIO_T eScenario;
    kal_uint32  u4Partition;
    VIDEO_INTMEM_ATOM_T arFreeMemory[_MAX_ALLOCATE_NUMBER];
}VIDEO_INTMEM_HANDLER_T;

typedef enum
{
    VIDEO_CACHEABLE = 0,
    VIDEO_NON_CACHEABLE
}VIDEO_MEMORY_SWITCH_T;

#ifdef __VE_VIDEO_COMMON__
kal_uint32 VideoCommExtBufferCacheableSwitchAlignMemory(kal_uint32 u4StartAddr, kal_uint32 u4Size, VIDEO_MEMORY_SWITCH_T eSwitch);
kal_uint32 VideoCommExtBufferCacheableSwitch(kal_uint32 u4StartAddr, kal_uint32 u4Size, VIDEO_MEMORY_SWITCH_T eSwitch);
kal_bool VideoCommIsExtBufferCacheable(kal_uint32 u4StartAddr, kal_uint32 u4Size);
kal_uint32 VideoCommFlushBuffer(kal_uint32 u4StartAddr, kal_uint32 u4Size);
kal_uint32 VideoCommInvalidateBuffer(kal_uint32 u4StartAddr, kal_uint32 u4Size);

// APIs for external memory
VIDEO_EXTMEM_HANDLER_T* VideoInitExtBuffer(kal_uint32 nStartAddr, kal_uint32 nSize, VIDEO_SCENARIO_T scenario);
void VideoDeInitExtBuffer(VIDEO_EXTMEM_HANDLER_T* prHandler);
kal_uint32 VideoGetExtBuffer(VIDEO_EXTMEM_HANDLER_T* prHandler, kal_uint32 nSize);

//Specialized API for encoder/decoder on MT6253
void VideoSetExtCacheBuffer(VIDEO_EXTMEM_HANDLER_T* prHandler, kal_uint32 u4Size);
kal_uint32 VideoGetExtCacheBuffer(VIDEO_EXTMEM_HANDLER_T* prHandler, kal_uint32 nSize);

// APIs for internal memory
VIDEO_INTMEM_HANDLER_T* VideoInitIntBuffer(kal_uint32 nStartAddr, kal_uint32 nSize, VIDEO_SCENARIO_T scenario);
void VideoDeInitIntBuffer(VIDEO_INTMEM_HANDLER_T* prHandler, VIDEO_SCENARIO_T scenario);
kal_uint32 VideoGetIntBuffer(VIDEO_INTMEM_HANDLER_T* prHandler, kal_uint32 nSize);
void VideoResetIntBuffer(VIDEO_INTMEM_HANDLER_T* prHandler);
kal_bool GetVideoIntBufferInitStatus(VIDEO_INTMEM_HANDLER_T* prHandler);
kal_uint32 VideoFreeIntBuffer(
    VIDEO_INTMEM_HANDLER_T* prHandler,
    kal_uint8* pu1FreeAddr,
    kal_uint32 u4FreeSize);

//An specialized API for Renderer
kal_uint32 VideoGetRendererExtBuffer(VIDEO_EXTMEM_HANDLER_T* prMgr, kal_uint32 u4RequestSize);
#endif

#endif /* VIDEO_BUFFER_MANAGEMENT_V2_H */ 

