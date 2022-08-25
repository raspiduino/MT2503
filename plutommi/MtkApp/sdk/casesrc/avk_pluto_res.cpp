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

extern "C"
{
#include "mdi_audio.h"
#include "AlertScreen.h"
#include "mmi_frm_events.h"
}

typedef struct
{
    mdi_handle aud_handle;
    MMI_BOOL is_hilight;
} avk_pluto_res_struct;

static avk_pluto_res_struct g_avk_pluto_res;


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_res_001_number_key
 * DESCRIPTION
 *  add menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_pluto_res_001_number_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_avk_pluto_res.is_hilight = MMI_TRUE;
    ClearHiliteHandler(MENU_ID_AVK_PLUTO_RES_1);
    ClearHiliteHandler(MENU_ID_AVK_PLUTO_RES_2);
    ClearHintHandler(MENU_ID_AVK_PLUTO_RES_1);
    ClearHintHandler(MENU_ID_AVK_PLUTO_RES_2);
    //mmi_popup_display_simple(L"Hilight/hint function unable!", MMI_EVENT_WARNING, AVK_MAIN_GRP_ID, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_res_001_menuitem_exit
 * DESCRIPTION
 *  add menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_pluto_res_001_menuitem_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_avk_pluto_res.aud_handle != 0)
    {
        mdi_audio_mma_stop(g_avk_pluto_res.aud_handle);
        mdi_audio_mma_close(g_avk_pluto_res.aud_handle);
        g_avk_pluto_res.aud_handle = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_res_001_key_left
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_pluto_res_001_key_left(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_res_001_key_right
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_pluto_res_001_key_right(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_res_001_hilight
 * DESCRIPTION
 *  add menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_pluto_res_001_hilight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 current_keymap[] = {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9};
    U8 current_key_count = 10;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set key handler */
//    SetLeftSoftkeyFunction(avk_pluto_res_001_key_left, KEY_EVENT_UP);
//    SetRightSoftkeyFunction(avk_pluto_res_001_key_right, KEY_EVENT_UP);
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_ENTER, KEY_EVENT_UP);
    ClearKeyHandler(KEY_ENTER, KEY_EVENT_UP);

    SetGroupKeyHandler(avk_pluto_res_001_number_key, (PU16) current_keymap, current_key_count, KEY_EVENT_DOWN);

    PowerAndEndKeyHandler();    /* the api will be called when EntryNewScreen is called automatic,so it is unnecessary here */
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_res_001_hint
 * DESCRIPTION
 *  add menuitem
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_pluto_res_001_hint(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_wcscpy((U16*) hintData[index], (U16*) L"vs_test");
}


/*****************************************************************************
 * FUNCTION
 *  avk_pluto_res_001_menuitem
 * DESCRIPTION
 *  add menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void avk_pluto_res_001_menuitem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16];
    U16 nItems = 0;
    U8 *guiBuffer;
    U8 *PopUpList[32];
    S32 i;
    S8 *audio_ptr = NULL;
    U32 audio_len = 0;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_scrn_enter(
            AVK_MAIN_GRP_ID,
            AVK_SCR_ID_1,
            avk_pluto_res_001_menuitem_exit,
            avk_pluto_res_001_menuitem,
            MMI_FRM_FULL_SCRN);
    if (ret == MMI_FALSE)
        return;
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    AVK_LOG(audio_ptr = GetAudio(ADO_ID_AVK_PLUTO_RES));

    audio_len |= (U32) ((U8) audio_ptr[1]);
    audio_len |= (U32) ((U8) audio_ptr[2] << 8);
    audio_len |= (U32) ((U8) audio_ptr[3] << 16);
    audio_len |= (U32) ((U8) audio_ptr[4] << 24);
    g_avk_pluto_res.aud_handle = mdi_audio_mma_open_string(0, (void*)(audio_ptr + 8), audio_len, MDI_FORMAT_WAV, 0, NULL, NULL);
    mdi_audio_mma_play(g_avk_pluto_res.aud_handle);

    /* get the number of current menu's submenu */
    AVK_LOG(nItems = GetNumOfChild(MENU_ID_AVK_PLUTO_RES));
    /* get the string list of current menu */
    AVK_LOG_NORMAL(GetSequenceStringIds(MENU_ID_AVK_PLUTO_RES, ItemList));
    AVK_LOG_NORMAL(SetParentHandler(MENU_ID_AVK_PLUTO_RES));

    /* unable the hint list */
    for (i = 0; i < nItems; i++)
    {
        PopUpList[i] = NULL;
    }
    /* define the item icon */
    for (i = 0; i < nItems; i++)
    {
        ItemIcons[i] = IMG_GLOBAL_L1 + i;
    }

    /* Register highlight handler */
    if (g_avk_pluto_res.is_hilight == MMI_FALSE)
    {
        SetHiliteHandler(MENU_ID_AVK_PLUTO_RES_1, avk_pluto_res_001_hilight);
        SetHiliteHandler(MENU_ID_AVK_PLUTO_RES_2, avk_pluto_res_001_hilight);
        SetHintHandler(MENU_ID_AVK_PLUTO_RES_1, avk_pluto_res_001_hint);
        SetHintHandler(MENU_ID_AVK_PLUTO_RES_2, avk_pluto_res_001_hint);
    }
    AVK_LOG_NORMAL(ConstructHintsList(MENU_ID_AVK_PLUTO_RES, PopUpList));
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory52Screen(
        STR_ID_AVK_PLUTO_RES,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        nItems,
        ItemList,
        (PU16) ItemIcons,
        (U8 **) PopUpList,
        0,
        0,
        guiBuffer);

    /* test some api function */
    AVK_LOG_EX(GetParentItemId(MENU_ID_AVK_PLUTO_RES_1) == MENU_ID_AVK_PLUTO_RES);
    AVK_LOG_EX(GetImageIdOfItem(MENU_ID_AVK_PLUTO_RES_1) == IMG_ID_AVK_PLUTO_RES_2);
    AVK_LOG_EX(GetSeqItemId(MENU_ID_AVK_PLUTO_RES, 0) == MENU_ID_AVK_PLUTO_RES_1);
    AVK_LOG_EX(GetSeqItemStringId(MENU_ID_AVK_PLUTO_RES, 0) == STR_ID_AVK_PLUTO_RES_MENUITEM_1);
    AVK_LOG_EX(GetSeqItemImageId(MENU_ID_AVK_PLUTO_RES, 0) == IMG_ID_AVK_PLUTO_RES_2);
    GetSequenceItemIds(MENU_ID_AVK_PLUTO_RES, ItemList);
    AVK_LOG_FUN(GetSequenceItemIds, ItemList[0] == MENU_ID_AVK_PLUTO_RES_1);
    GetSequenceImageIds(MENU_ID_AVK_PLUTO_RES, ItemIcons);
    AVK_LOG_FUN(GetSequenceImageIds, ItemIcons[0] == IMG_ID_AVK_PLUTO_RES_2);

    AVK_LOG_EX(GetParentHandler() == MENU_ID_AVK_PLUTO_RES);
    AVK_LOG_EX(GetCurrHiliteID() == 0);
    AVK_LOG_EX(GetStringIdOfItem(MENU_ID_AVK_PLUTO_RES_1) == STR_ID_AVK_PLUTO_RES_MENUITEM_1);
    AVK_LOG_EX(mmi_frm_get_hilite_hdlr(MENU_ID_AVK_PLUTO_RES_1) == avk_pluto_res_001_hilight);
    AVK_LOG_EX(mmi_frm_get_hint_hdlr(MENU_ID_AVK_PLUTO_RES_1) == avk_pluto_res_001_hint);

#ifdef __MMI_WGUI_CSK_ENABLE__
    ChangeCenterSoftkey(STR_GLOBAL_1, 0);
    SetCenterSoftkeyFunction(GetKeyHandler(KEY_1, KEY_EVENT_DOWN), KEY_EVENT_UP);
#else /* __MMI_WGUI_CSK_ENABLE__ */ 
    SetKeyHandler(GetKeyHandler(KEY_1, KEY_EVENT_DOWN), KEY_CSK, KEY_EVENT_UP);
#endif /* __MMI_WGUI_CSK_ENABLE__ */ 

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}

AVK_MANUAL_CASE(AVK_PLUTO_RES_CASE1,AVK_PLUTO_RES)
{
    avk_pluto_res_001_menuitem();
}
