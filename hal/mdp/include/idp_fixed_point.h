/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2005
 *
 *  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 *  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 *  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
 *  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 *  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 *  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 *  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 *  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 *  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
 *  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 *  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
 *  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 *  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
 *  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 *  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 *  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
 *  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 *  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
 *  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
 *  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
 *  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
 *  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
 *
 *****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *
 * Project:
 * --------
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __IDP_FIXED_POINT_H__
#define __IDP_FIXED_POINT_H__

#if defined(__MTK_TARGET__)
#include "kal_general_types.h"
#include <idp_define.h>

#ifdef __arm
#define INLINE __inline
#else
#define INLINE static __inline
#endif

typedef kal_int32 IDPfixed;

#define _IDP_X_FRAC_BITS          16
#define _IDP_X_INT_BITS           16
#define _IDP_X_INT_BITS_HALF      8
#define _IDP_X_INT_MASK           0xffff0000
#define _IDP_X_FRAC_MASK          0x0000ffff
#define _IDP_X_ZERO               ((IDPfixed)0x00000000)   /* S15.16  0.0 */
#define _IDP_X_ONE                ((IDPfixed)0x00010000)   /* S15.16  1.0 */
#define _IDP_X_TWO                ((IDPfixed)0x00020000)   /* S15.16  2.0 */
#define _IDP_X_THREE              ((IDPfixed)0x00030000)   /* S15.16  3.0 */
#define _IDP_X_FOUR               ((IDPfixed)0x00040000)   /* S15.16  4.0 */
#define _IDP_X_HALF               ((IDPfixed)0x00008000)   /* S15.16  0.5 */
#define _IDP_X_TENTH              ((IDPfixed)0x00001999)   /* S15.16  0.1 */
#define _IDP_X_NEG_ONE            ((IDPfixed)0xffff0000)   /* S15.16 -1.0 */
#define _IDP_X_NEG_HALF           ((IDPfixed)0xffff8000)   /* S15.16 -0.5 */
#define _IDP_X_PINF               ((IDPfixed)0x7fffffff)   /* +inf */
#define _IDP_X_MINF               ((IDPfixed)0x80000000)   /* -inf */
#define _IDP_X_PINF_F             _IDP_X_2_FLOAT(_IDP_X_PINF)
#define _IDP_X_EPSILON            ((IDPfixed)0x00000001)

#if defined(__arm) && !defined(__thumb)
INLINE IDPfixed _IDP_X_ADD(IDPfixed a, IDPfixed b)
{
  IDPfixed res;
  __asm {
    QADD res, a, b;
  }
  return res;
}

INLINE IDPfixed _IDP_X_SUB(IDPfixed a, IDPfixed b)
{
  IDPfixed res;
  __asm {
    QSUB res, a, b;
  }
  return res;
}

INLINE IDPfixed _IDP_X_MUL_NO_OVERFLOW_CHECK(IDPfixed b, IDPfixed c)
{
  IDPfixed al;
  IDPfixed ah;
  IDPfixed res;
  __asm {
    SMULL al, ah, b, c;
    MOV   res, al, LSR #16;
    ORR   res, res, ah, LSL #16;
  }
  return res;
}
#else
INLINE IDPfixed _IDP_X_MUL_NO_OVERFLOW_CHECK(IDPfixed b, IDPfixed c)
{
  IDPfixed res;
  IDPfixed al;
  IDPfixed ah;
  {
    long long ll_res;
    ll_res = (long long)b * c;
    al = (IDPfixed) (ll_res & 0xFFFFFFFF);
    ah = (IDPfixed) ((ll_res>>32) & 0xFFFFFFFF);
  }
  res = (((unsigned int)al)>>16) | (((unsigned int)ah)<<16);
  return res;
}
   
#define _IDP_X_ADD(a,b)           _idp_x_add(a, b)
#define _IDP_X_SUB(a,b)           _idp_x_sub((a),(b))

#endif   /// #if defined(__arm) && !defined(__thumb)

#define _IDP_X_MUL(a,b)           _idp_x_mul((a),(b))
#define _IDP_X_MLA(a,b,c)         _idp_x_mla((a),(b),(c))
#define _IDP_X_DIV(a,b)           _idp_x_div((a),(b))
#define _IDP_X_MUL_DIV(m1,m2,d)   _idp_x_mul_div((m1), (m2), (d))
#define _IDP_X_FLOOR(a)           ((a)&(_IDP_X_INT_MASK))
#define _IDP_X_CEIL(a)            _IDP_X_FLOOR((a)+(_IDP_X_ONE-_IDP_X_EPSILON))

#define _IDP_FLOAT_2_X(a)          (IDPfixed)((a)*_IDP_X_ONE)

#define _IDP_X_2_FLOAT(a)         ((float)(a)/(_IDP_X_ONE))
#define _IDP_X_2_INT(a)           ((IDPfixed)(a) >= 0 ? (a)>>_IDP_X_FRAC_BITS : -((-(IDPfixed)(a))>>_IDP_X_FRAC_BITS))
#define _IDP_X_2_INT_POS(a)       ((a)>>_IDP_X_FRAC_BITS)
#define _IDP_INT_2_X(a)            ((a)<<_IDP_X_FRAC_BITS)

INLINE IDPfixed _IDP_X_ABS(IDPfixed x)
{
  if (x>=0) {
    return x;
  } else {
    if ((IDPfixed)0x80000000 == x) {
      /// because -0x80000000 = 0x80000000
      return 0x7FFFFFFF;
    } else {
      return -x;
    }
  }
}

#define SQRT_X                      _idp_x_sqrt

#define _IDP_ZERO           _IDP_X_ZERO
#define _IDP_ONE            _IDP_X_ONE
#define _IDP_TWO            _IDP_X_TWO
#define _IDP_THREE          _IDP_X_THREE
#define _IDP_FOUR           _IDP_X_FOUR
#define _IDP_HALF           _IDP_X_HALF
#define _IDP_NEG_ONE        _IDP_X_NEG_ONE
#define _IDP_EPSILON        _IDP_X_EPSILON
#define _IDP_ADD(a,b)       _IDP_X_ADD(a,b)
#define _IDP_SUB(a,b)       _IDP_X_SUB(a,b)
#define _IDP_MUL(a,b)       _IDP_X_MUL(a,b)
#define _IDP_DIV(a,b)       _IDP_X_DIV(a,b)
#define _IDP_N_2_FLOAT(a)   _IDP_X_2_FLOAT(a)
#define _IDP_FLOAT_2_N(a)   _IDP_FLOAT_2_X(a)
#define _IDP_N_2_INT(a)     _IDP_X_2_INT(a)
#define _IDP_N_2_INT_POS(a) _IDP_X_2_INT_POS(a)
#define _IDP_INT_2_N(a)     _IDP_INT_2_X(a)
#define _IDP_N_2_X(a)       (a)
#define _IDP_X_2_N(a)       (a)
#define _IDP_ABS(x)         _IDP_X_ABS(x)
#define _IDP_IROUND_POS(x)  _IDP_X_2_INT(_IDP_X_FLOOR((x)+_IDP_X_HALF))
#define _IDP_SQRT(X)        SQRT_X(X)

#define _IDP_DET                     _IDP_X_DET
#define _IDP_DOTPROD_VEC2            _IDP_X_DOTPROD_VEC2
#define _IDP_DOTPROD_VEC2_N2V1_ADD   _IDP_X_DOTPROD_VEC2_N2V1_ADD
#define _IDP_DOTPROD_VEC3_N3V1       _IDP_X_DOTPROD_VEC3_N3V1
#define _IDP_DOTPROD_VEC3_N3V1_ADD   _IDP_X_DOTPROD_VEC3_N3V1_ADD
#define _IDP_DOTPROD_VEC3_N6         _IDP_X_DOTPROD_VEC3_N6
#define _IDP_DOTPROD_VEC4_N4V1       _IDP_X_DOTPROD_VEC4_N4V1
#define _IDP_LEN_SQUARED_VEC2        _IDP_X_LEN_SQUARED_VEC2
#define _IDP_LEN_SQUARED_VEC3        _IDP_X_LEN_SQUARED_VEC3
#define _IDP_MLA                     _IDP_X_MLA
#define _IDP_MUL_DIV                 _IDP_X_MUL_DIV

#define SQRT                        SQRT_X

IDPfixed _idp_x_add(IDPfixed a, IDPfixed b);
IDPfixed _idp_x_sub(IDPfixed a, IDPfixed b);
IDPfixed _idp_x_div(IDPfixed n, IDPfixed d);
IDPfixed _idp_x_mul_div(IDPfixed n1, IDPfixed n2, IDPfixed d);
IDPfixed _idp_x_mul(IDPfixed b, IDPfixed c);
IDPfixed _idp_x_mla(IDPfixed b, IDPfixed c, IDPfixed d);

#endif

#endif
