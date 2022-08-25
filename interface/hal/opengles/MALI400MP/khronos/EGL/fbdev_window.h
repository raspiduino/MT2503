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
 *    fbdev_window.h
 *
 * Project:
 * --------
 *   MAUI
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
 *
 * removed!
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/  
 
/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 * (C) COPYRIGHT 2008-2010 ARM Limited
 * ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 */

/**
 * @file fbdev_window.h
 * @brief A window type for the framebuffer device (used by egl and tests)
 */

#ifndef _FBDEV_WINDOW_H_
#define _FBDEV_WINDOW_H_

#include "kal_public_defs.h"

#ifdef __cplusplus
extern "C" {
#endif


#include "kal_public_defs.h"

typedef enum
{
	FBDEV_PIXMAP_DEFAULT = 0,
	FBDEV_PIXMAP_SUPPORTS_UMP = (1<<0),
	FBDEV_PIXMAP_ALPHA_FORMAT_PRE = (1<<1),
	FBDEV_PIXMAP_COLORSPACE_sRGB = (1<<2)
	
} fbdev_pixmap_flags;


typedef struct fb_window
{   
    void          *address;
	 unsigned int   width;
	 unsigned int   height;
    unsigned int   bytes_per_pixel;
    unsigned int   buffer_size;		
} fbdev_window;



typedef struct fbdev_pixmap
{
	unsigned int  height;
	unsigned int  width;
	unsigned int  bytes_per_pixel;
	unsigned char buffer_size;
	unsigned char red_size;
	unsigned char green_size;
	unsigned char blue_size;
	unsigned char alpha_size;
	unsigned char luminance_size;
	fbdev_pixmap_flags flags;
	unsigned short *data;
	unsigned int format; /* extra format information in case rgbal is not enough, especially for YUV formats */
} fbdev_pixmap;



typedef struct fb_var_screeninfo
{
    unsigned int lcd_width;
    unsigned int lcd_height;
    
    unsigned int red_length;
    unsigned int red_offset;
    
    unsigned int green_length;
    unsigned int green_offset;
    
    unsigned int blue_length;
    unsigned int blue_offset;
    
    unsigned int transp_length;
    unsigned int transp_offset;
    
    unsigned int bits_per_pixel;

} fb_var_screeninfo;

#if !defined(GEN_FOR_PC) && defined(__MTK_TARGET__)
typedef struct blt_info_struct
{
   LOCAL_PARA_HDR
   unsigned int frame_index;
   unsigned int buff_addr;
   unsigned int width;
   unsigned int height;
   unsigned int pitch;
   void     *cb_func;
   void     *cb_param;
} blt_info_struct;

typedef struct blt_finish_struct
{
   LOCAL_PARA_HDR
   void     *cb_func;
   void     *cb_param;
} blt_finish_struct;
#endif


#ifdef __cplusplus
}
#endif


#endif
