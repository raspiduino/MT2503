/**
@file IGInputStream.h  
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
#ifndef IG_INPUT_STREAM_H
#define IG_INPUT_STREAM_H

#include "IGComDef.h"
#include "IGMemoryPool.h"

#ifdef __cplusplus
extern "C"
{
#endif

#if defined(IGP_WIN32)
#include <stdio.h>
#endif

//only Win32 use standard file handle
#if !defined(IGP_WIN32)
typedef int     IGFileHandle;
#else
typedef FILE*   IGFileHandle;
#endif

typedef struct _IGOutputStreamRec IGOutputStream;
typedef struct _IGInputStreamRec IGInputStream;

typedef struct IGByteArrayHandle
{
    unsigned char*   m_base;
    unsigned char*   m_ptr;
    unsigned long    m_offset;

}   IGByteArrayHandle;

typedef struct IGCompressedHandle
{
    unsigned char*   m_bytes;
    unsigned char*   m_ptr;
    unsigned long    m_offset;
    unsigned long    m_available;
    unsigned long    m_inflated;
    unsigned long    m_deflated;
    unsigned char*   m_srcbuf;

    // persistent streams for physical media
    union
    {
        IGInputStream*   m_in;
        IGOutputStream*  m_out;
    }   m_stream;

}   IGCompressedHandle;

typedef struct _IGInputStreamRec
{
    igbool          m_notCompressed;
    unsigned long   m_numBytesRead;
#if defined(IG_NO_FUNCTION_PTR)
	int             m_streamType;
#endif

    union
    {
        IGByteArrayHandle   m_bh;
        IGFileHandle        m_fh;
        IGCompressedHandle  m_ch;
    }   m_handle;

#if !defined(IG_NO_FUNCTION_PTR)
    unsigned char   (*ReadByte)         ( IGMemoryPool*, IGInputStream*, IGErr* );
    void            (*SkipBytes)        ( IGMemoryPool*, IGInputStream*, unsigned long, IGErr* );
    void            (*DestroyData)      ( IGMemoryPool*, IGInputStream*, IGErr* );
    unsigned long   (*GetInputByteCount)( IGMemoryPool*, IGInputStream*, IGErr* );
    void            (*ReadIGFHeader)    ( IGMemoryPool*, IGInputStream*, char*, 
                                          iguint32*, iguint32*, IGErr* );
	void            (*ReadIGAHeader)    ( IGMemoryPool*, IGInputStream*, char*, 
		                                  iguint32*, iguint16*,iguint16*, IGErr* );
    void            (*Rewind)           ( IGMemoryPool*, IGInputStream*, IGErr* );
#endif

}   IGInputStream;

/*--------------------------------------------------------------------*\
|   IGInputStream public interface
\*--------------------------------------------------------------------*/
IGInputStream*  IGInputStream_newFromByteArray
                                        ( IGMemoryPool*         pMemPool, 
                                          const unsigned char*  iByteArray, 
                                          IGErr*                pErr );

IGInputStream*  IGInputStream_newFromFile
                                        ( IGMemoryPool*         pMemPool, 
                                          const char*           iFilename, 
                                          IGErr*                pErr );

IGInputStream*  IGInputStream_rawFromByteArray
                                        ( IGMemoryPool*         pMemPool, 
                                          const unsigned char*  iByteArray, 
                                          IGErr*                pErr );

void            IGInputStream_destroy   ( IGMemoryPool*     pMemPool, 
                                          IGInputStream*    iStream, 
                                          IGErr*            pErr );

IGInputStream*  IGInputStream_getRawStream
                                        ( IGMemoryPool*     pMemPool, 
                                          IGInputStream*    iStream, 
                                          IGErr*            pErr );                 

unsigned long   IGInputStream_readBytes ( IGMemoryPool*     pMemPool, 
                                          IGInputStream*    iStream, 
                                          unsigned char*    oBytes, 
                                          unsigned long     oNumBytes, 
                                          IGErr*            pErr );
                  
#ifdef __cplusplus
}
#endif

#endif//IG_INPUT_STREAM_H