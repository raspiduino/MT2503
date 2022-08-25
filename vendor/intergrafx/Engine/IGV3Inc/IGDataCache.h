/*--------------------------------------------------------------------*\
|   Copyright (c)2004 InterGrafx, Inc. All rights reserved.
\*--------------------------------------------------------------------*/
#ifndef IG_DATA_CACHE_I_H
#define IG_DATA_CACHE_I_H

#include "IGComDef.h"
#include "IGMemoryPool.h"

#ifdef __cplusplus
extern "C"
{
#endif


typedef struct
{
    unsigned char*  m_aData;
    unsigned long   m_elmsize;
    unsigned long   m_capacity;
    int             m_count;
}
IGDataCache;


void    IGDataCache_initialize    ( IGMemoryPool*         pMemPool, 
                                      IGDataCache*          iCache, 
                                      iguint32              iCapacity, 
                                      iguint32              iElmsize, 
                                      IGErr*                pErr );

void    IGDataCache_destroyData   ( IGMemoryPool*         pMemPool, 
                                      IGDataCache*          iCache, 
                                      IGErr*                pErr );

void    IGDataCache_add           ( IGMemoryPool*         pMemPool, 
                                      IGDataCache*          iCache, 
                                      const void*           iData, 
                                      IGErr*                pErr );

void    IGDataCache_clear         ( IGMemoryPool*         pMemPool, 
                                      IGDataCache*          iCache, 
                                      IGErr*                pErr );

void*   IGDataCache_getByIndex    ( IGMemoryPool*         pMemPool, 
                                      const IGDataCache*    iCache, 
                                      int                   iIndex, 
                                      IGErr*                pErr );

int     IGDataCache_getSize       ( IGMemoryPool*         pMemPool, 
                                      const IGDataCache*    iCache, 
                                      IGErr*                pErr );

void*   IGDataCache_newSlot       ( IGMemoryPool*         pMemPool, 
                                      IGDataCache*          iCache, 
                                      IGErr*                pErr );

void    IGDataCache_removeByIndex ( IGMemoryPool*         pMemPool, 
                                      IGDataCache*          iCache, 
                                      int                   iIndex, 
                                      IGErr*                pErr );

#ifdef __cplusplus
}
#endif

#endif//IG_DATA_CACHE_I_H
