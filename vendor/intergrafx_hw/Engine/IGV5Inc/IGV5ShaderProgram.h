
#ifndef __IGV5SHADERPROGRAM_H
#define __IGV5SHADERPROGRAM_H

#include "IGV5Light.h"
#include "IGV5Matrix.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _ShaderProgram{
	void (*render)(struct _ShaderProgram* shaderProgram, void* model, unsigned int nodeIndex, IGV5Light* light, IGV5Matrix *pWorld, IGV5Matrix *mView, IGV5Matrix *mProjection, void* renderInfo);
} ShaderProgram;

#ifdef __cplusplus
}
#endif

#endif