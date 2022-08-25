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
 *   iul_csc_r2y.h
 *
 * Project:
 * --------
 *   N/A
 *
 * Description:
 * ------------
 *   Image Utility Library: APIs for color space conversion (RGB to YUV)
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
 * 10 26 2010 rey.su
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __IUL_CSC_R2Y_H__
#define __IUL_CSC_R2Y_H__

/**
 * Convert RGB565 raw data into YUV422 interleaved (UYVY422) raw data.
 *
 * @param srcRGB  pointer to the buffer containing RGB565 raw data
 * @param dstYUV  pointer to the buffer to contain the output YUV422 interleaved (UYVY422) data
 * @param width   the width of the source image
 * @param height  the height of the source image
 *
 * @return
 *    If the function succeeds, returns 1; otherwise returns 0.
 *
 * @remarks
 *    The dimensions of source and destination must be the same. 
 *    The width must be even.
 */
int iul_csc_rgb565_to_yuv422itlv(unsigned short *srcRGB, unsigned int *dstYUV, int width, int height);


/**
 * Convert RGB565 raw data into gray-level (Y only) raw data.
 *
 * @param srcRGB  pointer to the buffer containing RGB565 raw data
 * @param dstY    pointer to the buffer to contain the output gray-level data
 * @param dstU    dummy, NULL is accepted
 * @param dstV    dummy, NULL is accepted
 * @param width   the width of the source image
 * @param height  the height of the source image
 *
 * @return
 *    If the function succeeds, returns 1; otherwise returns 0.
 *
 * @remarks
 */
int iul_csc_rgb565_to_y(unsigned short *srcRGB, 
                        unsigned char *dstY, unsigned char *dstU, unsigned char *dstV, 
                        int width, int height);


/**
 * Convert RGB565 raw data into YUV420 planar raw data.
 *
 * @param srcRGB  pointer to the buffer containing RGB565 raw data
 * @param dstY    pointer to the buffer to contain the output Y data
 * @param dstU    pointer to the buffer to contain the output U data
 * @param dstV    pointer to the buffer to contain the output V data
 * @param width   the width of the source image
 * @param height  the height of the source image
 *
 * @return
 *    If the function succeeds, returns 1; otherwise returns 0.
 *
 * @remarks
 */
int iul_csc_rgb565_to_yuv420(unsigned short *srcRGB, 
                             unsigned char *dstY, unsigned char *dstU, unsigned char *dstV, 
                             int width, int height);


/**
 * Convert RGB888 raw data into YUV422 planar raw data.
 *
 * @param srcRGB  pointer to the buffer containing RGB888 raw data
 * @param dstY    pointer to the buffer to contain the output Y data
 * @param dstU    pointer to the buffer to contain the output U data
 * @param dstV    pointer to the buffer to contain the output V data
 * @param width   the width of the source image
 * @param height  the height of the source image
 *
 * @return
 *    If the function succeeds, returns 1; otherwise returns 0.
 *
 * @remarks
 */
int iul_csc_rgb888_to_yuv422(unsigned char *srcRGB, 
                             unsigned char *dstY, unsigned char *dstU, unsigned char *dstV, 
                             int width, int height);


/**
 * Convert RGB888 raw data into YUV422 interleaved raw data.
 *
 * @param srcRGB  pointer to the buffer containing RGB888 raw data
 * @param dstYUV  pointer to the buffer to contain the output YUV422 interleaved data
 * @param width   the width of the source image
 * @param height  the height of the source image
 *
 * @return
 *    If the function succeeds, returns 1; otherwise returns 0.
 *
 * @remarks
 */
int iul_csc_rgb888_to_yuv422itlv(unsigned char *srcRGB, unsigned char *dstYUV, int width, int height);


/**
 * Convert RGB888 raw data into YUV420 planar raw data.
 *
 * @param srcRGB  pointer to the buffer containing RGB888 raw data
 * @param dstY    pointer to the buffer to contain the output Y data
 * @param dstU    pointer to the buffer to contain the output U data
 * @param dstV    pointer to the buffer to contain the output V data
 * @param width   the width of the source image
 * @param height  the height of the source image
 *
 * @return
 *    If the function succeeds, returns 1; otherwise returns 0.
 *
 * @remarks
 */
int iul_csc_rgb888_to_yuv420(unsigned char *srcRGB, 
                             unsigned char *dstY, unsigned char *dstU, unsigned char *dstV, 
                             int width, int height);

#endif /// __IUL_CSC_R2Y_H__
