//==============================================================================
// Copyright (c)2005 InterGrafx, Inc. All rights reserved.
// Project     : M3D_LW_Lib
// File        : M3DRenderer.c
// Description : M3D 桌布公用程式
// Author      : Ray
// Create      : 2011-05-31
// Update      : 2010-06-03
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "M3DRenderer.h"
#include "M3DGameDef.h"

#include "m3d_adaption.h"
#include "M3DMemory.h"
#include "M3DDummyGroup.h"

#ifdef __cplusplus
extern "C" {
#endif

//extern unsigned char const png_m3d_red[];
//extern long png_m3d_red_length;

M3DDummyGroup *M3DDummyGroup_New(M3DRenderer *_rr)
{
	M3DDummyGroup *self = NULL;

	if (_rr == NULL)
		return NULL;

	self = M3DMemory_New(sizeof(M3DDummyGroup));
	M3DMemory_Set((void *) self, sizeof(M3DDummyGroup), 0);
	self->m_rr = _rr;

	return self;
}

void M3DDummyGroup_Del(M3DDummyGroup *_this)
{
	if (_this == NULL)
		return;

	if (_this->m_Model != NULL)
	{
		M3DModel_Del(_this->m_Model);
		_this->m_Model = NULL;
	}
	M3DMemory_Del(_this);
}

void M3DDummyGroup_Load(M3DDummyGroup *_this, unsigned char const *_data, long _data_length, char *_dummy_names)
{
	if (_this == NULL)
		return;

	_this->m_Model = M3DModel_New(_this->m_rr, "");
	M3DModel_Load(_this->m_Model, _data, _data_length, NULL);
	M3DSplitString_Init(&_this->m_DummyNames, _dummy_names);
	_this->m_iTotalDummy = M3DSplitString_GetCount(&_this->m_DummyNames);
}

void M3DDummyGroup_SetType(M3DDummyGroup *_this, int _type)
{
	_this->m_type = _type;
}

/*
void M3DDummyGroup_ReplaceTexture(M3DDummyGroup *_this, unsigned char *_data, long _data_length)
{
	IGM3GErr err;
	IGM3GTexture2D *tex = M3DRenderer_LoadTextureFromArray(_this->m_rr, _data, _data_length);
	int cn;

	//for (cn = 0; cn < _this->m_iTotalDummy; cn++)
	for (cn = 0; cn < 1; cn++)
	{
		IGM3GMesh *pMesh = M3DRenderer_GetFirstMesh(_this->m_rr, _this->m_Dummy[cn]);
		IGM3GAppearance *pApp = M3DRenderer_GetMeshAppearance(_this->m_rr, pMesh, 0);

		if (pApp == NULL)
			continue;

		err = IGM3GAppearance_SetTexture(_this->m_rr->m_Mem, pApp, 0, tex);

		igSmartRelease(pApp);
		igSmartRelease(pMesh);
	}
}
*/
void M3DDummyGroup_AddStaticDummies(M3DDummyGroup *_this, M3DModel *_model, char *_node_name_prefix)
{
	int cn = 0;
	int iTotalNode = _model->m_Node.m_Scene.m_POD.nNumNode;
	int iLength = strlen(_node_name_prefix);
	int iFound = 0;

	if (_this == NULL)
		return;

	for (cn = 0; cn < iTotalNode; cn++)
	{
		if (strncmp(_model->m_Node.m_Scene.m_POD.pNode[cn].pszName, _node_name_prefix, iLength) == 0)
		{
			M3DModel_GetNodePosition(_model, _model->m_Node.m_Scene.m_POD.pNode[cn].pszName, &_this->m_DummyMeshPosition[iFound]);
			iFound++;
		}
	}
	_this->m_iTotalDummy = iFound;
	_this->m_Model = NULL;
}

void M3DDummyGroup_AddObject(M3DDummyGroup *_this, M3DModel *_model, char *_node_name)
{
	if (_this == NULL)
		return;

	if (_this->m_iTotalObject < M3D_DEFAULT_DUMMY_GROUP_OBJECT_SLOT)
	{
		M3DNode_Init(&_this->m_Object[_this->m_iTotalObject], _model, _node_name);
		_this->m_ObjectDummy[_this->m_iTotalObject] = -1;
		_this->m_iTotalObject++;
	}
}

void M3DDummyGroup_Attach(M3DDummyGroup *_this, int _dummy_idx, int _object_idx)
{
	char dummy_name[128];
	//if (_dummy_idx >= _this->m_iTotalDummy || _object_idx >= _this->m_iTotalObject || _this->m_Dummy[_dummy_idx] == NULL || _this->m_Object[_object_idx] == NULL || _this->m_Object[_object_idx]->m_Node == NULL)
	//	return;

	if (_this == NULL)
		return;

	M3DSplitString_GetAt(&_this->m_DummyNames, dummy_name, _dummy_idx);
	_this->m_ObjectDummy[_object_idx] = _dummy_idx;
}

//RAY::2011-08-29 move to next dummy
void M3DDummyGroup_AttachNext(M3DDummyGroup *_this, int _object_idx)
{
	if (_this == NULL)
		return;

	_this->m_ObjectDummy[_object_idx]++;
	_this->m_ObjectDummy[_object_idx] %= _this->m_iTotalDummy;
}

void M3DDummyGroup_AnimateStart(M3DDummyGroup *_this, int _object_idx)
{
	if (_this == NULL)
		return;

	_this->m_ObjectDummy[_object_idx] = m3d_adaption_rand() % _this->m_iTotalDummy;
	_this->m_ObjectTime[_object_idx] = 0L;
}

void M3DDummyGroup_AnimateOnce(M3DDummyGroup *_this, int _object_idx, float _ElapsedTime)
{
	char dummy_name[128];
	CVector3f pos;

	if (_this == NULL)
		return;

	if (_this->m_Object[_object_idx].m_Model == NULL || _this->m_ObjectDummy[_object_idx] == -1)
		return;

	M3DModel_AnimateOnce(_this->m_Object[_object_idx].m_Model, _ElapsedTime);
	if (_this->m_Object[_object_idx].m_Model->m_Stop == 1)
	{
		_this->m_ObjectDummy[_object_idx] = -1;
		_this->m_ObjectTime[_object_idx] = 0L;
	}

	if (_this->m_Model != NULL)
	{
		M3DSplitString_GetAt(&_this->m_DummyNames, dummy_name, _this->m_ObjectDummy[_object_idx]);
		M3DModel_AnimateLoop(_this->m_Model, _ElapsedTime, 0);
		M3DModel_GetNodePosition(_this->m_Model, dummy_name, &pos);
		M3DModel_SetNodePosition(_this->m_Object[_object_idx].m_Model, _this->m_Object[_object_idx].m_Name, &pos);
	}
	else
	{
		M3DModel_SetNodePosition(_this->m_Object[_object_idx].m_Model, _this->m_Object[_object_idx].m_Name, &_this->m_DummyMeshPosition[_this->m_ObjectDummy[_object_idx]]);
	}
}

/*
void M3DDummyGroup_AnimateNormal(M3DDummyGroup *_this, float _GameTime)
{
	int inteval;

	if (_this->m_bLoaded == 0)
		return;

	if (_this->m_Group != NULL)
	{
		mM3gErr = IGM3GNode_Animate(_this->m_rr->m_Mem, (IGM3GNode *) _this->m_Group, _GameTime % _this->m_AnimationLength, &inteval);
	}
}
*/

void M3DDummyGroup_Animate(M3DDummyGroup *_this, float _ElapsedTime)
{
	int iChangeTo;
	CVector3f pos;
	char dummy_name[128];
	int _object_idx = 0;

	if (_this == NULL)
		return;

	if (_this->m_iTotalObject == 0 || _this->m_iTotalDummy == 0 || _object_idx < 0 || _object_idx >= _this->m_iTotalObject)
		return;

	_this->m_ObjectTime[_object_idx] += (_ElapsedTime * _this->m_Object[_object_idx].m_Model->m_TimeFactor);
	switch (_this->m_type)
	{
		case M3D_DUMMY_GROUP_TYPE_RANDOM_BY_OBJECT :
			if (_this->m_ObjectTime[_object_idx] > _this->m_Object[_object_idx].m_Model->m_AnimationLength)
			{
				iChangeTo = m3d_adaption_rand() % _this->m_iTotalDummy;
				M3DDummyGroup_Attach(_this, iChangeTo, _object_idx);
				//_this->m_ObjectTime[_object_idx] -= _this->m_Object[_object_idx].m_Model->m_AnimationLength;
				_this->m_ObjectTime[_object_idx]  = 0;
			}
			break;
		case M3D_DUMMY_GROUP_TYPE_RANDOM_BY_DUMMY:
			if (_this->m_Model->m_Time > _this->m_Model->m_AnimationLength)
			{
				iChangeTo = m3d_adaption_rand() % _this->m_iTotalDummy;
				M3DDummyGroup_Attach(_this, iChangeTo, _object_idx);
				_this->m_Model->m_Time = 0;
			}
			break;
	}

	if (_this->m_Model != NULL)
	{
		M3DSplitString_GetAt(&_this->m_DummyNames, dummy_name, _this->m_ObjectDummy[_object_idx]);
		M3DModel_AnimateLoop(_this->m_Model, _ElapsedTime, 0);
		M3DModel_GetNodePosition(_this->m_Model, dummy_name, &pos);
		M3DModel_SetNodePosition(_this->m_Object[_object_idx].m_Model, _this->m_Object[_object_idx].m_Name, &pos);
	}
	else
	{
		M3DModel_SetNodePosition(_this->m_Object[_object_idx].m_Model, _this->m_Object[_object_idx].m_Name, &_this->m_DummyMeshPosition[_this->m_ObjectDummy[_object_idx]]);
	}
}

void M3DDummyGroup_Animate2(M3DDummyGroup *_this, float _ElapsedTime)
{
	int cn = 0;
	CVector3f pos;
	char dummy_name[128];
	int _object_idx = 0;

	if (_this == NULL)
		return;

	if (_this->m_iTotalObject == 0 || _this->m_iTotalDummy == 0 || _object_idx < 0 || _object_idx >= _this->m_iTotalObject)
		return;

	_this->m_ObjectTime[_object_idx] += _ElapsedTime;
	if (_this->m_Model->m_Stop == 1)
	{
		for (cn = 0; cn < _this->m_iTotalObject; cn++)
		{
			M3DDummyGroup_AttachNext(_this, cn);
		}
		M3DModel_AnimateStart(_this->m_Model);
	}

	if (_this->m_Model != NULL)
	{
		M3DModel_AnimateOnce(_this->m_Model, _ElapsedTime);
		for (cn = 0; cn < _this->m_iTotalObject; cn++)
		{
			M3DSplitString_GetAt(&_this->m_DummyNames, dummy_name, _this->m_ObjectDummy[cn]);
			M3DModel_GetNodePosition(_this->m_Model, dummy_name, &pos);
			M3DModel_SetNodePosition(_this->m_Object[cn].m_Model, _this->m_Object[cn].m_Name, &pos);
		}
	}
}


#ifdef __cplusplus
}
#endif
