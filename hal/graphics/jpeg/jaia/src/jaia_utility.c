/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   jaia_utility.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   ##
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_jpeg.h"
#if defined(__JAIA_SUPPORT__)

#ifdef WIN32
#include <stdio.h>
#endif

#include "kal_general_types.h"
#include "fsal.h"
#include "string.h"

#include "jaia_enum.h"
#include "jaia_structure.h"
#include "jaia_structure_int.h"

#include "mmu.h"
#include "cache_sw.h"
 

JAIA_RETURN_STATUS_ENUM jaia_utility_output_from_buffer_to_file(JAIA_HANDLE jaia_workspace, kal_uint32 dst_offset, JAIA_BUFFER *target_buffer)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_OK;
    STFSAL *dst_fsal = jaia_workspace->dst_jpeg_fsal_handle;
    JAIA_BUFFER dst_buffer;

    if (JAIA_OUTPUT_TO_FILE == jaia_workspace->dst_output_mode)
    {
        FSAL_Seek(dst_fsal, dst_offset);

        if (FSAL_OK != FSAL_Write(dst_fsal, (kal_uint8 *)target_buffer->buff_addr, target_buffer->buff_size))
        {
            return JAIA_RETURN_FSAL_OUTPUT_ERROR;
        }

        jaia_workspace->jpeg_write_index += target_buffer->buff_size;
    }
    else if (JAIA_OUTPUT_TO_MEMORY == jaia_workspace->dst_output_mode)
    {
        dst_buffer.buff_addr = jaia_workspace->dst_jpeg_file_buffer->buff_addr;
        dst_buffer.buff_size = jaia_workspace->dst_jpeg_file_buffer->buff_size;
        dst_buffer.buff_addr = (void *)((kal_uint32)dst_buffer.buff_addr + dst_offset);

        memcpy(dst_buffer.buff_addr, target_buffer->buff_addr, target_buffer->buff_size);

        jaia_workspace->jpeg_write_index += target_buffer->buff_size;
    }

    return ret_status;
}



JAIA_RETURN_STATUS_ENUM jaia_utility_output_file_to_file(JAIA_HANDLE jaia_workspace, kal_uint32 src_offset, kal_uint32 dst_offset, kal_uint32 output_size)
{
    JAIA_RETURN_STATUS_ENUM ret_status = JAIA_RETURN_OK;
    JAIA_BUFFER wb = jaia_workspace->file_copy_buffer;
    STFSAL *src_fsal = jaia_workspace->src_jpeg_fsal_handle;
    STFSAL *dst_fsal = jaia_workspace->dst_jpeg_fsal_handle;
    JAIA_BUFFER dst_buffer;
    kal_uint32 src_left_size;
    kal_uint32 cnt;

    if ((0 == output_size) || (0 == wb.buff_size) || (NULL == wb.buff_addr))
    {
        return JAIA_RETURN_FSAL_OUTPUT_ERROR;
    }

    if (JAIA_OUTPUT_TO_FILE == jaia_workspace->dst_output_mode)
    {
        FSAL_Seek(src_fsal, src_offset);
        FSAL_Seek(dst_fsal, dst_offset);

        src_left_size = output_size % wb.buff_size;

        for (cnt = 0; cnt < output_size / wb.buff_size; cnt++)
        {
            if (FSAL_OK != FSAL_Read(src_fsal, (kal_uint8 *)wb.buff_addr, wb.buff_size))
            {
                return JAIA_RETURN_FSAL_OUTPUT_ERROR;
            }

            if (FSAL_OK != FSAL_Write(dst_fsal, (kal_uint8 *)wb.buff_addr, wb.buff_size))
            {
                return JAIA_RETURN_FSAL_OUTPUT_ERROR;
            }
        }

        if (FSAL_OK != FSAL_Read(src_fsal, (kal_uint8 *)wb.buff_addr, src_left_size))
        {
            return JAIA_RETURN_FSAL_OUTPUT_ERROR;
        }

        if (FSAL_OK != FSAL_Write(dst_fsal, (kal_uint8 *)wb.buff_addr, src_left_size))
        {
            return JAIA_RETURN_FSAL_OUTPUT_ERROR;
        }

        jaia_workspace->jpeg_write_index += output_size;
    }
    else if (JAIA_OUTPUT_TO_MEMORY == jaia_workspace->dst_output_mode)
    {
        FSAL_Seek(src_fsal, src_offset);

        dst_buffer.buff_addr = jaia_workspace->dst_jpeg_file_buffer->buff_addr;
        dst_buffer.buff_size = jaia_workspace->dst_jpeg_file_buffer->buff_size;
        dst_buffer.buff_addr = (void *)((kal_uint32)dst_buffer.buff_addr + dst_offset);

        {
           kal_uint32 write_left;

           // consider source/destination overlapping case
           write_left = output_size % wb.buff_size;
           for (cnt = 0; cnt < output_size / wb.buff_size; cnt++)
           {
               if (FSAL_OK != FSAL_Read(src_fsal, (kal_uint8 *)wb.buff_addr, wb.buff_size))
               {
                   return JAIA_RETURN_FSAL_OUTPUT_ERROR;
               }
               memcpy((kal_uint8*)dst_buffer.buff_addr, (kal_uint8 *)wb.buff_addr, wb.buff_size);
               dst_buffer.buff_addr = (void*)((kal_uint32)dst_buffer.buff_addr + wb.buff_size);
           }
   
           if (FSAL_OK != FSAL_Read(src_fsal, (kal_uint8 *)wb.buff_addr, write_left))
           {
               return JAIA_RETURN_FSAL_OUTPUT_ERROR;
           }
           memcpy((kal_uint8*)dst_buffer.buff_addr, (kal_uint8 *)wb.buff_addr, write_left);
           dst_buffer.buff_addr = (void*)((kal_uint32)dst_buffer.buff_addr + write_left);
        }

        jaia_workspace->jpeg_write_index += output_size;
    }


    return ret_status;
}


#if defined(__MTK_TARGET__)

kal_bool jaia_extmem_switch_cachable_region(void **mem_ptr, kal_uint32 size, kal_bool b_cacheable)
{
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)

    kal_bool	ret = KAL_FALSE;

    if ((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(*mem_ptr))) && 
        (IS_CACHE_LINE_SIZE_ALIGNED(size)) &&
        (is_predef_dyna_c_region((kal_uint32)(*mem_ptr), size)))
    {
        if(b_cacheable == KAL_TRUE)
        {
            if(INT_QueryIsNonCachedRAM((kal_uint32 *)*mem_ptr, size) == KAL_TRUE)
            {
                dynamic_switch_cacheable_region((void **)mem_ptr, size, PAGE_CACHEABLE);
                ret = KAL_TRUE;
            }
        }
        else
        {
            if(INT_QueryIsCachedRAM((kal_uint32 *)*mem_ptr, size) == KAL_TRUE)
            {
                dynamic_switch_cacheable_region((void **)mem_ptr, size, PAGE_NO_CACHE);
                ret = KAL_TRUE;            
            }
        }
    }

	return ret;
#elif defined(__MTK_L1CACHEABLE__)

    kal_bool	ret = KAL_FALSE;
    kal_uint32 buffer_size = size;
    
    if((buffer_size%CPU_CACHE_LINE_SIZE) != 0)
    {
        buffer_size = ((buffer_size+CPU_CACHE_LINE_SIZE-1)/CPU_CACHE_LINE_SIZE)*CPU_CACHE_LINE_SIZE; 
    }

    if(b_cacheable == KAL_TRUE)
    {
        if(INT_QueryIsNonCachedRAM((kal_uint32 *)*mem_ptr, buffer_size) == KAL_TRUE)
        {
            dynamic_switch_cacheable_region((kal_uint32)(*mem_ptr), ((kal_uint32)*mem_ptr + buffer_size), buffer_size, PAGE_CACHEABLE);
            ret = KAL_TRUE;
        }
    }
    else
    {
        if(INT_QueryIsCachedRAM((kal_uint32 *)*mem_ptr, buffer_size) == KAL_TRUE)
        {
            dynamic_switch_cacheable_region((kal_uint32)(*mem_ptr), ((kal_uint32)*mem_ptr + buffer_size), buffer_size, PAGE_NO_CACHE);
            ret = KAL_TRUE;            
        }
    }

	return ret;

#endif
}

#endif


kal_bool gfxExtMemSwitchCachableRegion(void **mem_ptr, kal_uint32 size, kal_bool b_cacheable)
{
    kal_bool ret_switch = KAL_FALSE;
#ifdef __MTK_TARGET__
    kal_uint32 buffer_size = size;

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)

    if (0 != (buffer_size % CPU_CACHE_LINE_SIZE))
    {
        buffer_size = ((buffer_size + CPU_CACHE_LINE_SIZE - 1) / CPU_CACHE_LINE_SIZE) * CPU_CACHE_LINE_SIZE;
    }

    if ((IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(*mem_ptr))) && 
        (IS_CACHE_LINE_SIZE_ALIGNED(buffer_size)) &&
        (is_predef_dyna_c_region((kal_uint32)(*mem_ptr), size)))
    {
        if (KAL_TRUE == b_cacheable)
        {
            if(KAL_TRUE == INT_QueryIsNonCachedRAM((kal_uint32 *)*mem_ptr, buffer_size))
            {
                dynamic_switch_cacheable_region(mem_ptr, buffer_size, PAGE_CACHEABLE);
                ret_switch = KAL_TRUE;
            }
        }
        else
        {
            if(KAL_TRUE == INT_QueryIsCachedRAM((kal_uint32 *)*mem_ptr, buffer_size))
            {
                dynamic_switch_cacheable_region(mem_ptr, buffer_size, PAGE_NO_CACHE);
                ret_switch = KAL_TRUE;
            }
        }
    }
    
#elif defined(__MTK_L1CACHEABLE__)

    kal_bool is_wt_cache = (kal_bool)(INT_QueryIsWriteThroughCachedRAM(*mem_ptr, buffer_size));

    if (KAL_TRUE == is_wt_cache)
    {
        if(KAL_TRUE == b_cacheable)
        {
            invalidate_wt_cache((kal_uint32)*mem_ptr, buffer_size);
        }
    }
    else
    {
        if(KAL_TRUE == b_cacheable)
        {
            invalidate_l1cache((kal_uint32)*mem_ptr, buffer_size);
        }
    }
#endif

#endif /* __MTK_TARGET__ */

    return ret_switch;
}
#endif  // __JAIA_SUPPORT__

