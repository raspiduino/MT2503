
#ifndef __IGV5SKINNINGGOURAUDSHADER_H
#define __IGV5SKINNINGGOURAUDSHADER_H

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

} IGV5SkinningGouraudShaderProgram;

IGV5SkinningGouraudShaderProgram* IGV5SkinningGouraudShader_CreateProgram(void);

void IGV5SkinningGouraudShader_Render(ShaderProgram* shaderProgram, void* model, unsigned int nodeIndex, IGV5Light* light, IGV5Matrix *pWorld, IGV5Matrix *mView, IGV5Matrix *mProjection, void* renderInfo);

void IGV5SkinningGouraudShader_Release(IGV5SkinningGouraudShaderProgram** skinningGouraudShaderProgram);

void IGV5SkinningGouraudShader_SetAlphaThreshold(IGV5SkinningGouraudShaderProgram* skinningGouraudShaderProgram, float alphaThreshold);

float IGV5SkinningGouraudShader_GetAlphaThreshold(IGV5SkinningGouraudShaderProgram* skinningGouraudShaderProgram);

#ifdef __cplusplus
}
#endif

#endif