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
 *  ResCache.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "MMIDataType.h"

#include "MMI_features.h"

#include "ResCache.h"

#ifdef __MMI_RESOURCE_DEBUG_TRACE_SUPPORT__
#include "MMI_fw_trc.h"
#include "DebugInitDef_Int.h"
#endif

#ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__

/* resource cache size, 100 KB, TBD */
#define RES_CACHE_POOL_SIZE (MMI_RESOURCE_IMAGE_CACHE_SIZE + 2048)

#define RES_CACHE_TWO_ADM_OVERHEAD (512)
#define RES_CACHE_NODE_GUARD_PATTERN        0x1234
#define RES_CACHE_POOL_GUARD_PATTERN_BEGIN  0x16881688
#define RES_CACHE_POOL_GUARD_PATTERN_END    0x88618861

#define RES_CACHE_NODE_FLAG_DEFAULT     0
#define RES_CACHE_NODE_FLAG_FLUSHABLE   (1 << 0)

/*
 * HASH related
 */
/* use hash search should be faster? */
#define RES_CACHE_USE_HASH_SEARCH
#define RES_CACHE_HASH_ENTRY_NUM        256
/* enable this for hash debugging and statistics variables */
// #define RES_CACHE_HASH_DEBUG

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/* cache node */
typedef struct _rsc_cache_node_struct
{
    kal_uint16 guard_pattern;
    kal_uint16 id;

    /* DDL for LRU, the newest node is always appended to the end of the list. */
    struct _rsc_cache_node_struct* next;
    struct _rsc_cache_node_struct* prev;

    /* DDL for hash */
#ifdef RES_CACHE_USE_HASH_SEARCH
    struct _rsc_cache_node_struct* hash_next;
    struct _rsc_cache_node_struct* hash_prev;    
#endif /* RES_CACHE_USE_HASH_SEARCH */

    kal_uint32 flag;
    kal_uint32 buf_size;
    void *buf;    
} rsc_cache_node_struct;

/* hash table entry */
typedef struct 
{
    rsc_cache_node_struct *tail;
#ifdef RES_CACHE_HASH_DEBUG
    kal_uint32 node_num;
#endif
} rsc_cache_hash_entry;

/* cache pool struct */
typedef struct
{
    kal_uint32 guard_pattern_begin;
    
    KAL_ADM_ID adm_id;

    void *mutex;
    
    rsc_cache_node_struct *head;
    rsc_cache_node_struct *tail;    
    
    kal_uint32 cache_node_num;
    kal_uint32 used_size;
    kal_uint32 free_size;
    kal_uint32 total_size;
    
    kal_uint32 guard_pattern_end;
} rsc_cache_pool_struct;
    
#ifdef __MMI_RESOURCE_DEBUG_TRACE_SUPPORT__
#define MAX_PIN_IMAGE_HANDLE 50
typedef struct
{
	U32 pin_handler_list[MAX_PIN_IMAGE_HANDLE];
	U32 pin_mem;
	U32 pin_objID_num;
}MMIResourceSlimTrace;

static MMIResourceSlimTrace ResSlimTrace;
#endif


static rsc_cache_node_struct *rsc_cache_pool_del(RES_CACHE_HANDLE_T cachePool, rsc_cache_node_struct *n);

/* hash table, all pool shares the same one. */
// TODO: individual hash table should be better
#ifdef RES_CACHE_USE_HASH_SEARCH
static rsc_cache_hash_entry g_rsc_hash_table[RES_CACHE_HASH_ENTRY_NUM];
#endif

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* STATIC CACHE BUFFER */
static kal_uint32 g_rsc_mem_pool[RES_CACHE_POOL_SIZE / sizeof(U32)];
static KAL_ADM_ID g_rsc_adm_pool;

static kal_bool g_rsc_is_inited = KAL_FALSE;

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

#ifdef RES_CACHE_USE_HASH_SEARCH

/*****************************************************************************
 * FUNCTION
 *  rsc_hash_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  code       [IN]
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint32 rsc_hash_function(kal_uint32 code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return code & 0xFF;
}


/*****************************************************************************
 * FUNCTION
 *  rsc_hash_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cachePool       [IN]
 *  objectID        [IN]
 * RETURNS
 *  
 *****************************************************************************/
static rsc_cache_node_struct *rsc_hash_search(rsc_cache_hash_entry *rsc_hash_table, U16 objectID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rsc_cache_node_struct *n;    
    kal_uint32 i;
    rsc_cache_hash_entry *h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = rsc_hash_function((kal_uint32)objectID);
    ASSERT(i < RES_CACHE_HASH_ENTRY_NUM);    
    
    h = &rsc_hash_table[i];

    for (n = h->tail; n; n = n->hash_prev)
    {
        if (objectID == n->id)
        {
            return n;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  rsc_hash_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsc_hash_table  [IN]
 *  objectID        [IN]
 *  n               [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void rsc_hash_add(rsc_cache_hash_entry *rsc_hash_table, U16 objectID, rsc_cache_node_struct *n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;
    rsc_cache_hash_entry *h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = rsc_hash_function((kal_uint32)objectID);
    ASSERT(i < RES_CACHE_HASH_ENTRY_NUM);    
    h = &rsc_hash_table[i];

    if (h->tail == NULL)
    {
        n->hash_prev = NULL;
        n->hash_next = NULL;
    }
    else
    {
        h->tail->hash_next = n;
        n->hash_prev = h->tail;
        n->hash_next = NULL;
    }

    h->tail = n;    

#ifdef RES_CACHE_HASH_DEBUG
    h->node_num++;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  rsc_hash_del
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsc_hash_table  [IN]
 *  objectID        [IN]
 *  n               [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void rsc_hash_del(rsc_cache_hash_entry *rsc_hash_table, U16 objectID, rsc_cache_node_struct *n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;
    rsc_cache_hash_entry *h;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = rsc_hash_function((kal_uint32)objectID);
    ASSERT(i < RES_CACHE_HASH_ENTRY_NUM);
    h = &rsc_hash_table[i];

    /* update DDL */
    if (n->hash_next)
    {
        n->hash_next->hash_prev = n->hash_prev;
    }

    if (n->hash_prev)
    {
        n->hash_prev->hash_next = n->hash_next;
    }

    /* update list head and tail */
    if (h->tail == n)
    {
        h->tail = n->hash_prev;
    }

#ifdef RES_CACHE_HASH_DEBUG
    h->node_num--;
#endif
}


#endif /* RES_CACHE_USE_HASH_SEARCH */


/*****************************************************************************
 * FUNCTION
 *  rsc_create_mutex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void *rsc_create_mutex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (void*)kal_create_mutex("RS$");
}


/*****************************************************************************
 * FUNCTION
 *  rsc_take_mutex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mutex       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void rsc_take_mutex(void *mutex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (kal_query_systemInit() == KAL_TRUE)
    {
        return;
    }
    
    kal_take_mutex((kal_mutexid)mutex);    
}


/*****************************************************************************
 * FUNCTION
 *  rsc_give_mutex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mutex       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void rsc_give_mutex(void *mutex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (kal_query_systemInit() == KAL_TRUE)
    {
        return;
    }
    
    kal_give_mutex((kal_mutexid)mutex);
}

 
/*****************************************************************************
 * FUNCTION
 *  rsc_init_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pool       [IN]
 *  size       [IN]
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool rsc_init_pool(void *pool, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rsc_adm_pool = kal_adm_create(pool, size, NULL, KAL_FALSE);
    ASSERT(g_rsc_adm_pool);    

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  rsc_cache_pool_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  *pool       [IN]
 *  size        [IN]
 * RETURNS
 *  
 *****************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

static kal_bool rsc_cache_pool_init(rsc_cache_pool_struct **pool, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rsc_cache_pool_struct *c;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *pool = (rsc_cache_pool_struct*)kal_adm_alloc(g_rsc_adm_pool, size + sizeof(rsc_cache_pool_struct) + RES_CACHE_TWO_ADM_OVERHEAD);
    c = *pool;

    if (c == NULL)
    {
        return KAL_FALSE;
    }

    memset(c, 0, sizeof(rsc_cache_pool_struct));
    c->free_size = size;
    c->total_size = size;    

    /* create cache pool adm */
    c->adm_id = kal_adm_create(c + 1, size, NULL, KAL_FALSE);
    
    if (c->adm_id == NULL)
    {
        return KAL_FALSE;
    }

    /* create mutex */
    c->mutex = rsc_create_mutex();

    c->guard_pattern_begin = RES_CACHE_POOL_GUARD_PATTERN_BEGIN;
    c->guard_pattern_end = RES_CACHE_POOL_GUARD_PATTERN_END;    

    return KAL_TRUE;
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif


/*****************************************************************************
 * FUNCTION
 *  rsc_cache_pool_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cachePool        [IN]
 *  objectID         [IN]
 *  objectSize       [IN]
 * RETURNS
 *  
 *****************************************************************************/
static rsc_cache_node_struct *rsc_cache_pool_add(RES_CACHE_HANDLE_T cachePool, U16 objectID, U32 objectSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rsc_cache_node_struct *n;
    rsc_cache_pool_struct *pool = (rsc_cache_pool_struct*)cachePool;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_RESOURCE_DEBUG_TRACE_SUPPORT__
    MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RES_MEMORY_ALLOCATE_REQUEST_NOW,objectSize + sizeof(rsc_cache_node_struct));
#endif
    n = (rsc_cache_node_struct*)kal_adm_alloc(pool->adm_id, objectSize + sizeof(rsc_cache_node_struct));

    if (n)
    {
        n->guard_pattern = RES_CACHE_NODE_GUARD_PATTERN;
        n->id = objectID;
        n->buf = (void*)(n + 1);
        n->prev = pool->tail;
        n->next = NULL;
        n->flag = RES_CACHE_NODE_FLAG_DEFAULT;
        n->buf_size = (kal_uint32)objectSize;

        if (pool->head == NULL)
        {
            pool->head = n;
        }
        else
        {
            pool->tail->next = n;
        }

        pool->tail = n;

        pool->free_size -= objectSize;
        pool->used_size += objectSize;

        pool->cache_node_num++;

	#ifdef __MMI_RESOURCE_DEBUG_TRACE_SUPPORT__
		MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RES_ALLOCATE_MEMORY_FROM_CACHE,pool->used_size);
		MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RES_IMG_HANDLE_NUM_IN_CACHE_NOW,pool->cache_node_num);
		MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RES_FREE_MEMORY_FROM_CACHE,pool->free_size);
	#endif

    #ifdef RES_CACHE_USE_HASH_SEARCH
        /* add to hash */
        rsc_hash_add(g_rsc_hash_table, objectID, n);
    #endif
    
        return n;
    }   

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  rsc_cache_pool_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cachePool        [IN]
 *  objectID         [IN]
 *  objectSize       [IN]
 * RETURNS
 *  
 *****************************************************************************/
static rsc_cache_node_struct *rsc_cache_pool_del(RES_CACHE_HANDLE_T cachePool, rsc_cache_node_struct *n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rsc_cache_pool_struct *pool = (rsc_cache_pool_struct*)cachePool;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update DDL */
    if (n->next)
    {
        n->next->prev = n->prev;       
    }

    if (n->prev)
    {
        n->prev->next = n->next;
    }

    /* update list head and tail */
    if (pool->head == n)
    {
        pool->head = n->next;
    }

    if (pool->tail == n)
    {
        pool->tail = n->prev;
    }

    /* update pool statistics info */
    pool->free_size += n->buf_size;
    pool->used_size -= n->buf_size;

#ifdef RES_CACHE_USE_HASH_SEARCH
    rsc_hash_del(g_rsc_hash_table, n->id, n);
#endif
    
    /* free it */
    kal_adm_free(pool->adm_id, n);        

    pool->cache_node_num--;

#ifdef __MMI_RESOURCE_DEBUG_TRACE_SUPPORT__
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RES_ALLOCATE_MEMORY_FROM_CACHE,pool->used_size);
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RES_IMG_HANDLE_NUM_IN_CACHE_NOW,pool->cache_node_num);
	MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RES_FREE_MEMORY_FROM_CACHE,pool->free_size);
#endif

    return n;
}


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  CreateResObjectCache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sizeInBytes       [IN]
 * RETURNS
 *  
 *****************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

RES_CACHE_HANDLE_T RscCreateResObjectCache(U32 sizeInBytes)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rsc_cache_pool_struct *res_cache_pool;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_rsc_is_inited)
    {
        rsc_init_pool(g_rsc_mem_pool, RES_CACHE_POOL_SIZE);
        g_rsc_is_inited = KAL_TRUE;
    }
    
    rsc_cache_pool_init(&res_cache_pool, (kal_uint32)sizeInBytes);
            
    return (RES_CACHE_HANDLE_T)res_cache_pool;
}

#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

/*****************************************************************************
 * FUNCTION
 *  RetrieveResObjectFromCache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cachePool       [IN]
 *  objectID        [IN]
 * RETURNS
 *  
 *****************************************************************************/
S8* RscRetrieveResObjectFromCache(RES_CACHE_HANDLE_T cachePool, U16 objectID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rsc_cache_node_struct *n = NULL;
    rsc_cache_pool_struct *pool = (rsc_cache_pool_struct*)cachePool;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsc_take_mutex(pool->mutex);

#ifdef RES_CACHE_USE_HASH_SEARCH

    /* hash search */
    n = rsc_hash_search(g_rsc_hash_table, objectID);

#else /* RES_CACHE_USE_HASH_SEARCH */

    /* linear search */
    for (n = pool->head; n; n = n->next)
    {
        if (objectID == n->id)
        {
            rsc_give_mutex(pool->mutex);
            break;
        }
    }
    
#endif /* RES_CACHE_USE_HASH_SEARCH */

    rsc_give_mutex(pool->mutex);
    
    if (n == NULL)
    {
        return NULL;
    }
    
    return (S8*)n->buf;
}


/*****************************************************************************
 * FUNCTION
 *  PrepareResObjectInCache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cachePool        [IN]
 *  objectID         [IN]
 *  objectSize       [IN]
 * RETURNS
 *  
 *****************************************************************************/
S8* RscPrepareResObjectInCache(RES_CACHE_HANDLE_T cachePool, U16 objectID, U32 objectSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rsc_cache_node_struct *n;
    rsc_cache_node_struct *cache_node;
    rsc_cache_pool_struct *pool = (rsc_cache_pool_struct*)cachePool;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsc_take_mutex(pool->mutex);
    
    cache_node = rsc_cache_pool_add(cachePool, objectID, objectSize);    

    // free flushable nodes and retry
    if (cache_node == NULL)
    {
        n = pool->head;
        while (n)
        {            
            rsc_cache_node_struct *next = n->next;
            
            // free flushable nodes
            if (!(n->flag & RES_CACHE_NODE_FLAG_FLUSHABLE))
            {                   
                rsc_cache_pool_del(cachePool, n);
                
                // try to add again if free size is enough
                if (pool->free_size > objectSize)
                {
                    cache_node = rsc_cache_pool_add(cachePool, objectID, objectSize);
                    if (cache_node)
                    {
                        // allocated, done
                        break;
                    }
                }
            }

            n = next;
        }    
    }

    rsc_give_mutex(pool->mutex);
    
    if (cache_node == NULL)
    {
        return NULL;
    }

    return (S8*)cache_node->buf;
}


/*****************************************************************************
 * FUNCTION
 *  SaveResObjectToCache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cachePool        [IN]
 *  objectID         [IN]
 *  objectData       [IN]
 *  objectSize       [IN]
 * RETURNS
 *  
 *****************************************************************************/
BOOL RscSaveResObjectToCache(RES_CACHE_HANDLE_T cachePool, U16 objectID, S8 *objectData, U32 objectSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rsc_cache_node_struct *c;
    rsc_cache_pool_struct *pool = (rsc_cache_pool_struct*)cachePool;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsc_take_mutex(pool->mutex);
    
    c = rsc_cache_pool_add(cachePool, objectID, objectSize);
    if (c == NULL)
    {
        return FALSE;
    }

    memcpy(c->buf, objectData, objectSize);

    rsc_give_mutex(pool->mutex);
    
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  SetObjectFlushable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cachePool         [IN]
 *  objectID          [IN]
 *  isFlushable       [IN]
 * RETURNS
 *  
 *****************************************************************************/
BOOL RscSetObjectFlushable(RES_CACHE_HANDLE_T cachePool, U16 objectID, BOOL isFlushable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rsc_cache_node_struct *n;
    rsc_cache_pool_struct *pool = (rsc_cache_pool_struct*)cachePool;
	#ifdef __MMI_RESOURCE_DEBUG_TRACE_SUPPORT__
	int i;
	BOOL FlagForDebug = FALSE;
	#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsc_take_mutex(pool->mutex);
    
    for (n = pool->head; n; n = n->next)
    {
        if (objectID == n->id)
        {
            if(isFlushable){
				#ifdef __MMI_RESOURCE_DEBUG_TRACE_SUPPORT__
				if(n->flag == RES_CACHE_NODE_FLAG_FLUSHABLE)
					{
						ResSlimTrace.pin_mem -= n->buf_size;
						ResSlimTrace.pin_objID_num--;
					
						MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RES_IMG_HANDLE_NUM_BY_PIN_NOW,ResSlimTrace.pin_objID_num);
						MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RES_PIN_MEMORY_FROM_CACHE,ResSlimTrace.pin_mem);
						
						for(i = 0; i < MAX_PIN_IMAGE_HANDLE; i++)
						{
							if(ResSlimTrace.pin_handler_list[i] != objectID && ResSlimTrace.pin_handler_list[i] != 0)
							{
								MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RES_PINED_IMG_HANDLE,ResSlimTrace.pin_handler_list[i]);
							}
							else
							{
								ResSlimTrace.pin_handler_list[i] = 0;
							}
							
						}
					}
				#endif
				
                n->flag = RES_CACHE_NODE_FLAG_DEFAULT;
            }else{
            	#ifdef __MMI_RESOURCE_DEBUG_TRACE_SUPPORT__
				if(n->flag == RES_CACHE_NODE_FLAG_DEFAULT)
					{
						ResSlimTrace.pin_mem += n->buf_size;
						ResSlimTrace.pin_objID_num++;

						MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RES_IMG_HANDLE_NUM_BY_PIN_NOW,ResSlimTrace.pin_objID_num);
						MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RES_PIN_MEMORY_FROM_CACHE,ResSlimTrace.pin_mem);

						for(i = 0; i < MAX_PIN_IMAGE_HANDLE; i++)
						{
							if(ResSlimTrace.pin_handler_list[i] != 0)
							{
								MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RES_PINED_IMG_HANDLE,ResSlimTrace.pin_handler_list[i]);
							}
							else
							{
							    if(FlagForDebug == FALSE)
							    {
							    	ResSlimTrace.pin_handler_list[i] = objectID;
									FlagForDebug = TRUE;
									MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_RES_PINED_IMG_HANDLE,ResSlimTrace.pin_handler_list[i]);
							    }
							}
							
						}
					}
				#endif
				
                n->flag |= RES_CACHE_NODE_FLAG_FLUSHABLE;            
            }
            break;
        }
    }

    rsc_give_mutex(pool->mutex);

    return TRUE;    
}


/*****************************************************************************
 * FUNCTION
 *  FlushCacheForce
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cachePool       [IN]
 * RETURNS
 *  
 *****************************************************************************/
BOOL RscFlushCacheForce(RES_CACHE_HANDLE_T cachePool)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rsc_cache_node_struct *n;
    rsc_cache_pool_struct *pool = (rsc_cache_pool_struct*)cachePool;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsc_take_mutex(pool->mutex);

    n = pool->head;
    while (n)
    {            
        rsc_cache_node_struct *next = n->next;        
        rsc_cache_pool_del(cachePool, n);        
        n = next;
    }
 
    pool->head = NULL;
    pool->tail = NULL;
    pool->cache_node_num = 0;
    pool->used_size = 0;
    pool->free_size = pool->total_size;

    rsc_give_mutex(pool->mutex);

    return TRUE;
}


#endif /* __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__ */


