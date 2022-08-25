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

/*******************************************************************************
* Filename:
* ---------
*  AudioPlayerPlayList.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player play list
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/



#include "MMI_features.h"
#ifndef __MMI_ULTRA_SLIM_AUDIO_PLAYER__
#ifdef __MMI_AUDIO_PLAYER__


#include "stdlib.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "CommonScreens.h"
#include "FileMgrType.h"
#include "FileMgrGProt.h"
#include "ProfilesSrvGProt.h"
#include "AudioPlayerDef.h"
#include "AudioPlayerType.h"
#include "AudioPlayerProt.h"
#include "AudioPlayerPlayList.h"
#include "Mmi_frm_scenario_gprot.h"
#include "FilemgrCuiGprot.h"
#include "menucuigprot.h"
#include "AudioPlayerResDef.h"
#include "Filemgrsrvgprot.h"
#include "gui_data_types.h"
#include "MMIDataType.h"
#include "mmi_rp_app_audioplayer_def.h"
#include "kal_general_types.h"
#include "fs_type.h"
#include "GlobalConstants.h"
#include "AlertScreen.h"
#include "fs_errcode.h"
#include "mmi_media_app_trc.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "string.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "fs_func.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "mmi_frm_mem_gprot.h"
#include "CustDataRes.h"
#include "wgui_categories_list.h"
#include "gui_typedef.h"
#include "mmi_frm_input_gprot.h"
#include "stack_config.h"
#include "CommonScreensResDef.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_rp_file_type_def.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "gui.h"
#include "USBSrvGprot.h"

#if defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)
#include "mmi_rp_srv_a2dp_def.h"
#endif  //defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)


#ifdef __OTG_ENABLE__
#include "usb_host_ms_if.h"
#endif 
#if 0
/* under construction !*/
/* under construction !*/
#ifdef DAF_DECODE
/* under construction !*/
#ifdef MUSICAM_DECODE    
/* under construction !*/
#endif    
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef AU_DECODE
/* under construction !*/
/* under construction !*/
#endif
#ifdef AIFF_DECODE
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifdef AMRWB_DECODE
/* under construction !*/
#endif 
#ifdef AAC_DECODE
/* under construction !*/
#endif 
#ifdef YAMAHA_MA3
/* under construction !*/
#endif 
#ifdef WMA_DECODE
/* under construction !*/
#endif 
#ifdef AAC_DECODE
/* under construction !*/
#endif 
#if defined(__MMI_PURE_AUDIO__)
/* under construction !*/
/* under construction !*/
#endif
#ifdef __DRM_V02__
/* under construction !*/
#endif
#ifdef BSAC_DECODE
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif
/* 
**  mp3 mp2 amr aac awb bsac are the four audio types which
**  requires building cache to seek, so we put them in the frist six items
**  for build cache deciding api to reference.
*/
const static UI_character_type audio_file_exts[][5] = 
{
#ifdef DAF_DECODE
    L"mp3",
#ifdef MUSICAM_DECODE    
    L"mp2",
#endif    
#endif 
    L"amr", 
#ifdef AAC_DECODE
    L"aac",
#endif 
#ifdef AMRWB_DECODE
    L"awb",
#endif 
#ifdef BSAC_DECODE
/* under construction !*/
#endif
#ifdef __DRM_V02__
    L"odf",
#endif
    L"wav",   
    L"mid",
    L"midi", 
    L"imy",
//    L"vm ",
#ifdef AIFF_DECODE
    L"aif",
    L"aiff",
    L"aifc",
#endif
#ifdef AU_DECODE
    L"au",
#endif
#ifdef SND_DECODE
    L"snd",
#endif
#ifdef M4A_DECODE
    L"m4a",
#endif 
#ifdef YAMAHA_MA3
    L"mmf",
#endif 
#ifdef WMA_DECODE
    L"wma",
#endif 
#if defined(__MMI_PURE_AUDIO__)
    L"3gp",
    L"3g2",
    L"mp4",
#endif

#ifdef __RM_DEC_SUPPORT__
	L"ra",
#endif
	
#ifdef __APE_DECODE__
	L"ape",
#endif    
#ifdef __FLAC_DECODE__
    L"flac",
#endif

#if defined(__VORBIS_DECODE__) && !defined(__VORBIS_DECODE_SLIM__)
    L"OGG",
#endif
    

    L"\0"   /* end of list */
};

#if defined(MT6223) || defined(MT6223P)
const static UI_character_type audio_file_not_support_a2dp_exts[][5] = 
{
    L"AMR",
    L"\0"   /* end of list */
};
#endif


const U16 audio_file_icon_ids[] = 
{
#ifdef DAF_DECODE
    IMG_ID_AUDPLY_FILE_AUD_ICON,
#ifdef MUSICAM_DECODE
    IMG_ID_AUDPLY_FILE_AUD_ICON,
#endif
#endif
    IMG_ID_AUDPLY_FILE_AMR_ICON, 
#ifdef AAC_DECODE
    IMG_ID_AUDPLY_FILE_AAC_ICON,
#endif 
#ifdef AMRWB_DECODE
    IMG_ID_AUDPLY_FILE_AWB_ICON,
#endif
#ifdef BSAC_DECODE
/* under construction !*/
#endif
#ifdef __DRM_V02__
    IMG_ID_FMGR_ICON_FILE_TYPE_ODF,
#endif
    IMG_ID_AUDPLY_FILE_WAV_ICON,
    IMG_ID_AUDPLY_FILE_MID_ICON,
    IMG_ID_AUDPLY_FILE_MID_ICON,
    IMG_ID_AUDPLY_FILE_IMY_ICON
//    IMG_ID_AUDPLY_FILE_AUD_ICON, // for .VM
#ifdef AIFF_DECODE
    ,IMG_ID_AUDPLY_FILE_AIF_ICON
    ,IMG_ID_AUDPLY_FILE_AIF_ICON
    ,IMG_ID_AUDPLY_FILE_AIF_ICON
#endif
#ifdef AU_DECODE
    ,IMG_ID_AUDPLY_FILE_AU_ICON
#endif
#ifdef SND_DECODE
    ,IMG_ID_AUDPLY_FILE_SND_ICON
#endif
#ifdef M4A_DECODE
  , IMG_ID_AUDPLY_FILE_M4A_ICON
#endif 
#ifdef YAMAHA_MA3
  , IMG_ID_AUDPLY_FILE_MMF_ICON
#endif 
#ifdef WMA_DECODE
  , IMG_ID_AUDPLY_FILE_WMA_ICON
#endif 
#if defined(__MMI_PURE_AUDIO__)
  ,IMG_ID_AUDPLY_FILE_3GP_ICON
  ,IMG_ID_AUDPLY_FILE_3GP_ICON
  ,IMG_ID_AUDPLY_FILE_MP4_ICON
#endif

#ifdef __RM_DEC_SUPPORT__
    ,IMG_ID_AUDPLY_FILE_RA_ICON
#endif

#ifdef __APE_DECODE__
    ,IMG_ID_AUDPLY_FILE_APE_ICON
#endif
#ifdef __FLAC_DECODE__
    ,IMG_ID_AUDPLY_FILE_FLAC_ICON
#endif


#if defined(__VORBIS_DECODE__) && !defined(__VORBIS_DECODE_SLIM__)
    ,IMG_ID_AUDPLY_FILE_COMMON_ICON
#endif


};
extern U8 PhnsetGetDefEncodingType(void);
extern S16 g_audply_main_selected_button;

extern MMI_BOOL mdi_audio_is_file_seekable(void *file_name);

#define SINGLE_LIST_VARIABLES
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
typedef struct
{
	S32 remove_index;
    S32 remove_count;
    S32 offset;
    FS_HANDLE list_hdlr;
    MMI_BOOL need_reapply;
} mmi_audply_remove_cntx_struct;
static mmi_ret mmi_audply_playlist_proc(mmi_event_struct *evt);
static mmi_ret mmi_audply_option_proc(mmi_event_struct *evt);


static mmi_audply_remove_cntx_struct* remove_cntx_p = NULL;
/* for regenerate/refresh list */
MMI_BOOL need_refresh_list = MMI_FALSE;
MMI_BOOL need_reload_list = MMI_FALSE;

#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#endif

#if defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__)
/* steal using subMenuData as a buffer to move data in play list file */
extern U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
static CHAR* g_mmi_update_list_buff = (CHAR*)subMenuData;
static U32 g_mmi_update_list_buff_size = 4698;

static audply_auto_update_cache_struct cache_cntx;
static audply_auto_update_struct update_cntx;
#endif

#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */

#define MULTIPLE_LIST_VARIABLES
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
static MMI_BOOL browser_now_playing = MMI_FALSE;
static MMI_BOOL in_browser_mode = MMI_FALSE;
static U16 playlist_fwd_highlight_index = 0;
static U16 playlist_fwd_option_menu_id = 0;
#endif  /* __MMI_AUDPLY_MULTIPLE_LIST__ */

#define COMMON_VARIABLES
mmi_audply_playlist_cntx_struct list_cntx;
extern MMI_BOOL g_mmi_audply_init_done;
extern audply_struct g_audply;
extern mmi_id g_details_id;


#define mmi_audply_playlist_search_continue_req(context) \
    mmi_audply_playlist_search_continue_req_ext(context, __LINE__)

#define GENERATER_FUNCTION_PROTOTPYE
static void mmi_audply_playlist_generate(UI_string_type fullPath, int is_short);
static void mmi_audply_playlist_generate_cancel(void);
static void mmi_audply_playlist_generate_internal(void);
static void mmi_audply_playlist_generate_from_folder(UI_string_type path, MMI_BOOL is_multi_part_odf);
static S32 mmi_audply_playlist_generate_append_one(UI_string_type path, MMI_BOOL is_short);
static void mmi_audply_playlist_generate_search(void);
static void mmi_audply_playlist_generate_forwards(void);
static void mmi_audply_playlist_generate_backwards(void);

static void mmi_audply_playlist_generate_wait_screen_entry(void);
static void mmi_audply_playlist_generate_finish(void);
static void mmi_audply_playlist_generate_error_hdlr(void);
static void mmi_audply_playlist_generate_cancel_hdlr(void);
static S32 mmi_audply_playlist_generate_write_to_file(UI_string_type path, MMI_BOOL is_short);

#ifdef __DRM_V02__
static void mmi_audply_playlist_generate_search_odf(void);
static void mmi_audply_playlist_generate_search_for_drm(UI_string_type odf_path);
#endif

#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
static void mmi_audply_playlist_generate_sort_index(
            mmi_audply_playlist_index_node_struct* index, S32 low, S32 high);
static S32 mmi_audply_playlist_generate_append_one_multiple(UI_string_type path, MMI_BOOL is_short, MMI_BOOL write_back_file_immediately);
static void mmi_audply_playlist_generate_finish_multiple(void);
static void mmi_audply_playlist_generate_error_hdlr_multiple(void);
static void mmi_audply_playlist_generate_cancel_hdlr_multiple(void);
static S32 mmi_audply_playlist_generate_write_to_file_multiple(UI_string_type path, MMI_BOOL is_short);
#elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
static S32 mmi_audply_playlist_generate_append_one_single(UI_string_type path, MMI_BOOL is_short);
static void mmi_audply_playlist_generate_finish_single(void);
#ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
static void mmi_audply_playlist_generate_finish_single_one(void);
#endif
static void mmi_audply_playlist_generate_error_hdlr_single(void);
static void mmi_audply_playlist_generate_cancel_hdlr_single(void);
static S32 mmi_audply_playlist_generate_write_to_file_single(UI_string_type path, MMI_BOOL is_short);
static void mmi_audlpy_plst_fmgr_file_selector_handle(cui_file_selector_result_event_struct *file_select);
#endif


#define SINGLE_STATIC_FUNCTION_PROTOTYPE
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
static MMI_BOOL mmi_audply_playlist_check_filename_len(const UI_string_type fullfilename);
static U8 mmi_audply_playlist_get_path_single(UI_string_type fullfilename, S32 index);
static void mmi_audply_playlist_entry_playlist_option_single(void);
static void mmi_audply_playlist_exit_playlist_single(void);
static void mmi_audply_playlist_entry_playlist_single(void);
static S32 mmi_audply_playlist_get_item_async(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_audply_plst_tap_callback(mmi_tap_type_enum tap_type,S32 index);
#endif

static S32 mmi_audply_playlist_load_cache(S32 start_index);
static S32 mmi_audply_playlist_get_list(U16 *cached_num, U16 start_index);
static void mmi_audply_playlist_entry_remove_confirm(void);
static void mmi_audply_playlist_entry_remove_all_confirm(void);
static mmi_ret mmi_audply_playlist_entry_remove_all_confirm_cb(mmi_alert_result_evt_struct *evt);
static mmi_ret mmi_audply_playlist_entry_remove_confirm_cb(mmi_alert_result_evt_struct *evt);
static void mmi_audply_playlist_add_to_ring(void);
static void mmi_audply_playlist_refresh(void);
static void mmi_audply_playlist_add(void);
static void mmi_audply_playlist_initiate_play(void);
static void mmi_audply_playlist_add_file_hdlr(UI_string_type fullPath, int is_short);
#define AUTO_UPDATE_FUNCTION_PROTOTYPE
#if defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__)
static MMI_BOOL mmi_audply_update_set_cache_buff(CHAR* buffer_ptr, U32 size_limit);
static MMI_BOOL mmi_audply_update_fill_cache(FS_HANDLE fd, U32 offset);
static MMI_BOOL mmi_audply_update_backfill_cache(FS_HANDLE fd, U32 offset);
static void mmi_audply_update_rename_folder(MMI_BOOL is_folder);
static void mmi_audply_update_do_rename_folder(void);
static void mmi_audply_update_delete_folder(MMI_BOOL is_folder);
static void mmi_audply_update_do_delete_folder(void);
static U32 mmi_audply_update_does_record_in_list(const UI_string_type list_path, const CHAR* file_path);
#endif
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */

#define MULTIPLE_STATIC_FUNCTION_PROTOTYPE
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
static MMI_BOOL mmi_audply_playlist_save_last_path(UI_string_type path);
static MMI_BOOL mmi_audply_playlist_get_last_path(const UI_string_type path);
static void mmi_audply_playlist_save_last_index(S32 index);
static S32 mmi_audply_playlist_get_last_index(void);
static void mmi_audply_highlight_editor_input_method(void);
static void mmi_audply_highlight_editor_rename_playlist(void);
static void mmi_audply_highlight_editor_create_playlist(void);
static void mmi_audply_playlist_listmgr_init(void);
static void mmi_audply_playlist_listmgr_load_cache(U16 start_index);
static S32 mmi_audply_playlist_listmgr_list_all(void);
static void mmi_audply_playlist_listmgr_load_cache_internal(U16 *cached_num, U16 start_index);
static pBOOL mmi_audply_playlist_listmgr_get_item
    (S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static void mmi_audply_playlist_entry_listmgr_option(void);
static void mmi_audply_playlist_listmgr_get_path(UI_string_type path);
static void mmi_audply_playlist_listmgr_create_internal(void);
static void mmi_audply_playlist_listmgr_rename_check(void);
static void mmi_audply_get_drive_callback(CHAR driver_letter);
static void mmi_audply_playlist_listmgr_select_storage(void);
static void mmi_audply_playlist_listmgr_delete_all_confirm(void);
static void mmi_audply_playlist_listmgr_delete_all_LSK(void);
static void mmi_audply_playlist_listmgr_delete(void);
static void mmi_audply_playlist_listmgr_delete_LSK(void);
static void mmi_audply_playlist_listmgr_rename(void);
static void mmi_audply_playlist_listmgr_open(void);
static void mmi_audply_playlist_listmgr_create(void);
static void mmi_audply_playlist_option_initiate_play(void);
static void mmi_audply_playlist_option_remove(void);
static void mmi_audply_playlist_option_moveup(void);
static void mmi_audply_playlist_option_movedown(void);
static void mmi_audply_playlist_option_add(void);
static S32 mmi_audply_playlist_create(const UI_string_type path);
static S32 mmi_audply_playlist_open(const UI_string_type file_path);
static S32 mmi_audply_playlist_open_internal(const UI_string_type file_path, mmi_audply_playlist_struct* this);
static void mmi_audply_playlist_init_ui_cntx(void);
static void mmi_audply_playlist_exit_playlist_multiple(void);
static U8 mmi_audply_playlist_del_list_browser_callback(void* param);
static void mmi_audply_playlist_entry_playlist_multiple(void);
static S32 mmi_audply_playlist_load_cache(U16 start_index);
static S32 mmi_audply_playlist_get_list(U16 *cached_num, U16 start_index);

static void mmi_audply_playlist_entry_send(void);
static void mmi_audply_playlist_entry_use(void);
static void mmi_audply_playlist_entry_fwd_send_screen(void);
static void mmi_audply_playlist_entry_fwd_use_screen(void);
static void mmi_audply_playlist_fwd_screen_LSK(void);

static U8 mmi_audply_playlist_get_path_foreground(UI_string_type fullfilename, S32 index);
static U8 mmi_audply_playlist_get_path_background(UI_string_type fullfilename, S32 index);
static void mmi_audply_playlist_entry_playlist_option_multiple(void);


static S32 mmi_audply_playlist_write_back_to_file(mmi_audply_playlist_struct* list);


static void mmi_audply_entry_editor(void);
static void mmi_audply_editor_option_entry(void);
static void mmi_audply_editor_close_function(void);
static S32 mmi_audply_editor_check_name_valid(UI_string_type file_name);
#endif  /* __MMI_AUDPLY_MULTIPLE_LIST__ */

#define COMMON_STATIC_FUNCTION_PROTOTPYE
static void mmi_audply_playlist_reload_list(void);
static void mmi_audply_playlist_clear_list_browser_gui_buffer(void);
static void mmi_audply_playlist_error_hdlr_ext(void);

#define COMMON_STATIC_FUNCTION_BODY
#define COMMON_STATIC_FUNCTION_BODY
#define COMMON_STATIC_FUNCTION_BODY
#define COMMON_STATIC_FUNCTION_BODY

#ifdef AUDPLY_DEBUG
static U32 mmi_audply_get_current_time(void)
{
    kal_uint32 ticks = 0;
    kal_uint32 time = 0;
    kal_get_time(&ticks);
    time = kal_ticks_to_milli_secs(ticks);
    return time;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_reload_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_reload_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 total = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_cntx.list_ui.cache_end_index = 0;
    list_cntx.list_ui.cache_start_index = 0;
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    if (browser_now_playing)
    {
        list_cntx.list_ui.total = list_cntx.current_list.total;
        mmi_audply_playlist_get_list(&total, 0);
    }
    else
    {
        list_cntx.list_ui.total = list_cntx.browser_list.total;
        mmi_audply_playlist_get_list(&total, 0);
    }
#elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    list_cntx.list_ui.total = list_cntx.current_list.total;
    mmi_audply_playlist_get_list(&total, 0);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_clear_list_browser_gui_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_clear_list_browser_gui_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    HistoryReplace(SCR_ID_AUDPLY_LIST_BROWSER, 
        SCR_ID_AUDPLY_LIST_BROWSER, mmi_audply_playlist_entry_playlist_multiple);
    SetDelScrnIDCallbackHandler(SCR_ID_AUDPLY_LIST_BROWSER, 
                            mmi_audply_playlist_del_list_browser_callback);
#elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)

    mmi_frm_node_struct new_node_info;
    new_node_info.id = SCR_ID_AUDPLY_LIST_BROWSER;
    new_node_info.entry_proc = (mmi_proc_func)mmi_audply_playlist_entry_playlist_single;
    mmi_frm_scrn_replace (GRP_ID_AUDPLY_LIST_BROWSER, SCR_ID_AUDPLY_LIST_BROWSER, &new_node_info);
    
    /*
    HistoryReplace(SCR_ID_AUDPLY_LIST_BROWSER, 
        SCR_ID_AUDPLY_LIST_BROWSER, mmi_audply_playlist_entry_playlist_single);    
        */
#endif
}

#define SINGLE_LIST_CODE
#define SINGLE_LIST_CODE
#define SINGLE_LIST_CODE
#define SINGLE_LIST_CODE
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_need_generate_playlist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void               
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_need_generate_playlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type default_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1] = {0};
    FS_HANDLE fs_hdlr = -1;
    S32 ret = FS_NO_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAYLIST_NEED_GEN);
#ifdef __MMI_AUDPLY_WALK_PLAY__
    if (g_audply.play_style == AUDPLY_PLAY_STYLE_BY_FILE_ORDER)
        return;
#endif  //__MMI_AUDPLY_WALK_PLAY__

#ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    if (list_cntx.is_genning_playlist)
        return;
    
    //delete all the playlist
    kal_wsprintf(default_path, "%c:\\%w", (CHAR)g_audply.present_list, MMI_AUDPLY_DEFAULT_FOLDER);
    ret = FS_XDelete(
               (PU16)default_path,
               FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE,
               NULL,
               0);
    
    memset(default_path, 0, (SRV_FMGR_PATH_MAX_LEN+1) + 1);
#endif
    /* becasue the list will be initialization after refresh. */
    mmi_audply_stop_playing();  
    /* clear path and title in global context. */
    g_audply.filefullname[0] = 0;
    g_audply.title[0] = 0;
    g_audply.duration = 0;
#ifdef __MMI_SUBLCD__
    g_audply.sub_title[0] = 0;
#endif
    g_audply.seekable = MMI_FALSE;
    /* reset variables. */
    memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
    list_cntx.current_list.pick_index = -1;
    /* reset default path. check default playlist folder. compose playlist file path. */
    ret = mmi_audply_playlist_check_and_set_default_playlist_path(
                   list_cntx.current_list.path, (CHAR)g_audply.present_list);
    if (ret < FS_NO_ERROR)
    {
        /* create default playlist folder failed! */
		mmi_audply_playlist_display_popup(ret, NULL);
        return;
    }
    
#ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    memset(&(list_cntx.current_gen_list), 0, sizeof(mmi_audply_playlist_struct));
    mmi_ucs2ncpy((CHAR*)list_cntx.current_gen_list.path, (CHAR*)list_cntx.current_list.path, (SRV_FMGR_PATH_MAX_LEN+1));
    list_cntx.file_index = 0;
    list_cntx.file_num = 1;
    list_cntx.num_of_last_file = 0;
    list_cntx.is_genning_playlist = MMI_TRUE;
#endif

    /* compose refresh folder default path. */
    kal_wsprintf(default_path, "%c:\\", (CHAR)g_audply.present_list);    
#ifdef __MMI_MY_FAVORITE__
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
#endif  /* __MMI_MY_FAVORITE__ */
    mmi_ucs2cat((CHAR*)default_path, (CHAR*)MUSIC_FOLDER);

    /* check default directory. */
    fs_hdlr = FS_Open(default_path, FS_OPEN_DIR | FS_READ_ONLY);

    if (fs_hdlr < FS_NO_ERROR)
    {       
        if (fs_hdlr == FS_FAT_ALLOC_ERROR)
        {
            /* create default folder failed! */
            mmi_audply_playlist_display_popup(fs_hdlr, NULL);
            FS_Delete((PU16)list_cntx.current_list.path);
            return;
        }
        /* create default folder. */
        fs_hdlr = FS_CreateDir(default_path);
        if (FS_NO_ERROR > fs_hdlr)
        {
            /* create default folder failed! */
            if (fs_hdlr != FS_FILE_EXISTS)
            {
                mmi_audply_playlist_display_popup(fs_hdlr, NULL);
            }
            /*when FAT_ALLOC_ERROR, need to delete the file or any other FS api will fail*/
            if (fs_hdlr == FS_FAT_ALLOC_ERROR)
            {
                FS_Delete((PU16)list_cntx.current_list.path);
            }
        }
        else
        {
            /* create new playlist file. */
            fs_hdlr = FS_Open(list_cntx.current_list.path, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN);
            if (fs_hdlr < FS_NO_ERROR)
            {
                /* create new playlist file failed! */
                mmi_audply_playlist_display_popup(fs_hdlr, NULL);
                /*when FAT_ALLOC_ERROR, need to delete the file or any other FS api will fail*/
                if (fs_hdlr == FS_FAT_ALLOC_ERROR)
                {
                    FS_Delete((PU16)list_cntx.current_list.path);
                }
            }
            else
        	{
                FS_Close(fs_hdlr);
                mmi_popup_display_ext(
                    STR_GLOBAL_EMPTY, 
                    MMI_EVENT_FAILURE, 
                    NULL);
				mmi_audply_need_load_playlist();
        	}
        }
    }
    else
    {
        FS_Close(fs_hdlr);
        g_audply.successive_fail_num = 0;

        /* clear old file. */
        fs_hdlr = FS_Open(list_cntx.current_list.path, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN | FS_READ_WRITE);
        if (fs_hdlr < FS_NO_ERROR)
        {
            /* create new playlist file failed! */
			mmi_audply_playlist_display_popup(fs_hdlr, NULL);
            /*when FAT_ALLOC_ERROR, need to delete the file or any other FS api will fail*/
            if (fs_hdlr == FS_FAT_ALLOC_ERROR)
            {
                FS_Delete((PU16)list_cntx.current_list.path);
            }
        }
        else
        {
            /*  
            **  do not close file handler here, 
            **  this handle will be use by 
            **  mmi_audply_playlist_generate_from_folder().
            */
            #ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
			list_cntx.current_gen_list.fs_hdlr = fs_hdlr;
            #else
			list_cntx.current_list.fs_hdlr = fs_hdlr;
            #endif
            mmi_audply_playlist_generate_from_folder(default_path, MMI_FALSE);
             /* Check FALG*/
            if (mmi_frm_scrn_get_neighbor_id(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,MMI_FRM_NODE_AT_LATEST_FLAG) == SCR_ID_AUDPLY_LIST_BROWSER)
            {

                mmi_frm_node_struct new_node_info;
                new_node_info.id = SCR_ID_AUDPLY_LIST_BROWSER;
                new_node_info.entry_proc = (mmi_proc_func)mmi_audply_playlist_entry_playlist_single;
                mmi_frm_scrn_replace (GRP_ID_AUDPLY_LIST_BROWSER, SCR_ID_AUDPLY_LIST_BROWSER, &new_node_info);

               /* HistoryReplace(
                    SCR_ID_AUDPLY_LIST_BROWSER, 
                    SCR_ID_AUDPLY_LIST_BROWSER, 
                    mmi_audply_playlist_entry_playlist_single);*/
            }
        } 
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_need_load_playlist
 * DESCRIPTION
 *  
 * PARAMETERS      
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_need_load_playlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* becasue the list will be initialization. */
    mmi_audply_stop_playing();
    /* re-initialize list */
    mmi_audply_playlist_init(); 
	if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,MMI_FRM_NODE_ALL_FLAG) == MMI_RET_OK)
    {
        mmi_scrn_node_struct scr_node;
		//historyNode* scr_history;
    
	    if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,MMI_FRM_NODE_ALL_FLAG))
	    {
	        if (mmi_frm_scrn_get_info(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,&scr_node) == MMI_RET_OK)
	        {

            //if (GetHistoryPointer(SCR_ID_AUDPLY_LIST_BROWSER, &scr_history))
	        //{
	            if (scr_node.gui_buf)
	            {
	                OslMfree(scr_node.gui_buf);
	                scr_node.gui_buf = NULL;
	            }
                
	        }
	    }   
    }
    /* pick one and get its information then show them in main screen */
    #ifndef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    if (mmi_audply_playlist_pick_next() >= 0)
    #endif
    {
        mmi_audply_playlist_apply_picked_file();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_single_highlight_hdlr_init
 * DESCRIPTION
 *  init highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_single_highlight_hdlr_init(void)
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
 *  mmi_audply_highlight_option_refresh
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_option_refresh(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_refresh, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_option_play
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_option_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_initiate_play, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_option_details
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_option_details(void)
{
#ifdef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_entry_detail, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_option_remove
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_option_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_entry_remove_confirm, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_option_removeall
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_option_removeall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_entry_remove_all_confirm, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_option_settings
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_option_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void (*settings_entry_func)(void);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (AUDPLY_SETTING_ITEM_COUNT <= 10)
    {
        settings_entry_func = mmi_audply_entry_settings;
    }
    else
    {
        settings_entry_func = mmi_audply_entry_two_layers_settings;
    }
    SetLeftSoftkeyFunction(settings_entry_func, KEY_EVENT_UP);
   
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_option_add
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_option_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_add, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_option_add_to_ring
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_option_add_to_ring(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_add_to_ring, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}


#define SINGLE_STATIC_FUNCTION_BODY_BEGIN
#define SINGLE_STATIC_FUNCTION_BODY_BEGIN
#define SINGLE_STATIC_FUNCTION_BODY_BEGIN
#define SINGLE_STATIC_FUNCTION_BODY_BEGIN





/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_reload
 * DESCRIPTION
 *  
 * PARAMETERS  
 *  void
 * RETURNS
 *  BOOL
 *****************************************************************************/
static S32 mmi_audply_playlist_reload(void)
{
    S32 i = 0;
    S32 ret = 0, fs_ret;
    U32 read_size = 0, file_size;
    FS_HANDLE fd = -1;
    UI_character_type filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    
    /*config present play list path*/
    ret = mmi_audply_playlist_check_and_set_default_playlist_path(
                list_cntx.current_list.path, (CHAR)g_audply.present_list);  
    if (ret < FS_NO_ERROR)
    {
        return ret;
    }

	ret = FS_GetAttributes(list_cntx.current_list.path);

    if (ret < 0)
    {
		/* need create file. */
        fd = FS_Open(list_cntx.current_list.path, FS_READ_WRITE | FS_CREATE);

        if (fd < 0)
        {
			return fd;
        }
        else
        {
			FS_Close(fd);
            list_cntx.current_list.fs_hdlr = -1;
            list_cntx.current_list.total = 0;
			return 0;
        }
    }
    else
    {
	    fd = FS_Open(list_cntx.current_list.path, FS_READ_WRITE);
        fs_ret = FS_GetFileSize(fd, &file_size);
        if (fs_ret < FS_NO_ERROR)
        {
            return fs_ret;
        }
        else
        {            
            list_cntx.list_ui.total = file_size / MMI_AUDPLY_LIST_RECORD_SIZE;
        }

    	 if (fd >= 0)
    	 {
            mmi_audply_playlist_set_start(-1);
	        for (;
	             i < MMI_AUDPLY_MAX_PLAYLIST_ITEM &&
	             FS_Read(fd, path, MMI_AUDPLY_LIST_RECORD_SIZE, &read_size) >= FS_NO_ERROR;)
	        {
	            if (read_size < MMI_AUDPLY_LIST_RECORD_SIZE)
	            {
	                break;
	            }
	            
	            {
	                if (i < MMI_AUDPLY_LIST_BUFF_SIZE)
	    		    {
	                    /* load filename to play list buffer */
	                    path[EOS(read_size)] = 0;   /* make it must be in boundary */
	                    if (!mmi_audply_playlist_check_filename_len(path))
	                    {
	                        continue;
	                    }
	                    if (IS_SNAME(path))
	                    {
	                        mmi_audply_extract_filename(filename, path);
	                        mmi_chset_mixed_text_to_ucs2_str(
	                            (U8*)list_cntx.list_ui.cache[i].filename,
	                            (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
	                            (U8*)filename,
	                            g_chset_text_encoding);
	                    }
	                    else
	                    {
	                        mmi_audply_extract_filename(list_cntx.list_ui.cache[i].filename, path);
	                    }
	                }
                    else
                    {
                        break;
                    }
	                i++;
	            }
	        }
	        FS_Close(fd);

	        return list_cntx.list_ui.total;
	    }
	    else
	    {
	        return fd;
	    }
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_check_filename_len
 * DESCRIPTION
 *  check if filename is longer than we can sustain
 * PARAMETERS  
 *  fullfilename        [IN]        
 * RETURNS
 *  BOOL
 *****************************************************************************/
static MMI_BOOL mmi_audply_playlist_check_filename_len(const UI_string_type fullfilename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* ch = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ch = mmi_ucs2rchr((CHAR*)fullfilename, (U16)(L'\\'));

    if (ch == NULL)
    {
        return MMI_FALSE;
    }
    
    if (mmi_ucs2strlen((CHAR*)(ch + 2)) > SRV_FMGR_PATH_MAX_FILE_NAME_LEN)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_path_single
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fullfilename    [IN]
 *  index           [IN]
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_audply_playlist_get_path_single(UI_string_type fullfilename, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 0;
    U32 size;
    FS_HANDLE fd;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fd = FS_Open(list_cntx.current_list.path, FS_READ_ONLY);
    
    if (fd >= 0)
    {
        if (FS_Seek(fd, index * MMI_AUDPLY_LIST_RECORD_SIZE, FS_FILE_BEGIN) >= 0)
        {
            if (FS_Read(fd, fullfilename, MMI_AUDPLY_LIST_RECORD_SIZE, &size) >= FS_NO_ERROR)
            {
                if (size > 0)
                {
                    result = IS_SNAME(fullfilename) ? 2 : 1;
                    MARK_DRIVE(fullfilename);
                    fullfilename[EOS(size)] = 0;    /* make it must be in boundary */
                }
            }
        }
        FS_Close(fd);
    }

    if (!result)
    {
        fullfilename[0] = 0;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_entry_playlist_option_single
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_entry_playlist_option_single(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    U16 menu_id = 0;
    //MMI_ID cui_gid = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mmi_frm_group_is_present(GRP_ID_AUDPLY_OPTION))
    {
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
    }

    //mmi_frm_group_create(GRP_ID_AUDPLY_MAIN, GRP_ID_AUDPLY_OPTION, mmi_audply_option_proc, (void*)NULL); 
    //mmi_frm_group_enter(GRP_ID_AUDPLY_OPTION, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_create_ex(
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        GRP_ID_AUDPLY_MAIN_PRE_LIST,
    #else
        GRP_ID_AUDPLY_MAIN, 
    #endif
        GRP_ID_AUDPLY_OPTION, 
        mmi_audply_option_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_audply.in_list_screen = MMI_FALSE;
#ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    if (g_audply.list_auto_gen)
    {
        menu_id = MENU_ID_AUDPLY_OPTION_MENU_AUTO;
    }
    else
    #endif
    {
        menu_id = MENU_ID_AUDPLY_OPTION_MENU_MANUAL;
		}


    //cui_gid = cui_menu_create(
    //                        GRP_ID_AUDPLY_OPTION,
    //                        CUI_MENU_SRC_TYPE_RESOURCE,
    //                        CUI_MENU_TYPE_OPTION,
    //                        menu_id,
    //                        MMI_FALSE, NULL);
    //cui_menu_set_default_title_by_id(cui_gid,(STR_GLOBAL_OPTIONS),(GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID)));
    //cui_menu_run(cui_gid);
    cui_menu_create_and_run(
        GRP_ID_AUDPLY_OPTION, 
        CUI_MENU_SRC_TYPE_RESOURCE, 
        CUI_MENU_TYPE_OPTION, 
        menu_id, 
        MMI_FALSE, 
        NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_exit_playlist_single
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_exit_playlist_single(void)
{
    g_audply.in_list_screen = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_entry_playlist_option_single
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_entry_playlist_single(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 highlighted_item = 0;
    U8  total_drv_num;
    UI_string_type title_p = NULL;
    SRV_FMGR_DRVLIST_HANDLE drv_list;
    U8 driveletter;
    U8 *storage_str_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        GRP_ID_AUDPLY_MAIN_PRE_LIST,        
#else
        GRP_ID_AUDPLY_MAIN, 
#endif
        GRP_ID_AUDPLY_LIST_BROWSER, 
        mmi_audply_playlist_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (!mmi_frm_scrn_enter(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,mmi_audply_playlist_exit_playlist_single,mmi_audply_playlist_entry_playlist_single,MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    /* set screen state flag. */
    g_audply.in_list_screen = MMI_TRUE;

    /* title */
    /* New FMGR interface*/
    drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ALL);
    total_drv_num = srv_fmgr_drivelist_count(drv_list);
    driveletter =  g_audply.present_list;
    storage_str_p = (U8*)get_string(srv_fmgr_drv_get_string(driveletter));
    srv_fmgr_drivelist_destroy(drv_list);


    
    if (total_drv_num >1 && storage_str_p != NULL)
    {
        title_p = (UI_string_type)storage_str_p;
    }
    else
    {
        title_p = (UI_string_type)get_string(STR_ID_AUDPLY_PLAYLIST);
    }

    if (!need_refresh_list && need_reload_list) 
    {
        mmi_audply_need_load_playlist();
        need_reload_list = MMI_FALSE;
    }

    /* show category screen */
    if (mmi_audply_playlist_is_empty() ||
        need_refresh_list ||
        !mmi_audply_playlist_is_valid())
    {
        ShowCategory353Screen(
            (PU8)title_p,
            GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            NULL,
            NULL,
            NULL,
            1,
            0,
            NULL);
    }
    else
    {
        S32 total = mmi_audply_playlist_get_total();
        S32 cat_err = 0;
        /*
        **  2 cases:
        **      1. now playing list screen and enter from player screen.
        **          need set highlight on playing item.
        **      2. now playing list screen and go back from option or etc...
        **          need set back highlight on user selected before enter other screen from this screen.        
        */

        guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_AUDPLY_LIST_BROWSER, SCR_ID_AUDPLY_LIST_BROWSER);

        if (guiBuffer != NULL)
        {
            list_menu_category_history *hist = (list_menu_category_history*) guiBuffer;

            /* case 2. */
           // if (mmi_frm_scrn_get_neighbor_id(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,MMI_FRM_NODE_AT_BEGINNING_FLAG) == SCR_ID_AUDPLY_MAIN)
            {
                hist->highlighted_item = list_cntx.list_ui.highlight;
            }           
        }
        else
        {
            /* case 1. */
           // if (mmi_frm_scrn_get_neighbor_id(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,MMI_FRM_NODE_AT_BEGINNING_FLAG) == SCR_ID_AUDPLY_MAIN)
            {
                highlighted_item = mmi_audply_playlist_get_current_index();
                if (highlighted_item < 0)
                {
                    highlighted_item = 0;
                }
            }
        }
        list_cntx.list_ui.highlight = highlighted_item;

        /* register highligh handler */
        RegisterHighlightHandler(mmi_audply_playlist_ui_highlight_hdlr);
        
        wgui_cat1032_show(
            (WCHAR*) title_p,
            get_image(GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID)),
            get_string(STR_GLOBAL_OPTIONS),
            get_image(IMG_GLOBAL_OPTIONS),
            get_string(STR_GLOBAL_BACK),
            get_image(IMG_GLOBAL_BACK),
            total,
            mmi_audply_playlist_get_item_async,
            NULL,
            highlighted_item,
            0,    
            IMG_GLOBAL_L1, /* to calculate the coordinate offset of string */
            0,
            guiBuffer,
            &cat_err);
            
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
        #endif

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_audply_plst_tap_callback);
#endif

    }

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_audply_playlist_entry_playlist_option_single, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
//        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        if (!mmi_audply_playlist_is_empty())
        {
            SetCenterSoftkeyFunction(mmi_audply_playlist_initiate_play, KEY_EVENT_UP);
            
        }
        else
        {
        #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
        	if (g_audply.list_auto_gen)
            {
                SetCenterSoftkeyFunction(mmi_audply_playlist_refresh, KEY_EVENT_UP);
                
            }
            else
       #endif
            {
                SetCenterSoftkeyFunction(mmi_audply_playlist_add, KEY_EVENT_UP);
                
            }
  	

        }
    }
    

    
    if (need_refresh_list)
    {
        need_refresh_list = MMI_FALSE;
        mmi_audply_need_generate_playlist();
    }
    else if (need_reload_list) 
    {
        need_reload_list = MMI_FALSE;
        mmi_audply_need_load_playlist();
    }
}

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_plst_tap_callback(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        return;
    }

    mmi_audply_playlist_initiate_play();
    
    return;
}
#endif /*__MMI_FTE_SUPPORT__*/

static S32 mmi_audply_playlist_get_item_async(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body								                          */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_item; ++i, ++start_index)
    {
        mmi_audply_playlist_get_item(start_index, menu_data[i].item_list[0], &menu_data[i].image_list[0], 0);

        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    }
    
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [OUT]        
 *  img_buff_p          [OUT]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_audply_playlist_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_ext_index;
    UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    mmi_audply_list_item_info_struct item_info;
    S32 load_index;
    S32 current = 0;
    mmi_audply_dynamic_list_data_struct* list_ui = &(list_cntx.list_ui);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if ((item_index < list_ui->cache_start_index) ||
        (item_index >= list_ui->cache_end_index))
    {
        /* desired entry in the middle of cache */
        load_index = item_index - (MMI_AUDPLY_LIST_BUFF_SIZE / 2);

        if (load_index < 0)
        {
            load_index = 0;
        }

        if (0 > mmi_audply_playlist_load_cache(load_index))
        {
        	mmi_ucs2ncpy((CHAR*)str_buff, (CHAR*)GetString(STR_GLOBAL_LOADING), MAX_SUBMENU_CHARACTERS);
            *img_buff_p = NULL;
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
            #endif
            return MMI_TRUE;
        }
    }
    current = item_index - list_ui->cache_start_index;
    memcpy(&item_info, 
            &(list_ui->cache[current]), 
            sizeof(mmi_audply_list_item_info_struct));
    
    mmi_audply_split_filename_ext(item_info.filename, str_buff, ext);
    file_ext_index = mmi_audply_lookup_audio_file_format(ext);
#ifdef __MMI_SHOW_FILE_EXT__
#if !defined(__MMI_SHOW_DAF_FILE_EXT__) && (defined(DAF_DECODE) || defined(MUSICAM_DECODE))
    if(
#if defined(DAF_DECODE)
     file_ext_index != AUDPLY_AUDIO_FILE_TYPE_DAF
#endif
#if defined(DAF_DECODE) && defined(MUSICAM_DECODE)
    &&
#endif
#if defined(MUSICAM_DECODE)
    file_ext_index != AUDPLY_AUDIO_FILE_TYPE_MP2
#endif
     )
#endif
    {
        if (ext[0] != 0)    /* if its ext is not blank */
        {
            mmi_ucs2cat((CHAR*)str_buff, (CHAR*)L".");
            mmi_ucs2cat((CHAR*)str_buff, (CHAR*)ext);
        }
    }
#endif /* __MMI_SHOW_FILE_EXT__ */ 
    
    /* get ext icon */
#if !defined (__MMI_MAINLCD_96X64__)
    if (file_ext_index >= 0)
    {
        *img_buff_p = (PU8) GetImage(audio_file_icon_ids[file_ext_index]);
    }
    else
    {
        *img_buff_p = (PU8) GetImage(IMG_ID_AUDPLY_FILE_UNKNOWN_ICON);
    }
#endif
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
    #endif
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_option_proc
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_audply_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        
            if (menu_evt->parent_menu_id == MENU_ID_AUDPLY_OPTION_MENU_AUTO)
            {
                if (mmi_audply_playlist_is_empty())
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_PLAY,MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_ADD_TO_RING,MMI_TRUE);
#ifdef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_DETAILS, MMI_TRUE);
#endif
                }
                else
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_PLAY,MMI_FALSE);
        #ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
		         	cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_ADD_TO_RING,MMI_FALSE);
        #else
        	        cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_ADD_TO_RING,MMI_TRUE);
	    #endif
#ifdef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
		        	cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_DETAILS,MMI_FALSE);
#endif
                }


            }
            else if (menu_evt->parent_menu_id == MENU_ID_AUDPLY_OPTION_MENU_MANUAL)
            {
                if (mmi_audply_playlist_is_empty())
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_PLAY,MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_ADD_TO_RING,MMI_TRUE);
#ifdef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_DETAILS, MMI_TRUE);
#endif
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_REMOVE, MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_REMOVE_ALL, MMI_TRUE);

                }
                else
                {
                    #ifdef __MMI_AUDPLY_WALK_PLAY__
                    if (g_audply.play_style == AUDPLY_PLAY_STYLE_BY_FILE_ORDER)
                    {
                        cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_PLAY,MMI_TRUE);
                    }
                    else
                    {
                        cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_PLAY,MMI_FALSE);
                    }
                    #endif  //__MMI_AUDPLY_WALK_PLAY__
        #ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
		         	cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_ADD_TO_RING,MMI_FALSE);
        #else
        	        cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_ADD_TO_RING,MMI_TRUE);
	    #endif
#ifdef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
		        	cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_DETAILS,MMI_FALSE);
#endif
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_REMOVE,MMI_FALSE);
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_REMOVE_ALL,MMI_FALSE);
                }


            }
                
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
            cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_SETTINGS,MMI_TRUE);
        #endif
        
            break;
             
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            {
                switch(menu_evt->highlighted_menu_id)
                {
#ifdef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
                    case MENU_ID_AUDPLY_OPTION_DETAILS:
#endif
                    case MENU_ID_AUDPLY_OPTION_ADD:
                    case MENU_ID_AUDPLY_OPTION_REMOVE:
                    case MENU_ID_AUDPLY_OPTION_SETTINGS:
                    case MENU_ID_AUDPLY_OPTION_ADD_TO_RING:
                    case MENU_ID_AUDPLY_OPTION_REMOVE_ALL:
                    case MENU_ID_AUDPLY_OPTION_REFRESH:
                    case MENU_ID_AUDPLY_OPTION_PLAY :
                #ifdef __MMI_TOUCH_SCREEN__
                        wgui_reset_list_item_selected_callback();
                #endif
                        break;

                    default:
                        break;
                }
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_AUDPLY_OPTION_PLAY :
                        mmi_audply_playlist_initiate_play();
                        break;

#ifdef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
                    case MENU_ID_AUDPLY_OPTION_DETAILS:
                        mmi_audply_entry_detail();
                        break;
#endif

                    case MENU_ID_AUDPLY_OPTION_ADD:
                        mmi_audply_playlist_add();
                        break;

                    case MENU_ID_AUDPLY_OPTION_REMOVE:
                        mmi_audply_playlist_entry_remove_confirm();
                        break;
                        
                #ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
                    case MENU_ID_AUDPLY_OPTION_SETTINGS:
                        if (AUDPLY_SETTING_ITEM_COUNT <= 10)
                        {
                            mmi_audply_entry_settings();
                        }
                        else
                        {
                            mmi_audply_entry_two_layers_settings();
                        }
                        break;
                #endif
                    case MENU_ID_AUDPLY_OPTION_ADD_TO_RING:
                        mmi_audply_playlist_add_to_ring();
                        break;

                    case MENU_ID_AUDPLY_OPTION_REMOVE_ALL:
                        mmi_audply_playlist_entry_remove_all_confirm();
                        break;

                    case MENU_ID_AUDPLY_OPTION_REFRESH:
                        mmi_audply_playlist_refresh();
                        break;

                    default:
                        break;


                }
                        
           }
           break;


        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}
            
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_proc
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_audply_playlist_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct *sel_evt = (cui_file_selector_result_event_struct*)evt;
            
            
            mmi_audlpy_plst_fmgr_file_selector_handle(sel_evt);
            break;
        }

#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
        case EVT_ID_SRV_FMGR_ASYNC_DONE:
        {
            srv_fmgr_async_done_event_struct *fs_evt = (srv_fmgr_async_done_event_struct*)evt;
            mmi_audply_playlist_delete_all_rsp(fs_evt);
            break;
        }
#endif /*__MMI_AUDPLY_MULTIPLE_LIST__*/
				case EVT_ID_SCRN_DEINIT:
		    case EVT_ID_GROUP_DEINIT:
        {
			 		//	mmi_audply_playlist_generate_cancel();
            break;
        }
        default:
            break;
    
    
    }
    return MMI_RET_OK;

   
}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_load_cache
 * DESCRIPTION
 *  load play list to buffer
 * PARAMETERS      
 *  start_index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_audply_playlist_load_cache(S32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U16 cache_index = 0;
    S32 ret = FS_NO_ERROR;
    mmi_audply_dynamic_list_data_struct* list_ui = &(list_cntx.list_ui);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    /* init some value */
    list_ui->cache_start_index = start_index;

    for (i = 0; i < MMI_AUDPLY_LIST_BUFF_SIZE; i++)
    {
        list_ui->cache[i].filename[0] = 0;
        list_ui->cache[i].ext[0] = 0;
        list_ui->cache[i].file_type = 0;
        list_ui->cache[i].is_short = 0;
    }
   
    ret = mmi_audply_playlist_get_list(&cache_index, start_index);

    if (ret < 0)
    {
        /* error caught. */
        return ret;
    }
    else
    {
        list_ui->cache_start_index = start_index;
        list_ui->cache_end_index = start_index + cache_index;
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_list
 * DESCRIPTION
 *  read playlist to cache.
 * PARAMETERS
 *  cached_num      [OUT]
 *  start_index     [IN]
 * RETURNS
 *  S32     loaded item number/error code
 *****************************************************************************/
static S32 mmi_audply_playlist_get_list(U16 *cached_num, U16 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;
    U32 read_size = 0;

    UI_character_type *ucs2_buff = NULL;
    UI_character_type filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    FS_HANDLE fd = -1;
    mmi_audply_dynamic_list_data_struct* list_ui = &(list_cntx.list_ui);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    
    fd = FS_Open(list_cntx.current_list.path, FS_READ_ONLY);
    if (fd >= 0)
    {
    	ucs2_buff = (UI_character_type*) OslMalloc((MMI_AUDPLY_LIST_RECORD_SIZE + 1));
        if (FS_Seek(fd, start_index * MMI_AUDPLY_LIST_RECORD_SIZE, FS_FILE_BEGIN) >= 0)
        {
            while (count < MMI_AUDPLY_LIST_BUFF_SIZE && start_index < list_cntx.current_list.total)
            {
                FS_Read(fd, ucs2_buff, MMI_AUDPLY_LIST_RECORD_SIZE, &read_size);
                if (read_size < MMI_AUDPLY_LIST_RECORD_SIZE)
                {
                    break;
                }
                /* load filename to play list buffer */
                ucs2_buff[EOS(read_size)] = 0;   /* make it must be in boundary */
                if (!mmi_audply_playlist_check_filename_len(ucs2_buff))
                {
                    continue;
                }
                if (IS_SNAME(ucs2_buff))
                {
					CHAR* dot = NULL;
                    mmi_audply_extract_filename(filename, ucs2_buff);
                    mmi_chset_mixed_text_to_ucs2_str(
                        (U8*)list_ui->cache[count].filename,
                        (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                        (U8*)filename,
                        g_chset_text_encoding);
                    dot = mmi_ucs2rchr((CHAR*)list_ui->cache[count].filename, (U16)L'.');
                    if (dot == NULL)
                    {
                        dot = mmi_ucs2rchr((CHAR*)filename, (U16)L'.');
                        if (dot != NULL)
                        {
                            mmi_ucs2ncat((CHAR*)list_ui->cache[count].filename, (CHAR*)(dot), 4);
                        }
                    }
                }
                else
                {
                    mmi_audply_extract_filename(list_ui->cache[count].filename, ucs2_buff);
                }
                start_index++;
                count++;
            }
        }
	OslMfree(ucs2_buff);
        FS_Close(fd);
        *cached_num = count;
        return count;
    }
    else 
    {
        return fd;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_init
 * DESCRIPTION
 *  init play list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_init(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    mmi_audply_clear_play_seconds();
    mmi_audply_playlist_reset_ui_cntx();
/*
    g_audply.seekable = MMI_FALSE;
    g_audply.need_to_build_cache = MMI_FALSE;
    g_audply.title[0] = 0;
    g_audply.filefullname[0] = 0;
    */
    mmi_audply_reset_context();
    memset(list_cntx.current_list.bitset, 0, MMI_AUDPLY_MAX_BITSET_SIZE);
    list_cntx.current_list.total = 0;
    list_cntx.current_list.pick_index = -1;
    g_audply.successive_fail_num = 0;
    list_cntx.current_list.pick_count = 0;
    
    ret = mmi_audply_playlist_reload();  
    if (ret < FS_NO_ERROR)
    {
        list_cntx.list_loaded = MMI_FALSE;
        return;
    }
    list_cntx.list_loaded = MMI_TRUE;
    list_cntx.current_list.total = ret;
    mmi_audply_playlist_set_start(-1);
    
    #ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    if (!g_audply.is_reenter)
    {
        ReadValue(NVRAM_AUDPLY_PLAYLIST_FILE_NUM, &list_cntx.file_num, DS_BYTE, &error);
        ReadValue(NVRAM_AUDPLY_PLAYLIST_FILE_INDEX, &list_cntx.file_index, DS_BYTE, &error);
        ReadValue(NVRAM_AUDPLY_PLAYLIST_NUM_OF_LAST_FILE, &list_cntx.num_of_last_file, DS_BYTE, &error);
        ReadValue(NVRAM_AUDPLY_PLAYLIST_INDEX, &list_cntx.current_list.pick_index, DS_DOUBLE, &error);
        if (list_cntx.file_index > 0 && list_cntx.file_index < list_cntx.file_num)
        {
            kal_wsprintf(list_cntx.current_list.path, "%c:\\%w\\%w_%d", (CHAR)g_audply.present_list, MMI_AUDPLY_DEFAULT_FOLDER, MMI_AUDPLY_DEFAULT_LIST_NAME_PREFIX, list_cntx.file_index);
        }
        if (list_cntx.file_index == list_cntx.file_num-1)
        {
            list_cntx.current_list.total = list_cntx.num_of_last_file;
        }
    }
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_remove_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_playlist_remove_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd;
    MMI_BOOL isOK = MMI_FALSE;
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((fd = FS_Open(list->path, FS_READ_WRITE)) >= 0)
    {
        if (FS_Seek(fd, 0, FS_FILE_BEGIN) >= 0)
        {
            if (FS_Truncate(fd) == FS_NO_ERROR)
            {
                /*mmi_audply_clear_play_seconds();
//                g_audply.restorable = MMI_FALSE;
                g_audply.seekable = MMI_FALSE;                
                g_audply.filefullname[0] = 0;
                g_audply.need_to_build_cache = MMI_FALSE;
                g_audply.title[0] = 0;
                */
                mmi_audply_reset_context();
                
		g_audply.duration = 0;
                list->total = 0;
                mmi_audply_playlist_reset_ui_cntx();
                
                mmi_audply_playlist_set_start(-1);
                isOK = MMI_TRUE;
            }
        }
        FS_Close(fd);
    }

    return isOK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_remove_all_confirm_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_remove_all_confirm_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_stop_playing();
    if (mmi_audply_playlist_remove_all())
    {
        mmi_audply_playlist_reset_ui_cntx();
       

    }
    else
    {
    	mmi_popup_display_ext(
    	    STR_ID_AUDPLY_CANNOT_UPDATE_LIST_FS_FAIL, 
    	    MMI_EVENT_FAILURE, 
    	    NULL);
        mmi_frm_scrn_close_active_id();
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_remove_all_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_entry_remove_all_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
       
     do {
     	
     	mmi_confirm_property_struct arg;
     	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	//	arg.f_auto_map_empty_softkey = MMI_FALSE;
     	arg.callback = (mmi_proc_func)mmi_audply_playlist_entry_remove_all_confirm_cb;
     	mmi_confirm_display((WCHAR *)(get_string(STR_ID_AUDPLY_OPTION_REMOVE_ALL_ASK)), MMI_EVENT_QUERY, &arg);
     	
     		} while(0);  
    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_entry_remove_all_confirm_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static mmi_ret mmi_audply_playlist_entry_remove_all_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {

        case MMI_ALERT_CNFM_YES:
        	mmi_audply_playlist_remove_all_confirm_LSK();
        	break;
        	
        case MMI_ALERT_CNFM_NO:
        	mmi_frm_scrn_close_active_id();
        	break;
            
        }
    }
    return MMI_RET_OK;
}


static mmi_ret mmi_audply_playlist_remove_wait_scr_proc(mmi_event_struct *event)
{
    switch (event->evt_id)
    {
	case EVT_ID_SCRN_INACTIVE:
        {
            break;
        }
        case EVT_ID_SCRN_ACTIVE:
        {
                
        /* do not allow popup sliding for this waiting popup */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
            gui_screen_switch_effect_block(MMI_TRUE);
#endif
        
            ShowCategory66Screen(
                STR_ID_AUDPLY_TITLE,
                GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
                0,
                0,
                0,
                0,
                (U8*)GetString(STR_GLOBAL_PLEASE_WAIT),
                mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                NULL);
            mdi_audio_suspend_background_play();
            ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
            if (remove_cntx_p != NULL)
            {
                if(remove_cntx_p->list_hdlr != FS_MINIMUM_ERROR_CODE)
                {
                    FS_Close(remove_cntx_p->list_hdlr);
                }
                if (remove_cntx_p->need_reapply) // TODO: remove this statement?
                {
                    mmi_audply_playlist_apply_picked_file();
                    mmi_audply_clear_play_seconds();
                }
                         
                         
                free_ctrl_buffer(remove_cntx_p);
                remove_cntx_p = NULL;
            }
            
            mdi_audio_resume_background_play();
            break;
        }
        default:
            break;
    }
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_remove_wait_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_remove_wait_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN_REMOVE))
    {
        mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN_REMOVE);
    }

    //mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUDPLY_WAITSCREEN_REMOVE, mmi_audply_playlist_proc, (void*)NULL); 
    //mmi_frm_group_enter(GRP_ID_AUDPLY_WAITSCREEN_REMOVE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_create_ex(
        GRP_ID_ROOT, 
        GRP_ID_AUDPLY_WAITSCREEN_REMOVE, 
        mmi_audply_playlist_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

   mmi_frm_scrn_create(
        GRP_ID_AUDPLY_WAITSCREEN_REMOVE, 
        SCR_ID_AUDPLY_WAITSCREEN_REMOVE, 
        mmi_audply_playlist_remove_wait_scr_proc,   
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_remove_bitset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fd          [IN]        
 *  index       [IN]        
 * RETURNS
 * 	S32
 *****************************************************************************/
static S32 mmi_audply_playlist_remove_bitset(FS_HANDLE fd, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_size = list_cntx.current_list.total * MMI_AUDPLY_LIST_RECORD_SIZE;
	mmi_audply_playlist_struct* list = &(list_cntx.current_list);
	S32 ret = FS_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* erase the last record */
    ret = FS_Seek(fd, file_size - MMI_AUDPLY_LIST_RECORD_SIZE, FS_FILE_BEGIN);
    if (ret >= 0)
    {
    	ret = FS_Truncate(fd);
        if (ret >= FS_NO_ERROR)
        {
            /* eliminate the bit at index and left-shift the rest of bitset after index */
            S32 m = index / 8;
            S32 k = list->total / 8;
            S32 n;
            U8 CR, LSB;

            /* update pick count before we shift it */
            if (IsBitSetOn(index, list->bitset))
            {
                list->pick_count--;
            }
            for (CR = 0, LSB = 0; k > m; k--)
            {
                LSB = ((list->bitset[k] & 0x01) != 0) ? 0x80 : 0;        /* store LSB */
                list->bitset[k] = (list->bitset[k] >> 1) | CR;
                CR = LSB;
            }
            for (n = index & 0x07; n < 7; n++)
            {
                if ((list->bitset[m] & (1 << (n + 1))) != 0)
                {
                    list->bitset[m] |= (1 << n);     /* set bit */
                }
                else
                {
                    list->bitset[m] &= ~(1 << n);    /* clear bit */
                }
            }
            if (CR != 0)
            {
                list->bitset[m] |= 0x80; /* set MSB */
            }
            else
            {
                list->bitset[m] &= 0x7f; /* clear MSB */
            }

            list->total--;

            if (list->pick_index == index)
            {
                if (list->pick_index == list->total)  /* it's the tail before, but now it's out of list */
                {
                    mmi_audply_playlist_set_start(-1);   /* repick one */
                    mmi_audply_playlist_pick_next();
                }
            }
            else if (list->pick_index > index)
            {
                list->pick_index--;
            }
        }
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_remove_transit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_audply_playlist_remove_transit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type file_list_buff = (UI_string_type) subMenuData;       /* use 4698 bytes (it has 5040 bytes) */
    S32 max_buff_size = 0;
    U32 read_size = 0;
    U32 write_size = 0;
    S32 ret = FS_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(remove_cntx_p != NULL);
	max_buff_size = (MAX_SUB_MENUS * MAX_SUB_MENU_SIZE / MMI_AUDPLY_LIST_RECORD_SIZE) * MMI_AUDPLY_LIST_RECORD_SIZE;	
	do
    {
    	ret = FS_Seek(remove_cntx_p->list_hdlr, remove_cntx_p->offset + MMI_AUDPLY_LIST_RECORD_SIZE, FS_FILE_BEGIN);
		if (ret < FS_NO_ERROR)
        {
            break;
        }
        ret = FS_Read(remove_cntx_p->list_hdlr, file_list_buff, max_buff_size, &read_size);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
        ret = FS_Seek(remove_cntx_p->list_hdlr, remove_cntx_p->offset, FS_FILE_BEGIN);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
        ret = FS_Write(remove_cntx_p->list_hdlr, file_list_buff, read_size, &write_size);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
        MMI_ASSERT(read_size == write_size);
        remove_cntx_p->offset += write_size;
    } while (0);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_remove_one
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_audply_playlist_remove_one(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = FS_NO_ERROR;
    S32 count = 0;
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	MMI_ASSERT(remove_cntx_p != NULL);
	MMI_ASSERT(remove_cntx_p->remove_index < list->total);
    
	while (ret == FS_NO_ERROR && remove_cntx_p->remove_count > 0)
    {
    	ret = mmi_audply_playlist_remove_transit();
		if (ret < FS_NO_ERROR)
        {
			break;
        }
        else
        {
			remove_cntx_p->remove_count--;
            count++;
        }
    
		if (count == 19)
        {
			StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 100, mmi_audply_playlist_remove_one);
            return;
        }
    } 

	if (!(ret < FS_NO_ERROR))
    {
    	S16 error;
		
    	ret = mmi_audply_playlist_remove_bitset(remove_cntx_p->list_hdlr, remove_cntx_p->remove_index);
		g_audply.remove_process = 0;
		WriteValueSlim(NVRAM_AUDPLY_REMOVE_IN_PROCESS, &g_audply.remove_process, DS_BYTE);

		if (ret < FS_NO_ERROR)
        {
			if (mmi_frm_scrn_get_active_id() == SCR_ID_AUDPLY_WAITSCREEN_REMOVE)
			{
				mmi_audply_playlist_display_popup(ret, NULL);

                //mmi_frm_scrn_close(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN_REMOVE);
                mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN_REMOVE);
                if (mmi_frm_group_is_present(GRP_ID_AUDPLY_OPTION))
                {
                    mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
                }
                
                             
				//DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
			}
			else
			{
                
                if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN_REMOVE))
                {
                    mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN_REMOVE);
                    //DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN_REMOVE);
                }
			}
		}
        else
        {

    	    FS_Close(remove_cntx_p->list_hdlr);
            remove_cntx_p->list_hdlr = FS_MINIMUM_ERROR_CODE;
	        if (remove_cntx_p->need_reapply)
	        {
	            mmi_audply_playlist_apply_picked_file();
	            mmi_audply_clear_play_seconds();
	        }
	        mmi_audply_playlist_reload_list();

            if (mmi_frm_scrn_get_active_id() == SCR_ID_AUDPLY_WAITSCREEN_REMOVE)
            {
                //mmi_frm_scrn_close_active_id();
                //mmi_frm_scrn_close(GRP_ID_AUDPLY_WAITSCREEN_REMOVE,SCR_ID_AUDPLY_WAITSCREEN_REMOVE);
                mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN_REMOVE);
                if (mmi_frm_group_is_present(GRP_ID_AUDPLY_OPTION))
            {
                    mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
                }
                
                //GoBackToHistory(SCR_ID_AUDPLY_LIST_BROWSER);
            }
            else
            {
                if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN_REMOVE))
                {
                    mmi_frm_scrn_close(GRP_ID_AUDPLY_WAITSCREEN_REMOVE,SCR_ID_AUDPLY_WAITSCREEN_REMOVE);
                    //mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN_REMOVE);
                }
                //DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN_REMOVE);
            }
	        
        }
    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_AUDPLY_WAITSCREEN_REMOVE)
        {
		    mmi_audply_playlist_display_popup(ret, NULL);

            mmi_frm_scrn_close(GRP_ID_AUDPLY_WAITSCREEN_REMOVE,SCR_ID_AUDPLY_WAITSCREEN_REMOVE);
            //mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN_REMOVE);
            if (mmi_frm_group_is_present(GRP_ID_AUDPLY_OPTION))
            {
                mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
            }
            //DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
        }
        else
        {
            if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN_REMOVE))
            {
                mmi_frm_scrn_close(GRP_ID_AUDPLY_WAITSCREEN_REMOVE,SCR_ID_AUDPLY_WAITSCREEN_REMOVE);
               //mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN_REMOVE);
               
                
            }
            
        }
    }
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_remove_confirm_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_remove_confirm_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = FS_NO_ERROR;
    MMI_BOOL need_reApply = MMI_FALSE;
	mmi_audply_playlist_struct* list = &(list_cntx.current_list);
	S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_cntx.current_list.pick_index == list_cntx.list_ui.highlight)
    {
        mmi_audply_stop_playing();
        need_reApply = MMI_TRUE;
    }

    if (list->total <= 1)
    {
        if (mmi_audply_playlist_remove_all())
	    {
	        if (need_reApply)
	        {
	            mmi_audply_playlist_apply_picked_file();
	            mmi_audply_clear_play_seconds();
	        }
	        mmi_audply_playlist_reload_list();
	        
            if (mmi_frm_group_is_present(SCR_ID_AUDPLY_OPTION))
            {
                mmi_frm_group_close(SCR_ID_AUDPLY_OPTION);
            }
            mmi_frm_scrn_close_active_id();
            
            
	       // GoBackToHistory(SCR_ID_AUDPLY_LIST_BROWSER);
	    }
	    else
	    {
	  
			mmi_popup_display_ext(
                STR_ID_AUDPLY_CANNOT_UPDATE_LIST_FS_FAIL, 
                MMI_EVENT_FAILURE, 
                NULL);
	                
             if (mmi_frm_group_is_present(SCR_ID_AUDPLY_OPTION))
            {
                mmi_frm_group_close(SCR_ID_AUDPLY_OPTION);
            }
            
            // DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
	    }
    }
    else
    {
     	if ((ret = FS_Open(list->path, FS_READ_WRITE | FS_CACHE_DATA)) >= 0)
    	{
	        /* allocate memory for remove cntx. */
			MMI_ASSERT(remove_cntx_p == NULL);
		    remove_cntx_p = get_ctrl_buffer(sizeof(mmi_audply_remove_cntx_struct));
		    MMI_ASSERT(remove_cntx_p != NULL);

		    kal_mem_set(remove_cntx_p, 0, sizeof(mmi_audply_remove_cntx_struct));

            remove_cntx_p->list_hdlr = ret;
		    remove_cntx_p->remove_index = list_cntx.list_ui.highlight;
            remove_cntx_p->offset = remove_cntx_p->remove_index * MMI_AUDPLY_LIST_RECORD_SIZE;
			remove_cntx_p->remove_count = 
                (list->total - remove_cntx_p->remove_index - 1) / 
                (MAX_SUB_MENUS * MAX_SUB_MENU_SIZE / MMI_AUDPLY_LIST_RECORD_SIZE);
			if ((list->total - remove_cntx_p->remove_index - 1) % 
                (MAX_SUB_MENUS * MAX_SUB_MENU_SIZE / MMI_AUDPLY_LIST_RECORD_SIZE) > 0)
            {
				remove_cntx_p->remove_count++;
            }
			g_audply.remove_process = 1;
			WriteValueSlim(NVRAM_AUDPLY_REMOVE_IN_PROCESS, &g_audply.remove_process, DS_BYTE);
            remove_cntx_p->need_reapply = need_reApply;
	        mmi_audply_playlist_remove_wait_scr();
		    mmi_audply_playlist_remove_one();

	    }
        else
        {
			/* remove failed! */
			mmi_audply_playlist_display_popup(ret, NULL);
            //mmi_frm_scrn_close_active_id();
            if (mmi_frm_group_is_present(GRP_ID_AUDPLY_OPTION))
            {
                mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
            }
        	
        }
   	}	    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_remove_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_entry_remove_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	    
    
    do {
    	mmi_confirm_property_struct arg;
    	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	//	arg.f_auto_map_empty_softkey = MMI_FALSE;
    	arg.callback = (mmi_proc_func)mmi_audply_playlist_entry_remove_confirm_cb;
    	mmi_confirm_display((WCHAR *)(get_string(STR_ID_AUDPLY_OPTION_REMOVE_ASK)), MMI_EVENT_QUERY, &arg);
        }
      	while(0);
    	
    	if (mmi_frm_group_is_present(GRP_ID_AUDPLY_OPTION))
        {
            mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
        }
    	    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_entry_remove_confirm_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_audply_playlist_entry_remove_confirm_cb(mmi_alert_result_evt_struct *evt)
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
        		mmi_audply_playlist_remove_confirm_LSK();
				
        		break;
        		
          case MMI_ALERT_CNFM_NO:
          	mmi_frm_scrn_close_active_id();
          	break;
            
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_add_to_ring
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_audply_playlist_add_to_ring(void)
{


    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];

    mmi_audply_playlist_get_path(path, list_cntx.list_ui.highlight);
    
    if (!mmi_audply_does_file_exist(path))
    {
        mmi_audply_playlist_display_popup(FS_FILE_NOT_FOUND, NULL);
    }
    else
    {
        srv_prof_set_current_profile_tone_with_file_path(SRV_PROF_SETTINGS_MT_CALL_TONE, (WCHAR*)path);
    }
    mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_refresh
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_audply_playlist_refresh(void)
{
    mmi_audply_need_generate_playlist();
    /* clear play list gui buffer */
    mmi_audply_playlist_clear_list_browser_gui_buffer();

    if (mmi_frm_group_is_present(GRP_ID_AUDPLY_OPTION))
    {
         mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);    
    }
   // DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_audply_playlist_add(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FMGR_FILTER filter;
    U8 drv;
    S32 error;
    UI_character_type list_root[5]; /* "C:\" */
    MMI_ID cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
#ifdef __MMI_FILE_MANAGER__
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET_AUDIO(&filter);
#ifdef __VM_CODEC_SUPPORT__     
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_VM);
#endif /*__VM_CODEC_SUPPORT__*/    
#if defined(__MMI_PURE_AUDIO__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_3GP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_3G2);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_MP4);
#endif
#if defined(__VORBIS_DECODE__) && defined(__VORBIS_DECODE_SLIM__)
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_OGG);
#endif
#ifdef __DRM_V02__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif

    //mmi_frm_group_create(GRP_ID_AUDPLY_MAIN, GRP_ID_AUDPLY_LIST_ADD, mmi_audply_playlist_proc, (void*)NULL); 
    //mmi_frm_group_enter(GRP_ID_AUDPLY_LIST_ADD, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_group_create_ex(
    #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
        GRP_ID_AUDPLY_MAIN_PRE_LIST,
    #else
        GRP_ID_AUDPLY_MAIN, 
    #endif
        GRP_ID_AUDPLY_LIST_ADD, 
        mmi_audply_playlist_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /*config presnet_dir_root*/
    drv = mmi_audply_get_current_list_drv();
    kal_wsprintf(list_root, "%c:\\", drv);
	if ((error=FS_GetDevStatus(drv, FS_MOUNT_STATE_ENUM)) == FS_NO_ERROR)
    {

        cui_gid = cui_file_selector_create(
                                        GRP_ID_AUDPLY_LIST_ADD,
                                        (WCHAR*)list_root,
                                        &filter,
                                        CUI_FILE_SELECTOR_STYLE_FILE_AND_PATH,
                                        CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE | CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);


        if (cui_gid > GRP_ID_INVALID)
        {
            cui_file_selector_set_title(cui_gid, 0, GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID));
            cui_file_selector_run(cui_gid);
                   
        }
        else
        {   
            mmi_popup_display_ext(
                STR_GLOBAL_NOT_AVAILABLE, 
                MMI_EVENT_FAILURE, 
                NULL);
        }
    }
    else
    {        
        mmi_popup_display_ext(
            STR_GLOBAL_INSERT_MEMORY_CARD, 
            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(error), 
            NULL);
    }        
    mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);       
#endif /* __MMI_FILE_MANAGER__ */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audlpy_plst_fmgr_file_selector_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audlpy_plst_fmgr_file_selector_handle(cui_file_selector_result_event_struct *file_select)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_path[SRV_FMGR_PATH_BUFFER_SIZE];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_select->result > 0)
    {
        cui_file_selector_get_selected_filepath(
                                file_select->sender_id,
                                NULL,
                                (WCHAR *) temp_path,
                                SRV_FMGR_PATH_BUFFER_SIZE);
        
        mmi_audply_playlist_add_file_hdlr(temp_path, MMI_FALSE);
    }
    else if (file_select->result == 0)
    {
        cui_file_selector_close(file_select->sender_id);
    }
    else
    {
    #if defined(__USB_IN_NORMAL_MODE__)
	    if (!srv_usb_is_in_mass_storage_mode())
		    	    
    #endif /* defined(__USB_IN_NORMAL_MODE__) */ 
	   {
	        mmi_popup_display_ext(
	            (srv_fmgr_fs_error_get_string(file_select->result)), 
	            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(file_select->result), 
	            NULL);
		}	       
        cui_file_selector_close(file_select->sender_id);
    }

}




/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_initiate_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_audply_playlist_initiate_play(void)
{
#ifdef __MMI_BACKGROUND_CALL__
    if(srv_ucm_is_background_call())
    {
		mmi_ucm_entry_error_message();
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
        //DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
        return;
    }
#endif
    
    mmi_audply_playlist_set_start(list_cntx.list_ui.highlight);
    mmi_audply_playlist_set_pick_index(list_cntx.list_ui.highlight);
    if (mmi_audply_playlist_apply_picked_file())
    {
        mmi_audply_stop_playing();
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
        mmi_frm_group_close(GRP_ID_AUDPLY_LIST_BROWSER);
        #ifdef __MMI_AUDIO_PLAYER_BT__
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION_WITH_BT);
        #endif
        //GoBackToHistory(SCR_ID_AUDPLY_MAIN);
        mmi_audply_play();
    }
    else
    {
    	mmi_popup_display_ext(
    	    STR_ID_AUDPLY_OPEN_FILE_ERROR, 
    	    MMI_EVENT_FAILURE, 
    	    NULL);
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
        #ifdef __MMI_AUDIO_PLAYER_BT__
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION_WITH_BT);
        #endif
        //DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_add_file_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fullPath        [IN]
 *  is_short        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_add_file_hdlr(UI_string_type fullPath, int is_short)
{
    mmi_audply_playlist_generate(fullPath, is_short);
}
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */


#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
void mmi_audply_playlist_init(void)
{

}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_load_last_list
 * DESCRIPTION
 *  
 * PARAMETERS      
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_load_last_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type last_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    S32 ret = MMI_AUDPLY_PLAYLIST_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_audply_playlist_get_last_path(last_path))
    {
        if (last_path[0] != 0)
        {
            if (FS_GetAttributes(last_path) >= FS_NO_ERROR)
            {
               // memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
                ret = mmi_audply_playlist_open_internal(last_path, &(list_cntx.current_list));
                list_cntx.list_loaded = MMI_TRUE;
                if (ret < 0)
                {
                    FS_Close(list_cntx.current_list.fs_hdlr);
                    memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
                    list_cntx.list_loaded = MMI_FALSE;
                }
                else
                {
                    S32 last_index = mmi_audply_playlist_get_last_index();
                    mmi_audply_playlist_set_start(last_index);
                    mmi_audply_playlist_set_pick_index(last_index);
                    if (!mmi_audply_playlist_apply_picked_file())
                    {
                        FS_Close(list_cntx.current_list.fs_hdlr);
                        memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
                        list_cntx.list_loaded = MMI_FALSE;
                    }
                }
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_entry_listmgr
 * DESCRIPTION
 *  entry function of list manager screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_entry_listmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;
    mmi_audply_dynamic_list_data_struct* ui = &(list_cntx.list_ui);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (NULL == GetCurrGuiBuffer(SCR_ID_AUDPLY_LISTMGR))
    {
        mmi_audply_playlist_listmgr_init();
    }

    EntryNewScreen(SCR_ID_AUDPLY_LISTMGR, NULL, 
                   mmi_audply_playlist_entry_listmgr, NULL); 
        
    if (!ui->total)
    {
        ShowCategory52Screen(
            STR_ID_AUDPLY_LISTMGR,
            GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            NULL,
            NULL,
            NULL,
            1,
            0,
            NULL);
    }
    else
    {
        gui_buffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_LISTMGR);
        
        RegisterHighlightHandler(mmi_audply_playlist_ui_highlight_hdlr);
            
        ShowCategory185Screen(
            STR_ID_AUDPLY_LISTMGR,
            GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,			/* lsk */
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,    /* rsk */
            ui->total, 
            mmi_audply_playlist_listmgr_get_item, 
            NULL, 
            ui->highlight,
			MMI_FALSE,
			NULL,
            gui_buffer);  
    }

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_audply_playlist_entry_listmgr_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
    /* register left right arrow key handler */
    SetKeyDownHandler(mmi_audply_playlist_entry_listmgr_option, KEY_RIGHT_ARROW);
    SetKeyDownHandler(GoBackHistory, KEY_LEFT_ARROW);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_multiple_highlight_hdlr_init
 * DESCRIPTION
 *  init highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_multiple_highlight_hdlr_init(void)
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
 *  mmi_audply_highlight_option_play
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_option_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_option_initiate_play, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_option_details
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_option_details(void)
{
#ifdef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_entry_detail, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_option_moveup
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_option_moveup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_option_moveup, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_option_movedown
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_option_movedown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_option_movedown, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_option_remove
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_option_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_option_remove, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_option_forward
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_option_forward_use(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_entry_use, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_option_forward
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_option_forward_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_entry_send, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_option_settings
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_option_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_entry_two_layers_settings, KEY_EVENT_UP);
   
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_option_add
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_option_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_option_add, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_listmgr_option_load
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_listmgr_option_load(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_listmgr_open, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
} 

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_listmgr_option_new
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_listmgr_option_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_listmgr_create, KEY_EVENT_UP);
    SetKeyDownHandler(mmi_audply_playlist_listmgr_create, KEY_RIGHT_ARROW);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
} 

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_listmgr_option_delete
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_listmgr_option_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_listmgr_delete, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
} 

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_listmgr_option_delete
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_listmgr_option_delete_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_listmgr_delete_all_confirm, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
} 

void mmi_audply_highlight_listmgr_option_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_listmgr_select_storage, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_listmgr_option_rename
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_highlight_listmgr_option_rename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_listmgr_rename_check, KEY_EVENT_UP);
	
#ifdef __MMI_TOUCH_SCREEN__
	wgui_reset_list_item_selected_callback();
#endif
} 

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_editor_create_playlist
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_highlight_editor_create_playlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_listmgr_create_internal, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
} 

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_editor_rename_playlist
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_highlight_editor_rename_playlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_audply_playlist_listmgr_rename, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
} 
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_highlight_editor_rename_playlist
 * DESCRIPTION
 *  menu item highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_highlight_editor_input_method(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(EntryInputMethodScreen, KEY_EVENT_UP);
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
} 



static MMI_BOOL mmi_audply_playlist_save_last_path(UI_string_type path)
{
    S16 error = 0;
    
    if (0 > WriteRecordSlim(NVRAM_EF_AUDPLY_LAST_PLAYLIST_PATH_LID, 1, (void*)path, NVRAM_EF_AUDPLY_LIST_PLAYLIST_PATH_SIZE))
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

static MMI_BOOL mmi_audply_playlist_get_last_path(const UI_string_type path)
{
    S16 error = 0;
    
    if (ReadRecordSlim(NVRAM_EF_AUDPLY_LAST_PLAYLIST_PATH_LID, 1, (void*)path, NVRAM_EF_AUDPLY_LIST_PLAYLIST_PATH_SIZE) < 0)
    {     
        return MMI_FALSE;
    }
    return MMI_TRUE;    
}

static void mmi_audply_playlist_save_last_index(S32 index)
{
    S16 error = 0;
    U16 last_index = 0;
    if (index < 0)
    {
        last_index = 0xFFFF;
    }
    else
    {
        last_index = (U16)index;
    }
    WriteValueSlim(NVRAM_AUDPLY_LAST_PLAYLIST_INDEX, &last_index, DS_SHORT);
}

static S32 mmi_audply_playlist_get_last_index(void)
{
   // S16 error = 0;
    U16 index = 0;
    
    ReadValueSlim(NVRAM_AUDPLY_LAST_PLAYLIST_INDEX, &index, DS_SHORT);
    if (index == 0xFFFF)
    {     
        return -1;
    }
    return index;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_listmgr_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_listmgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_dynamic_list_data_struct* ui = &(list_cntx.list_ui);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_reset_ui_cntx();
    ui->total = mmi_audply_playlist_listmgr_list_all();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_listmgr_load_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_listmgr_load_cache(U16 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U16 cache_index = 0;
    
    mmi_audply_dynamic_list_data_struct* ui = &(list_cntx.list_ui);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(start_index < ui->total);

    /* init some value */
    ui->cache_start_index = start_index;

    for (i = 0; i < MMI_AUDPLY_LIST_BUFF_SIZE; i++)
    {
        ui->cache[i].filename[0] = 0;
        ui->cache[i].ext[0] = 0;
        ui->cache[i].file_type = 0;
        ui->cache[i].is_short = 0;
    }

    mmi_audply_playlist_listmgr_load_cache_internal(&cache_index, 
                                                ui->cache_start_index);


    ui->cache_start_index = start_index;
    ui->cache_end_index = start_index + cache_index;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_listmgr_list_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_audply_playlist_listmgr_list_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type search_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    FS_DOSDirEntry file_info;
    FS_HANDLE file_handle = -1;
    S32 return_value = FS_NO_ERROR;
    U16 file_count = 0;
    U8 file_type = 0;
    CHAR* ext_p = NULL;
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (g_audply.preferred_list == SRV_FMGR_CARD_DRV &&
        FS_GetDevStatus(g_audply.preferred_list, FS_MOUNT_STATE_ENUM) < 0)
    {
        g_audply.preferred_list = SRV_FMGR_PUBLIC_DRV;
    }
    
    kal_wsprintf((kal_wchar*)path, "%c:\\", (CHAR)g_audply.preferred_list);
    mmi_ucs2cat((CHAR*)path, (CHAR*)MMI_AUDPLY_DEFAULT_FOLDER);

    return_value = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);

    if (return_value < FS_NO_ERROR)
    {
        S32 ret = FS_NO_ERROR;
        
        ret = FS_CreateDir(path);
        if (ret < FS_NO_ERROR)
        {
            /* Do not care error. */
        }
        else
        {
            FS_SetAttributes(path, FS_ATTR_DIR | FS_ATTR_HIDDEN);    
        }
        return 0;
    }
    else
    {
        FS_Close(return_value);
    }
    
    mmi_ucs2cat((CHAR*)path, (CHAR*)L"\\");
    mmi_ucs2cat((CHAR*)path, (CHAR*)L"*.*");

    file_handle = FS_FindFirstN(
                (PU16)path,
                NULL,
                0,
                FS_ATTR_DIR,
                0,
                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                &file_info,
                (PU16)search_name,
                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1)* ENCODING_LENGTH,
                0,
                FS_FIND_DEFAULT);

    if (file_handle >= 0)
    {
        do
        {
            if (!(file_info.Attributes & (FS_ATTR_DIR | FS_ATTR_HIDDEN | FS_ATTR_VOLUME)))
            {
                /* check extend name. filter invalid. */
                ext_p = mmi_ucs2rchr((CHAR*)search_name, (U16)L'.');
                MMI_ASSERT(ext_p != NULL);

                if (!mmi_ucs2nicmp((CHAR*)ext_p, (CHAR*)MMI_AUDPLY_MULTIPLE_LIST_EXT, 4))
                {
                    file_type = MMI_AUDPLY_PLAYLIST_PLST;
                }
                else
                {
                    file_type = 0;
                }
                
                if (file_type)
                {  
                    ext_p = NULL;
                    /* increase counter */
                    file_count++;
                }
            }
            
            return_value = FS_FindNextN(
                                file_handle,
                                NULL,
                                0,
                                FS_ATTR_DIR,
                                &file_info,
                                (PU16)search_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                FS_FIND_DEFAULT);
        } while (return_value == FS_NO_ERROR);

        FS_FindClose(file_handle);
    }
    return file_count;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_listmgr_load_cache_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_audply_playlist_listmgr_load_cache_internal(U16 *cached_num, U16 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type search_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    FS_DOSDirEntry file_info;
    FS_HANDLE file_handle = -1;
    MMI_BOOL is_short = MMI_FALSE;
    S32 return_value = FS_NO_ERROR;
    U16 cache_index = 0;
    U8 file_type = 0;
    CHAR* ext_p = NULL;
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    mmi_audply_dynamic_list_data_struct* ui = &(list_cntx.list_ui);
    FS_Pattern_Struct list_file[1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    
    kal_wsprintf(path, "%c:\\", (CHAR)g_audply.preferred_list);
    mmi_ucs2cat((CHAR*)path, (CHAR*)MMI_AUDPLY_DEFAULT_FOLDER);
	mmi_ucs2cat((CHAR*)path, (CHAR*)L"\\");
    mmi_ucs2cat((CHAR*)path, (CHAR*)L"*.*");

    mmi_ucs2ncpy((CHAR*)list_file[0].Pattern, (CHAR*)L"*", 8);
    mmi_ucs2ncat((CHAR*)list_file[0].Pattern, (CHAR*)MMI_AUDPLY_MULTIPLE_LIST_EXT, 8);

    file_handle = FS_FindFirstN(
                (PU16)path,
                list_file,
                1,
                0,
                0,
                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME | FS_ATTR_DIR,
                &file_info,
                (PU16)search_name,
                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                start_index,
                FS_FIND_DEFAULT);

    if (file_handle >= 0)
    {
        do
        {
            if (!(file_info.Attributes & (FS_ATTR_DIR | FS_ATTR_HIDDEN | FS_ATTR_VOLUME)))
            {
                /* check extend name. filter invalid. */
                ext_p = mmi_ucs2rchr((CHAR*)search_name, (U16)L'.');
                //MMI_ASSERT(ext_p != NULL);
                if (ext_p == NULL)
                {
                    file_type = 0;
                }
                else
                {
                    if (!mmi_ucs2nicmp((CHAR*)ext_p, (CHAR*)MMI_AUDPLY_MULTIPLE_LIST_EXT, 4))
                    {
                        file_type = MMI_AUDPLY_PLAYLIST_PLST;
                    }
                    else
                    {
                        file_type = 0;
                    }
                }
                
                if (file_type)
                {  
                    ext_p = NULL;
                    /* still have entry to fill in the catch */
                    if (cache_index < MMI_AUDPLY_LIST_BUFF_SIZE)
                    {
                        is_short = ((file_info.NTReserved & FS_SFN_MATCH) != 0);

                        /* get extend name. */
                        if (is_short)
                        {
                            U8 j = 0;
                            ext[0] = L'.';
                            for (j = 1; j < 4; j++)
                            {
                                ext[j] = (UI_character_type) file_info.Extension[j - 1];
                            }
                            ext[j] = 0;
                        }
                        else
                        {
                            ext_p = mmi_ucs2rchr((CHAR*)search_name, (U16)L'.');
                            MMI_ASSERT(ext_p != NULL);
                            mmi_ucs2ncpy((CHAR*)ext, (CHAR*)ext_p, mmi_ucs2strlen((CHAR*)ext_p));
                        }
                        /* cut off extend name. */
                        ext_p = mmi_ucs2rchr((CHAR*)search_name, (U16)L'.');
                        MMI_ASSERT(ext_p != NULL);
                        *(ext_p + 1) = 0;
                        *ext_p = 0;
                        
                        /* save cache. */
                        if (cache_index < MMI_AUDPLY_LIST_BUFF_SIZE)
                        {
                            mmi_ucs2ncpy(
                                (CHAR*)ui->cache[cache_index].ext,
                                (CHAR*)ext,
                                mmi_ucs2strlen((CHAR*)ext));

                            if (is_short)
                            {
                                mmi_chset_mixed_text_to_ucs2_str(
                                    (U8*)ui->cache[cache_index].filename,
                                    (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                    (U8*)search_name,
                                    PhnsetGetDefEncodingType());
                            }
                            else
                            {
                                mmi_ucs2ncpy((CHAR*)ui->cache[cache_index].filename, 
                                       (CHAR*)search_name, SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
                            }
                            ui->cache[cache_index].file_type = file_type;
                            ui->cache[cache_index].is_short = is_short;

                            cache_index++;
                        }
                    }
                }
            }

            if (cache_index == MMI_AUDPLY_LIST_BUFF_SIZE)
            {
                *cached_num = cache_index;
                FS_FindClose(file_handle);
                return;
            }
            
            return_value = FS_FindNextN(
                                file_handle,
                                list_file,
                                1,
                                FS_ATTR_DIR,
                                &file_info,
                                (PU16)search_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                FS_FIND_DEFAULT);
        } while (return_value == FS_NO_ERROR);

        FS_FindClose(file_handle);
    }

    *cached_num = cache_index;
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_listmgr_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL mmi_audply_playlist_listmgr_get_item
    (S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_list_item_info_struct item_info;
    S32 load_index;
    mmi_audply_dynamic_list_data_struct* ui = &(list_cntx.list_ui);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (item_idx >= ui->total)
    {
        mmi_ucs2ncpy((CHAR*)str_buff, (CHAR*)GetString(STR_GLOBAL_LOADING), MAX_SUBMENU_CHARACTERS);
        *img_buff_p = NULL;
        return MMI_TRUE;
    }

    if ((item_idx < ui->cache_start_index) ||
        (item_idx >= ui->cache_end_index))
    {
        /* desired entry in the middle of cache */
        load_index = item_idx - (MMI_AUDPLY_LIST_BUFF_SIZE / 2);

        if (load_index < 0)
        {
            load_index = 0;
        }

        mmi_audply_playlist_listmgr_load_cache((U16)load_index);        
    }
    memcpy(&item_info, 
            &(ui->cache[item_idx - ui->cache_start_index]), 
            sizeof(mmi_audply_list_item_info_struct));

    //memset(str_buff, 0, sizeof(MAX_SUB_MENU_SIZE));


    mmi_ucs2ncpy((CHAR*)str_buff, 
               (CHAR*)item_info.filename, MAX_SUBMENU_CHARACTERS);
    str_buff[mmi_ucs2strlen((CHAR*)str_buff)] = 0;

    *img_buff_p = (PU8) GetImage(IMG_ID_AUDPLY_FILE_PLAYLIST_ICON);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_entry_listmgr_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_entry_listmgr_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U16 nNumofItem = 0;
    U8 *gui_buffer = NULL;
    mmi_audply_dynamic_list_data_struct* ui = &(list_cntx.list_ui);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* always hide all optional items. */
    mmi_frm_hide_menu_item(MENU_ID_AUDPLY_LISTMGR_OPTION_LOAD);
    mmi_frm_hide_menu_item(MENU_ID_AUDPLY_LISTMGR_OPTION_DELETE);
    mmi_frm_hide_menu_item(MENU_ID_AUDPLY_LISTMGR_OPTION_DELETE_ALL);
    mmi_frm_hide_menu_item(MENU_ID_AUDPLY_LISTMGR_OPTION_RENAME);

	if (ui->total > 0)
    {
        mmi_frm_unhide_menu_item(MENU_ID_AUDPLY_LISTMGR_OPTION_LOAD);
        mmi_frm_unhide_menu_item(MENU_ID_AUDPLY_LISTMGR_OPTION_DELETE);
        mmi_frm_unhide_menu_item(MENU_ID_AUDPLY_LISTMGR_OPTION_DELETE_ALL);
        mmi_frm_unhide_menu_item(MENU_ID_AUDPLY_LISTMGR_OPTION_RENAME);
    }

    EntryNewScreen(SCR_ID_AUDPLY_LISTMGR_OPTION, NULL, 
                                mmi_audply_playlist_entry_listmgr_option, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_LISTMGR_OPTION);
	
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild_Ext(MENU_ID_AUDPLY_OPTION_MENU_LISTMGR);
    GetSequenceStringIds_Ext(MENU_ID_AUDPLY_OPTION_MENU_LISTMGR, nStrItemList);
    SetParentHandler(MENU_ID_AUDPLY_OPTION_MENU_LISTMGR);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*)gIndexIconsImageList,
        LIST_MENU,
        0,
        gui_buffer);
    ClearKeyEvents();
    SetKeyDownHandler(GoBackHistory, KEY_LEFT_ARROW);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_listmgr_get_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
// TODO:need handle plug-out memory card!!!!
static void mmi_audply_playlist_listmgr_get_path(UI_string_type path)
{
    U16 index = (U16)list_cntx.list_ui.highlight;
    S32 load_index = 0;
	U16 cache_index = 0;
	

	if (index < list_cntx.list_ui.cache_start_index ||
		index > list_cntx.list_ui.cache_end_index)
	{
        /* desired entry in the middle of cache */
        load_index = index - (MMI_AUDPLY_LIST_BUFF_SIZE / 2);

        if (load_index < 0)
        {
            load_index = 0;
        }

        mmi_audply_playlist_listmgr_load_cache((U16)load_index); 
	}
    cache_index = (U16)(index - list_cntx.list_ui.cache_start_index);
    kal_wsprintf(path, "%c:\\", (CHAR)g_audply.preferred_list);
    mmi_ucs2cat((CHAR*)path, (CHAR*)MMI_AUDPLY_DEFAULT_FOLDER);
    mmi_ucs2cat((CHAR*)path, (CHAR*)"\\");
    mmi_ucs2cat((CHAR*)path, (CHAR*)list_cntx.list_ui.cache[cache_index].filename);
    mmi_ucs2cat((CHAR*)path, (CHAR*)list_cntx.list_ui.cache[cache_index].ext);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_select_drv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_listmgr_create_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret = FS_NO_ERROR;
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = mmi_audply_editor_check_name_valid(list_cntx.editor_buffer);
    if (fs_ret < FS_NO_ERROR)
    {
        if (fs_ret == MMI_AUDPLY_PLAYLIST_ERR_INVALID_FILENAME)
        {
            mmi_popup_display_ext(
                STR_GLOBAL_INVALID_FILENAME, 
                MMI_EVENT_ERROR, 
                NULL);
            DeleteScreenIfPresent(SCR_ID_AUDPLY_EDITOR_OPTION);
        }
        else if (fs_ret == MMI_AUDPLY_PLAYLIST_ERR_EMPTY_FILENAME)
        {
            mmi_popup_display_ext(
                STR_GLOBAL_PLEASE_INPUT_THE_FILENAME, 
                MMI_EVENT_ERROR, 
                NULL);
            DeleteScreenIfPresent(SCR_ID_AUDPLY_EDITOR_OPTION);
        }
        else
        {
            /* unknown case!!! */
            GoBackToHistory(SCR_ID_AUDPLY_EDITOR);
        }
        return;
    }

    kal_wsprintf(path, "%c:\\", (CHAR)g_audply.preferred_list);
/* check whether has enough space. */
{
    FS_DiskInfo disk_info;
    U32 disk_free_space;

    fs_ret = FS_GetDiskInfo((kal_uint16*)path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    if (fs_ret >= 0)
    {        
        disk_free_space = disk_info.FreeClusters * 
                          disk_info.SectorsPerCluster * 
                          disk_info.BytesPerSector;
        if (disk_free_space < 10 * 1024)    /* 10KB free space request. */
        {
            /* popup "Not enough space." */
            mmi_audply_playlist_display_popup(MMI_AUDPLY_PLAYLIST_ERR_NO_SPACE, NULL);
            return;
        }
    }
}

    
    mmi_ucs2cat((CHAR*)path, (CHAR*)MMI_AUDPLY_DEFAULT_FOLDER);
/* check default playlist folder. */
    fs_ret = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);

    if (fs_ret < 0)
    {     
        if (fs_ret == FS_FAT_ALLOC_ERROR)
        {
            mmi_audply_playlist_display_popup(fs_ret, NULL);
            DeleteUptoScrID(SCR_ID_AUDPLY_LISTMGR);
            return;
        }
        
        fs_ret = FS_CreateDir(path);
        if (fs_ret < 0)
        {
            mmi_audply_playlist_display_popup(fs_ret, NULL);
            DeleteUptoScrID(SCR_ID_AUDPLY_LISTMGR);
            return;
        }
        else
        {
            FS_SetAttributes(path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
            fs_ret = 0;
        }
    }
    else
    {
        FS_Close(fs_ret);
        fs_ret = 0;
    }
/* compose playlist full path. */
    mmi_ucs2cat((CHAR*)path, (CHAR*)L"\\");
    mmi_ucs2cat((CHAR*)path, (CHAR*)list_cntx.editor_buffer);
	mmi_ucs2cat((CHAR*)path, (CHAR*)MMI_AUDPLY_MULTIPLE_LIST_EXT);
    
    /* check file, pop up if exist. */
    if (FS_GetAttributes(path) > 0)
    {
        mmi_audply_playlist_display_popup(MMI_AUDPLY_PLAYLIST_ERR_EXIST_FILE, NULL);
        DeleteUptoScrID(SCR_ID_AUDPLY_LISTMGR);
    }
    else
    {
        fs_ret = mmi_audply_playlist_create(path);
        
        if (fs_ret < 0)
        {
            /* all error caught in create will popup "create plauylist failed" */
            mmi_audply_playlist_display_popup(MMI_AUDPLY_PLAYLIST_ERR_CREATE_FAILED, NULL);
            DeleteUptoScrID(SCR_ID_AUDPLY_LISTMGR);
        }
        else
        {
            mmi_popup_display_ext(
                STR_GLOBAL_DONE, 
                MMI_EVENT_SUCCESS, 
                NULL);

            /* need clear highlight index saved in gui buffer. */
            HistoryReplace(SCR_ID_AUDPLY_LISTMGR, 
                SCR_ID_AUDPLY_LISTMGR, mmi_audply_playlist_entry_listmgr);
            
            DeleteUptoScrID(SCR_ID_AUDPLY_LISTMGR);  
        }
    }
}

static MMI_BOOL mmi_audply_playlist_listmgr_get_filename(UI_string_type filename, S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_list_item_info_struct item_info;
    S32 load_index;
    S32 current = 0;
    mmi_audply_dynamic_list_data_struct* list_ui = &(list_cntx.list_ui);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index >= list_ui->total || item_index < 0)
    {
        return MMI_FALSE;
    }

    if ((item_index < list_ui->cache_start_index) ||
        (item_index >= list_ui->cache_end_index))
    {
        /* desired entry in the middle of cache */
        load_index = item_index - (MMI_AUDPLY_LIST_BUFF_SIZE / 2);

        if (load_index < 0)
        {
            load_index = 0;
        }

        mmi_audply_playlist_listmgr_load_cache((U16)load_index); 
    }
    current = item_index - list_ui->cache_start_index;
    memcpy(&item_info, 
            &(list_ui->cache[current]), 
            sizeof(mmi_audply_list_item_info_struct));
    
    mmi_ucs2ncpy((CHAR*)filename, (CHAR*)item_info.filename, SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
/*    
    if (item_info.ext[0] != 0)    
    {
        if (!mmi_ucs2rchr((CHAR*)item_info.ext, (U16)L'.'))
        {
            mmi_ucs2cat((CHAR*)filename, (CHAR*)L".");
        }
        mmi_ucs2cat((CHAR*)filename, (CHAR*)item_info.ext);
    }
*/    
    
    return MMI_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_listmgr_rename_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_listmgr_rename_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_audply_playlist_listmgr_get_filename(filename, 
                                                 list_cntx.list_ui.highlight))
    {
        list_cntx.editor_type = MMI_AUDPLY_EDITOR_RENAME;
        list_cntx.editor_buffer[0] = 0;
	    mmi_ucs2cpy((CHAR*)list_cntx.editor_buffer, (CHAR*)filename);
        mmi_audply_entry_editor();
    }
    // TODO: add trace!
}

static void mmi_audply_get_drive_callback(CHAR driver_letter)
{
    S16 error = 0;
    
    if (driver_letter == 0)
    {
        GoBackToHistory(SCR_ID_AUDPLY_LISTMGR);
    }
    else
    {
        if (driver_letter != g_audply.preferred_list)
        {
            g_audply.preferred_list = (U8)driver_letter;
            WriteValueSlim(NVRAM_AUDPLY_PREFER_LIST, &g_audply.preferred_list, DS_BYTE);
            mmi_popup_display_ext(
                STR_GLOBAL_DONE, 
                MMI_EVENT_SUCCESS, 
                NULL);
            HistoryReplace(SCR_ID_AUDPLY_LISTMGR, 
                SCR_ID_AUDPLY_LISTMGR, mmi_audply_playlist_entry_listmgr);
            DeleteUptoScrID(SCR_ID_AUDPLY_LISTMGR);
        }
        else
        {
            GoBackToHistory(SCR_ID_AUDPLY_LISTMGR);
        }
    }
}

static void mmi_audply_playlist_listmgr_select_storage(void)
{
    EntryNewScreen(SCR_ID_AUDPLY_SELECT_STORAGE, NULL, mmi_audply_playlist_listmgr_select_storage, NULL);
    mmi_fmgr_sel_drv_and_enter(APP_AUDIOPLAYER, (mmi_fmgr_select_drv_callback)mmi_audply_get_drive_callback, g_audply.preferred_list);
    DeleteScreenIfPresent(SCR_ID_AUDPLY_LISTMGR_OPTION);
}

static void mmi_audply_playlist_listmgr_delete_all_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type str[50];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(str, "%w", GetString(STR_GLOBAL_DELETE_ALL));
    mmi_ucs2cat((CHAR*)str, (CHAR*)GetString(STR_ID_FMGR_QUESTION_MARK));
    do {
	mmi_confirm_property_struct arg;
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	arg.callback = (mmi_proc_func)NULL;
	mmi_confirm_display((WCHAR *)(str), MMI_EVENT_QUERY, &arg);
	} while(0);
    SetLeftSoftkeyFunction(mmi_audply_playlist_listmgr_delete_all_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_delete_abort
 * DESCRIPTION
 *  Abort delete operation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_delete_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	FS_Abort(FS_ABORT_XDELETE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_progress
 * DESCRIPTION
 *  Delete all operation completed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_progress(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AUDPLY_DELETE_ALL_PROGRESS, NULL, mmi_audply_playlist_progress, NULL);

    /* Show searching screen */
    ShowCategory66Screen(
        STR_GLOBAL_DELETING,
        GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
        0,
        0,
        STR_GLOBAL_ABORT,
        0,
        (U8*) GetString(STR_GLOBAL_DELETING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    /* Set RSK to abort searching */
    SetRightSoftkeyFunction(mmi_audply_delete_abort, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_delete_all_rsp
 * DESCRIPTION
 *  Delete all operation completed
 * PARAMETERS
 *  has_popup       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_delete_all_rsp(srv_fmgr_async_done_event_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_async_done_event_struct *msg = (srv_fmgr_async_done_event_struct*) info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg->result >= FS_NO_ERROR)
    {
        mmi_popup_display_ext(
            STR_GLOBAL_DONE, 
            MMI_EVENT_SUCCESS, 
            NULL);
	}
	else
	{
		mmi_audply_playlist_display_popup(msg->result, NULL);
	}
	DeleteScreenIfPresent(SCR_ID_AUDPLY_DELETE_ALL_PROGRESS);
}


static void mmi_audply_playlist_listmgr_delete_all_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret = FS_NO_ERROR;
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    DeleteScreenIfPresent(SCR_ID_AUDPLY_LISTMGR_OPTION);

    if (list_cntx.list_loaded && 
        g_audply.preferred_list == mmi_audply_get_current_list_drv())
    {
        list_cntx.list_loaded = MMI_FALSE; 

        FS_Commit(list_cntx.current_list.fs_hdlr);
        fs_ret = FS_Close(list_cntx.current_list.fs_hdlr);
     
        memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
        
        mmi_audply_stop_playing();
        
        /* clear player data. for play failed case. */
        /*mmi_audply_clear_play_seconds();
        g_audply.seekable = MMI_FALSE;
        g_audply.need_to_build_cache = MMI_FALSE;
        g_audply.title[0] = 0;
        g_audply.filefullname[0] = 0;*/
        mmi_audply_reset_context();
        g_audply.successive_fail_num = 0;
        
        if (fs_ret < FS_NO_ERROR)
        {
        	mmi_audply_playlist_display_popup(fs_ret, NULL);
            DeleteUptoScrID(SCR_ID_AUDPLY_LISTMGR);
            return;
        }
    }
    kal_wsprintf((kal_wchar*)path, "%c:\\", (CHAR)g_audply.preferred_list);
    mmi_ucs2cat((CHAR*)path, (CHAR*)MMI_AUDPLY_DEFAULT_FOLDER);

    /* fs_ret = FS_XDelete(
     *           (PU16)path,
     *           FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE,
     *           NULL,
     *           0);
     */
    /* Multiple playlist: Directly replace, no impact*/
    srv_fmgr_async_delete((WCHAR *) path, 0, mmi_audply_playlist_proc, NULL);
    
    mmi_audply_playlist_progress();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_listmgr_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_listmgr_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str[100];
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    CHAR* filename = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_listmgr_get_path(path);

    //memset(str, 0, sizeof(str));

    mmi_ucs2cpy((CHAR*) str, (CHAR*) get_string(STR_GLOBAL_DELETE));
    mmi_ucs2cat((CHAR*) str, (CHAR*) L" ");
    
    filename = mmi_ucs2rchr((CHAR*)path, (U16)L'\\');
    
    if (filename == NULL)
    {
        // TODO: add trace!
        return;
    }
    filename += 2;

    mmi_ucs2cat((CHAR*)str, (CHAR*)filename);
#if !defined(__MMI_AUDPLY_M3U_SUPPORT__)
{
    CHAR* ext = mmi_ucs2rchr((CHAR*)str, (U16)L'.');
    
    if (ext == NULL)
    {
        // TODO: add trace!
        return;
    }
    *(ext + 1) = 0;
    *ext = 0;
}
#endif
    mmi_ucs2cat((CHAR*)str, (CHAR*)GetString(STR_ID_FMGR_QUESTION_MARK));

    do {
	mmi_confirm_property_struct arg;
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	arg.callback = (mmi_proc_func)NULL;
	mmi_confirm_display((WCHAR *)((UI_string_type)str), MMI_EVENT_QUERY, &arg);
	} while(0);

    SetLeftSoftkeyFunction(mmi_audply_playlist_listmgr_delete_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_listmgr_delete_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_listmgr_delete_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    S32 ret = 0;
    S32 fs_ret = FS_NO_ERROR;
    MMI_BOOL delete_now_playing = MMI_FALSE;
    MMI_BOOL resume_delay_paly_timer = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* count the current index in cache. */
    mmi_audply_playlist_listmgr_get_path(path);

    if (list_cntx.list_loaded)
    {
        if (!mmi_ucs2icmp((CHAR*)list_cntx.current_list.path, (CHAR*)path))
        {
            delete_now_playing = MMI_TRUE;
        }
    }
    /* the option screen of list manager. */
    DeleteScreenIfPresent(SCR_ID_AUDPLY_LISTMGR_OPTION);

    if (delete_now_playing)
    {
        if (g_audply.wait_next)
        {
            StopTimer(AUDPLY_DELAY_PLAY_TIMER);
            g_audply.wait_next = MMI_FALSE;
            resume_delay_paly_timer = MMI_TRUE;
        }
        FS_Commit(list_cntx.current_list.fs_hdlr);
        fs_ret = FS_Close(list_cntx.current_list.fs_hdlr);

        if (fs_ret < FS_NO_ERROR)
        {
        	mmi_audply_playlist_display_popup(fs_ret, NULL);
            DeleteUptoScrID(SCR_ID_AUDPLY_LISTMGR);
            return;
        }
    }

    
    ret = FS_Delete(path);
    /* error handling. */
    if (ret < 0)
    {
        if (delete_now_playing)
        {
            /* try to reopen. */
            S32 hdlr = FS_NO_ERROR;

            hdlr = FS_Open(list_cntx.current_list.path, FS_READ_WRITE);
            if (hdlr < 0)
            {
                /* clear list data and player variables. */
                list_cntx.list_loaded = MMI_FALSE;
                memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));

                mmi_audply_stop_playing();

                /* clear player data. for play failed case. */
                /*mmi_audply_clear_play_seconds();
                g_audply.seekable = MMI_FALSE;
                g_audply.need_to_build_cache = MMI_FALSE;
                g_audply.title[0] = 0;
                g_audply.filefullname[0] = 0;*/
                mmi_audply_reset_context();
                g_audply.successive_fail_num = 0;

                HistoryReplace(SCR_ID_AUDPLY_LISTMGR, 
                    SCR_ID_AUDPLY_LISTMGR, mmi_audply_playlist_entry_listmgr);
            }
            else
            {
                list_cntx.current_list.fs_hdlr = hdlr;
                if (resume_delay_paly_timer)
                {
                    StartTimer(AUDPLY_DELAY_PLAY_TIMER, 700, mmi_audply_delay_play);
                    g_audply.wait_next = MMI_TRUE;
                }
            }
        }

        mmi_audply_playlist_display_popup(ret, NULL);
        DeleteUptoScrID(SCR_ID_AUDPLY_LISTMGR);
    }
    else
    {
        /* no error, popup successful. */

        if (delete_now_playing)
        {
            list_cntx.list_loaded = MMI_FALSE;
            memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));

            mmi_audply_stop_playing();

            /* clear player data. for play failed case. */
/*
            mmi_audply_clear_play_seconds();
            g_audply.seekable = MMI_FALSE;
            g_audply.need_to_build_cache = MMI_FALSE;
            g_audply.title[0] = 0;
            g_audply.filefullname[0] = 0;*/
            mmi_audply_reset_context();
            g_audply.successive_fail_num = 0;
        }
        mmi_popup_display_ext(
            STR_GLOBAL_DELETED, 
            MMI_EVENT_SUCCESS, 
            NULL);
        DeleteScreenIfPresent(SCR_ID_AUDPLY_LISTMGR_OPTION);

        /* need clear highlight index saved in gui buffer, because the list changed. */
        HistoryReplace(SCR_ID_AUDPLY_LISTMGR, 
                SCR_ID_AUDPLY_LISTMGR, mmi_audply_playlist_entry_listmgr);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_listmgr_rename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_listmgr_rename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret = FS_NO_ERROR;
    UI_character_type filename_without_ext[SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN + 1];
    UI_character_type old_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type new_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    CHAR* filename = NULL;
    MMI_BOOL rename_now_playing = MMI_FALSE;
    MMI_BOOL resume_delay_play_timer = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2ncpy((CHAR*)filename_without_ext, (CHAR*)list_cntx.editor_buffer, SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN);
    fs_ret = mmi_audply_editor_check_name_valid(filename_without_ext);
    
    if (fs_ret != 0)
    {
        if (fs_ret == MMI_AUDPLY_PLAYLIST_ERR_INVALID_FILENAME)
        {
            mmi_popup_display_ext(
                STR_GLOBAL_INVALID_FILENAME, 
                MMI_EVENT_ERROR, 
                NULL);
            DeleteScreenIfPresent(SCR_ID_AUDPLY_EDITOR_OPTION);
        }
        else if (fs_ret == MMI_AUDPLY_PLAYLIST_ERR_EMPTY_FILENAME)
        {
            mmi_popup_display_ext(
                STR_GLOBAL_PLEASE_INPUT_THE_FILENAME, 
                MMI_EVENT_ERROR, 
                NULL);
            DeleteScreenIfPresent(SCR_ID_AUDPLY_EDITOR_OPTION);
        }
        else
        {
            /* unknown case!!! */
            // TODO: add trace!
            mmi_audply_editor_close_function();
        }
        return;
    }

    mmi_audply_playlist_listmgr_get_path(old_path);

    if (list_cntx.list_loaded)
    {
        if (!mmi_ucs2icmp((CHAR*)list_cntx.current_list.path, (CHAR*)old_path))
        {
            rename_now_playing = MMI_TRUE;
        }
    }
    
    mmi_ucs2ncpy((CHAR*)new_path, (CHAR*)old_path, (SRV_FMGR_PATH_MAX_LEN+1));

    filename = mmi_ucs2rchr((CHAR*)new_path, (U16)'\\');

    if (filename == NULL)
    {
        GoBackToHistory(SCR_ID_AUDPLY_LISTMGR);
        return;
    }
    filename += 2;

    mmi_ucs2cpy((CHAR*)filename, (CHAR*)filename_without_ext);
    mmi_ucs2cat((CHAR*)filename, (CHAR*)MMI_AUDPLY_MULTIPLE_LIST_EXT);
    /* check file whether is exist. */
    if (FS_GetAttributes(new_path) >= 0)
    {
        if (mmi_ucs2nicmp((CHAR*)new_path, (CHAR*)old_path, (SRV_FMGR_PATH_MAX_LEN+1)))
        {
            mmi_audply_playlist_display_popup(MMI_AUDPLY_PLAYLIST_ERR_EXIST_FILE, NULL);
            DeleteUptoScrID(SCR_ID_AUDPLY_LISTMGR);
        }
        else
        {
            /* name no change. */
            GoBackToHistory(SCR_ID_AUDPLY_LISTMGR);
        }
        return;
    }
    if (rename_now_playing)
    {
        S32 ret = FS_NO_ERROR;
        
        FS_Commit(list_cntx.current_list.fs_hdlr);
        ret = FS_Close(list_cntx.current_list.fs_hdlr);

        if (ret < FS_NO_ERROR)
        {
        	mmi_audply_playlist_display_popup(ret, NULL);
            DeleteUptoScrID(SCR_ID_AUDPLY_LISTMGR);
            return;
        }
        
        if (g_audply.wait_next)
        {
            resume_delay_play_timer = MMI_TRUE;
            StopTimer(AUDPLY_DELAY_PLAY_TIMER);
        }
    }
    /* rename. */
    fs_ret = FS_Rename(old_path, new_path);
    if (fs_ret < 0)
    {
        if (rename_now_playing)
        {
            S32 ret = FS_NO_ERROR;
            ret = FS_Open(list_cntx.current_list.path, FS_READ_WRITE);
            if (ret < FS_NO_ERROR)
            {
                /* clear list data and player variables. */
                list_cntx.list_loaded = MMI_FALSE;
                memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));

                mmi_audply_stop_playing();

                /* clear player data. for play failed case. */
                /*mmi_audply_clear_play_seconds();
                g_audply.seekable = MMI_FALSE;
                g_audply.need_to_build_cache = MMI_FALSE;
                g_audply.title[0] = 0;
                g_audply.filefullname[0] = 0;*/
                mmi_audply_reset_context();
                g_audply.successive_fail_num = 0;

                HistoryReplace(SCR_ID_AUDPLY_LISTMGR, 
                    SCR_ID_AUDPLY_LISTMGR, mmi_audply_playlist_entry_listmgr);
            }
            else
            {
                list_cntx.current_list.fs_hdlr = ret;
                if (resume_delay_play_timer)
                {
                    StartTimer(AUDPLY_DELAY_PLAY_TIMER, 700, mmi_audply_delay_play);
                }
            }
        }
        mmi_audply_playlist_display_popup(fs_ret, NULL);
        DeleteUptoScrID(SCR_ID_AUDPLY_LISTMGR);
        return;
    }
    else
    {
        if (rename_now_playing)
        {
            S32 ret = FS_NO_ERROR;
            mmi_ucs2ncpy((CHAR*)list_cntx.current_list.path, (CHAR*)new_path, (SRV_FMGR_PATH_MAX_LEN+1));
            ret = FS_Open(new_path, FS_READ_WRITE);
            MMI_ASSERT(!(ret < 0));
            
            list_cntx.current_list.fs_hdlr = ret;

            /* update title. */
            mmi_ucs2ncpy((CHAR*)list_cntx.current_list.title, 
                    (CHAR*)filename_without_ext, SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN);
            
            if (resume_delay_play_timer)
            {
                StartTimer(AUDPLY_DELAY_PLAY_TIMER, 700, mmi_audply_delay_play);
            }
        }
        /* clear gui buffer to reset highlight as 0. */
        HistoryReplace(SCR_ID_AUDPLY_LISTMGR, SCR_ID_AUDPLY_LISTMGR, mmi_audply_playlist_entry_listmgr);
        GoBackToHistory(SCR_ID_AUDPLY_LISTMGR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_listmgr_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_listmgr_open(void)
{
    S32 ret = 0;
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];

    mmi_audply_playlist_listmgr_get_path(path);
    ret = mmi_audply_playlist_open(path);

    if (ret < 0)
    {
        mmi_audply_playlist_display_popup(ret, NULL);
        DeleteUptoScrID(SCR_ID_AUDPLY_LISTMGR);
    }
    else
    {
        mmi_audply_playlist_entry_playlist_multiple();
        DeleteScreenIfPresent(SCR_ID_AUDPLY_LISTMGR_OPTION);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_listmgr_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_listmgr_create(void)
{
    list_cntx.editor_type = MMI_AUDPLY_EDITOR_NEW;
	list_cntx.editor_buffer[0] = 0;
    mmi_audply_entry_editor();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_option_initiate_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_option_initiate_play(void)
{
#ifdef __MMI_BACKGROUND_CALL__
    if(srv_ucm_is_background_call())
    {
        mmi_ucm_entry_error_message();
        DeleteScreenIfPresent(SCR_ID_AUDPLY_OPTION);
        DeleteScreenIfPresent(SCR_ID_AUDPLY_LIST_BROWSER);
        return;
    }
#endif

    if (!in_browser_mode)
    {
        return;
    }
    
    /* stop playing. */
    if (g_audply.state != STATE_IDLE)
    {
        mmi_audply_stop_playing();
    }
    
    if (list_cntx.list_loaded)
    {
        if (!browser_now_playing)
        {
            mmi_audply_stop_playing();
            /* close nowplaying list. */
            mmi_audply_playlist_write_back_to_file(&(list_cntx.current_list));
            FS_Close(list_cntx.current_list.fs_hdlr);
            memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
            /* copy all info about now browsering list to "current_list". */
            memcpy(&(list_cntx.current_list), &(list_cntx.browser_list), sizeof(mmi_audply_playlist_struct));
            mmi_audply_playlist_save_last_path(list_cntx.current_list.path);
            browser_now_playing = MMI_TRUE;
        }
        
        /* initiate play. */
        {
            mmi_audply_playlist_set_start(list_cntx.list_ui.highlight);
            mmi_audply_playlist_set_pick_index(list_cntx.list_ui.highlight);

            if (mmi_audply_playlist_apply_picked_file())
            {
                mmi_audply_stop_playing();
                /* enter player screen. */
                if (!IsScreenPresent(SCR_ID_AUDPLY_MAIN))
                {
                    /* initiate play from list manager's list browser. */
                    mmi_audply_entry_player();
                    DeleteScreenIfPresent(SCR_ID_AUDPLY_OPTION);
                    DeleteScreenIfPresent(SCR_ID_AUDPLY_LIST_BROWSER);
                    DeleteScreenIfPresent(SCR_ID_AUDPLY_LISTMGR);
                    /* reset highlight in main list screen. */
                    {
                        PU8 gui_buffer = NULL;    
                        gui_buffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_MAIN_LIST);
                        if (gui_buffer != NULL)
                        {
                            list_menu_category_history *hist = (list_menu_category_history*)gui_buffer;

                            hist->highlighted_item = 0;
                        }
                    }
                }
                else
                {
                    /* initiate play from now playling list. */
                    GoBackToHistory(SCR_ID_AUDPLY_MAIN);
                }
                mmi_audply_play();
            }
			else
			{
                mmi_popup_display_ext(
                    STR_ID_AUDPLY_OPEN_FILE_ERROR, 
                    MMI_EVENT_FAILURE, 
                    NULL);
			}
        }
    }
    else
    {
        /* init "current_list". */
        memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
        /* copy all info about now browsering list to "current_list". */
        memcpy(&(list_cntx.current_list), &(list_cntx.browser_list), sizeof(mmi_audply_playlist_struct));
        mmi_audply_playlist_save_last_path(list_cntx.current_list.path);
        /* set nowplaying flag. */
        browser_now_playing = MMI_TRUE;
        list_cntx.list_loaded = MMI_TRUE;
        /* initiate play. */
        {
            mmi_audply_playlist_set_start(list_cntx.list_ui.highlight);
            mmi_audply_playlist_set_pick_index(list_cntx.list_ui.highlight);
            if (mmi_audply_playlist_apply_picked_file())
            {
                mmi_audply_stop_playing();
                /* enter player screen. */
                if (!IsScreenPresent(SCR_ID_AUDPLY_MAIN))
                {
                    /* initiate play from list manager's list browser. */
                    mmi_audply_entry_player();
                    DeleteScreenIfPresent(SCR_ID_AUDPLY_OPTION);
                    DeleteScreenIfPresent(SCR_ID_AUDPLY_LIST_BROWSER);
                    DeleteScreenIfPresent(SCR_ID_AUDPLY_LISTMGR);
                    /* reset highlight in main list screen. */
                    {
                        PU8 gui_buffer = NULL;    
                        gui_buffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_MAIN_LIST);
                        if (gui_buffer != NULL)
                        {
                            list_menu_category_history *hist = (list_menu_category_history*)gui_buffer;
                            
                            hist->highlighted_item = 0;
                        }
                    }
                }
                else
                {
                    /* initiate play from now playling list. */
                    GoBackToHistory(SCR_ID_AUDPLY_MAIN);
                }
                mmi_audply_play();
            }
			else
			{
                mmi_popup_display_ext(
                    STR_ID_AUDPLY_OPEN_FILE_ERROR, 
                    MMI_EVENT_FAILURE, 
                    NULL);
			}
        }
    }
}



static void mmi_audply_playlist_option_remove_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_struct* list = &(list_cntx.browser_list);
    mmi_audply_playlist_block_node_struct block;
    U32 backup_offset = 0;
    U32 current_offset = 0;
    U32 next_offset = 0;
    U32 fs_size = 0;
    S32 ret = FS_NO_ERROR;
    U8 i = 0;
    MMI_BOOL need_reApply = MMI_FALSE;
    S32 hilite = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (browser_now_playing)
    {        
        list = &(list_cntx.current_list);
    }
    
    if (list_cntx.list_ui.highlight >= MMI_AUDPLY_MAX_PLAYLIST_ITEM)
    {
        return;
    }
    else if (list_cntx.list_ui.highlight < 0)
    {
        return;
    }
    else
    {
        hilite = list_cntx.list_ui.highlight;
    }
    
    if (browser_now_playing)
    {        
        if (list->pick_index == hilite)
        {
            mmi_audply_stop_playing();
            need_reApply = MMI_TRUE;
            if (list->pick_index == list->total - 1)
            {
                list->pick_index--;
             /*   list->pick_count--; */
            }
            if (hilite == list->total)
            {
                list_cntx.list_ui.highlight--;
            }
        }
        else
        {
            if (list->pick_index > hilite)
            {
                list->pick_index--;
            }
        }
    }
    backup_offset = list->header.empty_node.offset;

    list->header.empty_node.offset = list->header.index[hilite].offset;
    list->header.empty_node.used_block += list->header.index[hilite].used_block;
    
    list->header.index[hilite].is_active = 0;
    list->header.index[hilite].index = MMI_AUDPLY_MAX_PLAYLIST_ITEM;
    list->header.index[hilite].offset = 0;
    if (IsBitSetOn(hilite, list->bitset))
    {
        list->pick_count--;
        ClrBitSet(hilite, list->bitset);
    }
    current_offset = list->header.empty_node.offset;
    next_offset = current_offset;

    do
    {
        for (i = 0; i < list->header.index[hilite].used_block; i++)
        {
            if (next_offset == 0)
            {
                break;
            }
            ret = FS_Seek(list->fs_hdlr, next_offset, FS_FILE_BEGIN);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            current_offset = next_offset;
            ret = FS_Read(list->fs_hdlr, &block, sizeof(mmi_audply_playlist_block_node_struct), &fs_size);
            if (ret < FS_NO_ERROR)
            {
                break;
            }

            if (fs_size != sizeof(mmi_audply_playlist_block_node_struct))
            {
                ret = MMI_AUDPLY_PLAYLIST_ERR_READ_FAILED;
                break;
            }
            if (block.pattern_begin != AUDPLY_PLAYLIST_BLOCK_PATTERN_1 ||
                block.pattern_end != AUDPLY_PLAYLIST_BLOCK_PATTERN_2)
            {
                ret = MMI_AUDPLY_PLAYLIST_ERR_LIST_DAMAGED;
                break;
            }
            next_offset = block.next_ptr;
        }

        if (ret < FS_NO_ERROR)
        {
            break;
        }
        block.next_ptr = backup_offset;
        ret = FS_Seek(list->fs_hdlr, current_offset, FS_FILE_BEGIN);
        ret = FS_Write(list->fs_hdlr, &block, sizeof(mmi_audply_playlist_block_node_struct), &fs_size);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
        if (fs_size != sizeof(mmi_audply_playlist_block_node_struct))
        {
            ret = MMI_AUDPLY_PLAYLIST_ERR_WRITE_FAILED;
            break;
        }
    } while (0);
    
    list->header.total_slot--;
    list->total--;
    list_cntx.list_ui.total--;
    mmi_audply_playlist_generate_sort_index(list->header.index, 0, list->header.total_slot);
    MMI_ASSERT(list->header.pattern == AUDPLY_PLAYLIST_FOOTER_PATTERN);
    
    {
        U16 i = 0;
        U16 empty = 0;
        U16 used = list->header.total_slot;
        U16 total = list->header.total_slot + 1;
        mmi_audply_playlist_index_node_struct* index = list->header.index;

        for (i = 0; i < total; i++)
        {
            if (index[i].index != i)
            {
                if (index[i].index == MMI_AUDPLY_MAX_PLAYLIST_ITEM)
                {
                    index[i].index = used + empty;
                    empty++;
                }
                else
                {
                    index[i].index = i;
                }
            }
        }
    }
    ret = mmi_audply_playlist_write_back_to_file(list);
    if (browser_now_playing)
    {
        if (need_reApply)
        {
            mmi_audply_playlist_apply_picked_file();
            mmi_audply_clear_play_seconds();
        }

        if (mmi_audply_playlist_is_empty())
        {
            /*mmi_audply_clear_play_seconds();
            g_audply.seekable = MMI_FALSE;                
            g_audply.need_to_build_cache = MMI_FALSE;
            g_audply.title[0] = 0;
            g_audply.filefullname[0] = 0;
            */
            mmi_audply_reset_context();
        }
    }
    mmi_audply_playlist_reload_list();
    mmi_popup_display_ext(
        STR_GLOBAL_REMOVED, 
        MMI_EVENT_SUCCESS, 
        NULL);

    DeleteScreenIfPresent(SCR_ID_AUDPLY_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_option_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_option_remove(void)
{
	do {
	mmi_confirm_property_struct arg;
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	arg.callback = (mmi_proc_func)NULL;
	mmi_confirm_display((WCHAR *)(get_string(STR_ID_AUDPLY_OPTION_REMOVE_ASK)), MMI_EVENT_QUERY, &arg);
	} while(0);

    SetLeftSoftkeyFunction(mmi_audply_playlist_option_remove_LSK, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


static void mmi_audply_playlist_exchange_bitset(U16 old_index, U16 new_index, PU8 bitset)
{
    MMI_BOOL old_set = MMI_FALSE;
    MMI_BOOL new_set = MMI_FALSE;
    
    if (IsBitSetOn(old_index, bitset))
    {
        ClrBitSet(old_index, bitset);
        old_set = MMI_TRUE;
    }

    if (IsBitSetOn(new_index, bitset))
    {
        ClrBitSet(new_index, bitset);
        new_set = MMI_TRUE;
    }

    if (old_set)
    {
        SetBitSet(new_index, bitset);
    }

    if (new_set)
    {
        SetBitSet(old_index, bitset);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_option_moveup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_option_moveup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_struct* list = &(list_cntx.browser_list);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (browser_now_playing)
    {
        list = &(list_cntx.current_list);
    }
    if (list_cntx.list_ui.highlight == 0)
    {
        U16 i = 0;
        if (browser_now_playing)
        {
            if (list->header.index[0].index == list->pick_index)
            {
                /* set pick index. */
                list->pick_index = (list->total - 1);
                /* set first index to last one. */
                list->header.index[0].index = list->total - 1;
                /* set other's index. */
                for (i = 1; i < list->total; i++)
                {
                    /* exchange bitset. */
                    mmi_audply_playlist_exchange_bitset(
                            list->header.index[i].index,
                            (U16)(list->header.index[i].index - 1),
                            list->bitset);
                    /* set index. */
                    list->header.index[i].index--; 
                }
                /* set highlight. */
                list_cntx.list_ui.highlight = (list->total - 1);
            }
            else
            {
                MMI_BOOL set = MMI_FALSE;
                /* set first index to last one. */
                list->header.index[0].index = list->total - 1;
                /* set other's index. */                
                for (i = 1; i < list->total; i++)
                {                   
                    if (list->header.index[i].index == list->pick_index && !set)
                    {
                        /* set pick index. */
                        list->pick_index--;
                        set = MMI_TRUE;
                    }
                    /* exchange bitset. */
                    mmi_audply_playlist_exchange_bitset(
                            list->header.index[i].index,
                            (U16)(list->header.index[i].index - 1),
                            list->bitset);
                    /* set index. */
                    list->header.index[i].index--; 
                }
                /* set highlight. */
                list_cntx.list_ui.highlight = (list->total - 1);
            }
        }
        else
        {
            list->header.index[0].index = list->total - 1;
            for (i = 1; i < list->total; i++)
            {
                list->header.index[i].index--; 
            }
            /* set highlight. */
            list_cntx.list_ui.highlight = (list->total - 1);
        }
    }
    else
    {
        if (browser_now_playing)
        {
            if (list->pick_index == list->header.index[list_cntx.list_ui.highlight].index)
            {
                list->pick_index--;
            }
            else if (list->pick_index == list->header.index[list_cntx.list_ui.highlight - 1].index)
            {
                list->pick_index++;
            }
            else
           
            mmi_audply_playlist_exchange_bitset(
                        list->header.index[list_cntx.list_ui.highlight].index,
                        list->header.index[list_cntx.list_ui.highlight - 1].index,
                        list->bitset);
            list->header.index[list_cntx.list_ui.highlight].index--;
            list->header.index[list_cntx.list_ui.highlight - 1].index++;
            list_cntx.list_ui.highlight--;
        }
        else
        {
            list->header.index[list_cntx.list_ui.highlight].index--;
            list->header.index[list_cntx.list_ui.highlight - 1].index++;
            list_cntx.list_ui.highlight--;
        }
    }
    mmi_audply_playlist_generate_sort_index(list->header.index, 0, (list->total - 1));
    MMI_ASSERT(list->header.pattern == AUDPLY_PLAYLIST_FOOTER_PATTERN);

    mmi_audply_playlist_reload_list();
    GoBackToHistory(SCR_ID_AUDPLY_LIST_BROWSER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_option_movedown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_option_movedown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_struct* list = &(list_cntx.browser_list);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (browser_now_playing)
    {
        list = &(list_cntx.current_list);
    }
    if (list_cntx.list_ui.highlight == (list->total - 1))
    {
        U16 i = 0;
        if (browser_now_playing)
        {
            if (list->header.index[list_cntx.list_ui.highlight].index == list->pick_index)
            {
                list->pick_index = 0;
                list->header.index[list_cntx.list_ui.highlight].index = 0;
                for (i = 0; i < (list->total - 1); i++)
                {
                    mmi_audply_playlist_exchange_bitset(
                            list->header.index[i].index,
                            (U16)(list->header.index[i].index + 1),
                            list->bitset);
                    list->header.index[i].index++;
                }
                list_cntx.list_ui.highlight = 0;
            }
            else
            {
                MMI_BOOL set = MMI_FALSE;
                list->header.index[list_cntx.list_ui.highlight].index = 0;
                for (i = 0; i < (list->total - 1); i++)
                {
                    if (list->header.index[i].index == list->pick_index && !set)
                    {
                        list->pick_index++;
                        set = MMI_TRUE;
                    }
                    mmi_audply_playlist_exchange_bitset(
                            list->header.index[i].index,
                            (U16)(list->header.index[i].index + 1),
                            list->bitset);
                    list->header.index[i].index++;
                }
                list_cntx.list_ui.highlight = 0;
            }
        }
        else
        {
            list->header.index[list_cntx.list_ui.highlight].index = 0;
            for (i = 0; i < (list->total - 1); i++)
            {
                list->header.index[i].index++;
            }
            list_cntx.list_ui.highlight = 0;
        }
    }
    else
    {
        if (browser_now_playing)
        {
            if (list->pick_index == list->header.index[list_cntx.list_ui.highlight].index)
            {
                list->pick_index++;
            }
            else if (list->pick_index == list->header.index[list_cntx.list_ui.highlight + 1].index)
            {
                list->pick_index--;
            }

            mmi_audply_playlist_exchange_bitset(
                        list->header.index[list_cntx.list_ui.highlight].index,
                        list->header.index[list_cntx.list_ui.highlight + 1].index,
                        list->bitset);
            list->header.index[list_cntx.list_ui.highlight].index++;
            list->header.index[list_cntx.list_ui.highlight + 1].index--;
            list_cntx.list_ui.highlight++;
        }
        else
        {
            list->header.index[list_cntx.list_ui.highlight].index++;
            list->header.index[list_cntx.list_ui.highlight + 1].index--;
            list_cntx.list_ui.highlight++;
        }
    }
    mmi_audply_playlist_generate_sort_index(list->header.index, 0, (list->total - 1));
    MMI_ASSERT(list->header.pattern == AUDPLY_PLAYLIST_FOOTER_PATTERN); 

    mmi_audply_playlist_reload_list();
    GoBackToHistory(SCR_ID_AUDPLY_LIST_BROWSER);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_option_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_option_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* call file manager API to select media file or folder.*/  
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET_AUDIO(&filter);
#ifdef __VM_CODEC_SUPPORT__     
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_VM);
#endif /*__VM_CODEC_SUPPORT__*/    
#if defined(__MMI_PURE_AUDIO__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_3GP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_3G2);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_MP4);
#endif
#ifdef __DRM_V02__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif
    DeleteScreenIfPresent(SCR_ID_AUDPLY_OPTION);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_audply_playlist_create(const UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = MMI_AUDPLY_PLAYLIST_NO_ERROR;
    U32 write_size = 0;

    mmi_audply_playlist_header_struct * header = NULL;
    FS_HANDLE fs_hdlr = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    header = (mmi_audply_playlist_header_struct *) mmi_frm_scrmem_alloc(sizeof(mmi_audply_playlist_header_struct));
    if(header == NULL)
    {
        return MMI_AUDPLY_PLAYLIST_ERR_NO_SPACE;
    }
    memset(header, 0, sizeof(mmi_audply_playlist_header_struct));

    /* create new playlist. */
    do
    {
        ret = FS_Open(path, FS_CREATE_ALWAYS | FS_READ_WRITE);
        if (ret < 0)
        {
            break;
        }

        fs_hdlr = ret;
    /* write header. */
        header->footer_pattern_offset = AUDPLY_PLAYLIST_DATA_OFFSET;
        strncpy((CHAR*)header->type_id, AUDPLY_PLAYLIST_TYPE_ID, 4);
        strncpy((CHAR*)header->version, AUDPLY_PLAYLIST_VERSION, 2);
        header->pattern = AUDPLY_PLAYLIST_FOOTER_PATTERN;
        ret = FS_Write(fs_hdlr, header,
                       sizeof(mmi_audply_playlist_header_struct), 
                       &write_size);

        if (ret < 0)
        {
            break;
        }
        else if (write_size != sizeof(mmi_audply_playlist_header_struct))
        {
            ret = MMI_AUDPLY_PLAYLIST_ERR_CREATE_FAILED;
            break;
        }
    } while (0);
    FS_Commit(fs_hdlr);
    FS_Close(fs_hdlr);
    if (ret < 0)
    {
        FS_Delete(path);
    }
    mmi_frm_scrmem_free(header);
    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_open_for_browser
 * DESCRIPTION
 *  open a list file. 
 * PARAMETERS
 *  file_path
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_audply_playlist_open(const UI_string_type file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&(list_cntx.browser_list), 0, sizeof(mmi_audply_playlist_struct));

    /* check whether is the loading playlist. */
    if (list_cntx.list_loaded)
    {
        if (!mmi_ucs2icmp((CHAR*)file_path, (CHAR*)list_cntx.current_list.path))
        {
            browser_now_playing = MMI_TRUE;
            return FS_NO_ERROR;
        }
    }
	
	ret = mmi_audply_playlist_open_internal(file_path, &(list_cntx.browser_list));

	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_list_open_playlist
 * DESCRIPTION
 *  open a list file. 
 * PARAMETERS
 *  file_path
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_audply_playlist_open_internal(const UI_string_type file_path, mmi_audply_playlist_struct* this)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;
    U32 read_size = 0;
    U32 empty_size = 0;
    CHAR* filename = NULL;
    CHAR* dot = NULL;
    U32 file_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* open playlist file. */
    mmi_ucs2ncpy((CHAR*)this->path, (CHAR*)file_path, 
                                        mmi_ucs2strlen((CHAR*)file_path));

    do
    {
        ret = FS_Open(this->path, FS_READ_WRITE);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
        filename = mmi_ucs2rchr((CHAR*)file_path, (U16)L'\\');
        if (filename == NULL)
        {
            ret = MMI_AUDPLY_PLAYLIST_ERR_INVALID_PARA;
            break;
        }
        filename += 2;
        mmi_ucs2ncpy((CHAR*)this->title, (CHAR*)filename, SRV_FMGR_PATH_MAX_FILE_NAME_LEN);

        dot = mmi_ucs2rchr((CHAR*)this->title, (U16)L'.');
        if (dot == NULL)
        {
            ret = MMI_AUDPLY_PLAYLIST_ERR_INVALID_PARA;
            break;
        }
        *(dot + 1) = 0;
        *dot = 0;
        
        /* set variables. */
        this->fs_hdlr = ret;
        this->pick_index = 0;
        this->pick_count = 0;
        this->total = 0;
                

        ret = FS_Read(this->fs_hdlr, &(this->header), 
                        sizeof(mmi_audply_playlist_header_struct), &read_size);

        if (ret < FS_NO_ERROR)
        {
            FS_Close(this->fs_hdlr);
            break;
        }
        else if (read_size != sizeof(mmi_audply_playlist_header_struct))
        {
            FS_Close(this->fs_hdlr);
            ret = MMI_AUDPLY_PLAYLIST_ERR_NOT_PLST;
            break;
        }
        /* check type id and version. */
        if (strncmp((CHAR*)(this->header.type_id), AUDPLY_PLAYLIST_TYPE_ID, 4))
        {
            ret = MMI_AUDPLY_PLAYLIST_ERR_NOT_PLST;
            break;
        }

        if (strncmp((CHAR*)(this->header.version), AUDPLY_PLAYLIST_VERSION, 2))
        {
            ret = MMI_AUDPLY_PLAYLIST_ERR_WRONG_VER;
            break;
        }

        ret = FS_GetFileSize(this->fs_hdlr, &file_size);

        if (ret < FS_NO_ERROR)
        {
            ret = MMI_AUDPLY_PLAYLIST_ERR_NOT_PLST;
            break;
        }

        if (this->header.footer_pattern_offset != file_size) 
        {
            ret = MMI_AUDPLY_PLAYLIST_ERR_NOT_PLST;
            break;
        }

        if ((this->header.footer_pattern_offset - 
                sizeof(mmi_audply_playlist_header_struct)) % 
             sizeof(mmi_audply_playlist_block_node_struct) != 0)
        {
            ret = MMI_AUDPLY_PLAYLIST_ERR_NOT_PLST;
            break;        
        }

        if (this->header.pattern != AUDPLY_PLAYLIST_FOOTER_PATTERN)
        {
            ret = MMI_AUDPLY_PLAYLIST_ERR_NOT_PLST;
            break;
        }
        
        
    /* pass file type verification. */
        this->total = this->header.total_slot;
        ret = FS_Seek(this->fs_hdlr, AUDPLY_PLAYLIST_DATA_OFFSET, FS_FILE_BEGIN);
        
        if (ret < FS_NO_ERROR)
        {
            ret = MMI_AUDPLY_PLAYLIST_ERR_OPEN_FAILED;
            break;
        }
        
        mmi_audply_playlist_generate_sort_index(this->header.index, 0, (this->total - 1));
        MMI_ASSERT(this->header.pattern == AUDPLY_PLAYLIST_FOOTER_PATTERN);
        if (this->total)
        {
            empty_size = sizeof(mmi_audply_playlist_index_node_struct) * 
                            (MMI_AUDPLY_MAX_PLAYLIST_ITEM - this->header.total_slot);
            memset(&(this->header.index[this->total]), 0, empty_size);
            MMI_ASSERT(this->header.pattern == AUDPLY_PLAYLIST_FOOTER_PATTERN);
            
            mmi_audply_playlist_generate_sort_index(this->header.index, 0, (this->total - 1));
            MMI_ASSERT(this->header.pattern == AUDPLY_PLAYLIST_FOOTER_PATTERN);
        }
    } while (0);

    if (ret < FS_NO_ERROR)
    {   
        FS_Close(this->fs_hdlr);
    }
        
    return ret;       
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_init_ui_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_init_ui_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_dynamic_list_data_struct* ui = &(list_cntx.list_ui);
    mmi_audply_playlist_struct* list = &(list_cntx.browser_list);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (browser_now_playing)
    {
        list = &(list_cntx.current_list);
    }
    ui->total = list->total;
    mmi_ucs2cpy((CHAR*)ui->title, (CHAR*)list->title);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_exit_list_browser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_exit_playlist_multiple(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_audply.in_list_screen = MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_del_list_browser_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_audply_playlist_del_list_browser_callback(void* param)
{
    g_audply.in_list_screen = MMI_FALSE;
    in_browser_mode = MMI_FALSE;
    /* close opening play list. */
    if (!browser_now_playing)
    {
        mmi_audply_playlist_write_back_to_file(&(list_cntx.browser_list));
        FS_Close(list_cntx.browser_list.fs_hdlr);
    }
    else
    {
        browser_now_playing = MMI_FALSE;
        mmi_audply_playlist_write_back_to_file(&(list_cntx.current_list));
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_entry_list_browser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_entry_playlist_multiple(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_dynamic_list_data_struct* list_ui = &(list_cntx.list_ui);
    S32 highlighted_item = 0;
    U8 *guiBuffer = NULL;
    mmi_audply_playlist_struct* list = &(list_cntx.browser_list);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (browser_now_playing)
    {
        list = &(list_cntx.current_list);
    }
    
    if (NULL == GetCurrGuiBuffer(SCR_ID_AUDPLY_LIST_BROWSER))
    {
        mmi_audply_playlist_reset_ui_cntx();
        mmi_audply_playlist_init_ui_cntx();
    }

    EntryNewScreen(SCR_ID_AUDPLY_LIST_BROWSER, mmi_audply_playlist_exit_playlist_multiple, mmi_audply_playlist_entry_playlist_multiple, NULL);
    SetDelScrnIDCallbackHandler(SCR_ID_AUDPLY_LIST_BROWSER, 
                            mmi_audply_playlist_del_list_browser_callback);
    g_audply.in_list_screen = MMI_TRUE;
    in_browser_mode = MMI_TRUE;

    if (!mmi_audply_playlist_is_valid() && browser_now_playing)
    {
        ShowCategory52Screen(
            STR_ID_AUDPLY_PLAYLIST,
            GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            NULL,
            NULL,
            NULL,
            1,
            0,
            NULL);
        
        /* register LSK, RSK hanlders */
        SetLeftSoftkeyFunction(mmi_audply_playlist_entry_playlist_option_multiple, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        
        /* register left right arrow key handler */
        SetKeyDownHandler(mmi_audply_playlist_entry_playlist_option_multiple, KEY_RIGHT_ARROW);
        SetKeyDownHandler(GoBackHistory, KEY_LEFT_ARROW);
    }
    else if (list_ui->total == 0)
    {
        ShowCategory353Screen(
            (PU8)list->title,
            GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            NULL,
            NULL,
            NULL,
            1,
            0,
            NULL);

        /* register LSK, RSK hanlders */
        SetLeftSoftkeyFunction(mmi_audply_playlist_entry_playlist_option_multiple, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        
        /* register left right arrow key handler */
        SetKeyDownHandler(mmi_audply_playlist_entry_playlist_option_multiple, KEY_RIGHT_ARROW);
        SetKeyDownHandler(GoBackHistory, KEY_LEFT_ARROW);
    }
    else
    {       
        /*
        **  4 cases:
        **      1. now playing list screen and enter from player screen.
        **          need set highlight on playing item.
        **      2. now playing list screen and go back from option or etc...
        **          need set back highlight on user selected before enter other screen from this screen.
        **      3. common list browser screen and enter from list manager.
        **          do not care highlight, always set to begin.
        **      4. common list browser screen and go back from option or etc...
        **          need set back highlight on user selected before enter other screen from this screen.
        **          
        */
        guiBuffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_LIST_BROWSER);

        if (guiBuffer != NULL)
        {
            list_menu_category_history *hist = (list_menu_category_history*) guiBuffer;

            /* case 2. */
            if (browser_now_playing && GetCurrScrnId() == SCR_ID_AUDPLY_MAIN)
            {
                hist->highlighted_item = list_cntx.list_ui.highlight;
            }
            else    /* case 4. */
            {
                hist->highlighted_item = list_cntx.list_ui.highlight;
            }            
        }
        else
        {
            /* case 1. */
            if (browser_now_playing && GetCurrScrnId() == SCR_ID_AUDPLY_MAIN)
            {
                highlighted_item = mmi_audply_playlist_get_current_index();
                if (highlighted_item < 0)
                {
                    highlighted_item = 0;
                }
            }
            else    /* case 3. */
            {
                highlighted_item = 0;
            }
        }
        list_cntx.list_ui.highlight = highlighted_item;
        
        if (browser_now_playing)
        {
            memcpy(&(list_cntx.browser_list), &(list_cntx.current_list), sizeof(mmi_audply_playlist_struct));
        }

        /* register highligh handler */
        RegisterHighlightHandler(mmi_audply_playlist_ui_highlight_hdlr);

        ShowCategory183Screen(
            list->title, 
            get_image(GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID)),    
            get_string(STR_GLOBAL_OPTIONS),
            get_image(IMG_GLOBAL_OPTIONS),              
            get_string(STR_GLOBAL_BACK),
            get_image(IMG_GLOBAL_BACK), 
            list_ui->total,
            mmi_audply_playlist_get_item,
            NULL,
            highlighted_item,
            MMI_FALSE,
            NULL,
            guiBuffer);
  
        /* register LSK, RSK hanlders */
        SetLeftSoftkeyFunction(mmi_audply_playlist_entry_playlist_option_multiple, KEY_EVENT_UP);
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        
        /* register left right arrow key handler */
        SetKeyDownHandler(mmi_audply_playlist_entry_playlist_option_multiple, KEY_RIGHT_ARROW);
        SetKeyDownHandler(GoBackHistory, KEY_LEFT_ARROW);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
pBOOL mmi_audply_playlist_get_item(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_list_item_info_struct item_info;
    S32 load_index;
    S32 file_ext_index = 0;
    mmi_audply_dynamic_list_data_struct* ui = &(list_cntx.list_ui);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(item_idx < ui->total);    
    memset(&item_info, 0, sizeof(mmi_audply_list_item_info_struct));
    if ((item_idx < ui->cache_start_index) ||
        (item_idx >= ui->cache_end_index))
    {
        /* desired entry in the middle of cache */
        load_index = item_idx - (MMI_AUDPLY_LIST_BUFF_SIZE / 2);

        if (load_index < 0)
        {
            load_index = 0;
        }

        if (0 > mmi_audply_playlist_load_cache((U16)load_index))
        {
        	mmi_ucs2ncpy((CHAR*)str_buff, (CHAR*)GetString(STR_GLOBAL_LOADING), MAX_SUBMENU_CHARACTERS);
            *img_buff_p = NULL;
            return MMI_TRUE;
        }
    }
    memcpy(&item_info, 
            &(ui->cache[item_idx - ui->cache_start_index]), 
            sizeof(mmi_audply_list_item_info_struct));

    memset(str_buff, 0, sizeof(MAX_SUBMENU_CHARACTERS));

    mmi_ucs2ncpy((CHAR*)str_buff, (CHAR*)item_info.filename, MAX_SUBMENU_CHARACTERS);

    file_ext_index = mmi_audply_lookup_audio_file_format(item_info.ext);
#ifdef __MMI_SHOW_FILE_EXT__
#if !defined(__MMI_SHOW_DAF_FILE_EXT__)
    if (mmi_ucs2nicmp((CHAR*)item_info.ext, (CHAR*)L".MP3", SRV_FMGR_PATH_MAX_FILE_EXT_LEN) && 
        mmi_ucs2nicmp((CHAR*)item_info.ext, (CHAR*)L".MP2", SRV_FMGR_PATH_MAX_FILE_EXT_LEN))
#endif
        mmi_ucs2cat((CHAR*)str_buff, (CHAR*)item_info.ext);
#endif

    if (file_ext_index >= 0)
    {
        *img_buff_p = (PU8) GetImage(audio_file_icon_ids[file_ext_index]);
    }
    else
    {
        *img_buff_p = (PU8) GetImage(IMG_ID_AUDPLY_FILE_UNKNOWN_ICON);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_load_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_audply_playlist_load_cache(U16 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U16 cache_index = 0;
    mmi_audply_dynamic_list_data_struct* ui = &(list_cntx.list_ui);
    S32 ret = FS_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    /* init some value */
    ui->cache_start_index = start_index;

    for (i = 0; i < MMI_AUDPLY_LIST_BUFF_SIZE; i++)
    {
        ui->cache[i].filename[0] = 0;
        ui->cache[i].ext[0] = 0;
        ui->cache[i].file_type = 0;
        ui->cache[i].is_short = 0;
        //ui->cache[i].id = 0;
    }
   
    ret = mmi_audply_playlist_get_list(&cache_index, start_index);

    if (ret < 0)
    {
        return ret;
    }
    else
    {
        ui->cache_start_index = start_index;
        ui->cache_end_index = start_index + cache_index;
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *          
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_audply_playlist_get_list(U16 *cached_num, U16 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i = 0;
    U16 count = 0;
    U32 read_size = 0;
    CHAR* file_name = NULL;
    CHAR* ext = NULL;

	U32 data_offset = 0;
    S32 ret = MMI_AUDPLY_PLAYLIST_NO_ERROR;
    
    CHAR path_buff[SRV_FMGR_PATH_BUFFER_SIZE];
    UI_character_type ucs2_buff[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    mmi_audply_playlist_block_node_struct block;
    mmi_audply_playlist_struct* list = &(list_cntx.browser_list);
    mmi_audply_dynamic_list_data_struct* ui = &(list_cntx.list_ui);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (browser_now_playing)
    {
        list = &(list_cntx.current_list);
    }
    memset(path_buff, 0, SRV_SRV_FMGR_PATH_BUFFER_SIZE);
    memset(ucs2_buff, 0, ((SRV_FMGR_PATH_MAX_LEN+1) + 1) * ENCODING_LENGTH);
    while (count < MMI_AUDPLY_LIST_BUFF_SIZE && start_index < list->total)
    {
        if (!list->header.index[start_index].is_active)
        {
            /*
            **  current node is an empty node. 
            **  this case should not happen.
            **  pass this node.
            */
            // TODO: add trace
            start_index++;
            continue;
        }

        /* seek to current offset. */
		data_offset = list->header.index[start_index].offset;        

		for (i = 0; i < list->header.index[start_index].used_block; i++)
        {
            if (data_offset == 0)
            {
                break;
            }
            FS_Seek(list->fs_hdlr, data_offset, FS_FILE_BEGIN);
            ret = FS_Read(list->fs_hdlr, &block,
                    sizeof(mmi_audply_playlist_block_node_struct),
                    &read_size);    /* size = number of U8. */
            
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            else if (read_size != sizeof(mmi_audply_playlist_block_node_struct))
            {
                ret = MMI_AUDPLY_PLAYLIST_ERR_READ_FAILED;
                break;
            }
            else if (block.pattern_begin != AUDPLY_PLAYLIST_BLOCK_PATTERN_1 ||
                     block.pattern_end != AUDPLY_PLAYLIST_BLOCK_PATTERN_2)
            {
                ret = MMI_AUDPLY_PLAYLIST_ERR_LIST_DAMAGED;
                break;
            }
            else
            {
                data_offset = block.next_ptr;
                memcpy(&(path_buff[i * MMI_AUDPLY_BLOCK_DATA_SIZE]), &(block.data), MMI_AUDPLY_BLOCK_DATA_SIZE);
            }
            
        }

        if (ret < 0)
        {
            break;
        }
        
		if (list->header.index[start_index].is_active > 1)
        {
            /* set cache data. */
            ui->cache[count].is_short = 1;
        }
        else
        {
            /* set cache data. */
            ui->cache[count].is_short = 0;
        }
        
        /* utf8 -> ucs2 */
        mmi_chset_convert(
            CHSET_UTF8, 
            CHSET_UCS2,
            (char*)path_buff, 
            (char*)ucs2_buff, 
            SRV_FMGR_PATH_BUFFER_SIZE);

        file_name = mmi_ucs2rchr((CHAR*)ucs2_buff, (U16)L'\\');
        if (file_name == NULL)
        {
         // TODO: add trace!!
            ret = MMI_AUDPLY_PLAYLIST_ERR_LIST_DAMAGED;
            break;
        }

        file_name += 2;     /* skip '\\' */
        ext = mmi_ucs2rchr((CHAR*)file_name, (U16)L'.');

        if (ext == NULL)
        {
            // TODO: add trace!!
            ret = MMI_AUDPLY_PLAYLIST_ERR_LIST_DAMAGED;
            break;
        }
        mmi_ucs2ncpy((CHAR*)ui->cache[count].ext,
            (CHAR*)ext, (U32)mmi_ucs2strlen((CHAR*)ext));
        /* cut off ext. */
        *(ext + 1) = 0;
        *ext = 0;
        mmi_ucs2ncpy((CHAR*)ui->cache[count].filename,
                        (CHAR*)file_name, SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
        if (list->header.index[start_index].is_active > 1)
        {
            mmi_chset_mixed_text_to_ucs2_str(
                    (U8*)ui->cache[count].filename,
                    (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                    (U8*)file_name,
                    PhnsetGetDefEncodingType());
        }
        else
        {
            mmi_ucs2ncpy((CHAR*)ui->cache[count].filename,
                        (CHAR*)file_name, (U32)mmi_ucs2strlen((CHAR*)file_name));
        }  

        start_index++;
        count++;
    }
    if (ret < MMI_AUDPLY_PLAYLIST_NO_ERROR)
    {
        return ret;
    }
    else
    {
        *cached_num = count;
        return count;
    }
}

 
static U8 mmi_audply_playlist_get_path_foreground(UI_string_type fullfilename, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 0;
    U32 read_size = 0;   
    mmi_audply_playlist_block_node_struct block;
    mmi_audply_playlist_struct* list = &(list_cntx.browser_list);
    CHAR utf8[SRV_FMGR_PATH_BUFFER_SIZE];
    FS_HANDLE fd = -1;
    U32 path_size = 0;
    U8 i = 0;
    S32 ret = FS_NO_ERROR;
    U32 next_block = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (browser_now_playing)
    {
        list = &(list_cntx.current_list);
    }
    MMI_ASSERT(list->fs_hdlr >= 0);
    fd = list->fs_hdlr;
    
    next_block = list->header.index[index].offset;
    for (i = 0; i < list->header.index[index].used_block; i++)
    {
        if (!next_block)
        {
            break;
        }
        ret = FS_Seek(fd, next_block, FS_FILE_BEGIN);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
        ret = FS_Read(fd, &block, sizeof(mmi_audply_playlist_block_node_struct), &read_size);

        if (ret < FS_NO_ERROR)
        {
            break;
        }
        else if (read_size != sizeof(mmi_audply_playlist_block_node_struct))
        {
            ret = MMI_AUDPLY_PLAYLIST_ERR_READ_FAILED;
            break;
        }
        else if (block.pattern_begin != AUDPLY_PLAYLIST_BLOCK_PATTERN_1 ||
                block.pattern_end != AUDPLY_PLAYLIST_BLOCK_PATTERN_2)
        {
            ret = MMI_AUDPLY_PLAYLIST_ERR_LIST_DAMAGED;
            break;
        }
        memcpy(&utf8[i * MMI_AUDPLY_BLOCK_DATA_SIZE], &block.data, MMI_AUDPLY_BLOCK_DATA_SIZE);
        next_block = block.next_ptr;
    }
    if (ret < FS_NO_ERROR)
    {
        return 0;
    }
    

    path_size = mmi_chset_convert(
                        CHSET_UTF8,
                        CHSET_UCS2,
                        (char*)utf8, 
                        (char*)fullfilename,
                        SRV_FMGR_PATH_BUFFER_SIZE);
    if (list->header.index[index].is_active == 2)
    {
        result = 2;
    }
    else
    {
        result = 1;
    }
    fullfilename[EOS(path_size)] = 0;    /* make it must be in boundary */
    return result;
}


static U8 mmi_audply_playlist_get_path_background(UI_string_type fullfilename, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 0;
    U32 read_size = 0;   
    mmi_audply_playlist_block_node_struct block;
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    CHAR utf8[SRV_FMGR_PATH_BUFFER_SIZE];
    FS_HANDLE fd = -1;
    U32 path_size = 0;
    U8 i = 0;
    S32 ret = FS_NO_ERROR;
    U32 next_block = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(list->fs_hdlr >= 0);
    fd = list->fs_hdlr;
    
    next_block = list->header.index[index].offset;
    for (i = 0; i < list->header.index[index].used_block; i++)
    {
        if (!next_block)
        {
            break;
        }
        ret = FS_Seek(fd, next_block, FS_FILE_BEGIN);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
        ret = FS_Read(fd, &block, sizeof(mmi_audply_playlist_block_node_struct), &read_size);

        if (ret < FS_NO_ERROR)
        {
            break;
        }
        else if (read_size != sizeof(mmi_audply_playlist_block_node_struct))
        {
            ret = MMI_AUDPLY_PLAYLIST_ERR_READ_FAILED;
            break;
        }
        else if (block.pattern_begin != AUDPLY_PLAYLIST_BLOCK_PATTERN_1 ||
                block.pattern_end != AUDPLY_PLAYLIST_BLOCK_PATTERN_2)
        {
            ret = MMI_AUDPLY_PLAYLIST_ERR_LIST_DAMAGED;
            break;
        }
        
        memcpy(&utf8[i * MMI_AUDPLY_BLOCK_DATA_SIZE], &block.data, MMI_AUDPLY_BLOCK_DATA_SIZE);
        next_block = block.next_ptr;
    }
    if (ret < FS_NO_ERROR)
    {
        return 0;
    }
    

    path_size = mmi_chset_convert(
                        CHSET_UTF8,
                        CHSET_UCS2,
                        (char*)utf8, 
                        (char*)fullfilename,
                        SRV_FMGR_PATH_BUFFER_SIZE);
    if (list->header.index[index].is_active == 2)
    {
        result = 2;
    }
    else
    {
        result = 1;
    }
    fullfilename[EOS(path_size)] = 0;    /* make it must be in boundary */

    return result;
}


static void mmi_audply_playlist_entry_playlist_option_multiple(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U16 nNumofItem = 0;
    U8 *gui_buffer = NULL;
    S32 ret = 0;
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    mmi_audply_dynamic_list_data_struct* ui = &(list_cntx.list_ui);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* unhide all. */
    mmi_frm_unhide_menu_item(MENU_ID_AUDPLY_OPTION_MOVEUP);
    mmi_frm_unhide_menu_item(MENU_ID_AUDPLY_OPTION_MOVEDOWN);
    mmi_frm_unhide_menu_item(MENU_ID_AUDPLY_OPTION_ADD);
    mmi_frm_unhide_menu_item(MENU_ID_AUDPLY_OPTION_PLAY);
#ifdef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
    mmi_frm_unhide_menu_item(MENU_ID_AUDPLY_OPTION_DETAILS);
#endif
    mmi_frm_unhide_menu_item(MENU_ID_AUDPLY_OPTION_REMOVE);
    mmi_frm_unhide_menu_item(MENU_ID_AUDPLY_OPTION_SEND);
    mmi_frm_unhide_menu_item(MENU_ID_AUDPLY_OPTION_USE);

    if (ui->total == 0)
    {
        mmi_frm_hide_menu_item(MENU_ID_AUDPLY_OPTION_MOVEUP);
        mmi_frm_hide_menu_item(MENU_ID_AUDPLY_OPTION_MOVEDOWN);
        mmi_frm_hide_menu_item(MENU_ID_AUDPLY_OPTION_PLAY);
#ifdef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
        mmi_frm_hide_menu_item(MENU_ID_AUDPLY_OPTION_DETAILS);
#endif
        mmi_frm_hide_menu_item(MENU_ID_AUDPLY_OPTION_REMOVE);
        mmi_frm_hide_menu_item(MENU_ID_AUDPLY_OPTION_SEND);
        mmi_frm_hide_menu_item(MENU_ID_AUDPLY_OPTION_USE);
        if (!list_cntx.list_loaded && browser_now_playing)
        {
            mmi_frm_hide_menu_item(MENU_ID_AUDPLY_OPTION_ADD);
        }
    }
    else
    {
        if (ui->total == 1)
        {
            mmi_frm_hide_menu_item(MENU_ID_AUDPLY_OPTION_MOVEUP);
            mmi_frm_hide_menu_item(MENU_ID_AUDPLY_OPTION_MOVEDOWN);
        }
            
        // get highlight item's full path.
        if (ui->total > 0)
        {
            ret = mmi_audply_playlist_get_path(path, ui->highlight);
        	if (ret < 0)
        	{
        		/*GoBackHistory();*/
                //AUDPLY_POPUP_ERROR(ret, NULL);
        		return;
        	}
        }
        
        if (0 < srv_fmgr_types_get_use_option_menu(FMGR_TYPE_ALL, (WCHAR *) path))
        {
            mmi_frm_unhide_menu_item(MENU_ID_AUDPLY_OPTION_SEND);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_AUDPLY_OPTION_SEND);
        }
        
        if (0 < srv_fmgr_types_get_use_option_menu(FMGR_TYPE_ALL, (WCHAR *) path))
        {
            mmi_frm_unhide_menu_item(MENU_ID_AUDPLY_OPTION_USE);
        }
        else
        {
            mmi_frm_hide_menu_item(MENU_ID_AUDPLY_OPTION_USE);
        }
    }
    
    EntryNewScreen(SCR_ID_AUDPLY_OPTION, NULL, mmi_audply_playlist_entry_playlist_option_multiple, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_OPTION);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    nNumofItem = GetNumOfChild_Ext(MENU_ID_AUDPLY_OPTION_MENU_MULTIPLE);
    GetSequenceStringIds_Ext(MENU_ID_AUDPLY_OPTION_MENU_MULTIPLE, nStrItemList);
    SetParentHandler(MENU_ID_AUDPLY_OPTION_MENU_MULTIPLE);

    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*)gIndexIconsImageList,
        LIST_MENU,
        0,
        gui_buffer);
    ClearKeyEvents();
    SetKeyDownHandler(GoBackHistory, KEY_LEFT_ARROW);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


static void mmi_audply_playlist_entry_send(void)
{
    S32 menu_id = 0;
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    mmi_audply_dynamic_list_data_struct* ui = &(list_cntx.list_ui);

    if (!mmi_audply_playlist_get_path(path, ui->highlight))
    {
        GoBackHistory();
        return;
    }
    menu_id = srv_fmgr_types_get_send_option_menu(0, (WCHAR*)path);

    if (menu_id > 0)
    {
        playlist_fwd_option_menu_id = menu_id;
        mmi_audply_playlist_entry_fwd_send_screen();
    }
    else
    {
        GoBackHistory();
    }
}


static void mmi_audply_playlist_entry_use(void)
{
    S32 menu_id = 0;
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    mmi_audply_dynamic_list_data_struct* ui = &(list_cntx.list_ui);

    if (!mmi_audply_playlist_get_path(path, ui->highlight))
    {
        GoBackHistory();
        return;
    }
    menu_id = srv_fmgr_types_get_use_option_menu(0, (WCHAR*)path);

    if (menu_id > 0)
    {
        playlist_fwd_option_menu_id = menu_id;
        mmi_audply_playlist_entry_fwd_use_screen();
    }
    else
    {
        GoBackHistory();
    }
}


static void mmi_audply_playlist_fwd_screen_LSK(void)
{
    U16 current_menu_item_id = 0;
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    mmi_audply_dynamic_list_data_struct* ui = &(list_cntx.list_ui);

    if (!mmi_audply_playlist_get_path(path, ui->highlight))
    {
        GoBackHistory();
        return;
    }
    current_menu_item_id = GetSeqItemId_Ext(playlist_fwd_option_menu_id, playlist_fwd_highlight_index);
    if (!srv_fmgr_types_launch_option((WCHAR*)path, current_menu_item_id))
    {
        DeleteScreenIfPresent(SCR_ID_AUDPLY_OPTION);
        GoBackHistory();
    }
    else
    {
        DeleteScreenIfPresent(SCR_ID_AUDPLY_FWD);
        DeleteScreenIfPresent(SCR_ID_AUDPLY_OPTION);
    }
}

static void mmi_audply_playlist_fwd_highlight_hdlr(S32 index)
{
    playlist_fwd_highlight_index = (U16)index;
}
static void mmi_audply_playlist_entry_fwd_send_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U16 nNumofItem = 0;
    U8 *gui_buffer = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AUDPLY_FWD, NULL, mmi_audply_playlist_entry_fwd_send_screen, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_FWD);

    RegisterHighlightHandler(mmi_audply_playlist_fwd_highlight_hdlr);
    nNumofItem = GetNumOfChild_Ext(playlist_fwd_option_menu_id);
    GetSequenceStringIds_Ext(playlist_fwd_option_menu_id, nStrItemList);
    SetParentHandler(playlist_fwd_option_menu_id);

    ShowCategory15Screen(
        STR_GLOBAL_SEND,
        GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*)gIndexIconsImageList,
        LIST_MENU,
        0,
        gui_buffer);
    ClearKeyEvents();
    SetKeyDownHandler(mmi_audply_playlist_fwd_screen_LSK, KEY_RIGHT_ARROW);
    SetLeftSoftkeyFunction(mmi_audply_playlist_fwd_screen_LSK, KEY_EVENT_UP);
    
    SetKeyDownHandler(GoBackHistory, KEY_LEFT_ARROW);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

static void mmi_audply_playlist_entry_fwd_use_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U16 nNumofItem = 0;
    U8 *gui_buffer = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AUDPLY_FWD, NULL, mmi_audply_playlist_entry_fwd_use_screen, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_FWD);

    RegisterHighlightHandler(mmi_audply_playlist_fwd_highlight_hdlr);
    nNumofItem = GetNumOfChild_Ext(playlist_fwd_option_menu_id);
    GetSequenceStringIds_Ext(playlist_fwd_option_menu_id, nStrItemList);
    SetParentHandler(playlist_fwd_option_menu_id);

    ShowCategory15Screen(
        STR_GLOBAL_USE,
        GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*)gIndexIconsImageList,
        LIST_MENU,
        0,
        gui_buffer);
    ClearKeyEvents();
    SetKeyDownHandler(mmi_audply_playlist_fwd_screen_LSK, KEY_RIGHT_ARROW);
    SetLeftSoftkeyFunction(mmi_audply_playlist_fwd_screen_LSK, KEY_EVENT_UP);
    
    SetKeyDownHandler(GoBackHistory, KEY_LEFT_ARROW);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


static S32 mmi_audply_playlist_write_back_to_file(mmi_audply_playlist_struct* list)
{
    S32 ret = FS_NO_ERROR;
    U32 writed_size = 0;
    U32 to_write_size = 0;
    U32 seek_offset = 0;
    
    do 
    {
        ret = FS_Seek(list->fs_hdlr, 0, FS_FILE_BEGIN);
        if (ret < FS_NO_ERROR)
        {
            break;
        }

        to_write_size = sizeof(mmi_audply_playlist_header_struct);
        ret = FS_Write(list->fs_hdlr, &(list->header), to_write_size, &writed_size);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
        if (to_write_size != writed_size)
        {
            ret = MMI_AUDPLY_PLAYLIST_ERR_WRITE_FAILED;
            break;
        }

        seek_offset = list->header.footer_pattern_offset;
        ret = FS_Seek(list->fs_hdlr, seek_offset, FS_FILE_BEGIN);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
    } while (0);

    if (ret < FS_NO_ERROR)
    {
        FS_Close(list->fs_hdlr);
    }
    else
    {
        S32 fs_ret = FS_NO_ERROR;
        FS_Commit(list->fs_hdlr);
        fs_ret = FS_Close(list->fs_hdlr);
        if (FS_NO_ERROR > fs_ret)
        {
            MMI_ASSERT(FS_INVALID_FILE_HANDLE != FS_ParseFH(list->fs_hdlr));
        }
        else
        {
            list->fs_hdlr = FS_Open(list->path, FS_READ_WRITE);
            MMI_ASSERT(!(list->fs_hdlr < 0));
        }
    }
    
    return ret;
}

#define EDITOR_CODE
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_entry_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;
    U16 title_id = 0;
    U32 input_type = 0;
    S32 limit = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_AUDPLY_EDITOR, NULL, mmi_audply_entry_editor, NULL);

    switch (list_cntx.editor_type)
    {
        case MMI_AUDPLY_EDITOR_NEW:
            input_type = IMM_INPUT_TYPE_SENTENCE;
            title_id = STR_GLOBAL_EDIT;
            limit = SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN;
            break;
        case MMI_AUDPLY_EDITOR_EDIT_URL:
            input_type = IMM_INPUT_TYPE_ENGLISH_SENTENCE_LOWERCASE |
                         INPUT_TYPE_OVERRIDE_DEFAULT |
                         INPUT_TYPE_USE_ONLY_ENGLISH_MODES;
            title_id = STR_GLOBAL_EDIT;
            limit = MMI_AUDPLY_MAX_EDITOR_LEN;
            break;
        case MMI_AUDPLY_EDITOR_RENAME:
            input_type = IMM_INPUT_TYPE_SENTENCE;
            title_id = STR_GLOBAL_RENAME;
            limit = SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN;
            break;
        default:
            GoBackHistory();
            return;
    }

    gui_buffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_EDITOR);
    ShowCategory5Screen(
        title_id,
        GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        input_type,
        (U8*)list_cntx.editor_buffer,
        limit,
        gui_buffer);

    
    SetLeftSoftkeyFunction(mmi_audply_editor_option_entry, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_editor_option_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_editor_option_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[3];
    PU8 gui_buffer = NULL;
    U16 nNumofItem;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list_cntx.editor_type == MMI_AUDPLY_EDITOR_NEW)
    {
        SetHiliteHandler(MENU_ID_AUDPLY_EDITOR_OPTION_DONE, 
                        mmi_audply_highlight_editor_create_playlist);
    }
    else if (list_cntx.editor_type == MMI_AUDPLY_EDITOR_RENAME)
    {
        SetHiliteHandler(MENU_ID_AUDPLY_EDITOR_OPTION_DONE, 
                        mmi_audply_highlight_editor_rename_playlist);
    }
    SetHiliteHandler(MENU_ID_AUDPLY_EDITOR_OPTION_INPUT_METHOD, 
                        mmi_audply_highlight_editor_input_method);
    EntryNewScreen(SCR_ID_AUDPLY_EDITOR_OPTION, NULL, mmi_audply_editor_option_entry, NULL);

    gui_buffer = GetCurrGuiBuffer(SCR_ID_AUDPLY_EDITOR_OPTION);

    nNumofItem = GetNumOfChild(MENU_ID_AUDPLY_EDITOR_OPTION);
    GetSequenceStringIds(MENU_ID_AUDPLY_EDITOR_OPTION, nStrItemList);
    SetParentHandler(MENU_ID_AUDPLY_EDITOR_OPTION);

    ShowCategory159Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*)gIndexIconsImageList,
        1,
        0,
        gui_buffer,
        ExecuteCurrHiliteHandler,
        mmi_audply_editor_close_function);

    if (wgui_inputs_menu_index_in_editor_range() == MMI_FALSE)
    {
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyDownHandler(GoBackHistory, KEY_LEFT_ARROW);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_editor_close_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_editor_close_function(void)
{
    GoBacknHistory(1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_editor_check_name_valid
 * DESCRIPTION
 *  check filename whether is valid.
 * PARAMETERS
 *  CHAR*
 * RETURNS
 *  S32 
 *****************************************************************************/
static S32 mmi_audply_editor_check_name_valid(UI_string_type file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    S32 len = 0;
    S32 i = 0;
    UI_character_type temp_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    CHAR* begin = NULL;
    U32 start_len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2ncpy((CHAR*)temp_name, (CHAR*)file_name, SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
    begin = (CHAR*)temp_name;

    start_len = mmi_ucs2strlen((CHAR*)temp_name);

    /* 1. skip the space in new playlist name. */
    len = mmi_ucs2strlen(begin);
    if (len > 0)
    {
        len = len * 2;

        while (begin[i] == ' ' && begin[i + 1] == 0)
        {
            begin += 2;
            if (i >= len)
            {
                break;
            }
        }
        
        len = mmi_ucs2strlen(begin);
    }
    /* 2. check new playlist name whether is valid. */
    if (len == 0 || begin[0] == '.')
    {
        if (begin[0] == '.')
        {
            ret = MMI_AUDPLY_PLAYLIST_ERR_INVALID_FILENAME;
        }
        else
        {
            if (start_len != 0)
            {
                ret = MMI_AUDPLY_PLAYLIST_ERR_INVALID_FILENAME;
            }
            else
            {
                ret = MMI_AUDPLY_PLAYLIST_ERR_EMPTY_FILENAME;
            }
        }
    }
    else
    {
        while (len > 0)
        {
            len--;
            if ((begin[len << 1] == '/' && begin[(len << 1) + 1] == 0) 
                || (begin[len << 1] == '\\' && begin[(len << 1) + 1] == 0) 
                || (begin[len << 1] == ':' && begin[(len << 1) + 1] == 0)
                || (begin[len << 1] == '*' && begin[(len << 1) + 1] == 0) 
                || (begin[len << 1] == '?' && begin[(len << 1) + 1] == 0) 
                || (begin[len << 1] == '"' && begin[(len << 1) + 1] == 0)
                || (begin[len << 1] == '<' && begin[(len << 1) + 1] == 0) 
                || (begin[len << 1] == '>' && begin[(len << 1) + 1] == 0) 
                || (begin[len << 1] == '|' && begin[(len << 1) + 1] == 0)
                || (begin[len << 1] == '\n' && begin[(len << 1) + 1] == 0))
            {
                ret = MMI_AUDPLY_PLAYLIST_ERR_INVALID_FILENAME;
                break;
            }
        }
    }

    if (ret == 0)
    {
        mmi_ucs2ncpy((CHAR*)file_name, (CHAR*)begin, SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
    }
    return ret;
}




#endif  /* __MMI_AUDPLY_MULTIPLE_LIST__ */

#define PLAYLIST_COMMON_API
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_module_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_audply_playlist_module_init(void)
{
    list_cntx.drv_num = mmi_audply_util_count_optional_drv();
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    memset(&(list_cntx.browser_list), 0, sizeof(mmi_audply_playlist_struct));
    list_cntx.editor_type = 0;
#endif
    memset(&(list_cntx.list_ui), 0, sizeof(mmi_audply_dynamic_list_data_struct));
    memset(&(list_cntx.generate_info), 0, sizeof(mmi_audply_playlist_generate_struct));
    
    if (!list_cntx.list_loaded)
    {
        memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
    }
#if 0//defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
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
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_ui_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_ui_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_cntx.list_ui.highlight = index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_util_count_optional_drv
 * DESCRIPTION
 *  return optional driver number.
 *  check phone memory, memory card, SIM+ and OTG.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_audply_util_count_optional_drv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR drive; 
    U8 count = 0;
#if defined(__OTG_ENABLE__) || defined(__SIM_PLUS__)
    U8 i = 0;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_V_REMOVABLE)) >= 'A') && (drive <= 'Z'))
    {
        list_cntx.drv[count].drv_letter = drive;
        count++;
    }
    
    if (((drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
    {
        list_cntx.drv[count].drv_letter = drive;
        count++;
    }

#ifdef __OTG_ENABLE__
    for (i = 0; i < USB_HOST_MS_SUPPORT_LUN; i++)
    {
        if (((drive = FS_GetDrive(FS_DRIVE_V_EXTERNAL, i + 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
        {
            list_cntx.drv[count].drv_letter = drive;
            count++;
        }
    }
#endif /* __OTG_ENABLE__ */ 

#ifdef __SIM_PLUS__
    for (i = 0; i < 4; i++)
    {
        if (((drive = FS_GetDrive(FS_DRIVE_V_SIMPLUS, i + 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
        {
            list_cntx.drv[count].drv_letter = drive;
            count++;
        }
    }
#endif

#ifdef __MSDC2_SD_MMC__
    if (((drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 2, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
    {
        list_cntx.drv[count].drv_letter = drive;
        count++;
    }    
#endif

    return count;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_path_for_player
 * DESCRIPTION
 *  retrieve file path and name from play list file
 * PARAMETERS
 *  fullfilename        [IN]        
 *  index               [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_audply_playlist_get_path_for_player(UI_string_type fullfilename, S32 index)
{
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
#ifdef __MMI_AUDPLY_WALK_PLAY__
    MMI_BOOL result = MMI_TRUE;
    if (g_audply.play_style == AUDPLY_PLAY_STYLE_BY_FILE_ORDER)
    {
        if (g_audply.walk.state != AUDPLY_WALK_STATE_NONE)
        {
            if (g_audply.walk.state == AUDPLY_WALK_STATE_PREV)
            {
                result = mmi_audply_walk_get_prev((U8*)g_audply.filefullname);
            }
            else
            {
                result = mmi_audply_walk_get_next((U8*)g_audply.filefullname);
            }
            g_audply.walk.state = AUDPLY_WALK_STATE_NONE;
            
            if (result && g_audply.filefullname[0] != 0)
            {
                return (IS_SNAME(g_audply.filefullname) ? 2 : 1);
            }
        }
        mmi_audply_stop_playing();
        return 0;
    }
    else
#endif
    return mmi_audply_playlist_get_path_single(fullfilename, index);
#elif defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    if (!list_cntx.list_loaded)
    {
        return 0;
    }
    return mmi_audply_playlist_get_path_background(fullfilename, index);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_path
 * DESCRIPTION
 *  retrieve file path and name from play list file
 * PARAMETERS
 *  fullfilename        [IN]        
 *  index               [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_audply_playlist_get_path(UI_string_type fullfilename, S32 index)
{
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)   
    if (in_browser_mode)
    {
        if (!browser_now_playing)
        {
            /* run in background. */
            return mmi_audply_playlist_get_path_foreground(fullfilename, index);
        }
        else
        {
            /* run in foreground. */
            return mmi_audply_playlist_get_path_background(fullfilename, index);
        }
    }
    else
    {
        if (list_cntx.list_loaded)
        {
            /* run in background. */
            return mmi_audply_playlist_get_path_background(fullfilename, index);
        }
        else
        {
            return 0;
        }
    }
#elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    return mmi_audply_playlist_get_path_single(fullfilename, index);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_apply_picked_file
 * DESCRIPTION
 *  apply pick index to get full filename and title
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_playlist_apply_picked_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_APPLY_PICKED_FILE, list_cntx.current_list.pick_index, list_cntx.current_list.total);
    #ifndef __MMI_AUDPLY_WALK_PLAY__
    g_audply.is_support_pause = MMI_TRUE;  
    #endif  //__MMI_AUDPLY_WALK_PLAY__
    #ifdef __MMI_AUDPLY_WALK_PLAY__
    if (g_audply.play_style == AUDPLY_PLAY_STYLE_BY_PLAYLIST)
    #endif  //__MMI_AUDPLY_WALK_PLAY__
    {
        if (mmi_audply_playlist_is_empty())
        {
            g_audply.seekable = MMI_FALSE;
            g_audply.need_to_build_cache = MMI_FALSE;

            return MMI_FALSE;
        }
    }
    
#ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    if (list_cntx.current_list.pick_index < 0)
        list_cntx.current_list.pick_index = 0;
#endif

    result = mmi_audply_playlist_get_path_for_player(g_audply.filefullname, list_cntx.current_list.pick_index);   
    
    if (!result)
    {
        g_audply.seekable = MMI_FALSE;
        g_audply.need_to_build_cache = MMI_FALSE;

        return MMI_FALSE;
    }
    else
    {
    	{
		    UI_character_type filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
		    UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
        if (result == 2)    /* if it is a short filename */
        {
		    	UI_character_type wchar_filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
            mmi_audply_extract_filename(wchar_filename, g_audply.filefullname);
            mmi_chset_mixed_text_to_ucs2_str(
                (U8*) filename,
                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                (U8*) wchar_filename,
                g_chset_text_encoding);
        }
        else
        {
            mmi_audply_extract_filename(filename, g_audply.filefullname);
        }
        mmi_audply_split_filename_ext(filename, g_audply.title, ext);
    	}

#if defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
    if(g_audply.widget_callback != NULL)
    {
        g_audply.widget_callback(g_audply.widget_callback_userdata, MMI_WIDGET_PLAYER_MEDIA_CHANGE_CALLBACK, NULL);
    }
#endif
     #ifdef __MMI_NCENTER_SUPPORT__
       mmi_audply_ncenter_update();
	#endif
        mmi_audply_check_whether_build_cache(&g_audply.need_to_build_cache,&g_audply.seekable,g_audply.filefullname);
#if defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
	if (g_audply.lyrics_display &&
	        mmi_audply_is_lyrics_valid() && g_audply.in_main_screen)
	    {
			mmi_audply_prepare_lyrics();

	    }
    #endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
        /* in case there is no right */
    #ifdef __DRM_SUPPORT__
	
        result = mmi_audply_drm_valide_right((PU16)g_audply.filefullname);
        if(result ==2)
        {
            g_audply.seekable = MMI_FALSE;
        }
        g_audply.DRM_consumed = MMI_FALSE;
    #endif
        
    #if defined(MT6223) || defined(MT6223P)
        g_audply.support_A2DP = mmi_audply_check_support_A2DP_or_not(ext);
    #endif
    
        g_audply.seekable = mdi_audio_is_file_seekable(g_audply.filefullname);
        if(!g_audply.seekable)
        {
            g_audply.is_support_pause = MMI_FALSE;
        }
        #ifdef __MMI_AUDPLY_WALK_PLAY__
        else
        {
            g_audply.is_support_pause = MMI_TRUE;
        }
        #endif  //__MMI_AUDPLY_WALK_PLAY__
    
        if (mdi_audio_get_duration(g_audply.filefullname, &(g_audply.duration)) != MDI_AUDIO_SUCCESS)
        {
            g_audply.duration = 0 ;
        }
        mmi_audply_determine_progress_speed();
        
        if (mmi_ucs2cmp((CHAR*)g_audply.filefullname, (CHAR*)g_audply.prev_filefullname))
        {
            g_audply.file_name_identical =MMI_FALSE;
        }
        else
        {
            g_audply.file_name_identical = MMI_TRUE;
        }
    #if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
        mmi_audply_playlist_save_last_index(list_cntx.current_list.pick_index);
    #endif
    
        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
    
        #ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__        
        {
    		S16 error;
        WriteValue(NVRAM_AUDPLY_PLAYLIST_INDEX, &list_cntx.current_list.pick_index, DS_DOUBLE, &error);
        }
        #endif
    
        return MMI_TRUE;
    }
}

void mmi_audply_playlist_display_popup(S32 error_code, FuncPtr callback)
{
    mmi_event_notify_enum event_type = MMI_EVENT_DEFAULT;
    U16 string_id = 0;

    if (error_code > MMI_AUDPLY_PLAYLIST_ERR_BEGIN)
    {
        /* handle file system error code. */
        string_id = srv_fmgr_fs_error_get_string(error_code);
        event_type = (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(error_code);
        /* handle special case. */
        switch (error_code)
        {
            case FS_NO_MORE_FILES:
                string_id = STR_GLOBAL_EMPTY;
                break;
            default:
                break;
        }
    }
    else
    {
    	event_type = MMI_EVENT_FAILURE;
    /* get string id. */
        switch (error_code)
        {
            case MMI_AUDPLY_PLAYLIST_ERR_WRITE_FAILED:
                string_id = STR_ID_AUDPLY_PLAYLIST_ERR_WRITE_FAILED;
                break;
            case MMI_AUDPLY_PLAYLIST_ERR_READ_FAILED:
                string_id = STR_ID_AUDPLY_PLAYLIST_ERR_READ_FAILED;
                break;
            case MMI_AUDPLY_PLAYLIST_ERR_FILE_EXISTS:
                string_id = STR_GLOBAL_FILE_ALREADY_EXISTS;
                break;
            case MMI_AUDPLY_PLAYLIST_ERR_LIST_FULL:  
                string_id = STR_ID_AUDPLY_LIST_FULL;
                break;
            case MMI_AUDPLY_PLAYLIST_ERR_NOT_PLST:
                string_id = STR_GLOBAL_INVALID_FORMAT;
                break;
            case MMI_AUDPLY_PLAYLIST_ERR_WRONG_VER:
                string_id = STR_ID_AUDPLY_PLAYLIST_ERR_WRONG_VERSION;
                break;
            case MMI_AUDPLY_PLAYLIST_ERR_INVALID_PARA:
                string_id = FMGR_FS_PARAM_ERROR_TEXT;
                break;
            case MMI_AUDPLY_PLAYLIST_ERR_INVALID_FILENAME:
                string_id = STR_GLOBAL_INVALID_FILENAME;
                event_type = MMI_EVENT_ERROR;
                break;
            case MMI_AUDPLY_PLAYLIST_ERR_EMPTY_FILENAME:
                string_id = STR_GLOBAL_PLEASE_INPUT_THE_FILENAME;
				event_type = MMI_EVENT_ERROR;
                break;
            case MMI_AUDPLY_PLAYLIST_ERR_CREATE_FAILED:
                string_id = STR_ID_AUDPLY_PLAYLIST_ERR_CREATE_FAILED;
                break;
            case MMI_AUDPLY_PLAYLIST_ERR_EXIST_FILE:
                string_id = STR_GLOBAL_FILE_ALREADY_EXISTS;
				event_type = MMI_EVENT_ERROR;
                break;
            case MMI_AUDPLY_PLAYLIST_ERR_NO_SPACE:
                string_id = STR_GLOBAL_NOT_ENOUGH_MEMORY;
                break;
            case MMI_AUDPLY_PLAYLIST_ERR_LIST_DAMAGED:
                string_id = STR_ID_AUDPLY_PLAYLIST_ERR_DAMAGED;
                break;
            case MMI_AUDPLY_PLAYLIST_ERR_OPEN_FAILED:
                string_id = STR_ID_AUDPLY_PLAYLIST_ERR_OPEN_FAILED;
                break;
            default:
                string_id = STR_ID_AUDPLY_PLAYLIST_ERR_UNKNOWN_ERROR;
                break;        
        }
    }


    if (callback)
    {
        	do {
                mmi_popup_property_struct arg;
                mmi_popup_property_init(&arg);
                arg.callback = mmi_alert_normal_exit_helper;
		if (!g_audply.background_play)
		{
		   arg.parent_id = GRP_ID_AUDPLY_MAIN;
		}
		else
		{
		   arg.parent_id = GRP_ID_ROOT; 
		}
                arg.user_tag = (void *)(callback);
                mmi_popup_display_ext(
                    string_id, 
                    event_type, 
                    &arg);
                }
            while(0);
            

    }
    else
    {

        mmi_popup_display_ext(
            string_id, 
            event_type, 
            NULL);
    }

  if (mmi_frm_group_is_present(GRP_ID_AUDPLY_LIST_ADD))
    {
        mmi_frm_group_close(GRP_ID_AUDPLY_LIST_ADD);
    }
    mmi_frm_group_close(GRP_ID_AUDPLY_OPTION); 
}

void mmi_audply_playlist_pick_random(mmi_audply_playlist_struct* list)
{
    S32 i = 0;
    U32 seek_count = 0;
    
    /* need find an empty slot. */
   if (list->pick_count >= list->total)
    {
        /* reached end of list. */
        mmi_audply_playlist_set_start(-1);  /* reset all context. */
    } 
    i = (list->pick_index + (rand() % list->total) + 1) % list->total;
    
    while (1)
    {
        i = (i + 1) % list->total;
    
        if (IsBitSetOn(i, list->bitset))
        {
            MMI_ASSERT(seek_count < (U32)list->total);
            seek_count++;
        }
        else
        {
            break;
        }
    }
    
    list->pick_index = i;
    list->pick_count++;
    SetBitSet(list->pick_index, list->bitset);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_do_pick
 * DESCRIPTION
 *  pick a song from play list
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_playlist_do_pick(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    S32 result = 0;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_audply_playlist_is_empty())
    {
        return -1;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_PLAYLIST_DO_PICK);

    if (g_audply.repeat_mode == REPEAT_ONE)
    {
        /* pick count and bistset are useless in this time. */
        result = list->pick_index;
    }
    else
    {
        if (g_audply.random_mode)
        {
            if (list->pick_count >= list->total)
            {
                /* reached end of list. */
                mmi_audply_playlist_set_start(-1);	/* reset all context. */
                if (g_audply.repeat_mode == REPEAT_OFF)
                {
                    result = -1;	/* stop! */
                }
                else if (g_audply.repeat_mode == REPEAT_ALL)
                {
                    mmi_audply_playlist_pick_random(list);
                    result = list->pick_index;
                }
                else
                {
					MMI_ASSERT(g_audply.repeat_mode != REPEAT_ONE);
                }
            }
            else
            {
                mmi_audply_playlist_pick_random(list);
				result = list->pick_index;	/* begin from first one. */ 
            }
        }
        else
        {
        	/* "pick_count" is useless when random = OFF. */
			if (list->pick_index >= list->total - 1)
            {
				/* reached end of list. */
                mmi_audply_playlist_set_start(-1);	/* reset all context. */
                #ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
                //repeat all
            	list->pick_index = 0;
            	list->pick_count++;
            	SetBitSet(list->pick_index, list->bitset);
				result = list->pick_index;	/* begin from first one. */ 
                #else  //__MMI_BTD_BOX_UI_STYLE__
                if (g_audply.repeat_mode == REPEAT_OFF)
                {
                    result = -1;	/* stop! */
                }
                else if (g_audply.repeat_mode == REPEAT_ALL)
                {
                	list->pick_index = 0;
                	list->pick_count++;
                	SetBitSet(list->pick_index, list->bitset);
					result = list->pick_index;	/* begin from first one. */ 
                }
                else
                {
					MMI_ASSERT(g_audply.repeat_mode != REPEAT_ONE);
                }
                #endif  //__MMI_BTD_BOX_UI_STYLE__
            }
            else
            {
            	list->pick_index++;
                list->pick_count++;
                SetBitSet(list->pick_index, list->bitset);
				result = list->pick_index;
            }
        }        
	}
	return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_pick_next
 * DESCRIPTION
 *  pick the next song from play list
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_playlist_pick_next(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_AUDPLY_WALK_PLAY__
    if (g_audply.play_style == AUDPLY_PLAY_STYLE_BY_FILE_ORDER)
    {
        g_audply.walk.state = AUDPLY_WALK_STATE_NEXT;
        return -1;
    }
    #endif  //__MMI_AUDPLY_WALK_PLAY__
    if (list->total == 0)
    {
        return -1;
    }

    if (g_audply.random_mode)
    {
        mmi_audply_playlist_pick_random(list);
    }
    else
    {
        /* "pick_count" is useless when random = OFF. */
        if (list->pick_index >= list->total - 1)
        {
            /* reached end of list. */
            mmi_audply_playlist_set_start(-1);	/* reset all context. */
        }

        list->pick_index++;
        list->pick_count++;
        SetBitSet(list->pick_index, list->bitset);
    }        

    return list->pick_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_pick_prev
 * DESCRIPTION
 *  pick the previous song from play list
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_playlist_pick_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_AUDPLY_WALK_PLAY__
    if (g_audply.play_style == AUDPLY_PLAY_STYLE_BY_FILE_ORDER)
    {
        g_audply.walk.state = AUDPLY_WALK_STATE_PREV;
        return -1;
    }
    #endif  //__MMI_AUDPLY_WALK_PLAY__
    if (list->total == 0)
    {
        return -1;
    }


    if (g_audply.random_mode)
    {
        
        mmi_audply_playlist_pick_random(list);
    }
    else
    {
        if (list->pick_index <= 0)
        {
            index = list->total - 1;
        }
        else
        {
            index = list->pick_index - 1;
        }
        mmi_audply_playlist_set_start(index);
        #ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
        mmi_audply_playlist_set_pick_index(list->pick_index);
        #else
        mmi_audply_playlist_set_pick_index(index);
        #endif
    }        

    return list->pick_index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [OUT]
 *  item_index      [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_playlist_get_filename(UI_string_type filename, S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_list_item_info_struct item_info;
    S32 load_index;
    S32 current = 0;
    mmi_audply_dynamic_list_data_struct* list_ui = &(list_cntx.list_ui);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((item_index < list_ui->cache_start_index) ||
        (item_index >= list_ui->cache_end_index))
    {
        /* desired entry in the middle of cache */
        load_index = item_index - (MMI_AUDPLY_LIST_BUFF_SIZE / 2);

        if (load_index < 0)
        {
            load_index = 0;
        }

        if (0 > mmi_audply_playlist_load_cache((U16)load_index))
        {
            return MMI_FALSE;
        }     
    }
    current = item_index - list_ui->cache_start_index;
    memcpy(&item_info, 
            &(list_ui->cache[current]), 
            sizeof(mmi_audply_list_item_info_struct));
    
    mmi_ucs2ncpy((CHAR*)filename, (CHAR*)item_info.filename, SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
    
    if (item_info.ext[0] != 0)    /* if its ext is not blank */
    {
        if (!mmi_ucs2rchr((CHAR*)item_info.ext, (U16)L'.'))
        {
            mmi_ucs2cat((CHAR*)filename, (CHAR*)L".");
        }
        mmi_ucs2cat((CHAR*)filename, (CHAR*)item_info.ext);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_total
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
S32 mmi_audply_playlist_get_total(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (mmi_audply_playlist_is_empty())
    {
        return 0;
    }
    else
    {
        return list_cntx.current_list.total;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_reset_ui_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
S32 mmi_audply_playlist_get_current_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (mmi_audply_playlist_is_empty())
    {
        return -1;
    }
    else
    {
        return list_cntx.current_list.pick_index;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_current_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_playlist_get_current_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return list_cntx.list_ui.highlight;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_set_pick_index
 * DESCRIPTION
 *  seek play list index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_set_pick_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list->pick_index = index;
    if (!IsBitSetOn(index, list->bitset))
    {
        SetBitSet(index, list->bitset);
        list->pick_count++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_set_start
 * DESCRIPTION
 *  seek play list index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_set_start(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    #ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1] = {0};
    S32 fs_ret;
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(list->bitset, 0, MMI_AUDPLY_MAX_BITSET_SIZE);
    list->pick_index = index;
    list->pick_count = 0;
	/* reset play fail counter. */
    g_audply.successive_fail_num = 0;
#ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    //play next playlist
    if (list_cntx.file_num > 1 && ((g_audply_main_selected_button == AUDPLY_MAIN_PREV && index == list->total-1) || 
        (g_audply_main_selected_button == AUDPLY_MAIN_NEXT && index == -1)))
    {
        S16 error;
        
        if (g_audply_main_selected_button == AUDPLY_MAIN_NEXT && list_cntx.file_index < list_cntx.file_num-1)
        {
            list_cntx.file_index++;
            kal_wsprintf(path, "%c:\\%w\\%w_%d", (CHAR)g_audply.present_list, MMI_AUDPLY_DEFAULT_FOLDER, MMI_AUDPLY_DEFAULT_LIST_NAME_PREFIX, list_cntx.file_index);
            fs_ret = FS_GetAttributes((PU16)path);
            
            if (fs_ret < FS_NO_ERROR)
            {
                //if last file is not available, change to file 0
                list_cntx.file_index = 0;
            }
        }
        else if (g_audply_main_selected_button == AUDPLY_MAIN_PREV)
        {
            if (list_cntx.file_index > 0)
            {
                list_cntx.file_index--;
            }
            else
            {
                //if last file is not available, change to second last
                if (!list_cntx.is_genning_playlist)
                {
                    list_cntx.file_index = list_cntx.file_num - 1;
                }
                else if (list_cntx.file_num > 2)
                {
                    list_cntx.file_index = list_cntx.file_num - 2;
                }
                else
                {
                    list_cntx.file_index = 0;
                }
            }
        }
        else
        {
            list_cntx.file_index = 0;
        }
        
        kal_wsprintf(path, "%c:\\%w\\%w_%d", (CHAR)g_audply.present_list, MMI_AUDPLY_DEFAULT_FOLDER, MMI_AUDPLY_DEFAULT_LIST_NAME_PREFIX, list_cntx.file_index);
        mmi_ucs2ncpy((CHAR*)list_cntx.current_list.path, (CHAR*)path, (SRV_FMGR_PATH_MAX_LEN+1));
        //save file index to NVRAM
        WriteValue(NVRAM_AUDPLY_PLAYLIST_FILE_INDEX, &list_cntx.file_index, DS_BYTE, &error);
        
        if (!list_cntx.is_genning_playlist && list_cntx.file_index == list_cntx.file_num-1)
        {
            list_cntx.current_list.total = list_cntx.num_of_last_file;
        }
        else
        {
            list_cntx.current_list.total = MMI_AUDPLY_MAX_PICK_PER_SLICE - 1;
        }

        if (g_audply_main_selected_button == AUDPLY_MAIN_PREV)
        {
            list->pick_index = list_cntx.current_list.total - 1;
        }
        
        //MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAYLIST_SET_START, list_cntx.file_index, fs_ret);
    }
    //update count of last list
    if (!list_cntx.is_genning_playlist && list_cntx.file_index == list_cntx.file_num-1)
    {
        list_cntx.current_list.total = list_cntx.num_of_last_file;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAYLIST_SET_START, index, list_cntx.file_index, list_cntx.file_num, fs_ret);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_fmgr_notify_hdlr
 * DESCRIPTION
 *  seek play list index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_fmgr_notify_hdlr(CHAR drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    {
        if (list_cntx.list_loaded && 
            mmi_audply_get_current_list_drv() == drv)
        {
            mmi_audply_stop_playing();
            memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
            list_cntx.list_loaded = MMI_FALSE;

            mmi_audply_playlist_reset_ui_cntx();
            
            /*mmi_audply_clear_play_seconds();
            g_audply.seekable = MMI_FALSE;
            g_audply.need_to_build_cache = MMI_FALSE;
            g_audply.title[0] = 0;
            g_audply.filefullname[0] = 0;*/
            mmi_audply_reset_context();
            g_mmi_audply_init_done = MMI_FALSE;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_list_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_update_list_hdlr(const CHAR* old_path, const CHAR* new_path, U8 action_type, MMI_BOOL is_folder)
{
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
#if defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type list_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    S32 ret = FS_NO_ERROR;
    CHAR current_drv = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_UPDATE_LIST_HDLR,old_path==NULL,new_path==NULL,action_type,is_folder);
    /* check necessarily parameter. */
    if (old_path == NULL)
    {
        return;
    }

    /* check compile option. */
    
    if (g_audply.list_auto_gen)
    {
    #ifndef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
        return;
    #endif 
    }
    else    /* !list_auto_gen */
    {
    #ifndef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__
        return;
    #endif 
    }

    if (g_mmi_audply_init_done)
    {
        current_drv = (CHAR)g_audply.present_list;
    }
    else
    {
        current_drv = (CHAR)old_path[0];
    }
    ret = mmi_audply_playlist_check_and_set_default_playlist_path(
                                            list_path, (CHAR)current_drv);
    if (ret < FS_NO_ERROR)
    {
        return;
    }   
    
    /* check the modified file/folder whether about present list. start */
    if (mmi_ucs2nicmp((CHAR*)old_path, (CHAR*)list_path, 1) && (action_type != AUDPLY_ACTION_COPY && action_type != AUDPLY_ACTION_MOVE))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_1);
        /*current path's driver id is different with present list!*/
        return;
    }
    else if (FS_GetAttributes((PU16)list_path) < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_2);
        /*no list file exist!*/
        return;
    }

    /* init update_cntx begin */
    memset(&update_cntx, 0, sizeof(audply_auto_update_struct));
    
    mmi_ucs2ncpy((CHAR*)update_cntx.old_path, (CHAR*)old_path, (U32)mmi_ucs2strlen((CHAR*)old_path));
    if (new_path != NULL)
    {
        mmi_ucs2ncpy((CHAR*)update_cntx.new_path, (CHAR*)new_path, (U32)mmi_ucs2strlen((CHAR*)new_path));
		/* prepare file path. */
		if (!is_folder)
		{
			CHAR* last_backlash = NULL;
			last_backlash = mmi_ucs2rchr((CHAR*)update_cntx.new_path, (U16)L'\\');
			MMI_ASSERT(last_backlash != NULL);
			
			if (2 > mmi_ucs2strlen((CHAR*)last_backlash))
			{
				last_backlash = mmi_ucs2rchr((CHAR*)update_cntx.old_path, (U16)L'\\');
				MMI_ASSERT(last_backlash != NULL);
				last_backlash += 2;
				mmi_ucs2cat((CHAR*)update_cntx.new_path, (CHAR*)last_backlash);
			}
		}   
	}

    
    update_cntx.temp_file = -1;
    update_cntx.present_list = -1;
    update_cntx.counter = 0;
    update_cntx.deleted = 0;
    update_cntx.offset = 0;
    update_cntx.old_path_len = (U32)mmi_ucs2strlen((CHAR*)update_cntx.old_path);
    update_cntx.action_type = action_type;
    update_cntx.is_folder = is_folder;
    memset(&cache_cntx, 0, sizeof(audply_auto_update_cache_struct));
    /* init update_cntx end  */
    
    /* do check if action from FMGR is about audio player list */
    if (is_folder)
    {
        need_refresh_list = MMI_TRUE;
    }
    else
    {
        if (need_refresh_list == MMI_TRUE)
        {
            return;
        }
        if (action_type == AUDPLY_ACTION_COPY || action_type == AUDPLY_ACTION_MOVE)
        {
            UI_character_type my_music_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
            if (g_mmi_audply_init_done)
            {
                kal_wsprintf(my_music_path, "%c:\\", (CHAR)g_audply.present_list);
            }
            else
            {
                kal_wsprintf(my_music_path, "%c:\\", (CHAR)update_cntx.old_path[0]);
            }
            mmi_ucs2cat((CHAR*)my_music_path, (CHAR*)MUSIC_FOLDER);
           #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
            if (g_audply.list_auto_gen &&
                !mmi_ucs2nicmp((CHAR*)update_cntx.new_path, (CHAR*)my_music_path, (U32)mmi_ucs2strlen((CHAR*)my_music_path)) &&
                mmi_audply_is_audio_path((UI_string_type)update_cntx.new_path))
            {
                need_refresh_list = MMI_TRUE;
                return;
            }
            #endif
        }
        if (0 < mmi_audply_update_does_record_in_list(list_path, (CHAR*)update_cntx.old_path))
        {
            if (action_type == AUDPLY_ACTION_RENAME)
            {
                mmi_audply_update_rename_folder(MMI_FALSE);
            }
            else if (action_type == AUDPLY_ACTION_DELETE)
            {
                mmi_audply_update_delete_folder(MMI_FALSE);
            }
            else if (action_type == AUDPLY_ACTION_MOVE)
            {
                action_type = AUDPLY_ACTION_DELETE;
                mmi_audply_update_delete_folder(MMI_FALSE);
            }
        }
    }
#endif /*defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__) */
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */
}




/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_is_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_playlist_is_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;
    U16 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    do 
    {
        ret = FS_GetAttributes((PU16)list_cntx.current_list.path);
        if (i > 30)
        {
            break;
        }
        else
        {
            i++;
        }
    } while (ret == FS_DEVICE_BUSY);
    
    if (0 > ret)
    {
        list_cntx.list_loaded = MMI_FALSE;
    }
    else
    {
    #if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
        return MMI_TRUE;
    #endif
    }

    return list_cntx.list_loaded;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_is_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_playlist_is_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_audply_playlist_is_valid())
    {
        if (list_cntx.current_list.total > 0)
        {
            ret = MMI_FALSE;
        }
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_entry_playlist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_entry_playlist(void)
{    
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    browser_now_playing = MMI_TRUE;
    if (!list_cntx.list_loaded)
    {
        memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
        mmi_audply_playlist_entry_playlist_multiple();
    }
    else
    {
        browser_now_playing = MMI_TRUE;
        mmi_audply_playlist_entry_playlist_multiple();
    }
#elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    mmi_audply_playlist_entry_playlist_single();
#endif
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
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_check_whether_build_cache
 * DESCRIPTION
 *  check if the file type needs to build cache to seek
 * PARAMETERS
 *  need_to_build_cache [OUT]
 *  seekable [OUT]
 *  ext     [IN]        
 * RETURNS
 * void
 *****************************************************************************/
void mmi_audply_check_whether_build_cache(
        MMI_BOOL *need_to_build_cache, MMI_BOOL *seekable, const UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U32 ext_len = 0;
    CHAR* extension_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extension_p = mmi_ucs2rchr((const CHAR*)path, L'.');

    if (extension_p == NULL)
    {
	*need_to_build_cache = MMI_FALSE;
	*seekable = MMI_TRUE; 
	return;
    }
    else
    {
	extension_p += 2;
		ext_len = mmi_ucs2strlen((CHAR*)extension_p);
    }

    for (i = 0; i < NEED_TO_BUILD_CACHE_NUM; i++)
    {
        if (ext_len == mmi_ucs2strlen((CHAR*)audio_file_exts[i]))
        {
            if (!mmi_ucs2icmp((CHAR*)extension_p, (CHAR*)audio_file_exts[i]))
            {
            #ifdef __DRM_V02__
                if (i == ODF_FORMAT_FOR_CACHE)
                {
                    UI_character_type ext_in_odf[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
                    PU8 ext_name_p = NULL; 
                    
                    ext_name_p = (PU8)DRM_get_content_ext(0, (PU16)g_audply.filefullname);
                    if (ext_name_p != NULL)
                    {
                        memset(ext_in_odf, 0, sizeof(ext_in_odf));
                        mmi_asc_n_to_ucs2((CHAR*)ext_in_odf, (CHAR*)ext_name_p, strlen((const char *)ext_name_p));

                        ext_len = mmi_ucs2strlen((CHAR*)ext_in_odf);

                        for (i = 0; i < NEED_TO_BUILD_CACHE_NUM; i++)
                        {
                            if (ext_len == mmi_ucs2strlen((CHAR*)audio_file_exts[i]))
                            {
                                if (!mmi_ucs2icmp((CHAR*)ext_in_odf, (CHAR*)audio_file_exts[i]))
                                {
                                    *need_to_build_cache = MMI_TRUE;
                                    *seekable = MMI_TRUE;
                                    return;
                                }
                            }
                        }
                    }
                }
                else
            #endif /*__DRM_V02__*/                
                {
                    *need_to_build_cache = MMI_TRUE;
                    *seekable = MMI_TRUE;
                    return;
                }
            }
        }
    }

    *need_to_build_cache = MMI_FALSE;
    *seekable = MMI_TRUE; 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lookup_audio_file_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ext        [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_lookup_audio_file_format(const UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U32 ext_len = 0;
    UI_character_type file_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ext == NULL || 0 == (ext_len = mmi_ucs2strlen((CHAR*)ext)))
    {
        return -1;
    }
    /* skip ".". */
    {
        CHAR* dot = mmi_ucs2rchr((CHAR*)ext, (U16)L'.');
        if (dot)
        {
            dot += 2;
        }
        else
        {
            dot = (CHAR*)ext;
        }
        mmi_ucs2ncpy((CHAR*)file_ext, (CHAR*)dot, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
        ext_len = mmi_ucs2strlen((CHAR*)dot);
    }
    
    for (i = 0; i < audio_file_exts[i][0]; i++)
    {
        if (ext_len == mmi_ucs2strlen((CHAR*)audio_file_exts[i]))
        {
            if (!mmi_ucs2icmp((CHAR*)file_ext, (CHAR*)audio_file_exts[i]))
            {   
                return i;
            }
        }
    }

    return -1;
}

#if defined(MT6223) || defined(MT6223P)
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_check_support_A2DP_or_not
 * DESCRIPTION
 *  check if the file type supports A2DP
 * PARAMETERS
 *  ext     [IN]        
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_check_support_A2DP_or_not(const UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U32 ext_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ext == NULL || 0 == (ext_len = mmi_ucs2strlen((CHAR*)ext)))
    {
        return MMI_FALSE;
    }
    for (i = 0; i < audio_file_not_support_a2dp_exts[i][0] ; i++)
    {
        if (ext_len == mmi_ucs2strlen((CHAR*)audio_file_not_support_a2dp_exts[i]))
        {
            if (!mmi_ucs2icmp((CHAR*)ext, (CHAR*)audio_file_not_support_a2dp_exts[i]))
            {   
                return MMI_FALSE;
            }
        }
    }
    return MMI_TRUE;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_extract_ext
 * DESCRIPTION
 *  extract filename extension
 * PARAMETERS
 *  filename        [IN]        
 *  ext             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_extract_ext(const UI_string_type filename, UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* ext_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL)
    {
        *ext = 0;
    }
    else
    {
        ext_ptr = mmi_ucs2rchr((CHAR*)filename, (U16)L'.');

        if (ext_ptr == NULL)
        {
            *ext = 0;
        }
        else
        {
            ext_ptr += 2;
            mmi_ucs2ncpy((CHAR*)ext, (CHAR*)ext_ptr, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_split_filename_ext
 * DESCRIPTION
 *  split filename into two parts: name and extension
 * PARAMETERS
 *  filename                    [IN]        
 *  filename_without_ext        [IN]        
 *  ext                         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_split_filename_ext(const UI_string_type filename, UI_string_type filename_without_ext, UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* dot = NULL;
    U16 size;
//    U8 temp[(SRV_FMGR_PATH_MAX_LEN+1) + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SHOW_FILE_EXT__
    mmi_ucs2ncpy((CHAR*)filename_without_ext, (CHAR*)filename, ((MAX_SUBMENU_CHARACTERS)));
    size = MAX_SUBMENU_CHARACTERS;
#else
    mmi_ucs2ncpy((CHAR*)filename_without_ext, (CHAR*)filename, ((MAX_SUBMENU_CHARACTERS - SRV_FMGR_PATH_MAX_FILE_EXT_LEN)));
    size = MAX_SUBMENU_CHARACTERS - SRV_FMGR_PATH_MAX_FILE_EXT_LEN;
#endif 
    dot =(WCHAR*)mmi_ucs2rchr((CHAR*)filename, (U16)L'.');
    if (dot && ((kal_wstrlen(filename)-kal_wstrlen(dot)) < size))
    {
    dot =(WCHAR*)mmi_ucs2rchr((CHAR*)filename_without_ext, (U16)L'.');
    if (dot)
    {
        *dot = 0;
    }
    }
    
    dot =(WCHAR*)mmi_ucs2rchr((CHAR*)filename, (U16)L'.');
    if (dot == NULL)
    {
        *ext = 0;
    }
    else
    {
        mmi_ucs2ncpy((CHAR*)ext, (CHAR*)(dot + 1), SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
//        *(dot + 1) = 0;
//        *dot = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_extract_filename
 * DESCRIPTION
 *  get filename without path
 * PARAMETERS
 *  filename            [IN]        
 *  fullfilename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_extract_filename(UI_string_type filename, const UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* filename_ptr = mmi_ucs2rchr((CHAR*)path, (U16)(L'\\'));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename_ptr == NULL)
    {
        *filename = 0;
    }
    else
    {
        mmi_ucs2ncpy((CHAR*)filename, (CHAR*)(filename_ptr + 2), SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_does_file_exist
 * DESCRIPTION
 *  check whether does a file exist
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_does_file_exist(const UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_GetAttributes((PU16)path) < 0)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_is_any_file_selected
 * DESCRIPTION
 *  check does any song is selected
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_is_any_file_selected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_audply_playlist_is_empty() &&
        list_cntx.current_list.pick_index >= 0)
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
 *  mmi_audply_is_audio_path
 * DESCRIPTION
 *  check a path whether is an audio path
 * PARAMETERS
 *  path        [IN]
 * RETURNS
 *  MMI_BOOL        
 *****************************************************************************/
MMI_BOOL mmi_audply_is_audio_path(const UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* dot = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)
    {
        return MMI_FALSE;
    }
   
    dot = mmi_ucs2rchr((CHAR*)path, (U16)L'.');

    if (dot != NULL)
    {
        dot += 2;
        if (-1 == mmi_audply_lookup_audio_file_format((UI_string_type)dot))
        {
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_current_list_drv
 * DESCRIPTION
 *  get current playlist driver.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_audply_get_current_list_drv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    if (mmi_audply_playlist_is_valid())
    {
        return (U8)(list_cntx.current_list.path[0]);
    }
    else
#elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    if (FS_GetDevStatus(g_audply.preferred_list, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
    {
        return g_audply.preferred_list;
    }
    else
#endif
    {
        return (U8)SRV_FMGR_PUBLIC_DRV;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_reset_ui_cntx
 * DESCRIPTION
 *  reset list ui struct.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_reset_ui_cntx(void)
{
    memset(&(list_cntx.list_ui), 0, sizeof(mmi_audply_dynamic_list_data_struct));
}

void mmi_audply_playlist_usb_plug_in_hdlr(void)
{
	if(mmi_audply_is_playing())
	{
    mmi_audply_do_stop_action(MMI_TRUE); 
	}
    
    /* USB plugin during generate. */

    if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN,MMI_FRM_NODE_ALL_FLAG) || SCR_ID_AUDPLY_WAITSCREEN == mmi_frm_scrn_get_active_id())
    {
        //StopTimer(AUDPLY_PROCESS_ADD_FILE_TIMER);
        mmi_audply_playlist_generate_cancel_hdlr();
        mmi_frm_scrn_close_active_id();
        mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
        mmi_frm_group_close(GRP_ID_AUDPLY_LIST_BROWSER);
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
        mmi_frm_group_close(GRP_ID_AUDPLY_MAIN);
        mdi_audio_resume_background_play();
    }
	/*mmi_audply_clear_play_seconds();
	g_audply.duration = 0;
	g_audply.title[0] = 0;
    g_audply.filefullname[0] = 0;*/
    need_reload_list = MMI_TRUE;
    mmi_audply_reset_context();
    
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)   
    if (list_cntx.list_loaded)
    {
        /*
        **  need write list back if list loading when usb plug-in.
        */
        if (in_browser_mode)
        {
            if (browser_now_playing)
            {
                mmi_audply_playlist_write_back_to_file(&(list_cntx.current_list));
                FS_Close(list_cntx.current_list.fs_hdlr);
            }
            else
            {
                mmi_audply_playlist_write_back_to_file(&(list_cntx.browser_list));
                FS_Close(list_cntx.browser_list.fs_hdlr);
            }
        }
        else
        {
            mmi_audply_playlist_write_back_to_file(&(list_cntx.current_list));
            FS_Close(list_cntx.current_list.fs_hdlr);            
        }
    }
    else
    {
        if (in_browser_mode)
        {
            mmi_audply_playlist_write_back_to_file(&(list_cntx.browser_list));
            FS_Close(list_cntx.browser_list.fs_hdlr);
        }
    }
#endif

#ifdef __MMI_AUDPLY_WALK_PLAY__
    mmi_audply_walk_search_cancel_hdlr();
#endif
}


void mmi_audply_playlist_usb_plug_out_hdlr(void)
{
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    if (g_mmi_audply_init_done)
    {
        mmi_audply_playlist_init();
        if (mmi_audply_playlist_pick_next() >= 0)
        {
            mmi_audply_playlist_apply_picked_file();
        }
    }
    #ifdef __MMI_AUDPLY_WALK_PLAY__
    g_audply.walk.auto_walk_done = MMI_FALSE;
	mmi_audply_cache_do_validation();
    #endif  //__MMI_AUDPLY_WALK_PLAY__
#elif defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    if (list_cntx.list_loaded)
    {
        S32 ret = 0;
        mmi_ucs2ncpy((CHAR*)list_cntx.editor_buffer, (CHAR*)list_cntx.current_list.path, (SRV_FMGR_PATH_MAX_LEN+1));
        ret = mmi_audply_playlist_open_internal(list_cntx.editor_buffer, &(list_cntx.browser_list));

        if (ret < 0)
        {
            /* playlist file damaged, replaced or etc... */
            list_cntx.list_loaded = MMI_FALSE;
            g_mmi_audply_init_done = MMI_FALSE;
            
            /* clear screen. */
            /*mmi_audply_clear_play_seconds();
            g_audply.seekable = MMI_FALSE;
            g_audply.need_to_build_cache = MMI_FALSE;
            g_audply.title[0] = 0;
            g_audply.filefullname[0] = 0;*/
            mmi_audply_reset_context();
            if (g_audply.in_audio_player == MMI_FALSE)
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_AUDPLY);
            }
        }
        else
        {
            /* reset fs handler in current list cntx with new handler. */
            list_cntx.current_list.fs_hdlr = list_cntx.browser_list.fs_hdlr;
            /* check whether is the same file. */
            ret = memcmp(&(list_cntx.current_list.header), &(list_cntx.browser_list.header), sizeof(mmi_audply_playlist_header_struct));

            if (ret != 0)
            {
                /* playlist file damaged, replaced or etc... */
                list_cntx.list_loaded = MMI_FALSE;
                g_mmi_audply_init_done = MMI_FALSE;
                
                /* clear screen. */
                /*
                mmi_audply_clear_play_seconds();
                g_audply.seekable = MMI_FALSE;
                g_audply.need_to_build_cache = MMI_FALSE;
                g_audply.title[0] = 0;
                g_audply.filefullname[0] = 0;
                */
               mmi_audply_reset_context(); 
                if (g_audply.in_audio_player == MMI_FALSE)
                {
                    mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_AUDPLY);
                }
                FS_Close(list_cntx.current_list.fs_hdlr);
                memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
                memset(&(list_cntx.browser_list), 0, sizeof(mmi_audply_playlist_struct));
            }
            else
            {
                /* reopen is OK! */
                memset(&(list_cntx.browser_list), 0, sizeof(mmi_audply_playlist_struct));
            }
        }
    }
#endif
}

void mmi_audply_playlist_msdc_plug_out_hdlr(U8 drv_num, PU8 drv_list)
{
    U8 i = 0;
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    for (i = 0; i < drv_num; i++)
    {
#ifndef __MMI_AUDPLY_WALK_PLAY__
        if (g_audply.preferred_list == drv_list[i] &&
            g_audply.present_list == (U8)drv_list[i])
#endif
    {
    	mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
        /* in generate process. */
        if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN) || SCR_ID_AUDPLY_WAITSCREEN == mmi_frm_scrn_get_active_id())
        {
            StopTimer(AUDPLY_PROCESS_ADD_FILE_TIMER);
            mmi_audply_playlist_generate_cancel_hdlr();

            mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);

            //DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN);
        }  
        
        /* switch present list to PHONE */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_CARD_PLUG_OUT);
        
        g_audply.present_list = (U8)SRV_FMGR_PUBLIC_DRV;
        need_reload_list = MMI_TRUE;
        StopTimer(AUDPLY_PROCESS_ADD_FILE_TIMER);
        if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN_REMOVE))
    		{
      	    mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN_REMOVE);
    	  }
        memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
        g_audply.duration = 0;
        if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {

             mmi_frm_node_struct new_node_info;
                new_node_info.id = SCR_ID_AUDPLY_LIST_BROWSER;
                new_node_info.entry_proc = (mmi_proc_func)mmi_audply_playlist_entry_playlist_single;
                mmi_frm_scrn_replace (GRP_ID_AUDPLY_LIST_BROWSER, SCR_ID_AUDPLY_LIST_BROWSER, &new_node_info);

           
        }
        if (FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
	    {
	      
	        mmi_frm_group_close(GRP_ID_AUDPLY_MAIN);

	    }   
            
        break;
        }
    }
    
    #ifdef __MMI_AUDPLY_WALK_PLAY__
    mmi_audply_walk_search_cancel_hdlr();
    #endif  //__MMI_AUDPLY_WALK_PLAY__
#elif defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    for (i = 0; i < drv_num; i++)
    {
        if (g_audply.preferred_list == drv_list[i] &&
        FS_GetDevStatus(g_audply.preferred_list, FS_MOUNT_STATE_ENUM) < 0)
    {
        FS_Close(list_cntx.current_list.fs_hdlr);
        memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
        mmi_audply_playlist_reset_ui_cntx();
        g_mmi_audply_init_done = MMI_FALSE;
	mmi_audply_do_stop_action(MMI_TRUE);			
        memset(g_audply.title, 0, sizeof(UI_character_type)*(SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1));
        g_audply.preferred_list = SRV_FMGR_PUBLIC_DRV;
        HistoryReplace(SCR_ID_AUDPLY_LISTMGR, 
                SCR_ID_AUDPLY_LISTMGR, mmi_audply_playlist_entry_listmgr);
        if (mmi_frm_group_is_present(GRP_ID_AUDPLY_LISTMGR) && !mmi_frm_group_is_present(GRP_ID_AUDPLY_SETTINGS))
        {
            //mmi_frm_group_close_active_id();
            DeleteUptoScrID(SCR_ID_AUDPLY_LISTMGR);
        }
    }
        
        if (mmi_audply_get_current_list_drv() == (U8)drv_list[i])
    {
        /* in generate process. */
        if (IsScreenPresent(SCR_ID_AUDPLY_WAITSCREEN) || SCR_ID_AUDPLY_WAITSCREEN == GetActiveScreenId())
        {
            StopTimer(AUDPLY_PROCESS_ADD_FILE_TIMER);
            mmi_audply_playlist_generate_cancel_hdlr();
            DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN);
            //DeleteScreenIfPresent(SCR_ID_AUDPLY_LIST_BROWSER);
            DeleteScreenIfPresent(SCR_ID_AUDPLY_OPTION);
        }  
         
        /* Playlist is in card. stop playing. Clear list info in memory. */
        if (list_cntx.list_loaded)
        {
            list_cntx.list_loaded = MMI_FALSE;


            FS_Close(list_cntx.current_list.fs_hdlr);
            memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
            mmi_audply_playlist_reset_ui_cntx();
            g_mmi_audply_init_done = MMI_FALSE;

            /* browser_now_playing */
            if (browser_now_playing)
            {
                if (IsScreenPresent(SCR_ID_AUDPLY_MAIN))
                {
                    DeleteScreenIfPresent(SCR_ID_AUDPLY_OPTION);
                    DeleteScreenIfPresent(SCR_ID_AUDPLY_LIST_BROWSER);
                    DeleteScreenIfPresent(SCR_ID_AUDPLY_MAIN);
                }
                else if (IsScreenPresent(SCR_ID_AUDPLY_LISTMGR))
                {
                    DeleteScreenIfPresent(SCR_ID_AUDPLY_OPTION);
                    DeleteScreenIfPresent(SCR_ID_AUDPLY_LIST_BROWSER);
                }
                else
                {
                    /* error case. */
                }
            }
        }
            break;
    }
        else if (list_cntx.browser_list.path[0] == (UI_character_type)drv_list[i] &&
             in_browser_mode)
    {
        if (browser_now_playing)
        {
            /* this case should be handled in above code. */
        }
        else
        {
            FS_Close(list_cntx.browser_list.fs_hdlr);
            memset(&(list_cntx.browser_list), 0, sizeof(mmi_audply_playlist_struct));
            mmi_audply_playlist_reset_ui_cntx();
            /* need delete up to list manager if it exist. */
            if (IsScreenPresent(SCR_ID_AUDPLY_LISTMGR))
            {
                DeleteScreenIfPresent(SCR_ID_AUDPLY_OPTION);
                DeleteScreenIfPresent(SCR_ID_AUDPLY_LIST_BROWSER);
            }
            else
            {
                /* error case. */
            }
        }
            break;
        }
    }
#endif
}
    
void mmi_audply_playlist_msdc_plug_in_hdlr(U8 drv_num, PU8 drv_list)
{
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    U8 i = 0;

    for (i = 0; i < drv_num; i++)
    {
        if (g_audply.preferred_list == (U8)drv_list[i] && 
        g_audply.present_list == (U8)SRV_FMGR_PUBLIC_DRV)
    {
        /* switch present list to CARD */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_CARD_PLUG_IN);
            g_audply.present_list = (U8)drv_list[i];
        #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
        if (g_audply.list_auto_gen)
        {
            need_refresh_list = MMI_TRUE;
        }
        else
        #endif
        {
            need_reload_list = MMI_TRUE;
        }
        memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
        if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_frm_node_struct new_node_info;
                new_node_info.id = SCR_ID_AUDPLY_LIST_BROWSER;
                new_node_info.entry_proc = (mmi_proc_func)mmi_audply_playlist_entry_playlist_single;
                mmi_frm_scrn_replace (GRP_ID_AUDPLY_LIST_BROWSER, SCR_ID_AUDPLY_LIST_BROWSER, &new_node_info);

            /*HistoryReplace(
                SCR_ID_AUDPLY_LIST_BROWSER, 
                SCR_ID_AUDPLY_LIST_BROWSER, 
                mmi_audply_playlist_entry_playlist_single);*/
        }
       
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
        //DeleteScreenIfPresent(SCR_ID_AUDPLY_OPTION);
            break;
        }
    }
#elif defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    /* do nothing. */
#endif
#ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    mmi_audply_playlist_set_default_playlist_path();
#endif

#ifdef __MMI_AUDPLY_WALK_PLAY__    
    g_audply.walk.auto_walk_done = MMI_FALSE;
	mmi_audply_cache_do_validation();
#endif

}
#if 0 
/* under construction !*/
/* under construction !*/
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
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
#elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif
void mmi_audply_playlist_post_format_hdlr(CHAR drv)
{
    if ((U8)drv == mmi_audply_get_current_list_drv())
    {
        g_mmi_audply_init_done = MMI_FALSE;
        if (list_cntx.list_loaded)
        {
            list_cntx.list_loaded = MMI_FALSE;
            mmi_audply_playlist_reset_ui_cntx();
            /* clear screen. */
            /*
            mmi_audply_clear_play_seconds();
            g_audply.seekable = MMI_FALSE;
            g_audply.need_to_build_cache = MMI_FALSE;
            g_audply.title[0] = 0;
            g_audply.filefullname[0] = 0;*/
            mmi_audply_reset_context();
        } 
    }
    #ifdef __MMI_AUDPLY_WALK_PLAY__
    mmi_audply_walk_search_cancel_hdlr();
	mmi_audply_cache_do_validation();
    #endif  //__MMI_AUDPLY_WALK_PLAY__
}

#ifdef __MMI_AUDPLY_WALK_PLAY__
extern U8 Press_Prev;
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_plst_notify_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_audply_plst_notify_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables */
    /*----------------------------------------------------------------*/
    AUDPLY_UPDATE_LIST_ACTION_ENUM          action;

    /*----------------------------------------------------------------*/
    /* Code Body */
    /*----------------------------------------------------------------*/

    switch(event->evt_id)
    {
        #if defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)
        case EVT_ID_SRV_A2DP_CONNECT:
        {
            if (mmi_frm_group_get_state(GRP_ID_AUDPLY_MAIN) != MMI_SCENARIO_STATE_NONE
                #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
                || mmi_frm_group_get_state(GRP_ID_AUDPLY_MAIN_PRE_LIST) != MMI_SCENARIO_STATE_NONE
                #endif  //__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
                )
            {
                //mmi_frm_close_to_idle_group();
                mmi_frm_group_close(GRP_ID_AUDPLY_MAIN);
            }
            break;
        }
        #endif  //defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)
       
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
        case EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE:
        {
            srv_fmgr_notification_set_def_storage_event_struct *fmgr_storage
                = (srv_fmgr_notification_set_def_storage_event_struct*)event;
            
            if(fmgr_storage->state == SRV_FMGR_NOTIFICATION_STATE_QUERY) /* MMI_FMGR_NOTIFY_SET_STORAGE_PRE_CHK */
            {
                return mmi_audply_plst_notify_default_storage_change_pre_check((CHAR)fmgr_storage->drv_letter);
            }
            else if(fmgr_storage->state == SRV_FMGR_NOTIFICATION_STATE_AFTER) /* MMI_FMGR_NOTIFY_SET_STORAGE */
            {
                mmi_audply_plst_notify_default_storage_change((CHAR)fmgr_storage->drv_letter);
            }
            break;
        }

#endif /* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */

        case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT: 
        {
            srv_fmgr_notification_format_event_struct *fmgr_format
                = (srv_fmgr_notification_format_event_struct*)event;
            
            if(fmgr_format->state == SRV_FMGR_NOTIFICATION_STATE_BEFORE) /* MMI_FMGR_NOTIFY_DRV_PRE_FORMAT */
            {
                mmi_audply_fmgr_notify_drv_pre_format_hdlr((CHAR)fmgr_format->drv_letter);
            }
            else if(fmgr_format->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
            {
                mmi_audply_fmgr_notify_drv_post_format_hdlr((CHAR)fmgr_format->drv_letter);
            }
            break;
        }


        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT: /* MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT */
        {
            srv_fmgr_notification_dev_plug_event_struct *fmgr_plug
                = (srv_fmgr_notification_dev_plug_event_struct*)event;

            mmi_audply_msdc_plug_out_hdlr(fmgr_plug->count, fmgr_plug->drv_letters);
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN: /*MMI_FMGR_NOTIFY_DRV_POST_MOUNT*/
        {
            srv_fmgr_notification_dev_plug_event_struct *fmgr_plug
                = (srv_fmgr_notification_dev_plug_event_struct*)event;

            mmi_audply_msdc_plug_in_hdlr(fmgr_plug->count, fmgr_plug->drv_letters);
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT:
        {
            srv_fmgr_notification_dev_soft_mount_event_struct *fmgr_mount
                = (srv_fmgr_notification_dev_soft_mount_event_struct*)event;
            
            if(fmgr_mount->mount == MMI_FALSE) /*MMI_FMGR_NOTIFY_ENTRY_UNMOUNT*/
            {
                mmi_audply_fmgr_notify_hdlr((CHAR)fmgr_mount->drv_letter);
            }
           
            break;

        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
        {
            srv_fmgr_notification_adv_action_event_struct *fmgr_act 
                = (srv_fmgr_notification_adv_action_event_struct*)event;
            
            
            if(fmgr_act->state == SRV_FMGR_NOTIFICATION_STATE_QUERY)
            {
                if ((fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_MOVE) || /*MMI_FMGR_NOTIFY_PRE_DELETE, MMI_FMGR_NOTIFY_PRE_MOVE */
                    (fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE))
                {
                    if(mmi_audply_check_file_is_playing((CHAR*)fmgr_act->src_filepath, (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR), MMI_FALSE, MMI_FALSE,(fmgr_act->filter)))
                    {
                        return MMI_RET_ERR;
                    }
                    
                }
                else if(fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL) /* MMI_FMGR_NOTIFY_PRE_DEL_ALL */
                {
                    if (!FMGR_FILTER_IS_SET_AUDIO((FMGR_FILTER *)fmgr_act->filter))
                    {
                        /* avoid: delete all image files. need not check*/
                        return MMI_TRUE;
                    }
                    if(mmi_audply_check_file_is_playing((CHAR*)fmgr_act->src_filepath, (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR),MMI_FALSE, MMI_TRUE,(fmgr_act->filter)))
                    {
                        return MMI_RET_ERR;
                    }
                }
            }
            else if (fmgr_act->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
            {
                switch(fmgr_act->action)
                {
                    case SRV_FMGR_NOTIFICATION_ACTION_COPY:
                    {
                        action = AUDPLY_ACTION_COPY;
						#ifdef __MMI_AUDPLY_WALK_PLAY__
						if (g_audply.play_style == AUDPLY_PLAY_STYLE_BY_FILE_ORDER)
						{
							mmi_audply_cache_do_validation();
							Press_Prev = 2;
						}
						else
						#endif  //__MMI_AUDPLY_WALK_PLAY__
                        mmi_audply_update_list_hdlr((CHAR*)fmgr_act->src_filepath,(CHAR*)fmgr_act->dest_filepath,(U8)action, (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR));
                    }
                    break;
                    
                    case SRV_FMGR_NOTIFICATION_ACTION_MOVE:
                    {
                        CHAR* last_backlash = NULL;
                        MMI_BOOL trg_folder = MMI_FALSE;
                        MMI_BOOL src_folder = MMI_FALSE;
                        
                        last_backlash = mmi_ucs2rchr((CHAR*)fmgr_act->dest_filepath, (U16)L'\\');
                        
                        MMI_ASSERT(last_backlash != NULL);
                        
                        if (2 > mmi_ucs2strlen((CHAR*)last_backlash))
                        {
                            trg_folder = MMI_TRUE;
                        }
                        
                        last_backlash = mmi_ucs2rchr((CHAR*)fmgr_act->src_filepath, (U16)L'\\');
                        
                        MMI_ASSERT(last_backlash != NULL);
                        
                        if (2 > mmi_ucs2strlen((CHAR*)last_backlash))
                        {
                            src_folder = MMI_TRUE;
                        }

                        if (trg_folder && !src_folder)
                        {
                            //move file(source) to folder(target)
                            action = AUDPLY_ACTION_MOVE;
                        }
                        else
                        {
                            //rename file/folder(source) to file/folder(target)
                            action = AUDPLY_ACTION_RENAME;
                        }
                        
						#ifdef __MMI_AUDPLY_WALK_PLAY__
						if (g_audply.play_style == AUDPLY_PLAY_STYLE_BY_FILE_ORDER)
						{
							mmi_audply_cache_do_validation();
							Press_Prev = 2;
						}
						else
						#endif  //__MMI_AUDPLY_WALK_PLAY__
                        mmi_audply_update_list_hdlr((CHAR*)fmgr_act->src_filepath,(CHAR*)fmgr_act->dest_filepath,(U8)action, (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR));
                    }
                    break;
                    
                    case SRV_FMGR_NOTIFICATION_ACTION_DELETE:
                    {
                        action = AUDPLY_ACTION_DELETE;
						#ifdef __MMI_AUDPLY_WALK_PLAY__
						if (g_audply.play_style == AUDPLY_PLAY_STYLE_BY_FILE_ORDER)
						{
							mmi_audply_cache_do_validation();
							Press_Prev = 2;
						}
						else
						#endif  //__MMI_AUDPLY_WALK_PLAY__
                        mmi_audply_update_list_hdlr((CHAR*)fmgr_act->src_filepath,NULL,(U8)action, (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR));
                    }
                    break;

                    case SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL:
                    {
                        if (!FMGR_FILTER_IS_SET_AUDIO((FMGR_FILTER *)fmgr_act->filter))
                        {
                             /* avoid: delete all image files. need not check*/
                            return MMI_TRUE;
                        }
						#ifdef __MMI_AUDPLY_WALK_PLAY__
						if (g_audply.play_style == AUDPLY_PLAY_STYLE_BY_FILE_ORDER)
						{
							mmi_audply_cache_do_validation();
							Press_Prev = 2;
						}
						else
						#endif  //__MMI_AUDPLY_WALK_PLAY__
                        mmi_audply_update_list_hdlr((CHAR*)fmgr_act->src_filepath,NULL,AUDPLY_ACTION_DELETE_ALL, (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR));
                        break;
                    }
                    

                    default:
                        break;
                                        
                }
                
            }
            break;
        }
        
        default:
            break;
    }

    return MMI_RET_OK;
}

#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_set_default_playlist_path
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_set_default_playlist_path(void)
{
    kal_wsprintf(list_cntx.current_list.path, "%c:\\", (CHAR)g_audply.present_list);
    mmi_ucs2cat((CHAR*)list_cntx.current_list.path, (CHAR*)MMI_AUDPLY_DEFAULT_PATH);
   /* mmi_ucs2cat((CHAR*)list_cntx.current_list.path, (CHAR*)L"\\");
    mmi_ucs2cat((CHAR*)list_cntx.current_list.path, (CHAR*)MMI_AUDPLY_DEFAULT_LIST_NAME);*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_check_and_set_default_playlist_path
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  file_path       [OUT]
 *  driver_letter   [IN]
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_playlist_check_and_set_default_playlist_path(UI_string_type file_path, CHAR driver_letter)
{
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    S32 ret = FS_NO_ERROR;

    kal_wsprintf(path, "%c:\\", (CHAR)driver_letter);
    mmi_ucs2cat((CHAR*)path, (CHAR*)MMI_AUDPLY_DEFAULT_FOLDER);
    /* check default playlist fodler. */
    ret = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    if (ret < FS_NO_ERROR)
    {
        if (ret == FS_FAT_ALLOC_ERROR)
        {
            return ret;
        }
        
        ret = FS_CreateDir(path);
        if (FS_FILE_EXISTS == ret)
        {
            ret = -1;
        }
        else if(FS_NO_ERROR > ret)
        {
            return ret;
        }
        else
        {
            FS_SetAttributes(path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
            ret = -1;
        }
    }
    else
    {
        FS_Close(ret);
        ret = -1;
    }
    /* always set default playlist folder as hidden. */
    //FS_SetAttributes(path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    
    mmi_ucs2cat((CHAR*)path, (CHAR*)L"\\");
    mmi_ucs2cat((CHAR*)path, (CHAR*)MMI_AUDPLY_DEFAULT_LIST_NAME);

    mmi_ucs2ncpy((CHAR*)file_path, (CHAR*)path, (SRV_FMGR_PATH_MAX_LEN+1));
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_check_status
 * DESCRIPTION
 *  for check user modify list data file in mass storege mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_check_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_audply_init_done)
    {
        mmi_audply_playlist_init();
    }
}


#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */

#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
MMI_BOOL mmi_audply_plst_notify_default_storage_change_pre_check(CHAR new_storage_letter)
{
    return MMI_TRUE;
}

void mmi_audply_plst_notify_default_storage_change(CHAR new_storage_letter)
{
	S16 error = 0;

    if (g_audply.preferred_list != (U8)new_storage_letter)
    {
		g_audply.preferred_list = (U8)new_storage_letter;
		WriteValueSlim(NVRAM_AUDPLY_PREFER_LIST, &new_storage_letter, DS_BYTE);
    #ifdef __MMI_AUDIO_PLAYER_SINGLE_LIST__
    	if (g_mmi_audply_init_done)
        {
			mmi_audply_stop_playing();
			mmi_audply_refresh_cache(MMI_FALSE);
	        g_audply.present_list = (U8)new_storage_letter;
            #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
	        if (g_audply.list_auto_gen)
	        {
	            need_refresh_list = MMI_TRUE;
	        }
	        else
            #endif
	        {
	            need_reload_list = MMI_TRUE;
	        }
	        memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
        }
	#endif	/* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */
	}
}
#endif	/* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */
#define GENERATER_FUNCTION_BODY
#define GENERATER_FUNCTION_BODY
#define GENERATER_FUNCTION_BODY
#define GENERATER_FUNCTION_BODY

 /*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_send_msg
 * DESCRIPTION
 *  player list service send msg function 
 * PARAMETERS
 *  buffer      [IN]    buffer for sqlite database usage
 *  length      [IN]    length of buffer
 *  en_update   [IN]    enable update picture to database
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_cui_search_send_msg(module_type src, module_type dst, U32 msg_id, void *local_param_ptr)
{
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
#endif
    msg_send5(src, dst, MMI_MMI_SAP, (msg_type)msg_id, (local_para_struct*)local_param_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_search_continue_req_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_audply_playlist_search_continue_req_ext(void *context, U16 line_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_search_continue_req_struct *req_param_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_param_ptr = (mmi_audply_playlist_search_continue_req_struct*) construct_local_para(sizeof(mmi_audply_playlist_search_continue_req_struct), TD_CTRL);
    req_param_ptr->context = NULL;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAYLIST_SEARCH_CONTINUE_REQ, context, line_number);
    mmi_medply_cui_search_send_msg(MOD_MMI, MOD_MMI, MSG_ID_MMI_LIST_SEARCH_CUI_SEARCH_INT_REQ, req_param_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_generate(UI_string_type fullPath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    MMI_BOOL is_multi_part_odf = MMI_FALSE;
    CHAR* last_backlash = NULL;
#ifdef __DRM_V02__
    CHAR* ext = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fullPath == NULL)
    {
        mmi_audply_playlist_reload_list();
        /* TODO: CLose the gropus here & back to file list*/
        if (mmi_frm_group_is_present(GRP_ID_AUDPLY_LIST_ADD))
        {
            mmi_frm_group_close(GRP_ID_AUDPLY_LIST_ADD);
        }
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION); 
        //GoBackHistory();
        return;
    }
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    if (fullPath[0] != (CHAR)g_audply.present_list)
    {
        mmi_popup_display_ext(
            STR_ID_AUDPLY_FILE_IN_DIFFERENT_STORAGE, 
            MMI_EVENT_ERROR, 
            NULL);
        mmi_audply_playlist_reload_list();
         if (mmi_frm_group_is_present(GRP_ID_AUDPLY_LIST_ADD))
        {
            mmi_frm_group_close(GRP_ID_AUDPLY_LIST_ADD);
        }
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION); 

        //DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
        return;
    }
#endif

#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    if (list_cntx.current_list.total >= MMI_AUDPLY_MAX_PLAYLIST_ITEM)
    {
        mmi_popup_display_ext(
            STR_ID_AUDPLY_LIST_FULL, 
            MMI_EVENT_FAILURE, 
            NULL);
        mmi_audply_playlist_reload_list();

         if (mmi_frm_group_is_present(GRP_ID_AUDPLY_LIST_ADD))
        {
            mmi_frm_group_close(GRP_ID_AUDPLY_LIST_ADD);
        }
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION); 
        //DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
        return;
    }
#elif defined(__MMI_AUDPLY_MULTIPLE_LIST__)  
{
    U16 total = 0;
    if (browser_now_playing)
    {
        total = list_cntx.current_list.total;
    }
    else
    {
        total = list_cntx.browser_list.total;
    }

    if (total >= MMI_AUDPLY_MAX_PLAYLIST_ITEM)
    {
        mmi_popup_display_ext(
            STR_ID_AUDPLY_LIST_FULL, 
            MMI_EVENT_FAILURE, 
            NULL);
        mmi_audply_playlist_reload_list();
        DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
        return;
    }
}
#endif
#ifdef __DRM_V02__
    if (NULL != (ext = mmi_ucs2rchr((CHAR*)fullPath, (U16)L'.')))
    {
        if (!mmi_ucs2nicmp((CHAR*)ext, 
            (CHAR*)L".odf", (U32)mmi_ucs2strlen((CHAR*)ext)))
        {
            if (DRM_is_archive(0, (PU16)fullPath))
            {
                is_multi_part_odf = MMI_TRUE;
            }
            else 
            {
                is_multi_part_odf = MMI_FALSE;
            }             
        }
    }
    else
    {
        is_multi_part_odf = MMI_FALSE;
    }
#else
    is_multi_part_odf = MMI_FALSE;
#endif  /* __DRM_V02__ */   

    /* the last character will be '\\' if the path got from filemgr is a folder. */
    last_backlash = mmi_ucs2rchr((CHAR*)fullPath, (U16)L'\\');

    if (2 > mmi_ucs2strlen((CHAR*)last_backlash) || is_multi_part_odf)
    {
        /* 
        ** the backlash is the last character of this path. 
        ** so this is a folder path.
        */
    #if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
        ret = mmi_audply_playlist_check_and_set_default_playlist_path(
                   list_cntx.current_list.path, (CHAR)g_audply.present_list);
        if (ret < FS_NO_ERROR)
        {
            /* create default playlist folder failed! */
			mmi_audply_playlist_display_popup(ret, NULL);
            mmi_audply_playlist_reload_list();
            if (mmi_frm_group_is_present(GRP_ID_AUDPLY_LIST_ADD))
            {
                mmi_frm_group_close(GRP_ID_AUDPLY_LIST_ADD);
            }
            mmi_frm_group_close(GRP_ID_AUDPLY_OPTION); 
            //DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
            return;
        }
        /* generater need playlist file's handle. */
        ret = FS_Open(list_cntx.current_list.path, FS_READ_WRITE | FS_CREATE | FS_ATTR_HIDDEN);
        if (ret < 0)
        {
            mmi_audply_playlist_display_popup(ret, NULL);
            if (mmi_frm_group_is_present(GRP_ID_AUDPLY_LIST_ADD))
            {
                mmi_frm_group_close(GRP_ID_AUDPLY_LIST_ADD);
            }
            mmi_frm_group_close(GRP_ID_AUDPLY_OPTION); 
            //DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
        }
        else
        {
            list_cntx.current_list.fs_hdlr = ret;
            ret = FS_Seek(ret, list_cntx.current_list.total * MMI_AUDPLY_LIST_RECORD_SIZE, FS_FILE_BEGIN);
            if (ret < FS_NO_ERROR)
            {
                mmi_audply_playlist_display_popup(ret, NULL);
                
                if (mmi_frm_group_is_present(GRP_ID_AUDPLY_LIST_ADD))
                {
                    mmi_frm_group_close(GRP_ID_AUDPLY_LIST_ADD);
                }
                mmi_frm_group_close(GRP_ID_AUDPLY_OPTION); 
                //DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
            }
            else
            {
                /* always suspend background playing in single list. */
               #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
                if (!g_audply.list_auto_gen)
                #endif
                {
                    mdi_audio_suspend_background_play();
                }
                #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
                else
                {
                    mmi_audply_stop_playing();
                }
                #endif
                mmi_audply_playlist_generate_from_folder(fullPath, is_multi_part_odf);
            }
        }
    #elif defined(__MMI_AUDPLY_MULTIPLE_LIST__)
        /* need suspend background playing when do this about now playing list? */
        mmi_audply_playlist_generate_from_folder(fullPath, is_multi_part_odf);
    #endif
    }
    else
    {
    #if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
        ret = mmi_audply_playlist_check_and_set_default_playlist_path(
                   list_cntx.current_list.path, (CHAR)g_audply.present_list);
        if (ret < FS_NO_ERROR)
        {
            /* create default playlist folder failed! */
			mmi_audply_playlist_display_popup(ret, NULL);
            mmi_audply_playlist_reload_list();

            if (mmi_frm_group_is_present(GRP_ID_AUDPLY_LIST_ADD))
            {
                mmi_frm_group_close(GRP_ID_AUDPLY_LIST_ADD);
            }
            mmi_frm_group_close(GRP_ID_AUDPLY_OPTION); 
            
            //DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
            return;
        }
    #endif
        /* it is a file. append to playlist directly. */
        ret = mmi_audply_playlist_generate_append_one(fullPath, (MMI_BOOL)is_short);
        if (ret >= FS_NO_ERROR)
        {
            mmi_popup_display_ext(
                STR_GLOBAL_DONE, 
                MMI_EVENT_SUCCESS, 
                NULL);
        }
        else
        {
            mmi_audply_playlist_display_popup(ret, NULL);
            mmi_audply_playlist_reload_list();

            if (mmi_frm_group_is_present(GRP_ID_AUDPLY_LIST_ADD))
            {
                mmi_frm_group_close(GRP_ID_AUDPLY_LIST_ADD);
            }
            mmi_frm_group_close(GRP_ID_AUDPLY_OPTION); 
            //DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
        }
    #if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
        if (browser_now_playing)
    #endif
        {
            if (list_cntx.current_list.pick_index < 0)
            {
                if (mmi_audply_playlist_pick_next() >= 0)
                {
                    mmi_audply_playlist_apply_picked_file();
                }
            }
        }
    }
}

void mmi_audply_playlist_generate_cancel(void)
{
    StopTimer(AUDPLY_PROCESS_ADD_FILE_TIMER);
    list_cntx.generate_info.phase = MMI_AUDPLY_LIST_PHASE_CANCEL;
    StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
}

static U32 counter = 0;


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_from_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_generate_from_folder(UI_string_type path, MMI_BOOL is_multi_part_odf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_generate_struct* this = &(list_cntx.generate_info);
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)    
    mmi_audply_playlist_struct* list = &(list_cntx.browser_list);

    S32 ret = 0;
#elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
#ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    mmi_audply_playlist_struct* list = &(list_cntx.current_gen_list);
#else
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
#endif
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /* init generate variables. */
    memset(this, 0, sizeof(mmi_audply_playlist_generate_struct));
    
    
    
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)  
    if (browser_now_playing)
    {
        list = &(list_cntx.current_list);
    }
    this->footer_pattern_offset = list->header.footer_pattern_offset;
#elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    this->footer_pattern_offset = list->total * MMI_AUDPLY_LIST_RECORD_SIZE;
#endif
    this->list_file_handle = list->fs_hdlr;
    this->appended_number = 0;
    this->total_number = list->total;
    this->last_error_code = 0;
    this->search_handle = -1;
    if (is_multi_part_odf)
    {
        this->phase = MMI_AUDPLY_LIST_PHASE_SEARCH_ODF;
    }
    else
    {
        this->phase = MMI_AUDPLY_LIST_PHASE_SEARCH_FIRST;
        this->stack_index = 0;
        memset((this->stack), 0, MMI_AUDPLY_MAX_DEPTH_DIRECTORY * sizeof(mmi_audply_playlist_stack_node_struct));
    }
    
    mmi_ucs2cpy((CHAR*)this->path_cache, (CHAR*)path);
    
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    ret = FS_Seek(list->fs_hdlr, list->header.footer_pattern_offset, FS_FILE_BEGIN);
    /* cut off the footer area in list file. */
    FS_Truncate(list->fs_hdlr);
#endif  /* __MMI_AUDPLY_MULTIPLE_LIST__ */

    SetProtocolEventHandler(mmi_audply_playlist_generate_internal, MSG_ID_MMI_LIST_SEARCH_CUI_SEARCH_INT_REQ);

    /* entry wait screen. */
    mmi_audply_playlist_generate_wait_screen_entry();
    counter = 0;
    StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 50, mmi_audply_playlist_generate_internal);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAYLIST_UPDATE_START, __LINE__);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_generate_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
     if (mmi_frm_group_get_active_id() != GRP_ID_AUDPLY_WAITSCREEN && list_cntx.generate_info.phase != MMI_AUDPLY_LIST_PHASE_CANCEL)
    {
        /* Sleep if the waitting screen has been in history. */
        StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 500, mmi_audply_playlist_generate_internal);
        return;
    }
#endif
    
    switch (list_cntx.generate_info.phase)
    {
        case MMI_AUDPLY_LIST_PHASE_SEARCH_FIRST:
            mmi_audply_playlist_generate_search();
            return;
        case MMI_AUDPLY_LIST_PHASE_SEARCH_NEXT:
            mmi_audply_playlist_generate_search();
            return;
        case MMI_AUDPLY_LIST_PHASE_FORWARDS:
            mmi_audply_playlist_generate_forwards();
            return;
        case MMI_AUDPLY_LIST_PHASE_BACKWARDS:
        case MMI_AUDPLY_LIST_PHASE_BACKWARDS_ODF:
            mmi_audply_playlist_generate_backwards();
            return;
        case MMI_AUDPLY_LIST_PHASE_FINISH:
            mmi_audply_playlist_generate_finish();
            return;
        #ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
        case MMI_AUDPLY_LIST_PHASE_FINISH_ONE:
            mmi_audply_playlist_generate_finish_single_one();
            return;
        #endif
        case MMI_AUDPLY_LIST_PHASE_ERR_HDLR:
            mmi_audply_playlist_generate_error_hdlr();
            return;
        case MMI_AUDPLY_LIST_PHASE_CANCEL:
            mmi_audply_playlist_generate_cancel_hdlr();
            return;        
        case MMI_AUDPLY_LIST_PHASE_SEARCH_ODF:
        #ifdef __DRM_V02__
            mmi_audply_playlist_generate_search_odf();
        #endif  /* __DRM_V02__ */
            return;
        default: 
            MMI_ASSERT(list_cntx.generate_info.phase <= MMI_AUDPLY_LIST_PHASE_ERR_HDLR);
    }
}

#ifdef __DRM_V02__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_search_odf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_generate_search_odf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_generate_search_for_drm(list_cntx.generate_info.path_cache);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_search_for_drm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_generate_search_for_drm(UI_string_type odf_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_generate_struct* this = &(list_cntx.generate_info);
        /* for a short variable name. */
    drm_file_info_struct drm_file_info;
    FS_HANDLE multi_part_handle;
    UI_character_type content_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    UI_character_type temp_buffer[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type file_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    S32 ret = MMI_AUDPLY_PLAYLIST_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    this->DRM_find_cntx = DRM_get_find_cntx();
    multi_part_handle = DRM_find_firstN(
                                this->DRM_find_cntx,
                                (PU16)odf_path, 
                                0, 
                                0,
                                &drm_file_info,
                                content_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                0);
    if (multi_part_handle < FS_NO_ERROR)
    {
        /* because this memory will be free in DRM_find_firstN when DRM_find_firstN fail. */
        this->DRM_find_cntx = NULL;
        this->last_error_code = multi_part_handle;
        this->phase = MMI_AUDPLY_LIST_PHASE_ERR_HDLR;
        mmi_audply_playlist_search_continue_req(NULL);
        //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
        return;
    }
    else
    {
        do
        {
            mmi_audply_extract_ext(content_name, file_ext);
            if (mmi_audply_lookup_audio_file_format(file_ext) >= 0)
            {
                if (mmi_ucs2strlen((CHAR*)odf_path) + mmi_ucs2strlen((CHAR*)content_name) + 1 <= (SRV_FMGR_PATH_MAX_LEN+1))
                {
                    mmi_ucs2cpy((CHAR*)temp_buffer, (CHAR*)odf_path);
                    mmi_ucs2cat((CHAR*)temp_buffer, (CHAR*)L"\\");
                    mmi_ucs2cat((CHAR*)temp_buffer, (CHAR*)content_name);

                    if (this->total_number < MMI_AUDPLY_MAX_PLAYLIST_ITEM)
                    {
                        ret = mmi_audply_playlist_generate_write_to_file(temp_buffer, MMI_FALSE);
                        if (ret < MMI_AUDPLY_PLAYLIST_NO_ERROR)
                        {
                            DRM_find_close(this->DRM_find_cntx, multi_part_handle);
                            this->DRM_find_cntx = NULL;
                            this->last_error_code = ret;
                            this->phase = MMI_AUDPLY_LIST_PHASE_ERR_HDLR;
                            mmi_audply_playlist_search_continue_req(NULL);
                            //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
                            return;
                        }      
                        else
                        {
                            this->appended_number++;
                            this->total_number++;
                            MMI_ASSERT(this->total_number <= MMI_AUDPLY_MAX_PLAYLIST_ITEM);
                        }
                    }
                    else
                    {
                        DRM_find_close(this->DRM_find_cntx, multi_part_handle);
                        this->DRM_find_cntx = NULL;
                        this->last_error_code = MMI_AUDPLY_PLAYLIST_ERR_LIST_FULL;
                        this->phase = MMI_AUDPLY_LIST_PHASE_ERR_HDLR;
                        mmi_audply_playlist_search_continue_req(NULL);
                        //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
                        return;
                    }
                }
            }
        } while (FS_NO_ERROR == DRM_find_nextN(
                                this->DRM_find_cntx,
                                multi_part_handle, 
                                &drm_file_info,
                                content_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                1));
    }

    if (this->DRM_find_cntx)
    {
        DRM_find_close(this->DRM_find_cntx, multi_part_handle);
        this->DRM_find_cntx = NULL;
    }

    this->phase = MMI_AUDPLY_LIST_PHASE_BACKWARDS_ODF;
    mmi_audply_playlist_search_continue_req(NULL);
    //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
    return;
}
#endif  /* __DRM_V02__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_generate_search(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE ret = FS_NO_ERROR;
    U8 i = 0;
    FS_DOSDirEntry file_info;

    CHAR buf_file_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN * ENCODING_LENGTH + ENCODING_LENGTH];

    UI_character_type file_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type file_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    MMI_BOOL is_shortname = MMI_FALSE;
    mmi_audply_playlist_generate_struct* this = &(list_cntx.generate_info);
    
#ifdef __DRM_V02__
    UI_character_type odf_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type ext_in_odf[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    PU8 ext_name_p = NULL; 
    MMI_BOOL add_audio = MMI_FALSE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*)file_path, (CHAR*)this->path_cache);
    mmi_ucs2cat((CHAR*)file_path, (CHAR*)L"*.*");
        
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAYLIST_GENERATE_SEARCH, __LINE__);
    if (this->phase == MMI_AUDPLY_LIST_PHASE_SEARCH_FIRST)
    {
        ret = FS_FindFirstN(
                (PU16)file_path,
                NULL,
                0,
                FS_ATTR_DIR,    /* only search media files in this phase. */
                0,
                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                &file_info,
                (PU16)buf_file_name,
                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                0,
                FS_FIND_DEFAULT);
        
        if (ret >= 0)
        {
            this->search_handle = ret;
            this->phase = MMI_AUDPLY_LIST_PHASE_SEARCH_NEXT;
            
            /* begin to cache sub-folder infomation. */
            if (this->stack_index < MMI_AUDPLY_MAX_DEPTH_DIRECTORY)
            {
                this->stack[this->stack_index].level = this->stack_index;
                this->stack[this->stack_index].total_sub_folder = 0;
                this->stack[this->stack_index].index = 0;
                this->stack[this->stack_index].fs_index = 0;    /* it is invalid when this value is 0 or 1. */
            }
            else
            {
                /* max level, do not save. */
                MMI_ASSERT(this->stack_index < MMI_AUDPLY_MAX_DEPTH_DIRECTORY);
            }
        }
        else
        {
            if (this->stack_index == 0)
            {
                if (ret == FS_NO_MORE_FILES)
                {
                    this->phase = MMI_AUDPLY_LIST_PHASE_BACKWARDS;
                }
                else
                {
                    this->last_error_code = ret;
                    this->phase = MMI_AUDPLY_LIST_PHASE_ERR_HDLR;
                }
            }
            else
            {
                this->phase = MMI_AUDPLY_LIST_PHASE_BACKWARDS;
            }
            mmi_audply_playlist_search_continue_req(NULL);
            //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
            return;
        }
    }
    else if (this->phase == MMI_AUDPLY_LIST_PHASE_SEARCH_NEXT)
    {
        ret = FS_FindNextN(
                        this->search_handle,
                        NULL,
                        0,
                        FS_ATTR_DIR,
                        &file_info,
                        (PU16)buf_file_name,
                        (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                        FS_FIND_DEFAULT);
        if (ret < 0)
        {
            FS_FindClose(this->search_handle);
            this->search_handle = -1;
            if (ret == FS_NO_MORE_FILES)
            {
                if (!this->stack[this->stack_index].total_sub_folder)
                {
                    this->phase = MMI_AUDPLY_LIST_PHASE_BACKWARDS;
                }
                else
                {
                    if (this->stack_index < MMI_AUDPLY_MAX_DEPTH_DIRECTORY)
                    {
                        this->phase = MMI_AUDPLY_LIST_PHASE_FORWARDS;
                    }
                    else
                    {
                        this->phase = MMI_AUDPLY_LIST_PHASE_BACKWARDS;
                    }
                }
            }
            else
            {
                if (this->stack_index == 0)
                {
                    this->last_error_code = ret;
                    this->phase = MMI_AUDPLY_LIST_PHASE_ERR_HDLR;
                }
                else
                {
                    this->phase = MMI_AUDPLY_LIST_PHASE_BACKWARDS;
                }
            }
            mmi_audply_playlist_search_continue_req(NULL);
            //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
            return;
        }
    }
    else
    {
        /* these codes should never be run. */
        MMI_ASSERT(this->phase == MMI_AUDPLY_LIST_PHASE_SEARCH_NEXT ||
                   this->phase == MMI_AUDPLY_LIST_PHASE_SEARCH_FIRST);
    }
    
    do
    {
        if ((file_info.Attributes & (FS_ATTR_DIR | FS_ATTR_VOLUME | FS_ATTR_HIDDEN | FS_ATTR_SYSTEM)) == 0)
        {
            is_shortname = (MMI_BOOL)((file_info.NTReserved & FS_SFN_MATCH) != 0);
            if (is_shortname)
            {
                U8 j = 0;
                for (j = 0; j < 3; j++)
                {
                    if (file_info.Extension[j] == L' ')
                    {
                        break;
                    }
                    file_ext[j] = (UI_character_type) file_info.Extension[j];
                }
                file_ext[j] = 0;
            }
            else
            {
                CHAR* ext = mmi_ucs2rchr((CHAR*)buf_file_name, (U16)L'.');
                if (ext != NULL)
                {
                    ext += 2;
                    mmi_ucs2ncpy((CHAR*)file_ext, (CHAR*)ext, mmi_ucs2strlen((CHAR*)ext));
                }
                else
                {
                    ext = NULL;
                    file_ext[0] = 0;
                }
            }

            if (mmi_audply_lookup_audio_file_format(file_ext) >= 0)
            {
            #ifdef __DRM_V02__
                if (!mmi_ucs2nicmp((CHAR*)file_ext, (CHAR*)L"odf", (U32)mmi_ucs2strlen((CHAR*)file_ext)))
                {
                    add_audio = MMI_FALSE;
                    mmi_ucs2cpy((CHAR*)odf_path, (CHAR*)this->path_cache);
                    mmi_ucs2cat((CHAR*)odf_path, (CHAR*)buf_file_name);
                    
                    if (!DRM_is_archive(0, (PU16)odf_path))
                    {
                        ext_name_p = (PU8)DRM_get_content_ext(0, (PU16)odf_path);
                        if (ext_name_p != NULL)
                        {
                            mmi_asc_n_to_ucs2((CHAR*)ext_in_odf, (CHAR*)ext_name_p, strlen((const char *)ext_name_p));
                            ext_in_odf[strlen((const char *)ext_name_p)] = 0;
                            if (mmi_audply_lookup_audio_file_format(ext_in_odf) >= 0)
                            {
                                add_audio = MMI_TRUE;
                            }
                            else
                            {
                                add_audio = MMI_FALSE;
                            }
                        }
                        else
                        {
                            file_ext[0] = 0;
                        }
                    }
                    else
                    {
                        mmi_ucs2ncpy((CHAR*)this->path_cache, (CHAR*)odf_path, (SRV_FMGR_PATH_MAX_LEN+1));
                        this->stack_index++;
                        this->phase = MMI_AUDPLY_LIST_PHASE_SEARCH_ODF;
                        mmi_audply_playlist_search_continue_req(NULL);
                        //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
                        return;
                    }
                }
                else
                {
                    add_audio = MMI_TRUE;
                }
                if (add_audio)
            #endif  /* __DRM_V02__ */
                {
                    if (mmi_ucs2strlen((CHAR*)this->path_cache) + 
                        mmi_ucs2strlen((CHAR*)buf_file_name) <= (SRV_FMGR_PATH_MAX_LEN+1))
                    {
                        mmi_ucs2cpy((CHAR*)file_path, (CHAR*)this->path_cache);
                        mmi_ucs2cat((CHAR*)file_path, (CHAR*)buf_file_name);

                        if (this->total_number < MMI_AUDPLY_MAX_PLAYLIST_ITEM)
                        {
                            MMI_BOOL is_short = (file_info.NTReserved == FS_SFN_MATCH) ? MMI_TRUE : MMI_FALSE;
                            /* add media file data to data file. */  
                            ret = mmi_audply_playlist_generate_write_to_file(file_path, is_short);
                            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAYLIST_GENERATE_SEARCH_FIND, counter++, __LINE__);
                            
                            if (ret < 0)
                            {
                                FS_FindClose(this->search_handle);
                                this->search_handle = -1;
                                this->last_error_code = ret;
                                this->phase = MMI_AUDPLY_LIST_PHASE_ERR_HDLR;
                                mmi_audply_playlist_search_continue_req(NULL);
                                //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
                                return;
                            }
                            else
                            {
                                this->appended_number++;
                                this->total_number++;
                                MMI_ASSERT(this->total_number <= MMI_AUDPLY_MAX_PLAYLIST_ITEM);
                            }
                        }
                        else
                        {
                            FS_FindClose(this->search_handle);
                            this->search_handle = -1;
                            this->last_error_code = MMI_AUDPLY_PLAYLIST_ERR_LIST_FULL;
                            this->phase = MMI_AUDPLY_LIST_PHASE_ERR_HDLR;
                            mmi_audply_playlist_search_continue_req(NULL);
                            //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
                            return;                    
                        }
                    }
                    /* skip to ask other messages. */
                    if ((++i) == MMI_AUDPLY_MAX_PICK_PER_SLICE)    
                    {
                        FS_Commit(this->list_file_handle);
                        //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 50, mmi_audply_playlist_generate_internal);
                        mmi_audply_playlist_search_continue_req(NULL);
                        //gui_start_timer(50, mmi_audply_playlist_generate_internal);
                        return;
                    }
                }
            }
        }
        else if (file_info.Attributes & FS_ATTR_DIR)
        {
            /* skip "dot" and "dot dot". */
            if (mmi_ucs2strlen((CHAR*)buf_file_name) < 3)
            {
                if (mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)L".") &&
                    mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)L".."))
                {
                    this->stack[this->stack_index].total_sub_folder++;
                }
            }
            else
            {
                this->stack[this->stack_index].total_sub_folder++;
            }
        }
        
        ret = FS_FindNextN(
                        this->search_handle,
                        NULL,
                        0,
                        FS_ATTR_DIR,
                        &file_info,
                        (PU16)buf_file_name,
                        (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                        FS_FIND_DEFAULT);
    } while (ret == FS_NO_ERROR);
    FS_FindClose(this->search_handle);
    FS_Commit(this->list_file_handle);
    this->search_handle = -1;
    if (this->stack_index < MMI_AUDPLY_MAX_DEPTH_DIRECTORY)
    {
        this->phase = MMI_AUDPLY_LIST_PHASE_FORWARDS;
    }
    else
    {
        this->phase = MMI_AUDPLY_LIST_PHASE_BACKWARDS;
    }
    mmi_audply_playlist_search_continue_req(NULL);
    //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 50, mmi_audply_playlist_generate_internal);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_forwards
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_generate_forwards(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 return_value = 0;
    FS_DOSDirEntry file_info;
    CHAR buf_file_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN * ENCODING_LENGTH + ENCODING_LENGTH];

    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    U16 counter = 0;
    mmi_audply_playlist_generate_struct* this = &(list_cntx.generate_info);
        /* for a short variable name. */
    U32 path_length = 0;
    U32 sub_folder_length = 0;
    U32 total_length = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(this->stack_index < MMI_AUDPLY_MAX_DEPTH_DIRECTORY);
    if (!this->stack[this->stack_index].total_sub_folder)
    {
        /* no sub-folder, go backwards. */
        this->phase = MMI_AUDPLY_LIST_PHASE_BACKWARDS;
        mmi_audply_playlist_search_continue_req(NULL);
        //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
        return;
    }
    else if (this->stack[this->stack_index].total_sub_folder == 
                                this->stack[this->stack_index].index)
    {
        this->phase = MMI_AUDPLY_LIST_PHASE_BACKWARDS;
        mmi_audply_playlist_search_continue_req(NULL);
        //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
        return;
    }
    else    /* need forwards. */
    {
        mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)this->path_cache);
        mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"*.*");

        file_handle = FS_FindFirstN(
                        (PU16)temp_path,
                        NULL,
                        0,
                        0,
                        0,
                        FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                        &file_info,
                        (PU16)buf_file_name,
                        (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                        this->stack[this->stack_index].fs_index,
                        FS_FIND_DEFAULT);
        if (file_handle >= 0)
        {
            do
            {
                counter++;
                /* test if pass the filter */
                if (file_info.Attributes & FS_ATTR_DIR)
                {
                    FS_FindClose(file_handle);
                    /* check path length. */
                    
                    path_length = mmi_ucs2strlen((CHAR*)this->path_cache);
                    sub_folder_length = mmi_ucs2strlen((CHAR*)buf_file_name);
                    total_length = 0;

                    total_length = path_length + sub_folder_length;
                    total_length++;
                    if (total_length > (SRV_FMGR_PATH_MAX_LEN - 6))
                    {
                    // TODO: too long path, add trace.
                        this->stack[this->stack_index].fs_index += counter;
                        this->stack[this->stack_index].index++;
                    }
                    else 
                    {
                        if ((this->stack_index + 1) < MMI_AUDPLY_MAX_DEPTH_DIRECTORY)
                        {
                            /* compose next level path. */
                            mmi_ucs2cat((CHAR*)this->path_cache, (CHAR*)buf_file_name);
                            mmi_ucs2cat((CHAR*)this->path_cache, (CHAR*)L"\\");

                            /* save level node info. */
                            this->stack[this->stack_index].fs_index += counter;
                            this->stack[this->stack_index].index++;

                            /* entry next level. */
                            this->stack_index++;
                            this->phase = MMI_AUDPLY_LIST_PHASE_SEARCH_FIRST;
                            
                            mmi_audply_playlist_search_continue_req(NULL);
                            //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
                            return;
                        }
                        else /* get max depth. */
                        {
                            /* to get next file, even have a sub-directory. */
                            this->phase = MMI_AUDPLY_LIST_PHASE_SEARCH_NEXT;

                            mmi_audply_playlist_search_continue_req(NULL);
                            //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
                            return;
                        }
                    }
                }
                
                return_value = FS_FindNextN(
                                file_handle,
                                NULL,
                                0,
                                0,
                                &file_info,
                                (PU16)buf_file_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                FS_FIND_DEFAULT);
                
            } while (return_value == FS_NO_ERROR);
            FS_FindClose(file_handle);
            /* no more sub-folder, backwards. */
            this->phase = MMI_AUDPLY_LIST_PHASE_BACKWARDS;
            mmi_audply_playlist_search_continue_req(NULL);
            //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
            return;
        }
        else
        {
            if (this->stack_index == 0)
            {
                if (file_handle == FS_NO_MORE_FILES)
                {
                    this->phase = MMI_AUDPLY_LIST_PHASE_BACKWARDS;
                }
                else
                {
                    this->last_error_code = file_handle;
                    this->phase = MMI_AUDPLY_LIST_PHASE_ERR_HDLR;
                }
            }
            else
            {
                this->phase = MMI_AUDPLY_LIST_PHASE_BACKWARDS;
            }
            mmi_audply_playlist_search_continue_req(NULL);
            //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
            return;
        }
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_backwards
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_generate_backwards(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_generate_struct* this = &(list_cntx.generate_info);
        /* for a short variable name. */
    CHAR* last_backlash = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (this->stack_index > 0)
    {
        memset(&(this->stack[this->stack_index]), 0, 
                    sizeof(mmi_audply_playlist_stack_node_struct));
        /* update path cache. */
        last_backlash = mmi_ucs2rchr((CHAR*)this->path_cache, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);
        *(last_backlash + 1) = 0;
        *last_backlash = 0;
        
        if (this->phase == MMI_AUDPLY_LIST_PHASE_BACKWARDS)
        {
            last_backlash = mmi_ucs2rchr((CHAR*)this->path_cache, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            
        }
        mmi_ucs2cat((CHAR*)this->path_cache, (CHAR*)L"\\");
        this->stack_index--;
        this->phase = MMI_AUDPLY_LIST_PHASE_FORWARDS;
    }
    else
    {
        this->phase = MMI_AUDPLY_LIST_PHASE_FINISH;
    }
    mmi_audply_playlist_search_continue_req(NULL);
    //StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_finish
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_generate_finish(void)
{



#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    mmi_audply_playlist_generate_finish_multiple();
#elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    mmi_audply_playlist_generate_finish_single();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_error_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_generate_error_hdlr(void)
{
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    mmi_audply_playlist_generate_error_hdlr_multiple();
#elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    mmi_audply_playlist_generate_error_hdlr_single();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_write_to_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_audply_playlist_generate_write_to_file(UI_string_type path, MMI_BOOL is_short)
{
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    return mmi_audply_playlist_generate_write_to_file_multiple(path, is_short);
#elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    return mmi_audply_playlist_generate_write_to_file_single(path, is_short);
#endif

}

static mmi_ret mmi_audply_playlist_generate_wait_screen_proc(mmi_event_struct *event)
{
    switch (event->evt_id)
    {
	    case EVT_ID_SCRN_INACTIVE:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAYLIST_GENERATE_WAIT_SCREEN, __LINE__);
            break;
        }
        case EVT_ID_SCRN_ACTIVE:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAYLIST_GENERATE_WAIT_SCREEN, __LINE__);
            /* do not allow popup sliding for this waiting popup */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
            gui_screen_switch_effect_block(MMI_TRUE);
#endif
        
            ShowCategory66Screen(
                STR_ID_AUDPLY_TITLE,
                GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
                0,
                0,
                STR_GLOBAL_CANCEL,
                0,
                (U8*)GetString(STR_GLOBAL_PLEASE_WAIT),
                mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                NULL);
        
            ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        case EVT_ID_GROUP_DEINIT:
        {
        		mmi_audply_playlist_generate_cancel();
            break;
        }
        case EVT_ID_WGUI_RSK_CLICK:
        {
            mmi_audply_playlist_generate_cancel();
            return MMI_RET_KEY_HANDLED;          
        }
        
        default:
            break;
    }
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_wait_screen_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_generate_wait_screen_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_group_create_ex(
        GRP_ID_AUDPLY_MAIN, 
        GRP_ID_AUDPLY_WAITSCREEN, 
        mmi_audply_playlist_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(
         GRP_ID_AUDPLY_WAITSCREEN, 
         SCR_ID_AUDPLY_WAITSCREEN, 
         mmi_audply_playlist_generate_wait_screen_proc,   
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_append_one
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_audply_playlist_generate_append_one(UI_string_type path, MMI_BOOL is_short)
{
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    return mmi_audply_playlist_generate_append_one_multiple(path, is_short, MMI_TRUE);
#elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    return mmi_audply_playlist_generate_append_one_single(path, is_short);
#endif
}

static void mmi_audply_playlist_generate_cancel_hdlr(void)
{
#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    mmi_audply_playlist_generate_cancel_hdlr_multiple();
#elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    mmi_audply_playlist_generate_cancel_hdlr_single();
#endif    
}


#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)

static MMI_BOOL mmi_audply_playlist_check_free_space(CHAR drv_letter, U32 req_size)
{
    FS_DiskInfo disk_info;
    U32 disk_free_space;
    S32 fs_ret;
    UI_character_type path[10];
    
    kal_wsprintf(path, "%c:\\", drv_letter);    
    fs_ret = FS_GetDiskInfo((kal_uint16*)path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    if (fs_ret < 0)
    {
        return MMI_FALSE;
    }
    else
    {        
        disk_free_space = disk_info.FreeClusters * 
                          disk_info.SectorsPerCluster * 
                          disk_info.BytesPerSector;
        if (disk_free_space < req_size + disk_info.BytesPerSector)    /* more a sector free space to keep file system other operation normal. */
        {
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }
    }
}

typedef S32 (*CompFuncPtr)(const void *, const void *);
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_comp
 * DESCRIPTION
 *  compare to index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_audply_comp(const void* a, const void* b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((*(mmi_audply_playlist_index_node_struct*)a).index - (*(mmi_audply_playlist_index_node_struct*)b).index);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_swap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_swap(CHAR *a, CHAR *b, U32 data_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR tmp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (a != b)
    {
        while (data_width--) 
        {
            tmp = *a;
            *a++ = *b;
            *b++ = tmp;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_qsort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_qsort(void *sort_base, U32 number, U32 data_width, CompFuncPtr compare_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *low_item_ptr, *hight_item_ptr, *low_ptr, *high_ptr, *middle_ptr;
    CHAR *low_stack[30], *high_stack[30];
    S32 stack_ptr = 0;
    U32 buffer_size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(2 > number || 0 == data_width) 
    {
        return;
    }

    high_ptr = (CHAR *) sort_base + data_width * (number - 1);
    low_ptr = sort_base;

recursion:
    buffer_size = (high_ptr - low_ptr) / data_width + 1;
    middle_ptr = low_ptr + (buffer_size / 2) * data_width;
    mmi_audply_swap((CHAR*)middle_ptr, (CHAR*)low_ptr, data_width);
    hight_item_ptr = data_width + high_ptr;
    low_item_ptr = low_ptr;

    do
    {
        do 
        { 
            low_item_ptr += data_width; 
        } while (low_item_ptr <= high_ptr && compare_func(low_item_ptr, low_ptr) <= 0);
        
        do 
        { 
            hight_item_ptr -= data_width; 
        } while (hight_item_ptr > low_ptr && compare_func(hight_item_ptr, low_ptr) >= 0);
        
        if (low_item_ptr > hight_item_ptr) 
        {
            break;
        }
        mmi_audply_swap((CHAR*)low_item_ptr, (CHAR*)hight_item_ptr, data_width);
    }while(1);

    mmi_audply_swap((CHAR*)low_ptr, (CHAR*)hight_item_ptr, data_width);

    if (high_ptr - low_item_ptr > hight_item_ptr - low_ptr - 1) 
    {
        if (low_item_ptr < high_ptr) 
        {
            high_stack[stack_ptr] = high_ptr;
            low_stack[stack_ptr] = low_item_ptr;
            ++stack_ptr;
        }
        if (low_ptr + data_width < hight_item_ptr) 
        {
            high_ptr = hight_item_ptr - data_width;
            goto recursion;
        }
    }
    else
    {
        if (hight_item_ptr > low_ptr + data_width) 
        {
            high_stack[stack_ptr] = hight_item_ptr - data_width;
            low_stack[stack_ptr] = low_ptr;
            ++stack_ptr;
        }
        if (high_ptr > low_item_ptr) 
        {
            low_ptr = low_item_ptr;
            goto recursion;
        }
    }

    --stack_ptr;
    if (stack_ptr >= 0) 
    {
        high_ptr = high_stack[stack_ptr];
        low_ptr = low_stack[stack_ptr];
        goto recursion;
    }
    else
    {
        return;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_sort_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_generate_sort_index(
            mmi_audply_playlist_index_node_struct* index, S32 low, S32 high)
{
    mmi_audply_qsort(index, high + 1, sizeof(mmi_audply_playlist_index_node_struct), mmi_audply_comp);
}

static S32 mmi_audply_playlist_generate_append_one_multiple(UI_string_type path, MMI_BOOL is_short, MMI_BOOL write_back_file_immediately)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 write_size = 0;
    U32 insert_offset = 0;
    U32 next_block = 0;
    U32 used_size = 0;
    S32 ret = 0;
    U16 i = 0;
    
    mmi_audply_playlist_index_node_struct new_node;
    mmi_audply_playlist_block_node_struct block;
    U8 utf8_buff[SRV_FMGR_PATH_BUFFER_SIZE];
    mmi_audply_playlist_struct* list = &(list_cntx.browser_list);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    memset(utf8_buff, 0, SRV_FMGR_PATH_BUFFER_SIZE);
    if (browser_now_playing)
    {
        list = &(list_cntx.current_list);
    }
    /* make new node data. */
	memset(&new_node, 0, sizeof(mmi_audply_playlist_index_node_struct));
    new_node.offset = list->header.footer_pattern_offset;
    new_node.index = list->total;
    
    if (is_short)
    {
        new_node.is_active = 2;
    }
    else
    {
        new_node.is_active = 1;
    }
    /* ucs2 -> utf8 */
    used_size = mmi_chset_convert(
                    CHSET_UCS2,
                    CHSET_UTF8, 
                    (char*)path, 
                    (char*)utf8_buff, 
                    SRV_FMGR_PATH_BUFFER_SIZE);
    new_node.used_block = used_size / MMI_AUDPLY_BLOCK_DATA_SIZE;

    if (used_size % MMI_AUDPLY_BLOCK_DATA_SIZE > 0)
    {
        new_node.used_block++;
    }

    if (list->header.empty_node.used_block >= new_node.used_block && write_back_file_immediately)
    {
        mmi_audply_playlist_index_node_struct target_node;
        /* backup relative variables. */
        memcpy(&target_node, &(list->header.index[list->total]), sizeof(mmi_audply_playlist_index_node_struct));

        if (!list->header.empty_node.offset)
        {
            /* something wrong about link of empty nodes. */
            return MMI_AUDPLY_PLAYLIST_ERR_LIST_DAMAGED;
        }
        
        list->header.index[list->total].index = list->total;
        list->header.index[list->total].is_active = new_node.is_active;
        list->header.index[list->total].used_block = new_node.used_block;
        list->header.index[list->total].offset = list->header.empty_node.offset;
/* check empty nodes will be used. */
        insert_offset = list->header.empty_node.offset;
        next_block = insert_offset;
        for (i = 0; i < new_node.used_block; i++)
        {
            /* seek to blcok. */
            ret = FS_Seek(list->fs_hdlr, next_block, FS_FILE_BEGIN);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            insert_offset = next_block;
            /* read block to get next ptr. */
            ret = FS_Read(list->fs_hdlr, &block, sizeof(mmi_audply_playlist_block_node_struct), &write_size);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            else if (write_size != sizeof(mmi_audply_playlist_block_node_struct))
            {
                ret = MMI_AUDPLY_PLAYLIST_ERR_READ_FAILED;
                break;
            }
            /* check block. */
            if (block.pattern_begin != AUDPLY_PLAYLIST_BLOCK_PATTERN_1 ||
                block.pattern_end != AUDPLY_PLAYLIST_BLOCK_PATTERN_2)
            {
                ret = MMI_AUDPLY_PLAYLIST_ERR_LIST_DAMAGED;
                break;
            }
            
            next_block = block.next_ptr;
            if (!next_block && (i < new_node.used_block - 1))
            {
                ret = MMI_AUDPLY_PLAYLIST_ERR_LIST_DAMAGED;
                break;
            }
        }

        if (ret < FS_NO_ERROR)
        {
            /* check link of empty nodes failed. */
            return ret;
        }

/* write to file. */
        insert_offset = list->header.empty_node.offset;
        next_block = insert_offset;
        for (i = 0; i < new_node.used_block; i++)
        {           
            /* seek to block. */
            ret = FS_Seek(list->fs_hdlr, next_block, FS_FILE_BEGIN);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            insert_offset = next_block;
            /* read block to get next ptr. */
            ret = FS_Read(list->fs_hdlr, &block, sizeof(mmi_audply_playlist_block_node_struct), &write_size);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            else if (write_size != sizeof(mmi_audply_playlist_block_node_struct))
            {
                ret = MMI_AUDPLY_PLAYLIST_ERR_READ_FAILED;
                break;
            }
            /* check block. */
            if (block.pattern_begin != AUDPLY_PLAYLIST_BLOCK_PATTERN_1 ||
                block.pattern_end != AUDPLY_PLAYLIST_BLOCK_PATTERN_2)
            {
                ret = MMI_AUDPLY_PLAYLIST_ERR_LIST_DAMAGED;
                break;
            }
            
            next_block = block.next_ptr;
            if (!next_block && (i < new_node.used_block - 1))
            {
                MMI_ASSERT(next_block != 0);
            }
            /* make new block data. */
            memcpy(&(block.data), &(utf8_buff[i * MMI_AUDPLY_BLOCK_DATA_SIZE]), MMI_AUDPLY_BLOCK_DATA_SIZE);

            /* seek back to the begin of current block. */
            ret = FS_Seek(list->fs_hdlr, insert_offset, FS_FILE_BEGIN);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            
            /* write new block data. */   
            ret = FS_Write(list->fs_hdlr, &block, 
                            sizeof(mmi_audply_playlist_block_node_struct), &write_size);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            if (write_size != sizeof(mmi_audply_playlist_block_node_struct))
            {
                ret = MMI_AUDPLY_PLAYLIST_ERR_WRITE_FAILED;
                break;
            }
        }

        if (ret < FS_NO_ERROR)
        {
            if (i > 0)
            {
                /* 
                **  some blocks have been wrote to file.
                **  because the file size has not changed.
                **  only reset index node.
                */
                memcpy(&(list->header.index[list->total]), &target_node, sizeof(mmi_audply_playlist_index_node_struct));
            }
        }
        else
        {
            /* append successfully. */
            list->total++;
            list->header.total_slot++;
            list->header.empty_node.offset = next_block;
            list->header.empty_node.used_block -= new_node.used_block;
            
            if (!next_block)
            {
                list->header.empty_node.used_block = 0;
            }
            
            if (write_back_file_immediately)
            {
                ret = mmi_audply_playlist_write_back_to_file(list);
            }
        }
                
        return ret;
    }
    else
    {
        MMI_BOOL have_enough_space = MMI_FALSE;
        U32 require_size = new_node.used_block * MMI_AUDPLY_BLOCK_DATA_SIZE;
        CHAR drv_letter = (CHAR)list->path[0];
        
        have_enough_space = mmi_audply_playlist_check_free_space((CHAR)drv_letter, require_size);
        if (have_enough_space)
        {
            mmi_audply_playlist_index_node_struct target_node;
            /* backup relative variables. */
            memcpy(&target_node, &(list->header.index[list->total]), sizeof(mmi_audply_playlist_index_node_struct));

            list->header.index[list->total].index = list->total;
            list->header.index[list->total].is_active = new_node.is_active;
            list->header.index[list->total].used_block = new_node.used_block;
            list->header.index[list->total].offset = list->header.footer_pattern_offset;
            /*
            **  write map back->write new node->read new map->sort->write back new map
            **  more file system operation in order to avoid make memory flagment.
            */
            do 
            {   
                insert_offset = list->header.footer_pattern_offset;
                /* write new path. */ 
                ret = FS_Seek(list->fs_hdlr, insert_offset, FS_FILE_BEGIN);
                if (ret < FS_NO_ERROR)
                {
                    break;
                }
                
                for (i = 0; i < new_node.used_block; i++)
                {      
                    mmi_audply_playlist_block_node_struct block;
                    block.pattern_begin = AUDPLY_PLAYLIST_BLOCK_PATTERN_1;
                    block.pattern_end = AUDPLY_PLAYLIST_BLOCK_PATTERN_2;
                    
                    insert_offset += sizeof(mmi_audply_playlist_block_node_struct);
                    if (i + 1 == new_node.used_block)
                    {
                        block.next_ptr = 0;
                    }
                    else
                    {
                        block.next_ptr = insert_offset;
                    }
                    memcpy(&(block.data), &(utf8_buff[i * MMI_AUDPLY_BLOCK_DATA_SIZE]), MMI_AUDPLY_BLOCK_DATA_SIZE);
                    
                    /* write new path. */   
                    ret = FS_Write(list->fs_hdlr, &block, 
                                    sizeof(mmi_audply_playlist_block_node_struct), &write_size);
                    if (ret < FS_NO_ERROR)
                    {
                        break;
                    }
                    if (write_size != sizeof(mmi_audply_playlist_block_node_struct))
                    {
                        ret = MMI_AUDPLY_PLAYLIST_ERR_WRITE_FAILED;
                        break;
                    }
                }

                if (ret < FS_NO_ERROR)
                {
                    if (i > 0)
                    {
                        /* 
                        **  some blocks have been wrote to file.
                        **  because the file size has been changed.
                        **  overwrite index area from new node first block.
                        */
                        memcpy(&(list->header.index[list->total]), &target_node, sizeof(mmi_audply_playlist_index_node_struct));

                        ret = mmi_audply_playlist_write_back_to_file(list);
                    }
                }
                else
                {
                    /* update index area offset. */
                    list->header.footer_pattern_offset += new_node.used_block * sizeof(mmi_audply_playlist_block_node_struct);
                    list->header.total_slot++;
                    list->total++;
                    if (write_back_file_immediately)
                    {
                        ret = mmi_audply_playlist_write_back_to_file(list);
                        if (browser_now_playing)
                        {
                            if (list->pick_index < 0)
                            {
                                if (mmi_audply_playlist_pick_next() >= 0)
                                {
                                    mmi_audply_playlist_apply_picked_file();
                                }
                            }
                        }
                    }
                }
            } while (0);

            return ret;
        }
        else
        {
            return FS_DISK_FULL;
        }
    }
}


static void mmi_audply_playlist_generate_finish_multiple(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_generate_struct* this = &(list_cntx.generate_info);
    mmi_audply_playlist_struct* list = &(list_cntx.browser_list);
    S32 ret = FS_NO_ERROR;

    MMI_BOOL is_empty = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(this->stack_index == 0);

    if (browser_now_playing)
    {
        list = &(list_cntx.current_list);
    }

    if (this->search_handle)
    {
        FS_FindClose(this->search_handle);
		this->search_handle = -1;
    }

    if (this->appended_number)
    {
        mmi_audply_playlist_generate_sort_index(list->header.index, 0, (list->header.total_slot - 1));
        MMI_ASSERT(list->header.pattern == AUDPLY_PLAYLIST_FOOTER_PATTERN);
        ret = mmi_audply_playlist_write_back_to_file(list);
        if (browser_now_playing)
        {
            if (list->pick_index < 0)
            {
                if (mmi_audply_playlist_pick_next() >= 0)
                {
                    mmi_audply_playlist_apply_picked_file();
                }
            }
        }
    }
    else
    {
        is_empty = MMI_TRUE;
    }

    if (ret < 0)
    {
        /* change status to "handling error" if any error. */
        this->last_error_code = ret;
        this->phase = MMI_AUDPLY_LIST_PHASE_ERR_HDLR;
        StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 20, mmi_audply_playlist_generate_internal);
        return;
    }
    else
    {         
        if (IsScreenPresent(SCR_ID_AUDPLY_WAITSCREEN))
        {
            DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN);
        }
        else
        {
            if (is_empty)
            {
                mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, NULL);
                DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN);
            }
            else
            {
                mmi_popup_display_ext((STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, NULL);
                DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN);
            }
        }
    }
}

static void mmi_audply_playlist_generate_error_hdlr_multiple(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_generate_struct* this = &(list_cntx.generate_info);
    mmi_audply_playlist_struct* list = &(list_cntx.browser_list);
    S32 ret = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (browser_now_playing)
    {
        list = &(list_cntx.current_list);
    }
    
    if (this->search_handle)
    {
        FS_FindClose(this->search_handle);
		this->search_handle = -1;
    }

    if (this->appended_number)
    {
        mmi_audply_playlist_generate_sort_index(list->header.index, 0, (list->header.total_slot - 1));
        MMI_ASSERT(list->header.pattern == AUDPLY_PLAYLIST_FOOTER_PATTERN);
        ret = mmi_audply_playlist_write_back_to_file(list);
        mmi_audply_playlist_clear_list_browser_gui_buffer();
    }

    if (IsScreenPresent(SCR_ID_AUDPLY_WAITSCREEN))
    {
        DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN);
    }
    else
    {
        if (this->last_error_code != 0)
        {
            mmi_audply_display_popup(this->last_error_code, NULL, NULL);
            DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
        }
    }

    if (browser_now_playing)
    {
        if (list->pick_index < 0)
        {
            if (mmi_audply_playlist_pick_next() >= 0)
            {
                mmi_audply_playlist_apply_picked_file();
            }
        }
    }
}


static void mmi_audply_playlist_generate_cancel_hdlr_multiple(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_generate_struct* this = &(list_cntx.generate_info);
    mmi_audply_playlist_struct* list = &(list_cntx.browser_list);
    S32 ret = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(AUDPLY_PROCESS_ADD_FILE_TIMER);
    if (!(this->search_handle < 0))
    {
        FS_FindClose(this->search_handle);
    }

    if (browser_now_playing)
    {
        list = &(list_cntx.current_list);
    }
    
    if (this->appended_number)
    {
        mmi_audply_playlist_generate_sort_index(list->header.index, 0, (list->header.total_slot - 1));
        MMI_ASSERT(list->header.pattern == AUDPLY_PLAYLIST_FOOTER_PATTERN);
        ret = mmi_audply_playlist_write_back_to_file(list);
        mmi_audply_playlist_clear_list_browser_gui_buffer();
        if (browser_now_playing)
        {
            if (list->pick_index < 0)
            {
                if (mmi_audply_playlist_pick_next() >= 0)
                {
                    mmi_audply_playlist_apply_picked_file();
                }
            }
        }
    }

    mmi_audply_playlist_reload_list();
    if (GetActiveScreenId() == SCR_ID_AUDPLY_WAITSCREEN)    /* user press cancel in wait screen. */
    {
        GoBackHistory();    /* go back to FMGR screen. */
    }
    else if (IsScreenPresent(SCR_ID_AUDPLY_WAITSCREEN))     /* USB plug-in in generate process */
    {
        /* wait screen in history. need delete it. */
        DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN);
    }
}


static S32 mmi_audply_playlist_generate_write_to_file_multiple(UI_string_type path, MMI_BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return mmi_audply_playlist_generate_append_one_multiple(path, is_short, MMI_FALSE);
    //return mmi_audply_playlist_generate_append_one_multiple(path, is_short, MMI_TRUE);
}
#elif defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
#define GENERATE_SINGLE_PART
#define GENERATE_SINGLE_PART
#define GENERATE_SINGLE_PART
#define GENERATE_SINGLE_PART
#define GENERATE_SINGLE_PART
 
static S32 mmi_audply_playlist_generate_append_one_single(UI_string_type path, MMI_BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size = 0;
    FS_HANDLE fd = -1;
    S32 result = 0;
    S32 write_result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* we are goign to mark L or S in drive char */
    if (is_short)
    {
        MARK_SNAME(path);  /* mark short name */
    }
    else
    {
        MARK_LNAME(path);  /* mark long name */
    }
    
    if ((fd = FS_Open(list_cntx.current_list.path, FS_READ_WRITE | FS_CREATE | FS_ATTR_HIDDEN)) >= 0)
    {
        if ((write_result = FS_Seek(fd, list_cntx.current_list.total * MMI_AUDPLY_LIST_RECORD_SIZE, FS_FILE_BEGIN)) >= FS_NO_ERROR)
        {
            if ((write_result = FS_Write(fd, path, MMI_AUDPLY_LIST_RECORD_SIZE, &size)) >= FS_NO_ERROR)
            {
                list_cntx.current_list.total++;
            }
        }
        
        result = write_result;
        FS_Close(fd);
    }
    else
    {
        result = fd;
    }

    return result;

}


#ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
static void mmi_audply_playlist_generate_finish_single_one(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAYLIST_UPDATE_FINISH_ONE, __LINE__);
    
    list_cntx.current_list.total = MMI_AUDPLY_MAX_PICK_PER_SLICE - 1;

    mmi_audply_playlist_error_hdlr_ext();
    
    if (mmi_frm_scrn_get_active_id() == SCR_ID_AUDPLY_WAITSCREEN || !mmi_frm_is_in_backward_scenario())
    {
        ////mmi_popup_display_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, NULL);
        //mmi_frm_scrn_clean_gui_buf(GRP_ID_AUDPLY_LIST_BROWSER, SCR_ID_AUDPLY_LIST_BROWSER);
        mmi_frm_scrn_close(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN);
    }
    //mmi_frm_scrn_close_active_id();
    if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN,MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
    }
    
    /*
    **  this is to solve when user never enters audply,
    **  but tries to play by AVRCP first command will 
    **  trigger regenerate playlist when auto gen on,
    **  but the button flag will not have chance to update,
    **  so any button press/release command will be blocked.
    */ 
    mmi_audply_update_main_button_flag();

    //continue gen    
    list_cntx.generate_info.phase = MMI_AUDPLY_LIST_PHASE_SEARCH_NEXT;
    mmi_audply_playlist_search_continue_req(NULL);
}
#endif  //__MMI_BTD_BOX_UI_STYLE__

static void mmi_audply_playlist_generate_finish_single(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_generate_struct* this = &(list_cntx.generate_info);
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    #ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    S16 error;
    #endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAYLIST_UPDATE_FINISH, __LINE__);
    MMI_ASSERT(this->stack_index == 0);

    if (!(this->search_handle < 0))
    {
        FS_FindClose(this->search_handle);
    }
    FS_Close(this->list_file_handle);
    FS_Close(list->fs_hdlr);
    
#ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    list_cntx.is_genning_playlist = MMI_FALSE;
    WriteValue(NVRAM_AUDPLY_PLAYLIST_FILE_NUM, &list_cntx.file_num, DS_BYTE, &error);
    WriteValue(NVRAM_AUDPLY_PLAYLIST_NUM_OF_LAST_FILE, &this->appended_number, DS_BYTE, &error);
    list_cntx.num_of_last_file = this->appended_number;
    if (list_cntx.file_num == 1)
#endif
    {
        /*if (!g_audply.list_auto_gen)
        {
            list->total = this->total_number;
            mmi_audply_playlist_reload_list();
    	  if (list->pick_index < 0)
    	  {
    	    if (mmi_audply_playlist_pick_next() >= 0)
    	    {
    	        mmi_audply_playlist_apply_picked_file();
               }
    	  }
            else if(g_audply.filefullname[0] == 0)
            {
                mmi_audply_playlist_apply_picked_file();
            }
            mdi_audio_resume_background_play();
        }
        else
        {
            memset(list, 0, sizeof(mmi_audply_playlist_struct));
            mmi_audply_need_load_playlist();
        }
    */
        mmi_audply_playlist_error_hdlr_ext();
        if (this->appended_number)
        {
            if (mmi_frm_scrn_get_active_id() == SCR_ID_AUDPLY_WAITSCREEN || !mmi_frm_is_in_backward_scenario())
            {
                ////mmi_popup_display_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, NULL);
                mmi_frm_scrn_clean_gui_buf(GRP_ID_AUDPLY_LIST_BROWSER, SCR_ID_AUDPLY_LIST_BROWSER);
                mmi_frm_scrn_close(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN);
            }
            //mmi_frm_scrn_close_active_id();
            if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN,MMI_FRM_NODE_ALL_FLAG))
            {
                mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
            }
            /*
            else
            {
                mmi_frm_scrn_close(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN);
            }*/

            //DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN);  
        }
        else
        {
            if (mmi_frm_scrn_get_active_id() == SCR_ID_AUDPLY_WAITSCREEN || !mmi_frm_is_in_backward_scenario())
            {
                mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, NULL);
                mmi_frm_scrn_close(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN);
               
            }
             if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN,MMI_FRM_NODE_ALL_FLAG))
            {
                mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
            }
            
            //DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN);  
        }
        
        /*
        **  this is to solve when user never enters audply,
        **  but tries to play by AVRCP first command will 
        **  trigger regenerate playlist when auto gen on,
        **  but the button flag will not have chance to update,
        **  so any button press/release command will be blocked.
        */ 
        mmi_audply_update_main_button_flag();
    }
}


static void mmi_audply_playlist_generate_error_hdlr_single(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_generate_struct* this = &(list_cntx.generate_info);
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);

    S32 ret = FS_NO_ERROR;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(this->search_handle < 0))
    {
        FS_FindClose(this->search_handle);
    }

    /*if (this->last_error_code != MMI_AUDPLY_PLAYLIST_ERR_LIST_FULL)
    {
        FS_Seek(this->list_file_handle, this->footer_pattern_offset, FS_FILE_BEGIN);
        FS_Truncate(this->list_file_handle);
    }
    else*/
    #ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    list_cntx.is_genning_playlist = MMI_FALSE;
    WriteValue(NVRAM_AUDPLY_PLAYLIST_FILE_NUM, &list_cntx.file_num, DS_BYTE, &error);
    WriteValue(NVRAM_AUDPLY_PLAYLIST_NUM_OF_LAST_FILE, &this->appended_number, DS_BYTE, &error);
    list_cntx.num_of_last_file = this->appended_number;
    if (list_cntx.file_num == 1)
    #endif
    {
        {
            list->total = this->total_number;
        }
        FS_Close(this->list_file_handle);
       
        ret = this->last_error_code;
        
        if (ret < MMI_AUDPLY_PLAYLIST_NO_ERROR)
        {
        	if (ret == FS_NO_MORE_FILES)
        	{
        	    if (mmi_frm_scrn_get_active_id() == SCR_ID_AUDPLY_WAITSCREEN)
        	    {
                    mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, NULL);
                  
                    if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN))
        	    {
                        mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);

                    }
                    mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
                
        	       // DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
                }
                else
                {
                    if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN))
                    {
                        mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);

                    }
                    //mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
                   //DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN);
                }
        	}
        	else
            {   
                if (mmi_frm_scrn_get_active_id() == SCR_ID_AUDPLY_WAITSCREEN)
                {
        	        mmi_audply_display_popup(ret, NULL, NULL);
                    if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,MMI_FRM_NODE_ALL_FLAG))
                    {
                         if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN))
                    {
                             mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
                         }
                         
                         mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
                        
                        //DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
                    }
                    else if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_MAIN,SCR_ID_AUDPLY_MAIN,MMI_FRM_NODE_ALL_FLAG))
                    {
                        if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN))
                    {
                            mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
                        }

                        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
                        mmi_frm_group_close(GRP_ID_AUDPLY_LIST_BROWSER);

                       // DeleteUptoScrID(SCR_ID_AUDPLY_MAIN);
                    }
                    else
                    {
                        if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN))
                        {
                            mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
                        }
                        //DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN);
                    }
                }
                else
                {
                    if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN))
                    {
                        mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
                    }
                    //DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN);
                }
        	}	
        }
        mmi_audply_playlist_error_hdlr_ext();
        /*if (!g_audply.list_auto_gen)
        {
            list->total = this->total_number;
            mmi_audply_playlist_reload_list();
    	    if (list->pick_index < 0)
    	    {
    	        if (mmi_audply_playlist_pick_next() >= 0)
    	        {
    	            mmi_audply_playlist_apply_picked_file();
                    }
    	    }
            else if(g_audply.filefullname[0] == 0)
            {
                mmi_audply_playlist_apply_picked_file();
            }
            mdi_audio_resume_background_play();
        }
        else
        {
            memset(list, 0, sizeof(mmi_audply_playlist_struct));
            mmi_audply_need_load_playlist();
        }*/
        mmi_audply_update_main_button_flag();
    }
}


static void mmi_audply_playlist_error_hdlr_ext(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_generate_struct* this = &(list_cntx.generate_info);
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    if (!g_audply.list_auto_gen)
     #endif
    {
        #ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
        if (!list_cntx.is_genning_playlist)
        #endif
        list->total = this->total_number;
    
        mmi_audply_playlist_reload_list();
	    if (list->pick_index < 0)
	    {
	        if (mmi_audply_playlist_pick_next() >= 0)
	        {
	            mmi_audply_playlist_apply_picked_file();
            }
	    }
        else if(g_audply.filefullname[0] == 0)
        {
            mmi_audply_playlist_apply_picked_file();
        }
        mdi_audio_resume_background_play();
    }
    #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    else
    {
        memset(list, 0, sizeof(mmi_audply_playlist_struct));
        mmi_audply_need_load_playlist();
    }
    #endif
}



static void mmi_audply_playlist_generate_cancel_hdlr_single(void)
{
    mmi_audply_playlist_generate_struct* this = &(list_cntx.generate_info);
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    S16 error;
    
    ClearProtocolEventHandler(MSG_ID_MMI_LIST_SEARCH_CUI_SEARCH_INT_REQ);
    StopTimer(AUDPLY_PROCESS_ADD_FILE_TIMER);

    if (!(this->search_handle < 0))
    {
        FS_FindClose(this->search_handle);
    }

    FS_Close(this->list_file_handle);
    #ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    list_cntx.is_genning_playlist = MMI_FALSE;
    WriteValue(NVRAM_AUDPLY_PLAYLIST_FILE_NUM, &list_cntx.file_num, DS_BYTE, &error);
    WriteValue(NVRAM_AUDPLY_PLAYLIST_NUM_OF_LAST_FILE, &this->appended_number, DS_BYTE, &error);
    list_cntx.num_of_last_file = this->appended_number;
    if (list_cntx.file_num == 1)
    #endif
    {
        #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
        if (!g_audply.list_auto_gen)
        #endif
        {
            list->total = this->total_number;
            
            mmi_audply_playlist_reload_list();
            if (list->pick_index < 0)
            {
                if (mmi_audply_playlist_pick_next() >= 0)
                {
                    mmi_audply_playlist_apply_picked_file();
                }
            }
            else if(g_audply.filefullname[0] == 0)
            {
                mmi_audply_playlist_apply_picked_file();
            }
            mdi_audio_resume_background_play();
        }
        #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
        else
        {
            memset(list, 0, sizeof(mmi_audply_playlist_struct));
            mmi_audply_need_load_playlist();
        }
        #endif

        mmi_audply_update_main_button_flag();

        if (mmi_frm_scrn_get_active_id() == SCR_ID_AUDPLY_WAITSCREEN)    /* user press cancel in wait screen. */
        {
            mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
            //GoBackHistory();    /* go back to FMGR screen. */
        }
        else if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN,MMI_FRM_NODE_ALL_FLAG))     /* USB plug-in in generate process */
        {
            /* wait screen in history. need delete it. */
            if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN))
            {
                mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
            }
            //DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN);
        }
    }
}


static S32 mmi_audply_playlist_generate_write_to_file_single(UI_string_type path, MMI_BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 write_size = 0;
    S32 ret = MMI_AUDPLY_PLAYLIST_NO_ERROR;
    #ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    U32 duration = 0;
    #endif

    mmi_audply_playlist_generate_struct* this = &(list_cntx.generate_info);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (is_short)
    {
        MARK_SNAME(path);
    }
    else
    {
        MARK_LNAME(path);
    }

    #ifdef __MMI_AUDPLY_PLAYLIST_GEN_ASYN__
    //verify file  -- to do
    if (this->appended_number >= MMI_AUDPLY_MAX_PICK_PER_SLICE-1)
    {
        UI_character_type list_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1] = {0};

        list_cntx.file_num++;
        kal_wsprintf(list_path, "%c:\\%w\\%w_%d", (CHAR)g_audply.present_list, MMI_AUDPLY_DEFAULT_FOLDER, MMI_AUDPLY_DEFAULT_LIST_NAME_PREFIX, list_cntx.file_num-1);        
        mmi_ucs2ncpy((CHAR*)list_cntx.current_gen_list.path, (CHAR*)list_path, (SRV_FMGR_PATH_MAX_LEN+1));
        
        FS_Close(this->list_file_handle);
        this->list_file_handle = FS_Open(list_cntx.current_gen_list.path, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN | FS_READ_WRITE);
        if (this->list_file_handle < FS_NO_ERROR)
        {
            /* create new playlist file failed! */
			mmi_audply_playlist_display_popup(this->list_file_handle, NULL);
            /*when FAT_ALLOC_ERROR, need to delete the file or any other FS api will fail*/
            if (this->list_file_handle == FS_FAT_ALLOC_ERROR)
            {
                FS_Delete((PU16)list_cntx.current_gen_list.path);
                return FS_FAT_ALLOC_ERROR;
            }
        }
        this->appended_number = 0;

        if (list_cntx.file_num == 2)
        {
            /* audio player can start to play now. */
            this->phase = MMI_AUDPLY_LIST_PHASE_FINISH_ONE;
        }
    }
    #endif
    
    ret = FS_Write(this->list_file_handle, path, MMI_AUDPLY_LIST_RECORD_SIZE, &write_size);

    if (ret < FS_NO_ERROR)
    {
        return ret;
    }
    else if (write_size != MMI_AUDPLY_LIST_RECORD_SIZE)
    {
        ret = MMI_AUDPLY_PLAYLIST_ERR_WRITE_FAILED;
    }
	return ret;
}
#endif




#define AUTO_UPDATE_FUNCTION_BODY
#define AUTO_UPDATE_FUNCTION_BODY
#define AUTO_UPDATE_FUNCTION_BODY
#define AUTO_UPDATE_FUNCTION_BODY
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
#if defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__)
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_rename_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static void mmi_audply_update_rename_folder(MMI_BOOL is_folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    if (g_audply.list_auto_gen && is_folder)
    {
        UI_character_type list_path[SRV_FMGR_PATH_MAX_LEN + 1];
        UI_character_type present_folder[SRV_FMGR_PATH_MAX_LEN + 1];
        
        kal_wsprintf(present_folder, "%c:\\", (CHAR)g_audply.present_list);
        mmi_ucs2cat((CHAR*)present_folder, (CHAR*)MUSIC_FOLDER);
        
        ret = mmi_audply_playlist_check_and_set_default_playlist_path(list_path, (CHAR)g_audply.present_list);
        if (ret < FS_NO_ERROR)
        {
            return;
        }

        /* rename: from "My Music" to "my music" and something else... */
        if (!mmi_ucs2icmp((CHAR*)update_cntx.old_path, (CHAR*)update_cntx.new_path))
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_3);
            /*no need to modify list!*/
            return;
        }
        /* rename: from "my music" to something else... */
        else if (!mmi_ucs2nicmp((CHAR*)update_cntx.old_path, (CHAR*)present_folder, (U32)mmi_ucs2strlen((CHAR*)present_folder)))
        {
            /*since it's renamed, create an empty play list file*/
            FS_HANDLE fd ;
            if((fd = FS_Open((PU16)list_path, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN)) >= 0)
            {
                FS_Close(fd);
            }
            if (g_mmi_audply_init_done)
            {
                mmi_audply_need_load_playlist();
            }
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_4);
            /*delete list data file and reload list!*/
            return;
        }
        /* rename: from other name to "my music" or "My Music" or something else... */
        else if (!mmi_ucs2nicmp((CHAR*)update_cntx.new_path, (CHAR*)present_folder, (U32)mmi_ucs2strlen((CHAR*)present_folder)))
        {
            if (g_mmi_audply_init_done)
            {
                g_audply.seekable = MMI_TRUE;
                need_refresh_list = MMI_TRUE;
            }
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_5);
            /*only need refresh list!*/
            return;
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_6);
            /*no need to modify list! this is impossible!!!*/
            return;
        }
    }
    
    else
    #endif
    {
#ifdef __DRM_V02__

        CHAR* ext = NULL;
    
        ext = mmi_ucs2rchr((CHAR*)update_cntx.new_path, (U16)L'.');
        ext += 2;
        if (!mmi_ucs2nicmp((CHAR*)ext, (CHAR*)L"odf", (U32)mmi_ucs2strlen((CHAR*)ext)))
        {
            /* this is an odf file */
            if (DRM_is_archive(0, (PU16)update_cntx.new_path))
            {
                /* it is a multi-part odf file. */
                update_cntx.is_folder = MMI_TRUE;
            }
        }
#endif  /* __DRM_V02__ */
        mmi_audply_update_do_rename_folder();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_set_cache_buff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_audply_update_set_cache_buff(CHAR* buffer_ptr, U32 size_limit)
{
    cache_cntx.file_offset = 0;
    cache_cntx.cache_offset = 0;
    cache_cntx.cache_size = 0;
    cache_cntx.cache_limit = 0;

    if (buffer_ptr != NULL)
    {
        cache_cntx.cache_buffer_ptr = buffer_ptr;
        cache_cntx.cache_limit = size_limit;
        return MMI_TRUE;
    }
    else
    {
        cache_cntx.cache_buffer_ptr = NULL;
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_fill_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_audply_update_fill_cache(FS_HANDLE fd, U32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 read_size;
    S32 seek_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fd < 0)
    {
        /*fill cache - invalid parameter!*/
        return MMI_FALSE;
    }

    if (cache_cntx.cache_buffer_ptr == NULL)
    {
        /*fill cache - buffer_ptr = NULL!*/
        return MMI_FALSE;
    }
    
    if ((seek_ret = FS_Seek(fd, offset, FS_FILE_BEGIN)) >= 0)
    {
        if (seek_ret != offset)
        {
            /*seek failed!*/
            return MMI_FALSE;
        }

        if (FS_NO_ERROR <= (FS_Read(fd, cache_cntx.cache_buffer_ptr, cache_cntx.cache_limit, &read_size)))
        {
            cache_cntx.file_offset = offset;
            cache_cntx.cache_offset = 0;
            cache_cntx.cache_size = read_size;
            if (read_size == 0)
            {
                return MMI_FALSE;
            }
            else
            {
               return MMI_TRUE;
            }
        }
        else
        {
            /*fill cache - read file failed!*/
            return MMI_FALSE;
        }
    }
    else
    {
        /*fill cache - seek file failed!*/
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_backfill_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_audply_update_backfill_cache(FS_HANDLE fd, U32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 write_size;
    S32 seek_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (fd < 0)
    {
        /*fill cache - invalid parameter!*/
        return MMI_FALSE;
    }

    if (cache_cntx.cache_buffer_ptr == NULL)
    {
        /*fill cache - buffer_ptr = NULL!*/
        return MMI_FALSE;
    }
    
    if ((seek_ret = FS_Seek(fd, offset, FS_FILE_BEGIN)) >= 0)
    {
        if (seek_ret != offset)
        {
            return MMI_FALSE;
        }

        if (FS_NO_ERROR == (FS_Write(fd, cache_cntx.cache_buffer_ptr, cache_cntx.cache_size, &write_size)))
        {
            if (write_size == cache_cntx.cache_size)
            {
                //cache_cntx.file_offset = 0;
                cache_cntx.cache_offset = 0;
                cache_cntx.cache_size = 0;
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }
        else
        {
            /*backfill cache - write file error!*/
            return MMI_FALSE;
        }
    }
    else
    {
        /*backfill cache - write file failed!*/
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_do_rename_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static void mmi_audply_update_do_rename_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR current_drv = 0;
    CHAR* filename = NULL;
    UI_character_type new_path_buffer[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    MMI_BOOL need_reload_cache = MMI_TRUE;
    MMI_BOOL need_backfill_cache = MMI_FALSE;
    MMI_BOOL is_short = MMI_FALSE;
    U32 record_in_cache = 0;
    CHAR* path = NULL;
    S32 ret = FS_NO_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (update_cntx.present_list == -1)
    {
        if (g_mmi_audply_init_done)
        {
            current_drv = (CHAR)g_audply.present_list;
        }
        else
        {
            current_drv = (CHAR)update_cntx.old_path[0];
        }
        ret = mmi_audply_playlist_check_and_set_default_playlist_path(new_path_buffer, (CHAR)current_drv);
        if (ret < FS_NO_ERROR)
        {
            return;
        }   
        if (FS_NO_ERROR > (update_cntx.present_list = FS_Open((PU16)new_path_buffer, FS_READ_WRITE)))
        {
            /*can not open present list file!*/
            return;
        }
        FS_Seek(update_cntx.present_list, 0, FS_FILE_BEGIN);
        if (!mmi_audply_update_set_cache_buff((CHAR*)g_mmi_update_list_buff, g_mmi_update_list_buff_size))
        {
            MMI_ASSERT(0);
        }
        update_cntx.offset = 0;
    }
    
    for (; update_cntx.counter < (U32)list_cntx.current_list.total; )
    {
        if (need_reload_cache)
        {
            if (!mmi_audply_update_fill_cache(update_cntx.present_list, update_cntx.offset))
            {
                /*load cache failed!*/
                break;
            }
            else
            {
                need_reload_cache = MMI_FALSE;
                record_in_cache = (cache_cntx.cache_size / MMI_AUDPLY_LIST_RECORD_SIZE);
                update_cntx.offset += cache_cntx.cache_size;
            }
        }
        
        do
        {
            path = cache_cntx.cache_buffer_ptr + cache_cntx.cache_offset;
            is_short = MMI_FALSE;
            if (IS_SNAME2(path))
            {
                is_short = MMI_TRUE;
            }
            
            MARK_DRIVE_PS8(path);
            //like get a "D:/A/mp3.mp3"
            if (!mmi_ucs2nicmp((CHAR*)path, 
                            (CHAR*)update_cntx.old_path, 
                            update_cntx.old_path_len))
            {
                if (update_cntx.is_folder)
                {
                    //move "D:/A/"(old_path) to "D:/H/A/"(new_path)
                    filename = path + (mmi_ucs2strlen((CHAR*)update_cntx.old_path) * ENCODING_LENGTH);
                    mmi_ucs2cpy((CHAR*)new_path_buffer, (CHAR*)update_cntx.new_path);
                    mmi_ucs2cat((CHAR*)new_path_buffer, (CHAR*)filename);

                    if (is_short)
                    {
                        MARK_SNAME(new_path_buffer);
                    }
                    else
                    {
                        MARK_LNAME(new_path_buffer);
                    }
                    if ((SRV_FMGR_PATH_MAX_LEN+1) < mmi_ucs2strlen((CHAR*)new_path_buffer))
                    {
                        /*new path is too long!*/
                        break;
                    }
                    mmi_ucs2ncpy((CHAR*)path, (CHAR*)new_path_buffer, MMI_AUDPLY_LIST_RECORD_SIZE);
                }
                else
                {
                    //move "D:/A/mp3.mp3"(old_path) to "D:/H/mp3.mp3"(new_path)
                    MARK_LNAME(update_cntx.new_path);
                    mmi_ucs2ncpy((CHAR*)path, 
                        (CHAR*)update_cntx.new_path, MMI_AUDPLY_LIST_RECORD_SIZE);

                    /* reset loading file's filename and title in g_audply */
                    if (g_mmi_audply_init_done)
                    {
                        U32 index = update_cntx.counter + (cache_cntx.cache_size / MMI_AUDPLY_LIST_RECORD_SIZE) - record_in_cache;
                        if (index == list_cntx.current_list.pick_index)
                        {
                            CHAR* filename = mmi_ucs2rchr((CHAR*)update_cntx.new_path, (U16)L'\\');
                            CHAR* dot = mmi_ucs2rchr((CHAR*)update_cntx.new_path, (U16)L'.');
                            
                            mmi_ucs2ncpy((CHAR*)g_audply.filefullname, 
                                (CHAR*)update_cntx.new_path, MMI_AUDPLY_LIST_RECORD_SIZE);
                            mmi_ucs2ncpy((CHAR*)g_audply.title, (CHAR*)(filename + 2), (U32)(((dot - 2) - filename) / 2));
			                MARK_DRIVE(g_audply.filefullname);
                        }
                    }
                }
                need_backfill_cache = MMI_TRUE;
            }
			else
			{
				if (is_short)
				{
					MARK_SNAME2(path);
				}
				else
				{
					MARK_LNAME2(path);
				}
			}
			cache_cntx.cache_offset += MMI_AUDPLY_LIST_RECORD_SIZE;

        } while((--record_in_cache) > 0);

        update_cntx.counter += (cache_cntx.cache_size / MMI_AUDPLY_LIST_RECORD_SIZE);

        if (need_backfill_cache)
        {
            need_backfill_cache = MMI_FALSE;
            if (!mmi_audply_update_backfill_cache(update_cntx.present_list, cache_cntx.file_offset))
            {                
                /*backfill cache failed!*/
                break;
            }
        }
        need_reload_cache = MMI_TRUE;
    }
    FS_Close(update_cntx.present_list);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_delete_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static void mmi_audply_update_delete_folder(MMI_BOOL is_folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    if (g_audply.list_auto_gen && is_folder)
    {
        UI_character_type list_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
        UI_character_type present_folder[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
        
        kal_wsprintf(present_folder, "%c:\\", (CHAR)g_audply.present_list);
        mmi_ucs2cat((CHAR*)present_folder, (CHAR*)MUSIC_FOLDER);
        
        ret = mmi_audply_playlist_check_and_set_default_playlist_path(list_path, (CHAR)g_audply.present_list);
        if (ret < FS_NO_ERROR)
        {
            return;
        }
        /* delete: delete "My Music" folder. */
              
        if (!mmi_ucs2cmp((CHAR*)update_cntx.old_path, (CHAR*)present_folder))
        {
			FS_HANDLE fd ;
            if((fd = FS_Open((PU16)list_path, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN)) >= 0)
            {
                FS_Close(fd);
            }
            if (g_mmi_audply_init_done)
            {
                need_reload_list = MMI_TRUE;
            }
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_7);
            /*delete list data file and reload list!*/
            return;
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_6);
            /*no need to modify list! this is impossible!!!*/ 
            return;
        }
    }
    else
    #endif
    {
        mmi_audply_update_do_delete_folder();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_do_rename_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static void mmi_audply_update_do_delete_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR current_drv = 0;
    UI_character_type buffer[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    CHAR* path = NULL;
    S32 ret = FS_NO_ERROR;
    S32 total_records = list_cntx.current_list.total;   
    S32 current_index = list_cntx.current_list.pick_index;
    U32 record_in_cache = 0;
    U32 buffer_size; 
    MMI_BOOL need_reload_cache = MMI_TRUE;
    MMI_BOOL is_short = MMI_FALSE;
    MMI_BOOL fs_error = MMI_FALSE;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (update_cntx.present_list == -1)
    {
        if (g_mmi_audply_init_done)
        {
            current_drv = (CHAR)g_audply.present_list;
        }
        else
        {
            current_drv = (CHAR)update_cntx.old_path[0];
        }
        ret = mmi_audply_playlist_check_and_set_default_playlist_path(buffer, (CHAR)current_drv);
        if (ret < FS_NO_ERROR)
        {
            return;
        }
        if (FS_NO_ERROR > (update_cntx.present_list = FS_Open((PU16)buffer, FS_READ_WRITE)))
        {
            /*can not open present list file!*/
            return;
        }

        if (update_cntx.temp_file == -1)
        {
            kal_wsprintf(buffer, "%c:\\", current_drv);
            mmi_ucs2cat((CHAR*)buffer, (CHAR*)MMI_AUDPLY_DEFAULT_FOLDER);
            mmi_ucs2cat((CHAR*)buffer, (CHAR*)L"\\");
            mmi_ucs2cat((CHAR*)buffer, (CHAR*)L"~");
            mmi_ucs2cat((CHAR*)buffer, (CHAR*)MMI_AUDPLY_DEFAULT_LIST_NAME);
            update_cntx.temp_file= FS_Open((PU16)buffer, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN);
            ASSERT(update_cntx.temp_file != 0);
            if (update_cntx.temp_file < 0)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_8);
                /*can not create temp file!!!*/
                FS_Close(update_cntx.present_list);
                return;
            }
        }

        FS_Seek(update_cntx.present_list, 0, FS_FILE_BEGIN);
        if (!mmi_audply_update_set_cache_buff((CHAR*)g_mmi_update_list_buff, g_mmi_update_list_buff_size))
        {
            MMI_ASSERT(0);
        }
        update_cntx.offset = 0;
    }
    
    for (; update_cntx.counter < (U32)total_records; )
    {
        if (need_reload_cache)
        {
            if (!mmi_audply_update_fill_cache(update_cntx.present_list, cache_cntx.file_offset))
            {
                /*load cache failed!*/
                fs_error = MMI_TRUE;
                break;
            }
            else
            {
                need_reload_cache = MMI_FALSE;
                record_in_cache = (cache_cntx.cache_size / MMI_AUDPLY_LIST_RECORD_SIZE);
                cache_cntx.file_offset += cache_cntx.cache_size;
            }
        }
        
        do
        {
            MMI_BOOL need_remove = MMI_FALSE;
            
            path = cache_cntx.cache_buffer_ptr + cache_cntx.cache_offset;
            is_short = MMI_FALSE;
            if (IS_SNAME2(path))
            {
                is_short = MMI_TRUE;
            }
            
            MARK_DRIVE_PS8(path);
            if (!mmi_ucs2nicmp((CHAR*)path, 
                            (CHAR*)update_cntx.old_path, 
                            update_cntx.old_path_len))
            {
                //bql: duplicate code for need_remove init.
                //consider to modify as:
                /*
                if (FS_GetAttributes((PU16)path) < 0)
                {
                    need_remove = MMI_TRUE;
                }
                else
                {
                    need_remove = MMI_FALSE;
                }*/
                if (!mmi_ucs2nicmp((CHAR*)path, (CHAR*)g_audply.filefullname, (SRV_FMGR_PATH_MAX_LEN+1)))
                {
                    if (FS_GetAttributes((PU16)path) < 0)
                    {
                        /* can remove */
                        need_remove = MMI_TRUE;
                    }
                    else
                    {
                        /* CAN NOT REMOVE! */
                        need_remove = MMI_FALSE;
                    }
                }
                else
                {
                    //need_remove = MMI_TRUE;
                    if (FS_GetAttributes((PU16)path) < 0)
                    {
                        /* can remove */
                        need_remove = MMI_TRUE;
                    }
                    else
                    {
                        /* CAN NOT REMOVE! */
                        need_remove = MMI_FALSE;
                    }
                }
            }
            
            if (need_remove)
            {
                U8 i = 0;
                for (i = 0; i < record_in_cache; i++)
                {
                    //shift left for one MMI_AUDPLY_LIST_RECORD_SIZE
                    memcpy((path + i * MMI_AUDPLY_LIST_RECORD_SIZE), (path + (i + 1) * MMI_AUDPLY_LIST_RECORD_SIZE), MMI_AUDPLY_LIST_RECORD_SIZE);
                }
                /* update relative variable in struct "g_audply" */
                if (g_mmi_audply_init_done)
                {
                    U32 index = update_cntx.counter;
                    
                    if ((--total_records) < 0)
                    {
                        total_records = 0;
                    }
                    
                    if (current_index > (S32)index)
                    {
                        if ((--current_index) < 0)
                        {
                            current_index = 0;
                        }
                    }
                    else if (current_index == index)
                    {
                        mmi_audply_clear_play_seconds();
                    }
                }
                cache_cntx.cache_size -= MMI_AUDPLY_LIST_RECORD_SIZE;
                update_cntx.deleted++;
            } 
            else
            {
                if (is_short)
                {
                    MARK_SNAME2(path);
                }
                else
                {
                    MARK_LNAME2(path);
                }
                update_cntx.counter++;
                cache_cntx.cache_offset += MMI_AUDPLY_LIST_RECORD_SIZE;
            }
            
        } while((--record_in_cache) > 0);
        buffer_size = cache_cntx.cache_size;

        if (!mmi_audply_update_backfill_cache(update_cntx.temp_file, update_cntx.offset))
        {                
            /*backfill cache failed!*/
            fs_error = MMI_TRUE;
            break;
        }
        else
        {
            update_cntx.offset += buffer_size;
        }

        need_reload_cache = MMI_TRUE;
    }

    if (!fs_error)
    {   
        S32 seek_ret;
        seek_ret = FS_Seek(update_cntx.present_list, 
            update_cntx.counter * MMI_AUDPLY_LIST_RECORD_SIZE, FS_FILE_BEGIN);
        
        if ((update_cntx.counter * MMI_AUDPLY_LIST_RECORD_SIZE) != seek_ret)
        {
            fs_error = MMI_TRUE;
        }
        else
        {
            if (FS_NO_ERROR == FS_Truncate(update_cntx.present_list))
            {
                FS_Close(update_cntx.present_list);
                FS_Close(update_cntx.temp_file);

                /* replace old file */
                kal_wsprintf(update_cntx.old_path, "%c:\\", current_drv);
                mmi_ucs2cat((CHAR*)update_cntx.old_path, (CHAR*)MMI_AUDPLY_DEFAULT_FOLDER);
                mmi_ucs2cat((CHAR*)update_cntx.old_path, (CHAR*)L"\\");
                mmi_ucs2cat((CHAR*)update_cntx.old_path, (CHAR*)L"~");
                mmi_ucs2cat((CHAR*)update_cntx.old_path, (CHAR*)MMI_AUDPLY_DEFAULT_LIST_NAME);

                kal_wsprintf(update_cntx.new_path, "%c:\\", current_drv);
                mmi_ucs2cat((CHAR*)update_cntx.new_path, (CHAR*)MMI_AUDPLY_DEFAULT_FOLDER);
                mmi_ucs2cat((CHAR*)update_cntx.new_path, (CHAR*)L"\\");
                //mmi_ucs2cat((CHAR*)update_cntx.new_path, (CHAR*)L"~");
                mmi_ucs2cat((CHAR*)update_cntx.new_path, (CHAR*)MMI_AUDPLY_DEFAULT_LIST_NAME);

                if (FS_NO_ERROR == FS_Delete((PU16)update_cntx.new_path))
                {
                    FS_Rename((PU16)update_cntx.old_path, (PU16)update_cntx.new_path);
                    list_cntx.current_list.total = total_records;
                    list_cntx.current_list.pick_index = current_index;
                }
                else
                {
                    FS_Delete((PU16)update_cntx.old_path);
                }
            }
            else
            {
                fs_error = MMI_TRUE;
            }
        }
    }


    if (fs_error)
    {
        FS_Close(update_cntx.present_list);
        FS_Close(update_cntx.temp_file);
        
        kal_wsprintf(update_cntx.old_path, "%c:\\", current_drv);
        mmi_ucs2cat((CHAR*)update_cntx.old_path, (CHAR*)MMI_AUDPLY_DEFAULT_FOLDER);
        mmi_ucs2cat((CHAR*)update_cntx.old_path, (CHAR*)L"\\");
        mmi_ucs2cat((CHAR*)update_cntx.old_path, (CHAR*)L"~");
        mmi_ucs2cat((CHAR*)update_cntx.old_path, (CHAR*)MMI_AUDPLY_DEFAULT_LIST_NAME);

        FS_Delete((PU16)update_cntx.old_path);
    }

    /* clear dynamic list buffer */
    if (g_mmi_audply_init_done)
    {
        if (list_cntx.current_list.pick_index == list_cntx.current_list.total)
        {
            if (list_cntx.current_list.total == 0)
            {
                mmi_audply_playlist_init();
            }
            else
            {
                mmi_audply_playlist_set_start(0);
                mmi_audply_playlist_apply_picked_file();
            }
        }
        else if (list_cntx.current_list.total == 0)
        {
            mmi_audply_playlist_init();
        }
        else
        {
            mmi_audply_playlist_set_start(list_cntx.current_list.pick_index);
            mmi_audply_playlist_apply_picked_file();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_check_need_modify
 * DESCRIPTION
 *  check a file path whether in list.
 * PARAMETERS
 *  CHAR*         [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static U32 mmi_audply_update_does_record_in_list(const UI_string_type list_path, const CHAR* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 match = 0;
    U32 counter;
    U32 read_size;
    FS_HANDLE fd;
    UI_character_type buffer[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (FS_NO_ERROR > (fd = FS_Open((PU16)list_path, FS_READ_WRITE)))
    {
        /*can not open present list file!*/
        return 0;
    }
    
    for (counter = 0; counter < (U32)list_cntx.current_list.total; counter++)
    {
        if (FS_NO_ERROR== FS_Read(fd, &buffer, MMI_AUDPLY_LIST_RECORD_SIZE, &read_size))
        {
            if (read_size != MMI_AUDPLY_LIST_RECORD_SIZE)
            {  
                /* get end of file. */
                /*break from seek loop!*/ 
                break;
            }
            
            MARK_DRIVE(buffer);
            if (!mmi_ucs2nicmp((CHAR*)file_path, (CHAR*)buffer, (U32)mmi_ucs2strlen((CHAR*)buffer)))
            {
                match++;
            }
        }
    }
    FS_Close(fd);

    return match;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __DRM_V02__
/* under construction !*/
#endif
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
#ifdef __DRM_V02__
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
#endif  /* __DRM_V02__ */
/* under construction !*/
/* under construction !*/
#ifdef __DRM_V02__
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
#endif  /* __DRM_V02__ */
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
#endif
#endif /* defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__) */
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */
#endif /* __MMI_AUDIO_PLAYER__ */ 
#else /* __MMI_ULTRA_SLIM_AUDIO_PLAYER__ */

#ifdef __MMI_AUDIO_PLAYER__


#include "stdlib.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "CommonScreens.h"
#include "FileMgrType.h"
#include "FileMgrGProt.h"
#include "ProfilesSrvGProt.h"
#include "AudioPlayerDef.h"
#include "AudioPlayerType.h"
#include "AudioPlayerProt.h"
#include "AudioPlayerPlayList.h"
#include "Mmi_frm_scenario_gprot.h"
#include "FilemgrCuiGprot.h"
#include "menucuigprot.h"
#include "AudioPlayerResDef.h"
#include "Filemgrsrvgprot.h"
#include "gui_data_types.h"
#include "MMIDataType.h"
#include "mmi_rp_app_audioplayer_def.h"
#include "kal_general_types.h"
#include "fs_type.h"
#include "GlobalConstants.h"
#include "AlertScreen.h"
#include "fs_errcode.h"
#include "mmi_media_app_trc.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "string.h"
#include "kal_public_api.h"
#include "Unicodexdcl.h"
#include "fs_func.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "mmi_frm_mem_gprot.h"
#include "CustDataRes.h"
#include "wgui_categories_list.h"
#include "gui_typedef.h"
#include "mmi_frm_input_gprot.h"
#include "stack_config.h"
#include "CommonScreensResDef.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_rp_file_type_def.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "gui.h"
#include "USBSrvGprot.h"

#ifdef __OTG_ENABLE__
#include "usb_host_ms_if.h"
#endif 

#include "app_str.h"

/* 
**  mp3 mp2 amr aac awb bsac are the four audio types which
**  requires building cache to seek, so we put them in the frist six items
**  for build cache deciding api to reference.
*/
const static UI_character_type audio_file_exts[][5] = 
{
#ifdef DAF_DECODE
    L"mp3",
#ifdef MUSICAM_DECODE    
    L"mp2",
#endif    
#endif 
    L"amr", 
#ifdef AAC_DECODE
    L"aac",
#endif 
#ifdef AMRWB_DECODE
    L"awb",
#endif 
#ifdef BSAC_DECODE
/* under construction !*/
#endif
#ifdef __DRM_V02__
    L"odf",
#endif
    L"wav",   
    L"mid",
    L"midi", 
    L"imy",
//    L"vm ",
#ifdef AIFF_DECODE
    L"aif",
    L"aiff",
    L"aifc",
#endif
#ifdef AU_DECODE
    L"au",
#endif
#ifdef SND_DECODE
    L"snd",
#endif
#ifdef M4A_DECODE
    L"m4a",
#endif 
#ifdef YAMAHA_MA3
    L"mmf",
#endif 
#ifdef WMA_DECODE
    L"wma",
#endif 
#if defined(__MMI_PURE_AUDIO__)
    L"3gp",
    L"3g2",
    L"mp4",
#endif

#ifdef __RM_DEC_SUPPORT__
	L"ra",
#endif
	
#ifdef __APE_DECODE__
	L"ape",
#endif    
#ifdef __FLAC_DECODE__
    L"flac",
#endif

#if defined(__VORBIS_DECODE__) && !defined(__VORBIS_DECODE_SLIM__)
    L"OGG",
#endif
    

    L"\0"   /* end of list */
};

#if defined(MT6223) || defined(MT6223P)
const static UI_character_type audio_file_not_support_a2dp_exts[][5] = 
{
    L"AMR",
    L"\0"   /* end of list */
};
#endif


const U16 audio_file_icon_ids[] = 
{
#ifdef DAF_DECODE
    IMG_ID_AUDPLY_FILE_AUD_ICON,
#ifdef MUSICAM_DECODE
    IMG_ID_AUDPLY_FILE_AUD_ICON,
#endif
#endif
    IMG_ID_AUDPLY_FILE_AMR_ICON, 
#ifdef AAC_DECODE
    IMG_ID_AUDPLY_FILE_AAC_ICON,
#endif 
#ifdef AMRWB_DECODE
    IMG_ID_AUDPLY_FILE_AWB_ICON,
#endif
#ifdef BSAC_DECODE
/* under construction !*/
#endif
#ifdef __DRM_V02__
    IMG_ID_FMGR_ICON_FILE_TYPE_ODF,
#endif
    IMG_ID_AUDPLY_FILE_WAV_ICON,
    IMG_ID_AUDPLY_FILE_MID_ICON,
    IMG_ID_AUDPLY_FILE_MID_ICON,
    IMG_ID_AUDPLY_FILE_IMY_ICON
//    IMG_ID_AUDPLY_FILE_AUD_ICON, // for .VM
#ifdef AIFF_DECODE
    ,IMG_ID_AUDPLY_FILE_AIF_ICON
    ,IMG_ID_AUDPLY_FILE_AIF_ICON
    ,IMG_ID_AUDPLY_FILE_AIF_ICON
#endif
#ifdef AU_DECODE
    ,IMG_ID_AUDPLY_FILE_AU_ICON
#endif
#ifdef SND_DECODE
    ,IMG_ID_AUDPLY_FILE_SND_ICON
#endif
#ifdef M4A_DECODE
  , IMG_ID_AUDPLY_FILE_M4A_ICON
#endif 
#ifdef YAMAHA_MA3
  , IMG_ID_AUDPLY_FILE_MMF_ICON
#endif 
#ifdef WMA_DECODE
  , IMG_ID_AUDPLY_FILE_WMA_ICON
#endif 
#if defined(__MMI_PURE_AUDIO__)
  ,IMG_ID_AUDPLY_FILE_3GP_ICON
  ,IMG_ID_AUDPLY_FILE_3GP_ICON
  ,IMG_ID_AUDPLY_FILE_MP4_ICON
#endif

#ifdef __RM_DEC_SUPPORT__
    ,IMG_ID_AUDPLY_FILE_RA_ICON
#endif

#ifdef __APE_DECODE__
    ,IMG_ID_AUDPLY_FILE_APE_ICON
#endif
#ifdef __FLAC_DECODE__
    ,IMG_ID_AUDPLY_FILE_FLAC_ICON
#endif


#if defined(__VORBIS_DECODE__) && !defined(__VORBIS_DECODE_SLIM__)
    ,IMG_ID_AUDPLY_FILE_COMMON_ICON
#endif


};
extern U8 PhnsetGetDefEncodingType(void);
extern S16 g_audply_main_selected_button;

extern MMI_BOOL mdi_audio_is_file_seekable(void *file_name);



#define SINGLE_LIST_VARIABLES
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)

static mmi_ret mmi_audply_playlist_proc(mmi_event_struct *evt);
static mmi_ret mmi_audply_option_proc(mmi_event_struct *evt);



/* for regenerate/refresh list */
MMI_BOOL need_refresh_list = MMI_FALSE;
MMI_BOOL need_reload_list = MMI_FALSE;

#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#endif

#if defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__)
/* steal using subMenuData as a buffer to move data in play list file */
extern U8 subMenuData[MAX_SUB_MENUS][MAX_SUB_MENU_SIZE];
static CHAR* g_mmi_update_list_buff = (CHAR*)subMenuData;
static U32 g_mmi_update_list_buff_size = 4698;

static audply_auto_update_cache_struct cache_cntx;
static audply_auto_update_struct update_cntx;
#endif

#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */

#define MULTIPLE_LIST_VARIABLES

#define COMMON_VARIABLES
mmi_audply_playlist_cntx_struct list_cntx;
extern MMI_BOOL g_mmi_audply_init_done;
extern audply_struct g_audply;
extern mmi_id g_details_id;


#define GENERATER_FUNCTION_PROTOTPYE
static void mmi_audply_playlist_generate(UI_string_type fullPath, int is_short);
static void mmi_audply_playlist_generate_cancel(void);
static void mmi_audply_playlist_generate_internal(void);
static void mmi_audply_playlist_generate_from_folder(UI_string_type path, MMI_BOOL is_multi_part_odf);
static S32 mmi_audply_playlist_generate_append_one(UI_string_type path, MMI_BOOL is_short);
//static void mmi_audply_playlist_generate_search(void);
//static void mmi_audply_playlist_generate_forwards(void);
//static void mmi_audply_playlist_generate_backwards(void);

static void mmi_audply_playlist_generate_wait_screen_entry(void);
static void mmi_audply_playlist_generate_finish(void);
static void mmi_audply_playlist_generate_error_hdlr(void);
//static void mmi_audply_playlist_generate_cancel_hdlr(void);
//static S32 mmi_audply_playlist_generate_write_to_file(UI_string_type path, MMI_BOOL is_short);

#ifdef __DRM_V02__
static void mmi_audply_playlist_generate_search_odf(void);
static void mmi_audply_playlist_generate_search_for_drm(UI_string_type odf_path);
#endif

static S32 mmi_audply_playlist_generate_append_one_single(UI_string_type path, MMI_BOOL is_short);
static void mmi_audply_playlist_generate_finish_single(void);
//static void mmi_audply_playlist_generate_error_hdlr_single(void);
static void mmi_audply_playlist_generate_cancel_hdlr_single(void);
//static S32 mmi_audply_playlist_generate_write_to_file_single(UI_string_type path, MMI_BOOL is_short);
static void mmi_audlpy_plst_fmgr_file_selector_handle(cui_file_selector_result_event_struct *file_select);


#define SINGLE_STATIC_FUNCTION_PROTOTYPE
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
static MMI_BOOL mmi_audply_playlist_check_filename_len(const UI_string_type fullfilename);
static U8 mmi_audply_playlist_get_path_single(UI_string_type fullfilename, S32 index);
static void mmi_audply_playlist_entry_playlist_option_single(void);
static void mmi_audply_playlist_exit_playlist_single(void);
static void mmi_audply_playlist_entry_playlist_single(void);
static S32 mmi_audply_playlist_get_item_async(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_audply_plst_tap_callback(mmi_tap_type_enum tap_type,S32 index);
#endif

static S32 mmi_audply_playlist_load_cache(S32 start_index);
static S32 mmi_audply_playlist_get_list(U16 *cached_num, U16 start_index);
static void mmi_audply_playlist_entry_remove_confirm(void);
static void mmi_audply_playlist_entry_remove_all_confirm(void);
static mmi_ret mmi_audply_playlist_entry_remove_all_confirm_cb(mmi_alert_result_evt_struct *evt);
static mmi_ret mmi_audply_playlist_entry_remove_confirm_cb(mmi_alert_result_evt_struct *evt);
static void mmi_audply_playlist_add_to_ring(void);
static void mmi_audply_playlist_refresh(void);
static void mmi_audply_playlist_add(void);
static void mmi_audply_playlist_initiate_play(void);
static void mmi_audply_playlist_add_file_hdlr(UI_string_type fullPath, int is_short);
#define AUTO_UPDATE_FUNCTION_PROTOTYPE
#if defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__)
static MMI_BOOL mmi_audply_update_set_cache_buff(CHAR* buffer_ptr, U32 size_limit);
static MMI_BOOL mmi_audply_update_fill_cache(FS_HANDLE fd, U32 offset);
static MMI_BOOL mmi_audply_update_backfill_cache(FS_HANDLE fd, U32 offset);
static void mmi_audply_update_rename_folder(MMI_BOOL is_folder);
static void mmi_audply_update_do_rename_folder(void);
static void mmi_audply_update_delete_folder(MMI_BOOL is_folder);
static void mmi_audply_update_do_delete_folder(void);
static U32 mmi_audply_update_does_record_in_list(const UI_string_type list_path, const CHAR* file_path);
#endif
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */

#define MULTIPLE_STATIC_FUNCTION_PROTOTYPE

#define COMMON_STATIC_FUNCTION_PROTOTPYE
static void mmi_audply_playlist_reload_list(void);
static void mmi_audply_playlist_clear_list_browser_gui_buffer(void);
static void mmi_audply_playlist_error_hdlr_ext(void);

#define COMMON_STATIC_FUNCTION_BODY
#define COMMON_STATIC_FUNCTION_BODY
#define COMMON_STATIC_FUNCTION_BODY
#define COMMON_STATIC_FUNCTION_BODY

#ifdef AUDPLY_DEBUG
static U32 mmi_audply_get_current_time(void)
{
    kal_uint32 ticks = 0;
    kal_uint32 time = 0;
    kal_get_time(&ticks);
    time = kal_ticks_to_milli_secs(ticks);
    return time;
}
#endif


static void mmi_audply_playlist_refresh_ext(void);
static S32 mmi_audply_playlist_read_header(S16 *buffer);
static U16 mmi_audply_playlist_get_count(void);
static void mmi_audply_playlist_init_header(MMI_BOOL delete_all);
static S16 mmi_audply_playlist_get_abs_pos(void);
static void mmi_audply_playlist_cancel_init (void);
mmi_audply_playlist_mgr_struct     *g_audply_playlist;
mmi_audply_playlist_action_enum    g_audply_playlist_action;
S16                                g_playlist_result;
U16                                g_absolute_count;
static FS_HANDLE                   add_file_cursor;


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_reload_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_reload_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 total = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_cntx.list_ui.cache_end_index = 0;
    list_cntx.list_ui.cache_start_index = 0;
    list_cntx.list_ui.total = list_cntx.current_list.total;
    mmi_audply_playlist_get_list(&total, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_clear_list_browser_gui_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_clear_list_browser_gui_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_node_struct new_node_info;
    new_node_info.id = SCR_ID_AUDPLY_LIST_BROWSER;
    new_node_info.entry_proc = (mmi_proc_func)mmi_audply_playlist_entry_playlist_single;
    mmi_frm_scrn_replace (GRP_ID_AUDPLY_LIST_BROWSER, SCR_ID_AUDPLY_LIST_BROWSER, &new_node_info);
}

#define SINGLE_LIST_CODE
#define SINGLE_LIST_CODE
#define SINGLE_LIST_CODE
#define SINGLE_LIST_CODE

#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_need_generate_playlist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void               
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_need_generate_playlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type default_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    FS_HANDLE fs_hdlr = -1;
    S32 ret = FS_NO_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAYLIST_NEED_GEN);

    /* becasue the list will be initialization after refresh. */
    mmi_audply_stop_playing();  
    /* clear path and title in global context. */
    g_audply.filefullname[0] = 0;
    g_audply.title[0] = 0;
    g_audply.duration = 0;
#ifdef __MMI_SUBLCD__
    g_audply.sub_title[0] = 0;
#endif
    g_audply.seekable = MMI_FALSE;
    /* reset variables. */
    memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
    list_cntx.current_list.pick_index = -1;
    /* reset default path. check default playlist folder. compose playlist file path. */
    ret = mmi_audply_playlist_check_and_set_default_playlist_path(
                   list_cntx.current_list.path, (CHAR)g_audply.present_list);
    if (ret < FS_NO_ERROR)
    {
        goto FILE_ERROR;
    }

    /* compose refresh folder default path. */
    kal_wsprintf(default_path, "%c:\\", (CHAR)g_audply.present_list);    
#ifdef __MMI_MY_FAVORITE__
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
#endif  /* __MMI_MY_FAVORITE__ */
    mmi_ucs2cat((CHAR*)default_path, (CHAR*)MUSIC_FOLDER);

    /* check default directory. */
    fs_hdlr = FS_Open(default_path, FS_OPEN_DIR | FS_READ_ONLY);

    if (fs_hdlr < FS_NO_ERROR)
    {       
        if (fs_hdlr == FS_FAT_ALLOC_ERROR)
        {
            goto FILE_ERROR;
        }
        /* create default folder. */
        fs_hdlr = FS_CreateDir(default_path);
        if (FS_NO_ERROR > fs_hdlr)
        {
            goto FILE_ERROR;
        }
        else
        {
            /* create new playlist file. */
            fs_hdlr = FS_Open(list_cntx.current_list.path, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN);
            if (fs_hdlr < FS_NO_ERROR)
            {
                goto FILE_ERROR;
            }
            else
        	{
                FS_Close(fs_hdlr);
                fs_hdlr = -1;
                mmi_popup_display_ext(
                    STR_GLOBAL_EMPTY, 
                    MMI_EVENT_FAILURE, 
                    NULL);
				mmi_audply_need_load_playlist();
        	}
        }
    }
    else
    {
        FS_Close(fs_hdlr);
        g_audply.successive_fail_num = 0;

        /* clear old file. */
        fs_hdlr = FS_Open(list_cntx.current_list.path, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN | FS_READ_WRITE);
        if (fs_hdlr < FS_NO_ERROR)
        {
            goto FILE_ERROR;
        }
        else
        {
            /*  
            **  do not close file handler here, 
            **  this handle will be use by 
            **  mmi_audply_playlist_generate_from_folder().
            */
			list_cntx.current_list.fs_hdlr = fs_hdlr;
            mmi_audply_playlist_init_header(MMI_TRUE);
            mmi_audply_playlist_generate_from_folder(default_path, MMI_FALSE);
             /* Check FALG*/
            if (mmi_frm_scrn_get_neighbor_id(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,MMI_FRM_NODE_AT_LATEST_FLAG) == SCR_ID_AUDPLY_LIST_BROWSER)
            {
                mmi_frm_node_struct new_node_info;
                new_node_info.id = SCR_ID_AUDPLY_LIST_BROWSER;
                new_node_info.entry_proc = (mmi_proc_func)mmi_audply_playlist_entry_playlist_single;
                mmi_frm_scrn_replace (GRP_ID_AUDPLY_LIST_BROWSER, SCR_ID_AUDPLY_LIST_BROWSER, &new_node_info);

            }
        } 
    }
return;
FILE_ERROR:
    mmi_audply_playlist_display_popup(fs_hdlr, NULL);
    if (fs_hdlr == FS_FAT_ALLOC_ERROR)
    {
        FS_Delete((PU16)list_cntx.current_list.path);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_need_load_playlist
 * DESCRIPTION
 *  
 * PARAMETERS      
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_need_load_playlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* becasue the list will be initialization. */
    mmi_audply_stop_playing();
    /* re-initialize list */
    mmi_audply_playlist_init(); 
	if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,MMI_FRM_NODE_ALL_FLAG) == MMI_RET_OK)
    {
        mmi_scrn_node_struct scr_node;
		//historyNode* scr_history;
    
	    if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,MMI_FRM_NODE_ALL_FLAG))
	    {
	        if (mmi_frm_scrn_get_info(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,&scr_node) == MMI_RET_OK)
	        {

            //if (GetHistoryPointer(SCR_ID_AUDPLY_LIST_BROWSER, &scr_history))
	        //{
	            if (scr_node.gui_buf)
	            {
	                OslMfree(scr_node.gui_buf);
	                scr_node.gui_buf = NULL;
	            }
                
	        }
	    }   
    }
    /* pick one and get its information then show them in main screen */
    if (mmi_audply_playlist_pick_next() >= 0)
    {
        mmi_audply_playlist_apply_picked_file();
    }
}




/*****************************************************************************
 * FUNCTION
 *  mmi_audply_single_highlight_hdlr_init
 * DESCRIPTION
 *  init highlight handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_single_highlight_hdlr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
}

#define SINGLE_STATIC_FUNCTION_BODY_BEGIN
#define SINGLE_STATIC_FUNCTION_BODY_BEGIN
#define SINGLE_STATIC_FUNCTION_BODY_BEGIN
#define SINGLE_STATIC_FUNCTION_BODY_BEGIN




/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_check_filename_len
 * DESCRIPTION
 *  check if filename is longer than we can sustain
 * PARAMETERS  
 *  fullfilename        [IN]        
 * RETURNS
 *  BOOL
 *****************************************************************************/
static MMI_BOOL mmi_audply_playlist_check_filename_len(const UI_string_type fullfilename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* ch = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ch = mmi_ucs2rchr((CHAR*)fullfilename, (U16)(L'\\'));

    if (ch == NULL)
    {
        return MMI_FALSE;
    }
    
    if (mmi_ucs2strlen((CHAR*)(ch + 2)) > SRV_FMGR_PATH_MAX_FILE_NAME_LEN)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_path_single
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fullfilename    [IN]
 *  index           [IN]
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_audply_playlist_get_path_single(UI_string_type fullfilename, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = 0;
    U32 size;
    FS_HANDLE fd; 

    S16 track_abs_index, i;
    U32 file_seek;
    S32 ret = FS_NO_ERROR;
    S16  *audply_plylist_header = NULL;
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list->fs_hdlr > 0)
    {
        fd = list->fs_hdlr;
    }
    else
    {
    fd = FS_Open(list_cntx.current_list.path, FS_READ_ONLY);
    }

    audply_plylist_header = (S16*) OslMalloc((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2);
    memset (audply_plylist_header, 0, ((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2));
    ret = mmi_audply_playlist_read_header(audply_plylist_header);
    if (ret < FS_NO_ERROR)
    {
        OslMfree (audply_plylist_header);
        if (list->fs_hdlr <= 0)
        {
        FS_Close(fd);
        }
        return ret;
    }

    for (i = 0; audply_plylist_header[i] != index && i < MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT; i++);
    track_abs_index = i;

    file_seek = track_abs_index * MMI_AUDPLY_PATH_LEN + 2 * (MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2);
    FS_Seek(fd, file_seek, FS_FILE_BEGIN);
    
    if (fd >= 0)
    {
        if (FS_Read(fd, fullfilename, MMI_AUDPLY_LIST_RECORD_SIZE, &size) >= FS_NO_ERROR)
        {
            if (size > 0)
            {
                result = IS_SNAME(fullfilename) ? 2 : 1;
                MARK_DRIVE(fullfilename);
                fullfilename[EOS(size)] = 0;    /* make it must be in boundary */
            }
        }
        if (list->fs_hdlr <= 0)
        {
        FS_Close(fd);
    }
    }

    if (!result)
    {
        fullfilename[0] = 0;
    }

    OslMfree (audply_plylist_header);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_entry_playlist_option_single
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_entry_playlist_option_single(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    U16 menu_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mmi_frm_group_is_present(GRP_ID_AUDPLY_OPTION))
    {
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
    }

    mmi_frm_group_create_ex(
        GRP_ID_AUDPLY_MAIN, 
        GRP_ID_AUDPLY_OPTION, 
        mmi_audply_option_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_audply.in_list_screen = MMI_FALSE;
#ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    if (g_audply.list_auto_gen)
    {
        menu_id = MENU_ID_AUDPLY_OPTION_MENU_AUTO;
    }
    else
#endif
    {
        menu_id = MENU_ID_AUDPLY_OPTION_MENU_MANUAL;
    }

    cui_menu_create_and_run(
        GRP_ID_AUDPLY_OPTION, 
        CUI_MENU_SRC_TYPE_RESOURCE, 
        CUI_MENU_TYPE_OPTION, 
        menu_id, 
        MMI_FALSE, 
        NULL);

}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_exit_playlist_single
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_exit_playlist_single(void)
{
    g_audply.in_list_screen = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_entry_playlist_option_single
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_entry_playlist_single(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 highlighted_item = 0;
    U8  total_drv_num;
    UI_string_type title_p = NULL;
    SRV_FMGR_DRVLIST_HANDLE drv_list;
    U8 driveletter;
    U8 *storage_str_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(
        GRP_ID_AUDPLY_MAIN, 
        GRP_ID_AUDPLY_LIST_BROWSER, 
        mmi_audply_playlist_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    if (!mmi_frm_scrn_enter(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,mmi_audply_playlist_exit_playlist_single,mmi_audply_playlist_entry_playlist_single,MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }

    /* set screen state flag. */
    g_audply.in_list_screen = MMI_TRUE;

    /* title */
    /* New FMGR interface*/
    drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ALL);
    total_drv_num = srv_fmgr_drivelist_count(drv_list);
    driveletter =  g_audply.present_list;
    storage_str_p = (U8*)get_string(srv_fmgr_drv_get_string(driveletter));
    srv_fmgr_drivelist_destroy(drv_list);


    
    if (total_drv_num >1 && storage_str_p != NULL)
    {
        title_p = (UI_string_type)storage_str_p;
    }
    else
    {
        title_p = (UI_string_type)get_string(STR_ID_AUDPLY_PLAYLIST);
    }

    if (!need_refresh_list && need_reload_list) 
    {
        mmi_audply_need_load_playlist();
        need_reload_list = MMI_FALSE;
    }

    /* show category screen */
    if (mmi_audply_playlist_is_empty() ||
        need_refresh_list ||
        !mmi_audply_playlist_is_valid())
    {
        ShowCategory353Screen(
            (PU8)title_p,
            GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            NULL,
            NULL,
            NULL,
            1,
            0,
            NULL);
    }
    else
    {
        S32 total = mmi_audply_playlist_get_total();
        S32 cat_err = 0;
        /*
        **  2 cases:
        **      1. now playing list screen and enter from player screen.
        **          need set highlight on playing item.
        **      2. now playing list screen and go back from option or etc...
        **          need set back highlight on user selected before enter other screen from this screen.        
        */

        guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_AUDPLY_LIST_BROWSER, SCR_ID_AUDPLY_LIST_BROWSER);

        if (guiBuffer != NULL)
        {
            list_menu_category_history *hist = (list_menu_category_history*) guiBuffer;

            /* case 2. */
           // if (mmi_frm_scrn_get_neighbor_id(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,MMI_FRM_NODE_AT_BEGINNING_FLAG) == SCR_ID_AUDPLY_MAIN)
            {
                hist->highlighted_item = list_cntx.list_ui.highlight;
            }           
        }
        else
        {
            /* case 1. */
           // if (mmi_frm_scrn_get_neighbor_id(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,MMI_FRM_NODE_AT_BEGINNING_FLAG) == SCR_ID_AUDPLY_MAIN)
            {
                highlighted_item = mmi_audply_playlist_get_current_index();
                if (highlighted_item < 0)
                {
                    highlighted_item = 0;
                }
            }
        }
        list_cntx.list_ui.highlight = highlighted_item;

        /* register highligh handler */
        RegisterHighlightHandler(mmi_audply_playlist_ui_highlight_hdlr);
        
        wgui_cat1032_show(
            (WCHAR*) title_p,
            get_image(GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID)),
            get_string(STR_GLOBAL_OPTIONS),
            get_image(IMG_GLOBAL_OPTIONS),
            get_string(STR_GLOBAL_BACK),
            get_image(IMG_GLOBAL_BACK),
            total,
            mmi_audply_playlist_get_item_async,
            NULL,
            highlighted_item,
            0,    
            IMG_GLOBAL_L1, /* to calculate the coordinate offset of string */
            0,
            guiBuffer,
            &cat_err);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_audply_plst_tap_callback);
#endif

    }

    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_audply_playlist_entry_playlist_option_single, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    if (mmi_frm_kbd_is_key_supported(KEY_CSK))
    {
//        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        if (!mmi_audply_playlist_is_empty())
        {
            SetCenterSoftkeyFunction(mmi_audply_playlist_initiate_play, KEY_EVENT_UP);
            
        }
        else
        {
        #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
        	if (g_audply.list_auto_gen)
            {
                SetCenterSoftkeyFunction(mmi_audply_playlist_refresh, KEY_EVENT_UP);
                
            }
            else
       #endif
            {
                SetCenterSoftkeyFunction(mmi_audply_playlist_add, KEY_EVENT_UP);
                
            }
  	

        }
    }
    

    
    if (need_refresh_list)
    {
        need_refresh_list = MMI_FALSE;
        mmi_audply_need_generate_playlist();
    }
    else if (need_reload_list) 
    {
        need_reload_list = MMI_FALSE;
        mmi_audply_need_load_playlist();
    }
}

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_plst_tap_callback(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        return;
    }

    mmi_audply_playlist_initiate_play();
    
    return;
}
#endif /*__MMI_FTE_SUPPORT__*/

static S32 mmi_audply_playlist_get_item_async(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body								                          */
    /*----------------------------------------------------------------*/
    for (i = 0; i < num_item; ++i, ++start_index)
    {
        mmi_audply_playlist_get_item(start_index, menu_data[i].item_list[0], &menu_data[i].image_list[0], 0);
    }
    
    return num_item;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [OUT]        
 *  img_buff_p          [OUT]         
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_audply_playlist_get_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 file_ext_index;
    UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    mmi_audply_list_item_info_struct item_info;
    S32 load_index;
    S32 current = 0;
    mmi_audply_dynamic_list_data_struct* list_ui = &(list_cntx.list_ui);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if ((item_index < list_ui->cache_start_index) ||
        (item_index >= list_ui->cache_end_index))
    {
        /* desired entry not in the middle of cache */
        load_index = item_index - (MMI_AUDPLY_LIST_BUFF_SIZE / 2);

        if (load_index < 0)
        {
            load_index = 0;
        }

        if (0 > mmi_audply_playlist_load_cache(load_index))
        {
        	mmi_ucs2ncpy((CHAR*)str_buff, (CHAR*)GetString(STR_GLOBAL_LOADING), MAX_SUBMENU_CHARACTERS);
            *img_buff_p = NULL;
            return MMI_TRUE;
        }
    }
    current = item_index - list_ui->cache_start_index;
    memcpy(&item_info, 
            &(list_ui->cache[current]), 
            sizeof(mmi_audply_list_item_info_struct));
    
    mmi_audply_split_filename_ext(item_info.filename, str_buff, ext);
    file_ext_index = mmi_audply_lookup_audio_file_format(ext);
#ifdef __MMI_SHOW_FILE_EXT__
#if !defined(__MMI_SHOW_DAF_FILE_EXT__) && (defined(DAF_DECODE) || defined(MUSICAM_DECODE))
    if(
#if defined(DAF_DECODE)
     file_ext_index != AUDPLY_AUDIO_FILE_TYPE_DAF
#endif
#if defined(DAF_DECODE) && defined(MUSICAM_DECODE)
    &&
#endif
#if defined(MUSICAM_DECODE)
    file_ext_index != AUDPLY_AUDIO_FILE_TYPE_MP2
#endif
     )
#endif
    {
        if (ext[0] != 0)    /* if its ext is not blank */
        {
            mmi_ucs2cat((CHAR*)str_buff, (CHAR*)L".");
            mmi_ucs2cat((CHAR*)str_buff, (CHAR*)ext);
        }
    }
#endif /* __MMI_SHOW_FILE_EXT__ */ 
    
    /* get ext icon */
#if !defined (__MMI_MAINLCD_96X64__)
    if (file_ext_index >= 0)
    {
        *img_buff_p = (PU8) GetImage(audio_file_icon_ids[file_ext_index]);
    }
    else
    {
        *img_buff_p = (PU8) GetImage(IMG_ID_AUDPLY_FILE_UNKNOWN_ICON);
    }
#endif
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
    #endif
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_option_proc
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_audply_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        
            if (menu_evt->parent_menu_id == MENU_ID_AUDPLY_OPTION_MENU_AUTO)
            {
                if (mmi_audply_playlist_is_empty())
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_PLAY,MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_ADD_TO_RING,MMI_TRUE);
#ifdef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_DETAILS, MMI_TRUE);
#endif
                }
                else
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_PLAY,MMI_FALSE);
        #ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
		         	cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_ADD_TO_RING,MMI_FALSE);
        #else
        	        cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_ADD_TO_RING,MMI_TRUE);
	    #endif
#ifdef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
				cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_DETAILS,MMI_FALSE);
#endif
                }


            }
            else if (menu_evt->parent_menu_id == MENU_ID_AUDPLY_OPTION_MENU_MANUAL)
            {
                if (mmi_audply_playlist_is_empty())
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_PLAY,MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_ADD_TO_RING,MMI_TRUE);
#ifdef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_DETAILS, MMI_TRUE);
#endif
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_REMOVE, MMI_TRUE);
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_REMOVE_ALL, MMI_TRUE);

                }
                else
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_PLAY,MMI_FALSE);
        #ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
		         	cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_ADD_TO_RING,MMI_FALSE);
        #else
        	        cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_ADD_TO_RING,MMI_TRUE);
	    #endif
#ifdef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
				cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_DETAILS,MMI_FALSE);
#endif
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_REMOVE,MMI_FALSE);
                    cui_menu_set_item_hidden(menu_evt->sender_id,MENU_ID_AUDPLY_OPTION_REMOVE_ALL,MMI_FALSE);
                }


            }
    
            break;
             
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            {
                switch(menu_evt->highlighted_menu_id)
                {
#ifdef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
                    case MENU_ID_AUDPLY_OPTION_DETAILS:
#endif
                    case MENU_ID_AUDPLY_OPTION_ADD:
                    case MENU_ID_AUDPLY_OPTION_REMOVE:
                    case MENU_ID_AUDPLY_OPTION_SETTINGS:
                    case MENU_ID_AUDPLY_OPTION_ADD_TO_RING:
                    case MENU_ID_AUDPLY_OPTION_REMOVE_ALL:
                    case MENU_ID_AUDPLY_OPTION_REFRESH:
                    case MENU_ID_AUDPLY_OPTION_PLAY :
                #ifdef __MMI_TOUCH_SCREEN__
                        wgui_reset_list_item_selected_callback();
                #endif
                        break;

                    default:
                        break;
                }
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_AUDPLY_OPTION_PLAY :
                        mmi_audply_playlist_initiate_play();
                        break;

#ifdef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
                    case MENU_ID_AUDPLY_OPTION_DETAILS:
				mmi_audply_entry_detail();
                        break;
#endif

                    case MENU_ID_AUDPLY_OPTION_ADD:
                        mmi_audply_playlist_add();
                        break;

                    case MENU_ID_AUDPLY_OPTION_REMOVE:
                        mmi_audply_playlist_entry_remove_confirm();
                        break;

                    case MENU_ID_AUDPLY_OPTION_SETTINGS:
                        if (AUDPLY_SETTING_ITEM_COUNT <= 10)
                        {
                            mmi_audply_entry_settings();
                        }
                        else
                        {
                            mmi_audply_entry_two_layers_settings();
                        }
                        break;
    
                    case MENU_ID_AUDPLY_OPTION_ADD_TO_RING:
                        mmi_audply_playlist_add_to_ring();
                        break;

                    case MENU_ID_AUDPLY_OPTION_REMOVE_ALL:
                        mmi_audply_playlist_entry_remove_all_confirm();
                        break;

                    case MENU_ID_AUDPLY_OPTION_REFRESH:
                        mmi_audply_playlist_refresh();
                        break;

                    default:
                        break;


                }
                        
           }
           break;


        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}
            
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_proc
 * DESCRIPTION
 *   
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_audply_playlist_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct *sel_evt = (cui_file_selector_result_event_struct*)evt;
            
            
            mmi_audlpy_plst_fmgr_file_selector_handle(sel_evt);
            break;
        }
        default:
            break;
    
    }
    return MMI_RET_OK;   
}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_load_cache
 * DESCRIPTION
 *  load play list to buffer
 * PARAMETERS      
 *  start_index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_audply_playlist_load_cache(S32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U16 cache_index = 0;
    S32 ret = FS_NO_ERROR;
    mmi_audply_dynamic_list_data_struct* list_ui = &(list_cntx.list_ui);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    /* init some value */
    list_ui->cache_start_index = start_index;

    for (i = 0; i < MMI_AUDPLY_LIST_BUFF_SIZE; i++)
    {
        list_ui->cache[i].filename[0] = 0;
        list_ui->cache[i].ext[0] = 0;
        list_ui->cache[i].file_type = 0;
        list_ui->cache[i].is_short = 0;
    }
   
    ret = mmi_audply_playlist_get_list(&cache_index, start_index);

    if (ret < 0)
    {
        /* error caught. */
        return ret;
    }
    else
    {
        list_ui->cache_start_index = start_index;
        list_ui->cache_end_index = start_index + cache_index;
        return 0;
    }
} 


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_list
 * DESCRIPTION
 *  read playlist to cache.
 * PARAMETERS
 *  cached_num      [OUT]
 *  start_index     [IN]
 * RETURNS
 *  S32     loaded item number/error code
 *****************************************************************************/
static S32 mmi_audply_playlist_get_list(U16 *cached_num, U16 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;
    U32 read_size = 0;

    UI_character_type *ucs2_buff = NULL;
    UI_character_type *filename = NULL;//[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    FS_HANDLE fd = -1;
    mmi_audply_dynamic_list_data_struct* list_ui = &(list_cntx.list_ui);
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    S16 track_abs_index, i;
    U32 file_seek;
    S32 ret = FS_NO_ERROR;
    S16  *audply_plylist_header = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (list->fs_hdlr > 0)
    {
        fd = list->fs_hdlr;
    }
    else
    {
        fd = FS_Open(list_cntx.current_list.path, FS_READ_ONLY);
    }
    filename = (UI_character_type*) OslMalloc(SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1);
    memset (filename, 0, SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1);

    audply_plylist_header = (S16*) OslMalloc((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2);
    memset (audply_plylist_header, 0, ((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2));
    ret = mmi_audply_playlist_read_header(audply_plylist_header);
    if (ret < FS_NO_ERROR) 
    {
        OslMfree (audply_plylist_header);
        OslMfree (filename);
        return ret;
    }

    if (fd >= 0)
    {
    	ucs2_buff = (UI_character_type*) OslMalloc((MMI_AUDPLY_LIST_RECORD_SIZE + 1));

        while (count < MMI_AUDPLY_LIST_BUFF_SIZE && start_index < list_cntx.current_list.total)
        {
            for (i = 0; audply_plylist_header[i] != start_index && i < MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT; i++);
            track_abs_index = i;
            file_seek = (track_abs_index * MMI_AUDPLY_PATH_LEN) + (2 * (MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2));
            FS_Seek(fd, file_seek, FS_FILE_BEGIN);
            FS_Read(fd, ucs2_buff, MMI_AUDPLY_PATH_LEN, &read_size);

            /* load filename to play list buffer */
            ucs2_buff[EOS(read_size)] = 0;   /* make it must be in boundary */
            if (!mmi_audply_playlist_check_filename_len(ucs2_buff))
            {
                continue;
            }
            if (IS_SNAME(ucs2_buff))
            {
				CHAR* dot = NULL;
                mmi_audply_extract_filename(filename, ucs2_buff);
                mmi_chset_mixed_text_to_ucs2_str(
                    (U8*)list_ui->cache[count].filename,
                    (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                    (U8*)filename,
                    g_chset_text_encoding);
                dot = mmi_ucs2rchr((CHAR*)list_ui->cache[count].filename, (U16)L'.');
                if (dot == NULL)
                {
                    dot = mmi_ucs2rchr((CHAR*)filename, (U16)L'.');
                    if (dot != NULL)
                    {
                        mmi_ucs2ncat((CHAR*)list_ui->cache[count].filename, (CHAR*)(dot), 4);
                    }
                }
            }
            else
            {
                mmi_audply_extract_filename(list_ui->cache[count].filename, ucs2_buff);
            }
            start_index++;
            count++;
        }
        
        OslMfree(ucs2_buff);
        OslMfree (audply_plylist_header);
        OslMfree (filename);
        if (list->fs_hdlr <= 0)
        {
            FS_Close(fd);
        }
        *cached_num = count;
        return count;
    }
    else 
    {
        OslMfree (audply_plylist_header);
        OslMfree (filename);
        return fd;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_init
 * DESCRIPTION
 *  init play list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_init(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_reset_ui_cntx();

    mmi_audply_reset_context();
    memset(list_cntx.current_list.bitset, 0, MMI_AUDPLY_MAX_BITSET_SIZE);
    list_cntx.current_list.total = 0;
    list_cntx.current_list.pick_index = -1;
    g_audply.successive_fail_num = 0;
    list_cntx.current_list.pick_count = 0;
    mmi_audply_playlist_init_header(MMI_FALSE);
    list_cntx.current_list.total = mmi_audply_playlist_get_count ();
    if (ret < FS_NO_ERROR)
    {
        list_cntx.list_loaded = MMI_FALSE;
        return;
    }
    list_cntx.list_loaded = MMI_TRUE;

    mmi_audply_playlist_set_start(-1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_remove_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_playlist_remove_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd;
    MMI_BOOL isOK = MMI_FALSE;
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list->fs_hdlr > 0)
    {
        FS_Close(list->fs_hdlr);
        list->fs_hdlr  = 0;
    }
    if ((fd = FS_Open(list->path, FS_READ_WRITE)) >= 0)
    {
        if (FS_Seek(fd, 0, FS_FILE_BEGIN) >= 0)
        {
            if (FS_Truncate(fd) == FS_NO_ERROR)
            {
                mmi_audply_reset_context();

                g_audply.duration = 0;
                list->total = 0;
                mmi_audply_playlist_reset_ui_cntx();
                mmi_audply_playlist_init_header(MMI_TRUE);
                
                mmi_audply_playlist_set_start(-1);
                isOK = MMI_TRUE;
            }
        }
        FS_Close(fd);
    }

    return isOK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_remove_all_confirm_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_remove_all_confirm_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_stop_playing();
    if (mmi_audply_playlist_remove_all())
    {
        mmi_audply_playlist_reset_ui_cntx();
        mmi_audply_playlist_init_header(MMI_TRUE);
    }
    else
    {
    	mmi_popup_display_ext(
    	    STR_ID_AUDPLY_CANNOT_UPDATE_LIST_FS_FAIL, 
    	    MMI_EVENT_FAILURE, 
    	    NULL);
        mmi_frm_scrn_close_active_id();
        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_remove_all_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_entry_remove_all_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_audply_playlist_entry_remove_all_confirm_cb;
    mmi_confirm_display((WCHAR *)(get_string(STR_ID_AUDPLY_OPTION_REMOVE_ALL_ASK)), MMI_EVENT_QUERY, &arg);  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_entry_remove_all_confirm_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static mmi_ret mmi_audply_playlist_entry_remove_all_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {

        case MMI_ALERT_CNFM_YES:
        	mmi_audply_playlist_remove_all_confirm_LSK();
        	break;
        	
        case MMI_ALERT_CNFM_NO:
        	mmi_frm_scrn_close_active_id();
        	break;
            
        }
    }
    return MMI_RET_OK;
}


static mmi_ret mmi_audply_playlist_remove_wait_scr_proc(mmi_event_struct *event)
{
    switch (event->evt_id)
    {
	case EVT_ID_SCRN_INACTIVE:
        {
            break;
        }
        case EVT_ID_SCRN_ACTIVE:
        {
                
        /* do not allow popup sliding for this waiting popup */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
            gui_screen_switch_effect_block(MMI_TRUE);
#endif
        
            ShowCategory66Screen(
                STR_ID_AUDPLY_TITLE,
                GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
                0,
                0,
                0,
                0,
                (U8*)GetString(STR_GLOBAL_PLEASE_WAIT),
                mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                NULL);
            mdi_audio_suspend_background_play();
            ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
                    mdi_audio_resume_background_play();
            break;
        }
        default:
            break;
    }
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_remove_wait_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_remove_wait_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN_REMOVE))
    {
        mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN_REMOVE);
    }

    mmi_frm_group_create_ex(
        GRP_ID_ROOT, 
        GRP_ID_AUDPLY_WAITSCREEN_REMOVE, 
        mmi_audply_playlist_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

   mmi_frm_scrn_create(
        GRP_ID_AUDPLY_WAITSCREEN_REMOVE, 
        SCR_ID_AUDPLY_WAITSCREEN_REMOVE, 
        mmi_audply_playlist_remove_wait_scr_proc,   
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_remove_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_entry_remove_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_confirm_property_struct arg;
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_audply_playlist_entry_remove_confirm_cb;
    mmi_confirm_display((WCHAR *)(get_string(STR_ID_AUDPLY_OPTION_REMOVE_ASK)), MMI_EVENT_QUERY, &arg);

    if (mmi_frm_group_is_present(GRP_ID_AUDPLY_OPTION))
    {
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_remove_video
 * DESCRIPTION
 *  play finish handler
 * PARAMETERS
 *  void
 *  result(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_remove_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    S32 size;
    FS_HANDLE file_handle = -1;
    S32 ret = FS_NO_ERROR;
    MMI_BOOL  need_reApply = MMI_FALSE;
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    S16  *audply_plylist_header = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list->pick_index == list_cntx.list_ui.highlight)
    {
        mmi_audply_stop_playing();
        need_reApply = MMI_TRUE;
    }
    audply_plylist_header = (S16*) OslMalloc((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2);
    memset (audply_plylist_header, 0, ((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2));
    ret = mmi_audply_playlist_read_header(audply_plylist_header);
    if (ret < FS_NO_ERROR)
    {
        OslMfree(audply_plylist_header);
        goto ERROR;
    }

    /* If last file in the list is playing, we need to decrease picked index */
    if (list->pick_index == (audply_plylist_header[MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT] - 1))
    {
        list->pick_index--;
    }
    if (list->fs_hdlr > 0)
    {
        FS_Close(list->fs_hdlr);
        list->fs_hdlr  = 0;
    }
    file_handle = FS_Open(list->path, FS_READ_WRITE | FS_CACHE_DATA);
    for (i = 0; i < MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT && audply_plylist_header[i] != list_cntx.list_ui.highlight; i++);

    ASSERT(i < MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT);

    audply_plylist_header[i] = (S16) - 1;
    audply_plylist_header[MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT]--;
    list_cntx.current_list.total--;
    for (i = 0; i < MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT; i++)
    {
        if (audply_plylist_header[i] > list_cntx.list_ui.highlight && audply_plylist_header[i] != (S16) - 1)
            audply_plylist_header[i]--;
    }
    if (FS_Seek(file_handle, 0, FS_FILE_BEGIN) >= 0)
    {
        ret = FS_Write(
            file_handle,
            audply_plylist_header,
            (MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT * 2) + 2,
            (UINT*) & size);
    }
    FS_Commit(file_handle);
    FS_Close (file_handle);
    OslMfree(audply_plylist_header);

    if (need_reApply)
    {
        mmi_audply_playlist_apply_picked_file();
        mmi_audply_clear_play_seconds();
    }

ERROR:
    mmi_audply_playlist_reload_list();

    if (mmi_frm_scrn_get_active_id() == SCR_ID_AUDPLY_WAITSCREEN_REMOVE)
	{
        if (ret < FS_NO_ERROR)
        {
            mmi_audply_playlist_display_popup(ret, NULL);
        }

        mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN_REMOVE);
        if (mmi_frm_group_is_present(GRP_ID_AUDPLY_OPTION))
        {
            mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
        }
	}
	else
	{
        if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN_REMOVE))
        {
            mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN_REMOVE);
        }
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_entry_remove_confirm_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_audply_playlist_entry_remove_confirm_cb(mmi_alert_result_evt_struct *evt)
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
                mmi_audply_playlist_remove_wait_scr();
                mmi_audply_remove_audio();
        		break;
        		
          case MMI_ALERT_CNFM_NO:
          	mmi_frm_scrn_close_active_id();
          	break;
            
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_add_to_ring
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_audply_playlist_add_to_ring(void)
{


    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];

    mmi_audply_playlist_get_path_single(path, list_cntx.list_ui.highlight);
    
    if (!mmi_audply_does_file_exist(path))
    {
        mmi_audply_playlist_display_popup(FS_FILE_NOT_FOUND, NULL);
    }
    else
    {
        srv_prof_set_current_profile_tone_with_file_path(SRV_PROF_SETTINGS_MT_CALL_TONE, (WCHAR*)path);
    }
    mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_refresh
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_audply_playlist_refresh(void)
{
    mmi_audply_need_generate_playlist();
    /* clear play list gui buffer */
    mmi_audply_playlist_clear_list_browser_gui_buffer();

    if (mmi_frm_group_is_present(GRP_ID_AUDPLY_OPTION))
    {
         mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);    
    }
   // DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_audply_playlist_add(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    U8 drv;
    S32 error;
    UI_character_type list_root[5]; /* "C:\" */
    MMI_ID cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FILE_MANAGER__
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET_AUDIO(&filter);
#ifdef __VM_CODEC_SUPPORT__     
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_VM);
#endif /*__VM_CODEC_SUPPORT__*/    
#if defined(__MMI_PURE_AUDIO__)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_3GP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_3G2);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_MP4);
#endif
#if defined(__VORBIS_DECODE__) && defined(__VORBIS_DECODE_SLIM__)
    FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_OGG);
#endif
#ifdef __DRM_V02__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif

    mmi_frm_group_create_ex(
        GRP_ID_AUDPLY_MAIN, 
        GRP_ID_AUDPLY_LIST_ADD, 
        mmi_audply_playlist_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    drv = mmi_audply_get_current_list_drv();
    kal_wsprintf(list_root, "%c:\\", drv);
	if ((error=FS_GetDevStatus(drv, FS_MOUNT_STATE_ENUM)) == FS_NO_ERROR)
    {

        cui_gid = cui_file_selector_create(
                                        GRP_ID_AUDPLY_LIST_ADD,
                                        (WCHAR*)list_root,
                                        &filter,
                                        CUI_FILE_SELECTOR_STYLE_FILE_AND_PATH,
                                        CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE | CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);


        if (cui_gid > GRP_ID_INVALID)
        {
            cui_file_selector_set_title(cui_gid, 0, GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID));
            cui_file_selector_run(cui_gid);
                   
        }
        else
        {   
            mmi_popup_display_ext(
                STR_GLOBAL_NOT_AVAILABLE, 
                MMI_EVENT_FAILURE, 
                NULL);
        }
    }
    else
    {        
        mmi_popup_display_ext(
            STR_GLOBAL_INSERT_MEMORY_CARD, 
            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(error), 
            NULL);
    }        
    mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);       
#endif /* __MMI_FILE_MANAGER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audlpy_plst_fmgr_file_selector_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audlpy_plst_fmgr_file_selector_handle(cui_file_selector_result_event_struct *file_select)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *temp_path = NULL;//[SRV_FMGR_PATH_BUFFER_SIZE];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_path = (U16*) OslMalloc(SRV_FMGR_PATH_BUFFER_SIZE);
    memset (temp_path, 0, SRV_FMGR_PATH_BUFFER_SIZE);

    if (list_cntx.current_list.total >= MMI_AUDPLY_MAX_PLAYLIST_ITEM)
    {
        mmi_popup_display_ext(
            STR_ID_AUDPLY_LIST_FULL, 
            MMI_EVENT_FAILURE, 
            NULL);
        cui_file_selector_close(file_select->sender_id);
        OslMfree (temp_path);
        return;
    }
    if (file_select->result > 0)
    {
        cui_file_selector_get_selected_filepath(
                                file_select->sender_id,
                                NULL,
                                (WCHAR *) temp_path,
                                SRV_FMGR_PATH_BUFFER_SIZE);
        
        mmi_audply_playlist_generate(temp_path, MMI_FALSE);
    }
    else if (file_select->result == 0)
    {
        cui_file_selector_close(file_select->sender_id);
    }
    else
    {
    #if defined(__USB_IN_NORMAL_MODE__)
	    if (!srv_usb_is_in_mass_storage_mode())
		    	    
    #endif /* defined(__USB_IN_NORMAL_MODE__) */ 
	   {
	        mmi_popup_display_ext(
	            (srv_fmgr_fs_error_get_string(file_select->result)), 
	            (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(file_select->result), 
	            NULL);
		}	       
        cui_file_selector_close(file_select->sender_id);
    }
    OslMfree (temp_path);

}




/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_initiate_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_audply_playlist_initiate_play(void)
{
#ifdef __MMI_BACKGROUND_CALL__
    if(srv_ucm_is_background_call())
    {
		mmi_ucm_entry_error_message();
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
        //DeleteUptoScrID(SCR_ID_AUDPLY_LIST_BROWSER);
        return;
    }
#endif
    
    mmi_audply_playlist_set_start(list_cntx.list_ui.highlight);
    mmi_audply_playlist_set_pick_index(list_cntx.list_ui.highlight);
    if (mmi_audply_playlist_apply_picked_file())
    {
        mmi_audply_stop_playing();
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
        mmi_frm_group_close(GRP_ID_AUDPLY_LIST_BROWSER);
        mmi_audply_play();
    }
    else
    {
    	mmi_popup_display_ext(
    	    STR_ID_AUDPLY_OPEN_FILE_ERROR, 
    	    MMI_EVENT_FAILURE, 
    	    NULL);
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
    }
}
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */

#define PLAYLIST_COMMON_API
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_module_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_audply_playlist_module_init(void)
{
    list_cntx.drv_num = mmi_audply_util_count_optional_drv();
    memset(&(list_cntx.list_ui), 0, sizeof(mmi_audply_dynamic_list_data_struct));
    memset(&(list_cntx.generate_info), 0, sizeof(mmi_audply_playlist_generate_struct));
    
    if (!list_cntx.list_loaded)
    {
        memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_ui_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_ui_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_cntx.list_ui.highlight = index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_util_count_optional_drv
 * DESCRIPTION
 *  return optional driver number.
 *  check phone memory, memory card, SIM+ and OTG.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_audply_util_count_optional_drv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR drive; 
    U8 count = 0;
#if defined(__OTG_ENABLE__) || defined(__SIM_PLUS__)
    U8 i = 0;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_V_REMOVABLE)) >= 'A') && (drive <= 'Z'))
    {
        list_cntx.drv[count].drv_letter = drive;
        count++;
    }
    
    if (((drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
    {
        list_cntx.drv[count].drv_letter = drive;
        count++;
    }

#ifdef __OTG_ENABLE__
    for (i = 0; i < USB_HOST_MS_SUPPORT_LUN; i++)
    {
        if (((drive = FS_GetDrive(FS_DRIVE_V_EXTERNAL, i + 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
        {
            list_cntx.drv[count].drv_letter = drive;
            count++;
        }
    }
#endif /* __OTG_ENABLE__ */ 

#ifdef __SIM_PLUS__
    for (i = 0; i < 4; i++)
    {
        if (((drive = FS_GetDrive(FS_DRIVE_V_SIMPLUS, i + 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
        {
            list_cntx.drv[count].drv_letter = drive;
            count++;
        }
    }
#endif

#ifdef __MSDC2_SD_MMC__
    if (((drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 2, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
    {
        list_cntx.drv[count].drv_letter = drive;
        count++;
    }    
#endif

    return count;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_path_for_player
 * DESCRIPTION
 *  retrieve file path and name from play list file
 * PARAMETERS
 *  fullfilename        [IN]        
 *  index               [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_audply_playlist_get_path_for_player(UI_string_type fullfilename, S32 index)
{
    return mmi_audply_playlist_get_path_single(fullfilename, index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_path
 * DESCRIPTION
 *  retrieve file path and name from play list file
 * PARAMETERS
 *  fullfilename        [IN]        
 *  index               [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_audply_playlist_get_path(UI_string_type fullfilename, S32 index)
{
    return mmi_audply_playlist_get_path_single(fullfilename, index);
}


void mmi_audply_playlist_display_popup(S32 error_code, FuncPtr callback)
{
    mmi_event_notify_enum event_type = MMI_EVENT_DEFAULT;
    U16 string_id = 0;

    if (error_code > MMI_AUDPLY_PLAYLIST_ERR_BEGIN)
    {
        /* handle file system error code. */
        string_id = srv_fmgr_fs_error_get_string(error_code);
        event_type = (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(error_code);
        /* handle special case. */
        switch (error_code)
        {
            case FS_NO_MORE_FILES:
                string_id = STR_GLOBAL_EMPTY;
                break;
            default:
                break;
        }
    }
    else
    {
    	event_type = MMI_EVENT_FAILURE;
        string_id = STR_ID_AUDPLY_PLAYLIST_ERR_UNKNOWN_ERROR;
        if (error_code == MMI_AUDPLY_PLAYLIST_ERR_NO_SPACE)
        {
            string_id = STR_GLOBAL_NOT_ENOUGH_MEMORY;
        }
    }


    if (callback)
    {
        	do {
                mmi_popup_property_struct arg;
                mmi_popup_property_init(&arg);
                arg.callback = mmi_alert_normal_exit_helper;
		if (!g_audply.background_play)
		{
		   arg.parent_id = GRP_ID_AUDPLY_MAIN;
		}
		else
		{
		   arg.parent_id = GRP_ID_ROOT; 
		}
                arg.user_tag = (void *)(callback);
                mmi_popup_display_ext(
                    string_id, 
                    event_type, 
                    &arg);
                }
            while(0);
            

    }
    else
    {

        mmi_popup_display_ext(
            string_id, 
            event_type, 
            NULL);
    }

  if (mmi_frm_group_is_present(GRP_ID_AUDPLY_LIST_ADD))
    {
        mmi_frm_group_close(GRP_ID_AUDPLY_LIST_ADD);
    }
    mmi_frm_group_close(GRP_ID_AUDPLY_OPTION); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_apply_picked_file
 * DESCRIPTION
 *  apply pick index to get full filename and title
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_playlist_apply_picked_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;
    UI_character_type filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    UI_character_type wchar_filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_APPLY_PICKED_FILE);
    g_audply.is_support_pause = MMI_TRUE;  
    if (mmi_audply_playlist_is_empty())
    {
        g_audply.seekable = MMI_FALSE;
        g_audply.need_to_build_cache = MMI_FALSE;

        return MMI_FALSE;
    }


    result = mmi_audply_playlist_get_path_single(g_audply.filefullname, list_cntx.current_list.pick_index);   
    
    if (!result)
    {
        g_audply.seekable = MMI_FALSE;
        g_audply.need_to_build_cache = MMI_FALSE;

        return MMI_FALSE;
    }
    else
    {
        if (result == 2)    /* if it is a short filename */
        {
            mmi_audply_extract_filename(wchar_filename, g_audply.filefullname);
            mmi_chset_mixed_text_to_ucs2_str(
                (U8*) filename,
                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                (U8*) wchar_filename,
                g_chset_text_encoding);
        }
        else
        {
            mmi_audply_extract_filename(filename, g_audply.filefullname);
        }
        mmi_audply_split_filename_ext(filename, g_audply.title, ext);

#if defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__) || defined(__MMI_VUI_LAUNCHER_KEY__)
    if(g_audply.widget_callback != NULL)
    {
        g_audply.widget_callback(g_audply.widget_callback_userdata, MMI_WIDGET_PLAYER_MEDIA_CHANGE_CALLBACK, NULL);
    }
#endif
     #ifdef __MMI_NCENTER_SUPPORT__
       mmi_audply_ncenter_update();
	#endif
        mmi_audply_check_whether_build_cache(&g_audply.need_to_build_cache,&g_audply.seekable,g_audply.filefullname);
#if defined(__MMI_AUDIO_PLAYER_LYRIC_NLINE_DISPLAY__)
	if (g_audply.lyrics_display &&
	        mmi_audply_is_lyrics_valid() && g_audply.in_main_screen)
	    {
			mmi_audply_prepare_lyrics();

	    }
    #endif /* __MMI_AUDIO_PLAYER_LYRIC_DISPLAY__ */ 
        /* in case there is no right */
    #ifdef __DRM_SUPPORT__
	
        result = mmi_audply_drm_valide_right((PU16)g_audply.filefullname);
        if(result ==2)
        {
            g_audply.seekable = MMI_FALSE;
        }
        g_audply.DRM_consumed = MMI_FALSE;
    #endif
        
    #if defined(MT6223) || defined(MT6223P)
        g_audply.support_A2DP = mmi_audply_check_support_A2DP_or_not(ext);
    #endif
    
        g_audply.seekable = mdi_audio_is_file_seekable(g_audply.filefullname);
        if(!g_audply.seekable)
        {
            g_audply.is_support_pause = MMI_FALSE;
        }
    
        if (mdi_audio_get_duration(g_audply.filefullname, &(g_audply.duration)) != MDI_AUDIO_SUCCESS)
        {
            g_audply.duration = 0 ;
        }
        mmi_audply_determine_progress_speed();
        
        if (mmi_ucs2cmp((CHAR*)g_audply.filefullname, (CHAR*)g_audply.prev_filefullname))
        {
            g_audply.file_name_identical =MMI_FALSE;
        }
        else
        {
            g_audply.file_name_identical = MMI_TRUE;
        }
        g_audply_main_selected_button = AUDPLY_MAIN_PLAY;
        return MMI_TRUE;
    }
}


void mmi_audply_playlist_pick_random(mmi_audply_playlist_struct* list)
{
    S32 i = 0;
    U32 seek_count = 0;
    
    /* need find an empty slot. */
   if (list->pick_count >= list->total)
    {
        /* reached end of list. */
        mmi_audply_playlist_set_start(-1);  /* reset all context. */
    } 
    i = (list->pick_index + (rand() % list->total) + 1) % list->total;
    
    while (1)
    {
        i = (i + 1) % list->total;
    
        if (IsBitSetOn(i, list->bitset))
        {
            MMI_ASSERT(seek_count < (U32)list->total);
            seek_count++;
        }
        else
        {
            break;
        }
    }
    
    list->pick_index = i;
    list->pick_count++;
    SetBitSet(list->pick_index, list->bitset);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_do_pick
 * DESCRIPTION
 *  pick a song from play list
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_playlist_do_pick(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    S32 result = 0;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_audply_playlist_is_empty())
    {
        return -1;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_PLAYLIST_DO_PICK);

    if (g_audply.repeat_mode == REPEAT_ONE)
    {
        /* pick count and bistset are useless in this time. */
        result = list->pick_index;
    }
    else
    {
        if (g_audply.random_mode)
        {
            if (list->pick_count >= list->total)
            {
                /* reached end of list. */
                mmi_audply_playlist_set_start(-1);	/* reset all context. */
                if (g_audply.repeat_mode == REPEAT_OFF)
                {
                    result = -1;	/* stop! */
                }
                else if (g_audply.repeat_mode == REPEAT_ALL)
                {
                    mmi_audply_playlist_pick_random(list);
                    result = list->pick_index;
                }
                else
                {
					MMI_ASSERT(g_audply.repeat_mode != REPEAT_ONE);
                }
            }
            else
            {
                mmi_audply_playlist_pick_random(list);
				result = list->pick_index;	/* begin from first one. */ 
            }
        }
        else
        {
        	/* "pick_count" is useless when random = OFF. */
			if (list->pick_index == list->total - 1)
            {
				/* reached end of list. */
                mmi_audply_playlist_set_start(-1);	/* reset all context. */
                if (g_audply.repeat_mode == REPEAT_OFF)
                {
                    result = -1;	/* stop! */
                }
                else if (g_audply.repeat_mode == REPEAT_ALL)
                {
                	list->pick_index = 0;
                	list->pick_count++;
                	SetBitSet(list->pick_index, list->bitset);
					result = list->pick_index;	/* begin from first one. */ 
                }
                else
                {
					MMI_ASSERT(g_audply.repeat_mode != REPEAT_ONE);
                }
            }
            else
            {
            	list->pick_index++;
                list->pick_count++;
                SetBitSet(list->pick_index, list->bitset);
				result = list->pick_index;
            }
        }        
	}
	return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_pick_next
 * DESCRIPTION
 *  pick the next song from play list
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_playlist_pick_next(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list->total == 0)
    {
        return -1;
    }

    if (g_audply.random_mode)
    {
        mmi_audply_playlist_pick_random(list);
    }
    else
    {
        /* "pick_count" is useless when random = OFF. */
        if (list->pick_index == list->total - 1)
        {
            /* reached end of list. */
            mmi_audply_playlist_set_start(-1);	/* reset all context. */
        }

        list->pick_index++;
        list->pick_count++;
        SetBitSet(list->pick_index, list->bitset);
    }        

    return list->pick_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_pick_prev
 * DESCRIPTION
 *  pick the previous song from play list
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_playlist_pick_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list->total == 0)
    {
        return -1;
    }


    if (g_audply.random_mode)
    {
        
        mmi_audply_playlist_pick_random(list);
    }
    else
    {
        if (list->pick_index == 0)
        {
            index = list->total - 1;
        }
        else
        {
            index = list->pick_index - 1;
        }
        mmi_audply_playlist_set_start(index);
        mmi_audply_playlist_set_pick_index(index);
    }        

    return list->pick_index;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_total
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
S32 mmi_audply_playlist_get_total(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (mmi_audply_playlist_is_empty())
    {
        return 0;
    }
    else
    {
        return list_cntx.current_list.total;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_reset_ui_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
S32 mmi_audply_playlist_get_current_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (mmi_audply_playlist_is_empty())
    {
        return -1;
    }
    else
    {
        return list_cntx.current_list.pick_index;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_current_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_playlist_get_current_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return list_cntx.list_ui.highlight;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_set_pick_index
 * DESCRIPTION
 *  seek play list index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_set_pick_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list->pick_index = index;
    if (!IsBitSetOn(index, list->bitset))
    {
        SetBitSet(index, list->bitset);
        list->pick_count++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_set_start
 * DESCRIPTION
 *  seek play list index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_set_start(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(list->bitset, 0, MMI_AUDPLY_MAX_BITSET_SIZE);
    list->pick_index = index;
    list->pick_count = 0;
	/* reset play fail counter. */
    g_audply.successive_fail_num = 0;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_fmgr_notify_hdlr
 * DESCRIPTION
 *  seek play list index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_fmgr_notify_hdlr(CHAR drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    {
        if (list_cntx.list_loaded && 
            mmi_audply_get_current_list_drv() == drv)
        {
            mmi_audply_stop_playing();
            memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
            list_cntx.list_loaded = MMI_FALSE;

            mmi_audply_playlist_reset_ui_cntx();
            mmi_audply_playlist_init_header(MMI_TRUE);

            mmi_audply_reset_context();
            g_mmi_audply_init_done = MMI_FALSE;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_list_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_update_list_hdlr(const CHAR* old_path, const CHAR* new_path, U8 action_type, MMI_BOOL is_folder)
{
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
#if defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type list_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    S32 ret = FS_NO_ERROR;
    CHAR current_drv = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_UPDATE_LIST_HDLR,old_path==NULL,new_path==NULL,action_type,is_folder);
    /* check necessarily parameter. */
    if (old_path == NULL)
    {
        return;
    }

    /* check compile option. */
    
    if (g_audply.list_auto_gen)
    {
    #ifndef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
        return;
    #endif 
    }
    else    /* !list_auto_gen */
    {
    #ifndef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__
        return;
    #endif 
    }

    if (g_mmi_audply_init_done)
    {
        current_drv = (CHAR)g_audply.present_list;
    }
    else
    {
        current_drv = (CHAR)old_path[0];
    }
    ret = mmi_audply_playlist_check_and_set_default_playlist_path(
                                            list_path, (CHAR)current_drv);
    if (ret < FS_NO_ERROR)
    {
        return;
    }   
    
    /* check the modified file/folder whether about present list. start */
    if (mmi_ucs2nicmp((CHAR*)old_path, (CHAR*)list_path, 1) && (action_type != AUDPLY_ACTION_COPY && action_type != AUDPLY_ACTION_MOVE))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_1);
        /*current path's driver id is different with present list!*/
        return;
    }
    else if (FS_GetAttributes((PU16)list_path) < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_2);
        /*no list file exist!*/
        return;
    }

    /* init update_cntx begin */
    memset(&update_cntx, 0, sizeof(audply_auto_update_struct));
    
    mmi_ucs2ncpy((CHAR*)update_cntx.old_path, (CHAR*)old_path, (U32)mmi_ucs2strlen((CHAR*)old_path));
    if (new_path != NULL)
    {
        mmi_ucs2ncpy((CHAR*)update_cntx.new_path, (CHAR*)new_path, (U32)mmi_ucs2strlen((CHAR*)new_path));
		/* prepare file path. */
		if (!is_folder)
		{
			CHAR* last_backlash = NULL;
			last_backlash = mmi_ucs2rchr((CHAR*)update_cntx.new_path, (U16)L'\\');
			MMI_ASSERT(last_backlash != NULL);
			
			if (2 > mmi_ucs2strlen((CHAR*)last_backlash))
			{
				last_backlash = mmi_ucs2rchr((CHAR*)update_cntx.old_path, (U16)L'\\');
				MMI_ASSERT(last_backlash != NULL);
				last_backlash += 2;
				mmi_ucs2cat((CHAR*)update_cntx.new_path, (CHAR*)last_backlash);
			}
		}   
	}

    
    update_cntx.temp_file = -1;
    update_cntx.present_list = -1;
    update_cntx.counter = 0;
    update_cntx.deleted = 0;
    update_cntx.offset = 0;
    update_cntx.old_path_len = (U32)mmi_ucs2strlen((CHAR*)update_cntx.old_path);
    update_cntx.action_type = action_type;
    update_cntx.is_folder = is_folder;
    memset(&cache_cntx, 0, sizeof(audply_auto_update_cache_struct));
    /* init update_cntx end  */
    
    /* do check if action from FMGR is about audio player list */
    if (is_folder)
    {
        need_refresh_list = MMI_TRUE;
    }
    else
    {
        if (need_refresh_list == MMI_TRUE)
        {
            return;
        }
        if (action_type == AUDPLY_ACTION_COPY || action_type == AUDPLY_ACTION_MOVE)
        {
            UI_character_type my_music_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
            if (g_mmi_audply_init_done)
            {
                kal_wsprintf(my_music_path, "%c:\\", (CHAR)g_audply.present_list);
            }
            else
            {
                kal_wsprintf(my_music_path, "%c:\\", (CHAR)update_cntx.old_path[0]);
            }
            mmi_ucs2cat((CHAR*)my_music_path, (CHAR*)MUSIC_FOLDER);
           #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
            if (g_audply.list_auto_gen &&
                !mmi_ucs2nicmp((CHAR*)update_cntx.new_path, (CHAR*)my_music_path, (U32)mmi_ucs2strlen((CHAR*)my_music_path)) &&
                mmi_audply_is_audio_path((UI_string_type)update_cntx.new_path))
            {
                need_refresh_list = MMI_TRUE;
                return;
            }
            #endif
        }
        if (0 < mmi_audply_update_does_record_in_list(list_path, (CHAR*)update_cntx.old_path))
        {
            if (action_type == AUDPLY_ACTION_RENAME)
            {
                mmi_audply_update_rename_folder(MMI_FALSE);
            }
            else if (action_type == AUDPLY_ACTION_DELETE)
            {
                mmi_audply_update_delete_folder(MMI_FALSE);
            }
            else if (action_type == AUDPLY_ACTION_MOVE)
            {
                action_type = AUDPLY_ACTION_DELETE;
                mmi_audply_update_delete_folder(MMI_FALSE);
            }
        }
    }
#endif /*defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__) */
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */
}




/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_is_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_playlist_is_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;
    U16 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    do 
    {
        ret = FS_GetAttributes((PU16)list_cntx.current_list.path);
        if (i > 30)
        {
            break;
        }
        else
        {
            i++;
        }
    } while (ret == FS_DEVICE_BUSY);
    
    if (0 > ret)
    {
        list_cntx.list_loaded = MMI_FALSE;
    }
    else
    {
    #if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
        return MMI_TRUE;
    #endif
    }

    return list_cntx.list_loaded;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_is_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_playlist_is_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_audply_playlist_is_valid())
    {
        if (list_cntx.current_list.total > 0)
        {
            ret = MMI_FALSE;
        }
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_entry_playlist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_entry_playlist(void)
{    
    mmi_audply_playlist_entry_playlist_single();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_check_whether_build_cache
 * DESCRIPTION
 *  check if the file type needs to build cache to seek
 * PARAMETERS
 *  need_to_build_cache [OUT]
 *  seekable [OUT]
 *  ext     [IN]        
 * RETURNS
 * void
 *****************************************************************************/
void mmi_audply_check_whether_build_cache(
        MMI_BOOL *need_to_build_cache, MMI_BOOL *seekable, const UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U32 ext_len = 0;
    CHAR* extension_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extension_p = mmi_ucs2rchr((const CHAR*)path, L'.');

    if (extension_p == NULL)
    {
	*need_to_build_cache = MMI_FALSE;
	*seekable = MMI_TRUE; 
	return;
    }
    else
    {
	extension_p += 2;
		ext_len = mmi_ucs2strlen((CHAR*)extension_p);
    }

    for (i = 0; i < NEED_TO_BUILD_CACHE_NUM; i++)
    {
        if (ext_len == mmi_ucs2strlen((CHAR*)audio_file_exts[i]))
        {
            if (!mmi_ucs2icmp((CHAR*)extension_p, (CHAR*)audio_file_exts[i]))
            {
            #ifdef __DRM_V02__
                if (i == ODF_FORMAT_FOR_CACHE)
                {
                    UI_character_type ext_in_odf[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
                    PU8 ext_name_p = NULL; 
                    
                    ext_name_p = (PU8)DRM_get_content_ext(0, (PU16)g_audply.filefullname);
                    if (ext_name_p != NULL)
                    {
                        memset(ext_in_odf, 0, sizeof(ext_in_odf));
                        mmi_asc_n_to_ucs2((CHAR*)ext_in_odf, (CHAR*)ext_name_p, strlen((const char *)ext_name_p));

                        ext_len = mmi_ucs2strlen((CHAR*)ext_in_odf);

                        for (i = 0; i < NEED_TO_BUILD_CACHE_NUM; i++)
                        {
                            if (ext_len == mmi_ucs2strlen((CHAR*)audio_file_exts[i]))
                            {
                                if (!mmi_ucs2icmp((CHAR*)ext_in_odf, (CHAR*)audio_file_exts[i]))
                                {
                                    *need_to_build_cache = MMI_TRUE;
                                    *seekable = MMI_TRUE;
                                    return;
                                }
                            }
                        }
                    }
                }
                else
            #endif /*__DRM_V02__*/                
                {
                    *need_to_build_cache = MMI_TRUE;
                    *seekable = MMI_TRUE;
                    return;
                }
            }
        }
    }

    *need_to_build_cache = MMI_FALSE;
    *seekable = MMI_TRUE; 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lookup_audio_file_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ext        [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_lookup_audio_file_format(const UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U32 ext_len = 0;
    UI_character_type file_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ext == NULL || 0 == (ext_len = mmi_ucs2strlen((CHAR*)ext)))
    {
        return -1;
    }
    /* skip ".". */
    {
        CHAR* dot = mmi_ucs2rchr((CHAR*)ext, (U16)L'.');
        if (dot)
        {
            dot += 2;
        }
        else
        {
            dot = (CHAR*)ext;
        }
        mmi_ucs2ncpy((CHAR*)file_ext, (CHAR*)dot, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
        ext_len = mmi_ucs2strlen((CHAR*)dot);
    }
    
    for (i = 0; i < audio_file_exts[i][0]; i++)
    {
        if (ext_len == mmi_ucs2strlen((CHAR*)audio_file_exts[i]))
        {
            if (!mmi_ucs2icmp((CHAR*)file_ext, (CHAR*)audio_file_exts[i]))
            {   
                return i;
            }
        }
    }

    return -1;
}

#if defined(MT6223) || defined(MT6223P)
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_check_support_A2DP_or_not
 * DESCRIPTION
 *  check if the file type supports A2DP
 * PARAMETERS
 *  ext     [IN]        
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_check_support_A2DP_or_not(const UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U32 ext_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ext == NULL || 0 == (ext_len = mmi_ucs2strlen((CHAR*)ext)))
    {
        return MMI_FALSE;
    }
    for (i = 0; i < audio_file_not_support_a2dp_exts[i][0] ; i++)
    {
        if (ext_len == mmi_ucs2strlen((CHAR*)audio_file_not_support_a2dp_exts[i]))
        {
            if (!mmi_ucs2icmp((CHAR*)ext, (CHAR*)audio_file_not_support_a2dp_exts[i]))
            {   
                return MMI_FALSE;
            }
        }
    }
    return MMI_TRUE;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_extract_ext
 * DESCRIPTION
 *  extract filename extension
 * PARAMETERS
 *  filename        [IN]        
 *  ext             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_extract_ext(const UI_string_type filename, UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* ext_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL)
    {
        *ext = 0;
    }
    else
    {
        ext_ptr = mmi_ucs2rchr((CHAR*)filename, (U16)L'.');

        if (ext_ptr == NULL)
        {
            *ext = 0;
        }
        else
        {
            ext_ptr += 2;
            mmi_ucs2ncpy((CHAR*)ext, (CHAR*)ext_ptr, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_split_filename_ext
 * DESCRIPTION
 *  split filename into two parts: name and extension
 * PARAMETERS
 *  filename                    [IN]        
 *  filename_without_ext        [IN]        
 *  ext                         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_split_filename_ext(const UI_string_type filename, UI_string_type filename_without_ext, UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* dot = NULL;
    U16 size;
//    U8 temp[(SRV_FMGR_PATH_MAX_LEN+1) + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_SHOW_FILE_EXT__
    mmi_ucs2ncpy((CHAR*)filename_without_ext, (CHAR*)filename, ((MAX_SUBMENU_CHARACTERS)));
    size = MAX_SUBMENU_CHARACTERS;
#else
    mmi_ucs2ncpy((CHAR*)filename_without_ext, (CHAR*)filename, ((MAX_SUBMENU_CHARACTERS - SRV_FMGR_PATH_MAX_FILE_EXT_LEN)));
    size = MAX_SUBMENU_CHARACTERS - SRV_FMGR_PATH_MAX_FILE_EXT_LEN;
#endif 
    dot =(WCHAR*)mmi_ucs2rchr((CHAR*)filename, (U16)L'.');
    if (dot && ((kal_wstrlen(filename)-kal_wstrlen(dot)) < size))
    {
    dot =(WCHAR*)mmi_ucs2rchr((CHAR*)filename_without_ext, (U16)L'.');
    if (dot)
    {
        *dot = 0;
    }
    }
    
    dot =(WCHAR*)mmi_ucs2rchr((CHAR*)filename, (U16)L'.');
    if (dot == NULL)
    {
        *ext = 0;
    }
    else
    {
        mmi_ucs2ncpy((CHAR*)ext, (CHAR*)(dot + 1), SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_extract_filename
 * DESCRIPTION
 *  get filename without path
 * PARAMETERS
 *  filename            [IN]        
 *  fullfilename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_extract_filename(UI_string_type filename, const UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* filename_ptr = mmi_ucs2rchr((CHAR*)path, (U16)(L'\\'));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename_ptr == NULL)
    {
        *filename = 0;
    }
    else
    {
        mmi_ucs2ncpy((CHAR*)filename, (CHAR*)(filename_ptr + 2), SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_does_file_exist
 * DESCRIPTION
 *  check whether does a file exist
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_does_file_exist(const UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_GetAttributes((PU16)path) < 0)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_is_any_file_selected
 * DESCRIPTION
 *  check does any song is selected
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_is_any_file_selected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_audply_playlist_is_empty() &&
        list_cntx.current_list.pick_index >= 0)
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
 *  mmi_audply_is_audio_path
 * DESCRIPTION
 *  check a path whether is an audio path
 * PARAMETERS
 *  path        [IN]
 * RETURNS
 *  MMI_BOOL        
 *****************************************************************************/
MMI_BOOL mmi_audply_is_audio_path(const UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* dot = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path == NULL)
    {
        return MMI_FALSE;
    }
   
    dot = mmi_ucs2rchr((CHAR*)path, (U16)L'.');

    if (dot != NULL)
    {
        dot += 2;
        if (-1 == mmi_audply_lookup_audio_file_format((UI_string_type)dot))
        {
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_get_current_list_drv
 * DESCRIPTION
 *  get current playlist driver.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_audply_get_current_list_drv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FS_GetDevStatus(g_audply.preferred_list, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
    {
        return g_audply.preferred_list;
    }
    else
    {
        return (U8)SRV_FMGR_PUBLIC_DRV;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_reset_ui_cntx
 * DESCRIPTION
 *  reset list ui struct.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_reset_ui_cntx(void)
{
    memset(&(list_cntx.list_ui), 0, sizeof(mmi_audply_dynamic_list_data_struct));
}

void mmi_audply_playlist_usb_plug_in_hdlr(void)
{
	if(mmi_audply_is_playing())
	{
    mmi_audply_do_stop_action(MMI_TRUE); 
	}
    
    /* USB plugin during generate. */

    if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN,MMI_FRM_NODE_ALL_FLAG) || SCR_ID_AUDPLY_WAITSCREEN == mmi_frm_scrn_get_active_id())
    {
        mmi_audply_playlist_generate_cancel_hdlr_single();
        mmi_frm_scrn_close_active_id();
        mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
        mmi_frm_group_close(GRP_ID_AUDPLY_LIST_BROWSER);
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
        mmi_frm_group_close(GRP_ID_AUDPLY_MAIN);
        mdi_audio_resume_background_play();
    }
    need_reload_list = MMI_TRUE;
    mmi_audply_reset_context();
}


void mmi_audply_playlist_usb_plug_out_hdlr(void)
{
    if (g_mmi_audply_init_done)
    {
        mmi_audply_playlist_init();
        if (mmi_audply_playlist_pick_next() >= 0)
        {
            mmi_audply_playlist_apply_picked_file();
        }
    }
}

void mmi_audply_playlist_msdc_plug_out_hdlr(U8 drv_num, PU8 drv_list)
{
    U8 i = 0;
    for (i = 0; i < drv_num; i++)
    {
        if (g_audply.preferred_list == drv_list[i] &&
            g_audply.present_list == (U8)drv_list[i])
    {
    	mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
        /* in generate process. */
        if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN) || SCR_ID_AUDPLY_WAITSCREEN == mmi_frm_scrn_get_active_id())
        {
            StopTimer(AUDPLY_PROCESS_ADD_FILE_TIMER);
            mmi_audply_playlist_generate_cancel_hdlr_single();

            mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);

            //DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN);
        }  
        
        /* switch present list to PHONE */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_CARD_PLUG_OUT);
        
        g_audply.present_list = (U8)SRV_FMGR_PUBLIC_DRV;
        need_reload_list = MMI_TRUE;
        StopTimer(AUDPLY_PROCESS_ADD_FILE_TIMER);
        if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN_REMOVE))
    		{
      	    mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN_REMOVE);
    	  }
        //memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
        mmi_audply_playlist_reset_ui_cntx();
        //mmi_audply_playlist_init_header(MMI_TRUE);
        g_audply.duration = 0;
        if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {

             mmi_frm_node_struct new_node_info;
                new_node_info.id = SCR_ID_AUDPLY_LIST_BROWSER;
                new_node_info.entry_proc = (mmi_proc_func)mmi_audply_playlist_entry_playlist_single;
                mmi_frm_scrn_replace (GRP_ID_AUDPLY_LIST_BROWSER, SCR_ID_AUDPLY_LIST_BROWSER, &new_node_info);

           
        }
        if (FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
	    {
	      
	        mmi_frm_group_close(GRP_ID_AUDPLY_MAIN);

	    }   
            
        break;
        }
    }
    
}
    
void mmi_audply_playlist_msdc_plug_in_hdlr(U8 drv_num, PU8 drv_list)
{
    U8 i = 0;
    for (i = 0; i < drv_num; i++)
    {
        if (g_audply.preferred_list == (U8)drv_list[i] && 
        g_audply.present_list == (U8)SRV_FMGR_PUBLIC_DRV)
    {
        /* switch present list to CARD */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_CARD_PLUG_IN);
            g_audply.present_list = (U8)drv_list[i];
        #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
        if (g_audply.list_auto_gen)
        {
            need_refresh_list = MMI_TRUE;
        }
        else
        #endif
        {
            need_reload_list = MMI_TRUE;
        }
        //memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
        mmi_audply_playlist_init_header(MMI_FALSE);
        if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_LIST_BROWSER,SCR_ID_AUDPLY_LIST_BROWSER,MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_frm_node_struct new_node_info;
                new_node_info.id = SCR_ID_AUDPLY_LIST_BROWSER;
                new_node_info.entry_proc = (mmi_proc_func)mmi_audply_playlist_entry_playlist_single;
                mmi_frm_scrn_replace (GRP_ID_AUDPLY_LIST_BROWSER, SCR_ID_AUDPLY_LIST_BROWSER, &new_node_info);
        }
       
        mmi_frm_group_close(GRP_ID_AUDPLY_OPTION);
		break;
        }
    }
}


void mmi_audply_playlist_post_format_hdlr(CHAR drv)
{
    if ((U8)drv == mmi_audply_get_current_list_drv())
    {
        g_mmi_audply_init_done = MMI_FALSE;
        if (list_cntx.list_loaded)
        {
            list_cntx.list_loaded = MMI_FALSE;
            mmi_audply_playlist_reset_ui_cntx();
            mmi_audply_playlist_init_header(MMI_TRUE);
            mmi_audply_reset_context();
        } 
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_plst_notify_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_audply_plst_notify_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables */
    /*----------------------------------------------------------------*/
    AUDPLY_UPDATE_LIST_ACTION_ENUM          action;

    /*----------------------------------------------------------------*/
    /* Code Body */
    /*----------------------------------------------------------------*/

    switch(event->evt_id)
    {
       
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
        case EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE:
        {
            srv_fmgr_notification_set_def_storage_event_struct *fmgr_storage
                = (srv_fmgr_notification_set_def_storage_event_struct*)event;
            
            if(fmgr_storage->state == SRV_FMGR_NOTIFICATION_STATE_QUERY) /* MMI_FMGR_NOTIFY_SET_STORAGE_PRE_CHK */
            {
                return mmi_audply_plst_notify_default_storage_change_pre_check((CHAR)fmgr_storage->drv_letter);
            }
            else if(fmgr_storage->state == SRV_FMGR_NOTIFICATION_STATE_AFTER) /* MMI_FMGR_NOTIFY_SET_STORAGE */
            {
                mmi_audply_plst_notify_default_storage_change((CHAR)fmgr_storage->drv_letter);
            }
            break;
        }

#endif /* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */

        case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT: 
        {
            srv_fmgr_notification_format_event_struct *fmgr_format
                = (srv_fmgr_notification_format_event_struct*)event;
            
            if(fmgr_format->state == SRV_FMGR_NOTIFICATION_STATE_BEFORE) /* MMI_FMGR_NOTIFY_DRV_PRE_FORMAT */
            {
                mmi_audply_fmgr_notify_drv_pre_format_hdlr((CHAR)fmgr_format->drv_letter);
            }
            else if(fmgr_format->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
            {
                mmi_audply_fmgr_notify_drv_post_format_hdlr((CHAR)fmgr_format->drv_letter);
            }
            break;
        }


        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT: /* MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT */
        {
            srv_fmgr_notification_dev_plug_event_struct *fmgr_plug
                = (srv_fmgr_notification_dev_plug_event_struct*)event;

            mmi_audply_msdc_plug_out_hdlr(fmgr_plug->count, fmgr_plug->drv_letters);
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN: /*MMI_FMGR_NOTIFY_DRV_POST_MOUNT*/
        {
            srv_fmgr_notification_dev_plug_event_struct *fmgr_plug
                = (srv_fmgr_notification_dev_plug_event_struct*)event;

            mmi_audply_msdc_plug_in_hdlr(fmgr_plug->count, fmgr_plug->drv_letters);
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT:
        {
            srv_fmgr_notification_dev_soft_mount_event_struct *fmgr_mount
                = (srv_fmgr_notification_dev_soft_mount_event_struct*)event;
            
            if(fmgr_mount->mount == MMI_FALSE) /*MMI_FMGR_NOTIFY_ENTRY_UNMOUNT*/
            {
                mmi_audply_fmgr_notify_hdlr((CHAR)fmgr_mount->drv_letter);
            }
           
            break;

        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
        {
            srv_fmgr_notification_adv_action_event_struct *fmgr_act 
                = (srv_fmgr_notification_adv_action_event_struct*)event;
            
            
            if(fmgr_act->state == SRV_FMGR_NOTIFICATION_STATE_QUERY)
            {
                if ((fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_MOVE) || /*MMI_FMGR_NOTIFY_PRE_DELETE, MMI_FMGR_NOTIFY_PRE_MOVE */
                    (fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE))
                {
                    if(mmi_audply_check_file_is_playing((CHAR*)fmgr_act->src_filepath, (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR), MMI_FALSE, MMI_FALSE,(fmgr_act->filter)))
                    {
                        return MMI_RET_ERR;
                    }
                    
                }
                else if(fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL) /* MMI_FMGR_NOTIFY_PRE_DEL_ALL */
                {
                    if (!FMGR_FILTER_IS_SET_AUDIO((FMGR_FILTER *)fmgr_act->filter))
                    {
                        /* avoid: delete all image files. need not check*/
                        return MMI_TRUE;
                    }
                    if(mmi_audply_check_file_is_playing((CHAR*)fmgr_act->src_filepath, (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR),MMI_FALSE, MMI_TRUE,(fmgr_act->filter)))
                    {
                        return MMI_RET_ERR;
                    }
                }
            }
            else if (fmgr_act->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
            {
            #if defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__)
                switch(fmgr_act->action)
                {
                    case SRV_FMGR_NOTIFICATION_ACTION_COPY:
                    {
                        action = AUDPLY_ACTION_COPY;
                        mmi_audply_update_list_hdlr((CHAR*)fmgr_act->src_filepath,(CHAR*)fmgr_act->dest_filepath,(U8)action, (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR));
                    }
                    break;
                    
                    case SRV_FMGR_NOTIFICATION_ACTION_MOVE:
                    {
                        CHAR* last_backlash = NULL;
                        MMI_BOOL trg_folder = MMI_FALSE;
                        MMI_BOOL src_folder = MMI_FALSE;
                        
                        last_backlash = mmi_ucs2rchr((CHAR*)fmgr_act->dest_filepath, (U16)L'\\');
                        
                        MMI_ASSERT(last_backlash != NULL);
                        
                        if (2 > mmi_ucs2strlen((CHAR*)last_backlash))
                        {
                            trg_folder = MMI_TRUE;
                        }
                        
                        last_backlash = mmi_ucs2rchr((CHAR*)fmgr_act->src_filepath, (U16)L'\\');
                        
                        MMI_ASSERT(last_backlash != NULL);
                        
                        if (2 > mmi_ucs2strlen((CHAR*)last_backlash))
                        {
                            src_folder = MMI_TRUE;
                        }

                        if (trg_folder && !src_folder)
                        {
                            //move file(source) to folder(target)
                            action = AUDPLY_ACTION_MOVE;
                        }
                        else
                        {
                            //rename file/folder(source) to file/folder(target)
                            action = AUDPLY_ACTION_RENAME;
                        }
                        
                        mmi_audply_update_list_hdlr((CHAR*)fmgr_act->src_filepath,(CHAR*)fmgr_act->dest_filepath,(U8)action, (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR));
                    }
                    break;
                    
                    case SRV_FMGR_NOTIFICATION_ACTION_DELETE:
                    {
                        action = AUDPLY_ACTION_DELETE;
                        mmi_audply_update_list_hdlr((CHAR*)fmgr_act->src_filepath,NULL,(U8)action, (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR));
                    }
                    break;

                    case SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL:
                    {
                        if (!FMGR_FILTER_IS_SET_AUDIO((FMGR_FILTER *)fmgr_act->filter))
                        {
                             /* avoid: delete all image files. need not check*/
                            return MMI_TRUE;
                        }
                        mmi_audply_update_list_hdlr((CHAR*)fmgr_act->src_filepath,NULL,AUDPLY_ACTION_DELETE_ALL, (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR));
                        break;
                    }
                    

                    default:
                        break;
                                        
                }
            #endif /* #if defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__) */
            }
            break;
        }
        
        default:
            break;
    }

    return MMI_RET_OK;
}

#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_set_default_playlist_path
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_set_default_playlist_path(void)
{
    kal_wsprintf(list_cntx.current_list.path, "%c:\\", (CHAR)g_audply.present_list);
    mmi_ucs2cat((CHAR*)list_cntx.current_list.path, (CHAR*)MMI_AUDPLY_DEFAULT_PATH);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_check_and_set_default_playlist_path
 * DESCRIPTION
 *  .
 * PARAMETERS
 *  file_path       [OUT]
 *  driver_letter   [IN]
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_audply_playlist_check_and_set_default_playlist_path(UI_string_type file_path, CHAR driver_letter)
{
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    S32 ret = FS_NO_ERROR;

    kal_wsprintf(path, "%c:\\", (CHAR)driver_letter);
    mmi_ucs2cat((CHAR*)path, (CHAR*)MMI_AUDPLY_DEFAULT_FOLDER);
    /* check default playlist fodler. */
    ret = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    if (ret < FS_NO_ERROR)
    {
        if (ret == FS_FAT_ALLOC_ERROR)
        {
            return ret;
        }
        
        ret = FS_CreateDir(path);
        if (FS_FILE_EXISTS == ret)
        {
            ret = -1;
        }
        else if(FS_NO_ERROR > ret)
        {
            return ret;
        }
        else
        {
            FS_SetAttributes(path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
            ret = -1;
        }
        FS_Close(ret);
    }
    else
    {
        FS_Close(ret);
        ret = -1;
    }
    /* always set default playlist folder as hidden. */
    //FS_SetAttributes(path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    
    mmi_ucs2cat((CHAR*)path, (CHAR*)L"\\");
    mmi_ucs2cat((CHAR*)path, (CHAR*)MMI_AUDPLY_DEFAULT_LIST_NAME);

    mmi_ucs2ncpy((CHAR*)file_path, (CHAR*)path, (SRV_FMGR_PATH_MAX_LEN+1));
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_check_status
 * DESCRIPTION
 *  for check user modify list data file in mass storege mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_check_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_audply_init_done)
    {
        mmi_audply_playlist_init();
    }
}


#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */

#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
MMI_BOOL mmi_audply_plst_notify_default_storage_change_pre_check(CHAR new_storage_letter)
{
    return MMI_TRUE;
}

void mmi_audply_plst_notify_default_storage_change(CHAR new_storage_letter)
{
	S16 error = 0;

    if (g_audply.preferred_list != (U8)new_storage_letter)
    {
		g_audply.preferred_list = (U8)new_storage_letter;
		WriteValue(NVRAM_AUDPLY_PREFER_LIST, &new_storage_letter, DS_BYTE, &error);
    #ifdef __MMI_AUDIO_PLAYER_SINGLE_LIST__
    	if (g_mmi_audply_init_done)
        {
			mmi_audply_stop_playing();
			mmi_audply_refresh_cache(MMI_FALSE);
	        g_audply.present_list = (U8)new_storage_letter;
            #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
	        if (g_audply.list_auto_gen)
	        {
	            need_refresh_list = MMI_TRUE;
	        }
	        else
            #endif
	        {
	            need_reload_list = MMI_TRUE;
	        }
	        memset(&(list_cntx.current_list), 0, sizeof(mmi_audply_playlist_struct));
            mmi_audply_playlist_init_header(MMI_TRUE);
        }
	#endif	/* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */
	}
}
#endif	/* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */
#define GENERATER_FUNCTION_BODY
#define GENERATER_FUNCTION_BODY
#define GENERATER_FUNCTION_BODY
#define GENERATER_FUNCTION_BODY

 /*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_send_msg
 * DESCRIPTION
 *  player list service send msg function 
 * PARAMETERS
 *  buffer      [IN]    buffer for sqlite database usage
 *  length      [IN]    length of buffer
 *  en_update   [IN]    enable update picture to database
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_cui_search_send_msg(module_type src, module_type dst, U32 msg_id, void *local_param_ptr)
{
    msg_send5(src, dst, MMI_MMI_SAP, (msg_type)msg_id, (local_para_struct*)local_param_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_generate(UI_string_type fullPath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    MMI_BOOL is_multi_part_odf = MMI_FALSE;
    CHAR* last_backlash = NULL;
#ifdef __DRM_V02__
    CHAR* ext = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fullPath == NULL)
    {
        goto ERROR;
    }
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
    if (fullPath[0] != (CHAR)g_audply.present_list)
    {
        mmi_popup_display_ext(
            STR_ID_AUDPLY_FILE_IN_DIFFERENT_STORAGE, 
            MMI_EVENT_ERROR, 
            NULL);
        goto ERROR;
    }
#endif

    if (mmi_audply_playlist_get_count() >= MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT)
    {
        mmi_popup_display_ext(
            STR_ID_AUDPLY_LIST_FULL, 
            MMI_EVENT_FAILURE, 
            NULL);
        return;
    }
#ifdef __DRM_V02__    
    if (NULL != (ext = mmi_ucs2rchr((CHAR*)fullPath, (U16)L'.')))
    {
        if (!mmi_ucs2nicmp((CHAR*)ext, 
            (CHAR*)L".odf", (U32)mmi_ucs2strlen((CHAR*)ext)))
        {
            if (DRM_is_archive(0, (PU16)fullPath))
            {
                is_multi_part_odf = MMI_TRUE;
            }
            else 
            {
                is_multi_part_odf = MMI_FALSE;
            }             
        }
    }
    else
    {
        is_multi_part_odf = MMI_FALSE;
    }
#else
    is_multi_part_odf = MMI_FALSE;
#endif  /* __DRM_V02__ */   

    /* the last character will be '\\' if the path got from filemgr is a folder. */
    last_backlash = mmi_ucs2rchr((CHAR*)fullPath, (U16)L'\\');

    if (2 > mmi_ucs2strlen((CHAR*)last_backlash) || is_multi_part_odf)
    {
        /* 
        ** the backlash is the last character of this path. 
        ** so this is a folder path.
        */
        ret = mmi_audply_playlist_check_and_set_default_playlist_path(
                   list_cntx.current_list.path, (CHAR)g_audply.present_list);
        if (ret < FS_NO_ERROR)
        {
            /* create default playlist folder failed! */
			mmi_audply_playlist_display_popup(ret, NULL);
            goto ERROR;
        }
        /* generater need playlist file's handle. */
        ret = FS_Open(list_cntx.current_list.path, FS_READ_WRITE | FS_CREATE | FS_ATTR_HIDDEN);
        if (ret < 0)
        {
            mmi_audply_playlist_display_popup(ret, NULL);
            goto DELETE_SCR;
        }
        else
        {
            list_cntx.current_list.fs_hdlr = ret;
            list_cntx.current_list.total = mmi_audply_playlist_get_count();
            ret = FS_Seek(ret, list_cntx.current_list.total * MMI_AUDPLY_LIST_RECORD_SIZE, FS_FILE_BEGIN);
            if (ret < FS_NO_ERROR)
            {
                mmi_audply_playlist_display_popup(ret, NULL);                
                goto DELETE_SCR;
            }
            else
            {
                /* always suspend background playing in single list. */
               #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
                if (!g_audply.list_auto_gen)
                #endif
                {
                    mdi_audio_suspend_background_play();
                }
                #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
                else
                {
                    mmi_audply_stop_playing();
                }
                #endif
                mmi_audply_playlist_generate_from_folder(fullPath, is_multi_part_odf);
            }
        }
    }
    else
    {
    #if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
        ret = mmi_audply_playlist_check_and_set_default_playlist_path(
                   list_cntx.current_list.path, (CHAR)g_audply.present_list);
        if (ret < FS_NO_ERROR)
        {
            /* create default playlist folder failed! */
			mmi_audply_playlist_display_popup(ret, NULL);
            goto ERROR;
        }
    #endif
        /* it is a file. append to playlist directly. */
        ret = mmi_audply_playlist_generate_append_one(fullPath, (MMI_BOOL)is_short);
        if (ret >= FS_NO_ERROR)
        {
            mmi_popup_display_ext(
                STR_GLOBAL_DONE, 
                MMI_EVENT_SUCCESS, 
                NULL);
        }
        else
        {
            mmi_audply_playlist_display_popup(ret, NULL);
            goto ERROR;
        }
        if (list_cntx.current_list.pick_index < 0)
        {
            if (mmi_audply_playlist_pick_next() >= 0)
            {
                mmi_audply_playlist_apply_picked_file();
            }
        }
    }

    return;

ERROR:
    mmi_audply_playlist_reload_list();

DELETE_SCR:
    if (mmi_frm_group_is_present(GRP_ID_AUDPLY_LIST_ADD))
    {
        mmi_frm_group_close(GRP_ID_AUDPLY_LIST_ADD);
    }
    mmi_frm_group_close(GRP_ID_AUDPLY_OPTION); 
}

void mmi_audply_playlist_generate_cancel(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(AUDPLY_PROCESS_ADD_FILE_TIMER);
    mmi_audply_playlist_error_hdlr_ext();
    if (add_file_cursor >= 0)
    {
        /* re-initialize pick index if necessary */
        if (list && list->pick_index < 0)
        {
            if (mmi_audply_playlist_pick_next() >= 0)
            {
                mmi_audply_playlist_apply_picked_file();
            }
        }
        FS_FindClose(add_file_cursor);
        add_file_cursor = -1;
    }
    if(g_audply_playlist)
    {
    	OslMfree(g_audply_playlist);
	    g_audply_playlist = NULL;
    }

    if (list->fs_hdlr > 0)
    {
        FS_Close(list->fs_hdlr);
        list->fs_hdlr  = 0;
    }
    mmi_audply_update_main_button_flag();

    if (mmi_frm_scrn_get_active_id() == SCR_ID_AUDPLY_WAITSCREEN)    /* user press cancel in wait screen. */
    {
        mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
        //GoBackHistory();    /* go back to FMGR screen. */
    }
    else if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN,MMI_FRM_NODE_ALL_FLAG))     /* USB plug-in in generate process */
    {
        /* wait screen in history. need delete it. */
        if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN))
        {
            mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
        }
        //DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN);
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */
}

static U32 counter = 0;


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_from_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_generate_from_folder(UI_string_type path, MMI_BOOL is_multi_part_odf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_generate_struct* this = &(list_cntx.generate_info);
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /* init generate variables. */
    memset(this, 0, sizeof(mmi_audply_playlist_generate_struct));
    mmi_ucs2cpy((CHAR*)this->path_cache, (CHAR*)path);
    
    SetProtocolEventHandler(mmi_audply_playlist_generate_internal, MSG_ID_MMI_LIST_SEARCH_CUI_SEARCH_INT_REQ);

    /* entry wait screen. */
    mmi_audply_playlist_generate_wait_screen_entry();
    counter = 0;
    StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 50, mmi_audply_playlist_generate_internal);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAYLIST_UPDATE_START, __LINE__);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_generate_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_get_active_id() != GRP_ID_AUDPLY_WAITSCREEN)
    {
        /* Sleep if the waitting screen has been in history. */
        StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 500, mmi_audply_playlist_generate_internal);
        return;
    }
    mmi_audply_playlist_refresh_ext();
}




static mmi_ret mmi_audply_playlist_generate_wait_screen_proc(mmi_event_struct *event)
{
    switch (event->evt_id)
    {
	    case EVT_ID_SCRN_INACTIVE:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAYLIST_GENERATE_WAIT_SCREEN, __LINE__);
            break;
        }
        case EVT_ID_SCRN_ACTIVE:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAYLIST_GENERATE_WAIT_SCREEN, __LINE__);
            /* do not allow popup sliding for this waiting popup */
		#ifdef __MMI_SCREEN_SWITCH_EFFECT__
            gui_screen_switch_effect_block(MMI_TRUE);
		#endif
        
            ShowCategory66Screen(
                STR_ID_AUDPLY_TITLE,
                GetRootTitleIcon(AUDIO_PLAYER_MAIN_MENUID),
                0,
                0,
                STR_GLOBAL_CANCEL,
                0,
                (U8*)GetString(STR_GLOBAL_PLEASE_WAIT),
                mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                NULL);
        
            ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
            break;
        }
        case EVT_ID_WGUI_RSK_CLICK:
        {
            mmi_audply_playlist_generate_cancel();
            return MMI_RET_KEY_HANDLED;          
        }
        default:
            break;
    }
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_wait_screen_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_generate_wait_screen_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_group_create_ex(
        GRP_ID_AUDPLY_MAIN, 
        GRP_ID_AUDPLY_WAITSCREEN, 
        mmi_audply_playlist_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(
         GRP_ID_AUDPLY_WAITSCREEN, 
         SCR_ID_AUDPLY_WAITSCREEN, 
         mmi_audply_playlist_generate_wait_screen_proc,   
        NULL);
}


static void mmi_audply_playlist_generate_cancel_hdlr_single(void)
{
    mmi_audply_playlist_generate_struct* this = &(list_cntx.generate_info);
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    ClearProtocolEventHandler(MSG_ID_MMI_LIST_SEARCH_CUI_SEARCH_INT_REQ);
    StopTimer(AUDPLY_PROCESS_ADD_FILE_TIMER);
    mmi_audply_playlist_cancel_init ();

    #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    if (!g_audply.list_auto_gen)
    #endif
    {
        mmi_audply_playlist_reload_list();
        if (list->pick_index < 0)
        {
            if (mmi_audply_playlist_pick_next() >= 0)
            {
                mmi_audply_playlist_apply_picked_file();
            }
        }
        else if(g_audply.filefullname[0] == 0)
        {
            mmi_audply_playlist_apply_picked_file();
        }
        mdi_audio_resume_background_play();
    }
    #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    else
    {
        memset(list, 0, sizeof(mmi_audply_playlist_struct));
        mmi_audply_need_load_playlist();
    }
    #endif
    

    mmi_audply_update_main_button_flag();

    if (mmi_frm_scrn_get_active_id() == SCR_ID_AUDPLY_WAITSCREEN)    /* user press cancel in wait screen. */
    {
        mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
        //GoBackHistory();    /* go back to FMGR screen. */
    }
    else if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN,MMI_FRM_NODE_ALL_FLAG))     /* USB plug-in in generate process */
    {
        /* wait screen in history. need delete it. */
        if (mmi_frm_group_is_present(GRP_ID_AUDPLY_WAITSCREEN))
        {
            mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
        }
        //DeleteScreenIfPresent(SCR_ID_AUDPLY_WAITSCREEN);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_append_one
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_audply_playlist_generate_append_one(UI_string_type path, MMI_BOOL is_short)
{
    return mmi_audply_playlist_generate_append_one_single(path, is_short);
}



#define GENERATE_SINGLE_PART
 
static S32 mmi_audply_playlist_generate_append_one_single(UI_string_type path, MMI_BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_seek;
    S32 size;
    S32 len;
    S16 track_abs_pos;
    S16 write_result, result = 2;
    FS_HANDLE fd = -1;
    S32 ret = FS_NO_ERROR;
    S16 *audply_plylist_header = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    track_abs_pos = mmi_audply_playlist_get_abs_pos();
    audply_plylist_header = (S16*) OslMalloc((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2);
    memset (audply_plylist_header, 0, ((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2));
    ret = mmi_audply_playlist_read_header(audply_plylist_header);
    if (ret < FS_NO_ERROR)
    {
        OslMfree (audply_plylist_header);
        return ret;
    }
    fd = FS_Open(list_cntx.current_list.path, FS_READ_WRITE | FS_CREATE | FS_ATTR_HIDDEN);
    if (fd < 0)
    {
        return FS_ROOT_DIR_FULL;
    }

    file_seek = track_abs_pos * MMI_AUDPLY_PATH_LEN + 2 * (MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2);
    if (FS_Seek(fd, file_seek, FS_FILE_BEGIN) >= 0)
    {
        len = 2 * (1 + mmi_ucs2strlen((S8*) path));
        if (len <= 512)
        {
            write_result = FS_Write(fd, path, len, (UINT*) & size);

        }
        else
        {
            write_result = FS_Write(fd, path, MMI_AUDPLY_PATH_LEN, (UINT*) & size);
        }
		FS_Commit(fd);
        if (write_result == 0)
        {
            audply_plylist_header[track_abs_pos] = audply_plylist_header[MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT];
            audply_plylist_header[MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT]++;
            g_absolute_count++;
            list_cntx.current_list.total++;

            if (FS_Seek(fd, 0, FS_FILE_BEGIN) >= 0)
            {
                ret = FS_Write(
                    fd,
                    audply_plylist_header,
                    (MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT * 2) + 2,
                    (UINT*) & size);
            }
            result = 0;
        }
        else if (write_result == FS_DISK_FULL)
        {
            result = 1;
        }
        else
        {
            result = write_result;
        }
    }
    else
    {
        result = FS_ROOT_DIR_FULL;
    }
    OslMfree (audply_plylist_header);
	FS_Close(fd);
    return result;
}

static void mmi_audply_playlist_generate_finish_single(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_generate_struct* this = &(list_cntx.generate_info);
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_AUDPLY_TRC_PLAYLIST_UPDATE_FINISH, __LINE__);

    mmi_audply_playlist_error_hdlr_ext();

    if (list->pick_index < 0)
    {
        if (mmi_audply_playlist_pick_next() >= 0)
        {
            mmi_audply_playlist_apply_picked_file();
        }
    }
    else if (list->pick_index == 0)
    {
        mmi_audply_playlist_apply_picked_file();
    }
    if (g_audply_playlist->total_no_of_audios)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_AUDPLY_WAITSCREEN || !mmi_frm_is_in_backward_scenario())
        {
            mmi_frm_scrn_clean_gui_buf(GRP_ID_AUDPLY_LIST_BROWSER, SCR_ID_AUDPLY_LIST_BROWSER);
            mmi_frm_scrn_close(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN);
        }
        if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN,MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
        }
    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_AUDPLY_WAITSCREEN || !mmi_frm_is_in_backward_scenario())
        {
            mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, NULL);
            mmi_frm_scrn_close(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN);
           
        }
         if (mmi_frm_scrn_is_present(GRP_ID_AUDPLY_WAITSCREEN,SCR_ID_AUDPLY_WAITSCREEN,MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_frm_group_close(GRP_ID_AUDPLY_WAITSCREEN);
        }
        
    }
    
    /*
    **  this is to solve when user never enters audply,
    **  but tries to play by AVRCP first command will 
    **  trigger regenerate playlist when auto gen on,
    **  but the button flag will not have chance to update,
    **  so any button press/release command will be blocked.
    */ 
    mmi_audply_update_main_button_flag();
}



static void mmi_audply_playlist_error_hdlr_ext(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    if (!g_audply.list_auto_gen)
     #endif
    {
        mmi_audply_playlist_reload_list();
	    if (list->pick_index < 0)
	    {
	        if (mmi_audply_playlist_pick_next() >= 0)
	        {
	            mmi_audply_playlist_apply_picked_file();
                }
	    }
        else if(g_audply.filefullname[0] == 0)
        {
            mmi_audply_playlist_apply_picked_file();
        }
        mdi_audio_resume_background_play();
    }
    #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    else
    {
        memset(list, 0, sizeof(mmi_audply_playlist_struct));
        mmi_audply_need_load_playlist();
    }
    #endif
}



#define AUTO_UPDATE_FUNCTION_BODY
#define AUTO_UPDATE_FUNCTION_BODY
#define AUTO_UPDATE_FUNCTION_BODY
#define AUTO_UPDATE_FUNCTION_BODY
#if defined(__MMI_AUDIO_PLAYER_SINGLE_LIST__)
#if defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__)
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_rename_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static void mmi_audply_update_rename_folder(MMI_BOOL is_folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    if (g_audply.list_auto_gen && is_folder)
    {
        UI_character_type list_path[SRV_FMGR_PATH_MAX_LEN + 1];
        UI_character_type present_folder[SRV_FMGR_PATH_MAX_LEN + 1];
        
        kal_wsprintf(present_folder, "%c:\\", (CHAR)g_audply.present_list);
        mmi_ucs2cat((CHAR*)present_folder, (CHAR*)MUSIC_FOLDER);
        
        ret = mmi_audply_playlist_check_and_set_default_playlist_path(list_path, (CHAR)g_audply.present_list);
        if (ret < FS_NO_ERROR)
        {
            return;
        }

        /* rename: from "My Music" to "my music" and something else... */
        if (!mmi_ucs2icmp((CHAR*)update_cntx.old_path, (CHAR*)update_cntx.new_path))
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_3);
            /*no need to modify list!*/
            return;
        }
        /* rename: from "my music" to something else... */
        else if (!mmi_ucs2nicmp((CHAR*)update_cntx.old_path, (CHAR*)present_folder, (U32)mmi_ucs2strlen((CHAR*)present_folder)))
        {
            /*since it's renamed, create an empty play list file*/
            FS_HANDLE fd ;
            if((fd = FS_Open((PU16)list_path, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN)) >= 0)
            {
                FS_Close(fd);
            }
            if (g_mmi_audply_init_done)
            {
                mmi_audply_need_load_playlist();
            }
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_4);
            /*delete list data file and reload list!*/
            return;
        }
        /* rename: from other name to "my music" or "My Music" or something else... */
        else if (!mmi_ucs2nicmp((CHAR*)update_cntx.new_path, (CHAR*)present_folder, (U32)mmi_ucs2strlen((CHAR*)present_folder)))
        {
            if (g_mmi_audply_init_done)
            {
                g_audply.seekable = MMI_TRUE;
                need_refresh_list = MMI_TRUE;
            }
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_5);
            /*only need refresh list!*/
            return;
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_6);
            /*no need to modify list! this is impossible!!!*/
            return;
        }
    }
    
    else
    #endif
    {
#ifdef __DRM_V02__

        CHAR* ext = NULL;
    
        ext = mmi_ucs2rchr((CHAR*)update_cntx.new_path, (U16)L'.');
        ext += 2;
        if (!mmi_ucs2nicmp((CHAR*)ext, (CHAR*)L"odf", (U32)mmi_ucs2strlen((CHAR*)ext)))
        {
            /* this is an odf file */
            if (DRM_is_archive(0, (PU16)update_cntx.new_path))
            {
                /* it is a multi-part odf file. */
                update_cntx.is_folder = MMI_TRUE;
            }
        }
#endif  /* __DRM_V02__ */
        mmi_audply_update_do_rename_folder();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_set_cache_buff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_audply_update_set_cache_buff(CHAR* buffer_ptr, U32 size_limit)
{
    cache_cntx.file_offset = 0;
    cache_cntx.cache_offset = 0;
    cache_cntx.cache_size = 0;
    cache_cntx.cache_limit = 0;

    if (buffer_ptr != NULL)
    {
        cache_cntx.cache_buffer_ptr = buffer_ptr;
        cache_cntx.cache_limit = size_limit;
        return MMI_TRUE;
    }
    else
    {
        cache_cntx.cache_buffer_ptr = NULL;
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_fill_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_audply_update_fill_cache(FS_HANDLE fd, U32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 read_size;
    S32 seek_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fd < 0)
    {
        /*fill cache - invalid parameter!*/
        return MMI_FALSE;
    }

    if (cache_cntx.cache_buffer_ptr == NULL)
    {
        /*fill cache - buffer_ptr = NULL!*/
        return MMI_FALSE;
    }
    
    if ((seek_ret = FS_Seek(fd, offset, FS_FILE_BEGIN)) >= 0)
    {
        if (seek_ret != offset)
        {
            /*seek failed!*/
            return MMI_FALSE;
        }

        if (FS_NO_ERROR <= (FS_Read(fd, cache_cntx.cache_buffer_ptr, cache_cntx.cache_limit, &read_size)))
        {
            cache_cntx.file_offset = offset;
            cache_cntx.cache_offset = 0;
            cache_cntx.cache_size = read_size;
            if (read_size == 0)
            {
                return MMI_FALSE;
            }
            else
            {
               return MMI_TRUE;
            }
        }
        else
        {
            /*fill cache - read file failed!*/
            return MMI_FALSE;
        }
    }
    else
    {
        /*fill cache - seek file failed!*/
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_backfill_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_audply_update_backfill_cache(FS_HANDLE fd, U32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 write_size;
    S32 seek_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (fd < 0)
    {
        /*fill cache - invalid parameter!*/
        return MMI_FALSE;
    }

    if (cache_cntx.cache_buffer_ptr == NULL)
    {
        /*fill cache - buffer_ptr = NULL!*/
        return MMI_FALSE;
    }
    
    if ((seek_ret = FS_Seek(fd, offset, FS_FILE_BEGIN)) >= 0)
    {
        if (seek_ret != offset)
        {
            return MMI_FALSE;
        }

        if (FS_NO_ERROR == (FS_Write(fd, cache_cntx.cache_buffer_ptr, cache_cntx.cache_size, &write_size)))
        {
            if (write_size == cache_cntx.cache_size)
            {
                //cache_cntx.file_offset = 0;
                cache_cntx.cache_offset = 0;
                cache_cntx.cache_size = 0;
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }
        else
        {
            /*backfill cache - write file error!*/
            return MMI_FALSE;
        }
    }
    else
    {
        /*backfill cache - write file failed!*/
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_do_rename_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static void mmi_audply_update_do_rename_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR current_drv = 0;
    CHAR* filename = NULL;
    UI_character_type new_path_buffer[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    MMI_BOOL need_reload_cache = MMI_TRUE;
    MMI_BOOL need_backfill_cache = MMI_FALSE;
    MMI_BOOL is_short = MMI_FALSE;
    U32 record_in_cache = 0;
    CHAR* path = NULL;
    S32 ret = FS_NO_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (update_cntx.present_list == -1)
    {
        if (g_mmi_audply_init_done)
        {
            current_drv = (CHAR)g_audply.present_list;
        }
        else
        {
            current_drv = (CHAR)update_cntx.old_path[0];
        }
        ret = mmi_audply_playlist_check_and_set_default_playlist_path(new_path_buffer, (CHAR)current_drv);
        if (ret < FS_NO_ERROR)
        {
            return;
        }   
        if (FS_NO_ERROR > (update_cntx.present_list = FS_Open((PU16)new_path_buffer, FS_READ_WRITE)))
        {
            /*can not open present list file!*/
            return;
        }
        FS_Seek(update_cntx.present_list, 0, FS_FILE_BEGIN);
        if (!mmi_audply_update_set_cache_buff((CHAR*)g_mmi_update_list_buff, g_mmi_update_list_buff_size))
        {
            MMI_ASSERT(0);
        }
        update_cntx.offset = 0;
    }
    
    for (; update_cntx.counter < (U32)list_cntx.current_list.total; )
    {
        if (need_reload_cache)
        {
            if (!mmi_audply_update_fill_cache(update_cntx.present_list, update_cntx.offset))
            {
                /*load cache failed!*/
                break;
            }
            else
            {
                need_reload_cache = MMI_FALSE;
                record_in_cache = (cache_cntx.cache_size / MMI_AUDPLY_LIST_RECORD_SIZE);
                update_cntx.offset += cache_cntx.cache_size;
            }
        }
        
        do
        {
            path = cache_cntx.cache_buffer_ptr + cache_cntx.cache_offset;
            is_short = MMI_FALSE;
            if (IS_SNAME2(path))
            {
                is_short = MMI_TRUE;
            }
            
            MARK_DRIVE_PS8(path);
            //like get a "D:/A/mp3.mp3"
            if (!mmi_ucs2nicmp((CHAR*)path, 
                            (CHAR*)update_cntx.old_path, 
                            update_cntx.old_path_len))
            {
                if (update_cntx.is_folder)
                {
                    //move "D:/A/"(old_path) to "D:/H/A/"(new_path)
                    filename = path + (mmi_ucs2strlen((CHAR*)update_cntx.old_path) * ENCODING_LENGTH);
                    mmi_ucs2cpy((CHAR*)new_path_buffer, (CHAR*)update_cntx.new_path);
                    mmi_ucs2cat((CHAR*)new_path_buffer, (CHAR*)filename);

                    if (is_short)
                    {
                        MARK_SNAME(new_path_buffer);
                    }
                    else
                    {
                        MARK_LNAME(new_path_buffer);
                    }
                    if ((SRV_FMGR_PATH_MAX_LEN+1) < mmi_ucs2strlen((CHAR*)new_path_buffer))
                    {
                        /*new path is too long!*/
                        break;
                    }
                    mmi_ucs2ncpy((CHAR*)path, (CHAR*)new_path_buffer, MMI_AUDPLY_LIST_RECORD_SIZE);
                }
                else
                {
                    //move "D:/A/mp3.mp3"(old_path) to "D:/H/mp3.mp3"(new_path)
                    MARK_LNAME(update_cntx.new_path);
                    mmi_ucs2ncpy((CHAR*)path, 
                        (CHAR*)update_cntx.new_path, MMI_AUDPLY_LIST_RECORD_SIZE);

                    /* reset loading file's filename and title in g_audply */
                    if (g_mmi_audply_init_done)
                    {
                        U32 index = update_cntx.counter + (cache_cntx.cache_size / MMI_AUDPLY_LIST_RECORD_SIZE) - record_in_cache;
                        if (index == list_cntx.current_list.pick_index)
                        {
                            CHAR* filename = mmi_ucs2rchr((CHAR*)update_cntx.new_path, (U16)L'\\');
                            CHAR* dot = mmi_ucs2rchr((CHAR*)update_cntx.new_path, (U16)L'.');
                            
                            mmi_ucs2ncpy((CHAR*)g_audply.filefullname, 
                                (CHAR*)update_cntx.new_path, MMI_AUDPLY_LIST_RECORD_SIZE);
                            mmi_ucs2ncpy((CHAR*)g_audply.title, (CHAR*)(filename + 2), (U32)(((dot - 2) - filename) / 2));
			                MARK_DRIVE(g_audply.filefullname);
                        }
                    }
                }
                need_backfill_cache = MMI_TRUE;
            }
			else
			{
				if (is_short)
				{
					MARK_SNAME2(path);
				}
				else
				{
					MARK_LNAME2(path);
				}
			}
			cache_cntx.cache_offset += MMI_AUDPLY_LIST_RECORD_SIZE;

        } while((--record_in_cache) > 0);

        update_cntx.counter += (cache_cntx.cache_size / MMI_AUDPLY_LIST_RECORD_SIZE);

        if (need_backfill_cache)
        {
            need_backfill_cache = MMI_FALSE;
            if (!mmi_audply_update_backfill_cache(update_cntx.present_list, cache_cntx.file_offset))
            {                
                /*backfill cache failed!*/
                break;
            }
        }
        need_reload_cache = MMI_TRUE;
    }
    FS_Close(update_cntx.present_list);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_delete_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static void mmi_audply_update_delete_folder(MMI_BOOL is_folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #ifdef __MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__
    if (g_audply.list_auto_gen && is_folder)
    {
        UI_character_type list_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
        UI_character_type present_folder[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
        
        kal_wsprintf(present_folder, "%c:\\", (CHAR)g_audply.present_list);
        mmi_ucs2cat((CHAR*)present_folder, (CHAR*)MUSIC_FOLDER);
        
        ret = mmi_audply_playlist_check_and_set_default_playlist_path(list_path, (CHAR)g_audply.present_list);
        if (ret < FS_NO_ERROR)
        {
            return;
        }
        /* delete: delete "My Music" folder. */
              
        if (!mmi_ucs2cmp((CHAR*)update_cntx.old_path, (CHAR*)present_folder))
        {
			FS_HANDLE fd ;
            if((fd = FS_Open((PU16)list_path, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN)) >= 0)
            {
                FS_Close(fd);
            }
            if (g_mmi_audply_init_done)
            {
                need_reload_list = MMI_TRUE;
            }
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_7);
            /*delete list data file and reload list!*/
            return;
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_6);
            /*no need to modify list! this is impossible!!!*/ 
            return;
        }
    }
    else
    #endif
    {
        mmi_audply_update_do_delete_folder();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_do_rename_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
static void mmi_audply_update_do_delete_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR current_drv = 0;
    UI_character_type buffer[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    CHAR* path = NULL;
    S32 ret = FS_NO_ERROR;
    S32 total_records = list_cntx.current_list.total;   
    S32 current_index = list_cntx.current_list.pick_index;
    U32 record_in_cache = 0;
    U32 buffer_size; 
    MMI_BOOL need_reload_cache = MMI_TRUE;
    MMI_BOOL is_short = MMI_FALSE;
    MMI_BOOL fs_error = MMI_FALSE;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (update_cntx.present_list == -1)
    {
        if (g_mmi_audply_init_done)
        {
            current_drv = (CHAR)g_audply.present_list;
        }
        else
        {
            current_drv = (CHAR)update_cntx.old_path[0];
        }
        ret = mmi_audply_playlist_check_and_set_default_playlist_path(buffer, (CHAR)current_drv);
        if (ret < FS_NO_ERROR)
        {
            return;
        }
        if (FS_NO_ERROR > (update_cntx.present_list = FS_Open((PU16)buffer, FS_READ_WRITE)))
        {
            /*can not open present list file!*/
            return;
        }

        if (update_cntx.temp_file == -1)
        {
            kal_wsprintf(buffer, "%c:\\", current_drv);
            mmi_ucs2cat((CHAR*)buffer, (CHAR*)MMI_AUDPLY_DEFAULT_FOLDER);
            mmi_ucs2cat((CHAR*)buffer, (CHAR*)L"\\");
            mmi_ucs2cat((CHAR*)buffer, (CHAR*)L"~");
            mmi_ucs2cat((CHAR*)buffer, (CHAR*)MMI_AUDPLY_DEFAULT_LIST_NAME);
            update_cntx.temp_file= FS_Open((PU16)buffer, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN);
            ASSERT(update_cntx.temp_file != 0);
            if (update_cntx.temp_file < 0)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AUDPLY_TRC_UPDATE_LIST_WARNING_8);
                /*can not create temp file!!!*/
                FS_Close(update_cntx.present_list);
                return;
            }
        }

        FS_Seek(update_cntx.present_list, 0, FS_FILE_BEGIN);
        if (!mmi_audply_update_set_cache_buff((CHAR*)g_mmi_update_list_buff, g_mmi_update_list_buff_size))
        {
            MMI_ASSERT(0);
        }
        update_cntx.offset = 0;
    }
    
    for (; update_cntx.counter < (U32)total_records; )
    {
        if (need_reload_cache)
        {
            if (!mmi_audply_update_fill_cache(update_cntx.present_list, cache_cntx.file_offset))
            {
                /*load cache failed!*/
                fs_error = MMI_TRUE;
                break;
            }
            else
            {
                need_reload_cache = MMI_FALSE;
                record_in_cache = (cache_cntx.cache_size / MMI_AUDPLY_LIST_RECORD_SIZE);
                cache_cntx.file_offset += cache_cntx.cache_size;
            }
        }
        
        do
        {
            MMI_BOOL need_remove = MMI_FALSE;
            
            path = cache_cntx.cache_buffer_ptr + cache_cntx.cache_offset;
            is_short = MMI_FALSE;
            if (IS_SNAME2(path))
            {
                is_short = MMI_TRUE;
            }
            
            MARK_DRIVE_PS8(path);
            if (!mmi_ucs2nicmp((CHAR*)path, 
                            (CHAR*)update_cntx.old_path, 
                            update_cntx.old_path_len))
            {
                //bql: duplicate code for need_remove init.
                //consider to modify as:
                /*
                if (FS_GetAttributes((PU16)path) < 0)
                {
                    need_remove = MMI_TRUE;
                }
                else
                {
                    need_remove = MMI_FALSE;
                }*/
                if (!mmi_ucs2nicmp((CHAR*)path, (CHAR*)g_audply.filefullname, (SRV_FMGR_PATH_MAX_LEN+1)))
                {
                    if (FS_GetAttributes((PU16)path) < 0)
                    {
                        /* can remove */
                        need_remove = MMI_TRUE;
                    }
                    else
                    {
                        /* CAN NOT REMOVE! */
                        need_remove = MMI_FALSE;
                    }
                }
                else
                {
                    //need_remove = MMI_TRUE;
                    if (FS_GetAttributes((PU16)path) < 0)
                    {
                        /* can remove */
                        need_remove = MMI_TRUE;
                    }
                    else
                    {
                        /* CAN NOT REMOVE! */
                        need_remove = MMI_FALSE;
                    }
                }
            }
            
            if (need_remove)
            {
                U8 i = 0;
                for (i = 0; i < record_in_cache; i++)
                {
                    //shift left for one MMI_AUDPLY_LIST_RECORD_SIZE
                    memcpy((path + i * MMI_AUDPLY_LIST_RECORD_SIZE), (path + (i + 1) * MMI_AUDPLY_LIST_RECORD_SIZE), MMI_AUDPLY_LIST_RECORD_SIZE);
                }
                /* update relative variable in struct "g_audply" */
                if (g_mmi_audply_init_done)
                {
                    U32 index = update_cntx.counter;
                    
                    if ((--total_records) < 0)
                    {
                        total_records = 0;
                    }
                    
                    if (current_index > (S32)index)
                    {
                        if ((--current_index) < 0)
                        {
                            current_index = 0;
                        }
                    }
                    else if (current_index == index)
                    {
                        mmi_audply_clear_play_seconds();
                    }
                }
                cache_cntx.cache_size -= MMI_AUDPLY_LIST_RECORD_SIZE;
                update_cntx.deleted++;
            } 
            else
            {
                if (is_short)
                {
                    MARK_SNAME2(path);
                }
                else
                {
                    MARK_LNAME2(path);
                }
                update_cntx.counter++;
                cache_cntx.cache_offset += MMI_AUDPLY_LIST_RECORD_SIZE;
            }
            
        } while((--record_in_cache) > 0);
        buffer_size = cache_cntx.cache_size;

        if (!mmi_audply_update_backfill_cache(update_cntx.temp_file, update_cntx.offset))
        {                
            /*backfill cache failed!*/
            fs_error = MMI_TRUE;
            break;
        }
        else
        {
            update_cntx.offset += buffer_size;
        }

        need_reload_cache = MMI_TRUE;
    }

    if (!fs_error)
    {   
        S32 seek_ret;
        seek_ret = FS_Seek(update_cntx.present_list, 
            update_cntx.counter * MMI_AUDPLY_LIST_RECORD_SIZE, FS_FILE_BEGIN);
        
        if ((update_cntx.counter * MMI_AUDPLY_LIST_RECORD_SIZE) != seek_ret)
        {
            fs_error = MMI_TRUE;
        }
        else
        {
            if (FS_NO_ERROR == FS_Truncate(update_cntx.present_list))
            {
                FS_Close(update_cntx.present_list);
                FS_Close(update_cntx.temp_file);

                /* replace old file */
                kal_wsprintf(update_cntx.old_path, "%c:\\", current_drv);
                mmi_ucs2cat((CHAR*)update_cntx.old_path, (CHAR*)MMI_AUDPLY_DEFAULT_FOLDER);
                mmi_ucs2cat((CHAR*)update_cntx.old_path, (CHAR*)L"\\");
                mmi_ucs2cat((CHAR*)update_cntx.old_path, (CHAR*)L"~");
                mmi_ucs2cat((CHAR*)update_cntx.old_path, (CHAR*)MMI_AUDPLY_DEFAULT_LIST_NAME);

                kal_wsprintf(update_cntx.new_path, "%c:\\", current_drv);
                mmi_ucs2cat((CHAR*)update_cntx.new_path, (CHAR*)MMI_AUDPLY_DEFAULT_FOLDER);
                mmi_ucs2cat((CHAR*)update_cntx.new_path, (CHAR*)L"\\");
                //mmi_ucs2cat((CHAR*)update_cntx.new_path, (CHAR*)L"~");
                mmi_ucs2cat((CHAR*)update_cntx.new_path, (CHAR*)MMI_AUDPLY_DEFAULT_LIST_NAME);

                if (FS_NO_ERROR == FS_Delete((PU16)update_cntx.new_path))
                {
                    FS_Rename((PU16)update_cntx.old_path, (PU16)update_cntx.new_path);
                    list_cntx.current_list.total = total_records;
                    list_cntx.current_list.pick_index = current_index;
                }
                else
                {
                    FS_Delete((PU16)update_cntx.old_path);
                }
            }
            else
            {
                fs_error = MMI_TRUE;
            }
        }
    }


    if (fs_error)
    {
        FS_Close(update_cntx.present_list);
        FS_Close(update_cntx.temp_file);
        
        kal_wsprintf(update_cntx.old_path, "%c:\\", current_drv);
        mmi_ucs2cat((CHAR*)update_cntx.old_path, (CHAR*)MMI_AUDPLY_DEFAULT_FOLDER);
        mmi_ucs2cat((CHAR*)update_cntx.old_path, (CHAR*)L"\\");
        mmi_ucs2cat((CHAR*)update_cntx.old_path, (CHAR*)L"~");
        mmi_ucs2cat((CHAR*)update_cntx.old_path, (CHAR*)MMI_AUDPLY_DEFAULT_LIST_NAME);

        FS_Delete((PU16)update_cntx.old_path);
    }

    /* clear dynamic list buffer */
    if (g_mmi_audply_init_done)
    {
        if (list_cntx.current_list.pick_index == list_cntx.current_list.total)
        {
            if (list_cntx.current_list.total == 0)
            {
                mmi_audply_playlist_init();
            }
            else
            {
                mmi_audply_playlist_set_start(0);
                mmi_audply_playlist_apply_picked_file();
            }
        }
        else if (list_cntx.current_list.total == 0)
        {
            mmi_audply_playlist_init();
        }
        else
        {
            mmi_audply_playlist_set_start(list_cntx.current_list.pick_index);
            mmi_audply_playlist_apply_picked_file();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_update_check_need_modify
 * DESCRIPTION
 *  check a file path whether in list.
 * PARAMETERS
 *  CHAR*         [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static U32 mmi_audply_update_does_record_in_list(const UI_string_type list_path, const CHAR* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 match = 0;
    U32 counter;
    U32 read_size;
    FS_HANDLE fd;
    UI_character_type buffer[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (FS_NO_ERROR > (fd = FS_Open((PU16)list_path, FS_READ_WRITE)))
    {
        /*can not open present list file!*/
        return 0;
    }
    
    for (counter = 0; counter < (U32)list_cntx.current_list.total; counter++)
    {
        if (FS_NO_ERROR== FS_Read(fd, &buffer, MMI_AUDPLY_LIST_RECORD_SIZE, &read_size))
        {
            if (read_size != MMI_AUDPLY_LIST_RECORD_SIZE)
            {  
                /* get end of file. */
                /*break from seek loop!*/ 
                break;
            }
            
            MARK_DRIVE(buffer);
            if (!mmi_ucs2nicmp((CHAR*)file_path, (CHAR*)buffer, (U32)mmi_ucs2strlen((CHAR*)buffer)))
            {
                match++;
            }
        }
    }
    FS_Close(fd);

    return match;
}

#endif /* defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_ON__) || defined(__MMI_AUDIO_PLAYER_AUTO_REFRESH_LIST_AUTOGEN_OFF__) */
#endif  /* __MMI_AUDIO_PLAYER_SINGLE_LIST__ */



void mmi_audply_playlist_cancel_init (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    S32 ret = FS_NO_ERROR;
    S16  *audply_plylist_header = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(add_file_cursor > 0)
	{
	    FS_FindClose(add_file_cursor);
            add_file_cursor = -1;
	}
	if(g_audply_playlist)
    {
        OslMfree(g_audply_playlist);
        g_audply_playlist = NULL;
	}
    audply_plylist_header = (S16*) OslMalloc((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2);
    memset (audply_plylist_header, 0, ((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2));

	ret = mmi_audply_playlist_read_header(audply_plylist_header);
    if (ret < FS_NO_ERROR)
    {
        OslMfree(audply_plylist_header);
        list->total = 0;
        return;
    }

    list->total = audply_plylist_header[MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT];
    
    if (list->fs_hdlr > 0)
    {
        FS_Close(list->fs_hdlr);
        list->fs_hdlr = -1;
    }
    OslMfree(audply_plylist_header);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_count
 * DESCRIPTION
 *  Refreshe the playlsit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 mmi_audply_playlist_get_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;
    S16  *audply_plylist_header = NULL;
    U32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    audply_plylist_header = (S16*) OslMalloc((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2);
    memset (audply_plylist_header, 0, ((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2));
    ret = mmi_audply_playlist_read_header(audply_plylist_header);
    if (ret < FS_NO_ERROR)
    {
        OslMfree (audply_plylist_header);
        return 0;
    }
    count = audply_plylist_header[MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT];

    OslMfree (audply_plylist_header);
    return count;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vdoply_playlist_read_header
 * DESCRIPTION
 *  Refreshe the playlsit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_audply_playlist_read_header(S16 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size;
    S32 ret = 0;
    FS_HANDLE fd = -1;
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_audply_playlist_check_and_set_default_playlist_path(
                list_cntx.current_list.path, (CHAR)g_audply.present_list);  
    if (ret < FS_NO_ERROR)
    {
        return ret;
    }
    if (list->fs_hdlr > 0)
    {
        fd = list->fs_hdlr;
    }
    else
    {
        fd = FS_Open(list_cntx.current_list.path, FS_READ_ONLY);
    }
    if (fd < FS_NO_ERROR)
    {
        return fd;
    }
    FS_Seek(fd, 0, FS_FILE_BEGIN);
    ret = FS_Read(
        fd,
        buffer,
        (MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2,
        (UINT*) & size);
    if (list->fs_hdlr <= 0)
    {
        FS_Close(fd);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_write_header
 * DESCRIPTION
 *  Intialises all the lists
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_write_header(S16 *header)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size;
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);
    S32 ret = 0;
    FS_HANDLE fd = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list->fs_hdlr > 0)
    {
        fd = list->fs_hdlr;
    }
    else
    {
        fd = FS_Open(list_cntx.current_list.path, FS_READ_WRITE | FS_CREATE | FS_ATTR_HIDDEN);
    }
    if (FS_Seek(fd, 0, FS_FILE_BEGIN) >= 0)
    {
        FS_Write(
            fd,
            header,
            (MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT * 2) + 2,
            (UINT*) & size);
    }
	list->total = *(header + MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT);
    
    FS_Commit(fd);
    if (list->fs_hdlr <= 0)
    {
        FS_Close(fd);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_deinit
 * DESCRIPTION
 *  Intialises all the lists
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_struct* list = &(list_cntx.current_list);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(list->total >= MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT)
	{
		if(g_audply_playlist_action == MMI_AUDVDOPLY_ACTION_ADD)
		{
			g_playlist_result = 1;
		}
	}
	
	if ((list->total <= 0 || g_absolute_count == 0) && g_playlist_result >= 0)
    {
        g_playlist_result = 2;
    }    
	mmi_audply_playlist_generate_finish_single();
    mmi_audply_playlist_cancel_init();
    if (g_audply_playlist)
    {
        OslMfree(g_audply_playlist);
        g_audply_playlist = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_check_file_ext
 * DESCRIPTION
 *  check for the extension if desired
 * PARAMETERS
 *  file_name       [?]     
 *  extension       [?](?)
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_audply_playlist_check_file_ext (UI_character_type *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type file_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_audply_extract_ext(file_name, file_ext);

    if (mmi_audply_lookup_audio_file_format (file_ext) < 0)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_next_file
 * DESCRIPTION
 *  Get next file from FS
 * PARAMETERS
 *  file_name       [IN]        
 *  counter         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_audply_playlist_get_next_file(PU16 file_name, S32 counter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    FS_HANDLE result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (counter == 0 && add_file_cursor < 0)
    {
        add_file_cursor = FS_FindFirstN(
                            g_audply_playlist->recent_folder,
                            NULL,
                            0,
                            FS_ATTR_DIR,
                            0,
                            FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                            &g_audply_playlist->file_info,
                            (PU16) file_name,
                            MMI_AUDPLY_PATH_LEN - 1,
                            counter,
                            FS_FIND_DEFAULT);
    }
    else if (add_file_cursor < 0)
    {
        add_file_cursor = FS_FindFirstN(
                            g_audply_playlist->recent_folder,
                            NULL,
                            0,
                            FS_ATTR_DIR,
                            0,
                            FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                            &g_audply_playlist->file_info,
                            (PU16) file_name,
                            MMI_AUDPLY_PATH_LEN - 1,
                            counter - 1,
                            FS_FIND_DEFAULT);
    }

    if (add_file_cursor < 0)
    {
        return MMI_AUDPLY_PLAYLIST_RESULT_NO_FILE;
    }
    if (counter > 0)
    {
        result = FS_FindNextN(
                    add_file_cursor,
                    NULL,
                    0,
                    0,
                    &g_audply_playlist->file_info,
                    (PU16) file_name,
                    MMI_AUDPLY_PATH_LEN,
                    FS_FIND_DEFAULT);
    }
    if (add_file_cursor == FS_NO_MORE_FILES)
    {
        FS_FindClose(add_file_cursor);
        add_file_cursor = -1;
        return MMI_AUDPLY_PLAYLIST_RESULT_NO_FILE;
    }

    if (result)
    {
        FS_FindClose(add_file_cursor);
        add_file_cursor = -1;
        return MMI_AUDPLY_PLAYLIST_RESULT_NO_FILE;
    }
    if (g_audply_playlist->file_info.Attributes & FS_ATTR_DIR)
    {
        /* define a  macro for this */
        FS_FindClose(add_file_cursor);
        add_file_cursor = -1;
        return MMI_AUDPLY_PLAYLIST_RESULT_DIR;
    }
    else
    {
        if (mmi_audply_playlist_check_file_ext(file_name))
        {
            return MMI_AUDPLY_PLAYLIST_RESULT_NO_ERROR;
        }
        else
        {
            return MMI_AUDPLY_PLAYLIST_RESULT_INVALID_FILE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_goto_level_up
 * DESCRIPTION
 *  Go 1 level deeper
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_goto_level_up(PU16 path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU16 full_path = path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* remove "*.*" */
    /* len = app_ucs2_strlen((const kal_int8 *) full_path); */
    if (path == NULL)   /* WBT issue fix */
        return;
    path = (PU16) app_ucs2_strrchr((const S8*)full_path, L'\\');
    if (path == NULL)   /* WBT issue fix */
        return;
    *path = 0;
    path = (PU16) app_ucs2_strrchr((const S8*)full_path, L'\\');
    if (path == NULL)   /* WBT issue fix */
        return;
    app_ucs2_strcpy((S8*) path, (const S8*)L"\\*.*");
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_goto_next_folder
 * DESCRIPTION
 *  Intialises all the lists
 * PARAMETERS
 *  path        [IN]        
 *  folder      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
PU16 mmi_audply_playlist_goto_next_folder(PU16 path, PU16 folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* S32 len; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* len = app_ucs2_strlen((const kal_int8 *) path); */
    if (path == NULL || folder == NULL) /* WBT issue solve */
        return NULL;
    path = (PU16) app_ucs2_strrchr((S8*) path, L'\\');
    path++;
    if (path == NULL)                   /* WBT issue solve */
        return NULL;
    app_ucs2_strcpy((S8*) path, (const S8*)folder);
    app_ucs2_strcat((S8*) path, (S8*) L"\\*.*");
    return path;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_full_path
 * DESCRIPTION
 *  Get full path for file
 * PARAMETERS
 *  dest        [IN]        
 *  file        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_get_full_path(PU16 dest, PU16 file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    app_ucs2_strcpy((kal_int8*) dest, (const kal_int8*)g_audply_playlist->recent_folder);
    len = app_ucs2_strlen((const kal_int8*)dest);
    dest += (len - 3);
    app_ucs2_strcpy((kal_int8*) dest, (const kal_int8*)file);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_get_abs_pos
 * DESCRIPTION
 *  Intialises all the lists
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S16 mmi_audply_playlist_get_abs_pos(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 track_abs_pos;
    S32 ret = FS_NO_ERROR;
    S16  *audply_plylist_header = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    audply_plylist_header = (S16*) OslMalloc((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2);
    memset (audply_plylist_header, 0, ((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2));
    ret = mmi_audply_playlist_read_header(audply_plylist_header);
    if (ret < FS_NO_ERROR)
    {
        OslMfree (audply_plylist_header);
        return ret;
    }
    for (track_abs_pos = 0; 
        track_abs_pos < MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT && audply_plylist_header[track_abs_pos] != -1; 
        track_abs_pos++);
    OslMfree (audply_plylist_header);
    return track_abs_pos;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_write_record
 * DESCRIPTION
 *  Intialises all the lists
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 mmi_audply_playlist_write_record(PU8 filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_seek;
    S32 size;
    S32 len;
    S16 track_abs_pos;
    S16 write_result, result = 2;
    S32 ret = FS_NO_ERROR;
    S16  *audply_plylist_header = NULL;

    mmi_audply_playlist_struct* list = &(list_cntx.current_list);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    track_abs_pos = mmi_audply_playlist_get_abs_pos();

    audply_plylist_header = (S16*) OslMalloc((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2);
    memset (audply_plylist_header, 0, ((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2));
    ret = mmi_audply_playlist_read_header(audply_plylist_header);
    if (ret < FS_NO_ERROR)
    {
        OslMfree (audply_plylist_header);
        return ret;
    }

    if (list->fs_hdlr < 0)
    {
        OslMfree (audply_plylist_header);
        return FS_ROOT_DIR_FULL;
    }

    file_seek = track_abs_pos * MMI_AUDPLY_PATH_LEN + 2 * (MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2);
    if (FS_Seek(list->fs_hdlr, file_seek, FS_FILE_BEGIN) >= 0)
    {
        len = 2 * (1 + app_ucs2_strlen((S8*) filename));
        if (len <= 512)
        {
            write_result = FS_Write(list->fs_hdlr, filename, len, (UINT*) & size);

        }
        else
        {
            write_result = FS_Write(list->fs_hdlr, filename, MMI_AUDPLY_PATH_LEN, (UINT*) & size);
        }
		FS_Commit(list->fs_hdlr);
        if (write_result == 0)
        {
            audply_plylist_header[track_abs_pos] = audply_plylist_header[MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT];
            audply_plylist_header[MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT]++;
            mmi_audply_playlist_write_header(audply_plylist_header);
            g_audply_playlist->total_no_of_audios++;
            g_absolute_count++;

            result = 0;
        }
        else if (write_result == FS_DISK_FULL)
        {
            result = 1;
        }
        else
        {
            result = write_result;
        }
    }
    else
    {
        OslMfree (audply_plylist_header);
        return FS_ROOT_DIR_FULL;
    }
    OslMfree (audply_plylist_header);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_update_record
 * DESCRIPTION
 *  Intialises all the lists
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_playlist_update_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *working_buff;
    FS_HANDLE next_file;
    PU8 scratch_buffer;
    U16 index;
    S16 save_data = 2;
    S32 counter = 0;
    S32 file_length, folder_length;
    MMI_BOOL refresh_complete = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    working_buff = (U16*) OslMalloc (MMI_AUDPLY_PATH_LEN);
    scratch_buffer = (PU8) OslMalloc((SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH);
    do
    {
    	 if (g_audply_playlist->total_no_of_audios >= MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT)
    	 {
    	 	g_absolute_count = 1;
            break;
    	 }
        save_data = MMI_FALSE;
        index = g_audply_playlist->curr_index[g_audply_playlist->curr_level];
        next_file = mmi_audply_playlist_get_next_file(working_buff, index);
		// todo MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_VDOPLY_TRC_GET_NEXT_FILE, index, next_file);
        file_length = app_ucs2_strlen((S8*) working_buff);
        folder_length = app_ucs2_strlen((S8*) g_audply_playlist->recent_folder);
        if (next_file != MMI_AUDPLY_PLAYLIST_RESULT_NO_FILE &&
            ((file_length + folder_length) > (SRV_FMGR_PATH_MAX_LEN + 4)))
        {
            g_audply_playlist->curr_index[g_audply_playlist->curr_level]++;
            continue;
        }
        /*
         * MMI_TRACE(
         * *MMI_MEDIA_TRC_G3_APP_DETAIL,
         * *MMI_AUDPLY_METADB_TRC_GET_NEXT,
         * *next_file,
         * *index);
         */

        if (next_file == MMI_AUDPLY_PLAYLIST_RESULT_NO_FILE)
        {
            if (g_audply_playlist->curr_level > 0)
            {
                g_audply_playlist->curr_level--;
                g_audply_playlist->curr_index[g_audply_playlist->curr_level]++;
                mmi_audply_playlist_goto_level_up(g_audply_playlist->recent_folder);
            }
            else
            {
                refresh_complete = MMI_TRUE;

            }
        }
        else if (next_file == MMI_AUDPLY_PLAYLIST_RESULT_DIR)
        {
            /* check for max depth */
            g_audply_playlist->curr_index[g_audply_playlist->curr_level]++;
            if (g_audply_playlist->curr_level < 5)
            {
                g_audply_playlist->curr_level++;
                g_audply_playlist->curr_index[g_audply_playlist->curr_level] = 0;
                mmi_audply_playlist_goto_next_folder(g_audply_playlist->recent_folder, working_buff);
            }
        }
        else if (next_file == MMI_AUDPLY_PLAYLIST_RESULT_INVALID_FILE)
        {
            g_audply_playlist->curr_index[g_audply_playlist->curr_level]++;
        }
        else if (next_file == MMI_AUDPLY_PLAYLIST_RESULT_NO_ERROR)
        {
            g_audply_playlist->curr_index[g_audply_playlist->curr_level]++;

            mmi_audply_playlist_get_full_path((PU16) scratch_buffer, working_buff);
            save_data = mmi_audply_playlist_write_record(scratch_buffer);

            if (save_data != 0)
            {
            	if(save_data == 1)
            	{
            	       	g_playlist_result = 3;
            	}
                else if(save_data < 0)
                {
                    g_playlist_result = save_data;
                }
                OslMfree(scratch_buffer);
                OslMfree(working_buff);
                mmi_audply_playlist_deinit();			
                return;
            }
        }
       
        counter++;
    } while (counter != 10);

    OslMfree(scratch_buffer);
    OslMfree(working_buff);

    if (g_audply_playlist->total_no_of_audios < MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT && !refresh_complete)
    {
        StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 100, mmi_audply_playlist_update_record);
    }
    else if (!refresh_complete)
    {
        mmi_popup_display_ext(
            STR_ID_AUDPLY_LIST_FULL, 
            MMI_EVENT_FAILURE, 
            NULL);
        mmi_audply_playlist_deinit();
    }
    else
    {
        mmi_audply_playlist_deinit();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_init_header
 * DESCRIPTION
 *  Refreshe the playlsit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_playlist_init_header(MMI_BOOL delete_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 counter;
    S32 ret = FS_NO_ERROR;
    S32 size;
    FS_HANDLE fd = -1;
    S16  *audply_plylist_header= NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    audply_plylist_header = (S16*) OslMalloc((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2);
    memset (audply_plylist_header, 0, ((MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2));
    ret = mmi_audply_playlist_check_and_set_default_playlist_path(
                list_cntx.current_list.path, (CHAR)g_audply.present_list);  
    if (ret < FS_NO_ERROR)
    {
        goto ERROR;
    }

    if (delete_all)
    {
        goto ERROR;
    }
    
	fd = FS_Open(list_cntx.current_list.path, FS_READ_WRITE);

    if (fd < FS_NO_ERROR)
    {
        FS_Close(fd);
        goto ERROR;
    }
    FS_Seek(fd, 0, FS_FILE_BEGIN);
    ret = FS_Read(
        fd,
        audply_plylist_header,
        (MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT + 2) * 2,
        (UINT*) &size);

    if (ret < FS_NO_ERROR || size == 0)
    {
        FS_Close(fd);
        goto ERROR;
    }
    FS_Close(fd);
    mmi_audply_playlist_write_header(audply_plylist_header);
    OslMfree(audply_plylist_header);
    return;

ERROR:
    for (counter = 0; counter < MMI_AUDPLY_PLAYLIST_ALL_AUDIO_COUNT; counter++)
        audply_plylist_header[counter] = (S16) - 1;

    audply_plylist_header[counter++] = 0;
    audply_plylist_header[counter] = (S16) - 1;
    mmi_audply_playlist_write_header(audply_plylist_header);
    OslMfree(audply_plylist_header);
}


static void mmi_audply_playlist_refresh_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //FS_HANDLE folder_handle;
    mmi_audply_playlist_generate_struct* this = &(list_cntx.generate_info);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    add_file_cursor = -1;
    if (g_audply_playlist == NULL)
    {
    g_audply_playlist = (mmi_audply_playlist_mgr_struct*) OslMalloc(sizeof(mmi_audply_playlist_mgr_struct));
    }
    memset (g_audply_playlist, 0, sizeof(mmi_audply_playlist_mgr_struct));
    g_audply_playlist->total_no_of_audios= mmi_audply_playlist_get_count();
    g_audply_playlist->curr_level = 0;
    memset(g_audply_playlist->curr_index, 0, sizeof(g_audply_playlist->curr_index));
    mmi_ucs2cpy((CHAR*)g_audply_playlist->recent_folder, (CHAR*)this->path_cache);
    mmi_ucs2cat((CHAR*)g_audply_playlist->recent_folder, (CHAR*)L"*.*");

    g_audply_playlist_action = MMI_AUDPLY_ACTION_REFRESH;
    g_playlist_result = 0;
    g_absolute_count = 0;
    StartTimer(AUDPLY_PROCESS_ADD_FILE_TIMER, 100, mmi_audply_playlist_update_record);
}

#endif /* __MMI_AUDIO_PLAYER__ */ 



#endif /* __MMI_ULTRA_SLIM_AUDIO_PLAYER__ */

