/*--------------------------------------------------------------------*\
|   Copyright (c)2004 InterGrafx, Inc. All rights reserved.
\*--------------------------------------------------------------------*/
#ifndef IG_INFLATER_H
#define IG_INFLATER_H

#include "IGComDef.h"
#include "IGInputStream.h"
#include "IGMemoryPool.h"

#ifdef __cplusplus
extern "C"
{
#endif

int     IGInflater_inflateZLib      ( IGMemoryPool*     pMemPool, 
                                      IGInputStream*    iInStream, 
                                      unsigned char*    iDestBuf, 
                                      unsigned char*    iSrcBuf, 
                                      unsigned long     iSrcLen, 
                                      IGErr*            pErr );

#ifdef __cplusplus
}
#endif

#endif//IG_INFLATER_H
