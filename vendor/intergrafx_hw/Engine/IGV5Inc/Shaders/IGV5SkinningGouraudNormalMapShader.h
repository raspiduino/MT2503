
#ifndef __IGV5SKINNINGGOURAUDNORMALMAPSHADER_H
#define __IGV5SKINNINGGOURAUDNORMALMAPSHADER_H

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

} IGV5SkinningGouraudNormalMapShaderProgram;

IGV5SkinningGouraudNormalMapShaderProgram* IGV5SkinningGouraudNormalMapShader_CreateProgram(void);

void IGV5SkinningGouraudNormalMapShader_Render(ShaderProgram* shaderProgram, void* model, unsigned int nodeIndex, IGV5Light* light, IGV5Matrix *pWorld, IGV5Matrix *mView, IGV5Matrix *mProjection, void* renderInfo);

void IGV5SkinningGouraudNormalMapShader_Release(IGV5SkinningGouraudNormalMapShaderProgram** skinningGouraudNormalMapShaderProgram);

void IGV5SkinningGouraudNormalMapShader_SetAlphaThreshold(IGV5SkinningGouraudNormalMapShaderProgram* skinningGouraudNormalMapShaderProgram, float alphaThreshold);

float IGV5SkinningGouraudNormalMapShader_GetAlphaThreshold(IGV5SkinningGouraudNormalMapShaderProgram* skinningGouraudNormalMapShaderProgram);

#ifdef __cplusplus
}
#endif

#endif