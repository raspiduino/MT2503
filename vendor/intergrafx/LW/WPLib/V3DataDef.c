//==============================================================================
// Copyright (c)2010 InterGrafx, Inc. All rights reserved.
// Project     : IGV3Retained
// File        : V3DataDef.h
// Description : V3 ¸ê®Æµ²ºc
// Author      : Ray
// Create      : 2010-09-01
// Update      : 2011-02-15
//==============================================================================

#include <stdlib.h>
#include "V3DataDef.h"

#define DEFAULT_TEXTURE_SLOT	8

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

V3Texture *V3Texture_New(unsigned char const *_buf, const char *_name, int _r, int _g, int _b, int _keycolor)
{
	V3Texture *self = (V3Texture *) CNew(sizeof(V3Texture));
	self->m_pBuf = _buf;
	self->m_pName = _name;
	self->m_Mask[0] = _r;
	self->m_Mask[1] = _g;
	self->m_Mask[2] = _b;
	self->m_Keycolor = _keycolor;

	return self;
}

void V3Texture_Del(V3Texture *_this)
{
	CDel(_this);
}

CArray *V3Textures_New(V3Texture *_item)
{
	CArray *self = CArray_New((void *) _item);

	return self;
}

void V3Textures_Del(CArray *_this)
{
	int cn;

	for (cn = 0; cn < _this->m_Count; cn = cn + 1)
	{
		V3Texture_Del(_this->m_Array[cn]);
		_this->m_Array[cn] = NULL;
	}
	CArray_Del(_this);
}


V3World *V3World_New(unsigned char const *_buf, CArray *_textures, V3Texture *_background, const char *_name_scene, const char *_name_camera, const char *_name_animation)
{
	V3World *self = (V3World *) CNew(sizeof(V3World));
	self->m_pBuf = _buf;

	if (self->m_pBackground == NULL)
	{
		self->m_pBackground = V3Textures_New(NULL);
	}
	CArray_Add(self->m_pBackground, _background);

	self->m_pTextures = _textures;
	self->m_pName_SceneRoot = _name_scene;
	self->m_pName_Camera = _name_camera;
	self->m_pName_Animation = _name_animation;

	return self;
}

V3World *V3World_New2(unsigned char const *_buf, CArray *_textures, CArray *_textures_switch, V3Texture *_background, const char *_name_scene, const char *_name_camera, const char *_name_animation)
{
	V3World *self = (V3World *) CNew(sizeof(V3World));
	self->m_pBuf = _buf;

	if (self->m_pBackground == NULL)
	{
		self->m_pBackground = V3Textures_New(NULL);
	}
	CArray_Add(self->m_pBackground, _background);

	self->m_pTextures = _textures;
	self->m_pTexturesSwitch = _textures_switch;
	self->m_pName_SceneRoot = _name_scene;
	self->m_pName_Camera = _name_camera;
	self->m_pName_Animation = _name_animation;

	return self;
}

void V3World_AddBackground(V3World *_this, V3Texture *_background)
{
	CArray_Add(_this->m_pBackground, _background);
}

void V3World_Del(V3World *_this)
{
	if (_this != NULL)
	{
		V3Textures_Del(_this->m_pBackground);
		V3Textures_Del(_this->m_pTextures);
		if (_this->m_pTexturesSwitch != NULL)
			V3Textures_Del(_this->m_pTexturesSwitch);
		CDel(_this);
	}
}

#ifdef __cplusplus
}
#endif // __cplusplus
