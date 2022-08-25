
#ifndef _IGV5BOUNDINGBOX_H_
#define _IGV5BOUNDINGBOX_H_

#include "IGV5Def.h"
#include "IGV5Matrix.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
	Vec3 min;
	Vec3 max;
} IGV5AABB;

typedef struct {
	Vec3 m_vPoints[8];

	Vec3 m_vCenter;
	Vec3 m_vHalfLength;
	Vec3 m_vRotation;
} IGV5BoundingBox;

void IGV5BoundingBox_TransformBoundingBox(IGV5Matrix* transMat, IGV5BoundingBox* originalBB, IGV5BoundingBox* transformedBB);

void IGV5BoundingBox_TransformBoundingBoxNative(IGV5Matrix* transMat, Vec3* originalVertices, Vec3* transformedVertices);

void IGV5BoundingBox_InitAABB(IGV5AABB* aabb);

void IGV5BoundingBox_GetAABB(IGV5BoundingBox* box, IGV5AABB* aabb);

void IGV5BoundingBox_GetAABBNative(Vec3* boxVertices, IGV5AABB* aabb);

unsigned int IGV5BoundingBox_isAABBIntersectedXY(IGV5AABB* aabb1, IGV5AABB* aabb2);

void IGV5BoundingBox_UnionAAABB(IGV5AABB* resultAABB, IGV5AABB* aabb1, IGV5AABB* aabb2);

void IGV5BoundingBox_IntersectionAABB(IGV5AABB* resultAABB, IGV5AABB* aabb1, IGV5AABB* aabb2);

/*!***************************************************************************
 @fn			IGV5BoundingBox_TestBBoxBBox
 @param			p1			pointer to first IGV5BoundingBox
 @param			p2			pointer to second IGV5BoundingBox
 @param			pvOverRate	pointer to Vec3 object to return percentage of overlapping along each axis
 @return		IGV5_TRUE	if collide, IGV5_FALSE if definitely not collide
 @brief			This function performs axis-aligned bounding-box to bounding box collision tes.
*****************************************************************************/
int IGV5BoundingBox_TestBBoxBBox(IGV5BoundingBox *p1, IGV5BoundingBox *p2, Vec3 *pvOverRate);

#ifdef __cplusplus
}
#endif

#endif


