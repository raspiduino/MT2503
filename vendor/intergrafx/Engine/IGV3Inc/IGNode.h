/**
@file IGNode.h 
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
#ifndef IG_NODE_H
#define IG_NODE_H

#include "IGMemoryPool.h"
#include "IGObjCache.h"
#include "IGObjTable.h"
#include "IGTexture.h"
#include "IGKeyPath.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct _IGNodeRec
{
    char        m_name[ IG_NAMELEN+1 ];
	igreal		m_uvTile;//by for UV tile [2007.8.6]
    IGNodeType  m_type;
    igbool      m_active;
     
    IGObjTable  m_paths;
    IGKeyPath*  m_curPath;
    int         m_start;
    igbool      m_loop;
    
    igreal      m_defPos[ 3 ];
    igreal      m_defOri[ 4 ];
    igreal      m_defScale[ 3 ];
    igreal      m_defSO[ 4 ];
    igreal      m_position[ 3 ];
    igreal      m_oriMat[ 12 ];
    igreal      m_scale[ 3 ];
    igreal      m_soMat[ 12 ];
    igreal      m_soInvMat[ 12 ];
    igreal      m_matrix[ 12 ];
    igreal      m_lvMatrix[ 12 ];
    igreal      m_radius;
    igreal      m_vsBBox[ 6 ];			//Each frames's screen-projected bounding box for mesh or mesh bone

	igreal      m_tMatrix[ 12 ];		//Each frame's transformed world matrix 
	igreal      m_BBox[ 6 ];			//Each frames's bounding box for mesh or mesh bone

	struct _IGNodeRec*		m_pBoneSibling;
	struct _IGNodeRec*		m_pSibling;
} IGNode;

/**
Gets an IGNode's active status.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pNode
  Handle to the IGNode
@param pErr
  Stores error code raised by this function
@return
  @a IGBOOL_TRUE if the IGNode participates in rendering, @a IGBOOL_FALSE otherwise
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // hNode references a previously allocated IGNode.
  igbool active = IGNode_getActive(pMemPool, hNode, pErr);
@endcode
@see IGNode_setActive
*/
igbool      IGNode_getActive    ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  IGErr*        pErr );
/**
Sets an IGNode active or inactive.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pNode
  Handle to the IGNode
@param iActive
  @a IGBOOL_TRUE if the IGNode should be traversed during rendering; @a IGBOOL_FALSE
  otherwise.
@param pErr
  Stores error code raised by this function
@return
  void
@par Example:
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // hNode references a previously allocated IGNode.
  IGNode_setActive(pMemPool, hNode, IGBOOL_TRUE, pErr);
@endcode
@see IGNode_getActive
*/
void        IGNode_setActive    ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igbool        iActive, 
                                  IGErr*        pErr );
                                  
void        IGNode_getDefPosition  
                                ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal*       oPos, 
                                  IGErr*        pErr );

void        IGNode_setDefPosition  
                                ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  const igreal* iPos, 
                                  IGErr*        pErr );
/**
Gets an IGNode's lookAt vector.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pNode
  Handle to the IGNode
@param oLookAt
  The IGNode's lookAt vector is written into this buffer; must have a
  capacity of at least 3 elements
@param pErr
  Stores error code raised by this function
@return
  void
@par Example:
@code
  igreal aLookAt[3];

  // pMemPool points to a previously allocated IGMemoryPool.
  // hNode references a previously allocated IGNode.
  IGNode_getLookAt(pMemPool, hNode, aLookAt, pErr);
@endcode
@see IGNode_setLookAt
@see IGNode_getUp
*/
void        IGNode_getLookAt    ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal*       oLookAt, 
                                  IGErr*        pErr );
/**
Sets an IGNode's lookAt, lookUp, and lookRight vectors.
The lookAt vector will point in the specified direction. The lookUp vector 
will point as near to the positive y axis of the IGNode parent's space as 
possible. The IGNode's lookRight vector is the cross-product of the 
lookAt and lookUp vectors.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param pNode
  Handle to the IGNode
@param iLookAt
  Buffer whose first 3 elements hold the new lookAt vector
@param pErr
  Stores error code raised by this function
@return
  void
@par Example:
@code
  // Set the IGNode to look in the positive x direction.
  igreal const akLookAt[] = {IG_ONE, IG_ZERO, IG_ZERO};

  // pMemPool points to a previously allocated IGMemoryPool.
  // hNode references a previously allocated IGNode.
  IGNode_setLookAt(pMemPool, hNode, akLookAt, pErr);

  // Now the IGNode's lookAt vector points along +x; lookUp points along +y;
  // lookRight points along +z.
@endcode
@see IGNode_getLookAt
@see IGNode_getUp
*/
void        IGNode_setLookAt    ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  const igreal* iLookAt, 
                                  IGErr*        pErr );
/**
* Gets an IGNode's name.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param oName
*   The IGNode's name is written to this buffer; must have a capacity of at
*   least @a MAXNAMELEN + 1 characters (to accommodate the null terminator)
* @param oLen
*   The maximum length of buffer to write name
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   char aNameDest[MAXNAMELEN + 1];
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_getName(pMemPool, hNode, aNameDest, pErr);
*
*   // aNameDest now contains the IGNode's name.
* @endcode
* @see IGNode_setName
* @see MAXNAMELEN
*/
void        IGNode_getName      ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  char*         oName, 
								  unsigned        oLen,
                                  IGErr*        pErr );
/**
* Sets an IGNode's name.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iName
*   Name to set; will only be internally unique up to @a MAXNAMELEN characters
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_setName(pMemPool, hNode, "myObject", pErr);
* @endcode
* @see IGNode_getName
* @see MAXNAMELEN
*/
void        IGNode_setName      ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  const char*   iName, 
                                  IGErr*        pErr );
/**
* Gets an IGNode's position in its parent's space.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param oPos
*   The IGNode's position vector is written into this buffer; must have
*   a capacity of at least 3 elements
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   igreal aObjTrans[3];
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_getTranslation(pMemPool, hNode, aObjTrans, pErr);
* @endcode
* @see IGNode_setPosition
*/
void        IGNode_getPosition  ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal*       oPos, 
                                  IGErr*        pErr );

/**
* Sets an IGNodes's position in its parent's space.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iPos
*   Buffer whose first 3 elements hold the new position vector
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @note
*   Sets an IGNode's position relative to its parent; any existing position
*   is overwritten; to add a cumulative translation on top of the existing
*   position, use IGNode_translateX, IGNode_translateY,
*   IGNode_translateZ, or IGNode_translateXYZ.
* @code
*   igreal const akPos[] = {IG_ONE_HALF, IG_ONE_HALF, IG_ONE_HALF};
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_setPosition(pMemPool, hNode, akPos, pErr);
* @endcode
* @see IGNode_getPosition
*/
void        IGNode_setPosition  ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  const igreal* iPos, 
                                  IGErr*        pErr );
/**
* Gets an IGNode's scale relative to its parent's space.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param oScale
*   The IGNode's scale vector is written into this buffer; must have
*   a capacity of at least 3 elements
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   igreal aObjScale[3];
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_getScale(pMemPool, hNode, aObjScale, pErr);
* @endcode
* @see IGNode_setScale
*/
void        IGNode_getScale     ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal*       oScale, 
                                  IGErr*        pErr );
/**
* Sets the IGNode's scale relative to its parent's space.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iScale
*   Buffer whose first 3 elements specify a scale in each Cartesian direction;
*   each scale component must be in the range [@a IG_ZERO, @a IG_ONE]
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // Unit scaling with respect to parent.
*   igreal const akScale[] = {IG_ONE, IG_ONE, IG_ONE};
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_setScale(pMemPool, hNode, aScale, pErr);           
*		//e.g. Original scale is 2, aScale is 3, then the new scale is 3
*	IGNode_multiplyScale (pMemPool, hNode, aScale, pErr);	  
*		//e.g. Original scale is 2, sScale is 3, then the new scale is 6
* @endcode
* @see IGNode_getScale
*/
void        IGNode_setScale     ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  const igreal* iScale, 
                                  IGErr*        pErr );

void        IGNode_multiplyScale ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  const igreal* iScale, 
                                  IGErr*        pErr );
/**
* Sets an IGNode's orientation.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iAngleAxis
*   Buffer whose first 4 elements specify an angle-axis ({x, y, z, angle})
*   orientation to set
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @note
*   Sets an IGNode's orientation relative to its parent; any existing
*   orientation is overwritten; to add a cumulative rotation on top of the
*   existing orientation, use IGNode_rotateX, IGNode_rotateY,
*   IGNode_rotateZ, or IGNode_rotateXYZ.
* @par Example:
* @code
*   // Set the IGNode's rotation to be 90 degrees about the z axis of its
*   // parent.
*   igreal const akAngleAxis[] = {IG_ZERO, IG_ZERO, IG_ONE, IG_HALF_PI};
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_setOrientation(pMemPool, hNode, anAngleAxis, pErr);
* @endcode
*/
void        IGNode_setOrientation
                                ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  const igreal* iAngleAxis, 
                                  IGErr*        pErr );
/**
* Sets the IGNode's scale orientation relative to its parent's space.
* The scale orientation determines a set of axes with respect to which
* an IGNode's scale takes effect.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iAngleAxis
*   Buffer whose first 4 elements specify an angle-axis ({x, y, z, angle})
*   orientation to set
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // Perform scaling along the 45-degree axes.
*   igreal const akScaleAxes[] = {IG_ONE, IG_ONE, IG_ONE, IG_ONE};
*
*   // Scale to one half in each direction.
*   igreal const akScale[] = {IG_ONE_HALF, IG_ONE_HALF, IG_ONE_HALF};
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_setScaleOrientation(pMemPool, hNode, akScaleAxes, pErr);
*   IGNode_setScale(pMemPool, hNode, akScale, pErr);
* @endcode
* @see IGNode_setScale
*/
void        IGNode_setScaleOrientation
                                ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  const igreal* iAngleAxis, 
                                  IGErr*        pErr );

void		IGNode_getMatrix	( IGMemoryPool* pMemPool,
								  IGNode*		pNode,
								  igreal		oMat[12],
								  IGErr*		pErr );

void		IGNode_getViewPosition
								( IGMemoryPool* pMemPool,
								  IGNode*		pNode,
								  igreal		oPos[3],
								  IGErr*		pErr );

IGNodeType  IGNode_getType      ( IGMemoryPool* pMemPool, 
                                  const IGNode* pNode, 
                                  IGErr*        pErr );
/**
* Gets an IGNode's lookUp vector.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param oUpVec
*   The IGNode's lookUp vector is written into this buffer; must have a
*   capacity of at least 3 elements
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   igreal aLookUp[3];
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_getUp(pMemPool, hNode, aLookUp, pErr);
* @endcode
* @see IGNode_setLookAt
* @see IGNode_getLookAt
*/
void        IGNode_getUp        ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal*       oUpVec, 
                                  IGErr*        pErr );

void        IGNode_setUp        ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal        iUpVec[ 3 ], 
                                  IGErr*        pErr );

/*--------------------------------------------------------------------*\
|   Node transformation
\*--------------------------------------------------------------------*/
/**
* Translates an IGNode forward or backward along its look vector.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iDist
*   Amount to translate by
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_forwardBackward(pMemPool, hNode, IG_ONE_HUNDREDTH, pErr);
* @endcode
* @see IGNode_leftRight
* @see IGNode_upDown
*/
void        IGNode_forwardBackward
                                ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal        iDist, 
                                  IGErr*        pErr );
/**
* Translates an IGNode left or right relative to its look vector.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iDist
*   Amount to translate by
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_leftRight(pMemPool, hNode, IG_ONE_HUNDREDTH, pErr);
* @endcode
* @see IGNode_forwardBackward
* @see IGNode_upDown
*/
void        IGNode_leftRight    ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal        iDist, 
                                  IGErr*        pErr );
/**
* Translates an IGNode up or down relative to its look vector.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iDist
*   Amount to translate by
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_upDown(pMemPool, hNode, IG_ONE_HUNDREDTH, pErr);
* @endcode
* @see IGNode_forwardBackward
* @see IGNode_leftRight
*/
void        IGNode_upDown       ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal        iDist, 
                                  IGErr*        pErr );
/**
* Rotates an IGNode about the x axis of its parent's space.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iAngle
*   Rotation angle (in radians)
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @note
*   This is a cumulative rotation; the rotation occurs on top of the
*   IGNode's existing orientation.
* @code
*   // Rotate the IGNode 90 degrees about the parent's x axis.
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_rotateX(pMemPool, hNode, IG_HALF_PI, pErr);
* @endcode
* @see IGNode_rotateY
* @see IGNode_rotateZ
* @see IGNode_rotateXYZ
*/
void        IGNode_rotateX      ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal        iAngle, 
                                  IGErr*        pErr );
/**
* Rotates an IGNode about the y axis of its parent's space.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iAngle
*   Rotation angle (in radians)
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @note
*   This is a cumulative rotation; the rotation occurs on top of the
*   IGNode's existing orientation.
* @code
*   // Rotate the IGNode 90 degrees about the parent's y axis.
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_rotateY(pMemPool, hNode, IG_HALF_PI, pErr);
* @endcode
* @see IGNode_rotateX
* @see IGNode_rotateZ
* @see IGNode_rotateXYZ
*/
void        IGNode_rotateY      ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal        iAngle, 
                                  IGErr*        pErr );
/**
* Rotates an IGNode about the z axis of its parent's space.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iAngle
*   Rotation angle (in radians)
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @note
*   This is a cumulative rotation; the rotation occurs on top of the
*   IGNode's existing orientation.
* @code
*   // Rotate the IGNode 90 degrees about the parent's z axis.
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_rotateZ(pMemPool, hNode, IG_HALF_PI, pErr);
* @endcode
* @see IGNode_rotateX
* @see IGNode_rotateY
* @see IGNode_rotateXYZ
*/
void        IGNode_rotateZ      ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal        iAngle, 
                                  IGErr*        pErr );
/**
* Rotates an IGNode about an arbitrary axis in its parent's space.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iAngleAxis
*   Buffer whose first 4 elements specify an angle-axis ({x, y, z, angle})
*   rotation
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // Rotate the IGNode 90 degrees about the unit cube's diagonal.
*   igreal const akAngleAxis[] = {
*     ONE_OVER_IG_SQRT_THREE,
*     ONE_OVER_IG_SQRT_THREE,
*     ONE_OVER_IG_SQRT_THREE,
*     IG_HALF_PI
*   };
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_rotateXYZ(pMemPool, hNode, akAngleAxis, pErr);
* @endcode
* @see IGNode_rotateX
* @see IGNode_rotateY
* @see IGNode_rotateZ
*/
void        IGNode_rotateXYZ    ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  const igreal* iAngleAxis, 
                                  IGErr*        pErr );

/**
* Rotates an IGNode about an X, Y, and/or Z in its parent's space.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iAngles
*   Buffer whose first 3 elements specify rotation angels (rx, ry, rz)
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // Rotate the IGNode 90 degrees on X axis and 180 degrees around Z axis.
*   igreal const Angles[] = { IG_HALF_PI, 0, IG_PI };
*   IGNode_rotateXYZ_A(pMemPool, hNode, Angles, pErr);
* @endcode
* @see IGNode_rotateX
* @see IGNode_rotateY
* @see IGNode_rotateZ
*/
void        IGNode_rotateXYZ_A   ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal        iAngles[3], 
                                  IGErr*        pErr );      

/**
* Translates an IGNode in the x direction of its parent's space.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iDist
*   Translation distance
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_translateX(pMemPool, hNode, IG_ONE_EIGHTH, pErr);
* @endcode
* @see IGNode_translateY
* @see IGNode_translateZ
* @see IGNode_translateXYZ
*/
void        IGNode_translateX   ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal        iDist, 
                                  IGErr*        pErr );
/**
* Translates an IGNode in the y direction of its parent's space.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iDist
*   Translation distance
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_translateY(pMemPool, hNode, IG_ONE_EIGHTH, pErr);
* @endcode
* @see IGNode_translateX
* @see IGNode_translateZ
* @see IGNode_translateXYZ
*/
void        IGNode_translateY   ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal        iDist, 
                                  IGErr*        pErr );
/**
* Translates an IGNode in the z direction of its parent's space.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iDist
*   Translation distance
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_translateZ(pMemPool, hNode, IG_ONE_EIGHTH, pErr);
* @endcode
* @see IGNode_translateX
* @see IGNode_translateY
* @see IGNode_translateXYZ
*/
void        IGNode_translateZ   ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal        iDist, 
                                  IGErr*        pErr );
/**
* Translates an IGNode in an arbitrary direction in its parent's space.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iTrans
*   Buffer whose first 3 elements specify a Cartesian translation vector
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   igreal const akTrans[] = {IG_ONE_HALF, IG_ONE_HALF, IG_ONE_HALF};
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_translateXYZ(pMemPool, hNode, akTrans, pErr);
* @endcode
* @see IGNode_translateX
* @see IGNode_translateY
* @see IGNode_translateZ
*/
void        IGNode_translateXYZ ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  const igreal* iTrans, 
                                  IGErr*        pErr );
/**
* Rotates an IGNode about its lookAt vector.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iAngle
*   Rotation angle (in radians) about the lookAt vector; positive means
*   counterclockwise rotation (roll right)
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // Flip the IGNode upside down.
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_roll(pMemPool, hNode, IG_PI, pErr);
* @endcode
* @see IGNode_yaw
* @see IGNode_pitch
*/
void        IGNode_roll         ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal        iAngle, 
                                  IGErr*        pErr );
/**
* Rotates an IGNode about its lookAt vector.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the IGNode
* @param iAngle
*   Rotation angle (in radians) about the lookAt vector; positive means
*   counterclockwise rotation (roll right)
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // Flip the IGNode upside down.
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_roll(pMemPool, hNode, IG_PI, pErr);
* @endcode
* @see IGNode_yaw
* @see IGNode_pitch
*/
void        IGNode_pitch        ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal        iAngle, 
                                  IGErr*        pErr );
/**
* Rotates an IGNode about its lookUp vector.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Handle to the pNode
* @param iAngle
*   Rotation angle (in radians) about the lookUp vector; positive means
*   counterclockwise rotation (yaw left)
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // Make the IGNode look right.
*   IGNode_yaw(pMemPool, hNode, IG_HALF_PI, pErr);
* @endcode
* @see IGNode_roll
* @see IGNode_pitch
*/
void        IGNode_yaw          ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  igreal        iAngle, 
                                  IGErr*        pErr );

/*--------------------------------------------------------------------*\
|   Node animation
\*--------------------------------------------------------------------*/
/**
* Determines if the bounding boxes of two nodes overlap.  Each node must be
* either an unskinned mesh or a bone for a skin, and the call must occur after
* a call to IGScene_render.  Otherwise an IGERR_INVALIDBOUNDINGBOX error is 
* thrown.  Also, the bounding box of a node does not include the bounding 
* boxes of any child nodes.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iNode1
*   Handle to first IGNode object
* @param iNode2
*   Handle to second IGNode object
* @param pErr
*   Stores error code raised by this function
* @return
*   IGBOOL_TRUE if the bounding boxes overlap, IGBOOL_FALSE otherwise.
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode1 references a previously allocated node to be used in the test
*   // for collision.
*   // hNode2 references a second previously allocated node to be used in the 
*   // test for collision.
*   IGNode_collision(pMemPool, (IGNode*) hNode1, (IGNode*) hNode2, pErr);
* @endcode
*/
igbool      IGNode_collision    ( IGMemoryPool* pMemPool, 
                                  IGNode*       iNode1, 
                                  IGNode*       iNode2, 
                                  IGErr*        pErr );

void		IGNode_removeAction	( IGMemoryPool* pMemPool,
								  IGNode*		pNode,
								  const char*	iActionName,
								  IGErr*		pErr );
/**
* Tells every IGNode in a subtree to stop their current action and start the 
* action with the specified name.  IGNodes that do not support the action 
* remain unchanged, and will continue with their previous action, if any.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Root node of the subtree
* @param iActionName
*   Name of the action to start
* @param iAnimTime
*   Time at which to start the action; this determines where in the action's
*   keyframe sequence execution will begin
* @param iIsLooping
*   Whether or not to continuously repeat the action
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   // "ANIMATE0" is the name of an action as listed for hNode in the scene 
*   // hierarchy.
*   // g_worldTime is a previously declared and initialized global
*   // igint32 variable.
*   IGNode_startAction(pMemPool, hNode, "ANIMATE0", g_worldTime, IGBOOL_TRUE, pErr);
* @endcode
* @see IGNode_startAction
* @see IGNode_update
*/
void        IGNode_startAction  ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  const char*   iActionName, 
                                  long          iAnimTime, 
                                  igbool        iIsLooping, 
                                  IGErr*        pErr );

/**
* Tells every IGNode in a subtree to stop their current action and start the 
* action from another subtree with the specified name.  IGNodes that do not 
* support the action remain unchanged, and will continue with their previous 
* action, if any. This function enables sharing aniamtion. Ideally, the two 
* subtrees should be in the same structure. For example, two characters have
* identical skeleton associated with different aniamtions. 
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Root node of the subtree
* @param pSourceNode
*   Root node of the source subtree. This subtree actually provides animation data.
* @param iActionName
*   Name of the action to start
* @param iAnimTime
*   Time at which to start the action; this determines where in the action's
*   keyframe sequence execution will begin
* @param iIsLooping
*   Whether or not to continuously repeat the action
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   // "ANIMATE0" is the name of an action as listed for hNode in the scene 
*   // hierarchy.
*   // g_worldTime is a previously declared and initialized global
*   // igint32 variable.
*   IGNode_startAction(pMemPool, hNode, "ANIMATE0", g_worldTime, IGBOOL_TRUE, pErr);
* @endcode
* @see IGNode_startAction
* @see IGNode_update
*/
void        IGNode_startActionA  ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
								  IGNode*       pSourceNode, 
                                  const char*   iActionName, 
                                  long          iAnimTime, 
                                  igbool        iIsLooping,
                                  IGErr*        pErr );

/**
* Tells every IGNode in a subtree to stop their current action and
* return to their default state.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Root node of the subtree
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_stopAndReset(pMemPool, hNode, pErr);
* @endcode
* @see IGNode_startAction
* @see IGNode_update
*/
void        IGNode_stopAndReset ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  IGErr*        pErr );


/**
* Tells every IGNode in a subtree to stop their current action
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Root node of the subtree
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   IGNode_stopAction(pMemPool, hNode, pErr);
* @endcode
* @see IGNode_startAction
* @see IGNode_update
*/
void IGNode_stopAction (IGMemoryPool* pMemPool, IGNode* pNode, IGErr* pErr );

/**
* Tells every IGNode in a subtree to update its matrix based on 
* the given time. IGNodes currently following a keyframe path will 
* interpolate along the path. IGNodes not following a path will be
* unaffected.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Root node of the subtree.
* @param iAnimTime
*   Current time to update to.
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hNode references a previously allocated IGNode.
*   // g_worldTime is a previously declared and initialized global
*   // igint32 variable.
*   IGNode_update(pMemPool, hNode, g_worldTime, pErr);
* @endcode
* @see IGNode_startAction
* @see IGNode_stopAndReset
*/
igbool      IGNode_update       ( IGMemoryPool* pMemPool, 
                                  IGNode*       pNode, 
                                  long          iAnimTime, 
                                  IGErr*        pErr );


void SetExportAnim(int bExportAnim);

/*--------------------------------------------------------------------*\
|   Search
\*--------------------------------------------------------------------*/
/**
* Gets the IGNode with the specified name and type in a tree.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iRoot
*   Handle to the root of the tree to search.
* @param iName
*   Name of the object we are searching for
* @param iType
*   Type of the object we are searching for
* @param pErr
*   Stores error code raised by this function
* @return
*   Handle to the IGNode with the specified name; NULL if no such IGNode
*   exists in the tree
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hRoot references a previously allocated IGGroup.
*   IGCamera* hCam = (IGCamera*) IGNode_find(pMemPool, hRoot, "My Camera", IGNODE_CAMERA, pErr);
* @endcode
* @see IGNode_findAll
*/
IGNode*     IGNode_find         ( IGMemoryPool* pMemPool, 
                                  IGNode*       iRoot, 
                                  const char*   iName, 
                                  IGNodeType    iType, 
                                  IGErr*        pErr );

/**
* Finds all IGNodes of a certain type in a tree and adds them to an IGObjCache.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iRoot
*   Handle to the root of the tree to search.
* @param iType
*   Type of object to search for.
* @param iNodes
*   Handle to IGObjCache to add IGNodes to.
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hRoot references a previously allocated IGGroup.
*   // hLightCache references a previously allocated IGObjCache.
*   IGNode_findAll(pMemPool, hRoot, IGNODE_LIGHT, hLightCache, pErr);
* @endcode
* @see IGNode_find
*/
void        IGNode_findAll      ( IGMemoryPool* pMemPool, 
                                  IGNode*       iRoot, 
                                  IGNodeType    iType, 
                                  IGObjCache*   iNodes, 
                                  IGErr*        pErr );


void        IGNode_findAllTypes   ( IGMemoryPool* pMemPool, 
                                  IGNode*       iRoot, 
                                  IGObjCache*   iNodes, 
                                  IGErr*        pErr );
/**
* Gets the IGTexture with the specified name in a tree.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iRoot
*   Handle to the root of the tree to search.
* @param iName
*   Name of the desired texture.
* @param pErr
*   Stores error code raised by this function
* @return
*   Handle to the IGTexture with the specified name; NULL if no such IGTexture
*   exists in the tree
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hRoot references a previously allocated IGGroup.
*   IGTexture* hCam = (IGTexture*) IGNode_findTexture(pMemPool, hRoot, "My Tex", pErr);
* @endcode
* @see IGNode_findAllTextures
*/
IGTexture* IGNode_findTexture   ( IGMemoryPool* pMemPool, 
                                  IGNode*       iRoot, 
                                  const char*   iName, 
                                  IGErr*        pErr );
/**
* Finds all IGTextures in a tree and adds them to an IGObjCache.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iRoot
*   Handle to the root of the tree to search.
* @param iTextures
*   Handle to IGObjCache to add IGTextures to.
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hRoot references a previously allocated IGGroup.
*   // hTextures references a previously allocated IGObjCache.
*   IGNode_findAllTextures(pMemPool, hRoot, hTextures, pErr);
* @endcode
*/
void        IGNode_findAllTextures
                                ( IGMemoryPool* pMemPool, 
                                  IGNode*       iRoot, 
                                  IGObjCache*   iTextures, 
                                  IGErr*    pErr );
/**
* Replaces a texture in the tree with another texture
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iRoot
*   Handle to the root of the tree in which to switch textures
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
*   // hRoot references a previously allocated IGGroup.
*   // hOldTex references a previously allocated IGTexture. This is the
*   // texture to be replaced.
*   // hNewTex references a previously allocated IGTexture. This is the
*   // texture that is to take the place of hOldTex.
*   IGNode_switchTextures(pMemPool, hRoot, hOldTex, hNewTex, pErr);
* @endcode
*/
void        IGNode_switchTextures
                                ( IGMemoryPool* pMemPool, 
                                  IGNode*       iRoot, 
                                  IGTexture*    iOldTex, 
                                  IGTexture*    iNewTex, 
                                  IGErr*        pErr );

void		SetExportAnim(int bExportAnim);

/**
* Find a node starting from the root node
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param pNode
*   Pointer to the root node
* @param NodeType
*   Specifies for what type of node you are searching. It enables different type of nodes to share the same name
* @param pNodeName
*	Name of the node being searched
* @param pOutParent
*   If the node has been found, this parameter returns the parent node if it exists, otherwise, it returns NULL.
* @param pOutPreSibling
*   If the node has been found, this parameter returns the previous sibling if it exists, otherwise, it returns NULL.
*   could be its parrent or previous sibling
* @return
*   The found node or NULL (not found) 
*/

IGNode *IGNode_FindNodeByName(IGMemoryPool *pMemPool, 
								   IGNode *pRoot, 
								   IGNodeType NodeType, 
								   char *pNodeName,
								   IGNode **pOutParent,
								   IGNode **pOutPreSibling,
								   IGErr *pErr);  



#ifdef __cplusplus
}
#endif

#endif//IG_NODE_H

