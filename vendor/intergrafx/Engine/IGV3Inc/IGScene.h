/**
@file IGScene.h 
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

#ifndef IG_SCENE_H
#define IG_SCENE_H



#include "IGBackground.h"
#include "IGCamera.h"
#include "IGComDef.h"
#include "IGGroup.h"
#include "IGInputStream.h"
#include "IGMemoryPool.h"
#include "IGRenderer.h"
#include "IGGameObject.h"

#ifdef __cplusplus
extern "C"
{
#endif


extern IGDataCache SceneObjectList;
extern igreal EnabledUpdateObjectBBoxes;
extern IGObjCache PickedGameObjects;


#define MaxBoneScene	50

typedef struct _IGSceneRec
{
    IGBackground*   m_activeBgnd;
    igbool          m_bgndChanged;
    IGGroup*        m_sceneRoot;
    iguint32        m_owner;
    iguint32        m_rdowner;

	IGGroup*		m_AttachedBoneRootGroup[MaxBoneScene];

}   IGScene;


/**
* IGScene constructor.
* Allocates a new IGScene with it's tree rooted at the specified IGGroup.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iRoot
*   Handle to an IGGroup to set as the root node of the IGScene's tree
* @param pErr
*   Stores error code raised by this function
* @return
*   Handle to the newly created IGScene; NULL if creation failed
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hRoot references a previously allocated IGGroup.
*   IGScene* pScene = IGScene_new(pMemPool, hRoot, pErr);
* @endcode
* @see IGScene_destroy
* @see IGScene_destroyAll
*/
IGScene*        IGScene_new             ( IGMemoryPool*         pMemPool, 
                                          IGGroup*              iRoot, 
                                          IGErr*                pErr );

IGScene*        IGScene_fromByteArray   ( IGMemoryPool*         pMemPool, 
                                          const unsigned char*  iByteArray, 
                                          IGObjCache*           iTextureCache, 
                                          IGErr*                pErr );
              
IGScene*        IGScene_fromFile        ( IGMemoryPool*         pMemPool, 
                                          const char*           iFilename, 
                                          IGObjCache*           iTextureCache, 
                                          IGErr*                pErr );

/**
* Shallow IGScene destructor.
* Deallocates an IGScene.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pScene
*   Handle to the IGScene
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @note
*   This function only deallocates the IGScene object itself. Use
*   IGScene_destroyAll to deallocate the entire scene hierarchy under
*   the root node (this frees all runtime resources of the IGScene).
* @par Example:
* @code
*   // Dispose of the IGScene object, but leave the scene tree under the
*   // root node intact.
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // pScene references a previously allocated IGScene.
*   if (pScene) {
*     IGScene_destroy(pMemPool, pScene, pErr);
*   }
* @endcode
* @see IGScene_new
* @see IGScene_destroyAll
*/
void            IGScene_destroy         ( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          IGErr*                pErr );

/**
* Deep IGScene destructor.
* Deallocates all objects in an IGScene's tree, including the IGScene
* object itself.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pScene
*   Handle to IGScene object
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // pScene references a previously allocated IGScene.
*   if (pScene) {
*     IGScene_destroyAll(pMemPool, pScene, pErr);
*   }
* @endcode
* @see IGScene_destroy
* @see IGScene_new
*/
void            IGScene_destroyAll      ( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          IGErr*                pErr );

/**
* Gets the IGNode with the specified name and type in an IGScene.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pScene
*   Pointer to the IGScene
* @param iName
*   Name of the IGNode to grab
* @param iType
*   Type of the object we are searching for
* @param pErr
*   Stores error code raised by this function
* @return
*   Handle to the IGNode with the specified name; NULL if no such IGNode
*   exists in the IGScene's tree
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // pScene references a previously allocated IGScene.
*   IGCamera* hCam = (IGCamera*) IGScene_get(pMemPool, pScene, "My Camera", IGNODE_CAMERA, pErr);
* @endcode
* @see IGScene_getList
*/
IGNode*         IGScene_get             ( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          const char*           iName, 
                                          IGNodeType            iType, 
                                          IGErr*                pErr );
/**
* Gets a list of all IGNodes of a specific type in an IGScene
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pScene
*   Pointer to the IGScene
* @param iType
*   Type of the object we are searching for
* @param pErr
*   Stores error code raised by this function
* @return
*   List of all nodes of that type
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // pScene references a previously allocated IGScene.
*   IGObjCache* hLights = IGScene_getList(pMemPool, pScene, IGNODE_LIGHT, pErr);
* @endcode
* @see IGScene_get
*/
IGObjCache*     IGScene_getList         ( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          IGNodeType            iType, 
                                          IGErr*                pErr );
/**
* Gets an IGScene's currently active IGBackground
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pScene
*   Pointer to the IGScene
* @param pErr
*   Stores error code raised by this function
* @return
*   Pointer to the IGScene's active IGBackground; NULL if no active
*   IGBackground exists
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // pScene references a previously allocated IGScene.
*   IGBackground* hBack = IGScene_getActiveBackground(pMemPool, pScene, pErr);
* @endcode
* @see IGScene_setActiveBackground
*/
IGBackground*   IGScene_getActiveBackground
                                        ( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          IGErr*                pErr );
/**
* Sets the active IGBackground of an IGScene.
* Subsequent calls to IGScene_render will render the active IGBackground.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pScene
*   Pointer to the IGScene
* @param pBgnd
*   Handle to the IGBackground to use
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   IGBackground* hBack = ...
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // pScene references a previously allocated IGScene.
*   // hBack references a previously allocated IGBackground.
*   IGScene_setActiveBackground(pMemPool, pScene, hBack, pErr);
* @endcode
* @see IGScene_getActiveBackground
*/
void            IGScene_setActiveBackground
                                        ( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          IGBackground*         pBgnd, 
                                          IGErr*                pErr );
/**
* Gets an IGScene's currently active IGCamera.
* The IGScene is rendered from the viewpoint of the active IGCamera.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pScene
*   Pointer to the IGScene
* @param pErr
*   Stores error code raised by this function
* @return
*   Handle to the IGScene's active IGCamera; NULL if no active IGCamera exists
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // pScene references a previously allocated IGScene.
*   IGCamera* hCam = IGScene_getActiveCamera(pMemPool, pScene, pErr);
*
*   // Manipulate the active IGCamera (move it forward)
*   IGNode_forwardBackward(pMemPool, (IGNode*) hCam, IG_ONE_HUNDREDTH, pErr);
* @endcode
* @see IGScene_setActiveCamera
*/
IGCamera*       IGScene_getActiveCamera ( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          IGErr*                pErr );
/**
* Sets the active IGCamera in an IGScene.
* Subsequent calls to IGScene_render will render the IGScene from the
* specified IGCamera's viewpoint.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pScene
*   Pointer to the IGScene
* @param iName
*   Name of the IGCamera to activate; must be the name of an IGCamera in the
*   IGScene's tree
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // pScene references a previously allocated IGScene.
*   // Activate the IGCamera named "myCam".
*   IGScene_setActiveCamera(pMemPool, pScene, "myCam", pErr);
* @endcode
* @see IGScene_getActiveCamera
*/
void            IGScene_setActiveCamera ( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          const char*           iName, 
                                          IGErr*                pErr );

void			IGScene_getCameraMatrix ( IGMemoryPool*			pMemPool,
										  IGScene*				pScene,
										  igreal				viewMatrix[12],
										  IGErr*				pErr );
/**
* Gets an IGScene's root node.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pScene
*   Pointer to the IGScene
* @param pErr
*   Stores error code raised by this function
* @return
*   Handle to the root node of the scene tree
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // pScene references a previously allocated IGScene.
*   IGGroup* hRoot = IGScene_getSceneRoot(pMemPool, pScene, pErr);
* @endcode
* @see IGScene_setSceneRoot
*/
IGGroup*        IGScene_getSceneRoot    ( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          IGErr*                pErr );
/**
* Sets an IGScene's root node.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pScene
*   Pointer to the IGScene
* @param iRoot
*   Pointer to node to set as the root of the scene tree
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // pScene references a previously allocated IGScene.
*   // hRoot references a previously allocated IGGroup.
*   IGScene_setSceneRoot(pMemPool, pScene, hNewRoot, pErr);
* @endcode
* @see IGScene_getSceneRoot
*/
void            IGScene_setSceneRoot    ( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          IGGroup*              iRoot, 
                                          IGErr*                pErr );

IGScene*        IGScene_init            ( IGMemoryPool*         pMemPool, 
                                          IGInputStream*        iStream, 
                                          IGObjCache*           iTextureCache, 
                                          IGErr*                pErr );

void            IGScene_read            ( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          IGInputStream*        iStream, 
                                          IGObjCache*           iTextureCache, 
                                          IGErr*                pErr );

/**
* Renders an IGScene to a destination buffer.
* The IGScene is rendered into the destination buffer set by
* IGRenderer_setTarget. If no render target has been set, this function
* has no effect.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pScene
*   Handle to the IGScene
* @param pRender
*   Handle to the renderer
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // pRender references a previouslay allocated IGRenderer.
*   // pVideoMem points to a previously set up top-down video memory buffer of size 400 by 400 pixels.
*   // Z-buffering is disabled.
*   IGRenderer_setTarget(pMemPool, pRender, pVideoMem, 400L, 400L, IGBOOL_TRUE, IGBOOL_FALSE, pErr);
*
*   // pScene references a previously allocated IGScene.
*   // Render one frame to the destination buffer.
*   IGScene_render(pMemPool, pScene, pRender, pErr);
*
*   // Now pVideo contains a 2D rendering of the scene.
* @endcode
* @see IGRenderer_setTarget
*/
void            IGScene_render          ( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          IGRenderer*           pRender, 
                                          IGErr*                pErr );
/**
* Renders the active background of the IGScene to a destination buffer.
* If there is no active background, the screen will be drawn white.
* If no render target has been set, this function has no effect.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pScene
*   Pointer to the IGScene
* @param pRender
*   Pointer to the renderer
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hRender references a previouslay allocated IGRenderer.
*   // pVideoMem points to a previously set up top-down video memory buffer 
*   // of size 400 by 400 pixels.
*   // Z-buffering is disabled.
*   IGRenderer_setTarget(pMemPool, hRender, pVideoMem, 400L, 400L, IGBOOL_TRUE, IGBOOL_FALSE, pErr);
*
*   // pScene references a previously allocated IGScene.
*   // Render one frame to the destination buffer.
*   IGScene_renderBackground(pMemPool, pScene, hRender, pErr);
*
*   // Now pVideo contains a 2D rendering of the scene's active background.
* @endcode
* @see IGRenderer_setTarget
*/
void            IGScene_renderBackground( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          IGRenderer*           pRender, 
                                          IGErr*                pErr );

void			IGScene_renderBackgroundRegion
										( IGMemoryPool*			pMemPool,
										  IGScene*				pScene,
										  IGRenderer*			pRender,
										  IGErr*				pErr );

/**
* Prepare 3D rendering.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pScene
*   Pointer to the IGScene
* @param pRender
*   Pointer to the renderer
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @see IGScene_end
*/
void            IGScene_begin           ( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          IGRenderer*           pRender, 
                                          IGErr*                pErr );

/**
* Finalize 3D rendering.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pScene
*   Pointer to the IGScene
* @param pRender
*   Pointer to the renderer
* @param pRect
*   Pointer to a IGRect, this function fill minimum bounding rectangle region of 3D objects on screen
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @see IGScene_end
*/
igbool          IGScene_end             ( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          IGRenderer*           pRender, 
                                          IGRect*               pRect, 
                                          IGErr*                pErr );
/**
* Renders an IGScene (not including the background) to a destination buffer.
* The IGScene is rendered into the destination buffer set by
* IGRenderer_setTarget. If no render target has been set, this function
* has no effect.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pScene
*   Pointer to the IGScene
* @param pRender
*   Pointer to the renderer
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @note
*   This function will not clear the pixel buffer before drawing.
*   Thus it will be overlaid on what ever image is already in the pixel buffer.
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hRender references a previouslay allocated IGRenderer.
*   // pVideoMem points to a previously set up top-down video memory buffer 
*   // of size 400 by 400 pixels.
*   // Z-buffering is disabled.
*   IGRenderer_setTarget(pMemPool,hRender, pVideoMem, 400L, 400L, IGBOOL_TRUE, IGBOOL_FALSE, pErr);
*
*   // pScene references a previously allocated IGScene.
*   // Render one frame to the destination buffer.
*   IGScene_renderForeground(pMemPool, pScene, hRender, pErr);
*
*   // Now pVideo contains a 2D rendering of the scene foreground overlaid
*   // on whatever image it used to contain.
* @endcode
* @see IGRenderer_setTarget
*/
void            IGScene_renderForeground( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          IGRenderer*           pRender, 
                                          IGErr*                pErr );

void            IGScene_renderRegion    ( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          IGRenderer*           pRender, 
                                          IGErr*                pErr );
                                     
void			IGScene_renderObjects
										( IGMemoryPool*			pMemPool,
										  IGScene*				pScene,
										  IGRenderer*			pRender,
										  igreal				viewMatrix[12],
										  IGErr*				pErr );
     
/**
* Replaces a texture in the scene with another texture
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pScene
*   Handle to the IGScene
* @param iOldTex
*   Texture to switch out
* @param iNewTex
*   Texture to switch in
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // pScene references a previously allocated IGScene.
*   // hOldTex references a previously allocated IGTexture. This is the
*   // texture to be replaced.
*   // hNewTex references a previously allocated IGTexture. This is the
*   // texture that is to take the place of hOldTex.
*   IGScene_switchTextures(pMemPool, pScene, hOldTex, hNewTex, pErr);
* @endcode
*/
void            IGScene_switchTextures  ( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene,
                                          IGTexture*            iOldTex, 
                                          IGTexture*            iNewTex, 
                                          IGErr*                pErr );
/**
* Sets an IGScene's world time.
* This world time determines the state of all animated IGGroups.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pScene
*   Pointer to the IGScene.
* @param iAnimTime
*   World time to set
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // pScene references a previously allocated IGScene.
*   // g_worldTime is a previously declared and initialized global
*   // igint32 variable.
*   // Run looping animations continuously.
*   for (;;) {
*     g_worldTime += 100;
*     IGScene_update(pMemPool, pScene, g_worldTime, pErr);
*   }
* @endcode
* @see IGGroup_update
*/
igbool          IGScene_update          ( IGMemoryPool*         pMemPool, 
                                          IGScene*              pScene, 
                                          long                  iAnimTime, 
                                          IGErr*                pErr );
/*
void			IGScene_project			( IGMemoryPool*			pMemPool,
										  IGScene*				pScene,
										  IGCamera*				pCam,
										  igreal				iPos[3],
										  igreal				oPos[2],
									 	  igint32				iScreenW,
										  igint32				iScreenH,
										  IGErr*				pErr );
*/


/**
Attach an IGGroup onto target scene's module. This function will find 
node name identical from source to target and attach there.

@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pSceneTo
  Pointer to target scene
@param pGroupFrom
  Pointer to source group
@param pErr
  Stores error code raised by this function

@return
  void
@par Example:
@code
    // Load the parent scene from the byte array.
    g_scene = IGScene_fromByteArray( &g_mem, g_f1, pCache, &err );

    // Load the child scene from the byte array.
    g_scene2 = IGScene_fromByteArray( &g_mem, g_f2, pCache, &err );
    // get the first child node under "Scene Root" in g_scene2
    pGroupFrom = (IGGroup*)IGScene_get( &g_mem, g_scene2, "Scene Root", IGNODE_GROUP, &err );
    pGroupFrom = (IGGroup*)IGGroup_getFirstChild( (IGGroup*)pNodeFrom );

    IGScene_attachGroup(&g_mem, g_scene, pNodeFrom, &err);
@endcode
@see IGScene_detachGroup, IGScene_isAttachable
*/
void IGScene_attachGroup( IGMemoryPool* pMemPool, IGScene* pSceneTo, IGGroup* pGroupFrom, IGErr* pErr );

void IGScene_attachGroupAutoScale(IGMemoryPool *pMemPool, IGScene* pSceneTo, IGGroup* pGroupFrom, IGErr* pErr );

/**
Detach an IGGroup from target scene's module. This function will find 
node name identical from source to target and detach it.

@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pSceneTo
  Pointer to target scene
@param pGroupFrom
  Pointer to source group
@param pErr
  Stores error code raised by this function

@return
  void
@par Example:
@code
    IGScene_detachGroup( &g_mem, g_scene, pGroupFrom, &err );
@endcode
@see IGScene_attachGroup, IGScene_isAttachable
*/
void IGScene_detachGroup( IGMemoryPool* pMemPool, IGScene* pSceneTo, IGGroup* pGroupFrom, IGErr* pErr );

/**
Test an IGGroup, find if the node name identical from source to target.

@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pSceneTo
  Pointer to target scene
@param pGroupFrom
  Pointer to source group
@param pErr
  Stores error code raised by this function

@return
  Return is the pGroupFrom attachable to the pSceneTo.
@par Example:
@code
    IGScene_isAttachable( &g_mem, g_scene, pNodeFrom, &err );
@endcode
@see IGScene_attachGroup, IGScene_detachGroup
*/
igbool IGScene_isAttachable( IGMemoryPool* pMemPool, IGScene* pSceneTo, IGGroup* pGroupFrom, IGErr* pErr );


//Attach With Bone Group
void IGScene_attachBoneGroup( IGMemoryPool* pMemPool, IGScene* pSceneTo, IGScene* pSceneFrom, IGGroup* pGroupFrom, IGErr* pErr );

//Detach With Bone Group
void IGScene_detachBoneGroup( IGMemoryPool* pMemPool, IGScene* pSceneTo, IGScene* pSceneFrom, IGGroup* pGroupFrom, IGErr* pErr );


void IGScene_AddToGameObjectList(IGMemoryPool* pMemPool, IGGameObject *pObj, IGErr* pErr);
IGGameObject * IGScene_RemoveGameObject(IGMemoryPool* pMemPool, int index, IGErr* pErr);		//Remove the object from game object list and return it
const IGGameObject *IGScene_GetGameObject(IGMemoryPool* pMemPool, int index, IGErr* pErr);		//Simply return the game object by its index on the game object list
const IGDataCache *IGScene_GetGameObjectList(IGMemoryPool* pMemPool, IGErr* pErr);
void IGScene_ClearGameObjectList(IGMemoryPool* pMemPool, IGErr* pErr);
void IGSecene_UpdateGameObjects(IGMemoryPool* pMemPool, IGErr* pErr);
void IGScene_UpdateGameObjectBBoxes(IGMemoryPool* pMemPool, IGErr* pErr);
void IGScene_EnableUpdateGameObjectBBoxes(void);
void IGScene_DisableUpdateGameObjectBBoxes(void);
igreal IGScene_IsUpdatingGameObjectBBoxesEnabled(void);

typedef struct _IGPickedObject
{
	IGGameObject *	m_pObject;
	IGObjCache		m_PickedMeshNodes;
} IGPickedObject;

void IGScene_ClearPickedObjects(IGMemoryPool *pMemPool, IGErr* pErr);
IGObjCache *IGScene_PickSceneObjects(IGMemoryPool *pMemPool, IGPoint *pickPoint, IGErr* pErr);

/**
* Reset EnaledUpdateObjetBBoxes = IGBOOL_FALSE;
* Clear SceneObjectList and PickedGameObjects;
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
*/
void IGScene_ResetGameObjects(IGMemoryPool *pMemPool, IGErr *pErr );

#ifdef __cplusplus
}
#endif

#endif//IG_SCENE_H

