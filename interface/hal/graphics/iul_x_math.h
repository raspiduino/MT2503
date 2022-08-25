/*****************************************************************************
 *
 * Filename:
 * ---------
 *   iul_x_math.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Image Utility Lirary: fixed-point math libary
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 11 23 2010 robin.huang
 * removed!
 * .remove include iul_gl_x_math.h
 *
 * 11 23 2010 robin.huang
 * removed!
 * .
 *
 * 09 01 2010 robin.huang
 * removed!
 * .
 *
 * removed!
 * removed!
 * Initial version.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __IUL_X_MATH_H__
#define __IUL_X_MATH_H__

typedef int IUL_FIXED;                                   ///< Type definition as S15.16 fixed-point

#define IUL_I_TO_X(i)         ((i) << 16)                ///< Convert from integer to S15.16 fixed-point
#define IUL_X_TO_I(x)         (((x) + (1 << 15)) >> 16)  ///< Convert from S15.16 fixed-point to integer (round)
#define IUL_X_TO_I_ROUND(x)   (((x) + (1 << 15)) >> 16)  ///< Convert from S15.16 fixed-point to integer (round)
#define IUL_X_TO_I_CHOP(x)    ((x) >> 16)                ///< Convert from S15.16 fixed-point to integer (chop)
#define IUL_X_TO_I_CARRY(x)   (((x) + 0x0000FFFF) >> 16) ///< Convert from S15.16 fixed-point to integer (carry)
#define IUL_X_FRACTION(x)     ((x) & 0x0000FFFF)

#define IUL_X_HALF            (1 << 15)

#define IUL_X_TO_F(x)         ((float)x / 65536.0)
#define IUL_F_TO_X(x)         (IUL_FIXED)((x) * 65536.0)

#define IUL_X_MUL(a, b)       (((a) * (b)) >> 16)        /// S15.16 fixed-point multiplication, the overflow is not taken into consideration
                                                         /// for fixed-point multiplication with overflow checking, please use iul_x_mul(a, b)


/// function prototype declaration
IUL_FIXED iul_x_add(IUL_FIXED a, IUL_FIXED b);
IUL_FIXED iul_x_sub(IUL_FIXED a, IUL_FIXED b);
IUL_FIXED iul_x_mul(IUL_FIXED a, IUL_FIXED b);
IUL_FIXED iul_x_div(IUL_FIXED n, IUL_FIXED d);
IUL_FIXED iul_x_sin(IUL_FIXED angle);
IUL_FIXED iul_x_cos(IUL_FIXED angle);
IUL_FIXED iul_x_sqrt(IUL_FIXED n);
IUL_FIXED iul_x_power(IUL_FIXED base, IUL_FIXED power);
IUL_FIXED iul_x_log2(IUL_FIXED n);

IUL_FIXED iul_x_cos_rad(IUL_FIXED angle);  /// [IN] An angle in radians
IUL_FIXED iul_x_sin_rad(IUL_FIXED angle);  /// [IN] An angle in radians


#endif /*__IUL_X_MATH_H__*/
