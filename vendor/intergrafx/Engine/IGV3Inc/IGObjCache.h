/**
@file IGObjCache.h 
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
#ifndef IG_OBJ_CACHE_H
#define IG_OBJ_CACHE_H

#include "IGComDef.h"
#include "IGMemoryPool.h"
#include "IGDataCache.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct _IGObjCacheRec
{
    IGDataCache m_pointers;

} IGObjCache;


/*--------------------------------------------------------------------*\
|   IGObjCache public interface
\*--------------------------------------------------------------------*/
/**
* IGObjCache constructor.
* Allocates an IGObjCache with the specified initial capacity.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iCapacity
*   Initial size of IGObjCache
* @param pErr
*   Stores error code raised by this function
* @return
*   Handle to the new IGObjCache
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // Create an IGObjCache to hold 15 references.
*   IGObjCache* hCache = IGObjCache_new(pMemPool, 15, pErr);
* @endcode
* @see IGObjCache_destroy
*/
IGObjCache* IGObjCache_new          ( IGMemoryPool* pMemPool, 
                                      unsigned long iCapacity, 
                                      IGErr*        pErr );
/**
* Deallocates an IGObjCache.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iCache
*   Handle to the IGObjCache
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hCache references a previously allocated IGObjCache.
*   IGObjCache_destroy(pMemPool, hCache, pErr);
* @endcode
* @see IGObjCache_new
*/
void        IGObjCache_destroy      ( IGMemoryPool* pMemPool, 
                                      IGObjCache*   iCache, 
                                      IGErr*        pErr );

void        IGObjCache_destroyData	( IGMemoryPool*     pMemPool, 
                                      IGObjCache*       iCache, 
                                      IGErr*            pErr );
/**
* Adds an element to an IGObjCache.
* Adds an object to the end of the IGObjCache, resizing the cache if it is full.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iCache
*   Handle to the IGObjCache object
* @param iObject
*   Handle to the object to add
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hLightCache references a previously allocated IGObjCache.
*   // hLight references a previously allocated IGLight.
*   IGObjCache_add(pMemPool, hLightCache, (void*) hLight, pErr);
* @endcode
* @see IGObjCache_removeByIndex
* @see IGObjCache_removeByValue
*/
void        IGObjCache_add          ( IGMemoryPool* pMemPool, 
                                      IGObjCache*   iCache, 
                                      const void*         iObject, 
                                      IGErr*        pErr );
/**
* Removes all elements from an IGObjCache.
* Removes all the objects from the IGObjCache and sets the size of the IGObjCache
* to 0.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iCache
*   Handle to the IGObjCache object
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @warning
*   IGObjCache_clear does not free an IGObjCache object; use IGObjCache_destroy to
*   properly clean up an IGObjCache object
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hLightCache references a previously allocated IGObjCache.
*   IGObjCache_clear(pMemPool, hLightCache, pErr);
* @endcode
* @see IGObjCache_destroy
*/
void        IGObjCache_clear        ( IGMemoryPool* pMemPool, 
                                      IGObjCache*   iCache, 
                                      IGErr*        pErr );
/**
* Returns a pointer to the object at a given index.
* Returns a pointer to the object that is at a given index in the cache,
*   or NULL if that index is out of range
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iCache
*   Handle to IGObjCache object
* @param iIndex
*   Index of the element we want to retrieve
* @param pErr
*   Stores error code raised by this function
* @return
*   Handle to the object at the specified index, or NULL if the index is out
*   of range
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hLightCache references a previously allocated IGObjCache.
*   IGLight* hLight = (IGLight*) IGObjCache_getByIndex(pMemPool, hLightCache, 0, pErr);
* @endcode
* @see IGObjCache_getIndexOf
* @see IGObjCache_removeByIndex
*/
void*       IGObjCache_getByIndex   ( IGMemoryPool* pMemPool, 
                                      const IGObjCache*   iCache, 
                                      int           iIndex, 
                                      IGErr*        pErr );
/**
* Returns the index of a given element.
* Returns the index of the first object found that has the same ID as
* the object passed in, or -1 if the object is not in the cache.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iCache
*   Handle to IGObjCache object
* @param iObject
*   Handle to the object
* @param pErr
*   Stores error code raised by this function
* @return
*   Index at which specified element was found, or -1 if the element was not
*   found
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hLightCache references a previously allocated IGObjCache.
*   // hLight references a previously allocated IGLight.
*   int index = IGObjCache_getIndexOf(pMemPool, hLightCache, (void*) hLight, pErr);
* @endcode
* @see IGObjCache_getByIndex
* @see IGObjCache_removeByIndex
*/
int         IGObjCache_getIndexOf   ( IGMemoryPool* pMemPool, 
                                      const IGObjCache*   iCache, 
                                      const void*         iObject, 
                                      IGErr*        pErr );
/**
* Returns the size of an IGObjCache.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iCache
*   Handle to the IGObjCache object
* @param pErr
*   Stores error code raised by this function
* @return
*   Number of objects in the IGObjCache
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hLightCache references a previously allocated IGObjCache.
*   int size = IGObjCache_getSize(pMemPool, hLightCache, pErr);
* @endcode
*/
int         IGObjCache_getSize      ( IGMemoryPool* pMemPool, 
                                      const IGObjCache*   iCache, 
                                      IGErr*        pErr );

void        IGObjCache_initialize   ( IGMemoryPool* pMemPool, 
                                      IGObjCache*   iCache, 
                                      unsigned long iCapacity, 
                                      IGErr*        pErr );
/**
* Removes the object at the specified index.
* Removes the object at a given index from the IGObjCache and updates the
* IGObjCache, or does nothing if the index is out of range.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iCache
*   Pointer to the IGObjCache object
* @param iIndex
*   Index of the object to be removed
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hLightCache references a previously allocated IGObjCache.
*   IGObjCache_removeByIndex(pMemPool, hLightCache, 0, pErr);
* @endcode
* @see IGObjCache_add
* @see IGObjCache_removeByRef
*/
void        IGObjCache_removeByIndex( IGMemoryPool* pMemPool, 
                                      IGObjCache*   iCache, 
                                      int           iIndex, 
                                      IGErr*        pErr );
/**
* Removes an element from an IGObjCache.
* Removes the first object found that has an address identical to the value of
* the pointer passed in, or does nothing if that object is not found in the
* cache.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iCache
*   Handle to the IGObjCache object
* @param iObject
*   Handle to the object to remove
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hLightCache references a previously allocated IGObjCache.
*   // hLight references a previously allocated IGLight.
*   IGObjCache_removeByRef(pMemPool, hLightCache, (void*) hLight, pErr);
* @endcode
* @see IGObjCache_removeByIndex
*/
void        IGObjCache_removeByRef  ( IGMemoryPool* pMemPool, 
                                      IGObjCache*   iCache, 
                                      const void*         iObject, 
                                      IGErr*        pErr );

#ifdef __cplusplus
}
#endif

///////////////////////////////////////////






#endif//IG_OBJ_CACHE_H


