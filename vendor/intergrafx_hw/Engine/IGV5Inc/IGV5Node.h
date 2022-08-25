/******************************************************************************

@file   IGV5Node.h

@brief  Scene Graph node 

******************************************************************************/

#ifndef __IGV5NODE_H
#define __IGV5NODE_H

#include "IGV5Matrix.h"
#include "IGV5Model.h"

#ifdef __cplusplus
extern "C" {
#endif

/*!***************************************************************************
@enum		IGV5NodeEnum
@brief		Enumeration of IGV5Node type 
*****************************************************************************/
typedef enum {

	IGV5NT_NODE,		/*!< generic node which might have some children */
	IGV5NT_CAMERA,		/*!< node associate with a IGV5Camera object */
	IGV5NT_MESH,		/*!< node associate with a IGV5Mesh object */
	IGV5NT_LIGHT,		/*!< node associate with a IGV5Light object */
	IGV5NT_MODEL,		/*!< node associate with a IGV5Model object */
	IGV5NT_USER			/*!< user defined IGV5Node */

} IGV5NodeEnum;

#define IGV5NF_DIRTY 0x00000001
#define IGV5NF_RENDERABLE 0x00001000

/*!***************************************************************************
@struct		IGV5Node
@brief		A structure for scene graph node related information
*****************************************************************************/
typedef struct IGV5NodeType {

	IGV5NodeEnum m_eType;				/*!< node type */
	char m_sName[16];					/*!< name of the node: maximum 16 character */
	struct IGV5NodeType *m_pParent;		/*!< pointer to parent node */
	struct IGV5NodeType *m_pSibling;	/*!< pointer to other same-level neiborgh node(s) */
	struct IGV5NodeType *m_pChild;		/*!< pointer to 1st child */

	Vec3 m_vScale;						/*!< scale value, 1.0 = no scale, 0.0 = disappear */
	Vec3 m_vXYZAngle;					/*!< rotation angle of X, Y, Z */
	Vec3 m_vPosition;					/*!< related position */
	unsigned m_uFlags;					/*!< node update flags used internally */

	IGV5Matrix m_World;					/*!< cached world transform matrix */
	IGV5Matrix m_Local;					/*!< local transform matrix */
	
} IGV5Node;

/*!***************************************************************************
@struct		IGV5ModelNode
@brief		A structure for scene graph node related information
*****************************************************************************/
typedef struct {

	IGV5Node m_Node;				/*!< node structure */
	IGV5Model *m_pModel;			/*!< model object */
	
} IGV5ModelNode;

/*!***********************************************************************
 @fn		IGV5Node_Create
 @param		pN			pointer to IGV5Node structure to be created
 @param		pName		name of node
 @param		pParent		parent node, if any
 @param		pT			pointer to IGV5Matrix object, specified related transform to parent
 @return    IGV5ERR_NONE if succeed
 @brief		Create an IGV5Node 
*************************************************************************/
IGV5Err IGV5Node_Create(IGV5Node *pN, char *pName, IGV5Node *pParent, IGV5Matrix *pT);

/*!***********************************************************************
 @fn		IGV5Node_Update
 @param		pN			pointer to IGV5Node structure to be updated
 @param		fFrameTime	frame time
 @brief		Update node transform and animation status
*************************************************************************/
void IGV5Node_Update(IGV5RC *pThisRC, IGV5Node *pN, float fFrameTime);

/*!***********************************************************************
 @fn		IGV5Node_SetPosition
 @param		x			related distance of x
 @param		y			related distance of y
 @param		z			related distance of z
 @brief		Update node position related to parent node
*************************************************************************/
void IGV5Node_SetPosition(IGV5Node *pN, float x, float y, float z);

/*!***********************************************************************
 @fn		IGV5Node_SetRotation
 @param		pN			pointer to IGV5Node structure
 @param		x			related rotation angle of x
 @param		y			related rotation angle  of y
 @param		z			related rotation angle  of z
 @brief		Update node rotation
*************************************************************************/
void IGV5Node_SetRotation(IGV5Node *pN, float x, float y, float z);

/*!***********************************************************************
 @fn		IGV5Node_SetScale
 @param		pN			pointer to IGV5Node structure 
 @param		x			related scale factor of x
 @param		y			related scale factor of y
 @param		z			related scale factor  of z
 @brief		Update node scale factor
*************************************************************************/
void IGV5Node_SetScale(IGV5Node *pN, float x, float y, float z);

/*!***********************************************************************
 @fn		IGV5Node_Render
 @param		pN			pointer to IGV5Node structure to be rendered
 @param		pCam		pointer to IGV5Camera object
 @brief		Render a renderable (and its children) node
*************************************************************************/
void IGV5Node_RenderWithCamera(IGV5Node *pN, IGV5Camera *pCam);

/*!***********************************************************************
 @fn		IGV5ModelNode_Create
 @param		pN			pointer to IGV5Node structure to be initalized
 @param		pParent		parent node, if any
 @param		pM			pointer to IGV5Model object
 @brief		Create an IGV5Node 
*************************************************************************/
IGV5Err IGV5ModelNode_Create(IGV5ModelNode *pN, char *pName, IGV5Node *pParent, IGV5Model *pM);

/*!***********************************************************************
 @fn		IGV5Node_GetPreviousSibling
 @param		pN				pointer to IGV5Node structure to be initalized
 @brief		Retrieve previous sibling IGV5Node from this IGV5Node
*************************************************************************/
IGV5Node *IGV5Node_GetPreviousSibling(IGV5Node *pN);

/*!***********************************************************************
 @fn		IGV5Node_Release
 @param		pN				pointer to IGV5Node structure to be initalized
 @param		pParent			parent node, if any
 @param		bFreeNodeMem	Set this parameter to IGV5_TRUE to call IGV5Memory_Free() on each subnode pointer
 @brief		Release an IGV5Node and all its children.  
*************************************************************************/
IGV5Err IGV5Node_Release(IGV5Node *pN, int bFreeNodeMem);

#ifdef __cplusplus
}
#endif


#endif

