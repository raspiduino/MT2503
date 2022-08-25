
#ifndef __IGV5GOURAUDSPECULARSHADER_H
#define __IGV5GOURAUDSPECULARSHADER_H

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

	GLuint cameraPosLoc;

	GLuint lightCountLoc;
	GLuint lightTypeLoc;
	GLuint lightPosDirLoc;
	GLuint lightColorLoc;

	// Fragment Shader variable locations
	GLuint sceneAmbientLoc;
	GLuint sceneDiffuseLoc;
	GLuint sceneSpecularLoc;
	GLuint shininessLoc;

	GLuint opacityLoc;
	GLuint alphaThresholdLoc;

	// Attributes
	float alphaThreshold;

} IGV5GouraudSpecularShaderProgram;

IGV5GouraudSpecularShaderProgram* IGV5GouraudSpecularShader_CreateProgram(void);

void IGV5GouraudSpecularShader_Render(ShaderProgram* shaderProgram, void* model, unsigned int nodeIndex, IGV5Light* light, IGV5Matrix* pWorld, IGV5Matrix* mView, IGV5Matrix* mProjection, void* renderInfo);

void IGV5GouraudSpecularShader_Release(IGV5GouraudSpecularShaderProgram** gouraudSpecularShaderProgram);

void IGV5GouraudSpecularShader_SetAlphaThreshold(IGV5GouraudSpecularShaderProgram* gouraudSpecularShaderProgram, float alphaThreshold);

float IGV5GouraudSpecularShader_GetAlphaThreshold(IGV5GouraudSpecularShaderProgram* gouraudSpecularShaderProgram);

#ifdef __cplusplus
}
#endif

#endif