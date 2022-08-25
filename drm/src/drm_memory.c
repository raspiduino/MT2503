/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * drm_memory.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *  Contains OS Abstraction Interface function declarations for
 *  allocating, reallocating and freeing memory. Normally the
 *  implementation of these are \#define-s to CRT functions malloc(),
 *  realloc() and free().
 *
 * Author:
 * -------
 * -------
 * -------
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
#ifdef __DRM_SUPPORT__

#include "drm_memory.h"
#include "drm_util.h"
#include "drm_trace.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "string.h"
#include "kal_public_defs.h"
#include "kal_internal_api.h"

#if !defined(__DRM_EXTERNAL__)
//#define DRM_MEM_LOG_ON
//#define DRM_MEM_CHECK_ON
#define DRM_MEM_DEBUG(x, y) kal_trace y
#define DRM_MEM_DEBUGP(x) drm_trace x   /* print */
#define DRM_MEM_DEBUGE(x) drm_trace x   /* must print , error info */
#else /* DRM_MEM_DEBUG_ON */
#define DRM_MEM_DEBUG(x, y) kal_trace y
#define DRM_MEM_DEBUGP(x)
#define DRM_MEM_DEBUGE(x)
#endif /* DRM_MEM_DEBUG_ON */ 

#if defined(__DRM_V02__)
#define DRM_MEM_SIZE (150 * 1024)
#elif defined(__DRM_EXTERNAL__) 
#define DRM_MEM_SIZE (32 * 1024)
#else
#define DRM_MEM_SIZE (4 * 12 * 1024)
#endif 

/* Use kal_uint32 to be 4-byte aligned */
static KAL_ADM_ID drmt_mem_id = NULL;
static kal_uint32 drmt_mem_pool[DRM_MEM_SIZE / 4] = {0};
static kal_mutexid drmt_mem_mutex;

#ifdef DRM_MEM_EVAL_ON
static kal_bool drmt_eval_on = KAL_FALSE;
#endif 

#define DRM_MEM_MUTEX_BEGIN        kal_take_mutex(drmt_mem_mutex)
#define DRM_MEM_MUTEX_END       kal_give_mutex(drmt_mem_mutex)

#ifdef DRM_MEM_EVAL_ON

#define DRM_MEM_RECORD_TBL_SIZE 256

typedef struct
{
    void *ptr;
    kal_int32 line;
    kal_int32 size;
    kal_int32 seq;
    kal_char filename[16];
} drmt_mem_record;

static drmt_mem_record record_tbl[DRM_MEM_RECORD_TBL_SIZE];

static kal_int32 start_evalute_size;
static kal_int32 end_evalute_size;
static kal_int32 evalute_seq = 0;
static kal_int32 max_use_mem = 0;


/*****************************************************************************
 * FUNCTION
 *  drmt_mem_find_rec
 * DESCRIPTION
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *****************************************************************************/
kal_int32 drmt_mem_find_rec(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ptr == NULL)
    {
        for (i = 0; i < DRM_MEM_RECORD_TBL_SIZE; i++)
        {
            if (record_tbl[i].ptr == NULL)
            {

                return i;
            }
        }
        return -1;
    }
    else
    {

        for (i = 0; i < DRM_MEM_RECORD_TBL_SIZE; i++)
        {
            if (record_tbl[i].ptr == ptr)
            {

                return i;
            }
        }
        return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  drmt_mem_del_rec
 * DESCRIPTION
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *****************************************************************************/
kal_int32 drmt_mem_del_rec(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ptr == NULL)
    {
        memset(record_tbl, 0, sizeof(record_tbl));
        evalute_seq = 0;
        return 0;
    }
    else
    {
        index = drmt_mem_find_rec(ptr);
        if (index >= 0)
        {
            memset(&record_tbl[index], 0, sizeof(drmt_mem_record));
            return 0;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_mem_add_rec
 * DESCRIPTION
 * PARAMETERS
 *  ptr             [?]         
 *  size            [IN]        
 *  filename        [IN]        
 *  line            [IN]        
 * RETURNS
 *****************************************************************************/
kal_int32 drmt_mem_add_rec(void *ptr, kal_int32 size, const char *filename, int line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = drmt_mem_find_rec(NULL);

    if (index >= 0)
    {
        strncpy(record_tbl[index].filename, filename, 15);
        record_tbl[index].filename[15] = 0;
        record_tbl[index].line = line;
        record_tbl[index].ptr = ptr;
        record_tbl[index].size = size;
        record_tbl[index].seq = evalute_seq;
        evalute_seq++;
        return 0;
    }
    else
    {
        ASSERT(0);
        return -1;
    }
}

#endif /* DRM_MEM_EVAL_ON */ 


/*****************************************************************************
 * FUNCTION
 *  drmt_mem_init
 * DESCRIPTION
 *  Allocates memory blocks.
 * PARAMETERS
 *  void
 *  size(?)     [IN]        The size of the (continuous) memory block to allocate.(?)(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_mem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_DEBUG("[DRM] mem_init", (TRACE_GROUP_MEM, DRM_MEM_F7D4DBC76E8B4960BD93EE45FC503963));

    drmt_mem_mutex = kal_create_mutex("DRM MEM");

    memset(drmt_mem_pool, 0, DRM_MEM_SIZE);

#ifdef DRM_MEM_LOG_ON
    drmt_mem_id = kal_adm_create(drmt_mem_pool, DRM_MEM_SIZE, NULL, KAL_TRUE);
#else 
    drmt_mem_id = kal_adm_create(drmt_mem_pool, DRM_MEM_SIZE, NULL, KAL_FALSE);
#endif 

    EXT_ASSERT(drmt_mem_id, 0, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  drmt_mem_reinit
 * DESCRIPTION
 *  Allocates memory blocks.
 * PARAMETERS
 *  void
 *  size(?)     [IN]        The size of the (continuous) memory block to allocate.(?)(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_mem_reinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_DEBUG("[DRM] mem_reinit", (TRACE_GROUP_MEM, DRM_MEM_1101E0162A10E030579EDC200ACF2ABC));

    memset(drmt_mem_pool, 0, DRM_MEM_SIZE);

#ifdef DRM_MEM_LOG_ON
    drmt_mem_id = kal_adm_create(drmt_mem_pool, DRM_MEM_SIZE, NULL, KAL_TRUE);
#else 
    drmt_mem_id = kal_adm_create(drmt_mem_pool, DRM_MEM_SIZE, NULL, KAL_FALSE);
#endif 

    EXT_ASSERT(drmt_mem_id, 0, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  drmt_mem_total_left_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 drmt_mem_total_left_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 leftSize = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* DRM_MEM_DEBUG((TRACE_GROUP_3, "[DRM] mem_total_left_size")); */

    if (drmt_mem_id != 0)
    {
        leftSize = kal_adm_get_total_left_size(drmt_mem_id);
    }

    return leftSize;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_mem_check_corruption
 * DESCRIPTION
 *  Allocates memory blocks.
 * PARAMETERS
 *  void
 *  size(?)     [IN]        The size of the (continuous) memory block to allocate.(?)
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_mem_check_corruption(void)
{
#ifdef DRM_MEM_CHECK_ON
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *corrupted_mem_address = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_MUTEX_BEGIN;

    if (drmt_mem_id != 0)
    {
        corrupted_mem_address = kal_adm_check_integrity(drmt_mem_id);
        if (corrupted_mem_address != NULL)
        {
            kal_adm_print_log(drmt_mem_id);
            EXT_ASSERT(0, (int)corrupted_mem_address, (int)drmt_mem_total_left_size(), 0);
        }
    }
    DRM_MEM_MUTEX_END;
#endif /* DRM_MEM_CHECK_ON */ /* DRM_MEM_DEBUG_ON */
}


/*****************************************************************************
 * FUNCTION
 *  drmt_mem_alloc_ext
 * DESCRIPTION
 *  Allocates memory blocks.
 * PARAMETERS
 *  size        [IN]        The size of the (continuous) memory block to allocate.
 *  file        [IN]        [?]
 *  line        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *drmt_mem_alloc_ext(int size, const char *file, int line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr = NULL;

#if 1// def DRM_MEM_LOG_ON
    static int min_left_size = DRM_MEM_SIZE;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!size)
    {
        return NULL;
    }

    EXT_ASSERT(drmt_mem_id, 0, 0, 0);

    drmt_mem_check_corruption();

    DRM_MEM_MUTEX_BEGIN;
    if (drmt_mem_id)
    {

    #ifdef DRM_MEM_LOG_ON
        ptr = (kal_uint32*) kal_adm_internal_alloc(drmt_mem_id, size, basename((char*)file), line);
    #else 
        ptr = (kal_uint32*) kal_adm_alloc(drmt_mem_id, size);
    #endif 

    #ifdef DRM_MEM_EVAL_ON

        if (drmt_eval_on && ptr)
        {
            kal_int32 left_size = drmt_mem_total_left_size();

            drmt_mem_add_rec(ptr, size, basename((kal_char*) file), line);

            if (start_evalute_size - left_size > max_use_mem)
            {
                max_use_mem = start_evalute_size - left_size;
            }
        }

    #endif /* DRM_MEM_EVAL_ON */ 

        DRM_MEM_DEBUGP((TRACE_GROUP_MEM, "[DRM] mem_alloc, file: %s, %d, block:%x size:%d", basename((char*)file),
                        line, ptr, size));

        if (ptr == NULL)
        {
            if (drmt_mem_total_left_size() > (kal_uint32)size)
            {
                kal_bool FRAGMENTATION = KAL_FALSE;

                kal_adm_print_log(drmt_mem_id);
                EXT_ASSERT(FRAGMENTATION, 0, 0, 0);  /* fragmentation */
            }
            else
            {
                kal_bool OUT_OF_MEMORY = KAL_FALSE;

                kal_adm_print_log(drmt_mem_id);
                EXT_ASSERT(OUT_OF_MEMORY, 0, 0, 0);  /* out of memory */
            }
        }
        else
        {
        #if 1 //def DRM_MEM_LOG_ON
            size = drmt_mem_total_left_size();
            if (size < min_left_size)
            {
                if (size < 0)
                {
                    /* should have memory corruption */
                    EXT_ASSERT(0, 0, 0, 0);
                }
                min_left_size = size;
                DRM_MEM_DEBUGE((TRACE_GROUP_MEM, "[DRM] mem_alloc, leftsize:%d", min_left_size));
            }
        #endif /* DRM_MEM_LOG_ON */ 
        }
    }
    DRM_MEM_MUTEX_END;

    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_mem_realloc_ext
 * DESCRIPTION
 *  Reallocate memory blocks.
 * PARAMETERS
 *  memblock        [?]         [?]         [?]         [?]         [?]         [?]         [In] The block to reallocate.
 *  size            [IN]        [In] The size of the (continuous) memory block to allocate.
 *  file            [IN]        [?]
 *  line            [IN]        
 * RETURNS
 *  non-NULL: pointer to reallocated space.
 *  NULL: memory reallocation failed (original block is left
 *  unchanged) or size was not positive (the block is freed).(?)(?)(?)(?)(?)(?)
 *****************************************************************************/
void *drmt_mem_realloc_ext(void *memblock, int size, const char *file, int line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_DEBUGP((TRACE_GROUP_MEM, "[DRM] mem_realloc, file:%s %d block:%x size:%d", basename((char*)file), line,
                    memblock, size));

    if (memblock)
    {
        void *ptr = NULL;

        if (size && (ptr = drmt_mem_alloc(size)) != NULL)
        {
            /* it is not safe here */
            memcpy(ptr, memblock, size);
        }

        drmt_mem_free(memblock);

        return ptr;
    }
    else
    {
        return drmt_mem_alloc(size);
    }
}


/*****************************************************************************
 * FUNCTION
 *  drmt_mem_free_ext
 * DESCRIPTION
 *  Deallocates or frees a memory block.
 * PARAMETERS
 *  memblock        [?]         [?]         [?]     [?]     [?]     [?]     [In] The memory block to free.
 *  file            [IN]        [?]
 *  line            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_mem_free_ext(void *memblock, const char *file, int line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_DEBUGP((TRACE_GROUP_MEM, "[DRM] mem_free, file: %s %d block:%x", basename((char*)file), line, memblock));

    if (!memblock)
    {
        return;
    }

    drmt_mem_check_corruption();

    DRM_MEM_MUTEX_BEGIN;
    if (memblock)
    {
        kal_adm_free(drmt_mem_id, memblock);
    }
    DRM_MEM_MUTEX_END;

#ifdef DRM_MEM_EVAL_ON

    if (drmt_eval_on)
    {
        drmt_mem_del_rec(memblock);
    }

#endif /* DRM_MEM_EVAL_ON */ 

}


/*****************************************************************************
 * FUNCTION
 *  drmt_mem_delete
 * DESCRIPTION
 *  Deallocates or frees a memory block.
 * PARAMETERS
 *  void
 *  memblock        [?]     [?]     [?]     [?]     [In] The memory block to free.(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_mem_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_status ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MEM_DEBUG("[DRM] mem_delete", (TRACE_GROUP_MEM, DRM_MEM_C11C3F6606DFCB84F7E38CB3F53F2EDD));

    DRM_MEM_MUTEX_BEGIN;
    if (drmt_mem_id)
    {
        ret = kal_adm_delete(drmt_mem_id);
        drmt_mem_id = 0;
        ASSERT(ret == KAL_SUCCESS);
    }
    DRM_MEM_MUTEX_END;
}


/*****************************************************************************
 * FUNCTION
 *  drmt_mem_valid
 * DESCRIPTION
 * PARAMETERS
 *  address     [IN]        
 * RETURNS
 *****************************************************************************/
kal_bool drmt_mem_valid(kal_uint32 address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 start = (kal_uint32) & drmt_mem_pool[0];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (address >= start && address <= start + sizeof(drmt_mem_pool))
    {
        DRM_MEM_DEBUGP((TRACE_GROUP_MEM, "[DRM] mem valid, add:%x", address));
        return KAL_TRUE;
    }
    else
    {
        DRM_MEM_DEBUGP((TRACE_GROUP_MEM, "[DRM] mem invalid, add:%x", address));
        return KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  drmt_mem_virtual
 * DESCRIPTION
 *  to check if the memory pool is in virutal memory or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  a boolean value
 *****************************************************************************/
kal_bool drmt_mem_virtual(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 start = (kal_int32) drmt_mem_pool;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (start < 0)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  drmt_mem_set_start_eval
 * DESCRIPTION
 * PARAMETERS
 *  file            [IN]        
 *  line            [IN]        
 *  address(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_mem_set_start_eval(const kal_char *file, kal_int32 line)
{
#ifdef DRM_MEM_EVAL_ON
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drmt_mem_del_rec(NULL);
    drmt_eval_on = KAL_TRUE;
    max_use_mem = 0;
    start_evalute_size = drmt_mem_total_left_size();
#endif /* DRM_MEM_EVAL_ON */ 

}


/*****************************************************************************
 * FUNCTION
 *  drmt_mem_set_end_eval
 * DESCRIPTION
 * PARAMETERS
 *  file            [IN]        
 *  line            [IN]        
 *  address(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_mem_set_end_eval(const kal_char *file, kal_int32 line)
{
#ifdef DRM_MEM_EVAL_ON
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    end_evalute_size = drmt_mem_total_left_size();
    drmt_eval_on = KAL_FALSE;
#endif /* DRM_MEM_EVAL_ON */ 

}


/*****************************************************************************
 * FUNCTION
 *  drmt_mem_show_eval
 * DESCRIPTION
 * PARAMETERS
 *  show_log        [IN]        
 *  file            [IN]        
 *  line            [IN]        
 *  address(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drmt_mem_show_eval(kal_bool show_log, const kal_char *file, kal_int32 line)
{
#ifdef DRM_MEM_EVAL_ON
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (start_evalute_size != end_evalute_size)
    {
        DRM_MEM_DEBUGE((TRACE_GROUP_MEM, "[DRM EVAL] file = %s, line = %d, start = %d, end = %d",
                        file, line, start_evalute_size, end_evalute_size));

        if (show_log)
        {
            for (i = 0; i < DRM_MEM_RECORD_TBL_SIZE; i++)
            {
                if (record_tbl[i].ptr != NULL)
                {
                    DRM_MEM_DEBUGE((TRACE_GROUP_MEM, "[DRM EVAL] file = %s, line = %d, size = %d, seq = %d",
                                    record_tbl[i].filename, record_tbl[i].line, record_tbl[i].size, record_tbl[i].seq));
                }
            }
        }
    }
#endif /* DRM_MEM_EVAL_ON */ 
}

#endif /* __DRM_SUPPORT__ */ 

