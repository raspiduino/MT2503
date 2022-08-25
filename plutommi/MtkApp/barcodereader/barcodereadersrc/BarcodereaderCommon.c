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
 *  BarcodeReadeCommon.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Barcode Reader Common
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
#include "MMI_features_barcodereader.h"

/***************************************************************************** 
* Included .h file
*****************************************************************************/
#include "mmi_include.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "USBDeviceGProt.h"
#include "gpioInc.h"
#include "CommonScreens.h"
#include "FileMgr.h"
#include "mmiapi_enum.h"
#include "BarcodereaderCommonProt.h"
#include "BarcodereaderCommonResDef.h"
#include "BarcodereaderLcd.h"
#include "resource_barcodereader_skins.h"
#ifdef __MMI_CAMCORDER__
#include "mmi_features_camcorder.h"
#include "CamcorderGprot.h"
#else
#include "CameraGprot.h"
#endif /* __MMI_CAMCORDER__ */
#include "SimDetectionGprot.h"
#include "NetworkSetupDefs.h"

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"
#endif 
#include "BarcodereaderOp00Prot.h"
#include "BarcodereaderOp11Prots.h"
#include "BarcodereaderCameraSettingProt.h"

#if defined(__MMI_DUAL_SIM_MASTER__)
/* under construction !*/
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#include "NetworkSetupDefs.h"

#include "mdi_include.h"

/***************************************************************************** 
* Function declare
*****************************************************************************/
static U16 mmi_barcodereader_get_error_string(S32 error_code);
extern void mmi_barcodereader_init_op01_app(void);
extern pBOOL mmi_bootup_get_active_flight_mode(void);

/***************************************************************************** 
* Function implementation
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_create_file_dir
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filepath        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 mmi_barcodereader_create_file_dir(PS8 filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_createpath[FMGR_PATH_BUFFER_SIZE];
    S8 buf_filepath[FMGR_PATH_BUFFER_SIZE];
    S32 fs_ret;
    S32 str_len;
    S32 cmp_ret;
    S32 i;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = FS_NO_ERROR;

    file_handle = FS_Open((kal_uint16*) filepath, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        return FS_NO_ERROR;
    }

    /* create directory if it is not there */
    mmi_ucs2cpy((PS8) buf_filepath, (PS8) filepath);

    str_len = mmi_ucs2strlen((PS8) buf_filepath);
    str_len *= ENCODING_LENGTH;

    /* skip drive. "z:\" */
    for (i = 3 * ENCODING_LENGTH; i < str_len; i += 2)
    {
        cmp_ret = mmi_ucs2ncmp((PS8) & buf_filepath[i], (PS8) L"\\", 1);
        if (cmp_ret == 0)
        {
            /* create dir */

            mmi_ucs2ncpy((PS8) buf_createpath, (PS8) buf_filepath, i / ENCODING_LENGTH);
            buf_createpath[i] = '\0';
            buf_createpath[i + 1] = '\0';

            fs_ret = FS_CreateDir((PU16) buf_createpath);

            if (fs_ret < 0)
            {
                return fs_ret;
            }
        }
    }

    return fs_ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_init_framework
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_init_framework(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* entry full screen app */
    entry_full_screen();

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /* stop bg music */
    mdi_audio_suspend_background_play();

    /* 
     * This is used to solve a very rare situation. When playing a IMELODY 
     * with backlight on/off, and the screen previous to this screen is a 
     * horizontal screen. Before enter this screen, the IMELODY turn off the
     * backlight. While exit previous screen, the layer rotate back to normal
     * size and the content is not correct. So when calling TurnOnBacklight, 
     * LCD is in sleepin state and draw wrong content to LCD.
     * So we need to clear the buffer first to avoid this situation.
     */
    gdi_layer_clear(GDI_COLOR_BLACK);

    /* stop MMI sleep */
    TurnOnBacklight(GPIO_BACKLIGHT_PERMANENT);

    /* force all playing keypad tone off */
    AudioStopReq(GetCurKeypadTone());

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* disalbe align timer  */
    UI_disable_alignment_timers();

    /* stop LED patten */
    StopLEDPatternBackGround();

    /* enable multi-layer */
    gdi_layer_multi_layer_enable();

#ifdef __MMI_TVOUT__
    /* since someone change lcd/lcm rotate mechanism (gdi_lcd_set_rotate_by_layer()), 
       we must call this function to change driver's mode */
    if (mdi_tvout_is_enable())
    {
        mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR, 0, 0);
    }
#endif /* __MMI_TVOUT__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_uninit_frameword
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_uninit_frameword(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* resume background audio */
    mdi_audio_resume_background_play();

    /* let MMI can sleep */
    TurnOffBacklight();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* resume alignment timer */
    UI_enable_alignment_timers();

    /* resume LED patten */
    StartLEDPatternBackGround();
    
    /* enable multi-layer */
    gdi_layer_multi_layer_disable();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_bolder_rect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x1                  [IN]        
 *  y1                  [IN]        
 *  x2                  [IN]        
 *  y2                  [IN]        
 *  bolder_width        [IN]        
 *  frame_color         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_draw_bolder_rect(S32 x1, S32 y1, S32 x2, S32 y2, S32 bolder_width, gdi_color frame_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_draw_rect(x1 - bolder_width, y1 - bolder_width, x2 + bolder_width, y2 + bolder_width, frame_color);
    gdi_draw_rect(x1 + bolder_width, y1 + bolder_width, x2 - bolder_width, y2 - bolder_width, frame_color);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_display_error_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_result        [IN]        
 *  error_type          [IN]        
 *  tone_id             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_display_error_popup(S32 error_result, S32 error_type, U8 tone_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = 0;
    mmi_event_notify_enum popup_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if has error */

    switch (error_type)
    {
        case MMI_BARCODEREADER_ERROR_TYPE_FROM_CAMERA:
            string_id = mdi_util_get_mdi_error_info(error_result, (mmi_event_notify_enum*) &popup_type);
            break;

        case MMI_BARCODEREADER_ERROR_TYPE_FROM_FS:
             string_id = mmi_fmgr_util_get_fs_error_info(error_result, (S32*) &popup_type);
            break;

        case MMI_BARCODEREADER_ERROR_TYPE_FROM_BARCODEREADER:
            string_id = mmi_barcodereader_get_error_string(error_result);
            popup_type = MMI_EVENT_FAILURE;
            break;

        default:
            string_id = STR_GLOBAL_ERROR;
            popup_type = MMI_EVENT_FAILURE;
            break;
    }


#if defined(__MMI_HORIZONTAL_BARCODEREADER__)
    mmi_display_popup_rotated((UI_string_type) GetString(string_id), popup_type, MMI_BARCODEREADER_OSD_ROTATE_0);
#else 
    mmi_display_popup((UI_string_type) GetString(string_id), popup_type);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_get_error_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_code      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U16 mmi_barcodereader_get_error_string(S32 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = STR_GLOBAL_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (error_code)
    {
        case MMI_BARCODEREADER_ERROR_NO_ERROR:
            /* string_id = ; */
            break;

        case MMI_BARCODEREADER_ERROR_ENCODING_ERROR:
            string_id = STR_ID_BARCODEREADER_ERROR_ENCODING_ERROR;
            break;

        case MMI_BARCODEREADER_OP01_ENCODING_ERROR:
            string_id = STR_ID_BARCODEREADER_OP01_ENCODING_ERROR;   
            break;

        case MMI_BARCODEREADER_ERROR_COMMON:
            string_id = STR_GLOBAL_ERROR;
            break;

        case MMI_BARCODEREADER_ERROR_DECODE_FAILED:
            string_id = STR_ID_BARCODEREADER_ERROR_DECODE_FAILED;
            break;

        case MMI_BARCODEREADER_ERROR_TOO_LONG_NUMBER:
            string_id = STR_ID_BARCODEREADER_ERROR_DECODE_FAILED;
            break;

        case MMI_BARCODEREADER_ERROR_NOT_DM_CODE:
            string_id = STR_ID_BARCODEREADER_ERROR_NOT_DM_CODE;
            break;

        case MMI_BARCODEREADER_ERROR_NOT_SUPPORT_THIS_SERIVCE:
            string_id = STR_ID_BARCODEREADER_ERROR_NOT_SUPPORT_THIS_SERIVCE;
            break;

        case MMI_BARCODEREADER_ERROR_NOT_SUPPORT_THIS_MODE:
            string_id = STR_ID_BARCODEREADER_ERROR_NOT_SUPPORT_THIS_MODE;
            break;

        case MMI_BARCODEREADER_ERROR_FORMAT:
            string_id = STR_ID_BARCODEREADER_ERROR_FORMAT;
            break;

        case MMI_BARCODEREADER_ERROR_TOO_LONG_URL:
            string_id = STR_ID_BARCODEREADER_ERROR_TOO_LONG_URL;
            break;

        case MMI_BARCODEREADER_ERROR_FORBID_DIRECT_MODE:
            string_id = STR_ID_BARCODEREADER_ERROR_FORBID_DIRECT_MODE;
            break;

        case MMI_BARCODEREADER_ERROR_FILE_CORRUPT:
            string_id = STR_ID_BARCODEREADER_ERROR_FILE_CORRUPT;
            break;

        case MMI_BARCODEREADER_ERROR_NO_SIMCARD:
            string_id = STR_ID_BARCODEREADER_ERROR_NO_SIMCARD;
            break;

        case MDI_RES_BARCODEREADER_DECODE_TIMEOUT:
            string_id = STR_ID_BARCODEREADER_ERROR_DECODE_TIMEOUT;
            break;

        case MMI_BARCODEREADER_ERROR_SERVER_NOT_CONNECT:
            string_id = STR_ID_BARCODEREADER_ERROR_SERVER_NOT_CONNECT;
            break;

        case MMI_BARCODEREADER_ERROR_SERVER_NOT_CONFIGED:
            string_id = STR_ID_BARCODEREADER_ERROR_SERVER_NOT_CONFIGED;
            break;

        case MMI_BARCODEREADER_ERROR_NO_STORAGE:
            string_id = STR_ID_BARCODEREADER_NOTIFY_NO_MEMORY_CARD;
            break;
            
        case MDI_RES_BARCODEREADER_IMAGE_ERROR:
        case MDI_RES_BARCODEREADER_MODULE_ERROR:
        case MDI_RES_BARCODEREADER_OUT_OF_MEMORY:
        case MDI_RES_BARCODEREADER_OVER_VERSION:
        case MDI_RES_BARCODEREADER_ERROR_CODE_TYPE:
            string_id = STR_ID_BARCODEREADER_ERROR_DECODE_FAILED;
            break;

        default:
            string_id = STR_GLOBAL_ERROR;
    }

    return string_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_ucs2_strtoken
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string          [IN]        
 *  seperate        [IN]        
 *  length          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_ucs2_strtoken(PS8 string, S8 seperate, PS32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string == NULL)
    {
        *length = 0;
        return;
    }

    tail = mmi_ucs2chr(string, seperate);
    /* not found */
    if (!tail)
    {
        *length = -1;
        return;
    }

    *length = (tail - string) / 2;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_draw_style_text
 * DESCRIPTION
 *  draw style text
 * PARAMETERS
 *  str             [IN]        String
 *  offset_x        [IN]        Offset x
 *  offset_y        [IN]        Offset y
 *  style_txt       [IN]        Text style
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_draw_style_text(PS8 str, S32 offset_x, S32 offset_y, S32 truncated_width, barcodereader_style_text_struct *style_txt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (r2lMMIFlag)
    {
        offset_x += gui_get_string_width((UI_string_type) str);
    }

    if (truncated_width == 0)
    {
    if (style_txt->style == MMI_BARCODEREADER_TEXT_STYLE_NORMAL)
    {

        gui_move_text_cursor(offset_x, offset_y);
        gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
        gui_print_text((UI_string_type) str);
    }
    else if (style_txt->style == MMI_BARCODEREADER_TEXT_STYLE_BORDER)
    {
        gui_move_text_cursor(offset_x, offset_y);
        gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
        gui_set_text_border_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
        gui_print_bordered_text((UI_string_type) str);
    }
    else if (style_txt->style == MMI_BARCODEREADER_TEXT_STYLE_SHADOW)
    {
        gui_move_text_cursor(offset_x + 1, offset_y + 1);
        gui_set_text_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
        gui_print_text((UI_string_type) str);

        gui_move_text_cursor(offset_x, offset_y);
        gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
        gui_print_text((UI_string_type) str);
    }
    else
    {
        MMI_ASSERT(0);
    }
    }
    else if (truncated_width > 0)
    {
        if (style_txt->style == MMI_BARCODEREADER_TEXT_STYLE_NORMAL)
        {
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_print_truncated_text(offset_x,offset_y,truncated_width,(UI_string_type) str);
        }
        else if (style_txt->style == MMI_BARCODEREADER_TEXT_STYLE_BORDER)
        {
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_set_text_border_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
            gui_print_truncated_borderd_text(offset_x,offset_y,truncated_width,(UI_string_type) str);
        }
        else if (style_txt->style == MMI_BARCODEREADER_TEXT_STYLE_SHADOW)
        {
            gui_set_text_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
            gui_print_truncated_text(offset_x+1,offset_y+1,truncated_width,(UI_string_type) str);

            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_print_truncated_text(offset_x,offset_y,truncated_width,(UI_string_type) str);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        MMI_ASSERT(truncated_width>=0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_barcodereader_init_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_barcodereader_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_barcodereader_load_camera_setting();

#ifdef __MMI_OP11_BARCODEREADER__
/* under construction !*/
#elif defined (__MMI_OP01_BARCODEREADER__)
/* under construction !*/
#else
    mmi_barcodereader_init_op00_app();
#endif

}


/*****************************************************************************
* FUNCTION
*  mmi_barcodereader_is_network_permit
* DESCRIPTION
*  is net work is available
* PARAMETERS
*  MMI_TRUE  judge the net work
*  MMI_FALSE judge the sim valid
* RETURNS
*  MMI_TRUE  net work is available
*  MMI_FALSE net work is unavailable
*****************************************************************************/
MMI_BOOL mmi_barcodereader_is_network_permit(MMI_BOOL is_net)
{
    if (mmi_bootup_get_active_flight_mode() != 0)    
    {
        return MMI_FALSE;
    }
    
#if !defined(__MMI_DUAL_SIM_MASTER__)
    
    if (is_net)
    {
        if (mmi_bootup_is_network_service_available() == TRUE)
        {
            return MMI_TRUE;
        }
    }
    else
    {
    #if defined(__MMI_WLAN_FEATURES__)
        if (mmi_netset_get_active_preferred_mode() == P_WLAN_ONLY)
        {
            return MMI_FALSE;
        }
    #endif
        if (mmi_bootup_is_sim_valid())
        {
            return MMI_TRUE;
        }
    }
    
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_WLAN_FEATURES__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif
    
    return MMI_FALSE;
}

#endif
