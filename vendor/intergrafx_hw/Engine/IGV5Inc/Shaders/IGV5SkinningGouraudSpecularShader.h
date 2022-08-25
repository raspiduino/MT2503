
#ifndef __IGV5SKINNINGGOURAUDSPECULARSHADER_H
#define __IGV5SKINNINGGOURAUDSPECULARSHADER_H

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
	GLuint viewProjMatrixLoc;

	GLuint boneCountLoc;
	GLuint boneMatrixArrayLoc;
	GLuint boneVecMatrixArrayLoc;

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

} IGV5SkinningGouraudSpecularShaderProgram;

IGV5SkinningGouraudSpecularShaderProgram* IGV5SkinningGouraudSpecularShader_CreateProgram(void);

void IGV5SkinningGouraudSpecularShader_Render(ShaderProgram* shaderProgram, void* model, unsigned int nodeIndex, IGV5Light* light, IGV5Matrix *pWorld, IGV5Matrix *mView, IGV5Matrix *mProjection, void* renderInfo);

void IGV5SkinningGouraudSpecularShader_Release(IGV5SkinningGouraudSpecularShaderProgram** skinningGouraudSpecularShaderProgram);

void IGV5SkinningGouraudSpecularShader_SetAlphaThreshold(IGV5SkinningGouraudSpecularShaderProgram* skinningGouraudSpecularShaderProgram, float alphaThreshold);

float IGV5SkinningGouraudSpecularShader_GetAlphaThreshold(IGV5SkinningGouraudSpecularShaderProgram* skinningGouraudSpecularShaderProgram);

#ifdef __cplusplus
}
#endif

#endif