#ifndef _mcfmemory_h_
#define _mcfmemory_h_

#include "McfCommon.h"


MINT McfMem_Init(MVOID);

MINT McfMem_Deinit(MVOID);

//主存申请
MVOID *McfMem_Malloc(MINT nMemStyle, MUINT nSize);

//主存释放
MVOID McfMem_Free(MINT nMemStyle, MVOID * pMem);


//后备内存申请
//MVOID *McfMem_ReserveMalloc(MUINT nSize);

//后备内存释放
//MVOID McfMem_ReserveFree(MVOID * pMem);

//MVOID *McfMem_PortingMalloc(MUINT nSize);
//MVOID McfMem_PortingFree(MVOID * pMem);


MUINT McfMem_PoolCreate(MVOID* pMem, MUINT nSize);

MINT McfMem_PoolDelete(MUINT nPoolId);

MVOID* McfMem_PoolMalloc(MUINT nPoolId, MUINT nSize);

MVOID McfMem_PoolFree(MUINT nPoolId, MVOID *pMem);

MUINT McfMem_PoolGetTotalLeftSize(MUINT nPoolId);

MUINT McfMem_PoolGetMaxAllocSize(MUINT nPoolId);

MVOID McfMem_PoolFreeDebug(MUINT nPoolId, MVOID *pMem, MCHAR *pFileName, MINT nLineNo);

MVOID* McfMem_PoolMallocDebug(MUINT nPoolId, MUINT nSize, MCHAR *pFileName, MINT nLineNo);


#endif
