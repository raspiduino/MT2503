/** 
 *
 *	@file		IGV5DataCache.h	
 *
 *  @brief		Header file for various data cache definitions
 *
 *	@author		Charles Shih-I Yeh
 *
*/
#ifndef __IGV5DATACACHE_H
#define __IGV5DATACACHE_H

#include "IGV5Memory.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
    unsigned char*  m_aData;
    unsigned long   m_elmsize;
    unsigned long   m_capacity;
    int             m_count;
} IGV5DataCache;

IGV5Err IGV5DataCache_Create(IGV5DataCache *pCache, unsigned iCapacity, unsigned iElmsize);

void IGV5DataCache_Release(IGV5DataCache* pThis);

IGV5Err IGV5DataCache_Add(IGV5DataCache*  iCache, void* iData);

void IGV5DataCache_Clear(IGV5DataCache* iCache);

void* IGV5DataCache_Get(IGV5DataCache*  iCache, unsigned iIndex);

unsigned IGV5DataCache_GetSize(IGV5DataCache*  iCache);

void IGV5DataCache_Remove(IGV5DataCache*  iCache, int iIndex);

/////////////////////////////////////////////////////////////////////////////////////////////

typedef struct
{
    IGV5DataCache m_Names;
	IGV5DataCache m_Objects;

} IGV5NameCache;

IGV5Err IGV5NameCache_Create (IGV5NameCache*iCache, unsigned iCapacity, unsigned uElementSize);

void IGV5NameCache_Release(IGV5NameCache*iCache);

IGV5Err IGV5NameCache_Add(IGV5NameCache* iCache, char*iName, void *pItem);

void IGV5NameCache_Clear(IGV5NameCache*iCache);

IGV5Err IGV5NameCache_GetName(IGV5NameCache*iCache, unsigned iIndex, char* pRetrieved);

void *IGV5NameCache_GetData(IGV5NameCache*iCache, unsigned iIndex);

int IGV5NameCache_Find(IGV5NameCache*  iCache, char* iName, void **ppItem);

void *IGV5NameCache_GetDataByName(IGV5NameCache* iCache, char* iName);

unsigned IGV5NameCache_GetSize(IGV5NameCache*  iCache);

void IGV5NameCache_Remove(IGV5NameCache* iCache, int iIndex);

void IGV5NameCache_RemoveByName(IGV5NameCache* iCache, char* iName);

#ifdef __cplusplus
}
#endif

#endif