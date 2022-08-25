/** 
 *
 *	@file		IGV5MathHelper.h	
 *
 *  @brief		Header file for math helper functions
 *
 *	@author		George Li
 *
*/

#ifndef  __IGV5MATHHELPER_H
#define  __IGV5MATHHELPER_H

#include "IGV5Def.h"
#include "IGV5Matrix.h"
//#include "IGV5UnitTest.h"

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////// Math Definitions /////////////////////////////////////////////////////

#define IG_ATAN2_FACTOR		0.268f			//0.268 = 2 - sqrt(3)
#define IG_SQRT_PRECISION	0.000001f

//////////////////////////////////////////////////////// Math Functions  /////////////////////////////////////////////////////


/*!****************************************************************************
 @fn		sgn
 @param		a			
 @return	Returns the result of the signum function.
 @brief		Takes a float input and determines if it's value is greater than,
				equal to or less than zero. It returns a value within normal
				space to reflect this outcome
******************************************************************************/
float IGV5_Sign(float a);

/*!***************************************************************************
 @fn			IGV5_Sqrt
 @param			m				a value that needs to be used to calculate its 
                                square foot.
 @Return        square foot of the given value. If the input value is 
                invalid (m < 0), return 0;

 @brief			Calculate square foot value of a given value
*****************************************************************************/
float IGV5Math_Sqrt(float m);

/*!***************************************************************************
 @fn			IGV5_ArcTan2
 @param			x				y value for tan(theta). 
 @param			y				x value for tan(theta). 
 @Return        the theta value in radians

 @brief			Calculate tangent value with two factors
*****************************************************************************/
float IGV5Math_ArcTan2 (float x, float y);		//Don't use, need to be unit tested

/*!***************************************************************************
 @fn			IGV5_ArcTan
 @param			x				a tan(theta) value. 
 @Return        the theta value in radians

 @brief			Calculate arc tangent value 
*****************************************************************************/
float IGV5Math_ArcTan(float x);					//Don't use, need to be unit tested

/*!***************************************************************************
 @fn			IGV5_ArcCos
 @param			x				a cos(theta) value. 
 @Return        the theta value in radians

 @brief			Calculate arc cosine value 
*****************************************************************************/
float IGV5Math_ArcCos(float x);					//Don't use, need to be unit tested

/*!***************************************************************************
 @fn			IGV5_ArcSin
 @param			x				a sin(theta) value. 
 @Return        the theta value in radians

 @brief			Calculate arc sine value 
*****************************************************************************/
float IGV5Math_ArcSin(float x);					//Don't use, need to be unit tested

/*!***************************************************************************
 @fn			IGV5Math_GetTranslationMatrixFromMatrix
 @param			matrix			pointer to the source matrix. 
 @param			outMatrix		pointer to a matrix that contains the result
 @Return        0: failed, 1-Succeeded.

 @brief			Extract translation matrix from a transformation matrix. 
*****************************************************************************/
int IGV5Math_GetTranslationMatrixFromMatrix(IGV5Matrix *matrix, IGV5Matrix *outMatrix);

/*!***************************************************************************
 @fn			IGV5Math_GetTranslationFromMatrix
 @param			matrix			pointer to the source matrix. 
 @param			outScale		pointer to a vector that contains the result
 @Return        0: failed, 1-Succeeded.

 @brief			Extract translation vector from a transformation matrix. 
*****************************************************************************/
int IGV5Math_GetTranslationFromMatrix(IGV5Matrix *matrix, Vec3 *outPosition);

/*!***************************************************************************
 @fn			IGV5Math_GetScaleFromMatrix
 @param			matrix			pointer to the source matrix. 
 @param			outMatrix		pointer to a matrix that contains the result
 @Return        0: failed, 1-Succeeded.
 
 @brief			Extract scale matrix from a transformation matrix. 
*****************************************************************************/
int IGV5Math_GetScaleMatrixFromMatrix(IGV5Matrix *matrix, IGV5Matrix *outMatrix);

/*!***************************************************************************
 @fn			IGV5Math_GetScaleFromMatrix
 @param			matrix			pointer to the source matrix. 
 @param			outScale		pointer to a vector that contains the result
 @Return        0: failed, 1-Succeeded.

 @brief			Extract scale vector from a transformation matrix. 
*****************************************************************************/
int IGV5Math_GetScaleFromMatrix(IGV5Matrix *matrix, Vec3 *outScale);

/*!***************************************************************************
 @fn			IGV5Math_GetRotationMatrixFromMatrix
 @param			matrix			pointer to the source matrix. This matrix can 
                                be a transform matrix that includes scale and 
								translation information as well.
 @param			outMatrix		pointer to a matrix that contains the result
 @Return        0: failed, 1-Succeeded.

 @brief			Extract rotation matrix from a transformation matrix. 
*****************************************************************************/
int IGV5Math_GetRotationMatrixFromMatrix(IGV5Matrix *matrix, IGV5Matrix *outMatrix);

/*!***************************************************************************
 @fn			IGV5Math_GetRotationXYZFromRotationMatrix
 @param			matrix			pointer to the source matrix. This matrix should 
                                be a pure rotation matrix.
 @param			outRotation1	pointer to a vector that contains result1 for 
                                rotaitons on x, y, and z
 @param			outRotation2	pointer to a vector that contains result2 for 
                                rotaitons on x, y, and z
 @Return        0: failed, 1-Succeeded and suggest to use result 1; 2-Succeeded 
                and suggest to use result 2; 

 @brief			Extract rotation angles on x, y, and z axis from a rotation
                matrix that only has rotation information. The original rotation 
				order must be x, y, z. 
*****************************************************************************/
int IGV5Math_GetRotationXYZFromRotationMatrix(IGV5Matrix *matrix, Vec3 *outRotation1, Vec3 *outRotation2);

/*!***************************************************************************
 @fn			IGV5Math_GetRotationXYZFromRotationMatrix
 @param			matrix			pointer to the source matrix. This matrix can 
                                be a transform matrix that includes scale and 
								translation information as well
 @param			outRotation1	pointer to a vector that contains result1 for 
                                rotaitons on x, y, and z
 @param			outRotation2	pointer to a vector that contains result2 for 
                                rotaitons on x, y, and z
 @Return        0: failed, 1-Succeeded and suggest to use result 1; 2-Succeeded 
                and suggest to use result 2; 

 @brief			Extract rotation angles on x, y, and z axis from a transformation
                matrix that may also contain scale and translation information. 
				The original rotation order must be x, y, z. 
*****************************************************************************/
int IGV5Math_GetRotationXYZFromTransformMatrix(IGV5Matrix *matrix, Vec3 *outRotation, Vec3 *outRotation2);


/*!***************************************************************************
 @fn			IGV5Math_Clamp
 @param			value			The input value that needs to be clamped between min and max
 @param			min				The minimum valid value
 @param			max				The maximum valid value
 @Return        The value that is clamped between min and max

 @brief			This function clamps a float value within a range 
*****************************************************************************/
float IGV5Math_ClampFloat(float value, float min, float max);

#ifdef __cplusplus
}
#endif			


#endif    //end of __IGV5MATHHELPER_H
