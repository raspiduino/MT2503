//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : IGV4GameFramework
// File        : CUtils.c
// Description : C 語言公用結構與函式
// Author      : Ray
// Create      : 2010-09-13
// Update      : 2011-02-15
//==============================================================================

#include "CUtils.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

void CTime_Set(CTime *_this, unsigned char _Hour, unsigned char _Min, unsigned char _Sec)
{
	_this->m_Hour = _Hour;
	_this->m_Min = _Min;
	_this->m_Sec = _Sec;
}

//================= CArray Begin ================================
CArray *CArray_New(void *_item)
{
	CArray *self = (CArray *) CNew(sizeof(CArray));
	self->m_Slot = DEFAULT_SLOT;
	self->m_Array = (void **) CNew(sizeof(void *) * self->m_Slot);

	if (_item != NULL)
		CArray_Add(self, _item);

	return self;
}

CArray *CArray_Init(CArray *_this, int _slot)
{
	_this->m_Slot = _slot;

	_this->m_Array = (void **) CNew(sizeof(void *) * _this->m_Slot);

	return _this;
}

void CArray_Expand(CArray *_this)
{
	int iNewSize = _this->m_Slot + DEFAULT_SLOT;
	void **_array = NULL;

	if (_this == NULL)
		return;

	_array = (void **) CNew(sizeof(void *) * iNewSize);
	CMemcpy(_array, _this->m_Array, (sizeof(void *) * _this->m_Slot));

	_this->m_Slot = _this->m_Slot + DEFAULT_SLOT;
	CDel(_this->m_Array);
	_this->m_Array = _array;
}

void CArray_Add(CArray *_this, void *_item)
{
	if (_this == NULL)
		return;

	if (_this->m_Count == _this->m_Slot)
		CArray_Expand(_this);
	_this->m_Array[_this->m_Count] = _item;
	//_this->m_Count++; edit by Odin
	_this->m_Count = _this->m_Count + 1;
}

void *CArray_Get(CArray *_this, int _index)
{
	if (_this == NULL || _this->m_Array == NULL)
		return NULL;

	if (_index >= 0 && _index < _this->m_Count)
		return _this->m_Array[_index];
	else
		return NULL;
}

//RAY::2010-10-18
void CArray_Remove(CArray *_this, int _index)
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

void CArray_Clear(CArray *_this)
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

void CArray_Del(CArray *_this)
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
		CDel(_this->m_Array);
	}
	CDel(_this);
}

//================= CArray End ==================================

//================= CStringArray Begin ==========================

CArray *CStringArray_New(const char *_name)
{
	char *name = NULL;
	CArray *self = NULL;

	if (_name != NULL)
	{
		name = (char *) CNew(DEFAULT_NAME_SIZE);
		CStrNCpy(name, _name, DEFAULT_NAME_SIZE);
	}

	self = CArray_New(name);

	return self;
}

void CStringArray_Add(CArray *_this, const char *_name)
{
	char *name = NULL;

	if (_this == NULL)
		return;

	name = (char *) CNew(DEFAULT_NAME_SIZE);

	if (_name != NULL)
	{
		CStrNCpy(name, _name, DEFAULT_NAME_SIZE);
	}
	CArray_Add(_this, name);
}

int CStringArray_GetIndex(CArray *_this, const char *_name)
{
	int iIndex = -1;
	int cn;

	if (_this == NULL)
		return iIndex;

	if (_this->m_Array != NULL)
	{
		for (cn = 0; cn < _this->m_Count; cn = cn + 1)
		{
			if (CStrCmp(_this->m_Array[cn], _name) == 0)
			{
				iIndex = cn;
				break;
			}
		}
	}
	return iIndex;
}

const char *CStringArray_Get(CArray *_this, int _index)
{
	if (_this == NULL || _this->m_Array == NULL)
		return NULL;

	if (_index >= 0 && _index < _this->m_Count)
		return (const char *) _this->m_Array[_index];
	else
		return NULL;
}

//RAY::2010-10-19
void CStringArray_Remove(CArray *_this, int _index)
{
	int cn = 0;
	if (_this == NULL || _this->m_Array == NULL || _this->m_Count == 0 || _index < 0 || _index >= _this->m_Count)
		return;

	for (cn = _index; cn < _this->m_Count - 1; cn = cn + 1)
	{
		_this->m_Array[cn] = _this->m_Array[cn+1];
	}
	CDel(_this->m_Array[_this->m_Count - 1]);
	_this->m_Array[_this->m_Count - 1] = NULL;
	_this->m_Count = _this->m_Count - 1;
}

void CStringArray_Clear(CArray *_this)
{
	int cn;

	if (_this == NULL)
		return;

	if (_this->m_Array != NULL)
	{
		for (cn = 0; cn < _this->m_Count; cn = cn + 1)
		{
			CDel(_this->m_Array[cn]);
		}
	}
	_this->m_Count = 0;
}

void CStringArray_Del(CArray *_this)
{
	if (_this == NULL)
		return;

	if (_this->m_Array != NULL)
	{
		CStringArray_Clear(_this);
	}
	CArray_Del(_this);
}

//================= CStringArray End ============================


//================= CNamedObjArray Begin=========================

CArray *CNamedObjArray_New(const char *_name, void *_obj)
{
	CNamedObj *item = NULL;
	CArray *self = NULL;

	if (_name != NULL && _obj != NULL)
	{
		item = (CNamedObj *) CNew(sizeof(CNamedObj));
		CStrNCpy(item->m_Name, _name, DEFAULT_NAME_SIZE);

		item->m_Obj = _obj;
	}

	self = CArray_New(item);

	return self;
}

void CNamedObjArray_Add(CArray *_this, const char *_name, void *_obj)
{
	CNamedObj *item = NULL;

	if (_this == NULL)
		return;

	if (_name != NULL && _obj != NULL)
	{
		item = (CNamedObj *) CNew(sizeof(CNamedObj));
		CStrNCpy(item->m_Name, _name, DEFAULT_NAME_SIZE);

		item->m_Obj = _obj;
	}

	CArray_Add(_this, item);
}

int CNamedObjArray_GetIndex(CArray *_this, const char *_name)
{
	int iIndex = -1;
	int cn;
	CNamedObj *item = NULL;

	if (_this == NULL)
		return iIndex;

	if (_this->m_Array != NULL)
	{
		for (cn = 0; cn < _this->m_Count; cn = cn + 1)
		{
			item = (CNamedObj *) _this->m_Array[cn];
			if (CStrCmp(item->m_Name, _name) == 0)
			{
				iIndex = cn;
				break;
			}
		}
	}

	return iIndex;
}

int CNamedObjArray_GetNextIndexByName(CArray *_this, const char *_name, int _iPrev)
{
	int cn = 0, index = -1;
	CNamedObj *item = NULL;

	if (_this == NULL || _this->m_Array == NULL || _iPrev < 0)
		return -1;

	for (cn = _iPrev; cn < _this->m_Count; cn = cn + 1)
	{
		item = (CNamedObj *) _this->m_Array[cn];
		if (CStrCmp(item->m_Name, _name) == 0)
		{
			//obj = item->m_Obj;
			break;
		}
	}

	return index;
}

const char *CNamedObjArray_GetName(CArray *_this, int _index)
{
	CNamedObj *item = NULL;

	if (_index >= 0 && _index < _this->m_Count)
	{
		item = _this->m_Array[_index];
		return item->m_Name;
	}
	else
		return NULL;
}

void *CNamedObjArray_Get(CArray *_this, int _index)
{
	CNamedObj *item = NULL;

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

void *CNamedObjArray_GetFirstByName(CArray *_this, const char *_name)
{
	int index = -1;
	void *obj = NULL;

	if (_this == NULL || _this->m_Array == NULL)
		return NULL;

	index = CNamedObjArray_GetIndex(_this, _name);
	if (index != -1)
	{
		obj = CNamedObjArray_Get(_this, index);
	}

	return obj;
}

void *CNamedObjArray_GetNextByName(CArray *_this, const char *_name, void *_pPrev)
{
	int cn = 0;
	void *obj = NULL;
	int iFindPrev = 0;
	CNamedObj *item = NULL;

	if (_this == NULL || _this->m_Array == NULL)
		return NULL;

	for (cn = 0; cn < _this->m_Count; cn = cn + 1)
	{
		item = (CNamedObj *) _this->m_Array[cn];
		if (CStrCmp(item->m_Name, _name) == 0)
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
void CNamedObjArray_Remove(CArray *_this, int _index)
{
	int cn = 0;
	if (_this == NULL || _this->m_Array == NULL || _this->m_Count == 0 || _index < 0 || _index >= _this->m_Count)
		return;

	CDel(_this->m_Array[_index]);
	_this->m_Array[_index] = NULL;
	for (cn = _index; cn < _this->m_Count - 1; cn = cn + 1)
	{
		_this->m_Array[cn] = _this->m_Array[cn+1];
	}
	_this->m_Array[_this->m_Count - 1] = NULL;
	_this->m_Count = _this->m_Count - 1;
}

void CNamedObjArray_Clear(CArray *_this)
{
	int cn;

	if (_this == NULL || _this->m_Array == NULL)
		return;

	for (cn = 0; cn < _this->m_Count; cn = cn + 1)
	{
		CDel(_this->m_Array[cn]);
	}
	_this->m_Count = 0;
}

void CNamedObjArray_Del(CArray *_this)
{
	if (_this == NULL)
		return;

	if (_this->m_Array != NULL)
	{
		CNamedObjArray_Clear(_this);
	}
	CArray_Del(_this);
}

//================= CNamedObjArray End ===========================

//================= CNamedIdArray Begin=========================

void CNamedIdArray_Add(CArray *_this, const char *_name, int _id)
{
	CNamedId *item = NULL;

	if (_this == NULL)
		return;

	if (_name != NULL)
	{
		item = (CNamedId *) CNew(sizeof(CNamedId));
		CStrNCpy(item->m_Name, _name, DEFAULT_NAME_SIZE);

		item->m_Id = _id;
	}

	CArray_Add(_this, item);
}

int CNamedIdArray_GetIndex(CArray *_this, const char *_name)
{
	int iIndex = -1;
	int cn;
	CNamedId *item = NULL;

	if (_this == NULL || _this->m_Array == NULL)
		return iIndex;

	for (cn = 0; cn < _this->m_Count; cn = cn + 1)
	{
		item = (CNamedId *) _this->m_Array[cn];
		if (CStrCmp(item->m_Name, _name) == 0)
		{
			iIndex = cn;
			break;
		}
	}

	return iIndex;
}

int CNamedIdArray_Get(CArray *_this, int _index)
{
	CNamedId *item = NULL;

	if (_this == NULL || _this->m_Array == NULL)
		return -1;

	if (_index >= 0 && _index < _this->m_Count)
	{
		item = _this->m_Array[_index];
		return item->m_Id;
	}
	else
		return -1;
}

int CNamedIdArray_GetByName(CArray *_this, const char *_name)
{
	int index = -1;
	int id = -1;

	if (_this == NULL)
		return id;

	index = CNamedIdArray_GetIndex(_this, _name);
	if (index != -1)
	{
		id = CNamedIdArray_Get(_this, index);
	}

	return id;
}

void CNamedIdArray_Clear(CArray *_this)
{
	int cn;

	if (_this == NULL || _this->m_Array == NULL)
		return;

	for (cn = 0; cn < _this->m_Count; cn = cn + 1)
	{
		CDel(_this->m_Array[cn]);
	}
	_this->m_Count = 0;
}

void CNamedIdArray_Del(CArray *_this)
{
	if (_this == NULL)
		return;

	if (_this->m_Array != NULL)
	{
		CNamedIdArray_Clear(_this);
	}
	CArray_Del(_this);
}

//================= CNamedIdArray End ===========================

CQueue *CQueue_New(int _size)
{
	CQueue *self = (CQueue *) CNew(sizeof(CQueue));
	self->m_Slot = _size;
	self->m_Array = (void **) CNew(sizeof(void *) * self->m_Slot);

	self->m_Head = -1;
	self->m_Tail = -1;

	return self;
}

int  CQueue_Available(CQueue *_this)
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

int  CQueue_Used(CQueue *_this)
{
	int iAvailable = CQueue_Available(_this);
	return _this->m_Slot - iAvailable;
}

//there are some problems
void CQueue_Expand(CQueue *_this)
{
	void **_array = NULL;

	if (_this == NULL)
		return;

	_array = (void **) CNew(sizeof(void *) * (_this->m_Slot + DEFAULT_SLOT));
	CMemcpy(_array, _this->m_Array, _this->m_Slot);

	_this->m_Slot = _this->m_Slot + DEFAULT_SLOT;
	CDel(_this->m_Array);
	_this->m_Array = _array;
}

void CQueue_Push(CQueue *_this, void *_item)
{
	if (_this == NULL || _this->m_Array == NULL)
		return;

	if (CQueue_Available(_this) == 0)
		CQueue_Expand(_this);

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

void *CQueue_Pop(CQueue *_this)
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

void *CQueue_Head(CQueue *_this)
{
	void *item = NULL;

	if (_this == NULL || _this->m_Array == NULL)
		return NULL;

	if (_this->m_Head != -1)
		item = _this->m_Array[_this->m_Head];

	return item;
}

void *CQueue_Tail(CQueue *_this)
{
	void *item = NULL;

	if (_this == NULL || _this->m_Array == NULL)
		return NULL;

	if (_this->m_Tail != -1)
		item = _this->m_Array[_this->m_Tail];

	return item;
}

void CQueue_Clear(CQueue *_this)
{
	int cn;

	if (_this == NULL || _this->m_Array == NULL)
		return;

	for (cn = 0; cn < _this->m_Slot; cn = cn + 1)
	{
		_this->m_Array[cn] = NULL;
	}
	_this->m_Slot = 0;
	_this->m_Head = -1;
	_this->m_Tail = -1;
}

void CQueue_Del(CQueue *_this)
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
		CDel(_this->m_Array);
	}
	CDel(_this);
}


void CArrayPool_Init(CArrayPool *_this, void *_Mem, int _MemSize, int _UnitSize)
{
	int cn = 0;
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

void *CArrayPool_Alloc(CArrayPool *_this)
{
	int cn = 0;
	int index = -1;
	unsigned char *address = NULL;

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

int CArrayPool_Available(CArrayPool *_this)
{
	return _this->m_Slot - _this->m_Used;
}

void CArrayPool_Free(CArrayPool *_this, void *_address)
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

void CRect_Set(CRect *_this, int _x, int _y, int _width, int _height)
{
	_this->m_X = _x;
	_this->m_Y = _y;
	_this->m_Width = _width;
	_this->m_Height = _height;
	_this->m_Right = _x + _width - 1;
	_this->m_Bottom = _y + _height - 1;
}

int  CRect_Hit(CRect *_this, int _x, int _y)
{
	int hit = 0;
	if (_x >= _this->m_X && _x <= _this->m_Right && _y >= _this->m_Y && _y <= _this->m_Bottom)
		hit = 1;
	return hit;
}

#ifdef __cplusplus
}
#endif // __cplusplus
