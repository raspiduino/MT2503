/**
@file IGMesh.h  
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
#ifndef IG_MESH_H
#define IG_MESH_H

#include "IGMemoryPool.h"
#include "IGTexture.h"
#include "IGMorphPath.h"
#include "IGDataCache.h"
#include "IGObjTable.h"
#include "IGNode.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct _IGMaterialRec
{
    igbool          m_textured;
    IGShadingMode   m_shading;
    igint32         m_color;
    igreal          m_transparency;
    IGTexture*      m_tex;

} IGMaterial;

typedef struct
{
    IGDataCache     m_texPositions;
    IGDataCache     m_tris;
	int             m_count;
    int             m_matIndex;
}  IGMultiTexData;

typedef struct _IGMeshRec
{
    IGNode          m_super;   
    int             m_flags;   
    int             m_numVerts;
    IGRect          m_screenRect;
    IGDataCache     m_lsPositions;
    IGDataCache     m_positions;
    IGDataCache     m_posFlags;
    IGDataCache     m_bones;
    IGDataCache     m_texPositions;
    IGDataCache     m_mats;
	IGDataCache     m_norms;
	IGMultiTexData  m_multiTex;
	IGDataCache     m_topo;	 
	IGDataCache     m_aux;
	IGDataCache     m_faceFlags;	 

    int             m_numTris;
    IGDataCache     m_tris;
	IGObjTable      m_UVAnimPaths;
	IGUVAnimCollection* m_curUVAnimCollection;
    IGObjTable      m_vertPaths;
    IGMorphPath*    m_curPath;
    int             m_start;
    igbool          m_loop;

} IGMesh;


/*--------------------------------------------------------------------*\
|   IGMesh public interface
\*--------------------------------------------------------------------*/

/**
IGMesh destructor.
Deallocates an existing IGMesh.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pMesh
  Handle to the IGMesh
@param pErr
  Stores error code raised by this function
@return
  void
*/
void        IGMesh_destroy          ( IGMemoryPool* pMemPool, 
                                      IGMesh*       pMesh, 
                                      IGErr*        pErr );
/**
Gets an IGMesh's material.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pMesh
  Handle to the IGMesh
@param iIdx
  Index of the material to be returned
@param pErr
  Stores error code raised by this function
@return
  Requested hMesh material
*/
IGMaterial* IGMesh_getMaterial      ( IGMemoryPool* pMemPool, 
                                      IGMesh*       pMesh, 
                                      int           iIdx, 
                                      IGErr*        pErr );
/**
* Gets the number of materials a mesh has.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pMesh
*   Handle to the IGMesh
* @param pErr
*   Stores error code raised by this function
* @return
*   Number of materials hMesh has
*/
long        IGMesh_getNumMaterials  ( IGMemoryPool* pMemPool, 
                                      IGMesh*       pMesh, 
                                      IGErr*        pErr );
/**
* Gets the screen space rectangle taken up by the mesh when it was last rendered.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pMesh
*   Handle to the IGMesh
* @param pRect
*   Buffer into which will be written the {MIN_X, MAX_X, MIN_Y, MAX_Y} components 
*   of the screen rectangle
* @param pErr
*   Stores error code raised by this function
* @return
*   void
*/
void        IGMesh_getScreenRect    ( IGMemoryPool* pMemPool, 
                                      IGMesh*       pMesh, 
                                      IGRect*       pRect,
                                      IGErr*        pErr );
/**
* Gets the texture space position of one of the vertices in an IGMesh.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pMesh
*   Handle to the IGMesh
* @param iVert
*   Index of the vertex whose texture position will be retrieved
* @param oPos
*   Buffer into which the texture coordinates will be written
* @param pErr
*   Stores error code raised by this function
* @return
*   void
*/
void        IGMesh_getVertexPosUV   ( IGMemoryPool* pMemPool, 
                                      IGMesh*       pMesh, 
                                      long          iVert, 
                                      igreal        oPos[ 2 ], 
                                      IGErr*        pErr );
/**
Sets the position in texture space of one of the vertices in an IGMesh.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pMesh
  Handle to the IGMesh
@param iVert
  Index of the vertex whose texture position will be set
@param iPos
  The u,v coordinates of the new texture position
@param pErr
  Stores error code raised by this function
@return
  void
*/
void        IGMesh_setVertexPosUV   ( IGMemoryPool* pMemPool, 
                                      IGMesh*       pMesh, 
                                      long          iVert, 
                                      const igreal  iPos[ 2 ], 
                                      IGErr*        pErr );
/**
Gets the local space position of one of the vertices in an IGMesh.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pMesh
  Handle to the IGMesh
@param iVert
  Index of the vertex whose position will be retrieved
@param oPos
  Buffer into which the vertex coordinates will be written
@param pErr
  Stores error code raised by this function
@return
  void
*/
void        IGMesh_getVertexPosXYZ  ( IGMemoryPool* pMemPool, 
                                      IGMesh*       pMesh, 
                                      long          iVert, 
                                      igreal        oPos[ 3 ], 
                                      IGErr*        pErr );
/**
Sets the position in local space of one of the vertices in an IGMesh.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pMesh
  Handle to the IGMesh
@param iVert
  Index of the vertex whose position will be set
@param iPos
  Cartesian coordinates of the new position
@param pErr
  Stores error code raised by this function
@return
  void
*/
void        IGMesh_setVertexPosXYZ  ( IGMemoryPool* pMemPool, 
                                      IGMesh*       pMesh, 
                                      long          iVert, 
                                      const igreal  iPos[ 3 ], 
                                      IGErr*        pErr );


/**
  Toggle Environmaent mapping.  
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pMesh
  Handle to the IGMesh
@param pErr
  Stores error code raised by this function
@return
  void
*/


/*--------------------------------------------------------------------*\
|   IGMaterial public interface
\*--------------------------------------------------------------------*/
/**
Gets an IGMaterial's color.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pMat
  Handle to the IGMaterial
@param pErr
  Stores error code raised by this function
@return
  Color of the IGMaterial
@see IGMaterial_setColor
*/
long            IGMaterial_getColor         ( IGMemoryPool* pMemPool, 
                                              IGMaterial*   pMat, 
                                              IGErr*        pErr );
/**
Sets an IGMaterial's color.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pMat
  Handle to the IGMaterial
@param iColor
  Color of the material
@param pErr
  Stores error code raised by this function
@return
  void
@see IGMaterial_getColor
*/
void            IGMaterial_setColor         ( IGMemoryPool* pMemPool, 
                                              IGMaterial*   pMat, 
                                              long          iColor, 
                                              IGErr*        pErr );
/**
Gets an IGMaterial's shading mode.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pMat
  Handle to the IGMaterial
@param pErr
  Stores error code raised by this function
@return
  An IGShadingMode that indicates how the IGMaterial's surfaces should be illuminated
@see IGMaterial_setShadingMode
@see IGShadingMode
*/
IGShadingMode   IGMaterial_getShadingMode   ( IGMemoryPool* pMemPool, 
                                              IGMaterial*   pMat, 
                                              IGErr*        pErr );
/**
Sets an IGMaterial's shading mode.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pMat
  Handle to the IGMaterial
@param iMode
  An IGShadingMode that indicates how the IGMaterial's surfaces should be illuminated
@param pErr
  Stores error code raised by this function
@return
  void
@see IGMaterial_getShadingMode
@see IGShadingMode
*/
void            IGMaterial_setShadingMode   ( IGMemoryPool* pMemPool, 
                                              IGMaterial*   pMat, 
                                              IGShadingMode iMode, 
                                              IGErr*        pErr );
/**
Gets an IGMaterial's texture.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pMat
  Handle to the IGMaterial
@param pErr
  Stores error code raised by this function
@return
  Handle to the IGTexture to get
@see IGMaterial_setTexture
*/
IGTexture*      IGMaterial_getTexture       ( IGMemoryPool* pMemPool, 
                                              IGMaterial*   pMat, 
                                              IGErr*        pErr );
/**
Sets an IGMaterial's texture.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pMat
  Handle to the IGMaterial
@param iTex
  Handle to the IGTexture to set
@param pErr
  Stores error code raised by this function
@return
  void
@see IGMaterial_getTexture
*/
void            IGMaterial_setTexture       ( IGMemoryPool* pMemPool, 
                                              IGMaterial*   pMat, 
                                              IGTexture*    iTex, 
                                              IGErr*        pErr );
/**
Gets an IGMaterial's texturing.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pMat
  Handle to the IGMaterial
@param pErr
  Stores error code raised by this function
@return
  Whether or not the IGMaterial's texture is used
@see IGMaterial_setTexturing
*/
igbool          IGMaterial_getTexturing     ( IGMemoryPool* pMemPool, 
                                              IGMaterial*   pMat, 
                                              IGErr*        pErr );
/**
Sets an IGMaterial's texturing.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pMat
  Handle to the IGMaterial
@param iTextured
  Specifies whether the IGMaterial's texture should (IGBOOL_TRUE) or should not (IGBOOL_FALSE) be used
@param pErr
  Stores error code raised by this function
@return
  void
@see IGMaterial_getTexturing
*/
void            IGMaterial_setTexturing     ( IGMemoryPool* pMemPool, 
                                              IGMaterial*   pMat, 
                                              igbool        iTextured, 
                                              IGErr*        pErr );
/**
Gets an IGMaterial's transparency.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pMat
  Handle to the IGMaterial
@param pErr
  Stores error code raised by this function
@return
  Transparency of the IGMaterial
@see IGMaterial_setTransparency
*/
igreal          IGMaterial_getTransparency  ( IGMemoryPool* pMemPool, 
                                              IGMaterial*   pMat, 
                                              IGErr*        pErr );
/**
Sets an IGMaterial's transparency.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pMat
  Handle to the IGMaterial
@param iTrans
  Specifies the transparency of the IGMaterial
@param pErr
  Stores error code raised by this function
@return
  void
@see IGMaterial_getTransparency
*/
void            IGMaterial_setTransparency  ( IGMemoryPool* pMemPool, 
                                              IGMaterial*   pMat, 
                                              igreal        iTrans, 
                                              IGErr*        pErr );







#ifdef __cplusplus
}
#endif

#endif//IG_MEMORY_POOL_H

