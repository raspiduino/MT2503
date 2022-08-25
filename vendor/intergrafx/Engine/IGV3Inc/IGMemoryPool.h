/**
@file IGMemoryPool.h 
@brief 

@par Last updated:


@par Copyright (c) 2005 InterGrafx, Inc. All rights reserved.
InterGrafx CONFIDENTIAL AND PROPRIETARY
@par
This source is the sole property of InterGrafx Inc. Reproduction or
Utilization of this source in whole or in part is forbidden without
The written consent of InterGrafx Inc.

@par History:


@par Description:
more description here.
*/
#ifndef IG_MEMORY_POOL_H
#define IG_MEMORY_POOL_H

#include "IGComDef.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define IG_SERIAL_CHUNK_SIZE 8192   // ZLib max chunk size

#define IG_SWAPUINT16(A)    ((((unsigned short)(A) & 0xff00) >> 8)  | \
                             (((unsigned short)(A) & 0x00ff) << 8))
                   
#define IG_SWAPUINT32(A)    ((((unsigned long)(A) & 0xff000000) >> 24)  | \
                             (((unsigned long)(A) & 0x00ff0000) >> 8)   | \
                             (((unsigned long)(A) & 0x0000ff00) << 8)   | \
                             (((unsigned long)(A) & 0x000000ff) << 24))


typedef struct {
	iguint32 m_uSize;
	unsigned char *m_pNextBlk;
} IGMemBlkHeader;
              
typedef struct IGMemoryPool
{
	void*			m_ActiveCamera;
    unsigned char*  m_aBase;			// memory pool base address
    unsigned long   m_uMaxSize;			// memory pool maximum size in bytes
    unsigned long   m_uUsed;			// maximum used address
	unsigned long   m_uTotalAllocSize;		// total memory available
	unsigned char*   m_pFreeListHead;	// first element of free block list	

	///unsigned m_uMaxFreeListBlockSize;   // max size block in free list
	unsigned m_uTotalFreeListSize;      // total size of freelist blocks
    
}   IGMemoryPool;

typedef struct IGClientData
{
    IGMemoryPool*   m_memPool;
    IGErr*          m_errcode;
    
}   IGClientData;

/*--------------------------------------------------------------------*\
|   IGMemoryPool public interface
\*--------------------------------------------------------------------*/
void*           IGMemoryPool_allocate       ( IGMemoryPool*     pMemPool, 
                                              unsigned long     iSize, 
                                              IGErr*            pErr );
                                              
unsigned long   IGMemoryPool_available      ( IGMemoryPool*     pMemPool,
                                              IGErr*            pErr );                  
/**
Releases resources consumed by an IGMemoryPool.
@param pMemPool
  Pointer to IGMemoryPool
@param pErr
  Stores error code raised by this function
@return
  void
@note
  It is the caller's responsibility to free the memory block after
  finalization.
*/
void            IGMemoryPool_finalize       ( IGMemoryPool*     pMemPool, 
                                              IGErr*            pErr );

void            IGMemoryPool_free           ( IGMemoryPool*     pMemPool, 
                                              void*             iBlock, 
                                              IGErr*            pErr );
/**
Initializes an IGMemoryPool with a caller-supplied memory block.
@param pMemPool
  Pointer to IGMemoryPool
@param iBase
  Pointer of the Memory base
@param iSize
  Pool size
@param pErr
  Stores error code raised by this function
@return
  void
*/
void            IGMemoryPool_initialize     ( IGMemoryPool*     pMemPool, 
                                              unsigned char*    iBase, 
                                              unsigned long     iSize, 
                                              IGErr*            pErr );

igbool          IGMemoryPool_isLittleEndian ( IGMemoryPool*     pMemPool, 
                                              IGErr*            pErr );

void*           IGMemoryPool_reallocate     ( IGMemoryPool*     pMemPool, 
                                              void*             iBlock, 
                                              unsigned long     iSize, 
                                              IGErr*            pErr );

unsigned long   IGMemoryPool_report         ( IGMemoryPool*     pMemPool); 

void            IGMemoryPool_reset          ( IGMemoryPool*     pMemPool, 
                                              IGErr*            pErr );

////////////////////////////////////////////////////////

/*--------------------------------------------------------------------*\
|   (In)convenience macros
\*--------------------------------------------------------------------*/

		
	
#define IG_XALLOC(T, ERR) (T*)IGMemoryPool_allocate(pMemPool, sizeof(T), ERR);

#define IG_XNALLOC(T, N, ERR) (T*)IGMemoryPool_allocate(pMemPool, N * sizeof(T), ERR);

#define IG_XFREE(T, PTR, ERR) IGMemoryPool_free(pMemPool, PTR,  ERR);

#define IG_XNFREE(T, N, PTR, ERR) IGMemoryPool_free(pMemPool, PTR, ERR);

#define IG_XNREALLOC(T, SIZE, PTR, ERR) (T*)IGMemoryPool_reallocate(pMemPool, PTR, SIZE * sizeof(T), ERR);

#define IG_XNMEMCPY(T, FPTR, TPTR, N, ERR) IGMemoryPool_i_memcpy(TPTR, FPTR, N*sizeof(T), ERR)

#define IG_XNMEMSET(T, PTR, N, VAL, ERR) IGMemoryPool_i_memset(PTR, N*sizeof(T), VAL, ERR)

/*--------------------------------------------------------------------*\
|   IGMemoryPool private interface
\*--------------------------------------------------------------------*/
void*   IGMemoryPool_i_memcpy       ( void*         iDst, 
                                      const void*   iSrc, 
                                      long          iNumBytes, 
                                      IGErr*        pErr );

void*   IGMemoryPool_i_memset       ( void*         iPtr, 
                                      long          iCount, 
                                      int           iVal, 
                                      IGErr*        pErr );

int		IGMemoryPool_i_strlen		( const char*     iStr );

int     IGMemoryPool_i_strcmp       ( const char*   iStr1, 
                                      const char*   iStr2 );

char*   IGMemoryPool_i_strcpy       ( char*         iDst, 
                                      const char*   iSrc );

char*   IGMemoryPool_i_strncpy      ( char*         iDst, 
                                      const char*   iSrc, 
                                      int           iNum );

char*   IGMemoryPool_i_strcat       ( char*         iDst, 
                                      const char*   iSrc );

#ifdef __cplusplus
}
#endif

#endif//IG_MEMORY_POOL_H

