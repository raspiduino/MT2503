
#ifndef __IGV5GOURAUDSHADER_H
#define __IGV5GOURAUDSHADER_H

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
	GLuint transMatrixLoc;
	GLuint normalMatrixLoc;
	GLuint mvpMatrixLoc;

	GLuint lightCountLoc;
	GLuint lightTypeLoc;
	GLuint lightPosDirLoc;
	GLuint lightColorLoc;

	// Fragment Shader variable locations
	GLuint sceneAmbientLoc;
	GLuint sceneDiffuseLoc;
	GLuint opacityLoc;
	GLuint alphaThresholdLoc;

	// Attributes
	float alphaThreshold;

} IGV5GouraudShaderProgram;

IGV5GouraudShaderProgram* IGV5GouraudShader_CreateProgram(void);

void IGV5GouraudShader_Render(ShaderProgram* shaderProgram, void* model, unsigned int nodeIndex, IGV5Light* light, IGV5Matrix* pWorld, IGV5Matrix* mView, IGV5Matrix* mProjection, void* renderInfo);

void IGV5GouraudShader_Release(IGV5GouraudShaderProgram** gouraudShaderProgram);

void IGV5GouraudShader_SetAlphaThreshold(IGV5GouraudShaderProgram* gouraudShaderProgram, float alphaThreshold);

float IGV5GouraudShader_GetAlphaThreshold(IGV5GouraudShaderProgram* gouraudShaderProgram);

#ifdef __cplusplus
}
#endif

#endif