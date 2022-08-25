//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : M3DGameFramework
// File        : M3DUtils.c
// Description : C 語言公用結構與函式
// Author      : Ray
// Create      : 2010-09-13
// Update      : 2011-06-03
//==============================================================================

#include "M3DUtils.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

void M3DTime_Set(M3DTime *_this, unsigned char _Hour, unsigned char _Min, unsigned char _Sec)
{
	_this->m_Hour = _Hour;
	_this->m_Min = _Min;
	_this->m_Sec = _Sec;
}

//================= M3DArray Begin ================================
M3DArray *M3DArray_New(void)
{
	M3DArray *self = (M3DArray *) M3DMemory_New(sizeof(M3DArray));

	if (self == NULL)
		return NULL;

	self->m_Slot = DEFAULT_SLOT;
	self->m_Array = (void **) M3DMemory_New(sizeof(void *) * self->m_Slot);
	if (self->m_Array == NULL)
		self->m_Slot = 0;

	return self;
}

M3DArray *M3DArray_Init(M3DArray *_this, int _slot)
{
	if (_this == NULL)
		return NULL;

	_this->m_Slot = _slot;

	_this->m_Array = (void **) M3DMemory_New(sizeof(void *) * _this->m_Slot);
	if (_this->m_Array == NULL)
		_this->m_Slot = 0;

	return _this;
}

void M3DArray_Expand(M3DArray *_this)
{
	int iNewSize = 0;
	void **_array = NULL;

	if (_this == NULL)
		return;

	iNewSize = _this->m_Slot + DEFAULT_SLOT;
	_array = (void **) M3DMemory_New(sizeof(void *) * iNewSize);
	if (_array == NULL)
		return;

	M3DMemory_Copy(_array, _this->m_Array, (sizeof(void *) * _this->m_Slot));

	_this->m_Slot = iNewSize;
	M3DMemory_Del(_this->m_Array);
	_this->m_Array = _array;
}

void M3DArray_Add(M3DArray *_this, void *_item)
{
	if (_this == NULL || _this->m_Array == NULL)
		return;

	if (_this->m_Count == _this->m_Slot)
		M3DArray_Expand(_this);

	//RAY::2011-06-03 再檢查一次, 以免 Expand 錯誤
	if (_this->m_Count == _this->m_Slot)
		return;

	_this->m_Array[_this->m_Count] = _item;
	_this->m_Count = _this->m_Count + 1;
}

void *M3DArray_Get(M3DArray *_this, int _index)
{
	if (_this == NULL || _this->m_Array == NULL)
		return NULL;

	if (_index >= 0 && _index < _this->m_Count)
		return _this->m_Array[_index];
	else
		return NULL;
}

//RAY::2010-10-18
void M3DArray_Remove(M3DArray *_this, int _index)
{
	int cn = 0;
	if (_this == NULL || _this->m_Array == NULL || _this->m_Count == 0 || _index < 0 || _index >= _this->m_Count)
		return;

	for (cn = _index; cn < _this->m_Count - 1; cn = cn + 1)
	{
		_this->m_Array[cn] = _this->m_Array[cn+1];
	}
	_this->m_Array[_this->m_Count - 1] = NULL;
	_this->m_Count = _this->m_Count - 1;
}

void M3DArray_RemoveAndFreeItem(M3DArray *_this, int _index)
{
	int cn = 0;
	if (_this == NULL || _this->m_Array == NULL || _this->m_Count == 0 || _index < 0 || _index >= _this->m_Count)
		return;

	//RAY::2011-06-03 釋放該項目的記憶體
	M3DMemory_Del(_this->m_Array[_index]);
	for (cn = _index; cn < _this->m_Count - 1; cn = cn + 1)
	{
		_this->m_Array[cn] = _this->m_Array[cn+1];
	}
	_this->m_Array[_this->m_Count - 1] = NULL;
	_this->m_Count = _this->m_Count - 1;
}

void M3DArray_Clear(M3DArray *_this)
{
	int cn;

	if (_this == NULL)
		return;

	if (_this->m_Array != NULL)
	{
		for (cn = 0; cn < _this->m_Count; cn = cn + 1)
		{
			_this->m_Array[cn] = NULL;
		}
	}
	_this->m_Count = 0;
}

void M3DArray_ClearAndFreeItems(M3DArray *_this)
{
	int cn;

	if (_this == NULL)
		return;

	if (_this->m_Array != NULL)
	{
		for (cn = 0; cn < _this->m_Count; cn = cn + 1)
		{
			//RAY::2011-06-03 釋放該項目的記憶體
			M3DMemory_Del(_this->m_Array[cn]);
			_this->m_Array[cn] = NULL;
		}
	}
	_this->m_Count = 0;
}

//RAY::2011-06-03 如果要釋放項目的記憶體, 請先呼叫 M3DArray_ClearAndFreeItems
void M3DArray_Del(M3DArray *_this)
{
	int cn;

	if (_this == NULL)
		return;

	if (_this->m_Array != NULL)
	{
		for (cn = 0; cn < _this->m_Count; cn = cn + 1)
		{
			_this->m_Array[cn] = NULL;
		}
		M3DMemory_Del(_this->m_Array);
	}
	M3DMemory_Del(_this);
}

//================= M3DArray End ==================================

//================= M3DNamedObjArray Begin=========================

M3DArray *M3DNamedObjArray_New(void)
{
	M3DArray *self = NULL;

	self = M3DArray_New();

	return self;
}

void M3DNamedObjArray_Add(M3DArray *_this, const char *_name, void *_obj)
{
	M3DNamedObj *item = NULL;

	if (_this == NULL)
		return;

	if (_name != NULL && _obj != NULL)
	{
		item = (M3DNamedObj *) M3DMemory_New(sizeof(M3DNamedObj));
		strncpy(item->m_Name, _name, DEFAULT_NAME_SIZE);

		item->m_Obj = _obj;
	}

	M3DArray_Add(_this, item);
}

int M3DNamedObjArray_GetIndex(M3DArray *_this, const char *_name)
{
	int iIndex = -1;
	int cn;
	M3DNamedObj *item = NULL;

	if (_this == NULL)
		return iIndex;

	if (_this->m_Array != NULL)
	{
		for (cn = 0; cn < _this->m_Count; cn = cn + 1)
		{
			item = (M3DNamedObj *) _this->m_Array[cn];
			if (strcmp(item->m_Name, _name) == 0)
			{
				iIndex = cn;
				break;
			}
		}
	}

	return iIndex;
}

int M3DNamedObjArray_GetNextIndexByName(M3DArray *_this, const char *_name, int _iPrev)
{
	int cn = 0, index = -1;
	M3DNamedObj *item = NULL;

	if (_this == NULL || _this->m_Array == NULL || _iPrev < 0)
		return -1;

	for (cn = _iPrev; cn < _this->m_Count; cn = cn + 1)
	{
		item = (M3DNamedObj *) _this->m_Array[cn];
		if (strcmp(item->m_Name, _name) == 0)
		{
			index = cn;
			break;
		}
	}

	return index;
}

const char *M3DNamedObjArray_GetName(M3DArray *_this, int _index)
{
	M3DNamedObj *item = NULL;

	if (_this == NULL)
		return NULL;

	if (_index >= 0 && _index < _this->m_Count)
	{
		item = _this->m_Array[_index];
		return item->m_Name;
	}
	else
		return NULL;
}

const char *M3DNamedObjArray_GetNameByName(M3DArray *_this, char *_name)
{
	int index = -1;

	if (_this == NULL)
		return NULL;

	index = M3DNamedObjArray_GetIndex(_this, _name);

	return M3DNamedObjArray_GetName(_this, index);
}

void *M3DNamedObjArray_Get(M3DArray *_this, int _index)
{
	M3DNamedObj *item = NULL;

	if (_this == NULL || _this->m_Array == NULL)
		return NULL;

	if (_index >= 0 && _index < _this->m_Count)
	{
		item = _this->m_Array[_index];
		return item->m_Obj;
	}
	else
		return NULL;
}


/*
void CNamedObjArray_Set(CArray *_this, int _index, void *_obj)
{
	CNamedObj *item = NULL;
	void *obj = NULL;

	if (_this == NULL || _this->m_Array == NULL)
		return NULL;

	if (_index >= 0 && _index < _this->m_Count)
	{
		item = _this->m_Array[_index];
		item->m_Obj = _obj;
	}
}
*/

void *M3DNamedObjArray_GetFirstByName(M3DArray *_this, const char *_name)
{
	int index = -1;
	void *obj = NULL;

	if (_this == NULL || _this->m_Array == NULL)
		return NULL;

	index = M3DNamedObjArray_GetIndex(_this, _name);
	if (index != -1)
	{
		obj = M3DNamedObjArray_Get(_this, index);
	}

	return obj;
}

void *M3DNamedObjArray_GetNextByName(M3DArray *_this, const char *_name, void *_pPrev)
{
	int cn = 0;
	void *obj = NULL;
	int iFindPrev = 0;
	M3DNamedObj *item = NULL;

	if (_this == NULL || _this->m_Array == NULL)
		return NULL;

	for (cn = 0; cn < _this->m_Count; cn = cn + 1)
	{
		item = (M3DNamedObj *) _this->m_Array[cn];
		if (strcmp(item->m_Name, _name) == 0)
		{
			if (iFindPrev == 0)
			{
				if (item->m_Obj == _pPrev)
					iFindPrev = 1;
			}
			else
			{
				obj = item->m_Obj;
				break;
			}
		}
	}

	return obj;
}

/*
void CNamedObjArray_SetByName(CArray *_this, const char *_name, void *_obj)
{
	int index = -1;
	void *obj = NULL;
	CNamedObj *item = NULL;

	if (_this == NULL || _this->m_Array == NULL)
		return NULL;

	index = CNamedObjArray_GetIndex(_this, _name);
	if (index != -1)
	{
		item = _this->m_Array[index];
		item->m_Obj = _obj;
	}
	else
	{
		CNamedObjArray_Add(_this, _name, _obj);
	}

	return obj;
}
*/

//RAY::2010-10-19
void M3DNamedObjArray_Remove(M3DArray *_this, int _index)
{
	int cn = 0;
	if (_this == NULL || _this->m_Array == NULL || _this->m_Count == 0 || _index < 0 || _index >= _this->m_Count)
		return;

	M3DMemory_Del(_this->m_Array[_index]);
	_this->m_Array[_index] = NULL;
	for (cn = _index; cn < _this->m_Count - 1; cn = cn + 1)
	{
		_this->m_Array[cn] = _this->m_Array[cn+1];
	}
	_this->m_Array[_this->m_Count - 1] = NULL;
	_this->m_Count = _this->m_Count - 1;
}

void M3DNamedObjArray_Clear(M3DArray *_this)
{
	int cn;

	if (_this == NULL || _this->m_Array == NULL)
		return;

	for (cn = 0; cn < _this->m_Count; cn = cn + 1)
	{
		M3DMemory_Del(_this->m_Array[cn]);
	}
	_this->m_Count = 0;
}

void M3DNamedObjArray_Del(M3DArray *_this)
{
	if (_this == NULL)
		return;

	if (_this->m_Array != NULL)
	{
		M3DNamedObjArray_Clear(_this);
	}
	M3DArray_Del(_this);
}

//================= M3DNamedObjArray End ===========================


//================= M3DQueue Begin ================================

M3DQueue *M3DQueue_New(int _size)
{
	M3DQueue *self = (M3DQueue *) M3DMemory_New(sizeof(M3DQueue));

	if (self == NULL)
		return self;

	self->m_Slot = _size;
	self->m_Array = (void **) M3DMemory_New(sizeof(void *) * self->m_Slot);
	if (self->m_Array == NULL)
		self->m_Slot = 0;

	self->m_Head = -1;
	self->m_Tail = -1;

	return self;
}

int  M3DQueue_Available(M3DQueue *_this)
{
	int iUsed = 0;
	int iAvailable = 0;

	if (_this == NULL)
		return iAvailable;

	if (_this->m_Head == -1 && _this->m_Tail == -1)
		iUsed = 0;
	else if (_this->m_Head == _this->m_Tail)
		iUsed = 1;
	else if (_this->m_Head > _this->m_Tail)
		iUsed = _this->m_Head - _this->m_Tail + 1;
	else
		iUsed = _this->m_Head - _this->m_Tail + 1 + _this->m_Slot;

	iAvailable = _this->m_Slot - iUsed;

	return iAvailable;
}

int  M3DQueue_Used(M3DQueue *_this)
{
	int iAvailable = 0;

	if (_this == NULL)
		return iAvailable;

	iAvailable = M3DQueue_Available(_this);

	return _this->m_Slot - iAvailable;
}

//don't use this, there are some problems
void M3DQueue_Expand(M3DQueue *_this)
{
	void **_array = NULL;

	if (_this == NULL)
		return;

	_array = (void **) M3DMemory_New(sizeof(void *) * (_this->m_Slot + DEFAULT_SLOT));
	M3DMemory_Copy(_array, _this->m_Array, _this->m_Slot);

	_this->m_Slot = _this->m_Slot + DEFAULT_SLOT;
	M3DMemory_Del(_this->m_Array);
	_this->m_Array = _array;
}

void M3DQueue_Push(M3DQueue *_this, void *_item)
{
	if (_this == NULL || _this->m_Array == NULL)
		return;

	if (M3DQueue_Available(_this) == 0)
		M3DQueue_Expand(_this);

	if (_this->m_Head == -1 && _this->m_Tail == -1)
	{
		_this->m_Head = 0;
		_this->m_Tail = 0;
	}
	else
	{
		_this->m_Head = _this->m_Head + 1;
		if (_this->m_Head == _this->m_Slot - 1)
			_this->m_Head = 0;
	}
	 _this->m_Array[_this->m_Head] = _item;
}

void *M3DQueue_Pop(M3DQueue *_this)
{
	void *item = NULL;

	if (_this == NULL || _this->m_Array == NULL)
		return NULL;

	if (_this->m_Head == -1 && _this->m_Tail == -1)
	{
		item = NULL;
	}
	else
	{
		item = _this->m_Array[_this->m_Tail];
		_this->m_Array[_this->m_Tail] = NULL;

		if (_this->m_Head == _this->m_Tail)
		{
			_this->m_Head = -1;
			_this->m_Tail = -1;
		}
		else
		{
			_this->m_Tail = _this->m_Tail + 1;
			if (_this->m_Tail == _this->m_Slot - 1)
				_this->m_Tail = 0;
		}
	}
	return item;
}

void *M3DQueue_Head(M3DQueue *_this)
{
	void *item = NULL;

	if (_this == NULL || _this->m_Array == NULL)
		return NULL;

	if (_this->m_Head != -1)
		item = _this->m_Array[_this->m_Head];

	return item;
}

void *M3DQueue_Tail(M3DQueue *_this)
{
	void *item = NULL;

	if (_this == NULL || _this->m_Array == NULL)
		return NULL;

	if (_this->m_Tail != -1)
		item = _this->m_Array[_this->m_Tail];

	return item;
}

void M3DQueue_Clear(M3DQueue *_this)
{
	int cn;

	if (_this == NULL || _this->m_Array == NULL)
		return;

	for (cn = 0; cn < _this->m_Slot; cn = cn + 1)
	{
		_this->m_Array[cn] = NULL;
	}
	_this->m_Head = -1;
	_this->m_Tail = -1;
}

void M3DQueue_ClearAndFreeItems(M3DQueue *_this)
{
	int cn;

	if (_this == NULL || _this->m_Array == NULL)
		return;

	for (cn = 0; cn < _this->m_Slot; cn = cn + 1)
	{
		//RAY::2011-06-03 釋放該項目的記憶體
		M3DMemory_Del(_this->m_Array[cn]);
		_this->m_Array[cn] = NULL;
	}
	_this->m_Head = -1;
	_this->m_Tail = -1;
}

//RAY::2011-06-03 如果要釋放項目的記憶體, 請先呼叫 M3DQueue_ClearAndFreeItems
void M3DQueue_Del(M3DQueue *_this)
{
	int cn;

	if (_this == NULL)
		return;

	if (_this->m_Array != NULL)
	{
		for (cn = 0; cn < _this->m_Slot; cn = cn + 1)
		{
			_this->m_Array[cn] = NULL;
		}
		M3DMemory_Del(_this->m_Array);
	}
	M3DMemory_Del(_this);
}

//================= M3DQueue End ==================================


//================= M3DArrayPool Begin ================================

M3DArrayPool * M3DArrayPool_New(M3DArrayPool *_this, int _MemSize, int _UnitSize)
{
	int cn = 0;
	M3DArrayPool *self = NULL;

	self = (M3DArrayPool *) M3DMemory_New(sizeof(M3DArrayPool));
	if (self == NULL)
		return self;

	self->m_Mem = (unsigned char *) M3DMemory_New(_MemSize);
	if (self->m_Mem != NULL)
		self->m_MemSize = _MemSize;

	self->m_UnitSize = _UnitSize;
	self->m_Used = 0;
	self->m_Slot = _MemSize / _UnitSize;
	if (self->m_Slot > MAX_ARRAY_POOL)
		self->m_Slot = MAX_ARRAY_POOL;

	for (cn = 0; cn < self->m_Slot; cn = cn + 1)
	{
		self->m_Array[cn] = 0;
	}

	return self;
}

void M3DArrayPool_Init(M3DArrayPool *_this, void *_Mem, int _MemSize, int _UnitSize)
{
	int cn = 0;

	if (_this == NULL)
		return;

	_this->m_Mem = _Mem;
	_this->m_MemSize = _MemSize;
	_this->m_UnitSize = _UnitSize;
	_this->m_Used = 0;
	_this->m_Slot = _MemSize / _UnitSize;
	if (_this->m_Slot > MAX_ARRAY_POOL)
		_this->m_Slot = MAX_ARRAY_POOL;

	for (cn = 0; cn < _this->m_Slot; cn = cn + 1)
	{
		_this->m_Array[cn] = 0;
	}
}

void *M3DArrayPool_Alloc(M3DArrayPool *_this)
{
	int cn = 0;
	int index = -1;
	unsigned char *address = NULL;

	if (_this == NULL)
		return NULL;

	for (cn = 0; cn < _this->m_Slot; cn = cn + 1)
	{
		if (_this->m_Array[cn] == 0)
		{
			_this->m_Array[cn] = 1;
			_this->m_Used = _this->m_Used + 1;
			index = cn;
			address = _this->m_Mem + _this->m_UnitSize * index;
			break;
		}
	}

	return (void *)address;
}

int M3DArrayPool_Available(M3DArrayPool *_this)
{
	if (_this == NULL)
		return 0;

	return _this->m_Slot - _this->m_Used;
}

void M3DArrayPool_Free(M3DArrayPool *_this, void *_address)
{
	int cn = 0;
	unsigned char *address = _this->m_Mem;

	for (cn = 0; cn < _this->m_Slot; cn = cn + 1)
	{
		address = _this->m_Mem + _this->m_UnitSize * cn;
		if (address == _address)
		{
			_this->m_Array[cn] = 0;
			_this->m_Used = _this->m_Used - 1;
			break;
		}
	}
}

//RAY::2011-06-03 用 M3DArrayPool_New 才可以用這個
void M3DArrayPool_Del(M3DArrayPool *_this)
{
	if (_this == NULL)
		return;

	M3DMemory_Del(_this->m_Mem);
	M3DMemory_Del(_this);
}

//================= M3DArrayPool End   ================================

void M3DRect_Set(M3DRect *_this, int _x, int _y, int _width, int _height)
{
	if (_this == NULL)
		return;

	_this->m_X = _x;
	_this->m_Y = _y;
	_this->m_Width = _width;
	_this->m_Height = _height;
	_this->m_Right = _x + _width - 1;
	_this->m_Bottom = _y + _height - 1;
}

int  M3DRect_Hit(M3DRect *_this, int _x, int _y)
{
	int hit = 0;

	if (_this == NULL)
		return 0;

	if (_x >= _this->m_X && _x <= _this->m_Right && _y >= _this->m_Y && _y <= _this->m_Bottom)
		hit = 1;

	return hit;
}

M3DSplitString *M3DSplitString_New(char *_strings)
{
	M3DSplitString *self = M3DMemory_New(sizeof(M3DSplitString));

	if (self != NULL)
	{
		self->m_length = (int) strlen(_strings);
		strcpy(self->m_strings, _strings);
		self->m_current = 0;
	}
	return self;
}

void M3DSplitString_Del(M3DSplitString *_this)
{
	if (_this == NULL)
		return;

	M3DMemory_Del(_this);
}

void M3DSplitString_Init(M3DSplitString *_this, char *_strings)
{
	if (_this == NULL)
		return;

	_this->m_length = (int) strlen(_strings);
	strcpy(_this->m_strings, _strings);
	_this->m_current = 0;
}

int  M3DSplitString_GetCount(M3DSplitString *_this)
{
	int cn = 0, count = 0;
	char *_string = NULL;
	int len = 0;

	if (_this == NULL)
		return 0;

	_string = _this->m_strings;
	len = strlen(_string);

	for (cn = 0; cn < len; cn++)
	{
		if (_string[cn] == ',' || _string[cn] == ';')
			count++;
	}

	return count;
}

static int GetRemainCount(char *_string)
{
	int cn = 0, count = 0;
	int len = 0;

	if (_string == NULL)
		return 0;

	len = strlen(_string);

	for (cn = 0; cn < len; cn++)
	{
		if (_string[cn] == ',' || _string[cn] == ';')
			count++;
	}

	return count;
}

void M3DSplitString_Reset(M3DSplitString *_this)
{
	if (_this == NULL)
		return;

	_this->m_current = 0;
}

int M3DSplitString_GetFirst(M3DSplitString *_this, char *_string)
{
	if (_this == NULL)
		return -1;

	_this->m_current = 0;
	return M3DSplitString_GetNext(_this, _string);
}

int M3DSplitString_GetNext(M3DSplitString *_this, char *_string)
{
	int cn, count;

	if (_this == NULL)
		return -1;

	_string[0] = '\0';
	for (cn = 0; _this->m_current < _this->m_length;)
	{
		//如果第一個就是 ',' 或是 ';', 代表這個字串是空字串, 直接 break 回去
		if (_this->m_strings[_this->m_current] == ',' || _this->m_strings[_this->m_current] == ';')
		{
			_this->m_current++;
			break;
		}
		_string[cn] = _this->m_strings[_this->m_current];
		_this->m_current++;
		cn++;
		if (_this->m_strings[_this->m_current] == ',' || _this->m_strings[_this->m_current] == ';')
		{
			_this->m_current++;
			break;
		}
	}
	_string[cn] = '\0';

	count = GetRemainCount(_this->m_strings + _this->m_current);

	return count;
}

int M3DSplitString_GetAt(M3DSplitString *_this, char *_string, int _index)
{
	int cn = 0, count = 0;

	if (_this == NULL)
		return -1;

	_this->m_current = 0;
	for (cn = 0; cn < _this->m_length; cn++)
	{
		if (count == _index)
			break;
		if (_this->m_strings[cn] == ',')
			count++;
		_this->m_current++;
	}
	return M3DSplitString_GetNext(_this, _string);
}

#ifdef __cplusplus
}
#endif // __cplusplus
