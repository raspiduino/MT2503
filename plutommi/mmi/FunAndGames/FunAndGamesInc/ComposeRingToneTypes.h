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
 *  ComposeRingToneTypes.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Context structures for the Compose Ring tone app
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef RING_COMPOSER_TYPES_H
#define RING_COMPOSER_TYPES_H

#include "MMI_features.h"
#include "ComposeRingToneEngineDefs.h"

#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)

/* RHR */
#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"
#include "gdi_include.h"
//#include "kal_general_types.h"

/* RHR */


typedef struct
{
    S8 FileName[RNGC_FILE_LEN];     /* string of filename */
    U8 CurrTone;                    /* index of current composed tone */
    U8 CurrInstr;                   /* current instrument */
    U16 CurrSpeed;                   /* current play speed */
//#ifdef __MMI_RING_COMPOSER_STYLE__
    U8 CurrStyle;
//#endif
    U8 IsTonePlaying;               /* if tone is playing */
    U8 CurrHiliteItem;              /* index of current selected option */
    U8 CurrEditState;               /* eidt state 0 == Add, 1 == Edit, 2 == Rename */
    U8 IsSelfStop;
} rngc_context_struct;

typedef struct
{
    PU8 ImageList[NUM_NOTES_IN_STAVE];
    S16 TotalNotes;     /* total number of notes */
    U16 CurrNoteIndex;  /* current position of cursor */
    U16 CurrUIPos;      /* current UI position */
    U16 NotesList[MAX_NOTES + 1];
    U16 YPos[NUM_NOTES_IN_STAVE];
    U8 IsRskLP;         /* if RSK is long-pressed */
    U8 CursorWidth;
    U8 IsSefLeftKeyDown; 
} rngc_engine_context_struct;

typedef struct
{
    U16 nNote;
    U8 nImageId;
} NoteInfo;

typedef struct
{
    U16 nImageId;
    U8 nXPos;
    U16 nYPos; 
} DisplayInfo;

#ifdef __MMI_TOUCH_RING_COMPOSER__

typedef struct
{
    S16 matrix_x, matrix_y;
    S16 n_matrix_rows, n_matrix_columns;
    S16 matrix_width, matrix_height;
    S16 key_width, key_height;
    MMI_ID_TYPE key_image[RNGC_MAX_ROW][RNGC_MAX_COLUMN];
    U16 key_note[RNGC_MAX_ROW][RNGC_MAX_COLUMN];
} rngc_matrix_key_layout_struct;

typedef struct
{
    S16 x, y;
    S16 key_width, key_height;
    MMI_ID_TYPE key_image;
    U16 key_note;
} rngc_custom_key_layout_struct;

typedef struct
{
    S16 n_matrix_keys, n_custom_keys;
    S16 image_x, image_y;
    rngc_matrix_key_layout_struct *matrix_layout;
    rngc_custom_key_layout_struct *custom_keys;
    S16 horizontal_gap, vertical_gap;
    MMI_ID_TYPE imageid;
} rngc_selection_area_layout_struct;

typedef struct
{
    U16 original_key_note;
    touch_rngc_mode mode;
    S32 play_mode;
    S32 selected_key_x, selected_key_y;
    S32 key_width, key_height;
    S32 selected_key_image;
    gdi_image_cache_bmp_struct selected_key_bitmap;
    touch_rngc_selection_area area_type;
    U16 key_note_type;
    U32 flag;
} touch_rngc_struct;
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

typedef struct 
{
    U16 main_bg_img_id;
    S16 main_bg_img_area_y1, main_bg_img_area_y2;

    S16 stave_rectangle_y1, stave_rectangle_y2;

    MMI_BOOL is_draw_notes_rect_bg_color;
    S16 remain_notes_rect_y1, remain_notes_rect_height;

    S16 instr_sel_rect_y1, instr_sel_rect_y2;
    S16 instr_img_x1;

    S16 title_rect_y1, title_rect_height;
} rngc_skin_layout_struct;
#endif /* defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__) */ // #if defined(__MMI_RING_COMPOSER__)
#endif /* RING_COMPOSER_DEFS_H */ 

