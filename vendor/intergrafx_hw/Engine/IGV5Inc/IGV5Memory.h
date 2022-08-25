/******************************************************************************

 @File         IGV5Memory.h 

 @Title        IGV5Memory

 @Version      

 @brief			Memory management functions

******************************************************************************/


#ifndef __IGV5MEMORY_H
#define __IGV5MEMORY_H

#include "IGV5Def.h"

#ifdef __cplusplus
extern "C" {
#endif

IGV5Err IGV5Memory_Init(void *, unsigned);

int IGV5Memory_GetIsInitialized(void);			//return 0-is not initialized; 1-is initialized

void IGV5Memory_Shutdown(void *);

void *IGV5Memory_Alloc(unsigned);

void IGV5Memory_Free(void *);

void *IGV5Memory_ReAlloc(void *, unsigned);

unsigned IGV5Memory_GetUsed(void *);

unsigned IGV5Memory_GetMaxSize(void *);

#ifdef __cplusplus
}
#endif


#endif

