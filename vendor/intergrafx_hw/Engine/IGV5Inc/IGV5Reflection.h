
#ifndef __IGV5REFLECTION_H
#define __IGV5REFLECTION_H

#include "IGV5Matrix.h"
#include "IGV5Model.h"
#include "IGV5LoadPODModel.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	unsigned char infinitePlane;
	unsigned char stencilEnabled;

	IGV5Model* reflectionModel;
	unsigned int reflectionPlaneNodeIndex;
	
	ModelNode* aryReflectedNode;
	unsigned int numOfReflectedNode;

	Vec3 reflectionPlaneNormal;
	Vec3 reflectionPlanePoint;

	IGV5Matrix reflectionMatrix;
} ReflectionInfo;

ReflectionInfo* IGV5Reflection_InitReflectionInfo(IGV5Model *pModel, unsigned int reflectionPlaneNodeIndex, ModelNode* aryReflectedNode, unsigned int numOfReflectedNode, unsigned char stencilEnabled);
ReflectionInfo* IGV5Reflection_InitReflectionInfoInfinite(IGV5Model *pModel, Vec3* planeNormal, Vec3* planePoint, ModelNode* aryReflectedNode, unsigned int numOfReflectedNode);

void IGV5Reflection_Release(ReflectionInfo* reflectionInfo);

void IGV5Reflection_RenderReflection(ReflectionInfo* reflectionInfo, IGV5Light* light, IGV5Camera *pCam);
void IGV5Reflection_RenderReflectionPlaneStencil(ReflectionInfo* reflectionInfo, IGV5Light* light, IGV5Camera *pCam);

#ifdef __cplusplus
}
#endif

#endif