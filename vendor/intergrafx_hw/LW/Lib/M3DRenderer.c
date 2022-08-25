//============================================================================== 
// Copyright (c)2005 InterGrafx, Inc. All rights reserved.
// Project     : M3D_Lib
// File        : M3DRenderer.c
// Description : M3D 桌布公用程式 for IGV5
// Author      : Ray
// Create      : 2011-06-20
// Update      : 2010-12-15
//==============================================================================
#include <stdio.h>
#include <stdlib.h>
#include "IGV5RuntimeContext.h"
#include "IGV5Shader.h"
#include "IGV5Matrix.h"
#include "IGV5Texture.h"
#include "IGV5Renderer.h"
#include "IGV5Camera.h"
#include "IGV5Memory.h"
#include "IGV5LoadPODModel.h"
#include "IGV5LoadPODModel.h"
#include "IGV5Model.h"
#include "IGV5Font.h"

#include "M3DMemory.h"
#include "M3DRenderer.h"
#include "M3DGameDef.h"
#include "M3DPhysics.h"
#include "m3d_adaption.h"

#ifdef __cplusplus
extern "C" {
#endif

extern void M3DModel_InitStock(void);

void M3DCameraInfo_Copy(M3DCameraInfo *_this, M3DCameraInfo *_to)
{
	M3DMemory_Copy(_to, _this, sizeof(M3DCameraInfo));
}

int  M3DRenderer_Init(M3DRenderer *_this, void *_pConfig)
{
	M3DConfig *PC = (M3DConfig *)_pConfig;

	_this->m_InitInfo.m_pPoolPtr = PC->m_pMemBuffer;
	_this->m_InitInfo.uSize = PC->m_MemSize;
	_this->m_InitInfo.m_EGL.m_uWidth = PC->m_Width;
	_this->m_InitInfo.m_EGL.m_uHeight = PC->m_Height;
	_this->m_InitInfo.m_EGL.m_bUseDepthBuffer = IGV5_TRUE;
	_this->m_InitInfo.m_EGL.m_bUseStencilBuffer = IGV5_FALSE;

	if (_this->m_InitInfo.m_pPoolPtr == NULL)
		return 0;

	memset(&_this->m_EngineRC, 0, sizeof(IGV5RC));
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	if (IGV5Engine_Init(&_this->m_EngineRC, sizeof(IGV5InitInfoVer0101), &_this->m_InitInfo) != IGV5ERR_NONE)
#else
	if (IGV5Engine_InitForOwnerDraw(&_this->m_EngineRC, sizeof(IGV5InitInfoVer0101), &_this->m_InitInfo) != IGV5ERR_NONE)
#endif
		return 0;

	//_this->m_Scene = M3DMemory_New(sizeof(IGV5PODModel));
	//_this->m_SceneRoot = M3DMemory_New(sizeof(IGV5Node));
	_this->m_CameraInfo.m_ui32Camera = 0;
	_this->m_CameraInfo.m_Near = 0.1f;
	_this->m_CameraInfo.m_Far = 100000.0f;
	_this->m_CameraInfo.m_AspectRatio = (float)(_this->m_EngineRC.m_sEGLInfo.m_uWidth) / (float)(_this->m_EngineRC.m_sEGLInfo.m_uHeight);

	//IGV5Node_Create(_this->m_SceneRoot, "Root", NULL, NULL);

	M3DTextureCollection_Init(&_this->m_TextureCollection, (void *) _this);
	
	//M3DModel 有一些靜態的變數, 是用來 Callback 用的, 在 Init 的時候必須清空
	M3DModel_InitStock();

	//一開始要先設為 0, 才不會被其他 LW 影響
	M3DRenderer_EnableSpecular(_this, 0);

	IGV5Font_Create(_this->m_EngineRC.m_sEGLInfo.m_uWidth, _this->m_EngineRC.m_sEGLInfo.m_uHeight);

	_this->m_gouraudShader = NULL;
	_this->m_gouraudShadowShader = NULL;
	_this->m_skinningGouraudShader = NULL;
	_this->m_uvDisplacementShader = NULL;
	_this->m_textureShader = NULL;
	_this->m_skinningTextureShader = NULL;
	_this->m_textureNoAlphaShader = NULL;
	_this->m_skinningGouraudSpecularShader = NULL;

	_this->m_ReflectorModel = NULL;
	_this->m_ReflectorNodeName = NULL;
	_this->m_ShadowInfoPtr = NULL;
	_this->m_ReflectionInfoPtr = NULL;

	_this->m_GameTime = 0.0f;
	_this->m_iReflectionModel = 0;
	_this->m_iShadowModel = 0;

	return 1;
}

int  M3DRenderer_IsMemNull(M3DRenderer *_this)
{
	if (_this->m_InitInfo.m_pPoolPtr == NULL)
		return 1;
	else
		return 0;
}

void M3DRenderer_Del(M3DRenderer *_this)
{
	IGV5Font_Release();

	if (_this->m_gouraudShader != NULL)
	{
		M3DRenderer_ReleaseGouraudShader(_this);
		_this->m_gouraudShader = NULL;
	}
	if (_this->m_gouraudShadowShader != NULL)
	{
		M3DRenderer_ReleaseGouraudShadowShader(_this);
		_this->m_gouraudShadowShader = NULL;
	}
	if (_this->m_skinningGouraudShader != NULL)
	{
		M3DRenderer_ReleaseSkinningGouraudShader(_this);
		_this->m_skinningGouraudShader = NULL;
	}
	if (_this->m_uvDisplacementShader != NULL)
	{
		M3DRenderer_ReleaseUVDisplacementShader(_this);
		_this->m_uvDisplacementShader = NULL;
	}
	if (_this->m_textureShader != NULL)
	{
		M3DRenderer_ReleaseTextureShader(_this);
		_this->m_textureShader = NULL;
	}
	if (_this->m_skinningTextureShader != NULL)
	{
		M3DRenderer_ReleaseSkinningTextureShader(_this);
		_this->m_skinningTextureShader = NULL;
	}
	if (_this->m_textureNoAlphaShader != NULL)
	{
		M3DRenderer_ReleaseTextureNoAlphaShader(_this);
		_this->m_textureNoAlphaShader = NULL;
	}
	if (_this->m_gouraudSpecularShader != NULL)
	{
		M3DRenderer_ReleaseGouraudSpecularShader(_this);
		_this->m_gouraudSpecularShader = NULL;
	}
	if (_this->m_skinningGouraudSpecularShader != NULL)
	{
		M3DRenderer_ReleaseSkinningGouraudSpecularShader(_this);
		_this->m_skinningGouraudSpecularShader = NULL;
	}

	//M3DMemory_Del(_this->m_Scene);
	//_this->m_Scene = NULL;
	//M3DMemory_Del(_this->m_SceneRoot);
	//_this->m_SceneRoot = NULL;
	_this->m_GameTime = 0.0f;
	_this->m_iReflectionModel = 0;
	_this->m_iShadowModel = 0;

	M3DTextureCollection_Release(&_this->m_TextureCollection);

#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	IGV5Engine_Shutdown(&_this->m_EngineRC);
#else
	IGV5Engine_ShutdownForOwnerDraw(&_this->m_EngineRC);
#endif
	M3DMemory_Set(_this, sizeof(M3DRenderer), 0);
	_this->m_InitInfo.m_pPoolPtr = NULL;
}

unsigned M3DRenderer_GetUsedMemory(M3DRenderer *_this)
{
	if (_this->m_EngineRC.m_pMemPool == NULL)
		return 0;
	else
		return IGV5Memory_GetUsed(_this->m_EngineRC.m_pMemPool);
}

void M3DRenderer_LoadModel(M3DRenderer *_this, char *_path, char *_filename, char *_textures)
{
}

void M3DRenderer_LoadFromFile(M3DRenderer *_this, IGV5Model *_pModel, char *_filename)
{
}

void M3DRenderer_SetLookAt(M3DRenderer *_this, float _posX, float _posY, float _posZ, float _lookX, float _lookY, float _lookZ, float _upX, float _upY, float _upZ)
{
	Vec3 vFrom, vTo, vUp;

	CVector3f_Init((CVector3f *) &vFrom, _posX, _posY, _posZ);
	CVector3f_Init((CVector3f *) &vTo, _lookX, _lookY, _lookZ);
	CVector3f_Init((CVector3f *) &vUp, _upX, _upY, _upZ);
}

float FloatMod(float _num1, float _num2)
{
	int num = (int) (_num1 / _num2);
	float ret = _num1 - (float) num*_num2;

	return ret;
}

void M3DRenderer_SetAlphaTestCmpValue(M3DRenderer *_this, float _value)
{
    IGV5Model_SetAlphaTestCmpValue(_value);
}

void M3DRenderer_EnableSpecular(M3DRenderer *_this, int _bEnable)
{
	IGV5Renderer_EnableSpecular(_bEnable);
}

void M3DRenderer_SetCameraNearFar(M3DRenderer *_this, float _near, float _far)
{
	_this->m_CameraInfo.m_Near = _near;
	_this->m_CameraInfo.m_Far  = _far;
	_this->m_CameraInfoCurrent.m_Near = _near;
	_this->m_CameraInfoCurrent.m_Far  = _far;
}

void M3DRenderer_PrepareCamera(M3DRenderer *_this, IGV5Model *_pModel)
{
	IGV5Model_UpdateCamera(_pModel, &_this->m_CameraInfo.m_From, &_this->m_CameraInfo.m_To, &_this->m_CameraInfo.m_Up, &_this->m_CameraInfo.m_Fov, 0);
	IGV5Camera_LookAt(&_this->m_Camera, &_this->m_CameraInfo.m_From, &_this->m_CameraInfo.m_To, &_this->m_CameraInfo.m_Up);
	//_this->m_CameraInfo.m_Fov = 1.5f;
	IGV5Camera_Project(&_this->m_Camera, _this->m_CameraInfo.m_Fov,  (float)(_this->m_EngineRC.m_sEGLInfo.m_uWidth) / (float)(_this->m_EngineRC.m_sEGLInfo.m_uHeight), _this->m_CameraInfo.m_Near, _this->m_CameraInfo.m_Far);

	M3DCameraInfo_Copy(&_this->m_CameraInfo, &_this->m_CameraInfoCurrent);
}

void M3DRenderer_PrepareLight(M3DRenderer *_this, IGV5Model *_pModel)
{
	IGV5Model_GetLight(_pModel, &_this->m_Light);
}

void M3DRenderer_SetLightColor(M3DRenderer *_this, int _light_idx, float _r, float _g, float _b)
{
	unsigned int light_idx = (unsigned int) _light_idx;
	if (light_idx < _this->m_Light.lightCount)
	{
		_this->m_Light.aryLight[light_idx].lightColor.x = _r;
		_this->m_Light.aryLight[light_idx].lightColor.y = _g;
		_this->m_Light.aryLight[light_idx].lightColor.z = _b;
	}
}

void M3DRenderer_Update(M3DRenderer *_this, float _fFrameTime)
{
}

void M3DRenderer_PrepareRender(M3DRenderer *_this)
{
	IGV5RenderState_Reset(&_this->m_EngineRC); //CY
	glViewport(0, 0, _this->m_EngineRC.m_sEGLInfo.m_uWidth, _this->m_EngineRC.m_sEGLInfo.m_uHeight);
	IGV5Renderer_SetZWrite(IGV5_TRUE);
	IGV5Renderer_SetZTestFunc(IGV5RS_ZTEST_LEQUAL);
	IGV5Renderer_SetBackFaceCulling(IGV5RS_CULL_BACK);

	//glClearColor(0.6f, 0.8f, 1.0f, 1.0f);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	GL_CHECK(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	GL_CHECK(glEnable(GL_DITHER));
	GL_CHECK(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));  //CY: prevent someone set index buffer before us

	IGV5Renderer_SetAlphaBlendMode(IGV5RS_ALPHA_COMPLEMENT);
}

void M3DRenderer_Render2D(M3DRenderer *_this, const char *_tex_name)
{
	IGV5Rect rect;
	IGV5Texture *tex = NULL;
	
	tex = M3DTextureCollection_Get(&_this->m_TextureCollection, _tex_name);

	rect.m_iLeft = 0;
	rect.m_iTop = 0;
	rect.m_iRight = _this->m_EngineRC.m_sEGLInfo.m_uWidth;
	rect.m_iBottom = _this->m_EngineRC.m_sEGLInfo.m_uHeight;

	IGV5RenderState_Reset(&_this->m_EngineRC);   //CY
	glViewport(0, 0, _this->m_EngineRC.m_sEGLInfo.m_uWidth, _this->m_EngineRC.m_sEGLInfo.m_uHeight); //CY
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	GL_CHECK(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));  //CY: prevent someone set index buffer before us

	GL_CHECK(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	GL_CHECK(glEnable(GL_DITHER));
	IGV5Renderer_SetAlphaBlendMode(IGV5RS_ALPHA_NONE);
	IGV5Texture_Draw2(&_this->m_EngineRC, tex, NULL, 0.0f, 0.0f, &rect, 1.0f, 1.0f, 0xFFFFFFFF);

#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	IGV5Renderer_Present(&_this->m_EngineRC);
#endif
}

void M3DRenderer_Render(M3DRenderer *_this)
{
	//extern int iii;
#if defined(M3D_SHOW_MEMORY)
	unsigned mem_used = M3DRenderer_GetUsedMemory(_this);
	IGV5Font_DrawNum(&_this->m_EngineRC, 10,100, (int)mem_used, 0xffff0000);
	IGV5Font_DrawNum(&_this->m_EngineRC, 10,130, m3d_adaption_get_pvr_time(), 0xffff0000);
	IGV5Font_DrawNum(&_this->m_EngineRC, 10,160, m3d_adaption_get_load1_time(), 0xffff0000);
	IGV5Font_DrawNum(&_this->m_EngineRC, 10,190, m3d_adaption_get_load2_time(), 0xffff0000);
#endif
  //IGV5Font_DrawNum(&_this->m_EngineRC, 10,190, iii, 0xffff0000);

	IGV5Time_UpdateFPS(&_this->m_EngineRC.m_sPerformanceInfo);

#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	IGV5Renderer_Present(&_this->m_EngineRC);
#endif

	/*
	if (_this->m_RBO_ID != 0)
	{
		GL_CHECK(glDeleteRenderbuffers(1, &_this->m_RBO_ID));
		_this->m_RBO_ID = 0;
	}
	*/
}

//Camera
void M3DRenderer_InitCameraRotation(M3DRenderer *_this, float _degree)
{
}

void M3DRenderer_SetCameraRotation(M3DRenderer *_this, float _degree)
{
	_this->m_CameraRotation = _degree;
}

void M3DRenderer_IncreaseCameraRotation(M3DRenderer *_this, float _degree)
{
	_this->m_CameraRotation += _degree;
}

void M3DRenderer_UpdateCameraRotation(M3DRenderer *_this)
{
	float ds = M3DDistance(_this->m_CameraInfo.m_From.x - _this->m_CameraInfo.m_To.x, 0.0f, _this->m_CameraInfo.m_From.z - _this->m_CameraInfo.m_To.z);
	float degree = _this->m_CameraRotation + 90.0f;
	CVector3f *center = (CVector3f *) &_this->m_CameraInfoCurrent.m_To;
	CVector3f *point = (CVector3f *) &_this->m_CameraInfoCurrent.m_From;

	if (degree >= 360.0f)
		degree -= 360.0f;
	if (degree <= -360.0f)
		degree += 360.0f;

	M3DCircleDegree(center, ds, degree, point);
	IGV5Camera_LookAt(&_this->m_Camera, &_this->m_CameraInfoCurrent.m_From, &_this->m_CameraInfoCurrent.m_To, &_this->m_CameraInfoCurrent.m_Up);
	IGV5Camera_Project(&_this->m_Camera, _this->m_CameraInfoCurrent.m_Fov,  (float)(_this->m_EngineRC.m_sEGLInfo.m_uWidth) / (float)(_this->m_EngineRC.m_sEGLInfo.m_uHeight), _this->m_CameraInfoCurrent.m_Near, _this->m_CameraInfoCurrent.m_Far);
}

void M3DRenderer_UpdateVerticalCameraRotation(M3DRenderer *_this)
{
	float ds = M3DDistance(_this->m_CameraInfo.m_From.y - _this->m_CameraInfo.m_To.y, 0.0f, _this->m_CameraInfo.m_From.z - _this->m_CameraInfo.m_To.z);
	float degree = _this->m_CameraRotation;
	CVector3f *center = (CVector3f *) &_this->m_CameraInfoCurrent.m_To;
	CVector3f *point = (CVector3f *) &_this->m_CameraInfoCurrent.m_From;

	if (degree >= 360.0f)
		degree -= 360.0f;
	if (degree <= -360.0f)
		degree += 360.0f;

	M3DVerticalCircleDegree(center, ds, degree, point);
	IGV5Camera_LookAt(&_this->m_Camera, &_this->m_CameraInfoCurrent.m_From, &_this->m_CameraInfoCurrent.m_To, &_this->m_CameraInfoCurrent.m_Up);
	IGV5Camera_Project(&_this->m_Camera, _this->m_CameraInfoCurrent.m_Fov,  (float)(_this->m_EngineRC.m_sEGLInfo.m_uWidth) / (float)(_this->m_EngineRC.m_sEGLInfo.m_uHeight), _this->m_CameraInfoCurrent.m_Near, _this->m_CameraInfoCurrent.m_Far);
}

void M3DRenderer_SetCameraPanX(M3DRenderer *_this, float _x)
{
	_this->m_CameraPan.x = _x;
}

void M3DRenderer_SetCameraPanY(M3DRenderer *_this, float _y)
{
	_this->m_CameraPan.y = _y;
}

void M3DRenderer_SetCameraPanZ(M3DRenderer *_this, float _z)
{
	_this->m_CameraPan.z = _z;
}

void M3DRenderer_UpdateCameraPan(M3DRenderer *_this)
{
	_this->m_CameraInfoCurrent.m_From.x = _this->m_CameraInfo.m_From.x + _this->m_CameraPan.x;
	_this->m_CameraInfoCurrent.m_To.x = _this->m_CameraInfo.m_To.x + _this->m_CameraPan.x;
	_this->m_CameraInfoCurrent.m_From.z = _this->m_CameraInfo.m_From.z + _this->m_CameraPan.z;
	_this->m_CameraInfoCurrent.m_To.z = _this->m_CameraInfo.m_To.z + _this->m_CameraPan.z;
	IGV5Camera_LookAt(&_this->m_Camera, &_this->m_CameraInfoCurrent.m_From, &_this->m_CameraInfoCurrent.m_To, &_this->m_CameraInfoCurrent.m_Up);
	IGV5Camera_Project(&_this->m_Camera, _this->m_CameraInfoCurrent.m_Fov,  (float)(_this->m_EngineRC.m_sEGLInfo.m_uWidth) / (float)(_this->m_EngineRC.m_sEGLInfo.m_uHeight), _this->m_CameraInfoCurrent.m_Near, _this->m_CameraInfoCurrent.m_Far);
}

void M3DRenderer_UpdateCameraMove(M3DRenderer *_this)
{
	_this->m_CameraInfoCurrent.m_From.y = _this->m_CameraInfo.m_From.y + _this->m_CameraPan.y;
	IGV5Camera_LookAt(&_this->m_Camera, &_this->m_CameraInfoCurrent.m_From, &_this->m_CameraInfoCurrent.m_To, &_this->m_CameraInfoCurrent.m_Up);
	IGV5Camera_Project(&_this->m_Camera, _this->m_CameraInfoCurrent.m_Fov,  (float)(_this->m_EngineRC.m_sEGLInfo.m_uWidth) / (float)(_this->m_EngineRC.m_sEGLInfo.m_uHeight), _this->m_CameraInfoCurrent.m_Near, _this->m_CameraInfoCurrent.m_Far);
}

void M3DRenderer_SetLookTo(M3DRenderer *_this, CVector3f *_to)
{
	_this->m_CameraInfoCurrent.m_To.x = _to->x;
	_this->m_CameraInfoCurrent.m_To.y = _to->y;
	_this->m_CameraInfoCurrent.m_To.z = _to->z;

	IGV5Camera_LookAt(&_this->m_Camera, &_this->m_CameraInfoCurrent.m_From, &_this->m_CameraInfoCurrent.m_To, &_this->m_CameraInfoCurrent.m_Up);
	IGV5Camera_Project(&_this->m_Camera, _this->m_CameraInfoCurrent.m_Fov,  (float)(_this->m_EngineRC.m_sEGLInfo.m_uWidth) / (float)(_this->m_EngineRC.m_sEGLInfo.m_uHeight), _this->m_CameraInfoCurrent.m_Near, _this->m_CameraInfoCurrent.m_Far);
}

//Shader
void M3DRenderer_CreateGouraudShader(M3DRenderer *_this)
{
	_this->m_gouraudShader = IGV5GouraudShader_CreateProgram();
}

void M3DRenderer_CreateGouraudShadowShader(M3DRenderer *_this)
{
	_this->m_gouraudShadowShader = IGV5GouraudShadowShader_CreateProgram();
}

void M3DRenderer_CreateSkinningGouraudShader(M3DRenderer *_this)
{
	_this->m_skinningGouraudShader = IGV5SkinningGouraudShader_CreateProgram();
}

void M3DRenderer_CreateUVDisplacementShader(M3DRenderer *_this)
{
	_this->m_uvDisplacementShader = IGV5UVDisplacementShader_CreateProgram();
	_this->m_TextureCollection.uvDisplacementShader = _this->m_uvDisplacementShader;
}

void M3DRenderer_CreateTextureShader(M3DRenderer *_this)
{
	_this->m_textureShader = IGV5TextureShader_CreateProgram();
}

void M3DRenderer_CreateSkinningTextureShader(M3DRenderer *_this)
{
	_this->m_skinningTextureShader = IGV5SkinningTextureShader_CreateProgram();
}

void M3DRenderer_CreateTextureNoAlphaShader(M3DRenderer *_this)
{
	_this->m_textureNoAlphaShader = IGV5TextureNoAlphaShader_CreateProgram();
}

void M3DRenderer_CreateGouraudSpecularShader(M3DRenderer *_this)
{
	_this->m_gouraudSpecularShader = IGV5GouraudSpecularShader_CreateProgram();
}

void M3DRenderer_CreateSkinningGouraudSpecularShader(M3DRenderer *_this)
{
	_this->m_skinningGouraudSpecularShader = IGV5SkinningGouraudSpecularShader_CreateProgram();
}

void M3DRenderer_ReleaseGouraudShader(M3DRenderer *_this)
{
	IGV5GouraudShader_Release(&_this->m_gouraudShader);
}

void M3DRenderer_ReleaseGouraudShadowShader(M3DRenderer *_this)
{
	IGV5GouraudShadowShader_Release(&_this->m_gouraudShadowShader);
}

void M3DRenderer_ReleaseSkinningGouraudShader(M3DRenderer *_this)
{
	IGV5SkinningGouraudShader_Release(&_this->m_skinningGouraudShader);
}

void M3DRenderer_ReleaseUVDisplacementShader(M3DRenderer *_this)
{
	IGV5UVDisplacementShader_Release(&_this->m_uvDisplacementShader);
	_this->m_TextureCollection.uvDisplacementShader = NULL;
}

void M3DRenderer_ReleaseTextureShader(M3DRenderer *_this)
{
	IGV5TextureShader_Release(&_this->m_textureShader);
}

void M3DRenderer_ReleaseSkinningTextureShader(M3DRenderer *_this)
{
	IGV5SkinningTextureShader_Release(&_this->m_skinningTextureShader);
}

void M3DRenderer_ReleaseTextureNoAlphaShader(M3DRenderer *_this)
{
	IGV5TextureNoAlphaShader_Release(&_this->m_textureNoAlphaShader);
}

void M3DRenderer_ReleaseGouraudSpecularShader(M3DRenderer *_this)
{
	IGV5GouraudSpecularShader_Release(&_this->m_gouraudSpecularShader);
}

void M3DRenderer_ReleaseSkinningGouraudSpecularShader(M3DRenderer *_this)
{
	IGV5SkinningGouraudSpecularShader_Release(&_this->m_skinningGouraudSpecularShader);
}

void M3DRenderer_Shader_SetAlphaThreshold(M3DRenderer *_this, int _iShader, float _alphaThreshold)
{
	switch (_iShader)
	{
	case M3D_GOURAUD_SHADER :
		if (_this->m_gouraudShader == NULL)
		{
			M3DRenderer_CreateGouraudShader(_this);
		}
		IGV5GouraudShader_SetAlphaThreshold(_this->m_gouraudShader, _alphaThreshold);
		break;
	case M3D_GOURAUD_SHADOW_SHADER :
		if (_this->m_gouraudShadowShader == NULL)
		{
			M3DRenderer_CreateGouraudShadowShader(_this);
		}
		IGV5GouraudShadowShader_SetAlphaThreshold(_this->m_gouraudShadowShader, _alphaThreshold);
		break;
	case M3D_SKINNING_GOURAUD_SHADER :
		if (_this->m_skinningGouraudShader == NULL)
		{
			M3DRenderer_CreateSkinningGouraudShader(_this);
		}
		IGV5SkinningGouraudShader_SetAlphaThreshold(_this->m_skinningGouraudShader, _alphaThreshold);
		break;
	case M3D_UV_DISPLACEMENT_SHADER :
		if (_this->m_uvDisplacementShader == NULL)
		{
			M3DRenderer_CreateUVDisplacementShader(_this);
		}
		IGV5UVDisplacementShader_SetAlphaThreshold(_this->m_uvDisplacementShader, _alphaThreshold);
		break;
	case M3D_TEXTURE_SHADER :
		if (_this->m_textureShader == NULL)
		{
			M3DRenderer_CreateTextureShader(_this);
		}
		IGV5TextureShader_SetAlphaThreshold(_this->m_textureShader, _alphaThreshold);
		break;
	case M3D_TEXTURE_NO_ALPHA_SHADER:
		if (_this->m_textureNoAlphaShader == NULL)
		{
			M3DRenderer_CreateTextureNoAlphaShader(_this);
		}
		IGV5TextureNoAlphaShader_SetAlphaThreshold(_this->m_textureNoAlphaShader, _alphaThreshold);
		break;
	case M3D_SKINNING_TEXTURE_SHADER :
		if (_this->m_skinningTextureShader == NULL)
		{
			M3DRenderer_CreateSkinningTextureShader(_this);
		}
		IGV5SkinningTextureShader_SetAlphaThreshold(_this->m_skinningTextureShader, _alphaThreshold);
		break;
	case M3D_GOURAUD_SPECULAR_SHADER:
		if (_this->m_gouraudSpecularShader == NULL)
		{
			M3DRenderer_CreateGouraudSpecularShader(_this);
		}
		IGV5GouraudSpecularShader_SetAlphaThreshold(_this->m_gouraudSpecularShader, _alphaThreshold);
		break;
	case M3D_SKINNING_GOURAUD_SPECULAR_SHADER:
		if (_this->m_skinningGouraudSpecularShader == NULL)
		{
			M3DRenderer_CreateSkinningGouraudSpecularShader(_this);
		}
		IGV5SkinningGouraudSpecularShader_SetAlphaThreshold(_this->m_skinningGouraudSpecularShader, _alphaThreshold);
		break;
	}
}

ShaderProgram *M3DRenderer_GetShader(M3DRenderer *_this, int _iShader)
{
	ShaderProgram *pShader = NULL;

	switch (_iShader)
	{
	case M3D_GOURAUD_SHADER :
		if (_this->m_gouraudShader == NULL)
			M3DRenderer_CreateGouraudShader(_this);

		pShader = (ShaderProgram*)_this->m_gouraudShader;
		break;
	case M3D_GOURAUD_SHADOW_SHADER :
		if (_this->m_gouraudShadowShader == NULL)
			M3DRenderer_CreateGouraudShadowShader(_this);

		pShader = (ShaderProgram*)_this->m_gouraudShadowShader;
		break;
	case M3D_SKINNING_GOURAUD_SHADER :
		if (_this->m_skinningGouraudShader == NULL)
			M3DRenderer_CreateSkinningGouraudShader(_this);

		pShader = (ShaderProgram*)_this->m_skinningGouraudShader;
		break;
	case M3D_UV_DISPLACEMENT_SHADER :
		if (_this->m_uvDisplacementShader == NULL)
			M3DRenderer_CreateUVDisplacementShader(_this);

		pShader = (ShaderProgram*)_this->m_uvDisplacementShader;
		break;
	case M3D_TEXTURE_SHADER :
		if (_this->m_textureShader == NULL)
			M3DRenderer_CreateTextureShader(_this);

		pShader = (ShaderProgram*)_this->m_textureShader;
		break;
	case M3D_SKINNING_TEXTURE_SHADER :
		if (_this->m_skinningTextureShader == NULL)
			M3DRenderer_CreateSkinningTextureShader(_this);

		pShader = (ShaderProgram*)_this->m_skinningTextureShader;
		break;
	case M3D_TEXTURE_NO_ALPHA_SHADER :
		if (_this->m_textureNoAlphaShader == NULL)
			M3DRenderer_CreateTextureNoAlphaShader(_this);

		pShader = (ShaderProgram*)_this->m_textureNoAlphaShader;
		break;
	case M3D_GOURAUD_SPECULAR_SHADER :
		if (_this->m_gouraudSpecularShader == NULL)
			M3DRenderer_CreateGouraudSpecularShader(_this);

		pShader = (ShaderProgram*)_this->m_gouraudSpecularShader;
		break;
	case M3D_SKINNING_GOURAUD_SPECULAR_SHADER :
		if (_this->m_skinningGouraudSpecularShader == NULL)
			M3DRenderer_CreateSkinningGouraudSpecularShader(_this);

		pShader = (ShaderProgram*)_this->m_skinningGouraudSpecularShader;
		break;
	}

	return pShader;
}

//Shadow and Reflection
void M3DRenderer_AddReflectionModel(M3DRenderer *_this, IGV5Model *_pModel)
{
	_this->m_ReflectionModels[_this->m_iReflectionModel].model = _pModel;
	_this->m_ReflectionModels[_this->m_iReflectionModel].allNode = IGV5_TRUE;
	_this->m_iReflectionModel++;
}

void M3DRenderer_AddShadowModel(M3DRenderer *_this, IGV5Model *_pModel)
{
	_this->m_ShadowModels[_this->m_iShadowModel].model = _pModel;
	_this->m_ShadowModels[_this->m_iShadowModel].allNode = IGV5_TRUE;
	_this->m_iShadowModel++;
}

int  M3DRenderer_GetDirectionalLightIndex(M3DRenderer *_this)
{
	IGV5Light *light = &_this->m_Light;
	unsigned int cn;
	int index = -1;

	for (cn = 0; cn < light->lightCount; cn++)
	{
		if (light->aryLight[cn].type == ePODDirectional)
		{
			index = cn;
			break;
		}
	}
	return index;
}

void M3DRenderer_PrepareShadow(M3DRenderer *_this)
{
	Vec3 lightDir;
	IGV5Light *light = &_this->m_Light;
	IGV5Camera *camera = &_this->m_Camera;
	int  iLight = M3DRenderer_GetDirectionalLightIndex(_this);

	lightDir.x = light->aryLight[0].lightPosDir.x;
	lightDir.y = light->aryLight[0].lightPosDir.y;
	lightDir.z = light->aryLight[0].lightPosDir.z;

	if (iLight == -1)
	{
		lightDir.x = 1;
		lightDir.y = -2;
		lightDir.z = -2;
	}
	else
	{
		lightDir.x = light->aryLight[iLight].lightPosDir.x;
		lightDir.y = light->aryLight[iLight].lightPosDir.y;
		lightDir.z = light->aryLight[iLight].lightPosDir.z;
	}

#if defined(M3D_ENABLE_SHADOW)
	_this->m_ShadowInfoPtr = IGV5Model_InitShadowInfo(camera, &lightDir, _this->m_ShadowModels, _this->m_iShadowModel, 0.35f, 0.02f);
	IGV5Model_RenderShadow(&_this->m_EngineRC, NULL, _this->m_ShadowInfoPtr);
#endif
}

void M3DRenderer_InitReflection(M3DRenderer *_this, IGV5Model *_reflector, char *_node_name, float reflectorOpacity)
{
	int node_index = -1;

	_this->m_ReflectorModel = _reflector;
	_this->m_ReflectorNodeName = _node_name;
//#if defined(M3D_ENABLE_SHADOW)
	node_index = IGV5Model_FindNodeIdxByName(_reflector, _node_name);
	
	MMI_ASSERT((node_index >= 0));
	
	_reflector->m_Scene.m_POD.pMaterial[_reflector->m_Scene.m_POD.pNode[node_index].nIdxMaterial].fMatOpacity = reflectorOpacity;
	_this->m_ReflectionInfoPtr = IGV5Reflection_InitReflectionInfo(_reflector, node_index, _this->m_ReflectionModels, _this->m_iReflectionModel, IGV5_FALSE);
//#endif
}

void M3DRenderer_PrepareReflection(M3DRenderer *_this)
{
	IGV5Light *light = &_this->m_Light;
	IGV5Camera *camera = &_this->m_Camera;

	if (_this->m_ReflectionInfoPtr == NULL) {
		return; 
	}

#if defined(M3D_ENABLE_SHADOW)
	IGV5Reflection_RenderReflection(_this->m_ReflectionInfoPtr, light, camera);
#endif
}

void M3DRenderer_ReleaseShadow(M3DRenderer *_this)
{
#if defined(M3D_ENABLE_SHADOW)
	IGV5Model_ReleaseShadowInfo(_this->m_ShadowInfoPtr);
#endif
}

void M3DRenderer_ReleaseReflection(M3DRenderer *_this)
{
	if (_this->m_ReflectionInfoPtr == NULL)
		return;

#if defined(M3D_ENABLE_SHADOW)
	IGV5Reflection_Release(_this->m_ReflectionInfoPtr);
	_this->m_ReflectionInfoPtr = NULL;
#endif
}

void M3DRenderer_LoadSkyboxTexture(M3DRenderer *_this, char *_water_tex_name, unsigned char const *_water_tex_data, char *_sky_tex_name, unsigned char const *_sky_box_tex_data)
{
	M3DTextureCollection_AddFromMem(&_this->m_TextureCollection, "Water.pvr",   _water_tex_data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	M3DTextureCollection_AddFromMem(&_this->m_TextureCollection, "Sky_box.pvr", _sky_box_tex_data);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

void M3DRenderer_InitSkybox(M3DRenderer *_this, char *_water_tex_name, char *_sky_tex_name, int (*_fnDrawReflectionModels)(struct IGV5SkyBoxType *pSkyBox, IGV5Matrix *pView, IGV5Matrix *pProjection))
{
	IGV5Texture *pTex = NULL;

	pTex = M3DTextureCollection_Get(&_this->m_TextureCollection, _water_tex_name);
	_this->m_SkyBox.m_pWaterNormalTex = pTex;
	pTex = M3DTextureCollection_Get(&_this->m_TextureCollection, _sky_tex_name);
	_this->m_SkyBox.m_pSkyCubeTex = pTex;
	_this->m_SkyBox.m_fnDrawReflectionModels = _fnDrawReflectionModels;

	_this->m_SkyBox.m_pSceneCamera = &_this->m_Camera;
	_this->m_SkyBox.m_bDrawWater = IGV5_FALSE;
	_this->m_SkyBox.m_fBoxSize = 4000.0f; 
	_this->m_SkyBox.m_fWaterLevel = 0.0f;

	IGV5Vec3_Set(&_this->m_SkyBox.m_vSkyBoxPos, 0.0f, 10.0f,0.0f);  // position of skybox, only height (Y-axis) matters
	IGV5Vec4_Set(&_this->m_SkyBox.m_vWaterColor, 0.3f,0.0f,0.0f,1.0f);  // color of water

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	IGV5SkyBox_Create(&_this->m_SkyBox);
}

void M3DRenderer_UpdateSkybox(M3DRenderer *_this, float _ElapsedTime)
{
	IGV5SkyBox_Update(&_this->m_EngineRC, &_this->m_SkyBox, _ElapsedTime);
}

void M3DRenderer_ReleaseSkybox(M3DRenderer *_this)
{
	IGV5SkyBox_Release(&_this->m_SkyBox);
}

#ifdef __cplusplus
}
#endif
