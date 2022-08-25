/******************************************************************************

 @File         IGV5Quaternion.h

 @Title        IGV5Quaternion

 @Version      

 @brief  Quaternion functions for floating and fixed point math.

******************************************************************************/
#ifndef __IGV5QUATERNION_H_
#define __IGV5QUATERNION_H_

#include "IGV5Matrix.h"

/****************************************************************************
** Typedefs
****************************************************************************/

typedef Vec4 IGV5Quaternion;

/****************************************************************************
** Functions
****************************************************************************/

/*!***************************************************************************
 @fn			IGV5MatrixQuaternionIdentityF
 @param		qOut	Identity quaternion
 @brief		Sets the quaternion to (0, 0, 0, 1), the identity quaternion.
*****************************************************************************/
void IGV5Quaternion_Identity(IGV5Quaternion *qOut);

/*!***************************************************************************
 @fn			IGV5MatrixQuaternionRotationAxisF
 @param			qOut	Rotation quaternion
 @param				vAxis	Axis to rotate around
 @param				fAngle	Angle to rotate
 @brief		Create quaternion corresponding to a rotation of fAngle
					radians around submitted vector.
*****************************************************************************/
void IGV5Quaternion_RotationAxis(IGV5Quaternion *qOut, Vec3	*vAxis, float fAngle);


/*!***************************************************************************
 @fn			IGV5MatrixQuaternionToAxisAngleF
 @param				qIn		Quaternion to transform
 @param			vAxis	Axis of rotation
 @param			fAngle	Angle of rotation
 @brief		Convert a quaternion to an axis and angle. Expects a unit
					quaternion.
*****************************************************************************/
void IGV5Quaternion_ToAxisAngle(IGV5Quaternion *qIn, Vec3 *vAxis, float *fAngle);


/*!***************************************************************************
 @fn			IGV5MatrixQuaternionSlerpF
 @param			qOut	Result of the interpolation
 @param				qA		First quaternion to interpolate from
 @param				qB		Second quaternion to interpolate from
 @param				t		Coefficient of interpolation
 @brief		Perform a Spherical Linear intERPolation between quaternion A
					and quaternion B at time t. t must be between 0.0f and 1.0f
*****************************************************************************/
void IGV5Quaternion_Slerp(IGV5Quaternion *qOut, IGV5Quaternion *qA, IGV5Quaternion *qB, float t);



/*!***************************************************************************
 @fn			IGV5MatrixQuaternionNormalizeF
 @param			quat	Vector to normalize
 @brief		Normalize quaternion.
*****************************************************************************/
void IGV5Quaternion_Normalize(IGV5Quaternion *quat);



/*!***************************************************************************
 @fn			IGV5MatrixRotationQuaternionF
 @param		mOut	Resulting rotation matrix
 @param				quat	Quaternion to transform
 @brief		Create rotation matrix from submitted quaternion.
					Assuming the quaternion is of the form [X Y Z W]:

						|       2     2									|
						| 1 - 2Y  - 2Z    2XY - 2ZW      2XZ + 2YW		 0	|
						|													|
						|                       2     2					|
					M = | 2XY + 2ZW       1 - 2X  - 2Z   2YZ - 2XW		 0	|
						|													|
						|                                      2     2		|
						| 2XZ - 2YW       2YZ + 2XW      1 - 2X  - 2Y	 0	|
						|													|
						|     0			   0			  0          1  |
*****************************************************************************/
void IGV5Quaternion_ToRotationMatrix(IGV5Matrix *mOut, IGV5Quaternion *quat);



/*!***************************************************************************
 @fn			IGV5MatrixQuaternionMultiplyF
 @param		qOut	Resulting quaternion
 @param				qA		First quaternion to multiply
 @param				qB		Second quaternion to multiply
 @brief		Multiply quaternion A with quaternion B and return the
					result in qOut.
*****************************************************************************/
void IGV5Quaternion_Multiply(IGV5Quaternion *qOut, IGV5Quaternion *qA, IGV5Quaternion *qB);

#endif

/*****************************************************************************
 End of file (PVRTQuaternion.h)
*****************************************************************************/

