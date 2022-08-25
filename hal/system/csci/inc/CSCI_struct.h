#ifndef __CSCI_STRUCT__
#define __CSCI_STRUCT__

#define CSCI_DEBUG 0
#define CSCI_VERSION 1 // 0 ~ 255
#define CSCI_HEADER_MAGIC 0xC5C1
#define CSCI_CHUNK_HEADER_ID 0xC5
#define CSCI_ALLOC_SIZE MAX_CSCI_INFO_SIZE
#define CSCI_ALLOC_ALIGNMENT 4
#define CSCI_ALIGNMENT_MASK (CSCI_ALLOC_ALIGNMENT-1)
#define CSCI_ALLOC_KEY_LENGTH 4

#define MAX_ALLOC_SIZE 4096
#define MIN_ALLOC_SIZE 4


typedef struct 
{
    unsigned int size:10;           /* 0~(2^10-1) represents 4~4096 bytes */
    unsigned int prev_size:10;      /* the real chunk size is (size+1)*4 */
    unsigned int in_use:1;          /* 0: free chunk; 1:used chunk */
    unsigned int reserved:3;
    unsigned int checksum:8;
} CSCI_CHUNK_HEADER_T;

typedef struct 
{
    CSCI_CHUNK_HEADER_T hdr;
    char key[CSCI_ALLOC_KEY_LENGTH];
} CSCI_USER_HEADER_T;

typedef struct csci_free_chunk_t
{
    CSCI_CHUNK_HEADER_T hdr;
    struct csci_free_chunk_t* next; //unused now
} CSCI_FREE_CHUNK_T;

typedef struct
{
    unsigned int block_size:16;
    unsigned int magic:16;
    ////////////////////////
    unsigned int checksum:8;
    unsigned int reserved:14;
    unsigned int debug:2;
    unsigned int version:8;
} CSCI_DYNAMIC_HEADER_T;

#if CSCI_DEBUG

typedef struct
{
    char key[CSCI_ALLOC_KEY_LENGTH];
    unsigned int tick;
    unsigned int block_offset:16;
    unsigned int block_size:16;
    char valid:1;
    char reserved:7;
} CSCI_DEBUG_ENTRY_T;

typedef struct
{
    unsigned int magic:8;
    unsigned int entries:6;
    unsigned int index:6;
    unsigned int reserved:4;
    unsigned int checksum:8;
} CSCI_DEBUG_HEADER_T;

#define CSCI_DBG_ENTRIES 16
#define CSCI_DBG_MAGIC 0xDB
#define CSCI_OVERHEAD (sizeof(CSCI_DYNAMIC_HEADER_T)+sizeof(CSCI_DEBUG_HEADER_T)+sizeof(CSCI_DEBUG_ENTRY_T)*CSCI_DBG_ENTRIES)
#define CSCI_DEBUG_HEADER ((unsigned int)dynamic_CSCI_start+sizeof(CSCI_DYNAMIC_HEADER_T))
#define CSCI_DEBUG_FIRST_ENTRY (CSCI_DEBUG_HEADER+sizeof(CSCI_DEBUG_HEADER_T))

#else //!CSCI_DEBUG
#define CSCI_OVERHEAD (sizeof(CSCI_DYNAMIC_HEADER_T))

#endif //if CSCI_DEBUG

#define CSCI_NEXT_ALIGNMENT(addr) (((unsigned int)(addr) + CSCI_ALIGNMENT_MASK) & ~CSCI_ALIGNMENT_MASK)
#define IS_VALID_CHUNK(addr) (((unsigned int)addr >= (unsigned int)dynamic_CSCI_start) && ((unsigned int)addr < (unsigned int)dynamic_CSCI_end) && CSCI_CHUNK_HEADER_ID == chksum32_8(addr, sizeof(CSCI_USER_HEADER_T)))
#define IS_USER_CHUNK(addr) (IS_VALID_CHUNK(addr) && (((CSCI_CHUNK_HEADER_T*)addr)->in_use))
#define IS_FREE_CHUNK(addr) (IS_VALID_CHUNK(addr) && !(((CSCI_CHUNK_HEADER_T*)addr)->in_use))

#define CHUNK_REAL_SIZE(sz) (((unsigned int)(sz)+1)<<2)
#define CHUNK_REC_SIZE(size) (((unsigned int)(size)>>2)-1)
#define CHUNKSIZE_OF(chk) (CHUNK_REAL_SIZE(((CSCI_CHUNK_HEADER_T*)chk)->size))


#define FOLLOW_CHUNK_NEXT(addr) ((((unsigned int)addr) + CHUNK_REAL_SIZE((CSCI_CHUNK_HEADER_T*)addr->size) + sizeof(CSCI_USER_HEADER_T)))
#define FOLLOW_CHUNK_PREV(addr) ((((unsigned int)addr) - CHUNK_REAL_SIZE((CSCI_CHUNK_HEADER_T*)addr->prev_size) - sizeof(CSCI_USER_HEADER_T)))

#define CHUNK_TO_USER_ADDR(addr) ((char*)(addr) + sizeof(CSCI_USER_HEADER_T))
#define USER_TO_CHUNK_ADDR(addr) ((char*)(addr) - sizeof(CSCI_USER_HEADER_T))

#define STATIC_CSCI_END Image$$CSCI_DATA$$ZI$$Limit
#define STATIC_CSCI_START Image$$CSCI_DATA$$ZI$$Base
#define STATIC_CSCI_LENGTH Image$$CSCI_DATA$$ZI$$Length
#define CSCI_LINKER_SYMBOL(symbol) extern void* symbol;

#endif //__CSCI_STRUCT__
