/*--------------------------------------------------------------------*\
|   Copyright (c)2004 InterGrafx, Inc. All rights reserved.
\*--------------------------------------------------------------------*/
#ifndef IG_BYTESTREAM_H
#define IG_BYTESTREAM_H

#include "IGInputStream.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct _IGOutputStreamRec
{
    igbool          m_notCompressed;
    unsigned long   m_numBytesWritten;

    union
    {
        IGByteArrayHandle   m_bh;
        IGFileHandle        m_fh;
        IGCompressedHandle  m_ch;
    }   m_handle;

    void            (*WriteByte)         ( IGMemoryPool*, IGOutputStream*, unsigned char, IGErr* );
    void            (*SkipBytes)         ( IGMemoryPool*, IGOutputStream*, unsigned long, IGErr* );
    void            (*Flush)             ( IGMemoryPool*, IGOutputStream*, IGErr* );
    void            (*DestroyData)       ( IGMemoryPool*, IGOutputStream*, IGErr* );
    unsigned long   (*GetOutputByteCount)( IGMemoryPool*, IGOutputStream*, IGErr* );
    void            (*WriteIGFHeader)    ( IGMemoryPool*, IGOutputStream*, iguint32, IGErr* );
    void            (*WriteIGAHeader)    ( IGMemoryPool*, IGOutputStream*, iguint16, iguint16, IGErr* );

}   IGOutputStream;

#ifdef __cplusplus
}
#endif

#endif