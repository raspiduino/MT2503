/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2014
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
 *   AP_CSCI_dynamic.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Cross System Communication Interface
 *
 * Author:
 * -------
 *
 ****************************************************************************/

#include <string.h>
#include "kal_trace.h"
#include "kal_public_api.h"
#include "AP_CSCI_dynamic.h"
#include "CSCI_struct.h"

#define DBG_MOD MOD_DRVKBD

#if defined(__TINY_SYS__)

#include "ts_mem_config.h"

#define TOP_CHUNK (CSCI_CHUNK_HEADER_T*)((unsigned int)dynamic_CSCI_start + CSCI_OVERHEAD)

#define MIN_CHUNK_SIZE (sizeof(CSCI_USER_HEADER_T) + MIN_ALLOC_SIZE)
#define MAX_CHUNK_SIZE (sizeof(CSCI_USER_HEADER_T) + MAX_ALLOC_SIZE)

#if CSCI_DEBUG
#define DBG_CLEAR_FREECHUNK(chunk) memset((void*)CHUNK_TO_USER_ADDR(chunk), 0, CHUNKSIZE_OF(chunk))
#else
#define DBG_CLEAR_FREECHUNK
#endif

void* dynamic_CSCI_start = NULL;
void* dynamic_CSCI_end = (void*)(CSCI_INFO_BASE_ON_AP + MAX_CSCI_INFO_SIZE);

CSCI_LINKER_SYMBOL(STATIC_CSCI_START);
CSCI_LINKER_SYMBOL(STATIC_CSCI_END);
CSCI_LINKER_SYMBOL(STATIC_CSCI_LENGTH);

static unsigned char chksum32_8(const void* start, unsigned int size)
{
    unsigned char result = 0;
    unsigned int temp = 0;
    volatile unsigned int* i;

    if (!size)
        return 0;

    size /= sizeof(int);

    for (i = (volatile unsigned int*)start; size > 0; size--, i++)
        temp ^= *i;

    result = result ^ temp;
    temp = temp >> 8;
    result = result ^ temp;
    temp = temp >> 8;
    result = result ^ temp;
    temp = temp >> 8;
    result = result ^ temp;

    return result;
}

static void update_chunk_chksum(CSCI_CHUNK_HEADER_T* chunk)
{
    chunk->checksum = CSCI_CHUNK_HEADER_ID;
    chunk->checksum = chksum32_8((void*)chunk, sizeof(CSCI_USER_HEADER_T));
}

static char AP_is_CSCI_valid(void)
{
    return ((dynamic_CSCI_start != NULL) && 
        (((CSCI_DYNAMIC_HEADER_T*)dynamic_CSCI_start)->magic == CSCI_HEADER_MAGIC) && 
        !chksum32_8(dynamic_CSCI_start, sizeof(CSCI_DYNAMIC_HEADER_T)));
}

static void write_chunk_header(void* addr, unsigned int prevSize, unsigned int size, char use)
{
    ((CSCI_CHUNK_HEADER_T*)addr)->in_use = use;
    ((CSCI_CHUNK_HEADER_T*)addr)->reserved = 0;
    ((CSCI_CHUNK_HEADER_T*)addr)->prev_size = prevSize;
    ((CSCI_CHUNK_HEADER_T*)addr)->size = size;
}

static void update_following_prevsize(CSCI_CHUNK_HEADER_T* following, unsigned int sz)
{
    if (IS_VALID_CHUNK(following))
        following->prev_size = sz;
    update_chunk_chksum(following);
}

static void csci_merge_free_chunks(CSCI_CHUNK_HEADER_T* first, CSCI_CHUNK_HEADER_T* second)
{
    /* Check whether any of the two chunks to be merged
     * is MAX-sized.
     * If yes, skip merge process.
     */
    if (CHUNKSIZE_OF(first) < MAX_ALLOC_SIZE && CHUNKSIZE_OF(second) < MAX_ALLOC_SIZE)
    {
        unsigned int newSize;
        CSCI_CHUNK_HEADER_T* following;

        following = (CSCI_CHUNK_HEADER_T*)FOLLOW_CHUNK_NEXT(second);

        /* Calculate the merged size */
        newSize = CHUNKSIZE_OF(first) + CHUNKSIZE_OF(second) + sizeof(CSCI_FREE_CHUNK_T);       
#if CSCI_DEBUG            
        memset((void*)second, 0, sizeof(CSCI_USER_HEADER_T));
#endif
        if (newSize > MAX_ALLOC_SIZE)
        {
            void* new_second;
            /* The merged size is over max chunk size. Separate them to 2 free chunks */                                   

            if (newSize < (MAX_ALLOC_SIZE + MIN_CHUNK_SIZE))
            {
                /* result to a near-max chunk and a minimum free chunk */               
                update_following_prevsize(following, CHUNK_REC_SIZE(MIN_ALLOC_SIZE));
                first->size = CHUNK_REC_SIZE(newSize - MIN_CHUNK_SIZE);
                update_chunk_chksum(first);
                DBG_CLEAR_FREECHUNK(first);
                
                /* mark the 2nd chunk */
                new_second = (void*)FOLLOW_CHUNK_NEXT(first);
                write_chunk_header(new_second, first->size, CHUNK_REC_SIZE(MIN_ALLOC_SIZE), 0);
                update_chunk_chksum(new_second);
                DBG_CLEAR_FREECHUNK(new_second);
            }
            else
            {
                /* Separte to a MAX chunk and the leftover chunk */
                update_following_prevsize(following, CHUNK_REC_SIZE(newSize - MAX_CHUNK_SIZE));
                first->size = CHUNK_REC_SIZE(MAX_ALLOC_SIZE);
                update_chunk_chksum(first);
                DBG_CLEAR_FREECHUNK(first);
                
                /* mark the 2nd chunk */
                new_second = (void*)FOLLOW_CHUNK_NEXT(first);
                write_chunk_header(new_second, first->size, following->prev_size, 0);                
                update_chunk_chksum(new_second);
                DBG_CLEAR_FREECHUNK(new_second);
            }
        }
        else /* Merge to one chunk */
        {
            first->size = CHUNK_REC_SIZE(newSize);
            update_chunk_chksum(first);
            update_following_prevsize(following, first->size);
        }
    }
}

int csci_init(int first_boot)
{
    int sz_remaining;
    unsigned int csci_ptr;
    CSCI_FREE_CHUNK_T* prev = NULL;

    /* Calculate Dynamic CSCI start addr */
    dynamic_CSCI_start = (void*)CSCI_NEXT_ALIGNMENT(&STATIC_CSCI_END);

    if (!first_boot)
        return 0;
    
    sz_remaining = ((unsigned int)dynamic_CSCI_end - (unsigned int)dynamic_CSCI_start - CSCI_OVERHEAD);
    if (sz_remaining < MIN_CHUNK_SIZE)
        return -1; // Not enough space for any allocation            

    /* Fill CSCI header */
    ((CSCI_DYNAMIC_HEADER_T*)dynamic_CSCI_start)->magic = CSCI_HEADER_MAGIC;
    ((CSCI_DYNAMIC_HEADER_T*)dynamic_CSCI_start)->block_size = ((unsigned int)dynamic_CSCI_end - (unsigned int)dynamic_CSCI_start)/CSCI_ALLOC_ALIGNMENT;
    ((CSCI_DYNAMIC_HEADER_T*)dynamic_CSCI_start)->version = CSCI_VERSION;
#if CSCI_DEBUG
    ((CSCI_DYNAMIC_HEADER_T*)dynamic_CSCI_start)->debug = 1;    
#else
    ((CSCI_DYNAMIC_HEADER_T*)dynamic_CSCI_start)->debug = 0;
#endif
    ((CSCI_DYNAMIC_HEADER_T*)dynamic_CSCI_start)->reserved = 0;
    ((CSCI_DYNAMIC_HEADER_T*)dynamic_CSCI_start)->checksum = 0;
    ((CSCI_DYNAMIC_HEADER_T*)dynamic_CSCI_start)->checksum = chksum32_8(dynamic_CSCI_start, sizeof(CSCI_DYNAMIC_HEADER_T));

#if CSCI_DEBUG
    csci_ptr = ((unsigned int)dynamic_CSCI_start + sizeof(CSCI_DYNAMIC_HEADER_T));

    memset((void*)csci_ptr, 0, sz_remaining);
    
    ((CSCI_DEBUG_HEADER_T*)csci_ptr)->magic = CSCI_DBG_MAGIC;
    ((CSCI_DEBUG_HEADER_T*)csci_ptr)->entries = CSCI_DBG_ENTRIES;
    ((CSCI_DEBUG_HEADER_T*)csci_ptr)->checksum = chksum32_8((const void*)csci_ptr, sizeof(CSCI_DEBUG_HEADER_T));
#endif

    csci_ptr = (unsigned int)TOP_CHUNK;

    /* Mark free chunks */
    while(sz_remaining >= MIN_CHUNK_SIZE)
    {
        int size;        
        
        if (sz_remaining > MAX_CHUNK_SIZE)
            if (sz_remaining < (MAX_CHUNK_SIZE + MIN_CHUNK_SIZE))
                size = MAX_ALLOC_SIZE - MIN_CHUNK_SIZE;
            else
                size = MAX_ALLOC_SIZE;
        else
            size = sz_remaining - sizeof(CSCI_USER_HEADER_T);

        /* write header */
        if (prev != NULL)
            write_chunk_header((void*)csci_ptr, prev->hdr.size, CHUNK_REC_SIZE(size), 0);
        else
            write_chunk_header((void*)csci_ptr, 0, CHUNK_REC_SIZE(size), 0);

        update_chunk_chksum((void*)csci_ptr);

        //kal_prompt_trace(MOD_ENG, "this size=%d\n", size>>2);

        prev = (CSCI_FREE_CHUNK_T*)csci_ptr;
        csci_ptr += (size + sizeof(CSCI_USER_HEADER_T));
        sz_remaining -= (size + sizeof(CSCI_USER_HEADER_T));
    };

    return 0;
}

int csci_alloc(size_t size, char* key, void** addr)
{
    CSCI_CHUNK_HEADER_T* iter;
    CSCI_FREE_CHUNK_T* target;
    CSCI_CHUNK_HEADER_T* following;
    int sz;
    CSCI_USER_HEADER_T* user;
    char is_full_occupied = 0;

    /* CSCI Check */
    if (!AP_is_CSCI_valid())
        return CSCI_ERR_NOT_INITIALIZED;

    /* Sanity Check */
    if (size <= 0)
    {
        kal_prompt_trace(DBG_MOD, "size <= 0\n");
        return CSCI_ERR_INVALID_SIZE;
    }

    if (addr == NULL)
    {
        return CSCI_ERR_INVALID_ADDR;
    }

    if (strlen(key) != CSCI_ALLOC_KEY_LENGTH)
    {
        return CSCI_ERR_INVALID_KEY;
    }

    /* Align allocating size */
    sz = (size + CSCI_ALIGNMENT_MASK) & ~CSCI_ALIGNMENT_MASK;

    if (sz > MAX_ALLOC_SIZE)
    {
        return CSCI_ERR_INVALID_SIZE;
    }
    
    sz = CHUNK_REC_SIZE(sz);

    iter = TOP_CHUNK;
    target = NULL; 
    
    do
    {
        if (IS_USER_CHUNK(iter))
        {
            if (!memcmp(((CSCI_USER_HEADER_T*)iter)->key, key, CSCI_ALLOC_KEY_LENGTH))
            {
                kal_prompt_trace(DBG_MOD, "invalid key: %s\n", key);
                return CSCI_ERR_DUP_KEY;                
            }
        }
        else  // a free chunk
        {
            if (iter->size == sz)
            {
                /* Just fit the size. Choose this */
                target = (CSCI_FREE_CHUNK_T*)iter;
                break;
            }
            if (iter->size > sz)
                if (!target || iter->size < target->hdr.size)
                    target = (CSCI_FREE_CHUNK_T*)iter;
        }               

        iter = (CSCI_CHUNK_HEADER_T*)FOLLOW_CHUNK_NEXT(iter);
    }while(IS_VALID_CHUNK(iter));

    if (!target)
    {
        kal_prompt_trace(DBG_MOD, "no space\n");
        return CSCI_ERR_NO_SPACE;
    }

    //kal_prompt_trace(DBG_MOD, "found target chunk addr:%x\n", target);
    //kal_prompt_trace(DBG_MOD, "prev_size=%d, size=%d\n", target->hdr.prev_size, target->hdr.size);

    following = (CSCI_CHUNK_HEADER_T*)(CHUNK_TO_USER_ADDR(target) + CHUNK_REAL_SIZE(target->hdr.size));
    
    if (target->hdr.size <= (sz + (sizeof(CSCI_USER_HEADER_T)/CSCI_ALLOC_ALIGNMENT))) //<8 bytes can't become another free chunk
    {
        /* no free space left can make another free chunk */        
        sz = target->hdr.size; //give all of free space
        is_full_occupied = 1;
    }
    else
    {
        /* mark new free chunk */
        write_chunk_header(target, target->hdr.prev_size, target->hdr.size-sz-(sizeof(CSCI_USER_HEADER_T)/CSCI_ALLOC_ALIGNMENT)-1, 0);    
        update_chunk_chksum((void*)target);
    }

    /* modify following chunk's prev_size */
    update_following_prevsize(following, sz);

    /* mark user chunk */
    user = (CSCI_USER_HEADER_T*)((unsigned int)following - CHUNK_REAL_SIZE(sz) - sizeof(CSCI_USER_HEADER_T));
    if (is_full_occupied)
        write_chunk_header(user, target->hdr.prev_size, sz, 1);
    else
        write_chunk_header(user, target->hdr.size, sz, 1);
    memcpy(user->key, key, CSCI_ALLOC_KEY_LENGTH); // write key
    update_chunk_chksum((void*)user);
    *addr = (void*)CHUNK_TO_USER_ADDR(user);
    return CHUNK_REAL_SIZE(sz);
}

int csci_free(void* addr)
{
    CSCI_CHUNK_HEADER_T* chunk;
    CSCI_CHUNK_HEADER_T* tmp;

    /* CSCI Check */
    if (!AP_is_CSCI_valid())
        return CSCI_ERR_NOT_INITIALIZED;        

    chunk = (CSCI_CHUNK_HEADER_T*)USER_TO_CHUNK_ADDR(addr);

    /* Check sanity */
    if (!IS_USER_CHUNK(chunk))
        return CSCI_ERR_INVALID_ADDR;

    /* clear use flag */
    chunk->in_use = 0;
    update_chunk_chksum((void*)chunk);
    DBG_CLEAR_FREECHUNK(chunk);

#if CSCI_DEBUG
{
    CSCI_DEBUG_HEADER_T* header = (CSCI_DEBUG_HEADER_T*)CSCI_DEBUG_HEADER;
    CSCI_DEBUG_ENTRY_T* entry = &((CSCI_DEBUG_ENTRY_T*)CSCI_DEBUG_FIRST_ENTRY)[header->index];    
    
    memcpy(entry->key, ((CSCI_USER_HEADER_T*)chunk)->key, CSCI_ALLOC_KEY_LENGTH);
    entry->block_offset = ((unsigned int)CHUNK_TO_USER_ADDR(chunk) - (unsigned int)&STATIC_CSCI_START)/CSCI_ALLOC_ALIGNMENT;
    entry->block_size = CHUNKSIZE_OF(chunk)/CSCI_ALLOC_ALIGNMENT;
    kal_get_time(&entry->tick);
    entry->valid = 1;

    header->index = (header->index + 1) % CSCI_DBG_ENTRIES;
}
#endif

    /* check whether next chunk is free */
    tmp = (CSCI_CHUNK_HEADER_T*)FOLLOW_CHUNK_NEXT(chunk);
    if (IS_FREE_CHUNK(tmp))
        csci_merge_free_chunks(chunk, tmp);

    /* check whether prev chunk is free */
    tmp = (CSCI_CHUNK_HEADER_T*)FOLLOW_CHUNK_PREV(chunk);
    if (IS_FREE_CHUNK(tmp))
        csci_merge_free_chunks(tmp, chunk);
    
    return 0;
}

void* csci_addr(char *key)
{
    CSCI_CHUNK_HEADER_T* iter;

    /* CSCI Check */
    if (!AP_is_CSCI_valid())
        return NULL;
    
    /* Check sanity */
    if (key == NULL)
        return NULL;

    iter = TOP_CHUNK;
    
    do
    {
        if (IS_USER_CHUNK(iter) && !memcmp(((CSCI_USER_HEADER_T*)iter)->key, key, CSCI_ALLOC_KEY_LENGTH))
            return CHUNK_TO_USER_ADDR(iter);
        
        iter = (CSCI_CHUNK_HEADER_T*)FOLLOW_CHUNK_NEXT(iter);
    }while(IS_VALID_CHUNK(iter));
    return NULL;
}

int csci_size(void *addr)
{
    CSCI_CHUNK_HEADER_T* ptr;

    /* CSCI Check */
    if (!AP_is_CSCI_valid())
        return CSCI_ERR_NOT_INITIALIZED;
    
    /* Check sanity */
    if (addr == NULL)
        return CSCI_ERR_INVALID_ADDR;
    
    ptr = (CSCI_CHUNK_HEADER_T*)USER_TO_CHUNK_ADDR(addr);
    if (IS_USER_CHUNK(ptr))
        return CHUNK_REAL_SIZE(ptr->size);

    return CSCI_ERR_INVALID_ADDR;
}

#pragma arm section code = "SNORCODE", rodata = "SNORCONST"

void AP_CSCI_backup_dynamic(void)
{
    CSCI_CHUNK_HEADER_T* iter;
    kal_uint32 ts_dynamic_CSCI_start;
    
    /* CSCI Check */
    if (!AP_is_CSCI_valid())
    {
        return;
    }

    ts_dynamic_CSCI_start = CSCI_NEXT_ALIGNMENT(CSCI_INFO_BASE_ON_TINY + (unsigned int)&STATIC_CSCI_LENGTH);
    
#if CSCI_DEBUG
    {        
        kal_uint32* src = (kal_uint32*)dynamic_CSCI_start;
        kal_uint32* dst = (kal_uint32*)ts_dynamic_CSCI_start;            
        kal_uint32* end = (kal_uint32*)dynamic_CSCI_end;
    
        for (; src < end; dst++, src++)
            *dst= *src;
    }
#else
    /* Copy CSCI header To Tiny */
    *(CSCI_DYNAMIC_HEADER_T*)ts_dynamic_CSCI_start = *(CSCI_DYNAMIC_HEADER_T*)dynamic_CSCI_start;
    
    iter = TOP_CHUNK;

    /* traverse each chunk */
    do
    {
        unsigned int next_chunk_addr;
    
        if (!IS_VALID_CHUNK(iter))
            return;

        next_chunk_addr = (((unsigned int)iter) + sizeof(CSCI_USER_HEADER_T) + CHUNKSIZE_OF(iter));
        
        if (IS_USER_CHUNK(iter))
        {
            /* it's user chunk, do copy full chunk */
            kal_uint32* src = (kal_uint32*)iter;
            kal_uint32* dst = (kal_uint32*)((unsigned int)iter - CSCI_INFO_BASE_ON_AP + CSCI_INFO_BASE_ON_TINY);            
            kal_uint32* end = (kal_uint32*)next_chunk_addr;
        
            for (; src < end; dst++, src++)
                *dst= *src; 
        }
        else
        {
            /* it's free chunk, only copy chunk header */
            *(CSCI_FREE_CHUNK_T*)((unsigned int)iter - CSCI_INFO_BASE_ON_AP + CSCI_INFO_BASE_ON_TINY) = *(CSCI_FREE_CHUNK_T*)iter;
        }
        
        iter = (CSCI_CHUNK_HEADER_T*)next_chunk_addr;
    }while(IS_VALID_CHUNK(iter));
#endif
}

#pragma arm section code , rodata

void dump_csci(void)
{
    int i;
    kal_prompt_trace(DBG_MOD, "           %08x %08x %08x %08x %08x %08x %08x %08x\n           ",
            0, 4, 8, 12, 16, 20, 24, 28);
    for(i=0;i<71;i++)
        kal_prompt_trace(DBG_MOD, "=");
    kal_prompt_trace(DBG_MOD, "\n");
    
    for(i=0;i<CSCI_ALLOC_SIZE;i+=32)
    {
        kal_prompt_trace(DBG_MOD, "%08x | %08x %08x %08x %08x %08x %08x %08x %08x\n",
            (unsigned int)dynamic_CSCI_start+i,
            *(unsigned int*)((unsigned int)dynamic_CSCI_start+i), 
            *(unsigned int*)((unsigned int)dynamic_CSCI_start+i+4),
            *(unsigned int*)((unsigned int)dynamic_CSCI_start+i+8),
            *(unsigned int*)((unsigned int)dynamic_CSCI_start+i+12),
            *(unsigned int*)((unsigned int)dynamic_CSCI_start+i+16),
            *(unsigned int*)((unsigned int)dynamic_CSCI_start+i+20),
            *(unsigned int*)((unsigned int)dynamic_CSCI_start+i+24),
            *(unsigned int*)((unsigned int)dynamic_CSCI_start+i+28));
    }
}

void dbg_csci()
{
    CSCI_CHUNK_HEADER_T* iter = TOP_CHUNK;
    CSCI_CHUNK_HEADER_T* prev = NULL;

    do{
        if (IS_FREE_CHUNK(iter))
        {
            kal_prompt_trace(DBG_MOD, "free(%d):%x\n", CHUNK_REAL_SIZE(iter->size), iter);
        }
        else if (IS_USER_CHUNK(iter))
        {
            kal_prompt_trace(DBG_MOD, "used(%d):%x(%c%c%c%c)\n", CHUNK_REAL_SIZE(iter->size), iter, ((CSCI_USER_HEADER_T*)iter)->key[0], ((CSCI_USER_HEADER_T*)iter)->key[1], ((CSCI_USER_HEADER_T*)iter)->key[2], ((CSCI_USER_HEADER_T*)iter)->key[3]);
        }
        else
        {
            kal_prompt_trace(DBG_MOD, "Error!!!!\n");
            return;
        }

        if (prev && iter->prev_size != prev->size)
        {
            kal_prompt_trace(DBG_MOD, "Size mismatch!!! prev_size=%d, prev->size=%d\n", iter->prev_size, prev->size);
            return;
        }

        prev = iter;
        iter = (CSCI_CHUNK_HEADER_T*)FOLLOW_CHUNK_NEXT(iter);
    }while(IS_VALID_CHUNK(iter));
}

#else /* defined(__TINY_SYS__) */

#define DUMMY_CSCI_INIT csci_init
#define DUMMY_CSCI_ALLOC csci_alloc
#define DUMMY_CSCI_FREE csci_free
#define DUMMY_CSCI_ADDR csci_addr
#define DUMMY_CSCI_SIZE csci_size

int DUMMY_CSCI_INIT(int first_boot){return 0;}
int DUMMY_CSCI_ALLOC(size_t size, char* key, void** addr){return 0;}
int DUMMY_CSCI_FREE(void* addr){return 0;}
void* DUMMY_CSCI_ADDR(char *key){return NULL;}
int DUMMY_CSCI_SIZE(void *addr){return 0;}

#endif

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
	
