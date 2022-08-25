/**
@file IGMathUtil.h  
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
#ifndef IG_MATH_UTIL_H
#define IG_MATH_UTIL_H


#include "IGComDef.h"


#ifdef __cplusplus
extern "C"
{
#endif

/**
    * @def IG_ZERO
    * The quantity 0 as an igreal.
    * @see igreal
    */

/**
    * @def IG_ONE
    * The quantity 1 as an igreal.
    * @see igreal
    */

/**
    * @def IG_TWO
    * The quantity 2 as an igreal.
    * @see igreal
    */

/**
    * @def IG_FOUR
    * The quantity 4 as an igreal.
    * @see igreal
    */

/**
    * @def IG_ONE_HALF
    * The quantity 0.5 as an igreal.
    * @see igreal
    */

/**
    * @def IG_ONE_FOURTH
    * The quantity 0.25 as an igreal.
    * @see igreal
    */

/**
    * @def IG_THREE_FOURTHS
    * The quantity 0.75 as an igreal.
    * @see igreal
    */

/**
    * @def IG_ONE_EIGHTH
    * The quantity 0.125 as an igreal.
    * @see igreal
    */

/**
    * @def IG_THREE_EIGHTHS
    * The quantity 0.375 as an igreal.
    * @see igreal
    */

/**
    * @def IG_FIVE_EIGHTHS
    * The quantity 0.625 as an igreal.
    * @see igreal
    */

/**
    * @def IG_SEVEN_EIGHTHS
    * The quantity 0.875 as an igreal.
    * @see igreal
    */

/**
    * @def IG_ONE_HUNDREDTH
    * The quantity 0.01 as an igreal.
    * @see igreal
    */

/**
    * @def IG_PI
    * The quantity 3.14159 as an igreal.
    * @see igreal
    */

/**
    * @def IG_TWO_PI
    * The quantity 6.28319 as an igreal.
    * @see igreal
    */

/**
    * @def IG_HALF_PI
    * The quantity 1.57080 as an igreal.
    * @see igreal
    */

/**
    * @def IG_TENTH_PI
    * The quantity 0.31415927 as an igreal.
    * @see igreal
    */

/**
    * @def IG_HUNDREDTH_PI
    * The quantity 0.031415927 as an igreal.
    * @see igreal
    */

#if defined(IG_FLOATING) // 8 significant decimal digits

#define IG_ZERO 0.0f

#define IG_ONE  1.0f
#define IG_TWO  2.0f
#define IG_FOUR 4.0f

#define IG_ONE_HALF 0.5f

#define IG_ONE_FOURTH    0.25f
#define IG_THREE_FOURTHS 0.75f

#define IG_ONE_EIGHTH    0.125f
#define IG_THREE_EIGHTHS 0.375f
#define IG_FIVE_EIGHTHS  0.625f
#define IG_SEVEN_EIGHTHS 0.875f

#define IG_ONE_HUNDREDTH 0.01f

#define IG_PI           3.1415927f
#define IG_TWO_PI       6.2831853f
#define IG_HALF_PI      1.5707963f
#define IG_TENTH_PI     0.31415927f
#define IG_HUNDREDTH_PI 0.031415927f
#define IG_THOUSANDTH_PI 0.003141593f

#define IG_ATAN2_FACTOR  0.268f

#else

#define IG_ZERO 0L

#define IG_ONE		32768L
#define IG_TWO		65536L
#define IG_THREE	98304L
#define IG_FOUR		131072L
#define IG_FIVE		163840L
#define IG_SEVEN	229376L

#define IG_ONE_HALF 16384L

#define IG_ONE_FOURTH     8192L
#define IG_THREE_FOURTHS 24576L

#define IG_ONE_EIGHTH     4096L
#define IG_THREE_EIGHTHS 12288L
#define IG_FIVE_EIGHTHS  20480L
#define IG_SEVEN_EIGHTHS 28672L

#define IG_ONE_HUNDREDTH 328L

#define IG_PI         102944L
#define IG_TWO_PI     205887L
#define IG_HALF_PI     51472L
#define IG_FORTH_PI	   25736L
#define IG_SIXTH_PI    17157L
#define IG_TENTH_PI    10294L
#define IG_HUNDREDTH_PI 1029L
#define IG_THOUSANDTH_PI  64L

#define IG_ATAN2_FACTOR   8782L		//0.268 = 2 - sqrt(3)
#define IG_SQRTROOT_THREE 56754L    //sqrt(3)

#endif

/**
    * @def IG_FLOOR
    *   Returns the greatest integer less than or equal to the argument.
    * @param X
    *   Argument whose floor will be returned
    * @return
    *   Floor of @a X as a machine-dependent @a int
    * @par Example:
    * @code
    *   igreal x = IG_FOUR + IG_ONE_HALF;
    *   igreal y = IG_FOUR + IG_ONE;
    *
    *   int xFloor = IG_FLOOR(x); // 4
    *   int yFloor = IG_FLOOR(y); // 5
    * @endcode
    */

/**
    * @def IG_UPCAST
    *   Casts a number into a format with more accuracy but less range.
    *   Has no effect nothing in floating-point mode.
    * @param X
    *   Number in arbitrary 32-bit format (31 - xfb).xfb
    * @param Y
    *   Number of fractional bits to add to format
    * @return
    *    X in in (31 - xfb - @a Y).(xfb + @a Y) format
    * @par Example:
    * @code
    *    igreal xUp = IG_UPCAST(9000L, 2); // 36000L
    * @endcode
    * @see IG_DOWNCAST
    */

/**
    * @def IG_DOWNCAST
    *   Casts a number into a format with less accuracy but more range.
    *   Has no effect in floating-point mode.
    * @param X
    *   Number in arbitrary 32-bit format (31 - xfb).xfb
    * @param Y
    *   Number of fractional bits to subtract from format
    * @return
    *    X in in (31 - xfb + @a Y).(xfb - @a Y) format
    * @par Example:
    * @code
    *    igreal xDown = IG_DOWNCAST(9000L, 2); // 2250L
    * @endcode
    * @see IG_UPCAST
    */

/**
    * @def IG_HALVE
    *   Divides a number by 2.
    * @param X
    *   Number to halve
    * @return
    *    @a X / 2
    * @par Example:
    * @code
    *   igreal xHalf = IG_HALVE(IG_FOUR); // IG_TWO
    * @endcode
    * @see IG_DOUBLE
    */

/**
    * @def IG_DOUBLE
    *   Multiplies a number by 2.
    * @param X
    *   Number to double
    * @return
    *    2 * @a X
    * @par Example:
    * @code
    *   igreal xDouble = IG_DOUBLE(IG_TWO); // IG_FOUR
    * @endcode
    * @see IG_HALVE
    */

#if defined(IG_FLOATING)

#define IG_FLOOR(X) ((int)(X))							//TODO (George): Is this correct? IG_FLOOR_EX(X) is recommended
#define IG_CEIL(X) ((int)(X) + (((X) < 0) ? 1 : 0))		//TODO (George): Is this correct? IG_CEIL_EX(X) is recommended

#define IG_FLOOR_EX(X) ((int)X + ((X - (int)X != 0 && X < 0) ? -1 : 0))
#define IG_CEIL_EX(X) ((int)X + ((X - (int)X != 0 && X > 0) ? 1 : 0))


#define IG_UPCAST(X, Y)   (X)
#define IG_DOWNCAST(X, Y) (X)

#define IG_HALVE(X)  ((X) * 0.5f)
#define IG_DOUBLE(X) ((X) * 2.0f)

#else

#define IG_FLOOR(X) ((X) >> IG_UNIT_FB)	//TODO (George): Is this correct? IG_FLOOR_EX(X) is recommended
#define IG_CEIL(X)  ((X) << IG_UNIT_FB) //TODO (George): Is this correct? IG_CEIL_EX(X) is recommended

#define IG_FLOOR_EX(X) ((((X & 0x7fff) && X < 0) ? -1 : 0) + (X >> IG_UNIT_FB))
#define IG_CEIL_EX(X) ((((X & 0x7fff) && X > 0) ? 1 : 0) + (X >> IG_UNIT_FB))	

#define IG_UPCAST(X, Y)   ((X) << (Y))
#define IG_DOWNCAST(X, Y) ((X) >> (Y))

#define IG_HALVE( X )   ((X) >> 1)
#define IG_DOUBLE( X )  ((X) << 1)

#endif

/**
    * @def IG_MUL
    *   Multiplies two numbers.
    * @param X
    *   First factor
    * @param Y
    *   Second factor
    * @return
    *    @a X * @a Y
    * @par Example:
    * @code
    *    igreal x = IG_ONE_HALF;
    *    igreal y = IG_ONE_HALF;
    *    igreal z = IG_MUL(x, y); // z = IG_ONE_FOURTH
    * @endcode
    */
#define IG_MUL( X, Y )  (IG_DOWNCAST( (X) * (Y), IG_UNIT_FB ))

/**
    * Divides two numbers.
    * @param iX
    *   Dividend
    * @param iY
    *   Divisor
    * @return
    *   @a x / @a y
    * @par Example:
    * @code
    *   igreal x = IG_ONE_FOURTH;
    *   igreal y = IG_ONE_HALF;
    *   igreal z = IGMathUtil_divide(x, y); // z = IG_ONE_HALF
    * @endcode
    * @see IG_DIV
    */
igreal      IGMathUtil_divide       ( igreal    iX, 
                                      igreal    iY );

/**
    * @def IG_DIV
    * Macro for shorthand access to IGMathUtil_divide.
    * @see IGMathUtil_divide.
    */
#define IG_DIV( X, Y )  (IGMathUtil_divide( (X), (Y) ))

/**
    * Gets the reciprocal of a number.
    * @param iX
    *   Argument
    * @return
    *   1/@a x in @a IG_UNIT_FB format
    * @par Example:
    * @code
    *   igreal xRecip = IGMathUtil_recip(IG_ONE_HALF); // IG_TWO
    * @endcode
    * @see IG_RECIP
    */
igreal      IGMathUtil_recip        ( igreal    iX );

/**
    * @def IG_RECIP
    *   Macro for shorthand access to IGMathUtil_recip.
    * @see IGMathUtil_recip
    */
#define IG_RECIP(Y) (IGMathUtil_recip(Y))

/**
    * Gets the square root of a number.
    * @param iX
    *   Argument
    * @return
    *   Square root of @a x
    * @par Example:
    * @code
    *   igreal root = IGMathUtil_sqrt(IG_FOUR, pErr); // IG_TWO
    * @endcode
    * @see IG_SQRT
    */
igreal      IGMathUtil_sqrt         ( igreal    iX );

/**
    * @def IG_SQRT
    *   Macro for shorthand access to IGMathUtil_sqrt.
    * @see IGMathUtil_sqrt
    */
#define IG_SQRT(X) (IGMathUtil_sqrt(X))

/**
    * Gets the sine of an angle.
    * @param iAngle
    *   Angle in radians
    * @return
    *   Sine in [@a -IG_ONE, @a IG_ONE]
    * @par Example:
    * @code
    *   igreal sin = IGMathUtil_sin(IG_ONE);
    * @endcode
    * @see IG_SIN
    */
igreal      IGMathUtil_sin          ( igreal    iAngle );

/**
    * @def IG_SIN
    *   Macro for shorthand access to IGMathUtil_sin.
    * @see IGMathUtil_sin
    */
#define IG_SIN(X) (IGMathUtil_sin(X))

/**
    * Gets the cosine of an angle.
    * @param iAngle
    *   Angle in radians
    * @return
    *   Cosine in [@a -IG_ONE, @a IG_ONE]
    * @par Example:
    * @code
    *   igreal cos = IGMathUtil_cos(IG_ONE);
    * @endcode
    * @see IG_COS
    */
igreal      IGMathUtil_cos          ( igreal    iAngle );

/**
    * @def IG_COS
    *   Macro for shorthand access to IGMathUtil_cos.
    * @see IGMathUtil_cos
    */
#define IG_COS(X) (IGMathUtil_cos(X))

/**
    * Gets the sine and cosine of an angle.
    * This function is provided as a speed optimization for cases where both
    * sine and cosine must be computed.
    * @param iAngle
    *   Angle in radians
    * @param oCos
    *   Cosine in [@a -IG_ONE, @a IG_ONE] is written here; may be NULL
    * @param oSin
    *   Sine in [@a -IG_ONE, @a IG_ONE] is written here; may be NULL
    * @return
    *   void
    * @par Example:
    * @code
    *   igreal sin;
    *   igreal cos;
    *
    *   IGMathUtil_sinCos(IG_ONE, &cos, &sin);
    *
    *   // {cos, sin} now contain the cosine and sin of 1.0 radians
    * @endcode
    */
void    IGMathUtil_sinCos           ( igreal    iAngle, 
                                      igreal*   oCos, 
                                      igreal*   oSin );

/**
    * Gets the inverse cosine of a number.
    * @param iX
    *   Fixed point number in 1.30 format
    * @return
    *   igint32 containing arccos(x) in 2.29 fixed point format (result will be
    *   between IG_ZERO and IG_PI)
    * @par Example:
    * @code
    *    igint32 x = IG_ONE;
    *    igint32 arccosX;
    *
    *    arccosX = IGMathUtil_arcCos(x, pErr);
    *    // arccosX is now IG_HALF_PI
    * @endcode
    * @see IG_ARCCOS
    */
igreal  IGMathUtil_arcCos           ( igreal    iX );

/**
    * @def IG_ARCCOS
    *   Macro for shorthand access to IGMathUtil_arcCos.
    * @see IGMathUtil_arcCos
    */
#define IG_ARCCOS(X) (IGMathUtil_arcCos(X))

/**
    * Gets the inverse tanent of a number.
    * @param iY
    *   Fixed point number in 1.30 format
    * @param iX
    *   Fixed point number in 1.30 format
    * @return
    *   igint32 containing arctan2(x) in 2.29 fixed point format (result will be
    *   between IG_ZERO and IG_PI)
    * @par Example:
    * @code
    *    igint32 y = IG_ONE;
	*    igint32 x = IG_ONE;
    *    igint32 arctan;
    *
    *    arctan = IGMathUtil_arcTan2(y, x);
    *    arctan is now 1/4 pi
    * @endcode
    * @see IG_ARCTAN2
    */
igreal  IGMathUtil_arcTan2           ( igreal    iX, igreal    iY );

/**
    * @def IG_ARCTAN2
    *   Macro for shorthand access to IGMathUtil_arcTan2.
    * @see IGMathUtil_arcTan2
    */
#define IG_ARCTAN2(X, Y) (IGMathUtil_arcTan2(X, Y))

/**
    * Gets the PseudoPolarize (r, theta) values.
    * @param iX
    *   Fixed point number in 1.30 format
    * @param iY
    *   Fixed point number in 1.30 format
    * @param oR
    *   Fixed point number in 1.30 format. The length of the vector
    * @param oTheta
    *   Fixed point number in 1.30 format. The angle in radians
    */
void  IGMathUtil_PseudoPolarize( igreal iX, igreal iY, igreal *oR, igreal *oTheta );

/**
    * Pre-normalize the arguments to a magnitude suitable.
    * @param iX
    *   Fixed point number in 1.30 format
    * @param iY
    *   Fixed point number in 1.30 format
    * @param oX
    *   Fixed point number in 1.30 format. 
    * @param oY
    *   Fixed point number in 1.30 format. 
	* @return
    *   int shift count;
	*/
int  IGMathUtil_PreNormalize( igreal iX, igreal iY, igreal *oX, igreal *oY );

#ifdef __cplusplus
}
#endif

#endif//IG_MATH_UTIL_H

