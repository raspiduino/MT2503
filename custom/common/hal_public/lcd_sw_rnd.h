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
 *    lcd_sw_rnd.h
 *
 * Project:
 * --------
 *    Maui_Software
 *
 * Description:
 * ------------
 *    This file is abstract LCD driver functions and defination for MMI.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _LCD_SW_RND_H
#define _LCD_SW_RND_H

/****************************************************************************
 * Include Directives
 ****************************************************************************/
#include "lcd_hw.h"
#include "lcd_sw_inc.h" // If RHR is done, this inclusion is unnecessary.
#include "kal_general_types.h"

/****************************************************************************
 * Macro Definitions
 ****************************************************************************/
#if ((!defined(WHITE_BACKLIGHT)) && (!defined(BLUE_BACKLIGHT)) && (!defined(BLACK_BACKLIGHT)))
#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif
#endif

/**
 *  Defined in 
 *  Mainlcd.c (mcu\lcmmi\mmi\framework\osl\oslsrc) or 
 *  Sublcd.c (mcu\lcmmi\mmi\framework\osl\oslsrc)
 *  \todo Check why the two symbols need to be externed here.
 */
//#ifdef DUAL_LCD
  #ifndef COLOR_SUBLCD  // not Color SUBLCD
    extern const kal_uint8 SubLCDSetArray[];
    extern const kal_uint8 SubLCDReSetArray[];
  #endif
//#endif

/****************************************************************************
 * Main LCD
 *****************************************************************************/
#if defined(__MMI_DISPLAY_TYPE_COLOR__)

#ifndef DRV_MAINLCD_BIT_PER_PIXEL
#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif
#endif

/* Frame Buffer */
#if (16 == DRV_MAINLCD_BIT_PER_PIXEL)

/* Color Transform */
#if (defined(MT6205)) || (defined(MT6218B))
  #define DRV_RGB_TO_HW(R,G,B)   ( (((B)&0xf8)<<5)|(((R)&0xf8))|(((G)&0xe0)>>5)|(((G)&0x1c)<<11) )
  #define DRV_HW_TO_RGB_R(VALUE) ( (kal_uint8)((VALUE)&0x00f8) )
  #define DRV_HW_TO_RGB_G(VALUE) ( (kal_uint8)((((VALUE)&0xe000)>>11)|(((VALUE)&0x0007)<<5)))
  #define DRV_HW_TO_RGB_B(VALUE) ( (kal_uint8)(((VALUE)&0x1f00)>>5) )
#else   /* Other  new Chip */
  #define DRV_RGB_TO_HW(R,G,B)   ( (kal_uint16)(((B)&0xf8)>>3)|(((G)&0xfc)<<3)|(((R)&0xf8)<<8) )
  #define DRV_HW_TO_RGB_R(VALUE) ( (kal_uint8)(((VALUE)&0xf800)>>8))
  #define DRV_HW_TO_RGB_G(VALUE) ( (kal_uint8)(((VALUE)&0x07e0)>>3))
  #define DRV_HW_TO_RGB_B(VALUE) ( (kal_uint8)(((VALUE)&0x001f)<<3))
#endif

#define DRV_MAINLCD_GET_BUFFER_PIXEL_EXT(X,Y,VALUE,BUF,PITCH)   (VALUE=(*((kal_uint16*)BUF+((Y)*(PITCH)+(X)))))
#define DRV_MAINLCD_SET_BUFFER_PIXEL_EXT(X,Y,VALUE,BUF,PITCH)   ((*((kal_uint16*)BUF+((Y)*(PITCH)+(X))))=VALUE)
#define DRV_MAINLCD_GET_BUFFER_PIXEL(X,Y,VALUE)   (VALUE=(*((kal_uint16*)GDI_LAYER.act_buf_ptr+((Y)*(GDI_LAYER.act_pitch)+(X)))))
#define DRV_MAINLCD_SET_BUFFER_PIXEL(X,Y,VALUE)   ((*((kal_uint16*)GDI_LAYER.act_buf_ptr+((Y)*(GDI_LAYER.act_pitch)+(X))))=VALUE)

// The two are added for MT6223 and MT6251
#define DRV_MAINLCD_GET_INDEX_BUFFER_PIXEL(X,Y,VALUE)   (VALUE=(*((kal_uint8*)GDI_LAYER.act_buf_ptr+((Y)*(GDI_LAYER.act_pitch)+(X)))))
#define DRV_MAINLCD_SET_INDEX_BUFFER_PIXEL(X,Y,VALUE)   ((*((kal_uint8*)GDI_LAYER.act_buf_ptr+((Y)*(GDI_LAYER.act_pitch)+(X))))=VALUE)


#define DRV_MAINLCD_COLOR_TYPE  kal_uint16

#define DRV_MAINLCD_ACCESS_BEGIN(ADDR,PITCH)  { \
              _lcd_address=(DRV_MAINLCD_COLOR_TYPE*)ADDR; \
              _lcd_pitch  =(int) PITCH; \
              {

#define DRV_MAINLCD_GOTO_XY(X,Y)  _lcd_current_address = _lcd_address + (Y)*_lcd_pitch + (X)

#define DRV_MAINLCD_SET_PIXEL(COLOR)    do{ \
              *_lcd_current_address = (DRV_MAINLCD_COLOR_TYPE) COLOR; \
              _lcd_current_address++; \
              }while(0)

#define DRV_MAINLCD_GET_PIXEL(COLOR)    do{ \
              COLOR = *_lcd_current_address; \
              _lcd_current_address++; \
              }while(0)

#define DRV_MAINLCD_JUMP_PIXELS(PIXELS) do{ \
              _lcd_current_address+=PIXELS; \
              }while(0)

#define DRV_MAINLCD_ACCESS_END      } }

/* Init Color */
#define DRV_MAINLCD_INIT_COLOR  (0x0000)  /* 16bit */

#elif (24 == DRV_MAINLCD_BIT_PER_PIXEL)
#elif (32 == DRV_MAINLCD_BIT_PER_PIXEL)
#else   // DRV_MAINLCD_BIT_PER_PIXEL
  #if defined(__MTK_INTERNAL__)
/* under construction !*/
  #endif
#endif  // DRV_MAINLCD_BIT_PER_PIXEL

#else   // #if defined(__MMI_DISPLAY_TYPE_COLOR__)

#ifndef DRV_MAINLCD_BIT_PER_PIXEL
#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif
#endif

#if (1 == DRV_MAINLCD_BIT_PER_PIXEL)
/* Color Transform */
#define  DRV_RGB_TO_HW(R,G,B)   ( ((kal_uint16)(((int)(R)+(int)(G)+(int)(B))/(int)3)>=0x80)? 1:0 )
#define  DRV_HW_TO_RGB_R(VALUE) ( (kal_uint8)((VALUE) ? 0xFF:0x00) )
#define  DRV_HW_TO_RGB_G(VALUE) ( (kal_uint8)((VALUE) ? 0xFF:0x00) )
#define  DRV_HW_TO_RGB_B(VALUE) ( (kal_uint8)((VALUE) ? 0xFF:0x00) )
#ifdef MMI_ON_HARDWARE_P
#define  DRV_MAINLCD_GET_BUFFER_PIXEL(X,Y,VALUE)  (VALUE= ( (*((kal_uint8*)GDI_LAYER.act_buf_ptr+(((Y)/8)*LCD_WIDTH+ (X/8)))) & SubLCDSetArray[(X)%8] )?0xFF:0x00)
#define  DRV_MAINLCD_SET_BUFFER_PIXEL(X,Y,VALUE)  (((VALUE)<=0)?((*((kal_uint8*)GDI_LAYER.act_buf_ptr+(((Y)/8)*LCD_WIDTH+(X/8))))|= SubLCDSetArray[(X)%8]): ((*((kal_uint8*)GDI_LAYER.act_buf_ptr+(((Y)/8)*LCD_WIDTH+(X/8)))) &= SubLCDReSetArray[(X)%8]))
#define  DRV_MAINLCD_GET_BUFFER_PIXEL_EXT(X,Y,VALUE,BUF,PITCH)  (VALUE= ( (*((kal_uint8*)BUF+((Y)*(PITCH)+(X/8)))) & SubLCDSetArray[(X)%8] )?0xFF:0x00)
#define  DRV_MAINLCD_SET_BUFFER_PIXEL_EXT(X,Y,VALUE,BUF,PITCH)  (((VALUE)<=0)?((*((kal_uint8*)BUF +((Y)*(PITCH)+(X/8))))|= SubLCDSetArray[(X)%8]): ((*((kal_uint8*)BUF +((Y)*(PITCH)+(X/8)))) &= SubLCDReSetArray[(X)%8]))

#else
#define  DRV_MAINLCD_GET_BUFFER_PIXEL(X,Y,VALUE)  (VALUE= ((*((kal_uint8*)GDI_LAYER.act_buf_ptr+(((Y)/8)+X*(LCD_HEIGHT/8)))) &SubLCDSetArray[(Y)%8] )?0xFF:0x00)
#define  DRV_MAINLCD_SET_BUFFER_PIXEL(X,Y,VALUE)  (((VALUE)<=0)?((*((kal_uint8*)GDI_LAYER.act_buf_ptr+(((Y)/8)+X*(LCD_HEIGHT/8))))|=SubLCDSetArray[(Y)%8]):((*((kal_uint8*)GDI_LAYER.act_buf_ptr+((Y/8)+(LCD_HEIGHT/8)*X))) &=SubLCDReSetArray[(Y)%8]))
#define  DRV_MAINLCD_GET_BUFFER_PIXEL_EXT(X,Y,VALUE,BUF,PITCH)  (VALUE= ( (*((kal_uint8*)BUF+((X)*(PITCH)+(Y/8)))) & SubLCDSetArray[(Y)%8] )?0xFF:0x00)
#define  DRV_MAINLCD_SET_BUFFER_PIXEL_EXT(X,Y,VALUE,BUF,PITCH)  (((VALUE)<=0)?((*((kal_uint8*)BUF +((X)*(PITCH)+(Y/8))))|= SubLCDSetArray[(Y)%8]): ((*((kal_uint8*)BUF +((X)*(PITCH)+(Y/8)))) &= SubLCDReSetArray[(Y)%8]))

#endif

#define DRV_MAINLCD_COLOR_TYPE  kal_uint8

#define DRV_MAINLCD_ACCESS_BEGIN(ADDR,PITCH)  { \
            _lcd_address=(DRV_MAINLCD_COLOR_TYPE*)ADDR; \
            _lcd_pitch  =(int) PITCH; \
            {

#define DRV_MAINLCD_GOTO_XY(X,Y)          do{ \
            _lcd_current_address = _lcd_address + (Y/8)*_lcd_pitch + (X); \
            _lcd_offset = (Y)&0x7; \
            }while(0)

#define DRV_MAINLCD_SET_PIXEL(COLOR)      do{ \
            if(COLOR>0) \
            { \
              *_lcd_current_address |= 1<<_lcd_offset; \
            } \
            else \
            { \
              *_lcd_current_address &= ~(1<<_lcd_offset); \
            } \
            _lcd_offset++; \
            if(!(_lcd_offset&0x7))\
              _lcd_current_address++; \
            }while(0)

#define DRV_MAINLCD_GET_PIXEL(COLOR)      do{\
            if(*_lcd_current_address &( 1<<_lcd_offset))\
            { \
              COLOR = 0xff; \
            } \
            else \
            { \
              COLOR = 0; \
            } \
            _lcd_offset++; \
            if(!(_lcd_offset&0x7))\
              _lcd_current_address++; \
            }while(0)

#define DRV_MAINLCD_JUMP_PIXELS(PIXELS)   do{ \
            _lcd_offset = (_lcd_offset&0x7) + PIXELS; \
            _lcd_current_address += _lcd_offset>>3; \
            }while(0)

#define DRV_MAINLCD_ACCESS_END      } }

/* Init Color */
#define DRV_MAINLCD_INIT_COLOR  (0x0000)  /* 16bit */
#else   // DRV_MAINLCD_BIT_PER_PIXEL
  #if defined(__MTK_INTERNAL__)
/* under construction !*/
  #endif
#endif  // DRV_MAINLCD_BIT_PER_PIXEL

#endif  // #if defined(__MMI_DISPLAY_TYPE_COLOR__)

/****************************************************************************
 * Sub LCD
 *****************************************************************************/

#ifdef DUAL_LCD

#ifdef COLOR_SUBLCD
  // Color SUBLCD

#ifndef DRV_SUBLCD_BIT_PER_PIXEL
#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif
#endif

#if (16 == DRV_SUBLCD_BIT_PER_PIXEL)
  #define SUBMMI_RGB_TO_HW_FORMAT(R,G,B)  ( (((R)&0xF8)<<8)|(((G)&0xFC)<<3)|(((B)&0xF8)>>3))
  #define HW_FORMAT_TO_SUBMMI_R(VALUE)    ( (VALUE&0xF800)>>8 )
  #define HW_FORMAT_TO_SUBMMI_G(VALUE)    ( (VALUE&0x07E0)>>3)
  #define HW_FORMAT_TO_SUBMMI_B(VALUE)    ( (VALUE&0x001F)<<3 )
  #define DRV_SUBLCD_GET_BUFFER_PIXEL_EXT(X,Y,VALUE,BUF,PITCH)  (VALUE=(*((kal_uint16*)BUF+((Y)*(PITCH)+(X)))))
  #define DRV_SUBLCD_SET_BUFFER_PIXEL_EXT(X,Y,VALUE,BUF,PITCH)  ((*((kal_uint16*)BUF+((Y)*(PITCH)+(X))))=VALUE)
  #define DRV_SUBLCD_GET_BUFFER_PIXEL(X,Y,VALUE)  (VALUE=(*((kal_uint16*)GDI_LAYER.act_buf_ptr+((Y)*(GDI_LAYER.act_pitch)+(X)))))
  #define DRV_SUBLCD_SET_BUFFER_PIXEL(X,Y,VALUE)  ((*((kal_uint16*)GDI_LAYER.act_buf_ptr+((Y)*(GDI_LAYER.act_pitch)+(X))))=VALUE)

  #define DRV_SUBLCD_COLOR_TYPE   kal_uint16

  #define DRV_SUBLCD_ACCESS_BEGIN(ADDR,PITCH) { \
              _sublcd_address=(DRV_SUBLCD_COLOR_TYPE*)ADDR; \
              _sublcd_current_address; \
              _sublcd_pitch  =(int) PITCH; \
              {

  #define DRV_SUBLCD_GOTO_XY(X,Y) _lcd_current_address = _sublcd_address + (Y)*_sublcd_pitch + (X)

  #define DRV_SUBLCD_SET_PIXEL(COLOR)     do{ \
              *_sublcd_current_address = (DRV_SUBLCD_COLOR_TYPE) COLOR; \
              _sublcd_current_address++; \
              }while(0)

  #define DRV_SUBLCD_GET_PIXEL(COLOR)     do{ \
              COLOR = *_sublcd_current_address; \
              _sublcd_current_address++; \
              }while(0)

  #define DRV_SUBLCD_JUMP_PIXELS(PIXELS)  do{ \
              _sublcd_current_address+=PIXELS; \
              }while(0)

  #define DRV_SUBLCD_ACCESS_END     } }

  /* Init Color */
  #define DRV_SUBLCD_INIT_COLOR (0x0000)  /* 16bit */
#else   // DRV_SUBLCD_BIT_PER_PIXEL
  #if defined(__MTK_INTERNAL__)
/* under construction !*/
  #endif
#endif  // DRV_SUBLCD_BIT_PER_PIXEL


#else   // #ifdef COLOR_SUBLCD
  // Mono LCD

#ifndef DRV_SUBLCD_BIT_PER_PIXEL
#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif
#endif

#if (1 == DRV_SUBLCD_BIT_PER_PIXEL)

  #define SUBMMI_RGB_TO_HW_FORMAT(R,G,B)  ( ((kal_uint16)(((kal_int32)(R)+(kal_int32)(G)+(kal_int32)(B))/(kal_int32)3)>=0x80)? 1:0 )
  #define HW_FORMAT_TO_SUBMMI_R(VALUE)    ( (kal_uint8)((VALUE) ? 0xFF:0x00) )
  #define HW_FORMAT_TO_SUBMMI_G(VALUE)    ( (kal_uint8)((VALUE) ? 0xFF:0x00) )
  #define HW_FORMAT_TO_SUBMMI_B(VALUE)    ( (kal_uint8)((VALUE) ? 0xFF:0x00) )
  #define DRV_SUBLCD_GET_BUFFER_PIXEL_EXT(X,Y,VALUE,BUF,PITCH)  (VALUE= ( (*((kal_uint8*)BUF+(((Y)/8)*SUBLCD_WIDTH+X))) & SubLCDSetArray[(Y)%8] )?0xFF:0x00)
  #define DRV_SUBLCD_SET_BUFFER_PIXEL_EXT(X,Y,VALUE,BUF,PITCH)  (((VALUE)<=0)?((*((kal_uint8*)BUF+(((Y)/8)*SUBLCD_WIDTH+X)))|= SubLCDSetArray[(Y)%8]): ((*((kal_uint8*)BUF+(((Y)/8)*SUBLCD_WIDTH+X))) &= SubLCDReSetArray[(Y)%8]))
  #define DRV_SUBLCD_GET_BUFFER_PIXEL(X,Y,VALUE)  (VALUE= ( (*((kal_uint8*)GDI_LAYER.act_buf_ptr+(((Y)/8)*SUBLCD_WIDTH+X))) & SubLCDSetArray[(Y)%8] )?0xFF:0x00)
  #define DRV_SUBLCD_SET_BUFFER_PIXEL(X,Y,VALUE)  (((VALUE)<=0)?((*((kal_uint8*)GDI_LAYER.act_buf_ptr+(((Y)/8)*SUBLCD_WIDTH+X)))|= SubLCDSetArray[(Y)%8]): ((*((kal_uint8*)GDI_LAYER.act_buf_ptr+(((Y)/8)*SUBLCD_WIDTH+X))) &= SubLCDReSetArray[(Y)%8]))

  #define DRV_SUBLCD_COLOR_TYPE   kal_uint8

  #define DRV_SUBLCD_ACCESS_BEGIN(ADDR,PITCH) { \
              _sublcd_address=(DRV_SUBLCD_COLOR_TYPE*)ADDR; \
              _sublcd_pitch  =(int) PITCH; \
              {

  #define DRV_SUBLCD_GOTO_XY(X,Y)         do{ \
              _sublcd_current_address = _sublcd_address + (Y/8)*_sublcd_pitch + (X); \
              _sublcd_offset = (Y)&0x7; \
              }while(0)

  #define DRV_SUBLCD_SET_PIXEL(COLOR)     do{ \
              if(COLOR>0) \
              { \
                *_lcd_current_address |= 1<<_sublcd_offset; \
              } \
              else \
              { \
                *_lcd_current_address &= ~(1<<_sublcd_offset); \
              } \
              _sublcd_offset++; \
              if(!(_sublcd_offset&0x7))\
                _lcd_current_address++; \
              }while(0)

  #define DRV_SUBLCD_GET_PIXEL(COLOR)     do{\
              if(*_lcd_current_address &( 1<<_sublcd_offset))\
              { \
                COLOR = 0xff; \
              } \
              else \
              { \
                COLOR = 0; \
              } \
              _sublcd_offset++; \
              if(!(_sublcd_offset&0x7))\
                _lcd_current_address++; \
              }while(0)

  #define DRV_SUBLCD_JUMP_PIXELS(PIXELS)  do{ \
              _sublcd_offset = (_sublcd_offset&0x7) + PIXELS; \
              _lcd_current_address += _sublcd_offset>>3; \
              }while(0)

  #define DRV_SUBLCD_ACCESS_END       } }

  /* Init Color */
  #define DRV_SUBLCD_INIT_COLOR   (0x0000)  /* 16bit */
#else   // #if (1 == DRV_SUBLCD_BIT_PER_PIXEL)
  #if defined(__MTK_INTERNAL__)
/* under construction !*/
  #endif
#endif  // #if (1 == DRV_SUBLCD_BIT_PER_PIXEL)

#endif  // #ifdef COLOR_SUBLCD

#endif  /* DUAL_LCD */
#endif  // _LCD_SW_RND_H

