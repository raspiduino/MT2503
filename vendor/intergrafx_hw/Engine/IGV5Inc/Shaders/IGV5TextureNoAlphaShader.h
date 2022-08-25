
#ifndef __IGV5TEXTURENOALPHASHADER_H
#define __IGV5TEXTURENOALPHASHADER_H

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

} IGV5TextureNoAlphaShaderProgram;

IGV5TextureNoAlphaShaderProgram* IGV5TextureNoAlphaShader_CreateProgram(void);

void IGV5TextureNoAlphaShader_Render(ShaderProgram* shaderProgram, void* model, unsigned int nodeIndex, IGV5Light* light, IGV5Matrix *pWorld, IGV5Matrix *mView, IGV5Matrix *mProjection, void* renderInfo);

void IGV5TextureNoAlphaShader_Release(IGV5TextureNoAlphaShaderProgram** textureNoAlphaShaderProgram);

void IGV5TextureNoAlphaShader_SetAlphaThreshold(IGV5TextureNoAlphaShaderProgram* textureNoAlphaShaderProgram, float alphaThreshold);

float IGV5TextureNoAlphaShader_GetAlphaThreshold(IGV5TextureNoAlphaShaderProgram* textureNoAlphaShaderProgram);

#ifdef __cplusplus
}
#endif

#endif