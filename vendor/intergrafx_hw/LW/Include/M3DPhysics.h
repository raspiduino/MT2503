//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : M3DGameFramework
// File        : CPhysics.h
// Description : C 語言公用結構與函式
// Author      : Ray
// Create      : 2011-06-10
// Update      : 2011-06-10
//==============================================================================

#include "M3DMemory.h"

#ifndef __C_PHYSICS__
#define __C_PHYSICS__

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

extern float M3DDistance(float _x, float _y, float _z);

typedef struct _CVector3f
{
	float x, y, z;
} CVector3f;

extern void M3DCircleDegree(CVector3f *_center, float _ds, float _degree, CVector3f *_point);
extern void M3DVerticalCircleDegree(CVector3f *_center, float _ds, float _degree, CVector3f *_point);
extern void CVector3f_Init(CVector3f *_this, float _x, float _y, float _z);
extern void CVector3f_Assign(CVector3f *_this, CVector3f *_src);

typedef struct _CLinear
{
	float		m_TimeStart;
	float		m_TimeEnd;
	CVector3f	m_PosStart;
	CVector3f	m_PosEnd;
	CVector3f	m_PosCurrent;
	CVector3f	m_Velocity;
	float		m_Distance;
} CLinear;

extern void CLinear_Init(CLinear *_this, float _x1, float _y1, float _z1, float _x2, float _y2, float _z2, float _time1, float _time2);
extern void CLinear_Update(CLinear *_this, float _GameTime);

typedef struct _M3DRebound
{
	float		m_Min, m_Max, m_Extra, m_RebondDS;
	float		m_Pos;
	int			m_bTouch;
	int			m_bTouchMove;
	int			m_bRebond;
	float		m_GameTime, m_RebondTime;
	float		m_RebondSpeed;
} M3DRebond;

extern void  M3DRebond_Init(M3DRebond *_this, float _min, float _max);
extern void  M3DRebond_SetTouch(M3DRebond *_this, int _bTouch);
extern void  M3DRebond_Move(M3DRebond *_this, float _ds);
extern int   M3DRebond_GetTouchMove(M3DRebond *_this);
extern float M3DRebond_Update(M3DRebond *_this, float _GameTime);

typedef struct _M3DLWPage
{
	int	m_PageWidth;
	int	m_TotalPage;
	int	m_CurrentPage;
	int	m_CurrentX;
	int	m_Direction;
	int m_Status;
} M3DLWPage;

extern void M3DLWPage_Init(M3DLWPage *_this, int _page_width, int _total_page);
extern int  M3DLWPage_Changed(M3DLWPage *_this, int _x);
extern int  M3DLWPage_GetPage(M3DLWPage *_this);
extern int  M3DLWPage_GetDirection(M3DLWPage *_this);
extern int  M3DLWPage_IsFirstPage(M3DLWPage *_this);
extern int  M3DLWPage_IsLastPage(M3DLWPage *_this);
extern int  M3DLWPage_GetInversePage(M3DLWPage *_this);
extern int  M3DLWPage_GetInverseX(M3DLWPage *_this);
extern int  M3DLWPage_GetTotalWidth(M3DLWPage *_this);
extern void M3DLWPage_SetStatus(M3DLWPage *_this, int _Status);

typedef struct _M3DRotateSimple
{
	float		m_Degree;
	float		m_Speed;
	int			m_Direction;
} M3DRotateSimple;

extern void  M3DRotateSimple_Init(M3DRotateSimple *_this, float _speed);
extern void  M3DRotateSimple_InitRandom(M3DRotateSimple *_this, float _speed);
extern float M3DRotateSimple_Update(M3DRotateSimple *_this, float _ElapsedTime);

typedef struct _M3DRotateCenter
{
	float		m_Min, m_Max, m_Degree;
	M3DLWPage	*m_Pager;
	int			m_bTouch;
	int			m_bTouchMove;
	float		m_Speed;
	int			m_Direction;
} M3DRotateCenter;

extern void  M3DRotateCenter_Init(M3DRotateCenter *_this);
extern void  M3DRotateCenter_Init2(M3DRotateCenter *_this, float _min, float _max);
extern void  M3DRotateCenter_InitPager(M3DRotateCenter *_this, M3DLWPage *_pager, float _min, float _max);
extern void  M3DRotateCenter_SetTouch(M3DRotateCenter *_this, int _bTouch);
extern void  M3DRotateCenter_Move(M3DRotateCenter *_this, float _ds);
extern void  M3DRotateCenter_MoveOut(M3DRotateCenter *_this, float _ds, float _out);
extern void  M3DRotateCenter_MoveByPixel(M3DRotateCenter *_this, int _pixel, float _ds);
extern int   M3DRotateCenter_GetTouchMove(M3DRotateCenter *_this);
extern float M3DRotateCenter_Update(M3DRotateCenter *_this, float _GameTime);

extern void  M3DRotateCenter_SetAuto(M3DRotateCenter *_this, int _pixel, float _speed);
extern float M3DRotateCenter_UpdateAuto(M3DRotateCenter *_this, float _ElapsedTime);
extern float M3DRotateCenter_UpdatePage(M3DRotateCenter *_this, float _ElapsedTime);
extern float M3DRotateCenter_UpdatePageX(M3DRotateCenter *_this, float _ElapsedTime);
extern int   M3DRotateCenter_IsMoving(M3DRotateCenter *_this);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //__C_UTILS__
