/*--------------------------------------------------------------------*\
|   Copyright (c)2004 InterGrafx, Inc. All rights reserved.
\*--------------------------------------------------------------------*/
#ifndef IG_DEFLATER_I_H
#define IG_DEFLATER_I_H

#include "IGByteStream.h"

#ifdef __cplusplus
extern "C"
{
#endif

int     IGDeflater_i_deflateZLib    ( IGMemoryPool*, 
                                      iguint8*, 
                                      iguint32, 
                                      IGOutputStream*, 
                                      IGErr* );

#ifdef __cplusplus
}
#endif

#endif//IG_DEFLATER_I_H
