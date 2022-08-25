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
 *   SDKFramework.h
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   SDK Application Framework API prototypes
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef SDKFRAMEWORK_H
#define SDKFRAMEWORK_H

/****************************************************************************
 * Include
 ****************************************************************************/
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "wgui.h"
#include "gui_inputs.h"
#include "gui_config.h"
#include "gui_typedef.h"
#include "ImeGprot.h"
#include "MMI_features.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gdi_const.h"
#include "gui_data_types.h"
#include "CustThemesRes.h"
#include "nvram_enums.h"
#include "mmi_theme_mgr.h"
#include "WguiCategoryGprot.h"

/****************************************************************************
 * App_mem.h
 ****************************************************************************/
/*extern void *applib_mem_ap_alloc_int(kal_uint32 app_id, kal_uint32 mem_size, kal_bool is_framebuffer, kal_char *file, kal_uint32 line, kal_bool is_anonymous);*/
extern void applib_mem_ap_free_thread_safe(void *mem_ptr, kal_char *file, kal_uint32 line, kal_bool is_anonymous);

/*
#define applib_mem_ap_alloc(app_id, mem_size) applib_mem_ap_alloc_int(app_id, mem_size, KAL_FALSE, __FILE__, __LINE__, KAL_FALSE)
#define applib_mem_ap_alloc_framebuffer(app_id, mem_size) applib_mem_ap_alloc_int(app_id, mem_size, KAL_TRUE, __FILE__, __LINE__, KAL_FALSE)
#define applib_mem_ap_free(mem_ptr) applib_mem_ap_free_thread_safe(mem_ptr, __FILE__, __LINE__, KAL_FALSE);
*/
extern void *applib_mem_screen_alloc_int(kal_uint32 mem_size, kal_bool is_framebuffer, kal_uint32 line);
extern void applib_mem_screen_free_int(void *mem_ptr, kal_uint32 line);

/*
#define applib_mem_screen_alloc(mem_size) applib_mem_screen_alloc_int(mem_size, KAL_FALSE, __LINE__)
#define applib_mem_screen_alloc_framebuffer(mem_size) applib_mem_screen_alloc_int(mem_size, KAL_TRUE, __LINE__)
#define applib_mem_screen_free(mem_ptr) applib_mem_screen_free_int(mem_ptr, __LINE__)
*/

extern void applib_mem_ap_register(
                kal_uint32 app_id, 
                kal_uint32 app_string_id, 
                kal_uint32 app_icon_id,
                void (*stop_callback_by_MMI)(void));
extern void applib_mem_ap_notify_stop_finished(kal_uint32 app_id, kal_bool result);
extern kal_uint32 applib_mem_ap_get_total_left_size(void);
extern kal_uint32 applib_mem_ap_get_max_alloc_size(void);
extern kal_uint32 applib_mem_ap_get_pool_size(void);
extern kal_uint32 applib_mem_ap_get_alloc_count(void);
extern kal_bool applib_mem_ap_is_valid_block(void *mem_ptr);
extern kal_uint32 applib_mem_screen_get_total_left_size(void);
extern kal_uint32 applib_mem_screen_get_max_alloc_size(void);
extern kal_uint32 applib_mem_screen_get_pool_size(void);
extern kal_uint32 applib_mem_screen_get_alloc_count(void);
extern kal_bool applib_mem_screen_is_valid_block(void *mem_ptr);

/****************************************************************************
 * mmi_frm_mem_gprot.h
 ****************************************************************************/
extern void mmi_frm_appmem_prompt_to_release_mem(
                MMI_ID_TYPE app_name, 
                MMI_ID_TYPE app_icon, 
                U32 required_size,
                void (*success_callback)(void));

/****************************************************************************
 * Unicodexdcl.h
 ****************************************************************************/
extern U16 mmi_asc_to_wcs(U16 *pOutBuffer, S8 *pInBuffer);
extern U16 mmi_asc_n_to_wcs(U16 *pOutBuffer, S8 *pInBuffer, U32 len);
extern U16 mmi_wcs_to_asc(S8 *pOutBuffer, U16 *pInBuffer);
extern U16 mmi_wcs_n_to_asc(S8 *pOutBuffer, U16 *pInBuffer, U32 len);
extern S32 mmi_wcslen(const U16 *string);
extern S32 mmi_wcscmp(const U16 *str_src, const U16 *str_dst);
extern S32 mmi_wcsncmp(const U16 *str_src, const U16 *str_dst, U32 count);
extern U16 *mmi_wcscpy(U16 *str_dst, const U16 *str_src);
extern U16 *mmi_wcsncpy(U16 *str_dst, const U16 *str_src, U32 count);
extern U16 *mmi_wcscat(U16 *str_dst, const U16 *str_src);
extern U16 *mmi_wcsncat(U16 *str_dst, const U16 *str_src, U32 count);
extern U16 *mmi_wcsstr(U16 *string, const U16 *str_char_set);
extern U16 *mmi_wcschr(const U16 *string,  U16 ch);
extern U16 *mmi_wcsrchr(const U16 * string, U16 ch);
extern U16 *mmi_wcslwr(U16 *string);
extern U16 *mmi_wcsupr(U16 *string);
extern S32 mmi_wcsicmp(const U16 *str_src, const U16 *str_dst);
extern S32 mmi_wcsnicmp(const U16 *str_src, const U16 *str_dst, U32 count);

/****************************************************************************
 * app_base64.h
 ****************************************************************************/

 extern kal_int32 applib_base64_encode_basic(
                    const kal_char *src, 
                    kal_int32 srcl,
                    kal_char *dst,
                    kal_int32 dstl,
                    kal_bool auto_line_wrap);

extern kal_int32 applib_base64_decode_basic(
                    const kal_char *src, 
                    kal_int32 srcl,
                    kal_char *dst,
                    kal_int32 dstl);


/****************************************************************************
 * Conversions.h
 ****************************************************************************/
#include "Conversions.h"
extern kal_uint16 mmi_chset_wchar_to_ucs2(kal_uint16 encode_char, TextEncodingEnum encoding);
extern kal_uint16 mmi_chset_ucs2_to_wchar(kal_uint16 ucs2_char, TextEncodingEnum encoding);

extern kal_uint16 mmi_chset_text_to_ucs2_str(
                    kal_uint8 *dest,
                    kal_int32 dest_size,
                    kal_uint8 *src,
                    TextEncodingEnum encoding);
extern kal_uint16 mmi_chset_text_to_ucs2_str_ex(
                    kal_uint8 *dest,
                    kal_int32 dest_size,
                    kal_uint8 *src,
                    TextEncodingEnum encoding,
                    kal_uint32 *src_end_pos);

extern kal_uint16 mmi_chset_ucs2_to_text_str(
                    kal_uint8 *dest,
                    kal_int32 dest_size,
                    kal_uint8 *src,
                    TextEncodingEnum encoding);
extern kal_uint16 mmi_chset_ucs2_to_text_str_ex(
                    kal_uint8 *dest,
                    kal_int32 dest_size,
                    kal_uint8 *src,
                    TextEncodingEnum encoding,
                    kal_uint32 *src_end_pos);

extern kal_uint8 mmi_chset_is_text_in_str(kal_uint8 *src);

extern kal_int32 mmi_chset_convert(
                    mmi_chset_enum src_type,
                    mmi_chset_enum dest_type,
                    char *src_buff,
                    char *dest_buff,
                    kal_int32 dest_size);

/****************************************************************************
 * mmi_frm_history_gprot.h
 ****************************************************************************/

 #ifdef OSL_MEMORY_DUMP
    extern void AddHistoryReferenceMemoryRecord(history *addHistory, char *fileName, int lineNumber);
    #define AddHistory(addHistory) AddHistoryReferenceMemoryRecord(&(addHistory), __FILE__, __LINE__)
#else /* OSL_MEMORY_DUMP */ 
    extern void AddHistoryReference(history *addHistory);
    #define AddHistory(addHistory) AddHistoryReference(&(addHistory))
#endif /* OSL_MEMORY_DUMP */ 
extern U8 GetHistory(U16 scrnID, history *ptrHistory);
extern void GoBackHistory(void);
extern U8 GoBackToHistory(U16 scrnid);
extern U8 *GetCurrGuiBuffer(U16 scrnid);                
extern U8 *GetCurrInputBuffer(U16 scrnid);
extern U8 DeleteScreens(U16 start_scrnid, U16 end_scrnid);
extern U32 DeleteHistory(U16 startScrId, U8 bIncStart, U16 count, U16 endScrId, U8 bIncEnd);
extern U16 DeleteScreenIfPresent(U16 ScrId);
extern MMI_BOOL IsScreenPresent(U16 scrnId);
extern MMI_BOOL IsMainLCDHistoryBack(void);
extern U8 *GetCurrNInputBuffer(U16 scrnid, U16 *size);
extern U8 SetDelScrnIDCallbackHandler(U16 ScrnID, HistoryDelCBPtr funcPtr);
extern U8 ClearDelScrnIDCallbackHandler(U16 ScrnID, HistoryDelCBPtr funcPtr);

/****************************************************************************
 * mmi_frm_events_gprot.h
 ****************************************************************************/

extern U8 EntryNewScreen(U16 newscrnID, FuncPtr newExitHandler, FuncPtr newEntryHandler, void *flag);        
extern U16 GetActiveScreenId(void);                     
extern void ExecuteCurrHiliteHandler(S32 hiliteid);     
extern void ClearInputEventHandler(U16 device);
extern void SetHiliteHandler(U16 itemid, FuncPtr hiliteFuncPtr);        
extern void ClearHiliteHandler(U16 itemid);
extern void SetParentHandler(U16 parentid);
extern U16 GetParentHandler(void);
extern U16 GetCurrHiliteID(void);
extern void ConstructHintsList(U16 currParentID, U8 **hintArray);
extern void SetHintHandler(U16 itemid, FuncPtrShort hintFuncPtr);
extern void ClearHintHandler(U16 itemid);
extern void GenericExitInlineScreen(U16 scrnID, FuncPtr entryFuncPtr);
extern void GenericExitScreen(U16 scrnID, FuncPtr entryFuncPtr);
extern FuncPtr mmi_frm_get_hilite_hdlr(U16 menu_id);
extern FuncPtrShort mmi_frm_get_hint_hdlr(U16 menu_id);


extern void mmi_frm_set_protocol_event_handler(U16 eventID, PsIntFuncPtr funcPtr, MMI_BOOL isMultiHandler);
#define SetProtocolEventHandler(func, event)   \
        mmi_frm_set_protocol_event_handler(event, (PsIntFuncPtr)func, MMI_FALSE)
extern void mmi_frm_clear_protocol_event_handler(U16 eventID, PsIntFuncPtr funcPtr);
#define ClearProtocolEventHandler(event)   \
        mmi_frm_clear_protocol_event_handler(event, (PsIntFuncPtr)NULL)
extern void mmi_frm_block_interrupt_event_handler(mmi_frm_int_event_type interrupt_event, interrupt_event_hdlr int_event_p, interrupt_event_hdlr post_int_event_p);
extern void mmi_frm_block_general_interrupt_event(mmi_frm_int_event_type interrupt_event);
extern void mmi_frm_clear_interrupt_event_handler(mmi_frm_int_event_type interrupt_event);

/****************************************************************************
 * mmi_frm_timer_gprot.h
 ****************************************************************************/

extern void StartTimerEx(U16 timerid, U32 delay, oslTimerFuncPtr funcPtr, void* arg);
extern void StartNonAlignTimerEx(U16 timerid, U32 delay, oslTimerFuncPtr funcPtr, void* arg);
extern void StopTimer(U16 timerid);

/****************************************************************************
 * mmi_frm_input_gprot.h
 ****************************************************************************/
extern void ExecuteCurrKeyHandler(S16 keyCode, S16 keyType);  
extern void GetkeyInfo(U16 *keyCode, U16 *keyType); /* gives key code & key type of last key event */
extern FuncPtr GetKeyHandler(U16 keyCode, U16 keyType);
extern void SetKeyHandler(FuncPtr funcPtr, U16 keyCode, U16 keyType);  
extern void SetGroupKeyHandler(FuncPtr funcPtr, PU16 keyCodes, U8 len, U16 keyType);   
extern void ClearKeyHandler(U16 keyCode, U16 keyType);
extern void PowerAndEndKeyHandler(void);              
extern void ClearKeyEvents(void);
extern void mmi_frm_kbd_set_tone_state(mmi_frm_kbd_tone_state_enum state);
extern mmi_frm_kbd_tone_state_enum mmi_frm_kbd_get_key_tone_state(void);

/****************************************************************************
 * mmi_frm_input_gprot.h
 ****************************************************************************/
extern void mmi_pen_register_down_handler(mmi_pen_hdlr pen_fp);
extern void mmi_pen_register_long_tap_handler(mmi_pen_hdlr pen_fp);
extern void mmi_pen_register_repeat_handler(mmi_pen_hdlr pen_fp);
extern void mmi_pen_register_move_handler(mmi_pen_hdlr pen_fp);
extern void mmi_pen_register_up_handler(mmi_pen_hdlr pen_fp);
extern void mmi_pen_register_abort_handler(mmi_pen_hdlr pen_fp);

/****************************************************************************
 * Wgui_categories.h
 ****************************************************************************/

#include "gui_inputs.h"
    extern void ShowCategory7Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *message,
                    U8 *history_buffer);
    extern void ShowCategory66Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *message,
                    U16 message_icon,
                    U8 *history_buffer);
    extern void ShowCategory69Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U16 message,
                    U32 input_type,
                    U8 *buffer,
                    S32 buffer_size,
                    U8 *history_buffer);
    extern void SetCategory69RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
    extern void ShowCategory74Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *buffer,
                    S32 buffer_length,
                    U8 *history_buffer);
    extern void wgui_cat074_change_text(U8 *new_string, S32 buffer_size, MMI_BOOL is_reset_y);
    extern void ShowCategory78Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    multi_line_input_box_icon_hdlr icon_callback,
                    U8 *buffer,
                    S32 buffer_size,
                    U8 *history_buffer);
    void SetCategory111RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
    extern void ShowCategory111Screen(
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U16 message,
                    U32 input_type,
                    U8 *buffer,
                    S32 buffer_size,
                    U8 *message2,
                    U8 *history_buffer);
#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
    extern void ShowCategory273Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    S32 number_of_items,
                    GetItemFuncPtr get_item_func,
                    wgui_get_display_style get_display_style_func,
                    wgui_get_two_line_menu_item_properties get_properties_func,
                    S32 highlighted_item,
                    U8 *history_buffer);
    extern void RedrawCategory273Screen(void);
    extern U8 *GetCategory273History(U8 *history_buffer);
    extern void ExitCategory273Screen(void);
#endif /* __MMI_UI_TWO_LINE_MENUITEM_STYLES__ */ 
    extern void ShowCategory228Screen(
                    U16 title,U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8* buffer,
                    S32 buffer_size,
                    HILITE_STR hilite_str_list[],
                    U16 hilite_str_number,
                    void (*hilite_cb)(S32 idx),
                    U8* history_buffer);
    extern void ShowCategory402Screen(
                    U8 *title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *string,
                    U16 percentage,
                    U8 *progress_string);
    extern void UpdateCategory402Value(U16 value, U8 *string);

/****************************************************************************
 * Wgui_categories_inputs.h
 ****************************************************************************/

extern void ShowCategory5Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U32 input_type,
                U8 *buffer,
                S32 buffer_size,
                U8 *history_buffer);
extern void ShowCategory5Screen_ext(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U32 input_type,
                U8 *buffer,
                S32 buffer_size,
                U8 *history_buffer,
                S16 input_ext_type,
                mmi_imm_input_mode_enum *required_input_mode_set);
extern void SetCategory5RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
extern mmi_imm_message_id_enum mmi_imm_set_app_desired_input_mode(mmi_imm_input_mode_enum desired_input_mode);
extern void mmi_ime_delete_editor_common_scr(U16 scr_id);

/****************************************************************************
 * Wgui_categories_list.h
 ****************************************************************************/
#include "Wgui_categories_list.h"
extern void ShowCategory52Screen(
                  U16 title,
                  U16 title_icon,
                  U16 left_softkey,
                  U16 left_softkey_icon,
                  U16 right_softkey,
                  U16 right_softkey_icon,
                  S32 number_of_items,
                  U16 *list_of_items,
                  U16 *list_of_icons,
                  U8 **list_of_descriptions,
                  S32 flags,
                  S32 highlighted_item,
                  U8 *history_buffer);
extern void ShowCategory36Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U16 highlighted_item,
                U8 *history_buffer);
#ifdef UI_SMALL_LIST_SCREEN
    extern void ShowCategory10Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    S32 number_of_items,
                    U16 *list_of_items,
                    U16 *list_of_icons,
                    S32 highlighted_item,
                    U8 *history_buffer);
    extern void ExitCategory10Screen(void);
#endif /* UI_SMALL_LIST_SCREEN */
extern void ShowCategory15Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                S32 number_of_items,
                U16 *list_of_items,
                U16 *list_of_icons,
                S32 flags,
                S32 highlighted_item,
                U8 *history_buffer);
extern void ShowCategory140Screen(
                U16 title,
                U16 title_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U8 *list_of_states,
                S32 highlighted_item,
                U8 *history_buffer);

extern void ShowCategory184Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        S32 highlighted_item,
        U8 *history_buffer);
/****************************************************************************
 * Wgui_categories_multimedia.h
 ****************************************************************************/

extern void ShowCategory222Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                gdi_color background_color,
                S8 *button_string,
                S8 *file_name_ptr, 
                BOOL is_short, 
                void (*decode_result_callback) (S32),
                gdi_image_src_enum src_type);
extern void ShowCategory223Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U16 message_icon,
                U16 flag,
                U32 duration,
                U8 *history_buffer);
extern void ShowCategory225Screen(U16 title_str,
                                  U16 title_icon,
                                  U16 lsk_str,
                                  U16 lsk_icon,
                                  U16 rsk_str,
                                  U16 rsk_icon,
                                  U16 video_id,
                                  PS8 video_filename,
                                  U16 repeat_count,
                                  BOOL is_visual_update,
                                  BOOL is_play_audio,
                                  BOOL is_lcd_no_sleep,
                                  GDI_COLOR bg_color, void (*play_finish_callback) (S32), void *gui_buffer);

/****************************************************************************
 * Wgui_categories_popup.h
 ****************************************************************************/

extern void ShowCategory65Screen(U8 *message, U16 message_icon, U8 *history_buffer);
extern void ShowCategory165Screen(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                UI_string_type message,
                U16 message_icon,
                U8 *history_buffer);
extern void ShowCategory151Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *message,
                U8 *message_icon,
                U8 *history_buffer);

/****************************************************************************
 * Wgui_categories_util.h
 ****************************************************************************/

extern S32 GetHighlightedItem(void);
void RegisterHighlightHandler(void (*f) (S32 item_index));
extern void ClearHighlightHandler(void);
extern void ChangeLeftSoftkey(U16 s, U16 i);
extern void ChangeRightSoftkey(U16 s, U16 i);
extern void SetLeftSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
extern void SetRightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
extern void entry_full_screen(void);
extern void leave_full_screen(void);

extern void SetCenterSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
extern void ChangeCenterSoftkey(U16 s, U16 i);

void SetCheckboxToggleRightSoftkeyFunctions(void (*done_function) (void), void (*back_function) (void));

/****************************************************************************
 * CustDataRes.h
 ****************************************************************************/
extern S8 *GetString(U16 StringId);
extern S8 *GetImage(U16 ImageId);
extern S8 *GetAudio(U16 AudioId);   

/****************************************************************************
 * Custmenures.h
 ****************************************************************************/
extern U16 GetParentItemId(U16 ItemId);
extern U16 GetNumOfChild(U16 ItemId);
extern U16 GetStringIdOfItem(U16 ItemId);
extern U16 GetImageIdOfItem(U16 ItemId);
extern U16 GetSeqItemId(U16 ParentItemId, U16 Seq);
extern U16 GetSeqItemStringId(U16 ParentItemId, U16 Seq);
extern U16 GetSeqItemImageId(U16 ParentItemId, U16 Seq);
extern void GetSequenceItemIds(U16 ParentItemId, U16 *ItemIds);
extern void GetSequenceStringIds(U16 ParentItemId, U16 *StringIds);
extern void GetSequenceImageIds(U16 ParentItemId, U16 *ImageIds);

/****************************************************************************
 * Gui.h
 ****************************************************************************/

    extern color(*gui_color) (U8 r, U8 g, U8 b);
    extern void (*gui_measure_string) (UI_string_type text, S32 *width, S32 *height);
    extern void (*gui_measure_string_n) (UI_string_type text, S32 n, S32 *width, S32 *height);
    extern void (*gui_set_font) (UI_font_type f);
    extern void (*gui_move_text_cursor) (S32 x, S32 y);
    extern void (*gui_print_text) (UI_string_type _text);
    extern void (*gui_print_text_n) (UI_string_type _text, int _n);
    extern void (*gui_set_text_color) (color c);
    extern S32(*gui_get_string_width) (UI_string_type text);
    extern S32(*gui_get_string_width_n) (UI_string_type text, S32 n);
    extern S32(*gui_get_character_width) (UI_character_type c);
    extern void gui_draw_filled_area(S32 x1, S32 y1, S32 x2, S32 y2, UI_filled_area *f);
    extern void (*gui_start_timer) (S32 count, void (*callback) (void));
    extern void (*gui_cancel_timer) (void (*callback) (void));

/****************************************************************************
 * NvramGProt.h
 ****************************************************************************/
extern S32 ReadRecord(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize, S16 *pError);
extern S32 WriteRecord(nvram_lid_enum nLID, U16 nRecordId, void *pBuffer, U16 nBufferSize, S16 *pError);
extern S32 ReadValue(U16 nDataItemId, void *pBuffer, U8 nDataType, S16 *pError);
extern S32 WriteValue(U16 nDataItemId, void *pBuffer, U8 nDataType, S16 *pError);

/****************************************************************************
 * CommonScreens.h
 ****************************************************************************/


/* begin  new popup function from 09A  */
//extern void mmi_display_popup(UI_string_type string, mmi_event_notify_enum event_id);

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__

extern S32 mmi_tm_activate_theme_from_fmgr(tm_theme_type_enum theme_type, 
                                          S8 drv_letter, 
                                          U8 *theme_name_p,
                                          MMI_BOOL is_short);
#endif

#endif /* SDKFRAMEWORK_H */ 


