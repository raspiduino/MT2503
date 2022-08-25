/*--------------------------------------------------------------------*\
|   Copyright (c)2004 InterGrafx, Inc. All rights reserved.
\*--------------------------------------------------------------------*/
#ifndef IG_NAME_CACHE_I_H
#define IG_NAME_CACHE_I_H

#include "IGDataCache.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct
{
    IGDataCache m_pointers;

}   IGNameCache;

/*--------------------------------------------------------------------*\
|   IGNameCache private interface
\*--------------------------------------------------------------------*/
void    IGNameCache_i_initialize    ( IGMemoryPool*         pMemPool, 
                                      IGNameCache*          iCache, 
                                      iguint32              iCapacity, 
                                      IGErr*                pErr );

void    IGNameCache_i_destroyData   ( IGMemoryPool*         pMemPool, 
                                      IGNameCache*          iCache, 
                                      IGErr*                pErr );

void    IGNameCache_i_add           ( IGMemoryPool*         pMemPool, 
                                      IGNameCache*          iCache, 
                                      const char*           iName, 
                                      IGErr*                pErr );

void    IGNameCache_i_clear         ( IGMemoryPool*         pMemPool, 
                                      IGNameCache*          iCache, 
                                      IGErr*                pErr );

void    IGNameCache_i_getByIndex    ( IGMemoryPool*         pMemPool, 
                                      const IGNameCache*    iCache, 
                                      int                   iIndex, 
                                      char*                 pRetrieved, 
                                      IGErr*                pErr );

int     IGNameCache_i_getIndexOf    ( IGMemoryPool*         pMemPool, 
                                      const IGNameCache*    iCache, 
                                      const char*           iName, 
                                      IGErr*                pErr );

int     IGNameCache_i_getSize       ( IGMemoryPool*         pMemPool, 
                                      const IGNameCache*    iCache, 
                                      IGErr*                pErr );

void    IGNameCache_i_removeByIndex ( IGMemoryPool*         pMemPool, 
                                      IGNameCache*          iCache, 
                                      int                   iIndex, 
                                      IGErr*                pErr );

void    IGNameCache_i_removeByName  ( IGMemoryPool*         pMemPool, 
                                      IGNameCache*          iCache, 
                                      const char*           iName, 
                                      IGErr*                pErr );

void	IGNameCache_i_getUnrepeatName	(	IGMemoryPool*   pMemPool, 
											IGNameCache*    iCache, 
											char*			iName, 
											char*			oName, 
											IGErr*          pErr );

#ifdef __cplusplus
}
#endif

#endif//IG_NAME_CACHE_I_H
