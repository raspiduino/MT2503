
#ifndef __IGV5UVDISPLACEMENTSHADER_H
#define __IGV5UVDISPLACEMENTSHADER_H

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
	GLuint displacementLoc;
	GLuint mvpMatrixLoc;

	// Fragment Shader variable locations
	GLuint opacityLoc;
	GLuint alphaThresholdLoc;

	// Attribute
	float displacement[2];
	float alphaThreshold;

} IGV5UVDisplacementShaderProgram;

IGV5UVDisplacementShaderProgram* IGV5UVDisplacementShader_CreateProgram(void);

void IGV5UVDisplacementShader_Render(ShaderProgram* shaderProgram, void* model, unsigned int nodeIndex, IGV5Light* light, IGV5Matrix *pWorld, IGV5Matrix *mView, IGV5Matrix *mProjection, void* renderInfo);

void IGV5UVDisplacementShader_Release(IGV5UVDisplacementShaderProgram** uvDisplacementShaderProgram);

void IGV5UVDisplacementShader_SetDisplacement(IGV5UVDisplacementShaderProgram* uvDisplacementShaderProgram, float uDisplacement, float vDisplacement);

void IGV5UVDisplacementShader_GetDisplacement(IGV5UVDisplacementShaderProgram* uvDisplacementShaderProgram, float *uDisplacement, float *vDisplacement);

void IGV5UVDisplacementShader_SetAlphaThreshold(IGV5UVDisplacementShaderProgram* uvDisplacementShaderProgram, float alphaThreshold);

float IGV5UVDisplacementShader_GetAlphaThreshold(IGV5UVDisplacementShaderProgram* uvDisplacementShaderProgram);

#ifdef __cplusplus
}
#endif

#endif