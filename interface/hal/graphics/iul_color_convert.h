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
 *   iul_color_convert.h
 *
 * Project:
 * --------
 *   N/A
 *
 * Description:
 * ------------
 *   Image Utility Library: APIs for color space conversion
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
 * 11 23 2010 rey.su
 * removed!
 * .
 *
 * 11 01 2010 rey.su
 * removed!
 * .
 *
 * 10 26 2010 rey.su
 * removed!
 * .
 *
 * 10 04 2010 joey.pan
 * removed!
 * Add UYVY422 to RGB565 bi-directional in-place color transform
 *
 * 08 02 2010 rey.su
 * removed!
 * Improve YUV420 to RGB565 reszier with box filter..
 *
 * removed!
 * removed!
 * move the fixed-point math macro definition to iul_x_math.h
 *
 * removed!
 * removed!
 * Add MediaTek SW disclaimer.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Code optimize.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add YUV422 interleaved -> RGB565 general resizer API.
 *
 * removed!
 * removed!
 * Initial version.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/// Deprecation Notice: 2010.10.20
/// This file will be deprecated on 11A and later SW branches.
/// Users must use new APIs after W1112.

#ifndef __IUL_COLOR_CONVERT_H__
#define __IUL_COLOR_CONVERT_H__


int iul_yuv420_non_interleave_to_rgb565_general_resize(
                              unsigned char *srcY, unsigned char *srcU, unsigned char *srcV,
                              int srcWidth, int srcHeight,
                              unsigned short *dstRGB,
                              int dstWidth, int dstHeight);

int iul_yuv422_interleave_to_yuv420_non_interleave(
                              unsigned int *srcYUV, 
                              unsigned char *dstY, unsigned char *dstU, unsigned char *dstV, 
                              int width, int height);

int iul_rgb565_to_uyvy422_interleave(void *srcRGB, void *dstYUV, int width, int height);

int iul_rgb565_to_y_only(unsigned short *srcRGB, 
                         unsigned char *dstY, unsigned char *dstU, unsigned char *dstV, 
                         int width, int height);

int iul_rgb565_to_yuv420_non_interleave(unsigned short *srcRGB, 
                                        unsigned char *dstY, unsigned char *dstU, unsigned char *dstV, 
                                        int width, int height);

int iul_rgb888_to_yuv422_non_interleave(unsigned char *srcRGB, 
                                        unsigned char *dstY, unsigned char *dstU, unsigned char *dstV, 
                                        int width, int height);

int iul_rgb888_to_yuv422_interleave(unsigned char *srcRGB, unsigned char *dstYUV, int width, int height);

int iul_rgb888_to_yuv420_non_interleave(
                              unsigned char *srcRGB, 
                              unsigned char *dstY, unsigned char *dstU, unsigned char *dstV, 
                              int width, int height);

int iul_yuv422_interleave_to_yuv422_non_interleave(
                              unsigned int *srcYUV, 
                              unsigned char *dstY, unsigned char *dstU, unsigned char *dstV, 
                              int width, int height);

int iul_yuv422_interleave_to_rgb565_quarter_size(
                              unsigned int *srcYUV, 
                              unsigned short *dstRGB,
                              int width, int height);

int iul_yuv422_interleave_to_rgb565_general_resize(
                              unsigned int *srcYUV, int srcWidth, int srcHeight,
                              unsigned short *dstRGB, int dstWidth, int dstHeight);

int iul_yuv422_interleave_to_rgb565(
                              unsigned int *srcYUV, 
                              unsigned short *dstRGB,
                              int width, int height);

int iul_yuv420_non_interleave_to_rgb565_quarter_size(
                              unsigned char *srcY, unsigned char *srcU, unsigned char *srcV,
                              unsigned short *dstRGB, 
                              int width, int height);

#endif /// __IUL_COLOR_CONVERT_H__
