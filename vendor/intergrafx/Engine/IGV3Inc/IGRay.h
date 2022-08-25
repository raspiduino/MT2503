/*---------------------------------------------------------------------------------------

  File:      IGRay.h
  Version:   Nov, 2010  GL

  Copyright: Copyright (c) 2010 InterGrafx, Inc. All Rights Reserved.
---------------------------------------------------------------------------------------*/


#ifndef IGRAY_H
#define IGRAY_H

#include "IGComDef.h" 
#include "IGMemoryPool.h"
#include "IGGameObject.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct tIGRay
{
	igreal mP0[3];		//Start position
	igreal mP1[3];		//End position
} IGRay;

/**
* Checks if a ray intersects with a plane
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param oIntersection
*   if the ray collides with the given plane, returns the intersection point position
* @param ori
*   if the ray collides with the given plane, returns the ri where p(ri) = p0 + ri (p1 - p0)
* @param ray
*   The ray pointer
* @param v0
*   A point's position in the plane
* @param normal
*   The plane's normal
* @param useSegment
*   Test with the ray segment (true) or with a real ray
* @param pErr
*	returns the error code
* @return
*	returns IGBOOL_TRUE, the ray collides with the plane, 
*  otherwise, the ray segment is parallel or in the plane or doesn't interset with the plane 
*/
igbool IGRay_CollideWithPlane(IGMemoryPool* pMemPool,
							igreal oIntersection[3],
							igreal *ori,
							const IGRay *ray,
							const igreal v0[3],
							const igreal normal[3],
							igbool useSegment, //If true, ray segment is used, otherwize, a true ray is used 
							IGErr* pErr);

/**
* Checks if a ray intersects with a bounding box
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param oIntersection
*   if the ray collides with the given plane, returns the nearest intersection point position
* @param oFaceIdx
*   output the face index (0 to 5) on the bounding box. the order is left, forward, right, backward, top, and bottom when
*   The camera position is placed at (0, 0, 0) and looking to +Y direction. +X is right, +Z is up. 
* @param oNormal
*   Outpur the face's normal
* @param ray
*   The ray pointer
* @param bbox
*   The given bounding box
* @param useSegment
*   Test with the ray segment (true) or with a real ray
* @param pErr
*	returns the error code
* @return
*	returns IGBOOL_TRUE, the ray collides with the bounding box, 
*   otherwise, the ray dosn't interset with the bounding box
*/
igbool IGRay_CollideWithBoundingBox(IGMemoryPool* pMemPool, 
								  igreal oIntersection[3],
								  int *oFaceIdx,
								  igreal oNormal[3],
								  const IGRay *ray,
								  const igreal bbox[6],
								  igbool useSegment, //If true, ray segment is used, otherwize, a true ray is used 
								  IGErr* pErr);

/* Use this enums to specify where the the tracing ray returned by IGRay_GetGameObjectTracingRay will start from.
* Example:
*   A game object has a mesh. The position is (0, 0, 0), and the bounding box is MIN(-1, -1, -1) and MAX(0.5, 0, 1).
*   That means mvsBBox[6] = { -1, 0.5, -1, 0.5, -1, 0.5 }
*	Casting a tracing ray to the positive Y direction with the following values gets different rays`start positions:
*		Suppose: Start position: (0, 0, 0); end position (0, 1, 0)
*		         Use IGRAY_FROM_NO_TRANSLATION						get Ray: P0(0, 0, 0), P1(0, 1, 0)
*				 Use IGRAY_FROM_CENTER								get Ray: P0(-0.25, -0.5, 0), P1(-0.25, 0.5, 0)
*				 Use IGRAY_FROM_CENTER | IGRAY_FROM_NEGATIVE_X		get Ray: P0(-1, -0.5, 0), P1(-1, 0.5, 0)
*				 Use IGRAY_FROM_CENTER | IGRAY_FROM_POSITIVE_Y		get Ray: P0(-0.25, 0, 0), P1(-0.25, 0, 0)
*				 Use IGRAY_FROM_POSITIVE_X | IGRAY_FROM_POSITIVE_Y | IGRAY_FROM_POSITIVE_Z				
*																	get Ray: P0(0.5, 0, 1), P1(0.5, 1, 1)
*				 Use IGRAY_FROM_CENTER | IGRAY_FROM_POSITIVE_Y | IGRAY_FROM_NEGATIVE_X				
*																	get Ray: P0(-1, 0, 0), P1(-1, 1, 0)
* You can use any other combinations to cast a tracing ray from different positions on the bounding box. 
*/
typedef enum eTracingRayFrom
{
	IGRAY_FROM_CENTER		= 0x00000001,
	IGRAY_FROM_NEGATIVE_X	= 0x00000010,
	IGRAY_FROM_POSITIVE_X	= 0x00000100,
	IGRAY_FROM_NEGATIVE_Y	= 0x00001000,
	IGRAY_FROM_POSITIVE_Y	= 0x00010000,
	IGRAY_FROM_NEGATIVE_Z	= 0x00100000,
	IGRAY_FROM_POSITIVE_Z	= 0x01000000,
	IGRAY_FROM_NO_TRANSLATION  = 0x10000000 
} IGRayFrom;

/**
* This function uses the center of a game object's bounding box (mesh-based) and the given 
* vector to generate a tracing ray. 
* The standard version uses view-space bounding box Version A uses world-space bounding box
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param oObjRay
*   output the generate tracing ray
* @param pObj
*   the game object
* @param startPos
*   the start position
* @param endPos
*   the end position
* @param pErr
*	returns the error code
*/
void IGRay_GetGameObjectTracingRay(IGMemoryPool* pMemPool, 
								   IGRay *oObjRay,
								   IGGameObject *pObj,								  
								   const igreal startPos[3],
								   const igreal endPos[3],
								   IGRayFrom rayFrom,
								   IGErr* pErr);

void IGRay_GetGameObjectTracingRayA(IGMemoryPool* pMemPool, 
								   IGRay *oObjRay,
								   IGGameObject *pObj,								  
								   const igreal startPos[3],
								   const igreal endPos[3],
								   IGRayFrom rayFrom,
								   IGErr* pErr);

#ifdef __cplusplus
}
#endif

#endif
