/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
* SWFlashPlayer.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This file is intends to handle all scenario of swflash player
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

#include "MMI_include.h"

#ifdef __MMI_SWFLASH__
#ifdef SWFLASH_NEOMTEL

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "ProtocolEvents.h"
#include "MainMenuDef.h"
#include "SettingProfile.h"

/* Mime type */
#include "app_mine.h"

/* File and Memory */
#include "FileManagerGProt.h"
#include "FileManagerDef.h"
#include "FileMgr.h"
#ifdef __DRM_SUPPORT__
#include "RightsMgrGProt.h"
#endif
#include "rtfiles.h"
#include "med_smalloc.h"
#include "med_api.h"
/* Data Account */
#include "DataAccountGProt.h"
#include "DataAccountDef.h"
#include "wapadp.h"
#include "wap_ps_struct.h"

/* MDI */
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_swflash.h"
#include "mdi_include.h"

/* NVRAM */

/* mmi_chset */
#include "Conversions.h"

/* Setting */
#include "SettingDefs.h"

/* Download Agent */
//#include "DLAgentResDef.h"
#include "SettingProfile.h"

/* Silent or Meeting Mode */
#include "ProfileGprots.h"

/* LED */
#include "gpioInc.h"            

/*sim card*/
#include "simDetectionGprot.h"


#ifdef __MMI_TOUCH_SCREEN__
#endif 

/* SWFlash */
#include "SWFlashGProt.h"
#include "SWFlashProt.h"
#include "SWFlashDef.h"

#if defined(__MMI_DUAL_SIM_MASTER__)
/* under construction !*/
#endif  /* __MMI_DUAL_SIM_MASTER__ */

#include "NetworkSetupDefs.h"

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#include "UcmSrvGProt.h"
#endif /*__MMI_UCM__*/

/* NVRAM */
#include "nvram_enums.h"
#include "nvram_interface.h"


/***************************************************************************** 
* Define
*****************************************************************************/
#define MMI_SWFLASH_KEY_NUMBER (18)
#ifdef __MMI_SWFLASH_STOP_AT_THE_LAST_FRAME__
#define MMI_SWLFASH_LAST_FRAME_BUFFER_SIZE  (LCD_WIDTH * LCD_HEIGHT * 2)
#endif

/***************************************************************************** 
* Local Variable
*****************************************************************************/
typedef struct
{
    
    U8 volume;
    S8 *printable_str;
    MMI_BOOL is_load_setting;            /*if setting load is ready*/
    MMI_BOOL is_zdd;                     /*if the works is zdd file*/
										 U8 srcAPP;                           /*indicate the command come from 
										 0: filemgr 1: my favorite 2:other*/   
										 MMI_BOOL is_nexturl_on;        /*if player will go to next url or not*/
										 
										 S16 layer_offset_x;
										 S16 layer_offset_y;
										 S16 layer_width;
										 S16 layer_height;
										 U8 swflash_cmp_full_path[FMGR_MAX_PATH_LEN *ENCODING_LENGTH + ENCODING_LENGTH];
										 
										 gdi_handle swflash_play_layer;
										 gdi_handle swflash_base_layer;
#ifdef __MMI_SWFLASH_STOP_AT_THE_LAST_FRAME__
										 PU8 last_frame_buffer;
#endif
} mmi_swflash_context_struct;

static mmi_swflash_context_struct g_swflash_cntx;


/***************************************************************************** 
* Extern Variable
*****************************************************************************/
extern mdi_swflash_info_struct wgui_swflash_info;

/*****************************************************************************
* Local function                                                     
*****************************************************************************/

static void mmi_swflash_play_callback(MDI_RESULT result);
static void mmi_swflash_play_status(mdi_swflash_pl_state_enum state);
#ifdef __BT_SPK_VOL_CONTROL__
static MMI_BOOL mmi_swflash_hfp_volume_callback(U8 volume, MMI_BOOL is_mute);
#endif
/*****************************************************************************
* FUNCTION
*  mmi_swflash_init_app
* DESCRIPTION
*  init video player applcation, register highlight handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_swflash_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    g_swflash_cntx.is_load_setting = MMI_FALSE;
    g_swflash_cntx.is_zdd = MMI_FALSE;
    g_swflash_cntx.is_nexturl_on = MMI_FALSE;
    g_swflash_cntx.printable_str=NULL;
    mmi_swflash_load_setting();
    mdi_swflash_init();
    mmi_swflash_dl_init();
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_load_setting
* DESCRIPTION
*  load setting from NVRAM
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_swflash_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 IMEIbuf[16];
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_swflash_cntx.is_load_setting)
    {
        return;
    }
	
    g_swflash_cntx.is_load_setting = MMI_TRUE;
	
    /* volume setting */
    ReadValue(NVRAM_SWFLASH_VOLUME, &g_swflash_cntx.volume, DS_BYTE, &error);
    nvram_get_imei_value(16, IMEIbuf, 1);
    mdi_swflash_set_imei(IMEIbuf);
    if (g_swflash_cntx.volume > 6)
    {
        g_swflash_cntx.volume = 4;
        WriteValue(NVRAM_SWFLASH_VOLUME, &g_swflash_cntx.volume, DS_BYTE, &error);
    }
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_set_file_full_path
* DESCRIPTION
*  set the file full path 
* PARAMETERS
*  path:the folder path 
*  filename: the file name(not the full name)
* RETURNS
*  void
*****************************************************************************/

void mmi_swflash_set_file_full_path(const S8 *path,const S8 * filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    mmi_ucs2cpy((PS8)g_swflash_cntx.swflash_cmp_full_path,path); 
    mmi_ucs2cat((PS8) g_swflash_cntx.swflash_cmp_full_path, (PS8) filename);
}

void mmi_swflash_option_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret;
    U32 total_len = 0;
    U32 current_len = 0;
    U32 category = 0;
	
    FMGR_FILE_INFO_STRUCT info;
    U16 app_id;
    S8  *filepath;

	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filepath = mmi_fmgr_get_current_fileinfo(&info, &app_id);
#ifdef __PLUTO_MMI_PACKAGE__
    if(app_id == APP_FILEMANAGER)
#else
    if (0)
#endif
    {
        g_swflash_cntx.srcAPP = 0;
    }
    else if(app_id == APP_MYFAVORITE)  
    {
        g_swflash_cntx.srcAPP = 1;
    }
    else
    {
        g_swflash_cntx.srcAPP = 2;
    }
	
    /* Only FMGR has copy/move */
#ifdef __PLUTO_MMI_PACKAGE__
    if(app_id != APP_FILEMANAGER)
#else
    if (1)
#endif        
    {
        mmi_frm_hide_menu_item(MENU_ID_FMGR_GEN_OPTION_COPY);
        mmi_frm_hide_menu_item(MENU_ID_FMGR_GEN_OPTION_MOVE);
    }
	
    /* in My Favorite, turn off 3 options. */
    if (app_id == APP_MYFAVORITE)
    {
        mmi_frm_hide_menu_item(MENU_ID_FMGR_GEN_OPTION_DETAIL);
        mmi_frm_hide_menu_item(MENU_ID_FMGR_GEN_OPTION_DELETE_ALL);
        mmi_frm_hide_menu_item(MENU_ID_FMGR_GEN_OPTION_SORT);
    }
	
	
    /*check if the file is complete ,undemanged,size is reasonable*/
    ret = mdi_swflash_check_download_file((U16*) filepath, &total_len, &current_len, &category);
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        mmi_frm_hide_menu_item(MENU_ID_SWFLASH_OPTION_DOWNLOAD);
        mmi_frm_hide_menu_item(MENU_ID_SWFLASH_OPTION_INFO);
        mmi_frm_hide_menu_item(MENU_ID_SWFLASH_OPTION_PLAY);
        mmi_frm_hide_menu_item(MENU_ID_FMGR_GEN_OPTION_FORWARD_USE);
        return;
    }
	
    /*check if is zdd file*/
    if (FMGR_FILTER_IS_SET(&fileinfo->file_type,FMGR_TYPE_ZDD))
    {
        mmi_ucs2cpy((S8*) g_swflash_cntx.swflash_cmp_full_path, (S8*) filepath);
        g_swflash_cntx.is_zdd = MMI_TRUE;
        if ((mmi_bootup_get_active_flight_mode() == MMI_TRUE)||
            (mmi_swflash_is_network_services_available() == MMI_FALSE))
        {   
            /* ZDD can only be download when has network */
            mmi_frm_hide_menu_item(MENU_ID_SWFLASH_OPTION_DOWNLOAD);
            mmi_frm_hide_menu_item(MENU_ID_SWFLASH_OPTION_INFO);
        }
        /*check current wap support*/
#ifndef WAP_SUPPORT
        mmi_frm_hide_menu_item(MENU_ID_SWFLASH_OPTION_DOWNLOAD);
        mmi_frm_hide_menu_item(MENU_ID_SWFLASH_OPTION_INFO);
#endif
        /* ZDD cannot be play */
        mmi_frm_hide_menu_item(MENU_ID_SWFLASH_OPTION_PLAY);
		
        /* ZDD cannot be forward */
        //mmi_frm_hide_menu_item(MENU_ID_FMGR_GEN_OPTION_FORWARD_SEND);
        mmi_frm_hide_menu_item(MENU_ID_FMGR_GEN_OPTION_FORWARD_USE);
        return;
    }
	
    /* only ZDD has download */
    mmi_frm_hide_menu_item(MENU_ID_SWFLASH_OPTION_DOWNLOAD);
    g_swflash_cntx.is_zdd = MMI_FALSE;
	
    /* only MyFavorite has "info" */
    if(g_swflash_cntx.srcAPP != 1)
        mmi_frm_hide_menu_item(MENU_ID_SWFLASH_OPTION_INFO);
	
    /*check play file status*/
    if (total_len > 0 && current_len == total_len)
    {
        /* can be used for playback */
        mmi_ucs2cpy((S8*) g_swflash_cntx.swflash_cmp_full_path, (S8*) filepath);
        if (FMGR_FILTER_IS_SET(&fileinfo->file_type,FMGR_TYPE_VIS) || FMGR_FILTER_IS_SET(&fileinfo->file_type,FMGR_TYPE_MVIS))
        {
            /*.vis, mvis total four digit*/
            if (fileinfo->is_short)
            {
                mmi_chset_mixed_text_to_ucs2_str(
                    (U8*) wgui_swflash_info.title,
                    (FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH,
                    (U8*) fileinfo->file_name,
                    g_chset_text_encoding);
            }
            else
            {
                mmi_ucs2ncpy((S8*)wgui_swflash_info.title,fileinfo->file_name,mmi_ucs2strlen((S8*)fileinfo->file_name)-4);
            }
        }
        else
        {
            /*.ivis,kvis total five digit*/
            if (fileinfo->is_short)
            {
                mmi_chset_mixed_text_to_ucs2_str(
                    (U8*) wgui_swflash_info.title,
                    (FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH,
                    (U8*) fileinfo->file_name,
                    g_chset_text_encoding);
            }
            else
            {
                mmi_ucs2ncpy((S8*)wgui_swflash_info.title,fileinfo->file_name,mmi_ucs2strlen((S8*)fileinfo->file_name)-5);
            }
        }
        /*store works date ,time ,size*/
        date_string(&(info.time), (PU16) & (wgui_swflash_info.date), DT_IDLE_SCREEN);
        time_string(&(info.time), (PU16) & (wgui_swflash_info.time), DT_IDLE_SCREEN);
        wgui_swflash_info.size = fileinfo->file_size;
    }
	
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_is_network_services_available
* DESCRIPTION
*  check if the network is available 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL mmi_swflash_is_network_services_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
/* under construction !*/
#endif
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_SINGLE_CALL__
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
#else /* __MMI_DUAL_SIM_SINGLE_CALL__ */
	
    return mmi_bootup_is_network_service_available();
	
#endif /* __MMI_DUAL_SIM_SINGLE_CALL__ */
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_get_category
* DESCRIPTION
*  Callback function from file manaegr
* PARAMETERS
*  filename        [?]     
*  downloaded      [?]     
*  fullname        [?]         (Full path name of the file )(?)
* RETURNS
*  void
*****************************************************************************/
U32 mmi_swflash_get_category(void *filename, S32 *downloaded,FMGR_FILTER *type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* filefullname passed from FileMgr is full file name */
	
    *downloaded = 1;
    if (FMGR_FILTER_IS_SET(type,FMGR_TYPE_VIS))
    {
        return 1;  /*animation*/
    }
    else if(FMGR_FILTER_IS_SET(type,FMGR_TYPE_IVIS))
    {
        return 3;  /*game*/
    }
    else if(FMGR_FILTER_IS_SET(type,FMGR_TYPE_KVIS))
    {
        return 5;  /*kalaok*/
    }
    
    else if(FMGR_FILTER_IS_SET(type,FMGR_TYPE_MVIS))
    {
        return 7;  /*move clip*/
    }
    
    else if(FMGR_FILTER_IS_SET(type,FMGR_TYPE_ZDD))
    {
        return 9;  /*describle file*/
    } 
    return 0;
}

/*****************************************************************************
* FUNCTION
*  mmi_swflash_press_inc_volume
* DESCRIPTION
*  increase volume
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_swflash_press_inc_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int silent = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    silent = IsSilentModeActivated() || IsMeetingModeActivated();
    if (!silent && g_swflash_cntx.volume < 6)
    {
        S16 error;
		
        if (g_swflash_cntx.volume == 0)
        {
            mdi_audio_set_mute(MDI_VOLUME_MEDIA, FALSE);
            g_swflash_cntx.volume++;
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_swflash_cntx.volume);
        }
        else
        {
            g_swflash_cntx.volume++;
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_swflash_cntx.volume);
        }
        WriteValue(NVRAM_SWFLASH_VOLUME, &g_swflash_cntx.volume, DS_BYTE, &error);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_press_dec_volume
* DESCRIPTION
*  depress the volume
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_swflash_press_dec_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int silent = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    silent = IsSilentModeActivated() || IsMeetingModeActivated();
	
    if (!silent && g_swflash_cntx.volume > 0)
    {
        S16 error;
		
        if (g_swflash_cntx.volume == 1)
        {
            mdi_audio_set_mute(MDI_VOLUME_MEDIA, TRUE);
            g_swflash_cntx.volume--;
        }
        else
        {
            g_swflash_cntx.volume--;
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_swflash_cntx.volume);
        }
		
        WriteValue(NVRAM_SWFLASH_VOLUME, &g_swflash_cntx.volume, DS_BYTE, &error);
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_swflash_sms_interrupt_hdlr
* DESCRIPTION
*  the preprocess function of sms interrupt
* PARAMETERS
*  inMsg: the message come from framework
* RETURNS
*  void
*****************************************************************************/

static U8 mmi_swflash_sms_interrupt_hdlr(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInterruptPopupDisplay(POPUP_ALL_OFF);
    PlayVibratorOnce();
    return FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_key_down
* DESCRIPTION
*  set_key down handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_swflash_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    mdi_swflash_key_down_event(Keycode);
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_key_up
* DESCRIPTION
*  set_key up handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_swflash_key_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);
    mdi_swflash_key_up_event(Keycode);
}



/*****************************************************************************
* FUNCTION
*  mmi_swflash_set_key_handle
* DESCRIPTION
*  set_key_handle
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_swflash_set_key_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 swFlashScreenDigits[MMI_SWFLASH_KEY_NUMBER] = {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5,
        KEY_6,KEY_7, KEY_8, KEY_9, KEY_STAR,KEY_POUND,KEY_UP_ARROW,KEY_DOWN_ARROW,KEY_RIGHT_ARROW,KEY_LEFT_ARROW,
        KEY_ENTER,KEY_SEND};
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    SetGroupKeyHandler(mmi_swflash_key_down, swFlashScreenDigits, MMI_SWFLASH_KEY_NUMBER, KEY_EVENT_DOWN);
    SetGroupKeyHandler(mmi_swflash_key_up, swFlashScreenDigits, MMI_SWFLASH_KEY_NUMBER, KEY_EVENT_UP);
}

/*****************************************************************************
* FUNCTION
*  mmi_swflash_post_interrupt_hdlr
* DESCRIPTION
*  the post function of sms interrupt
* PARAMETERS
*  inMsg:the message come from framework
* RETURNS
*  void
*****************************************************************************/

static U8 mmi_swflash_post_interrupt_hdlr(mmi_frm_int_event_type interrupt_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetInterruptPopupDisplay(POPUP_ALL_ON);
    return FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_set_interrupt_handler
* DESCRIPTION
* set_interrupt_handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void  mmi_swflash_set_interrupt_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    mmi_frm_block_interrupt_event_handler(MMI_FRM_INT_SMS | MMI_FRM_INT_WAP_MMS | MMI_FRM_INT_MMI_JAVA_TIMEALARM_PUSH, 
		mmi_swflash_sms_interrupt_hdlr,
        mmi_swflash_post_interrupt_hdlr);    
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_reset_interrupt_handler
* DESCRIPTION
* set_interrupt_handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void  mmi_swflash_reset_interrupt_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_clear_interrupt_event_handler(MMI_FRM_INT_SMS | MMI_FRM_INT_WAP_MMS);
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_wivg_render
* DESCRIPTION
*  callback function for category227
* PARAMETERS
*  coordinate      [?]     [?]
* RETURNS
*  void
*****************************************************************************/
static void mmi_swflash_wivg_render(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* width and height need to assign before open_file for create buffer */
    g_swflash_cntx.layer_offset_x = coordinate->s16X;
    g_swflash_cntx.layer_offset_y = coordinate->s16Y;
    g_swflash_cntx.layer_width = coordinate->s16Width;
    g_swflash_cntx.layer_height = coordinate->s16Height;
	
    return;
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_pen_event
* DESCRIPTION
*  touch screen callback function for category227
* PARAMETERS
*  pen_event      [in]     type of pen event
*  point          [in]     coordinate of pen
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL  mmi_swflash_pen_event(mmi_pen_event_type_enum pen_event,mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    switch(pen_event)
    {
    case MMI_PEN_EVENT_DOWN:
        return mdi_swflash_pen_down_event(point);
        break;
    case MMI_PEN_EVENT_UP:
        return mdi_swflash_pen_up_event(point);
        break;
    case MMI_PEN_EVENT_MOVE:
        return mdi_swflash_pen_move_event(point);
        break;
    default:break;
    }
#endif
    return 0;
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_play_screen_delete_callback
* DESCRIPTION
*  this function is the callback function when swflash play screen is deleted
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
U8 mmi_swflash_play_screen_delete_callback(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    g_swflash_cntx.is_nexturl_on = MMI_FALSE;
    mmi_swflash_set_save_file(MMI_TRUE);
#ifdef __MMI_SWFLASH_STOP_AT_THE_LAST_FRAME__
    if (g_swflash_cntx.last_frame_buffer)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&g_swflash_cntx.last_frame_buffer);
        g_swflash_cntx.last_frame_buffer = NULL;
    }
#endif
    return FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_option_play_entry_screen
* DESCRIPTION
*  the entry function of swflash play
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_swflash_option_play_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;
    S16 error;
    MMI_ID_TYPE string_id;
    mmi_event_notify_enum popup_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        mmi_fmgr_close_option_screen();
        return;
    }
#endif
	
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SWFLASH_APP_ENTRY_PLAY);
    ReadValue(NVRAM_SWFLASH_VOLUME, &g_swflash_cntx.volume, DS_BYTE, &error);
    mdi_swflash_set_is_from_player(MMI_TRUE);
    EntryNewScreen(SCR_ID_SWFLASH_OPTION_PLAY, mmi_swflash_option_play_exit_screen, NULL, NULL);
    DeleteScreenIfPresent(SCR_ID_SWFLASH_PERCENTAGE_BAR);
    
    /*BT control phone sound*/
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(APP_SWFLASH, MDI_AUD_VOL_LEVEL_NORMAL/*7 level volume*/, mmi_swflash_hfp_volume_callback);
#endif /* __BT_SPK_VOL_CONTROL__ */
	
    /* stop lcd sleep */
    TurnOnBacklight(0);
    /* stop LED patten */
    StopLEDPatternBackGround();
    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
    
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();
    
    ret = mdi_swflash_open_file((const S8*)g_swflash_cntx.swflash_cmp_full_path, VIS_PLAYER, &wgui_swflash_info);
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
		string_id = mdi_util_get_mdi_error_info(ret, &popup_type);
		mmi_display_popup((UI_string_type) GetString(string_id), popup_type);
        DeleteScreenIfPresent(SCR_ID_SWFLASH_OPTION_PLAY);
        mmi_fmgr_close_option_screen();
        return;
    }
	
    /* pause sound */
    mdi_audio_suspend_background_play();
    mdi_switch_device_ownership(MOD_MMI, MDI_DEVICE_AUDIO | MDI_DEVICE_CAMER | MDI_DEVICE_VIDEO);
    if (g_swflash_cntx.volume == 0)
    {
        mdi_audio_set_mute(MDI_VOLUME_MEDIA, TRUE);
    }
    else
    {
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_swflash_cntx.volume);
    }
	
    /*begin show category*/
    gdi_layer_lock_frame_buffer();          /*wait for decode ready*/
	
    ShowCategory227Screen(
        (PU8) GetString(STR_ID_SWFLASH_PLAYBACK),
        IMG_ID_SWFLASH_APP2,
        STR_GLOBAL_PAUSE,
        0,
        STR_GLOBAL_STOP,
        0,
        mmi_swflash_wivg_render,
        mmi_swflash_pen_event);
	
	
    /* create swflash layer on layer 1 */
    gdi_layer_multi_layer_enable();
    g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
    
    gdi_layer_create(
        g_swflash_cntx.layer_offset_x,
        g_swflash_cntx.layer_offset_y,
        g_swflash_cntx.layer_width,
        g_swflash_cntx.layer_height,
        &g_swflash_cntx.swflash_play_layer);
    ASSERT(g_swflash_cntx.swflash_play_layer != GDI_LAYER_EMPTY_HANDLE);
	
    gdi_layer_push_and_set_active(g_swflash_cntx.swflash_play_layer);
    gdi_layer_clear_background(GDI_COLOR_WHITE);
    gdi_layer_pop_and_restore_active();
	
    gdi_layer_get_base_handle(&g_swflash_cntx.swflash_base_layer);
    gdi_layer_set_blt_layer(g_swflash_cntx.swflash_base_layer, g_swflash_cntx.swflash_play_layer, 0, 0);
	
    ret = mdi_swflash_play(g_swflash_cntx.swflash_play_layer, 1, MDI_DEVICE_SPEAKER2, mmi_swflash_play_callback);
    gdi_layer_unlock_frame_buffer();             /*decode ready*/
	
    gdi_layer_blt_previous(
		g_swflash_cntx.layer_offset_x - 1,
		g_swflash_cntx.layer_offset_y - 1,
		g_swflash_cntx.layer_width+ g_swflash_cntx.layer_offset_x,
		g_swflash_cntx.layer_height+ g_swflash_cntx.layer_offset_y);
    
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        gdi_layer_free(g_swflash_cntx.swflash_play_layer);
        g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
		string_id = mdi_util_get_mdi_error_info(ret, &popup_type);
		mmi_display_popup((UI_string_type) GetString(string_id), popup_type);	
        DeleteScreenIfPresent(SCR_ID_SWFLASH_OPTION_PLAY);
        mmi_fmgr_close_option_screen();
        return;
    }
	
    /*malloc buffer for last frame display*/
#ifdef __MMI_SWFLASH_STOP_AT_THE_LAST_FRAME__
    media_get_ext_buffer_cacheable(MOD_MMI,(void **)&g_swflash_cntx.last_frame_buffer, MMI_SWLFASH_LAST_FRAME_BUFFER_SIZE);
    MMI_ASSERT(g_swflash_cntx.last_frame_buffer != NULL);
#endif
	
    /*for interaction*/
    mmi_swflash_set_key_handle();
    SetDelScrnIDCallbackHandler(SCR_ID_SWFLASH_OPTION_PLAY, (HistoryDelCBPtr)mmi_swflash_play_screen_delete_callback);
    /* Register function with right softkey */
    SetKeyHandler(mmi_swflash_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_swflash_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	
    mmi_swflash_play_status(MDI_SWFLASH_PL_STATE_PLAY);
    mmi_swflash_set_interrupt_handler();
    
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_option_play2_entry_screen
* DESCRIPTION
*  the reenry function of swflash play,mainly for the re-entry of interrupted 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_swflash_option_play2_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;
    S16 error;
	MMI_ID_TYPE string_id;
    mmi_event_notify_enum popup_type;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SWFLASH_APP_ENTRY_PLAY2);
    ReadValue(NVRAM_SWFLASH_VOLUME, &g_swflash_cntx.volume, DS_BYTE, &error);
    mdi_swflash_set_is_from_player(MMI_TRUE);
    /* stop lcd sleep */
    TurnOnBacklight(0);
    /* stop LED patten */
    StopLEDPatternBackGround();
    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
    
    EntryNewScreen(SCR_ID_SWFLASH_OPTION_PLAY, mmi_swflash_option_play_exit_screen, NULL, NULL);
    
    /*BT control phone sound*/
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(APP_SWFLASH, MDI_AUD_VOL_LEVEL_NORMAL/*7 level volume*/, mmi_swflash_hfp_volume_callback);
#endif /* __BT_SPK_VOL_CONTROL__ */
	
    gdi_layer_lock_frame_buffer();          /*wait for decode ready*/
	
	
    ShowCategory227Screen(
        (PU8) GetString(STR_ID_SWFLASH_PLAYBACK),
        IMG_ID_SWFLASH_APP2,
        STR_GLOBAL_PLAY,
        0,
        STR_GLOBAL_BACK,
        0,
        mmi_swflash_wivg_render,
		mmi_swflash_pen_event
		);
	
    /* pause sound */
    mdi_audio_suspend_background_play();
    mdi_switch_device_ownership(MOD_MMI, MDI_DEVICE_AUDIO | MDI_DEVICE_CAMER | MDI_DEVICE_VIDEO);
    if (g_swflash_cntx.volume == 0)
    {
        mdi_audio_set_mute(MDI_VOLUME_MEDIA, TRUE);
    }
    else
    {
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_swflash_cntx.volume);
    }
	
    /* create swflash layer on layer 1 */
    gdi_layer_multi_layer_enable();
    ASSERT(g_swflash_cntx.swflash_play_layer == GDI_LAYER_EMPTY_HANDLE);
    
    g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
    gdi_layer_create(
        g_swflash_cntx.layer_offset_x,
        g_swflash_cntx.layer_offset_y,
        g_swflash_cntx.layer_width,
        g_swflash_cntx.layer_height,
        &g_swflash_cntx.swflash_play_layer);
    gdi_layer_push_and_set_active(g_swflash_cntx.swflash_play_layer);
    gdi_layer_clear_background(GDI_COLOR_BLACK);
	
    gdi_layer_pop_and_restore_active();
    gdi_layer_get_base_handle(&g_swflash_cntx.swflash_base_layer);
    gdi_layer_set_blt_layer(g_swflash_cntx.swflash_base_layer, g_swflash_cntx.swflash_play_layer, 0, 0);
	
    ret = mdi_swflash_open_file((const S8*)g_swflash_cntx.swflash_cmp_full_path, VIS_PLAYER, &wgui_swflash_info);
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        gdi_layer_unlock_frame_buffer(); 
        gdi_layer_free(g_swflash_cntx.swflash_play_layer);
        g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
		string_id = mdi_util_get_mdi_error_info(ret, &popup_type);
		mmi_display_popup((UI_string_type) GetString(string_id), popup_type);
        DeleteScreenIfPresent(SCR_ID_SWFLASH_OPTION_PLAY);
        mmi_fmgr_close_option_screen();
        return;
    }
	
    ret = mdi_swflash_play(g_swflash_cntx.swflash_play_layer, 1, 0xFF, mmi_swflash_play_callback);
#ifdef __MMI_SWFLASH_STOP_AT_THE_LAST_FRAME__
    {
        PU8 curr_layer_buferr = 0;
        
        gdi_layer_push_and_set_active(g_swflash_cntx.swflash_play_layer);
        gdi_layer_get_buffer_ptr(&curr_layer_buferr);
        if (!g_swflash_cntx.last_frame_buffer)
        {
            MMI_ASSERT(0);
        }
        memcpy(curr_layer_buferr, g_swflash_cntx.last_frame_buffer, g_swflash_cntx.layer_width*g_swflash_cntx.layer_height*2);
        gdi_layer_pop_and_restore_active();
    }
#endif
    gdi_layer_unlock_frame_buffer();          /*decode ready*/
	
    gdi_layer_blt_previous(
		g_swflash_cntx.layer_offset_x - 1,
		g_swflash_cntx.layer_offset_y - 1,
		g_swflash_cntx.layer_width+ g_swflash_cntx.layer_offset_x,
		g_swflash_cntx.layer_height+ g_swflash_cntx.layer_offset_y);
    
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        gdi_layer_free(g_swflash_cntx.swflash_play_layer);
        g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
		string_id = mdi_util_get_mdi_error_info(ret, &popup_type);
		mmi_display_popup((UI_string_type) GetString(string_id), popup_type);
        DeleteScreenIfPresent(SCR_ID_SWFLASH_OPTION_PLAY);
        mmi_fmgr_close_option_screen();
        return;
    }
	
    /*for interaction*/
    mmi_swflash_set_key_handle();
    SetDelScrnIDCallbackHandler(SCR_ID_SWFLASH_OPTION_PLAY, (HistoryDelCBPtr)mmi_swflash_play_screen_delete_callback);
    /*Register function with right softkey */
    SetKeyHandler(mmi_swflash_press_inc_volume, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_swflash_press_dec_volume, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	
    mmi_swflash_play_status(MDI_SWFLASH_PL_STATE_READY);
    mmi_swflash_set_interrupt_handler();
	
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_option_play_exit_screen
* DESCRIPTION
*  the exit function
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_swflash_option_play_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop playback */
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SWFLASH_APP_EXIT_PLAY);
	
    mdi_swflash_set_is_from_player(MMI_FALSE);
    mdi_swflash_stop();
    
#ifdef __MMI_SWFLASH_STOP_AT_THE_LAST_FRAME__
    {
        PU8 curr_layer_buferr = 0;
        
        if (g_swflash_cntx.last_frame_buffer && g_swflash_cntx.swflash_play_layer)
        {
            gdi_layer_push_and_set_active(g_swflash_cntx.swflash_play_layer);
            gdi_layer_get_buffer_ptr(&curr_layer_buferr);
            memcpy(g_swflash_cntx.last_frame_buffer, curr_layer_buferr, MMI_SWLFASH_LAST_FRAME_BUFFER_SIZE);
            gdi_layer_pop_and_restore_active();
        }
    }
#endif
	
    /* free swflash layer */
    if (g_swflash_cntx.swflash_play_layer != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_swflash_cntx.swflash_play_layer);
        g_swflash_cntx.swflash_play_layer = GDI_LAYER_EMPTY_HANDLE;
    }
	
    /*free resource*/
    mdi_swflash_close_file();
    gdi_layer_set_blt_layer(g_swflash_cntx.swflash_base_layer, 0, 0, 0);
    gdi_layer_multi_layer_disable();
	
    /* resume audio */
    mdi_switch_device_ownership(MOD_MMI, MDI_DEVICE_AUDIO | MDI_DEVICE_CAMER | MDI_DEVICE_VIDEO);
    mdi_audio_resume_background_play();
	
    TurnOffBacklight();
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
	
    /* stop LED patten */
    StartLEDPatternBackGround();
	
    GenericExitScreen(SCR_ID_SWFLASH_OPTION_PLAY, mmi_swflash_option_play2_entry_screen);
    mmi_swflash_reset_interrupt_handler();
	
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_play_status
* DESCRIPTION
*  play status change function
* PARAMETERS
*  mdi_swflash_pl_state_enum state:play state
* RETURNS
*  void
*****************************************************************************/
static void mmi_swflash_play_status(mdi_swflash_pl_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(state)
    {
	case MDI_SWFLASH_PL_STATE_READY:
		ChangeLeftSoftkey(STR_GLOBAL_PLAY, 0);
		ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
		
		if( g_swflash_cntx.srcAPP == 1)
		{
			mmi_fmgr_close_option_screen();
		}
		
		SetLeftSoftkeyFunction(mmi_swflash_option_play_play, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_swflash_exit_play, KEY_EVENT_UP);
		break;
		
	case MDI_SWFLASH_PL_STATE_PLAY:
		ChangeLeftSoftkey(STR_GLOBAL_PAUSE, 0);
		ChangeRightSoftkey(STR_GLOBAL_STOP, 0);
		
		SetLeftSoftkeyFunction(mmi_swflash_option_play_pause, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_swflash_option_play_stop, KEY_EVENT_UP);
		break;
		
	case MDI_SWFLASH_PL_STATE_PAUSE:
		ChangeLeftSoftkey(STR_GLOBAL_RESUME, 0);
		ChangeRightSoftkey(STR_GLOBAL_STOP, 0);
		
		SetLeftSoftkeyFunction(mmi_swflash_option_play_resume, KEY_EVENT_UP);
		SetRightSoftkeyFunction(mmi_swflash_option_play_stop, KEY_EVENT_UP);
		break;
	case MDI_SWFLASH_PL_STATE_NULL:
		break;
	default:
		break;
    }
	
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_option_play_play
* DESCRIPTION
*  the function of play
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_swflash_option_play_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;
	MMI_ID_TYPE string_id;
    mmi_event_notify_enum popup_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif
	
    ret = mdi_swflash_play(g_swflash_cntx.swflash_play_layer, 1, MDI_DEVICE_SPEAKER2, mmi_swflash_play_callback);
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
		string_id = mdi_util_get_mdi_error_info(ret, &popup_type);
		mmi_display_popup((UI_string_type) GetString(string_id), popup_type);
		
    }
    else
    {
        mmi_swflash_play_status(MDI_SWFLASH_PL_STATE_PLAY);
    }
    
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_option_play_pause
* DESCRIPTION
*  the function of pause
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_swflash_option_play_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;
	MMI_ID_TYPE string_id;
    mmi_event_notify_enum popup_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_swflash_pause();
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        string_id = mdi_util_get_mdi_error_info(ret, &popup_type);
		mmi_display_popup((UI_string_type) GetString(string_id), popup_type);
    }
    else
    {
        mmi_swflash_play_status(MDI_SWFLASH_PL_STATE_PAUSE);
    }
	
}



/*****************************************************************************
* FUNCTION
*  mmi_swflash_option_play_stop
* DESCRIPTION
*  the function of stop
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_swflash_option_play_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;
	MMI_ID_TYPE string_id;
    mmi_event_notify_enum popup_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mdi_swflash_stop();
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        string_id = mdi_util_get_mdi_error_info(ret, &popup_type);
		mmi_display_popup((UI_string_type) GetString(string_id), popup_type);
    }
    else
    {
		
        mmi_swflash_play_status(MDI_SWFLASH_PL_STATE_READY);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_option_play_resume
* DESCRIPTION
*  the function of resume
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_swflash_option_play_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;
	MMI_ID_TYPE string_id;
    mmi_event_notify_enum popup_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif
    ret = mdi_swflash_resume();
    if (ret != MDI_RES_SWFLASH_SUCCEED)
    {
        string_id = mdi_util_get_mdi_error_info(ret, &popup_type);
		mmi_display_popup((UI_string_type) GetString(string_id), popup_type);
    }
    else
    {
        mmi_swflash_play_status(MDI_SWFLASH_PL_STATE_PLAY);
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_swflash_play_callback
* DESCRIPTION
*  
* PARAMETERS
*  result      [IN]        
* RETURNS
*  void
*****************************************************************************/
static void mmi_swflash_play_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SWFLASH_APP_PLAY_END);
    switch(result)
    {
    case MDI_SWFLASH_PL_RES_END_OF_FILE:
        mdi_swflash_on_end();
        mmi_swflash_play_status(MDI_SWFLASH_PL_STATE_READY);
        break;
    case MDI_SWFLASH_PL_RES_DRM_END:
        break;
    default:
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_dl_continue_confirm
* DESCRIPTION
*  confirm whether to continue downloading 
* PARAMETERS
*  void
*  ret(?)      [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_swflash_dl_continue_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_display_popup_confirm(
        (UI_string_type) GetString(STR_GLOBAL_YES),
        (PU8)GetImage(IMG_GLOBAL_YES),
        (UI_string_type) GetString(STR_GLOBAL_NO),
        (PU8)GetImage(IMG_GLOBAL_NO),
        (UI_string_type) GetString(STR_ID_SWFLASH_ASK_DOWNLOAD2),
        MMI_EVENT_QUERY);
	
	
    SetLeftSoftkeyFunction(mmi_swflash_option_download, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
	
    return;
}

/*****************************************************************************
* FUNCTION
*  mmi_swflash_option_info_entry_screen
* DESCRIPTION
*  entry function of swflash info
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_swflash_option_info_entry_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT ret = MDI_RES_SWFLASH_ERR_FAILED;
	MMI_ID_TYPE string_id;
    mmi_event_notify_enum popup_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_SWFLASH_APP_ENTER_INFO);
    if(g_swflash_cntx.is_zdd == MMI_TRUE)
    {
        g_swflash_cntx.is_zdd = MMI_FALSE;
        mmi_swflash_dl_continue_confirm();
    }
    else
    {
        ret = mdi_swflash_open_file((const S8*)g_swflash_cntx.swflash_cmp_full_path, VIS_SCREEN, &wgui_swflash_info);
        if (ret == MDI_RES_SWFLASH_SUCCEED)
        {
			if(g_swflash_cntx.printable_str == NULL)
            {
                media_get_ext_buffer_cacheable(MOD_MMI, (void **)&g_swflash_cntx.printable_str, 1000);
            }
            kal_mem_set(g_swflash_cntx.printable_str, 0, 1000);
            ret = mdi_swflash_transform_info(g_swflash_cntx.printable_str);
            mdi_swflash_close_file();
            if(ret == MDI_RES_SWFLASH_SUCCEED)
            {
                EntryNewScreen(SCR_ID_SWFLASH_OPTION_INFO, mmi_swflash_option_info_exit_screen, NULL, NULL);
				
                /* 8. Display Category74 Screen */
                ShowCategory74Screen(
                    STR_ID_SWFLASH_OPTION_INFO,
                    IMG_ID_SWFLASH_APP2,
                    0,
                    0,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    (PU8)g_swflash_cntx.printable_str,
                    mmi_ucs2strlen(g_swflash_cntx.printable_str),
                    NULL);
				
                /* 9. Register function with right softkey */
                SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
                SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            }
            else
            {
                if (g_swflash_cntx.printable_str != NULL)
                {
                    media_free_ext_buffer(MOD_MMI, (void **)&g_swflash_cntx.printable_str);
                    g_swflash_cntx.printable_str = NULL;
                }
				string_id = mdi_util_get_mdi_error_info(ret, &popup_type);
	        mmi_display_popup((UI_string_type) GetString(string_id), popup_type);           
	    }
        }
        else
        {
			string_id = mdi_util_get_mdi_error_info(ret, &popup_type);
			mmi_display_popup((UI_string_type) GetString(string_id), popup_type);
		}
	}
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_option_info_exit_screen
* DESCRIPTION
*  exit function
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_swflash_option_info_exit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitScreen(SCR_ID_SWFLASH_OPTION_INFO, mmi_swflash_option_info_entry_screen);
	
    if (g_swflash_cntx.printable_str != NULL)
    {
        media_free_ext_buffer(MOD_MMI, (void **)&g_swflash_cntx.printable_str);
        g_swflash_cntx.printable_str = NULL;
    }
}



/*****************************************************************************
* FUNCTION
*  mmi_swflash_get_storage_file_path
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/

MMI_BOOL mmi_swflash_get_storage_file_path(PS8 filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret_drv;
    S8 buf[64];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret_drv = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
    if (ret_drv >= 0)
    {
        sprintf(buf, "%c:\\", (U8) ret_drv);
        mmi_asc_to_ucs2(filepath, buf);
        mmi_ucs2cat((PS8) filepath, (PS8) SWFLASH_STORAGE_FILEPATH_PHONE);
    }    
    return MMI_TRUE;
	
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_get_current_storage_file_path
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/

MMI_BOOL mmi_swflash_get_current_storage_file_path(PS8* filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *filepath = (s8*)g_swflash_cntx.swflash_cmp_full_path;
    return MMI_TRUE;    
}
/*****************************************************************************
* FUNCTION
*  mmi_swflash_enter_idle_screen_notify
* DESCRIPTION
*  notify function when return to idle screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/

void mmi_swflash_enter_idle_screen_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*nothing*/
	
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_exit_play
* DESCRIPTION
*  exit the player
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/

void mmi_swflash_exit_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_swflash_set_save_file(MMI_TRUE);
    if (g_swflash_cntx.is_nexturl_on == MMI_FALSE)
    {
		GoBackHistory();
	}
    else
    {
        mmi_swflash_start_wap_browser();
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_swflash_set_next_url
* DESCRIPTION
*  set the next url for player
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_swflash_set_next_url(MMI_BOOL flag_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_swflash_cntx.is_nexturl_on = flag_on;
}


#ifdef __BT_SPK_VOL_CONTROL__
static MMI_BOOL mmi_swflash_hfp_volume_callback(U8 volume, MMI_BOOL is_mute)
{   
    S16 error;
	
    if (volume < MAX_VOL_LEVEL && is_mute == MMI_FALSE)
    {
        g_swflash_cntx.volume = volume;
        WriteValue(NVRAM_SWFLASH_VOLUME, &volume, DS_BYTE, &error);
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, volume);
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}
#endif

#endif
#endif

