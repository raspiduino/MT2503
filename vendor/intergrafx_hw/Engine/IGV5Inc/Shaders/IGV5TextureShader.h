
#ifndef __IGV5TEXTURESHADER_H
#define __IGV5TEXTURESHADER_H

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
	GLuint mvpMatrixLoc;

	// Fragment Shader variable locations
	GLuint opacityLoc;
	GLuint alphaThresholdLoc;

	// Attribute
	float alphaThreshold;

} IGV5TextureShaderProgram;

IGV5TextureShaderProgram* IGV5TextureShader_CreateProgram(void);

void IGV5TextureShader_Render(ShaderProgram* shaderProgram, void* model, unsigned int nodeIndex, IGV5Light* light, IGV5Matrix *pWorld, IGV5Matrix *mView, IGV5Matrix *mProjection, void* renderInfo);

void IGV5TextureShader_Release(IGV5TextureShaderProgram** textureShaderProgram);

void IGV5TextureShader_SetAlphaThreshold(IGV5TextureShaderProgram* textureShaderProgram, float alphaThreshold);

float IGV5TextureShader_GetAlphaThreshold(IGV5TextureShaderProgram* textureShaderProgram);

#ifdef __cplusplus
}
#endif

#endif