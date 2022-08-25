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

/*******************************************************************************
 * Filename:
 * ---------
 *  med_ext_smalloc.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "kal_release.h"
#include "kal_trace.h"
#include "med_global.h"
#include "med_mem.h"
#include "med_trc.h"
#include "med_smalloc.h"
#include "cache_sw.h"
#include "mmu.h"
#include "init.h"

#include "stack_ltlcom.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "string.h"
#include "kal_internal_api.h"
typedef struct med_temp_list_struct{
    struct med_temp_list_struct *next;
    kal_uint32 size;
    void (*free_notify_callback)(void*); /* this callback function should make sure thread-safe by each user */
} med_temp_list_struct;

typedef struct{
    KAL_ADM_ID ext_mem_pool_id;
    kal_uint32 ext_mem_alloc_count;
    kal_uint32 ext_mem_left_size;
    med_temp_list_struct *temp_mem_list;
    KAL_ADM_ID aud_mem_pool_id;
    kal_uint32 aud_mem_alloc_count;
    kal_uint32 aud_mem_left_size;
    #ifdef __VIDEO_STANDALONE_MEMORY__
    KAL_ADM_ID vid_mem_pool_id;
    kal_uint32 vid_mem_alloc_count;
    kal_uint32 vid_mem_left_size;
    #endif
    kal_bool is_debug_info_on;
}med_ext_mem_struct;

med_ext_mem_struct g_med_ext_mem_cntx;
extern kal_mutexid med_mem_mutex;

#define med_ext_smalloc_ex(size) med_ext_smalloc_ext(size,1,__FILE__, __LINE__)
#define MED_MEMORY_WITH_TEMPORARY_FLAG      0x80

#if defined(__MED_MEM_CACHEABLE_SUPPORT__)
#define MED_MEM_CACHEABLE_ALIGN_SIZE  32
#else
#define MED_MEM_CACHEABLE_ALIGN_SIZE  4
#endif

#define MED_MEM_FRAMEBUFFER_ALIGN_SIZE 32


#if defined(__MED_MEM_DEBUG_ON__)
    #define MED_MEM_ALLOC(adm_id,size,f,l)               kal_adm_alloc_dbg(adm_id,size,f,l)
    #define MED_MEM_ALLOC_TOPMOST_CACHEABLE(adm_id, size, a, f, l)       kal_adm_alloc_c_topmost_dbg(adm_id, size, a, f, l)
    #define MED_MEM_ALLOC_TOPMOST(adm_id, size, a, f, l)       kal_adm_alloc_topmost_dbg(adm_id, size, a, f, l)
    #define MED_MEM_ALLOC_CACHEABLE(adm_id, size, option, f, l)     kal_adm_alloc_cacheable_dbg(adm_id, size, option, f, l)
    #define MED_MEM_ALLOC_FRAMEBUFFER(adm_id, size, a, f, l)   kal_adm_alloc_align_dbg(adm_id, size, a, f, l)
#else
    #define MED_MEM_ALLOC(adm_id,size,f,l)               kal_adm_alloc(adm_id,size)
    #define MED_MEM_ALLOC_TOPMOST(adm_id, size, a, f, l)       kal_adm_alloc_topmost(adm_id, size, a)
    #define MED_MEM_ALLOC_TOPMOST_CACHEABLE(adm_id, size, a, f, l)       kal_adm_alloc_c_topmost(adm_id, size, a)
    #define MED_MEM_ALLOC_CACHEABLE(adm_id, size, option, f, l)     kal_adm_alloc_cacheable(adm_id, size, option)
    #define MED_MEM_ALLOC_FRAMEBUFFER(adm_id, size, a, f, l)   kal_adm_alloc_align(adm_id, size, a)
#endif

/*****************************************************************************
 * FUNCTION
 *  med_ext_release_temporyary
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void med_ext_release_temporyary(size_type size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int free_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(free_size = 0;g_med_ext_mem_cntx.temp_mem_list != NULL && free_size < size;)
    {
        med_temp_list_struct *list = g_med_ext_mem_cntx.temp_mem_list;
    
        /* deattach from temp_list ( FILO )*/
        g_med_ext_mem_cntx.temp_mem_list = list->next;
    
        /* process this item */
        list->free_notify_callback(((address_t)list)+sizeof(med_temp_list_struct));
        free_size += list->size;
    
        /* free this item */
        med_ext_sfree((address_t)list);
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_ext_smalloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static address_t med_ext_release_temporary_and_alloc(size_type size, unsigned short location, const char *file, int line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    address_t ret_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        /* try to call 2nd level real allocation */
        ret_ptr = med_ext_smalloc_ext(size,(unsigned short)(location|MED_MEMORY_WITH_TEMPORARY_FLAG),file,line);
        if(ret_ptr||g_med_ext_mem_cntx.temp_mem_list==NULL) break; /* success get memory */
        med_ext_release_temporyary(size);

    }while(1);
    return ret_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  med_ext_smalloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
address_t med_ext_smalloc_temp(size_type size, unsigned short location, void (*callback)(void*), const char* file, int line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    address_t ret_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(callback != NULL);

    if (size == 0)
    {
        return NULL;
    }
    
    size += sizeof(med_temp_list_struct);
    
    /* try to call 2nd level real allocation */
    ret_ptr = med_ext_smalloc_ext(size,location|MED_MEMORY_WITH_TEMPORARY_FLAG ,file,line);

    if(ret_ptr)
    {
        med_temp_list_struct *list = (med_temp_list_struct *)ret_ptr;

        /* initialize list header */
        memset(list,0,sizeof(med_temp_list_struct));
        list->free_notify_callback = callback;
        list->size = size;

        /* attach to temp_list ( FILO ) */
        list->next = g_med_ext_mem_cntx.temp_mem_list;
        g_med_ext_mem_cntx.temp_mem_list = list;

        /* shift to real memory begin */
        ret_ptr += sizeof(med_temp_list_struct);
    }
    return ret_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  med_ext_smalloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void med_ext_sfree_temp(address_t ptr) /* this function is called by user, it will not invoke callback */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_temp_list_struct *parent,*list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_med_ext_mem_cntx.temp_mem_list != NULL); /* ptr should inside the temp_list */
    
    ptr -= sizeof(med_temp_list_struct); /* shift to temp list header */

    parent = (med_temp_list_struct *)&g_med_ext_mem_cntx.temp_mem_list;
    list   = parent->next;
    
    for(; list != NULL; parent = list,list = list->next)
    {
        if((address_t)list == ptr)
        {
            parent->next = list->next; /* remove this item from temp_list */
            med_ext_sfree(ptr); /* free this item */
            return;
        }
    }
    ASSERT(0); /* can't find this memory from temp_list */
}


/*****************************************************************************
 * FUNCTION
 *  med_ext_smalloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
address_t med_ext_smalloc(size_type size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    address_t ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(med_mem_mutex);    
    ptr = med_ext_smalloc_ex(size);
    kal_give_mutex(med_mem_mutex);
    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  med_ext_smalloc_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
address_t med_ext_smalloc_ext(size_type size, unsigned short location, const char *file, int line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size == 0)
    {
        return NULL;
    }
    
    /* steal location 1 bit as a flag to identify is 2nd recursive allocate */
    if(!(location & MED_MEMORY_WITH_TEMPORARY_FLAG)) /* 1st level allocation: should try to free before allocate */
    {
        // TODO: To find out a better way to control the memory fragmentation problem instead of freeing all temp memory
        if (location == MED_EXT_MEMORY_TYPE_TOPPEST_CACHEABLE || location == MED_EXT_MEMORY_TYPE_TOPPEST_NONCACHEABLE)
        {
            med_ext_release_temporyary(MED_EXT_MEM_SIZE);
        }
    
        return med_ext_release_temporary_and_alloc(size,location,file,line);
    }

    location &= ~MED_MEMORY_WITH_TEMPORARY_FLAG;
    

    switch(location)
    {
        case MED_EXT_MEMORY_TYPE_NONCACHEABLE:
        case MED_EXT_MEMORY_TYPE_CACHEABLE:
        case MED_EXT_MEMORY_TYPE_FRAMEBUFFER:
        case MED_EXT_MEMORY_TYPE_TOPPEST_NONCACHEABLE:
        case MED_EXT_MEMORY_TYPE_TOPPEST_CACHEABLE:
            if (g_med_ext_mem_cntx.ext_mem_pool_id == 0)
                return NULL;           
        break;
        case MED_EXT_MEMORY_TYPE_AUDIO_NONCACHEABLE:
        case MED_EXT_MEMORY_TYPE_AUDIO_CACHEABLE:
        case MED_EXT_MEMORY_TYPE_TOPPEST_AUDIO_NONCACHEABLE:
		case MED_EXT_MEMORY_TYPE_TOPPEST_AUDIO_CACHEABLE:
            if (g_med_ext_mem_cntx.aud_mem_pool_id == 0)
                return NULL;
        break;
    #ifdef __VIDEO_STANDALONE_MEMORY__
        case MED_EXT_MEMORY_TYPE_VIDEO_NONCACHEABLE:
        case MED_EXT_MEMORY_TYPE_VIDEO_CACHEABLE:
            if (g_med_ext_mem_cntx.vid_mem_pool_id == 0)
                return NULL;
        break;            
    #endif /* __VIDEO_STANDALONE_MEMORY__ */
    }

    if (location == MED_EXT_MEMORY_TYPE_CACHEABLE)
    {
        ptr = MED_MEM_ALLOC_CACHEABLE(g_med_ext_mem_cntx.ext_mem_pool_id, size, MED_MEM_CACHEABLE_ALIGN_SIZE, basename((char *)file), line);
    }
    else if (location == MED_EXT_MEMORY_TYPE_TOPPEST_NONCACHEABLE)
    {
        ptr = MED_MEM_ALLOC_TOPMOST(g_med_ext_mem_cntx.ext_mem_pool_id, size, MED_MEM_CACHEABLE_ALIGN_SIZE, basename((char *)file), line);
    }
    else if (location == MED_EXT_MEMORY_TYPE_TOPPEST_CACHEABLE)
    {
        ptr = MED_MEM_ALLOC_TOPMOST_CACHEABLE(g_med_ext_mem_cntx.ext_mem_pool_id, size, MED_MEM_CACHEABLE_ALIGN_SIZE, basename((char *)file), line);
    }
    else if (location == MED_EXT_MEMORY_TYPE_FRAMEBUFFER)
    {
        if (size%32!=0)
        {
            size = (size+31)/32*32;
        }
        ptr = MED_MEM_ALLOC_CACHEABLE(g_med_ext_mem_cntx.ext_mem_pool_id, size, MED_MEM_FRAMEBUFFER_ALIGN_SIZE, basename((char *)file), line);

        #if defined (__DYNAMIC_SWITCH_CACHEABILITY__)
        if (INT_QueryIsCachedRAM(ptr, size) == KAL_TRUE)
        {
            dynamic_switch_cacheable_region((void*)&ptr, size, PAGE_NO_CACHE);
        }
        #endif
    }
    else if (location == MED_EXT_MEMORY_TYPE_AUDIO_NONCACHEABLE)
    {
        ptr = MED_MEM_ALLOC(g_med_ext_mem_cntx.aud_mem_pool_id, size,basename((char *)file), line);
    }
    else if (location == MED_EXT_MEMORY_TYPE_AUDIO_CACHEABLE)
    {
        ptr = MED_MEM_ALLOC_CACHEABLE(g_med_ext_mem_cntx.aud_mem_pool_id, size, MED_MEM_CACHEABLE_ALIGN_SIZE, basename((char *)file), line);
    }
    else if (location == MED_EXT_MEMORY_TYPE_TOPPEST_AUDIO_NONCACHEABLE)
    {
        ptr = MED_MEM_ALLOC_TOPMOST(g_med_ext_mem_cntx.aud_mem_pool_id, size, MED_MEM_CACHEABLE_ALIGN_SIZE, basename((char *)file), line);
    }
    else if (location == MED_EXT_MEMORY_TYPE_TOPPEST_AUDIO_CACHEABLE)
    {
        ptr = MED_MEM_ALLOC_TOPMOST_CACHEABLE(g_med_ext_mem_cntx.aud_mem_pool_id, size, MED_MEM_CACHEABLE_ALIGN_SIZE, basename((char *)file), line);
    }
#ifdef __VIDEO_STANDALONE_MEMORY__    
    else if (location == MED_EXT_MEMORY_TYPE_VIDEO_NONCACHEABLE)
    {
        ptr = MED_MEM_ALLOC(g_med_ext_mem_cntx.vid_mem_pool_id, size,basename((char *)file), line);
    }
    else if (location == MED_EXT_MEMORY_TYPE_VIDEO_CACHEABLE)
    {
        ptr = MED_MEM_ALLOC_CACHEABLE(g_med_ext_mem_cntx.vid_mem_pool_id, size, MED_MEM_CACHEABLE_ALIGN_SIZE, basename((char *)file), line);
    }
#endif
    else
    {
        ptr = MED_MEM_ALLOC(g_med_ext_mem_cntx.ext_mem_pool_id, size,basename((char *)file), line);
    }

    if (ptr!=NULL)
    {
        if (location == MED_EXT_MEMORY_TYPE_AUDIO_NONCACHEABLE ||
            location == MED_EXT_MEMORY_TYPE_AUDIO_CACHEABLE ||
            location == MED_EXT_MEMORY_TYPE_TOPPEST_AUDIO_NONCACHEABLE ||
           	location == MED_EXT_MEMORY_TYPE_TOPPEST_AUDIO_CACHEABLE)
        {
            g_med_ext_mem_cntx.aud_mem_alloc_count++;
            g_med_ext_mem_cntx.aud_mem_left_size = kal_adm_get_total_left_size(g_med_ext_mem_cntx.aud_mem_pool_id);
            MED_MEM_INFO_AUD(MED_AUD_MEM_SIZE, size, g_med_ext_mem_cntx.aud_mem_left_size, ptr, g_med_ext_mem_cntx.aud_mem_alloc_count);
        }
    #ifdef __VIDEO_STANDALONE_MEMORY__  
        else if (location == MED_EXT_MEMORY_TYPE_VIDEO_NONCACHEABLE ||
                 location == MED_EXT_MEMORY_TYPE_VIDEO_CACHEABLE)
        {
            g_med_ext_mem_cntx.vid_mem_alloc_count++;
            g_med_ext_mem_cntx.vid_mem_left_size = kal_adm_get_total_left_size(g_med_ext_mem_cntx.vid_mem_pool_id);
            MED_MEM_INFO_AUD(MED_VID_MEM_SIZE, size, g_med_ext_mem_cntx.vid_mem_left_size, ptr, g_med_ext_mem_cntx.vid_mem_alloc_count);
        }
    #endif
        else
        {
            g_med_ext_mem_cntx.ext_mem_alloc_count++;
            g_med_ext_mem_cntx.ext_mem_left_size = kal_adm_get_total_left_size(g_med_ext_mem_cntx.ext_mem_pool_id);
            MED_MEM_INFO(MED_EXT_MEM_SIZE, size, g_med_ext_mem_cntx.ext_mem_left_size, ptr, g_med_ext_mem_cntx.ext_mem_alloc_count);
        }
    }
    else
    {
        if (location == MED_EXT_MEMORY_TYPE_AUDIO_NONCACHEABLE ||
            location == MED_EXT_MEMORY_TYPE_AUDIO_CACHEABLE ||
            location == MED_EXT_MEMORY_TYPE_TOPPEST_AUDIO_NONCACHEABLE ||
           	location == MED_EXT_MEMORY_TYPE_TOPPEST_AUDIO_CACHEABLE)
        {
            if (g_med_ext_mem_cntx.is_debug_info_on == KAL_TRUE)
            {
                kal_adm_print_log(g_med_ext_mem_cntx.aud_mem_pool_id);
            }

            if (size < kal_adm_get_total_left_size(g_med_ext_mem_cntx.aud_mem_pool_id))
            {
                /* fragmentation */
                MED_MEM_FRAGMENTATION_AUD(MED_AUD_MEM_SIZE, size, g_med_ext_mem_cntx.aud_mem_left_size,g_med_ext_mem_cntx.aud_mem_alloc_count);
            }
            else
            {
                /* concurrent */
                MED_MEM_CONCURRENT_AUD(MED_AUD_MEM_SIZE, size, g_med_ext_mem_cntx.aud_mem_left_size,g_med_ext_mem_cntx.aud_mem_alloc_count);
            }
        }
    #ifdef __VIDEO_STANDALONE_MEMORY__        
        else if (location == MED_EXT_MEMORY_TYPE_VIDEO_NONCACHEABLE ||
                 location == MED_EXT_MEMORY_TYPE_VIDEO_CACHEABLE)
        {
            if (g_med_ext_mem_cntx.is_debug_info_on == KAL_TRUE)
            {
                kal_adm_print_log(g_med_ext_mem_cntx.vid_mem_pool_id);
            }

            if (size < kal_adm_get_total_left_size(g_med_ext_mem_cntx.vid_mem_pool_id))
            {
                /* fragmentation */
                MED_MEM_FRAGMENTATION_AUD(MED_VID_MEM_SIZE, size, g_med_ext_mem_cntx.vid_mem_left_size,g_med_ext_mem_cntx.vid_mem_alloc_count);
            }
            else
            {
                /* concurrent */
                MED_MEM_CONCURRENT_AUD(MED_VID_MEM_SIZE, size, g_med_ext_mem_cntx.vid_mem_left_size,g_med_ext_mem_cntx.vid_mem_alloc_count);
            }
        }
    #endif /* __VIDEO_STANDALONE_MEMORY__ */
        else
        {

            if (g_med_ext_mem_cntx.is_debug_info_on == KAL_TRUE)
            {
                kal_adm_print_log(g_med_ext_mem_cntx.ext_mem_pool_id);
            }

            if (size < kal_adm_get_total_left_size(g_med_ext_mem_cntx.ext_mem_pool_id))
            {
                /* fragmentation */
                MED_MEM_FRAGMENTATION(MED_EXT_MEM_SIZE, size, g_med_ext_mem_cntx.ext_mem_left_size,g_med_ext_mem_cntx.ext_mem_alloc_count);
            }
            else
            {
                /* concurrent */
                MED_MEM_CONCURRENT(MED_EXT_MEM_SIZE, size, g_med_ext_mem_cntx.ext_mem_left_size,g_med_ext_mem_cntx.ext_mem_alloc_count);
            }
        }
    }
    return (address_t) ptr;
}   /* malloc */


/*****************************************************************************
 * FUNCTION
 *  med_ext_sfree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_ext_sfree(address_t ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ptr!=NULL)
    {
        kal_adm_free(g_med_ext_mem_cntx.ext_mem_pool_id, ptr);
        g_med_ext_mem_cntx.ext_mem_alloc_count--;
        g_med_ext_mem_cntx.ext_mem_left_size = kal_adm_get_total_left_size(g_med_ext_mem_cntx.ext_mem_pool_id);
        MED_FREE_MEM_INFO(med_ext_left_size(), ptr, g_med_ext_mem_cntx.ext_mem_alloc_count );
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_aud_sfree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_aud_sfree(address_t ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ptr!=NULL)
    {
        kal_adm_free(g_med_ext_mem_cntx.aud_mem_pool_id, ptr);
        g_med_ext_mem_cntx.aud_mem_alloc_count--;
        g_med_ext_mem_cntx.aud_mem_left_size = kal_adm_get_total_left_size(g_med_ext_mem_cntx.aud_mem_pool_id);
        MED_FREE_MEM_INFO_AUD(g_med_ext_mem_cntx.aud_mem_left_size, ptr, g_med_ext_mem_cntx.aud_mem_alloc_count );
    }
}


/*****************************************************************************
 * FUNCTION
 *  med_vid_sfree
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_vid_sfree(address_t ptr)
{
#ifdef __VIDEO_STANDALONE_MEMORY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ptr!=NULL)
    {
        kal_adm_free(g_med_ext_mem_cntx.vid_mem_pool_id, ptr);
        g_med_ext_mem_cntx.vid_mem_alloc_count--;
        g_med_ext_mem_cntx.vid_mem_left_size = kal_adm_get_total_left_size(g_med_ext_mem_cntx.vid_mem_pool_id);
        MED_FREE_MEM_INFO_AUD(g_med_ext_mem_cntx.vid_mem_left_size, ptr, g_med_ext_mem_cntx.vid_mem_alloc_count);
    }
#endif
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif
/*****************************************************************************
 * FUNCTION
 *  med_set_ext_memory_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  memory      [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_set_ext_memory_pool(address_t memory, size_type size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_med_ext_mem_cntx.ext_mem_pool_id = kal_adm_create(
                                            memory,
                                            size,
                                            NULL,
                                    #if defined(__MED_MEM_DEBUG_ON__)
                                            KAL_TRUE
                                    #else                                            
                                            KAL_FALSE
                                    #endif
                                            );
    g_med_ext_mem_cntx.ext_mem_alloc_count = 0;
    g_med_ext_mem_cntx.ext_mem_left_size = size;
    
    g_med_ext_mem_cntx.temp_mem_list = NULL;
    g_med_ext_mem_cntx.is_debug_info_on = KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  med_set_aud_memory_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  memory      [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_set_aud_memory_pool(address_t memory, size_type size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_med_ext_mem_cntx.aud_mem_pool_id = kal_adm_create(
                                            memory,
                                            size,
                                            NULL,
                                    #if defined(__MED_MEM_DEBUG_ON__)
                                            KAL_TRUE
                                    #else                                            
                                            KAL_FALSE
                                    #endif
                                            );
    g_med_ext_mem_cntx.aud_mem_alloc_count = 0;
    g_med_ext_mem_cntx.aud_mem_left_size = size;
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif


/*****************************************************************************
 * FUNCTION
 *  med_set_vid_memory_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  memory      [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void med_set_vid_memory_pool(address_t memory, size_type size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VIDEO_STANDALONE_MEMORY__    
    g_med_ext_mem_cntx.vid_mem_pool_id = kal_adm_create(
                                            memory,
                                            size,
                                            NULL,
                                    #if defined(__MED_MEM_DEBUG_ON__)
                                            KAL_TRUE
                                    #else                                            
                                            KAL_FALSE
                                    #endif
                                            );
    g_med_ext_mem_cntx.vid_mem_alloc_count = 0;
    g_med_ext_mem_cntx.vid_mem_left_size = size;
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  med_ext_left_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
size_type med_ext_left_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_med_ext_mem_cntx.ext_mem_left_size;
}

/*****************************************************************************
 * FUNCTION
 *  med_ext_total_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
size_type med_ext_total_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MED_EXT_MEM_SIZE;
}

/*****************************************************************************
 * FUNCTION
 *  med_ext_used_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
size_type med_ext_used_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MED_EXT_MEM_SIZE-g_med_ext_mem_cntx.ext_mem_left_size;
}


/*****************************************************************************
 * FUNCTION
 *  med_ext_debug_info_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void med_ext_debug_info_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_med_ext_mem_cntx.is_debug_info_on = KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  med_ext_debug_info_off
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void med_ext_debug_info_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_med_ext_mem_cntx.is_debug_info_on = KAL_FALSE;
}
