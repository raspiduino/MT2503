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
 * Filename:
 * ---------
 * Game.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Game Menu
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

#include "MMI_features.h"

#ifdef __MMI_GAME__

#include "gui_data_types.h"
#include "MMIDataType.h"
#include "wgui_inline_edit.h"
#include "FontRes.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "GameDefs.h"
#include "gui_typedef.h"
#include "mmi_frm_scenario_gprot.h"
#include "custom_mmi_default_value.h"
#include "wgui.h"
#include "kal_general_types.h"
#include "stdlib.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "wgui_fixed_menus.h"
#include "wgui_categories_list.h"
#include "mmi_frm_history_gprot.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "string.h"

#include "GameResDef.h"
#include "GameProts.h"
#include "GameFramework.h"
#include "mmi_rp_app_games_def.h"

#ifdef __MMI_GAME_F1RACE__
#include "F1RaceProts.h"
#endif

#ifdef __MMI_GAME_HANOI__
#include "TOHProts.h"
#endif

#ifdef __MMI_GAME_RICHES__
#include "RichesProts.h"
#endif

#ifdef __MMI_GAME_COLORBALL__
#include "ColorBallsProts.h"
#endif

#ifdef __MMI_GAME_SNAKE__
#include "SnakeProts.h"
#endif

#ifdef __MMI_GAME_SMASH__
#include "SmashProts.h"
#endif

#ifdef __MMI_GAME_DOLL__
#include "DollProts.h"
#endif

#ifdef __MMI_GAME_MAJUNG__
#include "MajungProts.h"
#endif

#if defined(__MMI_GAME_COPTER__) || defined(__MMI_GAME_SUBMARINE__) || defined(__MMI_GAME_JET__)
#include "CopterProts.h"
#endif

#ifdef __MMI_GAME_PUZZLE__
#include "PuzzleProts.h"
#endif

#if defined(__MMI_GAME_PANDA__) || defined(__MMI_GAME_MONKEY__)
#include "PandaProts.h"
#endif

#if defined(__MMI_GAME_CHICKEN__) || defined(__MMI_GAME_ROBOT__)
#include "StairProts.h"
#endif

#ifdef __MMI_GAME_UFO__
#include "UfoProts.h"
#endif

#ifdef __MMI_GAME_DANCE__
#include "DanceProts.h"
#endif

#ifdef __MMI_GAME_MAGICSUSHI__
#include "MagicsushiProts.h"
#endif

#ifdef __MMI_GAME_FRUIT__
#include "FruitProts.h"
#endif

#ifdef __MMI_GAME_VSMJ__
#include "VsmjProts.h"
#endif

#ifdef __MMI_GAME_FRUITNINJA__
#include "FruitNinjaProts.h"
#endif

#ifdef __MMI_GAME_DIAMOND__
#include "DiamondProts.h"
#endif

#ifdef __MMI_GAME_NINJACLIMB__
#include "NinjaClimbProts.h"
#endif

#ifdef __MMI_GAME_FROGCANDY__
#include "FrogCandyProts.h"
#endif

#ifdef __MMI_GAME_TRUEMAN__
#include "TrueManProts.h"
#endif

#ifdef __MMI_GAME_TOPGUN__
#include "TopGunProts.h"
#endif


#include "DateTimeType.h"
#include "App_DateTime.h"

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
#include "GameProts.h"
#endif

#include "mmi_rp_app_funandgames_def.h"

/* cui prot */
#include "inlinecuigprot.h"

/****************************************************************************
* Macro                                                                
*****************************************************************************/
#define GAME_SWITCH(index, func_ptr)                             \
{                                                                \
   case index:                                                   \
      {                                                          \
         SetLeftSoftkeyFunction(func_ptr,KEY_EVENT_UP);          \
         EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);          \
         SetCenterSoftkeyFunction(func_ptr, KEY_EVENT_UP);        \
      }                                                          \
      break;                                                     \
}

typedef enum
{
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    MMI_GAME_SETTING_BACKGROUND,
    MMI_GAME_SETTING_SOUND_EFFECTS,
#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ /* /__MMI_GAME_MULICHANNEL_SOUND__ */
    MMI_GAME_SETTING_AUD,
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    MMI_GAME_SETTING_VIB,
    MMI_GAME_SETTING_VOL,

    MMI_GAME_SETTING_ITEM_COUNT,

#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    MMI_GAME_SETTING_BACKGROUND_SELECTOR,
    MMI_GAME_SETTING_SOUND_EFFECTS_SELECTOR,
#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ /* /__MMI_GAME_MULICHANNEL_SOUND__ */
    MMI_GAME_SETTING_AUD_SELECTOR,
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    MMI_GAME_SETTING_VIB_SELECTOR,
    MMI_GAME_SETTING_VOL_SELECTOR,
    
    MMI_GAME_SETTING_VOL_ALL
} mmi_game_setting_inline_enum;

typedef struct
{

    /* strings for inline selection display */
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    UI_string_type background_music_str[2];
    UI_string_type sound_effect_str[2];
#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    UI_string_type aud_str[2];
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    UI_string_type vib_str[2];
    UI_string_type vol_str[7];

#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    S32 bgm_selected;
    S32 sound_effect_selected;
#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    S32 aud_selected;
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    S32 vib_selected;
    S32 vol_selected;

    /* inline selection item */
    InlineItem inline_game_items[MMI_GAME_SETTING_ITEM_COUNT *2];      /* one for caption, one for selection */

} mmi_game_cntx_struct;

mmi_game_cntx_struct g_mmi_game_cntx;

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__   
/*used for multi-language language_mapping_table_struct     , currently we max support ten languages*/
mmi_game_language_mapping_table_struct g_mmi_game_language_mapping_table[] =
{
        {MMI_GAME_LANGUAGE0,  "English", "*#0044#"},
        {MMI_GAME_LANGUAGE1,  "Chinese", "*#0086#"},
        //{MMI_GAME_LANGUAGE2,  "Arabic" , "*#0966#"},
        {MMI_GAME_LANGUAGE2,  "", ""},
        {MMI_GAME_LANGUAGE3,  "", ""},
        {MMI_GAME_LANGUAGE4,  "", ""},
        {MMI_GAME_LANGUAGE5,  "", ""},
        {MMI_GAME_LANGUAGE6,  "", ""},
        {MMI_GAME_LANGUAGE7,  "", ""},
        {MMI_GAME_LANGUAGE8,  "", ""},
        {MMI_GAME_LANGUAGE9,  "", ""}
};
extern U16 gCurrLangIndex;
extern const sLanguageDetails mtk_gLanguageArray[];
U16 g_mmi_game_current_language_index;
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/



static const U16 game_setting_bg_sound_selector_str[] =
{
    STR_GLOBAL_OFF,
        STR_GLOBAL_ON
};

static const U16 game_setting_volume_selector_str[] =
{
    STR_GLOBAL_1,
        STR_GLOBAL_2,
        STR_GLOBAL_3,
        STR_GLOBAL_4,
        STR_GLOBAL_5,
        STR_GLOBAL_6,
        STR_GLOBAL_7
};

#if defined(__MMI_GAME_MULTICHANNEL_SOUND__)

    static const cui_inline_item_caption_struct game_setting_bg_sound_caption = 
    {
        STR_ID_GAME_SETTING_MULTICHANNEL_BACKGROUND_MUSIC
    };
    static const cui_inline_item_select_struct game_setting_bg_sound_selector = 
    {
        2, 0, (U16 *)&game_setting_bg_sound_selector_str[0]
    };

    static const cui_inline_item_caption_struct game_setting_sound_effect_caption = 
    {
        STR_ID_GAME_SETTING_MULTICHANNEL_SOUND_EFFECT
    };
    static const cui_inline_item_select_struct game_setting_sound_effect_selector = 
    {
        2, 0, (U16 *)&game_setting_bg_sound_selector_str[0]
    };

#else /*__MMI_GAME_MULTICHANNEL_SOUND__*/

    static const cui_inline_item_caption_struct game_setting_audio_caption = 
    {
        STR_ID_GAME_SETTING_AUD
    };

    static const cui_inline_item_select_struct game_setting_audio_selector = 
    {
        2, 0, (U16 *)&game_setting_bg_sound_selector_str[0]
    };

#endif /*__MMI_GAME_MULTICHANNEL_SOUND__*/


static const cui_inline_item_caption_struct game_setting_vib_caption = 
{
    STR_ID_GAME_SETTING_VIB
};

static const cui_inline_item_caption_struct game_setting_volume_caption = 
{
    STR_GLOBAL_VOLUME
};


static const cui_inline_item_select_struct game_setting_vib_selector = 
{
    2, 0, (U16 *)&game_setting_bg_sound_selector_str[0]
};

static const cui_inline_item_select_struct game_setting_volume_selector = 
{
    7, 0, (U16 *)&game_setting_volume_selector_str[0]
};



static const cui_inline_set_item_struct game_setting_inline_item[] = 
{
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    {CUI_INLINE_ITEM_ID_BASE + MMI_GAME_SETTING_BACKGROUND,             CUI_INLINE_ITEM_TYPE_CAPTION,       IMG_GLOBAL_L1 + MMI_GAME_SETTING_BACKGROUND,     (void*)&game_setting_bg_sound_caption},
    {CUI_INLINE_ITEM_ID_BASE + MMI_GAME_SETTING_BACKGROUND_SELECTOR,    CUI_INLINE_ITEM_TYPE_SELECT,        0,                                               (void*)&game_setting_bg_sound_selector},
    {CUI_INLINE_ITEM_ID_BASE + MMI_GAME_SETTING_SOUND_EFFECTS,          CUI_INLINE_ITEM_TYPE_CAPTION,       IMG_GLOBAL_L1 + MMI_GAME_SETTING_SOUND_EFFECTS,  (void*)&game_setting_sound_effect_caption},
    {CUI_INLINE_ITEM_ID_BASE + MMI_GAME_SETTING_SOUND_EFFECTS_SELECTOR, CUI_INLINE_ITEM_TYPE_SELECT,        0,                                               (void*)&game_setting_sound_effect_selector},
#else
    {CUI_INLINE_ITEM_ID_BASE + MMI_GAME_SETTING_AUD,                    CUI_INLINE_ITEM_TYPE_CAPTION,       IMG_GLOBAL_L1 + MMI_GAME_SETTING_AUD,            (void*)&game_setting_audio_caption},
    {CUI_INLINE_ITEM_ID_BASE + MMI_GAME_SETTING_AUD_SELECTOR,           CUI_INLINE_ITEM_TYPE_SELECT,       0,                                               (void*)&game_setting_audio_selector},
#endif
    {CUI_INLINE_ITEM_ID_BASE + MMI_GAME_SETTING_VIB,                    CUI_INLINE_ITEM_TYPE_CAPTION,       IMG_GLOBAL_L1 + MMI_GAME_SETTING_VIB,            (void*)&game_setting_vib_caption},
    {CUI_INLINE_ITEM_ID_BASE + MMI_GAME_SETTING_VIB_SELECTOR,           CUI_INLINE_ITEM_TYPE_SELECT,        0,                                               (void*)&game_setting_vib_selector},
    {CUI_INLINE_ITEM_ID_BASE + MMI_GAME_SETTING_VOL,                    CUI_INLINE_ITEM_TYPE_CAPTION,       IMG_GLOBAL_L1 + MMI_GAME_SETTING_VOL,            (void*)&game_setting_volume_caption},
    {CUI_INLINE_ITEM_ID_BASE + MMI_GAME_SETTING_VOL_SELECTOR,           CUI_INLINE_ITEM_TYPE_SELECT,        0,                                               (void*)&game_setting_volume_selector}
};


static const cui_inline_struct game_setting_inline_cntx = 
{
    MMI_GAME_SETTING_ITEM_COUNT * 2,
    STR_ID_GAME_SETTING,
    0,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE, 
    NULL, 
    game_setting_inline_item 
};


/****************************************************************************
* Local Functions                                                        
*****************************************************************************/
static void mmi_game_highlight_hdlr(S32 index);

static void mmi_game_entry_app_screen_internal(void);
//static void mmi_game_exit_setting_screen(void);
//static void mmi_game_setting_highlight_hdlr(S32 index);
static void mmi_game_setting_done_hdlr(void);
static void mmi_game_entry_setting_screen(void);

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__   /*used for multi-language*/
    static U16 mmi_gfx_get_current_language_index(void);
    static U8 mmi_gfx_get_fisrt_valid_language_index(void);  
#endif /*__MMI_GAME_MULTI_LANGUAGE_SUPPORT__*/
/*****************************************************************************
 * FUNCTION
 *  mmi_game_highlight_hdlr
 * DESCRIPTION
 *  highlight hdlr for games
 * PARAMETERS
 *  index       [IN]        Highlighted index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_game_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
    #ifdef __MMI_GAME_F1RACE__
            GAME_SWITCH(game_f1race, F1Race_Enter_GFX);
    #endif 

    #ifdef __MMI_GAME_HANOI__
            GAME_SWITCH(game_hanoi, TOH_Enter_GFX);
    #endif 

    #ifdef __MMI_GAME_RICHES__
            GAME_SWITCH(game_riches, Riches_Enter_GFX);
    #endif 

    #ifdef __MMI_GAME_COLORBALL__
            GAME_SWITCH(game_colorballs, ColorBalls_Enter_GFX);
    #endif 

    #ifdef __MMI_GAME_SNAKE__
            GAME_SWITCH(game_snake, Snake_Enter_GFX);
    #endif 

    #ifdef __MMI_GAME_SMASH__
            GAME_SWITCH(game_smash, Smash_Enter_GFX);
    #endif 

    #ifdef __MMI_GAME_DOLL__
            GAME_SWITCH(game_doll, Doll_Enter_GFX);
    #endif 

    #ifdef __MMI_GAME_MAJUNG__
            GAME_SWITCH(game_majung, Majung_Enter_GFX);
    #endif 

    #ifdef __MMI_GAME_COPTER__
            GAME_SWITCH(game_copter, mmi_gx_copter_enter_gfx);
    #endif 

    #ifdef __MMI_GAME_SUBMARINE__
            GAME_SWITCH(game_submarine, mmi_gx_copter_enter_gfx);
    #endif 

    #ifdef __MMI_GAME_JET__
            GAME_SWITCH(game_jet, mmi_gx_copter_enter_gfx);
    #endif 

    #ifdef __MMI_GAME_PUZZLE__
            GAME_SWITCH(game_puzzle, mmi_gx_puzzle_enter_gfx);
    #endif 

    #ifdef __MMI_GAME_PANDA__
            GAME_SWITCH(game_panda, mmi_gx_panda_enter_gfx);
    #endif 

    #ifdef __MMI_GAME_MONEY__
            GAME_SWITCH(game_monkey, mmi_gx_panda_enter_gfx);
    #endif

    #ifdef __MMI_GAME_CHICKEN__
            GAME_SWITCH(game_chicken, mmi_gx_stair_enter_gfx);
    #endif 

    #ifdef __MMI_GAME_ROBOT__
            GAME_SWITCH(game_robot, mmi_gx_stair_enter_gfx);
    #endif 

    #ifdef __MMI_GAME_UFO__
            GAME_SWITCH(game_ufo, mmi_gx_ufo_enter_gfx);
    #endif 

    #ifdef __MMI_GAME_DANCE__
            GAME_SWITCH(game_dance, mmi_gx_dance_enter_gfx);
    #endif 

    #ifdef __MMI_GAME_MAGICSUSHI__
            GAME_SWITCH(game_magicsushi, mmi_gx_magicsushi_enter_gfx);
    #endif 

    #ifdef __MMI_GAME_FRUIT__
            GAME_SWITCH(game_fruit, mmi_gx_fruit_enter_gfx);
    #endif 

    #ifdef __MMI_GAME_VSMJ__
            GAME_SWITCH(game_vsmj, mmi_gx_vsmj_enter_gfx);
    #endif 

    #ifdef __MMI_GAME_FRUITNINJA__
            GAME_SWITCH(game_fruitninja, mmi_gx_fruitninja_enter_gfx);
    #endif 

    #ifdef __MMI_GAME_DIAMOND__
            GAME_SWITCH(game_diamond, mmi_gx_diamond_enter_gfx);
    #endif 

    #ifdef __MMI_GAME_NINJACLIMB__
            GAME_SWITCH(game_ninjaclimb, mmi_gx_ninjaclimb_enter_gfx);
    #endif 

    #ifdef __MMI_GAME_FROGCANDY__
            GAME_SWITCH(game_frogcandy, mmi_gx_frogcandy_enter_gfx);
    #endif 

    #ifdef __MMI_GAME_TRUEMAN__
            GAME_SWITCH(game_trueman, mmi_gx_trueman_enter_gfx);
    #endif 

    #ifdef __MMI_GAME_TOPGUN__
            GAME_SWITCH(game_topgun, mmi_gx_topgun_enter_gfx);
    #endif 

        default:
            SetLeftSoftkeyFunction(mmi_game_entry_setting_screen, KEY_EVENT_UP);
            EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_game_entry_setting_screen, KEY_EVENT_UP);
            break;

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_game_highlight_app
 * DESCRIPTION
 *  highlight game app menitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_GAME__)
void mmi_game_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    redraw_softkey(MMI_CENTER_SOFTKEY);
    SetLeftSoftkeyFunction(mmi_game_entry_app_screen, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_game_entry_app_screen, KEY_EVENT_UP);
    
}
#endif /* defined(__MMI_GAME__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_game_group_proc
 * DESCRIPTION
 *  entry game group proc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_game_group_proc(mmi_event_struct *evt)
{
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_game_entry_app_screen
 * DESCRIPTION
 *  entry game app screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_game_entry_app_screen(void)
{
	GFX.cur_gid = mmi_frm_group_create (GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_game_group_proc, NULL);
    
    mmi_frm_group_enter(GFX.cur_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

	mmi_game_entry_app_screen_internal();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_game_entry_app_screen_internal
 * DESCRIPTION
 *  entry game app screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_game_entry_app_screen_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    UI_time t;
    U16 menu_str[game_list_count + 1];
    U16 menu_img[game_list_count + 1];
    U16 index = 0;
    MMI_BOOL entry_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* str and img +1 for setting */

#ifdef __MMI_GAME_F1RACE__
    menu_str[index] = STR_GX_F1RACE_GAME_NAME;
    menu_img[index++] = IMG_GX_F1RACE_GAME_ICON;
#endif  //__MMI_GAME_F1RACE__

#ifdef __MMI_GAME_HANOI__
    menu_str[index] = STR_GX_TOH_GAME_NAME;
    menu_img[index++] = IMG_GX_TOH_GAME_ICON;
#endif  //__MMI_GAME_HANOI__

#ifdef __MMI_GAME_RICHES__
    menu_str[index] = STR_GX_RICHES_GAME_NAME;
    menu_img[index++] = IMG_GX_RICHES_GAME_ICON;
#endif  //__MMI_GAME_RICHES__

#ifdef __MMI_GAME_COLORBALL__
    menu_str[index] = STR_GX_COLORBALLS_GAME_NAME;
    menu_img[index++] = IMG_GX_COLORBALLS_GAME_ICON;
#endif  //__MMI_GAME_COLORBALL__

#ifdef __MMI_GAME_SNAKE__
    menu_str[index] = STR_GX_SNAKE_GAME_NAME;
    menu_img[index++] = IMG_GX_SNAKE_GAME_ICON;
#endif  //__MMI_GAME_SNAKE__

#ifdef __MMI_GAME_SMASH__
    menu_str[index] = STR_GX_SMASH_GAME_NAME;
    menu_img[index++] = IMG_GX_SMASH_GAME_ICON;
#endif  //__MMI_GAME_SMASH__

#ifdef __MMI_GAME_DOLL__
    menu_str[index] = STR_GX_DOLL_GAME_NAME;
    menu_img[index++] = IMG_GX_DOLL_GAME_ICON;
#endif  //__MMI_GAME_DOLL__

#ifdef __MMI_GAME_MAJUNG__
    menu_str[index] = STR_GX_MAJUNG_GAME_NAME;
    menu_img[index++] = IMG_GX_MAJUNG_GAME_ICON;
#endif  //__MMI_GAME_MAJUNG__

#ifdef __MMI_GAME_COPTER__
    /* copter */
    menu_str[index] = STR_ID_GX_COPTER_GAME_NAME;
    menu_img[index++] = IMG_ID_GX_COPTER_GAME_ICON;
#endif  //__MMI_GAME_COPTER__

#ifdef __MMI_GAME_SUBMARINE__
    /* sub */
    menu_str[index] = STR_ID_GX_COPTER_GAME_NAME_SUBMARINE;
    menu_img[index++] = IMG_ID_GX_COPTER_GAME_ICON;
#endif  //__MMI_GAME_SUBMARINE__

#ifdef __MMI_GAME_JET__
    /* jet */
    menu_str[index] = STR_ID_GX_COPTER_GAME_NAME_JET;
    menu_img[index++] = IMG_ID_GX_COPTER_GAME_ICON;
#endif  //__MMI_GAME_JET__

#ifdef __MMI_GAME_PUZZLE__
    menu_str[index] = STR_ID_GX_PUZZLE_GAME_NAME;
    menu_img[index++] = IMG_ID_GX_PUZZLE_GAME_ICON;
#endif  //__MMI_GAME_PUZZLE__ 

#ifdef __MMI_GAME_PANDA__
    /* panda */
    menu_str[index] = STR_ID_GX_PANDA_GAME_NAME;
    menu_img[index++] = IMG_ID_GX_PANDA_GAME_ICON;
#endif  //__MMI_GAME_PANDA__

#ifdef __MMI_GAME_MONKEY__
    /* monkey */
    menu_str[index] = STR_ID_GX_PANDA_GAME_NAME_MONKEY;
    menu_img[index++] = IMG_ID_GX_PANDA_GAME_ICON;
#endif  //__MMI_GAME_MONKEY__

#ifdef __MMI_GAME_CHICKEN__
    /* chicken */
    menu_str[index] = STR_ID_GX_STAIR_GAME_NAME_CHICKEN;
    menu_img[index++] = IMG_ID_GX_STAIR_GAME_ICON;
#endif  //__MMI_GAME_CHICKEN__

#ifdef __MMI_GAME_ROBOT__
    /* robot */
    menu_str[index] = STR_ID_GX_STAIR_GAME_NAME_ROBOT;
    menu_img[index++] = IMG_ID_GX_STAIR_GAME_ICON;
#endif  //__MMI_GAME_ROBOT__

#ifdef __MMI_GAME_UFO__
    /* ufo */
    menu_str[index] = STR_ID_GX_UFO_GAME_NAME;
    menu_img[index++] = IMG_ID_GX_UFO_GAME_ICON;
#endif  //__MMI_GAME_UFO__

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

#ifdef __MMI_GAME_DANCE__
    menu_str[index] = STR_ID_GX_DANCE_GAME_NAME;
    menu_img[index++] = IMG_ID_GX_DANCE_GAME_ICON;
#endif  //__MMI_GAME_DANCE__

#ifdef __MMI_GAME_MAGICSUSHI__
    menu_str[index] = STR_ID_GX_MAGICSUSHI_GAME_NAME;
    menu_img[index++] = IMG_ID_GX_MAGICSUSHI_GAME_ICON;
#endif  //__MMI_GAME_MAGICSUSHI__

#ifdef __MMI_GAME_FRUIT__
    menu_str[index] = STR_ID_GX_FRUIT_GAME_NAME;
    menu_img[index++] = IMG_ID_GX_FRUIT_GAME_ICON;
#endif  //__MMI_GAME_FRUIT__

#ifdef __MMI_GAME_VSMJ__
    menu_str[index] = STR_ID_GX_VSMJ_GAME_NAME;
    menu_img[index++] = IMG_ID_GX_VSMJ_GAME_ICON;
#endif  //__MMI_GAME_VSMJ__

#ifdef __MMI_GAME_FRUITNINJA__
    menu_str[index] = STR_ID_GX_FRUITNINJA_GAME_NAME;
    menu_img[index++] = 0;//IMG_ID_GX_FRUITNINJA_GAME_ICON;
#endif  //__MMI_GAME_FRUIT__

#ifdef __MMI_GAME_DIAMOND__
        menu_str[index] = STR_ID_GX_DIAMOND_GAME_NAME;
        menu_img[index++] = 0;//IMG_ID_GX_DIAMOND_GAME_ICON;
#endif  //__MMI_GAME_FRUIT__

#ifdef __MMI_GAME_NINJACLIMB__
        menu_str[index] = STR_ID_GX_NINJACLIMB_GAME_NAME;
        menu_img[index++] = 0;//IMG_ID_GX_NINJACLIMB_GAME_ICON;
#endif  //__MMI_GAME_FRUIT__

#ifdef __MMI_GAME_FROGCANDY__
        menu_str[index] = STR_GX_FROGCANDY_GAME_NAME;
        menu_img[index++] = 0;//IMG_GX_FROGCANDY_GAME_ICON;
#endif  //__MMI_GAME_FRUIT__

#ifdef __MMI_GAME_TRUEMAN__
        menu_str[index] = STR_ID_GX_TRUEMAN_GAME_NAME;
        menu_img[index++] = 0;//IMG_ID_GX_TRUEMAN_GAME_ICON;
#endif  //__MMI_GAME_FRUIT__

#ifdef __MMI_GAME_TOPGUN__
        menu_str[index] = STR_ID_GX_TOPGUN_GAME_NAME;
        menu_img[index++] = 0;//IMG_ID_GX_TOPGUN_GAME_ICON;
#endif  //__MMI_GAME_FRUIT__

    menu_str[index] = STR_ID_GAME_SETTING;
    menu_img[index++] = IMG_ID_GAME_SETTING;

    /* Set random seed */
    GetDateTime(&t);
    srand(t.nMin);

    //get current language , used for multi-language
#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
    g_mmi_game_current_language_index = mmi_gfx_get_current_language_index(); 
#endif
    
	entry_ret = mmi_frm_scrn_enter (GFX.cur_gid, SCR_ID_GAME, NULL, mmi_game_entry_app_screen_internal, 0);
	if (!entry_ret)
	{
		kal_prompt_trace(MOD_MMI, "Misstion is imposible");
		return;
	}

    guiBuffer = mmi_frm_scrn_get_gui_buf(GFX.cur_gid, SCR_ID_GAME);

    RegisterHighlightHandler(mmi_game_highlight_hdlr);

    /* when choose a  number shortcut in the list menu, access the menu directly */
	wgui_list_menu_enable_access_by_shortcut();
	
	ShowCategory15Screen(
        STR_MENU3105_GAMES,
        GetRootTitleIcon(MENU3105_GAMES),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        index,
        menu_str,
        menu_img,
        1,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    /* load game settings */
    mmi_gfx_load_setting();
}


static void mmi_game_setting_change_item_content(cui_event_inline_notify_struct *inline_evt)
{
    switch(inline_evt->item_id - CUI_INLINE_ITEM_ID_BASE)
    {
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    case MMI_GAME_SETTING_BACKGROUND_SELECTOR:
        g_mmi_game_cntx.bgm_selected = inline_evt->param;
        break;

    case MMI_GAME_SETTING_SOUND_EFFECTS_SELECTOR:
        g_mmi_game_cntx.sound_effect_selected = inline_evt->param;
        break;
#else
    case MMI_GAME_SETTING_AUD_SELECTOR:
        g_mmi_game_cntx.aud_selected = inline_evt->param;
        break;
#endif

    case MMI_GAME_SETTING_VIB_SELECTOR:
        g_mmi_game_cntx.vib_selected = inline_evt->param;
        break;

    case MMI_GAME_SETTING_VOL_SELECTOR:
        g_mmi_game_cntx.vol_selected = inline_evt->param;
        break;
    }
}

static mmi_ret mmi_game_settings_group_proc(mmi_event_struct *evt)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
		/**********************Inline CUI event*************************/
    case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *notify = (cui_event_inline_notify_struct *)evt;
            if (notify->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
            {
                mmi_game_setting_change_item_content(notify);
            }
        }
        break;
        
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            //cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;
        }
        break;
        
    case EVT_ID_CUI_INLINE_SET_KEY:
        {
            //cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;
        }
        break;
        
    case EVT_ID_CUI_INLINE_CSK_PRESS:
    case EVT_ID_CUI_INLINE_SUBMIT:
        {
            cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;

            mmi_game_setting_done_hdlr();
			cui_inline_close(inline_evt->sender_id);
        }
        break;
        
    case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;

            cui_inline_close(inline_evt->sender_id);
        }
        break;
    }

    return MMI_RET_OK;
}


static void mmi_game_init_setting_inline_item_value(MMI_ID inline_id)
{
	mmi_gfx_load_setting();
	
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
	g_mmi_game_cntx.bgm_selected = GFX.is_background_music_on;
	cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + MMI_GAME_SETTING_BACKGROUND_SELECTOR, 
        (void *)g_mmi_game_cntx.bgm_selected);

	g_mmi_game_cntx.sound_effect_selected = GFX.is_sound_effect_on;
	cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + MMI_GAME_SETTING_SOUND_EFFECTS_SELECTOR, 
        (void *)g_mmi_game_cntx.sound_effect_selected);

#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
	g_mmi_game_cntx.aud_selected = GFX.is_aud_on;
	cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + MMI_GAME_SETTING_AUD_SELECTOR, 
        (void *)g_mmi_game_cntx.aud_selected);

#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
	
	g_mmi_game_cntx.vib_selected = GFX.is_vib_on;
	cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + MMI_GAME_SETTING_VIB_SELECTOR, 
        (void *)g_mmi_game_cntx.vib_selected);
	
	g_mmi_game_cntx.vol_selected = GFX.aud_volume;
	cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + MMI_GAME_SETTING_VOL_SELECTOR, 
        (void *)g_mmi_game_cntx.vol_selected);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_game_entry_setting_screen
 * DESCRIPTION
 *  entry point for game setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_game_entry_setting_screen(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID inline_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_group_create(GRP_ID_ROOT, SCR_ID_GAME_SETTING, mmi_game_settings_group_proc, (void*)NULL); 
    mmi_frm_group_enter(SCR_ID_GAME_SETTING, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    inline_id = cui_inline_create(SCR_ID_GAME_SETTING, &game_setting_inline_cntx);
	mmi_game_init_setting_inline_item_value(inline_id);
    cui_inline_set_title_icon(inline_id, GetRootTitleIcon(MENU3105_GAMES));
    cui_inline_run(inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_game_setting_done_hdlr
 * DESCRIPTION
 *  done hdlr for game setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_game_setting_done_hdlr(void)
{
#if defined(__MMI_GAME__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* game effect */
#ifdef __MMI_GAME_MULTICHANNEL_SOUND__
    GFX.is_background_music_on = g_mmi_game_cntx.bgm_selected;
    GFX.is_sound_effect_on = g_mmi_game_cntx.sound_effect_selected;
#else /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    GFX.is_aud_on = g_mmi_game_cntx.aud_selected;
#endif /* __MMI_GAME_MULTICHANNEL_SOUND__ */ 
    GFX.is_vib_on = g_mmi_game_cntx.vib_selected;
    GFX.aud_volume = g_mmi_game_cntx.vol_selected;
    mmi_gfx_store_setting();

    mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, SCR_ID_GAME_SETTING, NULL);
#endif /* defined(__MMI_GAME__) */ 
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_GAME__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_GAME__) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_GAME_MULTI_LANGUAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  ColorBall_Get_Current_Language_Index
 * DESCRIPTION
 *  get current language index
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
U16 mmi_gfx_get_current_language_index()
{
    U8 i;
    
    for (i = MMI_GAME_LANGUAGE0 ; i < MMI_GAME_LANGUAGE_TATAL ; i++)
    {
        if(strcmp((PS8)mtk_gLanguageArray[gCurrLangIndex].aLangSSC, (PS8)g_mmi_game_language_mapping_table[i].aLangSSC) == 0)
            return i;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Get_Current_Language_Image_ID
 * DESCRIPTION
 *  get image id of current language
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_gfx_get_multilanguage_image_ID(
        MMI_GAME_MULTI_LANGUAGE_ENUM language, 
        U16 image_ID_base, 
        U16 total_string_count, 
        U16 string_number)
{

    return (image_ID_base + language*total_string_count + string_number);
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Check_Image_Validity
 * DESCRIPTION
 *  check image in current language is valid or not, and get valid language
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
BOOL mmi_gfx_check_image_get_valid_language(
            U16 *game_language_index, 
            U16 image_ID_base, 
            U16 total_string_count)
{
    U8 *pData = NULL;
    BOOL image_validate = TRUE;
    U8  first_valid_language_index;
    U16 image_handle;
    U8 i;

    for (i = 0 ; i < total_string_count ; i++)
    {
        image_handle = (*game_language_index) * total_string_count + image_ID_base + i;
        pData = (PU8)GetImage(image_handle);    
        if (pData == MMI_GAME_DEFAULT_IMAGE_BMP|| pData == MMI_GAME_EMPTYIMAGE_BMP)
        {
            image_validate = FALSE;
            break;
        }      
    }
    
    if(image_validate == FALSE)
    {
        first_valid_language_index = mmi_gfx_get_fisrt_valid_language_index();
        *game_language_index= first_valid_language_index;
    }
        
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  ColorBalls_Get_Fisrt_Valid_Language_Index
 * DESCRIPTION
 *  get first valid language index
 * PARAMETERS
 *  void
 *  viod(?)
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_gfx_get_fisrt_valid_language_index()
{
    U32 i;
        
    for(i = MMI_GAME_LANGUAGE0 ; i < MMI_GAME_LANGUAGE_TATAL ; i++)
    {
        if(strlen((PS8)g_mmi_game_language_mapping_table[i].aLangSSC) != 0)
        {
            return i;
        }
    }

    return MMI_GAME_LANGUAGE0;
}
#endif /* __MMI_GAME_MULTI_LANGUAGE_SUPPORT__ */

#endif /* __MMI_GAME__ */ 

