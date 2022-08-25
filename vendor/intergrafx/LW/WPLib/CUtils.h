//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : IGV4GameFramework
// File        : CUtils.h
// Description : C 語言公用結構與函式
// Author      : Ray
// Create      : 2010-09-13
// Update      : 2011-02-15
//==============================================================================

#include "CMemory.h"

#ifndef __C_UTILS__
#define __C_UTILS__

#define DEFAULT_SLOT		8
#define DEFAULT_NAME_SIZE	16
#define DEFAULT_QUEUE_SIZE	64

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

typedef struct _CTime
{
	unsigned char	m_Hour;
	unsigned char	m_Min;
	unsigned char	m_Sec;
} CTime;

extern void CTime_Set(CTime *_this, unsigned char _Hour, unsigned char _Min, unsigned char _Sec);

struct _CArray
{
	void **m_Array;
	int m_Slot;
	int m_Count;
};

typedef struct _CArray CArray;
extern CArray *CArray_New(void *_item);
extern CArray *CArray_Init(CArray *_this, int _slot);
extern void CArray_Expand(CArray *_this);
extern void CArray_Add(CArray *_this, void *_item);
extern void *CArray_Get(CArray *_this, int _index);
extern void CArray_Remove(CArray *_this, int _index);
extern void CArray_Clear(CArray *_this);
extern void CArray_Del(CArray *_this);

extern CArray *CStringArray_New(const char *_name);
extern void CStringArray_Add(CArray *_this, const char *_name);
extern int  CStringArray_GetIndex(CArray *_this, const char *_name);
extern const char *CStringArray_Get(CArray *_this, int _index);
extern void CStringArray_Remove(CArray *_this, int _index);
extern void CStringArray_Clear(CArray *_this);
extern void CStringArray_Del(CArray *_this);

struct _CNamedObj
{
	char m_Name[DEFAULT_NAME_SIZE];
	void *m_Obj;
};

typedef struct _CNamedObj CNamedObj;

extern CArray *CNamedObjArray_New(const char *_name, void *_obj);
extern void CNamedObjArray_Add(CArray *_this, const char *_name, void *_obj);
extern int  CNamedObjArray_GetIndex(CArray *_this, const char *_name);
extern int  CNamedObjArray_GetNextIndexByName(CArray *_this, const char *_name, int _iPrev);
extern const char *CNamedObjArray_GetName(CArray *_this, int _index);
extern void *CNamedObjArray_Get(CArray *_this, int _index);
extern void CNamedObjArray_Set(CArray *_this, int _index, void *_obj);
extern void *CNamedObjArray_GetFirstByName(CArray *_this, const char *_name);
extern void *CNamedObjArray_GetNextByName(CArray *_this, const char *_name, void *_pPrev);
extern void CNamedObjArray_SetByName(CArray *_this, const char *_name, void *_obj);
extern void CNamedObjArray_Remove(CArray *_this, int _index);
extern void CNamedObjArray_Clear(CArray *_this);
extern void CNamedObjArray_Del(CArray *_this);

struct _CNamedId
{
	char m_Name[DEFAULT_NAME_SIZE];
	int  m_Id;
};

typedef struct _CNamedId CNamedId;

struct _CQueue
{
	void **m_Array;
	int m_Slot;
	int m_Head;
	int m_Tail;
};

typedef struct _CQueue CQueue;

extern CQueue *CQueue_New(int _size);
extern int  CQueue_Available(CQueue *_this);
extern int  CQueue_Used(CQueue *_this);
extern void CQueue_Expand(CQueue *_this);
extern void CQueue_Push(CQueue *_this, void *_item);
extern void *CQueue_Pop(CQueue *_this);
extern void *CQueue_Head(CQueue *_this);
extern void *CQueue_Tail(CQueue *_this);
extern void CQueue_Clear(CQueue *_this);
extern void CQueue_Del(CQueue *_this);

struct _CDateTime
{
	unsigned char m_Hour;
	unsigned char m_Minute;
	unsigned char m_Second;
};

typedef struct _CDateTime CDateTime;

#define MAX_ARRAY_POOL	1024

typedef struct _CArrayPool
{
	unsigned char	*m_Mem;
	int		m_MemSize;
	int		m_UnitSize;
	int		m_Slot;
	int		m_Used;
	char	m_Array[MAX_ARRAY_POOL];
} CArrayPool;

extern void CArrayPool_Init(CArrayPool *_this, void *_Mem, int _MemSize, int _UnitSize);
extern void *CArrayPool_Alloc(CArrayPool *_this);
extern int  CArrayPool_Available(CArrayPool *_this);
extern void CArrayPool_Free(CArrayPool *_this, void *_address);


typedef struct _CRect
{
	int m_X, m_Y, m_Width, m_Height, m_Right, m_Bottom;
} CRect;

extern void CRect_Set(CRect *_this, int _x, int _y, int _width, int _height);
extern int  CRect_Hit(CRect *_this, int _x, int _y);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__C_UTILS__
