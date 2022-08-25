//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : M3DGameFramework
// File        : CPhysics.c
// Description : C 語言公用結構與函式
// Author      : Ray
// Create      : 2011-06-10
// Update      : 2011-06-10
//==============================================================================

#include "M3DPhysics.h"
#include "math.h"
#include "m3d_adaption.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

float M3DDistance(float _x, float _y, float _z)
{
	float distance = 0.0f;
	float value;

	value = _x * _x + _y * _y + _z * _z;
	distance = (float) sqrt(value);

	return distance;
}

void M3DCircleDegree(CVector3f *_center, float _ds, float _degree, CVector3f *_point)
{
	CVector3f rpoint;
	rpoint.x = _ds * (float) cos(_degree / 180.0f * M_PI);
	rpoint.z = _ds * (float) sin(_degree / 180.0f * M_PI);

	_point->x = _center->x + rpoint.x;
	_point->z = _center->z + rpoint.z;
}

void M3DVerticalCircleDegree(CVector3f *_center, float _ds, float _degree, CVector3f *_point)
{
	CVector3f rpoint;
	rpoint.y = _ds * (float) cos(_degree / 180.0f * M_PI);
	rpoint.z = _ds * (float) sin(_degree / 180.0f * M_PI);

	_point->y = _center->y + rpoint.y;
	_point->z = _center->z + rpoint.z;
}

void CVector3f_Init(CVector3f *_this, float _x, float _y, float _z)
{
	_this->x = _x;
	_this->y = _y;
	_this->z = _z;
}

void CVector3f_Assign(CVector3f *_this, CVector3f *_src)
{
	_this->x = _src->x;
	_this->y = _src->y;
	_this->z = _src->z;
}

void CLinear_Init(CLinear *_this, float _x1, float _y1, float _z1, float _x2, float _y2, float _z2, float _time1, float _time2)
{
	_this->m_TimeStart = _time1;
	_this->m_TimeEnd = _time2;
	_this->m_Distance = M3DDistance(_x2-_x1, _y2-_y1, _z2-_z1);

	CVector3f_Init(&_this->m_PosStart, _x1, _y1, _z1);
	CVector3f_Init(&_this->m_PosEnd, _x2, _y2, _z2);
	CVector3f_Init(&_this->m_PosCurrent, 0.0f, 0.0f, 0.0f);
	CVector3f_Init(&_this->m_Velocity, (_x2-_x1)/(_time2 - _time1), (_y2-_y1)/(_time2 - _time1), (_z2-_z1)/(_time2 - _time1));
}

void CLinear_Update(CLinear *_this, float _GameTime)
{
	if (_GameTime < _this->m_TimeStart)
	{
		CVector3f_Assign(&_this->m_PosCurrent, &_this->m_PosStart);
		return;
	}
	if (_GameTime > _this->m_TimeEnd)
	{
		CVector3f_Assign(&_this->m_PosCurrent, &_this->m_PosEnd);
		return;
	}
	_this->m_PosCurrent.x = _this->m_PosStart.x + _this->m_Velocity.x * (_GameTime - _this->m_TimeStart);
	_this->m_PosCurrent.y = _this->m_PosStart.y + _this->m_Velocity.y * (_GameTime - _this->m_TimeStart);
	_this->m_PosCurrent.z = _this->m_PosStart.z + _this->m_Velocity.z * (_GameTime - _this->m_TimeStart);
}

void M3DRebond_Init(M3DRebond *_this, float _min, float _max)
{
	_this->m_Min = _min;
	_this->m_Max = _max;
	_this->m_Pos = 0.0f;
	_this->m_bTouch = 0;
	_this->m_bRebond = 0;
	_this->m_Extra = (_this->m_Max - _this->m_Min) * 0.05f;
	_this->m_RebondDS = 1.0f;
	_this->m_GameTime = 0;
	_this->m_RebondTime = 0;
	_this->m_RebondSpeed = 15.0f;
}

void M3DRebond_SetTouch(M3DRebond *_this, int _bTouch)
{
	_this->m_bTouchMove = 0;
	if (_bTouch > 0)
	{
		_this->m_bTouch = 1;
		_this->m_bRebond = 0;
	}
	else
	{
		_this->m_bTouch = 0;
		if (_this->m_Pos > _this->m_Max || _this->m_Pos < _this->m_Min)
		{
			_this->m_bRebond = 1;
			_this->m_RebondTime = _this->m_GameTime;
		}
	}
}

void M3DRebond_Move(M3DRebond *_this, float _ds)
{
	_this->m_Pos += _ds;
	if (_this->m_bTouch == 0)
	{
		if (_this->m_Pos > _this->m_Max)
			_this->m_Pos = _this->m_Max;
		if (_this->m_Pos < _this->m_Min)
			_this->m_Pos = _this->m_Min;
	}
	else
	{
		_this->m_bTouchMove = 1;
		if (_this->m_Pos > _this->m_Max + _this->m_Extra)
			_this->m_Pos = _this->m_Max + _this->m_Extra;
		if (_this->m_Pos < _this->m_Min - _this->m_Extra)
			_this->m_Pos = _this->m_Min - _this->m_Extra;
	}
}

int  M3DRebond_GetTouchMove(M3DRebond *_this)
{
	return _this->m_bTouchMove;
}

float M3DRebond_Update(M3DRebond *_this, float _GameTime)
{
	float time = (float) _GameTime - _this->m_GameTime;
	float ds = _this->m_RebondSpeed * time / 1000.0f;

	if (_this->m_bRebond == 1)
	{
		if (_this->m_Pos > _this->m_Max)
		{
			_this->m_Pos -= ds;
		}
		if (_this->m_Pos < _this->m_Min)
		{
			_this->m_Pos += ds;
		}
	}
	_this->m_GameTime = _GameTime;

	return _this->m_Pos;
}

void  M3DRotateSimple_Init(M3DRotateSimple *_this, float _speed)
{
	_this->m_Speed = _speed;
	_this->m_Degree = 0.0f;
	_this->m_Direction = 1;
}

void  M3DRotateSimple_InitRandom(M3DRotateSimple *_this, float _speed)
{
	_this->m_Speed = _speed;
	_this->m_Degree = (float) (m3d_adaption_rand() % 360);
	_this->m_Direction = 1;
}

float M3DRotateSimple_Update(M3DRotateSimple *_this, float _ElapsedTime)
{
	_this->m_Degree += _this->m_Speed * _this->m_Direction * _ElapsedTime;
	if (_this->m_Degree > 360.0f)
		_this->m_Degree -= 360.0f;
	if (_this->m_Degree < -360.0f)
		_this->m_Degree += 360.0f;
	return _this->m_Degree;
}

void  M3DRotateCenter_Init(M3DRotateCenter *_this)
{
	_this->m_bTouch = 0;
	_this->m_Direction = 1;
	_this->m_Speed = 0.0f;
	_this->m_Degree = 0.0f;
	_this->m_Pager = NULL;
	_this->m_Max = 360;
	_this->m_Min = 0;
}

void M3DRotateCenter_Init2(M3DRotateCenter *_this, float _min, float _max)
{
	_this->m_bTouch = 0;
	_this->m_Direction = 1;
	_this->m_Speed = 0.0f;
	_this->m_Degree = 0.0f;
	_this->m_Pager = NULL;
	_this->m_Max = _max;
	_this->m_Min = _min;
	_this->m_Degree = (_max - _min) / 2 + _min;
}

void  M3DRotateCenter_InitPager(M3DRotateCenter *_this, M3DLWPage *_pager, float _min, float _max)
{
	_this->m_bTouch = 0;
	_this->m_Direction = 1;
	_this->m_Speed = 0.0f;
	_this->m_Degree = 0.0f;
	_this->m_Pager = _pager;
	_this->m_Max = _max;
	_this->m_Min = _min;
}

void  M3DRotateCenter_SetTouch(M3DRotateCenter *_this, int _bTouch)
{
	_this->m_bTouchMove = 0;
	if (_bTouch > 0)
	{
		_this->m_bTouch = 1;
	}
	else
	{
		_this->m_bTouch = 0;
	}
}

void  M3DRotateCenter_Move(M3DRotateCenter *_this, float _ds)
{
	_this->m_Degree += _ds;
	if (_this->m_bTouch == 1)
		_this->m_bTouchMove = 1;
}

void  M3DRotateCenter_MoveOut(M3DRotateCenter *_this, float _ds, float _out)
{
	_this->m_Degree += _ds;
	if (_this->m_Degree > (_this->m_Max + _out))
		_this->m_Degree = _this->m_Max + _out;
	if (_this->m_Degree < (_this->m_Min - _out))
		_this->m_Degree = _this->m_Min - _out;

	if (_this->m_bTouch == 1)
		_this->m_bTouchMove = 1;
}

void  M3DRotateCenter_MoveByPixel(M3DRotateCenter *_this, int _pixel, float _ds)
{
	if (_pixel > 2 || _pixel < -2)
	{
		_this->m_Degree += _ds * _pixel;
		if (_this->m_Degree > _this->m_Max)
			_this->m_Degree = _this->m_Max;
		if (_this->m_Degree < _this->m_Min)
			_this->m_Degree = _this->m_Min;

		if (_this->m_bTouch == 1)
			_this->m_bTouchMove = 1;
	}
}

int   M3DRotateCenter_GetTouchMove(M3DRotateCenter *_this)
{
	return _this->m_bTouchMove;
}

float M3DRotateCenter_Update(M3DRotateCenter *_this, float _GameTime)
{
	return _this->m_Degree;
}

void  M3DRotateCenter_SetAuto(M3DRotateCenter *_this, int _pixel, float _speed)
{
	_this->m_Speed = _speed;
	if (_pixel < 0)
	{
		switch (_this->m_Direction)
		{
			case 0 :
			case 1 :
			case 2 :
				_this->m_Direction = -1;
				break;
			case -1:
				_this->m_Direction = -2;
				break;
		}
	}
	else
	{
		switch (_this->m_Direction)
		{
			case 0 :
			case -1 :
			case -2 :
				_this->m_Direction = 1;
				break;
			case 1:
				_this->m_Direction = 2;
				break;
		}
	}
}

float M3DRotateCenter_UpdateAuto(M3DRotateCenter *_this, float _ElapsedTime)
{
	_this->m_Degree += _this->m_Speed * _this->m_Direction * _ElapsedTime;
	return _this->m_Degree;
}

float M3DRotateCenter_UpdatePage(M3DRotateCenter *_this, float _ElapsedTime)
{
	float dest_degree = _this->m_Min + (_this->m_Max - _this->m_Min) * M3DLWPage_GetInversePage(_this->m_Pager) / (_this->m_Pager->m_TotalPage - 1);
	float ds = dest_degree - _this->m_Degree;
	float speed;

	if (ds >= 0.0f)
	{
		if (ds < 3.0f)
		{
			_this->m_Degree = dest_degree;
			return _this->m_Degree;
		}
		if (ds > 30.0f)
			speed = 0.3f;
		else
			speed = 0.15f;
	}
	else
	{
		if (ds > -3.0f)
		{
			_this->m_Degree = dest_degree;
			return _this->m_Degree;
		}
		if (ds < -30.0f)
			speed = -0.3f;
		else
			speed = -0.15f;
	}
	_this->m_Degree += speed * _ElapsedTime;
	if (speed > 0)
	{
		if (_this->m_Degree > dest_degree)
			_this->m_Degree = dest_degree;
	}
	else
	{
		if (_this->m_Degree < dest_degree)
			_this->m_Degree = dest_degree;
	}
	return _this->m_Degree;
}

float M3DRotateCenter_UpdatePageX(M3DRotateCenter *_this, float _ElapsedTime)
{
	float dest_degree = _this->m_Min + (_this->m_Max - _this->m_Min) * M3DLWPage_GetInverseX(_this->m_Pager) / M3DLWPage_GetTotalWidth(_this->m_Pager);
	float ds = dest_degree - _this->m_Degree;
	float speed;

	if (ds >= 0.0f)
	{
		if (ds < 3.0f)
		{
			_this->m_Degree = dest_degree;
			return _this->m_Degree;
		}
		speed = 0.15f;
	}
	else
	{
		if (ds > -3.0f)
		{
			_this->m_Degree = dest_degree;
			return _this->m_Degree;
		}
		speed = -0.15f;
	}
	_this->m_Degree += speed * _ElapsedTime;
	if (speed > 0)
	{
		if (_this->m_Degree > dest_degree)
			_this->m_Degree = dest_degree;
	}
	else
	{
		if (_this->m_Degree < dest_degree)
			_this->m_Degree = dest_degree;
	}
	return _this->m_Degree;
}

int  M3DRotateCenter_IsMoving(M3DRotateCenter *_this)
{
	float dest_degree = _this->m_Min + (_this->m_Max - _this->m_Min) * M3DLWPage_GetInverseX(_this->m_Pager) / M3DLWPage_GetTotalWidth(_this->m_Pager);
	if (_this->m_Degree == dest_degree)
		return 0;
	else
		return 1;
}

void  M3DLWPage_Init(M3DLWPage *_this, int _page_width, int _total_page)
{
	_this->m_PageWidth = _page_width;
	_this->m_TotalPage = _total_page;
	_this->m_CurrentPage = _total_page / 2;
	_this->m_CurrentX = _this->m_CurrentPage * _this->m_PageWidth;
}

int   M3DLWPage_Changed(M3DLWPage *_this, int _x)
{
	int direction = _x - _this->m_CurrentX;

	_this->m_CurrentX = _x;
	_this->m_CurrentPage = _this->m_CurrentX / _this->m_PageWidth;
	if (direction > 0)
		_this->m_Direction = 1;
	else
		_this->m_Direction = -1;

	M3DLWPage_SetStatus(_this, 1);

	return _this->m_Direction;
}

int   M3DLWPage_GetPage(M3DLWPage *_this)
{
	return _this->m_CurrentPage;
}

int   M3DLWPage_GetDirection(M3DLWPage *_this)
{
	return _this->m_Direction;
}

int  M3DLWPage_IsFirstPage(M3DLWPage *_this)
{
	int ret = 0;
	if (_this->m_CurrentPage == 0)
		ret = 1;

	return ret;
}

int  M3DLWPage_IsLastPage(M3DLWPage *_this)
{
	int ret = 0;
	if (_this->m_CurrentPage == _this->m_TotalPage - 1)
		ret = 1;

	return ret;
}

int  M3DLWPage_GetInversePage(M3DLWPage *_this)
{
	return _this->m_TotalPage - 1 - _this->m_CurrentPage;
}

int  M3DLWPage_GetInverseX(M3DLWPage *_this)
{
	return (_this->m_TotalPage  - 1) * _this->m_PageWidth - _this->m_CurrentX;
}

int  M3DLWPage_GetTotalWidth(M3DLWPage *_this)
{
	return (_this->m_TotalPage  - 1) * _this->m_PageWidth;
}

void M3DLWPage_SetStatus(M3DLWPage *_this, int _Status)
{
	if (_Status == 0)
		_this->m_Status = 0;
	else
		_this->m_Status = 1;
}

#ifdef __cplusplus
}
#endif // __cplusplus
