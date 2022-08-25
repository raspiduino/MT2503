/*---------------------------------------------------------------------------------------

  File:      IGGameObject.h
  Version:   Sep, 2010  GL

  Copyright: Copyright (c) 2010 InterGrafx, Inc. All Rights Reserved.
---------------------------------------------------------------------------------------*/



#ifndef IG_GAMEOBJECT_H
#define IG_GAMEOBJECT_H

#include "IGComDef.h" 
#include "IGMesh.h"
#include "IGNode.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct tIGGameObject
{
	int			mID;
	IGNode *	mRootNode;
	void *		mAttributes;
	igreal		mScale[3];
	igreal		mRotation[4];		//Axis[3]angle[1]
	igreal		mPosition[3];

	igreal		mvsBBox[6];			//Object bouning box screen-space
	igreal		mBBox[6];			//Object bounding box world-space
	IGObjCache *mMeshes;			//Points to all the mesh nodes
	IGObjCache *mBones;				//Pointers to all bones

} IGGameObject;

IGGameObject *IGNewAGameObject(IGMemoryPool* pMemPool, IGErr* pErr);

void IGFreeGameObject(IGMemoryPool* pMemPool, IGGameObject *pObj, IGErr* pErr);

void IGUpdateGameObject(IGMemoryPool* pMemPool, IGGameObject* pObj, IGErr* pErr);

/**
* Attach a node in the scene to be the root node of the game object
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pObj
*   Handle to the object
* @param pSceneRoot
*   The scene root node. This functions searches the entire scene for the meshes associated with current object 
* @param pNode
*   The scene node that will be the root node of the game object
*/

void IGAttachRootNodeToGameObject(IGMemoryPool* pMemPool, 
								  IGGameObject *pObj, 
								  IGNode *pSceneRoot, 
								  IGNode *pNode, 
								  IGErr* pErr);

/**
* Collision detection for two game objects.
* The standard version uses view-space bounding box Version A uses world-space bounding box
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pObj1
*   Handle to the first object
* @param pObj2
*   Hanlde to the second object
* @param NodeBased
*	This parameter indicates if the collistion detection will use mesh node bounding boxes 
*	for collision detection. If this parameter is true, both game objects' mesh node bounding 
*	boxes will be used for collition detection. That means lower performance. If this parameter 
*	is false, only the game object's bounding box is used for collision detection
* @return
*   true - obj1 collides obj2; false - No colletion detectd
*/

igbool IGGameObjectCollision(IGMemoryPool* pMemPool, 
							  const IGGameObject *pObj1, 
							  const IGGameObject *pObj2, 
							  igbool Bonebased,
							  IGErr* pErr);

igbool IGGameObjectCollisionA(IGMemoryPool* pMemPool, 
							  const IGGameObject *pObj1, 
							  const IGGameObject *pObj2, 
							  igbool Bonebased,
							  IGErr* pErr);

/**
* Find a node starting from the object's root node
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pSceneRoot
*   Pointer to the scene root
* @param pObj
*   Pointer to game object
* @param NodeType
*   Specifies for what type of node you are searching. It enables different type of nodes to share the same name
* @param pNodeName
*	Name of the node being searched
* @param pOutParent
*   If the node has been found, this parameter returns the parent node if it exists, otherwise, it returns NULL.
* @param pOutPreSibling
*   If the node has been found, this parameter returns the previous sibling if it exists, otherwise, it returns NULL.
* @param ObjectMeshIndex
*	If the mesh is found, returns the index of the mesh in the object's mMeshs collection cache
* @return
*   The found node or NULL (not found) 
*/

IGNode *IGGameObjectFindMeshByName(IGMemoryPool *pMemPool, 
								   IGNode *pSceneRoot,
								   IGGameObject *pObj, 
								   IGNodeType NodeType, 
								   char *pNodeName,
								   IGNode **pOutParent,
								   IGNode **pOutPreSibling,
								   int *ObjectMeshIndex,
								   IGErr* pErr);  


/**
* Swith game object meshes.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pSceneRoot1
*   Pointer to the scene root on which object 1 is.
* @param pObj1
*   Hanlde to the first object
* @param MeshNodeName1
*   The mesh node name of the first object
* @param pSceneRoot2
*   Pointer to the scene root on which object 2 is. pSceneRoot2 can equal to pSceneRoot1 or a different scene root
* @param pObj2
*   Hanlde to the second object
* @param MeshNodeName2
*   The mesh node name of the second object
* @return
*   true - Operation succeeded; false - Failed. 
*/

igbool IGSwitchGameObjectMeshNodes(IGMemoryPool* pMemPool,
								    IGNode *pSceneRoot1,
									IGGameObject *pObj1,
									char *MeshNodeName1,
									IGNode *pSceneRoot2,
									IGGameObject *pObj2,
									char *MeshNodeName2, 
									IGErr* pErr);


#ifdef __cplusplus
}
#endif


#endif

