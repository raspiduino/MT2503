/*!*****************************************************************************

 @File         IGV5Model.h 

 @Title        IGV5Model

 @Version      

 @brief			header file for model stuff

******************************************************************************/

#ifndef __IGV5MODEL_H
#define __IGV5MODEL_H

#include "IGV5BoundingBox.h"
#include "IGV5Light.h"
#include "IGV5Shader.h"
#include "IGV5Matrix.h"
#include "IGV5Texture.h"
#include "IGV5Renderer.h"
#include "IGV5Camera.h"
#include "IGV5Memory.h"
#include "IGV5LoadPODModel.h"
#include "IGV5RenderTarget.h"
#include "IGV5DataCache.h"
#include "math.h"

#ifdef __cplusplus
extern "C" {
#endif

#define IGV5MODEL_ALLOCATE_TEXTURE 0x00000001

/*! @typedef	3D model */
typedef struct IGV5ModelType {

	DWORD m_dwFlags;					/*!< for internal bookkeeping */

	IGV5PODModel m_Scene;			/*!< Proprietary model format */

	IGV5Texture **m_ppTextures;		/*!< texture pointer */
	

	IGV5BoundingBox *m_pWordlBBox;	/*!< world bounding box, calculated after rendering */

	IGV5BoundingBox *m_pScreenBBox;	/*!< screen bounding box, calculated after rendering */

	GLuint*	m_puiVbo;				/*!< vertex buffer object */

	GLuint*	m_puiIndexVbo;			/*!< index buffer object */

	float m_fFrame;					/*!< handle the animation in a time-based manner */

	Vec4 m_vLightDirection;

	int (*m_fnSetTextureCallBack)(struct IGV5ModelType *pModel, int i32NodeIndex);			/*!< callback function called when textur is about to used */
	int (*m_fnLoadTextureCallback)(struct IGV5ModelType *pModel, char *pOldName, unsigned nMaxLen);  /*!< callback function called when textur is about to load */
	void (*m_fnLoopThroughAllMeshNodes)(struct IGV5ModelType *pModel, SPODMesh *pMesh, unsigned iNodeIdx);  /*!< callback function called after model is loaded */

} IGV5Model;

typedef struct {
	IGV5Model* model;
	unsigned char allNode;
	unsigned int* aryNodeIndices;
	unsigned int numOfNode;
} ModelNode;

typedef struct {
	Vec3 shadowLightDir;

	IGV5Matrix projViewMat;
	IGV5Matrix shadowSapceMat;

	ModelNode* aryShadowCaster;
	unsigned int numOfShadowCaster;

	GLenum shadowTextureID;
	float shadowIntensity;
	float biasValue;
} ShadowInfo;

ShadowInfo* IGV5Model_InitShadowInfo(IGV5Camera* camera, Vec3* lightDir, ModelNode* aryModelNode, unsigned int numOfModelNode, float shadowIntensity, float biasValue);

void IGV5Model_ReleaseShadowInfo(ShadowInfo* shadowInfo);

void IGV5Model_RenderFromCameraWithShadow(IGV5Model *pModel, IGV5Light* light, IGV5Camera *pCam, IGV5Matrix *pWorld, ShadowInfo* shadowInfo, unsigned uRenderPass);

void IGV5Model_RenderFromViewPerspectiveWithShadow(IGV5Model *pModel, IGV5Light* light, IGV5Matrix *pWorld, IGV5Matrix *mView, IGV5Matrix *mProjection, ShadowInfo* shadowInfo, unsigned uRenderPass);

void IGV5Model_RenderNodeFromViewPerspectiveWithShadow(IGV5Model *pModel, unsigned int nodeIndex, IGV5Light* light, IGV5Matrix *pWorld, IGV5Matrix *mView, IGV5Matrix *mProjection, ShadowInfo* shadowInfo);

/*!***************************************************************************
 @fn			IGV5Model_Create
 @param			pModel		pointer to IGV5Model object
 @brief			Multiply quaternion A with quaternion B and return the result in qOut.
*****************************************************************************/
IGV5Err IGV5Model_Create(IGV5Model *pModel);

/*!***************************************************************************
 @fn			IGV5Model_UpdateCamera
 @param			pModel			pointer to IGV5Model object
 @param			vFrom			pointer to Vec3 object to get cmaera position
 @param			vTo				pointer to Vec3 object to get cmaera lookat position
 @param			vUp				pointer to Vec3 object to get cmaera upward position
 @param			fFOV			pointer of float variable to get camera FOV
 @param			g_ui32Camera	camera index in model/scene file
 @brief			Get cureent camera setting from model/scene file, if camera is animated, this function also get right setting based on camera animation 
*****************************************************************************/
int IGV5Model_UpdateCamera(IGV5Model *pModel, Vec3 *vFrom, Vec3 *vTo, Vec3 *vUp, float *fFOV, int g_ui32Camera);

/*!***************************************************************************
 @fn			IGV5Model_GetLight
 @param			pModel			pointer to IGV5Model object
 @param			light			pointer to light structure
 @brief			Retrieve all lights information from an IGV5Model
*****************************************************************************/
void IGV5Model_GetLight(IGV5Model *pModel, IGV5Light* light);

/*!***************************************************************************
 @fn			IGV5Model_DownloadGeometry
 @param			pModel			pointer to IGV5Model object
 @brief			Download vertex buffer and index buffer object(s) of this model 
                to hardware
*****************************************************************************/
IGV5Err IGV5Model_DownloadGeometry(IGV5Model *pModel);

/*!***************************************************************************
 @fn			IGV5Model_LoadTextureFromCache
 @param			pModel			pointer to IGV5Model object
 @param			pTexCache		pointer to IGV5Texture cache object
 @brief			Assign preloaded texturemap.
*****************************************************************************/
IGV5Err IGV5Model_LoadTextureFromCache(IGV5Model *pModel, IGV5NameCache *pTexCache);

/*!***************************************************************************
 @fn			IGV5Model_LoadTextureFromFile
 @param			pModel			pointer to IGV5Model object
 @param			pHomePath		pointer to home path
 @brief			Assign preloaded texturemap.
*****************************************************************************/
IGV5Err IGV5Model_LoadTextureFromFile(IGV5Model *pModel, char *pHomePath);

/*!***************************************************************************
 @fn			IGV5Model_LoadFromMemory
 @param			pModel			pointer to IGV5Model object
 @param			pData		    pointer to memory address at beginning of model data
 @param			usize			size (in bytes) of model file
 @brief			Load an IGV5Model from memory address 
*****************************************************************************/
IGV5Err IGV5Model_LoadFromMemory(IGV5Model *pModel,void *pData, unsigned usize);

/*!***************************************************************************
 @fn			IGV5Model_LoadFromFile
 @param			pModel			pointer to IGV5Model object
 @param			pHomePath		"home path" of all content
 @param			pFilename		filename under this home path
 @brief			Load an IGV5Model from content file. You need to download vertex 
                buffer object, load texture by yourself. 
*****************************************************************************/
IGV5Err IGV5Model_LoadFromFile(IGV5Model *pModel, char *pHomePath, char *pFilename);


/*!***************************************************************************
 @fn			IGV5Model_LoadContent
 @param			pModel			pointer to IGV5Model object
 @param			pHomePath		"home path" of all content
 @param			pFilename		filename under this home path
 @brief			Load an IGV5Model from content file 
*****************************************************************************/
IGV5Err IGV5Model_LoadContent(IGV5Model *pModel, char *pHomePath, char *pFilename);

/*!***************************************************************************
 @fn			IGV5Model_LoadContentFromCache
 @param			pModel			pointer to IGV5Model object
 @param			pData		    pointer to memory address at beginning of model data
 @param			usize			size (in bytes) of model file
 @brief			Load an IGV5Model from content file 
*****************************************************************************/
IGV5Err IGV5Model_LoadContentFromCache(IGV5Model *pModel, void *pData, unsigned usize, IGV5NameCache *pTexCache);

/*!***************************************************************************
 @fn			IGV5Model_Unload
 @param			pModel			pointer to IGV5Model object
 @brief			Destroy an IGV5Model 
*****************************************************************************/
void IGV5Model_Unload(IGV5Model *pModel);

/*!***************************************************************************
 @fn			IGV5Model_Update
 @param			pThisRC			current rendering context
 @param			pModel			pointer to IGV5Model object
 @param			fFrameTime		time interval from last time the function been called
 @param			pWorld			pointer to external world matrix object
 @brief			update Model animations and timing stuff 
*****************************************************************************/
void IGV5Model_Update(IGV5RC *pThisRC, IGV5Model *pModel, float fFrameTime, IGV5Matrix *pWorld);

/*!***************************************************************************
 @fn			IGV5Model_RenderShadow
 @param			pModel			pointer to IGV5Model object
 @param			pLightDir		specified light direction. pass NULL to use default light assigned by artist
 @param			pWorld			optional world matrix
 @brief			Render shadow 
*****************************************************************************/
void IGV5Model_RenderShadow(IGV5RC *pThisRC, IGV5Matrix *pWorld, ShadowInfo* shadowInfo);

/*!***************************************************************************
 @fn			IGV5Model_RenderWithCamera
 @param			pModel			pointer to IGV5Model object
 @param			pCam			render from camera
 @param			pWorld			optional world matrix
 @param			uRenderPass		all submeshes with specified pass index will be rendered. 
 @brief			Render from given camera object
*****************************************************************************/
void IGV5Model_RenderWithCamera(IGV5Model *pModel, IGV5Light* light, IGV5Camera *pCam, IGV5Matrix *pWorld, unsigned uRenderPass);

/*!***************************************************************************
 @fn			IGV5Model_RenderWithViewProjection
 @param			pModel			pointer to IGV5Model object
 @param			pWorld			optional world matrix
 @param			mView			pointer to model-view matrix
 @param			mProjection		pointer to projection matrix
 @param			uRenderPass		all submeshes with specified pass index will be rendered. 
 @brief			Render from given model-view and projection matrix
*****************************************************************************/
void IGV5Model_RenderWithViewProjection(IGV5Model *pModel, IGV5Light* light, IGV5Matrix *pWorld, IGV5Matrix *mView, IGV5Matrix *mProjection, unsigned uRenderPass);

void IGV5Model_RenderNodeWithViewProjection(IGV5Model *pModel, unsigned int nodeIndex, IGV5Light* light, IGV5Matrix *pWorld, IGV5Matrix *mView, IGV5Matrix *mProjection);

void IGV5Model_RenderWithViewProjectionList(IGV5Model *pModel, IGV5Light* light, IGV5Matrix *pWorld, IGV5Matrix *mView, IGV5Matrix *mProjection, int *pNodeIdxList);

void IGV5Model_UpdateModelBoundingBox(IGV5Model *pModel, IGV5Matrix *pWorld);

void IGV5Model_UpdateMeshNodeBoundingBox(IGV5Model *pModel, unsigned int nodeIndex, IGV5Matrix *pWorld);


/*!***************************************************************************
 @fn			IGV5Model_ReplaceTexture
 @param			pModel			pointer to IGV5Model object
 @param			pNewTexture		new texture 
 @param			tidx			index of IGV5Texture of this Model
 @brief			Replace specified indexed texture of pModel with new IGV5Texture pointer
*****************************************************************************/
IGV5Texture *IGV5Model_ReplaceTextureByIdx(IGV5Model *pModel, IGV5Texture *pNewTexture, unsigned tidx);

/*!***************************************************************************
 @fn			IGV5Model_GetNodeName
 @param			pModel			pointer to IGV5Model object
 @param			uIdx			node index to retrieve name 
 @brief			Get node name from index
*****************************************************************************/
char *IGV5Model_GetNodeName(IGV5Model *pModel, unsigned uIdx);

/*!***************************************************************************
 @fn			IGV5Model_FindNodeIdxByName
 @param			pThis			Model pointer
 @param			pNodeName		name of node to look for
 @Return		Number of indices used by mesh
 @brief			Return node index. Return -1 if not found.
*****************************************************************************/
int IGV5Model_FindNodeIdxByName(IGV5Model *pThis, char *pNodeName);

/*!***************************************************************************
 @fn			IGV5Model_EnableNodeRendering
 @param			pThis		Model pointer
				NodeIdx		Node index
				bEnable		IGV5_TRUE to render this node, IGV5_FALSE to skip this node for rendering actions
 @Return		old visibility status 
 @brief			Enable or disable rendering actions. However, even this node is set to "not render", it will keep update itself.
				So next time the node is rendered again, it will appear to it's antocipated location. If you want the node continue
				animated from where it was disabled to rendering, also call IGV5Model_EnableNodeAnimation() to stop animation
*****************************************************************************/
int IGV5Model_EnableNodeRendering(IGV5Model *pThis, unsigned NodeIdx, int bEnable);

int IGV5Model_EnableNodeRenderingByName(IGV5Model *pThis, char *pNodeName, int bEnable);

/*!***************************************************************************
 @fn			IGV5Model_EnableNodeAnimation
 @param			pThis		Model pointer
				NodeIdx		Node index
				bEnable		IGV5_TRUE to enable animation, IGV5_FALSE to disable
 @Return		old animation status 
 @brief			Enable or disable animation
*****************************************************************************/
int IGV5Model_EnableNodeAnimation(IGV5Model *pModel, unsigned NodeIdx, int bEnable);

/*!***************************************************************************
 @fn			IGV5Model_EnableNodeAnimationByName
 @param			pModel			pointer to IGV5Model object
 @param			pNodeName		specify name of the node to enable/disable animation 
 @param			bEnable			IGV5_TRUE to enable animation, IGV5_FALSE to disable
 @brief			Enable or disable an IGV5Model sub-node animation, when disable 
				an ongoing animation and re-enable it, it will resume from the 
				frame it has been stopped.
*****************************************************************************/
int IGV5Model_EnableNodeAnimationByName(IGV5Model *pModel, char *pNodeName, int bEnable);

/*!***************************************************************************
 @fn			IGV5Model_SetNodeAnimationSpeed
 @param			pModel			pointer to IGV5Model object
 @param			pNodeName		specify name of the node to adjust speed factor
 @param			fSpeedScale		1.0 = original animation speed.
 @brief			Adjust animation speed factor of a node, it doesn't affect sub-nodes
*****************************************************************************/
void IGV5Model_SetNodeAnimationSpeed(IGV5Model *pModel, char *pNodeName, float fSpeedScale);

/*!***************************************************************************
 @fn			IGV5Model_SetNodeAnimationFrameByName
 @param			pThis		Model pointer
				pNodeName	Node name to look for
				bEnable		IGV5_TRUE to enable animation, IGV5_FALSE to disable
 @Return		old animation status 
 @brief			Directly set node animation frames by specifying node name
*****************************************************************************/
void IGV5Model_SetNodeAnimationFrameByName(IGV5Model *pModel, char *pNodeName, float fNodeFrame);

void IGV5Model_SetMeshNodeBoneAnimationFrameByName(IGV5Model* model, char* nodeName, float frame);

/*!***************************************************************************
 @fn			IGV5Model_ResetNodeTransform
 @param			pModel		Model pointer
				idx			Node index
 @brief			Reset local node transform in Model
*****************************************************************************/
void IGV5Model_ResetNodeTransform(IGV5Model *pModel, unsigned idx);

/*!***********************************************************************
 @fn		IGV5Model_SetNodePosition
 @param		idx			node index
 @param		x			related distance of x
 @param		y			related distance of y
 @param		z			related distance of z
 @brief		Update node position related to parent node
*************************************************************************/
void IGV5Model_SetNodePosition(IGV5Model *pModel, unsigned idx, float x, float y, float z);

/*!***********************************************************************
 @fn		IGV5Model_SetNodePositionByName
 @param		pModel		pointer to IGV5PODModel
 @param		pNodeName	the name of node to set position
 @param		x			related position of x (to it's parent)
 @param		y			related position of y (to it's parent)
 @param		z			related position of z (to it's parent)
 @brief		Update related position of this node to it's parent
*************************************************************************/
void IGV5Model_SetNodePositionByName(IGV5Model *pModel, char *pNodeName, float x, float y, float z);

/*!***********************************************************************
 @fn		IGV5Model_SetNodeRotation
 @param		pModel		pointer to IGV5PODModel
 @param		idx			node index
 @param		x			related rotation angle of x
 @param		y			related rotation angle  of y
 @param		z			related rotation angle  of z
 @brief		Update relative node rotation (to its parent)
*************************************************************************/
void IGV5Model_SetNodeRotation(IGV5Model *pModel, unsigned idx, float x, float y, float z);

/*!***********************************************************************
 @fn		IGV5Model_SetNodeRotationByName
 @param		pModel		pointer to IGV5PODModel
 @param		pNodeName	the name of node to set position
 @param		x			related rotation angle of x
 @param		y			related rotation angle  of y
 @param		z			related rotation angle  of z
 @brief		Update relative node rotation (to its parent)
*************************************************************************/
void IGV5Model_SetNodeRotationByName(IGV5Model *pModel, char *pNodeName, float x, float y, float z);

/*!***********************************************************************
 @fn		IGV5Model_SetNodeScale
 @param		pModel		pointer to IGV5PODModel
 @param		idx			node index
 @param		x			related scale factor of x
 @param		y			related scale factor of y
 @param		z			related scale factor  of z
 @brief		Update relative node scale (to its parent)
*************************************************************************/
void IGV5Model_SetNodeScale(IGV5Model *pModel, unsigned idx, float x, float y, float z);

/*!***********************************************************************
 @fn		IGV5Model_SetNodeScaleByName
 @param		pModel		pointer to IGV5PODModel
 @param		pNodeName	the name of node to set position
 @param		x			related scale of x
 @param		y			related scale of y
 @param		z			related scale of z
 @brief		Update relative node scale (to its parent)
*************************************************************************/
void IGV5Model_SetNodeScaleByName(IGV5Model *pModel, char *pNodeName, float x, float y, float z);

/*!***********************************************************************
 @fn		IGV5Model_GetNodeWorldMatrix
 @param		pModel		pointer to IGV5PODModel
 @param		idx			index of node
 @param		pResult		world matrix of node
 @brief		Calculate and return world matrix of node with specified index
*************************************************************************/
void IGV5Model_GetNodeWorldMatrix(IGV5Model *pModel, unsigned idx, IGV5Matrix *pResult);

/*!***********************************************************************
 @fn		IGV5Model_GetNodeWorldMatrixByName
 @param		pModel		pointer to IGV5PODModel
 @param		pNodeName	the name of node to set position
 @param		pResult		world matrix of node
 @brief		Calculate and return world matrix of node with specified name
*************************************************************************/
void IGV5Model_GetNodeWorldMatrixByName(IGV5Model *pModel, char *pNodeName, IGV5Matrix *pResult);

/*!***********************************************************************
 @fn		IGV5Model_GetNodeWorldPos
 @param		pModel		pointer to IGV5PODModel
 @param		idx			index of node
 @param		pResult		world matrix of node
 @brief		Calculate and return world matrix of node with specified index
*************************************************************************/
void IGV5Model_GetNodeWorldPos(IGV5Model *pModel, unsigned idx, Vec3 *vPosition);

/*!***********************************************************************
 @fn		IGV5Model_SetNodeMatrixByName
 @param		pModel			pointer to IGV5PODModel
 @param		pNodeName		node name
 @param		pLocalMatrix	local matrix for Node
 @brief		Assign local transformation matrix directly to specified node
*************************************************************************/
void IGV5Model_SetNodeMatrixByName(IGV5Model *pModel, char *pNodeName, IGV5Matrix *pLocalMatrix);

void IGV5Model_SetNodeMatrix(IGV5Model *pModel, unsigned idx, IGV5Matrix *pLocalMatrix);

/*!***********************************************************************
 @fn		IGV5Model_GetNodeWorldPosByName
 @param		pModel		pointer to IGV5PODModel
 @param		idx			index of node
 @param		pResult		world matrix of node
 @brief		Calculate and return world matrix of node with specified name
*************************************************************************/
void IGV5Model_GetNodeWorldPosByName(IGV5Model *pModel, char *pNodeName, Vec3 *vPosition);


typedef enum {
	
	IGV5HitTestMode_Rough = 0,  // a fastest but very rough hit testing
	IGV5HitTestMode_Mesh,		// a slower, but exact mesh hit testing
	IGV5HitTestMode_Tri			// a slowest, but exact triangle-hit point testing

} IGV5HitTestMode;

void IGV5Model_CalcScreenBBox(IGV5RC* pThisRC, IGV5Model* pModel, IGV5Camera* pCam);


/*!***********************************************************************
 @fn		IGV5Model_Pick
 @param		pThisRC				pointer to render context
 @param		pModel				pointer to IGV5PODModel
 @param		pHitPoint			pointer to 2D (x,y) hit pointer, using screen (device) coordinate
 @param		nHited				number of nodes hited
 @param		HitList				an integer array of hitted model
 @param		nMaxResultWanted	number of object wanted in picking test
 @brief		Find all nodes possibly hitted by screen 2D coordinate (from left-top to right-bottom)
*************************************************************************/
void IGV5Model_Pick( IGV5Model *pModel, IGV5HitTestMode nMode, Vec2 *pHitPoint, int *nHited, int *HitList , int nMaxResultWanted );

/*!***************************************************************************
 @fn			IGV5Model_TestNodes
 @param			pM1			pointer to first IGV5Model
 @param			uIdx1		index of first model's node to test collision
 @param			pM2			pointer to second IGV5Model
 @param			uIdx2		index of second model's node to test collision
 @param			pvOver		pointer to Vec3 object to return overlapping length (absolute value) along each axis
 @return		IGV5_TRUE	if collide, IGV5_FALSE if definitely not collide
 @brief			This function performs axis-aligned bounding-box to bounding box collision test between two IGV5Model's specified node.

 Note: It's AP programmer's responsibility to make sure two nodes are both have their world position calculated. To make sure this, at least
 render them once.
*****************************************************************************/
int IGV5Model_TestNodes(IGV5Model *pM1, unsigned uIdx1, IGV5Model *pM2,  unsigned uIdx2, Vec3 *pvOver);

void IGV5Model_SetNodeFaceToByName(IGV5Model *pModel, char *pName, Vec3 *pTargetPos);

/*!***************************************************************************
 @fn			IGV5Model_UnloadGeometry
 @param			pModel		pointer to first IGV5Model
 @brief			This function unload vertice and index buffers from GPU. It will be called within IGV5Model_Unload().
*****************************************************************************/
void IGV5Model_UnloadGeometry(IGV5Model *pModel);

/*!***************************************************************************
 @fn			IGV5Model_UnloadTextures
 @param			pModel		pointer to first IGV5Model
 @brief			This function unload texture map from GPU. It will be called within IGV5Model_Unload().
*****************************************************************************/
void IGV5Model_UnloadTextures(IGV5Model *pModel);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void IGV5Model_SetAnimatedUVUniform(float fUScrollSpeed, float fVScrollSpeed, float fDeltaTime);

void IGV5Model_SetShadowMapSize(unsigned int shadowMapWidth, unsigned int shadowMapHeight);

void IGV5Model_SetShaderProgramForAllNode(IGV5Model *model, ShaderProgram* modelShaderProgram, ShaderProgram* skinningShaderProgram);

void IGV5Model_SetShaderProgram(IGV5Model *model, unsigned int nodeIndex, ShaderProgram* shaderProgram);

void IGV5Model_SetAlphaTestCmpValue(float fCmpValue);

#ifdef __cplusplus
}
#endif

#endif

