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
 *  ComposeRingToneEngineDefs.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : ComposeRingToneEngineDefs.h

   PURPOSE     : Resource IDs for the RingToneComposer Application

   REMARKS     : nil

   AUTHOR      : Ashish Garg

   DATE     : Restructured on May-24-2003

**************************************************************/
#ifndef RING_COMPOSER_ENGINE_DEFS_H
#define RING_COMPOSER_ENGINE_DEFS_H

#include "MMI_features.h"
#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)

/* RHR */
#include "MMIDataType.h"
/* RHR */

#include "ComposeRingToneDefs.h"
//#include "ComposeRingToneProts.h"
//#include "FileMgr.h"
#include "Filemgrsrvgprot.h"
#ifdef __MMI_TOUCH_RING_COMPOSER__
#include "wgui.h"
//#include "gdi_datatype.h"
//#include "gdi_image_bmp.h"
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
#include "gui_setting.h"

#if (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__)|| defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__))
#ifndef RNGC_HAS_INST_RECTANGLE
#define RNGC_HAS_INST_RECTANGLE
#endif 
#else /* (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)) */ 
#ifdef RNGC_HAS_INST_RECTANGLE
#undef RNGC_HAS_INST_RECTANGLE
#endif 
#endif /* (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)) */ 

#if (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__))
#ifndef  RNGC_NOTE_STYLE_STANDARD
#define  RNGC_NOTE_STYLE_STANDARD
#endif 
#else /* (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)) */ 
#ifdef  RNGC_NOTE_STYLE_STANDARD
#undef  RNGC_NOTE_STYLE_STANDARD
#endif 
#endif /* (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)) */ 

#if (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__))
#ifndef RNGC_STATUS_BAR_TRANSPANT_BG
#define RNGC_STATUS_BAR_TRANSPANT_BG
#endif 
#else /* (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)) */ 
#ifdef RNGC_STATUS_BAR_TRANSPANT_BG
#undef RNGC_STATUS_BAR_TRANSPANT_BG
#endif
#endif /* (defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)) */ 

#if defined( DSP_WT_SYN ) && (defined(WT150K) || defined(WT100K) || defined(WT70K))
#ifndef RNGC_SUPPORT_INSTR_STYLE1
#define RNGC_SUPPORT_INSTR_STYLE1
#endif
#elif  (defined( DSP_WT_SYN ) && defined(WT20K))
#ifndef RNGC_SUPPORT_INSTR_STYLE2
#define RNGC_SUPPORT_INSTR_STYLE2
#endif
#else
#ifndef RNGC_SUPPORT_INSTR_STYLE3
#define RNGC_SUPPORT_INSTR_STYLE3
#endif
#endif

#if defined(RNGC_SUPPORT_INSTR_STYLE1)
#define  INSTR_PIANO                     1
#define  INSTR_GUITAR                    25
#define  INSTR_VIOLIN                    41
#define  INSTR_SPHONE                    68
#define  INSTR_SDRUMS                    115
#define  INSTR_HARMONICA                 23

#define  RNGC_DEFAULT_FIRST_INSTR         (INSTR_PIANO)
#define  ENUM_TOTAL_INSTR                8/*number of instruments*/   

#elif defined(RNGC_SUPPORT_INSTR_STYLE2)  
#define  INSTR_GUITAR                    25
#define  INSTR_VIOLIN                    41

#define  RNGC_DEFAULT_FIRST_INSTR         (INSTR_GUITAR)
#define  ENUM_TOTAL_INSTR                4 /*number of instruments*/

#else
#define  INSTR_PIANO                     2
#define  INSTR_MUSICBOX                  11
#define  INSTR_XYLOPHONE                 13
#define  INSTR_HARMONICA                 23
#define  INSTR_GUITAR                    26
#define  INSTR_VIOLIN                    45
#define  INSTR_SPHONE                    66
#define  INSTR_SDRUMS                    115

#define  RNGC_DEFAULT_FIRST_INSTR         (INSTR_PIANO)
#define  ENUM_TOTAL_INSTR                10  /*number of instruments*/
#endif

#define  INSTR_FLUTE                     74
#define  INSTR_TRUMPET                   57

#define  SLOW_SPEED                      60
#define  NORMAL_SPEED                    120
#define  FAST_SPEED                      180

//#ifdef __MMI_RING_COMPOSER_STYLE__
#define  CONTINUOUS_STYLE                1
#define  NORMAL_STYLE                    0
#define  STACCATO_STYLE                  2
//#endif

/* Time in which you can add multiple items on the same key */
#define  MULTITAP_TIME           1000

/* iMelody header/tailer */
#define  MELODY_HEADER           "BEGIN:IMELODY\r\nVERSION:1.2\r\nFORMAT:CLASS1.0\r\n"
#define  MELODY_END              "\r\nEND:IMELODY\r\n"

/* Masks for the musical notes */
#define  NOTE_MASK               0x0000000F     /* symbol of musical note */
#define  NOTETYPE_MASK           0x00000030     /* sharp, normal, flat */
#define  OCTAVE_MASK             0x000000C0     /* octave */
#define  DURATION_MASK           0x00000F00     /* beat length */
#ifdef __MMI_RING_COMPOSER_REPEAT__
#define  REPEAT_MASK             0x0000F000     /* repeat */
#endif

#define  CLEAR_NOTE_MASK         0xFFFFFFF0
#define  CLEAR_NOTETYPE_MASK     0xFFFFFFCF
#define  CLEAR_DURATION_MASK     0xFFFFF0FF
#ifdef __MMI_RING_COMPOSER_REPEAT__
#define  CLEAR_REPEAT_MASK       0xFFFF0FFF     /* repeat */
#endif
#define MAX_HEADER_LEN 50
#define MAX_INSTR_LEN 30
#define MAX_FOOTER_LEN 20

#define NUM_OF_NOTES ((MAX_MELODY_BUF_LEN - MAX_HEADER_LEN - MAX_INSTR_LEN - MAX_FOOTER_LEN) / 7)

#if (NUM_OF_NOTES > 150)
#define  MAX_NOTES                       150
#elif (NUM_OF_NOTES > 100 && NUM_OF_NOTES < 150)
#define  MAX_NOTES            100
#else
#define  MAX_NOTES            50
#endif 

#define  RNGC_MAX_FILE_LEN               2048
#define  TIMEOUT_COMPOSER_RINGTONE       2000
#define  RNGC_FILE_LEN                   SRV_FMGR_PATH_MAX_FILE_NAME_LEN*ENCODING_LENGTH
#define RNGC_PATH_LEN    SRV_FMGR_PATH_MAX_LEN*ENCODING_LENGTH
#define  RNGC_INPUT_FILE_LEN             SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN
#define  MELODY_FILE_EXTENSION           ".imy"

/*BEGIN:__MMI_MAINLCD_128X128__*/
#if defined ( __MMI_MAINLCD_128X128__)
#define  BKG_IMG_Y1                         27  
#define  NOTE_BAR_HEIGHT                    10 
#define  RNGC_NOTE_OFFSET                   BKG_IMG_Y1
#define  RNGC_EFFECT_NOTE_OFFSET            (BKG_IMG_Y1+14)
#define  NUM_NOTES_IN_STAVE                 5
#define  RNGC_X_POS_BASED                   25
#define  RNGC_X_POS_OFFSET                  20
#define  RNGC_NUM_RIGHT_ALIGN_OFFSET        1

#define  NOTE_SELECTION_IMAGE_X             (0)
#define  NOTE_SELECTION_IMAGE_Y             (150)
#define  NOTE_SELECTION_WIDTH               (176)
#define  NOTE_SELECTION_HEIGHT              (49)

#ifdef __MMI_TOUCH_RING_COMPOSER__
#define  RNGC_MATRIX_KEY_WIDTH              (18)
#define  RNGC_MATRIX_KEY_HEIGHT             (23)
#define  NORMAL_TOOLBAR_IMAGE_X             (0)
#define  NORMAL_TOOLBAR_IMAGE_Y             (184)
#define  NORMAL_TOOLBAR_HEIGHT              (16)
#define  NORMAL_TOOLBAR_WIDTH               (176)
#define  RNGC_NOTE_SELECT_MATRIX_WIDTH      (132) 
#define  RNGC_NOTE_SELECT_MATRIX_HEIGHT     (47)

#define  RNGC_TOOL_BAR_LEFT_OFFSET          (1)
#define  RNGC_TOOL_BAR_TOP_OFFSET           (1)
#define  RNGC_NOTE_SELECTION_VERTICAL_GAP   (1)
#define  RNGC_NOTE_SELECTION_HORZ_GAP       (1)
#endif /*__MMI_TOUCH_RING_COMPOSER__*/
/*End:__MMI_MAINLCD_128X128__*/

/*BEGIN:__MMI_MAINLCD_128X160__*/
#elif defined (__MMI_MAINLCD_128X160__)
#ifdef __MMI_TOUCH_RING_COMPOSER__
#define  BKG_IMG_Y1                         17 /* y-coordinate of main backgourd image */ 
#else
#define  BKG_IMG_Y1                         29 /* y-coordinate of main backgourd image */ 
#endif 
#define  NOTE_BAR_HEIGHT                    11 /* the height to display remaining number of notes */
#define  RNGC_NOTE_OFFSET                   (BKG_IMG_Y1+8)/* y-coordinate based of musical notes */
#define  RNGC_EFFECT_NOTE_OFFSET            (BKG_IMG_Y1+14+8)/*y coordinate of effect note offset */
#define  NUM_NOTES_IN_STAVE                 5 /* maximal number of notes per stave */
#define  RNGC_X_POS_BASED                   18 /*x offset to draw the first note in stave*/
#define  RNGC_X_POS_OFFSET                  20 /*offset between two notes*/
#define  RNGC_NUM_RIGHT_ALIGN_OFFSET        1 /*offset to right align to show notes number*/

#define  NOTE_SELECTION_WIDTH               (128) /*width of notes select keyboard area*/
#define  NOTE_SELECTION_HEIGHT              (36) /*heigth of notes select keyboard area*/
#define  NOTE_SELECTION_IMAGE_X             (0) /*x coordinate of to draw notes select keyboard*/
#define  NOTE_SELECTION_IMAGE_Y             (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-NOTE_SELECTION_HEIGHT-2) /*y coordinate of to draw notes select keyboard*/

#ifdef __MMI_TOUCH_RING_COMPOSER__
#define  RNGC_MATRIX_KEY_WIDTH              (13) /*width of the matrix notes soft key*/
#define  RNGC_MATRIX_KEY_HEIGHT             (17)/*height of the matrix notes soft key*/

#define  NORMAL_TOOLBAR_HEIGHT              (12)/*height of normal toolbar area*/
#define  NORMAL_TOOLBAR_WIDTH               (128)/*width of normal toolbar area*/
#define  NORMAL_TOOLBAR_IMAGE_X             (0) /*x coordinate of to draw normal toolbar image*/
#define  NORMAL_TOOLBAR_IMAGE_Y             (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-NORMAL_TOOLBAR_HEIGHT-2)/*y coordinate of to draw normal toolbar image*/

#define  RNGC_NOTE_SELECT_MATRIX_WIDTH      (100) /*width of the notes select keyboard area*/
#define  RNGC_NOTE_SELECT_MATRIX_HEIGHT     (36) /*height of the notes select keyboard area*/

#define  RNGC_TOOL_BAR_LEFT_OFFSET          (1)
#define  RNGC_TOOL_BAR_TOP_OFFSET           (1)
#define  RNGC_NOTE_SELECTION_VERTICAL_GAP   (1)
#define  RNGC_NOTE_SELECTION_HORZ_GAP       (1)
#endif /*__MMI_TOUCH_RING_COMPOSER__*/
/*End:__MMI_MAINLCD_128X160__*/

/*BEGIN:__MMI_MAINLCD_176X220__*/
#elif defined( __MMI_MAINLCD_176X220__) 
#ifdef __MMI_TOUCH_RING_COMPOSER__
#define  BKG_IMG_Y1                         52
#define  NOTE_BAR_HEIGHT                    11
#define  RNGC_NOTE_OFFSET                   (BKG_IMG_Y1+6)
#define  RNGC_EFFECT_NOTE_OFFSET            (BKG_IMG_Y1+4+6)
#define  RNGC_MATRIX_KEY_WIDTH              (18)
#define  RNGC_MATRIX_KEY_HEIGHT             (23)
#define  NORMAL_TOOLBAR_IMAGE_X             (0)
#define  NORMAL_TOOLBAR_IMAGE_Y             (184)
#define  NORMAL_TOOLBAR_HEIGHT              (16)
#define  NORMAL_TOOLBAR_WIDTH               (176)
#define  RNGC_NOTE_SELECT_MATRIX_WIDTH      (132) 
#define  RNGC_NOTE_SELECT_MATRIX_HEIGHT     (47)
#define  RNGC_TOOL_BAR_LEFT_OFFSET          (1)
#define  RNGC_TOOL_BAR_TOP_OFFSET           (1)
#define  RNGC_NOTE_SELECTION_VERTICAL_GAP   (1)
#define  RNGC_NOTE_SELECTION_HORZ_GAP       (1)
#else /* __MMI_TOUCH_RING_COMPOSER__ */ 
#define  BKG_IMG_Y1                         52
#define  NOTE_BAR_HEIGHT                    11
#define  RNGC_NOTE_OFFSET                   (BKG_IMG_Y1+6)
#define  RNGC_EFFECT_NOTE_OFFSET            (BKG_IMG_Y1+4+6)
#endif /* __MMI_TOUCH_RING_COMPOSER__ */

#define  NUM_NOTES_IN_STAVE                 7   
#define  RNGC_X_POS_BASED                   29
#define  RNGC_X_POS_OFFSET                  20
#define  RNGC_NUM_RIGHT_ALIGN_OFFSET        2   /* Need to leave space for border (1 pixel front and back) */

#define  NOTE_SELECTION_IMAGE_X             (0)
#define  NOTE_SELECTION_IMAGE_Y             (150)
#define  NOTE_SELECTION_WIDTH               (176)
#define  NOTE_SELECTION_HEIGHT              (49)
/*End:__MMI_MAINLCD_176X220__*/

/*BEGIN:__MMI_MAINLCD_240X320__*/
#elif defined(__MMI_MAINLCD_240X320__)
#define  BKG_IMG_Y1                         (108)
#define  NOTE_BAR_HEIGHT                    (18)  
#define  RNGC_NOTE_OFFSET                   (BKG_IMG_Y1+13)
#define  RNGC_EFFECT_NOTE_OFFSET            (BKG_IMG_Y1+8+13)
#define  NUM_NOTES_IN_STAVE                 10   
#define  RNGC_X_POS_BASED                   25
#define  RNGC_X_POS_OFFSET                  20
#define  RNGC_NUM_RIGHT_ALIGN_OFFSET        2
#define  MMI_RNGC_INSTRUMENT_SELECT_HEIGHT  (39)
#define  RNGC_INSTR_SELECT_MARGIN           (1)
#define  RNGC_INSTR_SELECT_X_OFFSET         (6)

#define  NOTE_SELECTION_WIDTH               (UI_device_width)
#define  NOTE_SELECTION_HEIGHT              (66)
#define  NOTE_SELECTION_IMAGE_X             (0)
#define  NOTE_SELECTION_IMAGE_Y             (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-NOTE_SELECTION_HEIGHT)   

#ifdef __MMI_TOUCH_RING_COMPOSER__
#define  RNGC_MATRIX_KEY_WIDTH              (24)
#define  RNGC_MATRIX_KEY_HEIGHT             (31)

#define  SOFT_KEY_BOARD_X                   1          
#define  SOFT_KEY_BOARD_Y                   1
#define  NORMAL_TOOLBAR_HEIGHT              (23)
#define  NORMAL_TOOLBAR_WIDTH               (UI_device_width)
#define  NORMAL_TOOLBAR_IMAGE_X             (0)
#define  NORMAL_TOOLBAR_IMAGE_Y             (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-NORMAL_TOOLBAR_HEIGHT)     

#define  RNGC_NOTE_SELECT_MATRIX_WIDTH      (175)
#define  RNGC_NOTE_SELECT_MATRIX_HEIGHT     (65)
#define  RNGC_TOOL_BAR_LEFT_OFFSET          (1)
#define  RNGC_TOOL_BAR_TOP_OFFSET           (1)
#define  RNGC_NOTE_SELECTION_VERTICAL_GAP   (2)
#define  RNGC_NOTE_SELECTION_HORZ_GAP       (1)

#endif /*__MMI_TOUCH_RING_COMPOSER__*/
/*End:__MMI_MAINLCD_240X320__*/

/*BEGIN:__MMI_MAINLCD_320X240__*/
#elif defined(__MMI_MAINLCD_320X240__)
#define  BKG_IMG_Y1                         (0)/* y-coordinate of main backgourd image */
#define  NOTE_BAR_HEIGHT                    (14)/* the height to display remaining number of notes */
#define  RNGC_NOTE_OFFSET                   (BKG_IMG_Y1+70)/* y-coordinate based of musical notes */
#define  RNGC_EFFECT_NOTE_OFFSET            (RNGC_NOTE_OFFSET + 13)/*y coordinate of effect note offset */
#define  NUM_NOTES_IN_STAVE                 13  /* maximal number of notes per stave */
#define  RNGC_X_POS_BASED                   30 /*x offset to draw the first note in stave*/
#define  RNGC_X_POS_OFFSET                  20 /*offset between two notes*/
#define  RNGC_NUM_RIGHT_ALIGN_OFFSET        5  /*offset to right align to show notes number*/
#define  MMI_RNGC_INSTRUMENT_SELECT_HEIGHT  (33)/*height of instrment select rectangle*/
#define  RNGC_INSTR_SELECT_MARGIN           (0) /*margin value between two different area */
#define  RNGC_INSTR_SELECT_X_OFFSET         (6) /*x offset to draw instrument image*/

#define  NOTE_SELECTION_WIDTH               (279)/*width of notes select keyboard area*/
#define  NOTE_SELECTION_HEIGHT              (49)/*heigth of notes select keyboard area*/
#define  NOTE_SELECTION_IMAGE_X             (0)/*x coordinate of to draw notes select keyboard*/
#define  NOTE_SELECTION_IMAGE_Y             (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-NOTE_SELECTION_HEIGHT)      

#ifdef __MMI_TOUCH_RING_COMPOSER__
#define  RNGC_MATRIX_KEY_WIDTH              (30)/*width of the matrix notes soft key*/
#define  RNGC_MATRIX_KEY_HEIGHT             (23)/*height of the matrix notes soft key*/
#define  NORMAL_TOOLBAR_HEIGHT              (24)/*height of normal toolbar area*/
#define  NORMAL_TOOLBAR_WIDTH               (276)/*width of normal toolbar area*/
#define  NORMAL_TOOLBAR_IMAGE_X             (0) /*x coordinate of to draw normal toolbar image*/
#define  NORMAL_TOOLBAR_IMAGE_Y             (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-NORMAL_TOOLBAR_HEIGHT) 

#define  RNGC_NOTE_SELECT_MATRIX_WIDTH      (217)/*width of the notes select keyboard area*/
#define  RNGC_NOTE_SELECT_MATRIX_HEIGHT     (49)/*height of the notes select keyboard area*/
#define  RNGC_TOOL_BAR_LEFT_OFFSET          (19)/*x offset of the really soft key area to left align*/
#define  RNGC_TOOL_BAR_TOP_OFFSET           (1)
#define  RNGC_NOTE_SELECTION_VERTICAL_GAP   (1)
#define  RNGC_NOTE_SELECTION_HORZ_GAP       (1)
#endif /*__MMI_TOUCH_RING_COMPOSER__*/
/*End:__MMI_MAINLCD_320X240__*/

/*BEGIN:__MMI_MAINLCD_240X400__*/
#elif defined(__MMI_MAINLCD_240X400__)
#define  BKG_IMG_Y1                         (0)/* y-coordinate of main backgourd image */
#define  NOTE_BAR_HEIGHT                    (14)/* the height to display remaining number of notes */
#define  RNGC_NOTE_OFFSET                   (BKG_IMG_Y1+150)/* y-coordinate based of musical notes */
#define  RNGC_EFFECT_NOTE_OFFSET            (RNGC_NOTE_OFFSET + 13)/*y coordinate of effect note offset */
#define  NUM_NOTES_IN_STAVE                 9  /* maximal number of notes per stave */
#define  RNGC_X_POS_BASED                   30 /*x offset to draw the first note in stave*/
#define  RNGC_X_POS_OFFSET                  20 /*offset between two notes*/
#define  RNGC_NUM_RIGHT_ALIGN_OFFSET        10  /*offset to right align to show notes number*/
#define  MMI_RNGC_INSTRUMENT_SELECT_HEIGHT  (33)/*height of instrment select rectangle*/
#define  RNGC_INSTR_SELECT_MARGIN           (0) /*margin value between two different area */
#define  RNGC_INSTR_SELECT_X_OFFSET         (4) /*x offset to draw instrument image*/

#define  NOTE_SELECTION_WIDTH               (UI_device_width)/*width of notes select keyboard area*/
#define  NOTE_SELECTION_HEIGHT              (71)/*heigth of notes select keyboard area*/
#define  NOTE_SELECTION_IMAGE_X             (0)/*x coordinate of to draw notes select keyboard*/
#define  NOTE_SELECTION_IMAGE_Y             (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-NOTE_SELECTION_HEIGHT)      

#ifdef __MMI_TOUCH_RING_COMPOSER__
#define  RNGC_MATRIX_KEY_WIDTH              (23)/*width of the matrix notes soft key*/
#define  RNGC_MATRIX_KEY_HEIGHT             (30)/*height of the matrix notes soft key*/
#define  NORMAL_TOOLBAR_HEIGHT              (37)/*height of normal toolbar area*/
#define  NORMAL_TOOLBAR_WIDTH               (UI_device_width)/*width of normal toolbar area*/
#define  NORMAL_TOOLBAR_IMAGE_X             (0) /*x coordinate of to draw normal toolbar image*/
#define  NORMAL_TOOLBAR_IMAGE_Y             (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-NORMAL_TOOLBAR_HEIGHT) 

#define  RNGC_NOTE_SELECT_MATRIX_WIDTH      (175)/*width of the notes select keyboard area*/
#define  RNGC_NOTE_SELECT_MATRIX_HEIGHT     (71)/*height of the notes select keyboard area*/
#define  RNGC_TOOL_BAR_LEFT_OFFSET          (2)/*x offset of the really soft key area to left align*/
#define  RNGC_TOOL_BAR_TOP_OFFSET           (3)
#define  RNGC_NOTE_SELECTION_VERTICAL_GAP   (4)
#define  RNGC_NOTE_SELECTION_HORZ_GAP       (2)
#endif /*__MMI_TOUCH_RING_COMPOSER__*/
/*End:__MMI_MAINLCD_240X400__*/

/*BEGIN:__MMI_MAINLCD_320X480__*/
#elif defined(__MMI_MAINLCD_320X480__)
#define  BKG_IMG_Y1                         (0)/* y-coordinate of main backgourd image */
#define  NOTE_BAR_HEIGHT                    (15)/* the height to display remaining number of notes */
#define  RNGC_NOTE_OFFSET                   (BKG_IMG_Y1+172)/* y-coordinate based of musical notes */
#define  RNGC_EFFECT_NOTE_OFFSET            (RNGC_NOTE_OFFSET + 19)/*y coordinate of effect note offset */
#define  NUM_NOTES_IN_STAVE                 9  /* maximal number of notes per stave */
#define  RNGC_X_POS_BASED                   40 /*x offset to draw the first note in stave*/
#define  RNGC_X_POS_OFFSET                  27 /*offset between two notes*/
#define  RNGC_NUM_RIGHT_ALIGN_OFFSET        20  /*offset to right align to show notes number*/
#define  MMI_RNGC_INSTRUMENT_SELECT_HEIGHT  (56)/*height of instrment select rectangle*/
#define  RNGC_INSTR_SELECT_MARGIN           (0) /*margin value between two different area */
#define  RNGC_INSTR_SELECT_X_OFFSET         (8) /*x offset to draw instrument image*/

#define  NOTE_SELECTION_WIDTH               (UI_device_width)/*width of notes select keyboard area*/
#define  NOTE_SELECTION_HEIGHT              (86)/*heigth of notes select keyboard area*/
#define  NOTE_SELECTION_IMAGE_X             (0)/*x coordinate of to draw notes select keyboard*/
#define  NOTE_SELECTION_IMAGE_Y             (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-NOTE_SELECTION_HEIGHT)      

#ifdef __MMI_TOUCH_RING_COMPOSER__
#define  RNGC_MATRIX_KEY_WIDTH              (30)/*width of the matrix notes soft key*/
#define  RNGC_MATRIX_KEY_HEIGHT             (35)/*height of the matrix notes soft key*/
#define  NORMAL_TOOLBAR_HEIGHT              (45)/*height of normal toolbar area*/
#define  NORMAL_TOOLBAR_WIDTH               (UI_device_width)/*width of normal toolbar area*/
#define  NORMAL_TOOLBAR_IMAGE_X             (0) /*x coordinate of to draw normal toolbar image*/
#define  NORMAL_TOOLBAR_IMAGE_Y             (MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-NORMAL_TOOLBAR_HEIGHT) 

#define  RNGC_NOTE_SELECT_MATRIX_WIDTH      (233)/*width of the notes select keyboard area*/
#define  RNGC_NOTE_SELECT_MATRIX_HEIGHT     (86)/*height of the notes select keyboard area*/
#define  RNGC_TOOL_BAR_LEFT_OFFSET          (3)/*x offset of the really soft key area to left align*/
#define  RNGC_TOOL_BAR_TOP_OFFSET           (5)
#define  RNGC_NOTE_SELECTION_VERTICAL_GAP   (6)
#define  RNGC_NOTE_SELECTION_HORZ_GAP       (3)
#endif /*__MMI_TOUCH_RING_COMPOSER__*/
/*End:__MMI_MAINLCD_320X480__*/

/*BEGIN:else*/
#else 
#define  BKG_IMG_Y1                         27     
#define  NOTE_BAR_HEIGHT                    9  
#define  RNGC_NOTE_OFFSET                   (BKG_IMG_Y1+21)
#define  RNGC_EFFECT_NOTE_OFFSET            (BKG_IMG_Y1+14+21)
#define  NUM_NOTES_IN_STAVE                 5 
#define  RNGC_X_POS_BASED                   25
#define  RNGC_X_POS_OFFSET                  20
#define  RNGC_NUM_RIGHT_ALIGN_OFFSET        1

#define  NOTE_SELECTION_IMAGE_X             (0)
#define  NOTE_SELECTION_IMAGE_Y             (150)
#define  NOTE_SELECTION_WIDTH               (176)
#define  NOTE_SELECTION_HEIGHT              (49)

#ifdef __MMI_TOUCH_RING_COMPOSER__
#define  RNGC_MATRIX_KEY_WIDTH              (18)
#define  RNGC_MATRIX_KEY_HEIGHT             (23)

#define  NORMAL_TOOLBAR_IMAGE_X             (0)
#define  NORMAL_TOOLBAR_IMAGE_Y             (184)
#define  NORMAL_TOOLBAR_HEIGHT              (16)
#define  NORMAL_TOOLBAR_WIDTH               (176)
#define  RNGC_NOTE_SELECT_MATRIX_WIDTH      (132) 
#define  RNGC_NOTE_SELECT_MATRIX_HEIGHT     (47)

#define  RNGC_TOOL_BAR_LEFT_OFFSET          (1)
#define  RNGC_TOOL_BAR_TOP_OFFSET           (1)
#define  RNGC_NOTE_SELECTION_VERTICAL_GAP   (1)
#define  RNGC_NOTE_SELECTION_HORZ_GAP       (1)
#endif /*__MMI_TOUCH_RING_COMPOSER__*/
#endif 

#ifdef __MMI_TOUCH_RING_COMPOSER__
#define  RNGC_NOTE_SELECTION_FINAL          0x0001
#define  RNGC_SHOW_SELECTION_AREA           0x0002
#define  RNGC_SELECTION_AREA_REDRAW         0x0004
#define  RNGC_PEN_EVENT_UP                  0x0008

#define  RNGC_MAX_ROW                       (2)
#define  RNGC_MAX_COLUMN                    (7)
#define  RNGC_MAX_CUSTOM_KEYS               (4)

#define  RNGC_INSTRUMENT_WIDTH              (24)
#define  RNGC_INSTRUMENT_HEIGHT             (24)
#define  RNGC_INSTRUMENT_X                  (UI_device_width-RNGC_INSTRUMENT_WIDTH-2)
#define  RNGC_INSTRUMENT_Y                  (MMI_title_y)
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

#define        SetVibrationOff()    {g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_NOTE_MASK;\
                               g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=NOTE_VIBRATION_OFF;}

#define        SetVibrationOn()     {g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_NOTE_MASK;\
                              g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=NOTE_VIBRATION_ON;}

#define        SetLEDOff()          {g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_NOTE_MASK;\
                               g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=NOTE_LED_OFF;}

#define        SetLEDOn()           {g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_NOTE_MASK;\
                              g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=NOTE_LED_ON;}

#define        SetBackLightOff()    {g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_NOTE_MASK;\
                               g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=NOTE_BACKLIGHT_OFF;}

#define        SetBackLightOn()     {g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_NOTE_MASK;\
                              g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=NOTE_BACKLIGHT_ON;}

#define        SetNoteType(nType)      {g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_NOTETYPE_MASK;\
                              g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=nType;}

#define        SetOctave(nType)     {g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=~OCTAVE_MASK;\
                              g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=nType;}

#ifdef __MMI_RING_COMPOSER_REPEAT__
#define        IncrementRepeatCount()        {                                                                        \
                                 S32 nRepeat;                                                                     \
                                 nRepeat = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] & REPEAT_MASK;\
                                 if(nRepeat >= REPEAT_INFINITE && nRepeat < REPEAT_NINE){                                                    \
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex] &= CLEAR_REPEAT_MASK;  \
                                    nRepeat = nRepeat >> 12;    \
                                    nRepeat++ ;     \
                                    nRepeat = nRepeat << 12;    \
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=nRepeat;     \
                                 }                                                                                 \
                                 }

#define        DecrementRepeatCount()        {                                                                        \
                                 S32 nRepeat;                                                                     \
                                 nRepeat = g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&REPEAT_MASK;\
                                 if(nRepeat > REPEAT_INFINITE && nRepeat <= REPEAT_NINE)                                                    \
                                 {                                                                                 \
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_REPEAT_MASK;  \
                                    nRepeat = nRepeat >> 12;    \
                                    nRepeat-- ;     \
                                    nRepeat = nRepeat << 12;    \
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=nRepeat;     \
                                 }                                                                                 \
                                 }
#endif

#define        IncrementNoteBeat()        {                                                                        \
                                 S32 nTempVal;                                                                     \
                                 nTempVal=g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&DURATION_MASK;\
                                 g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_DURATION_MASK;  \
                                 if(nTempVal >= DURATION_1BY16)                                                    \
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=DURATION_3BY2;     \
                                 else                                                                              \
                                 {                                                                                 \
                                    nTempVal=nTempVal>>8;                                                          \
                                    ++nTempVal;                                                                    \
                                    nTempVal=nTempVal<<8;                                                          \
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=nTempVal;          \
                                 }                                                                                 \
                                 }
#ifdef __MMI_TOUCH_RING_COMPOSER__
#define     TouchRngcDecrementNoteBeat()  {                                                                        \
                                 S32 nTempVal;                                                                     \
                                 nTempVal=g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&DURATION_MASK;\
                                 g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_DURATION_MASK;  \
                                 if(nTempVal <= DURATION_3BY2)                                                     \
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=DURATION_1BY16;    \
                                 else                                                                              \
                                 {                                                                                 \
                                    nTempVal=nTempVal>>8;                                                          \
                                    --nTempVal;                                                                    \
                                    nTempVal=nTempVal<<8;                                                          \
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=nTempVal;          \
                                 }                                                                                 \
                                 }
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

#define        IncrementRestBeat()        {                                                                        \
                                 S32 nTempVal;                                                                     \
                                 nTempVal=g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&DURATION_MASK;\
                                 g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]&=CLEAR_DURATION_MASK;  \
                                 if(nTempVal >= DURATION_1BY16)                                                    \
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=DURATION_3BY8;     \
                                 else                                                                              \
                                 {                                                                                 \
                                    nTempVal=nTempVal>>8;                                                          \
                                    ++nTempVal;                                                                    \
                                    nTempVal=nTempVal<<8;                                                          \
                                    g_rngc_eng_cntx->NotesList[g_rngc_eng_cntx->CurrNoteIndex]|=nTempVal;          \
                                 }                                                                                 \
                                 }

/* 
 * Typedef 
 */
typedef enum
{
    RNGC_PREVIOUS_INSTR = 0,
    RNGC_NEXT_INSTR,
    RNGC_INSRT_NONE
} RNGC_SELECTED_INSTR;

#ifdef __MMI_TOUCH_RING_COMPOSER__

typedef enum
{
    GUI_RNGC_NORMAL_TOOLBAR = 1,
    GUI_RNGC_NOTE_SELECTION
} touch_rngc_selection_area;

typedef enum
{
    RNGC_PEN_NONE = 1,
    RNGC_PEN_INSTRUMENT,
    RNGC_PEN_STAVE,
    RNGC_PEN_NORMAL_TOOLBAR,
    RNGC_PEN_NOTE_SELECTION,
    RNGC_PEN_LEFT_MOVE_AREA,
    RNGC_PEN_RIGHT_MOVE_AREA,
    TOUCH_RNGC_PEN_LSK,
    TOUCH_RNGC_PEN_RSK
} touch_rngc_pen_state;

typedef enum
{
    GUI_RNGC_VIEW = 1,
    GUI_RNGC_EDIT,
    GUI_RNGC_INSERT,
    GUI_RNGC_INSERT_EDIT,
    RNGC_PLAY,
    RNGC_PAUSE
} touch_rngc_mode;

typedef enum
{
    GUI_RNGC_KEY_SHARP = SHARP,
    GUI_RNGC_KEY_FLAT = FLAT,
    GUI_RNGC_KEY_DOT,
    GUI_RNGC_KEY_OK,
    GUI_RNGC_KEY_EDIT,
    GUI_RNGC_KEY_INSERT,
    GUI_RNGC_KEY_PLAY,
    GUI_RNGC_KEY_NEXT,
    GUI_RNGC_KEY_PREV,
    GUI_RNGC_OCTAVE_UP,
    GUI_RNGC_OCTAVE_DOWN,
    GUI_RNGC_KEY_NOTE1 = (NOTE_C | OCTAVE_4 | DURATION_1 | NORMAL),
    GUI_RNGC_KEY_NOTE2 = (NOTE_C | OCTAVE_4 | DURATION_1BY2 | NORMAL),
    GUI_RNGC_KEY_NOTE3 = (NOTE_C | OCTAVE_4 | DURATION_1BY4 | NORMAL),
    GUI_RNGC_KEY_NOTE4 = (NOTE_C | OCTAVE_4 | DURATION_1BY8 | NORMAL),
    GUI_RNGC_KEY_NOTE5 = (NOTE_C | OCTAVE_4 | DURATION_1BY16 | NORMAL),
    GUI_RNGC_KEY_NOTE6 = (NOTE_REST | OCTAVE_4 | DURATION_1BY4),
    GUI_RNGC_KEY_NOTE7 = (NOTE_REST | OCTAVE_4 | DURATION_1BY8),
    GUI_RNGC_KEY_NOTE8 = (NOTE_REST | OCTAVE_4 | DURATION_1BY16)
} touch_rngc_key_note;

#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

#endif /* defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__) */ // #if defined(__MMI_RING_COMPOSER__)
#endif /* RING_COMPOSER_DEFS_H */ 

