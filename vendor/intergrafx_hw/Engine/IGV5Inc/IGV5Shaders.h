
#ifndef __IGV5SHADERS_H
#define __IGV5SHADERS_H

#include "Shaders/IGV5GouraudShader.h"
#include "Shaders/IGV5GouraudShadowShader.h"
#include "Shaders/IGV5SkinningGouraudShader.h"
#include "Shaders/IGV5SkinningTextureShader.h"
#include "Shaders/IGV5TextureNoAlphaShader.h"
#include "Shaders/IGV5TextureShader.h"
#include "Shaders/IGV5UVDisplacementShader.h"
#include "Shaders/IGV5GouraudNormalMapShader.h"
#include "Shaders/IGV5GouraudSpecularShader.h"
#include "Shaders/IGV5SkinningGouraudNormalMapShader.h"
#include "Shaders/IGV5SkinningGouraudSpecularShader.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef enum 
{
    SHADERS_TYPE_UNKNOWN = 0,
    SHADERS_TYPE_TEXTURE_SHADER,                //default model shader
	SHADERS_TYPE_TEXTURE_NO_ALPHA_SHADER,	
	SHADERS_TYPE_UV_DISPLACEMENT_SHADER,

	SHADERS_TYPE_GOURAUD_SHADER,	
	SHADERS_TYPE_GOURAUD_SHADOW_SHADER,
	SHADERS_TYPE_GOURAUD_NORMAL_MAP_SHADER,
	SHADERS_TYPE_GOURAUD_SPECULAR_SHADER,

    // skinning shaders
    SHADERS_TYPE_SKINNING_TEXTURE_SHADER,       //default skinning shader
    SHADERS_TYPE_SKINNING_GROURAUD_SHADER,
	SHADERS_TYPE_SKINNING_GOURAUD_NORMAL_MAP_SHADER,
	SHADERS_TYPE_SKINNING_GOURAUD_SPECULAR_SHADER,

    //SHADERS_TYPE_COUNT,
} eShadersTypes;


ShaderProgram *IGV5Shaders_CreateShaderProgram(eShadersTypes shaderType);

void IGV5Shaders_ReleaseShaderProgram(ShaderProgram *shaderProgram, eShadersTypes shaderType);

void IGV5Shaders_SetShaderAlphaThreshold(ShaderProgram *shaderProgram, eShadersTypes shaderType, float threshold);
float IGV5Shaders_GetShaderAlphaThreshold(ShaderProgram *shaderProgram, eShadersTypes shaderType);

void IGV5Shaders_SetShaderUVDisplacement(ShaderProgram *shaderProgram, eShadersTypes shaderType, float u, float v);
void IGV5Shaders_GetShaderUVDisplacement(ShaderProgram *shaderProgram, eShadersTypes shaderType, float *u_out, float *v_out);

#ifdef __cplusplus
}
#endif

#endif  //__IGV5SHADERS_H