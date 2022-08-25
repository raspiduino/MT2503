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
 *   EngineerModeFSTestUI.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines all structure needed in FS Test UI
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
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#include "FileMgrSrvGProt.h"
#include "FileMgrGProt.h"
#include "EngineerModeAppResDef.h"
#include "EngineerModeFSTestUI.h"
#include "EngineerModeFSTestCore.h"
#include "kal_trace.h"
#include "fmt_struct.h"
#include "wgui_softkeys.h"

#include "EngineerModeCommUI.h"

#if ( defined (__MMI_EM_PROFILING_FS_TEST__) && !defined(FMT_NOT_PRESENT) && !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__))
#define FS_TEST_COLOR_DRAK_GREEN  gdi_act_color_from_rgb(255, 107, 142, 35)
#define FS_TEST_COLOR_LIGTH_YELLOW  gdi_act_color_from_rgb(255,245,222,179)
#define FS_TEST_COLOR_INDIA_RED  gdi_act_color_from_rgb(255, 176,23,31)
#define FS_TEST_COLOR_DRAK_RED  gdi_act_color_from_rgb(255, 255,0,255)
#define FS_TEST_COLOR_ORGANGLE  gdi_act_color_from_rgb(255, 255,69,0)

#define EM_FS_TEST_SCREEN_MEMORY_SIZE  4096

extern MMI_BOOL g_wgui_status_bar_integrated_disabled;

static mmi_em_fs_test_context_struct g_em_fs_test_context;

static mmi_em_fs_test_fmt_result_struct test_result_data[MMI_EM_FS_TEST_FMT_DISK_TOTAL];

extern mmi_em_fs_test_fmt_finish_iln_struct test_result_struct;

U16 g_em_fs_test_current_disk_index = 0;

WCHAR *g_em_fs_test_result_view_text_data;

GDI_HANDLE base_layer_handle;
GDI_HANDLE status_icon_layer_handle;
GDI_HANDLE soft_key_layer_handle;
GDI_HANDLE title_bar_layer_handle;

typedef void (*em_fs_test_view_chart_entry_ptr) ();

typedef struct
{
    U16 entry_name[20];
    em_fs_test_view_chart_entry_ptr entry_func;
} em_fs_test_view_chart_entry_struct;

static MMI_BOOL mmi_em_fs_test_get_obj_status(mmi_em_fs_test_obj_enum obj);

static void mmi_em_fs_test_main_entry(void);

static void mmi_em_fs_test_start_entry(void);

static void mmi_em_fs_test_disk_selection_entry(void);

static void mmi_em_fs_test_format_entry(void);

static void mmi_em_fs_test_format_handler_int(S8 drive);

static void mmi_em_fs_test_content_selection_entry(void);

static void mmi_em_fs_test_help_entry(void);

static void mmi_em_fs_test_cancel_entry(void);

static void mmi_em_fs_test_disk_selection_exit(void);

static void mmi_em_fs_test_start_rsq_handler(void);

static void mmi_em_fs_test_finish_rsq_handler(void *msg);

static void mmi_em_fs_test_cancel_req_handler(void);

static void mmi_em_fs_test_cancel_rsp_handler(void);

static void mmi_em_fs_test_result_entry(void);

static void mmi_em_fs_test_result_menu_hilite_handler(S32 item_index);

static void mmi_em_fs_test_result_save_entry(void);

static void mmi_em_fs_test_result_save_finish_handler(void *msg);

static void mmi_em_fs_test_result_view_disk_selection_entry(void);

static void mmi_em_fs_test_result_view_disk_selection_menu_hilite_handler(S32 item_index);

static void mmi_em_fs_test_result_view_chart_entry(void);

static void mmi_em_fs_test_result_view_chart_menu_hilite_handler(S32 item_index);

static void mmi_em_fs_test_result_view_chart_read_entry(void);

static void mmi_em_fs_test_result_view_chart_write_entry(void);

static void mmi_em_fs_test_result_view_chart_read_cache_entry(void);

static void mmi_em_fs_test_result_view_chart_write_cache_entry(void);

static void mmi_em_fs_test_result_view_chart_exit(void);

static void mmi_em_fs_test_result_view_text_entry(void);

static void mmi_em_fs_test_result_view_text_exit(void);

static void mmi_em_fs_test_result_view_chart_goback(void);

static void mmi_em_fs_test_result_view_println(
                WCHAR *outStr,
                U32 data_id,
                U32 data_type,
                S32 *buffer_size,
                mmi_em_fs_test_fmt_result_uint result_uint);

static void mmi_em_fs_test_result_view_chart_read_help_entry(void);

static void mmi_em_fs_test_result_view_chart_write_help_entry(void);

static void mmi_em_fs_test_result_view_chart_read_cache_help_entry(void);

static void mmi_em_fs_test_result_view_chart_write_cache_help_entry(void);

static void mmi_em_fs_test_result_view_chart_text_help_entry(void);

static void mmi_em_fs_test_show_category_screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U32 *data,
                S8 **lenged_title,
                U32 point_num,
                U32 line_num);

static void mmi_em_fs_test_view_init_layers(void);

static void mmi_em_fs_test_view_deinit_layer(void);

static void mmi_em_fs_test_view_show_status_bar(void);

static void mmi_em_fs_test_view_show_title(U16 *title);

static void mmi_em_fs_test_view_show_button(U16 *left_softkey_label, U16 *right_softkey_label);

static void mmi_em_fs_test_stop_buffer_callback(void);

static U8 mmi_em_fs_test_del_main_entry_screen(void *);

static void mmi_em_fs_test_popup(U8 *message, U16 message_icon);

static const em_fs_test_view_chart_entry_struct chart_views[] = 
{
    {L"FS_Read", mmi_em_fs_test_result_view_chart_read_entry},
    {L"FS_Write", mmi_em_fs_test_result_view_chart_write_entry},
    {L"FSAL_Read", mmi_em_fs_test_result_view_chart_read_cache_entry},
    {L"FSAL_Write", mmi_em_fs_test_result_view_chart_write_cache_entry},
    {L"All Result", mmi_em_fs_test_result_view_text_entry}
};

#define EM_FS_TEST_VIEW_CHART_NUM  (sizeof(chart_views)/sizeof(em_fs_test_view_chart_entry_struct))


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_fs_test_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]fs init"); */

    applib_mem_ap_register(APPLIB_MEM_AP_ID_EM, EM_FS_TEST_ENTRY_STR_ID, IMG_GLOBAL_DEFAULT, mmi_em_fs_test_stop_buffer_callback);
    mmi_em_fs_test_engine_init();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_stop_buffer_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_stop_buffer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_fs_test_mutex_lock();
    if(mmi_em_fs_test_get_engine_status() == MMI_EM_FS_TEST_FMT_ENGINE_STATUS_RUNNING)
    {
            mmi_em_fs_test_set_engine_status(MMI_EM_FS_TEST_FMT_ENGINE_STATUS_ABORT);
    }
    mmi_em_fs_test_mutex_unlock();
    
    if (g_em_fs_test_context.buffer_for_fmt)
    {
        applib_mem_ap_free(g_em_fs_test_context.buffer_for_fmt);
        g_em_fs_test_context.buffer_for_fmt = NULL;
    }
    ClearProtocolEventHandler(MSG_ID_MMI_FMT_TEST_START_CNF);

    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_EM, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_hilite_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_fs_test_hilite_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]entry fs hilite main"); */

    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_em_fs_test_main_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_em_fs_test_main_entry, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);

    /* kal_prompt_trace(MOD_MMI,"[EM_FS]exit fs hilite main"); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_hilite_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_fs_test_hilite_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]entry fs hilite run"); */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_em_fs_test_start_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_em_fs_test_start_entry, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);

    /* kal_prompt_trace(MOD_MMI,"[EM_FS]exit fs hilite run"); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_hilite_disk_selection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_fs_test_hilite_disk_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]entry fs hilite disk selection"); */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_em_fs_test_disk_selection_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_em_fs_test_disk_selection_entry, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]exit fs hilite disk selection"); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_hilite_content_selection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_fs_test_hilite_content_selection(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]entry fs hilite content selection"); */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_em_fs_test_content_selection_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_em_fs_test_content_selection_entry, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]exit fs hilite content selection"); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_hilite_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_fs_test_hilite_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]entry fs hilite format"); */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_em_fs_test_format_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_em_fs_test_format_entry, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]exit fs hilite format"); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_hilite_help
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_fs_test_hilite_help(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]entry fs hilite help"); */
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_em_fs_test_help_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_em_fs_test_help_entry, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]exit fs hilite help"); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_main_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_main_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem;
    U16 nDispAttribute;
    U16 nStrItemList[10];
    U16 disk_index, index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]entry fs main entry"); */
    
     
    if (!CheckIsBackHistory())
    {

        extern void mmi_em_fs_test_fmt_test_init(void);

        /* init fs test engine */
        mmi_em_fs_test_fmt_test_init();

        for (index = 0; index < MMI_EM_FS_TEST_FMT_CATEGORY_TOTAL; index++)
            g_em_fs_test_context.content_state_info[index] = 0;

        g_em_fs_test_context.content_text_info[MMI_EM_FS_TEST_FMT_CATEGORY_BASIC] =
            (U8*) GetString(EM_FS_TEST_CASE_BASIC_STR_ID);
        g_em_fs_test_context.content_text_info[MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL] =
            (U8*) GetString(EM_FS_TEST_CASE_NORMAL_STR_ID);
        g_em_fs_test_context.content_text_info[MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE] =
            (U8*) GetString(EM_FS_TEST_CASE_ADVANCE_STR_ID);

        g_em_fs_test_context.content_count = MMI_EM_FS_TEST_FMT_CATEGORY_TOTAL;

        g_em_fs_test_context.drv_num = 0;
        for (disk_index = 0; disk_index < MMI_EM_FS_TEST_FMT_DISK_TOTAL; disk_index++)
        {
            g_em_fs_test_context.drv_letter[disk_index] = 0;
            g_em_fs_test_context.drv_state_info[disk_index] = 0;
            g_em_fs_test_context.drv_names[disk_index] = NULL;
        }

    }
    EntryNewScreen(EM_FS_TEST_SCR_ID, NULL, mmi_em_fs_test_main_entry, NULL);

    guiBuffer = GetCurrGuiBuffer(EM_FS_TEST_SCR_ID);

    SetParentHandler(EM_FS_TEST_MAIN_MENU_ID);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    nNumofItem = GetNumOfChild(EM_FS_TEST_MAIN_MENU_ID);

    nDispAttribute = GetDispAttributeOfItem(EM_FS_TEST_MAIN_MENU_ID);

    GetSequenceStringIds(EM_FS_TEST_MAIN_MENU_ID, nStrItemList);

    ShowCategory52Screen(
        EM_FS_TEST_MAIN_TITLE_STR_ID,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        MMI_EM_INDEX_ICON_LIST,
        NULL,
        0,
        0,
        guiBuffer);

    /* set the delete callback, if "endkey" is pressed, this call will be invoked */
    SetDelScrnIDCallbackHandler(EM_FS_TEST_SCR_ID, mmi_em_fs_test_del_main_entry_screen);
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]exit fs main entry"); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_start_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_em_fs_test_start_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    MMI_BOOL check_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     
    check_result = MMI_FALSE;
    for (index = 0; index < g_em_fs_test_context.drv_num; index++)
    {
        if (g_em_fs_test_context.drv_state_info[index])
        {
            check_result = MMI_TRUE;
            break;
        }
    }

    if (!check_result)
    {
        mmi_em_fs_test_popup((U8*) GetString(EM_FS_TEST_SELECTION_DISK_FIRST_STR_ID), IMG_GLOBAL_WARNING);
        return MMI_FALSE;
    }

    check_result = MMI_FALSE;
    for (index = 0; index < g_em_fs_test_context.content_count; index++)
    {
        if (g_em_fs_test_context.content_state_info[index])
        {
            check_result = MMI_TRUE;
            break;
        }
    }
    if (!check_result)
    {
        mmi_em_fs_test_popup((U8*) GetString(EM_FS_TEST_SELECTION_CONTENT_FIRST_STR_ID), IMG_GLOBAL_WARNING);
        return MMI_FALSE;
    }

    check_result = MMI_FALSE;

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_start_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_start_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_fs_test_fmt_start_req_struct *start_test_req;
    U16 index;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]entry fs run entry"); */

    if (!CheckIsBackHistory())
    {
        if (!mmi_em_fs_test_start_check())
            return;

         mmi_em_fs_test_mutex_lock();
    if(mmi_em_fs_test_get_engine_status() == MMI_EM_FS_TEST_FMT_ENGINE_STATUS_RUNNING)
    {
            mmi_em_fs_test_set_engine_status(MMI_EM_FS_TEST_FMT_ENGINE_STATUS_ABORT);
    }
    mmi_em_fs_test_mutex_unlock();

    
        if(g_em_fs_test_context.buffer_for_fmt!=NULL)
        {
            applib_mem_ap_free(g_em_fs_test_context.buffer_for_fmt);
            g_em_fs_test_context.buffer_for_fmt = NULL;
        }
        
        /* alloc temp buffer for fs test engine */
        g_em_fs_test_context.buffer_for_fmt = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_EM, 32 * 1024);
        
        if(g_em_fs_test_context.buffer_for_fmt == NULL)
        {
            mmi_em_fs_test_popup((U8 *)L"Can't alloc memory",IMG_GLOBAL_WARNING);
            return;

        }

        start_test_req =
            (mmi_em_fs_test_fmt_start_req_struct*) OslConstructDataPtr(sizeof(mmi_em_fs_test_fmt_start_req_struct));

        for (index = 0; index < MMI_EM_FS_TEST_FMT_CATEGORY_TOTAL; index++)
            start_test_req->category[index] = g_em_fs_test_context.content_state_info[index];

        for (index = 0; index < MMI_EM_FS_TEST_FMT_DISK_TOTAL; index++)
        {
            if (g_em_fs_test_context.drv_state_info[index])
                start_test_req->drv_letter[index] = g_em_fs_test_context.drv_letter[index];
            else
                start_test_req->drv_letter[index] = 0;
        }

        start_test_req->buffer = g_em_fs_test_context.buffer_for_fmt;

        /* SetProtocolEventHandler(mmi_em_fs_test_start_rsq_handler, MSG_ID_MMI_FMT_TEST_START_CNF); */
        SetProtocolEventHandler(mmi_em_fs_test_finish_rsq_handler, MSG_ID_MMI_FMT_TEST_FINISH_IND);
        mmi_frm_send_ilm(MOD_FMT, MSG_ID_MMI_FMT_TEST_START_REQ, 
                        (oslParaType*)start_test_req, NULL);
    }

    EntryNewScreen(EM_FS_TEST_START_TEST_SCR_ID, NULL, mmi_em_fs_test_start_entry, NULL);

    guiBuffer = GetCurrGuiBuffer(EM_FS_TEST_START_TEST_SCR_ID);

    ShowCategory8Screen(
        EM_FS_TEST_START_TITLE_STR_ID,
        0,
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        EM_FS_TEST_RUNNING_WAITING_STR_ID,
        IMG_GLOBAL_PROGRESS,
        guiBuffer);

    ClearInputEventHandler(MMI_DEVICE_KEY);

    SetRightSoftkeyFunction(mmi_em_fs_test_cancel_entry, KEY_EVENT_UP);

    /* kal_prompt_trace(MOD_MMI,"[EM_FS]exit fs run entry"); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_del_start_entry_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [?]     
 * RETURNS
 *  
 *****************************************************************************/
static U8 mmi_em_fs_test_del_main_entry_screen(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     mmi_em_fs_test_mutex_lock();
    if(mmi_em_fs_test_get_engine_status() == MMI_EM_FS_TEST_FMT_ENGINE_STATUS_RUNNING)
    {
            mmi_em_fs_test_set_engine_status(MMI_EM_FS_TEST_FMT_ENGINE_STATUS_ABORT);
    }
    mmi_em_fs_test_mutex_unlock();
    
    if (g_em_fs_test_context.buffer_for_fmt)
    {
        applib_mem_ap_free(g_em_fs_test_context.buffer_for_fmt);
        g_em_fs_test_context.buffer_for_fmt = NULL;
    }
    ClearProtocolEventHandler(MSG_ID_MMI_FMT_TEST_START_CNF);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_disk_selection_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_disk_selection_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    S16 index;
    SRV_FMGR_DRVLIST_HANDLE handle = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        EM_FS_TEST_DISK_SELECTION_SCR_ID,
        mmi_em_fs_test_disk_selection_exit,
        mmi_em_fs_test_disk_selection_entry,
        NULL);
    gui_buffer = GetCurrGuiBuffer(EM_FS_TEST_DISK_SELECTION_SCR_ID);

    /* get all exist drive letter */
    //mmi_fmgr_get_exist_drive_letter(g_em_fs_test_context.drv_letter, &g_em_fs_test_context.drv_num);

    handle = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
    g_em_fs_test_context.drv_num =(U8) srv_fmgr_drivelist_count(handle);

    for (index = 0; index < g_em_fs_test_context.drv_num && index < MMI_EM_FS_TEST_FMT_DISK_TOTAL; index++)
	{
		g_em_fs_test_context.drv_letter[index] = (S8)srv_fmgr_drivelist_get_drv_letter(handle, index);
	}

    srv_fmgr_drivelist_destroy(handle);

    if (g_em_fs_test_context.drv_num <= 0)
    {
        mmi_em_fs_test_popup((U8*) L"No disk", IMG_GLOBAL_WARNING);
        DeleteScreenIfPresent(EM_FS_TEST_DISK_SELECTION_SCR_ID);
        return;
    }
    //ASSERT(g_em_fs_test_context.drv_num <= MMI_EM_FS_TEST_FMT_DISK_TOTAL);
    if(g_em_fs_test_context.drv_num>MMI_EM_FS_TEST_FMT_DISK_TOTAL)
        {
        mmi_em_fs_test_popup((U8*) L"Only support two disks!", IMG_GLOBAL_WARNING);
        DeleteScreenIfPresent(EM_FS_TEST_DISK_SELECTION_SCR_ID);
        return;
        }

    /* get all drive's name */
    for (index = g_em_fs_test_context.drv_num - 1; index >= 0; index--)
    {
        g_em_fs_test_context.drv_names[index] = (S8*) applib_mem_screen_alloc(MMI_EM_FS_TEST_MAX_DRIVE_NAME_LEN);
        if (g_em_fs_test_context.drv_names[index] == 0)
        {
            mmi_em_fs_test_popup((U8*) L"Can't alloc memory", IMG_GLOBAL_ERROR);
            DeleteScreenIfPresent(EM_FS_TEST_DISK_SELECTION_SCR_ID);
            return;
        }
        srv_fmgr_drv_get_name(
            (U8)(g_em_fs_test_context.drv_letter[index]), /* drive letter */
            (WCHAR*)(g_em_fs_test_context.drv_names[index]),  /* drive name */
            MMI_EM_FS_TEST_MAX_DRIVE_NAME_LEN /* max drive name length */ );
    }

    /* set check action */
    SetCheckboxToggleRightSoftkeyFunctions(GoBackHistory, GoBackHistory);

    /* show check selection screen */
    ShowCategory140Screen(
        EM_FS_TEST_DISK_SELECTION_TITLE_STR_ID,
        0,
        g_em_fs_test_context.drv_num,
        (U8 **) g_em_fs_test_context.drv_names,
        g_em_fs_test_context.drv_state_info,
        0,
        gui_buffer);
    ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_disk_selection_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_disk_selection_exit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = g_em_fs_test_context.drv_num - 1; index >= 0; index--)
    {
        if (g_em_fs_test_context.drv_names[index])
            applib_mem_screen_free(g_em_fs_test_context.drv_names[index]);
        g_em_fs_test_context.drv_names[index] = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_content_selection_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_content_selection_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_FS_TEST_CONTENT_SELECTION_SCR_ID, NULL, mmi_em_fs_test_content_selection_entry, NULL);
    gui_buffer = GetCurrGuiBuffer(EM_FS_TEST_CONTENT_SELECTION_SCR_ID);
    SetCheckboxToggleRightSoftkeyFunctions(GoBackHistory, GoBackHistory);
    ShowCategory140Screen(
        EM_FS_TEST_CONTENT_SELECTION_TITLE_STR_ID,
        0,
        g_em_fs_test_context.content_count,
        (U8 **) (g_em_fs_test_context.content_text_info),
        g_em_fs_test_context.content_state_info,
        0,
        gui_buffer);
    ChangeRightSoftkey(STR_GLOBAL_DONE, 0);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_format_finish_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_format_finish_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_fmt_format_rsp_strcut *rsp = (mmi_fmt_format_rsp_strcut *)msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(rsp->result == FS_NO_ERROR)
	{
		mmi_em_fs_test_popup((U8*) GetString(EM_FS_TEST_FINISH_TIP_STR_ID),IMG_GLOBAL_INFO);
	}
	else if(rsp->result == FS_DEVICE_BUSY)
	{
		mmi_em_fs_test_popup((U8*) L"Device is busy",IMG_GLOBAL_ERROR);
	}
	else if(rsp->result == FS_DRIVE_NOT_FOUND)
	{
		mmi_em_fs_test_popup((U8*) L"Drive not found",IMG_GLOBAL_ERROR);
	}
	else 
	{
		mmi_em_fs_test_popup((U8*) L"Format failed",IMG_GLOBAL_ERROR);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_format_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drive       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_format_handler(S8 drive)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* MYQUEUE message; */

    /* mmi_fmt_format_req_strcut *req; */

    /* void *guiBuffer=NULL; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((S16) drive <= 0)
        return;
    /*
     * ShowCategory8Screen(
     * EM_FS_TEST_FORMAT_STR_ID,
     * 0,
     * STR_GLOBAL_YES,
     * 0,
     * STR_GLOBAL_NO,
     * 0,
     * EM_FS_TEST_FORMAT_TIP_STR_ID,
     * IMG_GLOBAL_PROGRESS,
     * guiBuffer);
     * 
     * SetLeftSoftkeyFunction(mmi_em_fs_test_format_handler_int, KEY_EVENT_UP);
     * SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
     * 
     * SetKeyHandler(mmi_em_fs_test_format_handler_int, KEY_RIGHT_ARROW, KEY_EVENT_UP);
     * SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);
     */
    mmi_em_fs_test_format_handler_int(drive);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_format_handler_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drive       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_format_handler_int(S8 drive)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmt_format_req_strcut *req;

    void *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (mmi_fmt_format_req_strcut*) OslConstructDataPtr(sizeof(mmi_fmt_format_req_strcut));
    req->drive = drive;
    req->level = FS_FORMAT_HIGH;

    SetProtocolEventHandler(mmi_em_fs_test_format_finish_handler, MSG_ID_MMI_FMT_FORMAT_RSP);
    mmi_frm_send_ilm(MOD_FMT, MSG_ID_MMI_FMT_FORMAT_REQ, 
                        (oslParaType*)req, NULL);
    
    EntryNewScreen(EM_FS_TEST_FORMAT_SCR_ID, NULL, NULL, NULL);

    ShowCategory8Screen(
        EM_FS_TEST_FORMAT_STR_ID,
        0,
        0,
        0,
        0,
        0,
        EM_FS_TEST_FORMAT_STR_ID,
        IMG_GLOBAL_PROGRESS,
        guiBuffer);

    ClearInputEventHandler(MMI_DEVICE_KEY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_format_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_format_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]entry fs format entry"); */

    mmi_fmgr_select_drive(APPLIB_MEM_AP_ID_EM, mmi_em_fs_test_format_handler, 0);

    /* kal_prompt_trace(MOD_MMI,"[EM_FS]exit fs main entry"); */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_help_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_help_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    S8 *buffer = GetString(EM_FS_TEST_HELP_CONTENT_STR_ID);

    S32 buffer_len = (S32) (kal_wstrlen((const WCHAR*)buffer) * 2);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(EM_FS_TEST_HELP_SCR_ID, NULL, mmi_em_fs_test_help_entry, NULL);

    guiBuffer = GetCurrGuiBuffer(EM_FS_TEST_HELP_SCR_ID);

    ShowCategory74Screen(
        EM_FS_TEST_HELP_TITLE_STR_ID,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) buffer,
        buffer_len,
        guiBuffer);

    SetLeftSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_RIGHT_ARROW, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_start_rsq_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_start_rsq_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //kal_prompt_trace(MOD_MMI,"[EM_FS]entry start rsq callback");
    //do nothing

    /* kal_prompt_trace(MOD_MMI,"[EM_FS]exit start rsq callback"); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    U16 listItems[2] = {EM_FS_TEST_RESULT_SAVE_STR_ID, EM_FS_TEST_RESULT_VIEW_STR_ID};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]entry fs run entry"); */

    EntryNewScreen(EM_FS_TEST_RESULT_SCR_ID, NULL, mmi_em_fs_test_result_entry, NULL);

    guiBuffer = GetCurrGuiBuffer(EM_FS_TEST_RESULT_SCR_ID);

    SetParentHandler(0);

    RegisterHighlightHandler(mmi_em_fs_test_result_menu_hilite_handler);

    ShowCategory15Screen(
        EM_FS_TEST_RESULT_TITLE_STR_ID,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        2,
        (U16*) listItems,
        MMI_EM_INDEX_ICON_LIST,
        LIST_MENU,
        0,
        guiBuffer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_menu_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_menu_hilite_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index == 0)
    {
        SetLeftSoftkeyFunction(mmi_em_fs_test_result_save_entry, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

        SetKeyHandler(mmi_em_fs_test_result_save_entry, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);
    }
    else if (item_index == 1)
    {
        SetLeftSoftkeyFunction(mmi_em_fs_test_result_view_disk_selection_entry, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

        SetKeyHandler(mmi_em_fs_test_result_view_disk_selection_entry, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_save_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_save_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_fs_test_fmt_save_data_req_struct *req;

    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_em_fs_test_context.drv_num > 0);

    if (!CheckIsBackHistory())
    {
        if (g_em_fs_test_context.buffer_for_fmt == NULL)
        {
            g_em_fs_test_context.buffer_for_fmt = applib_mem_ap_alloc(APPLIB_MEM_AP_ID_EM, 32 * 1024);

            /* ASSERT(g_em_fs_test_context.buffer_for_fmt); */
            if (g_em_fs_test_context.buffer_for_fmt == NULL)
            {
                mmi_em_fs_test_popup((U8*) L"Can't alloc memory", IMG_GLOBAL_ERROR);
                return;
            }
        }

        req =
            (mmi_em_fs_test_fmt_save_data_req_struct*)
            OslConstructDataPtr(sizeof(mmi_em_fs_test_fmt_save_data_req_struct));

        for (index = 0; index < MMI_EM_FS_TEST_FMT_DISK_TOTAL; index++)
        {
            req->data_ptr[index] = &(test_result_data[index]);
        }

        req->bufffer = g_em_fs_test_context.buffer_for_fmt;

        kal_wsprintf(
            req->file_name,
            "%c:\\%w",
            g_em_fs_test_context.drv_letter[0],
            get_string(EM_FS_TEST_SAVE_FILE_NAME_PREFIX_STR_ID));

        SetProtocolEventHandler(mmi_em_fs_test_result_save_finish_handler, MSG_ID_MMI_FMT_TEST_SAVE_CNF);
        mmi_frm_send_ilm(MOD_FMT, MSG_ID_MMI_FMT_TEST_SAVE_REQ, 
                        (oslParaType*)req, NULL);

    }
    EntryNewScreen(EM_FS_TEST_RESULT_SAVE_SCR_ID, NULL, mmi_em_fs_test_result_save_entry, NULL);

    ShowCategory8Screen(
        EM_FS_TEST_RESULT_SAVE_STR_ID,
        0,
        0,
        0,
        0,
        0,
        EM_FS_TEST_RESULT_SAVE_WAITING_STR_ID,
        IMG_GLOBAL_PROGRESS,
        NULL);

    ClearInputEventHandler(MMI_DEVICE_KEY);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_save_finish_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_save_finish_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_em_fs_test_fmt_save_data_cnf_struct * message = (mmi_em_fs_test_fmt_save_data_cnf_struct *)msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(message == NULL)
    {
        ASSERT(0);
    }
    
    if(message->result == MMI_EM_FS_TEST_FMT_SAVE_NO_ERROR)
	{	
		DisplayPopup((U8*) GetString(EM_FS_TEST_RESULT_SAVE_FINISH_TIP_STR_ID),IMG_GLOBAL_INFO,0, 
		2000, 0);
	}
    else if(message->result == MMI_EM_FS_TEST_FMT_SAVE_DISK_FULL)
	{
		DisplayPopup((U8*) L"Save failed! Disk is full",IMG_GLOBAL_ERROR,0, 2000, 0);
	}
    else
        {
            DisplayPopup((U8*) L"Save failed! Unknown reason",IMG_GLOBAL_ERROR,0, 
            2000, 0);
        }

    DeleteScreenIfPresent(EM_FS_TEST_RESULT_SAVE_SCR_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_disk_selection_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_disk_selection_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    U16 nStrItemList[MMI_EM_FS_TEST_FMT_DISK_TOTAL];

    U16 disk_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]entry fs result view entry"); */

    /* ASSERT(g_em_fs_test_context.drv_num); */
    if (g_em_fs_test_context.drv_num <= 0)
    {
        return;
    }

    if (g_em_fs_test_context.drv_state_info[MMI_EM_FS_TEST_FMT_DISK_PHONE])
    {
        nStrItemList[disk_index++] = EM_FS_TEST_DISK_PHONE_STR_ID;
    }
#if defined(__FS_CARD_SUPPORT__)
    if (g_em_fs_test_context.drv_state_info[MMI_EM_FS_TEST_FMT_DISK_MEMORY_CARD])
    {
        nStrItemList[disk_index++] = EM_FS_TEST_DISK_MEMORY_CARD_STR_ID;
    }
#endif /* defined(__FS_CARD_SUPPORT__) */ 

    EntryNewScreen(EM_FS_TEST_RESULT_VIEW_SCR_ID, NULL, mmi_em_fs_test_result_view_disk_selection_entry, NULL);

    guiBuffer = GetCurrGuiBuffer(EM_FS_TEST_RESULT_VIEW_SCR_ID);

    SetParentHandler(0);

    RegisterHighlightHandler(mmi_em_fs_test_result_view_disk_selection_menu_hilite_handler);

    ShowCategory55Screen(
        EM_FS_TEST_DISK_SELECTION_TITLE_STR_ID,
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        disk_index,
        nStrItemList,
        NULL,
        0,
        guiBuffer);

    /* kal_prompt_trace(MOD_MMI,"[EM_FS]exit fs result view entry"); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_disk_selection_menu_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_disk_selection_menu_hilite_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(item_index >= 0 && item_index < MMI_EM_FS_TEST_FMT_DISK_TOTAL);

	g_em_fs_test_current_disk_index = item_index;
	if (!g_em_fs_test_context.drv_state_info[MMI_EM_FS_TEST_FMT_DISK_PHONE])
    {
#if defined(__FS_CARD_SUPPORT__)
		if (g_em_fs_test_context.drv_state_info[MMI_EM_FS_TEST_FMT_DISK_MEMORY_CARD])
		{
			g_em_fs_test_current_disk_index++;
		}
#endif /* defined(__FS_CARD_SUPPORT__) */ 
    }
    SetLeftSoftkeyFunction(mmi_em_fs_test_result_view_chart_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_em_fs_test_result_view_chart_entry, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_chart_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_chart_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *nStrItemList[EM_FS_TEST_VIEW_CHART_NUM];
    U16 view_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]entry fs result view entry"); */

    //if (EM_FS_TEST_VIEW_CHART_NUM <= 0)
    //{
    //}

    for (view_index = 0; view_index < EM_FS_TEST_VIEW_CHART_NUM; view_index++)
    {
        nStrItemList[view_index] = (U8*) chart_views[view_index].entry_name;
    }

    EntryNewScreen(EM_FS_TEST_RESULT_VIEW_SCR_ID, NULL, mmi_em_fs_test_result_view_chart_entry, NULL);

    guiBuffer = GetCurrGuiBuffer(EM_FS_TEST_RESULT_VIEW_SCR_ID);

    SetParentHandler(0);

    RegisterHighlightHandler(mmi_em_fs_test_result_view_chart_menu_hilite_handler);

    ShowCategory353Screen(
        (U8*) get_string(EM_FS_TEST_DISK_SELECTION_TITLE_STR_ID),
        0,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        EM_FS_TEST_VIEW_CHART_NUM,
        nStrItemList,
        MMI_EM_INDEX_ICON_LIST,
        NULL,
        0,
        0,
        guiBuffer);

    /* kal_prompt_trace(MOD_MMI,"[EM_FS]exit fs result view entry"); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_chart_menu_hilite_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_chart_menu_hilite_handler(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(item_index >= 0 && item_index < EM_FS_TEST_VIEW_CHART_NUM);

    SetLeftSoftkeyFunction(chart_views[item_index].entry_func, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(chart_views[item_index].entry_func, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_chart_read_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_chart_read_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 line_num = 2;

#if defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
    U32 point_num = 7;
    U32 basic_data[2][7];
#else /* defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__) */ 
    U32 point_num = 6;
    U32 basic_data[2][6];
#endif /* defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__) */ 
    S8 *lenged_title[2] = { /* (S8*)get_string(EM_FS_TEST_VIEW_LEGEND_BASIC_TEST_STR_ID),(S8*)get_string(EM_FS_TEST_VIEW_LEGEND_NORMAL_TEST_STR_ID) */
        (S8*) L"Basic Test", (S8*) L"Normal Test"
    };

    U32 *basic_test_case_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    basic_test_case_time = test_result_data[g_em_fs_test_current_disk_index].basic_test_case_time;

    basic_data[0][0] = basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_8_ID];
    basic_data[0][1] = basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_128_ID];
    basic_data[0][2] = basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_1k_ID];
    basic_data[0][3] = basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_2k_ID];
    basic_data[0][4] = basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_16k_ID];
    basic_data[0][5] = basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_32k_ID];

#if defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
    basic_data[0][6] = basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_16MB_ID];
#endif 

    basic_test_case_time = test_result_data[g_em_fs_test_current_disk_index].normal_test_case_time;
    basic_data[1][0] = basic_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_8_ID];
    basic_data[1][1] = basic_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_128_ID];
    basic_data[1][2] = basic_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_1k_ID];
    basic_data[1][3] = basic_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_2k_ID];
    basic_data[1][4] = basic_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_16k_ID];
    basic_data[1][5] = basic_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_32k_ID];

#if defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
    basic_data[1][6] = basic_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_16MB_ID];
#endif 

    EntryNewScreen(
        EM_FS_TEST_POPUP_SCR_ID,
        mmi_em_fs_test_result_view_chart_exit,
        mmi_em_fs_test_result_view_chart_read_entry,
        NULL);

    mmi_em_fs_test_show_category_screen(
        (U8*) get_string(EM_FS_TEST_FS_READ_STR_ID),
        0,
        STR_GLOBAL_HELP,
        0,
        STR_GLOBAL_BACK,
        0,
        (U32*) basic_data,
        (S8 **) lenged_title,
        point_num,
        line_num);

    SetLeftSoftkeyFunction(mmi_em_fs_test_result_view_chart_read_help_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_chart_write_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_chart_write_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 line_num = 2;

#if defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
    U32 point_num = 7;
    U32 basic_data[2][7];
#else /* defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__) */ 
    U32 point_num = 6;
    U32 basic_data[2][6];
#endif /* defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__) */ 

    S8 *lenged_title[2] = {(S8*) L"Basic Test", (S8*) L"Normal Test"};

    U32 *basic_test_case_time, *normal_test_case_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    basic_test_case_time = test_result_data[g_em_fs_test_current_disk_index].basic_test_case_time;
    basic_data[0][0] = basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_8_ID];
    basic_data[0][1] = basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_128_ID];
    basic_data[0][2] = basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_1k_ID];
    basic_data[0][3] = basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_2k_ID];
    basic_data[0][4] = basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_16k_ID];
    basic_data[0][5] = basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_32k_ID];

#if defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
    basic_data[0][6] = basic_test_case_time[MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_16MB_ID];
#endif 

    normal_test_case_time = test_result_data[g_em_fs_test_current_disk_index].normal_test_case_time;
    basic_data[1][0] = normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_8_ID];
    basic_data[1][1] = normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_128_ID];
    basic_data[1][2] = normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_1k_ID];
    basic_data[1][3] = normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_2k_ID];
    basic_data[1][4] = normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_16k_ID];
    basic_data[1][5] = normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_32k_ID];

#if defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
    basic_data[1][6] = normal_test_case_time[MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_16MB_ID];
#endif 
   
    EntryNewScreen(
        EM_FS_TEST_POPUP_SCR_ID,
        mmi_em_fs_test_result_view_chart_exit,
        mmi_em_fs_test_result_view_chart_write_entry,
        NULL);

    mmi_em_fs_test_show_category_screen(
        (U8*) get_string(EM_FS_TEST_FS_WRITE_STR_ID),
        0,
        STR_GLOBAL_HELP,
        0,
        STR_GLOBAL_BACK,
        0,
        (U32*) basic_data,
        (S8 **) lenged_title,
        point_num,
        line_num);

    SetLeftSoftkeyFunction(mmi_em_fs_test_result_view_chart_write_help_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_chart_read_cache_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_chart_read_cache_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 line_num = 4;
    U32 point_num = 5;
    U32 basic_data[4][5];
    S8 *lenged_title[4] = 
    {
        (S8*) L"32B", (S8*) L"512B", (S8*) L"2K", (S8*) L"16K"
    };

    U32 *advance_test_case_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    advance_test_case_time = test_result_data[g_em_fs_test_current_disk_index].advance_test_case_time;

    basic_data[0][0] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_1K_ID];
    basic_data[0][1] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_2K_ID];
    basic_data[0][2] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_4K_ID];
    basic_data[0][3] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_8K_ID];
    basic_data[0][4] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_16K_ID];

    basic_data[1][0] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_1K_ID];
    basic_data[1][1] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_2K_ID];
    basic_data[1][2] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_4K_ID];
    basic_data[1][3] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_8K_ID];
    basic_data[1][4] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_16K_ID];

    basic_data[2][0] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_1K_ID];
    basic_data[2][1] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_2K_ID];
    basic_data[2][2] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_4K_ID];
    basic_data[2][3] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_8K_ID];
    basic_data[2][4] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_16K_ID];

    basic_data[3][0] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_1K_ID];
    basic_data[3][1] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_2K_ID];
    basic_data[3][2] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_4K_ID];
    basic_data[3][3] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_8K_ID];
    basic_data[3][4] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_16K_ID];
    
    EntryNewScreen(
        EM_FS_TEST_POPUP_SCR_ID,
        mmi_em_fs_test_result_view_chart_exit,
        mmi_em_fs_test_result_view_chart_read_cache_entry,
        NULL);

    mmi_em_fs_test_show_category_screen(
        (U8*) get_string(EM_FS_TEST_FSAL_READ_STR_ID),
        0,
        STR_GLOBAL_HELP,
        0,
        STR_GLOBAL_BACK,
        0,
        (U32*) basic_data,
        (S8 **) lenged_title,
        point_num,
        line_num);

    SetLeftSoftkeyFunction(mmi_em_fs_test_result_view_chart_read_cache_help_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_chart_write_cache_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_chart_write_cache_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 line_num = 4;
    U32 point_num = 5;
    U32 basic_data[4][5];
    S8 *lenged_title[4] = 
    {
        (S8*) L"32B", (S8*) L"512B", (S8*) L"2K", (S8*) L"16K"
    };

    U32 *advance_test_case_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    advance_test_case_time = test_result_data[g_em_fs_test_current_disk_index].advance_test_case_time;

    basic_data[0][0] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_1K_ID];
    basic_data[0][1] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_2K_ID];
    basic_data[0][2] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_4K_ID];
    basic_data[0][3] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_8K_ID];
    basic_data[0][4] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_16K_ID];

    basic_data[1][0] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_1K_ID];
    basic_data[1][1] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_2K_ID];
    basic_data[1][2] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_4K_ID];
    basic_data[1][3] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_8K_ID];
    basic_data[1][4] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_16K_ID];

    basic_data[2][0] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_1K_ID];
    basic_data[2][1] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_2K_ID];
    basic_data[2][2] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_4K_ID];
    basic_data[2][3] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_8K_ID];
    basic_data[2][4] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_16K_ID];

    basic_data[3][0] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_1K_ID];
    basic_data[3][1] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_2K_ID];
    basic_data[3][2] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_4K_ID];
    basic_data[3][3] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_8K_ID];
    basic_data[3][4] = advance_test_case_time[MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_16K_ID];
  
    EntryNewScreen(
        EM_FS_TEST_POPUP_SCR_ID,
        mmi_em_fs_test_result_view_chart_exit,
        mmi_em_fs_test_result_view_chart_write_cache_entry,
        NULL);

    mmi_em_fs_test_show_category_screen(
        (U8*) get_string(EM_FS_TEST_FSAL_WRITE_STR_ID),
        0,
        STR_GLOBAL_HELP,
        0,
        STR_GLOBAL_BACK,
        0,
        (U32*) basic_data,
        (S8 **) lenged_title,
        point_num,
        line_num);

    SetLeftSoftkeyFunction(mmi_em_fs_test_result_view_chart_write_cache_help_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_em_fs_test_result_view_chart_goback, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_chart_read_help_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_chart_read_help_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buffer_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        EM_FS_TEST_HELP_SCR_ID,
        mmi_em_fs_test_result_view_text_exit,
        mmi_em_fs_test_result_view_chart_read_help_entry,
        NULL);

    g_em_fs_test_result_view_text_data = (WCHAR*) applib_mem_screen_alloc(EM_FS_TEST_SCREEN_MEMORY_SIZE);

    if (g_em_fs_test_result_view_text_data == 0)
    {
        mmi_em_fs_test_popup((U8*) L"Can't alloc memory", IMG_GLOBAL_ERROR);
        DeleteScreenIfPresent(EM_FS_TEST_HELP_SCR_ID);
        return;
    }

    kal_mem_set((void*)g_em_fs_test_result_view_text_data, 0x00, EM_FS_TEST_SCREEN_MEMORY_SIZE);

    kal_wsprintf(g_em_fs_test_result_view_text_data + buffer_size, "%w\n", L"X axis:read 8B,128B,1K,2K,16K,32K");
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        L"Y axis: the time of reading one KB data in second(KB/S),and the time is mapped to 0~1");
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    ShowCategory74Screen(
        STR_GLOBAL_HELP,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) g_em_fs_test_result_view_text_data,
        buffer_size,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_chart_write_help_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_chart_write_help_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buffer_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        EM_FS_TEST_HELP_SCR_ID,
        mmi_em_fs_test_result_view_text_exit,
        mmi_em_fs_test_result_view_chart_read_help_entry,
        NULL);

    g_em_fs_test_result_view_text_data = (WCHAR*) applib_mem_screen_alloc(EM_FS_TEST_SCREEN_MEMORY_SIZE);

    if (g_em_fs_test_result_view_text_data == 0)
    {
        mmi_em_fs_test_popup((U8*) L"Can't alloc memory", IMG_GLOBAL_ERROR);
        DeleteScreenIfPresent(EM_FS_TEST_HELP_SCR_ID);
        return;
    }

    kal_mem_set((void*)g_em_fs_test_result_view_text_data, 0x00, EM_FS_TEST_SCREEN_MEMORY_SIZE);

    kal_wsprintf(g_em_fs_test_result_view_text_data + buffer_size, "%w\n", L"X axis:write 8B,128B,1K,2K,16K,32K");
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        L"Y axis: the time of writing one KB data in second(KB/S),and the time is mapped to 0~1");
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    ShowCategory74Screen(
        STR_GLOBAL_HELP,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) g_em_fs_test_result_view_text_data,
        buffer_size,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_chart_read_cache_help_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_chart_read_cache_help_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buffer_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        EM_FS_TEST_HELP_SCR_ID,
        mmi_em_fs_test_result_view_text_exit,
        mmi_em_fs_test_result_view_chart_read_help_entry,
        NULL);

    g_em_fs_test_result_view_text_data = (WCHAR*) applib_mem_screen_alloc(EM_FS_TEST_SCREEN_MEMORY_SIZE);

    if (g_em_fs_test_result_view_text_data == 0)
    {
        mmi_em_fs_test_popup((U8*) L"Can't alloc memory", IMG_GLOBAL_ERROR);
        DeleteScreenIfPresent(EM_FS_TEST_HELP_SCR_ID);
        return;
    }

    kal_mem_set((void*)g_em_fs_test_result_view_text_data, 0x00, EM_FS_TEST_SCREEN_MEMORY_SIZE);

    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        L"X axis:the read buffer is  1K,2K,4K,8K,16K");
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        L"Y axis: the time of reading one KB data in second(KB/S),and the time is mapped to 0~1");
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    ShowCategory74Screen(
        STR_GLOBAL_HELP,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) g_em_fs_test_result_view_text_data,
        buffer_size,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_chart_write_cache_help_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_chart_write_cache_help_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buffer_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        EM_FS_TEST_HELP_SCR_ID,
        mmi_em_fs_test_result_view_text_exit,
        mmi_em_fs_test_result_view_chart_read_help_entry,
        NULL);

    g_em_fs_test_result_view_text_data = (WCHAR*) applib_mem_screen_alloc(EM_FS_TEST_SCREEN_MEMORY_SIZE);

    if (g_em_fs_test_result_view_text_data == 0)
    {
        mmi_em_fs_test_popup((U8*) L"Can't alloc memory", IMG_GLOBAL_ERROR);
        DeleteScreenIfPresent(EM_FS_TEST_HELP_SCR_ID);
        return;
    }

    kal_mem_set((void*)g_em_fs_test_result_view_text_data, 0x00, EM_FS_TEST_SCREEN_MEMORY_SIZE);

    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        L"X axis:the write buffer is  1K,2K,4K,8K,16K");
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        L"Y axis: the time of writing one KB data in second(KB/S),and the time is mapped to 0~1");
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    ShowCategory74Screen(
        STR_GLOBAL_HELP,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) g_em_fs_test_result_view_text_data,
        buffer_size,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_chart_text_help_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_chart_text_help_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buffer_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        EM_FS_TEST_HELP_SCR_ID,
        mmi_em_fs_test_result_view_text_exit,
        mmi_em_fs_test_result_view_chart_read_help_entry,
        NULL);

    g_em_fs_test_result_view_text_data = (WCHAR*) applib_mem_screen_alloc(EM_FS_TEST_SCREEN_MEMORY_SIZE);

    if (g_em_fs_test_result_view_text_data == 0)
    {

        mmi_em_fs_test_popup((U8*) L"Can't alloc memory", IMG_GLOBAL_ERROR);
        DeleteScreenIfPresent(EM_FS_TEST_HELP_SCR_ID);
        return;
    }

    kal_mem_set((void*)g_em_fs_test_result_view_text_data, 0x00, EM_FS_TEST_SCREEN_MEMORY_SIZE);

    kal_wsprintf(g_em_fs_test_result_view_text_data + buffer_size, "%w\n", L"All test APIs are listed in the view");
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    ShowCategory74Screen(
        STR_GLOBAL_HELP,
        0,
        0,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) g_em_fs_test_result_view_text_data,
        buffer_size,
        NULL);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_chart_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_chart_exit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_fs_test_view_deinit_layer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_chart_goback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_chart_goback()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GoBackToHistory(EM_FS_TEST_RESULT_VIEW_SCR_ID);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_println
 * DESCRIPTION
 *  
 * PARAMETERS
 *  outStr          [?]         [?]
 *  data_id         [IN]        
 *  data_type       [IN]        
 *  buffer_size     [?]         [?]
 *  result_uint     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_println(
                WCHAR *outStr,
                U32 data_id,
                U32 data_type,
                S32 *buffer_size,
                mmi_em_fs_test_fmt_result_uint result_uint)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 *test_time = NULL;
    U16 data_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_index = g_em_fs_test_current_disk_index;

    if (data_index == 0 && !g_em_fs_test_context.drv_state_info[MMI_EM_FS_TEST_FMT_DISK_PHONE])
    {
        data_index = g_em_fs_test_current_disk_index + 1;
    }

    if (data_type == MMI_EM_FS_TEST_FMT_CATEGORY_BASIC)
    {
        test_time = test_result_data[data_index].basic_test_case_time;
    }
    else if (data_type == MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL)
    {
        test_time = test_result_data[data_index].normal_test_case_time;
    }
    else if (data_type == MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE)
    {
        test_time = test_result_data[data_index].advance_test_case_time;
    }
    else
    {
        ASSERT(0);
    }

    if (test_time[data_id] != FMT_TEST_RESULT_TIME_MAX)
    {
        if (result_uint == MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S)
        {
            kal_wsprintf(g_em_fs_test_result_view_text_data + *buffer_size, "%w%u KB/S\n", outStr, test_time[data_id]);
        }
        else if (result_uint == MMI_EM_FS_TEST_FMT_RESULT_UINT_MS)
        {
            kal_wsprintf(g_em_fs_test_result_view_text_data + *buffer_size, "%w%u ms\n", outStr, test_time[data_id]);
        }
        else if (MMI_EM_FS_TEST_FMT_RESULT_UINT_S)
        {
            kal_wsprintf(g_em_fs_test_result_view_text_data + *buffer_size, "%w%u s\n", outStr, test_time[data_id]);
        }
        else
        {
            kal_wsprintf(g_em_fs_test_result_view_text_data + *buffer_size, "%w%u\n", outStr, test_time[data_id]);
        }
    }
    else
    {
        kal_wsprintf(g_em_fs_test_result_view_text_data + *buffer_size, "%w%d\n", outStr, test_time[data_id]);
    }
    *buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_text_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_text_entry()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 buffer_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        EM_FS_TEST_SETTING_SCR_ID,
        mmi_em_fs_test_result_view_text_exit,
        mmi_em_fs_test_result_view_text_entry,
        NULL);

    g_em_fs_test_result_view_text_data = (WCHAR*) applib_mem_screen_alloc(EM_FS_TEST_SCREEN_MEMORY_SIZE);

    if (g_em_fs_test_result_view_text_data == NULL)
    {

        mmi_em_fs_test_popup((U8*) L"Can't alloc memory", IMG_GLOBAL_ERROR);
        DeleteScreenIfPresent(EM_FS_TEST_SETTING_SCR_ID);
        return;
    }

    kal_mem_set((void*)g_em_fs_test_result_view_text_data, 0x00, EM_FS_TEST_SCREEN_MEMORY_SIZE);

    /* Basic Test */
    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        get_string(EM_FS_TEST_BASIC_DESCRIPTION_STR_ID));
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    /* remove */
    /*
     * kal_wsprintf(
     * g_em_fs_test_result_view_text_data + buffer_size,
     * "%w\n",
     * get_string(EM_FS_TEST_BASIC_READ_WRITE_16K_DESCRIPTION_STR_ID));
     * buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);
     */
    /* FS_Write-->8B,128B,1K,2K,16K,32K */
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_WRITE_8B_STR_ID),
        MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_8_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_BASIC,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_WRITE_128B_STR_ID),
        MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_128_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_BASIC,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_WRITE_1K_STR_ID),
        MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_1k_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_BASIC,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_WRITE_2K_STR_ID),
        MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_2k_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_BASIC,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_WRITE_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_16k_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_BASIC,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_WRITE_32K_STR_ID),
        MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_32k_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_BASIC,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    /* FS_Write End */

    /* FS_Read -->8B,128B,1K,2K,16K,32K */
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_READ_8B_STR_ID),
        MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_8_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_BASIC,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_READ_128B_STR_ID),
        MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_128_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_BASIC,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_READ_1K_STR_ID),
        MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_1k_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_BASIC,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_READ_2K_STR_ID),
        MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_2k_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_BASIC,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_READ_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_16k_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_BASIC,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_READ_32K_STR_ID),
        MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_32k_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_BASIC,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    /* FS_Read End */

#if defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        get_string(EM_FS_TEST_BASIC_READ_WRITE_16MB_DESCRIPTION_STR_ID));
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_WRITE_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_WRITE_16MB_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_BASIC,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_READ_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_READ_16MB_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_BASIC,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_DELETE_STR_ID),
        MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_DELETE_16MB_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_BASIC,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
#endif /* defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__) */ 

    /* Normal Test */
    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        (WCHAR*) get_string(EM_FS_TEST_NORMAL_DESCRIPTION_STR_ID));
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);
    /* remove */
    /*
     * kal_wsprintf(
     * g_em_fs_test_result_view_text_data + buffer_size,
     * "%w\n",
     * (WCHAR*) get_string(EM_FS_TEST_NORMAL_READ_WRITE_16K_DESCRIPTION_STR_ID));
     * buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);
     */

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_WRITE_8B_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_8_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_WRITE_128B_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_128_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_WRITE_1K_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_1k_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_WRITE_2K_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_2k_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_WRITE_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_16k_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_WRITE_32K_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_32k_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_READ_8B_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_8_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_READ_128B_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_128_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_READ_1K_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_1k_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_READ_2K_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_2k_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_READ_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_16k_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_READ_32K_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_32k_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);

#if defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__)
    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        get_string(EM_FS_TEST_NORMAL_READ_WRITE_16MB_DESCRIPTION_STR_ID));
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_WRITE_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_16MB_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_READ_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_16MB_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_DELETE_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_DELETE_16MB_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);
#endif /* defined(__MMI_EM_PROFILING_FS_TEST_FS_RW_16MB__) */ 

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_NORMAL_WRITE_FLUSH_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_FLUSH_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_NORMAL_WRITE_NO_FLUSH_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_WRITE_NO_FLUSH_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_NORMAL_READ_SELLP_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_SLEEP_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_NORMAL_READ_NO_SLEEP_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_READ_NO_SLEEP_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_NORMAL_OPEN_WRITE_READ_COLOSE_DELETE_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_OPEN_WRITE_READ_CLOSE_DELETE_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);

#if defined(__MMI_EM_PROFILING_FS_TEST_FS_SEEK__)
    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        get_string(EM_FS_TEST_NORMAL_FULL_DESCRIPTION_STR_ID));
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_NORMAL_OPEN_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_OPEN_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_NORMAL_SEEK_HEAD_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_SEEK_HEAD_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_NORMAL_SEEK_MID_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_SEEK_MID_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_NORMAL_SEEK_TAIL_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_SEEK_TAIL_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_NORMAL_CLOSE_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_CLOSE_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_DELETE_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_FULL_DELETE_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);

    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        get_string(EM_FS_TEST_NORMAL_5MB_DESCRIPTION_STR_ID));
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_NORMAL_OPEN_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_OPEN_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_NORMAL_SEEK_HEAD_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_SEEK_HEAD_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_NORMAL_SEEK_MID_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_SEEK_MID_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_NORMAL_SEEK_TAIL_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_SEEK_MID_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_NORMAL_CLOSE_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_SEEK_MID_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_DELETE_STR_ID),
        MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_5MB_DELETE_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);
#endif /* defined(__MMI_EM_PROFILING_FS_TEST_FS_SEEK__) */ 

    /* Adavnce Test */

    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        get_string(EM_FS_TEST_ADVANCE_DESCRIPTION_STR_ID));
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FIND_FIRST_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FIND_FIRST_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FIND_NEXT_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FIND_NEXT_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_MS);

    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_READ_WIRTH_CACHE_DESCRIPTION_STR_ID));
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_CACHE_1KB_DESCRIPTION_STR_ID));
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_32B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_1K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_512B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_1K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_2K_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_1K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_1K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_32B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_1K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_512B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_1K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);

    /*
     * mmi_em_fs_test_result_view_println(
     * (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_2K_STR_ID),
     * MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_1K_ID,
     * MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
     * &buffer_size);
     */
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_1K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);

    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_CACHE_2KB_DESCRIPTION_STR_ID));
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_32B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_2K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_512B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_2K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_2K_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_2K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_2K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_32B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_2K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_512B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_2K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    /*
     * mmi_em_fs_test_result_view_println(
     * (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_2K_STR_ID),
     * MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_2K_ID,
     * MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
     * &buffer_size);
     */
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_2K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);

    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_CACHE_4KB_DESCRIPTION_STR_ID));
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_32B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_4K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_512B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_4K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_2K_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_4K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_4K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_32B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_4K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_512B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_4K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    /*
     * mmi_em_fs_test_result_view_println(
     * (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_2K_STR_ID),
     * MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_4K_ID,
     * MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
     * &buffer_size,MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
     */
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_4K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);

    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_CACHE_8KB_DESCRIPTION_STR_ID));
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_32B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_8K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_512B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_8K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_2K_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_8K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_8K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_32B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_8K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_512B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_8K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    /*
     * mmi_em_fs_test_result_view_println(
     * (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_2K_STR_ID),
     * MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_8K_ID,
     * MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
     * &buffer_size);
     */
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_8K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);

    kal_wsprintf(
        g_em_fs_test_result_view_text_data + buffer_size,
        "%w\n",
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_CACHE_16KB_DESCRIPTION_STR_ID));
    buffer_size = kal_wstrlen(g_em_fs_test_result_view_text_data);

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_32B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_32B_16K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_512B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_512B_16K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_2K_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_2K_16K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_WRITE_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_WRITE_16K_16K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);

    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_32B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_32B_16K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_512B_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_512B_16K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
    /*
     * mmi_em_fs_test_result_view_println(
     * (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_2K_STR_ID),
     * MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_2K_16K_ID,
     * MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
     * &buffer_size,MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);
     */
    mmi_em_fs_test_result_view_println(
        (WCHAR*) get_string(EM_FS_TEST_ADVANCE_FSAL_READ_16K_STR_ID),
        MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_FSAL_READ_16K_16K_ID,
        MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE,
        &buffer_size,
        MMI_EM_FS_TEST_FMT_RESULT_UINT_KB_S);

    ShowCategory74Screen(
        EM_FS_TEST_TITLE_ALL_RESULT_STR_ID,
        0,
        STR_GLOBAL_HELP,
        0,
        STR_GLOBAL_BACK,
        0,
        (U8*) g_em_fs_test_result_view_text_data,
        buffer_size,
        NULL);

    SetLeftSoftkeyFunction(mmi_em_fs_test_result_view_chart_text_help_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_em_fs_test_result_view_chart_goback, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_result_view_text_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_result_view_text_exit()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_em_fs_test_result_view_text_data != NULL)
    {
        applib_mem_screen_free((void*)g_em_fs_test_result_view_text_data);
        g_em_fs_test_result_view_text_data = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_finish_rsq_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_finish_rsq_handler(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i, j;
    mmi_em_fs_test_fmt_finish_iln_struct *result_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //result_ptr = test_result_struct(mmi_em_fs_test_fmt_finish_iln_struct*) msg;
    result_ptr = &test_result_struct;
    
    for (i = 0; i < MMI_EM_FS_TEST_FMT_DISK_TOTAL; i++)
    {
        for (j = 0; j < MMI_EM_FS_TEST_FMT_CATEGORY_TOTAL; j++)
        {
            test_result_data[i].category[j] = result_ptr->data[i].category[j];
        }

        for (j = 0; j < MMI_EM_FS_TEST_FMT_BASE_TEST_CASE_TOTAL; j++)
        {
            test_result_data[i].basic_test_case_time[j] = result_ptr->data[i].basic_test_case_time[j];
        }
        for (j = 0; j < MMI_EM_FS_TEST_FMT_NORMAL_TEST_CASE_TOTAL; j++)
        {
            test_result_data[i].normal_test_case_time[j] = result_ptr->data[i].normal_test_case_time[j];
        }
        for (j = 0; j < MMI_EM_FS_TEST_FMT_ADVANCE_TEST_CASE_TOTAL; j++)
        {
            test_result_data[i].advance_test_case_time[j] = result_ptr->data[i].advance_test_case_time[j];
        }
    }

    if (g_em_fs_test_context.buffer_for_fmt)
    {
        applib_mem_ap_free(g_em_fs_test_context.buffer_for_fmt);
        g_em_fs_test_context.buffer_for_fmt = NULL;
    }

    /* kal_prompt_trace(MOD_MMI,"[EM_FS]entry finish rsq callback"); */

    mmi_em_fs_test_popup((U8*)GetString(EM_FS_TEST_FINISH_TIP_STR_ID), IMG_GLOBAL_INFO);
    HistoryReplace(EM_FS_TEST_START_TEST_SCR_ID, EM_FS_TEST_RESULT_SCR_ID, mmi_em_fs_test_result_entry);
    DeleteScreenIfPresent(EM_FS_TEST_CANCEL_REQ_SCR_ID);
    DeleteScreenIfPresent(EM_FS_TEST_CANCEL_RSP_SCR_ID);

    /* kal_prompt_trace(MOD_MMI,"[EM_FS]exit finish rsq callback"); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_cancel_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_cancel_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_prompt_trace(MOD_MMI,"[EM_FS]entry fs run entry"); */

    EntryNewScreen(EM_FS_TEST_CANCEL_REQ_SCR_ID, NULL, mmi_em_fs_test_cancel_entry, NULL);
    guiBuffer = GetCurrGuiBuffer(EM_FS_TEST_CANCEL_REQ_SCR_ID);

    ShowCategory8Screen(
        EM_FS_TEST_START_TITLE_STR_ID,
        0,
        STR_GLOBAL_YES,
        0,
        STR_GLOBAL_NO,
        0,
        EM_FS_TEST_CANCEL_TIP_STR_ID,
        IMG_GLOBAL_WARNING,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_em_fs_test_cancel_req_handler, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_em_fs_test_cancel_req_handler, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_cancel_req_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_cancel_req_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetProtocolEventHandler(mmi_em_fs_test_cancel_rsp_handler, MSG_ID_MMI_FMT_TEST_START_CNF);
   
    mmi_em_fs_test_set_engine_status(MMI_EM_FS_TEST_FMT_ENGINE_STATUS_ABORT);
    

    /* display popup */
    EntryNewScreen(EM_FS_TEST_CANCEL_RSP_SCR_ID, NULL, NULL, NULL);
    ShowCategory8Screen(
        EM_FS_TEST_CANCEL_TITLE_STR_ID,
        0,
        0,
        0,
        0,
        0,
        EM_FS_TEST_CANCEL_WAITING_STR_ID,
        IMG_GLOBAL_PROGRESS,
        NULL);

    ClearInputEventHandler(MMI_DEVICE_KEY);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_cancel_rsp_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_fs_test_cancel_rsp_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_em_fs_test_context.buffer_for_fmt)
    {
        applib_mem_ap_free(g_em_fs_test_context.buffer_for_fmt);
        g_em_fs_test_context.buffer_for_fmt = NULL;
    }

    DisplayPopup((U8 *)GetString(EM_FS_TEST_CANCEL_FINISH_TIP_STR_ID), IMG_GLOBAL_INFO, 0, 
    2000, 0);

    GoBackToHistory(EM_FS_TEST_SCR_ID);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_view_init_layers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_view_init_layers()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *buf_ptr = NULL;
    S32 byte_per_pixel = 0;
    S32 title_offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
    title_offset = 0;
#else 
    title_offset = MMI_status_bar_height;
#endif 

    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);

    gdi_layer_get_buffer_ptr(&buf_ptr);
    byte_per_pixel = (gdi_layer_get_bit_per_pixel() >> 3);

    if (status_icon_layer_handle == 0)
    {
        gdi_layer_create_cf_using_outside_memory(
            __MMI_MAIN_BASE_LAYER_FORMAT__,
            0,
            0,
            UI_device_width,
            MMI_status_bar_height,
            &status_icon_layer_handle,
            buf_ptr,
            UI_device_width * MMI_status_bar_height * byte_per_pixel);
        gdi_layer_push_and_set_active(status_icon_layer_handle);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }

    if (title_bar_layer_handle == 0)
    {
        gdi_layer_create_cf_using_outside_memory(
            __MMI_MAIN_BASE_LAYER_FORMAT__,
            0,
            title_offset,
            UI_device_width,
            MMI_title_height,
            &title_bar_layer_handle,
            buf_ptr + UI_device_width * title_offset * byte_per_pixel,
            UI_device_width * MMI_title_height * byte_per_pixel);
        gdi_layer_push_and_set_active(title_bar_layer_handle);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }

    if (base_layer_handle == 0)
    {
        gdi_layer_create_cf_using_outside_memory(
            __MMI_MAIN_BASE_LAYER_FORMAT__,
            0,
            title_offset + MMI_title_height,
            UI_device_width,
            UI_device_height - title_offset - MMI_title_height - MMI_softkey_height,
            &base_layer_handle,
            buf_ptr + UI_device_width * (title_offset + MMI_title_height) * byte_per_pixel,
            UI_device_width * (UI_device_height - title_offset - MMI_title_height - MMI_softkey_height) * byte_per_pixel);
        gdi_layer_push_and_set_active(base_layer_handle);
        //gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
		gdi_layer_clear(GDI_COLOR_WHITE);
        gdi_layer_pop_and_restore_active();
    }

    if (soft_key_layer_handle == 0)
    {

        gdi_layer_create_cf_using_outside_memory(
            __MMI_MAIN_BASE_LAYER_FORMAT__,
            0,
            UI_device_height - MMI_softkey_height,
            UI_device_width,
            MMI_softkey_height,
            &soft_key_layer_handle,
            buf_ptr + (UI_device_width * (UI_device_height - MMI_softkey_height) * byte_per_pixel),
            UI_device_width * MMI_softkey_height * byte_per_pixel);
        gdi_layer_push_and_set_active(soft_key_layer_handle);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }

    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    //gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    wgui_status_icon_bar_set_target_layer(
        WGUI_STATUS_ICON_BAR_H_BAR, 
        GDI_LAYER_MAIN_BASE_LAYER_HANDLE);

    gdi_layer_pop_and_restore_active();

#if defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
    wgui_status_icon_bar_enable_integrated(KAL_FALSE);
    wgui_status_icon_bar_register_integrated_redraw(NULL);
#endif /* defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_view_deinit_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_view_deinit_layer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE mmi_layer_handle = GDI_LAYER_MAIN_BASE_LAYER_HANDLE;
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (status_icon_layer_handle)
    {
        gdi_layer_free(status_icon_layer_handle);
        status_icon_layer_handle = 0;
    }

    if (title_bar_layer_handle)
    {
        gdi_layer_free(title_bar_layer_handle);
        title_bar_layer_handle = 0;
    }
    if (base_layer_handle)
    {
        gdi_layer_free(base_layer_handle);
        base_layer_handle = 0;
    }
    if (soft_key_layer_handle)
    {
        gdi_layer_free(soft_key_layer_handle);
        soft_key_layer_handle = 0;
    }

    wgui_status_icon_bar_reset_target_layer(WGUI_STATUS_ICON_BAR_H_BAR);

    wgui_status_icon_bar_reset_update_callback();

    ASSERT(current_MMI_theme->lite_disp_scr_bg_color);
    c = *current_MMI_theme->lite_disp_scr_bg_color;

    gdi_layer_push_and_set_active(mmi_layer_handle);
    gui_push_clip();
    gui_set_clip(0, MMI_status_bar_height, UI_device_width - 1, UI_device_height - 1);
    gui_fill_rectangle(0, MMI_status_bar_height, UI_device_width - 1, UI_device_height - MMI_button_bar_height - 1, c);
    gui_pop_clip();
    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_view_hide_status_icons_bar0
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_fs_test_view_hide_status_icons_bar0(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, y1, x2, y2;
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(current_MMI_theme->lite_disp_scr_bg_color);
    c = *current_MMI_theme->lite_disp_scr_bg_color;
    if ((GDI_HANDLE) wgui_status_icon_bar_get_target_layer(WGUI_STATUS_ICON_BAR_H_BAR) != GDI_ERROR_HANDLE)
    {
        gdi_layer_push_and_set_active(wgui_status_icon_bar_get_target_layer(WGUI_STATUS_ICON_BAR_H_BAR));
    }

    /* set clip region */
    gui_push_clip();
    wgui_status_icon_bar_get_clip(WGUI_STATUS_ICON_BAR_H_BAR, &x1, &y1, &x2, &y2);    /* get teh clip values of bar_id */
    gui_set_clip(x1, y1, x2, y2);

    gui_fill_rectangle(x1, y1, x2, y2, c);  /* fill the icon position with grey color */

    gui_pop_clip();

    if ((GDI_HANDLE) wgui_status_icon_bar_get_target_layer(WGUI_STATUS_ICON_BAR_H_BAR) != GDI_ERROR_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_view_show_status_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_view_show_status_bar()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
#if defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);
#else /* defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
    wgui_status_icon_bar_register_hide_callback(
        WGUI_STATUS_ICON_BAR_H_BAR, 
        mmi_em_fs_test_view_hide_status_icons_bar0);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_update();
#endif /* defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 
    gdi_layer_pop_and_restore_active();
}

#if defined (MMI_SHOW_STATUS_ICON_IN_TITLE)


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_title_oem_show_normal_ex
 * DESCRIPTION
 *  Show title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_em_fs_test_title_oem_show_normal_ex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

    if (status_icon_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_push_and_set_active(status_icon_layer_handle);
    }
    gui_title_oem_show_normal_ex();
    if (status_icon_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
    }

    wgui_status_icon_bar_register_integrated_redraw(mmi_em_fs_test_title_oem_show_normal_ex);
    gdi_layer_unlock_frame_buffer();
}
#endif /* defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_view_show_title
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_view_show_title(U16 *title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_HANDLE org_layer_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined (MMI_SHOW_STATUS_ICON_IN_TITLE)
    if (wgui_status_icon_bar_whether_integrated_enable())
    {
        wgui_status_icon_bar_enable_integrated(KAL_TRUE);
        wgui_status_icon_bar_register_integrated_redraw(mmi_em_fs_test_title_oem_show_normal_ex);
    }
#endif /* defined (MMI_SHOW_STATUS_ICON_IN_TITLE) */ 

    MMI_title_string = (UI_string_type) title;
    wgui_title_set_menu_shortcut_number(-1);
    MMI_title_icon = NULL;

    gdi_layer_lock_frame_buffer();
    org_layer_handle = gdi_set_alpha_blending_source_layer(title_bar_layer_handle);
    wgui_title_set_alpha_layer(title_bar_layer_handle);
    draw_title();
    gdi_set_alpha_blending_source_layer(org_layer_handle);
    gdi_layer_unlock_frame_buffer();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_view_show_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  left_softkey_label      [?]     [?]
 *  right_softkey_label     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_view_show_button(U16 *left_softkey_label, U16 *right_softkey_label)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_left_softkey_label((UI_string_type) left_softkey_label);
    set_right_softkey_label((UI_string_type) right_softkey_label);

    gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);

    gdi_layer_lock_frame_buffer();
    show_softkey_background();

    if ((MMI_softkeys[MMI_LEFT_SOFTKEY].text != NULL) || (MMI_softkeys[MMI_LEFT_SOFTKEY].normal_up_icon != NULL))
    {
        gui_show_icontext_button(&MMI_softkeys[MMI_LEFT_SOFTKEY]);
    }

    if ((MMI_softkeys[MMI_RIGHT_SOFTKEY].text != NULL) || (MMI_softkeys[MMI_RIGHT_SOFTKEY].normal_up_icon != NULL))
    {
        gui_show_icontext_button(&MMI_softkeys[MMI_RIGHT_SOFTKEY]);
    }

    gdi_layer_unlock_frame_buffer();

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_get_line_color
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static gdi_color mmi_em_fs_test_get_line_color(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index % 10)
    {
        case 0:
            return GDI_COLOR_RED;
        case 1:
            return GDI_COLOR_GREEN;
        case 2:
            return GDI_COLOR_GRAY;
        case 3:
            return GDI_COLOR_BLACK;
        case 4:
            return GDI_COLOR_RED;
        case 5:
            return FS_TEST_COLOR_DRAK_GREEN;
        case 6:
            return FS_TEST_COLOR_LIGTH_YELLOW;
        case 7:
            return FS_TEST_COLOR_INDIA_RED;
        case 8:
            return FS_TEST_COLOR_DRAK_RED;
        case 9:
            return FS_TEST_COLOR_ORGANGLE;
    }
    return GDI_COLOR_BLACK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_view_show_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data                [?]         [?]
 *  lenged_title        [IN]        
 *  point_num           [IN]        
 *  line_num            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_view_show_data(U32 *data, S8 **lenged_title, U32 point_num, U32 line_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 point_span_x;

    U32 point_span_y;

    U32 temp_x, temp_y, temp_next_x, temp_next_y, temp_data_1, temp_data_2;

    S32 line_index, point_index;

    U32 y_max_value;

    double scaling;

    S32 layer_width, layer_height;

    S32 x, y, width, height;
    S32 total_lenged_width;

    S32 left_margin, right_margin, top_margin, buttom_margin;

    S32 y_value_num = 10;

    S32 string_width, string_height;

    MMI_BOOL exist_data;

    stFontAttribute ui_font_type;

    const U16 *y_axis_string[11] =
        {L"  0", L"0.1", L"0.2", L"0.3", L"0.4", L"0.5", L"0.6", L"0.7", L"0.8", L"0.9", L"1.0", };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(base_layer_handle);
	
    gdi_layer_get_dimension(&layer_width, &layer_height);

    ui_font_type.type = 1;
    ui_font_type.bold = 0;
    ui_font_type.italic = 0;
    ui_font_type.underline = 0;
    ui_font_type.size = SMALL_FONT;
    ui_font_type.oblique = 0;

    gui_set_font(&ui_font_type);

    string_width = gui_get_string_width((UI_string_type) y_axis_string[0]);
    string_height = gui_get_string_height((UI_string_type) y_axis_string[0]);

    left_margin = string_width + 5;
    right_margin = 5;
    top_margin = 5;
    buttom_margin = string_height + 5;

    x = left_margin;
    y = layer_height - buttom_margin;

    width = layer_width - left_margin - right_margin;
    height = layer_height - top_margin - buttom_margin;

    /* x axis */
    gdi_draw_line(x, y, x + width + right_margin, y, GDI_COLOR_BLACK);

    gdi_draw_line(x + width + right_margin, y, x + width + right_margin - 5, y - 5, GDI_COLOR_BLACK);

    gdi_draw_line(x + width + right_margin, y, x + width + right_margin - 5, y + 5, GDI_COLOR_BLACK);

    /* y axis */
    gdi_draw_line(x, y, x, y - height - top_margin, GDI_COLOR_BLACK);

    gdi_draw_line(x, y - height - top_margin, x - 5, y - height - top_margin + 5, GDI_COLOR_BLACK);

    gdi_draw_line(x, y - height - top_margin, x + 5, y - height - top_margin + 5, GDI_COLOR_BLACK);

    if (point_num > 1)
    {
        point_span_x = width / (point_num - 1);
    }
    else
    {
        point_span_x = 0;
    }

    point_span_y = height / y_value_num;
    for (point_index = 0; point_index < point_num; point_index++)
    {
        gdi_draw_line(x + point_span_x * point_index, y, x + point_span_x * point_index, y - 5, GDI_COLOR_BLACK);
    }

    gui_set_text_color(gui_color(0, 0, 0));
    gui_set_font(&ui_font_type);
    for (line_index = 0; line_index <= y_value_num; line_index++)
    {
        gdi_draw_line(x, y - point_span_y * line_index, x + 5, y - point_span_y * line_index, GDI_COLOR_BLACK);
        gui_move_text_cursor(x - string_width - 5, y - point_span_y * line_index - string_height / 3);
        gui_print_text((UI_string_type) y_axis_string[line_index]);
    }

    y_max_value = 0;

    exist_data = MMI_FALSE;

    for (line_index = 0; line_index < line_num; line_index++)
    {
        for (point_index = 0; point_index < point_num; point_index++)
        {
            if (data[line_index * point_num + point_index] != FMT_TEST_RESULT_TIME_MAX)
            {
                exist_data = MMI_TRUE;

                if (data[line_index * point_num + point_index] > y_max_value)
                {
                    y_max_value = data[line_index * point_num + point_index];
                }
            }
        }
    }
    if (!exist_data)
    {
        gdi_layer_pop_and_restore_active();
        return;
    }

    if (y_max_value == 0)
        scaling = 1;
    else
        scaling = height * 1.0 / y_max_value;

    if (point_num <= 1)
    {
        for (line_index = 0; line_index < line_num; line_index++)
        {
            if (data[line_index * point_num + 0] == FMT_TEST_RESULT_TIME_MAX)
            {
                gdi_draw_rect(x - 2, y - 2, x + 2, y + 2, mmi_em_fs_test_get_line_color(line_index));
            }
            else
            {
                gdi_draw_point(
                    x,
                    y - scaling * data[line_index * point_num + 0],
                    mmi_em_fs_test_get_line_color(line_index));
            }
        }
    }
    else
    {
        for (line_index = 0; line_index < line_num; line_index++)
        {

            for (point_index = 0; point_index < point_num - 1; point_index++)
            {
                temp_data_1 = data[line_index * point_num + point_index];
                temp_data_2 = data[line_index * point_num + point_index + 1];
                temp_x = x + point_span_x * point_index;
                temp_next_x = x + point_span_x * (point_index + 1);

                if (temp_data_1 == FMT_TEST_RESULT_TIME_MAX)
                {
                    temp_data_1 = 0;
                    gdi_draw_rect(temp_x - 2, y - 2, temp_x + 2, y + 2, mmi_em_fs_test_get_line_color(line_index));
                }
                if (temp_data_2 == FMT_TEST_RESULT_TIME_MAX)
                {
                    temp_data_2 = 0;
                    gdi_draw_rect(
                        temp_next_x - 2,
                        y - 2,
                        temp_next_x + 2,
                        y + 2,
                        mmi_em_fs_test_get_line_color(line_index));
                }

                temp_y = y - scaling * temp_data_1;

                temp_next_y = y - scaling * temp_data_2;
                gdi_draw_line(temp_x, temp_y, temp_next_x, temp_next_y, mmi_em_fs_test_get_line_color(line_index));

            }
        }

    }

    total_lenged_width = 0;
    gui_set_font(&ui_font_type);
    for (line_index = 0; line_index < line_num; line_index++)
    {
        total_lenged_width += gui_get_string_width((UI_string_type) lenged_title[line_index]);
    }
    total_lenged_width += line_num * (10 + 5);

    x = (layer_width - total_lenged_width) / 2;

    x = x > 0 ? x : 0;

    gui_set_text_color(gui_color(0, 0, 0));
    for (line_index = 0; line_index < line_num; line_index++)
    {
        gdi_draw_line(
            x,
            y + string_height / 2 + 5,
            x + 10,
            y + string_height / 2 + 5,
            mmi_em_fs_test_get_line_color(line_index));
        x += 10 + 2;
        gui_move_text_cursor(x, y + 5);
        gui_print_text((UI_string_type) lenged_title[line_index]);
        x += gui_get_string_width((UI_string_type) lenged_title[line_index]) + 3;
    }

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_show_category_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  title                   [?]         [?]
 *  title_icon              [IN]        
 *  left_softkey            [IN]        
 *  left_softkey_icon       [IN]        
 *  right_softkey           [IN]        
 *  right_softkey_icon      [IN]        
 *  data                    [?]         [?]
 *  lenged_title            [IN]        
 *  point_num               [IN]        
 *  line_num                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_show_category_screen(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U32 *data,
                S8 **lenged_title,
                U32 point_num,
                U32 line_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_em_fs_test_view_init_layers();

    mmi_em_fs_test_view_show_status_bar();
    mmi_em_fs_test_view_show_title((U16*) title);
    mmi_em_fs_test_view_show_button(get_string(left_softkey), get_string(right_softkey));

	gdi_push_and_set_alpha_blending_source_layer(base_layer_handle);
    mmi_em_fs_test_view_show_data(data, lenged_title, point_num, line_num);
	gdi_layer_push_and_set_active(GDI_LAYER_MAIN_BASE_LAYER_HANDLE);
    //gdi_layer_blt_base_layer(0, 0, UI_device_width - 1, UI_device_height - 1);
	gdi_layer_flatten_to_base(GDI_LAYER_MAIN_BASE_LAYER_HANDLE,base_layer_handle,0,0);
    gdi_layer_flatten_to_base(GDI_LAYER_MAIN_BASE_LAYER_HANDLE,status_icon_layer_handle,0,0);
	gdi_layer_flatten_to_base(GDI_LAYER_MAIN_BASE_LAYER_HANDLE,title_bar_layer_handle,0,0);
	gdi_layer_blt(GDI_LAYER_MAIN_BASE_LAYER_HANDLE,soft_key_layer_handle,0,0,0,0,UI_device_width - 1, UI_device_height - 1);
	//gdi_layer_blt(base_layer_handle,status_icon_layer_handle,title_bar_layer_handle,soft_key_layer_handle,0,0,UI_device_width - 1, UI_device_height - 1);
	gdi_layer_pop_and_restore_active();
    gdi_pop_and_restore_alpha_blending_source_layer();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  message             [?]         
 *  message_icon        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_em_fs_test_popup(U8 *message, U16 message_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*EntryNewScreen(EM_FS_TEST_POPUP_SCR_ID, NULL, NULL, NULL);
    ShowCategory65Screen(message, message_icon, NULL);
    SetKeyHandler(GoBackHistory, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_RSK, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_CSK, KEY_EVENT_UP);
    */
    DisplayPopup(message,message_icon,0,2000,0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_em_fs_test_get_obj_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_em_fs_test_get_obj_status(mmi_em_fs_test_obj_enum obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (obj)
    {
        case MMI_EM_FS_TEST_OBJ_PHONE:
            return g_em_fs_test_context.drv_state_info[MMI_EM_FS_TEST_FMT_DISK_PHONE];
        case MMI_EM_FS_TEST_OBJ_MEMORY_CARD:
    #if defined(__FS_CARD_SUPPORT__)
            return g_em_fs_test_context.drv_state_info[MMI_EM_FS_TEST_FMT_DISK_MEMORY_CARD];
    #endif 
            return MMI_FALSE;
        case MMI_EM_FS_TEST_OBJ_BASIC:
            return g_em_fs_test_context.content_state_info[MMI_EM_FS_TEST_FMT_CATEGORY_BASIC] > 0;
        case MMI_EM_FS_TEST_OBJ_NORMAL:
            return g_em_fs_test_context.content_state_info[MMI_EM_FS_TEST_FMT_CATEGORY_NORMAL] > 0;
        case MMI_EM_FS_TEST_OBJ_ADVANCE:
            return g_em_fs_test_context.content_state_info[MMI_EM_FS_TEST_FMT_CATEGORY_ADVANCE] > 0;
    }
    return MMI_FALSE;
}
#endif /* ( defined (__MMI_EM_PROFILING_FS_TEST__) && !defined(FMT_NOT_PRESENT) && !defined(__L1_STANDALONE__) && !defined(__MAUI_BASIC__)) */ 

