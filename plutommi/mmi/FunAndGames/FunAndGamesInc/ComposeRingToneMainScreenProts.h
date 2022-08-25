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
 * ComposeRingToneGProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for the extern declarations in Compose Ring Tone
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
*********************************************************************************/
 
#ifndef _MMI_COMPRINGTONEGPROTS_H
#define _MMI_COMPRINGTONEGPROTS_H
#include "MMI_features.h"
#include "ComposeRingToneEngineDefs.h"
#include "ComposeRingToneTypes.h"

#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)

/* RHR */
#include "MMIDataType.h"
#include "gui_typedef.h"
//#include "kal_general_types.h"
/* RHR */

extern S16 RINGCOMPOSER_PATH[];
extern const U8 CurrentInstrument[];
extern U16 g_rngc_fmgr_explorer_id;

#ifdef __MMI_TOUCH_RING_COMPOSER__
extern touch_rngc_struct touch_rngc_context;
extern rngc_selection_area_layout_struct const *selection_area_context;
extern S32 rngc_pen_event_on_object;
#endif /* __MMI_TOUCH_RING_COMPOSER__ */ 

extern void mmi_rngc_show_composer(void);
extern void mmi_rngc_redraw_LSK(BOOL bPressed);
extern void mmi_rngc_redraw_RSK(BOOL bPressed);
extern void mmi_rngc_redraw_SK(BOOL bPressed, WGUI_SOFTKEY_ENUM key, U16 softkey_text);
extern void mmi_rngc_redraw_main_screen(void);
extern void mmi_rngc_draw_status_icons(void);
extern void mmi_rngc_redraw_stave(void);
extern void mmi_rngc_redraw_remaining_notes(void);
extern S32 mmi_rngc_redraw_instrument(void);
extern void mmi_rngc_redraw_main_title_background(S32 x1, S32 y1, S32 x2, S32 y2);
extern void mmi_rngc_redraw_title(void);
extern void mmi_rngc_redraw_touch_screen(void);
extern void mmi_rngc_exit_mainscreen(void);
extern void mmi_rngc_initialize_skinlayout(void);
extern void mmi_rngc_initialize_composer(void);
extern MMI_BOOL mmi_rngc_redraw_notes(void);
extern void mmi_rngc_refresh_notes_list(U16 TotalNotes, DisplayInfo *psDisplayInfo);
extern void mmi_rngc_show_note(U16 nNote);
extern void mmi_rngc_reset_toolbar(void);

#ifdef RNGC_HAS_INST_RECTANGLE
extern void mmi_rngc_instrument_menu_clear_background_callback(S32 x1, S32 y1, S32 x2, S32 y2);
extern void mmi_rngc_initialize_instrument_select_menu_items(S32 x, S32 y, S32 width, S32 height, U8 **list_of_items,
                                                  S32 *highlighted_item, void (*f) (S32 item_index));
#endif /* RNGC_HAS_INST_RECTANGLE */ 

#ifdef RNGC_STATUS_BAR_TRANSPANT_BG
extern void mmi_rngc_redraw_statusbar_bg_callback(void);
#endif /* RNGC_STATUS_BAR_TRANSPANT_BG */

extern void mmi_rngc_set_ring_composer(
        U16 title_id,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon);

#endif /* defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__) */
#endif /* _MMI_COMPRINGTONEGPROTS_H */ 

