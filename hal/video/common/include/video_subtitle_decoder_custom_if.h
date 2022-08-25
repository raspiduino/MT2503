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
 *   video_subtitle_decoder_custom_if.h
 *
 * Project:
 * --------
 *	MTK
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
 ****************************************************************************/
#ifndef VIDEO_SUBTITLE_DECODER_CUSTOM_IF_H
#define VIDEO_SUBTITLE_DECODER_CUSTOM_IF_H


#include "lcd_sw_inc.h"


#define VIDEO_SUBTITLE_MAX_FRAMES                       4


#if (LCD_WIDTH >= LCD_HEIGHT)
    #define VIDEO_SUBTITLE_WIDTH                        LCD_WIDTH
    #define VIDEO_SUBTITLE_HEIGHT                       LCD_HEIGHT
#else
    #define VIDEO_SUBTITLE_WIDTH                        LCD_HEIGHT
    #define VIDEO_SUBTITLE_HEIGHT                       LCD_WIDTH
#endif  // (LCD_WIDTH >= LCD_HEIGHT)


/******************************************************************************
* The height shall be able to display two lines of subtitle strings.
******************************************************************************/
#if (VIDEO_SUBTITLE_WIDTH >= 800)
    /* WVGA (848x480 or 800x480) */
    #define VIDEO_SUBTITLE_MAX_WIDTH_INTERNAL           740
    #define VIDEO_SUBTITLE_MAX_HEIGHT_INTERNAL          120
#elif (VIDEO_SUBTITLE_WIDTH >= 480)
    /* HVGA (480x320) */
    #define VIDEO_SUBTITLE_MAX_WIDTH_INTERNAL           440
    #define VIDEO_SUBTITLE_MAX_HEIGHT_INTERNAL           80
#elif (VIDEO_SUBTITLE_WIDTH >= 400)
    /* WQVGA (400x240) */
    #define VIDEO_SUBTITLE_MAX_WIDTH_INTERNAL           368
    #define VIDEO_SUBTITLE_MAX_HEIGHT_INTERNAL           64
#elif (VIDEO_SUBTITLE_WIDTH >= 320)
    /* QVGA (320x240) */
    #define VIDEO_SUBTITLE_MAX_WIDTH_INTERNAL           288
    #define VIDEO_SUBTITLE_MAX_HEIGHT_INTERNAL           64
#else
    #define VIDEO_SUBTITLE_MAX_WIDTH_INTERNAL             0
    #define VIDEO_SUBTITLE_MAX_HEIGHT_INTERNAL            0
#endif


#endif  // VIDEO_SUBTITLE_DECODER_CUSTOM_IF_H

