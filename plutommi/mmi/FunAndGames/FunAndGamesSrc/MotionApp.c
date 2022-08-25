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
 *  MotionApp.c
 *
 * Project:
 * --------
 *  Maui
 *
 * Description:
 * ------------
 *  Motion Game 
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

#include "MMI_features.h"

#ifdef __MMI_MOTION_APP__

#include "GameResDef.h"
#include "MMIDataType.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "GameDefs.h"
#include "gui_typedef.h"
#include "custom_mmi_default_value.h"
#include "wgui.h"
#include "DateTimeType.h"
#include "app_datetime.h"
#include "stdlib.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "wgui_fixed_menus.h"
#include "wgui_categories_list.h"
#include "mmi_frm_scenario_gprot.h"


#ifdef __MMI_MOTIONGAME_DICE__
#include "MotionDiceGprots.h"
#endif /* IS_DICE_BASE_MOTIONGAME */ 

#ifdef IS_DJ_BASE_MOTIONGAME
#include "MotionDJGprots.h"
#endif /* IS_DJ_BASE_MOTIONGAME */ 

#include "mmi_rp_app_funandgames_def.h"
#include "mmi_rp_app_games_def.h"

/****************************************************************************
* Macro                                                                
*****************************************************************************/
#define GAME_SWITCH(index, func_ptr)                             \
{                                                                \
   case index:                                                   \
      {                                                          \
         SetLeftSoftkeyFunction(func_ptr,KEY_EVENT_UP);          \
         EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);          \
         SetCenterSoftkeyFunction(func_ptr, KEY_EVENT_UP);       \
      }                                                          \
      break;                                                     \
}

/****************************************************************************
* Local Functions                                                        
*****************************************************************************/
void mmi_motion_highlight_hdlr(S32 index);
void mmi_motion_entry_app_screen(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_init
 * DESCRIPTION
 *  init moiton apps
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_motion_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MOTIONGAME_DICE__
    mmi_motion_dice_inti_app();
#endif 

#ifdef __MMI_MOTIONGAME_DJ__
    mmi_motion_dj_init_app();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_highlight_hdlr
 * DESCRIPTION
 *  highlight hdlr for motion
 * PARAMETERS
 *  index       [IN]        Highlighted index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_motion_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (index)
    {
    #ifdef __MMI_MOTIONGAME_DICE__
            GAME_SWITCH(motion_dice, mmi_motion_dice_entry_app);
    #endif 

    #ifdef __MMI_MOTIONGAME_DJ__
            GAME_SWITCH(motion_dj, mmi_motion_dj_entry_app);
    #endif 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_highlight_app
 * DESCRIPTION
 *  highlight motion app menitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_motion_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_motion_entry_app_screen, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    redraw_softkey(MMI_CENTER_SOFTKEY);
    SetCenterSoftkeyFunction(mmi_motion_entry_app_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_entry_app_screen
 * DESCRIPTION
 *  entry game app screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_motion_entry_app_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_time t;
    MMI_BOOL entry_ret; 
    U8 *gui_buffer;
    U16 menu_str[motion_list_count + 1];
    U16 menu_img[motion_list_count + 1];
#if defined(__MMI_MOTIONGAME_DICE__) || defined(__MMI_MOTIONGAME_DJ__)
    U16 index = 0;
#endif
    MMI_ID gid;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, NULL, NULL);
    mmi_frm_group_enter(gid, MMI_FRM_NODE_SMART_CLOSE_FLAG );
    
#ifdef __MMI_MOTIONGAME_DICE__
    menu_str[index] = STR_ID_MOTION_DICE_APP;
    menu_img[index++] = IMG_ID_MOTION_DICE_APP;
#endif /* IS_DICE_BASE_MOTIONGAME */ 

#ifdef __MMI_MOTIONGAME_DJ__
    menu_str[index] = STR_ID_MOTION_DJ_APP;
    menu_img[index++] = IMG_ID_MOTION_DJ_APP;
#endif /* IS_DJ_BASE_MOTIONGAME */ 

    /* Set random seed */
    GetDateTime(&t);
    srand(t.nMin);

    /* enter screen */
    entry_ret = mmi_frm_scrn_enter(gid, SCR_ID_MOTION_APP, NULL, mmi_motion_entry_app_screen, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
	{
		return;
	}
    
    gui_buffer = mmi_frm_scrn_get_gui_buf(gid, SCR_ID_MOTION_APP);

    RegisterHighlightHandler(mmi_motion_highlight_hdlr);

    wgui_list_menu_enable_access_by_shortcut();

    ShowCategory15Screen(
        STR_ID_MOTION_APP,
        GetRootTitleIcon(MENU_ID_MOTION_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        motion_list_count,
        menu_str,
        menu_img,
        1,
        0,
        gui_buffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    /* load game settings */
    //mmi_gfx_load_setting();
}

#endif /* __MMI_MOTION_APP__ */ 

