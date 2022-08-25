/** 
 *
 *	@file		IGV5Matrix.h	
 *
 *  @brief		Header file for common IGV5 matrix operations
 *
 *	@author		Simon Ko and Charles Shih-I Yeh
 *
*/

#ifndef  __IGV5MATRIX_H
#define  __IGV5MATRIX_H

#include "IGV5Def.h"

#ifdef __cplusplus
extern "C" {
#endif

/*! @typedef	3x3 matrix */
typedef struct {
    float aElem[9];  /*!< Items are stored in column major order as GL expects them. */
} IGV5Matrix3;

/*! @typedef	4x4 matrix */
typedef struct {	
    float aElem[16];	/*!< Items are stored in column major order as GL expects them. */
} IGV5Matrix;

/*! @fn		IGV5Vec3_Normalize
 @param		vOut		pointer to result Vec3 object
 @retun		vIn			pointer to Vec3 object
 @brief		normalize a Vec3 object

			This funciton normalize Vec3 object. You can pass same Vec3 pointer for vIn and vOut. 
*/
Vec3 *IGV5Vec3_Normalize(Vec3 *vOut, Vec3 *vIn);

/*! @fn		IGV5Vec3_Add
 @param		vOut		pointer to result Vec3 object
 @param		v1			pointer to Vec3 object
 @param		v2			pointer to Vec3 object
 @retun		vOut		pointer to result Vec3 object
 @brief		vOut = v1 + v2  

			This funciton adds v2 to v1 vector.
*/
Vec3 *IGV5Vec3_Add(Vec3 *vOut, Vec3 *v1, Vec3 *v2);

/*! @fn		IGV5Vec3_Subtruct
@param		vOut		pointer to result Vec3 object
 @param		v1			pointer to Vec3 object
 @param		v2			pointer to Vec3 object
 @retun		vOut		pointer to result Vec3 object
 @brief		vOut = v1 - v2

			This funciton subtract v2 vector from v1 vector. 
*/
Vec3 *IGV5Vec3_Subtract(Vec3 *vOut, Vec3 *v1, Vec3 *v2);

/*! @fn		IGV5Vec3_Scale
 @param		vOut		pointer to result Vec3 object
 @param		vIn			pointer to Vec3 object
 @param		scale		scale factor
 @retun		vOut		pointer to result Vec3 object
 @brief		vOut = vIn * scale

			This funciton multi play a scale to the vector. 
*/
Vec3 *IGV5Vec3_Scale(Vec3 *vOut, Vec3 *vIn, float scale);

/*! @fn		IGV5Vec3_CrossProduct
 @param		vOut		pointer to result Vec3 object
 @param		v1			pointer to first Vec3 object
 @param		v2			pointer to second Vec3 object
 @retun		pointer to result Vec3 object
 @brief		Compute cross product of two Vec3 objects

			This funciton computes cross product from two Vec3 objects. 
*/
Vec3 *IGV5Vec3_CrossProduct(Vec3 *vOut, Vec3 *v1, Vec3 *v2);

/*! @fn		IGV5Vec3_DotProduct
 @param		v1			pointer to first Vec3 object
 @param		v2			pointer to second Vec3 object
 @retun		value of dot product 
 @brief		Compute dot product of two Vec3 objects

			This funciton computes dot product from two Vec3 objects. 
*/
float IGV5Vec3_DotProduct(Vec3 *v1, Vec3 *v2);

/*! @fn		IGV5Vec4_DotProduct
 @param		v1			pointer to first Vec4 object
 @param		v2			pointer to second Vec4 object
 @retun		value of dot product 
 @brief		Compute dot product of two Vec4 objects

			This funciton computes dot product from two Vec4 objects. 
*/
float IGV5Vec4_DotProduct(Vec4 *v1, Vec4 *v2);

/*! @fn		IGV5Vec2_Set
 @param		x			x value
 @param		y			y value
 @retun		value of dot product 
 @brief		assign (x,y) to Vec2 object
*/
Vec2 *IGV5Vec2_Set(Vec2 *pResult, float x, float y);

/*! @fn		IGV5Vec3_Set
 @param		x			x value
 @param		y			y value
 @param     z			z value
 @retun		value of dot product 
 @brief		assign (x,y,z) to Vec3 object
*/
Vec3 *IGV5Vec3_Set(Vec3 *pResult, float x, float y, float z);

/*! @fn		IGV5Vec4_Set
 @param		x			x value
 @param		y			y value
 @param     z			z value
 @param     w			w value
 @retun		value of dot product 
 @brief		assign (x,y,z,w) to Vec3 object
*/
Vec4 *IGV5Vec4_Set(Vec4 *pResult, float x, float y, float z, float w);

/*! @fn		IGV5Matrix3_ConstructorFromMatrix
 @param		pDst		pointer to result IGV5Matrix3 object
 @param		pSrc		pointer to source IGV5Matrix
 @retun		pointer to result IGV5Matrix3
 @brief		copy value from an IGV5Matrix object to IGV5Matrix3 object. Only left-top 3x3 elements in whole 4x4 elements are copied.

  The matrix is returned in column-major order
*/
IGV5Matrix3 *IGV5Matrix3_ConstructorFromMatrix(IGV5Matrix3 *pDst, IGV5Matrix *pSrc);

/*! @fn		IGV5Matrix3_Inverse
 @param		pDst		pointer to result IGV5Matrix3 object
 @param		pSrc		pointer to source IGV5Matrix3 object
 @retun		pointer to result IGV5Matrix3
 @brief		inverse an IGV5Matrix3, source and destination can be same IGV5Matrix3 object

  The matrix is returned in column-major order.
*/
IGV5Matrix3 *IGV5Matrix3_Inverse(IGV5Matrix3 *pDst, IGV5Matrix3 *pThis);

/*! @fn		IGV5Matrix3_Transpose
 @param		pDst		pointer to result IGV5Matrix3 object
 @param		pThis		pointer to source IGV5Matrix3 object
 @retun		pointer to result IGV5Matrix3
 @brief		transpose an IGV5Matrix3, source and destination can be same IGV5Matrix3 object

  The matrix is returned in column-major order.
*/
IGV5Matrix3 *IGV5Matrix3_Transpose(IGV5Matrix3 *pDst, IGV5Matrix3 *pThis);

/*! @fn		IGV5Matrix_Identity
 @param		pDst		pointer to source and result IGV5Matrix object
 @retun		pointer to result IGV5Matrix3
 @brief		make IGV5Matrix an identity matrix

  The matrix is returned in column-major order.
*/
IGV5Matrix *IGV5Matrix_Identity(IGV5Matrix *pDst);

/*! @fn		IGV5Matrix_Identity
 @param		pDst		pointer to source and result IGV5Matrix object
 @retun		pointer to result IGV5Matrix
 @brief		transpose an IGV5Matrix

  The matrix is returned in column-major order.
*/
IGV5Matrix *IGV5Matrix_Transpose(IGV5Matrix *pDst);

/*! @fn		IGV5Matrix_Multiply
 @param		pDst		pointer to result IGV5Matrix object
 @param		pL			pointer to left matrix object
 @param		pR			pointer to right matrix object
 @retun		pointer to result IGV5Matrix as (*pL) * (*pR)
 @brief		multiply pL and pR IGV5Matrix

  The matrix is returned in column-major order.
*/
IGV5Matrix * IGV5Matrix_Multiply(IGV5Matrix *pDst, IGV5Matrix *pL, IGV5Matrix *pR);

/*! @fn		IGV5MatrixRotateX
 @param		mOut		pointer to result IGV5Matrix object
 @param		iAngle		rotation angle in radian
 @retun		pointer to rotated IGV5Matrix, same as mOut 
 @brief		Make a rotation matrix rotate iAngle along X axis 

  The matrix is returned in column-major order.
*/
IGV5Matrix *IGV5MatrixRotateX(IGV5Matrix *mOut, float iAngle);

/*! @fn		IGV5MatrixRotateY
 @param		mOut		pointer to result IGV5Matrix object
 @param		iAngle		rotation angle in radian
 @retun		pointer to rotated IGV5Matrix, same as mOut 
 @brief		Make a rotation matrix rotate iAngle along Y axis 

  The matrix is returned in column-major order.
*/
IGV5Matrix *IGV5Matrix_RotateY(IGV5Matrix *mOut, float iAngle);

/*! @fn		IGV5MatrixRotateZ
 @param		mOut		pointer to result IGV5Matrix object
 @param		iAngle		rotation angle in radian
 @retun		pointer to rotated IGV5Matrix, same as mOut 
 @brief		Make a rotation matrix rotate iAngle along Z axis 

  The matrix is returned in column-major order.
*/
IGV5Matrix *IGV5MatrixRotateZ(IGV5Matrix *mOut, float iAngle);

/*! @fn		IGV5MatrixRotateXYZ
 @param		mOut		pointer to result IGV5Matrix object
 @param		iAngleX		rotation angle in radian along x axis
 @param		iAngleY		rotation angle in radian along y axis
 @param		iAngleZ		rotation angle in radian along z axis
 @retun		pointer to rotated IGV5Matrix, same as mOut 
 @brief		Make a rotation matrix 

  The matrix is returned in column-major order.
*/
IGV5Matrix *IGV5Matrix_RotateXYZ(IGV5Matrix *pResult, float iAngleX, float iAngleY, float iAngleZ);

void IGV5Matrix_GetRotation(IGV5Matrix* rotationMat, Vec3* srcVec, Vec3* dstVec);

void IGV5Matrix_GetPerpendicularVector(Vec3* perpendicularVec, Vec3* vec);

/*! @fn		IGV5Matrix_Translate
 @param		mOut		pointer to result IGV5Matrix object
 @param		fX			x axis related distance, 0 means no movement along this axis
 @param		fY			y axis related distance, 0 means no movement along this axis
 @param		fZ			z axis related distance, 0 means no movement along this axis
 @retun		pointer to scaled IGV5Matrix, same as mOut 
 @brief		make a translate matrix

  The matrix is returned in column-major order.
*/
IGV5Matrix *IGV5Matrix_Translate(IGV5Matrix *mOut, float fX, float fY, float fZ);



/*! @fn		IGV5Matrix_Scale
 @param		mOut		pointer to result IGV5Matrix object
 @param		fX			x axis scaling factor, 1.0 means no scaling, 0 means you can not see anything
 @param		fY			y axis scaling factor, 1.0 means no scaling, 0 means you can not see anything
 @param		fZ			z axis scaling factor, 1.0 means no scaling, 0 means you can not see anything
 @retun		pointer to scaled IGV5Matrix, same as mOut 
 @brief		scaling an IGV5Matrix

  The matrix is returned in column-major order
*/
IGV5Matrix *IGV5Matrix_Scale(IGV5Matrix *, float sX, float sY, float sZ);

void IGV5MatrixPrint(IGV5Matrix *);

/*! @fn		IGV5Matrix_Perspective
 @param		mOut		pointer to result IGV5Matrix object
 @param		fFOV		field of view in radian
 @param		fRatio		aspect ration of (width / height)
 @param		fNear		near distance in camera space
 @param		fFar		far distance in camera space
 @retun		pointer to new IGV5Matrix, same as mOut 
 @brief		Make a new perspective projection matrix based on parameters

  The matrix is returned in column-major order.
*/
IGV5Matrix *IGV5Matrix_Perspective(IGV5Matrix *mOut, float fFOV, float fRatio, float fNear, float fFar);

/*! @fn		IGV5Matrix_Orthographic
 @param		mOut		pointer to result IGV5Matrix object
 @param		fLeft		left side
 @param		fRight		right side
 @param		fTop		top side
 @param		fBottom		bottom side
 @param		fNear		near distance in camera space
 @param		fFar		far distance in camera space
 @retun		pointer to new IGV5Matrix, same as mOut 
 @brief		Make a new orthogonal projection matrix based on parameters

  The matrix is returned in column-major order.
*/
IGV5Matrix *IGV5Matrix_Orthographic(IGV5Matrix *mOut, float fLeft, float fRight, float fBottom, float fTop, float fNear, float fFar);

/*! @fn		IGV5Matrix_Orthographic
 @param		pResult		pointer to result IGV5Matrix object
 @param		vEye		eye(camera) position
 @param		vAt			lookat position
 @param		vUp			camera upward direction
 @retun		pointer to new IGV5Matrix, same as pResult 
 @brief		Make a new view matrix based on parameters

  The matrix is returned in column-major order.
*/
IGV5Matrix *IGV5Matrix_LookAtRH(IGV5Matrix *pResult, Vec3 *vEye, Vec3 *vAt, Vec3 *vUp);

/*! @fn		IGV5Matrix_LookUp
 @param		pResult		pointer to result IGV5Matrix object
 @param		vLook		eyesight vector
 @param		vUp			camera upward direction
 @retun		pointer to new IGV5Matrix, same as pResult 
 @brief		Make a new view matrix based on parameters

  The matrix is returned in column-major order.
*/
IGV5Matrix *IGV5Matrix_LookUp(IGV5Matrix *pResult, Vec3 *vLook, Vec3 *vUp);

/*! @fn		IGV5Matrix_TransformHomoVec3
 @param		rhs				pointer to IGV5Matrix object used to transform 4D vector
 @param		vFrom			pointer to Vec4 object to be transformed
 @param		vTo				pointer to target Vec4
 @oparam	w_coordinate	w coordinate use to transform vector. Use 1.0 for position calcualtion and 0.0f for normal caluclation
 @retun		pointer to new IGV5Matrix, same as pResult 
 @brief		Transform a Vec4 vector by IGV5Matrix object. Return value is scaled by w coordinate of calculated matrix (Homogeneous coordinte)

  This function is used to do transform between model space to screen sapce. The matrix is in column-major order. 
*/
void IGV5Matrix_TransformHomoVec3(IGV5Matrix *rhs, Vec3 *vFrom, Vec3 *vTo, float w_coordinate);

/*! @fn		IGV5Matrix_TransformHomoVec3Array
 @param		rhs				pointer to IGV5Matrix object used to transform 4D vector
 @param		vFrom			pointer to Vec4 object to be transformed
 @param		vTo				pointer to target Vec4
 @param		w_coordinate	w coordinate use to transform vector. Use 1.0 for position calcualtion and 0.0f for normal caluclation
 @param		numverts		number of vertices (Vec3s)
 @param		nstride			stride of each vertices
 @retun		pointer to new IGV5Matrix, same as pResult 
 @brief		Transform a Vec4 vector by IGV5Matrix object. Return value is scaled by w coordinate of calculated matrix (Homogeneous coordinte)

  This function is used to do transform between model space to screen sapce. The matrix is in column-major order. 
*/
void IGV5Matrix_TransformHomoVec3Array(IGV5Matrix *rhs, Vec3 *vFrom, Vec3 *vTo, float w_coordinate, unsigned numverts, unsigned nstride);

/*! @fn		IGV5Matrix_TransformVec3Array
 @param		rhs				pointer to IGV5Matrix object used to transform 4D vector
 @param		vFrom			pointer to Vec4 object to be transformed
 @param		vTo				pointer to target Vec4
 @param		w_coordinate	w coordinate use to transform vector. Use 1.0 for position calcualtion and 0.0f for normal caluclation
 @param		numverts		number of vertices (Vec3s)
 @param		nstride			stride of each vertices
 @retun		pointer to new IGV5Matrix, same as pResult 
 @brief		Transform a Vec4 vector by IGV5Matrix object. Return value is unscaled.

  This function is used to do transform between model space to world sapce. The matrix is in column-major order. 
*/
void IGV5Matrix_TransformVec3Array(IGV5Matrix *rhs, Vec3 *vFrom, Vec3 *vTo, float w_coordinate, unsigned numverts, unsigned nstride);

/*! @fn		IGV5Matrix_TransformVec4
 @param		rhs			pointer to IGV5Matrix object used to transform 4D vector
 @param		vFrom		pointer to Vec4 object to be transformed
 @param		vTo			pointer to target Vec4
 @retun		pointer to new IGV5Matrix, same as pResult 
 @brief		Transform a Vec4 vector by IGV5Matrix object. 

  The matrix is in column-major order
*/
void IGV5Matrix_TransformVec4(IGV5Matrix *rhs, Vec4 *vFrom, Vec4 *vTo);

void IGV5Matrix_TransformVec4Raw(IGV5Matrix *rhs, Vec4 *vFrom, Vec4 *vTo);

void IGV5Matrix_TransformVec3(IGV5Matrix3 *rhs, Vec3 *vFrom, Vec3 *vTo);


/*! @fn		IGv5Matrix_RotateAngelAxis
 @param		pResult		pointer to IGV5Matrix object
 @param		angle		rotation angle in radian
 @param		x,y,z		Vec3 			
 @retun		pointer to new IGV5Matrix, same as pResult 
 @brief		Simulate desktop glRotatef()

 Simulates desktop's glRotatef. The matrix is returned in column-major order.
*/
IGV5Matrix *IGv5Matrix_RotateAngelAxis(IGV5Matrix *pResult, float angle, float x, float y, float z);

/*! ***************************************************************************
 @fn		IGV5Matrix_Inverse
 @param		mOut		pointer to IGV5Matrix object
 @param		mIn			pointer to input IGV5Matrix object		
 @retun		pointer to new IGV5Matrix, same as pResult 
 @brief		Calculate inverse IGV5Matrix

 The matrix is returned in column-major order.
*****************************************************************************/
IGV5Matrix *IGV5Matrix_Inverse(IGV5Matrix *mOut, IGV5Matrix *mIn);

/*! ***************************************************************************
 @fn		IGV5Matrix_InverseEx
 @param		mOut		pointer to IGV5Matrix object
 @param		mIn			pointer to input IGV5Matrix object 			
 @retun		pointer to new IGV5Matrix, same as pResult 
 @brief		Calculate inverse IGV5Matrix

 The matrix is returned in column-major order. Calculates multiplicative inverse of this matrix.
 Uses a linear equation solver and the knowledge that M.M^-1=I. Use this fn to calculate the 
 inverse of matrices that IGV5Matrix_Inverse() cannot.
*****************************************************************************/
IGV5Matrix *IGV5Matrix_InverseEx(IGV5Matrix *mOut, IGV5Matrix *mIn);

/*!***************************************************************************
 @fn			IGV5MatrixVec3Lerp
 @param			vOut		pointer to result of interpolated Vec3
 @param				v1		pointer to first vector to interpolate from
 @param				v2		pointer to second vector to interpolate form
 @param				s		Coefficient of interpolation
 @brief		This function performs the linear interpolation based on
					the following formula: V1 + s(V2-V1).
*****************************************************************************/
void IGV5Vec3_Lerp(Vec3 *vOut, Vec3*v1, Vec3 *v2, float s);


void IGV5Math_LinearEqSolve(IGV5VertexType * pRes, IGV5VertexType ** pSrc,  int nCnt);

int IGV5Math_CalculateInfinitePlane(IGV5VertexType* pfVtx,int nStride, Vec4 *pvPlane,IGV5Matrix*  pmViewProjInv,Vec3* pFrom, IGV5VertexType fFar);

/*!***************************************************************************
 @fn			IGV5Math_TestBBoxBBox
 @param			p1			pointer to first IGV5BoundingBox
 @param			p2			pointer to second IGV5BoundingBox
 @param			pvOverRate	pointer to Vec3 object to return percentage of overlapping along each axis
 @return		IGV5_TRUE	if collide, IGV5_FALSE if definitely not collide
 @brief			This function performs axis-aligned bounding-box to bounding box collision tes.
*****************************************************************************/

void IGV5Matrix_CreateReflectionMatrix(Vec3* planePoint, Vec3* planeNormal, IGV5Matrix* reflectionMatrix);

void IGV5Matrix_ToEulerAnglesXYZ(IGV5Matrix* pMat, Vec3* pVec);



#ifdef __cplusplus
}
#endif

#endif  /*  __IGV5MATRIX_H */

