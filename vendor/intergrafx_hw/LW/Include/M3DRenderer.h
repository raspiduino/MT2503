//==============================================================================
// Copyright (c)2005 InterGrafx, Inc. All rights reserved.
// Project     : M3D_Lib
// File        : M3DRenderer.h
// Description : M3D 桌布公用程式 for IGV5
// Author      : Ray
// Create      : 2011-06-20
// Update      : 2010-09-27
//==============================================================================
#ifndef __M3D_RENDERER_H__
#define __M3D_RENDERER_H__

#include "IGV5RuntimeContext.h"
#include "IGV5LoadPODModel.h"
#include "M3DTextureManager.h"

#include "IGV5Camera.h"
#include "IGV5Light.h"
#include "IGV5Model.h"
#include "IGV5Node.h"
#include "IGV5Reflection.h"
#include "IGV5SkyBox.h"

#include "M3DPhysics.h"

#include "IGV5Shaders.h"
#include "Shaders\IGV5SkinningGouraudShader.h"
#include "Shaders\IGV5GouraudShadowShader.h"
#include "Shaders\IGV5GouraudShader.h"
#include "Shaders\IGV5SkinningTextureShader.h"
#include "Shaders\IGV5TextureNoAlphaShader.h"
#include "Shaders\IGV5TextureShader.h"
#include "Shaders\IGV5UVDisplacementShader.h"
#include "Shaders\IGV5UVDisplacementShader.h"
#include "Shaders\IGV5GouraudSpecularShader.h"
#include "Shaders\IGV5SkinningGouraudSpecularShader.h"

#define M3D_NULL_SHADER								SHADERS_TYPE_UNKNOWN
#define M3D_GOURAUD_SHADER							SHADERS_TYPE_GOURAUD_SHADER
#define M3D_GOURAUD_SHADOW_SHADER					SHADERS_TYPE_GOURAUD_SHADOW_SHADER
#define M3D_SKINNING_GOURAUD_SHADER					SHADERS_TYPE_SKINNING_GROURAUD_SHADER
#define M3D_UV_DISPLACEMENT_SHADER					SHADERS_TYPE_UV_DISPLACEMENT_SHADER
#define M3D_TEXTURE_SHADER							SHADERS_TYPE_TEXTURE_SHADER
#define M3D_SKINNING_TEXTURE_SHADER					SHADERS_TYPE_SKINNING_TEXTURE_SHADER
#define M3D_TEXTURE_NO_ALPHA_SHADER					SHADERS_TYPE_TEXTURE_NO_ALPHA_SHADER
#define M3D_GOURAUD_SPECULAR_SHADER					SHADERS_TYPE_GOURAUD_SPECULAR_SHADER
#define M3D_SKINNING_GOURAUD_SPECULAR_SHADER		SHADERS_TYPE_SKINNING_GOURAUD_SPECULAR_SHADER

#ifdef __cplusplus
extern "C" {
#endif

#define M3D_FRAME_RATE	(1.0f / 30.0f)

typedef struct _M3DCameraInfo
{
	int				m_ui32Camera;
	float			m_Fov;
	float			m_AspectRatio;
	float			m_Near;
	float			m_Far;
	Vec3			m_From, m_To, m_Up;
} M3DCameraInfo;

extern void M3DCameraInfo_Copy(M3DCameraInfo *_this, M3DCameraInfo *_to);


typedef struct _M3DRenderer
{
	IGV5InitInfoVer0101	m_InitInfo;

	M3DTextureCollection	m_TextureCollection;

	IGV5RC			m_EngineRC;
	int				m_WindowWidth;
	int				m_WindowHeight;

	//IGV5PODModel	*m_Scene;
	//IGV5Node		*m_SceneRoot;
	IGV5Camera		m_Camera;
	IGV5Light		m_Light;
	M3DCameraInfo	m_CameraInfo;	//Ori
	M3DCameraInfo	m_CameraInfoCurrent;
	ModelNode		m_ShadowModels[10];
	ModelNode		m_ReflectionModels[10];

	//Shader
	IGV5GouraudShaderProgram			*m_gouraudShader;
	IGV5GouraudShadowShaderProgram		*m_gouraudShadowShader;
	IGV5SkinningGouraudShaderProgram	*m_skinningGouraudShader;
	IGV5UVDisplacementShaderProgram		*m_uvDisplacementShader;
	IGV5TextureShaderProgram			*m_textureShader;
	IGV5SkinningTextureShaderProgram	*m_skinningTextureShader;
	IGV5TextureNoAlphaShaderProgram		*m_textureNoAlphaShader;
	IGV5GouraudSpecularShaderProgram	*m_gouraudSpecularShader;
	IGV5SkinningGouraudSpecularShaderProgram	*m_skinningGouraudSpecularShader;

	int				m_iShadowModel;
	int				m_iReflectionModel;
	IGV5Model		*m_ReflectorModel;
	char			*m_ReflectorNodeName;
	ShadowInfo		*m_ShadowInfoPtr;
	ReflectionInfo  *m_ReflectionInfoPtr;
	IGV5SkyBox		m_SkyBox;

	float			m_CameraRotation;
	CVector3f		m_CameraPan;
	float			m_GameTime;
	int				m_LoadState;
} M3DRenderer;


extern int  M3DRenderer_Init(M3DRenderer *_this, void *_pConfig);
extern unsigned M3DRenderer_GetUsedMemory(M3DRenderer *_this);
extern void M3DRenderer_Del(M3DRenderer *_this);
extern int  M3DRenderer_IsMemNull(M3DRenderer *_this);

extern void M3DRenderer_LoadModel(M3DRenderer *_this, char *_path, char *_filename, char *_textures);
extern void M3DRenderer_SetLookAt(M3DRenderer *_this, float _posX, float _posY, float _posZ, float _lookX, float _lookY, float _lookZ, float _upX, float _upY, float _upZ);

extern void M3DRenderer_LoadShader(M3DRenderer *_this);
extern void M3DRenderer_DrawMesh(M3DRenderer *_this, int i32NodeIndex);

extern void M3DRenderer_SetAlphaTestCmpValue(M3DRenderer *_this, float _value);
extern void M3DRenderer_EnableSpecular(M3DRenderer *_this, int _bEnable);

extern void M3DRenderer_Update(M3DRenderer *_this, float _fFrameTime);
extern void M3DRenderer_SetCameraNearFar(M3DRenderer *_this, float _near, float _far);
extern void M3DRenderer_PrepareCamera(M3DRenderer *_this, IGV5Model *_pModel);
extern void M3DRenderer_PrepareLight(M3DRenderer *_this, IGV5Model *_pModel);
extern void M3DRenderer_SetLightColor(M3DRenderer *_this, int _light_idx, float _r, float _g, float _b);
extern void M3DRenderer_Render2D(M3DRenderer *_this, const char *_tex_name);
extern void M3DRenderer_Render(M3DRenderer *_this);
extern void M3DRenderer_PrepareRender(M3DRenderer *_this);
extern int  M3DRenderer_GetDirectionalLightIndex(M3DRenderer *_this);
extern void M3DRenderer_PrepareShadow(M3DRenderer *_this);
extern void M3DRenderer_ReleaseShadow(M3DRenderer *_this);
extern void M3DRenderer_InitReflection(M3DRenderer *_this, IGV5Model *_reflector, char *_node_name, float reflectorOpacity);
extern void M3DRenderer_PrepareReflection(M3DRenderer *_this);
extern void M3DRenderer_ReleaseReflection(M3DRenderer *_this);

//Camera
extern void M3DRenderer_SetCameraRotation(M3DRenderer *_this, float _degree);
extern void M3DRenderer_IncreaseCameraRotation(M3DRenderer *_this, float _degree);
extern void M3DRenderer_UpdateCameraRotation(M3DRenderer *_this);
extern void M3DRenderer_UpdateVerticalCameraRotation(M3DRenderer *_this);
extern void M3DRenderer_SetCameraPanX(M3DRenderer *_this, float _x);
extern void M3DRenderer_SetCameraPanY(M3DRenderer *_this, float _y);
extern void M3DRenderer_SetCameraPanZ(M3DRenderer *_this, float _x);
extern void M3DRenderer_UpdateCameraPan(M3DRenderer *_this);
extern void M3DRenderer_UpdateCameraMove(M3DRenderer *_this);
extern void M3DRenderer_SetLookTo(M3DRenderer *_this, CVector3f *_to);

//Shadow and Reflection
extern void M3DRenderer_CreateGouraudShader(M3DRenderer *_this);
extern void M3DRenderer_CreateGouraudShadowShader(M3DRenderer *_this);
extern void M3DRenderer_CreateSkinningGouraudShader(M3DRenderer *_this);
extern void M3DRenderer_CreateUVDisplacementShader(M3DRenderer *_this);
extern void M3DRenderer_CreateTextureShader(M3DRenderer *_this);
extern void M3DRenderer_CreateSkinningTextureShader(M3DRenderer *_this);
extern void M3DRenderer_CreateTextureNoAlphaShader(M3DRenderer *_this);
extern void M3DRenderer_CreateGouraudSpecularShader(M3DRenderer *_this);
extern void M3DRenderer_CreateSkinningGouraudSpecularShader(M3DRenderer *_this);

extern void M3DRenderer_ReleaseGouraudShader(M3DRenderer *_this);
extern void M3DRenderer_ReleaseGouraudShadowShader(M3DRenderer *_this);
extern void M3DRenderer_ReleaseSkinningGouraudShader(M3DRenderer *_this);
extern void M3DRenderer_ReleaseUVDisplacementShader(M3DRenderer *_this);
extern void M3DRenderer_ReleaseTextureShader(M3DRenderer *_this);
extern void M3DRenderer_ReleaseSkinningTextureShader(M3DRenderer *_this);
extern void M3DRenderer_ReleaseTextureNoAlphaShader(M3DRenderer *_this);
extern void M3DRenderer_ReleaseGouraudSpecularShader(M3DRenderer *_this);
extern void M3DRenderer_ReleaseSkinningGouraudSpecularShader(M3DRenderer *_this);

extern void M3DRenderer_Shader_SetAlphaThreshold(M3DRenderer *_this, int _iShader, float _alphaThreshold);
extern ShaderProgram *M3DRenderer_GetShader(M3DRenderer *_this, int _iShader);

extern void M3DRenderer_AddReflectionModel(M3DRenderer *_this, IGV5Model *_pModel);
extern void M3DRenderer_AddShadowModel(M3DRenderer *_this, IGV5Model *_pModel);

extern void M3DRenderer_LoadSkyboxTexture(M3DRenderer *_this, char *_water_tex_name, unsigned char const *_water_tex_data, char *_sky_tex_name, unsigned char const *_sky_box_tex_data);
extern void M3DRenderer_InitSkybox(M3DRenderer *_this, char *_water_tex_name, char *_sky_tex_name, int (*_fnDrawReflectionModels)(struct IGV5SkyBoxType *pSkyBox, IGV5Matrix *pView, IGV5Matrix *pProjection));
extern void M3DRenderer_UpdateSkybox(M3DRenderer *_this, float _ElapsedTime);
extern void M3DRenderer_ReleaseSkybox(M3DRenderer *_this);

#ifdef __cplusplus
}
#endif

#endif

