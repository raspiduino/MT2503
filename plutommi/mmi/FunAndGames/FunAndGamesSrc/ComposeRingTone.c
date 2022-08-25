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
 * ComposeRingTone.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements screen flow of Ring Tone Composer application.
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
 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**************************************************************

   FILENAME : ComposeRingTone.c

   PURPOSE     : Main functions of the Fun and Games, Compose Ring Tone application

   REMARKS     : nil

   AUTHOR      : Yogesh

   DATE     : July-28-2003

**************************************************************/
#ifndef _MMI_COMPOSERINGTONE_C
#define _MMI_COMPOSERINGTONE_C

/*  Include: MMI header file */

#include "MMI_features.h"
#if defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__)

/* RHR */
#include "MMIDataType.h"
#include "AlertScreen.h"
#include "string.h"
#include "Unicodexdcl.h"
//#include "kal_general_types.h"
#include "stdio.h"
#include "FileMgrType.h"
#include "fs_errcode.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "gui_data_types.h"
//#include "kal_public_api.h"
#include "GlobalConstants.h"
#include "drm_def.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrGProt.h"
#include "wgui_categories_list.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "MediaPlayerGProt.h"
#include "stack_msgs.h"
#include "GpioSrvGprot.h"
#include "gpiosrvgprot.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "CommonScreensResDef.h"

/* RHR */


//#include "mmi_include.h"
#include "CustDataRes.h"
#include "CustMenuRes.h"
#include "menucuigprot.h"


//#include "MainMenuDef.h"
#include "CommonScreens.h"
#include "ProtocolEvents.h"

//#include "FunAndGamesDefs.h"
//#include "FunAndGamesProts.h"
#include "ComposeRingToneEngineProts.h"
#include "ComposeRingToneTypes.h"
#include "ComposeRingToneMainScreenProts.h"
#include "ComposeRingToneEngineDefs.h"
#include "ComposeRingToneProts.h"
#include "ComposeRingToneDefs.h"
#include "mmi_rp_app_ringtonecomposer_def.h"
#include "ComposeRingToneResDef.h"
//#include "ProfileGprots.h"
//#include "PhoneBookGprot.h"
//#include "gpioInc.h"
//#include "FileManagerGProt.h"
#ifdef __MOD_SMSAL__
//#include "MessagesExDcl.h"
#endif 

#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#endif 

#include "fs_type.h"
#include "FS_Func.h"

#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "MediaAppGProt.h"
#include "IdleGprot.h"

#ifdef __MMI_AUDIO_PLAYER__
#include "AudioPlayerProt.h"
#else
#include "MediaPlayerGProt.h"
#endif/*__MMI_AUDIO_PLAYER__*/

/* it is assumed that the filemanager will always on */
//#include "FileManagerDef.h"
//#include "FileMgr.h"
//#include "FileManagerGProt.h"
#include "Filemgrcuigprot.h"
#ifdef __PLUTO_MMI_PACKAGE__
#include "mmi_rp_app_filemanager_def.h"
#endif

//#include "FileMgrResDef.h"
#include "Filemgrsrvgprot.h"

/* FMGR_Revise */
#ifdef __DRM_SUPPORT__
#include "RightsMgrGProt.h"
#endif

#include "datetimetype.h"
#include "app_datetime.h"
#include "USBDeviceGprot.h"     /* USB MS mode */

#if defined(__MMI_BACKGROUND_CALL__)
#include "UCMSrvGProt.h"
#endif

/* 
 * Global Variable
 */
mmi_id menu_gid, browse_gid;
U16 g_rngc_fmgr_explorer_id = 0;
S16 RINGCOMPOSER_PATH[SRV_FMGR_PATH_BUFFER_SIZE];
S16 RNGC_TEMP_PATH[SRV_FMGR_PATH_BUFFER_SIZE];
S16 RNGC_TEMP_FILE[SRV_FMGR_PATH_BUFFER_SIZE];

rngc_context_struct g_rngc_cntx;
extern rngc_engine_context_struct *g_rngc_eng_cntx;  
extern rngc_skin_layout_struct g_rngc_skin_layout;
extern void RngcExecEdit(void);
static mmi_ret mmi_rngc_entry_save_confirmcb(mmi_alert_result_evt_struct *evt);

/* 
 * Global Function
 */
mmi_id g_index = MENU_COMP_RINGTONE_COMP_PLAY;

/* FMGR_Revise */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __DRM_SUPPORT__
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
#endif /* __DRM_SUPPORT__ */
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  RngcCreateDir
 * DESCRIPTION
 *  Create directory for ring tone composer if not exists.
 * PARAMETERS
 *  void
 * RETURNS
 *  enum value of result
 *****************************************************************************/
S32 RngcCreateDir(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    srv_fmgr_fileinfo_struct   file_info;
    S8                      *fileBuf;
    S8                      *filepath;
    S8 file[SRV_FMGR_PATH_BUFFER_SIZE];
    S8 file_temp[SRV_FMGR_PATH_BUFFER_SIZE];
    S32 err = 0;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(RINGCOMPOSER_PATH, 0, sizeof(RINGCOMPOSER_PATH));
    filepath = (S8*)srv_fmgr_types_query_fileinfo(&file_info);
    if (filepath)
    {
        mmi_ucs2cpy((S8*) file, (S8*) filepath);
        fileBuf = (S8*)srv_fmgr_path_get_filename_ptr((WCHAR*) file);
		
        *fileBuf = '\0';
        *(fileBuf + 1) = '\0';
        mmi_ucs2cpy((S8*) RINGCOMPOSER_PATH, (S8*) file);
    }
    else 
    {
        memset(RINGCOMPOSER_PATH, 0, sizeof(RINGCOMPOSER_PATH));
        sprintf(file, "%c:\\", SRV_FMGR_PUBLIC_DRV);
		
    /* create file directory if not exists */
        mmi_asc_to_ucs2((S8*) RINGCOMPOSER_PATH, (S8*) file);
    mmi_ucs2cat((S8*) RINGCOMPOSER_PATH, (S8*) FMGR_DEFAULT_FOLDER_AUDIO);
    }

    file_handle = FS_Open((U16*) RINGCOMPOSER_PATH, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle < 0)
    {
        err = FS_CreateDir((U16*) RINGCOMPOSER_PATH);
        if (err != FS_NO_ERROR)
            return err;
    }
    else
    {
        FS_Close(file_handle);
        err = FS_NO_ERROR;
    }

    /* Creating a temp folder inside the audio folder for playing files temporarily*/
    memset(RNGC_TEMP_PATH, 0, sizeof(RNGC_TEMP_PATH));
    memset(RNGC_TEMP_FILE, 0, sizeof(RNGC_TEMP_FILE));
 /*
    sprintf(file_temp, "%c:\\", SRV_FMGR_PUBLIC_DRV);
    mmi_asc_to_ucs2((S8*) RNGC_TEMP_PATH, (S8*) file_temp);
    mmi_ucs2cat((S8*) RNGC_TEMP_PATH, (S8*) FMGR_DEFAULT_FOLDER_AUDIO);*/
    
    mmi_ucs2cpy((S8*) RNGC_TEMP_PATH, (S8*) RINGCOMPOSER_PATH);
    mmi_asc_to_ucs2((S8*) file_temp, (S8*) "Temp\\");
    mmi_ucs2cat((S8*) RNGC_TEMP_PATH, (S8*) file_temp);
    file_handle = FS_Open((U16*) RNGC_TEMP_PATH, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle < 0)
    {
        err = FS_CreateDir((U16*) RNGC_TEMP_PATH);
        FS_SetAttributes((U16*) RNGC_TEMP_PATH, FS_ATTR_DIR | FS_ATTR_HIDDEN);    
        if (err != FS_NO_ERROR)
            return err;
    }
    else
    {
        FS_Close(file_handle);
    }
    mmi_ucs2cpy((S8*) RNGC_TEMP_FILE, (S8*) RNGC_TEMP_PATH);
    mmi_asc_to_ucs2((S8*) file_temp, (S8*) "~rngc.imy");
    mmi_ucs2cat((S8*) RNGC_TEMP_FILE, (S8*) file_temp);    
    err = FS_NO_ERROR;
    return err;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_menu_cui_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler for Menu CUI
 * PARAMETERS
 *  menu_id     [IN]        Highlighted Menu ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_menu_cui_highlight_hdlr(MMI_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_menu_cui_lsk_hdlr
 * DESCRIPTION
 *  LSK handler for menu CUI
 * PARAMETERS
 *  menu_id     [IN]        Highlighted Menu ID
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_rngc_menu_cui_lsk_hdlr(MMI_ID menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID start_id, end_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined( DSP_WT_SYN ) && defined(WT20K))
    start_id = MENU_COMP_RINGTONE_GUITAR;
#else
    start_id = MENU_COMP_RINGTONE_PIANO;
#endif 
#if (defined( DSP_WT_SYN ) && (defined(WT150K) || defined(WT100K) || defined(WT70K))) || \
    (defined( DSP_WT_SYN ) && defined(WT20K))
    end_id = MENU_COMP_RINGTONE_TRUMPET;
#else 
    end_id = MENU_COMP_RINGTONE_XYLOPHONE;
#endif 
    if (menu_id >=start_id && menu_id <=end_id)
    {
        g_rngc_cntx.CurrInstr = CurrentInstrument[menu_id - start_id];
        return MMI_TRUE;
    }
    switch (menu_id)
    {
    case MENU_COMP_RINGTONE_FAST:
        g_rngc_cntx.CurrSpeed = FAST_SPEED;
        break;
    case MENU_COMP_RINGTONE_NORMAL:
        g_rngc_cntx.CurrSpeed = NORMAL_SPEED;
        break;
    case MENU_COMP_RINGTONE_SLOW:
        g_rngc_cntx.CurrSpeed = SLOW_SPEED;
        break;
#ifdef __MMI_RING_COMPOSER_STYLE__
    case MENU_COMP_RINGTONE_STYLE_CONTINUOUS:
        g_rngc_cntx.CurrStyle = CONTINUOUS_STYLE;
        break;
    case MENU_COMP_RINGTONE_STYLE_NORMAL:
        g_rngc_cntx.CurrStyle = NORMAL_STYLE;
        break;
    case MENU_COMP_RINGTONE_STYLE_STACCATO:
        g_rngc_cntx.CurrStyle = STACCATO_STYLE;
        break;
#endif /* __MMI_RING_COMPOSER_STYLE__ */
    case MENU_COMP_RINGTONE_COMP_SAVE:
	g_index = MENU_COMP_RINGTONE_COMP_PLAY;
        RngcGotoSelectedCompToneOpt(ENUM_ADD_TONE_OPT_SAVE);
        return MMI_FALSE;
    case MENU_COMP_RINGTONE_COMP_PLAY:
		g_index = MENU_COMP_RINGTONE_COMP_PLAY;
        RngcGotoSelectedCompToneOpt(ENUM_ADD_TONE_OPT_PLAY);
        return MMI_FALSE;
    default:
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_get_highlighted_menu
 * DESCRIPTION
 *  Entry first screen of composer
 * PARAMETERS
 *  parent      [IN]        Parent menu ID
 * RETURNS
 *  highlighted menu ID
 *****************************************************************************/
MMI_ID mmi_rngc_get_highlighted_menu(MMI_ID parent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID start_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (parent)
    {
    case MENU_COMP_RINGTONE_COMP_PLAY_SPEED:
		g_index = MENU_COMP_RINGTONE_COMP_PLAY_SPEED;
        return (MMI_ID)(MENU_COMP_RINGTONE_FAST + GetIndexCurrCompRingToneSpeed());
        break;
#ifdef __MMI_RING_COMPOSER_STYLE__
    case MENU_COMP_RINGTONE_COMP_PLAY_STYLE:
		g_index =MENU_COMP_RINGTONE_COMP_PLAY_STYLE;
        return (MMI_ID)(MENU_COMP_RINGTONE_STYLE_CONTINUOUS + GetIndexCurrCompRingToneStyle());
        break;
#endif 
    case MENU_COMP_RINGTONE_COMP_SEL_INST:
    #if (defined( DSP_WT_SYN ) && defined(WT20K))
        start_id = MENU_COMP_RINGTONE_GUITAR;
    #else
        start_id = MENU_COMP_RINGTONE_PIANO;
    #endif 
		g_index = MENU_COMP_RINGTONE_COMP_SEL_INST;
        return (MMI_ID)(start_id + GetCurrIndexCompRingToneInst());
        break;
	default:
		g_index = 0;
		return g_index;
		break;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_proc_hdlr
 * DESCRIPTION
 *  Entry first screen of composer
 * PARAMETERS
 *  evt         [IN]        Event
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_rngc_proc_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
	MMI_ID title_string;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_FIRST_ENTRY:
        break;
    case EVT_ID_GROUP_INACTIVE:
        if (mmi_frm_scrn_get_count(GRP_ID_RNGC_COMPOSE) == 0)
        {
            mmi_frm_group_close(GRP_ID_RNGC_COMPOSE);
        }
        break;
    case EVT_ID_GROUP_ACTIVE:
        break;
        
    case EVT_ID_GROUP_GOBACK:
        mmi_frm_group_close(GRP_ID_RNGC_COMPOSE);
        break;

    case EVT_ID_GROUP_DELETE_REQ:
        break;
        
    case EVT_ID_GROUP_DEINIT:
        g_index = 0;
        mmi_frm_group_close(GRP_ID_RNGC_COMPOSE);
        break;
        
    case EVT_ID_GROUP_FOCUSED:
        break;
    case EVT_ID_CUI_MENU_ITEM_HILITE:
        break;
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
			
            MMI_ID highlighted_menu;
	    if (menu_evt->parent_menu_id == MENU_COMP_RINGTONE_COMP_ADDOPT)
	    {
		cui_menu_set_currlist_flags(
                    menu_evt->sender_id,CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

		  cui_menu_set_currlist_highlighted_id(
                  menu_evt->sender_id,
                  g_index);
			
		  g_index = MENU_COMP_RINGTONE_COMP_PLAY;

	     }
            highlighted_menu = mmi_rngc_get_highlighted_menu(menu_evt->parent_menu_id);
            if (highlighted_menu != 0 && (mmi_frm_is_in_backward_scenario() == MMI_FALSE))
            {
                cui_menu_set_currlist_highlighted_id(
                    menu_evt->sender_id,
                    highlighted_menu);
            }
        }
		
		switch(menu_evt->parent_menu_id)
		{

			case MENU_COMP_RINGTONE_COMP_PLAY_SPEED:
				title_string = STR_COMP_RINGTONE_PLAY_SPEED;
				break;
			#ifdef __MMI_RING_COMPOSER_STYLE__
			case MENU_COMP_RINGTONE_COMP_PLAY_STYLE:
				title_string = STR_COMP_RINGTONE_PLAY_STYLE;
				break;
                        #endif 
			case MENU_COMP_RINGTONE_COMP_SEL_INST:
				title_string = STR_COMP_RINGTONE_SEL_INST;
				break;
			default:
				title_string = 0;
     	                  	break;
		}
		if (title_string)
		{
			cui_menu_set_currlist_title(menu_evt->sender_id,(WCHAR *)GetString(title_string),(UI_image_type)get_image(GetRootTitleIcon(MENU3103_RINGTONE_COMPOSER)));
		}

		  
        break;
    case EVT_ID_CUI_MENU_ITEM_SELECT:
        if (mmi_rngc_menu_cui_lsk_hdlr(menu_evt->highlighted_menu_id))
        {
            //mmi_frm_scrn_close_active_id();
             cui_menu_close(menu_evt->sender_id);
	     EntryRngcCompToneOptList();

           
        }
        break;
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(menu_evt->sender_id);
        break;  
        
    case EVT_ID_CUI_FOLDER_BROWSER_ON_ENTRY:
        break;
    
    case EVT_ID_CUI_FOLDER_BROWSER_ON_EXIT:
        break;
    case EVT_ID_CUI_FOLDER_BROWSER_ON_QUIT:
        cui_folder_browser_close(g_rngc_fmgr_explorer_id);
        break;

    case EVT_ID_CUI_FOLDER_BROWSER_ON_EMPTY:
        RngcExecAdd();
        break;

    case EVT_ID_CUI_FOLDER_BROWSER_ON_MENU:
        {
            cui_folder_browser_on_menu_event_struct *option_menu_evt = (cui_folder_browser_on_menu_event_struct *)menu_evt;

            switch(option_menu_evt->menuitem_id)
            {
                case MENU_COMP_RINGTONE_COMP_SELEDIT:
                    RngcExecEdit();
                    return MMI_RET_DONT_CARE;

                case MENU_COMP_RINGTONE_COMP_SELADD:
                    RngcExecAdd();
                    return MMI_RET_DONT_CARE;

                default:
                    break;
            }
            
            return MMI_RET_OK;
        }
        


    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_fmgr_edit_imy
 * DESCRIPTION
 *  Get file info from file manager
 * PARAMETERS
 *  buffer      [IN]     
 * RETURNS
 *  enum value of result(IN)
 *****************************************************************************/
/* void mmi_rngc_fmgr_edit_imy(mmi_fmgr_instance_struct *instance, srv_fmgr_fileinfo_struct* file_info) */
void mmi_rngc_fmgr_edit_imy(S8* buffer, S8* filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 filenameExt[16];
    U8 FileLen = 0;
    U8 ExtLen = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    InitRingToneComposer();
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_RNGC_COMPOSE, mmi_rngc_proc_hdlr, NULL);
    mmi_frm_group_enter(GRP_ID_RNGC_COMPOSE, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_ucs2cpy(g_rngc_cntx.FileName, (S8*) buffer);
     /* remove file extension */
    FileLen = (U8) mmi_ucs2strlen((S8*) g_rngc_cntx.FileName);
    ExtLen = strlen((S8*) MELODY_FILE_EXTENSION);
    mmi_ucs2_to_asc((S8*) filenameExt, (S8*) & g_rngc_cntx.FileName[(FileLen - ExtLen) * ENCODING_LENGTH]);

    if (!StrnCmp((S8*) filenameExt, (S8*) MELODY_FILE_EXTENSION, ExtLen))
    {
        g_rngc_cntx.FileName[(FileLen - ExtLen) * ENCODING_LENGTH] = '\0';
        g_rngc_cntx.FileName[((FileLen - ExtLen) * ENCODING_LENGTH)+1] = '\0';
    }
    g_rngc_cntx.CurrEditState = ENUM_COMP_EDIT;
    EditMelody((U8*) filepath);
}


/*****************************************************************************
 * FUNCTION
 *  RngcGetFileInfo
 * DESCRIPTION
 *  Get file info from file manager
 * PARAMETERS
 *  void
 * RETURNS
 *  enum value of result(IN)
 *****************************************************************************/
void RngcGetFileInfo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    srv_fmgr_fileinfo_struct file_info;
    S8 filenameExt[16];
    U8 FileLen = 0;
    U8 ExtLen = 0;
    WCHAR *filepath = NULL;
    WCHAR buffer[SRV_FMGR_PATH_BUFFER_SIZE];
    WCHAR *temp_filename;
    S32 index = 0;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* FMGR_Revise */
    
       
    
    index = cui_folder_browser_get_highlight_index(browse_gid);

    cui_folder_browser_get_filepath(browse_gid,index,&file_info,buffer,sizeof(buffer));
    
          
    temp_filename =(WCHAR *)srv_fmgr_path_get_filename_ptr((WCHAR *)buffer);

    if (!buffer)
    {
        ASSERT(0);
    }

    
    mmi_ucs2cpy(g_rngc_cntx.FileName, (S8*)temp_filename);
    /* remove file extension */
    FileLen = (U8) mmi_ucs2strlen((S8*) g_rngc_cntx.FileName);
    ExtLen = strlen((S8*) MELODY_FILE_EXTENSION);
    mmi_ucs2_to_asc((S8*) filenameExt, (S8*) & g_rngc_cntx.FileName[(FileLen - ExtLen) * ENCODING_LENGTH]);

    if (!StrnCmp((S8*) filenameExt, (S8*) MELODY_FILE_EXTENSION, ExtLen))
    {
        g_rngc_cntx.FileName[(FileLen - ExtLen) * ENCODING_LENGTH] = '\0';
        g_rngc_cntx.FileName[((FileLen - ExtLen) * ENCODING_LENGTH)+1] = '\0';
    }
}


/*****************************************************************************
 * FUNCTION
 *  RngcExecPlay
 * DESCRIPTION
 *  Prepare temporary file and entry play screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcExecPlay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //RngcGetFileInfo();
    //mmi_ucs2cpy((S8*) g_rngc_cntx.PrevFileName, (S8*) g_rngc_cntx.FileName);
    //EntryRngcPlayTone();
}


/*****************************************************************************
 * FUNCTION
 *  HighlightRngcPlay
 * DESCRIPTION
 *  Highlight handler of play option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightRngcPlay(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(RngcExecPlay, KEY_EVENT_UP);
    
}
/*TODO: DELETE IT*/
void HighlightRngcGenericOptHdlr(S32 index)
{
}


/*****************************************************************************
 * FUNCTION
 *  RngcExecEdit
 * DESCRIPTION
 *  Execute Edit command
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcExecEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 FileNameBuff[SRV_FMGR_PATH_BUFFER_SIZE];
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RngcGetFileInfo();
    g_rngc_cntx.CurrEditState = ENUM_COMP_EDIT;
    GenerateCompleteComposeFileName((PS8) g_rngc_cntx.FileName, (PS8) FileNameBuff);
#ifdef __DRM_SUPPORT__
    if (DRM_METHOD_NONE != DRM_get_object_method(0, (PU16)FileNameBuff))
    {
        mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DRM_PROHIBITED)), MMI_EVENT_FAILURE, GRP_ID_RNGC_COMPOSE, NULL);
        return;
    }
#endif /* __DRM_SUPPORT__ */ 
    EditMelody((U8*) FileNameBuff);
}


/*****************************************************************************
 * FUNCTION
 *  HighlightRngcEdit
 * DESCRIPTION
 *  Highlight handler of Edit option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightRngcEdit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(RngcExecEdit, KEY_EVENT_UP);
    
}


/*****************************************************************************
 * FUNCTION
 *  RngcExecAdd
 * DESCRIPTION
 *  Execute Add command
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcExecAdd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_group_is_present(GRP_ID_RNGC_COMPOSE))
    {
    mmi_frm_group_create(mmi_frm_group_get_active_id(), GRP_ID_RNGC_COMPOSE, mmi_rngc_proc_hdlr, NULL);
    mmi_frm_group_enter(GRP_ID_RNGC_COMPOSE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    g_rngc_cntx.CurrEditState = ENUM_COMP_ADD;
    FreeMemory();
    EntryRngcComposerEngine();
}


/*****************************************************************************
 * FUNCTION
 *  HighlightRngcAdd
 * DESCRIPTION
 *  Highlight handler of Add option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightRngcAdd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(RngcExecAdd, KEY_EVENT_UP);
    
}

/* FMGR_Revise */
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
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
*  mmi_rngc_opt_hint_select_speed
* DESCRIPTION
*  effect setting hint handler
* PARAMETERS
*  index       [IN]        Index of selected item
* RETURNS
*  void
*****************************************************************************/
void mmi_rngc_opt_hint_select_speed(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    if (g_rngc_cntx.CurrSpeed >= FAST_SPEED)
        str_id = STR_COMP_RINGTONE_FAST;
    else if (g_rngc_cntx.CurrSpeed >= NORMAL_SPEED)
        str_id = STR_COMP_RINGTONE_NORMAL;
    else if (g_rngc_cntx.CurrSpeed >= SLOW_SPEED)
        str_id = STR_COMP_RINGTONE_SLOW;
    else 
        str_id = STR_COMP_RINGTONE_SLOW;
    
    mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString((U16) (str_id)));
}


#ifdef __MMI_RING_COMPOSER_STYLE__
/*****************************************************************************
* FUNCTION
*  mmi_rngc_opt_hint_select_style
* DESCRIPTION
*  effect setting hint handler
* PARAMETERS
*  index       [IN]        Index of selected item
* RETURNS
*  void
*****************************************************************************/
void mmi_rngc_opt_hint_select_style(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    switch (g_rngc_cntx.CurrStyle)
    {
    case CONTINUOUS_STYLE:
        str_id = STR_COMP_RINGTONE_STYLE_CONTINUOUS;
        break;
    case NORMAL_STYLE:
        str_id = STR_COMP_RINGTONE_STYLE_NORMAL;
        break;
    case STACCATO_STYLE:
        str_id = STR_COMP_RINGTONE_STYLE_STACCATO;
        break;
    default:
        str_id = STR_COMP_RINGTONE_STYLE_NORMAL;
    }
    
    mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString((U16) (str_id)));
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_rngc_opt_hint_select_inst
* DESCRIPTION
*  effect setting hint handler
* PARAMETERS
*  index       [IN]        Index of selected item
* RETURNS
*  void
*****************************************************************************/
void mmi_rngc_opt_hint_select_inst(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    
    mmi_ucs2cpy((S8*) hintData[index], (S8*) GetString((U16) (GetInstrumentString(g_rngc_cntx.CurrInstr))));
}


/*****************************************************************************
 * FUNCTION
 *  InitRingToneComposer
 * DESCRIPTION
 *  1. initialize handler
 *  2. reset global variables
 *  3. read data from NVRAM
 *  4. Sync files and file indices
 * PARAMETERS
 *  void
 * RETURNS
 *  enum value of result(IN)
 *****************************************************************************/
void InitRingToneComposer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_result = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reset global context */
    memset(&g_rngc_cntx, 0, sizeof(g_rngc_cntx));
    g_rngc_cntx.CurrInstr = RNGC_DEFAULT_FIRST_INSTR;
    g_rngc_cntx.CurrSpeed = NORMAL_SPEED;
    /*
     * sync file system,
     * create dir if not exists.
     */
    fs_result = RngcCreateDir();
    /*if (fs_result < FS_NO_ERROR)
    {
        mmi_popup_display((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(fs_result))), MMI_EVENT_FAILURE, NULL);
        return;
    }*/
}


/*****************************************************************************
 * FUNCTION
 *  HighlightRngcMenu
 * DESCRIPTION
 *  Highlight handler for Ring Tone Composer menu in FunAndGames
 * PARAMETERS
 *  void
 * RETURNS
 *  enum value of result(IN)
 *****************************************************************************/
void HighlightRngcMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryRngcApp, KEY_EVENT_UP);
}

/* FMGR_Revise */
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
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_get_sg_id
 * DESCRIPTION
 *  Entry first screen of composer
 * PARAMETERS
 *  evt         [IN]        Event
 * RETURNS
 *  void
 *****************************************************************************/
mmi_id mmi_rngc_get_sg_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id ID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ID = mmi_frm_group_get_active_id();
    return ID;
}


/*****************************************************************************
 * FUNCTION
 *  EntryRngcApp
 * DESCRIPTION
 *  Entry first screen of composer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_entry_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  


    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_RNGC_COMPOSE, mmi_rngc_proc_hdlr, NULL);
    mmi_frm_group_enter(GRP_ID_RNGC_COMPOSE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_IMY);
    
    /* FMGR_Revise */
    {
        mmi_fmgr_browse_setting_struct setting;

        mmi_fmgr_browse_init_setting(&setting);
        setting.display_type = FMGR_DISPLAY_TYPE_BANNER_LIST;
        setting.option_menu_id = MENU_COMP_RINGTONE_COMP_SELMENU_1;
        setting.empty_opt_menu_id = 0;
        setting.empty_lsk_hdlr = RngcExecAdd;
        setting.empty_lsk_string_id = STR_GLOBAL_ADD;

        if ((browse_gid = cui_folder_browser_create(GRP_ID_RNGC_COMPOSE,(WCHAR *)RINGCOMPOSER_PATH,&filter,0,
            setting.option_menu_id,setting.empty_opt_menu_id)) != GRP_ID_INVALID)
        {
            g_rngc_fmgr_explorer_id = browse_gid;

            if(setting.empty_lsk_string_id)
            {
		cui_folder_browser_set_title(browse_gid,STR_MENU3103_RINGTONE_COMPOSER,GetRootTitleIcon(MENU3103_RINGTONE_COMPOSER));
                cui_folder_browser_set_empty_lsk(browse_gid, setting.empty_lsk_string_id, 0);
            }
            cui_folder_browser_run(browse_gid);
            
        }
        /*
        if (mmi_fmgr_browse_path(APP_RINGTONECOMPOSER, 0, filter, (S8*) RINGCOMPOSER_PATH, &setting))
        {
            g_rngc_fmgr_explorer_id = GetActiveScreenId();
        }*/
    }
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
}


/*****************************************************************************
 * FUNCTION
 *  EntryRngcApp
 * DESCRIPTION
 *  Entry first screen of composer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRngcApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((PS8) L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    /* init code. */
    /* reset global context */
    InitRingToneComposer();
    mmi_rngc_entry_app();
}


/* FMGR_Revise */
/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_option_enabler
 * DESCRIPTION
 *  Enables the options of forward
 * PARAMETERS
 *  menu_id         [IN]        
 *  fileinfo        [IN]        
 *  nIndex(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_option_enabler(U16 menu_id, const srv_fmgr_fileinfo_struct* fileinfo)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8* filepath;
    S32 drm_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filepath = (S8*)srv_fmgr_types_query_fileinfo(NULL);
    drm_flag = mmi_rmgr_check_forward((U16*)filepath);
#ifdef __PLUTO_MMI_PACKAGE__    
    if(drm_flag & MMI_RMGR_USAGE_SEND == 0)
        mmi_frm_hide_menu_item(MENU_ID_FMGR_GEN_OPTION_FORWARD_SEND);
    if(drm_flag & MMI_RMGR_USAGE_SET == 0)
        mmi_frm_hide_menu_item(MENU_ID_FMGR_GEN_OPTION_FORWARD_USE);
#endif    
#endif /* __DRM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  HighlightRngcCompTone
 * DESCRIPTION
 *  Highlight handler when selecting a composed tone
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightRngcCompTone(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rngc_cntx.CurrTone = (U8) nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  EntryRngcMainMenuOptList
 * DESCRIPTION
 *  Display available options for a composed tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRngcMainMenuOptList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    U16 RingToneOptionList[ENUM_COMP_OPT_TOTAL];
    U16 noOfChildren;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
        mmi_frm_group_get_active_id(),
        SCR_COMPOSE_RINGTONE_OPTION,
        NULL,
        EntryRngcMainMenuOptList,
        MMI_FRM_FULL_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    GetSequenceStringIds(MENU_COMP_RINGTONE_COMP_SELMENU_1, RingToneOptionList);
    SetParentHandler(MENU_COMP_RINGTONE_COMP_SELMENU_1);
    noOfChildren = GetNumOfChild(MENU_COMP_RINGTONE_COMP_SELMENU_1);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU3103_RINGTONE_COMPOSER),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        noOfChildren,
        RingToneOptionList,
        (PU16) gIndexIconsImageList,
        1,
        0,
        guiBuffer);

    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  SetRingToneFilenameBuf
 * DESCRIPTION
 *  Fill filename buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void SetRingToneFilenameBuf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_rngc_cntx.CurrEditState)
    {
        case ENUM_COMP_ADD: /* insert default filename */
        {
            MYTIME TodayDateTime;
            S8 dummyString[RNGC_FILE_LEN];  /* RMMDDHHMM */
            S8 fullName[RNGC_FILE_LEN];
            S8 extName[RNGC_FILE_LEN];
            S32 i;

            mmi_asc_to_ucs2(extName, MELODY_FILE_EXTENSION);
            GetDateTime(&TodayDateTime);
            sprintf(
                dummyString,
                "R%02d%02d%02d%02da",
                TodayDateTime.nMonth,
                TodayDateTime.nDay,
                TodayDateTime.nHour,
                TodayDateTime.nMin);

            for (i = 0; i < RNGC_MAX_ENG_CHAR; i++)
            {
                mmi_asc_to_ucs2(fullName, dummyString);

                if (!IsCompToneExisted(fullName))
                {
                    break;
                }

                dummyString[9] = 'a' + i + 1;
            }

            mmi_asc_to_ucs2(g_rngc_cntx.FileName, dummyString);
            break;
        }
        default:
            break;
    }
}

/* FMGR_Revise */
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
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  CompRingTonePlayFinishInd
 * DESCRIPTION
 *  Message handler of PRT_EQ_PLAY_AUDIO_FINISH_IND, go back to previous screen
 * PARAMETERS
 *  result      [IN]        
 *  info(?)     [IN]        Local paramater of PRT_EQ_PLAY_AUDIO_FINISH_IND message(?)
 * RETURNS
 *  void
 *****************************************************************************/
void CompRingTonePlayFinishInd(mdi_result result)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_cntx.IsSelfStop == FALSE && result == MDI_AUDIO_TERMINATED)
    {
        g_rngc_cntx.IsTonePlaying = FALSE;
        GoBackHistory();
    }
    else if (result != MDI_AUDIO_SUCCESS && result != MDI_AUDIO_TERMINATED)
    {
        GoBackHistory();
    }
#endif /* __MTK_TARGET__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  RngcStopToneAndGoBackHistory
 * DESCRIPTION
 *  Stop iMelody and go back to previous screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcStopToneAndGoBackHistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rngc_cntx.IsSelfStop = TRUE;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  RngcStopToneAndGoToIdle
 * DESCRIPTION
 *  Stop iMelody and go to IDLE screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcStopToneAndGoToIdle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rngc_cntx.IsSelfStop = TRUE;
    mmi_idle_display();
}


/*****************************************************************************
 * FUNCTION
 *  RngcPlayToneCallBack
 * DESCRIPTION
 *  1. Call back function when play finished.
 *  2. delete temporary file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcPlayToneCallBack(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 fileBuf[RNGC_FILE_LEN + 80]; /* for path name */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) fileBuf, (S8*) RNGC_TEMP_FILE);
    FS_Delete((U16*) fileBuf);
}


/*****************************************************************************
 * FUNCTION
 *  EntryRngcPlayTone
 * DESCRIPTION
 *  1. Display playing screen.
 *  2. Stop LED pattern.
 *  3. Play iMedloy file by name and file id.
 *  4. Set playing flag.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRngcPlayTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *fileBuf = (S8*)OslMalloc(RNGC_FILE_LEN + 80); /* for path name */
    S8 *fileBuf1 = (S8*)OslMalloc(RNGC_FILE_LEN + 80); /* for path name */
    S8 file_temp[SRV_FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*) fileBuf, (S8*) RNGC_TEMP_FILE);

    mmi_ucs2cpy((S8*) fileBuf1, (S8*) g_rngc_cntx.FileName);
    mmi_asc_to_ucs2((S8*) file_temp, (S8*) ".imy");
    mmi_ucs2cat((S8*) fileBuf1, (S8*) file_temp);    

    mmi_media_app_play_audio_with_title(fileBuf,RngcPlayToneCallBack,GetRootTitleIcon(MENU3103_RINGTONE_COMPOSER), (UI_string_type)fileBuf1);
    OslMfree(fileBuf);
    OslMfree(fileBuf1);
}


/*****************************************************************************
 * FUNCTION
 *  ExitRngcPlayTone
 * DESCRIPTION
 *  Exit handler of EntryRngcPlayTone
 *  1. Stop playing file.
 *  2. Reset IsTonePlaying flag.
 *  3. Restore LED pattern.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitRngcPlayTone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 fileBuf[RNGC_FILE_LEN];  /* for path name */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(PRT_EQ_PLAY_AUDIO_FINISH_IND);

    /* stop playing file */
    if (g_rngc_cntx.IsTonePlaying == TRUE)
    {
        mdi_audio_stop_file();
    }

    /* reset flag */
    g_rngc_cntx.IsTonePlaying = FALSE;

    mmi_asc_to_ucs2((S8*) fileBuf, (S8*) RNGC_TEMP_FILE);
    FS_Delete((U16*) fileBuf);

    /* restore LED pattern */
    srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_START);
}
/*****************************************************************************
 * FUNCTION
 *  RngcComposerLSKUpHandler
 * DESCRIPTION
 *  Display available options when composing a rnig tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcComposerLSKUpHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     mmi_rngc_redraw_LSK(0);
    EntryRngcCompToneOptList();
}
/*****************************************************************************
 * FUNCTION
 *  EntryRngcCompToneOptList
 * DESCRIPTION
 *  Display available options when composing a rnig tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryRngcCompToneOptList(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop multitap timer of tone editor screen */

	if (mmi_frm_scrn_get_active_id() != SCR_COMPOSER_ENGINE)
	{
		return;
	}



    StopTimer(NOTE_MULTITAP_TIMER);

    menu_gid = cui_menu_create(
        GRP_ID_RNGC_COMPOSE,
        CUI_MENU_SRC_TYPE_RESOURCE,
        CUI_MENU_TYPE_OPTION,
        MENU_COMP_RINGTONE_COMP_ADDOPT,
        MMI_FALSE,
        NULL);

    cui_menu_set_default_title(
        menu_gid,
        get_string(STR_GLOBAL_OPTIONS),
        get_image(GetRootTitleIcon(MENU3103_RINGTONE_COMPOSER)));
    cui_menu_set_default_left_softkey(
        menu_gid,
        get_string(STR_GLOBAL_SELECT));
    cui_menu_set_default_right_softkey(
        menu_gid,
        get_string(STR_GLOBAL_BACK));
    cui_menu_run(menu_gid);

}


/*****************************************************************************
 * FUNCTION
 *  HighlightRngcCompToneOpt
 * DESCRIPTION
 *  Highlight handler of EntryRngcCompToneOptList
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void HighlightRngcCompToneOpt(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


void mmi_rngc_save_melody(void)
{
    S32 err = 0;

    switch (g_rngc_cntx.CurrEditState)
    {
        case ENUM_COMP_ADD:
        case ENUM_COMP_EDIT:
        {
            err = GenerateMelodyFile((S8*) g_rngc_cntx.FileName);
            break;
        }

        default:
            break;
    }
    
    if (err != RC_SUCCESS)
    {
		
        //Not enough memory
        mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(err))), MMI_EVENT_FAILURE, GRP_ID_RNGC_COMPOSE, NULL);
        DeleteNScrId(SCR_COMPOSER_ENGINE);
        if(IsScreenPresent(g_rngc_fmgr_explorer_id))
            DeleteUptoScrID(g_rngc_fmgr_explorer_id);
    }
    else
    {
        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SAVED)), MMI_EVENT_SUCCESS, NULL);

       cui_menu_close(menu_gid);
       mmi_frm_scrn_close(GRP_ID_RNGC_COMPOSE, SCR_COMPOSER_ENGINE);

       
    }
}


void mmi_rngc_no_save(void)
{
    mmi_frm_scrn_close_active_id();
   
}


void mmi_rngc_entry_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type str[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(str, "%w", GetString(STR_GLOBAL_SAVE));
    mmi_ucs2cat((PS8)str, (const PS8)GetString(STR_ID_FMGR_QUESTION_MARK));
     do {
	mmi_confirm_property_struct arg;
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	arg.callback = (mmi_proc_func)mmi_rngc_entry_save_confirmcb;
	arg.parent_id = GRP_ID_RNGC_COMPOSE;
	mmi_confirm_display((WCHAR *)(str), MMI_EVENT_QUERY, &arg);
	} while(0);
  
   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_entry_save_confirmcb
 * DESCRIPTION
 *  This function is the cb save confirm
 * PARAMETERS
 *  event_structure
 * RETURNS
 *  mmi_ret_
 *****************************************************************************/
static mmi_ret mmi_rngc_entry_save_confirmcb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
           case MMI_ALERT_CNFM_YES:
              mmi_rngc_save_melody();
              break; 
           case MMI_ALERT_CNFM_NO:
              mmi_rngc_no_save();
              break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  RngcGotoSelectedCompToneOpt
 * DESCRIPTION
 *  Entry selected option when adding a tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcGotoSelectedCompToneOpt(U16 item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 FileNameBuff[SRV_FMGR_PATH_MAX_LEN * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (item)
    {
        case ENUM_ADD_TONE_OPT_PLAY:    /* Play */
            #if defined(__MMI_BACKGROUND_CALL__)
                if (srv_ucm_is_background_call())
                {
                    mmi_ucm_app_entry_error_message();
                    return;
                }
    #endif /* defined(__MMI_BACKGROUND_CALL__) */ 
            if (g_rngc_eng_cntx->TotalNotes > 0)
            {
                S32 err;
                mmi_ucs2cpy((S8*) FileNameBuff, (S8*) FMGR_TEMP_FILE_MELODY);
                err = GenerateMelodyFile((S8*) FileNameBuff);
                if (err == 0)
                {
                    EntryRngcPlayTone();
                }
                else
                {
                    mmi_popup_display((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(err))), MMI_EVENT_FAILURE, NULL);
                        
                }
            }
            else
            {
                mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_COMP_RINGTONE_EMPTYRINGTONE)), MMI_EVENT_FAILURE, NULL);
                    
            }
            break;
        case ENUM_ADD_TONE_OPT_SAVE:    /* Save File */
			
            if (g_rngc_eng_cntx->TotalNotes > 0)
            {
                SetRingToneFilenameBuf();
                mmi_rngc_entry_save();
            }
            else
            {
                mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_COMP_RINGTONE_EMPTYRINGTONE)), MMI_EVENT_FAILURE, NULL);
            }
			    
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  GetIndexCurrCompRingToneSpeed
 * DESCRIPTION
 *  Retrieve the item index of selected speed.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 : index of selected speed
 *****************************************************************************/
U8 GetIndexCurrCompRingToneSpeed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rngc_cntx.CurrSpeed >= FAST_SPEED)
        return ENUM_SPEED_FAST;
    else if (g_rngc_cntx.CurrSpeed >= NORMAL_SPEED)
        return ENUM_SPEED_NORMAL;
    else if (g_rngc_cntx.CurrSpeed >= SLOW_SPEED)
        return ENUM_SPEED_SLOW;
    else 
        return ENUM_SPEED_SLOW;    
}


#ifdef __MMI_RING_COMPOSER_STYLE__
/*****************************************************************************
 * FUNCTION
 *  GetIndexCurrCompRingToneStyle
 * DESCRIPTION
 *  Retrieve the item index of selected style.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 : index of selected style
 *****************************************************************************/
U8 GetIndexCurrCompRingToneStyle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_rngc_cntx.CurrStyle)
    {
        case CONTINUOUS_STYLE:
            return ENUM_CONTINUOUS_STYLE;
        case NORMAL_STYLE:
            return ENUM_NORMAL_STYLE;
        case STACCATO_STYLE:
            return ENUM_STACCATO_STYLE;
        default:
            return (U8) 0;
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  GetCurrIndexCompRingToneInst
 * DESCRIPTION
 *  Retrieve the index of instrument for highlight
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 : the item index of selected instrument
 *****************************************************************************/
U8 GetCurrIndexCompRingToneInst(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < ENUM_TOTAL_INSTR; i++)
    {
        if ((U8) g_rngc_cntx.CurrInstr == CurrentInstrument[i])
        {
            return i;
        }
    }
    return (U8) 0;
}


/*****************************************************************************
 * FUNCTION
 *  SetCurrCompRingToneInstrument
 * DESCRIPTION
 *  Save the instrument according to selection
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 : the item index of selected instrument(?)(?)
 *****************************************************************************/
void SetCurrCompRingToneInstrument(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_rngc_cntx.CurrInstr = CurrentInstrument[g_rngc_cntx.CurrHiliteItem];
    
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  RngcGoBackFromEditor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void RngcGoBackFromEditor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FILE_MANAGER__)
    //mmi_ucs2cpy((S8*) g_rngc_cntx.FileName, (S8*) g_rngc_cntx.PrevFileName);
#endif 
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  GetComposedIMelodyInfo
 * DESCRIPTION
 *  Retrieve file info and total number of composed tones
 * PARAMETERS
 *  downloadAudioInfo       [IN/OUT]        Pointer to get file info
 * RETURNS
 *  total number of composed tones
 *****************************************************************************/
U8 GetComposedIMelodyInfo(DYNAUDIOINFO **downloadAudioInfo)
{
#if !defined(__MMI_FILE_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *downloadAudioInfo = g_rngc_cntx.RingToneInfo;
    return g_rngc_cntx.TotalTone;
#else /* !defined(__MMI_FILE_MANAGER__) */ 
    return 0;
#endif /* !defined(__MMI_FILE_MANAGER__) */ 
}


/*****************************************************************************
 * FUNCTION
 *  GetComposedIMelodyNameInFileSystem
 * DESCRIPTION
 *  Retrieve filename from id
 * PARAMETERS
 *  AudioId     [IN]        File index
 * RETURNS
 *  pointer of filename
 *****************************************************************************/
S8 *GetComposedIMelodyNameInFileSystem(U16 AudioId)
{
#if !defined(__MMI_FILE_MANAGER__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (AudioId >= COMPOSED_RINGTONE_BASE && AudioId <= COMPOSED_RINGTONE_BASE_END)
    {
        for (i = 0; i < g_rngc_cntx.TotalTone; i++)
        {
            if (g_rngc_cntx.RingToneInfo[i].AudioId == AudioId)
            {
                return (S8*) g_rngc_cntx.RingToneInfo[i].AudioName;
            }
        }
    }
#endif /* !defined(__MMI_FILE_MANAGER__) */ 
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  IsCompToneExisted
 * DESCRIPTION
 *  To check if file already exists
 * PARAMETERS
 *  filename        [IN]        Filename without path
 * RETURNS
 *  1 == true, 0 == false
 *****************************************************************************/
U8 IsCompToneExisted(S8 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 sFileBuf[SRV_FMGR_PATH_BUFFER_SIZE];
    FS_HANDLE h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenerateCompleteComposeFileName((S8*) filename, (S8*) sFileBuf);

    h = FS_Open((U16*) sFileBuf, FS_READ_ONLY);
    if (h > 0)
    {
        FS_Close(h);
        return 1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rngc_sd_plug_out_hdlr
 * DESCRIPTION
 *  memory card plug out hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rngc_sd_plug_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_FMGR_PUBLIC_DRV == SRV_FMGR_CARD_DRV)
    {   /* Only card drive */
        mmi_frm_scrn_close(mmi_frm_group_get_active_id(), SCR_COMP_RINGTONE_SAVE_OPT);
        mmi_frm_scrn_close(mmi_frm_group_get_active_id(), SCR_COMP_RINGTONE_SAVEFILE);
        mmi_frm_scrn_close(mmi_frm_group_get_active_id(), SCR_COMP_RINGTONE_SPEED);
#ifdef __MMI_RING_COMPOSER_STYLE__
        mmi_frm_scrn_close(mmi_frm_group_get_active_id(), SCR_COMP_RINGTONE_STYLE);
#endif        
        mmi_frm_scrn_close(mmi_frm_group_get_active_id(), SCR_COMP_RINGTONE_INSTRUMENT);
        mmi_frm_scrn_close(mmi_frm_group_get_active_id(), SCR_COMP_RINGTONE_ADD_OPT);
        mmi_frm_scrn_close(mmi_frm_group_get_active_id(), SCR_COMPOSER_ENGINE);
    }
}

 mmi_ret mmi_rngcomposer_notify_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT) /* MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT */
    {
            mmi_rngc_sd_plug_out_hdlr();
             

            
    }    
    
    return MMI_RET_OK;
}

#endif /* defined(__MMI_RING_COMPOSER__) && defined(__MMI_IMELODY_SUPPORT__) */ // #if defined(__MMI_RING_COMPOSER__)
#endif /* _MMI_COMPOSERINGTONE_C */ // #ifndef _MMI_COMPOSERINGTONE_C

