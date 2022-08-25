
#ifndef __IGV5GOURAUDNORMALMAPSHADER_H
#define __IGV5GOURAUDNORMALMAPSHADER_H

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

} IGV5GouraudNormalMapShaderProgram;

IGV5GouraudNormalMapShaderProgram* IGV5GouraudNormalMapShader_CreateProgram(void);

void IGV5GouraudNormalMapShader_Render(ShaderProgram* shaderProgram, void* model, unsigned int nodeIndex, IGV5Light* light, IGV5Matrix* pWorld, IGV5Matrix* mView, IGV5Matrix* mProjection, void* renderInfo);

void IGV5GouraudNormalMapShader_Release(IGV5GouraudNormalMapShaderProgram** gouraudNormalMapShaderProgram);

void IGV5GouraudNormalMapShader_SetAlphaThreshold(IGV5GouraudNormalMapShaderProgram* gouraudNormalMapShaderProgram, float alphaThreshold);
float IGV5GouraudNormalMapShader_GetAlphaThreshold(IGV5GouraudNormalMapShaderProgram* gouraudNormalMapShaderProgram);

#ifdef __cplusplus
}
#endif

#endif