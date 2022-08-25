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
 *   iul_csc_y2r.h
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
 * 03 16 2012 robin.huang
 * removed!
 * [IUL]Fix dithering API typo
 *
 * 09 28 2011 sophie.chen
 * removed!
 * removed!
 *
 * 08 29 2011 sophie.chen
 * removed!
 * .
 *
 * 03 01 2011 rey.su
 * removed!
 * Improve Y2R quality.
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

#ifndef __IUL_CSC_Y2R_H__
#define __IUL_CSC_Y2R_H__
#include "iul_common_struct.h"

/**
 * @brief            Resize YUV420 planar image into RGB565 image with dithering.
 * @param srcY       pointer to the buffer containing Y channel
 * @param srcU       pointer to the buffer containing U channel
 * @param srcV       pointer to the buffer containing V channel
 * @param srcWidth   width of the source image
 * @param srcHeight  height of the source image
 * @param dstRGB     pointer to the buffer to contain the output RGB565 data
 * @param dstWidth   width of the destination image
 * @param dstHeight  height of the destination image
 * @return           If the function succeeds, returns 1; otherwise returns 0.
 * @remarks          The dimensions of source and destination must be the same. 
 *                   The width must be even.
 */
int iul_csc_yuv420_to_rgb565_resize(unsigned char *srcY, unsigned char *srcU, unsigned char *srcV,
                                    int srcWidth, int srcHeight,
                                    unsigned short *dstRGB, 
                                    int dstWidth, int dstHeight);


/**
 * @brief            Resize YUV420 planar image into RGB565 image with dithering and source clipping.
 * @param srcY       pointer to the buffer containing Y channel, presenting the start Yaddress of source image.
 * @param srcU       pointer to the buffer containing U channel, presenting the start Uaddress of source image.
 * @param srcV       pointer to the buffer containing V channel, presenting the start Vaddress of source image.
 * @param srcWidth   width of the source image
 * @param srcHeight  height of the source image
 * @param dstRGB     pointer to the buffer to contain the output RGB565 data
 * @param dstWidth   width of the destination image
 * @param dstHeight  height of the destination image
 * @param srcClipWindow  clipping window of the source image 
 * @return           If the function succeeds, returns 1; otherwise returns 0.
 * @remarks          The dimensions of source and destination must be the same. 
 *                   The width must be even.
 */
int iul_csc_yuv420_to_rgb565_resize_with_src_clip(
   unsigned char *srcY, unsigned char *srcU, unsigned char *srcV,
   int srcWidth, int srcHeight,
   unsigned short *dstRGB, 
   int dstWidth, int dstHeight,
   iul_rect *srcClipWindow);



/**
 * @brief            Convert YUV420 planar image into RGB565 image with FXP (fixed-pattern) dithering.
 * @param srcY       pointer to Y component
 * @param srcU       pointer to U component
 * @param srcV       pointer to V component
 * @param srcPitchY  source pitch of Y component
 * @param srcPitchUV source pitch of UV component
 * @param dstPtr     pointer to destination buffer in RGB565 format
 * @param dstPitch   pixel pitch of the destination image
 * @param width      width of source image
 * @param height     height of source image
 * @return           If the function succeeds, returns 1; otherwise returns 0.
 * @remarks          The dimensions of source and destination must be the same. 
 *                   The width must be even.
 */
int iul_csc_yuv420_to_rgb565_fxp_dithering(unsigned char *srcPtrY, unsigned char *srcPtrU, unsigned char *srcPtrV,
                                           unsigned int srcPitchY, unsigned int srcPitchUV,
                                           unsigned short *dstPtr, unsigned int dstPitch,
                                           int width, int height);


/**
 * @brief            Convert YUV420 planar raw data into RGB565 raw data with MWC (Multiply-With-Carry) dithering.
 * @param srcY       pointer to Y component
 * @param srcU       pointer to U component
 * @param srcV       pointer to V component
 * @param srcPitchY  source pitch of Y component
 * @param srcPitchUV source pitch of UV component
 * @param dstPtr     pointer to destination buffer in RGB565 format
 * @param dstPitch   pixel pitch of the destination image
 * @param Width      width of the source image
 * @param height     height of the source image
 * @return           If the function succeeds, returns 1; otherwise returns 0.
 * @remarks          The dimensions of source and destination must be the same.
 *                   The width must be even.
 */
int iul_csc_yuv420_to_rgb565_mwc_dithering(unsigned char *srcPtrY, unsigned char *srcPtrU, unsigned char *srcPtrV,
                                           unsigned int srcPitchY, unsigned int srcPitchUV,
                                           unsigned short *dstPtr, unsigned int dstPitch,
                                           int width, int height);


/**
 * @brief            Convert YUV422 interleaved (UYVY422) raw data into RGB565 raw data with FXP (fixed-pattern) dithering.
 * @param srcYUV     pointer to the buffer containing UYVY422 data
 * @param dstRGB     pointer to the buffer to contain the output RGB565 data
 * @param width      width of the source image
 * @param height     height of the source image
 * @return           If the function succeeds, returns 1; otherwise returns 0.
 * @remarks          The width must be even.
 */
int iul_csc_yuv422itlv_to_rgb565_fxp_dithering(unsigned int *srcYUV, unsigned short *dstRGB, int width, int height);


/**
 * @brief            Convert YUV422 interleaved (UYVY422) raw data into RGB565 raw data with MWC (Multiply-With-Carry) dithering.
 * @param srcYUV     pointer to the buffer containing UYVY422 data
 * @param dstRGB     pointer to the buffer to contain the output RGB565 data
 * @param width      width of the source image
 * @param height     height of the source image
 * @return           If the function succeeds, returns 1; otherwise returns 0.
 * @remarks          The width must be even.
 */
int iul_csc_yuv422itlv_to_rgb565_mwc_dithering(unsigned int *srcYUV, unsigned short *dstRGB, int width, int height);



int iul_csc_yuv422itlv_to_rgb565(unsigned int *srcYUV, unsigned short *dstRGB, int width, int height);

int iul_csc_yuv422itlv_to_rgb565_resize(unsigned int *srcYUV, int srcWidth, int srcHeight, unsigned short *dstRGB, int dstWidth, int dstHeight);


int iul_csc_yuv422itlv_to_rgb565_resize(
    unsigned int *srcYUV,
    int srcWidth, int srcHeight,
    unsigned short *dstRGB, 
    int dstWidth, int dstHeight);

#endif   /// __IUL_CSC_Y2R_H__


