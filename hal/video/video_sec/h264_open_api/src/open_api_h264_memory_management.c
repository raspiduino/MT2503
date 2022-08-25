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
 *   open_api_h264_memory_management.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file implements H.264 memory management functions
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include files
 *******************************************************************************/
#include "drv_comm.h"
#include "drv_features_video.h"
#if defined (__VE_H264_HW_OPEN_API_SUPPORT__) || defined(__VE_H264_DEC_HW_SUPPORT__)
#include "cache_sw.h"
#include "kal_release.h"
#include "open_api_h264_memory_management.h"

/*******************************************************************************
*   Local global variable
*******************************************************************************/
H264_WORK_MEM_STRUCT rH264WorkMem;

/*******************************************************************************
*   Extern variable
*******************************************************************************/

/*******************************************************************************
*   Extern function
*******************************************************************************/

/*******************************************************************************
*   Local static H.264 handle decode function
*******************************************************************************/

/*******************************************************************************
*   H264 memory functions
*******************************************************************************/

void h264_extmem_init(void *start_ptr, kal_uint32 length)
{
    kal_uint8 *p_video_addr = (kal_uint8*)start_ptr;
    kal_uint32 video_length = length;
    
    if(INT_QueryIsCachedRAM(start_ptr, length))
    {
        EXT_ASSERT(0, (kal_uint32)start_ptr, length, 0);		
    }
 
    ASSERT( (((kal_uint32)p_video_addr&0x03)==0)&&(rH264WorkMem.ext_ram_init==KAL_FALSE) );
    rH264WorkMem.ext_ram_start_ptr = (kal_uint32 *)p_video_addr;
    rH264WorkMem.ext_ram_total_length = video_length;
    rH264WorkMem.ext_ram_index = 0;
    rH264WorkMem.ext_ram_init = KAL_TRUE;
}

kal_uint8 *h264_extmem_get_buffer(kal_uint32 size)
{
    kal_uint8 *ptr;
    ptr = (kal_uint8 *)&rH264WorkMem.ext_ram_start_ptr[rH264WorkMem.ext_ram_index];
    rH264WorkMem.ext_ram_index += ((size+3)>>2);
    if ((rH264WorkMem.ext_ram_index*4) > rH264WorkMem.ext_ram_total_length)
    {
        ASSERT(0);
    }
    return ptr;
}

void h264_extmem_deinit(void)
{
    rH264WorkMem.ext_ram_total_length = 0;
    rH264WorkMem.ext_ram_index = 0;
    rH264WorkMem.ext_ram_init = KAL_FALSE;
}

void h264_intmem_init(void *start_ptr,kal_uint32 length)
{
    kal_uint8 *p_video_addr = (kal_uint8*)start_ptr;
    kal_uint32 video_length = length;

    if(INT_QueryIsCachedRAM(start_ptr, length))
    {
        EXT_ASSERT(0, (kal_uint32)start_ptr, length, 0);		
    } 	 

    ASSERT( (((kal_uint32)p_video_addr&0x03)==0)&&(rH264WorkMem.int_ram_init==KAL_FALSE) );
    rH264WorkMem.int_ram_start_ptr = (kal_uint32 *)p_video_addr;
    rH264WorkMem.int_ram_total_length = video_length;
    rH264WorkMem.int_ram_index = 0;
    rH264WorkMem.int_ram_init = KAL_TRUE;
}

kal_uint8 *h264_intmem_get_buffer(kal_uint32 size)
{
    kal_uint8 *ptr;
    ptr = (kal_uint8 *)&rH264WorkMem.int_ram_start_ptr[rH264WorkMem.int_ram_index];
    rH264WorkMem.int_ram_index += (((size+3)>>2));
    if ((rH264WorkMem.int_ram_index*4) > rH264WorkMem.int_ram_total_length)
    {
        ASSERT(0);
    }
    return ptr;
}

void h264_intmem_deinit(void)
{
    rH264WorkMem.int_ram_total_length = 0;
    rH264WorkMem.int_ram_index = 0;
    rH264WorkMem.int_ram_init = KAL_FALSE;
}
#endif /*#ifdef __VE_H264_HW_OPEN_API_SUPPORT__*/

