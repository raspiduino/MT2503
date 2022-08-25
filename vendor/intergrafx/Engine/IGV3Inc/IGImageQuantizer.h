/*--------------------------------------------------------------------*\
|   Copyright (c)2004 InterGrafx, Inc. All rights reserved.
\*--------------------------------------------------------------------*/
#ifndef IG_IMAGE_QUANTIZER_I_H
#define IG_IMAGE_QUANTIZER_I_H

#include "IGComDef.h"
#include "IGMemoryPool.h"

#ifdef __cplusplus
extern "C"
{
#endif

iguint32*   IGQuantizeImage     ( IGMemoryPool*     pMemPool, 
                                  iguint32*         iImage, 
                                  iguint32          iWidth, 
                                  iguint32          iHeight, 
                                  iguint32          iMaxColors, 
                                  iguint32*         oNumRealColors, 
                                  IGErr*            pErr );

#ifdef __cplusplus
}
#endif

#endif//IG_IMAGE_QUANTIZER_I_H
