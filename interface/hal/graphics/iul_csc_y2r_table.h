/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   iul_csc_y2r_table.c
 *
 * Project:
 * --------
 *   N/A
 *
 * Description:
 * ------------
 *   
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
 * 05 17 2011 rey.su
 * removed!
 * Code shrinking.
 *
 * 05 11 2011 rey.su
 * removed!
 * Code refine.
 *
 * 11 23 2010 rey.su
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Help Rey Su to check-in.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __IUL_CSC_Y2R_TABLE_H__
#define __IUL_CSC_Y2R_TABLE_H__


/// Macros for RGB565 output.
#define FLAGS              0x40080100

/*
 * Range Clamping
 */
#define RANGE_CLAMP(Y)           \
do {                             \
   int val = (Y) & FLAGS;        \
   if (0 != val)                 \
   {                             \
      val -= (val >> 8);         \
      (Y) |= val;                \
      val  = FLAGS & ~(Y >> 1);  \
      (Y) += val >> 8;           \
   }                             \
} while (0)



#define Y2R_LUT_Y_OFFSET   (0)
#define Y2R_LUT_U_OFFSET   (256)
#define Y2R_LUT_V_OFFSET   (512)

#define READ_UV(U, V)   (y2r_565_table[Y2R_LUT_U_OFFSET + (U)] + y2r_565_table[Y2R_LUT_V_OFFSET + (V)])
#define READ_Y(Y)       (y2r_565_table[Y2R_LUT_Y_OFFSET + (Y)])
#define READ_U(U)       (y2r_565_table[Y2R_LUT_U_OFFSET + (U)])
#define READ_V(V)       (y2r_565_table[Y2R_LUT_V_OFFSET + (V)])


extern int iul_y2r_table[];
extern void iul_y2r_table_init(void);


#endif /// __IUL_CSC_Y2R_TABLE_H__

