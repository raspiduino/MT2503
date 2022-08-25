#ifndef __RES_CACHE_UTIL_H__
#define __RES_CACHE_UTIL_H__

#include "ResCompressConfig.h"

#ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__

#include "CustDataRes.h"
#include "CustDataProts.h"
#include "MMIDataType.h"
#include "kal_general_types.h"




typedef U32 RES_CACHE_HANDLE_T;


extern RES_CACHE_HANDLE_T CreateResObjectCache(U32 sizeInBytes);

extern S8 * RetriveResObjectFromCache(RES_CACHE_HANDLE_T cachePool, U16 objectId);

extern S8 * PrepareResObjectInCache(RES_CACHE_HANDLE_T cachePool, U16 objectId, U32 objectSize);

extern MMI_BOOL SaveResObjectToCache(RES_CACHE_HANDLE_T cachePool, U16 objectId, S8 * objectData, U32 objectSize);

extern MMI_BOOL SetObjectFlushable(RES_CACHE_HANDLE_T cachePtr, U16 objectId, MMI_BOOL isFlushable);

extern MMI_BOOL FlushCacheForce(RES_CACHE_HANDLE_T cachePtr);

#endif // __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
#endif //__RES_CACHE_UTIL_H__
