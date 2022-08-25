
#ifndef __IGV5SKINNINGTEXTURESHADER_H
#define __IGV5SKINNINGTEXTURESHADER_H

#include "IGV5ShaderProgram.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	ShaderProgram shaderProgram;

	// Shader IDs
	GLuint vertexShader;
	GLuint fragmentShader;
	GLuint programID;

	// Vertex Shader variable locations
	GLuint boneCountLoc;
	GLuint boneMatrixArrayLoc;

	GLuint viewProjMatrixLoc;

	// Fragment Shader variable locations
	GLuint opacityLoc;
	GLuint alphaThresholdLoc;

	// Attributes
	float alphaThreshold;

} IGV5SkinningTextureShaderProgram;

IGV5SkinningTextureShaderProgram* IGV5SkinningTextureShader_CreateProgram(void);

void IGV5SkinningTextureShader_Render(ShaderProgram* shaderProgram, void* model, unsigned int nodeIndex, IGV5Light* light, IGV5Matrix *pWorld, IGV5Matrix *mView, IGV5Matrix *mProjection, void* renderInfo);

void IGV5SkinningTextureShader_Release(IGV5SkinningTextureShaderProgram** skinningTextureShaderProgram);

void IGV5SkinningTextureShader_SetAlphaThreshold(IGV5SkinningTextureShaderProgram* skinningTextureShaderProgram, float alphaThreshold);

float IGV5SkinningTextureShader_GetAlphaThreshold(IGV5SkinningTextureShaderProgram* skinningTextureShaderProgram);

#ifdef __cplusplus
}
#endif

#endif