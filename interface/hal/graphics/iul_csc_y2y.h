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
 *   iul_csc_y2y.h
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
 * 09 28 2011 sophie.chen
 * removed!
 * removed!
 *
 * 08 29 2011 sophie.chen
 * removed!
 * .
 *
 * 11 23 2010 rey.su
 * removed!
 * .
 *
 * 10 29 2010 rey.su
 * removed!
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __IUL_CSC_Y2Y_H__
#define __IUL_CSC_Y2Y_H__

#include "iul_common_struct.h"

/**
 * @brief               Convert YUV422 interleaved image to YUV420 planar image.
 * @param srcYUV        pointer to source image in YUV422 interleaved format.
 * @param dstY          pointer to Y component of destination image in YUV420 planar format.
 * @param dstU          pointer to U component of destination image in YUV420 planar format.
 * @param dstV          pointer to V component of destination image in YUV420 planar format.
 * @param width         width of the image.
 * @param height        height of the image.
 * @remarks             
 *
 */
int iul_csc_yuv422itlv_to_yuv420(unsigned int *srcYUV, 
                                 unsigned char *dstY, unsigned char *dstU, unsigned char *dstV, 
                                 int width, int height);


/**
 * @brief               Convert YUV422 interleaved image to YUV422 planar image.
 * @param srcYUV        pointer to source image in YUV422 interleaved format.
 * @param dstY          pointer to Y component of destination image in YUV422 planar format.
 * @param dstU          pointer to U component of destination image in YUV422 planar format.
 * @param dstV          pointer to V component of destination image in YUV422 planar format.
 * @param width         width of the image.
 * @param height        height of the image.
 * @remarks             
 *
 */
int iul_csc_yuv422itlv_to_yuv422(unsigned int *srcYUV, 
                                 unsigned char *dstY, unsigned char *dstU, unsigned char *dstV, 
                                 int width, int height);



/**
 * @brief               Resize UV420 planar image to YUV420 planar image.
 * @param srcY          pointer to Y component of source image in YUV420 planar format.
 * @param srcU          pointer to U component of source image in YUV420 planar format.
 * @param srcV          pointer to V component of source image in YUV420 planar format.
 * @param srcWidth      width of source image
 * @param srcHeight     height of source image
 * @param dstY          pointer to Y component of destination image in YUV420 planar format.
 * @param dstU          pointer to U component of destination image in YUV420 planar format.
 * @param dstV          pointer to V component of destination image in YUV420 planar format.
 * @param dstWidth      width of destination image.
 * @param dstHeight     height of destination image.
 * @return              If the function succeeds, returns 1; otherwise returns 0.
 * @remarks             srcWidth, srcHeight, dstWidth and dstHeight must all be even.
 *
 */
int iul_csc_yuv420_to_yuv420_resize(unsigned char *srcY, unsigned char *srcU, unsigned char *srcV,
                                    int srcWidth, int srcHeight,
                                    unsigned char *dstY, unsigned char *dstU, unsigned char *dstV,
                                    int dstWidth, int dstHeight);
int iul_csc_yuv420_to_yuv420_resize_with_src_clip(
   unsigned char *srcY, unsigned char *srcU, unsigned char *srcV,
   int srcWidth, int srcHeight,
   unsigned char *dstY, unsigned char *dstU, unsigned char *dstV,
   int dstWidth, int dstHeight,
   iul_rect *srcClipWindow);


int iul_csc_yuv420_to_yuv422itlv_resize_with_src_clip(
   unsigned char *srcY, unsigned char *srcU, unsigned char *srcV,
   int srcWidth, int srcHeight,
   unsigned int *dstUYVY,
   int dstWidth, int dstHeight,
   iul_rect *srcClipWindow);

#endif

