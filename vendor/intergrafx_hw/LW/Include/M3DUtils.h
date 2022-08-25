//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : M3DGameFramework
// File        : M3DUtils.h
// Description : C 語言公用結構與函式
// Author      : Ray
// Create      : 2010-09-13
// Update      : 2011-06-03
//==============================================================================

#include "M3DMemory.h"

#ifndef __M3D_UTILS__
#define __M3D_UTILS__

#define DEFAULT_SLOT		8
#define DEFAULT_NAME_SIZE	32
#define DEFAULT_QUEUE_SIZE	64

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

typedef struct _M3DTime
{
	unsigned char	m_Hour;
	unsigned char	m_Min;
	unsigned char	m_Sec;
} M3DTime;

extern void M3DTime_Set(M3DTime *_this, unsigned char _Hour, unsigned char _Min, unsigned char _Sec);

struct _M3DArray
{
	void **m_Array;
	int m_Slot;
	int m_Count;
};

typedef struct _M3DArray M3DArray;

extern M3DArray *M3DArray_New(void);
extern M3DArray *M3DArray_Init(M3DArray *_this, int _slot);
extern void M3DArray_Expand(M3DArray *_this);
extern void M3DArray_Add(M3DArray *_this, void *_item);
extern void *M3DArray_Get(M3DArray *_this, int _index);
extern void M3DArray_Remove(M3DArray *_this, int _index);
extern void M3DArray_RemoveAndFreeItem(M3DArray *_this, int _index);
extern void M3DArray_Clear(M3DArray *_this);
extern void M3DArray_ClearAndFreeItems(M3DArray *_this);
extern void M3DArray_Del(M3DArray *_this);

struct _M3DNamedObj
{
	char m_Name[DEFAULT_NAME_SIZE];
	void *m_Obj;
};

typedef struct _M3DNamedObj M3DNamedObj;

extern M3DArray *M3DNamedObjArray_New(void);
extern void M3DNamedObjArray_Add(M3DArray *_this, const char *_name, void *_obj);
extern int  M3DNamedObjArray_GetIndex(M3DArray *_this, const char *_name);
extern int  M3DNamedObjArray_GetNextIndexByName(M3DArray *_this, const char *_name, int _iPrev);
extern const char *M3DNamedObjArray_GetName(M3DArray *_this, int _index);
extern const char *M3DNamedObjArray_GetNameByName(M3DArray *_this, char *_name);
extern void *M3DNamedObjArray_Get(M3DArray *_this, int _index);
extern void M3DNamedObjArray_Set(M3DArray *_this, int _index, void *_obj);
extern void *M3DNamedObjArray_GetFirstByName(M3DArray *_this, const char *_name);
extern void *M3DNamedObjArray_GetNextByName(M3DArray *_this, const char *_name, void *_pPrev);
extern void M3DNamedObjArray_SetByName(M3DArray *_this, const char *_name, void *_obj);
extern void M3DNamedObjArray_Remove(M3DArray *_this, int _index);
extern void M3DNamedObjArray_Clear(M3DArray *_this);
extern void M3DNamedObjArray_Del(M3DArray *_this);


struct _M3DQueue
{
	void **m_Array;
	int m_Slot;
	int m_Head;
	int m_Tail;
};

typedef struct _M3DQueue M3DQueue;

extern M3DQueue *M3DQueue_New(int _size);
extern int  M3DQueue_Available(M3DQueue *_this);
extern int  M3DQueue_Used(M3DQueue *_this);
extern void M3DQueue_Expand(M3DQueue *_this);
extern void M3DQueue_Push(M3DQueue *_this, void *_item);
extern void *M3DQueue_Pop(M3DQueue *_this);
extern void *M3DQueue_Head(M3DQueue *_this);
extern void *M3DQueue_Tail(M3DQueue *_this);
extern void M3DQueue_Clear(M3DQueue *_this);
extern void M3DQueue_ClearAndFreeItems(M3DQueue *_this);
extern void M3DQueue_Del(M3DQueue *_this);

struct _M3DDateTime
{
	unsigned char m_Hour;
	unsigned char m_Minute;
	unsigned char m_Second;
};

typedef struct _M3DDateTime M3DDateTime;

#define MAX_ARRAY_POOL	1024

typedef struct _M3DArrayPool
{
	unsigned char	*m_Mem;
	int		m_MemSize;
	int		m_UnitSize;
	int		m_Slot;
	int		m_Used;
	char	m_Array[MAX_ARRAY_POOL];
} M3DArrayPool;

extern M3DArrayPool * M3DArrayPool_New(M3DArrayPool *_this, int _MemSize, int _UnitSize);
extern void M3DArrayPool_Init(M3DArrayPool *_this, void *_Mem, int _MemSize, int _UnitSize);
extern void *M3DArrayPool_Alloc(M3DArrayPool *_this);
extern int  M3DArrayPool_Available(M3DArrayPool *_this);
extern void M3DArrayPool_Free(M3DArrayPool *_this, void *_address);
extern void M3DArrayPool_Del(M3DArrayPool *_this);


typedef struct _M3DRect
{
	int m_X, m_Y, m_Width, m_Height, m_Right, m_Bottom;
} M3DRect;

extern void M3DRect_Set(M3DRect *_this, int _x, int _y, int _width, int _height);
extern int  M3DRect_Hit(M3DRect *_this, int _x, int _y);

typedef struct _M3DSplitString
{
	char m_strings[DEFAULT_NAME_SIZE * DEFAULT_SLOT * 3];
	int	m_length;
	int	m_current;
} M3DSplitString;

extern M3DSplitString *M3DSplitString_New(char *_strings);
extern void M3DSplitString_Del(M3DSplitString *_this);
extern void M3DSplitString_Init(M3DSplitString *_this, char *_strings);
extern int  M3DSplitString_GetCount(M3DSplitString *_this);
extern void M3DSplitString_Reset(M3DSplitString *_this);
extern int  M3DSplitString_GetFirst(M3DSplitString *_this, char *_string);
extern int  M3DSplitString_GetNext(M3DSplitString *_this, char *_string);
extern int M3DSplitString_GetAt(M3DSplitString *_this, char *_string, int _index);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__M3D_UTILS__
