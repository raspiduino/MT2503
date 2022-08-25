//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : M3D_LW_Lib
// File        : M3DTextureManager.c
// Description : M3D Texture Manager
// Author      : Ray
// Create      : 2011-08-03
// Update      : 2011-08-03
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "M3DRenderer.h"
#include "M3DGameDef.h"
#include "M3DUtils.h"

#include "m3d_adaption.h"
#include "M3DMemory.h"
#include "M3DTextureManager.h"
#include "IGV5Texture.h"
#include "IGV5Memory.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

static IGV5Texture *IGV5Texture_New()
{
	IGV5Texture *_self = (IGV5Texture *) M3DMemory_New(sizeof(IGV5Texture));
	return _self;
}

static void IGV5Texture_Del(IGV5Texture *_this)
{
	if (_this == NULL)
		return;

	IGV5Texture_Release(_this);
	M3DMemory_Del(_this);
	_this = NULL;
}

void M3DTextureCollection_Init(M3DTextureCollection *_this, void *_rr)
{
	_this->m_rr = _rr;
	_this->m_Textures = M3DNamedObjArray_New();
	_this->m_TexturesNormal = M3DNamedObjArray_New();
	_this->m_TexturesAlpha  = M3DNamedObjArray_New();
	_this->m_TexturesUVAnim = M3DNamedObjArray_New();
	_this->m_UVAnimTimeFactorU = 0.5f;
	_this->m_UVAnimTimeFactorV = 0.0f;
	_this->uvDisplacementShader = NULL;

	IGV5Texture_CreateDefault();
}

static void M3DTextureCollection_Gen_Filepath(char *_filepath, char *_filename)
{
	strcpy(_filepath, "./PVR/");
	strcat(_filepath, _filename);
	strcat(_filepath, ".pvr");
}

static void M3DTextureCollection_Gen_Normal_Filepath(char *_filepath, char *_filename)
{
	strcpy(_filepath, "./PVR/");
	strcat(_filepath, _filename);
	strcat(_filepath, "_normal.pvr");
}

static void M3DTextureCollection_Gen_Alpha_Filepath(char *_filepath, char *_filename)
{
	strcpy(_filepath, "./PVR/");
	strcat(_filepath, _filename);
	strcat(_filepath, "_a.pvr");
}

static int iMipMapStartLevel = 0;

void M3DTextureCollection_Add(M3DTextureCollection *_this, char *_tex_name, unsigned char const *_data, unsigned char const *_data_n, unsigned char const *_data_a)
{
	char name[128];
	IGV5Texture *pTexture = IGV5Texture_New();

	strcpy(name, _tex_name);
	strcat(name, ".pvr");
	IGV5Texture_LoadPVRFromMem(pTexture, (void *) _data, NULL, IGV5_TRUE, iMipMapStartLevel, NULL);
	M3DNamedObjArray_Add(_this->m_Textures, name, pTexture);
	if (_data_n != NULL)
	{
		pTexture = IGV5Texture_New();
		IGV5Texture_LoadPVRFromMem(pTexture, (void *) _data_n, NULL, IGV5_TRUE, iMipMapStartLevel, NULL);
		M3DNamedObjArray_Add(_this->m_TexturesNormal, name, pTexture);
	}
	if (_data_a != NULL)
	{
		pTexture = IGV5Texture_New();
		IGV5Texture_LoadPVRFromMem(pTexture, (void *) _data_a, NULL, IGV5_TRUE, iMipMapStartLevel, NULL);
		M3DNamedObjArray_Add(_this->m_TexturesAlpha, name, pTexture);
	}
}

void M3DTextureCollection_SetMipLevelStart(int iL)
{
	iMipMapStartLevel = iL;
}

void M3DTextureCollection_AddFromFile(M3DTextureCollection *_this, char *_tex_name, char *_filepath)
{
	IGV5Texture *pTexture = IGV5Texture_New();

	if (_tex_name != NULL && _filepath != NULL)
	{
		IGV5Texture_LoadPVRFromFile(pTexture, _filepath, NULL, IGV5_TRUE, 0);
		M3DNamedObjArray_Add(_this->m_Textures, _tex_name, pTexture);
	}
}

void M3DTextureCollection_AddFromMem(M3DTextureCollection *_this, char *_tex_name, unsigned char const *_data)
{
	IGV5Texture *pTexture = IGV5Texture_New();

	if (_tex_name != NULL && _data != NULL)
	{
		IGV5Texture_LoadPVRFromMem(pTexture, (void *) _data, NULL, IGV5_TRUE, iMipMapStartLevel, NULL);
		M3DNamedObjArray_Add(_this->m_Textures, _tex_name, pTexture);
	}
}

void M3DTextureCollection_Map(M3DTextureCollection *_this, char *_tex_name, char *_normal_tex_name, char *_alpha_tex_name)
{
	IGV5Texture *pTexture = NULL;

	if (_normal_tex_name != NULL)
	{
		pTexture = M3DTextureCollection_Get(_this, _normal_tex_name);
		M3DNamedObjArray_Add(_this->m_TexturesNormal, _tex_name, pTexture);
	}
	if (_alpha_tex_name != NULL)
	{
		pTexture = M3DTextureCollection_Get(_this, _alpha_tex_name);
		M3DNamedObjArray_Add(_this->m_TexturesAlpha, _tex_name, pTexture);
	}
}

void M3DTextureCollection_MapAlpha(M3DTextureCollection *_this, char *_tex_name, char *_alpha_tex_name)
{
	IGV5Texture *pTexture = NULL;

	if (_alpha_tex_name != NULL)
	{
		pTexture = M3DTextureCollection_Get(_this, _alpha_tex_name);
		M3DNamedObjArray_Add(_this->m_TexturesAlpha, _tex_name, pTexture);
	}
}

void M3DTextureCollection_AddUVAnim(M3DTextureCollection *_this, char *_tex_name)
{
	M3DNamedObjArray_Add(_this->m_TexturesUVAnim, _tex_name, _tex_name);
}

int  M3DTextureCollection_IsUVAnim(M3DTextureCollection *_this, char *_tex_name)
{
	int ret = 0;

	if (M3DNamedObjArray_GetFirstByName(_this->m_TexturesUVAnim, _tex_name) != NULL)
		ret = 1;
	return ret;
}

void M3DTextureCollection_AddFromFile_old(M3DTextureCollection *_this, char *_filename, int _bNormal, int _bAlpha)
{
	char filepath[128];
	char name[128];
	IGV5Texture *pTexture = IGV5Texture_New();

	strcpy(name, _filename);
	strcat(name, ".pvr");
	M3DTextureCollection_Gen_Filepath(filepath, _filename);
	IGV5Texture_LoadPVRFromFile(pTexture, filepath, NULL, IGV5_TRUE, 0);
	M3DNamedObjArray_Add(_this->m_Textures, name, pTexture);
	if (_bNormal)
	{
		pTexture = IGV5Texture_New();
		M3DTextureCollection_Gen_Normal_Filepath(filepath, _filename);
		IGV5Texture_LoadPVRFromFile(pTexture, filepath, NULL, IGV5_TRUE, 0);
		M3DNamedObjArray_Add(_this->m_TexturesNormal, name, pTexture);
	}
	if (_bAlpha)
	{
		pTexture = IGV5Texture_New();
		M3DTextureCollection_Gen_Alpha_Filepath(filepath, _filename);
		IGV5Texture_LoadPVRFromFile(pTexture, filepath, NULL, IGV5_TRUE, 0);
		M3DNamedObjArray_Add(_this->m_TexturesAlpha, name, pTexture);
	}
}

void M3DTextureCollection_AddFromFiles(M3DTextureCollection *_this, M3DSplitString *_filenames)
{
	char filepath[128];
	IGV5Texture *tex = NULL;
	IGV5Texture *pTexture = NULL;
	char filename[32];
	int remain = 0;

	M3DSplitString_Reset(_filenames);

	do {
		remain = M3DSplitString_GetNext(_filenames, filename);
		if (strlen(filename) > 0)	//如果不是空白字串才要載入
		{
			tex = M3DTextureCollection_Get(_this, filename);
			if (tex == NULL)	//不要重複載入, 不存在的才要載入
			{
				strcpy(filepath, "./PVR/");
				strcat(filepath, filename);
				pTexture = IGV5Texture_New();
				IGV5Texture_LoadPVRFromFile(pTexture, filepath,  NULL, IGV5_TRUE, 0);
				M3DNamedObjArray_Add(_this->m_Textures, filename, pTexture);
			}
		}
	} while (remain > 0);
}

void M3DTextureCollection_Remove(M3DTextureCollection *_this, const char *_tex_name)
{
	int idx = M3DNamedObjArray_GetIndex(_this->m_Textures, _tex_name);
	IGV5Texture *tex = (IGV5Texture *) M3DNamedObjArray_Get(_this->m_Textures, idx);

	if (tex != NULL)
	{
		IGV5Texture_Del(tex);
		M3DNamedObjArray_Remove(_this->m_Textures, idx);
	}
}

void M3DTextureCollection_Release(M3DTextureCollection *_this)
{
	int cn;
	IGV5Texture *tex = NULL;

	IGV5Texture_ReleaseDefault();

	for (cn = 0; cn < _this->m_Textures->m_Count; cn = cn + 1)
	{
		tex = (IGV5Texture *) M3DNamedObjArray_Get(_this->m_Textures, cn);
		IGV5Texture_Del(tex);
	}
	for (cn = 0; cn < _this->m_TexturesNormal->m_Count; cn = cn + 1)
	{
		tex = (IGV5Texture *) M3DNamedObjArray_Get(_this->m_TexturesNormal, cn);
		IGV5Texture_Del(tex);
	}
	for (cn = 0; cn < _this->m_TexturesAlpha->m_Count; cn = cn + 1)
	{
		tex = (IGV5Texture *) M3DNamedObjArray_Get(_this->m_TexturesAlpha, cn);
		IGV5Texture_Del(tex);
	}
	M3DNamedObjArray_Del(_this->m_TexturesUVAnim);
	M3DNamedObjArray_Del(_this->m_TexturesAlpha);
	M3DNamedObjArray_Del(_this->m_TexturesNormal);
	M3DNamedObjArray_Del(_this->m_Textures);
}

IGV5Texture *M3DTextureCollection_Get(M3DTextureCollection *_this, const char *_name)
{
	IGV5Texture *tex = NULL;
	tex = (IGV5Texture *) M3DNamedObjArray_GetFirstByName(_this->m_Textures, _name);

	return tex;
}

void M3DTextureCollection_GetByNames(M3DTextureCollection *_this, M3DSplitString *_names, IGV5NameCache *_cache)
{
	IGV5Texture *tex = NULL;
	int count = 0;
	char tex_name[128];
	char *name = NULL;

	M3DSplitString_Reset(_names);
	do {
		count = M3DSplitString_GetNext(_names, tex_name);
		tex = M3DTextureCollection_Get(_this, tex_name);
		name = (char *) M3DNamedObjArray_GetNameByName(_this->m_Textures, tex_name);
		IGV5NameCache_Add(_cache, name, tex);
	} while (count > 0);
}

void M3DTextureCollection_Bind(M3DTextureCollection *_this, const char *_name)
{
	IGV5Texture *tex = NULL;

	tex = (IGV5Texture *) M3DNamedObjArray_GetFirstByName(_this->m_TexturesNormal, _name);
	if (tex != NULL)
	{
		IGV5Texture_Set(tex, 1);
	}
	tex = (IGV5Texture *) M3DNamedObjArray_GetFirstByName(_this->m_TexturesAlpha, _name);
	if (tex != NULL)
	{
		IGV5Texture_Set(tex, 3);
		//IGV5Renderer_SetBackFaceCulling(IGV5RS_CULL_NONE);
	}

	if (M3DTextureCollection_IsUVAnim(_this, (char *)_name) == 1 && _this->uvDisplacementShader) {
		M3DRenderer *rr = (M3DRenderer *) _this->m_rr;
		float uDisplacement = rr->m_GameTime / 5000.0f * _this->m_UVAnimTimeFactorU;
		float vDisplacement = rr->m_GameTime / 5000.0f * _this->m_UVAnimTimeFactorV;
		int iu = (int) (uDisplacement / 2.0f);
		int iv = (int) (vDisplacement / 2.0f);

		uDisplacement = uDisplacement - iu * 2;
		vDisplacement = vDisplacement - iv * 2;
		IGV5UVDisplacementShader_SetDisplacement(_this->uvDisplacementShader, uDisplacement, vDisplacement);
	}
}

void M3DTextureCollection_SetUVAnimTimeFactor(M3DTextureCollection *_this, float _time_factor_u, float _time_factor_v)
{
	_this->m_UVAnimTimeFactorU = _time_factor_u;
	_this->m_UVAnimTimeFactorV = _time_factor_v;
}

#ifdef __cplusplus
}
#endif // __cplusplus
