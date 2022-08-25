/**
@file IGGroup.h 
@brief 

@par Last updated:


@par Copyright (c) 2005 InterGrafx, Inc. All rights reserved.
InterGrafx CONFIDENTIAL AND PROPRIETARY
@par
This source is the sole property of InterGrafx Inc. Reproduction or
Utilization of this source in whole or in part is forbidden without
The written consent of InterGrafx Inc.

@par History:


@par Description:
more description here.
*/
#ifndef IG_GROUP_H
#define IG_GROUP_H

//#include "IGRenderer.h"
#include "IGNode.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct _IGRendererRec IGRenderer; 

/**
* Represents a group of IGNode objects in a scene.
*/

typedef struct _IGGroup
{
    IGNode      m_super;
	IGNode*		m_pChild;
} IGGroup;

/*--------------------------------------------------------------------*\
|   IGGroup public interface
\*--------------------------------------------------------------------*/
/**
IGGroup constructor.
Allocates a new IGGroup.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pName
  Initial name of IGGroup; will be internally unique up to only
  @a MAXNAMELEN characters
@param pErr
  Stores error code raised by this function
@return
  Handle to newly created IGGroup; NULL if creation failed
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  IGGroup* hGroup = IGGroup_new(pMemPool, "myGroup", pErr);

  if (hGroup) {
    ...
  }
@endcode
@see IGGroup_destroy
*/
IGGroup*    IGGroup_new         ( IGMemoryPool* pMemPool, 
								  const char*     pName, 
                                  IGErr*        pErr );

IGGroup*    IGGroup_alloc		( IGMemoryPool* pMemPool, 
                                  IGErr*        pErr );
/**
IGGroup destructor.
Deallocates an IGGroup.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pGroup
  Handle to the IGGroup
@param pErr
  Stores error code raised by this function
@return
  void
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // hGroup references a previously allocated IGGroup.
  if (hGroup) {
    IGGroup_destroy(pMemPool, hGroup, pErr);
  }
@endcode
@see IGGroup_new
*/
void        IGGroup_destroy     ( IGMemoryPool* pMemPool, 
                                  IGGroup*      pGroup, 
                                  IGErr*        pErr );
/**
Deep IGGroup destructor.
Deallocates an IGGroup and all children in the hierarchy under it.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pGroup
  Handle to the IGGroup.
@param pErr
  Stores error code raised by this function
@return
  void
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // hGroup references a previously allocated IGGroup.
  if (hGroup) {
    IGGroup_destroyAll(pMemPool, hGroup, pErr);
  }
@endcode
@see IGGroup_destroy
*/
void        IGGroup_destroyAll  ( IGMemoryPool* pMemPool, 
                                  IGGroup*      pGroup, 
                                  IGErr*        pErr );
/**
Adds a child IGNode to an IGGroup.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pGroup
  Handle to the IGGroup to which the child should be added
@param pChild
  Handle to the IGNode to add as a child
@param pErr
  Stores error code raised by this function
@return
  void
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // hRoot references a previously allocated IGGroup.
  // hCam references a previously allocated IGCamera.
  IGGroup_addChild(pMemPool, hRoot, (IGNode*) hCam, pErr);
@endcode
@see IGGroup_removeChild
*/
void        IGGroup_addChild    ( IGMemoryPool* pMemPool, 
                                  IGGroup*      pGroup, 
                                  IGNode*       pChild, 
                                  IGErr*        pErr );

/**
Removes a child IGNode from an IGGroup.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pGroup
  Pointer to the IGGroup from which the child should be removed
@param pChild
  Pointer to the child IGNode to remove
@param pErr
  Stores error code raised by this function
@return
   void
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // hRoot references a previously allocated IGGroup.
  // hCam references a previously allocated IGCamera.
  IGGroup_addChild(pMemPool, hRoot, (IGNode*) hCam, pErr);
  IGGroup_removeChild(pMemPool, hRoot, (IGNode*) hCam, pErr);
@endcode
@see IGGroup_addChild
*/
void        IGGroup_removeChild ( IGMemoryPool* pMemPool, 
                                  IGGroup*      pGroup, 
                                  IGNode*       pChild, 
                                  IGErr*        pErr );

/**
Get first child IGNode from an IGGroup.

@param pGroup
    Pointer to the IGGroup
@return
    The child IGNode, if there is no any children, NULL will be returned
@par Example:
@code
    for (pNodeItr = IGGroup_getFirstChild (pParent); pNodeItr != NULL; pNodeItr = IGGroup_getNextChild (pNodeItr))
    {
        // do something for each child node
    }
@endcode
@see IGGroup_getNextChild
*/
IGNode* IGGroup_getFirstChild (IGGroup* pGroup);

/**
Get next child IGNode from an IGGroup.

@param pGroup
    Pointer to the IGGroup
@return
    The child IGNode, if there is no any children, NULL will be returned
@par Example:
@code
    for (pNodeItr = IGGroup_getFirstChild (pParent); pNodeItr != NULL; pNodeItr = IGGroup_getNextChild (pNodeItr))
    {
        // do something for each child node
    }
@endcode
@see IGGroup_getNextChild
*/
IGNode* IGGroup_getNextChild (IGNode* pNode);

/**
Get numbers of child IGNodes of an IGGroup.

@param pMemPool
    Pointer to the memory pool where engine data is stored
@param pGroup
    Pointer to the IGGroup
@param pErr
    Stores error code raised by this function
@return
    Numbers of children
*/
igint32 IGGroup_getChildCount (IGMemoryPool* pMemPool, IGGroup* pGroup, IGErr* pErr);


void            IGGroup_render     ( IGMemoryPool*         pMemPool, 
                                          IGGroup*              pGroup, 
                                          IGRenderer*           pRender, 
                                          IGErr*                pErr );

void            IGGroup_renderObjects	(	IGMemoryPool*	pMemPool,
											IGGroup*        pGroup, 
											IGRenderer*		pRender,
											igreal			viewMatrix[12],
											IGErr*			pErr );


#ifdef __cplusplus
}
#endif

#endif//IG_GROUP_H

