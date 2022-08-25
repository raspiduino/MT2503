//==============================================================================
// Copyright (c)2005 InterGrafx, Inc. All rights reserved.
// Project     : M3D_LW_Lib
// File        : M3DRenderer.c
// Description : M3D 桌布公用程式
// Author      : Ray
// Create      : 2011-05-31
// Update      : 2011-11-03
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "M3DRenderer.h"
#include "M3DGameDef.h"

#include "m3d_adaption.h"
#include "M3DMemory.h"
#include "M3DModel.h"

#ifdef __cplusplus
extern "C" {
#endif

static M3DModel *M3DModel_Current = NULL;
static int M3DModel_SetTextureCallBack(struct IGV5ModelType *pModel, int _i32NodeIndex);
static int M3DModel_BeforeLoadTextureCallback(struct IGV5ModelType *pModel, char *pOldName, unsigned nMaxLen);
static M3DModel *M3DModel_Stock[16];
static int M3DModel_CurrentStock;

void M3DAniInfo_Init(M3DAniInfo *_this, char *_values)
{
	int cn;
	long value = 0L;
	float total_duration = 0L;
	int length = strlen(_values);

	if (_values == NULL)
		return;

	for (cn = 0; cn < length; cn++)
	{
		if (_values[cn] == ',' || _values[cn] == ';')
		{
			M3DAniInfo_Append(_this, (float) value);
			total_duration += (float) value;
			value = 0;
		}
		else
		{
			value = value * 10 + _values[cn] - '0';
		}
	}
	_this->m_TotalDuration = total_duration;
}

void M3DAniInfo_InitEven(M3DAniInfo *_this, char *_values)
{
	int cn;
	long value = 0L;
	float total_duration = 0L;
	int length = strlen(_values);

	if (_values == NULL)
		return;

	for (cn = 0; cn < length; cn++)
	{
		if (_values[cn] == ',' || _values[cn] == ';')
		{
			M3DAniInfo_Append(_this, (float) value);
			total_duration += (float) value;
			value = 0;
		}
		else
		{
			value = value * 10 + _values[cn] - '0';
		}
	}
	_this->m_TotalDuration = total_duration;
	_this->m_Even = 1;
}

void M3DAniInfo_Copy(M3DAniInfo *_this, M3DAniInfo *_to)
{
	int cn;
	_to->m_Count = _this->m_Count;
	_to->m_TotalDuration = _this->m_TotalDuration;

	for (cn = 0; cn < _this->m_Count; cn++)
	{
		_to->m_Animation[cn].m_Start = _this->m_Animation[cn].m_Start;
		_to->m_Animation[cn].m_End = _this->m_Animation[cn].m_End;
		_to->m_Animation[cn].m_Duration = _this->m_Animation[cn].m_Duration;
		_to->m_Animation[cn].m_TimeFactor = _this->m_Animation[cn].m_TimeFactor;
	}
}

void M3DAniInfo_Append(M3DAniInfo *_this, float _duration)
{
	if (_this->m_Count < M3D_DEFAULT_ANIMATION_SLOT)
	{
		_this->m_Animation[_this->m_Count].m_Duration = _duration;

		if (_this->m_Count == 0)
			_this->m_Animation[_this->m_Count].m_Start = 0;
		else
			_this->m_Animation[_this->m_Count].m_Start = _this->m_Animation[_this->m_Count-1].m_End;

		_this->m_Animation[_this->m_Count].m_End = _this->m_Animation[_this->m_Count].m_Start + _this->m_Animation[_this->m_Count].m_Duration;
		_this->m_Animation[_this->m_Count].m_TimeFactor = 1.0f;
		_this->m_Count++;
	}
}

void M3DAniInfo_Add(M3DAniInfo *_this, char *_name, float _iStart, float _iEnd)
{
	if (_this->m_Count < M3D_DEFAULT_ANIMATION_SLOT)
	{
		strcpy(_this->m_Animation[_this->m_Count].m_Name, _name);
		_this->m_Animation[_this->m_Count].m_Duration = _iEnd - _iStart;
		_this->m_Animation[_this->m_Count].m_Start = _iStart;
		_this->m_Animation[_this->m_Count].m_End = _iEnd;
		_this->m_Animation[_this->m_Count].m_TimeFactor = 1.0f;
		_this->m_Count++;
	}
}

void M3DAniInfo_AddByFrame(M3DAniInfo *_this, char *_name, int _iStart, int _iEnd, float _time_factor)
{
	if (_this->m_Count < M3D_DEFAULT_ANIMATION_SLOT)
	{
		strcpy(_this->m_Animation[_this->m_Count].m_Name, _name);
		_this->m_Animation[_this->m_Count].m_Start = (float) _iStart * 1000.0f / 30.0f;
		_this->m_Animation[_this->m_Count].m_End = (float) _iEnd * 1000.0f / 30.0f;
		_this->m_Animation[_this->m_Count].m_TimeFactor = _time_factor;
		_this->m_Animation[_this->m_Count].m_Duration = _this->m_Animation[_this->m_Count].m_End - _this->m_Animation[_this->m_Count].m_Start;
		_this->m_Count++;
	}
}

int  M3DAniInfo_GetIndex(M3DAniInfo *_this, char *_name)
{
	int cn = 0;
	int index = -1;

	for (cn = 0; cn < _this->m_Count; cn++)
	{
		if (strcmp(_this->m_Animation[cn].m_Name, _name) == 0)
		{
			index = cn;
			break;
		}
	}

	return index;
}

M3DAnimation *M3DAniInfo_Get(M3DAniInfo *_this, int _index)
{
	M3DAnimation *_ani = NULL;

	if (_this->m_Even == 1)
	{
		if ((_index*2) < _this->m_Count)
		{
			_ani = &_this->m_Animation[_index*2];
		}
	}
	else
	{
		if (_index < _this->m_Count)
		{
			_ani = &_this->m_Animation[_index];
		}
	}

	return _ani;
}

M3DAnimation *M3DAniInfo_GetByName(M3DAniInfo *_this, char *_name)
{
	int index = M3DAniInfo_GetIndex(_this, _name);
	M3DAnimation *_ani = NULL;

	if (index != -1)
		_ani = &_this->m_Animation[index];

	return _ani;
}

void M3DModel_InitStock(void)
{
	int cn;
	M3DModel_CurrentStock = 0;
	for (cn = 0; cn < 16; cn++)
	{
		M3DModel_Stock[cn] = NULL;
	}
}

M3DModel *M3DModel_GetCurrentStock(struct IGV5ModelType *pModel)
{
	int cn;
	M3DModel *pM3DModel = NULL;

	for (cn = 0; cn < 16; cn++)
	{
		if (&M3DModel_Stock[cn]->m_Node == pModel)
		{
			pM3DModel = M3DModel_Stock[cn];
			break;
		}
	}
	return pM3DModel;
}

M3DModel *M3DModel_New(M3DRenderer *_rr, char *_name)
{
	M3DModel *self = NULL;

	if (_rr == NULL)
		return NULL;

	self = M3DMemory_New(sizeof(M3DModel));
	M3DMemory_Set((void *) self, sizeof(M3DModel), 0);
	strcpy(self->m_Name, _name);
	self->m_rr = _rr;
	self->m_TimeFactor = 1.0f;
	self->m_iAnimateForward = 1;

	return self;
}


static int M3DModel_SetTextureCallBack(struct IGV5ModelType *pModel, int _i32NodeIndex)
{
	/* we want to manually set normal map and shadow map */
	//IGV5Texture_SetBlankNormalMap(1);

	M3DModel_Current = M3DModel_GetCurrentStock(pModel);
	M3DModel_BindTexture(M3DModel_Current, _i32NodeIndex);

	return 0;
}

static int M3DModel_BeforeLoadTextureCallback(struct IGV5ModelType *pModel, char *pOldName, unsigned nMaxLen)
{
	/* The POD model has all original texture in png format, we simply show how to specify your own here */
	char *pTexExt = strstr(pOldName, ".png");
	if (pTexExt)
		strcpy(pTexExt, ".pvr");

	return 0;
}

void M3DModel_BindTexture(M3DModel *_this, int _i32NodeIndex)
{
	SPODNode *pNode = NULL;
	int iMatIndex = -1;
	int iTexIndex = -1;
	SPODTexture *pTexture = NULL;
	char tex_name[32];
	char *pTexExt = NULL;

	if (_this == NULL)
		return;

	if (_i32NodeIndex < (int) _this->m_Node.m_Scene.m_POD.nNumMeshNode)
	{
		//if (strcmp(_this->m_Name, "coral") == 0)
			//pNode = NULL;
		pNode = &_this->m_Node.m_Scene.m_POD.pNode[_i32NodeIndex];
		iMatIndex = pNode->nIdxMaterial;
		if (iMatIndex == -1)
			return;

		iTexIndex = _this->m_Node.m_Scene.m_POD.pMaterial[iMatIndex].nIdxTexDiffuse;

		if (iTexIndex >= 0)
		{
			pTexture = &_this->m_Node.m_Scene.m_POD.pTexture[iTexIndex];

			//RAY::2011-09-04 這一段之後要拿掉
			strcpy(tex_name, pTexture->pszName);
			pTexExt = strstr(tex_name, ".png");
			if (pTexExt)
				strcpy(pTexExt, ".pvr");

			M3DTextureCollection_Bind(&_this->m_rr->m_TextureCollection, tex_name);
			//M3DTextureCollection_Bind(&_this->m_rr->m_TextureCollection, pTexture->pszName);
		}
	}
}

void M3DModel_Load(M3DModel *_this, unsigned char const *_data, long _data_length, M3DSplitString *_textures)
{
	int iCount = 0;

	if (_this == NULL)
		return;

	if (_textures != NULL)
		iCount = M3DSplitString_GetCount(_textures);

	IGV5NameCache_Create(&_this->m_TexCache, iCount, sizeof(IGV5Texture));

	IGV5Model_Create(&_this->m_Node);
	if (_textures != NULL)
		M3DTextureCollection_GetByNames(&_this->m_rr->m_TextureCollection, _textures, &_this->m_TexCache);

	M3DModel_Current = _this;
	_this->m_TextureName = _textures;
	_this->m_Node.m_fnSetTextureCallBack = M3DModel_SetTextureCallBack;
	_this->m_Node.m_fnLoadTextureCallback = M3DModel_BeforeLoadTextureCallback;
	IGV5Model_LoadContentFromCache(&_this->m_Node, (void *) _data, (unsigned int) _data_length, &_this->m_TexCache);

	// Enable backface culling and depth test
	M3DModel_Stock[M3DModel_CurrentStock] = _this;
	M3DModel_CurrentStock++;

	_this->m_AnimationLength = (float)(_this->m_Node.m_Scene.m_POD.nNumFrame-1) * 1000.0f / 30.0f;
	_this->m_bLoaded = 1;
}

void M3DModel_LoadFromFile(M3DModel *_this, char *_filename, M3DSplitString *_textures)
{
	if (_this == NULL)
		return;

	IGV5Model_Create(&_this->m_Node);

	M3DModel_Current = _this;
	_this->m_TextureName = _textures;
	_this->m_Node.m_fnSetTextureCallBack = M3DModel_SetTextureCallBack;
	_this->m_Node.m_fnLoadTextureCallback = M3DModel_BeforeLoadTextureCallback;
	IGV5Model_LoadContent(&_this->m_Node, "./POD/", _filename);

	// Enable backface culling and depth test
	IGV5Renderer_SetBackFaceCulling(IGV5RS_CULL_BACK);
	IGV5Renderer_SetZTestFunc(IGV5RS_ZTEST_LEQUAL);
	IGV5Renderer_SetZWrite(IGV5_TRUE);

	M3DModel_Stock[M3DModel_CurrentStock] = _this;
	M3DModel_CurrentStock++;

	_this->m_AnimationLength = (float)(_this->m_Node.m_Scene.m_POD.nNumFrame-1) * 1000.0f / 30.0f;
	_this->m_bLoaded = 1;
}

void M3DModel_InitAnimation(M3DModel *_this, char *_anim_info)
{
	if (_this == NULL)
		return;

	M3DAniInfo_Init(&_this->m_AniInfo, _anim_info);
}

void M3DModel_InitAnimationEven(M3DModel *_this, char *_anim_info)
{
	if (_this == NULL)
		return;

	M3DAniInfo_InitEven(&_this->m_AniInfo, _anim_info);
}

void M3DModel_AddAnimationByFrame(M3DModel *_this, char *_name, int _iStartFrame, int _iEndFrame, float _time_factor)
{
	if (_this == NULL)
		return;

	M3DAniInfo_AddByFrame(&_this->m_AniInfo, _name, _iStartFrame, _iEndFrame, _time_factor);
}

void M3DModel_SetAnimation(M3DModel *_this, int _iAnimation)
{
	if (_this == NULL)
		return;

	if (_this->m_iCurrentAnimation == _this->m_iDefaultAnimation)
	{
		_this->m_iCurrentAnimation = _iAnimation;
		_this->m_CurrentAnimationName = NULL;
		_this->m_Time = 0;
	}
	_this->m_Stop = 0;
}

void M3DModel_SetAnimationStart(M3DModel *_this, int _iAnimation)
{
	if (_this == NULL)
		return;

	if (_this->m_bLoaded == 0)
		return;

	_this->m_iCurrentAnimation = _iAnimation;
	_this->m_CurrentAnimationName = NULL;
	_this->m_Time = 0;
	_this->m_Stop = 0;
}

void M3DModel_SetDefaultAnimation(M3DModel *_this, int _iAnimation, float _time_factor)
{
	if (_this == NULL)
		return;

	_this->m_iDefaultAnimation = _iAnimation;
	_this->m_iCurrentAnimation = _iAnimation;
	_this->m_AniInfo.m_Animation[_iAnimation].m_TimeFactor = _time_factor;
	_this->m_Time = 0;
}

int M3DModel_IsDefaultAnimation(M3DModel *_this)
{
	if (_this == NULL)
		return 0;

	if (_this->m_iCurrentAnimation == _this->m_iDefaultAnimation)
		return 1;
	else
		return 0;
}

void M3DModel_SetAnimationByName(M3DModel *_this, char *_name)
{
	int index = -1;
	
	if (_this == NULL)
		return;

	index = M3DAniInfo_GetIndex(&_this->m_AniInfo, _name);

	if (index != -1 && _this->m_iCurrentAnimation == _this->m_iDefaultAnimation)
	{
		_this->m_iCurrentAnimation = index;
		_this->m_CurrentAnimationName = _name;
		_this->m_Time = 0;
		_this->m_Stop = 0;
	}
}

void M3DModel_SetActiveCamera(M3DModel *_this)
{
	if (_this == NULL)
		return;

	M3DRenderer_PrepareCamera(_this->m_rr, &_this->m_Node);
}

void M3DModel_SetActiveLight(M3DModel *_this)
{
	if (_this == NULL)
		return;

	M3DRenderer_PrepareLight(_this->m_rr, &_this->m_Node);
}

void M3DModel_AnimateStart(M3DModel *_this)
{
	if (_this == NULL)
		return;

	if (_this->m_bLoaded == 0)
		return;

	_this->m_Time = 0;
	_this->m_Stop = 0;
}

void M3DModel_AnimateStop(M3DModel *_this)
{
	if (_this == NULL)
		return;

	if (_this->m_bLoaded == 0)
		return;

	_this->m_Time = 0;
	_this->m_Stop = 1;
	IGV5PODModel_SetFrame(&_this->m_Node.m_Scene, 0);
	IGV5Model_UpdateModelBoundingBox(&_this->m_Node, NULL);
}

void M3DModel_AnimateOnce(M3DModel *_this, float _ElapsedTime)
{
	float ElapsedTime = 0.0f;
	float frame = 0.0f;
	IGV5PODModel *pModel = NULL;

	if (_this == NULL)
		return;

	if (_this->m_bLoaded == 0 || _this->m_Stop == 1)
		return;

	ElapsedTime = (float) (_ElapsedTime * _this->m_TimeFactor);
	
	pModel = &(_this->m_Node.m_Scene);

	if (_this->m_Time + ElapsedTime < _this->m_AnimationLength)
		_this->m_Time += ElapsedTime;
	else
	{
		_this->m_Stop = 1;
		_this->m_Time = 0;
	}
	frame = (float) _this->m_Time * 30.0f / 1000.0f;

	IGV5PODModel_SetFrame(pModel, frame);
	IGV5Model_UpdateModelBoundingBox(&_this->m_Node, NULL);
}

void M3DModel_SetTime(M3DModel *_this, float _Time)
{
	if (_this == NULL)
		return;

	_this->m_Time = _Time;
}

float M3DModel_GetTimeFrame(M3DModel *_this)
{
	if (_this == NULL)
		return 0.0f;

	return _this->m_Time * 30.0f / 1000.0f;
}

float M3DModel_GetCurrentFrame(M3DModel *_this)
{
	float frame = 0.0f;
	M3DAnimation *ani = NULL;
	
	if (_this == NULL)
		return 0.0f;

	ani = M3DModel_GetCurrentAnimation(_this);

	if (ani != NULL)
	{
		frame = _this->m_Time + ani->m_Start;
		frame = frame * 30.0f / 1000.0f;
	}
	return frame;
}

void M3DModel_AnimateLoop(M3DModel *_this, float _ElapsedTime, int _bRewind)
{
	float ElapsedTime ;
	float frame = 0.0f;
	IGV5PODModel *pModel = NULL;

	if (_this == NULL)
		return;

	if (_this->m_bLoaded == 0)
		return;

	pModel = &(_this->m_Node.m_Scene);
	
	ElapsedTime = (float) (_ElapsedTime * _this->m_TimeFactor);

	_this->m_Time += _this->m_iAnimateForward * ElapsedTime;

	if (_this->m_bLoaded == 1)
	{
		if (_bRewind == 1)
		{
			if (_this->m_Time > _this->m_AnimationLength)
			{
				_this->m_Time = _this->m_AnimationLength - 1;
				_this->m_iAnimateForward = -1;
			}
			if (_this->m_Time < 0)
			{
				_this->m_Time = 0;
				_this->m_iAnimateForward = 1;
			}
		}
		else
		{
			if (_this->m_Time > _this->m_AnimationLength)
			{
				_this->m_Time = 0;
			}
		}
		frame = (float) _this->m_Time * 30.0f / 1000.0f;

		IGV5PODModel_SetFrame(pModel, frame);
		IGV5Model_UpdateModelBoundingBox(&_this->m_Node, NULL);
	}
}

M3DAnimation *M3DModel_GetCurrentAnimation(M3DModel *_this)
{
	M3DAnimation *ani = NULL;

	if (_this == NULL)
		return NULL;

	if (_this->m_CurrentAnimationName != NULL)
		ani = M3DAniInfo_GetByName(&_this->m_AniInfo, _this->m_CurrentAnimationName);

	if (ani == NULL)
		ani = M3DAniInfo_Get(&_this->m_AniInfo, _this->m_iCurrentAnimation);

	return ani;
}

void M3DModel_AnimateCurrent(M3DModel *_this, float _ElapsedTime)
{
	M3DAnimation *ani = NULL;
	float ElapsedTime = 0.0f;

	if (_this == NULL)
		return;

	ElapsedTime = (float) (_ElapsedTime * _this->m_TimeFactor);

	if (_this->m_bLoaded == 1)
	{
		float time = 0;
		float frame = 0.0f;

		ani = M3DModel_GetCurrentAnimation(_this);
		//RAY::2011-09-18
		if (ani->m_TimeFactor != 1.0f)
			ElapsedTime = (float) (_ElapsedTime * ani->m_TimeFactor);
			
		_this->m_Time += ElapsedTime;

		if (_this->m_Time > ani->m_Duration)
		{
			_this->m_Time -= ani->m_Duration;
			_this->m_iCurrentAnimation = _this->m_iDefaultAnimation;
			_this->m_CurrentAnimationName = NULL;
		}
		ani = M3DModel_GetCurrentAnimation(_this);
		time = ani->m_Start + _this->m_Time;
		frame = (float) time * 30.0f / 1000.0f;
		IGV5PODModel_SetFrame(&_this->m_Node.m_Scene, frame);
		IGV5Model_UpdateModelBoundingBox(&_this->m_Node, NULL);
	}
}

void M3DModel_AnimateCurrentLoop(M3DModel *_this, float _ElapsedTime, int _bRewind)
{
	M3DAnimation *ani = NULL;
	float ElapsedTime = 0.0f;

	if (_this == NULL)
		return;
	ElapsedTime = (float) (_ElapsedTime * _this->m_TimeFactor);


	if (_this->m_bLoaded == 1)
	{
		float time = 0;
		float frame = 0.0f;

		ani = M3DModel_GetCurrentAnimation(_this);
		//RAY::2011-09-18
		if (ani->m_TimeFactor != 1.0f)
			ElapsedTime = (float) (_ElapsedTime * ani->m_TimeFactor);

		_this->m_Time += _this->m_iAnimateForward * ElapsedTime;

		if (_bRewind == 1)
		{
			if (_this->m_Time > ani->m_Duration)
			{
				_this->m_Time = ani->m_Duration - 1;
				_this->m_iAnimateForward = -1;
			}
			if (_this->m_Time < 0)
			{
				_this->m_Time = 0;
				_this->m_iAnimateForward = 1;
			}
		}
		else
		{
			if (_this->m_Time > ani->m_Duration)
			{
				_this->m_Time = 0;
			}
		}
		time = ani->m_Start + _this->m_Time;
		frame = (float) time * 30.0f / 1000.0f;
		IGV5PODModel_SetFrame(&_this->m_Node.m_Scene, frame);
		IGV5Model_UpdateModelBoundingBox(&_this->m_Node, NULL);
	}
}

void M3DModel_AnimateCurrentOnce(M3DModel *_this, float _ElapsedTime)
{
	M3DAnimation *ani = NULL;
	float ElapsedTime = 0.0f;

	if (_this == NULL)
		return;

	if (_this->m_Stop == 1)
		return;

	ElapsedTime = (float) (_ElapsedTime * _this->m_TimeFactor);


	if (_this->m_bLoaded == 1)
	{
		float time = 0;
		float frame = 0.0f;

		ani = M3DModel_GetCurrentAnimation(_this);
		//RAY::2011-09-18
		if (ani->m_TimeFactor != 1.0f)
			ElapsedTime = (float) (_ElapsedTime * ani->m_TimeFactor);

		_this->m_Time += ElapsedTime;

		if (_this->m_Time > ani->m_Duration)
		{
			_this->m_Time = 0;
			_this->m_iCurrentAnimation = _this->m_iDefaultAnimation;
			_this->m_CurrentAnimationName = NULL;
			_this->m_Stop = 1;
		}
		ani = M3DModel_GetCurrentAnimation(_this);
		time = ani->m_Start + _this->m_Time;
		frame = (float) time * 30.0f / 1000.0f;
		IGV5PODModel_SetFrame(&_this->m_Node.m_Scene, frame);
		IGV5Model_UpdateModelBoundingBox(&_this->m_Node, NULL);
	}
}

//RAY::2011-10-24 可以倒撥, 目前只有 M3DModel_AnimateCurrentOnceAndPause 支援
void M3DModel_AnimateCurrentOnceAndPause(M3DModel *_this, float _ElapsedTime)
{
	M3DAnimation *ani = NULL;
	float ElapsedTime = 0.0f;

	if (_this == NULL)
		return;

	if (_this->m_Stop == 1)
		return;

		ElapsedTime = (float) (_ElapsedTime * _this->m_TimeFactor);

	if (_this->m_bLoaded == 1)
	{
		float time = 0;
		float frame = 0.0f;

		ani = M3DModel_GetCurrentAnimation(_this);
		//RAY::2011-09-18
		if (ani->m_TimeFactor != 1.0f)
			ElapsedTime = (float) (_ElapsedTime * ani->m_TimeFactor);

		if (ani->m_Start < ani->m_End)
		{
			_this->m_Time += ElapsedTime;

			if (_this->m_Time > ani->m_Duration)
			{
				_this->m_Time = ani->m_Duration - 1.0f;
				_this->m_Stop = 1;
			}
		}
		else
		{
			_this->m_Time -= ElapsedTime;

			if (_this->m_Time < ani->m_Duration)
			{
				_this->m_Time = ani->m_Duration + 1.0f;
				_this->m_Stop = 1;
			}
		}

		ani = M3DModel_GetCurrentAnimation(_this);
		time = ani->m_Start + _this->m_Time;
		frame = (float) time * 30.0f / 1000.0f;
		IGV5PODModel_SetFrame(&_this->m_Node.m_Scene, frame);
		IGV5Model_UpdateModelBoundingBox(&_this->m_Node, NULL);
	}
}

void M3DModel_SetAnimationPercent(M3DModel *_this, int _iAnimation, float _percent)
{
	M3DAnimation *ani = NULL;

	if (_this == NULL)
		return;

	if (_this->m_bLoaded == 1)
	{
		float time = 0;
		float frame = 0.0f;

		_this->m_iCurrentAnimation = _iAnimation;
		_this->m_CurrentAnimationName = NULL;
		ani = M3DModel_GetCurrentAnimation(_this);

		_this->m_Time = ani->m_Duration * _percent;
		_this->m_Stop = 1;

		time = ani->m_Start + _this->m_Time;
		frame = (float) time * 30.0f / 1000.0f;
		IGV5PODModel_SetFrame(&_this->m_Node.m_Scene, frame);
		IGV5Model_UpdateModelBoundingBox(&_this->m_Node, NULL);
	}
}

void M3DModel_Update(M3DModel *_this, float _fFrameTime)
{
	if (_this == NULL)
		return;

	IGV5Model_Update(&_this->m_rr->m_EngineRC, &_this->m_Node, _fFrameTime, NULL);
}

void M3DModel_SetPosition(M3DModel *_this, float _x, float _y, float _z)
{
	if (_this == NULL)
		return;

	IGV5Model_SetNodePositionByName(&_this->m_Node, _this->m_Name, _x, _y, _z);
}

void M3DModel_SetNodeBeside(M3DModel *_this, char *_name, M3DModel *_beside, char *_beside_name, int _range)
{
	Vec3 pos;
	int range, sign;

	if (_this == NULL)
		return;

	if (_this->m_bLoaded == 0 || _beside->m_bLoaded == 0)
		return;

	if (_range > 0)
	{
		sign = 1;
		range = _range;
	}
	else
	{
		sign = -1;
		range = -_range;
	}
	IGV5Model_GetNodeWorldPosByName(&_beside->m_Node, _beside_name, &pos);
	pos.x += (float) (sign * (m3d_adaption_rand() % range));
	pos.y += (float) (sign * (m3d_adaption_rand() % range));
	pos.z += (float) (sign * (m3d_adaption_rand() % range));

	IGV5Model_SetNodePositionByName(&_this->m_Node, _name, pos.x, pos.y, pos.z);
}

void M3DModel_SetNodePosition(M3DModel *_this, char *_name, CVector3f *_position)
{
	if (_this == NULL)
		return;

	IGV5Model_SetNodePositionByName(&_this->m_Node, _name, _position->x, _position->y, _position->z);
}

void M3DModel_GetNodePosition(M3DModel *_this, char *_name, CVector3f *_position)
{
	if (_this == NULL)
		return;

	IGV5Model_GetNodeWorldPosByName(&_this->m_Node, _name, (Vec3 *)_position);
}

void M3DModel_SetNodeScale(M3DModel *_this, char *_name, CVector3f *_scale)
{
	if (_this == NULL)
		return;

	IGV5Model_SetNodeScaleByName(&_this->m_Node, _name, _scale->x, _scale->y, _scale->z);
}

void M3DModel_SetNodeZRotation(M3DModel *_this, char *_name, float _degree)
{
	if (_this == NULL)
		return;

	IGV5Model_SetNodeRotationByName(&_this->m_Node, _name, 0.0f, 0.0f, _degree);
}

void M3DModel_SetNodeYRotation(M3DModel *_this, char *_name, float _degree)
{
	if (_this == NULL)
		return;

	IGV5Model_SetNodeRotationByName(&_this->m_Node, _name, 0.0f, _degree, 0.0f);
}

void M3DModel_SetNodeXRotation(M3DModel *_this, char *_name, float _degree)
{
	if (_this == NULL)
		return;

	IGV5Model_SetNodeRotationByName(&_this->m_Node, _name, _degree, 0.0f, 0.0f);
}

void M3DModel_FaceToCameraByXZ(M3DModel *_this, char *_node_name)
{
	Vec3 pos;
	Vec3 to;

	if (_this == NULL)
		return;

	if (_this->m_bLoaded == 0)
		return;

	//RAY::2011-10-03 y 必須對齊, 才不會歪掉
	IGV5Model_GetNodeWorldPosByName(&_this->m_Node, _node_name, &pos);
	to.x = _this->m_rr->m_CameraInfoCurrent.m_From.x;
	to.y = pos.y;
	to.z = _this->m_rr->m_CameraInfoCurrent.m_From.z;
	IGV5Model_SetNodeFaceToByName(&_this->m_Node, _node_name, &to);
}

void M3DModel_FaceToCamera(M3DModel *_this, char *_node_name)
{
	Vec3 to;

	if (_this == NULL)
		return;

	if (_this->m_bLoaded == 0)
		return;

	to.x = _this->m_rr->m_CameraInfoCurrent.m_From.x;
	to.y = _this->m_rr->m_CameraInfoCurrent.m_From.y;
	to.z = _this->m_rr->m_CameraInfoCurrent.m_From.z;
	IGV5Model_SetNodeFaceToByName(&_this->m_Node, _node_name, &to);
}

void M3DModel_SetPassID(M3DModel *_this, char *_node_name, int _iPassId)
{
	int idx = -1;
	
	if (_this == NULL)
		return;

	idx = IGV5Model_FindNodeIdxByName(&_this->m_Node, _node_name);
	_this->m_Node.m_Scene.m_POD.pMesh[idx].m_uPassID = _iPassId;
}

void M3DModel_EnableNode(M3DModel *_this, char *_node_name, int _bEnable)
{
	if (_this == NULL)
		return;

	if (_this->m_bLoaded == 0)
		return;
	IGV5Model_EnableNodeRenderingByName(&_this->m_Node, _node_name, _bEnable);
}

void M3DModel_EnableNodeByIndex(M3DModel *_this, int _index, int _bEnable)
{
	if (_this == NULL)
		return;

	if (_this->m_bLoaded == 0)
		return;
	IGV5Model_EnableNodeRendering(&_this->m_Node, (unsigned int) _index, _bEnable);
}

void M3DModel_EnableAllNode(M3DModel *_this, int _bEnable)
{
	unsigned int cn = 0;
	IGV5Model *pModel = NULL;

	if (_this == NULL)
		return;

	if (_this->m_bLoaded == 0)
		return;

	pModel = &_this->m_Node;
	for (cn = 0; cn < pModel->m_Scene.m_POD.nNumMesh; cn++)
	{
		IGV5Model_EnableNodeRendering(pModel, cn, _bEnable);
	}
}

void M3DModel_SetMaterialOpacity(M3DModel *_this, float _fOpacity)
{
	unsigned cn = 0;

	if (_this == NULL)
		return;

	for(cn = 0; cn < _this->m_Node.m_Scene.m_POD.nNumMeshNode; cn++){
		_this->m_Node.m_Scene.m_POD.pMaterial[_this->m_Node.m_Scene.m_POD.pNode[cn].nIdxMaterial].fMatOpacity = _fOpacity;
	}
}

void M3DModel_Render(M3DModel *_this)
{
	if (_this == NULL)
		return;

	if (_this->m_bLoaded == 0)
		return;

	IGV5Model_RenderWithCamera(&_this->m_Node, &_this->m_rr->m_Light, &_this->m_rr->m_Camera, NULL, 0);
}

void M3DModel_RenderWithShadow(M3DModel *_this)
{
	IGV5Model *pModel = NULL;

	if (_this == NULL)
		return;

	if (_this->m_bLoaded == 0)
		return;

	pModel = &_this->m_Node;

#if defined(M3D_ENABLE_SHADOW)
	IGV5Model_RenderFromCameraWithShadow(pModel, &_this->m_rr->m_Light, &_this->m_rr->m_Camera, NULL, _this->m_rr->m_ShadowInfoPtr, 0);
#else
	IGV5Model_RenderWithCamera(&_this->m_Node, &_this->m_rr->m_Light, &_this->m_rr->m_Camera, NULL, 0);
#endif
}

int  M3DModel_Pick(M3DModel *_this, int *_Picked, int _x, int _y)
{
	int nPicked = 0;
	Vec2 HitPoint;

	if (_this == NULL)
		return 0;

	if (_this->m_bLoaded == 0)
		return nPicked;

	HitPoint.x = (float) _x;
	HitPoint.y = (float) _y;

	IGV5Model_CalcScreenBBox(&_this->m_rr->m_EngineRC, &_this->m_Node, &_this->m_rr->m_Camera);
	IGV5Model_Pick(&_this->m_Node, IGV5HitTestMode_Rough, &HitPoint, &nPicked, _Picked, 4);

	return nPicked;
}

char *M3DModel_PickNode(M3DModel *_this, int _x, int _y) {
	int Picked[16], nPicked, iPickedNodeIdx;
	Vec2 HitPoint;
	char *node_name = NULL;
	//float sx,sy;

	if (_this == NULL)
		return NULL;

	if (_this->m_bLoaded == 0)
		return node_name;

	HitPoint.x = (float) _x;
	HitPoint.y = (float) _y;

	IGV5Model_CalcScreenBBox(&_this->m_rr->m_EngineRC, &_this->m_Node, &_this->m_rr->m_Camera);
	IGV5Model_Pick(&_this->m_Node, IGV5HitTestMode_Rough, &HitPoint, &nPicked, Picked, 1);

	if (nPicked == 1) {
		iPickedNodeIdx = Picked[0];
		node_name = _this->m_Node.m_Scene.m_POD.pNode[iPickedNodeIdx].pszName;
	}

	return node_name;
}

char *M3DModel_PickLastNode(M3DModel *_this, int _x, int _y)
{
	int Picked[16], nPicked, iPickedNodeIdx;
	Vec2 HitPoint;
	char *node_name = NULL;
	//float sx,sy;

	if (_this == NULL)
		return NULL;

	if (_this->m_bLoaded == 0)
		return node_name;

	HitPoint.x = (float) _x;
	HitPoint.y = (float) _y;

	IGV5Model_CalcScreenBBox(&_this->m_rr->m_EngineRC, &_this->m_Node, &_this->m_rr->m_Camera);
	IGV5Model_Pick(&_this->m_Node, IGV5HitTestMode_Rough, &HitPoint, &nPicked, Picked, 4);

	if (nPicked > 0) {
		iPickedNodeIdx = Picked[nPicked-1];
		node_name = _this->m_Node.m_Scene.m_POD.pNode[iPickedNodeIdx].pszName;
	}

	return node_name;
}

char *M3DModel_PickNodeByNamePrefix(M3DModel *_this, int _x, int _y, char *_node_name_prefix)
{
	int cn = 0, len;
	int Picked[16], nPicked, iPickedNodeIdx;
	Vec2 HitPoint;
	char *node_name = NULL;
	//float sx,sy;

	if (_this == NULL)
		return NULL;

	if (_this->m_bLoaded == 0)
		return node_name;

	HitPoint.x = (float) _x;
	HitPoint.y = (float) _y;

	IGV5Model_CalcScreenBBox(&_this->m_rr->m_EngineRC, &_this->m_Node, &_this->m_rr->m_Camera);
	IGV5Model_Pick(&_this->m_Node, IGV5HitTestMode_Rough, &HitPoint, &nPicked, Picked, 4);

	len = strlen(_node_name_prefix);
	for (cn = 0; cn < nPicked; cn++)
	{
		iPickedNodeIdx = Picked[cn];
		if (strncmp(_this->m_Node.m_Scene.m_POD.pNode[iPickedNodeIdx].pszName, _node_name_prefix, len) == 0)
		{
			node_name = _this->m_Node.m_Scene.m_POD.pNode[iPickedNodeIdx].pszName;
			break;
		}
	}

	return node_name;
}

int M3DModel_PickNodeIndex(M3DModel *_this, int _x, int _y)
{
	int Picked[16], nPicked, iPickedNodeIdx = -1;
	Vec2 HitPoint;
	//float sx,sy;

	if (_this == NULL)
		return -1;

	if (_this->m_bLoaded == 0)
		return iPickedNodeIdx;

	HitPoint.x = (float) _x;
	HitPoint.y = (float) _y;

	IGV5Model_CalcScreenBBox(&_this->m_rr->m_EngineRC, &_this->m_Node, &_this->m_rr->m_Camera);
	IGV5Model_Pick(&_this->m_Node, IGV5HitTestMode_Rough, &HitPoint, &nPicked, Picked, 1);

	if (nPicked == 1) {
		iPickedNodeIdx = Picked[0];
	}

	return iPickedNodeIdx;
}

void M3DModel_ChangeSingleTexture(M3DModel *_this, char *_new_tex_name)
{
	IGV5Texture *pTex = NULL;

	if (_this == NULL)
		return;

	if (_this->m_bLoaded == 0)
		return;

	pTex = M3DTextureCollection_Get(&_this->m_rr->m_TextureCollection, _new_tex_name);

	if (pTex != NULL)
	{
		_this->m_Node.m_ppTextures[0] = pTex;
	}
}

void M3DModel_ChangeTexture(M3DModel *_this, char *_old_tex_name, char *_new_tex_name)
{
	IGV5Texture *pNewTex = NULL;
	unsigned int cn = 0;

	if (_this == NULL)
		return;

	if (_this->m_bLoaded == 0)
		return;

	pNewTex = M3DTextureCollection_Get(&_this->m_rr->m_TextureCollection, _new_tex_name);

	for (cn = 0; cn < _this->m_Node.m_Scene.m_POD.nNumTexture; cn++)
	{
		if (strcmp(_old_tex_name, _this->m_Node.m_Scene.m_POD.pTexture[cn].pszName) == 0)
		{
			_this->m_Node.m_ppTextures[cn] = pNewTex;
			break;
		}
	}
}

void M3DModel_Release(M3DModel *_this)
{
	if (_this == NULL)
		return;

	IGV5NameCache_Release(&_this->m_TexCache);
	if (_this->m_bLoaded != 0)
		IGV5Model_Unload(&_this->m_Node);
}

void M3DModel_Del(M3DModel *_this)
{
	if (_this == NULL)
		return;

	M3DModel_Release(_this);
	M3DMemory_Del(_this);
}

M3DNode *M3DNode_New(M3DModel *_model, char *_node_name)
{
	M3DNode *self = NULL;
	SPODNode *pNode = NULL;

	if (_model == NULL)
		return NULL;

	pNode = IGV5PODModel_FindNodeByName(&_model->m_Node.m_Scene, _node_name);
	if (pNode == NULL)
		return NULL;

	self = M3DMemory_New(sizeof(M3DNode));
	M3DMemory_Set((void *) self, sizeof(M3DNode), 0);
	strcpy(self->m_Name, _node_name);
	self->m_Model = _model;
	self->m_Time = 0L;
	self->m_Stop = 1;
	self->m_ParentNodeIndex = -1;
	IGV5PODModel_EnableNodeAnimationByName(&_model->m_Node.m_Scene, _node_name, 1);
	IGV5PODModel_EnableNodeRenderingByName(&_model->m_Node.m_Scene, _node_name, 1);

	return self;
}

M3DNode *M3DNode_NewBone(M3DModel *_model, char *_node_name)
{
	M3DNode *self = NULL;
	
	if (_model == NULL)
		return NULL;

	self = M3DNode_New(_model, _node_name);
	self->m_IsBone = 1;
	return self;
}

M3DNode *M3DNode_NewParent(M3DModel *_model, char *_parent_node_name)
{
	M3DNode *self = NULL;
	SPODNode *pNode = NULL;

	if (_model == NULL)
		return NULL;

	pNode = IGV5PODModel_FindNodeByName(&_model->m_Node.m_Scene, _parent_node_name);
	if (pNode == NULL)
		return NULL;

	self = M3DMemory_New(sizeof(M3DNode));
	M3DMemory_Set((void *) self, sizeof(M3DNode), 0);

	M3DNode_InitParent(self, _model, _parent_node_name);
	return self;
}

int  M3DNode_IsChild(M3DNode *_this, char *_child_node_name)
{
	int ret = 0;
	int cn = 0;
	int index = -1;
	
	if (_this == NULL)
		return 0;

	index = IGV5PODModel_FindNodeIdxByName(&_this->m_Model->m_Node.m_Scene, _child_node_name);

	for (cn = 0; cn < _this->m_iChildNode; cn++)
	{
		if (_this->m_ChildNodeIndex[cn] == index)
			ret = 1;
		break;
	}

	return ret;
}

void M3DNode_Del(M3DNode *_this)
{
	if (_this == NULL)
		return;

	M3DMemory_Del(_this);
}

void M3DNode_Init(M3DNode *_this, M3DModel *_model, char *_node_name)
{
	SPODNode *pNode = NULL;
	
	if (_this == NULL)
		return;

	pNode = IGV5PODModel_FindNodeByName(&_model->m_Node.m_Scene, _node_name);
	if (pNode == NULL)
		return;

	strcpy(_this->m_Name, _node_name);
	_this->m_Model = _model;
	_this->m_Time = 0L;
	_this->m_Stop = 1;
	_this->m_ParentNodeIndex = -1;
	_this->m_iChildNode = 0;

	IGV5PODModel_EnableNodeAnimationByName(&_model->m_Node.m_Scene, _node_name, 1);
	IGV5PODModel_EnableNodeRenderingByName(&_model->m_Node.m_Scene, _node_name, 1);
}

void M3DNode_InitParent(M3DNode *_this, M3DModel *_model, char *_parent_node_name)
{
	unsigned int cn = 0, cn2;
	SPODNode *pNode = NULL;
	int iNodeIdx = -1;
	
	if (_this == NULL)
		return;

	pNode = IGV5PODModel_FindNodeByName(&_model->m_Node.m_Scene, _parent_node_name);
	if (pNode == NULL)
		return;

	iNodeIdx = IGV5PODModel_FindNodeIdxByName(&_model->m_Node.m_Scene, _parent_node_name);

	strcpy(_this->m_Name, _parent_node_name);
	_this->m_Model = _model;
	_this->m_Time = 0L;
	_this->m_Stop = 1;
	_this->m_ParentNodeIndex = iNodeIdx;
	_this->m_iChildNode = 0;
	//這邊要 enable 所有的 childs, 檢查兩層就好
	for (cn = 0; cn < _model->m_Node.m_Scene.m_POD.nNumNode; cn++)
	{
		if (iNodeIdx == _model->m_Node.m_Scene.m_POD.pNode[cn].nIdxParent)
		{
			_this->m_ChildNodeIndex[_this->m_iChildNode] = cn;
			_this->m_iChildNode++;
			IGV5PODModel_EnableNodeAnimationByName(&_model->m_Node.m_Scene, _model->m_Node.m_Scene.m_POD.pNode[cn].pszName, 1);
			IGV5PODModel_EnableNodeRenderingByName(&_model->m_Node.m_Scene, _model->m_Node.m_Scene.m_POD.pNode[cn].pszName, 1);

			for (cn2 = 0; cn2 < _model->m_Node.m_Scene.m_POD.nNumNode; cn2++)
			{
				if (cn == _model->m_Node.m_Scene.m_POD.pNode[cn2].nIdxParent)
				{
					_this->m_ChildNodeIndex[_this->m_iChildNode] = cn2;
					_this->m_iChildNode++;
					IGV5PODModel_EnableNodeAnimationByName(&_model->m_Node.m_Scene, _model->m_Node.m_Scene.m_POD.pNode[cn2].pszName, 1);
					IGV5PODModel_EnableNodeRenderingByName(&_model->m_Node.m_Scene, _model->m_Node.m_Scene.m_POD.pNode[cn2].pszName, 1);
				}
			}
		}
	}
}

void M3DNode_ResetTime(M3DNode *_this)
{
	if (_this == NULL)
		return;

	_this->m_Time = 0L;
	_this->m_Stop = 1;
}

void M3DNode_SetTime(M3DNode *_this, float _Time)
{
	if (_this == NULL)
		return;

	_this->m_Time = _Time;
}

void M3DNode_AnimateLoop(M3DNode *_this, float _ElapsedTime)
{
	float ElapsedTime = 0L;
	float frame = 0.0f;
	IGV5PODModel *pModel = NULL;

	if (_this == NULL)
		return;

	if (_this->m_Model == NULL)
		return;

	ElapsedTime = (float) (_ElapsedTime * _this->m_Model->m_TimeFactor);
	pModel = &(_this->m_Model->m_Node.m_Scene);

	_this->m_Time += ElapsedTime;
	if (_this->m_Time >= _this->m_Model->m_AnimationLength)
		_this->m_Time -= _this->m_Model->m_AnimationLength;

	frame = (float) _this->m_Time * 30.0f / 1000.0f;

	IGV5PODModel_EnableNodeAnimationByName(pModel, _this->m_Name, 1);
	IGV5PODModel_SetNodeAnimationFrameByName(pModel, _this->m_Name, frame);
	IGV5Model_UpdateModelBoundingBox(&_this->m_Model->m_Node, NULL);
}

void M3DNode_AnimateStart(M3DNode *_this, float _Time)
{
	if (_this == NULL)
		return;

	_this->m_Time = _Time;
	_this->m_Stop = 0;
}

void M3DNode_AnimateOnce(M3DNode *_this, float _ElapsedTime)
{
	float ElapsedTime = 0.0f;
	float frame = 0.0f;
	IGV5PODModel *pModel = NULL;

	if (_this == NULL || _this->m_Model->m_bLoaded == 0)
		return;
	if (_this->m_Stop == 1)
		return;

	pModel = &(_this->m_Model->m_Node.m_Scene);
	ElapsedTime = (float) (_ElapsedTime * _this->m_Model->m_TimeFactor);

	if (_this->m_Time + ElapsedTime < _this->m_Model->m_AnimationLength)
		_this->m_Time += ElapsedTime;
	else
		_this->m_Stop = 1;
	frame = (float) _this->m_Time * 30.0f / 1000.0f;

	IGV5PODModel_EnableNodeAnimationByName(pModel, _this->m_Name, 1);
	if (_this->m_IsBone == 0)
		IGV5PODModel_SetNodeAnimationFrameByName(pModel, _this->m_Name, frame);
	else
		IGV5Model_SetMeshNodeBoneAnimationFrameByName(&_this->m_Model->m_Node, _this->m_Name, frame);

	IGV5Model_UpdateModelBoundingBox(&_this->m_Model->m_Node, NULL);
}

void M3DNode_AnimateChildsOnce(M3DNode *_this, float _ElapsedTime)
{
	int cn = 0;
	float ElapsedTime = 0.0f;
	float frame = 0.0f;

	if (_this == NULL || _this->m_Model->m_bLoaded == 0)
		return;
	if (_this->m_Stop == 1)
		return;

	ElapsedTime = (float) (_ElapsedTime * _this->m_Model->m_TimeFactor);

	if (_this->m_Time + ElapsedTime < _this->m_Model->m_AnimationLength)
		_this->m_Time += ElapsedTime;
	else
		_this->m_Stop = 1;
	frame = (float) _this->m_Time * 30.0f / 1000.0f;

	/*
	for (cn = 0; cn < _this->m_Model->m_Node.m_Scene.m_POD.nNumNode; cn++)
	{
		if (_this->m_ParentNodeIndex == _this->m_Model->m_Node.m_Scene.m_POD.pNode[cn].nIdxParent)
		{
			IGV5PODModel_EnableNodeAnimationByName(&_this->m_Model->m_Node.m_Scene, _this->m_Model->m_Node.m_Scene.m_POD.pNode[cn].pszName, 1);
			IGV5PODModel_SetNodeAnimationFrameByName(&_this->m_Model->m_Node.m_Scene, _this->m_Model->m_Node.m_Scene.m_POD.pNode[cn].pszName, frame);
		}
	}
	*/

	for (cn = 0; cn < _this->m_iChildNode; cn++)
	{
		int idx = _this->m_ChildNodeIndex[cn];
		IGV5PODModel_EnableNodeAnimationByName(&_this->m_Model->m_Node.m_Scene, _this->m_Model->m_Node.m_Scene.m_POD.pNode[idx].pszName, 1);
		IGV5PODModel_SetNodeAnimationFrameByName(&_this->m_Model->m_Node.m_Scene, _this->m_Model->m_Node.m_Scene.m_POD.pNode[idx].pszName, frame);
	}

	IGV5Model_UpdateModelBoundingBox(&_this->m_Model->m_Node, NULL);
}

void M3DNode_SetAnimationStart(M3DNode *_this, int _iAnimation)
{
	if (_this == NULL)
		return;

	if (_this->m_Model->m_bLoaded == 0)
		return;

	_this->m_iCurrentAnimation = _iAnimation;
	_this->m_Time = 0;
	_this->m_Stop = 0;
}

void M3DNode_AnimateCurrentOnce(M3DNode *_this, float _ElapsedTime)
{
	M3DAnimation *ani = NULL;
	float ElapsedTime = 0.0f;
	float time = 0;
	float frame = 0.0f;
	IGV5PODModel *pModel = NULL;

	if (_this == NULL || _this->m_Model->m_bLoaded == 0)
		return;
	if (_this->m_Stop == 1)
		return;

	pModel = &(_this->m_Model->m_Node.m_Scene);
	ElapsedTime = (float) (_ElapsedTime * _this->m_Model->m_TimeFactor);

	ani = M3DModel_GetCurrentAnimation(_this->m_Model);
	if (ani->m_TimeFactor != 1.0f)
		ElapsedTime = (float) (_ElapsedTime * ani->m_TimeFactor);

	_this->m_Time += ElapsedTime;

	if (_this->m_Time > ani->m_Duration)
	{
		_this->m_Time = 0;
		_this->m_iCurrentAnimation = _this->m_Model->m_iDefaultAnimation;
		_this->m_Stop = 1;
	}
	ani = M3DModel_GetCurrentAnimation(_this->m_Model);
	time = ani->m_Start + _this->m_Time;
	frame = (float) time * 30.0f / 1000.0f;

	IGV5PODModel_EnableNodeAnimationByName(pModel, _this->m_Name, 1);
	if (_this->m_IsBone == 0)
		IGV5PODModel_SetNodeAnimationFrameByName(pModel, _this->m_Name, frame);
	else
		IGV5Model_SetMeshNodeBoneAnimationFrameByName(&_this->m_Model->m_Node, _this->m_Name, frame);

	IGV5Model_UpdateModelBoundingBox(&_this->m_Model->m_Node, NULL);
}

void M3DNode_AnimateChildCurrentOnce(M3DNode *_this, float _ElapsedTime)
{
	M3DAnimation *ani = NULL;
	float ElapsedTime = 0.0f;
	float time = 0;
	float frame = 0.0f;
	IGV5PODModel *pModel = NULL;
	int cn = 0;

	if (_this == NULL || _this->m_Model->m_bLoaded == 0)
		return;
	if (_this->m_Stop == 1)
		return;

	pModel = &(_this->m_Model->m_Node.m_Scene);
	ElapsedTime = (float) (_ElapsedTime * _this->m_Model->m_TimeFactor);

	ani = M3DModel_GetCurrentAnimation(_this->m_Model);
	if (ani->m_TimeFactor != 1.0f)
		ElapsedTime = (float) (_ElapsedTime * ani->m_TimeFactor);

	_this->m_Time += ElapsedTime;

	if (_this->m_Time > ani->m_Duration)
	{
		_this->m_Time = 0;
		_this->m_iCurrentAnimation = _this->m_Model->m_iDefaultAnimation;
		_this->m_Stop = 1;
	}
	ani = M3DModel_GetCurrentAnimation(_this->m_Model);
	time = ani->m_Start + _this->m_Time;
	frame = (float) time * 30.0f / 1000.0f;

	IGV5PODModel_EnableNodeAnimationByName(pModel, _this->m_Name, 1);
	IGV5PODModel_SetNodeAnimationFrameByName(pModel, _this->m_Name, frame);
	for (cn = 0; cn < _this->m_iChildNode; cn++)
	{
		int idx = _this->m_ChildNodeIndex[cn];
		IGV5PODModel_EnableNodeAnimationByName(&_this->m_Model->m_Node.m_Scene, _this->m_Model->m_Node.m_Scene.m_POD.pNode[idx].pszName, 1);
		IGV5PODModel_SetNodeAnimationFrameByName(&_this->m_Model->m_Node.m_Scene, _this->m_Model->m_Node.m_Scene.m_POD.pNode[idx].pszName, frame);
	}

	IGV5Model_UpdateModelBoundingBox(&_this->m_Model->m_Node, NULL);
}

//Shadow and Reflection
void M3DModel_SetShaderProgram(M3DModel *_this, int _iModelShader, int _iSkinningShader)
{
	ShaderProgram *pModelShader = NULL;
	ShaderProgram *pSkinningShader = NULL;

	if (_this == NULL)
		return;

	if (_iModelShader != M3D_NULL_SHADER)
		pModelShader = M3DRenderer_GetShader(_this->m_rr, _iModelShader);
	if (_iSkinningShader != M3D_NULL_SHADER)
		pSkinningShader = M3DRenderer_GetShader(_this->m_rr, _iSkinningShader);

	IGV5Model_SetShaderProgramForAllNode(&_this->m_Node, pModelShader, pSkinningShader);
}

void M3DModel_SetShaderProgramByNodeName(M3DModel *_this, char *pNodeName, int _iShader)
{
	ShaderProgram *pShader = NULL;
	int iNodeIndex = -1;
	
	if (_this == NULL)
		return;

	iNodeIndex = IGV5Model_FindNodeIdxByName(&_this->m_Node, pNodeName);

	if (_iShader != M3D_NULL_SHADER && iNodeIndex >= 0)
	{
		pShader = M3DRenderer_GetShader(_this->m_rr, _iShader);
		IGV5Model_SetShaderProgram(&_this->m_Node, iNodeIndex, pShader);
	}
}

void M3DModel_SetShadow(M3DModel *_this)
{
	if (_this == NULL)
		return;

	M3DRenderer_AddShadowModel(_this->m_rr, &_this->m_Node);
}

void M3DModel_InitReflector(M3DModel *_this, char *_node_name, float reflectorOpacity)
{
	if (_this == NULL)
		return;

	M3DRenderer_InitReflection(_this->m_rr, &_this->m_Node, _node_name, reflectorOpacity);
}

void M3DModel_SetReflection(M3DModel *_this)
{
	if (_this == NULL)
		return;

	M3DRenderer_AddReflectionModel(_this->m_rr, &_this->m_Node);
}

#ifdef __cplusplus
}
#endif
