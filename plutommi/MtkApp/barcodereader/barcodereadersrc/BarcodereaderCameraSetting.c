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
 *  BarcodeReaderCameraSetting.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Barcode Reader Camera Setting
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_BARCODEREADER__
#include "mmi_include.h"
#include "Nvram_common_defs.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "USBDeviceGProt.h"
#include "gpioInc.h"
#include "CommonScreens.h"
#include "mdi_camera.h"
#include "MMI_features_camera.h"

/***************************************************************************** 
* Included .h file
*****************************************************************************/
#include "mmi_features_barcodereader.h"
#include "Barcodereadergprot.h"
#include "BarcodereaderLcd.h"
#include "BarcodereaderCameraSettingResDef.h"
#include "BarcodereaderCameraSetting.h"
#include "BarcodereaderCameraSettingProt.h"
#include "BarcodereaderCommonProt.h"

/****************************************************************************
* Setting command map                                                                
*****************************************************************************/
#define DUMMY_COMMAND      (0)

/*********** EV ***********/
const U8 mmi_barcodereader_ev_command_map[MMI_BARCODEREADER_SETTING_EV_COUNT + 1] = 
{
#ifdef __MMI_BARCODEREADER_EV_4__
    MDI_CAMERA_EV_N4,   /* CAMERA_SETTING_EV_N4 */
#endif 

#ifdef __MMI_BARCODEREADER_EV_3__
    MDI_CAMERA_EV_N3,   /* CAMERA_SETTING_EV_N3 */
#endif 

#ifdef __MMI_BARCODEREADER_EV_2__
    MDI_CAMERA_EV_N2,   /* CAMERA_SETTING_EV_N2 */
#endif 

    MDI_CAMERA_EV_N1,   /* CAMERA_SETTING_EV_N1 */
    MDI_CAMERA_EV_0,    /* CAMERA_SETTING_EV_0 */
    MDI_CAMERA_EV_P1,   /* CAMERA_SETTING_EV_P1 */

#ifdef __MMI_BARCODEREADER_EV_2__
    MDI_CAMERA_EV_P2,   /* CAMERA_SETTING_EV_P2 */
#endif 

#ifdef __MMI_BARCODEREADER_EV_3__
    MDI_CAMERA_EV_P3,   /* CAMERA_SETTING_EV_P3 */
#endif 

#ifdef __MMI_BARCODEREADER_EV_4__
    MDI_CAMERA_EV_P4,   /* CAMERA_SETTING_EV_P4 */
#endif 
    DUMMY_COMMAND
};

const U8 mmi_barcodereader_flash_command_map[MMI_BARCODEREADER_SETTING_FLASH_COUNT + 1] = 
{
    MDI_CAMERA_FLASH_OFF,   /* CAMERA_SETTING_FLASH_OFF */
    MDI_CAMERA_FLASH_ON,    /* CAMERA_SETTING_FLASH_ON */
    DUMMY_COMMAND
};

#if MDI_CAMERA_MT6238_SERIES
const U8 mmi_barcodereader_focus_mode_command_map[MMI_BARCODEREADER_SETTING_FOCUS_MODE_COUNT + 1] = 
{

    MDI_CAMERA_AF_RANGE_AUTO,

#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MACRO__
    MDI_CAMERA_AF_RANGE_MACRO,
    #endif 
    DUMMY_COMMAND
};
#else
const U8 mmi_barcodereader_focus_mode_command_map[MMI_BARCODEREADER_SETTING_FOCUS_MODE_COUNT + 1] = 
{

    MDI_CAMERA_AUTOFOCUS_MODE_AUTO,

#ifdef __MMI_BARCODEREADER_FOCUS_MODE_MACRO__
    MDI_CAMERA_AUTOFOCUS_MODE_MACRO,
#endif 
    DUMMY_COMMAND
};
#endif

const U8 mmi_barcodereader_banding_command_map[MMI_BARCODEREADER_SETTING_BANDING_COUNT + 1] = 
{
    MDI_CAMERA_BANDING_50HZ,
    MDI_CAMERA_BANDING_60HZ,
    DUMMY_COMMAND
};

/***************************************************************************** 
* variable declare
*****************************************************************************/
static mmi_barcodereader_camera_setting_cntx_struct g_barcodereader_camera_setting_cntx;
static mmi_barcodereader_camera_record_setting_struct g_barcodereader_record_setting_cntx;
static U16 barcode_camera_setting_title_id = STR_ID_BARCODEREADER_CAMERA_SETTING;

/***************************************************************************** 
* Function declare
*****************************************************************************/
       void mmi_barcodereader_load_camera_setting(void);
static void mmi_barcodereader_store_camera_setting(void);
static void mmi_barcodereader_restore_camera_setting(void);
static void mmi_barcodereader_option_setting_set_value(void);
static void mmi_barcodereader_option_setting_highlight_hdlr(S32 index);

/***************************************************************************** 
* Function Implementation
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_enter_camera_setting_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_enter_camera_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *inputBuffer;
    U16 inputBufferSize;
    S32 item_offset = 0;
    S32 i;
    MMI_ID_TYPE item_icons[MMI_BARCODEREADER_SETTING_ITEM_COUNT * 2] = 
    {
    #ifdef __MMI_BARCODEREADER_FLASH__
        IMG_ID_BARCODEREADER_MENUICON_FLASH,
        0,
    #endif /* __MMI_BARCODEREADER_FLASH__ */ /* __BARCODEREADER_FLASH__ */

        IMG_ID_BARCODEREADER_MENUICON_EV,
        0,

    #ifdef __MMI_BARCODEREADER_FOCUS_MODE__
        IMG_ID_BARCODEREADER_MENUICON_FOCUS_MODE,
        0,
    #endif /* __MMI_BARCODEREADER_FOCUS_MODE__ */ /* __BARCODEREADER_FOCUS_MODE__ */

    #ifdef __MMI_BARCODEREADER_BANDING__
        IMG_ID_BARCODEREADER_MENUICON_BANDING,
        0,
    #endif /* __MMI_BARCODEREADER_BANDING__ */ /* __BARCODEREADER_BANDING__ */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(
        SCR_ID_BARCODEREADER_CAMERA_SETTING,
        NULL,
        mmi_barcodereader_enter_camera_setting_screen,
        MMI_FULL_SCREEN);

    InitializeCategory57Screen();

    guiBuffer = GetCurrGuiBuffer(SCR_ID_BARCODEREADER_CAMERA_SETTING);
    if (guiBuffer == NULL)
    {
    g_barcodereader_camera_setting_cntx.flash_selected = g_barcodereader_record_setting_cntx.flash;
    g_barcodereader_camera_setting_cntx.ev_selected = g_barcodereader_record_setting_cntx.ev;
    g_barcodereader_camera_setting_cntx.af_mode_selected = g_barcodereader_record_setting_cntx.af_mode;
    g_barcodereader_camera_setting_cntx.banding_selected = g_barcodereader_record_setting_cntx.banding;
    }
   /****************************************************************************
   *  Create inline selection                                                               
   *****************************************************************************/
#ifdef __MMI_BARCODEREADER_FLASH__

        g_barcodereader_camera_setting_cntx.flash_str[0] =
            (UI_string_type) GetString((U16) (STR_GLOBAL_OFF));

        g_barcodereader_camera_setting_cntx.flash_str[1] =
            (UI_string_type) GetString((U16) (STR_GLOBAL_ON));        
    
    SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8) GetString((U16) (STR_ID_BARCODEREADER_FLASH)));
    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[item_offset++],
        MMI_BARCODEREADER_SETTING_FLASH_COUNT,
        (U8 **) g_barcodereader_camera_setting_cntx.flash_str,
        &g_barcodereader_camera_setting_cntx.flash_selected);
#endif /* __MMI_BARCODEREADER_FLASH__ */ 

    for (i = 0; i < MMI_BARCODEREADER_SETTING_EV_COUNT; i++)
    {
        g_barcodereader_camera_setting_cntx.ev_str[i] =
            (UI_string_type) GetString((U16) (STR_ID_BARCODEREADER_EV_START + i + 1));
    }
    SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8) GetString((U16) (STR_ID_BARCODEREADER_EV)));
    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[item_offset++],
        MMI_BARCODEREADER_SETTING_EV_COUNT,
        (U8 **) g_barcodereader_camera_setting_cntx.ev_str,
        &g_barcodereader_camera_setting_cntx.ev_selected);

#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
    for (i = 0; i < MMI_BARCODEREADER_SETTING_FOCUS_MODE_COUNT; i++)
    {
        g_barcodereader_camera_setting_cntx.af_mode_str[i] =
            (UI_string_type) GetString((U16) (STR_ID_BARCODEREADER_FOCUS_MODE_START + i + 1));
    }
    SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8) GetString((U16) (STR_ID_BARCODEREADER_FOCUS_MODE)));
    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[item_offset++],
        MMI_BARCODEREADER_SETTING_FOCUS_MODE_COUNT,
        (U8 **) g_barcodereader_camera_setting_cntx.af_mode_str,
        &g_barcodereader_camera_setting_cntx.af_mode_selected);
#endif /* __MMI_BARCODEREADER_FOCUS_MODE__ */ 

#ifdef __MMI_BARCODEREADER_BANDING__
    for (i = 0; i < MMI_BARCODEREADER_SETTING_BANDING_COUNT; i++)
    {
        g_barcodereader_camera_setting_cntx.banding_str[i] =
            (UI_string_type) GetString((U16) (STR_ID_BARCODEREADER_BANDING_START + i + 1));
    }
    SetInlineItemCaption(&wgui_inline_items[item_offset++], (PU8) GetString((U16) (STR_ID_BARCODEREADER_BANDING)));
    SetInlineItemActivation(&wgui_inline_items[item_offset], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemSelect(
        &wgui_inline_items[item_offset++],
        MMI_BARCODEREADER_SETTING_BANDING_COUNT,
        (U8 **) g_barcodereader_camera_setting_cntx.banding_str,
        &g_barcodereader_camera_setting_cntx.banding_selected);
#endif /* __MMI_BARCODEREADER_BANDING__ */ 

    inputBuffer = GetCurrNInputBuffer(SCR_ID_BARCODEREADER_CAMERA_SETTING, &inputBufferSize);

    if (inputBuffer != NULL)
    {
        SetCategory57Data(wgui_inline_items, MMI_BARCODEREADER_CAMERA_SETTING_ITEM_COUNT * 2, inputBuffer);
    }

    RegisterHighlightHandler(mmi_barcodereader_option_setting_highlight_hdlr);

    /* show category */
    ShowCategory57Screen(
        barcode_camera_setting_title_id,
        GetRootTitleIcon(MENU_ID_BARCODEREADER_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        item_offset,
        item_icons,
        wgui_inline_items,
        0,
        guiBuffer);

    /* set key hdlr */
    SetCategory57LeftSoftkeyFunction(mmi_barcodereader_option_setting_set_value);
    DisableCategory57ScreenDone();
    SetCategory57RightSoftkeyFunctions(GoBackHistory, GoBackHistory);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_load_camera_setting
 * DESCRIPTION
 *  load camera settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_load_camera_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if setting is already loaded from NVRAM, it is already exist in memory, do not loaded again */
    if (g_barcodereader_camera_setting_cntx.is_loaded != MMI_TRUE)
    {
        ReadRecord(
            NVRAM_EF_BARCODEREADER_SETTING_LID,
            1,
            (void*)&g_barcodereader_record_setting_cntx,
            NVRAM_EF_BARCODEREADER_SETTING_SIZE,
            &error);

        if (g_barcodereader_record_setting_cntx.ev == 0xffff)
        {
            mmi_barcodereader_restore_camera_setting();
        }

        g_barcodereader_camera_setting_cntx.flash_selected = g_barcodereader_record_setting_cntx.flash;
        g_barcodereader_camera_setting_cntx.ev_selected = g_barcodereader_record_setting_cntx.ev;
        g_barcodereader_camera_setting_cntx.af_mode_selected = g_barcodereader_record_setting_cntx.af_mode;
        g_barcodereader_camera_setting_cntx.banding_selected = g_barcodereader_record_setting_cntx.banding;

        g_barcodereader_camera_setting_cntx.is_loaded = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_store_camera_setting
 * DESCRIPTION
 *  store camera settings to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_store_camera_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_BARCODEREADER_SETTING_LID,
        1,
        (void*)&g_barcodereader_record_setting_cntx,
        NVRAM_EF_BARCODEREADER_SETTING_SIZE,
        &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_restore_camera_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_restore_camera_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_record_setting_cntx.flash = MMI_BARCODEREADER_DEFAULT_SETTING_FLASH;
    g_barcodereader_record_setting_cntx.banding = MMI_BARCODEREADER_DEFAULT_SETTING_BANDING;
    g_barcodereader_record_setting_cntx.ev = MMI_BARCODEREADER_DEFAULT_SETTING_EV;
    g_barcodereader_record_setting_cntx.af_mode = MMI_BARCODEREADER_SETTING_FOCUS_MODE_AUTO;

    mmi_barcodereader_store_camera_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_option_setting_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for camera setting menu
 * PARAMETERS
 *  index       [IN]        Highlighted item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_option_setting_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    SetCategory57LeftSoftkeyFunction(mmi_barcodereader_option_setting_set_value);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_option_setting_set_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_barcodereader_option_setting_set_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_barcodereader_record_setting_cntx.flash = g_barcodereader_camera_setting_cntx.flash_selected;
    g_barcodereader_record_setting_cntx.ev = g_barcodereader_camera_setting_cntx.ev_selected;
    g_barcodereader_record_setting_cntx.af_mode = g_barcodereader_camera_setting_cntx.af_mode_selected;
    g_barcodereader_record_setting_cntx.banding = g_barcodereader_camera_setting_cntx.banding_selected;
    mmi_barcodereader_store_camera_setting();

    mmi_display_popup((UI_string_type) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);

    DeleteScreenIfPresent(SCR_ID_BARCODEREADER_CAMERA_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_check_flash_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_check_flash_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_barcodereader_record_setting_cntx.flash == MMI_BARCODEREADER_SETTING_FLASH_OFF)
    {
        mdi_camera_flash_setting(FALSE);
    }
    else
    {
        mdi_camera_flash_setting(TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_flash_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_next     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_flash_change(MMI_BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_barcodereader_record_setting_cntx.flash < MMI_BARCODEREADER_SETTING_FLASH_COUNT - 1)
        {
            g_barcodereader_record_setting_cntx.flash++;
        }
        else
        {
            g_barcodereader_record_setting_cntx.flash = 0;
        }
    }
    else
    {
        if (g_barcodereader_record_setting_cntx.flash >= 1)
        {
            g_barcodereader_record_setting_cntx.flash--;
        }
        else
        {
            g_barcodereader_record_setting_cntx.flash = MMI_BARCODEREADER_SETTING_FLASH_COUNT - 1;
        }
    }

    /* update quality parameter to mdi_camera */
    if (g_barcodereader_record_setting_cntx.flash == MMI_BARCODEREADER_SETTING_FLASH_OFF)
    {
        mdi_camera_flash_setting(FALSE);
    }
    else
    {
        mdi_camera_flash_setting(TRUE);
    }

    mmi_barcodereader_store_camera_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_get_flash_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_barcodereader_get_flash_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_barcodereader_record_setting_cntx.flash;
}


#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_focus_mode_change
 * DESCRIPTION
 *  shot mode hotkey pressed
 * PARAMETERS
 *  is_next     [IN]        Change shot mode to next, otherwise is previous
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_focus_mode_change(MMI_BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_barcodereader_record_setting_cntx.af_mode < MMI_BARCODEREADER_SETTING_FOCUS_MODE_COUNT - 1)
        {
            g_barcodereader_record_setting_cntx.af_mode++;
        }
        else
        {
            g_barcodereader_record_setting_cntx.af_mode = 0;
        }
    }
    else
    {
        if (g_barcodereader_record_setting_cntx.af_mode >= 1)
        {
            g_barcodereader_record_setting_cntx.af_mode--;
        }
        else
        {
            g_barcodereader_record_setting_cntx.af_mode = MMI_BARCODEREADER_SETTING_FOCUS_MODE_COUNT - 1;
        }
    }

    /* update quality parameter to mdi_camera */
#if MDI_CAMERA_MT6238_SERIES
    mdi_camera_update_para_af_range(mmi_barcodereader_focus_mode_command_map
                                   [g_barcodereader_record_setting_cntx.af_mode]);    
#else
    mdi_camera_update_para_af_mode(mmi_barcodereader_focus_mode_command_map
                                   [g_barcodereader_record_setting_cntx.af_mode]);
#endif
    mmi_barcodereader_store_camera_setting();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_get_focus_mode_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_barcodereader_get_focus_mode_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_barcodereader_record_setting_cntx.af_mode;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_ev_status_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_next     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_ev_status_change(MMI_BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next)
    {
        if (g_barcodereader_record_setting_cntx.ev >= MMI_BARCODEREADER_SETTING_EV_COUNT - 1)
        {
            return;
        }
        g_barcodereader_record_setting_cntx.ev =
            (g_barcodereader_record_setting_cntx.ev + 1) % MMI_BARCODEREADER_SETTING_EV_COUNT;
    }
    else
    {
        if (g_barcodereader_record_setting_cntx.ev < 1)
        {
            return;
        }
        g_barcodereader_record_setting_cntx.ev =
            (g_barcodereader_record_setting_cntx.ev - 1 + MMI_BARCODEREADER_SETTING_EV_COUNT) %
            MMI_BARCODEREADER_SETTING_EV_COUNT;
    }

    mdi_camera_update_para_ev(mmi_barcodereader_ev_command_map[g_barcodereader_record_setting_cntx.ev]);
    mmi_barcodereader_store_camera_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_get_ev_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_barcodereader_get_ev_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_barcodereader_record_setting_cntx.ev;
}


MMI_BOOL mmi_barcodereader_ev_is_reach_max(void)
{
#ifdef __MMI_BARCODEREADER_EV_4__
    if (g_barcodereader_record_setting_cntx.ev == MMI_BARCODEREADER_SETTING_EV_P4)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#endif
    
#ifdef __MMI_BARCODEREADER_EV_3__
    if (g_barcodereader_record_setting_cntx.ev == MMI_BARCODEREADER_SETTING_EV_P3)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#endif

#ifdef __MMI_BARCODEREADER_EV_2__
    if (g_barcodereader_record_setting_cntx.ev == MMI_BARCODEREADER_SETTING_EV_P2)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#endif

    if (g_barcodereader_record_setting_cntx.ev == MMI_BARCODEREADER_SETTING_EV_P1)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
    
}


MMI_BOOL mmi_barcodereader_ev_is_reach_min(void)
{
    if (g_barcodereader_record_setting_cntx.ev == 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_banding_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_next     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_banding_change(MMI_BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_next == MMI_TRUE)
    {
        g_barcodereader_record_setting_cntx.banding =
            (g_barcodereader_record_setting_cntx.banding + 1) % MMI_BARCODEREADER_SETTING_BANDING_COUNT;
    }
    else
    {
        g_barcodereader_record_setting_cntx.banding =
            (g_barcodereader_record_setting_cntx.banding - 1 + MMI_BARCODEREADER_SETTING_BANDING_COUNT) %
            MMI_BARCODEREADER_SETTING_BANDING_COUNT;
    }

    /* update  parameter to mdi_camera */
    mdi_camera_update_para_banding(mmi_barcodereader_focus_mode_command_map
                                   [g_barcodereader_record_setting_cntx.banding]);
    mmi_barcodereader_store_camera_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_get_banding_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_barcodereader_get_banding_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_barcodereader_record_setting_cntx.banding;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_get_curr_zoom_factor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_barcodereader_get_curr_zoom_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_factor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //zoom_factor = g_camera_feature_zoom[g_barcodereader_camera_setting_cntx.zoom_index];
    return zoom_factor;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_set_curr_zoom_factor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  zoom_index      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_barcodereader_set_curr_zoom_factor(U16 zoom_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //g_barcodereader_camera_setting_cntx.zoom_index = CAMERA_DEFAULT_SETTING_ZOOM_IDX;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_get_default_zoom_factor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_barcodereader_get_default_zoom_factor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 zoom_factor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //zoom_factor = g_camera_feature_zoom[CAMERA_DEFAULT_SETTING_ZOOM_IDX];
    return zoom_factor;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_zoom_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_next     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_zoom_change(MMI_BOOL is_next)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 zoom_factor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    if (is_next == MMI_TRUE)
    {
        if (g_barcodereader_camera_setting_cntx.zoom_index < CAMERA_FEATURE_ZOOM_COUNT - 1)
        {
            g_barcodereader_camera_setting_cntx.zoom_index++;
        }
    }
    else
    {
        if (g_barcodereader_camera_setting_cntx.zoom_index > 0)
        {
            g_barcodereader_camera_setting_cntx.zoom_index--;
        }
    }

    zoom_factor = g_camera_feature_zoom[g_barcodereader_camera_setting_cntx.zoom_index];
    mdi_camera_update_para_zoom(zoom_factor);
    mmi_barcodereader_store_camera_setting();  */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_check_zoom_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_check_zoom_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 zoom_factor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    zoom_factor = g_camera_feature_zoom[g_barcodereader_camera_setting_cntx.zoom_index];
    mdi_camera_update_para_zoom(zoom_factor);*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_get_camera_setting_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  setting_which       [IN]        
 *  str1                [IN]        
 *  str2                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_get_camera_setting_string(
        mmi_barcodereader_camera_setting_enum setting_which,
        PS8 str1,
        PS8 str2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (setting_which)
    {
        case MMI_BARCODEREADER_CAMERA_SETTING_FLASH:
            mmi_ucs2ncpy((PS8) str1, (PS8) L"[ ", 2);
            mmi_ucs2ncat((PS8) str1, (PS8) GetString(STR_ID_BARCODEREADER_FLASH), (U32)BR_HINT_BUFFER_SIZE/ENCODING_LENGTH - 5);
            mmi_ucs2ncat((PS8) str1, (PS8) L" ]", 2);

			if (g_barcodereader_record_setting_cntx.flash == MMI_BARCODEREADER_SETTING_FLASH_OFF)
			{
				mmi_ucs2ncpy(
					str2,
					GetString((U16) (STR_GLOBAL_OFF)),
					(U32)BR_HINT_BUFFER_SIZE/ENCODING_LENGTH - 1);
			}
			else
			{
				mmi_ucs2ncpy(
					str2,
					GetString((U16) (STR_GLOBAL_ON)),
					(U32)BR_HINT_BUFFER_SIZE/ENCODING_LENGTH - 1);
			}
            break;

        case MMI_BARCODEREADER_CAMERA_SETTING_BANDING:
            mmi_ucs2ncpy((PS8) str1, (PS8) L"[ ", 2);
            mmi_ucs2ncat((PS8) str1, (PS8) GetString(STR_ID_BARCODEREADER_BANDING), (U32)BR_HINT_BUFFER_SIZE/ENCODING_LENGTH - 5);
            mmi_ucs2ncat((PS8) str1, (PS8) L" ]", 2);

            mmi_ucs2ncpy(
                str2,
                GetString((U16) (g_barcodereader_record_setting_cntx.banding + STR_ID_BARCODEREADER_BANDING_START + 1)),
                (U32)BR_HINT_BUFFER_SIZE/ENCODING_LENGTH - 1);
            break;

        case MMI_BARCODEREADER_CAMERA_SETTING_FOCUS_MODE:
            mmi_ucs2ncpy((PS8) str1, (PS8) L"[ ", 2);
            mmi_ucs2ncat((PS8) str1, (PS8) GetString(STR_ID_BARCODEREADER_FOCUS_MODE), (U32)BR_HINT_BUFFER_SIZE/ENCODING_LENGTH - 5);
            mmi_ucs2ncat((PS8) str1, (PS8) L" ]", 2);

            mmi_ucs2ncpy(
                str2,
                GetString((U16) (g_barcodereader_record_setting_cntx.af_mode + STR_ID_BARCODEREADER_FOCUS_MODE_START + 1)),
                (U32)BR_HINT_BUFFER_SIZE/ENCODING_LENGTH - 1);
            break;

        default:
            mmi_ucs2cpy(str1, "");
            mmi_ucs2cpy(str2, "");
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereder_init_camera_befor_preview
 * DESCRIPTION
 *  
 * PARAMETERS
 *  camera_setting_data     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereder_init_camera_befor_preview(mdi_camera_setting_struct *camera_setting_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_camera_load_default_setting(camera_setting_data);

    camera_setting_data->osd_rotate = 0;

    /* preview parametes */
    camera_setting_data->ev = mmi_barcodereader_ev_command_map[g_barcodereader_record_setting_cntx.ev];
    camera_setting_data->flash = mmi_barcodereader_flash_command_map[g_barcodereader_record_setting_cntx.flash];
    camera_setting_data->af_mode =
        mmi_barcodereader_focus_mode_command_map[g_barcodereader_record_setting_cntx.af_mode];
    camera_setting_data->banding = mmi_barcodereader_banding_command_map[g_barcodereader_record_setting_cntx.banding];
    camera_setting_data->osd_rotate = MDI_CAMERA_PREVIEW_ROTATE_0;
#ifdef __MMI_HORIZONTAL_BARCODEREADER__
    camera_setting_data->preview_width = MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT;
    camera_setting_data->preview_height = MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH;
#else
    camera_setting_data->preview_width = MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH;
    camera_setting_data->preview_height = MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT;
#endif

    /* capture parameters */
#ifdef __MMI_HORIZONTAL_BARCODEREADER__
    camera_setting_data->image_width = MMI_BARCODEREADER_IMAGE_HEIGHT;
    camera_setting_data->image_height = MMI_BARCODEREADER_IMAGE_WIDTH;
#else
    camera_setting_data->image_width = MMI_BARCODEREADER_IMAGE_WIDTH;
    camera_setting_data->image_height = MMI_BARCODEREADER_IMAGE_HEIGHT;
#endif
    camera_setting_data->lcm = MDI_CAMERA_PREVIEW_LCM_MAINLCD;
    camera_setting_data->preview_rotate = MMI_BARCODEREADER_PREVIEW_MAINLCD_ROTATE;
    camera_setting_data->lcm_rotate = MMI_BARCODEREADER_LCM_MAINLCD_ROTATE;

#ifdef CAMERA_MODULE_WITH_LCD
    gdi_layer_clear(CAMEAR_BG_TRASN_COLOR);
#endif 

#ifdef __MMI_BARCODEREADER_FOCUS_MODE__
#ifdef __MMI_HORIZONTAL_BARCODEREADER__
    {
        camera_setting_data->af_zone0_x = MMI_BARCODEREADER_AF_POSITION_1_X;
        camera_setting_data->af_zone0_y = MMI_BARCODEREADER_AF_POSITION_1_Y;
        camera_setting_data->af_zone1_x = MMI_BARCODEREADER_AF_POSITION_2_X;
        camera_setting_data->af_zone1_y = MMI_BARCODEREADER_AF_POSITION_2_Y;
        camera_setting_data->af_zone2_x = MMI_BARCODEREADER_AF_POSITION_3_X;
        camera_setting_data->af_zone2_y = MMI_BARCODEREADER_AF_POSITION_3_Y;
        camera_setting_data->af_zone3_x = MMI_BARCODEREADER_AF_POSITION_4_X;
        camera_setting_data->af_zone3_y = MMI_BARCODEREADER_AF_POSITION_4_Y;
        camera_setting_data->af_zone4_x = MMI_BARCODEREADER_AF_POSITION_5_X;
        camera_setting_data->af_zone4_y = MMI_BARCODEREADER_AF_POSITION_5_Y;
    }
#else /* __MMI_HORIZONTAL_BARCODEREADER__ */ 
    camera_setting_data->af_zone0_x =
        MMI_BARCODEREADER_PREVIEW_WINDOW_WIDTH / 2 + MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_X;
    camera_setting_data->af_zone0_y =
        MMI_BARCODEREADER_PREVIEW_WINDOW_HEIGHT / 2 + MMI_BARCODEREADER_PREVIEW_WINDOW_OFFSET_Y;
#endif /* __MMI_HORIZONTAL_BARCODEREADER__ */ 
#endif /* __MMI_BARCODEREADER_FOCUS_MODE__ */ /* __MMI_BARCODEREADERREADER_FOCUS_MODE__ */

}


void mmi_barcodereader_camera_set_title(U16 title_id)
{
    barcode_camera_setting_title_id = title_id;
}

#endif /* __MMI_BARCODEREADER__ */ 

