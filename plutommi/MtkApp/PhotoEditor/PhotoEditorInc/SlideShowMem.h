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

/*******************************************************************************
 * Filename:
 * ---------
 *   SlideShowMem.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Define the External memory useage of Slideshow.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __SLIDESHOWMEM_H__
#define __SLIDESHOWMEM_H__


#ifdef __MMI_SLIDESHOW__
    #if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
        #define MMI_SSHOW_MEM_ABCD_BITS_PER_PIXEL   MAIN_MEDIA_LAYER_BITS_PER_PIXEL
    #else
        #define MMI_SSHOW_MEM_ABCD_BITS_PER_PIXEL   (16)
    #endif
        #if defined(__MMI_MAINLCD_320X480__)
        
            #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
                #define MMI_SSHOW_POOL_SIZE (320 * 480 * 2 * 1 + SRV_FMGR_PATH_BUFFER_SIZE * 2 + (320 * 480 * MMI_SSHOW_MEM_ABCD_BITS_PER_PIXEL / 8) * 2)
            #else
                #define MMI_SSHOW_POOL_SIZE (320 * 480 * 2 * 0 + SRV_FMGR_PATH_BUFFER_SIZE * 2 + (320 * 480 * MMI_SSHOW_MEM_ABCD_BITS_PER_PIXEL / 8) * 2)
            #endif
            
        #elif defined(__MMI_MAINLCD_240X400__)
        
            #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
                #define MMI_SSHOW_POOL_SIZE (240 * 400 * 2 * 1 + SRV_FMGR_PATH_BUFFER_SIZE * 2 + (240 * 400 * MMI_SSHOW_MEM_ABCD_BITS_PER_PIXEL / 8) * 2)
            #else
                #define MMI_SSHOW_POOL_SIZE (240 * 400 * 2 * 0 + SRV_FMGR_PATH_BUFFER_SIZE * 2 + (240 * 400 * MMI_SSHOW_MEM_ABCD_BITS_PER_PIXEL / 8) * 2)
            #endif
            
        #elif (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__))
        
            #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
                #define MMI_SSHOW_POOL_SIZE (240 * 320 * 2 * 1 + SRV_FMGR_PATH_BUFFER_SIZE * 2 + (240 * 320 * MMI_SSHOW_MEM_ABCD_BITS_PER_PIXEL / 8) * 2)
            #else
                #define MMI_SSHOW_POOL_SIZE (240 * 320 * 2 * 0 + SRV_FMGR_PATH_BUFFER_SIZE * 2 + (240 * 320 * MMI_SSHOW_MEM_ABCD_BITS_PER_PIXEL / 8) * 2)
            #endif
        
        #elif defined(__MMI_MAINLCD_176X220__)
        
            #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
                #define MMI_SSHOW_POOL_SIZE (176 * 220 * 2 * 1 + SRV_FMGR_PATH_BUFFER_SIZE * 2 + (176 * 220 * MMI_SSHOW_MEM_ABCD_BITS_PER_PIXEL / 8) * 2)
            #else
                #define MMI_SSHOW_POOL_SIZE (176 * 220 * 2 * 0 + SRV_FMGR_PATH_BUFFER_SIZE * 2 + (176 * 220 * MMI_SSHOW_MEM_ABCD_BITS_PER_PIXEL / 8) * 2)
            #endif
            
        #elif defined(__MMI_MAINLCD_128X160__)
        
            #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
                #define MMI_SSHOW_POOL_SIZE (128 * 160 * 2 * 1 + SRV_FMGR_PATH_BUFFER_SIZE * 2 + (128 * 160 * MMI_SSHOW_MEM_ABCD_BITS_PER_PIXEL / 8) * 2)
            #else
                #define MMI_SSHOW_POOL_SIZE (128 * 160 * 2 * 0 + SRV_FMGR_PATH_BUFFER_SIZE * 2 + (128 * 160 * MMI_SSHOW_MEM_ABCD_BITS_PER_PIXEL / 8) * 2)
            #endif
            
        #elif defined(__MMI_MAINLCD_128X128__)

            #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
                #define MMI_SSHOW_POOL_SIZE (128 * 128 * 2 * 1 + SRV_FMGR_PATH_BUFFER_SIZE * 2 + (128 * 128 * MMI_SSHOW_MEM_ABCD_BITS_PER_PIXEL / 8) * 2)
            #else
                #define MMI_SSHOW_POOL_SIZE (128 * 128 * 2 * 0 + SRV_FMGR_PATH_BUFFER_SIZE * 2 + (128 * 128 * MMI_SSHOW_MEM_ABCD_BITS_PER_PIXEL / 8) * 2)
            #endif
            
        #else
            #error "[slide show]Please add new memory configuration according to new LCD resolution"
        #endif

    #define MMI_SSHOW_SCR_MEM_SIZE (GDI_LCD_WIDTH * GDI_LCD_HEIGHT * __MMI_MAIN_BASE_LAYER_FORMAT__)
      
#endif /* __MMI_SLIDESHOW__ */
#endif /* __SLIDESHOWMEM_H__ */

