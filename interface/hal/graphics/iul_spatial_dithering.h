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
 *   iul_spatial_dithering.h
 *
 * Project:
 * --------
 *   N/A
 *
 * Description:
 * ------------
 *   Image Utility Library: Interface for spatial dithering
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
 * 11 02 2010 rey.su
 * removed!
 * .
 *
 * 10 26 2010 rey.su
 * removed!
 * .
 *
 * removed!
 * removed!
 * Add source key.
 *
 * removed!
 * removed!
 * Initial version.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __IUL_SPATIAL_DITHERING_H__
#define __IUL_SPATIAL_DITHERING_H__

/**
 * @brief                  Convert a RGB888 image to RGB565 with spatial dithering with source key.
 * @param pSrc             pointer to source image in RGB888 format (R is the most significant byte).
 * @param pDst             pointer to destination image in RGB565 format. must be 2-byte aligned.
 * @param uWidth           width of source image.
 * @param uHeight          height of source image.
 * @param uDstPixelPitch   pixel pitch of destination image.
 * @param pSrcKeyColor     pointer to source key color in RGB565 format.
 * @remarks                The source pixel pitch must be equal to width of the image.
 *
 */
void iul_sd_rgb888_to_rgb565_srckey(unsigned char *pSrc, unsigned short *pDst, 
                                    unsigned int uWidth, unsigned int uHeight, 
                                    unsigned int uDstPixelPitch,
                                    unsigned short *pSrcKeyColor);


/**
 * @brief                  Convert a BGR888 image to RGB565 with spatial dithering and source key.
 * @param pSrc             pointer to source image in BGR888 format (B is the most significant byte).
 * @param pDst             pointer to destination image in RGB565 format. must be 2-byte aligned.
 * @param uWidth           width of source image.
 * @param uHeight          height of source image.
 * @param uDstPixelPitch   pixel pitch of destination image.
 * @param pSrcKeyColor     pointer to source key color in RGB565 format.
 * @remarks                The source pixel pitch must be equal to width of the image.
 *
 */
void iul_sd_bgr888_to_rgb565_srckey(unsigned char *pSrc, unsigned short *pDst, 
                                    unsigned int uWidth, unsigned int uHeight, 
                                    unsigned int uDstPixelPitch,
                                    unsigned short *pSrcKeyColor);


/**
 * @brief                  Convert a RGB888 image to RGB565 with spatial dithering.
 * @param pSrc             pointer to source image in RGB888 format (R is the most significant byte).
 * @param pDst             pointer to destination image in RGB565 format. must be 2-byte aligned.
 * @param uWidth           width of source image.
 * @param uHeight          height of source image.
 * @param uDstPixelPitch   pixel pitch of destination image.
 * @remarks                The source pixel pitch must be equal to width of the image.
 *
 */
void iul_sd_rgb888_to_rgb565(unsigned char *pSrc, unsigned short *pDst, 
                             unsigned int uWidth, unsigned int uHeight, 
                             unsigned int uDstPixelPitch);


/**
 * @brief                  Convert a BGR888 image to RGB565 with spatial dithering.
 * @param pSrc             pointer to source image in BGR888 format (B is the most significant byte).
 * @param pDst             pointer to destination image in RGB565 format. must be 2-byte aligned.
 * @param uWidth           width of source image.
 * @param uHeight          height of source image.
 * @param uDstPixelPitch   pixel pitch of destination image.
 * @remarks                The source pixel pitch must be equal to width of the image.
 *
 */
void iul_sd_bgr888_to_rgb565(unsigned char *pSrc, unsigned short *pDst, 
                             unsigned int uWidth, unsigned int uHeight, 
                             unsigned int uDstPixelPitch);


/**
 * @brief               Add 2 bits dithering for each components of a RGB888 image with source key.
 *                      The postfix "ip" means it is an in-place function.
 * @param pImg          pointer to the image in RGB888 format (R is the most significant byte).
 * @param uWidth        width of the image.
 * @param uHeight       height of the image.
 * @param uPixelPitch   pixel pitch of the image.
 * @param pSrcKeyColor  pointer to source key color, assumed to be unsigned char [3]; if this parameter is NULL, source key will be disabled.
 * @remarks             This function is an in-place function, which means the processed data will be written back to the input buffer.
 *
 */
void iul_sd_rgb888_2bits_dithering_ip_srckey(unsigned char *pImg, 
                                             unsigned int uWidth, unsigned int uHeight, 
                                             unsigned int uPixelPitch,
                                             unsigned char *pSrcKeyColor);


                                             /**
 * @brief               Add 2 bits dithering for each components of a BGR888 image with source key.
 *                      The postfix "ip" means it is an in-place function.
 * @param pImg          pointer to the image in BGR888 format (B is the least significant byte).
 * @param uWidth        width of the image.
 * @param uHeight       height of the image.
 * @param uPixelPitch   pixel pitch of the image.
 * @param pSrcKeyColor  pointer to source key color, assumed to be unsigned char [3]; if this parameter is NULL, source key will be disabled.
 * @remarks             This function is an in-place function, which means the processed data will be written back to the input buffer.
 *
 */
#define iul_sd_bgr888_2bits_dithering_ip_srckey  iul_sd_rgb888_2bits_dithering_ip_srckey


/**
 * @brief               Add 2 bits dithering for each components of a RGB888 image.
 *                      The postfix "ip" means it is an in-place function.
 * @param pImg          pointer to the image in RGB888 format (R is the most significant byte).
 * @param uWidth        width of the image.
 * @param uHeight       height of the image.
 * @param uPixelPitch   pixel pitch of the image.
 * @param pSrcKeyColor  pointer to source key color, assumed to be unsigned char [3]; if this parameter is NULL, source key will be disabled.
 * @remarks             This function is an in-place function, which means the processed data will be written back to the input buffer.
 *
 */
void iul_sd_rgb888_2bits_dithering_ip(unsigned char *pImg, 
                                      unsigned int uWidth, unsigned int uHeight, 
                                      unsigned int uPixelPitch);


/**
 * @brief               Add 2 bits dithering for each components of a BGR888 image.
 *                      The postfix "ip" means it is an in-place function.
 * @param pImg          pointer to the image in BGR888 format (B is the least significant byte).
 * @param uWidth        width of the image.
 * @param uHeight       height of the image.
 * @param uPixelPitch   pixel pitch of the image.
 * @param pSrcKeyColor  pointer to source key color, assumed to be unsigned char [3]; if this parameter is NULL, source key will be disabled.
 * @remarks             This function is an in-place function, which means the processed data will be written back to the input buffer.
 *
 */
#define iul_sd_bgr888_2bits_dithering_ip  iul_sd_rgb888_2bits_dithering_ip


#endif /// __IUL_SPATIAL_DITHERING_H__
