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
 *    CubeApp.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#include "MMI_features.h"

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "ctype.h" 
#include "kal_release.h"
#include "MMIDataType.h"
#include "mmi_include.h"
#include "kal_trace.h"
#include "SettingProfile.h"
#include "fileMgrGProt.h"
#include "Fs_type.h"
#include "med_api.h"
#include "med_smalloc.h"


#ifdef __MMI_VUI_3D_CUBE_APP__

/* shell app */
#include "CubeAppGprot.h"
#include "CubeAppProt.h"
#include "Vapp_cube_res.h"
#include "CubeApp\vadp_p2v_cube.h"
#include "CubeApp\vadp_v2p_cube.h"
#include "CubeApp\vadp_p2v_cube_media_player.h"
#include "CubeApp\vadp_p2v_cube_imgview.h"
#include "CubeApp\vadp_p2v_cube_vip_contact.h"
/* home screen */
#include "IdleAppProt.h"
#include "IdleAppResDef.h"
#include "IdleVenus.h"
#include "Vapp_hs_res.h"


/**********************************************************************
 * Constant Definitions:
 **********************************************************************/

/***************************************************************************** 
 * Structure
 *****************************************************************************/
static mmi_cube_vapp_struct mmi_cube_vapp_callback_tbl[MMI_CUBE_APP_NUM] = 
{
    {VAPP_CUBE_HOME_TITLE_TEXT, mmi_vhs_show_homescreen},
    {VAPP_CUBE_VIP_CONTACE_TITLE_TEXT, mmi_vs_show_vip_contact},
    {VAPP_CUBE_STR_IMGVIEW_TITLE, mmi_cube_vapp_show_imgview},
    {VAPP_CUBE_STR_MPLAYER_TITLE,mmi_cube_vapp_show_media_player}  //guoming
};


/***************************************************************************** 
 * Extern
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Locals
 *****************************************************************************/
static void *g_cube_scr_obj[MMI_CUBE_APP_NUM];
static MMI_BOOL g_cube_is_img_prefetch = MMI_FALSE;


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_app_set_img_prefetch_mode
 * DESCRIPTION
 *  This function set prefetch mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_app_set_img_prefetch_mode(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    g_cube_is_img_prefetch = enable;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cube_app_get_img_prefetch_mode
 * DESCRIPTION
 *  This function get prefetch mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_cube_app_get_img_prefetch_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return g_cube_is_img_prefetch;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cube_vapp_cache_image
 * DESCRIPTION
 *  This function is used to get current screen snapshot
 * PARAMETERS
 *  cur_idx     [IN]    current screen index
 * RETURNS
 *  >= 0 : success
 *  <0 : fail
 *****************************************************************************/
static void mmi_cube_vapp_prefetch_image(U8 scr_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    gdi_lcd_freeze(MMI_TRUE);

    mmi_cube_app_set_img_prefetch_mode(MMI_TRUE);
     
    EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
    /*
     * Some APP, e.g., UM, will use this function to show a dummy screen before
     * it gets the information to be shown. If the keypad is locked, because the 
     * user will leave the locked screen, the icon will be temporarily removed.
     * Restore the icon here; otherwise, the icon will flash.
     *
     * [MAUI_01586766]
     * For touch screen, we should always show icon for background.
     */
#ifndef __MMI_TOUCH_SCREEN__
    if (g_keylock_context.gKeyPadLockFlag)
#endif
    {
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_KEYPAD_LOCK);
    }
   
    // prefetch next screen index
    mmi_cube_vapp_callback_tbl[scr_idx].callback();
    mmi_cube_app_set_img_prefetch_mode(MMI_FALSE);
    vadp_v2p_cube_vapp_save_cur_layer_to_buffer(scr_idx);
    
    gdi_lcd_freeze(MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cube_vapp_get_hs_category
 * DESCRIPTION
 *  This function shows the Venus home screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_cube_vapp_get_hs_category(U8 scr_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_cube_scr_obj[scr_idx];
}


//guoming
/*****************************************************************************
 * FUNCTION
 *  mmi_cube_vapp_show_media_player
 * DESCRIPTION
 *  This function shows the media player cube screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_cube_vapp_show_media_player(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ret = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VUI_3D_CUBE_APP_MEDIA_PLAYER__
    /* Show venus screen */
    ret = vadp_p2v_cube_vapp_media_player_init();
    
    /* Register the exit category function. */
    ExitCategoryFunction = vadp_p2v_cube_vapp_media_player_deinit;
#endif
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vs_show_vip_contact
 * DESCRIPTION
 *  This function shows the Vip contact
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_vs_show_vip_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Show venus screen */
    ret = vadp_p2v_cube_vip_contact_init();
    
    /* Register the exit category function. */
    ExitCategoryFunction = vadp_p2v_cube_vip_contact_deinit;

    return ret;
}


void *mmi_cube_vapp_show_imgview()
{
    void *ret = NULL;

    ExitCategoryFunction = NULL;

#ifdef __MMI_VUI_3D_CUBE_APP_IMGVIEW__
    ret = vadp_p2v_cube_vapp_imgview_init();

    ExitCategoryFunction = vadp_p2v_cube_vapp_imgview_deinit;
#endif

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_vapp_prefetch_image_and_save
 * DESCRIPTION
 *  prefetch cube image and save it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_vapp_prefetch_image_and_save(void)
{
#if defined(__MMI_VUI_3D_CUBE_FREE_MODE__) || defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    MMI_BOOL is_img_fetched = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/      
    for (i = 1; i < MMI_CUBE_APP_NUM; i++)
    {
    #ifdef __MMI_VUI_3D_CUBE_FREE_MODE__
        if (!(vadp_v2p_cube_vapp_is_cur_scr_snapshot_existed(i, 0, 0)) &&
            !(vadp_v2p_cube_vapp_is_cur_scr_snapshot_existed(i, 0, 1)))
    #else
        if (!(vadp_v2p_cube_vapp_is_cur_scr_snapshot_existed(i, 1, 0)) &&
            !(vadp_v2p_cube_vapp_is_cur_scr_snapshot_existed(i, 1, 1)))
    #endif
        {
            mmi_cube_vapp_prefetch_image(i);
            vadp_v2p_cube_vapp_save_cur_layer_buf_to_file(i);
            is_img_fetched = MMI_TRUE;
        }
    }

    if (is_img_fetched)
    {
        vadp_v2p_cube_vapp_free_layer();
    }
#endif /* defined(__MMI_VUI_3D_CUBE_FREE_MODE__) || defined(__MMI_VUI_3D_CUBE_SAVE_SNAPSHOT__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_cube_vapp_show_homescreen
 * DESCRIPTION
 *  This function shows the venus shell screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_vapp_show_homescreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 scr_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    vadp_p2v_cube_vapp_get_cur_scr_idx(&scr_idx);
    ASSERT(scr_idx >= 0 && scr_idx < MMI_CUBE_APP_NUM);
    
    g_cube_scr_obj[scr_idx] = mmi_cube_vapp_callback_tbl[scr_idx].callback();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cube_vapp_get_title
 * DESCRIPTION
 *  This function gets the shell screen title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S8 mmi_cube_vapp_get_title(U8 scr_idx, U16 *title_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scr_idx >= MMI_CUBE_APP_NUM || title_id == NULL)
    {
        return MMI_CUBE_ERROR;
    }
    
    *title_id = mmi_cube_vapp_callback_tbl[scr_idx].title_str_id;
    return MMI_CUBE_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cube_vapp_close_hs_category
 * DESCRIPTION
 *  This function is called when we close category
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_cube_vapp_close_hs_category(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 scr_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vadp_p2v_cube_vapp_get_cur_scr_idx(&scr_idx) >= 0)
    {
        g_cube_scr_obj[scr_idx] = NULL;
    }

    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_cube_vapp_is_self_exited
 * DESCRIPTION
 *  cube is exited by itself or not
 * PARAMETERS
 *  void
 * RETURNS
 *  CUBE_OK : exited by itself
 *  CUBE_ERROR  : not exited by itself
 *****************************************************************************/
S8 mmi_cube_vapp_is_self_exited(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GetActiveScreenId() == IDLE_SCREEN_ID ||
        GetActiveScreenId() == VAPP_CUBE_APP_SCR_ID ||
        GetActiveScreenId() == GLOBAL_SCR_DUMMY)
    {
        return MMI_CUBE_OK;
    }

    return MMI_CUBE_ERROR;
}

/*****************************************************************************
 * FUNCTION
 *  EntryCalcApp
 * DESCRIPTION
 *  Entry function of calculator application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCubeVapp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Release Venus screen and resource */
    /* Store current screen operation */
    vadp_p2v_cube_vapp_deinit();

    /* free unreleased resource and save screen snapshot if necessary */
    vadp_v2p_cube_vapp_save_cur_layer();
    vadp_v2p_cube_vapp_free_layer();
    
    /* check if we need to push into history */
    if (vadp_p2v_cube_vapp_is_small())
    {
        GenericExitScreen(VAPP_CUBE_APP_SCR_ID, EntryCubeVapp);
    }
    
    return;
}

/*****************************************************************************
 * FUNCTION
 *  EntryCubeVapp
 * DESCRIPTION
 *  Entry function of shell application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCubeVapp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL cube_effect = vadp_p2v_cube_vapp_get_effect();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(VAPP_CUBE_APP_SCR_ID, ExitCubeVapp, NULL, MMI_FULL_SCREEN);

    /* Show venus screen */
    vadp_p2v_cube_vapp_set_effect(MMI_FALSE);
    vadp_p2v_cube_vapp_init(cube_effect);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  EntryCubeVappByDir
 * DESCRIPTION
 *  Entry function of shell application by direction
 * PARAMETERS
 *  is_small_cube   [IN] KAL_TRUE: small cube  KAL_FALSE: not small cube
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void EntryCubeVappByDir(MMI_BOOL is_small_cube, MMI_BOOL is_free_mode, mmi_cube_vapp_dir_enum dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_VUI_3D_CUBE_FREE_MODE__
    S8 scr_idx;
#endif
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_small_cube)
    {
        vadp_p2v_cube_vapp_set_small_mode();
    }
    else
    {
        vadp_p2v_cube_vapp_set_action(dir);
        vadp_p2v_cube_vapp_set_free_mode(is_free_mode);
    #ifndef __MMI_VUI_3D_CUBE_FREE_MODE__
        if (vadp_p2v_cube_vapp_get_cur_scr_idx((U8 *)&scr_idx) >= 0)
        {
            /* save current layer */
            vadp_v2p_cube_vapp_save_cur_layer_to_buffer(scr_idx);
             
            if (dir == MMI_CUBE_VAPP_DIR_NEXT)
            {
                scr_idx = (scr_idx + 1) % MMI_CUBE_APP_NUM;
            }
            else
            {
                scr_idx = 
                ((scr_idx - 1) >= 0) ? (scr_idx - 1): (MMI_CUBE_APP_NUM-1);
            }
            /* prefetch next layer */
            mmi_cube_vapp_prefetch_image((U8)scr_idx);
                 }
    #endif /* !__MMI_VUI_3D_CUBE_FREE_MODE__ */
    }

    vadp_p2v_cube_vapp_set_effect(MMI_TRUE);
    EntryCubeVapp();
    return;
}

#endif /* __MMI_VUI_3D_CUBE_APP__ */


