/*!*****************************************************************************

 @File         IGV5SkyBox.h 

 @Title        IGV5SkyBox

 @Version      

 @brief			header file for model stuff

******************************************************************************/

#ifndef __IGV5SKYBOX_H
#define __IGV5SKYBOX_H

#include "IGV5Shader.h"
#include "IGV5Camera.h"
#include "IGV5Matrix.h"
#include "IGV5Texture.h"
#include "IGV5Renderer.h"
#include "IGV5Memory.h"
#include "IGV5LoadPODModel.h"
#include "IGV5MathHelper.h"
#include "IGV5RuntimeContext.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct IGV5SkyBoxType {

	IGV5Texture *m_pSkyCubeTex;
	IGV5Texture *m_pWaterNormalTex;
	float m_fBoxSize;

	int m_bDrawWater;

	Vec4 m_vWaterColor;
	Vec3 m_vSkyBoxPos;

	IGV5Camera *m_pSceneCamera;

	Vec4 m_vLightDirection;

	float m_fWaterLevel;		//height of water 

	int (*m_fnDrawReflectionModels)(struct IGV5SkyBoxType *pSkyBox, IGV5Matrix *pView, IGV5Matrix *pProjection);

} IGV5SkyBox;

IGV5Err IGV5SkyBox_Create(IGV5SkyBox *pSB);
void IGV5SkyBox_Update(IGV5RC *pThisRC, IGV5SkyBox *pSB, float fTimeInterval);
void IGV5SkyBox_Release(IGV5SkyBox *pSB);

#ifdef __cplusplus
}
#endif

#endif