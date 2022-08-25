
#ifndef __IGV5GOURAUDSHADOWSHADER_H
#define __IGV5GOURAUDSHADOWSHADER_H

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

	GLuint shadowLightDirLoc;
	GLuint shadowSpaceMatrixLoc;
	GLuint biasValueLoc;
	GLuint shadowIntensityLoc;

	// Attributes
	float alphaThreshold;

} IGV5GouraudShadowShaderProgram;

IGV5GouraudShadowShaderProgram* IGV5GouraudShadowShader_CreateProgram(void);

void IGV5GouraudShadowShader_Render(ShaderProgram* shaderProgram, void* model, unsigned int nodeIndex, IGV5Light* light, IGV5Matrix *pWorld, IGV5Matrix *mView, IGV5Matrix *mProjection, void* renderInfo);

void IGV5GouraudShadowShader_Release(IGV5GouraudShadowShaderProgram** gouraudShadowShaderProgram);

void IGV5GouraudShadowShader_SetAlphaThreshold(IGV5GouraudShadowShaderProgram* gouraudShadowShaderProgram, float alphaThreshold);

float IGV5GouraudShadowShader_GetAlphaThreshold(IGV5GouraudShadowShaderProgram* gouraudShadowShaderProgram);

#ifdef __cplusplus
}
#endif

#endif