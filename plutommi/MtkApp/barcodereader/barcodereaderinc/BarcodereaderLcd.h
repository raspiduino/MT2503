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
 *  BarcodeReader.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  QR Code Reader Applications v0.1
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef BARCODEREADER_LCD_H
#define BARCODEREADER_LCD_H

#include "MMI_features.h"
#include "mmi_features_barcodereader.h"
#include "wgui.h"

#if ((LCD_WIDTH == 128) && (LCD_HEIGHT == 128))

#elif ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))

#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )

#ifdef __MMI_OP11_BARCODEREADER__
/* under construction !*/
#ifdef GUI_COMMON_SHOW_STATUS_ICON
/* under construction !*/
#else 
/* under construction !*/
#endif 
/* under construction !*/
#ifdef GUI_COMMON_SHOW_STATUS_ICON
/* under construction !*/
#else 
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP11_BARCODEREADER__ */ 
   #ifdef __MMI_OP01_BARCODEREADER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if MDI_CAMERA_MT6225_SERIES
/* under construction !*/
/* under construction !*/
        #else
/* under construction !*/
/* under construction !*/
        #endif
   #else
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH   176
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT 132
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X 0
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y 24
        #if MDI_CAMERA_MT6228_SERIES
            #define MMI_BARCODEREADER_IMAGE_WIDTH 320
            #define MMI_BARCODEREADER_IMAGE_HEIGHT 240
        #else
            #define MMI_BARCODEREADER_IMAGE_WIDTH 176
            #define MMI_BARCODEREADER_IMAGE_HEIGHT 132
        #endif
   #endif /* __MMI_OP01_BARCODEREADER__ */
#endif 
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
#ifdef __MMI_OP11_BARCODEREADER__
/* under construction !*/
#ifdef GUI_COMMON_SHOW_STATUS_ICON
/* under construction !*/
#else 
/* under construction !*/
#endif 
/* under construction !*/
#ifdef GUI_COMMON_SHOW_STATUS_ICON
/* under construction !*/
#else 
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
#else /* __MMI_OP11_BARCODEREADER__ */ 
    #ifdef __MMI_OP01_BARCODEREADER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH   240
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT 180
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X 0
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y 39
        #define MMI_BARCODEREADER_IMAGE_WIDTH 320
        #define MMI_BARCODEREADER_IMAGE_HEIGHT 240
    #endif
#endif /* __MMI_OP11_BARCODEREADER__ */ 

#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
    #ifdef __MMI_OP11_BARCODEREADER__
/* under construction !*/
        #ifdef GUI_COMMON_SHOW_STATUS_ICON
/* under construction !*/
        #else 
/* under construction !*/
        #endif 
/* under construction !*/
        #ifdef GUI_COMMON_SHOW_STATUS_ICON
/* under construction !*/
        #else 
/* under construction !*/
        #endif 
/* under construction !*/
/* under construction !*/
    #else /* __MMI_OP11_BARCODEREADER__ */ 
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH   240
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT 180
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X 20
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y 27
        #define MMI_BARCODEREADER_IMAGE_WIDTH 320
        #define MMI_BARCODEREADER_IMAGE_HEIGHT 240
    #endif /* __MMI_OP11_BARCODEREADER__ */ 

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 400) )
    #ifdef __MMI_OP11_BARCODEREADER__
/* under construction !*/
        #ifdef GUI_COMMON_SHOW_STATUS_ICON
/* under construction !*/
        #else 
/* under construction !*/
        #endif 
/* under construction !*/
        #ifdef GUI_COMMON_SHOW_STATUS_ICON
/* under construction !*/
        #else 
/* under construction !*/
        #endif 
/* under construction !*/
/* under construction !*/
    #else /* __MMI_OP11_BARCODEREADER__ */ 
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH   240
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT 196
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X 0
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y 108
        #define MMI_BARCODEREADER_IMAGE_WIDTH 240
        #define MMI_BARCODEREADER_IMAGE_HEIGHT 196
    #endif /* __MMI_OP11_BARCODEREADER__ */ 

#elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 480))
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH   320
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT 236
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X 0
        #define MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y 130
        #define MMI_BARCODEREADER_IMAGE_WIDTH 320
        #define MMI_BARCODEREADER_IMAGE_HEIGHT 236
#endif 

#ifdef __MMI_BARCODEREADER_AF_SUPPORT__
#define MMI_BARCODEREADER_AF_POSITION_1_X                     (LCD_WIDTH/2)
#define MMI_BARCODEREADER_AF_POSITION_1_Y                     (MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y+MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT/2)
#define MMI_BARCODEREADER_AF_POSITION_2_X                     (0)
#define MMI_BARCODEREADER_AF_POSITION_2_Y                     (0)
#define MMI_BARCODEREADER_AF_POSITION_3_X                     (0)
#define MMI_BARCODEREADER_AF_POSITION_3_Y                     (0)
#define MMI_BARCODEREADER_AF_POSITION_4_X                     (0)
#define MMI_BARCODEREADER_AF_POSITION_4_Y                     (0)
#define MMI_BARCODEREADER_AF_POSITION_5_X                     (0)
#define MMI_BARCODEREADER_AF_POSITION_5_Y                     (0)
#endif /* __MMI_BARCODEREADER_AF_SUPPORT__ */ 

#endif /* BARCODEREADER_LCD_H */ 

