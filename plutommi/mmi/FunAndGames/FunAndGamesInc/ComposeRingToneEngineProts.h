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
 * ComposeRingToneProts.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is defines prototypes for Ring Tone Composer application.
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

   FILENAME : ComposeRingToneEngineProts.h

   PURPOSE     : Prototypes for the Fun and Games application

   REMARKS     : nil

   AUTHOR      : Vikram

   DATE     : 

**************************************************************/

#ifndef RING_COMPOSER_PROTS_H
#define RING_COMPOSER_PROTS_H

#include "MMI_features.h"
#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)
/* RHR */
#include "MMIDataType.h"
//#include "kal_general_types.h"
#include "mmi_frm_input_gprot.h"
/* RHR */

//#include "ComposeRingToneDefs.h"
#include "ComposeRingToneTypes.h"
//#include "FileMgr.h"
#ifdef __MMI_TOUCH_RING_COMPOSER__
//#include "wgui.h"
//#include "gdi_datatype.h"
//#include "gdi_image_bmp.h"
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 
//#include "gui_setting.h"

extern void ExitRngcComposerEngine(void);
extern mmi_ret rngc_key_proc(mmi_event_struct *evt);

extern void HandleKey_0(void);
extern void HandleKey_1(void);
extern void ShowNote(U16 nNote);

extern void HandleKey_2(void);
extern void HandleKey_3(void);
extern void HandleKey_4(void);
extern void HandleKey_5(void);
extern void HandleKey_6(void);

extern void HandleKey_7(void);
extern void HandleKey_8(void);
extern void HandleKey_9(void);
extern void HandleKey_STAR(void);
extern void HandleKey_POUND(void);
extern void HandleKey_UP(void);
extern void HandleKey_DOWN(void);
extern void HandleKey_LEFT(void);
extern void HandleKey_RIGHT(void);
extern void HandleKey_RIGHT_check(void);
extern void HandleKey_END(void);
extern void HandleKey_CLEARLONG(void);
extern void mmi_rngc_HandleKey_LEFT_down_hdlr(void);
extern void mmi_rngc_HandleKey_LEFT_up_hdlr(void);
extern void RngcComposerRSKUpHandler(void);
extern void RngcComposerRSKDownHandler(void);
extern void RngcComposerLSKDownHandler(void);
extern void RngcComposerLSKUpHandler(void);

extern U16 GetMelodyFromStruct(U8 *pList, U16 nListSize);
extern U8 GetComposerStructFromMelody(U8 *pMelody);
extern U8 *GetStringForNode(U8 *pStr, U32 nNote);
extern MMI_BOOL GetIndexInList(U16 nNote, U16 *pImageId, U16 *pYVal);
extern S32 GenerateMelodyFile(PS8 pFileName);
extern void EditMelody(U8 *pFileName);

extern void InsertNote(U16 nNote);
extern void DeleteCurNote(void);
extern void FreeMemory(void);
extern void RngcTurnOffBacklightTimer(void);

extern U8 CompareMelody(U8 **pptr, void *ps);
extern U8 Tolower(U8 ch);
extern S8 StrnCmp(S8 *s1, S8 *s2, int maxlen);
extern void TrimStr(U8 **pptr);
extern void ClearToEnd(U8 **pptr);

extern U8 GetInstrument(U8 **pptr);
extern U16 GetInstrumentImage(U8 instru_type);
extern U16 GetInstrumentString(U8 instru_type);
extern U16 GetBeat(U8 **pptr);
//#ifdef __MMI_RING_COMPOSER_STYLE__
extern U16 GetStyle(U8 **pptr);
//#endif
extern void SkipSpace(U8 **pptr);
extern S32 GetInteger(U8 **pptr);
extern U8 SetNote(U8 **pptr);
extern U8 SetOctaveFromStream(U8 **pptr);
extern U8 SetLED(U8 **pptr);
extern U8 SetVibration(U8 **pptr);
extern U8 SetBackLight(U8 **pptr);
#ifdef __MMI_RING_COMPOSER_REPEAT__
extern U8 SetRepeat(U8 **pptr);
#endif
extern U8 GetMelody(U8 **pptr);

extern void PlayCurrentNode(void);
extern void GenerateCompleteComposeFileName(PS8 pFileName, PS8 pCompletePath);
extern S32 RngcCreateDir(void);

extern void mmi_rngc_change_instrument(S32 selected_instrument);
extern void mmi_rngc_select_previous_instrument_down(void);
extern void mmi_rngc_select_previous_instrument_up(void);
extern void mmi_rngc_select_previous_instrument(void);
extern void mmi_rngc_select_next_instrument_down(void);
extern void mmi_rngc_select_next_instrument_up(void);
extern void mmi_rngc_select_next_instrument(void);

#ifdef __MMI_TOUCH_RING_COMPOSER__
extern void mmi_touch_rngc_setup(touch_rngc_struct *touch_rngc_context);
extern void mmi_rngc_note_selection(touch_rngc_struct *touch_rngc_context);
extern void show_touch_rngc_selection_area(void);
extern MMI_BOOL mmi_rngc_pen_down_selection_area(touch_rngc_struct *touch_rngc_context, mmi_pen_point_struct pos);
extern MMI_BOOL mmi_rngc_pen_down_on_stave(mmi_pen_point_struct pos, S32 *item_index);
extern MMI_BOOL mmi_rngc_pen_down_instrument(mmi_pen_point_struct pos);
extern void mmi_rngc_set_note_type(S32 note_type_to_set);
extern void mmi_rngc_set_note_beat(void);
extern void mmi_rngc_change_stave_notes(touch_rngc_struct *touch_rngc_context, S32 item_index);
extern void mmi_rngc_normal_toolbar(touch_rngc_struct *touch_rngc_context);
extern void mmi_rngc_note_selection(touch_rngc_struct *touch_rngc_context);
extern void mmi_rngc_pen_down_hdlr(mmi_pen_point_struct pos);
extern void mmi_rngc_pen_up_hdlr(mmi_pen_point_struct pos);
extern void mmi_rngc_pen_move_hdlr(mmi_pen_point_struct pos);
extern void mmi_rngc_pen_repeat_hdlr(mmi_pen_point_struct pos);
extern void mmi_rngc_pen_longtap_hdlr(mmi_pen_point_struct pos);
extern void mmi_rngc_finish_insert_editing(void);
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

#endif /* defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__) */ // #if defined(__MMI_RING_COMPOSER__)
#endif /* RING_COMPOSER_PROTS_H */ 
