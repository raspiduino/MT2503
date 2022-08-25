///////////////////////////////////////////////////////////////////////
/// \file       et_cache.h
/// \brief      cache management
/// \details    thread safe
/// <br><br>
/// Chang Log: <br>
///   0.1       Zheng Xu     Initialize <br>
///
/// \author     Zheng Xu<zxu@etrump.net>
/// \version    0.1
/// \date       December 2010
///
///////////////////////////////////////////////////////////////////////
#ifndef __ET_CACHE_H__
#define __ET_CACHE_H__

#include "et_types.h"

/// cache key
typedef ET_UINT32 ET_CacheKey;

/// make a key which required by cache system <br>
/// <table>
/// <tr> <td>31~24</td>  <td>23~16</td>  <td>15~8</td>    <td>7~0</td> </tr>
/// <tr> <td>module</td> <td>module</td> <td>subType</td> <td>keyCount</td> </tr>
/// </table>
#define ET_CACHE_MAKE_KEY(module, subType, keyCount) \
    ( ((ET_UINT32)(ET_UINT16)(module) << 16) \
    | ((ET_UINT32)(ET_UINT8)(subType) << 8) \
    | ((ET_UINT32)(ET_UINT8)(keyCount) << 0) )

/// handle to cache unit, used to retrieve memory
typedef struct ET_CacheUnit_Str* ET_CacheUnit;

////////////////////////////////////////////////////////////////////////
/// \brief function pointer, release private data of a cache unit
/// \details it will be triggered when the unit is cached out or destroyed
/// \param[in] ET_VOID* -- callback data
/// \return ET_VOID -- should always success
////////////////////////////////////////////////////////////////////////
typedef ET_VOID (*ET_CACHEUNIT_FREE)(ET_VOID* IN pData);

////////////////////////////////////////////////////////////////////////
/// \brief initialize cache
/// \details can only be called once
/// \param[in] size -- max cache memory size
/// \return ET_ERROR
////////////////////////////////////////////////////////////////////////
ET_API ET_ERROR ET_Cache_Initialize(ET_UINT32 IN size);

////////////////////////////////////////////////////////////////////////
/// \brief create a cache unit which can be managed by the cache system
/// \details the caller has the ownership of the returned unit unless ET_Cache_AddUnit() is called <br>
/// (key + keys) MUST be able to unique in the whole system
/// \param[out] pCacheUnit
/// \param[in] key
/// \param[in] pKeys
/// \param[in] cacheFree
/// \param[in] pData
/// \param[in] size
/// \return ET_ERROR
////////////////////////////////////////////////////////////////////////
ET_API ET_ERROR ET_CacheUnit_Create(ET_CacheUnit* OUT pCacheUnit,
                                    ET_CacheKey IN key,
                                    ET_UINT8* IN pKeys,
                                    ET_CACHEUNIT_FREE IN cacheFree,
                                    ET_VOID* IN pData,
                                    ET_UINT32 IN size);

////////////////////////////////////////////////////////////////////////
/// \brief destroy cache unit
/// \details the caller MUST has the ownership of the unit <br>
/// the caller should free the cache private data which can be get by ET_CacheUnit_GetData()
/// \param[in] cacheUnit
/// \return ET_ERROR
////////////////////////////////////////////////////////////////////////
ET_API ET_ERROR ET_CacheUnit_Destroy(ET_CacheUnit IN cacheUnit);

////////////////////////////////////////////////////////////////////////
/// \brief get private data of a cache unit
/// \details the cache unit MUST be owned or locked by the caller
/// \param[in] cacheUnit
/// \param[in] ppData
/// \return ET_ERROR
////////////////////////////////////////////////////////////////////////
ET_API ET_ERROR ET_CacheUnit_GetData(ET_CacheUnit IN cacheUnit,
                                     ET_VOID** OUT ppData);

////////////////////////////////////////////////////////////////////////
/// \brief add a cache unit to the cache system
/// \details the cache system will be the owner of the unit <br>
/// it will be unsafe to access the unit after ET_Cache_AddUnit() was called
/// \param[in] cacheUnit
/// \return ET_ERROR
////////////////////////////////////////////////////////////////////////
ET_API ET_ERROR ET_Cache_AddUnit(ET_CacheUnit IN cacheUnit);

////////////////////////////////////////////////////////////////////////
/// \brief get a cache unit from the cache system
/// \details the caller will get the ownership of the returned unit
/// \param[out] pCacheUnit
/// \param[in] key
/// \param[in] pKeys
/// \return ET_ERROR
////////////////////////////////////////////////////////////////////////
ET_API ET_ERROR ET_Cache_GetUnit(ET_CacheUnit* OUT pCacheUnit,
                                 ET_CacheKey IN key,
                                 ET_UINT8* IN pKeys);

////////////////////////////////////////////////////////////////////////
/// \brief lock a cache unit
/// \details cache system still owns the returned unit <br>
/// the returned unit will be safe to access until it was unlocked
/// \param[out] pCacheUnit
/// \param[in] key
/// \param[in] pKeys
/// \return ET_ERROR
////////////////////////////////////////////////////////////////////////
ET_API ET_ERROR ET_Cache_LockUnit(ET_CacheUnit* OUT pCacheUnit,
                                  ET_CacheKey IN key,
                                  ET_UINT8* IN pKeys);

////////////////////////////////////////////////////////////////////////
/// \brief unlock a cache unit
/// \details 
/// \param[in] cacheUnit
/// \return ET_ERROR
////////////////////////////////////////////////////////////////////////
ET_API ET_ERROR ET_Cache_UnlockUnit(ET_CacheUnit IN cacheUnit);

////////////////////////////////////////////////////////////////////////
/// \brief drop some cache unit to free *pSize memory at least
/// \details 
/// \param[in,out] pSize -- free one unit, if pSize == NULL. the freed memory size will be put in *pSize
/// \return ET_ERROR -- success if freed size >= *pSize
////////////////////////////////////////////////////////////////////////
ET_API ET_ERROR ET_Cache_Drop(ET_UINT32* INOUT pSize);

////////////////////////////////////////////////////////////////////////
/// \brief add a cache unit to cache system and lock it
/// \details it will be safe to access the unit after ET_Cache_AddLockUnit() <br>
/// but do not forget to ET_Cache_UnlockUnit()
/// \param[] cacheUnit
/// \return ET_API ET_ERROR
////////////////////////////////////////////////////////////////////////
ET_API ET_ERROR ET_Cache_AddLockUnit(ET_CacheUnit IN cacheUnit);

#endif
